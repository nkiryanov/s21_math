#include "../s21_math.h"

long double s21_cos(double x) {
  // Edge cases
  if s21_isnan (x) return x;
  if s21_isinf (x) return S21_NAN;
  if (x == 0.0) return 1.0;

  long double series_sum;
  long double series_term;
  int step_sign;

  x = s21_fmod(x, 2 * S21_PI);  // Reduce degrees to less whole circle

  series_sum = 1.0;
  series_term = 1.0;
  step_sign = -1;

  // Taylor series implementation for cos(x)
  for (int series_step = 2; s21_fabs(series_term) > S21_EPS; series_step += 2) {
    series_term *= x * x / (series_step * (series_step - 1));
    series_sum += series_term * step_sign;
    step_sign *= -1;
  }

  return series_sum;
}
