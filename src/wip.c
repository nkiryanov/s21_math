#include <math.h>
#include <stdio.h>

#include "s21_math.h"

int main() {
    double x = NAN;
    double y = S21_NAN;

    union {
        double double_value;
        unsigned long long int bits;
    } bits;

    bits.double_value = x;
    printf("bits=%Lu\n", bits.bits);
    printf("double size = %lu\n", sizeof(double));
    printf("unsigned int size = %lu\n", sizeof(unsigned long long int));

    bits.double_value = y;
    printf("bits=%Lu\n", bits.bits);
    // if ! (s21_signbit_double(x)) {
    //     printf("x less than zero\n");
    // }

    // if (x > 0) {
    //     printf("x bigger than zero\n.");
    // }
    // int y = (sizeof(x) == sizeof(float)) ? 1 : (int)(x>>31);

    // printf("sqrt of nan=%lf\n", sqrt(x));
    // printf("%Lf\n", s21_sqrt(x));
    // printf("original_sqrt=%lf\n", sqrt(x));
}
