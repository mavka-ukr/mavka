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

static int setnonblocking(int sockfd) {
  if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK) == -1) {
    return -1;
  }
  return 0;
}

static void epoll_ctl_add(int epfd, int fd, uint32_t events) {
  struct epoll_event ev;
  ev.events = events;
  ev.data.fd = fd;
  if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev) == -1) {
    perror("epoll_ctl()");
    exit(1);
  }
}

typedef struct Рушій Рушій;
typedef struct Обслуговувач Обслуговувач;
typedef struct Клієнт Клієнт;

typedef struct Клієнт {
  Клієнт* наступний;
  int fd;
} Клієнт;

typedef void (*ВідкликНаПідключення)(Рушій* рушій,
                                     Обслуговувач* обслуговувач,
                                     невідома_адреса аргумент,
                                     ц32 оф);
typedef void (*ВідкликНаВідключення)(Рушій* рушій,
                                     Обслуговувач* обслуговувач,
                                     невідома_адреса аргумент,
                                     ц32 оф);
typedef void (*ВідкликНаДані)(Рушій* рушій,
                              Обслуговувач* обслуговувач,
                              невідома_адреса аргумент,
                              ц32 оф,
                              size_t розмір,
                              памʼять_п8 дані);
typedef void (*ВідкликНаЗупинку)(Рушій* рушій,
                                 Обслуговувач* обслуговувач,
                                 невідома_адреса аргумент);

typedef struct Обслуговувач {
  Обслуговувач* наступний;
  ц32 оф;
  невідома_адреса аргумент;
  Клієнт* перший_клієнт;
  Клієнт* останній_клієнт;
  ВідкликНаПідключення відклик_на_підключення;
  ВідкликНаДані відклик_на_дані;
  ВідкликНаВідключення відклик_на_відключення;
  ВідкликНаЗупинку відклик_на_зупинку;
} Обслуговувач;

typedef struct Рушій {
  int epoll_fd;
  Обслуговувач* перший_обслуговувач;
  Обслуговувач* останній_обслуговувач;
} Рушій;

Рушій* глобальний_рушій = NULL;

extern Рушій* мавка_біб_отримати_рушій() {
  if (глобальний_рушій == NULL) {
    Рушій* рушій = (Рушій*)malloc(sizeof(Рушій));
    рушій->epoll_fd = epoll_create(1);
    рушій->перший_обслуговувач = NULL;
    рушій->останній_обслуговувач = NULL;
    глобальний_рушій = рушій;
  }
  return глобальний_рушій;
}

extern Обслуговувач* мавка_біб_запустити_обслуговувач(
    Рушій* рушій,
    ю8 адреса,
    ц32 порт,
    невідома_адреса аргумент,
    ВідкликНаПідключення відклик_на_підключення,
    ВідкликНаДані відклик_на_дані,
    ВідкликНаВідключення відклик_на_відключення,
    ВідкликНаЗупинку відклик_на_зупинку) {
  const char* addr_str = перетворити_ю8_в_chars(адреса);

  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(порт);

  free((void*)addr_str);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  int optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
  bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

  setnonblocking(sockfd);
  listen(sockfd, 128);
  epoll_ctl_add(рушій->epoll_fd, sockfd, EPOLLIN | EPOLLOUT | EPOLLET);
  printf("imhere\n");

  // todo: handle errors

  Обслуговувач* обслуговувач = (Обслуговувач*)malloc(sizeof(Обслуговувач));
  обслуговувач->наступний = NULL;
  обслуговувач->оф = sockfd;
  обслуговувач->аргумент = аргумент;
  обслуговувач->перший_клієнт = NULL;
  обслуговувач->останній_клієнт = NULL;
  обслуговувач->відклик_на_підключення = відклик_на_підключення;
  обслуговувач->відклик_на_дані = відклик_на_дані;
  обслуговувач->відклик_на_відключення = відклик_на_відключення;
  обслуговувач->відклик_на_зупинку = відклик_на_зупинку;

  if (рушій->перший_обслуговувач == NULL) {
    рушій->перший_обслуговувач = обслуговувач;
  }
  if (рушій->останній_обслуговувач == NULL) {
    рушій->останній_обслуговувач = обслуговувач;
  } else {
    рушій->останній_обслуговувач->наступний = обслуговувач;
    рушій->останній_обслуговувач = обслуговувач;
  }

  return обслуговувач;
}

extern ніщо мавка_біб_надіслати(Рушій* рушій,
                                ц32 оф,
                                позитивне розмір,
                                памʼять_п8 дані) {
  write(оф, дані, розмір);
}

typedef void (*ОбробникПодіїРушія)(Рушій* рушій,
                                   невідома_адреса дані_обробника_події);

extern ніщо мавка_біб_запустити_рушій(Рушій* рушій,
                                      ОбробникПодіїРушія обробник_події,
                                      невідома_адреса дані_обробника_події) {
  struct epoll_event events[32];

  for (;;) {
    обробник_події(рушій, дані_обробника_події);

    if (рушій->перший_обслуговувач == NULL) {
      return;
    }
    printf("wait\n");

    int nfds = epoll_wait(рушій->epoll_fd, events, 32, -1);

    if (nfds == -1) {
      return;
    }

    for (int i = 0; i < nfds; i++) {
      обробник_події(рушій, дані_обробника_події);
      Обслуговувач* обслуговувач = рушій->перший_обслуговувач;
      while (обслуговувач != NULL) {
        if (обслуговувач->оф == events[i].data.fd) {
          struct sockaddr_in cli_addr;
          socklen_t socklen;
          int conn_sock =
              accept(обслуговувач->оф, (struct sockaddr*)&cli_addr, &socklen);
          setnonblocking(conn_sock);
          epoll_ctl_add(рушій->epoll_fd, conn_sock,
                        EPOLLIN | EPOLLET | EPOLLRDHUP | EPOLLHUP);

          Клієнт* клієнт = (Клієнт*)malloc(sizeof(Клієнт));
          клієнт->наступний = NULL;
          клієнт->fd = conn_sock;

          if (обслуговувач->перший_клієнт == NULL) {
            обслуговувач->перший_клієнт = клієнт;
          }
          if (обслуговувач->останній_клієнт == NULL) {
            обслуговувач->останній_клієнт = клієнт;
          } else {
            обслуговувач->останній_клієнт->наступний = клієнт;
            обслуговувач->останній_клієнт = клієнт;
          }

          обслуговувач->відклик_на_підключення(
              рушій, обслуговувач, обслуговувач->аргумент, conn_sock);
          break;
        }
        обслуговувач = обслуговувач->наступний;
      }
      if (events[i].events & EPOLLIN) {
        char* buf = (char*)malloc(128);
        int n = read(events[i].data.fd, buf, 128);
        if (n <= 0 /* || errno == EAGAIN */) {
          free(buf);
          goto next;
        }
        Обслуговувач* обслуговувач = рушій->перший_обслуговувач;
        while (обслуговувач != NULL) {
          Клієнт* клієнт = обслуговувач->перший_клієнт;
          while (клієнт != NULL) {
            if (клієнт->fd == events[i].data.fd) {
              обслуговувач->відклик_на_дані(рушій, обслуговувач,
                                            обслуговувач->аргумент, клієнт->fd,
                                            n, (памʼять_п8)buf);
              goto next;
            }

            клієнт = клієнт->наступний;
          }

          обслуговувач = обслуговувач->наступний;
        }
      }
    next:
      /* check if the connection is closing */
      if (events[i].events & (EPOLLRDHUP | EPOLLHUP)) {
        printf("[+] connection closed\n");
        epoll_ctl(рушій->epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
        close(events[i].data.fd);
        continue;
      }
      printf("event\n");
    }
  }
}
