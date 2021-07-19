#define SIMDE_TEST_X86_AVX512_INSN popcnt

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/popcnt.h>

static int
test_simde_mm_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  95), -INT8_C( 112),  INT8_C(  35),  INT8_C(  57),  INT8_C( 117), -INT8_C(  49),  INT8_C(  91), -INT8_C( 116),
         INT8_C(  48), -INT8_C(  74), -INT8_C(  33),  INT8_C(  26),  INT8_C(  20), -INT8_C( 110), -INT8_C(  77),  INT8_C( 125) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   7),  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6) } },
    { {  INT8_C(   4),  INT8_C(   1),  INT8_C(  71), -INT8_C(  23), -INT8_C(  44),  INT8_C(   8), -INT8_C(   5), -INT8_C(  69),
         INT8_C(  21), -INT8_C(   3),  INT8_C(  44),  INT8_C(  97),  INT8_C(  81), -INT8_C(  14),  INT8_C( 125), -INT8_C(  13) },
      {  INT8_C(   1),  INT8_C(   1),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   7),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6) } },
    { { -INT8_C( 125), -INT8_C(  96),  INT8_C(  44), -INT8_C(   8),  INT8_C( 111), -INT8_C( 121), -INT8_C( 124), -INT8_C(  97),
         INT8_C(  62),  INT8_C(  99), -INT8_C(  70),  INT8_C(  82), -INT8_C(  11),  INT8_C( 109), -INT8_C(  48), -INT8_C(   7) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),  INT8_C(   6) } },
    { {  INT8_C( 110),  INT8_C(  23), -INT8_C(  30),  INT8_C(  67),  INT8_C(  31), -INT8_C(  35), -INT8_C(   2),  INT8_C(  53),
        -INT8_C(  37),  INT8_C(  42), -INT8_C( 106),  INT8_C(  44),  INT8_C(  29),  INT8_C(  19),  INT8_C(  31), -INT8_C(  96) },
      {  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   7),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   2) } },
    { { -INT8_C(  76),  INT8_C(  75), -INT8_C( 104),  INT8_C(  35), -INT8_C(  45),  INT8_C(  28), -INT8_C(  61),  INT8_C(  17),
             INT8_MIN,  INT8_C( 125),  INT8_C(  99),  INT8_C( 117), -INT8_C(  22),  INT8_C(  51),  INT8_C( 111),  INT8_C(  88) },
      {  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),
         INT8_C(   1),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3) } },
    { {  INT8_C(  75),  INT8_C(  81), -INT8_C( 101),  INT8_C( 106),  INT8_C(  47), -INT8_C( 102), -INT8_C(  97),  INT8_C(  10),
        -INT8_C(  60),  INT8_C(  53),  INT8_C(  54), -INT8_C(  31),  INT8_C(  73),  INT8_C(  86), -INT8_C( 127), -INT8_C(   3) },
      {  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   7) } },
    { { -INT8_C(  95),  INT8_C(  25),  INT8_C(  32),  INT8_C( 116),  INT8_C(  54), -INT8_C(  29), -INT8_C( 123), -INT8_C(  74),
         INT8_C(  96), -INT8_C(  23),  INT8_C(  43),  INT8_C(  74),  INT8_C(  28), -INT8_C( 102), -INT8_C(  93),  INT8_C( 103) },
      {  INT8_C(   3),  INT8_C(   3),  INT8_C(   1),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5) } },
    { { -INT8_C(  20),  INT8_C(  62), -INT8_C(  46),  INT8_C(  27), -INT8_C(  40),  INT8_C( 113),  INT8_C(  37), -INT8_C(  99),
        -INT8_C(  89),  INT8_C(  91),  INT8_C( 126), -INT8_C(  16), -INT8_C(  79),  INT8_C(   0), -INT8_C(  19),  INT8_C(  83) },
      {  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   0),  INT8_C(   6),  INT8_C(   4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_popcnt_epi8(a);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_popcnt_epi8(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  96), -INT8_C(  15), -INT8_C(  58), -INT8_C(  70), -INT8_C(  29),  INT8_C(  39),  INT8_C(  94), -INT8_C(  67),
        -INT8_C(  28), -INT8_C(  71), -INT8_C(  37), -INT8_C(  96), -INT8_C(  58),  INT8_C(  28), -INT8_C(  94),  INT8_C(  29) },
      UINT16_C(22462),
      {  INT8_C(   0), -INT8_C(  17),  INT8_C(  93),  INT8_C( 100),  INT8_C(  75), -INT8_C(  23),  INT8_C(  75), -INT8_C(  98),
         INT8_C(  29),  INT8_C(  40),  INT8_C(  57),  INT8_C(  88), -INT8_C(  67), -INT8_C(  39),  INT8_C(  74), -INT8_C( 125) },
      { -INT8_C(  96),  INT8_C(   7),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(  94),  INT8_C(   5),
         INT8_C(   4),  INT8_C(   2),  INT8_C(   4), -INT8_C(  96),  INT8_C(   6),  INT8_C(  28),  INT8_C(   3),  INT8_C(  29) } },
    { { -INT8_C( 108),  INT8_C(  45), -INT8_C(  86), -INT8_C(  14), -INT8_C(  22), -INT8_C( 113), -INT8_C(  85), -INT8_C(  59),
         INT8_C(  47),  INT8_C( 113), -INT8_C(  31), -INT8_C(  47), -INT8_C( 114), -INT8_C(  97),  INT8_C(  41), -INT8_C( 114) },
      UINT16_C(34447),
      { -INT8_C(  14), -INT8_C(  38),  INT8_C( 111),  INT8_C(  62),  INT8_C( 121), -INT8_C( 116),  INT8_C( 102), -INT8_C(  78),
        -INT8_C(  28),  INT8_C(  36), -INT8_C( 116),  INT8_C(  46), -INT8_C(  89),  INT8_C(  32),  INT8_C(  91),  INT8_C(  82) },
      {  INT8_C(   5),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5), -INT8_C(  22), -INT8_C( 113), -INT8_C(  85),  INT8_C(   4),
         INT8_C(  47),  INT8_C(   2),  INT8_C(   3), -INT8_C(  47), -INT8_C( 114), -INT8_C(  97),  INT8_C(  41),  INT8_C(   3) } },
    { {  INT8_C(  18),  INT8_C(  69), -INT8_C(  31), -INT8_C(  67),  INT8_C(  10),  INT8_C(  16),  INT8_C(  46), -INT8_C(  20),
        -INT8_C(  31), -INT8_C(  68), -INT8_C( 117),  INT8_C(  10),  INT8_C(  74),  INT8_C(  26), -INT8_C( 112),  INT8_C(  60) },
      UINT16_C(65525),
      {  INT8_C( 122),  INT8_C( 110), -INT8_C( 117), -INT8_C(  31),  INT8_C(  32),  INT8_C( 112),  INT8_C(   5), -INT8_C(  84),
        -INT8_C(  98), -INT8_C(  84), -INT8_C(  52), -INT8_C(   6), -INT8_C(   2), -INT8_C(  34),  INT8_C(  63), -INT8_C(  33) },
      {  INT8_C(   5),  INT8_C(  69),  INT8_C(   4), -INT8_C(  67),  INT8_C(   1),  INT8_C(   3),  INT8_C(   2),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6),  INT8_C(   7),  INT8_C(   6),  INT8_C(   6),  INT8_C(   7) } },
    { { -INT8_C( 101),  INT8_C(  74), -INT8_C(  17), -INT8_C(  55),  INT8_C(  54), -INT8_C(  47), -INT8_C( 123), -INT8_C(  63),
        -INT8_C(  37), -INT8_C(  49), -INT8_C(  36),  INT8_C( 108),  INT8_C(  12), -INT8_C(  47),  INT8_C( 107), -INT8_C( 122) },
      UINT16_C(63295),
      {  INT8_C( 103),  INT8_C(  95),  INT8_C( 103),  INT8_C( 108),  INT8_C(  12),  INT8_C(   5),  INT8_C(  25), -INT8_C(  40),
        -INT8_C(   1),  INT8_C(  23), -INT8_C(  73),  INT8_C(  63), -INT8_C(   9),  INT8_C(  82), -INT8_C( 119), -INT8_C(  26) },
      {  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   2), -INT8_C( 123), -INT8_C(  63),
         INT8_C(   8),  INT8_C(   4),  INT8_C(   6),  INT8_C( 108),  INT8_C(   7),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5) } },
    { {  INT8_C(  28), -INT8_C(  65), -INT8_C(  73), -INT8_C(  95),      INT8_MIN, -INT8_C( 109),  INT8_C( 113),  INT8_C(  92),
        -INT8_C(   1),  INT8_C( 125),  INT8_C(  45),  INT8_C( 106),  INT8_C(   3),  INT8_C( 108),  INT8_C(  97),  INT8_C( 107) },
      UINT16_C(51404),
      { -INT8_C(  41), -INT8_C(  40), -INT8_C(  50), -INT8_C(  16), -INT8_C(  80), -INT8_C(  51),  INT8_C(   8),  INT8_C( 103),
         INT8_C(  12), -INT8_C(   1), -INT8_C(  70), -INT8_C( 107), -INT8_C(  27), -INT8_C(  42),  INT8_C(  84), -INT8_C(  99) },
      {  INT8_C(  28), -INT8_C(  65),  INT8_C(   5),  INT8_C(   4),      INT8_MIN, -INT8_C( 109),  INT8_C(   1),  INT8_C(   5),
        -INT8_C(   1),  INT8_C( 125),  INT8_C(  45),  INT8_C(   4),  INT8_C(   3),  INT8_C( 108),  INT8_C(   3),  INT8_C(   5) } },
    { {  INT8_C( 119), -INT8_C(  43),  INT8_C(  48), -INT8_C(  24),  INT8_C(  49),  INT8_C(  47),  INT8_C( 101),  INT8_C(  95),
        -INT8_C( 103),  INT8_C( 105), -INT8_C(  53), -INT8_C(   5), -INT8_C(  44), -INT8_C( 105), -INT8_C(  61), -INT8_C(  85) },
      UINT16_C(37231),
      { -INT8_C( 100),  INT8_C(  32),  INT8_C(  95), -INT8_C(  92), -INT8_C( 121),  INT8_C( 107), -INT8_C(  93),  INT8_C(  65),
         INT8_C(   1), -INT8_C( 120),  INT8_C(  23),  INT8_C(  85),  INT8_C(  37), -INT8_C( 113),  INT8_C(  42),  INT8_C(  85) },
      {  INT8_C(   4),  INT8_C(   1),  INT8_C(   6),  INT8_C(   3),  INT8_C(  49),  INT8_C(   5),  INT8_C(   4),  INT8_C(  95),
         INT8_C(   1),  INT8_C( 105), -INT8_C(  53), -INT8_C(   5),  INT8_C(   3), -INT8_C( 105), -INT8_C(  61),  INT8_C(   4) } },
    { {  INT8_C( 119),  INT8_C(  92), -INT8_C( 124), -INT8_C(  35), -INT8_C(  69),  INT8_C(  30),  INT8_C(  70), -INT8_C( 122),
         INT8_C(  25),  INT8_C(  26),  INT8_C(  30), -INT8_C(  36), -INT8_C(  59), -INT8_C( 115),  INT8_C( 110),  INT8_C(  97) },
      UINT16_C(52653),
      {  INT8_C(   5),  INT8_C(  53),  INT8_C(  56), -INT8_C(  88),  INT8_C( 118),  INT8_C(  57),  INT8_C(  49), -INT8_C( 114),
        -INT8_C( 113),  INT8_C(  86),  INT8_C(  29), -INT8_C(  71), -INT8_C(  84), -INT8_C( 108),  INT8_C(  21),  INT8_C(  48) },
      {  INT8_C(   2),  INT8_C(  92),  INT8_C(   3),  INT8_C(   3), -INT8_C(  69),  INT8_C(   4),  INT8_C(  70),  INT8_C(   4),
         INT8_C(   5),  INT8_C(  26),  INT8_C(   4),  INT8_C(   5), -INT8_C(  59), -INT8_C( 115),  INT8_C(   3),  INT8_C(   2) } },
    { {  INT8_C( 113), -INT8_C(  48),  INT8_C(  78), -INT8_C(  73),  INT8_C(  87),  INT8_C( 103), -INT8_C(  47),  INT8_C( 117),
         INT8_C(  68), -INT8_C( 105),  INT8_C(   2), -INT8_C(  78), -INT8_C(   8), -INT8_C(  80),      INT8_MAX, -INT8_C(   2) },
      UINT16_C(47077),
      { -INT8_C(  90),  INT8_C(  91), -INT8_C(  15), -INT8_C(  41), -INT8_C(  23),      INT8_MIN,  INT8_C(  46),  INT8_C(   6),
         INT8_C(  57), -INT8_C(  38), -INT8_C( 101),  INT8_C(  79),  INT8_C(  10),  INT8_C(  12),  INT8_C(  31),  INT8_C(  89) },
      {  INT8_C(   4), -INT8_C(  48),  INT8_C(   5), -INT8_C(  73),  INT8_C(  87),  INT8_C(   1),  INT8_C(   4),  INT8_C(   2),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   5), -INT8_C(  78),  INT8_C(   2),  INT8_C(   2),      INT8_MAX,  INT8_C(   4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_mask_popcnt_epi8(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i8x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask_popcnt_epi8(src, k, a);

    simde_test_x86_write_i8x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(30404),
      { -INT8_C(  64), -INT8_C( 107), -INT8_C(  21),  INT8_C(   4),  INT8_C(  44), -INT8_C(  18), -INT8_C(  74),  INT8_C(  37),
        -INT8_C(  98),  INT8_C(  53),  INT8_C(  35), -INT8_C( 125), -INT8_C(  19), -INT8_C(  55), -INT8_C(  34), -INT8_C(  34) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   3),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   4),  INT8_C(   6),  INT8_C(   0) } },
    { UINT16_C(51361),
      {  INT8_C(  94), -INT8_C(  49), -INT8_C(  50), -INT8_C( 105), -INT8_C(  87),  INT8_C( 105), -INT8_C(  26), -INT8_C(  77),
         INT8_C( 118),  INT8_C(   6),  INT8_C(  12),  INT8_C(  58),  INT8_C( 124), -INT8_C(  51), -INT8_C(  49),  INT8_C( 104) },
      {  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   3) } },
    { UINT16_C(64721),
      {  INT8_C(  86), -INT8_C( 120),  INT8_C(  33), -INT8_C(  12), -INT8_C(  67),  INT8_C(  68),  INT8_C( 119), -INT8_C(  86),
         INT8_C(  13),  INT8_C(  85), -INT8_C( 120), -INT8_C(  82),  INT8_C(  29), -INT8_C(  26),  INT8_C( 125), -INT8_C(  20) },
      {  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   6),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5) } },
    { UINT16_C( 9854),
      {  INT8_C(  85),  INT8_C( 100), -INT8_C(  38), -INT8_C(  53),  INT8_C( 106), -INT8_C(  26),  INT8_C(   5), -INT8_C(  25),
        -INT8_C(  77), -INT8_C(  43),  INT8_C(  79), -INT8_C( 123), -INT8_C(  47), -INT8_C(  91),  INT8_C(  13), -INT8_C(  14) },
      {  INT8_C(   0),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(51865),
      {  INT8_C(  54),  INT8_C(  16),  INT8_C( 117),  INT8_C(  67),  INT8_C( 101), -INT8_C(   3), -INT8_C(  14), -INT8_C( 125),
        -INT8_C(  28),  INT8_C( 111),  INT8_C( 111),  INT8_C(  98), -INT8_C( 106), -INT8_C(  60), -INT8_C(  58),  INT8_C( 112) },
      {  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
         INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   3) } },
    { UINT16_C(12688),
      {  INT8_C(  86), -INT8_C( 107),  INT8_C(  24),  INT8_C(  10),  INT8_C( 106),  INT8_C( 103), -INT8_C( 113),  INT8_C(  59),
         INT8_C(  12), -INT8_C( 100),  INT8_C(  45), -INT8_C(  91),  INT8_C( 102),  INT8_C(  99), -INT8_C(  75), -INT8_C(  37) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C( 6823),
      { -INT8_C(  39), -INT8_C( 103), -INT8_C(  99), -INT8_C(  67),  INT8_C(   8),  INT8_C(  12),  INT8_C(  31), -INT8_C(  98),
        -INT8_C(  47), -INT8_C(  27),  INT8_C(  14),  INT8_C(  97),  INT8_C(  22),  INT8_C( 101), -INT8_C(  10),  INT8_C(  46) },
      {  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(24943),
      { -INT8_C( 107), -INT8_C(   2), -INT8_C( 100), -INT8_C(  95), -INT8_C( 102), -INT8_C(  54),  INT8_C(  70),  INT8_C(   0),
         INT8_C(  45), -INT8_C(   5), -INT8_C(  36), -INT8_C(  44),  INT8_C(  22), -INT8_C(  75),  INT8_C( 109), -INT8_C(  77) },
      {  INT8_C(   4),  INT8_C(   7),  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_popcnt_epi8(test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_maskz_popcnt_epi8(k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 16477),  INT16_C( 20158),  INT16_C( 18616), -INT16_C( 15068),  INT16_C( 14754),  INT16_C(  9995), -INT16_C( 22730), -INT16_C(  6367) },
      {  INT16_C(     6),  INT16_C(    10),  INT16_C(     6),  INT16_C(     6),  INT16_C(     7),  INT16_C(     7),  INT16_C(     9),  INT16_C(     8) } },
    { {  INT16_C( 22158),  INT16_C( 29113), -INT16_C(  3006),  INT16_C( 18235), -INT16_C(   973),  INT16_C( 20169),  INT16_C( 18356),  INT16_C(  4535) },
      {  INT16_C(     8),  INT16_C(     9),  INT16_C(     7),  INT16_C(     9),  INT16_C(    10),  INT16_C(     8),  INT16_C(     8),  INT16_C(     8) } },
    { {  INT16_C( 30343),  INT16_C( 16479), -INT16_C( 31554),  INT16_C( 24581),  INT16_C(  4285), -INT16_C(  3193), -INT16_C( 22345),  INT16_C( 18139) },
      {  INT16_C(     9),  INT16_C(     7),  INT16_C(     8),  INT16_C(     4),  INT16_C(     7),  INT16_C(    10),  INT16_C(     9),  INT16_C(     9) } },
    { { -INT16_C( 27393),  INT16_C( 16823), -INT16_C(  3192), -INT16_C( 17528),  INT16_C( 20975), -INT16_C( 23799), -INT16_C( 16231),  INT16_C(  8372) },
      {  INT16_C(    11),  INT16_C(     8),  INT16_C(     8),  INT16_C(     8),  INT16_C(    10),  INT16_C(     6),  INT16_C(     6),  INT16_C(     5) } },
    { {  INT16_C(  5174), -INT16_C(  2976),  INT16_C( 26264),  INT16_C( 21844), -INT16_C(  9354),  INT16_C( 11849),  INT16_C(  9348), -INT16_C( 31884) },
      {  INT16_C(     6),  INT16_C(     7),  INT16_C(     7),  INT16_C(     7),  INT16_C(    11),  INT16_C(     7),  INT16_C(     4),  INT16_C(     7) } },
    { {  INT16_C( 11192),  INT16_C( 16580),  INT16_C( 19486),  INT16_C(  3579),  INT16_C(  1181),  INT16_C( 14000),  INT16_C( 26052), -INT16_C(  1193) },
      {  INT16_C(     8),  INT16_C(     4),  INT16_C(     7),  INT16_C(    10),  INT16_C(     6),  INT16_C(     7),  INT16_C(     7),  INT16_C(    12) } },
    { { -INT16_C( 18567),  INT16_C(  4591),  INT16_C( 17437), -INT16_C( 27546), -INT16_C( 20705), -INT16_C( 23614),  INT16_C( 14035), -INT16_C( 29914) },
      {  INT16_C(    11),  INT16_C(     9),  INT16_C(     6),  INT16_C(     7),  INT16_C(    11),  INT16_C(     7),  INT16_C(     9),  INT16_C(     7) } },
    { { -INT16_C(  5535), -INT16_C( 32565), -INT16_C( 14794), -INT16_C( 11123),  INT16_C( 16074), -INT16_C( 28918),  INT16_C( 24995),  INT16_C(  7306) },
      {  INT16_C(     8),  INT16_C(     6),  INT16_C(     8),  INT16_C(     8),  INT16_C(     9),  INT16_C(     7),  INT16_C(     7),  INT16_C(     6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_popcnt_epi16(a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_popcnt_epi16(a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 30322), -INT16_C( 28224), -INT16_C( 28396),  INT16_C(  9078), -INT16_C( 29198), -INT16_C(  6008), -INT16_C(  2117),  INT16_C( 20809) },
      UINT8_C(245),
      { -INT16_C(  3354), -INT16_C( 20337), -INT16_C( 28871),  INT16_C( 13533), -INT16_C( 19861),  INT16_C(  8266), -INT16_C(   481), -INT16_C( 27246) },
      {  INT16_C(    10), -INT16_C( 28224),  INT16_C(     9),  INT16_C(  9078),  INT16_C(     9),  INT16_C(     4),  INT16_C(    12),  INT16_C(     7) } },
    { {  INT16_C(  9150),  INT16_C( 20394), -INT16_C( 12902),  INT16_C( 10049),  INT16_C( 10581),  INT16_C( 19682),  INT16_C( 13171),  INT16_C( 22849) },
      UINT8_C( 38),
      {  INT16_C(  2512),  INT16_C( 24415), -INT16_C( 27674), -INT16_C( 26421), -INT16_C(  5154), -INT16_C(  9032),  INT16_C( 19838), -INT16_C( 24166) },
      {  INT16_C(  9150),  INT16_C(    12),  INT16_C(     9),  INT16_C( 10049),  INT16_C( 10581),  INT16_C(     9),  INT16_C( 13171),  INT16_C( 22849) } },
    { { -INT16_C(  5641), -INT16_C( 15301),  INT16_C( 25130),  INT16_C( 21273),  INT16_C( 25925),  INT16_C( 30918),  INT16_C(  8102),  INT16_C( 30366) },
      UINT8_C( 40),
      { -INT16_C( 10499), -INT16_C( 28401), -INT16_C( 22623), -INT16_C( 29585),  INT16_C( 19295), -INT16_C( 21238), -INT16_C( 21275), -INT16_C( 12636) },
      { -INT16_C(  5641), -INT16_C( 15301),  INT16_C( 25130),  INT16_C(     9),  INT16_C( 25925),  INT16_C(     7),  INT16_C(  8102),  INT16_C( 30366) } },
    { {  INT16_C( 27111),  INT16_C( 19192),  INT16_C( 19330), -INT16_C(  6001),  INT16_C(  1810),  INT16_C( 12686),  INT16_C(  1446), -INT16_C( 23718) },
      UINT8_C(219),
      {  INT16_C( 13417),  INT16_C(  4220),  INT16_C(  2211), -INT16_C(  4496),  INT16_C(  7443), -INT16_C( 16429), -INT16_C( 24127),  INT16_C( 10918) },
      {  INT16_C(     7),  INT16_C(     6),  INT16_C( 19330),  INT16_C(     9),  INT16_C(     7),  INT16_C( 12686),  INT16_C(     6),  INT16_C(     7) } },
    { { -INT16_C(  3943), -INT16_C(  6739), -INT16_C( 27265), -INT16_C( 30729),  INT16_C( 10275),  INT16_C( 10285), -INT16_C( 12158), -INT16_C(  5373) },
      UINT8_C(  5),
      { -INT16_C(   897), -INT16_C( 30552), -INT16_C( 26772), -INT16_C( 30309),  INT16_C( 23146),  INT16_C(  3146),  INT16_C( 29952), -INT16_C(  3675) },
      {  INT16_C(    13), -INT16_C(  6739),  INT16_C(     9), -INT16_C( 30729),  INT16_C( 10275),  INT16_C( 10285), -INT16_C( 12158), -INT16_C(  5373) } },
    { { -INT16_C( 30174), -INT16_C( 18576), -INT16_C(  2175), -INT16_C( 21798),  INT16_C(   804), -INT16_C(  2772),  INT16_C(  6150), -INT16_C( 30982) },
      UINT8_C( 20),
      {  INT16_C(  3746),  INT16_C( 14720),  INT16_C(  2473),  INT16_C(   932), -INT16_C( 20397), -INT16_C( 14333), -INT16_C(  2987), -INT16_C(  7958) },
      { -INT16_C( 30174), -INT16_C( 18576),  INT16_C(     6), -INT16_C( 21798),  INT16_C(     7), -INT16_C(  2772),  INT16_C(  6150), -INT16_C( 30982) } },
    { { -INT16_C( 24219),  INT16_C( 23649),  INT16_C(  2940),  INT16_C( 32641),  INT16_C( 30264),  INT16_C( 20613),  INT16_C(  2928),  INT16_C(  4708) },
      UINT8_C( 25),
      {  INT16_C( 19684), -INT16_C(  4670), -INT16_C( 14864), -INT16_C( 24512),  INT16_C(  2505), -INT16_C( 16907), -INT16_C( 10765), -INT16_C( 27358) },
      {  INT16_C(     7),  INT16_C( 23649),  INT16_C(  2940),  INT16_C(     3),  INT16_C(     6),  INT16_C( 20613),  INT16_C(  2928),  INT16_C(  4708) } },
    { {  INT16_C( 32567),  INT16_C( 16913), -INT16_C( 28672),  INT16_C( 30330), -INT16_C( 13803),  INT16_C(  8678), -INT16_C(  2002),  INT16_C(  4666) },
      UINT8_C( 68),
      { -INT16_C(     3), -INT16_C( 15820), -INT16_C( 11200),  INT16_C( 18827),  INT16_C( 18890), -INT16_C( 24772), -INT16_C( 11925), -INT16_C(  5418) },
      {  INT16_C( 32567),  INT16_C( 16913),  INT16_C(     5),  INT16_C( 30330), -INT16_C( 13803),  INT16_C(  8678),  INT16_C(     9),  INT16_C(  4666) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_mask_popcnt_epi16(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_popcnt_epi16(src, k, a);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(226),
      { -INT16_C(  5607), -INT16_C( 27790), -INT16_C( 30624),  INT16_C( 18014), -INT16_C( 29527), -INT16_C(  7361), -INT16_C( 31841), -INT16_C( 24864) },
      {  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),  INT16_C(     9),  INT16_C(     8) } },
    { UINT8_C(184),
      { -INT16_C(  8541),  INT16_C( 11916),  INT16_C( 22055),  INT16_C( 25719), -INT16_C(  7178), -INT16_C( 13259),  INT16_C(  6349), -INT16_C( 18203) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(    11),  INT16_C(     8),  INT16_C(     0),  INT16_C(     9) } },
    { UINT8_C(138),
      {  INT16_C(  6265), -INT16_C( 10478), -INT16_C( 17569), -INT16_C( 24989),  INT16_C(   671),  INT16_C( 32545), -INT16_C(  9823),  INT16_C( 32546) },
      {  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9) } },
    { UINT8_C(102),
      { -INT16_C( 22703), -INT16_C( 14148), -INT16_C( 19957),  INT16_C( 16555),  INT16_C( 31103),  INT16_C( 25688), -INT16_C(  7375),  INT16_C( 18909) },
      {  INT16_C(     0),  INT16_C(     8),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     8),  INT16_C(     0) } },
    { UINT8_C(245),
      { -INT16_C( 22348),  INT16_C(  6321),  INT16_C( 20550),  INT16_C( 26650), -INT16_C( 17457), -INT16_C(  3519), -INT16_C( 22725), -INT16_C(  7613) },
      {  INT16_C(     7),  INT16_C(     0),  INT16_C(     5),  INT16_C(     0),  INT16_C(    12),  INT16_C(     7),  INT16_C(    10),  INT16_C(     7) } },
    { UINT8_C(100),
      { -INT16_C(  4853), -INT16_C( 18666), -INT16_C( 27347), -INT16_C( 31184),  INT16_C( 25082), -INT16_C( 10391),  INT16_C( 24234),  INT16_C( 21388) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     9),  INT16_C(     0) } },
    { UINT8_C( 15),
      { -INT16_C( 26204), -INT16_C( 16801),  INT16_C( 12033),  INT16_C( 17274), -INT16_C( 19167),  INT16_C( 25834),  INT16_C( 20119), -INT16_C( 31633) },
      {  INT16_C(     7),  INT16_C(    12),  INT16_C(     6),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(101),
      { -INT16_C( 20186),  INT16_C( 22266), -INT16_C(  3017), -INT16_C( 24393),  INT16_C( 25292),  INT16_C( 22783),  INT16_C(  3765),  INT16_C( 20220) },
      {  INT16_C(     7),  INT16_C(     0),  INT16_C(    10),  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),  INT16_C(     8),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_popcnt_epi16(test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_popcnt_epi16(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   257302130),  INT32_C(   843701006), -INT32_C(  1571721565), -INT32_C(  1251033202) },
      {  INT32_C(          16),  INT32_C(          15),  INT32_C(          15),  INT32_C(          21) } },
    { { -INT32_C(   257155824), -INT32_C(  1201709097), -INT32_C(    76945165),  INT32_C(   359760263) },
      {  INT32_C(          13),  INT32_C(          22),  INT32_C(          21),  INT32_C(          13) } },
    { {  INT32_C(  1879382626), -INT32_C(  1734127627),  INT32_C(  1262154941), -INT32_C(  1023366989) },
      {  INT32_C(          11),  INT32_C(          18),  INT32_C(          19),  INT32_C(          12) } },
    { { -INT32_C(  1649169210), -INT32_C(    11201780), -INT32_C(  2097496325), -INT32_C(  1583912129) },
      {  INT32_C(          18),  INT32_C(          17),  INT32_C(          21),  INT32_C(          19) } },
    { {  INT32_C(  2064817541), -INT32_C(  1458326036),  INT32_C(  1559514793), -INT32_C(  1138690826) },
      {  INT32_C(          16),  INT32_C(          17),  INT32_C(          17),  INT32_C(          17) } },
    { { -INT32_C(  1386622047), -INT32_C(   491999514), -INT32_C(  1402689939), -INT32_C(  1773208559) },
      {  INT32_C(          17),  INT32_C(          18),  INT32_C(          16),  INT32_C(          16) } },
    { { -INT32_C(  2062458727), -INT32_C(  1104272107),  INT32_C(  1763320435), -INT32_C(  1222231530) },
      {  INT32_C(          11),  INT32_C(          16),  INT32_C(          14),  INT32_C(          16) } },
    { { -INT32_C(   194740466), -INT32_C(  1680469970), -INT32_C(   951632970), -INT32_C(   799107785) },
      {  INT32_C(          18),  INT32_C(          15),  INT32_C(          19),  INT32_C(          17) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_popcnt_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_popcnt_epi32(a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1655653778), -INT32_C(   373386444), -INT32_C(   864017795), -INT32_C(  1204747119) },
      UINT8_C(182),
      {  INT32_C(   552406571),  INT32_C(   686591686), -INT32_C(  1679997811), -INT32_C(   100062400) },
      { -INT32_C(  1655653778),  INT32_C(          15),  INT32_C(          17), -INT32_C(  1204747119) } },
    { {  INT32_C(   238003835), -INT32_C(  2037639068), -INT32_C(  1659348839), -INT32_C(  1269575543) },
      UINT8_C(222),
      { -INT32_C(   811281343),  INT32_C(    73190592), -INT32_C(   716900439), -INT32_C(  1487913215) },
      {  INT32_C(   238003835),  INT32_C(          11),  INT32_C(          18),  INT32_C(          14) } },
    { { -INT32_C(  2046009490),  INT32_C(  1126142699),  INT32_C(  2060238250),  INT32_C(  1364819984) },
      UINT8_C( 85),
      { -INT32_C(   904584963),  INT32_C(  1953700476), -INT32_C(  1653258146), -INT32_C(   133489511) },
      {  INT32_C(          15),  INT32_C(  1126142699),  INT32_C(          17),  INT32_C(  1364819984) } },
    { { -INT32_C(  1142713816),  INT32_C(  1852122801),  INT32_C(  1920983282),  INT32_C(   919064633) },
      UINT8_C(241),
      { -INT32_C(   143851299), -INT32_C(  1135222412),  INT32_C(  1935012694), -INT32_C(  1868870146) },
      {  INT32_C(          18),  INT32_C(  1852122801),  INT32_C(  1920983282),  INT32_C(   919064633) } },
    { {  INT32_C(  1447188016), -INT32_C(  1672957764),  INT32_C(    14007087),  INT32_C(  1609632642) },
      UINT8_C( 12),
      {  INT32_C(  1082152542), -INT32_C(  1617544020), -INT32_C(   543356526), -INT32_C(    82825563) },
      {  INT32_C(  1447188016), -INT32_C(  1672957764),  INT32_C(          17),  INT32_C(          16) } },
    { {  INT32_C(   548890224),  INT32_C(  1783649199),  INT32_C(   887902248), -INT32_C(  1623176127) },
      UINT8_C(162),
      { -INT32_C(    61939776),  INT32_C(  2140073334), -INT32_C(  1188794741), -INT32_C(   467066754) },
      {  INT32_C(   548890224),  INT32_C(          22),  INT32_C(   887902248), -INT32_C(  1623176127) } },
    { {  INT32_C(   731072983), -INT32_C(   380371559),  INT32_C(   908756970), -INT32_C(  2015835449) },
      UINT8_C(169),
      {  INT32_C(   337609767), -INT32_C(  2137022702), -INT32_C(   469870397), -INT32_C(   876878975) },
      {  INT32_C(          13), -INT32_C(   380371559),  INT32_C(   908756970),  INT32_C(          18) } },
    { {  INT32_C(  1952769654), -INT32_C(  1050784199),  INT32_C(  1116247160), -INT32_C(  1813245844) },
      UINT8_C(148),
      { -INT32_C(  1431918581), -INT32_C(  1603393721),  INT32_C(   136401189), -INT32_C(   226497524) },
      {  INT32_C(  1952769654), -INT32_C(  1050784199),  INT32_C(           9), -INT32_C(  1813245844) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_popcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_popcnt_epi32(src, k, a);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 81),
      {  INT32_C(  1369386227),  INT32_C(  1977948141),  INT32_C(  1183142234), -INT32_C(  1924064795) },
      {  INT32_C(          18),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(192),
      {  INT32_C(  1793578236), -INT32_C(  1766126476), -INT32_C(  1803368427), -INT32_C(   427306054) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(114),
      { -INT32_C(  1114975272), -INT32_C(   837884855),  INT32_C(  2078864170),  INT32_C(  1433905280) },
      {  INT32_C(           0),  INT32_C(          15),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(143),
      { -INT32_C(  1650734623), -INT32_C(   496652193), -INT32_C(   877322428), -INT32_C(   643618810) },
      {  INT32_C(          18),  INT32_C(          17),  INT32_C(          17),  INT32_C(          13) } },
    { UINT8_C(178),
      {  INT32_C(  1872110176), -INT32_C(   647839503), -INT32_C(  1283333317),  INT32_C(    26480696) },
      {  INT32_C(           0),  INT32_C(          15),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(171),
      { -INT32_C(  1772330703), -INT32_C(   122249149),  INT32_C(   253803628), -INT32_C(  1200565611) },
      {  INT32_C(          14),  INT32_C(          15),  INT32_C(           0),  INT32_C(          15) } },
    { UINT8_C(104),
      {  INT32_C(  1093183967),  INT32_C(    52716674), -INT32_C(  1424794601), -INT32_C(  1075986850) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          24) } },
    { UINT8_C( 26),
      {  INT32_C(   700121715),  INT32_C(   468002810), -INT32_C(  1494385866), -INT32_C(   595241421) },
      {  INT32_C(           0),  INT32_C(          19),  INT32_C(           0),  INT32_C(          16) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_popcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_popcnt_epi32(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 3426434154627122044), -INT64_C( 4165654989628200704) },
      {  INT64_C(                  31),  INT64_C(                  26) } },
    { {  INT64_C( 6488701872467398292),  INT64_C(  560774584721515154) },
      {  INT64_C(                  35),  INT64_C(                  23) } },
    { { -INT64_C( 3126393329426630527),  INT64_C( 3394460239127116922) },
      {  INT64_C(                  34),  INT64_C(                  37) } },
    { {  INT64_C(  120942359153274714), -INT64_C( 2893198449337822897) },
      {  INT64_C(                  33),  INT64_C(                  32) } },
    { { -INT64_C( 8868925732892231613),  INT64_C( 3172211798448883259) },
      {  INT64_C(                  30),  INT64_C(                  33) } },
    { { -INT64_C( 6821778803459643932),  INT64_C( 7308300006718691134) },
      {  INT64_C(                  31),  INT64_C(                  32) } },
    { { -INT64_C( 8569673553837027451), -INT64_C( 4202873432559326034) },
      {  INT64_C(                  30),  INT64_C(                  32) } },
    { { -INT64_C( 7638829170975757558),  INT64_C( 4741048768649654340) },
      {  INT64_C(                  34),  INT64_C(                  28) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_popcnt_epi64(a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_popcnt_epi64(a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 5258341705674835838), -INT64_C(  770848351340550796) },
      UINT8_C(103),
      {  INT64_C( 9179879772881231624),  INT64_C( 6358676480548015210) },
      {  INT64_C(                  31),  INT64_C(                  27) } },
    { { -INT64_C( 4629264897366810132),  INT64_C( 5331759763703329842) },
      UINT8_C( 86),
      { -INT64_C( 1637380768083052449),  INT64_C( 7280019612139980428) },
      { -INT64_C( 4629264897366810132),  INT64_C(                  29) } },
    { {  INT64_C(  780599476883576087), -INT64_C( 3887006242294764415) },
      UINT8_C( 12),
      { -INT64_C(  950307984663468440),  INT64_C( 5060248215802538574) },
      {  INT64_C(  780599476883576087), -INT64_C( 3887006242294764415) } },
    { {  INT64_C( 2295823925786828060),  INT64_C(  816369388910908595) },
      UINT8_C(249),
      {  INT64_C(  459603677551086910), -INT64_C( 7438188758807576050) },
      {  INT64_C(                  29),  INT64_C(  816369388910908595) } },
    { { -INT64_C( 7874989259201240677), -INT64_C( 8124423009945125389) },
      UINT8_C(141),
      { -INT64_C( 9003909507399900890), -INT64_C( 7096873135621884504) },
      {  INT64_C(                  27), -INT64_C( 8124423009945125389) } },
    { {  INT64_C( 4143079915989468450),  INT64_C( 3256131150682965602) },
      UINT8_C(187),
      { -INT64_C( 1498784747495871782),  INT64_C( 2483177314018859645) },
      {  INT64_C(                  36),  INT64_C(                  29) } },
    { {  INT64_C( 5201541583154774687), -INT64_C( 2596751790400614111) },
      UINT8_C(167),
      { -INT64_C( 5517251929968908622),  INT64_C( 4382689877872853807) },
      {  INT64_C(                  36),  INT64_C(                  34) } },
    { { -INT64_C( 6951861491259760689),  INT64_C( 7600242975119098198) },
      UINT8_C(226),
      { -INT64_C( 8336674418864727466), -INT64_C(  883267012606459266) },
      { -INT64_C( 6951861491259760689),  INT64_C(                  35) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_popcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_popcnt_epi64(src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(191),
      {  INT64_C(  174545691363164452), -INT64_C( 1747852345401793554) },
      {  INT64_C(                  24),  INT64_C(                  37) } },
    { UINT8_C(220),
      {  INT64_C(  193242725553516765), -INT64_C( 5234374679635754376) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(137),
      { -INT64_C( 7379830672591611899), -INT64_C( 5001293523891641605) },
      {  INT64_C(                  27),  INT64_C(                   0) } },
    { UINT8_C(225),
      { -INT64_C(  255328622659045693),  INT64_C( 4213759709905119770) },
      {  INT64_C(                  38),  INT64_C(                   0) } },
    { UINT8_C(237),
      { -INT64_C( 1755422070222596884),  INT64_C( 6742345381037648950) },
      {  INT64_C(                  32),  INT64_C(                   0) } },
    { UINT8_C( 10),
      {  INT64_C( 1215979945859044610), -INT64_C( 8006761059378003332) },
      {  INT64_C(                   0),  INT64_C(                  28) } },
    { UINT8_C(198),
      {  INT64_C( 2572532187450736227), -INT64_C( 3685688909733095099) },
      {  INT64_C(                   0),  INT64_C(                  34) } },
    { UINT8_C(186),
      { -INT64_C( 8776885455195923121),  INT64_C( 8969361752886898227) },
      {  INT64_C(                   0),  INT64_C(                  36) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_popcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_popcnt_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  88),  INT8_C(  12),  INT8_C(  67), -INT8_C(  89), -INT8_C(  24), -INT8_C(  16),  INT8_C(  56), -INT8_C( 104),
         INT8_C( 101),  INT8_C(   8),  INT8_C( 123),  INT8_C( 114), -INT8_C(   2), -INT8_C(  69),  INT8_C(  28), -INT8_C(  14),
        -INT8_C(  26),  INT8_C(  95),  INT8_C(  33),  INT8_C( 100), -INT8_C(  87),  INT8_C(  70), -INT8_C(  53),  INT8_C( 123),
         INT8_C(  60), -INT8_C(   1),  INT8_C(  45),  INT8_C(   2),  INT8_C(  34),  INT8_C( 121), -INT8_C(  84),  INT8_C( 122) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   1),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   6),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),
         INT8_C(   4),  INT8_C(   8),  INT8_C(   4),  INT8_C(   1),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5) } },
    { { -INT8_C( 123), -INT8_C(  16),  INT8_C(  33),  INT8_C( 109), -INT8_C(  32),  INT8_C(  89),  INT8_C(   5),  INT8_C(  69),
         INT8_C(  97), -INT8_C( 127), -INT8_C(  73),  INT8_C(  95),  INT8_C(  60), -INT8_C(  45),  INT8_C(  81),  INT8_C(  34),
         INT8_C(  51),  INT8_C( 114), -INT8_C( 121), -INT8_C(  36), -INT8_C(  72),  INT8_C(  82),  INT8_C(  87), -INT8_C(  12),
         INT8_C(  82), -INT8_C( 124), -INT8_C(  10),  INT8_C( 116), -INT8_C(   3), -INT8_C(  93), -INT8_C(  17), -INT8_C( 126) },
      {  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   6),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   2),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   4),  INT8_C(   7),  INT8_C(   2) } },
    { { -INT8_C( 109),  INT8_C(  16), -INT8_C(  16),  INT8_C( 115),  INT8_C( 106), -INT8_C(  11), -INT8_C(  72), -INT8_C(  53),
         INT8_C( 118),  INT8_C( 111),  INT8_C(  43), -INT8_C(  77),  INT8_C(  66),  INT8_C( 124), -INT8_C(  43),  INT8_C( 117),
        -INT8_C(  17),  INT8_C(  92),  INT8_C(  81), -INT8_C(  89), -INT8_C(  81), -INT8_C(  88), -INT8_C( 100),  INT8_C(   1),
         INT8_C(  45), -INT8_C( 110),  INT8_C( 117),  INT8_C(  42),  INT8_C(  53),  INT8_C( 100), -INT8_C(  83), -INT8_C(  56) },
      {  INT8_C(   4),  INT8_C(   1),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),
         INT8_C(   7),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   1),
         INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3) } },
    { {  INT8_C( 117), -INT8_C(  99),  INT8_C(  59), -INT8_C(  33), -INT8_C( 110), -INT8_C(  13), -INT8_C(  86),  INT8_C(   9),
         INT8_C(  98), -INT8_C(  43), -INT8_C(  68), -INT8_C(  91),  INT8_C(  82), -INT8_C( 111),  INT8_C(  26),  INT8_C(  65),
        -INT8_C(  18),  INT8_C( 108), -INT8_C(  24), -INT8_C(  99),  INT8_C(  20), -INT8_C( 124), -INT8_C(  98),  INT8_C(  65),
         INT8_C(  23),  INT8_C(  19),  INT8_C( 108),  INT8_C(  76),  INT8_C( 120),  INT8_C(  25),  INT8_C(  21), -INT8_C(  19) },
      {  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   7),  INT8_C(   3),  INT8_C(   6),  INT8_C(   4),  INT8_C(   2),
         INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   2),
         INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   2),  INT8_C(   5),  INT8_C(   2),
         INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6) } },
    { { -INT8_C(  74),  INT8_C(  80), -INT8_C(  52),  INT8_C(  72),  INT8_C(  68),  INT8_C( 118),  INT8_C(  81), -INT8_C(  90),
         INT8_C(  76),  INT8_C(  13),  INT8_C(  75), -INT8_C(  98), -INT8_C(  97),  INT8_C( 102), -INT8_C(  33), -INT8_C( 115),
        -INT8_C(  46), -INT8_C(  57),  INT8_C(  42), -INT8_C(  26),  INT8_C(  76), -INT8_C(  56),  INT8_C(  40),  INT8_C(  99),
        -INT8_C(  37), -INT8_C( 108), -INT8_C(  81),  INT8_C(  83), -INT8_C(  83), -INT8_C(  60),  INT8_C(  64),  INT8_C(  99) },
      {  INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   2),  INT8_C(   2),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   4),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   2),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   3),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   1),  INT8_C(   4) } },
    { {  INT8_C(  21),  INT8_C(  12), -INT8_C(  85),  INT8_C(  89), -INT8_C( 125), -INT8_C(   3), -INT8_C(   1), -INT8_C(  49),
         INT8_C(  10),  INT8_C(  75),  INT8_C( 109), -INT8_C(  87), -INT8_C(  79),  INT8_C(  76),  INT8_C(  54), -INT8_C( 125),
         INT8_C(  19),  INT8_C(  96),  INT8_C( 105),  INT8_C(  95),  INT8_C(  40), -INT8_C( 111), -INT8_C(  62),  INT8_C(   4),
         INT8_C(  37),  INT8_C( 114),  INT8_C(  87), -INT8_C(  46),  INT8_C(  54), -INT8_C( 104),  INT8_C(  53),  INT8_C(  75) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   7),  INT8_C(   8),  INT8_C(   6),
         INT8_C(   2),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2),  INT8_C(   3),  INT8_C(   3),  INT8_C(   1),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4) } },
    { { -INT8_C(  92), -INT8_C(  31), -INT8_C(  92),  INT8_C(  39), -INT8_C(  34), -INT8_C(  92), -INT8_C(  10), -INT8_C(  24),
        -INT8_C(  17),  INT8_C(  99), -INT8_C( 110), -INT8_C(  96), -INT8_C(  81), -INT8_C(  56),  INT8_C(  35), -INT8_C(  61),
         INT8_C(  41), -INT8_C( 116),  INT8_C(  34),  INT8_C(  81),  INT8_C(  30), -INT8_C(  27),  INT8_C(  85),  INT8_C(  67),
         INT8_C(  87), -INT8_C(  83),  INT8_C(  22), -INT8_C( 115),  INT8_C(  69),  INT8_C(  75), -INT8_C(  39), -INT8_C(  23) },
      {  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3),  INT8_C(   6),  INT8_C(   4),
         INT8_C(   7),  INT8_C(   4),  INT8_C(   3),  INT8_C(   2),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   3),  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5) } },
    { {  INT8_C(  44),  INT8_C( 125),  INT8_C(  17),  INT8_C(  10),  INT8_C(  33),  INT8_C(   7), -INT8_C(  13),  INT8_C(  16),
         INT8_C( 107), -INT8_C( 123), -INT8_C(  80),  INT8_C(  26),  INT8_C(  77), -INT8_C(  45), -INT8_C(  35),  INT8_C( 118),
         INT8_C(  96),  INT8_C(   0), -INT8_C(  56),  INT8_C( 126), -INT8_C(  27),  INT8_C(  29), -INT8_C(  63),  INT8_C(  60),
        -INT8_C(  54), -INT8_C(  41), -INT8_C(  55),  INT8_C(  15),  INT8_C(  35), -INT8_C(  94), -INT8_C(   7),  INT8_C(  79) },
      {  INT8_C(   3),  INT8_C(   6),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   3),  INT8_C(   6),  INT8_C(   1),
         INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   4),  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i r = simde_mm256_popcnt_epi8(a);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_popcnt_epi8(a);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[32];
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  76), -INT8_C(  61), -INT8_C( 119), -INT8_C( 124),  INT8_C( 117), -INT8_C(   1),  INT8_C(  13),  INT8_C(  93),
         INT8_C(  52),  INT8_C(  90), -INT8_C( 116), -INT8_C( 120),  INT8_C(   3), -INT8_C(  21),  INT8_C( 107),  INT8_C(  19),
        -INT8_C( 106),  INT8_C(  41),  INT8_C(  95),  INT8_C(   9), -INT8_C(  76), -INT8_C(  48), -INT8_C(  31), -INT8_C(  72),
        -INT8_C(  40), -INT8_C(  61), -INT8_C(   3), -INT8_C(   8), -INT8_C(  37),  INT8_C(  90), -INT8_C(  60),  INT8_C(  40) },
      UINT32_C(2477542686),
      {  INT8_C(  76), -INT8_C(  71), -INT8_C(  16), -INT8_C( 127),  INT8_C(  20),  INT8_C( 124),  INT8_C(   9),  INT8_C(  23),
         INT8_C( 103),  INT8_C( 116),  INT8_C(  42), -INT8_C(   2), -INT8_C(  99), -INT8_C( 118),  INT8_C(   7),  INT8_C(  81),
         INT8_C(  90), -INT8_C(  24),  INT8_C(   9),  INT8_C(  51), -INT8_C(  85),  INT8_C(   6),  INT8_C(  43), -INT8_C( 121),
         INT8_C(  97), -INT8_C(  17), -INT8_C(  81),      INT8_MAX,  INT8_C(  60),  INT8_C(  91),  INT8_C(  18), -INT8_C( 119) },
      {  INT8_C(  76),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   2), -INT8_C(   1),  INT8_C(  13),  INT8_C(  93),
         INT8_C(   5),  INT8_C(  90),  INT8_C(   3),  INT8_C(   7),  INT8_C(   3), -INT8_C(  21),  INT8_C(   3),  INT8_C(  19),
        -INT8_C( 106),  INT8_C(  41),  INT8_C(   2),  INT8_C(   4), -INT8_C(  76),  INT8_C(   2), -INT8_C(  31),  INT8_C(   4),
         INT8_C(   3),  INT8_C(   7), -INT8_C(   3), -INT8_C(   8),  INT8_C(   4),  INT8_C(  90), -INT8_C(  60),  INT8_C(   3) } },
    { {  INT8_C(  21),  INT8_C(   3),  INT8_C(  10),  INT8_C(  41),      INT8_MAX,  INT8_C(  19),  INT8_C(  64), -INT8_C(  25),
        -INT8_C( 121),  INT8_C( 106), -INT8_C(  27),  INT8_C(  36), -INT8_C(  12), -INT8_C(  20),  INT8_C( 117),  INT8_C(  79),
        -INT8_C(  44),      INT8_MAX, -INT8_C( 126),      INT8_MAX, -INT8_C( 123), -INT8_C(  83),  INT8_C(   6), -INT8_C(  26),
        -INT8_C( 100), -INT8_C(  75),  INT8_C( 101), -INT8_C(  40),  INT8_C(  17),  INT8_C( 120),  INT8_C(  97),  INT8_C(  38) },
      UINT32_C(4199508859),
      {  INT8_C( 126), -INT8_C( 113), -INT8_C(  31),  INT8_C(   5), -INT8_C(   7), -INT8_C(  58),  INT8_C(  41), -INT8_C(  18),
        -INT8_C(  78), -INT8_C(  97),  INT8_C(  61), -INT8_C( 122),  INT8_C(  30), -INT8_C(  65),  INT8_C(   6), -INT8_C(  93),
         INT8_C( 108),  INT8_C(  12), -INT8_C( 118),  INT8_C(   8), -INT8_C(  62), -INT8_C(  17), -INT8_C(  32), -INT8_C(  45),
         INT8_C( 103),  INT8_C(  66), -INT8_C(   7), -INT8_C(  30), -INT8_C(  83),  INT8_C(  72), -INT8_C(  35),  INT8_C(  44) },
      {  INT8_C(   6),  INT8_C(   5),  INT8_C(  10),  INT8_C(   2),  INT8_C(   6),  INT8_C(   4),  INT8_C(   3), -INT8_C(  25),
         INT8_C(   4),  INT8_C(   6), -INT8_C(  27),  INT8_C(   3), -INT8_C(  12),  INT8_C(   7),  INT8_C(   2),  INT8_C(  79),
         INT8_C(   4),  INT8_C(   2),  INT8_C(   3),  INT8_C(   1), -INT8_C( 123), -INT8_C(  83),  INT8_C(   3), -INT8_C(  26),
        -INT8_C( 100),  INT8_C(   2),  INT8_C( 101),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   6),  INT8_C(   3) } },
    { { -INT8_C(  41), -INT8_C(  66),  INT8_C(  49), -INT8_C(  48), -INT8_C( 123),  INT8_C(  91), -INT8_C(  66),  INT8_C(  55),
        -INT8_C(   6), -INT8_C(   5), -INT8_C(  66),  INT8_C(  24), -INT8_C(  70), -INT8_C(  60), -INT8_C(  69),  INT8_C(  38),
        -INT8_C(  48),  INT8_C(  69),  INT8_C(  46), -INT8_C( 110),  INT8_C(  53),  INT8_C(  15),  INT8_C( 101), -INT8_C( 100),
         INT8_C(  81),  INT8_C(  94),      INT8_MAX, -INT8_C(   2), -INT8_C(  90),  INT8_C(  92),  INT8_C(  42),  INT8_C( 125) },
      UINT32_C(2672712730),
      { -INT8_C(  73),  INT8_C(  12), -INT8_C(  41), -INT8_C(  79),  INT8_C(   8), -INT8_C( 107), -INT8_C(  55), -INT8_C(  62),
         INT8_C(  89), -INT8_C( 124), -INT8_C(  23),  INT8_C(  41), -INT8_C(  54),  INT8_C(  23), -INT8_C(  68), -INT8_C(   1),
         INT8_C(  38),  INT8_C(  33), -INT8_C( 101),  INT8_C( 119),      INT8_MIN,  INT8_C(  26),  INT8_C( 118),  INT8_C(  38),
         INT8_C( 118), -INT8_C(  96), -INT8_C(  92), -INT8_C( 111), -INT8_C(   4), -INT8_C(  14),  INT8_C(  48), -INT8_C(  77) },
      { -INT8_C(  41),  INT8_C(   2),  INT8_C(  49),  INT8_C(   4),  INT8_C(   1),  INT8_C(  91), -INT8_C(  66),  INT8_C(  55),
        -INT8_C(   6), -INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4), -INT8_C(  60),  INT8_C(   5),  INT8_C(  38),
        -INT8_C(  48),  INT8_C(   2),  INT8_C(   5),  INT8_C(   6),  INT8_C(  53),  INT8_C(  15),  INT8_C(   5), -INT8_C( 100),
         INT8_C(   5),  INT8_C(   2),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6),  INT8_C(  92),  INT8_C(  42),  INT8_C(   5) } },
    { { -INT8_C(   2),  INT8_C(   7),  INT8_C( 100),  INT8_C(   6), -INT8_C( 100),  INT8_C(  45), -INT8_C(  55), -INT8_C(  11),
        -INT8_C(  78), -INT8_C(  78),  INT8_C(  31),  INT8_C( 124), -INT8_C(  55), -INT8_C(  37),  INT8_C( 123), -INT8_C(  16),
        -INT8_C(   4),  INT8_C(  22),  INT8_C( 103),  INT8_C( 124),  INT8_C(  49), -INT8_C(  35), -INT8_C(  93), -INT8_C(  89),
         INT8_C( 126),  INT8_C(  71),  INT8_C(  56),  INT8_C( 122),  INT8_C(  57),  INT8_C( 105),  INT8_C(  46),  INT8_C(  55) },
      UINT32_C( 222204528),
      { -INT8_C(  64),  INT8_C(   7),  INT8_C(   2),  INT8_C( 114), -INT8_C(  71),  INT8_C(  33), -INT8_C(  18), -INT8_C( 126),
        -INT8_C(   4),  INT8_C( 105),  INT8_C( 114), -INT8_C(   7),      INT8_MAX, -INT8_C(  38),  INT8_C( 117), -INT8_C(  80),
        -INT8_C(  73),  INT8_C(  24),  INT8_C(  88),  INT8_C(  53),  INT8_C(  95), -INT8_C( 112), -INT8_C(  80), -INT8_C( 104),
        -INT8_C(   7), -INT8_C(  34), -INT8_C(  48),  INT8_C( 106),  INT8_C( 112),  INT8_C(  14),  INT8_C( 119),  INT8_C(  48) },
      { -INT8_C(   2),  INT8_C(   7),  INT8_C( 100),  INT8_C(   6),  INT8_C(   5),  INT8_C(   2),  INT8_C(   6), -INT8_C(  11),
        -INT8_C(  78),  INT8_C(   4),  INT8_C(  31),  INT8_C( 124),  INT8_C(   7), -INT8_C(  37),  INT8_C( 123),  INT8_C(   3),
        -INT8_C(   4),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2), -INT8_C(  93), -INT8_C(  89),
         INT8_C(   6),  INT8_C(  71),  INT8_C(   3),  INT8_C(   4),  INT8_C(  57),  INT8_C( 105),  INT8_C(  46),  INT8_C(  55) } },
    { {  INT8_C(  21),  INT8_C( 121), -INT8_C(  94), -INT8_C(  50), -INT8_C( 101), -INT8_C( 112),  INT8_C(  80), -INT8_C( 105),
        -INT8_C(   7), -INT8_C(  61), -INT8_C( 112),  INT8_C( 121), -INT8_C(  99),  INT8_C(   6),  INT8_C(  41),  INT8_C(  84),
         INT8_C(  30), -INT8_C( 127), -INT8_C( 118),  INT8_C( 126),  INT8_C(  18),  INT8_C(  58),  INT8_C(  22),  INT8_C(  11),
         INT8_C(  24), -INT8_C(  26),  INT8_C( 117), -INT8_C( 120), -INT8_C(  12), -INT8_C(  20), -INT8_C(  71),  INT8_C(   9) },
      UINT32_C(  30890854),
      { -INT8_C(  20),  INT8_C(  40), -INT8_C( 104), -INT8_C(  27), -INT8_C(  21),  INT8_C(  41),  INT8_C(  94), -INT8_C( 120),
         INT8_C(  47), -INT8_C( 120), -INT8_C(  36),  INT8_C(  77),  INT8_C(   9),  INT8_C( 102), -INT8_C(  53),  INT8_C(  27),
        -INT8_C(  96), -INT8_C(  30),  INT8_C(  39), -INT8_C(  72), -INT8_C(  56), -INT8_C( 100),  INT8_C(  65), -INT8_C(  67),
        -INT8_C( 119), -INT8_C(   6), -INT8_C(  58), -INT8_C(  17),  INT8_C(  85), -INT8_C(  98), -INT8_C(  16),  INT8_C(  65) },
      {  INT8_C(  21),  INT8_C(   2),  INT8_C(   3), -INT8_C(  50), -INT8_C( 101),  INT8_C(   3),  INT8_C(   5), -INT8_C( 105),
         INT8_C(   5),  INT8_C(   2), -INT8_C( 112),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),  INT8_C(   5),  INT8_C(  84),
         INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C( 126),  INT8_C(   3),  INT8_C(  58),  INT8_C(   2),  INT8_C(   6),
         INT8_C(   3), -INT8_C(  26),  INT8_C( 117), -INT8_C( 120), -INT8_C(  12), -INT8_C(  20), -INT8_C(  71),  INT8_C(   9) } },
    { { -INT8_C(  58), -INT8_C( 120),  INT8_C(  39), -INT8_C(  79), -INT8_C(  79), -INT8_C( 123),  INT8_C(  57), -INT8_C(  32),
         INT8_C(  13),  INT8_C(  21),  INT8_C(  46),  INT8_C(  23),  INT8_C( 124), -INT8_C(   7),  INT8_C(  50),  INT8_C(  28),
        -INT8_C(  37),  INT8_C(  89), -INT8_C(  43), -INT8_C(  92), -INT8_C(  10),  INT8_C(  22),  INT8_C(  97),      INT8_MAX,
         INT8_C(  16),  INT8_C(  39),  INT8_C( 110),  INT8_C( 101), -INT8_C(  59),  INT8_C(  94), -INT8_C(  89), -INT8_C( 117) },
      UINT32_C(2554121958),
      {  INT8_C(  83),  INT8_C( 117),  INT8_C( 120),  INT8_C(  97), -INT8_C( 117), -INT8_C(  90),  INT8_C( 120),  INT8_C(   7),
        -INT8_C(  96), -INT8_C(  86),  INT8_C(  35),  INT8_C( 123),  INT8_C(   4), -INT8_C(   8),  INT8_C(  31), -INT8_C(   6),
         INT8_C(  14),      INT8_MIN,  INT8_C( 121),  INT8_C(  30), -INT8_C(  88), -INT8_C(  25), -INT8_C( 124),  INT8_C( 109),
         INT8_C(  69),  INT8_C(  43), -INT8_C(   7),  INT8_C(  43), -INT8_C(   7),  INT8_C(  53), -INT8_C(  61),  INT8_C(  76) },
      { -INT8_C(  58),  INT8_C(   5),  INT8_C(   4), -INT8_C(  79), -INT8_C(  79),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),
         INT8_C(  13),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C( 124), -INT8_C(   7),  INT8_C(   5),  INT8_C(   6),
        -INT8_C(  37),  INT8_C(  89),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(  97),      INT8_MAX,
         INT8_C(  16),  INT8_C(  39),  INT8_C( 110),  INT8_C(   4),  INT8_C(   6),  INT8_C(  94), -INT8_C(  89),  INT8_C(   3) } },
    { { -INT8_C(  85),  INT8_C(  60), -INT8_C(  83),  INT8_C(  54), -INT8_C(  30),  INT8_C(  37),  INT8_C(  61), -INT8_C( 126),
        -INT8_C(  48),  INT8_C(  96), -INT8_C(   2), -INT8_C(  44),  INT8_C(  89),  INT8_C(  29), -INT8_C(  50),  INT8_C( 103),
        -INT8_C(  98),  INT8_C(  71), -INT8_C( 122),  INT8_C(  70),  INT8_C(  46),  INT8_C(  10), -INT8_C(  77),  INT8_C( 115),
         INT8_C(  53), -INT8_C(  84), -INT8_C(  98),  INT8_C(  46), -INT8_C(  30),  INT8_C(  98),  INT8_C( 122), -INT8_C( 115) },
      UINT32_C(2160273566),
      {  INT8_C(  77),  INT8_C(   0),  INT8_C(   3),  INT8_C(  29),  INT8_C(  96),  INT8_C(   1), -INT8_C(  15), -INT8_C(  71),
         INT8_C(  30), -INT8_C(  65),  INT8_C(  33), -INT8_C(  68),  INT8_C(   6), -INT8_C(  89),  INT8_C(   2),  INT8_C(  52),
        -INT8_C(  79), -INT8_C(  74), -INT8_C(  89), -INT8_C(  26),  INT8_C(  98),  INT8_C(  70),  INT8_C(  20),  INT8_C(  68),
        -INT8_C(  88), -INT8_C( 114), -INT8_C(  47),  INT8_C(  70), -INT8_C(  74), -INT8_C( 108), -INT8_C(  58),  INT8_C(   4) },
      { -INT8_C(  85),  INT8_C(   0),  INT8_C(   2),  INT8_C(   4),  INT8_C(   2),  INT8_C(  37),  INT8_C(  61),  INT8_C(   5),
        -INT8_C(  48),  INT8_C(  96), -INT8_C(   2),  INT8_C(   5),  INT8_C(  89),  INT8_C(   5), -INT8_C(  50),  INT8_C( 103),
         INT8_C(   4),  INT8_C(   5), -INT8_C( 122),  INT8_C(  70),  INT8_C(  46),  INT8_C(  10),  INT8_C(   2),  INT8_C(   2),
         INT8_C(  53), -INT8_C(  84), -INT8_C(  98),  INT8_C(  46), -INT8_C(  30),  INT8_C(  98),  INT8_C( 122),  INT8_C(   1) } },
    { { -INT8_C( 108), -INT8_C(  55),  INT8_C(  33), -INT8_C(  11), -INT8_C(  54),  INT8_C(  19), -INT8_C(  82), -INT8_C(  23),
        -INT8_C(  46), -INT8_C(  49), -INT8_C(  91), -INT8_C(  39),  INT8_C( 118), -INT8_C(  88),  INT8_C(  13),  INT8_C(  39),
         INT8_C(  94), -INT8_C(  75),  INT8_C(  13), -INT8_C(  64), -INT8_C(   5),  INT8_C(  33),  INT8_C(   5), -INT8_C(  93),
        -INT8_C(  80), -INT8_C(  42), -INT8_C(  23),  INT8_C( 102),  INT8_C( 107), -INT8_C(  81),  INT8_C( 106), -INT8_C(   1) },
      UINT32_C(1140100217),
      { -INT8_C(  97), -INT8_C(  93),  INT8_C(  44),  INT8_C( 113),  INT8_C( 114), -INT8_C(  46),  INT8_C(  74), -INT8_C(  23),
         INT8_C( 122),  INT8_C(  88),  INT8_C(  16), -INT8_C(  40),  INT8_C(  13),  INT8_C(  30), -INT8_C( 104),  INT8_C(   8),
         INT8_C(  63), -INT8_C(  99), -INT8_C(  85), -INT8_C(  17),  INT8_C( 116), -INT8_C( 108),  INT8_C(  86), -INT8_C(  33),
         INT8_C(  67), -INT8_C(  64), -INT8_C(  34), -INT8_C(  68),  INT8_C(  76), -INT8_C(  45),  INT8_C(   0), -INT8_C(  21) },
      {  INT8_C(   6), -INT8_C(  55),  INT8_C(  33),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3), -INT8_C(  23),
        -INT8_C(  46), -INT8_C(  49),  INT8_C(   1),  INT8_C(   4),  INT8_C( 118), -INT8_C(  88),  INT8_C(  13),  INT8_C(   1),
         INT8_C(  94), -INT8_C(  75),  INT8_C(   5), -INT8_C(  64),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   7),
         INT8_C(   3),  INT8_C(   2), -INT8_C(  23),  INT8_C( 102),  INT8_C( 107), -INT8_C(  81),  INT8_C(   0), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi8(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_popcnt_epi8(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i8x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask_popcnt_epi8(src, k, a);

    simde_test_x86_write_i8x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C(3898420342),
      { -INT8_C(   2), -INT8_C(  89), -INT8_C(  47),  INT8_C( 120), -INT8_C(   1), -INT8_C(  30),  INT8_C(  80),  INT8_C(  12),
         INT8_C(   0), -INT8_C(  23),  INT8_C(  20),  INT8_C(  63), -INT8_C( 122), -INT8_C(  65),  INT8_C(  47), -INT8_C(   6),
         INT8_C(  83), -INT8_C( 123), -INT8_C(  39), -INT8_C( 105),  INT8_C(  69), -INT8_C(  72),  INT8_C(  83), -INT8_C( 110),
        -INT8_C( 117),  INT8_C(  83),  INT8_C( 125),  INT8_C(   1),      INT8_MIN, -INT8_C(  38), -INT8_C(  23),  INT8_C( 126) },
      {  INT8_C(   0),  INT8_C(   5),  INT8_C(   4),  INT8_C(   0),  INT8_C(   8),  INT8_C(   4),  INT8_C(   2),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   6),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(   6) } },
    { UINT32_C(2180496258),
      { -INT8_C(  99),  INT8_C(  71), -INT8_C( 114), -INT8_C(  99),  INT8_C(  48), -INT8_C(  94), -INT8_C(  36), -INT8_C(  73),
         INT8_C(  98),  INT8_C(  11), -INT8_C(  79), -INT8_C(  75), -INT8_C( 112), -INT8_C( 117),  INT8_C(  76), -INT8_C(  42),
         INT8_C(  67), -INT8_C(  96),  INT8_C( 104), -INT8_C(  50), -INT8_C(  13), -INT8_C(  27), -INT8_C(  49),  INT8_C( 115),
        -INT8_C(  64), -INT8_C(  72), -INT8_C(  14),  INT8_C(  66),  INT8_C( 115), -INT8_C(  23), -INT8_C(  61),  INT8_C(  16) },
      {  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   3),  INT8_C(   0),  INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1) } },
    { UINT32_C(1638748464),
      { -INT8_C(  12), -INT8_C( 118),  INT8_C(  24),  INT8_C(  86), -INT8_C( 107), -INT8_C(  55),  INT8_C(  11),  INT8_C(  38),
         INT8_C(  84),  INT8_C(  88), -INT8_C(   4), -INT8_C( 105), -INT8_C(   8),  INT8_C( 100),  INT8_C( 101), -INT8_C(  21),
         INT8_C(  73),  INT8_C(  52),  INT8_C(  95),  INT8_C(   9), -INT8_C(  19),  INT8_C(  81),  INT8_C(  75),  INT8_C(  96),
         INT8_C(  58),  INT8_C(  15),  INT8_C( 113),  INT8_C( 106),  INT8_C(  96),  INT8_C(  30), -INT8_C(  53),  INT8_C(  84) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   2),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   2),
         INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0) } },
    { UINT32_C(1051386792),
      { -INT8_C(  83), -INT8_C(  74),  INT8_C( 100),  INT8_C(   1),  INT8_C(  14),  INT8_C(  96), -INT8_C( 103),  INT8_C(   6),
        -INT8_C(  60), -INT8_C(   2), -INT8_C(  15),  INT8_C(  13),  INT8_C(  51),  INT8_C(  80),  INT8_C(  23),  INT8_C(  32),
        -INT8_C(  95),  INT8_C(  98),      INT8_MIN, -INT8_C(  37),  INT8_C( 113), -INT8_C(  15),  INT8_C(  70), -INT8_C(  46),
         INT8_C(  16),  INT8_C(  17),  INT8_C(  38), -INT8_C(  72), -INT8_C(  11), -INT8_C(  47), -INT8_C(  10), -INT8_C(  94) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   2),
         INT8_C(   3),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   4),  INT8_C(   1),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(2510510727),
      { -INT8_C(  70),  INT8_C(  60), -INT8_C( 101),  INT8_C( 126),  INT8_C(  59), -INT8_C( 116), -INT8_C( 116),  INT8_C( 110),
        -INT8_C(  35), -INT8_C(  93), -INT8_C( 114),  INT8_C( 126),  INT8_C(   5),  INT8_C(  14),  INT8_C(  90),  INT8_C( 119),
         INT8_C(   0), -INT8_C(  96),  INT8_C(  73),  INT8_C(  16), -INT8_C(  79),  INT8_C( 111), -INT8_C(  56), -INT8_C(  90),
         INT8_C(  64), -INT8_C(  65),  INT8_C(  72), -INT8_C(  57),  INT8_C(  25), -INT8_C(  20),  INT8_C(  92), -INT8_C(  44) },
      {  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   6),  INT8_C(   2),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   1),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4) } },
    { UINT32_C(1666381608),
      { -INT8_C( 124), -INT8_C(  34), -INT8_C(  47),  INT8_C(  97), -INT8_C( 127),  INT8_C(  95), -INT8_C(  33), -INT8_C( 121),
         INT8_C( 110),  INT8_C(  57), -INT8_C(   2),  INT8_C( 110), -INT8_C(  39),  INT8_C(  71),  INT8_C( 126), -INT8_C( 117),
        -INT8_C(  74),  INT8_C(  70),  INT8_C(  49), -INT8_C(   9),  INT8_C(   5),  INT8_C( 122), -INT8_C(  66),  INT8_C(  31),
         INT8_C( 102),  INT8_C(  27), -INT8_C(  13), -INT8_C( 114),  INT8_C(  18),  INT8_C(  69), -INT8_C(  14), -INT8_C( 106) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   7),  INT8_C(   0),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   5),  INT8_C(   0) } },
    { UINT32_C(2784477988),
      {  INT8_C(  35), -INT8_C(  41),  INT8_C(  44), -INT8_C( 111),  INT8_C(  16),  INT8_C(  42), -INT8_C(   1), -INT8_C(  22),
         INT8_C( 113),  INT8_C( 125),  INT8_C( 117),  INT8_C(  40), -INT8_C(  61), -INT8_C(  90),  INT8_C(  31), -INT8_C(  55),
         INT8_C(  32), -INT8_C(  35), -INT8_C(  24), -INT8_C( 122), -INT8_C(   8), -INT8_C(  37),  INT8_C(  21),  INT8_C(  11),
         INT8_C(  32),  INT8_C(   7), -INT8_C(  95),  INT8_C(  68), -INT8_C(  54), -INT8_C( 103), -INT8_C(  22), -INT8_C(  19) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   1),  INT8_C(   6),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   1),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   6) } },
    { UINT32_C(2155746928),
      {  INT8_C(  65),  INT8_C( 125),  INT8_C( 106), -INT8_C(  78), -INT8_C(   6), -INT8_C(  33), -INT8_C(  38), -INT8_C(  66),
        -INT8_C( 122), -INT8_C(   7), -INT8_C( 121), -INT8_C(  90), -INT8_C(  41),  INT8_C( 111),  INT8_C(  45), -INT8_C(  49),
         INT8_C(  74),  INT8_C(  66), -INT8_C(  38),  INT8_C( 106),  INT8_C(  73),  INT8_C( 124), -INT8_C(  81),  INT8_C(  19),
         INT8_C(  21), -INT8_C( 103),  INT8_C(   1), -INT8_C( 123), -INT8_C(  81),      INT8_MAX,  INT8_C(   5), -INT8_C(  16) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   7),  INT8_C(   5),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   6),  INT8_C(   4),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_popcnt_epi8(test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_maskz_popcnt_epi8(k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C(  9761),  INT16_C( 13479),  INT16_C( 19321), -INT16_C( 21203), -INT16_C( 27968), -INT16_C( 11641),  INT16_C( 16819),  INT16_C( 23726),
         INT16_C( 23361),  INT16_C( 16813), -INT16_C( 31182), -INT16_C( 13763),  INT16_C(  2077), -INT16_C( 25825),  INT16_C( 22544),  INT16_C( 12594) },
      {  INT16_C(     5),  INT16_C(     8),  INT16_C(     9),  INT16_C(     9),  INT16_C(     5),  INT16_C(     8),  INT16_C(     7),  INT16_C(     9),
         INT16_C(     7),  INT16_C(     7),  INT16_C(     6),  INT16_C(     9),  INT16_C(     5),  INT16_C(    10),  INT16_C(     4),  INT16_C(     6) } },
    { { -INT16_C(  9602), -INT16_C(  1947), -INT16_C( 28123), -INT16_C(  6747),  INT16_C( 11300), -INT16_C( 10313),  INT16_C( 25966), -INT16_C( 20684),
        -INT16_C(  7744), -INT16_C(  3088),  INT16_C( 11623), -INT16_C( 31555), -INT16_C(  9163),  INT16_C( 17696),  INT16_C( 21044), -INT16_C( 19594) },
      {  INT16_C(    11),  INT16_C(     9),  INT16_C(     6),  INT16_C(     9),  INT16_C(     5),  INT16_C(    12),  INT16_C(     9),  INT16_C(     9),
         INT16_C(     6),  INT16_C(    10),  INT16_C(     9),  INT16_C(     8),  INT16_C(     9),  INT16_C(     4),  INT16_C(     6),  INT16_C(    10) } },
    { { -INT16_C(  9428),  INT16_C( 20907),  INT16_C( 20589), -INT16_C( 28362), -INT16_C(  4484), -INT16_C(  5527), -INT16_C( 25261),  INT16_C(  5273),
        -INT16_C( 30338), -INT16_C(  6905), -INT16_C( 15178), -INT16_C(  5271), -INT16_C( 30304), -INT16_C( 10960), -INT16_C( 22820),  INT16_C(  2184) },
      {  INT16_C(     9),  INT16_C(     8),  INT16_C(     7),  INT16_C(     7),  INT16_C(    11),  INT16_C(     9),  INT16_C(     9),  INT16_C(     6),
         INT16_C(     9),  INT16_C(     8),  INT16_C(     8),  INT16_C(    10),  INT16_C(     5),  INT16_C(     7),  INT16_C(     9),  INT16_C(     3) } },
    { {  INT16_C( 13185), -INT16_C(  4518), -INT16_C( 28541), -INT16_C(   128), -INT16_C(  5762), -INT16_C( 11542), -INT16_C( 31866),  INT16_C(  1254),
        -INT16_C(  4851), -INT16_C( 15383),  INT16_C( 21169),  INT16_C( 20911), -INT16_C(  8228), -INT16_C( 18394), -INT16_C( 20858),  INT16_C(  1984) },
      {  INT16_C(     6),  INT16_C(    10),  INT16_C(     5),  INT16_C(     9),  INT16_C(    11),  INT16_C(     9),  INT16_C(     6),  INT16_C(     6),
         INT16_C(     9),  INT16_C(     9),  INT16_C(     7),  INT16_C(     9),  INT16_C(    12),  INT16_C(     7),  INT16_C(     8),  INT16_C(     5) } },
    { {  INT16_C(  6881),  INT16_C( 25846),  INT16_C( 30379),  INT16_C( 10596),  INT16_C( 20063), -INT16_C(  6661), -INT16_C(  7727), -INT16_C(  8471),
        -INT16_C( 11570),  INT16_C( 32674),  INT16_C( 20772),  INT16_C(   209), -INT16_C(  2256), -INT16_C( 18760),  INT16_C( 31142), -INT16_C( 30786) },
      {  INT16_C(     7),  INT16_C(     9),  INT16_C(    10),  INT16_C(     6),  INT16_C(    10),  INT16_C(    12),  INT16_C(     8),  INT16_C(    11),
         INT16_C(     9),  INT16_C(    10),  INT16_C(     5),  INT16_C(     4),  INT16_C(     9),  INT16_C(     9),  INT16_C(     9),  INT16_C(    10) } },
    { { -INT16_C( 19309),  INT16_C( 16108),  INT16_C( 20522), -INT16_C( 30360),  INT16_C( 25502),  INT16_C( 28526),  INT16_C( 22341),  INT16_C(  4942),
        -INT16_C(  4055),  INT16_C( 19859),  INT16_C( 25665),  INT16_C( 29006),  INT16_C(  1627),  INT16_C(   296), -INT16_C(  6529),  INT16_C(  5001) },
      {  INT16_C(     8),  INT16_C(    10),  INT16_C(     5),  INT16_C(     6),  INT16_C(     9),  INT16_C(    11),  INT16_C(     8),  INT16_C(     7),
         INT16_C(     7),  INT16_C(     8),  INT16_C(     5),  INT16_C(     8),  INT16_C(     7),  INT16_C(     3),  INT16_C(    12),  INT16_C(     6) } },
    { {  INT16_C( 30106), -INT16_C( 15279), -INT16_C( 17979),  INT16_C( 25421), -INT16_C( 17635),  INT16_C( 25298),  INT16_C(  8210),  INT16_C( 15221),
         INT16_C(  2064),  INT16_C( 20872), -INT16_C( 10644), -INT16_C( 14141), -INT16_C(  5155),  INT16_C( 23753),  INT16_C( 21201),  INT16_C( 27503) },
      {  INT16_C(     9),  INT16_C(     6),  INT16_C(     9),  INT16_C(     8),  INT16_C(    10),  INT16_C(     7),  INT16_C(     3),  INT16_C(    10),
         INT16_C(     2),  INT16_C(     5),  INT16_C(     9),  INT16_C(     7),  INT16_C(    12),  INT16_C(     8),  INT16_C(     7),  INT16_C(    11) } },
    { { -INT16_C( 15929), -INT16_C( 29649),  INT16_C( 31866), -INT16_C( 26641), -INT16_C( 15817),  INT16_C( 18937),  INT16_C( 28642), -INT16_C(  3196),
         INT16_C(  3191), -INT16_C(  7100),  INT16_C(  2019), -INT16_C( 16212),  INT16_C( 30194), -INT16_C( 15588), -INT16_C( 29496), -INT16_C( 28882) },
      {  INT16_C(     8),  INT16_C(     8),  INT16_C(    10),  INT16_C(    12),  INT16_C(     8),  INT16_C(     9),  INT16_C(    10),  INT16_C(     8),
         INT16_C(     8),  INT16_C(     6),  INT16_C(     8),  INT16_C(     6),  INT16_C(    10),  INT16_C(     7),  INT16_C(     6),  INT16_C(     9) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_popcnt_epi16(a);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_popcnt_epi16(a);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 28925), -INT16_C(  2141),  INT16_C( 32079), -INT16_C( 10827),  INT16_C( 15479),  INT16_C( 20092), -INT16_C( 22101), -INT16_C(  2787),
        -INT16_C(  1813),  INT16_C( 13408),  INT16_C(  3956), -INT16_C( 30393),  INT16_C( 18600),  INT16_C( 22286),  INT16_C(  5064), -INT16_C( 15032) },
      UINT16_C(60291),
      { -INT16_C( 11332),  INT16_C( 29288), -INT16_C(  8280),  INT16_C(  9390),  INT16_C( 23085),  INT16_C( 19405), -INT16_C( 18353), -INT16_C( 20669),
        -INT16_C( 18452),  INT16_C( 13502),  INT16_C( 26176),  INT16_C( 20092),  INT16_C( 17598),  INT16_C(  1633), -INT16_C(  6903), -INT16_C( 14607) },
      {  INT16_C(    10),  INT16_C(     7),  INT16_C( 32079), -INT16_C( 10827),  INT16_C( 15479),  INT16_C( 20092), -INT16_C( 22101),  INT16_C(     9),
         INT16_C(    11),  INT16_C(     9),  INT16_C(  3956),  INT16_C(     9),  INT16_C( 18600),  INT16_C(     5),  INT16_C(     7),  INT16_C(     9) } },
    { {  INT16_C( 22968),  INT16_C( 24632), -INT16_C(  6599),  INT16_C( 26245),  INT16_C( 21056), -INT16_C( 28495), -INT16_C(  3061), -INT16_C(  2241),
        -INT16_C(   341), -INT16_C(  5333), -INT16_C( 22428),  INT16_C(  8761), -INT16_C( 25620), -INT16_C(  2520),  INT16_C(  6528),  INT16_C( 14524) },
      UINT16_C(62579),
      { -INT16_C( 21352),  INT16_C(  7642),  INT16_C(  6930), -INT16_C( 15248),  INT16_C( 31659), -INT16_C(  5448),  INT16_C( 25714), -INT16_C( 24856),
         INT16_C( 19791), -INT16_C( 30394),  INT16_C( 12911), -INT16_C( 26588), -INT16_C( 23512), -INT16_C(  6991),  INT16_C(  9436),  INT16_C( 29912) },
      {  INT16_C(     7),  INT16_C(     9), -INT16_C(  6599),  INT16_C( 26245),  INT16_C(    11),  INT16_C(     9),  INT16_C(     7), -INT16_C(  2241),
        -INT16_C(   341), -INT16_C(  5333),  INT16_C(     9),  INT16_C(  8761),  INT16_C(     5),  INT16_C(     8),  INT16_C(     7),  INT16_C(     8) } },
    { { -INT16_C( 19504), -INT16_C(  7278),  INT16_C(   718),  INT16_C( 31143),  INT16_C( 24445), -INT16_C(  4253),  INT16_C( 19651),  INT16_C(  5005),
        -INT16_C( 11367),  INT16_C(  2204), -INT16_C( 16378),  INT16_C( 11936),  INT16_C( 21092),  INT16_C( 16403), -INT16_C(  5258),  INT16_C( 18356) },
      UINT16_C(18078),
      {  INT16_C( 27690), -INT16_C( 11960), -INT16_C( 14875),  INT16_C( 18736), -INT16_C(  2891),  INT16_C( 17045),  INT16_C( 11783), -INT16_C( 23786),
         INT16_C(  7222), -INT16_C( 10397), -INT16_C( 14518),  INT16_C( 23849), -INT16_C( 24825), -INT16_C( 17591), -INT16_C(  6170),  INT16_C(  4098) },
      { -INT16_C( 19504),  INT16_C(     6),  INT16_C(     9),  INT16_C(     5),  INT16_C(    10), -INT16_C(  4253),  INT16_C( 19651),  INT16_C(     7),
        -INT16_C( 11367),  INT16_C(    10),  INT16_C(     8),  INT16_C( 11936),  INT16_C( 21092),  INT16_C( 16403),  INT16_C(    11),  INT16_C( 18356) } },
    { {  INT16_C( 19028),  INT16_C( 14817),  INT16_C(  4624), -INT16_C( 14974),  INT16_C(  5894),  INT16_C(  3335),  INT16_C(  7493),  INT16_C( 31920),
         INT16_C(  4921), -INT16_C( 31661),  INT16_C( 31962), -INT16_C(  7711),  INT16_C( 10779),  INT16_C(   668), -INT16_C( 25070),  INT16_C( 26130) },
      UINT16_C(62697),
      { -INT16_C(  1633),  INT16_C(  8710),  INT16_C(  3262), -INT16_C( 15047),  INT16_C( 32537), -INT16_C( 13853),  INT16_C(  7419),  INT16_C( 20188),
        -INT16_C( 18784), -INT16_C( 32054), -INT16_C(  6761),  INT16_C( 13228), -INT16_C( 16665), -INT16_C(  1326), -INT16_C( 17628), -INT16_C( 15122) },
      {  INT16_C(    12),  INT16_C( 14817),  INT16_C(  4624),  INT16_C(     8),  INT16_C(  5894),  INT16_C(     9),  INT16_C(    10),  INT16_C(     9),
         INT16_C(  4921), -INT16_C( 31661),  INT16_C(    10), -INT16_C(  7711),  INT16_C(    12),  INT16_C(    10),  INT16_C(     8),  INT16_C(     9) } },
    { { -INT16_C(  2892),  INT16_C( 29414),  INT16_C(  7936),  INT16_C(  6455),  INT16_C(  6814), -INT16_C( 26142), -INT16_C( 16841), -INT16_C( 10265),
        -INT16_C( 20108),  INT16_C(  2905),  INT16_C(  1687),  INT16_C( 32318),  INT16_C(  4292), -INT16_C(  5768),  INT16_C( 26315),  INT16_C( 32685) },
      UINT16_C(37722),
      {  INT16_C( 23281),  INT16_C( 10674),  INT16_C( 20851),  INT16_C( 21827),  INT16_C( 31466), -INT16_C( 11757), -INT16_C( 30894), -INT16_C( 21629),
         INT16_C(  6802), -INT16_C( 11855),  INT16_C( 30361),  INT16_C(  4577), -INT16_C( 21153),  INT16_C(  3192), -INT16_C( 11732),  INT16_C(  7839) },
      { -INT16_C(  2892),  INT16_C(     7),  INT16_C(  7936),  INT16_C(     7),  INT16_C(    10), -INT16_C( 26142),  INT16_C(     7), -INT16_C( 10265),
         INT16_C(     6),  INT16_C(     8),  INT16_C(  1687),  INT16_C( 32318),  INT16_C(    11), -INT16_C(  5768),  INT16_C( 26315),  INT16_C(    10) } },
    { {  INT16_C( 20781), -INT16_C( 24505), -INT16_C( 30046), -INT16_C( 29194),  INT16_C(  2309),  INT16_C( 22367), -INT16_C(  7535),  INT16_C(  8962),
        -INT16_C( 19203), -INT16_C( 26892), -INT16_C( 10710), -INT16_C( 30297),  INT16_C(  8067), -INT16_C( 20587),  INT16_C( 13554),  INT16_C(  8141) },
      UINT16_C( 5253),
      {  INT16_C( 10431), -INT16_C( 19041), -INT16_C( 23371),  INT16_C(  5311),  INT16_C( 20731), -INT16_C(   522), -INT16_C(  3213),  INT16_C( 26801),
        -INT16_C(  9335),  INT16_C( 12606), -INT16_C( 16028), -INT16_C(  1712),  INT16_C( 17008),  INT16_C( 15917), -INT16_C( 19615),  INT16_C(  8530) },
      {  INT16_C(     9), -INT16_C( 24505),  INT16_C(     8), -INT16_C( 29194),  INT16_C(  2309),  INT16_C( 22367), -INT16_C(  7535),  INT16_C(     7),
        -INT16_C( 19203), -INT16_C( 26892),  INT16_C(     6), -INT16_C( 30297),  INT16_C(     5), -INT16_C( 20587),  INT16_C( 13554),  INT16_C(  8141) } },
    { { -INT16_C(  3621), -INT16_C( 28458), -INT16_C( 27243), -INT16_C( 28508), -INT16_C( 25883),  INT16_C( 22926),  INT16_C( 16270),  INT16_C(  6081),
        -INT16_C(   229),  INT16_C( 32584), -INT16_C( 26176),  INT16_C( 12409), -INT16_C( 22821),  INT16_C( 15726), -INT16_C( 16039),  INT16_C( 13406) },
      UINT16_C(13490),
      {  INT16_C( 18628),  INT16_C( 26826), -INT16_C( 20520),  INT16_C( 26115), -INT16_C( 28408), -INT16_C( 13914), -INT16_C( 15960), -INT16_C(  3640),
        -INT16_C( 30656), -INT16_C( 18038),  INT16_C( 26041),  INT16_C( 10080), -INT16_C( 18014),  INT16_C(   232), -INT16_C( 25618), -INT16_C( 19915) },
      { -INT16_C(  3621),  INT16_C(     7), -INT16_C( 27243), -INT16_C( 28508),  INT16_C(     4),  INT16_C(     8),  INT16_C( 16270),  INT16_C(     8),
        -INT16_C(   229),  INT16_C( 32584),  INT16_C(     9),  INT16_C( 12409),  INT16_C(     8),  INT16_C(     4), -INT16_C( 16039),  INT16_C( 13406) } },
    { { -INT16_C(    29), -INT16_C( 17637),  INT16_C(  7854), -INT16_C( 18654), -INT16_C( 14161),  INT16_C( 22400),  INT16_C( 18825), -INT16_C( 14008),
        -INT16_C( 11567), -INT16_C( 30077), -INT16_C(  7368), -INT16_C(  9550), -INT16_C( 25956), -INT16_C( 29989),  INT16_C(  4149),  INT16_C(  6205) },
      UINT16_C(22543),
      { -INT16_C( 16940), -INT16_C(  2442),  INT16_C(  9588), -INT16_C(  2626),  INT16_C( 18300), -INT16_C( 15042),  INT16_C(  3856), -INT16_C( 27753),
        -INT16_C( 12390),  INT16_C( 19574),  INT16_C(  5034), -INT16_C( 31258),  INT16_C(  7325), -INT16_C(  9579), -INT16_C( 23500),  INT16_C(  2098) },
      {  INT16_C(    10),  INT16_C(    11),  INT16_C(     7),  INT16_C(    12), -INT16_C( 14161),  INT16_C( 22400),  INT16_C( 18825), -INT16_C( 14008),
        -INT16_C( 11567), -INT16_C( 30077), -INT16_C(  7368),  INT16_C(     8),  INT16_C(     8), -INT16_C( 29989),  INT16_C(     6),  INT16_C(  6205) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_popcnt_epi16(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_popcnt_epi16(src, k, a);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(43105),
      { -INT16_C( 10498), -INT16_C( 17203),  INT16_C( 19147),  INT16_C(  2307),  INT16_C(  5135), -INT16_C( 23016), -INT16_C( 19801),  INT16_C(  7798),
         INT16_C(  8446), -INT16_C(  6863), -INT16_C( 12635),  INT16_C( 14849),  INT16_C( 13737), -INT16_C(  9250),  INT16_C( 16190),  INT16_C( 15492) },
      {  INT16_C(    12),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     9),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(     0),  INT16_C(    12),  INT16_C(     0),  INT16_C(     6) } },
    { UINT16_C(20757),
      { -INT16_C(  7943), -INT16_C(   869), -INT16_C( 21783),  INT16_C(   528), -INT16_C( 18351), -INT16_C( 14412), -INT16_C( 19498),  INT16_C(  2023),
        -INT16_C( 29544), -INT16_C( 26155),  INT16_C( 32454), -INT16_C( 23346),  INT16_C(  3162), -INT16_C(  8477), -INT16_C(  1719),  INT16_C( 16943) },
      {  INT16_C(     9),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0) } },
    { UINT16_C(52185),
      { -INT16_C( 15554),  INT16_C( 20341), -INT16_C( 14651),  INT16_C( 30983), -INT16_C(  8819),  INT16_C( 29740), -INT16_C( 15132), -INT16_C( 18176),
        -INT16_C( 14755),  INT16_C( 11320), -INT16_C( 28054),  INT16_C( 20024), -INT16_C( 32400), -INT16_C( 24761),  INT16_C(  8387),  INT16_C(   618) },
      {  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(    10),  INT16_C(     0),  INT16_C(     7),  INT16_C(     5),
         INT16_C(     9),  INT16_C(     6),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(     5) } },
    { UINT16_C(57571),
      { -INT16_C( 22447),  INT16_C( 22694),  INT16_C( 13346),  INT16_C( 20021),  INT16_C(  6568), -INT16_C( 22253),  INT16_C( 28882),  INT16_C(  2671),
        -INT16_C(  9572), -INT16_C( 10852),  INT16_C(  3112),  INT16_C( 28502),  INT16_C(  6828),  INT16_C(  5775),  INT16_C( 29468),  INT16_C( 28150) },
      {  INT16_C(     6),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     7),  INT16_C(     7),  INT16_C(     8),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(     8),  INT16_C(    11) } },
    { UINT16_C(40219),
      {  INT16_C( 15813), -INT16_C(  1327),  INT16_C( 31116), -INT16_C( 24813), -INT16_C(  6878), -INT16_C( 28145), -INT16_C( 21264), -INT16_C( 29588),
        -INT16_C( 27519), -INT16_C( 10343),  INT16_C( 17667), -INT16_C( 27919),  INT16_C(  3419),  INT16_C( 20997),  INT16_C(  8570),  INT16_C( 16367) },
      {  INT16_C(     9),  INT16_C(    10),  INT16_C(     0),  INT16_C(     9),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     5),  INT16_C(     0),  INT16_C(     5),  INT16_C(     8),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(    13) } },
    { UINT16_C(49246),
      { -INT16_C(  5575),  INT16_C( 19513),  INT16_C( 23689), -INT16_C( 26318),  INT16_C(  8942),  INT16_C( 23109), -INT16_C( 14674),  INT16_C( 18414),
        -INT16_C(  3683), -INT16_C( 28788), -INT16_C(  6013), -INT16_C( 30308),  INT16_C(  5946),  INT16_C( 10666),  INT16_C(  2134), -INT16_C( 28439) },
      {  INT16_C(     0),  INT16_C(     7),  INT16_C(     7),  INT16_C(     7),  INT16_C(     8),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(     7) } },
    { UINT16_C( 8947),
      {  INT16_C( 31964),  INT16_C(  3710),  INT16_C( 27669),  INT16_C( 23088), -INT16_C(  8250), -INT16_C( 19424), -INT16_C( 16858), -INT16_C( 19547),
         INT16_C( 10573), -INT16_C(  5733), -INT16_C( 10830),  INT16_C( 23552),  INT16_C( 22526), -INT16_C(  6300),  INT16_C( 22503), -INT16_C( 15607) },
      {  INT16_C(    10),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),  INT16_C(     5),  INT16_C(     9),  INT16_C(     9),
         INT16_C(     0),  INT16_C(    10),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(35028),
      { -INT16_C(  5678),  INT16_C(   756), -INT16_C( 17596),  INT16_C( 25825),  INT16_C(  2159),  INT16_C(  5410),  INT16_C( 28603),  INT16_C( 22078),
        -INT16_C(  4007),  INT16_C( 22827),  INT16_C( 10572), -INT16_C( 20304), -INT16_C( 26864),  INT16_C(  6408), -INT16_C(  9125),  INT16_C( 11681) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(    12),  INT16_C(     9),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     7) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_popcnt_epi16(test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_popcnt_epi16(k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(   327274205),  INT32_C(  1237076491),  INT32_C(  1343327205), -INT32_C(    61886264), -INT32_C(  1858176940),  INT32_C(   482220276), -INT32_C(  1738769486), -INT32_C(  1286435114) },
      {  INT32_C(          16),  INT32_C(          14),  INT32_C(          13),  INT32_C(          17),  INT32_C(          15),  INT32_C(          16),  INT32_C(          17),  INT32_C(          17) } },
    { {  INT32_C(  1741083484),  INT32_C(    45122077), -INT32_C(   715996659), -INT32_C(   959339918),  INT32_C(   257429530), -INT32_C(   634710488),  INT32_C(  1735624593),  INT32_C(  1897645333) },
      {  INT32_C(          18),  INT32_C(          10),  INT32_C(          14),  INT32_C(          15),  INT32_C(          11),  INT32_C(          14),  INT32_C(          17),  INT32_C(          15) } },
    { { -INT32_C(  1244077672),  INT32_C(  1907853668), -INT32_C(  1119418037), -INT32_C(   964421461),  INT32_C(  1356192808), -INT32_C(  2094333710), -INT32_C(  1645568376), -INT32_C(    82901661) },
      {  INT32_C(          16),  INT32_C(          16),  INT32_C(          16),  INT32_C(          13),  INT32_C(          14),  INT32_C(          12),  INT32_C(          17),  INT32_C(          17) } },
    { {  INT32_C(  1269884903), -INT32_C(  1145280656),  INT32_C(   477692784),  INT32_C(  1155726620), -INT32_C(   879380519),  INT32_C(  1062125751), -INT32_C(  1042466722),  INT32_C(   633138238) },
      {  INT32_C(          19),  INT32_C(          19),  INT32_C(          13),  INT32_C(          16),  INT32_C(          20),  INT32_C(          18),  INT32_C(          17),  INT32_C(          18) } },
    { {  INT32_C(  1148218579),  INT32_C(  1140796627),  INT32_C(  1281325104),  INT32_C(  1318076789), -INT32_C(  1340529160),  INT32_C(  1139763173), -INT32_C(   570110816), -INT32_C(  1945911112) },
      {  INT32_C(          14),  INT32_C(          19),  INT32_C(          15),  INT32_C(          13),  INT32_C(          14),  INT32_C(          20),  INT32_C(          13),  INT32_C(          11) } },
    { { -INT32_C(     3116244), -INT32_C(   817639521), -INT32_C(  1122262456), -INT32_C(   603149084), -INT32_C(  1215552047),  INT32_C(   771390605),  INT32_C(    17563464), -INT32_C(   326299969) },
      {  INT32_C(          19),  INT32_C(          21),  INT32_C(          15),  INT32_C(          15),  INT32_C(          16),  INT32_C(          19),  INT32_C(          14),  INT32_C(          19) } },
    { {  INT32_C(   552295809),  INT32_C(  1961897516), -INT32_C(  1255011375), -INT32_C(  1986969929), -INT32_C(   264233373), -INT32_C(   501400934), -INT32_C(   102553543), -INT32_C(  1209700298) },
      {  INT32_C(          14),  INT32_C(          15),  INT32_C(          15),  INT32_C(          17),  INT32_C(          13),  INT32_C(          16),  INT32_C(          17),  INT32_C(          18) } },
    { { -INT32_C(    86454067), -INT32_C(   798045953), -INT32_C(  1954176813),  INT32_C(  1108612830), -INT32_C(   835562444), -INT32_C(   927903602), -INT32_C(  1346268040), -INT32_C(   765024763) },
      {  INT32_C(          18),  INT32_C(          19),  INT32_C(          14),  INT32_C(          13),  INT32_C(          14),  INT32_C(          13),  INT32_C(          16),  INT32_C(          14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_popcnt_epi32(a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_popcnt_epi32(a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(   154113733), -INT32_C(  1066528431), -INT32_C(   724201447),  INT32_C(  1495929600),  INT32_C(  1337087235), -INT32_C(  1912577154),  INT32_C(  1437010170), -INT32_C(  1451079196) },
      UINT8_C(223),
      { -INT32_C(  1020218446), -INT32_C(  1310920671), -INT32_C(   642666298),  INT32_C(   803015386),  INT32_C(   548220093),  INT32_C(   874134316),  INT32_C(   723022050), -INT32_C(  1542798606) },
      {  INT32_C(          15),  INT32_C(          15),  INT32_C(          16),  INT32_C(          18),  INT32_C(          15), -INT32_C(  1912577154),  INT32_C(          13),  INT32_C(          13) } },
    { { -INT32_C(  1771619723), -INT32_C(   246987989), -INT32_C(   842335757), -INT32_C(  1057183997),  INT32_C(    14723540), -INT32_C(   952763420),  INT32_C(  1576160619), -INT32_C(  2080178929) },
      UINT8_C( 55),
      { -INT32_C(  1386079639),  INT32_C(  1537233762), -INT32_C(   983667170),  INT32_C(   345579370), -INT32_C(    84370689),  INT32_C(   476430287), -INT32_C(  1356020814),  INT32_C(   786870469) },
      {  INT32_C(          15),  INT32_C(          14),  INT32_C(          18), -INT32_C(  1057183997),  INT32_C(          23),  INT32_C(          20),  INT32_C(  1576160619), -INT32_C(  2080178929) } },
    { {  INT32_C(   769345995), -INT32_C(  1165460324),  INT32_C(  1417733866),  INT32_C(    90708229), -INT32_C(  2097192525), -INT32_C(   761305824), -INT32_C(   310260952),  INT32_C(  1176201339) },
      UINT8_C(177),
      {  INT32_C(  1934455799), -INT32_C(   497219333), -INT32_C(  1578651256),  INT32_C(  2069228570),  INT32_C(  1369167852),  INT32_C(  1098477174),  INT32_C(  1472030447),  INT32_C(  2013791105) },
      {  INT32_C(          21), -INT32_C(  1165460324),  INT32_C(  1417733866),  INT32_C(    90708229),  INT32_C(          19),  INT32_C(          17), -INT32_C(   310260952),  INT32_C(           9) } },
    { {  INT32_C(  1928025719), -INT32_C(   430684066),  INT32_C(   344407290),  INT32_C(   344972328),  INT32_C(   711273140), -INT32_C(  2006131048), -INT32_C(   958453436), -INT32_C(  1556158420) },
      UINT8_C( 62),
      {  INT32_C(  1922831914), -INT32_C(  1502838166), -INT32_C(   422608887),  INT32_C(   983229199),  INT32_C(   668124233),  INT32_C(  1500273200),  INT32_C(   579220026), -INT32_C(  1704973968) },
      {  INT32_C(  1928025719),  INT32_C(          14),  INT32_C(          14),  INT32_C(          17),  INT32_C(          14),  INT32_C(          14), -INT32_C(   958453436), -INT32_C(  1556158420) } },
    { { -INT32_C(  1441924033), -INT32_C(  2024769154),  INT32_C(   158146554),  INT32_C(  1279461123), -INT32_C(    59566388), -INT32_C(  1437147280), -INT32_C(  2100503535),  INT32_C(  1159474181) },
      UINT8_C( 40),
      { -INT32_C(  1549340887),  INT32_C(  1604136511), -INT32_C(  1553815909),  INT32_C(     7319274),  INT32_C(    24144673), -INT32_C(  1659757631),  INT32_C(   346264807), -INT32_C(   633542479) },
      { -INT32_C(  1441924033), -INT32_C(  2024769154),  INT32_C(   158146554),  INT32_C(          16), -INT32_C(    59566388),  INT32_C(          14), -INT32_C(  2100503535),  INT32_C(  1159474181) } },
    { {  INT32_C(   377349079), -INT32_C(  1401611759), -INT32_C(  1420830783), -INT32_C(  1481916795), -INT32_C(   341304534),  INT32_C(   512342582),  INT32_C(     3288143), -INT32_C(   338006508) },
      UINT8_C( 81),
      {  INT32_C(  1919025496),  INT32_C(  1311969143),  INT32_C(   500489822), -INT32_C(  1522041975), -INT32_C(   572837341), -INT32_C(   416482885), -INT32_C(  1694815189),  INT32_C(  1609295367) },
      {  INT32_C(          11), -INT32_C(  1401611759), -INT32_C(  1420830783), -INT32_C(  1481916795),  INT32_C(          18),  INT32_C(   512342582),  INT32_C(          18), -INT32_C(   338006508) } },
    { {  INT32_C(  1607552744), -INT32_C(  1146288803),  INT32_C(  1842905571),  INT32_C(   521281532),  INT32_C(   234745170),  INT32_C(   318056935),  INT32_C(  1571614806), -INT32_C(  1078159145) },
      UINT8_C(230),
      { -INT32_C(  1841095027),  INT32_C(  1299644107), -INT32_C(   162929705), -INT32_C(   498570763), -INT32_C(  1882630554),  INT32_C(  1004919883),  INT32_C(   538067592), -INT32_C(  1945710082) },
      {  INT32_C(  1607552744),  INT32_C(          21),  INT32_C(          20),  INT32_C(   521281532),  INT32_C(   234745170),  INT32_C(          19),  INT32_C(           7),  INT32_C(          16) } },
    { { -INT32_C(  1155642897),  INT32_C(   520655944),  INT32_C(  1813336439),  INT32_C(   542072506), -INT32_C(     5236556),  INT32_C(  2100991476), -INT32_C(   694333992),  INT32_C(   241345566) },
      UINT8_C(237),
      {  INT32_C(   355846529),  INT32_C(   579687633), -INT32_C(   924976790),  INT32_C(  1635581256),  INT32_C(  1129675693),  INT32_C(    35377845),  INT32_C(   337768816), -INT32_C(   721342636) },
      {  INT32_C(          13),  INT32_C(   520655944),  INT32_C(          19),  INT32_C(          17), -INT32_C(     5236556),  INT32_C(          14),  INT32_C(          12),  INT32_C(          14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_popcnt_epi32(src, k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_popcnt_epi32(src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(248),
      { -INT32_C(  1949701577),  INT32_C(  1911942007), -INT32_C(   960905784), -INT32_C(  1267525063),  INT32_C(  1114289776), -INT32_C(  1011716911), -INT32_C(  1139292531), -INT32_C(     4920120) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          16),  INT32_C(          14),  INT32_C(          16),  INT32_C(          17),  INT32_C(          20) } },
    { UINT8_C(214),
      {  INT32_C(  1766754941),  INT32_C(  1026670464), -INT32_C(  1820854408),  INT32_C(   553855851),  INT32_C(    49497493), -INT32_C(  1097877768), -INT32_C(  1182380851),  INT32_C(  2123334912) },
      {  INT32_C(           0),  INT32_C(          16),  INT32_C(          21),  INT32_C(           0),  INT32_C(          14),  INT32_C(           0),  INT32_C(          16),  INT32_C(          14) } },
    { UINT8_C( 16),
      { -INT32_C(  1668225059),  INT32_C(   269864216),  INT32_C(  1887152196), -INT32_C(   268067669),  INT32_C(  1172834191), -INT32_C(   485316713), -INT32_C(  1276916947),  INT32_C(   952328539) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          15),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 72),
      {  INT32_C(   543282515), -INT32_C(  1838845462), -INT32_C(  2009213460), -INT32_C(   501731878), -INT32_C(  1116119786),  INT32_C(  1005214832), -INT32_C(  1583964865), -INT32_C(  1276522656) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          15),  INT32_C(           0),  INT32_C(           0),  INT32_C(          18),  INT32_C(           0) } },
    { UINT8_C(164),
      { -INT32_C(  1148267446),  INT32_C(   245833785), -INT32_C(  1964494755), -INT32_C(  1516189112), -INT32_C(  1625989821), -INT32_C(   438349496), -INT32_C(  1236893465), -INT32_C(  1269106327) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(          14),  INT32_C(           0),  INT32_C(           0),  INT32_C(          17),  INT32_C(           0),  INT32_C(          18) } },
    { UINT8_C(205),
      {  INT32_C(   134639592),  INT32_C(  1197806615), -INT32_C(   946867971), -INT32_C(   301255536), -INT32_C(  1690916278),  INT32_C(   159521673),  INT32_C(  1534277985),  INT32_C(  2083006355) },
      {  INT32_C(          13),  INT32_C(           0),  INT32_C(          21),  INT32_C(          14),  INT32_C(           0),  INT32_C(           0),  INT32_C(          17),  INT32_C(          15) } },
    { UINT8_C(150),
      {  INT32_C(  1135445039), -INT32_C(   633277206), -INT32_C(  1201010557), -INT32_C(  1123919853), -INT32_C(  1438147186),  INT32_C(  1477136415), -INT32_C(   353605949), -INT32_C(  1098815345) },
      {  INT32_C(           0),  INT32_C(          16),  INT32_C(          12),  INT32_C(           0),  INT32_C(          17),  INT32_C(           0),  INT32_C(           0),  INT32_C(          16) } },
    { UINT8_C(236),
      {  INT32_C(   601227566),  INT32_C(  1252438082),  INT32_C(  1935498779), -INT32_C(    50193824), -INT32_C(  1306678175),  INT32_C(   511014327), -INT32_C(   911384479),  INT32_C(   263613409) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(          19),  INT32_C(          13),  INT32_C(           0),  INT32_C(          20),  INT32_C(          14),  INT32_C(          18) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_popcnt_epi32(k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_popcnt_epi32(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 9180157546750876299),  INT64_C( 6528454621326779297),  INT64_C( 8540427516066969233),  INT64_C( 2319718390403649481) },
      {  INT64_C(                  34),  INT64_C(                  31),  INT64_C(                  30),  INT64_C(                  33) } },
    { { -INT64_C( 9183970083979631002),  INT64_C( 5106138276520852382),  INT64_C( 8963694547182485852),  INT64_C(  753679642747623871) },
      {  INT64_C(                  31),  INT64_C(                  33),  INT64_C(                  34),  INT64_C(                  33) } },
    { { -INT64_C( 6674157605451593470),  INT64_C( 7968839243837828508), -INT64_C( 5678542207945178622),  INT64_C( 4164557759809231644) },
      {  INT64_C(                  19),  INT64_C(                  28),  INT64_C(                  29),  INT64_C(                  32) } },
    { {  INT64_C( 2246305019510514052),  INT64_C( 6154178043267076583), -INT64_C( 6616003870184520309),  INT64_C( 3766751671039112662) },
      {  INT64_C(                  28),  INT64_C(                  30),  INT64_C(                  31),  INT64_C(                  27) } },
    { { -INT64_C( 4488705803573960687), -INT64_C( 5124495846947543750), -INT64_C(  210150587542082328), -INT64_C( 4936418349722928486) },
      {  INT64_C(                  30),  INT64_C(                  30),  INT64_C(                  34),  INT64_C(                  34) } },
    { {  INT64_C( 6938925685168684209),  INT64_C( 1229428999754417961),  INT64_C( 4962852074585998779), -INT64_C( 1335866784484496879) },
      {  INT64_C(                  23),  INT64_C(                  31),  INT64_C(                  33),  INT64_C(                  34) } },
    { { -INT64_C(  878547404063127992),  INT64_C( 4974042766826453964),  INT64_C( 3570235340317231518),  INT64_C( 8005820303234833137) },
      {  INT64_C(                  35),  INT64_C(                  32),  INT64_C(                  23),  INT64_C(                  33) } },
    { {  INT64_C( 2731340101872096041),  INT64_C( 2897261014923555174),  INT64_C( 6052552450516212908),  INT64_C( 8623438146849270550) },
      {  INT64_C(                  36),  INT64_C(                  27),  INT64_C(                  36),  INT64_C(                  34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_popcnt_epi64(a);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_popcnt_epi64(a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 6411112928500681836), -INT64_C( 3344541264769231561), -INT64_C( 8552343216328560007), -INT64_C( 3222033719442015143) },
      UINT8_C(149),
      { -INT64_C( 3419311312166813060),  INT64_C( 7799409623512917238), -INT64_C( 5051034657582977387), -INT64_C( 1869007681694457487) },
      {  INT64_C(                  29), -INT64_C( 3344541264769231561),  INT64_C(                  37), -INT64_C( 3222033719442015143) } },
    { {  INT64_C(  198378341499921013), -INT64_C( 6479832064508690196),  INT64_C( 3956161331365980017),  INT64_C( 8110350686751819580) },
      UINT8_C(162),
      {  INT64_C( 2341222134743720137), -INT64_C( 2383573844977703817),  INT64_C(  532790350153259276),  INT64_C( 7128478688399657867) },
      {  INT64_C(  198378341499921013),  INT64_C(                  37),  INT64_C( 3956161331365980017),  INT64_C( 8110350686751819580) } },
    { { -INT64_C( 4390604685930423343),  INT64_C( 2858141013359018900), -INT64_C( 5527970457609875903), -INT64_C( 8234009778809058625) },
      UINT8_C(135),
      { -INT64_C( 3192322540603998547),  INT64_C( 8520270810834697940),  INT64_C( 1357926307028959333), -INT64_C( 7366943499552411312) },
      {  INT64_C(                  36),  INT64_C(                  38),  INT64_C(                  25), -INT64_C( 8234009778809058625) } },
    { {  INT64_C(  161119330446579417), -INT64_C( 6519737540193342745), -INT64_C( 4136390821928885059), -INT64_C( 7256207463878072633) },
      UINT8_C( 92),
      {  INT64_C( 7733959573212038147),  INT64_C(  974273859419857802),  INT64_C(  751056209364323086),  INT64_C( 7957129826191286092) },
      {  INT64_C(  161119330446579417), -INT64_C( 6519737540193342745),  INT64_C(                  25),  INT64_C(                  34) } },
    { {  INT64_C(  943556360226469739),  INT64_C( 2488337838145651602), -INT64_C( 6839784394211259546), -INT64_C( 5535732874437533613) },
      UINT8_C( 23),
      {  INT64_C( 4308439024497417992), -INT64_C( 2793232535703829125),  INT64_C( 4305669231051949625), -INT64_C( 5352187662281048190) },
      {  INT64_C(                  35),  INT64_C(                  37),  INT64_C(                  33), -INT64_C( 5535732874437533613) } },
    { {  INT64_C( 8378867912037716629),  INT64_C( 4730052880957609724),  INT64_C( 2621779575812575948), -INT64_C( 5814007366675929874) },
      UINT8_C(209),
      { -INT64_C( 7354027430294930627),  INT64_C( 3665053094701546377),  INT64_C( 5399244645254562704),  INT64_C( 1589229537972226238) },
      {  INT64_C(                  37),  INT64_C( 4730052880957609724),  INT64_C( 2621779575812575948), -INT64_C( 5814007366675929874) } },
    { { -INT64_C( 6815077527090177586),  INT64_C( 9171737798669044919), -INT64_C( 3296235714462737263), -INT64_C( 8727379348844206605) },
      UINT8_C(247),
      { -INT64_C( 3485873231103043348),  INT64_C( 1909876981663446370),  INT64_C( 6781015558691190972), -INT64_C( 5321392422287644911) },
      {  INT64_C(                  35),  INT64_C(                  35),  INT64_C(                  31), -INT64_C( 8727379348844206605) } },
    { {  INT64_C( 5154156355403003381),  INT64_C( 4614986223788181234),  INT64_C( 5497070213069814321), -INT64_C(  942481588107911061) },
      UINT8_C(214),
      {  INT64_C( 8626648598550719113), -INT64_C( 1286555370642495173), -INT64_C( 5002243156508864348),  INT64_C( 4425254701905725937) },
      {  INT64_C( 5154156355403003381),  INT64_C(                  38),  INT64_C(                  26), -INT64_C(  942481588107911061) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_popcnt_epi64(src, k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_popcnt_epi64(src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 83),
      {  INT64_C( 7234184782249460517), -INT64_C( 8153759990556370697),  INT64_C( 6744037726349688880), -INT64_C( 5092077406075671975) },
      {  INT64_C(                  28),  INT64_C(                  32),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 81),
      { -INT64_C( 7003817296455146791), -INT64_C( 2756015124843331446),  INT64_C( 2922216025895036562), -INT64_C( 4792825181070651428) },
      {  INT64_C(                  34),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 88),
      {  INT64_C( 6955032686291293065),  INT64_C( 4365416124191937881), -INT64_C( 1934468292668634753),  INT64_C( 6408208641140806175) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  34) } },
    { UINT8_C( 26),
      { -INT64_C( 1358720562914241651), -INT64_C( 8744582289087584493),  INT64_C( 7547401952936455994), -INT64_C( 3662113416619273588) },
      {  INT64_C(                   0),  INT64_C(                  27),  INT64_C(                   0),  INT64_C(                  29) } },
    { UINT8_C(226),
      { -INT64_C( 2047546027497842521),  INT64_C( 5739036590934637163),  INT64_C( 5932030161924211460),  INT64_C( 4140603090087929093) },
      {  INT64_C(                   0),  INT64_C(                  36),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(248),
      {  INT64_C(  739320761825934128), -INT64_C( 7610035177591755464), -INT64_C( 2093636728507717090),  INT64_C( 3158341635452208507) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  38) } },
    { UINT8_C(105),
      { -INT64_C(  911482747879881847),  INT64_C( 5045680974219098413),  INT64_C( 7554407820859535730),  INT64_C( 1094532518484685337) },
      {  INT64_C(                  29),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  29) } },
    { UINT8_C(146),
      {  INT64_C( 4889444141946646761), -INT64_C( 5233280868665016047),  INT64_C( 4694725049517259113),  INT64_C(  687316950435032935) },
      {  INT64_C(                   0),  INT64_C(                  37),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_popcnt_epi64(k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_popcnt_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C(  93), -INT8_C(  54), -INT8_C(  39), -INT8_C(  75), -INT8_C( 109), -INT8_C(  78), -INT8_C(  61),  INT8_C(  15),
        -INT8_C(  31), -INT8_C(   5),  INT8_C(   3),  INT8_C(  55), -INT8_C( 115),  INT8_C( 109),  INT8_C( 124),  INT8_C(  65),
        -INT8_C(  45), -INT8_C(  28),  INT8_C(  15), -INT8_C(   6), -INT8_C(  49),  INT8_C(  24),  INT8_C(  53),  INT8_C(  81),
        -INT8_C(  20),  INT8_C(  15),  INT8_C(  96), -INT8_C(  81),  INT8_C(  90), -INT8_C(  81),  INT8_C(  17), -INT8_C(   3),
         INT8_C( 121), -INT8_C(  22), -INT8_C(  77),  INT8_C(  13), -INT8_C( 100),  INT8_C( 118),  INT8_C(  28),  INT8_C( 125),
         INT8_C( 113),  INT8_C(  31), -INT8_C(  76), -INT8_C(   1), -INT8_C( 116),  INT8_C(  48),  INT8_C(  64),  INT8_C(  95),
         INT8_C(  21),  INT8_C(  80),  INT8_C(  89), -INT8_C(  28),  INT8_C( 104), -INT8_C( 114),  INT8_C(  53),  INT8_C(  84),
        -INT8_C(  98), -INT8_C( 106),  INT8_C(   3), -INT8_C(   8),  INT8_C(  69),  INT8_C(  20), -INT8_C(  10), -INT8_C(  66) },
      {  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   4),  INT8_C(   7),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   2),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6),  INT8_C(   6),  INT8_C(   2),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2),  INT8_C(   7),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   6),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   8),  INT8_C(   3),  INT8_C(   2),  INT8_C(   1),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(   3),  INT8_C(   2),  INT8_C(   6),  INT8_C(   6) } },
    { { -INT8_C(   2), -INT8_C(  87), -INT8_C(  53), -INT8_C( 102),  INT8_C(  31), -INT8_C(  24),  INT8_C(  23), -INT8_C( 111),
         INT8_C(   7), -INT8_C(  53), -INT8_C( 112), -INT8_C( 108), -INT8_C(   5), -INT8_C(  48), -INT8_C(  13),  INT8_C(  16),
         INT8_C(  32),  INT8_C(  77), -INT8_C(  12), -INT8_C( 120), -INT8_C(  37),  INT8_C(  42), -INT8_C(  36),  INT8_C( 121),
        -INT8_C(  64), -INT8_C(  33),  INT8_C( 114),  INT8_C(   5), -INT8_C(  13),  INT8_C( 104), -INT8_C(  61), -INT8_C(  15),
         INT8_C(  17), -INT8_C( 113), -INT8_C( 117),  INT8_C(  48),  INT8_C( 119), -INT8_C(  94), -INT8_C(  63),  INT8_C( 126),
         INT8_C( 109),  INT8_C(  81),  INT8_C(  18),  INT8_C( 105),  INT8_C(  34),  INT8_C(   6),  INT8_C( 121),  INT8_C(  66),
         INT8_C(  83),  INT8_C( 110), -INT8_C(  53),  INT8_C(  46), -INT8_C( 104), -INT8_C(  89), -INT8_C(  88),  INT8_C(  88),
        -INT8_C( 121),  INT8_C(  26),  INT8_C(  93),  INT8_C( 122), -INT8_C( 126),  INT8_C(  32),  INT8_C( 108), -INT8_C( 109) },
      {  INT8_C(   7),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   5),  INT8_C(   2),  INT8_C(   3),  INT8_C(   7),  INT8_C(   3),  INT8_C(   6),  INT8_C(   1),
         INT8_C(   1),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   7),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6),
         INT8_C(   5),  INT8_C(   3),  INT8_C(   2),  INT8_C(   4),  INT8_C(   2),  INT8_C(   2),  INT8_C(   5),  INT8_C(   2),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   2),  INT8_C(   1),  INT8_C(   4),  INT8_C(   4) } },
    { { -INT8_C(  81), -INT8_C(   9), -INT8_C(  61),  INT8_C(  38), -INT8_C( 102), -INT8_C( 123), -INT8_C(  91),  INT8_C(   7),
        -INT8_C(  42), -INT8_C(  73),  INT8_C( 112), -INT8_C(   8), -INT8_C(  67), -INT8_C(  22),  INT8_C(  59),  INT8_C(  16),
         INT8_C(  88),  INT8_C(   6),  INT8_C(  63), -INT8_C(  16), -INT8_C(  83), -INT8_C(  25),  INT8_C(  72),  INT8_C(  52),
         INT8_C(   1), -INT8_C(  91), -INT8_C(  81), -INT8_C( 125), -INT8_C(  59),  INT8_C(  27),  INT8_C(  22),  INT8_C( 117),
         INT8_C(  18), -INT8_C(  39), -INT8_C( 101), -INT8_C(  84),  INT8_C(  94),  INT8_C(  64), -INT8_C(  76),  INT8_C(  53),
        -INT8_C(   8),  INT8_C(  36),  INT8_C(  45), -INT8_C(  75),  INT8_C(  14),  INT8_C( 104), -INT8_C(  58),  INT8_C( 102),
         INT8_C( 110),  INT8_C(   5),  INT8_C(  86),  INT8_C(  28), -INT8_C(  20), -INT8_C(  98),  INT8_C(  80), -INT8_C(  19),
         INT8_C(  67), -INT8_C(   1),  INT8_C( 112),  INT8_C(   9),  INT8_C(  26), -INT8_C( 122),  INT8_C( 126),  INT8_C(  45) },
      {  INT8_C(   6),  INT8_C(   7),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   1),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   2),  INT8_C(   3),
         INT8_C(   1),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   1),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   2),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   8),  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6),  INT8_C(   4) } },
    { {  INT8_C(  95),  INT8_C(  25), -INT8_C(  39), -INT8_C(  66),  INT8_C(  90), -INT8_C( 115), -INT8_C(  13),  INT8_C(  82),
        -INT8_C(  78),  INT8_C(  32),  INT8_C(   7), -INT8_C(  64), -INT8_C( 119), -INT8_C(  51),  INT8_C(  39), -INT8_C(   9),
        -INT8_C(  46),  INT8_C( 125),  INT8_C(  19), -INT8_C(  66),  INT8_C(  28),  INT8_C( 100), -INT8_C(  85),  INT8_C(  95),
         INT8_C(  99),  INT8_C(  27),  INT8_C( 104),  INT8_C( 126), -INT8_C(  95), -INT8_C(  26), -INT8_C(  85),  INT8_C(   1),
         INT8_C(   0), -INT8_C( 124), -INT8_C(  65),  INT8_C(  90),  INT8_C(  18), -INT8_C(  78), -INT8_C(  84), -INT8_C(  60),
        -INT8_C(  46), -INT8_C(  77), -INT8_C( 124),  INT8_C(  91), -INT8_C( 127), -INT8_C(  85),  INT8_C(  83),  INT8_C(  83),
         INT8_C(  41),  INT8_C( 102),  INT8_C(  18),  INT8_C(  69), -INT8_C(  54), -INT8_C(  67), -INT8_C(  92),  INT8_C(  46),
        -INT8_C(  39),  INT8_C(  13), -INT8_C(  84),  INT8_C( 122), -INT8_C(  13),  INT8_C(  87),  INT8_C( 123), -INT8_C(  13) },
      {  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   1),  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   7),
         INT8_C(   4),  INT8_C(   6),  INT8_C(   3),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   1),
         INT8_C(   0),  INT8_C(   2),  INT8_C(   7),  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   5),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6) } },
    { { -INT8_C(  37),  INT8_C(  58),  INT8_C(  77), -INT8_C(  19), -INT8_C(  20), -INT8_C(   7), -INT8_C(  79), -INT8_C(  65),
        -INT8_C(  83),  INT8_C(  54),  INT8_C(  26),  INT8_C(  46), -INT8_C(  31),  INT8_C( 109), -INT8_C( 127),  INT8_C(  10),
        -INT8_C(  44), -INT8_C( 109),  INT8_C(  79), -INT8_C(  98),  INT8_C(  81), -INT8_C(  12), -INT8_C(  52),  INT8_C(  42),
         INT8_C(   1),  INT8_C( 120), -INT8_C(  92), -INT8_C(  12), -INT8_C(  49),  INT8_C(  32), -INT8_C(  24), -INT8_C(  85),
         INT8_C(  90),  INT8_C(  53), -INT8_C( 104),  INT8_C(  71),  INT8_C(  47),  INT8_C(  74),  INT8_C(   6), -INT8_C(  36),
             INT8_MIN,  INT8_C(  32),  INT8_C(  10),  INT8_C(  97), -INT8_C( 114), -INT8_C( 117),  INT8_C( 108),  INT8_C(  98),
         INT8_C(  31), -INT8_C(  69),  INT8_C(   0),  INT8_C( 112), -INT8_C(  81), -INT8_C(  51), -INT8_C( 102), -INT8_C(  80),
         INT8_C(  69),  INT8_C(  62), -INT8_C(  91),  INT8_C(  21),  INT8_C(  94), -INT8_C( 115), -INT8_C(  64), -INT8_C(  71) },
      {  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   2),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   1),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   1),  INT8_C(   4),  INT8_C(   5),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   2),  INT8_C(   5),
         INT8_C(   1),  INT8_C(   1),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   6),  INT8_C(   0),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5) } },
    { { -INT8_C(  62),  INT8_C(  88),  INT8_C(   0), -INT8_C(  15), -INT8_C(  94),  INT8_C(   6), -INT8_C(  51),  INT8_C(  34),
         INT8_C(  38), -INT8_C(  41), -INT8_C( 124), -INT8_C(  76),  INT8_C(  99), -INT8_C(  16),  INT8_C(  22), -INT8_C( 126),
        -INT8_C(  85),  INT8_C(  23), -INT8_C(  14),  INT8_C(  91), -INT8_C(  28), -INT8_C( 116),  INT8_C(  11),  INT8_C(  41),
        -INT8_C(  54), -INT8_C(  80),  INT8_C(  62),  INT8_C(  41),  INT8_C(  61), -INT8_C(   2), -INT8_C(  30),  INT8_C(   0),
         INT8_C(  87), -INT8_C(  30), -INT8_C(  15), -INT8_C(   7), -INT8_C(  24), -INT8_C(  65),  INT8_C(  28),  INT8_C(  14),
        -INT8_C( 106), -INT8_C(  96), -INT8_C(  61), -INT8_C(   7), -INT8_C( 112), -INT8_C(  39),  INT8_C( 123),  INT8_C(  59),
        -INT8_C(  16),  INT8_C( 109), -INT8_C( 106), -INT8_C(  44), -INT8_C(   7), -INT8_C(  94), -INT8_C(   2), -INT8_C(  60),
         INT8_C(  82),  INT8_C(  60), -INT8_C(  19), -INT8_C( 112),  INT8_C(  59), -INT8_C(  49), -INT8_C( 112), -INT8_C( 110) },
      {  INT8_C(   3),  INT8_C(   3),  INT8_C(   0),  INT8_C(   5),  INT8_C(   3),  INT8_C(   2),  INT8_C(   5),  INT8_C(   2),
         INT8_C(   3),  INT8_C(   6),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   2),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   7),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3),  INT8_C(   7),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2),  INT8_C(   5),  INT8_C(   6),  INT8_C(   2),  INT8_C(   3) } },
    { { -INT8_C(  79), -INT8_C( 127), -INT8_C( 117), -INT8_C( 103),  INT8_C(  64), -INT8_C(  89), -INT8_C(  89), -INT8_C(  41),
         INT8_C(  71),  INT8_C( 106), -INT8_C(  48), -INT8_C(  41),  INT8_C(  68),  INT8_C(  76),  INT8_C(  19),  INT8_C(  52),
        -INT8_C(  71), -INT8_C(  87),  INT8_C(   9), -INT8_C(  77),  INT8_C(  75),  INT8_C(   7),  INT8_C( 119), -INT8_C(  98),
         INT8_C(  67),  INT8_C( 100),  INT8_C(  46),  INT8_C( 126),  INT8_C(  51), -INT8_C(  66),  INT8_C(  16), -INT8_C(  28),
         INT8_C(  63), -INT8_C( 100),  INT8_C( 125),      INT8_MIN,  INT8_C(  67),  INT8_C(  36),  INT8_C(  87), -INT8_C( 117),
        -INT8_C( 113),  INT8_C(  39),  INT8_C(  98), -INT8_C(  45),  INT8_C( 115),  INT8_C( 117),  INT8_C(   7),  INT8_C(  45),
         INT8_C(  31),  INT8_C(  16), -INT8_C(  32),  INT8_C( 106),  INT8_C(  23),  INT8_C(  87),  INT8_C(   8),  INT8_C(  91),
        -INT8_C(  69),  INT8_C(  54), -INT8_C(  39), -INT8_C(  18), -INT8_C(  12), -INT8_C(  22), -INT8_C(  46),  INT8_C(  52) },
      {  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   1),  INT8_C(   5),  INT8_C(   5),  INT8_C(   6),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(   2),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   4),  INT8_C(   6),  INT8_C(   1),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   4),  INT8_C(   6),  INT8_C(   1),  INT8_C(   3),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   1),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   1),  INT8_C(   5),
         INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3) } },
    { { -INT8_C( 122),  INT8_C(  79), -INT8_C(  76), -INT8_C(  55),  INT8_C( 115),  INT8_C(  11),  INT8_C(  84),  INT8_C(   2),
         INT8_C(  50), -INT8_C(  73), -INT8_C(  43), -INT8_C(  90),  INT8_C(  44), -INT8_C(  35), -INT8_C(  45),  INT8_C(  75),
        -INT8_C(  19), -INT8_C(  77), -INT8_C(  74),  INT8_C(   5),  INT8_C(  10), -INT8_C(  66),  INT8_C(  96), -INT8_C(  59),
        -INT8_C(  11),  INT8_C(  57), -INT8_C(  77), -INT8_C(  23),  INT8_C(  35), -INT8_C( 123),  INT8_C(  29), -INT8_C(  87),
        -INT8_C(  44), -INT8_C(  47),  INT8_C( 115),  INT8_C(  71), -INT8_C(  36), -INT8_C(  57),  INT8_C(  74),  INT8_C(  15),
         INT8_C( 126),  INT8_C(  31), -INT8_C(  75), -INT8_C(  85), -INT8_C(   4), -INT8_C( 120), -INT8_C(  10), -INT8_C(  22),
         INT8_C(  59), -INT8_C(  84), -INT8_C(  17),  INT8_C(  69),  INT8_C( 107),  INT8_C(  79),  INT8_C(  10),  INT8_C(  96),
        -INT8_C( 120), -INT8_C(  67),  INT8_C(  73), -INT8_C(  84),  INT8_C(  66),  INT8_C( 103),  INT8_C(  85),  INT8_C(  22) },
      {  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   1),
         INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   2),  INT8_C(   2),  INT8_C(   6),  INT8_C(   2),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   6),  INT8_C(   2),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   7),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   2),  INT8_C(   2),
         INT8_C(   2),  INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i r = simde_mm512_popcnt_epi8(a);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_popcnt_epi8(a);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  66), -INT8_C( 119),  INT8_C(  39),  INT8_C(  96),  INT8_C(  39),  INT8_C(  56), -INT8_C(  40),  INT8_C( 115),
        -INT8_C(  81),  INT8_C(  14),  INT8_C(  36), -INT8_C(  78), -INT8_C(  24),  INT8_C(  78), -INT8_C(  53), -INT8_C(  77),
         INT8_C(  87), -INT8_C(  84), -INT8_C(  31), -INT8_C(  43), -INT8_C(  29),  INT8_C(  95),  INT8_C(  86),  INT8_C( 121),
         INT8_C(  57), -INT8_C(  14),  INT8_C(  64),  INT8_C(  32), -INT8_C(   1),  INT8_C(  13),  INT8_C(  91),  INT8_C(  65),
        -INT8_C( 106), -INT8_C( 126), -INT8_C(  95), -INT8_C(  67), -INT8_C(  70),  INT8_C( 122),  INT8_C(  49),  INT8_C( 105),
        -INT8_C( 120),  INT8_C(  85),  INT8_C(  27),  INT8_C( 113), -INT8_C(  92), -INT8_C(  25),  INT8_C(  36), -INT8_C(   5),
        -INT8_C( 109),  INT8_C(   5), -INT8_C(  48),  INT8_C( 119),  INT8_C( 100),  INT8_C(  39), -INT8_C(  16), -INT8_C(  98),
         INT8_C(  25),  INT8_C(  48), -INT8_C(  66),  INT8_C(  25),  INT8_C(  62),  INT8_C(  25),  INT8_C(  90), -INT8_C(  44) },
      UINT64_C(18356886994188172444),
      {  INT8_C(  24), -INT8_C(  37),  INT8_C( 111), -INT8_C(  68), -INT8_C(  62), -INT8_C( 109), -INT8_C(  72),  INT8_C(  86),
        -INT8_C( 104), -INT8_C( 120), -INT8_C(  51), -INT8_C(   3), -INT8_C(  81), -INT8_C(  67), -INT8_C( 101), -INT8_C(  55),
        -INT8_C(  19),  INT8_C(  89), -INT8_C(  30),  INT8_C(  43),  INT8_C( 115),  INT8_C(  60),  INT8_C(   0),  INT8_C(  15),
         INT8_C(  56), -INT8_C( 110),  INT8_C( 101), -INT8_C(  82),  INT8_C(  85),  INT8_C(  37), -INT8_C(  83),  INT8_C( 109),
         INT8_C(   1),  INT8_C(  28),  INT8_C(  42), -INT8_C(  61), -INT8_C(  80), -INT8_C(  30),  INT8_C(  25),  INT8_C(  72),
         INT8_C( 106), -INT8_C(  26),  INT8_C(  69),  INT8_C(  26), -INT8_C(  93), -INT8_C(  32), -INT8_C(  29), -INT8_C( 111),
         INT8_C(  58), -INT8_C(  59), -INT8_C(  68), -INT8_C(  83),  INT8_C(   1), -INT8_C(  68), -INT8_C(  68),  INT8_C(  58),
         INT8_C(  78),  INT8_C(  33), -INT8_C(  24), -INT8_C(  93),  INT8_C(  71), -INT8_C( 107),  INT8_C(  17),  INT8_C(  72) },
      {  INT8_C(  66), -INT8_C( 119),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),  INT8_C(  56), -INT8_C(  40),  INT8_C(   4),
        -INT8_C(  81),  INT8_C(  14),  INT8_C(   5),  INT8_C(   7),  INT8_C(   6),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),
         INT8_C(  87),  INT8_C(   4), -INT8_C(  31), -INT8_C(  43),  INT8_C(   5),  INT8_C(  95),  INT8_C(  86),  INT8_C(   4),
         INT8_C(  57),  INT8_C(   3),  INT8_C(   4),  INT8_C(  32),  INT8_C(   4),  INT8_C(  13),  INT8_C(   5),  INT8_C(  65),
        -INT8_C( 106),  INT8_C(   3),  INT8_C(   3), -INT8_C(  67),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C( 105),
         INT8_C(   4),  INT8_C(   5),  INT8_C(  27),  INT8_C( 113), -INT8_C(  92), -INT8_C(  25),  INT8_C(   5),  INT8_C(   3),
        -INT8_C( 109),  INT8_C(   5), -INT8_C(  48),  INT8_C( 119),  INT8_C( 100),  INT8_C(  39),  INT8_C(   5),  INT8_C(   4),
         INT8_C(  25),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   2),  INT8_C(   2) } },
    { { -INT8_C(  78),  INT8_C(  59),  INT8_C(  11),  INT8_C(  98),  INT8_C(  29),  INT8_C(  37), -INT8_C(  86), -INT8_C( 121),
         INT8_C(  11), -INT8_C(  16), -INT8_C(  95), -INT8_C(  81), -INT8_C(  48), -INT8_C( 124),  INT8_C(  64),  INT8_C(  10),
         INT8_C(  73), -INT8_C(   4), -INT8_C(  73),  INT8_C(  75), -INT8_C(  71),  INT8_C( 115), -INT8_C( 123),  INT8_C(   7),
        -INT8_C( 107),  INT8_C( 109), -INT8_C(  85), -INT8_C(  36),  INT8_C(   3), -INT8_C(  68),  INT8_C(  36), -INT8_C(  75),
        -INT8_C(   9),  INT8_C(  47),  INT8_C(  23),  INT8_C(  20),  INT8_C(  84), -INT8_C(  63), -INT8_C( 101),  INT8_C(  96),
        -INT8_C(  79),  INT8_C(  61),  INT8_C(  15), -INT8_C( 126), -INT8_C(  63),  INT8_C(  79), -INT8_C( 116),  INT8_C(  11),
         INT8_C(  75),  INT8_C(  68),  INT8_C(  86),  INT8_C(   4), -INT8_C(  73), -INT8_C(  37),  INT8_C(  12),  INT8_C(  76),
         INT8_C(  72), -INT8_C(  73),  INT8_C(  40),  INT8_C(  75),  INT8_C( 115),  INT8_C(  76),  INT8_C(   0),  INT8_C( 106) },
      UINT64_C( 9957487199412688764),
      {  INT8_C(  86),  INT8_C(  63),  INT8_C(  12),  INT8_C(  24), -INT8_C( 114), -INT8_C( 103),  INT8_C(  35), -INT8_C(  38),
        -INT8_C(  35),  INT8_C( 121), -INT8_C(  34), -INT8_C( 108),  INT8_C(  84), -INT8_C(  22), -INT8_C(  31), -INT8_C( 100),
        -INT8_C(  95),  INT8_C(   9), -INT8_C(  24),  INT8_C(  20),  INT8_C(  86), -INT8_C(  24),  INT8_C( 126), -INT8_C(  46),
         INT8_C(   0), -INT8_C(   4), -INT8_C(  94), -INT8_C(  39),  INT8_C(  22), -INT8_C(  45),  INT8_C(  99),  INT8_C( 108),
         INT8_C(  18),  INT8_C( 112), -INT8_C( 124), -INT8_C(  95),  INT8_C(   9), -INT8_C(  89),  INT8_C( 123), -INT8_C(  26),
         INT8_C(  32),  INT8_C(  89),  INT8_C( 122),  INT8_C( 116),  INT8_C(  68),  INT8_C(  91),  INT8_C(  17), -INT8_C(  27),
         INT8_C( 101), -INT8_C(   7), -INT8_C(   6), -INT8_C(  69), -INT8_C(  31),  INT8_C( 120), -INT8_C( 115), -INT8_C(  31),
         INT8_C( 117),  INT8_C(  47), -INT8_C(  70), -INT8_C( 117),  INT8_C(   2),  INT8_C(  30), -INT8_C(   9),  INT8_C(  21) },
      { -INT8_C(  78),  INT8_C(  59),  INT8_C(   2),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3), -INT8_C( 121),
         INT8_C(   6),  INT8_C(   5),  INT8_C(   6), -INT8_C(  81),  INT8_C(   3), -INT8_C( 124),  INT8_C(  64),  INT8_C(  10),
         INT8_C(  73),  INT8_C(   2),  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6),  INT8_C(   7),
        -INT8_C( 107),  INT8_C( 109), -INT8_C(  85), -INT8_C(  36),  INT8_C(   3), -INT8_C(  68),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   2),  INT8_C(  47),  INT8_C(  23),  INT8_C(   3),  INT8_C(   2), -INT8_C(  63),  INT8_C(   6),  INT8_C(   5),
         INT8_C(   1),  INT8_C(  61),  INT8_C(  15),  INT8_C(   4),  INT8_C(   2),  INT8_C(  79), -INT8_C( 116),  INT8_C(  11),
         INT8_C(  75),  INT8_C(  68),  INT8_C(  86),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(  12),  INT8_C(  76),
         INT8_C(  72),  INT8_C(   5),  INT8_C(  40),  INT8_C(   4),  INT8_C( 115),  INT8_C(  76),  INT8_C(   0),  INT8_C(   3) } },
    { { -INT8_C( 114),  INT8_C( 124), -INT8_C(  74), -INT8_C( 105),  INT8_C(  35),  INT8_C(  49),  INT8_C( 125),  INT8_C(  68),
        -INT8_C( 118), -INT8_C(   9), -INT8_C(  72), -INT8_C(  50),  INT8_C(  83), -INT8_C(  55), -INT8_C(  76), -INT8_C(  72),
        -INT8_C(  62), -INT8_C(  82),  INT8_C( 115), -INT8_C(  92),  INT8_C(  38),  INT8_C(   0), -INT8_C( 123), -INT8_C( 101),
         INT8_C(  47),  INT8_C(  64),  INT8_C(  38),  INT8_C(  50),  INT8_C(  94),  INT8_C(  30),  INT8_C(  71), -INT8_C(  20),
        -INT8_C( 102), -INT8_C(   3), -INT8_C( 125), -INT8_C(  67),  INT8_C(  46),  INT8_C(   0),  INT8_C(   1), -INT8_C(  72),
        -INT8_C(   9), -INT8_C(  70), -INT8_C( 121),  INT8_C(  74), -INT8_C( 125),  INT8_C(  59),  INT8_C(   2),  INT8_C(  70),
        -INT8_C(  23),  INT8_C( 117), -INT8_C(  22),  INT8_C(  15),  INT8_C( 117),  INT8_C( 111), -INT8_C(  85), -INT8_C(  91),
        -INT8_C(  81), -INT8_C(  47), -INT8_C(  41),  INT8_C(  13), -INT8_C(  17),  INT8_C(  30), -INT8_C(   7), -INT8_C( 119) },
      UINT64_C( 8359042082018917403),
      {  INT8_C(   2), -INT8_C( 120), -INT8_C(  66), -INT8_C( 122), -INT8_C(  61), -INT8_C(  63), -INT8_C(  52), -INT8_C(  84),
         INT8_C(  54), -INT8_C(  74), -INT8_C(  68), -INT8_C(  84),  INT8_C(  37),  INT8_C( 103),  INT8_C(  81), -INT8_C(  43),
         INT8_C(  56),  INT8_C(  40), -INT8_C(  30),  INT8_C(  40),  INT8_C(  70), -INT8_C(  36), -INT8_C(  79),  INT8_C(  97),
         INT8_C(  88), -INT8_C(   8), -INT8_C(  86), -INT8_C(  43),  INT8_C(  65), -INT8_C(  85),  INT8_C(  73),  INT8_C(  67),
         INT8_C(  52),  INT8_C(   7), -INT8_C(  55), -INT8_C(   9), -INT8_C(  56), -INT8_C( 107), -INT8_C(  92), -INT8_C(   1),
         INT8_C(  75),  INT8_C(  96), -INT8_C(  85),  INT8_C( 113), -INT8_C(  57), -INT8_C(   4),  INT8_C(  70), -INT8_C(   1),
         INT8_C(  36),  INT8_C(  40),  INT8_C(  39),  INT8_C( 106),  INT8_C(   4), -INT8_C(  39), -INT8_C(  53),  INT8_C(  93),
        -INT8_C(  47),  INT8_C( 117),  INT8_C(  50),  INT8_C(  18),  INT8_C(  32),  INT8_C( 123),  INT8_C(  86),  INT8_C(  84) },
      {  INT8_C(   1),  INT8_C(   2), -INT8_C(  74),  INT8_C(   3),  INT8_C(   4),  INT8_C(  49),  INT8_C( 125),  INT8_C(  68),
        -INT8_C( 118), -INT8_C(   9),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3), -INT8_C(  72),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   4), -INT8_C(  92),  INT8_C(  38),  INT8_C(   0),  INT8_C(   4), -INT8_C( 101),
         INT8_C(   3),  INT8_C(  64),  INT8_C(  38),  INT8_C(   5),  INT8_C(  94),  INT8_C(  30),  INT8_C(   3), -INT8_C(  20),
        -INT8_C( 102), -INT8_C(   3),  INT8_C(   4),  INT8_C(   7),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3), -INT8_C(  72),
        -INT8_C(   9), -INT8_C(  70), -INT8_C( 121),  INT8_C(   4), -INT8_C( 125),  INT8_C(  59),  INT8_C(   3),  INT8_C(  70),
         INT8_C(   2),  INT8_C( 117), -INT8_C(  22),  INT8_C(  15),  INT8_C( 117),  INT8_C( 111), -INT8_C(  85), -INT8_C(  91),
        -INT8_C(  81), -INT8_C(  47),  INT8_C(   3),  INT8_C(  13),  INT8_C(   1),  INT8_C(   6),  INT8_C(   4), -INT8_C( 119) } },
    { { -INT8_C( 126),  INT8_C(  31),  INT8_C(  76),  INT8_C(  75), -INT8_C(  75), -INT8_C(  16),  INT8_C(  74),  INT8_C(   0),
         INT8_C(  80), -INT8_C(  11),  INT8_C( 113),  INT8_C(  23), -INT8_C(  15), -INT8_C(  73),  INT8_C(  22),  INT8_C(  21),
        -INT8_C(  32),  INT8_C(  62),      INT8_MAX, -INT8_C(  28),  INT8_C(  23),  INT8_C(  74),  INT8_C(  65), -INT8_C(  24),
        -INT8_C(  65),  INT8_C( 115), -INT8_C(   5), -INT8_C(  33), -INT8_C(  18),  INT8_C(  81),  INT8_C(  52),  INT8_C( 113),
         INT8_C( 112),      INT8_MIN, -INT8_C(  68),  INT8_C(  37),  INT8_C( 112),  INT8_C(   6),  INT8_C(  38), -INT8_C(  64),
        -INT8_C(   5), -INT8_C( 105), -INT8_C(  41), -INT8_C(  20),  INT8_C(  79), -INT8_C(  19),  INT8_C(   1),  INT8_C(  47),
         INT8_C(  43),      INT8_MIN,  INT8_C(  19),  INT8_C(  66), -INT8_C(  54),  INT8_C(  85),  INT8_C(  43), -INT8_C( 119),
        -INT8_C(  56),  INT8_C(  38),  INT8_C( 104), -INT8_C(  73),  INT8_C( 119), -INT8_C( 100),  INT8_C(  40), -INT8_C(  25) },
      UINT64_C(16522638215380591644),
      { -INT8_C(  54),  INT8_C(  35), -INT8_C(  47),  INT8_C(  25),  INT8_C(  17), -INT8_C(  46),  INT8_C(  72),  INT8_C(  60),
         INT8_C(  82),  INT8_C(  92),      INT8_MAX,  INT8_C(  28), -INT8_C(  79), -INT8_C(  86), -INT8_C(  91),  INT8_C( 121),
        -INT8_C(  48),  INT8_C(  13),  INT8_C(  48),  INT8_C(  71), -INT8_C(  86),  INT8_C(  88),  INT8_C(  46), -INT8_C(  58),
         INT8_C(  60),  INT8_C(  59),  INT8_C(  83),  INT8_C(  38),  INT8_C( 110), -INT8_C(  97),  INT8_C(  11),  INT8_C(  57),
        -INT8_C(  61), -INT8_C(  36),  INT8_C(  82), -INT8_C(  44), -INT8_C(  82), -INT8_C( 101),  INT8_C(  16),  INT8_C(   0),
        -INT8_C(   9), -INT8_C( 113),  INT8_C(  28), -INT8_C(  88),  INT8_C(  57), -INT8_C(  63),  INT8_C(  33),  INT8_C(   9),
        -INT8_C(  49),  INT8_C(  82),  INT8_C(  80),  INT8_C( 121), -INT8_C(  86),      INT8_MAX,  INT8_C(  63), -INT8_C(  25),
        -INT8_C(  70), -INT8_C( 110),  INT8_C(  13),  INT8_C(  41),  INT8_C(  50),  INT8_C(  25),  INT8_C(  98), -INT8_C(  11) },
      { -INT8_C( 126),  INT8_C(  31),  INT8_C(   4),  INT8_C(   3),  INT8_C(   2), -INT8_C(  16),  INT8_C(  74),  INT8_C(   0),
         INT8_C(  80), -INT8_C(  11),  INT8_C(   7),  INT8_C(  23), -INT8_C(  15),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),
         INT8_C(   3),  INT8_C(  62),  INT8_C(   2),  INT8_C(   4),  INT8_C(  23),  INT8_C(  74),  INT8_C(  65), -INT8_C(  24),
        -INT8_C(  65),  INT8_C( 115),  INT8_C(   4),  INT8_C(   3), -INT8_C(  18),  INT8_C(  81),  INT8_C(  52),  INT8_C(   4),
         INT8_C( 112),  INT8_C(   5), -INT8_C(  68),  INT8_C(   4),  INT8_C( 112),  INT8_C(   5),  INT8_C(   1),  INT8_C(   0),
         INT8_C(   7),  INT8_C(   5), -INT8_C(  41), -INT8_C(  20),  INT8_C(   4),  INT8_C(   3),  INT8_C(   1),  INT8_C(  47),
         INT8_C(  43),      INT8_MIN,  INT8_C(   2),  INT8_C(   5), -INT8_C(  54),  INT8_C(  85),  INT8_C(   6), -INT8_C( 119),
         INT8_C(   5),  INT8_C(  38),  INT8_C(   3), -INT8_C(  73),  INT8_C( 119),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6) } },
    { { -INT8_C(  11), -INT8_C(  76), -INT8_C(  55), -INT8_C(  92),  INT8_C(  79), -INT8_C(  39), -INT8_C(  92),  INT8_C(  70),
         INT8_C( 105), -INT8_C(  63), -INT8_C(  18), -INT8_C(  94), -INT8_C( 126),  INT8_C(  16), -INT8_C(  84),  INT8_C(  81),
         INT8_C(  98), -INT8_C(   4), -INT8_C(  54),  INT8_C(  12),  INT8_C( 123),  INT8_C(  10), -INT8_C(  13),  INT8_C(  54),
        -INT8_C( 100),  INT8_C(   1),  INT8_C(  95), -INT8_C(  50),  INT8_C(  26), -INT8_C(  63), -INT8_C(  61),  INT8_C(  15),
         INT8_C( 117), -INT8_C( 116), -INT8_C(  77), -INT8_C(  59),  INT8_C( 102),  INT8_C(  88),  INT8_C(  11), -INT8_C(  49),
         INT8_C(  25), -INT8_C(   6),  INT8_C( 113), -INT8_C( 101),  INT8_C(  10),  INT8_C(  29), -INT8_C(  19),  INT8_C( 108),
         INT8_C(  26), -INT8_C(  73),  INT8_C( 120), -INT8_C( 107), -INT8_C(  63),  INT8_C( 108), -INT8_C(  53),  INT8_C(  94),
         INT8_C( 109),  INT8_C(  42),  INT8_C(  44), -INT8_C( 121), -INT8_C(  21), -INT8_C(  16), -INT8_C( 106),  INT8_C(  97) },
      UINT64_C(13524645731618933372),
      {  INT8_C(  43),  INT8_C(  35),  INT8_C(  86),  INT8_C(  53),  INT8_C(  64),  INT8_C(  67), -INT8_C(  95),  INT8_C(  90),
        -INT8_C(   5),  INT8_C(  26), -INT8_C(  16), -INT8_C(  68), -INT8_C( 122), -INT8_C(  69),  INT8_C(  26), -INT8_C(  13),
        -INT8_C(  26),  INT8_C(  71),  INT8_C( 122), -INT8_C(  47),  INT8_C(  55),  INT8_C(  16),  INT8_C(  50), -INT8_C(  77),
         INT8_C(  90),  INT8_C(  88), -INT8_C( 106), -INT8_C(   4), -INT8_C( 118),  INT8_C(  71), -INT8_C(  73), -INT8_C(  75),
         INT8_C( 106),  INT8_C(  14), -INT8_C(  21), -INT8_C(  85),  INT8_C(  81), -INT8_C( 116),  INT8_C(   5),  INT8_C(  76),
        -INT8_C(  90), -INT8_C(  11),  INT8_C(   9),  INT8_C(  44), -INT8_C(  79),  INT8_C(  35),  INT8_C(  31), -INT8_C( 105),
         INT8_C( 106), -INT8_C( 103),  INT8_C( 104), -INT8_C(  95), -INT8_C(  86), -INT8_C( 101),  INT8_C(  85),  INT8_C(   4),
        -INT8_C(  13), -INT8_C(  21),  INT8_C(   1),  INT8_C( 125),  INT8_C(  50), -INT8_C(  72),  INT8_C(  51), -INT8_C(  99) },
      { -INT8_C(  11), -INT8_C(  76),  INT8_C(   4),  INT8_C(   4),  INT8_C(   1),  INT8_C(   3),  INT8_C(   3),  INT8_C(  70),
         INT8_C( 105),  INT8_C(   3), -INT8_C(  18),  INT8_C(   5), -INT8_C( 126),  INT8_C(  16),  INT8_C(   3),  INT8_C(  81),
         INT8_C(  98),  INT8_C(   4),  INT8_C(   5),  INT8_C(  12),  INT8_C( 123),  INT8_C(   1), -INT8_C(  13),  INT8_C(  54),
        -INT8_C( 100),  INT8_C(   3),  INT8_C(  95), -INT8_C(  50),  INT8_C(  26),  INT8_C(   4),  INT8_C(   6),  INT8_C(   5),
         INT8_C( 117),  INT8_C(   3), -INT8_C(  77), -INT8_C(  59),  INT8_C( 102),  INT8_C(   3),  INT8_C(  11),  INT8_C(   3),
         INT8_C(   4), -INT8_C(   6),  INT8_C( 113), -INT8_C( 101),  INT8_C(   4),  INT8_C(   3), -INT8_C(  19),  INT8_C( 108),
         INT8_C(   4), -INT8_C(  73),  INT8_C( 120), -INT8_C( 107),  INT8_C(   4),  INT8_C(   5), -INT8_C(  53),  INT8_C(   1),
         INT8_C(   6),  INT8_C(   6),  INT8_C(  44),  INT8_C(   6),  INT8_C(   3),  INT8_C(   4), -INT8_C( 106),  INT8_C(   5) } },
    { { -INT8_C(  58),  INT8_C(  30),  INT8_C(  72),  INT8_C(  24), -INT8_C(  86),  INT8_C(  77),  INT8_C( 100),  INT8_C(  81),
         INT8_C(  67),  INT8_C( 109),  INT8_C( 125), -INT8_C(  12), -INT8_C( 111), -INT8_C(  99), -INT8_C( 117), -INT8_C(   5),
         INT8_C(  54), -INT8_C(  13), -INT8_C(  99), -INT8_C(  32), -INT8_C( 114), -INT8_C(  14), -INT8_C(  27), -INT8_C( 126),
        -INT8_C(  35), -INT8_C(  26), -INT8_C(   1),  INT8_C(  15), -INT8_C(  98),  INT8_C(  50), -INT8_C(  84),  INT8_C( 101),
         INT8_C(  80), -INT8_C(  12),  INT8_C( 125), -INT8_C(   5),  INT8_C(  66), -INT8_C(  31),  INT8_C(  76), -INT8_C( 123),
         INT8_C(  79), -INT8_C(  55),  INT8_C( 121), -INT8_C(  32),  INT8_C( 102),  INT8_C(   4), -INT8_C(  37), -INT8_C(  99),
        -INT8_C(   9),  INT8_C( 120),  INT8_C( 125), -INT8_C( 122),  INT8_C( 106),  INT8_C(  98),  INT8_C(   8),  INT8_C(  71),
         INT8_C(  72),  INT8_C(   7),  INT8_C(  87), -INT8_C(  25),  INT8_C(  58),  INT8_C(   3),  INT8_C(  76), -INT8_C( 118) },
      UINT64_C(17996333165052283384),
      { -INT8_C( 101),  INT8_C(  56), -INT8_C(  39),  INT8_C(   1),  INT8_C(  60), -INT8_C(  75), -INT8_C(  98),  INT8_C(  51),
         INT8_C(  45),  INT8_C(  28), -INT8_C(  71), -INT8_C( 104),  INT8_C( 126), -INT8_C(  63), -INT8_C(  33), -INT8_C(  57),
        -INT8_C(  55),  INT8_C(  54), -INT8_C(  82),  INT8_C(   3),  INT8_C(  58), -INT8_C(   6), -INT8_C( 115),  INT8_C(  50),
        -INT8_C(  61),  INT8_C(  19),  INT8_C( 108),  INT8_C( 109), -INT8_C(  28),  INT8_C(  43),  INT8_C( 103),      INT8_MAX,
         INT8_C(  99),  INT8_C(  64), -INT8_C( 127), -INT8_C(  97), -INT8_C(  11),  INT8_C(  31), -INT8_C(  46),  INT8_C(  35),
         INT8_C(  59), -INT8_C( 116), -INT8_C(  69), -INT8_C(  70),  INT8_C(  77), -INT8_C( 102), -INT8_C( 127),  INT8_C(  22),
        -INT8_C(  47),  INT8_C(  47),  INT8_C(  25),  INT8_C(  11),  INT8_C(  41), -INT8_C(  89),  INT8_C(  61), -INT8_C(  20),
        -INT8_C(  70), -INT8_C(  87),  INT8_C(  89), -INT8_C(  98), -INT8_C(  44), -INT8_C(  64),  INT8_C(  30),  INT8_C(  55) },
      { -INT8_C(  58),  INT8_C(  30),  INT8_C(  72),  INT8_C(   1),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   4),  INT8_C( 109),  INT8_C( 125),  INT8_C(   3), -INT8_C( 111), -INT8_C(  99),  INT8_C(   7),  INT8_C(   5),
         INT8_C(   4), -INT8_C(  13),  INT8_C(   5), -INT8_C(  32), -INT8_C( 114), -INT8_C(  14), -INT8_C(  27),  INT8_C(   3),
        -INT8_C(  35),  INT8_C(   3), -INT8_C(   1),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4), -INT8_C(  84),  INT8_C( 101),
         INT8_C(  80),  INT8_C(   1),  INT8_C( 125),  INT8_C(   6),  INT8_C(  66),  INT8_C(   5),  INT8_C(  76),  INT8_C(   3),
         INT8_C(   5), -INT8_C(  55),  INT8_C( 121), -INT8_C(  32),  INT8_C(   4),  INT8_C(   4),  INT8_C(   2),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   8),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   7),  INT8_C(  87),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   5) } },
    { {  INT8_C(   1), -INT8_C(  97), -INT8_C(  42), -INT8_C(  10), -INT8_C(  66), -INT8_C(  88),  INT8_C(  25), -INT8_C(   6),
         INT8_C(  52), -INT8_C(  44), -INT8_C(  76), -INT8_C( 126),  INT8_C( 111),  INT8_C(  53), -INT8_C( 104),  INT8_C(  64),
         INT8_C( 100), -INT8_C(  78),  INT8_C(  75), -INT8_C( 115),  INT8_C(  89), -INT8_C( 120),  INT8_C( 121),  INT8_C(  19),
         INT8_C(  49), -INT8_C(  46), -INT8_C(  79),  INT8_C(   5), -INT8_C( 109), -INT8_C(  49),  INT8_C(  60), -INT8_C( 108),
         INT8_C( 110),  INT8_C(  18), -INT8_C( 118),  INT8_C(  45), -INT8_C(  70), -INT8_C(  92),  INT8_C(  39), -INT8_C(  17),
         INT8_C( 120), -INT8_C(  37),  INT8_C( 113), -INT8_C(  25),  INT8_C(  16),  INT8_C(   9),  INT8_C(  39),  INT8_C( 116),
        -INT8_C(  69),  INT8_C( 114),  INT8_C(   1),  INT8_C(  20), -INT8_C(   6),  INT8_C( 122),  INT8_C(  39),  INT8_C(  43),
         INT8_C(  76), -INT8_C(  39),  INT8_C(  48), -INT8_C(  33), -INT8_C(  88),  INT8_C( 108),  INT8_C( 115),  INT8_C(  23) },
      UINT64_C( 1884874788544249470),
      {  INT8_C(  70), -INT8_C( 103),  INT8_C(   2),  INT8_C(  86), -INT8_C(  94),  INT8_C(  41), -INT8_C(  54),  INT8_C(  94),
        -INT8_C( 100), -INT8_C(  53),  INT8_C( 114), -INT8_C( 106),  INT8_C(  69), -INT8_C( 102), -INT8_C(  62), -INT8_C( 111),
         INT8_C( 115), -INT8_C(  14),  INT8_C( 113),  INT8_C(  27),  INT8_C(  95), -INT8_C(  28),  INT8_C(  50), -INT8_C(  35),
        -INT8_C(  30),  INT8_C( 118),  INT8_C(  22), -INT8_C( 124), -INT8_C(  31),  INT8_C(  62), -INT8_C(  97),  INT8_C(  39),
        -INT8_C(  41), -INT8_C(  95),  INT8_C( 125),  INT8_C( 122), -INT8_C(  54),  INT8_C(  71), -INT8_C(  40),  INT8_C( 102),
         INT8_C(  18),  INT8_C(  74), -INT8_C(   3),  INT8_C(  87), -INT8_C(  28), -INT8_C(  65), -INT8_C(  23),  INT8_C(  87),
        -INT8_C(  79),  INT8_C(  90),  INT8_C( 115),  INT8_C(  16),  INT8_C(  62), -INT8_C(  91), -INT8_C(  18),  INT8_C(  33),
         INT8_C(  28),  INT8_C(   4), -INT8_C(  91), -INT8_C(   3),  INT8_C(  67),  INT8_C(  68),  INT8_C(  37),  INT8_C(  26) },
      {  INT8_C(   1),  INT8_C(   4),  INT8_C(   1),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4), -INT8_C(   6),
         INT8_C(  52),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),
         INT8_C( 100), -INT8_C(  78),  INT8_C(   4), -INT8_C( 115),  INT8_C(  89), -INT8_C( 120),  INT8_C(   3),  INT8_C(  19),
         INT8_C(   4), -INT8_C(  46), -INT8_C(  79),  INT8_C(   2),  INT8_C(   4),  INT8_C(   5),  INT8_C(  60), -INT8_C( 108),
         INT8_C( 110),  INT8_C(   3), -INT8_C( 118),  INT8_C(  45), -INT8_C(  70),  INT8_C(   4),  INT8_C(  39),  INT8_C(   4),
         INT8_C(   2),  INT8_C(   3),  INT8_C( 113),  INT8_C(   5),  INT8_C(  16),  INT8_C(   7),  INT8_C(   5),  INT8_C( 116),
        -INT8_C(  69),  INT8_C( 114),  INT8_C(   1),  INT8_C(   1), -INT8_C(   6),  INT8_C(   4),  INT8_C(  39),  INT8_C(  43),
         INT8_C(  76),  INT8_C(   1),  INT8_C(  48),  INT8_C(   7),  INT8_C(   3),  INT8_C( 108),  INT8_C( 115),  INT8_C(  23) } },
    { { -INT8_C(  27), -INT8_C(  94), -INT8_C( 108), -INT8_C(  80), -INT8_C(  22),  INT8_C( 108),  INT8_C(  22), -INT8_C(   4),
        -INT8_C(  73),  INT8_C(  19),  INT8_C(  84), -INT8_C( 101), -INT8_C(  46),  INT8_C(  61), -INT8_C(  13), -INT8_C( 124),
        -INT8_C( 105),  INT8_C( 102), -INT8_C( 108), -INT8_C(  43),  INT8_C(  11), -INT8_C( 126), -INT8_C(  10),  INT8_C(  39),
        -INT8_C( 121), -INT8_C( 100),  INT8_C(  37), -INT8_C(  54), -INT8_C(  32),  INT8_C(  74), -INT8_C(  28), -INT8_C(  58),
        -INT8_C(  20),  INT8_C( 121),  INT8_C( 118), -INT8_C(  42), -INT8_C(  27), -INT8_C( 116), -INT8_C(  45), -INT8_C( 100),
        -INT8_C(  96),  INT8_C(  39),  INT8_C(  56),  INT8_C( 114),  INT8_C( 100),  INT8_C(  43), -INT8_C(  10), -INT8_C(   5),
        -INT8_C( 111), -INT8_C( 117), -INT8_C(  48), -INT8_C( 100),  INT8_C(  13), -INT8_C(  57), -INT8_C(  60), -INT8_C( 108),
         INT8_C(  99), -INT8_C(  23),  INT8_C(  94),  INT8_C(  67),  INT8_C(  51),  INT8_C(  67),  INT8_C(   9),  INT8_C(  31) },
      UINT64_C(12411578679173742524),
      { -INT8_C(  16),  INT8_C( 118),  INT8_C(  30),  INT8_C(  84), -INT8_C(  95),  INT8_C(  21),  INT8_C(  79),  INT8_C(  50),
        -INT8_C(  96),  INT8_C(  31), -INT8_C(  50), -INT8_C(  83), -INT8_C(  26), -INT8_C( 110),  INT8_C(  66),  INT8_C(  73),
         INT8_C( 123), -INT8_C(  96), -INT8_C( 115), -INT8_C(  82), -INT8_C(  29), -INT8_C( 106), -INT8_C(  50), -INT8_C(  97),
         INT8_C(  22), -INT8_C(  60),  INT8_C(  65),  INT8_C(  34), -INT8_C( 115),      INT8_MAX, -INT8_C(  50),  INT8_C( 125),
        -INT8_C(  11), -INT8_C(  20), -INT8_C(  47), -INT8_C( 106),  INT8_C(   1),  INT8_C(  32), -INT8_C(  56), -INT8_C(  95),
         INT8_C(  63), -INT8_C( 106),  INT8_C(  79),  INT8_C(  38),  INT8_C(  41), -INT8_C( 111),  INT8_C( 111), -INT8_C(  92),
         INT8_C(  49), -INT8_C(   4),  INT8_C(  83),  INT8_C(  21), -INT8_C( 109),  INT8_C(  33), -INT8_C(  76), -INT8_C(  87),
        -INT8_C(  27), -INT8_C(  11), -INT8_C(  53),  INT8_C( 114),  INT8_C( 116), -INT8_C( 103), -INT8_C(  17),  INT8_C( 105) },
      { -INT8_C(  27), -INT8_C(  94),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(  22),  INT8_C(   3),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   2), -INT8_C( 124),
        -INT8_C( 105),  INT8_C(   2),  INT8_C(   4), -INT8_C(  43),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),
         INT8_C(   3), -INT8_C( 100),  INT8_C(  37), -INT8_C(  54), -INT8_C(  32),  INT8_C(   7), -INT8_C(  28),  INT8_C(   6),
        -INT8_C(  20),  INT8_C( 121),  INT8_C(   4),  INT8_C(   4), -INT8_C(  27), -INT8_C( 116), -INT8_C(  45), -INT8_C( 100),
         INT8_C(   6),  INT8_C(  39),  INT8_C(  56),  INT8_C(   3),  INT8_C( 100),  INT8_C(  43),  INT8_C(   6),  INT8_C(   3),
        -INT8_C( 111),  INT8_C(   6),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2), -INT8_C(  60), -INT8_C( 108),
         INT8_C(  99), -INT8_C(  23),  INT8_C(   5),  INT8_C(   4),  INT8_C(  51),  INT8_C(   4),  INT8_C(   9),  INT8_C(   4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_popcnt_epi8(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i8x64();
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask_popcnt_epi8(src, k, a);

    simde_test_x86_write_i8x64(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C( 2245264181412479109),
      {  INT8_C(  94),  INT8_C( 119),  INT8_C(  69), -INT8_C( 121),  INT8_C(   8), -INT8_C(  75),  INT8_C(  43),  INT8_C(  58),
        -INT8_C(  79),  INT8_C( 126),  INT8_C(  79),  INT8_C(  68), -INT8_C(  97),  INT8_C(   3), -INT8_C(  19), -INT8_C( 124),
        -INT8_C(   7), -INT8_C(  72), -INT8_C(  10),  INT8_C( 109),  INT8_C(  81), -INT8_C(  27), -INT8_C(  41), -INT8_C(  41),
        -INT8_C(  91), -INT8_C(  42),  INT8_C(  94), -INT8_C( 123), -INT8_C(  98), -INT8_C( 122), -INT8_C(  91), -INT8_C(   4),
        -INT8_C(   2), -INT8_C(  22), -INT8_C( 125),  INT8_C(   6), -INT8_C(  97), -INT8_C(  82),  INT8_C(  64),  INT8_C(  81),
         INT8_C(  45), -INT8_C( 113), -INT8_C( 107), -INT8_C(  52), -INT8_C( 109), -INT8_C( 125),  INT8_C(  81), -INT8_C( 116),
         INT8_C(  59),  INT8_C(  71), -INT8_C(   7), -INT8_C( 115),  INT8_C(  45), -INT8_C(  48),  INT8_C( 100), -INT8_C(  46),
        -INT8_C(  89), -INT8_C(  62),  INT8_C(  88),  INT8_C(  69),  INT8_C(  72), -INT8_C(   3),  INT8_C(  65),  INT8_C(  70) },
      {  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   2),
         INT8_C(   6),  INT8_C(   4),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   1),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C(11518111570035852519),
      {  INT8_C(  29),  INT8_C( 109),  INT8_C( 108), -INT8_C(  80), -INT8_C(  16), -INT8_C(  67),  INT8_C(  60),  INT8_C(  44),
         INT8_C(   4),  INT8_C(  53), -INT8_C(  71),  INT8_C(  49),  INT8_C(   6),  INT8_C(  29),  INT8_C(   4), -INT8_C(  83),
        -INT8_C(  33),  INT8_C(  92), -INT8_C(  14),  INT8_C(  39),  INT8_C(  89),  INT8_C(  51),  INT8_C( 110),  INT8_C(  64),
        -INT8_C(   9), -INT8_C(  69), -INT8_C(  57),  INT8_C( 105),  INT8_C(  72), -INT8_C(  97),  INT8_C(   9),  INT8_C( 101),
         INT8_C(  13),  INT8_C( 117),  INT8_C(  21), -INT8_C(   3),  INT8_C(  50),  INT8_C(  81),  INT8_C(  41),  INT8_C(  54),
        -INT8_C( 121), -INT8_C(  30),  INT8_C( 104), -INT8_C( 115), -INT8_C(   1),  INT8_C( 108),  INT8_C(  58), -INT8_C(  34),
        -INT8_C(  56),  INT8_C(  44),  INT8_C(   6),  INT8_C(  33),  INT8_C(  95),  INT8_C( 116),  INT8_C(  97),  INT8_C(  86),
         INT8_C(  47),  INT8_C(  41), -INT8_C(  65),  INT8_C( 119), -INT8_C(  56), -INT8_C(  56), -INT8_C(  35), -INT8_C(  43) },
      {  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   5),
         INT8_C(   7),  INT8_C(   0),  INT8_C(   5),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),
         INT8_C(   7),  INT8_C(   6),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   6),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   5),  INT8_C(   3),  INT8_C(   7),  INT8_C(   6),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5) } },
    { UINT64_C(14674693806697476669),
      { -INT8_C(  33),  INT8_C(  14),  INT8_C(  88), -INT8_C(  34),  INT8_C( 122), -INT8_C( 110), -INT8_C(  67),  INT8_C(  66),
        -INT8_C(  66), -INT8_C(  61),  INT8_C(  99),  INT8_C(  29),  INT8_C(  55), -INT8_C(  60),  INT8_C( 115),  INT8_C( 102),
        -INT8_C(  19),  INT8_C(  50), -INT8_C(  35), -INT8_C(  74), -INT8_C(   5), -INT8_C(  70), -INT8_C( 117),  INT8_C(  56),
        -INT8_C(  83),  INT8_C(  94), -INT8_C(  88), -INT8_C(  15),  INT8_C(  91),  INT8_C(  78), -INT8_C(  68),  INT8_C(  58),
         INT8_C(  92),  INT8_C(  20),  INT8_C(  24), -INT8_C(  42), -INT8_C(  90), -INT8_C(  43),  INT8_C(  24),  INT8_C( 100),
        -INT8_C( 104),  INT8_C( 123), -INT8_C( 127), -INT8_C(  49),  INT8_C(  63), -INT8_C(  12),  INT8_C(  53),  INT8_C(  45),
         INT8_C(  38),  INT8_C(  19), -INT8_C(  29),  INT8_C(  33), -INT8_C(  51),  INT8_C( 110),  INT8_C(  90),  INT8_C( 122),
        -INT8_C(  51),  INT8_C(   2),  INT8_C( 107),  INT8_C(  40),  INT8_C(  80),  INT8_C(  39),  INT8_C(  98), -INT8_C(  84) },
      {  INT8_C(   7),  INT8_C(   0),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   0),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   6),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   1),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4) } },
    { UINT64_C(16736953262363802171),
      {  INT8_C(  21), -INT8_C(  58), -INT8_C(  72),  INT8_C(  84), -INT8_C(  70), -INT8_C(  19), -INT8_C( 127), -INT8_C(  31),
         INT8_C(   0),  INT8_C( 100),  INT8_C(   2), -INT8_C(  50), -INT8_C(  45),  INT8_C(  92),  INT8_C(  72), -INT8_C(  96),
         INT8_C(  94), -INT8_C(  76), -INT8_C(  56), -INT8_C(  82), -INT8_C(  37),  INT8_C(  42),  INT8_C(  90),  INT8_C(  23),
        -INT8_C(  92), -INT8_C(  36), -INT8_C(   8), -INT8_C(  12),  INT8_C( 118),  INT8_C(  62), -INT8_C(  35), -INT8_C( 117),
         INT8_C(   4), -INT8_C( 107), -INT8_C(  32), -INT8_C(  65), -INT8_C( 126),  INT8_C(  97), -INT8_C(  96), -INT8_C( 125),
        -INT8_C(  58), -INT8_C(  94),  INT8_C(  81), -INT8_C( 103), -INT8_C(   1), -INT8_C( 103),  INT8_C(  57),  INT8_C(  93),
         INT8_C(  77),  INT8_C(   1),  INT8_C(  12),  INT8_C(  41),  INT8_C(  43),  INT8_C( 102),  INT8_C(  64), -INT8_C(  49),
         INT8_C(  67),  INT8_C(  56), -INT8_C(  60), -INT8_C(  71),  INT8_C( 118), -INT8_C(  95),  INT8_C(  69),  INT8_C( 123) },
      {  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   4),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   4),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6) } },
    { UINT64_C( 5493224442659743030),
      {  INT8_C( 124), -INT8_C( 116), -INT8_C(  27),  INT8_C( 123),  INT8_C(  38),  INT8_C(  30), -INT8_C(  39),  INT8_C( 115),
         INT8_C(  31), -INT8_C(  27), -INT8_C( 100),  INT8_C(  74),  INT8_C(  75), -INT8_C(  36),  INT8_C(  26), -INT8_C( 114),
         INT8_C(  21), -INT8_C(  34),  INT8_C(  72), -INT8_C( 117),      INT8_MAX, -INT8_C( 115),  INT8_C(   6), -INT8_C(  75),
        -INT8_C(  78),  INT8_C(  64),  INT8_C( 109),  INT8_C(  56),  INT8_C(  26), -INT8_C(  87), -INT8_C( 123), -INT8_C( 105),
         INT8_C(  53),  INT8_C( 106),  INT8_C(  18),  INT8_C(  91), -INT8_C( 119), -INT8_C(  21), -INT8_C(  49), -INT8_C(  88),
        -INT8_C(  48),  INT8_C( 107), -INT8_C(  13),  INT8_C(  28),  INT8_C(  72),  INT8_C(  13), -INT8_C(  86),  INT8_C(  93),
        -INT8_C(  21), -INT8_C(  14), -INT8_C(  24),  INT8_C( 106),      INT8_MAX, -INT8_C(  17),  INT8_C(  31),  INT8_C(  49),
         INT8_C(  47), -INT8_C( 116),  INT8_C( 106),  INT8_C(  74),  INT8_C(  53), -INT8_C(  17), -INT8_C(  31),  INT8_C( 107) },
      {  INT8_C(   0),  INT8_C(   3),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   5),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   4),  INT8_C(   7),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   2),  INT8_C(   0),  INT8_C(   4),  INT8_C(   5),
         INT8_C(   6),  INT8_C(   5),  INT8_C(   0),  INT8_C(   4),  INT8_C(   7),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0) } },
    { UINT64_C(12649368767215104857),
      {  INT8_C(   1),  INT8_C( 126), -INT8_C(  53),  INT8_C(  73), -INT8_C( 117),  INT8_C( 118), -INT8_C(  90),  INT8_C( 118),
         INT8_C( 104), -INT8_C( 114), -INT8_C(  32), -INT8_C(  24),  INT8_C( 125), -INT8_C(   1),  INT8_C(  25), -INT8_C(  83),
        -INT8_C( 117), -INT8_C( 125), -INT8_C(   9), -INT8_C(  63),  INT8_C( 114), -INT8_C(  40),  INT8_C(  44), -INT8_C(  52),
        -INT8_C(  53), -INT8_C(  14), -INT8_C(  82), -INT8_C(  86), -INT8_C( 120),  INT8_C(  57),  INT8_C(  90), -INT8_C( 119),
        -INT8_C(  73),  INT8_C(  37), -INT8_C(  46),  INT8_C(  66), -INT8_C( 101),  INT8_C( 120), -INT8_C(  72),  INT8_C(   4),
         INT8_C(   6), -INT8_C( 104), -INT8_C(  20), -INT8_C( 124), -INT8_C( 105),  INT8_C(   5),  INT8_C(  49),  INT8_C(  35),
        -INT8_C( 119),  INT8_C(  40), -INT8_C(  28), -INT8_C(   5),  INT8_C(   0),  INT8_C(  16), -INT8_C(  57), -INT8_C(  53),
         INT8_C(   2),  INT8_C( 118),  INT8_C( 118), -INT8_C( 118), -INT8_C(  81), -INT8_C(  48),  INT8_C(  19),  INT8_C( 103) },
      {  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   8),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   0),  INT8_C(   3),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),  INT8_C(   0),  INT8_C(   4),  INT8_C(   1),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   1),  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   5) } },
    { UINT64_C( 7247807329337992693),
      { -INT8_C(   6), -INT8_C( 127), -INT8_C(  24), -INT8_C( 110), -INT8_C( 122),  INT8_C(  25), -INT8_C(  75),  INT8_C(  15),
         INT8_C(  65), -INT8_C( 103),  INT8_C(  11),  INT8_C(  65), -INT8_C(  87), -INT8_C(  46),  INT8_C(  12), -INT8_C(  85),
         INT8_C(  72), -INT8_C( 126),  INT8_C(  54), -INT8_C(   8),  INT8_C(  82),  INT8_C(  73),  INT8_C(  95),  INT8_C(  72),
         INT8_C(  47),  INT8_C(   8), -INT8_C(  39), -INT8_C( 116),  INT8_C( 106),  INT8_C( 110), -INT8_C(  16),  INT8_C( 101),
        -INT8_C(  17), -INT8_C(  40), -INT8_C(   9),  INT8_C( 117), -INT8_C(  15), -INT8_C(  84), -INT8_C( 123),  INT8_C(  50),
         INT8_C(  69), -INT8_C( 112),  INT8_C( 115), -INT8_C(  18),  INT8_C(  98),      INT8_MIN, -INT8_C( 103), -INT8_C(  85),
         INT8_C(   2), -INT8_C(  49), -INT8_C(  93),  INT8_C(  85),  INT8_C(  25),  INT8_C(   2), -INT8_C(  99),  INT8_C(  72),
         INT8_C(  10),  INT8_C( 118), -INT8_C(  44),  INT8_C( 117), -INT8_C(  28), -INT8_C(  59), -INT8_C(  38), -INT8_C(  45) },
      {  INT8_C(   6),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   2),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   2),
         INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   7),  INT8_C(   0),  INT8_C(   7),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   1),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0) } },
    { UINT64_C(14033723853021696413),
      {  INT8_C(  93),  INT8_C(  53), -INT8_C(  80), -INT8_C(  64), -INT8_C(  75),  INT8_C(  73),  INT8_C( 107), -INT8_C(  73),
         INT8_C(  25),  INT8_C(  14),  INT8_C(  12),  INT8_C(  50),  INT8_C(  16), -INT8_C(  87),  INT8_C( 122),  INT8_C(  26),
         INT8_C(  31),  INT8_C(  78), -INT8_C( 113),  INT8_C(   3),  INT8_C(  19),  INT8_C( 105), -INT8_C(  42), -INT8_C(  79),
         INT8_C(  58),  INT8_C(  31),  INT8_C(  64), -INT8_C(  73), -INT8_C(  20),  INT8_C(   1),  INT8_C( 121),  INT8_C(  74),
         INT8_C(  54),  INT8_C(  41),  INT8_C(  10), -INT8_C(  21),  INT8_C( 115),  INT8_C( 117), -INT8_C(  93), -INT8_C( 116),
        -INT8_C( 125), -INT8_C(  81), -INT8_C(  66), -INT8_C( 109),  INT8_C(  89),  INT8_C(  56), -INT8_C(  83),  INT8_C( 120),
        -INT8_C( 122),  INT8_C(  61),  INT8_C( 124), -INT8_C( 102), -INT8_C(  90),  INT8_C(  82),  INT8_C(  75), -INT8_C(  31),
         INT8_C( 113), -INT8_C( 117), -INT8_C( 104),  INT8_C(  94), -INT8_C( 116),  INT8_C(  18), -INT8_C(  88), -INT8_C(  61) },
      {  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   2),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   5),  INT8_C(   3),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   5),  INT8_C(   1),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
         INT8_C(   4),  INT8_C(   0),  INT8_C(   2),  INT8_C(   6),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   4),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_popcnt_epi8(test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_maskz_popcnt_epi8(k, a);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 14280),  INT16_C(  5469), -INT16_C( 22640),  INT16_C(  3620), -INT16_C(  9785), -INT16_C( 15431), -INT16_C( 20383), -INT16_C( 25427),
        -INT16_C( 25508), -INT16_C( 14367), -INT16_C(  5141),  INT16_C( 29735),  INT16_C( 29096), -INT16_C(  5600),  INT16_C( 30168),  INT16_C(  4096),
         INT16_C( 23870), -INT16_C( 12763),  INT16_C( 18693), -INT16_C( 13092), -INT16_C( 27102), -INT16_C( 31857),  INT16_C( 15686), -INT16_C( 24033),
         INT16_C(   217), -INT16_C( 14998), -INT16_C( 28181), -INT16_C( 27847),  INT16_C( 22786), -INT16_C(  9603),  INT16_C( 32206),  INT16_C(  3307) },
      {  INT16_C(     6),  INT16_C(     8),  INT16_C(     7),  INT16_C(     5),  INT16_C(    10),  INT16_C(     9),  INT16_C(     6),  INT16_C(     9),
         INT16_C(     8),  INT16_C(     9),  INT16_C(    12),  INT16_C(     8),  INT16_C(     7),  INT16_C(     6),  INT16_C(     9),  INT16_C(     1),
         INT16_C(    10),  INT16_C(     8),  INT16_C(     5),  INT16_C(     9),  INT16_C(     6),  INT16_C(     8),  INT16_C(     8),  INT16_C(     8),
         INT16_C(     5),  INT16_C(     8),  INT16_C(     9),  INT16_C(     8),  INT16_C(     5),  INT16_C(    11),  INT16_C(    11),  INT16_C(     8) } },
    { {  INT16_C(  4315), -INT16_C(  7974), -INT16_C( 18598),  INT16_C( 31916),  INT16_C( 15181), -INT16_C( 27904),  INT16_C(  8056),  INT16_C( 21045),
        -INT16_C( 24800),  INT16_C(  2839),  INT16_C( 20529),  INT16_C( 13215),  INT16_C(  7337),  INT16_C( 30478), -INT16_C(  1638),  INT16_C( 30084),
         INT16_C( 24073),  INT16_C( 25429),  INT16_C(   277),  INT16_C( 25312), -INT16_C(  8132), -INT16_C( 18955),  INT16_C( 11263),  INT16_C(  7943),
         INT16_C(  7882), -INT16_C(  1237), -INT16_C( 13714),  INT16_C(  5935),  INT16_C( 15846), -INT16_C( 32626),  INT16_C(  4662),  INT16_C( 16373) },
      {  INT16_C(     7),  INT16_C(     8),  INT16_C(    10),  INT16_C(     9),  INT16_C(     9),  INT16_C(     4),  INT16_C(     9),  INT16_C(     7),
         INT16_C(     7),  INT16_C(     7),  INT16_C(     5),  INT16_C(    10),  INT16_C(     7),  INT16_C(     9),  INT16_C(    10),  INT16_C(     7),
         INT16_C(     7),  INT16_C(     8),  INT16_C(     4),  INT16_C(     6),  INT16_C(     7),  INT16_C(    11),  INT16_C(    12),  INT16_C(     8),
         INT16_C(     8),  INT16_C(    11),  INT16_C(     9),  INT16_C(     9),  INT16_C(    10),  INT16_C(     5),  INT16_C(     6),  INT16_C(    12) } },
    { {  INT16_C( 19057), -INT16_C( 31069), -INT16_C( 31925), -INT16_C( 30487), -INT16_C(  8605),  INT16_C( 25149),  INT16_C( 17417), -INT16_C( 11134),
        -INT16_C( 21150), -INT16_C( 12081), -INT16_C(   393),  INT16_C( 24039),  INT16_C( 30011),  INT16_C( 29150), -INT16_C( 11384), -INT16_C(  1615),
         INT16_C( 21534),  INT16_C( 27007),  INT16_C( 26839),  INT16_C( 15089),  INT16_C( 11847),  INT16_C( 20636),  INT16_C(  7794), -INT16_C( 11228),
        -INT16_C(  2869),  INT16_C( 17060), -INT16_C( 29710),  INT16_C( 11936),  INT16_C( 32257), -INT16_C( 30305),  INT16_C( 20561),  INT16_C( 28546) },
      {  INT16_C(     7),  INT16_C(     7),  INT16_C(     7),  INT16_C(     7),  INT16_C(    10),  INT16_C(     8),  INT16_C(     4),  INT16_C(     6),
         INT16_C(     8),  INT16_C(     9),  INT16_C(    13),  INT16_C(    11),  INT16_C(    10),  INT16_C(    10),  INT16_C(     7),  INT16_C(    10),
         INT16_C(     7),  INT16_C(    11),  INT16_C(     9),  INT16_C(     9),  INT16_C(     8),  INT16_C(     6),  INT16_C(     8),  INT16_C(     6),
         INT16_C(    10),  INT16_C(     5),  INT16_C(     9),  INT16_C(     6),  INT16_C(     7),  INT16_C(     9),  INT16_C(     5),  INT16_C(     8) } },
    { {  INT16_C(   420),  INT16_C( 31705), -INT16_C( 13718), -INT16_C( 20043),  INT16_C( 21241),  INT16_C( 27393),  INT16_C(  9840),  INT16_C( 15424),
        -INT16_C(  7142),  INT16_C(  3198),  INT16_C(  7792),  INT16_C( 28986), -INT16_C(  9572), -INT16_C(  4358),  INT16_C( 31786), -INT16_C( 12451),
         INT16_C( 13949), -INT16_C(  6326),  INT16_C(     1), -INT16_C(  1384), -INT16_C( 26030), -INT16_C( 15771), -INT16_C( 23104), -INT16_C(  9474),
         INT16_C( 32138), -INT16_C(  1306),  INT16_C(  8603),  INT16_C( 14443),  INT16_C( 26107),  INT16_C(  9510), -INT16_C( 31775),  INT16_C( 24308) },
      {  INT16_C(     4),  INT16_C(    11),  INT16_C(     8),  INT16_C(     9),  INT16_C(     9),  INT16_C(     6),  INT16_C(     6),  INT16_C(     5),
         INT16_C(     7),  INT16_C(     8),  INT16_C(     7),  INT16_C(     8),  INT16_C(     9),  INT16_C(    12),  INT16_C(     8),  INT16_C(    11),
         INT16_C(    10),  INT16_C(     9),  INT16_C(     1),  INT16_C(     9),  INT16_C(     7),  INT16_C(     7),  INT16_C(     6),  INT16_C(    12),
         INT16_C(     9),  INT16_C(    11),  INT16_C(     7),  INT16_C(     8),  INT16_C(    11),  INT16_C(     6),  INT16_C(     7),  INT16_C(    10) } },
    { {  INT16_C( 16314), -INT16_C( 17594), -INT16_C(  8641), -INT16_C( 28235),  INT16_C(  6776),  INT16_C( 14419),  INT16_C( 21184),  INT16_C( 18962),
        -INT16_C(  1585),  INT16_C( 27204), -INT16_C( 20710),  INT16_C(  5538), -INT16_C( 14316), -INT16_C(  2758),  INT16_C( 12108),  INT16_C(  1619),
        -INT16_C( 26258), -INT16_C( 21055),  INT16_C( 30328), -INT16_C(  4034), -INT16_C( 28272),  INT16_C( 20521),  INT16_C( 15331), -INT16_C( 19814),
        -INT16_C(  8652),  INT16_C( 19997), -INT16_C( 16499), -INT16_C( 24221), -INT16_C( 24952), -INT16_C( 11114), -INT16_C(  5427),  INT16_C( 15322) },
      {  INT16_C(    11),  INT16_C(     9),  INT16_C(    12),  INT16_C(     8),  INT16_C(     7),  INT16_C(     7),  INT16_C(     5),  INT16_C(     5),
         INT16_C(    12),  INT16_C(     6),  INT16_C(     9),  INT16_C(     6),  INT16_C(     5),  INT16_C(    10),  INT16_C(     8),  INT16_C(     6),
         INT16_C(     9),  INT16_C(     8),  INT16_C(     9),  INT16_C(     9),  INT16_C(     5),  INT16_C(     5),  INT16_C(    10),  INT16_C(     8),
         INT16_C(     9),  INT16_C(     8),  INT16_C(    11),  INT16_C(     7),  INT16_C(     7),  INT16_C(     8),  INT16_C(    10),  INT16_C(    10) } },
    { { -INT16_C( 25725), -INT16_C(  1048),  INT16_C(  9745), -INT16_C( 24084),  INT16_C(  5559), -INT16_C( 25614), -INT16_C( 29616), -INT16_C( 31411),
         INT16_C( 27243), -INT16_C(  1837),  INT16_C( 14122), -INT16_C( 19814),  INT16_C( 12501), -INT16_C( 23930),  INT16_C( 24602), -INT16_C( 24867),
        -INT16_C( 14853),  INT16_C(  3225), -INT16_C( 31253), -INT16_C( 23891), -INT16_C( 24678), -INT16_C(  5315), -INT16_C( 29908), -INT16_C( 26768),
         INT16_C( 17397),  INT16_C(  8079),  INT16_C( 10618),  INT16_C( 20433),  INT16_C( 22362),  INT16_C( 29937), -INT16_C( 12617), -INT16_C( 19950) },
      {  INT16_C(     8),  INT16_C(    11),  INT16_C(     5),  INT16_C(     8),  INT16_C(     9),  INT16_C(    10),  INT16_C(     5),  INT16_C(     7),
         INT16_C(     9),  INT16_C(    10),  INT16_C(     8),  INT16_C(     8),  INT16_C(     7),  INT16_C(     6),  INT16_C(     5),  INT16_C(    11),
         INT16_C(    11),  INT16_C(     6),  INT16_C(     9),  INT16_C(     8),  INT16_C(    10),  INT16_C(    11),  INT16_C(     7),  INT16_C(     8),
         INT16_C(     9),  INT16_C(    10),  INT16_C(     8),  INT16_C(     9),  INT16_C(     9),  INT16_C(     9),  INT16_C(    11),  INT16_C(     6) } },
    { { -INT16_C( 21357),  INT16_C( 32446),  INT16_C( 27697), -INT16_C( 13279),  INT16_C( 24075),  INT16_C( 14263),  INT16_C( 10217), -INT16_C(  8242),
         INT16_C( 24170), -INT16_C(  6658), -INT16_C( 12153), -INT16_C(  7884),  INT16_C(  9767), -INT16_C(  8362),  INT16_C( 26868), -INT16_C( 30575),
         INT16_C( 20500),  INT16_C( 17926),  INT16_C( 10172), -INT16_C( 14574), -INT16_C( 13946),  INT16_C( 28671), -INT16_C( 12816),  INT16_C( 23118),
         INT16_C( 19755), -INT16_C( 19649),  INT16_C( 29725),  INT16_C( 17556), -INT16_C(  5478), -INT16_C( 29149), -INT16_C( 19117),  INT16_C( 26390) },
      {  INT16_C(     8),  INT16_C(    12),  INT16_C(     7),  INT16_C(     6),  INT16_C(     8),  INT16_C(    11),  INT16_C(     9),  INT16_C(    12),
         INT16_C(     9),  INT16_C(    12),  INT16_C(     7),  INT16_C(     7),  INT16_C(     7),  INT16_C(    11),  INT16_C(     8),  INT16_C(     5),
         INT16_C(     4),  INT16_C(     5),  INT16_C(     9),  INT16_C(     7),  INT16_C(     7),  INT16_C(    14),  INT16_C(     9),  INT16_C(     8),
         INT16_C(     8),  INT16_C(    11),  INT16_C(     8),  INT16_C(     5),  INT16_C(     9),  INT16_C(     7),  INT16_C(     9),  INT16_C(     8) } },
    { {  INT16_C(  7429), -INT16_C( 15955), -INT16_C( 16572), -INT16_C( 13688), -INT16_C( 30840),  INT16_C( 30778), -INT16_C( 30635), -INT16_C( 32557),
         INT16_C(  4821), -INT16_C(  3533), -INT16_C( 14202),  INT16_C(  8247),  INT16_C( 23218),  INT16_C(  1455), -INT16_C( 15089),  INT16_C(  5229),
         INT16_C(  6882),  INT16_C( 10197),  INT16_C( 24282),  INT16_C( 25329),  INT16_C( 11237),  INT16_C( 15067), -INT16_C( 20812), -INT16_C( 30277),
        -INT16_C(  4416),  INT16_C( 18300), -INT16_C( 19530),  INT16_C( 26983),  INT16_C(  5645),  INT16_C(  7534), -INT16_C(  9252), -INT16_C( 16847) },
      {  INT16_C(     6),  INT16_C(     8),  INT16_C(     9),  INT16_C(     6),  INT16_C(     6),  INT16_C(     8),  INT16_C(     6),  INT16_C(     6),
         INT16_C(     7),  INT16_C(     9),  INT16_C(     6),  INT16_C(     6),  INT16_C(     8),  INT16_C(     8),  INT16_C(     8),  INT16_C(     7),
         INT16_C(     7),  INT16_C(     9),  INT16_C(    10),  INT16_C(     8),  INT16_C(     9),  INT16_C(    10),  INT16_C(     9),  INT16_C(     9),
         INT16_C(     8),  INT16_C(     9),  INT16_C(    10),  INT16_C(     9),  INT16_C(     6),  INT16_C(     9),  INT16_C(    11),  INT16_C(     9) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_popcnt_epi16(a);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_popcnt_epi16(a);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 19909), -INT16_C( 20818),  INT16_C( 20775), -INT16_C( 21958), -INT16_C(  2047),  INT16_C( 23101), -INT16_C(  5584), -INT16_C( 18478),
         INT16_C( 20007), -INT16_C( 12719), -INT16_C( 25439),  INT16_C(  4783),  INT16_C( 18215), -INT16_C( 19600),  INT16_C(  6233), -INT16_C( 27274),
         INT16_C(  9674), -INT16_C(  3773),  INT16_C( 32374),  INT16_C( 30619), -INT16_C( 10122), -INT16_C( 22575), -INT16_C( 23357), -INT16_C(  5538),
        -INT16_C( 20494), -INT16_C( 27720),  INT16_C( 26443),  INT16_C( 29350),  INT16_C(  5807),  INT16_C(  2085), -INT16_C( 25553), -INT16_C(  1635) },
      UINT32_C( 938205633),
      { -INT16_C( 31137), -INT16_C( 10833), -INT16_C( 32673),  INT16_C(  8828), -INT16_C(  9692),  INT16_C(  5900), -INT16_C( 14967), -INT16_C( 11094),
         INT16_C( 20524), -INT16_C(  9402),  INT16_C( 27751), -INT16_C( 26908), -INT16_C( 32504), -INT16_C( 13937),  INT16_C( 31330), -INT16_C( 16128),
        -INT16_C( 20735),  INT16_C( 24727),  INT16_C(  4912),  INT16_C( 21634), -INT16_C( 28946),  INT16_C( 30571),  INT16_C(  5715), -INT16_C( 32692),
        -INT16_C( 28058), -INT16_C( 12965),  INT16_C( 16382),  INT16_C(  1635), -INT16_C(  3135),  INT16_C(  9167), -INT16_C( 12179),  INT16_C( 28389) },
      {  INT16_C(     9), -INT16_C( 20818),  INT16_C( 20775), -INT16_C( 21958), -INT16_C(  2047),  INT16_C( 23101),  INT16_C(     7),  INT16_C(     8),
         INT16_C(     5), -INT16_C( 12719), -INT16_C( 25439),  INT16_C(  4783),  INT16_C( 18215),  INT16_C(     9),  INT16_C(     8),  INT16_C(     3),
         INT16_C(     7),  INT16_C(     7),  INT16_C( 32374),  INT16_C(     5), -INT16_C( 10122),  INT16_C(    11),  INT16_C(     7),  INT16_C(     4),
         INT16_C(     7),  INT16_C(    10),  INT16_C(    13),  INT16_C( 29350),  INT16_C(     9),  INT16_C(     9), -INT16_C( 25553), -INT16_C(  1635) } },
    { {  INT16_C( 31871), -INT16_C( 20530),  INT16_C( 20623),  INT16_C( 32004),  INT16_C( 28639),  INT16_C( 13045),  INT16_C( 16773), -INT16_C(  4942),
         INT16_C(  3795), -INT16_C( 11591),  INT16_C(  7501),  INT16_C(  3800), -INT16_C( 22512),  INT16_C( 32050),  INT16_C(  6008), -INT16_C(  2068),
        -INT16_C( 17773),  INT16_C(  8871), -INT16_C( 21749), -INT16_C(  5472), -INT16_C( 27366), -INT16_C( 24548), -INT16_C( 12330), -INT16_C( 22132),
         INT16_C( 17885),  INT16_C( 10875),  INT16_C( 21602),  INT16_C( 29241),  INT16_C( 27644),  INT16_C( 29936), -INT16_C(  9086),  INT16_C(  5483) },
      UINT32_C(2704741014),
      { -INT16_C( 10307), -INT16_C( 10101), -INT16_C( 22420),  INT16_C( 17016),  INT16_C(  1143),  INT16_C( 21740),  INT16_C( 26441), -INT16_C( 21378),
        -INT16_C( 18501), -INT16_C( 18658),  INT16_C(  3618), -INT16_C( 23509), -INT16_C( 26646), -INT16_C( 32327), -INT16_C(  3671),  INT16_C( 26402),
        -INT16_C( 20792),  INT16_C( 13631), -INT16_C( 18602), -INT16_C( 12937),  INT16_C( 25531),  INT16_C(  1057), -INT16_C( 24629), -INT16_C( 31056),
        -INT16_C( 12457),  INT16_C( 31038),  INT16_C( 27101), -INT16_C( 14306), -INT16_C( 10496), -INT16_C( 21943),  INT16_C( 27592), -INT16_C( 28399) },
      {  INT16_C( 31871),  INT16_C(     8),  INT16_C(     7),  INT16_C( 32004),  INT16_C(     7),  INT16_C( 13045),  INT16_C( 16773),  INT16_C(    10),
         INT16_C(  3795),  INT16_C(    10),  INT16_C(  7501),  INT16_C(  3800),  INT16_C(    10),  INT16_C( 32050),  INT16_C(  6008), -INT16_C(  2068),
         INT16_C(     8),  INT16_C(    10),  INT16_C(    10), -INT16_C(  5472),  INT16_C(    10),  INT16_C(     3), -INT16_C( 12330), -INT16_C( 22132),
         INT16_C(    11),  INT16_C( 10875),  INT16_C( 21602),  INT16_C( 29241),  INT16_C( 27644),  INT16_C(     7), -INT16_C(  9086),  INT16_C(     5) } },
    { {  INT16_C( 20505),  INT16_C( 28614),  INT16_C( 15623), -INT16_C( 15812),  INT16_C( 23969),  INT16_C( 27846),  INT16_C( 30717),  INT16_C( 21746),
         INT16_C( 12358),  INT16_C(  9165), -INT16_C(  5222), -INT16_C( 25877),  INT16_C( 13507), -INT16_C( 29884),  INT16_C( 21920), -INT16_C( 18148),
        -INT16_C(  7515), -INT16_C( 21463),  INT16_C( 25888), -INT16_C( 16018),  INT16_C( 13763), -INT16_C( 16339),  INT16_C(  8108), -INT16_C(  3564),
        -INT16_C(  7856), -INT16_C(  5611),  INT16_C(   461), -INT16_C( 28540), -INT16_C( 14027), -INT16_C( 10981),  INT16_C( 14366), -INT16_C( 15217) },
      UINT32_C( 980465690),
      { -INT16_C(  8419), -INT16_C(  7941),  INT16_C( 10260), -INT16_C( 16224), -INT16_C( 19384), -INT16_C( 26446), -INT16_C( 14442),  INT16_C( 25474),
         INT16_C(  1736), -INT16_C(   269),  INT16_C(  3791), -INT16_C(  4397),  INT16_C( 25158),  INT16_C( 25010),  INT16_C(  8730),  INT16_C( 14491),
        -INT16_C( 26879),  INT16_C(  5400), -INT16_C( 17985),  INT16_C(  2005), -INT16_C( 30867),  INT16_C(   927),  INT16_C(  8527),  INT16_C(  5990),
         INT16_C( 22824), -INT16_C(  2283), -INT16_C(  5784), -INT16_C( 20763), -INT16_C( 26805),  INT16_C( 26127), -INT16_C( 21574), -INT16_C( 17506) },
      {  INT16_C( 20505),  INT16_C(    10),  INT16_C( 15623),  INT16_C(     4),  INT16_C(     6),  INT16_C( 27846),  INT16_C( 30717),  INT16_C( 21746),
         INT16_C( 12358),  INT16_C(  9165), -INT16_C(  5222),  INT16_C(    11),  INT16_C(     6),  INT16_C(     7),  INT16_C( 21920),  INT16_C(     8),
        -INT16_C(  7515), -INT16_C( 21463),  INT16_C( 25888), -INT16_C( 16018),  INT16_C(     9),  INT16_C(     8),  INT16_C(     7), -INT16_C(  3564),
        -INT16_C(  7856),  INT16_C(    10),  INT16_C(   461),  INT16_C(    10),  INT16_C(     9),  INT16_C(     8),  INT16_C( 14366), -INT16_C( 15217) } },
    { { -INT16_C( 18878),  INT16_C(   465), -INT16_C( 22929), -INT16_C(  8951), -INT16_C( 22482),  INT16_C( 32224),  INT16_C( 18378), -INT16_C(  3436),
        -INT16_C( 21856),  INT16_C(  2281), -INT16_C( 12397), -INT16_C(  8521), -INT16_C( 14746),  INT16_C(  8260), -INT16_C(  7567), -INT16_C( 19492),
        -INT16_C( 21095),  INT16_C(  2229), -INT16_C( 16813), -INT16_C( 32283), -INT16_C( 14746),  INT16_C( 12542), -INT16_C( 27891), -INT16_C( 21214),
         INT16_C(  3133), -INT16_C( 12106),  INT16_C( 28123),  INT16_C( 16814), -INT16_C(  3277), -INT16_C( 23198),  INT16_C( 16085),  INT16_C( 28248) },
      UINT32_C(1047989739),
      {  INT16_C( 23755),  INT16_C( 12992), -INT16_C( 16862),  INT16_C( 12130), -INT16_C( 31407), -INT16_C( 28963), -INT16_C( 27759),  INT16_C( 27742),
         INT16_C(  3328),  INT16_C( 13229),  INT16_C(  3840), -INT16_C( 10792),  INT16_C( 12621),  INT16_C( 14404), -INT16_C( 17602),  INT16_C(  2679),
         INT16_C( 14103),  INT16_C( 14908), -INT16_C( 24843),  INT16_C( 18281),  INT16_C( 17955), -INT16_C( 19243),  INT16_C( 13529), -INT16_C(  9952),
        -INT16_C( 12735),  INT16_C( 16653), -INT16_C(  6691),  INT16_C( 11030),  INT16_C( 23062),  INT16_C( 21859), -INT16_C(  9707),  INT16_C( 11615) },
      {  INT16_C(     9),  INT16_C(     5), -INT16_C( 22929),  INT16_C(     8), -INT16_C( 22482),  INT16_C(    10),  INT16_C(     7),  INT16_C(     9),
         INT16_C(     3),  INT16_C(  2281),  INT16_C(     4),  INT16_C(     9), -INT16_C( 14746),  INT16_C(  8260), -INT16_C(  7567), -INT16_C( 19492),
         INT16_C(     9),  INT16_C(     8),  INT16_C(    11), -INT16_C( 32283),  INT16_C(     6),  INT16_C(     9),  INT16_C(     8), -INT16_C( 21214),
         INT16_C(  3133),  INT16_C(     5),  INT16_C(    11),  INT16_C(     7),  INT16_C(     7),  INT16_C(     8),  INT16_C( 16085),  INT16_C( 28248) } },
    { { -INT16_C( 25839),  INT16_C(  1895), -INT16_C( 12231),  INT16_C( 23886),  INT16_C(  8983), -INT16_C(  4079),  INT16_C( 12887), -INT16_C( 26422),
        -INT16_C( 10496), -INT16_C(  8743), -INT16_C(  3908), -INT16_C( 11512),  INT16_C( 27722),  INT16_C( 24616), -INT16_C( 30906),  INT16_C( 22669),
        -INT16_C(  3038),  INT16_C( 23391), -INT16_C( 21052), -INT16_C(  9288), -INT16_C( 13616),  INT16_C( 10444), -INT16_C( 26884), -INT16_C(   832),
        -INT16_C( 26003),  INT16_C( 10713), -INT16_C(  7542), -INT16_C( 11012),  INT16_C(  9294), -INT16_C( 27596), -INT16_C( 15957), -INT16_C( 12820) },
      UINT32_C(2049526709),
      { -INT16_C(  7688), -INT16_C( 13995),  INT16_C(  8619), -INT16_C( 22543), -INT16_C( 20041),  INT16_C(  9379),  INT16_C( 32075), -INT16_C( 10930),
         INT16_C( 19039), -INT16_C( 21078), -INT16_C(  8593),  INT16_C(  6721),  INT16_C( 11936),  INT16_C( 21992),  INT16_C(  4473),  INT16_C( 29391),
         INT16_C(  9714), -INT16_C( 25029),  INT16_C( 11334), -INT16_C(   443), -INT16_C(  5667),  INT16_C( 10530),  INT16_C( 28774), -INT16_C( 14850),
        -INT16_C( 22341),  INT16_C( 10866), -INT16_C( 19577),  INT16_C( 10052),  INT16_C( 11489),  INT16_C( 23420),  INT16_C( 19517),  INT16_C( 12493) },
      {  INT16_C(     9),  INT16_C(  1895),  INT16_C(     7),  INT16_C( 23886),  INT16_C(    10),  INT16_C(     6),  INT16_C( 12887),  INT16_C(     9),
         INT16_C(     9),  INT16_C(     9), -INT16_C(  3908),  INT16_C(     5),  INT16_C( 27722),  INT16_C( 24616),  INT16_C(     7),  INT16_C( 22669),
         INT16_C(     8),  INT16_C( 23391), -INT16_C( 21052),  INT16_C(    10), -INT16_C( 13616),  INT16_C(     5), -INT16_C( 26884), -INT16_C(   832),
        -INT16_C( 26003),  INT16_C(     7), -INT16_C(  7542),  INT16_C(     6),  INT16_C(     7),  INT16_C(    10),  INT16_C(     8), -INT16_C( 12820) } },
    { {  INT16_C(  2161), -INT16_C( 18482),  INT16_C(  4916),  INT16_C(  4533), -INT16_C(  9988),  INT16_C( 25146),  INT16_C( 14664),  INT16_C(   807),
        -INT16_C( 26143),  INT16_C( 26669),  INT16_C( 29261),  INT16_C( 11919),  INT16_C(  3230), -INT16_C(  9079),  INT16_C( 22104), -INT16_C( 14068),
        -INT16_C(  9634), -INT16_C( 28032),  INT16_C( 14061), -INT16_C(  5468), -INT16_C(  8690),  INT16_C( 22092),  INT16_C( 29719), -INT16_C(  1702),
        -INT16_C( 30963),  INT16_C( 23137), -INT16_C(  3591), -INT16_C( 26487),  INT16_C(  4861),  INT16_C( 21876), -INT16_C( 32663), -INT16_C( 14562) },
      UINT32_C(1197121114),
      { -INT16_C(   300), -INT16_C(  7631),  INT16_C( 32476), -INT16_C(  3015), -INT16_C( 27662), -INT16_C(    19),  INT16_C( 19994),  INT16_C(  5210),
        -INT16_C(  7361),  INT16_C( 15532),  INT16_C(  8437),  INT16_C( 24209), -INT16_C( 20576), -INT16_C(  1498), -INT16_C( 32690),  INT16_C(  8769),
         INT16_C( 29566),  INT16_C( 23045),  INT16_C( 16113), -INT16_C(  7346),  INT16_C( 15313), -INT16_C(  5150),  INT16_C( 15498), -INT16_C( 13825),
        -INT16_C( 21729),  INT16_C(  5382), -INT16_C( 26677),  INT16_C( 27507), -INT16_C( 26297), -INT16_C( 27291), -INT16_C( 22759), -INT16_C( 26697) },
      {  INT16_C(  2161),  INT16_C(     7),  INT16_C(  4916),  INT16_C(     9),  INT16_C(     9),  INT16_C( 25146),  INT16_C(     7),  INT16_C(   807),
        -INT16_C( 26143),  INT16_C(     8),  INT16_C(     7),  INT16_C(     8),  INT16_C(     8), -INT16_C(  9079),  INT16_C( 22104),  INT16_C(     4),
        -INT16_C(  9634),  INT16_C(     6),  INT16_C( 14061),  INT16_C(     9),  INT16_C(     9),  INT16_C( 22092),  INT16_C(     7), -INT16_C(  1702),
         INT16_C(    10),  INT16_C(     5),  INT16_C(    10), -INT16_C( 26487),  INT16_C(  4861),  INT16_C( 21876),  INT16_C(     8), -INT16_C( 14562) } },
    { { -INT16_C( 17382),  INT16_C(  3058),  INT16_C( 16634), -INT16_C( 13330), -INT16_C( 12164),  INT16_C(  1719), -INT16_C( 18931),  INT16_C( 11471),
        -INT16_C( 10910),  INT16_C( 11585), -INT16_C( 19091), -INT16_C( 19303), -INT16_C(   434),  INT16_C( 26697),  INT16_C(   165), -INT16_C( 16385),
        -INT16_C(  3651), -INT16_C( 18486), -INT16_C( 18382), -INT16_C( 20861),  INT16_C( 14985), -INT16_C( 26956), -INT16_C( 31760),  INT16_C( 21186),
         INT16_C(  1113), -INT16_C( 14720),  INT16_C(  6585),  INT16_C(  1914), -INT16_C( 15593), -INT16_C( 17041),  INT16_C( 28611), -INT16_C( 32644) },
      UINT32_C(2453161824),
      { -INT16_C( 17409), -INT16_C( 30656), -INT16_C(  2827), -INT16_C(  6882), -INT16_C(  7816), -INT16_C( 11976), -INT16_C( 18203), -INT16_C( 24937),
         INT16_C(  4561), -INT16_C(  5979),  INT16_C(  5588), -INT16_C( 26715),  INT16_C(  8836), -INT16_C(  7144),  INT16_C( 20585),  INT16_C( 26743),
        -INT16_C( 18677),  INT16_C(   241),  INT16_C(  4012),  INT16_C(  9445),  INT16_C(  7664), -INT16_C( 10763), -INT16_C( 29483), -INT16_C( 22925),
         INT16_C(  6557),  INT16_C( 29071),  INT16_C( 13358), -INT16_C( 19960),  INT16_C(  8278), -INT16_C( 16490),  INT16_C(  3440),  INT16_C( 31528) },
      { -INT16_C( 17382),  INT16_C(  3058),  INT16_C( 16634), -INT16_C( 13330), -INT16_C( 12164),  INT16_C(     7),  INT16_C(     9),  INT16_C( 11471),
         INT16_C(     6),  INT16_C(     8),  INT16_C(     7), -INT16_C( 19303), -INT16_C(   434),  INT16_C( 26697),  INT16_C(     6), -INT16_C( 16385),
        -INT16_C(  3651), -INT16_C( 18486), -INT16_C( 18382),  INT16_C(     7),  INT16_C(     8),  INT16_C(    11), -INT16_C( 31760),  INT16_C( 21186),
         INT16_C(  1113),  INT16_C(     9),  INT16_C(  6585),  INT16_C(  1914),  INT16_C(     5), -INT16_C( 17041),  INT16_C( 28611),  INT16_C(     8) } },
    { {  INT16_C(  6597),  INT16_C( 29051),  INT16_C( 24872),  INT16_C(  6549), -INT16_C( 30082),  INT16_C( 21742),  INT16_C( 25110), -INT16_C( 19462),
        -INT16_C( 30341), -INT16_C( 22236),  INT16_C( 11454),  INT16_C(  5211), -INT16_C(  3763), -INT16_C( 16940), -INT16_C(   769), -INT16_C( 15303),
        -INT16_C( 19435),  INT16_C( 15669), -INT16_C( 13803), -INT16_C( 27562),  INT16_C( 17748),  INT16_C( 27368), -INT16_C(  7513),  INT16_C(  8733),
         INT16_C( 16748),  INT16_C( 10955),  INT16_C(  9837), -INT16_C( 17858),  INT16_C(  4631),  INT16_C(  5752), -INT16_C( 20210),  INT16_C(  9178) },
      UINT32_C(2069958501),
      { -INT16_C( 18471),  INT16_C( 11535), -INT16_C(  2052), -INT16_C( 23657), -INT16_C( 19239),  INT16_C( 17861), -INT16_C( 28427),  INT16_C( 25455),
        -INT16_C( 20810), -INT16_C( 12771), -INT16_C( 27200), -INT16_C( 12316), -INT16_C( 16570), -INT16_C( 21262),  INT16_C( 21454), -INT16_C( 22489),
         INT16_C( 13835),  INT16_C(  2005),  INT16_C( 27949),  INT16_C(  1707),  INT16_C( 28705),  INT16_C(  5964), -INT16_C( 17663), -INT16_C( 18566),
        -INT16_C( 26775),  INT16_C( 10885),  INT16_C( 27181),  INT16_C( 29689), -INT16_C(  5335), -INT16_C(  2273),  INT16_C( 17983),  INT16_C( 19103) },
      {  INT16_C(    11),  INT16_C( 29051),  INT16_C(    13),  INT16_C(  6549), -INT16_C( 30082),  INT16_C(     7),  INT16_C(     8), -INT16_C( 19462),
         INT16_C(    10),  INT16_C(     9),  INT16_C(     6),  INT16_C(    10), -INT16_C(  3763), -INT16_C( 16940), -INT16_C(   769), -INT16_C( 15303),
         INT16_C(     7),  INT16_C( 15669), -INT16_C( 13803), -INT16_C( 27562),  INT16_C( 17748),  INT16_C(     7),  INT16_C(     7),  INT16_C(  8733),
         INT16_C(     9),  INT16_C(     6),  INT16_C(  9837),  INT16_C(    11),  INT16_C(     9),  INT16_C(    12),  INT16_C(     9),  INT16_C(  9178) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_popcnt_epi16(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_popcnt_epi16(src, k, a);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(2840687996),
      { -INT16_C(   798),  INT16_C(   944), -INT16_C(   915),  INT16_C( 28186), -INT16_C( 27465),  INT16_C(  8485), -INT16_C( 21716),  INT16_C( 22859),
         INT16_C( 17429),  INT16_C( 16076), -INT16_C(  5073),  INT16_C( 28213), -INT16_C( 10958), -INT16_C( 20552),  INT16_C(  2634),  INT16_C( 11352),
         INT16_C(  2054),  INT16_C( 29487),  INT16_C( 18948), -INT16_C( 17183),  INT16_C(  2014),  INT16_C(  2781),  INT16_C( 10418), -INT16_C( 14493),
         INT16_C( 12396), -INT16_C( 25851),  INT16_C( 14876),  INT16_C( 19978), -INT16_C( 15857),  INT16_C( 23037),  INT16_C( 22220), -INT16_C( 11387) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),  INT16_C(     8),  INT16_C(     9),  INT16_C(     5),  INT16_C(     8),  INT16_C(     0),
         INT16_C(     5),  INT16_C(     0),  INT16_C(    10),  INT16_C(     0),  INT16_C(     8),  INT16_C(    10),  INT16_C(     5),  INT16_C(     0),
         INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),
         INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(    11),  INT16_C(     0),  INT16_C(     8) } },
    { UINT32_C(1665578334),
      {  INT16_C( 10495), -INT16_C(  8929), -INT16_C(   977), -INT16_C(  7704),  INT16_C( 19236), -INT16_C( 28504), -INT16_C( 21125), -INT16_C( 26837),
         INT16_C( 13799), -INT16_C(  2074), -INT16_C(  7176), -INT16_C( 15280), -INT16_C( 10695), -INT16_C( 26473), -INT16_C(  8565), -INT16_C( 29957),
         INT16_C(  6662),  INT16_C( 13671),  INT16_C( 20246),  INT16_C( 14870), -INT16_C( 16741),  INT16_C(  5834), -INT16_C(  2709),  INT16_C( 21166),
        -INT16_C( 27605),  INT16_C(  9033), -INT16_C( 25993), -INT16_C( 19993),  INT16_C( 32624), -INT16_C(  1207),  INT16_C( 17501),  INT16_C( 25477) },
      {  INT16_C(     0),  INT16_C(    11),  INT16_C(    11),  INT16_C(     8),  INT16_C(     6),  INT16_C(     0),  INT16_C(    11),  INT16_C(     0),
         INT16_C(    10),  INT16_C(     0),  INT16_C(    10),  INT16_C(     0),  INT16_C(     9),  INT16_C(     8),  INT16_C(     0),  INT16_C(    10),
         INT16_C(     0),  INT16_C(     9),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),  INT16_C(     0),
         INT16_C(     7),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     7),  INT16_C(     0) } },
    { UINT32_C(1956179038),
      { -INT16_C( 20932), -INT16_C( 10322),  INT16_C( 30828), -INT16_C( 10259), -INT16_C( 25747), -INT16_C( 26583),  INT16_C( 29487), -INT16_C( 22597),
        -INT16_C( 23795),  INT16_C( 32088), -INT16_C( 24286),  INT16_C( 32632), -INT16_C(   539),  INT16_C( 17378),  INT16_C( 31465),  INT16_C(  9655),
         INT16_C( 25896), -INT16_C( 27396), -INT16_C(  5411),  INT16_C( 19051), -INT16_C( 27515), -INT16_C( 18973), -INT16_C( 25081),  INT16_C(  5212),
        -INT16_C( 19391),  INT16_C( 25489),  INT16_C(  2389),  INT16_C( 15074), -INT16_C( 15354), -INT16_C(  3971),  INT16_C( 13374),  INT16_C( 26133) },
      {  INT16_C(     0),  INT16_C(    11),  INT16_C(     8),  INT16_C(    12),  INT16_C(    10),  INT16_C(     0),  INT16_C(    10),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(    11),  INT16_C(     0),  INT16_C(     7),  INT16_C(    10),  INT16_C(     9),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     5),  INT16_C(    10),  INT16_C(     8),  INT16_C(     0) } },
    { UINT32_C(1996100249),
      {  INT16_C( 26108), -INT16_C( 32320), -INT16_C( 23558),  INT16_C(   310), -INT16_C( 28094), -INT16_C( 31978), -INT16_C( 22714), -INT16_C( 25625),
        -INT16_C( 13903), -INT16_C( 18475),  INT16_C( 21134), -INT16_C( 13145), -INT16_C( 17018),  INT16_C(  7987),  INT16_C( 11727), -INT16_C( 13419),
         INT16_C( 22163), -INT16_C( 29364), -INT16_C( 31751),  INT16_C( 15246), -INT16_C( 23531),  INT16_C( 23743), -INT16_C( 22964), -INT16_C(   521),
        -INT16_C( 12945), -INT16_C(   588),  INT16_C( 23583), -INT16_C( 22838), -INT16_C(   743), -INT16_C(  5947),  INT16_C( 23338), -INT16_C( 16973) },
      {  INT16_C(    10),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(     5),  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),
         INT16_C(     0),  INT16_C(    11),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     9),  INT16_C(     6),  INT16_C(    11),  INT16_C(     7),  INT16_C(    14),
         INT16_C(     0),  INT16_C(    11),  INT16_C(     9),  INT16_C(     0),  INT16_C(    10),  INT16_C(     8),  INT16_C(     8),  INT16_C(     0) } },
    { UINT32_C(2857041841),
      { -INT16_C(  9854), -INT16_C( 26394), -INT16_C( 23171), -INT16_C( 13836), -INT16_C(  5301), -INT16_C( 17722),  INT16_C( 31672), -INT16_C( 10056),
        -INT16_C( 32041), -INT16_C(  3970),  INT16_C( 17279), -INT16_C( 22056), -INT16_C( 29794),  INT16_C( 20327), -INT16_C( 20086),  INT16_C(  3578),
        -INT16_C(  8054),  INT16_C(  2213), -INT16_C( 26235), -INT16_C( 12079), -INT16_C( 26492),  INT16_C( 15754),  INT16_C( 16915), -INT16_C(  5611),
        -INT16_C( 27708),  INT16_C( 17370), -INT16_C( 19754),  INT16_C( 30189),  INT16_C( 21565), -INT16_C( 14396), -INT16_C( 16891), -INT16_C( 28460) },
      {  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     9),  INT16_C(     0),  INT16_C(     8),
         INT16_C(     8),  INT16_C(    10),  INT16_C(    10),  INT16_C(     8),  INT16_C(     9),  INT16_C(    10),  INT16_C(     7),  INT16_C(     9),
         INT16_C(     0),  INT16_C(     5),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(    11),  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(     6) } },
    { UINT32_C( 597195166),
      {  INT16_C( 26898), -INT16_C( 26637),  INT16_C( 32257),  INT16_C(  5332), -INT16_C(  5696), -INT16_C( 31234), -INT16_C( 10116),  INT16_C( 21192),
        -INT16_C( 19062), -INT16_C( 14393), -INT16_C( 29687),  INT16_C(  3983),  INT16_C( 25418), -INT16_C(  5729),  INT16_C( 14301), -INT16_C(  4340),
         INT16_C(   160), -INT16_C( 23930),  INT16_C( 23166),  INT16_C( 16054), -INT16_C( 19133), -INT16_C( 16445), -INT16_C( 29555),  INT16_C(  6162),
        -INT16_C(  9919),  INT16_C( 19423),  INT16_C( 28261), -INT16_C( 20390), -INT16_C(  1582), -INT16_C( 20583), -INT16_C( 23248), -INT16_C( 12130) },
      {  INT16_C(     0),  INT16_C(    11),  INT16_C(     7),  INT16_C(     6),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),
         INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     7),  INT16_C(    11),  INT16_C(    11),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(     4),
         INT16_C(     7),  INT16_C(    11),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C( 594683301),
      {  INT16_C( 10623), -INT16_C( 15518),  INT16_C(  9694),  INT16_C( 27522), -INT16_C( 27471), -INT16_C(  3197),  INT16_C( 25454), -INT16_C( 11458),
        -INT16_C( 26415), -INT16_C( 23677),  INT16_C(  7313), -INT16_C( 16046), -INT16_C(  3646),  INT16_C( 26513),  INT16_C(  1046), -INT16_C( 27253),
        -INT16_C(  4819),  INT16_C(  2904), -INT16_C(  9454), -INT16_C( 15242), -INT16_C(  1425), -INT16_C(  8777), -INT16_C(  2723),  INT16_C( 11953),
         INT16_C( 13453),  INT16_C(  7890),  INT16_C(  9297),  INT16_C(  5087),  INT16_C( 28693),  INT16_C( 11130),  INT16_C(  1396), -INT16_C( 24127) },
      {  INT16_C(    10),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(    10),
         INT16_C(     7),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(    12),  INT16_C(    12),  INT16_C(    11),  INT16_C(     0),
         INT16_C(     7),  INT16_C(     8),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(  95164914),
      {  INT16_C(  9204),  INT16_C( 25801), -INT16_C( 32739),  INT16_C( 31297), -INT16_C(  3467),  INT16_C(   680),  INT16_C( 31271),  INT16_C( 30752),
        -INT16_C(    97), -INT16_C( 19317),  INT16_C(  1391), -INT16_C(  6944), -INT16_C( 24309), -INT16_C(   635),  INT16_C( 12986), -INT16_C( 20734),
        -INT16_C( 13483),  INT16_C( 29203),  INT16_C( 21579), -INT16_C( 16148), -INT16_C( 27577),  INT16_C( 28354), -INT16_C(  7665), -INT16_C( 20762),
         INT16_C( 29153),  INT16_C( 20834),  INT16_C( 17014), -INT16_C( 32459), -INT16_C( 17693), -INT16_C( 24961), -INT16_C( 32276),  INT16_C( 16717) },
      {  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     4),  INT16_C(     9),  INT16_C(     5),
         INT16_C(    14),  INT16_C(     0),  INT16_C(     0),  INT16_C(     7),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     7),  INT16_C(     7),  INT16_C(     0),  INT16_C(     8),  INT16_C(     0),  INT16_C(    10),
         INT16_C(     8),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_popcnt_epi16(test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_popcnt_epi16(k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   790296586),  INT32_C(  1244845925), -INT32_C(  1232794366),  INT32_C(  2084585659), -INT32_C(   440157138),  INT32_C(  2085497455),  INT32_C(   496614465), -INT32_C(  1898198120),
         INT32_C(   928956882), -INT32_C(  1702784872),  INT32_C(  1498482334),  INT32_C(  1976930630), -INT32_C(  1134913459),  INT32_C(    70822083), -INT32_C(    64892316),  INT32_C(  1871379613) },
      {  INT32_C(          17),  INT32_C(          16),  INT32_C(          12),  INT32_C(          13),  INT32_C(          18),  INT32_C(          18),  INT32_C(          15),  INT32_C(          18),
         INT32_C(          17),  INT32_C(          11),  INT32_C(          14),  INT32_C(          16),  INT32_C(          16),  INT32_C(          11),  INT32_C(          15),  INT32_C(          20) } },
    { {  INT32_C(  1437001917),  INT32_C(   401614713),  INT32_C(  1953513774),  INT32_C(   535381714), -INT32_C(  1579465762),  INT32_C(  1352995819), -INT32_C(  2108897563), -INT32_C(  2131634237),
         INT32_C(   953587647), -INT32_C(   313538881), -INT32_C(   647905273), -INT32_C(   453489914),  INT32_C(  2055656334), -INT32_C(   859165722), -INT32_C(  1253173518), -INT32_C(  1389018899) },
      {  INT32_C(          18),  INT32_C(          17),  INT32_C(          13),  INT32_C(          17),  INT32_C(          18),  INT32_C(          15),  INT32_C(          14),  INT32_C(          16),
         INT32_C(          20),  INT32_C(          22),  INT32_C(          13),  INT32_C(          15),  INT32_C(          17),  INT32_C(          17),  INT32_C(          17),  INT32_C(          16) } },
    { { -INT32_C(  1763374121), -INT32_C(   662489647), -INT32_C(    72227339), -INT32_C(  1092638416),  INT32_C(  1664640380), -INT32_C(  2094071151),  INT32_C(   104365337), -INT32_C(  1783403075),
         INT32_C(  1244371321), -INT32_C(  1021071410), -INT32_C(   994126700), -INT32_C(    92103298), -INT32_C(  1805796605), -INT32_C(   703099715), -INT32_C(   941797622),  INT32_C(   895258812) },
      {  INT32_C(          18),  INT32_C(          15),  INT32_C(          22),  INT32_C(          19),  INT32_C(          16),  INT32_C(          12),  INT32_C(          14),  INT32_C(          20),
         INT32_C(          16),  INT32_C(          18),  INT32_C(          16),  INT32_C(          19),  INT32_C(          16),  INT32_C(          18),  INT32_C(          18),  INT32_C(          15) } },
    { { -INT32_C(   142571479), -INT32_C(   876960969), -INT32_C(   175146889),  INT32_C(   435163414), -INT32_C(  1968353844), -INT32_C(   463420198), -INT32_C(   810861293), -INT32_C(   150665010),
        -INT32_C(   940604016), -INT32_C(  1617778392),  INT32_C(   949297442), -INT32_C(    11434702), -INT32_C(  1400242478), -INT32_C(   711923262), -INT32_C(   173786073), -INT32_C(   722687676) },
      {  INT32_C(          13),  INT32_C(          19),  INT32_C(          21),  INT32_C(          12),  INT32_C(          16),  INT32_C(          14),  INT32_C(          19),  INT32_C(          15),
         INT32_C(          17),  INT32_C(          15),  INT32_C(          11),  INT32_C(          17),  INT32_C(          18),  INT32_C(          15),  INT32_C(          17),  INT32_C(          15) } },
    { {  INT32_C(  1453054766), -INT32_C(  1477038715), -INT32_C(  2132833458), -INT32_C(   494981104), -INT32_C(   259061714),  INT32_C(   432349170), -INT32_C(  1626445477),  INT32_C(  1098119699),
         INT32_C(  1536691926), -INT32_C(  1996321221),  INT32_C(   688578841),  INT32_C(  1057720593), -INT32_C(  2077255022),  INT32_C(   362673338),  INT32_C(  1890954077),  INT32_C(  2075273381) },
      {  INT32_C(          19),  INT32_C(          18),  INT32_C(          16),  INT32_C(          14),  INT32_C(          14),  INT32_C(          17),  INT32_C(          18),  INT32_C(          16),
         INT32_C(          16),  INT32_C(          13),  INT32_C(          12),  INT32_C(          14),  INT32_C(          14),  INT32_C(          18),  INT32_C(          18),  INT32_C(          16) } },
    { {  INT32_C(  1926646327), -INT32_C(   235087656), -INT32_C(   904264007),  INT32_C(   554247567),  INT32_C(  2057648320), -INT32_C(  1970322900), -INT32_C(  1812314899), -INT32_C(  1542542227),
        -INT32_C(   837360138),  INT32_C(  2009010877), -INT32_C(  1472079592), -INT32_C(  1077326849), -INT32_C(  1338413181), -INT32_C(  1623537487),  INT32_C(  2050110477), -INT32_C(   685883167) },
      {  INT32_C(          17),  INT32_C(          19),  INT32_C(          14),  INT32_C(          12),  INT32_C(          14),  INT32_C(          13),  INT32_C(          18),  INT32_C(          15),
         INT32_C(          19),  INT32_C(          21),  INT32_C(          12),  INT32_C(          23),  INT32_C(          16),  INT32_C(          17),  INT32_C(          14),  INT32_C(          15) } },
    { { -INT32_C(   475646939),  INT32_C(  1599759687),  INT32_C(  1040685887),  INT32_C(  1795019238), -INT32_C(   249940416),  INT32_C(   194008318),  INT32_C(  1770373768),  INT32_C(   675390211),
         INT32_C(   520873944), -INT32_C(  1954650804), -INT32_C(   406223359), -INT32_C(  1756248489), -INT32_C(    74945540),  INT32_C(  1208359359), -INT32_C(   558789413),  INT32_C(   117961263) },
      {  INT32_C(          15),  INT32_C(          18),  INT32_C(          19),  INT32_C(          20),  INT32_C(          13),  INT32_C(          15),  INT32_C(          12),  INT32_C(          10),
         INT32_C(          18),  INT32_C(          17),  INT32_C(          14),  INT32_C(          17),  INT32_C(          20),  INT32_C(          14),  INT32_C(          19),  INT32_C(          16) } },
    { {  INT32_C(   640029401),  INT32_C(  2041685368), -INT32_C(  2107606229),  INT32_C(  1041871425), -INT32_C(   583425763), -INT32_C(  1775943750), -INT32_C(    76228917), -INT32_C(  1576895543),
         INT32_C(   113781134), -INT32_C(   109086002),  INT32_C(   914087925), -INT32_C(  1351314287), -INT32_C(   259216075), -INT32_C(  1199132179),  INT32_C(  1353972359),  INT32_C(    83080822) },
      {  INT32_C(          13),  INT32_C(          17),  INT32_C(          14),  INT32_C(          14),  INT32_C(          17),  INT32_C(          18),  INT32_C(          21),  INT32_C(          14),
         INT32_C(          12),  INT32_C(          23),  INT32_C(          23),  INT32_C(          16),  INT32_C(          16),  INT32_C(          17),  INT32_C(          17),  INT32_C(          17) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_popcnt_epi32(a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_popcnt_epi32(a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1733074867), -INT32_C(    78012492),  INT32_C(  1130961716), -INT32_C(   537833474),  INT32_C(   925914048),  INT32_C(  2042127766),  INT32_C(   202848032),  INT32_C(   105800889),
         INT32_C(  2040398276), -INT32_C(   713754719),  INT32_C(   286842387), -INT32_C(   286258899), -INT32_C(   232447652), -INT32_C(  1502814842), -INT32_C(   827096299), -INT32_C(  1395392024) },
      UINT16_C(29186),
      { -INT32_C(  1704287451), -INT32_C(  1871151752),  INT32_C(  2123998606), -INT32_C(  1197476205),  INT32_C(  1419126504),  INT32_C(  2144906188),  INT32_C(  1300283513), -INT32_C(  1832942740),
        -INT32_C(  1624495834),  INT32_C(   875537574), -INT32_C(   575420087), -INT32_C(  1483386177),  INT32_C(  1174154104),  INT32_C(  1338299606),  INT32_C(    10241428), -INT32_C(   292397880) },
      { -INT32_C(  1733074867),  INT32_C(          16),  INT32_C(  1130961716), -INT32_C(   537833474),  INT32_C(   925914048),  INT32_C(  2042127766),  INT32_C(   202848032),  INT32_C(   105800889),
         INT32_C(  2040398276),  INT32_C(          15),  INT32_C(   286842387), -INT32_C(   286258899),  INT32_C(          17),  INT32_C(          17),  INT32_C(          10), -INT32_C(  1395392024) } },
    { {  INT32_C(   747486853), -INT32_C(  1402946206),  INT32_C(  1166611334), -INT32_C(   554951066),  INT32_C(   539224138),  INT32_C(  1349576892), -INT32_C(   179237843), -INT32_C(   287055000),
         INT32_C(    68841890), -INT32_C(  1263502802), -INT32_C(   184993394), -INT32_C(  1563237032), -INT32_C(  1966934322),  INT32_C(   198914782), -INT32_C(  1493160897), -INT32_C(  1315577073) },
      UINT16_C(44884),
      {  INT32_C(  1714062006),  INT32_C(   799062070),  INT32_C(  2115369132),  INT32_C(  1551164314),  INT32_C(  1217352301),  INT32_C(  1567936093),  INT32_C(   188843125), -INT32_C(   340093643),
         INT32_C(  1314055192),  INT32_C(  1216279196), -INT32_C(  2067295254), -INT32_C(   471843978), -INT32_C(   349409394), -INT32_C(  1287020483),  INT32_C(  1522436644),  INT32_C(   927299615) },
      {  INT32_C(   747486853), -INT32_C(  1402946206),  INT32_C(          18), -INT32_C(   554951066),  INT32_C(          15),  INT32_C(  1349576892),  INT32_C(          12), -INT32_C(   287055000),
         INT32_C(          13),  INT32_C(          17),  INT32_C(          16),  INT32_C(          18), -INT32_C(  1966934322),  INT32_C(          15), -INT32_C(  1493160897),  INT32_C(          17) } },
    { { -INT32_C(   108619939),  INT32_C(  1933706377),  INT32_C(   234293655), -INT32_C(   755967932), -INT32_C(  2051138489), -INT32_C(   516421699), -INT32_C(  1338247535), -INT32_C(   873954962),
        -INT32_C(  1564119528),  INT32_C(   152373106),  INT32_C(  1410731280),  INT32_C(   740755173), -INT32_C(   525212381),  INT32_C(  2109860332),  INT32_C(  1311636959), -INT32_C(  1776740994) },
      UINT16_C(56963),
      {  INT32_C(  1323693368),  INT32_C(   341571070),  INT32_C(  1897611338),  INT32_C(   508968556), -INT32_C(   553172450), -INT32_C(   321067073),  INT32_C(  1308777013),  INT32_C(   690849265),
         INT32_C(  2037846651),  INT32_C(  1385091592),  INT32_C(  2143529234),  INT32_C(    94181863),  INT32_C(   451191899), -INT32_C(  1073299061),  INT32_C(   202311707),  INT32_C(   154549390) },
      {  INT32_C(          18),  INT32_C(          20),  INT32_C(   234293655), -INT32_C(   755967932), -INT32_C(  2051138489), -INT32_C(   516421699), -INT32_C(  1338247535),  INT32_C(          15),
        -INT32_C(  1564119528),  INT32_C(          12),  INT32_C(          17),  INT32_C(          16),  INT32_C(          15),  INT32_C(  2109860332),  INT32_C(          11),  INT32_C(          14) } },
    { {  INT32_C(  1451404622), -INT32_C(  1834479488), -INT32_C(  1609471047), -INT32_C(   542790012), -INT32_C(   554071469),  INT32_C(  1721696331), -INT32_C(  1770803704),  INT32_C(   949987818),
        -INT32_C(   695262634), -INT32_C(   328648910),  INT32_C(   663517859),  INT32_C(  2080846377),  INT32_C(   123338940),  INT32_C(   158202112), -INT32_C(  1851793241), -INT32_C(   523616375) },
      UINT16_C(22881),
      {  INT32_C(   529568694),  INT32_C(   211432319),  INT32_C(  1648280411), -INT32_C(  1721566657),  INT32_C(  1855152897),  INT32_C(   189741676), -INT32_C(  1773479732),  INT32_C(  1877978040),
        -INT32_C(  1097957569),  INT32_C(   248129715),  INT32_C(   711985387),  INT32_C(    63230466), -INT32_C(  1586342091),  INT32_C(  1571668369),  INT32_C(  1391720345), -INT32_C(   490610013) },
      {  INT32_C(          16), -INT32_C(  1834479488), -INT32_C(  1609471047), -INT32_C(   542790012), -INT32_C(   554071469),  INT32_C(          16),  INT32_C(          15),  INT32_C(   949987818),
         INT32_C(          23), -INT32_C(   328648910),  INT32_C(   663517859),  INT32_C(          10),  INT32_C(          16),  INT32_C(   158202112),  INT32_C(          20), -INT32_C(   523616375) } },
    { {  INT32_C(   362827618),  INT32_C(  1663265656),  INT32_C(  1989055347), -INT32_C(  1686547867),  INT32_C(   977071017),  INT32_C(  1184426412), -INT32_C(  2070377503), -INT32_C(   798598802),
         INT32_C(   551880360), -INT32_C(   444331919),  INT32_C(     5968539),  INT32_C(   228316260),  INT32_C(  1816647872), -INT32_C(  1565335615), -INT32_C(   651802005),  INT32_C(  1286180003) },
      UINT16_C(36499),
      { -INT32_C(   258603924),  INT32_C(  1140994537), -INT32_C(   853973455), -INT32_C(  1146758797), -INT32_C(   124099003),  INT32_C(   792855817), -INT32_C(  2017663266), -INT32_C(  1642770638),
         INT32_C(  1032825683),  INT32_C(   243372508),  INT32_C(  1809554168), -INT32_C(  1188659085), -INT32_C(   273563162), -INT32_C(  1524632634),  INT32_C(   187489241),  INT32_C(  2108310058) },
      {  INT32_C(          13),  INT32_C(          11),  INT32_C(  1989055347), -INT32_C(  1686547867),  INT32_C(          16),  INT32_C(  1184426412), -INT32_C(  2070377503),  INT32_C(          16),
         INT32_C(   551880360),  INT32_C(          13),  INT32_C(          20),  INT32_C(          14),  INT32_C(  1816647872), -INT32_C(  1565335615), -INT32_C(   651802005),  INT32_C(          15) } },
    { { -INT32_C(   893765139), -INT32_C(  1026016054),  INT32_C(  1244574678),  INT32_C(   419648563), -INT32_C(   603343851), -INT32_C(  2122241881),  INT32_C(   764194051), -INT32_C(   576047377),
         INT32_C(   984049007),  INT32_C(  2013036449),  INT32_C(  1707158066), -INT32_C(  1803631489),  INT32_C(   544245624), -INT32_C(  1298009681), -INT32_C(  1897976417), -INT32_C(   747926940) },
      UINT16_C( 4847),
      {  INT32_C(   177311757), -INT32_C(   919289081), -INT32_C(  1483885784), -INT32_C(  1204943288), -INT32_C(   945103322),  INT32_C(  1895057808),  INT32_C(  1140480215),  INT32_C(   961931564),
        -INT32_C(  2143033479), -INT32_C(   750159702),  INT32_C(  1937430315),  INT32_C(    53258461),  INT32_C(   399169158), -INT32_C(   158876129),  INT32_C(  1127842071), -INT32_C(   478376086) },
      {  INT32_C(          10),  INT32_C(          14),  INT32_C(          16),  INT32_C(          12), -INT32_C(   603343851),  INT32_C(          13),  INT32_C(          18),  INT32_C(          16),
         INT32_C(   984049007),  INT32_C(          16),  INT32_C(  1707158066), -INT32_C(  1803631489),  INT32_C(          16), -INT32_C(  1298009681), -INT32_C(  1897976417), -INT32_C(   747926940) } },
    { {  INT32_C(   543408246),  INT32_C(  1676913976),  INT32_C(  1641508228), -INT32_C(  1671167210), -INT32_C(   122474791),  INT32_C(    65944300),  INT32_C(   625354939),  INT32_C(   755549111),
        -INT32_C(  1152553853), -INT32_C(  1658961639), -INT32_C(   989923922), -INT32_C(   782146824),  INT32_C(  2093552784),  INT32_C(   176207951), -INT32_C(  1758411040),  INT32_C(   214186121) },
      UINT16_C( 4516),
      { -INT32_C(   430785081),  INT32_C(  1490747738),  INT32_C(   649778373),  INT32_C(  1866156709),  INT32_C(  1193773767), -INT32_C(  1005779052),  INT32_C(  1660786590),  INT32_C(  1802740131),
        -INT32_C(  1185823137), -INT32_C(  1944965945), -INT32_C(  1498166272), -INT32_C(   568988137),  INT32_C(   203766904), -INT32_C(   506383805),  INT32_C(  1833160393), -INT32_C(   824658321) },
      {  INT32_C(   543408246),  INT32_C(  1676913976),  INT32_C(          16), -INT32_C(  1671167210), -INT32_C(   122474791),  INT32_C(          12),  INT32_C(   625354939),  INT32_C(          17),
         INT32_C(          18), -INT32_C(  1658961639), -INT32_C(   989923922), -INT32_C(   782146824),  INT32_C(          13),  INT32_C(   176207951), -INT32_C(  1758411040),  INT32_C(   214186121) } },
    { {  INT32_C(  1132996988),  INT32_C(  1456511573),  INT32_C(  2113700710), -INT32_C(   379907727), -INT32_C(  1862959027),  INT32_C(  2087831219),  INT32_C(    82424980), -INT32_C(   405618326),
         INT32_C(  1076517610),  INT32_C(  1536621300), -INT32_C(   287796611), -INT32_C(   254331741),  INT32_C(  1736494516),  INT32_C(   686092691),  INT32_C(   254594469),  INT32_C(  2046230159) },
      UINT16_C( 8537),
      {  INT32_C(  1327189433), -INT32_C(  2115921496),  INT32_C(  1605731463), -INT32_C(   198416012), -INT32_C(  1243234351),  INT32_C(   327322343), -INT32_C(  1877864038),  INT32_C(  1152478091),
         INT32_C(  1637141944), -INT32_C(   303925914),  INT32_C(  1850513402), -INT32_C(   782010368),  INT32_C(   528894008),  INT32_C(  1832061395), -INT32_C(  1510128358),  INT32_C(  1760210864) },
      {  INT32_C(          18),  INT32_C(  1456511573),  INT32_C(  2113700710),  INT32_C(          16),  INT32_C(          21),  INT32_C(  2087831219),  INT32_C(          10), -INT32_C(   405618326),
         INT32_C(          15),  INT32_C(  1536621300), -INT32_C(   287796611), -INT32_C(   254331741),  INT32_C(  1736494516),  INT32_C(          16),  INT32_C(   254594469),  INT32_C(  2046230159) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_popcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_popcnt_epi32(src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_popcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(32380),
      { -INT32_C(  1410080055),  INT32_C(   474148303), -INT32_C(  1080802468), -INT32_C(  1693987820),  INT32_C(   530897644),  INT32_C(  1164230215),  INT32_C(  1324618852),  INT32_C(  1187803260),
         INT32_C(   569491282),  INT32_C(   155006125), -INT32_C(  1949773193), -INT32_C(  1977167970), -INT32_C(   240530774), -INT32_C(   315224695), -INT32_C(  1640289759), -INT32_C(   320600166) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(          17),  INT32_C(          14),  INT32_C(          18),  INT32_C(          16),  INT32_C(          14),  INT32_C(           0),
         INT32_C(           0),  INT32_C(          15),  INT32_C(          17),  INT32_C(          17),  INT32_C(          17),  INT32_C(          16),  INT32_C(          15),  INT32_C(           0) } },
    { UINT16_C(54726),
      {  INT32_C(  1258910478),  INT32_C(  1142784124),  INT32_C(   840219660), -INT32_C(   251806138), -INT32_C(   419592529), -INT32_C(  1374675085), -INT32_C(  1581929539), -INT32_C(  1518961769),
         INT32_C(  1810989295),  INT32_C(   212864512),  INT32_C(   289391818),  INT32_C(   822164610),  INT32_C(   890764994), -INT32_C(   622647267),  INT32_C(  1786484947),  INT32_C(    34664979) },
      {  INT32_C(           0),  INT32_C(          12),  INT32_C(          12),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          19),  INT32_C(          20),
         INT32_C(          18),  INT32_C(           0),  INT32_C(          15),  INT32_C(           0),  INT32_C(          18),  INT32_C(           0),  INT32_C(          18),  INT32_C(          10) } },
    { UINT16_C(  370),
      {  INT32_C(   504328814), -INT32_C(  1092429185), -INT32_C(   319134485), -INT32_C(  1377125227), -INT32_C(   724236047),  INT32_C(  1584179426),  INT32_C(   575700754), -INT32_C(   266091902),
        -INT32_C(  1290915020), -INT32_C(   126750707), -INT32_C(   370906284),  INT32_C(   412536359), -INT32_C(  1175688234),  INT32_C(   639064083),  INT32_C(  1514694616),  INT32_C(  1565158441) },
      {  INT32_C(           0),  INT32_C(          22),  INT32_C(           0),  INT32_C(           0),  INT32_C(          15),  INT32_C(          16),  INT32_C(          13),  INT32_C(           0),
         INT32_C(          15),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(22687),
      { -INT32_C(  2109166575), -INT32_C(  1997628252),  INT32_C(   475403653),  INT32_C(   445066542), -INT32_C(    42755098),  INT32_C(   157567937), -INT32_C(   277508699), -INT32_C(    79227670),
         INT32_C(  1686015936), -INT32_C(  1326683093), -INT32_C(  1345567871),  INT32_C(  1456100464), -INT32_C(  1336721937),  INT32_C(   767145864),  INT32_C(   773599044),  INT32_C(    69886787) },
      {  INT32_C(          10),  INT32_C(          15),  INT32_C(          13),  INT32_C(          15),  INT32_C(          22),  INT32_C(           0),  INT32_C(           0),  INT32_C(          18),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          14),  INT32_C(          19),  INT32_C(           0),  INT32_C(          14),  INT32_C(           0) } },
    { UINT16_C(43250),
      {  INT32_C(  1427381608), -INT32_C(  1701276211),  INT32_C(   267257925), -INT32_C(  1320362658),  INT32_C(  1181275277),  INT32_C(   494251009),  INT32_C(    75545050),  INT32_C(   632058557),
         INT32_C(  1551548559), -INT32_C(  1678372266),  INT32_C(  2024465434),  INT32_C(  1311372993), -INT32_C(   879390262),  INT32_C(   417860157), -INT32_C(  2145621821),  INT32_C(  1772538330) },
      {  INT32_C(           0),  INT32_C(          16),  INT32_C(           0),  INT32_C(           0),  INT32_C(          14),  INT32_C(          14),  INT32_C(          12),  INT32_C(          17),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          16),  INT32_C(           0),  INT32_C(          13),  INT32_C(           0),  INT32_C(          17) } },
    { UINT16_C( 8329),
      { -INT32_C(  1137451067),  INT32_C(   614485370), -INT32_C(   283483450),  INT32_C(  1166140592), -INT32_C(  1756315985), -INT32_C(   201387050),  INT32_C(   985454996),  INT32_C(   140133698),
        -INT32_C(  1614508763), -INT32_C(  1580964645),  INT32_C(  2005982918),  INT32_C(  1924927939), -INT32_C(  1509290800), -INT32_C(  1265039072),  INT32_C(   636376547), -INT32_C(  1070774117) },
      {  INT32_C(          20),  INT32_C(           0),  INT32_C(           0),  INT32_C(          12),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          10),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          11),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(61910),
      {  INT32_C(   592884063), -INT32_C(   503178158),  INT32_C(  1358218643),  INT32_C(  1096598583),  INT32_C(    72055914),  INT32_C(   509161008), -INT32_C(  2123893677),  INT32_C(   343031220),
         INT32_C(  1077397742),  INT32_C(  2015508965),  INT32_C(   919082750),  INT32_C(  1165436378), -INT32_C(   766917983),  INT32_C(  1156621040),  INT32_C(  1271224215), -INT32_C(  2107689068) },
      {  INT32_C(           0),  INT32_C(          11),  INT32_C(          15),  INT32_C(           0),  INT32_C(          14),  INT32_C(           0),  INT32_C(          16),  INT32_C(          15),
         INT32_C(          15),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          13),  INT32_C(          13),  INT32_C(          18),  INT32_C(          16) } },
    { UINT16_C(38656),
      { -INT32_C(   439294526),  INT32_C(   654036829),  INT32_C(  2085344773),  INT32_C(  1681910811), -INT32_C(  1358549058),  INT32_C(   939957619),  INT32_C(  1215339497), -INT32_C(   522227683),
        -INT32_C(  1295667115), -INT32_C(  2066169729), -INT32_C(  1325390954), -INT32_C(   837468400), -INT32_C(   495117201), -INT32_C(  1575254855),  INT32_C(  1022069535),  INT32_C(  1344064251) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(          15),  INT32_C(          15),  INT32_C(          11),  INT32_C(           0),  INT32_C(          19),  INT32_C(           0),  INT32_C(           0),  INT32_C(          16) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_popcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_maskz_popcnt_epi32(k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 3073294659356376031), -INT64_C( 1537462820203847320),  INT64_C( 7865643292054664579),  INT64_C( 8202657540467514459),
        -INT64_C( 3401127664895991956), -INT64_C( 8753745316382364187),  INT64_C( 1944462947203309480), -INT64_C( 2882936618288956678) },
      {  INT64_C(                  34),  INT64_C(                  33),  INT64_C(                  29),  INT64_C(                  36),
         INT64_C(                  31),  INT64_C(                  29),  INT64_C(                  39),  INT64_C(                  40) } },
    { { -INT64_C( 4262579123589145697), -INT64_C( 4684619826757459341),  INT64_C(  800595171150262850),  INT64_C( 7441518647381067523),
         INT64_C( 8670914746795409329), -INT64_C( 2828564482170571799),  INT64_C( 6339650270139124702), -INT64_C( 2797568623294180611) },
      {  INT64_C(                  35),  INT64_C(                  38),  INT64_C(                  23),  INT64_C(                  28),
         INT64_C(                  33),  INT64_C(                  45),  INT64_C(                  41),  INT64_C(                  31) } },
    { { -INT64_C( 3726800280995914551), -INT64_C(    8573849791875470), -INT64_C( 5890451362257388651), -INT64_C( 2775166181828196997),
         INT64_C( 1651957552028051005), -INT64_C( 2934939297517684700), -INT64_C( 7486671304171440965),  INT64_C( 7849413712912616965) },
      {  INT64_C(                  36),  INT64_C(                  30),  INT64_C(                  36),  INT64_C(                  33),
         INT64_C(                  33),  INT64_C(                  25),  INT64_C(                  25),  INT64_C(                  32) } },
    { { -INT64_C( 6315883393434479202),  INT64_C( 3696105611150129201),  INT64_C( 1305404029951478888), -INT64_C( 5700408059274766008),
         INT64_C( 2006157827222237610),  INT64_C( 7021635157590263237),  INT64_C( 1370506935620997607), -INT64_C( 1432021255157240739) },
      {  INT64_C(                  29),  INT64_C(                  32),  INT64_C(                  27),  INT64_C(                  26),
         INT64_C(                  37),  INT64_C(                  37),  INT64_C(                  30),  INT64_C(                  29) } },
    { {  INT64_C( 2803193216111350753),  INT64_C( 4040526362533197495),  INT64_C( 6540688995199482086), -INT64_C( 6806089398316609443),
         INT64_C( 5657457466480043517), -INT64_C( 6678256893049247799),  INT64_C(  891460585958767881),  INT64_C( 1138344257487841642) },
      {  INT64_C(                  30),  INT64_C(                  30),  INT64_C(                  35),  INT64_C(                  31),
         INT64_C(                  36),  INT64_C(                  34),  INT64_C(                  30),  INT64_C(                  30) } },
    { {  INT64_C( 6179203174758169051), -INT64_C( 2866328065511800872),  INT64_C( 1367191753343274302), -INT64_C( 5366028122070342554),
        -INT64_C( 4745693504319457982), -INT64_C( 7903945630411418969), -INT64_C( 3327464770486981351),  INT64_C( 6605605386928656156) },
      {  INT64_C(                  32),  INT64_C(                  37),  INT64_C(                  39),  INT64_C(                  31),
         INT64_C(                  33),  INT64_C(                  34),  INT64_C(                  33),  INT64_C(                  34) } },
    { {  INT64_C( 7164186580010849224),  INT64_C( 7261256476685680608), -INT64_C( 2840373074880871337),  INT64_C( 8825782795924069894),
        -INT64_C( 3283803686514940595), -INT64_C( 3962099558296172716),  INT64_C( 2712608571996710928),  INT64_C( 4263150649363231742) },
      {  INT64_C(                  33),  INT64_C(                  33),  INT64_C(                  31),  INT64_C(                  38),
         INT64_C(                  30),  INT64_C(                  30),  INT64_C(                  28),  INT64_C(                  37) } },
    { {  INT64_C( 4263415604419252837),  INT64_C(  807233929640358137), -INT64_C( 2572824369040933114), -INT64_C( 5397083319491063568),
         INT64_C(  588342143371468039), -INT64_C( 1554402800833526426), -INT64_C( 5539327751270480539),  INT64_C( 7633507227987455210) },
      {  INT64_C(                  32),  INT64_C(                  38),  INT64_C(                  37),  INT64_C(                  30),
         INT64_C(                  28),  INT64_C(                  32),  INT64_C(                  27),  INT64_C(                  34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_popcnt_epi64(a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_popcnt_epi64(a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 4070651131221696890),  INT64_C( 3233021294986034942), -INT64_C(  182630123339556325), -INT64_C( 6413031115145452875),
        -INT64_C( 2588972897580023240),  INT64_C( 1695262196422605980),  INT64_C( 8430286324001183010), -INT64_C( 4135671636426475322) },
      UINT8_C( 39),
      { -INT64_C( 5766893736910610372),  INT64_C( 7905158576588149195), -INT64_C( 1451670139380648529), -INT64_C( 6624442757530661435),
        -INT64_C( 4520498062044490272),  INT64_C( 7028721200252841543),  INT64_C( 2187428190064261309), -INT64_C(  781065484466858980) },
      {  INT64_C(                  32),  INT64_C(                  35),  INT64_C(                  36), -INT64_C( 6413031115145452875),
        -INT64_C( 2588972897580023240),  INT64_C(                  30),  INT64_C( 8430286324001183010), -INT64_C( 4135671636426475322) } },
    { {  INT64_C( 7342779572813309999), -INT64_C(   86677519175829062), -INT64_C( 6107222428106210873), -INT64_C( 8095403533333936226),
        -INT64_C( 5403023247430897535),  INT64_C( 6707246973916907476), -INT64_C( 1555505158480362962),  INT64_C( 8355097541546383619) },
      UINT8_C(116),
      { -INT64_C( 7055410988695219545), -INT64_C( 4439825482494235834),  INT64_C( 2580272907230781455), -INT64_C( 3725451996110179692),
         INT64_C( 2832804717389593755),  INT64_C( 2761194851635201104), -INT64_C( 1402378327327416356), -INT64_C( 4331599557000126734) },
      {  INT64_C( 7342779572813309999), -INT64_C(   86677519175829062),  INT64_C(                  29), -INT64_C( 8095403533333936226),
         INT64_C(                  29),  INT64_C(                  27),  INT64_C(                  35),  INT64_C( 8355097541546383619) } },
    { {  INT64_C( 7410045463114937037), -INT64_C( 3997428538680135863),  INT64_C( 3020427951220881319), -INT64_C( 8268568506698518698),
        -INT64_C( 4282060703785044714),  INT64_C( 8643721395884558655),  INT64_C( 3495462751712977441), -INT64_C(  190014404867276017) },
      UINT8_C(163),
      {  INT64_C( 5037244008122689943),  INT64_C( 3013344685551129094),  INT64_C( 8102876974369942019),  INT64_C( 3995348864769410016),
         INT64_C( 8682875700998213757),  INT64_C( 2740432830724609496),  INT64_C( 2180303236085975588),  INT64_C( 7572625669925673025) },
      {  INT64_C(                  35),  INT64_C(                  23),  INT64_C( 3020427951220881319), -INT64_C( 8268568506698518698),
        -INT64_C( 4282060703785044714),  INT64_C(                  31),  INT64_C( 3495462751712977441),  INT64_C(                  31) } },
    { { -INT64_C( 7793439867477428498),  INT64_C( 2162424889421725880), -INT64_C( 3756230191686382460),  INT64_C( 1809817213460073672),
        -INT64_C( 7203416462802173511),  INT64_C( 8676882821756254802),  INT64_C( 5862588893567211782), -INT64_C( 8851785708264421147) },
      UINT8_C(228),
      {  INT64_C( 9027012471265229474),  INT64_C( 6295445128420103132),  INT64_C( 5990124273809813027), -INT64_C(  342655817962541001),
         INT64_C( 5124873637382260383), -INT64_C( 7125262530693393976),  INT64_C( 7459924913426136553), -INT64_C( 1621577020775226069) },
      { -INT64_C( 7793439867477428498),  INT64_C( 2162424889421725880),  INT64_C(                  28),  INT64_C( 1809817213460073672),
        -INT64_C( 7203416462802173511),  INT64_C(                  36),  INT64_C(                  40),  INT64_C(                  28) } },
    { {  INT64_C( 7834480645749042694),  INT64_C( 4274847687967397691),  INT64_C( 5972887080763534668), -INT64_C( 6067098956295920486),
         INT64_C( 4527196261029009603), -INT64_C( 6865376629205236436), -INT64_C( 5192651342696667019), -INT64_C( 2381444212045593180) },
      UINT8_C(194),
      {  INT64_C( 2094740182149711120),  INT64_C( 8265532801226477816),  INT64_C(  491532550809801006),  INT64_C( 2165948907683650274),
        -INT64_C( 3568234269333269691),  INT64_C( 3270391779141020838),  INT64_C( 1899161383545336085), -INT64_C( 4507130724710187961) },
      {  INT64_C( 7834480645749042694),  INT64_C(                  26),  INT64_C( 5972887080763534668), -INT64_C( 6067098956295920486),
         INT64_C( 4527196261029009603), -INT64_C( 6865376629205236436),  INT64_C(                  34),  INT64_C(                  34) } },
    { {  INT64_C( 3669476623463118663), -INT64_C( 3192624707033433466), -INT64_C( 9095155539198342027), -INT64_C( 1712130225886319360),
         INT64_C( 8899378899545578689), -INT64_C( 7170380247789952276),  INT64_C( 3060213719226754494),  INT64_C( 6541166858318794557) },
      UINT8_C( 64),
      { -INT64_C( 3843346022747756596),  INT64_C( 8511959221882934193), -INT64_C( 2367264404914890537), -INT64_C( 7596214905024806032),
         INT64_C( 3128873069273401722), -INT64_C( 4496933382297592752),  INT64_C( 8085875582344640198), -INT64_C(  346398382643433519) },
      {  INT64_C( 3669476623463118663), -INT64_C( 3192624707033433466), -INT64_C( 9095155539198342027), -INT64_C( 1712130225886319360),
         INT64_C( 8899378899545578689), -INT64_C( 7170380247789952276),  INT64_C(                  28),  INT64_C( 6541166858318794557) } },
    { { -INT64_C( 3258626452607892447), -INT64_C( 3886454727294888603),  INT64_C( 6282618815954139328),  INT64_C( 7963528852719989767),
        -INT64_C( 8143685526457015897),  INT64_C( 4104447735805898279),  INT64_C( 8539714875897223078),  INT64_C( 4600570610500662558) },
      UINT8_C(163),
      {  INT64_C( 5898408620765047010),  INT64_C( 1354460865642432057), -INT64_C( 1134072047878407941),  INT64_C( 7502091554870832630),
         INT64_C( 9071928898322491696), -INT64_C( 6049617764759064579),  INT64_C( 8851002104162061417),  INT64_C( 6245663811482836416) },
      {  INT64_C(                  34),  INT64_C(                  27),  INT64_C( 6282618815954139328),  INT64_C( 7963528852719989767),
        -INT64_C( 8143685526457015897),  INT64_C(                  35),  INT64_C( 8539714875897223078),  INT64_C(                  30) } },
    { { -INT64_C( 4775557505287009801),  INT64_C( 4025023783293574526),  INT64_C( 9172689772707818573),  INT64_C( 4956618537583263310),
         INT64_C(  124193703769191227),  INT64_C( 9123180347141484439), -INT64_C(  651161948249933896),  INT64_C( 7523600921493355481) },
      UINT8_C(230),
      { -INT64_C( 8234151191506230039),  INT64_C( 8241935569752301468), -INT64_C( 8431001495530710901),  INT64_C( 8688322803788096890),
         INT64_C(  301553607950204292), -INT64_C( 5358987611049497228),  INT64_C( 5062006178458615014), -INT64_C( 7420094809383897600) },
      { -INT64_C( 4775557505287009801),  INT64_C(                  35),  INT64_C(                  32),  INT64_C( 4956618537583263310),
         INT64_C(  124193703769191227),  INT64_C(                  33),  INT64_C(                  40),  INT64_C(                  29) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_popcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_popcnt_epi64(src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_popcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(132),
      {  INT64_C( 6371168969363831713), -INT64_C(  607925220291733092),  INT64_C( 8857747608148591890),  INT64_C( 2596370825725574397),
        -INT64_C( 9139908225974733724), -INT64_C(  914024147818141154),  INT64_C( 2017276313582244864),  INT64_C( 2013576011498687818) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  30),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  31) } },
    { UINT8_C(157),
      { -INT64_C( 4850655994897634805),  INT64_C( 7919739760071739437), -INT64_C(  537152755261019022),  INT64_C( 6092465715316414534),
         INT64_C( 4432549258039987636),  INT64_C( 2549616496530038940), -INT64_C( 2675719180805411461),  INT64_C(  712788467021089863) },
      {  INT64_C(                  26),  INT64_C(                   0),  INT64_C(                  30),  INT64_C(                  31),
         INT64_C(                  28),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  27) } },
    { UINT8_C( 99),
      {  INT64_C( 8357185930636021961),  INT64_C( 4566729543022669782), -INT64_C( 5772860304374151764),  INT64_C( 2319369578360369783),
         INT64_C( 3072713144481522654), -INT64_C( 4685591811097376409), -INT64_C(  971022171355034444),  INT64_C( 8585813180150680495) },
      {  INT64_C(                  35),  INT64_C(                  33),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                  38),  INT64_C(                  35),  INT64_C(                   0) } },
    { UINT8_C(146),
      {  INT64_C( 1622438585336965284),  INT64_C(  235003252547534110),  INT64_C( 3110984177696971072), -INT64_C(  166849411546861010),
        -INT64_C( 4375918134430165533), -INT64_C( 7776429766796612133),  INT64_C( 3492327111829590700),  INT64_C( 6468855126396058479) },
      {  INT64_C(                   0),  INT64_C(                  28),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                  32),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  38) } },
    { UINT8_C(146),
      {  INT64_C( 4276161036454103262),  INT64_C( 1119184630391466058), -INT64_C( 8727342435093392331),  INT64_C( 5628749046861310606),
        -INT64_C( 7500990036867132450), -INT64_C( 3452575796551256183), -INT64_C(  819049962225326384), -INT64_C( 3274507306183712816) },
      {  INT64_C(                   0),  INT64_C(                  30),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                  35),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  34) } },
    { UINT8_C(240),
      { -INT64_C( 2521219304788230568),  INT64_C( 4905625188931471687),  INT64_C( 8179275600547754124), -INT64_C( 6292874134927523297),
         INT64_C(  358639510690588855),  INT64_C( 5084664834986308141), -INT64_C(  446001660259976309),  INT64_C( 2681436656102618429) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                  30),  INT64_C(                  31),  INT64_C(                  42),  INT64_C(                  32) } },
    { UINT8_C( 73),
      { -INT64_C( 5861143284662582696), -INT64_C( 4667788029406415791), -INT64_C( 7250633337484962137),  INT64_C( 9003309340056743496),
         INT64_C( 5934232487583086448),  INT64_C( 1862861255283229334),  INT64_C( 5822480348469753036),  INT64_C( 8370761262769493641) },
      {  INT64_C(                  27),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  30),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  31),  INT64_C(                   0) } },
    { UINT8_C(226),
      {  INT64_C( 4348847191585136675), -INT64_C( 4379812968688356044),  INT64_C(  875697474441472258),  INT64_C( 2585492800884757779),
         INT64_C( 3340055715676406948), -INT64_C( 3257844367350036297), -INT64_C( 4505121701797784776), -INT64_C( 5579782854969095571) },
      {  INT64_C(                   0),  INT64_C(                  36),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                  32),  INT64_C(                  33),  INT64_C(                  27) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_popcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_popcnt_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_popcnt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_popcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_popcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_popcnt_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
