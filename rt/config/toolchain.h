#ifndef TOOLCHAIN_H
#define TOOLCHAIN_H
#if defined(__GNUC__)
#define INLINE static inline __attribute__((always_inline))
#else
#define INLINE static inline
#endif
#endif
