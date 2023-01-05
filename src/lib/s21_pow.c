// WIP
#include <math.h>

#include "../s21_math.h"

double _s21_pow_non_negative_int_exp(double base, unsigned int exp);
long double _s21_pow_non_negative_double_exp(double base, double exp);

long double s21_pow(double base, double exp) {
  double result;

  if (base == 1.0) return 1.0;

  if (exp == 0.0) return 1.0;

  if (exp < 0) {
    result = 1 / _s21_pow_non_negative_double_exp(base, -exp);
  } else {
    result = _s21_pow_non_negative_double_exp(base, exp);
  }

  return result;
}

double _s21_pow_non_negative_int_exp(double base, unsigned int exp) {
  // Just to make the code easier to read and accuracy purpose.
  double result = 1;

  while (exp) {
    if (exp % 2 == 1) {
      result *= base;  // if exp is odd -> do mul manually and exp - 1
      exp--;
    } else {
      base *= base;  // cause x^y^z == x^(y * z)
      exp /= 2;
    }
  }

  return result;
}

long double _s21_pow_non_negative_double_exp(double base, double exp) {
  double result;
  double fractional_exp_part;
  unsigned int integer_exp_part;

  integer_exp_part = (unsigned int)exp;
  fractional_exp_part = exp - integer_exp_part;

  result = _s21_pow_non_negative_int_exp(base, integer_exp_part);
  result += pow(base, fractional_exp_part);

  return result;
}
