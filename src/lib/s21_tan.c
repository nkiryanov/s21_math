#include "../s21_math.h"

long double s21_tan(double x) {
  // Edge cases
  if (s21_isnan(x) || x == 0.0) return x;
  if s21_isinf(x) return S21_NAN;

  return s21_sin(x) / s21_cos(x);
}
