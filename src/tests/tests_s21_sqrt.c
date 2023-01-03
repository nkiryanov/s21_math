#include <check.h>

#include "../s21_math.h"

START_TEST(positive_value_bigger_one) {
  double x = 12112.12;

  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
}
END_TEST

START_TEST(positive_value_in_range_from_zero_to_one) {
  double x = 0.000000007;

  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
}
END_TEST

START_TEST(positive_value_exact_one) {
  int x = 1;

  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
}
END_TEST

START_TEST(positive_zero) {
  double x = 0.0;
  int sign;

  sign = signbit(s21_sqrt(x));

  ck_assert_double_eq(s21_sqrt(x), 0.0);
  ck_assert_int_eq(sign, 0);  // for positive values signbit has to be 0
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;
  int sign;

  sign = signbit(s21_sqrt(x));

  ck_assert_double_eq(s21_sqrt(x), -0.0);
  ck_assert_int_eq(sign, 1);  // for negative values signbit has to be 1
}
END_TEST

START_TEST(not_a_number) {
  double x = NAN;

  ck_assert_double_nan(s21_sqrt(x));
}

TCase *tcase_s21_sqrt(void) {
  TCase *tc;

  tc = tcase_create("Tests for `long double s21_sqrt(double x)` function");

  tcase_add_test(tc, positive_value_bigger_one);
  tcase_add_test(tc, positive_value_in_range_from_zero_to_one);
  tcase_add_test(tc, positive_value_exact_one);
  tcase_add_test(tc, positive_zero);
  tcase_add_test(tc, negative_zero);
  tcase_add_test(tc, not_a_number);

  return tc;
}
