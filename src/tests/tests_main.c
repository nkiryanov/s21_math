#include <check.h>
#include <stdlib.h>

#include "test_cases.h"

Suite *suite_s21_math(void) {
  Suite *suite;

  suite = suite_create("Tests s21_math");
  suite_add_tcase(suite, tcase_s21_abs());
  suite_add_tcase(suite, tcase_s21_exp());
  suite_add_tcase(suite, tcase_s21_fabs());
  suite_add_tcase(suite, tcase_s21_isfinite());
  suite_add_tcase(suite, tcase_s21_isinf());
  suite_add_tcase(suite, tcase_s21_isnan());
  suite_add_tcase(suite, tcase_s21_log());
  suite_add_tcase(suite, tcase_s21_signbit());
  suite_add_tcase(suite, tcase_s21_sqrt());

  return suite;
}

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(suite_s21_math());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
