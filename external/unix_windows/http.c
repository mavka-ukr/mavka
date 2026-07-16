#include <curl/curl.h>
#include <uv.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

typedef struct {
  uv_work_t work;
  char* url;
  char* method;
  char* payload;
  char* content_type;

  CURLcode err_code;
  long status_code;
  char* response_buffer;
  size_t response_len;

  БібліотекаМавкиХТТПВідклик user_cb;
  void* user_arg;
} http_req_t;

static void* my_malloc(size_t size) {
  return пристрій_мавки_виділити(size);
}

static void my_free(void* ptr) {
  пристрій_мавки_звільнити(ptr);
}

static void* my_realloc(void* ptr, size_t size) {
  return пристрій_мавки_перевиділити(ptr, size);
}

static void* my_calloc(size_t count, size_t size) {
  return каллок(count, size);
}

static char* my_strdup(const char* str) {
  return стрдуп(str);
}

int custom_init(void) {
  if (uv_replace_allocator(my_malloc, my_realloc, my_calloc, my_free) != 0) {
    return -1;
  }

  CURLcode curl_err = curl_global_init_mem(CURL_GLOBAL_ALL, my_malloc, my_free,
                                           my_realloc, my_strdup, my_calloc);

  if (curl_err != CURLE_OK) {
    return -1;
  }

  return 0;
}

static size_t write_cb(char* ptr, size_t size, size_t nmemb, void* userdata) {
  http_req_t* hreq = (http_req_t*)userdata;
  size_t total = size * nmemb;

  char* new_buf = пристрій_мавки_перевиділити(hreq->response_buffer,
                                              hreq->response_len + total + 1);
  if (!new_buf)
    return 0;

  hreq->response_buffer = new_buf;
  мемкоп(hreq->response_buffer + hreq->response_len, ptr, total);
  hreq->response_len += total;
  hreq->response_buffer[hreq->response_len] = '\0';

  return total;
}

static void http_work_cb(uv_work_t* req) {
  http_req_t* hreq = (http_req_t*)req->data;
  CURL* curl = curl_easy_init();
  if (!curl) {
    hreq->err_code = CURLE_FAILED_INIT;
    return;
  }

  struct curl_slist* headers = NULL;

  curl_easy_setopt(curl, CURLOPT_URL, hreq->url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, hreq);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  if (strcmp(hreq->method, "POST") == 0) {
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
  } else if (strcmp(hreq->method, "GET") != 0) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, hreq->method);
  }

  if (hreq->payload) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, hreq->payload);
  }

  if (hreq->content_type) {
    char header_buf[256];
    snprintf(header_buf, sizeof(header_buf), "Content-Type: %s",
             hreq->content_type);
    headers = curl_slist_append(headers, header_buf);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  }

  hreq->err_code = curl_easy_perform(curl);
  if (hreq->err_code == CURLE_OK) {
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &hreq->status_code);
  }

  if (headers)
    curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
}

static void http_after_work_cb(uv_work_t* req, int status) {
  http_req_t* hreq = (http_req_t*)req->data;

  if (hreq->user_cb) {
    hreq->user_cb(hreq->err_code, hreq->status_code, (п8*)hreq->response_buffer,
                  hreq->response_len, hreq->user_arg);
  }

  пристрій_мавки_звільнити(hreq->url);
  пристрій_мавки_звільнити(hreq->method);
  if (hreq->payload)
    пристрій_мавки_звільнити(hreq->payload);
  if (hreq->content_type)
    пристрій_мавки_звільнити(hreq->content_type);
  if (hreq->response_buffer)
    пристрій_мавки_звільнити(hreq->response_buffer);
  пристрій_мавки_звільнити(hreq);
}

static int http_request(uv_loop_t* loop,
                        const char* method,
                        const char* url,
                        const char* payload,
                        const char* content_type,
                        БібліотекаМавкиХТТПВідклик cb,
                        void* arg) {
  http_req_t* hreq = calloc(1, sizeof(http_req_t));
  if (!hreq)
    return -1;

  hreq->url = strdup(url);
  hreq->method = strdup(method);
  if (payload)
    hreq->payload = strdup(payload);
  if (content_type)
    hreq->content_type = strdup(content_type);

  hreq->user_cb = cb;
  hreq->user_arg = arg;
  hreq->work.data = hreq;

  return uv_queue_work(loop, &hreq->work, http_work_cb, http_after_work_cb);
}

void бібліотека_мавки_хттп_гет(п8* дані_урл,
                               природне розмір_урл,
                               БібліотекаМавкиХТТПВідклик відклик,
                               адреса аргумент) {
  char* url = (char*)пристрій_мавки_виділити(розмір_урл + 1);
  if (!url)
    return;

  for (природне i = 0; i < розмір_урл; i++) {
    url[i] = (char)дані_урл[i];
  }
  url[розмір_урл] = '\0';

  http_request(uv_default_loop(), "GET", url, NULL, NULL, відклик, аргумент);

  пристрій_мавки_звільнити(url);
}