#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(if_nan_return_nan) {
  double x = NAN;

  ck_assert_double_nan(tan(x));
  ck_assert_double_nan(s21_tan(x));
}
END_TEST

START_TEST(if_positive_zero_return_itself) {
  double x = 0.0;

  ck_assert_double_eq(tan(x), 0.0);  // To be sure std expected value
  ck_assert_int_eq(signbit(x), 0);

  ck_assert_double_eq(s21_tan(x), 0.0);
  ck_assert_int_eq(signbit(x), 0);
}
END_TEST

START_TEST(if_negative_zero_return_itself) {
  double x = -0.0;

  ck_assert_double_eq(tan(x), 0.0);  // To be sure std expected value
  ck_assert_int_ge(signbit(x), 1);

  ck_assert_double_eq(s21_tan(x), 0.0);
  ck_assert_int_ge(signbit(x), 1);
}
END_TEST

START_TEST(if_positive_infinity_return_nan) {
  double x = INFINITY;

  ck_assert_double_nan(tan(x));
  ck_assert_double_nan(s21_tan(x));
}
END_TEST

START_TEST(if_negative_infinity_return_nan) {
  double x = -INFINITY;

  ck_assert_double_nan(tan(x));
  ck_assert_double_nan(s21_tan(x));
}
END_TEST

START_TEST(positive_regular) {
  double x = M_PI;

  ck_assert_double_eq_tol(s21_tan(x), tan(x), S21_EPS);
}
END_TEST

START_TEST(positive_regular_another_value) {
  double x = 1.0;

  ck_assert_double_eq_tol(s21_tan(x), tan(x), S21_EPS);
}
END_TEST

START_TEST(positive_big_value) {
  double x = 100.0;

  ck_assert_double_eq_tol(s21_tan(x), tan(x), S21_EPS);
}
END_TEST

START_TEST(negative_regular) {
  double x = -M_PI;

  ck_assert_double_eq_tol(s21_tan(x), tan(x), S21_EPS);
}
END_TEST

START_TEST(negative_regular_another_value) {
  double x = -1.0;

  ck_assert_double_eq_tol(s21_tan(x), tan(x), S21_EPS);
}
END_TEST

START_TEST(negative_big_value) {
  double x = -100.0;

  ck_assert_double_eq_tol(s21_tan(x), tan(x), S21_EPS);
}
END_TEST

TCase *tcase_s21_tan(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_tan` implementation");

  tcase_add_test(tc, if_nan_return_nan);
  tcase_add_test(tc, if_positive_zero_return_itself);
  tcase_add_test(tc, if_negative_zero_return_itself);
  tcase_add_test(tc, if_positive_infinity_return_nan);
  tcase_add_test(tc, if_negative_infinity_return_nan);
  tcase_add_test(tc, positive_regular);
  tcase_add_test(tc, positive_regular_another_value);
  tcase_add_test(tc, positive_big_value);
  tcase_add_test(tc, negative_regular);
  tcase_add_test(tc, negative_regular_another_value);
  tcase_add_test(tc, negative_big_value);

  return tc;
}
