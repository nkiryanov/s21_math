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

  x = NAN;
  printf("is_nan=%d\n", s21_isnan(x));
  printf("is_not_nan=%d\n", s21_isnan(100.0));

  x = S21_INFINITY;
  printBits(sizeof(x), &x);
}
