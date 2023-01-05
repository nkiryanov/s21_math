#include "../s21_math.h"

long double s21_sqrt(double x) {
  double left_edge;
  double right_edge;
  double middle;

  if (s21_isnan(x) || x == 0.0) return x;

  if (x < 0) return S21_NAN;

  if (s21_fabs(1.0 - x) < S21_EPS) return x;  // return 1.0 for values near 1.0

  left_edge = x > 1 ? 0.0 : x;
  right_edge = x > 1 ? x / 2 : 1.0;

  // For huge `x` use counter to stop iteration cause step delta may
  // be much more than epsilon and it will not work at all (ex. x = 12e1
  for (int i = 0; i <= 400 && (right_edge - left_edge > S21_EPS); i++) {
    middle = (right_edge - left_edge) / 2.0 + left_edge;

    if (middle * middle > x)
      right_edge = middle;
    else
      left_edge = middle;
  }

  return (long double)middle;
}
