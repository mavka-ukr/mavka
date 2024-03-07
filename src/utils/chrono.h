#ifndef CHRONO_H
#define CHRONO_H

#define CHRONO_ON 0

#if CHRONO_ON
#define START_CHRONO(name)                                                   \
  std::chrono::time_point<std::chrono::steady_clock> chrono_##name##_start = \
      std::chrono::steady_clock::now();

#define END_CHRONO(name, prefix, pretty)                                      \
  std::chrono::time_point<std::chrono::steady_clock> chrono_##name##_end =    \
      std::chrono::steady_clock::now();                                       \
  std::chrono::duration<unsigned long long, std::milli>                       \
      chrono_##name##_int_ms =                                                \
          std::chrono::duration_cast<std::chrono::milliseconds>(              \
              chrono_##name##_end - chrono_##name##_start);                   \
  std::cout << prefix << pretty << " took " << chrono_##name##_int_ms.count() \
            << "ms" << std::endl;
#else
#define START_CHRONO(name)
#define END_CHRONO(name, prefix, pretty)
#endif

#endif // CHRONO_H
