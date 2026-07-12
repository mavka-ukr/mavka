#include <uv.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

typedef struct ConnectContext {
  uv_tcp_t handle;
  uv_connect_t connect_req;
  uv_timer_t timer;

  БібліотекаМавкиІнетПідключенняОбробникПідключення обробник_підключення;
  БібліотекаМавкиІнетПідключенняОбробникДаних обробник_даних;
  БібліотекаМавкиІнетПідключенняОбробникСтікання обробник_стікання;
  БібліотекаМавкиІнетПідключенняОбробникПомилки обробник_помилки;
  БібліотекаМавкиІнетПідключенняОбробникВідключення обробник_відключення;
  БібліотекаМавкиІнетПідключенняОбробникПомилкиПідключення
  обробник_помилки_підключення;
  БібліотекаМавкиІнетПідключенняОбробникЗакінчення обробник_закінчення;
  БібліотекаМавкиІнетПідключенняОбробникЗасидження обробник_засидження;

  адреса аргумент;
  БібліотекаМавкиІнетПідключенняОбробникЗнищення обробник_знищення;

  int буфер_переповнений;
  int підключено;
  int закривається;
} ConnectContext;

typedef struct ConnWriteReq {
  uv_write_t req;
  uv_buf_t buf;
  адреса аргумент;
  БібліотекаМавкиІнетПідключенняОбробникНадіслання обробник;
} ConnWriteReq;

static void conn_alloc_buffer(uv_handle_t* handle,
                              size_t suggested_size,
                              uv_buf_t* buf) {
  buf->base = (char*)пристрій_мавки_виділити(suggested_size);
  buf->len = buf->base ? suggested_size : 0;
}

static void on_connect_client_close(uv_handle_t* handle) {
  ConnectContext* ctx = (ConnectContext*)handle->data;
  if (!ctx)
    return;

  if (ctx->обробник_закінчення) {
    ctx->обробник_закінчення((адреса)ctx);
  }

  if (ctx->обробник_знищення) {
    ctx->обробник_знищення(ctx->аргумент);
  }

  пристрій_мавки_звільнити(ctx);
}

static void close_connect_context(ConnectContext* ctx) {
  if (!ctx || ctx->закривається)
    return;
  ctx->закривається = 1;

  if (!uv_is_closing((uv_handle_t*)&ctx->timer)) {
    uv_timer_stop(&ctx->timer);
    uv_close((uv_handle_t*)&ctx->timer, NULL);
  }

  if (!uv_is_closing((uv_handle_t*)&ctx->handle)) {
    uv_close((uv_handle_t*)&ctx->handle, on_connect_client_close);
  }
}

static void on_connect_read(uv_stream_t* stream,
                            ssize_t nread,
                            const uv_buf_t* buf) {
  ConnectContext* ctx = (ConnectContext*)stream->data;

  if (nread > 0) {
    if (ctx->обробник_даних) {
      ctx->обробник_даних((адреса)ctx, (п8*)buf->base, (природне)nread);
    }
  } else if (nread < 0) {
    if (ctx->обробник_відключення) {
      природне err = (nread == UV_EOF) ? 0 : (природне)(-nread);
      ctx->обробник_відключення((адреса)ctx, err);
    }
    close_connect_context(ctx);
  }

  if (buf->base) {
    пристрій_мавки_звільнити(buf->base);
  }
}

static void on_connect_timeout(uv_timer_t* handle) {
  ConnectContext* ctx = (ConnectContext*)handle->data;

  if (ctx->обробник_засидження) {
    ctx->обробник_засидження((адреса)ctx);
  }

  close_connect_context(ctx);
}

static void on_connect_complete(uv_connect_t* req, int status) {
  ConnectContext* ctx = (ConnectContext*)req->handle->data;

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

  uv_read_start((uv_stream_t*)&ctx->handle, conn_alloc_buffer, on_connect_read);
}

static void on_connect_write_complete(uv_write_t* req, int status) {
  ConnWriteReq* wr = (ConnWriteReq*)req;
  ConnectContext* ctx = (ConnectContext*)req->handle->data;

  if (wr->обробник) {
    природне err = (status < 0) ? (природне)(-status) : 0;
    wr->обробник(err, wr->аргумент);
  }

  if (wr->buf.base) {
    пристрій_мавки_звільнити(wr->buf.base);
  }
  пристрій_мавки_звільнити(wr);

  if (ctx && ctx->обробник_стікання) {
    if (uv_stream_get_write_queue_size((uv_stream_t*)&ctx->handle) == 0) {
      if (ctx->буфер_переповнений) {
        ctx->буфер_переповнений = 0;
        ctx->обробник_стікання((адреса)ctx);
      }
    }
  }
}

адреса бібліотека_інет_підключитись(
    природне іа,
    природне порт,
    БібліотекаМавкиІнетПідключенняОбробникПідключення обробник_підключення,
    БібліотекаМавкиІнетПідключенняОбробникДаних обробник_даних,
    БібліотекаМавкиІнетПідключенняОбробникСтікання обробник_стікання,
    БібліотекаМавкиІнетПідключенняОбробникПомилки обробник_помилки,
    БібліотекаМавкиІнетПідключенняОбробникВідключення обробник_відключення,
    БібліотекаМавкиІнетПідключенняОбробникПомилкиПідключення
        обробник_помилки_підключення,
    БібліотекаМавкиІнетПідключенняОбробникЗакінчення обробник_закінчення,
    БібліотекаМавкиІнетПідключенняОбробникЗасидження обробник_засидження,
    адреса аргумент,
    БібліотекаМавкиІнетПідключенняОбробникЗнищення обробник_знищення) {
  ConnectContext* ctx =
      (ConnectContext*)пристрій_мавки_виділити(sizeof(ConnectContext));
  if (!ctx) {
    if (обробник_помилки) {
      обробник_помилки(UV_ENOMEM, NULL);
    }
    return NULL;
  }

  memset(ctx, 0, sizeof(ConnectContext));

  ctx->обробник_підключення = обробник_підключення;
  ctx->обробник_даних = обробник_даних;
  ctx->обробник_стікання = обробник_стікання;
  ctx->обробник_помилки = обробник_помилки;
  ctx->обробник_відключення = обробник_відключення;
  ctx->обробник_помилки_підключення = обробник_помилки_підключення;
  ctx->обробник_закінчення = обробник_закінчення;
  ctx->обробник_засидження = обробник_засидження;
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

ціле бібліотека_мавки_інет_підключення_надіслати(
    адреса адр_підключення,
    п8* дані,
    природне розмір,
    адреса аргумент,
    БібліотекаМавкиІнетПідключенняОбробникНадіслання обробник) {
  ConnectContext* ctx = (ConnectContext*)адр_підключення;

  if (!ctx || !дані || розмір == 0) {
    if (обробник) {
      обробник(UV_EINVAL, аргумент);
    }
    return -1;
  }

  ConnWriteReq* wr =
      (ConnWriteReq*)пристрій_мавки_виділити(sizeof(ConnWriteReq));
  if (!wr) {
    if (ctx->обробник_помилки) {
      ctx->обробник_помилки(UV_ENOMEM, ctx->аргумент);
    }
    if (обробник) {
      обробник(UV_ENOMEM, аргумент);
    }
    return -1;
  }

  wr->buf.base = (char*)пристрій_мавки_виділити(розмір);
  if (!wr->buf.base) {
    пристрій_мавки_звільнити(wr);
    if (ctx->обробник_помилки) {
      ctx->обробник_помилки(UV_ENOMEM, ctx->аргумент);
    }
    if (обробник) {
      обробник(UV_ENOMEM, аргумент);
    }
    return -1;
  }

  memcpy(wr->buf.base, дані, розмір);
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
    пристрій_мавки_звільнити(wr->buf.base);
    пристрій_мавки_звільнити(wr);

    if (ctx->обробник_помилки) {
      ctx->обробник_помилки((природне)(-res), ctx->аргумент);
    }
    if (обробник) {
      обробник((природне)(-res), аргумент);
    }
    return res;
  }

  return 0;
}

адреса бібліотека_мавки_інет_отримати_аргумент_підключення(
    адреса адр_підключення) {
  return ((ConnectContext*)адр_підключення)->аргумент;
}