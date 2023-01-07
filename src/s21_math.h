#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdint.h>

/* ---------------------------------
        User-faced defines
------------------------------------*/
#define S21_EPS 1e-9
#define S21_EXP 2.71828182846l
#define S21_PI 3.1415926535897932384626433832795

// Maybe not the best, but easiest way
#define S21_INFINITY (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)

// The logic is common for all macros:
// 1. Convert value to u_int representation
// 2. Set null all non meaningful bits
// 3. Compare bits value with same size infinite. NaN has to be bigger
//
// See https://float.exposed/0x7ff0000000000000 what the magic values mean.

#define s21_isnan(x)                                      \
  ((sizeof(x) == sizeof(float))                           \
       ? ((_get_float_bits(x) & 0x7fffffff) > 0x7f800000) \
       : ((_get_double_bits(x) & 0x7fffffffffffffff) > 0x7ff0000000000000))

#define s21_isinf(x)                                       \
  ((sizeof(x) == sizeof(float))                            \
       ? ((_get_float_bits(x) & 0x7fffffff) == 0x7f800000) \
       : ((_get_double_bits(x) & 0x7fffffffffffffff) == 0x7ff0000000000000))

#define s21_isfinite(x)                                   \
  ((sizeof(x) == sizeof(float))                           \
       ? ((_get_float_bits(x) & 0x7fffffff) < 0x7f800000) \
       : ((_get_double_bits(x) & 0x7fffffffffffffff) < 0x7ff0000000000000))

#define s21_signbit(x)                                             \
  ((sizeof(x) == sizeof(float)) ? ((_get_float_bits(x) >> 31) & 1) \
                                : ((_get_double_bits(x) >> 63) & 1))

/* ---------------------------------
        User-faced functions
------------------------------------*/
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);

/* ---------------------------------
         Internal functions
------------------------------------*/
uint32_t _get_float_bits(float x);
uint64_t _get_double_bits(double x);

#endif  // SRC_S21_MATH_H_
