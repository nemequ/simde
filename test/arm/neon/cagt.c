#define SIMDE_TEST_ARM_NEON_INSN cagt

#include "test-neon.h"
#include "../../../simde/arm/neon/cagt.h"

static int
test_simde_vcagts_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 b;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_MATH_NANF,
      SIMDE_FLOAT32_C(     0.52),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   705.02),
                 SIMDE_MATH_NANF,
      UINT32_C(         0) },
    {            SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF,
      UINT32_C(         0) },
    #endif

    { SIMDE_FLOAT32_C(     8.79),
      SIMDE_FLOAT32_C(   792.83),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -399.97),
      SIMDE_FLOAT32_C(  -256.84),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   231.75),
      SIMDE_FLOAT32_C(  -411.54),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   864.59),
      SIMDE_FLOAT32_C(  -881.95),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -814.20),
      SIMDE_FLOAT32_C(   479.81),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   263.32),
      SIMDE_FLOAT32_C(  -797.51),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   321.47),
      SIMDE_FLOAT32_C(   -74.97),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   -57.92),
      SIMDE_FLOAT32_C(   535.57),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcagts_f32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    uint32_t r = simde_vcagts_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagtd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 b;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {              SIMDE_MATH_NAN,
      SIMDE_FLOAT64_C(     0.52),
      UINT64_C(         0) },
    { SIMDE_FLOAT64_C(   705.02),
                  SIMDE_MATH_NAN,
      UINT64_C(         0) },
    {             SIMDE_MATH_NAN,
                  SIMDE_MATH_NAN,
      UINT64_C(         0) },
    #endif

    { SIMDE_FLOAT64_C(  -111.66),
      SIMDE_FLOAT64_C(  -149.68),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -365.17),
      SIMDE_FLOAT64_C(  -219.70),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   -45.32),
      SIMDE_FLOAT64_C(   606.55),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -324.50),
      SIMDE_FLOAT64_C(  -332.43),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   611.77),
      SIMDE_FLOAT64_C(   425.54),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   910.11),
      SIMDE_FLOAT64_C(   648.44),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   572.56),
      SIMDE_FLOAT64_C(  -409.05),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   265.81),
      SIMDE_FLOAT64_C(  -418.65),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcagtd_f64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t b = simde_test_codegen_random_f64(-1000.0, 1000.0);
    uint64_t r = simde_vcagtd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagt_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   311.69), SIMDE_FLOAT32_C(  -932.68) },
      { SIMDE_FLOAT32_C(    98.33), SIMDE_FLOAT32_C(  -552.98) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   959.61), SIMDE_FLOAT32_C(   617.75) },
      { SIMDE_FLOAT32_C(  -197.11), SIMDE_FLOAT32_C(   562.98) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   468.98), SIMDE_FLOAT32_C(  -916.49) },
      { SIMDE_FLOAT32_C(   965.35), SIMDE_FLOAT32_C(   700.25) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -647.13), SIMDE_FLOAT32_C(  -147.35) },
      { SIMDE_FLOAT32_C(  -117.68), SIMDE_FLOAT32_C(  -241.37) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -664.10), SIMDE_FLOAT32_C(  -976.12) },
      { SIMDE_FLOAT32_C(   874.22), SIMDE_FLOAT32_C(   -12.94) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    25.04), SIMDE_FLOAT32_C(  -125.75) },
      { SIMDE_FLOAT32_C(   212.15), SIMDE_FLOAT32_C(   782.89) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   561.17), SIMDE_FLOAT32_C(   217.87) },
      { SIMDE_FLOAT32_C(  -238.74), SIMDE_FLOAT32_C(   679.32) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -965.46), SIMDE_FLOAT32_C(  -738.96) },
      { SIMDE_FLOAT32_C(  -711.74), SIMDE_FLOAT32_C(   346.23) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcagt_f32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcagt_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    85.26) },
      { SIMDE_FLOAT64_C(   122.65) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -500.89) },
      { SIMDE_FLOAT64_C(   936.69) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   594.89) },
      { SIMDE_FLOAT64_C(   788.77) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   543.70) },
      { SIMDE_FLOAT64_C(  -150.09) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -875.02) },
      { SIMDE_FLOAT64_C(   442.69) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   673.76) },
      { SIMDE_FLOAT64_C(   217.24) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   789.39) },
      { SIMDE_FLOAT64_C(   718.78) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -511.44) },
      { SIMDE_FLOAT64_C(   752.01) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcagt_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcagtq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   880.25), SIMDE_FLOAT32_C(   497.37), SIMDE_FLOAT32_C(   188.18), SIMDE_FLOAT32_C(  -214.92) },
      { SIMDE_FLOAT32_C(  -292.63), SIMDE_FLOAT32_C(   165.21), SIMDE_FLOAT32_C(  -507.32), SIMDE_FLOAT32_C(  -554.07) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    21.58), SIMDE_FLOAT32_C(  -187.66), SIMDE_FLOAT32_C(    52.34), SIMDE_FLOAT32_C(   522.72) },
      { SIMDE_FLOAT32_C(   805.10), SIMDE_FLOAT32_C(  -357.26), SIMDE_FLOAT32_C(   451.59), SIMDE_FLOAT32_C(   744.08) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   113.67), SIMDE_FLOAT32_C(   334.71), SIMDE_FLOAT32_C(   489.01), SIMDE_FLOAT32_C(   347.72) },
      { SIMDE_FLOAT32_C(  -991.50), SIMDE_FLOAT32_C(  -625.74), SIMDE_FLOAT32_C(  -356.50), SIMDE_FLOAT32_C(   848.94) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    90.46), SIMDE_FLOAT32_C(   858.14), SIMDE_FLOAT32_C(  -123.29), SIMDE_FLOAT32_C(  -917.86) },
      { SIMDE_FLOAT32_C(  -788.14), SIMDE_FLOAT32_C(   739.22), SIMDE_FLOAT32_C(   572.18), SIMDE_FLOAT32_C(  -907.90) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   236.59), SIMDE_FLOAT32_C(  -239.64), SIMDE_FLOAT32_C(  -122.81), SIMDE_FLOAT32_C(   943.97) },
      { SIMDE_FLOAT32_C(   925.57), SIMDE_FLOAT32_C(   369.86), SIMDE_FLOAT32_C(  -610.11), SIMDE_FLOAT32_C(   -52.85) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -817.80), SIMDE_FLOAT32_C(   442.23), SIMDE_FLOAT32_C(  -530.12), SIMDE_FLOAT32_C(   987.30) },
      { SIMDE_FLOAT32_C(  -915.03), SIMDE_FLOAT32_C(   921.46), SIMDE_FLOAT32_C(   731.38), SIMDE_FLOAT32_C(   198.64) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   256.18), SIMDE_FLOAT32_C(   220.39), SIMDE_FLOAT32_C(  -453.64), SIMDE_FLOAT32_C(   264.67) },
      { SIMDE_FLOAT32_C(   594.64), SIMDE_FLOAT32_C(   189.87), SIMDE_FLOAT32_C(   113.62), SIMDE_FLOAT32_C(  -314.89) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    48.01), SIMDE_FLOAT32_C(   990.32), SIMDE_FLOAT32_C(  -232.76), SIMDE_FLOAT32_C(   259.86) },
      { SIMDE_FLOAT32_C(   729.55), SIMDE_FLOAT32_C(  -660.58), SIMDE_FLOAT32_C(   351.97), SIMDE_FLOAT32_C(   -33.86) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcagtq_f32(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcagtq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   230.31), SIMDE_FLOAT64_C(  -618.28) },
      { SIMDE_FLOAT64_C(   180.85), SIMDE_FLOAT64_C(   444.53) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   217.53), SIMDE_FLOAT64_C(  -615.67) },
      { SIMDE_FLOAT64_C(   629.35), SIMDE_FLOAT64_C(  -484.75) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   170.44), SIMDE_FLOAT64_C(  -454.09) },
      { SIMDE_FLOAT64_C(   330.58), SIMDE_FLOAT64_C(   520.13) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -764.76), SIMDE_FLOAT64_C(  -650.22) },
      { SIMDE_FLOAT64_C(   -78.50), SIMDE_FLOAT64_C(   683.38) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -812.10), SIMDE_FLOAT64_C(   401.95) },
      { SIMDE_FLOAT64_C(  -416.07), SIMDE_FLOAT64_C(   983.29) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -496.16), SIMDE_FLOAT64_C(   249.85) },
      { SIMDE_FLOAT64_C(    57.13), SIMDE_FLOAT64_C(  -909.73) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -537.53), SIMDE_FLOAT64_C(   707.06) },
      { SIMDE_FLOAT64_C(   -45.84), SIMDE_FLOAT64_C(  -807.07) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   -27.41), SIMDE_FLOAT64_C(   231.88) },
      { SIMDE_FLOAT64_C(  -442.67), SIMDE_FLOAT64_C(  -797.10) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcagtq_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcagts_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagtd_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcagt_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagt_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcagtq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagtq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
