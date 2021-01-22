/* Copyright (c) 2017, 2019 Evan Nemerson <evan@nemerson.com>
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
 */

#define SIMDE_TESTS_CURRENT_ISAX sse
#include <simde/x86/sse2.h>
#include <test/x86/test-sse2.h>

#if defined(HEDLEY_MSVC_VERSION)
#  pragma warning(disable:4223)
#endif

#if defined(HEDLEY_MSVC_VERSION)
#  pragma warning(disable:4324)
#endif

static int
test_simde_mm_set_ps(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[sizeof(simde__m128) / sizeof(simde_float32)];
    simde_float32 r[sizeof(simde__m128) / sizeof(simde_float32)];
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(   -97.93), SIMDE_FLOAT32_C(   487.12), SIMDE_FLOAT32_C(   843.18), SIMDE_FLOAT32_C(   237.66) },
      { SIMDE_FLOAT32_C(   -97.93), SIMDE_FLOAT32_C(   487.12), SIMDE_FLOAT32_C(   843.18), SIMDE_FLOAT32_C(   237.66) } },
    { { SIMDE_FLOAT32_C(   627.94), SIMDE_FLOAT32_C(   -96.43), SIMDE_FLOAT32_C(   561.80), SIMDE_FLOAT32_C(   279.44) },
      { SIMDE_FLOAT32_C(   627.94), SIMDE_FLOAT32_C(   -96.43), SIMDE_FLOAT32_C(   561.80), SIMDE_FLOAT32_C(   279.44) } },
    { { SIMDE_FLOAT32_C(   624.69), SIMDE_FLOAT32_C(    44.07), SIMDE_FLOAT32_C(   250.52), SIMDE_FLOAT32_C(     5.41) },
      { SIMDE_FLOAT32_C(   624.69), SIMDE_FLOAT32_C(    44.07), SIMDE_FLOAT32_C(   250.52), SIMDE_FLOAT32_C(     5.41) } },
    { { SIMDE_FLOAT32_C(   782.09), SIMDE_FLOAT32_C(   437.78), SIMDE_FLOAT32_C(   640.50), SIMDE_FLOAT32_C(   -79.45) },
      { SIMDE_FLOAT32_C(   782.09), SIMDE_FLOAT32_C(   437.78), SIMDE_FLOAT32_C(   640.50), SIMDE_FLOAT32_C(   -79.45) } },
    { { SIMDE_FLOAT32_C(   962.63), SIMDE_FLOAT32_C(   -46.96), SIMDE_FLOAT32_C(   706.41), SIMDE_FLOAT32_C(   465.51) },
      { SIMDE_FLOAT32_C(   962.63), SIMDE_FLOAT32_C(   -46.96), SIMDE_FLOAT32_C(   706.41), SIMDE_FLOAT32_C(   465.51) } },
    { { SIMDE_FLOAT32_C(   701.40), SIMDE_FLOAT32_C(   189.03), SIMDE_FLOAT32_C(   149.80), SIMDE_FLOAT32_C(   519.08) },
      { SIMDE_FLOAT32_C(   701.40), SIMDE_FLOAT32_C(   189.03), SIMDE_FLOAT32_C(   149.80), SIMDE_FLOAT32_C(   519.08) } },
    { { SIMDE_FLOAT32_C(   706.01), SIMDE_FLOAT32_C(   918.36), SIMDE_FLOAT32_C(   149.95), SIMDE_FLOAT32_C(   205.77) },
      { SIMDE_FLOAT32_C(   706.01), SIMDE_FLOAT32_C(   918.36), SIMDE_FLOAT32_C(   149.95), SIMDE_FLOAT32_C(   205.77) } },
    { { SIMDE_FLOAT32_C(   -61.28), SIMDE_FLOAT32_C(    87.71), SIMDE_FLOAT32_C(   709.93), SIMDE_FLOAT32_C(   -59.21) },
      { SIMDE_FLOAT32_C(   -61.28), SIMDE_FLOAT32_C(    87.71), SIMDE_FLOAT32_C(   709.93), SIMDE_FLOAT32_C(   -59.21) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32* a = test_vec[i].a;
    simde__m128 r = simde_mm_set_ps(a[3], a[2], a[1], a[0]);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_set_ps1(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    float a;
    simde__m128 r;
  } test_vec[8] = {
    {      0.29f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(     0.29)) },
    {      0.14f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.14)) },
    {      0.98f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     0.98)) },
    {      0.88f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(     0.88)) },
    {      0.92f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.92)) },
    {      0.07f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(     0.07)) },
    {      0.66f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.66)) },
    {      0.47f,
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.47)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_set_ps1(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}


static int
test_simde_mm_set_ss(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a;
    simde_float32 r[sizeof(simde__m128) / sizeof(simde_float32)];
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(-521.61),
      { SIMDE_FLOAT32_C(  -521.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(992.45),
      { SIMDE_FLOAT32_C(   992.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(274.16),
      { SIMDE_FLOAT32_C(   274.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(897.70),
      { SIMDE_FLOAT32_C(   897.70), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(-80.03),
      { SIMDE_FLOAT32_C(   -80.03), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(-294.04),
      { SIMDE_FLOAT32_C(  -294.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(421.54),
      { SIMDE_FLOAT32_C(   421.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { SIMDE_FLOAT32_C(458.33),
      { SIMDE_FLOAT32_C(   458.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 r = simde_mm_set_ss(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_set1_ps(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a;
    simde_float32 r[sizeof(simde__m128) / sizeof(simde_float32)];
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(968.47),
      { SIMDE_FLOAT32_C(   968.47), SIMDE_FLOAT32_C(   968.47), SIMDE_FLOAT32_C(   968.47), SIMDE_FLOAT32_C(   968.47) } },
    { SIMDE_FLOAT32_C(560.37),
      { SIMDE_FLOAT32_C(   560.37), SIMDE_FLOAT32_C(   560.37), SIMDE_FLOAT32_C(   560.37), SIMDE_FLOAT32_C(   560.37) } },
    { SIMDE_FLOAT32_C(509.11),
      { SIMDE_FLOAT32_C(   509.11), SIMDE_FLOAT32_C(   509.11), SIMDE_FLOAT32_C(   509.11), SIMDE_FLOAT32_C(   509.11) } },
    { SIMDE_FLOAT32_C(34.32),
      { SIMDE_FLOAT32_C(    34.32), SIMDE_FLOAT32_C(    34.32), SIMDE_FLOAT32_C(    34.32), SIMDE_FLOAT32_C(    34.32) } },
    { SIMDE_FLOAT32_C(-34.10),
      { SIMDE_FLOAT32_C(   -34.10), SIMDE_FLOAT32_C(   -34.10), SIMDE_FLOAT32_C(   -34.10), SIMDE_FLOAT32_C(   -34.10) } },
    { SIMDE_FLOAT32_C(357.28),
      { SIMDE_FLOAT32_C(   357.28), SIMDE_FLOAT32_C(   357.28), SIMDE_FLOAT32_C(   357.28), SIMDE_FLOAT32_C(   357.28) } },
    { SIMDE_FLOAT32_C(-650.83),
      { SIMDE_FLOAT32_C(  -650.83), SIMDE_FLOAT32_C(  -650.83), SIMDE_FLOAT32_C(  -650.83), SIMDE_FLOAT32_C(  -650.83) } },
    { SIMDE_FLOAT32_C(429.31),
      { SIMDE_FLOAT32_C(   429.31), SIMDE_FLOAT32_C(   429.31), SIMDE_FLOAT32_C(   429.31), SIMDE_FLOAT32_C(   429.31) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 r = simde_mm_set1_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_setr_ps(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[sizeof(simde__m128) / sizeof(simde_float32)];
    simde_float32 r[sizeof(simde__m128) / sizeof(simde_float32)];
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(   955.73), SIMDE_FLOAT32_C(   396.29), SIMDE_FLOAT32_C(   305.27), SIMDE_FLOAT32_C(   896.93) },
      { SIMDE_FLOAT32_C(   896.93), SIMDE_FLOAT32_C(   305.27), SIMDE_FLOAT32_C(   396.29), SIMDE_FLOAT32_C(   955.73) } },
    { { SIMDE_FLOAT32_C(   982.30), SIMDE_FLOAT32_C(   209.24), SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(    23.25) },
      { SIMDE_FLOAT32_C(    23.25), SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(   209.24), SIMDE_FLOAT32_C(   982.30) } },
    { { SIMDE_FLOAT32_C(   860.95), SIMDE_FLOAT32_C(   -26.58), SIMDE_FLOAT32_C(   238.44), SIMDE_FLOAT32_C(   340.72) },
      { SIMDE_FLOAT32_C(   340.72), SIMDE_FLOAT32_C(   238.44), SIMDE_FLOAT32_C(   -26.58), SIMDE_FLOAT32_C(   860.95) } },
    { { SIMDE_FLOAT32_C(   -48.15), SIMDE_FLOAT32_C(   640.42), SIMDE_FLOAT32_C(   675.86), SIMDE_FLOAT32_C(   647.82) },
      { SIMDE_FLOAT32_C(   647.82), SIMDE_FLOAT32_C(   675.86), SIMDE_FLOAT32_C(   640.42), SIMDE_FLOAT32_C(   -48.15) } },
    { { SIMDE_FLOAT32_C(   453.33), SIMDE_FLOAT32_C(   576.55), SIMDE_FLOAT32_C(   828.03), SIMDE_FLOAT32_C(   770.37) },
      { SIMDE_FLOAT32_C(   770.37), SIMDE_FLOAT32_C(   828.03), SIMDE_FLOAT32_C(   576.55), SIMDE_FLOAT32_C(   453.33) } },
    { { SIMDE_FLOAT32_C(   438.60), SIMDE_FLOAT32_C(   313.90), SIMDE_FLOAT32_C(   397.19), SIMDE_FLOAT32_C(    64.15) },
      { SIMDE_FLOAT32_C(    64.15), SIMDE_FLOAT32_C(   397.19), SIMDE_FLOAT32_C(   313.90), SIMDE_FLOAT32_C(   438.60) } },
    { { SIMDE_FLOAT32_C(   430.55), SIMDE_FLOAT32_C(   275.82), SIMDE_FLOAT32_C(   482.54), SIMDE_FLOAT32_C(    85.82) },
      { SIMDE_FLOAT32_C(    85.82), SIMDE_FLOAT32_C(   482.54), SIMDE_FLOAT32_C(   275.82), SIMDE_FLOAT32_C(   430.55) } },
    { { SIMDE_FLOAT32_C(   486.66), SIMDE_FLOAT32_C(   277.28), SIMDE_FLOAT32_C(    62.44), SIMDE_FLOAT32_C(   442.39) },
      { SIMDE_FLOAT32_C(   442.39), SIMDE_FLOAT32_C(    62.44), SIMDE_FLOAT32_C(   277.28), SIMDE_FLOAT32_C(   486.66) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32* a = test_vec[i].a;
    simde__m128 r = simde_mm_setr_ps(a[3], a[2], a[1], a[0]);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_setzero_ps(SIMDE_MUNIT_TEST_ARGS) {
  simde_test_x86_assert_equal_f32x4(simde_mm_setzero_ps(), simde_mm_set1_ps(0.0f), 1);

  return 0;
}

static int
test_simde_x_mm_setone_ps(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128 r = simde_x_mm_setone_ps();
  simde_test_x86_assert_equal_u32x4(simde_mm_castps_si128(r), simde_mm_set1_epi32(~INT32_C(0)));

  return 0;
}

static int
test_simde_x_mm_abs_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -421.46), SIMDE_FLOAT32_C(  -889.21), SIMDE_FLOAT32_C(  -223.16), SIMDE_FLOAT32_C(   165.23) },
      { SIMDE_FLOAT32_C(   421.46), SIMDE_FLOAT32_C(   889.21), SIMDE_FLOAT32_C(   223.16), SIMDE_FLOAT32_C(   165.23) } },
    { { SIMDE_FLOAT32_C(  -519.69), SIMDE_FLOAT32_C(   704.36), SIMDE_FLOAT32_C(    72.76), SIMDE_FLOAT32_C(   522.49) },
      { SIMDE_FLOAT32_C(   519.69), SIMDE_FLOAT32_C(   704.36), SIMDE_FLOAT32_C(    72.76), SIMDE_FLOAT32_C(   522.49) } },
    { { SIMDE_FLOAT32_C(   870.86), SIMDE_FLOAT32_C(  -918.56), SIMDE_FLOAT32_C(   997.87), SIMDE_FLOAT32_C(   143.92) },
      { SIMDE_FLOAT32_C(   870.86), SIMDE_FLOAT32_C(   918.56), SIMDE_FLOAT32_C(   997.87), SIMDE_FLOAT32_C(   143.92) } },
    { { SIMDE_FLOAT32_C(   368.61), SIMDE_FLOAT32_C(   537.92), SIMDE_FLOAT32_C(   637.07), SIMDE_FLOAT32_C(  -512.16) },
      { SIMDE_FLOAT32_C(   368.61), SIMDE_FLOAT32_C(   537.92), SIMDE_FLOAT32_C(   637.07), SIMDE_FLOAT32_C(   512.16) } },
    { { SIMDE_FLOAT32_C(   125.42), SIMDE_FLOAT32_C(   861.61), SIMDE_FLOAT32_C(  -914.90), SIMDE_FLOAT32_C(  -887.65) },
      { SIMDE_FLOAT32_C(   125.42), SIMDE_FLOAT32_C(   861.61), SIMDE_FLOAT32_C(   914.90), SIMDE_FLOAT32_C(   887.65) } },
    { { SIMDE_FLOAT32_C(  -429.10), SIMDE_FLOAT32_C(   351.84), SIMDE_FLOAT32_C(   840.63), SIMDE_FLOAT32_C(  -928.69) },
      { SIMDE_FLOAT32_C(   429.10), SIMDE_FLOAT32_C(   351.84), SIMDE_FLOAT32_C(   840.63), SIMDE_FLOAT32_C(   928.69) } },
    { { SIMDE_FLOAT32_C(  -715.59), SIMDE_FLOAT32_C(   906.22), SIMDE_FLOAT32_C(   -64.85), SIMDE_FLOAT32_C(   686.85) },
      { SIMDE_FLOAT32_C(   715.59), SIMDE_FLOAT32_C(   906.22), SIMDE_FLOAT32_C(    64.85), SIMDE_FLOAT32_C(   686.85) } },
    { { SIMDE_FLOAT32_C(   445.44), SIMDE_FLOAT32_C(   794.89), SIMDE_FLOAT32_C(    44.90), SIMDE_FLOAT32_C(  -976.02) },
      { SIMDE_FLOAT32_C(   445.44), SIMDE_FLOAT32_C(   794.89), SIMDE_FLOAT32_C(    44.90), SIMDE_FLOAT32_C(   976.02) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_x_mm_abs_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_add_ps (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    83.02), SIMDE_FLOAT32_C(   389.11), SIMDE_FLOAT32_C(  -551.93), SIMDE_FLOAT32_C(   499.43) },
      { SIMDE_FLOAT32_C(   438.42), SIMDE_FLOAT32_C(   399.55), SIMDE_FLOAT32_C(  -203.56), SIMDE_FLOAT32_C(   299.49) },
      { SIMDE_FLOAT32_C(   521.44), SIMDE_FLOAT32_C(   788.66), SIMDE_FLOAT32_C(  -755.49), SIMDE_FLOAT32_C(   798.92) } },
    { { SIMDE_FLOAT32_C(  -379.62), SIMDE_FLOAT32_C(   462.50), SIMDE_FLOAT32_C(  -825.60), SIMDE_FLOAT32_C(    38.74) },
      { SIMDE_FLOAT32_C(   149.18), SIMDE_FLOAT32_C(    29.45), SIMDE_FLOAT32_C(   149.99), SIMDE_FLOAT32_C(   766.00) },
      { SIMDE_FLOAT32_C(  -230.44), SIMDE_FLOAT32_C(   491.94), SIMDE_FLOAT32_C(  -675.61), SIMDE_FLOAT32_C(   804.74) } },
    { { SIMDE_FLOAT32_C(   856.05), SIMDE_FLOAT32_C(   987.49), SIMDE_FLOAT32_C(   -70.35), SIMDE_FLOAT32_C(  -659.83) },
      { SIMDE_FLOAT32_C(  -940.54), SIMDE_FLOAT32_C(   739.82), SIMDE_FLOAT32_C(   922.41), SIMDE_FLOAT32_C(  -908.67) },
      { SIMDE_FLOAT32_C(   -84.49), SIMDE_FLOAT32_C(  1727.30), SIMDE_FLOAT32_C(   852.06), SIMDE_FLOAT32_C( -1568.50) } },
    { { SIMDE_FLOAT32_C(  -590.79), SIMDE_FLOAT32_C(  -852.37), SIMDE_FLOAT32_C(  -630.57), SIMDE_FLOAT32_C(  -823.06) },
      { SIMDE_FLOAT32_C(  -434.22), SIMDE_FLOAT32_C(  -548.87), SIMDE_FLOAT32_C(     5.97), SIMDE_FLOAT32_C(   648.80) },
      { SIMDE_FLOAT32_C( -1025.02), SIMDE_FLOAT32_C( -1401.25), SIMDE_FLOAT32_C(  -624.60), SIMDE_FLOAT32_C(  -174.26) } },
    { { SIMDE_FLOAT32_C(   840.24), SIMDE_FLOAT32_C(   454.04), SIMDE_FLOAT32_C(   148.23), SIMDE_FLOAT32_C(   278.66) },
      { SIMDE_FLOAT32_C(  -146.41), SIMDE_FLOAT32_C(   944.67), SIMDE_FLOAT32_C(  -421.85), SIMDE_FLOAT32_C(   473.97) },
      { SIMDE_FLOAT32_C(   693.83), SIMDE_FLOAT32_C(  1398.71), SIMDE_FLOAT32_C(  -273.62), SIMDE_FLOAT32_C(   752.63) } },
    { { SIMDE_FLOAT32_C(   407.16), SIMDE_FLOAT32_C(  -247.45), SIMDE_FLOAT32_C(  -487.29), SIMDE_FLOAT32_C(  -443.65) },
      { SIMDE_FLOAT32_C(   781.99), SIMDE_FLOAT32_C(   662.70), SIMDE_FLOAT32_C(  -677.65), SIMDE_FLOAT32_C(   638.04) },
      { SIMDE_FLOAT32_C(  1189.16), SIMDE_FLOAT32_C(   415.25), SIMDE_FLOAT32_C( -1164.94), SIMDE_FLOAT32_C(   194.39) } },
    { { SIMDE_FLOAT32_C(   650.19), SIMDE_FLOAT32_C(   252.00), SIMDE_FLOAT32_C(   978.21), SIMDE_FLOAT32_C(   709.65) },
      { SIMDE_FLOAT32_C(    -8.18), SIMDE_FLOAT32_C(   900.62), SIMDE_FLOAT32_C(   800.98), SIMDE_FLOAT32_C(   401.02) },
      { SIMDE_FLOAT32_C(   642.00), SIMDE_FLOAT32_C(  1152.62), SIMDE_FLOAT32_C(  1779.19), SIMDE_FLOAT32_C(  1110.67) } },
    { { SIMDE_FLOAT32_C(  -951.75), SIMDE_FLOAT32_C(  -829.59), SIMDE_FLOAT32_C(   577.96), SIMDE_FLOAT32_C(  -385.97) },
      { SIMDE_FLOAT32_C(  -378.46), SIMDE_FLOAT32_C(  -416.07), SIMDE_FLOAT32_C(  -737.17), SIMDE_FLOAT32_C(  -538.23) },
      { SIMDE_FLOAT32_C( -1330.21), SIMDE_FLOAT32_C( -1245.67), SIMDE_FLOAT32_C(  -159.21), SIMDE_FLOAT32_C(  -924.20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_add_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_add_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  807.64), SIMDE_FLOAT32_C(  618.52), SIMDE_FLOAT32_C( -396.84), SIMDE_FLOAT32_C( -297.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -471.66), SIMDE_FLOAT32_C(  713.91), SIMDE_FLOAT32_C(  549.43), SIMDE_FLOAT32_C( -169.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  807.64), SIMDE_FLOAT32_C(  618.52), SIMDE_FLOAT32_C( -396.84), SIMDE_FLOAT32_C( -466.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  544.68), SIMDE_FLOAT32_C(   42.73), SIMDE_FLOAT32_C( -460.22), SIMDE_FLOAT32_C( -292.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  187.56), SIMDE_FLOAT32_C( -798.97), SIMDE_FLOAT32_C(  272.51), SIMDE_FLOAT32_C(   51.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  544.68), SIMDE_FLOAT32_C(   42.73), SIMDE_FLOAT32_C( -460.22), SIMDE_FLOAT32_C( -241.09)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -110.27), SIMDE_FLOAT32_C(  680.50), SIMDE_FLOAT32_C(  761.66), SIMDE_FLOAT32_C(  277.48)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -67.06), SIMDE_FLOAT32_C(  934.00), SIMDE_FLOAT32_C(  502.27), SIMDE_FLOAT32_C(  358.64)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -110.27), SIMDE_FLOAT32_C(  680.50), SIMDE_FLOAT32_C(  761.66), SIMDE_FLOAT32_C(  636.12)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  434.09), SIMDE_FLOAT32_C(  948.98), SIMDE_FLOAT32_C( -323.81), SIMDE_FLOAT32_C( -338.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -221.66), SIMDE_FLOAT32_C( -861.25), SIMDE_FLOAT32_C(   78.84), SIMDE_FLOAT32_C( -873.32)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  434.09), SIMDE_FLOAT32_C(  948.98), SIMDE_FLOAT32_C( -323.81), SIMDE_FLOAT32_C(-1211.69)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -878.90), SIMDE_FLOAT32_C( -860.71), SIMDE_FLOAT32_C(  840.94), SIMDE_FLOAT32_C(   25.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  571.90), SIMDE_FLOAT32_C( -703.66), SIMDE_FLOAT32_C(  -53.73), SIMDE_FLOAT32_C( -560.77)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -878.90), SIMDE_FLOAT32_C( -860.71), SIMDE_FLOAT32_C(  840.94), SIMDE_FLOAT32_C( -535.28)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  496.95), SIMDE_FLOAT32_C( -413.78), SIMDE_FLOAT32_C(  -24.10), SIMDE_FLOAT32_C(  918.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -8.88), SIMDE_FLOAT32_C(  751.51), SIMDE_FLOAT32_C(  315.02), SIMDE_FLOAT32_C(  734.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  496.95), SIMDE_FLOAT32_C( -413.78), SIMDE_FLOAT32_C(  -24.10), SIMDE_FLOAT32_C( 1653.01)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  101.05), SIMDE_FLOAT32_C( -424.85), SIMDE_FLOAT32_C( -158.08), SIMDE_FLOAT32_C(  354.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  568.62), SIMDE_FLOAT32_C( -525.68), SIMDE_FLOAT32_C(   73.90), SIMDE_FLOAT32_C( -463.92)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  101.05), SIMDE_FLOAT32_C( -424.85), SIMDE_FLOAT32_C( -158.08), SIMDE_FLOAT32_C( -109.09)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -477.51), SIMDE_FLOAT32_C(  986.65), SIMDE_FLOAT32_C(  -44.77), SIMDE_FLOAT32_C(  993.26)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  591.07), SIMDE_FLOAT32_C(  806.35), SIMDE_FLOAT32_C( -137.78), SIMDE_FLOAT32_C( -899.14)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -477.51), SIMDE_FLOAT32_C(  986.65), SIMDE_FLOAT32_C(  -44.77), SIMDE_FLOAT32_C(   94.12)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_add_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  230308132), INT32_C( -227837326), INT32_C( 2068647778), INT32_C(  339280616)),
      simde_mm_set_epi32(INT32_C(-2005788472), INT32_C(  635603096), INT32_C( 1918425762), INT32_C( -674479342)),
      simde_mm_set_epi32(INT32_C(  137500672), INT32_C(  543295504), INT32_C( 1917323810), INT32_C(  336069120)) },
    { simde_mm_set_epi32(INT32_C( -291660154), INT32_C( 1180299090), INT32_C( 1302245871), INT32_C(-2053540867)),
      simde_mm_set_epi32(INT32_C(  -87778126), INT32_C( -288172017), INT32_C( 1641035711), INT32_C( -987206598)),
      simde_mm_set_epi32(INT32_C( -360407934), INT32_C( 1179699202), INT32_C( 1099968943), INT32_C(-2063048648)) },
    { simde_mm_set_epi32(INT32_C( 1329542878), INT32_C( 1207699188), INT32_C(   24647547), INT32_C( -417192016)),
      simde_mm_set_epi32(INT32_C(-1903170010), INT32_C( 1636014785), INT32_C(-1789298238), INT32_C(  431363012)),
      simde_mm_set_epi32(INT32_C(  235873798), INT32_C( 1098908352), INT32_C(   22548802), INT32_C(   19006336)) },
    { simde_mm_set_epi32(INT32_C( 1291921239), INT32_C(-2088318277), INT32_C(  293687175), INT32_C(  -70855120)),
      simde_mm_set_epi32(INT32_C( -181527647), INT32_C( 1885539289), INT32_C( 1200729803), INT32_C(-1998296563)),
      simde_mm_set_epi32(INT32_C( 1157628673), INT32_C(     133785), INT32_C(   25235075), INT32_C(-2000403968)) },
    { simde_mm_set_epi32(INT32_C( -352637975), INT32_C( 1914022535), INT32_C( -883801519), INT32_C(-2099443995)),
      simde_mm_set_epi32(INT32_C(   82894436), INT32_C(  345641451), INT32_C(-1766434082), INT32_C(  545403119)),
      simde_mm_set_epi32(INT32_C(   15731296), INT32_C(  269484163), INT32_C(-2112732592), INT32_C(    8388837)) },
    { simde_mm_set_epi32(INT32_C(-1731787377), INT32_C( -251709819), INT32_C(  707964452), INT32_C( 1634791391)),
      simde_mm_set_epi32(INT32_C( -198581371), INT32_C( 1425724652), INT32_C(  -85534714), INT32_C(  593903546)),
      simde_mm_set_epi32(INT32_C(-1878982267), INT32_C( 1358566532), INT32_C(  706906116), INT32_C(  559951770)) },
    { simde_mm_set_epi32(INT32_C( 1475548270), INT32_C(  196183104), INT32_C( 1788414168), INT32_C( -339387422)),
      simde_mm_set_epi32(INT32_C(  372209195), INT32_C( 2023049541), INT32_C(  537336467), INT32_C(-1542274771)),
      simde_mm_set_epi32(INT32_C(  371397674), INT32_C(  143720512), INT32_C(  536938640), INT32_C(-1610596064)) },
    { simde_mm_set_epi32(INT32_C( 1365641873), INT32_C(-1596735940), INT32_C( 1148782984), INT32_C( -513375328)),
      simde_mm_set_epi32(INT32_C(-1663652637), INT32_C(-1297596491), INT32_C(-1521550159), INT32_C(-2063966090)),
      simde_mm_set_epi32(INT32_C(  273025153), INT32_C(-1602208204), INT32_C(   71829632), INT32_C(-2141061088)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(simde_mm_and_ps(simde_mm_castsi128_ps(test_vec[i].a), simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(test_vec[i].r, r);
  }

  return 0;
}

static int
test_simde_mm_andnot_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1177189245), INT32_C( 1897888048), INT32_C(-1445410189), INT32_C(-2027773136)),
      simde_mm_set_epi32(INT32_C(-1799619754), INT32_C( 1146608002), INT32_C( -118138295), INT32_C( -396850997)),
      simde_mm_set_epi32(INT32_C(-1869512702), INT32_C(   71336066), INT32_C( 1344606216), INT32_C( 1750599883)) },
    { simde_mm_set_epi32(INT32_C(  207339929), INT32_C(-1653197317), INT32_C( 1742328793), INT32_C(-1943741545)),
      simde_mm_set_epi32(INT32_C( 1475927203), INT32_C(-1393438167), INT32_C( -244601726), INT32_C(-1116772072)),
      simde_mm_set_epi32(INT32_C( 1403001890), INT32_C(  545374720), INT32_C(-1876808702), INT32_C(  827006984)) },
    { simde_mm_set_epi32(INT32_C(  280787508), INT32_C( -476758383), INT32_C( -690500493), INT32_C( 1730225777)),
      simde_mm_set_epi32(INT32_C(  455229920), INT32_C(  254808493), INT32_C( -318322364), INT32_C( -744606195)),
      simde_mm_set_epi32(INT32_C(  184680896), INT32_C(  203424044), INT32_C(  687866116), INT32_C(-1868689396)) },
    { simde_mm_set_epi32(INT32_C( 1314224819), INT32_C( -883715485), INT32_C( 1830060352), INT32_C(  484123993)),
      simde_mm_set_epi32(INT32_C(-1600415403), INT32_C( 1247040590), INT32_C( -903138997), INT32_C( 1339483582)),
      simde_mm_set_epi32(INT32_C(-1601535676), INT32_C(     279564), INT32_C(-2111098869), INT32_C( 1124384934)) },
    { simde_mm_set_epi32(INT32_C(  491653802), INT32_C( 1332021673), INT32_C(-1558543881), INT32_C( 1668194718)),
      simde_mm_set_epi32(INT32_C( 1904424558), INT32_C(-1115627084), INT32_C(-1533509640), INT32_C( 1120379446)),
      simde_mm_set_epi32(INT32_C( 1619080260), INT32_C(-1333731308), INT32_C(   75529736), INT32_C(    8454688)) },
    { simde_mm_set_epi32(INT32_C( 1894428518), INT32_C( 1907474957), INT32_C( -645595730), INT32_C( -336066790)),
      simde_mm_set_epi32(INT32_C( -923650038), INT32_C(-1468609389), INT32_C(-1710432847), INT32_C(-1709785329)),
      simde_mm_set_epi32(INT32_C(-2012213240), INT32_C(-2008675182), INT32_C(   34078737), INT32_C(  268875781)) },
    { simde_mm_set_epi32(INT32_C(  194114005), INT32_C(  123455954), INT32_C(-1857684581), INT32_C( -281966329)),
      simde_mm_set_epi32(INT32_C( -794388211), INT32_C(-1374144398), INT32_C( 1808738256), INT32_C(   -8964047)),
      simde_mm_set_epi32(INT32_C( -802813944), INT32_C(-1476382688), INT32_C( 1787429952), INT32_C(  273035312)) },
    { simde_mm_set_epi32(INT32_C(-1545262354), INT32_C(  905989253), INT32_C( -414577725), INT32_C( 1431039599)),
      simde_mm_set_epi32(INT32_C( 1566256833), INT32_C(-1518668169), INT32_C(-1754223695), INT32_C( 1280260013)),
      simde_mm_set_epi32(INT32_C( 1545208833), INT32_C(-2122665358), INT32_C(  271622192), INT32_C(  134484352)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_andnot_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_not_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1059535058),  INT32_C(  2048808202),  INT32_C(   683407848),  INT32_C(  1249446257) },
      {  INT32_C(  1059535057), -INT32_C(  2048808203), -INT32_C(   683407849), -INT32_C(  1249446258) } },
    { { -INT32_C(  1990686684),  INT32_C(   961619650),  INT32_C(  1292910096),  INT32_C(  1808415805) },
      {  INT32_C(  1990686683), -INT32_C(   961619651), -INT32_C(  1292910097), -INT32_C(  1808415806) } },
    { {  INT32_C(   237740548), -INT32_C(   544650761), -INT32_C(  1274592190),  INT32_C(  1912504653) },
      { -INT32_C(   237740549),  INT32_C(   544650760),  INT32_C(  1274592189), -INT32_C(  1912504654) } },
    { { -INT32_C(   872786423), -INT32_C(  1929098372), -INT32_C(   958786423),  INT32_C(  1429382225) },
      {  INT32_C(   872786422),  INT32_C(  1929098371),  INT32_C(   958786422), -INT32_C(  1429382226) } },
    { {  INT32_C(  1029922118), -INT32_C(   383980377),  INT32_C(  2107450160), -INT32_C(  1376871260) },
      { -INT32_C(  1029922119),  INT32_C(   383980376), -INT32_C(  2107450161),  INT32_C(  1376871259) } },
    { {  INT32_C(  1870194930), -INT32_C(  1107526349), -INT32_C(   494676335), -INT32_C(  1070090886) },
      { -INT32_C(  1870194931),  INT32_C(  1107526348),  INT32_C(   494676334),  INT32_C(  1070090885) } },
    { { -INT32_C(  1157784813), -INT32_C(  1197270649), -INT32_C(   516603588), -INT32_C(   812768035) },
      {  INT32_C(  1157784812),  INT32_C(  1197270648),  INT32_C(   516603587),  INT32_C(   812768034) } },
    { {  INT32_C(  1077806860),  INT32_C(   368917124), -INT32_C(  1963425776),  INT32_C(  1229598518) },
      { -INT32_C(  1077806861), -INT32_C(   368917125),  INT32_C(  1963425775), -INT32_C(  1229598519) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_castps_si128(simde_x_mm_not_ps(simde_mm_castsi128_ps(a)));
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_mm_select_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   689.01), SIMDE_FLOAT32_C(   -11.14), SIMDE_FLOAT32_C(   334.10), SIMDE_FLOAT32_C(   442.90) },
      { SIMDE_FLOAT32_C(  -212.34), SIMDE_FLOAT32_C(  -259.33), SIMDE_FLOAT32_C(   883.69), SIMDE_FLOAT32_C(   488.72) },
      { SIMDE_FLOAT32_C(  -212.34), SIMDE_FLOAT32_C(  -259.33), SIMDE_FLOAT32_C(   334.10), SIMDE_FLOAT32_C(   442.90) } },
    { { SIMDE_FLOAT32_C(   -26.63), SIMDE_FLOAT32_C(  -842.74), SIMDE_FLOAT32_C(  -183.46), SIMDE_FLOAT32_C(  -506.27) },
      { SIMDE_FLOAT32_C(   624.94), SIMDE_FLOAT32_C(  -269.87), SIMDE_FLOAT32_C(  -399.29), SIMDE_FLOAT32_C(   452.04) },
      { SIMDE_FLOAT32_C(   -26.63), SIMDE_FLOAT32_C(  -842.74), SIMDE_FLOAT32_C(  -399.29), SIMDE_FLOAT32_C(  -506.27) } },
    { { SIMDE_FLOAT32_C(  -903.49), SIMDE_FLOAT32_C(  -810.21), SIMDE_FLOAT32_C(   457.27), SIMDE_FLOAT32_C(  -144.98) },
      { SIMDE_FLOAT32_C(  -658.80), SIMDE_FLOAT32_C(  -235.68), SIMDE_FLOAT32_C(   453.63), SIMDE_FLOAT32_C(  -772.14) },
      { SIMDE_FLOAT32_C(  -903.49), SIMDE_FLOAT32_C(  -810.21), SIMDE_FLOAT32_C(   453.63), SIMDE_FLOAT32_C(  -772.14) } },
    { { SIMDE_FLOAT32_C(   598.69), SIMDE_FLOAT32_C(   276.57), SIMDE_FLOAT32_C(   406.80), SIMDE_FLOAT32_C(   699.05) },
      { SIMDE_FLOAT32_C(  -976.76), SIMDE_FLOAT32_C(  -581.80), SIMDE_FLOAT32_C(    38.73), SIMDE_FLOAT32_C(   712.25) },
      { SIMDE_FLOAT32_C(  -976.76), SIMDE_FLOAT32_C(  -581.80), SIMDE_FLOAT32_C(    38.73), SIMDE_FLOAT32_C(   699.05) } },
    { { SIMDE_FLOAT32_C(   407.06), SIMDE_FLOAT32_C(  -627.17), SIMDE_FLOAT32_C(   155.16), SIMDE_FLOAT32_C(  -805.28) },
      { SIMDE_FLOAT32_C(   113.51), SIMDE_FLOAT32_C(    38.85), SIMDE_FLOAT32_C(   683.44), SIMDE_FLOAT32_C(  -913.12) },
      { SIMDE_FLOAT32_C(   113.51), SIMDE_FLOAT32_C(  -627.17), SIMDE_FLOAT32_C(   155.16), SIMDE_FLOAT32_C(  -913.12) } },
    { { SIMDE_FLOAT32_C(   196.11), SIMDE_FLOAT32_C(  -500.01), SIMDE_FLOAT32_C(  -419.39), SIMDE_FLOAT32_C(  -178.96) },
      { SIMDE_FLOAT32_C(   230.12), SIMDE_FLOAT32_C(   181.32), SIMDE_FLOAT32_C(  -726.92), SIMDE_FLOAT32_C(   326.63) },
      { SIMDE_FLOAT32_C(   196.11), SIMDE_FLOAT32_C(  -500.01), SIMDE_FLOAT32_C(  -726.92), SIMDE_FLOAT32_C(  -178.96) } },
    { { SIMDE_FLOAT32_C(   371.12), SIMDE_FLOAT32_C(   730.35), SIMDE_FLOAT32_C(  -818.35), SIMDE_FLOAT32_C(   712.32) },
      { SIMDE_FLOAT32_C(  -505.33), SIMDE_FLOAT32_C(   635.28), SIMDE_FLOAT32_C(   940.19), SIMDE_FLOAT32_C(  -906.64) },
      { SIMDE_FLOAT32_C(  -505.33), SIMDE_FLOAT32_C(   635.28), SIMDE_FLOAT32_C(  -818.35), SIMDE_FLOAT32_C(  -906.64) } },
    { { SIMDE_FLOAT32_C(   -88.15), SIMDE_FLOAT32_C(   346.99), SIMDE_FLOAT32_C(   792.41), SIMDE_FLOAT32_C(   -64.91) },
      { SIMDE_FLOAT32_C(   765.19), SIMDE_FLOAT32_C(  -168.85), SIMDE_FLOAT32_C(  -352.65), SIMDE_FLOAT32_C(   172.25) },
      { SIMDE_FLOAT32_C(   -88.15), SIMDE_FLOAT32_C(  -168.85), SIMDE_FLOAT32_C(  -352.65), SIMDE_FLOAT32_C(   -64.91) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_x_mm_select_ps(b, a, simde_mm_cmplt_ps(a, b));
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_avg_pu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu16(UINT16_C(  984), UINT16_C(30280), UINT16_C(42568), UINT16_C(40084)),
      simde_x_mm_set_pu16(UINT16_C(27500), UINT16_C(27572), UINT16_C(25285), UINT16_C(55528)),
      simde_x_mm_set_pu16(UINT16_C(14242), UINT16_C(28926), UINT16_C(33927), UINT16_C(47806)) },
    { simde_x_mm_set_pu16(UINT16_C(16799), UINT16_C(60083), UINT16_C(41622), UINT16_C(59771)),
      simde_x_mm_set_pu16(UINT16_C(44269), UINT16_C(15826), UINT16_C(52483), UINT16_C(45725)),
      simde_x_mm_set_pu16(UINT16_C(30534), UINT16_C(37955), UINT16_C(47053), UINT16_C(52748)) },
    { simde_x_mm_set_pu16(UINT16_C(41380), UINT16_C(64067), UINT16_C(33526), UINT16_C(10279)),
      simde_x_mm_set_pu16(UINT16_C(34327), UINT16_C(29328), UINT16_C( 8579), UINT16_C( 1111)),
      simde_x_mm_set_pu16(UINT16_C(37854), UINT16_C(46698), UINT16_C(21053), UINT16_C( 5695)) },
    { simde_x_mm_set_pu16(UINT16_C(18628), UINT16_C(48112), UINT16_C( 3068), UINT16_C(50432)),
      simde_x_mm_set_pu16(UINT16_C(  746), UINT16_C(22132), UINT16_C(21846), UINT16_C(48900)),
      simde_x_mm_set_pu16(UINT16_C( 9687), UINT16_C(35122), UINT16_C(12457), UINT16_C(49666)) },
    { simde_x_mm_set_pu16(UINT16_C(10018), UINT16_C( 4381), UINT16_C(59604), UINT16_C( 6897)),
      simde_x_mm_set_pu16(UINT16_C(44395), UINT16_C(45261), UINT16_C(45129), UINT16_C(12723)),
      simde_x_mm_set_pu16(UINT16_C(27207), UINT16_C(24821), UINT16_C(52367), UINT16_C( 9810)) },
    { simde_x_mm_set_pu16(UINT16_C(25446), UINT16_C(46949), UINT16_C(46494), UINT16_C(27481)),
      simde_x_mm_set_pu16(UINT16_C(54442), UINT16_C(34061), UINT16_C(46613), UINT16_C(44299)),
      simde_x_mm_set_pu16(UINT16_C(39944), UINT16_C(40505), UINT16_C(46554), UINT16_C(35890)) },
    { simde_x_mm_set_pu16(UINT16_C( 4562), UINT16_C(11032), UINT16_C(30725), UINT16_C(48961)),
      simde_x_mm_set_pu16(UINT16_C(11741), UINT16_C(52603), UINT16_C(11503), UINT16_C(62380)),
      simde_x_mm_set_pu16(UINT16_C( 8152), UINT16_C(31818), UINT16_C(21114), UINT16_C(55671)) },
    { simde_x_mm_set_pu16(UINT16_C(25787), UINT16_C(46963), UINT16_C( 3756), UINT16_C(41201)),
      simde_x_mm_set_pu16(UINT16_C(64587), UINT16_C(22291), UINT16_C( 7901), UINT16_C(11300)),
      simde_x_mm_set_pu16(UINT16_C(45187), UINT16_C(34627), UINT16_C( 5829), UINT16_C(26251)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_avg_pu16(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pavgw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu16(UINT16_C(  984), UINT16_C(30280), UINT16_C(42568), UINT16_C(40084)),
      simde_x_mm_set_pu16(UINT16_C(27500), UINT16_C(27572), UINT16_C(25285), UINT16_C(55528)),
      simde_x_mm_set_pu16(UINT16_C(14242), UINT16_C(28926), UINT16_C(33927), UINT16_C(47806)) },
    { simde_x_mm_set_pu16(UINT16_C(16799), UINT16_C(60083), UINT16_C(41622), UINT16_C(59771)),
      simde_x_mm_set_pu16(UINT16_C(44269), UINT16_C(15826), UINT16_C(52483), UINT16_C(45725)),
      simde_x_mm_set_pu16(UINT16_C(30534), UINT16_C(37955), UINT16_C(47053), UINT16_C(52748)) },
    { simde_x_mm_set_pu16(UINT16_C(41380), UINT16_C(64067), UINT16_C(33526), UINT16_C(10279)),
      simde_x_mm_set_pu16(UINT16_C(34327), UINT16_C(29328), UINT16_C( 8579), UINT16_C( 1111)),
      simde_x_mm_set_pu16(UINT16_C(37854), UINT16_C(46698), UINT16_C(21053), UINT16_C( 5695)) },
    { simde_x_mm_set_pu16(UINT16_C(18628), UINT16_C(48112), UINT16_C( 3068), UINT16_C(50432)),
      simde_x_mm_set_pu16(UINT16_C(  746), UINT16_C(22132), UINT16_C(21846), UINT16_C(48900)),
      simde_x_mm_set_pu16(UINT16_C( 9687), UINT16_C(35122), UINT16_C(12457), UINT16_C(49666)) },
    { simde_x_mm_set_pu16(UINT16_C(10018), UINT16_C( 4381), UINT16_C(59604), UINT16_C( 6897)),
      simde_x_mm_set_pu16(UINT16_C(44395), UINT16_C(45261), UINT16_C(45129), UINT16_C(12723)),
      simde_x_mm_set_pu16(UINT16_C(27207), UINT16_C(24821), UINT16_C(52367), UINT16_C( 9810)) },
    { simde_x_mm_set_pu16(UINT16_C(25446), UINT16_C(46949), UINT16_C(46494), UINT16_C(27481)),
      simde_x_mm_set_pu16(UINT16_C(54442), UINT16_C(34061), UINT16_C(46613), UINT16_C(44299)),
      simde_x_mm_set_pu16(UINT16_C(39944), UINT16_C(40505), UINT16_C(46554), UINT16_C(35890)) },
    { simde_x_mm_set_pu16(UINT16_C( 4562), UINT16_C(11032), UINT16_C(30725), UINT16_C(48961)),
      simde_x_mm_set_pu16(UINT16_C(11741), UINT16_C(52603), UINT16_C(11503), UINT16_C(62380)),
      simde_x_mm_set_pu16(UINT16_C( 8152), UINT16_C(31818), UINT16_C(21114), UINT16_C(55671)) },
    { simde_x_mm_set_pu16(UINT16_C(25787), UINT16_C(46963), UINT16_C( 3756), UINT16_C(41201)),
      simde_x_mm_set_pu16(UINT16_C(64587), UINT16_C(22291), UINT16_C( 7901), UINT16_C(11300)),
      simde_x_mm_set_pu16(UINT16_C(45187), UINT16_C(34627), UINT16_C( 5829), UINT16_C(26251)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_m_pavgw(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_avg_pu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(UINT8_C( 188), UINT8_C( 166), UINT8_C(  84), UINT8_C( 155),
                         UINT8_C( 198), UINT8_C( 220), UINT8_C( 172), UINT8_C( 150)),
      simde_x_mm_set_pu8(UINT8_C( 192), UINT8_C( 110), UINT8_C( 123), UINT8_C( 195),
                         UINT8_C( 186), UINT8_C( 160), UINT8_C(  76), UINT8_C(  17)),
      simde_x_mm_set_pu8(UINT8_C( 190), UINT8_C( 138), UINT8_C( 104), UINT8_C( 175),
                         UINT8_C( 192), UINT8_C( 190), UINT8_C( 124), UINT8_C(  84)) },
    { simde_x_mm_set_pu8(UINT8_C(  81), UINT8_C( 231), UINT8_C(  17), UINT8_C( 205),
                         UINT8_C( 110), UINT8_C( 170), UINT8_C(  68), UINT8_C( 253)),
      simde_x_mm_set_pu8(UINT8_C( 162), UINT8_C( 211), UINT8_C( 109), UINT8_C( 219),
                         UINT8_C(  84), UINT8_C(  95), UINT8_C( 217), UINT8_C( 146)),
      simde_x_mm_set_pu8(UINT8_C( 122), UINT8_C( 221), UINT8_C(  63), UINT8_C( 212),
                         UINT8_C(  97), UINT8_C( 133), UINT8_C( 143), UINT8_C( 200)) },
    { simde_x_mm_set_pu8(UINT8_C(  65), UINT8_C( 248), UINT8_C( 129), UINT8_C( 144),
                         UINT8_C(   4), UINT8_C(  42), UINT8_C( 191), UINT8_C( 186)),
      simde_x_mm_set_pu8(UINT8_C( 181), UINT8_C( 198), UINT8_C(  22), UINT8_C(  17),
                         UINT8_C( 197), UINT8_C( 123), UINT8_C( 216), UINT8_C( 195)),
      simde_x_mm_set_pu8(UINT8_C( 123), UINT8_C( 223), UINT8_C(  76), UINT8_C(  81),
                         UINT8_C( 101), UINT8_C(  83), UINT8_C( 204), UINT8_C( 191)) },
    { simde_x_mm_set_pu8(UINT8_C( 149), UINT8_C( 191), UINT8_C( 152), UINT8_C( 239),
                         UINT8_C( 227), UINT8_C( 104), UINT8_C( 122), UINT8_C( 140)),
      simde_x_mm_set_pu8(UINT8_C(   5), UINT8_C(  95), UINT8_C( 201), UINT8_C(  16),
                         UINT8_C(  30), UINT8_C( 151), UINT8_C( 230), UINT8_C( 228)),
      simde_x_mm_set_pu8(UINT8_C(  77), UINT8_C( 143), UINT8_C( 177), UINT8_C( 128),
                         UINT8_C( 129), UINT8_C( 128), UINT8_C( 176), UINT8_C( 184)) },
    { simde_x_mm_set_pu8(UINT8_C(  99), UINT8_C( 248), UINT8_C( 192), UINT8_C(  96),
                         UINT8_C(   9), UINT8_C( 180), UINT8_C( 230), UINT8_C(  75)),
      simde_x_mm_set_pu8(UINT8_C( 205), UINT8_C( 207), UINT8_C( 224), UINT8_C( 197),
                         UINT8_C( 157), UINT8_C(  96), UINT8_C( 165), UINT8_C(  63)),
      simde_x_mm_set_pu8(UINT8_C( 152), UINT8_C( 228), UINT8_C( 208), UINT8_C( 147),
                         UINT8_C(  83), UINT8_C( 138), UINT8_C( 198), UINT8_C(  69)) },
    { simde_x_mm_set_pu8(UINT8_C( 207), UINT8_C(  50), UINT8_C(  87), UINT8_C( 142),
                         UINT8_C( 106), UINT8_C( 190), UINT8_C(  31), UINT8_C( 212)),
      simde_x_mm_set_pu8(UINT8_C( 236), UINT8_C(  29), UINT8_C(  22), UINT8_C( 123),
                         UINT8_C( 184), UINT8_C( 176), UINT8_C( 133), UINT8_C(  58)),
      simde_x_mm_set_pu8(UINT8_C( 222), UINT8_C(  40), UINT8_C(  55), UINT8_C( 133),
                         UINT8_C( 145), UINT8_C( 183), UINT8_C(  82), UINT8_C( 135)) },
    { simde_x_mm_set_pu8(UINT8_C(  31), UINT8_C( 172), UINT8_C( 185), UINT8_C( 135),
                         UINT8_C( 147), UINT8_C( 121), UINT8_C(  19), UINT8_C( 169)),
      simde_x_mm_set_pu8(UINT8_C(  25), UINT8_C( 222), UINT8_C( 106), UINT8_C(   4),
                         UINT8_C( 238), UINT8_C(  72), UINT8_C( 216), UINT8_C(  75)),
      simde_x_mm_set_pu8(UINT8_C(  28), UINT8_C( 197), UINT8_C( 146), UINT8_C(  70),
                         UINT8_C( 193), UINT8_C(  97), UINT8_C( 118), UINT8_C( 122)) },
    { simde_x_mm_set_pu8(UINT8_C( 126), UINT8_C( 117), UINT8_C(  85), UINT8_C(  61),
                         UINT8_C(   8), UINT8_C( 204), UINT8_C( 178), UINT8_C(  71)),
      simde_x_mm_set_pu8(UINT8_C( 216), UINT8_C( 115), UINT8_C( 127), UINT8_C(  61),
                         UINT8_C(  84), UINT8_C(  84), UINT8_C(  64), UINT8_C(  51)),
      simde_x_mm_set_pu8(UINT8_C( 171), UINT8_C( 116), UINT8_C( 106), UINT8_C(  61),
                         UINT8_C(  46), UINT8_C( 144), UINT8_C( 121), UINT8_C(  61)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_avg_pu8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_test_x86_assert_equal_u8x8(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pavgb(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(UINT8_C( 188), UINT8_C( 166), UINT8_C(  84), UINT8_C( 155),
                         UINT8_C( 198), UINT8_C( 220), UINT8_C( 172), UINT8_C( 150)),
      simde_x_mm_set_pu8(UINT8_C( 192), UINT8_C( 110), UINT8_C( 123), UINT8_C( 195),
                         UINT8_C( 186), UINT8_C( 160), UINT8_C(  76), UINT8_C(  17)),
      simde_x_mm_set_pu8(UINT8_C( 190), UINT8_C( 138), UINT8_C( 104), UINT8_C( 175),
                         UINT8_C( 192), UINT8_C( 190), UINT8_C( 124), UINT8_C(  84)) },
    { simde_x_mm_set_pu8(UINT8_C(  81), UINT8_C( 231), UINT8_C(  17), UINT8_C( 205),
                         UINT8_C( 110), UINT8_C( 170), UINT8_C(  68), UINT8_C( 253)),
      simde_x_mm_set_pu8(UINT8_C( 162), UINT8_C( 211), UINT8_C( 109), UINT8_C( 219),
                         UINT8_C(  84), UINT8_C(  95), UINT8_C( 217), UINT8_C( 146)),
      simde_x_mm_set_pu8(UINT8_C( 122), UINT8_C( 221), UINT8_C(  63), UINT8_C( 212),
                         UINT8_C(  97), UINT8_C( 133), UINT8_C( 143), UINT8_C( 200)) },
    { simde_x_mm_set_pu8(UINT8_C(  65), UINT8_C( 248), UINT8_C( 129), UINT8_C( 144),
                         UINT8_C(   4), UINT8_C(  42), UINT8_C( 191), UINT8_C( 186)),
      simde_x_mm_set_pu8(UINT8_C( 181), UINT8_C( 198), UINT8_C(  22), UINT8_C(  17),
                         UINT8_C( 197), UINT8_C( 123), UINT8_C( 216), UINT8_C( 195)),
      simde_x_mm_set_pu8(UINT8_C( 123), UINT8_C( 223), UINT8_C(  76), UINT8_C(  81),
                         UINT8_C( 101), UINT8_C(  83), UINT8_C( 204), UINT8_C( 191)) },
    { simde_x_mm_set_pu8(UINT8_C( 149), UINT8_C( 191), UINT8_C( 152), UINT8_C( 239),
                         UINT8_C( 227), UINT8_C( 104), UINT8_C( 122), UINT8_C( 140)),
      simde_x_mm_set_pu8(UINT8_C(   5), UINT8_C(  95), UINT8_C( 201), UINT8_C(  16),
                         UINT8_C(  30), UINT8_C( 151), UINT8_C( 230), UINT8_C( 228)),
      simde_x_mm_set_pu8(UINT8_C(  77), UINT8_C( 143), UINT8_C( 177), UINT8_C( 128),
                         UINT8_C( 129), UINT8_C( 128), UINT8_C( 176), UINT8_C( 184)) },
    { simde_x_mm_set_pu8(UINT8_C(  99), UINT8_C( 248), UINT8_C( 192), UINT8_C(  96),
                         UINT8_C(   9), UINT8_C( 180), UINT8_C( 230), UINT8_C(  75)),
      simde_x_mm_set_pu8(UINT8_C( 205), UINT8_C( 207), UINT8_C( 224), UINT8_C( 197),
                         UINT8_C( 157), UINT8_C(  96), UINT8_C( 165), UINT8_C(  63)),
      simde_x_mm_set_pu8(UINT8_C( 152), UINT8_C( 228), UINT8_C( 208), UINT8_C( 147),
                         UINT8_C(  83), UINT8_C( 138), UINT8_C( 198), UINT8_C(  69)) },
    { simde_x_mm_set_pu8(UINT8_C( 207), UINT8_C(  50), UINT8_C(  87), UINT8_C( 142),
                         UINT8_C( 106), UINT8_C( 190), UINT8_C(  31), UINT8_C( 212)),
      simde_x_mm_set_pu8(UINT8_C( 236), UINT8_C(  29), UINT8_C(  22), UINT8_C( 123),
                         UINT8_C( 184), UINT8_C( 176), UINT8_C( 133), UINT8_C(  58)),
      simde_x_mm_set_pu8(UINT8_C( 222), UINT8_C(  40), UINT8_C(  55), UINT8_C( 133),
                         UINT8_C( 145), UINT8_C( 183), UINT8_C(  82), UINT8_C( 135)) },
    { simde_x_mm_set_pu8(UINT8_C(  31), UINT8_C( 172), UINT8_C( 185), UINT8_C( 135),
                         UINT8_C( 147), UINT8_C( 121), UINT8_C(  19), UINT8_C( 169)),
      simde_x_mm_set_pu8(UINT8_C(  25), UINT8_C( 222), UINT8_C( 106), UINT8_C(   4),
                         UINT8_C( 238), UINT8_C(  72), UINT8_C( 216), UINT8_C(  75)),
      simde_x_mm_set_pu8(UINT8_C(  28), UINT8_C( 197), UINT8_C( 146), UINT8_C(  70),
                         UINT8_C( 193), UINT8_C(  97), UINT8_C( 118), UINT8_C( 122)) },
    { simde_x_mm_set_pu8(UINT8_C( 126), UINT8_C( 117), UINT8_C(  85), UINT8_C(  61),
                         UINT8_C(   8), UINT8_C( 204), UINT8_C( 178), UINT8_C(  71)),
      simde_x_mm_set_pu8(UINT8_C( 216), UINT8_C( 115), UINT8_C( 127), UINT8_C(  61),
                         UINT8_C(  84), UINT8_C(  84), UINT8_C(  64), UINT8_C(  51)),
      simde_x_mm_set_pu8(UINT8_C( 171), UINT8_C( 116), UINT8_C( 106), UINT8_C(  61),
                         UINT8_C(  46), UINT8_C( 144), UINT8_C( 121), UINT8_C(  61)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_m_pavgb(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_test_x86_assert_equal_u8x8(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_cmpeq_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1552099433), INT32_C(-1589398258), INT32_C(  -34553673), INT32_C(-1178885563)),
      simde_mm_set_epi32(INT32_C( 1552099433), INT32_C( 2025844073), INT32_C(  -34553673), INT32_C(-1178885563)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1766041281), INT32_C(-1662168132), INT32_C(  997624458), INT32_C(  980393671)),
      simde_mm_set_epi32(INT32_C( 1122334686), INT32_C(-1662168132), INT32_C( 1502327165), INT32_C( 1228800964)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1053856039), INT32_C(  189518021), INT32_C(-2093780846), INT32_C(  717465502)),
      simde_mm_set_epi32(INT32_C( 1053856039), INT32_C(  189518021), INT32_C( -730260217), INT32_C( 1570531267)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1211703701), INT32_C( 1792645956), INT32_C(  451470260), INT32_C(   72883505)),
      simde_mm_set_epi32(INT32_C(-1211703701), INT32_C( -873756537), INT32_C( 1700529530), INT32_C(   72883505)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1123941451), INT32_C(-1499396317), INT32_C( -496690637), INT32_C(  857633319)),
      simde_mm_set_epi32(INT32_C(-1095910111), INT32_C(-1499396317), INT32_C(  -59751101), INT32_C(  -47922840)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1786351786), INT32_C(  618588335), INT32_C(-1648947504), INT32_C(-1160443929)),
      simde_mm_set_epi32(INT32_C( 1923711258), INT32_C(  775175059), INT32_C(-1633817987), INT32_C(  778628411)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 2132068337), INT32_C(  303020289), INT32_C(-1544950892), INT32_C(-2063582009)),
      simde_mm_set_epi32(INT32_C( 2132068337), INT32_C(  628767021), INT32_C(-1152607496), INT32_C(-1526726995)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 2000861670), INT32_C(-1296714344), INT32_C(  682422961), INT32_C( -767128199)),
      simde_mm_set_epi32(INT32_C( 2000861670), INT32_C(-1296714344), INT32_C(  682422961), INT32_C(-1784377677)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpeq_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  975888251), INT32_C( 1037275787), INT32_C( -206927716), INT32_C( 1719930130)),
      simde_mm_set_epi32(INT32_C(-1683768293), INT32_C( 1037275787), INT32_C( -206927716), INT32_C( 1719930130)),
      simde_mm_set_epi32(INT32_C(  975888251), INT32_C( 1037275787), INT32_C( -206927716), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1524488806), INT32_C( -573553543), INT32_C(   42112282), INT32_C(  112731860)),
      simde_mm_set_epi32(INT32_C( 1557664843), INT32_C(  -39848297), INT32_C(   42112282), INT32_C(  112731860)),
      simde_mm_set_epi32(INT32_C(-1524488806), INT32_C( -573553543), INT32_C(   42112282), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1378184574), INT32_C(-1915421318), INT32_C( -131047892), INT32_C( -798352758)),
      simde_mm_set_epi32(INT32_C( 1378184574), INT32_C(-1967398858), INT32_C( -131047892), INT32_C(-1869734720)),
      simde_mm_set_epi32(INT32_C( 1378184574), INT32_C(-1915421318), INT32_C( -131047892), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1981544552), INT32_C(  329373642), INT32_C( -104014353), INT32_C(-2092043281)),
      simde_mm_set_epi32(INT32_C( 2125102991), INT32_C(  978475086), INT32_C( 1426268882), INT32_C( -436875296)),
      simde_mm_set_epi32(INT32_C( 1981544552), INT32_C(  329373642), INT32_C( -104014353), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  600612499), INT32_C(-1490414099), INT32_C(-2094604589), INT32_C(  126748780)),
      simde_mm_set_epi32(INT32_C(  600612499), INT32_C(-1490414099), INT32_C(-2094604589), INT32_C(  126748780)),
      simde_mm_set_epi32(INT32_C(  600612499), INT32_C(-1490414099), INT32_C(-2094604589), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(   60156341), INT32_C( 1267841603), INT32_C(-1347475320), INT32_C(-1548408923)),
      simde_mm_set_epi32(INT32_C(   60156341), INT32_C( -387226227), INT32_C(  -76120938), INT32_C(-1548408923)),
      simde_mm_set_epi32(INT32_C(   60156341), INT32_C( 1267841603), INT32_C(-1347475320), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-2114878036), INT32_C(-1987807687), INT32_C( 1314812087), INT32_C( -402159797)),
      simde_mm_set_epi32(INT32_C(-2114878036), INT32_C(-1987807687), INT32_C( -580165908), INT32_C( -311736955)),
      simde_mm_set_epi32(INT32_C(-2114878036), INT32_C(-1987807687), INT32_C( 1314812087), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1498340262), INT32_C(  467089732), INT32_C( -352096361), INT32_C( -125007519)),
      simde_mm_set_epi32(INT32_C(-1919145018), INT32_C(  854922987), INT32_C(  767022324), INT32_C( -125007519)),
      simde_mm_set_epi32(INT32_C( 1498340262), INT32_C(  467089732), INT32_C( -352096361), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpeq_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpge_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-2117681573), INT32_C( 1744824135), INT32_C(-1062100051), INT32_C( -758867207)),
      simde_mm_set_epi32(INT32_C(  447802409), INT32_C(-1805122446), INT32_C(-1062100051), INT32_C(  180201744)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  501801973), INT32_C( -437596087), INT32_C(   96926344), INT32_C( 1479688678)),
      simde_mm_set_epi32(INT32_C( 2057298249), INT32_C( -899804986), INT32_C( -711059659), INT32_C(  886835596)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  927826628), INT32_C(-1620708712), INT32_C(-2141396655), INT32_C(-1921942403)),
      simde_mm_set_epi32(INT32_C( -440885672), INT32_C(-1620708712), INT32_C( 2101230656), INT32_C(-1921942403)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1545828562), INT32_C( -731809091), INT32_C(-1137290929), INT32_C(  -77584541)),
      simde_mm_set_epi32(INT32_C( 1117766142), INT32_C(-2055588954), INT32_C(-1137290929), INT32_C(-1359346144)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1420198491), INT32_C( 1600056611), INT32_C( -347234499), INT32_C( 1584151154)),
      simde_mm_set_epi32(INT32_C(-1420198491), INT32_C( 1600056611), INT32_C( 1047775179), INT32_C(  673458453)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -594070283), INT32_C( -270758299), INT32_C(  185236064), INT32_C(  607788733)),
      simde_mm_set_epi32(INT32_C( -310503835), INT32_C( 1875198957), INT32_C(  185236064), INT32_C(  290211410)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  275701977), INT32_C(-1310829701), INT32_C(-1932286124), INT32_C(  124706827)),
      simde_mm_set_epi32(INT32_C(  275701977), INT32_C( 2044408096), INT32_C(  371148478), INT32_C( 1787635053)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  335124996), INT32_C(-2113521475), INT32_C(  960990723), INT32_C( -969567969)),
      simde_mm_set_epi32(INT32_C(-1587045050), INT32_C(-2113521475), INT32_C( -168625313), INT32_C( 1040258918)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpge_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpge_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1012979392), INT32_C(-1453212125), INT32_C(  815083508), INT32_C( 1351772430)),
      simde_mm_set_epi32(INT32_C( 1169877184), INT32_C(-1037467546), INT32_C( 1421795564), INT32_C(  905862977)),
      simde_mm_set_epi32(INT32_C(-1012979392), INT32_C(-1453212125), INT32_C(  815083508), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -324333154), INT32_C( 1314427040), INT32_C( -483618994), INT32_C( 1502460142)),
      simde_mm_set_epi32(INT32_C( -202797776), INT32_C(   94174629), INT32_C(  926181510), INT32_C( 1502460142)),
      simde_mm_set_epi32(INT32_C( -324333154), INT32_C( 1314427040), INT32_C( -483618994), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  467112718), INT32_C(-1304161813), INT32_C(-1064952269), INT32_C(  631164600)),
      simde_mm_set_epi32(INT32_C(  467112718), INT32_C(-1304161813), INT32_C(  200476027), INT32_C( 1663275417)),
      simde_mm_set_epi32(INT32_C(  467112718), INT32_C(-1304161813), INT32_C(-1064952269), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -347696391), INT32_C(  148936949), INT32_C( 1398613274), INT32_C( 1250010386)),
      simde_mm_set_epi32(INT32_C( -347696391), INT32_C(  148936949), INT32_C( 1202050063), INT32_C( 1250010386)),
      simde_mm_set_epi32(INT32_C( -347696391), INT32_C(  148936949), INT32_C( 1398613274), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1684279233), INT32_C(-2118983098), INT32_C(  160153353), INT32_C( -113728462)),
      simde_mm_set_epi32(INT32_C(-1684279233), INT32_C(-2118983098), INT32_C(  160153353), INT32_C( 1908868579)),
      simde_mm_set_epi32(INT32_C(-1684279233), INT32_C(-2118983098), INT32_C(  160153353), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1844989631), INT32_C( 1725503201), INT32_C(  822658308), INT32_C( -958604095)),
      simde_mm_set_epi32(INT32_C( 1098943561), INT32_C( 1725503201), INT32_C( -755708322), INT32_C( -958604095)),
      simde_mm_set_epi32(INT32_C(-1844989631), INT32_C( 1725503201), INT32_C(  822658308), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  375717031), INT32_C( -882753921), INT32_C( 1130912475), INT32_C( 2045186948)),
      simde_mm_set_epi32(INT32_C(  375717031), INT32_C( -882753921), INT32_C( -800937725), INT32_C( 2045186948)),
      simde_mm_set_epi32(INT32_C(  375717031), INT32_C( -882753921), INT32_C( 1130912475), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  602871888), INT32_C(  470458702), INT32_C(-1169608009), INT32_C( -214741679)),
      simde_mm_set_epi32(INT32_C(  602871888), INT32_C( -493719927), INT32_C(-1169608009), INT32_C( 2044474163)),
      simde_mm_set_epi32(INT32_C(  602871888), INT32_C(  470458702), INT32_C(-1169608009), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpge_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1960669177), INT32_C(-1800221672), INT32_C( -201138064), INT32_C( 1882570539)),
      simde_mm_set_epi32(INT32_C( 1960669177), INT32_C( 1636503467), INT32_C(  379370104), INT32_C( 1549588428)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1497868169), INT32_C( 1587819932), INT32_C(   11597982), INT32_C(  367113544)),
      simde_mm_set_epi32(INT32_C( 1497868169), INT32_C( 1587819932), INT32_C(   11597982), INT32_C(-2087685948)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -420177326), INT32_C( 1458568188), INT32_C( 1173908260), INT32_C(-1290366123)),
      simde_mm_set_epi32(INT32_C(-1452540627), INT32_C(-1072533390), INT32_C( 1463315378), INT32_C(  944710330)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1987295390), INT32_C( -783471208), INT32_C( 1614612869), INT32_C(  941455851)),
      simde_mm_set_epi32(INT32_C(  776864087), INT32_C( -275776600), INT32_C( 1614612869), INT32_C(  941455851)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -802004143), INT32_C(-2136990592), INT32_C( 1617943513), INT32_C( 1268400008)),
      simde_mm_set_epi32(INT32_C( -802004143), INT32_C(-2136990592), INT32_C( 1458980297), INT32_C( 1268400008)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1974256896), INT32_C( 1350058685), INT32_C(-1649890899), INT32_C(-2052839662)),
      simde_mm_set_epi32(INT32_C(-1974256896), INT32_C( 1388826354), INT32_C(-2033282795), INT32_C(-2052839662)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(   42472091), INT32_C( 2006715626), INT32_C(   18778978), INT32_C( 1523053306)),
      simde_mm_set_epi32(INT32_C(   42472091), INT32_C(-1636528069), INT32_C(   18778978), INT32_C(  737106093)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1244568026), INT32_C(-1381724018), INT32_C( -492895509), INT32_C( -783840348)),
      simde_mm_set_epi32(INT32_C(  567191695), INT32_C( -729265936), INT32_C( -492895509), INT32_C( -783840348)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpgt_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1869056804), INT32_C(-1753986411), INT32_C( -585204320), INT32_C(-1910961055)),
      simde_mm_set_epi32(INT32_C( 1869056804), INT32_C(-1102496477), INT32_C(  -20892909), INT32_C(  -63499356)),
      simde_mm_set_epi32(INT32_C( 1869056804), INT32_C(-1753986411), INT32_C( -585204320), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  528987825), INT32_C( -236154839), INT32_C( 1847822202), INT32_C( 1073580784)),
      simde_mm_set_epi32(INT32_C(  301802145), INT32_C( -236154839), INT32_C( 1847822202), INT32_C( 1073580784)),
      simde_mm_set_epi32(INT32_C(  528987825), INT32_C( -236154839), INT32_C( 1847822202), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -453663293), INT32_C(  374222760), INT32_C(  660253560), INT32_C(-1094975358)),
      simde_mm_set_epi32(INT32_C(  922033710), INT32_C(-1385400175), INT32_C(  281683050), INT32_C(-1094975358)),
      simde_mm_set_epi32(INT32_C( -453663293), INT32_C(  374222760), INT32_C(  660253560), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(   56611761), INT32_C( -294357766), INT32_C(  221827642), INT32_C(-1086961889)),
      simde_mm_set_epi32(INT32_C(-2059704292), INT32_C( -294357766), INT32_C(-1642431615), INT32_C(-1453505032)),
      simde_mm_set_epi32(INT32_C(   56611761), INT32_C( -294357766), INT32_C(  221827642), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -677567670), INT32_C(-1065179289), INT32_C( 1230662601), INT32_C( 1022052917)),
      simde_mm_set_epi32(INT32_C( -677567670), INT32_C(  692939036), INT32_C( 1108906800), INT32_C(-2115601689)),
      simde_mm_set_epi32(INT32_C( -677567670), INT32_C(-1065179289), INT32_C( 1230662601), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  658893489), INT32_C( -592874075), INT32_C(   90769968), INT32_C( 1780967347)),
      simde_mm_set_epi32(INT32_C( -745618317), INT32_C( -592874075), INT32_C(   90769968), INT32_C( 1901683344)),
      simde_mm_set_epi32(INT32_C(  658893489), INT32_C( -592874075), INT32_C(   90769968), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  596908542), INT32_C( -725878217), INT32_C(   43862031), INT32_C(  120397305)),
      simde_mm_set_epi32(INT32_C( 1105546030), INT32_C( -725878217), INT32_C(   43862031), INT32_C(-1679076026)),
      simde_mm_set_epi32(INT32_C(  596908542), INT32_C( -725878217), INT32_C(   43862031), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-2095835916), INT32_C( 2093817071), INT32_C(-1700253832), INT32_C( 1213385208)),
      simde_mm_set_epi32(INT32_C(-1122300334), INT32_C( 1314746582), INT32_C(-1700253832), INT32_C( 1213385208)),
      simde_mm_set_epi32(INT32_C(-2095835916), INT32_C( 2093817071), INT32_C(-1700253832), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpgt_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmple_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1214095902), INT32_C(  -66909402), INT32_C( -553169346), INT32_C( 1655881585)),
      simde_mm_set_epi32(INT32_C( 1411879436), INT32_C( 1800787365), INT32_C( -553169346), INT32_C( -934991244)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  935354519), INT32_C( -241132058), INT32_C( 1879436355), INT32_C( -995448835)),
      simde_mm_set_epi32(INT32_C(  935354519), INT32_C( -241132058), INT32_C(  778854493), INT32_C( 1939053113)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-2000937674), INT32_C(  926691548), INT32_C( 1566199240), INT32_C(-2071387770)),
      simde_mm_set_epi32(INT32_C(  -33682990), INT32_C(  926691548), INT32_C( -862341564), INT32_C(-2071387770)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1400009830), INT32_C( 2074443710), INT32_C(-1988154474), INT32_C(-1285973673)),
      simde_mm_set_epi32(INT32_C( 1431717555), INT32_C( 2074443710), INT32_C( -236063022), INT32_C(-1285973673)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -969028248), INT32_C( 1961285965), INT32_C( 2034451315), INT32_C(  982408470)),
      simde_mm_set_epi32(INT32_C( -969028248), INT32_C(  737591133), INT32_C( 2034451315), INT32_C( 1972820242)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  689515799), INT32_C( 1226329239), INT32_C( -601248060), INT32_C( -246025007)),
      simde_mm_set_epi32(INT32_C(  689515799), INT32_C( 1567083199), INT32_C( -315367605), INT32_C(  895186883)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1299136382), INT32_C(   66630204), INT32_C(    5361190), INT32_C( 1189577124)),
      simde_mm_set_epi32(INT32_C(-1645066809), INT32_C(   66630204), INT32_C( -985693313), INT32_C( 1189577124)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -861186400), INT32_C(-1832454806), INT32_C(  -43975819), INT32_C(   67490279)),
      simde_mm_set_epi32(INT32_C( -259498670), INT32_C(-1523721259), INT32_C(  -43975819), INT32_C(  292054476)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmple_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmple_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  577834131), INT32_C(  125783617), INT32_C(-1878005293), INT32_C(-2039280607)),
      simde_mm_set_epi32(INT32_C(  577834131), INT32_C(  125783617), INT32_C(-1878005293), INT32_C( 2032820947)),
      simde_mm_set_epi32(INT32_C(  577834131), INT32_C(  125783617), INT32_C(-1878005293), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1229544726), INT32_C(-1899015779), INT32_C( 1583449198), INT32_C(-1177374746)),
      simde_mm_set_epi32(INT32_C(  -10568623), INT32_C( 2105302200), INT32_C( 1583449198), INT32_C(  113127759)),
      simde_mm_set_epi32(INT32_C(-1229544726), INT32_C(-1899015779), INT32_C( 1583449198), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1403164448), INT32_C(-1420499873), INT32_C(-1053362140), INT32_C(-1673889705)),
      simde_mm_set_epi32(INT32_C(-1403164448), INT32_C(-1420499873), INT32_C(-1053362140), INT32_C(-1409095555)),
      simde_mm_set_epi32(INT32_C(-1403164448), INT32_C(-1420499873), INT32_C(-1053362140), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1464154482), INT32_C( -512313078), INT32_C(-1671698744), INT32_C(-1338032665)),
      simde_mm_set_epi32(INT32_C(-1464154482), INT32_C(  350929661), INT32_C(-1095578259), INT32_C( -137690799)),
      simde_mm_set_epi32(INT32_C(-1464154482), INT32_C( -512313078), INT32_C(-1671698744), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -876240227), INT32_C(  638830515), INT32_C( 1194125228), INT32_C( 1201799459)),
      simde_mm_set_epi32(INT32_C(  370717124), INT32_C(  575915100), INT32_C(  323333140), INT32_C(-1701764718)),
      simde_mm_set_epi32(INT32_C( -876240227), INT32_C(  638830515), INT32_C( 1194125228), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1870075868), INT32_C( -538093027), INT32_C( 1796667049), INT32_C(  944394189)),
      simde_mm_set_epi32(INT32_C( 1870075868), INT32_C(-1718307451), INT32_C( 1796667049), INT32_C(  944394189)),
      simde_mm_set_epi32(INT32_C( 1870075868), INT32_C( -538093027), INT32_C( 1796667049), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1976935464), INT32_C(-1126118718), INT32_C(  992307422), INT32_C( 1933654831)),
      simde_mm_set_epi32(INT32_C(  980618308), INT32_C(-1126118718), INT32_C(  992307422), INT32_C( 1933654831)),
      simde_mm_set_epi32(INT32_C( 1976935464), INT32_C(-1126118718), INT32_C(  992307422), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  957949500), INT32_C(  241498261), INT32_C(-2057282883), INT32_C(  160259126)),
      simde_mm_set_epi32(INT32_C(  945346495), INT32_C(  241498261), INT32_C(-2057282883), INT32_C(  160259126)),
      simde_mm_set_epi32(INT32_C(  957949500), INT32_C(  241498261), INT32_C(-2057282883), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmple_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -864121404), INT32_C(  820258235), INT32_C(-1696337178), INT32_C(-1482432629)),
      simde_mm_set_epi32(INT32_C( -864121404), INT32_C(  820258235), INT32_C(-1696337178), INT32_C(-1482432629)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1757897801), INT32_C(-1139623844), INT32_C(  396231785), INT32_C( 1433495183)),
      simde_mm_set_epi32(INT32_C(-1757897801), INT32_C( 1640940421), INT32_C(  923198702), INT32_C( 1433495183)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1329593143), INT32_C( 1809390238), INT32_C( 1760230809), INT32_C( -549294944)),
      simde_mm_set_epi32(INT32_C( 1011105980), INT32_C( 1809390238), INT32_C( 1760230809), INT32_C( -549294944)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1918857994), INT32_C(-1864521589), INT32_C(  155537477), INT32_C( 1666430711)),
      simde_mm_set_epi32(INT32_C(-1918857994), INT32_C(-1864521589), INT32_C(  155537477), INT32_C(  735305870)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  197471455), INT32_C(   -1555852), INT32_C(-1752379132), INT32_C(  240472065)),
      simde_mm_set_epi32(INT32_C(  579332444), INT32_C(   -1555852), INT32_C(-1752379132), INT32_C(  240472065)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1086999122), INT32_C( 1309092278), INT32_C(  365604292), INT32_C(-1138767432)),
      simde_mm_set_epi32(INT32_C( 1086999122), INT32_C( -886110099), INT32_C(  219975772), INT32_C(-1138767432)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1954260003), INT32_C( 1696592095), INT32_C( 2078494375), INT32_C(  650856359)),
      simde_mm_set_epi32(INT32_C( 1954260003), INT32_C( 2098551061), INT32_C( 2078494375), INT32_C(  650856359)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1672271308), INT32_C(-1503351515), INT32_C(-1874414686), INT32_C(  435117874)),
      simde_mm_set_epi32(INT32_C(-1672271308), INT32_C(-1630328519), INT32_C(-1874414686), INT32_C(  435117874)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmplt_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1231873664), INT32_C( 1036602093), INT32_C( -933713727), INT32_C( 2093671800)),
      simde_mm_set_epi32(INT32_C( 1231873664), INT32_C( 1036602093), INT32_C(  357806524), INT32_C( 2093671800)),
      simde_mm_set_epi32(INT32_C( 1231873664), INT32_C( 1036602093), INT32_C( -933713727), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  793534664), INT32_C(  376969487), INT32_C(  721355231), INT32_C( 1023311191)),
      simde_mm_set_epi32(INT32_C(-1925750607), INT32_C(-1255391862), INT32_C(  721355231), INT32_C( 2118013683)),
      simde_mm_set_epi32(INT32_C(  793534664), INT32_C(  376969487), INT32_C(  721355231), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1783953523), INT32_C( 1823399536), INT32_C( 1402581392), INT32_C(-1166205233)),
      simde_mm_set_epi32(INT32_C( 1218188972), INT32_C(-1327532162), INT32_C(-1033869830), INT32_C(-1166205233)),
      simde_mm_set_epi32(INT32_C(-1783953523), INT32_C( 1823399536), INT32_C( 1402581392), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  223867160), INT32_C(-1451057003), INT32_C( 2044754038), INT32_C(  605919704)),
      simde_mm_set_epi32(INT32_C(  223867160), INT32_C(-1334167478), INT32_C( 2044754038), INT32_C(  605919704)),
      simde_mm_set_epi32(INT32_C(  223867160), INT32_C(-1451057003), INT32_C( 2044754038), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  951875437), INT32_C( 1770306939), INT32_C(-1002738540), INT32_C( 1475715403)),
      simde_mm_set_epi32(INT32_C(  935489339), INT32_C( 1770306939), INT32_C(-1002738540), INT32_C(  867597907)),
      simde_mm_set_epi32(INT32_C(  951875437), INT32_C( 1770306939), INT32_C(-1002738540), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -400845231), INT32_C(-1931717289), INT32_C(  187179269), INT32_C( 1693770206)),
      simde_mm_set_epi32(INT32_C( -400845231), INT32_C( 1409986791), INT32_C(  867295140), INT32_C( 1693770206)),
      simde_mm_set_epi32(INT32_C( -400845231), INT32_C(-1931717289), INT32_C(  187179269), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1979013327), INT32_C( 1144749620), INT32_C( -915616748), INT32_C(-1688776910)),
      simde_mm_set_epi32(INT32_C( 1979013327), INT32_C( -522411693), INT32_C( -915616748), INT32_C(-1688776910)),
      simde_mm_set_epi32(INT32_C( 1979013327), INT32_C( 1144749620), INT32_C( -915616748), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1335736202), INT32_C(  434505386), INT32_C( 1706493603), INT32_C( 1636681283)),
      simde_mm_set_epi32(INT32_C(-1335736202), INT32_C(  434505386), INT32_C( 1706493603), INT32_C(  754767105)),
      simde_mm_set_epi32(INT32_C(-1335736202), INT32_C(  434505386), INT32_C( 1706493603), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmplt_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpneq_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  532215048), INT32_C(  130142512), INT32_C(-2127364592), INT32_C( 1091895543)),
      simde_mm_set_epi32(INT32_C(  532215048), INT32_C(  130142512), INT32_C(-2127364592), INT32_C( 1091895543)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1046985290), INT32_C(-1731603099), INT32_C(  610751781), INT32_C( 1112478841)),
      simde_mm_set_epi32(INT32_C(-1046985290), INT32_C(  622608062), INT32_C(-1239630421), INT32_C(-1197092706)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1281269663), INT32_C(   10288009), INT32_C(  351928123), INT32_C(   68696372)),
      simde_mm_set_epi32(INT32_C( 1281269663), INT32_C( 1321240790), INT32_C( 1472147540), INT32_C(  221255688)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 2082220393), INT32_C(  853275580), INT32_C( 1554259301), INT32_C( 1874019211)),
      simde_mm_set_epi32(INT32_C( 2082220393), INT32_C(  853275580), INT32_C( -464704033), INT32_C( 1874019211)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1607341285), INT32_C(  801224090), INT32_C(  790655246), INT32_C( 1500708888)),
      simde_mm_set_epi32(INT32_C( 1686421224), INT32_C( -848290084), INT32_C( 1521902022), INT32_C(  974050035)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  209990814), INT32_C( 2072268417), INT32_C( -198384983), INT32_C( -634248146)),
      simde_mm_set_epi32(INT32_C(-1549476809), INT32_C( -306787617), INT32_C( -198384983), INT32_C(  461233263)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 2046647956), INT32_C(  403639600), INT32_C( -500490027), INT32_C(   21369987)),
      simde_mm_set_epi32(INT32_C( 2046647956), INT32_C( 1922885083), INT32_C( -500490027), INT32_C(  437329742)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1569313979), INT32_C(-1644454001), INT32_C(-1155267042), INT32_C( -840725054)),
      simde_mm_set_epi32(INT32_C(-1569313979), INT32_C(-1403674957), INT32_C(-1155267042), INT32_C( -840725054)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpneq_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpneq_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -360810495), INT32_C(-1592808236), INT32_C(  688144434), INT32_C( 1729628761)),
      simde_mm_set_epi32(INT32_C(-1174522920), INT32_C(  592092453), INT32_C(  688144434), INT32_C(-1493258549)),
      simde_mm_set_epi32(INT32_C( -360810495), INT32_C(-1592808236), INT32_C(  688144434), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1897806214), INT32_C( -836251000), INT32_C( 1879840962), INT32_C( 1741986879)),
      simde_mm_set_epi32(INT32_C( 1897806214), INT32_C( 1708676885), INT32_C( -829246870), INT32_C( 1436108855)),
      simde_mm_set_epi32(INT32_C( 1897806214), INT32_C( -836251000), INT32_C( 1879840962), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1752241902), INT32_C(-2071998685), INT32_C( -472663454), INT32_C( -626361712)),
      simde_mm_set_epi32(INT32_C( 2013622797), INT32_C(-2071998685), INT32_C(-1052835841), INT32_C( -626361712)),
      simde_mm_set_epi32(INT32_C(-1752241902), INT32_C(-2071998685), INT32_C( -472663454), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1426139517), INT32_C(  408854398), INT32_C( 1288359889), INT32_C(-1580268734)),
      simde_mm_set_epi32(INT32_C(-1426139517), INT32_C(  408854398), INT32_C( 1288359889), INT32_C(-1580268734)),
      simde_mm_set_epi32(INT32_C(-1426139517), INT32_C(  408854398), INT32_C( 1288359889), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1447450397), INT32_C(  498817306), INT32_C(   48851994), INT32_C(-1751968553)),
      simde_mm_set_epi32(INT32_C( -142346191), INT32_C(-1158316806), INT32_C( 1062598271), INT32_C( -267767173)),
      simde_mm_set_epi32(INT32_C( 1447450397), INT32_C(  498817306), INT32_C(   48851994), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  777179606), INT32_C( 1922869133), INT32_C(-2009725956), INT32_C( 2047200466)),
      simde_mm_set_epi32(INT32_C(  778691217), INT32_C(  807594000), INT32_C(-2009725956), INT32_C( 2047200466)),
      simde_mm_set_epi32(INT32_C(  777179606), INT32_C( 1922869133), INT32_C(-2009725956), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1844022768), INT32_C(  257130431), INT32_C( 1749772003), INT32_C(-1329350641)),
      simde_mm_set_epi32(INT32_C( 1038626596), INT32_C(  257130431), INT32_C( 1749772003), INT32_C( 1329214996)),
      simde_mm_set_epi32(INT32_C(-1844022768), INT32_C(  257130431), INT32_C( 1749772003), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  381813049), INT32_C( -254051472), INT32_C(-1103075616), INT32_C(-1510860170)),
      simde_mm_set_epi32(INT32_C(-1489319643), INT32_C( -254051472), INT32_C(-1103075616), INT32_C( -696173092)),
      simde_mm_set_epi32(INT32_C(  381813049), INT32_C( -254051472), INT32_C(-1103075616), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpneq_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnge_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1888650448), INT32_C( 1952380142), INT32_C( -418024326), INT32_C(  954406307)),
      simde_mm_set_epi32(INT32_C( 1888650448), INT32_C( 1952380142), INT32_C( 1530340429), INT32_C(  315056976)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -675143251), INT32_C(   71969785), INT32_C( -921847024), INT32_C(   22067797)),
      simde_mm_set_epi32(INT32_C(   72561527), INT32_C( 1005464844), INT32_C( -921847024), INT32_C(   22067797)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-2139620548), INT32_C(-1593174748), INT32_C( -604878160), INT32_C(-1601463094)),
      simde_mm_set_epi32(INT32_C(-2139620548), INT32_C(  492282745), INT32_C( -604878160), INT32_C( 1512309058)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1508734054), INT32_C(  370976534), INT32_C( 2066803930), INT32_C( -701634011)),
      simde_mm_set_epi32(INT32_C( 1927420129), INT32_C(  370976534), INT32_C( 2066803930), INT32_C( -701634011)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  297952699), INT32_C( 2014428800), INT32_C( -102481167), INT32_C( 2086329997)),
      simde_mm_set_epi32(INT32_C( 1611455963), INT32_C( 2014428800), INT32_C( -102481167), INT32_C(-2102996894)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -649625825), INT32_C( -985868832), INT32_C( 1191775411), INT32_C(  442065450)),
      simde_mm_set_epi32(INT32_C( -649625825), INT32_C( 1060858907), INT32_C( -423355707), INT32_C(-2066634583)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1343578941), INT32_C(  107928701), INT32_C(-2043979132), INT32_C( 1583468645)),
      simde_mm_set_epi32(INT32_C( -744928720), INT32_C(-1908186697), INT32_C(-2043979132), INT32_C(  -98145208)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1297942286), INT32_C( 1312694015), INT32_C(-1476884375), INT32_C( 1085937493)),
      simde_mm_set_epi32(INT32_C( 1297942286), INT32_C( 1312694015), INT32_C(-1476884375), INT32_C(  811271927)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpnge_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnge_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  106734352), INT32_C(-1177695143), INT32_C( 1251867427), INT32_C(-1113436842)),
      simde_mm_set_epi32(INT32_C(-2016761807), INT32_C(-1602250813), INT32_C(-1502543805), INT32_C(-1113436842)),
      simde_mm_set_epi32(INT32_C(  106734352), INT32_C(-1177695143), INT32_C( 1251867427), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -992010454), INT32_C(  875520944), INT32_C( -773626008), INT32_C(  297000538)),
      simde_mm_set_epi32(INT32_C( -992010454), INT32_C(  875520944), INT32_C(-1960267017), INT32_C(  267267504)),
      simde_mm_set_epi32(INT32_C( -992010454), INT32_C(  875520944), INT32_C( -773626008), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1423404927), INT32_C( -273294615), INT32_C( 1115052821), INT32_C( 1762207327)),
      simde_mm_set_epi32(INT32_C(-1423404927), INT32_C(-2004658753), INT32_C( 1115052821), INT32_C(-1955515955)),
      simde_mm_set_epi32(INT32_C(-1423404927), INT32_C( -273294615), INT32_C( 1115052821), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  630570300), INT32_C( 1480720620), INT32_C(-2111634368), INT32_C(  381139912)),
      simde_mm_set_epi32(INT32_C(   91445288), INT32_C( 1480720620), INT32_C(-2111634368), INT32_C(  381139912)),
      simde_mm_set_epi32(INT32_C(  630570300), INT32_C( 1480720620), INT32_C(-2111634368), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-2140660333), INT32_C( -873371869), INT32_C(-1549425333), INT32_C( 1861722511)),
      simde_mm_set_epi32(INT32_C(-1410997069), INT32_C( -873371869), INT32_C(-1549425333), INT32_C( -149520118)),
      simde_mm_set_epi32(INT32_C(-2140660333), INT32_C( -873371869), INT32_C(-1549425333), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1896750546), INT32_C(  577432699), INT32_C( -255384715), INT32_C(  717895922)),
      simde_mm_set_epi32(INT32_C( 1233088565), INT32_C(-1957258082), INT32_C( 1913240068), INT32_C(-1565227266)),
      simde_mm_set_epi32(INT32_C(-1896750546), INT32_C(  577432699), INT32_C( -255384715), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1577990746), INT32_C( 1577580126), INT32_C( -298703690), INT32_C(  397262282)),
      simde_mm_set_epi32(INT32_C(-2105366944), INT32_C( 1950034916), INT32_C( -298703690), INT32_C( 1632078127)),
      simde_mm_set_epi32(INT32_C( 1577990746), INT32_C( 1577580126), INT32_C( -298703690), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1398991860), INT32_C( -868057052), INT32_C(  897239402), INT32_C(  478239630)),
      simde_mm_set_epi32(INT32_C(-1398991860), INT32_C(-1311190075), INT32_C(-1018578616), INT32_C(-1096405398)),
      simde_mm_set_epi32(INT32_C(-1398991860), INT32_C( -868057052), INT32_C(  897239402), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpnge_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpngt_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1123406769), INT32_C( -826046923), INT32_C( 1391137025), INT32_C(  225408485)),
      simde_mm_set_epi32(INT32_C(-1123406769), INT32_C( 1170001915), INT32_C( -443741078), INT32_C(  225408485)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  919359233), INT32_C(  121568041), INT32_C( 1196900513), INT32_C(-2068491895)),
      simde_mm_set_epi32(INT32_C( -229431781), INT32_C(  121568041), INT32_C( -495278912), INT32_C(-2068491895)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1546227894), INT32_C(  -80396000), INT32_C( 1691185200), INT32_C(-1185796610)),
      simde_mm_set_epi32(INT32_C(  930129185), INT32_C(  460197193), INT32_C( 1461329142), INT32_C(  -46416365)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  801509529), INT32_C(  166196414), INT32_C( 1533458041), INT32_C(-2125985376)),
      simde_mm_set_epi32(INT32_C(  801509529), INT32_C(  166196414), INT32_C(  170298010), INT32_C( -614823370)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -383558878), INT32_C( 1739426797), INT32_C(-1413157826), INT32_C(-1057748324)),
      simde_mm_set_epi32(INT32_C( -383558878), INT32_C(  561929576), INT32_C(-1413157826), INT32_C(-1057748324)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  303550578), INT32_C(  722713191), INT32_C(-1131128469), INT32_C( -492258520)),
      simde_mm_set_epi32(INT32_C( -260529955), INT32_C(  722713191), INT32_C(-1131128469), INT32_C( -492258520)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -760270686), INT32_C(-1716923162), INT32_C(  225019073), INT32_C(-2108522398)),
      simde_mm_set_epi32(INT32_C( -103603972), INT32_C(  226706263), INT32_C(  225019073), INT32_C( -506819004)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(   44043689), INT32_C( 1891018514), INT32_C(  705898855), INT32_C( -899283598)),
      simde_mm_set_epi32(INT32_C(   44043689), INT32_C( 1891018514), INT32_C( -639205394), INT32_C( -899283598)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpngt_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpngt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  612778091), INT32_C( 1832771785), INT32_C( -622594968), INT32_C(  910095126)),
      simde_mm_set_epi32(INT32_C(  458628115), INT32_C(  689947875), INT32_C( -348460368), INT32_C(  227312121)),
      simde_mm_set_epi32(INT32_C(  612778091), INT32_C( 1832771785), INT32_C( -622594968), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1078825247), INT32_C(-1403039755), INT32_C( 1610931740), INT32_C(  175799384)),
      simde_mm_set_epi32(INT32_C( -601333689), INT32_C(  307533582), INT32_C( 1610931740), INT32_C(  175799384)),
      simde_mm_set_epi32(INT32_C(-1078825247), INT32_C(-1403039755), INT32_C( 1610931740), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -473381137), INT32_C(-1853677516), INT32_C(    4434085), INT32_C(  177860717)),
      simde_mm_set_epi32(INT32_C( -473381137), INT32_C(-1429612088), INT32_C( 1023613916), INT32_C(-1567281359)),
      simde_mm_set_epi32(INT32_C( -473381137), INT32_C(-1853677516), INT32_C(    4434085), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1461690128), INT32_C( -186641995), INT32_C(-1876360628), INT32_C(  720924768)),
      simde_mm_set_epi32(INT32_C( 1256087859), INT32_C( -186641995), INT32_C(-1876360628), INT32_C(  720924768)),
      simde_mm_set_epi32(INT32_C(-1461690128), INT32_C( -186641995), INT32_C(-1876360628), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 2056917783), INT32_C( -907049588), INT32_C( 1171345475), INT32_C(-1386896922)),
      simde_mm_set_epi32(INT32_C( 2056917783), INT32_C( -907049588), INT32_C( 2132166674), INT32_C(-1386896922)),
      simde_mm_set_epi32(INT32_C( 2056917783), INT32_C( -907049588), INT32_C( 1171345475), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  333966351), INT32_C( 1310053758), INT32_C( 1466732857), INT32_C(-1121891710)),
      simde_mm_set_epi32(INT32_C(  333966351), INT32_C( 1310053758), INT32_C( 1572556388), INT32_C(-1121891710)),
      simde_mm_set_epi32(INT32_C(  333966351), INT32_C( 1310053758), INT32_C( 1466732857), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  860690730), INT32_C(-1667003350), INT32_C(-1337189707), INT32_C( 1913729946)),
      simde_mm_set_epi32(INT32_C(  860690730), INT32_C(-1667003350), INT32_C( -470676019), INT32_C( -895735920)),
      simde_mm_set_epi32(INT32_C(  860690730), INT32_C(-1667003350), INT32_C(-1337189707), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1440878372), INT32_C( 1637362808), INT32_C( -984574857), INT32_C(  760105912)),
      simde_mm_set_epi32(INT32_C(  511504303), INT32_C( 1637362808), INT32_C( -984574857), INT32_C(  760105912)),
      simde_mm_set_epi32(INT32_C( 1440878372), INT32_C( 1637362808), INT32_C( -984574857), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpngt_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnle_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 2084445991), INT32_C(-1270940367), INT32_C( -137999497), INT32_C( 1274474466)),
      simde_mm_set_epi32(INT32_C( 2084445991), INT32_C( 1003404174), INT32_C( -137999497), INT32_C( 1274474466)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1073857581), INT32_C(  297220883), INT32_C(-1118323043), INT32_C(-2009485771)),
      simde_mm_set_epi32(INT32_C(-1073857581), INT32_C(-1478175756), INT32_C(-1118323043), INT32_C(-2009485771)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1368751028), INT32_C( 1620987038), INT32_C( 1536890594), INT32_C( -889040581)),
      simde_mm_set_epi32(INT32_C( 2024237287), INT32_C( 1620987038), INT32_C(  809803938), INT32_C( -761648004)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  965653593), INT32_C( 1368656732), INT32_C(-2063999421), INT32_C( -170225342)),
      simde_mm_set_epi32(INT32_C(  965653593), INT32_C( 1368656732), INT32_C(-1629280761), INT32_C( -170225342)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1924982985), INT32_C(  388770010), INT32_C( 1672412411), INT32_C(-1198604482)),
      simde_mm_set_epi32(INT32_C( -502648824), INT32_C( 1358695998), INT32_C(-1024782381), INT32_C(-1198604482)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1453860753), INT32_C(-1007750264), INT32_C( 2035232495), INT32_C(-1933616133)),
      simde_mm_set_epi32(INT32_C(-1419270643), INT32_C(-2082779635), INT32_C(-1193599699), INT32_C( 1986918969)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  731183446), INT32_C( -811315535), INT32_C( -739483356), INT32_C(  137475709)),
      simde_mm_set_epi32(INT32_C(-1602128714), INT32_C( -811315535), INT32_C( -739483356), INT32_C(  137475709)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -278168455), INT32_C(-1440405844), INT32_C( -351927257), INT32_C( -925114922)),
      simde_mm_set_epi32(INT32_C(   97237822), INT32_C(-1440405844), INT32_C( 1100655169), INT32_C(  181456962)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpnle_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnle_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  586573716), INT32_C( 2092571439), INT32_C(-1569791359), INT32_C( -771884114)),
      simde_mm_set_epi32(INT32_C(-1772197058), INT32_C( 2000867488), INT32_C( 1628528221), INT32_C( -771884114)),
      simde_mm_set_epi32(INT32_C(  586573716), INT32_C( 2092571439), INT32_C(-1569791359), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1418270756), INT32_C(-1023444334), INT32_C( 1630284961), INT32_C( 1200999231)),
      simde_mm_set_epi32(INT32_C(-1887216511), INT32_C(   -3136960), INT32_C( 1630284961), INT32_C( 1952383628)),
      simde_mm_set_epi32(INT32_C( 1418270756), INT32_C(-1023444334), INT32_C( 1630284961), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-1506287819), INT32_C(  667997188), INT32_C( -179453871), INT32_C( 1445563364)),
      simde_mm_set_epi32(INT32_C(-1506287819), INT32_C(  832794192), INT32_C( -179453871), INT32_C( 1445563364)),
      simde_mm_set_epi32(INT32_C(-1506287819), INT32_C(  667997188), INT32_C( -179453871), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -921490700), INT32_C(  767377840), INT32_C( 1198841751), INT32_C(  335888297)),
      simde_mm_set_epi32(INT32_C( -729465888), INT32_C(  767377840), INT32_C(-1211611524), INT32_C(  962373371)),
      simde_mm_set_epi32(INT32_C( -921490700), INT32_C(  767377840), INT32_C( 1198841751), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  279427637), INT32_C(-1356366148), INT32_C( -778146350), INT32_C( -407135484)),
      simde_mm_set_epi32(INT32_C( -396894639), INT32_C(-1356366148), INT32_C( -778146350), INT32_C( 1071745245)),
      simde_mm_set_epi32(INT32_C(  279427637), INT32_C(-1356366148), INT32_C( -778146350), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  646913785), INT32_C(-1754178229), INT32_C(  419585954), INT32_C(  -90816511)),
      simde_mm_set_epi32(INT32_C(  733359934), INT32_C(-1754178229), INT32_C( 1438707211), INT32_C(  -90816511)),
      simde_mm_set_epi32(INT32_C(  646913785), INT32_C(-1754178229), INT32_C(  419585954), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -929496881), INT32_C( -605733719), INT32_C(  626875427), INT32_C(  862216293)),
      simde_mm_set_epi32(INT32_C(  769282939), INT32_C( -605733719), INT32_C(  626875427), INT32_C(  862216293)),
      simde_mm_set_epi32(INT32_C( -929496881), INT32_C( -605733719), INT32_C(  626875427), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1307976927), INT32_C( 1620554754), INT32_C( 1085448799), INT32_C( 1857805228)),
      simde_mm_set_epi32(INT32_C(-1751946539), INT32_C( 1620554754), INT32_C( -209862470), INT32_C(-1671218193)),
      simde_mm_set_epi32(INT32_C( 1307976927), INT32_C( 1620554754), INT32_C( 1085448799), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpnle_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnlt_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -696394921), INT32_C( -747986358), INT32_C( -647555009), INT32_C( 1026098152)),
      simde_mm_set_epi32(INT32_C( -633562196), INT32_C( -747986358), INT32_C( -647555009), INT32_C( 1026098152)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -452783834), INT32_C( -762534148), INT32_C(  527526057), INT32_C(  875267484)),
      simde_mm_set_epi32(INT32_C( 2135403130), INT32_C( -762534148), INT32_C(  527526057), INT32_C( -792882965)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1833897906), INT32_C(-1370978496), INT32_C(-1396909811), INT32_C(  612871018)),
      simde_mm_set_epi32(INT32_C(-1833897906), INT32_C(-1370978496), INT32_C( 1459624563), INT32_C(  612871018)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1770608184), INT32_C(-1440913128), INT32_C( -375433996), INT32_C(-1167135078)),
      simde_mm_set_epi32(INT32_C( 1685329021), INT32_C( 1594341486), INT32_C( -749207466), INT32_C(-1647221832)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(-2031323732), INT32_C( -384315017), INT32_C(-2075546059), INT32_C(-1034483494)),
      simde_mm_set_epi32(INT32_C(  261868471), INT32_C( -384315017), INT32_C(-2075546059), INT32_C(-1034483494)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  749959102), INT32_C( 1174344579), INT32_C( 1538886158), INT32_C( 1204052778)),
      simde_mm_set_epi32(INT32_C(  915491351), INT32_C( 1174344579), INT32_C( 1538886158), INT32_C( 1204052778)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  702745450), INT32_C(-1148209866), INT32_C(  305771684), INT32_C(   10161619)),
      simde_mm_set_epi32(INT32_C( -437200102), INT32_C(-1148209866), INT32_C(  703243165), INT32_C(   10161619)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(-1984623370), INT32_C( 1198216493), INT32_C( 1096311405), INT32_C( -697370337)),
      simde_mm_set_epi32(INT32_C(-1984623370), INT32_C( 1198216493), INT32_C( 1096311405), INT32_C( -697370337)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpnlt_ps(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnlt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1412010535), INT32_C(-1239400933), INT32_C(  594063422), INT32_C( 1188961914)),
      simde_mm_set_epi32(INT32_C( 1663850825), INT32_C(-1239400933), INT32_C(  594063422), INT32_C( 1188961914)),
      simde_mm_set_epi32(INT32_C( 1412010535), INT32_C(-1239400933), INT32_C(  594063422), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -316965064), INT32_C(-1377591008), INT32_C(-1622896924), INT32_C(-1267585285)),
      simde_mm_set_epi32(INT32_C( -662180320), INT32_C(-1377591008), INT32_C( -505498051), INT32_C( -824079960)),
      simde_mm_set_epi32(INT32_C( -316965064), INT32_C(-1377591008), INT32_C(-1622896924), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  952041483), INT32_C( -759750393), INT32_C(  571126339), INT32_C(-1097881178)),
      simde_mm_set_epi32(INT32_C(  952041483), INT32_C( -759750393), INT32_C(  571126339), INT32_C(  206622744)),
      simde_mm_set_epi32(INT32_C(  952041483), INT32_C( -759750393), INT32_C(  571126339), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( -778057296), INT32_C(-1150074331), INT32_C(  485854915), INT32_C( -514788129)),
      simde_mm_set_epi32(INT32_C(  235219858), INT32_C(-1150074331), INT32_C(  485854915), INT32_C( -514788129)),
      simde_mm_set_epi32(INT32_C( -778057296), INT32_C(-1150074331), INT32_C(  485854915), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( 1021281951), INT32_C(  386387638), INT32_C(  435001339), INT32_C(  317446933)),
      simde_mm_set_epi32(INT32_C(-1890218411), INT32_C(-1750380903), INT32_C(  435001339), INT32_C(  317446933)),
      simde_mm_set_epi32(INT32_C( 1021281951), INT32_C(  386387638), INT32_C(  435001339), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -137019013), INT32_C( 1227598678), INT32_C( 1179331321), INT32_C(-2004841764)),
      simde_mm_set_epi32(INT32_C( 1473692950), INT32_C( 1227598678), INT32_C( 1179331321), INT32_C(-2004841764)),
      simde_mm_set_epi32(INT32_C( -137019013), INT32_C( 1227598678), INT32_C( 1179331321), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C(  196197184), INT32_C(-1956925508), INT32_C( 1585557819), INT32_C(  132702049)),
      simde_mm_set_epi32(INT32_C(-1510035164), INT32_C(-1956925508), INT32_C(-2054438272), INT32_C(  132702049)),
      simde_mm_set_epi32(INT32_C(  196197184), INT32_C(-1956925508), INT32_C( 1585557819), INT32_C(         -1)) },
    { simde_mm_set_epi32(INT32_C( -985194720), INT32_C( 1720892194), INT32_C( 1096426703), INT32_C(-1009397670)),
      simde_mm_set_epi32(INT32_C( -874151390), INT32_C( -332830918), INT32_C( 1096426703), INT32_C( 1294469295)),
      simde_mm_set_epi32(INT32_C( -985194720), INT32_C( 1720892194), INT32_C( 1096426703), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(
        simde_mm_cmpnlt_ss(
          simde_mm_castsi128_ps(test_vec[i].a),
          simde_mm_castsi128_ps(test_vec[i].b)));
    simde_test_x86_assert_equal_i32x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpord_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_mm_set_ps(1.0f,  NAN,  NAN, 2.0f),
      simde_mm_set_ps( NAN, 3.0f,  NAN, 4.0f),
      simde_mm_move_ss(simde_mm_setzero_ps(), simde_x_mm_setone_ps()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpord_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_cmpord_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   458.45), SIMDE_FLOAT32_C(   -42.89), SIMDE_FLOAT32_C(   680.45), SIMDE_FLOAT32_C(  -622.11)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   343.10), SIMDE_FLOAT32_C(  -612.18), SIMDE_FLOAT32_C(  -268.76),                   nanf("")),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   458.45), SIMDE_FLOAT32_C(   -42.89), SIMDE_FLOAT32_C(   680.45), SIMDE_FLOAT32_C(  -622.11)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -452.28), SIMDE_FLOAT32_C(  -680.79), SIMDE_FLOAT32_C(   958.41), SIMDE_FLOAT32_C(   629.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -707.65), SIMDE_FLOAT32_C(   308.61), SIMDE_FLOAT32_C(   360.51),                   nanf("")),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -452.28), SIMDE_FLOAT32_C(  -680.79), SIMDE_FLOAT32_C(   958.41), SIMDE_FLOAT32_C(   629.53)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -606.93), SIMDE_FLOAT32_C(  -332.63), SIMDE_FLOAT32_C(  -293.59), SIMDE_FLOAT32_C(   771.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   725.97),                   nanf(""), SIMDE_FLOAT32_C(  -698.52), SIMDE_FLOAT32_C(  -855.59)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -606.93), SIMDE_FLOAT32_C(  -332.63), SIMDE_FLOAT32_C(  -293.59), SIMDE_FLOAT32_C(   771.09)), simde_x_mm_setone_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -910.47), SIMDE_FLOAT32_C(   -52.21), SIMDE_FLOAT32_C(   524.20), SIMDE_FLOAT32_C(   797.22)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   507.03), SIMDE_FLOAT32_C(   414.86),                   nanf(""),                   nanf("")),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -910.47), SIMDE_FLOAT32_C(   -52.21), SIMDE_FLOAT32_C(   524.20), SIMDE_FLOAT32_C(   797.22)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -835.84), SIMDE_FLOAT32_C(   -92.24), SIMDE_FLOAT32_C(   876.06), SIMDE_FLOAT32_C(   325.47)),
      simde_mm_set_ps(                  nanf(""),                   nanf(""),                   nanf(""), SIMDE_FLOAT32_C(   830.79)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -835.84), SIMDE_FLOAT32_C(   -92.24), SIMDE_FLOAT32_C(   876.06), SIMDE_FLOAT32_C(   325.47)), simde_x_mm_setone_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   486.04), SIMDE_FLOAT32_C(  -785.31), SIMDE_FLOAT32_C(  -528.45), SIMDE_FLOAT32_C(   809.84)),
      simde_mm_set_ps(                  nanf(""), SIMDE_FLOAT32_C(  -874.62),                   nanf(""), SIMDE_FLOAT32_C(  -620.27)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   486.04), SIMDE_FLOAT32_C(  -785.31), SIMDE_FLOAT32_C(  -528.45), SIMDE_FLOAT32_C(   809.84)), simde_x_mm_setone_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -705.98), SIMDE_FLOAT32_C(  -135.25), SIMDE_FLOAT32_C(  -941.10), SIMDE_FLOAT32_C(  -105.40)),
      simde_mm_set_ps(                  nanf(""),                   nanf(""),                   nanf(""), SIMDE_FLOAT32_C(   424.16)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -705.98), SIMDE_FLOAT32_C(  -135.25), SIMDE_FLOAT32_C(  -941.10), SIMDE_FLOAT32_C(  -105.40)), simde_x_mm_setone_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   692.24), SIMDE_FLOAT32_C(  -983.30), SIMDE_FLOAT32_C(   728.96), SIMDE_FLOAT32_C(   658.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -329.64), SIMDE_FLOAT32_C(    60.61),                   nanf(""), SIMDE_FLOAT32_C(   824.02)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   692.24), SIMDE_FLOAT32_C(  -983.30), SIMDE_FLOAT32_C(   728.96), SIMDE_FLOAT32_C(   658.52)), simde_x_mm_setone_ps()) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cmpord_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cmpunord_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(2.0), SIMDE_FLOAT32_C(3.0), SIMDE_FLOAT32_C(4.0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(2.0), SIMDE_FLOAT32_C(3.0), SIMDE_FLOAT32_C(4.0)),
      simde_mm_setzero_ps() },
    { simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_x_mm_setone_ps() },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(2.0), SIMDE_FLOAT32_C(3.0), NAN),
      simde_mm_set_ps(SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(2.0), SIMDE_FLOAT32_C(3.0), SIMDE_FLOAT32_C(4.0)),
      simde_mm_move_ss(simde_mm_setzero_ps(), simde_x_mm_setone_ps()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpunord_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_comieq_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      1 },
    { simde_mm_set_ps(0.9426f, 0.1679f, 0.2845f, 0.1698f),
      simde_mm_set_ps(0.9426f, 0.6931f, 0.2845f, 0.1698f),
      1 },
    { simde_mm_set_ps(0.0547f, 0.2368f, 0.3365f, 0.9146f),
      simde_mm_set_ps(0.0547f, 0.5935f, 0.3365f, 0.5014f),
      0 },
    { simde_mm_set_ps(0.7179f, 0.8607f, 0.4372f, 0.6140f),
      simde_mm_set_ps(0.7179f, 0.7239f, 0.4372f, 0.6140f),
      1 },
    { simde_mm_set_ps(0.4474f, 0.6848f, 0.4305f, 0.8738f),
      simde_mm_set_ps(0.6059f, 0.8463f, 0.4305f, 0.1517f),
      0 },
    { simde_mm_set_ps(0.4537f, 0.7254f, 0.9987f, 0.9115f),
      simde_mm_set_ps(0.1771f, 0.2982f, 0.9987f, 0.9003f),
      0 },
    { simde_mm_set_ps(0.2162f, 0.6303f, 0.0602f, 0.9986f),
      simde_mm_set_ps(0.2162f, 0.5872f, 0.0602f, 0.2491f),
      0 },
    { simde_mm_set_ps(0.4836f, 0.9929f, 0.8942f, 0.2367f),
      simde_mm_set_ps(0.4836f, 0.9929f, 0.4202f, 0.2367f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comieq_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comige_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comige_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comigt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comigt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comile_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comile_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comilt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comilt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comineq_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comineq_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpunord_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -653.22), SIMDE_FLOAT32_C(   230.72), SIMDE_FLOAT32_C(   -26.51), SIMDE_FLOAT32_C(  -933.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -424.17), SIMDE_FLOAT32_C(  -842.33), SIMDE_FLOAT32_C(  -110.12), SIMDE_FLOAT32_C(   206.71)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -653.22), SIMDE_FLOAT32_C(   230.72), SIMDE_FLOAT32_C(   -26.51), SIMDE_FLOAT32_C(  -933.90)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -108.53), SIMDE_FLOAT32_C(   720.30), SIMDE_FLOAT32_C(   100.87), SIMDE_FLOAT32_C(   112.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   506.84),                       NAN , SIMDE_FLOAT32_C(   498.67), SIMDE_FLOAT32_C(  -576.77)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -108.53), SIMDE_FLOAT32_C(   720.30), SIMDE_FLOAT32_C(   100.87), SIMDE_FLOAT32_C(   112.49)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -877.11), SIMDE_FLOAT32_C(   574.64), SIMDE_FLOAT32_C(   434.50), SIMDE_FLOAT32_C(  -728.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -677.16),                       NAN , SIMDE_FLOAT32_C(   284.18), SIMDE_FLOAT32_C(  -923.70)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  -877.11), SIMDE_FLOAT32_C(   574.64), SIMDE_FLOAT32_C(   434.50), SIMDE_FLOAT32_C(  -728.82)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   876.32), SIMDE_FLOAT32_C(  -475.29), SIMDE_FLOAT32_C(  -377.05), SIMDE_FLOAT32_C(   152.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   737.32), SIMDE_FLOAT32_C(  -937.49),                       NAN ,                       NAN ),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   876.32), SIMDE_FLOAT32_C(  -475.29), SIMDE_FLOAT32_C(  -377.05), SIMDE_FLOAT32_C(   152.30)), simde_x_mm_setone_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   752.03), SIMDE_FLOAT32_C(   -30.87), SIMDE_FLOAT32_C(  -483.32), SIMDE_FLOAT32_C(   405.97)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   728.44),                       NAN ,                       NAN , SIMDE_FLOAT32_C(   923.45)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   752.03), SIMDE_FLOAT32_C(   -30.87), SIMDE_FLOAT32_C(  -483.32), SIMDE_FLOAT32_C(   405.97)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   354.09), SIMDE_FLOAT32_C(  -692.72), SIMDE_FLOAT32_C(     1.69), SIMDE_FLOAT32_C(  -654.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   593.37), SIMDE_FLOAT32_C(   396.32), SIMDE_FLOAT32_C(  -487.41), SIMDE_FLOAT32_C(  -895.17)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   354.09), SIMDE_FLOAT32_C(  -692.72), SIMDE_FLOAT32_C(     1.69), SIMDE_FLOAT32_C(  -654.30)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   964.75), SIMDE_FLOAT32_C(  -220.47), SIMDE_FLOAT32_C(  -310.10), SIMDE_FLOAT32_C(   557.03)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -517.95),                       NAN , SIMDE_FLOAT32_C(    -0.27), SIMDE_FLOAT32_C(   260.96)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   964.75), SIMDE_FLOAT32_C(  -220.47), SIMDE_FLOAT32_C(  -310.10), SIMDE_FLOAT32_C(   557.03)), simde_mm_setzero_ps()) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    73.48), SIMDE_FLOAT32_C(   303.75), SIMDE_FLOAT32_C(   206.16), SIMDE_FLOAT32_C(   533.85)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -948.94), SIMDE_FLOAT32_C(  -599.14), SIMDE_FLOAT32_C(  -836.27), SIMDE_FLOAT32_C(  -409.07)),
      simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(    73.48), SIMDE_FLOAT32_C(   303.75), SIMDE_FLOAT32_C(   206.16), SIMDE_FLOAT32_C(   533.85)), simde_mm_setzero_ps()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpunord_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_x_mm_copysign_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -616.55), SIMDE_FLOAT32_C(  -399.29), SIMDE_FLOAT32_C(   528.87), SIMDE_FLOAT32_C(  -307.11) },
      { SIMDE_FLOAT32_C(   907.35), SIMDE_FLOAT32_C(  -230.71), SIMDE_FLOAT32_C(   874.68), SIMDE_FLOAT32_C(   549.16) },
      { SIMDE_FLOAT32_C(   616.55), SIMDE_FLOAT32_C(  -399.29), SIMDE_FLOAT32_C(   528.87), SIMDE_FLOAT32_C(   307.11) } },
    { { SIMDE_FLOAT32_C(   446.77), SIMDE_FLOAT32_C(    35.68), SIMDE_FLOAT32_C(   883.50), SIMDE_FLOAT32_C(  -871.02) },
      { SIMDE_FLOAT32_C(   531.89), SIMDE_FLOAT32_C(  -844.86), SIMDE_FLOAT32_C(  -327.10), SIMDE_FLOAT32_C(   604.14) },
      { SIMDE_FLOAT32_C(   446.77), SIMDE_FLOAT32_C(   -35.68), SIMDE_FLOAT32_C(  -883.50), SIMDE_FLOAT32_C(   871.02) } },
    { { SIMDE_FLOAT32_C(  -238.71), SIMDE_FLOAT32_C(   172.16), SIMDE_FLOAT32_C(   638.91), SIMDE_FLOAT32_C(   321.67) },
      { SIMDE_FLOAT32_C(  -441.31), SIMDE_FLOAT32_C(  -457.17), SIMDE_FLOAT32_C(  -768.83), SIMDE_FLOAT32_C(  -416.48) },
      { SIMDE_FLOAT32_C(  -238.71), SIMDE_FLOAT32_C(  -172.16), SIMDE_FLOAT32_C(  -638.91), SIMDE_FLOAT32_C(  -321.67) } },
    { { SIMDE_FLOAT32_C(  -568.75), SIMDE_FLOAT32_C(  -736.25), SIMDE_FLOAT32_C(   662.43), SIMDE_FLOAT32_C(  -206.91) },
      { SIMDE_FLOAT32_C(   583.40), SIMDE_FLOAT32_C(   854.52), SIMDE_FLOAT32_C(   190.70), SIMDE_FLOAT32_C(   966.85) },
      { SIMDE_FLOAT32_C(   568.75), SIMDE_FLOAT32_C(   736.25), SIMDE_FLOAT32_C(   662.43), SIMDE_FLOAT32_C(   206.91) } },
    { { SIMDE_FLOAT32_C(  -544.77), SIMDE_FLOAT32_C(  -280.43), SIMDE_FLOAT32_C(  -340.26), SIMDE_FLOAT32_C(  -637.42) },
      { SIMDE_FLOAT32_C(   488.86), SIMDE_FLOAT32_C(  -465.58), SIMDE_FLOAT32_C(   911.74), SIMDE_FLOAT32_C(   -64.37) },
      { SIMDE_FLOAT32_C(   544.77), SIMDE_FLOAT32_C(  -280.43), SIMDE_FLOAT32_C(   340.26), SIMDE_FLOAT32_C(  -637.42) } },
    { { SIMDE_FLOAT32_C(   570.10), SIMDE_FLOAT32_C(   795.24), SIMDE_FLOAT32_C(    64.61), SIMDE_FLOAT32_C(   101.99) },
      { SIMDE_FLOAT32_C(   950.38), SIMDE_FLOAT32_C(   737.51), SIMDE_FLOAT32_C(  -293.87), SIMDE_FLOAT32_C(  -288.33) },
      { SIMDE_FLOAT32_C(   570.10), SIMDE_FLOAT32_C(   795.24), SIMDE_FLOAT32_C(   -64.61), SIMDE_FLOAT32_C(  -101.99) } },
    { { SIMDE_FLOAT32_C(   -90.33), SIMDE_FLOAT32_C(  -654.96), SIMDE_FLOAT32_C(  -966.67), SIMDE_FLOAT32_C(   468.36) },
      { SIMDE_FLOAT32_C(  -112.14), SIMDE_FLOAT32_C(  -735.49), SIMDE_FLOAT32_C(  -948.11), SIMDE_FLOAT32_C(   319.11) },
      { SIMDE_FLOAT32_C(   -90.33), SIMDE_FLOAT32_C(  -654.96), SIMDE_FLOAT32_C(  -966.67), SIMDE_FLOAT32_C(   468.36) } },
    { { SIMDE_FLOAT32_C(  -471.74), SIMDE_FLOAT32_C(   714.32), SIMDE_FLOAT32_C(  -887.80), SIMDE_FLOAT32_C(  -888.34) },
      { SIMDE_FLOAT32_C(   568.84), SIMDE_FLOAT32_C(   302.91), SIMDE_FLOAT32_C(  -921.50), SIMDE_FLOAT32_C(  -975.94) },
      { SIMDE_FLOAT32_C(   471.74), SIMDE_FLOAT32_C(   714.32), SIMDE_FLOAT32_C(  -887.80), SIMDE_FLOAT32_C(  -888.34) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_x_mm_copysign_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_x_mm_xorsign_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -256.75), SIMDE_FLOAT32_C(    58.01), SIMDE_FLOAT32_C(  -152.81), SIMDE_FLOAT32_C(   780.53) },
      { SIMDE_FLOAT32_C(  -131.60), SIMDE_FLOAT32_C(  -695.20), SIMDE_FLOAT32_C(   -75.09), SIMDE_FLOAT32_C(  -141.32) },
      { SIMDE_FLOAT32_C(   256.75), SIMDE_FLOAT32_C(   -58.01), SIMDE_FLOAT32_C(   152.81), SIMDE_FLOAT32_C(  -780.53) } },
    { { SIMDE_FLOAT32_C(   823.76), SIMDE_FLOAT32_C(  -840.56), SIMDE_FLOAT32_C(  -829.93), SIMDE_FLOAT32_C(  -159.51) },
      { SIMDE_FLOAT32_C(   664.20), SIMDE_FLOAT32_C(  -222.93), SIMDE_FLOAT32_C(    30.99), SIMDE_FLOAT32_C(    36.00) },
      { SIMDE_FLOAT32_C(   823.76), SIMDE_FLOAT32_C(   840.56), SIMDE_FLOAT32_C(  -829.93), SIMDE_FLOAT32_C(  -159.51) } },
    { { SIMDE_FLOAT32_C(   637.35), SIMDE_FLOAT32_C(  -689.71), SIMDE_FLOAT32_C(   543.62), SIMDE_FLOAT32_C(   362.05) },
      { SIMDE_FLOAT32_C(   629.38), SIMDE_FLOAT32_C(  -813.91), SIMDE_FLOAT32_C(   470.90), SIMDE_FLOAT32_C(   839.80) },
      { SIMDE_FLOAT32_C(   637.35), SIMDE_FLOAT32_C(   689.71), SIMDE_FLOAT32_C(   543.62), SIMDE_FLOAT32_C(   362.05) } },
    { { SIMDE_FLOAT32_C(  -425.95), SIMDE_FLOAT32_C(   -92.61), SIMDE_FLOAT32_C(  -251.32), SIMDE_FLOAT32_C(   813.31) },
      { SIMDE_FLOAT32_C(  -430.82), SIMDE_FLOAT32_C(   216.76), SIMDE_FLOAT32_C(   838.12), SIMDE_FLOAT32_C(   312.43) },
      { SIMDE_FLOAT32_C(   425.95), SIMDE_FLOAT32_C(   -92.61), SIMDE_FLOAT32_C(  -251.32), SIMDE_FLOAT32_C(   813.31) } },
    { { SIMDE_FLOAT32_C(  -725.23), SIMDE_FLOAT32_C(  -314.69), SIMDE_FLOAT32_C(    92.96), SIMDE_FLOAT32_C(   143.17) },
      { SIMDE_FLOAT32_C(    -9.89), SIMDE_FLOAT32_C(  -982.12), SIMDE_FLOAT32_C(  -998.15), SIMDE_FLOAT32_C(  -186.13) },
      { SIMDE_FLOAT32_C(   725.23), SIMDE_FLOAT32_C(   314.69), SIMDE_FLOAT32_C(   -92.96), SIMDE_FLOAT32_C(  -143.17) } },
    { { SIMDE_FLOAT32_C(  -822.68), SIMDE_FLOAT32_C(  -828.08), SIMDE_FLOAT32_C(   654.36), SIMDE_FLOAT32_C(   841.52) },
      { SIMDE_FLOAT32_C(   -51.01), SIMDE_FLOAT32_C(  -314.64), SIMDE_FLOAT32_C(  -122.49), SIMDE_FLOAT32_C(  -413.66) },
      { SIMDE_FLOAT32_C(   822.68), SIMDE_FLOAT32_C(   828.08), SIMDE_FLOAT32_C(  -654.36), SIMDE_FLOAT32_C(  -841.52) } },
    { { SIMDE_FLOAT32_C(    -4.35), SIMDE_FLOAT32_C(  -578.87), SIMDE_FLOAT32_C(   948.39), SIMDE_FLOAT32_C(  -374.97) },
      { SIMDE_FLOAT32_C(  -392.78), SIMDE_FLOAT32_C(   419.28), SIMDE_FLOAT32_C(  -535.17), SIMDE_FLOAT32_C(   181.27) },
      { SIMDE_FLOAT32_C(     4.35), SIMDE_FLOAT32_C(  -578.87), SIMDE_FLOAT32_C(  -948.39), SIMDE_FLOAT32_C(  -374.97) } },
    { { SIMDE_FLOAT32_C(  -673.33), SIMDE_FLOAT32_C(   213.51), SIMDE_FLOAT32_C(    -5.42), SIMDE_FLOAT32_C(  -104.15) },
      { SIMDE_FLOAT32_C(  -569.73), SIMDE_FLOAT32_C(  -167.30), SIMDE_FLOAT32_C(  -791.72), SIMDE_FLOAT32_C(  -294.96) },
      { SIMDE_FLOAT32_C(   673.33), SIMDE_FLOAT32_C(  -213.51), SIMDE_FLOAT32_C(     5.42), SIMDE_FLOAT32_C(   104.15) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_x_mm_xorsign_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_cvt_pi2ps(SIMDE_MUNIT_TEST_ARGS) {

  const struct {
    simde__m128 a;
    simde__m64 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -480.01), SIMDE_FLOAT32_C(   184.13), SIMDE_FLOAT32_C(   826.50), SIMDE_FLOAT32_C(  -461.15)),
      simde_mm_set_pi32(INT32_C(        136), INT32_C(       -836)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -480.01), SIMDE_FLOAT32_C(   184.13), SIMDE_FLOAT32_C(   136.00), SIMDE_FLOAT32_C(  -836.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -265.13), SIMDE_FLOAT32_C(   660.82), SIMDE_FLOAT32_C(  -962.73), SIMDE_FLOAT32_C(   878.13)),
      simde_mm_set_pi32(INT32_C(       -766), INT32_C(       -811)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -265.13), SIMDE_FLOAT32_C(   660.82), SIMDE_FLOAT32_C(  -766.00), SIMDE_FLOAT32_C(  -811.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   531.34), SIMDE_FLOAT32_C(  -581.54), SIMDE_FLOAT32_C(  -290.28), SIMDE_FLOAT32_C(   767.75)),
      simde_mm_set_pi32(INT32_C(        867), INT32_C(       -379)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   531.34), SIMDE_FLOAT32_C(  -581.54), SIMDE_FLOAT32_C(   867.00), SIMDE_FLOAT32_C(  -379.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    10.42), SIMDE_FLOAT32_C(  -706.07), SIMDE_FLOAT32_C(  -747.94), SIMDE_FLOAT32_C(   462.62)),
      simde_mm_set_pi32(INT32_C(        463), INT32_C(       -757)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    10.42), SIMDE_FLOAT32_C(  -706.07), SIMDE_FLOAT32_C(   463.00), SIMDE_FLOAT32_C(  -757.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -542.71), SIMDE_FLOAT32_C(   432.33), SIMDE_FLOAT32_C(   560.90), SIMDE_FLOAT32_C(   894.98)),
      simde_mm_set_pi32(INT32_C(       -614), INT32_C(        188)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -542.71), SIMDE_FLOAT32_C(   432.33), SIMDE_FLOAT32_C(  -614.00), SIMDE_FLOAT32_C(   188.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -4.09), SIMDE_FLOAT32_C(  -652.62), SIMDE_FLOAT32_C(   136.92), SIMDE_FLOAT32_C(  -919.87)),
      simde_mm_set_pi32(INT32_C(       -944), INT32_C(       -693)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -4.09), SIMDE_FLOAT32_C(  -652.62), SIMDE_FLOAT32_C(  -944.00), SIMDE_FLOAT32_C(  -693.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -98.24), SIMDE_FLOAT32_C(  -855.63), SIMDE_FLOAT32_C(   645.40), SIMDE_FLOAT32_C(  -996.57)),
      simde_mm_set_pi32(INT32_C(       -186), INT32_C(       -809)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -98.24), SIMDE_FLOAT32_C(  -855.63), SIMDE_FLOAT32_C(  -186.00), SIMDE_FLOAT32_C(  -809.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -305.17), SIMDE_FLOAT32_C(  -762.98), SIMDE_FLOAT32_C(  -655.45), SIMDE_FLOAT32_C(  -521.87)),
      simde_mm_set_pi32(INT32_C(        481), INT32_C(        -37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -305.17), SIMDE_FLOAT32_C(  -762.98), SIMDE_FLOAT32_C(   481.00), SIMDE_FLOAT32_C(   -37.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvt_pi2ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvt_ps2pi(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   585.40), SIMDE_FLOAT32_C(  -596.31), SIMDE_FLOAT32_C(   -33.58), SIMDE_FLOAT32_C(  -973.52)),
      simde_mm_set_pi32(INT32_C(        -34), INT32_C(       -974)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   461.40), SIMDE_FLOAT32_C(  -885.65), SIMDE_FLOAT32_C(  -130.70), SIMDE_FLOAT32_C(   767.11)),
      simde_mm_set_pi32(INT32_C(       -131), INT32_C(        767)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   667.28), SIMDE_FLOAT32_C(   289.45), SIMDE_FLOAT32_C(   167.11), SIMDE_FLOAT32_C(  -820.87)),
      simde_mm_set_pi32(INT32_C(        167), INT32_C(       -821)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -445.67), SIMDE_FLOAT32_C(   116.25), SIMDE_FLOAT32_C(   836.77), SIMDE_FLOAT32_C(  -145.00)),
      simde_mm_set_pi32(INT32_C(        837), INT32_C(       -145)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   457.72), SIMDE_FLOAT32_C(  -725.98), SIMDE_FLOAT32_C(  -428.45), SIMDE_FLOAT32_C(   251.28)),
      simde_mm_set_pi32(INT32_C(       -428), INT32_C(        251)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   776.17), SIMDE_FLOAT32_C(   285.46), SIMDE_FLOAT32_C(  -148.62), SIMDE_FLOAT32_C(   251.11)),
      simde_mm_set_pi32(INT32_C(       -149), INT32_C(        251)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -758.68), SIMDE_FLOAT32_C(  -834.46), SIMDE_FLOAT32_C(   247.62), SIMDE_FLOAT32_C(   252.25)),
      simde_mm_set_pi32(INT32_C(        248), INT32_C(        252)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   185.27), SIMDE_FLOAT32_C(   -33.00), SIMDE_FLOAT32_C(   323.39), SIMDE_FLOAT32_C(   851.62)),
      simde_mm_set_pi32(INT32_C(        323), INT32_C(        852)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cvt_ps2pi(test_vec[i].a);
    simde_test_x86_assert_equal_i32x2(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvt_si2ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    int32_t b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -896.28), SIMDE_FLOAT32_C(  -653.23), SIMDE_FLOAT32_C(    62.87), SIMDE_FLOAT32_C(  -477.72)),
      INT32_C(-172),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -896.28), SIMDE_FLOAT32_C(  -653.23), SIMDE_FLOAT32_C(    62.87), SIMDE_FLOAT32_C(  -172.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   980.80), SIMDE_FLOAT32_C(   527.97), SIMDE_FLOAT32_C(  -324.27), SIMDE_FLOAT32_C(   641.93)),
      INT32_C(-906),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   980.80), SIMDE_FLOAT32_C(   527.97), SIMDE_FLOAT32_C(  -324.27), SIMDE_FLOAT32_C(  -906.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     6.14), SIMDE_FLOAT32_C(   647.61), SIMDE_FLOAT32_C(   446.77), SIMDE_FLOAT32_C(   149.50)),
      INT32_C(-312),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     6.14), SIMDE_FLOAT32_C(   647.61), SIMDE_FLOAT32_C(   446.77), SIMDE_FLOAT32_C(  -312.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   671.83), SIMDE_FLOAT32_C(   292.90), SIMDE_FLOAT32_C(   137.83), SIMDE_FLOAT32_C(   652.08)),
      INT32_C(  72),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   671.83), SIMDE_FLOAT32_C(   292.90), SIMDE_FLOAT32_C(   137.83), SIMDE_FLOAT32_C(    72.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   428.68), SIMDE_FLOAT32_C(   323.04), SIMDE_FLOAT32_C(  -369.14), SIMDE_FLOAT32_C(  -143.52)),
      INT32_C( 648),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   428.68), SIMDE_FLOAT32_C(   323.04), SIMDE_FLOAT32_C(  -369.14), SIMDE_FLOAT32_C(   648.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -834.08), SIMDE_FLOAT32_C(   861.01), SIMDE_FLOAT32_C(   -60.60), SIMDE_FLOAT32_C(  -978.47)),
      INT32_C( 327),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -834.08), SIMDE_FLOAT32_C(   861.01), SIMDE_FLOAT32_C(   -60.60), SIMDE_FLOAT32_C(   327.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -462.87), SIMDE_FLOAT32_C(   -82.73), SIMDE_FLOAT32_C(   641.71), SIMDE_FLOAT32_C(   690.58)),
      INT32_C(  78),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -462.87), SIMDE_FLOAT32_C(   -82.73), SIMDE_FLOAT32_C(   641.71), SIMDE_FLOAT32_C(    78.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -896.41), SIMDE_FLOAT32_C(  -179.07), SIMDE_FLOAT32_C(  -535.21), SIMDE_FLOAT32_C(   722.87)),
      INT32_C(-106),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -896.41), SIMDE_FLOAT32_C(  -179.07), SIMDE_FLOAT32_C(  -535.21), SIMDE_FLOAT32_C(  -106.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvt_si2ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvt_ss2si (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -434.80), SIMDE_FLOAT32_C(   718.49), SIMDE_FLOAT32_C(  -765.08) },
                 INT32_MIN },
    { {           -SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   610.10),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -238.39) },
                 INT32_MIN },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(float, INT32_MAX), SIMDE_FLOAT32_C(   264.19), SIMDE_FLOAT32_C(  -247.70), SIMDE_FLOAT32_C(  -466.34) },
                 INT32_MIN },
    { { HEDLEY_STATIC_CAST(float, INT32_MIN), SIMDE_FLOAT32_C(  -656.10), SIMDE_FLOAT32_C(   528.97), SIMDE_FLOAT32_C(  -664.65) },
      -INT32_C(  2147483648) },
    { { HEDLEY_STATIC_CAST(float, INT32_MAX - 100), SIMDE_FLOAT32_C(  -572.40), SIMDE_FLOAT32_C(   986.43), SIMDE_FLOAT32_C(   789.86) },
       INT32_C(  2147483520) },
    { { HEDLEY_STATIC_CAST(float, INT32_MIN + 100), SIMDE_FLOAT32_C(  -226.55), SIMDE_FLOAT32_C(  -926.20), SIMDE_FLOAT32_C(   130.01) },
      -INT32_C(  2147483520) },
    #endif
    { { SIMDE_FLOAT32_C(   555.67), SIMDE_FLOAT32_C(   330.04), SIMDE_FLOAT32_C(  -110.18), SIMDE_FLOAT32_C(   679.85) },
       INT32_C(         556) },
    { { SIMDE_FLOAT32_C(   809.05), SIMDE_FLOAT32_C(  -456.06), SIMDE_FLOAT32_C(   886.35), SIMDE_FLOAT32_C(   696.23) },
       INT32_C(         809) },
    { { SIMDE_FLOAT32_C(  -676.99), SIMDE_FLOAT32_C(   517.95), SIMDE_FLOAT32_C(   287.44), SIMDE_FLOAT32_C(  -885.31) },
      -INT32_C(         677) },
    { { SIMDE_FLOAT32_C(  -202.79), SIMDE_FLOAT32_C(    24.50), SIMDE_FLOAT32_C(   108.39), SIMDE_FLOAT32_C(  -810.69) },
      -INT32_C(         203) },
    { { SIMDE_FLOAT32_C(  -214.44), SIMDE_FLOAT32_C(   248.05), SIMDE_FLOAT32_C(  -729.85), SIMDE_FLOAT32_C(  -886.40) },
      -INT32_C(         214) },
    { { SIMDE_FLOAT32_C(  -238.22), SIMDE_FLOAT32_C(  -190.61), SIMDE_FLOAT32_C(   -31.58), SIMDE_FLOAT32_C(  -490.90) },
      -INT32_C(         238) },
    { { SIMDE_FLOAT32_C(    86.03), SIMDE_FLOAT32_C(   720.06), SIMDE_FLOAT32_C(   886.14), SIMDE_FLOAT32_C(  -649.64) },
       INT32_C(          86) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    int32_t r = simde_mm_cvt_ss2si(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtpi16_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-11158), INT16_C(-16899), INT16_C( 32486), INT16_C( 25075)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-11158.00), SIMDE_FLOAT32_C(-16899.00), SIMDE_FLOAT32_C( 32486.00), SIMDE_FLOAT32_C( 25075.00)) },
    { simde_mm_set_pi16(INT16_C(-26366), INT16_C(-24687), INT16_C(-32040), INT16_C( -8761)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-26366.00), SIMDE_FLOAT32_C(-24687.00), SIMDE_FLOAT32_C(-32040.00), SIMDE_FLOAT32_C( -8761.00)) },
    { simde_mm_set_pi16(INT16_C(   472), INT16_C( 26905), INT16_C(-13169), INT16_C(  3569)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   472.00), SIMDE_FLOAT32_C( 26905.00), SIMDE_FLOAT32_C(-13169.00), SIMDE_FLOAT32_C(  3569.00)) },
    { simde_mm_set_pi16(INT16_C( 29219), INT16_C( -2558), INT16_C( 15879), INT16_C( 28507)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 29219.00), SIMDE_FLOAT32_C( -2558.00), SIMDE_FLOAT32_C( 15879.00), SIMDE_FLOAT32_C( 28507.00)) },
    { simde_mm_set_pi16(INT16_C( 29483), INT16_C( 27189), INT16_C(  5847), INT16_C(  7015)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 29483.00), SIMDE_FLOAT32_C( 27189.00), SIMDE_FLOAT32_C(  5847.00), SIMDE_FLOAT32_C(  7015.00)) },
    { simde_mm_set_pi16(INT16_C(-26392), INT16_C(-23898), INT16_C( -5838), INT16_C(-12444)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-26392.00), SIMDE_FLOAT32_C(-23898.00), SIMDE_FLOAT32_C( -5838.00), SIMDE_FLOAT32_C(-12444.00)) },
    { simde_mm_set_pi16(INT16_C( 16651), INT16_C(-25505), INT16_C(-23268), INT16_C( 15044)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 16651.00), SIMDE_FLOAT32_C(-25505.00), SIMDE_FLOAT32_C(-23268.00), SIMDE_FLOAT32_C( 15044.00)) },
    { simde_mm_set_pi16(INT16_C( 18794), INT16_C( 24463), INT16_C( -7002), INT16_C(-17845)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 18794.00), SIMDE_FLOAT32_C( 24463.00), SIMDE_FLOAT32_C( -7002.00), SIMDE_FLOAT32_C(-17845.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtpi16_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtpi32_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m64 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   143.12), SIMDE_FLOAT32_C(   382.05), SIMDE_FLOAT32_C(  -756.03), SIMDE_FLOAT32_C(   501.27)),
      simde_mm_set_pi32(INT32_C(        747), INT32_C(       -200)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   143.12), SIMDE_FLOAT32_C(   382.05), SIMDE_FLOAT32_C(   747.00), SIMDE_FLOAT32_C(  -200.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   972.78), SIMDE_FLOAT32_C(  -402.40), SIMDE_FLOAT32_C(   516.01), SIMDE_FLOAT32_C(   710.18)),
      simde_mm_set_pi32(INT32_C(        533), INT32_C(       -843)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   972.78), SIMDE_FLOAT32_C(  -402.40), SIMDE_FLOAT32_C(   533.00), SIMDE_FLOAT32_C(  -843.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   472.16), SIMDE_FLOAT32_C(  -696.64), SIMDE_FLOAT32_C(  -295.14), SIMDE_FLOAT32_C(   252.19)),
      simde_mm_set_pi32(INT32_C(       -428), INT32_C(        182)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   472.16), SIMDE_FLOAT32_C(  -696.64), SIMDE_FLOAT32_C(  -428.00), SIMDE_FLOAT32_C(   182.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -566.65), SIMDE_FLOAT32_C(   623.99), SIMDE_FLOAT32_C(   879.56), SIMDE_FLOAT32_C(   610.97)),
      simde_mm_set_pi32(INT32_C(        176), INT32_C(        681)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -566.65), SIMDE_FLOAT32_C(   623.99), SIMDE_FLOAT32_C(   176.00), SIMDE_FLOAT32_C(   681.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   572.11), SIMDE_FLOAT32_C(  -357.92), SIMDE_FLOAT32_C(   212.83), SIMDE_FLOAT32_C(   936.07)),
      simde_mm_set_pi32(INT32_C(       -310), INT32_C(        515)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   572.11), SIMDE_FLOAT32_C(  -357.92), SIMDE_FLOAT32_C(  -310.00), SIMDE_FLOAT32_C(   515.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   696.01), SIMDE_FLOAT32_C(  -960.55), SIMDE_FLOAT32_C(  -478.31), SIMDE_FLOAT32_C(  -831.25)),
      simde_mm_set_pi32(INT32_C(        324), INT32_C(        -65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   696.01), SIMDE_FLOAT32_C(  -960.55), SIMDE_FLOAT32_C(   324.00), SIMDE_FLOAT32_C(   -65.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -973.73), SIMDE_FLOAT32_C(   578.94), SIMDE_FLOAT32_C(   658.26), SIMDE_FLOAT32_C(   635.66)),
      simde_mm_set_pi32(INT32_C(       -268), INT32_C(        691)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -973.73), SIMDE_FLOAT32_C(   578.94), SIMDE_FLOAT32_C(  -268.00), SIMDE_FLOAT32_C(   691.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   654.54), SIMDE_FLOAT32_C(  -615.74), SIMDE_FLOAT32_C(  -430.24), SIMDE_FLOAT32_C(   224.63)),
      simde_mm_set_pi32(INT32_C(        370), INT32_C(       -505)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   654.54), SIMDE_FLOAT32_C(  -615.74), SIMDE_FLOAT32_C(   370.00), SIMDE_FLOAT32_C(  -505.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtpi32_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtpi32x2_ps(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    simde_float32 r[4];
  } test_vec[] = {
   { {  INT32_C(     46384),  INT32_C(     57201) },
      {  INT32_C(     54113),  INT32_C(     10228) },
      { SIMDE_FLOAT32_C( 46384.00), SIMDE_FLOAT32_C( 57201.00), SIMDE_FLOAT32_C( 54113.00), SIMDE_FLOAT32_C( 10228.00) } },
    { {  INT32_C(     15587),  INT32_C(      1419) },
      {  INT32_C(     22490),  INT32_C(      4374) },
      { SIMDE_FLOAT32_C( 15587.00), SIMDE_FLOAT32_C(  1419.00), SIMDE_FLOAT32_C( 22490.00), SIMDE_FLOAT32_C(  4374.00) } },
    { {  INT32_C(     18119),  INT32_C(     48934) },
      {  INT32_C(     35218),  INT32_C(     42416) },
      { SIMDE_FLOAT32_C( 18119.00), SIMDE_FLOAT32_C( 48934.00), SIMDE_FLOAT32_C( 35218.00), SIMDE_FLOAT32_C( 42416.00) } },
    { {  INT32_C(     38881),  INT32_C(     38044) },
      {  INT32_C(     13548),  INT32_C(     56134) },
      { SIMDE_FLOAT32_C( 38881.00), SIMDE_FLOAT32_C( 38044.00), SIMDE_FLOAT32_C( 13548.00), SIMDE_FLOAT32_C( 56134.00) } },
    { {  INT32_C(     58145),  INT32_C(     18338) },
      {  INT32_C(     47824),  INT32_C(     39776) },
      { SIMDE_FLOAT32_C( 58145.00), SIMDE_FLOAT32_C( 18338.00), SIMDE_FLOAT32_C( 47824.00), SIMDE_FLOAT32_C( 39776.00) } },
    { {  INT32_C(     29235),  INT32_C(     49415) },
      {  INT32_C(     52982),  INT32_C(     16041) },
      { SIMDE_FLOAT32_C( 29235.00), SIMDE_FLOAT32_C( 49415.00), SIMDE_FLOAT32_C( 52982.00), SIMDE_FLOAT32_C( 16041.00) } },
    { {  INT32_C(     36386),  INT32_C(     57813) },
      {  INT32_C(     46492),  INT32_C(     15185) },
      { SIMDE_FLOAT32_C( 36386.00), SIMDE_FLOAT32_C( 57813.00), SIMDE_FLOAT32_C( 46492.00), SIMDE_FLOAT32_C( 15185.00) } },
    { {  INT32_C(     60590),  INT32_C(     39597) },
      {  INT32_C(     40296),  INT32_C(     10460) },
      { SIMDE_FLOAT32_C( 60590.00), SIMDE_FLOAT32_C( 39597.00), SIMDE_FLOAT32_C( 40296.00), SIMDE_FLOAT32_C( 10460.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m64 a, b;
    simde__m128 e;
    simde_memcpy(&a, test_vec[i].a, sizeof(a));
    simde_memcpy(&b, test_vec[i].b, sizeof(a));
    simde_memcpy(&e, test_vec[i].r, sizeof(e));
    simde__m128 r = simde_mm_cvtpi32x2_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, e, 1);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_cvtpi8_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C( -61), INT8_C(  15), INT8_C(  46), INT8_C(  20),
                       INT8_C(  68), INT8_C(  82), INT8_C(  13), INT8_C( 113)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    68.00), SIMDE_FLOAT32_C(    82.00), SIMDE_FLOAT32_C(    13.00), SIMDE_FLOAT32_C(   113.00)) },
    { simde_mm_set_pi8(INT8_C(  67), INT8_C( -77), INT8_C(  44), INT8_C( -51),
                       INT8_C(  66), INT8_C(  66), INT8_C(-123), INT8_C(  31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    66.00), SIMDE_FLOAT32_C(    66.00), SIMDE_FLOAT32_C(  -123.00), SIMDE_FLOAT32_C(    31.00)) },
    { simde_mm_set_pi8(INT8_C( -62), INT8_C(  28), INT8_C( -11), INT8_C( -61),
                       INT8_C( -61), INT8_C(-110), INT8_C( -20), INT8_C( -51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -61.00), SIMDE_FLOAT32_C(  -110.00), SIMDE_FLOAT32_C(   -20.00), SIMDE_FLOAT32_C(   -51.00)) },
    { simde_mm_set_pi8(INT8_C( -63), INT8_C( -73), INT8_C(  71), INT8_C( -82),
                       INT8_C(  68), INT8_C(  25), INT8_C(-121), INT8_C( -82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    68.00), SIMDE_FLOAT32_C(    25.00), SIMDE_FLOAT32_C(  -121.00), SIMDE_FLOAT32_C(   -82.00)) },
    { simde_mm_set_pi8(INT8_C(  66), INT8_C( -52), INT8_C(-113), INT8_C(  92),
                       INT8_C(  68), INT8_C(  36), INT8_C( -82), INT8_C(  20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    68.00), SIMDE_FLOAT32_C(    36.00), SIMDE_FLOAT32_C(   -82.00), SIMDE_FLOAT32_C(    20.00)) },
    { simde_mm_set_pi8(INT8_C( -62), INT8_C(  34), INT8_C( -41), INT8_C(  10),
                       INT8_C(  68), INT8_C(  34), INT8_C( -68), INT8_C( -51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    68.00), SIMDE_FLOAT32_C(    34.00), SIMDE_FLOAT32_C(   -68.00), SIMDE_FLOAT32_C(   -51.00)) },
    { simde_mm_set_pi8(INT8_C(  67), INT8_C( 107), INT8_C(-121), INT8_C( -82),
                       INT8_C( -60), INT8_C( 116), INT8_C( -88), INT8_C( -10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -60.00), SIMDE_FLOAT32_C(   116.00), SIMDE_FLOAT32_C(   -88.00), SIMDE_FLOAT32_C(   -10.00)) },
    { simde_mm_set_pi8(INT8_C( -61), INT8_C(  67), INT8_C(  -6), INT8_C( -31),
                       INT8_C( -61), INT8_C(-115), INT8_C( -82), INT8_C(  20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -61.00), SIMDE_FLOAT32_C(  -115.00), SIMDE_FLOAT32_C(   -82.00), SIMDE_FLOAT32_C(    20.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtpi8_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtps_pi16(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -263.01), SIMDE_FLOAT32_C(   371.44), SIMDE_FLOAT32_C(  -589.91), SIMDE_FLOAT32_C(  -375.58) },
      { -INT16_C(  263),  INT16_C(  371), -INT16_C(  590), -INT16_C(  376) } },
    { { SIMDE_FLOAT32_C(   317.69), SIMDE_FLOAT32_C(  -570.66), SIMDE_FLOAT32_C(  -267.81), SIMDE_FLOAT32_C(   844.93) },
      {  INT16_C(  318), -INT16_C(  571), -INT16_C(  268),  INT16_C(  845) } },
    { { SIMDE_FLOAT32_C(   295.60), SIMDE_FLOAT32_C(   531.31), SIMDE_FLOAT32_C(   524.76), SIMDE_FLOAT32_C(   178.54) },
      {  INT16_C(  296),  INT16_C(  531),  INT16_C(  525),  INT16_C(  179) } },
    { { SIMDE_FLOAT32_C(  -332.79), SIMDE_FLOAT32_C(  -873.21), SIMDE_FLOAT32_C(  -995.14), SIMDE_FLOAT32_C(   991.60) },
      { -INT16_C(  333), -INT16_C(  873), -INT16_C(  995),  INT16_C(  992) } },
    { { SIMDE_FLOAT32_C(  -312.48), SIMDE_FLOAT32_C(  -321.64), SIMDE_FLOAT32_C(   146.29), SIMDE_FLOAT32_C(   734.78) },
      { -INT16_C(  312), -INT16_C(  322),  INT16_C(  146),  INT16_C(  735) } },
    { { SIMDE_FLOAT32_C(  -467.86), SIMDE_FLOAT32_C(  -597.35), SIMDE_FLOAT32_C(   676.08), SIMDE_FLOAT32_C(   861.72) },
      { -INT16_C(  468), -INT16_C(  597),  INT16_C(  676),  INT16_C(  862) } },
    { { SIMDE_FLOAT32_C(  -765.08), SIMDE_FLOAT32_C(  -574.12), SIMDE_FLOAT32_C(    36.42), SIMDE_FLOAT32_C(   212.73) },
      { -INT16_C(  765), -INT16_C(  574),  INT16_C(   36),  INT16_C(  213) } },
    { { SIMDE_FLOAT32_C(   564.76), SIMDE_FLOAT32_C(  -219.68), SIMDE_FLOAT32_C(   291.77), SIMDE_FLOAT32_C(  -698.25) },
      {  INT16_C(  565), -INT16_C(  220),  INT16_C(  292), -INT16_C(  698) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128
      a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m64
      r = simde_mm_cvtps_pi16(a);
    simde__m64 e;
    simde_memcpy(&e, &(test_vec[i].r), sizeof(e));
    simde_test_x86_assert_equal_i16x4(r, e);
  }

  return 0;
}

static int
test_simde_mm_cvtps_pi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   718.49), SIMDE_FLOAT32_C(  -765.08) },
      {              INT32_MIN,              INT32_MIN } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(float, INT32_MAX), HEDLEY_STATIC_CAST(float, INT32_MAX - 100), SIMDE_FLOAT32_C(   729.56), SIMDE_FLOAT32_C(   -32.75) },
      {              INT32_MIN,  INT32_C(  2147483520) } },
    { { HEDLEY_STATIC_CAST(float, INT32_MIN), HEDLEY_STATIC_CAST(float, INT32_MIN + 100), SIMDE_FLOAT32_C(  -402.31), SIMDE_FLOAT32_C(  -757.67) },
      {              INT32_MIN, -INT32_C(  2147483520) } },
    #endif
    { { SIMDE_FLOAT32_C(   954.39), SIMDE_FLOAT32_C(  -602.35), SIMDE_FLOAT32_C(  -802.59), SIMDE_FLOAT32_C(   470.56) },
      {  INT32_C(         954), -INT32_C(         602) } },
    { { SIMDE_FLOAT32_C(  -253.18), SIMDE_FLOAT32_C(   950.24), SIMDE_FLOAT32_C(   -57.78), SIMDE_FLOAT32_C(   758.15) },
      { -INT32_C(         253),  INT32_C(         950) } },
    { { SIMDE_FLOAT32_C(   856.62), SIMDE_FLOAT32_C(   127.52), SIMDE_FLOAT32_C(   286.18), SIMDE_FLOAT32_C(  -453.57) },
      {  INT32_C(         857),  INT32_C(         128) } },
    { { SIMDE_FLOAT32_C(   420.35), SIMDE_FLOAT32_C(   737.11), SIMDE_FLOAT32_C(  -767.49), SIMDE_FLOAT32_C(   960.69) },
      {  INT32_C(         420),  INT32_C(         737) } },
    { { SIMDE_FLOAT32_C(  -116.84), SIMDE_FLOAT32_C(   629.86), SIMDE_FLOAT32_C(    88.62), SIMDE_FLOAT32_C(   485.45) },
      { -INT32_C(         117),  INT32_C(         630) } },
    { { SIMDE_FLOAT32_C(  -731.19), SIMDE_FLOAT32_C(   307.46), SIMDE_FLOAT32_C(   739.75), SIMDE_FLOAT32_C(  -587.43) },
      { -INT32_C(         731),  INT32_C(         307) } },
    { { SIMDE_FLOAT32_C(   269.00), SIMDE_FLOAT32_C(   633.12), SIMDE_FLOAT32_C(  -560.38), SIMDE_FLOAT32_C(  -888.86) },
      {  INT32_C(         269),  INT32_C(         633) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m64 r = simde_mm_cvtps_pi32(a);
    simde_test_x86_assert_equal_i32x2(r, simde_x_mm_loadu_si64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvtps_pi8(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    int8_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -89.74), SIMDE_FLOAT32_C(    -2.76), SIMDE_FLOAT32_C(   -28.75), SIMDE_FLOAT32_C(    92.62) },
      { -INT8_C( 90), -INT8_C(  3), -INT8_C( 29),  INT8_C( 93),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(  -146.68), SIMDE_FLOAT32_C(  -116.78), SIMDE_FLOAT32_C(   176.97), SIMDE_FLOAT32_C(     5.88) },
      {     INT8_MIN, -INT8_C(117),     INT8_MAX,  INT8_C(  6),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(   159.51), SIMDE_FLOAT32_C(    49.64), SIMDE_FLOAT32_C(   160.41), SIMDE_FLOAT32_C(  -150.16) },
      {     INT8_MAX,  INT8_C( 50),     INT8_MAX,     INT8_MIN,  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(  -127.96), SIMDE_FLOAT32_C(   -30.84), SIMDE_FLOAT32_C(   119.71), SIMDE_FLOAT32_C(    85.16) },
      {     INT8_MIN, -INT8_C( 31),  INT8_C(120),  INT8_C( 85),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(   102.72), SIMDE_FLOAT32_C(   170.20), SIMDE_FLOAT32_C(  -183.68), SIMDE_FLOAT32_C(   -37.32) },
      {  INT8_C(103),     INT8_MAX,     INT8_MIN, -INT8_C( 37),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(   167.11), SIMDE_FLOAT32_C(    58.87), SIMDE_FLOAT32_C(   128.98), SIMDE_FLOAT32_C(  -160.55) },
      {     INT8_MAX,  INT8_C( 59),     INT8_MAX,     INT8_MIN,  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(  -151.25), SIMDE_FLOAT32_C(   -18.20), SIMDE_FLOAT32_C(   157.11), SIMDE_FLOAT32_C(   162.11) },
      {     INT8_MIN, -INT8_C( 18),     INT8_MAX,     INT8_MAX,  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } },
    { { SIMDE_FLOAT32_C(  -188.54), SIMDE_FLOAT32_C(  -194.06), SIMDE_FLOAT32_C(   -85.40), SIMDE_FLOAT32_C(   -78.27) },
      {     INT8_MIN,     INT8_MIN, -INT8_C( 85), -INT8_C( 78),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0),  INT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m64 r = simde_mm_cvtps_pi8(simde_mm_loadu_ps(test_vec[i].a));

    /* The upper half is undefined */
    int8_t r_[8];
    simde_memcpy(r_, &r, sizeof(r));
    simde_assert_equal_vi8(4, r_, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtpu16_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { -INT16_C( 15210), -INT16_C(   656),  INT16_C( 21841), -INT16_C(  5069) },
      { SIMDE_FLOAT32_C( 50326.00), SIMDE_FLOAT32_C( 64880.00), SIMDE_FLOAT32_C( 21841.00), SIMDE_FLOAT32_C( 60467.00) } },
    { { -INT16_C( 19160), -INT16_C( 18589),  INT16_C( 31824),  INT16_C( 28058) },
      { SIMDE_FLOAT32_C( 46376.00), SIMDE_FLOAT32_C( 46947.00), SIMDE_FLOAT32_C( 31824.00), SIMDE_FLOAT32_C( 28058.00) } },
    { { -INT16_C( 25235), -INT16_C( 26832),  INT16_C( 23207),  INT16_C( 24159) },
      { SIMDE_FLOAT32_C( 40301.00), SIMDE_FLOAT32_C( 38704.00), SIMDE_FLOAT32_C( 23207.00), SIMDE_FLOAT32_C( 24159.00) } },
    { {  INT16_C( 19021), -INT16_C( 32629),  INT16_C(  1472),  INT16_C( 22326) },
      { SIMDE_FLOAT32_C( 19021.00), SIMDE_FLOAT32_C( 32907.00), SIMDE_FLOAT32_C(  1472.00), SIMDE_FLOAT32_C( 22326.00) } },
    { { -INT16_C( 22839),  INT16_C(  6740), -INT16_C( 30725),  INT16_C(  9223) },
      { SIMDE_FLOAT32_C( 42697.00), SIMDE_FLOAT32_C(  6740.00), SIMDE_FLOAT32_C( 34811.00), SIMDE_FLOAT32_C(  9223.00) } },
    { {  INT16_C( 27197), -INT16_C( 29221),  INT16_C( 30438),  INT16_C( 21498) },
      { SIMDE_FLOAT32_C( 27197.00), SIMDE_FLOAT32_C( 36315.00), SIMDE_FLOAT32_C( 30438.00), SIMDE_FLOAT32_C( 21498.00) } },
    { {  INT16_C( 11027), -INT16_C( 17685),  INT16_C( 19077), -INT16_C( 11752) },
      { SIMDE_FLOAT32_C( 11027.00), SIMDE_FLOAT32_C( 47851.00), SIMDE_FLOAT32_C( 19077.00), SIMDE_FLOAT32_C( 53784.00) } },
    { { -INT16_C( 23660),  INT16_C( 21842), -INT16_C( 30551),  INT16_C( 29356) },
      { SIMDE_FLOAT32_C( 41876.00), SIMDE_FLOAT32_C( 21842.00), SIMDE_FLOAT32_C( 34985.00), SIMDE_FLOAT32_C( 29356.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m64 a = simde_x_mm_loadu_si64(test_vec[i].a);
    simde__m128 r = simde_mm_cvtpu16_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_cvtpu8_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t a[8];
    const simde_float32 r[4];
  } test_vec[] = {
    { {  INT8_C( 101),  INT8_C(  32), -INT8_C(  83), -INT8_C(  19),  INT8_C(  16),  INT8_C(  50), -INT8_C( 116), -INT8_C(  15) },
      { SIMDE_FLOAT32_C(   101.00), SIMDE_FLOAT32_C(    32.00), SIMDE_FLOAT32_C(   173.00), SIMDE_FLOAT32_C(   237.00) } },
    { { -INT8_C(   5), -INT8_C(  57), -INT8_C(  74), -INT8_C(   2), -INT8_C( 118),  INT8_C(  93), -INT8_C(  14), -INT8_C(  86) },
      { SIMDE_FLOAT32_C(   251.00), SIMDE_FLOAT32_C(   199.00), SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(   254.00) } },
    { {  INT8_C(  54), -INT8_C(  97), -INT8_C( 126),  INT8_C(  51), -INT8_C(   9),  INT8_C(  72),  INT8_C(   9), -INT8_C( 127) },
      { SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   159.00), SIMDE_FLOAT32_C(   130.00), SIMDE_FLOAT32_C(    51.00) } },
    { { -INT8_C( 100), -INT8_C(  20),  INT8_C(   7), -INT8_C(  64),  INT8_C( 114),  INT8_C(  84),  INT8_C( 108), -INT8_C(  41) },
      { SIMDE_FLOAT32_C(   156.00), SIMDE_FLOAT32_C(   236.00), SIMDE_FLOAT32_C(     7.00), SIMDE_FLOAT32_C(   192.00) } },
    { {  INT8_C( 116),  INT8_C(  26), -INT8_C(  60), -INT8_C( 123),  INT8_C(  76),  INT8_C(  80),  INT8_C( 118),  INT8_C(  71) },
      { SIMDE_FLOAT32_C(   116.00), SIMDE_FLOAT32_C(    26.00), SIMDE_FLOAT32_C(   196.00), SIMDE_FLOAT32_C(   133.00) } },
    { {  INT8_C(  24),  INT8_C(  44),  INT8_C(  70), -INT8_C(  94), -INT8_C( 119),  INT8_C(  56),  INT8_C(  76), -INT8_C(  65) },
      { SIMDE_FLOAT32_C(    24.00), SIMDE_FLOAT32_C(    44.00), SIMDE_FLOAT32_C(    70.00), SIMDE_FLOAT32_C(   162.00) } },
    { { -INT8_C(  40), -INT8_C(  49), -INT8_C(  13), -INT8_C(  49),  INT8_C(  23), -INT8_C(   4),  INT8_C(  80), -INT8_C(  77) },
      { SIMDE_FLOAT32_C(   216.00), SIMDE_FLOAT32_C(   207.00), SIMDE_FLOAT32_C(   243.00), SIMDE_FLOAT32_C(   207.00) } },
    { { -INT8_C(  24),  INT8_C(  88),  INT8_C( 115),  INT8_C(  91), -INT8_C(  84), -INT8_C(  32),  INT8_C(  50),  INT8_C(  32) },
      { SIMDE_FLOAT32_C(   232.00), SIMDE_FLOAT32_C(    88.00), SIMDE_FLOAT32_C(   115.00), SIMDE_FLOAT32_C(    91.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m64 a = simde_x_mm_loadu_si64(test_vec[i].a);
    simde__m128 r = simde_mm_cvtpu8_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_cvtsi32_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    int32_t b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -368.26), SIMDE_FLOAT32_C(  -772.15), SIMDE_FLOAT32_C(   700.78), SIMDE_FLOAT32_C(  -416.87)),
      INT32_C(     -93207),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -368.26), SIMDE_FLOAT32_C(  -772.15), SIMDE_FLOAT32_C(   700.78), SIMDE_FLOAT32_C(-93207.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   774.49), SIMDE_FLOAT32_C(   920.32), SIMDE_FLOAT32_C(   159.83), SIMDE_FLOAT32_C(  -900.78)),
      INT32_C(     -99810),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   774.49), SIMDE_FLOAT32_C(   920.32), SIMDE_FLOAT32_C(   159.83), SIMDE_FLOAT32_C(-99810.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -606.72), SIMDE_FLOAT32_C(  -127.65), SIMDE_FLOAT32_C(  -336.22), SIMDE_FLOAT32_C(  -528.09)),
      INT32_C(     -24917),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -606.72), SIMDE_FLOAT32_C(  -127.65), SIMDE_FLOAT32_C(  -336.22), SIMDE_FLOAT32_C(-24917.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   534.13), SIMDE_FLOAT32_C(  -401.63), SIMDE_FLOAT32_C(  -949.41), SIMDE_FLOAT32_C(   -38.28)),
      INT32_C(     -25377),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   534.13), SIMDE_FLOAT32_C(  -401.63), SIMDE_FLOAT32_C(  -949.41), SIMDE_FLOAT32_C(-25377.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   704.87), SIMDE_FLOAT32_C(   236.14), SIMDE_FLOAT32_C(   -91.25), SIMDE_FLOAT32_C(  -708.13)),
      INT32_C(      83867),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   704.87), SIMDE_FLOAT32_C(   236.14), SIMDE_FLOAT32_C(   -91.25), SIMDE_FLOAT32_C( 83867.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   570.72), SIMDE_FLOAT32_C(  -412.30), SIMDE_FLOAT32_C(  -578.88), SIMDE_FLOAT32_C(   196.41)),
      INT32_C(      72066),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   570.72), SIMDE_FLOAT32_C(  -412.30), SIMDE_FLOAT32_C(  -578.88), SIMDE_FLOAT32_C( 72066.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   891.77), SIMDE_FLOAT32_C(  -473.67), SIMDE_FLOAT32_C(   332.65), SIMDE_FLOAT32_C(  -615.45)),
      INT32_C(      12054),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   891.77), SIMDE_FLOAT32_C(  -473.67), SIMDE_FLOAT32_C(   332.65), SIMDE_FLOAT32_C( 12054.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -552.37), SIMDE_FLOAT32_C(  -873.85), SIMDE_FLOAT32_C(   968.75), SIMDE_FLOAT32_C(  -669.38)),
      INT32_C(      88818),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -552.37), SIMDE_FLOAT32_C(  -873.85), SIMDE_FLOAT32_C(   968.75), SIMDE_FLOAT32_C( 88818.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtsi32_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtsi64_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    int64_t b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   253.23), SIMDE_FLOAT32_C(  -834.96), SIMDE_FLOAT32_C(   -59.37), SIMDE_FLOAT32_C(  -234.88)),
      INT64_C( -400),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   253.23), SIMDE_FLOAT32_C(  -834.96), SIMDE_FLOAT32_C(   -59.37), SIMDE_FLOAT32_C(  -400.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -504.89), SIMDE_FLOAT32_C(   601.98), SIMDE_FLOAT32_C(   647.71), SIMDE_FLOAT32_C(   743.03)),
      INT64_C(  778),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -504.89), SIMDE_FLOAT32_C(   601.98), SIMDE_FLOAT32_C(   647.71), SIMDE_FLOAT32_C(   778.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -54.05), SIMDE_FLOAT32_C(  -259.82), SIMDE_FLOAT32_C(   622.33), SIMDE_FLOAT32_C(  -585.76)),
      INT64_C(  469),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -54.05), SIMDE_FLOAT32_C(  -259.82), SIMDE_FLOAT32_C(   622.33), SIMDE_FLOAT32_C(   469.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -466.68), SIMDE_FLOAT32_C(   568.80), SIMDE_FLOAT32_C(  -210.64), SIMDE_FLOAT32_C(   607.00)),
      INT64_C( -865),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -466.68), SIMDE_FLOAT32_C(   568.80), SIMDE_FLOAT32_C(  -210.64), SIMDE_FLOAT32_C(  -865.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   796.90), SIMDE_FLOAT32_C(   289.94), SIMDE_FLOAT32_C(  -605.55), SIMDE_FLOAT32_C(  -696.91)),
      INT64_C(   55),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   796.90), SIMDE_FLOAT32_C(   289.94), SIMDE_FLOAT32_C(  -605.55), SIMDE_FLOAT32_C(    55.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -322.36), SIMDE_FLOAT32_C(  -443.46), SIMDE_FLOAT32_C(   641.09), SIMDE_FLOAT32_C(   796.50)),
      INT64_C(  105),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -322.36), SIMDE_FLOAT32_C(  -443.46), SIMDE_FLOAT32_C(   641.09), SIMDE_FLOAT32_C(   105.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   797.45), SIMDE_FLOAT32_C(  -128.18), SIMDE_FLOAT32_C(  -171.74), SIMDE_FLOAT32_C(  -508.28)),
      INT64_C( -475),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   797.45), SIMDE_FLOAT32_C(  -128.18), SIMDE_FLOAT32_C(  -171.74), SIMDE_FLOAT32_C(  -475.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   301.56), SIMDE_FLOAT32_C(  -923.23), SIMDE_FLOAT32_C(   417.31), SIMDE_FLOAT32_C(   873.00)),
      INT64_C(  418),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   301.56), SIMDE_FLOAT32_C(  -923.23), SIMDE_FLOAT32_C(   417.31), SIMDE_FLOAT32_C(   418.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtsi64_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtss_f32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde_float32 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -625.65), SIMDE_FLOAT32_C(   -39.83), SIMDE_FLOAT32_C(  -796.10), SIMDE_FLOAT32_C(  -156.62)),
      SIMDE_FLOAT32_C(  -156.62) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   931.13), SIMDE_FLOAT32_C(  -382.67), SIMDE_FLOAT32_C(   930.16), SIMDE_FLOAT32_C(   630.96)),
      SIMDE_FLOAT32_C(   630.96) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   353.46), SIMDE_FLOAT32_C(   159.93), SIMDE_FLOAT32_C(   833.30), SIMDE_FLOAT32_C(  -880.80)),
      SIMDE_FLOAT32_C(  -880.80) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   198.16), SIMDE_FLOAT32_C(   987.02), SIMDE_FLOAT32_C(   469.43), SIMDE_FLOAT32_C(  -215.34)),
      SIMDE_FLOAT32_C(  -215.34) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   929.58), SIMDE_FLOAT32_C(  -288.70), SIMDE_FLOAT32_C(  -524.51), SIMDE_FLOAT32_C(  -342.93)),
      SIMDE_FLOAT32_C(  -342.93) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    83.98), SIMDE_FLOAT32_C(   604.13), SIMDE_FLOAT32_C(   826.04), SIMDE_FLOAT32_C(  -567.24)),
      SIMDE_FLOAT32_C(  -567.24) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   328.58), SIMDE_FLOAT32_C(  -935.74), SIMDE_FLOAT32_C(  -805.95), SIMDE_FLOAT32_C(   456.28)),
      SIMDE_FLOAT32_C(   456.28) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   520.91), SIMDE_FLOAT32_C(   709.50), SIMDE_FLOAT32_C(   751.51), SIMDE_FLOAT32_C(  -700.59)),
      SIMDE_FLOAT32_C(  -700.59) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r = simde_mm_cvtss_f32(test_vec[i].a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtss_si32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde_float32 r;
  } test_vec[10] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -420.84), SIMDE_FLOAT32_C(   180.64), SIMDE_FLOAT32_C(  -145.08), SIMDE_FLOAT32_C(   328.00)),
       SIMDE_FLOAT32_C(328.00) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   951.13), SIMDE_FLOAT32_C(   455.59), SIMDE_FLOAT32_C(   803.81), SIMDE_FLOAT32_C(  -553.94)),
      -SIMDE_FLOAT32_C(553.94) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -596.13), SIMDE_FLOAT32_C(  -629.54), SIMDE_FLOAT32_C(  -358.00), SIMDE_FLOAT32_C(  -173.08)),
      -SIMDE_FLOAT32_C(173.08) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   531.31), SIMDE_FLOAT32_C(  -294.53), SIMDE_FLOAT32_C(   348.93), SIMDE_FLOAT32_C(  -374.17)),
      -SIMDE_FLOAT32_C(374.17) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -5.22), SIMDE_FLOAT32_C(  -902.50), SIMDE_FLOAT32_C(   534.84), SIMDE_FLOAT32_C(   611.14)),
       SIMDE_FLOAT32_C(611.14) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   437.42), SIMDE_FLOAT32_C(   -64.33), SIMDE_FLOAT32_C(  -167.86), SIMDE_FLOAT32_C(  -495.17)),
      -SIMDE_FLOAT32_C(495.17) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   400.50), SIMDE_FLOAT32_C(   665.80), SIMDE_FLOAT32_C(   205.90), SIMDE_FLOAT32_C(   133.58)),
       SIMDE_FLOAT32_C(133.58) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   762.41), SIMDE_FLOAT32_C(  -424.85), SIMDE_FLOAT32_C(   903.51), SIMDE_FLOAT32_C(  -209.85)),
      -SIMDE_FLOAT32_C(209.85) },
    { simde_mm_set_ps(-SIMDE_FLOAT32_C(2147483650.0), -SIMDE_FLOAT32_C(2147483650.0), -SIMDE_FLOAT32_C(2147483650.0), -SIMDE_FLOAT32_C(2147483650.0)),
      -SIMDE_FLOAT32_C(2147483648.0) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( 2147483649.0), SIMDE_FLOAT32_C( 2147483649.0), SIMDE_FLOAT32_C( 2147483649.0), SIMDE_FLOAT32_C( 2147483649.0)),
       SIMDE_FLOAT32_C(2147483648.0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r = simde_mm_cvtss_f32(test_vec[i].a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtss_si64(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    int64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   432.13), SIMDE_FLOAT32_C(   656.82), SIMDE_FLOAT32_C(   -60.62), SIMDE_FLOAT32_C(   359.43) },
       INT64_C(                432) },
    { { SIMDE_FLOAT32_C(   849.69), SIMDE_FLOAT32_C(  -168.26), SIMDE_FLOAT32_C(   534.64), SIMDE_FLOAT32_C(  -909.91) },
       INT64_C(                850) },
    { { SIMDE_FLOAT32_C(  -354.33), SIMDE_FLOAT32_C(   491.23), SIMDE_FLOAT32_C(   177.36), SIMDE_FLOAT32_C(  -562.80) },
      -INT64_C(                354) },
    { { SIMDE_FLOAT32_C(  -588.89), SIMDE_FLOAT32_C(   671.54), SIMDE_FLOAT32_C(  -880.28), SIMDE_FLOAT32_C(   870.90) },
      -INT64_C(                589) },
    { { SIMDE_FLOAT32_C(   943.47), SIMDE_FLOAT32_C(   -40.20), SIMDE_FLOAT32_C(  -409.04), SIMDE_FLOAT32_C(   908.82) },
       INT64_C(                943) },
    { { SIMDE_FLOAT32_C(  -851.90), SIMDE_FLOAT32_C(   774.67), SIMDE_FLOAT32_C(  -782.48), SIMDE_FLOAT32_C(   624.28) },
      -INT64_C(                852) },
    { { SIMDE_FLOAT32_C(  -583.19), SIMDE_FLOAT32_C(  -593.84), SIMDE_FLOAT32_C(  -529.68), SIMDE_FLOAT32_C(   960.44) },
      -INT64_C(                583) },
    { { SIMDE_FLOAT32_C(  -977.60), SIMDE_FLOAT32_C(  -925.70), SIMDE_FLOAT32_C(   101.18), SIMDE_FLOAT32_C(   454.53) },
      -INT64_C(                978) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    int64_t r = simde_mm_cvtss_si64(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtt_ps2pi (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   752.47), SIMDE_FLOAT32_C(  -313.93) },
      {                  INT32_MIN,                  INT32_MIN } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(float, INT32_MAX), HEDLEY_STATIC_CAST(float, INT32_MAX - 100), SIMDE_FLOAT32_C(   635.26), SIMDE_FLOAT32_C(  -364.72) },
      {                  INT32_MIN,  INT32_C(  2147483520) } },
    { { HEDLEY_STATIC_CAST(float, INT32_MIN), HEDLEY_STATIC_CAST(float, INT32_MIN + 100), SIMDE_FLOAT32_C(  -722.55), SIMDE_FLOAT32_C(  -645.71) },
      {                  INT32_MIN, -INT32_C(  2147483520) } },
    #endif
    { { SIMDE_FLOAT32_C(   229.49), SIMDE_FLOAT32_C(  -522.02), SIMDE_FLOAT32_C(   848.45), SIMDE_FLOAT32_C(   552.88) },
      {  INT32_C(         229), -INT32_C(         522) } },
    { { SIMDE_FLOAT32_C(  -356.77), SIMDE_FLOAT32_C(  -271.27), SIMDE_FLOAT32_C(  -421.48), SIMDE_FLOAT32_C(  -727.39) },
      { -INT32_C(         356), -INT32_C(         271) } },
    { { SIMDE_FLOAT32_C(   269.10), SIMDE_FLOAT32_C(  -977.88), SIMDE_FLOAT32_C(  -217.05), SIMDE_FLOAT32_C(  -590.05) },
      {  INT32_C(         269), -INT32_C(         977) } },
    { { SIMDE_FLOAT32_C(  -562.37), SIMDE_FLOAT32_C(  -270.05), SIMDE_FLOAT32_C(   582.52), SIMDE_FLOAT32_C(  -950.27) },
      { -INT32_C(         562), -INT32_C(         270) } },
    { { SIMDE_FLOAT32_C(  -859.67), SIMDE_FLOAT32_C(   561.63), SIMDE_FLOAT32_C(  -377.72), SIMDE_FLOAT32_C(   480.02) },
      { -INT32_C(         859),  INT32_C(         561) } },
    { { SIMDE_FLOAT32_C(   582.73), SIMDE_FLOAT32_C(  -146.67), SIMDE_FLOAT32_C(  -649.38), SIMDE_FLOAT32_C(  -147.99) },
      {  INT32_C(         582), -INT32_C(         146) } },
    { { SIMDE_FLOAT32_C(  -586.20), SIMDE_FLOAT32_C(   946.33), SIMDE_FLOAT32_C(   520.10), SIMDE_FLOAT32_C(  -556.78) },
      { -INT32_C(         586),  INT32_C(         946) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m64 r = simde_mm_cvtt_ps2pi(a);
    simde_test_x86_assert_equal_i32x2(r, simde_x_mm_loadu_si64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvtt_ss2si (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -434.80), SIMDE_FLOAT32_C(   718.49), SIMDE_FLOAT32_C(  -765.08) },
                 INT32_MIN },
    { {           -SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   610.10),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -238.39) },
                 INT32_MIN },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(float, INT32_MAX), SIMDE_FLOAT32_C(   264.19), SIMDE_FLOAT32_C(  -247.70), SIMDE_FLOAT32_C(  -466.34) },
                 INT32_MIN },
    { { HEDLEY_STATIC_CAST(float, INT32_MIN), SIMDE_FLOAT32_C(  -656.10), SIMDE_FLOAT32_C(   528.97), SIMDE_FLOAT32_C(  -664.65) },
      -INT32_C(  2147483648) },
    { { HEDLEY_STATIC_CAST(float, INT32_MAX - 100), SIMDE_FLOAT32_C(  -572.40), SIMDE_FLOAT32_C(   986.43), SIMDE_FLOAT32_C(   789.86) },
       INT32_C(  2147483520) },
    { { HEDLEY_STATIC_CAST(float, INT32_MIN + 100), SIMDE_FLOAT32_C(  -226.55), SIMDE_FLOAT32_C(  -926.20), SIMDE_FLOAT32_C(   130.01) },
      -INT32_C(  2147483520) },
    #endif
    { { SIMDE_FLOAT32_C(   555.67), SIMDE_FLOAT32_C(   330.04), SIMDE_FLOAT32_C(  -110.18), SIMDE_FLOAT32_C(   679.85) },
       INT32_C(         555) },
    { { SIMDE_FLOAT32_C(   809.05), SIMDE_FLOAT32_C(  -456.06), SIMDE_FLOAT32_C(   886.35), SIMDE_FLOAT32_C(   696.23) },
       INT32_C(         809) },
    { { SIMDE_FLOAT32_C(  -676.99), SIMDE_FLOAT32_C(   517.95), SIMDE_FLOAT32_C(   287.44), SIMDE_FLOAT32_C(  -885.31) },
      -INT32_C(         676) },
    { { SIMDE_FLOAT32_C(  -202.79), SIMDE_FLOAT32_C(    24.50), SIMDE_FLOAT32_C(   108.39), SIMDE_FLOAT32_C(  -810.69) },
      -INT32_C(         202) },
    { { SIMDE_FLOAT32_C(  -214.44), SIMDE_FLOAT32_C(   248.05), SIMDE_FLOAT32_C(  -729.85), SIMDE_FLOAT32_C(  -886.40) },
      -INT32_C(         214) },
    { { SIMDE_FLOAT32_C(  -238.22), SIMDE_FLOAT32_C(  -190.61), SIMDE_FLOAT32_C(   -31.58), SIMDE_FLOAT32_C(  -490.90) },
      -INT32_C(         238) },
    { { SIMDE_FLOAT32_C(    86.03), SIMDE_FLOAT32_C(   720.06), SIMDE_FLOAT32_C(   886.14), SIMDE_FLOAT32_C(  -649.64) },
       INT32_C(          86) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    int32_t r = simde_mm_cvtt_ss2si(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvttss_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -26.30), SIMDE_FLOAT32_C(  -753.04), SIMDE_FLOAT32_C(   939.86), SIMDE_FLOAT32_C(   229.58)),
      INT64_C( 229) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -756.13), SIMDE_FLOAT32_C(  -951.35), SIMDE_FLOAT32_C(   -40.11), SIMDE_FLOAT32_C(   621.33)),
      INT64_C( 621) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -451.41), SIMDE_FLOAT32_C(    91.05), SIMDE_FLOAT32_C(  -819.88), SIMDE_FLOAT32_C(  -387.32)),
      INT64_C(-387) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -882.02), SIMDE_FLOAT32_C(  -524.02), SIMDE_FLOAT32_C(    80.52), SIMDE_FLOAT32_C(  -645.48)),
      INT64_C(-645) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -474.88), SIMDE_FLOAT32_C(   -59.96), SIMDE_FLOAT32_C(   536.08), SIMDE_FLOAT32_C(  -612.35)),
      INT64_C(-612) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -6.13), SIMDE_FLOAT32_C(   143.04), SIMDE_FLOAT32_C(   295.14), SIMDE_FLOAT32_C(   637.76)),
      INT64_C( 637) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -573.26), SIMDE_FLOAT32_C(  -332.75), SIMDE_FLOAT32_C(  -589.80), SIMDE_FLOAT32_C(    18.82)),
      INT64_C(  18) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   447.07), SIMDE_FLOAT32_C(   103.62), SIMDE_FLOAT32_C(   276.09), SIMDE_FLOAT32_C(   287.14)),
      INT64_C( 287) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvttss_si64(test_vec[i].a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_div_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   525.22), SIMDE_FLOAT32_C(   469.67), SIMDE_FLOAT32_C(   507.34), SIMDE_FLOAT32_C(  -895.29)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -817.67), SIMDE_FLOAT32_C(   254.19), SIMDE_FLOAT32_C(   275.30), SIMDE_FLOAT32_C(   248.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     1.85), SIMDE_FLOAT32_C(     1.84), SIMDE_FLOAT32_C(    -3.61)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   718.98), SIMDE_FLOAT32_C(   567.01), SIMDE_FLOAT32_C(  -547.97), SIMDE_FLOAT32_C(  -853.48)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -930.62), SIMDE_FLOAT32_C(  -977.41), SIMDE_FLOAT32_C(   357.59), SIMDE_FLOAT32_C(  -240.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(    -1.53), SIMDE_FLOAT32_C(     3.55)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   987.48), SIMDE_FLOAT32_C(    42.26), SIMDE_FLOAT32_C(  -181.92), SIMDE_FLOAT32_C(   184.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -876.49), SIMDE_FLOAT32_C(  -490.31), SIMDE_FLOAT32_C(   841.85), SIMDE_FLOAT32_C(    60.02)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -1.13), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(     3.07)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -613.04), SIMDE_FLOAT32_C(  -465.73), SIMDE_FLOAT32_C(   556.95), SIMDE_FLOAT32_C(   817.86)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -116.73), SIMDE_FLOAT32_C(  -977.12), SIMDE_FLOAT32_C(   568.77), SIMDE_FLOAT32_C(   558.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     5.25), SIMDE_FLOAT32_C(     0.48), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     1.46)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -672.76), SIMDE_FLOAT32_C(   393.57), SIMDE_FLOAT32_C(  -393.40), SIMDE_FLOAT32_C(  -853.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -888.73), SIMDE_FLOAT32_C(  -177.78), SIMDE_FLOAT32_C(   921.78), SIMDE_FLOAT32_C(   898.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(    -2.21), SIMDE_FLOAT32_C(    -0.43), SIMDE_FLOAT32_C(    -0.95)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   128.49), SIMDE_FLOAT32_C(  -969.45), SIMDE_FLOAT32_C(   460.39), SIMDE_FLOAT32_C(   323.29)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -32.22), SIMDE_FLOAT32_C(  -509.48), SIMDE_FLOAT32_C(  -582.48), SIMDE_FLOAT32_C(  -592.44)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -3.99), SIMDE_FLOAT32_C(     1.90), SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.55)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -938.19), SIMDE_FLOAT32_C(   629.18), SIMDE_FLOAT32_C(   564.19), SIMDE_FLOAT32_C(  -570.62)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   505.64), SIMDE_FLOAT32_C(  -444.97), SIMDE_FLOAT32_C(    38.59), SIMDE_FLOAT32_C(   692.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -1.86), SIMDE_FLOAT32_C(    -1.41), SIMDE_FLOAT32_C(    14.62), SIMDE_FLOAT32_C(    -0.82)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    37.78), SIMDE_FLOAT32_C(   840.67), SIMDE_FLOAT32_C(   915.86), SIMDE_FLOAT32_C(   911.39)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -720.31), SIMDE_FLOAT32_C(  -591.88), SIMDE_FLOAT32_C(   194.42), SIMDE_FLOAT32_C(  -372.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(    -1.42), SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(    -2.44)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_div_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_div_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -793.82), SIMDE_FLOAT32_C(   -34.36), SIMDE_FLOAT32_C(    80.43), SIMDE_FLOAT32_C(  -203.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   824.19), SIMDE_FLOAT32_C(   444.15), SIMDE_FLOAT32_C(   477.20), SIMDE_FLOAT32_C(  -757.29)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -793.82), SIMDE_FLOAT32_C(   -34.36), SIMDE_FLOAT32_C(    80.43), SIMDE_FLOAT32_C(     0.27)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   305.50), SIMDE_FLOAT32_C(  -288.99), SIMDE_FLOAT32_C(  -230.29), SIMDE_FLOAT32_C(   214.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   811.96), SIMDE_FLOAT32_C(   942.32), SIMDE_FLOAT32_C(  -733.60), SIMDE_FLOAT32_C(   612.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   305.50), SIMDE_FLOAT32_C(  -288.99), SIMDE_FLOAT32_C(  -230.29), SIMDE_FLOAT32_C(     0.35)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   273.05), SIMDE_FLOAT32_C(   372.05), SIMDE_FLOAT32_C(  -656.44), SIMDE_FLOAT32_C(   200.77)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    71.50), SIMDE_FLOAT32_C(  -992.70), SIMDE_FLOAT32_C(   826.54), SIMDE_FLOAT32_C(  -872.88)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   273.05), SIMDE_FLOAT32_C(   372.05), SIMDE_FLOAT32_C(  -656.44), SIMDE_FLOAT32_C(    -0.23)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   246.96), SIMDE_FLOAT32_C(   324.32), SIMDE_FLOAT32_C(  -964.89), SIMDE_FLOAT32_C(   778.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -432.74), SIMDE_FLOAT32_C(   520.15), SIMDE_FLOAT32_C(   952.89), SIMDE_FLOAT32_C(  -146.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   246.96), SIMDE_FLOAT32_C(   324.32), SIMDE_FLOAT32_C(  -964.89), SIMDE_FLOAT32_C(    -5.31)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   525.51), SIMDE_FLOAT32_C(   309.52), SIMDE_FLOAT32_C(  -262.93), SIMDE_FLOAT32_C(  -866.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   148.82), SIMDE_FLOAT32_C(   425.80), SIMDE_FLOAT32_C(   180.19), SIMDE_FLOAT32_C(   897.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   525.51), SIMDE_FLOAT32_C(   309.52), SIMDE_FLOAT32_C(  -262.93), SIMDE_FLOAT32_C(    -0.97)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   306.95), SIMDE_FLOAT32_C(    97.55), SIMDE_FLOAT32_C(   783.15), SIMDE_FLOAT32_C(   211.26)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -499.54), SIMDE_FLOAT32_C(   333.83), SIMDE_FLOAT32_C(   267.98), SIMDE_FLOAT32_C(  -538.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   306.95), SIMDE_FLOAT32_C(    97.55), SIMDE_FLOAT32_C(   783.15), SIMDE_FLOAT32_C(    -0.39)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -431.78), SIMDE_FLOAT32_C(  -941.60), SIMDE_FLOAT32_C(   991.34), SIMDE_FLOAT32_C(  -979.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   814.75), SIMDE_FLOAT32_C(   774.29), SIMDE_FLOAT32_C(   205.12), SIMDE_FLOAT32_C(   569.13)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -431.78), SIMDE_FLOAT32_C(  -941.60), SIMDE_FLOAT32_C(   991.34), SIMDE_FLOAT32_C(    -1.72)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -391.64), SIMDE_FLOAT32_C(   983.60), SIMDE_FLOAT32_C(   175.73), SIMDE_FLOAT32_C(  -840.27)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   318.68), SIMDE_FLOAT32_C(  -883.66), SIMDE_FLOAT32_C(  -893.33), SIMDE_FLOAT32_C(   900.04)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -391.64), SIMDE_FLOAT32_C(   983.60), SIMDE_FLOAT32_C(   175.73), SIMDE_FLOAT32_C(    -0.93)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_div_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_extract_pi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int16_t r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-14353), INT16_C( 22942), INT16_C(-17535), INT16_C( 13021)),
      13021 },
    { simde_mm_set_pi16(INT16_C(-11477), INT16_C( 26597), INT16_C( 17199), INT16_C(-30275)),
      17199 },
    { simde_mm_set_pi16(INT16_C( 24440), INT16_C(-12101), INT16_C(-13621), INT16_C(-14757)),
      -12101 },
    { simde_mm_set_pi16(INT16_C(-23205), INT16_C(-26140), INT16_C(-19797), INT16_C( 24953)),
      -23205 }
  };

  int16_t r;

  r = simde_mm_extract_pi16(test_vec[0].a, 0);
  simde_assert_equal_i16(test_vec[0].r, r);

  r = simde_mm_extract_pi16(test_vec[1].a, 1);
  simde_assert_equal_i16(test_vec[1].r, r);

  r = simde_mm_extract_pi16(test_vec[2].a, 2);
  simde_assert_equal_i16(test_vec[2].r, r);

  r = simde_mm_extract_pi16(test_vec[3].a, 3);
  simde_assert_equal_i16(test_vec[3].r, r);

  return 0;
}

static int
test_simde_m_pextrw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int16_t r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-14353), INT16_C( 22942), INT16_C(-17535), INT16_C( 13021)),
      13021 },
    { simde_mm_set_pi16(INT16_C(-11477), INT16_C( 26597), INT16_C( 17199), INT16_C(-30275)),
      17199 },
    { simde_mm_set_pi16(INT16_C( 24440), INT16_C(-12101), INT16_C(-13621), INT16_C(-14757)),
      -12101 },
    { simde_mm_set_pi16(INT16_C(-23205), INT16_C(-26140), INT16_C(-19797), INT16_C( 24953)),
      -23205 }
  };

  int16_t r;

  r = simde_m_pextrw(test_vec[0].a, 0);
  simde_assert_equal_i16(test_vec[0].r, r);

  r = simde_m_pextrw(test_vec[1].a, 1);
  simde_assert_equal_i16(test_vec[1].r, r);

  r = simde_m_pextrw(test_vec[2].a, 2);
  simde_assert_equal_i16(test_vec[2].r, r);

  r = simde_m_pextrw(test_vec[3].a, 3);
  simde_assert_equal_i16(test_vec[3].r, r);

  return 0;
}

static int
test_simde_mm_insert_pi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int16_t b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-16831), INT16_C( 27027), INT16_C( -2166), INT16_C(-28596)),
      INT16_C(  2418),
      simde_mm_set_pi16(INT16_C(-16831), INT16_C( 27027), INT16_C( -2166), INT16_C(  2418)) },
    { simde_mm_set_pi16(INT16_C(-28809), INT16_C( 15538), INT16_C( 32114), INT16_C(  2219)),
      INT16_C(  1863),
      simde_mm_set_pi16(INT16_C(-28809), INT16_C( 15538), INT16_C(  1863), INT16_C(  2219)) },
    { simde_mm_set_pi16(INT16_C(-29640), INT16_C(-13575), INT16_C( 25300), INT16_C(  9162)),
      INT16_C( 32619),
      simde_mm_set_pi16(INT16_C(-29640), INT16_C( 32619), INT16_C( 25300), INT16_C(  9162)) },
    { simde_mm_set_pi16(INT16_C( 29435), INT16_C(-21501), INT16_C( 32589), INT16_C(-29370)),
      INT16_C(  6382),
      simde_mm_set_pi16(INT16_C(  6382), INT16_C(-21501), INT16_C( 32589), INT16_C(-29370)) }
  };

  simde__m64 r;

  r = simde_mm_insert_pi16(test_vec[0].a, test_vec[0].b, 0);
  simde_test_x86_assert_equal_i16x4(r, test_vec[0].r);

  r = simde_mm_insert_pi16(test_vec[1].a, test_vec[1].b, 1);
  simde_test_x86_assert_equal_i16x4(r, test_vec[1].r);

  r = simde_mm_insert_pi16(test_vec[2].a, test_vec[2].b, 2);
  simde_test_x86_assert_equal_i16x4(r, test_vec[2].r);

  r = simde_mm_insert_pi16(test_vec[3].a, test_vec[3].b, 3);
  simde_test_x86_assert_equal_i16x4(r, test_vec[3].r);

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pinsrw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int16_t b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-16831), INT16_C( 27027), INT16_C( -2166), INT16_C(-28596)),
      INT16_C(  2418),
      simde_mm_set_pi16(INT16_C(-16831), INT16_C( 27027), INT16_C( -2166), INT16_C(  2418)) },
    { simde_mm_set_pi16(INT16_C(-28809), INT16_C( 15538), INT16_C( 32114), INT16_C(  2219)),
      INT16_C(  1863),
      simde_mm_set_pi16(INT16_C(-28809), INT16_C( 15538), INT16_C(  1863), INT16_C(  2219)) },
    { simde_mm_set_pi16(INT16_C(-29640), INT16_C(-13575), INT16_C( 25300), INT16_C(  9162)),
      INT16_C( 32619),
      simde_mm_set_pi16(INT16_C(-29640), INT16_C( 32619), INT16_C( 25300), INT16_C(  9162)) },
    { simde_mm_set_pi16(INT16_C( 29435), INT16_C(-21501), INT16_C( 32589), INT16_C(-29370)),
      INT16_C(  6382),
      simde_mm_set_pi16(INT16_C(  6382), INT16_C(-21501), INT16_C( 32589), INT16_C(-29370)) }
  };

  simde__m64 r;

  r = simde_m_pinsrw(test_vec[0].a, test_vec[0].b, 0);
  simde_test_x86_assert_equal_i16x4(r, test_vec[0].r);

  r = simde_m_pinsrw(test_vec[1].a, test_vec[1].b, 1);
  simde_test_x86_assert_equal_i16x4(r, test_vec[1].r);

  r = simde_m_pinsrw(test_vec[2].a, test_vec[2].b, 2);
  simde_test_x86_assert_equal_i16x4(r, test_vec[2].r);

  r = simde_m_pinsrw(test_vec[3].a, test_vec[3].b, 3);
  simde_test_x86_assert_equal_i16x4(r, test_vec[3].r);

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_load_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128) const simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   796.55), SIMDE_FLOAT32_C(   -42.53), SIMDE_FLOAT32_C(   966.47), SIMDE_FLOAT32_C(  -905.61) } },
    { { SIMDE_FLOAT32_C(   758.03), SIMDE_FLOAT32_C(   301.98), SIMDE_FLOAT32_C(   267.59), SIMDE_FLOAT32_C(  -948.37) } },
    { { SIMDE_FLOAT32_C(   433.23), SIMDE_FLOAT32_C(  -486.34), SIMDE_FLOAT32_C(  -487.77), SIMDE_FLOAT32_C(   180.47) } },
    { { SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(  -707.20), SIMDE_FLOAT32_C(   441.44), SIMDE_FLOAT32_C(  -927.94) } },
    { { SIMDE_FLOAT32_C(  -275.54), SIMDE_FLOAT32_C(    31.37), SIMDE_FLOAT32_C(   841.81), SIMDE_FLOAT32_C(  -508.63) } },
    { { SIMDE_FLOAT32_C(   463.05), SIMDE_FLOAT32_C(   911.09), SIMDE_FLOAT32_C(  -153.25), SIMDE_FLOAT32_C(   259.61) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_f32x4(simde_mm_load_ps(test_vec[i].a), simde_mm_loadu_ps(test_vec[i].a), 1);
  }

  return 0;
}

static int
test_simde_mm_load_ps1(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float32 a;
    simde__m128 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(   109.27),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   109.27), SIMDE_FLOAT32_C(   109.27), SIMDE_FLOAT32_C(   109.27), SIMDE_FLOAT32_C(   109.27)) },
    { SIMDE_FLOAT32_C(  -226.37),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -226.37), SIMDE_FLOAT32_C(  -226.37), SIMDE_FLOAT32_C(  -226.37), SIMDE_FLOAT32_C(  -226.37)) },
    { SIMDE_FLOAT32_C(   574.72),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   574.72), SIMDE_FLOAT32_C(   574.72), SIMDE_FLOAT32_C(   574.72), SIMDE_FLOAT32_C(   574.72)) },
    { SIMDE_FLOAT32_C(  -930.02),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -930.02), SIMDE_FLOAT32_C(  -930.02), SIMDE_FLOAT32_C(  -930.02), SIMDE_FLOAT32_C(  -930.02)) },
    { SIMDE_FLOAT32_C(  -710.77),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -710.77), SIMDE_FLOAT32_C(  -710.77), SIMDE_FLOAT32_C(  -710.77), SIMDE_FLOAT32_C(  -710.77)) },
    { SIMDE_FLOAT32_C(   446.62),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   446.62), SIMDE_FLOAT32_C(   446.62), SIMDE_FLOAT32_C(   446.62), SIMDE_FLOAT32_C(   446.62)) },
    { SIMDE_FLOAT32_C(  -974.29),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -974.29), SIMDE_FLOAT32_C(  -974.29), SIMDE_FLOAT32_C(  -974.29), SIMDE_FLOAT32_C(  -974.29)) },
    { SIMDE_FLOAT32_C(  -406.72),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -406.72), SIMDE_FLOAT32_C(  -406.72), SIMDE_FLOAT32_C(  -406.72), SIMDE_FLOAT32_C(  -406.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_load_ps1(&(test_vec[i].a));
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_load_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float32 a;
    simde__m128 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(   982.60),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   982.60)) },
    { SIMDE_FLOAT32_C(  -862.06),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -862.06)) },
    { SIMDE_FLOAT32_C(   458.44),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   458.44)) },
    { SIMDE_FLOAT32_C(  -232.03),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -232.03)) },
    { SIMDE_FLOAT32_C(  -187.73),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -187.73)) },
    { SIMDE_FLOAT32_C(   614.96),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   614.96)) },
    { SIMDE_FLOAT32_C(  -222.01),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -222.01)) },
    { SIMDE_FLOAT32_C(   -65.37),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -65.37)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_load_ss(&(test_vec[i].a));
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_loadh_pi (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[2];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -931.10), SIMDE_FLOAT32_C(   146.10), SIMDE_FLOAT32_C(   323.97), SIMDE_FLOAT32_C(   666.93) },
      { SIMDE_FLOAT32_C(   536.39), SIMDE_FLOAT32_C(   -55.33) },
      { SIMDE_FLOAT32_C(  -931.10), SIMDE_FLOAT32_C(   146.10), SIMDE_FLOAT32_C(   536.39), SIMDE_FLOAT32_C(   -55.33) } },
    { { SIMDE_FLOAT32_C(   232.94), SIMDE_FLOAT32_C(   310.53), SIMDE_FLOAT32_C(   277.06), SIMDE_FLOAT32_C(    23.22) },
      { SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(  -298.75) },
      { SIMDE_FLOAT32_C(   232.94), SIMDE_FLOAT32_C(   310.53), SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(  -298.75) } },
    { { SIMDE_FLOAT32_C(   212.42), SIMDE_FLOAT32_C(   -85.39), SIMDE_FLOAT32_C(   335.83), SIMDE_FLOAT32_C(  -627.07) },
      { SIMDE_FLOAT32_C(  -208.48), SIMDE_FLOAT32_C(  -609.05) },
      { SIMDE_FLOAT32_C(   212.42), SIMDE_FLOAT32_C(   -85.39), SIMDE_FLOAT32_C(  -208.48), SIMDE_FLOAT32_C(  -609.05) } },
    { { SIMDE_FLOAT32_C(   560.76), SIMDE_FLOAT32_C(  -751.94), SIMDE_FLOAT32_C(  -976.19), SIMDE_FLOAT32_C(  -259.36) },
      { SIMDE_FLOAT32_C(   981.44), SIMDE_FLOAT32_C(  -348.97) },
      { SIMDE_FLOAT32_C(   560.76), SIMDE_FLOAT32_C(  -751.94), SIMDE_FLOAT32_C(   981.44), SIMDE_FLOAT32_C(  -348.97) } },
    { { SIMDE_FLOAT32_C(   282.19), SIMDE_FLOAT32_C(   412.73), SIMDE_FLOAT32_C(  -115.39), SIMDE_FLOAT32_C(  -766.32) },
      { SIMDE_FLOAT32_C(  -979.64), SIMDE_FLOAT32_C(    46.41) },
      { SIMDE_FLOAT32_C(   282.19), SIMDE_FLOAT32_C(   412.73), SIMDE_FLOAT32_C(  -979.64), SIMDE_FLOAT32_C(    46.41) } },
    { { SIMDE_FLOAT32_C(   430.25), SIMDE_FLOAT32_C(  -910.75), SIMDE_FLOAT32_C(  -807.49), SIMDE_FLOAT32_C(  -245.79) },
      { SIMDE_FLOAT32_C(   756.18), SIMDE_FLOAT32_C(   728.90) },
      { SIMDE_FLOAT32_C(   430.25), SIMDE_FLOAT32_C(  -910.75), SIMDE_FLOAT32_C(   756.18), SIMDE_FLOAT32_C(   728.90) } },
    { { SIMDE_FLOAT32_C(   698.88), SIMDE_FLOAT32_C(   -10.88), SIMDE_FLOAT32_C(    39.43), SIMDE_FLOAT32_C(   -24.06) },
      { SIMDE_FLOAT32_C(  -987.66), SIMDE_FLOAT32_C(   218.51) },
      { SIMDE_FLOAT32_C(   698.88), SIMDE_FLOAT32_C(   -10.88), SIMDE_FLOAT32_C(  -987.66), SIMDE_FLOAT32_C(   218.51) } },
    { { SIMDE_FLOAT32_C(   677.19), SIMDE_FLOAT32_C(   224.76), SIMDE_FLOAT32_C(  -866.88), SIMDE_FLOAT32_C(    13.01) },
      { SIMDE_FLOAT32_C(   597.69), SIMDE_FLOAT32_C(   -75.37) },
      { SIMDE_FLOAT32_C(   677.19), SIMDE_FLOAT32_C(   224.76), SIMDE_FLOAT32_C(   597.69), SIMDE_FLOAT32_C(   -75.37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_loadh_pi(a, SIMDE_ALIGN_CAST(const simde__m64*, test_vec[i].b));
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_loadl_pi(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde_float32 b[2];
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -759.67), SIMDE_FLOAT32_C(  -161.20), SIMDE_FLOAT32_C(  -647.60), SIMDE_FLOAT32_C(  -354.59)),
      { SIMDE_FLOAT32_C(   151.83), SIMDE_FLOAT32_C(   650.74) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -759.67), SIMDE_FLOAT32_C(  -161.20), SIMDE_FLOAT32_C(   650.74), SIMDE_FLOAT32_C(   151.83)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   622.29), SIMDE_FLOAT32_C(   971.32), SIMDE_FLOAT32_C(   189.94), SIMDE_FLOAT32_C(  -546.65)),
      { SIMDE_FLOAT32_C(   704.03), SIMDE_FLOAT32_C(  -840.05) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   622.29), SIMDE_FLOAT32_C(   971.32), SIMDE_FLOAT32_C(  -840.05), SIMDE_FLOAT32_C(   704.03)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -740.17), SIMDE_FLOAT32_C(   779.38), SIMDE_FLOAT32_C(  -852.02), SIMDE_FLOAT32_C(   399.85)),
      { SIMDE_FLOAT32_C(  -182.16), SIMDE_FLOAT32_C(  -228.45) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -740.17), SIMDE_FLOAT32_C(   779.38), SIMDE_FLOAT32_C(  -228.45), SIMDE_FLOAT32_C(  -182.16)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -846.70), SIMDE_FLOAT32_C(   853.34), SIMDE_FLOAT32_C(  -863.68), SIMDE_FLOAT32_C(  -823.68)),
      { SIMDE_FLOAT32_C(  -970.25), SIMDE_FLOAT32_C(   188.74) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -846.70), SIMDE_FLOAT32_C(   853.34), SIMDE_FLOAT32_C(   188.74), SIMDE_FLOAT32_C(  -970.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   199.88), SIMDE_FLOAT32_C(  -915.58), SIMDE_FLOAT32_C(   899.92), SIMDE_FLOAT32_C(   424.76)),
      { SIMDE_FLOAT32_C(   674.47), SIMDE_FLOAT32_C(  -152.19) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   199.88), SIMDE_FLOAT32_C(  -915.58), SIMDE_FLOAT32_C(  -152.19), SIMDE_FLOAT32_C(   674.47)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   686.01), SIMDE_FLOAT32_C(   545.43), SIMDE_FLOAT32_C(   -50.76), SIMDE_FLOAT32_C(   611.26)),
      { SIMDE_FLOAT32_C(  -551.50), SIMDE_FLOAT32_C(  -609.71) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   686.01), SIMDE_FLOAT32_C(   545.43), SIMDE_FLOAT32_C(  -609.71), SIMDE_FLOAT32_C(  -551.50)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    29.24), SIMDE_FLOAT32_C(   172.70), SIMDE_FLOAT32_C(   -27.31), SIMDE_FLOAT32_C(  -586.10)),
      { SIMDE_FLOAT32_C(  -893.37), SIMDE_FLOAT32_C(   126.78) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(    29.24), SIMDE_FLOAT32_C(   172.70), SIMDE_FLOAT32_C(   126.78), SIMDE_FLOAT32_C(  -893.37)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    57.95), SIMDE_FLOAT32_C(   614.04), SIMDE_FLOAT32_C(   530.49), SIMDE_FLOAT32_C(   660.83)),
      { SIMDE_FLOAT32_C(  -772.86), SIMDE_FLOAT32_C(   749.53) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(    57.95), SIMDE_FLOAT32_C(   614.04), SIMDE_FLOAT32_C(   749.53), SIMDE_FLOAT32_C(  -772.86)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_loadl_pi(test_vec[i].a, SIMDE_ALIGN_CAST(simde__m64 const*, test_vec[i].b));
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_loadr_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128) const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -880.56), SIMDE_FLOAT32_C(  -284.61), SIMDE_FLOAT32_C(  -934.21), SIMDE_FLOAT32_C(   785.08) },
      { SIMDE_FLOAT32_C(   785.08), SIMDE_FLOAT32_C(  -934.21), SIMDE_FLOAT32_C(  -284.61), SIMDE_FLOAT32_C(  -880.56) } },
    { { SIMDE_FLOAT32_C(  -829.46), SIMDE_FLOAT32_C(  -887.14), SIMDE_FLOAT32_C(   710.11), SIMDE_FLOAT32_C(  -137.75) },
      { SIMDE_FLOAT32_C(  -137.75), SIMDE_FLOAT32_C(   710.11), SIMDE_FLOAT32_C(  -887.14), SIMDE_FLOAT32_C(  -829.46) } },
    { { SIMDE_FLOAT32_C(   524.87), SIMDE_FLOAT32_C(  -290.80), SIMDE_FLOAT32_C(   257.30), SIMDE_FLOAT32_C(  -491.27) },
      { SIMDE_FLOAT32_C(  -491.27), SIMDE_FLOAT32_C(   257.30), SIMDE_FLOAT32_C(  -290.80), SIMDE_FLOAT32_C(   524.87) } },
    { { SIMDE_FLOAT32_C(  -344.66), SIMDE_FLOAT32_C(  -151.52), SIMDE_FLOAT32_C(  -772.85), SIMDE_FLOAT32_C(  -708.41) },
      { SIMDE_FLOAT32_C(  -708.41), SIMDE_FLOAT32_C(  -772.85), SIMDE_FLOAT32_C(  -151.52), SIMDE_FLOAT32_C(  -344.66) } },
    { { SIMDE_FLOAT32_C(   875.04), SIMDE_FLOAT32_C(  -304.95), SIMDE_FLOAT32_C(   237.12), SIMDE_FLOAT32_C(   595.93) },
      { SIMDE_FLOAT32_C(   595.93), SIMDE_FLOAT32_C(   237.12), SIMDE_FLOAT32_C(  -304.95), SIMDE_FLOAT32_C(   875.04) } },
    { { SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   875.01), SIMDE_FLOAT32_C(   682.00), SIMDE_FLOAT32_C(   758.45) },
      { SIMDE_FLOAT32_C(   758.45), SIMDE_FLOAT32_C(   682.00), SIMDE_FLOAT32_C(   875.01), SIMDE_FLOAT32_C(  -182.45) } },
    { { SIMDE_FLOAT32_C(  -461.05), SIMDE_FLOAT32_C(  -321.67), SIMDE_FLOAT32_C(  -167.95), SIMDE_FLOAT32_C(  -232.59) },
      { SIMDE_FLOAT32_C(  -232.59), SIMDE_FLOAT32_C(  -167.95), SIMDE_FLOAT32_C(  -321.67), SIMDE_FLOAT32_C(  -461.05) } },
    { { SIMDE_FLOAT32_C(   323.21), SIMDE_FLOAT32_C(  -420.37), SIMDE_FLOAT32_C(  -966.28), SIMDE_FLOAT32_C(   442.65) },
      { SIMDE_FLOAT32_C(   442.65), SIMDE_FLOAT32_C(  -966.28), SIMDE_FLOAT32_C(  -420.37), SIMDE_FLOAT32_C(   323.21) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 r = simde_mm_loadr_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_loadu_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float32 a[4];
    simde__m128 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(   658.17), SIMDE_FLOAT32_C(  -216.72), SIMDE_FLOAT32_C(   812.08), SIMDE_FLOAT32_C(   746.73) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   746.73), SIMDE_FLOAT32_C(   812.08), SIMDE_FLOAT32_C(  -216.72), SIMDE_FLOAT32_C(   658.17)) },
    { { SIMDE_FLOAT32_C(  -626.80), SIMDE_FLOAT32_C(   899.16), SIMDE_FLOAT32_C(  -494.66), SIMDE_FLOAT32_C(  -802.94) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -802.94), SIMDE_FLOAT32_C(  -494.66), SIMDE_FLOAT32_C(   899.16), SIMDE_FLOAT32_C(  -626.80)) },
    { { SIMDE_FLOAT32_C(  -126.83), SIMDE_FLOAT32_C(  -920.21), SIMDE_FLOAT32_C(    37.07), SIMDE_FLOAT32_C(   514.70) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   514.70), SIMDE_FLOAT32_C(    37.07), SIMDE_FLOAT32_C(  -920.21), SIMDE_FLOAT32_C(  -126.83)) },
    { { SIMDE_FLOAT32_C(   591.39), SIMDE_FLOAT32_C(    -2.44), SIMDE_FLOAT32_C(  -874.39), SIMDE_FLOAT32_C(  -396.41) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -396.41), SIMDE_FLOAT32_C(  -874.39), SIMDE_FLOAT32_C(    -2.44), SIMDE_FLOAT32_C(   591.39)) },
    { { SIMDE_FLOAT32_C(  -253.20), SIMDE_FLOAT32_C(  -832.85), SIMDE_FLOAT32_C(  -949.34), SIMDE_FLOAT32_C(  -940.41) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -940.41), SIMDE_FLOAT32_C(  -949.34), SIMDE_FLOAT32_C(  -832.85), SIMDE_FLOAT32_C(  -253.20)) },
    { { SIMDE_FLOAT32_C(   693.54), SIMDE_FLOAT32_C(   223.92), SIMDE_FLOAT32_C(  -939.11), SIMDE_FLOAT32_C(   355.93) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   355.93), SIMDE_FLOAT32_C(  -939.11), SIMDE_FLOAT32_C(   223.92), SIMDE_FLOAT32_C(   693.54)) },
    { { SIMDE_FLOAT32_C(    -8.12), SIMDE_FLOAT32_C(   751.96), SIMDE_FLOAT32_C(  -621.91), SIMDE_FLOAT32_C(   106.31) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   106.31), SIMDE_FLOAT32_C(  -621.91), SIMDE_FLOAT32_C(   751.96), SIMDE_FLOAT32_C(    -8.12)) },
    { { SIMDE_FLOAT32_C(   -14.41), SIMDE_FLOAT32_C(   565.48), SIMDE_FLOAT32_C(   361.01), SIMDE_FLOAT32_C(   431.24) },
      simde_mm_set_ps(SIMDE_FLOAT32_C(   431.24), SIMDE_FLOAT32_C(   361.01), SIMDE_FLOAT32_C(   565.48), SIMDE_FLOAT32_C(   -14.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_loadu_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_maskmove_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int8_t b[8];
    simde__m64 mask;
    int8_t r[8];
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  -5), INT8_C( 112), INT8_C( 109), INT8_C(  -9), INT8_C( -10), INT8_C( -30), INT8_C(-103), INT8_C( -13)),
      { INT8_C( -67), INT8_C( -21), INT8_C( 107), INT8_C(  96), INT8_C( -47), INT8_C(  95), INT8_C(  34), INT8_C(-108) },
      simde_mm_set_pi8(-112,   64,  -92,   19,  -70,  -49,  -42,   75),
      { INT8_C( -67), INT8_C(-103), INT8_C( -30), INT8_C( -10), INT8_C( -47), INT8_C( 109), INT8_C(  34), INT8_C(  -5) } },
    { simde_mm_set_pi8(INT8_C(-111), INT8_C(  -8), INT8_C( -84), INT8_C(  80), INT8_C(   8), INT8_C( -61), INT8_C( -80), INT8_C( -85)),
      { INT8_C(  66), INT8_C(  19), INT8_C(  96), INT8_C(   6), INT8_C( -30), INT8_C(  85), INT8_C(  97), INT8_C( -44) },
      simde_mm_set_pi8( -90,  -11, -113,   11,  -96, -125,  121, -113),
      { INT8_C( -85), INT8_C(  19), INT8_C( -61), INT8_C(   8), INT8_C( -30), INT8_C( -84), INT8_C(  -8), INT8_C(-111) } },
    { simde_mm_set_pi8(INT8_C( 120), INT8_C(-105), INT8_C(   2), INT8_C(  21), INT8_C(  93), INT8_C(-124), INT8_C(  -2), INT8_C(  79)),
      { INT8_C(  87), INT8_C(  98), INT8_C( -52), INT8_C(  28), INT8_C(  37), INT8_C(-120), INT8_C( 109), INT8_C(  79) },
      simde_mm_set_pi8(  34,  106,  -74,   83, -114,  -10,   67,  111),
      { INT8_C(  87), INT8_C(  98), INT8_C(-124), INT8_C(  93), INT8_C(  37), INT8_C(   2), INT8_C( 109), INT8_C(  79) } },
    { simde_mm_set_pi8(INT8_C( -26), INT8_C(  96), INT8_C(-115), INT8_C(  78), INT8_C(  35), INT8_C(  49), INT8_C(  36), INT8_C( -25)),
      { INT8_C(  29), INT8_C(  28), INT8_C(  30), INT8_C( -80), INT8_C( -12), INT8_C(  81), INT8_C( -81), INT8_C( 120) },
      simde_mm_set_pi8( -59,  -55, -111, -119,   86,   -5,   74,    2),
      { INT8_C(  29), INT8_C(  28), INT8_C(  49), INT8_C( -80), INT8_C(  78), INT8_C(-115), INT8_C(  96), INT8_C( -26) } },
    { simde_mm_set_pi8(INT8_C( -37), INT8_C(  41), INT8_C( 123), INT8_C(-107), INT8_C(-123), INT8_C(  32), INT8_C(  33), INT8_C(   5)),
      { INT8_C(-126), INT8_C(  94), INT8_C( -30), INT8_C( -13), INT8_C(  99), INT8_C( 126), INT8_C(  16), INT8_C(   5) },
      simde_mm_set_pi8( 113,    1,   66,    5,  -18,   77,  -41,   -4),
      { INT8_C(   5), INT8_C(  33), INT8_C( -30), INT8_C(-123), INT8_C(  99), INT8_C( 126), INT8_C(  16), INT8_C(   5) } },
    { simde_mm_set_pi8(INT8_C( -90), INT8_C(-113), INT8_C(  97), INT8_C(  73), INT8_C(  33), INT8_C(  -3), INT8_C( 109), INT8_C(  63)),
      { INT8_C( -41), INT8_C( -87), INT8_C(-115), INT8_C( -26), INT8_C(  68), INT8_C( -33), INT8_C(   7), INT8_C( -69) },
      simde_mm_set_pi8(  28,  106,  -56,  -23, -126, -119,   22,  -23),
      { INT8_C(  63), INT8_C( -87), INT8_C(  -3), INT8_C(  33), INT8_C(  73), INT8_C(  97), INT8_C(   7), INT8_C( -69) } },
    { simde_mm_set_pi8(INT8_C(  12), INT8_C(   9), INT8_C( -66), INT8_C(-114), INT8_C(  19), INT8_C(  94), INT8_C(-103), INT8_C(  38)),
      { INT8_C( 102), INT8_C( -71), INT8_C(  55), INT8_C(  40), INT8_C(-122), INT8_C(  94), INT8_C(  71), INT8_C( -99) },
      simde_mm_set_pi8(  78,   82, -126,   33,  118,   93, -125,  113),
      { INT8_C( 102), INT8_C(-103), INT8_C(  55), INT8_C(  40), INT8_C(-122), INT8_C( -66), INT8_C(  71), INT8_C( -99) } },
    { simde_mm_set_pi8(INT8_C(  67), INT8_C( 108), INT8_C(  55), INT8_C( -68), INT8_C(  -5), INT8_C( -18), INT8_C( 115), INT8_C( 126)),
      { INT8_C(  92), INT8_C( -82), INT8_C( 101), INT8_C( -48), INT8_C(  45), INT8_C( 101), INT8_C(  95), INT8_C(  51) },
      simde_mm_set_pi8( -92,  -27,   65,  -21,   36,  126,   80,   50),
      { INT8_C(  92), INT8_C( -82), INT8_C( 101), INT8_C( -48), INT8_C( -68), INT8_C( 101), INT8_C( 108), INT8_C(  67) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int8_t r[8], e[8];
    simde_memcpy(r, test_vec[i].b, sizeof(r));
    simde_memcpy(e, test_vec[i].r, sizeof(e));

    #if defined(SIMDE_X86_SSE_NATIVE) && defined(SIMDE_NATIVE_ALIASES_TESTING)
      simde_mm_maskmove_si64(test_vec[i].a, test_vec[i].mask, HEDLEY_REINTERPRET_CAST(char *, r));
    #else
      simde_mm_maskmove_si64(test_vec[i].a, test_vec[i].mask, r);
    #endif
    simde_assert_equal_vi8(8, r, e);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_maskmovq(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int8_t b[8];
    simde__m64 mask;
    int8_t r[8];
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  -5), INT8_C( 112), INT8_C( 109), INT8_C(  -9), INT8_C( -10), INT8_C( -30), INT8_C(-103), INT8_C( -13)),
      { INT8_C( -67), INT8_C( -21), INT8_C( 107), INT8_C(  96), INT8_C( -47), INT8_C(  95), INT8_C(  34), INT8_C(-108) },
      simde_mm_set_pi8(-112,   64,  -92,   19,  -70,  -49,  -42,   75),
      { INT8_C( -67), INT8_C(-103), INT8_C( -30), INT8_C( -10), INT8_C( -47), INT8_C( 109), INT8_C(  34), INT8_C(  -5) } },
    { simde_mm_set_pi8(INT8_C(-111), INT8_C(  -8), INT8_C( -84), INT8_C(  80), INT8_C(   8), INT8_C( -61), INT8_C( -80), INT8_C( -85)),
      { INT8_C(  66), INT8_C(  19), INT8_C(  96), INT8_C(   6), INT8_C( -30), INT8_C(  85), INT8_C(  97), INT8_C( -44) },
      simde_mm_set_pi8( -90,  -11, -113,   11,  -96, -125,  121, -113),
      { INT8_C( -85), INT8_C(  19), INT8_C( -61), INT8_C(   8), INT8_C( -30), INT8_C( -84), INT8_C(  -8), INT8_C(-111) } },
    { simde_mm_set_pi8(INT8_C( 120), INT8_C(-105), INT8_C(   2), INT8_C(  21), INT8_C(  93), INT8_C(-124), INT8_C(  -2), INT8_C(  79)),
      { INT8_C(  87), INT8_C(  98), INT8_C( -52), INT8_C(  28), INT8_C(  37), INT8_C(-120), INT8_C( 109), INT8_C(  79) },
      simde_mm_set_pi8(  34,  106,  -74,   83, -114,  -10,   67,  111),
      { INT8_C(  87), INT8_C(  98), INT8_C(-124), INT8_C(  93), INT8_C(  37), INT8_C(   2), INT8_C( 109), INT8_C(  79) } },
    { simde_mm_set_pi8(INT8_C( -26), INT8_C(  96), INT8_C(-115), INT8_C(  78), INT8_C(  35), INT8_C(  49), INT8_C(  36), INT8_C( -25)),
      { INT8_C(  29), INT8_C(  28), INT8_C(  30), INT8_C( -80), INT8_C( -12), INT8_C(  81), INT8_C( -81), INT8_C( 120) },
      simde_mm_set_pi8( -59,  -55, -111, -119,   86,   -5,   74,    2),
      { INT8_C(  29), INT8_C(  28), INT8_C(  49), INT8_C( -80), INT8_C(  78), INT8_C(-115), INT8_C(  96), INT8_C( -26) } },
    { simde_mm_set_pi8(INT8_C( -37), INT8_C(  41), INT8_C( 123), INT8_C(-107), INT8_C(-123), INT8_C(  32), INT8_C(  33), INT8_C(   5)),
      { INT8_C(-126), INT8_C(  94), INT8_C( -30), INT8_C( -13), INT8_C(  99), INT8_C( 126), INT8_C(  16), INT8_C(   5) },
      simde_mm_set_pi8( 113,    1,   66,    5,  -18,   77,  -41,   -4),
      { INT8_C(   5), INT8_C(  33), INT8_C( -30), INT8_C(-123), INT8_C(  99), INT8_C( 126), INT8_C(  16), INT8_C(   5) } },
    { simde_mm_set_pi8(INT8_C( -90), INT8_C(-113), INT8_C(  97), INT8_C(  73), INT8_C(  33), INT8_C(  -3), INT8_C( 109), INT8_C(  63)),
      { INT8_C( -41), INT8_C( -87), INT8_C(-115), INT8_C( -26), INT8_C(  68), INT8_C( -33), INT8_C(   7), INT8_C( -69) },
      simde_mm_set_pi8(  28,  106,  -56,  -23, -126, -119,   22,  -23),
      { INT8_C(  63), INT8_C( -87), INT8_C(  -3), INT8_C(  33), INT8_C(  73), INT8_C(  97), INT8_C(   7), INT8_C( -69) } },
    { simde_mm_set_pi8(INT8_C(  12), INT8_C(   9), INT8_C( -66), INT8_C(-114), INT8_C(  19), INT8_C(  94), INT8_C(-103), INT8_C(  38)),
      { INT8_C( 102), INT8_C( -71), INT8_C(  55), INT8_C(  40), INT8_C(-122), INT8_C(  94), INT8_C(  71), INT8_C( -99) },
      simde_mm_set_pi8(  78,   82, -126,   33,  118,   93, -125,  113),
      { INT8_C( 102), INT8_C(-103), INT8_C(  55), INT8_C(  40), INT8_C(-122), INT8_C( -66), INT8_C(  71), INT8_C( -99) } },
    { simde_mm_set_pi8(INT8_C(  67), INT8_C( 108), INT8_C(  55), INT8_C( -68), INT8_C(  -5), INT8_C( -18), INT8_C( 115), INT8_C( 126)),
      { INT8_C(  92), INT8_C( -82), INT8_C( 101), INT8_C( -48), INT8_C(  45), INT8_C( 101), INT8_C(  95), INT8_C(  51) },
      simde_mm_set_pi8( -92,  -27,   65,  -21,   36,  126,   80,   50),
      { INT8_C(  92), INT8_C( -82), INT8_C( 101), INT8_C( -48), INT8_C( -68), INT8_C( 101), INT8_C( 108), INT8_C(  67) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int8_t r[8], e[8];
    simde_memcpy(r, test_vec[i].b, sizeof(r));
    simde_memcpy(e, test_vec[i].r, sizeof(e));

    #if defined(SIMDE_X86_SSE_NATIVE) && defined(SIMDE_NATIVE_ALIASES_TESTING)
      simde_m_maskmovq(test_vec[i].a, test_vec[i].mask, HEDLEY_REINTERPRET_CAST(char *, r));
    #else
      simde_m_maskmovq(test_vec[i].a, test_vec[i].mask, r);
    #endif
    simde_assert_equal_vi8(8, r, e);
  }

  simde_mm_empty();

  return 0;
}


static int
test_simde_mm_max_pi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -3941), INT16_C(-29039), INT16_C(  9572), INT16_C( 17112)),
      simde_mm_set_pi16(INT16_C(-32765), INT16_C(  1912), INT16_C(  7655), INT16_C( -8077)),
      simde_mm_set_pi16(INT16_C( -3941), INT16_C(  1912), INT16_C(  9572), INT16_C( 17112)) },
    { simde_mm_set_pi16(INT16_C( -1581), INT16_C( 31995), INT16_C( 26494), INT16_C(-18794)),
      simde_mm_set_pi16(INT16_C( 16922), INT16_C(-22945), INT16_C( 32135), INT16_C(-23580)),
      simde_mm_set_pi16(INT16_C( 16922), INT16_C( 31995), INT16_C( 32135), INT16_C(-18794)) },
    { simde_mm_set_pi16(INT16_C( -5356), INT16_C(-22344), INT16_C( 30948), INT16_C(-20444)),
      simde_mm_set_pi16(INT16_C( 23575), INT16_C( 15204), INT16_C( -2804), INT16_C(  7606)),
      simde_mm_set_pi16(INT16_C( 23575), INT16_C( 15204), INT16_C( 30948), INT16_C(  7606)) },
    { simde_mm_set_pi16(INT16_C(-15388), INT16_C( -4009), INT16_C(-12203), INT16_C( 19351)),
      simde_mm_set_pi16(INT16_C(-11390), INT16_C(-14248), INT16_C(  6877), INT16_C(-11224)),
      simde_mm_set_pi16(INT16_C(-11390), INT16_C( -4009), INT16_C(  6877), INT16_C( 19351)) },
    { simde_mm_set_pi16(INT16_C(  9439), INT16_C(-12374), INT16_C( 28008), INT16_C(-15421)),
      simde_mm_set_pi16(INT16_C(  2278), INT16_C( 32415), INT16_C(-22150), INT16_C(  3793)),
      simde_mm_set_pi16(INT16_C(  9439), INT16_C( 32415), INT16_C( 28008), INT16_C(  3793)) },
    { simde_mm_set_pi16(INT16_C(  8379), INT16_C(-13717), INT16_C( 19788), INT16_C(-10969)),
      simde_mm_set_pi16(INT16_C(-11192), INT16_C(-31648), INT16_C(  6691), INT16_C(-15431)),
      simde_mm_set_pi16(INT16_C(  8379), INT16_C(-13717), INT16_C( 19788), INT16_C(-10969)) },
    { simde_mm_set_pi16(INT16_C( -9393), INT16_C( 10266), INT16_C( 19011), INT16_C( 29123)),
      simde_mm_set_pi16(INT16_C( -1050), INT16_C( 12724), INT16_C(-11587), INT16_C( 10160)),
      simde_mm_set_pi16(INT16_C( -1050), INT16_C( 12724), INT16_C( 19011), INT16_C( 29123)) },
    { simde_mm_set_pi16(INT16_C(  3665), INT16_C(-28011), INT16_C(-19799), INT16_C( 10281)),
      simde_mm_set_pi16(INT16_C( 18116), INT16_C( 25642), INT16_C( 26951), INT16_C( 15276)),
      simde_mm_set_pi16(INT16_C( 18116), INT16_C( 25642), INT16_C( 26951), INT16_C( 15276)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_max_pi16(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_m_pmaxsw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -3941), INT16_C(-29039), INT16_C(  9572), INT16_C( 17112)),
      simde_mm_set_pi16(INT16_C(-32765), INT16_C(  1912), INT16_C(  7655), INT16_C( -8077)),
      simde_mm_set_pi16(INT16_C( -3941), INT16_C(  1912), INT16_C(  9572), INT16_C( 17112)) },
    { simde_mm_set_pi16(INT16_C( -1581), INT16_C( 31995), INT16_C( 26494), INT16_C(-18794)),
      simde_mm_set_pi16(INT16_C( 16922), INT16_C(-22945), INT16_C( 32135), INT16_C(-23580)),
      simde_mm_set_pi16(INT16_C( 16922), INT16_C( 31995), INT16_C( 32135), INT16_C(-18794)) },
    { simde_mm_set_pi16(INT16_C( -5356), INT16_C(-22344), INT16_C( 30948), INT16_C(-20444)),
      simde_mm_set_pi16(INT16_C( 23575), INT16_C( 15204), INT16_C( -2804), INT16_C(  7606)),
      simde_mm_set_pi16(INT16_C( 23575), INT16_C( 15204), INT16_C( 30948), INT16_C(  7606)) },
    { simde_mm_set_pi16(INT16_C(-15388), INT16_C( -4009), INT16_C(-12203), INT16_C( 19351)),
      simde_mm_set_pi16(INT16_C(-11390), INT16_C(-14248), INT16_C(  6877), INT16_C(-11224)),
      simde_mm_set_pi16(INT16_C(-11390), INT16_C( -4009), INT16_C(  6877), INT16_C( 19351)) },
    { simde_mm_set_pi16(INT16_C(  9439), INT16_C(-12374), INT16_C( 28008), INT16_C(-15421)),
      simde_mm_set_pi16(INT16_C(  2278), INT16_C( 32415), INT16_C(-22150), INT16_C(  3793)),
      simde_mm_set_pi16(INT16_C(  9439), INT16_C( 32415), INT16_C( 28008), INT16_C(  3793)) },
    { simde_mm_set_pi16(INT16_C(  8379), INT16_C(-13717), INT16_C( 19788), INT16_C(-10969)),
      simde_mm_set_pi16(INT16_C(-11192), INT16_C(-31648), INT16_C(  6691), INT16_C(-15431)),
      simde_mm_set_pi16(INT16_C(  8379), INT16_C(-13717), INT16_C( 19788), INT16_C(-10969)) },
    { simde_mm_set_pi16(INT16_C( -9393), INT16_C( 10266), INT16_C( 19011), INT16_C( 29123)),
      simde_mm_set_pi16(INT16_C( -1050), INT16_C( 12724), INT16_C(-11587), INT16_C( 10160)),
      simde_mm_set_pi16(INT16_C( -1050), INT16_C( 12724), INT16_C( 19011), INT16_C( 29123)) },
    { simde_mm_set_pi16(INT16_C(  3665), INT16_C(-28011), INT16_C(-19799), INT16_C( 10281)),
      simde_mm_set_pi16(INT16_C( 18116), INT16_C( 25642), INT16_C( 26951), INT16_C( 15276)),
      simde_mm_set_pi16(INT16_C( 18116), INT16_C( 25642), INT16_C( 26951), INT16_C( 15276)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_m_pmaxsw(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_max_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   353.79),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -20.53) },
      { SIMDE_FLOAT32_C(  -559.69),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   542.61) },
      { SIMDE_FLOAT32_C(  -559.69),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   542.61) } },
    #endif
    { { SIMDE_FLOAT32_C(  -584.82), SIMDE_FLOAT32_C(  -771.96), SIMDE_FLOAT32_C(   713.78), SIMDE_FLOAT32_C(   -25.19) },
      { SIMDE_FLOAT32_C(  -146.60), SIMDE_FLOAT32_C(  -788.24), SIMDE_FLOAT32_C(   792.99), SIMDE_FLOAT32_C(  -871.40) },
      { SIMDE_FLOAT32_C(  -146.60), SIMDE_FLOAT32_C(  -771.96), SIMDE_FLOAT32_C(   792.99), SIMDE_FLOAT32_C(   -25.19) } },
    { { SIMDE_FLOAT32_C(  -253.85), SIMDE_FLOAT32_C(   796.83), SIMDE_FLOAT32_C(   458.25), SIMDE_FLOAT32_C(   983.39) },
      { SIMDE_FLOAT32_C(  -205.15), SIMDE_FLOAT32_C(  -738.14), SIMDE_FLOAT32_C(   103.55), SIMDE_FLOAT32_C(   362.69) },
      { SIMDE_FLOAT32_C(  -205.15), SIMDE_FLOAT32_C(   796.83), SIMDE_FLOAT32_C(   458.25), SIMDE_FLOAT32_C(   983.39) } },
    { { SIMDE_FLOAT32_C(  -535.82), SIMDE_FLOAT32_C(  -110.18), SIMDE_FLOAT32_C(  -688.86), SIMDE_FLOAT32_C(   231.16) },
      { SIMDE_FLOAT32_C(  -765.48), SIMDE_FLOAT32_C(  -343.50), SIMDE_FLOAT32_C(   811.93), SIMDE_FLOAT32_C(   559.03) },
      { SIMDE_FLOAT32_C(  -535.82), SIMDE_FLOAT32_C(  -110.18), SIMDE_FLOAT32_C(   811.93), SIMDE_FLOAT32_C(   559.03) } },
    { { SIMDE_FLOAT32_C(  -989.71), SIMDE_FLOAT32_C(  -736.05), SIMDE_FLOAT32_C(  -461.50), SIMDE_FLOAT32_C(  -549.40) },
      { SIMDE_FLOAT32_C(  -316.97), SIMDE_FLOAT32_C(  -791.36), SIMDE_FLOAT32_C(   993.20), SIMDE_FLOAT32_C(    98.21) },
      { SIMDE_FLOAT32_C(  -316.97), SIMDE_FLOAT32_C(  -736.05), SIMDE_FLOAT32_C(   993.20), SIMDE_FLOAT32_C(    98.21) } },
    { { SIMDE_FLOAT32_C(  -563.32), SIMDE_FLOAT32_C(   706.98), SIMDE_FLOAT32_C(  -926.98), SIMDE_FLOAT32_C(   290.07) },
      { SIMDE_FLOAT32_C(   918.74), SIMDE_FLOAT32_C(   866.01), SIMDE_FLOAT32_C(   418.68), SIMDE_FLOAT32_C(  -335.11) },
      { SIMDE_FLOAT32_C(   918.74), SIMDE_FLOAT32_C(   866.01), SIMDE_FLOAT32_C(   418.68), SIMDE_FLOAT32_C(   290.07) } },
    { { SIMDE_FLOAT32_C(   662.83), SIMDE_FLOAT32_C(  -123.07), SIMDE_FLOAT32_C(  -351.72), SIMDE_FLOAT32_C(  -542.32) },
      { SIMDE_FLOAT32_C(   138.79), SIMDE_FLOAT32_C(   751.84), SIMDE_FLOAT32_C(   820.37), SIMDE_FLOAT32_C(   602.97) },
      { SIMDE_FLOAT32_C(   662.83), SIMDE_FLOAT32_C(   751.84), SIMDE_FLOAT32_C(   820.37), SIMDE_FLOAT32_C(   602.97) } },
    { { SIMDE_FLOAT32_C(  -358.34), SIMDE_FLOAT32_C(  -868.49), SIMDE_FLOAT32_C(  -165.86), SIMDE_FLOAT32_C(  -123.83) },
      { SIMDE_FLOAT32_C(  -211.99), SIMDE_FLOAT32_C(  -353.93), SIMDE_FLOAT32_C(  -564.80), SIMDE_FLOAT32_C(  -201.70) },
      { SIMDE_FLOAT32_C(  -211.99), SIMDE_FLOAT32_C(  -353.93), SIMDE_FLOAT32_C(  -165.86), SIMDE_FLOAT32_C(  -123.83) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_max_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_max_pu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8( 95,  35, 185, 136, 198,  90, 109, 138),
      simde_x_mm_set_pu8(165,  90, 139, 114, 195, 147,  62, 160),
      simde_x_mm_set_pu8(165,  90, 185, 136, 198, 147, 109, 160) },
    { simde_x_mm_set_pu8(192, 104, 198, 106, 121, 208, 222,  80),
      simde_x_mm_set_pu8( 14,  66, 107, 237,  19, 244, 121, 240),
      simde_x_mm_set_pu8(192, 104, 198, 237, 121, 244, 222, 240) },
    { simde_x_mm_set_pu8( 95,  71, 177, 202,  66,  32,  85, 206),
      simde_x_mm_set_pu8(206, 134,  86, 165, 246, 242, 112, 247),
      simde_x_mm_set_pu8(206, 134, 177, 202, 246, 242, 112, 247) },
    { simde_x_mm_set_pu8(247, 220,   6,  72, 190, 176, 185, 129),
      simde_x_mm_set_pu8(102, 233,  69,  70,  65,  36, 164, 122),
      simde_x_mm_set_pu8(247, 233,  69,  72, 190, 176, 185, 129) },
    { simde_x_mm_set_pu8(121,  66, 178,  31,  46,  35, 117,  91),
      simde_x_mm_set_pu8(162, 127, 145,  79, 214,  91, 102,  58),
      simde_x_mm_set_pu8(162, 127, 178,  79, 214,  91, 117,  91) },
    { simde_x_mm_set_pu8( 75,  55, 102,  27, 144, 219,  63,  26),
      simde_x_mm_set_pu8(178, 228,  83,  88,  34,  43, 215,  34),
      simde_x_mm_set_pu8(178, 228, 102,  88, 144, 219, 215,  34) },
    { simde_x_mm_set_pu8( 71, 199, 130, 210,  23, 163, 117, 223),
      simde_x_mm_set_pu8( 47, 138,  43,  60, 152,  77, 246,   8),
      simde_x_mm_set_pu8( 71, 199, 130, 210, 152, 163, 246, 223) },
    { simde_x_mm_set_pu8( 65, 226,  26,  83, 148,  71,   8, 192),
      simde_x_mm_set_pu8( 48,  22, 250, 180,  93,  65,  44,  38),
      simde_x_mm_set_pu8( 65, 226, 250, 180, 148,  71,  44, 192) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_max_pu8(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u8x8(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pmaxub(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8( 95,  35, 185, 136, 198,  90, 109, 138),
      simde_x_mm_set_pu8(165,  90, 139, 114, 195, 147,  62, 160),
      simde_x_mm_set_pu8(165,  90, 185, 136, 198, 147, 109, 160) },
    { simde_x_mm_set_pu8(192, 104, 198, 106, 121, 208, 222,  80),
      simde_x_mm_set_pu8( 14,  66, 107, 237,  19, 244, 121, 240),
      simde_x_mm_set_pu8(192, 104, 198, 237, 121, 244, 222, 240) },
    { simde_x_mm_set_pu8( 95,  71, 177, 202,  66,  32,  85, 206),
      simde_x_mm_set_pu8(206, 134,  86, 165, 246, 242, 112, 247),
      simde_x_mm_set_pu8(206, 134, 177, 202, 246, 242, 112, 247) },
    { simde_x_mm_set_pu8(247, 220,   6,  72, 190, 176, 185, 129),
      simde_x_mm_set_pu8(102, 233,  69,  70,  65,  36, 164, 122),
      simde_x_mm_set_pu8(247, 233,  69,  72, 190, 176, 185, 129) },
    { simde_x_mm_set_pu8(121,  66, 178,  31,  46,  35, 117,  91),
      simde_x_mm_set_pu8(162, 127, 145,  79, 214,  91, 102,  58),
      simde_x_mm_set_pu8(162, 127, 178,  79, 214,  91, 117,  91) },
    { simde_x_mm_set_pu8( 75,  55, 102,  27, 144, 219,  63,  26),
      simde_x_mm_set_pu8(178, 228,  83,  88,  34,  43, 215,  34),
      simde_x_mm_set_pu8(178, 228, 102,  88, 144, 219, 215,  34) },
    { simde_x_mm_set_pu8( 71, 199, 130, 210,  23, 163, 117, 223),
      simde_x_mm_set_pu8( 47, 138,  43,  60, 152,  77, 246,   8),
      simde_x_mm_set_pu8( 71, 199, 130, 210, 152, 163, 246, 223) },
    { simde_x_mm_set_pu8( 65, 226,  26,  83, 148,  71,   8, 192),
      simde_x_mm_set_pu8( 48,  22, 250, 180,  93,  65,  44,  38),
      simde_x_mm_set_pu8( 65, 226, 250, 180, 148,  71,  44, 192) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_m_pmaxub(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u8x8(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_max_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 275.98f,  244.68f,  294.03f,  414.26f),
      simde_mm_set_ps( 915.80f,   -0.19f,   23.06f,   81.33f),
      simde_mm_set_ps( 275.98f,  244.68f,  294.03f,  414.26f) },
    { simde_mm_set_ps(-813.38f,  435.35f,  419.41f, -441.22f),
      simde_mm_set_ps( 389.17f, -536.41f, -137.18f, -787.72f),
      simde_mm_set_ps(-813.38f,  435.35f,  419.41f, -441.22f) },
    { simde_mm_set_ps(-619.96f, -614.05f, -479.78f, -823.70f),
      simde_mm_set_ps(-814.29f,  295.27f, -132.00f,  -70.04f),
      simde_mm_set_ps(-619.96f, -614.05f, -479.78f,  -70.04f) },
    { simde_mm_set_ps(-480.26f, -233.90f,  242.17f, -129.02f),
      simde_mm_set_ps(-777.79f, -728.41f,  -33.93f, -163.52f),
      simde_mm_set_ps(-480.26f, -233.90f,  242.17f, -129.02f) },
    { simde_mm_set_ps(-442.14f,  410.97f,  665.05f, -946.79f),
      simde_mm_set_ps(-545.42f,   47.51f,  -78.24f, -648.70f),
      simde_mm_set_ps(-442.14f,  410.97f,  665.05f, -648.70f) },
    { simde_mm_set_ps(-136.30f, -558.74f,  355.69f,   48.70f),
      simde_mm_set_ps(-820.06f, -448.36f,  -48.18f, -396.98f),
      simde_mm_set_ps(-136.30f, -558.74f,  355.69f,   48.70f) },
    { simde_mm_set_ps( 955.43f, -448.98f, -165.93f,   79.87f),
      simde_mm_set_ps(-380.33f,  295.42f,  -77.30f,  721.77f),
      simde_mm_set_ps( 955.43f, -448.98f, -165.93f,  721.77f) },
    { simde_mm_set_ps( -40.78f,  393.73f,  -60.99f, -143.02f),
      simde_mm_set_ps(-232.14f,   77.20f, -606.64f, -624.14f),
      simde_mm_set_ps( -40.78f,  393.73f,  -60.99f, -143.02f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_max_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_min_pi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(-17712,  12551, -23434, -13133),
      simde_mm_set_pi16( 26266, -20490,   7912,  29803),
      simde_mm_set_pi16(-17712, -20490, -23434, -13133) },
    { simde_mm_set_pi16(-24457,  29877, -26735, -29539),
      simde_mm_set_pi16( 11486,  18014,  20714, -14577),
      simde_mm_set_pi16(-24457,  18014, -26735, -29539) },
    { simde_mm_set_pi16(-20528,   7690,  11233,  -7462),
      simde_mm_set_pi16(-32519,   4248, -31417, -32471),
      simde_mm_set_pi16(-32519,   4248, -31417, -32471) },
    { simde_mm_set_pi16(-31520,   3559, -26842,  21046),
      simde_mm_set_pi16( 13846,  -3714,  16375,  18158),
      simde_mm_set_pi16(-31520,  -3714, -26842,  18158) },
    { simde_mm_set_pi16( 21922,   9874,  13654,  24031),
      simde_mm_set_pi16( 23732,  13322,   8641,  -2491),
      simde_mm_set_pi16( 21922,   9874,   8641,  -2491) },
    { simde_mm_set_pi16( 14557,   3319,  16372,  28742),
      simde_mm_set_pi16(-29436,  20833, -11479, -29779),
      simde_mm_set_pi16(-29436,   3319, -11479, -29779) },
    { simde_mm_set_pi16( 14514,  25528,  18329,  19467),
      simde_mm_set_pi16(  7807, -10832,  -5002, -30632),
      simde_mm_set_pi16(  7807, -10832,  -5002, -30632) },
    { simde_mm_set_pi16( 10007,  31428,  28911, -29602),
      simde_mm_set_pi16( 29865, -25102,  11884,   9524),
      simde_mm_set_pi16( 10007, -25102,  11884, -29602) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_min_pi16(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pminsw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(-17712,  12551, -23434, -13133),
      simde_mm_set_pi16( 26266, -20490,   7912,  29803),
      simde_mm_set_pi16(-17712, -20490, -23434, -13133) },
    { simde_mm_set_pi16(-24457,  29877, -26735, -29539),
      simde_mm_set_pi16( 11486,  18014,  20714, -14577),
      simde_mm_set_pi16(-24457,  18014, -26735, -29539) },
    { simde_mm_set_pi16(-20528,   7690,  11233,  -7462),
      simde_mm_set_pi16(-32519,   4248, -31417, -32471),
      simde_mm_set_pi16(-32519,   4248, -31417, -32471) },
    { simde_mm_set_pi16(-31520,   3559, -26842,  21046),
      simde_mm_set_pi16( 13846,  -3714,  16375,  18158),
      simde_mm_set_pi16(-31520,  -3714, -26842,  18158) },
    { simde_mm_set_pi16( 21922,   9874,  13654,  24031),
      simde_mm_set_pi16( 23732,  13322,   8641,  -2491),
      simde_mm_set_pi16( 21922,   9874,   8641,  -2491) },
    { simde_mm_set_pi16( 14557,   3319,  16372,  28742),
      simde_mm_set_pi16(-29436,  20833, -11479, -29779),
      simde_mm_set_pi16(-29436,   3319, -11479, -29779) },
    { simde_mm_set_pi16( 14514,  25528,  18329,  19467),
      simde_mm_set_pi16(  7807, -10832,  -5002, -30632),
      simde_mm_set_pi16(  7807, -10832,  -5002, -30632) },
    { simde_mm_set_pi16( 10007,  31428,  28911, -29602),
      simde_mm_set_pi16( 29865, -25102,  11884,   9524),
      simde_mm_set_pi16( 10007, -25102,  11884, -29602) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_m_pminsw(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_min_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    52.40),            SIMDE_MATH_NANF,       SIMDE_MATH_INFINITYF },
        { SIMDE_FLOAT32_C(    17.29),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -535.67) },
        { SIMDE_FLOAT32_C(    17.29),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -535.67) } },
      { { SIMDE_FLOAT32_C(    52.40),      -SIMDE_MATH_INFINITYF,      -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF },
        {       SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   299.86),            SIMDE_MATH_NANF,       SIMDE_MATH_INFINITYF },
        { SIMDE_FLOAT32_C(    52.40),      -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,       SIMDE_MATH_INFINITYF } },
    #endif
    { { SIMDE_FLOAT32_C(  -711.87), SIMDE_FLOAT32_C(    44.39), SIMDE_FLOAT32_C(  -762.65), SIMDE_FLOAT32_C(  -621.30) },
      { SIMDE_FLOAT32_C(   258.76), SIMDE_FLOAT32_C(  -263.48), SIMDE_FLOAT32_C(   915.20), SIMDE_FLOAT32_C(   737.73) },
      { SIMDE_FLOAT32_C(  -711.87), SIMDE_FLOAT32_C(  -263.48), SIMDE_FLOAT32_C(  -762.65), SIMDE_FLOAT32_C(  -621.30) } },
    { { SIMDE_FLOAT32_C(   263.09), SIMDE_FLOAT32_C(     2.29), SIMDE_FLOAT32_C(  -485.34), SIMDE_FLOAT32_C(  -760.23) },
      { SIMDE_FLOAT32_C(  -189.22), SIMDE_FLOAT32_C(   207.98), SIMDE_FLOAT32_C(   885.59), SIMDE_FLOAT32_C(   -61.86) },
      { SIMDE_FLOAT32_C(  -189.22), SIMDE_FLOAT32_C(     2.29), SIMDE_FLOAT32_C(  -485.34), SIMDE_FLOAT32_C(  -760.23) } },
    { { SIMDE_FLOAT32_C(  -140.13), SIMDE_FLOAT32_C(  -387.88), SIMDE_FLOAT32_C(  -850.20), SIMDE_FLOAT32_C(   265.81) },
      { SIMDE_FLOAT32_C(   267.32), SIMDE_FLOAT32_C(   453.87), SIMDE_FLOAT32_C(   754.87), SIMDE_FLOAT32_C(  -301.67) },
      { SIMDE_FLOAT32_C(  -140.13), SIMDE_FLOAT32_C(  -387.88), SIMDE_FLOAT32_C(  -850.20), SIMDE_FLOAT32_C(  -301.67) } },
    { { SIMDE_FLOAT32_C(   478.04), SIMDE_FLOAT32_C(  -504.48), SIMDE_FLOAT32_C(  -579.57), SIMDE_FLOAT32_C(   714.80) },
      { SIMDE_FLOAT32_C(   431.69), SIMDE_FLOAT32_C(  -177.02), SIMDE_FLOAT32_C(  -184.05), SIMDE_FLOAT32_C(   719.83) },
      { SIMDE_FLOAT32_C(   431.69), SIMDE_FLOAT32_C(  -504.48), SIMDE_FLOAT32_C(  -579.57), SIMDE_FLOAT32_C(   714.80) } },
    { { SIMDE_FLOAT32_C(   867.37), SIMDE_FLOAT32_C(    53.30), SIMDE_FLOAT32_C(  -901.47), SIMDE_FLOAT32_C(   126.14) },
      { SIMDE_FLOAT32_C(   789.82), SIMDE_FLOAT32_C(  -986.27), SIMDE_FLOAT32_C(  -136.13), SIMDE_FLOAT32_C(    52.91) },
      { SIMDE_FLOAT32_C(   789.82), SIMDE_FLOAT32_C(  -986.27), SIMDE_FLOAT32_C(  -901.47), SIMDE_FLOAT32_C(    52.91) } },
    { { SIMDE_FLOAT32_C(    16.02), SIMDE_FLOAT32_C(   378.53), SIMDE_FLOAT32_C(   292.68), SIMDE_FLOAT32_C(   826.80) },
      { SIMDE_FLOAT32_C(  -413.49), SIMDE_FLOAT32_C(   178.27), SIMDE_FLOAT32_C(  -235.07), SIMDE_FLOAT32_C(   446.39) },
      { SIMDE_FLOAT32_C(  -413.49), SIMDE_FLOAT32_C(   178.27), SIMDE_FLOAT32_C(  -235.07), SIMDE_FLOAT32_C(   446.39) } },
    { { SIMDE_FLOAT32_C(   790.39), SIMDE_FLOAT32_C(   -85.27), SIMDE_FLOAT32_C(  -287.81), SIMDE_FLOAT32_C(    57.70) },
      { SIMDE_FLOAT32_C(  -631.40), SIMDE_FLOAT32_C(  -532.94), SIMDE_FLOAT32_C(   756.03), SIMDE_FLOAT32_C(   846.64) },
      { SIMDE_FLOAT32_C(  -631.40), SIMDE_FLOAT32_C(  -532.94), SIMDE_FLOAT32_C(  -287.81), SIMDE_FLOAT32_C(    57.70) } },
    { { SIMDE_FLOAT32_C(   -37.42), SIMDE_FLOAT32_C(  -823.54), SIMDE_FLOAT32_C(   561.44), SIMDE_FLOAT32_C(  -605.72) },
      { SIMDE_FLOAT32_C(    -0.56), SIMDE_FLOAT32_C(  -622.61), SIMDE_FLOAT32_C(  -885.90), SIMDE_FLOAT32_C(  -133.18) },
      { SIMDE_FLOAT32_C(   -37.42), SIMDE_FLOAT32_C(  -823.54), SIMDE_FLOAT32_C(  -885.90), SIMDE_FLOAT32_C(  -605.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_min_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_min_pu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(  3,  32, 201, 226, 126, 175,  31,  50),
      simde_x_mm_set_pu8(220, 148, 109, 216,  32, 219, 221, 116),
      simde_x_mm_set_pu8(  3,  32, 109, 216,  32, 175,  31,  50) },
    { simde_x_mm_set_pu8(123, 186, 147,  62,  85, 163, 217, 248),
      simde_x_mm_set_pu8( 50, 187, 220, 240, 243, 231, 241, 209),
      simde_x_mm_set_pu8( 50, 186, 147,  62,  85, 163, 217, 209) },
    { simde_x_mm_set_pu8(100,  27,  19,  67, 100, 214, 111, 154),
      simde_x_mm_set_pu8( 31,  16,  59, 138, 178,  43,  63, 213),
      simde_x_mm_set_pu8( 31,  16,  19,  67, 100,  43,  63, 154) },
    { simde_x_mm_set_pu8(205, 136,  79, 245, 178, 167,   7,   9),
      simde_x_mm_set_pu8(103, 214, 180, 123,  12, 141,  59, 104),
      simde_x_mm_set_pu8(103, 136,  79, 123,  12, 141,   7,   9) },
    { simde_x_mm_set_pu8(143, 111, 158,  95, 192,  18,  83,  18),
      simde_x_mm_set_pu8( 81, 138, 112,  76,  64, 169,  64,  35),
      simde_x_mm_set_pu8( 81, 111, 112,  76,  64,  18,  64,  18) },
    { simde_x_mm_set_pu8(246, 106, 240, 187, 202, 248,   5, 105),
      simde_x_mm_set_pu8(184, 221, 161, 239, 162, 163,  17, 109),
      simde_x_mm_set_pu8(184, 106, 161, 187, 162, 163,   5, 105) },
    { simde_x_mm_set_pu8(172,  59,  82,   1, 130,  31, 233,  87),
      simde_x_mm_set_pu8( 51, 153, 219,  33, 100, 204, 105, 228),
      simde_x_mm_set_pu8( 51,  59,  82,   1, 100,  31, 105,  87) },
    { simde_x_mm_set_pu8(228, 182, 179, 248,  70,  35,  65,  84),
      simde_x_mm_set_pu8( 84, 159, 106,   2, 156, 107, 120,  67),
      simde_x_mm_set_pu8( 84, 159, 106,   2,  70,  35,  65,  67) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_min_pu8(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u8x8(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pminub(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(  3,  32, 201, 226, 126, 175,  31,  50),
      simde_x_mm_set_pu8(220, 148, 109, 216,  32, 219, 221, 116),
      simde_x_mm_set_pu8(  3,  32, 109, 216,  32, 175,  31,  50) },
    { simde_x_mm_set_pu8(123, 186, 147,  62,  85, 163, 217, 248),
      simde_x_mm_set_pu8( 50, 187, 220, 240, 243, 231, 241, 209),
      simde_x_mm_set_pu8( 50, 186, 147,  62,  85, 163, 217, 209) },
    { simde_x_mm_set_pu8(100,  27,  19,  67, 100, 214, 111, 154),
      simde_x_mm_set_pu8( 31,  16,  59, 138, 178,  43,  63, 213),
      simde_x_mm_set_pu8( 31,  16,  19,  67, 100,  43,  63, 154) },
    { simde_x_mm_set_pu8(205, 136,  79, 245, 178, 167,   7,   9),
      simde_x_mm_set_pu8(103, 214, 180, 123,  12, 141,  59, 104),
      simde_x_mm_set_pu8(103, 136,  79, 123,  12, 141,   7,   9) },
    { simde_x_mm_set_pu8(143, 111, 158,  95, 192,  18,  83,  18),
      simde_x_mm_set_pu8( 81, 138, 112,  76,  64, 169,  64,  35),
      simde_x_mm_set_pu8( 81, 111, 112,  76,  64,  18,  64,  18) },
    { simde_x_mm_set_pu8(246, 106, 240, 187, 202, 248,   5, 105),
      simde_x_mm_set_pu8(184, 221, 161, 239, 162, 163,  17, 109),
      simde_x_mm_set_pu8(184, 106, 161, 187, 162, 163,   5, 105) },
    { simde_x_mm_set_pu8(172,  59,  82,   1, 130,  31, 233,  87),
      simde_x_mm_set_pu8( 51, 153, 219,  33, 100, 204, 105, 228),
      simde_x_mm_set_pu8( 51,  59,  82,   1, 100,  31, 105,  87) },
    { simde_x_mm_set_pu8(228, 182, 179, 248,  70,  35,  65,  84),
      simde_x_mm_set_pu8( 84, 159, 106,   2, 156, 107, 120,  67),
      simde_x_mm_set_pu8( 84, 159, 106,   2,  70,  35,  65,  67) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_m_pminub(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u8x8(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_min_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 905.52f, -330.94f, -743.29f,  -10.28f),
      simde_mm_set_ps(-603.64f,  -33.37f,  723.28f, -975.56f),
      simde_mm_set_ps( 905.52f, -330.94f, -743.29f, -975.56f) },
    { simde_mm_set_ps(-901.94f,  395.72f,  391.94f, -212.21f),
      simde_mm_set_ps(-188.76f,  605.72f, -757.32f, -217.92f),
      simde_mm_set_ps(-901.94f,  395.72f,  391.94f, -217.92f) },
    { simde_mm_set_ps( 270.60f,  585.69f, -494.83f,  500.56f),
      simde_mm_set_ps( 444.26f,  925.14f, -362.96f,  120.59f),
      simde_mm_set_ps( 270.60f,  585.69f, -494.83f,  120.59f) },
    { simde_mm_set_ps( 222.03f, -452.05f, -212.51f,   16.60f),
      simde_mm_set_ps(-338.89f,  786.83f, -596.87f,  345.56f),
      simde_mm_set_ps( 222.03f, -452.05f, -212.51f,   16.60f) },
    { simde_mm_set_ps( 130.17f, -389.05f, -693.23f, -558.79f),
      simde_mm_set_ps( 351.18f,    1.64f,  661.55f,  667.31f),
      simde_mm_set_ps( 130.17f, -389.05f, -693.23f, -558.79f) },
    { simde_mm_set_ps(-492.87f,  857.67f,   99.45f, -129.44f),
      simde_mm_set_ps( 424.94f,  552.64f,   68.12f,  195.21f),
      simde_mm_set_ps(-492.87f,  857.67f,   99.45f, -129.44f) },
    { simde_mm_set_ps( 213.75f,  969.89f, -341.00f,  -19.41f),
      simde_mm_set_ps( 773.33f, -228.51f,   68.57f, -153.07f),
      simde_mm_set_ps( 213.75f,  969.89f, -341.00f, -153.07f) },
    { simde_mm_set_ps(-482.05f, -169.03f, -647.88f, -151.80f),
      simde_mm_set_ps( 604.32f, -221.45f,  450.87f, -490.43f),
      simde_mm_set_ps(-482.05f, -169.03f, -647.88f, -490.43f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_min_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_move_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-358.23f,  557.58f,  318.93f, -758.38f),
      simde_mm_set_ps(   1.51f,  975.39f, -136.78f, -157.41f),
      simde_mm_set_ps(-358.23f,  557.58f,  318.93f, -157.41f) },
    { simde_mm_set_ps(-944.08f, -768.00f,  457.67f,  835.58f),
      simde_mm_set_ps(-700.69f,  960.42f,  670.21f, -766.17f),
      simde_mm_set_ps(-944.08f, -768.00f,  457.67f, -766.17f) },
    { simde_mm_set_ps(-640.75f,   79.11f, -809.30f, -582.60f),
      simde_mm_set_ps( 451.92f,  260.70f, -368.72f, -418.36f),
      simde_mm_set_ps(-640.75f,   79.11f, -809.30f, -418.36f) },
    { simde_mm_set_ps(-265.37f, -906.15f,  463.48f,  857.51f),
      simde_mm_set_ps(  52.86f, -189.27f,  -89.79f,  636.22f),
      simde_mm_set_ps(-265.37f, -906.15f,  463.48f,  636.22f) },
    { simde_mm_set_ps( 627.30f, -419.51f,  242.55f, -669.89f),
      simde_mm_set_ps( 891.75f,  884.03f,  808.69f,   48.90f),
      simde_mm_set_ps( 627.30f, -419.51f,  242.55f,   48.90f) },
    { simde_mm_set_ps( 162.10f, -144.97f,  -36.34f,  747.42f),
      simde_mm_set_ps( 962.83f,  377.89f, -519.04f, -497.15f),
      simde_mm_set_ps( 162.10f, -144.97f,  -36.34f, -497.15f) },
    { simde_mm_set_ps(-230.32f,  536.55f, -396.11f,  274.97f),
      simde_mm_set_ps(-442.89f,  237.99f, -587.16f,  603.90f),
      simde_mm_set_ps(-230.32f,  536.55f, -396.11f,  603.90f) },
    { simde_mm_set_ps(-213.83f,  999.36f,  795.03f,  885.52f),
      simde_mm_set_ps(-878.99f, -162.39f,   89.22f, -749.67f),
      simde_mm_set_ps(-213.83f,  999.36f,  795.03f, -749.67f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_move_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_movehl_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 448.42f,  812.28f, -569.58f, -612.98f),
      simde_mm_set_ps(-260.91f,  851.49f, -543.31f, -452.37f),
      simde_mm_set_ps( 448.42f,  812.28f, -260.91f,  851.49f) },
    { simde_mm_set_ps( 164.79f, -510.29f, -875.53f,  338.43f),
      simde_mm_set_ps( 195.22f, -222.31f, -247.28f, -544.38f),
      simde_mm_set_ps( 164.79f, -510.29f,  195.22f, -222.31f) },
    { simde_mm_set_ps( 632.26f, -381.04f, -465.25f, -913.48f),
      simde_mm_set_ps(-790.33f, -504.12f, -321.51f, -760.29f),
      simde_mm_set_ps( 632.26f, -381.04f, -790.33f, -504.12f) },
    { simde_mm_set_ps( 203.91f,  884.83f, -352.58f, -259.85f),
      simde_mm_set_ps(  92.13f,  448.80f,  494.59f,  -13.35f),
      simde_mm_set_ps( 203.91f,  884.83f,   92.13f,  448.80f) },
    { simde_mm_set_ps( 223.91f, -533.66f,  185.50f, -579.52f),
      simde_mm_set_ps(-316.81f, -862.60f, -895.66f,  129.46f),
      simde_mm_set_ps( 223.91f, -533.66f, -316.81f, -862.60f) },
    { simde_mm_set_ps(-731.11f,  221.64f,  388.77f,   -5.75f),
      simde_mm_set_ps(-220.42f,  -24.67f, -629.56f, -668.90f),
      simde_mm_set_ps(-731.11f,  221.64f, -220.42f,  -24.67f) },
    { simde_mm_set_ps(-367.65f,  429.37f,  435.99f,  954.93f),
      simde_mm_set_ps( 382.29f, -511.24f,  874.66f,  450.20f),
      simde_mm_set_ps(-367.65f,  429.37f,  382.29f, -511.24f) },
    { simde_mm_set_ps( 917.13f, -437.03f, -611.86f, -766.78f),
      simde_mm_set_ps( -43.20f, -568.30f,  -68.56f, -878.32f),
      simde_mm_set_ps( 917.13f, -437.03f,  -43.20f, -568.30f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_movehl_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_movelh_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-126.61f, -366.61f,  342.01f, -290.15f),
      simde_mm_set_ps( 691.90f, -944.15f,   99.58f,  438.89f),
      simde_mm_set_ps(  99.58f,  438.89f,  342.01f, -290.15f) },
    { simde_mm_set_ps(-879.79f,  930.29f,  951.33f,  492.78f),
      simde_mm_set_ps( 600.74f, -198.87f,  936.84f,  313.69f),
      simde_mm_set_ps( 936.84f,  313.69f,  951.33f,  492.78f) },
    { simde_mm_set_ps(-467.81f, -802.41f,  821.13f, -596.55f),
      simde_mm_set_ps( 695.24f,  173.94f, -480.51f,  -41.27f),
      simde_mm_set_ps(-480.51f,  -41.27f,  821.13f, -596.55f) },
    { simde_mm_set_ps( 645.54f,  -99.35f, -669.53f, -518.75f),
      simde_mm_set_ps( 261.98f,   -2.77f,  -35.85f, -725.12f),
      simde_mm_set_ps( -35.85f, -725.12f, -669.53f, -518.75f) },
    { simde_mm_set_ps( 851.93f,  376.50f, -125.53f,  315.67f),
      simde_mm_set_ps( 722.06f, -287.10f,  806.63f, -831.38f),
      simde_mm_set_ps( 806.63f, -831.38f, -125.53f,  315.67f) },
    { simde_mm_set_ps(-180.42f, -861.51f,  293.97f,  929.27f),
      simde_mm_set_ps( -61.47f, -964.08f, -555.27f,  147.09f),
      simde_mm_set_ps(-555.27f,  147.09f,  293.97f,  929.27f) },
    { simde_mm_set_ps( 294.20f,   18.46f,  779.53f, -177.14f),
      simde_mm_set_ps( 664.57f,  349.92f,  797.65f,  206.26f),
      simde_mm_set_ps( 797.65f,  206.26f,  779.53f, -177.14f) },
    { simde_mm_set_ps(-737.06f, -946.48f, -251.45f, -808.64f),
      simde_mm_set_ps(-245.46f,  616.13f, -342.03f,  914.50f),
      simde_mm_set_ps(-342.03f,  914.50f, -251.45f, -808.64f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_movelh_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_movemask_pi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pi8(   7,  -33,    4,  -58,  -87,   16,   83,  -97),  89 },
    { simde_mm_set_pi8(  28,  -40,  -15, -114,  -71,  -97,  -12,  -53), 127 },
    { simde_mm_set_pi8( -16,  -80,   47,   37,   16, -111,  120,  -12), 197 },
    { simde_mm_set_pi8(   4,  -17,  -44,   -3,  -35,   81,  -87,   97), 122 },
    { simde_mm_set_pi8( -84,   23,   93,   30,   87,  114,   66,   94), 128 },
    { simde_mm_set_pi8(  -1,  -24,   -4,  -87,   33,   91,   32,   43), 240 },
    { simde_mm_set_pi8( -11,   96,  -68,   84,   53, -120,  124,   -4), 165 },
    { simde_mm_set_pi8(-122,   91,   -3,  -17,  -54,   62,  119,  -40), 185 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_movemask_pi8(test_vec[i].a);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pmovmskb(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pi8(   7,  -33,    4,  -58,  -87,   16,   83,  -97),  89 },
    { simde_mm_set_pi8(  28,  -40,  -15, -114,  -71,  -97,  -12,  -53), 127 },
    { simde_mm_set_pi8( -16,  -80,   47,   37,   16, -111,  120,  -12), 197 },
    { simde_mm_set_pi8(   4,  -17,  -44,   -3,  -35,   81,  -87,   97), 122 },
    { simde_mm_set_pi8( -84,   23,   93,   30,   87,  114,   66,   94), 128 },
    { simde_mm_set_pi8(  -1,  -24,   -4,  -87,   33,   91,   32,   43), 240 },
    { simde_mm_set_pi8( -11,   96,  -68,   84,   53, -120,  124,   -4), 165 },
    { simde_mm_set_pi8(-122,   91,   -3,  -17,  -54,   62,  119,  -40), 185 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_m_pmovmskb(test_vec[i].a);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_movemask_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    int r;
  } test_vec[8] = {
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0xa67d815d), UINT32_C(0x313ba9ba), UINT32_C(0x21c24eef), UINT32_C(0x423f8c9e))),   8 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0x489edd7d), UINT32_C(0x67cd5a03), UINT32_C(0x615ae189), UINT32_C(0x97259ce3))),   1 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0xe28d2b70), UINT32_C(0xe91a3281), UINT32_C(0x73d2c004), UINT32_C(0x7cc3587e))),  12 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0xb38e9200), UINT32_C(0xd86e4d45), UINT32_C(0xd67c3858), UINT32_C(0x6dd9c655))),  14 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0x3324bf52), UINT32_C(0x86f260cf), UINT32_C(0x1c6c8682), UINT32_C(0x53be68fe))),   4 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0xf2018c61), UINT32_C(0x250c57a7), UINT32_C(0x0654d448), UINT32_C(0x8a06fe60))),   9 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0x0430e063), UINT32_C(0x7ffc7ad3), UINT32_C(0x9306516d), UINT32_C(0x5896591c))),   2 },
    { simde_mm_castsi128_ps(simde_x_mm_set_epu32(UINT32_C(0xfa68023e), UINT32_C(0x2e799bce), UINT32_C(0x88c4c4ea), UINT32_C(0x31bc8ed8))),  10 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_movemask_ps(test_vec[i].a);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mul_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  954.95), SIMDE_FLOAT32_C(  261.79), SIMDE_FLOAT32_C( -313.98), SIMDE_FLOAT32_C(  739.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -996.12), SIMDE_FLOAT32_C(  311.86), SIMDE_FLOAT32_C( -571.44), SIMDE_FLOAT32_C(  595.57)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-951244.81), SIMDE_FLOAT32_C(81641.83), SIMDE_FLOAT32_C(179420.73), SIMDE_FLOAT32_C(440245.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -636.86), SIMDE_FLOAT32_C( -888.18), SIMDE_FLOAT32_C(  244.79), SIMDE_FLOAT32_C( -720.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -205.91), SIMDE_FLOAT32_C( -899.67), SIMDE_FLOAT32_C(  -45.24), SIMDE_FLOAT32_C(  371.39)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(131135.84), SIMDE_FLOAT32_C(799068.88), SIMDE_FLOAT32_C(-11074.30), SIMDE_FLOAT32_C(-267683.06)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -261.34), SIMDE_FLOAT32_C(  756.03), SIMDE_FLOAT32_C( -536.77), SIMDE_FLOAT32_C(  470.04)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -270.28), SIMDE_FLOAT32_C( -385.03), SIMDE_FLOAT32_C( -550.64), SIMDE_FLOAT32_C(  -31.96)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(70634.98), SIMDE_FLOAT32_C(-291094.25), SIMDE_FLOAT32_C(295567.06), SIMDE_FLOAT32_C(-15022.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  670.10), SIMDE_FLOAT32_C(  171.23), SIMDE_FLOAT32_C( -843.34), SIMDE_FLOAT32_C( -179.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  422.05), SIMDE_FLOAT32_C(  672.20), SIMDE_FLOAT32_C(   26.32), SIMDE_FLOAT32_C( -386.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(282815.69), SIMDE_FLOAT32_C(115100.80), SIMDE_FLOAT32_C(-22196.71), SIMDE_FLOAT32_C(69377.40)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  312.99), SIMDE_FLOAT32_C(  740.76), SIMDE_FLOAT32_C(  751.62), SIMDE_FLOAT32_C(  667.74)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  773.99), SIMDE_FLOAT32_C( -645.18), SIMDE_FLOAT32_C(  712.40), SIMDE_FLOAT32_C(  206.98)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(242251.12), SIMDE_FLOAT32_C(-477923.53), SIMDE_FLOAT32_C(535454.12), SIMDE_FLOAT32_C(138208.83)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   80.67), SIMDE_FLOAT32_C(  206.46), SIMDE_FLOAT32_C(  384.59), SIMDE_FLOAT32_C( -166.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  113.49), SIMDE_FLOAT32_C( -659.02), SIMDE_FLOAT32_C(  494.54), SIMDE_FLOAT32_C(  459.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 9155.24), SIMDE_FLOAT32_C(-136061.28), SIMDE_FLOAT32_C(190195.14), SIMDE_FLOAT32_C(-76497.22)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -139.02), SIMDE_FLOAT32_C( -702.78), SIMDE_FLOAT32_C( -728.15), SIMDE_FLOAT32_C( -708.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  433.72), SIMDE_FLOAT32_C(  494.77), SIMDE_FLOAT32_C( -283.59), SIMDE_FLOAT32_C(  890.69)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-60295.76), SIMDE_FLOAT32_C(-347714.47), SIMDE_FLOAT32_C(206496.06), SIMDE_FLOAT32_C(-631232.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  770.76), SIMDE_FLOAT32_C( -739.61), SIMDE_FLOAT32_C(   17.92), SIMDE_FLOAT32_C(  985.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  803.92), SIMDE_FLOAT32_C( -255.00), SIMDE_FLOAT32_C(  902.16), SIMDE_FLOAT32_C(  -11.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(619629.38), SIMDE_FLOAT32_C(188600.55), SIMDE_FLOAT32_C(16166.71), SIMDE_FLOAT32_C(-11381.02)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_mul_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_mul_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -140.76), SIMDE_FLOAT32_C(    33.48), SIMDE_FLOAT32_C(  -910.86), SIMDE_FLOAT32_C(   198.54)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -93.54), SIMDE_FLOAT32_C(   951.74), SIMDE_FLOAT32_C(   208.33), SIMDE_FLOAT32_C(  -345.25)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -140.76), SIMDE_FLOAT32_C(    33.48), SIMDE_FLOAT32_C(  -910.86), SIMDE_FLOAT32_C(-68545.93)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   609.37), SIMDE_FLOAT32_C(   468.64), SIMDE_FLOAT32_C(    18.66), SIMDE_FLOAT32_C(    58.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -358.79), SIMDE_FLOAT32_C(   577.16), SIMDE_FLOAT32_C(   555.29), SIMDE_FLOAT32_C(  -529.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   609.37), SIMDE_FLOAT32_C(   468.64), SIMDE_FLOAT32_C(    18.66), SIMDE_FLOAT32_C(-31205.22)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -332.93), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   337.69), SIMDE_FLOAT32_C(  -988.14)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -523.52), SIMDE_FLOAT32_C(  -948.77), SIMDE_FLOAT32_C(   316.79), SIMDE_FLOAT32_C(   243.63)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -332.93), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   337.69), SIMDE_FLOAT32_C(-240740.56)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   364.16), SIMDE_FLOAT32_C(   161.67), SIMDE_FLOAT32_C(   286.28), SIMDE_FLOAT32_C(  -439.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   425.79), SIMDE_FLOAT32_C(  -839.17), SIMDE_FLOAT32_C(  -537.00), SIMDE_FLOAT32_C(   731.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   364.16), SIMDE_FLOAT32_C(   161.67), SIMDE_FLOAT32_C(   286.28), SIMDE_FLOAT32_C(-321260.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -250.92), SIMDE_FLOAT32_C(  -215.18), SIMDE_FLOAT32_C(   745.12), SIMDE_FLOAT32_C(   449.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   466.48), SIMDE_FLOAT32_C(  -916.07), SIMDE_FLOAT32_C(  -892.65), SIMDE_FLOAT32_C(   808.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -250.92), SIMDE_FLOAT32_C(  -215.18), SIMDE_FLOAT32_C(   745.12), SIMDE_FLOAT32_C(363635.50)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   423.52), SIMDE_FLOAT32_C(  -740.87), SIMDE_FLOAT32_C(   -85.09), SIMDE_FLOAT32_C(   -24.81)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   458.98), SIMDE_FLOAT32_C(   772.91), SIMDE_FLOAT32_C(  -603.60), SIMDE_FLOAT32_C(  -319.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   423.52), SIMDE_FLOAT32_C(  -740.87), SIMDE_FLOAT32_C(   -85.09), SIMDE_FLOAT32_C(  7931.01)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   347.42), SIMDE_FLOAT32_C(   289.85), SIMDE_FLOAT32_C(   603.24), SIMDE_FLOAT32_C(   660.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -295.61), SIMDE_FLOAT32_C(  -117.86), SIMDE_FLOAT32_C(  -569.10), SIMDE_FLOAT32_C(   741.88)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   347.42), SIMDE_FLOAT32_C(   289.85), SIMDE_FLOAT32_C(   603.24), SIMDE_FLOAT32_C(490048.84)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   162.90), SIMDE_FLOAT32_C(  -653.62), SIMDE_FLOAT32_C(   155.70), SIMDE_FLOAT32_C(   -76.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -537.32), SIMDE_FLOAT32_C(   255.52), SIMDE_FLOAT32_C(  -774.74), SIMDE_FLOAT32_C(   454.04)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   162.90), SIMDE_FLOAT32_C(  -653.62), SIMDE_FLOAT32_C(   155.70), SIMDE_FLOAT32_C(-34561.53)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_mul_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_mulhi_pu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu16(UINT16_C(53192), UINT16_C(40647), UINT16_C(19455), UINT16_C(  638)),
      simde_x_mm_set_pu16(UINT16_C(25315), UINT16_C(56464), UINT16_C(55360), UINT16_C(30008)),
      simde_x_mm_set_pu16(UINT16_C(20546), UINT16_C(35020), UINT16_C(16434), UINT16_C(  292)) },
    { simde_x_mm_set_pu16(UINT16_C(37591), UINT16_C(35425), UINT16_C(33771), UINT16_C(61304)),
      simde_x_mm_set_pu16(UINT16_C( 7821), UINT16_C( 6117), UINT16_C(18035), UINT16_C(21492)),
      simde_x_mm_set_pu16(UINT16_C( 4486), UINT16_C( 3306), UINT16_C( 9293), UINT16_C(20104)) },
    { simde_x_mm_set_pu16(UINT16_C(56491), UINT16_C(  868), UINT16_C(60755), UINT16_C( 8677)),
      simde_x_mm_set_pu16(UINT16_C(58515), UINT16_C(60020), UINT16_C(23196), UINT16_C(54339)),
      simde_x_mm_set_pu16(UINT16_C(50439), UINT16_C(  794), UINT16_C(21503), UINT16_C( 7194)) },
    { simde_x_mm_set_pu16(UINT16_C(20057), UINT16_C(59149), UINT16_C(59878), UINT16_C( 6128)),
      simde_x_mm_set_pu16(UINT16_C(47066), UINT16_C(54772), UINT16_C(43338), UINT16_C(21897)),
      simde_x_mm_set_pu16(UINT16_C(14404), UINT16_C(49434), UINT16_C(39596), UINT16_C( 2047)) },
    { simde_x_mm_set_pu16(UINT16_C(59698), UINT16_C(43803), UINT16_C(12280), UINT16_C(21097)),
      simde_x_mm_set_pu16(UINT16_C(50904), UINT16_C(56386), UINT16_C(59528), UINT16_C( 6251)),
      simde_x_mm_set_pu16(UINT16_C(46369), UINT16_C(37687), UINT16_C(11154), UINT16_C( 2012)) },
    { simde_x_mm_set_pu16(UINT16_C(20821), UINT16_C(22825), UINT16_C(58828), UINT16_C(28131)),
      simde_x_mm_set_pu16(UINT16_C(56256), UINT16_C(14992), UINT16_C( 5527), UINT16_C(36188)),
      simde_x_mm_set_pu16(UINT16_C(17872), UINT16_C( 5221), UINT16_C( 4961), UINT16_C(15533)) },
    { simde_x_mm_set_pu16(UINT16_C(33433), UINT16_C(25342), UINT16_C(10000), UINT16_C(30758)),
      simde_x_mm_set_pu16(UINT16_C(22897), UINT16_C(28868), UINT16_C(29159), UINT16_C(17106)),
      simde_x_mm_set_pu16(UINT16_C(11680), UINT16_C(11162), UINT16_C( 4449), UINT16_C( 8028)) },
    { simde_x_mm_set_pu16(UINT16_C(52226), UINT16_C(24593), UINT16_C(54243), UINT16_C(33338)),
      simde_x_mm_set_pu16(UINT16_C(55013), UINT16_C( 9352), UINT16_C(30196), UINT16_C(22000)),
      simde_x_mm_set_pu16(UINT16_C(43840), UINT16_C( 3509), UINT16_C(24992), UINT16_C(11191)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_mulhi_pu16(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u16x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_m_pmulhuw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu16(UINT16_C(53192), UINT16_C(40647), UINT16_C(19455), UINT16_C(  638)),
      simde_x_mm_set_pu16(UINT16_C(25315), UINT16_C(56464), UINT16_C(55360), UINT16_C(30008)),
      simde_x_mm_set_pu16(UINT16_C(20546), UINT16_C(35020), UINT16_C(16434), UINT16_C(  292)) },
    { simde_x_mm_set_pu16(UINT16_C(37591), UINT16_C(35425), UINT16_C(33771), UINT16_C(61304)),
      simde_x_mm_set_pu16(UINT16_C( 7821), UINT16_C( 6117), UINT16_C(18035), UINT16_C(21492)),
      simde_x_mm_set_pu16(UINT16_C( 4486), UINT16_C( 3306), UINT16_C( 9293), UINT16_C(20104)) },
    { simde_x_mm_set_pu16(UINT16_C(56491), UINT16_C(  868), UINT16_C(60755), UINT16_C( 8677)),
      simde_x_mm_set_pu16(UINT16_C(58515), UINT16_C(60020), UINT16_C(23196), UINT16_C(54339)),
      simde_x_mm_set_pu16(UINT16_C(50439), UINT16_C(  794), UINT16_C(21503), UINT16_C( 7194)) },
    { simde_x_mm_set_pu16(UINT16_C(20057), UINT16_C(59149), UINT16_C(59878), UINT16_C( 6128)),
      simde_x_mm_set_pu16(UINT16_C(47066), UINT16_C(54772), UINT16_C(43338), UINT16_C(21897)),
      simde_x_mm_set_pu16(UINT16_C(14404), UINT16_C(49434), UINT16_C(39596), UINT16_C( 2047)) },
    { simde_x_mm_set_pu16(UINT16_C(59698), UINT16_C(43803), UINT16_C(12280), UINT16_C(21097)),
      simde_x_mm_set_pu16(UINT16_C(50904), UINT16_C(56386), UINT16_C(59528), UINT16_C( 6251)),
      simde_x_mm_set_pu16(UINT16_C(46369), UINT16_C(37687), UINT16_C(11154), UINT16_C( 2012)) },
    { simde_x_mm_set_pu16(UINT16_C(20821), UINT16_C(22825), UINT16_C(58828), UINT16_C(28131)),
      simde_x_mm_set_pu16(UINT16_C(56256), UINT16_C(14992), UINT16_C( 5527), UINT16_C(36188)),
      simde_x_mm_set_pu16(UINT16_C(17872), UINT16_C( 5221), UINT16_C( 4961), UINT16_C(15533)) },
    { simde_x_mm_set_pu16(UINT16_C(33433), UINT16_C(25342), UINT16_C(10000), UINT16_C(30758)),
      simde_x_mm_set_pu16(UINT16_C(22897), UINT16_C(28868), UINT16_C(29159), UINT16_C(17106)),
      simde_x_mm_set_pu16(UINT16_C(11680), UINT16_C(11162), UINT16_C( 4449), UINT16_C( 8028)) },
    { simde_x_mm_set_pu16(UINT16_C(52226), UINT16_C(24593), UINT16_C(54243), UINT16_C(33338)),
      simde_x_mm_set_pu16(UINT16_C(55013), UINT16_C( 9352), UINT16_C(30196), UINT16_C(22000)),
      simde_x_mm_set_pu16(UINT16_C(43840), UINT16_C( 3509), UINT16_C(24992), UINT16_C(11191)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_m_pmulhuw(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u16x4(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_or_ps(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  24636191), -INT32_C( 568024895),  INT32_C(1143850822), -INT32_C(1856938366) },
      { -INT32_C( 367983280), -INT32_C( 385742397), -INT32_C( 219313137),  INT32_C(  79432164) },
      { -INT32_C( 344461473), -INT32_C(  14243389), -INT32_C( 152187057), -INT32_C(1778556954) } },
    { { -INT32_C(1257949964),  INT32_C( 445852116),  INT32_C(1935655152),  INT32_C(1862578206) },
      {  INT32_C(2019104181),  INT32_C( 761355038), -INT32_C( 887074841),  INT32_C(1288690776) },
      { -INT32_C(  44222987),  INT32_C(1072921566), -INT32_C(  75509769),  INT32_C(1875901534) } },
    { { -INT32_C( 452865008), -INT32_C( 285240067),  INT32_C(1935760980), -INT32_C( 991795953) },
      { -INT32_C(1724040325),  INT32_C(2110234262),  INT32_C(1162405869), -INT32_C( 728688445) },
      { -INT32_C(  46268549), -INT32_C(     24833),  INT32_C(2003435517), -INT32_C( 722240049) } },
    { { -INT32_C( 356936980),  INT32_C(2077800486),  INT32_C( 653146391),  INT32_C( 434819230) },
      { -INT32_C(1582094581), -INT32_C(1289848122),  INT32_C( 620324449),  INT32_C(1811450494) },
      { -INT32_C( 340019217), -INT32_C(  69272858),  INT32_C( 654278519),  INT32_C(2080037630) } },
    { {  INT32_C(1129689373), -INT32_C(2118242966),  INT32_C(  78097510), -INT32_C(2028039812) },
      {  INT32_C(2133381561), -INT32_C(1405991349),  INT32_C( 735062957), -INT32_C( 745092682) },
      {  INT32_C(2138960317), -INT32_C(1380028565),  INT32_C( 804761583), -INT32_C( 677455362) } },
    { { -INT32_C( 468259974),  INT32_C(2120602904), -INT32_C(  24966015),  INT32_C(1468375454) },
      { -INT32_C(1110004110), -INT32_C(1586951948), -INT32_C( 355649228),  INT32_C(2109563650) },
      { -INT32_C(  36245638), -INT32_C(   9576964), -INT32_C(  19972683),  INT32_C(2143151006) } },
    { {  INT32_C(1734464335),  INT32_C( 719767464),  INT32_C(1898473939),  INT32_C(2093526282) },
      {  INT32_C(1345953371), -INT32_C( 604921177), -INT32_C( 557465893),  INT32_C(1901822498) },
      {  INT32_C(2004475743), -INT32_C(  67639377), -INT32_C(   1179685),  INT32_C(2111549226) } },
    { { -INT32_C(  19350443),  INT32_C(1462288003),  INT32_C( 835211303),  INT32_C(1504547325) },
      { -INT32_C( 693508561),  INT32_C(1689361032),  INT32_C(2067953241),  INT32_C(1324129784) },
      { -INT32_C(  17170817),  INT32_C(2008661643),  INT32_C(2076866175),  INT32_C(1609407997) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i
      a = simde_x_mm_loadu_epi32(test_vec[i].a),
      b = simde_x_mm_loadu_epi32(test_vec[i].b),
      r = simde_mm_castps_si128(simde_mm_or_ps(simde_mm_castsi128_ps(a), simde_mm_castsi128_ps(b)));
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_mm_negate_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   609.12), SIMDE_FLOAT32_C(  -335.30), SIMDE_FLOAT32_C(  -903.57), SIMDE_FLOAT32_C(   535.52) },
      { SIMDE_FLOAT32_C(  -609.12), SIMDE_FLOAT32_C(   335.30), SIMDE_FLOAT32_C(   903.57), SIMDE_FLOAT32_C(  -535.52) } },
    { { SIMDE_FLOAT32_C(  -719.54), SIMDE_FLOAT32_C(   357.37), SIMDE_FLOAT32_C(   467.60), SIMDE_FLOAT32_C(   606.73) },
      { SIMDE_FLOAT32_C(   719.54), SIMDE_FLOAT32_C(  -357.37), SIMDE_FLOAT32_C(  -467.60), SIMDE_FLOAT32_C(  -606.73) } },
    { { SIMDE_FLOAT32_C(   150.40), SIMDE_FLOAT32_C(   368.42), SIMDE_FLOAT32_C(  -425.94), SIMDE_FLOAT32_C(  -208.19) },
      { SIMDE_FLOAT32_C(  -150.40), SIMDE_FLOAT32_C(  -368.42), SIMDE_FLOAT32_C(   425.94), SIMDE_FLOAT32_C(   208.19) } },
    { { SIMDE_FLOAT32_C(  -450.08), SIMDE_FLOAT32_C(   276.04), SIMDE_FLOAT32_C(    89.04), SIMDE_FLOAT32_C(   692.08) },
      { SIMDE_FLOAT32_C(   450.08), SIMDE_FLOAT32_C(  -276.04), SIMDE_FLOAT32_C(   -89.04), SIMDE_FLOAT32_C(  -692.08) } },
    { { SIMDE_FLOAT32_C(  -956.32), SIMDE_FLOAT32_C(   -75.40), SIMDE_FLOAT32_C(   701.34), SIMDE_FLOAT32_C(   998.74) },
      { SIMDE_FLOAT32_C(   956.32), SIMDE_FLOAT32_C(    75.40), SIMDE_FLOAT32_C(  -701.34), SIMDE_FLOAT32_C(  -998.74) } },
    { { SIMDE_FLOAT32_C(   827.21), SIMDE_FLOAT32_C(   940.48), SIMDE_FLOAT32_C(  -609.72), SIMDE_FLOAT32_C(  -903.80) },
      { SIMDE_FLOAT32_C(  -827.21), SIMDE_FLOAT32_C(  -940.48), SIMDE_FLOAT32_C(   609.72), SIMDE_FLOAT32_C(   903.80) } },
    { { SIMDE_FLOAT32_C(   575.73), SIMDE_FLOAT32_C(  -655.11), SIMDE_FLOAT32_C(  -276.39), SIMDE_FLOAT32_C(   475.22) },
      { SIMDE_FLOAT32_C(  -575.73), SIMDE_FLOAT32_C(   655.11), SIMDE_FLOAT32_C(   276.39), SIMDE_FLOAT32_C(  -475.22) } },
    { { SIMDE_FLOAT32_C(   571.07), SIMDE_FLOAT32_C(   422.77), SIMDE_FLOAT32_C(  -914.98), SIMDE_FLOAT32_C(   180.19) },
      { SIMDE_FLOAT32_C(  -571.07), SIMDE_FLOAT32_C(  -422.77), SIMDE_FLOAT32_C(   914.98), SIMDE_FLOAT32_C(  -180.19) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_x_mm_negate_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_rcp_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-8.23f, -5.18f,  3.66f, -3.55f),
      simde_mm_set_ps(-0.12f, -0.19f,  0.27f, -0.28f) },
    { simde_mm_set_ps( 5.27f,  1.94f, -1.37f,  3.59f),
      simde_mm_set_ps( 0.19f,  0.52f, -0.73f,  0.28f) },
    { simde_mm_set_ps( 1.70f, -6.14f,  4.86f,  1.14f),
      simde_mm_set_ps( 0.59f, -0.16f,  0.21f,  0.88f) },
    { simde_mm_set_ps(-6.46f,  0.31f,  0.95f,  1.02f),
      simde_mm_set_ps(-0.15f,  3.25f,  1.05f,  0.98f) },
    { simde_mm_set_ps( 0.27f,  3.55f, -8.33f, -7.65f),
      simde_mm_set_ps( 3.70f,  0.28f, -0.12f, -0.13f) },
    { simde_mm_set_ps( 3.04f, -3.61f,  1.60f, -3.92f),
      simde_mm_set_ps( 0.33f, -0.28f,  0.62f, -0.25f) },
    { simde_mm_set_ps( 4.81f,  3.50f,  6.45f,  9.52f),
      simde_mm_set_ps( 0.21f,  0.29f,  0.15f,  0.11f) },
    { simde_mm_set_ps( 6.39f,  6.57f, -0.50f,  6.01f),
      simde_mm_set_ps( 0.16f,  0.15f, -2.00f,  0.17f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rcp_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_rcp_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-0.17f, -5.82f,  9.03f,  0.51f),
      simde_mm_set_ps(-0.17f, -5.82f,  9.03f,  1.97f) },
    { simde_mm_set_ps( 3.71f,  8.82f,  3.74f, -1.45f),
      simde_mm_set_ps( 3.71f,  8.82f,  3.74f, -0.69f) },
    { simde_mm_set_ps( 6.34f, -2.54f, -3.13f, -5.87f),
      simde_mm_set_ps( 6.34f, -2.54f, -3.13f, -0.17f) },
    { simde_mm_set_ps(-3.12f,  8.32f,  6.67f,  6.69f),
      simde_mm_set_ps(-3.12f,  8.32f,  6.67f,  0.15f) },
    { simde_mm_set_ps( 8.74f,  8.53f,  5.33f,  6.71f),
      simde_mm_set_ps( 8.74f,  8.53f,  5.33f,  0.15f) },
    { simde_mm_set_ps( 8.56f, -4.33f,  4.16f, -1.33f),
      simde_mm_set_ps( 8.56f, -4.33f,  4.16f, -0.75f) },
    { simde_mm_set_ps( 0.83f, -2.25f, -0.87f,  8.44f),
      simde_mm_set_ps( 0.83f, -2.25f, -0.87f,  0.12f) },
    { simde_mm_set_ps( 0.99f,  5.65f, -2.23f,  1.17f),
      simde_mm_set_ps( 0.99f,  5.65f, -2.23f,  0.85f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rcp_ss(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_rsqrt_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 19.76f,  43.05f,  24.93f,  44.79f),
      simde_mm_set_ps(  0.22f,   0.15f,   0.20f,   0.15f) },
    { simde_mm_set_ps( 53.16f,  37.63f,  14.64f,  91.38f),
      simde_mm_set_ps(  0.14f,   0.16f,   0.26f,   0.10f) },
    { simde_mm_set_ps( 51.45f,  20.86f,  31.69f,  22.93f),
      simde_mm_set_ps(  0.14f,   0.22f,   0.18f,   0.21f) },
    { simde_mm_set_ps( 70.34f,  27.96f,  47.70f,  68.63f),
      simde_mm_set_ps(  0.12f,   0.19f,   0.14f,   0.12f) },
    { simde_mm_set_ps( 15.37f,  83.67f,  71.19f,  29.53f),
      simde_mm_set_ps(  0.26f,   0.11f,   0.12f,   0.18f) },
    { simde_mm_set_ps( 54.38f,   5.48f,  29.73f,  69.45f),
      simde_mm_set_ps(  0.14f,   0.43f,   0.18f,   0.12f) },
    { simde_mm_set_ps( 84.04f,  25.31f,  28.88f,  94.95f),
      simde_mm_set_ps(  0.11f,   0.20f,   0.19f,   0.10f) },
    { simde_mm_set_ps( 62.50f,   1.25f,  73.97f,  57.92f),
      simde_mm_set_ps(  0.13f,   0.90f,   0.12f,   0.13f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rsqrt_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_rsqrt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 19.76f,  43.05f,  24.93f,  44.79f),
      simde_mm_set_ps( 19.76f,  43.05f,  24.93f,   0.15f) },
    { simde_mm_set_ps( 53.16f,  37.63f,  14.64f,  91.38f),
      simde_mm_set_ps( 53.16f,  37.63f,  14.64f,   0.10f) },
    { simde_mm_set_ps( 51.45f,  20.86f,  31.69f,  22.93f),
      simde_mm_set_ps( 51.45f,  20.86f,  31.69f,   0.21f) },
    { simde_mm_set_ps( 70.34f,  27.96f,  47.70f,  68.63f),
      simde_mm_set_ps( 70.34f,  27.96f,  47.70f,   0.12f) },
    { simde_mm_set_ps( 15.37f,  83.67f,  71.19f,  29.53f),
      simde_mm_set_ps( 15.37f,  83.67f,  71.19f,   0.18f) },
    { simde_mm_set_ps( 54.38f,   5.48f,  29.73f,  69.45f),
      simde_mm_set_ps( 54.38f,   5.48f,  29.73f,   0.12f) },
    { simde_mm_set_ps( 84.04f,  25.31f,  28.88f,  94.95f),
      simde_mm_set_ps( 84.04f,  25.31f,  28.88f,   0.10f) },
    { simde_mm_set_ps( 62.50f,   1.25f,  73.97f,  57.92f),
      simde_mm_set_ps( 62.50f,   1.25f,  73.97f,   0.13f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rsqrt_ss(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_sad_pu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(158,  38, 204, 230, 242, 108, 135, 100),
      simde_x_mm_set_pu8(130, 168, 102, 233, 237, 176,  22, 158),
      simde_x_mm_set_pu16(0, 0, 0, 507) },
    { simde_x_mm_set_pu8( 15, 252, 176, 193, 115,  44,   0,  83),
      simde_x_mm_set_pu8( 99, 169,  76, 203, 218, 181, 138, 226),
      simde_x_mm_set_pu16(0, 0, 0, 798) },
    { simde_x_mm_set_pu8(230,  50, 152, 234, 252,  79, 170, 145),
      simde_x_mm_set_pu8(225, 219, 116, 170, 250, 129, 102, 178),
      simde_x_mm_set_pu16(0, 0, 0, 427) },
    { simde_x_mm_set_pu8( 77, 112,  20, 247, 206, 117, 128, 107),
      simde_x_mm_set_pu8(189, 223, 203, 181,  71, 239,  64, 186),
      simde_x_mm_set_pu16(0, 0, 0, 872) },
    { simde_x_mm_set_pu8(128, 104,  93, 138, 250, 105, 219, 255),
      simde_x_mm_set_pu8(113, 248, 217,  59,  72,   4, 165,  83),
      simde_x_mm_set_pu16(0, 0, 0, 867) },
    { simde_x_mm_set_pu8(143,  12,  71,  81, 251, 175,  44, 206),
      simde_x_mm_set_pu8( 80, 100, 129,  82,  59,  63,  26,  22),
      simde_x_mm_set_pu16(0, 0, 0, 716) },
    { simde_x_mm_set_pu8(  7, 202, 222,  71, 138,  18, 223,  92),
      simde_x_mm_set_pu8(208, 174,  15, 221,  13,  93, 209, 116),
      simde_x_mm_set_pu16(0, 0, 0, 824) },
    { simde_x_mm_set_pu8( 92, 133, 132,   0,  24, 132, 201, 186),
      simde_x_mm_set_pu8(194,  29, 160,  58,  50,  10,  65, 234),
      simde_x_mm_set_pu16(0, 0, 0, 624) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sad_pu8(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_psadbw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(158,  38, 204, 230, 242, 108, 135, 100),
      simde_x_mm_set_pu8(130, 168, 102, 233, 237, 176,  22, 158),
      simde_x_mm_set_pu16(0, 0, 0, 507) },
    { simde_x_mm_set_pu8( 15, 252, 176, 193, 115,  44,   0,  83),
      simde_x_mm_set_pu8( 99, 169,  76, 203, 218, 181, 138, 226),
      simde_x_mm_set_pu16(0, 0, 0, 798) },
    { simde_x_mm_set_pu8(230,  50, 152, 234, 252,  79, 170, 145),
      simde_x_mm_set_pu8(225, 219, 116, 170, 250, 129, 102, 178),
      simde_x_mm_set_pu16(0, 0, 0, 427) },
    { simde_x_mm_set_pu8( 77, 112,  20, 247, 206, 117, 128, 107),
      simde_x_mm_set_pu8(189, 223, 203, 181,  71, 239,  64, 186),
      simde_x_mm_set_pu16(0, 0, 0, 872) },
    { simde_x_mm_set_pu8(128, 104,  93, 138, 250, 105, 219, 255),
      simde_x_mm_set_pu8(113, 248, 217,  59,  72,   4, 165,  83),
      simde_x_mm_set_pu16(0, 0, 0, 867) },
    { simde_x_mm_set_pu8(143,  12,  71,  81, 251, 175,  44, 206),
      simde_x_mm_set_pu8( 80, 100, 129,  82,  59,  63,  26,  22),
      simde_x_mm_set_pu16(0, 0, 0, 716) },
    { simde_x_mm_set_pu8(  7, 202, 222,  71, 138,  18, 223,  92),
      simde_x_mm_set_pu8(208, 174,  15, 221,  13,  93, 209, 116),
      simde_x_mm_set_pu16(0, 0, 0, 824) },
    { simde_x_mm_set_pu8( 92, 133, 132,   0,  24, 132, 201, 186),
      simde_x_mm_set_pu8(194,  29, 160,  58,  50,  10,  65, 234),
      simde_x_mm_set_pu16(0, 0, 0, 624) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_m_psadbw(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_u16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_shuffle_pi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16( 20374,  -8020,   9831, -21724),
      simde_mm_set_pi16(-21724, -21724,   9831,   9831) },
    { simde_mm_set_pi16( 26825,   6867,  -1457,  28819),
      simde_mm_set_pi16( 28819,  28819,  -1457,  -1457) },
    { simde_mm_set_pi16( -4347, -12641,  -8333, -18450),
      simde_mm_set_pi16(-18450, -18450,  -8333,  -8333) },
    { simde_mm_set_pi16( 22439,  23179, -32421,  -3266),
      simde_mm_set_pi16( -3266,  -3266, -32421, -32421) },
    { simde_mm_set_pi16(  9337,  -3310,  22225, -14472),
      simde_mm_set_pi16(-14472, -14472,  22225,  22225) },
    { simde_mm_set_pi16(-17114, -15656,  26827,  -1486),
      simde_mm_set_pi16( -1486,  -1486,  26827,  26827) },
    { simde_mm_set_pi16(  8123,   8758,  31545,  -8216),
      simde_mm_set_pi16( -8216,  -8216,  31545,  31545) },
    { simde_mm_set_pi16(-32324,  31163,  -3386,  23646),
      simde_mm_set_pi16( 23646,  23646,  -3386,  -3386) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_shuffle_pi16(test_vec[i].a, 5);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_m_pshufw(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16( 20374,  -8020,   9831, -21724),
      simde_mm_set_pi16(-21724, -21724,   9831,   9831) },
    { simde_mm_set_pi16( 26825,   6867,  -1457,  28819),
      simde_mm_set_pi16( 28819,  28819,  -1457,  -1457) },
    { simde_mm_set_pi16( -4347, -12641,  -8333, -18450),
      simde_mm_set_pi16(-18450, -18450,  -8333,  -8333) },
    { simde_mm_set_pi16( 22439,  23179, -32421,  -3266),
      simde_mm_set_pi16( -3266,  -3266, -32421, -32421) },
    { simde_mm_set_pi16(  9337,  -3310,  22225, -14472),
      simde_mm_set_pi16(-14472, -14472,  22225,  22225) },
    { simde_mm_set_pi16(-17114, -15656,  26827,  -1486),
      simde_mm_set_pi16( -1486,  -1486,  26827,  26827) },
    { simde_mm_set_pi16(  8123,   8758,  31545,  -8216),
      simde_mm_set_pi16( -8216,  -8216,  31545,  31545) },
    { simde_mm_set_pi16(-32324,  31163,  -3386,  23646),
      simde_mm_set_pi16( 23646,  23646,  -3386,  -3386) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_m_pshufw(test_vec[i].a, 5);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_shuffle_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 387.45f, -469.79f,  719.43f,  371.94f),
      simde_mm_set_ps( 641.56f,  341.35f,  292.84f,  441.22f),
      simde_mm_set_ps( 441.22f,  441.22f, -469.79f,  387.45f) },
    { simde_mm_set_ps( 648.82f,  641.81f, -789.10f,  982.80f),
      simde_mm_set_ps( 472.27f, -304.33f,  524.09f, -589.31f),
      simde_mm_set_ps(-589.31f, -589.31f,  641.81f,  648.82f) },
    { simde_mm_set_ps(-163.67f, -311.30f, -600.60f,  597.71f),
      simde_mm_set_ps(-247.76f,  246.42f, -742.25f,  -20.93f),
      simde_mm_set_ps( -20.93f,  -20.93f, -311.30f, -163.67f) },
    { simde_mm_set_ps( 968.74f,  810.41f, -699.53f,  224.20f),
      simde_mm_set_ps(-966.41f,  917.94f, -300.26f,   64.06f),
      simde_mm_set_ps(  64.06f,   64.06f,  810.41f,  968.74f) },
    { simde_mm_set_ps(  99.15f,  957.94f,  380.12f, -611.50f),
      simde_mm_set_ps( -77.49f, -255.84f,  787.35f, -671.91f),
      simde_mm_set_ps(-671.91f, -671.91f,  957.94f,   99.15f) },
    { simde_mm_set_ps(-280.55f, -182.50f,  340.17f,  473.64f),
      simde_mm_set_ps(  -3.29f, -413.78f, -406.24f,  521.82f),
      simde_mm_set_ps( 521.82f,  521.82f, -182.50f, -280.55f) },
    { simde_mm_set_ps(-677.92f,  481.01f,  494.26f,  565.24f),
      simde_mm_set_ps( 205.66f,  769.40f, -900.58f, -847.82f),
      simde_mm_set_ps(-847.82f, -847.82f,  481.01f, -677.92f) },
    { simde_mm_set_ps( 703.71f,  397.64f,  773.55f, -739.53f),
      simde_mm_set_ps(  99.18f, -932.61f, -902.04f,  169.61f),
      simde_mm_set_ps( 169.61f,  169.61f,  397.64f,  703.71f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_shuffle_ps(test_vec[i].a, test_vec[i].b, 11);
    simde_test_x86_assert_equal_f32x4(test_vec[i].r, r, 1);
  }

  return 0;
}

static int
test_simde_mm_sqrt_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   942.33), SIMDE_FLOAT32_C(   666.40), SIMDE_FLOAT32_C(   694.68), SIMDE_FLOAT32_C(   693.95) },
      { SIMDE_FLOAT32_C(    30.70), SIMDE_FLOAT32_C(    25.81), SIMDE_FLOAT32_C(    26.36), SIMDE_FLOAT32_C(    26.34) } },
    { { SIMDE_FLOAT32_C(   724.41), SIMDE_FLOAT32_C(   941.55), SIMDE_FLOAT32_C(   455.77), SIMDE_FLOAT32_C(   201.95) },
      { SIMDE_FLOAT32_C(    26.91), SIMDE_FLOAT32_C(    30.68), SIMDE_FLOAT32_C(    21.35), SIMDE_FLOAT32_C(    14.21) } },
    { { SIMDE_FLOAT32_C(   512.68), SIMDE_FLOAT32_C(   412.12), SIMDE_FLOAT32_C(   807.00), SIMDE_FLOAT32_C(   845.18) },
      { SIMDE_FLOAT32_C(    22.64), SIMDE_FLOAT32_C(    20.30), SIMDE_FLOAT32_C(    28.41), SIMDE_FLOAT32_C(    29.07) } },
    { { SIMDE_FLOAT32_C(   136.62), SIMDE_FLOAT32_C(    19.19), SIMDE_FLOAT32_C(   410.53), SIMDE_FLOAT32_C(   868.07) },
      { SIMDE_FLOAT32_C(    11.69), SIMDE_FLOAT32_C(     4.38), SIMDE_FLOAT32_C(    20.26), SIMDE_FLOAT32_C(    29.46) } },
    { { SIMDE_FLOAT32_C(   174.19), SIMDE_FLOAT32_C(   221.68), SIMDE_FLOAT32_C(   554.52), SIMDE_FLOAT32_C(   172.63) },
      { SIMDE_FLOAT32_C(    13.20), SIMDE_FLOAT32_C(    14.89), SIMDE_FLOAT32_C(    23.55), SIMDE_FLOAT32_C(    13.14) } },
    { { SIMDE_FLOAT32_C(   352.23), SIMDE_FLOAT32_C(   782.29), SIMDE_FLOAT32_C(   336.58), SIMDE_FLOAT32_C(   708.85) },
      { SIMDE_FLOAT32_C(    18.77), SIMDE_FLOAT32_C(    27.97), SIMDE_FLOAT32_C(    18.35), SIMDE_FLOAT32_C(    26.62) } },
    { { SIMDE_FLOAT32_C(   102.08), SIMDE_FLOAT32_C(   957.70), SIMDE_FLOAT32_C(   725.58), SIMDE_FLOAT32_C(   821.06) },
      { SIMDE_FLOAT32_C(    10.10), SIMDE_FLOAT32_C(    30.95), SIMDE_FLOAT32_C(    26.94), SIMDE_FLOAT32_C(    28.65) } },
    { { SIMDE_FLOAT32_C(   939.60), SIMDE_FLOAT32_C(   907.66), SIMDE_FLOAT32_C(   921.23), SIMDE_FLOAT32_C(   881.93) },
      { SIMDE_FLOAT32_C(    30.65), SIMDE_FLOAT32_C(    30.13), SIMDE_FLOAT32_C(    30.35), SIMDE_FLOAT32_C(    29.70) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_sqrt_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_sqrt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 619.69f,  412.13f,  497.92f,  538.00f),
      simde_mm_set_ps( 619.69f,  412.13f,  497.92f,   23.19f) },
    { simde_mm_set_ps( 620.13f,  731.84f,  667.03f,  801.31f),
      simde_mm_set_ps( 620.13f,  731.84f,  667.03f,   28.31f) },
    { simde_mm_set_ps( 720.02f,  314.91f,  596.04f,  727.65f),
      simde_mm_set_ps( 720.02f,  314.91f,  596.04f,   26.97f) },
    { simde_mm_set_ps( 888.04f,  213.48f,  907.68f,  515.93f),
      simde_mm_set_ps( 888.04f,  213.48f,  907.68f,   22.71f) },
    { simde_mm_set_ps( 196.63f,  888.92f,  163.58f,  421.90f),
      simde_mm_set_ps( 196.63f,  888.92f,  163.58f,   20.54f) },
    { simde_mm_set_ps( 966.24f,  260.28f,  707.39f,  467.81f),
      simde_mm_set_ps( 966.24f,  260.28f,  707.39f,   21.63f) },
    { simde_mm_set_ps( 762.80f,  805.99f,  106.70f,  460.44f),
      simde_mm_set_ps( 762.80f,  805.99f,  106.70f,   21.46f) },
    { simde_mm_set_ps( 398.96f,  926.80f,  642.37f,  392.46f),
      simde_mm_set_ps( 398.96f,  926.80f,  642.37f,   19.81f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sqrt_ss(test_vec[i].a);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_store_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 797.84f,  342.63f,  173.26f,  427.65f),
      {  427.65f,  173.26f,  342.63f,  797.84f } },
    { simde_mm_set_ps( 911.58f,  127.96f,   79.17f,    4.20f),
      {    4.20f,   79.17f,  127.96f,  911.58f } },
    { simde_mm_set_ps( 206.93f,  418.54f,  921.68f,  840.36f),
      {  840.36f,  921.68f,  418.54f,  206.93f } },
    { simde_mm_set_ps( 692.59f,   90.67f,  787.67f,  591.30f),
      {  591.30f,  787.67f,   90.67f,  692.59f } },
    { simde_mm_set_ps(  57.64f,   25.24f,  486.10f,  797.60f),
      {  797.60f,  486.10f,   25.24f,   57.64f } },
    { simde_mm_set_ps( 987.53f,  693.84f,  633.62f,  186.39f),
      {  186.39f,  633.62f,  693.84f,  987.53f } },
    { simde_mm_set_ps( 772.05f,  227.52f,  175.91f,  879.34f),
      {  879.34f,  175.91f,  227.52f,  772.05f } },
    { simde_mm_set_ps( 640.49f,  596.15f,  891.32f,   37.15f),
      {   37.15f,  891.32f,  596.15f,  640.49f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
    simde_mm_store_ps(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_store_ps1(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 854.57f,  299.85f,   53.35f,  467.01f),
      {  467.01f,  467.01f,  467.01f,  467.01f } },
    { simde_mm_set_ps( 477.02f,  854.94f,  677.55f,  339.79f),
      {  339.79f,  339.79f,  339.79f,  339.79f } },
    { simde_mm_set_ps( 736.99f,  148.01f,  536.77f,  621.38f),
      {  621.38f,  621.38f,  621.38f,  621.38f } },
    { simde_mm_set_ps( 947.26f,  901.13f,  502.63f,  117.54f),
      {  117.54f,  117.54f,  117.54f,  117.54f } },
    { simde_mm_set_ps( 193.39f,  545.92f,  514.75f,  687.45f),
      {  687.45f,  687.45f,  687.45f,  687.45f } },
    { simde_mm_set_ps( 844.08f,  252.82f,  783.61f,  372.00f),
      {  372.00f,  372.00f,  372.00f,  372.00f } },
    { simde_mm_set_ps( 988.23f,  778.23f,  199.92f,  424.51f),
      {  424.51f,  424.51f,  424.51f,  424.51f } },
    { simde_mm_set_ps( 515.70f,  944.74f,  777.26f,  470.44f),
      {  470.44f,  470.44f,  470.44f,  470.44f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
    simde_mm_store_ps1(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_store_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 854.57f,  299.85f,   53.35f,  467.01f),
      {  467.01f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 477.02f,  854.94f,  677.55f,  339.79f),
      {  339.79f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 736.99f,  148.01f,  536.77f,  621.38f),
      {  621.38f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 947.26f,  901.13f,  502.63f,  117.54f),
      {  117.54f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 193.39f,  545.92f,  514.75f,  687.45f),
      {  687.45f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 844.08f,  252.82f,  783.61f,  372.00f),
      {  372.00f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 988.23f,  778.23f,  199.92f,  424.51f),
      {  424.51f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 515.70f,  944.74f,  777.26f,  470.44f),
      {  470.44f,    0.00f,    0.00f,    0.00f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4] = { SIMDE_FLOAT32_C(0.0), };
    simde_mm_store_ss(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_store1_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 274.23f,   89.27f,  784.72f,  646.53f),
      {  646.53f,  646.53f,  646.53f,  646.53f } },
    { simde_mm_set_ps( 322.23f,  913.84f,  883.41f,  484.76f),
      {  484.76f,  484.76f,  484.76f,  484.76f } },
    { simde_mm_set_ps( 272.81f,  739.51f,  776.03f,   57.85f),
      {   57.85f,   57.85f,   57.85f,   57.85f } },
    { simde_mm_set_ps( 414.64f,  733.36f,  680.70f,  973.86f),
      {  973.86f,  973.86f,  973.86f,  973.86f } },
    { simde_mm_set_ps( 541.43f,  860.27f,  162.49f,  726.46f),
      {  726.46f,  726.46f,  726.46f,  726.46f } },
    { simde_mm_set_ps( 735.30f,  924.35f,   18.46f,  634.38f),
      {  634.38f,  634.38f,  634.38f,  634.38f } },
    { simde_mm_set_ps( 676.23f,   61.60f,   24.97f,  803.79f),
      {  803.79f,  803.79f,  803.79f,  803.79f } },
    { simde_mm_set_ps( 373.81f,  509.18f,  233.96f,  910.43f),
      {  910.43f,  910.43f,  910.43f,  910.43f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4] = { 0, };
    simde_mm_store1_ps(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_storeh_pi(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 575.54f,  220.03f,  206.01f,  870.81f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 575.54), SIMDE_FLOAT32_C( 220.03)) },
    { simde_mm_set_ps( 289.58f,  629.51f,  767.25f,  704.01f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 289.58), SIMDE_FLOAT32_C( 629.51)) },
    { simde_mm_set_ps( 627.14f,  949.08f,  581.33f,  434.65f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 627.14), SIMDE_FLOAT32_C( 949.08)) },
    { simde_mm_set_ps( 369.75f,  459.24f,  702.99f,   90.66f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 369.75), SIMDE_FLOAT32_C( 459.24)) },
    { simde_mm_set_ps(  57.99f,  910.00f,  605.74f,   76.21f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C(  57.99), SIMDE_FLOAT32_C( 910.00)) },
    { simde_mm_set_ps( 918.98f,  456.74f,  224.68f,  627.20f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 918.98), SIMDE_FLOAT32_C( 456.74)) },
    { simde_mm_set_ps( 963.09f,  356.12f,   33.23f,  995.23f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 963.09), SIMDE_FLOAT32_C( 356.12)) },
    { simde_mm_set_ps( 967.89f,  231.25f,  230.84f,  538.31f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 967.89), SIMDE_FLOAT32_C( 231.25)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r;
    simde_mm_storeh_pi(&r, test_vec[i].a);
    simde_test_x86_assert_equal_f32x2(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_storel_pi(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 258.22f,  461.17f,  500.19f,  792.00f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 500.19), SIMDE_FLOAT32_C( 792.00)) },
    { simde_mm_set_ps( 839.05f,  239.15f,  886.65f,  576.97f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 886.65), SIMDE_FLOAT32_C( 576.97)) },
    { simde_mm_set_ps( 905.98f,  580.29f,   37.85f,  782.47f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C(  37.85), SIMDE_FLOAT32_C( 782.47)) },
    { simde_mm_set_ps( 367.06f,  905.12f,  385.52f,  288.25f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 385.52), SIMDE_FLOAT32_C( 288.25)) },
    { simde_mm_set_ps( 345.47f,   91.39f,  757.41f,  177.58f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 757.41), SIMDE_FLOAT32_C( 177.58)) },
    { simde_mm_set_ps(  41.60f,  601.66f,  873.51f,  499.62f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 873.51), SIMDE_FLOAT32_C( 499.62)) },
    { simde_mm_set_ps( 185.64f,  301.30f,   85.92f,  684.99f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C(  85.92), SIMDE_FLOAT32_C( 684.99)) },
    { simde_mm_set_ps( 556.83f,  958.68f,  557.15f,  788.14f),
      simde_x_mm_set_f32x2(SIMDE_FLOAT32_C( 557.15), SIMDE_FLOAT32_C( 788.14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r;
    simde_mm_storel_pi(&r, test_vec[i].a);
    simde_test_x86_assert_equal_f32x2(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_storer_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 709.97f,  746.23f,  453.60f,  303.28f),
      {  709.97f,  746.23f,  453.60f,  303.28f } },
    { simde_mm_set_ps( 764.16f,  229.13f,  431.64f,  384.08f),
      {  764.16f,  229.13f,  431.64f,  384.08f } },
    { simde_mm_set_ps( 237.88f,  156.25f,  582.89f,   91.67f),
      {  237.88f,  156.25f,  582.89f,   91.67f } },
    { simde_mm_set_ps( 244.82f,   86.89f,  868.91f,  106.59f),
      {  244.82f,   86.89f,  868.91f,  106.59f } },
    { simde_mm_set_ps( 570.53f,  397.46f,  850.83f,  961.86f),
      {  570.53f,  397.46f,  850.83f,  961.86f } },
    { simde_mm_set_ps( 946.89f,  801.12f,  881.81f,  752.94f),
      {  946.89f,  801.12f,  881.81f,  752.94f } },
    { simde_mm_set_ps( 779.85f,   31.75f,  218.17f,  299.71f),
      {  779.85f,   31.75f,  218.17f,  299.71f } },
    { simde_mm_set_ps( 409.61f,  712.65f,  619.44f,  952.97f),
      {  409.61f,  712.65f,  619.44f,  952.97f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4] = { 0, };
    simde_mm_storer_ps(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_storeu_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 304.73f,  535.11f,   34.80f,  759.84f),
      {  759.84f,   34.80f,  535.11f,  304.73f } },
    { simde_mm_set_ps( 360.59f,  120.47f,  501.36f,  116.79f),
      {  116.79f,  501.36f,  120.47f,  360.59f } },
    { simde_mm_set_ps( 709.31f,  269.06f,  586.46f,  622.65f),
      {  622.65f,  586.46f,  269.06f,  709.31f } },
    { simde_mm_set_ps( 653.72f,  295.37f,   94.24f,  886.62f),
      {  886.62f,   94.24f,  295.37f,  653.72f } },
    { simde_mm_set_ps(   4.93f,  676.49f,  303.89f,  920.73f),
      {  920.73f,  303.89f,  676.49f,    4.93f } },
    { simde_mm_set_ps( 930.44f,  841.16f,  891.12f,  349.34f),
      {  349.34f,  891.12f,  841.16f,  930.44f } },
    { simde_mm_set_ps( 899.13f,  242.56f,  161.77f,   99.90f),
      {   99.90f,  161.77f,  242.56f,  899.13f } },
    { simde_mm_set_ps( 350.94f,  738.74f,  750.24f,  329.42f),
      {  329.42f,  750.24f,  738.74f,  350.94f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4] = { 0, };
    simde_mm_storeu_ps(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_sub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-670.13f, -257.04f,  449.06f,  965.86f),
      simde_mm_set_ps(-637.34f,  741.89f,  -14.02f,  918.72f),
      simde_mm_set_ps( -32.80f, -998.93f,  463.07f,   47.13f) },
    { simde_mm_set_ps(-744.89f,  -52.84f,  460.90f,  134.66f),
      simde_mm_set_ps( 177.89f, -904.94f,  443.55f, -742.83f),
      simde_mm_set_ps(-922.78f,  852.10f,   17.35f,  877.49f) },
    { simde_mm_set_ps( 807.56f,  945.11f,  259.44f,  557.41f),
      simde_mm_set_ps( 404.99f,  399.93f,  -68.79f,  957.61f),
      simde_mm_set_ps( 402.57f,  545.19f,  328.23f, -400.20f) },
    { simde_mm_set_ps(  74.77f,  473.53f, -483.74f,  415.65f),
      simde_mm_set_ps(-608.38f,  553.08f, -146.88f,   64.98f),
      simde_mm_set_ps( 683.15f,  -79.55f, -336.86f,  350.67f) },
    { simde_mm_set_ps( 879.68f, -763.80f,  -53.30f,   95.40f),
      simde_mm_set_ps( 164.85f,  427.62f,  174.59f,  925.02f),
      simde_mm_set_ps( 714.82f, -1191.42f, -227.89f, -829.62f) },
    { simde_mm_set_ps( 571.32f,  207.75f,  439.31f, -973.48f),
      simde_mm_set_ps(-719.88f, -346.38f, -249.12f, -239.62f),
      simde_mm_set_ps(1291.20f,  554.13f,  688.43f, -733.86f) },
    { simde_mm_set_ps( 995.34f, -761.80f, -600.36f,  665.89f),
      simde_mm_set_ps( 578.64f, -853.98f,  329.02f, -360.51f),
      simde_mm_set_ps( 416.70f,   92.18f, -929.38f, 1026.41f) },
    { simde_mm_set_ps(-961.63f,  818.44f, -364.30f, -740.41f),
      simde_mm_set_ps(  86.59f,  540.64f,  243.58f,  458.04f),
      simde_mm_set_ps(-1048.22f,  277.80f, -607.89f, -1198.46f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sub_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_sub_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-670.13f, -257.04f,  449.06f,  965.86f),
      simde_mm_set_ps(-637.34f,  741.89f,  -14.02f,  918.72f),
      simde_mm_set_ps(-670.13f, -257.04f,  449.06f,   47.13f) },
    { simde_mm_set_ps(-744.89f,  -52.84f,  460.90f,  134.66f),
      simde_mm_set_ps( 177.89f, -904.94f,  443.55f, -742.83f),
      simde_mm_set_ps(-744.89f,  -52.84f,  460.90f,  877.49f) },
    { simde_mm_set_ps( 807.56f,  945.11f,  259.44f,  557.41f),
      simde_mm_set_ps( 404.99f,  399.93f,  -68.79f,  957.61f),
      simde_mm_set_ps( 807.56f,  945.11f,  259.44f, -400.20f) },
    { simde_mm_set_ps(  74.77f,  473.53f, -483.74f,  415.65f),
      simde_mm_set_ps(-608.38f,  553.08f, -146.88f,   64.98f),
      simde_mm_set_ps(  74.77f,  473.53f, -483.74f,  350.67f) },
    { simde_mm_set_ps( 879.68f, -763.80f,  -53.30f,   95.40f),
      simde_mm_set_ps( 164.85f,  427.62f,  174.59f,  925.02f),
      simde_mm_set_ps( 879.68f, -763.80f,  -53.30f, -829.62f) },
    { simde_mm_set_ps( 571.32f,  207.75f,  439.31f, -973.48f),
      simde_mm_set_ps(-719.88f, -346.38f, -249.12f, -239.62f),
      simde_mm_set_ps( 571.32f,  207.75f,  439.31f, -733.86f) },
    { simde_mm_set_ps( 995.34f, -761.80f, -600.36f,  665.89f),
      simde_mm_set_ps( 578.64f, -853.98f,  329.02f, -360.51f),
      simde_mm_set_ps( 995.34f, -761.80f, -600.36f, 1026.41f) },
    { simde_mm_set_ps(-961.63f,  818.44f, -364.30f, -740.41f),
      simde_mm_set_ps(  86.59f,  540.64f,  243.58f,  458.04f),
      simde_mm_set_ps(-961.63f,  818.44f, -364.30f, -1198.46f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sub_ss(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_ucomieq_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      1 },
    { simde_mm_set_ps(0.9426f, 0.1679f, 0.2845f, 0.1698f),
      simde_mm_set_ps(0.9426f, 0.6931f, 0.2845f, 0.1698f),
      1 },
    { simde_mm_set_ps(0.0547f, 0.2368f, 0.3365f, 0.9146f),
      simde_mm_set_ps(0.0547f, 0.5935f, 0.3365f, 0.5014f),
      0 },
    { simde_mm_set_ps(0.7179f, 0.8607f, 0.4372f, 0.6140f),
      simde_mm_set_ps(0.7179f, 0.7239f, 0.4372f, 0.6140f),
      1 },
    { simde_mm_set_ps(0.4474f, 0.6848f, 0.4305f, 0.8738f),
      simde_mm_set_ps(0.6059f, 0.8463f, 0.4305f, 0.1517f),
      0 },
    { simde_mm_set_ps(0.4537f, 0.7254f, 0.9987f, 0.9115f),
      simde_mm_set_ps(0.1771f, 0.2982f, 0.9987f, 0.9003f),
      0 },
    { simde_mm_set_ps(0.2162f, 0.6303f, 0.0602f, 0.9986f),
      simde_mm_set_ps(0.2162f, 0.5872f, 0.0602f, 0.2491f),
      0 },
    { simde_mm_set_ps(0.4836f, 0.9929f, 0.8942f, 0.2367f),
      simde_mm_set_ps(0.4836f, 0.9929f, 0.4202f, 0.2367f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomieq_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomige_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomige_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomigt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomigt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomile_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomile_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomilt_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomilt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomineq_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomineq_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpackhi_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-756.38f, -450.47f,  901.78f,  859.60f),
      simde_mm_set_ps( -17.95f, -383.47f,  601.72f,  328.61f),
      simde_mm_set_ps( -17.95f, -756.38f, -383.47f, -450.47f) },
    { simde_mm_set_ps(-696.67f, -318.67f, -746.84f,  486.97f),
      simde_mm_set_ps(  76.54f, -173.13f,  775.95f,  744.80f),
      simde_mm_set_ps(  76.54f, -696.67f, -173.13f, -318.67f) },
    { simde_mm_set_ps(-181.38f,  -64.52f, -525.50f,  383.47f),
      simde_mm_set_ps(-830.80f,  462.90f,  208.76f, -840.43f),
      simde_mm_set_ps(-830.80f, -181.38f,  462.90f,  -64.52f) },
    { simde_mm_set_ps(-437.50f, -751.51f, -255.04f,  713.97f),
      simde_mm_set_ps(-835.16f,  838.19f, -968.67f, -800.39f),
      simde_mm_set_ps(-835.16f, -437.50f,  838.19f, -751.51f) },
    { simde_mm_set_ps( 252.51f,  219.43f,  234.16f,  718.42f),
      simde_mm_set_ps( 737.55f, -360.52f,  129.47f,  866.75f),
      simde_mm_set_ps( 737.55f,  252.51f, -360.52f,  219.43f) },
    { simde_mm_set_ps(-543.89f,  -12.39f,  996.39f, -521.27f),
      simde_mm_set_ps(-330.73f, -334.66f,  798.87f, -360.08f),
      simde_mm_set_ps(-330.73f, -543.89f, -334.66f,  -12.39f) },
    { simde_mm_set_ps( 633.16f,  239.27f,  625.35f,  330.43f),
      simde_mm_set_ps(-890.86f,  495.17f, -524.21f,  275.19f),
      simde_mm_set_ps(-890.86f,  633.16f,  495.17f,  239.27f) },
    { simde_mm_set_ps(-443.30f, -851.22f,  842.49f,  697.77f),
      simde_mm_set_ps(   8.81f, -953.12f,   -1.45f, -983.63f),
      simde_mm_set_ps(   8.81f, -443.30f, -953.12f, -851.22f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_unpackhi_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_unpacklo_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-756.38f, -450.47f,  901.78f,  859.60f),
      simde_mm_set_ps( -17.95f, -383.47f,  601.72f,  328.61f),
      simde_mm_set_ps( 601.72f,  901.78f,  328.61f,  859.60f) },
    { simde_mm_set_ps(-696.67f, -318.67f, -746.84f,  486.97f),
      simde_mm_set_ps(  76.54f, -173.13f,  775.95f,  744.80f),
      simde_mm_set_ps( 775.95f, -746.84f,  744.80f,  486.97f) },
    { simde_mm_set_ps(-181.38f,  -64.52f, -525.50f,  383.47f),
      simde_mm_set_ps(-830.80f,  462.90f,  208.76f, -840.43f),
      simde_mm_set_ps( 208.76f, -525.50f, -840.43f,  383.47f) },
    { simde_mm_set_ps(-437.50f, -751.51f, -255.04f,  713.97f),
      simde_mm_set_ps(-835.16f,  838.19f, -968.67f, -800.39f),
      simde_mm_set_ps(-968.67f, -255.04f, -800.39f,  713.97f) },
    { simde_mm_set_ps( 252.51f,  219.43f,  234.16f,  718.42f),
      simde_mm_set_ps( 737.55f, -360.52f,  129.47f,  866.75f),
      simde_mm_set_ps( 129.47f,  234.16f,  866.75f,  718.42f) },
    { simde_mm_set_ps(-543.89f,  -12.39f,  996.39f, -521.27f),
      simde_mm_set_ps(-330.73f, -334.66f,  798.87f, -360.08f),
      simde_mm_set_ps( 798.87f,  996.39f, -360.08f, -521.27f) },
    { simde_mm_set_ps( 633.16f,  239.27f,  625.35f,  330.43f),
      simde_mm_set_ps(-890.86f,  495.17f, -524.21f,  275.19f),
      simde_mm_set_ps(-524.21f,  625.35f,  275.19f,  330.43f) },
    { simde_mm_set_ps(-443.30f, -851.22f,  842.49f,  697.77f),
      simde_mm_set_ps(   8.81f, -953.12f,   -1.45f, -983.63f),
      simde_mm_set_ps(  -1.45f,  842.49f, -983.63f,  697.77f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_unpacklo_ps(test_vec[i].a, test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_undefined_ps(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128 z = simde_mm_setzero_ps();
  simde__m128 v = simde_mm_undefined_ps();
  v = simde_mm_xor_ps(v, v);

  simde_test_x86_assert_equal_i32x4(simde_mm_castps_si128(z), simde_mm_castps_si128(v));

  return 0;
}

static int
test_simde_mm_xor_ps(SIMDE_MUNIT_TEST_ARGS) {
  struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(1471749541),  INT32_C( 594543369),  INT32_C(1488726073), -INT32_C( 377183697) },
      { -INT32_C(1298589699), -INT32_C( 480283399), -INT32_C( 106049451), -INT32_C(1090298013) },
      {  INT32_C( 450885030), -INT32_C(1070630928), -INT32_C(1592657812),  INT32_C(1451752780) } },
    { {  INT32_C(1265060161), -INT32_C(2039556275),  INT32_C( 803088896), -INT32_C( 904371252) },
      {  INT32_C(1937551738),  INT32_C(2052578341),  INT32_C( 259196076), -INT32_C(1513195677) },
      {  INT32_C( 941357115), -INT32_C(  63370392),  INT32_C( 548220588),  INT32_C(1876300975) } },
    { {  INT32_C( 233846208),  INT32_C( 227761677),  INT32_C(1413247624),  INT32_C(1327387861) },
      {  INT32_C( 717396741),  INT32_C( 598022519), -INT32_C(2127423459),  INT32_C(1344668047) },
      {  INT32_C( 657632965),  INT32_C( 775309178), -INT32_C( 720475499),  INT32_C( 523785562) } },
    { {  INT32_C(1130174006), -INT32_C(  61804172),  INT32_C( 944802915), -INT32_C( 444108832) },
      { -INT32_C(2129639158), -INT32_C(2136689309),  INT32_C(1560401613),  INT32_C( 246228951) },
      { -INT32_C(1035116740),  INT32_C(2096382999),  INT32_C(1699830446), -INT32_C( 349550537) } },
    { { -INT32_C(1320089027),  INT32_C(1588437755),  INT32_C( 261553710),  INT32_C(2012487021) },
      { -INT32_C( 889715609), -INT32_C(2025153351),  INT32_C(1256475762), -INT32_C(1319595661) },
      {  INT32_C(2074676826), -INT32_C( 639156670),  INT32_C(1165144668), -INT32_C( 961770466) } },
    { { -INT32_C(1755141733),  INT32_C(2062880843),  INT32_C(2072611854),  INT32_C( 284327337) },
      {  INT32_C(1004202626), -INT32_C( 121494138), -INT32_C( 465394063), -INT32_C( 745170377) },
      { -INT32_C(1397210343), -INT32_C(2110310963), -INT32_C(1614075265), -INT32_C(1016600674) } },
    { { -INT32_C(1888815036),  INT32_C( 369712904), -INT32_C(1785621781), -INT32_C(1834646768) },
      { -INT32_C( 204636051),  INT32_C( 384536741),  INT32_C(1861889590),  INT32_C( 205623496) },
      {  INT32_C(2091350057),  INT32_C(  14864301), -INT32_C(  76825379), -INT32_C(1629219880) } },
    { { -INT32_C(1868780664), -INT32_C( 156850934),  INT32_C(1217083192),  INT32_C( 668610746) },
      {  INT32_C(1427810224),  INT32_C(1852507447), -INT32_C(  52664781),  INT32_C(2114461174) },
      { -INT32_C( 981070792), -INT32_C(1731354563), -INT32_C(1269346037),  INT32_C(1506946380) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i
      a = simde_x_mm_loadu_epi32(test_vec[i].a),
      b = simde_x_mm_loadu_epi32(test_vec[i].b),
      r = simde_mm_castps_si128(simde_mm_xor_ps(simde_mm_castsi128_ps(a), simde_mm_castsi128_ps(b))),
      e = simde_x_mm_loadu_epi32(test_vec[i].r);
    simde_test_x86_assert_equal_i32x4(r, e);
  }

  return 0;
}

static int
test_simde_mm_stream_pi(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(  6761, -22445, -23476, -30705),
      simde_mm_set_pi16(  6761, -22445, -23476, -30705) },
    { simde_mm_set_pi16( 19012, -30608,  30482, -20411),
      simde_mm_set_pi16( 19012, -30608,  30482, -20411) },
    { simde_mm_set_pi16( 23487, -28638,  -4660,  -3430),
      simde_mm_set_pi16( 23487, -28638,  -4660,  -3430) },
    { simde_mm_set_pi16( -9884,  -9588,  -4377, -27077),
      simde_mm_set_pi16( -9884,  -9588,  -4377, -27077) },
    { simde_mm_set_pi16( 15488, -17321,   2333,   8745),
      simde_mm_set_pi16( 15488, -17321,   2333,   8745) },
    { simde_mm_set_pi16( 30278,   5796, -17311,  13106),
      simde_mm_set_pi16( 30278,   5796, -17311,  13106) },
    { simde_mm_set_pi16(-18652,  26507,  -8174,  31557),
      simde_mm_set_pi16(-18652,  26507,  -8174,  31557) },
    { simde_mm_set_pi16(-16725,  22668,   9074,   1013),
      simde_mm_set_pi16(-16725,  22668,   9074,   1013) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r;
    simde_mm_stream_pi(&r, test_vec[i].a);
    simde_test_x86_assert_equal_i16x4(r, test_vec[i].r);
  }

  simde_mm_empty();

  return 0;
}

static int
test_simde_mm_stream_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps(-386.97f,  492.19f,  318.83f,  345.85f),
      {  345.85f,  318.83f,  492.19f, -386.97f } },
    { simde_mm_set_ps( 908.43f,  787.88f, -776.77f, -773.68f),
      { -773.68f, -776.77f,  787.88f,  908.43f } },
    { simde_mm_set_ps( 241.81f,  684.64f, -474.83f,  614.26f),
      {  614.26f, -474.83f,  684.64f,  241.81f } },
    { simde_mm_set_ps(-327.50f, -550.14f, -266.51f, -677.19f),
      { -677.19f, -266.51f, -550.14f, -327.50f } },
    { simde_mm_set_ps( 706.39f, -425.59f,  678.55f, -877.83f),
      { -877.83f,  678.55f, -425.59f,  706.39f } },
    { simde_mm_set_ps( 902.50f,  144.03f,  -93.04f,  995.74f),
      {  995.74f,  -93.04f,  144.03f,  902.50f } },
    { simde_mm_set_ps( 898.99f, -437.71f, -170.25f,  875.61f),
      {  875.61f, -170.25f, -437.71f,  898.99f } },
    { simde_mm_set_ps( 347.85f, -128.18f,  904.62f,  936.88f),
      {  936.88f,  904.62f, -128.18f,  347.85f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
    simde_mm_stream_ps(r, test_vec[i].a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_prefetch(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    SIMDE_ALIGN_LIKE_16(simde__m128) simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps(-386.97f,  492.19f,  318.83f,  345.85f),
      {  345.85f,  318.83f,  492.19f, -386.97f } },
    { simde_mm_set_ps( 908.43f,  787.88f, -776.77f, -773.68f),
      { -773.68f, -776.77f,  787.88f,  908.43f } },
    { simde_mm_set_ps( 241.81f,  684.64f, -474.83f,  614.26f),
      {  614.26f, -474.83f,  684.64f,  241.81f } },
    { simde_mm_set_ps(-327.50f, -550.14f, -266.51f, -677.19f),
      { -677.19f, -266.51f, -550.14f, -327.50f } },
    { simde_mm_set_ps( 706.39f, -425.59f,  678.55f, -877.83f),
      { -877.83f,  678.55f, -425.59f,  706.39f } },
    { simde_mm_set_ps( 902.50f,  144.03f,  -93.04f,  995.74f),
      {  995.74f,  -93.04f,  144.03f,  902.50f } },
    { simde_mm_set_ps( 898.99f, -437.71f, -170.25f,  875.61f),
      {  875.61f, -170.25f, -437.71f,  898.99f } },
    { simde_mm_set_ps( 347.85f, -128.18f,  904.62f,  936.88f),
      {  936.88f,  904.62f, -128.18f,  347.85f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_mm_prefetch(HEDLEY_REINTERPRET_CAST(const char *, &test_vec[i].a), SIMDE_MM_HINT_T0);
    simde_mm_prefetch(HEDLEY_REINTERPRET_CAST(const char *, &test_vec[i].a), SIMDE_MM_HINT_T1);
    simde_mm_prefetch(HEDLEY_REINTERPRET_CAST(const char *, &test_vec[i].a), SIMDE_MM_HINT_T2);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_ps1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setr_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setzero_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_setone_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_abs_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_andnot_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_not_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_select_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_avg_pu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pavgw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_avg_pu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pavgb)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnge_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnge_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpngt_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpngt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnle_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnle_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnlt_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnlt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpord_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpord_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpunord_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpunord_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comieq_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comige_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comigt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comile_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comilt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comineq_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_copysign_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_xorsign_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvt_pi2ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvt_ps2pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvt_si2ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvt_ss2si)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpi16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpi32_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpi32x2_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpi8_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_pi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_pi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_pi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpu16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpu8_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi32_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi64_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtss_f32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtss_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtss_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtt_ps2pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtt_ss2si)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttss_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_div_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_div_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_extract_pi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pextrw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_insert_pi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pinsrw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_ps1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadh_pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadl_pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadr_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskmove_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_maskmovq)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_pi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pmaxsw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_pu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pmaxub)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_pi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pminsw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_pu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pminub)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_move_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movehl_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movelh_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movemask_pi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pmovmskb)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movemask_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mulhi_pu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pmulhuw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_or_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_negate_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rcp_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rcp_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rsqrt_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rsqrt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sad_pu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_psadbw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shuffle_pi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(m_pshufw)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shuffle_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sqrt_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sqrt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_ps1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store1_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeh_pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storel_pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storer_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomieq_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomige_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomigt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomile_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomilt_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomineq_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_undefined_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_xor_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_pi)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_prefetch)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
