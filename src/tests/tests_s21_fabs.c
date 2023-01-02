#include <check.h>

#include "../s21_math.h"

START_TEST(positive_value) {
  double x = 12112.12;

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(negative_value) {
  double x = -12112.12;

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(positive_infinity) {
  double x = INFINITY;

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(negative_infinity) {
  double x = -INFINITY;

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(positive_zero) {
  double x = +0.0;

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(not_a_number) {
  double x = NAN;

  ck_assert_double_nan(s21_fabs(x));
}
END_TEST

TCase *tcase_s21_fabs(void) {
  TCase *tc;

  tc = tcase_create("Tests for `long double s21_fabs(double x)` function");

  tcase_add_test(tc, positive_value);
  tcase_add_test(tc, negative_value);
  tcase_add_test(tc, positive_infinity);
  tcase_add_test(tc, negative_infinity);
  tcase_add_test(tc, positive_zero);
  tcase_add_test(tc, negative_zero);
  tcase_add_test(tc, not_a_number);

  return tc;
}
