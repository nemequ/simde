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
 */

#if !defined(SIMDE_ARM_NEON_ABS_H)
#define SIMDE_ARM_NEON_ABS_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vabsd_s64(int64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,1,0))
    return vabsd_s64(a);
  #else
    return a < 0 ? -a : a;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabsd_s64
  #define vabsd_s64(a) simde_vabsd_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vabs_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabs_f32(a);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
    }

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabs_f32
  #define vabs_f32(a) simde_vabs_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vabs_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabs_f64(a);
  #else
    simde_float64x1_private
      r_,
      a_ = simde_float64x1_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
    }

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabs_f64
  #define vabs_f64(a) simde_vabs_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vabs_s8(simde_int8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabs_s8(a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_abs_pi8(a);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a);

    #if (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT8_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabs_s8
  #define vabs_s8(a) simde_vabs_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vabs_s16(simde_int16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabs_s16(a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_abs_pi16(a);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT16_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabs_s16
  #define vabs_s16(a) simde_vabs_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vabs_s32(simde_int32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabs_s32(a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_abs_pi32(a);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT32_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabs_s32
  #define vabs_s32(a) simde_vabs_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vabs_s64(simde_int64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabs_s64(a);
  #else
    simde_int64x1_private
      r_,
      a_ = simde_int64x1_to_private(a);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT64_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabs_s64
  #define vabs_s64(a) simde_vabs_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vabsq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabsq_f32(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_abs(a);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f32x4_abs(a);
  #elif defined(SIMDE_X86_AVX512F_NATIVE) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(7,0,0))
    return _mm512_castps512_ps128(_mm512_abs_ps(_mm512_castps128_ps512(a)));
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_math_fabsf(a_.values[i]);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabsq_f32
  #define vabsq_f32(a) simde_vabsq_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vabsq_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabsq_f64(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    return vec_abs(a);
  #elif defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(7,0,0))
    return _mm512_castpd512_pd128(_mm512_abs_pd(_mm512_castpd128_pd512(a)));
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_math_fabs(a_.values[i]);
    }

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabsq_f64
  #define vabsq_f64(a) simde_vabsq_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vabsq_s8(simde_int8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabsq_s8(a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    return _mm_abs_epi8(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_abs(a);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_abs(a);
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a);

    #if (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT8_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabsq_s8
  #define vabsq_s8(a) simde_vabsq_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vabsq_s16(simde_int16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabsq_s16(a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    return _mm_abs_epi16(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_abs(a);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_abs(a);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a);

    #if (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT16_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabsq_s16
  #define vabsq_s16(a) simde_vabsq_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vabsq_s32(simde_int32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vabsq_s32(a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    return _mm_abs_epi32(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_abs(a);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_abs(a);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a);

    #if (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT32_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabsq_s32
  #define vabsq_s32(a) simde_vabsq_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vabsq_s64(simde_int64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabsq_s64(a);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s64(vreinterpretq_u64_s64(vshrq_n_s64(a, 63)), vsubq_s64(vdupq_n_s64(0), a), a);
  #elif defined(SIMDE_POWER_ALTIVEC_P64_NATIVE) && !defined(HEDLEY_IBM_VERSION)
    return vec_abs(a);
  #else
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a);

    #if (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) m = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values < INT64_C(0));
      r_.values = (-a_.values & m) | (a_.values & ~m);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] < 0 ? -a_.values[i] : a_.values[i];
      }
    #endif

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vabsq_s64
  #define vabsq_s64(a) simde_vabsq_s64(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ABS_H) */
