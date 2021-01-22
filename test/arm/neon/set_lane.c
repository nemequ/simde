#define SIMDE_TEST_ARM_NEON_INSN set_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/set_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vset_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 v[2];
    simde_float32 r[2];
    int lane;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -373.45),
      { SIMDE_FLOAT32_C(   -29.14), SIMDE_FLOAT32_C(  -643.20) },
      { SIMDE_FLOAT32_C(  -373.45), SIMDE_FLOAT32_C(  -643.20) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -393.25),
      { SIMDE_FLOAT32_C(   559.43), SIMDE_FLOAT32_C(   188.28) },
      { SIMDE_FLOAT32_C(   559.43), SIMDE_FLOAT32_C(  -393.25) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -417.57),
      { SIMDE_FLOAT32_C(  -310.73), SIMDE_FLOAT32_C(  -403.05) },
      { SIMDE_FLOAT32_C(  -417.57), SIMDE_FLOAT32_C(  -403.05) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(   648.73),
      { SIMDE_FLOAT32_C(  -615.41), SIMDE_FLOAT32_C(  -429.89) },
      { SIMDE_FLOAT32_C(  -615.41), SIMDE_FLOAT32_C(   648.73) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -883.49),
      { SIMDE_FLOAT32_C(   683.52), SIMDE_FLOAT32_C(  -808.37) },
      { SIMDE_FLOAT32_C(  -883.49), SIMDE_FLOAT32_C(  -808.37) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -958.79),
      { SIMDE_FLOAT32_C(  -189.00), SIMDE_FLOAT32_C(  -443.44) },
      { SIMDE_FLOAT32_C(  -189.00), SIMDE_FLOAT32_C(  -958.79) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -384.49),
      { SIMDE_FLOAT32_C(  -569.39), SIMDE_FLOAT32_C(    61.86) },
      { SIMDE_FLOAT32_C(  -384.49), SIMDE_FLOAT32_C(    61.86) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -147.57),
      { SIMDE_FLOAT32_C(  -852.16), SIMDE_FLOAT32_C(   891.56) },
      { SIMDE_FLOAT32_C(  -852.16), SIMDE_FLOAT32_C(  -147.57) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    simde_float32x2_t v = simde_vld1_f32(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vset_lane_f32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x2_t v = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    int lane = lanes[i];
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vset_lane_f32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 v[1];
    simde_float64 r[1];
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -818.08),
      { SIMDE_FLOAT64_C(  -697.80) },
      { SIMDE_FLOAT64_C(  -818.08) } },
    { SIMDE_FLOAT64_C(   601.34),
      { SIMDE_FLOAT64_C(   459.90) },
      { SIMDE_FLOAT64_C(   601.34) } },
    { SIMDE_FLOAT64_C(   447.26),
      { SIMDE_FLOAT64_C(  -758.22) },
      { SIMDE_FLOAT64_C(   447.26) } },
    { SIMDE_FLOAT64_C(   101.07),
      { SIMDE_FLOAT64_C(    15.34) },
      { SIMDE_FLOAT64_C(   101.07) } },
    { SIMDE_FLOAT64_C(    79.96),
      { SIMDE_FLOAT64_C(   259.71) },
      { SIMDE_FLOAT64_C(    79.96) } },
    { SIMDE_FLOAT64_C(  -390.89),
      { SIMDE_FLOAT64_C(   316.98) },
      { SIMDE_FLOAT64_C(  -390.89) } },
    { SIMDE_FLOAT64_C(   966.83),
      { SIMDE_FLOAT64_C(   767.40) },
      { SIMDE_FLOAT64_C(   966.83) } },
    { SIMDE_FLOAT64_C(  -253.76),
      { SIMDE_FLOAT64_C(  -391.61) },
      { SIMDE_FLOAT64_C(  -253.76) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    simde_float64x1_t v = simde_vld1_f64(test_vec[i].v);
    simde_float64x1_t r = simde_vset_lane_f64(a, v, 0);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64x1_t v = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vset_lane_f64(a, v, 0);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t v[8];
    int8_t r[8];
    int lane;
  } test_vec[] = {
    {  INT8_C(  70),
      { -INT8_C(  27),  INT8_C( 121), -INT8_C(  72), -INT8_C(  82),  INT8_C(  88), -INT8_C( 125), -INT8_C( 103),  INT8_C(  16) },
      {  INT8_C(  70),  INT8_C( 121), -INT8_C(  72), -INT8_C(  82),  INT8_C(  88), -INT8_C( 125), -INT8_C( 103),  INT8_C(  16) },
       INT32_C(           0) },
    { -INT8_C(  35),
      {  INT8_C( 110), -INT8_C(  50),  INT8_C(  63),  INT8_C(  98),  INT8_C(  28),  INT8_C( 122),      INT8_MAX, -INT8_C(  19) },
      {  INT8_C( 110), -INT8_C(  35),  INT8_C(  63),  INT8_C(  98),  INT8_C(  28),  INT8_C( 122),      INT8_MAX, -INT8_C(  19) },
       INT32_C(           1) },
    {  INT8_C(   7),
      {  INT8_C(  91),  INT8_C(  62),  INT8_C(  61), -INT8_C(  17),  INT8_C(  45), -INT8_C( 120), -INT8_C(  38),  INT8_C( 107) },
      {  INT8_C(  91),  INT8_C(  62),  INT8_C(   7), -INT8_C(  17),  INT8_C(  45), -INT8_C( 120), -INT8_C(  38),  INT8_C( 107) },
       INT32_C(           2) },
    { -INT8_C( 111),
      { -INT8_C( 115), -INT8_C( 114), -INT8_C(  44), -INT8_C(  45),  INT8_C( 115),  INT8_C(  77), -INT8_C( 117),  INT8_C(  33) },
      { -INT8_C( 115), -INT8_C( 114), -INT8_C(  44), -INT8_C( 111),  INT8_C( 115),  INT8_C(  77), -INT8_C( 117),  INT8_C(  33) },
       INT32_C(           3) },
    { -INT8_C(  91),
      {  INT8_C(  15), -INT8_C(  70), -INT8_C(  74), -INT8_C(  20),  INT8_C(  40), -INT8_C( 124),  INT8_C(  44), -INT8_C( 118) },
      {  INT8_C(  15), -INT8_C(  70), -INT8_C(  74), -INT8_C(  20), -INT8_C(  91), -INT8_C( 124),  INT8_C(  44), -INT8_C( 118) },
       INT32_C(           4) },
    { -INT8_C(  96),
      { -INT8_C(  90),  INT8_C(  10), -INT8_C( 114), -INT8_C(  83),  INT8_C( 101), -INT8_C(  52), -INT8_C(  22),  INT8_C(  84) },
      { -INT8_C(  90),  INT8_C(  10), -INT8_C( 114), -INT8_C(  83),  INT8_C( 101), -INT8_C(  96), -INT8_C(  22),  INT8_C(  84) },
       INT32_C(           5) },
    { -INT8_C(   7),
      {  INT8_C( 114),  INT8_C(  47),  INT8_C( 100),  INT8_C(   3), -INT8_C(  68), -INT8_C(  14), -INT8_C(  41), -INT8_C( 112) },
      {  INT8_C( 114),  INT8_C(  47),  INT8_C( 100),  INT8_C(   3), -INT8_C(  68), -INT8_C(  14), -INT8_C(   7), -INT8_C( 112) },
       INT32_C(           6) },
    {  INT8_C( 101),
      {  INT8_C(  37),  INT8_C(  27), -INT8_C( 121), -INT8_C(  54),  INT8_C(  42),  INT8_C(  65),      INT8_MIN,  INT8_C(  23) },
      {  INT8_C(  37),  INT8_C(  27), -INT8_C( 121), -INT8_C(  54),  INT8_C(  42),  INT8_C(  65),      INT8_MIN,  INT8_C( 101) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t a = test_vec[i].a;
    simde_int8x8_t v = simde_vld1_s8(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vset_lane_s8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    simde_int8x8_t v = simde_test_arm_neon_random_i8x8();
    int lane = lanes[i];
    simde_int8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vset_lane_s8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t v[4];
    int16_t r[4];
    int lane;
  } test_vec[] = {
    {  INT16_C( 25881),
      { -INT16_C( 12793), -INT16_C( 20903), -INT16_C( 17144), -INT16_C( 13187) },
      {  INT16_C( 25881), -INT16_C( 20903), -INT16_C( 17144), -INT16_C( 13187) },
       INT32_C(           0) },
    {  INT16_C(  8494),
      { -INT16_C(  5273),  INT16_C( 20093), -INT16_C(  7951), -INT16_C( 13815) },
      { -INT16_C(  5273),  INT16_C(  8494), -INT16_C(  7951), -INT16_C( 13815) },
       INT32_C(           1) },
    { -INT16_C(  6266),
      { -INT16_C( 23690), -INT16_C( 22694),  INT16_C( 22066), -INT16_C( 28727) },
      { -INT16_C( 23690), -INT16_C( 22694), -INT16_C(  6266), -INT16_C( 28727) },
       INT32_C(           2) },
    { -INT16_C(  7659),
      {  INT16_C(  7412),  INT16_C( 19888), -INT16_C( 17974),  INT16_C( 18443) },
      {  INT16_C(  7412),  INT16_C( 19888), -INT16_C( 17974), -INT16_C(  7659) },
       INT32_C(           3) },
    {  INT16_C( 14725),
      { -INT16_C(  4759), -INT16_C(  6363),  INT16_C(  5691),  INT16_C( 17607) },
      {  INT16_C( 14725), -INT16_C(  6363),  INT16_C(  5691),  INT16_C( 17607) },
       INT32_C(           0) },
    {  INT16_C( 20192),
      {  INT16_C( 22316), -INT16_C( 30991),  INT16_C(  9214), -INT16_C( 14372) },
      {  INT16_C( 22316),  INT16_C( 20192),  INT16_C(  9214), -INT16_C( 14372) },
       INT32_C(           1) },
    { -INT16_C(  3662),
      { -INT16_C( 22871),  INT16_C( 23054), -INT16_C(  9996), -INT16_C(   237) },
      { -INT16_C( 22871),  INT16_C( 23054), -INT16_C(  3662), -INT16_C(   237) },
       INT32_C(           2) },
    { -INT16_C( 26592),
      { -INT16_C( 30152),  INT16_C( 23941), -INT16_C( 16271),  INT16_C( 14451) },
      { -INT16_C( 30152),  INT16_C( 23941), -INT16_C( 16271), -INT16_C( 26592) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vset_lane_s16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int lane = lanes[i];
    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vset_lane_s16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t v[2];
    int32_t r[2];
    int lane;
  } test_vec[] = {
    {  INT32_C(  1781637630),
      {  INT32_C(  1014922503), -INT32_C(   800151665) },
      {  INT32_C(  1781637630), -INT32_C(   800151665) },
       INT32_C(           0) },
    { -INT32_C(  1747077392),
      { -INT32_C(  1502972235), -INT32_C(  1101704828) },
      { -INT32_C(  1502972235), -INT32_C(  1747077392) },
       INT32_C(           1) },
    {  INT32_C(  1015661746),
      {  INT32_C(   310432275),  INT32_C(  2071769460) },
      {  INT32_C(  1015661746),  INT32_C(  2071769460) },
       INT32_C(           0) },
    { -INT32_C(  1095239122),
      { -INT32_C(  1852963167),  INT32_C(  1915317180) },
      { -INT32_C(  1852963167), -INT32_C(  1095239122) },
       INT32_C(           1) },
    {  INT32_C(  1696109537),
      { -INT32_C(  1775997212),  INT32_C(  1171434802) },
      {  INT32_C(  1696109537),  INT32_C(  1171434802) },
       INT32_C(           0) },
    { -INT32_C(   212381057),
      {  INT32_C(   846123779),  INT32_C(  1878009549) },
      {  INT32_C(   846123779), -INT32_C(   212381057) },
       INT32_C(           1) },
    { -INT32_C(   402620884),
      { -INT32_C(   900060695), -INT32_C(  1607437380) },
      { -INT32_C(   402620884), -INT32_C(  1607437380) },
       INT32_C(           0) },
    {  INT32_C(   322393313),
      { -INT32_C(  2141714175),  INT32_C(  1601482844) },
      { -INT32_C(  2141714175),  INT32_C(   322393313) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vset_lane_s32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int lane = lanes[i];
    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vset_lane_s32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t v[1];
    int64_t r[1];
  } test_vec[] = {
    {  INT64_C( 8132893339551323787),
      { -INT64_C( 2277587063383407450) },
      {  INT64_C( 8132893339551323787) } },
    { -INT64_C( 1201043362115393959),
      { -INT64_C( 7370413409463753472) },
      { -INT64_C( 1201043362115393959) } },
    {  INT64_C( 5599798045544665310),
      {  INT64_C( 8341159202254534462) },
      {  INT64_C( 5599798045544665310) } },
    {  INT64_C( 1189717831917504294),
      { -INT64_C( 8320776697033939489) },
      {  INT64_C( 1189717831917504294) } },
    { -INT64_C( 2563242400167091335),
      { -INT64_C( 5779385468923819713) },
      { -INT64_C( 2563242400167091335) } },
    { -INT64_C( 3915944839153045370),
      { -INT64_C( 4998366386176223127) },
      { -INT64_C( 3915944839153045370) } },
    {  INT64_C( 4312839844605359200),
      { -INT64_C( 7112768106479183855) },
      {  INT64_C( 4312839844605359200) } },
    { -INT64_C( 5096990314087609201),
      { -INT64_C( 7606735666318083725) },
      { -INT64_C( 5096990314087609201) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde_int64x1_t v = simde_vld1_s64(test_vec[i].v);
    simde_int64x1_t r = simde_vset_lane_s64(a, v, 0);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    simde_int64x1_t v = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vset_lane_s64(a, v, 0);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t v[8];
    uint8_t r[8];
    int lane;
  } test_vec[] = {
    { UINT8_C(107),
      { UINT8_C(232), UINT8_C( 68), UINT8_C( 62), UINT8_C( 98), UINT8_C(251), UINT8_C(241), UINT8_C(101), UINT8_C( 54) },
      { UINT8_C(107), UINT8_C( 68), UINT8_C( 62), UINT8_C( 98), UINT8_C(251), UINT8_C(241), UINT8_C(101), UINT8_C( 54) },
       INT32_C(           0) },
    { UINT8_C(150),
      { UINT8_C( 83), UINT8_C( 39), UINT8_C(121), UINT8_C(113), UINT8_C(247), UINT8_C( 41), UINT8_C(120), UINT8_C(159) },
      { UINT8_C( 83), UINT8_C(150), UINT8_C(121), UINT8_C(113), UINT8_C(247), UINT8_C( 41), UINT8_C(120), UINT8_C(159) },
       INT32_C(           1) },
    { UINT8_C(173),
      { UINT8_C(167), UINT8_C( 57), UINT8_C(216), UINT8_C( 30), UINT8_C( 55), UINT8_C( 36), UINT8_C(109), UINT8_C(248) },
      { UINT8_C(167), UINT8_C( 57), UINT8_C(173), UINT8_C( 30), UINT8_C( 55), UINT8_C( 36), UINT8_C(109), UINT8_C(248) },
       INT32_C(           2) },
    { UINT8_C( 60),
      { UINT8_C(242), UINT8_C(234), UINT8_C(103), UINT8_C( 93), UINT8_C(211), UINT8_C(171), UINT8_C(155), UINT8_C( 53) },
      { UINT8_C(242), UINT8_C(234), UINT8_C(103), UINT8_C( 60), UINT8_C(211), UINT8_C(171), UINT8_C(155), UINT8_C( 53) },
       INT32_C(           3) },
    { UINT8_C(167),
      { UINT8_C(141), UINT8_C(154), UINT8_C(221), UINT8_C( 35), UINT8_C(237), UINT8_C(  5), UINT8_C(156), UINT8_C( 95) },
      { UINT8_C(141), UINT8_C(154), UINT8_C(221), UINT8_C( 35), UINT8_C(167), UINT8_C(  5), UINT8_C(156), UINT8_C( 95) },
       INT32_C(           4) },
    { UINT8_C(252),
      { UINT8_C(198), UINT8_C(215), UINT8_C(155), UINT8_C(115), UINT8_C(126), UINT8_C(212), UINT8_C( 76), UINT8_C(156) },
      { UINT8_C(198), UINT8_C(215), UINT8_C(155), UINT8_C(115), UINT8_C(126), UINT8_C(252), UINT8_C( 76), UINT8_C(156) },
       INT32_C(           5) },
    { UINT8_C( 11),
      { UINT8_C(112), UINT8_C( 10), UINT8_C(  4), UINT8_C(172), UINT8_C(252), UINT8_C(238), UINT8_C( 19), UINT8_C( 89) },
      { UINT8_C(112), UINT8_C( 10), UINT8_C(  4), UINT8_C(172), UINT8_C(252), UINT8_C(238), UINT8_C( 11), UINT8_C( 89) },
       INT32_C(           6) },
    { UINT8_C(193),
      { UINT8_C(191), UINT8_C(245), UINT8_C(246), UINT8_C(102), UINT8_C(130), UINT8_C(144), UINT8_C( 67), UINT8_C(165) },
      { UINT8_C(191), UINT8_C(245), UINT8_C(246), UINT8_C(102), UINT8_C(130), UINT8_C(144), UINT8_C( 67), UINT8_C(193) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t a = test_vec[i].a;
    simde_uint8x8_t v = simde_vld1_u8(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vset_lane_u8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    simde_uint8x8_t v = simde_test_arm_neon_random_u8x8();
    int lane = lanes[i];
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vset_lane_u8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t v[4];
    uint16_t r[4];
    int lane;
  } test_vec[] = {
    { UINT16_C(45765),
      { UINT16_C(30953), UINT16_C(24357), UINT16_C( 4588), UINT16_C(51685) },
      { UINT16_C(45765), UINT16_C(24357), UINT16_C( 4588), UINT16_C(51685) },
       INT32_C(           0) },
    { UINT16_C( 3768),
      { UINT16_C(49965), UINT16_C(13884), UINT16_C( 6907), UINT16_C(15397) },
      { UINT16_C(49965), UINT16_C( 3768), UINT16_C( 6907), UINT16_C(15397) },
       INT32_C(           1) },
    { UINT16_C(43298),
      { UINT16_C(51529), UINT16_C(   48), UINT16_C(59229), UINT16_C(37787) },
      { UINT16_C(51529), UINT16_C(   48), UINT16_C(43298), UINT16_C(37787) },
       INT32_C(           2) },
    { UINT16_C(24647),
      { UINT16_C(12357), UINT16_C(27352), UINT16_C(50320), UINT16_C(30075) },
      { UINT16_C(12357), UINT16_C(27352), UINT16_C(50320), UINT16_C(24647) },
       INT32_C(           3) },
    { UINT16_C(13197),
      { UINT16_C(47747), UINT16_C(49143), UINT16_C(62192), UINT16_C( 5594) },
      { UINT16_C(13197), UINT16_C(49143), UINT16_C(62192), UINT16_C( 5594) },
       INT32_C(           0) },
    { UINT16_C(64558),
      { UINT16_C(30654), UINT16_C(61125), UINT16_C( 8823), UINT16_C( 4821) },
      { UINT16_C(30654), UINT16_C(64558), UINT16_C( 8823), UINT16_C( 4821) },
       INT32_C(           1) },
    { UINT16_C( 7349),
      { UINT16_C(64114), UINT16_C(19021), UINT16_C(56676), UINT16_C(57358) },
      { UINT16_C(64114), UINT16_C(19021), UINT16_C( 7349), UINT16_C(57358) },
       INT32_C(           2) },
    { UINT16_C(39762),
      { UINT16_C(54547), UINT16_C( 2645), UINT16_C(17812), UINT16_C(28412) },
      { UINT16_C(54547), UINT16_C( 2645), UINT16_C(17812), UINT16_C(39762) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t a = test_vec[i].a;
    simde_uint16x4_t v = simde_vld1_u16(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vset_lane_u16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    int lane = lanes[i];
    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vset_lane_u16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t v[2];
    uint32_t r[2];
    int lane;
  } test_vec[] = {
    { UINT32_C(3686056461),
      { UINT32_C(3107362155), UINT32_C(1460699361) },
      { UINT32_C(3686056461), UINT32_C(1460699361) },
       INT32_C(           0) },
    { UINT32_C(2717558461),
      { UINT32_C(4167524849), UINT32_C(3776814077) },
      { UINT32_C(4167524849), UINT32_C(2717558461) },
       INT32_C(           1) },
    { UINT32_C(3227136249),
      { UINT32_C(2690237075), UINT32_C(4017819012) },
      { UINT32_C(3227136249), UINT32_C(4017819012) },
       INT32_C(           0) },
    { UINT32_C(2208871074),
      { UINT32_C(4024088626), UINT32_C(1334891870) },
      { UINT32_C(4024088626), UINT32_C(2208871074) },
       INT32_C(           1) },
    { UINT32_C( 860420150),
      { UINT32_C(2366924179), UINT32_C( 676163477) },
      { UINT32_C( 860420150), UINT32_C( 676163477) },
       INT32_C(           0) },
    { UINT32_C(3049825841),
      { UINT32_C(1453606068), UINT32_C( 685395190) },
      { UINT32_C(1453606068), UINT32_C(3049825841) },
       INT32_C(           1) },
    { UINT32_C(1645720580),
      { UINT32_C(3216156553), UINT32_C( 871561887) },
      { UINT32_C(1645720580), UINT32_C( 871561887) },
       INT32_C(           0) },
    { UINT32_C(4106225503),
      { UINT32_C(2803699062), UINT32_C(1750918580) },
      { UINT32_C(2803699062), UINT32_C(4106225503) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    simde_uint32x2_t v = simde_vld1_u32(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vset_lane_u32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    int lane = lanes[i];
    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vset_lane_u32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vset_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t v[1];
    uint64_t r[1];
    int lane;
  } test_vec[] = {
    { UINT64_C( 6406044039131507225),
      { UINT64_C( 1703588918030527433) },
      { UINT64_C( 6406044039131507225) },
       INT32_C(           0) },
    { UINT64_C( 6803362325393349286),
      { UINT64_C( 9198016635619938545) },
      { UINT64_C( 6803362325393349286) },
       INT32_C(           0) },
    { UINT64_C( 4002095255047804694),
      { UINT64_C( 1073592190821075895) },
      { UINT64_C( 4002095255047804694) },
       INT32_C(           0) },
    { UINT64_C(10745787330633285317),
      { UINT64_C( 7217255135707226948) },
      { UINT64_C(10745787330633285317) },
       INT32_C(           0) },
    { UINT64_C(10597851576315383662),
      { UINT64_C( 9917851913051871532) },
      { UINT64_C(10597851576315383662) },
       INT32_C(           0) },
    { UINT64_C(16555350570174246279),
      { UINT64_C( 3999680018493928142) },
      { UINT64_C(16555350570174246279) },
       INT32_C(           0) },
    { UINT64_C( 7400582118781425734),
      { UINT64_C(16649137534843688896) },
      { UINT64_C( 7400582118781425734) },
       INT32_C(           0) },
    { UINT64_C(10525426639353108619),
      { UINT64_C(11296488388647952325) },
      { UINT64_C(10525426639353108619) },
       INT32_C(           0) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a;
    simde_uint64x1_t v = simde_vld1_u64(test_vec[i].v);
    simde_uint64x1_t r = simde_vset_lane_u64(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    simde_uint64x1_t v = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_vset_lane_u64(a, v, 0);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 v[4];
    simde_float32 r[4];
    int lane;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   571.97),
      { SIMDE_FLOAT32_C(  -685.65), SIMDE_FLOAT32_C(   527.31), SIMDE_FLOAT32_C(   563.52), SIMDE_FLOAT32_C(  -329.90) },
      { SIMDE_FLOAT32_C(   571.97), SIMDE_FLOAT32_C(   527.31), SIMDE_FLOAT32_C(   563.52), SIMDE_FLOAT32_C(  -329.90) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -413.88),
      { SIMDE_FLOAT32_C(   284.95), SIMDE_FLOAT32_C(  -150.39), SIMDE_FLOAT32_C(  -996.77), SIMDE_FLOAT32_C(  -669.25) },
      { SIMDE_FLOAT32_C(   284.95), SIMDE_FLOAT32_C(  -413.88), SIMDE_FLOAT32_C(  -996.77), SIMDE_FLOAT32_C(  -669.25) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(   -28.31),
      { SIMDE_FLOAT32_C(  -917.74), SIMDE_FLOAT32_C(   704.61), SIMDE_FLOAT32_C(  -331.98), SIMDE_FLOAT32_C(   790.85) },
      { SIMDE_FLOAT32_C(  -917.74), SIMDE_FLOAT32_C(   704.61), SIMDE_FLOAT32_C(   -28.31), SIMDE_FLOAT32_C(   790.85) },
       INT32_C(           2) },
    { SIMDE_FLOAT32_C(  -568.07),
      { SIMDE_FLOAT32_C(   411.05), SIMDE_FLOAT32_C(  -327.15), SIMDE_FLOAT32_C(  -816.35), SIMDE_FLOAT32_C(  -260.46) },
      { SIMDE_FLOAT32_C(   411.05), SIMDE_FLOAT32_C(  -327.15), SIMDE_FLOAT32_C(  -816.35), SIMDE_FLOAT32_C(  -568.07) },
       INT32_C(           3) },
    { SIMDE_FLOAT32_C(  -649.49),
      { SIMDE_FLOAT32_C(   712.24), SIMDE_FLOAT32_C(  -363.52), SIMDE_FLOAT32_C(  -141.46), SIMDE_FLOAT32_C(  -532.55) },
      { SIMDE_FLOAT32_C(  -649.49), SIMDE_FLOAT32_C(  -363.52), SIMDE_FLOAT32_C(  -141.46), SIMDE_FLOAT32_C(  -532.55) },
       INT32_C(           0) },
    { SIMDE_FLOAT32_C(  -673.98),
      { SIMDE_FLOAT32_C(  -328.33), SIMDE_FLOAT32_C(  -599.26), SIMDE_FLOAT32_C(   253.06), SIMDE_FLOAT32_C(    22.83) },
      { SIMDE_FLOAT32_C(  -328.33), SIMDE_FLOAT32_C(  -673.98), SIMDE_FLOAT32_C(   253.06), SIMDE_FLOAT32_C(    22.83) },
       INT32_C(           1) },
    { SIMDE_FLOAT32_C(  -654.71),
      { SIMDE_FLOAT32_C(  -174.97), SIMDE_FLOAT32_C(   337.18), SIMDE_FLOAT32_C(   872.60), SIMDE_FLOAT32_C(  -611.45) },
      { SIMDE_FLOAT32_C(  -174.97), SIMDE_FLOAT32_C(   337.18), SIMDE_FLOAT32_C(  -654.71), SIMDE_FLOAT32_C(  -611.45) },
       INT32_C(           2) },
    { SIMDE_FLOAT32_C(  -992.72),
      { SIMDE_FLOAT32_C(  -541.28), SIMDE_FLOAT32_C(   673.50), SIMDE_FLOAT32_C(  -143.10), SIMDE_FLOAT32_C(  -538.05) },
      { SIMDE_FLOAT32_C(  -541.28), SIMDE_FLOAT32_C(   673.50), SIMDE_FLOAT32_C(  -143.10), SIMDE_FLOAT32_C(  -992.72) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsetq_lane_f32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x4_t v = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    int lane = lanes[i];
    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsetq_lane_f32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 v[2];
    simde_float64 r[2];
    int lane;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   293.82),
      { SIMDE_FLOAT64_C(   297.03), SIMDE_FLOAT64_C(   420.15) },
      { SIMDE_FLOAT64_C(   293.82), SIMDE_FLOAT64_C(   420.15) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(  -258.58),
      { SIMDE_FLOAT64_C(   -13.57), SIMDE_FLOAT64_C(  -351.16) },
      { SIMDE_FLOAT64_C(   -13.57), SIMDE_FLOAT64_C(  -258.58) },
       INT32_C(           1) },
    { SIMDE_FLOAT64_C(   926.74),
      { SIMDE_FLOAT64_C(   398.53), SIMDE_FLOAT64_C(   288.03) },
      { SIMDE_FLOAT64_C(   926.74), SIMDE_FLOAT64_C(   288.03) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(   471.78),
      { SIMDE_FLOAT64_C(    53.12), SIMDE_FLOAT64_C(    54.20) },
      { SIMDE_FLOAT64_C(    53.12), SIMDE_FLOAT64_C(   471.78) },
       INT32_C(           1) },
    { SIMDE_FLOAT64_C(  -866.38),
      { SIMDE_FLOAT64_C(  -780.75), SIMDE_FLOAT64_C(   -71.08) },
      { SIMDE_FLOAT64_C(  -866.38), SIMDE_FLOAT64_C(   -71.08) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(   629.85),
      { SIMDE_FLOAT64_C(  -883.80), SIMDE_FLOAT64_C(   -25.61) },
      { SIMDE_FLOAT64_C(  -883.80), SIMDE_FLOAT64_C(   629.85) },
       INT32_C(           1) },
    { SIMDE_FLOAT64_C(  -974.10),
      { SIMDE_FLOAT64_C(   564.55), SIMDE_FLOAT64_C(   339.50) },
      { SIMDE_FLOAT64_C(  -974.10), SIMDE_FLOAT64_C(   339.50) },
       INT32_C(           0) },
    { SIMDE_FLOAT64_C(  -659.40),
      { SIMDE_FLOAT64_C(   273.60), SIMDE_FLOAT64_C(  -218.27) },
      { SIMDE_FLOAT64_C(   273.60), SIMDE_FLOAT64_C(  -659.40) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vsetq_lane_f64, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64x2_t v = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = lanes[i];
    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vsetq_lane_f64, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t v[16];
    int8_t r[16];
    int lane;
  } test_vec[] = {
    {  INT8_C( 105),
      { -INT8_C(  61),  INT8_C(  86), -INT8_C( 122), -INT8_C(  74), -INT8_C(  57), -INT8_C(  79), -INT8_C( 121),  INT8_C( 110),
        -INT8_C(  44), -INT8_C(  76),  INT8_C(  11),  INT8_C(  25), -INT8_C(  43), -INT8_C(  10), -INT8_C( 114), -INT8_C(  86) },
      {  INT8_C( 105),  INT8_C(  86), -INT8_C( 122), -INT8_C(  74), -INT8_C(  57), -INT8_C(  79), -INT8_C( 121),  INT8_C( 110),
        -INT8_C(  44), -INT8_C(  76),  INT8_C(  11),  INT8_C(  25), -INT8_C(  43), -INT8_C(  10), -INT8_C( 114), -INT8_C(  86) },
       INT32_C(           0) },
    { -INT8_C(  77),
      { -INT8_C( 110), -INT8_C( 116),  INT8_C(  44),  INT8_C(  10), -INT8_C(  39),  INT8_C(  68),  INT8_C(  90),  INT8_C(  84),
         INT8_C(  29),  INT8_C(  44),  INT8_C( 113), -INT8_C(  70), -INT8_C(  40), -INT8_C(  38),  INT8_C( 125),  INT8_C(  47) },
      { -INT8_C( 110), -INT8_C( 116), -INT8_C(  77),  INT8_C(  10), -INT8_C(  39),  INT8_C(  68),  INT8_C(  90),  INT8_C(  84),
         INT8_C(  29),  INT8_C(  44),  INT8_C( 113), -INT8_C(  70), -INT8_C(  40), -INT8_C(  38),  INT8_C( 125),  INT8_C(  47) },
       INT32_C(           2) },
    {  INT8_C(  96),
      {  INT8_C(  51), -INT8_C(  10),  INT8_C(  17), -INT8_C(  70),  INT8_C( 100), -INT8_C(  26),  INT8_C( 111),  INT8_C( 112),
        -INT8_C(   1),  INT8_C(  68),  INT8_C( 102), -INT8_C( 115), -INT8_C(  18),  INT8_C(  25),  INT8_C(  32),  INT8_C( 123) },
      {  INT8_C(  51), -INT8_C(  10),  INT8_C(  17), -INT8_C(  70),  INT8_C(  96), -INT8_C(  26),  INT8_C( 111),  INT8_C( 112),
        -INT8_C(   1),  INT8_C(  68),  INT8_C( 102), -INT8_C( 115), -INT8_C(  18),  INT8_C(  25),  INT8_C(  32),  INT8_C( 123) },
       INT32_C(           4) },
    {  INT8_C(  70),
      {  INT8_C(  42),  INT8_C(  84), -INT8_C( 118), -INT8_C( 123), -INT8_C(  87), -INT8_C(  88), -INT8_C(  79),  INT8_C(  26),
         INT8_C(  98), -INT8_C( 119), -INT8_C(  12), -INT8_C(  33), -INT8_C(  72),  INT8_C(  85),  INT8_C(  19), -INT8_C(  81) },
      {  INT8_C(  42),  INT8_C(  84), -INT8_C( 118), -INT8_C( 123), -INT8_C(  87), -INT8_C(  88),  INT8_C(  70),  INT8_C(  26),
         INT8_C(  98), -INT8_C( 119), -INT8_C(  12), -INT8_C(  33), -INT8_C(  72),  INT8_C(  85),  INT8_C(  19), -INT8_C(  81) },
       INT32_C(           6) },
    {  INT8_C( 102),
      { -INT8_C(  51),  INT8_C(  19),  INT8_C(  76),  INT8_C(  60), -INT8_C( 125),  INT8_C(  75), -INT8_C( 127), -INT8_C(  23),
        -INT8_C(  39),  INT8_C( 111),  INT8_C(   3), -INT8_C(   7), -INT8_C(  22),  INT8_C(  73),  INT8_C(  35),  INT8_C(  63) },
      { -INT8_C(  51),  INT8_C(  19),  INT8_C(  76),  INT8_C(  60), -INT8_C( 125),  INT8_C(  75), -INT8_C( 127), -INT8_C(  23),
        -INT8_C(  39),  INT8_C( 102),  INT8_C(   3), -INT8_C(   7), -INT8_C(  22),  INT8_C(  73),  INT8_C(  35),  INT8_C(  63) },
       INT32_C(           9) },
    { -INT8_C(  45),
      { -INT8_C(  88), -INT8_C(  24),  INT8_C( 123),  INT8_C(  89),  INT8_C(   2), -INT8_C(  35), -INT8_C(  29), -INT8_C(  10),
        -INT8_C(  67), -INT8_C( 101),  INT8_C(  75), -INT8_C(  48),  INT8_C(  74), -INT8_C(  78), -INT8_C(  99),  INT8_C(  94) },
      { -INT8_C(  88), -INT8_C(  24),  INT8_C( 123),  INT8_C(  89),  INT8_C(   2), -INT8_C(  35), -INT8_C(  29), -INT8_C(  10),
        -INT8_C(  67), -INT8_C( 101), -INT8_C(  45), -INT8_C(  48),  INT8_C(  74), -INT8_C(  78), -INT8_C(  99),  INT8_C(  94) },
       INT32_C(          10) },
    { -INT8_C(   2),
      { -INT8_C(  38), -INT8_C(  31),  INT8_C(  74),  INT8_C(  91), -INT8_C(  53),  INT8_C(  35), -INT8_C(  54), -INT8_C(  50),
         INT8_C(  28), -INT8_C(  75),  INT8_C(  23),  INT8_C(  63), -INT8_C(  12), -INT8_C(  22), -INT8_C(  24), -INT8_C(  36) },
      { -INT8_C(  38), -INT8_C(  31),  INT8_C(  74),  INT8_C(  91), -INT8_C(  53),  INT8_C(  35), -INT8_C(  54), -INT8_C(  50),
         INT8_C(  28), -INT8_C(  75),  INT8_C(  23), -INT8_C(   2), -INT8_C(  12), -INT8_C(  22), -INT8_C(  24), -INT8_C(  36) },
       INT32_C(          11) },
    {  INT8_C( 102),
      {  INT8_C(  65), -INT8_C(  34),  INT8_C(  67),  INT8_C(  36), -INT8_C(  44),  INT8_C(   0), -INT8_C(  64),  INT8_C(  32),
        -INT8_C(  48),  INT8_C(  10), -INT8_C(  46),  INT8_C( 110),  INT8_C( 104), -INT8_C(  48),  INT8_C(  72),  INT8_C(  74) },
      {  INT8_C(  65), -INT8_C(  34),  INT8_C(  67),  INT8_C(  36), -INT8_C(  44),  INT8_C(   0), -INT8_C(  64),  INT8_C(  32),
        -INT8_C(  48),  INT8_C(  10), -INT8_C(  46),  INT8_C( 110),  INT8_C( 102), -INT8_C(  48),  INT8_C(  72),  INT8_C(  74) },
       INT32_C(          12) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t a = test_vec[i].a;
    simde_int8x16_t v = simde_vld1q_s8(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vsetq_lane_s8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 2, 4, 6, 9, 10, 11, 12 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    simde_int8x16_t v = simde_test_arm_neon_random_i8x16();
    int lane = lanes[i];
    simde_int8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vsetq_lane_s8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t v[8];
    int16_t r[8];
    int lane;
  } test_vec[] = {
    {  INT16_C(  4491),
      { -INT16_C(  7694),  INT16_C( 31799),  INT16_C( 16694), -INT16_C( 15473), -INT16_C(  6552), -INT16_C(  9167), -INT16_C( 11511), -INT16_C( 19751) },
      {  INT16_C(  4491),  INT16_C( 31799),  INT16_C( 16694), -INT16_C( 15473), -INT16_C(  6552), -INT16_C(  9167), -INT16_C( 11511), -INT16_C( 19751) },
       INT32_C(           0) },
    { -INT16_C( 24147),
      { -INT16_C( 11711),  INT16_C(  7395), -INT16_C( 25881), -INT16_C( 25843), -INT16_C( 25342), -INT16_C( 29124),  INT16_C( 11951), -INT16_C(  6545) },
      { -INT16_C( 11711), -INT16_C( 24147), -INT16_C( 25881), -INT16_C( 25843), -INT16_C( 25342), -INT16_C( 29124),  INT16_C( 11951), -INT16_C(  6545) },
       INT32_C(           1) },
    { -INT16_C( 23125),
      {  INT16_C( 14887), -INT16_C( 28567), -INT16_C( 26080),  INT16_C( 10604),  INT16_C( 18030),  INT16_C(  7131),  INT16_C(  7655), -INT16_C( 13586) },
      {  INT16_C( 14887), -INT16_C( 28567), -INT16_C( 23125),  INT16_C( 10604),  INT16_C( 18030),  INT16_C(  7131),  INT16_C(  7655), -INT16_C( 13586) },
       INT32_C(           2) },
    { -INT16_C( 10951),
      {  INT16_C( 18276),  INT16_C( 26480), -INT16_C( 21020), -INT16_C( 27659),  INT16_C( 25819), -INT16_C( 31110), -INT16_C( 24310),  INT16_C( 29632) },
      {  INT16_C( 18276),  INT16_C( 26480), -INT16_C( 21020), -INT16_C( 10951),  INT16_C( 25819), -INT16_C( 31110), -INT16_C( 24310),  INT16_C( 29632) },
       INT32_C(           3) },
    { -INT16_C(  8143),
      { -INT16_C( 25075),  INT16_C( 31497), -INT16_C(  6684), -INT16_C( 13417), -INT16_C( 31486),  INT16_C( 15254), -INT16_C(  1446), -INT16_C( 13694) },
      { -INT16_C( 25075),  INT16_C( 31497), -INT16_C(  6684), -INT16_C( 13417), -INT16_C(  8143),  INT16_C( 15254), -INT16_C(  1446), -INT16_C( 13694) },
       INT32_C(           4) },
    {  INT16_C( 26465),
      {  INT16_C( 22135),  INT16_C( 21498),  INT16_C( 29883), -INT16_C( 14887), -INT16_C( 26090),  INT16_C( 18232),  INT16_C( 17786), -INT16_C( 31515) },
      {  INT16_C( 22135),  INT16_C( 21498),  INT16_C( 29883), -INT16_C( 14887), -INT16_C( 26090),  INT16_C( 26465),  INT16_C( 17786), -INT16_C( 31515) },
       INT32_C(           5) },
    { -INT16_C( 13887),
      {  INT16_C( 22633),  INT16_C( 27541),  INT16_C( 11229),  INT16_C( 14246),  INT16_C( 10533), -INT16_C( 30975),  INT16_C( 31120), -INT16_C( 29987) },
      {  INT16_C( 22633),  INT16_C( 27541),  INT16_C( 11229),  INT16_C( 14246),  INT16_C( 10533), -INT16_C( 30975), -INT16_C( 13887), -INT16_C( 29987) },
       INT32_C(           6) },
    { -INT16_C( 26420),
      { -INT16_C( 23041),  INT16_C(  5469), -INT16_C( 27329), -INT16_C( 17828),  INT16_C( 17115), -INT16_C( 25538), -INT16_C( 22773), -INT16_C( 24332) },
      { -INT16_C( 23041),  INT16_C(  5469), -INT16_C( 27329), -INT16_C( 17828),  INT16_C( 17115), -INT16_C( 25538), -INT16_C( 22773), -INT16_C( 26420) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vsetq_lane_s16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    int lane = lanes[i];
    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vsetq_lane_s16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t v[4];
    int32_t r[4];
    int lane;
  } test_vec[] = {
    {  INT32_C(   963230229),
      { -INT32_C(    66824687), -INT32_C(  1083756224),  INT32_C(   656723093), -INT32_C(  1485455016) },
      {  INT32_C(   963230229), -INT32_C(  1083756224),  INT32_C(   656723093), -INT32_C(  1485455016) },
       INT32_C(           0) },
    { -INT32_C(   554431575),
      {  INT32_C(   944199529),  INT32_C(   422117123), -INT32_C(   900558407),  INT32_C(   684152807) },
      {  INT32_C(   944199529), -INT32_C(   554431575), -INT32_C(   900558407),  INT32_C(   684152807) },
       INT32_C(           1) },
    {  INT32_C(   501689992),
      {  INT32_C(  1380191482),  INT32_C(  1996143053),  INT32_C(   760606404),  INT32_C(  1231461445) },
      {  INT32_C(  1380191482),  INT32_C(  1996143053),  INT32_C(   501689992),  INT32_C(  1231461445) },
       INT32_C(           2) },
    {  INT32_C(  1432522395),
      {  INT32_C(   119518239), -INT32_C(  1825577461),  INT32_C(   246486548), -INT32_C(   278792926) },
      {  INT32_C(   119518239), -INT32_C(  1825577461),  INT32_C(   246486548),  INT32_C(  1432522395) },
       INT32_C(           3) },
    {  INT32_C(  1936087983),
      { -INT32_C(  1885226167), -INT32_C(   220723369), -INT32_C(  1270400363), -INT32_C(    88381458) },
      {  INT32_C(  1936087983), -INT32_C(   220723369), -INT32_C(  1270400363), -INT32_C(    88381458) },
       INT32_C(           0) },
    {  INT32_C(  1653467725),
      {  INT32_C(   594558465), -INT32_C(   485240524),  INT32_C(  1985378604), -INT32_C(  1962543308) },
      {  INT32_C(   594558465),  INT32_C(  1653467725),  INT32_C(  1985378604), -INT32_C(  1962543308) },
       INT32_C(           1) },
    { -INT32_C(  1820467714),
      {  INT32_C(    88655127),  INT32_C(  2046755628), -INT32_C(   270823954), -INT32_C(    15577909) },
      {  INT32_C(    88655127),  INT32_C(  2046755628), -INT32_C(  1820467714), -INT32_C(    15577909) },
       INT32_C(           2) },
    {  INT32_C(  1256334621),
      { -INT32_C(   759154274),  INT32_C(   794674480), -INT32_C(  1178412126), -INT32_C(   859960672) },
      { -INT32_C(   759154274),  INT32_C(   794674480), -INT32_C(  1178412126),  INT32_C(  1256334621) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsetq_lane_s32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int lane = lanes[i];
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsetq_lane_s32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t v[2];
    int64_t r[2];
    int lane;
  } test_vec[] = {
    { -INT64_C( 6275848456464942524),
      { -INT64_C( 1023053585428821105), -INT64_C( 1413666450029352452) },
      { -INT64_C( 6275848456464942524), -INT64_C( 1413666450029352452) },
       INT32_C(           0) },
    {  INT64_C( 6704605406273618420),
      { -INT64_C( 8610410823455259451),  INT64_C( 3681846863876511223) },
      { -INT64_C( 8610410823455259451),  INT64_C( 6704605406273618420) },
       INT32_C(           1) },
    { -INT64_C( 3586240954304351115),
      { -INT64_C( 6497837878180096675),  INT64_C( 4382284209977202767) },
      { -INT64_C( 3586240954304351115),  INT64_C( 4382284209977202767) },
       INT32_C(           0) },
    { -INT64_C( 7980243183598333995),
      {  INT64_C( 8455539187811154863), -INT64_C( 5694873878574442639) },
      {  INT64_C( 8455539187811154863), -INT64_C( 7980243183598333995) },
       INT32_C(           1) },
    {  INT64_C( 5465340758585865814),
      {  INT64_C( 7279672657599478617),  INT64_C( 8367484709461026450) },
      {  INT64_C( 5465340758585865814),  INT64_C( 8367484709461026450) },
       INT32_C(           0) },
    {  INT64_C( 2211476088021191326),
      { -INT64_C( 3678153970188375757),  INT64_C( 8568177333557611725) },
      { -INT64_C( 3678153970188375757),  INT64_C( 2211476088021191326) },
       INT32_C(           1) },
    { -INT64_C( 4853685099509524690),
      {  INT64_C( 6570589300708895305),  INT64_C( 5212064977732888853) },
      { -INT64_C( 4853685099509524690),  INT64_C( 5212064977732888853) },
       INT32_C(           0) },
    {  INT64_C(  837586917696181829),
      {  INT64_C( 5145047008699793291), -INT64_C( 6643223354434641333) },
      {  INT64_C( 5145047008699793291),  INT64_C(  837586917696181829) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde_int64x2_t v = simde_vld1q_s64(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vsetq_lane_s64, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    simde_int64x2_t v = simde_test_arm_neon_random_i64x2();
    int lane = lanes[i];
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vsetq_lane_s64, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t v[16];
    uint8_t r[16];
    int lane;
  } test_vec[] = {
    { UINT8_C(238),
      { UINT8_C( 34), UINT8_C( 29), UINT8_C(146), UINT8_C( 44), UINT8_C(194), UINT8_C( 98), UINT8_C(109), UINT8_C(200),
        UINT8_C( 43), UINT8_C(150), UINT8_C( 94),    UINT8_MAX, UINT8_C(180), UINT8_C(219), UINT8_C( 87), UINT8_C(201) },
      { UINT8_C(238), UINT8_C( 29), UINT8_C(146), UINT8_C( 44), UINT8_C(194), UINT8_C( 98), UINT8_C(109), UINT8_C(200),
        UINT8_C( 43), UINT8_C(150), UINT8_C( 94),    UINT8_MAX, UINT8_C(180), UINT8_C(219), UINT8_C( 87), UINT8_C(201) },
       INT32_C(           0) },
    { UINT8_C( 62),
      { UINT8_C(200), UINT8_C( 35), UINT8_C( 96), UINT8_C( 42), UINT8_C( 87), UINT8_C(172), UINT8_C(236), UINT8_C( 73),
        UINT8_C(  8), UINT8_C( 33), UINT8_C(247), UINT8_C( 76), UINT8_C( 81), UINT8_C(229), UINT8_C(110), UINT8_C(110) },
      { UINT8_C(200), UINT8_C( 35), UINT8_C( 62), UINT8_C( 42), UINT8_C( 87), UINT8_C(172), UINT8_C(236), UINT8_C( 73),
        UINT8_C(  8), UINT8_C( 33), UINT8_C(247), UINT8_C( 76), UINT8_C( 81), UINT8_C(229), UINT8_C(110), UINT8_C(110) },
       INT32_C(           2) },
    { UINT8_C(119),
      { UINT8_C(154), UINT8_C( 48), UINT8_C(217), UINT8_C(  7), UINT8_C(248), UINT8_C(  5), UINT8_C(158), UINT8_C( 86),
        UINT8_C(  4), UINT8_C( 82), UINT8_C( 49), UINT8_C( 91), UINT8_C( 27), UINT8_C(112), UINT8_C( 35), UINT8_C( 63) },
      { UINT8_C(154), UINT8_C( 48), UINT8_C(217), UINT8_C(  7), UINT8_C(119), UINT8_C(  5), UINT8_C(158), UINT8_C( 86),
        UINT8_C(  4), UINT8_C( 82), UINT8_C( 49), UINT8_C( 91), UINT8_C( 27), UINT8_C(112), UINT8_C( 35), UINT8_C( 63) },
       INT32_C(           4) },
    { UINT8_C(208),
      { UINT8_C( 77), UINT8_C(150), UINT8_C(124), UINT8_C( 57), UINT8_C(223), UINT8_C(133), UINT8_C( 90), UINT8_C(214),
        UINT8_C(209), UINT8_C(172), UINT8_C(187), UINT8_C( 63), UINT8_C( 26), UINT8_C( 51), UINT8_C(218), UINT8_C( 75) },
      { UINT8_C( 77), UINT8_C(150), UINT8_C(124), UINT8_C( 57), UINT8_C(223), UINT8_C(133), UINT8_C(208), UINT8_C(214),
        UINT8_C(209), UINT8_C(172), UINT8_C(187), UINT8_C( 63), UINT8_C( 26), UINT8_C( 51), UINT8_C(218), UINT8_C( 75) },
       INT32_C(           6) },
    { UINT8_C( 12),
      { UINT8_C(225), UINT8_C( 67), UINT8_C( 17), UINT8_C(127), UINT8_C(154), UINT8_C( 21), UINT8_C(210), UINT8_C(203),
        UINT8_C(112), UINT8_C(237), UINT8_C( 59), UINT8_C(147), UINT8_C( 44), UINT8_C( 11), UINT8_C(224), UINT8_C(194) },
      { UINT8_C(225), UINT8_C( 67), UINT8_C( 17), UINT8_C(127), UINT8_C(154), UINT8_C( 21), UINT8_C(210), UINT8_C(203),
        UINT8_C( 12), UINT8_C(237), UINT8_C( 59), UINT8_C(147), UINT8_C( 44), UINT8_C( 11), UINT8_C(224), UINT8_C(194) },
       INT32_C(           8) },
    { UINT8_C(136),
      { UINT8_C( 25), UINT8_C(162), UINT8_C( 13), UINT8_C(116), UINT8_C(120), UINT8_C(222), UINT8_C( 32), UINT8_C( 52),
        UINT8_C( 29), UINT8_C( 58), UINT8_C(103), UINT8_C(247), UINT8_C(133), UINT8_C(115), UINT8_C(217), UINT8_C(201) },
      { UINT8_C( 25), UINT8_C(162), UINT8_C( 13), UINT8_C(116), UINT8_C(120), UINT8_C(222), UINT8_C( 32), UINT8_C( 52),
        UINT8_C( 29), UINT8_C( 58), UINT8_C(136), UINT8_C(247), UINT8_C(133), UINT8_C(115), UINT8_C(217), UINT8_C(201) },
       INT32_C(          10) },
    { UINT8_C(133),
      { UINT8_C( 88), UINT8_C( 99), UINT8_C(154), UINT8_C( 42), UINT8_C( 46), UINT8_C( 11), UINT8_C( 24), UINT8_C(106),
        UINT8_C(158), UINT8_C( 68), UINT8_C(117), UINT8_C(127), UINT8_C(  7), UINT8_C(253), UINT8_C(152), UINT8_C(169) },
      { UINT8_C( 88), UINT8_C( 99), UINT8_C(154), UINT8_C( 42), UINT8_C( 46), UINT8_C( 11), UINT8_C( 24), UINT8_C(106),
        UINT8_C(158), UINT8_C( 68), UINT8_C(117), UINT8_C(127), UINT8_C(133), UINT8_C(253), UINT8_C(152), UINT8_C(169) },
       INT32_C(          12) },
    { UINT8_C( 10),
      { UINT8_C( 12), UINT8_C( 33), UINT8_C(232), UINT8_C( 44), UINT8_C( 85), UINT8_C(  6), UINT8_C(103), UINT8_C(188),
        UINT8_C(253), UINT8_C(236), UINT8_C( 48), UINT8_C(214), UINT8_C(181), UINT8_C(181), UINT8_C( 47), UINT8_C( 24) },
      { UINT8_C( 12), UINT8_C( 33), UINT8_C(232), UINT8_C( 44), UINT8_C( 85), UINT8_C(  6), UINT8_C(103), UINT8_C(188),
        UINT8_C(253), UINT8_C(236), UINT8_C( 48), UINT8_C(214), UINT8_C(181), UINT8_C(181), UINT8_C( 10), UINT8_C( 24) },
       INT32_C(          14) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t a = test_vec[i].a;
    simde_uint8x16_t v = simde_vld1q_u8(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vsetq_lane_u8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 2, 4, 6, 8, 10, 12, 14 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    simde_uint8x16_t v = simde_test_arm_neon_random_u8x16();
    int lane = lanes[i];
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vsetq_lane_u8, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t v[8];
    uint16_t r[8];
    int lane;
  } test_vec[] = {
    { UINT16_C(32446),
      { UINT16_C(19553), UINT16_C(61358), UINT16_C(14924), UINT16_C( 6732), UINT16_C(13757), UINT16_C(36062), UINT16_C(42840), UINT16_C(27459) },
      { UINT16_C(32446), UINT16_C(61358), UINT16_C(14924), UINT16_C( 6732), UINT16_C(13757), UINT16_C(36062), UINT16_C(42840), UINT16_C(27459) },
       INT32_C(           0) },
    { UINT16_C(48560),
      { UINT16_C(32777), UINT16_C(43662), UINT16_C(65055), UINT16_C( 2648), UINT16_C(36938), UINT16_C( 2492), UINT16_C( 7695), UINT16_C(48469) },
      { UINT16_C(32777), UINT16_C(48560), UINT16_C(65055), UINT16_C( 2648), UINT16_C(36938), UINT16_C( 2492), UINT16_C( 7695), UINT16_C(48469) },
       INT32_C(           1) },
    { UINT16_C(41229),
      { UINT16_C(23031), UINT16_C(46267), UINT16_C(39566), UINT16_C(58944), UINT16_C(33601), UINT16_C(61778), UINT16_C(23360), UINT16_C(53106) },
      { UINT16_C(23031), UINT16_C(46267), UINT16_C(41229), UINT16_C(58944), UINT16_C(33601), UINT16_C(61778), UINT16_C(23360), UINT16_C(53106) },
       INT32_C(           2) },
    { UINT16_C(37126),
      { UINT16_C(24269), UINT16_C( 6043), UINT16_C(22767), UINT16_C(65056), UINT16_C(30326), UINT16_C(33723), UINT16_C(45591), UINT16_C(54237) },
      { UINT16_C(24269), UINT16_C( 6043), UINT16_C(22767), UINT16_C(37126), UINT16_C(30326), UINT16_C(33723), UINT16_C(45591), UINT16_C(54237) },
       INT32_C(           3) },
    { UINT16_C(27494),
      { UINT16_C(42605), UINT16_C(44626), UINT16_C(42025), UINT16_C(27295), UINT16_C( 4607), UINT16_C( 1337), UINT16_C( 1698), UINT16_C(15972) },
      { UINT16_C(42605), UINT16_C(44626), UINT16_C(42025), UINT16_C(27295), UINT16_C(27494), UINT16_C( 1337), UINT16_C( 1698), UINT16_C(15972) },
       INT32_C(           4) },
    { UINT16_C(21277),
      { UINT16_C(16022), UINT16_C( 3153), UINT16_C( 3252), UINT16_C(52111), UINT16_C(27838), UINT16_C( 9374), UINT16_C( 3032), UINT16_C(10954) },
      { UINT16_C(16022), UINT16_C( 3153), UINT16_C( 3252), UINT16_C(52111), UINT16_C(27838), UINT16_C(21277), UINT16_C( 3032), UINT16_C(10954) },
       INT32_C(           5) },
    { UINT16_C(62393),
      { UINT16_C(22990), UINT16_C(52573), UINT16_C(38506), UINT16_C( 3539), UINT16_C(14236), UINT16_C(47691), UINT16_C(57738), UINT16_C(56312) },
      { UINT16_C(22990), UINT16_C(52573), UINT16_C(38506), UINT16_C( 3539), UINT16_C(14236), UINT16_C(47691), UINT16_C(62393), UINT16_C(56312) },
       INT32_C(           6) },
    { UINT16_C(44269),
      { UINT16_C(31975), UINT16_C(42359), UINT16_C( 5865), UINT16_C(49609), UINT16_C(37665), UINT16_C(56299), UINT16_C(47494), UINT16_C(58420) },
      { UINT16_C(31975), UINT16_C(42359), UINT16_C( 5865), UINT16_C(49609), UINT16_C(37665), UINT16_C(56299), UINT16_C(47494), UINT16_C(44269) },
       INT32_C(           7) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t a = test_vec[i].a;
    simde_uint16x8_t v = simde_vld1q_u16(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vsetq_lane_u16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    simde_uint16x8_t v = simde_test_arm_neon_random_u16x8();
    int lane = lanes[i];
    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vsetq_lane_u16, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t v[4];
    uint32_t r[4];
    int lane;
  } test_vec[] = {
    { UINT32_C(1099264639),
      { UINT32_C(1082970218), UINT32_C(2894578869), UINT32_C(4293238305), UINT32_C(1201326841) },
      { UINT32_C(1099264639), UINT32_C(2894578869), UINT32_C(4293238305), UINT32_C(1201326841) },
       INT32_C(           0) },
    { UINT32_C(2013389258),
      { UINT32_C( 494535141), UINT32_C(3369462601), UINT32_C(3339278941), UINT32_C(3741881642) },
      { UINT32_C( 494535141), UINT32_C(2013389258), UINT32_C(3339278941), UINT32_C(3741881642) },
       INT32_C(           1) },
    { UINT32_C(2056032089),
      { UINT32_C( 645558573), UINT32_C( 107877435), UINT32_C(3682496502), UINT32_C(3136878705) },
      { UINT32_C( 645558573), UINT32_C( 107877435), UINT32_C(2056032089), UINT32_C(3136878705) },
       INT32_C(           2) },
    { UINT32_C(1099091428),
      { UINT32_C(1376357160), UINT32_C(2050101537), UINT32_C(3472211616), UINT32_C(1811181359) },
      { UINT32_C(1376357160), UINT32_C(2050101537), UINT32_C(3472211616), UINT32_C(1099091428) },
       INT32_C(           3) },
    { UINT32_C(2037473923),
      { UINT32_C(1129639890), UINT32_C(3422375399), UINT32_C(1108180762), UINT32_C( 731190794) },
      { UINT32_C(2037473923), UINT32_C(3422375399), UINT32_C(1108180762), UINT32_C( 731190794) },
       INT32_C(           0) },
    { UINT32_C(3349595943),
      { UINT32_C(3029703557), UINT32_C(2367654410), UINT32_C(3188166892), UINT32_C(1728142207) },
      { UINT32_C(3029703557), UINT32_C(3349595943), UINT32_C(3188166892), UINT32_C(1728142207) },
       INT32_C(           1) },
    { UINT32_C(3274899112),
      { UINT32_C(2282045309), UINT32_C(2092145237), UINT32_C(3863239009), UINT32_C(4271626740) },
      { UINT32_C(2282045309), UINT32_C(2092145237), UINT32_C(3274899112), UINT32_C(4271626740) },
       INT32_C(           2) },
    { UINT32_C(1351400035),
      { UINT32_C(3389952843), UINT32_C(2536575214), UINT32_C(2354734094), UINT32_C(4178861987) },
      { UINT32_C(3389952843), UINT32_C(2536575214), UINT32_C(2354734094), UINT32_C(1351400035) },
       INT32_C(           3) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    simde_uint32x4_t v = simde_vld1q_u32(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsetq_lane_u32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    simde_uint32x4_t v = simde_test_arm_neon_random_u32x4();
    int lane = lanes[i];
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsetq_lane_u32, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsetq_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t v[2];
    uint64_t r[2];
    int lane;
  } test_vec[] = {
    { UINT64_C( 5390401428211676195),
      { UINT64_C(14829740467812854006), UINT64_C( 6030377659942938448) },
      { UINT64_C( 5390401428211676195), UINT64_C( 6030377659942938448) },
       INT32_C(           0) },
    { UINT64_C(16865715377620681228),
      { UINT64_C(16327746488354496450), UINT64_C(17394597901878546230) },
      { UINT64_C(16327746488354496450), UINT64_C(16865715377620681228) },
       INT32_C(           1) },
    { UINT64_C(18413438712080547758),
      { UINT64_C( 5178889453871920686), UINT64_C(16377951018670153595) },
      { UINT64_C(18413438712080547758), UINT64_C(16377951018670153595) },
       INT32_C(           0) },
    { UINT64_C( 4075162322782160122),
      { UINT64_C( 7175633015332112801), UINT64_C( 4123669697782129006) },
      { UINT64_C( 7175633015332112801), UINT64_C( 4075162322782160122) },
       INT32_C(           1) },
    { UINT64_C(17557542605282201111),
      { UINT64_C(12047721669956871279), UINT64_C(  593579713905861028) },
      { UINT64_C(17557542605282201111), UINT64_C(  593579713905861028) },
       INT32_C(           0) },
    { UINT64_C(16386687870275654770),
      { UINT64_C( 7345177435188955651), UINT64_C( 4477019592935308915) },
      { UINT64_C( 7345177435188955651), UINT64_C(16386687870275654770) },
       INT32_C(           1) },
    { UINT64_C(11661319370131856691),
      { UINT64_C(  763142462340452840), UINT64_C(  188859325098639172) },
      { UINT64_C(11661319370131856691), UINT64_C(  188859325098639172) },
       INT32_C(           0) },
    { UINT64_C(14000456004831804788),
      { UINT64_C(11513844660171662330), UINT64_C( 1749344802057787957) },
      { UINT64_C(11513844660171662330), UINT64_C(14000456004831804788) },
       INT32_C(           1) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a;
    simde_uint64x2_t v = simde_vld1q_u64(test_vec[i].v);
    int lane = test_vec[i].lane;
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vsetq_lane_u64, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
    uint64_t a = simde_test_codegen_random_u64();
    simde_uint64x2_t v = simde_test_arm_neon_random_u64x2();
    int lane = lanes[i];
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vsetq_lane_u64, r, (HEDLEY_UNREACHABLE(), v), lane, a, v);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vset_lane_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsetq_lane_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
