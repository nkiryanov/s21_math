#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(nan_has_return_itself) {
  double x = NAN;

  ck_assert_double_nan(floor(x));
  ck_assert_double_nan(s21_floor(x));
}
END_TEST

START_TEST(negative_nan_has_return_itself) {
  double x = -NAN;

  ck_assert_double_nan(floor(x));
  ck_assert_int_ge(signbit(floor(x)), 1);

  ck_assert_double_nan(s21_floor(x));
  ck_assert_int_ge(signbit(s21_floor(x)), 1);
}
END_TEST

START_TEST(positive_zero_return_itself) {
  double x = +0.0;

  ck_assert_double_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(negative_zero_return_itself) {
  double x = -0.0;

  ck_assert_double_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(positive_inf_return_itself) {
  double x = INFINITY;

  ck_assert_double_infinite(floor(x));
  ck_assert_ldouble_infinite(s21_floor(x));
}
END_TEST

START_TEST(negative_inf_return_itself) {
  double x = -INFINITY;

  ck_assert_double_infinite(floor(x));
  ck_assert_ldouble_infinite(s21_floor(x));
}
END_TEST

START_TEST(positive_return_integer_part) {
  double x = 30303030.1010102;

  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(negative_return_integer_part_minus_one) {
  double x = -30303030.1010102;

  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(negative_not_rounding_if_integer_already) {
  double x = -303;

  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(positive_not_rounding_if_integer_already) {
  double x = 303;

  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

TCase *tcase_s21_floor(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_floor` implementation");

  tcase_add_test(tc, nan_has_return_itself);
  tcase_add_test(tc, negative_nan_has_return_itself);
  tcase_add_test(tc, positive_zero_return_itself);
  tcase_add_test(tc, negative_zero_return_itself);
  tcase_add_test(tc, positive_inf_return_itself);
  tcase_add_test(tc, negative_inf_return_itself);
  tcase_add_test(tc, positive_return_integer_part);
  tcase_add_test(tc, negative_return_integer_part_minus_one);
  tcase_add_test(tc, negative_not_rounding_if_integer_already);
  tcase_add_test(tc, positive_not_rounding_if_integer_already);

  return tc;
}
