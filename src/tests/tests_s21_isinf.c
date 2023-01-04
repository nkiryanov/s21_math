#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(isinf_return_one_for_float_positive_inf) {
  float x = INFINITY;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 1);
}
END_TEST

START_TEST(isinf_return_one_for_float_negative_inf) {
  float x = -INFINITY;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 1);
}
END_TEST

START_TEST(isinf_return_zero_for_float_nan) {
  float x = NAN;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 0);
}
END_TEST

START_TEST(isinf_return_zero_for_normal_float) {
  float x = 1.1;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 0);
}
END_TEST

START_TEST(isinf_return_one_for_double_positive_inf) {
  double x = INFINITY;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 1);
}
END_TEST

START_TEST(isinf_return_one_for_double_negative_inf) {
  double x = -INFINITY;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 1);
}
END_TEST

START_TEST(isinf_return_zero_for_double_nan) {
  double x = NAN;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 0);
}
END_TEST

START_TEST(isinf_return_zero_for_normal_double) {
  double x = 1.1;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 0);
}
END_TEST

START_TEST(s21_defined_infinity_is_actually_infinity) {
  double x = S21_INFINITY;
  int is_infinity;

  is_infinity = s21_isinf(x);

  ck_assert_int_eq(is_infinity, 1);
}
END_TEST

TCase *tcase_s21_isinf(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_isinf` implementation.");

  tcase_add_test(tc, isinf_return_one_for_float_positive_inf);
  tcase_add_test(tc, isinf_return_one_for_float_negative_inf);
  tcase_add_test(tc, isinf_return_zero_for_float_nan);
  tcase_add_test(tc, isinf_return_zero_for_normal_float);
  tcase_add_test(tc, isinf_return_one_for_double_positive_inf);
  tcase_add_test(tc, isinf_return_one_for_double_negative_inf);
  tcase_add_test(tc, isinf_return_zero_for_double_nan);
  tcase_add_test(tc, isinf_return_zero_for_normal_double);
  tcase_add_test(tc, s21_defined_infinity_is_actually_infinity);

  return tc;
}
