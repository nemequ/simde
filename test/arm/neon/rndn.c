#define SIMDE_TEST_ARM_NEON_INSN rndn

#include "test-neon.h"
#include "../../../simde/arm/neon/rndn.h"

static int
test_simde_vrndn_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT32_C(  -593.90), SIMDE_FLOAT32_C(   196.84) },
      { SIMDE_FLOAT32_C(  -594.00), SIMDE_FLOAT32_C(   197.00) } },
    { { SIMDE_FLOAT32_C(   569.79), SIMDE_FLOAT32_C(   336.27) },
      { SIMDE_FLOAT32_C(   570.00), SIMDE_FLOAT32_C(   336.00) } },
    { { SIMDE_FLOAT32_C(  -670.11), SIMDE_FLOAT32_C(   299.96) },
      { SIMDE_FLOAT32_C(  -670.00), SIMDE_FLOAT32_C(   300.00) } },
    { { SIMDE_FLOAT32_C(    -4.27), SIMDE_FLOAT32_C(  -333.31) },
      { SIMDE_FLOAT32_C(    -4.00), SIMDE_FLOAT32_C(  -333.00) } },
    { { SIMDE_FLOAT32_C(  -389.20), SIMDE_FLOAT32_C(   338.21) },
      { SIMDE_FLOAT32_C(  -389.00), SIMDE_FLOAT32_C(   338.00) } },
    { { SIMDE_FLOAT32_C(   172.22), SIMDE_FLOAT32_C(   764.71) },
      { SIMDE_FLOAT32_C(   172.00), SIMDE_FLOAT32_C(   765.00) } },
    { { SIMDE_FLOAT32_C(   789.38), SIMDE_FLOAT32_C(  -740.62) },
      { SIMDE_FLOAT32_C(   789.00), SIMDE_FLOAT32_C(  -741.00) } },
    { { SIMDE_FLOAT32_C(   713.87), SIMDE_FLOAT32_C(   -75.96) },
      { SIMDE_FLOAT32_C(   714.00), SIMDE_FLOAT32_C(   -76.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrndn_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrndn_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndn_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT64_C(   956.89) },
      { SIMDE_FLOAT64_C(   957.00) } },
    { { SIMDE_FLOAT64_C(   240.71) },
      { SIMDE_FLOAT64_C(   241.00) } },
    { { SIMDE_FLOAT64_C(  -255.78) },
      { SIMDE_FLOAT64_C(  -256.00) } },
    { { SIMDE_FLOAT64_C(   583.46) },
      { SIMDE_FLOAT64_C(   583.00) } },
    { { SIMDE_FLOAT64_C(   184.46) },
      { SIMDE_FLOAT64_C(   184.00) } },
    { { SIMDE_FLOAT64_C(  -123.90) },
      { SIMDE_FLOAT64_C(  -124.00) } },
    { { SIMDE_FLOAT64_C(   757.51) },
      { SIMDE_FLOAT64_C(   758.00) } },
    { { SIMDE_FLOAT64_C(   200.47) },
      { SIMDE_FLOAT64_C(   200.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrndn_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrndn_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndnq_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT32_C(   826.17), SIMDE_FLOAT32_C(  -229.41), SIMDE_FLOAT32_C(  -487.35), SIMDE_FLOAT32_C(    89.00) },
      { SIMDE_FLOAT32_C(   826.00), SIMDE_FLOAT32_C(  -229.00), SIMDE_FLOAT32_C(  -487.00), SIMDE_FLOAT32_C(    89.00) } },
    { { SIMDE_FLOAT32_C(  -306.79), SIMDE_FLOAT32_C(  -855.59), SIMDE_FLOAT32_C(   532.14), SIMDE_FLOAT32_C(    99.31) },
      { SIMDE_FLOAT32_C(  -307.00), SIMDE_FLOAT32_C(  -856.00), SIMDE_FLOAT32_C(   532.00), SIMDE_FLOAT32_C(    99.00) } },
    { { SIMDE_FLOAT32_C(   341.26), SIMDE_FLOAT32_C(   101.93), SIMDE_FLOAT32_C(  -564.42), SIMDE_FLOAT32_C(   671.15) },
      { SIMDE_FLOAT32_C(   341.00), SIMDE_FLOAT32_C(   102.00), SIMDE_FLOAT32_C(  -564.00), SIMDE_FLOAT32_C(   671.00) } },
    { { SIMDE_FLOAT32_C(  -598.11), SIMDE_FLOAT32_C(   431.31), SIMDE_FLOAT32_C(  -662.17), SIMDE_FLOAT32_C(    12.69) },
      { SIMDE_FLOAT32_C(  -598.00), SIMDE_FLOAT32_C(   431.00), SIMDE_FLOAT32_C(  -662.00), SIMDE_FLOAT32_C(    13.00) } },
    { { SIMDE_FLOAT32_C(  -230.48), SIMDE_FLOAT32_C(   510.05), SIMDE_FLOAT32_C(  -222.60), SIMDE_FLOAT32_C(  -441.10) },
      { SIMDE_FLOAT32_C(  -230.00), SIMDE_FLOAT32_C(   510.00), SIMDE_FLOAT32_C(  -223.00), SIMDE_FLOAT32_C(  -441.00) } },
    { { SIMDE_FLOAT32_C(   769.43), SIMDE_FLOAT32_C(  -508.73), SIMDE_FLOAT32_C(   482.94), SIMDE_FLOAT32_C(   726.32) },
      { SIMDE_FLOAT32_C(   769.00), SIMDE_FLOAT32_C(  -509.00), SIMDE_FLOAT32_C(   483.00), SIMDE_FLOAT32_C(   726.00) } },
    { { SIMDE_FLOAT32_C(   731.99), SIMDE_FLOAT32_C(  -772.85), SIMDE_FLOAT32_C(   309.78), SIMDE_FLOAT32_C(   -83.55) },
      { SIMDE_FLOAT32_C(   732.00), SIMDE_FLOAT32_C(  -773.00), SIMDE_FLOAT32_C(   310.00), SIMDE_FLOAT32_C(   -84.00) } },
    { { SIMDE_FLOAT32_C(   103.25), SIMDE_FLOAT32_C(    67.29), SIMDE_FLOAT32_C(  -883.08), SIMDE_FLOAT32_C(   -70.58) },
      { SIMDE_FLOAT32_C(   103.00), SIMDE_FLOAT32_C(    67.00), SIMDE_FLOAT32_C(  -883.00), SIMDE_FLOAT32_C(   -71.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndnq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndnq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndnq_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT64_C(   837.88), SIMDE_FLOAT64_C(  -370.43) },
      { SIMDE_FLOAT64_C(   838.00), SIMDE_FLOAT64_C(  -370.00) } },
    { { SIMDE_FLOAT64_C(  -981.58), SIMDE_FLOAT64_C(  -468.91) },
      { SIMDE_FLOAT64_C(  -982.00), SIMDE_FLOAT64_C(  -469.00) } },
    { { SIMDE_FLOAT64_C(  -226.02), SIMDE_FLOAT64_C(   550.56) },
      { SIMDE_FLOAT64_C(  -226.00), SIMDE_FLOAT64_C(   551.00) } },
    { { SIMDE_FLOAT64_C(   630.40), SIMDE_FLOAT64_C(  -884.76) },
      { SIMDE_FLOAT64_C(   630.00), SIMDE_FLOAT64_C(  -885.00) } },
    { { SIMDE_FLOAT64_C(  -347.50), SIMDE_FLOAT64_C(  -934.02) },
      { SIMDE_FLOAT64_C(  -348.00), SIMDE_FLOAT64_C(  -934.00) } },
    { { SIMDE_FLOAT64_C(   786.38), SIMDE_FLOAT64_C(    54.39) },
      { SIMDE_FLOAT64_C(   786.00), SIMDE_FLOAT64_C(    54.00) } },
    { { SIMDE_FLOAT64_C(   497.29), SIMDE_FLOAT64_C(  -875.79) },
      { SIMDE_FLOAT64_C(   497.00), SIMDE_FLOAT64_C(  -876.00) } },
    { { SIMDE_FLOAT64_C(  -932.92), SIMDE_FLOAT64_C(  -733.19) },
      { SIMDE_FLOAT64_C(  -933.00), SIMDE_FLOAT64_C(  -733.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndnq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrndnq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndn_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndn_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndnq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndnq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
