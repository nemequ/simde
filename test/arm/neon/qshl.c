#define SIMDE_TEST_ARM_NEON_INSN qshl

#include "test-neon.h"
#include "../../../simde/arm/neon/qshl.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/shl.h"

/* Until v12, clang used unsigned parameters on the scalar versions, so
 * when testing we need to disable the -Wsign-conversion to avoid a
 * diagnostic.  If this is a problem in your code you might want to
 * consider using simde_vqshl* instead of vqshl* so you can avoid an
 * ifdef. */

#if HEDLEY_HAS_WARNING("-Wsign-conversion") && defined(SIMDE_NATIVE_ALIASES_TESTING)
  #pragma clang diagnostic ignored "-Wsign-conversion"
#endif

static int
test_simde_vqshlb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t b;
    int8_t r;
  } test_vec[] = {
    {  INT8_C(  76),
       INT8_C(   1),
           INT8_MAX },
    { -INT8_C(  27),
       INT8_C(  11),
           INT8_MIN },
    {  INT8_C(  93),
       INT8_C(   7),
           INT8_MAX },
    { -INT8_C(   1),
       INT8_C(   4),
      -INT8_C(  16) },
    {  INT8_C(   1),
       INT8_C(   8),
           INT8_MAX },
    { -INT8_C(  48),
       INT8_C(   1),
      -INT8_C(  96) },
    { -INT8_C(   1),
       INT8_C(  12),
           INT8_MIN },
    {  INT8_C(   3),
       INT8_C(   4),
       INT8_C(  48) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqshlb_s8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8() >> (simde_test_codegen_random_i8() & 7);
    int8_t b = simde_test_codegen_random_i8() & 15;
    int8_t r = simde_vqshlb_s8(a, b);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t r;
  } test_vec[] = {
    {  INT16_C(  1815),
       INT16_C(    27),
            INT16_MAX },
    { -INT16_C(  3418),
       INT16_C(     8),
            INT16_MIN },
    {  INT16_C(     7),
       INT16_C(    25),
            INT16_MAX },
    {  INT16_C(    27),
       INT16_C(     7),
       INT16_C(  3456) },
    {  INT16_C(   126),
       INT16_C(     6),
       INT16_C(  8064) },
    { -INT16_C(     5),
       INT16_C(     2),
      -INT16_C(    20) },
    {  INT16_C(     2),
       INT16_C(    28),
            INT16_MAX },
    {  INT16_C(  6300),
       INT16_C(     4),
            INT16_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqshlh_s16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16() >> (simde_test_codegen_random_i16() & 15);
    int16_t b = simde_test_codegen_random_i16() & 31;
    int16_t r = simde_vqshlh_s16(a, b);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshls_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t r;
  } test_vec[] = {
    { -INT32_C(     4189281),
       INT32_C(          48),
                 INT32_MIN },
    {  INT32_C(   125729542),
       INT32_C(          40),
                 INT32_MAX },
    { -INT32_C(          95),
       INT32_C(          58),
                 INT32_MIN },
    {  INT32_C(        1661),
       INT32_C(          19),
       INT32_C(   870842368) },
    {  INT32_C(           0),
       INT32_C(          39),
       INT32_C(           0) },
    { -INT32_C(   553689631),
       INT32_C(          25),
                 INT32_MIN },
    {  INT32_C(      139156),
       INT32_C(          19),
                 INT32_MAX },
    {  INT32_C(     1819628),
       INT32_C(           9),
       INT32_C(   931649536) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqshls_s32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32() >> (simde_test_codegen_random_i32() & 31);
    int32_t b = simde_test_codegen_random_i32() & 63;
    int32_t r = simde_vqshls_s32(a, b);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshld_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    {  INT64_C( 5670071369984075849),
       INT64_C(                  39),
                          INT64_MAX },
    { -INT64_C(         15590799414),
       INT64_C(                  59),
                          INT64_MIN },
    { -INT64_C(    3355610189070484),
       INT64_C(                  10),
      -INT64_C( 3436144833608175616) },
    { -INT64_C(  353835611503824087),
       INT64_C(                  42),
                          INT64_MIN },
    {  INT64_C(        791223430054),
       INT64_C(                  29),
                          INT64_MAX },
    {  INT64_C(     948157670769426),
       INT64_C(                  47),
                          INT64_MAX },
    {  INT64_C( 7265832135546397357),
       INT64_C(                  34),
                          INT64_MAX },
    { -INT64_C(    1096390776312631),
       INT64_C(                  25),
                          INT64_MIN }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqshld_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64() >> (simde_test_codegen_random_i64() & 31);
    int64_t b = simde_test_codegen_random_i64() & 63;
    int64_t r = simde_vqshld_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    int8_t b;
    uint8_t r;
  } test_vec[] = {
    { UINT8_C(  1),
       INT8_C(   9),
         UINT8_MAX },
    { UINT8_C(107),
      -INT8_C(   4),
      UINT8_C(  6) },
    { UINT8_C(182),
      -INT8_C(   1),
      UINT8_C( 91) },
    { UINT8_C(  3),
       INT8_C(  10),
         UINT8_MAX },
    { UINT8_C( 20),
      -INT8_C(   1),
      UINT8_C( 10) },
    { UINT8_C(  6),
      -INT8_C(   1),
      UINT8_C(  3) },
    { UINT8_C( 28),
      -INT8_C(   3),
      UINT8_C(  3) },
    { UINT8_C(  3),
      -INT8_C(  13),
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_vqshlb_u8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8() >> (simde_test_codegen_random_u8() & 7);
    int8_t b = simde_test_codegen_random_i8() % 16;
    uint8_t r = simde_vqshlb_u8(a, b);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    int16_t b;
    uint16_t r;
  } test_vec[] = {
    { UINT16_C(  368),
      -INT16_C(     6),
      UINT16_C(    5) },
    { UINT16_C(    1),
       INT16_C(    22),
           UINT16_MAX },
    { UINT16_C(   22),
       INT16_C(    16),
           UINT16_MAX },
    { UINT16_C( 5634),
      -INT16_C(     8),
      UINT16_C(   22) },
    { UINT16_C(17754),
      -INT16_C(    20),
      UINT16_C(    0) },
    { UINT16_C( 3312),
       INT16_C(    13),
           UINT16_MAX },
    { UINT16_C(    1),
       INT16_C(    19),
           UINT16_MAX },
    { UINT16_C(61653),
      -INT16_C(     4),
      UINT16_C( 3853) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vqshlh_u16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16() >> (simde_test_codegen_random_u16() & 15);
    int16_t b = simde_test_codegen_random_i16() % 32;
    uint16_t r = simde_vqshlh_u16(a, b);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshls_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    int32_t b;
    uint32_t r;
  } test_vec[] = {
    { UINT32_C(   1061138),
       INT32_C(          20),
                UINT32_MAX },
    { UINT32_C(3565737185),
       INT32_C(          57),
                UINT32_MAX },
    { UINT32_C(    268518),
       INT32_C(          43),
                UINT32_MAX },
    { UINT32_C(         5),
       INT32_C(          19),
      UINT32_C(   2621440) },
    { UINT32_C( 428356234),
       INT32_C(          10),
                UINT32_MAX },
    { UINT32_C(      5680),
       INT32_C(          16),
      UINT32_C( 372244480) },
    { UINT32_C(       206),
       INT32_C(          16),
      UINT32_C(  13500416) },
    { UINT32_C(  43944177),
       INT32_C(          29),
                UINT32_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vqshls_u32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32() >> (simde_test_codegen_random_u32() & 31);
    int32_t b = simde_test_codegen_random_u32() % 64;
    uint32_t r = simde_vqshls_u32(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshld_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C( 8538370902170065728),
       INT64_C(                  63),
                         UINT64_MAX },
    { UINT64_C( 7371871036122383575),
       INT64_C(                  63),
                         UINT64_MAX },
    { UINT64_C(  822863165501813659),
      -INT64_C(                   4),
      UINT64_C(   51428947843863353) },
    { UINT64_C(          4293105166),
       INT64_C(                  51),
                         UINT64_MAX },
    { UINT64_C(          5056019599),
       INT64_C(                  30),
      UINT64_C( 5428859706410008576) },
    { UINT64_C(        168829403185),
      -INT64_C(                   5),
      UINT64_C(          5275918849) },
    { UINT64_C(         12247585093),
       INT64_C(                  48),
                         UINT64_MAX },
    { UINT64_C(15004996209508217752),
       INT64_C(                  38),
                         UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vqshld_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64() >> (simde_test_codegen_random_u64() & 31);
    int64_t b = simde_test_codegen_random_i64() % 64;
    uint64_t r = simde_vqshld_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  65), -INT8_C(   6), -INT8_C(  64), -INT8_C(  21),  INT8_C(   1), -INT8_C( 115), -INT8_C(   1),  INT8_C(  31) },
      {  INT8_C(   1),  INT8_C(  14),  INT8_C(   0),  INT8_C(   6),  INT8_C(   8),  INT8_C(   9),  INT8_C(  14),  INT8_C(  15) },
      {      INT8_MAX,      INT8_MIN, -INT8_C(  64),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX } },
    { {  INT8_C(   1),  INT8_C(   2), -INT8_C(   4), -INT8_C(   1),  INT8_C(   1),  INT8_C(  13), -INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(  15),  INT8_C(   8),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   5),  INT8_C(   7) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN, -INT8_C(  32),  INT8_C(  32),  INT8_C(  13), -INT8_C(  32),      INT8_MIN } },
    { { -INT8_C( 122),  INT8_C(  29), -INT8_C(   1),  INT8_C(   0), -INT8_C(   5), -INT8_C(  25), -INT8_C(   4),  INT8_C(  57) },
      {  INT8_C(   6),  INT8_C(  15),  INT8_C(   7),  INT8_C(  13),  INT8_C(   8),  INT8_C(   0),  INT8_C(   5),  INT8_C(   8) },
      {      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MIN, -INT8_C(  25),      INT8_MIN,      INT8_MAX } },
    { {  INT8_C(   2),  INT8_C(   8),  INT8_C(  95), -INT8_C(   4), -INT8_C(   5), -INT8_C(   2), -INT8_C(   3),  INT8_C(   6) },
      {  INT8_C(  11),  INT8_C(   6),  INT8_C(   8),  INT8_C(  10),  INT8_C(   4),  INT8_C(  13),  INT8_C(   4),  INT8_C(  11) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN, -INT8_C(  80),      INT8_MIN, -INT8_C(  48),      INT8_MAX } },
    { {  INT8_C(   0), -INT8_C(  19),  INT8_C(   0),  INT8_C(  20),  INT8_C(   0), -INT8_C(  53), -INT8_C(   3),  INT8_C(  10) },
      {  INT8_C(   9),  INT8_C(  10),  INT8_C(  10),  INT8_C(   6),  INT8_C(  15),  INT8_C(   7),  INT8_C(   9),  INT8_C(  10) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MAX,  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MAX } },
    { { -INT8_C(   1), -INT8_C(   2),  INT8_C(   4), -INT8_C(   6),  INT8_C(   2), -INT8_C(   3),  INT8_C(   0),  INT8_C(  30) },
      {  INT8_C(   8),  INT8_C(   6),  INT8_C(  15),  INT8_C(   5),  INT8_C(  13),  INT8_C(  11),  INT8_C(   9),  INT8_C(   6) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MAX } },
    { { -INT8_C(   6), -INT8_C(   1), -INT8_C(   3),  INT8_C(  86),  INT8_C(  19),  INT8_C(   1), -INT8_C(   1),  INT8_C(  49) },
      {  INT8_C(  15),  INT8_C(   2),  INT8_C(   1),  INT8_C(   3),  INT8_C(  15),  INT8_C(   5),  INT8_C(   0),  INT8_C(   7) },
      {      INT8_MIN, -INT8_C(   4), -INT8_C(   6),      INT8_MAX,      INT8_MAX,  INT8_C(  32), -INT8_C(   1),      INT8_MAX } },
    { {  INT8_C(  10),  INT8_C(   0), -INT8_C(   1),  INT8_C( 117), -INT8_C(   3), -INT8_C(   1), -INT8_C(   1), -INT8_C( 121) },
      {  INT8_C(   7),  INT8_C(  11),  INT8_C(  13),  INT8_C(   4),  INT8_C(   4),  INT8_C(  14),  INT8_C(   6),  INT8_C(   4) },
      {      INT8_MAX,  INT8_C(   0),      INT8_MIN,      INT8_MAX, -INT8_C(  48),      INT8_MIN, -INT8_C(  64),      INT8_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vqshl_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();

    a = simde_vshl_s8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    b = simde_vand_s8(b, simde_vdup_n_s8(15));

    simde_int8x8_t r = simde_vqshl_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(   629), -INT16_C(  1930), -INT16_C(   203), -INT16_C(    57) },
      {  INT16_C(    24),  INT16_C(    25),  INT16_C(     9),  INT16_C(    19) },
      {       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C(   341), -INT16_C(     2), -INT16_C(    51),  INT16_C(   320) },
      {  INT16_C(    15),  INT16_C(     9),  INT16_C(    26),  INT16_C(    24) },
      {       INT16_MAX, -INT16_C(  1024),       INT16_MIN,       INT16_MAX } },
    { { -INT16_C(     9), -INT16_C(  1567), -INT16_C( 31654), -INT16_C(    66) },
      {  INT16_C(    25),  INT16_C(    13),  INT16_C(    19),  INT16_C(     0) },
      {       INT16_MIN,       INT16_MIN,       INT16_MIN, -INT16_C(    66) } },
    { { -INT16_C(  3881),  INT16_C(  1242),  INT16_C(    43),  INT16_C(    24) },
      {  INT16_C(     3),  INT16_C(    31),  INT16_C(     2),  INT16_C(    27) },
      { -INT16_C( 31048),       INT16_MAX,  INT16_C(   172),       INT16_MAX } },
    { {  INT16_C(    15),  INT16_C(   991), -INT16_C(     4), -INT16_C(    31) },
      {  INT16_C(    23),  INT16_C(    10),  INT16_C(    20),  INT16_C(    16) },
      {       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C(    38), -INT16_C(   758),  INT16_C(     1),  INT16_C(  1012) },
      {  INT16_C(     9),  INT16_C(    27),  INT16_C(    30),  INT16_C(    22) },
      {  INT16_C( 19456),       INT16_MIN,       INT16_MAX,       INT16_MAX } },
    { {  INT16_C(   974),  INT16_C(    63), -INT16_C(    79),  INT16_C(     8) },
      {  INT16_C(    30),  INT16_C(     3),  INT16_C(    14),  INT16_C(    29) },
      {       INT16_MAX,  INT16_C(   504),       INT16_MIN,       INT16_MAX } },
    { { -INT16_C(    97),  INT16_C(     7),  INT16_C(   935), -INT16_C(     2) },
      {  INT16_C(    13),  INT16_C(     9),  INT16_C(    30),  INT16_C(    25) },
      {       INT16_MIN,  INT16_C(  3584),       INT16_MAX,       INT16_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqshl_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();

    a = simde_vshl_s16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    b = simde_vand_s16(b, simde_vdup_n_s16(31));

    simde_int16x4_t r = simde_vqshl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(     1173271),  INT32_C(     7299919) },
      {  INT32_C(          20),  INT32_C(          51) },
      {            INT32_MIN,            INT32_MAX } },
    { { -INT32_C(    90947158), -INT32_C(     2365082) },
      {  INT32_C(          54),  INT32_C(          18) },
      {            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(        4265),  INT32_C(           2) },
      {  INT32_C(          32),  INT32_C(          15) },
      {            INT32_MAX,  INT32_C(       65536) } },
    { {  INT32_C(     2841512), -INT32_C(        1958) },
      {  INT32_C(          44),  INT32_C(          14) },
      {            INT32_MAX, -INT32_C(    32079872) } },
    { { -INT32_C(          97),  INT32_C(   128986388) },
      {  INT32_C(           4),  INT32_C(          47) },
      { -INT32_C(        1552),            INT32_MAX } },
    { { -INT32_C(   401488194), -INT32_C(        2750) },
      {  INT32_C(          51),  INT32_C(          19) },
      {            INT32_MIN, -INT32_C(  1441792000) } },
    { { -INT32_C(       36123),  INT32_C(           9) },
      {  INT32_C(          20),  INT32_C(          39) },
      {            INT32_MIN,            INT32_MAX } },
    { {  INT32_C(          41), -INT32_C(          14) },
      {  INT32_C(          55),  INT32_C(          15) },
      {            INT32_MAX, -INT32_C(      458752) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqshl_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();

    a = simde_vshl_s32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    b = simde_vand_s32(b, simde_vdup_n_s32(63));

    simde_int32x2_t r = simde_vqshl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C(       1420889861288) },
      {  INT64_C(                  36) },
      {                     INT64_MIN } },
    { {  INT64_C(      23751618503999) },
      {  INT64_C(                  10) },
      {  INT64_C(   24321657348094976) } },
    { {  INT64_C(         58288625249) },
      {  INT64_C(                  19) },
      {  INT64_C(   30560026754547712) } },
    { {  INT64_C(     104685087965022) },
      {  INT64_C(                  23) },
      {                     INT64_MAX } },
    { {  INT64_C(                6277) },
      {  INT64_C(                  11) },
      {  INT64_C(            12855296) } },
    { {  INT64_C(              412853) },
      {  INT64_C(                  32) },
      {  INT64_C(    1773190133055488) } },
    { { -INT64_C(    3675864865379130) },
      {  INT64_C(                  30) },
      {                     INT64_MIN } },
    { {  INT64_C(    1096678395763767) },
      {  INT64_C(                  60) },
      {                     INT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vqshl_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();

    a = simde_vshl_s64(a, simde_vneg_s64(simde_vand_s64(simde_test_arm_neon_random_i64x1(), simde_vdup_n_s64(63))));
    b = simde_vand_s64(b, simde_vdup_n_s64(63));

    simde_int64x1_t r = simde_vqshl_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(  2), UINT8_C( 79), UINT8_C( 19), UINT8_C(202), UINT8_C( 12), UINT8_C( 46), UINT8_C(  3), UINT8_C( 74) },
      {  INT8_C(   5),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   4),  INT8_C(   8),  INT8_C(   2),  INT8_C(   8) },
      { UINT8_C( 64), UINT8_C( 79),    UINT8_MAX, UINT8_C(202), UINT8_C(192),    UINT8_MAX, UINT8_C( 12),    UINT8_MAX } },
    { { UINT8_C(147), UINT8_C( 12), UINT8_C(  6), UINT8_C( 13), UINT8_C(  3), UINT8_C(  0), UINT8_C(  9), UINT8_C( 59) },
      {  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),  INT8_C(  11),  INT8_C(  15),  INT8_C(   8),  INT8_C(   0),  INT8_C(   4) },
      {    UINT8_MAX, UINT8_C( 96), UINT8_C(  6),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  9),    UINT8_MAX } },
    { { UINT8_C(104), UINT8_C(102), UINT8_C( 22), UINT8_C( 36), UINT8_C( 57), UINT8_C( 23), UINT8_C( 12), UINT8_C( 30) },
      {  INT8_C(  13),  INT8_C(  14),  INT8_C(  14),  INT8_C(   2),  INT8_C(   4),  INT8_C(  14),  INT8_C(   9),  INT8_C(   8) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(144),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(  2), UINT8_C( 20), UINT8_C( 14), UINT8_C( 14), UINT8_C(  6), UINT8_C( 26), UINT8_C(  5) },
      {  INT8_C(   8),  INT8_C(   5),  INT8_C(   3),  INT8_C(  14),  INT8_C(   3),  INT8_C(   8),  INT8_C(   7),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C( 64), UINT8_C(160),    UINT8_MAX, UINT8_C(112),    UINT8_MAX,    UINT8_MAX, UINT8_C(  5) } },
    { { UINT8_C(  0), UINT8_C( 57), UINT8_C(  4), UINT8_C( 12), UINT8_C( 21), UINT8_C( 27), UINT8_C(  2), UINT8_C( 58) },
      {  INT8_C(   1),  INT8_C(   9),  INT8_C(  13),  INT8_C(   0),  INT8_C(   4),  INT8_C(   2),  INT8_C(  15),  INT8_C(  13) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 12),    UINT8_MAX, UINT8_C(108),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 62), UINT8_C( 47), UINT8_C( 43), UINT8_C(  1), UINT8_C(  5), UINT8_C(120), UINT8_C(  4), UINT8_C( 14) },
      {  INT8_C(   7),  INT8_C(   7),  INT8_C(   7),  INT8_C(   2),  INT8_C(   0),  INT8_C(   9),  INT8_C(  12),  INT8_C(   1) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  4), UINT8_C(  5),    UINT8_MAX,    UINT8_MAX, UINT8_C( 28) } },
    { { UINT8_C( 26), UINT8_C( 39), UINT8_C(174), UINT8_C(111), UINT8_C( 22), UINT8_C(  7), UINT8_C( 12), UINT8_C(  2) },
      {  INT8_C(   8),  INT8_C(  14),  INT8_C(   8),  INT8_C(   2),  INT8_C(  14),  INT8_C(  10),  INT8_C(   2),  INT8_C(   6) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 48), UINT8_C(128) } },
    { { UINT8_C(141), UINT8_C(  0), UINT8_C(  2), UINT8_C(  1), UINT8_C( 43), UINT8_C(193), UINT8_C(  1), UINT8_C( 17) },
      {  INT8_C(   0),  INT8_C(  10),  INT8_C(   9),  INT8_C(   3),  INT8_C(   3),  INT8_C(  10),  INT8_C(  14),  INT8_C(  11) },
      { UINT8_C(141), UINT8_C(  0),    UINT8_MAX, UINT8_C(  8),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vqshl_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();

    a = simde_vshl_u8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    b = simde_vand_s8(b, simde_vdup_n_s8(15));

    simde_uint8x8_t r = simde_vqshl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 1105), UINT16_C(   11), UINT16_C( 3430), UINT16_C(   11) },
      {  INT16_C(     1),  INT16_C(    26),  INT16_C(    18),  INT16_C(     5) },
      { UINT16_C( 2210),      UINT16_MAX,      UINT16_MAX, UINT16_C(  352) } },
    { { UINT16_C(36784), UINT16_C( 3175), UINT16_C(  172), UINT16_C( 1338) },
      {  INT16_C(    17),  INT16_C(     4),  INT16_C(    12),  INT16_C(    18) },
      {      UINT16_MAX, UINT16_C(50800),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1559), UINT16_C( 2688), UINT16_C(53249), UINT16_C(    2) },
      {  INT16_C(    31),  INT16_C(    23),  INT16_C(    25),  INT16_C(    11) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 4096) } },
    { { UINT16_C( 2352), UINT16_C(14028), UINT16_C( 3054), UINT16_C(  155) },
      {  INT16_C(    24),  INT16_C(     2),  INT16_C(    11),  INT16_C(    11) },
      {      UINT16_MAX, UINT16_C(56112),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 3439), UINT16_C(   62), UINT16_C(   20), UINT16_C(   34) },
      {  INT16_C(    23),  INT16_C(    31),  INT16_C(     7),  INT16_C(     1) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C( 2560), UINT16_C(   68) } },
    { { UINT16_C(    2), UINT16_C(10879), UINT16_C(   20), UINT16_C( 3359) },
      {  INT16_C(    15),  INT16_C(    16),  INT16_C(    23),  INT16_C(    20) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 3984), UINT16_C( 4191), UINT16_C(   67), UINT16_C(   84) },
      {  INT16_C(    17),  INT16_C(    18),  INT16_C(     3),  INT16_C(    29) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(  536),      UINT16_MAX } },
    { { UINT16_C(    1), UINT16_C( 1767), UINT16_C( 4978), UINT16_C( 3035) },
      {  INT16_C(    23),  INT16_C(    26),  INT16_C(    25),  INT16_C(     1) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 6070) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vqshl_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();

    a = simde_vshl_u16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    b = simde_vand_s16(b, simde_vdup_n_s16(31));

    simde_uint16x4_t r = simde_vqshl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(        11), UINT32_C(      2456) },
      {  INT32_C(          55),  INT32_C(          31) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 146134516), UINT32_C(     28278) },
      {  INT32_C(          20),  INT32_C(          24) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(        97), UINT32_C(       436) },
      {  INT32_C(           9),  INT32_C(          63) },
      { UINT32_C(     49664),           UINT32_MAX } },
    { { UINT32_C(     25335), UINT32_C(         9) },
      {  INT32_C(          31),  INT32_C(          46) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(       603), UINT32_C(    113827) },
      {  INT32_C(          63),  INT32_C(          39) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(        14), UINT32_C(   1635361) },
      {  INT32_C(          60),  INT32_C(          62) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(      3044), UINT32_C(   1889936) },
      {  INT32_C(          31),  INT32_C(          42) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(     11315), UINT32_C(   2830620) },
      {  INT32_C(          20),  INT32_C(          31) },
      {           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vqshl_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();

    a = simde_vshl_u32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    b = simde_vand_s32(b, simde_vdup_n_s32(63));

    simde_uint32x2_t r = simde_vqshl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(            11758907) },
      {  INT64_C(                  53) },
      {                    UINT64_MAX } },
    { { UINT64_C(                 201) },
      {  INT64_C(                  39) },
      { UINT64_C(     110500918591488) } },
    { { UINT64_C(               10353) },
      {  INT64_C(                  60) },
      {                    UINT64_MAX } },
    { { UINT64_C(         16865279727) },
      {  INT64_C(                  54) },
      {                    UINT64_MAX } },
    { { UINT64_C(        298491154210) },
      {  INT64_C(                  26) },
      {                    UINT64_MAX } },
    { { UINT64_C(                  45) },
      {  INT64_C(                  59) },
      {                    UINT64_MAX } },
    { { UINT64_C(                 158) },
      {  INT64_C(                  54) },
      { UINT64_C( 2846274964498153472) } },
    { { UINT64_C(              415649) },
      {  INT64_C(                  33) },
      { UINT64_C(    3570397723230208) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vqshl_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();

    a = simde_vshl_u64(a, simde_vneg_s64(simde_vand_s64(simde_test_arm_neon_random_i64x1(), simde_vdup_n_s64(63))));
    b = simde_vand_s64(b, simde_vdup_n_s64(63));

    simde_uint64x1_t r = simde_vqshl_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   1),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(   5), -INT8_C(   2),  INT8_C(  41),  INT8_C(   0),
         INT8_C(  45),  INT8_C(   6), -INT8_C(  39), -INT8_C(   7), -INT8_C(  23), -INT8_C(  59), -INT8_C(   8), -INT8_C(   1) },
      {  INT8_C(   5),  INT8_C(   7),  INT8_C(   6),  INT8_C(   1),  INT8_C(   7),  INT8_C(  14),  INT8_C(   8),  INT8_C(  11),
         INT8_C(  14),  INT8_C(   0),  INT8_C(   2),  INT8_C(   1),  INT8_C(   7),  INT8_C(  12),  INT8_C(  10),  INT8_C(   1) },
      { -INT8_C(  32),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),
             INT8_MAX,  INT8_C(   6),      INT8_MIN, -INT8_C(  14),      INT8_MIN,      INT8_MIN,      INT8_MIN, -INT8_C(   2) } },
    { { -INT8_C(  17), -INT8_C(  16),  INT8_C(   9),  INT8_C(  27),  INT8_C(   6),  INT8_C(   1),  INT8_C(  49), -INT8_C(  11),
         INT8_C(   2),  INT8_C(  58), -INT8_C(  16),  INT8_C(  15), -INT8_C(   4), -INT8_C(   1), -INT8_C(   8),  INT8_C(   5) },
      {  INT8_C(   7),  INT8_C(   5),  INT8_C(  15),  INT8_C(   3),  INT8_C(   4),  INT8_C(  15),  INT8_C(  11),  INT8_C(   5),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   9),  INT8_C(  13),  INT8_C(  13),  INT8_C(   6),  INT8_C(  11),  INT8_C(  12) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  96),      INT8_MAX,      INT8_MAX,      INT8_MIN,
         INT8_C(  16),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C(  64),      INT8_MIN,      INT8_MAX } },
    { { -INT8_C(   2), -INT8_C(   1),  INT8_C(  11), -INT8_C(   3),  INT8_C(   0),  INT8_C(   1), -INT8_C(  30),  INT8_C(   2),
         INT8_C(  19),  INT8_C(   3),  INT8_C(  17),  INT8_C(   6), -INT8_C(  26), -INT8_C(  26),  INT8_C(   1), -INT8_C(  32) },
      {  INT8_C(   8),  INT8_C(  11),  INT8_C(  12),  INT8_C(  11),  INT8_C(   1),  INT8_C(   5),  INT8_C(   7),  INT8_C(  12),
         INT8_C(  14),  INT8_C(   2),  INT8_C(   7),  INT8_C(   2),  INT8_C(  13),  INT8_C(  10),  INT8_C(  14),  INT8_C(  14) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(   0),  INT8_C(  32),      INT8_MIN,      INT8_MAX,
             INT8_MAX,  INT8_C(  12),      INT8_MAX,  INT8_C(  24),      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN } },
    { {  INT8_C(   4),  INT8_C(   0), -INT8_C(   7), -INT8_C(  16), -INT8_C(  13),  INT8_C(   0),  INT8_C(   1),  INT8_C(  19),
        -INT8_C(   1),  INT8_C(  44),  INT8_C(   1), -INT8_C(   9), -INT8_C(  77), -INT8_C(  49), -INT8_C(  11), -INT8_C(   1) },
      {  INT8_C(  11),  INT8_C(  14),  INT8_C(  12),  INT8_C(   2),  INT8_C(  12),  INT8_C(  15),  INT8_C(   8),  INT8_C(  14),
         INT8_C(   3),  INT8_C(   9),  INT8_C(  10),  INT8_C(   5),  INT8_C(   2),  INT8_C(   9),  INT8_C(   0),  INT8_C(   6) },
      {      INT8_MAX,  INT8_C(   0),      INT8_MIN, -INT8_C(  64),      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MAX,
        -INT8_C(   8),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN, -INT8_C(  11), -INT8_C(  64) } },
    { { -INT8_C(   2), -INT8_C(  53),  INT8_C(   1), -INT8_C(  14), -INT8_C(   1),  INT8_C(  70),  INT8_C(  49), -INT8_C(   2),
         INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   4),  INT8_C(   1),  INT8_C(   0),  INT8_C(   1), -INT8_C(  43) },
      {  INT8_C(   4),  INT8_C(   4),  INT8_C(  13),  INT8_C(   7),  INT8_C(   2),  INT8_C(  14),  INT8_C(   9),  INT8_C(  10),
         INT8_C(  15),  INT8_C(   7),  INT8_C(   4),  INT8_C(  15),  INT8_C(   1),  INT8_C(  14),  INT8_C(  11),  INT8_C(   9) },
      { -INT8_C(  32),      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C(   4),      INT8_MAX,      INT8_MAX,      INT8_MIN,
             INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   2),  INT8_C(   0),      INT8_MAX,      INT8_MIN } },
    { { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 121),  INT8_C(   2), -INT8_C( 121),  INT8_C(  28),
        -INT8_C(  52), -INT8_C(  69),  INT8_C(   7),  INT8_C(  10),  INT8_C(   1), -INT8_C(   1), -INT8_C(  93),  INT8_C(  13) },
      {  INT8_C(  12),  INT8_C(   0),  INT8_C(   6),  INT8_C(  11),  INT8_C(   1),  INT8_C(   8),  INT8_C(   9),  INT8_C(  15),
         INT8_C(   7),  INT8_C(   8),  INT8_C(   3),  INT8_C(   5),  INT8_C(  15),  INT8_C(   2),  INT8_C(   6),  INT8_C(   9) },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,
             INT8_MIN,      INT8_MIN,  INT8_C(  56),      INT8_MAX,      INT8_MAX, -INT8_C(   4),      INT8_MIN,      INT8_MAX } },
    { { -INT8_C(   2),  INT8_C(   9),  INT8_C(  14), -INT8_C(  11),  INT8_C(   0),  INT8_C(  31),  INT8_C(  19), -INT8_C(   2),
        -INT8_C(   3), -INT8_C(   7),  INT8_C(  10),  INT8_C(  34), -INT8_C(   3),  INT8_C(  24), -INT8_C(   7),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   5),  INT8_C(   1),  INT8_C(   1),  INT8_C(   2),  INT8_C(   1),  INT8_C(  10),  INT8_C(  11),
         INT8_C(   9),  INT8_C(  14),  INT8_C(  14),  INT8_C(   5),  INT8_C(   4),  INT8_C(  14),  INT8_C(  14),  INT8_C(  11) },
      { -INT8_C(   2),      INT8_MAX,  INT8_C(  28), -INT8_C(  22),  INT8_C(   0),  INT8_C(  62),      INT8_MAX,      INT8_MIN,
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  48),      INT8_MAX,      INT8_MIN,  INT8_C(   0) } },
    { { -INT8_C(   2),  INT8_C(   0),  INT8_C(  10),  INT8_C(  40),  INT8_C( 109),  INT8_C(   0), -INT8_C(   4), -INT8_C(  25),
        -INT8_C(  41),  INT8_C(   0), -INT8_C(   8), -INT8_C(  14), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   2) },
      {  INT8_C(  12),  INT8_C(   3),  INT8_C(  15),  INT8_C(  12),  INT8_C(  13),  INT8_C(   8),  INT8_C(   1),  INT8_C(   2),
         INT8_C(  12),  INT8_C(  12),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(  15),  INT8_C(   8),  INT8_C(   3) },
      {      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C(   8), -INT8_C( 100),
             INT8_MIN,  INT8_C(   0),      INT8_MIN, -INT8_C(  56), -INT8_C(  32),      INT8_MIN,      INT8_MIN,  INT8_C(  16) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vqshlq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();

    a = simde_vshlq_s8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    b = simde_vandq_s8(b, simde_vdupq_n_s8(15));

    simde_int8x16_t r = simde_vqshlq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(     0),  INT16_C(    19),  INT16_C(    25),  INT16_C(     7), -INT16_C(    34),  INT16_C(   659), -INT16_C(   161), -INT16_C(  1333) },
      {  INT16_C(    19),  INT16_C(    10),  INT16_C(    23),  INT16_C(    29),  INT16_C(    25),  INT16_C(    18),  INT16_C(     5),  INT16_C(     9) },
      {  INT16_C(     0),  INT16_C( 19456),       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MAX, -INT16_C(  5152),       INT16_MIN } },
    { { -INT16_C(   794),  INT16_C(  7198), -INT16_C(    83),  INT16_C(   687), -INT16_C(  1495),  INT16_C(   477), -INT16_C(   111), -INT16_C(     6) },
      {  INT16_C(     1),  INT16_C(    25),  INT16_C(    15),  INT16_C(    30),  INT16_C(    12),  INT16_C(    17),  INT16_C(     8),  INT16_C(    13) },
      { -INT16_C(  1588),       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MAX, -INT16_C( 28416),       INT16_MIN } },
    { { -INT16_C(     1),  INT16_C(   394), -INT16_C(    70), -INT16_C(     2),  INT16_C(    14), -INT16_C(  4474), -INT16_C(     2), -INT16_C(     1) },
      {  INT16_C(    17),  INT16_C(    20),  INT16_C(    22),  INT16_C(    15),  INT16_C(    17),  INT16_C(    12),  INT16_C(     2),  INT16_C(    25) },
      {       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MIN, -INT16_C(     8),       INT16_MIN } },
    { {  INT16_C(     4),  INT16_C(     4),  INT16_C(  1287),  INT16_C(   368), -INT16_C(    73),  INT16_C(   109), -INT16_C(   138), -INT16_C(   228) },
      {  INT16_C(     4),  INT16_C(    23),  INT16_C(    19),  INT16_C(     3),  INT16_C(    13),  INT16_C(    23),  INT16_C(    11),  INT16_C(    26) },
      {  INT16_C(    64),       INT16_MAX,       INT16_MAX,  INT16_C(  2944),       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MIN } },
    { { -INT16_C(   197),  INT16_C(  1656), -INT16_C(  1202),  INT16_C(    12),  INT16_C(    10), -INT16_C(  1877), -INT16_C(     6),  INT16_C(   563) },
      {  INT16_C(    20),  INT16_C(    24),  INT16_C(    16),  INT16_C(    17),  INT16_C(     4),  INT16_C(    17),  INT16_C(    28),  INT16_C(    14) },
      {       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MAX,  INT16_C(   160),       INT16_MIN,       INT16_MIN,       INT16_MAX } },
    { { -INT16_C(     5), -INT16_C(  2325),  INT16_C(     1), -INT16_C(     8),  INT16_C(     0), -INT16_C(  1092), -INT16_C(   446), -INT16_C(    49) },
      {  INT16_C(    18),  INT16_C(     1),  INT16_C(    13),  INT16_C(    21),  INT16_C(    17),  INT16_C(    10),  INT16_C(    22),  INT16_C(    28) },
      {       INT16_MIN, -INT16_C(  4650),  INT16_C(  8192),       INT16_MIN,  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C(     7), -INT16_C(    16), -INT16_C( 24061), -INT16_C(   685),  INT16_C(     0),  INT16_C(     6), -INT16_C(   779),  INT16_C(     0) },
      {  INT16_C(    17),  INT16_C(    12),  INT16_C(    13),  INT16_C(     4),  INT16_C(     9),  INT16_C(    29),  INT16_C(    30),  INT16_C(     1) },
      {       INT16_MAX,       INT16_MIN,       INT16_MIN, -INT16_C( 10960),  INT16_C(     0),       INT16_MAX,       INT16_MIN,  INT16_C(     0) } },
    { {  INT16_C( 23495),  INT16_C(     0),  INT16_C(    25),  INT16_C( 27714),  INT16_C(     1),  INT16_C(   877),  INT16_C(  3402), -INT16_C( 16431) },
      {  INT16_C(    24),  INT16_C(    14),  INT16_C(     4),  INT16_C(     3),  INT16_C(    25),  INT16_C(    22),  INT16_C(    17),  INT16_C(    20) },
      {       INT16_MAX,  INT16_C(     0),  INT16_C(   400),       INT16_MAX,       INT16_MAX,       INT16_MAX,       INT16_MAX,       INT16_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqshlq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();

    a = simde_vshlq_s16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    b = simde_vandq_s16(b, simde_vdupq_n_s16(31));

    simde_int16x8_t r = simde_vqshlq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(      339863),  INT32_C(      968313), -INT32_C(  1235562459), -INT32_C(        9465) },
      {  INT32_C(           4),  INT32_C(          44),  INT32_C(           3),  INT32_C(          15) },
      { -INT32_C(     5437808),            INT32_MAX,            INT32_MIN, -INT32_C(   310149120) } },
    { { -INT32_C(        4310), -INT32_C(           6), -INT32_C(        3997),  INT32_C(     2046270) },
      {  INT32_C(          32),  INT32_C(          42),  INT32_C(          54),  INT32_C(          54) },
      {            INT32_MIN,            INT32_MIN,            INT32_MIN,            INT32_MAX } },
    { {  INT32_C(          60),  INT32_C(           0), -INT32_C(           2), -INT32_C(           2) },
      {  INT32_C(          41),  INT32_C(          52),  INT32_C(          39),  INT32_C(          32) },
      {            INT32_MAX,  INT32_C(           0),            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(         118),  INT32_C(    45659413), -INT32_C(           2), -INT32_C(     1935607) },
      {  INT32_C(          20),  INT32_C(           0),  INT32_C(          48),  INT32_C(          60) },
      {  INT32_C(   123731968),  INT32_C(    45659413),            INT32_MIN,            INT32_MIN } },
    { { -INT32_C(           3), -INT32_C(          56), -INT32_C(       22048),  INT32_C(    12517613) },
      {  INT32_C(          26),  INT32_C(          32),  INT32_C(           8),  INT32_C(           1) },
      { -INT32_C(   201326592),            INT32_MIN, -INT32_C(     5644288),  INT32_C(    25035226) } },
    { {  INT32_C(      482311),  INT32_C(           1),  INT32_C(       28143), -INT32_C(           1) },
      {  INT32_C(          17),  INT32_C(          40),  INT32_C(           5),  INT32_C(          15) },
      {            INT32_MAX,            INT32_MAX,  INT32_C(      900576), -INT32_C(       32768) } },
    { { -INT32_C(    12146667), -INT32_C(      412308),  INT32_C(       58268),  INT32_C(       51128) },
      {  INT32_C(           3),  INT32_C(           1),  INT32_C(          57),  INT32_C(          61) },
      { -INT32_C(    97173336), -INT32_C(      824616),            INT32_MAX,            INT32_MAX } },
    { { -INT32_C(       49114), -INT32_C(   310905264),  INT32_C(           0), -INT32_C(          19) },
      {  INT32_C(          30),  INT32_C(          26),  INT32_C(          63),  INT32_C(          25) },
      {            INT32_MIN,            INT32_MIN,  INT32_C(           0), -INT32_C(   637534208) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqshlq_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();

    a = simde_vshlq_s32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    b = simde_vandq_s32(b, simde_vdupq_n_s32(63));

    simde_int32x4_t r = simde_vqshlq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  138420769706638201), -INT64_C(               30931) },
      {  INT64_C(                  11),  INT64_C(                  55) },
      {                     INT64_MIN,                     INT64_MIN } },
    { { -INT64_C(          4812641786),  INT64_C(             5565153) },
      {  INT64_C(                  25),  INT64_C(                  14) },
      { -INT64_C(  161485461548695552),  INT64_C(         91179466752) } },
    { { -INT64_C(                 123),  INT64_C(                 318) },
      {  INT64_C(                  34),  INT64_C(                   6) },
      { -INT64_C(       2113123909632),  INT64_C(               20352) } },
    { {  INT64_C(  516225737598936679), -INT64_C(              151207) },
      {  INT64_C(                  61),  INT64_C(                  42) },
      {                     INT64_MAX, -INT64_C(  665015418804502528) } },
    { { -INT64_C(          1210783136), -INT64_C(                   2) },
      {  INT64_C(                  50),  INT64_C(                  38) },
      {                     INT64_MIN, -INT64_C(        549755813888) } },
    { { -INT64_C(     288097725918163),  INT64_C(                  38) },
      {  INT64_C(                  56),  INT64_C(                  45) },
      {                     INT64_MIN,  INT64_C(    1337006139375616) } },
    { {  INT64_C(       7429992216965),  INT64_C(      73287991613121) },
      {  INT64_C(                  42),  INT64_C(                  15) },
      {                     INT64_MAX,  INT64_C( 2401500909178748928) } },
    { { -INT64_C(        909897764488),  INT64_C(                6277) },
      {  INT64_C(                  58),  INT64_C(                  53) },
      {                     INT64_MIN,                     INT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vqshlq_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();

    a = simde_vshlq_s64(a, simde_vnegq_s64(simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63))));
    b = simde_vandq_s64(b, simde_vdupq_n_s64(63));

    simde_int64x2_t r = simde_vqshlq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C( 19), UINT8_C( 19), UINT8_C(  0), UINT8_C( 15), UINT8_C(  8),
        UINT8_C( 32), UINT8_C(  9), UINT8_C(  3), UINT8_C( 10), UINT8_C(  3), UINT8_C( 26), UINT8_C( 30), UINT8_C( 75) },
      {  INT8_C(  11),  INT8_C(  15),  INT8_C(   9),  INT8_C(   4),  INT8_C(  10),  INT8_C(   6),  INT8_C(   8),  INT8_C(  12),
         INT8_C(   2),  INT8_C(  13),  INT8_C(  13),  INT8_C(   9),  INT8_C(   8),  INT8_C(  15),  INT8_C(  10),  INT8_C(   5) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(128),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  5), UINT8_C( 26), UINT8_C(  4), UINT8_C(  6), UINT8_C(108), UINT8_C(  2), UINT8_C(232), UINT8_C(  4),
        UINT8_C(  2), UINT8_C( 24), UINT8_C(  1), UINT8_C(  1), UINT8_C( 98), UINT8_C(  0), UINT8_C(  2), UINT8_C(  4) },
      {  INT8_C(   4),  INT8_C(   7),  INT8_C(  14),  INT8_C(  14),  INT8_C(  15),  INT8_C(   3),  INT8_C(   9),  INT8_C(   0),
         INT8_C(  15),  INT8_C(  14),  INT8_C(   2),  INT8_C(   5),  INT8_C(   0),  INT8_C(  11),  INT8_C(   6),  INT8_C(   2) },
      { UINT8_C( 80),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 16),    UINT8_MAX, UINT8_C(  4),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  4), UINT8_C( 32), UINT8_C( 98), UINT8_C(  0), UINT8_C(128), UINT8_C( 16) } },
    { { UINT8_C(  3), UINT8_C( 25), UINT8_C( 12), UINT8_C( 50), UINT8_C(  1), UINT8_C(  0), UINT8_C( 15), UINT8_C( 54),
        UINT8_C(  1), UINT8_C(  6), UINT8_C(  0), UINT8_C( 37), UINT8_C(  5), UINT8_C( 49), UINT8_C( 62), UINT8_C( 63) },
      {  INT8_C(   3),  INT8_C(  10),  INT8_C(   5),  INT8_C(  12),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(  10),
         INT8_C(   8),  INT8_C(   7),  INT8_C(   9),  INT8_C(  10),  INT8_C(   6),  INT8_C(   4),  INT8_C(  15),  INT8_C(  12) },
      { UINT8_C( 24),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C( 15),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  3), UINT8_C(  2), UINT8_C( 86), UINT8_C( 46), UINT8_C(101), UINT8_C( 28), UINT8_C(  3), UINT8_C( 14),
        UINT8_C(113), UINT8_C( 56), UINT8_C(  5), UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(  1), UINT8_C(  1) },
      {  INT8_C(   0),  INT8_C(   7),  INT8_C(  10),  INT8_C(  15),  INT8_C(  15),  INT8_C(  15),  INT8_C(   9),  INT8_C(  14),
         INT8_C(   4),  INT8_C(  14),  INT8_C(  15),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(  13) },
      { UINT8_C(  3),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(  2),    UINT8_MAX } },
    { { UINT8_C(  5), UINT8_C(  1),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  9), UINT8_C(  4),
        UINT8_C(  0), UINT8_C(111), UINT8_C(  3), UINT8_C(  2), UINT8_C(  7), UINT8_C( 24), UINT8_C(  3), UINT8_C(  1) },
      {  INT8_C(   5),  INT8_C(  14),  INT8_C(   7),  INT8_C(  15),  INT8_C(  14),  INT8_C(  12),  INT8_C(  11),  INT8_C(  15),
         INT8_C(  15),  INT8_C(   1),  INT8_C(   5),  INT8_C(  14),  INT8_C(  12),  INT8_C(  12),  INT8_C(  14),  INT8_C(  14) },
      { UINT8_C(160),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(222), UINT8_C( 96),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 54), UINT8_C(  2), UINT8_C( 25), UINT8_C(165), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C( 87),
        UINT8_C(178), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1), UINT8_C(245), UINT8_C( 28), UINT8_C( 78), UINT8_C( 81) },
      {  INT8_C(   0),  INT8_C(  13),  INT8_C(   1),  INT8_C(   6),  INT8_C(  12),  INT8_C(   4),  INT8_C(   2),  INT8_C(  11),
         INT8_C(  13),  INT8_C(   6),  INT8_C(   9),  INT8_C(  15),  INT8_C(  15),  INT8_C(  13),  INT8_C(   6),  INT8_C(   5) },
      { UINT8_C( 54),    UINT8_MAX, UINT8_C( 50),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(192),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  1), UINT8_C(  1), UINT8_C(123), UINT8_C(  5), UINT8_C(  5), UINT8_C( 44), UINT8_C(  8), UINT8_C(  5),
        UINT8_C( 40), UINT8_C(  5), UINT8_C(  2),    UINT8_MAX, UINT8_C(  8), UINT8_C( 84), UINT8_C(  1), UINT8_C( 14) },
      {  INT8_C(   4),  INT8_C(  15),  INT8_C(  15),  INT8_C(   2),  INT8_C(  14),  INT8_C(   6),  INT8_C(   2),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   4),  INT8_C(   4),  INT8_C(  12),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4) },
      { UINT8_C( 16),    UINT8_MAX,    UINT8_MAX, UINT8_C( 20),    UINT8_MAX,    UINT8_MAX, UINT8_C( 32),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  5), UINT8_C( 32),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 32), UINT8_C(224) } },
    { { UINT8_C(232), UINT8_C(  1), UINT8_C( 12), UINT8_C(  1), UINT8_C( 25), UINT8_C(  4), UINT8_C(  3), UINT8_C(192),
        UINT8_C(106), UINT8_C( 88), UINT8_C( 66), UINT8_C(  0), UINT8_C( 29), UINT8_C(  0), UINT8_C(  7), UINT8_C(  0) },
      {  INT8_C(   5),  INT8_C(  15),  INT8_C(  11),  INT8_C(  10),  INT8_C(   8),  INT8_C(  12),  INT8_C(   0),  INT8_C(  11),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   3),  INT8_C(  12),  INT8_C(  13),  INT8_C(  10),  INT8_C(  12),  INT8_C(   5) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  3),    UINT8_MAX,
        UINT8_C(106),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vqshlq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();

    a = simde_vshlq_u8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    b = simde_vandq_s8(b, simde_vdupq_n_s8(15));

    simde_uint8x16_t r = simde_vqshlq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 1010), UINT16_C(    0), UINT16_C(   90), UINT16_C(  211), UINT16_C(    1), UINT16_C(  139), UINT16_C(   44), UINT16_C(    1) },
      {  INT16_C(    17),  INT16_C(    13),  INT16_C(     7),  INT16_C(    27),  INT16_C(     4),  INT16_C(    22),  INT16_C(    23),  INT16_C(    16) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(11520),      UINT16_MAX, UINT16_C(   16),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 6946), UINT16_C(    0), UINT16_C(  894), UINT16_C(  880), UINT16_C(14593), UINT16_C( 3540), UINT16_C(  482), UINT16_C( 2380) },
      {  INT16_C(    29),  INT16_C(     9),  INT16_C(    25),  INT16_C(    24),  INT16_C(    12),  INT16_C(     6),  INT16_C(    23),  INT16_C(    18) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(   93), UINT16_C(  221), UINT16_C(   20), UINT16_C( 2962), UINT16_C(   30), UINT16_C(  258), UINT16_C(    0), UINT16_C(13384) },
      {  INT16_C(    10),  INT16_C(    31),  INT16_C(    20),  INT16_C(    18),  INT16_C(    20),  INT16_C(    22),  INT16_C(    22),  INT16_C(    30) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C( 4017), UINT16_C(  733), UINT16_C(33924), UINT16_C(    0), UINT16_C(  164), UINT16_C( 3541), UINT16_C(11363), UINT16_C(    6) },
      {  INT16_C(     9),  INT16_C(    14),  INT16_C(    29),  INT16_C(    14),  INT16_C(     8),  INT16_C(    18),  INT16_C(    29),  INT16_C(    10) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(41984),      UINT16_MAX,      UINT16_MAX, UINT16_C( 6144) } },
    { { UINT16_C(   11), UINT16_C(   40), UINT16_C(    1), UINT16_C(    0), UINT16_C(  384), UINT16_C(   21), UINT16_C(    4), UINT16_C(    0) },
      {  INT16_C(    30),  INT16_C(    25),  INT16_C(     4),  INT16_C(     5),  INT16_C(     8),  INT16_C(     3),  INT16_C(     5),  INT16_C(    21) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(   16), UINT16_C(    0),      UINT16_MAX, UINT16_C(  168), UINT16_C(  128), UINT16_C(    0) } },
    { { UINT16_C(   29), UINT16_C(14721), UINT16_C(14975), UINT16_C(    2), UINT16_C(   29), UINT16_C(    1), UINT16_C(    1), UINT16_C(12488) },
      {  INT16_C(    23),  INT16_C(    24),  INT16_C(     6),  INT16_C(     2),  INT16_C(     8),  INT16_C(     7),  INT16_C(    26),  INT16_C(    21) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    8), UINT16_C( 7424), UINT16_C(  128),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(  993), UINT16_C(    3), UINT16_C(   15), UINT16_C(  265), UINT16_C(   80), UINT16_C(  331), UINT16_C( 2709), UINT16_C(   25) },
      {  INT16_C(     2),  INT16_C(     5),  INT16_C(     5),  INT16_C(    26),  INT16_C(    28),  INT16_C(    30),  INT16_C(    29),  INT16_C(    17) },
      { UINT16_C( 3972), UINT16_C(   96), UINT16_C(  480),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 2321), UINT16_C(  466), UINT16_C(   29), UINT16_C( 1146), UINT16_C(  930), UINT16_C(    1), UINT16_C(    2), UINT16_C(   39) },
      {  INT16_C(    25),  INT16_C(    15),  INT16_C(    18),  INT16_C(     9),  INT16_C(    17),  INT16_C(    23),  INT16_C(     5),  INT16_C(    27) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(   64),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vqshlq_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();

    a = simde_vshlq_u16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    b = simde_vandq_s16(b, simde_vdupq_n_s16(31));

    simde_uint16x8_t r = simde_vqshlq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(     24300), UINT32_C(         4), UINT32_C(        10), UINT32_C(   5267993) },
      {  INT32_C(          40),  INT32_C(          55),  INT32_C(          12),  INT32_C(           4) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(     40960), UINT32_C(  84287888) } },
    { { UINT32_C(    508275), UINT32_C(     38365), UINT32_C(        77), UINT32_C(3970210525) },
      {  INT32_C(          19),  INT32_C(          54),  INT32_C(          49),  INT32_C(          11) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 414773067), UINT32_C(         3), UINT32_C(       896), UINT32_C(       210) },
      {  INT32_C(          35),  INT32_C(          19),  INT32_C(          51),  INT32_C(           7) },
      {           UINT32_MAX, UINT32_C(   1572864),           UINT32_MAX, UINT32_C(     26880) } },
    { { UINT32_C(    117690), UINT32_C(        89), UINT32_C(         6), UINT32_C(        38) },
      {  INT32_C(          23),  INT32_C(          34),  INT32_C(          45),  INT32_C(          11) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(     77824) } },
    { { UINT32_C(        72), UINT32_C(  10692582), UINT32_C(         0), UINT32_C(  68375885) },
      {  INT32_C(          24),  INT32_C(           0),  INT32_C(          59),  INT32_C(          59) },
      { UINT32_C(1207959552), UINT32_C(  10692582), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3490692944), UINT32_C( 648397257), UINT32_C(  17661220), UINT32_C(         2) },
      {  INT32_C(          33),  INT32_C(          11),  INT32_C(          11),  INT32_C(          17) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(    262144) } },
    { { UINT32_C(  92097311), UINT32_C(     12173), UINT32_C(         0), UINT32_C( 176732640) },
      {  INT32_C(          29),  INT32_C(          58),  INT32_C(          58),  INT32_C(          49) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 198186158), UINT32_C(        23), UINT32_C(         2), UINT32_C(   5784654) },
      {  INT32_C(          15),  INT32_C(           2),  INT32_C(          13),  INT32_C(           0) },
      {           UINT32_MAX, UINT32_C(        92), UINT32_C(     16384), UINT32_C(   5784654) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vqshlq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();

    a = simde_vshlq_u32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    b = simde_vandq_s32(b, simde_vdupq_n_s32(63));

    simde_uint32x4_t r = simde_vqshlq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(                  14), UINT64_C( 6558353326851752741) },
      {  INT64_C(                   6),  INT64_C(                  29) },
      { UINT64_C(                 896),                    UINT64_MAX } },
    { { UINT64_C(   12353627805118795), UINT64_C(           473443966) },
      {  INT64_C(                  46),  INT64_C(                  58) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(                 901), UINT64_C(          1704486418) },
      {  INT64_C(                  36),  INT64_C(                   3) },
      { UINT64_C(      61916248539136), UINT64_C(         13635891344) } },
    { { UINT64_C(                  21), UINT64_C(                  17) },
      {  INT64_C(                  15),  INT64_C(                  62) },
      { UINT64_C(              688128),                    UINT64_MAX } },
    { { UINT64_C(         66472473494), UINT64_C(         47300183899) },
      {  INT64_C(                  58),  INT64_C(                  42) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(           227152248), UINT64_C(           162342530) },
      {  INT64_C(                  60),  INT64_C(                  43) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(               33185), UINT64_C(         31991553854) },
      {  INT64_C(                  31),  INT64_C(                  48) },
      { UINT64_C(      71264244858880),                    UINT64_MAX } },
    { { UINT64_C(          4061564034), UINT64_C(   70125565431909990) },
      {  INT64_C(                  56),  INT64_C(                  24) },
      {                    UINT64_MAX,                    UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vqshlq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();

    a = simde_vshlq_u64(a, simde_vnegq_s64(simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63))));
    b = simde_vandq_s64(b, simde_vdupq_n_s64(63));

    simde_uint64x2_t r = simde_vqshlq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshls_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshld_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshls_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshld_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
