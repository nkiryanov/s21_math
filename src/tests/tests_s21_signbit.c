#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(negative_regular_float_return_one) {
  float x = -1.1;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 1);
}
END_TEST

START_TEST(positive_regular_float_return_zero) {
  float x = 1.1;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 0);
}
END_TEST

START_TEST(positive_regular_double_return_zero) {
  double x = 1.1;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 0);
}
END_TEST

START_TEST(negative_regular_double_return_one) {
  double x = -1.1;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 1);
}
END_TEST

START_TEST(positive_zero_return_zero) {
  double x = 0.0;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 0);
}
END_TEST

START_TEST(negative_zero_return_one) {
  double x = -0.0;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_gt(sign, 0);
}
END_TEST

START_TEST(positive_infinity_return_zero) {
  double x = INFINITY;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 0);
}
END_TEST

START_TEST(negative_infinity_return_one) {
  double x = -INFINITY;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_gt(sign, 0);
}
END_TEST

START_TEST(positive_nan_return_zero) {
  double x = NAN;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_eq(sign, 0);
}
END_TEST

START_TEST(negative_nan_return_one) {
  double x = -NAN;
  int sign;

  sign = s21_signbit(x);

  ck_assert_int_gt(sign, 0);
}
END_TEST

TCase *tcase_s21_signbit(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_signbit` implementation.");

  tcase_add_test(tc, negative_regular_float_return_one);
  tcase_add_test(tc, positive_regular_float_return_zero);
  tcase_add_test(tc, negative_regular_double_return_one);
  tcase_add_test(tc, positive_regular_double_return_zero);
  tcase_add_test(tc, positive_zero_return_zero);
  tcase_add_test(tc, negative_zero_return_one);
  tcase_add_test(tc, positive_infinity_return_zero);
  tcase_add_test(tc, negative_infinity_return_one);
  tcase_add_test(tc, positive_nan_return_zero);
  tcase_add_test(tc, negative_nan_return_one);

  return tc;
}
