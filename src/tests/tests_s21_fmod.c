#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(if_x_isnan_return_nan) {
  double x = NAN;
  double y = 34;

  ck_assert_double_nan(s21_fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(if_y_isnan_return_nan) {
  double x = 34;
  double y = NAN;

  ck_assert_double_nan(s21_fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(if_y_is_positive_zero_return_nan) {
  double x = 34;
  double y = +0.0;

  ck_assert_double_nan(s21_fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(if_y_is_negative_zero_return_nan) {
  double x = 34;
  double y = -0.0;

  ck_assert_double_nan(s21_fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(if_x_is_positive_inf_return_nan) {
  double x = INFINITY;
  double y = 3223.23;

  ck_assert_double_nan(s21_fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(if_x_is_negative_inf_return_nan) {
  double x = -INFINITY;
  double y = 3223.23;

  ck_assert_double_nan(s21_fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(if_x_is_positive_zero_and_y_not_zero_return_x) {
  double x = +0.0;
  double y = 3223.23;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));

  ck_assert_int_eq(signbit(fmod(x, y)), 0);
  ck_assert_int_eq(signbit(s21_fmod(x, y)), 0);
}
END_TEST

START_TEST(if_x_is_negative_zero_and_y_not_zero_return_x) {
  double x = -0.0;
  double y = 3223.23;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));

  ck_assert_int_ge(signbit(fmod(x, y)), 1);
  ck_assert_int_ge(signbit(s21_fmod(x, y)), 1);
}
END_TEST

START_TEST(if_x_is_finite_and_y_is_plus_inf_return_x) {
  double x = -2323.22323;
  double y = INFINITY;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(if_x_is_finite_and_y_is_minus_inf_return_x) {
  double x = -2323.22323;
  double y = -INFINITY;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(if_x_is_finite_positive_and_y_finite_positive) {
  double x = 2323.22323;
  double y = 2342.223;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(if_x_is_finite_negative_and_y_finite_positive) {
  double x = -2323.22323;
  double y = 2342.223;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(if_x_is_finite_negative_and_y_finite_negative) {
  double x = -2323.22323;
  double y = -2342.223;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(if_x_is_finite_positive_and_y_finite_negative) {
  double x = 2323.22323;
  double y = -2342.223;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(if_x_is_finite_small_y_is_finite_small) {
  double x = 0.22323;
  double y = -0.0002;

  ck_assert_double_eq_tol(s21_fmod(x, y), fmod(x, y), S21_EPS);
}
END_TEST

START_TEST(if_x_is_integer_and_y_is_exact_one_return_zero) {
  double x = -60.0e10;
  double y = 1.0;

  ck_assert_double_eq(fmod(x, y), 0.0);
  ck_assert_double_eq(s21_fmod(x, y), 0.0);
}
END_TEST

TCase *tcase_s21_fmod(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_fmod` implementation");

  tcase_add_test(tc, if_x_isnan_return_nan);
  tcase_add_test(tc, if_y_isnan_return_nan);
  tcase_add_test(tc, if_y_is_positive_zero_return_nan);
  tcase_add_test(tc, if_y_is_negative_zero_return_nan);
  tcase_add_test(tc, if_x_is_positive_inf_return_nan);
  tcase_add_test(tc, if_x_is_negative_inf_return_nan);
  tcase_add_test(tc, if_x_is_positive_zero_and_y_not_zero_return_x);
  tcase_add_test(tc, if_x_is_negative_zero_and_y_not_zero_return_x);
  tcase_add_test(tc, if_x_is_finite_and_y_is_plus_inf_return_x);
  tcase_add_test(tc, if_x_is_finite_and_y_is_minus_inf_return_x);
  tcase_add_test(tc, if_x_is_finite_positive_and_y_finite_positive);
  tcase_add_test(tc, if_x_is_finite_negative_and_y_finite_positive);
  tcase_add_test(tc, if_x_is_finite_negative_and_y_finite_negative);
  tcase_add_test(tc, if_x_is_finite_positive_and_y_finite_negative);
  tcase_add_test(tc, if_x_is_finite_small_y_is_finite_small);
  tcase_add_test(tc, if_x_is_integer_and_y_is_exact_one_return_zero);

  return tc;
}
