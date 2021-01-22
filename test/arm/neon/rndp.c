#define SIMDE_TEST_ARM_NEON_INSN rndp

#include "test-neon.h"
#include "../../../simde/arm/neon/rndp.h"

static int
test_simde_vrndp_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     2.00) } },
    { { SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     3.00) } },
    { { SIMDE_FLOAT32_C(  -980.04), SIMDE_FLOAT32_C(   939.96) },
      { SIMDE_FLOAT32_C(  -980.00), SIMDE_FLOAT32_C(   940.00) } },
    { { SIMDE_FLOAT32_C(   208.31), SIMDE_FLOAT32_C(  -110.24) },
      { SIMDE_FLOAT32_C(   209.00), SIMDE_FLOAT32_C(  -110.00) } },
    { { SIMDE_FLOAT32_C(  -288.01), SIMDE_FLOAT32_C(   612.61) },
      { SIMDE_FLOAT32_C(  -288.00), SIMDE_FLOAT32_C(   613.00) } },
    { { SIMDE_FLOAT32_C(   975.34), SIMDE_FLOAT32_C(   999.38) },
      { SIMDE_FLOAT32_C(   976.00), SIMDE_FLOAT32_C(  1000.00) } },
    { { SIMDE_FLOAT32_C(  -633.20), SIMDE_FLOAT32_C(  -603.45) },
      { SIMDE_FLOAT32_C(  -633.00), SIMDE_FLOAT32_C(  -603.00) } },
    { { SIMDE_FLOAT32_C(    29.78), SIMDE_FLOAT32_C(   554.21) },
      { SIMDE_FLOAT32_C(    30.00), SIMDE_FLOAT32_C(   555.00) } },
    { { SIMDE_FLOAT32_C(  -734.21), SIMDE_FLOAT32_C(   840.44) },
      { SIMDE_FLOAT32_C(  -734.00), SIMDE_FLOAT32_C(   841.00) } },
    { { SIMDE_FLOAT32_C(   418.90), SIMDE_FLOAT32_C(   259.02) },
      { SIMDE_FLOAT32_C(   419.00), SIMDE_FLOAT32_C(   260.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrndp_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrndp_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndp_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C(    -1.00) } },
    { { SIMDE_FLOAT64_C(     1.50) },
      { SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(    -2.50) },
      { SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(     3.00) } },
    { { SIMDE_FLOAT64_C(  -235.01) },
      { SIMDE_FLOAT64_C(  -235.00) } },
    { { SIMDE_FLOAT64_C(  -729.80) },
      { SIMDE_FLOAT64_C(  -729.00) } },
    { { SIMDE_FLOAT64_C(  -569.69) },
      { SIMDE_FLOAT64_C(  -569.00) } },
    { { SIMDE_FLOAT64_C(  -128.47) },
      { SIMDE_FLOAT64_C(  -128.00) } },
    { { SIMDE_FLOAT64_C(  -404.59) },
      { SIMDE_FLOAT64_C(  -404.00) } },
    { { SIMDE_FLOAT64_C(   535.14) },
      { SIMDE_FLOAT64_C(   536.00) } },
    { { SIMDE_FLOAT64_C(  -863.09) },
      { SIMDE_FLOAT64_C(  -863.00) } },
    { { SIMDE_FLOAT64_C(   977.14) },
      { SIMDE_FLOAT64_C(   978.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrndp_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrndp_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndpq_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     3.00) } },
    { { SIMDE_FLOAT32_C(    86.24), SIMDE_FLOAT32_C(   581.00), SIMDE_FLOAT32_C(   890.92), SIMDE_FLOAT32_C(   188.30) },
      { SIMDE_FLOAT32_C(    87.00), SIMDE_FLOAT32_C(   581.00), SIMDE_FLOAT32_C(   891.00), SIMDE_FLOAT32_C(   189.00) } },
    { { SIMDE_FLOAT32_C(   162.02), SIMDE_FLOAT32_C(   633.16), SIMDE_FLOAT32_C(  -103.71), SIMDE_FLOAT32_C(   181.98) },
      { SIMDE_FLOAT32_C(   163.00), SIMDE_FLOAT32_C(   634.00), SIMDE_FLOAT32_C(  -103.00), SIMDE_FLOAT32_C(   182.00) } },
    { { SIMDE_FLOAT32_C(   573.12), SIMDE_FLOAT32_C(  -895.40), SIMDE_FLOAT32_C(  -928.26), SIMDE_FLOAT32_C(  -714.90) },
      { SIMDE_FLOAT32_C(   574.00), SIMDE_FLOAT32_C(  -895.00), SIMDE_FLOAT32_C(  -928.00), SIMDE_FLOAT32_C(  -714.00) } },
    { { SIMDE_FLOAT32_C(   717.20), SIMDE_FLOAT32_C(  -952.92), SIMDE_FLOAT32_C(  -715.52), SIMDE_FLOAT32_C(  -915.99) },
      { SIMDE_FLOAT32_C(   718.00), SIMDE_FLOAT32_C(  -952.00), SIMDE_FLOAT32_C(  -715.00), SIMDE_FLOAT32_C(  -915.00) } },
    { { SIMDE_FLOAT32_C(  -556.37), SIMDE_FLOAT32_C(   314.25), SIMDE_FLOAT32_C(   638.22), SIMDE_FLOAT32_C(  -290.58) },
      { SIMDE_FLOAT32_C(  -556.00), SIMDE_FLOAT32_C(   315.00), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(  -290.00) } },
    { { SIMDE_FLOAT32_C(   154.70), SIMDE_FLOAT32_C(    57.12), SIMDE_FLOAT32_C(   968.43), SIMDE_FLOAT32_C(   919.68) },
      { SIMDE_FLOAT32_C(   155.00), SIMDE_FLOAT32_C(    58.00), SIMDE_FLOAT32_C(   969.00), SIMDE_FLOAT32_C(   920.00) } },
    { { SIMDE_FLOAT32_C(   327.32), SIMDE_FLOAT32_C(  -601.25), SIMDE_FLOAT32_C(  -208.79), SIMDE_FLOAT32_C(   922.73) },
      { SIMDE_FLOAT32_C(   328.00), SIMDE_FLOAT32_C(  -601.00), SIMDE_FLOAT32_C(  -208.00), SIMDE_FLOAT32_C(   923.00) } },
    { { SIMDE_FLOAT32_C(   933.89), SIMDE_FLOAT32_C(   -71.87), SIMDE_FLOAT32_C(   899.87), SIMDE_FLOAT32_C(    20.13) },
      { SIMDE_FLOAT32_C(   934.00), SIMDE_FLOAT32_C(   -71.00), SIMDE_FLOAT32_C(   900.00), SIMDE_FLOAT32_C(    21.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndpq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndpq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndpq_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(    -2.50), SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     3.00) } },
    { { SIMDE_FLOAT64_C(  -490.87), SIMDE_FLOAT64_C(   790.79) },
      { SIMDE_FLOAT64_C(  -490.00), SIMDE_FLOAT64_C(   791.00) } },
    { { SIMDE_FLOAT64_C(  -791.57), SIMDE_FLOAT64_C(   671.15) },
      { SIMDE_FLOAT64_C(  -791.00), SIMDE_FLOAT64_C(   672.00) } },
    { { SIMDE_FLOAT64_C(   423.95), SIMDE_FLOAT64_C(   104.72) },
      { SIMDE_FLOAT64_C(   424.00), SIMDE_FLOAT64_C(   105.00) } },
    { { SIMDE_FLOAT64_C(  -146.87), SIMDE_FLOAT64_C(    -2.94) },
      { SIMDE_FLOAT64_C(  -146.00), SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(   209.32), SIMDE_FLOAT64_C(   -75.14) },
      { SIMDE_FLOAT64_C(   210.00), SIMDE_FLOAT64_C(   -75.00) } },
    { { SIMDE_FLOAT64_C(   282.16), SIMDE_FLOAT64_C(   -73.47) },
      { SIMDE_FLOAT64_C(   283.00), SIMDE_FLOAT64_C(   -73.00) } },
    { { SIMDE_FLOAT64_C(   -28.06), SIMDE_FLOAT64_C(   566.64) },
      { SIMDE_FLOAT64_C(   -28.00), SIMDE_FLOAT64_C(   567.00) } },
    { { SIMDE_FLOAT64_C(    10.53), SIMDE_FLOAT64_C(   415.57) },
      { SIMDE_FLOAT64_C(    11.00), SIMDE_FLOAT64_C(   416.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndpq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrndpq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndp_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndp_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndpq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndpq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
