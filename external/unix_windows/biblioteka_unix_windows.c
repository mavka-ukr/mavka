#include <uv.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

typedef enum {
  CONN_STATE_DISCONNECTED = 0,
  CONN_STATE_CONNECTING,
  CONN_STATE_CONNECTED,
  CONN_STATE_CLOSING
} MavkaConnState;

static void* каллок(size_t num, size_t size) {
  if (num == 0 || size == 0) {
    return пристрій_мавки_виділити(0);
  }

  if (num > SIZE_MAX / size) {
    return NULL;
  }

  size_t total = num * size;
  void* ptr = пристрій_мавки_виділити(total);

  if (ptr != NULL) {
    unsigned char* byte_ptr = (unsigned char*)ptr;
    for (size_t i = 0; i < total; i++) {
      byte_ptr[i] = 0;
    }
  }

  return ptr;
}

typedef struct {
  uv_tcp_t server;
  адреса argument;
  БібліотекаМавкиІнетСлугаОбробникЗапуску on_start;
  БібліотекаМавкиІнетСлугаОбробникПомилки on_error;
  БібліотекаМавкиІнетСлугаОбробникЗупинки on_stop;
  БібліотекаМавкиІнетСлугаОбробникЗнищення on_destroy;
  БібліотекаМавкиІнетСлугаОбробникПідключенняЗвʼязку on_connection;
  БібліотекаМавкиІнетСлугаОбробникДанихЗвʼязку on_data;
  БібліотекаМавкиІнетСлугаОбробникСтіканняЗвʼязку on_drain;
  БібліотекаМавкиІнетСлугаОбробникЗакінченняЗвʼязку on_end;
  БібліотекаМавкиІнетСлугаОбробникПомилкиЗвʼязку on_conn_error;
  БібліотекаМавкиІнетСлугаОбробникВідключенняЗвʼязку on_disconnect;
  int closing;
} MavkaServer;

typedef struct MavkaConn MavkaConn;

struct MavkaConn {
  uv_tcp_t handle;
  MavkaServer* server;
  адреса conn_argument;
  БібліотекаМавкиІнетЗвʼязокОбробникЗнищення on_conn_destroy;
  БібліотекаМавкиІнетКлієнтОбробникПідключення client_on_connect;
  БібліотекаМавкиІнетКлієнтОбробникДаних client_on_data;
  БібліотекаМавкиІнетКлієнтОбробникСтікання client_on_drain;
  БібліотекаМавкиІнетКлієнтОбробникЗакінчення client_on_end;
  БібліотекаМавкиІнетКлієнтОбробникПомилки client_on_error;
  БібліотекаМавкиІнетКлієнтОбробникВідключення client_on_disconnect;
  uv_connect_t connect_req;
  int is_client;
  int write_backlog_active;
  int pending_close;
  size_t active_writes;
  MavkaConnState state;
};

typedef struct {
  uv_write_t req;
  uv_buf_t buf;
  MavkaConn* conn;
  адреса arg;
  БібліотекаМавкиІнетЗвʼязокОбробникНадіслання on_send;
  БібліотекаМавкиІнетЗвʼязокОбробникЗакінчення on_end;
  int is_end_req;
} MavkaWriteReq;

static природне map_uv_error(int err) {
  switch (err) {
    case 0:
      return МАВКА_ІНЕТ_УСПІХ;
    case UV_ENOMEM:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ;
    case UV_EINVAL:
      return МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ;
    case UV_EADDRINUSE:
      return МАВКА_ІНЕТ_ПОМИЛКА_АДРЕСА_ВИКОРИСТОВУЄТЬСЯ;
    case UV_ECONNREFUSED:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗʼЄДНАННЯ_ВІДХИЛЕНО;
    case UV_ECONNRESET:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗʼЄДНАННЯ_СКИНОТО;
    case UV_ENETUNREACH:
      return МАВКА_ІНЕТ_ПОМИЛКА_МЕРЕЖА_НЕДОСТУПНА;
    case UV_EHOSTUNREACH:
    case UV_EHOSTDOWN:
      return МАВКА_ІНЕТ_ПОМИЛКА_ХОСТ_НЕДОСТУПНИЙ;
    case UV_ETIMEDOUT:
      return МАВКА_ІНЕТ_ПОМИЛКА_ТАЙМАУТ;
    case UV_EPIPE:
    case UV_ECANCELED:
    case UV_ESHUTDOWN:
      return МАВКА_ІНЕТ_ПОМИЛКА_КАНАЛ_ЗЛАМАНО;
    case UV_EACCES:
    case UV_EPERM:
      return МАВКА_ІНЕТ_ПОМИЛКА_ДОСТУПУ;
    case UV_EMFILE:
    case UV_ENFILE:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗАБАГАТО_ФАЙЛІВ;
    case UV_EADDRNOTAVAIL:
      return МАВКА_ІНЕТ_ПОМИЛКА_АДРЕСА_НЕДОСТУПНА;
    case UV_ENOBUFS:
      return МАВКА_ІНЕТ_ПОМИЛКА_ПЕРЕПОВНЕННЯ_БУФЕРА;
    case UV_ENETDOWN:
      return МАВКА_ІНЕТ_ПОМИЛКА_МЕРЕЖА_ВІДМОВИЛА;
    case UV_ECONNABORTED:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗʼЄДНАННЯ_ПЕРЕРВАНО;
    case UV_EISCONN:
      return МАВКА_ІНЕТ_ПОМИЛКА_ВЖЕ_ПІДДОСЛІДЖЕНО;
    case UV_ENOTCONN:
    case UV_ENOTSOCK:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕ_ПІДʼЄДНАНО;
    case UV_EIO:
      return МАВКА_ІНЕТ_ПОМИЛКА_ВХІД_ВИХІД;
    case UV_EBADF:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕПРАВИЛЬНИЙ_ФАЙЛ;
    default:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕВІДОМА;
  }
}

static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  (void)handle;
  buf->base = (char*)пристрій_мавки_виділити(suggested_size);
  buf->len = buf->base ? suggested_size : 0;
}

static void conn_close_cb(uv_handle_t* handle) {
  if (handle->type != UV_TCP) {
    return;
  }

  MavkaConn* conn = (MavkaConn*)handle->data;
  if (!conn)
    return;

  conn->state = CONN_STATE_DISCONNECTED;

  if (conn->on_conn_destroy) {
    conn->on_conn_destroy(conn->conn_argument);
  }

  пристрій_мавки_звільнити(conn);
}

static void safe_close_conn(MavkaConn* conn) {
  if (!conn || conn->state == CONN_STATE_DISCONNECTED ||
      conn->state == CONN_STATE_CLOSING) {
    return;
  }

  conn->pending_close = 1;

  if (conn->active_writes == 0 && !uv_is_closing((uv_handle_t*)&conn->handle)) {
    conn->state = CONN_STATE_CLOSING;
    uv_close((uv_handle_t*)&conn->handle, conn_close_cb);
  }
}

static void read_cb(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
  MavkaConn* conn = (MavkaConn*)stream->data;
  if (!conn) {
    if (buf->base)
      пристрій_мавки_звільнити(buf->base);
    return;
  }

  if (nread > 0) {
    if (conn->server && conn->server->on_data) {
      conn->server->on_data((адреса)conn->server, (адреса)conn, (п8*)buf->base,
                            (природне)nread);
    } else if (conn->is_client && conn->client_on_data) {
      conn->client_on_data((адреса)conn, (п8*)buf->base, (природне)nread);
    }
  } else if (nread < 0) {
    uv_read_stop(stream);
    if (nread == UV_EOF) {
      if (conn->server && conn->server->on_end) {
        conn->server->on_end((адреса)conn->server, (адреса)conn);
      } else if (conn->is_client && conn->client_on_end) {
        conn->client_on_end((адреса)conn);
      }
    } else {
      природне err_code = map_uv_error((int)nread);
      if (conn->server && conn->server->on_conn_error) {
        conn->server->on_conn_error((адреса)conn->server, (адреса)conn,
                                    err_code);
      } else if (conn->is_client && conn->client_on_error) {
        conn->client_on_error((адреса)conn, err_code);
      }
    }

    if (conn->server && conn->server->on_disconnect) {
      conn->server->on_disconnect((адреса)conn->server, (адреса)conn);
    } else if (conn->is_client && conn->client_on_disconnect) {
      conn->client_on_disconnect((адреса)conn);
    }

    safe_close_conn(conn);
  }

  if (buf->base) {
    пристрій_мавки_звільнити(buf->base);
  }
}

static void server_close_cb(uv_handle_t* handle) {
  MavkaServer* server = (MavkaServer*)handle->data;
  if (!server)
    return;

  if (server->on_stop) {
    server->on_stop((адреса)server);
  }
  if (server->on_destroy) {
    server->on_destroy(server->argument);
  }

  пристрій_мавки_звільнити(server);
}

static void on_new_connection(uv_stream_t* server_handle, int status) {
  MavkaServer* server = (MavkaServer*)server_handle->data;
  if (!server || server->closing)
    return;

  if (status < 0) {
    if (server->on_error) {
      server->on_error((адреса)server, map_uv_error(status));
    }
    return;
  }

  MavkaConn* conn = (MavkaConn*)каллок(1, sizeof(MavkaConn));
  if (!conn)
    return;

  conn->server = server;
  conn->is_client = 0;
  conn->write_backlog_active = 0;
  conn->pending_close = 0;
  conn->active_writes = 0;
  conn->state = CONN_STATE_CONNECTED;

  if (uv_tcp_init(uv_default_loop(), &conn->handle) != 0) {
    пристрій_мавки_звільнити(conn);
    return;
  }
  conn->handle.data = conn;

  if (uv_accept(server_handle, (uv_stream_t*)&conn->handle) == 0) {
    if (server->on_connection) {
      server->on_connection((адреса)server, (адреса)conn);
    }
    uv_read_start((uv_stream_t*)&conn->handle, alloc_cb, read_cb);
  } else {
    safe_close_conn(conn);
  }
}

void бібліотека_мавки_інет_служити(
    природне іа_вид,
    п8* іа_дані,
    природне іа_розмір,
    природне порт,
    БібліотекаМавкиІнетСлугаОбробникЗапуску обробник_запуску,
    БібліотекаМавкиІнетСлугаОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетСлугаОбробникЗупинки обробник_зупинки,
    адреса аргумент,
    БібліотекаМавкиІнетСлугаОбробникЗнищення обробник_знищення,
    БібліотекаМавкиІнетСлугаОбробникПідключенняЗвʼязку
        обробник_підключення_звʼязку,
    БібліотекаМавкиІнетСлугаОбробникДанихЗвʼязку обробник_даних_звʼязку,
    БібліотекаМавкиІнетСлугаОбробникСтіканняЗвʼязку обробник_стікання_звʼязку,
    БібліотекаМавкиІнетСлугаОбробникЗакінченняЗвʼязку
        обробник_закінчення_звʼязку,
    БібліотекаМавкиІнетСлугаОбробникПомилкиЗвʼязку обробник_помилки_звʼязку,
    БібліотекаМавкиІнетСлугаОбробникВідключенняЗвʼязку
        обробник_відключення_звʼязку) {
  MavkaServer* server = (MavkaServer*)каллок(1, sizeof(MavkaServer));
  if (!server)
    return;

  server->argument = аргумент;
  server->on_start = обробник_запуску;
  server->on_error = обробник_помилки;
  server->on_stop = обробник_зупинки;
  server->on_destroy = обробник_знищення;
  server->on_connection = обробник_підключення_звʼязку;
  server->on_data = обробник_даних_звʼязку;
  server->on_drain = обробник_стікання_звʼязку;
  server->on_end = обробник_закінчення_звʼязку;
  server->on_conn_error = обробник_помилки_звʼязку;
  server->on_disconnect = обробник_відключення_звʼязку;

  if (uv_tcp_init(uv_default_loop(), &server->server) != 0) {
    пристрій_мавки_звільнити(server);
    return;
  }

  server->server.data = server;

  struct sockaddr_storage addr;
  memset(&addr, 0, sizeof(addr));

  int res = 0;

  if (іа_вид == 4) {
    char ip_str[64];
    if (іа_розмір >= sizeof(ip_str)) {
      if (server->on_start) {
        server->on_start((адреса)server, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
      }
      uv_close((uv_handle_t*)&server->server, server_close_cb);
      return;
    }

    memcpy(ip_str, іа_дані, іа_розмір);
    ip_str[іа_розмір] = '\0';

    res = uv_ip4_addr(ip_str, (int)порт, (struct sockaddr_in*)&addr);
  } else if (іа_вид == 6) {
    if (іа_розмір != 16) {
      if (server->on_start) {
        server->on_start((адреса)server, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
      }
      uv_close((uv_handle_t*)&server->server, server_close_cb);
      return;
    }

    struct sockaddr_in6* addr6 = (struct sockaddr_in6*)&addr;
    addr6->sin6_family = AF_INET6;
    addr6->sin6_port = htons((uint16_t)порт);
    memcpy(&addr6->sin6_addr, іа_дані, 16);
  } else {
    if (server->on_start) {
      server->on_start((адреса)server, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
    }
    uv_close((uv_handle_t*)&server->server, server_close_cb);
    return;
  }

  res = uv_tcp_bind(&server->server, (const struct sockaddr*)&addr, 0);
  if (res != 0) {
    if (server->on_start) {
      server->on_start((адреса)server, map_uv_error(res));
    }
    uv_close((uv_handle_t*)&server->server, server_close_cb);
    return;
  }

  res = uv_listen((uv_stream_t*)&server->server, SOMAXCONN, on_new_connection);
  if (res != 0) {
    if (server->on_start) {
      server->on_start((адреса)server, map_uv_error(res));
    }
    uv_close((uv_handle_t*)&server->server, server_close_cb);
    return;
  }

  if (server->on_start) {
    server->on_start((адреса)server, МАВКА_ІНЕТ_УСПІХ);
  }
}

адреса бібліотека_мавки_інет_отримати_аргумент_слуги(адреса адр_слуга) {
  if (!адр_слуга)
    return NULL;
  return ((MavkaServer*)адр_слуга)->argument;
}

static void close_walk_cb(uv_handle_t* handle, void* arg) {
  MavkaServer* server = (MavkaServer*)arg;

  if (uv_is_closing(handle)) {
    return;
  }

  if (handle == (uv_handle_t*)&server->server) {
    uv_close(handle, server_close_cb);
    return;
  }

  if (handle->type == UV_TCP) {
    MavkaConn* conn = (MavkaConn*)handle->data;
    if (conn && !conn->is_client && conn->server == server) {
      conn->state = CONN_STATE_CLOSING;
      uv_close(handle, conn_close_cb);
    }
  }
}

void бібліотека_мавки_інет_зупинити_слугу(адреса адр_слуга,
                                          природне закрити_підключення) {
  MavkaServer* server = (MavkaServer*)адр_слуга;
  if (!server || server->closing)
    return;

  server->closing = 1;

  if (закрити_підключення) {
    uv_walk(uv_default_loop(), close_walk_cb, server);
  } else if (!uv_is_closing((uv_handle_t*)&server->server)) {
    uv_close((uv_handle_t*)&server->server, server_close_cb);
  }
}

static void on_connect(uv_connect_t* req, int status) {
  MavkaConn* conn = (MavkaConn*)req->data;
  if (!conn)
    return;

  природне err_code = map_uv_error(status);

  if (status == 0) {
    conn->state = CONN_STATE_CONNECTED;
  }

  if (conn->client_on_connect) {
    conn->client_on_connect((адреса)conn, err_code);
  }

  if (status < 0) {
    safe_close_conn(conn);
    return;
  }

  uv_read_start((uv_stream_t*)&conn->handle, alloc_cb, read_cb);
}

void бібліотека_мавки_інет_підключитись(
    природне іа_вид,
    п8* іа_дані,
    природне іа_розмір,
    природне порт,
    БібліотекаМавкиІнетКлієнтОбробникПідключення обробник_підключення,
    БібліотекаМавкиІнетКлієнтОбробникДаних обробник_даних,
    БібліотекаМавкиІнетКлієнтОбробникСтікання обробник_стікання,
    БібліотекаМавкиІнетКлієнтОбробникЗакінчення обробник_закінчення,
    БібліотекаМавкиІнетКлієнтОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетКлієнтОбробникВідключення обробник_відключення,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення) {
  MavkaConn* conn = (MavkaConn*)каллок(1, sizeof(MavkaConn));
  if (!conn)
    return;

  conn->is_client = 1;
  conn->write_backlog_active = 0;
  conn->pending_close = 0;
  conn->active_writes = 0;
  conn->state = CONN_STATE_CONNECTING;
  conn->client_on_connect = обробник_підключення;
  conn->client_on_data = обробник_даних;
  conn->client_on_drain = обробник_стікання;
  conn->client_on_end = обробник_закінчення;
  conn->client_on_error = обробник_помилки;
  conn->client_on_disconnect = обробник_відключення;
  conn->conn_argument = аргумент;
  conn->on_conn_destroy = обробник_знищення;

  if (uv_tcp_init(uv_default_loop(), &conn->handle) != 0) {
    пристрій_мавки_звільнити(conn);
    return;
  }

  conn->handle.data = conn;
  conn->connect_req.data = conn;

  struct sockaddr_storage addr;
  memset(&addr, 0, sizeof(addr));

  int res = 0;

  if (іа_вид == 4) {
    char ip_str[64];
    if (іа_розмір >= sizeof(ip_str)) {
      if (conn->client_on_connect) {
        conn->client_on_connect((адреса)conn, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
      }
      safe_close_conn(conn);
      return;
    }

    memcpy(ip_str, іа_дані, іа_розмір);
    ip_str[іа_розмір] = '\0';

    res = uv_ip4_addr(ip_str, (int)порт, (struct sockaddr_in*)&addr);
  } else if (іа_вид == 6) {
    if (іа_розмір != 16) {
      if (conn->client_on_connect) {
        conn->client_on_connect((адреса)conn, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
      }
      safe_close_conn(conn);
      return;
    }

    struct sockaddr_in6* addr6 = (struct sockaddr_in6*)&addr;
    addr6->sin6_family = AF_INET6;
    addr6->sin6_port = htons((uint16_t)порт);
    memcpy(&addr6->sin6_addr, іа_дані, 16);
  } else {
    if (conn->client_on_connect) {
      conn->client_on_connect((адреса)conn, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
    }
    safe_close_conn(conn);
    return;
  }

  res = uv_tcp_connect(&conn->connect_req, &conn->handle,
                       (const struct sockaddr*)&addr, on_connect);
  if (res != 0) {
    if (conn->client_on_connect) {
      conn->client_on_connect((адреса)conn, map_uv_error(res));
    }
    safe_close_conn(conn);
    return;
  }
}

природне бібліотека_мавки_інет_отримати_іа_звʼязку(адреса адр_звʼязок,
                                                   природне* вихід_іа4,
                                                   п8* вихід_іа6) {
  if (!адр_звʼязок)
    return 0;
  MavkaConn* conn = (MavkaConn*)адр_звʼязок;

  struct sockaddr_storage name;
  int namelen = sizeof(name);

  if (uv_tcp_getsockname(&conn->handle, (struct sockaddr*)&name, &namelen) !=
      0) {
    return 0;
  }

  if (name.ss_family == AF_INET) {
    if (вихід_іа4) {
      struct sockaddr_in* s4 = (struct sockaddr_in*)&name;
      *вихід_іа4 = (природне)ntohl(s4->sin_addr.s_addr);
    }
    return 4;
  } else if (name.ss_family == AF_INET6) {
    if (вихід_іа6) {
      struct sockaddr_in6* s6 = (struct sockaddr_in6*)&name;
      memcpy(вихід_іа6, s6->sin6_addr.s6_addr, 16);
    }
    return 6;
  }

  return 0;
}

void бібліотека_мавки_інет_записати_аргумент_звʼязку(
    адреса адр_звʼязок,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення) {
  if (!адр_звʼязок)
    return;
  MavkaConn* conn = (MavkaConn*)адр_звʼязок;
  conn->conn_argument = аргумент;
  conn->on_conn_destroy = обробник_знищення;
}

адреса бібліотека_мавки_інет_отримати_аргумент_звʼязку(адреса адр_звʼязок) {
  if (!адр_звʼязок)
    return NULL;
  return ((MavkaConn*)адр_звʼязок)->conn_argument;
}

static void on_write_complete(uv_write_t* req, int status) {
  MavkaWriteReq* wreq = (MavkaWriteReq*)req->data;
  if (!wreq)
    return;

  MavkaConn* conn = wreq->conn;

  if (conn) {
    if (conn->active_writes > 0) {
      conn->active_writes--;
    }

    if (status == 0) {
      if (wreq->on_send) {
        wreq->on_send((адреса)conn, wreq->arg);
      }
      if (wreq->on_end) {
        wreq->on_end((адреса)conn, wreq->arg);
      }

      if (conn->write_backlog_active) {
        size_t write_queue_size =
            uv_stream_get_write_queue_size((uv_stream_t*)&conn->handle);
        if (write_queue_size == 0) {
          conn->write_backlog_active = 0;
          if (conn->server && conn->server->on_drain) {
            conn->server->on_drain((адреса)conn->server, (адреса)conn);
          } else if (conn->is_client && conn->client_on_drain) {
            conn->client_on_drain((адреса)conn);
          }
        }
      }
    } else {
      conn->write_backlog_active = 0;
      природне err_code = map_uv_error(status);
      if (conn->server && conn->server->on_conn_error) {
        conn->server->on_conn_error((адреса)conn->server, (адреса)conn,
                                    err_code);
      } else if (conn->is_client && conn->client_on_error) {
        conn->client_on_error((адреса)conn, err_code);
      }
    }

    if (wreq->is_end_req) {
      conn->pending_close = 1;
    }

    if (conn->pending_close && conn->active_writes == 0) {
      if (!uv_is_closing((uv_handle_t*)&conn->handle)) {
        conn->state = CONN_STATE_CLOSING;
        uv_close((uv_handle_t*)&conn->handle, conn_close_cb);
      }
    }
  }

  if (wreq->buf.base)
    пристрій_мавки_звільнити(wreq->buf.base);
  пристрій_мавки_звільнити(wreq);
}

логічне бібліотека_мавки_інет_звʼязок_надіслати(
    адреса адр_звʼязок,
    п8* дані,
    природне розмір,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникНадіслання обробник) {
  if (!адр_звʼязок)
    return 0;
  MavkaConn* conn = (MavkaConn*)адр_звʼязок;

  if (conn->state != CONN_STATE_CONNECTED || conn->pending_close) {
    return 0;
  }

  if (розмір == 0) {
    if (обробник) {
      обробник((адреса)conn, аргумент);
    }
    return 1;
  }

  MavkaWriteReq* wreq = (MavkaWriteReq*)каллок(1, sizeof(MavkaWriteReq));
  if (!wreq)
    return 0;

  char* data_copy = (char*)пристрій_мавки_виділити((size_t)розмір);
  if (!data_copy) {
    пристрій_мавки_звільнити(wreq);
    return 0;
  }

  memcpy(data_copy, дані, (size_t)розмір);
  wreq->buf = uv_buf_init(data_copy, (unsigned int)розмір);
  wreq->conn = conn;
  wreq->arg = аргумент;
  wreq->on_send = обробник;
  wreq->is_end_req = 0;
  wreq->req.data = wreq;

  conn->write_backlog_active = 1;
  conn->active_writes++;

  int res = uv_write(&wreq->req, (uv_stream_t*)&conn->handle, &wreq->buf, 1,
                     on_write_complete);
  if (res != 0) {
    conn->active_writes--;
    conn->write_backlog_active = 0;
    пристрій_мавки_звільнити(data_copy);
    пристрій_мавки_звільнити(wreq);
    return 0;
  }

  return 1;
}

void бібліотека_мавки_інет_звʼязок_закінчити(
    адреса адр_звʼязок,
    п8* дані,
    природне розмір,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗакінчення обробник) {
  if (!адр_звʼязок)
    return;
  MavkaConn* conn = (MavkaConn*)адр_звʼязок;

  if (conn->state != CONN_STATE_CONNECTED || conn->pending_close) {
    return;
  }

  if (дані && розмір > 0) {
    MavkaWriteReq* wreq = (MavkaWriteReq*)каллок(1, sizeof(MavkaWriteReq));
    if (wreq) {
      char* data_copy = (char*)пристрій_мавки_виділити((size_t)розмір);
      if (data_copy) {
        memcpy(data_copy, дані, (size_t)розмір);
        wreq->buf = uv_buf_init(data_copy, (unsigned int)розмір);
        wreq->conn = conn;
        wreq->arg = аргумент;
        wreq->on_end = обробник;
        wreq->is_end_req = 1;
        wreq->req.data = wreq;

        conn->write_backlog_active = 1;
        conn->active_writes++;

        if (uv_write(&wreq->req, (uv_stream_t*)&conn->handle, &wreq->buf, 1,
                     on_write_complete) != 0) {
          conn->active_writes--;
          conn->write_backlog_active = 0;
          пристрій_мавки_звільнити(data_copy);
          пристрій_мавки_звільнити(wreq);
          safe_close_conn(conn);
        }
        return;
      } else {
        пристрій_мавки_звільнити(wreq);
      }
    }
  } else {
    if (обробник) {
      обробник((адреса)conn, аргумент);
    }
  }

  safe_close_conn(conn);
}

void бібліотека_мавки_інет_звʼязок_знищити(адреса адр_звʼязок) {
  if (!адр_звʼязок)
    return;
  MavkaConn* conn = (MavkaConn*)адр_звʼязок;
  safe_close_conn(conn);
}