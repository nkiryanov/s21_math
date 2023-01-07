#include "../s21_math.h"

long double s21_ceil(double x) {
  // Obviously it's not a good idea to cast to int because overflow may happen.
  // By the way it's ok for allowed ranges according to task.
  long long int ceiled_x;

  if (s21_isnan(x) || s21_isinf(x) || (x == 0.0)) return x;

  ceiled_x = (long long int)x;

  return (x == ceiled_x) ? ceiled_x : (x < 0) ? ceiled_x : ceiled_x + 1;
}
