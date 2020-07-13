#define SIMDE_TEST_ARM_NEON_INSN qshl

#include "test-neon.h"
#include "../../../simde/arm/neon/qshl.h"


static int
test_simde_vqshl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  67), -INT8_C( 118), -INT8_C(  50), -INT8_C(  67), -INT8_C( 126), -INT8_C(  81), -INT8_C(  46), -INT8_C(  10) },
      { -INT8_C( 126),  INT8_C(  11),  INT8_C(  33), -INT8_C(  90), -INT8_C( 103),  INT8_C(  52),  INT8_C( 123), -INT8_C(  81) },
      { -INT8_C(   1),      INT8_MIN,      INT8_MIN, -INT8_C(   1), -INT8_C(   1),      INT8_MIN,      INT8_MIN, -INT8_C(   1) } },
    { { -INT8_C(  96), -INT8_C( 114), -INT8_C(   3), -INT8_C(  35), -INT8_C( 101), -INT8_C(  42), -INT8_C(  25),  INT8_C(   6) },
      { -INT8_C( 111),  INT8_C(  66), -INT8_C(   1),  INT8_C(   2), -INT8_C(  26), -INT8_C( 127), -INT8_C( 113), -INT8_C(  93) },
      { -INT8_C(   1),      INT8_MIN, -INT8_C(   2),      INT8_MIN, -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  11),  INT8_C(  93),  INT8_C(  97), -INT8_C( 115),  INT8_C(  12),  INT8_C(  51), -INT8_C( 124), -INT8_C( 114) },
      {  INT8_C(  62), -INT8_C(  91),  INT8_C(  52), -INT8_C(  40), -INT8_C(  39), -INT8_C(  80), -INT8_C( 121),  INT8_C( 121) },
      {      INT8_MAX,  INT8_C(   0),      INT8_MAX, -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),      INT8_MIN } },
    { {  INT8_C(  62), -INT8_C( 124),  INT8_C(  86), -INT8_C(  38),  INT8_C(  91),  INT8_C(  61), -INT8_C(  32), -INT8_C(  20) },
      {      INT8_MAX, -INT8_C(  33), -INT8_C(  17),  INT8_C( 101),  INT8_C(  96),  INT8_C( 126),  INT8_C(   9),  INT8_C( 108) },
      {      INT8_MAX, -INT8_C(   1),  INT8_C(   0),      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN } },
    { { -INT8_C(  37),  INT8_C( 106), -INT8_C(   7), -INT8_C(  25), -INT8_C(  99),  INT8_C( 125),  INT8_C( 118), -INT8_C(  37) },
      {  INT8_C(  34), -INT8_C(  86), -INT8_C(  77), -INT8_C(   5),  INT8_C(  90),  INT8_C(  59),  INT8_C( 117), -INT8_C( 103) },
      {      INT8_MIN,  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(   1) } },
    { { -INT8_C(  65), -INT8_C(  53),  INT8_C( 115),  INT8_C(  26),  INT8_C(   9),  INT8_C(  83),  INT8_C(   7), -INT8_C( 120) },
      {  INT8_C(  50), -INT8_C(  10), -INT8_C(  18), -INT8_C( 109),  INT8_C( 116), -INT8_C(   9), -INT8_C(   1),  INT8_C(  79) },
      {      INT8_MIN, -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,  INT8_C(   0),  INT8_C(   3),      INT8_MIN } },
    { {  INT8_C(  97), -INT8_C(   8),  INT8_C(  54), -INT8_C(   2),  INT8_C( 118), -INT8_C(  84), -INT8_C(  39), -INT8_C( 104) },
      {  INT8_C(  87), -INT8_C( 115), -INT8_C( 108), -INT8_C(  79), -INT8_C(  56),  INT8_C(   9),  INT8_C(  74), -INT8_C( 121) },
      {      INT8_MAX, -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),      INT8_MIN,      INT8_MIN, -INT8_C(   1) } },
    { { -INT8_C(  44), -INT8_C(  67), -INT8_C(  94), -INT8_C(  35),  INT8_C(  16), -INT8_C(  87),  INT8_C( 102),  INT8_C(  67) },
      { -INT8_C(  97),  INT8_C(  84), -INT8_C(  42),  INT8_C(  19),  INT8_C(  75), -INT8_C(  43),  INT8_C(  98), -INT8_C(  84) },
      { -INT8_C(   1),      INT8_MIN, -INT8_C(   1),      INT8_MIN,      INT8_MAX, -INT8_C(   1),      INT8_MAX,  INT8_C(   0) } },

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
    { {  INT16_C( 29628), -INT16_C( 30864),  INT16_C( 27308),  INT16_C( 12874) },
      {  INT16_C( 20639),  INT16_C( 21823),  INT16_C( 19672), -INT16_C( 11585) },
      {  INT16_C(     0),       INT16_MIN,  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 10273),  INT16_C( 29916),  INT16_C( 11913), -INT16_C( 28240) },
      { -INT16_C(  7336),  INT16_C( 10644),  INT16_C(  8816),  INT16_C( 11593) },
      {       INT16_MIN,  INT16_C(     0),       INT16_MAX,       INT16_MIN } },
    { { -INT16_C( 18027),  INT16_C( 16820), -INT16_C(   476), -INT16_C( 15501) },
      { -INT16_C( 19890),  INT16_C( 10009), -INT16_C(  9986), -INT16_C(  8711) },
      {       INT16_MIN,       INT16_MAX, -INT16_C(   119), -INT16_C(   122) } },
    { { -INT16_C( 10577),  INT16_C( 14418),  INT16_C(   516),  INT16_C( 23753) },
      {  INT16_C( 24038),  INT16_C( 22149), -INT16_C( 12673),  INT16_C(  5251) },
      { -INT16_C(     1),  INT16_C(     0),       INT16_MAX,  INT16_C(     0) } },
    { {  INT16_C( 14216), -INT16_C( 21419), -INT16_C( 14026), -INT16_C( 31633) },
      { -INT16_C( 30597),  INT16_C( 31403), -INT16_C( 23200),  INT16_C(  3927) },
      {       INT16_MAX, -INT16_C(     1),       INT16_MIN,       INT16_MIN } },
    { { -INT16_C( 22149),  INT16_C( 32584),  INT16_C(  4524), -INT16_C( 27941) },
      {  INT16_C( 24687), -INT16_C(  4376),  INT16_C( 27695), -INT16_C( 18685) },
      {       INT16_MIN,  INT16_C(     0),       INT16_MAX,       INT16_MIN } },
    { {  INT16_C( 22691), -INT16_C(  9885), -INT16_C( 11743), -INT16_C( 25250) },
      {  INT16_C(  2395), -INT16_C( 17641),  INT16_C( 28334),  INT16_C( 10699) },
      {       INT16_MAX,       INT16_MIN, -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  4888), -INT16_C( 15192), -INT16_C( 31964), -INT16_C( 27818) },
      {  INT16_C( 16100),  INT16_C(  4994), -INT16_C( 31318),  INT16_C( 20170) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },

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
    { {  INT32_C(    25896997),  INT32_C(   730424697) },
      { -INT32_C(  1525151358),  INT32_C(  2021814177) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1808350064),  INT32_C(   570814048) },
      {  INT32_C(   645002428),  INT32_C(   378732784) },
      {  INT32_C(           0),  INT32_C(        8709) } },
    { { -INT32_C(  1575543255),  INT32_C(   114139267) },
      {  INT32_C(  1252779689), -INT32_C(   977130155) },
      { -INT32_C(           1),            INT32_MAX } },
    { { -INT32_C(   919565207),  INT32_C(   921384570) },
      {  INT32_C(   442260778), -INT32_C(  2043613091) },
      {            INT32_MIN,            INT32_MAX } },
    { { -INT32_C(  1842854130), -INT32_C(  1852246296) },
      {  INT32_C(   836518876), -INT32_C(   621371791) },
      { -INT32_C(           1),            INT32_MIN } },
    { { -INT32_C(  1516034518), -INT32_C(  2032431268) },
      {  INT32_C(  1235302636),  INT32_C(   919654696) },
      { -INT32_C(        1446),            INT32_MIN } },
    { {  INT32_C(    29947929), -INT32_C(   896376594) },
      {  INT32_C(   368799396),  INT32_C(   938471693) },
      {  INT32_C(           0),            INT32_MIN } },
    { {  INT32_C(  1960612376),  INT32_C(   234600481) },
      {  INT32_C(   408394992), -INT32_C(  2041698451) },
      {  INT32_C(       29916),            INT32_MAX } },

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
    { { -INT64_C( 5534515823632166357) },
      {  INT64_C(    6410193341859581) },
      { -INT64_C(  691814477954020795) } },
    { {  INT64_C( 5102739046457945545) },
      { -INT64_C( 6693238038093945276) },
      {                     INT64_MAX } },
    { {  INT64_C( 3245771726970928426) },
      { -INT64_C( 5720215945320980077) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 1749953926247301602) },
      { -INT64_C( 7901941129509171141) },
      {                     INT64_MAX } },
    { {  INT64_C( 5820329387604210023) },
      { -INT64_C(  311159484281167081) },
      {                     INT64_MAX } },
    { {  INT64_C( 4951222946988225483) },
      {  INT64_C( 6256148522353509592) },
      {  INT64_C(             4503111) } },
    { { -INT64_C( 3905549197655491394) },
      {  INT64_C( 1020757196977715478) },
      {                     INT64_MIN } },
    { {  INT64_C( 5167426952770693225) },
      { -INT64_C( 4977223076060615000) },
      {  INT64_C(                   0) } },

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
    { { UINT8_C( 68), UINT8_C(  7), UINT8_C( 75), UINT8_C(171), UINT8_C(219), UINT8_C(139),    UINT8_MAX, UINT8_C(199) },
      { -INT8_C(  65),  INT8_C(  87),  INT8_C(   2),  INT8_C(  59),  INT8_C(  23), -INT8_C(  88), -INT8_C(  64), -INT8_C(  49) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(186), UINT8_C( 34), UINT8_C(133), UINT8_C(217), UINT8_C( 20), UINT8_C( 42), UINT8_C(120), UINT8_C(144) },
      { -INT8_C(  51),  INT8_C( 120), -INT8_C(  98),  INT8_C(  53), -INT8_C(  54),  INT8_C(  19), -INT8_C(  73),  INT8_C(  15) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 26), UINT8_C(  2), UINT8_C(186), UINT8_C(245), UINT8_C(141), UINT8_C(185), UINT8_C(189), UINT8_C( 76) },
      {  INT8_C(  17), -INT8_C(  65), -INT8_C( 121),  INT8_C(  40),  INT8_C( 103),  INT8_C(  71), -INT8_C(   8),  INT8_C(  33) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(106), UINT8_C(125), UINT8_C(251), UINT8_C(126), UINT8_C(167), UINT8_C(115), UINT8_C( 15), UINT8_C(116) },
      { -INT8_C(  20), -INT8_C(  83), -INT8_C(  87), -INT8_C(  74), -INT8_C(  64),  INT8_C(  96), -INT8_C(  59), -INT8_C(  37) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 98), UINT8_C(127), UINT8_C(208), UINT8_C(239), UINT8_C( 57), UINT8_C(141), UINT8_C( 59), UINT8_C( 74) },
      {  INT8_C(  76), -INT8_C(  62),  INT8_C( 114), -INT8_C(  76),  INT8_C(  10),  INT8_C( 106), -INT8_C(  43),  INT8_C( 116) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(231), UINT8_C(208), UINT8_C(242), UINT8_C(142), UINT8_C( 68), UINT8_C(  1), UINT8_C(  2), UINT8_C( 48) },
      { -INT8_C(  82), -INT8_C(  85), -INT8_C(  26),  INT8_C( 111),  INT8_C(  11), -INT8_C(  84),  INT8_C(  74),  INT8_C( 109) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 43), UINT8_C( 26), UINT8_C( 92), UINT8_C(100), UINT8_C(168), UINT8_C(151), UINT8_C(174), UINT8_C(244) },
      {  INT8_C(  90),  INT8_C(  33), -INT8_C(  88),  INT8_C( 100), -INT8_C( 117),  INT8_C( 126), -INT8_C(  40),  INT8_C( 115) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 78), UINT8_C(202), UINT8_C(  1), UINT8_C(146), UINT8_C(204), UINT8_C(  4), UINT8_C(194), UINT8_C(122) },
      { -INT8_C(  81), -INT8_C(  87), -INT8_C(  23), -INT8_C(  69),  INT8_C(  85),  INT8_C(  51),  INT8_C(  40),      INT8_MIN },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },

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
    { { UINT16_C(34645), UINT16_C(12817), UINT16_C(54051), UINT16_C(19652) },
      { -INT16_C( 10294),  INT16_C( 24097),  INT16_C( 16743), -INT16_C( 26091) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1812), UINT16_C(41212), UINT16_C( 7072), UINT16_C(10597) },
      { -INT16_C( 31347),  INT16_C( 15716),  INT16_C( 14230), -INT16_C(  5075) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(16062), UINT16_C(57630), UINT16_C(58130), UINT16_C(56366) },
      {  INT16_C( 20410),  INT16_C(  8762),  INT16_C( 20368), -INT16_C( 23364) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(47191), UINT16_C(63300), UINT16_C(43476), UINT16_C(24865) },
      { -INT16_C( 31442), -INT16_C( 14946), -INT16_C( 13379),  INT16_C( 31665) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(53002), UINT16_C( 7261), UINT16_C(35762), UINT16_C(28152) },
      {  INT16_C( 13274),  INT16_C( 27535),  INT16_C( 19330), -INT16_C(  9969) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(21508), UINT16_C(55505), UINT16_C(62205), UINT16_C(11321) },
      { -INT16_C( 10377),  INT16_C( 13553), -INT16_C( 23901), -INT16_C( 21072) },
      {      UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 3441), UINT16_C( 9417), UINT16_C(49560), UINT16_C(29329) },
      {  INT16_C(  8436),  INT16_C( 30685), -INT16_C(  4757),  INT16_C( 28496) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 8513), UINT16_C(15943), UINT16_C(32787), UINT16_C(35690) },
      {  INT16_C( 23384), -INT16_C(  1089),  INT16_C( 28669),  INT16_C( 28584) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C( 4098), UINT16_C(    0) } },

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
    { { UINT32_C(3353597833), UINT32_C(3629921071) },
      {  INT32_C(    89682258), -INT32_C(   508617958) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1330460603), UINT32_C(2172680244) },
      {  INT32_C(   356970575), -INT32_C(   718851508) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 966593034), UINT32_C(2417162558) },
      { -INT32_C(  2070582678),  INT32_C(  1097221510) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2962273148), UINT32_C(2050101291) },
      {  INT32_C(  1301248001), -INT32_C(  1256016213) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(4293836737), UINT32_C( 596574393) },
      { -INT32_C(   240638869), -INT32_C(   449704343) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3969303233), UINT32_C(3546728658) },
      { -INT32_C(   350161600),  INT32_C(  1822442411) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3144388354), UINT32_C(4208982671) },
      { -INT32_C(  1997830369),  INT32_C(  1450057109) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2990671071), UINT32_C( 210086092) },
      {  INT32_C(  1224255133), -INT32_C(   340420375) },
      { UINT32_C(         0), UINT32_C(        25) } },

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
    { { UINT64_C(15523027699347871150) },
      {  INT64_C( 5409432945647958787) },
      {                    UINT64_MAX } },
    { { UINT64_C(13343628011615303163) },
      { -INT64_C( 7773715541337081503) },
      {                    UINT64_MAX } },
    { { UINT64_C( 3338489119348509451) },
      {  INT64_C( 2221340195661806061) },
      { UINT64_C(       6367662657448) } },
    { { UINT64_C(10642547098118921214) },
      { -INT64_C( 6998699840934683291) },
      {                    UINT64_MAX } },
    { { UINT64_C(14214047447287277034) },
      { -INT64_C( 4563517777460201111) },
      {                    UINT64_MAX } },
    { { UINT64_C(13475168475214801211) },
      {  INT64_C(  862692359560135367) },
      { UINT64_C(                  93) } },
    { { UINT64_C(17053269782605796107) },
      {  INT64_C( 5899192239321118299) },
      {                    UINT64_MAX } },
    { { UINT64_C(14455921493260867469) },
      { -INT64_C( 7679171132949093310) },
      {                    UINT64_MAX } },

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
    { {  INT8_C( 116),  INT8_C(  67),  INT8_C(  92),  INT8_C( 118), -INT8_C(  50), -INT8_C(  61),  INT8_C(  82),  INT8_C(  72),
         INT8_C( 120),  INT8_C( 101),  INT8_C( 109), -INT8_C(  21), -INT8_C(   8), -INT8_C(  93), -INT8_C(  13),  INT8_C(  57) },
      {  INT8_C(   2), -INT8_C(  32), -INT8_C( 122), -INT8_C(  17), -INT8_C(  73),  INT8_C(  85), -INT8_C(  56), -INT8_C( 102),
         INT8_C(  85),  INT8_C(   4),  INT8_C(  10), -INT8_C(  66), -INT8_C(  66),  INT8_C(  18), -INT8_C(  37),  INT8_C(  50) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),
             INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MIN, -INT8_C(   1),      INT8_MAX } },
    { {  INT8_C(  86),  INT8_C(  56), -INT8_C(  88),  INT8_C(  36), -INT8_C(   5), -INT8_C(   5),  INT8_C( 108),  INT8_C( 115),
         INT8_C(  96), -INT8_C(  39),  INT8_C(  94),  INT8_C(  88),  INT8_C( 124),  INT8_C(  81), -INT8_C( 111),      INT8_MAX },
      {  INT8_C(  50),  INT8_C(  23),  INT8_C( 110), -INT8_C(  23),  INT8_C( 109),  INT8_C(  54), -INT8_C( 124), -INT8_C(  62),
         INT8_C(  58), -INT8_C( 114),      INT8_MIN, -INT8_C(   8), -INT8_C(  96),  INT8_C(  92),  INT8_C(  42), -INT8_C(  10) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),
             INT8_MAX, -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,      INT8_MIN,  INT8_C(   0) } },
    { { -INT8_C( 108), -INT8_C(  45),  INT8_C(  26), -INT8_C( 113), -INT8_C(  50), -INT8_C( 121),  INT8_C(   2),  INT8_C(  46),
         INT8_C(  96),  INT8_C(  96), -INT8_C( 122), -INT8_C(  35), -INT8_C(  78),  INT8_C(  24),  INT8_C(  92), -INT8_C(  28) },
      {  INT8_C(  47), -INT8_C(  54), -INT8_C(  51), -INT8_C( 100),  INT8_C(   0),  INT8_C(  81),  INT8_C(  94),  INT8_C(  58),
        -INT8_C(  33), -INT8_C(  33),  INT8_C(  50),      INT8_MIN,  INT8_C(  59),  INT8_C(  92),  INT8_C( 118), -INT8_C(  49) },
      {      INT8_MIN, -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(  50),      INT8_MIN,      INT8_MAX,      INT8_MAX,
         INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(   1),      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(   1) } },
    { {  INT8_C(  47), -INT8_C( 111),  INT8_C(  94), -INT8_C(   3),  INT8_C(  24),  INT8_C(  96),  INT8_C(  43),  INT8_C( 120),
        -INT8_C(  64), -INT8_C(  78),  INT8_C(  85),  INT8_C( 114), -INT8_C(  54), -INT8_C(  79),  INT8_C(  86), -INT8_C(   7) },
      {  INT8_C( 123),  INT8_C(  36), -INT8_C( 106),  INT8_C( 123),  INT8_C( 117), -INT8_C(  12), -INT8_C(  75),  INT8_C(  85),
        -INT8_C(  45), -INT8_C(  25), -INT8_C(  43),  INT8_C(  14),  INT8_C(  68),  INT8_C(  75), -INT8_C(  35),  INT8_C( 115) },
      {      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   0),      INT8_MAX,
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),      INT8_MAX,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN } },
    { { -INT8_C(  36),  INT8_C(  59),  INT8_C( 113), -INT8_C(  12), -INT8_C( 101), -INT8_C( 100),  INT8_C( 109),  INT8_C(  92),
         INT8_C(  78), -INT8_C(  62), -INT8_C(  50),  INT8_C(  24),  INT8_C( 116),  INT8_C(  37),  INT8_C(  18), -INT8_C(  17) },
      {  INT8_C(  73), -INT8_C(  88),  INT8_C( 107), -INT8_C(  66), -INT8_C( 100),  INT8_C(  32),  INT8_C(  19),  INT8_C( 112),
         INT8_C(   8), -INT8_C(  24),  INT8_C( 126),  INT8_C(  76),  INT8_C(  52),  INT8_C(  92), -INT8_C(  65),  INT8_C(  16) },
      {      INT8_MIN,  INT8_C(   0),      INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MIN,      INT8_MAX,      INT8_MAX,
             INT8_MAX, -INT8_C(   1),      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(   0),      INT8_MIN } },
    { { -INT8_C( 105),  INT8_C(  48),  INT8_C(   5),  INT8_C(  51), -INT8_C(  51),  INT8_C( 114), -INT8_C( 113),  INT8_C(  27),
         INT8_C(  52),  INT8_C(  93),  INT8_C(  52), -INT8_C(  88), -INT8_C( 126),  INT8_C(  70), -INT8_C( 104), -INT8_C(  53) },
      { -INT8_C(  18),  INT8_C(   3), -INT8_C( 118), -INT8_C( 118),  INT8_C(  35), -INT8_C(  99), -INT8_C(   6),  INT8_C(  43),
        -INT8_C( 122),  INT8_C( 121),  INT8_C( 119), -INT8_C(  70), -INT8_C(  43),  INT8_C(  55), -INT8_C(  54),  INT8_C( 108) },
      { -INT8_C(   1),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0), -INT8_C(   2),      INT8_MAX,
         INT8_C(   0),      INT8_MAX,      INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MAX, -INT8_C(   1),      INT8_MIN } },
    { {  INT8_C( 103), -INT8_C(  49), -INT8_C(  97),  INT8_C(  52),  INT8_C(  65),  INT8_C(  46),  INT8_C(  80),  INT8_C( 118),
        -INT8_C( 116), -INT8_C( 124),  INT8_C(  30),  INT8_C(  14), -INT8_C(  54), -INT8_C(  74), -INT8_C(  38), -INT8_C(  72) },
      { -INT8_C(  71),  INT8_C( 100),  INT8_C(  66), -INT8_C(  35),  INT8_C(   1),  INT8_C(  61),  INT8_C(   8), -INT8_C( 121),
        -INT8_C(  74),      INT8_MIN,  INT8_C(  65), -INT8_C( 117), -INT8_C(  73),  INT8_C(  12), -INT8_C(   9),  INT8_C(  30) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),      INT8_MAX,  INT8_C(   0), -INT8_C(   1),      INT8_MIN, -INT8_C(   1),      INT8_MIN } },
    { { -INT8_C(  37), -INT8_C( 105),  INT8_C(  83),  INT8_C(  29), -INT8_C(  59), -INT8_C(  93), -INT8_C( 109),  INT8_C(  81),
         INT8_C(  39), -INT8_C(  79),  INT8_C(  96), -INT8_C(  15),  INT8_C( 104),  INT8_C(  58), -INT8_C(  87),  INT8_C(  33) },
      { -INT8_C(  98), -INT8_C(  21), -INT8_C(   2), -INT8_C(  97),  INT8_C(  40),  INT8_C(   7),  INT8_C(  39), -INT8_C(  34),
        -INT8_C( 121),  INT8_C( 104),  INT8_C( 105),  INT8_C(  62),  INT8_C( 116),  INT8_C(  97),  INT8_C(  92),  INT8_C(  80) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(  20),  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),
         INT8_C(   0),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX } },

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
    { { -INT16_C( 22125),  INT16_C( 23758),  INT16_C( 23600),  INT16_C( 14125),  INT16_C(  3218),  INT16_C( 29467), -INT16_C( 26547), -INT16_C( 32285) },
      {  INT16_C( 26762), -INT16_C( 18866),  INT16_C(  2010),  INT16_C(  3609), -INT16_C(  5123),  INT16_C( 13178), -INT16_C(  1435), -INT16_C(  1890) },
      { -INT16_C(     1),       INT16_MAX,  INT16_C(     0),       INT16_MAX,  INT16_C(   402),       INT16_MAX,       INT16_MIN, -INT16_C(     1) } },
    { {  INT16_C( 27811), -INT16_C( 11435), -INT16_C( 32056),  INT16_C( 23051),  INT16_C(  9871), -INT16_C(  9011), -INT16_C( 20289),  INT16_C( 18782) },
      { -INT16_C( 21480), -INT16_C(  3073),  INT16_C(  6324), -INT16_C( 20223),  INT16_C( 31491),  INT16_C( 27108), -INT16_C( 32139),  INT16_C(  6497) },
      {       INT16_MAX, -INT16_C(  5718), -INT16_C(     1),       INT16_MAX,       INT16_MAX, -INT16_C(     1),       INT16_MIN,       INT16_MAX } },
    { { -INT16_C( 18706), -INT16_C( 18708), -INT16_C(  2247), -INT16_C( 14320), -INT16_C(  8930), -INT16_C(  8796),  INT16_C(   653), -INT16_C( 23258) },
      {  INT16_C(  9647),  INT16_C( 25496), -INT16_C( 26307),  INT16_C( 16660), -INT16_C(  2027), -INT16_C( 30038),  INT16_C(  2938),  INT16_C( 26787) },
      { -INT16_C(     1), -INT16_C(     1),       INT16_MIN,       INT16_MIN,       INT16_MIN, -INT16_C(     1),       INT16_MAX, -INT16_C(     1) } },
    { { -INT16_C( 28478), -INT16_C(  1250),  INT16_C( 11911), -INT16_C( 23101),  INT16_C( 26379), -INT16_C( 26494), -INT16_C( 22422),  INT16_C(  6461) },
      { -INT16_C( 10547),  INT16_C(  2940), -INT16_C( 28561), -INT16_C( 31668), -INT16_C(  2424),  INT16_C(   527), -INT16_C( 19967), -INT16_C( 15510) },
      { -INT16_C(     1),       INT16_MIN,       INT16_MAX,       INT16_MIN,  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MAX } },
    { { -INT16_C( 30654), -INT16_C( 13634), -INT16_C( 32330), -INT16_C( 16017), -INT16_C(  3351),  INT16_C( 21337), -INT16_C( 26982),  INT16_C( 26732) },
      { -INT16_C(  6036), -INT16_C(  9101), -INT16_C( 16520),  INT16_C(    96),  INT16_C( 28597), -INT16_C( 18942),  INT16_C( 27682),  INT16_C( 25722) },
      {       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN, -INT16_C(     1),       INT16_MAX,       INT16_MIN,       INT16_MAX } },
    { {  INT16_C( 14580), -INT16_C( 21970), -INT16_C( 24902), -INT16_C( 23701), -INT16_C( 15216),  INT16_C( 10998),  INT16_C( 25178), -INT16_C( 14446) },
      {  INT16_C(  1354), -INT16_C( 15709),  INT16_C(   964),  INT16_C( 31170), -INT16_C( 15245), -INT16_C( 27344), -INT16_C( 21968),  INT16_C(  9465) },
      {       INT16_MAX, -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),       INT16_MIN,       INT16_MAX,       INT16_MAX, -INT16_C(   113) } },
    { {  INT16_C( 10466), -INT16_C( 25394),  INT16_C( 14790),  INT16_C( 22079),  INT16_C( 13821),  INT16_C( 22400),  INT16_C(  5015), -INT16_C(  7906) },
      { -INT16_C( 16104), -INT16_C(  8797),  INT16_C( 26053),  INT16_C( 14422), -INT16_C( 31191),  INT16_C( 22989), -INT16_C( 14800),  INT16_C(  4989) },
      {       INT16_MAX, -INT16_C(     1),  INT16_C(     0),       INT16_MAX,       INT16_MAX,  INT16_C(     0),       INT16_MAX,       INT16_MIN } },
    { {  INT16_C( 19438), -INT16_C( 19281), -INT16_C(  4220), -INT16_C( 32502), -INT16_C( 29916), -INT16_C( 17191), -INT16_C(  2146), -INT16_C( 18787) },
      {  INT16_C( 16825),  INT16_C( 32403), -INT16_C(  5466), -INT16_C( 12106), -INT16_C( 31888), -INT16_C( 24279), -INT16_C( 22711),  INT16_C( 14516) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),       INT16_MIN,       INT16_MIN,       INT16_MIN, -INT16_C(     1) } },

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
    { {  INT32_C(  1548896495), -INT32_C(  2074449818),  INT32_C(  1114140613),  INT32_C(  1953151475) },
      {  INT32_C(  2002933178), -INT32_C(  2130620066), -INT32_C(  1589685393), -INT32_C(  1494921033) },
      {  INT32_C(           0),            INT32_MIN,            INT32_MAX,  INT32_C(           0) } },
    { { -INT32_C(    33409128),  INT32_C(  1686264991), -INT32_C(  1096291381),  INT32_C(  1597116836) },
      { -INT32_C(   992570010),  INT32_C(  1430640614), -INT32_C(   503872214),  INT32_C(  1837620437) },
      {            INT32_MIN,  INT32_C(          25),            INT32_MIN,  INT32_C(           0) } },
    { { -INT32_C(  1284732652), -INT32_C(  1340543259),  INT32_C(  2121252825),  INT32_C(   920494544) },
      {  INT32_C(   502969142), -INT32_C(  1250803574), -INT32_C(  1701418555),  INT32_C(  1510415942) },
      {            INT32_MIN, -INT32_C(           1),  INT32_C(           0),            INT32_MAX } },
    { { -INT32_C(  1928498265),  INT32_C(   993863010), -INT32_C(  1262899996), -INT32_C(  2065000882) },
      { -INT32_C(   727587511), -INT32_C(   360115163), -INT32_C(  1014751363), -INT32_C(   451048643) },
      {            INT32_MIN,            INT32_MAX,            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(  1634872319),  INT32_C(   899460944), -INT32_C(  1427548580),  INT32_C(   909038828) },
      { -INT32_C(   569716551),  INT32_C(  1640535012), -INT32_C(   265990990), -INT32_C(   690666793) },
      {  INT32_C(           0),  INT32_C(           3), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(  1103673491),  INT32_C(  1391711478),  INT32_C(   385670186),  INT32_C(  1766599600) },
      { -INT32_C(   548972805), -INT32_C(  1673523223),  INT32_C(   864839003),  INT32_C(   352936360) },
      { -INT32_C(    34489797),  INT32_C(         165),            INT32_MAX,  INT32_C(           0) } },
    { { -INT32_C(  1630322264),  INT32_C(  1072809493),  INT32_C(  1398140323),  INT32_C(   331194904) },
      { -INT32_C(   487455496),  INT32_C(  1870541588),  INT32_C(  1084361368),  INT32_C(   324447339) },
      { -INT32_C(     6368447),            INT32_MAX,  INT32_C(           0),            INT32_MAX } },
    { {  INT32_C(    45165037), -INT32_C(  1824414992), -INT32_C(  1461283184),  INT32_C(   834446136) },
      { -INT32_C(  1139560792),  INT32_C(  2049675745),  INT32_C(   112905883),  INT32_C(  1729695866) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),            INT32_MAX } },

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
    { {  INT64_C( 6942469271379624409), -INT64_C( 7723113162142897726) },
      { -INT64_C( 4007394308462114140),  INT64_C( 1029452075532083908) },
      {  INT64_C(                   0), -INT64_C(                   7) } },
    { {  INT64_C( 5512518683035889178),  INT64_C( 8620611868605470095) },
      {  INT64_C( 8718303348530402330), -INT64_C( 3258604229957034364) },
      {                     INT64_MAX,  INT64_C(                   0) } },
    { { -INT64_C( 3683818890666519030),  INT64_C( 5229098279326359111) },
      { -INT64_C(  613198240308932271),  INT64_C( 8674627144731611609) },
      {                     INT64_MIN,  INT64_C(             9511674) } },
    { {  INT64_C( 1033273506286818381), -INT64_C(  143629557312245622) },
      { -INT64_C( 3173768922402685046),  INT64_C( 7617775119345362130) },
      {  INT64_C(                   0), -INT64_C(                2042) } },
    { {  INT64_C( 4246975468369330970),  INT64_C( 6640263884054927482) },
      {  INT64_C( 8953242553098578291), -INT64_C( 8901237764130036493) },
      {                     INT64_MAX,  INT64_C(     810579087409048) } },
    { {  INT64_C( 3395809458291895351),  INT64_C( 8907413112401367918) },
      {  INT64_C( 4092973014053418918),  INT64_C( 3800124379380550093) },
      {  INT64_C(                   0),  INT64_C(                3955) } },
    { { -INT64_C( 1868646980023344596), -INT64_C( 8371412268056352690) },
      { -INT64_C( 5604260365042140229),  INT64_C( 7810549348884381747) },
      { -INT64_C(                   1),                     INT64_MIN } },
    { {  INT64_C(  587262054949093319), -INT64_C( 3731459814277034553) },
      { -INT64_C( 1044265846491573012), -INT64_C( 2795743532770235258) },
      {  INT64_C(        560056738804), -INT64_C(                   1) } },

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
    { { UINT8_C(143), UINT8_C(128), UINT8_C(135), UINT8_C(101), UINT8_C(125), UINT8_C(137), UINT8_C(187), UINT8_C(136),
        UINT8_C(133), UINT8_C( 37), UINT8_C(123), UINT8_C(128), UINT8_C(122), UINT8_C( 38), UINT8_C(157), UINT8_C(157) },
      { -INT8_C(  81), -INT8_C(  35), -INT8_C(  69), -INT8_C(  96),  INT8_C(   6),  INT8_C( 113), -INT8_C(  11),  INT8_C(  70),
        -INT8_C( 118), -INT8_C(  46),  INT8_C(  44),  INT8_C(  27),  INT8_C(  85),  INT8_C(  80), -INT8_C(  12), -INT8_C(  28) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(208), UINT8_C(123), UINT8_C( 74), UINT8_C( 77), UINT8_C(  4), UINT8_C(  5), UINT8_C(213), UINT8_C(137),
        UINT8_C( 43), UINT8_C( 80), UINT8_C( 10), UINT8_C(165), UINT8_C(118), UINT8_C(167), UINT8_C( 66), UINT8_C( 37) },
      { -INT8_C( 124), -INT8_C(   3), -INT8_C(  59), -INT8_C( 117),  INT8_C( 110), -INT8_C(  70), -INT8_C(  47), -INT8_C(   8),
        -INT8_C( 115), -INT8_C(   2),  INT8_C(  19), -INT8_C(  30),  INT8_C(  78),  INT8_C(   7), -INT8_C(  57),  INT8_C(  30) },
      { UINT8_C(  0), UINT8_C( 15), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C( 20),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(130), UINT8_C( 17), UINT8_C(107), UINT8_C(135), UINT8_C( 22), UINT8_C( 64), UINT8_C( 16), UINT8_C( 65),
        UINT8_C(145), UINT8_C( 26), UINT8_C(230), UINT8_C(  7), UINT8_C(193), UINT8_C( 40), UINT8_C( 45), UINT8_C( 70) },
      {  INT8_C(  37), -INT8_C(  14), -INT8_C(  47), -INT8_C( 109), -INT8_C(  83), -INT8_C(  94), -INT8_C( 117),  INT8_C(  58),
        -INT8_C(  96), -INT8_C(  98),  INT8_C(  28), -INT8_C(  18), -INT8_C(  91), -INT8_C(  29),  INT8_C(  12),  INT8_C(  40) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(244), UINT8_C(119), UINT8_C(175), UINT8_C( 11), UINT8_C(184), UINT8_C(191), UINT8_C( 76), UINT8_C( 73),
        UINT8_C(218), UINT8_C( 51), UINT8_C( 80), UINT8_C(155), UINT8_C( 91), UINT8_C(125), UINT8_C(225), UINT8_C(129) },
      {  INT8_C( 112), -INT8_C(  78),  INT8_C(  20),  INT8_C(  29),  INT8_C(  85), -INT8_C(  96),  INT8_C(  87), -INT8_C(  11),
         INT8_C(  62),  INT8_C( 115), -INT8_C(  28), -INT8_C(  28),  INT8_C(  87), -INT8_C(  16),  INT8_C(  12),  INT8_C(  75) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(104), UINT8_C(187), UINT8_C( 86), UINT8_C( 32), UINT8_C(122), UINT8_C(163), UINT8_C(105), UINT8_C( 84),
        UINT8_C(214), UINT8_C(185), UINT8_C(240), UINT8_C( 49), UINT8_C( 55), UINT8_C(209), UINT8_C(178), UINT8_C(167) },
      { -INT8_C( 124), -INT8_C(  57), -INT8_C(  60), -INT8_C(  39),  INT8_C( 103),  INT8_C(  27), -INT8_C(  50), -INT8_C(  91),
        -INT8_C( 114), -INT8_C(  78), -INT8_C( 119), -INT8_C(  27), -INT8_C(  93), -INT8_C( 107),  INT8_C(  49),  INT8_C(  11) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 80), UINT8_C(135), UINT8_C( 43), UINT8_C(203), UINT8_C( 42), UINT8_C(148), UINT8_C( 31), UINT8_C(  0),
        UINT8_C( 77), UINT8_C( 15), UINT8_C( 50), UINT8_C(132), UINT8_C(225), UINT8_C(228), UINT8_C( 43), UINT8_C(101) },
      { -INT8_C(  85), -INT8_C(  17),  INT8_C(  62),  INT8_C(  18),  INT8_C(  10),  INT8_C(  12), -INT8_C(  72), -INT8_C( 103),
        -INT8_C(  65),  INT8_C(  65),  INT8_C( 126),  INT8_C(  98), -INT8_C(  41), -INT8_C(  81),  INT8_C( 109),  INT8_C(  39) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 55), UINT8_C(152), UINT8_C(242), UINT8_C( 97), UINT8_C( 44), UINT8_C( 18), UINT8_C( 98), UINT8_C(121),
        UINT8_C( 33), UINT8_C(148), UINT8_C(254), UINT8_C(  2), UINT8_C(120), UINT8_C( 41), UINT8_C(103), UINT8_C( 36) },
      {  INT8_C(  25), -INT8_C(  91),  INT8_C(  54),  INT8_C(  35), -INT8_C(  78), -INT8_C(  18), -INT8_C(  68),  INT8_C( 113),
         INT8_C(  48),  INT8_C(  59), -INT8_C(  45),  INT8_C(   7), -INT8_C(  22),  INT8_C(  64),  INT8_C(  46),  INT8_C(  33) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(216), UINT8_C( 33), UINT8_C(131), UINT8_C(  4), UINT8_C( 51), UINT8_C(229), UINT8_C(125), UINT8_C( 84),
        UINT8_C(121), UINT8_C(123), UINT8_C( 87), UINT8_C(241), UINT8_C(165), UINT8_C(190), UINT8_C( 21), UINT8_C(190) },
      {  INT8_C( 100),  INT8_C(  76), -INT8_C(  31),  INT8_C(  22),  INT8_C(  58), -INT8_C(  98), -INT8_C( 121),  INT8_C( 106),
        -INT8_C(  39),  INT8_C(  90),  INT8_C( 113), -INT8_C(  61), -INT8_C( 102), -INT8_C(  96), -INT8_C(  27),  INT8_C( 114) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },

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
    { { UINT16_C(35007), UINT16_C( 6507), UINT16_C(57369), UINT16_C(25912), UINT16_C(57354), UINT16_C( 1276), UINT16_C(48278), UINT16_C(51829) },
      {  INT16_C( 30786),  INT16_C( 20682), -INT16_C(   499),  INT16_C( 28190),  INT16_C( 11232),  INT16_C(  9453),  INT16_C(  9598),  INT16_C( 15799) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 8877), UINT16_C(51030), UINT16_C(36610), UINT16_C( 3116), UINT16_C(10351), UINT16_C( 1297), UINT16_C(34533), UINT16_C(10191) },
      { -INT16_C( 26114),  INT16_C(  3191), -INT16_C( 26985),  INT16_C( 30586),  INT16_C( 26561),  INT16_C( 16540),  INT16_C( 21388),  INT16_C( 14717) },
      { UINT16_C( 2219),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(54389), UINT16_C(30464), UINT16_C(11363), UINT16_C(53892), UINT16_C(38229), UINT16_C(15063), UINT16_C(42523), UINT16_C( 6753) },
      { -INT16_C(  9921), -INT16_C( 10714), -INT16_C( 24465),  INT16_C( 12366), -INT16_C(  5625), -INT16_C( 27792), -INT16_C(  4547), -INT16_C( 19764) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(52674), UINT16_C( 9513), UINT16_C(44537), UINT16_C(20215), UINT16_C(52802), UINT16_C(24200), UINT16_C(60020), UINT16_C(45944) },
      { -INT16_C( 24893),  INT16_C( 12937), -INT16_C( 10434),  INT16_C( 17762), -INT16_C( 11327), -INT16_C(   296), -INT16_C( 23359), -INT16_C( 31824) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(55921), UINT16_C(27560), UINT16_C(40839), UINT16_C(51897), UINT16_C(17005), UINT16_C(57640), UINT16_C(41004), UINT16_C(61332) },
      {  INT16_C(  7486),  INT16_C( 31777), -INT16_C( 31755), -INT16_C( 18751), -INT16_C( 26282),  INT16_C(  6069),  INT16_C( 25917), -INT16_C( 20582) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(   19), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(16959), UINT16_C(50970), UINT16_C(54241), UINT16_C(20113), UINT16_C(47381), UINT16_C(16687), UINT16_C(50009), UINT16_C(38704) },
      {  INT16_C( 20961), -INT16_C( 10733), -INT16_C( 11051),  INT16_C( 11148),  INT16_C( 16749), -INT16_C( 21949), -INT16_C(  8793), -INT16_C(  6567) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(29472), UINT16_C(  429), UINT16_C(15943), UINT16_C(23632), UINT16_C(32759), UINT16_C(20638), UINT16_C(52803), UINT16_C( 9447) },
      { -INT16_C(  1504), -INT16_C(  2566), -INT16_C( 31026),  INT16_C( 15136),  INT16_C( 25544),  INT16_C( 28646),  INT16_C( 16193),  INT16_C( 24917) },
      {      UINT16_MAX, UINT16_C(    6), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(  947), UINT16_C(64098), UINT16_C(45633), UINT16_C(14678), UINT16_C(62514), UINT16_C(30089), UINT16_C(29123), UINT16_C(58265) },
      { -INT16_C( 27797),  INT16_C( 15064), -INT16_C(  2023), -INT16_C(  7819),  INT16_C( 23388), -INT16_C( 25264), -INT16_C( 22885),  INT16_C( 20222) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(14566) } },

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
    { { UINT32_C(3368499890), UINT32_C(3904864458), UINT32_C(3533680851), UINT32_C(2231366303) },
      {  INT32_C(  1876485103), -INT32_C(  1250778945), -INT32_C(  1708061353),  INT32_C(   255663709) },
      { UINT32_C(     25699), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 601293913), UINT32_C(1477154437), UINT32_C(3844844102), UINT32_C(2355702429) },
      { -INT32_C(   855949043),  INT32_C(   964849121), -INT32_C(   673991814),  INT32_C(   736497874) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2588851733), UINT32_C(2616351060), UINT32_C(2692750595), UINT32_C(1429072455) },
      {  INT32_C(   220276779),  INT32_C(   273064854),  INT32_C(   703076695),  INT32_C(  1045745193) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3789070988), UINT32_C(4269591547), UINT32_C( 815791336), UINT32_C( 310758630) },
      { -INT32_C(  1977637132), -INT32_C(  1583651510), -INT32_C(  1479900290), -INT32_C(   555344303) },
      { UINT32_C(    925066),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3149905600), UINT32_C(1924742025), UINT32_C( 513955895), UINT32_C( 422586148) },
      {  INT32_C(   396578765),  INT32_C(   850935476),  INT32_C(   333021889),  INT32_C(  1626455968) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 119255166), UINT32_C( 578409963), UINT32_C(1379932973), UINT32_C( 275476546) },
      {  INT32_C(  1931939519),  INT32_C(   245751885),  INT32_C(    52526946), -INT32_C(  1134357954) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2915336130), UINT32_C(2177908052), UINT32_C(2614300761), UINT32_C(1084964481) },
      { -INT32_C(  1699425459),  INT32_C(   363354547),  INT32_C(   387500760), -INT32_C(  1613529892) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1330419707), UINT32_C( 785390805), UINT32_C(2932450349), UINT32_C( 804156898) },
      { -INT32_C(    70671800), -INT32_C(   737119492),  INT32_C(   418064700), -INT32_C(  1598570587) },
      {           UINT32_MAX, UINT32_C(  49086925),           UINT32_MAX, UINT32_C(         0) } },

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
    { { UINT64_C(15419489519727496451), UINT64_C( 4022890969710678935) },
      {  INT64_C( 4871272435518416524), -INT64_C( 5189200425544602375) },
      { UINT64_C(                   0), UINT64_C(   31428835700864679) } },
    { { UINT64_C(15161762026598511503), UINT64_C(16066163216512001209) },
      {  INT64_C( 7375502477450359200),  INT64_C( 5126014160735663800) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(12430855209924398197), UINT64_C( 4871032927324678504) },
      { -INT64_C( 3573969048660407661),  INT64_C( 7146191084576221997) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(12937319231662589930), UINT64_C(16908208823409178048) },
      { -INT64_C( 1876223442879381231),  INT64_C( 8740632070487421180) },
      {                    UINT64_MAX, UINT64_C( 1056763051463073628) } },
    { { UINT64_C(13329494879103246589), UINT64_C( 9230341219049826518) },
      {  INT64_C( 5720025983636406980),  INT64_C( 2221828369504807886) },
      { UINT64_C(                  11), UINT64_C(                8198) } },
    { { UINT64_C(16327344206960274661), UINT64_C( 4087061141460660937) },
      { -INT64_C( 3761607410281324502),  INT64_C( 8034419031029581120) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 1159926794746193193), UINT64_C( 8881662858392774805) },
      {  INT64_C( 5488415752828024417),  INT64_C( 8773906317794235082) },
      {                    UINT64_MAX, UINT64_C(                 493) } },
    { { UINT64_C( 9829607509708443667), UINT64_C( 1494021567751041776) },
      {  INT64_C( 4837882471828862154),  INT64_C( 1276589067401155054) },
      { UINT64_C(                 545), UINT64_C(       5699239989284) } },

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
    simde_uint64x2_t r = simde_vqshlq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
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
