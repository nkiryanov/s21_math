#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "s21_math.h"

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
  double base;
  double exp;
  
  base = -INFINITY;
  exp = -3;
  
  // printf("result_s21p=%Lf\n", s21_pow(base, exp));
  printf("result_orig=%Lf\n", s21_pow(base, exp));

  // base = 13.23;
  // exp = 26;

  // printf("result_s21p=%16Lf\n", s21_pow(base, exp));
  // printf("result_orig=%16lf\n", pow(base, exp));

  // printf("%d>>%d=%d\n", 7, 1, 7>>1);
  // printf("%d>>%d=%d\n", 9, 1, 7>>1);
}
