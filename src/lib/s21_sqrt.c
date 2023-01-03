#include "../s21_math.h"

long double s21_sqrt(double x) {
  double left_edge;
  double right_edge;
  double middle;

  if s21_isnan(x)
    return x;

  if (x == 0.0)
    return x;

  if (s21_fabs(x - 1.0) < S21_EPS)
    return x;

  left_edge = x > 1 ? 0.0 : x;
  right_edge = x > 1 ? x : 1.0;

  while (right_edge - left_edge > S21_EPS) {
    middle = (right_edge - left_edge) / 2.0 + left_edge;

    if (middle * middle > x)
      right_edge = middle;
    else
      left_edge = middle;
  }

  return (long double)middle;
}
