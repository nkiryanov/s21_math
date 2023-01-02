#include <check.h>
#include <limits.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(positive_return_same_value) {
  int x = 100;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(negative_return_return_negated_value) {
  int x = -100;

  ck_assert_int_eq(s21_abs(x), abs(-x));
}
END_TEST

START_TEST(zero_works_well_too) {
  int x = 0;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(edge_case_int_max) {
  int x = INT_MAX;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(edge_case_int_min) {
  int x = INT_MIN;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

TCase *tcase_s21_abs(void) {
  TCase *tc;

  tc = tcase_create("Tests for `int s21_abs(int x)` function");

  tcase_add_test(tc, positive_return_same_value);
  tcase_add_test(tc, negative_return_return_negated_value);
  tcase_add_test(tc, zero_works_well_too);
  tcase_add_test(tc, edge_case_int_max);
  tcase_add_test(tc, edge_case_int_min);

  return tc;
}
