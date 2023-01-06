#include "../s21_math.h"

long double s21_acos(double x) {
  long double result;

  // Edge cases
  if (s21_isnan(x) || s21_isinf(x) || s21_fabs(x) > 1.0)return S21_NAN;
  if (x == 1.0) return 0.0;

  // Regular cases
  result = s21_atan(s21_sqrt(1 - x * x) / x);

  if (x < 0) result += S21_PI;

  return result;
}
