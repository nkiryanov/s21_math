#include <stdint.h>

#include "../s21_math.h"

uint32_t _get_float_bits(float x) {
  union {
    float as_float;
    uint32_t as_uint;
  } x_bits;

  x_bits.as_float = x;
  return x_bits.as_uint;
}
