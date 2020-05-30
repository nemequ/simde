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
 *   2017-2020 Evan Nemerson <evan@nemerson.com>
 */

/* Attempt to find math functions.  Functions may be in <cmath>,
 * <math.h>, compiler built-ins/intrinsics, or platform/architecture
 * specific headers.  In some cases, especially those not built in to
 * libm, we may need to define our own implementations.
 *
 * Including <cmath> will undefine isnan, so we need to use
 * std::isnan.  However, we can't just use std::isnan in C++ because
 * if <cmath> hasn't been included but <math.h> has we'll have isnan
 * but not std::isnan.  Unfortunately, it seems some implementations
 * are buggy and define HUGE_VAL somehow but don't define isnan or
 * std::isnan.  If you run into one of these please let us know so we
 * can try to figure out how to detect it. */

#if !defined(SIMDE_MATH_H)

#include "hedley.h"

#if defined(__has_builtin)
  #define SIMDE_MATH_BUILTIN_LIBM(func) __has_builtin(__builtin_##func)
#elif \
    HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    HEDLEY_GCC_VERSION_CHECK(4,4,0)
  #define SIMDE_MATH_BUILTIN_LIBM(func) (0)
#else
  #define SIMDE_MATH_BUILTIN_LIBM(func) (0)
#endif

#if defined(HUGE_VAL)
  /* Looks like <math.h> or <cmath> has already been included. */

  /* The math.h from libc++ (yes, the C header from the C++ standard
   * library) will define an isnan function, but not an isnan macro
   * like the C standard requires.  So, we detect the header guards
   * macro libc++ uses. */
  #if defined(isnan) || (defined(_LIBCPP_MATH_H) && !defined(_LIBCPP_CMATH))
    #define SIMDE_MATH_HAVE_MATH_H
  #elif defined(__cplusplus)
    #define SIMDE_MATH_HAVE_CMATH
  #endif
#elif defined(__has_include)
  #if defined(__cplusplus) && (__cplusplus >= 201103L) && __has_include(<cmath>)
    #define SIMDE_MATH_HAVE_CMATH
    #include <cmath>
  #elif __has_include(<math.h>)
    #define SIMDE_MATH_HAVE_MATH_H
    #include <math.h>
  #elif !defined(SIMDE_MATH_NO_LIBM)
    #define SIMDE_MATH_NO_LIBM
  #endif
#elif !defined(SIMDE_MATH_NO_LIBM)
  #if defined(__cplusplus) && (__cplusplus >= 201103L)
    #define SIMDE_MATH_HAVE_CMATH
    HEDLEY_DIAGNOSTIC_PUSH
    #if defined(HEDLEY_MSVC_VERSION)
      /* VS 14 emits this diagnostic about noexcept being used on a
       * <cmath>, which we can't do anything about. */
      #pragma warning(disable:4996)
    #endif
    #include <cmath>
    HEDLEY_DIAGNOSTIC_POP
  #else
    #define SIMDE_MATH_HAVE_MATH_H
    #include <math.h>
  #endif
#endif


/*** Classification macros from C99 ***/

#if !defined(simde_math_isnan)
  #if SIMDE_MATH_BUILTIN_LIBM(isnan)
    #define simde_math_isnan(v) __builtin_isnan(v)
  #elif defined(isnan) || defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_isnan(v) isnan(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_isnan(v) std::isnan(v)
  #endif
#endif

#if !defined(simde_math_isnanf)
  #if HEDLEY_HAS_BUILTIN(__builtin_isnanf) || \
      HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
      HEDLEY_ARM_VERSION_CHECK(4,1,0)
    /* XL C/C++ has __builtin_isnan but not __builtin_isnanf */
    #define simde_math_isnanf(v) __builtin_isnanf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_isnanf(v) std::isnan(v)
  #elif defined(simde_math_isnan)
    #define simde_math_isnanf(v) simde_math_isnan(HEDLEY_STATIC_CAST(double, v))
  #endif
#endif

#if !defined(simde_math_isnormal)
  #if SIMDE_MATH_BUILTIN_LIBM(isnormal)
    #define simde_math_isnormal(v) __builtin_isnormal(v)
  #elif defined(isnormal) || defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_isnormal(v) isnormal(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_isnormal(v) std::isnormal(v)
  #elif defined(simde_math_isnan)
    #define simde_math_isnormal(v) simde_math_isnormal(v)
  #endif
#endif

/*** Functions from C99 ***/

#if !defined(simde_math_abs)
  #if SIMDE_MATH_BUILTIN_LIBM(abs)
    #define simde_math_abs(v) __builtin_abs(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_abs(v) std::abs(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_abs(v) abs(v)
  #endif
#endif

#if !defined(simde_math_absf)
  #if SIMDE_MATH_BUILTIN_LIBM(absf)
    #define simde_math_absf(v) __builtin_absf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_absf(v) std::abs(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_absf(v) absf(v)
  #endif
#endif

#if !defined(simde_math_acos)
  #if SIMDE_MATH_BUILTIN_LIBM(acos)
    #define simde_math_acos(v) __builtin_acos(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_acos(v) std::acos(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_acos(v) acos(v)
  #endif
#endif

#if !defined(simde_math_acosf)
  #if SIMDE_MATH_BUILTIN_LIBM(acosf)
    #define simde_math_acosf(v) __builtin_acosf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_acosf(v) std::acos(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_acosf(v) acosf(v)
  #endif
#endif

#if !defined(simde_math_acosh)
  #if SIMDE_MATH_BUILTIN_LIBM(acosh)
    #define simde_math_acosh(v) __builtin_acosh(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_acosh(v) std::acosh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_acosh(v) acosh(v)
  #endif
#endif

#if !defined(simde_math_acoshf)
  #if SIMDE_MATH_BUILTIN_LIBM(acoshf)
    #define simde_math_acoshf(v) __builtin_acoshf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_acoshf(v) std::acosh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_acoshf(v) acoshf(v)
  #endif
#endif

#if !defined(simde_math_asin)
  #if SIMDE_MATH_BUILTIN_LIBM(asin)
    #define simde_math_asin(v) __builtin_asin(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_asin(v) std::asin(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_asin(v) asin(v)
  #endif
#endif

#if !defined(simde_math_asinf)
  #if SIMDE_MATH_BUILTIN_LIBM(asinf)
    #define simde_math_asinf(v) __builtin_asinf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_asinf(v) std::asin(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_asinf(v) asinf(v)
  #endif
#endif

#if !defined(simde_math_atan)
  #if SIMDE_MATH_BUILTIN_LIBM(atan)
    #define simde_math_atan(v) __builtin_atan(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_atan(v) std::atan(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_atan(v) atan(v)
  #endif
#endif

#if !defined(simde_math_atanf)
  #if SIMDE_MATH_BUILTIN_LIBM(atanf)
    #define simde_math_atanf(v) __builtin_atanf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_atanf(v) std::atan(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_atanf(v) atanf(v)
  #endif
#endif

#if !defined(simde_math_ceil)
  #if SIMDE_MATH_BUILTIN_LIBM(ceil)
    #define simde_math_ceil(v) __builtin_ceil(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_ceil(v) std::ceil(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_ceil(v) ceil(v)
  #endif
#endif

#if !defined(simde_math_ceilf)
  #if SIMDE_MATH_BUILTIN_LIBM(ceilf)
    #define simde_math_ceilf(v) __builtin_ceilf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_ceilf(v) std::ceil(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_ceilf(v) ceilf(v)
  #endif
#endif

#if !defined(simde_math_cos)
  #if SIMDE_MATH_BUILTIN_LIBM(cos)
    #define simde_math_cos(v) __builtin_cos(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_cos(v) std::cos(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_cos(v) cos(v)
  #endif
#endif

#if !defined(simde_math_cosf)
  #if SIMDE_MATH_BUILTIN_LIBM(cosf)
    #define simde_math_cosf(v) __builtin_cosf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_cosf(v) std::cos(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_cosf(v) cosf(v)
  #endif
#endif

#if !defined(simde_math_cosh)
  #if SIMDE_MATH_BUILTIN_LIBM(cosh)
    #define simde_math_cosh(v) __builtin_cosh(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_cosh(v) std::cosh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_cosh(v) cosh(v)
  #endif
#endif

#if !defined(simde_math_coshf)
  #if SIMDE_MATH_BUILTIN_LIBM(coshf)
    #define simde_math_coshf(v) __builtin_coshf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_coshf(v) std::cosh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_coshf(v) coshf(v)
  #endif
#endif

#if !defined(simde_math_exp)
  #if SIMDE_MATH_BUILTIN_LIBM(exp)
    #define simde_math_exp(v) __builtin_exp(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_exp(v) std::exp(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_exp(v) exp(v)
  #endif
#endif

#if !defined(simde_math_expf)
  #if SIMDE_MATH_BUILTIN_LIBM(expf)
    #define simde_math_expf(v) __builtin_expf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_expf(v) std::exp(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_expf(v) expf(v)
  #endif
#endif

#if !defined(simde_math_fabs)
  #if SIMDE_MATH_BUILTIN_LIBM(fabs)
    #define simde_math_fabs(v) __builtin_fabs(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_fabs(v) std::fabs(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_fabs(v) fabs(v)
  #endif
#endif

#if !defined(simde_math_fabsf)
  #if SIMDE_MATH_BUILTIN_LIBM(fabsf)
    #define simde_math_fabsf(v) __builtin_fabsf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_fabsf(v) std::fabs(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_fabsf(v) fabsf(v)
  #endif
#endif

#if !defined(simde_math_floor)
  #if SIMDE_MATH_BUILTIN_LIBM(floor)
    #define simde_math_floor(v) __builtin_floor(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_floor(v) std::floor(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_floor(v) floor(v)
  #endif
#endif

#if !defined(simde_math_floorf)
  #if SIMDE_MATH_BUILTIN_LIBM(floorf)
    #define simde_math_floorf(v) __builtin_floorf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_floorf(v) std::floor(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_floorf(v) floorf(v)
  #endif
#endif

#if !defined(simde_math_nearbyint)
  #if SIMDE_MATH_BUILTIN_LIBM(nearbyint)
    #define simde_math_nearbyint(v) __builtin_nearbyint(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_nearbyint(v) std::nearbyint(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_nearbyint(v) nearbyint(v)
  #endif
#endif

#if !defined(simde_math_nearbyintf)
  #if SIMDE_MATH_BUILTIN_LIBM(nearbyintf)
    #define simde_math_nearbyintf(v) __builtin_nearbyintf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_nearbyintf(v) std::nearbyint(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_nearbyintf(v) nearbyintf(v)
  #endif
#endif

#if !defined(simde_math_round)
  #if SIMDE_MATH_BUILTIN_LIBM(round)
    #define simde_math_round(v) __builtin_round(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_round(v) std::round(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_round(v) round(v)
  #endif
#endif

#if !defined(simde_math_roundf)
  #if SIMDE_MATH_BUILTIN_LIBM(roundf)
    #define simde_math_roundf(v) __builtin_roundf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_roundf(v) std::round(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_roundf(v) roundf(v)
  #endif
#endif

#if !defined(simde_math_sin)
  #if SIMDE_MATH_BUILTIN_LIBM(sin)
    #define simde_math_sin(v) __builtin_sin(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_sin(v) std::sin(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_sin(v) sin(v)
  #endif
#endif

#if !defined(simde_math_sinf)
  #if SIMDE_MATH_BUILTIN_LIBM(sinf)
    #define simde_math_sinf(v) __builtin_sinf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_sinf(v) std::sin(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_sinf(v) sinf(v)
  #endif
#endif

#if !defined(simde_math_sinh)
  #if SIMDE_MATH_BUILTIN_LIBM(sinh)
    #define simde_math_sinh(v) __builtin_sinh(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_sinh(v) std::sinh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_sinh(v) sinh(v)
  #endif
#endif

#if !defined(simde_math_sinhf)
  #if SIMDE_MATH_BUILTIN_LIBM(sinhf)
    #define simde_math_sinhf(v) __builtin_sinhf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_sinhf(v) std::sinh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_sinhf(v) sinhf(v)
  #endif
#endif

#if !defined(simde_math_sqrt)
  #if SIMDE_MATH_BUILTIN_LIBM(sqrt)
    #define simde_math_sqrt(v) __builtin_sqrt(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_sqrt(v) std::sqrt(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_sqrt(v) sqrt(v)
  #endif
#endif

#if !defined(simde_math_sqrtf)
  #if SIMDE_MATH_BUILTIN_LIBM(sqrtf)
    #define simde_math_sqrtf(v) __builtin_sqrtf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_sqrtf(v) std::sqrt(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_sqrtf(v) sqrtf(v)
  #endif
#endif

#if !defined(simde_math_tan)
  #if SIMDE_MATH_BUILTIN_LIBM(tan)
    #define simde_math_tan(v) __builtin_tan(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_tan(v) std::tan(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_tan(v) tan(v)
  #endif
#endif

#if !defined(simde_math_tanf)
  #if SIMDE_MATH_BUILTIN_LIBM(tanf)
    #define simde_math_tanf(v) __builtin_tanf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_tanf(v) std::tan(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_tanf(v) tanf(v)
  #endif
#endif

#if !defined(simde_math_tanh)
  #if SIMDE_MATH_BUILTIN_LIBM(tanh)
    #define simde_math_tanh(v) __builtin_tanh(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_tanh(v) std::tanh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_tanh(v) tanh(v)
  #endif
#endif

#if !defined(simde_math_tanhf)
  #if SIMDE_MATH_BUILTIN_LIBM(tanhf)
    #define simde_math_tanhf(v) __builtin_tanhf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_tanhf(v) std::tanh(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_tanhf(v) tanhf(v)
  #endif
#endif

#if !defined(simde_math_trunc)
  #if SIMDE_MATH_BUILTIN_LIBM(trunc)
    #define simde_math_trunc(v) __builtin_trunc(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_trunc(v) std::trunc(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_trunc(v) trunc(v)
  #endif
#endif

#if !defined(simde_math_truncf)
  #if SIMDE_MATH_BUILTIN_LIBM(truncf)
    #define simde_math_truncf(v) __builtin_truncf(v)
  #elif defined(SIMDE_MATH_HAVE_CMATH)
    #define simde_math_truncf(v) std::trunc(v)
  #elif defined(SIMDE_MATH_HAVE_MATH_H)
    #define simde_math_truncf(v) truncf(v)
  #endif
#endif

#if defined(M_PI)
  #define SIMDE_MATH_PI M_PI
#else
  #define SIMDE_MATH_PI 3.14159265358979323846
#endif

/*** Additional functions not in libm ***/

#if defined(simde_math_fabs) && defined(simde_math_sqrt) && defined(simde_math_exp)
  static HEDLEY_INLINE
  double
  simde_math_cdfnorm(double x) {
    /* https://www.johndcook.com/blog/cpp_phi/
    * Public Domain */
    static const double a1 =  0.254829592;
    static const double a2 = -0.284496736;
    static const double a3 =  1.421413741;
    static const double a4 = -1.453152027;
    static const double a5 =  1.061405429;
    static const double p  =  0.3275911;

    const int sign = x < 0;
    x = simde_math_fabs(x) / simde_math_sqrt(2.0);

    /* A&S formula 7.1.26 */
    double t = 1.0 / (1.0 + p * x);
    double y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * simde_math_exp(-x * x);

    return 0.5 * (1.0 + (sign ? -y : y));
  }
  #define simde_math_cdfnorm simde_math_cdfnorm
#endif

#if defined(simde_math_fabsf) && defined(simde_math_sqrtf) && defined(simde_math_expf)
  static HEDLEY_INLINE
  float
  simde_math_cdfnormf(float x) {
    /* https://www.johndcook.com/blog/cpp_phi/
    * Public Domain */
    static const float a1 =  0.254829592f;
    static const float a2 = -0.284496736f;
    static const float a3 =  1.421413741f;
    static const float a4 = -1.453152027f;
    static const float a5 =  1.061405429f;
    static const float p  =  0.3275911f;

    const int sign = x < 0;
    x = simde_math_fabsf(x) / simde_math_sqrtf(2.0f);

    /* A&S formula 7.1.26 */
    float t = 1.0f / (1.0f + p * x);
    float y = 1.0f - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * simde_math_expf(-x * x);

    return 0.5f * (1.0f + (sign ? -y : y));
  }
  #define simde_math_cdfnormf simde_math_cdfnormf
#endif

static HEDLEY_INLINE
double
simde_math_rad2deg(double radians) {
 return radians * (180.0 / SIMDE_MATH_PI);
}

static HEDLEY_INLINE
double
simde_math_deg2rad(double degrees) {
  return degrees * (SIMDE_MATH_PI / 180.0);
}

static HEDLEY_INLINE
float
simde_math_rad2degf(float radians) {
    return radians * (180.0f / HEDLEY_STATIC_CAST(float, SIMDE_MATH_PI));
}

static HEDLEY_INLINE
float
simde_math_deg2radf(float degrees) {
    return degrees * (HEDLEY_STATIC_CAST(float, SIMDE_MATH_PI) / 180.0f);
}

#endif /* !defined(SIMDE_MATH_H) */
