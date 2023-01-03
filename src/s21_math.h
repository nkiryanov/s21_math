#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_EPS 1e-7
#define S21_INFINITY 0x7ff0000000000000  // fill exponent with 1, while significant is 0
#define S21_NAN 0x7ff8000000000000  // exponent and first bit of significant is 1

#define s21_isnan(x) \
    ((x) != (x))  // Just comparing to itself. NaN has to return 0

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_sqrt(double x);

#endif  // SRC_S21_MATH_H_
