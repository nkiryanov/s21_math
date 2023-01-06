#include "../s21_math.h"

long double _atan_taylor_series(double x) {
  long double series_sum = x;
  long double series_term = 1.0;  // To be sure to enter the loop bellow
  int term_sign = 1;              // On every step the `series_term` change sign

  for (int term_num = 3; s21_fabs(series_term) > S21_EPS; term_num += 2) {
    term_sign *= -1;
    series_term = s21_pow(x, term_num) / term_num;
    series_sum += series_term * term_sign;
  }

  return series_sum;
}

long double s21_atan(double x) {
  long double result;

  // Edge cases
  if (s21_isnan(x) || x == 0.0) return x;
  if s21_isinf (x) return (x > 0) ? S21_PI / 2 : -S21_PI / 2;

  // Regular cases
  result = 0;

  if (s21_fabs(x) == 1.0) result = (x > 0) ? S21_PI / 4 : -S21_PI / 4;
  if (s21_fabs(x) < 1.0) result = _atan_taylor_series(x);
  if (s21_fabs(x) > 1.0) {
    result = -_atan_taylor_series(1 / x);
    result += (x > 0) ? S21_PI / 2 : -S21_PI / 2;
  }

  return result;
}
