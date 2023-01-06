#include "../s21_math.h"

long double s21_asin(double x) {
  long double result;

  // Edge cases
  if (s21_isnan(x) || s21_isinf(x) || s21_fabs(x) > 1.0) return S21_NAN;
  if (x == 0) return x;

  // Regular cases
  result = s21_acos(s21_sqrt(1 - x * x));

  return (x > 0) ? result : -result;
}
