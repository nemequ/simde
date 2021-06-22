#if !defined(SIMDE_X86_AVX512_ROR_H)
#define SIMDE_X86_AVX512_ROR_H

#include "types.h"
#include "mov.h"
#include "or.h"
#include "srli.h"
#include "slli.h"
#include "../avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_ror_epi32(a, imm8) _mm_ror_epi32(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_ror_epi32 (simde__m128i a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    switch (imm8 & 31) {
      case 0:
        r_ = a_;
        break;
      default:
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = (a_.u32[i] >> (imm8 & 31)) | (a_.u32[i] << (32 - (imm8 & 31)));
        }
        break;
    }

    return simde__m128i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_ror_epi32
  #define _mm_ror_epi32(a, imm8) simde_mm_ror_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_ror_epi32(src, k, a, imm8) _mm_mask_ror_epi32(src, k, a, imm8)
#else
  #define simde_mm_mask_ror_epi32(src, k, a, imm8) simde_mm_mask_mov_epi32(src, k, simde_mm_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_ror_epi32
  #define _mm_mask_ror_epi32(src, k, a, imm8) simde_mm_mask_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_ror_epi32(k, a, imm8) _mm_maskz_ror_epi32(k, a, imm8)
#else
  #define simde_mm_maskz_ror_epi32(k, a, imm8) simde_mm_maskz_mov_epi32(k, simde_mm_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_ror_epi32
  #define _mm_maskz_ror_epi32(src, k, a, imm8) simde_mm_maskz_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_ror_epi32(a, imm8) _mm256_ror_epi32(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256i
  simde_mm256_ror_epi32 (simde__m256i a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a);

    switch (imm8 & 31) {
      case 0:
        r_ = a_;
        break;
      default:
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = (a_.u32[i] >> (imm8 & 31)) | (a_.u32[i] << (32 - (imm8 & 31)));
        }
        break;
    }

    return simde__m256i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_ror_epi32
  #define _mm256_ror_epi32(a, imm8) simde_mm256_ror_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_ror_epi32(src, k, a, imm8) _mm256_mask_ror_epi32(src, k, a, imm8)
#else
  #define simde_mm256_mask_ror_epi32(src, k, a, imm8) simde_mm256_mask_mov_epi32(src, k, simde_mm256_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_ror_epi32
  #define _mm256_mask_ror_epi32(src, k, a, imm8) simde_mm256_mask_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_ror_epi32(k, a, imm8) _mm256_maskz_ror_epi32(k, a, imm8)
#else
  #define simde_mm256_maskz_ror_epi32(k, a, imm8) simde_mm256_maskz_mov_epi32(k, simde_mm256_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_ror_epi32
  #define _mm256_maskz_ror_epi32(k, a, imm8) simde_mm256_maskz_ror_epi32(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_ror_epi32(a, imm8) _mm512_ror_epi32(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512i
  simde_mm512_ror_epi32 (simde__m512i a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a);

    switch (imm8 & 31) {
      case 0:
        r_ = a_;
        break;
      default:
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = (a_.u32[i] >> (imm8 & 31)) | (a_.u32[i] << (32 - (imm8 & 31)));
        }
        break;
    }

    return simde__m512i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_ror_epi32
  #define _mm512_ror_epi32(a, imm8) simde_mm512_ror_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_ror_epi32(src, k, a, imm8) _mm512_mask_ror_epi32(src, k, a, imm8)
#else
  #define simde_mm512_mask_ror_epi32(src, k, a, imm8) simde_mm512_mask_mov_epi32(src, k, simde_mm512_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_ror_epi32
  #define _mm512_mask_ror_epi32(src, k, a, imm8) simde_mm512_mask_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_ror_epi32(k, a, imm8) _mm512_maskz_ror_epi32(k, a, imm8)
#else
  #define simde_mm512_maskz_ror_epi32(k, a, imm8) simde_mm512_maskz_mov_epi32(k, simde_mm512_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_ror_epi32
  #define _mm512_maskz_ror_epi32(k, a, imm8) simde_mm512_maskz_ror_epi32(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_ror_epi64(a, imm8) _mm_ror_epi64(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_ror_epi64 (simde__m128i a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    switch (imm8 & 63) {
      case 0:
        r_ = a_;
        break;
      default:
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
          r_.u64[i] = (a_.u64[i] >> (imm8 & 63)) | (a_.u64[i] << (64 - (imm8 & 63)));
        }
        break;
    }

    return simde__m128i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_ror_epi64
  #define _mm_ror_epi64(a, imm8) simde_mm_ror_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_ror_epi64(src, k, a, imm8) _mm_mask_ror_epi64(src, k, a, imm8)
#else
  #define simde_mm_mask_ror_epi64(src, k, a, imm8) simde_mm_mask_mov_epi64(src, k, simde_mm_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_ror_epi64
  #define _mm_mask_ror_epi64(src, k, a, imm8) simde_mm_mask_ror_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_ror_epi64(k, a, imm8) _mm_maskz_ror_epi64(k, a, imm8)
#else
  #define simde_mm_maskz_ror_epi64(k, a, imm8) simde_mm_maskz_mov_epi64(k, simde_mm_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_ror_epi64
  #define _mm_maskz_ror_epi64(k, a, imm8) simde_mm_maskz_ror_epi64(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_ror_epi64(a, imm8) _mm256_ror_epi64(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256i
  simde_mm256_ror_epi64 (simde__m256i a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a);

    switch (imm8 & 63) {
      case 0:
        r_ = a_;
        break;
      default:
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
          r_.u64[i] = (a_.u64[i] >> (imm8 & 63)) | (a_.u64[i] << (64 - (imm8 & 63)));
        }
        break;
    }

    return simde__m256i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_ror_epi64
  #define _mm256_ror_epi64(a, imm8) simde_mm256_ror_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_ror_epi64(src, k, a, imm8) _mm256_mask_ror_epi64(src, k, a, imm8)
#else
  #define simde_mm256_mask_ror_epi64(src, k, a, imm8) simde_mm256_mask_mov_epi64(src, k, simde_mm256_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_ror_epi64
  #define _mm256_mask_ror_epi64(src, k, a, imm8) simde_mm256_mask_ror_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_ror_epi64(k, a, imm8) _mm256_maskz_ror_epi64(k, a, imm8)
#else
  #define simde_mm256_maskz_ror_epi64(k, a, imm8) simde_mm256_maskz_mov_epi64(k, simde_mm256_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_ror_epi64
  #define _mm256_maskz_ror_epi64(k, a, imm8) simde_mm256_maskz_ror_epi64(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_ror_epi64(a, imm8) _mm512_ror_epi64(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512i
  simde_mm512_ror_epi64 (simde__m512i a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a);

    switch (imm8 & 63) {
      case 0:
        r_ = a_;
        break;
      default:
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
          r_.u64[i] = (a_.u64[i] >> (imm8 & 63)) | (a_.u64[i] << (64 - (imm8 & 63)));
        }
        break;
    }

    return simde__m512i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_ror_epi64
  #define _mm512_ror_epi64(a, imm8) simde_mm512_ror_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_ror_epi64(src, k, a, imm8) _mm512_mask_ror_epi64(src, k, a, imm8)
#else
  #define simde_mm512_mask_ror_epi64(src, k, a, imm8) simde_mm512_mask_mov_epi64(src, k, simde_mm512_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_ror_epi64
  #define _mm512_mask_ror_epi64(src, k, a, imm8) simde_mm512_mask_ror_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_ror_epi64(k, a, imm8) _mm512_maskz_ror_epi64(k, a, imm8)
#else
  #define simde_mm512_maskz_ror_epi64(k, a, imm8) simde_mm512_maskz_mov_epi64(k, simde_mm512_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_ror_epi64
  #define _mm512_maskz_ror_epi64(k, a, imm8) simde_mm512_maskz_ror_epi64(k, a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ROR_H) */
