#define SIMDE_TEST_X86_AVX512_INSN loadu

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/loadu.h>
#include <simde/x86/avx512/set.h>

static int
test_simde_mm_loadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  98),  INT8_C( 124), -INT8_C(  57), -INT8_C(  74),  INT8_C( 104),  INT8_C(  59),  INT8_C(  69), -INT8_C(  25),
         INT8_C(  20), -INT8_C(  48), -INT8_C(  57), -INT8_C(  59),  INT8_C(  21),  INT8_C( 119), -INT8_C(  97),  INT8_C(  28) },
      {  INT8_C(  98),  INT8_C( 124), -INT8_C(  57), -INT8_C(  74),  INT8_C( 104),  INT8_C(  59),  INT8_C(  69), -INT8_C(  25),
         INT8_C(  20), -INT8_C(  48), -INT8_C(  57), -INT8_C(  59),  INT8_C(  21),  INT8_C( 119), -INT8_C(  97),  INT8_C(  28) } },
    { {  INT8_C(  70), -INT8_C(  33),  INT8_C(  29),  INT8_C(  10),  INT8_C(  39),  INT8_C(  31), -INT8_C(  91),  INT8_C(  90),
         INT8_C( 111), -INT8_C(  46), -INT8_C(  65),  INT8_C( 124), -INT8_C(  81),  INT8_C(  57), -INT8_C(  34),  INT8_C(  17) },
      {  INT8_C(  70), -INT8_C(  33),  INT8_C(  29),  INT8_C(  10),  INT8_C(  39),  INT8_C(  31), -INT8_C(  91),  INT8_C(  90),
         INT8_C( 111), -INT8_C(  46), -INT8_C(  65),  INT8_C( 124), -INT8_C(  81),  INT8_C(  57), -INT8_C(  34),  INT8_C(  17) } },
    { { -INT8_C(  75), -INT8_C(  91), -INT8_C(  56),  INT8_C(  30), -INT8_C(  31),  INT8_C(  13),  INT8_C(   5), -INT8_C(  11),
        -INT8_C(  35), -INT8_C(  52), -INT8_C(  70), -INT8_C(  14),  INT8_C(  67),  INT8_C(  89),  INT8_C(  15), -INT8_C( 118) },
      { -INT8_C(  75), -INT8_C(  91), -INT8_C(  56),  INT8_C(  30), -INT8_C(  31),  INT8_C(  13),  INT8_C(   5), -INT8_C(  11),
        -INT8_C(  35), -INT8_C(  52), -INT8_C(  70), -INT8_C(  14),  INT8_C(  67),  INT8_C(  89),  INT8_C(  15), -INT8_C( 118) } },
    { {  INT8_C(  56),  INT8_C(  44), -INT8_C( 108),  INT8_C(  96),  INT8_C(  75),  INT8_C(  57), -INT8_C(  70), -INT8_C(  70),
         INT8_C(  12),  INT8_C( 121),  INT8_C(  55), -INT8_C(  69), -INT8_C(  78),  INT8_C(  21), -INT8_C(  51),  INT8_C( 104) },
      {  INT8_C(  56),  INT8_C(  44), -INT8_C( 108),  INT8_C(  96),  INT8_C(  75),  INT8_C(  57), -INT8_C(  70), -INT8_C(  70),
         INT8_C(  12),  INT8_C( 121),  INT8_C(  55), -INT8_C(  69), -INT8_C(  78),  INT8_C(  21), -INT8_C(  51),  INT8_C( 104) } },
    { { -INT8_C(  69), -INT8_C( 107), -INT8_C( 122), -INT8_C( 100), -INT8_C(  94), -INT8_C( 117), -INT8_C( 111),      INT8_MAX,
         INT8_C(  87),  INT8_C(  75),  INT8_C( 114), -INT8_C( 102), -INT8_C(  91), -INT8_C( 127),  INT8_C(  36), -INT8_C(  35) },
      { -INT8_C(  69), -INT8_C( 107), -INT8_C( 122), -INT8_C( 100), -INT8_C(  94), -INT8_C( 117), -INT8_C( 111),      INT8_MAX,
         INT8_C(  87),  INT8_C(  75),  INT8_C( 114), -INT8_C( 102), -INT8_C(  91), -INT8_C( 127),  INT8_C(  36), -INT8_C(  35) } },
    { { -INT8_C(  83), -INT8_C(  72),  INT8_C(  61), -INT8_C(   8), -INT8_C(  14), -INT8_C(   8), -INT8_C(  78), -INT8_C(   2),
         INT8_C( 113), -INT8_C(  23), -INT8_C(  71),  INT8_C(  36), -INT8_C(   1), -INT8_C( 122), -INT8_C( 116), -INT8_C(  70) },
      { -INT8_C(  83), -INT8_C(  72),  INT8_C(  61), -INT8_C(   8), -INT8_C(  14), -INT8_C(   8), -INT8_C(  78), -INT8_C(   2),
         INT8_C( 113), -INT8_C(  23), -INT8_C(  71),  INT8_C(  36), -INT8_C(   1), -INT8_C( 122), -INT8_C( 116), -INT8_C(  70) } },
    { {  INT8_C(  27),  INT8_C(  18),  INT8_C(  86), -INT8_C(  67), -INT8_C(  99), -INT8_C(  25),  INT8_C(  61), -INT8_C(  12),
         INT8_C(  50), -INT8_C(  81), -INT8_C( 114), -INT8_C(  41),  INT8_C(  48), -INT8_C(  77), -INT8_C(  75), -INT8_C(  35) },
      {  INT8_C(  27),  INT8_C(  18),  INT8_C(  86), -INT8_C(  67), -INT8_C(  99), -INT8_C(  25),  INT8_C(  61), -INT8_C(  12),
         INT8_C(  50), -INT8_C(  81), -INT8_C( 114), -INT8_C(  41),  INT8_C(  48), -INT8_C(  77), -INT8_C(  75), -INT8_C(  35) } },
    { {  INT8_C( 107), -INT8_C(  14), -INT8_C(  43),  INT8_C(  93), -INT8_C(  22), -INT8_C( 121),  INT8_C(  91),  INT8_C(  92),
         INT8_C( 113),  INT8_C(  21),      INT8_MIN,  INT8_C( 112), -INT8_C( 101),  INT8_C(  12),  INT8_C(  42), -INT8_C(  73) },
      {  INT8_C( 107), -INT8_C(  14), -INT8_C(  43),  INT8_C(  93), -INT8_C(  22), -INT8_C( 121),  INT8_C(  91),  INT8_C(  92),
         INT8_C( 113),  INT8_C(  21),      INT8_MIN,  INT8_C( 112), -INT8_C( 101),  INT8_C(  12),  INT8_C(  42), -INT8_C(  73) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i8x16(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = a;

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 32738), -INT16_C( 17548), -INT16_C( 20121), -INT16_C( 26193),  INT16_C( 15712), -INT16_C( 28559),  INT16_C(  9968),  INT16_C( 23661) },
      { -INT16_C( 32738), -INT16_C( 17548), -INT16_C( 20121), -INT16_C( 26193),  INT16_C( 15712), -INT16_C( 28559),  INT16_C(  9968),  INT16_C( 23661) } },
    { {  INT16_C( 16920),  INT16_C(   953),  INT16_C(  5578),  INT16_C( 15199), -INT16_C(  8406), -INT16_C( 14933), -INT16_C( 10773),  INT16_C(  2428) },
      {  INT16_C( 16920),  INT16_C(   953),  INT16_C(  5578),  INT16_C( 15199), -INT16_C(  8406), -INT16_C( 14933), -INT16_C( 10773),  INT16_C(  2428) } },
    { { -INT16_C(  3755), -INT16_C( 17212),  INT16_C( 29602),  INT16_C(   853), -INT16_C( 14672), -INT16_C( 24173),  INT16_C(   492),  INT16_C(  1533) },
      { -INT16_C(  3755), -INT16_C( 17212),  INT16_C( 29602),  INT16_C(   853), -INT16_C( 14672), -INT16_C( 24173),  INT16_C(   492),  INT16_C(  1533) } },
    { { -INT16_C( 18877),  INT16_C(  3336),  INT16_C( 26571), -INT16_C(  2744), -INT16_C(  3258),  INT16_C( 12731),  INT16_C( 14280),  INT16_C(  7482) },
      { -INT16_C( 18877),  INT16_C(  3336),  INT16_C( 26571), -INT16_C(  2744), -INT16_C(  3258),  INT16_C( 12731),  INT16_C( 14280),  INT16_C(  7482) } },
    { { -INT16_C(   472), -INT16_C( 13351),  INT16_C( 12145),  INT16_C(  8654),  INT16_C( 25077), -INT16_C(  7486), -INT16_C( 16542), -INT16_C( 22809) },
      { -INT16_C(   472), -INT16_C( 13351),  INT16_C( 12145),  INT16_C(  8654),  INT16_C( 25077), -INT16_C(  7486), -INT16_C( 16542), -INT16_C( 22809) } },
    { { -INT16_C(  4234),  INT16_C( 16819), -INT16_C(   938), -INT16_C( 25545), -INT16_C(  3345), -INT16_C( 18227),  INT16_C(  1833),  INT16_C( 21205) },
      { -INT16_C(  4234),  INT16_C( 16819), -INT16_C(   938), -INT16_C( 25545), -INT16_C(  3345), -INT16_C( 18227),  INT16_C(  1833),  INT16_C( 21205) } },
    { { -INT16_C( 20731),  INT16_C( 30237), -INT16_C(  5154), -INT16_C( 11369),  INT16_C( 23116), -INT16_C( 20555), -INT16_C( 25575), -INT16_C( 28843) },
      { -INT16_C( 20731),  INT16_C( 30237), -INT16_C(  5154), -INT16_C( 11369),  INT16_C( 23116), -INT16_C( 20555), -INT16_C( 25575), -INT16_C( 28843) } },
    { {  INT16_C(  2187), -INT16_C(  7727),  INT16_C(  2052), -INT16_C(  2947),  INT16_C( 19194),  INT16_C(  9132), -INT16_C( 32431),  INT16_C( 22133) },
      {  INT16_C(  2187), -INT16_C(  7727),  INT16_C(  2052), -INT16_C(  2947),  INT16_C( 19194),  INT16_C(  9132), -INT16_C( 32431),  INT16_C( 22133) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x8(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = a;

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   248287792), -INT32_C(   891132803), -INT32_C(   679897154), -INT32_C(  1083716044) },
      {  INT32_C(   248287792), -INT32_C(   891132803), -INT32_C(   679897154), -INT32_C(  1083716044) } },
    { { -INT32_C(   610191146),  INT32_C(   986652224), -INT32_C(  1168278679),  INT32_C(   756143100) },
      { -INT32_C(   610191146),  INT32_C(   986652224), -INT32_C(  1168278679),  INT32_C(   756143100) } },
    { { -INT32_C(   482615963), -INT32_C(     5431999), -INT32_C(   371775819), -INT32_C(   894943500) },
      { -INT32_C(   482615963), -INT32_C(     5431999), -INT32_C(   371775819), -INT32_C(   894943500) } },
    { { -INT32_C(  1230681738), -INT32_C(   772770712), -INT32_C(   326414865), -INT32_C(  2045141984) },
      { -INT32_C(  1230681738), -INT32_C(   772770712), -INT32_C(   326414865), -INT32_C(  2045141984) } },
    { { -INT32_C(  1150724998),  INT32_C(   666572402),  INT32_C(   806392380),  INT32_C(  1190836432) },
      { -INT32_C(  1150724998),  INT32_C(   666572402),  INT32_C(   806392380),  INT32_C(  1190836432) } },
    { {  INT32_C(  1794940930),  INT32_C(    71035924),  INT32_C(  1525728825), -INT32_C(   572520093) },
      {  INT32_C(  1794940930),  INT32_C(    71035924),  INT32_C(  1525728825), -INT32_C(   572520093) } },
    { { -INT32_C(   812103331), -INT32_C(  1678355617), -INT32_C(  1244985627), -INT32_C(  1040464449) },
      { -INT32_C(   812103331), -INT32_C(  1678355617), -INT32_C(  1244985627), -INT32_C(  1040464449) } },
    { {  INT32_C(  2049701733),  INT32_C(   494823139), -INT32_C(  1887998420), -INT32_C(   731097225) },
      {  INT32_C(  2049701733),  INT32_C(   494823139), -INT32_C(  1887998420), -INT32_C(   731097225) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x4(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = a;

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4511087683801712032), -INT64_C( 8060898892722248287) },
      {  INT64_C( 4511087683801712032), -INT64_C( 8060898892722248287) } },
    { { -INT64_C( 2384787176194159386),  INT64_C( 6143431839469952758) },
      { -INT64_C( 2384787176194159386),  INT64_C( 6143431839469952758) } },
    { {  INT64_C( 2411376884971791839),  INT64_C( 4543466100033153363) },
      {  INT64_C( 2411376884971791839),  INT64_C( 4543466100033153363) } },
    { { -INT64_C( 7674432146617329682), -INT64_C( 6460338043923272626) },
      { -INT64_C( 7674432146617329682), -INT64_C( 6460338043923272626) } },
    { { -INT64_C( 1312143318173438935), -INT64_C( 2642072646704280642) },
      { -INT64_C( 1312143318173438935), -INT64_C( 2642072646704280642) } },
    { { -INT64_C( 7150315094646497649),  INT64_C( 3770910417545578470) },
      { -INT64_C( 7150315094646497649),  INT64_C( 3770910417545578470) } },
    { {  INT64_C( 4983981236450898595), -INT64_C( 7152365960020912652) },
      {  INT64_C( 4983981236450898595), -INT64_C( 7152365960020912652) } },
    { {  INT64_C( 1871967141139003407),  INT64_C( 3861302942246541911) },
      {  INT64_C( 1871967141139003407),  INT64_C( 3861302942246541911) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x2(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = a;

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  29), -INT8_C(  94),  INT8_C(  76),  INT8_C(  20),  INT8_C(  54), -INT8_C(  63),      INT8_MAX,  INT8_C(  69),
        -INT8_C(   2),  INT8_C( 122),  INT8_C(  91),  INT8_C(  14),  INT8_C( 107),  INT8_C( 122), -INT8_C(  75),  INT8_C( 113),
         INT8_C(  74), -INT8_C(  31), -INT8_C(  17), -INT8_C(  25),  INT8_C(  39),  INT8_C(  64), -INT8_C(  71),  INT8_C( 123),
             INT8_MAX, -INT8_C(  97), -INT8_C( 125), -INT8_C(  43), -INT8_C(  70), -INT8_C( 126),  INT8_C( 107), -INT8_C(  41) },
      {  INT8_C(  29), -INT8_C(  94),  INT8_C(  76),  INT8_C(  20),  INT8_C(  54), -INT8_C(  63),      INT8_MAX,  INT8_C(  69),
        -INT8_C(   2),  INT8_C( 122),  INT8_C(  91),  INT8_C(  14),  INT8_C( 107),  INT8_C( 122), -INT8_C(  75),  INT8_C( 113),
         INT8_C(  74), -INT8_C(  31), -INT8_C(  17), -INT8_C(  25),  INT8_C(  39),  INT8_C(  64), -INT8_C(  71),  INT8_C( 123),
             INT8_MAX, -INT8_C(  97), -INT8_C( 125), -INT8_C(  43), -INT8_C(  70), -INT8_C( 126),  INT8_C( 107), -INT8_C(  41) } },
    { {  INT8_C(  37), -INT8_C(  73), -INT8_C(  21),  INT8_C(  91),  INT8_C( 121),  INT8_C( 107), -INT8_C(  96),  INT8_C( 119),
        -INT8_C(  27), -INT8_C(   5), -INT8_C( 123),  INT8_C(  80),  INT8_C( 118),  INT8_C(  59), -INT8_C(  63), -INT8_C(  64),
         INT8_C(  28), -INT8_C(  80), -INT8_C(  89),  INT8_C(  67), -INT8_C(  16),  INT8_C(  96), -INT8_C(  65),  INT8_C( 112),
        -INT8_C(   1),  INT8_C(  66),  INT8_C(  69), -INT8_C(  71), -INT8_C(  59), -INT8_C(  80), -INT8_C( 111), -INT8_C(  22) },
      {  INT8_C(  37), -INT8_C(  73), -INT8_C(  21),  INT8_C(  91),  INT8_C( 121),  INT8_C( 107), -INT8_C(  96),  INT8_C( 119),
        -INT8_C(  27), -INT8_C(   5), -INT8_C( 123),  INT8_C(  80),  INT8_C( 118),  INT8_C(  59), -INT8_C(  63), -INT8_C(  64),
         INT8_C(  28), -INT8_C(  80), -INT8_C(  89),  INT8_C(  67), -INT8_C(  16),  INT8_C(  96), -INT8_C(  65),  INT8_C( 112),
        -INT8_C(   1),  INT8_C(  66),  INT8_C(  69), -INT8_C(  71), -INT8_C(  59), -INT8_C(  80), -INT8_C( 111), -INT8_C(  22) } },
    { {  INT8_C( 103),  INT8_C( 124),  INT8_C(  69), -INT8_C(  32), -INT8_C(  25), -INT8_C(  27),  INT8_C(  87), -INT8_C(  52),
        -INT8_C(  31), -INT8_C(  35),  INT8_C(  28),  INT8_C(  87),  INT8_C(  24), -INT8_C(  34),  INT8_C(  23),  INT8_C(  52),
        -INT8_C( 114), -INT8_C(  66),  INT8_C( 120),      INT8_MAX,  INT8_C(  30),  INT8_C(  55), -INT8_C(  17),  INT8_C(  29),
         INT8_C( 121),  INT8_C(  52), -INT8_C(  42),  INT8_C(  62), -INT8_C(  28),  INT8_C( 103),  INT8_C(  40),  INT8_C(  75) },
      {  INT8_C( 103),  INT8_C( 124),  INT8_C(  69), -INT8_C(  32), -INT8_C(  25), -INT8_C(  27),  INT8_C(  87), -INT8_C(  52),
        -INT8_C(  31), -INT8_C(  35),  INT8_C(  28),  INT8_C(  87),  INT8_C(  24), -INT8_C(  34),  INT8_C(  23),  INT8_C(  52),
        -INT8_C( 114), -INT8_C(  66),  INT8_C( 120),      INT8_MAX,  INT8_C(  30),  INT8_C(  55), -INT8_C(  17),  INT8_C(  29),
         INT8_C( 121),  INT8_C(  52), -INT8_C(  42),  INT8_C(  62), -INT8_C(  28),  INT8_C( 103),  INT8_C(  40),  INT8_C(  75) } },
    { { -INT8_C(  28),  INT8_C( 109),  INT8_C(  44), -INT8_C(  53),  INT8_C(  83), -INT8_C( 125), -INT8_C( 104),  INT8_C(  52),
         INT8_C(  96), -INT8_C(  76), -INT8_C( 117),  INT8_C( 120), -INT8_C( 110), -INT8_C(  94), -INT8_C(  83),  INT8_C(  33),
         INT8_C(  96),  INT8_C(  37), -INT8_C(  96),  INT8_C( 126),  INT8_C(  92), -INT8_C( 113), -INT8_C( 101), -INT8_C(  43),
        -INT8_C(  61),  INT8_C( 113),  INT8_C(  20), -INT8_C(  89), -INT8_C(  39),  INT8_C(  60), -INT8_C(  14), -INT8_C(  67) },
      { -INT8_C(  28),  INT8_C( 109),  INT8_C(  44), -INT8_C(  53),  INT8_C(  83), -INT8_C( 125), -INT8_C( 104),  INT8_C(  52),
         INT8_C(  96), -INT8_C(  76), -INT8_C( 117),  INT8_C( 120), -INT8_C( 110), -INT8_C(  94), -INT8_C(  83),  INT8_C(  33),
         INT8_C(  96),  INT8_C(  37), -INT8_C(  96),  INT8_C( 126),  INT8_C(  92), -INT8_C( 113), -INT8_C( 101), -INT8_C(  43),
        -INT8_C(  61),  INT8_C( 113),  INT8_C(  20), -INT8_C(  89), -INT8_C(  39),  INT8_C(  60), -INT8_C(  14), -INT8_C(  67) } },
    { { -INT8_C(  86),  INT8_C(  30), -INT8_C( 120), -INT8_C(   3), -INT8_C(  94),  INT8_C(  32),  INT8_C(  49),  INT8_C(   2),
        -INT8_C(  43), -INT8_C(  68),  INT8_C( 123),  INT8_C( 103),  INT8_C(  94),  INT8_C(  40), -INT8_C( 120), -INT8_C(  66),
         INT8_C(  77),  INT8_C(  40),  INT8_C(  60), -INT8_C(  87), -INT8_C(  73), -INT8_C(  41),  INT8_C( 126),  INT8_C( 122),
         INT8_C(  72), -INT8_C( 110),  INT8_C(  33),  INT8_C(  33), -INT8_C(  49),  INT8_C(  20), -INT8_C(  34),  INT8_C( 121) },
      { -INT8_C(  86),  INT8_C(  30), -INT8_C( 120), -INT8_C(   3), -INT8_C(  94),  INT8_C(  32),  INT8_C(  49),  INT8_C(   2),
        -INT8_C(  43), -INT8_C(  68),  INT8_C( 123),  INT8_C( 103),  INT8_C(  94),  INT8_C(  40), -INT8_C( 120), -INT8_C(  66),
         INT8_C(  77),  INT8_C(  40),  INT8_C(  60), -INT8_C(  87), -INT8_C(  73), -INT8_C(  41),  INT8_C( 126),  INT8_C( 122),
         INT8_C(  72), -INT8_C( 110),  INT8_C(  33),  INT8_C(  33), -INT8_C(  49),  INT8_C(  20), -INT8_C(  34),  INT8_C( 121) } },
    { {  INT8_C(  50),  INT8_C( 103),  INT8_C( 118), -INT8_C(  44), -INT8_C( 121), -INT8_C(  89), -INT8_C(  41),  INT8_C(  92),
         INT8_C(  99),  INT8_C(  82), -INT8_C(  60), -INT8_C(  63),  INT8_C( 122),  INT8_C(  76),      INT8_MAX, -INT8_C(  57),
         INT8_C( 117), -INT8_C(  69),  INT8_C( 112),  INT8_C(  44), -INT8_C( 110), -INT8_C(  18), -INT8_C(  89), -INT8_C(  38),
        -INT8_C( 127), -INT8_C(  56), -INT8_C(   4),  INT8_C(  80), -INT8_C(  36), -INT8_C(  38), -INT8_C(  55),  INT8_C(  15) },
      {  INT8_C(  50),  INT8_C( 103),  INT8_C( 118), -INT8_C(  44), -INT8_C( 121), -INT8_C(  89), -INT8_C(  41),  INT8_C(  92),
         INT8_C(  99),  INT8_C(  82), -INT8_C(  60), -INT8_C(  63),  INT8_C( 122),  INT8_C(  76),      INT8_MAX, -INT8_C(  57),
         INT8_C( 117), -INT8_C(  69),  INT8_C( 112),  INT8_C(  44), -INT8_C( 110), -INT8_C(  18), -INT8_C(  89), -INT8_C(  38),
        -INT8_C( 127), -INT8_C(  56), -INT8_C(   4),  INT8_C(  80), -INT8_C(  36), -INT8_C(  38), -INT8_C(  55),  INT8_C(  15) } },
    { {  INT8_C(  65),  INT8_C(  63), -INT8_C(  29), -INT8_C(  55), -INT8_C(  26), -INT8_C(  70),  INT8_C(  37),  INT8_C(  73),
         INT8_C(  12), -INT8_C(  23),  INT8_C(  10), -INT8_C( 122),  INT8_C(  54), -INT8_C( 119),  INT8_C(  77), -INT8_C(  85),
         INT8_C(  68), -INT8_C(  67), -INT8_C(  41), -INT8_C(  42), -INT8_C(  84),  INT8_C( 126), -INT8_C(  80),  INT8_C(  45),
         INT8_C(  71), -INT8_C(  84),  INT8_C( 125),  INT8_C(  35), -INT8_C( 121),  INT8_C(  70),  INT8_C(  50), -INT8_C(  56) },
      {  INT8_C(  65),  INT8_C(  63), -INT8_C(  29), -INT8_C(  55), -INT8_C(  26), -INT8_C(  70),  INT8_C(  37),  INT8_C(  73),
         INT8_C(  12), -INT8_C(  23),  INT8_C(  10), -INT8_C( 122),  INT8_C(  54), -INT8_C( 119),  INT8_C(  77), -INT8_C(  85),
         INT8_C(  68), -INT8_C(  67), -INT8_C(  41), -INT8_C(  42), -INT8_C(  84),  INT8_C( 126), -INT8_C(  80),  INT8_C(  45),
         INT8_C(  71), -INT8_C(  84),  INT8_C( 125),  INT8_C(  35), -INT8_C( 121),  INT8_C(  70),  INT8_C(  50), -INT8_C(  56) } },
    { { -INT8_C( 123),  INT8_C(  22), -INT8_C( 111),  INT8_C( 107), -INT8_C(  48), -INT8_C(  73), -INT8_C(  76), -INT8_C(  35),
        -INT8_C(  96), -INT8_C(  66),  INT8_C(  99), -INT8_C(  42),  INT8_C(  71), -INT8_C(  79), -INT8_C( 127), -INT8_C( 117),
         INT8_C( 110),  INT8_C(  89),  INT8_C(  97),  INT8_C(  26), -INT8_C(  41),  INT8_C(  17),  INT8_C(  71),  INT8_C(  30),
        -INT8_C(  66), -INT8_C(  60),  INT8_C(  66),  INT8_C(  69),  INT8_C(  10),  INT8_C( 116),  INT8_C(  13), -INT8_C( 113) },
      { -INT8_C( 123),  INT8_C(  22), -INT8_C( 111),  INT8_C( 107), -INT8_C(  48), -INT8_C(  73), -INT8_C(  76), -INT8_C(  35),
        -INT8_C(  96), -INT8_C(  66),  INT8_C(  99), -INT8_C(  42),  INT8_C(  71), -INT8_C(  79), -INT8_C( 127), -INT8_C( 117),
         INT8_C( 110),  INT8_C(  89),  INT8_C(  97),  INT8_C(  26), -INT8_C(  41),  INT8_C(  17),  INT8_C(  71),  INT8_C(  30),
        -INT8_C(  66), -INT8_C(  60),  INT8_C(  66),  INT8_C(  69),  INT8_C(  10),  INT8_C( 116),  INT8_C(  13), -INT8_C( 113) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i8x32(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = a;

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 24694),  INT16_C( 23546), -INT16_C( 20906), -INT16_C(  2504), -INT16_C( 25748), -INT16_C( 19507),  INT16_C( 20044), -INT16_C( 17602),
        -INT16_C( 24665),  INT16_C( 32725),  INT16_C(  7601),  INT16_C( 28573), -INT16_C(  8223), -INT16_C(  4940), -INT16_C( 16044), -INT16_C(  8581) },
      { -INT16_C( 24694),  INT16_C( 23546), -INT16_C( 20906), -INT16_C(  2504), -INT16_C( 25748), -INT16_C( 19507),  INT16_C( 20044), -INT16_C( 17602),
        -INT16_C( 24665),  INT16_C( 32725),  INT16_C(  7601),  INT16_C( 28573), -INT16_C(  8223), -INT16_C(  4940), -INT16_C( 16044), -INT16_C(  8581) } },
    { {  INT16_C( 30304), -INT16_C( 18887),  INT16_C( 28964), -INT16_C( 28243),  INT16_C( 31245),  INT16_C( 22852), -INT16_C( 31800),  INT16_C( 28692),
        -INT16_C(  5598), -INT16_C( 11281), -INT16_C( 29689), -INT16_C(  6078), -INT16_C(  2452), -INT16_C( 16172),  INT16_C( 20664),  INT16_C(  6302) },
      {  INT16_C( 30304), -INT16_C( 18887),  INT16_C( 28964), -INT16_C( 28243),  INT16_C( 31245),  INT16_C( 22852), -INT16_C( 31800),  INT16_C( 28692),
        -INT16_C(  5598), -INT16_C( 11281), -INT16_C( 29689), -INT16_C(  6078), -INT16_C(  2452), -INT16_C( 16172),  INT16_C( 20664),  INT16_C(  6302) } },
    { { -INT16_C( 10042), -INT16_C(  5425),  INT16_C( 31817),  INT16_C( 22139), -INT16_C( 16138), -INT16_C( 16720), -INT16_C( 15293),  INT16_C( 25902),
         INT16_C(  7598), -INT16_C( 19143),  INT16_C( 31658),  INT16_C(  5790),  INT16_C( 29298),  INT16_C( 10966),  INT16_C( 29890), -INT16_C( 30654) },
      { -INT16_C( 10042), -INT16_C(  5425),  INT16_C( 31817),  INT16_C( 22139), -INT16_C( 16138), -INT16_C( 16720), -INT16_C( 15293),  INT16_C( 25902),
         INT16_C(  7598), -INT16_C( 19143),  INT16_C( 31658),  INT16_C(  5790),  INT16_C( 29298),  INT16_C( 10966),  INT16_C( 29890), -INT16_C( 30654) } },
    { {  INT16_C(  4428), -INT16_C( 27021), -INT16_C(  4467), -INT16_C( 31764), -INT16_C( 25426), -INT16_C(  3774),  INT16_C( 28769),  INT16_C(  3927),
        -INT16_C( 28530),  INT16_C( 14533),  INT16_C( 25355),  INT16_C( 32078),  INT16_C(  9429), -INT16_C( 26457), -INT16_C(  5480), -INT16_C(  6880) },
      {  INT16_C(  4428), -INT16_C( 27021), -INT16_C(  4467), -INT16_C( 31764), -INT16_C( 25426), -INT16_C(  3774),  INT16_C( 28769),  INT16_C(  3927),
        -INT16_C( 28530),  INT16_C( 14533),  INT16_C( 25355),  INT16_C( 32078),  INT16_C(  9429), -INT16_C( 26457), -INT16_C(  5480), -INT16_C(  6880) } },
    { { -INT16_C( 27653), -INT16_C( 30341),  INT16_C( 26498),  INT16_C( 12300),  INT16_C( 19972),  INT16_C( 25890),  INT16_C( 31167),  INT16_C( 19828),
         INT16_C( 14601),  INT16_C(  5253), -INT16_C( 11364),  INT16_C( 29330),  INT16_C( 14839), -INT16_C( 28918),  INT16_C( 10787),  INT16_C(  8052) },
      { -INT16_C( 27653), -INT16_C( 30341),  INT16_C( 26498),  INT16_C( 12300),  INT16_C( 19972),  INT16_C( 25890),  INT16_C( 31167),  INT16_C( 19828),
         INT16_C( 14601),  INT16_C(  5253), -INT16_C( 11364),  INT16_C( 29330),  INT16_C( 14839), -INT16_C( 28918),  INT16_C( 10787),  INT16_C(  8052) } },
    { { -INT16_C(  4162),  INT16_C( 16552), -INT16_C( 19369),  INT16_C( 23408), -INT16_C( 28157), -INT16_C( 15680),  INT16_C( 13323),  INT16_C(  5135),
        -INT16_C( 27538),  INT16_C(  2601), -INT16_C( 17561),  INT16_C( 24188), -INT16_C( 30988),  INT16_C(  6381),  INT16_C( 25265),  INT16_C( 28471) },
      { -INT16_C(  4162),  INT16_C( 16552), -INT16_C( 19369),  INT16_C( 23408), -INT16_C( 28157), -INT16_C( 15680),  INT16_C( 13323),  INT16_C(  5135),
        -INT16_C( 27538),  INT16_C(  2601), -INT16_C( 17561),  INT16_C( 24188), -INT16_C( 30988),  INT16_C(  6381),  INT16_C( 25265),  INT16_C( 28471) } },
    { { -INT16_C(  8367), -INT16_C( 22353),  INT16_C(  8083), -INT16_C( 27133), -INT16_C( 15438), -INT16_C( 17064),  INT16_C( 26616),  INT16_C( 26322),
        -INT16_C(  1029),  INT16_C( 25200), -INT16_C(  4682), -INT16_C( 21824), -INT16_C( 20877),  INT16_C(  9410), -INT16_C(  1776),  INT16_C( 24979) },
      { -INT16_C(  8367), -INT16_C( 22353),  INT16_C(  8083), -INT16_C( 27133), -INT16_C( 15438), -INT16_C( 17064),  INT16_C( 26616),  INT16_C( 26322),
        -INT16_C(  1029),  INT16_C( 25200), -INT16_C(  4682), -INT16_C( 21824), -INT16_C( 20877),  INT16_C(  9410), -INT16_C(  1776),  INT16_C( 24979) } },
    { {  INT16_C( 17112),  INT16_C( 27658),  INT16_C(  3426),  INT16_C(  5122),  INT16_C( 23505), -INT16_C( 13871), -INT16_C( 23614), -INT16_C( 16849),
        -INT16_C( 24674),  INT16_C( 21536), -INT16_C(  7796),  INT16_C(   255), -INT16_C( 15985), -INT16_C( 24796), -INT16_C( 18245), -INT16_C( 27904) },
      {  INT16_C( 17112),  INT16_C( 27658),  INT16_C(  3426),  INT16_C(  5122),  INT16_C( 23505), -INT16_C( 13871), -INT16_C( 23614), -INT16_C( 16849),
        -INT16_C( 24674),  INT16_C( 21536), -INT16_C(  7796),  INT16_C(   255), -INT16_C( 15985), -INT16_C( 24796), -INT16_C( 18245), -INT16_C( 27904) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x16(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = a;

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1560218362), -INT32_C(   378535400),  INT32_C(   531776093), -INT32_C(  2065833499),  INT32_C(   232324736),  INT32_C(  1846400991),  INT32_C(  1410150809), -INT32_C(   454619671) },
      {  INT32_C(  1560218362), -INT32_C(   378535400),  INT32_C(   531776093), -INT32_C(  2065833499),  INT32_C(   232324736),  INT32_C(  1846400991),  INT32_C(  1410150809), -INT32_C(   454619671) } },
    { {  INT32_C(   809559832),  INT32_C(  1176089065), -INT32_C(   664417293),  INT32_C(   744244140),  INT32_C(   540620097), -INT32_C(  1517402612),  INT32_C(  1643748216), -INT32_C(  1069162072) },
      {  INT32_C(   809559832),  INT32_C(  1176089065), -INT32_C(   664417293),  INT32_C(   744244140),  INT32_C(   540620097), -INT32_C(  1517402612),  INT32_C(  1643748216), -INT32_C(  1069162072) } },
    { { -INT32_C(  1309636920),  INT32_C(   720832823), -INT32_C(  2147328812), -INT32_C(   525508705), -INT32_C(  1610553708), -INT32_C(  1522102739), -INT32_C(   771342551), -INT32_C(   393065440) },
      { -INT32_C(  1309636920),  INT32_C(   720832823), -INT32_C(  2147328812), -INT32_C(   525508705), -INT32_C(  1610553708), -INT32_C(  1522102739), -INT32_C(   771342551), -INT32_C(   393065440) } },
    { {  INT32_C(   161055698),  INT32_C(  1630769292), -INT32_C(  1931397651),  INT32_C(   678268564), -INT32_C(  1563857547),  INT32_C(   625414140),  INT32_C(  1878478158),  INT32_C(  1800899225) },
      {  INT32_C(   161055698),  INT32_C(  1630769292), -INT32_C(  1931397651),  INT32_C(   678268564), -INT32_C(  1563857547),  INT32_C(   625414140),  INT32_C(  1878478158),  INT32_C(  1800899225) } },
    { { -INT32_C(  1720389363),  INT32_C(  1861920641),  INT32_C(  1912331485), -INT32_C(   543528854), -INT32_C(   780049451), -INT32_C(  1057503118), -INT32_C(  1355813354), -INT32_C(  2061793416) },
      { -INT32_C(  1720389363),  INT32_C(  1861920641),  INT32_C(  1912331485), -INT32_C(   543528854), -INT32_C(   780049451), -INT32_C(  1057503118), -INT32_C(  1355813354), -INT32_C(  2061793416) } },
    { { -INT32_C(   115372168),  INT32_C(   342366519),  INT32_C(  1619354613), -INT32_C(  1606475829), -INT32_C(   193805950), -INT32_C(  1615500919), -INT32_C(   800070569), -INT32_C(   480941461) },
      { -INT32_C(   115372168),  INT32_C(   342366519),  INT32_C(  1619354613), -INT32_C(  1606475829), -INT32_C(   193805950), -INT32_C(  1615500919), -INT32_C(   800070569), -INT32_C(   480941461) } },
    { {  INT32_C(   819819769), -INT32_C(  2092677746),  INT32_C(  1944308392),  INT32_C(  1813193705),  INT32_C(  1835042276),  INT32_C(  1175262702),  INT32_C(  1695964410), -INT32_C(  1085707322) },
      {  INT32_C(   819819769), -INT32_C(  2092677746),  INT32_C(  1944308392),  INT32_C(  1813193705),  INT32_C(  1835042276),  INT32_C(  1175262702),  INT32_C(  1695964410), -INT32_C(  1085707322) } },
    { {  INT32_C(  1861232352),  INT32_C(   334574699), -INT32_C(   393816578), -INT32_C(   598435336),  INT32_C(   222934047), -INT32_C(  1001171254),  INT32_C(  2015979954), -INT32_C(  1254591787) },
      {  INT32_C(  1861232352),  INT32_C(   334574699), -INT32_C(   393816578), -INT32_C(   598435336),  INT32_C(   222934047), -INT32_C(  1001171254),  INT32_C(  2015979954), -INT32_C(  1254591787) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x8(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = a;

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 2730480485383468799),  INT64_C( 3961809025040497319), -INT64_C( 7760876929369986550),  INT64_C( 2630957754019333904) },
      { -INT64_C( 2730480485383468799),  INT64_C( 3961809025040497319), -INT64_C( 7760876929369986550),  INT64_C( 2630957754019333904) } },
    { {  INT64_C( 2406427958756382740),  INT64_C( 1484904791614610964), -INT64_C( 2360563711534695397), -INT64_C( 4781223386344087970) },
      {  INT64_C( 2406427958756382740),  INT64_C( 1484904791614610964), -INT64_C( 2360563711534695397), -INT64_C( 4781223386344087970) } },
    { {  INT64_C( 5864722717878051783),  INT64_C( 7398096197995911564), -INT64_C( 1370136013387598003), -INT64_C( 7183219597633509398) },
      {  INT64_C( 5864722717878051783),  INT64_C( 7398096197995911564), -INT64_C( 1370136013387598003), -INT64_C( 7183219597633509398) } },
    { { -INT64_C( 3205083785718752777), -INT64_C( 2680742885939594470),  INT64_C( 1263244472435006221),  INT64_C(   39394444786922777) },
      { -INT64_C( 3205083785718752777), -INT64_C( 2680742885939594470),  INT64_C( 1263244472435006221),  INT64_C(   39394444786922777) } },
    { { -INT64_C( 4203624633801086578),  INT64_C( 3916713484056400884),  INT64_C( 6704269143766553041),  INT64_C( 3699662719747403598) },
      { -INT64_C( 4203624633801086578),  INT64_C( 3916713484056400884),  INT64_C( 6704269143766553041),  INT64_C( 3699662719747403598) } },
    { {  INT64_C( 4084959771584138049), -INT64_C( 6690919879014753339), -INT64_C( 7060055079283591580),  INT64_C( 7578517111345336660) },
      {  INT64_C( 4084959771584138049), -INT64_C( 6690919879014753339), -INT64_C( 7060055079283591580),  INT64_C( 7578517111345336660) } },
    { { -INT64_C( 6100963634310728488), -INT64_C( 8766892043372261664), -INT64_C( 1539611403198992203), -INT64_C( 4821648871914235772) },
      { -INT64_C( 6100963634310728488), -INT64_C( 8766892043372261664), -INT64_C( 1539611403198992203), -INT64_C( 4821648871914235772) } },
    { {  INT64_C( 5896672549719927620), -INT64_C( 2096610149610066370), -INT64_C( 3618209875233467063),  INT64_C(   55047857207160097) },
      {  INT64_C( 5896672549719927620), -INT64_C( 2096610149610066370), -INT64_C( 3618209875233467063),  INT64_C(   55047857207160097) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x4(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = a;

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C( 115),  INT8_C(   0), -INT8_C(  90), -INT8_C(  57),  INT8_C(  50),  INT8_C(  15), -INT8_C( 121),  INT8_C(  47),
        -INT8_C(   4), -INT8_C(  87), -INT8_C(  26), -INT8_C( 116),  INT8_C(  32), -INT8_C(  59),  INT8_C(  96),  INT8_C(  45),
         INT8_C(  33), -INT8_C(  50), -INT8_C(  83), -INT8_C(  99),  INT8_C(  12),  INT8_C(  64), -INT8_C(  87),  INT8_C( 109),
        -INT8_C(  66), -INT8_C(  55),  INT8_C(  19), -INT8_C(  76), -INT8_C(  80),  INT8_C(  43),  INT8_C(  80),  INT8_C(  36),
         INT8_C(  43), -INT8_C(   9), -INT8_C(  21),  INT8_C(  94),  INT8_C(   6),  INT8_C( 114), -INT8_C( 115),  INT8_C(   2),
         INT8_C(  27),  INT8_C( 115), -INT8_C( 114),  INT8_C(  59),  INT8_C(  56), -INT8_C(  17),  INT8_C( 104),  INT8_C(  89),
        -INT8_C(  67),  INT8_C(  21), -INT8_C(  10), -INT8_C(  55),  INT8_C(  85), -INT8_C(  96),  INT8_C(  55),  INT8_C(  20),
         INT8_C( 105),  INT8_C(  74), -INT8_C(  56),  INT8_C(  26),  INT8_C( 117),  INT8_C(  24),  INT8_C(  62), -INT8_C(  95) },
      {  INT8_C( 115),  INT8_C(   0), -INT8_C(  90), -INT8_C(  57),  INT8_C(  50),  INT8_C(  15), -INT8_C( 121),  INT8_C(  47),
        -INT8_C(   4), -INT8_C(  87), -INT8_C(  26), -INT8_C( 116),  INT8_C(  32), -INT8_C(  59),  INT8_C(  96),  INT8_C(  45),
         INT8_C(  33), -INT8_C(  50), -INT8_C(  83), -INT8_C(  99),  INT8_C(  12),  INT8_C(  64), -INT8_C(  87),  INT8_C( 109),
        -INT8_C(  66), -INT8_C(  55),  INT8_C(  19), -INT8_C(  76), -INT8_C(  80),  INT8_C(  43),  INT8_C(  80),  INT8_C(  36),
         INT8_C(  43), -INT8_C(   9), -INT8_C(  21),  INT8_C(  94),  INT8_C(   6),  INT8_C( 114), -INT8_C( 115),  INT8_C(   2),
         INT8_C(  27),  INT8_C( 115), -INT8_C( 114),  INT8_C(  59),  INT8_C(  56), -INT8_C(  17),  INT8_C( 104),  INT8_C(  89),
        -INT8_C(  67),  INT8_C(  21), -INT8_C(  10), -INT8_C(  55),  INT8_C(  85), -INT8_C(  96),  INT8_C(  55),  INT8_C(  20),
         INT8_C( 105),  INT8_C(  74), -INT8_C(  56),  INT8_C(  26),  INT8_C( 117),  INT8_C(  24),  INT8_C(  62), -INT8_C(  95) } },
    { {  INT8_C(  15),  INT8_C(  41), -INT8_C(   1),  INT8_C(  22), -INT8_C( 101), -INT8_C( 116),  INT8_C(  24), -INT8_C(  74),
        -INT8_C(   1), -INT8_C(  89), -INT8_C(  15),  INT8_C(  55), -INT8_C( 106),  INT8_C(  90), -INT8_C( 112),  INT8_C(  83),
         INT8_C( 111), -INT8_C( 121),  INT8_C(  29), -INT8_C(  59),  INT8_C(  39),  INT8_C(  84), -INT8_C(  39), -INT8_C( 112),
        -INT8_C(  98), -INT8_C(  95), -INT8_C(  86),  INT8_C(  20), -INT8_C(  71), -INT8_C(  24), -INT8_C(  75), -INT8_C(  55),
         INT8_C(  17), -INT8_C(  76), -INT8_C(  33), -INT8_C(  84),  INT8_C(  64), -INT8_C(   9),  INT8_C(  98),  INT8_C(  63),
        -INT8_C(  98),  INT8_C(  84),  INT8_C( 118),  INT8_C(  52), -INT8_C(  82),  INT8_C(   6), -INT8_C( 120),  INT8_C(  29),
        -INT8_C( 115), -INT8_C(  91), -INT8_C(  30), -INT8_C(  76), -INT8_C(   7), -INT8_C(  69),  INT8_C(  69), -INT8_C( 105),
         INT8_C(  92), -INT8_C(  17), -INT8_C(  85),  INT8_C(  22), -INT8_C(  40),  INT8_C(  96), -INT8_C(  33), -INT8_C(  23) },
      {  INT8_C(  15),  INT8_C(  41), -INT8_C(   1),  INT8_C(  22), -INT8_C( 101), -INT8_C( 116),  INT8_C(  24), -INT8_C(  74),
        -INT8_C(   1), -INT8_C(  89), -INT8_C(  15),  INT8_C(  55), -INT8_C( 106),  INT8_C(  90), -INT8_C( 112),  INT8_C(  83),
         INT8_C( 111), -INT8_C( 121),  INT8_C(  29), -INT8_C(  59),  INT8_C(  39),  INT8_C(  84), -INT8_C(  39), -INT8_C( 112),
        -INT8_C(  98), -INT8_C(  95), -INT8_C(  86),  INT8_C(  20), -INT8_C(  71), -INT8_C(  24), -INT8_C(  75), -INT8_C(  55),
         INT8_C(  17), -INT8_C(  76), -INT8_C(  33), -INT8_C(  84),  INT8_C(  64), -INT8_C(   9),  INT8_C(  98),  INT8_C(  63),
        -INT8_C(  98),  INT8_C(  84),  INT8_C( 118),  INT8_C(  52), -INT8_C(  82),  INT8_C(   6), -INT8_C( 120),  INT8_C(  29),
        -INT8_C( 115), -INT8_C(  91), -INT8_C(  30), -INT8_C(  76), -INT8_C(   7), -INT8_C(  69),  INT8_C(  69), -INT8_C( 105),
         INT8_C(  92), -INT8_C(  17), -INT8_C(  85),  INT8_C(  22), -INT8_C(  40),  INT8_C(  96), -INT8_C(  33), -INT8_C(  23) } },
    { {  INT8_C(  20), -INT8_C(  66), -INT8_C( 106),  INT8_C(  84), -INT8_C(  75), -INT8_C(   8), -INT8_C( 109),  INT8_C(  84),
         INT8_C(  76),  INT8_C(   9), -INT8_C( 120), -INT8_C(   6),  INT8_C(  16),  INT8_C(  16),  INT8_C(  24), -INT8_C(  99),
        -INT8_C(  75), -INT8_C(   6),  INT8_C(  82), -INT8_C(  82), -INT8_C(  74), -INT8_C( 105),  INT8_C(  70),  INT8_C(  18),
        -INT8_C( 122), -INT8_C(  15),  INT8_C(  40),  INT8_C(  94),  INT8_C(  82),  INT8_C(   7),  INT8_C(  72),  INT8_C( 102),
        -INT8_C(  59), -INT8_C(  34), -INT8_C(  69),  INT8_C( 123), -INT8_C(  42),  INT8_C(  78), -INT8_C(  49),  INT8_C(  35),
         INT8_C(  88),  INT8_C(  87),  INT8_C(  29),  INT8_C( 104),  INT8_C( 104),  INT8_C(  53),  INT8_C(   5),  INT8_C(  29),
         INT8_C(  48),  INT8_C(  87), -INT8_C(  52), -INT8_C(  26), -INT8_C(  18),  INT8_C(  18), -INT8_C(   8),  INT8_C( 117),
         INT8_C(   3),  INT8_C(  33), -INT8_C(  45),  INT8_C(  85),  INT8_C(  40),  INT8_C(  27), -INT8_C(  68), -INT8_C(  18) },
      {  INT8_C(  20), -INT8_C(  66), -INT8_C( 106),  INT8_C(  84), -INT8_C(  75), -INT8_C(   8), -INT8_C( 109),  INT8_C(  84),
         INT8_C(  76),  INT8_C(   9), -INT8_C( 120), -INT8_C(   6),  INT8_C(  16),  INT8_C(  16),  INT8_C(  24), -INT8_C(  99),
        -INT8_C(  75), -INT8_C(   6),  INT8_C(  82), -INT8_C(  82), -INT8_C(  74), -INT8_C( 105),  INT8_C(  70),  INT8_C(  18),
        -INT8_C( 122), -INT8_C(  15),  INT8_C(  40),  INT8_C(  94),  INT8_C(  82),  INT8_C(   7),  INT8_C(  72),  INT8_C( 102),
        -INT8_C(  59), -INT8_C(  34), -INT8_C(  69),  INT8_C( 123), -INT8_C(  42),  INT8_C(  78), -INT8_C(  49),  INT8_C(  35),
         INT8_C(  88),  INT8_C(  87),  INT8_C(  29),  INT8_C( 104),  INT8_C( 104),  INT8_C(  53),  INT8_C(   5),  INT8_C(  29),
         INT8_C(  48),  INT8_C(  87), -INT8_C(  52), -INT8_C(  26), -INT8_C(  18),  INT8_C(  18), -INT8_C(   8),  INT8_C( 117),
         INT8_C(   3),  INT8_C(  33), -INT8_C(  45),  INT8_C(  85),  INT8_C(  40),  INT8_C(  27), -INT8_C(  68), -INT8_C(  18) } },
    { { -INT8_C(   7),  INT8_C( 119),  INT8_C( 105), -INT8_C(  48), -INT8_C(  59),  INT8_C(  56), -INT8_C(  13),  INT8_C(  29),
        -INT8_C( 113),  INT8_C(  16), -INT8_C( 123), -INT8_C(   9),  INT8_C(  70), -INT8_C( 117),  INT8_C(  21),  INT8_C( 118),
        -INT8_C(  30), -INT8_C(  31),  INT8_C(  92), -INT8_C(  47), -INT8_C(  13),  INT8_C(  84),  INT8_C(  70), -INT8_C(  10),
         INT8_C( 117),  INT8_C(  25),  INT8_C(  76), -INT8_C(  98),  INT8_C(  53),  INT8_C(   8), -INT8_C( 116),  INT8_C(  46),
             INT8_MAX, -INT8_C(  11), -INT8_C(   2),  INT8_C(  68),  INT8_C(  45), -INT8_C(  15),  INT8_C(  98), -INT8_C(  68),
         INT8_C(   2), -INT8_C(  25), -INT8_C(  76),  INT8_C(  72),  INT8_C( 114), -INT8_C(  55), -INT8_C(  66),  INT8_C(  85),
        -INT8_C(  86),  INT8_C(  26),  INT8_C(  38), -INT8_C(  99),  INT8_C( 110),  INT8_C( 108), -INT8_C( 109), -INT8_C(  28),
        -INT8_C( 123), -INT8_C(  33), -INT8_C( 126), -INT8_C(  70), -INT8_C(  25),  INT8_C(  14), -INT8_C(  23),  INT8_C( 102) },
      { -INT8_C(   7),  INT8_C( 119),  INT8_C( 105), -INT8_C(  48), -INT8_C(  59),  INT8_C(  56), -INT8_C(  13),  INT8_C(  29),
        -INT8_C( 113),  INT8_C(  16), -INT8_C( 123), -INT8_C(   9),  INT8_C(  70), -INT8_C( 117),  INT8_C(  21),  INT8_C( 118),
        -INT8_C(  30), -INT8_C(  31),  INT8_C(  92), -INT8_C(  47), -INT8_C(  13),  INT8_C(  84),  INT8_C(  70), -INT8_C(  10),
         INT8_C( 117),  INT8_C(  25),  INT8_C(  76), -INT8_C(  98),  INT8_C(  53),  INT8_C(   8), -INT8_C( 116),  INT8_C(  46),
             INT8_MAX, -INT8_C(  11), -INT8_C(   2),  INT8_C(  68),  INT8_C(  45), -INT8_C(  15),  INT8_C(  98), -INT8_C(  68),
         INT8_C(   2), -INT8_C(  25), -INT8_C(  76),  INT8_C(  72),  INT8_C( 114), -INT8_C(  55), -INT8_C(  66),  INT8_C(  85),
        -INT8_C(  86),  INT8_C(  26),  INT8_C(  38), -INT8_C(  99),  INT8_C( 110),  INT8_C( 108), -INT8_C( 109), -INT8_C(  28),
        -INT8_C( 123), -INT8_C(  33), -INT8_C( 126), -INT8_C(  70), -INT8_C(  25),  INT8_C(  14), -INT8_C(  23),  INT8_C( 102) } },
    { {  INT8_C(   3), -INT8_C(  25), -INT8_C(  85),  INT8_C(  48), -INT8_C(  39),  INT8_C(  13), -INT8_C(  20), -INT8_C(  37),
        -INT8_C(  12), -INT8_C(  96),  INT8_C(  35),  INT8_C( 103),  INT8_C( 105), -INT8_C(  31), -INT8_C(  68),  INT8_C(  19),
        -INT8_C(   5), -INT8_C(  30), -INT8_C(  80),  INT8_C( 105),  INT8_C(  78),  INT8_C(  68),  INT8_C(  77), -INT8_C(  45),
         INT8_C(  35), -INT8_C(  49), -INT8_C( 114),  INT8_C(  11), -INT8_C(  35),  INT8_C( 119),  INT8_C( 113), -INT8_C(  32),
         INT8_C(  94),  INT8_C(  28),  INT8_C(  16),  INT8_C(  55),  INT8_C(  41), -INT8_C(   3),  INT8_C(  18),  INT8_C(  30),
        -INT8_C(  99),  INT8_C(  53), -INT8_C( 123),  INT8_C(   7),  INT8_C(  22),  INT8_C(  65),  INT8_C(  26),  INT8_C(  17),
         INT8_C(  35), -INT8_C(  53),  INT8_C( 123),  INT8_C( 113),  INT8_C(  15), -INT8_C(  56),  INT8_C(  68),  INT8_C(  50),
        -INT8_C( 104), -INT8_C(  46),  INT8_C(  61),  INT8_C( 117),  INT8_C(  73), -INT8_C(  81),  INT8_C(  86), -INT8_C(  88) },
      {  INT8_C(   3), -INT8_C(  25), -INT8_C(  85),  INT8_C(  48), -INT8_C(  39),  INT8_C(  13), -INT8_C(  20), -INT8_C(  37),
        -INT8_C(  12), -INT8_C(  96),  INT8_C(  35),  INT8_C( 103),  INT8_C( 105), -INT8_C(  31), -INT8_C(  68),  INT8_C(  19),
        -INT8_C(   5), -INT8_C(  30), -INT8_C(  80),  INT8_C( 105),  INT8_C(  78),  INT8_C(  68),  INT8_C(  77), -INT8_C(  45),
         INT8_C(  35), -INT8_C(  49), -INT8_C( 114),  INT8_C(  11), -INT8_C(  35),  INT8_C( 119),  INT8_C( 113), -INT8_C(  32),
         INT8_C(  94),  INT8_C(  28),  INT8_C(  16),  INT8_C(  55),  INT8_C(  41), -INT8_C(   3),  INT8_C(  18),  INT8_C(  30),
        -INT8_C(  99),  INT8_C(  53), -INT8_C( 123),  INT8_C(   7),  INT8_C(  22),  INT8_C(  65),  INT8_C(  26),  INT8_C(  17),
         INT8_C(  35), -INT8_C(  53),  INT8_C( 123),  INT8_C( 113),  INT8_C(  15), -INT8_C(  56),  INT8_C(  68),  INT8_C(  50),
        -INT8_C( 104), -INT8_C(  46),  INT8_C(  61),  INT8_C( 117),  INT8_C(  73), -INT8_C(  81),  INT8_C(  86), -INT8_C(  88) } },
    { { -INT8_C(  53),  INT8_C( 102), -INT8_C(  33), -INT8_C(  11),  INT8_C(  99), -INT8_C(  14),  INT8_C(  19),  INT8_C(   1),
         INT8_C(  39), -INT8_C( 104),  INT8_C(   8),  INT8_C(  62), -INT8_C(  39),  INT8_C(  34),  INT8_C(  79), -INT8_C(   4),
        -INT8_C(  19), -INT8_C(  54),  INT8_C( 109), -INT8_C(   4), -INT8_C( 109), -INT8_C(  79),  INT8_C(  47),  INT8_C(  43),
        -INT8_C( 124),  INT8_C( 108), -INT8_C(  96), -INT8_C(  51),  INT8_C(  27), -INT8_C(  10),  INT8_C( 117), -INT8_C(  25),
         INT8_C(  93),  INT8_C(  85), -INT8_C(  36), -INT8_C(  64),  INT8_C(  71), -INT8_C(  17), -INT8_C(  63),  INT8_C( 110),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(  84),  INT8_C(  96), -INT8_C(  20), -INT8_C(   4),  INT8_C(  92), -INT8_C(  39),
        -INT8_C(  58), -INT8_C(  55), -INT8_C(  42),  INT8_C(  89),  INT8_C( 122),  INT8_C(   5), -INT8_C( 124), -INT8_C(   2),
         INT8_C( 113),  INT8_C(  37), -INT8_C(  52), -INT8_C( 115),  INT8_C(  27),  INT8_C(  65),  INT8_C( 116),  INT8_C( 120) },
      { -INT8_C(  53),  INT8_C( 102), -INT8_C(  33), -INT8_C(  11),  INT8_C(  99), -INT8_C(  14),  INT8_C(  19),  INT8_C(   1),
         INT8_C(  39), -INT8_C( 104),  INT8_C(   8),  INT8_C(  62), -INT8_C(  39),  INT8_C(  34),  INT8_C(  79), -INT8_C(   4),
        -INT8_C(  19), -INT8_C(  54),  INT8_C( 109), -INT8_C(   4), -INT8_C( 109), -INT8_C(  79),  INT8_C(  47),  INT8_C(  43),
        -INT8_C( 124),  INT8_C( 108), -INT8_C(  96), -INT8_C(  51),  INT8_C(  27), -INT8_C(  10),  INT8_C( 117), -INT8_C(  25),
         INT8_C(  93),  INT8_C(  85), -INT8_C(  36), -INT8_C(  64),  INT8_C(  71), -INT8_C(  17), -INT8_C(  63),  INT8_C( 110),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(  84),  INT8_C(  96), -INT8_C(  20), -INT8_C(   4),  INT8_C(  92), -INT8_C(  39),
        -INT8_C(  58), -INT8_C(  55), -INT8_C(  42),  INT8_C(  89),  INT8_C( 122),  INT8_C(   5), -INT8_C( 124), -INT8_C(   2),
         INT8_C( 113),  INT8_C(  37), -INT8_C(  52), -INT8_C( 115),  INT8_C(  27),  INT8_C(  65),  INT8_C( 116),  INT8_C( 120) } },
    { { -INT8_C( 106),  INT8_C(  80),  INT8_C(  57), -INT8_C(  35),  INT8_C(  63), -INT8_C(   6),  INT8_C(  76), -INT8_C(  58),
        -INT8_C(  60), -INT8_C(   8),  INT8_C(  38), -INT8_C(  80), -INT8_C(  12), -INT8_C( 126), -INT8_C( 119), -INT8_C(  69),
         INT8_C(  75),  INT8_C(  95),  INT8_C(  20), -INT8_C(  59),  INT8_C( 100), -INT8_C( 103), -INT8_C(  60), -INT8_C(  42),
        -INT8_C(  66), -INT8_C( 112),  INT8_C(  99), -INT8_C(  39), -INT8_C(  47), -INT8_C(  41),  INT8_C(  82),  INT8_C( 104),
         INT8_C(  39), -INT8_C( 117),  INT8_C(  69),  INT8_C( 102), -INT8_C( 123), -INT8_C( 111),  INT8_C(  44),  INT8_C(  73),
        -INT8_C( 118),  INT8_C(  82), -INT8_C(   7),  INT8_C( 126), -INT8_C(  44), -INT8_C( 125),  INT8_C(  57),  INT8_C(  31),
        -INT8_C(  30),  INT8_C(  78), -INT8_C(  28),  INT8_C(  71), -INT8_C(  25), -INT8_C(  88),  INT8_C(  29), -INT8_C(  91),
         INT8_C(  56),      INT8_MIN,  INT8_C( 126),  INT8_C(  10),  INT8_C(  87), -INT8_C(  48),  INT8_C( 114),  INT8_C( 126) },
      { -INT8_C( 106),  INT8_C(  80),  INT8_C(  57), -INT8_C(  35),  INT8_C(  63), -INT8_C(   6),  INT8_C(  76), -INT8_C(  58),
        -INT8_C(  60), -INT8_C(   8),  INT8_C(  38), -INT8_C(  80), -INT8_C(  12), -INT8_C( 126), -INT8_C( 119), -INT8_C(  69),
         INT8_C(  75),  INT8_C(  95),  INT8_C(  20), -INT8_C(  59),  INT8_C( 100), -INT8_C( 103), -INT8_C(  60), -INT8_C(  42),
        -INT8_C(  66), -INT8_C( 112),  INT8_C(  99), -INT8_C(  39), -INT8_C(  47), -INT8_C(  41),  INT8_C(  82),  INT8_C( 104),
         INT8_C(  39), -INT8_C( 117),  INT8_C(  69),  INT8_C( 102), -INT8_C( 123), -INT8_C( 111),  INT8_C(  44),  INT8_C(  73),
        -INT8_C( 118),  INT8_C(  82), -INT8_C(   7),  INT8_C( 126), -INT8_C(  44), -INT8_C( 125),  INT8_C(  57),  INT8_C(  31),
        -INT8_C(  30),  INT8_C(  78), -INT8_C(  28),  INT8_C(  71), -INT8_C(  25), -INT8_C(  88),  INT8_C(  29), -INT8_C(  91),
         INT8_C(  56),      INT8_MIN,  INT8_C( 126),  INT8_C(  10),  INT8_C(  87), -INT8_C(  48),  INT8_C( 114),  INT8_C( 126) } },
    { {  INT8_C(  91), -INT8_C(  73), -INT8_C(  28), -INT8_C(  31),  INT8_C(  73),  INT8_C(  16),  INT8_C(  42), -INT8_C(  45),
         INT8_C(  98),  INT8_C(  36),  INT8_C(  81),  INT8_C(  54), -INT8_C(  89), -INT8_C( 117),  INT8_C(  85), -INT8_C( 119),
        -INT8_C(  39),  INT8_C(  57), -INT8_C(  48), -INT8_C(  64), -INT8_C(  30), -INT8_C(  19),  INT8_C( 101),  INT8_C(  26),
         INT8_C( 109), -INT8_C(  29),  INT8_C(  36), -INT8_C(  60), -INT8_C(  76), -INT8_C( 106),  INT8_C(  66),  INT8_C(  15),
         INT8_C(  78),  INT8_C(  38), -INT8_C(  16), -INT8_C( 105),  INT8_C(  54),  INT8_C(  27),  INT8_C( 106), -INT8_C( 104),
         INT8_C(  63), -INT8_C(  69), -INT8_C(  50), -INT8_C(  26),  INT8_C(  70),  INT8_C(  35),  INT8_C( 111),  INT8_C(  31),
         INT8_C(  93),  INT8_C(  64), -INT8_C(  33),  INT8_C(  63),  INT8_C(  45),  INT8_C(  68),  INT8_C(  89), -INT8_C( 101),
         INT8_C(  40),  INT8_C( 126),  INT8_C(  95), -INT8_C(  36),  INT8_C(  20), -INT8_C(  94), -INT8_C(  21),  INT8_C(  98) },
      {  INT8_C(  91), -INT8_C(  73), -INT8_C(  28), -INT8_C(  31),  INT8_C(  73),  INT8_C(  16),  INT8_C(  42), -INT8_C(  45),
         INT8_C(  98),  INT8_C(  36),  INT8_C(  81),  INT8_C(  54), -INT8_C(  89), -INT8_C( 117),  INT8_C(  85), -INT8_C( 119),
        -INT8_C(  39),  INT8_C(  57), -INT8_C(  48), -INT8_C(  64), -INT8_C(  30), -INT8_C(  19),  INT8_C( 101),  INT8_C(  26),
         INT8_C( 109), -INT8_C(  29),  INT8_C(  36), -INT8_C(  60), -INT8_C(  76), -INT8_C( 106),  INT8_C(  66),  INT8_C(  15),
         INT8_C(  78),  INT8_C(  38), -INT8_C(  16), -INT8_C( 105),  INT8_C(  54),  INT8_C(  27),  INT8_C( 106), -INT8_C( 104),
         INT8_C(  63), -INT8_C(  69), -INT8_C(  50), -INT8_C(  26),  INT8_C(  70),  INT8_C(  35),  INT8_C( 111),  INT8_C(  31),
         INT8_C(  93),  INT8_C(  64), -INT8_C(  33),  INT8_C(  63),  INT8_C(  45),  INT8_C(  68),  INT8_C(  89), -INT8_C( 101),
         INT8_C(  40),  INT8_C( 126),  INT8_C(  95), -INT8_C(  36),  INT8_C(  20), -INT8_C(  94), -INT8_C(  21),  INT8_C(  98) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i8x64(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = a;

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C(  1628), -INT16_C( 19656), -INT16_C( 13922),  INT16_C(   835), -INT16_C(  2787), -INT16_C( 10395),  INT16_C(  6399),  INT16_C( 11765),
         INT16_C(  4017),  INT16_C( 12521),  INT16_C( 21092), -INT16_C( 30322),  INT16_C(  5175),  INT16_C( 12717), -INT16_C( 28003), -INT16_C(  1686),
        -INT16_C( 23911),  INT16_C( 14252), -INT16_C(  4245), -INT16_C( 30662), -INT16_C( 24604), -INT16_C(  7329),  INT16_C( 21687),  INT16_C( 26897),
        -INT16_C(  1436), -INT16_C( 14183),  INT16_C( 10060), -INT16_C( 31919), -INT16_C(   452), -INT16_C(  9803),  INT16_C(  8081),  INT16_C( 10962) },
      {  INT16_C(  1628), -INT16_C( 19656), -INT16_C( 13922),  INT16_C(   835), -INT16_C(  2787), -INT16_C( 10395),  INT16_C(  6399),  INT16_C( 11765),
         INT16_C(  4017),  INT16_C( 12521),  INT16_C( 21092), -INT16_C( 30322),  INT16_C(  5175),  INT16_C( 12717), -INT16_C( 28003), -INT16_C(  1686),
        -INT16_C( 23911),  INT16_C( 14252), -INT16_C(  4245), -INT16_C( 30662), -INT16_C( 24604), -INT16_C(  7329),  INT16_C( 21687),  INT16_C( 26897),
        -INT16_C(  1436), -INT16_C( 14183),  INT16_C( 10060), -INT16_C( 31919), -INT16_C(   452), -INT16_C(  9803),  INT16_C(  8081),  INT16_C( 10962) } },
    { {  INT16_C( 32450),  INT16_C( 11617), -INT16_C( 25746),  INT16_C( 21174),  INT16_C(  5434), -INT16_C(  3786),  INT16_C( 18282), -INT16_C( 12710),
        -INT16_C(  3263), -INT16_C( 29034), -INT16_C(  6373),  INT16_C( 22289), -INT16_C( 14618),  INT16_C( 30512),  INT16_C(   742), -INT16_C( 22367),
         INT16_C(   640), -INT16_C(  4395), -INT16_C( 29795), -INT16_C( 10431),  INT16_C( 30625),  INT16_C(  3016),  INT16_C(  9150), -INT16_C(    39),
         INT16_C( 28438),  INT16_C( 12685), -INT16_C( 24746),  INT16_C( 15496), -INT16_C( 18331),  INT16_C( 19379),  INT16_C( 21690),  INT16_C( 15347) },
      {  INT16_C( 32450),  INT16_C( 11617), -INT16_C( 25746),  INT16_C( 21174),  INT16_C(  5434), -INT16_C(  3786),  INT16_C( 18282), -INT16_C( 12710),
        -INT16_C(  3263), -INT16_C( 29034), -INT16_C(  6373),  INT16_C( 22289), -INT16_C( 14618),  INT16_C( 30512),  INT16_C(   742), -INT16_C( 22367),
         INT16_C(   640), -INT16_C(  4395), -INT16_C( 29795), -INT16_C( 10431),  INT16_C( 30625),  INT16_C(  3016),  INT16_C(  9150), -INT16_C(    39),
         INT16_C( 28438),  INT16_C( 12685), -INT16_C( 24746),  INT16_C( 15496), -INT16_C( 18331),  INT16_C( 19379),  INT16_C( 21690),  INT16_C( 15347) } },
    { { -INT16_C( 13994), -INT16_C(  3287),  INT16_C( 27220), -INT16_C(  2614), -INT16_C( 27679), -INT16_C( 24832), -INT16_C(  9802), -INT16_C( 13153),
         INT16_C( 11336), -INT16_C( 24578), -INT16_C( 31029),  INT16_C( 12763), -INT16_C( 28865), -INT16_C(  1668),  INT16_C( 28899),  INT16_C( 14900),
         INT16_C( 24121), -INT16_C( 29395), -INT16_C(  1848), -INT16_C( 21885), -INT16_C( 31861),  INT16_C( 16713), -INT16_C(  6051), -INT16_C( 23283),
         INT16_C(  2837), -INT16_C(  8124),  INT16_C(  8338), -INT16_C( 12015), -INT16_C( 29009), -INT16_C( 27958), -INT16_C(     2),  INT16_C( 14284) },
      { -INT16_C( 13994), -INT16_C(  3287),  INT16_C( 27220), -INT16_C(  2614), -INT16_C( 27679), -INT16_C( 24832), -INT16_C(  9802), -INT16_C( 13153),
         INT16_C( 11336), -INT16_C( 24578), -INT16_C( 31029),  INT16_C( 12763), -INT16_C( 28865), -INT16_C(  1668),  INT16_C( 28899),  INT16_C( 14900),
         INT16_C( 24121), -INT16_C( 29395), -INT16_C(  1848), -INT16_C( 21885), -INT16_C( 31861),  INT16_C( 16713), -INT16_C(  6051), -INT16_C( 23283),
         INT16_C(  2837), -INT16_C(  8124),  INT16_C(  8338), -INT16_C( 12015), -INT16_C( 29009), -INT16_C( 27958), -INT16_C(     2),  INT16_C( 14284) } },
    { { -INT16_C(  1443),  INT16_C(  9668),  INT16_C( 18418),  INT16_C( 32207),  INT16_C(  6603),  INT16_C( 10430), -INT16_C( 13567),  INT16_C(  5837),
         INT16_C(  4823),  INT16_C( 27127),  INT16_C(  2098), -INT16_C(  7878),  INT16_C(  1174), -INT16_C( 27533),  INT16_C( 16387),  INT16_C( 24779),
        -INT16_C( 28614),  INT16_C( 11398),  INT16_C( 21975), -INT16_C( 23895),  INT16_C( 26478),  INT16_C( 28874), -INT16_C( 26574),  INT16_C(  2438),
         INT16_C( 32170), -INT16_C(  9102), -INT16_C( 21370),  INT16_C(  7357),  INT16_C( 12465), -INT16_C( 19279),  INT16_C( 31856), -INT16_C( 21995) },
      { -INT16_C(  1443),  INT16_C(  9668),  INT16_C( 18418),  INT16_C( 32207),  INT16_C(  6603),  INT16_C( 10430), -INT16_C( 13567),  INT16_C(  5837),
         INT16_C(  4823),  INT16_C( 27127),  INT16_C(  2098), -INT16_C(  7878),  INT16_C(  1174), -INT16_C( 27533),  INT16_C( 16387),  INT16_C( 24779),
        -INT16_C( 28614),  INT16_C( 11398),  INT16_C( 21975), -INT16_C( 23895),  INT16_C( 26478),  INT16_C( 28874), -INT16_C( 26574),  INT16_C(  2438),
         INT16_C( 32170), -INT16_C(  9102), -INT16_C( 21370),  INT16_C(  7357),  INT16_C( 12465), -INT16_C( 19279),  INT16_C( 31856), -INT16_C( 21995) } },
    { { -INT16_C( 25844), -INT16_C(  6954),  INT16_C( 32752),  INT16_C( 24454),  INT16_C( 20966),  INT16_C(  6607),  INT16_C( 21993), -INT16_C( 27870),
        -INT16_C( 27181),  INT16_C( 22895),  INT16_C( 11329), -INT16_C(  3467),  INT16_C(  9820), -INT16_C( 12889), -INT16_C( 17245), -INT16_C( 20617),
         INT16_C( 20055),  INT16_C( 18323),  INT16_C(  6861), -INT16_C( 19290),  INT16_C( 30059),  INT16_C( 21709), -INT16_C(  4149), -INT16_C( 24857),
         INT16_C( 22148), -INT16_C( 14601),  INT16_C( 27778), -INT16_C(  8520),  INT16_C( 24467),  INT16_C( 13995),  INT16_C(  8987),  INT16_C( 29413) },
      { -INT16_C( 25844), -INT16_C(  6954),  INT16_C( 32752),  INT16_C( 24454),  INT16_C( 20966),  INT16_C(  6607),  INT16_C( 21993), -INT16_C( 27870),
        -INT16_C( 27181),  INT16_C( 22895),  INT16_C( 11329), -INT16_C(  3467),  INT16_C(  9820), -INT16_C( 12889), -INT16_C( 17245), -INT16_C( 20617),
         INT16_C( 20055),  INT16_C( 18323),  INT16_C(  6861), -INT16_C( 19290),  INT16_C( 30059),  INT16_C( 21709), -INT16_C(  4149), -INT16_C( 24857),
         INT16_C( 22148), -INT16_C( 14601),  INT16_C( 27778), -INT16_C(  8520),  INT16_C( 24467),  INT16_C( 13995),  INT16_C(  8987),  INT16_C( 29413) } },
    { {  INT16_C( 31089),  INT16_C( 16058),  INT16_C( 24723), -INT16_C(   270), -INT16_C( 16426), -INT16_C( 24238),  INT16_C( 14767),  INT16_C( 13119),
         INT16_C( 13967),  INT16_C(  4601), -INT16_C( 19806),  INT16_C( 13807), -INT16_C( 25839),  INT16_C( 11627),  INT16_C( 20926),  INT16_C( 12191),
         INT16_C( 22986),  INT16_C( 23917),  INT16_C( 24762), -INT16_C( 28581), -INT16_C( 21217), -INT16_C( 12751),  INT16_C( 28902),  INT16_C( 29954),
        -INT16_C(  1114),  INT16_C( 18566),  INT16_C( 30125), -INT16_C( 16514), -INT16_C(  5872), -INT16_C( 12564), -INT16_C( 29894),  INT16_C(  1277) },
      {  INT16_C( 31089),  INT16_C( 16058),  INT16_C( 24723), -INT16_C(   270), -INT16_C( 16426), -INT16_C( 24238),  INT16_C( 14767),  INT16_C( 13119),
         INT16_C( 13967),  INT16_C(  4601), -INT16_C( 19806),  INT16_C( 13807), -INT16_C( 25839),  INT16_C( 11627),  INT16_C( 20926),  INT16_C( 12191),
         INT16_C( 22986),  INT16_C( 23917),  INT16_C( 24762), -INT16_C( 28581), -INT16_C( 21217), -INT16_C( 12751),  INT16_C( 28902),  INT16_C( 29954),
        -INT16_C(  1114),  INT16_C( 18566),  INT16_C( 30125), -INT16_C( 16514), -INT16_C(  5872), -INT16_C( 12564), -INT16_C( 29894),  INT16_C(  1277) } },
    { {  INT16_C( 27621), -INT16_C( 24735), -INT16_C( 17205), -INT16_C(  5585),  INT16_C( 24681),  INT16_C( 20409), -INT16_C( 17456),  INT16_C( 30404),
         INT16_C( 19126),  INT16_C( 25790),  INT16_C( 15552), -INT16_C( 12253),  INT16_C(  3878),  INT16_C( 24735), -INT16_C( 25446),  INT16_C( 32613),
        -INT16_C( 14841), -INT16_C( 11746),  INT16_C( 19843), -INT16_C(  4931),  INT16_C( 30381),  INT16_C( 32060),  INT16_C(    49), -INT16_C(  6157),
        -INT16_C( 19893),  INT16_C(  2891),  INT16_C( 28398),  INT16_C(  5339),  INT16_C( 31357),  INT16_C(  6261), -INT16_C(  9705),  INT16_C(  7831) },
      {  INT16_C( 27621), -INT16_C( 24735), -INT16_C( 17205), -INT16_C(  5585),  INT16_C( 24681),  INT16_C( 20409), -INT16_C( 17456),  INT16_C( 30404),
         INT16_C( 19126),  INT16_C( 25790),  INT16_C( 15552), -INT16_C( 12253),  INT16_C(  3878),  INT16_C( 24735), -INT16_C( 25446),  INT16_C( 32613),
        -INT16_C( 14841), -INT16_C( 11746),  INT16_C( 19843), -INT16_C(  4931),  INT16_C( 30381),  INT16_C( 32060),  INT16_C(    49), -INT16_C(  6157),
        -INT16_C( 19893),  INT16_C(  2891),  INT16_C( 28398),  INT16_C(  5339),  INT16_C( 31357),  INT16_C(  6261), -INT16_C(  9705),  INT16_C(  7831) } },
    { { -INT16_C( 18784),  INT16_C(  9201), -INT16_C( 20989), -INT16_C( 20208),  INT16_C( 19492),  INT16_C( 21806),  INT16_C(  8780), -INT16_C( 26820),
        -INT16_C( 30508), -INT16_C( 15710),  INT16_C( 32502),  INT16_C( 29911),  INT16_C( 19704),  INT16_C(  3980),  INT16_C(  8998), -INT16_C( 14802),
         INT16_C(  8153), -INT16_C(  8726), -INT16_C(  1331), -INT16_C(  3698), -INT16_C( 17338), -INT16_C( 28090), -INT16_C( 32034), -INT16_C( 19926),
        -INT16_C( 13302),  INT16_C(   373),  INT16_C( 19530),  INT16_C( 17269),  INT16_C(   408), -INT16_C( 16814), -INT16_C( 32732), -INT16_C(   380) },
      { -INT16_C( 18784),  INT16_C(  9201), -INT16_C( 20989), -INT16_C( 20208),  INT16_C( 19492),  INT16_C( 21806),  INT16_C(  8780), -INT16_C( 26820),
        -INT16_C( 30508), -INT16_C( 15710),  INT16_C( 32502),  INT16_C( 29911),  INT16_C( 19704),  INT16_C(  3980),  INT16_C(  8998), -INT16_C( 14802),
         INT16_C(  8153), -INT16_C(  8726), -INT16_C(  1331), -INT16_C(  3698), -INT16_C( 17338), -INT16_C( 28090), -INT16_C( 32034), -INT16_C( 19926),
        -INT16_C( 13302),  INT16_C(   373),  INT16_C( 19530),  INT16_C( 17269),  INT16_C(   408), -INT16_C( 16814), -INT16_C( 32732), -INT16_C(   380) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x32(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = a;

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1085279312),  INT32_C(  1689654203), -INT32_C(  1704027444),  INT32_C(  1992004399),  INT32_C(  1598136076), -INT32_C(  1107314712),  INT32_C(  1634510512),  INT32_C(  2144272078),
        -INT32_C(  1405215247), -INT32_C(    65931984), -INT32_C(  1097433201),  INT32_C(   523522579), -INT32_C(   629246223), -INT32_C(   560497363), -INT32_C(   230751453), -INT32_C(   210694911) },
      { -INT32_C(  1085279312),  INT32_C(  1689654203), -INT32_C(  1704027444),  INT32_C(  1992004399),  INT32_C(  1598136076), -INT32_C(  1107314712),  INT32_C(  1634510512),  INT32_C(  2144272078),
        -INT32_C(  1405215247), -INT32_C(    65931984), -INT32_C(  1097433201),  INT32_C(   523522579), -INT32_C(   629246223), -INT32_C(   560497363), -INT32_C(   230751453), -INT32_C(   210694911) } },
    { {  INT32_C(  1537191723),  INT32_C(   878227620),  INT32_C(  1139994160),  INT32_C(   845293376), -INT32_C(   905125475), -INT32_C(  2102877346), -INT32_C(  1468733529),  INT32_C(   547087861),
         INT32_C(   964377492),  INT32_C(   460182507),  INT32_C(    39739330),  INT32_C(   590659974),  INT32_C(    15614114), -INT32_C(  1954375964),  INT32_C(  1932785278),  INT32_C(  1888735195) },
      {  INT32_C(  1537191723),  INT32_C(   878227620),  INT32_C(  1139994160),  INT32_C(   845293376), -INT32_C(   905125475), -INT32_C(  2102877346), -INT32_C(  1468733529),  INT32_C(   547087861),
         INT32_C(   964377492),  INT32_C(   460182507),  INT32_C(    39739330),  INT32_C(   590659974),  INT32_C(    15614114), -INT32_C(  1954375964),  INT32_C(  1932785278),  INT32_C(  1888735195) } },
    { { -INT32_C(   173470198), -INT32_C(  1542383902), -INT32_C(    56201355), -INT32_C(   769664208), -INT32_C(     2945765),  INT32_C(   579491236),  INT32_C(   664125004), -INT32_C(  1751701363),
         INT32_C(   411844662), -INT32_C(   860054186),  INT32_C(  1036542733),  INT32_C(  1494279998), -INT32_C(  1722162187), -INT32_C(  2068061384),  INT32_C(   783044769), -INT32_C(  1362803848) },
      { -INT32_C(   173470198), -INT32_C(  1542383902), -INT32_C(    56201355), -INT32_C(   769664208), -INT32_C(     2945765),  INT32_C(   579491236),  INT32_C(   664125004), -INT32_C(  1751701363),
         INT32_C(   411844662), -INT32_C(   860054186),  INT32_C(  1036542733),  INT32_C(  1494279998), -INT32_C(  1722162187), -INT32_C(  2068061384),  INT32_C(   783044769), -INT32_C(  1362803848) } },
    { { -INT32_C(   624471420), -INT32_C(    56196113),  INT32_C(   607809254),  INT32_C(  1266567766),  INT32_C(  1709496109),  INT32_C(  1558880186),  INT32_C(  1737135855),  INT32_C(  1561678041),
        -INT32_C(  1858544478),  INT32_C(  1183768160), -INT32_C(  1553217459),  INT32_C(  1072621842),  INT32_C(  2057622208),  INT32_C(  1624673905), -INT32_C(    20487900),  INT32_C(  1398529201) },
      { -INT32_C(   624471420), -INT32_C(    56196113),  INT32_C(   607809254),  INT32_C(  1266567766),  INT32_C(  1709496109),  INT32_C(  1558880186),  INT32_C(  1737135855),  INT32_C(  1561678041),
        -INT32_C(  1858544478),  INT32_C(  1183768160), -INT32_C(  1553217459),  INT32_C(  1072621842),  INT32_C(  2057622208),  INT32_C(  1624673905), -INT32_C(    20487900),  INT32_C(  1398529201) } },
    { {  INT32_C(   434410425), -INT32_C(  1084263822),  INT32_C(  1281542714),  INT32_C(  1938510003), -INT32_C(  1813106654), -INT32_C(   470563650), -INT32_C(   689849819),  INT32_C(  1328102550),
         INT32_C(  1114115792), -INT32_C(  1157511040),  INT32_C(  1174889362), -INT32_C(   709258317), -INT32_C(  2123847741), -INT32_C(  1855693972), -INT32_C(  1419229931),  INT32_C(  1392218498) },
      {  INT32_C(   434410425), -INT32_C(  1084263822),  INT32_C(  1281542714),  INT32_C(  1938510003), -INT32_C(  1813106654), -INT32_C(   470563650), -INT32_C(   689849819),  INT32_C(  1328102550),
         INT32_C(  1114115792), -INT32_C(  1157511040),  INT32_C(  1174889362), -INT32_C(   709258317), -INT32_C(  2123847741), -INT32_C(  1855693972), -INT32_C(  1419229931),  INT32_C(  1392218498) } },
    { {  INT32_C(   546595743), -INT32_C(  1092905685), -INT32_C(  1425743112),  INT32_C(   947961205), -INT32_C(   776279963),  INT32_C(  1482825283), -INT32_C(   435959196), -INT32_C(    80150948),
        -INT32_C(  1927558046),  INT32_C(  1498150497),  INT32_C(  1308905433),  INT32_C(  1921483789), -INT32_C(  1354546836), -INT32_C(  1022909089), -INT32_C(   861336976),  INT32_C(  1808261385) },
      {  INT32_C(   546595743), -INT32_C(  1092905685), -INT32_C(  1425743112),  INT32_C(   947961205), -INT32_C(   776279963),  INT32_C(  1482825283), -INT32_C(   435959196), -INT32_C(    80150948),
        -INT32_C(  1927558046),  INT32_C(  1498150497),  INT32_C(  1308905433),  INT32_C(  1921483789), -INT32_C(  1354546836), -INT32_C(  1022909089), -INT32_C(   861336976),  INT32_C(  1808261385) } },
    { {  INT32_C(   251192237), -INT32_C(  1301855015), -INT32_C(  1610519661),  INT32_C(  1527941359),  INT32_C(   671765961),  INT32_C(  1810633211),  INT32_C(   624399644),  INT32_C(   613482103),
        -INT32_C(  1154250527),  INT32_C(  1617795788), -INT32_C(   184521210), -INT32_C(  1085205514),  INT32_C(  1676172136), -INT32_C(  1982933907), -INT32_C(   525466263), -INT32_C(   452641276) },
      {  INT32_C(   251192237), -INT32_C(  1301855015), -INT32_C(  1610519661),  INT32_C(  1527941359),  INT32_C(   671765961),  INT32_C(  1810633211),  INT32_C(   624399644),  INT32_C(   613482103),
        -INT32_C(  1154250527),  INT32_C(  1617795788), -INT32_C(   184521210), -INT32_C(  1085205514),  INT32_C(  1676172136), -INT32_C(  1982933907), -INT32_C(   525466263), -INT32_C(   452641276) } },
    { { -INT32_C(  1818216250), -INT32_C(   655159598),  INT32_C(  1942942588),  INT32_C(  1865555718), -INT32_C(   405661062),  INT32_C(  1483776494), -INT32_C(  1439162714),  INT32_C(   596655452),
         INT32_C(  1219899509), -INT32_C(  1155487426), -INT32_C(  1557205348), -INT32_C(  2012061683),  INT32_C(  1768940667),  INT32_C(   750903429),  INT32_C(  1540815614), -INT32_C(  1384225225) },
      { -INT32_C(  1818216250), -INT32_C(   655159598),  INT32_C(  1942942588),  INT32_C(  1865555718), -INT32_C(   405661062),  INT32_C(  1483776494), -INT32_C(  1439162714),  INT32_C(   596655452),
         INT32_C(  1219899509), -INT32_C(  1155487426), -INT32_C(  1557205348), -INT32_C(  2012061683),  INT32_C(  1768940667),  INT32_C(   750903429),  INT32_C(  1540815614), -INT32_C(  1384225225) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x16(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = a;

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 2031689546876671122), -INT64_C( 4181824216786536295),  INT64_C( 3378378289711491617),  INT64_C( 1413316256384642707),
        -INT64_C( 4698950795030485050),  INT64_C( 7475600748512024817), -INT64_C( 2293462173326056235),  INT64_C( 2603685720003003242) },
      { -INT64_C( 2031689546876671122), -INT64_C( 4181824216786536295),  INT64_C( 3378378289711491617),  INT64_C( 1413316256384642707),
        -INT64_C( 4698950795030485050),  INT64_C( 7475600748512024817), -INT64_C( 2293462173326056235),  INT64_C( 2603685720003003242) } },
    { {  INT64_C( 4049249843808980558),  INT64_C( 7392641815426491883),  INT64_C( 1801878204460544724), -INT64_C(   48330471621752111),
         INT64_C( 2024547467117354649),  INT64_C( 1044804576756910729),  INT64_C( 4782031642370761366),  INT64_C( 7668159918304822970) },
      {  INT64_C( 4049249843808980558),  INT64_C( 7392641815426491883),  INT64_C( 1801878204460544724), -INT64_C(   48330471621752111),
         INT64_C( 2024547467117354649),  INT64_C( 1044804576756910729),  INT64_C( 4782031642370761366),  INT64_C( 7668159918304822970) } },
    { {  INT64_C(  680433322035960868),  INT64_C( 4032026382637907372),  INT64_C( 1024807869850854276), -INT64_C( 7738621839182026145),
        -INT64_C(  916101787114937152), -INT64_C( 7858554787118552041), -INT64_C( 6533667226337645326),  INT64_C( 8173594282907061610) },
      {  INT64_C(  680433322035960868),  INT64_C( 4032026382637907372),  INT64_C( 1024807869850854276), -INT64_C( 7738621839182026145),
        -INT64_C(  916101787114937152), -INT64_C( 7858554787118552041), -INT64_C( 6533667226337645326),  INT64_C( 8173594282907061610) } },
    { { -INT64_C( 3994697604197623979),  INT64_C( 3028796336221808999), -INT64_C( 4986958888383311650),  INT64_C( 7327921812528210064),
        -INT64_C( 4048013273381903271), -INT64_C( 6603326236083268358),  INT64_C( 2296716578005830869), -INT64_C( 3555290135981427917) },
      { -INT64_C( 3994697604197623979),  INT64_C( 3028796336221808999), -INT64_C( 4986958888383311650),  INT64_C( 7327921812528210064),
        -INT64_C( 4048013273381903271), -INT64_C( 6603326236083268358),  INT64_C( 2296716578005830869), -INT64_C( 3555290135981427917) } },
    { {  INT64_C( 3935770298369485431), -INT64_C(  762861917337756674), -INT64_C(  558453203728190831),  INT64_C( 2931813335080607596),
         INT64_C( 3458938454811838351), -INT64_C( 4643389136534410887),  INT64_C( 1174628764682791568), -INT64_C(  245550163283572547) },
      {  INT64_C( 3935770298369485431), -INT64_C(  762861917337756674), -INT64_C(  558453203728190831),  INT64_C( 2931813335080607596),
         INT64_C( 3458938454811838351), -INT64_C( 4643389136534410887),  INT64_C( 1174628764682791568), -INT64_C(  245550163283572547) } },
    { { -INT64_C( 5869378661672118744),  INT64_C( 7934735468561203248), -INT64_C( 2939425477300585343), -INT64_C( 1152397282285115752),
        -INT64_C( 4659583426481174413), -INT64_C(  675194194085700267),  INT64_C(  947814707075179574), -INT64_C( 4886946240843846537) },
      { -INT64_C( 5869378661672118744),  INT64_C( 7934735468561203248), -INT64_C( 2939425477300585343), -INT64_C( 1152397282285115752),
        -INT64_C( 4659583426481174413), -INT64_C(  675194194085700267),  INT64_C(  947814707075179574), -INT64_C( 4886946240843846537) } },
    { { -INT64_C( 6617272956007253540), -INT64_C( 5205464620909246634), -INT64_C( 6530450158184309283),  INT64_C( 7034361509239288218),
         INT64_C( 1332492355739845515), -INT64_C( 6091786111122778819),  INT64_C( 4994593874853592189), -INT64_C( 3335539744629574450) },
      { -INT64_C( 6617272956007253540), -INT64_C( 5205464620909246634), -INT64_C( 6530450158184309283),  INT64_C( 7034361509239288218),
         INT64_C( 1332492355739845515), -INT64_C( 6091786111122778819),  INT64_C( 4994593874853592189), -INT64_C( 3335539744629574450) } },
    { { -INT64_C( 5361209383270579765), -INT64_C( 7640663431528024195),  INT64_C( 2185812967214347366),  INT64_C( 1286946775314366149),
         INT64_C( 3158766812587919016), -INT64_C( 7397886743846434135), -INT64_C( 1382324539653187999),  INT64_C( 1284884244920222333) },
      { -INT64_C( 5361209383270579765), -INT64_C( 7640663431528024195),  INT64_C( 2185812967214347366),  INT64_C( 1286946775314366149),
         INT64_C( 3158766812587919016), -INT64_C( 7397886743846434135), -INT64_C( 1382324539653187999),  INT64_C( 1284884244920222333) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x8(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = a;

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu32(UINT32_C(2465927924), UINT32_C(3593197775), UINT32_C( 612910812), UINT32_C(3812769805),
                              UINT32_C(4149829677), UINT32_C(3483799324), UINT32_C(1459962882), UINT32_C(4149819515),
                              UINT32_C(2650201844), UINT32_C( 758753621), UINT32_C(1440172455), UINT32_C(1093653043),
                              UINT32_C(4135659774), UINT32_C(2249292246), UINT32_C(3926208727), UINT32_C( 363227362)),
      simde_x_mm512_set_epu32(UINT32_C(2465927924), UINT32_C(3593197775), UINT32_C( 612910812), UINT32_C(3812769805),
                              UINT32_C(4149829677), UINT32_C(3483799324), UINT32_C(1459962882), UINT32_C(4149819515),
                              UINT32_C(2650201844), UINT32_C( 758753621), UINT32_C(1440172455), UINT32_C(1093653043),
                              UINT32_C(4135659774), UINT32_C(2249292246), UINT32_C(3926208727), UINT32_C( 363227362)) },
    { simde_x_mm512_set_epu32(UINT32_C( 468967701), UINT32_C(1464888328), UINT32_C(2623912787), UINT32_C(3584306317),
                              UINT32_C(3441172772), UINT32_C(1957813224), UINT32_C(3956090282), UINT32_C(2819645236),
                              UINT32_C(2119397630), UINT32_C(3325357179), UINT32_C( 910080153), UINT32_C(3698201489),
                              UINT32_C(3945376801), UINT32_C(2699586726), UINT32_C(1169343086), UINT32_C(2983594096)),
      simde_x_mm512_set_epu32(UINT32_C( 468967701), UINT32_C(1464888328), UINT32_C(2623912787), UINT32_C(3584306317),
                              UINT32_C(3441172772), UINT32_C(1957813224), UINT32_C(3956090282), UINT32_C(2819645236),
                              UINT32_C(2119397630), UINT32_C(3325357179), UINT32_C( 910080153), UINT32_C(3698201489),
                              UINT32_C(3945376801), UINT32_C(2699586726), UINT32_C(1169343086), UINT32_C(2983594096)) },
    { simde_x_mm512_set_epu32(UINT32_C(3220925730), UINT32_C(4163700514), UINT32_C( 208162340), UINT32_C(  72282893),
                              UINT32_C(2784701415), UINT32_C(2960668076), UINT32_C(2280551509), UINT32_C( 511971347),
                              UINT32_C(3142311802), UINT32_C(3582165504), UINT32_C(3533175269), UINT32_C(3138584679),
                              UINT32_C(3117232701), UINT32_C(1582887517), UINT32_C(2957127939), UINT32_C(3388466484)),
      simde_x_mm512_set_epu32(UINT32_C(3220925730), UINT32_C(4163700514), UINT32_C( 208162340), UINT32_C(  72282893),
                              UINT32_C(2784701415), UINT32_C(2960668076), UINT32_C(2280551509), UINT32_C( 511971347),
                              UINT32_C(3142311802), UINT32_C(3582165504), UINT32_C(3533175269), UINT32_C(3138584679),
                              UINT32_C(3117232701), UINT32_C(1582887517), UINT32_C(2957127939), UINT32_C(3388466484)) },
    { simde_x_mm512_set_epu32(UINT32_C(2382371522), UINT32_C(  66180421), UINT32_C(3915007092), UINT32_C(3548556152),
                              UINT32_C(3063171483), UINT32_C( 175336822), UINT32_C(2621074902), UINT32_C(2785523281),
                              UINT32_C(3351907467), UINT32_C(3611626580), UINT32_C(3274777282), UINT32_C(2819588991),
                              UINT32_C(4142757399), UINT32_C(3841212820), UINT32_C(1375549108), UINT32_C(3217099434)),
      simde_x_mm512_set_epu32(UINT32_C(2382371522), UINT32_C(  66180421), UINT32_C(3915007092), UINT32_C(3548556152),
                              UINT32_C(3063171483), UINT32_C( 175336822), UINT32_C(2621074902), UINT32_C(2785523281),
                              UINT32_C(3351907467), UINT32_C(3611626580), UINT32_C(3274777282), UINT32_C(2819588991),
                              UINT32_C(4142757399), UINT32_C(3841212820), UINT32_C(1375549108), UINT32_C(3217099434)) },
    { simde_x_mm512_set_epu32(UINT32_C(1625945136), UINT32_C(  82950125), UINT32_C(3598722192), UINT32_C(2456005821),
                              UINT32_C(3054050921), UINT32_C(3350002014), UINT32_C(1546778759), UINT32_C(3175686900),
                              UINT32_C(3418645543), UINT32_C(1247476579), UINT32_C(2559569107), UINT32_C(3884223622),
                              UINT32_C(2206347705), UINT32_C(1195297710), UINT32_C(4206427691), UINT32_C(2187435296)),
      simde_x_mm512_set_epu32(UINT32_C(1625945136), UINT32_C(  82950125), UINT32_C(3598722192), UINT32_C(2456005821),
                              UINT32_C(3054050921), UINT32_C(3350002014), UINT32_C(1546778759), UINT32_C(3175686900),
                              UINT32_C(3418645543), UINT32_C(1247476579), UINT32_C(2559569107), UINT32_C(3884223622),
                              UINT32_C(2206347705), UINT32_C(1195297710), UINT32_C(4206427691), UINT32_C(2187435296)) },
    { simde_x_mm512_set_epu32(UINT32_C(3055114510), UINT32_C( 314498376), UINT32_C( 259740532), UINT32_C(2845634146),
                              UINT32_C(3528445754), UINT32_C(1438308061), UINT32_C(1618483487), UINT32_C(4280155704),
                              UINT32_C(4191548278), UINT32_C( 955760205), UINT32_C(3071952989), UINT32_C(3353486020),
                              UINT32_C(3091053226), UINT32_C(2241572393), UINT32_C(3491849165), UINT32_C(2750648051)),
      simde_x_mm512_set_epu32(UINT32_C(3055114510), UINT32_C( 314498376), UINT32_C( 259740532), UINT32_C(2845634146),
                              UINT32_C(3528445754), UINT32_C(1438308061), UINT32_C(1618483487), UINT32_C(4280155704),
                              UINT32_C(4191548278), UINT32_C( 955760205), UINT32_C(3071952989), UINT32_C(3353486020),
                              UINT32_C(3091053226), UINT32_C(2241572393), UINT32_C(3491849165), UINT32_C(2750648051)) },
    { simde_x_mm512_set_epu32(UINT32_C(2791699552), UINT32_C(1697626027), UINT32_C(3068022880), UINT32_C( 492436222),
                              UINT32_C(2413088982), UINT32_C(1530446668), UINT32_C(1370127960), UINT32_C(2402932897),
                              UINT32_C(4061542194), UINT32_C( 154485056), UINT32_C(3577835063), UINT32_C(3500138573),
                              UINT32_C(  48074834), UINT32_C(1773313389), UINT32_C(3571862316), UINT32_C(1059958902)),
      simde_x_mm512_set_epu32(UINT32_C(2791699552), UINT32_C(1697626027), UINT32_C(3068022880), UINT32_C( 492436222),
                              UINT32_C(2413088982), UINT32_C(1530446668), UINT32_C(1370127960), UINT32_C(2402932897),
                              UINT32_C(4061542194), UINT32_C( 154485056), UINT32_C(3577835063), UINT32_C(3500138573),
                              UINT32_C(  48074834), UINT32_C(1773313389), UINT32_C(3571862316), UINT32_C(1059958902)) },
    { simde_x_mm512_set_epu32(UINT32_C(1166001194), UINT32_C( 115042765), UINT32_C( 557502548), UINT32_C(2408114255),
                              UINT32_C( 870354895), UINT32_C( 955362708), UINT32_C(1149136654), UINT32_C(1920883489),
                              UINT32_C(3238897491), UINT32_C(1952390233), UINT32_C( 223001918), UINT32_C( 310736118),
                              UINT32_C(2747509005), UINT32_C( 134376306), UINT32_C(1234549716), UINT32_C( 594304164)),
      simde_x_mm512_set_epu32(UINT32_C(1166001194), UINT32_C( 115042765), UINT32_C( 557502548), UINT32_C(2408114255),
                              UINT32_C( 870354895), UINT32_C( 955362708), UINT32_C(1149136654), UINT32_C(1920883489),
                              UINT32_C(3238897491), UINT32_C(1952390233), UINT32_C( 223001918), UINT32_C( 310736118),
                              UINT32_C(2747509005), UINT32_C( 134376306), UINT32_C(1234549716), UINT32_C( 594304164)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_loadu_si512(&(test_vec[i].a));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_si512)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
