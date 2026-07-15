#include <uv.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

static природне перетворити_помилку_uv(int uv_err) {
  if (uv_err >= 0) {
    return МАВКА_ІНЕТ_УСПІХ;
  }

  switch (uv_err) {
    case UV_ENOMEM:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ;
    case UV_EINVAL:
      return МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ;
    case UV_EADDRINUSE:
      return МАВКА_ІНЕТ_ПОМИЛКА_АДРЕСА_ВИКОРИСТОВУЄТЬСЯ;
    case UV_EADDRNOTAVAIL:
      return МАВКА_ІНЕТ_ПОМИЛКА_АДРЕСА_НЕДОСТУПНА;
    case UV_ECONNREFUSED:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗʼЄДНАННЯ_ВІДХИЛЕНО;
    case UV_ECONNRESET:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗʼЄДНАННЯ_СКИНОТО;
    case UV_ECONNABORTED:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗʼЄДНАННЯ_ПЕРЕРВАНО;
    case UV_ENETUNREACH:
      return МАВКА_ІНЕТ_ПОМИЛКА_МЕРЕЖА_НЕДОСТУПНА;
    case UV_ENETDOWN:
      return МАВКА_ІНЕТ_ПОМИЛКА_МЕРЕЖА_ВІДМОВИЛА;
    case UV_EHOSTUNREACH:
      return МАВКА_ІНЕТ_ПОМИЛКА_ХОСТ_НЕДОСТУПНИЙ;
    case UV_ETIMEDOUT:
      return МАВКА_ІНЕТ_ПОМИЛКА_ТАЙМАУТ;
    case UV_EPIPE:
      return МАВКА_ІНЕТ_ПОМИЛКА_КАНАЛ_ЗЛАМАНО;
    case UV_EACCES:
    case UV_EPERM:
      return МАВКА_ІНЕТ_ПОМИЛКА_ДОСТУПУ;
    case UV_EMFILE:
    case UV_ENFILE:
      return МАВКА_ІНЕТ_ПОМИЛКА_ЗАБАГАТО_ФАЙЛІВ;
    case UV_ENOBUFS:
      return МАВКА_ІНЕТ_ПОМИЛКА_ПЕРЕПОВНЕННЯ_БУФЕРА;
    case UV_EALREADY:
      return МАВКА_ІНЕТ_ПОМИЛКА_ВЖЕ_ПІДДОСЛІДЖЕНО;
    case UV_ENOTCONN:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕ_ПІДʼЄДНАНО;
    case UV_EIO:
      return МАВКА_ІНЕТ_ПОМИЛКА_ВХІД_ВИХІД;
    case UV_EBADF:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕПРАВИЛЬНИЙ_ФАЙЛ;
    default:
      return МАВКА_ІНЕТ_ПОМИЛКА_НЕВІДОМА;
  }
}

typedef struct ListenerContext ListenerContext;

typedef struct ConnectionContext {
  uv_tcp_t handle;
  uv_connect_t connect_req;

  ListenerContext* listener;

  БібліотекаМавкиІнетКлієнтОбробникПідключення обробник_підключення;
  БібліотекаМавкиІнетКлієнтОбробникДаних обробник_даних;
  БібліотекаМавкиІнетКлієнтОбробникСтікання обробник_стікання;
  БібліотекаМавкиІнетКлієнтОбробникЗакінчення обробник_закінчення;
  БібліотекаМавкиІнетКлієнтОбробникПомилки обробник_помилки;
  БібліотекаМавкиІнетКлієнтОбробникВідключення обробник_відключення;

  адреса аргумент;
  БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення;

  int буфер_переповнений;
  int підключено;
  int закривається;
  int handle_closed;
  природне error_emitted;
} ConnectionContext;

struct ListenerContext {
  uv_tcp_t server;

  БібліотекаМавкиІнетСлугаОбробникЗапуску обробник_запуску;
  БібліотекаМавкиІнетСлугаОбробникЗупинки обробник_зупинки;
  БібліотекаМавкиІнетСлугаОбробникПідключення обробник_підключення;
  БібліотекаМавкиІнетСлугаОбробникДаних обробник_даних;
  БібліотекаМавкиІнетСлугаОбробникСтікання обробник_стікання;
  БібліотекаМавкиІнетСлугаОбробникЗакінчення обробник_закінчення;
  БібліотекаМавкиІнетСлугаОбробникПомилки обробник_помилки;
  БібліотекаМавкиІнетСлугаОбробникВідключення обробник_відключення;

  адреса аргумент;
  БібліотекаМавкиІнетСлугаОбробникЗнищення обробник_знищення;
};

typedef struct ConnWriteReq {
  uv_write_t req;
  uv_buf_t buf;
  адреса аргумент;
  БібліотекаМавкиІнетЗвʼязокОбробникНадіслання обробник;
} ConnWriteReq;

typedef struct ConnEndReq {
  uv_shutdown_t shutdown_req;
  uv_write_t write_req;
  uv_buf_t buf;
  адреса аргумент;
  БібліотекаМавкиІнетЗвʼязокОбробникЗакінчення обробник;
} ConnEndReq;

static void conn_alloc_buffer(uv_handle_t* handle,
                              size_t suggested_size,
                              uv_buf_t* buf) {
  buf->base = (char*)пристрій_мавки_виділити(suggested_size);
  buf->len = buf->base ? suggested_size : 0;
}

static void try_free_connection_context(ConnectionContext* ctx) {
  if (!ctx)
    return;

  if (ctx->handle_closed) {
    if (ctx->listener) {
      if (ctx->listener->обробник_відключення) {
        ctx->listener->обробник_відключення((адреса)ctx->listener, (адреса)ctx,
                                            ctx->error_emitted);
      }
    } else {
      if (ctx->підключено && ctx->обробник_відключення) {
        ctx->обробник_відключення((адреса)ctx, ctx->error_emitted);
      }
    }

    if (ctx->обробник_знищення && ctx->аргумент) {
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

static void close_connect_context(ConnectionContext* ctx) {
  if (!ctx || ctx->закривається)
    return;
  ctx->закривається = 1;

  if (!uv_is_closing((uv_handle_t*)&ctx->handle)) {
    uv_close((uv_handle_t*)&ctx->handle, on_connect_client_close);
  } else {
    ctx->handle_closed = 1;
    try_free_connection_context(ctx);
  }
}

static void on_connect_read(uv_stream_t* stream,
                            ssize_t nread,
                            const uv_buf_t* buf) {
  ConnectionContext* ctx = (ConnectionContext*)stream->data;
  if (!ctx) {
    if (buf->base)
      пристрій_мавки_звільнити(buf->base);
    return;
  }

  if (nread > 0) {
    int handled = 0;
    if (ctx->listener && ctx->listener->обробник_даних) {
      ctx->listener->обробник_даних((адреса)ctx->listener, (адреса)ctx,
                                    (п8*)buf->base, (природне)nread);
      handled = 1;
    } else if (!ctx->listener && ctx->обробник_даних) {
      ctx->обробник_даних((адреса)ctx, (п8*)buf->base, (природне)nread);
      handled = 1;
    }

    if (!handled && buf->base) {
      пристрій_мавки_звільнити(buf->base);
    }
  } else {
    if (buf->base) {
      пристрій_мавки_звільнити(buf->base);
    }

    if (nread < 0) {
      if (nread == UV_EOF) {
        if (ctx->listener && ctx->listener->обробник_закінчення) {
          ctx->listener->обробник_закінчення((адреса)ctx->listener,
                                             (адреса)ctx);
        } else if (!ctx->listener && ctx->обробник_закінчення) {
          ctx->обробник_закінчення((адреса)ctx);
        }
      } else {
        природне err = перетворити_помилку_uv((int)nread);
        ctx->error_emitted = err;
        if (ctx->listener && ctx->listener->обробник_помилки) {
          ctx->listener->обробник_помилки((адреса)ctx->listener, (адреса)ctx,
                                          err);
        } else if (!ctx->listener && ctx->обробник_помилки) {
          ctx->обробник_помилки((адреса)ctx, err);
        }
      }

      close_connect_context(ctx);
    }
  }
}

static void on_connect_complete(uv_connect_t* req, int status) {
  ConnectionContext* ctx = (ConnectionContext*)req->handle->data;
  if (!ctx || ctx->закривається)
    return;

  if (status < 0) {
    природне err = перетворити_помилку_uv(status);
    ctx->error_emitted = err;
    if (ctx->обробник_підключення) {
      ctx->обробник_підключення((адреса)ctx, err);
    }
    close_connect_context(ctx);
    return;
  }

  ctx->підключено = 1;

  if (ctx->обробник_підключення) {
    ctx->обробник_підключення((адреса)ctx, МАВКА_ІНЕТ_УСПІХ);
  }

  int res = uv_read_start((uv_stream_t*)&ctx->handle, conn_alloc_buffer,
                          on_connect_read);
  if (res != 0) {
    природне err = перетворити_помилку_uv(res);
    ctx->error_emitted = err;
    if (ctx->обробник_помилки) {
      ctx->обробник_помилки((адреса)ctx, err);
    }
    close_connect_context(ctx);
  }
}

static void on_connect_write_complete(uv_write_t* req, int status) {
  ConnWriteReq* wr = (ConnWriteReq*)req;
  ConnectionContext* ctx = (ConnectionContext*)req->handle->data;

  if (status < 0 && ctx && !ctx->закривається) {
    природне err = перетворити_помилку_uv(status);
    ctx->error_emitted = err;
    if (ctx->listener && ctx->listener->обробник_помилки) {
      ctx->listener->обробник_помилки((адреса)ctx->listener, (адреса)ctx, err);
    } else if (!ctx->listener && ctx->обробник_помилки) {
      ctx->обробник_помилки((адреса)ctx, err);
    }
  }

  if (wr->обробник) {
    природне err =
        (status < 0) ? перетворити_помилку_uv(status) : МАВКА_ІНЕТ_УСПІХ;
    wr->обробник(ctx, wr->аргумент, err);
  }

  пристрій_мавки_звільнити(wr);

  if (ctx && !ctx->закривається) {
    size_t write_queue_size =
        uv_stream_get_write_queue_size((uv_stream_t*)&ctx->handle);
    if (write_queue_size == 0 && ctx->буфер_переповнений) {
      ctx->буфер_переповнений = 0;
      if (ctx->listener && ctx->listener->обробник_стікання) {
        ctx->listener->обробник_стікання((адреса)ctx->listener, (адреса)ctx);
      } else if (!ctx->listener && ctx->обробник_стікання) {
        ctx->обробник_стікання((адреса)ctx);
      }
    }

    if (status < 0 && status != UV_ECANCELED) {
      close_connect_context(ctx);
    }
  }
}

void бібліотека_мавки_інет_підключитись(
    природне іа,
    природне порт,
    БібліотекаМавкиІнетКлієнтОбробникПідключення обробник_підключення,
    БібліотекаМавкиІнетКлієнтОбробникДаних обробник_даних,
    БібліотекаМавкиІнетКлієнтОбробникСтікання обробник_стікання,
    БібліотекаМавкиІнетКлієнтОбробникЗакінчення обробник_закінчення,
    БібліотекаМавкиІнетКлієнтОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетКлієнтОбробникВідключення обробник_відключення,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення) {
  ConnectionContext* ctx =
      (ConnectionContext*)пристрій_мавки_виділити(sizeof(ConnectionContext));
  if (!ctx) {
    if (обробник_підключення) {
      обробник_підключення(NULL, МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ);
    }
    if (обробник_знищення) {
      обробник_знищення(аргумент);
    }
    return;
  }

  memset(ctx, 0, sizeof(ConnectionContext));

  ctx->обробник_підключення = обробник_підключення;
  ctx->обробник_даних = обробник_даних;
  ctx->обробник_стікання = обробник_стікання;
  ctx->обробник_помилки = обробник_помилки;
  ctx->обробник_закінчення = обробник_закінчення;
  ctx->обробник_відключення = обробник_відключення;
  ctx->аргумент = аргумент;
  ctx->обробник_знищення = обробник_знищення;

  uv_loop_t* loop = uv_default_loop();

  int init_res = uv_tcp_init(loop, &ctx->handle);
  if (init_res != 0) {
    if (обробник_підключення) {
      обробник_підключення((адреса)ctx, перетворити_помилку_uv(init_res));
    }
    ctx->handle_closed = 1;
    try_free_connection_context(ctx);
    return;
  }

  ctx->handle.data = ctx;

  struct sockaddr_in dest;
  memset(&dest, 0, sizeof(dest));
  dest.sin_family = AF_INET;
  dest.sin_port = htons((uint16_t)порт);
  dest.sin_addr.s_addr = htonl((uint32_t)іа);

  int res = uv_tcp_connect(&ctx->connect_req, &ctx->handle,
                           (const struct sockaddr*)&dest, on_connect_complete);
  if (res != 0) {
    if (обробник_підключення) {
      обробник_підключення((адреса)ctx, перетворити_помилку_uv(res));
    }
    close_connect_context(ctx);
    return;
  }
}

логічне бібліотека_мавки_інет_звʼязок_надіслати(
    адреса адр_звʼязок,
    п8* дані,
    природне розмір,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникНадіслання обробник,
    природне має_власний_обробник_помилки) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;

  if (!ctx || !ctx->підключено || !дані || розмір == 0 || ctx->закривається) {
    if (обробник) {
      обробник(ctx, аргумент, МАВКА_ІНЕТ_ПОМИЛКА_АРГУМЕНТУ);
    }
    return false;
  }

  ConnWriteReq* wr =
      (ConnWriteReq*)пристрій_мавки_виділити(sizeof(ConnWriteReq));
  if (!wr) {
    if (обробник) {
      обробник(ctx, аргумент, МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ);
    }
    return false;
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

    природне err = перетворити_помилку_uv(res);
    ctx->error_emitted = err;
    if (ctx->listener && ctx->listener->обробник_помилки) {
      ctx->listener->обробник_помилки((адреса)ctx->listener, (адреса)ctx, err);
    } else if (!ctx->listener && ctx->обробник_помилки) {
      ctx->обробник_помилки((адреса)ctx, err);
    }
    if (обробник) {
      обробник(ctx, аргумент, err);
    }
    return false;
  }

  return true;
}

static void on_shutdown_complete(uv_shutdown_t* req, int status) {
  ConnEndReq* end_req = (ConnEndReq*)req->data;
  ConnectionContext* ctx = (ConnectionContext*)req->handle->data;

  if (status < 0 && ctx && !ctx->закривається) {
    природне err = перетворити_помилку_uv(status);
    ctx->error_emitted = err;
    if (ctx->listener && ctx->listener->обробник_помилки) {
      ctx->listener->обробник_помилки((адреса)ctx->listener, (адреса)ctx, err);
    } else if (!ctx->listener && ctx->обробник_помилки) {
      ctx->обробник_помилки((адреса)ctx, err);
    }
  }

  if (end_req->обробник) {
    природне err =
        (status < 0) ? перетворити_помилку_uv(status) : МАВКА_ІНЕТ_УСПІХ;
    end_req->обробник(ctx, end_req->аргумент, err);
  }

  пристрій_мавки_звільнити(end_req);
}

static void on_end_write_complete(uv_write_t* req, int status) {
  ConnEndReq* end_req = (ConnEndReq*)req->data;
  ConnectionContext* ctx = (ConnectionContext*)req->handle->data;

  if (status < 0 || !ctx || ctx->закривається) {
    if (end_req->обробник) {
      природне err = (status < 0) ? перетворити_помилку_uv(status)
                                  : МАВКА_ІНЕТ_ПОМИЛКА_НЕ_ПІДʼЄДНАНО;
      end_req->обробник(ctx, end_req->аргумент, err);
    }
    пристрій_мавки_звільнити(end_req);
    return;
  }

  end_req->shutdown_req.data = end_req;
  int res = uv_shutdown(&end_req->shutdown_req, (uv_stream_t*)&ctx->handle,
                        on_shutdown_complete);
  if (res != 0) {
    if (end_req->обробник) {
      end_req->обробник(ctx, end_req->аргумент, перетворити_помилку_uv(res));
    }
    пристрій_мавки_звільнити(end_req);
  }
}

void бібліотека_мавки_інет_звʼязок_закінчити(
    адреса адр_звʼязок,
    п8* дані,
    природне розмір,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗакінчення обробник,
    природне має_власний_обробник_помилки) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;

  if (!ctx || !ctx->підключено || ctx->закривається) {
    if (обробник) {
      обробник(ctx, аргумент, МАВКА_ІНЕТ_ПОМИЛКА_НЕ_ПІДʼЄДНАНО);
    }
    return;
  }

  ConnEndReq* end_req =
      (ConnEndReq*)пристрій_мавки_виділити(sizeof(ConnEndReq));
  if (!end_req) {
    if (обробник) {
      обробник(ctx, аргумент, МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ);
    }
    return;
  }

  memset(end_req, 0, sizeof(ConnEndReq));
  end_req->аргумент = аргумент;
  end_req->обробник = обробник;

  if (дані && розмір > 0) {
    end_req->buf.base = (char*)дані;
    end_req->buf.len = розмір;
    end_req->write_req.data = end_req;

    int res = uv_write(&end_req->write_req, (uv_stream_t*)&ctx->handle,
                       &end_req->buf, 1, on_end_write_complete);
    if (res != 0) {
      if (обробник) {
        обробник(ctx, аргумент, перетворити_помилку_uv(res));
      }
      пристрій_мавки_звільнити(end_req);
    }
  } else {
    end_req->shutdown_req.data = end_req;
    int res = uv_shutdown(&end_req->shutdown_req, (uv_stream_t*)&ctx->handle,
                          on_shutdown_complete);
    if (res != 0) {
      if (обробник) {
        обробник(ctx, аргумент, перетворити_помилку_uv(res));
      }
      пристрій_мавки_звільнити(end_req);
    }
  }
}

void бібліотека_мавки_інет_звʼязок_знищити(адреса адр_звʼязок) {
  // todo: implement
}

void бібліотека_мавки_інет_закрити_звʼязок(адреса адр_звʼязок) {
  close_connect_context((ConnectionContext*)адр_звʼязок);
}

адреса бібліотека_мавки_інет_отримати_аргумент_звʼязку(адреса адр_звʼязок) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;
  return ctx ? ctx->аргумент : NULL;
}

void бібліотека_мавки_інет_записати_аргумент_звʼязку(
    адреса адр_звʼязок,
    адреса аргумент,
    БібліотекаМавкиІнетЗвʼязокОбробникЗнищення обробник_знищення) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;
  if (!ctx)
    return;

  if (ctx->обробник_знищення && ctx->аргумент && ctx->аргумент != аргумент) {
    ctx->обробник_знищення(ctx->аргумент);
  }

  ctx->аргумент = аргумент;
  ctx->обробник_знищення = обробник_знищення;
}

природне бібліотека_мавки_інет_отримати_іа_звʼязку(адреса адр_звʼязок,
                                                   природне* вихід_іа4,
                                                   п8* вихід_іа6) {
  ConnectionContext* ctx = (ConnectionContext*)адр_звʼязок;
  if (!ctx || ctx->закривається)
    return 0;

  struct sockaddr_storage addr;
  int addr_len = sizeof(addr);

  if (uv_tcp_getpeername(&ctx->handle, (struct sockaddr*)&addr, &addr_len) !=
      0) {
    return 0;
  }

  if (addr.ss_family == AF_INET) {
    if (вихід_іа4) {
      struct sockaddr_in* addr_in = (struct sockaddr_in*)&addr;
      *вихід_іа4 = (природне)ntohl(addr_in->sin_addr.s_addr);
    }
    return 4;
  } else if (addr.ss_family == AF_INET6) {
    if (вихід_іа6) {
      struct sockaddr_in6* addr_in6 = (struct sockaddr_in6*)&addr;
      memcpy(вихід_іа6, &addr_in6->sin6_addr, 16);
    }
    return 6;
  }

  return 0;
}

static void on_new_connection(uv_stream_t* server_handle, int status) {
  ListenerContext* listener = (ListenerContext*)server_handle->data;
  if (!listener)
    return;

  if (status < 0) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки((адреса)listener, NULL,
                                 перетворити_помилку_uv(status));
    }
    return;
  }

  ConnectionContext* conn =
      (ConnectionContext*)пристрій_мавки_виділити(sizeof(ConnectionContext));
  if (!conn) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки((адреса)listener, NULL,
                                 МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ);
    }
    return;
  }

  memset(conn, 0, sizeof(ConnectionContext));
  conn->listener = listener;

  uv_loop_t* loop = server_handle->loop;

  if (uv_tcp_init(loop, &conn->handle) != 0) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки((адреса)listener, NULL,
                                 МАВКА_ІНЕТ_ПОМИЛКА_НЕВІДОМА);
    }
    пристрій_мавки_звільнити(conn);
    return;
  }

  conn->handle.data = conn;

  if (uv_accept(server_handle, (uv_stream_t*)&conn->handle) == 0) {
    conn->підключено = 1;
    if (listener->обробник_підключення) {
      listener->обробник_підключення((адреса)listener, (адреса)conn);
    }
    int res = uv_read_start((uv_stream_t*)&conn->handle, conn_alloc_buffer,
                            on_connect_read);
    if (res != 0) {
      природне err = перетворити_помилку_uv(res);
      conn->error_emitted = err;
      if (listener->обробник_помилки) {
        listener->обробник_помилки((адреса)listener, (адреса)conn, err);
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
    if (listener->обробник_зупинки) {
      listener->обробник_зупинки((адреса)listener, МАВКА_ІНЕТ_УСПІХ);
    }
    if (listener->обробник_знищення) {
      listener->обробник_знищення(listener->аргумент);
    }
    пристрій_мавки_звільнити(listener);
  }
}

static void on_listener_close_on_init_fail(uv_handle_t* handle) {
  ListenerContext* listener = (ListenerContext*)handle->data;
  if (listener) {
    if (listener->обробник_знищення) {
      listener->обробник_знищення(listener->аргумент);
    }
    пристрій_мавки_звільнити(listener);
  }
}

void бібліотека_мавки_інет_слухати(
    природне іа,
    природне порт,
    БібліотекаМавкиІнетСлугаОбробникЗапуску обробник_запуску,
    БібліотекаМавкиІнетСлугаОбробникЗупинки обробник_зупинки,
    БібліотекаМавкиІнетСлугаОбробникПідключення обробник_підключення,
    БібліотекаМавкиІнетСлугаОбробникДаних обробник_даних,
    БібліотекаМавкиІнетСлугаОбробникСтікання обробник_стікання,
    БібліотекаМавкиІнетСлугаОбробникЗакінчення обробник_закінчення,
    БібліотекаМавкиІнетСлугаОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетСлугаОбробникВідключення обробник_відключення,
    адреса аргумент,
    БібліотекаМавкиІнетСлугаОбробникЗнищення обробник_знищення) {
  ListenerContext* listener =
      (ListenerContext*)пристрій_мавки_виділити(sizeof(ListenerContext));
  if (!listener) {
    if (обробник_запуску) {
      обробник_запуску(NULL, МАВКА_ІНЕТ_ПОМИЛКА_НЕДОСТАТНЬО_ПАМʼЯТІ);
    }
    if (обробник_знищення) {
      обробник_знищення(аргумент);
    }
    return;
  }

  memset(listener, 0, sizeof(ListenerContext));
  listener->обробник_запуску = обробник_запуску;
  listener->обробник_зупинки = обробник_зупинки;
  listener->обробник_підключення = обробник_підключення;
  listener->обробник_даних = обробник_даних;
  listener->обробник_стікання = обробник_стікання;
  listener->обробник_закінчення = обробник_закінчення;
  listener->обробник_помилки = обробник_помилки;
  listener->обробник_відключення = обробник_відключення;
  listener->обробник_знищення = обробник_знищення;
  listener->аргумент = аргумент;

  uv_loop_t* loop = uv_default_loop();

  int init_res = uv_tcp_init(loop, &listener->server);
  if (init_res != 0) {
    природне err = перетворити_помилку_uv(init_res);
    if (обробник_запуску) {
      обробник_запуску((адреса)listener, err);
    }
    if (listener->обробник_знищення) {
      listener->обробник_знищення(listener->аргумент);
    }
    пристрій_мавки_звільнити(listener);
    return;
  }

  listener->server.data = listener;

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons((uint16_t)порт);
  addr.sin_addr.s_addr = htonl((uint32_t)іа);

  int bind_res =
      uv_tcp_bind(&listener->server, (const struct sockaddr*)&addr, 0);
  if (bind_res != 0) {
    природне err = перетворити_помилку_uv(bind_res);
    if (обробник_запуску) {
      обробник_запуску((адреса)listener, err);
    }
    uv_close((uv_handle_t*)&listener->server, on_listener_close_on_init_fail);
    return;
  }

  int res =
      uv_listen((uv_stream_t*)&listener->server, SOMAXCONN, on_new_connection);
  if (res != 0) {
    природне err = перетворити_помилку_uv(res);
    if (обробник_запуску) {
      обробник_запуску((адреса)listener, err);
    }
    uv_close((uv_handle_t*)&listener->server, on_listener_close_on_init_fail);
    return;
  }

  if (обробник_запуску) {
    обробник_запуску((адреса)listener, МАВКА_ІНЕТ_УСПІХ);
  }
}

адреса бібліотека_мавки_інет_отримати_аргумент_слуги(адреса адр_слуга) {
  ListenerContext* listener = (ListenerContext*)адр_слуга;
  return listener ? listener->аргумент : NULL;
}

static void close_client_walk_cb(uv_handle_t* handle, void* arg) {
  ListenerContext* target_listener = (ListenerContext*)arg;

  if (!uv_is_closing(handle) && handle->type == UV_TCP) {
    ConnectionContext* conn = (ConnectionContext*)handle->data;
    if (conn && conn->listener == target_listener &&
        (uv_handle_t*)&conn->handle == handle) {
      close_connect_context(conn);
    }
  }
}

void бібліотека_мавки_інет_зупинити_слугу(адреса адр_слуга,
                                          природне закрити_підключення) {
  ListenerContext* listener = (ListenerContext*)адр_слуга;
  if (!listener)
    return;

  if (uv_is_closing((uv_handle_t*)&listener->server)) {
    return;
  }

  if (закрити_підключення) {
    uv_loop_t* loop = listener->server.loop;
    if (loop) {
      uv_walk(loop, close_client_walk_cb, listener);
    }
  }

  uv_close((uv_handle_t*)&listener->server, on_listener_close);
}