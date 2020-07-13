/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Sean Maher <seanptmaher@gmail.com>
 */

#if !defined(SIMDE_ARM_NEON_QSHL_H)
#define SIMDE_ARM_NEON_QSHL_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#define SIMDE_MIN_(A, B) (((A) > (B)) ? (B) : (A))

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vqshl_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_s8(a, b);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint8_t mask = HEDLEY_STATIC_CAST(uint8_t, UINT8_MAX << SIMDE_MIN_((7 - b_value), 8));
      if (b_value > 0) {
        if (b_value >= 8) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT8_MAX;
            } else {
              r_.values[i] = INT8_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint8_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT8_MAX;
          } else {
            r_.values[i] = INT8_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int8_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -8) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_s8
  #define vqshl_s8(a, b) simde_vqshl_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vqshl_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_s16(a, b);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint16_t mask = HEDLEY_STATIC_CAST(uint16_t, UINT16_MAX << SIMDE_MIN_((15 - b_value), 16));
      if (b_value > 0) {
        if (b_value >= 16) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT16_MAX;
            } else {
              r_.values[i] = INT16_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint16_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT16_MAX;
          } else {
            r_.values[i] = INT16_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -16) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_s16
  #define vqshl_s16(a, b) simde_vqshl_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vqshl_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_s32(a, b);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint32_t mask = HEDLEY_STATIC_CAST(uint32_t, UINT32_MAX << SIMDE_MIN_((31 - b_value), 32));
      if (b_value > 0) {
        if (b_value >= 32) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT32_MAX;
            } else {
              r_.values[i] = INT32_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT32_MAX;
          } else {
            r_.values[i] = INT32_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -32) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_s32
  #define vqshl_s32(a, b) simde_vqshl_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vqshl_s64(simde_int64x1_t a, simde_int64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_s64(a, b);
  #else
    simde_int64x1_private
      r_,
      a_ = simde_int64x1_to_private(a),
      b_ = simde_int64x1_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint64_t mask = HEDLEY_STATIC_CAST(uint64_t, UINT64_MAX << SIMDE_MIN_((63 - b_value), 64));
      if (b_value > 0) {
        if (b_value >= 64) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT64_MAX;
            } else {
              r_.values[i] = INT64_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT64_MAX;
          } else {
            r_.values[i] = INT64_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int64_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -64) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_s64
  #define vqshl_s64(a, b) simde_vqshl_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vqshl_u8(simde_uint8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_u8(a, b);
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a);
    simde_int8x8_private b_ = simde_int8x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint8_t mask = HEDLEY_STATIC_CAST(uint8_t, UINT8_MAX << SIMDE_MIN_((8 - b_value), 8));
      if (b_value > 0) {
        if (b_value >= 8) {
          if (a_.values[i]) {
            r_.values[i] = UINT8_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint8_t, a_.values[i]) & mask) {
          r_.values[i] = UINT8_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -8) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_u8
  #define vqshl_u8(a, b) simde_vqshl_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vqshl_u16(simde_uint16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_u16(a, b);
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a);
    simde_int16x4_private b_ = simde_int16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint16_t mask = HEDLEY_STATIC_CAST(uint16_t, UINT16_MAX << SIMDE_MIN_((16 - b_value), 16));
      if (b_value > 0) {
        if (b_value >= 16) {
          if (a_.values[i]) {
            r_.values[i] = UINT16_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint16_t, a_.values[i]) & mask) {
          r_.values[i] = UINT16_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -16) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_u16
  #define vqshl_u16(a, b) simde_vqshl_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vqshl_u32(simde_uint32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_u32(a, b);
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a);
    simde_int32x2_private b_ = simde_int32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint32_t mask = HEDLEY_STATIC_CAST(uint32_t, UINT32_MAX << SIMDE_MIN_((32 - b_value), 32));
      if (b_value > 0) {
        if (b_value >= 32) {
          if (a_.values[i]) {
            r_.values[i] = UINT32_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) & mask) {
          r_.values[i] = UINT32_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -32) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_u32
  #define vqshl_u32(a, b) simde_vqshl_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vqshl_u64(simde_uint64x1_t a, simde_int64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshl_u64(a, b);
  #else
    simde_uint64x1_private
      r_,
      a_ = simde_uint64x1_to_private(a);
    simde_int64x1_private b_ = simde_int64x1_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint64_t mask = HEDLEY_STATIC_CAST(uint64_t, UINT64_MAX << SIMDE_MIN_((64 - b_value), 64));
      if (b_value > 0) {
        if (b_value >= 64) {
          if (a_.values[i]) {
            r_.values[i] = UINT64_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) & mask) {
          r_.values[i] = UINT64_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -64) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshl_u64
  #define vqshl_u64(a, b) simde_vqshl_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vqshlq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_s8(a, b);
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint8_t mask = HEDLEY_STATIC_CAST(uint8_t, UINT8_MAX << SIMDE_MIN_((7 - b_value), 8));
      if (b_value > 0) {
        if (b_value >= 8) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT8_MAX;
            } else {
              r_.values[i] = INT8_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint8_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT8_MAX;
          } else {
            r_.values[i] = INT8_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int8_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -8) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_s8
  #define vqshlq_s8(a, b) simde_vqshlq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vqshlq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_s16(a, b);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint16_t mask = HEDLEY_STATIC_CAST(uint16_t, UINT16_MAX << SIMDE_MIN_((15 - b_value), 16));
      if (b_value > 0) {
        if (b_value >= 16) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT16_MAX;
            } else {
              r_.values[i] = INT16_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint16_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT16_MAX;
          } else {
            r_.values[i] = INT16_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -16) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_s16
  #define vqshlq_s16(a, b) simde_vqshlq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vqshlq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_s32(a, b);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint32_t mask = HEDLEY_STATIC_CAST(uint32_t, UINT32_MAX << SIMDE_MIN_((31 - b_value), 32));
      if (b_value > 0) {
        if (b_value >= 32) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT32_MAX;
            } else {
              r_.values[i] = INT32_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT32_MAX;
          } else {
            r_.values[i] = INT32_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -32) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_s32
  #define vqshlq_s32(a, b) simde_vqshlq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vqshlq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_s64(a, b);
  #else
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint64_t mask = HEDLEY_STATIC_CAST(uint64_t, UINT64_MAX << SIMDE_MIN_((63 - b_value), 64));
      if (b_value > 0) {
        if (b_value >= 64) {
          if (a_.values[i]) {
            if (a_.values[i] > 0) {
              r_.values[i] = INT64_MAX;
            } else {
              r_.values[i] = INT64_MIN;
            }
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) & mask) {
          if (a_.values[i] > 0) {
            r_.values[i] = INT64_MAX;
          } else {
            r_.values[i] = INT64_MIN;
          }
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(int64_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -64) {
        if (a_.values[i] >= 0) {
          r_.values[i] = 0;
        } else {
          r_.values[i] = -1;
        }
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_s64
  #define vqshlq_s64(a, b) simde_vqshlq_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vqshlq_u8(simde_uint8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_u8(a, b);
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a);
    simde_int8x16_private b_ = simde_int8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint8_t mask = HEDLEY_STATIC_CAST(uint8_t, UINT8_MAX << SIMDE_MIN_((8 - b_value), 8));
      if (b_value > 0) {
        if (b_value >= 8) {
          if (a_.values[i]) {
            r_.values[i] = UINT8_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint8_t, a_.values[i]) & mask) {
          r_.values[i] = UINT8_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -8) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_u8
  #define vqshlq_u8(a, b) simde_vqshlq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vqshlq_u16(simde_uint16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_u16(a, b);
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a);
    simde_int16x8_private b_ = simde_int16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint16_t mask = HEDLEY_STATIC_CAST(uint16_t, UINT16_MAX << SIMDE_MIN_((16 - b_value), 16));
      if (b_value > 0) {
        if (b_value >= 16) {
          if (a_.values[i]) {
            r_.values[i] = UINT16_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint16_t, a_.values[i]) & mask) {
          r_.values[i] = UINT16_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -16) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_u16
  #define vqshlq_u16(a, b) simde_vqshlq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vqshlq_u32(simde_uint32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_u32(a, b);
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a);
    simde_int32x4_private b_ = simde_int32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint32_t mask = HEDLEY_STATIC_CAST(uint32_t, UINT32_MAX << SIMDE_MIN_((32 - b_value), 32));
      if (b_value > 0) {
        if (b_value >= 32) {
          if (a_.values[i]) {
            r_.values[i] = UINT32_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) & mask) {
          r_.values[i] = UINT32_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -32) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_u32
  #define vqshlq_u32(a, b) simde_vqshlq_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vqshlq_u64(simde_uint64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqshlq_u64(a, b);
  #else
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a);
    simde_int64x2_private b_ = simde_int64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      int8_t b_value = HEDLEY_STATIC_CAST(int8_t, b_.values[i] & 0xff); // HEDLEY_STATIC_CAST(int8_t, b_.values[i]);
      uint64_t mask = HEDLEY_STATIC_CAST(uint64_t, UINT64_MAX << SIMDE_MIN_((64 - b_value), 64));
      if (b_value > 0) {
        if (b_value >= 64) {
          if (a_.values[i]) {
            r_.values[i] = UINT64_MAX;
          } else {
            r_.values[i] = 0;
          }
        } else if (HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) & mask) {
          r_.values[i] = UINT64_MAX;
        } else {
          r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i] << b_value);
        }
      } else if (b_value <= -64) {
          r_.values[i] = 0;
      } else {
        r_.values[i] = a_.values[i] >> -b_value;
      }
    }

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlq_u64
  #define vqshlq_u64(a, b) simde_vqshlq_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_QSHL_H) */
