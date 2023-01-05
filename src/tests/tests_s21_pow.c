#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../s21_math.h"

char std_representation[17];
char s21_representation[17];

void save_first_16_digits_as_string(char *string_representation,
                                    long double value) {
  snprintf(string_representation, (sizeof(char) * 16), "%Lf", value);
  string_representation[16] = '\0';
}

void setup(void) {
  // Clean string representation on every test run
  std_representation[0] = '\0';
  s21_representation[0] = '\0';
}

// Do nothing
void teardown(void) {}

START_TEST(int_base_and_int_exp) {
  double base = 45;
  double exp = 60;

  save_first_16_digits_as_string(std_representation, pow(base, exp));
  save_first_16_digits_as_string(s21_representation, s21_pow(base, exp));

  ck_assert_str_eq(s21_representation, std_representation);
}
END_TEST

START_TEST(double_base_and_int_exp) {
  double base = 13.23;
  double exp = 25;

  save_first_16_digits_as_string(std_representation, pow(base, exp));
  save_first_16_digits_as_string(s21_representation, s21_pow(base, exp));

  ck_assert_str_eq(s21_representation, std_representation);
}
END_TEST

START_TEST(return_one_if_base_is_positive_one_positive_exp) {
  double base = 1.0;
  double exp = 26;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_one_negative_exp) {
  double base = 1.0;
  double exp = -26;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_one_and_exp_nan) {
  double base = 1.0;
  double exp = NAN;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_one_and_exp_positive_inf) {
  double base = 1.0;
  double exp = +INFINITY;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_one_and_exp_negative_inf) {
  double base = 1.0;
  double exp = -INFINITY;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_and_exp_is_null) {
  double base = 231.0;
  double exp = 0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_negative_and_exp_is_null) {
  double base = -231.0;
  double exp = 0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_nan_and_exp_is_null) {
  double base = NAN;
  double exp = 0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_inf_and_exp_is_null) {
  double base = INFINITY;
  double exp = 0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_negative_inf_and_exp_is_null) {
  double base = -INFINITY;
  double exp = 0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_positive_and_exp_is_negative_null) {
  double base = 231.0;
  double exp = -0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_negative_and_exp_is_negative_null) {
  double base = -231.0;
  double exp = -0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_nan_and_exp_is_negative_null) {
  double base = NAN;
  double exp = -0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_plus_inf_and_exp_is_negative_null) {
  double base = INFINITY;
  double exp = -0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(return_one_if_base_is_minus_inf_and_exp_is_negative_null) {
  double base = -INFINITY;
  double exp = -0.0;

  ck_assert_double_eq(pow(base, exp), 1.0);
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

TCase *tcase_s21_pow(void) {
  TCase *tc;

  tc = tcase_create("Tests for `s21_pow` implementation");

  tcase_add_checked_fixture(tc, setup, teardown);
  tcase_add_test(tc, int_base_and_int_exp);
  tcase_add_test(tc, double_base_and_int_exp);
  tcase_add_test(tc, return_one_if_base_is_positive_one_positive_exp);
  tcase_add_test(tc, return_one_if_base_is_positive_one_negative_exp);
  tcase_add_test(tc, return_one_if_base_is_positive_one_and_exp_nan);
  tcase_add_test(tc, return_one_if_base_is_positive_one_and_exp_positive_inf);
  tcase_add_test(tc, return_one_if_base_is_positive_one_and_exp_negative_inf);
  tcase_add_test(tc, return_one_if_base_is_positive_and_exp_is_null);
  tcase_add_test(tc, return_one_if_base_is_negative_and_exp_is_null);
  tcase_add_test(tc, return_one_if_base_is_nan_and_exp_is_null);
  tcase_add_test(tc, return_one_if_base_is_positive_inf_and_exp_is_null);
  tcase_add_test(tc, return_one_if_base_is_negative_inf_and_exp_is_null);
  tcase_add_test(tc, return_one_if_base_is_positive_and_exp_is_negative_null);
  tcase_add_test(tc, return_one_if_base_is_negative_and_exp_is_negative_null);
  tcase_add_test(tc, return_one_if_base_is_nan_and_exp_is_negative_null);
  tcase_add_test(tc, return_one_if_base_is_plus_inf_and_exp_is_negative_null);
  tcase_add_test(tc, return_one_if_base_is_minus_inf_and_exp_is_negative_null);

  return tc;
}
