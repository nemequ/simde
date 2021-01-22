#define SIMDE_TEST_ARM_NEON_INSN add

#include "test-neon.h"
#include "../../../simde/arm/neon/add.h"

static int
test_simde_vaddd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    { -INT64_C( 5376176558586261779),
      -INT64_C( 8975014256303024679),
       INT64_C( 4095553258820265158) },
    {  INT64_C( 4193233660194686354),
       INT64_C( 8392010986138408549),
      -INT64_C( 5861499427376456713) },
    { -INT64_C(  498686658264423049),
      -INT64_C(  235223563850804956),
      -INT64_C(  733910222115228005) },
    { -INT64_C( 7287872900825752874),
      -INT64_C( 5631607047233613604),
       INT64_C( 5527264125650185138) },
    {  INT64_C( 4017813484947424424),
      -INT64_C( 3919207051327069898),
       INT64_C(   98606433620354526) },
    { -INT64_C( 3110218261649903353),
       INT64_C( 1009950248106779417),
      -INT64_C( 2100268013543123936) },
    {  INT64_C( 8007005661493138900),
      -INT64_C( 4253741394523353286),
       INT64_C( 3753264266969785614) },
    { -INT64_C( 4311396562388294819),
       INT64_C( 5057573658044097211),
       INT64_C(  746177095655802392) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vaddd_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r = simde_vaddd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(15770000197539399473),
      UINT64_C(17536172067039799771),
      UINT64_C(14859428190869647628) },
    { UINT64_C(17353057886393621858),
      UINT64_C( 3930588065693821396),
      UINT64_C( 2836901878377891638) },
    { UINT64_C(16195923950262401352),
      UINT64_C( 3237477675399957348),
      UINT64_C(  986657551952807084) },
    { UINT64_C( 8959642801591104818),
      UINT64_C(17451817626807527669),
      UINT64_C( 7964716354689080871) },
    { UINT64_C(12821359242969338377),
      UINT64_C( 7809127654626125417),
      UINT64_C( 2183742823885912178) },
    { UINT64_C(11092975718023534798),
      UINT64_C( 1022251167223362963),
      UINT64_C(12115226885246897761) },
    { UINT64_C( 1266930590655711894),
      UINT64_C(12040272284058140784),
      UINT64_C(13307202874713852678) },
    { UINT64_C(12139750857182669372),
      UINT64_C( 7482753672160808133),
      UINT64_C( 1175760455633925889) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vaddd_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vaddd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -645.65), SIMDE_FLOAT32_C(   153.94) },
      { SIMDE_FLOAT32_C(   112.49), SIMDE_FLOAT32_C(  -617.76) },
      { SIMDE_FLOAT32_C(  -533.16), SIMDE_FLOAT32_C(  -463.81) } },
    { { SIMDE_FLOAT32_C(  -544.46), SIMDE_FLOAT32_C(   -10.20) },
      { SIMDE_FLOAT32_C(   -53.36), SIMDE_FLOAT32_C(  -475.60) },
      { SIMDE_FLOAT32_C(  -597.83), SIMDE_FLOAT32_C(  -485.80) } },
    { { SIMDE_FLOAT32_C(   567.70), SIMDE_FLOAT32_C(   173.84) },
      { SIMDE_FLOAT32_C(   812.81), SIMDE_FLOAT32_C(   166.74) },
      { SIMDE_FLOAT32_C(  1380.51), SIMDE_FLOAT32_C(   340.59) } },
    { { SIMDE_FLOAT32_C(  -854.69), SIMDE_FLOAT32_C(  -924.50) },
      { SIMDE_FLOAT32_C(   -17.33), SIMDE_FLOAT32_C(  -405.57) },
      { SIMDE_FLOAT32_C(  -872.02), SIMDE_FLOAT32_C( -1330.07) } },
    { { SIMDE_FLOAT32_C(   507.20), SIMDE_FLOAT32_C(  -886.90) },
      { SIMDE_FLOAT32_C(   991.64), SIMDE_FLOAT32_C(   755.28) },
      { SIMDE_FLOAT32_C(  1498.84), SIMDE_FLOAT32_C(  -131.62) } },
    { { SIMDE_FLOAT32_C(  -419.88), SIMDE_FLOAT32_C(   108.98) },
      { SIMDE_FLOAT32_C(   853.76), SIMDE_FLOAT32_C(   233.89) },
      { SIMDE_FLOAT32_C(   433.88), SIMDE_FLOAT32_C(   342.87) } },
    { { SIMDE_FLOAT32_C(  -196.90), SIMDE_FLOAT32_C(   244.58) },
      { SIMDE_FLOAT32_C(   298.75), SIMDE_FLOAT32_C(   867.12) },
      { SIMDE_FLOAT32_C(   101.85), SIMDE_FLOAT32_C(  1111.70) } },
    { { SIMDE_FLOAT32_C(    32.51), SIMDE_FLOAT32_C(  -749.49) },
      { SIMDE_FLOAT32_C(  -783.09), SIMDE_FLOAT32_C(   386.86) },
      { SIMDE_FLOAT32_C(  -750.58), SIMDE_FLOAT32_C(  -362.63) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vadd_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vadd_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   404.45) },
      { SIMDE_FLOAT64_C(   329.40) },
      { SIMDE_FLOAT64_C(   733.85) } },
    { { SIMDE_FLOAT64_C(   769.10) },
      { SIMDE_FLOAT64_C(   859.99) },
      { SIMDE_FLOAT64_C(  1629.09) } },
    { { SIMDE_FLOAT64_C(  -680.80) },
      { SIMDE_FLOAT64_C(  -284.26) },
      { SIMDE_FLOAT64_C(  -965.06) } },
    { { SIMDE_FLOAT64_C(  -615.61) },
      { SIMDE_FLOAT64_C(   886.90) },
      { SIMDE_FLOAT64_C(   271.29) } },
    { { SIMDE_FLOAT64_C(   889.58) },
      { SIMDE_FLOAT64_C(  -802.80) },
      { SIMDE_FLOAT64_C(    86.78) } },
    { { SIMDE_FLOAT64_C(    53.64) },
      { SIMDE_FLOAT64_C(  -965.11) },
      { SIMDE_FLOAT64_C(  -911.46) } },
    { { SIMDE_FLOAT64_C(  -727.30) },
      { SIMDE_FLOAT64_C(  -963.68) },
      { SIMDE_FLOAT64_C( -1690.98) } },
    { { SIMDE_FLOAT64_C(  -370.68) },
      { SIMDE_FLOAT64_C(   779.90) },
      { SIMDE_FLOAT64_C(   409.22) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vadd_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  51),  INT8_C(   8), -INT8_C(  16), -INT8_C(  79), -INT8_C( 121), -INT8_C( 101), -INT8_C(  47),  INT8_C( 115) },
      { -INT8_C( 103),  INT8_C(  43), -INT8_C(  76), -INT8_C(  98), -INT8_C(  75),  INT8_C(  79), -INT8_C(  61),  INT8_C( 120) },
      {  INT8_C( 102),  INT8_C(  51), -INT8_C(  92),  INT8_C(  79),  INT8_C(  60), -INT8_C(  22), -INT8_C( 108), -INT8_C(  21) } },
    { {  INT8_C(  28), -INT8_C( 124), -INT8_C(  17), -INT8_C( 117), -INT8_C( 124), -INT8_C(  22),  INT8_C( 125),  INT8_C( 109) },
      {  INT8_C(  14), -INT8_C( 125),  INT8_C(  88),  INT8_C( 115), -INT8_C(  23),  INT8_C( 119), -INT8_C(  31), -INT8_C(  73) },
      {  INT8_C(  42),  INT8_C(   7),  INT8_C(  71), -INT8_C(   2),  INT8_C( 109),  INT8_C(  97),  INT8_C(  94),  INT8_C(  36) } },
    { {      INT8_MAX, -INT8_C(  47),  INT8_C( 104),  INT8_C(   6),  INT8_C( 109),  INT8_C(  57),  INT8_C( 121),  INT8_C(   6) },
      {  INT8_C( 100),  INT8_C(  45), -INT8_C(  92),  INT8_C(  25),  INT8_C( 125),  INT8_C( 104), -INT8_C( 111), -INT8_C( 103) },
      { -INT8_C(  29), -INT8_C(   2),  INT8_C(  12),  INT8_C(  31), -INT8_C(  22), -INT8_C(  95),  INT8_C(  10), -INT8_C(  97) } },
    { { -INT8_C(  20),      INT8_MIN,  INT8_C(  37),  INT8_C( 112),  INT8_C( 106), -INT8_C(  94), -INT8_C(  35),  INT8_C( 120) },
      {  INT8_C(  37),  INT8_C(  54), -INT8_C(  20),  INT8_C(  14), -INT8_C(  83), -INT8_C(  51), -INT8_C(  59),  INT8_C(  44) },
      {  INT8_C(  17), -INT8_C(  74),  INT8_C(  17),  INT8_C( 126),  INT8_C(  23),  INT8_C( 111), -INT8_C(  94), -INT8_C(  92) } },
    { { -INT8_C(  98),  INT8_C(  45),  INT8_C(  51),  INT8_C(  11),  INT8_C( 102), -INT8_C(  84),  INT8_C(  17), -INT8_C(  53) },
      { -INT8_C(  38), -INT8_C(  74), -INT8_C(  28),  INT8_C(  87),  INT8_C(  30),  INT8_C( 118), -INT8_C(  16),  INT8_C(  10) },
      {  INT8_C( 120), -INT8_C(  29),  INT8_C(  23),  INT8_C(  98), -INT8_C( 124),  INT8_C(  34),  INT8_C(   1), -INT8_C(  43) } },
    { { -INT8_C(  10),  INT8_C(  21),  INT8_C( 122),  INT8_C(  97), -INT8_C(  73),  INT8_C(  88), -INT8_C(  39), -INT8_C(  36) },
      { -INT8_C( 114), -INT8_C(  59), -INT8_C(  21),  INT8_C(  59), -INT8_C( 110), -INT8_C(  80),  INT8_C( 103),  INT8_C(  49) },
      { -INT8_C( 124), -INT8_C(  38),  INT8_C( 101), -INT8_C( 100),  INT8_C(  73),  INT8_C(   8),  INT8_C(  64),  INT8_C(  13) } },
    { { -INT8_C(  34), -INT8_C( 102),  INT8_C(  60),  INT8_C(  68),  INT8_C(  71),  INT8_C(  78),  INT8_C(  15),  INT8_C(  33) },
      {  INT8_C(   4), -INT8_C(  12),  INT8_C( 120),  INT8_C(  34),  INT8_C( 106),  INT8_C( 104),  INT8_C(  44),  INT8_C(  96) },
      { -INT8_C(  30), -INT8_C( 114), -INT8_C(  76),  INT8_C( 102), -INT8_C(  79), -INT8_C(  74),  INT8_C(  59), -INT8_C( 127) } },
    { {  INT8_C( 126), -INT8_C(  90), -INT8_C(  63),  INT8_C(  53), -INT8_C(   2), -INT8_C( 101),  INT8_C(  18), -INT8_C( 116) },
      {  INT8_C(  96), -INT8_C(   3), -INT8_C(  57), -INT8_C(  13), -INT8_C(  83),  INT8_C(  47),  INT8_C(  36), -INT8_C( 117) },
      { -INT8_C(  34), -INT8_C(  93), -INT8_C( 120),  INT8_C(  40), -INT8_C(  85), -INT8_C(  54),  INT8_C(  54),  INT8_C(  23) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vadd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 24777),  INT16_C(  4304), -INT16_C(  8274), -INT16_C( 19919) },
      { -INT16_C( 22061),  INT16_C( 15828),  INT16_C(    18), -INT16_C( 28514) },
      {  INT16_C(  2716),  INT16_C( 20132), -INT16_C(  8256),  INT16_C( 17103) } },
    { {  INT16_C( 24487), -INT16_C( 23099), -INT16_C( 10246),  INT16_C( 23346) },
      { -INT16_C(  1580), -INT16_C( 32178),  INT16_C( 29224), -INT16_C(  3571) },
      {  INT16_C( 22907),  INT16_C( 10259),  INT16_C( 18978),  INT16_C( 19775) } },
    { { -INT16_C(  8750), -INT16_C( 32510),  INT16_C( 13501), -INT16_C( 28621) },
      {  INT16_C(  2269), -INT16_C(  4146),  INT16_C( 27656), -INT16_C( 20609) },
      { -INT16_C(  6481),  INT16_C( 28880), -INT16_C( 24379),  INT16_C( 16306) } },
    { {  INT16_C( 17867), -INT16_C( 14763), -INT16_C( 30948), -INT16_C(  3807) },
      {  INT16_C( 28544), -INT16_C( 22157), -INT16_C( 32543), -INT16_C( 19557) },
      { -INT16_C( 19125),  INT16_C( 28616),  INT16_C(  2045), -INT16_C( 23364) } },
    { { -INT16_C( 25250),  INT16_C(  6964),  INT16_C( 26833), -INT16_C( 20565) },
      {  INT16_C( 31088),  INT16_C( 30878),  INT16_C(  7909), -INT16_C( 20184) },
      {  INT16_C(  5838), -INT16_C( 27694), -INT16_C( 30794),  INT16_C( 24787) } },
    { {  INT16_C( 32099),  INT16_C( 32631), -INT16_C( 26620), -INT16_C( 31632) },
      { -INT16_C(  7417), -INT16_C(  6099), -INT16_C( 14236), -INT16_C( 15717) },
      {  INT16_C( 24682),  INT16_C( 26532),  INT16_C( 24680),  INT16_C( 18187) } },
    { { -INT16_C( 12186),  INT16_C( 14301), -INT16_C( 30664), -INT16_C( 22298) },
      { -INT16_C( 31486), -INT16_C(  6368),  INT16_C( 18595),  INT16_C(  1688) },
      {  INT16_C( 21864),  INT16_C(  7933), -INT16_C( 12069), -INT16_C( 20610) } },
    { {  INT16_C(  4037), -INT16_C( 13947), -INT16_C(  2393), -INT16_C( 20914) },
      {  INT16_C( 31705),  INT16_C( 15766),  INT16_C( 12868), -INT16_C( 21761) },
      { -INT16_C( 29794),  INT16_C(  1819),  INT16_C( 10475),  INT16_C( 22861) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vadd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   987880450),  INT32_C(  1742915685) },
      { -INT32_C(   263323059),  INT32_C(   284616523) },
      {  INT32_C(   724557391),  INT32_C(  2027532208) } },
    { { -INT32_C(  1629848586),  INT32_C(  1263282289) },
      { -INT32_C(   410459229),  INT32_C(   395413525) },
      { -INT32_C(  2040307815),  INT32_C(  1658695814) } },
    { { -INT32_C(   917408924), -INT32_C(  2010107077) },
      { -INT32_C(  2139586763),  INT32_C(  1553034854) },
      {  INT32_C(  1237971609), -INT32_C(   457072223) } },
    { {  INT32_C(  1543138281),  INT32_C(   916866963) },
      {  INT32_C(  1058942506),  INT32_C(   458665910) },
      { -INT32_C(  1692886509),  INT32_C(  1375532873) } },
    { {  INT32_C(  1575266082),  INT32_C(   266671578) },
      { -INT32_C(    91202156), -INT32_C(  1252646453) },
      {  INT32_C(  1484063926), -INT32_C(   985974875) } },
    { {  INT32_C(   521163148), -INT32_C(  1034570088) },
      { -INT32_C(  1694403612),  INT32_C(  1169577763) },
      { -INT32_C(  1173240464),  INT32_C(   135007675) } },
    { { -INT32_C(   660366594),  INT32_C(  1139247279) },
      { -INT32_C(  1321371674),  INT32_C(   610702488) },
      { -INT32_C(  1981738268),  INT32_C(  1749949767) } },
    { {  INT32_C(  2101573349),  INT32_C(   289380652) },
      {  INT32_C(   799817740), -INT32_C(  1787469161) },
      { -INT32_C(  1393576207), -INT32_C(  1498088509) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vadd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 8723660904129029892) },
      { -INT64_C( 6446446838156874292) },
      {  INT64_C( 3276636331423647432) } },
    { {  INT64_C( 8237754855438142485) },
      {  INT64_C( 6759364693269282466) },
      { -INT64_C( 3449624525002126665) } },
    { {  INT64_C( 6581439727009348398) },
      {  INT64_C( 4723230566403575077) },
      { -INT64_C( 7142073780296628141) } },
    { { -INT64_C( 5481490900376703211) },
      { -INT64_C( 3201572641363423533) },
      { -INT64_C( 8683063541740126744) } },
    { { -INT64_C( 5124823067756684555) },
      { -INT64_C(    3892366966611835) },
      { -INT64_C( 5128715434723296390) } },
    { {  INT64_C( 2134538319889593818) },
      {  INT64_C( 4354666682578472181) },
      {  INT64_C( 6489205002468065999) } },
    { { -INT64_C( 8158375143962242948) },
      {  INT64_C( 7722040105862391106) },
      { -INT64_C(  436335038099851842) } },
    { {  INT64_C(   76268774866003111) },
      { -INT64_C( 4682326055126867838) },
      { -INT64_C( 4606057280260864727) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vadd_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(145), UINT8_C(172), UINT8_C(192), UINT8_C(101), UINT8_C(103), UINT8_C( 94), UINT8_C(186), UINT8_C(229) },
      { UINT8_C(202), UINT8_C( 17), UINT8_C(115), UINT8_C( 16), UINT8_C(110), UINT8_C( 20), UINT8_C(220), UINT8_C(201) },
      { UINT8_C( 91), UINT8_C(189), UINT8_C( 51), UINT8_C(117), UINT8_C(213), UINT8_C(114), UINT8_C(150), UINT8_C(174) } },
    { { UINT8_C(228), UINT8_C(100), UINT8_C(144), UINT8_C(122), UINT8_C( 55), UINT8_C(227), UINT8_C(226), UINT8_C(153) },
      { UINT8_C( 24), UINT8_C(198), UINT8_C(165), UINT8_C( 23), UINT8_C(173), UINT8_C( 87), UINT8_C( 39), UINT8_C( 62) },
      { UINT8_C(252), UINT8_C( 42), UINT8_C( 53), UINT8_C(145), UINT8_C(228), UINT8_C( 58), UINT8_C(  9), UINT8_C(215) } },
    { { UINT8_C(  3), UINT8_C(231), UINT8_C(163), UINT8_C(106), UINT8_C( 69), UINT8_C( 93), UINT8_C( 80), UINT8_C( 15) },
      { UINT8_C(110), UINT8_C(195), UINT8_C( 31), UINT8_C(221), UINT8_C(216), UINT8_C(251), UINT8_C(166), UINT8_C(188) },
      { UINT8_C(113), UINT8_C(170), UINT8_C(194), UINT8_C( 71), UINT8_C( 29), UINT8_C( 88), UINT8_C(246), UINT8_C(203) } },
    { { UINT8_C( 96), UINT8_C( 55), UINT8_C( 55), UINT8_C(151), UINT8_C( 26), UINT8_C( 25), UINT8_C( 48), UINT8_C( 50) },
      { UINT8_C(223), UINT8_C(213), UINT8_C( 74), UINT8_C(140), UINT8_C( 45), UINT8_C(113), UINT8_C(202), UINT8_C( 48) },
      { UINT8_C( 63), UINT8_C( 12), UINT8_C(129), UINT8_C( 35), UINT8_C( 71), UINT8_C(138), UINT8_C(250), UINT8_C( 98) } },
    { { UINT8_C( 88), UINT8_C(109), UINT8_C(155), UINT8_C(157), UINT8_C(202), UINT8_C(235), UINT8_C(172), UINT8_C( 56) },
      { UINT8_C(174), UINT8_C(203), UINT8_C( 21), UINT8_C(134), UINT8_C(198), UINT8_C(188), UINT8_C( 67), UINT8_C( 38) },
      { UINT8_C(  6), UINT8_C( 56), UINT8_C(176), UINT8_C( 35), UINT8_C(144), UINT8_C(167), UINT8_C(239), UINT8_C( 94) } },
    { { UINT8_C(243), UINT8_C(122), UINT8_C(189), UINT8_C( 13), UINT8_C(147), UINT8_C(238), UINT8_C( 64), UINT8_C(114) },
      { UINT8_C(195), UINT8_C(138), UINT8_C(254), UINT8_C(240), UINT8_C(251), UINT8_C(200), UINT8_C( 33), UINT8_C( 83) },
      { UINT8_C(182), UINT8_C(  4), UINT8_C(187), UINT8_C(253), UINT8_C(142), UINT8_C(182), UINT8_C( 97), UINT8_C(197) } },
    { { UINT8_C( 53), UINT8_C(188), UINT8_C(240),    UINT8_MAX, UINT8_C(167), UINT8_C(156), UINT8_C( 55), UINT8_C( 85) },
      { UINT8_C(103), UINT8_C( 77), UINT8_C(220), UINT8_C( 45), UINT8_C(  9), UINT8_C( 31), UINT8_C( 84), UINT8_C(252) },
      { UINT8_C(156), UINT8_C(  9), UINT8_C(204), UINT8_C( 44), UINT8_C(176), UINT8_C(187), UINT8_C(139), UINT8_C( 81) } },
    { { UINT8_C(153), UINT8_C( 17), UINT8_C(  9), UINT8_C( 44),    UINT8_MAX, UINT8_C( 73), UINT8_C(158), UINT8_C(195) },
      { UINT8_C(211), UINT8_C(156), UINT8_C(179), UINT8_C(206), UINT8_C(100), UINT8_C(212), UINT8_C( 33), UINT8_C(153) },
      { UINT8_C(108), UINT8_C(173), UINT8_C(188), UINT8_C(250), UINT8_C( 99), UINT8_C( 29), UINT8_C(191), UINT8_C( 92) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vadd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 4496), UINT16_C(14232), UINT16_C(53165), UINT16_C( 5261) },
      { UINT16_C(26908), UINT16_C( 9538), UINT16_C(38536), UINT16_C( 8481) },
      { UINT16_C(31404), UINT16_C(23770), UINT16_C(26165), UINT16_C(13742) } },
    { { UINT16_C(11175), UINT16_C(42829), UINT16_C(60276), UINT16_C(18538) },
      { UINT16_C( 7559), UINT16_C(60182), UINT16_C(14578), UINT16_C(33412) },
      { UINT16_C(18734), UINT16_C(37475), UINT16_C( 9318), UINT16_C(51950) } },
    { { UINT16_C( 7241), UINT16_C(63418), UINT16_C(18411), UINT16_C( 2059) },
      { UINT16_C(19888), UINT16_C(14381), UINT16_C(20451), UINT16_C(35673) },
      { UINT16_C(27129), UINT16_C(12263), UINT16_C(38862), UINT16_C(37732) } },
    { { UINT16_C(42618), UINT16_C(60978), UINT16_C(40081), UINT16_C( 6198) },
      { UINT16_C(19897), UINT16_C(43779), UINT16_C(34693), UINT16_C(52782) },
      { UINT16_C(62515), UINT16_C(39221), UINT16_C( 9238), UINT16_C(58980) } },
    { { UINT16_C(59555), UINT16_C(36549), UINT16_C(53551), UINT16_C(57238) },
      { UINT16_C(50206), UINT16_C(  535), UINT16_C(28691), UINT16_C(36237) },
      { UINT16_C(44225), UINT16_C(37084), UINT16_C(16706), UINT16_C(27939) } },
    { { UINT16_C(48918), UINT16_C(42875), UINT16_C(45659), UINT16_C( 5311) },
      { UINT16_C(49919), UINT16_C(33984), UINT16_C(61001), UINT16_C(60498) },
      { UINT16_C(33301), UINT16_C(11323), UINT16_C(41124), UINT16_C(  273) } },
    { { UINT16_C( 6358), UINT16_C( 1402), UINT16_C( 4585), UINT16_C( 2020) },
      { UINT16_C(64469), UINT16_C(59401), UINT16_C(38507), UINT16_C(33141) },
      { UINT16_C( 5291), UINT16_C(60803), UINT16_C(43092), UINT16_C(35161) } },
    { { UINT16_C(61525), UINT16_C(45096), UINT16_C(59298), UINT16_C(41413) },
      { UINT16_C(34217), UINT16_C(61989), UINT16_C(30835), UINT16_C(18910) },
      { UINT16_C(30206), UINT16_C(41549), UINT16_C(24597), UINT16_C(60323) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vadd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2035177616), UINT32_C(1048588905) },
      { UINT32_C(2552662573), UINT32_C(1981389600) },
      { UINT32_C( 292872893), UINT32_C(3029978505) } },
    { { UINT32_C( 774259084), UINT32_C(3520129832) },
      { UINT32_C(3821270384), UINT32_C(4247560557) },
      { UINT32_C( 300562172), UINT32_C(3472723093) } },
    { { UINT32_C(1668709113), UINT32_C(3651270572) },
      { UINT32_C(2708588673), UINT32_C(4011297379) },
      { UINT32_C(  82330490), UINT32_C(3367600655) } },
    { { UINT32_C(4078845643), UINT32_C(2596597289) },
      { UINT32_C(1367181283), UINT32_C( 575580712) },
      { UINT32_C(1151059630), UINT32_C(3172178001) } },
    { { UINT32_C(3515204900), UINT32_C(1034561212) },
      { UINT32_C(1390288110), UINT32_C(1916925606) },
      { UINT32_C( 610525714), UINT32_C(2951486818) } },
    { { UINT32_C(1566924596), UINT32_C( 838281805) },
      { UINT32_C(3665982897), UINT32_C(1140641823) },
      { UINT32_C( 937940197), UINT32_C(1978923628) } },
    { { UINT32_C(1360298389), UINT32_C(2525937575) },
      { UINT32_C(2179493339), UINT32_C(2549295459) },
      { UINT32_C(3539791728), UINT32_C( 780265738) } },
    { { UINT32_C(3606337929), UINT32_C( 872934531) },
      { UINT32_C(2148436321), UINT32_C(4022536794) },
      { UINT32_C(1459806954), UINT32_C( 600504029) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vadd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 8271370438949591179) },
      { UINT64_C( 7149156384669675836) },
      { UINT64_C(15420526823619267015) } },
    { { UINT64_C( 8716507174114306880) },
      { UINT64_C(11246819847481853643) },
      { UINT64_C( 1516582947886608907) } },
    { { UINT64_C( 7033664003445314963) },
      { UINT64_C(13224599815624691785) },
      { UINT64_C( 1811519745360455132) } },
    { { UINT64_C(14839766502604456290) },
      { UINT64_C( 4045366772834167159) },
      { UINT64_C(  438389201729071833) } },
    { { UINT64_C(15340385730390389596) },
      { UINT64_C( 9132594273923359887) },
      { UINT64_C( 6026235930604197867) } },
    { { UINT64_C( 2310322047046596415) },
      { UINT64_C( 7327580934766068434) },
      { UINT64_C( 9637902981812664849) } },
    { { UINT64_C(11681996663360525247) },
      { UINT64_C(15296307448611608238) },
      { UINT64_C( 8531560038262581869) } },
    { { UINT64_C(18043431286987964317) },
      { UINT64_C(11211186651486359335) },
      { UINT64_C(10807873864764772036) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vadd_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -476.88), SIMDE_FLOAT32_C(   -38.10), SIMDE_FLOAT32_C(   469.39), SIMDE_FLOAT32_C(  -664.80) },
      { SIMDE_FLOAT32_C(   181.43), SIMDE_FLOAT32_C(  -154.03), SIMDE_FLOAT32_C(  -345.56), SIMDE_FLOAT32_C(  -102.63) },
      { SIMDE_FLOAT32_C(  -295.46), SIMDE_FLOAT32_C(  -192.12), SIMDE_FLOAT32_C(   123.83), SIMDE_FLOAT32_C(  -767.44) } },
    { { SIMDE_FLOAT32_C(  -103.40), SIMDE_FLOAT32_C(   661.42), SIMDE_FLOAT32_C(  -336.65), SIMDE_FLOAT32_C(   536.30) },
      { SIMDE_FLOAT32_C(   318.30), SIMDE_FLOAT32_C(  -387.41), SIMDE_FLOAT32_C(   435.33), SIMDE_FLOAT32_C(  -961.83) },
      { SIMDE_FLOAT32_C(   214.90), SIMDE_FLOAT32_C(   274.01), SIMDE_FLOAT32_C(    98.69), SIMDE_FLOAT32_C(  -425.53) } },
    { { SIMDE_FLOAT32_C(   203.44), SIMDE_FLOAT32_C(  -916.52), SIMDE_FLOAT32_C(  -867.20), SIMDE_FLOAT32_C(    66.23) },
      { SIMDE_FLOAT32_C(  -667.27), SIMDE_FLOAT32_C(  -968.66), SIMDE_FLOAT32_C(   101.74), SIMDE_FLOAT32_C(   202.05) },
      { SIMDE_FLOAT32_C(  -463.83), SIMDE_FLOAT32_C( -1885.18), SIMDE_FLOAT32_C(  -765.47), SIMDE_FLOAT32_C(   268.28) } },
    { { SIMDE_FLOAT32_C(  -612.77), SIMDE_FLOAT32_C(  -920.83), SIMDE_FLOAT32_C(    82.14), SIMDE_FLOAT32_C(  -930.15) },
      { SIMDE_FLOAT32_C(  -763.40), SIMDE_FLOAT32_C(  -818.04), SIMDE_FLOAT32_C(   -97.96), SIMDE_FLOAT32_C(  -240.29) },
      { SIMDE_FLOAT32_C( -1376.18), SIMDE_FLOAT32_C( -1738.88), SIMDE_FLOAT32_C(   -15.82), SIMDE_FLOAT32_C( -1170.43) } },
    { { SIMDE_FLOAT32_C(   143.86), SIMDE_FLOAT32_C(  -628.57), SIMDE_FLOAT32_C(    94.91), SIMDE_FLOAT32_C(  -674.71) },
      { SIMDE_FLOAT32_C(   217.40), SIMDE_FLOAT32_C(   749.35), SIMDE_FLOAT32_C(   222.65), SIMDE_FLOAT32_C(  -886.00) },
      { SIMDE_FLOAT32_C(   361.26), SIMDE_FLOAT32_C(   120.77), SIMDE_FLOAT32_C(   317.56), SIMDE_FLOAT32_C( -1560.71) } },
    { { SIMDE_FLOAT32_C(   410.77), SIMDE_FLOAT32_C(   886.01), SIMDE_FLOAT32_C(   650.30), SIMDE_FLOAT32_C(  -270.93) },
      { SIMDE_FLOAT32_C(  -501.41), SIMDE_FLOAT32_C(    85.64), SIMDE_FLOAT32_C(  -232.77), SIMDE_FLOAT32_C(   702.03) },
      { SIMDE_FLOAT32_C(   -90.64), SIMDE_FLOAT32_C(   971.64), SIMDE_FLOAT32_C(   417.54), SIMDE_FLOAT32_C(   431.10) } },
    { { SIMDE_FLOAT32_C(   169.12), SIMDE_FLOAT32_C(   -99.97), SIMDE_FLOAT32_C(  -231.73), SIMDE_FLOAT32_C(   501.86) },
      { SIMDE_FLOAT32_C(   -68.63), SIMDE_FLOAT32_C(   870.00), SIMDE_FLOAT32_C(  -296.10), SIMDE_FLOAT32_C(   318.59) },
      { SIMDE_FLOAT32_C(   100.49), SIMDE_FLOAT32_C(   770.03), SIMDE_FLOAT32_C(  -527.83), SIMDE_FLOAT32_C(   820.45) } },
    { { SIMDE_FLOAT32_C(   949.17), SIMDE_FLOAT32_C(   786.05), SIMDE_FLOAT32_C(   388.45), SIMDE_FLOAT32_C(  -814.23) },
      { SIMDE_FLOAT32_C(   968.00), SIMDE_FLOAT32_C(  -709.52), SIMDE_FLOAT32_C(   -54.52), SIMDE_FLOAT32_C(   111.86) },
      { SIMDE_FLOAT32_C(  1917.17), SIMDE_FLOAT32_C(    76.53), SIMDE_FLOAT32_C(   333.93), SIMDE_FLOAT32_C(  -702.37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vaddq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vaddq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -338.09), SIMDE_FLOAT64_C(  -959.61) },
      { SIMDE_FLOAT64_C(   437.15), SIMDE_FLOAT64_C(   879.31) },
      { SIMDE_FLOAT64_C(    99.06), SIMDE_FLOAT64_C(   -80.30) } },
    { { SIMDE_FLOAT64_C(   789.73), SIMDE_FLOAT64_C(  -340.20) },
      { SIMDE_FLOAT64_C(   993.31), SIMDE_FLOAT64_C(   200.50) },
      { SIMDE_FLOAT64_C(  1783.05), SIMDE_FLOAT64_C(  -139.70) } },
    { { SIMDE_FLOAT64_C(  -454.19), SIMDE_FLOAT64_C(   643.62) },
      { SIMDE_FLOAT64_C(   929.57), SIMDE_FLOAT64_C(    44.40) },
      { SIMDE_FLOAT64_C(   475.38), SIMDE_FLOAT64_C(   688.02) } },
    { { SIMDE_FLOAT64_C(  -270.75), SIMDE_FLOAT64_C(  -303.20) },
      { SIMDE_FLOAT64_C(  -253.57), SIMDE_FLOAT64_C(   898.38) },
      { SIMDE_FLOAT64_C(  -524.31), SIMDE_FLOAT64_C(   595.18) } },
    { { SIMDE_FLOAT64_C(   596.83), SIMDE_FLOAT64_C(   514.70) },
      { SIMDE_FLOAT64_C(   400.23), SIMDE_FLOAT64_C(  -471.80) },
      { SIMDE_FLOAT64_C(   997.06), SIMDE_FLOAT64_C(    42.90) } },
    { { SIMDE_FLOAT64_C(   384.71), SIMDE_FLOAT64_C(  -895.87) },
      { SIMDE_FLOAT64_C(   846.79), SIMDE_FLOAT64_C(   333.88) },
      { SIMDE_FLOAT64_C(  1231.50), SIMDE_FLOAT64_C(  -561.99) } },
    { { SIMDE_FLOAT64_C(   890.18), SIMDE_FLOAT64_C(   235.24) },
      { SIMDE_FLOAT64_C(   519.64), SIMDE_FLOAT64_C(   858.18) },
      { SIMDE_FLOAT64_C(  1409.82), SIMDE_FLOAT64_C(  1093.42) } },
    { { SIMDE_FLOAT64_C(   525.73), SIMDE_FLOAT64_C(  -534.88) },
      { SIMDE_FLOAT64_C(   -29.96), SIMDE_FLOAT64_C(  -812.36) },
      { SIMDE_FLOAT64_C(   495.77), SIMDE_FLOAT64_C( -1347.24) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vaddq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vaddq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 111), -INT8_C(  97), -INT8_C(  90),  INT8_C(  69),  INT8_C( 113),  INT8_C(  56), -INT8_C( 115),  INT8_C( 112),
         INT8_C(  53), -INT8_C( 107), -INT8_C(  44),  INT8_C(  82), -INT8_C(  51), -INT8_C(  96), -INT8_C(  21), -INT8_C(  97) },
      { -INT8_C(  99),  INT8_C(  22),  INT8_C( 102),      INT8_MIN,  INT8_C( 111),  INT8_C( 102),  INT8_C(  52), -INT8_C(  31),
         INT8_C(  89),  INT8_C(  28), -INT8_C( 108), -INT8_C(  49),  INT8_C( 112), -INT8_C( 116),  INT8_C( 125), -INT8_C(  33) },
      {  INT8_C(  12), -INT8_C(  75),  INT8_C(  12), -INT8_C(  59), -INT8_C(  32), -INT8_C(  98), -INT8_C(  63),  INT8_C(  81),
        -INT8_C( 114), -INT8_C(  79),  INT8_C( 104),  INT8_C(  33),  INT8_C(  61),  INT8_C(  44),  INT8_C( 104),  INT8_C( 126) } },
    { {  INT8_C(  43),  INT8_C(  35),  INT8_C(  36), -INT8_C( 100),  INT8_C(  92), -INT8_C(  78),  INT8_C(  12), -INT8_C( 111),
         INT8_C(  71), -INT8_C(  32), -INT8_C(  28),  INT8_C(  20), -INT8_C( 127), -INT8_C(  49), -INT8_C(  77),  INT8_C(  30) },
      { -INT8_C(  26),  INT8_C(  25), -INT8_C(  97),  INT8_C(  85),      INT8_MIN, -INT8_C(  45),  INT8_C(  54), -INT8_C(  39),
        -INT8_C(  17), -INT8_C(  54), -INT8_C(  88),  INT8_C(  95),  INT8_C(  86),  INT8_C(  37),  INT8_C(  63), -INT8_C( 126) },
      {  INT8_C(  17),  INT8_C(  60), -INT8_C(  61), -INT8_C(  15), -INT8_C(  36), -INT8_C( 123),  INT8_C(  66),  INT8_C( 106),
         INT8_C(  54), -INT8_C(  86), -INT8_C( 116),  INT8_C( 115), -INT8_C(  41), -INT8_C(  12), -INT8_C(  14), -INT8_C(  96) } },
    { {  INT8_C(  73),  INT8_C(  99),  INT8_C(  30), -INT8_C(  91),  INT8_C(  21),  INT8_C(  43),  INT8_C(  54),  INT8_C(  92),
         INT8_C(  11),  INT8_C(  26),  INT8_C( 112), -INT8_C( 116), -INT8_C(  22),  INT8_C(  35), -INT8_C(  85), -INT8_C(  48) },
      {  INT8_C(  61),  INT8_C(  74),  INT8_C(  37), -INT8_C(  67),  INT8_C(  29),  INT8_C(  91), -INT8_C( 106),  INT8_C(  12),
         INT8_C(  37),  INT8_C(  62),  INT8_C( 108),  INT8_C( 124),  INT8_C(  99), -INT8_C(  85), -INT8_C(   2), -INT8_C(  84) },
      { -INT8_C( 122), -INT8_C(  83),  INT8_C(  67),  INT8_C(  98),  INT8_C(  50), -INT8_C( 122), -INT8_C(  52),  INT8_C( 104),
         INT8_C(  48),  INT8_C(  88), -INT8_C(  36),  INT8_C(   8),  INT8_C(  77), -INT8_C(  50), -INT8_C(  87),  INT8_C( 124) } },
    { {  INT8_C(  14),  INT8_C(  28),  INT8_C(  81),  INT8_C(  36),  INT8_C(  71), -INT8_C( 120),      INT8_MIN,  INT8_C(  83),
        -INT8_C(  94), -INT8_C(  15), -INT8_C(  33), -INT8_C( 116),  INT8_C(  20), -INT8_C( 118),  INT8_C(  92),  INT8_C(  81) },
      { -INT8_C(  44), -INT8_C( 127),  INT8_C(  14), -INT8_C(  15), -INT8_C(  36), -INT8_C(  92), -INT8_C(   2),  INT8_C(   2),
        -INT8_C(  30),  INT8_C( 106),  INT8_C( 126),  INT8_C(  70),  INT8_C(  21),  INT8_C( 124), -INT8_C(  14),  INT8_C(  35) },
      { -INT8_C(  30), -INT8_C(  99),  INT8_C(  95),  INT8_C(  21),  INT8_C(  35),  INT8_C(  44),  INT8_C( 126),  INT8_C(  85),
        -INT8_C( 124),  INT8_C(  91),  INT8_C(  93), -INT8_C(  46),  INT8_C(  41),  INT8_C(   6),  INT8_C(  78),  INT8_C( 116) } },
    { { -INT8_C( 104),  INT8_C(  68),  INT8_C(  71), -INT8_C(  32), -INT8_C(  52), -INT8_C(  56),  INT8_C(  51),  INT8_C( 110),
        -INT8_C(  71),  INT8_C(  18), -INT8_C(   5), -INT8_C(  51), -INT8_C(  99),  INT8_C(  87),  INT8_C(  31),  INT8_C( 113) },
      { -INT8_C(  39),  INT8_C(  45),  INT8_C(  99), -INT8_C(  75), -INT8_C(  46),  INT8_C(  97), -INT8_C(  73), -INT8_C(  76),
        -INT8_C(  53),  INT8_C(  53), -INT8_C(   6), -INT8_C(  32), -INT8_C(  79), -INT8_C(  19),  INT8_C(   3),  INT8_C(  74) },
      {  INT8_C( 113),  INT8_C( 113), -INT8_C(  86), -INT8_C( 107), -INT8_C(  98),  INT8_C(  41), -INT8_C(  22),  INT8_C(  34),
        -INT8_C( 124),  INT8_C(  71), -INT8_C(  11), -INT8_C(  83),  INT8_C(  78),  INT8_C(  68),  INT8_C(  34), -INT8_C(  69) } },
    { {  INT8_C(  49),  INT8_C(  75),  INT8_C(  42), -INT8_C(   3),  INT8_C(  19),  INT8_C(  93),  INT8_C( 107), -INT8_C(  52),
         INT8_C( 111),  INT8_C( 102), -INT8_C( 103),  INT8_C(  12), -INT8_C(  66), -INT8_C(  72),  INT8_C( 126), -INT8_C( 105) },
      { -INT8_C(  26), -INT8_C(  31),  INT8_C(  76), -INT8_C(  72),  INT8_C(  66),  INT8_C(   4),  INT8_C( 108),  INT8_C(  13),
         INT8_C(  57),  INT8_C( 103), -INT8_C(  19), -INT8_C(  21),  INT8_C(  84), -INT8_C(  16),  INT8_C(  53), -INT8_C( 123) },
      {  INT8_C(  23),  INT8_C(  44),  INT8_C( 118), -INT8_C(  75),  INT8_C(  85),  INT8_C(  97), -INT8_C(  41), -INT8_C(  39),
        -INT8_C(  88), -INT8_C(  51), -INT8_C( 122), -INT8_C(   9),  INT8_C(  18), -INT8_C(  88), -INT8_C(  77),  INT8_C(  28) } },
    { {  INT8_C(  59),  INT8_C(  95), -INT8_C( 126),  INT8_C(  78), -INT8_C(  68), -INT8_C(  19),  INT8_C(  26),  INT8_C(  43),
         INT8_C(  84), -INT8_C(  76),  INT8_C(  56),  INT8_C(  18),  INT8_C( 108), -INT8_C(  74), -INT8_C(  87),  INT8_C(  82) },
      { -INT8_C( 105), -INT8_C(  11),  INT8_C(  10), -INT8_C(  39), -INT8_C(   7),  INT8_C( 119), -INT8_C(  26),  INT8_C(  51),
        -INT8_C(  34), -INT8_C(  45),  INT8_C(  30),  INT8_C(  50), -INT8_C(  61),  INT8_C(  83), -INT8_C(  73), -INT8_C(   1) },
      { -INT8_C(  46),  INT8_C(  84), -INT8_C( 116),  INT8_C(  39), -INT8_C(  75),  INT8_C( 100),  INT8_C(   0),  INT8_C(  94),
         INT8_C(  50), -INT8_C( 121),  INT8_C(  86),  INT8_C(  68),  INT8_C(  47),  INT8_C(   9),  INT8_C(  96),  INT8_C(  81) } },
    { { -INT8_C(  78),  INT8_C(  57),  INT8_C(  77),  INT8_C( 110),  INT8_C(  38),  INT8_C( 104), -INT8_C( 103),  INT8_C( 122),
         INT8_C(  28), -INT8_C(  47), -INT8_C( 116), -INT8_C( 120), -INT8_C( 121),  INT8_C(  53), -INT8_C(  37),  INT8_C(  30) },
      {  INT8_C(  43), -INT8_C(  27), -INT8_C(   9),  INT8_C(  36),  INT8_C(  92), -INT8_C(  35),  INT8_C(  87),  INT8_C(  58),
        -INT8_C(  80),  INT8_C( 117),  INT8_C( 108),  INT8_C( 116), -INT8_C(  56),  INT8_C(  35),  INT8_C( 115),  INT8_C( 122) },
      { -INT8_C(  35),  INT8_C(  30),  INT8_C(  68), -INT8_C( 110), -INT8_C( 126),  INT8_C(  69), -INT8_C(  16), -INT8_C(  76),
        -INT8_C(  52),  INT8_C(  70), -INT8_C(   8), -INT8_C(   4),  INT8_C(  79),  INT8_C(  88),  INT8_C(  78), -INT8_C( 104) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vaddq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  9359),  INT16_C( 19853), -INT16_C(  5258),  INT16_C( 25982),  INT16_C( 13488), -INT16_C(  9621), -INT16_C(  8264), -INT16_C( 14382) },
      { -INT16_C( 29038),  INT16_C( 16526), -INT16_C(  8207), -INT16_C( 10419), -INT16_C( 27770),  INT16_C(  8648), -INT16_C(  9930), -INT16_C( 22287) },
      {  INT16_C( 27139), -INT16_C( 29157), -INT16_C( 13465),  INT16_C( 15563), -INT16_C( 14282), -INT16_C(   973), -INT16_C( 18194),  INT16_C( 28867) } },
    { {  INT16_C( 32436),  INT16_C( 10997),  INT16_C( 29545),  INT16_C(  6799), -INT16_C(  1112),  INT16_C( 24820), -INT16_C( 14630),  INT16_C( 27688) },
      { -INT16_C( 18860),  INT16_C( 17836), -INT16_C(  1643),  INT16_C(  6940), -INT16_C(  7028), -INT16_C( 15556),  INT16_C( 11710),  INT16_C( 29291) },
      {  INT16_C( 13576),  INT16_C( 28833),  INT16_C( 27902),  INT16_C( 13739), -INT16_C(  8140),  INT16_C(  9264), -INT16_C(  2920), -INT16_C(  8557) } },
    { {  INT16_C( 24747),  INT16_C(  5533),  INT16_C( 11476),  INT16_C( 31791),  INT16_C(  8999),  INT16_C(   476),  INT16_C(  1257),  INT16_C( 15981) },
      {  INT16_C(  6587),  INT16_C( 20611), -INT16_C( 24557), -INT16_C( 24724), -INT16_C( 22396),  INT16_C( 16994), -INT16_C( 12842), -INT16_C( 32331) },
      {  INT16_C( 31334),  INT16_C( 26144), -INT16_C( 13081),  INT16_C(  7067), -INT16_C( 13397),  INT16_C( 17470), -INT16_C( 11585), -INT16_C( 16350) } },
    { {  INT16_C( 21038),  INT16_C(   662), -INT16_C( 14978), -INT16_C( 22914),  INT16_C( 23272), -INT16_C( 11609),  INT16_C(  5471),  INT16_C(  6672) },
      { -INT16_C( 27858),  INT16_C( 16746), -INT16_C( 10701), -INT16_C( 18207),  INT16_C( 17279),  INT16_C( 22010), -INT16_C( 20719),  INT16_C( 16342) },
      { -INT16_C(  6820),  INT16_C( 17408), -INT16_C( 25679),  INT16_C( 24415), -INT16_C( 24985),  INT16_C( 10401), -INT16_C( 15248),  INT16_C( 23014) } },
    { {  INT16_C( 27905), -INT16_C( 32703), -INT16_C( 16590),  INT16_C(  6950), -INT16_C( 13031),  INT16_C( 30957), -INT16_C(   542),  INT16_C(  4498) },
      { -INT16_C(   624), -INT16_C( 15278),  INT16_C( 13267),  INT16_C( 21116),  INT16_C( 30327), -INT16_C( 30553),  INT16_C( 32294),  INT16_C( 10183) },
      {  INT16_C( 27281),  INT16_C( 17555), -INT16_C(  3323),  INT16_C( 28066),  INT16_C( 17296),  INT16_C(   404),  INT16_C( 31752),  INT16_C( 14681) } },
    { {  INT16_C(  2283),  INT16_C(  7591), -INT16_C( 12857), -INT16_C(  8136),  INT16_C(  9627),  INT16_C( 32089), -INT16_C(  5342), -INT16_C( 19570) },
      { -INT16_C(  7704), -INT16_C( 17289), -INT16_C(  3308), -INT16_C( 29938), -INT16_C( 18839), -INT16_C( 28909), -INT16_C(  9676),  INT16_C(  8119) },
      { -INT16_C(  5421), -INT16_C(  9698), -INT16_C( 16165),  INT16_C( 27462), -INT16_C(  9212),  INT16_C(  3180), -INT16_C( 15018), -INT16_C( 11451) } },
    { {  INT16_C( 24290), -INT16_C( 22212),  INT16_C( 29996), -INT16_C( 14454), -INT16_C(  7270), -INT16_C( 17084), -INT16_C( 11314), -INT16_C( 18576) },
      { -INT16_C(  6220), -INT16_C( 14221), -INT16_C( 32294),  INT16_C( 17236),  INT16_C( 26423),  INT16_C( 27603), -INT16_C( 30142),  INT16_C(  9354) },
      {  INT16_C( 18070),  INT16_C( 29103), -INT16_C(  2298),  INT16_C(  2782),  INT16_C( 19153),  INT16_C( 10519),  INT16_C( 24080), -INT16_C(  9222) } },
    { { -INT16_C( 14360),  INT16_C(  5326),  INT16_C( 22588), -INT16_C( 10533),  INT16_C(  8251),  INT16_C(  2451),  INT16_C(  1011), -INT16_C( 22592) },
      {  INT16_C( 13290), -INT16_C( 15249), -INT16_C( 15435), -INT16_C(  5112), -INT16_C(  9429),  INT16_C( 27992), -INT16_C(  7579),  INT16_C( 19857) },
      { -INT16_C(  1070), -INT16_C(  9923),  INT16_C(  7153), -INT16_C( 15645), -INT16_C(  1178),  INT16_C( 30443), -INT16_C(  6568), -INT16_C(  2735) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vaddq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   446537815), -INT32_C(   222544457),  INT32_C(  1358712669),  INT32_C(  1039645779) },
      { -INT32_C(  1526568976),  INT32_C(  1435568682),  INT32_C(  1254287845),  INT32_C(  1972851916) },
      { -INT32_C(  1973106791),  INT32_C(  1213024225), -INT32_C(  1681966782), -INT32_C(  1282469601) } },
    { {  INT32_C(  1801189811), -INT32_C(  1805838537), -INT32_C(  1176151706),  INT32_C(   116907030) },
      {  INT32_C(  1856764227), -INT32_C(   389858301), -INT32_C(   231569882), -INT32_C(  1922577958) },
      { -INT32_C(   637013258),  INT32_C(  2099270458), -INT32_C(  1407721588), -INT32_C(  1805670928) } },
    { { -INT32_C(    84360509),  INT32_C(  1083070169), -INT32_C(   973507665), -INT32_C(  1815351216) },
      { -INT32_C(   335448343), -INT32_C(   640367181),  INT32_C(   634062411), -INT32_C(  1817038128) },
      { -INT32_C(   419808852),  INT32_C(   442702988), -INT32_C(   339445254),  INT32_C(   662577952) } },
    { { -INT32_C(   829576203), -INT32_C(  1341252863), -INT32_C(   545912689), -INT32_C(   495828488) },
      {  INT32_C(  1808692408), -INT32_C(  2075876551),  INT32_C(  2041122729),  INT32_C(   906779457) },
      {  INT32_C(   979116205),  INT32_C(   877837882),  INT32_C(  1495210040),  INT32_C(   410950969) } },
    { {  INT32_C(   117807366),  INT32_C(  1152914357),  INT32_C(   337849883),  INT32_C(   670471535) },
      {  INT32_C(  1116914697),  INT32_C(   298243687),  INT32_C(   663384037), -INT32_C(   782395445) },
      {  INT32_C(  1234722063),  INT32_C(  1451158044),  INT32_C(  1001233920), -INT32_C(   111923910) } },
    { { -INT32_C(   438738384), -INT32_C(  1859546762),  INT32_C(   782585023), -INT32_C(   346645534) },
      { -INT32_C(   953227168), -INT32_C(  1529285441),  INT32_C(   801858404),  INT32_C(   704653818) },
      { -INT32_C(  1391965552),  INT32_C(   906135093),  INT32_C(  1584443427),  INT32_C(   358008284) } },
    { {  INT32_C(    17881483),  INT32_C(   697514346),  INT32_C(  1750612102),  INT32_C(   877899476) },
      {  INT32_C(  1442546070), -INT32_C(   621095818),  INT32_C(   822723895),  INT32_C(  2052786670) },
      {  INT32_C(  1460427553),  INT32_C(    76418528), -INT32_C(  1721631299), -INT32_C(  1364281150) } },
    { {  INT32_C(  1299934179),  INT32_C(   729222821),  INT32_C(   462671687),  INT32_C(   324003453) },
      { -INT32_C(   563525016),  INT32_C(  1438147358),  INT32_C(   394707240), -INT32_C(  1382948150) },
      {  INT32_C(   736409163), -INT32_C(  2127597117),  INT32_C(   857378927), -INT32_C(  1058944697) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 7069932454407769165), -INT64_C(   13004371797364671) },
      { -INT64_C( 4140332404967654890),  INT64_C( 4669791854137250134) },
      {  INT64_C( 2929600049440114275),  INT64_C( 4656787482339885463) } },
    { {  INT64_C( 9004754196787087738),  INT64_C( 6311525774842819585) },
      {  INT64_C( 6893064936395404358),  INT64_C( 8024092871902594599) },
      { -INT64_C( 2548924940527059520), -INT64_C( 4111125426964137432) } },
    { { -INT64_C( 2319920201253745130),  INT64_C( 6415393146933806960) },
      { -INT64_C( 3248530561039559550), -INT64_C( 3544254053793109396) },
      { -INT64_C( 5568450762293304680),  INT64_C( 2871139093140697564) } },
    { {  INT64_C( 4725381914672747733), -INT64_C( 7178462820614140940) },
      { -INT64_C( 1222143994085532274),  INT64_C( 1441468807256274812) },
      {  INT64_C( 3503237920587215459), -INT64_C( 5736994013357866128) } },
    { {  INT64_C(  145904156942017013), -INT64_C( 9215373147744044954) },
      { -INT64_C( 3352152200456879353), -INT64_C( 2302176223951467846) },
      { -INT64_C( 3206248043514862340),  INT64_C( 6929194702014038816) } },
    { { -INT64_C( 7550095452228168409), -INT64_C( 5469846406055902556) },
      {  INT64_C( 5664886855523291254), -INT64_C( 3436716378960715133) },
      { -INT64_C( 1885208596704877155), -INT64_C( 8906562785016617689) } },
    { {  INT64_C( 4967820718097494825), -INT64_C( 5629233198243575680) },
      {  INT64_C( 6531657446270508995),  INT64_C( 7725668155930504637) },
      { -INT64_C( 6947265909341547796),  INT64_C( 2096434957686928957) } },
    { { -INT64_C(  293377758463705846),  INT64_C( 9127117198251772094) },
      {  INT64_C(   25185705384028199),  INT64_C( 4761604672234922343) },
      { -INT64_C(  268192053079677647), -INT64_C( 4558022203222857179) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vaddq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(219), UINT8_C(217), UINT8_C(235), UINT8_C( 86), UINT8_C(143), UINT8_C(217), UINT8_C( 81), UINT8_C( 77),
        UINT8_C(161), UINT8_C(120), UINT8_C( 70), UINT8_C( 92), UINT8_C(128), UINT8_C(240), UINT8_C(218), UINT8_C(167) },
      { UINT8_C( 24), UINT8_C(175), UINT8_C(166), UINT8_C( 91), UINT8_C( 42),    UINT8_MAX, UINT8_C( 92), UINT8_C(145),
        UINT8_C( 32), UINT8_C(195), UINT8_C( 58), UINT8_C( 88), UINT8_C( 97), UINT8_C( 78), UINT8_C(154), UINT8_C( 60) },
      { UINT8_C(243), UINT8_C(136), UINT8_C(145), UINT8_C(177), UINT8_C(185), UINT8_C(216), UINT8_C(173), UINT8_C(222),
        UINT8_C(193), UINT8_C( 59), UINT8_C(128), UINT8_C(180), UINT8_C(225), UINT8_C( 62), UINT8_C(116), UINT8_C(227) } },
    { { UINT8_C( 39), UINT8_C(134), UINT8_C(146), UINT8_C(182), UINT8_C( 95), UINT8_C(227), UINT8_C(  3), UINT8_C(  0),
        UINT8_C( 91), UINT8_C( 73), UINT8_C( 93), UINT8_C(220), UINT8_C( 58), UINT8_C( 55), UINT8_C(131), UINT8_C( 82) },
      { UINT8_C(231), UINT8_C( 41), UINT8_C(174), UINT8_C( 17), UINT8_C( 40), UINT8_C( 10), UINT8_C(162), UINT8_C( 73),
        UINT8_C(205), UINT8_C(221), UINT8_C(161), UINT8_C( 46), UINT8_C( 43), UINT8_C( 60), UINT8_C(106), UINT8_C( 83) },
      { UINT8_C( 14), UINT8_C(175), UINT8_C( 64), UINT8_C(199), UINT8_C(135), UINT8_C(237), UINT8_C(165), UINT8_C( 73),
        UINT8_C( 40), UINT8_C( 38), UINT8_C(254), UINT8_C( 10), UINT8_C(101), UINT8_C(115), UINT8_C(237), UINT8_C(165) } },
    { { UINT8_C(194), UINT8_C(252), UINT8_C(  9), UINT8_C( 33), UINT8_C(223), UINT8_C( 13), UINT8_C( 33), UINT8_C( 58),
        UINT8_C( 86), UINT8_C(126), UINT8_C( 22), UINT8_C(144), UINT8_C(182), UINT8_C(154), UINT8_C(227), UINT8_C(157) },
      { UINT8_C(195), UINT8_C(145), UINT8_C(174), UINT8_C(236), UINT8_C(155), UINT8_C( 80), UINT8_C( 53), UINT8_C(104),
        UINT8_C( 45), UINT8_C(214), UINT8_C(150), UINT8_C( 89), UINT8_C( 18), UINT8_C(  0), UINT8_C(172), UINT8_C(212) },
      { UINT8_C(133), UINT8_C(141), UINT8_C(183), UINT8_C( 13), UINT8_C(122), UINT8_C( 93), UINT8_C( 86), UINT8_C(162),
        UINT8_C(131), UINT8_C( 84), UINT8_C(172), UINT8_C(233), UINT8_C(200), UINT8_C(154), UINT8_C(143), UINT8_C(113) } },
    { { UINT8_C(252), UINT8_C(181), UINT8_C(245), UINT8_C(219), UINT8_C(194), UINT8_C( 23), UINT8_C( 21), UINT8_C( 25),
        UINT8_C(149), UINT8_C( 44), UINT8_C(169), UINT8_C( 75), UINT8_C(198), UINT8_C(140), UINT8_C(232), UINT8_C(137) },
      { UINT8_C( 29), UINT8_C(150), UINT8_C(117), UINT8_C(184), UINT8_C(231), UINT8_C(170), UINT8_C( 32), UINT8_C( 20),
        UINT8_C(129), UINT8_C(182), UINT8_C(109), UINT8_C(147), UINT8_C(182), UINT8_C( 25), UINT8_C(104), UINT8_C(178) },
      { UINT8_C( 25), UINT8_C( 75), UINT8_C(106), UINT8_C(147), UINT8_C(169), UINT8_C(193), UINT8_C( 53), UINT8_C( 45),
        UINT8_C( 22), UINT8_C(226), UINT8_C( 22), UINT8_C(222), UINT8_C(124), UINT8_C(165), UINT8_C( 80), UINT8_C( 59) } },
    { { UINT8_C(207), UINT8_C( 93), UINT8_C(141), UINT8_C(145), UINT8_C(116), UINT8_C(163), UINT8_C(170), UINT8_C( 10),
        UINT8_C(207), UINT8_C( 84), UINT8_C( 85), UINT8_C(149), UINT8_C(224), UINT8_C( 62), UINT8_C( 30), UINT8_C(254) },
      { UINT8_C(212), UINT8_C(148), UINT8_C(182), UINT8_C(187), UINT8_C( 62), UINT8_C(215), UINT8_C(208), UINT8_C(191),
        UINT8_C(141), UINT8_C( 61), UINT8_C( 83), UINT8_C( 68), UINT8_C( 87), UINT8_C(187), UINT8_C(246), UINT8_C( 38) },
      { UINT8_C(163), UINT8_C(241), UINT8_C( 67), UINT8_C( 76), UINT8_C(178), UINT8_C(122), UINT8_C(122), UINT8_C(201),
        UINT8_C( 92), UINT8_C(145), UINT8_C(168), UINT8_C(217), UINT8_C( 55), UINT8_C(249), UINT8_C( 20), UINT8_C( 36) } },
    { { UINT8_C( 24), UINT8_C(132), UINT8_C(183), UINT8_C(141), UINT8_C( 39), UINT8_C( 98), UINT8_C(151), UINT8_C(246),
        UINT8_C(182), UINT8_C(236), UINT8_C(139), UINT8_C(150), UINT8_C( 42), UINT8_C(169), UINT8_C(148),    UINT8_MAX },
      { UINT8_C( 61), UINT8_C( 75), UINT8_C(186), UINT8_C(124), UINT8_C( 34), UINT8_C(138), UINT8_C( 59), UINT8_C(175),
        UINT8_C(200), UINT8_C(142), UINT8_C(243), UINT8_C( 31), UINT8_C( 73), UINT8_C(234), UINT8_C( 69), UINT8_C( 98) },
      { UINT8_C( 85), UINT8_C(207), UINT8_C(113), UINT8_C(  9), UINT8_C( 73), UINT8_C(236), UINT8_C(210), UINT8_C(165),
        UINT8_C(126), UINT8_C(122), UINT8_C(126), UINT8_C(181), UINT8_C(115), UINT8_C(147), UINT8_C(217), UINT8_C( 97) } },
    { { UINT8_C(110), UINT8_C(252), UINT8_C(239), UINT8_C(149), UINT8_C( 94), UINT8_C(134), UINT8_C(139), UINT8_C( 20),
        UINT8_C(114), UINT8_C( 22), UINT8_C(171), UINT8_C(157), UINT8_C(191), UINT8_C( 63), UINT8_C(156), UINT8_C(253) },
      { UINT8_C(138), UINT8_C( 86), UINT8_C(121), UINT8_C(172), UINT8_C(225), UINT8_C(180), UINT8_C( 92), UINT8_C(169),
        UINT8_C( 67), UINT8_C( 79), UINT8_C(200), UINT8_C(140), UINT8_C( 57), UINT8_C( 13), UINT8_C(238), UINT8_C(167) },
      { UINT8_C(248), UINT8_C( 82), UINT8_C(104), UINT8_C( 65), UINT8_C( 63), UINT8_C( 58), UINT8_C(231), UINT8_C(189),
        UINT8_C(181), UINT8_C(101), UINT8_C(115), UINT8_C( 41), UINT8_C(248), UINT8_C( 76), UINT8_C(138), UINT8_C(164) } },
    { { UINT8_C(  9), UINT8_C(221), UINT8_C( 60), UINT8_C(104), UINT8_C( 99), UINT8_C(199), UINT8_C(124), UINT8_C(214),
        UINT8_C(221), UINT8_C( 39), UINT8_C(115), UINT8_C(157), UINT8_C(103), UINT8_C( 15), UINT8_C(154), UINT8_C(241) },
      { UINT8_C(101), UINT8_C( 19), UINT8_C(158), UINT8_C( 70), UINT8_C(199), UINT8_C(250), UINT8_C(239), UINT8_C( 10),
        UINT8_C( 73), UINT8_C(183), UINT8_C(151), UINT8_C(131), UINT8_C(196), UINT8_C(133), UINT8_C( 42), UINT8_C(206) },
      { UINT8_C(110), UINT8_C(240), UINT8_C(218), UINT8_C(174), UINT8_C( 42), UINT8_C(193), UINT8_C(107), UINT8_C(224),
        UINT8_C( 38), UINT8_C(222), UINT8_C( 10), UINT8_C( 32), UINT8_C( 43), UINT8_C(148), UINT8_C(196), UINT8_C(191) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vaddq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(26467), UINT16_C(50742), UINT16_C(45614), UINT16_C( 3228), UINT16_C( 4058), UINT16_C(16809), UINT16_C(17182), UINT16_C(33842) },
      { UINT16_C(53334), UINT16_C( 7626), UINT16_C(47818), UINT16_C( 5160), UINT16_C(49009), UINT16_C(13975), UINT16_C(49476), UINT16_C(42756) },
      { UINT16_C(14265), UINT16_C(58368), UINT16_C(27896), UINT16_C( 8388), UINT16_C(53067), UINT16_C(30784), UINT16_C( 1122), UINT16_C(11062) } },
    { { UINT16_C(14888), UINT16_C(22382), UINT16_C( 2796), UINT16_C(50787), UINT16_C( 3098), UINT16_C(14343), UINT16_C(14927), UINT16_C(42428) },
      { UINT16_C(34570), UINT16_C(54722), UINT16_C(59969), UINT16_C(45801), UINT16_C(32937), UINT16_C(61160), UINT16_C(60481), UINT16_C(27285) },
      { UINT16_C(49458), UINT16_C(11568), UINT16_C(62765), UINT16_C(31052), UINT16_C(36035), UINT16_C( 9967), UINT16_C( 9872), UINT16_C( 4177) } },
    { { UINT16_C(  806), UINT16_C( 5057), UINT16_C( 9230), UINT16_C(10457), UINT16_C(57648), UINT16_C(32608), UINT16_C( 7451), UINT16_C( 9508) },
      { UINT16_C(59044), UINT16_C(58874), UINT16_C(58321), UINT16_C(31383), UINT16_C(32867), UINT16_C(42344), UINT16_C(65132), UINT16_C(37647) },
      { UINT16_C(59850), UINT16_C(63931), UINT16_C( 2015), UINT16_C(41840), UINT16_C(24979), UINT16_C( 9416), UINT16_C( 7047), UINT16_C(47155) } },
    { { UINT16_C(53249), UINT16_C( 4006), UINT16_C(32756), UINT16_C( 9271), UINT16_C(39008), UINT16_C(31651), UINT16_C(51125), UINT16_C(22945) },
      { UINT16_C(39853), UINT16_C(32318), UINT16_C(54655), UINT16_C(58105), UINT16_C(24917), UINT16_C(49799), UINT16_C(38495), UINT16_C(24917) },
      { UINT16_C(27566), UINT16_C(36324), UINT16_C(21875), UINT16_C( 1840), UINT16_C(63925), UINT16_C(15914), UINT16_C(24084), UINT16_C(47862) } },
    { { UINT16_C(64358), UINT16_C(23152), UINT16_C(43130), UINT16_C(56190), UINT16_C( 8512), UINT16_C(62806), UINT16_C(63464), UINT16_C(38478) },
      { UINT16_C(35987), UINT16_C( 4628), UINT16_C( 3425), UINT16_C(47092), UINT16_C(31855), UINT16_C(52857), UINT16_C(52754), UINT16_C(31023) },
      { UINT16_C(34809), UINT16_C(27780), UINT16_C(46555), UINT16_C(37746), UINT16_C(40367), UINT16_C(50127), UINT16_C(50682), UINT16_C( 3965) } },
    { { UINT16_C(41161), UINT16_C(17363), UINT16_C(21064), UINT16_C(34846), UINT16_C(30067), UINT16_C(23677), UINT16_C(52076), UINT16_C(65522) },
      { UINT16_C( 1623), UINT16_C(47121), UINT16_C( 1556), UINT16_C(33647), UINT16_C(59522), UINT16_C(37969), UINT16_C(33206), UINT16_C(32525) },
      { UINT16_C(42784), UINT16_C(64484), UINT16_C(22620), UINT16_C( 2957), UINT16_C(24053), UINT16_C(61646), UINT16_C(19746), UINT16_C(32511) } },
    { { UINT16_C(57633), UINT16_C(27075), UINT16_C(57651), UINT16_C(42737), UINT16_C(28246), UINT16_C(49922), UINT16_C(62521), UINT16_C(37058) },
      { UINT16_C(54523), UINT16_C( 3912), UINT16_C(47322), UINT16_C(23698), UINT16_C(58272), UINT16_C(22512), UINT16_C(65124), UINT16_C(34262) },
      { UINT16_C(46620), UINT16_C(30987), UINT16_C(39437), UINT16_C(  899), UINT16_C(20982), UINT16_C( 6898), UINT16_C(62109), UINT16_C( 5784) } },
    { { UINT16_C(39391), UINT16_C( 4846), UINT16_C(57211), UINT16_C(53688), UINT16_C(47949), UINT16_C(34452), UINT16_C(22447), UINT16_C(43542) },
      { UINT16_C(24363), UINT16_C( 1465), UINT16_C(19223), UINT16_C(46945), UINT16_C(20783), UINT16_C(37646), UINT16_C(58703), UINT16_C(11801) },
      { UINT16_C(63754), UINT16_C( 6311), UINT16_C(10898), UINT16_C(35097), UINT16_C( 3196), UINT16_C( 6562), UINT16_C(15614), UINT16_C(55343) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vaddq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(4181723006), UINT32_C( 885783015), UINT32_C(1673224116), UINT32_C(3775844790) },
      { UINT32_C(1206306608), UINT32_C(1124026131), UINT32_C(3906276761), UINT32_C(1897393906) },
      { UINT32_C(1093062318), UINT32_C(2009809146), UINT32_C(1284533581), UINT32_C(1378271400) } },
    { { UINT32_C(3714734070), UINT32_C(  68236624), UINT32_C(1265159317), UINT32_C(3459085982) },
      { UINT32_C(1343623997), UINT32_C(4103214427), UINT32_C( 366766114), UINT32_C(1283912534) },
      { UINT32_C( 763390771), UINT32_C(4171451051), UINT32_C(1631925431), UINT32_C( 448031220) } },
    { { UINT32_C(2603216971), UINT32_C(3147840294), UINT32_C(2768635911), UINT32_C(3144954750) },
      { UINT32_C(2718730823), UINT32_C(3247873695), UINT32_C(1574334982), UINT32_C(2980666470) },
      { UINT32_C(1026980498), UINT32_C(2100746693), UINT32_C(  48003597), UINT32_C(1830653924) } },
    { { UINT32_C(1934414669), UINT32_C( 355396622), UINT32_C(1924871412), UINT32_C(2939039592) },
      { UINT32_C(1481718457), UINT32_C(3743016920), UINT32_C(3208441945), UINT32_C(2574312780) },
      { UINT32_C(3416133126), UINT32_C(4098413542), UINT32_C( 838346061), UINT32_C(1218385076) } },
    { { UINT32_C(3322723768), UINT32_C(2665233065), UINT32_C(3608188783), UINT32_C(2139504326) },
      { UINT32_C(1373099896), UINT32_C( 389083326), UINT32_C( 769092832), UINT32_C( 180766545) },
      { UINT32_C( 400856368), UINT32_C(3054316391), UINT32_C(  82314319), UINT32_C(2320270871) } },
    { { UINT32_C(2932921092), UINT32_C(2085399565), UINT32_C( 156458051), UINT32_C( 327735707) },
      { UINT32_C(1852071856), UINT32_C( 814126160), UINT32_C(1381850368), UINT32_C(2841388196) },
      { UINT32_C( 490025652), UINT32_C(2899525725), UINT32_C(1538308419), UINT32_C(3169123903) } },
    { { UINT32_C(  72822007), UINT32_C( 478258137), UINT32_C(2586236159), UINT32_C(1588506286) },
      { UINT32_C(1590497806), UINT32_C(2811122599), UINT32_C(1425665200), UINT32_C( 134042896) },
      { UINT32_C(1663319813), UINT32_C(3289380736), UINT32_C(4011901359), UINT32_C(1722549182) } },
    { { UINT32_C(1527469186), UINT32_C(4151807223), UINT32_C( 261201249), UINT32_C(1517109068) },
      { UINT32_C(4189600338), UINT32_C(1033913997), UINT32_C(1116903986), UINT32_C(1900646383) },
      { UINT32_C(1422102228), UINT32_C( 890753924), UINT32_C(1378105235), UINT32_C(3417755451) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vaddq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4814986688458413540), UINT64_C(17692320368709166305) },
      { UINT64_C(13313924206382956537), UINT64_C(14594553297499805225) },
      { UINT64_C(18128910894841370077), UINT64_C(13840129592499419914) } },
    { { UINT64_C( 8988473036196107929), UINT64_C(14372448548797616092) },
      { UINT64_C( 1994835094183764848), UINT64_C( 9807079594316311145) },
      { UINT64_C(10983308130379872777), UINT64_C( 5732784069404375621) } },
    { { UINT64_C( 1381409056111181588), UINT64_C( 8531232789823149263) },
      { UINT64_C( 3492853524787409771), UINT64_C( 9168371629288304069) },
      { UINT64_C( 4874262580898591359), UINT64_C(17699604419111453332) } },
    { { UINT64_C(14961619866231914328), UINT64_C(12081417531889038382) },
      { UINT64_C(17832984800169039493), UINT64_C(17011757792814168874) },
      { UINT64_C(14347860592691402205), UINT64_C(10646431250993655640) } },
    { { UINT64_C(14696404044792677158), UINT64_C(13201361342813856081) },
      { UINT64_C(16277837227336350142), UINT64_C(11455340474931777913) },
      { UINT64_C(12527497198419475684), UINT64_C( 6209957744036082378) } },
    { { UINT64_C(16372757905063310543), UINT64_C(11169953870697739545) },
      { UINT64_C(18335686276445570782), UINT64_C( 5051355942773124099) },
      { UINT64_C(16261700107799329709), UINT64_C(16221309813470863644) } },
    { { UINT64_C(12749384425783090810), UINT64_C(16328080845921083167) },
      { UINT64_C(10919518894275568390), UINT64_C( 1555480866372949464) },
      { UINT64_C( 5222159246349107584), UINT64_C(17883561712294032631) } },
    { { UINT64_C( 5859481300311754763), UINT64_C( 6004676323984625006) },
      { UINT64_C(10246929086205053448), UINT64_C( 9200137657917523965) },
      { UINT64_C(16106410386516808211), UINT64_C(15204813981902148971) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vaddq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vadd_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
