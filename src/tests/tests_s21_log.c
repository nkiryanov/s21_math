#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(positive_regular) {
  double x = 100;

  ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPS);
}
END_TEST

START_TEST(huge_positive) {
  double x = 10000.323;

  ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPS);
}
END_TEST

START_TEST(positive_one_zero_has_to_be_returned) {
  double x = 1;
  int std_sign;
  int s21_sign;

  std_sign = log(x);
  s21_sign = s21_log(x);

  ck_assert_double_eq(log(x), 0);
  ck_assert_int_eq(std_sign, 0);  // To be sure std lib return +0.0

  ck_assert_double_eq(s21_log(x), 0);
  ck_assert_int_eq(s21_sign, 0);
}
END_TEST

START_TEST(small_positive) {
  double x = 0.23;

  ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPS);
}
END_TEST

START_TEST(smallest_positive) {
  double x = 1e-6;

  ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPS);
}
END_TEST

START_TEST(positive_zero_has_return_negative_infinity) {
  double x = +0.0;
  int std_sign;
  int s21_sign;

  std_sign = signbit(log(x));
  s21_sign = signbit(s21_log(x));

  ck_assert_int_ge(std_sign, 1);  // stdlib should return bigger than 1
  ck_assert_double_infinite(log(x));

  ck_assert_int_ge(s21_sign, 1);
  ck_assert_double_infinite(s21_log(x));
}
END_TEST

START_TEST(negative_zero_has_return_negative_infinity) {
  double x = -0.0;
  int std_sign;
  int s21_sign;

  std_sign = signbit(log(x));
  s21_sign = signbit(s21_log(x));

  ck_assert_int_ge(std_sign, 1);  // stdlib should return bigger than 1
  ck_assert_double_infinite(log(x));

  ck_assert_int_ge(s21_sign, 1);
  ck_assert_double_infinite(s21_log(x));
}
END_TEST

START_TEST(positive_infinity_return_itself) {
  double x = INFINITY;
  int std_sign;
  int s21_sign;

  std_sign = signbit(log(x));
  s21_sign = signbit(s21_log(x));

  ck_assert_int_eq(std_sign, 0);  // stdlib should return 0
  ck_assert_double_infinite(log(x));

  ck_assert_int_eq(s21_sign, 0);
  ck_assert_double_infinite(s21_log(x));
}
END_TEST

START_TEST(any_negative_return_nan) {
  double x = -0.23;

  ck_assert_double_nan(s21_log(x));
}
END_TEST

START_TEST(any_nan_return_itself) {
  double x = NAN;

  ck_assert_double_nan(s21_log(x));
}
END_TEST

TCase *tcase_s21_log(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_log` implementation");

  tcase_add_test(tc, positive_regular);
  tcase_add_test(tc, huge_positive);
  tcase_add_test(tc, positive_one_zero_has_to_be_returned);
  tcase_add_test(tc, small_positive);
  tcase_add_test(tc, smallest_positive);
  tcase_add_test(tc, positive_zero_has_return_negative_infinity);
  tcase_add_test(tc, negative_zero_has_return_negative_infinity);
  tcase_add_test(tc, positive_infinity_return_itself);
  tcase_add_test(tc, any_negative_return_nan);
  tcase_add_test(tc, any_nan_return_itself);

  return tc;
}
