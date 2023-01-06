// WIP
#include <math.h>

#include "../s21_math.h"

double _pow_natural_exp(double base, unsigned int exp) {
  // Just to make the code easier to read and accuracy purpose.
  double result = 1;

  while (exp) {
    if (exp % 2 != 0) {
      result *= base;  // if exp is odd -> do mul manually and exp - 1
      exp--;
    } else {
      base *= base;  // cause x^y^z == x^(y * z)
      exp /= 2;
    }
  }

  return result;
}

long double _pow_positive_exp(double base, double exp) {
  long double result;
  long double fractional_exp_part;
  unsigned int natural_exp_part;

  natural_exp_part = (unsigned int)s21_floor(exp);
  fractional_exp_part = exp - (long double)natural_exp_part;

  result = _pow_natural_exp(base, natural_exp_part);
  result += pow(base, fractional_exp_part);

  return result;
}

int _is_integer(double x) {
  return (s21_isfinite(x) && s21_fmod(x, 1.0) == 0.0) ? 1 : 0;
}

int _is_even_integer(double x) {
  if (!_is_integer(x)) return 0;

  return ((long long int)x % 2 == 0) ? 1 : 0;
}

int _is_odd_integer(double x) {
  if (!_is_integer(x)) return 0;

  return ((long long int)x % 2 != 0) ? 1 : 0;
}

long double s21_pow(double base, double exp) {
  double result;

  // Documented edge cases
  if (base == 0.0 && exp < 0 && _is_even_integer(exp)) return S21_INFINITY;
  if (base == 1.0) return 1.0;
  if (exp == 0.0) return 1.0;
  if (base == 0.0 && exp > 0) return 0.0;
  if (s21_isinf(exp)) {
    if (base == -1.0) return 1.0;
    if (s21_fabs(base) < 1.0 && exp < 0) return S21_INFINITY;
    if (s21_fabs(base) > 1.0 && exp > 0) return S21_INFINITY;
    if (s21_fabs(base) < 1.0 && exp > 0) return 0.0;
    if (s21_fabs(base) > 1.0 && exp < 0) return 0.0;
  }
  if (s21_isinf(base)) {
    if (base < 0 && exp < 0 && _is_odd_integer(exp)) return -0.0;
    if (base < 0 && exp > 0 && _is_odd_integer(exp)) return -S21_INFINITY;
    if (base < 0 && exp < 0) return +0.0;
    if (base < 0 && exp > 0) return S21_INFINITY;
    if (base > 0 && exp < 0) return +0.0;
    if (base > 0 && exp > 0) return S21_INFINITY;
  }
  if (base < 0 && !_is_integer(exp)) return S21_NAN;

  // Regular cases
  if (exp < 0) {
    result = 1 / _pow_positive_exp(base, -exp);
  } else {
    result = _pow_positive_exp(base, exp);
  }

  return result;
}
