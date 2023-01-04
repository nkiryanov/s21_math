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
  double x = -INFINITY;

  double_bits x_bits;
  x_bits.double_value = x;
  printBits(sizeof(double_bits), &x_bits);

  x = S21_INFINITY;
  printBits(sizeof(x), &x);

  x = -8000.2203023;

  printf("exp_x =%lf\n", exp(x));
  printf("s21_exp=%Lf\n", s21_exp(x));
}
