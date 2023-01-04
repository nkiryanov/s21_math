#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "s21_math.h"

typedef union double_bits {
  double double_value;
  u_int64_t bits;
} double_bits;

// Assumes little endian
void printBits(size_t const size, void const *const ptr) {
  unsigned char *b = (unsigned char *)ptr;
  unsigned char byte;
  int i, j;

  for (i = size - 1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
    printf("%5.c", ' ');
  }
  printf("\n");
  for (i = size - 1; i >= 0; i--) {
    printf("%-12.p", &b[i]);
    printf(" ");
  }
  printf("\n");
}

int main() {
  double x = -100.000001223;;

  double_bits bits;
  double std_result;
  double s21_result;

  std_result = exp(x);
  bits.double_value = std_result;
  printBits(sizeof(double_bits), &bits);
  printf("std_dec_result=%20.20lf\n", std_result);
  printf("std_result_as_hex=%llx\n", bits.bits);

  s21_result = s21_exp(x);
  bits.double_value = s21_result;
  printBits(sizeof(double_bits), &bits);
  printf("s21_dec_result=%20.20ff\n", s21_result);
  printf("s21_result_as_hex=%llx\n", bits.bits);

  // x = S21_INFINITY;
  // printBits(sizeof(x), &x);

  // x = -8000.2203023;

  // printf("exp_x =%lf\n", exp(x));
  // printf("s21_exp=%Lf\n", s21_exp(x));
}
