// WIP
#include <math.h>

#include "../s21_math.h"

double _pow_natural_exp(double base, unsigned int exp) {
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


long double s21_pow(double base, double exp) {
  double result;

  if (base == 1.0) return 1.0;

  if (exp == 0.0) return 1.0;

  if (exp < 0) {
    result = 1 / _pow_positive_exp(base, -exp);
  } else {
    result = _pow_positive_exp(base, exp);
  }

  return result;
}
