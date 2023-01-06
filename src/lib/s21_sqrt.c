#include "../s21_math.h"

long double s21_sqrt(double x) {
  // Edge cases
  if (s21_isnan(x) || x == 0.0) return x;
  if (x < 0) return S21_NAN;
  if (x == 1.0) return x;

  // Regular case
  return s21_pow(x, 0.5);
}
