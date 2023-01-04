#include "../s21_math.h"

long double s21_exp(double x) {
  double taylor_sum;
  double taylor_member;
  int is_x_negative;

  if s21_isnan (x) return x;

  if (s21_isinf(x) && s21_signbit(x)) return +0.0;  // x is -Inf

  if s21_isinf (x) return x;  // +Inf, just an optimization

  is_x_negative = (x < 0) ? 1 : 0;
  x = (x > 0) ? x : -x;

  taylor_sum = 1.0;
  taylor_member = x;

  for (int n = 2; s21_fabs(taylor_member) > S21_EPS && s21_isfinite(taylor_sum);
       n++) {
    taylor_sum += taylor_member;
    taylor_member *= x / n;
  }

  if (is_x_negative) {
    if s21_isfinite(taylor_sum) taylor_sum = 1 / taylor_sum;
    if s21_isinf(taylor_sum) taylor_sum = +0.0;  // when overflow return +0.0
  }

  return (long double)taylor_sum;
}
