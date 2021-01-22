#define SIMDE_TEST_ARM_NEON_INSN st1_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/st1_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vst1_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 val[2];
    int lane;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   758.86),
      { SIMDE_FLOAT32_C(   758.86), SIMDE_FLOAT32_C(   425.86) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -723.17),
      { SIMDE_FLOAT32_C(  -381.17), SIMDE_FLOAT32_C(  -723.17) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -445.02),
      { SIMDE_FLOAT32_C(  -445.02), SIMDE_FLOAT32_C(  -699.72) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -700.54),
      { SIMDE_FLOAT32_C(  -207.44), SIMDE_FLOAT32_C(  -700.54) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -873.60),
      { SIMDE_FLOAT32_C(  -873.60), SIMDE_FLOAT32_C(  -557.72) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(   122.92),
      { SIMDE_FLOAT32_C(   178.64), SIMDE_FLOAT32_C(   122.92) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(   972.30),
      { SIMDE_FLOAT32_C(   972.30), SIMDE_FLOAT32_C(   277.03) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(    73.76),
      { SIMDE_FLOAT32_C(   826.05), SIMDE_FLOAT32_C(    73.76) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t val = simde_vld1_f32(test_vec[i].val);
    simde_float32 a;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst1_lane_f32, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);

    simde_assert_equal_f32(a, test_vec[i].a, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a;
    simde_float32x2_t val = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_vst1_lane_f32(&a, val, lanes[i]);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 val[1];
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -672.00),
      { SIMDE_FLOAT64_C(  -672.00) } },
    { SIMDE_FLOAT64_C(   684.22),
      { SIMDE_FLOAT64_C(   684.22) } },
    { SIMDE_FLOAT64_C(   -14.73),
      { SIMDE_FLOAT64_C(   -14.73) } },
    { SIMDE_FLOAT64_C(  -277.48),
      { SIMDE_FLOAT64_C(  -277.48) } },
    { SIMDE_FLOAT64_C(  -464.79),
      { SIMDE_FLOAT64_C(  -464.79) } },
    { SIMDE_FLOAT64_C(  -299.87),
      { SIMDE_FLOAT64_C(  -299.87) } },
    { SIMDE_FLOAT64_C(  -770.81),
      { SIMDE_FLOAT64_C(  -770.81) } },
    { SIMDE_FLOAT64_C(  -134.46),
      { SIMDE_FLOAT64_C(  -134.46) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t val = simde_vld1_f64(test_vec[i].val);
    simde_float64 a;
    simde_vst1_lane_f64(&a, val, 0);

    simde_assert_equal_f64(a, test_vec[i].a, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a;
    simde_float64x1_t val = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_vst1_lane_f64(&a, val, 0);
    int lane = 0;

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t val[8];
    int lane;
  } test_vec[] = {
    {  INT8_C(   9),
      {  INT8_C(   9),  INT8_C(  57),  INT8_C(   8), -INT8_C(  94),  INT8_C(  72),  INT8_C(  37), -INT8_C(  66),  INT8_C(  77) },
       INT32_C(           0) },
    {  INT8_C( 114),
      { -INT8_C(  76),  INT8_C( 114),  INT8_C(  11), -INT8_C(  90), -INT8_C(  75),  INT8_C(   3), -INT8_C(  20), -INT8_C(   3) },
       INT32_C(           1) },
    { -INT8_C(   5),
      {  INT8_C(  90),  INT8_C(  34), -INT8_C(   5), -INT8_C(  23), -INT8_C( 121), -INT8_C(  42),  INT8_C(  41), -INT8_C(  74) },
       INT32_C(           2) },
    {  INT8_C(  15),
      {  INT8_C( 123),  INT8_C(  18), -INT8_C(   2),  INT8_C(  15),  INT8_C( 126), -INT8_C( 126),  INT8_C(  31), -INT8_C( 121) },
       INT32_C(           3) },
    {  INT8_C(  76),
      { -INT8_C(  69),  INT8_C(  39),  INT8_C(  42),  INT8_C(   3),  INT8_C(  76), -INT8_C(  24),  INT8_C(  80),  INT8_C(   1) },
       INT32_C(           4) },
    { -INT8_C( 109),
      {  INT8_C(  90),  INT8_C(  91), -INT8_C(  89),  INT8_C(  16),  INT8_C(  94), -INT8_C( 109),  INT8_C(  13), -INT8_C(  72) },
       INT32_C(           5) },
    { -INT8_C(  13),
      { -INT8_C(  75),  INT8_C(   8), -INT8_C(  94),  INT8_C(  60), -INT8_C(  34), -INT8_C(  53), -INT8_C(  13),  INT8_C(  90) },
       INT32_C(           6) },
    {  INT8_C(  46),
      { -INT8_C(  35), -INT8_C(  15),  INT8_C( 105),  INT8_C(  91),  INT8_C( 115), -INT8_C( 120), -INT8_C(  30),  INT8_C(  46) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t a;
    simde_int8x8_t val = simde_vld1_s8(test_vec[i].val);
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst1_lane_s8, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);

    simde_assert_equal_i8(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a;
    simde_int8x8_t val = simde_test_arm_neon_random_i8x8();
    const int lane = lanes[i];
    simde_vst1_lane_s8(&a, val, lane);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t val[4];
    int lane;
  } test_vec[] = {
    {  INT16_C( 25194),
      {  INT16_C( 25194),  INT16_C( 22539),  INT16_C( 14552),  INT16_C( 12907) },
       INT32_C(           0) },
    { -INT16_C( 28985),
      { -INT16_C(  7314), -INT16_C( 28985),  INT16_C( 29951), -INT16_C( 32699) },
       INT32_C(           1) },
    { -INT16_C( 15453),
      { -INT16_C( 32139), -INT16_C( 19838), -INT16_C( 15453), -INT16_C( 18078) },
       INT32_C(           2) },
    { -INT16_C(   834),
      { -INT16_C(  3979),  INT16_C( 28323), -INT16_C( 12399), -INT16_C(   834) },
       INT32_C(           3) },
    { -INT16_C( 14031),
      { -INT16_C( 14031),  INT16_C(  2644), -INT16_C( 16639),  INT16_C( 28476) },
       INT32_C(           0) },
    { -INT16_C( 24067),
      {  INT16_C(   930), -INT16_C( 24067),  INT16_C( 17271), -INT16_C(  5086) },
       INT32_C(           1) },
    {  INT16_C(   359),
      { -INT16_C( 23355),  INT16_C( 26783),  INT16_C(   359), -INT16_C(  9183) },
       INT32_C(           2) },
    { -INT16_C( 14978),
      { -INT16_C( 14863), -INT16_C( 32181),  INT16_C(  2452), -INT16_C( 14978) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t val = simde_vld1_s16(test_vec[i].val);
    int16_t a;
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst1_lane_s16, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_i16(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a;
    simde_int16x4_t val = simde_test_arm_neon_random_i16x4();
    const int lane = lanes[i];
    simde_vst1_lane_s16(&a, val, lane);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t val[2];
    int lane;
  } test_vec[] = {
    { -INT32_C(  1176692915),
      { -INT32_C(  1176692915), -INT32_C(  1019739805) },
       INT32_C(           0) },
    {  INT32_C(   639152599),
      {  INT32_C(  1743701338),  INT32_C(   639152599) },
       INT32_C(           1) },
    { -INT32_C(  2131206463),
      { -INT32_C(  2131206463), -INT32_C(   691177546) },
       INT32_C(           0) },
    {  INT32_C(   773618656),
      { -INT32_C(  1531866460),  INT32_C(   773618656) },
       INT32_C(           1) },
    { -INT32_C(   152569453),
      { -INT32_C(   152569453),  INT32_C(  1438261498) },
       INT32_C(           0) },
    {  INT32_C(   451073113),
      { -INT32_C(  1128486683),  INT32_C(   451073113) },
       INT32_C(           1) },
    { -INT32_C(   392439246),
      { -INT32_C(   392439246), -INT32_C(   155228079) },
       INT32_C(           0) },
    {  INT32_C(  2131343340),
      { -INT32_C(   610635525),  INT32_C(  2131343340) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t val = simde_vld1_s32(test_vec[i].val);
    int32_t a;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst1_lane_s32, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_i32(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a;
    simde_int32x2_t val = simde_test_arm_neon_random_i32x2();
    const int lane = lanes[i];
    simde_vst1_lane_s32(&a, val, lane);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t val[1];
  } test_vec[] = {
    { -INT64_C( 3973240137489820217),
      { -INT64_C( 3973240137489820217) } },
    { -INT64_C(  194556375924638676),
      { -INT64_C(  194556375924638676) } },
    {  INT64_C( 2167462674658928341),
      {  INT64_C( 2167462674658928341) } },
    {  INT64_C(  140538722373190919),
      {  INT64_C(  140538722373190919) } },
    { -INT64_C( 1185217718330684256),
      { -INT64_C( 1185217718330684256) } },
    {  INT64_C( 7547189185119307710),
      {  INT64_C( 7547189185119307710) } },
    {  INT64_C( 1843413786645214118),
      {  INT64_C( 1843413786645214118) } },
    { -INT64_C( 4747008286953647387),
      { -INT64_C( 4747008286953647387) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t val = simde_vld1_s64(test_vec[i].val);
    int64_t a;
    simde_vst1_lane_s64(&a, val, 0);
    simde_assert_equal_i64(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a;
    simde_int64x1_t val = simde_test_arm_neon_random_i64x1();
    const int lane = lanes[i];
    simde_vst1_lane_s64(&a, val, lane);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t val[8];
    int lane;
  } test_vec[] = {
    { UINT8_C(144),
      { UINT8_C(144), UINT8_C(105), UINT8_C( 20), UINT8_C(162), UINT8_C( 36), UINT8_C(  2), UINT8_C(118), UINT8_C(233) },
       INT32_C(           0) },
    { UINT8_C(133),
      { UINT8_C( 80), UINT8_C(133), UINT8_C(190), UINT8_C( 62), UINT8_C(191), UINT8_C(138), UINT8_C( 84), UINT8_C(132) },
       INT32_C(           1) },
    { UINT8_C(209),
      { UINT8_C( 52), UINT8_C( 89), UINT8_C(209), UINT8_C(104), UINT8_C( 51), UINT8_C(132), UINT8_C(163), UINT8_C( 59) },
       INT32_C(           2) },
    { UINT8_C( 59),
      { UINT8_C( 57), UINT8_C( 21), UINT8_C(200), UINT8_C( 59), UINT8_C(214), UINT8_C(197), UINT8_C( 18), UINT8_C(102) },
       INT32_C(           3) },
    { UINT8_C( 40),
      { UINT8_C( 47), UINT8_C( 38), UINT8_C(  8), UINT8_C( 83), UINT8_C( 40), UINT8_C(127), UINT8_C( 60), UINT8_C(120) },
       INT32_C(           4) },
    { UINT8_C( 11),
      { UINT8_C(  4), UINT8_C(250), UINT8_C(183), UINT8_C(196), UINT8_C(133), UINT8_C( 11), UINT8_C( 72), UINT8_C(185) },
       INT32_C(           5) },
    { UINT8_C(210),
      { UINT8_C(100), UINT8_C( 25), UINT8_C( 33), UINT8_C(151), UINT8_C(158), UINT8_C(197), UINT8_C(210), UINT8_C(215) },
       INT32_C(           6) },
    { UINT8_C(143),
      { UINT8_C(218), UINT8_C(154), UINT8_C( 18), UINT8_C(177), UINT8_C( 96), UINT8_C( 36), UINT8_C( 23), UINT8_C(143) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t val = simde_vld1_u8(test_vec[i].val);
    uint8_t a;
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst1_lane_u8, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u8(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a;
    simde_uint8x8_t val = simde_test_arm_neon_random_u8x8();
    const uint lane = lanes[i];
    simde_vst1_lane_u8(&a, val, lane);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t val[4];
    int lane;
  } test_vec[] = {
    { UINT16_C(52711),
      { UINT16_C(52711), UINT16_C(64187), UINT16_C(20378), UINT16_C(54290) },
       INT32_C(           0) },
    { UINT16_C(52158),
      { UINT16_C(59808), UINT16_C(52158), UINT16_C(18507), UINT16_C(50802) },
       INT32_C(           1) },
    { UINT16_C(27778),
      { UINT16_C(16782), UINT16_C(16914), UINT16_C(27778), UINT16_C(16423) },
       INT32_C(           2) },
    { UINT16_C(26042),
      { UINT16_C(44278), UINT16_C(62894), UINT16_C(31614), UINT16_C(26042) },
       INT32_C(           3) },
    { UINT16_C(30281),
      { UINT16_C(30281), UINT16_C(58207), UINT16_C(29381), UINT16_C(26039) },
       INT32_C(           0) },
    { UINT16_C(42544),
      { UINT16_C(30299), UINT16_C(42544), UINT16_C(41662), UINT16_C(19564) },
       INT32_C(           1) },
    { UINT16_C(46827),
      { UINT16_C(32483), UINT16_C(25998), UINT16_C(46827), UINT16_C(57765) },
       INT32_C(           2) },
    { UINT16_C( 6214),
      { UINT16_C(21602), UINT16_C(57558), UINT16_C(37071), UINT16_C( 6214) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t val = simde_vld1_u16(test_vec[i].val);
    uint16_t a;
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst1_lane_u16, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u16(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a;
    simde_uint16x4_t val = simde_test_arm_neon_random_u16x4();
    const uint lane = lanes[i];
    simde_vst1_lane_u16(&a, val, lane);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t val[2];
    int lane;
  } test_vec[] = {
    { UINT32_C( 481195642),
      { UINT32_C( 481195642), UINT32_C(2023252945) },
       INT32_C(           0) },
    { UINT32_C(1656647457),
      { UINT32_C(1504231974), UINT32_C(1656647457) },
       INT32_C(           1) },
    { UINT32_C( 583019691),
      { UINT32_C( 583019691), UINT32_C(1078655062) },
       INT32_C(           0) },
    { UINT32_C(3518892630),
      { UINT32_C(1791365296), UINT32_C(3518892630) },
       INT32_C(           1) },
    { UINT32_C(1374514304),
      { UINT32_C(1374514304), UINT32_C(4123624911) },
       INT32_C(           0) },
    { UINT32_C(2378960353),
      { UINT32_C(1766814280), UINT32_C(2378960353) },
       INT32_C(           1) },
    { UINT32_C(2410646585),
      { UINT32_C(2410646585), UINT32_C( 886045060) },
       INT32_C(           0) },
    { UINT32_C( 523328671),
      { UINT32_C(1621005578), UINT32_C( 523328671) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t val = simde_vld1_u32(test_vec[i].val);
    uint32_t a;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst1_lane_u32, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u32(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a;
    simde_uint32x2_t val = simde_test_arm_neon_random_u32x2();
    const uint lane = lanes[i];
    simde_vst1_lane_u32(&a, val, lane);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t val[1];
  } test_vec[] = {
    { UINT64_C( 5250363356913382472),
      { UINT64_C( 5250363356913382472) } },
    { UINT64_C( 6309684774697879748),
      { UINT64_C( 6309684774697879748) } },
    { UINT64_C( 2553653612082696328),
      { UINT64_C( 2553653612082696328) } },
    { UINT64_C(  687680480654673178),
      { UINT64_C(  687680480654673178) } },
    { UINT64_C(16556837661035665621),
      { UINT64_C(16556837661035665621) } },
    { UINT64_C( 6679908984284861564),
      { UINT64_C( 6679908984284861564) } },
    { UINT64_C(14442753382987286749),
      { UINT64_C(14442753382987286749) } },
    { UINT64_C(14485341070503236157),
      { UINT64_C(14485341070503236157) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t val = simde_vld1_u64(test_vec[i].val);
    uint64_t a;
    simde_vst1_lane_u64(&a, val, 0);
    simde_assert_equal_u64(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_uint64x1_t val = simde_test_arm_neon_random_u64x1();
    simde_vst1_lane_u64(&a, val, 0);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, 0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 val[4];
    int lane;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   455.33),
      { SIMDE_FLOAT32_C(   455.33), SIMDE_FLOAT32_C(  -829.93), SIMDE_FLOAT32_C(   456.39), SIMDE_FLOAT32_C(   -14.07) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(   915.54),
      { SIMDE_FLOAT32_C(   138.27), SIMDE_FLOAT32_C(   915.54), SIMDE_FLOAT32_C(  -484.19), SIMDE_FLOAT32_C(  -949.94) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -971.20),
      { SIMDE_FLOAT32_C(   540.73), SIMDE_FLOAT32_C(   942.66), SIMDE_FLOAT32_C(  -971.20), SIMDE_FLOAT32_C(    91.92) },
       INT32_C(           2) },
    { SIMDE_FLOAT32_C(  -278.01),
      { SIMDE_FLOAT32_C(  -834.19), SIMDE_FLOAT32_C(   557.12), SIMDE_FLOAT32_C(  -444.80), SIMDE_FLOAT32_C(  -278.01) },
       INT32_C(           3) },
    { SIMDE_FLOAT32_C(   -88.43),
      { SIMDE_FLOAT32_C(   -88.43), SIMDE_FLOAT32_C(  -162.64), SIMDE_FLOAT32_C(   136.08), SIMDE_FLOAT32_C(   284.45) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(   -56.88),
      { SIMDE_FLOAT32_C(   241.27), SIMDE_FLOAT32_C(   -56.88), SIMDE_FLOAT32_C(    -1.53), SIMDE_FLOAT32_C(  -841.12) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(   514.21),
      { SIMDE_FLOAT32_C(  -687.80), SIMDE_FLOAT32_C(  -889.79), SIMDE_FLOAT32_C(   514.21), SIMDE_FLOAT32_C(  -216.22) },
       INT32_C(           2) },
    { SIMDE_FLOAT32_C(  -681.62),
      { SIMDE_FLOAT32_C(  -136.95), SIMDE_FLOAT32_C(   169.15), SIMDE_FLOAT32_C(  -293.70), SIMDE_FLOAT32_C(  -681.62) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t val = simde_vld1q_f32(test_vec[i].val);
    simde_float32 a;
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst1q_lane_f32, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_f32(a, test_vec[i].a, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a;
    simde_float32x4_t val = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    const uint lane = lanes[i];
    simde_vst1q_lane_f32(&a, val, lane);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 val[2];
    int lane;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   521.90),
      { SIMDE_FLOAT64_C(   521.90), SIMDE_FLOAT64_C(  -472.06) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(  -745.36),
      { SIMDE_FLOAT64_C(  -586.76), SIMDE_FLOAT64_C(  -745.36) },
       INT32_C(           1) },
    { SIMDE_FLOAT64_C(   833.21),
      { SIMDE_FLOAT64_C(   833.21), SIMDE_FLOAT64_C(  -230.32) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(   228.92),
      { SIMDE_FLOAT64_C(   948.92), SIMDE_FLOAT64_C(   228.92) },
       INT32_C(           1) },
    { SIMDE_FLOAT64_C(   102.77),
      { SIMDE_FLOAT64_C(   102.77), SIMDE_FLOAT64_C(    74.33) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(   972.13),
      { SIMDE_FLOAT64_C(   437.97), SIMDE_FLOAT64_C(   972.13) },
       INT32_C(           1) },
    { SIMDE_FLOAT64_C(   896.14),
      { SIMDE_FLOAT64_C(   896.14), SIMDE_FLOAT64_C(    91.47) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(  -462.82),
      { SIMDE_FLOAT64_C(  -392.14), SIMDE_FLOAT64_C(  -462.82) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t val = simde_vld1q_f64(test_vec[i].val);
    simde_float64 a;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst1q_lane_f64, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_f64(a, test_vec[i].a, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a;
    simde_float64x2_t val = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    const uint lane = lanes[i];
    simde_vst1q_lane_f64(&a, val, lane);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t val[16];
    int lane;
  } test_vec[] = {
    { -INT8_C(   2),
      {  INT8_C(  74),  INT8_C(  57), -INT8_C(   2), -INT8_C(  13),  INT8_C(  54),  INT8_C(  95),  INT8_C(  36), -INT8_C( 117),
        -INT8_C( 126), -INT8_C(  27), -INT8_C(  19), -INT8_C(  94), -INT8_C(  73),  INT8_C(  84),  INT8_C(  45), -INT8_C( 105) },
       INT32_C(           2) },
    { -INT8_C(  47),
      {  INT8_C(  46),  INT8_C(  81), -INT8_C(  75),  INT8_C(  63), -INT8_C(  47),  INT8_C(  32),  INT8_C(  57), -INT8_C( 115),
         INT8_C( 108),  INT8_C(  37),  INT8_C(  83), -INT8_C(  59), -INT8_C(  67),  INT8_C(  34), -INT8_C( 112),  INT8_C(   7) },
       INT32_C(           4) },
    {  INT8_C(  29),
      {  INT8_C(  91), -INT8_C( 114), -INT8_C(   5), -INT8_C( 111), -INT8_C(  19),  INT8_C(  31),  INT8_C(  29),  INT8_C( 111),
         INT8_C(   4),  INT8_C(  10),  INT8_C(  18), -INT8_C(  68),  INT8_C(  94),  INT8_C(  63),  INT8_C(  83), -INT8_C( 115) },
       INT32_C(           6) },
    {  INT8_C(  42),
      { -INT8_C( 112),  INT8_C(   8), -INT8_C(  52),  INT8_C(  97),  INT8_C(  40),  INT8_C(   5), -INT8_C(  18), -INT8_C( 107),
         INT8_C(  42),  INT8_C(  66),  INT8_C(  90), -INT8_C(  24),  INT8_C( 100), -INT8_C(  22), -INT8_C(  17), -INT8_C(  65) },
       INT32_C(           8) },
    { -INT8_C(  54),
      {  INT8_C( 120), -INT8_C(  22),  INT8_C(  80),  INT8_C( 101),  INT8_C(   9),  INT8_C( 109), -INT8_C(  43),  INT8_C(  14),
         INT8_C( 119), -INT8_C(  25), -INT8_C(  54), -INT8_C(  42),  INT8_C(  38),  INT8_C(  29),  INT8_C(  99), -INT8_C(  74) },
       INT32_C(          10) },
    {  INT8_C(  39),
      {  INT8_C(  37),  INT8_C(  47),  INT8_C(  23),  INT8_C(  77),  INT8_C(  53),  INT8_C(   5), -INT8_C(  30),  INT8_C(  95),
         INT8_C(  71),  INT8_C(  61),  INT8_C(  71), -INT8_C(  85),  INT8_C(  39),  INT8_C(  55),  INT8_C( 106), -INT8_C(  96) },
       INT32_C(          12) },
    { -INT8_C(  99),
      {  INT8_C(  33), -INT8_C(  69),  INT8_C(   5),  INT8_C(  43),  INT8_C(  40), -INT8_C(  38),  INT8_C(  57), -INT8_C(  96),
        -INT8_C(  63),  INT8_C(   3),  INT8_C( 118), -INT8_C(  25),  INT8_C(  32), -INT8_C(  39), -INT8_C(  99),  INT8_C(  69) },
       INT32_C(          14) },
    {  INT8_C(  61),
      {  INT8_C(   8), -INT8_C(  76), -INT8_C( 110),  INT8_C(  61), -INT8_C(  70),  INT8_C( 117), -INT8_C(  99),  INT8_C(   1),
        -INT8_C(  78), -INT8_C(  28), -INT8_C(  83), -INT8_C(  39),  INT8_C(  27),  INT8_C(  23),  INT8_C( 121),  INT8_C(  61) },
       INT32_C(          15) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t val = simde_vld1q_s8(test_vec[i].val);
    int8_t a;
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst1q_lane_s8, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_i8(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 2, 4, 6, 8, 10, 12, 14, 15 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a;
    simde_int8x16_t val = simde_test_arm_neon_random_i8x16();
    const uint lane = lanes[i];
    simde_vst1q_lane_s8(&a, val, lane);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t val[8];
    int lane;
  } test_vec[] = {
    {  INT16_C( 23780),
      {  INT16_C( 23780),  INT16_C( 19170),  INT16_C( 16396), -INT16_C( 25092),  INT16_C(  4214), -INT16_C( 32078), -INT16_C( 29052),  INT16_C( 30694) },
       INT32_C(           0) },
    { -INT16_C( 28904),
      {  INT16_C(   511), -INT16_C( 28904), -INT16_C( 22919), -INT16_C( 13843),  INT16_C(  6751), -INT16_C(  1510), -INT16_C(  5103), -INT16_C(  2704) },
       INT32_C(           1) },
    {  INT16_C( 15507),
      {  INT16_C( 21320),  INT16_C( 21568),  INT16_C( 15507),  INT16_C(  2801), -INT16_C( 23476), -INT16_C( 12148),  INT16_C( 29234),  INT16_C( 12872) },
       INT32_C(           2) },
    {  INT16_C( 26038),
      {  INT16_C( 24692), -INT16_C(  4671), -INT16_C( 20730),  INT16_C( 26038), -INT16_C( 12087), -INT16_C(  9377), -INT16_C( 12100),  INT16_C(  1232) },
       INT32_C(           3) },
    {  INT16_C( 19694),
      {  INT16_C(  4131), -INT16_C( 18855),  INT16_C( 19020), -INT16_C( 26432),  INT16_C( 19694),  INT16_C(  8553), -INT16_C( 20033),  INT16_C( 13139) },
       INT32_C(           4) },
    {  INT16_C( 25192),
      {  INT16_C(  5137),  INT16_C(  6176), -INT16_C( 10557), -INT16_C( 29315), -INT16_C(  8794),  INT16_C( 25192),  INT16_C( 14509), -INT16_C( 12186) },
       INT32_C(           5) },
    {  INT16_C( 27720),
      { -INT16_C( 16567), -INT16_C( 27258),  INT16_C( 18186), -INT16_C(  2002), -INT16_C( 26733),  INT16_C( 21017),  INT16_C( 27720),  INT16_C( 22917) },
       INT32_C(           6) },
    { -INT16_C( 17591),
      { -INT16_C( 23167),  INT16_C( 17521), -INT16_C(  4229),  INT16_C(  8657),  INT16_C( 14796),  INT16_C( 31107), -INT16_C(  5518), -INT16_C( 17591) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t val = simde_vld1q_s16(test_vec[i].val);
    int16_t a;
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst1q_lane_s16, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_i16(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a;
    simde_int16x8_t val = simde_test_arm_neon_random_i16x8();
    const uint lane = lanes[i];
    simde_vst1q_lane_s16(&a, val, lane);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t val[4];
    int lane;
  } test_vec[] = {
    { -INT32_C(   407901645),
      { -INT32_C(   407901645), -INT32_C(  1768410816),  INT32_C(   630594925), -INT32_C(  1378185327) },
       INT32_C(           0) },
    { -INT32_C(  1750011511),
      {  INT32_C(    11366593), -INT32_C(  1750011511),  INT32_C(  2023889963),  INT32_C(  1010411273) },
       INT32_C(           1) },
    {  INT32_C(  1789722329),
      { -INT32_C(   769398639), -INT32_C(  2023179239),  INT32_C(  1789722329),  INT32_C(  1310164621) },
       INT32_C(           2) },
    { -INT32_C(   228551840),
      {  INT32_C(  2135868662), -INT32_C(   518586698),  INT32_C(   609859867), -INT32_C(   228551840) },
       INT32_C(           3) },
    { -INT32_C(  1782283397),
      { -INT32_C(  1782283397),  INT32_C(   404499519), -INT32_C(  1199388630),  INT32_C(  1158060622) },
       INT32_C(           0) },
    {  INT32_C(  1861606227),
      {  INT32_C(   348411230),  INT32_C(  1861606227), -INT32_C(   191737964),  INT32_C(  1575416546) },
       INT32_C(           1) },
    {  INT32_C(   632901846),
      { -INT32_C(  1242387850),  INT32_C(    30281430),  INT32_C(   632901846),  INT32_C(  1231732714) },
       INT32_C(           2) },
    { -INT32_C(   773752741),
      {  INT32_C(  1750937108), -INT32_C(  1646898423), -INT32_C(  2070779486), -INT32_C(   773752741) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t val = simde_vld1q_s32(test_vec[i].val);
    int32_t a;
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst1q_lane_s32, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_i32(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a;
    simde_int32x4_t val = simde_test_arm_neon_random_i32x4();
    const uint lane = lanes[i];
    simde_vst1q_lane_s32(&a, val, lane);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t val[2];
    int lane;
 } test_vec[] = {
    { -INT64_C( 2426938743921840642),
      { -INT64_C( 2426938743921840642),  INT64_C( 7093888712037390708) },
       INT32_C(           0) },
    {  INT64_C( 8177834832853814489),
      {  INT64_C( 7893852987986178362),  INT64_C( 8177834832853814489) },
       INT32_C(           1) },
    { -INT64_C( 6818477128198757266),
      { -INT64_C( 6818477128198757266),  INT64_C( 5536305007872607040) },
       INT32_C(           0) },
    {  INT64_C( 4621725464521429311),
      {  INT64_C( 6431125428008052569),  INT64_C( 4621725464521429311) },
       INT32_C(           1) },
    { -INT64_C( 2171543568441558769),
      { -INT64_C( 2171543568441558769), -INT64_C( 7709555375194483805) },
       INT32_C(           0) },
    { -INT64_C( 3527884484289751561),
      { -INT64_C( 7284389485093623793), -INT64_C( 3527884484289751561) },
       INT32_C(           1) },
    { -INT64_C( 8166177399901533399),
      { -INT64_C( 8166177399901533399),  INT64_C( 3966341036426723131) },
       INT32_C(           0) },
    { -INT64_C( 8623016287588913211),
      {  INT64_C( 1198994447883793070), -INT64_C( 8623016287588913211) },
       INT32_C(           1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t val = simde_vld1q_s64(test_vec[i].val);
    int64_t a;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst1q_lane_s64, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_i64(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a;
    simde_int64x2_t val = simde_test_arm_neon_random_i64x2();
    const uint lane = lanes[i];
    simde_vst1q_lane_s64(&a, val, lane);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t val[16];
    int lane;
  } test_vec[] = {
    { UINT8_C(151),
      { UINT8_C(151), UINT8_C( 83), UINT8_C(125), UINT8_C(109), UINT8_C(174), UINT8_C(214), UINT8_C( 29), UINT8_C(179),
        UINT8_C( 77), UINT8_C(149), UINT8_C(157), UINT8_C(193), UINT8_C( 32), UINT8_C(  6), UINT8_C(198), UINT8_C(243) },
       INT32_C(           0) },
    { UINT8_C(115),
      { UINT8_C(227), UINT8_C(151), UINT8_C(115), UINT8_C( 95), UINT8_C( 96), UINT8_C( 23), UINT8_C(103), UINT8_C( 20),
        UINT8_C(  9), UINT8_C(192), UINT8_C(138), UINT8_C( 13), UINT8_C(134), UINT8_C(240), UINT8_C(243), UINT8_C( 29) },
       INT32_C(           2) },
    { UINT8_C( 71),
      { UINT8_C( 67), UINT8_C(113), UINT8_C(139), UINT8_C(241), UINT8_C( 71), UINT8_C(168), UINT8_C(164), UINT8_C(149),
        UINT8_C( 61), UINT8_C( 66), UINT8_C( 86), UINT8_C( 93), UINT8_C( 72), UINT8_C( 28), UINT8_C( 80), UINT8_C( 43) },
       INT32_C(           4) },
    { UINT8_C( 40),
      { UINT8_C(179), UINT8_C(195), UINT8_C(139), UINT8_C( 20), UINT8_C(218), UINT8_C(242), UINT8_C( 40), UINT8_C(227),
        UINT8_C(178), UINT8_C(178), UINT8_C(241), UINT8_C( 56), UINT8_C(162), UINT8_C(228), UINT8_C( 86), UINT8_C(229) },
       INT32_C(           6) },
    { UINT8_C(189),
      { UINT8_C( 85), UINT8_C(225), UINT8_C(215), UINT8_C(157), UINT8_C(137), UINT8_C(123), UINT8_C( 50), UINT8_C(198),
        UINT8_C(189), UINT8_C(136), UINT8_C( 35), UINT8_C(  5), UINT8_C(165), UINT8_C(115), UINT8_C( 49), UINT8_C( 88) },
       INT32_C(           8) },
    { UINT8_C(152),
      { UINT8_C( 55), UINT8_C(188), UINT8_C(108), UINT8_C( 17), UINT8_C(174), UINT8_C(148), UINT8_C(245), UINT8_C( 96),
        UINT8_C( 70), UINT8_C(230), UINT8_C(152), UINT8_C(232), UINT8_C(202), UINT8_C(238), UINT8_C(206), UINT8_C( 32) },
       INT32_C(          10) },
    { UINT8_C(181),
      { UINT8_C(207), UINT8_C(165), UINT8_C(189), UINT8_C( 88), UINT8_C( 32), UINT8_C(239), UINT8_C( 30), UINT8_C(222),
        UINT8_C(119), UINT8_C( 65), UINT8_C(227), UINT8_C( 28), UINT8_C(181), UINT8_C( 20), UINT8_C(117), UINT8_C(236) },
       INT32_C(          12) },
    { UINT8_C(195),
      { UINT8_C(208), UINT8_C(225), UINT8_C(253), UINT8_C(126), UINT8_C(118), UINT8_C(242), UINT8_C(222), UINT8_C(188),
        UINT8_C(216), UINT8_C(119), UINT8_C(165), UINT8_C(163), UINT8_C(101), UINT8_C(115), UINT8_C(195), UINT8_C( 53) },
       INT32_C(          14) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t val = simde_vld1q_u8(test_vec[i].val);
    uint8_t a;
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst1q_lane_u8, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u8(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 2, 4, 6, 8, 10, 12, 14 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a;
    simde_uint8x16_t val = simde_test_arm_neon_random_u8x16();
    const uint lane = lanes[i];
    simde_vst1q_lane_u8(&a, val, lane);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t val[8];
    int lane;
  } test_vec[] = {
    { UINT16_C(43458),
      { UINT16_C(43458), UINT16_C(13306), UINT16_C(35769), UINT16_C(22726), UINT16_C(32286), UINT16_C( 4435), UINT16_C(23748), UINT16_C(58650) },
       INT32_C(           0) },
    { UINT16_C(23157),
      { UINT16_C(41658), UINT16_C(23157), UINT16_C(39294), UINT16_C(28061), UINT16_C(23415), UINT16_C(19135), UINT16_C(31134), UINT16_C(24696) },
       INT32_C(           1) },
    { UINT16_C(23037),
      { UINT16_C(29218), UINT16_C(56211), UINT16_C(23037), UINT16_C( 6964), UINT16_C(34775), UINT16_C(39725), UINT16_C(18403), UINT16_C(40576) },
       INT32_C(           2) },
    { UINT16_C( 2004),
      { UINT16_C(63209), UINT16_C(26616), UINT16_C(38287), UINT16_C( 2004), UINT16_C(37873), UINT16_C(36689), UINT16_C(51468), UINT16_C(12015) },
       INT32_C(           3) },
    { UINT16_C(33221),
      { UINT16_C(33339), UINT16_C(14602), UINT16_C(16091), UINT16_C(45652), UINT16_C(33221), UINT16_C(43086), UINT16_C(52936), UINT16_C(45382) },
       INT32_C(           4) },
    { UINT16_C(36180),
      { UINT16_C(16068), UINT16_C(21528), UINT16_C(60884), UINT16_C(50523), UINT16_C(44160), UINT16_C(36180), UINT16_C(17270), UINT16_C(45499) },
       INT32_C(           5) },
    { UINT16_C(46959),
      { UINT16_C(50629), UINT16_C(41194), UINT16_C(16131), UINT16_C(51282), UINT16_C(41152), UINT16_C(35185), UINT16_C(46959), UINT16_C(13114) },
       INT32_C(           6) },
    { UINT16_C(60342),
      { UINT16_C(21494), UINT16_C(51847), UINT16_C(57920), UINT16_C(49295), UINT16_C(58255), UINT16_C( 1357), UINT16_C( 2342), UINT16_C(60342) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t val = simde_vld1q_u16(test_vec[i].val);
    uint16_t a;
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst1q_lane_u16, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u16(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a;
    simde_uint16x8_t val = simde_test_arm_neon_random_u16x8();
    const uint lane = lanes[i];
    simde_vst1q_lane_u16(&a, val, lane);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t val[4];
    int lane;
  } test_vec[] = {
    { UINT32_C(2806064924),
      { UINT32_C(2806064924), UINT32_C(2135519540), UINT32_C(1714780091), UINT32_C( 822981959) },
       INT32_C(           0) },
    { UINT32_C( 476712139),
      { UINT32_C(3079758904), UINT32_C( 476712139), UINT32_C(1175560326), UINT32_C(2229864040) },
       INT32_C(           1) },
    { UINT32_C( 868095724),
      { UINT32_C(1630218797), UINT32_C(1474327708), UINT32_C( 868095724), UINT32_C(  57002955) },
       INT32_C(           2) },
    { UINT32_C(1538373934),
      { UINT32_C(4206556719), UINT32_C(2299995139), UINT32_C( 768551109), UINT32_C(1538373934) },
       INT32_C(           3) },
    { UINT32_C(2143149283),
      { UINT32_C(2143149283), UINT32_C(1037540689), UINT32_C(2121307571), UINT32_C(2407650656) },
       INT32_C(           0) },
    { UINT32_C( 626565216),
      { UINT32_C(3481877708), UINT32_C( 626565216), UINT32_C(4149356489), UINT32_C(3293774816) },
       INT32_C(           1) },
    { UINT32_C( 266329775),
      { UINT32_C( 826478816), UINT32_C(1634605741), UINT32_C( 266329775), UINT32_C(2157863348) },
       INT32_C(           2) },
    { UINT32_C(1500765305),
      { UINT32_C(4249823389), UINT32_C(2435033032), UINT32_C(2945021390), UINT32_C(1500765305) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t val = simde_vld1q_u32(test_vec[i].val);
    uint32_t a;
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst1q_lane_u32, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u32(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a;
    simde_uint32x4_t val = simde_test_arm_neon_random_u32x4();
    const uint lane = lanes[i];
    simde_vst1q_lane_u32(&a, val, lane);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t val[2];
    int lane;
  } test_vec[] = {
    { UINT64_C(16971928657155608481),
      { UINT64_C(16971928657155608481), UINT64_C( 4844228207813433367) },
       INT32_C(           0) },
    { UINT64_C(16041346042065173678),
      { UINT64_C( 1292742978285177726), UINT64_C(16041346042065173678) },
       INT32_C(           1) },
    { UINT64_C( 2718961477228275359),
      { UINT64_C( 2718961477228275359), UINT64_C(  391814847681421386) },
       INT32_C(           0) },
    { UINT64_C(15529282571677133160),
      { UINT64_C( 7962554083699327628), UINT64_C(15529282571677133160) },
       INT32_C(           1) },
    { UINT64_C(12101844403231370431),
      { UINT64_C(12101844403231370431), UINT64_C( 4994568648897444035) },
       INT32_C(           0) },
    { UINT64_C(14352207887664082717),
      { UINT64_C( 2410891140534635591), UINT64_C(14352207887664082717) },
       INT32_C(           1) },
    { UINT64_C(18156972424159352309),
      { UINT64_C(18156972424159352309), UINT64_C( 6646634741389250366) },
       INT32_C(           0) },
    { UINT64_C( 9338151759985132488),
      { UINT64_C( 4935339525449970339), UINT64_C( 9338151759985132488) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t val = simde_vld1q_u64(test_vec[i].val);
    uint64_t a;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst1q_lane_u64, HEDLEY_UNREACHABLE(), test_vec[i].lane, &a, val);
    simde_assert_equal_u64(a, test_vec[i].a);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_uint64x2_t val = simde_test_arm_neon_random_u64x2();
    const uint lane = lanes[i];
    simde_vst1q_lane_u64(&a, val, lane);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_lane_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_lane_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
