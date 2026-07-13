#include <uv.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

typedef struct ListenerContext ListenerContext;

typedef struct ConnectionContext {
  uv_tcp_t handle;
  uv_connect_t connect_req;
  uv_timer_t timer;

  ListenerContext* listener;

  БібліотекаМавкиІнетКлієнтОбробникПідключення обробник_підключення;
  БібліотекаМавкиІнетКлієнтОбробникПомилкиПідключення
  обробник_помилки_підключення;
  БібліотекаМавкиІнетКлієнтОбробникДаних обробник_даних;
  БібліотекаМавкиІнетКлієнтОбробникСтікання обробник_стікання;
  БібліотекаМавкиІнетКлієнтОбробникЗасидження обробник_засидження;
  БібліотекаМавкиІнетКлієнтОбробникЗакінчення обробник_закінчення;
  БібліотекаМавкиІнетКлієнтОбробникПомилки обробник_помилки;
  БібліотекаМавкиІнетКлієнтОбробникВідключення обробник_закриття;

  адреса аргумент;
  БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення;

  int буфер_переповнений;
  int підключено;
  int закривається;
  int timer_closed;
  int handle_closed;
} ConnectionContext;

struct ListenerContext {
  uv_tcp_t server;
  БібліотекаМавкиІнетСлугаОбробникПідключення обробник_підключення;
  БібліотекаМавкиІнетСлугаОбробникДаних обробник_даних;
  БібліотекаМавкиІнетСлугаОбробникСтікання обробник_стікання;
  БібліотекаМавкиІнетСлугаОбробникЗасидження обробник_засидження;
  БібліотекаМавкиІнетСлугаОбробникЗакінчення обробник_закінчення;
  БібліотекаМавкиІнетСлугаОбробникПомилки обробник_помилки;
  БібліотекаМавкиІнетСлугаОбробникВідключення обробник_закриття;
  адреса аргумент;
  БібліотекаМавкиІнетСлугаОбробникЗнищення обробник_знищення;
};

typedef struct ConnWriteReq {
  uv_write_t req;
  uv_buf_t buf;
  адреса аргумент;
  БібліотекаМавкиІнетЗвʼязокОбробникНадіслання обробник;
} ConnWriteReq;

static void conn_alloc_buffer(uv_handle_t* handle,
                              size_t suggested_size,
                              uv_buf_t* buf) {
  buf->base = (char*)пристрій_мавки_виділити(suggested_size);
  buf->len = buf->base ? suggested_size : 0;
}

static void try_free_connection_context(ConnectionContext* ctx) {
  if (!ctx)
    return;
  if (ctx->handle_closed && ctx->timer_closed) {
    if (ctx->listener) {
      if (ctx->listener->обробник_закінчення) {
        ctx->listener->обробник_закінчення((адреса)ctx->listener, (адреса)ctx);
      }
    } else {
      if (ctx->обробник_закінчення) {
        ctx->обробник_закінчення((адреса)ctx);
      }
    }

    if (ctx->обробник_знищення) {
      ctx->обробник_знищення(ctx->аргумент);
    }

    пристрій_мавки_звільнити(ctx);
  }
}

static void on_connect_client_close(uv_handle_t* handle) {
  ConnectionContext* ctx = (ConnectionContext*)handle->data;
  if (!ctx)
    return;
  ctx->handle_closed = 1;
  try_free_connection_context(ctx);
}

static void on_timer_close(uv_handle_t* handle) {
  ConnectionContext* ctx = (ConnectionContext*)handle->data;
  if (!ctx)
    return;
  ctx->timer_closed = 1;
  try_free_connection_context(ctx);
}

static void close_connect_context(ConnectionContext* ctx) {
  if (!ctx || ctx->закривається)
    return;
  ctx->закривається = 1;

  if (!uv_is_closing((uv_handle_t*)&ctx->timer)) {
    uv_timer_stop(&ctx->timer);
    uv_close((uv_handle_t*)&ctx->timer, on_timer_close);
  } else {
    ctx->timer_closed = 1;
  }

  if (!uv_is_closing((uv_handle_t*)&ctx->handle)) {
    uv_close((uv_handle_t*)&ctx->handle, on_connect_client_close);
  } else {
    ctx->handle_closed = 1;
  }

  try_free_connection_context(ctx);
}

static void on_connect_read(uv_stream_t* stream,
                            ssize_t nread,
                            const uv_buf_t* buf) {
  ConnectionContext* ctx = (ConnectionContext*)stream->data;

  if (ctx->listener) {
    ListenerContext* listener = ctx->listener;
    if (nread > 0) {
      if (listener->обробник_даних) {
        listener->обробник_даних((адреса)listener, (адреса)ctx, (п8*)buf->base,
                                 (природне)nread);
      }
    } else if (nread < 0) {
      if (buf->base) {
        пристрій_мавки_звільнити(buf->base);
      }
      if (listener->обробник_закриття) {
        природне err = (nread == UV_EOF) ? 0 : (природне)(-nread);
        listener->обробник_закриття((адреса)listener, (адреса)ctx, err);
      }
      close_connect_context(ctx);
    } else {
      if (buf->base) {
        пристрій_мавки_звільнити(buf->base);
      }
    }
  } else {
    if (nread > 0) {
      if (ctx->обробник_даних) {
        ctx->обробник_даних((адреса)ctx, (п8*)buf->base, (природне)nread);
      }
    } else if (nread < 0) {
      if (buf->base) {
        пристрій_мавки_звільнити(buf->base);
      }
      if (ctx->обробник_закриття) {
        природне err = (nread == UV_EOF) ? 0 : (природне)(-nread);
        ctx->обробник_закриття((адреса)ctx, err);
      }
      close_connect_context(ctx);
    } else {
      if (buf->base) {
        пристрій_мавки_звільнити(buf->base);
      }
    }
  }
}

static void on_connect_timeout(uv_timer_t* handle) {
  ConnectionContext* ctx = (ConnectionContext*)handle->data;

  if (ctx->listener) {
    if (ctx->listener->обробник_засидження) {
      ctx->listener->обробник_засидження((адреса)ctx->listener, (адреса)ctx);
    }
  } else {
    if (ctx->обробник_засидження) {
      ctx->обробник_засидження((адреса)ctx);
    }
  }

  close_connect_context(ctx);
}

static void on_connect_complete(uv_connect_t* req, int status) {
  ConnectionContext* ctx = (ConnectionContext*)req->handle->data;

  if (status < 0) {
    if (ctx->обробник_помилки_підключення) {
      ctx->обробник_помилки_підключення((адреса)ctx, (природне)(-status));
    }
    close_connect_context(ctx);
    return;
  }

  ctx->підключено = 1;

  if (ctx->обробник_підключення) {
    ctx->обробник_підключення((адреса)ctx);
  }

  int res = uv_read_start((uv_stream_t*)&ctx->handle, conn_alloc_buffer,
                          on_connect_read);
  if (res != 0) {
    if (ctx->обробник_помилки) {
      ctx->обробник_помилки((природне)(-res), ctx->аргумент);
    }
    close_connect_context(ctx);
  }
}

static void on_connect_write_complete(uv_write_t* req, int status) {
  ConnWriteReq* wr = (ConnWriteReq*)req;
  ConnectionContext* ctx = (ConnectionContext*)req->handle->data;

  if (wr->обробник) {
    природне err = (status < 0) ? (природне)(-status) : 0;
    wr->обробник(err, wr->аргумент);
  }

  пристрій_мавки_звільнити(wr);

  if (ctx) {
    if (ctx->listener) {
      if (ctx->listener->обробник_стікання &&
          uv_stream_get_write_queue_size((uv_stream_t*)&ctx->handle) == 0) {
        if (ctx->буфер_переповнений) {
          ctx->буфер_переповнений = 0;
          ctx->listener->обробник_стікання((адреса)ctx->listener, (адреса)ctx);
        }
      }
    } else if (ctx->обробник_стікання) {
      if (uv_stream_get_write_queue_size((uv_stream_t*)&ctx->handle) == 0) {
        if (ctx->буфер_переповнений) {
          ctx->буфер_переповнений = 0;
          ctx->обробник_стікання((адреса)ctx);
        }
      }
    }
  }
}

адреса бібліотека_інет_підключитись(
    природне іа,
    природне порт,
    БібліотекаМавкиІнетКлієнтОбробникПідключення обробник_підключення,
    БібліотекаМавкиІнетКлієнтОбробникПомилкиПідключення
        обробник_помилки_підключення,
    БібліотекаМавкиІнетКлієнтОбробникДаних обробник_даних,
    БібліотекаМавкиІнетКлієнтОбробникСтікання обробник_стікання,
    БібліотекаМавкиІнетКлієнтОбробникЗасидження обробник_засидження,
    БібліотекаМавкиІнетКлієнтОбробникЗакінчення обробник_закінчення,
    БібліотекаМавкиІнетКлієнтОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетКлієнтОбробникВідключення обробник_закриття,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення) {
  ConnectionContext* ctx =
      (ConnectionContext*)пристрій_мавки_виділити(sizeof(ConnectionContext));
  if (!ctx) {
    if (обробник_помилки) {
      обробник_помилки(UV_ENOMEM, NULL);
    }
    return NULL;
  }

  memset(ctx, 0, sizeof(ConnectionContext));

  ctx->обробник_підключення = обробник_підключення;
  ctx->обробник_помилки_підключення = обробник_помилки_підключення;
  ctx->обробник_даних = обробник_даних;
  ctx->обробник_стікання = обробник_стікання;
  ctx->обробник_помилки = обробник_помилки;
  ctx->обробник_закінчення = обробник_закінчення;
  ctx->обробник_засидження = обробник_засидження;
  ctx->обробник_закриття = обробник_закриття;
  ctx->аргумент = аргумент;
  ctx->обробник_знищення = обробник_знищення;

  uv_loop_t* loop = uv_default_loop();

  if (uv_tcp_init(loop, &ctx->handle) != 0) {
    if (обробник_помилки) {
      обробник_помилки(UV_UNKNOWN, NULL);
    }
    пристрій_мавки_звільнити(ctx);
    return NULL;
  }

  if (uv_timer_init(loop, &ctx->timer) != 0) {
    if (обробник_помилки) {
      обробник_помилки(UV_UNKNOWN, NULL);
    }
    uv_close((uv_handle_t*)&ctx->handle, NULL);
    пристрій_мавки_звільнити(ctx);
    return NULL;
  }

  ctx->handle.data = ctx;
  ctx->timer.data = ctx;

  struct sockaddr_in dest;
  memset(&dest, 0, sizeof(dest));
  dest.sin_family = AF_INET;
  dest.sin_port = htons((uint16_t)порт);
  dest.sin_addr.s_addr = htonl((uint32_t)іа);

  int res = uv_tcp_connect(&ctx->connect_req, &ctx->handle,
                           (const struct sockaddr*)&dest, on_connect_complete);
  if (res != 0) {
    if (обробник_помилки_підключення) {
      обробник_помилки_підключення((адреса)ctx, (природне)(-res));
    }
    uv_close((uv_handle_t*)&ctx->timer, NULL);
    uv_close((uv_handle_t*)&ctx->handle, NULL);
    пристрій_мавки_звільнити(ctx);
    return NULL;
  }

  return (адреса)ctx;
}

ціле бібліотека_мавки_інет_звʼязок_надіслати(
    адреса адр_звʼязок,
    п8* дані,
    природне розмір,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникНадіслання обробник) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;

  if (!ctx || !дані || розмір == 0) {
    if (обробник) {
      обробник(UV_EINVAL, аргумент);
    }
    return -1;
  }

  ConnWriteReq* wr =
      (ConnWriteReq*)пристрій_мавки_виділити(sizeof(ConnWriteReq));
  if (!wr) {
    if (ctx->listener && ctx->listener->обробник_помилки) {
      ctx->listener->обробник_помилки(UV_ENOMEM, ctx->listener->аргумент);
    } else if (ctx->обробник_помилки) {
      ctx->обробник_помилки(UV_ENOMEM, ctx->аргумент);
    }
    if (обробник) {
      обробник(UV_ENOMEM, аргумент);
    }
    return -1;
  }

  wr->buf.base = (char*)дані;
  wr->buf.len = розмір;
  wr->аргумент = аргумент;
  wr->обробник = обробник;

  int res = uv_write(&wr->req, (uv_stream_t*)&ctx->handle, &wr->buf, 1,
                     on_connect_write_complete);

  if (res == 0) {
    if (uv_stream_get_write_queue_size((uv_stream_t*)&ctx->handle) > 0) {
      ctx->буфер_переповнений = 1;
    }
  } else {
    пристрій_мавки_звільнити(wr);

    if (ctx->listener && ctx->listener->обробник_помилки) {
      ctx->listener->обробник_помилки((природне)(-res),
                                      ctx->listener->аргумент);
    } else if (ctx->обробник_помилки) {
      ctx->обробник_помилки((природне)(-res), ctx->аргумент);
    }
    if (обробник) {
      обробник((природне)(-res), аргумент);
    }
    return res;
  }

  return 0;
}

ціле бібліотека_мавки_інет_звʼязок_встановити_засидження(адреса адр_звʼязок,
                                                         природне таймаут_мс) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;
  if (!ctx)
    return -1;

  if (таймаут_мс == 0) {
    uv_timer_stop(&ctx->timer);
    return 0;
  }

  return uv_timer_start(&ctx->timer, on_connect_timeout, таймаут_мс, 0);
}

void бібліотека_мавки_інет_закрити_звʼязок(адреса адр_звʼязок) {
  close_connect_context((ConnectionContext*)адр_звʼязок);
}

адреса бібліотека_мавки_інет_отримати_аргумент_звʼязку(адреса адр_звʼязок) {
  return ((ConnectionContext*)адр_звʼязок)->аргумент;
}

void бібліотека_мавки_інет_записати_аргумент_звʼязку(
    адреса адр_звʼязок,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення) {
  ((ConnectionContext*)адр_звʼязок)->аргумент = аргумент;
  ((ConnectionContext*)адр_звʼязок)->обробник_знищення = обробник_знищення;
}

ціле бібліотека_мавки_інет_отримати_іа4_звʼязку(адреса адр_звʼязок,
                                                природне* вихід) {
  ConnectionContext* client = (ConnectionContext*)адр_звʼязок;
  if (!client) {
    return -1;
  }

  struct sockaddr_storage addr;
  int addr_len = sizeof(addr);

  if (uv_tcp_getpeername(&client->handle, (struct sockaddr*)&addr, &addr_len) !=
      0) {
    return -1;
  }

  if (addr.ss_family == AF_INET) {
    struct sockaddr_in* addr_in = (struct sockaddr_in*)&addr;

    *вихід = (природне)ntohl(addr_in->sin_addr.s_addr);

    return 0;
  }

  return -1;
}

ціле бібліотека_мавки_інет_отримати_іа6_звʼязку(адреса адр_звʼязок,
                                                п8* вихідний_буфер_16_байт) {
  ConnectionContext* client = (ConnectionContext*)адр_звʼязок;
  if (!client || !вихідний_буфер_16_байт) {
    return -1;
  }

  struct sockaddr_storage addr;
  int addr_len = sizeof(addr);

  if (uv_tcp_getpeername(&client->handle, (struct sockaddr*)&addr, &addr_len) !=
      0) {
    return -1;
  }

  if (addr.ss_family == AF_INET6) {
    struct sockaddr_in6* addr_in6 = (struct sockaddr_in6*)&addr;
    memcpy(вихідний_буфер_16_байт, &addr_in6->sin6_addr, 16);
    return 0;
  }

  return -1;
}

static void on_new_connection(uv_stream_t* server_handle, int status) {
  ListenerContext* listener = (ListenerContext*)server_handle->data;

  if (status < 0) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки((природне)(-status), listener->аргумент);
    }
    return;
  }

  ConnectionContext* conn =
      (ConnectionContext*)пристрій_мавки_виділити(sizeof(ConnectionContext));
  if (!conn) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки(UV_ENOMEM, listener->аргумент);
    }
    return;
  }

  memset(conn, 0, sizeof(ConnectionContext));
  conn->listener = listener;
  conn->handle.data = conn;

  if (uv_tcp_init(uv_default_loop(), &conn->handle) != 0) {
    пристрій_мавки_звільнити(conn);
    return;
  }

  if (uv_timer_init(uv_default_loop(), &conn->timer) != 0) {
    uv_close((uv_handle_t*)&conn->handle, NULL);
    пристрій_мавки_звільнити(conn);
    return;
  }

  conn->timer.data = conn;

  if (uv_accept(server_handle, (uv_stream_t*)&conn->handle) == 0) {
    if (listener->обробник_підключення) {
      listener->обробник_підключення((адреса)listener, (адреса)conn);
    }
    int res = uv_read_start((uv_stream_t*)&conn->handle, conn_alloc_buffer,
                            on_connect_read);
    if (res != 0) {
      if (listener->обробник_помилки) {
        listener->обробник_помилки((природне)(-res), listener->аргумент);
      }
      close_connect_context(conn);
    }
  } else {
    close_connect_context(conn);
  }
}

static void on_listener_close(uv_handle_t* handle) {
  ListenerContext* listener = (ListenerContext*)handle->data;
  if (listener) {
    if (listener->обробник_знищення) {
      listener->обробник_знищення(listener->аргумент);
    }
    пристрій_мавки_звільнити(listener);
  }
}

адреса бібліотека_мавки_інет_служити(
    природне іа,
    природне порт,
    БібліотекаМавкиІнетСлугаОбробникПідключення обробник_підключення,
    БібліотекаМавкиІнетСлугаОбробникДаних обробник_даних,
    БібліотекаМавкиІнетСлугаОбробникСтікання обробник_стікання,
    БібліотекаМавкиІнетСлугаОбробникЗасидження обробник_засидження,
    БібліотекаМавкиІнетСлугаОбробникЗакінчення обробник_закінчення,
    БібліотекаМавкиІнетСлугаОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетСлугаОбробникВідключення обробник_закриття,
    адреса аргумент,
    БібліотекаМавкиІнетСлугаОбробникЗнищення обробник_знищення) {
  ListenerContext* listener =
      (ListenerContext*)пристрій_мавки_виділити(sizeof(ListenerContext));
  if (!listener) {
    if (обробник_помилки)
      обробник_помилки(UV_ENOMEM, аргумент);
    if (обробник_знищення)
      обробник_знищення(аргумент);
    return NULL;
  }

  memset(listener, 0, sizeof(ListenerContext));
  listener->обробник_підключення = обробник_підключення;
  listener->обробник_даних = обробник_даних;
  listener->обробник_стікання = обробник_стікання;
  listener->обробник_засидження = обробник_засидження;
  listener->обробник_закінчення = обробник_закінчення;
  listener->обробник_помилки = обробник_помилки;
  listener->обробник_закриття = обробник_закриття;
  listener->обробник_знищення = обробник_знищення;
  listener->аргумент = аргумент;

  uv_loop_t* loop = uv_default_loop();

  if (uv_tcp_init(loop, &listener->server) != 0) {
    if (обробник_помилки)
      обробник_помилки(UV_UNKNOWN, listener->аргумент);
    if (listener->обробник_знищення)
      listener->обробник_знищення(listener->аргумент);
    пристрій_мавки_звільнити(listener);
    return NULL;
  }

  listener->server.data = listener;

  struct sockaddr_in addr;
  char ip_str[16];
  snprintf(ip_str, sizeof(ip_str), "%u.%u.%u.%u",
           (unsigned int)((іа >> 24) & 0xFF), (unsigned int)((іа >> 16) & 0xFF),
           (unsigned int)((іа >> 8) & 0xFF), (unsigned int)(іа & 0xFF));

  if (uv_ip4_addr(ip_str, (int)порт, &addr) != 0) {
    if (обробник_помилки)
      обробник_помилки(UV_EINVAL, listener->аргумент);
    uv_close((uv_handle_t*)&listener->server, on_listener_close);
    return NULL;
  }

  if (uv_tcp_bind(&listener->server, (const struct sockaddr*)&addr, 0) != 0) {
    if (обробник_помилки)
      обробник_помилки(UV_EADDRINUSE, listener->аргумент);
    uv_close((uv_handle_t*)&listener->server, on_listener_close);
    return NULL;
  }

  int res =
      uv_listen((uv_stream_t*)&listener->server, SOMAXCONN, on_new_connection);
  if (res != 0) {
    if (обробник_помилки)
      обробник_помилки((природне)(-res), listener->аргумент);
    uv_close((uv_handle_t*)&listener->server, on_listener_close);
    return NULL;
  }

  return (адреса)listener;
}

адреса бібліотека_мавки_інет_отримати_аргумент_слуги_зі_звʼязку(
    адреса адр_звʼязок) {
  ConnectionContext* conn = (ConnectionContext*)адр_звʼязок;
  return (conn && conn->listener) ? conn->listener->аргумент : NULL;
}

static void close_client_walk_cb(uv_handle_t* handle, void* arg) {
  ListenerContext* target_listener = (ListenerContext*)arg;

  if (!uv_is_closing(handle) && handle->type == UV_TCP) {
    ConnectionContext* conn = (ConnectionContext*)handle->data;
    if (conn && conn->listener == target_listener &&
        (uv_handle_t*)&conn->handle == handle) {
      if (conn->listener->обробник_закриття)
        conn->listener->обробник_закриття((адреса)target_listener, (адреса)conn,
                                          0);
      close_connect_context(conn);
    }
  }
}

ціле бібліотека_мавки_інет_зупинити_слугу(адреса слуга,
                                          природне закрити_підключення) {
  ListenerContext* listener = (ListenerContext*)слуга;

  if (!listener) {
    return -1;
  }

  if (uv_is_closing((uv_handle_t*)&listener->server)) {
    return 0;
  }

  if (закрити_підключення) {
    uv_loop_t* loop = listener->server.loop;
    if (loop) {
      uv_walk(loop, close_client_walk_cb, listener);
    }
  }

  uv_close((uv_handle_t*)&listener->server, on_listener_close);

  return 0;
}