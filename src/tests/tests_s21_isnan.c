#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(isnan_return_one_for_float_nan) {
  float x = NAN;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 1);
}
END_TEST

START_TEST(isnan_return_one_for_double_nan) {
  double x = NAN;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 1);
}
END_TEST

START_TEST(isnan_return_zero_for_regular_float) {
  float x = 1.1;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 0);
}
END_TEST

START_TEST(isnan_return_zero_for_regular_double) {
  double x = 1.1;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 0);
}
END_TEST

START_TEST(isnan_return_zero_for_float_infinity) {
  float x = INFINITY;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 0);
}
END_TEST

START_TEST(isnan_return_zero_for_double_infinity) {
  double x = INFINITY;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 0);
}
END_TEST

START_TEST(isnan_return_zero_for_float_negative_infinity) {
  float x = -INFINITY;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 0);
}
END_TEST

START_TEST(isnan_return_zero_for_double_negative_infinity) {
  double x = -INFINITY;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 0);
}
END_TEST

START_TEST(isnan_return_one_for_s21_nan_implementation) {
  double x = S21_NAN;
  int is_nan;

  is_nan = s21_isnan(x);

  ck_assert_int_eq(is_nan, 1);
}
END_TEST

TCase *tcase_s21_isnan(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_isnan` implementation.");

  tcase_add_test(tc, isnan_return_one_for_float_nan);
  tcase_add_test(tc, isnan_return_one_for_double_nan);
  tcase_add_test(tc, isnan_return_zero_for_regular_float);
  tcase_add_test(tc, isnan_return_zero_for_regular_double);
  tcase_add_test(tc, isnan_return_zero_for_float_infinity);
  tcase_add_test(tc, isnan_return_zero_for_double_infinity);
  tcase_add_test(tc, isnan_return_zero_for_float_negative_infinity);
  tcase_add_test(tc, isnan_return_zero_for_double_negative_infinity);
  tcase_add_test(tc, isnan_return_one_for_s21_nan_implementation);

  return tc;
}
