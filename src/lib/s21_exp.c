#include "../s21_math.h"

double _s21_exp_non_negative(double x) {
  double taylor_sum;
  double taylor_term;
  int taylor_term_num;

  if s21_isnan (x) return x;

  if s21_isinf (x) return x;  // +Inf, just as an optimization

  taylor_sum = 1.0;
  taylor_term = x;
  taylor_term_num = 1;

  while (taylor_term > S21_EPS && s21_isfinite(taylor_sum)) {
    taylor_sum += taylor_term;
    taylor_term *= x / ++taylor_term_num;
  }

  return taylor_sum;
}

long double s21_exp(double x) {
  return (x < 0) ? 1 / _s21_exp_non_negative(-x) : _s21_exp_non_negative(x);
}
