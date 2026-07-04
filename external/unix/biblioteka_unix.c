#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mavka/biblioteka.h"
#include "mavka/prystriy.h"

р64 бібліотека_мавки_синус_р64(р64 значення) {
  return sin(значення);
}

р64 бібліотека_мавки_косинус_р64(р64 значення) {
  return cos(значення);
}

р64 бібліотека_мавки_тангенс_р64(р64 значення) {
  return tan(значення);
}

р64 бібліотека_мавки_арксинус_р64(р64 значення) {
  return asin(значення);
}

р64 бібліотека_мавки_арккосинус_р64(р64 значення) {
  return acos(значення);
}

р64 бібліотека_мавки_арктангенс_р64(р64 значення) {
  return atan(значення);
}

р64 бібліотека_мавки_арктангенс2_р64(р64 а, р64 б) {
  return atan2(а, б);
}

р64 бібліотека_мавки_абсолютне_р64(р64 значення) {
  return fabs(значення);
}

р64 бібліотека_мавки_експонента_р64(р64 значення) {
  return exp(значення);
}

р64 бібліотека_мавки_корінь_р64(р64 значення) {
  return sqrt(значення);
}

р64 бібліотека_мавки_стеля_р64(р64 значення) {
  return ceil(значення);
}

р64 бібліотека_мавки_підлога_р64(р64 значення) {
  return floor(значення);
}

р64 бібліотека_мавки_округлити_р64(р64 значення) {
  return round(значення);
}

р64 бібліотека_мавки_остача_від_ділення_р64(р64 а, р64 б) {
  return fmod(а, б);
}

// видалити файл або папку за шляхом force recursively
логічне бібліотека_мавки_видалити(п8* дані_шляху, природне розмір_шляху) {
  char* шлях = (char*)malloc(розмір_шляху + 1);
  if (!шлях) {
    return false;
  }
  memcpy(шлях, дані_шляху, розмір_шляху);
  шлях[розмір_шляху] = '\0';

  struct stat статус;
  if (stat(шлях, &статус) == -1) {
    free(шлях);
    return false;
  }

  if (S_ISDIR(статус.st_mode)) {
    // Delete directory recursively
    DIR* папка = opendir(шлях);
    if (!папка) {
      free(шлях);
      return false;
    }

    struct dirent* запис;
    логічне успіх = true;
    while ((запис = readdir(папка)) != NULL) {
      if (strcmp(запис->d_name, ".") == 0 || strcmp(запис->d_name, "..") == 0) {
        continue;
      }

      size_t довжина_шляху = strlen(шлях) + strlen(запис->d_name) + 2;
      char* повний_шлях = (char*)malloc(довжина_шляху);
      if (!повний_шлях) {
        успіх = false;
        break;
      }
      snprintf(повний_шлях, довжина_шляху, "%s/%s", шлях, запис->d_name);

      if (!бібліотека_мавки_видалити((п8*)повний_шлях, strlen(повний_шлях))) {
        успіх = false;
      }
      free(повний_шлях);
    }

    closedir(папка);

    if (!успіх) {
      free(шлях);
      return false;
    }

    int ok = (rmdir(шлях) == 0) ? true : false;
    free(шлях);
    return ok;
  } else {
    // Delete file
    логічне результат = unlink(шлях) == 0 ? true : false;
    free(шлях);
    return результат;
  }
}

логічне бібліотека_мавки_дописати_файл(п8* дані_шляху,
                                       природне розмір_шляху,
                                       п8* дані_даних,
                                       природне розмір_даних) {
  char* шлях = (char*)malloc(розмір_шляху + 1);
  if (!шлях) {
    return false;
  }
  memcpy(шлях, дані_шляху, розмір_шляху);
  шлях[розмір_шляху] = '\0';

  FILE* файл = fopen((const char*)шлях, "ab");
  if (!файл) {
    free(шлях);
    return false;
  }

  size_t записано = fwrite(дані_даних, 1, розмір_даних, файл);
  fclose(файл);
  free(шлях);

  return записано == розмір_даних;
}

логічне бібліотека_мавки_записати_файл(п8* дані_шляху,
                                       природне розмір_шляху,
                                       п8* дані_даних,
                                       природне розмір_даних) {
  char* шлях = (char*)malloc(розмір_шляху + 1);
  if (!шлях) {
    return false;
  }
  memcpy(шлях, дані_шляху, розмір_шляху);
  шлях[розмір_шляху] = '\0';

  FILE* файл = fopen((const char*)шлях, "wb");
  if (!файл) {
    free(шлях);
    return false;
  }

  size_t записано = fwrite(дані_даних, 1, розмір_даних, файл);
  fclose(файл);
  free(шлях);

  return записано == розмір_даних;
}

логічне бібліотека_мавки_прочитати_файл(п8* дані_шляху,
                                        природне розмір_шляху,
                                        Дані* вихід) {
  char* шлях = (char*)malloc(розмір_шляху + 1);
  if (!шлях) {
    return false;
  }
  memcpy(шлях, дані_шляху, розмір_шляху);
  шлях[розмір_шляху] = '\0';
  FILE* файл = fopen((const char*)шлях, "rb");
  if (!файл) {
    free(шлях);
    return false;
  }

  fseek(файл, 0, SEEK_END);
  вихід->розмір = ftell(файл);
  fseek(файл, 0, SEEK_SET);

  вихід->дані = (п8*)malloc(вихід->розмір);
  if (!вихід->дані) {
    fclose(файл);
    free(шлях);
    return false;
  }

  size_t прочитано = fread(вихід->дані, 1, вихід->розмір, файл);
  fclose(файл);

  if (прочитано != вихід->розмір) {
    free(вихід->дані);
    free(шлях);
    return false;
  }

  free(шлях);

  return true;
}

логічне бібліотека_мавки_створити_папку(п8* дані_шляху, природне розмір_шляху) {
  char* шлях = (char*)malloc(розмір_шляху + 1);
  if (!шлях) {
    return false;
  }
  memcpy(шлях, дані_шляху, розмір_шляху);
  шлях[розмір_шляху] = '\0';

  // Check if directory already exists
  struct stat статус;
  if (stat(шлях, &статус) == 0 && S_ISDIR(статус.st_mode)) {
    free(шлях);
    return true;
  }

  // Create a copy to parse
  char* копія_шляху = (char*)malloc(розмір_шляху + 1);
  if (!копія_шляху) {
    free(шлях);
    return false;
  }
  memcpy(копія_шляху, дані_шляху, розмір_шляху);
  копія_шляху[розмір_шляху] = '\0';

  // Create directories recursively
  for (size_t я = 0; я < розмір_шляху; я++) {
    if (копія_шляху[я] == '/') {
      копія_шляху[я] = '\0';
      if (я > 0) { // Skip if it's the root /
        if (mkdir((const char*)копія_шляху, 0755) == -1) {
          if (errno != EEXIST) {
            free(копія_шляху);
            free(шлях);
            return false;
          }
        }
      }
      копія_шляху[я] = '/';
    }
  }

  // Create the final directory
  if (mkdir((const char*)шлях, 0755) == -1) {
    if (errno != EEXIST) {
      free(копія_шляху);
      free(шлях);
      return false;
    }
    // EEXIST occurred - verify it's actually a directory, not a file
    if (stat(шлях, &статус) == 0 && !S_ISDIR(статус.st_mode)) {
      free(копія_шляху);
      free(шлях);
      return false;
    }
  }

  free(копія_шляху);
  free(шлях);
  return true;
}

static логічне встановити_закриття_при_виконанні(int дескриптор) {
  int прапори = fcntl(дескриптор, F_GETFD);
  if (прапори == -1) {
    return false;
  }
  return fcntl(дескриптор, F_SETFD, прапори | FD_CLOEXEC) != -1;
}

static логічне прочитати_потік_в_дані(int дескриптор, Дані* вихід) {
  const size_t крок = 4096;
  size_t ємність = 0;
  size_t використано = 0;
  п8* буфер = NULL;

  while (true) {
    if (використано + крок > ємність) {
      size_t наступна_ємність = ємність == 0 ? крок : ємність * 2;
      if (наступна_ємність < використано + крок) {
        наступна_ємність = використано + крок;
      }
      п8* новий_буфер = (п8*)realloc(буфер, наступна_ємність);
      if (!новий_буфер) {
        free(буфер);
        return false;
      }
      буфер = новий_буфер;
      ємність = наступна_ємність;
    }

    ssize_t прочитано = read(дескриптор, буфер + використано, крок);
    if (прочитано < 0) {
      if (errno == EINTR) {
        continue;
      }
      free(буфер);
      return false;
    }
    if (прочитано == 0) {
      break;
    }

    використано += (size_t)прочитано;
  }

  if (використано == 0) {
    free(буфер);
    вихід->розмір = 0;
    вихід->дані = NULL;
    return true;
  }

  п8* обрізаний_буфер = (п8*)realloc(буфер, використано);
  if (обрізаний_буфер) {
    буфер = обрізаний_буфер;
  }

  вихід->розмір = використано;
  вихід->дані = буфер;
  return true;
}