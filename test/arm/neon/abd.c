#define SIMDE_TEST_ARM_NEON_INSN abd

#include "test-neon.h"
#include "../../../simde/arm/neon/abd.h"

/* https://community.intel.com/t5/Intel-C-Compiler/ICC-generates-incorrect-code/td-p/1199261 */
#if defined(HEDLEY_INTEL_VERSION)
#  define TEST_SIMDE_VABD_NO_TEST_32
#endif

static int
test_simde_vabds_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 b;
    simde_float32 r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_MATH_NANF,
      SIMDE_FLOAT32_C(     0.52),
                 SIMDE_MATH_NANF },
    { SIMDE_FLOAT32_C(   705.02),
                 SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF },
    {            SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF },
    #endif

    { SIMDE_FLOAT32_C(   531.62),
      SIMDE_FLOAT32_C(  -312.36),
      SIMDE_FLOAT32_C(   843.98) },
    { SIMDE_FLOAT32_C(  -308.11),
      SIMDE_FLOAT32_C(   992.42),
      SIMDE_FLOAT32_C(  1300.53) },
    { SIMDE_FLOAT32_C(   -79.01),
      SIMDE_FLOAT32_C(   594.71),
      SIMDE_FLOAT32_C(   673.72) },
    { SIMDE_FLOAT32_C(   -32.15),
      SIMDE_FLOAT32_C(   114.85),
      SIMDE_FLOAT32_C(   147.00) },
    { SIMDE_FLOAT32_C(   290.28),
      SIMDE_FLOAT32_C(   100.33),
      SIMDE_FLOAT32_C(   189.95) },
    { SIMDE_FLOAT32_C(  -384.37),
      SIMDE_FLOAT32_C(  -271.65),
      SIMDE_FLOAT32_C(   112.72) },
    { SIMDE_FLOAT32_C(   810.73),
      SIMDE_FLOAT32_C(  -621.11),
      SIMDE_FLOAT32_C(  1431.84) },
    { SIMDE_FLOAT32_C(  -383.51),
      SIMDE_FLOAT32_C(   354.85),
      SIMDE_FLOAT32_C(   738.36) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t r = simde_vabds_f32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vabds_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 b;
    simde_float64 r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {              SIMDE_MATH_NAN,
      SIMDE_FLOAT64_C(     0.52),
                  SIMDE_MATH_NAN },
    { SIMDE_FLOAT64_C(   705.02),
                  SIMDE_MATH_NAN,
                  SIMDE_MATH_NAN },
    {             SIMDE_MATH_NAN,
                  SIMDE_MATH_NAN,
                  SIMDE_MATH_NAN },
    #endif

    { SIMDE_FLOAT64_C(   779.86),
      SIMDE_FLOAT64_C(   261.91),
      SIMDE_FLOAT64_C(   517.95) },
    { SIMDE_FLOAT64_C(   645.51),
      SIMDE_FLOAT64_C(   275.82),
      SIMDE_FLOAT64_C(   369.69) },
    { SIMDE_FLOAT64_C(   482.58),
      SIMDE_FLOAT64_C(  -380.95),
      SIMDE_FLOAT64_C(   863.53) },
    { SIMDE_FLOAT64_C(   670.99),
      SIMDE_FLOAT64_C(   240.67),
      SIMDE_FLOAT64_C(   430.32) },
    { SIMDE_FLOAT64_C(  -761.70),
      SIMDE_FLOAT64_C(  -217.28),
      SIMDE_FLOAT64_C(   544.42) },
    { SIMDE_FLOAT64_C(  -965.81),
      SIMDE_FLOAT64_C(  -145.22),
      SIMDE_FLOAT64_C(   820.59) },
    { SIMDE_FLOAT64_C(   857.99),
      SIMDE_FLOAT64_C(  -115.73),
      SIMDE_FLOAT64_C(   973.72) },
    { SIMDE_FLOAT64_C(   -75.93),
      SIMDE_FLOAT64_C(   547.42),
      SIMDE_FLOAT64_C(   623.35) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r = simde_vabdd_f64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t b = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t r = simde_vabdd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabd_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -378.92), SIMDE_FLOAT32_C(  -620.80) },
      { SIMDE_FLOAT32_C(   475.93), SIMDE_FLOAT32_C(   308.98) },
      { SIMDE_FLOAT32_C(   854.85), SIMDE_FLOAT32_C(   929.78) } },
    { { SIMDE_FLOAT32_C(   159.45), SIMDE_FLOAT32_C(  -785.12) },
      { SIMDE_FLOAT32_C(  -745.18), SIMDE_FLOAT32_C(  -374.75) },
      { SIMDE_FLOAT32_C(   904.63), SIMDE_FLOAT32_C(   410.37) } },
    { { SIMDE_FLOAT32_C(  -423.39), SIMDE_FLOAT32_C(    68.89) },
      { SIMDE_FLOAT32_C(   583.57), SIMDE_FLOAT32_C(   386.20) },
      { SIMDE_FLOAT32_C(  1006.96), SIMDE_FLOAT32_C(   317.31) } },
    { { SIMDE_FLOAT32_C(  -153.15), SIMDE_FLOAT32_C(  -120.40) },
      { SIMDE_FLOAT32_C(   555.60), SIMDE_FLOAT32_C(  -702.70) },
      { SIMDE_FLOAT32_C(   708.75), SIMDE_FLOAT32_C(   582.30) } },
    { { SIMDE_FLOAT32_C(   380.05), SIMDE_FLOAT32_C(   448.15) },
      { SIMDE_FLOAT32_C(   736.37), SIMDE_FLOAT32_C(  -447.93) },
      { SIMDE_FLOAT32_C(   356.32), SIMDE_FLOAT32_C(   896.08) } },
    { { SIMDE_FLOAT32_C(  -910.48), SIMDE_FLOAT32_C(  -966.37) },
      { SIMDE_FLOAT32_C(  -441.23), SIMDE_FLOAT32_C(   -21.68) },
      { SIMDE_FLOAT32_C(   469.25), SIMDE_FLOAT32_C(   944.69) } },
    { { SIMDE_FLOAT32_C(  -684.24), SIMDE_FLOAT32_C(   -42.78) },
      { SIMDE_FLOAT32_C(   785.07), SIMDE_FLOAT32_C(  -505.67) },
      { SIMDE_FLOAT32_C(  1469.31), SIMDE_FLOAT32_C(   462.89) } },
    { { SIMDE_FLOAT32_C(   169.60), SIMDE_FLOAT32_C(   497.90) },
      { SIMDE_FLOAT32_C(    36.47), SIMDE_FLOAT32_C(   790.68) },
      { SIMDE_FLOAT32_C(   133.13), SIMDE_FLOAT32_C(   292.78) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vabd_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vabd_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
   { { SIMDE_FLOAT64_C(   877.10) },
      { SIMDE_FLOAT64_C(  -487.60) },
      { SIMDE_FLOAT64_C(  1364.70) } },
    { { SIMDE_FLOAT64_C(    99.66) },
      { SIMDE_FLOAT64_C(    36.55) },
      { SIMDE_FLOAT64_C(    63.11) } },
    { { SIMDE_FLOAT64_C(  -272.72) },
      { SIMDE_FLOAT64_C(   354.48) },
      { SIMDE_FLOAT64_C(   627.20) } },
    { { SIMDE_FLOAT64_C(   661.80) },
      { SIMDE_FLOAT64_C(   303.89) },
      { SIMDE_FLOAT64_C(   357.91) } },
    { { SIMDE_FLOAT64_C(  -576.63) },
      { SIMDE_FLOAT64_C(   245.37) },
      { SIMDE_FLOAT64_C(   822.00) } },
    { { SIMDE_FLOAT64_C(  -309.90) },
      { SIMDE_FLOAT64_C(   270.22) },
      { SIMDE_FLOAT64_C(   580.12) } },
    { { SIMDE_FLOAT64_C(  -875.02) },
      { SIMDE_FLOAT64_C(  -754.31) },
      { SIMDE_FLOAT64_C(   120.71) } },
    { { SIMDE_FLOAT64_C(   567.52) },
      { SIMDE_FLOAT64_C(   505.03) },
      { SIMDE_FLOAT64_C(    62.49) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vabd_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vabd_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabd_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {      INT8_MAX,      INT8_MAX,  INT8_C(  10),  INT8_C(  10),  INT8_C( 103),  INT8_C(  22), -INT8_C(  16), -INT8_C(  30) },
      { -INT8_C(   1), -INT8_C(   2),  INT8_C(  20), -INT8_C(  10), -INT8_C( 111),  INT8_C(   6), -INT8_C(  68),  INT8_C( 126) },
      {      INT8_MIN, -INT8_C( 127),  INT8_C(  10),  INT8_C(  20), -INT8_C(  42),  INT8_C(  16),  INT8_C(  52), -INT8_C( 100) } },
    { {  INT8_C(  18),  INT8_C(  60),  INT8_C(   4),  INT8_C( 117),  INT8_C( 103),  INT8_C(  22), -INT8_C(  16), -INT8_C(  30) },
      {  INT8_C(  87), -INT8_C(  83), -INT8_C( 104), -INT8_C(  48), -INT8_C( 111),  INT8_C(   6), -INT8_C(  68),  INT8_C( 126) },
      {  INT8_C(  69), -INT8_C( 113),  INT8_C( 108), -INT8_C(  91), -INT8_C(  42),  INT8_C(  16),  INT8_C(  52), -INT8_C( 100) } },
    { { -INT8_C(  87),  INT8_C( 114),  INT8_C( 114),  INT8_C(  23), -INT8_C(   5),  INT8_C(  68), -INT8_C(  72), -INT8_C(  50) },
      {  INT8_C(  90), -INT8_C(  66), -INT8_C(  84),  INT8_C(  51), -INT8_C(  90), -INT8_C(  91),  INT8_C(  49), -INT8_C(  72) },
      { -INT8_C(  79), -INT8_C(  76), -INT8_C(  58),  INT8_C(  28),  INT8_C(  85), -INT8_C(  97),  INT8_C( 121),  INT8_C(  22) } },
    { { -INT8_C(  31),  INT8_C(  53),  INT8_C(  45),  INT8_C(  72),  INT8_C(  75),  INT8_C(  29),  INT8_C(  42), -INT8_C(  94) },
      { -INT8_C(  53), -INT8_C(  62),  INT8_C( 115),  INT8_C(  92), -INT8_C(  55),  INT8_C(  47), -INT8_C(  38),  INT8_C( 114) },
      {  INT8_C(  22),  INT8_C( 115),  INT8_C(  70),  INT8_C(  20), -INT8_C( 126),  INT8_C(  18),  INT8_C(  80), -INT8_C(  48) } },
    { { -INT8_C(  94),  INT8_C(  77), -INT8_C( 118), -INT8_C(  99), -INT8_C( 111),  INT8_C(  66),  INT8_C( 107), -INT8_C(  21) },
      {  INT8_C(   0),  INT8_C(  24),  INT8_C(  30), -INT8_C(  90), -INT8_C(  67),  INT8_C(  79),  INT8_C(  95), -INT8_C(  97) },
      {  INT8_C(  94),  INT8_C(  53), -INT8_C( 108),  INT8_C(   9),  INT8_C(  44),  INT8_C(  13),  INT8_C(  12),  INT8_C(  76) } },
    { { -INT8_C( 123), -INT8_C( 116), -INT8_C(  25), -INT8_C(  48), -INT8_C(  86),  INT8_C(  18),  INT8_C( 115),  INT8_C( 117) },
      { -INT8_C(  44), -INT8_C(  26), -INT8_C(  47), -INT8_C(  99),  INT8_C(  21), -INT8_C(  85),  INT8_C(  16), -INT8_C(  73) },
      {  INT8_C(  79),  INT8_C(  90),  INT8_C(  22),  INT8_C(  51),  INT8_C( 107),  INT8_C( 103),  INT8_C(  99), -INT8_C(  66) } },
    { { -INT8_C(   8), -INT8_C( 102),  INT8_C(  84), -INT8_C( 119), -INT8_C(  36), -INT8_C(  64),  INT8_C( 116), -INT8_C(  35) },
      { -INT8_C(  40), -INT8_C( 109), -INT8_C( 125), -INT8_C( 107), -INT8_C(  30), -INT8_C(  30),  INT8_C(  52),  INT8_C( 103) },
      {  INT8_C(  32),  INT8_C(   7), -INT8_C(  47),  INT8_C(  12),  INT8_C(   6),  INT8_C(  34),  INT8_C(  64), -INT8_C( 118) } },
    { {  INT8_C( 111),  INT8_C(  28),  INT8_C(  56),  INT8_C(  25),  INT8_C(  46), -INT8_C(  85), -INT8_C( 114),  INT8_C(   2) },
      { -INT8_C( 111),  INT8_C(  95), -INT8_C(  96), -INT8_C(  90),  INT8_C(  10), -INT8_C(  80),  INT8_C(  94),  INT8_C(   3) },
      { -INT8_C(  34),  INT8_C(  67), -INT8_C( 104),  INT8_C( 115),  INT8_C(  36),  INT8_C(   5), -INT8_C(  48),  INT8_C(   1) } },
    { {  INT8_C(  74), -INT8_C(  78), -INT8_C( 116),  INT8_C(  38),  INT8_C( 114),  INT8_C(   1),  INT8_C(   3),  INT8_C(  74) },
      { -INT8_C( 108), -INT8_C( 121), -INT8_C(  32),  INT8_C( 118),  INT8_C( 105),  INT8_C(  20), -INT8_C(  34), -INT8_C(  40) },
      { -INT8_C(  74),  INT8_C(  43),  INT8_C(  84),  INT8_C(  80),  INT8_C(   9),  INT8_C(  19),  INT8_C(  37),  INT8_C( 114) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vabd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vabd_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabd_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 32445), -INT16_C( 19967), -INT16_C(  6025),  INT16_C( 10556) },
      {  INT16_C(  8506), -INT16_C(  5656), -INT16_C( 12592),  INT16_C( 28423) },
      {  INT16_C( 23939),  INT16_C( 14311),  INT16_C(  6567),  INT16_C( 17867) } },
    { {  INT16_C( 28389), -INT16_C( 10835),  INT16_C(   977),  INT16_C(  7110) },
      {  INT16_C( 21821), -INT16_C(  4751),  INT16_C(  1025), -INT16_C( 16711) },
      {  INT16_C(  6568),  INT16_C(  6084),  INT16_C(    48),  INT16_C( 23821) } },
    { { -INT16_C( 17790), -INT16_C(  1680), -INT16_C( 21341), -INT16_C(  8926) },
      {  INT16_C(  2765), -INT16_C( 25146), -INT16_C( 12584), -INT16_C( 17140) },
      {  INT16_C( 20555),  INT16_C( 23466),  INT16_C(  8757),  INT16_C(  8214) } },
    { { -INT16_C( 18116),  INT16_C(  3475),  INT16_C( 22972), -INT16_C(  1496) },
      { -INT16_C( 25938), -INT16_C( 20505), -INT16_C( 24162),  INT16_C(  8302) },
      {  INT16_C(  7822),  INT16_C( 23980), -INT16_C( 18402),  INT16_C(  9798) } },
    { { -INT16_C(  8613), -INT16_C(   487),  INT16_C( 15243),  INT16_C( 22748) },
      { -INT16_C( 23995),  INT16_C(  7926),  INT16_C(   624), -INT16_C( 21285) },
      {  INT16_C( 15382),  INT16_C(  8413),  INT16_C( 14619), -INT16_C( 21503) } },
    { {  INT16_C( 28348),  INT16_C( 30905), -INT16_C(  7481),  INT16_C( 30322) },
      {  INT16_C( 23164),  INT16_C(  6693), -INT16_C( 27653),  INT16_C( 22074) },
      {  INT16_C(  5184),  INT16_C( 24212),  INT16_C( 20172),  INT16_C(  8248) } },
    { {  INT16_C( 21362), -INT16_C(   683),  INT16_C( 12686), -INT16_C( 11435) },
      {  INT16_C( 19411),  INT16_C( 17649), -INT16_C( 12978),  INT16_C(  2800) },
      {  INT16_C(  1951),  INT16_C( 18332),  INT16_C( 25664),  INT16_C( 14235) } },
    { { -INT16_C( 21957),  INT16_C(   898), -INT16_C(  2676),  INT16_C(  2169) },
      { -INT16_C( 25009),  INT16_C( 18978),  INT16_C( 23602), -INT16_C( 23392) },
      {  INT16_C(  3052),  INT16_C( 18080),  INT16_C( 26278),  INT16_C( 25561) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vabd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vabd_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vabd_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1034024367), -INT32_C(    99551706) },
      { -INT32_C(  1874984382),  INT32_C(   177876687) },
      { -INT32_C(  1385958547),  INT32_C(   277428393) } },
    { {  INT32_C(  1678580952),  INT32_C(  1617724945) },
      {  INT32_C(  1470795301), -INT32_C(  1711584278) },
      {  INT32_C(   207785651), -INT32_C(   965658073) } },
    { {  INT32_C(  1742117952), -INT32_C(   731781230) },
      { -INT32_C(  1201365015), -INT32_C(  1497170227) },
      { -INT32_C(  1351484329),  INT32_C(   765388997) } },
    { {  INT32_C(   738906139),  INT32_C(  2072868694) },
      { -INT32_C(   254658811), -INT32_C(  1014379134) },
      {  INT32_C(   993564950), -INT32_C(  1207719468) } },
    { { -INT32_C(    64331671),  INT32_C(   818973511) },
      { -INT32_C(   135776982),  INT32_C(  1318955571) },
      {  INT32_C(    71445311),  INT32_C(   499982060) } },
    { { -INT32_C(   780425094),  INT32_C(   608962591) },
      { -INT32_C(  1038868673),  INT32_C(  1451597548) },
      {  INT32_C(   258443579),  INT32_C(   842634957) } },
    { {  INT32_C(  1163046910),  INT32_C(  1685398074) },
      { -INT32_C(  1956946601), -INT32_C(  2099644153) },
      { -INT32_C(  1174973785), -INT32_C(   509925069) } },
    { { -INT32_C(  1068280671), -INT32_C(  1662738596) },
      { -INT32_C(  1419839042), -INT32_C(  1795038313) },
      {  INT32_C(   351558371),  INT32_C(   132299717) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vabd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vabd_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_vabd_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(146), UINT8_C( 83), UINT8_C(218), UINT8_C(204), UINT8_C(117), UINT8_C( 79), UINT8_C( 48), UINT8_C(205) },
      { UINT8_C(172), UINT8_C(139), UINT8_C( 88), UINT8_C(179), UINT8_C(132), UINT8_C( 49), UINT8_C( 53), UINT8_C( 37) },
      { UINT8_C( 26), UINT8_C( 56), UINT8_C(130), UINT8_C( 25), UINT8_C( 15), UINT8_C( 30), UINT8_C(  5), UINT8_C(168) } },
    { { UINT8_C(134), UINT8_C(136), UINT8_C(229), UINT8_C(226), UINT8_C( 40), UINT8_C(202), UINT8_C(126), UINT8_C(230) },
      { UINT8_C(195), UINT8_C(220), UINT8_C(145), UINT8_C( 90), UINT8_C(191), UINT8_C(146), UINT8_C(239), UINT8_C( 81) },
      { UINT8_C( 61), UINT8_C( 84), UINT8_C( 84), UINT8_C(136), UINT8_C(151), UINT8_C( 56), UINT8_C(113), UINT8_C(149) } },
    { { UINT8_C(229), UINT8_C(201), UINT8_C( 29), UINT8_C( 91), UINT8_C( 24), UINT8_C( 77), UINT8_C( 40), UINT8_C(196) },
      { UINT8_C(217), UINT8_C(128), UINT8_C(119), UINT8_C( 93), UINT8_C(177), UINT8_C(173), UINT8_C(131), UINT8_C( 55) },
      { UINT8_C( 12), UINT8_C( 73), UINT8_C( 90), UINT8_C(  2), UINT8_C(153), UINT8_C( 96), UINT8_C( 91), UINT8_C(141) } },
    { { UINT8_C( 53), UINT8_C(104), UINT8_C( 26), UINT8_C( 93), UINT8_C( 50), UINT8_C(152), UINT8_C( 68), UINT8_C(245) },
      { UINT8_C(117), UINT8_C(213), UINT8_C( 79), UINT8_C( 52), UINT8_C(104), UINT8_C( 62), UINT8_C(134), UINT8_C( 77) },
      { UINT8_C( 64), UINT8_C(109), UINT8_C( 53), UINT8_C( 41), UINT8_C( 54), UINT8_C( 90), UINT8_C( 66), UINT8_C(168) } },
    { { UINT8_C(  7), UINT8_C(163), UINT8_C(168), UINT8_C( 31), UINT8_C(241), UINT8_C(208), UINT8_C(227), UINT8_C(202) },
      { UINT8_C( 80), UINT8_C( 91), UINT8_C( 39), UINT8_C(  2), UINT8_C(  8), UINT8_C(170), UINT8_C( 57), UINT8_C( 61) },
      { UINT8_C( 73), UINT8_C( 72), UINT8_C(129), UINT8_C( 29), UINT8_C(233), UINT8_C( 38), UINT8_C(170), UINT8_C(141) } },
    { { UINT8_C( 19), UINT8_C( 83), UINT8_C(155), UINT8_C( 69), UINT8_C(236), UINT8_C(223), UINT8_C( 59), UINT8_C( 97) },
      { UINT8_C(180), UINT8_C(138), UINT8_C(149), UINT8_C( 28), UINT8_C(201), UINT8_C( 27), UINT8_C(106), UINT8_C(208) },
      { UINT8_C(161), UINT8_C( 55), UINT8_C(  6), UINT8_C( 41), UINT8_C( 35), UINT8_C(196), UINT8_C( 47), UINT8_C(111) } },
    { { UINT8_C(191), UINT8_C( 18), UINT8_C(240), UINT8_C(176), UINT8_C(227), UINT8_C(211), UINT8_C(122), UINT8_C( 51) },
      { UINT8_C( 46), UINT8_C(161), UINT8_C( 53), UINT8_C( 54), UINT8_C( 76), UINT8_C(111), UINT8_C(116), UINT8_C( 95) },
      { UINT8_C(145), UINT8_C(143), UINT8_C(187), UINT8_C(122), UINT8_C(151), UINT8_C(100), UINT8_C(  6), UINT8_C( 44) } },
    { { UINT8_C(194), UINT8_C( 15), UINT8_C(164), UINT8_C(174), UINT8_C(238), UINT8_C(223), UINT8_C( 15), UINT8_C(162) },
      { UINT8_C(106), UINT8_C(165), UINT8_C(191), UINT8_C( 51), UINT8_C(192), UINT8_C( 41), UINT8_C(  3), UINT8_C(127) },
      { UINT8_C( 88), UINT8_C(150), UINT8_C( 27), UINT8_C(123), UINT8_C( 46), UINT8_C(182), UINT8_C( 12), UINT8_C( 35) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vabd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vabd_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabd_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(62267), UINT16_C( 7727), UINT16_C(43463), UINT16_C(62802) },
      { UINT16_C(34635), UINT16_C(38700), UINT16_C(41206), UINT16_C(47606) },
      { UINT16_C(27632), UINT16_C(30973), UINT16_C( 2257), UINT16_C(15196) } },
    { { UINT16_C(39599), UINT16_C(40295), UINT16_C(30586), UINT16_C(58431) },
      { UINT16_C(65052), UINT16_C(56343), UINT16_C( 6695), UINT16_C(25436) },
      { UINT16_C(25453), UINT16_C(16048), UINT16_C(23891), UINT16_C(32995) } },
    { { UINT16_C(35598), UINT16_C(54657), UINT16_C(54069), UINT16_C(32970) },
      { UINT16_C(63067), UINT16_C(20759), UINT16_C( 3478), UINT16_C(17674) },
      { UINT16_C(27469), UINT16_C(33898), UINT16_C(50591), UINT16_C(15296) } },
    { { UINT16_C(29351), UINT16_C( 8674), UINT16_C( 8937), UINT16_C( 1285) },
      { UINT16_C( 7200), UINT16_C(18657), UINT16_C(15671), UINT16_C(17835) },
      { UINT16_C(22151), UINT16_C( 9983), UINT16_C( 6734), UINT16_C(16550) } },
    { { UINT16_C(11465), UINT16_C(65050), UINT16_C(58368), UINT16_C(23422) },
      { UINT16_C(38363), UINT16_C(29100), UINT16_C(47010), UINT16_C(18871) },
      { UINT16_C(26898), UINT16_C(35950), UINT16_C(11358), UINT16_C( 4551) } },
    { { UINT16_C(39209), UINT16_C( 4715), UINT16_C(28859), UINT16_C(56343) },
      { UINT16_C(63629), UINT16_C(50212), UINT16_C(53046), UINT16_C(65289) },
      { UINT16_C(24420), UINT16_C(45497), UINT16_C(24187), UINT16_C( 8946) } },
    { { UINT16_C( 9211), UINT16_C(64509), UINT16_C(31495), UINT16_C(57942) },
      { UINT16_C(  784), UINT16_C(45652), UINT16_C( 3002), UINT16_C(58363) },
      { UINT16_C( 8427), UINT16_C(18857), UINT16_C(28493), UINT16_C(  421) } },
    { { UINT16_C(26276), UINT16_C(24821), UINT16_C( 3287), UINT16_C(25660) },
      { UINT16_C(24580), UINT16_C(14888), UINT16_C(12591), UINT16_C(10809) },
      { UINT16_C( 1696), UINT16_C( 9933), UINT16_C( 9304), UINT16_C(14851) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vabd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vabd_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vabd_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1529230932), UINT32_C(3242097841) },
      { UINT32_C( 963875455), UINT32_C(1092382621) },
      { UINT32_C( 565355477), UINT32_C(2149715220) } },
    { { UINT32_C(2896237013), UINT32_C( 571530525) },
      { UINT32_C(1817983037), UINT32_C(3180828265) },
      { UINT32_C(1078253976), UINT32_C(2609297740) } },
    { { UINT32_C(2115616204), UINT32_C(3107936057) },
      { UINT32_C(2264052713), UINT32_C(4157017890) },
      { UINT32_C( 148436509), UINT32_C(1049081833) } },
    { { UINT32_C(1050962208), UINT32_C(2220930118) },
      { UINT32_C(1458617581), UINT32_C( 521439058) },
      { UINT32_C( 407655373), UINT32_C(1699491060) } },
    { { UINT32_C(2124229956), UINT32_C(1832377476) },
      { UINT32_C(2985503119), UINT32_C(1504295480) },
      { UINT32_C( 861273163), UINT32_C( 328081996) } },
    { { UINT32_C(1788300579), UINT32_C(4008638209) },
      { UINT32_C( 105242291), UINT32_C(2854574438) },
      { UINT32_C(1683058288), UINT32_C(1154063771) } },
    { { UINT32_C( 170443398), UINT32_C( 779575198) },
      { UINT32_C(3252644489), UINT32_C(1209698340) },
      { UINT32_C(3082201091), UINT32_C( 430123142) } },
    { { UINT32_C(3618812373), UINT32_C(1556455592) },
      { UINT32_C(3831630462), UINT32_C(3918497635) },
      { UINT32_C( 212818089), UINT32_C(2362042043) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vabd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vabd_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_vabdq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   965.83), SIMDE_FLOAT32_C(  -857.34), SIMDE_FLOAT32_C(  -560.13), SIMDE_FLOAT32_C(  -970.93) },
      { SIMDE_FLOAT32_C(  -821.69), SIMDE_FLOAT32_C(  -283.01), SIMDE_FLOAT32_C(  -858.66), SIMDE_FLOAT32_C(  -780.80) },
      { SIMDE_FLOAT32_C(  1787.52), SIMDE_FLOAT32_C(   574.33), SIMDE_FLOAT32_C(   298.53), SIMDE_FLOAT32_C(   190.13) } },
    { { SIMDE_FLOAT32_C(   655.57), SIMDE_FLOAT32_C(    38.23), SIMDE_FLOAT32_C(   268.19), SIMDE_FLOAT32_C(   578.23) },
      { SIMDE_FLOAT32_C(   673.43), SIMDE_FLOAT32_C(   933.63), SIMDE_FLOAT32_C(  -513.03), SIMDE_FLOAT32_C(   540.19) },
      { SIMDE_FLOAT32_C(    17.86), SIMDE_FLOAT32_C(   895.40), SIMDE_FLOAT32_C(   781.22), SIMDE_FLOAT32_C(    38.04) } },
    { { SIMDE_FLOAT32_C(   559.01), SIMDE_FLOAT32_C(  -436.66), SIMDE_FLOAT32_C(  -201.42), SIMDE_FLOAT32_C(  -191.00) },
      { SIMDE_FLOAT32_C(   509.73), SIMDE_FLOAT32_C(   509.25), SIMDE_FLOAT32_C(    60.09), SIMDE_FLOAT32_C(   510.96) },
      { SIMDE_FLOAT32_C(    49.28), SIMDE_FLOAT32_C(   945.91), SIMDE_FLOAT32_C(   261.51), SIMDE_FLOAT32_C(   701.96) } },
    { { SIMDE_FLOAT32_C(  -928.29), SIMDE_FLOAT32_C(  -315.21), SIMDE_FLOAT32_C(   729.47), SIMDE_FLOAT32_C(   -38.60) },
      { SIMDE_FLOAT32_C(  -141.89), SIMDE_FLOAT32_C(  -957.64), SIMDE_FLOAT32_C(  -323.78), SIMDE_FLOAT32_C(  -176.06) },
      { SIMDE_FLOAT32_C(   786.40), SIMDE_FLOAT32_C(   642.43), SIMDE_FLOAT32_C(  1053.25), SIMDE_FLOAT32_C(   137.46) } },
    { { SIMDE_FLOAT32_C(  -814.98), SIMDE_FLOAT32_C(   116.09), SIMDE_FLOAT32_C(  -146.99), SIMDE_FLOAT32_C(  -636.67) },
      { SIMDE_FLOAT32_C(   833.08), SIMDE_FLOAT32_C(    -5.65), SIMDE_FLOAT32_C(  -417.47), SIMDE_FLOAT32_C(   488.65) },
      { SIMDE_FLOAT32_C(  1648.06), SIMDE_FLOAT32_C(   121.74), SIMDE_FLOAT32_C(   270.48), SIMDE_FLOAT32_C(  1125.32) } },
    { { SIMDE_FLOAT32_C(  -967.42), SIMDE_FLOAT32_C(   850.72), SIMDE_FLOAT32_C(    66.88), SIMDE_FLOAT32_C(   706.02) },
      { SIMDE_FLOAT32_C(   784.35), SIMDE_FLOAT32_C(   553.85), SIMDE_FLOAT32_C(   246.21), SIMDE_FLOAT32_C(   343.36) },
      { SIMDE_FLOAT32_C(  1751.77), SIMDE_FLOAT32_C(   296.87), SIMDE_FLOAT32_C(   179.33), SIMDE_FLOAT32_C(   362.66) } },
    { { SIMDE_FLOAT32_C(  -882.81), SIMDE_FLOAT32_C(  -955.21), SIMDE_FLOAT32_C(  -847.64), SIMDE_FLOAT32_C(   626.92) },
      { SIMDE_FLOAT32_C(   554.03), SIMDE_FLOAT32_C(   212.45), SIMDE_FLOAT32_C(   137.88), SIMDE_FLOAT32_C(   625.74) },
      { SIMDE_FLOAT32_C(  1436.84), SIMDE_FLOAT32_C(  1167.66), SIMDE_FLOAT32_C(   985.52), SIMDE_FLOAT32_C(     1.18) } },
    { { SIMDE_FLOAT32_C(   897.23), SIMDE_FLOAT32_C(  -132.65), SIMDE_FLOAT32_C(  -412.85), SIMDE_FLOAT32_C(  -244.66) },
      { SIMDE_FLOAT32_C(   -90.29), SIMDE_FLOAT32_C(   263.37), SIMDE_FLOAT32_C(   579.28), SIMDE_FLOAT32_C(    94.73) },
      { SIMDE_FLOAT32_C(   987.52), SIMDE_FLOAT32_C(   396.02), SIMDE_FLOAT32_C(   992.13), SIMDE_FLOAT32_C(   339.39) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vabdq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vabdq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -620.54), SIMDE_FLOAT64_C(  -567.71) },
      { SIMDE_FLOAT64_C(   458.06), SIMDE_FLOAT64_C(  -787.46) },
      { SIMDE_FLOAT64_C(  1078.60), SIMDE_FLOAT64_C(   219.75) } },
    { { SIMDE_FLOAT64_C(   426.64), SIMDE_FLOAT64_C(  -959.41) },
      { SIMDE_FLOAT64_C(   701.18), SIMDE_FLOAT64_C(   459.23) },
      { SIMDE_FLOAT64_C(   274.54), SIMDE_FLOAT64_C(  1418.64) } },
    { { SIMDE_FLOAT64_C(   891.32), SIMDE_FLOAT64_C(  -231.93) },
      { SIMDE_FLOAT64_C(   165.24), SIMDE_FLOAT64_C(   675.67) },
      { SIMDE_FLOAT64_C(   726.08), SIMDE_FLOAT64_C(   907.60) } },
    { { SIMDE_FLOAT64_C(  -678.09), SIMDE_FLOAT64_C(  -588.55) },
      { SIMDE_FLOAT64_C(    19.03), SIMDE_FLOAT64_C(  -560.89) },
      { SIMDE_FLOAT64_C(   697.12), SIMDE_FLOAT64_C(    27.66) } },
    { { SIMDE_FLOAT64_C(  -543.76), SIMDE_FLOAT64_C(   171.38) },
      { SIMDE_FLOAT64_C(  -933.97), SIMDE_FLOAT64_C(  -989.73) },
      { SIMDE_FLOAT64_C(   390.21), SIMDE_FLOAT64_C(  1161.11) } },
    { { SIMDE_FLOAT64_C(  -616.17), SIMDE_FLOAT64_C(   203.91) },
      { SIMDE_FLOAT64_C(   636.01), SIMDE_FLOAT64_C(  -718.93) },
      { SIMDE_FLOAT64_C(  1252.18), SIMDE_FLOAT64_C(   922.84) } },
    { { SIMDE_FLOAT64_C(  -928.74), SIMDE_FLOAT64_C(  -776.84) },
      { SIMDE_FLOAT64_C(    36.41), SIMDE_FLOAT64_C(   -19.03) },
      { SIMDE_FLOAT64_C(   965.15), SIMDE_FLOAT64_C(   757.81) } },
    { { SIMDE_FLOAT64_C(   486.53), SIMDE_FLOAT64_C(  -384.31) },
      { SIMDE_FLOAT64_C(  -924.30), SIMDE_FLOAT64_C(   865.99) },
      { SIMDE_FLOAT64_C(  1410.83), SIMDE_FLOAT64_C(  1250.30) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vabdq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vabdq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  96),  INT8_C(   5),  INT8_C(  65), -INT8_C(  34),  INT8_C(  54), -INT8_C(  32),  INT8_C(  28),  INT8_C(   7),
        -INT8_C( 121), -INT8_C(  62), -INT8_C(  84), -INT8_C(  15), -INT8_C( 127), -INT8_C(  16),  INT8_C(  29),  INT8_C(  20) },
      { -INT8_C(  54),  INT8_C(  16), -INT8_C(  97), -INT8_C(   2),  INT8_C(  54),  INT8_C( 104), -INT8_C(  54), -INT8_C( 118),
        -INT8_C(  56),  INT8_C( 113),  INT8_C(  40),  INT8_C(  25),  INT8_C(  54),  INT8_C( 121), -INT8_C( 127), -INT8_C( 106) },
      { -INT8_C( 106),  INT8_C(  11), -INT8_C(  94),  INT8_C(  32),  INT8_C(   0), -INT8_C( 120),  INT8_C(  82),  INT8_C( 125),
         INT8_C(  65), -INT8_C(  81),  INT8_C( 124),  INT8_C(  40), -INT8_C(  75), -INT8_C( 119), -INT8_C( 100),  INT8_C( 126) } },
    { {  INT8_C( 126), -INT8_C(  62),  INT8_C( 116), -INT8_C(  76), -INT8_C(  94), -INT8_C( 112), -INT8_C(  68),  INT8_C(  41),
         INT8_C(  82),  INT8_C( 104),  INT8_C(  26), -INT8_C(  45),  INT8_C(  88),  INT8_C(  56), -INT8_C(  24),  INT8_C(  35) },
      {  INT8_C(  72), -INT8_C( 121),  INT8_C(  33),  INT8_C( 126), -INT8_C(  17), -INT8_C(  21),  INT8_C(   8), -INT8_C(  72),
         INT8_C(  92),  INT8_C(  49), -INT8_C(  47), -INT8_C( 110), -INT8_C(  86),  INT8_C(  82),  INT8_C(  40),  INT8_C(  41) },
      {  INT8_C(  54),  INT8_C(  59),  INT8_C(  83), -INT8_C(  54),  INT8_C(  77),  INT8_C(  91),  INT8_C(  76),  INT8_C( 113),
         INT8_C(  10),  INT8_C(  55),  INT8_C(  73),  INT8_C(  65), -INT8_C(  82),  INT8_C(  26),  INT8_C(  64),  INT8_C(   6) } },
    { {  INT8_C(  20), -INT8_C( 100), -INT8_C(  35), -INT8_C(  74),  INT8_C(  44), -INT8_C( 103), -INT8_C(  33),  INT8_C( 126),
         INT8_C(   1), -INT8_C(   7),  INT8_C(  82),  INT8_C(  90),  INT8_C(  49),  INT8_C(  58),  INT8_C( 125),  INT8_C( 121) },
      { -INT8_C(  63), -INT8_C(  98), -INT8_C(   8), -INT8_C(  80), -INT8_C( 119),  INT8_C(   0),  INT8_C( 104), -INT8_C(  27),
         INT8_C(  49),  INT8_C(  57),  INT8_C( 119), -INT8_C(  36), -INT8_C( 117), -INT8_C(  97),  INT8_C(   5), -INT8_C(  97) },
      {  INT8_C(  83),  INT8_C(   2),  INT8_C(  27),  INT8_C(   6), -INT8_C(  93),  INT8_C( 103), -INT8_C( 119), -INT8_C( 103),
         INT8_C(  48),  INT8_C(  64),  INT8_C(  37),  INT8_C( 126), -INT8_C(  90), -INT8_C( 101),  INT8_C( 120), -INT8_C(  38) } },
    { {  INT8_C(  59), -INT8_C(  30),  INT8_C(  85),  INT8_C( 103),  INT8_C( 124),  INT8_C(  52), -INT8_C(  27),  INT8_C( 125),
         INT8_C(  46),  INT8_C(  55), -INT8_C(  41),  INT8_C(  95),  INT8_C( 113),  INT8_C(  84), -INT8_C(  39),  INT8_C(  50) },
      { -INT8_C(  14), -INT8_C(  47), -INT8_C(  29),  INT8_C( 123), -INT8_C(  47),  INT8_C(  75),  INT8_C(  96),  INT8_C(   3),
        -INT8_C( 123), -INT8_C(  41), -INT8_C(  33),  INT8_C(  16),  INT8_C( 118), -INT8_C(  28), -INT8_C(  80), -INT8_C(  79) },
      {  INT8_C(  73),  INT8_C(  17),  INT8_C( 114),  INT8_C(  20), -INT8_C(  85),  INT8_C(  23),  INT8_C( 123),  INT8_C( 122),
        -INT8_C(  87),  INT8_C(  96),  INT8_C(   8),  INT8_C(  79),  INT8_C(   5),  INT8_C( 112),  INT8_C(  41), -INT8_C( 127) } },
    { { -INT8_C(  58),  INT8_C(   5),  INT8_C(  24),  INT8_C(  66),  INT8_C(  58), -INT8_C(   2), -INT8_C(  64),  INT8_C( 104),
         INT8_C(  53), -INT8_C( 105), -INT8_C(  57), -INT8_C(  89), -INT8_C(  20), -INT8_C(  96), -INT8_C(  39), -INT8_C(  34) },
      {  INT8_C( 113), -INT8_C(  68),  INT8_C(  90),  INT8_C(  67),  INT8_C(   8), -INT8_C(  70),  INT8_C(  70), -INT8_C( 115),
        -INT8_C( 110),  INT8_C(  37), -INT8_C(  99),  INT8_C(   8),  INT8_C(   9),  INT8_C(  77), -INT8_C(  70), -INT8_C(  49) },
      { -INT8_C(  85),  INT8_C(  73),  INT8_C(  66),  INT8_C(   1),  INT8_C(  50),  INT8_C(  68), -INT8_C( 122), -INT8_C(  37),
        -INT8_C(  93), -INT8_C( 114),  INT8_C(  42),  INT8_C(  97),  INT8_C(  29), -INT8_C(  83),  INT8_C(  31),  INT8_C(  15) } },
    { {  INT8_C(  83), -INT8_C(  46),  INT8_C(  18), -INT8_C( 115), -INT8_C(  48), -INT8_C(  46), -INT8_C(  11),  INT8_C(   6),
         INT8_C( 105), -INT8_C(  68), -INT8_C(  83),  INT8_C(  85),  INT8_C(  93), -INT8_C( 122),  INT8_C(  52), -INT8_C(  50) },
      {  INT8_C(  67), -INT8_C( 114),  INT8_C(  17),  INT8_C(  75),  INT8_C(  72),  INT8_C(  87), -INT8_C(  40), -INT8_C(  38),
         INT8_C( 124),  INT8_C( 117), -INT8_C(  29), -INT8_C( 123), -INT8_C(  61), -INT8_C(  99),  INT8_C(  85),  INT8_C(  22) },
      {  INT8_C(  16),  INT8_C(  68),  INT8_C(   1), -INT8_C(  66),  INT8_C( 120), -INT8_C( 123),  INT8_C(  29),  INT8_C(  44),
         INT8_C(  19), -INT8_C(  71),  INT8_C(  54), -INT8_C(  48), -INT8_C( 102),  INT8_C(  23),  INT8_C(  33),  INT8_C(  72) } },
    { {  INT8_C( 111),  INT8_C( 103), -INT8_C(  93),  INT8_C(  64),  INT8_C(  57), -INT8_C( 104),  INT8_C(  70), -INT8_C(  94),
         INT8_C(  84), -INT8_C(  13), -INT8_C(   8), -INT8_C(  79),  INT8_C( 121),  INT8_C(  44),      INT8_MIN, -INT8_C(  68) },
      { -INT8_C(  70), -INT8_C( 111),  INT8_C(   7),  INT8_C(   2), -INT8_C(  23), -INT8_C(  33), -INT8_C(  35),  INT8_C( 101),
         INT8_C(  85), -INT8_C(  64), -INT8_C(  21),  INT8_C(  24),  INT8_C(  93),  INT8_C(  64),  INT8_C(  46), -INT8_C(  52) },
      { -INT8_C(  75), -INT8_C(  42),  INT8_C( 100),  INT8_C(  62),  INT8_C(  80),  INT8_C(  71),  INT8_C( 105), -INT8_C(  61),
         INT8_C(   1),  INT8_C(  51),  INT8_C(  13),  INT8_C( 103),  INT8_C(  28),  INT8_C(  20), -INT8_C(  82),  INT8_C(  16) } },
    { { -INT8_C(  89), -INT8_C(  47),  INT8_C(  12), -INT8_C(  32),  INT8_C( 105),  INT8_C(  82), -INT8_C( 126), -INT8_C(  67),
         INT8_C(  69),  INT8_C( 122),  INT8_C( 111), -INT8_C(  65), -INT8_C(  90), -INT8_C(  17),  INT8_C( 123),  INT8_C(  96) },
      {      INT8_MIN, -INT8_C( 125),  INT8_C(  99),  INT8_C( 105),  INT8_C(  98),  INT8_C(  64), -INT8_C(  49), -INT8_C(  73),
         INT8_C(   0), -INT8_C(  70), -INT8_C(  49),  INT8_C(  93), -INT8_C(   6), -INT8_C(   3),  INT8_C(  41), -INT8_C(  95) },
      {  INT8_C(  39),  INT8_C(  78),  INT8_C(  87), -INT8_C( 119),  INT8_C(   7),  INT8_C(  18),  INT8_C(  77),  INT8_C(   6),
         INT8_C(  69), -INT8_C(  64), -INT8_C(  96), -INT8_C(  98),  INT8_C(  84),  INT8_C(  14),  INT8_C(  82), -INT8_C(  65) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vabdq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vabdq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 14030),  INT16_C( 14209),  INT16_C(   904), -INT16_C( 12555),  INT16_C( 25726),  INT16_C(  9357),  INT16_C(  2131), -INT16_C( 11387) },
      { -INT16_C(  6005), -INT16_C(  4547),  INT16_C(  3112),  INT16_C( 10405),  INT16_C( 30150), -INT16_C( 16251), -INT16_C( 20878),  INT16_C( 16737) },
      {  INT16_C( 20035),  INT16_C( 18756),  INT16_C(  2208),  INT16_C( 22960),  INT16_C(  4424),  INT16_C( 25608),  INT16_C( 23009),  INT16_C( 28124) } },
    { { -INT16_C(  7452),  INT16_C( 28024),  INT16_C( 28133),  INT16_C( 25403), -INT16_C( 14127),  INT16_C(  9352),  INT16_C(  3536),  INT16_C( 23800) },
      {  INT16_C( 13813),  INT16_C(  7498), -INT16_C(  4287),  INT16_C(  1861), -INT16_C( 13724), -INT16_C( 10297),  INT16_C( 10360),  INT16_C( 23832) },
      {  INT16_C( 21265),  INT16_C( 20526),  INT16_C( 32420),  INT16_C( 23542),  INT16_C(   403),  INT16_C( 19649),  INT16_C(  6824),  INT16_C(    32) } },
    { { -INT16_C( 28662), -INT16_C(  4150),  INT16_C(  1534), -INT16_C( 12461), -INT16_C(  9267), -INT16_C( 25100), -INT16_C(  4888), -INT16_C(  8711) },
      {  INT16_C( 17185),  INT16_C( 25338),  INT16_C( 16179), -INT16_C( 26775),  INT16_C( 12297), -INT16_C( 32402), -INT16_C( 31144),  INT16_C( 25310) },
      { -INT16_C( 19689),  INT16_C( 29488),  INT16_C( 14645),  INT16_C( 14314),  INT16_C( 21564),  INT16_C(  7302),  INT16_C( 26256), -INT16_C( 31515) } },
    { { -INT16_C( 22505),  INT16_C(  5457), -INT16_C( 23379),  INT16_C( 31460), -INT16_C( 10113),  INT16_C( 26392),  INT16_C(  4548), -INT16_C(  6844) },
      {  INT16_C( 15957), -INT16_C( 30649), -INT16_C( 20355), -INT16_C( 31201), -INT16_C( 28960),  INT16_C( 14344), -INT16_C(  6636),  INT16_C( 11162) },
      { -INT16_C( 27074), -INT16_C( 29430),  INT16_C(  3024), -INT16_C(  2875),  INT16_C( 18847),  INT16_C( 12048),  INT16_C( 11184),  INT16_C( 18006) } },
    { { -INT16_C(  4977),  INT16_C( 15424),  INT16_C(  9616),  INT16_C(  4279), -INT16_C( 12291), -INT16_C( 15753), -INT16_C( 17184),  INT16_C( 13735) },
      { -INT16_C(  4102),  INT16_C( 30909), -INT16_C(  8801), -INT16_C( 32514),  INT16_C(  1643),  INT16_C( 32696),  INT16_C( 21485),  INT16_C( 31915) },
      {  INT16_C(   875),  INT16_C( 15485),  INT16_C( 18417), -INT16_C( 28743),  INT16_C( 13934), -INT16_C( 17087), -INT16_C( 26867),  INT16_C( 18180) } },
    { { -INT16_C(  5313), -INT16_C( 12360),  INT16_C( 28432),  INT16_C(  3807),  INT16_C( 22334),  INT16_C(  8144),  INT16_C( 30483),  INT16_C(  3412) },
      {  INT16_C(  4710),  INT16_C(  1669), -INT16_C( 31505),  INT16_C( 23174),  INT16_C( 16010),  INT16_C( 30681), -INT16_C( 31599), -INT16_C( 12045) },
      {  INT16_C( 10023),  INT16_C( 14029), -INT16_C(  5599),  INT16_C( 19367),  INT16_C(  6324),  INT16_C( 22537), -INT16_C(  3454),  INT16_C( 15457) } },
    { { -INT16_C( 21392), -INT16_C( 32608),  INT16_C( 32539),  INT16_C( 23182),  INT16_C( 24278), -INT16_C(  5767), -INT16_C( 12842),  INT16_C( 15607) },
      {  INT16_C( 31967), -INT16_C( 12734), -INT16_C( 14336), -INT16_C( 29912),  INT16_C(   519), -INT16_C( 26622), -INT16_C(  2426), -INT16_C(  2455) },
      { -INT16_C( 12177),  INT16_C( 19874), -INT16_C( 18661), -INT16_C( 12442),  INT16_C( 23759),  INT16_C( 20855),  INT16_C( 10416),  INT16_C( 18062) } },
    { {  INT16_C(  2466), -INT16_C( 17033),  INT16_C(  1416),  INT16_C( 24343), -INT16_C( 28572),  INT16_C( 14920),  INT16_C( 16222),  INT16_C( 15734) },
      { -INT16_C( 17988), -INT16_C( 17396),  INT16_C( 13441), -INT16_C( 30649),  INT16_C( 18998), -INT16_C( 17119), -INT16_C( 30144), -INT16_C(  7501) },
      {  INT16_C( 20454),  INT16_C(   363),  INT16_C( 12025), -INT16_C( 10544), -INT16_C( 17966),  INT16_C( 32039), -INT16_C( 19170),  INT16_C( 23235) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vabdq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vabdq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vabdq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   463415955), -INT32_C(  1803897040), -INT32_C(  1513176249), -INT32_C(  1092402174) },
      {  INT32_C(  2138828797),  INT32_C(  1510457891),  INT32_C(  1276585996),  INT32_C(  1160694450) },
      {  INT32_C(  1675412842), -INT32_C(   980612365), -INT32_C(  1505205051), -INT32_C(  2041870672) } },
    { {  INT32_C(   627166965), -INT32_C(   860234875), -INT32_C(  1586329698), -INT32_C(   916498997) },
      {  INT32_C(  1732827716), -INT32_C(  1446948963),  INT32_C(   720820344), -INT32_C(  1737481053) },
      {  INT32_C(  1105660751),  INT32_C(   586714088), -INT32_C(  1987817254),  INT32_C(   820982056) } },
    { {  INT32_C(  2008928754),  INT32_C(  1262778028), -INT32_C(   924010755),  INT32_C(  1334921995) },
      { -INT32_C(  1011427034), -INT32_C(  1586726871), -INT32_C(   204774832),  INT32_C(  2039167879) },
      { -INT32_C(  1274611508), -INT32_C(  1445462397),  INT32_C(   719235923),  INT32_C(   704245884) } },
    { { -INT32_C(  1175369716), -INT32_C(  1157352002), -INT32_C(   159059733),  INT32_C(  1631917371) },
      {  INT32_C(   405076975), -INT32_C(   994471565),  INT32_C(  2058847475), -INT32_C(   856407104) },
      {  INT32_C(  1580446691),  INT32_C(   162880437), -INT32_C(  2077060088), -INT32_C(  1806642821) } },
    { {  INT32_C(  1250289035),  INT32_C(    84248858), -INT32_C(  1241806471), -INT32_C(  1911144289) },
      { -INT32_C(  1348060357), -INT32_C(  1082957876), -INT32_C(  1556469021), -INT32_C(   110088595) },
      { -INT32_C(  1696617904),  INT32_C(  1167206734),  INT32_C(   314662550),  INT32_C(  1801055694) } },
    { {  INT32_C(   759428371), -INT32_C(   130922369),  INT32_C(  1907174866), -INT32_C(  1459633043) },
      { -INT32_C(   883448321), -INT32_C(   410334716),  INT32_C(  1653327093),  INT32_C(    89914354) },
      {  INT32_C(  1642876692),  INT32_C(   279412347),  INT32_C(   253847773),  INT32_C(  1549547397) } },
    { {  INT32_C(  1865588464), -INT32_C(  1184340761), -INT32_C(    30796399), -INT32_C(   660133415) },
      { -INT32_C(   761004338), -INT32_C(  1095160119), -INT32_C(   450870030),  INT32_C(   820673599) },
      { -INT32_C(  1668374494),  INT32_C(    89180642),  INT32_C(   420073631),  INT32_C(  1480807014) } },
    { {  INT32_C(    27204890),  INT32_C(   330958721), -INT32_C(   166599651), -INT32_C(   607143923) },
      { -INT32_C(  2136116553), -INT32_C(  1824626784), -INT32_C(   344432981), -INT32_C(   182754598) },
      { -INT32_C(  2131645853), -INT32_C(  2139381791),  INT32_C(   177833330),  INT32_C(   424389325) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vabdq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vabdq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_vabdq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(127), UINT8_C(186), UINT8_C(246), UINT8_C(  1), UINT8_C(194), UINT8_C(177), UINT8_C( 20), UINT8_C(223),
        UINT8_C(149), UINT8_C( 37), UINT8_C(213), UINT8_C(163), UINT8_C(222), UINT8_C(164), UINT8_C(126), UINT8_C(149) },
      { UINT8_C( 23), UINT8_C( 44), UINT8_C( 21), UINT8_C(183), UINT8_C(147), UINT8_C( 83), UINT8_C( 74), UINT8_C( 62),
        UINT8_C(177), UINT8_C(194), UINT8_C( 41), UINT8_C(140), UINT8_C( 37), UINT8_C( 68), UINT8_C(129), UINT8_C(164) },
      { UINT8_C(104), UINT8_C(142), UINT8_C(225), UINT8_C(182), UINT8_C( 47), UINT8_C( 94), UINT8_C( 54), UINT8_C(161),
        UINT8_C( 28), UINT8_C(157), UINT8_C(172), UINT8_C( 23), UINT8_C(185), UINT8_C( 96), UINT8_C(  3), UINT8_C( 15) } },
    { {    UINT8_MAX, UINT8_C(119), UINT8_C(165), UINT8_C(193), UINT8_C( 40), UINT8_C(185), UINT8_C(160), UINT8_C(190),
        UINT8_C(223), UINT8_C(117), UINT8_C( 97), UINT8_C(189), UINT8_C( 26), UINT8_C(223), UINT8_C( 82), UINT8_C( 49) },
      { UINT8_C( 11), UINT8_C(103), UINT8_C(232), UINT8_C(158), UINT8_C(186), UINT8_C( 51), UINT8_C(221), UINT8_C(107),
        UINT8_C(245), UINT8_C(  6), UINT8_C(247), UINT8_C( 26), UINT8_C( 75), UINT8_C(120), UINT8_C(191), UINT8_C( 74) },
      { UINT8_C(244), UINT8_C( 16), UINT8_C( 67), UINT8_C( 35), UINT8_C(146), UINT8_C(134), UINT8_C( 61), UINT8_C( 83),
        UINT8_C( 22), UINT8_C(111), UINT8_C(150), UINT8_C(163), UINT8_C( 49), UINT8_C(103), UINT8_C(109), UINT8_C( 25) } },
    { { UINT8_C(240), UINT8_C(100), UINT8_C( 11), UINT8_C( 24), UINT8_C( 30), UINT8_C(171), UINT8_C(214), UINT8_C(253),
        UINT8_C( 32), UINT8_C( 55), UINT8_C(186), UINT8_C( 58), UINT8_C( 23), UINT8_C( 12), UINT8_C(107), UINT8_C( 34) },
      { UINT8_C(115), UINT8_C( 84), UINT8_C(193), UINT8_C( 45), UINT8_C(135), UINT8_C(158), UINT8_C(152), UINT8_C(124),
        UINT8_C(164), UINT8_C(144), UINT8_C(151), UINT8_C(239), UINT8_C(  8), UINT8_C( 86), UINT8_C( 57), UINT8_C(248) },
      { UINT8_C(125), UINT8_C( 16), UINT8_C(182), UINT8_C( 21), UINT8_C(105), UINT8_C( 13), UINT8_C( 62), UINT8_C(129),
        UINT8_C(132), UINT8_C( 89), UINT8_C( 35), UINT8_C(181), UINT8_C( 15), UINT8_C( 74), UINT8_C( 50), UINT8_C(214) } },
    { { UINT8_C(186), UINT8_C( 68), UINT8_C( 17), UINT8_C(216), UINT8_C(239), UINT8_C(231), UINT8_C(213), UINT8_C( 16),
        UINT8_C( 31), UINT8_C(143), UINT8_C( 74), UINT8_C( 54), UINT8_C(155), UINT8_C(182), UINT8_C( 88), UINT8_C( 14) },
      { UINT8_C( 10), UINT8_C( 25), UINT8_C( 59), UINT8_C(145), UINT8_C(183), UINT8_C(212), UINT8_C( 13), UINT8_C( 92),
        UINT8_C(100), UINT8_C(164), UINT8_C( 75), UINT8_C(108), UINT8_C(250), UINT8_C(133), UINT8_C(101), UINT8_C(181) },
      { UINT8_C(176), UINT8_C( 43), UINT8_C( 42), UINT8_C( 71), UINT8_C( 56), UINT8_C( 19), UINT8_C(200), UINT8_C( 76),
        UINT8_C( 69), UINT8_C( 21), UINT8_C(  1), UINT8_C( 54), UINT8_C( 95), UINT8_C( 49), UINT8_C( 13), UINT8_C(167) } },
    { { UINT8_C(201), UINT8_C(118), UINT8_C(141), UINT8_C(185), UINT8_C( 93), UINT8_C( 99), UINT8_C(201), UINT8_C(124),
        UINT8_C(242), UINT8_C( 19), UINT8_C(178), UINT8_C(142), UINT8_C(201), UINT8_C( 11), UINT8_C(156), UINT8_C(211) },
      { UINT8_C( 36), UINT8_C(216), UINT8_C(100), UINT8_C(220), UINT8_C(172), UINT8_C(114), UINT8_C( 56), UINT8_C( 16),
        UINT8_C( 22), UINT8_C(131), UINT8_C(124), UINT8_C( 17), UINT8_C(  8), UINT8_C(225), UINT8_C(198), UINT8_C(210) },
      { UINT8_C(165), UINT8_C( 98), UINT8_C( 41), UINT8_C( 35), UINT8_C( 79), UINT8_C( 15), UINT8_C(145), UINT8_C(108),
        UINT8_C(220), UINT8_C(112), UINT8_C( 54), UINT8_C(125), UINT8_C(193), UINT8_C(214), UINT8_C( 42), UINT8_C(  1) } },
    { { UINT8_C( 87), UINT8_C( 83), UINT8_C(139), UINT8_C(181), UINT8_C(182), UINT8_C( 84), UINT8_C( 49), UINT8_C(169),
        UINT8_C(103), UINT8_C(228), UINT8_C( 55), UINT8_C( 49), UINT8_C(239), UINT8_C(211), UINT8_C(  4), UINT8_C( 19) },
      { UINT8_C(171), UINT8_C(105), UINT8_C(239), UINT8_C( 87), UINT8_C(219), UINT8_C( 39), UINT8_C(103), UINT8_C(241),
        UINT8_C(171), UINT8_C(228), UINT8_C(  2), UINT8_C(179), UINT8_C(197), UINT8_C(200), UINT8_C(133), UINT8_C( 29) },
      { UINT8_C( 84), UINT8_C( 22), UINT8_C(100), UINT8_C( 94), UINT8_C( 37), UINT8_C( 45), UINT8_C( 54), UINT8_C( 72),
        UINT8_C( 68), UINT8_C(  0), UINT8_C( 53), UINT8_C(130), UINT8_C( 42), UINT8_C( 11), UINT8_C(129), UINT8_C( 10) } },
    { { UINT8_C( 28), UINT8_C( 16), UINT8_C(210), UINT8_C(210), UINT8_C(100), UINT8_C(  3), UINT8_C(123), UINT8_C(204),
        UINT8_C(231), UINT8_C(178), UINT8_C(253), UINT8_C(214), UINT8_C(134), UINT8_C(  1), UINT8_C(234), UINT8_C( 49) },
      { UINT8_C(106), UINT8_C(217), UINT8_C(137), UINT8_C( 69), UINT8_C(  1), UINT8_C(240), UINT8_C( 55), UINT8_C(172),
        UINT8_C(212), UINT8_C( 57), UINT8_C( 95), UINT8_C(154), UINT8_C(  2), UINT8_C(229), UINT8_C(183), UINT8_C( 30) },
      { UINT8_C( 78), UINT8_C(201), UINT8_C( 73), UINT8_C(141), UINT8_C( 99), UINT8_C(237), UINT8_C( 68), UINT8_C( 32),
        UINT8_C( 19), UINT8_C(121), UINT8_C(158), UINT8_C( 60), UINT8_C(132), UINT8_C(228), UINT8_C( 51), UINT8_C( 19) } },
    { { UINT8_C(245), UINT8_C(137), UINT8_C(240), UINT8_C( 90), UINT8_C(140), UINT8_C(108), UINT8_C( 38), UINT8_C(116),
        UINT8_C( 30), UINT8_C( 35), UINT8_C( 74), UINT8_C(164), UINT8_C( 36), UINT8_C( 52), UINT8_C(214), UINT8_C(143) },
      { UINT8_C( 14), UINT8_C( 95), UINT8_C(212), UINT8_C( 15), UINT8_C( 79), UINT8_C( 11), UINT8_C(187), UINT8_C( 36),
        UINT8_C( 69), UINT8_C( 26), UINT8_C(190), UINT8_C( 71),    UINT8_MAX, UINT8_C(117), UINT8_C(101), UINT8_C(245) },
      { UINT8_C(231), UINT8_C( 42), UINT8_C( 28), UINT8_C( 75), UINT8_C( 61), UINT8_C( 97), UINT8_C(149), UINT8_C( 80),
        UINT8_C( 39), UINT8_C(  9), UINT8_C(116), UINT8_C( 93), UINT8_C(219), UINT8_C( 65), UINT8_C(113), UINT8_C(102) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vabdq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vabdq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(22014), UINT16_C(35407), UINT16_C(30145), UINT16_C(57598), UINT16_C(18840), UINT16_C(48260), UINT16_C(23165), UINT16_C(35659) },
      { UINT16_C( 8377), UINT16_C( 2458), UINT16_C(21803), UINT16_C(28717), UINT16_C(60272), UINT16_C(28599), UINT16_C( 7264), UINT16_C(24164) },
      { UINT16_C(13637), UINT16_C(32949), UINT16_C( 8342), UINT16_C(28881), UINT16_C(41432), UINT16_C(19661), UINT16_C(15901), UINT16_C(11495) } },
    { { UINT16_C(45938), UINT16_C(13288), UINT16_C(59176), UINT16_C(49171), UINT16_C(38960), UINT16_C(44413), UINT16_C(51442), UINT16_C(44089) },
      { UINT16_C(54248), UINT16_C( 5301), UINT16_C(57897), UINT16_C(39300), UINT16_C(15565), UINT16_C(11528), UINT16_C(27992), UINT16_C(51851) },
      { UINT16_C( 8310), UINT16_C( 7987), UINT16_C( 1279), UINT16_C( 9871), UINT16_C(23395), UINT16_C(32885), UINT16_C(23450), UINT16_C( 7762) } },
    { { UINT16_C(29472), UINT16_C(18942), UINT16_C( 4442), UINT16_C(35337), UINT16_C(34473), UINT16_C(39992), UINT16_C(29007), UINT16_C(14152) },
      { UINT16_C(64836), UINT16_C(27979), UINT16_C(53471), UINT16_C(44038), UINT16_C( 3852), UINT16_C(25817), UINT16_C(25724), UINT16_C(39983) },
      { UINT16_C(35364), UINT16_C( 9037), UINT16_C(49029), UINT16_C( 8701), UINT16_C(30621), UINT16_C(14175), UINT16_C( 3283), UINT16_C(25831) } },
    { { UINT16_C(11735), UINT16_C(13029), UINT16_C(61246), UINT16_C(59580), UINT16_C(62581), UINT16_C(50308), UINT16_C(52325), UINT16_C(43772) },
      { UINT16_C(18377), UINT16_C(43031), UINT16_C( 7703), UINT16_C( 9044), UINT16_C(11565), UINT16_C(43400), UINT16_C(46993), UINT16_C(26693) },
      { UINT16_C( 6642), UINT16_C(30002), UINT16_C(53543), UINT16_C(50536), UINT16_C(51016), UINT16_C( 6908), UINT16_C( 5332), UINT16_C(17079) } },
    { { UINT16_C(11236), UINT16_C( 8858), UINT16_C(22298), UINT16_C(36618), UINT16_C(36427), UINT16_C(45396), UINT16_C(20570), UINT16_C( 9051) },
      { UINT16_C(29335), UINT16_C(45003), UINT16_C( 8080), UINT16_C(48594), UINT16_C(23116), UINT16_C(56678), UINT16_C(44049), UINT16_C(62790) },
      { UINT16_C(18099), UINT16_C(36145), UINT16_C(14218), UINT16_C(11976), UINT16_C(13311), UINT16_C(11282), UINT16_C(23479), UINT16_C(53739) } },
    { { UINT16_C(57559), UINT16_C(61720), UINT16_C( 8759), UINT16_C(33664), UINT16_C(54449), UINT16_C( 2868), UINT16_C(36644), UINT16_C(48175) },
      { UINT16_C(64001), UINT16_C(37483), UINT16_C(15642), UINT16_C(26191), UINT16_C(46744), UINT16_C(43332), UINT16_C(35426), UINT16_C(14751) },
      { UINT16_C( 6442), UINT16_C(24237), UINT16_C( 6883), UINT16_C( 7473), UINT16_C( 7705), UINT16_C(40464), UINT16_C( 1218), UINT16_C(33424) } },
    { { UINT16_C(46954), UINT16_C(41514), UINT16_C(43737), UINT16_C(35365), UINT16_C(22911), UINT16_C(41878), UINT16_C(50664), UINT16_C(59743) },
      { UINT16_C(51903), UINT16_C(55675), UINT16_C(51976), UINT16_C(41024), UINT16_C(33921), UINT16_C(58185), UINT16_C(59406), UINT16_C(30748) },
      { UINT16_C( 4949), UINT16_C(14161), UINT16_C( 8239), UINT16_C( 5659), UINT16_C(11010), UINT16_C(16307), UINT16_C( 8742), UINT16_C(28995) } },
    { { UINT16_C(18079), UINT16_C(31002), UINT16_C(16368), UINT16_C(28419), UINT16_C(39320), UINT16_C(32787), UINT16_C(29278), UINT16_C( 7786) },
      { UINT16_C(58685), UINT16_C(17911), UINT16_C(14256), UINT16_C(12773), UINT16_C(11963), UINT16_C(51476), UINT16_C(12311), UINT16_C(46658) },
      { UINT16_C(40606), UINT16_C(13091), UINT16_C( 2112), UINT16_C(15646), UINT16_C(27357), UINT16_C(18689), UINT16_C(16967), UINT16_C(38872) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vabdq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vabdq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vabdq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1731157110), UINT32_C( 886453148), UINT32_C( 733342156), UINT32_C(2571706204) },
      { UINT32_C(3051241476), UINT32_C( 870761336), UINT32_C( 150862833), UINT32_C(2730442539) },
      { UINT32_C(1320084366), UINT32_C(  15691812), UINT32_C( 582479323), UINT32_C( 158736335) } },
    { { UINT32_C( 923397787), UINT32_C(4000112417), UINT32_C( 622404041), UINT32_C(1153327680) },
      { UINT32_C( 452566178), UINT32_C(1347346527), UINT32_C( 106515419), UINT32_C( 631773322) },
      { UINT32_C( 470831609), UINT32_C(2652765890), UINT32_C( 515888622), UINT32_C( 521554358) } },
    { { UINT32_C( 677228806), UINT32_C(1511442833), UINT32_C( 712978410), UINT32_C( 862862737) },
      { UINT32_C( 944662745), UINT32_C( 596155464), UINT32_C(1898570215), UINT32_C(   9884409) },
      { UINT32_C( 267433939), UINT32_C( 915287369), UINT32_C(1185591805), UINT32_C( 852978328) } },
    { { UINT32_C( 338228099), UINT32_C(2792242876), UINT32_C(4275105133), UINT32_C(  53559082) },
      { UINT32_C(4013653927), UINT32_C(  34784283), UINT32_C(2675129253), UINT32_C(2443119117) },
      { UINT32_C(3675425828), UINT32_C(2757458593), UINT32_C(1599975880), UINT32_C(2389560035) } },
    { { UINT32_C(3131426813), UINT32_C(1918899205), UINT32_C( 745550081), UINT32_C( 388997488) },
      { UINT32_C(1007053601), UINT32_C(3560904751), UINT32_C(1634972243), UINT32_C(3136426684) },
      { UINT32_C(2124373212), UINT32_C(1642005546), UINT32_C( 889422162), UINT32_C(2747429196) } },
    { { UINT32_C(3732183001), UINT32_C(2907755691), UINT32_C(1977204741), UINT32_C(2206992482) },
      { UINT32_C(2730463859), UINT32_C(4269276842), UINT32_C(1835002545), UINT32_C(3592901117) },
      { UINT32_C(1001719142), UINT32_C(1361521151), UINT32_C( 142202196), UINT32_C(1385908635) } },
    { { UINT32_C(2494929896), UINT32_C(1967195504), UINT32_C( 686496454), UINT32_C(2527819554) },
      { UINT32_C(3023596042), UINT32_C( 447917929), UINT32_C(2542211482), UINT32_C(1265479522) },
      { UINT32_C( 528666146), UINT32_C(1519277575), UINT32_C(1855715028), UINT32_C(1262340032) } },
    { { UINT32_C(3135185482), UINT32_C(3996131368), UINT32_C(1544952634), UINT32_C(2633154962) },
      { UINT32_C(2488347435), UINT32_C(1957561306), UINT32_C(1997223445), UINT32_C( 801274341) },
      { UINT32_C( 646838047), UINT32_C(2038570062), UINT32_C( 452270811), UINT32_C(1831880621) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vabdq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vabdq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vabds_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdd_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vabd_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vabd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabd_u16)

SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_u16)

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
  SIMDE_TEST_FUNC_LIST_ENTRY(vabd_s32)
  SIMDE_TEST_FUNC_LIST_ENTRY(vabd_u32)
  SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_u32)
  SIMDE_TEST_FUNC_LIST_ENTRY(vabdq_s32)
#endif
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
