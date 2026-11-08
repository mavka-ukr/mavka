#ifndef MAVKA_NUMBERTYPES_H
#define MAVKA_NUMBERTYPES_H

#ifdef MAVKA_CUSTOM_NUMBERTYPES_H_PATH
#include MAVKA_CUSTOM_NUMBERTYPES_H_PATH
#else

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(_WIN32) || defined(_MSC_VER) || defined(__WIN32__)
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__) || \
    defined(__FreeBSD__)
#include <sys/types.h>
#else
typedef ptrdiff_t ssize_t;
#endif

#endif

#endif // MAVKA_NUMBERTYPES_H