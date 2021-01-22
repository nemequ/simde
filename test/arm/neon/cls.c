#define SIMDE_TEST_ARM_NEON_INSN cls

#include "test-neon.h"
#include "../../../simde/arm/neon/cls.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/set_lane.h"
#include "../../../simde/arm/neon/shl.h"

static int
test_simde_vcls_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(   0), -INT8_C(   1), -INT8_C(   2),  INT8_C(   6), -INT8_C(   1), -INT8_C(   4),  INT8_C(   8), -INT8_C(   1) },
      {  INT8_C(   7),  INT8_C(   7),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   5),  INT8_C(   3),  INT8_C(   7) } },
    { { -INT8_C(  14), -INT8_C(   4), -INT8_C(   1), -INT8_C(   1), -INT8_C(   3), -INT8_C(  97),  INT8_C(   0),  INT8_C(  14) },
      {  INT8_C(   3),  INT8_C(   5),  INT8_C(   7),  INT8_C(   7),  INT8_C(   5),  INT8_C(   0),  INT8_C(   7),  INT8_C(   3) } },
    { {  INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   3),  INT8_C(  12), -INT8_C(  37), -INT8_C(  48), -INT8_C(  59) },
      {  INT8_C(   6),  INT8_C(   7),  INT8_C(   7),  INT8_C(   5),  INT8_C(   3),  INT8_C(   1),  INT8_C(   1),  INT8_C(   1) } },
    { {  INT8_C(  17),  INT8_C(  24), -INT8_C(   7), -INT8_C(   2),  INT8_C(   0), -INT8_C(  13),  INT8_C(   0), -INT8_C(   1) },
      {  INT8_C(   2),  INT8_C(   2),  INT8_C(   4),  INT8_C(   6),  INT8_C(   7),  INT8_C(   3),  INT8_C(   7),  INT8_C(   7) } },
    { { -INT8_C(  20),  INT8_C(   0),  INT8_C(  15),  INT8_C(   0), -INT8_C(  37),  INT8_C(   4), -INT8_C(   1), -INT8_C(  16) },
      {  INT8_C(   2),  INT8_C(   7),  INT8_C(   3),  INT8_C(   7),  INT8_C(   1),  INT8_C(   4),  INT8_C(   7),  INT8_C(   3) } },
    { { -INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C( 102), -INT8_C(   1),  INT8_C(   1),  INT8_C(   0), -INT8_C(  19) },
      {  INT8_C(   6),  INT8_C(   7),  INT8_C(   7),  INT8_C(   0),  INT8_C(   7),  INT8_C(   6),  INT8_C(   7),  INT8_C(   2) } },
    { { -INT8_C(   4), -INT8_C(  27), -INT8_C(   1), -INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3), -INT8_C(   3) },
      {  INT8_C(   5),  INT8_C(   2),  INT8_C(   7),  INT8_C(   4),  INT8_C(   7),  INT8_C(   7),  INT8_C(   5),  INT8_C(   5) } },
    { {  INT8_C(   2), -INT8_C(   2), -INT8_C(  12), -INT8_C(   1),  INT8_C(   1),  INT8_C(   3), -INT8_C(   3),  INT8_C(   1) },
      {  INT8_C(   5),  INT8_C(   6),  INT8_C(   3),  INT8_C(   7),  INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   6) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vcls_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    a = simde_vshl_s8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    if (i == 0) {
      a = simde_vset_lane_s8( INT8_C(0), a, 0);
      a = simde_vset_lane_s8(-INT8_C(1), a, 1);
    }
    simde_int8x8_t r = simde_vcls_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcls_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(     0), -INT16_C(     1), -INT16_C(     4), -INT16_C(   980) },
      {  INT16_C(    15),  INT16_C(    15),  INT16_C(    13),  INT16_C(     5) } },
    { {  INT16_C(   439), -INT16_C(  1580), -INT16_C(     4), -INT16_C( 19564) },
      {  INT16_C(     6),  INT16_C(     4),  INT16_C(    13),  INT16_C(     0) } },
    { { -INT16_C(   358), -INT16_C(     8), -INT16_C(  8990), -INT16_C(  8693) },
      {  INT16_C(     6),  INT16_C(    12),  INT16_C(     1),  INT16_C(     1) } },
    { {  INT16_C(   776),  INT16_C(     0), -INT16_C(  6837), -INT16_C(     1) },
      {  INT16_C(     5),  INT16_C(    15),  INT16_C(     2),  INT16_C(    15) } },
    { { -INT16_C(    56),  INT16_C(     0),  INT16_C( 13221),  INT16_C(     0) },
      {  INT16_C(     9),  INT16_C(    15),  INT16_C(     1),  INT16_C(    15) } },
    { { -INT16_C(     1), -INT16_C(     3), -INT16_C(     1), -INT16_C(   170) },
      {  INT16_C(    15),  INT16_C(    13),  INT16_C(    15),  INT16_C(     7) } },
    { { -INT16_C(    16), -INT16_C(     7),  INT16_C(     1),  INT16_C(    16) },
      {  INT16_C(    11),  INT16_C(    12),  INT16_C(    14),  INT16_C(    10) } },
    { { -INT16_C(     2), -INT16_C(     1), -INT16_C(     1), -INT16_C(    15) },
      {  INT16_C(    14),  INT16_C(    15),  INT16_C(    15),  INT16_C(    11) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vcls_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    a = simde_vshl_s16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    if (i == 0) {
      a = simde_vset_lane_s16( INT16_C(0), a, 0);
      a = simde_vset_lane_s16(-INT16_C(1), a, 1);
    }
    simde_int16x4_t r = simde_vcls_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcls_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(           0), -INT32_C(           1) },
      {  INT32_C(          31),  INT32_C(          31) } },
    { {  INT32_C(        5692),  INT32_C(     8382156) },
      {  INT32_C(          18),  INT32_C(           8) } },
    { { -INT32_C(        3780), -INT32_C(       72139) },
      {  INT32_C(          19),  INT32_C(          14) } },
    { { -INT32_C(          39), -INT32_C(    28205650) },
      {  INT32_C(          25),  INT32_C(           6) } },
    { { -INT32_C(          16), -INT32_C(       80820) },
      {  INT32_C(          27),  INT32_C(          14) } },
    { {  INT32_C(       18993), -INT32_C(      287849) },
      {  INT32_C(          16),  INT32_C(          12) } },
    { {  INT32_C(   137743468), -INT32_C(     5881742) },
      {  INT32_C(           3),  INT32_C(           8) } },
    { { -INT32_C(     5524402), -INT32_C(       25465) },
      {  INT32_C(           8),  INT32_C(          16) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vcls_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    a = simde_vshl_s32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    if (i == 0) {
      a = simde_vset_lane_s32( INT32_C(0), a, 0);
      a = simde_vset_lane_s32(-INT32_C(1), a, 1);
    }
    simde_int32x2_t r = simde_vcls_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* clang and GCC are both missing the unsigned versions
   of these functions.  See https://bugs.llvm.org/show_bug.cgi?id=47407 */
#if !defined(SIMDE_NATIVE_ALIASES_TESTING)

static int
test_simde_vcls_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { { UINT8_C(  0),    UINT8_MAX, UINT8_C(113), UINT8_C( 36), UINT8_C( 14), UINT8_C(  0), UINT8_C(  3), UINT8_C( 31) },
      {  INT8_C(   7),  INT8_C(   7),  INT8_C(   0),  INT8_C(   1),  INT8_C(   3),  INT8_C(   7),  INT8_C(   5),  INT8_C(   2) } },
    { { UINT8_C( 60), UINT8_C( 30), UINT8_C( 10), UINT8_C( 63), UINT8_C( 17), UINT8_C( 22), UINT8_C(  9), UINT8_C(  4) },
      {  INT8_C(   1),  INT8_C(   2),  INT8_C(   3),  INT8_C(   1),  INT8_C(   2),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4) } },
    { { UINT8_C( 17), UINT8_C(  0), UINT8_C(  4), UINT8_C(  5), UINT8_C( 10), UINT8_C(162), UINT8_C(180), UINT8_C( 34) },
      {  INT8_C(   2),  INT8_C(   7),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1) } },
    { { UINT8_C(  0), UINT8_C(  2), UINT8_C( 41), UINT8_C( 21), UINT8_C(  1), UINT8_C(  6), UINT8_C( 57), UINT8_C(  0) },
      {  INT8_C(   7),  INT8_C(   5),  INT8_C(   1),  INT8_C(   2),  INT8_C(   6),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7) } },
    { { UINT8_C( 39), UINT8_C( 47), UINT8_C(  1), UINT8_C( 41), UINT8_C(  0), UINT8_C(  1), UINT8_C( 14), UINT8_C( 77) },
      {  INT8_C(   1),  INT8_C(   1),  INT8_C(   6),  INT8_C(   1),  INT8_C(   7),  INT8_C(   6),  INT8_C(   3),  INT8_C(   0) } },
    { { UINT8_C(127), UINT8_C( 47), UINT8_C( 12), UINT8_C( 93), UINT8_C(  1), UINT8_C( 15), UINT8_C(  3), UINT8_C( 26) },
      {  INT8_C(   0),  INT8_C(   1),  INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),  INT8_C(   2) } },
    { { UINT8_C(  1), UINT8_C( 27), UINT8_C(  4), UINT8_C(162), UINT8_C( 29), UINT8_C(  3), UINT8_C( 15), UINT8_C( 84) },
      {  INT8_C(   6),  INT8_C(   2),  INT8_C(   4),  INT8_C(   0),  INT8_C(   2),  INT8_C(   5),  INT8_C(   3),  INT8_C(   0) } },
    { { UINT8_C(  0), UINT8_C( 41), UINT8_C( 59), UINT8_C(  3), UINT8_C(  2), UINT8_C(181), UINT8_C( 45), UINT8_C(121) },
      {  INT8_C(   7),  INT8_C(   1),  INT8_C(   1),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t r = simde_vcls_u8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    a = simde_vshl_u8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    if (i == 0) {
      a = simde_vset_lane_u8(UINT8_C(0), a, 0);
      a = simde_vset_lane_u8( UINT8_MAX, a, 1);
    }
    simde_int8x8_t r = simde_vcls_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcls_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { UINT16_C(    0),      UINT16_MAX, UINT16_C(  460), UINT16_C(    0) },
      {  INT16_C(    15),  INT16_C(    15),  INT16_C(     6),  INT16_C(    15) } },
    { { UINT16_C(  496), UINT16_C(   15), UINT16_C( 6837), UINT16_C( 1259) },
      {  INT16_C(     6),  INT16_C(    11),  INT16_C(     2),  INT16_C(     4) } },
    { { UINT16_C(   15), UINT16_C(   63), UINT16_C(    6), UINT16_C(   79) },
      {  INT16_C(    11),  INT16_C(     9),  INT16_C(    12),  INT16_C(     8) } },
    { { UINT16_C(  402), UINT16_C( 1467), UINT16_C(    4), UINT16_C(    4) },
      {  INT16_C(     6),  INT16_C(     4),  INT16_C(    12),  INT16_C(    12) } },
    { { UINT16_C(   28), UINT16_C(  755), UINT16_C(    3), UINT16_C(   14) },
      {  INT16_C(    10),  INT16_C(     5),  INT16_C(    13),  INT16_C(    11) } },
    { { UINT16_C(   38), UINT16_C(  821), UINT16_C(   57), UINT16_C( 1759) },
      {  INT16_C(     9),  INT16_C(     5),  INT16_C(     9),  INT16_C(     4) } },
    { { UINT16_C( 2122), UINT16_C(  480), UINT16_C(  402), UINT16_C(   27) },
      {  INT16_C(     3),  INT16_C(     6),  INT16_C(     6),  INT16_C(    10) } },
    { { UINT16_C(    2), UINT16_C(  239), UINT16_C( 7107), UINT16_C(   89) },
      {  INT16_C(    13),  INT16_C(     7),  INT16_C(     2),  INT16_C(     8) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t r = simde_vcls_u16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    a = simde_vshl_u16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    if (i == 0) {
      a = simde_vset_lane_u16(UINT16_C(0), a, 0);
      a = simde_vset_lane_u16( UINT16_MAX, a, 1);
    }
    simde_int16x4_t r = simde_vcls_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcls_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { { UINT32_C(         0),           UINT32_MAX },
      {  INT32_C(          31),  INT32_C(          31) } },
    { { UINT32_C(         1), UINT32_C(        78) },
      {  INT32_C(          30),  INT32_C(          24) } },
    { { UINT32_C( 102847535), UINT32_C(      2594) },
      {  INT32_C(           4),  INT32_C(          19) } },
    { { UINT32_C(      2630), UINT32_C(       493) },
      {  INT32_C(          19),  INT32_C(          22) } },
    { { UINT32_C(       187), UINT32_C(      1733) },
      {  INT32_C(          23),  INT32_C(          20) } },
    { { UINT32_C(     11704), UINT32_C(      3651) },
      {  INT32_C(          17),  INT32_C(          19) } },
    { { UINT32_C(   7030603), UINT32_C( 245915039) },
      {  INT32_C(           8),  INT32_C(           3) } },
    { { UINT32_C(        25), UINT32_C(   2041698) },
      {  INT32_C(          26),  INT32_C(          10) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t r = simde_vcls_u32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    a = simde_vshl_u32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    if (i == 0) {
      a = simde_vset_lane_u32(UINT32_C(0), a, 0);
      a = simde_vset_lane_u32( UINT32_MAX, a, 1);
    }
    simde_int32x2_t r = simde_vcls_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif

static int
test_simde_vclsq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   0), -INT8_C(   1), -INT8_C(   9),  INT8_C(   4), -INT8_C(  36),  INT8_C(   0), -INT8_C( 123), -INT8_C(  16),
        -INT8_C(  11),  INT8_C(  12),  INT8_C(   3), -INT8_C(   5),  INT8_C(  47),  INT8_C(   0), -INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   7),  INT8_C(   7),  INT8_C(   3),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7),  INT8_C(   0),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7),  INT8_C(   6),  INT8_C(   7) } },
    { {  INT8_C(   0), -INT8_C(   1),  INT8_C(   4),  INT8_C(  44),  INT8_C(   0), -INT8_C(   6), -INT8_C(   5), -INT8_C(  18),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20),  INT8_C(   6),  INT8_C(  12) },
      {  INT8_C(   7),  INT8_C(   7),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7),  INT8_C(   4),  INT8_C(   4),  INT8_C(   2),
         INT8_C(   7),  INT8_C(   7),  INT8_C(   6),  INT8_C(   7),  INT8_C(   7),  INT8_C(   2),  INT8_C(   4),  INT8_C(   3) } },
    { { -INT8_C(   1), -INT8_C(   2),  INT8_C(   3),  INT8_C(   1),  INT8_C(  18),  INT8_C(   0), -INT8_C(   2),  INT8_C(  44),
         INT8_C(   6),  INT8_C(   6), -INT8_C( 106),  INT8_C(  24), -INT8_C(   4), -INT8_C(   4), -INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   7),  INT8_C(   6),  INT8_C(   5),  INT8_C(   6),  INT8_C(   2),  INT8_C(   7),  INT8_C(   6),  INT8_C(   1),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   0),  INT8_C(   2),  INT8_C(   5),  INT8_C(   5),  INT8_C(   7),  INT8_C(   7) } },
    { {  INT8_C(   9),  INT8_C(   0), -INT8_C(   1),  INT8_C(  11),  INT8_C(   3), -INT8_C(  15), -INT8_C(   5),  INT8_C(   0),
        -INT8_C(   2),  INT8_C(   4), -INT8_C(  96),  INT8_C(   7),  INT8_C(  23),  INT8_C(   1),  INT8_C(   0),  INT8_C(   4) },
      {  INT8_C(   3),  INT8_C(   7),  INT8_C(   7),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   7),
         INT8_C(   6),  INT8_C(   4),  INT8_C(   0),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),  INT8_C(   7),  INT8_C(   4) } },
    { { -INT8_C(  44), -INT8_C(   2),  INT8_C(   0), -INT8_C(   4),  INT8_C(   5), -INT8_C(   2),  INT8_C(  15), -INT8_C(   1),
         INT8_C(   0), -INT8_C(  32),  INT8_C(   0),  INT8_C(  85),  INT8_C(  35),  INT8_C(  29), -INT8_C(   7), -INT8_C(   4) },
      {  INT8_C(   1),  INT8_C(   6),  INT8_C(   7),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3),  INT8_C(   7),
         INT8_C(   7),  INT8_C(   2),  INT8_C(   7),  INT8_C(   0),  INT8_C(   1),  INT8_C(   2),  INT8_C(   4),  INT8_C(   5) } },
    { {  INT8_C(   2),  INT8_C(  21),  INT8_C(  12),  INT8_C(   1),  INT8_C(   2), -INT8_C(   8), -INT8_C(   2), -INT8_C(   4),
         INT8_C(   1), -INT8_C(   1), -INT8_C(   2),  INT8_C(   1),  INT8_C(  32),  INT8_C(  58),  INT8_C(  12), -INT8_C(   1) },
      {  INT8_C(   5),  INT8_C(   2),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   6),  INT8_C(   7),  INT8_C(   6),  INT8_C(   6),  INT8_C(   1),  INT8_C(   1),  INT8_C(   3),  INT8_C(   7) } },
    { { -INT8_C(   1), -INT8_C(   2),  INT8_C(   8),  INT8_C(   2),  INT8_C(   5),  INT8_C(   0), -INT8_C( 101),  INT8_C(  88),
         INT8_C(   0),  INT8_C(   3), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   7),  INT8_C(   3),  INT8_C(   7) },
      {  INT8_C(   7),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   7),  INT8_C(   5),  INT8_C(   7),  INT8_C(   7),  INT8_C(   7),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4) } },
    { { -INT8_C( 104), -INT8_C(  17), -INT8_C(  28), -INT8_C(  11), -INT8_C(  14),  INT8_C(  11),  INT8_C(   0), -INT8_C(  18),
        -INT8_C(  93), -INT8_C(  15),  INT8_C(   0), -INT8_C(   2), -INT8_C(   9),  INT8_C(  12), -INT8_C(  13),  INT8_C(  15) },
      {  INT8_C(   0),  INT8_C(   2),  INT8_C(   2),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   7),  INT8_C(   2),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   7),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vclsq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    a = simde_vshlq_s8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    if (i == 0) {
      a = simde_vsetq_lane_s8( INT8_C(0), a, 0);
      a = simde_vsetq_lane_s8(-INT8_C(1), a, 1);
    }
    simde_int8x16_t r = simde_vclsq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclsq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(    11),  INT16_C(     1), -INT16_C(     8),  INT16_C(    69),  INT16_C(     0) },
      {  INT16_C(    15),  INT16_C(    15),  INT16_C(    15),  INT16_C(    11),  INT16_C(    14),  INT16_C(    12),  INT16_C(     8),  INT16_C(    15) } },
    { {  INT16_C(    25),  INT16_C(    39),  INT16_C(   412),  INT16_C(   550),  INT16_C(     0),  INT16_C(  1971), -INT16_C(    82),  INT16_C(   530) },
      {  INT16_C(    10),  INT16_C(     9),  INT16_C(     6),  INT16_C(     5),  INT16_C(    15),  INT16_C(     4),  INT16_C(     8),  INT16_C(     5) } },
    { { -INT16_C(     7), -INT16_C(  3665), -INT16_C(     4),  INT16_C(     1), -INT16_C(    20), -INT16_C(     2), -INT16_C(     1), -INT16_C(    43) },
      {  INT16_C(    12),  INT16_C(     3),  INT16_C(    13),  INT16_C(    14),  INT16_C(    10),  INT16_C(    14),  INT16_C(    15),  INT16_C(     9) } },
    { { -INT16_C(     6),  INT16_C(   109), -INT16_C(  7304),  INT16_C(  1198),  INT16_C(   134),  INT16_C(    13),  INT16_C(     0),  INT16_C(    11) },
      {  INT16_C(    12),  INT16_C(     8),  INT16_C(     2),  INT16_C(     4),  INT16_C(     7),  INT16_C(    11),  INT16_C(    15),  INT16_C(    11) } },
    { {  INT16_C(    28), -INT16_C(    14),  INT16_C(    27),  INT16_C(   271), -INT16_C(     5),  INT16_C(   257), -INT16_C(  3548), -INT16_C(    59) },
      {  INT16_C(    10),  INT16_C(    11),  INT16_C(    10),  INT16_C(     6),  INT16_C(    12),  INT16_C(     6),  INT16_C(     3),  INT16_C(     9) } },
    { {  INT16_C(     0), -INT16_C(   364), -INT16_C(     1),  INT16_C(    15),  INT16_C(    12), -INT16_C(   651), -INT16_C(     1),  INT16_C(     0) },
      {  INT16_C(    15),  INT16_C(     6),  INT16_C(    15),  INT16_C(    11),  INT16_C(    11),  INT16_C(     5),  INT16_C(    15),  INT16_C(    15) } },
    { {  INT16_C(     0),  INT16_C(  4449),  INT16_C(    28), -INT16_C(  5416), -INT16_C(     8),  INT16_C(  2848),  INT16_C(  9525),  INT16_C(     6) },
      {  INT16_C(    15),  INT16_C(     2),  INT16_C(    10),  INT16_C(     2),  INT16_C(    12),  INT16_C(     3),  INT16_C(     1),  INT16_C(    12) } },
    { { -INT16_C(   793),  INT16_C(   107),  INT16_C(   776),  INT16_C(  7301), -INT16_C( 26590), -INT16_C(    15), -INT16_C(   804),  INT16_C(    19) },
      {  INT16_C(     5),  INT16_C(     8),  INT16_C(     5),  INT16_C(     2),  INT16_C(     0),  INT16_C(    11),  INT16_C(     5),  INT16_C(    10) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vclsq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    a = simde_vshlq_s16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    if (i == 0) {
      a = simde_vsetq_lane_s16( INT16_C(0), a, 0);
      a = simde_vsetq_lane_s16(-INT16_C(1), a, 1);
    }
    simde_int16x8_t r = simde_vclsq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclsq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(           0), -INT32_C(           1), -INT32_C(          24),  INT32_C(  1190162929) },
      {  INT32_C(          31),  INT32_C(          31),  INT32_C(          26),  INT32_C(           0) } },
    { { -INT32_C(       32305), -INT32_C(           7),  INT32_C(           0), -INT32_C(          23) },
      {  INT32_C(          16),  INT32_C(          28),  INT32_C(          31),  INT32_C(          26) } },
    { {  INT32_C(    11961030), -INT32_C(          12),  INT32_C(       16145),  INT32_C(      501969) },
      {  INT32_C(           7),  INT32_C(          27),  INT32_C(          17),  INT32_C(          12) } },
    { { -INT32_C(         241),  INT32_C(     2208371),  INT32_C(        2033), -INT32_C(      472613) },
      {  INT32_C(          23),  INT32_C(           9),  INT32_C(          20),  INT32_C(          12) } },
    { { -INT32_C(          16),  INT32_C(      367204), -INT32_C(     8202558), -INT32_C(     9760908) },
      {  INT32_C(          27),  INT32_C(          12),  INT32_C(           8),  INT32_C(           7) } },
    { {  INT32_C(         461), -INT32_C(         129), -INT32_C(        1296), -INT32_C(       24948) },
      {  INT32_C(          22),  INT32_C(          23),  INT32_C(          20),  INT32_C(          16) } },
    { { -INT32_C(           1),  INT32_C(       55140),  INT32_C(       58632), -INT32_C(   466226226) },
      {  INT32_C(          31),  INT32_C(          15),  INT32_C(          15),  INT32_C(           2) } },
    { { -INT32_C(     1373374),  INT32_C(   542555820),  INT32_C(        1355), -INT32_C(       11555) },
      {  INT32_C(          10),  INT32_C(           1),  INT32_C(          20),  INT32_C(          17) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vclsq_s32(a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    a = simde_vshlq_s32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    if (i == 0) {
      a = simde_vsetq_lane_s32( INT32_C(0), a, 0);
      a = simde_vsetq_lane_s32(-INT32_C(1), a, 1);
    }
    simde_int32x4_t r = simde_vclsq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(SIMDE_NATIVE_ALIASES_TESTING)

static int
test_simde_vclsq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  0),    UINT8_MAX, UINT8_C(  7), UINT8_C( 18), UINT8_C( 91), UINT8_C( 73), UINT8_C( 44), UINT8_C( 10),
        UINT8_C(226), UINT8_C( 13), UINT8_C( 52), UINT8_C( 18), UINT8_C(  1), UINT8_C(  1), UINT8_C( 59), UINT8_C(  6) },
      {  INT8_C(   7),  INT8_C(   7),  INT8_C(   4),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   3),
         INT8_C(   2),  INT8_C(   3),  INT8_C(   1),  INT8_C(   2),  INT8_C(   6),  INT8_C(   6),  INT8_C(   1),  INT8_C(   4) } },
    { { UINT8_C( 14), UINT8_C( 79), UINT8_C( 18), UINT8_C(  4), UINT8_C(115), UINT8_C(  2), UINT8_C( 35), UINT8_C(100),
        UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C( 37), UINT8_C( 20), UINT8_C(  0), UINT8_C(  3), UINT8_C( 28) },
      {  INT8_C(   3),  INT8_C(   0),  INT8_C(   2),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),  INT8_C(   1),  INT8_C(   0),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   1),  INT8_C(   2),  INT8_C(   7),  INT8_C(   5),  INT8_C(   2) } },
    { { UINT8_C(102), UINT8_C(  4), UINT8_C( 21), UINT8_C( 44), UINT8_C( 56), UINT8_C( 15), UINT8_C(  7), UINT8_C( 55),
        UINT8_C( 11), UINT8_C(  1), UINT8_C( 51), UINT8_C( 22), UINT8_C(  4), UINT8_C(100), UINT8_C(  2), UINT8_C( 63) },
      {  INT8_C(   0),  INT8_C(   4),  INT8_C(   2),  INT8_C(   1),  INT8_C(   1),  INT8_C(   3),  INT8_C(   4),  INT8_C(   1),
         INT8_C(   3),  INT8_C(   6),  INT8_C(   1),  INT8_C(   2),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),  INT8_C(   1) } },
    { { UINT8_C(  1), UINT8_C(  6), UINT8_C(  0), UINT8_C( 94), UINT8_C( 89), UINT8_C( 16), UINT8_C(150), UINT8_C( 95),
        UINT8_C(  2), UINT8_C( 12), UINT8_C(  6), UINT8_C(164), UINT8_C(  2), UINT8_C(  0), UINT8_C(  8), UINT8_C( 59) },
      {  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),  INT8_C(   7),  INT8_C(   3),  INT8_C(   1) } },
    { { UINT8_C(  0), UINT8_C( 57), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C( 75), UINT8_C(123),
        UINT8_C( 45), UINT8_C(  0), UINT8_C( 15), UINT8_C(  4), UINT8_C(  7), UINT8_C(  8), UINT8_C(  0), UINT8_C(  5) },
      {  INT8_C(   7),  INT8_C(   1),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   1),  INT8_C(   7),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   7),  INT8_C(   4) } },
    { { UINT8_C( 13), UINT8_C( 21), UINT8_C(  5), UINT8_C(105), UINT8_C( 79), UINT8_C( 12), UINT8_C( 39), UINT8_C( 62),
        UINT8_C( 50), UINT8_C( 27), UINT8_C(  0), UINT8_C( 52), UINT8_C(  5), UINT8_C(  3), UINT8_C(  1), UINT8_C(  1) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   1),  INT8_C(   1),
         INT8_C(   1),  INT8_C(   2),  INT8_C(   7),  INT8_C(   1),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6) } },
    { { UINT8_C(  5), UINT8_C( 26), UINT8_C(  5), UINT8_C( 22), UINT8_C(  1), UINT8_C(  0), UINT8_C(  5), UINT8_C( 48),
        UINT8_C( 58), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  4), UINT8_C( 22), UINT8_C(  2), UINT8_C( 25) },
      {  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),  INT8_C(   7),  INT8_C(   4),  INT8_C(   1),
         INT8_C(   1),  INT8_C(   5),  INT8_C(   5),  INT8_C(   7),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(   2) } },
    { { UINT8_C( 13), UINT8_C( 16), UINT8_C( 12), UINT8_C(  6), UINT8_C(  0), UINT8_C(  3), UINT8_C(  6), UINT8_C(158),
        UINT8_C( 30), UINT8_C(125), UINT8_C(  1), UINT8_C(  0), UINT8_C(  5), UINT8_C(  3), UINT8_C(124), UINT8_C(  3) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   7),  INT8_C(   5),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   6),  INT8_C(   7),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0),  INT8_C(   5) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t r = simde_vclsq_u8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    a = simde_vshlq_u8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    if (i == 0) {
      a = simde_vsetq_lane_u8(UINT8_C(0), a, 0);
      a = simde_vsetq_lane_u8( UINT8_MAX, a, 1);
    }
    simde_int8x16_t r = simde_vclsq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclsq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { UINT16_C(    0),      UINT16_MAX, UINT16_C( 3478), UINT16_C(    2), UINT16_C(48946), UINT16_C( 7341), UINT16_C(29212), UINT16_C(   15) },
      {  INT16_C(    15),  INT16_C(    15),  INT16_C(     3),  INT16_C(    13),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0),  INT16_C(    11) } },
    { { UINT16_C(14806), UINT16_C(   11), UINT16_C(    3), UINT16_C(10114), UINT16_C(  438), UINT16_C( 5958), UINT16_C(    0), UINT16_C(    0) },
      {  INT16_C(     1),  INT16_C(    11),  INT16_C(    13),  INT16_C(     1),  INT16_C(     6),  INT16_C(     2),  INT16_C(    15),  INT16_C(    15) } },
    { { UINT16_C(16922), UINT16_C(    5), UINT16_C(   57), UINT16_C(    3), UINT16_C(13716), UINT16_C(  164), UINT16_C(    0), UINT16_C(    5) },
      {  INT16_C(     0),  INT16_C(    12),  INT16_C(     9),  INT16_C(    13),  INT16_C(     1),  INT16_C(     7),  INT16_C(    15),  INT16_C(    12) } },
    { { UINT16_C(   23), UINT16_C(   89), UINT16_C( 2792), UINT16_C( 2343), UINT16_C(  127), UINT16_C(  260), UINT16_C(  935), UINT16_C(    0) },
      {  INT16_C(    10),  INT16_C(     8),  INT16_C(     3),  INT16_C(     3),  INT16_C(     8),  INT16_C(     6),  INT16_C(     5),  INT16_C(    15) } },
    { { UINT16_C(   60), UINT16_C( 2113), UINT16_C(    3), UINT16_C( 3860), UINT16_C(13951), UINT16_C(29946), UINT16_C(    3), UINT16_C(  474) },
      {  INT16_C(     9),  INT16_C(     3),  INT16_C(    13),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0),  INT16_C(    13),  INT16_C(     6) } },
    { { UINT16_C(    1), UINT16_C(   62), UINT16_C(    0), UINT16_C( 1979), UINT16_C(  109), UINT16_C(   14), UINT16_C( 7464), UINT16_C( 3008) },
      {  INT16_C(    14),  INT16_C(     9),  INT16_C(    15),  INT16_C(     4),  INT16_C(     8),  INT16_C(    11),  INT16_C(     2),  INT16_C(     3) } },
    { { UINT16_C(   72), UINT16_C(    2), UINT16_C(  135), UINT16_C(   25), UINT16_C(  248), UINT16_C( 1679), UINT16_C( 3838), UINT16_C(    0) },
      {  INT16_C(     8),  INT16_C(    13),  INT16_C(     7),  INT16_C(    10),  INT16_C(     7),  INT16_C(     4),  INT16_C(     3),  INT16_C(    15) } },
    { { UINT16_C( 2263), UINT16_C(    0), UINT16_C(   11), UINT16_C(   31), UINT16_C(    3), UINT16_C(35599), UINT16_C(  313), UINT16_C( 4514) },
      {  INT16_C(     3),  INT16_C(    15),  INT16_C(    11),  INT16_C(    10),  INT16_C(    13),  INT16_C(     0),  INT16_C(     6),  INT16_C(     2) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t r = simde_vclsq_u16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    a = simde_vshlq_u16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    if (i == 0) {
      a = simde_vsetq_lane_u16(UINT16_C(0), a, 0);
      a = simde_vsetq_lane_u16( UINT16_MAX, a, 1);
    }
    simde_int16x8_t r = simde_vclsq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclsq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { { UINT32_C(         0),           UINT32_MAX, UINT32_C(   1556457), UINT32_C(       848) },
      {  INT32_C(          31),  INT32_C(          31),  INT32_C(          10),  INT32_C(          21) } },
    { { UINT32_C(   2905984), UINT32_C( 449098526), UINT32_C(    102184), UINT32_C(         7) },
      {  INT32_C(           9),  INT32_C(           2),  INT32_C(          14),  INT32_C(          28) } },
    { { UINT32_C(         0), UINT32_C(     98276), UINT32_C(         2), UINT32_C( 176368497) },
      {  INT32_C(          31),  INT32_C(          14),  INT32_C(          29),  INT32_C(           3) } },
    { { UINT32_C(   1941758), UINT32_C(       314), UINT32_C(      1267), UINT32_C(  74738014) },
      {  INT32_C(          10),  INT32_C(          22),  INT32_C(          20),  INT32_C(           4) } },
    { { UINT32_C(     21888), UINT32_C(     68176), UINT32_C(        84), UINT32_C(    571158) },
      {  INT32_C(          16),  INT32_C(          14),  INT32_C(          24),  INT32_C(          11) } },
    { { UINT32_C(    109194), UINT32_C(  97702763), UINT32_C(    203919), UINT32_C( 224015726) },
      {  INT32_C(          14),  INT32_C(           4),  INT32_C(          13),  INT32_C(           3) } },
    { { UINT32_C(       960), UINT32_C(1498788316), UINT32_C(       807), UINT32_C(       212) },
      {  INT32_C(          21),  INT32_C(           0),  INT32_C(          21),  INT32_C(          23) } },
    { { UINT32_C(        52), UINT32_C(        31), UINT32_C(       508), UINT32_C(      1422) },
      {  INT32_C(          25),  INT32_C(          26),  INT32_C(          22),  INT32_C(          20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t r = simde_vclsq_u32(a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    a = simde_vshlq_u32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    if (i == 0) {
      a = simde_vsetq_lane_u32(UINT32_C(0), a, 0);
      a = simde_vsetq_lane_u32( UINT32_MAX, a, 1);
    }
    simde_int32x4_t r = simde_vclsq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcls_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcls_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcls_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclsq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclsq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclsq_s32)

#if !defined(SIMDE_NATIVE_ALIASES_TESTING)
SIMDE_TEST_FUNC_LIST_ENTRY(vcls_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcls_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcls_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclsq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclsq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclsq_u32)
#endif
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
