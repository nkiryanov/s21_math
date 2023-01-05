#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(regular_positive) {
  double x = 23.329239;

  ck_assert_double_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(small_positive) {
  double x = 0.000001223;

  ck_assert_double_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(huge_positive_but_not_overflow) {
  double x = 150.329239;
  uint64_t std_first_16_digits;
  uint64_t s21_first_16_digits;

  std_first_16_digits = _get_double_bits(exp(x)) >> (64 - 16);
  s21_first_16_digits = _get_double_bits(exp(x)) >> (64 - 16);

  // We don't have very good accuracy, but first 16 digits has to be enough
  ck_assert_uint_eq(s21_first_16_digits, std_first_16_digits);
}
END_TEST

START_TEST(huge_positive_must_overflow) {
  double x = 800;

  ck_assert_double_infinite(exp(x));  // To be sure stdlib overflow
  ck_assert_double_infinite(s21_exp(x));
}
END_TEST

START_TEST(regular_negative) {
  double x = -23.2203023;

  ck_assert_double_eq_tol(exp(x), s21_exp(x), S21_EPS);
}
END_TEST

START_TEST(small_negative) {
  double x = -0.000001223;

  ck_assert_double_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(huge_negative_but_not_overflow) {
  double x = -100.000001223;

  ck_assert_double_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(huge_negative_must_overflow) {
  double x = -800.2203023;
  int std_sign;
  int s21_sign;

  std_sign = signbit(exp(x));
  s21_sign = signbit(s21_exp(x));

  ck_assert_double_eq(exp(x), 0.0);  // To be sure stdlib return 0
  ck_assert_int_eq(std_sign, 0);     // To be sure stdlib return +0.0

  ck_assert_double_eq(s21_exp(x), 0.0);
  ck_assert_int_eq(s21_sign, 0);
}
END_TEST

START_TEST(positive_nan_return_nan) {
  double x = NAN;

  ck_assert_double_nan(exp(x));  // To be sure stdlib return Nan
  ck_assert_double_nan(s21_exp(x));
}
END_TEST

START_TEST(positive_infinity_return_itself) {
  double x = INFINITY;
  int std_sign;
  int s21_sign;

  std_sign = signbit(exp(x));
  s21_sign = signbit(s21_exp(x));

  ck_assert_double_infinite(exp(x));
  ck_assert_int_eq(std_sign, 0);  // to be sure stdlib return positive infinity

  ck_assert_double_infinite(exp(x));
  ck_assert_int_eq(s21_sign, 0);
}
END_TEST

START_TEST(negative_infinity_return_negative_zero) {
  double x = -INFINITY;
  int std_sign;
  int s21_sign;

  std_sign = signbit(exp(x));
  s21_sign = signbit(s21_exp(x));

  ck_assert_double_eq(exp(x), 0);  // To be sure stdlib return 0
  ck_assert_int_eq(std_sign, 0);   // To be sure stdlib return +0.0

  ck_assert_ldouble_eq(s21_exp(x), 0);
  ck_assert_int_eq(s21_sign, 0);
}
END_TEST

START_TEST(negative_zero_return_one) {
  double x = -0.0;

  ck_assert_double_eq(exp(x), 1.0);  // To be sure stdlib return 1.0
  ck_assert_ldouble_eq(s21_exp(x), 1.0);
}
END_TEST

START_TEST(positive_zero_return_one) {
  double x = +0.0;

  ck_assert_double_eq(exp(x), 1.0);  // To be sure stdlib return 1.0
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
}
END_TEST

TCase *tcase_s21_exp(void) {
  TCase *tc;

  tc = tcase_create("Test for `s21_exp` implementation.");

  tcase_add_test(tc, regular_positive);
  tcase_add_test(tc, small_positive);
  tcase_add_test(tc, huge_positive_but_not_overflow);
  tcase_add_test(tc, huge_positive_must_overflow);
  tcase_add_test(tc, small_negative);
  tcase_add_test(tc, regular_negative);
  tcase_add_test(tc, huge_negative_but_not_overflow);
  tcase_add_test(tc, huge_negative_must_overflow);
  tcase_add_test(tc, positive_nan_return_nan);
  tcase_add_test(tc, positive_infinity_return_itself);
  tcase_add_test(tc, negative_infinity_return_negative_zero);
  tcase_add_test(tc, negative_zero_return_one);
  tcase_add_test(tc, positive_zero_return_one);

  return tc;
}
