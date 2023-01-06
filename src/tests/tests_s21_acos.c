#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(if_nan_return_nan) {
  double x = NAN;

  ck_assert_double_nan(acos(x));
  ck_assert_double_nan(s21_acos(x));
}
END_TEST

START_TEST(if_one_return_plus_zero) {
  double x = +1.0;

  ck_assert_double_eq(s21_acos(x), acos(x));

  ck_assert_int_eq(signbit(acos(x)), 0);
  ck_assert_int_eq(signbit(s21_acos(x)), 0);
}
END_TEST

START_TEST(if_plus_inf_return_nan) {
  double x = INFINITY;

  ck_assert_double_nan(acos(x));
  ck_assert_double_nan(s21_acos(x));
}
END_TEST

START_TEST(if_minus_inf_return_nan) {
  double x = -INFINITY;

  ck_assert_double_nan(acos(x));
  ck_assert_double_nan(s21_acos(x));
}
END_TEST

START_TEST(if_bigger_one_return_nan) {
  double x = 1.001;

  ck_assert_double_nan(acos(x));
  ck_assert_double_nan(s21_acos(x));
}
END_TEST

START_TEST(if_less_minus_one_return_nan) {
  double x = -1.001;

  ck_assert_double_nan(acos(x));
  ck_assert_double_nan(s21_acos(x));
}
END_TEST

START_TEST(negative_near_zero) {
  double x = -0.0023;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(negative_near_minus_one) {
  double x = -0.999003;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(positive_near_zero) {
  double x = 0.0012;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(positive_near_one) {
  double x = 0.84003;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(exact_one) {
  double x = 1.0;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(exact_minus_one) {
  double x = -1.0;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

TCase *tcase_s21_acos(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_acos` implementation");

  tcase_add_test(tc, if_nan_return_nan);
  tcase_add_test(tc, if_one_return_plus_zero);
  tcase_add_test(tc, if_plus_inf_return_nan);
  tcase_add_test(tc, if_minus_inf_return_nan);
  tcase_add_test(tc, if_bigger_one_return_nan);
  tcase_add_test(tc, if_less_minus_one_return_nan);
  tcase_add_test(tc, negative_near_zero);
  tcase_add_test(tc, negative_near_minus_one);
  tcase_add_test(tc, positive_near_zero);
  tcase_add_test(tc, positive_near_one);
  tcase_add_test(tc, exact_one);
  tcase_add_test(tc, exact_minus_one);

  return tc;
}
