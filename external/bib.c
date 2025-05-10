#include <arpa/inet.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <math.h>
#include <memory.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

static int set_non_blocking(int fd) {
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags == -1) {
    return -1;
  }
  return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

static int epoll_ctl_add(int epfd, int fd, uint32_t events) {
  struct epoll_event ev = {0};
  ev.events = events;
  ev.data.fd = fd;
  return epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
}

static int epoll_ctl_del(int epfd, int fd) {
  return epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
}

static int epoll_ctl_mod(int epfd, int fd, uint32_t events) {
  struct epoll_event ev = {0};
  ev.events = events;
  ev.data.fd = fd;
  return epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
}

// --- Mavka Epoll Lib START ---

typedef struct MEpoll MEpoll;
typedef struct MEpollListenerWriteData MEpollListenerWriteData;
typedef struct MEpollListener MEpollListener;

typedef void (*MEpollHandler)(MEpoll* mepoll,
                              MEpollListener* listener,
                              uint32_t event);

typedef struct MEpoll {
  int fd;
  size_t listeners_count;
  MEpollListener* first_listener;
  MEpollListener* last_listener;
} MEpoll;

typedef struct MEpollListenerWriteData {
  MEpollListenerWriteData* next;
  char* data;
  size_t data_size;
  size_t total_written;
} MEpollListenerWriteData;

typedef struct MEpollListener {
  MEpollListener* prev;
  MEpollListener* next;
  int fd;
  MEpollHandler handler;
  void* arg;
  MEpollListenerWriteData* first_write_data;
  MEpollListenerWriteData* last_write_data;
} MEpollListener;

MEpoll* global_mepoll = NULL;

MEpoll* mepoll_get_global() {
  if (global_mepoll == NULL) {
    global_mepoll = (MEpoll*)malloc(sizeof(MEpoll));
    global_mepoll->fd = epoll_create1(0);
    global_mepoll->listeners_count = 0;
    global_mepoll->first_listener = NULL;
    global_mepoll->last_listener = NULL;
  }
  return global_mepoll;
}

MEpollListener* mepoll_create_listener(MEpoll* mepoll,
                                       int fd,
                                       MEpollHandler handler,
                                       void* arg) {
  MEpollListener* listener = (MEpollListener*)malloc(sizeof(MEpollListener));
  listener->prev = NULL;
  listener->next = NULL;
  listener->fd = fd;
  listener->handler = handler;
  listener->arg = arg;
  listener->first_write_data = NULL;
  listener->last_write_data = NULL;

  if (mepoll->first_listener == NULL) {
    mepoll->first_listener = listener;
  }
  if (mepoll->last_listener == NULL) {
    mepoll->last_listener = listener;
  } else {
    listener->prev = mepoll->last_listener;
    mepoll->last_listener->next = listener;
    mepoll->last_listener = listener;
  }

  mepoll->listeners_count++;

  return listener;
}

void mepoll_delete_listener(MEpoll* mepoll, MEpollListener* listener) {
  MEpollListener* prev = listener->prev;
  MEpollListener* next = listener->next;

  if (prev != NULL) {
    prev->next = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }

  if (mepoll->first_listener == listener) {
    mepoll->first_listener = next;
  }
  if (mepoll->last_listener == listener) {
    mepoll->last_listener = prev;
  }

  while (listener->first_write_data) {
    MEpollListenerWriteData* write_data = listener->first_write_data;

    listener->first_write_data = write_data->next;

    if (listener->last_write_data == write_data) {
      listener->last_write_data = NULL;
    }

    free(write_data->data);
    free(write_data);
  }

  free(listener);

  mepoll->listeners_count--;
}

void mepoll_destroy(MEpoll* mepoll) {
  if (mepoll == global_mepoll) {
    global_mepoll = NULL;
  }

  while (mepoll->listeners_count > 0) {
    mepoll_delete_listener(mepoll, mepoll->first_listener);
  }

  close(mepoll->fd);

  free(mepoll);
}

void mepoll_listener_add_write_data(MEpoll* mepoll,
                                    MEpollListener* listener,
                                    char* data,
                                    size_t data_size,
                                    size_t total_written) {
  MEpollListenerWriteData* write_data =
      (MEpollListenerWriteData*)malloc(sizeof(MEpollListenerWriteData));
  write_data->next = NULL;
  write_data->data = strndup(data, data_size);
  write_data->data_size = data_size;
  write_data->total_written = total_written;
  if (listener->first_write_data == NULL) {
    listener->first_write_data = write_data;
  }
  if (listener->last_write_data == NULL) {
    listener->last_write_data = write_data;
  } else {
    listener->last_write_data->next = write_data;
    listener->last_write_data = write_data;
  }
}

MEpollListener* mepoll_find_listener(MEpoll* mepoll, int fd) {
  MEpollListener* listener = mepoll->first_listener;
  while (listener != NULL) {
    if (listener->fd == fd) {
      return listener;
    }
    listener = listener->next;
  }
  return NULL;
}

void mepoll_write_out_listener_data(MEpoll* mepoll, MEpollListener* listener) {
  while (listener->first_write_data != NULL) {
    MEpollListenerWriteData* write_data = listener->first_write_data;

    while (write_data->total_written < write_data->data_size) {
      ssize_t written =
          write(listener->fd, write_data->data + write_data->total_written,
                write_data->data_size - write_data->total_written);
      if (written < 0) {
        if (errno == EINTR) {
          continue;
        }
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
          return;
        }
        return;
      }
      write_data->total_written += written;
    }

    listener->first_write_data = write_data->next;

    if (listener->last_write_data == write_data) {
      listener->last_write_data = NULL;
    }

    free(write_data->data);
    free(write_data);
  }

  if (epoll_ctl_mod(mepoll->fd, listener->fd, EPOLLIN | EPOLLET) == -1) {
    // потім: помилка
    perror("wtf");
  }
}

#define MAX_EVENTS 64

typedef void (*BeforeEachEventHandler)(MEpoll* mepoll, void* arg);

MEpoll* mepoll_run(MEpoll* mepoll,
                   BeforeEachEventHandler before_each,
                   void* before_each_arg) {
  struct epoll_event events[MAX_EVENTS];

  while (true) {
    before_each(mepoll, before_each_arg);

    if (mepoll->listeners_count == 0) {
      break;
    }

    int n = epoll_wait(mepoll->fd, events, MAX_EVENTS, -1);
    if (n == -1) {
      perror("e10: ");
      // потім: помилка
    }

    for (int i = 0; i < n; i++) {
      MEpollListener* listener = mepoll->first_listener;

      // це трохи тупо, але на початок піде
      while (listener != NULL) {
        if (events[i].data.fd == listener->fd) {
          listener->handler(mepoll, listener, events[i].events);
          break;
        }

        listener = listener->next;
      }
    }
  }

  return 0;
}
// --- Mavka Epoll Lib END ---

#define п8 uint8_t
#define п16 uint16_t
#define п32 uint32_t
#define п64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define д32 float
#define д64 double
#define логічне uint8_t
#define позитивне п64
#define ціле ц64
#define дійсне д64
#define ніщо void
#define невідома_адреса void*
#define невідома_памʼять void*
#define памʼять_п8 п8*
#define адреса_памʼять_п8 п8**
#define памʼять_памʼять_п8 п8**
#define адреса_позитивне позитивне*
typedef struct т8 {
  позитивне розмір;
  памʼять_п8 дані;
} т8;
typedef struct ю8 {
  позитивне розмір;
  памʼять_п8 дані;
} ю8;
#define памʼять_т8 т8*
#define памʼять_ю8 ю8*

static char* перетворити_ю8_в_chars(ю8 value) {
  char* copy = (char*)malloc(value.розмір + 1);
  memcpy(copy, value.дані, value.розмір);
  copy[value.розмір] = 0;
  return copy;
}

typedef MEpoll Рушій;
typedef MEpollListener Слухач;

typedef void (*ВідкликНаПідключенняОбслуговувача)(Рушій* рушій,
                                                  Слухач* обслуговувач,
                                                  невідома_адреса аргумент,
                                                  ц32 оф,
                                                  ю8 адр,
                                                  ю8 прт);
typedef void (*ВідкликНаВідключенняОбслуговувача)(Рушій* рушій,
                                                  Слухач* обслуговувач,
                                                  невідома_адреса аргумент,
                                                  ц32 оф);
typedef void (*ВідкликНаДаніОбслуговувача)(Рушій* рушій,
                                           Слухач* обслуговувач,
                                           невідома_адреса аргумент,
                                           ц32 оф,
                                           size_t розмір,
                                           памʼять_п8 дані);
typedef void (*ВідкликНаЗупинкуОбслуговувача)(Рушій* рушій,
                                              Слухач* обслуговувач,
                                              невідома_адреса аргумент);

typedef struct ДаніОбслуговувача {
  невідома_адреса аргумент;
  ВідкликНаПідключенняОбслуговувача відклик_на_підключення;
  ВідкликНаДаніОбслуговувача відклик_на_дані;
  ВідкликНаВідключенняОбслуговувача відклик_на_відключення;
  ВідкликНаЗупинкуОбслуговувача відклик_на_зупинку;
  логічне обслуговувач_зупинено;
  позитивне кількість_підключених_клієнтів;
} ДаніОбслуговувача;

void tcp_client_event_handler(MEpoll* mepoll,
                              MEpollListener* tcp_client_listener,
                              uint32_t event) {
  MEpollListener* tcp_server_listener =
      (MEpollListener*)tcp_client_listener->arg;
  ДаніОбслуговувача* дані = (ДаніОбслуговувача*)tcp_server_listener->arg;

  if (event & EPOLLOUT) {
    mepoll_write_out_listener_data(mepoll, tcp_client_listener);
  }

  if (event & EPOLLIN) {
    while (1) {
      char* buf = (char*)malloc(128);

      int n = read(tcp_client_listener->fd, buf, 128);

      if (n == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
          free(buf);
          break;
        }

        // потім: помилка
        perror("e1: ");
        free(buf);
        break;
      } else if (n == 0) {
        free(buf);
        goto handle_close;
      } else {
        дані->відклик_на_дані(mepoll, tcp_server_listener, дані->аргумент,
                              tcp_client_listener->fd, n, (памʼять_п8)buf);
      }
    }
  }

  return;

handle_close:
  дані->відклик_на_відключення(mepoll, tcp_server_listener, дані->аргумент,
                               tcp_client_listener->fd);

  if (epoll_ctl_del(mepoll->fd, tcp_client_listener->fd) == -1) {
    perror("e2: ");
    // потім: помилка
  }

  if (close(tcp_client_listener->fd) == -1) {
    perror("e3: ");
    // потім: помилка
  }

  mepoll_delete_listener(mepoll, tcp_client_listener);

  дані->кількість_підключених_клієнтів--;

  if (дані->обслуговувач_зупинено &&
      дані->кількість_підключених_клієнтів == 0) {
    // потім: відклик на зупинку
    free(дані);
  }
}

void tcp_server_listener_event_handler(MEpoll* mepoll,
                                       MEpollListener* tcp_server_listener,
                                       uint32_t event) {
  struct sockaddr_in cli_addr = {0};
  socklen_t addr_len = {0};

  int conn_sock =
      accept(tcp_server_listener->fd, (struct sockaddr*)&cli_addr, &addr_len);
  if (conn_sock == -1) {
    perror("e4: ");
    // потім: помилка
    return;
  }

  if (set_non_blocking(conn_sock) == -1) {
    perror("e5: ");
    // потім: помилка
    return;
  }

  if (epoll_ctl_add(mepoll->fd, conn_sock, EPOLLIN | EPOLLET) == -1) {
    perror("e6: ");
    // потім: помилка
    return;
  }

  mepoll_create_listener(mepoll, conn_sock, tcp_client_event_handler,
                         tcp_server_listener);

  ю8 адр = {0};
  ю8 прт = {0};

  ДаніОбслуговувача* дані = (ДаніОбслуговувача*)tcp_server_listener->arg;

  дані->відклик_на_підключення(mepoll, tcp_server_listener, дані->аргумент,
                               conn_sock, адр, прт);

  дані->кількість_підключених_клієнтів++;
}

extern int мавка_біб_запустити_обслуговувач(
    Рушій* рушій,
    ю8 адреса,
    ц32 порт,
    невідома_адреса аргумент,
    ВідкликНаПідключенняОбслуговувача відклик_на_підключення,
    ВідкликНаДаніОбслуговувача відклик_на_дані,
    ВідкликНаВідключенняОбслуговувача відклик_на_відключення,
    ВідкликНаЗупинкуОбслуговувача відклик_на_зупинку) {
  const char* addr_str = перетворити_ю8_в_chars(адреса);

  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(addr_str);
  addr.sin_port = htons(порт);

  free((void*)addr_str);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return -1;
  }

  int optval = 1;
  int setsockopt_result =
      setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
  if (setsockopt_result == -1) {
    return -1;
  }

  int bind_result =
      bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
  if (bind_result == -1) {
    return -1;
  }

  if (set_non_blocking(sockfd) == -1) {
    return -1;
  }

  if (listen(sockfd, 128) == -1) {
    return -1;
  }

  if (epoll_ctl_add(рушій->fd, sockfd, EPOLLIN | EPOLLET) == -1) {
    return -1;
  }

  ДаніОбслуговувача* дані =
      (ДаніОбслуговувача*)malloc(sizeof(ДаніОбслуговувача));
  дані->аргумент = аргумент;
  дані->відклик_на_підключення = відклик_на_підключення;
  дані->відклик_на_дані = відклик_на_дані;
  дані->відклик_на_відключення = відклик_на_відключення;
  дані->відклик_на_зупинку = відклик_на_зупинку;
  дані->кількість_підключених_клієнтів = 0;
  дані->обслуговувач_зупинено = false;

  mepoll_create_listener(рушій, sockfd, tcp_server_listener_event_handler,
                         дані);

  return sockfd;
}

extern int мавка_біб_зупинити_обслуговувач(Рушій* рушій, ц32 оф) {
  if (epoll_ctl_del(рушій->fd, оф) == -1) {
    perror("e7: ");
    // потім: помилка
  }

  if (shutdown(оф, SHUT_RDWR) == -1) {
    perror("e8: ");
    // потім: помилка
  }

  if (close(оф) == -1) {
    perror("e9: ");
    // потім: помилка
  }

  // потім: видалити слухач

  return -1;
}

typedef void (*ВідкликНаПідключенняПідключення)(Рушій* рушій,
                                                Слухач* підключення,
                                                невідома_адреса аргумент);
typedef void (*ВідкликНаВідключенняПідключення)(Рушій* рушій,
                                                Слухач* підключення,
                                                невідома_адреса аргумент);
typedef void (*ВідкликНаДаніПідключення)(Рушій* рушій,
                                         Слухач* підключення,
                                         невідома_адреса аргумент,
                                         size_t розмір,
                                         памʼять_п8 дані);

typedef struct ДаніПідключення {
  невідома_адреса аргумент;
  ВідкликНаПідключенняПідключення відклик_на_підключення;
  ВідкликНаДаніПідключення відклик_на_дані;
  ВідкликНаВідключенняПідключення відклик_на_відключення;
  логічне підключено;
} ДаніПідключення;

void tcp_client_listener_event_handler(MEpoll* mepoll,
                                       MEpollListener* tcp_client_listener,
                                       uint32_t event) {
  ДаніПідключення* дані = (ДаніПідключення*)tcp_client_listener->arg;

  if (event & EPOLLOUT) {
    if (дані->підключено) {
      mepoll_write_out_listener_data(mepoll, tcp_client_listener);
    } else {
      int err;
      socklen_t len = sizeof(err);
      if (getsockopt(tcp_client_listener->fd, SOL_SOCKET, SO_ERROR, &err,
                     &len) < 0 ||
          err != 0) {
        fprintf(stderr, "Connection failed: %s\n", strerror(err));
        goto handle_close;
      }
      дані->підключено = true;
      if (epoll_ctl_mod(mepoll->fd, tcp_client_listener->fd,
                        EPOLLIN | EPOLLET) == -1) {
        // потім: помилка
        perror("wtf2");
      }

      дані->відклик_на_підключення(mepoll, tcp_client_listener, дані->аргумент);
    }
  }

  if (event & EPOLLIN) {
    while (1) {
      char* buf = (char*)malloc(128);

      int n = read(tcp_client_listener->fd, buf, 128);

      if (n == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
          free(buf);
          break;
        }

        // потім: помилка
        perror("ce1: ");
        free(buf);
        goto handle_close;
      } else if (n == 0) {
        free(buf);
        goto handle_close;
      } else {
        дані->відклик_на_дані(mepoll, tcp_client_listener, дані->аргумент, n,
                              (памʼять_п8)buf);
      }
    }
  }

  return;

handle_close:
  дані->відклик_на_відключення(mepoll, tcp_client_listener, дані->аргумент);

  if (epoll_ctl_del(mepoll->fd, tcp_client_listener->fd) == -1) {
    perror("e2: ");
    // потім: помилка
  }

  if (close(tcp_client_listener->fd) == -1) {
    perror("e3: ");
    // потім: помилка
  }

  mepoll_delete_listener(mepoll, tcp_client_listener);

  free(дані);
}

int make_socket_non_blocking(int sockfd) {
  int flags = fcntl(sockfd, F_GETFL, 0);
  if (flags == -1)
    return -1;
  return fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}

extern int мавка_біб_підключити_підключення(
    Рушій* рушій,
    ю8 адреса,
    ц32 порт,
    невідома_адреса аргумент,
    ВідкликНаПідключенняПідключення відклик_на_підключення,
    ВідкликНаДаніПідключення відклик_на_дані,
    ВідкликНаВідключенняПідключення відклик_на_відключення) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    // потім: помилка
    return -1;
  }

  make_socket_non_blocking(sockfd);

  const char* addr_str = перетворити_ю8_в_chars(адреса);

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(порт);
  inet_pton(AF_INET, addr_str, &serv_addr.sin_addr);

  free((void*)addr_str);

  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
    if (errno != EINPROGRESS) {
      perror("connect");
      close(sockfd);
      // потім: помилка
      return -1;
    }
  }

  if (epoll_ctl_add(рушій->fd, sockfd, EPOLLIN | EPOLLOUT | EPOLLET) == -1) {
    perror("epoll_ctl_add");
    close(sockfd);
    // потім: помилка
    return -1;
  }

  ДаніПідключення* дані = (ДаніПідключення*)malloc(sizeof(ДаніПідключення));
  дані->аргумент = аргумент;
  дані->відклик_на_підключення = відклик_на_підключення;
  дані->відклик_на_дані = відклик_на_дані;
  дані->відклик_на_відключення = відклик_на_відключення;
  дані->підключено = false;

  mepoll_create_listener(рушій, sockfd, tcp_client_listener_event_handler,
                         дані);

  return sockfd;
}

extern int мавка_біб_відключити_підключення(Рушій* рушій, ц32 оф) {
  if (epoll_ctl_del(рушій->fd, оф) == -1) {
    perror("ce0");
    // потім: помилка
  }

  if (shutdown(оф, SHUT_RDWR) == -1) {
    perror("ce1");
    // потім: помилка
  }

  if (close(оф) == -1) {
    perror("ce2");
    // потім: помилка
  }

  // потім: видалити слухач

  return -1;
}

extern Рушій* мавка_біб_отримати_рушій() {
  return mepoll_get_global();
}

extern int мавка_біб_надіслати(Рушій* рушій,
                               ц32 оф,
                               позитивне розмір,
                               памʼять_п8 дані) {
  size_t total_written = 0;
  while (total_written < розмір) {
    ssize_t written = write(оф, дані + total_written, розмір - total_written);
    if (written < 0) {
      if (errno == EINTR) {
        continue;
      }
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        MEpollListener* listener = mepoll_find_listener(рушій, оф);
        if (listener) {
          if (epoll_ctl_mod(рушій->fd, listener->fd,
                            EPOLLIN | EPOLLOUT | EPOLLET) == -1) {
            perror("wtf2");
            return -1;
          }
          mepoll_listener_add_write_data(рушій, listener, (char*)дані, розмір,
                                         total_written);
          return 0;
        }
        return -1;
      }
      return -1;
    }
    total_written += written;
  }
  return 0;
}

typedef void (*ОбробникПодіїРушія)(Рушій* рушій,
                                   невідома_адреса дані_обробника_події);

extern ніщо мавка_біб_запустити_рушій(Рушій* рушій,
                                      ОбробникПодіїРушія обробник_події,
                                      невідома_адреса дані_обробника_події) {
  mepoll_run(рушій, обробник_події, дані_обробника_події);
}

extern ніщо мавка_біб_знищити_рушій(Рушій* рушій) {
  mepoll_destroy(рушій);
}
