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
 *   2020      Sean Maher <seanptmaher@gmail.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_BSL_H)
#define SIMDE_ARM_NEON_BSL_H

#include "types.h"
#include "reinterpret.h"
#include "and.h"
#include "eor.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vbsl_u8(simde_uint8x8_t a, simde_uint8x8_t b, simde_uint8x8_t c);

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vbslq_u8(simde_uint8x16_t a, simde_uint8x16_t b, simde_uint8x16_t c);

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vbsl_f32(simde_uint32x2_t a, simde_float32x2_t b, simde_float32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_f32(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u32(a),
      b_ = simde_vreinterpret_u8_f32(b),
      c_ = simde_vreinterpret_u8_f32(c);
    return simde_vreinterpret_f32_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_f32
  #define vbsl_f32(a, b, c) simde_vbsl_f32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vbsl_f64(simde_uint64x1_t a, simde_float64x1_t b, simde_float64x1_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vbsl_f64(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u64(a),
      b_ = simde_vreinterpret_u8_f64(b),
      c_ = simde_vreinterpret_u8_f64(c);
    return simde_vreinterpret_f64_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vbsl_f64
  #define vbsl_f64(a, b, c) simde_vbsl_f64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vbsl_s8(simde_uint8x8_t a, simde_int8x8_t b, simde_int8x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s8(a, b, c);
  #else
    simde_uint8x8_t
      a_ = a,
      b_ = simde_vreinterpret_u8_s8(b),
      c_ = simde_vreinterpret_u8_s8(c);
    return simde_vreinterpret_s8_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s8
  #define vbsl_s8(a, b, c) simde_vbsl_s8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vbsl_s16(simde_uint16x4_t a, simde_int16x4_t b, simde_int16x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s16(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u16(a),
      b_ = simde_vreinterpret_u8_s16(b),
      c_ = simde_vreinterpret_u8_s16(c);
    return simde_vreinterpret_s16_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s16
  #define vbsl_s16(a, b, c) simde_vbsl_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vbsl_s32(simde_uint32x2_t a, simde_int32x2_t b, simde_int32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s32(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u32(a),
      b_ = simde_vreinterpret_u8_s32(b),
      c_ = simde_vreinterpret_u8_s32(c);
    return simde_vreinterpret_s32_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s32
  #define vbsl_s32(a, b, c) simde_vbsl_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vbsl_s64(simde_uint64x1_t a, simde_int64x1_t b, simde_int64x1_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s64(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u64(a),
      b_ = simde_vreinterpret_u8_s64(b),
      c_ = simde_vreinterpret_u8_s64(c);
    return simde_vreinterpret_s64_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s64
  #define vbsl_s64(a, b, c) simde_vbsl_s64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vbsl_u8(simde_uint8x8_t a, simde_uint8x8_t b, simde_uint8x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u8(a, b, c);
  #else
    return simde_veor_u8(c, simde_vand_u8(simde_veor_u8(b, c), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u8
  #define vbsl_u8(a, b, c) simde_vbsl_u8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vbsl_u16(simde_uint16x4_t a, simde_uint16x4_t b, simde_uint16x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u16(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u16(a),
      b_ = simde_vreinterpret_u8_u16(b),
      c_ = simde_vreinterpret_u8_u16(c);
    return simde_vreinterpret_u16_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u16
  #define vbsl_u16(a, b, c) simde_vbsl_u16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vbsl_u32(simde_uint32x2_t a, simde_uint32x2_t b, simde_uint32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u32(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u32(a),
      b_ = simde_vreinterpret_u8_u32(b),
      c_ = simde_vreinterpret_u8_u32(c);
    return simde_vreinterpret_u32_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u32
  #define vbsl_u32(a, b, c) simde_vbsl_u32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vbsl_u64(simde_uint64x1_t a, simde_uint64x1_t b, simde_uint64x1_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u64(a, b, c);
  #else
    simde_uint8x8_t
      a_ = simde_vreinterpret_u8_u64(a),
      b_ = simde_vreinterpret_u8_u64(b),
      c_ = simde_vreinterpret_u8_u64(c);
    return simde_vreinterpret_u64_u8(simde_vbsl_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u64
  #define vbsl_u64(a, b, c) simde_vbsl_u64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vbslq_f32(simde_uint32x4_t a, simde_float32x4_t b, simde_float32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_f32(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_castsi128_ps(_mm_ternarylogic_epi32(a, _mm_castps_si128(b), _mm_castps_si128(c), 0xca));
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u32(a),
      b_ = simde_vreinterpretq_u8_f32(b),
      c_ = simde_vreinterpretq_u8_f32(c);
    return simde_vreinterpretq_f32_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_f32
  #define vbslq_f32(a, b, c) simde_vbslq_f32((a), (b), (c))
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vbslq_f64(simde_uint64x2_t a, simde_float64x2_t b, simde_float64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vbslq_f64(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_castsi128_pd(_mm_ternarylogic_epi32(a, _mm_castpd_si128(b), _mm_castpd_si128(c), 0xca));
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u64(a),
      b_ = simde_vreinterpretq_u8_f64(b),
      c_ = simde_vreinterpretq_u8_f64(c);
    return simde_vreinterpretq_f64_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vbslq_f64
  #define vbslq_f64(a, b, c) simde_vbslq_f64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vbslq_s8(simde_uint8x16_t a, simde_int8x16_t b, simde_int8x16_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s8(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = (a),
      b_ = simde_vreinterpretq_u8_s8(b),
      c_ = simde_vreinterpretq_u8_s8(c);
    return simde_vreinterpretq_s8_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s8
  #define vbslq_s8(a, b, c) simde_vbslq_s8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vbslq_s16(simde_uint16x8_t a, simde_int16x8_t b, simde_int16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s16(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_sel(c, b, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u16(a),
      b_ = simde_vreinterpretq_u8_s16(b),
      c_ = simde_vreinterpretq_u8_s16(c);
    return simde_vreinterpretq_s16_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s16
  #define vbslq_s16(a, b, c) simde_vbslq_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vbslq_s32(simde_uint32x4_t a, simde_int32x4_t b, simde_int32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s32(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u32(a),
      b_ = simde_vreinterpretq_u8_s32(b),
      c_ = simde_vreinterpretq_u8_s32(c);
    return simde_vreinterpretq_s32_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s32
  #define vbslq_s32(a, b, c) simde_vbslq_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vbslq_s64(simde_uint64x2_t a, simde_int64x2_t b, simde_int64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s64(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u64(a),
      b_ = simde_vreinterpretq_u8_s64(b),
      c_ = simde_vreinterpretq_u8_s64(c);
    return simde_vreinterpretq_s64_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s64
  #define vbslq_s64(a, b, c) simde_vbslq_s64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vbslq_u8(simde_uint8x16_t a, simde_uint8x16_t b, simde_uint8x16_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u8(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_sel(c, b, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    return simde_veorq_u8(c, simde_vandq_u8(simde_veorq_u8(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u8
  #define vbslq_u8(a, b, c) simde_vbslq_u8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vbslq_u16(simde_uint16x8_t a, simde_uint16x8_t b, simde_uint16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u16(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u16(a),
      b_ = simde_vreinterpretq_u8_u16(b),
      c_ = simde_vreinterpretq_u8_u16(c);
    return simde_vreinterpretq_u16_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u16
  #define vbslq_u16(a, b, c) simde_vbslq_u16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vbslq_u32(simde_uint32x4_t a, simde_uint32x4_t b, simde_uint32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u32(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u32(a),
      b_ = simde_vreinterpretq_u8_u32(b),
      c_ = simde_vreinterpretq_u8_u32(c);
    return simde_vreinterpretq_u32_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u32
  #define vbslq_u32(a, b, c) simde_vbslq_u32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vbslq_u64(simde_uint64x2_t a, simde_uint64x2_t b, simde_uint64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u64(a, b, c);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_v128_bitselect(b, c, a);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #else
    simde_uint8x16_t
      a_ = simde_vreinterpretq_u8_u64(a),
      b_ = simde_vreinterpretq_u8_u64(b),
      c_ = simde_vreinterpretq_u8_u64(c);
    return simde_vreinterpretq_u64_u8(simde_vbslq_u8(a_, b_, c_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u64
  #define vbslq_u64(a, b, c) simde_vbslq_u64((a), (b), (c))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_BSL_H) */
