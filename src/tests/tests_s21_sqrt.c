#include <check.h>

#include "../s21_math.h"

START_TEST(positive_value_bigger_one) {
  double x = 12112.12;

  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
}
END_TEST

START_TEST(positive_value_the_biggest) {
  double x = 12e100;
  uint64_t std_bits;
  uint64_t s21_bits;

  // Accuracy may not match (it's ok for huge x)
  // Cause of that we comparing first 54 bits from 64
  std_bits = _get_double_bits(sqrt(x)) >> (64 - 10);
  s21_bits = _get_double_bits(s21_sqrt(x)) >> (64 - 10);

  ck_assert_uint_eq(s21_bits, std_bits);
}
END_TEST

START_TEST(positive_value_in_range_from_zero_to_one) {
  double x = 0.000000007;

  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
}
END_TEST

START_TEST(positive_value_exact_one_returns_itself) {
  int x = 1;

  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
}
END_TEST

START_TEST(positive_zero_return_itself) {
  double x = 0.0;
  int sign;

  sign = signbit(s21_sqrt(x));

  ck_assert_double_eq(s21_sqrt(x), 0.0);
  ck_assert_int_eq(sign, 0);  // for positive values signbit has to be 0
}
END_TEST

START_TEST(negative_zero_return_itself) {
  double x = -0.0;
  int sign;

  sign = signbit(s21_sqrt(x));

  ck_assert_double_eq(s21_sqrt(x), -0.0);
  ck_assert_int_gt(sign, 0);  // for negative zero signbit has NOT to be 0
}
END_TEST

START_TEST(not_a_number_return_itself) {
  double x = NAN;

  ck_assert_double_nan(sqrt(x));  // To be sure that stdlib returns NaN
  ck_assert_double_nan(s21_sqrt(x));
}
END_TEST

START_TEST(negative_value_return_nan) {
  double x = -10;

  ck_assert_double_nan(sqrt(x));  // To be sure that stdlib returns NaN
  ck_assert_double_nan(s21_sqrt(x));
}
END_TEST

START_TEST(positive_infinity_return_itself) {
  double x = INFINITY;
  int std_sign;
  int s21_sign;

  std_sign = signbit(sqrt(x));
  s21_sign = signbit(s21_sqrt(x));

  ck_assert_double_infinite(sqrt(x));  // To be sure stdlib return infinity
  ck_assert_int_eq(std_sign, 0);  // To be sure stdlib return positive infinity

  ck_assert_double_infinite(s21_sqrt(x));
  ck_assert_int_eq(s21_sign, 0);
}
END_TEST

START_TEST(negative_infinity_return_nan) {
  double x = -INFINITY;

  ck_assert_double_nan(sqrt(x));  // To be sure stdlib return positive nan
  ck_assert_double_nan(s21_sqrt(x));
}
END_TEST

TCase *tcase_s21_sqrt(void) {
  TCase *tc;

  tc = tcase_create("Tests for `long double s21_sqrt(double x)` function");

  tcase_add_test(tc, positive_value_bigger_one);
  tcase_add_test(tc, positive_value_the_biggest);
  tcase_add_test(tc, positive_value_in_range_from_zero_to_one);
  tcase_add_test(tc, positive_value_exact_one_returns_itself);
  tcase_add_test(tc, positive_zero_return_itself);
  tcase_add_test(tc, negative_zero_return_itself);
  tcase_add_test(tc, not_a_number_return_itself);
  tcase_add_test(tc, negative_value_return_nan);
  tcase_add_test(tc, positive_infinity_return_itself);
  tcase_add_test(tc, negative_infinity_return_nan);

  return tc;
}
