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

#if !defined(SIMDE_ARM_NEON_DOT_LANE_H)
#define SIMDE_ARM_NEON_DOT_LANE_H

#include "types.h"

#include "add.h"
#include "combine.h"
#include "dup_n.h"
#include "get_low.h"
#include "get_high.h"
#include "paddl.h"
#include "movn.h"
#include "mull.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vdot_lane_s32(simde_int32x2_t r, simde_int8x8_t a, simde_int8x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_int32x2_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_DOT_PROD)
    SIMDE_CONSTIFY_2_(vdot_lane_s32, result, (HEDLEY_UNCREACHABLE(), result), lane, r, a, b);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    simde_uint32x2_t mask;
    SIMDE_CONSTIFY_2_(vset_lane_u32, mask, (HEDLEY_UNREACHABLE(), mask), lane, UINT32_MAX, vdup_n_u32(0));
    result = vbsl_s32(mask,
                      vadd_s32(r, vmovn_s64(vpaddlq_s32(vpaddlq_s16(vmull_s8(a, b))))),
                      r);
  #else
    simde_int32x2_private r_ = simde_int32x2_to_private(simde_vdup_n_s32(0));
    simde_int8x8_private
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    int32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for (int j = 0 ; j < 4 ; j++) {
      const int idx = j + (lane << 2);
      acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx]) * HEDLEY_STATIC_CAST(int32_t, b_.values[idx]);
    }
    r_.values[lane] = acc;

    result = simde_vadd_s32(r, simde_int32x2_from_private(r_));
    #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(__ARM_FEATURE_DOTPROD))
  #undef vdot_lane_s32
  #define vdot_lane_s32(r, a, b, lane) simde_vdot_lane_s32((r), (a), (b), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vdot_lane_u32(simde_uint32x2_t r, simde_uint8x8_t a, simde_uint8x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_uint32x2_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_DOT_PROD)
    SIMDE_CONSTIFY_2_(vdot_lane_u32, result, (HEDLEY_UNCREACHABLE(), result), lane, r, a, b);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    simde_uint32x2_t mask;
    SIMDE_CONSTIFY_2_(vset_lane_u32, mask, (HEDLEY_UNREACHABLE(), mask), lane, UINT32_MAX, vdup_n_u32(0));
    result = vbsl_u32(mask,
                      vadd_u32(r, vmovn_u64(vpaddlq_u32(vpaddlq_u16(vmull_u8(a, b))))),
                      r);
  #else
    simde_uint32x2_private r_ = simde_uint32x2_to_private(simde_vdup_n_u32(0));
    simde_uint8x8_private
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    uint32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for (int j = 0 ; j < 4 ; j++) {
      const int idx = j + (lane << 2);
      acc += HEDLEY_STATIC_CAST(uint32_t, a_.values[idx]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[idx]);
    }
    r_.values[lane] = acc;

    result = simde_vadd_u32(r, simde_uint32x2_from_private(r_));
    #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(__ARM_FEATURE_DOTPROD))
  #undef vdot_lane_u32
  #define vdot_lane_u32(r, a, b, lane) simde_vdot_lane_u32((r), (a), (b), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vdot_laneq_s32(simde_int32x4_t r, simde_int8x16_t a, simde_int8x16_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_int32x4_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_DOT_PROD)
    SIMDE_CONSTIFY_4_(vdot_laneq_s32, result, (HEDLEY_UNCREACHABLE(), result), lane, r, a, b);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    simde_uint32x4_t mask;
    SIMDE_CONSTIFY_4_(vsetq_lane_u32, mask, (HEDLEY_UNREACHABLE(), mask), lane, UINT32_MAX, vdupq_n_u32(0));
    result = vbslq_s32(mask,
                       vaddq_s32(r, vcombine_s32(vmovn_s64(vpaddlq_s32(vpaddlq_s16(vmull_s8(vget_low_s8(a), vget_low_s8(b))))),
                                                vmovn_s64(vpaddlq_s32(vpaddlq_s16(vmull_s8(vget_high_s8(a), vget_high_s8(b))))))),
                       r);
  #else
    simde_int32x4_private r_ = simde_int32x4_to_private(simde_vdupq_n_s32(0));
    simde_int8x16_private
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    int32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for (int j = 0 ; j < 4 ; j++) {
      const int idx = j + (lane << 2);
      acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx]) * HEDLEY_STATIC_CAST(int32_t, b_.values[idx]);
    }
    r_.values[lane] = acc;

    result = simde_vaddq_s32(r, simde_int32x4_from_private(r_));
    #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(__ARM_FEATURE_DOTPROD))
  #undef vdot_laneq_s32
  #define vdot_laneq_s32(r, a, b, lane) simde_vdot_laneq_s32((r), (a), (b), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vdot_laneq_u32(simde_uint32x4_t r, simde_uint8x16_t a, simde_uint8x16_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_uint32x4_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_DOT_PROD)
    SIMDE_CONSTIFY_4_(vdot_laneq_u32, result, (HEDLEY_UNCREACHABLE(), result), lane, r, a, b);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    simde_uint32x4_t mask;
    SIMDE_CONSTIFY_4_(vsetq_lane_u32, mask, (HEDLEY_UNREACHABLE(), mask), lane, UINT32_MAX, vdupq_n_u32(0));
    result = vbslq_u32(mask,
                       vaddq_u32(r, vcombine_u32(vmovn_u64(vpaddlq_u32(vpaddlq_u16(vmull_u8(vget_low_u8(a), vget_low_u8(b))))),
                                                 vmovn_u64(vpaddlq_u32(vpaddlq_u16(vmull_u8(vget_high_u8(a), vget_high_u8(b))))))),
                       r);
  #else
    simde_uint32x4_private r_ = simde_uint32x4_to_private(simde_vdupq_n_u32(0));
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    uint32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for (int j = 0 ; j < 4 ; j++) {
      const int idx = j + (lane << 2);
      acc += HEDLEY_STATIC_CAST(uint32_t, a_.values[idx]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[idx]);
    }
    r_.values[lane] = acc;

    result = simde_vaddq_u32(r, simde_uint32x4_from_private(r_));
    #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(__ARM_FEATURE_DOTPROD))
  #undef vdot_laneq_u32
  #define vdot_laneq_u32(r, a, b, lane) simde_vdot_laneq_u32((r), (a), (b), (lane))
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_DOT_LANE_H) */
