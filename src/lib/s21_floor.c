#include "../s21_math.h"

long double s21_floor(double x) {
  // Obviously it's not a good idea to cast to int because overflow may happen.
  // By the way it's ok for allowed ranges according to task.
  long long int floored_x;

  if (s21_isnan(x) || s21_isinf(x) || (x == 0.0)) return x;

  floored_x = (long long int)x;

  return (x > 0) ? floored_x : floored_x - 1;
}
