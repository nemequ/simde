#define SIMDE_TEST_ARM_NEON_INSN ceq

#include "test-neon.h"
#include "../../../simde/arm/neon/ceq.h"

static int
test_simde_vceqs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 b;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_MATH_NANF,
      SIMDE_FLOAT32_C(     3.14),
                               0 },
    { SIMDE_FLOAT32_C(     1.62),
                 SIMDE_MATH_NANF,
                               0 },
    {            SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF,
                               0 },
    #endif

    { SIMDE_FLOAT32_C(   -56.05),
      SIMDE_FLOAT32_C(   -39.63),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   841.90),
      SIMDE_FLOAT32_C(   841.90),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -705.13),
      SIMDE_FLOAT32_C(  -696.24),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   -60.94),
      SIMDE_FLOAT32_C(   -60.94),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   769.23),
      SIMDE_FLOAT32_C(  -998.79),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   -11.03),
      SIMDE_FLOAT32_C(   -11.03),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   173.25),
      SIMDE_FLOAT32_C(   724.98),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   709.16),
      SIMDE_FLOAT32_C(   709.16),
                UINT32_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vceqs_f32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = (i & 1) ? a : simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    uint32_t r = simde_vceqs_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 b;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {             SIMDE_MATH_NAN,
      SIMDE_FLOAT64_C(     3.14),
                               0 },
    { SIMDE_FLOAT64_C(     1.62),
                  SIMDE_MATH_NAN,
                               0 },
    {             SIMDE_MATH_NAN,
                  SIMDE_MATH_NAN,
                               0 },
    #endif

    { SIMDE_FLOAT64_C(  -577.65),
      SIMDE_FLOAT64_C(  -703.85),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   325.12),
      SIMDE_FLOAT64_C(   325.12),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(  -527.91),
      SIMDE_FLOAT64_C(  -305.80),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -646.92),
      SIMDE_FLOAT64_C(  -646.92),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   438.65),
      SIMDE_FLOAT64_C(  -673.26),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -155.60),
      SIMDE_FLOAT64_C(  -155.60),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(  -252.03),
      SIMDE_FLOAT64_C(  -719.74),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(     6.27),
      SIMDE_FLOAT64_C(     6.27),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vceqd_f64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t b = (i & 1) ? a : simde_test_codegen_random_f64(-1000.0, 1000.0);
    uint64_t r = simde_vceqd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    { -INT64_C( 3883316718465380623),
      -INT64_C( 6525049216541933883),
      UINT64_C(                   0) },
    {  INT64_C(  144722424870567505),
       INT64_C(  144722424870567505),
                         UINT64_MAX },
    { -INT64_C( 4864164897981339177),
       INT64_C( 9142243167308417297),
      UINT64_C(                   0) },
    { -INT64_C( 6739643088005172605),
      -INT64_C( 6739643088005172605),
                         UINT64_MAX },
    { -INT64_C( 1746559855114065800),
      -INT64_C( 4942034653442889758),
      UINT64_C(                   0) },
    {  INT64_C( 6601627071088235366),
       INT64_C( 6601627071088235366),
                         UINT64_MAX },
    { -INT64_C( 7451588071995398749),
       INT64_C( 7531456216826416525),
      UINT64_C(                   0) },
    {  INT64_C( 2677530438617359042),
       INT64_C( 2677530438617359042),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vceqd_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = (i & 1) ? a : simde_test_codegen_random_i64();
    uint64_t r = simde_vceqd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C( 5604696383346243987),
      UINT64_C( 2792187346781598727),
      UINT64_C(                   0) },
    { UINT64_C(17677270875201804388),
      UINT64_C(17677270875201804388),
                         UINT64_MAX },
    { UINT64_C( 8831712695312082859),
      UINT64_C(13653696593774630020),
      UINT64_C(                   0) },
    { UINT64_C(17825427177876012193),
      UINT64_C(17825427177876012193),
                         UINT64_MAX },
    { UINT64_C( 1721557500519588795),
      UINT64_C( 6267904372928235163),
      UINT64_C(                   0) },
    { UINT64_C( 3411758805221171686),
      UINT64_C( 3411758805221171686),
                         UINT64_MAX },
    { UINT64_C(11261191358522146236),
      UINT64_C(17829590792684579308),
      UINT64_C(                   0) },
    { UINT64_C(16779414965382148533),
      UINT64_C(16779414965382148533),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vceqd_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = (i & 1) ? a : simde_test_codegen_random_u64();
    uint64_t r = simde_vceqd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    83.80), SIMDE_FLOAT32_C(   475.91) },
      { SIMDE_FLOAT32_C(    83.80), SIMDE_FLOAT32_C(   475.91) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   315.96), SIMDE_FLOAT32_C(    49.13) },
      { SIMDE_FLOAT32_C(   315.96), SIMDE_FLOAT32_C(    49.13) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   275.23), SIMDE_FLOAT32_C(  -410.87) },
      { SIMDE_FLOAT32_C(   275.23), SIMDE_FLOAT32_C(   115.66) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   336.04), SIMDE_FLOAT32_C(  -887.79) },
      { SIMDE_FLOAT32_C(   336.04), SIMDE_FLOAT32_C(   388.16) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   612.02), SIMDE_FLOAT32_C(   443.88) },
      { SIMDE_FLOAT32_C(   612.02), SIMDE_FLOAT32_C(   786.43) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -252.76), SIMDE_FLOAT32_C(   831.05) },
      { SIMDE_FLOAT32_C(   465.97), SIMDE_FLOAT32_C(   831.05) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -686.12), SIMDE_FLOAT32_C(   807.98) },
      { SIMDE_FLOAT32_C(  -686.12), SIMDE_FLOAT32_C(   169.08) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -388.06), SIMDE_FLOAT32_C(   887.17) },
      { SIMDE_FLOAT32_C(  -568.13), SIMDE_FLOAT32_C(   887.17) },
      { UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vceq_f32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a_[2], b_[2];
    simde_test_codegen_random_vf32(sizeof(a_) / sizeof(a_[0]), a_, -1000.0, 1000.0);
    simde_test_codegen_random_vf32(sizeof(b_) / sizeof(b_[0]), b_, -1000.0, 1000.0);
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint32x2_t r = simde_vceq_f32(simde_vld1_f32(a_), simde_vld1_f32(b_));

    simde_test_codegen_write_vf32(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf32(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   885.81) },
      { SIMDE_FLOAT64_C(   885.81) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    40.20) },
      { SIMDE_FLOAT64_C(    40.20) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -943.53) },
      { SIMDE_FLOAT64_C(  -943.53) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   766.97) },
      { SIMDE_FLOAT64_C(   766.97) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   492.60) },
      { SIMDE_FLOAT64_C(  -737.06) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   465.88) },
      { SIMDE_FLOAT64_C(   465.88) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -665.29) },
      { SIMDE_FLOAT64_C(  -902.43) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -382.78) },
      { SIMDE_FLOAT64_C(  -377.85) },
      { UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vceq_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a_[1], b_[1];
    simde_test_codegen_random_vf64(sizeof(a_) / sizeof(a_[0]), a_, -1000.0, 1000.0);
    simde_test_codegen_random_vf64(sizeof(b_) / sizeof(b_[0]), b_, -1000.0, 1000.0);
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint64x1_t r = simde_vceq_f64(simde_vld1_f64(a_), simde_vld1_f64(b_));

    simde_test_codegen_write_vf64(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf64(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C(   6), -INT8_C(  44),  INT8_C(  28),  INT8_C(  95), -INT8_C(  61),  INT8_C(  16),  INT8_C(   5), -INT8_C(  50) },
      { -INT8_C(   6), -INT8_C(  88),  INT8_C(  27),  INT8_C(  22), -INT8_C(  61),  INT8_C(  34), -INT8_C(  63), -INT8_C(   8) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C( 114), -INT8_C( 100), -INT8_C( 127),  INT8_C(  77), -INT8_C(   6), -INT8_C(  19), -INT8_C( 116), -INT8_C(  77) },
      { -INT8_C(  63), -INT8_C(  88), -INT8_C( 127),  INT8_C(  19), -INT8_C(  71), -INT8_C( 122), -INT8_C(  31), -INT8_C(  77) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C( 104), -INT8_C(  76), -INT8_C( 104), -INT8_C(  83), -INT8_C(  97), -INT8_C(   5),  INT8_C( 119),  INT8_C(  96) },
      { -INT8_C( 104), -INT8_C(  78), -INT8_C( 104), -INT8_C( 110), -INT8_C(  97),  INT8_C(  37), -INT8_C(  77),  INT8_C(  96) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 122),  INT8_C(   3), -INT8_C(  37),  INT8_C( 110), -INT8_C(  46), -INT8_C( 119),  INT8_C( 113),  INT8_C( 100) },
      {  INT8_C( 122), -INT8_C(  42),  INT8_C(  18),  INT8_C(  82), -INT8_C(  46), -INT8_C( 119), -INT8_C(  99),  INT8_C( 106) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  20),  INT8_C( 100), -INT8_C(  81),  INT8_C( 122),  INT8_C(   1),  INT8_C(  48), -INT8_C(  33),  INT8_C(  81) },
      { -INT8_C(  20),  INT8_C( 100), -INT8_C(  65),  INT8_C( 122),  INT8_C(  41),  INT8_C(  48), -INT8_C(  33), -INT8_C(  93) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  55), -INT8_C(   4), -INT8_C( 112),  INT8_C( 122), -INT8_C(  27), -INT8_C(   6), -INT8_C(  53), -INT8_C(  46) },
      {  INT8_C( 120), -INT8_C(   4),  INT8_C( 113),  INT8_C( 122), -INT8_C(  27), -INT8_C(   6), -INT8_C(  53), -INT8_C(  47) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  29),  INT8_C(  33), -INT8_C( 101), -INT8_C( 106), -INT8_C(  76), -INT8_C(  34),  INT8_C(  76),  INT8_C( 126) },
      {  INT8_C(  29), -INT8_C(  35), -INT8_C(  94),  INT8_C(  12), -INT8_C(  88), -INT8_C(  17), -INT8_C(  34),  INT8_C(  32) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C( 123), -INT8_C(  18),  INT8_C(  47),  INT8_C(  48),  INT8_C(  25),  INT8_C(  24), -INT8_C(  82),  INT8_C(   6) },
      {  INT8_C( 123),  INT8_C(  10), -INT8_C(  53),  INT8_C(  48), -INT8_C(  23),  INT8_C(  24), -INT8_C(  82),  INT8_C(   6) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vceq_s8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[8], b_[8];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint8x8_t r = simde_vceq_s8(simde_vld1_s8(a_), simde_vld1_s8(b_));

    simde_test_codegen_write_vi8(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi8(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 10359),  INT16_C(  9925),  INT16_C(  3010),  INT16_C( 26232) },
      {  INT16_C(   851),  INT16_C(  9925), -INT16_C( 16151), -INT16_C( 25263) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 24614), -INT16_C(  1678),  INT16_C(  3577), -INT16_C( 17548) },
      {  INT16_C(  8550), -INT16_C(  4287),  INT16_C(  3577), -INT16_C( 17548) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(  5626),  INT16_C( 11378), -INT16_C(  6838),  INT16_C( 17189) },
      { -INT16_C(  5626),  INT16_C( 11378), -INT16_C(  6838),  INT16_C( 17189) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 28630),  INT16_C( 23584), -INT16_C( 32611), -INT16_C( 18978) },
      { -INT16_C(   147),  INT16_C( 23584), -INT16_C( 19739), -INT16_C( 29899) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 29173),  INT16_C(  8094), -INT16_C( 21759), -INT16_C( 32478) },
      {  INT16_C( 29173),  INT16_C(  8094), -INT16_C( 21759), -INT16_C( 25021) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  1238),  INT16_C( 27477),  INT16_C(  7144), -INT16_C( 17774) },
      {  INT16_C(  1238),  INT16_C( 27477),  INT16_C(  7144), -INT16_C( 19893) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 11809), -INT16_C(  8164),  INT16_C( 13638), -INT16_C( 22401) },
      { -INT16_C( 11648), -INT16_C( 24256),  INT16_C( 13638),  INT16_C( 27816) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 31806),  INT16_C(  9889), -INT16_C( 18467),  INT16_C( 22809) },
      {  INT16_C(  2906),  INT16_C( 14747), -INT16_C( 18467),  INT16_C( 22809) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vceq_s16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[4], b_[4];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint16x4_t r = simde_vceq_s16(simde_vld1_s16(a_), simde_vld1_s16(b_));

    simde_test_codegen_write_vi16(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi16(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1874778135),  INT32_C(   443140088) },
      {  INT32_C(   126021491),  INT32_C(   207635942) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(   854773045),  INT32_C(  2091071115) },
      {  INT32_C(    53628719), -INT32_C(  1394914834) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(  1710993738), -INT32_C(   135368431) },
      { -INT32_C(  1710993738),  INT32_C(  1432828258) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1167126645),  INT32_C(  1287561566) },
      { -INT32_C(  1560700438),  INT32_C(  1556311405) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1967686665), -INT32_C(   216149872) },
      {  INT32_C(  1967686665), -INT32_C(   427502729) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1898924935),  INT32_C(  1999338411) },
      { -INT32_C(   374417771),  INT32_C(  1999338411) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1476217289),  INT32_C(  1537377324) },
      {  INT32_C(  1476217289),  INT32_C(  1537377324) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   416942211), -INT32_C(  1996388130) },
      {  INT32_C(    33565700), -INT32_C(  1776400409) },
      { UINT32_C(         0), UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vceq_s32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[2], b_[2];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint32x2_t r = simde_vceq_s32(simde_vld1_s32(a_), simde_vld1_s32(b_));

    simde_test_codegen_write_vi32(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi32(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 8535823101435549350) },
      { -INT64_C(   68493279294832619) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 6450899593806032554) },
      { -INT64_C( 8184543586398563143) },
      { UINT64_C(                   0) } },
    { {  INT64_C(  644778802918027581) },
      {  INT64_C( 9064137101271018600) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 2793435887488105527) },
      { -INT64_C( 4849783837811557109) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 6774498698231718756) },
      { -INT64_C( 6318717217871057330) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 3230373444996287677) },
      {  INT64_C( 3230373444996287677) },
      {                    UINT64_MAX } },
    { {  INT64_C( 8905651318291695689) },
      {  INT64_C( 8905651318291695689) },
      {                    UINT64_MAX } },
    { {  INT64_C( 3813610299838181612) },
      {  INT64_C( 3813610299838181612) },
      {                    UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vceq_s64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[1], b_[1];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint64x1_t r = simde_vceq_s64(simde_vld1_s64(a_), simde_vld1_s64(b_));

    simde_test_codegen_write_vi64(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi64(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(228), UINT8_C(114), UINT8_C( 18), UINT8_C(209), UINT8_C(222), UINT8_C(238), UINT8_C(135), UINT8_C( 83) },
      { UINT8_C(120), UINT8_C( 62), UINT8_C( 18), UINT8_C( 17), UINT8_C(222), UINT8_C( 31), UINT8_C(135), UINT8_C( 19) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(102), UINT8_C( 52), UINT8_C(143), UINT8_C( 47), UINT8_C(218), UINT8_C(224), UINT8_C(199), UINT8_C(190) },
      { UINT8_C(178), UINT8_C( 52), UINT8_C(143), UINT8_C(116), UINT8_C( 34), UINT8_C(224), UINT8_C(199), UINT8_C(155) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 42), UINT8_C( 74), UINT8_C(211), UINT8_C(  7), UINT8_C(134), UINT8_C(117), UINT8_C(195), UINT8_C(236) },
      { UINT8_C( 42), UINT8_C( 20), UINT8_C( 28), UINT8_C(  4), UINT8_C( 83), UINT8_C(117), UINT8_C(195), UINT8_C(  5) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 27), UINT8_C(189), UINT8_C(145), UINT8_C( 19), UINT8_C( 70), UINT8_C( 91), UINT8_C( 25), UINT8_C(138) },
      { UINT8_C(166), UINT8_C(189), UINT8_C(145), UINT8_C( 44), UINT8_C( 95), UINT8_C( 22), UINT8_C( 25), UINT8_C(137) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(163), UINT8_C(253), UINT8_C( 32), UINT8_C(224), UINT8_C(206), UINT8_C( 87), UINT8_C( 38), UINT8_C(116) },
      { UINT8_C(154), UINT8_C(114), UINT8_C(109), UINT8_C(224), UINT8_C(206), UINT8_C( 87), UINT8_C(107), UINT8_C(116) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 60), UINT8_C( 13), UINT8_C(187), UINT8_C(123), UINT8_C(218), UINT8_C(121), UINT8_C(213), UINT8_C( 46) },
      { UINT8_C( 60), UINT8_C( 13), UINT8_C( 83), UINT8_C(123), UINT8_C(148), UINT8_C(121), UINT8_C(213), UINT8_C( 46) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(169), UINT8_C(206), UINT8_C( 15), UINT8_C(131), UINT8_C(193), UINT8_C( 31), UINT8_C(  1), UINT8_C(118) },
      { UINT8_C(169), UINT8_C(130), UINT8_C( 15), UINT8_C(131), UINT8_C(193), UINT8_C(252), UINT8_C(  1), UINT8_C(253) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(145), UINT8_C(217), UINT8_C( 82), UINT8_C(245), UINT8_C( 83), UINT8_C(159), UINT8_C(107), UINT8_C(197) },
      { UINT8_C(109), UINT8_C(253), UINT8_C( 82), UINT8_C(245), UINT8_C( 28), UINT8_C( 24), UINT8_C(107), UINT8_C(197) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vceq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[8], b_[8];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint8x8_t r = simde_vceq_u8(simde_vld1_u8(a_), simde_vld1_u8(b_));

    simde_test_codegen_write_vu8(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu8(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(29979), UINT16_C(15451), UINT16_C(55565), UINT16_C( 2788) },
      { UINT16_C(29979), UINT16_C(15451), UINT16_C(55565), UINT16_C(52687) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(18039), UINT16_C( 7331), UINT16_C(33155), UINT16_C( 8027) },
      { UINT16_C(60406), UINT16_C(58586), UINT16_C(28391), UINT16_C(26862) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 9069), UINT16_C(21606), UINT16_C(21866), UINT16_C(60672) },
      { UINT16_C( 9069), UINT16_C(58546), UINT16_C(21866), UINT16_C(60672) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 2674), UINT16_C(12209), UINT16_C(62680), UINT16_C(25495) },
      { UINT16_C( 2674), UINT16_C(47757), UINT16_C(62680), UINT16_C(32526) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(10068), UINT16_C( 7713), UINT16_C(31613), UINT16_C(62541) },
      { UINT16_C(47319), UINT16_C( 7713), UINT16_C(53919), UINT16_C(62541) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(48094), UINT16_C(12953), UINT16_C( 5346), UINT16_C(  838) },
      { UINT16_C(48094), UINT16_C(12953), UINT16_C( 5346), UINT16_C(24560) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(16567), UINT16_C(42750), UINT16_C(53927), UINT16_C(65389) },
      { UINT16_C(16567), UINT16_C(42750), UINT16_C(40229), UINT16_C(65389) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(25574), UINT16_C(20571), UINT16_C(19375), UINT16_C(16048) },
      { UINT16_C(25574), UINT16_C(15012), UINT16_C(10552), UINT16_C(57134) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vceq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[4], b_[4];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint16x4_t r = simde_vceq_u16(simde_vld1_u16(a_), simde_vld1_u16(b_));

    simde_test_codegen_write_vu16(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu16(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(4068292116), UINT32_C(1657391483) },
      { UINT32_C(2579237544), UINT32_C(3419376549) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3471013382), UINT32_C(1572021813) },
      { UINT32_C(3471013382), UINT32_C( 755365807) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3576563242), UINT32_C( 591969003) },
      { UINT32_C(3576563242), UINT32_C( 591969003) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1339722057), UINT32_C(2253574819) },
      { UINT32_C(2682004405), UINT32_C(2253574819) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 817654875), UINT32_C(3300460009) },
      { UINT32_C( 817654875), UINT32_C(3300460009) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 929592194), UINT32_C(2855199800) },
      { UINT32_C(2260674582), UINT32_C(2855199800) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2792773707), UINT32_C(2933273541) },
      { UINT32_C(2373095480), UINT32_C(2969629769) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 198181621), UINT32_C( 318789789) },
      { UINT32_C(2819473524), UINT32_C( 318789789) },
      { UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vceq_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[2], b_[2];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint32x2_t r = simde_vceq_u32(simde_vld1_u32(a_), simde_vld1_u32(b_));

    simde_test_codegen_write_vu32(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu32(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(  462129490676742370) },
      { UINT64_C( 3396253101468774017) },
      { UINT64_C(                   0) } },
    { { UINT64_C(15200919614915212372) },
      { UINT64_C(15200919614915212372) },
      {                    UINT64_MAX } },
    { { UINT64_C(16437398615333454713) },
      { UINT64_C(16437398615333454713) },
      {                    UINT64_MAX } },
    { { UINT64_C( 1324451836855196340) },
      { UINT64_C( 1324451836855196340) },
      {                    UINT64_MAX } },
    { { UINT64_C( 4023702131190414723) },
      { UINT64_C( 4659676053606091433) },
      { UINT64_C(                   0) } },
    { { UINT64_C(10209850915128622795) },
      { UINT64_C(10209850915128622795) },
      {                    UINT64_MAX } },
    { { UINT64_C( 2190433362220569284) },
      { UINT64_C(11845426152445055938) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 6586157150835866609) },
      { UINT64_C( 6586157150835866609) },
      {                    UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vceq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[1], b_[1];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint64x1_t r = simde_vceq_u64(simde_vld1_u64(a_), simde_vld1_u64(b_));

    simde_test_codegen_write_vu64(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu64(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   151.95), SIMDE_FLOAT32_C(   801.55), SIMDE_FLOAT32_C(   470.19), SIMDE_FLOAT32_C(   494.12) },
      { SIMDE_FLOAT32_C(  -614.47), SIMDE_FLOAT32_C(   801.55), SIMDE_FLOAT32_C(   128.44), SIMDE_FLOAT32_C(   494.12) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -211.99), SIMDE_FLOAT32_C(   401.96), SIMDE_FLOAT32_C(  -113.21), SIMDE_FLOAT32_C(    64.60) },
      { SIMDE_FLOAT32_C(  -211.99), SIMDE_FLOAT32_C(    68.77), SIMDE_FLOAT32_C(  -113.21), SIMDE_FLOAT32_C(    64.60) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   843.56), SIMDE_FLOAT32_C(   416.97), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(   -30.43) },
      { SIMDE_FLOAT32_C(    54.01), SIMDE_FLOAT32_C(   416.97), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(  -794.04) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   264.61), SIMDE_FLOAT32_C(  -269.86), SIMDE_FLOAT32_C(  -951.46), SIMDE_FLOAT32_C(  -765.17) },
      { SIMDE_FLOAT32_C(   264.61), SIMDE_FLOAT32_C(   341.73), SIMDE_FLOAT32_C(  -453.78), SIMDE_FLOAT32_C(  -765.17) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -863.16), SIMDE_FLOAT32_C(   964.02), SIMDE_FLOAT32_C(  -403.70), SIMDE_FLOAT32_C(   980.39) },
      { SIMDE_FLOAT32_C(  -863.16), SIMDE_FLOAT32_C(  -832.51), SIMDE_FLOAT32_C(  -252.53), SIMDE_FLOAT32_C(   980.39) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -506.48), SIMDE_FLOAT32_C(   986.65), SIMDE_FLOAT32_C(   541.36), SIMDE_FLOAT32_C(  -198.05) },
      { SIMDE_FLOAT32_C(  -506.48), SIMDE_FLOAT32_C(   852.79), SIMDE_FLOAT32_C(   541.36), SIMDE_FLOAT32_C(  -198.05) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   -68.37), SIMDE_FLOAT32_C(  -248.88), SIMDE_FLOAT32_C(  -917.64), SIMDE_FLOAT32_C(  -455.58) },
      { SIMDE_FLOAT32_C(  -886.61), SIMDE_FLOAT32_C(   159.60), SIMDE_FLOAT32_C(   207.02), SIMDE_FLOAT32_C(  -455.58) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   970.82), SIMDE_FLOAT32_C(  -809.19), SIMDE_FLOAT32_C(   240.85), SIMDE_FLOAT32_C(   -38.07) },
      { SIMDE_FLOAT32_C(   332.11), SIMDE_FLOAT32_C(  -809.19), SIMDE_FLOAT32_C(     7.05), SIMDE_FLOAT32_C(  -849.83) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vceqq_f32(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a_[4], b_[4];
    simde_test_codegen_random_vf32(sizeof(a_) / sizeof(a_[0]), a_, -1000.0, 1000.0);
    simde_test_codegen_random_vf32(sizeof(b_) / sizeof(b_[0]), b_, -1000.0, 1000.0);
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint32x4_t r = simde_vceqq_f32(simde_vld1q_f32(a_), simde_vld1q_f32(b_));

    simde_test_codegen_write_vf32(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf32(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   211.07), SIMDE_FLOAT64_C(  -652.68) },
      { SIMDE_FLOAT64_C(  -764.13), SIMDE_FLOAT64_C(  -652.68) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -650.75), SIMDE_FLOAT64_C(  -819.92) },
      { SIMDE_FLOAT64_C(  -825.40), SIMDE_FLOAT64_C(  -295.90) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   934.40), SIMDE_FLOAT64_C(  -562.53) },
      { SIMDE_FLOAT64_C(   934.40), SIMDE_FLOAT64_C(   790.23) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -625.41), SIMDE_FLOAT64_C(    22.91) },
      { SIMDE_FLOAT64_C(  -625.41), SIMDE_FLOAT64_C(    22.91) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   523.75), SIMDE_FLOAT64_C(   311.54) },
      { SIMDE_FLOAT64_C(   286.95), SIMDE_FLOAT64_C(   311.54) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    41.17), SIMDE_FLOAT64_C(   277.04) },
      { SIMDE_FLOAT64_C(   630.41), SIMDE_FLOAT64_C(   277.04) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -701.97), SIMDE_FLOAT64_C(  -163.42) },
      { SIMDE_FLOAT64_C(  -701.97), SIMDE_FLOAT64_C(   980.64) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   144.09), SIMDE_FLOAT64_C(  -754.88) },
      { SIMDE_FLOAT64_C(  -879.09), SIMDE_FLOAT64_C(    78.48) },
      { UINT64_C(                   0), UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vceqq_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a_[2], b_[2];
    simde_test_codegen_random_vf64(sizeof(a_) / sizeof(a_[0]), a_, -1000.0, 1000.0);
    simde_test_codegen_random_vf64(sizeof(b_) / sizeof(b_[0]), b_, -1000.0, 1000.0);
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint64x2_t r = simde_vceqq_f64(simde_vld1q_f64(a_), simde_vld1q_f64(b_));

    simde_test_codegen_write_vf64(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf64(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   9), -INT8_C(   9), -INT8_C(  98),  INT8_C(  88),  INT8_C(  87), -INT8_C(  10), -INT8_C(  23), -INT8_C(  78),
        -INT8_C(  51), -INT8_C( 101),  INT8_C(  84), -INT8_C(  61), -INT8_C( 126),  INT8_C(  45),  INT8_C( 125),  INT8_C(  85) },
      {  INT8_C(  33), -INT8_C(   9),  INT8_C(  48), -INT8_C(  50), -INT8_C( 123), -INT8_C(  10),  INT8_C( 109), -INT8_C(  12),
         INT8_C(  61),  INT8_C(   6),  INT8_C(  84), -INT8_C(  65),  INT8_C(  94),  INT8_C(  46),  INT8_C(  97),  INT8_C(  85) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  32), -INT8_C(  24),  INT8_C(  19), -INT8_C(  51),      INT8_MAX,      INT8_MIN, -INT8_C( 121), -INT8_C(  63),
         INT8_C(  56),  INT8_C(   4),      INT8_MIN,  INT8_C(  92), -INT8_C(   2), -INT8_C(  31), -INT8_C(  95), -INT8_C(  17) },
      { -INT8_C(  32), -INT8_C(  24), -INT8_C( 110), -INT8_C(  51),      INT8_MAX,  INT8_C(  66), -INT8_C( 121), -INT8_C(  79),
         INT8_C(  56),  INT8_C(   4),  INT8_C( 101),  INT8_C(  92), -INT8_C(   2), -INT8_C(  61), -INT8_C(  95), -INT8_C(  17) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  62), -INT8_C(  93),  INT8_C(  65),  INT8_C(   6), -INT8_C(  27), -INT8_C(  40), -INT8_C(  14), -INT8_C(  27),
        -INT8_C(  17),  INT8_C(  87),  INT8_C(  98), -INT8_C(  24),  INT8_C(  26),  INT8_C(  27), -INT8_C(  62),  INT8_C( 107) },
      { -INT8_C(  48), -INT8_C( 123),  INT8_C(  65),  INT8_C(   6),  INT8_C(  85), -INT8_C(  40), -INT8_C(  62), -INT8_C(  27),
        -INT8_C(  17),  INT8_C(  98),  INT8_C(  98), -INT8_C(  24),  INT8_C(  61),  INT8_C( 115), -INT8_C(  62), -INT8_C(   1) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  44),  INT8_C(  38), -INT8_C( 124), -INT8_C(  62),  INT8_C(  42),  INT8_C(  70), -INT8_C( 118), -INT8_C(  27),
         INT8_C( 102), -INT8_C( 127), -INT8_C( 118), -INT8_C(  26), -INT8_C( 105), -INT8_C(  60), -INT8_C(  27),  INT8_C(  50) },
      {  INT8_C(  44),  INT8_C(  38), -INT8_C(  69), -INT8_C(  62),  INT8_C(  90), -INT8_C(  44), -INT8_C( 118), -INT8_C(  27),
         INT8_C( 102), -INT8_C( 127), -INT8_C( 118),  INT8_C(  20), -INT8_C( 105), -INT8_C( 101), -INT8_C( 109),  INT8_C(  50) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(   7), -INT8_C(  36), -INT8_C(  26),  INT8_C(  83), -INT8_C(  44),  INT8_C( 112), -INT8_C(  76), -INT8_C( 112),
        -INT8_C(  15), -INT8_C(  62), -INT8_C(  91), -INT8_C( 120),  INT8_C(  94),  INT8_C(  56), -INT8_C(  70),  INT8_C( 109) },
      {  INT8_C(  79), -INT8_C(  36),  INT8_C(  99), -INT8_C(  83), -INT8_C(  44), -INT8_C( 108), -INT8_C(  76),  INT8_C(   4),
        -INT8_C(  57), -INT8_C(  95), -INT8_C(  34), -INT8_C(  66),  INT8_C( 116),  INT8_C( 120), -INT8_C(  31),  INT8_C( 109) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  71), -INT8_C(  57),  INT8_C(  99), -INT8_C(  64),  INT8_C(  91),  INT8_C(  23), -INT8_C(  23),  INT8_C(  12),
        -INT8_C(  12), -INT8_C( 103), -INT8_C(  32),  INT8_C(  90),  INT8_C( 118), -INT8_C(  63), -INT8_C( 102),  INT8_C(  75) },
      { -INT8_C( 119),  INT8_C(  90),  INT8_C(  61), -INT8_C(  64),  INT8_C(  82), -INT8_C(  58), -INT8_C(  23),  INT8_C(  12),
        -INT8_C(  12), -INT8_C( 103),  INT8_C(  37),  INT8_C(  90),  INT8_C(   4), -INT8_C( 119),  INT8_C(  15),  INT8_C(  75) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 100), -INT8_C(  16), -INT8_C(  72), -INT8_C( 101),  INT8_C(  65), -INT8_C(  95), -INT8_C(  62), -INT8_C(   7),
         INT8_C(  58),  INT8_C(  78), -INT8_C(  13),  INT8_C(  62),  INT8_C(  88),  INT8_C(  49),  INT8_C(  75), -INT8_C(  64) },
      {  INT8_C(  17), -INT8_C(  16),  INT8_C( 107), -INT8_C( 101),  INT8_C( 118),  INT8_C(  56), -INT8_C(  34), -INT8_C(   7),
        -INT8_C(  27),  INT8_C(  78), -INT8_C(  13),  INT8_C(  84),  INT8_C(  88),  INT8_C(  49),  INT8_C(  75), -INT8_C(  68) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C( 105), -INT8_C(  72), -INT8_C(  61),  INT8_C(  30), -INT8_C(  30), -INT8_C(  39), -INT8_C(   3), -INT8_C(   2),
        -INT8_C( 106), -INT8_C(   7),  INT8_C(  42),      INT8_MAX,  INT8_C(  42),  INT8_C( 118),  INT8_C(  59),  INT8_C(  88) },
      {  INT8_C( 121), -INT8_C(  83), -INT8_C(  61),  INT8_C(  30), -INT8_C(  30), -INT8_C(  27), -INT8_C(   3), -INT8_C(   2),
        -INT8_C( 106),  INT8_C(  26), -INT8_C( 118), -INT8_C(  26), -INT8_C(  63), -INT8_C(  41),  INT8_C(  70),  INT8_C(  88) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vceqq_s8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[16], b_[16];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint8x16_t r = simde_vceqq_s8(simde_vld1q_s8(a_), simde_vld1q_s8(b_));

    simde_test_codegen_write_vi8(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi8(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 30689),  INT16_C( 17219),  INT16_C( 24342), -INT16_C(  6278), -INT16_C( 13469), -INT16_C( 11550), -INT16_C( 32354),  INT16_C( 32558) },
      {  INT16_C(  2591),  INT16_C( 17219),  INT16_C( 24342),  INT16_C( 11098), -INT16_C( 31655), -INT16_C( 11550), -INT16_C( 32354),  INT16_C( 32558) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 13658), -INT16_C(  1829),  INT16_C(  1817),  INT16_C( 14349),  INT16_C( 20497),  INT16_C(  2181),  INT16_C( 17067),  INT16_C( 19767) },
      {  INT16_C( 13658), -INT16_C(  1829),  INT16_C(  2742), -INT16_C( 20873), -INT16_C( 11205),  INT16_C(  2181),  INT16_C( 17067),  INT16_C( 19767) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(  8203), -INT16_C( 17794),  INT16_C(  9266),  INT16_C( 20931), -INT16_C( 24826), -INT16_C( 17335), -INT16_C( 26633), -INT16_C(  7061) },
      { -INT16_C(  3947),  INT16_C( 16876),  INT16_C(  9266), -INT16_C( 31090),  INT16_C( 15459), -INT16_C( 22030), -INT16_C( 26633),  INT16_C(   512) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  6571), -INT16_C( 23607), -INT16_C( 13904),  INT16_C( 26789),  INT16_C( 25160), -INT16_C( 24352),  INT16_C(  5859),  INT16_C(   750) },
      {  INT16_C(  6571), -INT16_C( 23607), -INT16_C( 13904),  INT16_C( 26789),  INT16_C( 25160), -INT16_C( 26601),  INT16_C(  5859),  INT16_C(   750) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(   593), -INT16_C( 28062), -INT16_C( 19368),  INT16_C(  1263), -INT16_C( 17971), -INT16_C( 11555),  INT16_C( 19586), -INT16_C(  5697) },
      { -INT16_C(   593), -INT16_C( 28062),  INT16_C( 20756),  INT16_C( 29588),  INT16_C( 24402), -INT16_C( 11555), -INT16_C(  6441), -INT16_C(  5697) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 11424),  INT16_C( 11397),  INT16_C( 13343), -INT16_C( 12627), -INT16_C( 12910), -INT16_C( 27533), -INT16_C(  2719), -INT16_C( 10908) },
      { -INT16_C( 27052),  INT16_C( 11397),  INT16_C( 17788),  INT16_C( 19221), -INT16_C( 12910), -INT16_C( 27533), -INT16_C( 24716), -INT16_C( 10908) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 16011), -INT16_C( 10660), -INT16_C(  8314),  INT16_C(  2698),  INT16_C(  6801),  INT16_C( 30346),  INT16_C( 19284), -INT16_C(  2675) },
      { -INT16_C(  6632), -INT16_C( 29317), -INT16_C(  8314), -INT16_C(  1950),  INT16_C(  6801),  INT16_C( 30346), -INT16_C(  5249), -INT16_C(  2675) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 13584), -INT16_C( 28925),  INT16_C( 17902),  INT16_C(  1952),  INT16_C( 20602), -INT16_C( 19820), -INT16_C( 25947),  INT16_C(  2597) },
      {  INT16_C( 13584), -INT16_C( 28925), -INT16_C( 28640), -INT16_C( 13180),  INT16_C( 20602),  INT16_C( 31278), -INT16_C( 25947),  INT16_C(  2597) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vceqq_s16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[8], b_[8];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint16x8_t r = simde_vceqq_s16(simde_vld1q_s16(a_), simde_vld1q_s16(b_));

    simde_test_codegen_write_vi16(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi16(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  INT32_C(    68585909), -INT32_C(   304121191), -INT32_C(  1443602637), -INT32_C(   449347537) },
      { -INT32_C(     6934970),  INT32_C(  1969593714), -INT32_C(  1443602637), -INT32_C(   449347537) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1418774728), -INT32_C(   350283357),  INT32_C(  1677692505),  INT32_C(  1864817917) },
      { -INT32_C(  1377530759),  INT32_C(   441899499),  INT32_C(  1677692505), -INT32_C(  1543051044) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1858135888),  INT32_C(  1238200173),  INT32_C(   149803864),  INT32_C(   442295914) },
      {  INT32_C(  1769004816),  INT32_C(  1238200173),  INT32_C(   149803864),  INT32_C(   442295914) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  2084019423), -INT32_C(  1403118783),  INT32_C(  1324392016),  INT32_C(  1513331513) },
      {  INT32_C(   964466913), -INT32_C(   700356244),  INT32_C(  1324392016),  INT32_C(  1513331513) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1366407681), -INT32_C(  1851760296), -INT32_C(    85142532), -INT32_C(  1686595537) },
      {  INT32_C(  1366407681), -INT32_C(  1851760296), -INT32_C(    85142532), -INT32_C(   432420401) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1880168978),  INT32_C(  1531164812), -INT32_C(   948229947), -INT32_C(  1280339551) },
      {  INT32_C(  1238153293),  INT32_C(  1531164812), -INT32_C(  2025685887), -INT32_C(  1280339551) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  1271016210), -INT32_C(  1683589639), -INT32_C(  1286712057),  INT32_C(    84963862) },
      {  INT32_C(   523468189), -INT32_C(  1683589639), -INT32_C(  1286712057),  INT32_C(    84963862) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1679457388),  INT32_C(   328874951), -INT32_C(   302752090), -INT32_C(  1338987093) },
      { -INT32_C(  1679457388), -INT32_C(   280087335), -INT32_C(   302752090), -INT32_C(  1338987093) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vceqq_s32(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[4], b_[4];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint32x4_t r = simde_vceqq_s32(simde_vld1q_s32(a_), simde_vld1q_s32(b_));

    simde_test_codegen_write_vi32(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi32(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  INT64_C(  122496343496134342), -INT64_C( 8871796291912087289) },
      { -INT64_C( 1619632953150757040), -INT64_C( 1315802993512906350) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C( 2083288838247884909),  INT64_C(  652781822731857462) },
      {  INT64_C( 8036705605673239169),  INT64_C(  652781822731857462) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C( 5840191344206578756), -INT64_C( 4478792894918717845) },
      { -INT64_C( 5840191344206578756), -INT64_C( 4478792894918717845) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 2165879478655069652), -INT64_C( 8949288324055110036) },
      {  INT64_C(  240926292617560533), -INT64_C( 8949288324055110036) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C( 4084512031659993958),  INT64_C(  681759254808292176) },
      {  INT64_C( 8087071077733255670),  INT64_C(  681759254808292176) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C(  135823057901789263), -INT64_C( 4749785724592454897) },
      {  INT64_C( 6527389508598676334), -INT64_C( 4749785724592454897) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C(  946894890669630655),  INT64_C( 7671867306212125913) },
      {  INT64_C( 6188038121830254663),  INT64_C( 7671867306212125913) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 2558880696443476662), -INT64_C( 3803050708524976813) },
      {  INT64_C( 2558880696443476662), -INT64_C( 2390307941852566042) },
      {                    UINT64_MAX, UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vceqq_s64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[2], b_[2];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint64x2_t r = simde_vceqq_s64(simde_vld1q_s64(a_), simde_vld1q_s64(b_));

    simde_test_codegen_write_vi64(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi64(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(113), UINT8_C( 65), UINT8_C( 13), UINT8_C( 19), UINT8_C(188), UINT8_C( 30), UINT8_C(127), UINT8_C( 46),
        UINT8_C(  5), UINT8_C(161), UINT8_C(152), UINT8_C(201), UINT8_C(221), UINT8_C( 11), UINT8_C(234), UINT8_C(187) },
      { UINT8_C(113), UINT8_C( 65), UINT8_C(119), UINT8_C(215), UINT8_C( 83), UINT8_C( 30), UINT8_C( 66), UINT8_C( 46),
        UINT8_C(  5), UINT8_C(160), UINT8_C( 36), UINT8_C( 28), UINT8_C(221), UINT8_C(166), UINT8_C(124), UINT8_C( 52) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {    UINT8_MAX, UINT8_C(125), UINT8_C(194), UINT8_C( 32), UINT8_C(198), UINT8_C(  9), UINT8_C( 43), UINT8_C( 47),
        UINT8_C(164),    UINT8_MAX, UINT8_C(121), UINT8_C(240), UINT8_C( 75), UINT8_C( 56), UINT8_C(182), UINT8_C( 97) },
      { UINT8_C(194), UINT8_C(254), UINT8_C( 51), UINT8_C( 32), UINT8_C(198), UINT8_C(  9), UINT8_C( 43), UINT8_C( 47),
        UINT8_C(119),    UINT8_MAX, UINT8_C(121), UINT8_C(240), UINT8_C(189), UINT8_C(127), UINT8_C(218), UINT8_C(189) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(124), UINT8_C( 21), UINT8_C(254), UINT8_C(157), UINT8_C( 30), UINT8_C( 54), UINT8_C(113), UINT8_C(139),
        UINT8_C( 57), UINT8_C(235), UINT8_C(133), UINT8_C(247), UINT8_C(106), UINT8_C( 96), UINT8_C( 67), UINT8_C(103) },
      { UINT8_C(252), UINT8_C(196), UINT8_C(254), UINT8_C(157), UINT8_C( 85), UINT8_C( 54), UINT8_C(227), UINT8_C(139),
        UINT8_C( 41), UINT8_C(170), UINT8_C( 12), UINT8_C( 85), UINT8_C( 40), UINT8_C(239), UINT8_C( 67), UINT8_C(165) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 94), UINT8_C( 20), UINT8_C( 55), UINT8_C(234), UINT8_C(211), UINT8_C(240), UINT8_C(176), UINT8_C( 23),
        UINT8_C(197), UINT8_C( 33), UINT8_C(198), UINT8_C(238), UINT8_C( 16), UINT8_C( 12), UINT8_C(102), UINT8_C( 17) },
      { UINT8_C( 94), UINT8_C(122), UINT8_C( 55), UINT8_C(234), UINT8_C(211), UINT8_C(240), UINT8_C(176), UINT8_C( 23),
        UINT8_C( 46), UINT8_C(108), UINT8_C(198), UINT8_C(204), UINT8_C(221), UINT8_C(219), UINT8_C(102), UINT8_C( 17) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 27), UINT8_C( 44), UINT8_C( 48), UINT8_C( 78), UINT8_C( 33), UINT8_C(221), UINT8_C(101), UINT8_C(241),
        UINT8_C(232), UINT8_C(193), UINT8_C( 22), UINT8_C(213), UINT8_C(  7), UINT8_C(199), UINT8_C(214), UINT8_C( 59) },
      { UINT8_C( 27), UINT8_C(113), UINT8_C( 48), UINT8_C(213), UINT8_C( 33), UINT8_C(221), UINT8_C( 84), UINT8_C(241),
        UINT8_C( 83), UINT8_C(193), UINT8_C(210), UINT8_C(213), UINT8_C(193), UINT8_C(199), UINT8_C(182), UINT8_C( 59) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(242), UINT8_C(121), UINT8_C(222), UINT8_C(131), UINT8_C(104), UINT8_C(252), UINT8_C(105), UINT8_C(131),
        UINT8_C(243), UINT8_C( 19), UINT8_C(164), UINT8_C(180), UINT8_C(148), UINT8_C(188), UINT8_C(240), UINT8_C(135) },
      { UINT8_C(134), UINT8_C(121), UINT8_C(161), UINT8_C(131), UINT8_C(104), UINT8_C(252), UINT8_C(105), UINT8_C(131),
        UINT8_C(109), UINT8_C( 19), UINT8_C(164), UINT8_C( 91), UINT8_C(148), UINT8_C(188), UINT8_C(100), UINT8_C(135) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(179), UINT8_C( 71), UINT8_C(  1), UINT8_C(239), UINT8_C( 67), UINT8_C(163), UINT8_C(145), UINT8_C( 69),
        UINT8_C(121), UINT8_C( 23), UINT8_C( 11), UINT8_C( 13), UINT8_C(211),    UINT8_MAX, UINT8_C(148), UINT8_C( 67) },
      { UINT8_C(179), UINT8_C( 47), UINT8_C(  1), UINT8_C( 40), UINT8_C(206), UINT8_C(163), UINT8_C(145), UINT8_C( 69),
        UINT8_C(146), UINT8_C(175), UINT8_C( 89), UINT8_C(133), UINT8_C(188),    UINT8_MAX, UINT8_C(254), UINT8_C( 67) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 28), UINT8_C(  5), UINT8_C(232), UINT8_C(124), UINT8_C(171), UINT8_C( 35), UINT8_C(189), UINT8_C(103),
        UINT8_C(105), UINT8_C( 59), UINT8_C( 35), UINT8_C(143), UINT8_C(182), UINT8_C( 95), UINT8_C(137), UINT8_C( 96) },
      { UINT8_C( 28), UINT8_C(  5), UINT8_C(232), UINT8_C(124), UINT8_C(171), UINT8_C( 35), UINT8_C( 85), UINT8_C(103),
        UINT8_C(105), UINT8_C( 59), UINT8_C(247), UINT8_C( 32), UINT8_C(182), UINT8_C( 95), UINT8_C(137), UINT8_C( 96) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vceqq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[16], b_[16];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint8x16_t r = simde_vceqq_u8(simde_vld1q_u8(a_), simde_vld1q_u8(b_));

    simde_test_codegen_write_vu8(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu8(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(44578), UINT16_C(17527), UINT16_C(33032), UINT16_C(22568), UINT16_C(39320), UINT16_C(43487), UINT16_C( 5405), UINT16_C(39565) },
      { UINT16_C(44578), UINT16_C(17527), UINT16_C(33032), UINT16_C(49551), UINT16_C(39320), UINT16_C(33295), UINT16_C(53936), UINT16_C(39565) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(27399), UINT16_C(49584), UINT16_C(15701), UINT16_C(41884), UINT16_C(20596), UINT16_C(45799), UINT16_C( 9582), UINT16_C(11635) },
      { UINT16_C(33552), UINT16_C(49584), UINT16_C(15701), UINT16_C(25947), UINT16_C(20596), UINT16_C(39065), UINT16_C( 9582), UINT16_C(30039) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(39753), UINT16_C(56856), UINT16_C(35858), UINT16_C( 8716), UINT16_C(48143), UINT16_C(25827), UINT16_C(56130), UINT16_C(35901) },
      { UINT16_C(25231), UINT16_C(64774), UINT16_C(23943), UINT16_C( 6003), UINT16_C( 3100), UINT16_C(55080), UINT16_C(56130), UINT16_C(35901) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(36402), UINT16_C(11349), UINT16_C(11812), UINT16_C(39591), UINT16_C( 4740), UINT16_C(26147), UINT16_C(52872), UINT16_C(47959) },
      { UINT16_C(18649), UINT16_C( 7152), UINT16_C(11812), UINT16_C(39591), UINT16_C( 4740), UINT16_C(26147), UINT16_C(52872), UINT16_C(47959) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(41049), UINT16_C(57919), UINT16_C(30379), UINT16_C(33847), UINT16_C(10175), UINT16_C( 3828), UINT16_C(31237), UINT16_C( 9819) },
      { UINT16_C(41049), UINT16_C(57919), UINT16_C(38510), UINT16_C(52125), UINT16_C(33859), UINT16_C( 3828), UINT16_C(31237), UINT16_C( 9819) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 5837), UINT16_C(54009), UINT16_C(21648), UINT16_C(51921), UINT16_C( 4584), UINT16_C(12013), UINT16_C(18855), UINT16_C(59937) },
      { UINT16_C( 5837), UINT16_C(54009), UINT16_C(21648), UINT16_C(59896), UINT16_C(15366), UINT16_C(12013), UINT16_C(30391), UINT16_C(22805) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(  930), UINT16_C(22855), UINT16_C(34511), UINT16_C(40134), UINT16_C(49052), UINT16_C(11374), UINT16_C(26131), UINT16_C( 6421) },
      { UINT16_C(  930), UINT16_C(22855), UINT16_C(23673), UINT16_C( 6578), UINT16_C( 1083), UINT16_C(25129), UINT16_C(  807), UINT16_C(23408) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(63865), UINT16_C(41002), UINT16_C(39676), UINT16_C(34299), UINT16_C(12349), UINT16_C(52445), UINT16_C(53550), UINT16_C(60100) },
      { UINT16_C(63865), UINT16_C(41002), UINT16_C(39676), UINT16_C(34299), UINT16_C(12912), UINT16_C(52445), UINT16_C(53550), UINT16_C(60100) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vceqq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[8], b_[8];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint16x8_t r = simde_vceqq_u16(simde_vld1q_u16(a_), simde_vld1q_u16(b_));

    simde_test_codegen_write_vu16(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu16(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3263161029), UINT32_C( 101765053), UINT32_C(1816709255), UINT32_C(3169297405) },
      { UINT32_C(3263161029), UINT32_C(  27782043), UINT32_C(2243996519), UINT32_C(3169297405) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2907166278), UINT32_C(2117207937), UINT32_C(1826343079), UINT32_C(3235830277) },
      { UINT32_C(2907166278), UINT32_C(2117207937), UINT32_C(1698306474), UINT32_C(3235830277) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3422007588), UINT32_C( 607638393), UINT32_C(1953130030), UINT32_C(3173101884) },
      { UINT32_C(1648055224), UINT32_C(1908962924), UINT32_C(3677464144), UINT32_C( 685716228) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3615632297), UINT32_C(3444305297), UINT32_C(1468689566), UINT32_C(3343075357) },
      { UINT32_C(2359066940), UINT32_C( 745065768), UINT32_C(3847505665), UINT32_C(3343075357) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1372842675), UINT32_C(3096611995), UINT32_C(1598120483), UINT32_C( 200072931) },
      { UINT32_C(2889307307), UINT32_C(3096611995), UINT32_C(1216337364), UINT32_C(1313742491) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2725529726), UINT32_C(4017755219), UINT32_C( 977127474), UINT32_C(3706507585) },
      { UINT32_C( 831880797), UINT32_C(4017755219), UINT32_C( 977127474), UINT32_C(1738137065) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1465781187), UINT32_C(2184020377), UINT32_C( 639009737), UINT32_C(2538992595) },
      { UINT32_C(4064530880), UINT32_C(2184020377), UINT32_C(2229978718), UINT32_C(2538992595) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2178929186), UINT32_C(1812318616), UINT32_C(3009344243), UINT32_C(3115512078) },
      { UINT32_C(2178929186), UINT32_C(1812318616), UINT32_C(3137559229), UINT32_C(3115512078) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vceqq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[4], b_[4];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint32x4_t r = simde_vceqq_u32(simde_vld1q_u32(a_), simde_vld1q_u32(b_));

    simde_test_codegen_write_vu32(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu32(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 5192497038293950529), UINT64_C( 8988655146390972230) },
      { UINT64_C( 7654138344029671543), UINT64_C( 8988655146390972230) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(18144684993376973743), UINT64_C(11614340388918583195) },
      { UINT64_C(18144684993376973743), UINT64_C(11129125334456797487) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 3127155335287534526), UINT64_C(16538076718182468773) },
      { UINT64_C(15278101899158077231), UINT64_C(16538076718182468773) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(17870817187791419502), UINT64_C( 8595970968818886908) },
      { UINT64_C(17870817187791419502), UINT64_C( 8595970968818886908) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(15626440220401441863), UINT64_C(11761352064860019587) },
      { UINT64_C(14003244560131081260), UINT64_C( 2326113439418180100) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(13483908073591550313), UINT64_C(13996729257435331014) },
      { UINT64_C(13483908073591550313), UINT64_C(13996729257435331014) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(  966342067865953351), UINT64_C(12496042449812497273) },
      { UINT64_C(16683983017028644208), UINT64_C(12496042449812497273) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(10354616983512965509), UINT64_C( 1816336881116977332) },
      { UINT64_C(10354616983512965509), UINT64_C( 1816336881116977332) },
      {                    UINT64_MAX,                    UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vceqq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[2], b_[2];
    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++) {
      if (simde_test_codegen_random_i8() & 1) {
        a_[j] = b_[j];
      }
    }
    simde_uint64x2_t r = simde_vceqq_u64(simde_vld1q_u64(a_), simde_vld1q_u64(b_));

    simde_test_codegen_write_vu64(2, sizeof(a_) / sizeof(a_[0]), a_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vu64(2, sizeof(b_) / sizeof(b_[0]), b_, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vceqs_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vceq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
