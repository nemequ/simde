#define SIMDE_TEST_ARM_NEON_INSN rndi

#include "test-neon.h"
#include "../../../simde/arm/neon/rndi.h"

static int
test_simde_vrndi_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF } },
    #endif
    { { SIMDE_FLOAT32_C(    -1.50), SIMDE_FLOAT32_C(     1.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },
    { { SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },

    { { SIMDE_FLOAT32_C(  -787.65), SIMDE_FLOAT32_C(  -795.95) },
      { SIMDE_FLOAT32_C(  -788.00), SIMDE_FLOAT32_C(  -796.00) } },
    { { SIMDE_FLOAT32_C(   899.31), SIMDE_FLOAT32_C(   -93.42) },
      { SIMDE_FLOAT32_C(   899.00), SIMDE_FLOAT32_C(   -93.00) } },
    { { SIMDE_FLOAT32_C(  -436.50), SIMDE_FLOAT32_C(  -165.94) },
      { SIMDE_FLOAT32_C(  -436.00), SIMDE_FLOAT32_C(  -166.00) } },
    { { SIMDE_FLOAT32_C(  -516.13), SIMDE_FLOAT32_C(  -288.52) },
      { SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(  -289.00) } },
    { { SIMDE_FLOAT32_C(  -568.31), SIMDE_FLOAT32_C(  -937.97) },
      { SIMDE_FLOAT32_C(  -568.00), SIMDE_FLOAT32_C(  -938.00) } },
    { { SIMDE_FLOAT32_C(   827.64), SIMDE_FLOAT32_C(   984.63) },
      { SIMDE_FLOAT32_C(   828.00), SIMDE_FLOAT32_C(   985.00) } },
    { { SIMDE_FLOAT32_C(   261.25), SIMDE_FLOAT32_C(   -11.30) },
      { SIMDE_FLOAT32_C(   261.00), SIMDE_FLOAT32_C(   -11.00) } },
    { { SIMDE_FLOAT32_C(    97.38), SIMDE_FLOAT32_C(  -824.40) },
      { SIMDE_FLOAT32_C(    97.00), SIMDE_FLOAT32_C(  -824.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrndi_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrndi_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndi_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    { {            -SIMDE_MATH_NAN },
      {            -SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(    -1.50) },
      { SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(     1.50) },
      { SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(    -2.50) },
      { SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(     2.00) } },

    { { SIMDE_FLOAT64_C(  -405.63) },
      { SIMDE_FLOAT64_C(  -406.00) } },
    { { SIMDE_FLOAT64_C(   554.36) },
      { SIMDE_FLOAT64_C(   554.00) } },
    { { SIMDE_FLOAT64_C(  -286.09) },
      { SIMDE_FLOAT64_C(  -286.00) } },
    { { SIMDE_FLOAT64_C(  -583.84) },
      { SIMDE_FLOAT64_C(  -584.00) } },
    { { SIMDE_FLOAT64_C(  -389.59) },
      { SIMDE_FLOAT64_C(  -390.00) } },
    { { SIMDE_FLOAT64_C(  -683.98) },
      { SIMDE_FLOAT64_C(  -684.00) } },
    { { SIMDE_FLOAT64_C(   628.93) },
      { SIMDE_FLOAT64_C(   629.00) } },
    { { SIMDE_FLOAT64_C(  -112.86) },
      { SIMDE_FLOAT64_C(  -113.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrndi_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrndi_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndiq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF } },
    #endif
    { { SIMDE_FLOAT32_C(    -1.50), SIMDE_FLOAT32_C(     1.50), SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },

    { { SIMDE_FLOAT32_C(  -938.67), SIMDE_FLOAT32_C(  -583.30), SIMDE_FLOAT32_C(  -219.07), SIMDE_FLOAT32_C(   510.59) },
      { SIMDE_FLOAT32_C(  -939.00), SIMDE_FLOAT32_C(  -583.00), SIMDE_FLOAT32_C(  -219.00), SIMDE_FLOAT32_C(   511.00) } },
    { { SIMDE_FLOAT32_C(  -715.91), SIMDE_FLOAT32_C(  -372.75), SIMDE_FLOAT32_C(  -712.38), SIMDE_FLOAT32_C(  -503.56) },
      { SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -373.00), SIMDE_FLOAT32_C(  -712.00), SIMDE_FLOAT32_C(  -504.00) } },
    { { SIMDE_FLOAT32_C(  -168.71), SIMDE_FLOAT32_C(  -813.07), SIMDE_FLOAT32_C(   403.02), SIMDE_FLOAT32_C(   394.80) },
      { SIMDE_FLOAT32_C(  -169.00), SIMDE_FLOAT32_C(  -813.00), SIMDE_FLOAT32_C(   403.00), SIMDE_FLOAT32_C(   395.00) } },
    { { SIMDE_FLOAT32_C(    21.00), SIMDE_FLOAT32_C(   886.89), SIMDE_FLOAT32_C(  -893.72), SIMDE_FLOAT32_C(   452.69) },
      { SIMDE_FLOAT32_C(    21.00), SIMDE_FLOAT32_C(   887.00), SIMDE_FLOAT32_C(  -894.00), SIMDE_FLOAT32_C(   453.00) } },
    { { SIMDE_FLOAT32_C(   948.91), SIMDE_FLOAT32_C(   933.92), SIMDE_FLOAT32_C(   437.32), SIMDE_FLOAT32_C(   210.16) },
      { SIMDE_FLOAT32_C(   949.00), SIMDE_FLOAT32_C(   934.00), SIMDE_FLOAT32_C(   437.00), SIMDE_FLOAT32_C(   210.00) } },
    { { SIMDE_FLOAT32_C(   -77.38), SIMDE_FLOAT32_C(  -465.30), SIMDE_FLOAT32_C(   385.77), SIMDE_FLOAT32_C(   516.99) },
      { SIMDE_FLOAT32_C(   -77.00), SIMDE_FLOAT32_C(  -465.00), SIMDE_FLOAT32_C(   386.00), SIMDE_FLOAT32_C(   517.00) } },
    { { SIMDE_FLOAT32_C(  -910.94), SIMDE_FLOAT32_C(  -900.33), SIMDE_FLOAT32_C(   933.15), SIMDE_FLOAT32_C(  -300.52) },
      { SIMDE_FLOAT32_C(  -911.00), SIMDE_FLOAT32_C(  -900.00), SIMDE_FLOAT32_C(   933.00), SIMDE_FLOAT32_C(  -301.00) } },
    { { SIMDE_FLOAT32_C(  -584.31), SIMDE_FLOAT32_C(   562.08), SIMDE_FLOAT32_C(   586.62), SIMDE_FLOAT32_C(  -522.98) },
      { SIMDE_FLOAT32_C(  -584.00), SIMDE_FLOAT32_C(   562.00), SIMDE_FLOAT32_C(   587.00), SIMDE_FLOAT32_C(  -523.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndiq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndiq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndiq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(    -1.50), SIMDE_FLOAT64_C(     1.50) },
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(    -2.50), SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     2.00) } },

    { { SIMDE_FLOAT64_C(   978.78), SIMDE_FLOAT64_C(  -632.45) },
      { SIMDE_FLOAT64_C(   979.00), SIMDE_FLOAT64_C(  -632.00) } },
    { { SIMDE_FLOAT64_C(   987.61), SIMDE_FLOAT64_C(  -737.13) },
      { SIMDE_FLOAT64_C(   988.00), SIMDE_FLOAT64_C(  -737.00) } },
    { { SIMDE_FLOAT64_C(    -5.20), SIMDE_FLOAT64_C(  -724.77) },
      { SIMDE_FLOAT64_C(    -5.00), SIMDE_FLOAT64_C(  -725.00) } },
    { { SIMDE_FLOAT64_C(  -240.69), SIMDE_FLOAT64_C(   826.09) },
      { SIMDE_FLOAT64_C(  -241.00), SIMDE_FLOAT64_C(   826.00) } },
    { { SIMDE_FLOAT64_C(  -537.84), SIMDE_FLOAT64_C(  -837.67) },
      { SIMDE_FLOAT64_C(  -538.00), SIMDE_FLOAT64_C(  -838.00) } },
    { { SIMDE_FLOAT64_C(   220.89), SIMDE_FLOAT64_C(   483.16) },
      { SIMDE_FLOAT64_C(   221.00), SIMDE_FLOAT64_C(   483.00) } },
    { { SIMDE_FLOAT64_C(  -950.78), SIMDE_FLOAT64_C(   327.17) },
      { SIMDE_FLOAT64_C(  -951.00), SIMDE_FLOAT64_C(   327.00) } },
    { { SIMDE_FLOAT64_C(   -64.15), SIMDE_FLOAT64_C(   998.14) },
      { SIMDE_FLOAT64_C(   -64.00), SIMDE_FLOAT64_C(   998.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndiq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrndiq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndi_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndi_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndiq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndiq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
