#include <check.h>
#include <stdlib.h>

#include "test_cases.h"

Suite *suite_s21_math(void) {
  Suite *s;

  s = suite_create("Tests s21_math");
  suite_add_tcase(s, tcase_s21_abs());

  return s;
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
