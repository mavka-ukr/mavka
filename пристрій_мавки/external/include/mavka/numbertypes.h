#ifndef NUMBERTYPES_H
#define NUMBERTYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef MAVKA_TYPES_GUARD
#define MAVKA_TYPES_GUARD

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

#endif // NUMBERTYPES_H