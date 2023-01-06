#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(if_nan_return_nan) {
  double x = NAN;

  ck_assert_double_nan(atan(x));
  ck_assert_double_nan(s21_atan(x));
}
END_TEST

START_TEST(if_zero_return_itself) {
  double x = +0.0;

  ck_assert_double_eq(s21_atan(x), atan(x));

  ck_assert_int_eq(signbit(atan(x)), 0);
  ck_assert_int_eq(signbit(s21_atan(x)), 0);
}
END_TEST

START_TEST(if_negative_zero_return_itself) {
  double x = -0.0;

  ck_assert_double_eq(s21_atan(x), atan(x));

  ck_assert_int_ge(signbit(atan(x)), 1);
  ck_assert_int_ge(signbit(s21_atan(x)), 1);
}
END_TEST

START_TEST(if_infinity_return_pi_2) {
  double x = INFINITY;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(if_minus_infinity_return_minus_pi_2) {
  double x = -INFINITY;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(if_one_return_pi_4) {
  double x = 1.0;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(if_minus_one_return_minus_pi_4) {
  double x = 1.0;

  ck_assert_double_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(positive_less_one) {
  double x = 0.23;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(positive_near_but_less_one) {
  double x = 0.99;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(positive_near_one_but_bigger) {
  double x = 1.09;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(positive_much_bigger_one) {
  double x = 100.09;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(negative_bigger_minus_one) {
  double x = -0.07;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(negative_bigger_minus_one_but_near) {
  double x = -0.99;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(negative_less_minus_one_but_near) {
  double x = -1.01;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

START_TEST(negative_much_less_minus_one) {
  double x = -100.01;

  ck_assert_double_eq_tol(s21_atan(x), atan(x), S21_EPS);
}
END_TEST

TCase *tcase_s21_atan(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_atan` implementation");

  tcase_add_test(tc, if_nan_return_nan);
  tcase_add_test(tc, if_zero_return_itself);
  tcase_add_test(tc, if_negative_zero_return_itself);
  tcase_add_test(tc, if_infinity_return_pi_2);
  tcase_add_test(tc, if_minus_infinity_return_minus_pi_2);
  tcase_add_test(tc, if_one_return_pi_4);
  tcase_add_test(tc, if_minus_one_return_minus_pi_4);
  tcase_add_test(tc, positive_less_one);
  tcase_add_test(tc, positive_near_but_less_one);
  tcase_add_test(tc, positive_near_one_but_bigger);
  tcase_add_test(tc, positive_much_bigger_one);
  tcase_add_test(tc, negative_bigger_minus_one);
  tcase_add_test(tc, negative_bigger_minus_one_but_near);
  tcase_add_test(tc, negative_less_minus_one_but_near);
  tcase_add_test(tc, negative_much_less_minus_one);
  return tc;
}
