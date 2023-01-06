#include "../s21_math.h"

double _reduce_x(double x, int *integer_part_ptr) {
  // Reduce and return `x` that is close to EXP value
  // Two facts is using for that:
  //    1. ln(x * y) = ln(x) + ln(y)
  //    2. ln(e) = 1
  // The integer part returned is `integer_part_ptr` has to be summed
  // with ln(`reduced_x`)
  *integer_part_ptr = 0;

  while (x > S21_EXP) {
    x /= S21_EXP;
    (*integer_part_ptr)++;
  }

  return x;
}

long double s21_log(double x) {
  // Use Halley's method here https://en.wikipedia.org/wiki/Halley%27s_method
  double reduced_x;
  int integer_part;

  double term;
  double prev_term;
  double exp_pow_term;

  if (x == 0) return -S21_INFINITY;
  if (x < 0) return S21_NAN;
  if (s21_isnan(x) || s21_isinf(x)) return x;  // +Inf or NaN possible here

  reduced_x = _reduce_x(x, &integer_part);

  term = 0;
  prev_term = term - 1;  // To be sure to enter the loop bellow

  while (s21_fabs(term - prev_term) > S21_EPS) {
    prev_term = term;
    exp_pow_term = s21_exp(term);
    term += 2 * (reduced_x - exp_pow_term) / (reduced_x + exp_pow_term);
  }

  return term + (double)integer_part;
}
