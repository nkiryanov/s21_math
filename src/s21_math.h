#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdint.h>

/* ---------------------------------
         Internal functions
------------------------------------*/
uint32_t _get_float_bits(float x);
uint64_t _get_double_bits(double x);

/* ---------------------------------
  User-faced defines and function
------------------------------------*/
#define S21_EPS 1e-7

// Maybe not the best, but easiest way
#define S21_INFINITY (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)

// How it works
// 1. Convert value to u_int representation (sign doesn't matter here)
// 2. Compare bits value with same size infinite. NaN has to be bigger
// See https://float.exposed/0x7ff0000000000000 for what this magic values mean.
#define s21_isnan(x)                                      \
  ((sizeof(x) == sizeof(float))                           \
       ? ((_get_float_bits(x) & 0x7fffffff) > 0x7f800000) \
       : ((_get_double_bits(x) & 0x7fffffffffffffff) > 0x7ff0000000000000))

// How it works
// 1. Convert value to u_int representation (sign doesn't matter here)
// 2. Compare bits value with same size infinite.
// See https://float.exposed/0x7ff0000000000000 for what this magic values mean.
#define s21_isinf(x)                                       \
  ((sizeof(x) == sizeof(float))                            \
       ? ((_get_float_bits(x) & 0x7fffffff) == 0x7f800000) \
       : ((_get_double_bits(x) & 0x7fffffffffffffff) == 0x7ff0000000000000))

#define s21_signbit(x)                                             \
  ((sizeof(x) == sizeof(float)) ? ((_get_float_bits(x) >> 31) & 1) \
                                : ((_get_double_bits(x) >> 63) & 1))

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_sqrt(double x);

#endif  // SRC_S21_MATH_H_
