#include "../s21_math.h"

long double s21_sin(double x) {
  // Edge cases
  if (s21_isnan(x) || x == 0.0) return x;
  if (s21_isinf(x)) return S21_NAN;

  long double series_sum;
  long double series_term;

  x = s21_fmod(x, 2 * S21_PI);  // Reduce degrees to less whole circle

  series_term = series_sum = x;

  // Taylor series implementation for cos(x)
  for (int series_step = 3; s21_fabs(series_term) > S21_EPS; series_step += 2) {
    series_term *= x * x / (series_step * (series_step - 1)) * -1;
    series_sum += series_term;
  }

  return series_sum;
}
