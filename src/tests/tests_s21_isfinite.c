#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(negative_regular_float_is_finite) {
  float x = -1.1;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_ge(is_finite, 1);
}
END_TEST

START_TEST(positive_regular_float_is_finite) {
  float x = 1.1;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_ge(is_finite, 1);
}
END_TEST

START_TEST(positive_regular_double_is_finite) {
  double x = 1.1;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_ge(is_finite, 1);
}
END_TEST

START_TEST(negative_regular_double_is_finite) {
  double x = -1.1;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_ge(is_finite, 1);
}
END_TEST

START_TEST(positive_zero_is_finite) {
  double x = 0.0;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_ge(is_finite, 1);
}
END_TEST

START_TEST(negative_zero_is_finite) {
  double x = -0.0;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_ge(is_finite, 1);
}
END_TEST

START_TEST(positive_infinity_return_zero) {
  double x = INFINITY;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_eq(is_finite, 0);
}
END_TEST

START_TEST(negative_infinity_return_zero) {
  double x = -INFINITY;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_eq(is_finite, 0);
}
END_TEST

START_TEST(positive_nan_return_zero) {
  double x = NAN;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_eq(is_finite, 0);
}
END_TEST

START_TEST(negative_nan_return_zero) {
  double x = -NAN;
  int is_finite;

  is_finite = s21_isfinite(x);

  ck_assert_int_eq(is_finite, 0);
}
END_TEST

TCase *tcase_s21_isfinite(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_isfinite` implementation.");

  tcase_add_test(tc, negative_regular_float_is_finite);
  tcase_add_test(tc, positive_regular_float_is_finite);
  tcase_add_test(tc, positive_regular_double_is_finite);
  tcase_add_test(tc, negative_regular_double_is_finite);
  tcase_add_test(tc, positive_zero_is_finite);
  tcase_add_test(tc, negative_zero_is_finite);
  tcase_add_test(tc, positive_infinity_return_zero);
  tcase_add_test(tc, negative_infinity_return_zero);
  tcase_add_test(tc, positive_nan_return_zero);
  tcase_add_test(tc, negative_nan_return_zero);

  return tc;
}
