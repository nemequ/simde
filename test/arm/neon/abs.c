#define SIMDE_TEST_ARM_NEON_INSN abs

#include "test-neon.h"
#include "../../../simde/arm/neon/abs.h"

static int
test_simde_vabsd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t r;
  } test_vec[] = {
    {  INT64_C(  276336164582230812),
       INT64_C(  276336164582230812) },
    { -INT64_C( 7462378710667308762),
       INT64_C( 7462378710667308762) },
    { -INT64_C( 3808596764535413647),
       INT64_C( 3808596764535413647) },
    { -INT64_C( 1744909785833839419),
       INT64_C( 1744909785833839419) },
    {  INT64_C( 3578898303845682272),
       INT64_C( 3578898303845682272) },
    { -INT64_C( 6462880738838780002),
       INT64_C( 6462880738838780002) },
    {  INT64_C( 7176398727321188705),
       INT64_C( 7176398727321188705) },
    {  INT64_C( 1281167105828772884),
       INT64_C( 1281167105828772884) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vabsd_s64(test_vec[i].a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t r = simde_vabsd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabs_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   240.57), SIMDE_FLOAT32_C(   605.25) },
      { SIMDE_FLOAT32_C(   240.57), SIMDE_FLOAT32_C(   605.25) } },
    { { SIMDE_FLOAT32_C(  -896.34), SIMDE_FLOAT32_C(  -983.98) },
      { SIMDE_FLOAT32_C(   896.34), SIMDE_FLOAT32_C(   983.98) } },
    { { SIMDE_FLOAT32_C(   435.53), SIMDE_FLOAT32_C(  -284.04) },
      { SIMDE_FLOAT32_C(   435.53), SIMDE_FLOAT32_C(   284.04) } },
    { { SIMDE_FLOAT32_C(   659.95), SIMDE_FLOAT32_C(  -108.19) },
      { SIMDE_FLOAT32_C(   659.95), SIMDE_FLOAT32_C(   108.19) } },
    { { SIMDE_FLOAT32_C(  -501.15), SIMDE_FLOAT32_C(   711.09) },
      { SIMDE_FLOAT32_C(   501.15), SIMDE_FLOAT32_C(   711.09) } },
    { { SIMDE_FLOAT32_C(   552.72), SIMDE_FLOAT32_C(  -497.32) },
      { SIMDE_FLOAT32_C(   552.72), SIMDE_FLOAT32_C(   497.32) } },
    { { SIMDE_FLOAT32_C(   568.44), SIMDE_FLOAT32_C(  -896.02) },
      { SIMDE_FLOAT32_C(   568.44), SIMDE_FLOAT32_C(   896.02) } },
    { { SIMDE_FLOAT32_C(   997.23), SIMDE_FLOAT32_C(  -515.53) },
      { SIMDE_FLOAT32_C(   997.23), SIMDE_FLOAT32_C(   515.53) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vabs_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vabs_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   526.66) },
      { SIMDE_FLOAT64_C(   526.66) } },
    { { SIMDE_FLOAT64_C(    52.02) },
      { SIMDE_FLOAT64_C(    52.02) } },
    { { SIMDE_FLOAT64_C(   169.50) },
      { SIMDE_FLOAT64_C(   169.50) } },
    { { SIMDE_FLOAT64_C(   466.20) },
      { SIMDE_FLOAT64_C(   466.20) } },
    { { SIMDE_FLOAT64_C(  -862.24) },
      { SIMDE_FLOAT64_C(   862.24) } },
    { { SIMDE_FLOAT64_C(   411.84) },
      { SIMDE_FLOAT64_C(   411.84) } },
    { { SIMDE_FLOAT64_C(  -921.62) },
      { SIMDE_FLOAT64_C(   921.62) } },
    { { SIMDE_FLOAT64_C(   -55.03) },
      { SIMDE_FLOAT64_C(    55.03) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vabs_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vabs_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {      INT8_MIN, -INT8_C(  18),  INT8_C( 117), -INT8_C(  22),  INT8_C(  13), -INT8_C(  62), -INT8_C(  94),  INT8_C(  57) },
      {      INT8_MIN,  INT8_C(  18),  INT8_C( 117),  INT8_C(  22),  INT8_C(  13),  INT8_C(  62),  INT8_C(  94),  INT8_C(  57) } },
    { {  INT8_C(  32),  INT8_C(  12),      INT8_MIN,  INT8_C(   3), -INT8_C(  50),  INT8_C(  38), -INT8_C( 120),  INT8_C(  34) },
      {  INT8_C(  32),  INT8_C(  12),      INT8_MIN,  INT8_C(   3),  INT8_C(  50),  INT8_C(  38),  INT8_C( 120),  INT8_C(  34) } },
    { {  INT8_C(   7),  INT8_C( 100), -INT8_C(  64), -INT8_C(  52), -INT8_C(  66), -INT8_C(  82), -INT8_C(  16),  INT8_C(  44) },
      {  INT8_C(   7),  INT8_C( 100),  INT8_C(  64),  INT8_C(  52),  INT8_C(  66),  INT8_C(  82),  INT8_C(  16),  INT8_C(  44) } },
    { {  INT8_C(  62), -INT8_C(  64),  INT8_C(  55),  INT8_C(  87), -INT8_C(  99),  INT8_C(  82), -INT8_C(  13), -INT8_C(  62) },
      {  INT8_C(  62),  INT8_C(  64),  INT8_C(  55),  INT8_C(  87),  INT8_C(  99),  INT8_C(  82),  INT8_C(  13),  INT8_C(  62) } },
    { {  INT8_C(  64),  INT8_C( 105), -INT8_C(  84),  INT8_C(  77),  INT8_C(  43),  INT8_C(  78), -INT8_C( 121),  INT8_C(  75) },
      {  INT8_C(  64),  INT8_C( 105),  INT8_C(  84),  INT8_C(  77),  INT8_C(  43),  INT8_C(  78),  INT8_C( 121),  INT8_C(  75) } },
    { {  INT8_C(  90),  INT8_C(   7),  INT8_C(  78),  INT8_C(  40),  INT8_C(  45), -INT8_C(  41),  INT8_C(  75),  INT8_C(  52) },
      {  INT8_C(  90),  INT8_C(   7),  INT8_C(  78),  INT8_C(  40),  INT8_C(  45),  INT8_C(  41),  INT8_C(  75),  INT8_C(  52) } },
    { {  INT8_C(  59),  INT8_C(  11),  INT8_C(   0), -INT8_C(   7), -INT8_C(  71), -INT8_C(  15),  INT8_C(  38), -INT8_C(   8) },
      {  INT8_C(  59),  INT8_C(  11),  INT8_C(   0),  INT8_C(   7),  INT8_C(  71),  INT8_C(  15),  INT8_C(  38),  INT8_C(   8) } },
    { { -INT8_C(  79),  INT8_C(  93),  INT8_C(  79),  INT8_C(  78), -INT8_C(  81),  INT8_C(  67),  INT8_C(  16), -INT8_C(  16) },
      {  INT8_C(  79),  INT8_C(  93),  INT8_C(  79),  INT8_C(  78),  INT8_C(  81),  INT8_C(  67),  INT8_C(  16),  INT8_C(  16) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vabs_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabs_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {       INT16_MIN, -INT16_C( 26113), -INT16_C( 28950), -INT16_C( 11718) },
      {       INT16_MIN,  INT16_C( 26113),  INT16_C( 28950),  INT16_C( 11718) } },
    { {  INT16_C( 26788), -INT16_C( 29463), -INT16_C( 17823), -INT16_C( 31905) },
      {  INT16_C( 26788),  INT16_C( 29463),  INT16_C( 17823),  INT16_C( 31905) } },
    { { -INT16_C( 14514),  INT16_C( 29487),  INT16_C( 22021), -INT16_C(  9957) },
      {  INT16_C( 14514),  INT16_C( 29487),  INT16_C( 22021),  INT16_C(  9957) } },
    { { -INT16_C( 19800),  INT16_C( 18730), -INT16_C( 30130), -INT16_C(  9884) },
      {  INT16_C( 19800),  INT16_C( 18730),  INT16_C( 30130),  INT16_C(  9884) } },
    { {  INT16_C( 25580), -INT16_C( 10638), -INT16_C( 21263), -INT16_C( 26968) },
      {  INT16_C( 25580),  INT16_C( 10638),  INT16_C( 21263),  INT16_C( 26968) } },
    { { -INT16_C( 28395),  INT16_C( 30242), -INT16_C( 32437), -INT16_C( 26118) },
      {  INT16_C( 28395),  INT16_C( 30242),  INT16_C( 32437),  INT16_C( 26118) } },
    { {  INT16_C( 10569),  INT16_C( 19980),  INT16_C( 10368),  INT16_C( 10279) },
      {  INT16_C( 10569),  INT16_C( 19980),  INT16_C( 10368),  INT16_C( 10279) } },
    { {  INT16_C( 20954),  INT16_C( 10354), -INT16_C( 10533), -INT16_C( 14591) },
      {  INT16_C( 20954),  INT16_C( 10354),  INT16_C( 10533),  INT16_C( 14591) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vabs_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabs_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {            INT32_MIN,  INT32_C(   958986776) },
      {            INT32_MIN,  INT32_C(   958986776) } },
    { {  INT32_C(  1449993369), -INT32_C(   502149650) },
      {  INT32_C(  1449993369),  INT32_C(   502149650) } },
    { { -INT32_C(   149790075),  INT32_C(   349615921) },
      {  INT32_C(   149790075),  INT32_C(   349615921) } },
    { {  INT32_C(   872241755), -INT32_C(   866869240) },
      {  INT32_C(   872241755),  INT32_C(   866869240) } },
    { {  INT32_C(  1757820240), -INT32_C(   928846289) },
      {  INT32_C(  1757820240),  INT32_C(   928846289) } },
    { {  INT32_C(    18812691),  INT32_C(  1642344668) },
      {  INT32_C(    18812691),  INT32_C(  1642344668) } },
    { { -INT32_C(  1017579886),  INT32_C(   148385709) },
      {  INT32_C(  1017579886),  INT32_C(   148385709) } },
    { { -INT32_C(  1841506935), -INT32_C(   983658379) },
      {  INT32_C(  1841506935),  INT32_C(   983658379) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vabs_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabs_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int64_t r[1];
  } test_vec[] = {
    { {                     INT64_MIN },
      {                     INT64_MIN } },
    { { -INT64_C( 9123335531813202818) },
      {  INT64_C( 9123335531813202818) } },
    { { -INT64_C(  969261482036724268) },
      {  INT64_C(  969261482036724268) } },
    { { -INT64_C( 1747836245580099480) },
      {  INT64_C( 1747836245580099480) } },
    { { -INT64_C( 3930266661464934217) },
      {  INT64_C( 3930266661464934217) } },
    { {  INT64_C( 4765662101956266231) },
      {  INT64_C( 4765662101956266231) } },
    { { -INT64_C( 4374945379510722939) },
      {  INT64_C( 4374945379510722939) } },
    { {  INT64_C( 1548238122455985763) },
      {  INT64_C( 1548238122455985763) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t r = simde_vabs_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabsq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   462.30), SIMDE_FLOAT32_C(   260.51), SIMDE_FLOAT32_C(  -298.75), SIMDE_FLOAT32_C(   -90.05) },
      { SIMDE_FLOAT32_C(   462.30), SIMDE_FLOAT32_C(   260.51), SIMDE_FLOAT32_C(   298.75), SIMDE_FLOAT32_C(    90.05) } },
    { { SIMDE_FLOAT32_C(   349.12), SIMDE_FLOAT32_C(   972.04), SIMDE_FLOAT32_C(     3.43), SIMDE_FLOAT32_C(  -624.53) },
      { SIMDE_FLOAT32_C(   349.12), SIMDE_FLOAT32_C(   972.04), SIMDE_FLOAT32_C(     3.43), SIMDE_FLOAT32_C(   624.53) } },
    { { SIMDE_FLOAT32_C(   653.64), SIMDE_FLOAT32_C(   788.52), SIMDE_FLOAT32_C(   687.80), SIMDE_FLOAT32_C(   756.52) },
      { SIMDE_FLOAT32_C(   653.64), SIMDE_FLOAT32_C(   788.52), SIMDE_FLOAT32_C(   687.80), SIMDE_FLOAT32_C(   756.52) } },
    { { SIMDE_FLOAT32_C(   163.46), SIMDE_FLOAT32_C(  -327.92), SIMDE_FLOAT32_C(   337.82), SIMDE_FLOAT32_C(   394.49) },
      { SIMDE_FLOAT32_C(   163.46), SIMDE_FLOAT32_C(   327.92), SIMDE_FLOAT32_C(   337.82), SIMDE_FLOAT32_C(   394.49) } },
    { { SIMDE_FLOAT32_C(   977.72), SIMDE_FLOAT32_C(   437.45), SIMDE_FLOAT32_C(   808.81), SIMDE_FLOAT32_C(   750.24) },
      { SIMDE_FLOAT32_C(   977.72), SIMDE_FLOAT32_C(   437.45), SIMDE_FLOAT32_C(   808.81), SIMDE_FLOAT32_C(   750.24) } },
    { { SIMDE_FLOAT32_C(   458.56), SIMDE_FLOAT32_C(  -377.89), SIMDE_FLOAT32_C(   748.70), SIMDE_FLOAT32_C(  -697.44) },
      { SIMDE_FLOAT32_C(   458.56), SIMDE_FLOAT32_C(   377.89), SIMDE_FLOAT32_C(   748.70), SIMDE_FLOAT32_C(   697.44) } },
    { { SIMDE_FLOAT32_C(  -708.39), SIMDE_FLOAT32_C(   955.88), SIMDE_FLOAT32_C(    31.34), SIMDE_FLOAT32_C(  -575.79) },
      { SIMDE_FLOAT32_C(   708.39), SIMDE_FLOAT32_C(   955.88), SIMDE_FLOAT32_C(    31.34), SIMDE_FLOAT32_C(   575.79) } },
    { { SIMDE_FLOAT32_C(  -270.33), SIMDE_FLOAT32_C(   422.59), SIMDE_FLOAT32_C(   310.75), SIMDE_FLOAT32_C(  -808.03) },
      { SIMDE_FLOAT32_C(   270.33), SIMDE_FLOAT32_C(   422.59), SIMDE_FLOAT32_C(   310.75), SIMDE_FLOAT32_C(   808.03) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vabsq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vabsq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   142.01), SIMDE_FLOAT64_C(   892.18) },
      { SIMDE_FLOAT64_C(   142.01), SIMDE_FLOAT64_C(   892.18) } },
    { { SIMDE_FLOAT64_C(    77.64), SIMDE_FLOAT64_C(   556.98) },
      { SIMDE_FLOAT64_C(    77.64), SIMDE_FLOAT64_C(   556.98) } },
    { { SIMDE_FLOAT64_C(   117.55), SIMDE_FLOAT64_C(   172.99) },
      { SIMDE_FLOAT64_C(   117.55), SIMDE_FLOAT64_C(   172.99) } },
    { { SIMDE_FLOAT64_C(  -701.87), SIMDE_FLOAT64_C(  -246.57) },
      { SIMDE_FLOAT64_C(   701.87), SIMDE_FLOAT64_C(   246.57) } },
    { { SIMDE_FLOAT64_C(   -27.40), SIMDE_FLOAT64_C(    39.73) },
      { SIMDE_FLOAT64_C(    27.40), SIMDE_FLOAT64_C(    39.73) } },
    { { SIMDE_FLOAT64_C(  -558.82), SIMDE_FLOAT64_C(  -689.88) },
      { SIMDE_FLOAT64_C(   558.82), SIMDE_FLOAT64_C(   689.88) } },
    { { SIMDE_FLOAT64_C(  -566.76), SIMDE_FLOAT64_C(   -58.12) },
      { SIMDE_FLOAT64_C(   566.76), SIMDE_FLOAT64_C(    58.12) } },
    { { SIMDE_FLOAT64_C(  -718.46), SIMDE_FLOAT64_C(   966.37) },
      { SIMDE_FLOAT64_C(   718.46), SIMDE_FLOAT64_C(   966.37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vabsq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vabsq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {      INT8_MIN, -INT8_C(  34), -INT8_C(  36),  INT8_C(  16),  INT8_C( 115),  INT8_C(   7), -INT8_C(  82),  INT8_C(  67),
        -INT8_C(  76),  INT8_C(  28),  INT8_C( 123), -INT8_C( 110), -INT8_C(  10), -INT8_C( 106),  INT8_C(   1), -INT8_C(  51) },
      {      INT8_MIN,  INT8_C(  34),  INT8_C(  36),  INT8_C(  16),  INT8_C( 115),  INT8_C(   7),  INT8_C(  82),  INT8_C(  67),
         INT8_C(  76),  INT8_C(  28),  INT8_C( 123),  INT8_C( 110),  INT8_C(  10),  INT8_C( 106),  INT8_C(   1),  INT8_C(  51) } },
    { { -INT8_C( 101), -INT8_C(   9),  INT8_C(  83),  INT8_C(  73),  INT8_C(  58),  INT8_C(  30),  INT8_C(  16),  INT8_C( 111),
         INT8_C(  33),  INT8_C(  15),  INT8_C(  47), -INT8_C(   5),  INT8_C(  74),  INT8_C(  49), -INT8_C(  64), -INT8_C( 105) },
      {  INT8_C( 101),  INT8_C(   9),  INT8_C(  83),  INT8_C(  73),  INT8_C(  58),  INT8_C(  30),  INT8_C(  16),  INT8_C( 111),
         INT8_C(  33),  INT8_C(  15),  INT8_C(  47),  INT8_C(   5),  INT8_C(  74),  INT8_C(  49),  INT8_C(  64),  INT8_C( 105) } },
    { {  INT8_C(  16), -INT8_C( 100), -INT8_C(  89), -INT8_C( 125), -INT8_C(  93),  INT8_C(  85), -INT8_C(  57),  INT8_C(  88),
         INT8_C( 114),  INT8_C(  66), -INT8_C(  22),  INT8_C( 104), -INT8_C(  40), -INT8_C(  21),  INT8_C(  53),  INT8_C( 116) },
      {  INT8_C(  16),  INT8_C( 100),  INT8_C(  89),  INT8_C( 125),  INT8_C(  93),  INT8_C(  85),  INT8_C(  57),  INT8_C(  88),
         INT8_C( 114),  INT8_C(  66),  INT8_C(  22),  INT8_C( 104),  INT8_C(  40),  INT8_C(  21),  INT8_C(  53),  INT8_C( 116) } },
    { { -INT8_C(  30), -INT8_C( 120), -INT8_C(  67),  INT8_C(  29), -INT8_C(  90), -INT8_C(  51), -INT8_C( 116), -INT8_C(  57),
        -INT8_C(  36), -INT8_C(  68), -INT8_C(  62),  INT8_C(  38), -INT8_C(  19), -INT8_C( 126), -INT8_C(  67), -INT8_C(   3) },
      {  INT8_C(  30),  INT8_C( 120),  INT8_C(  67),  INT8_C(  29),  INT8_C(  90),  INT8_C(  51),  INT8_C( 116),  INT8_C(  57),
         INT8_C(  36),  INT8_C(  68),  INT8_C(  62),  INT8_C(  38),  INT8_C(  19),  INT8_C( 126),  INT8_C(  67),  INT8_C(   3) } },
    { {  INT8_C(  30),  INT8_C( 100), -INT8_C( 127), -INT8_C(  62), -INT8_C(  71),  INT8_C(  72),  INT8_C(  26),  INT8_C(  43),
        -INT8_C( 118),  INT8_C(   4), -INT8_C( 109),  INT8_C(  98), -INT8_C(  17), -INT8_C(  56), -INT8_C(  42), -INT8_C(  46) },
      {  INT8_C(  30),  INT8_C( 100),      INT8_MAX,  INT8_C(  62),  INT8_C(  71),  INT8_C(  72),  INT8_C(  26),  INT8_C(  43),
         INT8_C( 118),  INT8_C(   4),  INT8_C( 109),  INT8_C(  98),  INT8_C(  17),  INT8_C(  56),  INT8_C(  42),  INT8_C(  46) } },
    { {  INT8_C(  80), -INT8_C( 109), -INT8_C(  17), -INT8_C(   9),  INT8_C(  96),  INT8_C( 123), -INT8_C(  66),  INT8_C(  60),
         INT8_C(  55), -INT8_C( 127),  INT8_C(  98),  INT8_C(  37),  INT8_C(   3),  INT8_C(  31),  INT8_C(  34),  INT8_C(  34) },
      {  INT8_C(  80),  INT8_C( 109),  INT8_C(  17),  INT8_C(   9),  INT8_C(  96),  INT8_C( 123),  INT8_C(  66),  INT8_C(  60),
         INT8_C(  55),      INT8_MAX,  INT8_C(  98),  INT8_C(  37),  INT8_C(   3),  INT8_C(  31),  INT8_C(  34),  INT8_C(  34) } },
    { { -INT8_C( 125), -INT8_C(  93), -INT8_C(  28),  INT8_C(  61), -INT8_C(  21), -INT8_C(   2),  INT8_C( 104),  INT8_C( 117),
         INT8_C(   2), -INT8_C(   4), -INT8_C(  40), -INT8_C(  15), -INT8_C(  60), -INT8_C(  82), -INT8_C(  61),  INT8_C(  21) },
      {  INT8_C( 125),  INT8_C(  93),  INT8_C(  28),  INT8_C(  61),  INT8_C(  21),  INT8_C(   2),  INT8_C( 104),  INT8_C( 117),
         INT8_C(   2),  INT8_C(   4),  INT8_C(  40),  INT8_C(  15),  INT8_C(  60),  INT8_C(  82),  INT8_C(  61),  INT8_C(  21) } },
    { {  INT8_C(  66), -INT8_C(  78),  INT8_C(  12), -INT8_C(  94),  INT8_C(  46), -INT8_C(  54), -INT8_C(  33),  INT8_C( 101),
         INT8_C(  75),  INT8_C(  65), -INT8_C( 118),  INT8_C(  79),  INT8_C(  97), -INT8_C(  83),  INT8_C( 113), -INT8_C(  28) },
      {  INT8_C(  66),  INT8_C(  78),  INT8_C(  12),  INT8_C(  94),  INT8_C(  46),  INT8_C(  54),  INT8_C(  33),  INT8_C( 101),
         INT8_C(  75),  INT8_C(  65),  INT8_C( 118),  INT8_C(  79),  INT8_C(  97),  INT8_C(  83),  INT8_C( 113),  INT8_C(  28) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vabsq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabsq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {       INT16_MIN,  INT16_C(  8680), -INT16_C(  9431), -INT16_C( 30617), -INT16_C( 25759),  INT16_C(   691),  INT16_C(  1725),  INT16_C( 11273) },
      {       INT16_MIN,  INT16_C(  8680),  INT16_C(  9431),  INT16_C( 30617),  INT16_C( 25759),  INT16_C(   691),  INT16_C(  1725),  INT16_C( 11273) } },
    { { -INT16_C(  5989),  INT16_C(  4088),  INT16_C( 16904), -INT16_C( 13230),  INT16_C( 21746),  INT16_C( 20255),  INT16_C( 15195), -INT16_C( 19725) },
      {  INT16_C(  5989),  INT16_C(  4088),  INT16_C( 16904),  INT16_C( 13230),  INT16_C( 21746),  INT16_C( 20255),  INT16_C( 15195),  INT16_C( 19725) } },
    { { -INT16_C(  9465),  INT16_C( 12756),  INT16_C( 15286),  INT16_C(  6329),  INT16_C( 27863), -INT16_C( 27622),  INT16_C(  9331),  INT16_C(  3776) },
      {  INT16_C(  9465),  INT16_C( 12756),  INT16_C( 15286),  INT16_C(  6329),  INT16_C( 27863),  INT16_C( 27622),  INT16_C(  9331),  INT16_C(  3776) } },
    { { -INT16_C( 18420),  INT16_C(  5149),  INT16_C( 28922), -INT16_C(  4895),  INT16_C(   196),  INT16_C(  8252),  INT16_C( 12091),  INT16_C( 17106) },
      {  INT16_C( 18420),  INT16_C(  5149),  INT16_C( 28922),  INT16_C(  4895),  INT16_C(   196),  INT16_C(  8252),  INT16_C( 12091),  INT16_C( 17106) } },
    { { -INT16_C( 23029), -INT16_C( 16013),  INT16_C( 11746), -INT16_C( 17959), -INT16_C(  2919),  INT16_C(  3149),  INT16_C(  3352),  INT16_C(  9242) },
      {  INT16_C( 23029),  INT16_C( 16013),  INT16_C( 11746),  INT16_C( 17959),  INT16_C(  2919),  INT16_C(  3149),  INT16_C(  3352),  INT16_C(  9242) } },
    { {  INT16_C( 14533), -INT16_C( 16583),  INT16_C(  6824),  INT16_C( 27819), -INT16_C(  6374),  INT16_C( 21900),  INT16_C( 24343),  INT16_C(  8855) },
      {  INT16_C( 14533),  INT16_C( 16583),  INT16_C(  6824),  INT16_C( 27819),  INT16_C(  6374),  INT16_C( 21900),  INT16_C( 24343),  INT16_C(  8855) } },
    { {  INT16_C(  2821), -INT16_C(  6173), -INT16_C( 17096), -INT16_C( 11872), -INT16_C(  4687), -INT16_C( 13858), -INT16_C(  1798), -INT16_C( 16403) },
      {  INT16_C(  2821),  INT16_C(  6173),  INT16_C( 17096),  INT16_C( 11872),  INT16_C(  4687),  INT16_C( 13858),  INT16_C(  1798),  INT16_C( 16403) } },
    { {  INT16_C(  9776), -INT16_C( 10114),  INT16_C( 10816),  INT16_C( 23109), -INT16_C( 12015),  INT16_C( 10415),  INT16_C( 18224),  INT16_C( 13898) },
      {  INT16_C(  9776),  INT16_C( 10114),  INT16_C( 10816),  INT16_C( 23109),  INT16_C( 12015),  INT16_C( 10415),  INT16_C( 18224),  INT16_C( 13898) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vabsq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabsq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {            INT32_MIN,  INT32_C(  2027380581),  INT32_C(  1316751660),  INT32_C(  2019026169) },
      {            INT32_MIN,  INT32_C(  2027380581),  INT32_C(  1316751660),  INT32_C(  2019026169) } },
    { { -INT32_C(   919386617), -INT32_C(   297545572),  INT32_C(  1283066671),  INT32_C(  1868282067) },
      {  INT32_C(   919386617),  INT32_C(   297545572),  INT32_C(  1283066671),  INT32_C(  1868282067) } },
    { { -INT32_C(  1989187036), -INT32_C(   167688246),  INT32_C(  1229225296),  INT32_C(  1757518689) },
      {  INT32_C(  1989187036),  INT32_C(   167688246),  INT32_C(  1229225296),  INT32_C(  1757518689) } },
    { {  INT32_C(  2100425953), -INT32_C(   194218555),  INT32_C(  1396762240), -INT32_C(  1027433314) },
      {  INT32_C(  2100425953),  INT32_C(   194218555),  INT32_C(  1396762240),  INT32_C(  1027433314) } },
    { { -INT32_C(   800378362), -INT32_C(   909751175),  INT32_C(   705825481), -INT32_C(  2020354907) },
      {  INT32_C(   800378362),  INT32_C(   909751175),  INT32_C(   705825481),  INT32_C(  2020354907) } },
    { { -INT32_C(  1929067320), -INT32_C(  1165922247), -INT32_C(   183647657),  INT32_C(  1689833566) },
      {  INT32_C(  1929067320),  INT32_C(  1165922247),  INT32_C(   183647657),  INT32_C(  1689833566) } },
    { {  INT32_C(  2067071746),  INT32_C(   423951184), -INT32_C(  1421584890), -INT32_C(   214771926) },
      {  INT32_C(  2067071746),  INT32_C(   423951184),  INT32_C(  1421584890),  INT32_C(   214771926) } },
    { { -INT32_C(   713017445), -INT32_C(    24182105),  INT32_C(   586456260),  INT32_C(  1854319724) },
      {  INT32_C(   713017445),  INT32_C(    24182105),  INT32_C(   586456260),  INT32_C(  1854319724) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vabsq_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabsq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int64_t r[2];
  } test_vec[] = {
    { {                     INT64_MIN, -INT64_C( 2815808507348841371) },
      {                     INT64_MIN,  INT64_C( 2815808507348841371) } },
    { { -INT64_C( 6379743846319689735),  INT64_C( 6714660166886377872) },
      {  INT64_C( 6379743846319689735),  INT64_C( 6714660166886377872) } },
    { {  INT64_C( 6202666085961610503),  INT64_C( 4486453037390956375) },
      {  INT64_C( 6202666085961610503),  INT64_C( 4486453037390956375) } },
    { { -INT64_C( 8218894509259856764), -INT64_C(  784383972760114201) },
      {  INT64_C( 8218894509259856764),  INT64_C(  784383972760114201) } },
    { { -INT64_C( 2789077807162968316),  INT64_C(  990379092211954748) },
      {  INT64_C( 2789077807162968316),  INT64_C(  990379092211954748) } },
    { {  INT64_C( 7887851912833787884), -INT64_C( 1597006666687211790) },
      {  INT64_C( 7887851912833787884),  INT64_C( 1597006666687211790) } },
    { {  INT64_C( 7412125822168790657), -INT64_C( 7623567593992412515) },
      {  INT64_C( 7412125822168790657),  INT64_C( 7623567593992412515) } },
    { { -INT64_C( 4287435838607816052),  INT64_C( 8600604211809725581) },
      {  INT64_C( 4287435838607816052),  INT64_C( 8600604211809725581) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t r = simde_vabsq_s64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vabsd_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vabs_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vabsq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
