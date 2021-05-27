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
 *   2021      Evan Nemerson <evan@nemerson.com>
 *   2021      Zhi An Ng <zhin@google.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_LD4_LANE_H)
#define SIMDE_ARM_NEON_LD4_LANE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_BUG_INTEL_857088)

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8x4_t simde_vld4_lane_s8(int8_t const *ptr, simde_int8x8x4_t src,
                                    const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  int8_t buf[4];
  simde_memcpy(buf, ptr, 4 * sizeof(*ptr));
  simde_int8x8_private a_[4];
  for (size_t i = 0; i < 4; i++) {
    a_[i] = simde_int8x8_to_private(src.val[i]);
    a_[i].values[lane] = buf[i];
  }
  simde_int8x8x4_t s_ = {
      {simde_int8x8_from_private(a_[0]), simde_int8x8_from_private(a_[1]),
       simde_int8x8_from_private(a_[2]), simde_int8x8_from_private(a_[3])}};
  return s_;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_s8(ptr, src, lane) vld4_lane_s8(ptr, src, lane)
#endif

#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_s8
  #define vld4_lane_s8(ptr, src, lane) simde_vld4_lane_s8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4x4_t simde_vld4_lane_s16(int16_t const *ptr, simde_int16x4x4_t src,
                                     const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  int16_t buf[4];
  simde_memcpy(buf, ptr, 4 * sizeof(*ptr));
  simde_int16x4_private a_[4];
  for (size_t i = 0; i < 4; i++) {
    a_[i] = simde_int16x4_to_private(src.val[i]);
    a_[i].values[lane] = buf[i];
  }
  simde_int16x4x4_t s_ = {
      {simde_int16x4_from_private(a_[0]), simde_int16x4_from_private(a_[1]),
       simde_int16x4_from_private(a_[2]), simde_int16x4_from_private(a_[3])}};
  return s_;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_s16(ptr, src, lane) vld4_lane_s16(ptr, src, lane)
#endif

#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_s16
  #define vld4_lane_s16(ptr, src, lane) simde_vld4_lane_s16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2x4_t simde_vld4_lane_s32(int32_t const *ptr, simde_int32x2x4_t src,
                                      const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  int32_t buf[4];
  simde_memcpy(buf, ptr, 4 * sizeof(*ptr));
  simde_int32x2_private a_[4];
  for (size_t i = 0; i < 4; i++) {
    a_[i] = simde_int32x2_to_private(src.val[i]);
    a_[i].values[lane] = buf[i];
  }
  simde_int32x2x4_t s_ = {
      {simde_int32x2_from_private(a_[0]), simde_int32x2_from_private(a_[1]),
       simde_int32x2_from_private(a_[2]), simde_int32x2_from_private(a_[3])}};
  return s_;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_s32(ptr, src, lane) vld4_lane_s32(ptr, src, lane)
#endif

#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_s32
  #define vld4_lane_s32(ptr, src, lane) simde_vld4_lane_s32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8x4_t simde_vld4_lane_u8(uint8_t const *ptr, simde_uint8x8x4_t src,
                                     const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  uint8_t buf[4];
  simde_memcpy(buf, ptr, 4 * sizeof(*ptr));
  simde_uint8x8_private a_[4];
  for (size_t i = 0; i < 4; i++) {
    a_[i] = simde_uint8x8_to_private(src.val[i]);
    a_[i].values[lane] = buf[i];
  }
  simde_uint8x8x4_t s_ = {
      {simde_uint8x8_from_private(a_[0]), simde_uint8x8_from_private(a_[1]),
       simde_uint8x8_from_private(a_[2]), simde_uint8x8_from_private(a_[3])}};
  return s_;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_u8(ptr, src, lane) vld4_lane_u8(ptr, src, lane)
#endif

#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_u8
  #define vld4_lane_u8(ptr, src, lane) simde_vld4_lane_u8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4x4_t simde_vld4_lane_u16(uint16_t const *ptr, simde_uint16x4x4_t src,
                                     const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  uint16_t buf[4];
  simde_memcpy(buf, ptr, 4 * sizeof(*ptr));
  simde_uint16x4_private a_[4];
  for (size_t i = 0; i < 4; i++) {
    a_[i] = simde_uint16x4_to_private(src.val[i]);
    a_[i].values[lane] = buf[i];
  }
  simde_uint16x4x4_t s_ = {
      {simde_uint16x4_from_private(a_[0]), simde_uint16x4_from_private(a_[1]),
       simde_uint16x4_from_private(a_[2]), simde_uint16x4_from_private(a_[3])}};
  return s_;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_u16(ptr, src, lane) vld4_lane_u16(ptr, src, lane)
#endif

#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_u16
  #define vld4_lane_u16(ptr, src, lane) simde_vld4_lane_u16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2x4_t simde_vld4_lane_u32(uint32_t const *ptr, simde_uint32x2x4_t src,
                                      const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  uint32_t buf[4];
  simde_memcpy(buf, ptr, 4 * sizeof(*ptr));
  simde_uint32x2_private a_[4];
  for (size_t i = 0; i < 4; i++) {
    a_[i] = simde_uint32x2_to_private(src.val[i]);
    a_[i].values[lane] = buf[i];
  }
  simde_uint32x2x4_t s_ = {
      {simde_uint32x2_from_private(a_[0]), simde_uint32x2_from_private(a_[1]),
       simde_uint32x2_from_private(a_[2]), simde_uint32x2_from_private(a_[3])}};
  return s_;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_u32(ptr, src, lane) vld4_lane_u32(ptr, src, lane)
#endif

#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_u32
  #define vld4_lane_u32(ptr, src, lane) simde_vld4_lane_u32((ptr), (src), (lane))
#endif

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_LD4_LANE_H) */
