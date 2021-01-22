#define SIMDE_TEST_ARM_NEON_INSN ext

#include "test-neon.h"
#include "../../../simde/arm/neon/ext.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vext_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    int n;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -687.45), SIMDE_FLOAT32_C(   362.88) },
      { SIMDE_FLOAT32_C(   244.11), SIMDE_FLOAT32_C(   675.58) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -687.45), SIMDE_FLOAT32_C(   362.88) } },
    { { SIMDE_FLOAT32_C(   707.43), SIMDE_FLOAT32_C(   -78.71) },
      { SIMDE_FLOAT32_C(   610.46), SIMDE_FLOAT32_C(  -912.57) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(   -78.71), SIMDE_FLOAT32_C(   610.46) } },
    { { SIMDE_FLOAT32_C(   754.89), SIMDE_FLOAT32_C(   993.62) },
      { SIMDE_FLOAT32_C(  -570.81), SIMDE_FLOAT32_C(  -534.46) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   754.89), SIMDE_FLOAT32_C(   993.62) } },
    { { SIMDE_FLOAT32_C(  -147.63), SIMDE_FLOAT32_C(  -385.01) },
      { SIMDE_FLOAT32_C(   570.33), SIMDE_FLOAT32_C(  -977.64) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(  -385.01), SIMDE_FLOAT32_C(   570.33) } },
    { { SIMDE_FLOAT32_C(  -414.19), SIMDE_FLOAT32_C(  -824.34) },
      { SIMDE_FLOAT32_C(  -892.91), SIMDE_FLOAT32_C(  -280.78) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -414.19), SIMDE_FLOAT32_C(  -824.34) } },
    { { SIMDE_FLOAT32_C(  -659.90), SIMDE_FLOAT32_C(   892.24) },
      { SIMDE_FLOAT32_C(  -796.45), SIMDE_FLOAT32_C(  -383.54) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(   892.24), SIMDE_FLOAT32_C(  -796.45) } },
    { { SIMDE_FLOAT32_C(   -29.63), SIMDE_FLOAT32_C(  -636.99) },
      { SIMDE_FLOAT32_C(   -37.62), SIMDE_FLOAT32_C(   -62.96) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   -29.63), SIMDE_FLOAT32_C(  -636.99) } },
    { { SIMDE_FLOAT32_C(  -107.40), SIMDE_FLOAT32_C(   234.54) },
      { SIMDE_FLOAT32_C(   866.55), SIMDE_FLOAT32_C(   205.15) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(   234.54), SIMDE_FLOAT32_C(   866.55) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    int n = test_vec[i].n;
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vext_f32, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vext_f32(a, b, lanes[i]);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -680.82) },
      { SIMDE_FLOAT64_C(    28.23) },
      { SIMDE_FLOAT64_C(  -680.82) } },
    { { SIMDE_FLOAT64_C(   422.94) },
      { SIMDE_FLOAT64_C(  -433.13) },
      { SIMDE_FLOAT64_C(   422.94) } },
    { { SIMDE_FLOAT64_C(  -224.72) },
      { SIMDE_FLOAT64_C(  -962.86) },
      { SIMDE_FLOAT64_C(  -224.72) } },
    { { SIMDE_FLOAT64_C(   366.48) },
      { SIMDE_FLOAT64_C(  -406.43) },
      { SIMDE_FLOAT64_C(   366.48) } },
    { { SIMDE_FLOAT64_C(   712.41) },
      { SIMDE_FLOAT64_C(   528.86) },
      { SIMDE_FLOAT64_C(   712.41) } },
    { { SIMDE_FLOAT64_C(   609.88) },
      { SIMDE_FLOAT64_C(  -935.77) },
      { SIMDE_FLOAT64_C(   609.88) } },
    { { SIMDE_FLOAT64_C(   202.19) },
      { SIMDE_FLOAT64_C(   313.38) },
      { SIMDE_FLOAT64_C(   202.19) } },
    { { SIMDE_FLOAT64_C(  -424.80) },
      { SIMDE_FLOAT64_C(   680.39) },
      { SIMDE_FLOAT64_C(  -424.80) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vext_f64(a, b, 0);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vext_f64(a, b, 0);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, n, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int n;
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  97), -INT8_C(  53), -INT8_C(  60),  INT8_C(  90),      INT8_MIN, -INT8_C( 105),  INT8_C(  27), -INT8_C(  34) },
      { -INT8_C(  25), -INT8_C(  82), -INT8_C(  56),  INT8_C(  95), -INT8_C(  75),  INT8_C(   9), -INT8_C(   5), -INT8_C( 102) },
       INT32_C(           0),
      { -INT8_C(  97), -INT8_C(  53), -INT8_C(  60),  INT8_C(  90),      INT8_MIN, -INT8_C( 105),  INT8_C(  27), -INT8_C(  34) } },
    { {  INT8_C(  76),  INT8_C( 122), -INT8_C(  21), -INT8_C(  77), -INT8_C(  52),  INT8_C(  88), -INT8_C( 109), -INT8_C(  51) },
      { -INT8_C(  91),  INT8_C(  82), -INT8_C(  77), -INT8_C(  45),  INT8_C(  24), -INT8_C(  52), -INT8_C(  41), -INT8_C(  73) },
       INT32_C(           1),
      {  INT8_C( 122), -INT8_C(  21), -INT8_C(  77), -INT8_C(  52),  INT8_C(  88), -INT8_C( 109), -INT8_C(  51), -INT8_C(  91) } },
    { { -INT8_C( 104), -INT8_C( 101),  INT8_C(  17),  INT8_C(  24),  INT8_C(  50),  INT8_C(  44), -INT8_C(  10),  INT8_C(  25) },
      { -INT8_C(  37), -INT8_C(  66),  INT8_C( 121), -INT8_C( 112), -INT8_C(  57),  INT8_C( 116),  INT8_C(  42),  INT8_C(  19) },
       INT32_C(           2),
      {  INT8_C(  17),  INT8_C(  24),  INT8_C(  50),  INT8_C(  44), -INT8_C(  10),  INT8_C(  25), -INT8_C(  37), -INT8_C(  66) } },
    { { -INT8_C(  18),  INT8_C(  22), -INT8_C(  58), -INT8_C(  69),  INT8_C( 110),  INT8_C(  90), -INT8_C( 120),  INT8_C(  20) },
      { -INT8_C(  84),  INT8_C(  59), -INT8_C(  25), -INT8_C(  60),  INT8_C(   8), -INT8_C(  66),  INT8_C( 123), -INT8_C(  96) },
       INT32_C(           3),
      { -INT8_C(  69),  INT8_C( 110),  INT8_C(  90), -INT8_C( 120),  INT8_C(  20), -INT8_C(  84),  INT8_C(  59), -INT8_C(  25) } },
    { {  INT8_C(  90), -INT8_C( 116), -INT8_C(  72), -INT8_C( 116), -INT8_C(  72), -INT8_C(  82), -INT8_C(  90), -INT8_C( 109) },
      {  INT8_C( 108),  INT8_C(  31),  INT8_C(  35),  INT8_C(  52), -INT8_C( 109),  INT8_C(  78),  INT8_C(  71), -INT8_C( 126) },
       INT32_C(           4),
      { -INT8_C(  72), -INT8_C(  82), -INT8_C(  90), -INT8_C( 109),  INT8_C( 108),  INT8_C(  31),  INT8_C(  35),  INT8_C(  52) } },
    { {  INT8_C( 100),  INT8_C(  14),  INT8_C(  61), -INT8_C(  46),  INT8_C( 104), -INT8_C(  59), -INT8_C(  26),  INT8_C(  20) },
      {  INT8_C(   0), -INT8_C(  50), -INT8_C(  40),  INT8_C(   8), -INT8_C( 116),  INT8_C(  83), -INT8_C(  88), -INT8_C(  26) },
       INT32_C(           5),
      { -INT8_C(  59), -INT8_C(  26),  INT8_C(  20),  INT8_C(   0), -INT8_C(  50), -INT8_C(  40),  INT8_C(   8), -INT8_C( 116) } },
    { { -INT8_C(  33),  INT8_C(  96),  INT8_C( 115), -INT8_C( 105),  INT8_C(  14),  INT8_C(  25),  INT8_C(  43),  INT8_C( 123) },
      {  INT8_C(  56),  INT8_C(  78), -INT8_C(  81), -INT8_C(  53), -INT8_C( 100), -INT8_C(  10),  INT8_C(  77),  INT8_C(   0) },
       INT32_C(           6),
      {  INT8_C(  43),  INT8_C( 123),  INT8_C(  56),  INT8_C(  78), -INT8_C(  81), -INT8_C(  53), -INT8_C( 100), -INT8_C(  10) } },
    { {  INT8_C(   4), -INT8_C( 118), -INT8_C(  45),  INT8_C( 108),  INT8_C(  79), -INT8_C(  71),      INT8_MIN,  INT8_C(  80) },
      { -INT8_C( 121),  INT8_C(  88),  INT8_C(  88),  INT8_C(  20), -INT8_C(  85),  INT8_C(   1), -INT8_C(   6), -INT8_C( 118) },
       INT32_C(           7),
      {  INT8_C(  80), -INT8_C( 121),  INT8_C(  88),  INT8_C(  88),  INT8_C(  20), -INT8_C(  85),  INT8_C(   1), -INT8_C(   6) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vext_s8, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vext_s8(a, b, lanes[i]);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int n;
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 30207), -INT16_C(  2757),  INT16_C( 19340), -INT16_C( 16644) },
      { -INT16_C( 30278),  INT16_C( 18083),  INT16_C(  5855), -INT16_C( 26433) },
       INT32_C(           0),
      {  INT16_C( 30207), -INT16_C(  2757),  INT16_C( 19340), -INT16_C( 16644) } },
    { { -INT16_C( 11351), -INT16_C(   407), -INT16_C( 17343), -INT16_C(  8726) },
      {  INT16_C( 11508), -INT16_C(  2305),  INT16_C(  3599),  INT16_C(  3665) },
       INT32_C(           1),
      { -INT16_C(   407), -INT16_C( 17343), -INT16_C(  8726),  INT16_C( 11508) } },
    { { -INT16_C( 29565),  INT16_C(  3843), -INT16_C(    41), -INT16_C( 28210) },
      {  INT16_C( 29065),  INT16_C( 26839), -INT16_C( 27000),  INT16_C( 12544) },
       INT32_C(           2),
      { -INT16_C(    41), -INT16_C( 28210),  INT16_C( 29065),  INT16_C( 26839) } },
    { {  INT16_C( 26985), -INT16_C( 21712),  INT16_C(  6694),  INT16_C(  6792) },
      { -INT16_C( 30906),  INT16_C( 22032),  INT16_C( 24981),  INT16_C(  6244) },
       INT32_C(           3),
      {  INT16_C(  6792), -INT16_C( 30906),  INT16_C( 22032),  INT16_C( 24981) } },
    { {  INT16_C( 26861), -INT16_C( 15064), -INT16_C(  2457), -INT16_C(  4010) },
      {  INT16_C( 11879), -INT16_C(  4263),  INT16_C( 22980),  INT16_C( 11809) },
       INT32_C(           0),
      {  INT16_C( 26861), -INT16_C( 15064), -INT16_C(  2457), -INT16_C(  4010) } },
    { {  INT16_C( 20931), -INT16_C(  5671),  INT16_C( 24939), -INT16_C( 19965) },
      {  INT16_C(  5352),  INT16_C( 32264),  INT16_C( 27765),  INT16_C( 25494) },
       INT32_C(           1),
      { -INT16_C(  5671),  INT16_C( 24939), -INT16_C( 19965),  INT16_C(  5352) } },
    { { -INT16_C( 16684),  INT16_C( 15400),  INT16_C( 32436),  INT16_C(  7212) },
      { -INT16_C( 31316),  INT16_C( 28939),  INT16_C( 11487), -INT16_C( 23905) },
       INT32_C(           2),
      {  INT16_C( 32436),  INT16_C(  7212), -INT16_C( 31316),  INT16_C( 28939) } },
    { {  INT16_C( 30845), -INT16_C(  5749), -INT16_C( 28967), -INT16_C( 15973) },
      { -INT16_C( 23646),  INT16_C(  6207), -INT16_C( 10737), -INT16_C(  7045) },
       INT32_C(           3),
      { -INT16_C( 15973), -INT16_C( 23646),  INT16_C(  6207), -INT16_C( 10737) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vext_s16, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vext_s16(a, b, lanes[i]);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int n;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   957350431), -INT32_C(   603021787) },
      { -INT32_C(  1074644418),  INT32_C(   794553918) },
       INT32_C(           0),
      {  INT32_C(   957350431), -INT32_C(   603021787) } },
    { {  INT32_C(   443957338), -INT32_C(  1718071061) },
      {  INT32_C(  1279020983), -INT32_C(  1469355383) },
       INT32_C(           1),
      { -INT32_C(  1718071061),  INT32_C(  1279020983) } },
    { { -INT32_C(  1847493524),  INT32_C(  1483599898) },
      {  INT32_C(  1746362154), -INT32_C(  1483181491) },
       INT32_C(           0),
      { -INT32_C(  1847493524),  INT32_C(  1483599898) } },
    { { -INT32_C(  1631449422),  INT32_C(   372726367) },
      {  INT32_C(   862090154),  INT32_C(  1239207389) },
       INT32_C(           1),
      {  INT32_C(   372726367),  INT32_C(   862090154) } },
    { {  INT32_C(  1675279689), -INT32_C(   675526739) },
      { -INT32_C(   197078105), -INT32_C(   123938746) },
       INT32_C(           0),
      {  INT32_C(  1675279689), -INT32_C(   675526739) } },
    { {  INT32_C(  1167482598),  INT32_C(  1650183608) },
      {  INT32_C(   513195329), -INT32_C(   731352437) },
       INT32_C(           1),
      {  INT32_C(  1650183608),  INT32_C(   513195329) } },
    { { -INT32_C(   583515601),  INT32_C(   833942666) },
      {  INT32_C(   220591303), -INT32_C(  1291402804) },
       INT32_C(           0),
      { -INT32_C(   583515601),  INT32_C(   833942666) } },
    { { -INT32_C(   654795745), -INT32_C(  1422240662) },
      { -INT32_C(  1664495599),  INT32_C(  1920020802) },
       INT32_C(           1),
      { -INT32_C(  1422240662), -INT32_C(  1664495599) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vext_s32, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vext_s32(a, b, lanes[i]);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 6639490098744952062) },
      { -INT64_C(  906714779595733515) },
      {  INT64_C( 6639490098744952062) } },
    { { -INT64_C( 1175976699607320186) },
      {  INT64_C( 8022877348809296326) },
      { -INT64_C( 1175976699607320186) } },
    { { -INT64_C( 1373935476923645568) },
      { -INT64_C( 4541150998765402287) },
      { -INT64_C( 1373935476923645568) } },
    { { -INT64_C( 7139179752814035311) },
      { -INT64_C( 5281588533336655149) },
      { -INT64_C( 7139179752814035311) } },
    { {  INT64_C( 8839218246575480008) },
      {  INT64_C(  123985814383417533) },
      {  INT64_C( 8839218246575480008) } },
    { { -INT64_C( 1103968923059055813) },
      {  INT64_C( 3319971401639943717) },
      { -INT64_C( 1103968923059055813) } },
    { {  INT64_C( 5613904681621084741) },
      {  INT64_C( 2513849614873160305) },
      {  INT64_C( 5613904681621084741) } },
    { { -INT64_C( 1180540366207328112) },
      { -INT64_C(   12563317733469889) },
      { -INT64_C( 1180540366207328112) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vext_s64(a, b, 0);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vext_s64(a, b, 0);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, 0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    int n;
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 41), UINT8_C(252), UINT8_C( 40), UINT8_C( 64), UINT8_C(135), UINT8_C(135), UINT8_C(244), UINT8_C(115) },
      { UINT8_C(156), UINT8_C(144), UINT8_C( 83), UINT8_C(200), UINT8_C(190), UINT8_C( 18), UINT8_C(166), UINT8_C(155) },
       INT32_C(           0),
      { UINT8_C( 41), UINT8_C(252), UINT8_C( 40), UINT8_C( 64), UINT8_C(135), UINT8_C(135), UINT8_C(244), UINT8_C(115) } },
    { { UINT8_C(  9), UINT8_C(208), UINT8_C(167), UINT8_C( 64), UINT8_C(179), UINT8_C( 73), UINT8_C(177), UINT8_C(189) },
      { UINT8_C(152), UINT8_C( 56), UINT8_C(227), UINT8_C(221), UINT8_C(232), UINT8_C(138), UINT8_C(102), UINT8_C( 17) },
       INT32_C(           1),
      { UINT8_C(208), UINT8_C(167), UINT8_C( 64), UINT8_C(179), UINT8_C( 73), UINT8_C(177), UINT8_C(189), UINT8_C(152) } },
    { { UINT8_C(135), UINT8_C(142), UINT8_C( 81), UINT8_C( 14), UINT8_C( 21), UINT8_C( 70), UINT8_C(129), UINT8_C(177) },
      { UINT8_C(214), UINT8_C(212), UINT8_C(122), UINT8_C(148), UINT8_C(230), UINT8_C( 32), UINT8_C( 47), UINT8_C(239) },
       INT32_C(           2),
      { UINT8_C( 81), UINT8_C( 14), UINT8_C( 21), UINT8_C( 70), UINT8_C(129), UINT8_C(177), UINT8_C(214), UINT8_C(212) } },
    { { UINT8_C(241), UINT8_C(215), UINT8_C( 48), UINT8_C(164), UINT8_C( 32), UINT8_C(225), UINT8_C( 98), UINT8_C(184) },
      { UINT8_C( 25), UINT8_C( 69), UINT8_C(149), UINT8_C(  1), UINT8_C(208), UINT8_C(251), UINT8_C( 18), UINT8_C( 87) },
       INT32_C(           3),
      { UINT8_C(164), UINT8_C( 32), UINT8_C(225), UINT8_C( 98), UINT8_C(184), UINT8_C( 25), UINT8_C( 69), UINT8_C(149) } },
    { { UINT8_C(137), UINT8_C(100), UINT8_C(101), UINT8_C(159), UINT8_C(170), UINT8_C(231), UINT8_C( 80), UINT8_C(128) },
      { UINT8_C(187), UINT8_C(202), UINT8_C( 21), UINT8_C(162), UINT8_C(235), UINT8_C( 68), UINT8_C(145), UINT8_C(220) },
       INT32_C(           4),
      { UINT8_C(170), UINT8_C(231), UINT8_C( 80), UINT8_C(128), UINT8_C(187), UINT8_C(202), UINT8_C( 21), UINT8_C(162) } },
    { { UINT8_C( 27), UINT8_C(193), UINT8_C(128), UINT8_C( 60), UINT8_C(163), UINT8_C(226), UINT8_C(244), UINT8_C(188) },
      { UINT8_C( 40), UINT8_C(138), UINT8_C(190), UINT8_C(248), UINT8_C(133), UINT8_C(208), UINT8_C( 79), UINT8_C( 15) },
       INT32_C(           5),
      { UINT8_C(226), UINT8_C(244), UINT8_C(188), UINT8_C( 40), UINT8_C(138), UINT8_C(190), UINT8_C(248), UINT8_C(133) } },
    { { UINT8_C( 52), UINT8_C(180), UINT8_C(174), UINT8_C(222), UINT8_C(155), UINT8_C(254), UINT8_C( 95), UINT8_C( 87) },
      { UINT8_C(201), UINT8_C(116), UINT8_C(249), UINT8_C(180), UINT8_C(184), UINT8_C(138), UINT8_C(144), UINT8_C(212) },
       INT32_C(           6),
      { UINT8_C( 95), UINT8_C( 87), UINT8_C(201), UINT8_C(116), UINT8_C(249), UINT8_C(180), UINT8_C(184), UINT8_C(138) } },
    { { UINT8_C( 76), UINT8_C( 16), UINT8_C( 16), UINT8_C(239), UINT8_C(243), UINT8_C(  4), UINT8_C(171), UINT8_C( 27) },
      { UINT8_C(142), UINT8_C(105), UINT8_C( 19), UINT8_C( 20), UINT8_C( 58), UINT8_C( 98), UINT8_C( 35), UINT8_C(110) },
       INT32_C(           7),
      { UINT8_C( 27), UINT8_C(142), UINT8_C(105), UINT8_C( 19), UINT8_C( 20), UINT8_C( 58), UINT8_C( 98), UINT8_C( 35) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vext_u8, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vext_u8(a, b, lanes[i]);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    int n;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(16781), UINT16_C(   83), UINT16_C(49358), UINT16_C(43895) },
      { UINT16_C(63669), UINT16_C(33927), UINT16_C(10175), UINT16_C(15472) },
       INT32_C(           0),
      { UINT16_C(16781), UINT16_C(   83), UINT16_C(49358), UINT16_C(43895) } },
    { { UINT16_C(10362), UINT16_C(59736), UINT16_C(10921), UINT16_C(40640) },
      { UINT16_C(39613), UINT16_C(56230), UINT16_C(57753), UINT16_C( 9976) },
       INT32_C(           1),
      { UINT16_C(59736), UINT16_C(10921), UINT16_C(40640), UINT16_C(39613) } },
    { { UINT16_C(19490), UINT16_C(61734), UINT16_C(40204), UINT16_C(49564) },
      { UINT16_C( 9109), UINT16_C(21829), UINT16_C(46411), UINT16_C(50577) },
       INT32_C(           2),
      { UINT16_C(40204), UINT16_C(49564), UINT16_C( 9109), UINT16_C(21829) } },
    { { UINT16_C(59869), UINT16_C(34478), UINT16_C(28180), UINT16_C(53540) },
      { UINT16_C(51721), UINT16_C(41644), UINT16_C(42411), UINT16_C(52936) },
       INT32_C(           3),
      { UINT16_C(53540), UINT16_C(51721), UINT16_C(41644), UINT16_C(42411) } },
    { { UINT16_C(61425), UINT16_C(64959), UINT16_C(23436), UINT16_C( 8894) },
      { UINT16_C(  894), UINT16_C(51575), UINT16_C( 2233), UINT16_C(38542) },
       INT32_C(           0),
      { UINT16_C(61425), UINT16_C(64959), UINT16_C(23436), UINT16_C( 8894) } },
    { { UINT16_C(15601), UINT16_C( 1309), UINT16_C(16811), UINT16_C(46294) },
      { UINT16_C(33548), UINT16_C(46934), UINT16_C( 7720), UINT16_C( 6533) },
       INT32_C(           1),
      { UINT16_C( 1309), UINT16_C(16811), UINT16_C(46294), UINT16_C(33548) } },
    { { UINT16_C(17421), UINT16_C(39446), UINT16_C(54431), UINT16_C( 7868) },
      { UINT16_C(13271), UINT16_C(37095), UINT16_C(30267), UINT16_C(11303) },
       INT32_C(           2),
      { UINT16_C(54431), UINT16_C( 7868), UINT16_C(13271), UINT16_C(37095) } },
    { { UINT16_C(17586), UINT16_C(23858), UINT16_C( 2181), UINT16_C(37137) },
      { UINT16_C(26507), UINT16_C(45897), UINT16_C(52870), UINT16_C(37836) },
       INT32_C(           3),
      { UINT16_C(37137), UINT16_C(26507), UINT16_C(45897), UINT16_C(52870) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vext_u16, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vext_u16(a, b, lanes[i]);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    int n;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2921936545), UINT32_C(1836714120) },
      { UINT32_C(3960998402), UINT32_C(1184252007) },
       INT32_C(           0),
      { UINT32_C(2921936545), UINT32_C(1836714120) } },
    { { UINT32_C(1465699894), UINT32_C(1555702821) },
      { UINT32_C( 496622738), UINT32_C(3470628141) },
       INT32_C(           1),
      { UINT32_C(1555702821), UINT32_C( 496622738) } },
    { { UINT32_C(1400702923), UINT32_C( 297858831) },
      { UINT32_C(1778309378), UINT32_C(1336906777) },
       INT32_C(           0),
      { UINT32_C(1400702923), UINT32_C( 297858831) } },
    { { UINT32_C(2275806050), UINT32_C(3269681200) },
      { UINT32_C(1793031485), UINT32_C(3711482898) },
       INT32_C(           1),
      { UINT32_C(3269681200), UINT32_C(1793031485) } },
    { { UINT32_C(3526407619), UINT32_C(2951016877) },
      { UINT32_C(3810058954), UINT32_C(3627206518) },
       INT32_C(           0),
      { UINT32_C(3526407619), UINT32_C(2951016877) } },
    { { UINT32_C(  56678611), UINT32_C(1992639289) },
      { UINT32_C(3537937600), UINT32_C( 615454816) },
       INT32_C(           1),
      { UINT32_C(1992639289), UINT32_C(3537937600) } },
    { { UINT32_C(2079776974), UINT32_C(2603277009) },
      { UINT32_C( 847135420), UINT32_C(3691753481) },
       INT32_C(           0),
      { UINT32_C(2079776974), UINT32_C(2603277009) } },
    { { UINT32_C(3252644744), UINT32_C(1865917614) },
      { UINT32_C(2839615304), UINT32_C(4274909488) },
       INT32_C(           1),
      { UINT32_C(1865917614), UINT32_C(2839615304) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vext_u32, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vext_u32(a, b, lanes[i]);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vext_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 4775218924999393801) },
      { UINT64_C(14341243545373652668) },
      { UINT64_C( 4775218924999393801) } },
    { { UINT64_C( 9139095911556337710) },
      { UINT64_C( 1794718599694819428) },
      { UINT64_C( 9139095911556337710) } },
    { { UINT64_C(17254207385035945953) },
      { UINT64_C( 6000040611349516152) },
      { UINT64_C(17254207385035945953) } },
    { { UINT64_C(14523168050340220606) },
      { UINT64_C( 2697498136351876169) },
      { UINT64_C(14523168050340220606) } },
    { { UINT64_C( 2867607344887786920) },
      { UINT64_C( 6706397092927255193) },
      { UINT64_C( 2867607344887786920) } },
    { { UINT64_C(15556831202562008502) },
      { UINT64_C( 9620707902598573083) },
      { UINT64_C(15556831202562008502) } },
    { { UINT64_C( 4386835494242146571) },
      { UINT64_C( 2547361106271831389) },
      { UINT64_C( 4386835494242146571) } },
    { { UINT64_C(15516627759135639025) },
      { UINT64_C( 3310630758589564047) },
      { UINT64_C(15516627759135639025) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vext_u64(a, b, 0);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_vext_u64(a, b, 0);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, 0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    int n;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -11.82), SIMDE_FLOAT32_C(  -542.24), SIMDE_FLOAT32_C(   904.95), SIMDE_FLOAT32_C(   599.34) },
      { SIMDE_FLOAT32_C(  -323.53), SIMDE_FLOAT32_C(   591.26), SIMDE_FLOAT32_C(  -753.72), SIMDE_FLOAT32_C(    19.62) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   -11.82), SIMDE_FLOAT32_C(  -542.24), SIMDE_FLOAT32_C(   904.95), SIMDE_FLOAT32_C(   599.34) } },
    { { SIMDE_FLOAT32_C(  -246.51), SIMDE_FLOAT32_C(  -600.23), SIMDE_FLOAT32_C(  -164.99), SIMDE_FLOAT32_C(  -616.01) },
      { SIMDE_FLOAT32_C(  -788.95), SIMDE_FLOAT32_C(  -648.59), SIMDE_FLOAT32_C(   630.30), SIMDE_FLOAT32_C(   886.86) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(  -600.23), SIMDE_FLOAT32_C(  -164.99), SIMDE_FLOAT32_C(  -616.01), SIMDE_FLOAT32_C(  -788.95) } },
    { { SIMDE_FLOAT32_C(   -83.54), SIMDE_FLOAT32_C(  -412.91), SIMDE_FLOAT32_C(   -86.28), SIMDE_FLOAT32_C(   790.95) },
      { SIMDE_FLOAT32_C(   194.71), SIMDE_FLOAT32_C(  -239.80), SIMDE_FLOAT32_C(  -880.77), SIMDE_FLOAT32_C(  -974.84) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   -86.28), SIMDE_FLOAT32_C(   790.95), SIMDE_FLOAT32_C(   194.71), SIMDE_FLOAT32_C(  -239.80) } },
    { { SIMDE_FLOAT32_C(   572.07), SIMDE_FLOAT32_C(   171.25), SIMDE_FLOAT32_C(   700.50), SIMDE_FLOAT32_C(  -266.41) },
      { SIMDE_FLOAT32_C(   107.61), SIMDE_FLOAT32_C(  -395.18), SIMDE_FLOAT32_C(  -409.82), SIMDE_FLOAT32_C(  -904.21) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(  -266.41), SIMDE_FLOAT32_C(   107.61), SIMDE_FLOAT32_C(  -395.18), SIMDE_FLOAT32_C(  -409.82) } },
    { { SIMDE_FLOAT32_C(    62.58), SIMDE_FLOAT32_C(  -504.88), SIMDE_FLOAT32_C(   695.13), SIMDE_FLOAT32_C(   739.05) },
      { SIMDE_FLOAT32_C(  -913.62), SIMDE_FLOAT32_C(   941.41), SIMDE_FLOAT32_C(  -241.33), SIMDE_FLOAT32_C(  -160.12) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(    62.58), SIMDE_FLOAT32_C(  -504.88), SIMDE_FLOAT32_C(   695.13), SIMDE_FLOAT32_C(   739.05) } },
    { { SIMDE_FLOAT32_C(  -658.83), SIMDE_FLOAT32_C(   593.68), SIMDE_FLOAT32_C(   223.86), SIMDE_FLOAT32_C(  -447.78) },
      { SIMDE_FLOAT32_C(   945.09), SIMDE_FLOAT32_C(  -145.84), SIMDE_FLOAT32_C(  -560.91), SIMDE_FLOAT32_C(  -138.45) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(   593.68), SIMDE_FLOAT32_C(   223.86), SIMDE_FLOAT32_C(  -447.78), SIMDE_FLOAT32_C(   945.09) } },
    { { SIMDE_FLOAT32_C(   441.26), SIMDE_FLOAT32_C(   352.81), SIMDE_FLOAT32_C(  -347.49), SIMDE_FLOAT32_C(  -364.04) },
      { SIMDE_FLOAT32_C(  -887.00), SIMDE_FLOAT32_C(  -228.26), SIMDE_FLOAT32_C(  -338.88), SIMDE_FLOAT32_C(   685.07) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(  -347.49), SIMDE_FLOAT32_C(  -364.04), SIMDE_FLOAT32_C(  -887.00), SIMDE_FLOAT32_C(  -228.26) } },
    { { SIMDE_FLOAT32_C(   942.99), SIMDE_FLOAT32_C(  -638.38), SIMDE_FLOAT32_C(  -581.34), SIMDE_FLOAT32_C(    50.60) },
      { SIMDE_FLOAT32_C(   -33.56), SIMDE_FLOAT32_C(     8.84), SIMDE_FLOAT32_C(   146.38), SIMDE_FLOAT32_C(  -970.98) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(    50.60), SIMDE_FLOAT32_C(   -33.56), SIMDE_FLOAT32_C(     8.84), SIMDE_FLOAT32_C(   146.38) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    int n = test_vec[i].n;
    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vextq_f32, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3, };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vextq_f32(a, b, lanes[i]);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    int n;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   223.42), SIMDE_FLOAT64_C(  -836.30) },
      { SIMDE_FLOAT64_C(  -552.33), SIMDE_FLOAT64_C(   -75.69) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   223.42), SIMDE_FLOAT64_C(  -836.30) } },
    { { SIMDE_FLOAT64_C(   756.82), SIMDE_FLOAT64_C(  -550.05) },
      { SIMDE_FLOAT64_C(   687.41), SIMDE_FLOAT64_C(   804.17) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   756.82), SIMDE_FLOAT64_C(  -550.05) } },
    { { SIMDE_FLOAT64_C(  -230.29), SIMDE_FLOAT64_C(  -327.40) },
      { SIMDE_FLOAT64_C(   614.24), SIMDE_FLOAT64_C(  -107.90) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(  -230.29), SIMDE_FLOAT64_C(  -327.40) } },
    { { SIMDE_FLOAT64_C(  -177.24), SIMDE_FLOAT64_C(  -842.50) },
      { SIMDE_FLOAT64_C(   773.97), SIMDE_FLOAT64_C(   644.31) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(  -177.24), SIMDE_FLOAT64_C(  -842.50) } },
    { { SIMDE_FLOAT64_C(  -485.54), SIMDE_FLOAT64_C(  -253.40) },
      { SIMDE_FLOAT64_C(  -930.32), SIMDE_FLOAT64_C(   677.29) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(  -485.54), SIMDE_FLOAT64_C(  -253.40) } },
    { { SIMDE_FLOAT64_C(   819.98), SIMDE_FLOAT64_C(   883.30) },
      { SIMDE_FLOAT64_C(  -760.51), SIMDE_FLOAT64_C(   669.54) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   819.98), SIMDE_FLOAT64_C(   883.30) } },
    { { SIMDE_FLOAT64_C(  -349.64), SIMDE_FLOAT64_C(   465.41) },
      { SIMDE_FLOAT64_C(  -828.45), SIMDE_FLOAT64_C(  -240.64) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(  -349.64), SIMDE_FLOAT64_C(   465.41) } },
    { { SIMDE_FLOAT64_C(  -629.75), SIMDE_FLOAT64_C(   891.13) },
      { SIMDE_FLOAT64_C(  -550.52), SIMDE_FLOAT64_C(   593.67) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(  -629.75), SIMDE_FLOAT64_C(   891.13) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    int n = test_vec[i].n;
    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vextq_f64, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vextq_f64(a, b, 0);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, 0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int n;
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  97), -INT8_C(   4), -INT8_C(  92),  INT8_C(  56),  INT8_C(  19),  INT8_C(  14), -INT8_C(  53),  INT8_C(  19),
         INT8_C( 106),  INT8_C(  24), -INT8_C(  46), -INT8_C(  86), -INT8_C( 103),  INT8_C( 115),  INT8_C(  96), -INT8_C(  67) },
      { -INT8_C(  10), -INT8_C(   2),  INT8_C(  82),  INT8_C(  65), -INT8_C(  30),  INT8_C(  34),  INT8_C(  93), -INT8_C(  78),
        -INT8_C(  68), -INT8_C(  13), -INT8_C(  43),  INT8_C(  71), -INT8_C(  27), -INT8_C(   5),  INT8_C(  39), -INT8_C( 123) },
       INT32_C(           2),
      { -INT8_C(  92),  INT8_C(  56),  INT8_C(  19),  INT8_C(  14), -INT8_C(  53),  INT8_C(  19),  INT8_C( 106),  INT8_C(  24),
        -INT8_C(  46), -INT8_C(  86), -INT8_C( 103),  INT8_C( 115),  INT8_C(  96), -INT8_C(  67), -INT8_C(  10), -INT8_C(   2) } },
    { { -INT8_C(   9), -INT8_C(  53), -INT8_C(  67),  INT8_C(  10), -INT8_C(  39), -INT8_C( 120),  INT8_C(  30),  INT8_C(  67),
        -INT8_C(  96), -INT8_C(  16), -INT8_C(  19),  INT8_C(  57),  INT8_C(  99),  INT8_C(  77), -INT8_C(   9),  INT8_C(  90) },
      {  INT8_C(  75),  INT8_C(  73), -INT8_C( 101),  INT8_C(  46),  INT8_C( 107), -INT8_C(   8), -INT8_C(  32),  INT8_C(  39),
        -INT8_C(  20), -INT8_C(  75),  INT8_C( 110), -INT8_C(  47), -INT8_C(  79), -INT8_C( 107),  INT8_C(  86), -INT8_C(  88) },
       INT32_C(           4),
      { -INT8_C(  39), -INT8_C( 120),  INT8_C(  30),  INT8_C(  67), -INT8_C(  96), -INT8_C(  16), -INT8_C(  19),  INT8_C(  57),
         INT8_C(  99),  INT8_C(  77), -INT8_C(   9),  INT8_C(  90),  INT8_C(  75),  INT8_C(  73), -INT8_C( 101),  INT8_C(  46) } },
    { {  INT8_C(  96),  INT8_C(  20), -INT8_C(  77),  INT8_C(  57), -INT8_C( 100), -INT8_C(  47),  INT8_C( 125),  INT8_C(  61),
        -INT8_C(  63),  INT8_C( 106),  INT8_C( 118),  INT8_C(  36), -INT8_C(  72),  INT8_C( 109),  INT8_C( 126),  INT8_C(   3) },
      { -INT8_C(  73),  INT8_C(  25),  INT8_C(  49),  INT8_C(  34),  INT8_C(  18),  INT8_C(  17),  INT8_C(  74), -INT8_C(   2),
        -INT8_C(  57), -INT8_C(  72), -INT8_C(  49),  INT8_C( 120),  INT8_C(  78),  INT8_C(  38),  INT8_C(  32), -INT8_C(  82) },
       INT32_C(           6),
      {  INT8_C( 125),  INT8_C(  61), -INT8_C(  63),  INT8_C( 106),  INT8_C( 118),  INT8_C(  36), -INT8_C(  72),  INT8_C( 109),
         INT8_C( 126),  INT8_C(   3), -INT8_C(  73),  INT8_C(  25),  INT8_C(  49),  INT8_C(  34),  INT8_C(  18),  INT8_C(  17) } },
    { {  INT8_C(  58), -INT8_C(  45), -INT8_C(  24), -INT8_C(  42), -INT8_C(  92),  INT8_C( 101),  INT8_C(  19),  INT8_C( 101),
        -INT8_C(  49), -INT8_C( 118), -INT8_C( 118), -INT8_C( 121), -INT8_C(   9),  INT8_C(   8), -INT8_C( 117), -INT8_C(  82) },
      {  INT8_C(  34), -INT8_C(  68), -INT8_C(  47),  INT8_C(  52), -INT8_C(  50),  INT8_C(  27),  INT8_C(  50), -INT8_C( 107),
        -INT8_C(  45),  INT8_C(   1),  INT8_C(  13),  INT8_C(  33),  INT8_C(  39),  INT8_C(  45), -INT8_C(  48),  INT8_C(  97) },
       INT32_C(           8),
      { -INT8_C(  49), -INT8_C( 118), -INT8_C( 118), -INT8_C( 121), -INT8_C(   9),  INT8_C(   8), -INT8_C( 117), -INT8_C(  82),
         INT8_C(  34), -INT8_C(  68), -INT8_C(  47),  INT8_C(  52), -INT8_C(  50),  INT8_C(  27),  INT8_C(  50), -INT8_C( 107) } },
    { {  INT8_C(   1), -INT8_C(  72),  INT8_C(  56), -INT8_C(  91),  INT8_C(  29),  INT8_C(  75),  INT8_C(  11), -INT8_C(  20),
        -INT8_C(  43), -INT8_C( 107),  INT8_C( 116), -INT8_C(  51), -INT8_C(  99), -INT8_C(   1),  INT8_C( 123), -INT8_C(  65) },
      { -INT8_C(  69),  INT8_C(  76), -INT8_C(  13), -INT8_C( 119),  INT8_C( 103),  INT8_C(  37),  INT8_C(  30),  INT8_C(  59),
         INT8_C(  39),  INT8_C(  43),  INT8_C(  92),  INT8_C(  78),  INT8_C(  89),  INT8_C(  44), -INT8_C(  80),  INT8_C(  90) },
       INT32_C(          10),
      {  INT8_C( 116), -INT8_C(  51), -INT8_C(  99), -INT8_C(   1),  INT8_C( 123), -INT8_C(  65), -INT8_C(  69),  INT8_C(  76),
        -INT8_C(  13), -INT8_C( 119),  INT8_C( 103),  INT8_C(  37),  INT8_C(  30),  INT8_C(  59),  INT8_C(  39),  INT8_C(  43) } },
    { { -INT8_C(  28), -INT8_C(  24), -INT8_C(   1),  INT8_C(   1),  INT8_C(  51),  INT8_C(  10), -INT8_C(  18),  INT8_C(   9),
        -INT8_C(  97),  INT8_C(  98), -INT8_C(  42),  INT8_C(  61),  INT8_C(  97),  INT8_C(  81), -INT8_C(   4),  INT8_C(  28) },
      { -INT8_C(  98), -INT8_C(  16), -INT8_C(  90),  INT8_C(   5),  INT8_C(  21), -INT8_C(  60),  INT8_C(  64),  INT8_C(  60),
        -INT8_C(  16), -INT8_C(  99), -INT8_C( 117),  INT8_C(  73), -INT8_C(  55),  INT8_C(  59), -INT8_C(  93), -INT8_C(  82) },
       INT32_C(          12),
      {  INT8_C(  97),  INT8_C(  81), -INT8_C(   4),  INT8_C(  28), -INT8_C(  98), -INT8_C(  16), -INT8_C(  90),  INT8_C(   5),
         INT8_C(  21), -INT8_C(  60),  INT8_C(  64),  INT8_C(  60), -INT8_C(  16), -INT8_C(  99), -INT8_C( 117),  INT8_C(  73) } },
    { {  INT8_C(  35), -INT8_C(  94), -INT8_C(  81),  INT8_C(  86), -INT8_C(  83), -INT8_C(  99),  INT8_C(  95),  INT8_C(  76),
        -INT8_C(   1),  INT8_C(  53), -INT8_C( 119),  INT8_C(  96), -INT8_C( 121), -INT8_C( 122),  INT8_C( 125),  INT8_C(  37) },
      {  INT8_C( 118),  INT8_C(  35),  INT8_C(  42), -INT8_C( 117), -INT8_C(  25),  INT8_C( 107), -INT8_C(  56), -INT8_C(  41),
         INT8_C(   8),  INT8_C(  83),  INT8_C(  32), -INT8_C(  47), -INT8_C( 114), -INT8_C(  61),      INT8_MAX, -INT8_C(  79) },
       INT32_C(          14),
      {  INT8_C( 125),  INT8_C(  37),  INT8_C( 118),  INT8_C(  35),  INT8_C(  42), -INT8_C( 117), -INT8_C(  25),  INT8_C( 107),
        -INT8_C(  56), -INT8_C(  41),  INT8_C(   8),  INT8_C(  83),  INT8_C(  32), -INT8_C(  47), -INT8_C( 114), -INT8_C(  61) } },
    { {  INT8_C( 102),  INT8_C(  47),  INT8_C(   7),  INT8_C(  19), -INT8_C(  52),  INT8_C( 103),  INT8_C(  95), -INT8_C(  52),
        -INT8_C( 100), -INT8_C(  23),  INT8_C(  44),  INT8_C(  35),  INT8_C( 111), -INT8_C(  87),  INT8_C(  72), -INT8_C(  27) },
      { -INT8_C(  52),  INT8_C( 115),  INT8_C( 112), -INT8_C(  76), -INT8_C(  34),  INT8_C(  56), -INT8_C( 117), -INT8_C(  26),
        -INT8_C( 117), -INT8_C(  84), -INT8_C(  73),  INT8_C(  25),  INT8_C( 111),  INT8_C(  55), -INT8_C(  54), -INT8_C(  43) },
       INT32_C(          15),
      { -INT8_C(  27), -INT8_C(  52),  INT8_C( 115),  INT8_C( 112), -INT8_C(  76), -INT8_C(  34),  INT8_C(  56), -INT8_C( 117),
        -INT8_C(  26), -INT8_C( 117), -INT8_C(  84), -INT8_C(  73),  INT8_C(  25),  INT8_C( 111),  INT8_C(  55), -INT8_C(  54) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vextq_s8, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 2, 4, 6, 8, 10, 12, 14, 15 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vextq_s8(a, b, lanes[i]);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int n;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  5517),  INT16_C( 11597), -INT16_C( 20136),  INT16_C( 32730), -INT16_C( 15613), -INT16_C( 13999), -INT16_C( 10256), -INT16_C( 12873) },
      {  INT16_C( 23318), -INT16_C( 23493),  INT16_C(  6269), -INT16_C( 11894), -INT16_C( 14678), -INT16_C(   567), -INT16_C( 20668), -INT16_C( 18497) },
       INT32_C(           0),
      { -INT16_C(  5517),  INT16_C( 11597), -INT16_C( 20136),  INT16_C( 32730), -INT16_C( 15613), -INT16_C( 13999), -INT16_C( 10256), -INT16_C( 12873) } },
    { {  INT16_C(  3481), -INT16_C(  3612), -INT16_C( 16706), -INT16_C( 16015), -INT16_C( 15742),  INT16_C( 29322),  INT16_C( 17049), -INT16_C( 20673) },
      {  INT16_C( 31389),  INT16_C(  6739), -INT16_C(  8813),  INT16_C( 15852), -INT16_C( 19037), -INT16_C(  6341), -INT16_C(  1436), -INT16_C(   354) },
       INT32_C(           1),
      { -INT16_C(  3612), -INT16_C( 16706), -INT16_C( 16015), -INT16_C( 15742),  INT16_C( 29322),  INT16_C( 17049), -INT16_C( 20673),  INT16_C( 31389) } },
    { { -INT16_C( 31993), -INT16_C( 14609),  INT16_C( 24641), -INT16_C( 15481),  INT16_C(  4642), -INT16_C( 17611),  INT16_C( 29780), -INT16_C(  3734) },
      { -INT16_C( 16913), -INT16_C( 32244), -INT16_C(  1894),  INT16_C( 15807), -INT16_C(  1363),  INT16_C(  4388), -INT16_C( 15371), -INT16_C(  1009) },
       INT32_C(           2),
      {  INT16_C( 24641), -INT16_C( 15481),  INT16_C(  4642), -INT16_C( 17611),  INT16_C( 29780), -INT16_C(  3734), -INT16_C( 16913), -INT16_C( 32244) } },
    { { -INT16_C(   186), -INT16_C( 30782),  INT16_C( 19039), -INT16_C( 32181), -INT16_C( 32676), -INT16_C( 20419), -INT16_C( 22283), -INT16_C(  7007) },
      { -INT16_C( 21147),  INT16_C(   102),  INT16_C(  9637),  INT16_C( 21053),  INT16_C( 25120),  INT16_C(  5476),  INT16_C( 29477),  INT16_C( 27409) },
       INT32_C(           3),
      { -INT16_C( 32181), -INT16_C( 32676), -INT16_C( 20419), -INT16_C( 22283), -INT16_C(  7007), -INT16_C( 21147),  INT16_C(   102),  INT16_C(  9637) } },
    { { -INT16_C( 11150), -INT16_C( 11534),  INT16_C( 15646),  INT16_C( 31316), -INT16_C( 28226), -INT16_C( 19670), -INT16_C( 13511), -INT16_C( 24681) },
      { -INT16_C(   647),  INT16_C(  7839), -INT16_C(  9182),  INT16_C( 17009), -INT16_C( 10946),  INT16_C( 25431),  INT16_C( 26952), -INT16_C( 17458) },
       INT32_C(           4),
      { -INT16_C( 28226), -INT16_C( 19670), -INT16_C( 13511), -INT16_C( 24681), -INT16_C(   647),  INT16_C(  7839), -INT16_C(  9182),  INT16_C( 17009) } },
    { { -INT16_C( 16067),  INT16_C( 23437), -INT16_C(  7682), -INT16_C( 17195), -INT16_C(   142), -INT16_C( 21393),  INT16_C(  1738),  INT16_C( 17227) },
      { -INT16_C(  5629),  INT16_C(  9826), -INT16_C( 11322),  INT16_C(  1384), -INT16_C( 16216), -INT16_C(  3992),  INT16_C( 14121),  INT16_C( 26283) },
       INT32_C(           5),
      { -INT16_C( 21393),  INT16_C(  1738),  INT16_C( 17227), -INT16_C(  5629),  INT16_C(  9826), -INT16_C( 11322),  INT16_C(  1384), -INT16_C( 16216) } },
    { {  INT16_C( 14584), -INT16_C(  2367), -INT16_C( 27111), -INT16_C( 29517),  INT16_C(  8853),  INT16_C( 24376), -INT16_C( 31959),  INT16_C( 11427) },
      {  INT16_C(  1389),  INT16_C( 13138), -INT16_C( 17448), -INT16_C( 32712), -INT16_C( 24197), -INT16_C( 23440),  INT16_C(  7384), -INT16_C( 12278) },
       INT32_C(           6),
      { -INT16_C( 31959),  INT16_C( 11427),  INT16_C(  1389),  INT16_C( 13138), -INT16_C( 17448), -INT16_C( 32712), -INT16_C( 24197), -INT16_C( 23440) } },
    { { -INT16_C( 13484),  INT16_C( 28358),  INT16_C( 31073), -INT16_C(  2310),  INT16_C( 12956), -INT16_C( 15019), -INT16_C(  1867),  INT16_C(  8945) },
      {  INT16_C( 17661), -INT16_C( 10923), -INT16_C( 28929),  INT16_C( 31317), -INT16_C( 14801),  INT16_C(  1822),  INT16_C( 10466),  INT16_C( 14039) },
       INT32_C(           7),
      {  INT16_C(  8945),  INT16_C( 17661), -INT16_C( 10923), -INT16_C( 28929),  INT16_C( 31317), -INT16_C( 14801),  INT16_C(  1822),  INT16_C( 10466) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vextq_s16, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vextq_s16(a, b, lanes[i]);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int n;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   145520176), -INT32_C(  1239517348),  INT32_C(  1536889979),  INT32_C(   771985900) },
      { -INT32_C(  1757387936),  INT32_C(  2023341027), -INT32_C(   369368052), -INT32_C(  2043944522) },
       INT32_C(           0),
      { -INT32_C(   145520176), -INT32_C(  1239517348),  INT32_C(  1536889979),  INT32_C(   771985900) } },
    { { -INT32_C(   948011413),  INT32_C(  1887280373), -INT32_C(  1664345936),  INT32_C(   164286377) },
      {  INT32_C(   362875442), -INT32_C(   762496314), -INT32_C(   709064674), -INT32_C(   715397270) },
       INT32_C(           1),
      {  INT32_C(  1887280373), -INT32_C(  1664345936),  INT32_C(   164286377),  INT32_C(   362875442) } },
    { {  INT32_C(  1537005925),  INT32_C(   650844534), -INT32_C(   624715983), -INT32_C(  1729917594) },
      {  INT32_C(  1588429976), -INT32_C(   584041538),  INT32_C(   766700739),  INT32_C(   956435923) },
       INT32_C(           2),
      { -INT32_C(   624715983), -INT32_C(  1729917594),  INT32_C(  1588429976), -INT32_C(   584041538) } },
    { {  INT32_C(  1570021095), -INT32_C(   394043465),  INT32_C(  1573013239),  INT32_C(  1828103892) },
      { -INT32_C(   372595926), -INT32_C(  1564017954), -INT32_C(  1160808217),  INT32_C(  1827918469) },
       INT32_C(           3),
      {  INT32_C(  1828103892), -INT32_C(   372595926), -INT32_C(  1564017954), -INT32_C(  1160808217) } },
    { {  INT32_C(   684296048), -INT32_C(   569356825),  INT32_C(  1731974035), -INT32_C(  1546440327) },
      { -INT32_C(  1282630187),  INT32_C(  2136298136),  INT32_C(  1345922506),  INT32_C(  1740385783) },
       INT32_C(           0),
      {  INT32_C(   684296048), -INT32_C(   569356825),  INT32_C(  1731974035), -INT32_C(  1546440327) } },
    { { -INT32_C(  1685092684),  INT32_C(  1719247059), -INT32_C(   321997453), -INT32_C(  1148214810) },
      { -INT32_C(   680584129),  INT32_C(   961987694), -INT32_C(   527855639),  INT32_C(  1900561852) },
       INT32_C(           1),
      {  INT32_C(  1719247059), -INT32_C(   321997453), -INT32_C(  1148214810), -INT32_C(   680584129) } },
    { { -INT32_C(  1643325493), -INT32_C(   368736649),  INT32_C(   567726907), -INT32_C(  1277335948) },
      { -INT32_C(   259371902), -INT32_C(    97918960),  INT32_C(   752530032), -INT32_C(  1013112072) },
       INT32_C(           2),
      {  INT32_C(   567726907), -INT32_C(  1277335948), -INT32_C(   259371902), -INT32_C(    97918960) } },
    { {  INT32_C(  1902291706),  INT32_C(  1801217840), -INT32_C(  1366543814),  INT32_C(   442657176) },
      { -INT32_C(   972297035),  INT32_C(  1036006605), -INT32_C(   546727193), -INT32_C(  1214117955) },
       INT32_C(           3),
      {  INT32_C(   442657176), -INT32_C(   972297035),  INT32_C(  1036006605), -INT32_C(   546727193) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vextq_s32, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vextq_s32(a, b, lanes[i]);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int n;
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8417013950001805874),  INT64_C( 3633663084360530521) },
      {  INT64_C( 1943148483586602984),  INT64_C( 3816659953121660075) },
       INT32_C(           0),
      {  INT64_C( 8417013950001805874),  INT64_C( 3633663084360530521) } },
    { { -INT64_C( 1439284280502823430),  INT64_C( 1054151440654452764) },
      { -INT64_C( 4311023356637567279), -INT64_C( 1374377497113431369) },
       INT32_C(           1),
      {  INT64_C( 1054151440654452764), -INT64_C( 4311023356637567279) } },
    { {  INT64_C( 9155400649511190671), -INT64_C( 6593111716141286836) },
      { -INT64_C( 7488392302349077195),  INT64_C( 2320267026713630292) },
       INT32_C(           0),
      {  INT64_C( 9155400649511190671), -INT64_C( 6593111716141286836) } },
    { { -INT64_C( 9016399738793971202), -INT64_C( 7889614551166694134) },
      {  INT64_C( 8044261376637614122),  INT64_C( 3458176489256055627) },
       INT32_C(           1),
      { -INT64_C( 7889614551166694134),  INT64_C( 8044261376637614122) } },
    { { -INT64_C( 7326670976013287525), -INT64_C( 1860835758546860227) },
      {  INT64_C( 5673852747975233075), -INT64_C(  583453248029232250) },
       INT32_C(           0),
      { -INT64_C( 7326670976013287525), -INT64_C( 1860835758546860227) } },
    { {  INT64_C( 2635198315562039143),  INT64_C( 4108384592786754145) },
      {  INT64_C(  957653221600916728),  INT64_C(  291517491048707511) },
       INT32_C(           1),
      {  INT64_C( 4108384592786754145),  INT64_C(  957653221600916728) } },
    { {  INT64_C( 5705936401661219620), -INT64_C( 3398123318154564200) },
      {  INT64_C( 6482956552596381284), -INT64_C( 8129991925187166581) },
       INT32_C(           0),
      {  INT64_C( 5705936401661219620), -INT64_C( 3398123318154564200) } },
    { {  INT64_C( 5730771934834796618), -INT64_C( 4080045330485349448) },
      { -INT64_C( 3666586218353513438),  INT64_C( 5432222966802123113) },
       INT32_C(           1),
      { -INT64_C( 4080045330485349448), -INT64_C( 3666586218353513438) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    int n = test_vec[i].n;
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vextq_s64, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vextq_s64(a, b, lanes[i]);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    int n;
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(236), UINT8_C( 12), UINT8_C(220), UINT8_C( 76), UINT8_C(149), UINT8_C(102), UINT8_C(190), UINT8_C(154),
        UINT8_C(190), UINT8_C( 97), UINT8_C( 26), UINT8_C(  0), UINT8_C(104), UINT8_C(  4), UINT8_C(242), UINT8_C( 16) },
      { UINT8_C( 85), UINT8_C(127), UINT8_C(245), UINT8_C( 30), UINT8_C(177), UINT8_C(132), UINT8_C( 67), UINT8_C(107),
        UINT8_C(115), UINT8_C( 46), UINT8_C(225), UINT8_C( 35), UINT8_C( 67), UINT8_C( 16), UINT8_C( 83), UINT8_C( 47) },
       INT32_C(           0),
      { UINT8_C(236), UINT8_C( 12), UINT8_C(220), UINT8_C( 76), UINT8_C(149), UINT8_C(102), UINT8_C(190), UINT8_C(154),
        UINT8_C(190), UINT8_C( 97), UINT8_C( 26), UINT8_C(  0), UINT8_C(104), UINT8_C(  4), UINT8_C(242), UINT8_C( 16) } },
    { { UINT8_C( 28), UINT8_C( 47), UINT8_C(124), UINT8_C(177), UINT8_C(149), UINT8_C( 58), UINT8_C( 76), UINT8_C( 83),
        UINT8_C(156), UINT8_C(102), UINT8_C( 84), UINT8_C(  4), UINT8_C(106), UINT8_C( 70), UINT8_C( 20), UINT8_C(191) },
      { UINT8_C(197), UINT8_C(  9), UINT8_C(221), UINT8_C(118), UINT8_C(141), UINT8_C( 33), UINT8_C(225), UINT8_C(  0),
        UINT8_C( 79), UINT8_C(194), UINT8_C( 35), UINT8_C(147), UINT8_C(210), UINT8_C(118), UINT8_C(194), UINT8_C(239) },
       INT32_C(           2),
      { UINT8_C(124), UINT8_C(177), UINT8_C(149), UINT8_C( 58), UINT8_C( 76), UINT8_C( 83), UINT8_C(156), UINT8_C(102),
        UINT8_C( 84), UINT8_C(  4), UINT8_C(106), UINT8_C( 70), UINT8_C( 20), UINT8_C(191), UINT8_C(197), UINT8_C(  9) } },
    { { UINT8_C(166), UINT8_C( 62), UINT8_C(160), UINT8_C( 59), UINT8_C(121), UINT8_C(236), UINT8_C(143), UINT8_C( 21),
        UINT8_C( 82), UINT8_C(227), UINT8_C( 25), UINT8_C(188), UINT8_C( 41), UINT8_C( 45), UINT8_C(123), UINT8_C(238) },
      { UINT8_C( 54), UINT8_C( 89), UINT8_C(100), UINT8_C(196), UINT8_C(122), UINT8_C( 69), UINT8_C(196), UINT8_C(201),
        UINT8_C(  7), UINT8_C(232), UINT8_C( 92), UINT8_C(218), UINT8_C( 94), UINT8_C( 31), UINT8_C(201), UINT8_C(  4) },
       INT32_C(           4),
      { UINT8_C(121), UINT8_C(236), UINT8_C(143), UINT8_C( 21), UINT8_C( 82), UINT8_C(227), UINT8_C( 25), UINT8_C(188),
        UINT8_C( 41), UINT8_C( 45), UINT8_C(123), UINT8_C(238), UINT8_C( 54), UINT8_C( 89), UINT8_C(100), UINT8_C(196) } },
    { { UINT8_C( 93), UINT8_C(105), UINT8_C( 64), UINT8_C(214), UINT8_C( 86), UINT8_C(207), UINT8_C(235), UINT8_C(168),
        UINT8_C(178), UINT8_C(  4), UINT8_C(101), UINT8_C(219), UINT8_C( 49), UINT8_C(224), UINT8_C(201), UINT8_C(104) },
      { UINT8_C( 57), UINT8_C( 45), UINT8_C( 44), UINT8_C(179), UINT8_C(114), UINT8_C(240), UINT8_C(125), UINT8_C(121),
        UINT8_C(216), UINT8_C(217), UINT8_C( 83), UINT8_C( 55), UINT8_C(248), UINT8_C( 28), UINT8_C( 59), UINT8_C( 86) },
       INT32_C(           6),
      { UINT8_C(235), UINT8_C(168), UINT8_C(178), UINT8_C(  4), UINT8_C(101), UINT8_C(219), UINT8_C( 49), UINT8_C(224),
        UINT8_C(201), UINT8_C(104), UINT8_C( 57), UINT8_C( 45), UINT8_C( 44), UINT8_C(179), UINT8_C(114), UINT8_C(240) } },
    { { UINT8_C(134), UINT8_C(123), UINT8_C( 44), UINT8_C(220), UINT8_C( 74), UINT8_C( 24), UINT8_C(132), UINT8_C(252),
        UINT8_C( 28), UINT8_C(233), UINT8_C(215), UINT8_C( 78), UINT8_C(202), UINT8_C(160), UINT8_C(182), UINT8_C(  3) },
      { UINT8_C(205), UINT8_C(226), UINT8_C(183), UINT8_C( 63), UINT8_C(210), UINT8_C( 52), UINT8_C(185), UINT8_C(171),
        UINT8_C( 13), UINT8_C( 12), UINT8_C(226), UINT8_C(  6), UINT8_C( 41), UINT8_C( 29), UINT8_C( 92), UINT8_C(175) },
       INT32_C(           8),
      { UINT8_C( 28), UINT8_C(233), UINT8_C(215), UINT8_C( 78), UINT8_C(202), UINT8_C(160), UINT8_C(182), UINT8_C(  3),
        UINT8_C(205), UINT8_C(226), UINT8_C(183), UINT8_C( 63), UINT8_C(210), UINT8_C( 52), UINT8_C(185), UINT8_C(171) } },
    { { UINT8_C(153), UINT8_C(136), UINT8_C(139), UINT8_C(227), UINT8_C(160), UINT8_C( 15), UINT8_C(224), UINT8_C(189),
        UINT8_C(249), UINT8_C(183), UINT8_C( 11), UINT8_C(195), UINT8_C( 88), UINT8_C(193), UINT8_C(198), UINT8_C( 37) },
      { UINT8_C(163), UINT8_C(125), UINT8_C(101), UINT8_C(117), UINT8_C(177), UINT8_C( 30), UINT8_C( 32), UINT8_C(191),
        UINT8_C( 42), UINT8_C(  2), UINT8_C(197), UINT8_C( 83), UINT8_C( 32), UINT8_C( 33), UINT8_C(  2), UINT8_C(185) },
       INT32_C(          10),
      { UINT8_C( 11), UINT8_C(195), UINT8_C( 88), UINT8_C(193), UINT8_C(198), UINT8_C( 37), UINT8_C(163), UINT8_C(125),
        UINT8_C(101), UINT8_C(117), UINT8_C(177), UINT8_C( 30), UINT8_C( 32), UINT8_C(191), UINT8_C( 42), UINT8_C(  2) } },
    { { UINT8_C(169), UINT8_C(141), UINT8_C(156), UINT8_C( 74), UINT8_C(157), UINT8_C(124), UINT8_C(  7), UINT8_C(150),
        UINT8_C( 52), UINT8_C( 18), UINT8_C( 89), UINT8_C(140), UINT8_C(211), UINT8_C( 31), UINT8_C(177), UINT8_C(118) },
      { UINT8_C(157), UINT8_C( 22), UINT8_C(235), UINT8_C( 78), UINT8_C( 52), UINT8_C( 12), UINT8_C( 13), UINT8_C( 95),
        UINT8_C( 14), UINT8_C(210), UINT8_C(178), UINT8_C( 46), UINT8_C(243), UINT8_C(181), UINT8_C(231), UINT8_C(157) },
       INT32_C(          12),
      { UINT8_C(211), UINT8_C( 31), UINT8_C(177), UINT8_C(118), UINT8_C(157), UINT8_C( 22), UINT8_C(235), UINT8_C( 78),
        UINT8_C( 52), UINT8_C( 12), UINT8_C( 13), UINT8_C( 95), UINT8_C( 14), UINT8_C(210), UINT8_C(178), UINT8_C( 46) } },
    { { UINT8_C( 66), UINT8_C(132), UINT8_C(231), UINT8_C(223), UINT8_C(  0), UINT8_C(238), UINT8_C(117), UINT8_C( 52),
        UINT8_C(  0), UINT8_C(206), UINT8_C(192), UINT8_C(211), UINT8_C(238), UINT8_C(114), UINT8_C( 73), UINT8_C(139) },
      { UINT8_C(136), UINT8_C( 52), UINT8_C(217), UINT8_C(189), UINT8_C( 64), UINT8_C(231), UINT8_C( 28), UINT8_C( 79),
        UINT8_C(185), UINT8_C(206), UINT8_C(125), UINT8_C(173), UINT8_C(131), UINT8_C(101), UINT8_C( 74), UINT8_C(198) },
       INT32_C(          14),
      { UINT8_C( 73), UINT8_C(139), UINT8_C(136), UINT8_C( 52), UINT8_C(217), UINT8_C(189), UINT8_C( 64), UINT8_C(231),
        UINT8_C( 28), UINT8_C( 79), UINT8_C(185), UINT8_C(206), UINT8_C(125), UINT8_C(173), UINT8_C(131), UINT8_C(101) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vextq_u8, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 2, 4, 6, 8, 10, 12, 14 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vextq_u8(a, b, lanes[i]);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    int n;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(24754), UINT16_C(42838), UINT16_C(61167), UINT16_C(61004), UINT16_C(44235), UINT16_C(29361), UINT16_C(52240), UINT16_C(47002) },
      { UINT16_C(58649), UINT16_C(62180), UINT16_C(35996), UINT16_C(45949), UINT16_C(27671), UINT16_C(46444), UINT16_C(49652), UINT16_C(42653) },
       INT32_C(           0),
      { UINT16_C(24754), UINT16_C(42838), UINT16_C(61167), UINT16_C(61004), UINT16_C(44235), UINT16_C(29361), UINT16_C(52240), UINT16_C(47002) } },
    { { UINT16_C(62241), UINT16_C( 4173), UINT16_C(39393), UINT16_C(44543), UINT16_C(45125), UINT16_C(21791), UINT16_C(47740), UINT16_C(38413) },
      { UINT16_C(61855), UINT16_C(15496), UINT16_C( 1405), UINT16_C(38383), UINT16_C(23410), UINT16_C(26186), UINT16_C(59165), UINT16_C(15884) },
       INT32_C(           1),
      { UINT16_C( 4173), UINT16_C(39393), UINT16_C(44543), UINT16_C(45125), UINT16_C(21791), UINT16_C(47740), UINT16_C(38413), UINT16_C(61855) } },
    { { UINT16_C(23002), UINT16_C(48207), UINT16_C(20210), UINT16_C(14185), UINT16_C(35070), UINT16_C(31628), UINT16_C(39234), UINT16_C(57873) },
      { UINT16_C(39307), UINT16_C( 2078), UINT16_C( 3487), UINT16_C( 4509), UINT16_C(59241), UINT16_C(34423), UINT16_C(33742), UINT16_C(43460) },
       INT32_C(           2),
      { UINT16_C(20210), UINT16_C(14185), UINT16_C(35070), UINT16_C(31628), UINT16_C(39234), UINT16_C(57873), UINT16_C(39307), UINT16_C( 2078) } },
    { { UINT16_C( 5084), UINT16_C(52837), UINT16_C(52833), UINT16_C(24581), UINT16_C(37206), UINT16_C(39387), UINT16_C(60459), UINT16_C(46715) },
      { UINT16_C(39301), UINT16_C( 9406), UINT16_C(23718), UINT16_C( 3893), UINT16_C(44099), UINT16_C( 4757), UINT16_C(23087), UINT16_C( 3003) },
       INT32_C(           3),
      { UINT16_C(24581), UINT16_C(37206), UINT16_C(39387), UINT16_C(60459), UINT16_C(46715), UINT16_C(39301), UINT16_C( 9406), UINT16_C(23718) } },
    { { UINT16_C( 8301), UINT16_C(53209), UINT16_C(57070), UINT16_C(17455), UINT16_C( 2672), UINT16_C(39901), UINT16_C(22774), UINT16_C(31569) },
      { UINT16_C( 4081), UINT16_C(39072), UINT16_C(54635), UINT16_C(44967), UINT16_C(15746), UINT16_C(45505), UINT16_C(31895), UINT16_C( 1213) },
       INT32_C(           4),
      { UINT16_C( 2672), UINT16_C(39901), UINT16_C(22774), UINT16_C(31569), UINT16_C( 4081), UINT16_C(39072), UINT16_C(54635), UINT16_C(44967) } },
    { { UINT16_C(38556), UINT16_C(35539), UINT16_C(  629), UINT16_C(58830), UINT16_C(44044), UINT16_C(  640), UINT16_C(53508), UINT16_C(63102) },
      { UINT16_C( 7904), UINT16_C(19598), UINT16_C(13811), UINT16_C(30203), UINT16_C(48242), UINT16_C( 2343), UINT16_C(58424), UINT16_C(54286) },
       INT32_C(           5),
      { UINT16_C(  640), UINT16_C(53508), UINT16_C(63102), UINT16_C( 7904), UINT16_C(19598), UINT16_C(13811), UINT16_C(30203), UINT16_C(48242) } },
    { { UINT16_C(57722), UINT16_C(61278), UINT16_C(11492), UINT16_C(61652), UINT16_C(21720), UINT16_C(56819), UINT16_C(28965), UINT16_C( 1747) },
      { UINT16_C(24975), UINT16_C(33362), UINT16_C(19862), UINT16_C( 2552), UINT16_C( 7945), UINT16_C(16658), UINT16_C( 8195), UINT16_C(32021) },
       INT32_C(           6),
      { UINT16_C(28965), UINT16_C( 1747), UINT16_C(24975), UINT16_C(33362), UINT16_C(19862), UINT16_C( 2552), UINT16_C( 7945), UINT16_C(16658) } },
    { { UINT16_C(29442), UINT16_C(58989), UINT16_C(16799), UINT16_C(30934), UINT16_C(51606), UINT16_C(47957), UINT16_C(10298), UINT16_C(51649) },
      { UINT16_C( 5001), UINT16_C( 8012), UINT16_C(17504), UINT16_C(26920), UINT16_C(15203), UINT16_C(26282), UINT16_C(48987), UINT16_C(24035) },
       INT32_C(           7),
      { UINT16_C(51649), UINT16_C( 5001), UINT16_C( 8012), UINT16_C(17504), UINT16_C(26920), UINT16_C(15203), UINT16_C(26282), UINT16_C(48987) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vextq_u16, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vextq_u16(a, b, lanes[i]);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    int n;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2900247930), UINT32_C( 249084522), UINT32_C(3367049666), UINT32_C(2305880858) },
      { UINT32_C(1681122816), UINT32_C( 807407232), UINT32_C(3769075986), UINT32_C(2554260254) },
       INT32_C(           0),
      { UINT32_C(2900247930), UINT32_C( 249084522), UINT32_C(3367049666), UINT32_C(2305880858) } },
    { { UINT32_C(2588155184), UINT32_C(2577931479), UINT32_C(1348557109), UINT32_C(1306120525) },
      { UINT32_C( 934350007), UINT32_C( 761778458), UINT32_C(2030898778), UINT32_C( 688999417) },
       INT32_C(           1),
      { UINT32_C(2577931479), UINT32_C(1348557109), UINT32_C(1306120525), UINT32_C( 934350007) } },
    { { UINT32_C(1086609000), UINT32_C(2832821362), UINT32_C( 335035334), UINT32_C(3294679308) },
      { UINT32_C(4160426461), UINT32_C(1009017826), UINT32_C(1807036785), UINT32_C(3851732861) },
       INT32_C(           2),
      { UINT32_C( 335035334), UINT32_C(3294679308), UINT32_C(4160426461), UINT32_C(1009017826) } },
    { { UINT32_C(2401589277), UINT32_C(2335702981), UINT32_C(1184771898), UINT32_C(3708485120) },
      { UINT32_C(4057269775), UINT32_C(3660446057), UINT32_C(2823152427), UINT32_C(3347962538) },
       INT32_C(           3),
      { UINT32_C(3708485120), UINT32_C(4057269775), UINT32_C(3660446057), UINT32_C(2823152427) } },
    { { UINT32_C(4149654322), UINT32_C(3967979186), UINT32_C(3190956221), UINT32_C( 765148446) },
      { UINT32_C(2887675971), UINT32_C(2508606570), UINT32_C(3644705839), UINT32_C(3634416294) },
       INT32_C(           0),
      { UINT32_C(4149654322), UINT32_C(3967979186), UINT32_C(3190956221), UINT32_C( 765148446) } },
    { { UINT32_C( 802223741), UINT32_C(1109086852), UINT32_C(2432716403), UINT32_C(3468663691) },
      { UINT32_C(1987763468), UINT32_C(1477115945), UINT32_C(1915832524), UINT32_C(2420887826) },
       INT32_C(           1),
      { UINT32_C(1109086852), UINT32_C(2432716403), UINT32_C(3468663691), UINT32_C(1987763468) } },
    { { UINT32_C(1287592904), UINT32_C(3767458669), UINT32_C(3027406377), UINT32_C( 914501930) },
      { UINT32_C( 950860814), UINT32_C(3381704700), UINT32_C( 289129215), UINT32_C(1537312403) },
       INT32_C(           2),
      { UINT32_C(3027406377), UINT32_C( 914501930), UINT32_C( 950860814), UINT32_C(3381704700) } },
    { { UINT32_C( 262693281), UINT32_C(1710175804), UINT32_C(4011418053), UINT32_C(2703596434) },
      { UINT32_C(2480525719), UINT32_C(2270980488), UINT32_C(3214448683), UINT32_C(3222944286) },
       INT32_C(           3),
      { UINT32_C(2703596434), UINT32_C(2480525719), UINT32_C(2270980488), UINT32_C(3214448683) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vextq_u32, r, (HEDLEY_UNREACHABLE(), a), n, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vextq_u32(a, b, lanes[i]);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vextq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    int n;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7730985752149231055), UINT64_C(16691050437685090889) },
      { UINT64_C(15296917467191559588), UINT64_C( 4953153054590983161) },
       INT32_C(           0),
      { UINT64_C( 7730985752149231055), UINT64_C(16691050437685090889) } },
    { { UINT64_C( 8585916073411621671), UINT64_C(12195681843175063656) },
      { UINT64_C( 3873588522413173385), UINT64_C( 1501322571122461211) },
       INT32_C(           1),
      { UINT64_C(12195681843175063656), UINT64_C( 3873588522413173385) } },
    { { UINT64_C(10348416691789093623), UINT64_C(  731032852088995190) },
      { UINT64_C( 8665691342820056273), UINT64_C(  397124965935696258) },
       INT32_C(           0),
      { UINT64_C(10348416691789093623), UINT64_C(  731032852088995190) } },
    { { UINT64_C(13794743674936644281), UINT64_C( 5696877048505194371) },
      { UINT64_C( 4670688828940093180), UINT64_C( 8357046737594997736) },
       INT32_C(           1),
      { UINT64_C( 5696877048505194371), UINT64_C( 4670688828940093180) } },
    { { UINT64_C( 7965675779152618627), UINT64_C( 2443345895848396059) },
      { UINT64_C(14593998027727979657), UINT64_C(17029159575628035878) },
       INT32_C(           0),
      { UINT64_C( 7965675779152618627), UINT64_C( 2443345895848396059) } },
    { { UINT64_C( 9599215256693417951), UINT64_C(13136443954186594824) },
      { UINT64_C( 4249011095164799050), UINT64_C( 5841571628204144572) },
       INT32_C(           1),
      { UINT64_C(13136443954186594824), UINT64_C( 4249011095164799050) } },
    { { UINT64_C( 1442649469284436245), UINT64_C( 8493665932999271676) },
      { UINT64_C( 2280960384311680345), UINT64_C( 5049754754406990417) },
       INT32_C(           0),
      { UINT64_C( 1442649469284436245), UINT64_C( 8493665932999271676) } },
    { { UINT64_C( 9024875554142563870), UINT64_C( 7678503297709670640) },
      { UINT64_C( 2081928341414687075), UINT64_C(11220986191717279809) },
       INT32_C(           1),
      { UINT64_C( 7678503297709670640), UINT64_C( 2081928341414687075) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    int n = test_vec[i].n;
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vextq_u64, r, (HEDLEY_UNREACHABLE(), a), n, a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vextq_u64(a, b, lanes[i]);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vext_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vext_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vextq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vextq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
