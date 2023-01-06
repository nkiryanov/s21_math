#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long long int integer_part;

  if (s21_isnan(x) || s21_isnan(y) || y == 0.0 || s21_isinf(x)) return S21_NAN;
  if (x == 0.0 && y != 0.0) return x;
  if (s21_isfinite(x) && s21_isinf(y)) return x;

  // Casting to int may cause overflow but it's ok for ranges defined it task.
  integer_part = (long long int)(x / y);

  return (long double)x - (long double)y * integer_part;
}
