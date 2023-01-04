#include <stdint.h>

uint64_t _get_double_bits(double x) {
  union {
    double as_double;
    uint64_t as_uint;
  } x_bits;

  x_bits.as_double = x;
  return x_bits.as_uint;
}
