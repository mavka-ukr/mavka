#include <uv.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

typedef struct ListenerContext {
  uv_tcp_t server;
  ІнтернетСлугаОбробникДаних обробник_даних;
  ІнтернетСлугаОбробникПідключення обробник_підключення;
  ІнтернетСлугаОбробникВідключення обробник_відключення;
  ІнтернетСлугаОбробникСтікання обробник_стікання;
  ІнтернетСлугаОбробникПомилки обробник_помилки;
  адреса аргумент;
  ІнтернетСлугаОбробникЗнищення обробник_знищення;
} ListenerContext;

typedef struct ClientContext {
  uv_tcp_t handle;
  ListenerContext* listener;
  адреса аргумент;
  ІнтернетСлугаРозеткаОбробникЗнищення обробник_знищення;
  int буфер_переповнений;
} ClientContext;

typedef struct WriteReq {
  uv_write_t req;
  uv_buf_t buf;
  адреса аргумент;
  ІнтернетОбробникНадіслання обробник;
} WriteReq;

static void alloc_buffer(uv_handle_t* handle,
                         size_t suggested_size,
                         uv_buf_t* buf) {
  buf->base = (char*)пристрій_мавки_виділити(suggested_size);
  buf->len = buf->base ? suggested_size : 0;
}

static void on_client_close(uv_handle_t* handle) {
  ClientContext* client = (ClientContext*)handle->data;
  if (client) {
    if (client->обробник_знищення)
      client->обробник_знищення(client->аргумент);
    пристрій_мавки_звільнити(client);
  }
}

static void on_read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
  ClientContext* client = (ClientContext*)stream->data;
  ListenerContext* listener = client->listener;

  if (nread > 0) {
    if (listener->обробник_даних) {
      listener->обробник_даних((адреса)client, (п8*)buf->base, (природне)nread);
    }
  } else if (nread < 0) {
    if (listener->обробник_відключення) {
      природне err = (nread == UV_EOF) ? 0 : (природне)(-nread);
      listener->обробник_відключення((адреса)client, err);
    }
    uv_close((uv_handle_t*)stream, on_client_close);
  }
}

static void on_new_connection(uv_stream_t* server_handle, int status) {
  ListenerContext* listener = (ListenerContext*)server_handle->data;

  if (status < 0) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки((природне)(-status), listener->аргумент);
    }
    return;
  }

  ClientContext* client =
      (ClientContext*)пристрій_мавки_виділити(sizeof(ClientContext));
  if (!client) {
    if (listener->обробник_помилки) {
      listener->обробник_помилки(UV_ENOMEM, listener->аргумент);
    }
    return;
  }

  client->listener = listener;
  client->handle.data = client;
  client->аргумент = NULL;
  client->обробник_знищення = NULL;
  client->буфер_переповнений = 0;

  if (uv_tcp_init(uv_default_loop(), &client->handle) != 0) {
    if (client->обробник_знищення)
      client->обробник_знищення(client->аргумент);
    пристрій_мавки_звільнити(client);
    return;
  }

  if (uv_accept(server_handle, (uv_stream_t*)&client->handle) == 0) {
    if (listener->обробник_підключення) {
      listener->обробник_підключення((адреса)client);
    }
    uv_read_start((uv_stream_t*)&client->handle, alloc_buffer, on_read);
  } else {
    uv_close((uv_handle_t*)&client->handle, on_client_close);
  }
}

static void on_write_complete(uv_write_t* req, int status) {
  WriteReq* wr = (WriteReq*)req;
  ClientContext* client = (ClientContext*)req->handle->data;

  if (wr->обробник) {
    природне err = (status < 0) ? (природне)(-status) : 0;
    wr->обробник(err, wr->аргумент);
  }

  if (wr->buf.base) {
    пристрій_мавки_звільнити(wr->buf.base);
  }
  пристрій_мавки_звільнити(wr);

  if (client && client->listener && client->listener->обробник_стікання) {
    if (uv_stream_get_write_queue_size((uv_stream_t*)&client->handle) == 0) {
      if (client->буфер_переповнений) {
        client->буфер_переповнений = 0;
        client->listener->обробник_стікання((адреса)client);
      }
    }
  }
}

int бібліотека_інтернет_надіслати(адреса розетка, п8* дані, природне розмір) {
  ClientContext* client = (ClientContext*)розетка;
  if (!client || !дані || розмір == 0)
    return -1;

  WriteReq* wr = (WriteReq*)пристрій_мавки_виділити(sizeof(WriteReq));
  if (!wr)
    return -1;

  wr->buf.base = (char*)пристрій_мавки_виділити(розмір);
  if (!wr->buf.base) {
    пристрій_мавки_звільнити(wr);
    return -1;
  }
  memcpy(wr->buf.base, дані, розмір);
  wr->buf.len = розмір;

  return uv_write(&wr->req, (uv_stream_t*)&client->handle, &wr->buf, 1,
                  on_write_complete);
}

адреса бібліотека_інтернет_служити(
    природне іа,
    природне порт,
    ІнтернетСлугаОбробникДаних обробник_даних,
    ІнтернетСлугаОбробникПідключення обробник_підключення,
    ІнтернетСлугаОбробникВідключення обробник_відключення,
    ІнтернетСлугаОбробникСтікання обробник_стікання,
    ІнтернетСлугаОбробникПомилки обробник_помилки,
    адреса аргумент,
    ІнтернетСлугаОбробникЗнищення обробник_знищення) {
  ListenerContext* listener =
      (ListenerContext*)пристрій_мавки_виділити(sizeof(ListenerContext));
  if (!listener) {
    if (обробник_помилки)
      обробник_помилки(UV_ENOMEM, аргумент);
    if (обробник_знищення)
      обробник_знищення(аргумент);
    return NULL;
  }

  listener->обробник_даних = обробник_даних;
  listener->обробник_підключення = обробник_підключення;
  listener->обробник_відключення = обробник_відключення;
  listener->обробник_стікання = обробник_стікання;
  listener->обробник_помилки = обробник_помилки;
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
  if (uv_ip4_addr("0.0.0.0", (int)порт, &addr) != 0) {
    if (обробник_помилки)
      обробник_помилки(UV_EINVAL, listener->аргумент);
    uv_close((uv_handle_t*)&listener->server, NULL);
    if (listener->обробник_знищення)
      listener->обробник_знищення(listener->аргумент);
    пристрій_мавки_звільнити(listener);
    return NULL;
  }

  if (uv_tcp_bind(&listener->server, (const struct sockaddr*)&addr, 0) != 0) {
    if (обробник_помилки)
      обробник_помилки(UV_EADDRINUSE, listener->аргумент);
    uv_close((uv_handle_t*)&listener->server, NULL);
    if (listener->обробник_знищення)
      listener->обробник_знищення(listener->аргумент);
    пристрій_мавки_звільнити(listener);
    return NULL;
  }

  int res =
      uv_listen((uv_stream_t*)&listener->server, SOMAXCONN, on_new_connection);
  if (res != 0) {
    if (обробник_помилки)
      обробник_помилки((природне)(-res), listener->аргумент);
    uv_close((uv_handle_t*)&listener->server, NULL);
    if (listener->обробник_знищення)
      listener->обробник_знищення(listener->аргумент);
    пристрій_мавки_звільнити(listener);
    return NULL;
  }

  return (адреса)listener;
}

адреса бібліотека_мавки_інет_отримати_аргумент_слуги_з_клієнта(адреса розетка) {
  return ((ClientContext*)розетка)->listener->аргумент;
}

void бібліотека_мавки_інет_записати_аргумент_клієнта_слуги(
    адреса розетка,
    адреса аргумент,
    ІнтернетСлугаРозеткаОбробникЗнищення обробник_знищення) {
  ((ClientContext*)розетка)->аргумент = аргумент;
  ((ClientContext*)розетка)->обробник_знищення = обробник_знищення;
}

адреса бібліотека_мавки_інет_отримати_аргумент_клієнта_слуги(адреса розетка) {
  return ((ClientContext*)розетка)->аргумент;
}

ціле бібліотека_мавки_інет_надіслати_клієнту_слуги(
    адреса розетка,
    п8* дані,
    природне розмір,
    адреса аргумент,
    ІнтернетОбробникНадіслання обробник) {
  ClientContext* client = (ClientContext*)розетка;

  if (!client || !дані || розмір == 0) {
    if (обробник) {
      обробник(UV_EINVAL, аргумент);
    }
    return -1;
  }

  WriteReq* wr = (WriteReq*)пристрій_мавки_виділити(sizeof(WriteReq));
  if (!wr) {
    if (client->listener && client->listener->обробник_помилки) {
      client->listener->обробник_помилки(UV_ENOMEM, client->listener->аргумент);
    }
    if (обробник) {
      обробник(UV_ENOMEM, аргумент);
    }
    return -1;
  }

  wr->buf.base = (char*)пристрій_мавки_виділити(розмір);
  if (!wr->buf.base) {
    пристрій_мавки_звільнити(wr);
    if (client->listener && client->listener->обробник_помилки) {
      client->listener->обробник_помилки(UV_ENOMEM, client->listener->аргумент);
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

  int res = uv_write(&wr->req, (uv_stream_t*)&client->handle, &wr->buf, 1,
                     on_write_complete);

  if (res == 0) {
    if (uv_stream_get_write_queue_size((uv_stream_t*)&client->handle) > 0) {
      client->буфер_переповнений = 1;
    }
  }

  if (res != 0) {
    пристрій_мавки_звільнити(wr->buf.base);
    пристрій_мавки_звільнити(wr);

    if (client->listener && client->listener->обробник_помилки) {
      client->listener->обробник_помилки((природне)(-res),
                                         client->listener->аргумент);
    }
    if (обробник) {
      обробник((природне)(-res), аргумент);
    }
    return res;
  }

  return 0;
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

static void close_client_walk_cb(uv_handle_t* handle, void* arg) {
  ListenerContext* target_listener = (ListenerContext*)arg;

  if (!uv_is_closing(handle) && handle->type == UV_TCP) {
    ClientContext* client = (ClientContext*)handle->data;
    if (client && client->listener == target_listener &&
        (uv_handle_t*)&client->handle == handle) {
      if (client->listener->обробник_відключення)
        client->listener->обробник_відключення((адреса)client, 0);
      uv_close(handle, on_client_close);
    }
  }
}

ціле бібліотека_мавки_інет_зупинити_слуги(адреса слуга,
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