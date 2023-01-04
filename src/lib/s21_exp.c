#include "../s21_math.h"

long double s21_exp(double x) {
  double taylor_sum;
  double taylor_member;

  if s21_isnan(x) return x;

  if (s21_isinf(x) && s21_signbit(x)) return +0.0;

  if s21_isinf(x) return x;  // +Inf, just an optimization

  taylor_sum = 1.0;
  taylor_member = x;

  for (int i = 2; s21_fabs(taylor_member) > S21_EPS && s21_isfinite(taylor_sum);
       i++) {
    taylor_sum += taylor_member;
    taylor_member *= x / i;
  }

  // If overflow happened while counting result for negative `x`
  taylor_sum = (s21_isinf(taylor_sum) && x < 0) ? +0.0 : taylor_sum;

  return (long double)taylor_sum;
}
