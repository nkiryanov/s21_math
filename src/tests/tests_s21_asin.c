#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(if_nan_return_nan) {
  double x = NAN;

  ck_assert_double_nan(asin(x));
  ck_assert_double_nan(s21_asin(x));
}
END_TEST

START_TEST(if_bigger_one_return_nan) {
  double x = 1.001;

  ck_assert_double_nan(asin(x));
  ck_assert_double_nan(s21_asin(x));
}
END_TEST

START_TEST(if_less_minus_one_return_nan) {
  double x = -1.001;

  ck_assert_double_nan(asin(x));
  ck_assert_double_nan(s21_asin(x));
}
END_TEST

START_TEST(if_plus_inf_return_nan) {
  double x = INFINITY;

  ck_assert_double_nan(asin(x));
  ck_assert_double_nan(s21_asin(x));
}
END_TEST

START_TEST(if_minus_inf_return_nan) {
  double x = -INFINITY;

  ck_assert_double_nan(asin(x));
  ck_assert_double_nan(s21_asin(x));
}
END_TEST

START_TEST(positive_zero_return_itself) {
  double x = +0.0;

  ck_assert_double_eq(asin(x), +0.0);
  ck_assert_int_eq(signbit(asin(x)), 0);

  ck_assert_double_eq(s21_asin(x), +0.0);
  ck_assert_int_eq(signbit(s21_asin(x)), 0);
}
END_TEST

START_TEST(negative_zero_return_itself) {
  double x = -0.0;

  ck_assert_double_eq(asin(x), -0.0);
  ck_assert_int_ge(signbit(asin(x)), 1);

  ck_assert_double_eq(s21_asin(x), -0.0);
  ck_assert_int_ge(signbit(s21_asin(x)), 1);
}
END_TEST

START_TEST(positive_near_zero) {
  double x = +0.0002;

  ck_assert_double_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(positive_near_one) {
  double x = +0.9902;

  ck_assert_double_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(negative_near_minus_zero) {
  double x = -0.0012;

  ck_assert_double_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(negative_near_minus_one) {
  double x = -0.9998;

  ck_assert_double_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

TCase *tcase_s21_asin(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_asin` implementation");

  tcase_add_test(tc, if_nan_return_nan);
  tcase_add_test(tc, if_bigger_one_return_nan);
  tcase_add_test(tc, if_plus_inf_return_nan);
  tcase_add_test(tc, if_minus_inf_return_nan);
  tcase_add_test(tc, if_less_minus_one_return_nan);
  tcase_add_test(tc, positive_zero_return_itself);
  tcase_add_test(tc, negative_zero_return_itself);
  tcase_add_test(tc, negative_zero_return_itself);
  tcase_add_test(tc, positive_near_zero);
  tcase_add_test(tc, positive_near_one);
  tcase_add_test(tc, negative_near_minus_zero);
  tcase_add_test(tc, negative_near_minus_one);

  return tc;
}
