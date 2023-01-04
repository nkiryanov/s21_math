#include <stdint.h>

u_int64_t _get_double_bits(double x) {
  union {
    double as_double;
    u_int64_t as_uint;
  } x_bits;

  x_bits.as_double = x;
  return x_bits.as_uint;
}
