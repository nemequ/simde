/* Copyright (c) 2017, 2019 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "test/test.h"
#define SIMDE_TESTS_CURRENT_ISAX sse2
#include <simde/x86/sse2.h>
#include <test/x86/test-sse2.h>

#if defined(HEDLEY_MSVC_VERSION)
#  pragma warning(disable:4324)
#endif

static int
test_simde_x_mm_abs_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   147.28), SIMDE_FLOAT64_C(   704.65) },
      { SIMDE_FLOAT64_C(   147.28), SIMDE_FLOAT64_C(   704.65) } },
    { { SIMDE_FLOAT64_C(   136.85), SIMDE_FLOAT64_C(  -756.74) },
      { SIMDE_FLOAT64_C(   136.85), SIMDE_FLOAT64_C(   756.74) } },
    { { SIMDE_FLOAT64_C(   178.63), SIMDE_FLOAT64_C(  -900.20) },
      { SIMDE_FLOAT64_C(   178.63), SIMDE_FLOAT64_C(   900.20) } },
    { { SIMDE_FLOAT64_C(  -651.54), SIMDE_FLOAT64_C(  -517.72) },
      { SIMDE_FLOAT64_C(   651.54), SIMDE_FLOAT64_C(   517.72) } },
    { { SIMDE_FLOAT64_C(    75.39), SIMDE_FLOAT64_C(  -705.91) },
      { SIMDE_FLOAT64_C(    75.39), SIMDE_FLOAT64_C(   705.91) } },
    { { SIMDE_FLOAT64_C(  -738.47), SIMDE_FLOAT64_C(  -668.92) },
      { SIMDE_FLOAT64_C(   738.47), SIMDE_FLOAT64_C(   668.92) } },
    { { SIMDE_FLOAT64_C(   212.72), SIMDE_FLOAT64_C(  -499.79) },
      { SIMDE_FLOAT64_C(   212.72), SIMDE_FLOAT64_C(   499.79) } },
    { { SIMDE_FLOAT64_C(   481.67), SIMDE_FLOAT64_C(   233.48) },
      { SIMDE_FLOAT64_C(   481.67), SIMDE_FLOAT64_C(   233.48) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d r = simde_x_mm_abs_pd(a);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  90),  INT8_C( 118), -INT8_C(  35), -INT8_C(  66),  INT8_C(  97),  INT8_C(  96),  INT8_C(  20), -INT8_C( 105),
         INT8_C(  78), -INT8_C(  32),  INT8_C( 110), -INT8_C(  33), -INT8_C(  12),  INT8_C(   9),  INT8_C( 119), -INT8_C(  73) },
      { -INT8_C( 117), -INT8_C( 121),  INT8_C( 108), -INT8_C( 124), -INT8_C(  90),  INT8_C( 100), -INT8_C( 121), -INT8_C( 115),
         INT8_C(  60),  INT8_C( 124),  INT8_C(  32), -INT8_C(  86),  INT8_C( 118), -INT8_C(  20), -INT8_C( 123), -INT8_C(  48) },
      { -INT8_C(  27), -INT8_C(   3),  INT8_C(  73),  INT8_C(  66),  INT8_C(   7), -INT8_C(  60), -INT8_C( 101),  INT8_C(  36),
        -INT8_C( 118),  INT8_C(  92), -INT8_C( 114), -INT8_C( 119),  INT8_C( 106), -INT8_C(  11), -INT8_C(   4), -INT8_C( 121) } },
    { {  INT8_C(  99),  INT8_C(  98), -INT8_C( 113), -INT8_C(  60), -INT8_C(  62), -INT8_C(  93),  INT8_C(  92),  INT8_C(  16),
        -INT8_C( 125), -INT8_C(  54), -INT8_C(  16),  INT8_C( 119), -INT8_C(  45),  INT8_C( 103),  INT8_C(  47),  INT8_C(  95) },
      { -INT8_C(  18), -INT8_C( 101), -INT8_C(  29), -INT8_C( 108), -INT8_C(   1),  INT8_C( 106),  INT8_C(  34),  INT8_C(  59),
        -INT8_C(  26),  INT8_C(  66), -INT8_C(  27),  INT8_C(  92),  INT8_C(  47),  INT8_C( 107),  INT8_C(  44), -INT8_C( 110) },
      {  INT8_C(  81), -INT8_C(   3),  INT8_C( 114),  INT8_C(  88), -INT8_C(  63),  INT8_C(  13),  INT8_C( 126),  INT8_C(  75),
         INT8_C( 105),  INT8_C(  12), -INT8_C(  43), -INT8_C(  45),  INT8_C(   2), -INT8_C(  46),  INT8_C(  91), -INT8_C(  15) } },
    { { -INT8_C(  51), -INT8_C(  69),  INT8_C(  86), -INT8_C( 112),  INT8_C(  94), -INT8_C(  78), -INT8_C(  96), -INT8_C(  31),
         INT8_C( 125), -INT8_C( 112),  INT8_C(  89),  INT8_C(  80), -INT8_C(   9), -INT8_C( 120), -INT8_C(  81), -INT8_C(  27) },
      {  INT8_C(  35), -INT8_C( 110),  INT8_C( 122),  INT8_C(  34), -INT8_C(   4), -INT8_C( 100),  INT8_C(  94), -INT8_C(  30),
        -INT8_C(  34),  INT8_C(  67),  INT8_C(  62),  INT8_C(  13), -INT8_C(  82),  INT8_C( 107), -INT8_C(  97),  INT8_C( 124) },
      { -INT8_C(  16),  INT8_C(  77), -INT8_C(  48), -INT8_C(  78),  INT8_C(  90),  INT8_C(  78), -INT8_C(   2), -INT8_C(  61),
         INT8_C(  91), -INT8_C(  45), -INT8_C( 105),  INT8_C(  93), -INT8_C(  91), -INT8_C(  13),  INT8_C(  78),  INT8_C(  97) } },
    { {  INT8_C(  38), -INT8_C(  10),  INT8_C(  12), -INT8_C( 123), -INT8_C(  88), -INT8_C(  84),  INT8_C( 102),  INT8_C(  37),
         INT8_C(  61), -INT8_C(  65),  INT8_C( 118),  INT8_C(  52),  INT8_C(  71),  INT8_C(  37),  INT8_C(  26),  INT8_C( 106) },
      { -INT8_C(  72), -INT8_C( 108), -INT8_C( 115), -INT8_C(  76),  INT8_C(  48), -INT8_C(  21), -INT8_C( 105),  INT8_C(  14),
         INT8_C(  46), -INT8_C(  43),  INT8_C(  28), -INT8_C(  35),  INT8_C(  64), -INT8_C(  69),  INT8_C(  89),  INT8_C( 103) },
      { -INT8_C(  34), -INT8_C( 118), -INT8_C( 103),  INT8_C(  57), -INT8_C(  40), -INT8_C( 105), -INT8_C(   3),  INT8_C(  51),
         INT8_C( 107), -INT8_C( 108), -INT8_C( 110),  INT8_C(  17), -INT8_C( 121), -INT8_C(  32),  INT8_C( 115), -INT8_C(  47) } },
    { { -INT8_C(  79),  INT8_C( 101), -INT8_C(  20),  INT8_C(  90),  INT8_C(  17),  INT8_C(  82),      INT8_MAX,  INT8_C(  78),
         INT8_C(  18), -INT8_C(  11), -INT8_C( 125),  INT8_C(  89),  INT8_C(  27), -INT8_C(  99), -INT8_C(  60), -INT8_C(  45) },
      {  INT8_C(  49),  INT8_C(  81), -INT8_C( 121),  INT8_C(  97),  INT8_C(  60),  INT8_C(  30),  INT8_C( 111),  INT8_C( 106),
        -INT8_C(  12), -INT8_C( 117),  INT8_C(  71),  INT8_C(  52),  INT8_C(  71), -INT8_C(  96), -INT8_C( 101), -INT8_C(   8) },
      { -INT8_C(  30), -INT8_C(  74),  INT8_C( 115), -INT8_C(  69),  INT8_C(  77),  INT8_C( 112), -INT8_C(  18), -INT8_C(  72),
         INT8_C(   6),      INT8_MIN, -INT8_C(  54), -INT8_C( 115),  INT8_C(  98),  INT8_C(  61),  INT8_C(  95), -INT8_C(  53) } },
    { {  INT8_C(   5), -INT8_C( 121),  INT8_C(  82),  INT8_C(  23), -INT8_C(  38), -INT8_C(  46),  INT8_C( 101), -INT8_C(  20),
        -INT8_C(  57), -INT8_C(  24),  INT8_C(  69), -INT8_C(  30), -INT8_C( 123),  INT8_C(   9), -INT8_C(  75), -INT8_C(  74) },
      {  INT8_C(  90),  INT8_C(  61),  INT8_C(  23), -INT8_C( 106),  INT8_C(  91), -INT8_C( 121),  INT8_C(   1),  INT8_C(  79),
         INT8_C(  18),  INT8_C(  72), -INT8_C( 124),  INT8_C(  89), -INT8_C(  23),  INT8_C(  31),  INT8_C(  82), -INT8_C(  18) },
      {  INT8_C(  95), -INT8_C(  60),  INT8_C( 105), -INT8_C(  83),  INT8_C(  53),  INT8_C(  89),  INT8_C( 102),  INT8_C(  59),
        -INT8_C(  39),  INT8_C(  48), -INT8_C(  55),  INT8_C(  59),  INT8_C( 110),  INT8_C(  40),  INT8_C(   7), -INT8_C(  92) } },
    { { -INT8_C(  89), -INT8_C(  92),  INT8_C(   5), -INT8_C( 127),  INT8_C( 118),  INT8_C( 107),  INT8_C( 109),  INT8_C(  62),
         INT8_C(  83), -INT8_C(  78),  INT8_C(  32), -INT8_C(  39), -INT8_C(  68), -INT8_C(  42), -INT8_C( 113),  INT8_C(  22) },
      {  INT8_C(  19), -INT8_C(  89), -INT8_C(  83),  INT8_C( 110),  INT8_C(  46), -INT8_C(  82), -INT8_C(  66),  INT8_C(  64),
        -INT8_C(  10),  INT8_C(  66), -INT8_C( 102), -INT8_C(  33),  INT8_C(  97), -INT8_C(  20), -INT8_C(  50),  INT8_C(   8) },
      { -INT8_C(  70),  INT8_C(  75), -INT8_C(  78), -INT8_C(  17), -INT8_C(  92),  INT8_C(  25),  INT8_C(  43),  INT8_C( 126),
         INT8_C(  73), -INT8_C(  12), -INT8_C(  70), -INT8_C(  72),  INT8_C(  29), -INT8_C(  62),  INT8_C(  93),  INT8_C(  30) } },
    { { -INT8_C( 112), -INT8_C(  45), -INT8_C( 119),  INT8_C(   7),  INT8_C(  62), -INT8_C(  10),  INT8_C(  69), -INT8_C( 110),
        -INT8_C(  87),  INT8_C( 101),  INT8_C( 107),  INT8_C( 101),  INT8_C(  59), -INT8_C(   6),  INT8_C( 123),  INT8_C(  78) },
      { -INT8_C(  95),  INT8_C(  40), -INT8_C(  67), -INT8_C(  49), -INT8_C(  42),  INT8_C( 123),  INT8_C(  16), -INT8_C(  51),
        -INT8_C(  67), -INT8_C(  86), -INT8_C(  84),  INT8_C(  30), -INT8_C( 106),  INT8_C( 122),  INT8_C(  39),  INT8_C(  38) },
      {  INT8_C(  49), -INT8_C(   5),  INT8_C(  70), -INT8_C(  42),  INT8_C(  20),  INT8_C( 113),  INT8_C(  85),  INT8_C(  95),
         INT8_C( 102),  INT8_C(  15),  INT8_C(  23), -INT8_C( 125), -INT8_C(  47),  INT8_C( 116), -INT8_C(  94),  INT8_C( 116) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_add_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  4111), -INT16_C( 19283),  INT16_C( 32346),  INT16_C( 31529),  INT16_C( 28909), -INT16_C( 11812),  INT16_C( 20575),  INT16_C( 29075) },
      { -INT16_C( 31999),  INT16_C( 11862),  INT16_C(  4324), -INT16_C( 23595),  INT16_C( 24767), -INT16_C( 10354), -INT16_C( 11824), -INT16_C( 16113) },
      {  INT16_C( 29426), -INT16_C(  7421), -INT16_C( 28866),  INT16_C(  7934), -INT16_C( 11860), -INT16_C( 22166),  INT16_C(  8751),  INT16_C( 12962) } },
    { { -INT16_C( 17215),  INT16_C(  7029), -INT16_C( 24774),  INT16_C( 10134),  INT16_C( 29199),  INT16_C( 28409), -INT16_C( 29502), -INT16_C( 15137) },
      {  INT16_C( 13584), -INT16_C(  2830), -INT16_C( 14522),  INT16_C(  1431),  INT16_C(  9512), -INT16_C(  1828), -INT16_C(  5129), -INT16_C( 18247) },
      { -INT16_C(  3631),  INT16_C(  4199),  INT16_C( 26240),  INT16_C( 11565), -INT16_C( 26825),  INT16_C( 26581),  INT16_C( 30905),  INT16_C( 32152) } },
    { {  INT16_C( 11944), -INT16_C(  7469),  INT16_C( 27085), -INT16_C(  9206),  INT16_C(   987), -INT16_C( 25013),  INT16_C( 10895), -INT16_C( 24734) },
      {  INT16_C( 21600), -INT16_C( 22892),  INT16_C( 11036),  INT16_C( 17579), -INT16_C( 30895),  INT16_C( 18492), -INT16_C(  2701),  INT16_C(  6912) },
      { -INT16_C( 31992), -INT16_C( 30361), -INT16_C( 27415),  INT16_C(  8373), -INT16_C( 29908), -INT16_C(  6521),  INT16_C(  8194), -INT16_C( 17822) } },
    { { -INT16_C( 11485), -INT16_C(  3587),  INT16_C(  1852),  INT16_C(  6093),  INT16_C(  6154), -INT16_C( 25931),  INT16_C(  5955), -INT16_C( 23751) },
      { -INT16_C( 12948), -INT16_C( 30647), -INT16_C(  2823),  INT16_C( 19148),  INT16_C(  2171), -INT16_C(  4462), -INT16_C( 27907),  INT16_C(  8201) },
      { -INT16_C( 24433),  INT16_C( 31302), -INT16_C(   971),  INT16_C( 25241),  INT16_C(  8325), -INT16_C( 30393), -INT16_C( 21952), -INT16_C( 15550) } },
    { {  INT16_C(  1893), -INT16_C( 24303), -INT16_C(  8434),  INT16_C(  6584),  INT16_C( 28407),  INT16_C( 15027), -INT16_C(  4987), -INT16_C(  3619) },
      {  INT16_C(  9914), -INT16_C( 19591),  INT16_C( 17690), -INT16_C( 26883), -INT16_C( 28851),  INT16_C( 19076), -INT16_C( 29151), -INT16_C( 31125) },
      {  INT16_C( 11807),  INT16_C( 21642),  INT16_C(  9256), -INT16_C( 20299), -INT16_C(   444), -INT16_C( 31433),  INT16_C( 31398),  INT16_C( 30792) } },
    { {  INT16_C( 31893), -INT16_C( 23769), -INT16_C(  8357),  INT16_C( 21436),  INT16_C( 28493), -INT16_C( 11379),  INT16_C( 27484),  INT16_C(  5828) },
      {  INT16_C( 16017), -INT16_C( 21303), -INT16_C( 14717), -INT16_C( 11966), -INT16_C( 14763),  INT16_C( 30235), -INT16_C( 31148), -INT16_C(  5636) },
      { -INT16_C( 17626),  INT16_C( 20464), -INT16_C( 23074),  INT16_C(  9470),  INT16_C( 13730),  INT16_C( 18856), -INT16_C(  3664),  INT16_C(   192) } },
    { {  INT16_C(  8963),  INT16_C( 24205),  INT16_C( 18690),  INT16_C( 20657),  INT16_C( 16313),  INT16_C(  5411), -INT16_C(  6230),  INT16_C( 15147) },
      { -INT16_C(  3035), -INT16_C( 22041),  INT16_C( 10682),  INT16_C(  3962), -INT16_C( 27152),  INT16_C( 17541), -INT16_C( 32484),  INT16_C(  7982) },
      {  INT16_C(  5928),  INT16_C(  2164),  INT16_C( 29372),  INT16_C( 24619), -INT16_C( 10839),  INT16_C( 22952),  INT16_C( 26822),  INT16_C( 23129) } },
    { { -INT16_C( 17500), -INT16_C( 22915),  INT16_C( 12036), -INT16_C( 16906),  INT16_C(  6510),  INT16_C(  6354), -INT16_C(   767),  INT16_C(  9811) },
      {  INT16_C( 15345), -INT16_C( 21553),  INT16_C( 18788),  INT16_C( 21690),  INT16_C( 16351), -INT16_C(  1127), -INT16_C( 14400),  INT16_C( 25626) },
      { -INT16_C(  2155),  INT16_C( 21068),  INT16_C( 30824),  INT16_C(  4784),  INT16_C( 22861),  INT16_C(  5227), -INT16_C( 15167), -INT16_C( 30099) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_add_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1587156417),  INT32_C(  1768270179), -INT32_C(  1942404587),  INT32_C(   346970517) },
      {  INT32_C(  2141391970),  INT32_C(  1584534422),  INT32_C(  1144809083), -INT32_C(   446909148) },
      { -INT32_C(   566418909), -INT32_C(   942162695), -INT32_C(   797595504), -INT32_C(    99938631) } },
    { {  INT32_C(   776206027), -INT32_C(  1265129313),  INT32_C(  2134954218), -INT32_C(  1953239511) },
      { -INT32_C(  1861535750), -INT32_C(   974160566),  INT32_C(   134884324), -INT32_C(  1393727775) },
      { -INT32_C(  1085329723),  INT32_C(  2055677417), -INT32_C(  2025128754),  INT32_C(   948000010) } },
    { { -INT32_C(    69586852), -INT32_C(  1011912232),  INT32_C(  1782771777), -INT32_C(   638134562) },
      {  INT32_C(  1466564877),  INT32_C(  1646090622),  INT32_C(  1718232965), -INT32_C(   384673907) },
      {  INT32_C(  1396978025),  INT32_C(   634178390), -INT32_C(   793962554), -INT32_C(  1022808469) } },
    { {  INT32_C(  1625615495), -INT32_C(  1641835683),  INT32_C(  1644717443),  INT32_C(  1211891259) },
      {  INT32_C(  2124457471), -INT32_C(  2082423298),  INT32_C(  1911114724),  INT32_C(   710605730) },
      { -INT32_C(   544894330),  INT32_C(   570708315), -INT32_C(   739135129),  INT32_C(  1922496989) } },
    { {  INT32_C(  1149910759),  INT32_C(  1440918993),  INT32_C(  1320676114), -INT32_C(   375983383) },
      { -INT32_C(  1788397929), -INT32_C(   686209037),  INT32_C(   893911698), -INT32_C(   446717186) },
      { -INT32_C(   638487170),  INT32_C(   754709956), -INT32_C(  2080379484), -INT32_C(   822700569) } },
    { { -INT32_C(  1305810464), -INT32_C(  1475933034), -INT32_C(   503922953),  INT32_C(  1204456880) },
      { -INT32_C(  1210306109),  INT32_C(   193918328), -INT32_C(   163522568),  INT32_C(  1524342649) },
      {  INT32_C(  1778850723), -INT32_C(  1282014706), -INT32_C(   667445521), -INT32_C(  1566167767) } },
    { {  INT32_C(   504104328),  INT32_C(   163975954), -INT32_C(  2115322415),  INT32_C(   231257162) },
      {  INT32_C(  1589945573), -INT32_C(  1838591078), -INT32_C(  1551324886), -INT32_C(   788700344) },
      {  INT32_C(  2094049901), -INT32_C(  1674615124),  INT32_C(   628319995), -INT32_C(   557443182) } },
    { {  INT32_C(  2079197545), -INT32_C(   310070244), -INT32_C(  1150390415),  INT32_C(   164181539) },
      {  INT32_C(  1969720795),  INT32_C(   168284384), -INT32_C(  1045524615),  INT32_C(  1536273394) },
      { -INT32_C(   246048956), -INT32_C(   141785860),  INT32_C(  2099052266),  INT32_C(  1700454933) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_add_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6468439616558299793),  INT64_C( 2325632228821341991) },
      { -INT64_C(  612652056685655455), -INT64_C(  191691543793121214) },
      { -INT64_C( 7081091673243955248),  INT64_C( 2133940685028220777) } },
    { { -INT64_C(  894566178211475330),  INT64_C( 6756798005412736627) },
      { -INT64_C( 3896691714656888127),  INT64_C( 2845879868330258419) },
      { -INT64_C( 4791257892868363457), -INT64_C( 8844066199966556570) } },
    { {  INT64_C( 7901755739001462504),  INT64_C( 1347655258826955098) },
      {  INT64_C( 8953142355952099055),  INT64_C(  248677757309780642) },
      { -INT64_C( 1591845978755990057),  INT64_C( 1596333016136735740) } },
    { { -INT64_C( 8141839393087780454), -INT64_C( 2946030458831039558) },
      { -INT64_C( 4972663281470790409),  INT64_C( 1165720327465335311) },
      {  INT64_C( 5332241399150980753), -INT64_C( 1780310131365704247) } },
    { { -INT64_C(   15861257455999742),  INT64_C( 4357558393977351353) },
      {  INT64_C( 7214407425212598092), -INT64_C( 7045112387664469068) },
      {  INT64_C( 7198546167756598350), -INT64_C( 2687553993687117715) } },
    { {  INT64_C( 4532200698918854304),  INT64_C( 7262715306804571977) },
      { -INT64_C(  803639368974039520), -INT64_C( 4520672699422448119) },
      {  INT64_C( 3728561329944814784),  INT64_C( 2742042607382123858) } },
    { { -INT64_C(   73591731732932298),  INT64_C( 6050399403914353275) },
      { -INT64_C( 5903761005476331555), -INT64_C( 4762108524214604026) },
      { -INT64_C( 5977352737209263853),  INT64_C( 1288290879699749249) } },
    { { -INT64_C( 7465715716457918288),  INT64_C( 2653502295939739981) },
      {  INT64_C( 4698470722568297185), -INT64_C( 3402942170898265983) },
      { -INT64_C( 2767244993889621103), -INT64_C(  749439874958526002) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_add_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_add_pd (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   755.33), SIMDE_FLOAT64_C(   721.25) },
      { SIMDE_FLOAT64_C(   781.60), SIMDE_FLOAT64_C(  -779.68) },
      { SIMDE_FLOAT64_C(  1536.93), SIMDE_FLOAT64_C(   -58.44) } },
    { { SIMDE_FLOAT64_C(  -566.45), SIMDE_FLOAT64_C(  -614.54) },
      { SIMDE_FLOAT64_C(   194.36), SIMDE_FLOAT64_C(  -334.34) },
      { SIMDE_FLOAT64_C(  -372.09), SIMDE_FLOAT64_C(  -948.88) } },
    { { SIMDE_FLOAT64_C(   813.61), SIMDE_FLOAT64_C(  -315.29) },
      { SIMDE_FLOAT64_C(   361.18), SIMDE_FLOAT64_C(   614.31) },
      { SIMDE_FLOAT64_C(  1174.78), SIMDE_FLOAT64_C(   299.02) } },
    { { SIMDE_FLOAT64_C(   824.96), SIMDE_FLOAT64_C(  -193.54) },
      { SIMDE_FLOAT64_C(   701.59), SIMDE_FLOAT64_C(  -521.55) },
      { SIMDE_FLOAT64_C(  1526.55), SIMDE_FLOAT64_C(  -715.09) } },
    { { SIMDE_FLOAT64_C(  -703.59), SIMDE_FLOAT64_C(   322.49) },
      { SIMDE_FLOAT64_C(   -26.00), SIMDE_FLOAT64_C(   910.61) },
      { SIMDE_FLOAT64_C(  -729.59), SIMDE_FLOAT64_C(  1233.10) } },
    { { SIMDE_FLOAT64_C(  -720.23), SIMDE_FLOAT64_C(   197.82) },
      { SIMDE_FLOAT64_C(  -770.39), SIMDE_FLOAT64_C(  -888.99) },
      { SIMDE_FLOAT64_C( -1490.62), SIMDE_FLOAT64_C(  -691.16) } },
    { { SIMDE_FLOAT64_C(   238.41), SIMDE_FLOAT64_C(  -248.68) },
      { SIMDE_FLOAT64_C(  -805.44), SIMDE_FLOAT64_C(   805.25) },
      { SIMDE_FLOAT64_C(  -567.03), SIMDE_FLOAT64_C(   556.57) } },
    { { SIMDE_FLOAT64_C(    13.85), SIMDE_FLOAT64_C(  -859.57) },
      { SIMDE_FLOAT64_C(   840.09), SIMDE_FLOAT64_C(  -230.82) },
      { SIMDE_FLOAT64_C(   853.93), SIMDE_FLOAT64_C( -1090.39) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_add_pd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_add_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -348.09), SIMDE_FLOAT64_C( -603.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.81), SIMDE_FLOAT64_C( -955.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -348.09), SIMDE_FLOAT64_C(-1559.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  600.30), SIMDE_FLOAT64_C(  362.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -245.13), SIMDE_FLOAT64_C( -144.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  600.30), SIMDE_FLOAT64_C(  218.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -909.82), SIMDE_FLOAT64_C(  -28.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -141.49), SIMDE_FLOAT64_C(  174.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -909.82), SIMDE_FLOAT64_C(  145.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -402.79), SIMDE_FLOAT64_C( -225.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -114.28), SIMDE_FLOAT64_C(  118.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -402.79), SIMDE_FLOAT64_C( -106.95)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  476.58), SIMDE_FLOAT64_C(  189.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  158.24), SIMDE_FLOAT64_C(  133.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  476.58), SIMDE_FLOAT64_C(  322.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -902.16), SIMDE_FLOAT64_C( -720.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -496.01), SIMDE_FLOAT64_C(  563.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -902.16), SIMDE_FLOAT64_C( -156.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   32.48), SIMDE_FLOAT64_C( -172.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  435.61), SIMDE_FLOAT64_C(  209.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   32.48), SIMDE_FLOAT64_C(   36.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  322.78), SIMDE_FLOAT64_C( -415.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.82), SIMDE_FLOAT64_C( -195.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  322.78), SIMDE_FLOAT64_C( -610.71)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_add_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_add_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  793111073070173174)),
      simde_mm_cvtsi64_m64(INT64_C( 2108668061446341817)),
      simde_mm_cvtsi64_m64(INT64_C( 2901779134516514991)), },
    { simde_mm_cvtsi64_m64(INT64_C( 8875506276833571865)),
      simde_mm_cvtsi64_m64(INT64_C(-8625831155966083456)),
      simde_mm_cvtsi64_m64(INT64_C(  249675120867488409)), },
    { simde_mm_cvtsi64_m64(INT64_C( 2916092148231541839)),
      simde_mm_cvtsi64_m64(INT64_C( 7640479428881902755)),
      simde_mm_cvtsi64_m64(INT64_C(-7890172496596107022)), },
    { simde_mm_cvtsi64_m64(INT64_C(-3448012693901819300)),
      simde_mm_cvtsi64_m64(INT64_C(-9198379985559078668)),
      simde_mm_cvtsi64_m64(INT64_C( 5800351394248653648)), },
    { simde_mm_cvtsi64_m64(INT64_C( 3628113225825158935)),
      simde_mm_cvtsi64_m64(INT64_C(-1333669735654572042)),
      simde_mm_cvtsi64_m64(INT64_C( 2294443490170586893)), },
    { simde_mm_cvtsi64_m64(INT64_C( 5048798289215441413)),
      simde_mm_cvtsi64_m64(INT64_C( -388036903570542302)),
      simde_mm_cvtsi64_m64(INT64_C( 4660761385644899111)), },
    { simde_mm_cvtsi64_m64(INT64_C( 6446512717337269554)),
      simde_mm_cvtsi64_m64(INT64_C(-7669829270527021775)),
      simde_mm_cvtsi64_m64(INT64_C(-1223316553189752221)), },
    { simde_mm_cvtsi64_m64(INT64_C( 6296531259101832881)),
      simde_mm_cvtsi64_m64(INT64_C( 5834912758815977701)),
      simde_mm_cvtsi64_m64(INT64_C(-6315300055791741034)), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_add_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_adds_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( 100), INT8_C(  33), INT8_C(  67), INT8_C(  67), INT8_C( 104), INT8_C(-123), INT8_C( -86), INT8_C(  74),
                        INT8_C( -93), INT8_C(  -4), INT8_C( -12), INT8_C(  28), INT8_C(   9), INT8_C(  39), INT8_C(  83), INT8_C( -52)),
      simde_mm_set_epi8(INT8_C(  40), INT8_C( -64), INT8_C( -19), INT8_C( -17), INT8_C(  67), INT8_C( -93), INT8_C( -22), INT8_C(  98),
                        INT8_C( -73), INT8_C( -83), INT8_C( 107), INT8_C(  95), INT8_C(  59), INT8_C(  84), INT8_C( -72), INT8_C(-115)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( -31), INT8_C(  48), INT8_C(  50), INT8_C( 127), INT8_C(-128), INT8_C(-108), INT8_C( 127),
                        INT8_C(-128), INT8_C( -87), INT8_C(  95), INT8_C( 123), INT8_C(  68), INT8_C( 123), INT8_C(  11), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C(  76), INT8_C( 121), INT8_C(  98), INT8_C(  52), INT8_C(  50), INT8_C( -16), INT8_C(  53), INT8_C(   3),
                        INT8_C( -57), INT8_C( -76), INT8_C( -42), INT8_C(  70), INT8_C(-122), INT8_C(  71), INT8_C( -56), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C( 100), INT8_C( 124), INT8_C(  99), INT8_C(  11), INT8_C(  -8), INT8_C(   5), INT8_C(   6), INT8_C( -54),
                        INT8_C(  42), INT8_C( -99), INT8_C(  23), INT8_C(-128), INT8_C(  77), INT8_C(  14), INT8_C(  94), INT8_C(  53)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(  63), INT8_C(  42), INT8_C( -11), INT8_C(  59), INT8_C( -51),
                        INT8_C( -15), INT8_C(-128), INT8_C( -19), INT8_C( -58), INT8_C( -45), INT8_C(  85), INT8_C(  38), INT8_C(  38)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C(  29), INT8_C(  30), INT8_C(  13), INT8_C(  51), INT8_C(  11), INT8_C( -27), INT8_C( -12),
                        INT8_C(  97), INT8_C(  87), INT8_C(  67), INT8_C(  70), INT8_C(   2), INT8_C( -40), INT8_C(  49), INT8_C( 116)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C( -17), INT8_C( -77), INT8_C( 126), INT8_C(-125), INT8_C( -42), INT8_C(  45), INT8_C( -79),
                        INT8_C( -23), INT8_C( 110), INT8_C( 117), INT8_C( -44), INT8_C( -92), INT8_C( -20), INT8_C(-121), INT8_C( 102)),
      simde_mm_set_epi8(INT8_C(  29), INT8_C(  12), INT8_C( -47), INT8_C( 127), INT8_C( -74), INT8_C( -31), INT8_C(  18), INT8_C( -91),
                        INT8_C(  74), INT8_C( 127), INT8_C( 127), INT8_C(  26), INT8_C( -90), INT8_C( -60), INT8_C( -72), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C(  55), INT8_C(-106), INT8_C( -49), INT8_C( -49), INT8_C( -85), INT8_C( -58), INT8_C( -56), INT8_C( -25),
                        INT8_C(  78), INT8_C(  18), INT8_C(  71), INT8_C( -12), INT8_C(  86), INT8_C( -84), INT8_C( -77), INT8_C(-116)),
      simde_mm_set_epi8(INT8_C(-103), INT8_C( 107), INT8_C(  33), INT8_C( -17), INT8_C( 106), INT8_C(   4), INT8_C( -98), INT8_C(-128),
                        INT8_C(  53), INT8_C(   4), INT8_C( 120), INT8_C( -44), INT8_C( -99), INT8_C( 120), INT8_C( -27), INT8_C(  45)),
      simde_mm_set_epi8(INT8_C( -48), INT8_C(   1), INT8_C( -16), INT8_C( -66), INT8_C(  21), INT8_C( -54), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C(  22), INT8_C( 127), INT8_C( -56), INT8_C( -13), INT8_C(  36), INT8_C(-104), INT8_C( -71)) },
    { simde_mm_set_epi8(INT8_C(  47), INT8_C(  15), INT8_C( 126), INT8_C(-115), INT8_C( -77), INT8_C( -27), INT8_C( -38), INT8_C(  32),
                        INT8_C( -21), INT8_C( -80), INT8_C( 112), INT8_C(  75), INT8_C( -15), INT8_C( -92), INT8_C(  43), INT8_C( -22)),
      simde_mm_set_epi8(INT8_C( -33), INT8_C( 127), INT8_C( 123), INT8_C(  65), INT8_C(  63), INT8_C(  85), INT8_C(  75), INT8_C(  99),
                        INT8_C(  -2), INT8_C(  13), INT8_C( -46), INT8_C(  -8), INT8_C( 127), INT8_C(-115), INT8_C(-109), INT8_C(  14)),
      simde_mm_set_epi8(INT8_C(  14), INT8_C( 127), INT8_C( 127), INT8_C( -50), INT8_C( -14), INT8_C(  58), INT8_C(  37), INT8_C( 127),
                        INT8_C( -23), INT8_C( -67), INT8_C(  66), INT8_C(  67), INT8_C( 112), INT8_C(-128), INT8_C( -66), INT8_C(  -8)) },
    { simde_mm_set_epi8(INT8_C(  18), INT8_C(  75), INT8_C(  10), INT8_C(  29), INT8_C(  27), INT8_C( 101), INT8_C(  -1), INT8_C(  78),
                        INT8_C( -78), INT8_C( 110), INT8_C(  18), INT8_C(  82), INT8_C( -41), INT8_C(  85), INT8_C(-113), INT8_C( 126)),
      simde_mm_set_epi8(INT8_C( -90), INT8_C(  80), INT8_C(-103), INT8_C(-111), INT8_C(  86), INT8_C(  65), INT8_C(  89), INT8_C(  88),
                        INT8_C( -83), INT8_C(-121), INT8_C(  -2), INT8_C(  40), INT8_C( -96), INT8_C( -36), INT8_C(  64), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C( -72), INT8_C( 127), INT8_C( -93), INT8_C( -82), INT8_C( 113), INT8_C( 127), INT8_C(  88), INT8_C( 127),
                        INT8_C(-128), INT8_C( -11), INT8_C(  16), INT8_C( 122), INT8_C(-128), INT8_C(  49), INT8_C( -49), INT8_C( 111)) },
    { simde_mm_set_epi8(INT8_C( -90), INT8_C(  48), INT8_C( -43), INT8_C(  22), INT8_C(  78), INT8_C( -17), INT8_C( -78), INT8_C( -64),
                        INT8_C( -97), INT8_C( -80), INT8_C( -51), INT8_C(  72), INT8_C( 114), INT8_C( -11), INT8_C( -89), INT8_C( -93)),
      simde_mm_set_epi8(INT8_C(   8), INT8_C(  57), INT8_C(  66), INT8_C(-119), INT8_C(  79), INT8_C( -29), INT8_C( -49), INT8_C(  26),
                        INT8_C( -12), INT8_C( -99), INT8_C(-101), INT8_C( 121), INT8_C(-112), INT8_C(  -5), INT8_C( -19), INT8_C( -27)),
      simde_mm_set_epi8(INT8_C( -82), INT8_C( 105), INT8_C(  23), INT8_C( -97), INT8_C( 127), INT8_C( -46), INT8_C(-127), INT8_C( -38),
                        INT8_C(-109), INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(   2), INT8_C( -16), INT8_C(-108), INT8_C(-120)) },
    { simde_mm_set_epi8(INT8_C(  26), INT8_C( -15), INT8_C(  12), INT8_C( -66), INT8_C(  -7), INT8_C(-115), INT8_C( -21), INT8_C(  27),
                        INT8_C( 111), INT8_C(-126), INT8_C( -43), INT8_C( -94), INT8_C( -97), INT8_C( -34), INT8_C( -47), INT8_C( -79)),
      simde_mm_set_epi8(INT8_C(-124), INT8_C( -47), INT8_C(-123), INT8_C(-115), INT8_C( -15), INT8_C( -87), INT8_C(-121), INT8_C( -50),
                        INT8_C( 103), INT8_C(  85), INT8_C(  34), INT8_C( -85), INT8_C(-124), INT8_C(  70), INT8_C(  14), INT8_C( -44)),
      simde_mm_set_epi8(INT8_C( -98), INT8_C( -62), INT8_C(-111), INT8_C(-128), INT8_C( -22), INT8_C(-128), INT8_C(-128), INT8_C( -23),
                        INT8_C( 127), INT8_C( -41), INT8_C(  -9), INT8_C(-128), INT8_C(-128), INT8_C(  36), INT8_C( -33), INT8_C(-123)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_adds_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( -9187), INT16_C( 11150), INT16_C(-25711), INT16_C( 30917),
                         INT16_C(  5637), INT16_C( 27391), INT16_C( 20667), INT16_C(-25552)),
      simde_mm_set_epi16(INT16_C( 15244), INT16_C(-26000), INT16_C(-24422), INT16_C(-28473),
                         INT16_C( -7393), INT16_C( 32134), INT16_C(  -161), INT16_C( -2948)),
      simde_mm_set_epi16(INT16_C(  6057), INT16_C(-14850), INT16_C(-32768), INT16_C(  2444),
                         INT16_C( -1756), INT16_C( 32767), INT16_C( 20506), INT16_C(-28500)) },
    { simde_mm_set_epi16(INT16_C(-27976), INT16_C(  8581), INT16_C( 17714), INT16_C(-15964),
                         INT16_C(-24791), INT16_C( 29014), INT16_C( -8950), INT16_C(-19859)),
      simde_mm_set_epi16(INT16_C(-20491), INT16_C(-23795), INT16_C(  5770), INT16_C(-28365),
                         INT16_C( -4266), INT16_C(-14588), INT16_C( 21498), INT16_C( 13063)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(-15214), INT16_C( 23484), INT16_C(-32768),
                         INT16_C(-29057), INT16_C( 14426), INT16_C( 12548), INT16_C( -6796)) },
    { simde_mm_set_epi16(INT16_C(-24285), INT16_C(-16974), INT16_C( 21513), INT16_C( 30869),
                         INT16_C(-30698), INT16_C(  2555), INT16_C(-20742), INT16_C(-26329)),
      simde_mm_set_epi16(INT16_C( 19660), INT16_C(-27596), INT16_C( 16650), INT16_C( 30694),
                         INT16_C( 14408), INT16_C(  7632), INT16_C( 15232), INT16_C( -7024)),
      simde_mm_set_epi16(INT16_C( -4625), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                         INT16_C(-16290), INT16_C( 10187), INT16_C( -5510), INT16_C(-32768)) },
    { simde_mm_set_epi16(INT16_C( -6143), INT16_C(  5190), INT16_C(  -240), INT16_C(-14301),
                         INT16_C( 12856), INT16_C( 32740), INT16_C(-13308), INT16_C( 31639)),
      simde_mm_set_epi16(INT16_C( 21047), INT16_C(-20544), INT16_C(-28076), INT16_C(-30442),
                         INT16_C( 28180), INT16_C(-18015), INT16_C( 12870), INT16_C( 12342)),
      simde_mm_set_epi16(INT16_C( 14904), INT16_C(-15354), INT16_C(-28316), INT16_C(-32768),
                         INT16_C( 32767), INT16_C( 14725), INT16_C(  -438), INT16_C( 32767)) },
    { simde_mm_set_epi16(INT16_C( 21004), INT16_C( 26590), INT16_C(  -387), INT16_C(  5458),
                         INT16_C( 28558), INT16_C( -1691), INT16_C( 13843), INT16_C( -2265)),
      simde_mm_set_epi16(INT16_C( 24548), INT16_C(-19288), INT16_C(  1056), INT16_C(  5037),
                         INT16_C(  9790), INT16_C( 12391), INT16_C( -2983), INT16_C(  8158)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(  7302), INT16_C(   669), INT16_C( 10495),
                         INT16_C( 32767), INT16_C( 10700), INT16_C( 10860), INT16_C(  5893)) },
    { simde_mm_set_epi16(INT16_C( 23035), INT16_C( 14493), INT16_C( 11060), INT16_C(-15265),
                         INT16_C(-25751), INT16_C(-17380), INT16_C(-20209), INT16_C(-22539)),
      simde_mm_set_epi16(INT16_C(-10338), INT16_C( 26220), INT16_C( -6324), INT16_C( 16083),
                         INT16_C(-20758), INT16_C( 28594), INT16_C(-27719), INT16_C(-21423)),
      simde_mm_set_epi16(INT16_C( 12697), INT16_C( 32767), INT16_C(  4736), INT16_C(   818),
                         INT16_C(-32768), INT16_C( 11214), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi16(INT16_C(  1437), INT16_C( -1148), INT16_C( -7704), INT16_C( -3845),
                         INT16_C(  5523), INT16_C( 32157), INT16_C( -3057), INT16_C( -2194)),
      simde_mm_set_epi16(INT16_C( 20255), INT16_C( 16313), INT16_C( 26265), INT16_C( -5377),
                         INT16_C( 31904), INT16_C(  3795), INT16_C( 20716), INT16_C(-30035)),
      simde_mm_set_epi16(INT16_C( 21692), INT16_C( 15165), INT16_C( 18561), INT16_C( -9222),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 17659), INT16_C(-32229)) },
    { simde_mm_set_epi16(INT16_C(   856), INT16_C( 13772), INT16_C(-17603), INT16_C(-26424),
                         INT16_C(  9957), INT16_C(-11801), INT16_C(  3067), INT16_C(-26950)),
      simde_mm_set_epi16(INT16_C(-26495), INT16_C(-22337), INT16_C(-30714), INT16_C( 24988),
                         INT16_C(-24287), INT16_C( 11170), INT16_C(-20015), INT16_C( 26834)),
      simde_mm_set_epi16(INT16_C(-25639), INT16_C( -8565), INT16_C(-32768), INT16_C( -1436),
                         INT16_C(-14330), INT16_C(  -631), INT16_C(-16948), INT16_C(  -116)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_adds_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(243, 185, 175,  84, 114, 173, 219, 130,
                           80,  12,   6, 121,  58, 223,  94, 203),
      simde_x_mm_set_epu8( 46, 142,  32,  64, 239,  92, 213, 158,
                           92,  20,  62, 216,   2, 162,   3, 226),
      simde_x_mm_set_epu8(255, 255, 207, 148, 255, 255, 255, 255,
                          172,  32,  68, 255,  60, 255,  97, 255) },
    { simde_x_mm_set_epu8(200, 115,  63, 101, 233, 139, 164, 230,
                            4, 147,   7, 233, 110, 206, 178, 233),
      simde_x_mm_set_epu8( 87,  74,  19, 102, 136, 119, 164, 198,
                          113, 170, 154,   7, 191, 195, 220, 182),
      simde_x_mm_set_epu8(255, 189,  82, 203, 255, 255, 255, 255,
                          117, 255, 161, 240, 255, 255, 255, 255) },
    { simde_x_mm_set_epu8( 35,  38, 142, 165, 104,  97, 151,   1,
                           79,  16, 160, 140,  19, 109, 210, 120),
      simde_x_mm_set_epu8(  2, 202, 138, 112, 199, 233, 201,  65,
                          233,  49, 101, 216,  62,  35, 235, 214),
      simde_x_mm_set_epu8( 37, 240, 255, 255, 255, 255, 255,  66,
                          255,  65, 255, 255,  81, 144, 255, 255) },
    { simde_x_mm_set_epu8( 98,  74, 253, 101, 187,  74, 205,  52,
                          154, 226, 198, 148, 241, 174, 125,  62),
      simde_x_mm_set_epu8(163, 110,   1, 166, 233, 185, 220, 101,
                          190,  92, 121, 253, 238,  73,  61,  34),
      simde_x_mm_set_epu8(255, 184, 254, 255, 255, 255, 255, 153,
                          255, 255, 255, 255, 255, 247, 186,  96) },
    { simde_x_mm_set_epu8( 91,  28,  52,  18, 175,  61,  49,  67,
                           76,  39, 238, 247, 137,  91, 133,   4),
      simde_x_mm_set_epu8(142, 255, 123,  14,  70,  48,  62, 186,
                          134,  31, 154,  34,   3,  30,  40, 184),
      simde_x_mm_set_epu8(233, 255, 175,  32, 245, 109, 111, 253,
                          210,  70, 255, 255, 140, 121, 173, 188) },
    { simde_x_mm_set_epu8( 32, 230,  94,  17, 123, 186,  43,  67,
                           13,  45, 219, 214, 133,  19,  25, 150),
      simde_x_mm_set_epu8(114,  27, 244, 244,  84,   0, 108, 198,
                          239, 228, 225, 158,   4,  27,  84, 116),
      simde_x_mm_set_epu8(146, 255, 255, 255, 207, 186, 151, 255,
                          252, 255, 255, 255, 137,  46, 109, 255) },
    { simde_x_mm_set_epu8( 66, 152,   8,  32,   7, 222,  46,  10,
                          116, 185,  69, 186, 194, 134,  55, 214),
      simde_x_mm_set_epu8(185,  11, 114, 201, 179, 122,  77, 244,
                          221, 175, 219,  12, 207, 104,  91, 252),
      simde_x_mm_set_epu8(251, 163, 122, 233, 186, 255, 123, 254,
                          255, 255, 255, 198, 255, 238, 146, 255) },
    { simde_x_mm_set_epu8(149,  71,  22, 119,  62,  37, 103,  26,
                          193,  60, 234, 165,  97, 233, 187,  76),
      simde_x_mm_set_epu8(169,   9, 188,  18, 251, 187,  96, 167,
                          158, 238, 176, 160,  74,  18, 253, 103),
      simde_x_mm_set_epu8(255,  80, 210, 137, 255, 224, 199, 193,
                          255, 255, 255, 255, 171, 251, 255, 179) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_adds_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(52397,  2628, 46614, 35162, 54536, 36456, 24004, 11160),
      simde_x_mm_set_epu16(41921, 12035, 29903, 58497,  1695, 15558, 14248, 61659),
      simde_x_mm_set_epu16(65535, 14663, 65535, 65535, 56231, 52014, 38252, 65535) },
    { simde_x_mm_set_epu16(57345,  6650,  8556, 25986, 61163, 19076, 40550, 40920),
      simde_x_mm_set_epu16(62607, 15369, 35325, 28241, 54252,  5722, 23748, 36984),
      simde_x_mm_set_epu16(65535, 22019, 43881, 54227, 65535, 24798, 64298, 65535) },
    { simde_x_mm_set_epu16(19370, 64323,  5781, 65431, 30915, 24348, 65190, 30074),
      simde_x_mm_set_epu16(34245, 57703, 60540, 40683, 24154, 18750, 32124, 33828),
      simde_x_mm_set_epu16(53615, 65535, 65535, 65535, 55069, 43098, 65535, 63902) },
    { simde_x_mm_set_epu16( 1083, 62410, 53296,    45, 57969, 54778, 42038, 36216),
      simde_x_mm_set_epu16(47446, 36131, 44258, 13796, 53696, 55457, 27279, 19924),
      simde_x_mm_set_epu16(48529, 65535, 65535, 13841, 65535, 65535, 65535, 56140) },
    { simde_x_mm_set_epu16(53022, 40173, 23284, 53830, 27939, 30100, 61471,   602),
      simde_x_mm_set_epu16(42952, 36449, 22644,  6670,   537,  5689,    73,  2247),
      simde_x_mm_set_epu16(65535, 65535, 45928, 60500, 28476, 35789, 61544,  2849) },
    { simde_x_mm_set_epu16( 8441, 24815, 22801, 35056, 30653,  5655, 39135, 32848),
      simde_x_mm_set_epu16( 7115, 32196, 31449, 51212, 54481,  9348, 63499, 54202),
      simde_x_mm_set_epu16(15556, 57011, 54250, 65535, 65535, 15003, 65535, 65535) },
    { simde_x_mm_set_epu16( 5059, 20924,  5143, 29698, 39512, 42596, 50907, 48157),
      simde_x_mm_set_epu16(55259, 30633, 10948, 60956, 47288, 59136, 49334, 11432),
      simde_x_mm_set_epu16(60318, 51557, 16091, 65535, 65535, 65535, 65535, 59589) },
    { simde_x_mm_set_epu16(53397,  1584, 56368, 64962, 35166, 11367, 24855, 22370),
      simde_x_mm_set_epu16( 5862,  9719, 15493, 14762, 25151, 48370, 30737, 29969),
      simde_x_mm_set_epu16(59259, 11303, 65535, 65535, 60317, 59737, 55592, 52339) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128d
    all_set = simde_x_mm_setone_pd(),
    all_unset = simde_mm_setzero_pd();

  simde_assert_m128d_equal(simde_mm_and_pd(all_set, all_unset), all_unset);
  simde_assert_m128d_equal(simde_mm_and_pd(all_set, all_set), all_set);
  simde_assert_m128d_equal(simde_mm_and_pd(all_unset, all_unset), all_unset);

  return 0;
}

static int
test_simde_mm_and_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1143386005), INT32_C(  255040004), INT32_C(  778825143), INT32_C( 1160880262)),
      simde_mm_set_epi32(INT32_C(-1598010564), INT32_C(  882577136), INT32_C( 1895747884), INT32_C(   78458499)),
      simde_mm_set_epi32(INT32_C(       2836), INT32_C(   68356608), INT32_C(  543867172), INT32_C(   69279874)) },
    { simde_mm_set_epi32(INT32_C(  929630839), INT32_C( 1332223012), INT32_C( -595247247), INT32_C( 1607004091)),
      simde_mm_set_epi32(INT32_C(  -96984995), INT32_C( -496201158), INT32_C( 1667897198), INT32_C(  329068048)),
      simde_mm_set_epi32(INT32_C(  841482325), INT32_C( 1114116128), INT32_C( 1073747808), INT32_C(  327691792)) },
    { simde_mm_set_epi32(INT32_C( 1507410371), INT32_C(-1202228125), INT32_C(  213174798), INT32_C( 1712466479)),
      simde_mm_set_epi32(INT32_C( -416935364), INT32_C(   76821686), INT32_C( -895281725), INT32_C(  640856929)),
      simde_mm_set_epi32(INT32_C( 1090519040), INT32_C(    1324066), INT32_C(  144703490), INT32_C(  638722593)) },
    { simde_mm_set_epi32(INT32_C(-1967400648), INT32_C( -398277023), INT32_C( 1276094966), INT32_C(-1580835262)),
      simde_mm_set_epi32(INT32_C(  185492863), INT32_C( 1265367516), INT32_C( -384438464), INT32_C( 1008626379)),
      simde_mm_set_epi32(INT32_C(  168444216), INT32_C( 1212334144), INT32_C( 1208330560), INT32_C(  537283138)) },
    { simde_mm_set_epi32(INT32_C( 1287640091), INT32_C( -654000828), INT32_C(  597524546), INT32_C(  182360913)),
      simde_mm_set_epi32(INT32_C( 1236330411), INT32_C( 1010510657), INT32_C(-1874705697), INT32_C( -544222805)),
      simde_mm_set_epi32(INT32_C( 1219544075), INT32_C(  402663744), INT32_C(         66), INT32_C(  177115393)) },
    { simde_mm_set_epi32(INT32_C( -783740762), INT32_C( 1592969400), INT32_C(-1896275639), INT32_C( 1398555518)),
      simde_mm_set_epi32(INT32_C(  618146080), INT32_C( -972493969), INT32_C( -440292799), INT32_C(  888342397)),
      simde_mm_set_epi32(INT32_C(    4718624), INT32_C( 1174456360), INT32_C(-2067718079), INT32_C(  273679228)) },
    { simde_mm_set_epi32(INT32_C(  975551520), INT32_C(  223749592), INT32_C(-1022254731), INT32_C( -845311996)),
      simde_mm_set_epi32(INT32_C( 1522650069), INT32_C( 1767255815), INT32_C( 1217271913), INT32_C(-1365644996)),
      simde_mm_set_epi32(INT32_C(  436307968), INT32_C(  156640512), INT32_C( 1073741921), INT32_C(-1936097276)) },
    { simde_mm_set_epi32(INT32_C(-1607852092), INT32_C( -146112938), INT32_C(  112326370), INT32_C(  971940993)),
      simde_mm_set_epi32(INT32_C( 1129446249), INT32_C( -367605030), INT32_C( 2031327443), INT32_C( -763011289)),
      simde_mm_set_epi32(INT32_C(       6976), INT32_C( -503166382), INT32_C(    1151170), INT32_C(  277087233)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_and_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_andnot_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 2301068032488183266),  INT64_C( 2211418302004999322) },
      { -INT64_C( 6496218963460796338), -INT64_C( 1823812953617724359) },
      {  INT64_C(  416592882749870144), -INT64_C( 2305839985119459295) } },
    { { -INT64_C( 4026537826130773906), -INT64_C( 4293586900818793454) },
      {  INT64_C( 3627658264586431853),  INT64_C( 2793073689318142995) },
      {  INT64_C( 3620897194948822273),  INT64_C( 2486233871494942721) } },
    { {  INT64_C( 9163842748139474741),  INT64_C( 2569644122047224175) },
      { -INT64_C(  969348282954885022),  INT64_C(  811088657167341923) },
      { -INT64_C( 9187294233813168062),  INT64_C(  594616163615653888) } },
    { { -INT64_C( 7634837049602759393),  INT64_C( 7858258033422095925) },
      {  INT64_C( 8560872385946379772),  INT64_C( 5408772763975523373) },
      {  INT64_C( 6972768561940938976),  INT64_C(  144627715121612808) } },
    { {  INT64_C( 5707717806252392055), -INT64_C( 3300212919446621766) },
      {  INT64_C( 9059126230790306606), -INT64_C( 7813869476910184169) },
      {  INT64_C( 3497071796361199880),  INT64_C(  111611459737241605) } },
    { {  INT64_C(  322122041068250894),  INT64_C( 3008683809568371225) },
      {  INT64_C(  127266174305791736), -INT64_C( 2153613612017236628) },
      {  INT64_C(  109216282184321264), -INT64_C( 4459687314800229020) } },
    { { -INT64_C( 3492115216109711814),  INT64_C( 5213618401531810613) },
      {  INT64_C( 6185505972225623532),  INT64_C( 2977154160444382105) },
      {  INT64_C( 1177221022203544004),  INT64_C( 2378043193183766664) } },
    { {  INT64_C( 1499198256367688520), -INT64_C(  638210378185732981) },
      { -INT64_C( 6727634533471112091), -INT64_C( 4478722654180704065) },
      { -INT64_C( 6764261500459572187),  INT64_C(   60904633988546612) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_castpd_si128(simde_mm_andnot_pd(simde_mm_castsi128_pd(a), simde_mm_castsi128_pd(b)));
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_andnot_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -560808079), INT32_C( -229809400), INT32_C(-1262424809), INT32_C(   39478984)),
      simde_mm_set_epi32(INT32_C(-2116907800), INT32_C( -478633369), INT32_C( -758500702), INT32_C(  774827765)),
      simde_mm_set_epi32(INT32_C(   20971656), INT32_C(   19955815), INT32_C( 1107956384), INT32_C(  740591669)) },
    { simde_mm_set_epi32(INT32_C( -390101732), INT32_C( -878593643), INT32_C(  -87858932), INT32_C( 1872700566)),
      simde_mm_set_epi32(INT32_C(  794830631), INT32_C( 1201718915), INT32_C( 1477008088), INT32_C( -178127418)),
      simde_mm_set_epi32(INT32_C(  121643555), INT32_C(   67126786), INT32_C(     531152), INT32_C(-1872701120)) },
    { simde_mm_set_epi32(INT32_C( -969785513), INT32_C(  743154241), INT32_C( -944974936), INT32_C(-1136592248)),
      simde_mm_set_epi32(INT32_C( -909998602), INT32_C(  431643866), INT32_C( -708589890), INT32_C( -556429363)),
      simde_mm_set_epi32(INT32_C(  163610784), INT32_C(  296770714), INT32_C(  272827414), INT32_C( 1117062469)) },
    { simde_mm_set_epi32(INT32_C( 1619650408), INT32_C(  861525694), INT32_C(-2058207417), INT32_C(  228720218)),
      simde_mm_set_epi32(INT32_C( 1416821078), INT32_C( 2107001565), INT32_C(-1248448269), INT32_C(-1204471361)),
      simde_mm_set_epi32(INT32_C(  343021590), INT32_C( 1283852353), INT32_C(  813957296), INT32_C(-1340866139)) },
    { simde_mm_set_epi32(INT32_C( -343490394), INT32_C( 1846187115), INT32_C( -847771260), INT32_C(   97935165)),
      simde_mm_set_epi32(INT32_C(  -69489865), INT32_C(-1109591795), INT32_C(  169478308), INT32_C( 1662522631)),
      simde_mm_set_epi32(INT32_C(  274279185), INT32_C(-1848350460), INT32_C(   33685536), INT32_C( 1644691458)) },
    { simde_mm_set_epi32(INT32_C(  608096731), INT32_C( -775399847), INT32_C(  -52780990), INT32_C(  459462722)),
      simde_mm_set_epi32(INT32_C(-1928888486), INT32_C(-1926941714), INT32_C(-1218438233), INT32_C(  195273416)),
      simde_mm_set_epi32(INT32_C(-1996411392), INT32_C(  203760038), INT32_C(   52435877), INT32_C(    8462984)) },
    { simde_mm_set_epi32(INT32_C( 1829801526), INT32_C( 1678890728), INT32_C(-1629742565), INT32_C(  902941266)),
      simde_mm_set_epi32(INT32_C(  110066513), INT32_C( -591553870), INT32_C( -950259417), INT32_C(  810403185)),
      simde_mm_set_epi32(INT32_C(   42955073), INT32_C(-1733556206), INT32_C( 1090527524), INT32_C(     787745)) },
    { simde_mm_set_epi32(INT32_C(  321441431), INT32_C(-1200267660), INT32_C( -313751420), INT32_C(  515761953)),
      simde_mm_set_epi32(INT32_C( -687838781), INT32_C( 1420638186), INT32_C(-1442242179), INT32_C( 1996838037)),
      simde_mm_set_epi32(INT32_C(-1006624448), INT32_C( 1149772170), INT32_C(   33628537), INT32_C( 1627394196)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_andnot_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_avg_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8( 22, 218, 216,  66,  82, 156,  47,  52,
                          255,   1, 136, 174, 147, 136, 106, 178),
      simde_x_mm_set_epu8( 66, 241, 223, 129,  96,  67,   0,  68,
                          242,  71, 233, 224, 227, 252, 191,  92),
      simde_x_mm_set_epu8( 44, 230, 220,  98,  89, 112,  24,  60,
                          249,  36, 185, 199, 187, 194, 149, 135) },
    { simde_x_mm_set_epu8(219, 214,  26,  72,  63,  56, 200, 118,
                          196, 107,  88, 110, 187,   3,  64, 214),
      simde_x_mm_set_epu8( 44, 175, 103,  82,  87, 192, 180,  37,
                            0, 200,  53, 214,  25,  17,  19, 149),
      simde_x_mm_set_epu8(132, 195,  65,  77,  75, 124, 190,  78,
                           98, 154,  71, 162, 106,  10,  42, 182) },
    { simde_x_mm_set_epu8(221,   9, 162, 208,  84,  84,  50, 140,
                          230,  69, 178,  12,  34, 173,  44,  58),
      simde_x_mm_set_epu8(  4, 110,  65, 218, 252, 108, 241, 136,
                           36, 109,  68,   2, 121,  10, 120, 101),
      simde_x_mm_set_epu8(113,  60, 114, 213, 168,  96, 146, 138,
                          133,  89, 123,   7,  78,  92,  82,  80) },
    { simde_x_mm_set_epu8(173,  38,  26, 251,  66, 136, 168, 132,
                          170, 244, 145,  27,  76, 168,  97, 129),
      simde_x_mm_set_epu8(211,  66,  29,  93, 231,  30, 149, 218,
                           72,  12, 231, 238, 124,   3, 127,  55),
      simde_x_mm_set_epu8(192,  52,  28, 172, 149,  83, 159, 175,
                          121, 128, 188, 133, 100,  86, 112,  92) },
    { simde_x_mm_set_epu8( 33, 120,  41,   4, 226,  71, 169,  72,
                           92, 211,  80,  53,  22, 250, 136,  31),
      simde_x_mm_set_epu8(163, 237, 214, 178,  29, 194, 137, 109,
                          134, 197,  40, 228, 174, 101, 114, 162),
      simde_x_mm_set_epu8( 98, 179, 128,  91, 128, 133, 153,  91,
                          113, 204,  60, 141,  98, 176, 125,  97) },
    { simde_x_mm_set_epu8(151, 241,  42,  96,  21, 167,  26, 188,
                          124, 136, 158, 144, 227, 152,   4, 152),
      simde_x_mm_set_epu8( 43, 216,  77, 147, 105, 127,  87,  93,
                          160, 103,  68,  85,  77,  41,  67, 189),
      simde_x_mm_set_epu8( 97, 229,  60, 122,  63, 147,  57, 141,
                          142, 120, 113, 115, 152,  97,  36, 171) },
    { simde_x_mm_set_epu8(229, 241,   5, 141,  89,  37, 175, 184,
                          139, 113,  20, 221, 179, 130,  61,  16),
      simde_x_mm_set_epu8( 74,  70, 240, 235, 217, 244,  23, 139,
                          224,  48, 224, 137, 221, 180, 178,  80),
      simde_x_mm_set_epu8(152, 156, 123, 188, 153, 141,  99, 162,
                          182,  81, 122, 179, 200, 155, 120,  48) },
    { simde_x_mm_set_epu8( 30,  40, 139,  23, 169,  60,  77, 114,
                           84,  55,  70, 122,  10,  27,  47, 237),
      simde_x_mm_set_epu8(133, 159, 246, 175, 239, 136, 111, 216,
                          173,  32, 117,  64, 231, 128, 162, 145),
      simde_x_mm_set_epu8( 82, 100, 193,  99, 204,  98,  94, 165,
                          129,  44,  94,  93, 121,  78, 105, 191) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_avg_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_avg_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16( 5850, 55362, 21148, 12084, 65281, 34990, 37768, 27314),
      simde_x_mm_set_epu16(17137, 57217, 24643,    68, 62023, 59872, 58364, 48988),
      simde_x_mm_set_epu16(11494, 56290, 22896,  6076, 63652, 47431, 48066, 38151) },
    { simde_x_mm_set_epu16(56278,  6728, 16184, 51318, 50283, 22638, 47875, 16598),
      simde_x_mm_set_epu16(11439, 26450, 22464, 46117,   200, 13782,  6417,  5013),
      simde_x_mm_set_epu16(33859, 16589, 19324, 48718, 25242, 18210, 27146, 10806) },
    { simde_x_mm_set_epu16(56585, 41680, 21588, 12940, 58949, 45580,  8877, 11322),
      simde_x_mm_set_epu16( 1134, 16858, 64620, 61832,  9325, 17410, 30986, 30821),
      simde_x_mm_set_epu16(28860, 29269, 43104, 37386, 34137, 31495, 19932, 21072) },
    { simde_x_mm_set_epu16(44326,  6907, 17032, 43140, 43764, 37147, 19624, 24961),
      simde_x_mm_set_epu16(54082,  7517, 59166, 38362, 18444, 59374, 31747, 32567),
      simde_x_mm_set_epu16(49204,  7212, 38099, 40751, 31104, 48261, 25686, 28764) },
    { simde_x_mm_set_epu16( 8568, 10500, 57927, 43336, 23763, 20533,  5882, 34847),
      simde_x_mm_set_epu16(41965, 54962,  7618, 35181, 34501, 10468, 44645, 29346),
      simde_x_mm_set_epu16(25267, 32731, 32773, 39259, 29132, 15501, 25264, 32097) },
    { simde_x_mm_set_epu16(38897, 10848,  5543,  6844, 31880, 40592, 58264,  1176),
      simde_x_mm_set_epu16(11224, 19859, 27007, 22365, 41063, 17493, 19753, 17341),
      simde_x_mm_set_epu16(25061, 15354, 16275, 14605, 36472, 29043, 39009,  9259) },
    { simde_x_mm_set_epu16(58865,  1421, 22821, 44984, 35697,  5341, 45954, 15632),
      simde_x_mm_set_epu16(19014, 61675, 55796,  6027, 57392, 57481, 56756, 45648),
      simde_x_mm_set_epu16(38940, 31548, 39309, 25506, 46545, 31411, 51355, 30640) },
    { simde_x_mm_set_epu16( 7720, 35607, 43324, 19826, 21559, 18042,  2587, 12269),
      simde_x_mm_set_epu16(34207, 63151, 61320, 28632, 44320, 30016, 59264, 41617),
      simde_x_mm_set_epu16(20964, 49379, 52322, 24229, 32940, 24029, 30926, 26943) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_avg_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_bslli_si128(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i a, e, r;

  a = simde_mm_set_epi8(INT8_C(  24), INT8_C( -55), INT8_C( -96), INT8_C(  87),
                        INT8_C( -58), INT8_C(-112), INT8_C(  23), INT8_C(-126),
                        INT8_C(  -8), INT8_C( -11), INT8_C(  18), INT8_C(  30),
                        INT8_C( 114), INT8_C(  65), INT8_C(  26), INT8_C(-121));

  e = simde_mm_set_epi8(INT8_C(  24), INT8_C( -55), INT8_C( -96), INT8_C(  87),
                        INT8_C( -58), INT8_C(-112), INT8_C(  23), INT8_C(-126),
                        INT8_C(  -8), INT8_C( -11), INT8_C(  18), INT8_C(  30),
                        INT8_C( 114), INT8_C(  65), INT8_C(  26), INT8_C(-121));
  r = simde_mm_bslli_si128(a, 0);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(  87), INT8_C( -58), INT8_C(-112), INT8_C(  23),
                        INT8_C(-126), INT8_C(  -8), INT8_C( -11), INT8_C(  18),
                        INT8_C(  30), INT8_C( 114), INT8_C(  65), INT8_C(  26),
                        INT8_C(-121), INT8_C(   0), INT8_C(   0), INT8_C(   0));
  r = simde_mm_bslli_si128(a, 3);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(  65), INT8_C(  26), INT8_C(-121), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0));
  r = simde_mm_bslli_si128(a, 13);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C( -96), INT8_C(  87), INT8_C( -58), INT8_C(-112),
                        INT8_C(  23), INT8_C(-126), INT8_C(  -8), INT8_C( -11),
                        INT8_C(  18), INT8_C(  30), INT8_C( 114), INT8_C(  65),
                        INT8_C(  26), INT8_C(-121), INT8_C(   0), INT8_C(   0));
  r = simde_mm_bslli_si128(a, 2);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0));
  r = simde_mm_bslli_si128(a, 19);
  simde_assert_m128i_i8(r, ==, e);

  return 0;
}

static int
test_simde_mm_bsrli_si128(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i a, e, r;

  a = simde_mm_set_epi8(INT8_C(-121), INT8_C( -58), INT8_C( -15), INT8_C(-115),
                        INT8_C( -97), INT8_C( -96), INT8_C( -74), INT8_C(-113),
                        INT8_C(-121), INT8_C(  99), INT8_C( 126), INT8_C( 113),
                        INT8_C( -29), INT8_C( 114), INT8_C( -65), INT8_C(   9));

  e = simde_mm_set_epi8(INT8_C(-121), INT8_C( -58), INT8_C( -15), INT8_C(-115),
                        INT8_C( -97), INT8_C( -96), INT8_C( -74), INT8_C(-113),
                        INT8_C(-121), INT8_C(  99), INT8_C( 126), INT8_C( 113),
                        INT8_C( -29), INT8_C( 114), INT8_C( -65), INT8_C(   9));
  r = simde_mm_bsrli_si128(a, 0);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-121),
                        INT8_C( -58), INT8_C( -15), INT8_C(-115), INT8_C( -97),
                        INT8_C( -96), INT8_C( -74), INT8_C(-113), INT8_C(-121),
                        INT8_C(  99), INT8_C( 126), INT8_C( 113), INT8_C( -29));
  r = simde_mm_bsrli_si128(a, 3);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(-121), INT8_C( -58), INT8_C( -15));
  r = simde_mm_bsrli_si128(a, 13);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(-121), INT8_C( -58),
                        INT8_C( -15), INT8_C(-115), INT8_C( -97), INT8_C( -96),
                        INT8_C( -74), INT8_C(-113), INT8_C(-121), INT8_C(  99),
                        INT8_C( 126), INT8_C( 113), INT8_C( -29), INT8_C( 114));
  r = simde_mm_bsrli_si128(a, 2);
  simde_assert_m128i_i8(r, ==, e);

  e = simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0));
  r = simde_mm_bsrli_si128(a, 19);
  simde_assert_m128i_i8(r, ==, e);

  return 0;
}

static int
test_simde_mm_castpd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( 499.48), SIMDE_FLOAT32_C(  72.83), SIMDE_FLOAT32_C(-420.10), SIMDE_FLOAT32_C( -361.15))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 499.48), SIMDE_FLOAT32_C(  72.83), SIMDE_FLOAT32_C(-420.10), SIMDE_FLOAT32_C( -361.15)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-412.40), SIMDE_FLOAT32_C(-314.35), SIMDE_FLOAT32_C(-851.03), SIMDE_FLOAT32_C(  128.01))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-412.40), SIMDE_FLOAT32_C(-314.35), SIMDE_FLOAT32_C(-851.03), SIMDE_FLOAT32_C(  128.01)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-411.93), SIMDE_FLOAT32_C( 780.67), SIMDE_FLOAT32_C(-928.22), SIMDE_FLOAT32_C(  762.24))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-411.93), SIMDE_FLOAT32_C( 780.67), SIMDE_FLOAT32_C(-928.22), SIMDE_FLOAT32_C(  762.24)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-614.18), SIMDE_FLOAT32_C( 644.19), SIMDE_FLOAT32_C( -41.15), SIMDE_FLOAT32_C(  871.68))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-614.18), SIMDE_FLOAT32_C( 644.19), SIMDE_FLOAT32_C( -41.15), SIMDE_FLOAT32_C(  871.68)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( 795.82), SIMDE_FLOAT32_C( 486.26), SIMDE_FLOAT32_C(-686.59), SIMDE_FLOAT32_C(  277.69))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 795.82), SIMDE_FLOAT32_C( 486.26), SIMDE_FLOAT32_C(-686.59), SIMDE_FLOAT32_C(  277.69)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( 221.74), SIMDE_FLOAT32_C(-655.22), SIMDE_FLOAT32_C(-366.90), SIMDE_FLOAT32_C( -245.25))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 221.74), SIMDE_FLOAT32_C(-655.22), SIMDE_FLOAT32_C(-366.90), SIMDE_FLOAT32_C( -245.25)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( -83.75), SIMDE_FLOAT32_C( 862.26), SIMDE_FLOAT32_C(  55.37), SIMDE_FLOAT32_C(  -26.83))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -83.75), SIMDE_FLOAT32_C( 862.26), SIMDE_FLOAT32_C(  55.37), SIMDE_FLOAT32_C(  -26.83)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-557.26), SIMDE_FLOAT32_C(-554.56), SIMDE_FLOAT32_C(-507.07), SIMDE_FLOAT32_C(  395.47))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-557.26), SIMDE_FLOAT32_C(-554.56), SIMDE_FLOAT32_C(-507.07), SIMDE_FLOAT32_C(  395.47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_castpd_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_castps_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -48.11), SIMDE_FLOAT32_C(    66.54), SIMDE_FLOAT32_C(  -702.38), SIMDE_FLOAT32_C(  -384.97)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -48.11), SIMDE_FLOAT32_C(    66.54), SIMDE_FLOAT32_C(  -702.38), SIMDE_FLOAT32_C(  -384.97)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   975.22), SIMDE_FLOAT32_C(  -352.19), SIMDE_FLOAT32_C(  -258.03), SIMDE_FLOAT32_C(   978.92)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   975.22), SIMDE_FLOAT32_C(  -352.19), SIMDE_FLOAT32_C(  -258.03), SIMDE_FLOAT32_C(   978.92)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    24.73), SIMDE_FLOAT32_C(  -551.11), SIMDE_FLOAT32_C(   -52.52), SIMDE_FLOAT32_C(   259.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    24.73), SIMDE_FLOAT32_C(  -551.11), SIMDE_FLOAT32_C(   -52.52), SIMDE_FLOAT32_C(   259.60)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   614.82), SIMDE_FLOAT32_C(   711.79), SIMDE_FLOAT32_C(   715.74), SIMDE_FLOAT32_C(   872.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   614.82), SIMDE_FLOAT32_C(   711.79), SIMDE_FLOAT32_C(   715.74), SIMDE_FLOAT32_C(   872.89)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   434.09), SIMDE_FLOAT32_C(    97.43), SIMDE_FLOAT32_C(   836.69), SIMDE_FLOAT32_C(   490.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   434.09), SIMDE_FLOAT32_C(    97.43), SIMDE_FLOAT32_C(   836.69), SIMDE_FLOAT32_C(   490.93)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -964.09), SIMDE_FLOAT32_C(   616.34), SIMDE_FLOAT32_C(  -267.39), SIMDE_FLOAT32_C(  -457.57)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -964.09), SIMDE_FLOAT32_C(   616.34), SIMDE_FLOAT32_C(  -267.39), SIMDE_FLOAT32_C(  -457.57)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -14.24), SIMDE_FLOAT32_C(   802.19), SIMDE_FLOAT32_C(   741.42), SIMDE_FLOAT32_C(  -211.48)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -14.24), SIMDE_FLOAT32_C(   802.19), SIMDE_FLOAT32_C(   741.42), SIMDE_FLOAT32_C(  -211.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -739.71), SIMDE_FLOAT32_C(  -918.58), SIMDE_FLOAT32_C(  -598.92), SIMDE_FLOAT32_C(  -924.03)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -739.71), SIMDE_FLOAT32_C(  -918.58), SIMDE_FLOAT32_C(  -598.92), SIMDE_FLOAT32_C(  -924.03)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_castpd_ps(simde_mm_castps_pd(test_vec[i].a));
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_castsi128_pd(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i test_vec[8] = {
    simde_mm_set_epi32(INT32_C(-1784593785), INT32_C( 1037253725), INT32_C(  225827038), INT32_C(-2070942389)),
    simde_mm_set_epi32(INT32_C( 2006039830), INT32_C(  831495128), INT32_C( 1875760759), INT32_C(  315081037)),
    simde_mm_set_epi32(INT32_C( -305750616), INT32_C(  602617399), INT32_C( 1569354160), INT32_C(-1091905770)),
    simde_mm_set_epi32(INT32_C(-1852218105), INT32_C(-1464694454), INT32_C(-1287612023), INT32_C( 1418106957)),
    simde_mm_set_epi32(INT32_C( 1382189486), INT32_C(  561466363), INT32_C( -455563445), INT32_C(  733917325)),
    simde_mm_set_epi32(INT32_C( -187102213), INT32_C( -373894547), INT32_C(  335417846), INT32_C(  400855569)),
    simde_mm_set_epi32(INT32_C( 1405293845), INT32_C( -164981292), INT32_C(  180491437), INT32_C( 1551867928)),
    simde_mm_set_epi32(INT32_C(  458893421), INT32_C(-1960480477), INT32_C( 1264329759), INT32_C( 1663854158))
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_castsi128_pd(test_vec[i]));
    simde_assert_m128i_equal(r, test_vec[i]);
  }

  return 0;
}

static int
test_simde_mm_castsi128_ps(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i test_vec[8] = {
    simde_mm_set_epi32(INT32_C(-1036963898), INT32_C( 1847069037), INT32_C(  740321504), INT32_C(  778754840)),
    simde_mm_set_epi32(INT32_C(  975137998), INT32_C( -252397546), INT32_C( 1504697866), INT32_C(-1327032545)),
    simde_mm_set_epi32(INT32_C(-1494981423), INT32_C( -175189577), INT32_C( 2056595322), INT32_C( 1080531273)),
    simde_mm_set_epi32(INT32_C(-1391843620), INT32_C(  424327107), INT32_C(  948927709), INT32_C( -666077781)),
    simde_mm_set_epi32(INT32_C(  951847201), INT32_C( -299846327), INT32_C(  575809604), INT32_C(-1150359231)),
    simde_mm_set_epi32(INT32_C(  837564377), INT32_C( -933128035), INT32_C( -581372672), INT32_C( -490866291)),
    simde_mm_set_epi32(INT32_C( -169157316), INT32_C( 1521943175), INT32_C(  841770394), INT32_C( -192049832)),
    simde_mm_set_epi32(INT32_C( -848324384), INT32_C(-1699878899), INT32_C( -332340467), INT32_C(  934012294))
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(simde_mm_castsi128_ps(test_vec[i]));
    simde_assert_m128i_i64(r, ==, test_vec[i]);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  48), INT8_C( -17), INT8_C(  87), INT8_C(  -4),
                        INT8_C(   4), INT8_C( -44), INT8_C( 121), INT8_C(  68),
                        INT8_C(  49), INT8_C(-108), INT8_C(  49), INT8_C( -79),
                        INT8_C(  51), INT8_C( -82), INT8_C(  23), INT8_C( -58)),
      simde_mm_set_epi8(INT8_C(  87), INT8_C( -42), INT8_C(  33), INT8_C( 126),
                        INT8_C(  91), INT8_C( 115), INT8_C( -90), INT8_C(  48),
                        INT8_C( -49), INT8_C(-119), INT8_C(  23), INT8_C(  50),
                        INT8_C( -10), INT8_C( -15), INT8_C( -16), INT8_C( -58)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  90), INT8_C( -93), INT8_C( 121), INT8_C( 114),
                        INT8_C(  21), INT8_C( -52), INT8_C( -45), INT8_C( -83),
                        INT8_C(-123), INT8_C(-119), INT8_C( -53), INT8_C(-117),
                        INT8_C( -60), INT8_C( -20), INT8_C(-100), INT8_C(  26)),
      simde_mm_set_epi8(INT8_C(  67), INT8_C( -34), INT8_C(-110), INT8_C( -79),
                        INT8_C( -72), INT8_C( -43), INT8_C(  64), INT8_C( -74),
                        INT8_C(  64), INT8_C(  85), INT8_C( -71), INT8_C(  89),
                        INT8_C(  35), INT8_C(  81), INT8_C( 104), INT8_C( 111)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  33), INT8_C(  56), INT8_C( -20), INT8_C(  49),
                        INT8_C( -77), INT8_C(-123), INT8_C( -77), INT8_C(-109),
                        INT8_C( -13), INT8_C(  91), INT8_C( 105), INT8_C(  29),
                        INT8_C(  35), INT8_C( -62), INT8_C(  39), INT8_C( -24)),
      simde_mm_set_epi8(INT8_C( -80), INT8_C( -37), INT8_C(  43), INT8_C( 121),
                        INT8_C(-104), INT8_C( -93), INT8_C(-100), INT8_C(  55),
                        INT8_C( -82), INT8_C( -92), INT8_C(  -6), INT8_C(   2),
                        INT8_C( -33), INT8_C( 114), INT8_C( -94), INT8_C(  58)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -50), INT8_C(  20), INT8_C(  99), INT8_C(   4),
                        INT8_C(  66), INT8_C( -69), INT8_C(-117), INT8_C(  25),
                        INT8_C( -96), INT8_C( -11), INT8_C( -75), INT8_C( -79),
                        INT8_C(  88), INT8_C(-123), INT8_C( -55), INT8_C(  22)),
      simde_mm_set_epi8(INT8_C(  68), INT8_C(-117), INT8_C(-113), INT8_C(  30),
                        INT8_C(   0), INT8_C(  65), INT8_C( -61), INT8_C( -31),
                        INT8_C( -53), INT8_C(  -2), INT8_C( -47), INT8_C(  20),
                        INT8_C( -79), INT8_C(-126), INT8_C(  40), INT8_C(  81)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 100), INT8_C( -54), INT8_C( -62), INT8_C( -41),
                        INT8_C(-110), INT8_C(  -3), INT8_C(-102), INT8_C(  -2),
                        INT8_C(  26), INT8_C( -67), INT8_C( -67), INT8_C( -73),
                        INT8_C(  18), INT8_C( 123), INT8_C( 122), INT8_C( 106)),
      simde_mm_set_epi8(INT8_C(  -5), INT8_C(   2), INT8_C( 119), INT8_C(  28),
                        INT8_C( -24), INT8_C(  12), INT8_C( 106), INT8_C( -55),
                        INT8_C( 124), INT8_C(  69), INT8_C(  31), INT8_C(-126),
                        INT8_C( -80), INT8_C( -78), INT8_C( -93), INT8_C( -23)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  48), INT8_C( -25), INT8_C( -80), INT8_C(  17),
                        INT8_C( -70), INT8_C( -40), INT8_C(  83), INT8_C(  37),
                        INT8_C(  22), INT8_C( -91), INT8_C( -79), INT8_C(   8),
                        INT8_C(   9), INT8_C( -21), INT8_C( -51), INT8_C( -21)),
      simde_mm_set_epi8(INT8_C(  55), INT8_C( 114), INT8_C( -79), INT8_C( -59),
                        INT8_C(  15), INT8_C( -50), INT8_C( -69), INT8_C(   7),
                        INT8_C(-113), INT8_C( -95), INT8_C( 112), INT8_C(   5),
                        INT8_C( -30), INT8_C( -68), INT8_C( -27), INT8_C( -43)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  34), INT8_C( 111), INT8_C(  52), INT8_C(  93),
                        INT8_C( -12), INT8_C(  98), INT8_C( -88), INT8_C(  63),
                        INT8_C(  64), INT8_C( -98), INT8_C(  18), INT8_C(  40),
                        INT8_C( 119), INT8_C(  68), INT8_C( -90), INT8_C( -37)),
      simde_mm_set_epi8(INT8_C(  35), INT8_C(  97), INT8_C(   3), INT8_C(  88),
                        INT8_C( -70), INT8_C( -12), INT8_C( -13), INT8_C(  52),
                        INT8_C( 127), INT8_C(  -5), INT8_C( -24), INT8_C( -10),
                        INT8_C( -21), INT8_C(-112), INT8_C( -81), INT8_C(  86)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -25), INT8_C(-100), INT8_C( -66), INT8_C( 103),
                        INT8_C(-103), INT8_C( 116), INT8_C( -97), INT8_C( -43),
                        INT8_C( 123), INT8_C( -33), INT8_C( -71), INT8_C(-122),
                        INT8_C( 100), INT8_C( 116), INT8_C(  67), INT8_C(-119)),
      simde_mm_set_epi8(INT8_C( 103), INT8_C( -84), INT8_C( 102), INT8_C( -67),
                        INT8_C( -82), INT8_C(  14), INT8_C( -17), INT8_C( -71),
                        INT8_C( -31), INT8_C(-109), INT8_C( -84), INT8_C( -22),
                        INT8_C(  78), INT8_C(-120), INT8_C( -77), INT8_C(  -6)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  5875), INT16_C(-30240), INT16_C(  4973), INT16_C(-24835),
                         INT16_C( -2682), INT16_C( 25733), INT16_C(  1837), INT16_C( -8035)),
      simde_mm_set_epi16(INT16_C(  5875), INT16_C(-30240), INT16_C(  9332), INT16_C(-24835),
                         INT16_C( -8998), INT16_C( 25733), INT16_C(  1837), INT16_C(-18483)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( -1458), INT16_C( 12290), INT16_C(   394), INT16_C(  6014),
                         INT16_C( 25725), INT16_C( 16049), INT16_C(  -659), INT16_C( 13250)),
      simde_mm_set_epi16(INT16_C( -1458), INT16_C( 12290), INT16_C(   394), INT16_C(  6014),
                         INT16_C( 25725), INT16_C(-30312), INT16_C(  -659), INT16_C( 20372)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( -4375), INT16_C(  1648), INT16_C( -8256), INT16_C( 10030),
                         INT16_C( 20444), INT16_C( -7330), INT16_C( -7889), INT16_C( 23879)),
      simde_mm_set_epi16(INT16_C(  -644), INT16_C(  1648), INT16_C( -8256), INT16_C( 10030),
                         INT16_C(  4813), INT16_C( -7330), INT16_C(-10599), INT16_C(-13677)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(-20962), INT16_C(-30592), INT16_C(-23740), INT16_C( -1360),
                         INT16_C(  6756), INT16_C( 10080), INT16_C( 31194), INT16_C(-10248)),
      simde_mm_set_epi16(INT16_C(-20962), INT16_C(-19403), INT16_C( 31222), INT16_C( 12369),
                         INT16_C( 10909), INT16_C( 10080), INT16_C( 31194), INT16_C(-10248)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( -5540), INT16_C(-14756), INT16_C(-15994), INT16_C(  1795),
                         INT16_C( 18849), INT16_C( 15779), INT16_C(  5314), INT16_C(-13448)),
      simde_mm_set_epi16(INT16_C( -5540), INT16_C( 14083), INT16_C(-16603), INT16_C(  1795),
                         INT16_C( 28557), INT16_C(-32040), INT16_C(  5314), INT16_C( -4887)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(-18621), INT16_C(  6869), INT16_C(-16161), INT16_C(-24568),
                         INT16_C(-10576), INT16_C( 20065), INT16_C( -8241), INT16_C(-21658)),
      simde_mm_set_epi16(INT16_C(-18621), INT16_C(  6869), INT16_C(-10830), INT16_C(-24568),
                         INT16_C(-10576), INT16_C( 20065), INT16_C( -8094), INT16_C(-21658)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C(-20765), INT16_C( 27683), INT16_C( 13646), INT16_C( 26224),
                         INT16_C(-12316), INT16_C( -2556), INT16_C( -1320), INT16_C(-15938)),
      simde_mm_set_epi16(INT16_C( -5976), INT16_C( 27683), INT16_C( -6395), INT16_C( 26224),
                         INT16_C(-12316), INT16_C( -2556), INT16_C( -1320), INT16_C(-15143)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( 25864), INT16_C( 17430), INT16_C( 25473), INT16_C( 24392),
                         INT16_C( 27481), INT16_C(  2288), INT16_C( 24811), INT16_C( 18514)),
      simde_mm_set_epi16(INT16_C( 25864), INT16_C(  8829), INT16_C( 25473), INT16_C( 24392),
                         INT16_C( 27481), INT16_C(  4599), INT16_C( 24811), INT16_C( 18514)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  385059296,   325951229,  -175741819,   120447133),
      simde_mm_set_epi32( -411118693,   325951229,  -175741819,   -74467379),
      simde_mm_set_epi32(          0,          -1,          -1,           0) },
    { simde_mm_set_epi32( 2086724423,  2071647391,   395772386,  -878201179),
      simde_mm_set_epi32( 2086724423,    25827198,  1685929649,   -43174974),
      simde_mm_set_epi32(         -1,           0,           0,           0) },
    { simde_mm_set_epi32(-1656549033,  -529471298,  -677159845, -1011499644),
      simde_mm_set_epi32(-1108138959,  2008596507,    36966751, -1011499644),
      simde_mm_set_epi32(          0,           0,           0,          -1) },
    { simde_mm_set_epi32(  -42154427,   232395060,   315449676,  -694564205),
      simde_mm_set_epi32(-1781616670,   232395060,   315449676,  -694564205),
      simde_mm_set_epi32(          0,          -1,          -1,          -1) },
    { simde_mm_set_epi32(-1373730688, -1555760464,   442771296,  2044385272),
      simde_mm_set_epi32( -819547083, -1555760464,   442771296,  2044385272),
      simde_mm_set_epi32(          0,          -1,          -1,          -1) },
    { simde_mm_set_epi32( -285007987,  1222927916,  -234086536,   711157928),
      simde_mm_set_epi32( -285007987,  1222927916,  1235303843,   711157928),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32( 1734698060,  -250509290,  -430142591,   970705024),
      simde_mm_set_epi32( 1734698060, -1399422252,  -430142591, -1199939349),
      simde_mm_set_epi32(         -1,           0,          -1,           0) },
    { simde_mm_set_epi32( 1285559999,  -709744735, -1852486552,  -530433851),
      simde_mm_set_epi32( 1285559999,  -709744735, -1768521466,  -530433851),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
   { simde_mm_set_pd(SIMDE_FLOAT64_C(  780.35), SIMDE_FLOAT64_C(  826.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  625.03), SIMDE_FLOAT64_C(  826.07)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C(-1), INT32_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -334.66), SIMDE_FLOAT64_C(  476.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -334.66), SIMDE_FLOAT64_C(  556.75)),
      simde_mm_set_epi32(INT32_C(-1), INT32_C(-1), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  324.97), SIMDE_FLOAT64_C(  726.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.03), SIMDE_FLOAT64_C(  556.75)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  432.42), SIMDE_FLOAT64_C(  208.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.03), SIMDE_FLOAT64_C(  556.75)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  361.87), SIMDE_FLOAT64_C( -173.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  190.30), SIMDE_FLOAT64_C( -730.35)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  187.80), SIMDE_FLOAT64_C( -428.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  754.99), SIMDE_FLOAT64_C( -730.35)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   34.65), SIMDE_FLOAT64_C(  814.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.60), SIMDE_FLOAT64_C(  292.36)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  221.70), SIMDE_FLOAT64_C( -277.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -578.28), SIMDE_FLOAT64_C(  292.36)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpeq_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_sd(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128d all_unset = simde_mm_setzero_pd();
  simde__m128d all_set = simde_mm_cmpeq_pd(all_unset, all_unset);

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  386.34), SIMDE_FLOAT64_C(  460.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -116.45), SIMDE_FLOAT64_C(  460.38)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  386.34), SIMDE_FLOAT64_C(  460.38)), all_set) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -493.11), SIMDE_FLOAT64_C(   58.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  511.42), SIMDE_FLOAT64_C(   58.42)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -493.11), SIMDE_FLOAT64_C(   58.42)), all_set) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  156.83), SIMDE_FLOAT64_C( -432.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  156.83), SIMDE_FLOAT64_C( -422.70)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  156.83), SIMDE_FLOAT64_C( -432.98)), all_unset) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C( -577.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  404.92), SIMDE_FLOAT64_C( -577.06)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C( -577.06)), all_set) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -468.33), SIMDE_FLOAT64_C(  -68.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -638.04), SIMDE_FLOAT64_C(  816.57)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -468.33), SIMDE_FLOAT64_C(  -68.91)), all_unset) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   37.53), SIMDE_FLOAT64_C(  339.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   37.53), SIMDE_FLOAT64_C(  339.53)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   37.53), SIMDE_FLOAT64_C(  339.53)), all_set) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -872.05), SIMDE_FLOAT64_C( -696.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.05), SIMDE_FLOAT64_C( -696.39)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -872.05), SIMDE_FLOAT64_C( -696.39)), all_set) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  251.77), SIMDE_FLOAT64_C( -366.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  251.77), SIMDE_FLOAT64_C( -622.95)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  251.77), SIMDE_FLOAT64_C( -366.11)), all_unset) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpeq_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpneq_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.42), SIMDE_FLOAT64_C( -471.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -120.90), SIMDE_FLOAT64_C( -471.42)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  174.13), SIMDE_FLOAT64_C(  302.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -462.00), SIMDE_FLOAT64_C(  302.06)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  456.61), SIMDE_FLOAT64_C(  -31.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  456.61), SIMDE_FLOAT64_C(  -31.59)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  863.75), SIMDE_FLOAT64_C(  743.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  863.75), SIMDE_FLOAT64_C( -940.38)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -207.80), SIMDE_FLOAT64_C(  181.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -207.80), SIMDE_FLOAT64_C(  980.93)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -330.41), SIMDE_FLOAT64_C(  936.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -223.97), SIMDE_FLOAT64_C(  936.80)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -293.06), SIMDE_FLOAT64_C( -978.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -858.76), SIMDE_FLOAT64_C( -978.73)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  215.10), SIMDE_FLOAT64_C( -720.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -813.22), SIMDE_FLOAT64_C(  235.59)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpneq_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpneq_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  489.91), SIMDE_FLOAT64_C(  496.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -40.59), SIMDE_FLOAT64_C(  496.15)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  489.91), SIMDE_FLOAT64_C(  496.15)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -981.34), SIMDE_FLOAT64_C(  944.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -433.21), SIMDE_FLOAT64_C(  882.20)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -981.34), SIMDE_FLOAT64_C(  944.87)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  983.93), SIMDE_FLOAT64_C(  764.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  621.75), SIMDE_FLOAT64_C(  764.39)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  983.93), SIMDE_FLOAT64_C(  764.39)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  274.45), SIMDE_FLOAT64_C(  789.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  274.45), SIMDE_FLOAT64_C(  789.62)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  274.45), SIMDE_FLOAT64_C(  789.62)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -35.27), SIMDE_FLOAT64_C(   92.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -35.27), SIMDE_FLOAT64_C(   92.02)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  -35.27), SIMDE_FLOAT64_C(   92.02)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -842.06), SIMDE_FLOAT64_C( -358.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  290.56), SIMDE_FLOAT64_C(  859.30)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -842.06), SIMDE_FLOAT64_C( -358.82)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -575.93), SIMDE_FLOAT64_C( -661.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -462.75), SIMDE_FLOAT64_C(  732.75)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -575.93), SIMDE_FLOAT64_C( -661.58)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -876.76), SIMDE_FLOAT64_C( -235.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  264.94), SIMDE_FLOAT64_C(  767.34)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -876.76), SIMDE_FLOAT64_C( -235.41)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpneq_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -98), INT8_C( 126), INT8_C( -78), INT8_C( -97),
                        INT8_C( -35), INT8_C( -49), INT8_C( -62), INT8_C(  -8),
                        INT8_C( -88), INT8_C(  71), INT8_C(  16), INT8_C(  -4),
                        INT8_C(  69), INT8_C( -61), INT8_C(  47), INT8_C(  84)),
      simde_mm_set_epi8(INT8_C(   5), INT8_C(-114), INT8_C( -27), INT8_C( -61),
                        INT8_C(  56), INT8_C( 115), INT8_C( -53), INT8_C(  16),
                        INT8_C( -80), INT8_C( -18), INT8_C(  83), INT8_C(  -9),
                        INT8_C(  -3), INT8_C(  36), INT8_C( -57), INT8_C(  89)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  94), INT8_C(  78), INT8_C( -26), INT8_C(-126),
                        INT8_C( -98), INT8_C(  65), INT8_C(  38), INT8_C( -71),
                        INT8_C( -54), INT8_C(  20), INT8_C( -52), INT8_C(  55),
                        INT8_C( -76), INT8_C(  37), INT8_C( -95), INT8_C(  91)),
      simde_mm_set_epi8(INT8_C( -10), INT8_C( -43), INT8_C(  70), INT8_C(  -4),
                        INT8_C( -89), INT8_C( -31), INT8_C( -61), INT8_C(  81),
                        INT8_C(  64), INT8_C( -78), INT8_C(  14), INT8_C( 125),
                        INT8_C(  81), INT8_C(  62), INT8_C(-124), INT8_C(  39)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 103), INT8_C(  49), INT8_C(  24), INT8_C(   0),
                        INT8_C( -50), INT8_C(  64), INT8_C(  11), INT8_C( 101),
                        INT8_C(  39), INT8_C(  41), INT8_C(-111), INT8_C( -32),
                        INT8_C(  91), INT8_C(  86), INT8_C(-117), INT8_C( 115)),
      simde_mm_set_epi8(INT8_C( -44), INT8_C(  47), INT8_C( -14), INT8_C( 109),
                        INT8_C(  44), INT8_C(  97), INT8_C( -41), INT8_C(  53),
                        INT8_C(-121), INT8_C( -57), INT8_C(  54), INT8_C( 124),
                        INT8_C(  50), INT8_C( -73), INT8_C( -30), INT8_C( -62)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(-110), INT8_C(   5), INT8_C(  41), INT8_C(  -3),
                        INT8_C(-114), INT8_C(  14), INT8_C(-117), INT8_C( -89),
                        INT8_C(  52), INT8_C(  62), INT8_C(  41), INT8_C( -25),
                        INT8_C( 114), INT8_C(  56), INT8_C(  58), INT8_C( -99)),
      simde_mm_set_epi8(INT8_C( -31), INT8_C( -36), INT8_C(-126), INT8_C( -69),
                        INT8_C( 113), INT8_C( -30), INT8_C( -24), INT8_C(  69),
                        INT8_C( -15), INT8_C(-110), INT8_C(  23), INT8_C(  87),
                        INT8_C(-127), INT8_C( -64), INT8_C( -38), INT8_C( -83)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -38), INT8_C( -67), INT8_C( -79), INT8_C( -41),
                        INT8_C(-114), INT8_C(  37), INT8_C( -71), INT8_C(  11),
                        INT8_C( 105), INT8_C( 102), INT8_C(  48), INT8_C( 127),
                        INT8_C(  84), INT8_C( 115), INT8_C(-102), INT8_C( -24)),
      simde_mm_set_epi8(INT8_C(  94), INT8_C( -20), INT8_C( -97), INT8_C(  -2),
                        INT8_C(-113), INT8_C(  46), INT8_C( 123), INT8_C(  -9),
                        INT8_C(  35), INT8_C( -47), INT8_C(  90), INT8_C( -73),
                        INT8_C(-122), INT8_C(  -3), INT8_C(-116), INT8_C(  -4)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  27), INT8_C(  41), INT8_C(  36), INT8_C( -97),
                        INT8_C( -84), INT8_C( 108), INT8_C( -37), INT8_C( -69),
                        INT8_C( -29), INT8_C(  45), INT8_C( 101), INT8_C( 104),
                        INT8_C( 102), INT8_C( -85), INT8_C(   3), INT8_C( 124)),
      simde_mm_set_epi8(INT8_C(-119), INT8_C(  16), INT8_C( -80), INT8_C(  97),
                        INT8_C(  97), INT8_C( -44), INT8_C(  71), INT8_C( -43),
                        INT8_C(  39), INT8_C( -54), INT8_C(  15), INT8_C( -61),
                        INT8_C( 100), INT8_C( -92), INT8_C(   5), INT8_C( -93)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  53), INT8_C(  82), INT8_C(  -6), INT8_C(  99),
                        INT8_C(  95), INT8_C( -34), INT8_C( -90), INT8_C( -14),
                        INT8_C( -43), INT8_C( -72), INT8_C( -83), INT8_C(-104),
                        INT8_C(  -1), INT8_C( -60), INT8_C( 103), INT8_C( -66)),
      simde_mm_set_epi8(INT8_C(  13), INT8_C( 118), INT8_C(  25), INT8_C(  60),
                        INT8_C( -83), INT8_C( -43), INT8_C(  90), INT8_C(  54),
                        INT8_C( -84), INT8_C(-125), INT8_C( -41), INT8_C(  52),
                        INT8_C(  18), INT8_C(  46), INT8_C( 126), INT8_C( -65)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  43), INT8_C( 123), INT8_C( -13), INT8_C(  35),
                        INT8_C(-119), INT8_C(  53), INT8_C( -35), INT8_C( -46),
                        INT8_C(  44), INT8_C(  69), INT8_C(  50), INT8_C(-120),
                        INT8_C(   2), INT8_C(  50), INT8_C( -95), INT8_C(  46)),
      simde_mm_set_epi8(INT8_C( -57), INT8_C( -76), INT8_C(-104), INT8_C(-127),
                        INT8_C( -27), INT8_C( 127), INT8_C( 127), INT8_C(-109),
                        INT8_C(  40), INT8_C( -63), INT8_C(  87), INT8_C( -27),
                        INT8_C(  -1), INT8_C(-101), INT8_C(  11), INT8_C(  44)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_cmplt_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-19152), INT16_C(  7219), INT16_C(  8875), INT16_C(-12109),
                         INT16_C( -6164), INT16_C(-29571), INT16_C( 29544), INT16_C( 12828)),
      simde_mm_set_epi16(INT16_C(-19152), INT16_C( -1176), INT16_C(-32721), INT16_C( 28268),
                         INT16_C( 28536), INT16_C(-24890), INT16_C(-20501), INT16_C( 12828)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(  -385), INT16_C( 10411), INT16_C( -4671), INT16_C( 18534),
                         INT16_C( 18234), INT16_C(  8064), INT16_C(-32746), INT16_C(  1460)),
      simde_mm_set_epi16(INT16_C(-11261), INT16_C( 19475), INT16_C( -4671), INT16_C(-23700),
                         INT16_C(  8656), INT16_C(  8064), INT16_C(-28801), INT16_C(  5582)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( 23112), INT16_C( 21760), INT16_C(-29652), INT16_C( -7707),
                         INT16_C(  4438), INT16_C(-14112), INT16_C(   617), INT16_C(-29125)),
      simde_mm_set_epi16(INT16_C(-20847), INT16_C(-17750), INT16_C(  7413), INT16_C( 13270),
                         INT16_C( 30220), INT16_C(-14112), INT16_C(  -140), INT16_C( 23495)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( 12262), INT16_C(-26458), INT16_C(-17793), INT16_C( 15097),
                         INT16_C(-28884), INT16_C(   -39), INT16_C( 29206), INT16_C( 24614)),
      simde_mm_set_epi16(INT16_C(-12392), INT16_C(-30769), INT16_C(-17793), INT16_C( 15097),
                         INT16_C( 22525), INT16_C(  7510), INT16_C( 28529), INT16_C( -9470)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( 14581), INT16_C( 30465), INT16_C( 26611), INT16_C(-25355),
                         INT16_C( 12222), INT16_C(-12322), INT16_C(   176), INT16_C( -4760)),
      simde_mm_set_epi16(INT16_C( 10242), INT16_C( 15750), INT16_C(-11513), INT16_C(  7111),
                         INT16_C(-29171), INT16_C(-12322), INT16_C(   176), INT16_C( -4760)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(-12610), INT16_C( 30415), INT16_C(-22748), INT16_C(  8564),
                         INT16_C(-28400), INT16_C(-22984), INT16_C(-31130), INT16_C(  2400)),
      simde_mm_set_epi16(INT16_C( 17489), INT16_C(-18807), INT16_C( 19401), INT16_C(   -73),
                         INT16_C(-28400), INT16_C( -7356), INT16_C( 31412), INT16_C(  2400)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(  5617), INT16_C( -8984), INT16_C( 20729), INT16_C( 15025),
                         INT16_C(-12038), INT16_C(-32017), INT16_C(-24693), INT16_C( -3874)),
      simde_mm_set_epi16(INT16_C( -8219), INT16_C( 19022), INT16_C(-28515), INT16_C( 15025),
                         INT16_C( -2982), INT16_C(  -314), INT16_C( 16536), INT16_C(-17813)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(  3028), INT16_C( 25056), INT16_C(-30420), INT16_C(  3400),
                         INT16_C( 27498), INT16_C(-24168), INT16_C(-10264), INT16_C( -5651)),
      simde_mm_set_epi16(INT16_C( 16763), INT16_C(  3971), INT16_C(-30420), INT16_C(-13950),
                         INT16_C( 26793), INT16_C(-27284), INT16_C( 22512), INT16_C(-19434)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmplt_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(-1255138253,   581685427,  -403927939,  1936208412),
      simde_mm_set_epi32(  212007784, -2144375188,  1870175942,  1936208412),
      simde_mm_set_epi32(         -1,           0,          -1,           0) },
    { simde_mm_set_epi32(-1412605706,  -573136614,  -789373589,  1859272017),
      simde_mm_set_epi32(-1412605706,  -306100122,  1194991488, -2146040396),
      simde_mm_set_epi32(          0,          -1,          -1,           0) },
    { simde_mm_set_epi32(-1857828629,  -865462431,  1845130162,  -790702535),
      simde_mm_set_epi32( 1020632409,  -786544507,   219144900,   222814568),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32(-1366181206,   485831638,  1980524634,    -9151545),
      simde_mm_set_epi32(-1932199485,   327347510,   706051828,  -541415230),
      simde_mm_set_epi32(          0,           0,           0,           0) },
    { simde_mm_set_epi32(  803641510, -1166066951, -1892876327,  1914069030),
      simde_mm_set_epi32( -812087345, -1002684270,  1476205910,  1869732610),
      simde_mm_set_epi32(          0,          -1,          -1,           0) },
    { simde_mm_set_epi32(-1773657387, -1529382252,  1397468980,  1171964570),
      simde_mm_set_epi32(  955610881,  1744018677,   801034206,  1171964570),
      simde_mm_set_epi32(         -1,          -1,           0,           0) },
    { simde_mm_set_epi32(-1807229965, -1210178631,  1522043695, -1735369601),
      simde_mm_set_epi32(-1560329504,  1101415557,  1311721597,  1371106332),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32( 1146205833,  1271529399,  1661264708,  2058651784),
      simde_mm_set_epi32(  624079870,  1320739553, -1066082248, -1119644266),
      simde_mm_set_epi32(          0,          -1,           0,           0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmplt_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  415.53), SIMDE_FLOAT64_C(  -98.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.53), SIMDE_FLOAT64_C( -729.13)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -102.02), SIMDE_FLOAT64_C( -129.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  345.59), SIMDE_FLOAT64_C( -901.28)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  733.11), SIMDE_FLOAT64_C(  268.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  733.11), SIMDE_FLOAT64_C(  632.42)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  988.26), SIMDE_FLOAT64_C(    0.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -735.83), SIMDE_FLOAT64_C(  857.46)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  631.80), SIMDE_FLOAT64_C(  -84.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  596.99), SIMDE_FLOAT64_C(  -84.12)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  633.74), SIMDE_FLOAT64_C(  134.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -981.15), SIMDE_FLOAT64_C( -897.95)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  995.74), SIMDE_FLOAT64_C( -864.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -773.77), SIMDE_FLOAT64_C( -294.67)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -847.57), SIMDE_FLOAT64_C(  363.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  743.31), SIMDE_FLOAT64_C( -671.22)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmplt_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmplt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  884.89), SIMDE_FLOAT64_C( -700.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  194.09), SIMDE_FLOAT64_C(  342.08)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  884.89), SIMDE_FLOAT64_C( -700.86)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -552.29), SIMDE_FLOAT64_C( -477.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -288.53), SIMDE_FLOAT64_C( -439.96)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -552.29), SIMDE_FLOAT64_C( -477.43)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -25.82), SIMDE_FLOAT64_C( -940.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  251.57), SIMDE_FLOAT64_C(  618.81)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  -25.82), SIMDE_FLOAT64_C( -940.19)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -905.83), SIMDE_FLOAT64_C(  120.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -235.64), SIMDE_FLOAT64_C( -293.77)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -905.83), SIMDE_FLOAT64_C(  120.16)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  804.90), SIMDE_FLOAT64_C(  266.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -104.58), SIMDE_FLOAT64_C( -965.81)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  804.90), SIMDE_FLOAT64_C(  266.33)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   44.09), SIMDE_FLOAT64_C( -365.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  534.45), SIMDE_FLOAT64_C( -718.87)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   44.09), SIMDE_FLOAT64_C( -365.90)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -108.03), SIMDE_FLOAT64_C(  233.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -420.51), SIMDE_FLOAT64_C( -879.83)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -108.03), SIMDE_FLOAT64_C(  233.20)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -399.23), SIMDE_FLOAT64_C(  758.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -334.35), SIMDE_FLOAT64_C( -250.33)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -399.23), SIMDE_FLOAT64_C(  758.04)), simde_mm_setzero_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmplt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnlt_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  852.01), SIMDE_FLOAT64_C( -875.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  852.01), SIMDE_FLOAT64_C( -124.49)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  396.43), SIMDE_FLOAT64_C( -754.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  396.43), SIMDE_FLOAT64_C( -446.22)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  253.13), SIMDE_FLOAT64_C(  198.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  253.13), SIMDE_FLOAT64_C(  828.60)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  137.84), SIMDE_FLOAT64_C( -995.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  137.84), SIMDE_FLOAT64_C( -366.89)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  981.94), SIMDE_FLOAT64_C( -371.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -999.24), SIMDE_FLOAT64_C(  567.77)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.23), SIMDE_FLOAT64_C( -984.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.65), SIMDE_FLOAT64_C(  102.67)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -625.86), SIMDE_FLOAT64_C(  -91.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -928.96), SIMDE_FLOAT64_C( -311.29)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -444.22), SIMDE_FLOAT64_C(  458.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.56), SIMDE_FLOAT64_C(  290.13)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpnlt_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnlt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -713.31), SIMDE_FLOAT64_C( -162.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -134.78), SIMDE_FLOAT64_C( -333.93)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -713.31), SIMDE_FLOAT64_C( -162.56)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  903.93), SIMDE_FLOAT64_C(  249.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  300.72), SIMDE_FLOAT64_C( -642.46)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  903.93), SIMDE_FLOAT64_C(  249.58)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -697.34), SIMDE_FLOAT64_C(   79.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -123.52), SIMDE_FLOAT64_C( -418.48)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -697.34), SIMDE_FLOAT64_C(   79.67)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   90.71), SIMDE_FLOAT64_C( -449.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  629.69), SIMDE_FLOAT64_C(  449.98)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   90.71), SIMDE_FLOAT64_C( -449.42)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  751.69), SIMDE_FLOAT64_C( -170.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -991.25), SIMDE_FLOAT64_C(  129.62)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  751.69), SIMDE_FLOAT64_C( -170.45)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  961.53), SIMDE_FLOAT64_C( -601.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -458.00), SIMDE_FLOAT64_C( -521.61)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  961.53), SIMDE_FLOAT64_C( -601.03)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -697.78), SIMDE_FLOAT64_C(  908.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -418.87), SIMDE_FLOAT64_C(  253.38)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -697.78), SIMDE_FLOAT64_C(  908.22)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  897.84), SIMDE_FLOAT64_C(   98.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  743.55), SIMDE_FLOAT64_C( -417.08)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  897.84), SIMDE_FLOAT64_C(   98.86)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnlt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmple_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  543.54), SIMDE_FLOAT64_C( -463.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  803.80), SIMDE_FLOAT64_C( -383.88)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -420.41), SIMDE_FLOAT64_C(  497.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.95), SIMDE_FLOAT64_C( -224.51)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -921.01), SIMDE_FLOAT64_C( -601.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -921.01), SIMDE_FLOAT64_C( -730.20)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -456.56), SIMDE_FLOAT64_C(  380.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -456.56), SIMDE_FLOAT64_C(  380.21)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  317.08), SIMDE_FLOAT64_C(  136.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  944.53), SIMDE_FLOAT64_C(  370.42)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -193.09), SIMDE_FLOAT64_C(  515.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.27), SIMDE_FLOAT64_C(  515.21)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.93), SIMDE_FLOAT64_C(  166.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   14.93), SIMDE_FLOAT64_C( -633.50)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  121.98), SIMDE_FLOAT64_C( -542.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  121.98), SIMDE_FLOAT64_C( -244.93)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmple_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmple_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -6.97), SIMDE_FLOAT64_C( -531.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  442.04), SIMDE_FLOAT64_C(  237.56)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   -6.97), SIMDE_FLOAT64_C( -531.93)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  953.55), SIMDE_FLOAT64_C( -668.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   75.21), SIMDE_FLOAT64_C( -841.44)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  953.55), SIMDE_FLOAT64_C( -668.52)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -962.44), SIMDE_FLOAT64_C(  733.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  366.34), SIMDE_FLOAT64_C(  744.84)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -962.44), SIMDE_FLOAT64_C(  733.31)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  546.64), SIMDE_FLOAT64_C(  333.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  540.77), SIMDE_FLOAT64_C(   -0.80)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  546.64), SIMDE_FLOAT64_C(  333.17)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -407.18), SIMDE_FLOAT64_C( -763.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  973.34), SIMDE_FLOAT64_C( -496.03)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -407.18), SIMDE_FLOAT64_C( -763.20)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  407.82), SIMDE_FLOAT64_C(  479.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  198.41), SIMDE_FLOAT64_C(  710.05)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  407.82), SIMDE_FLOAT64_C(  479.81)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -282.72), SIMDE_FLOAT64_C( -348.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  165.84), SIMDE_FLOAT64_C( -951.18)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -282.72), SIMDE_FLOAT64_C( -348.78)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  642.13), SIMDE_FLOAT64_C( -574.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -633.14), SIMDE_FLOAT64_C(  741.95)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  642.13), SIMDE_FLOAT64_C( -574.77)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmple_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnle_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.93), SIMDE_FLOAT64_C( -877.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.93), SIMDE_FLOAT64_C(   61.42)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  567.19), SIMDE_FLOAT64_C(  768.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -689.51), SIMDE_FLOAT64_C(  768.82)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  625.00), SIMDE_FLOAT64_C(  979.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   59.83), SIMDE_FLOAT64_C(  979.36)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -994.58), SIMDE_FLOAT64_C(  130.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -720.49), SIMDE_FLOAT64_C(  130.45)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  889.79), SIMDE_FLOAT64_C( -677.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  889.79), SIMDE_FLOAT64_C( -677.25)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  802.11), SIMDE_FLOAT64_C( -926.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -136.48), SIMDE_FLOAT64_C( -926.46)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -579.79), SIMDE_FLOAT64_C(  368.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -579.79), SIMDE_FLOAT64_C( -736.86)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  408.86), SIMDE_FLOAT64_C(   63.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  408.86), SIMDE_FLOAT64_C(  878.02)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpnle_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnle_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  863.30), SIMDE_FLOAT64_C(  817.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  465.11), SIMDE_FLOAT64_C(  402.99)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  863.30), SIMDE_FLOAT64_C(  817.71)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  189.40), SIMDE_FLOAT64_C( -607.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -476.72), SIMDE_FLOAT64_C( -670.93)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  189.40), SIMDE_FLOAT64_C( -607.91)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -333.27), SIMDE_FLOAT64_C(  662.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  741.44), SIMDE_FLOAT64_C( -212.71)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -333.27), SIMDE_FLOAT64_C(  662.88)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  426.15), SIMDE_FLOAT64_C( -964.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   54.04), SIMDE_FLOAT64_C(  321.51)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  426.15), SIMDE_FLOAT64_C( -964.01)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -797.48), SIMDE_FLOAT64_C(  851.48)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  907.15), SIMDE_FLOAT64_C(  638.76)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -797.48), SIMDE_FLOAT64_C(  851.48)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  439.23), SIMDE_FLOAT64_C(  238.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -23.09), SIMDE_FLOAT64_C(  160.20)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  439.23), SIMDE_FLOAT64_C(  238.01)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  537.28), SIMDE_FLOAT64_C(  982.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  303.40), SIMDE_FLOAT64_C(  928.78)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  537.28), SIMDE_FLOAT64_C(  982.90)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -169.84), SIMDE_FLOAT64_C( -696.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -302.24), SIMDE_FLOAT64_C( -382.83)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -169.84), SIMDE_FLOAT64_C( -696.10)), simde_mm_setzero_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnle_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  13), INT8_C( -99), INT8_C(-128), INT8_C(  91), INT8_C( -96), INT8_C( 103), INT8_C(-104), INT8_C(-110),
                        INT8_C( -46), INT8_C(  -5), INT8_C(  62), INT8_C(-125), INT8_C( -51), INT8_C( -65), INT8_C(-102), INT8_C( -14)),
      simde_mm_set_epi8(INT8_C(  10), INT8_C( -84), INT8_C(  90), INT8_C(-110), INT8_C( 113), INT8_C( -34), INT8_C( -75), INT8_C(-110),
                        INT8_C( -79), INT8_C(-114), INT8_C(  26), INT8_C(-127), INT8_C(  -5), INT8_C(  -9), INT8_C(-102), INT8_C( -38)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(-110), INT8_C( -93), INT8_C( 106), INT8_C( -55), INT8_C(  91), INT8_C( -78), INT8_C(  69), INT8_C(  62),
                        INT8_C(  38), INT8_C(-101), INT8_C(  86), INT8_C(-107), INT8_C( 114), INT8_C( 120), INT8_C(-118), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C(  58), INT8_C( -88), INT8_C(  75), INT8_C( -55), INT8_C(  92), INT8_C(  51), INT8_C(-109), INT8_C(  62),
                        INT8_C( 123), INT8_C( -42), INT8_C(   0), INT8_C(  40), INT8_C( 114), INT8_C(-115), INT8_C(  34), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  79), INT8_C(  -2), INT8_C(-126), INT8_C(-121), INT8_C(  71), INT8_C( -59), INT8_C(  95), INT8_C(  38),
                        INT8_C( -95), INT8_C( 103), INT8_C( -55), INT8_C( -42), INT8_C(-124), INT8_C( -82), INT8_C( 102), INT8_C(  97)),
      simde_mm_set_epi8(INT8_C( -39), INT8_C( -59), INT8_C(-126), INT8_C(-107), INT8_C(-111), INT8_C( 122), INT8_C( -55), INT8_C(  87),
                        INT8_C( -95), INT8_C( -99), INT8_C(  56), INT8_C( 120), INT8_C( 107), INT8_C( -79), INT8_C(  -9), INT8_C( -36)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -68), INT8_C(   7), INT8_C( -32), INT8_C( 120), INT8_C(-106), INT8_C(-127), INT8_C(  37), INT8_C(  95),
                        INT8_C( -77), INT8_C(-126), INT8_C(-111), INT8_C( -96), INT8_C(  67), INT8_C(  43), INT8_C(-123), INT8_C(  21)),
      simde_mm_set_epi8(INT8_C(  72), INT8_C(  68), INT8_C(  76), INT8_C( -22), INT8_C( -11), INT8_C(  34), INT8_C( 112), INT8_C(  95),
                        INT8_C( -77), INT8_C(  36), INT8_C( 119), INT8_C( -59), INT8_C( -49), INT8_C( -22), INT8_C(-125), INT8_C(  21)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -18), INT8_C(  13), INT8_C(  66), INT8_C( -52), INT8_C( -92), INT8_C(  28), INT8_C(-122), INT8_C( -12),
                        INT8_C( -60), INT8_C( 125), INT8_C(-104), INT8_C(-118), INT8_C( -76), INT8_C(  42), INT8_C( -48), INT8_C(-120)),
      simde_mm_set_epi8(INT8_C( -17), INT8_C(  13), INT8_C(  66), INT8_C( -64), INT8_C( -92), INT8_C( 114), INT8_C(-119), INT8_C(-106),
                        INT8_C(  78), INT8_C(-125), INT8_C(  88), INT8_C( -88), INT8_C( 101), INT8_C(  42), INT8_C( -58), INT8_C(  -8)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(-112), INT8_C( -16), INT8_C(  96), INT8_C( -64), INT8_C(  75), INT8_C(  56), INT8_C( -96), INT8_C(  96),
                        INT8_C(  -8), INT8_C(  16), INT8_C(  95), INT8_C(  41), INT8_C(  62), INT8_C(  -2), INT8_C(-105), INT8_C(-101)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(   7), INT8_C(  90), INT8_C( -93), INT8_C(  75), INT8_C(  14), INT8_C(  -5), INT8_C(  61),
                        INT8_C(  -8), INT8_C( -49), INT8_C(  95), INT8_C(  82), INT8_C( -93), INT8_C( -80), INT8_C(   6), INT8_C( -48)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -56), INT8_C( -85), INT8_C(   9), INT8_C(   3), INT8_C(  32), INT8_C(-105), INT8_C(  93), INT8_C( -78),
                        INT8_C(-113), INT8_C(  96), INT8_C(  61), INT8_C(  14), INT8_C( -92), INT8_C(  53), INT8_C(  51), INT8_C(  -7)),
      simde_mm_set_epi8(INT8_C(  15), INT8_C( 100), INT8_C(   9), INT8_C(  70), INT8_C(-115), INT8_C(-105), INT8_C(  14), INT8_C( -41),
                        INT8_C(-113), INT8_C( -54), INT8_C( -38), INT8_C(  14), INT8_C( -53), INT8_C(   5), INT8_C(-127), INT8_C(  -7)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 120), INT8_C(  38), INT8_C(  44), INT8_C( 103), INT8_C(  33), INT8_C( -93), INT8_C(-102), INT8_C( -46),
                        INT8_C(  47), INT8_C(   7), INT8_C( 120), INT8_C( 102), INT8_C( -87), INT8_C( -84), INT8_C(  92), INT8_C(  87)),
      simde_mm_set_epi8(INT8_C( -11), INT8_C(  89), INT8_C(  26), INT8_C(  69), INT8_C( 108), INT8_C( 127), INT8_C(-102), INT8_C(  49),
                        INT8_C(  53), INT8_C(  57), INT8_C( 120), INT8_C( -23), INT8_C( -87), INT8_C( -84), INT8_C( 113), INT8_C( -36)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_cmpgt_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 11481), INT16_C(-31028), INT16_C(-28938), INT16_C(  3434),
                         INT16_C(  2523), INT16_C(-16298), INT16_C(-20752), INT16_C( -3418)),
      simde_mm_set_epi16(INT16_C( 11481), INT16_C(-30562), INT16_C(  4762), INT16_C( -6519),
                         INT16_C(  2523), INT16_C(  9845), INT16_C(   -18), INT16_C( -5787)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( -3487), INT16_C( -2281), INT16_C(  2722), INT16_C(-23699),
                         INT16_C( -5087), INT16_C( 24907), INT16_C( 26126), INT16_C( 26357)),
      simde_mm_set_epi16(INT16_C( 32178), INT16_C(-24562), INT16_C( -3261), INT16_C(-23699),
                         INT16_C(  2431), INT16_C(-16600), INT16_C( -5679), INT16_C(-12625)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( 28908), INT16_C( -8639), INT16_C(-27999), INT16_C(-19726),
                         INT16_C( 28446), INT16_C(  -947), INT16_C( -9756), INT16_C(-32088)),
      simde_mm_set_epi16(INT16_C(-24056), INT16_C(-13026), INT16_C(-27999), INT16_C( 27584),
                         INT16_C(-22292), INT16_C( 18403), INT16_C(-15329), INT16_C( 30515)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                         INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( 32500), INT16_C( 28770), INT16_C(-12789), INT16_C(   764),
                         INT16_C(-17186), INT16_C(  5823), INT16_C(  5923), INT16_C(-14898)),
      simde_mm_set_epi16(INT16_C(  5264), INT16_C(-27897), INT16_C(-22472), INT16_C(-17764),
                         INT16_C( 20191), INT16_C( 20077), INT16_C(-20539), INT16_C( -7345)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(-32420), INT16_C(-10018), INT16_C( 10034), INT16_C( 21195),
                         INT16_C( 23576), INT16_C( 23578), INT16_C( 27261), INT16_C( 22728)),
      simde_mm_set_epi16(INT16_C(-22785), INT16_C(  9581), INT16_C( -7653), INT16_C(-22519),
                         INT16_C(  2089), INT16_C( 10927), INT16_C( 31136), INT16_C( 28081)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( -8613), INT16_C( 14814), INT16_C( 25977), INT16_C(-32026),
                         INT16_C(-14164), INT16_C( 15788), INT16_C( 26276), INT16_C(-23351)),
      simde_mm_set_epi16(INT16_C( 18907), INT16_C( 31050), INT16_C( 25483), INT16_C( -1544),
                         INT16_C(-22377), INT16_C(-30002), INT16_C( 26276), INT16_C(-21368)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( -8616), INT16_C( 18300), INT16_C(-13448), INT16_C(-25384),
                         INT16_C(-20778), INT16_C(  9404), INT16_C( 18457), INT16_C(-13013)),
      simde_mm_set_epi16(INT16_C( 28965), INT16_C(-22807), INT16_C( 20081), INT16_C(-25384),
                         INT16_C( 21664), INT16_C(-19420), INT16_C(-10494), INT16_C(  8092)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(-19643), INT16_C( 19578), INT16_C(-31344), INT16_C(-10120),
                         INT16_C( -1042), INT16_C( 26214), INT16_C(  7476), INT16_C( 19171)),
      simde_mm_set_epi16(INT16_C(  3338), INT16_C(-31811), INT16_C( 23264), INT16_C( 16135),
                         INT16_C( 10963), INT16_C( 28585), INT16_C( 10267), INT16_C( 15982)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpgt_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  752453324, -1896477334,   165396566, -1359940954),
      simde_mm_set_epi32(  752453324,   312141449, -1431099787,    -1119899),
      simde_mm_set_epi32(          0,           0,          -1,           0) },
    { simde_mm_set_epi32(  107153560,  1681238316, -2021152487, -1327623679),
      simde_mm_set_epi32( -228460777,   178430829,  -333356725,  1712219893),
      simde_mm_set_epi32(         -1,          -1,           0,           0) },
    { simde_mm_set_epi32( -899341348, -1183976764,    50756911,  -774436817),
      simde_mm_set_epi32( -899341348, -1675909702,    50756911,   393145285),
      simde_mm_set_epi32(          0,          -1,           0,           0) },
    { simde_mm_set_epi32(-1576481506,   693332928, -1460910109, -1004570829),
      simde_mm_set_epi32(-1038801032, -1159952439, -1460910109,   -43665635),
      simde_mm_set_epi32(          0,          -1,           0,           0) },
    { simde_mm_set_epi32( 2129948770,  -838139140, -1126295873,   388220366),
      simde_mm_set_epi32(  345019143, -1472677220,  1323257453, -1345985713),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32(  324758156,  1228690576, -1773311089,   254589418),
      simde_mm_set_epi32(-2124621602,  1228690576,  1545100314,  1786599624),
      simde_mm_set_epi32(         -1,           0,           0,           0) },
    { simde_mm_set_epi32(-1939857174,   351576089,    62939556, -1061610170),
      simde_mm_set_epi32(-1899113305,  1851167226,    62939556, -2109881445),
      simde_mm_set_epi32(          0,           0,           0,          -1) },
    { simde_mm_set_epi32( 1239120202,  1670117880, -1466463538,  1932307592),
      simde_mm_set_epi32( 1694384857,    79202881,  -114087446,  -617386644),
      simde_mm_set_epi32(          0,          -1,           0,          -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpgt_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -649.61), SIMDE_FLOAT64_C(  366.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  333.59), SIMDE_FLOAT64_C(  116.88)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -619.22), SIMDE_FLOAT64_C( -854.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -854.79), SIMDE_FLOAT64_C(  863.33)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.10), SIMDE_FLOAT64_C(  381.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  844.77), SIMDE_FLOAT64_C( -217.11)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -925.79), SIMDE_FLOAT64_C( -916.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.99), SIMDE_FLOAT64_C(  826.72)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  639.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  448.67)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C( -582.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C(  186.24)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  532.21), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -677.14), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  459.86), SIMDE_FLOAT64_C(  265.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.43), SIMDE_FLOAT64_C(  334.48)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpgt_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpgt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  482.46), SIMDE_FLOAT64_C(   39.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  175.75), SIMDE_FLOAT64_C( -451.08)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  482.46), SIMDE_FLOAT64_C(   39.32)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  850.79), SIMDE_FLOAT64_C(  999.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -978.35), SIMDE_FLOAT64_C(  216.37)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  850.79), SIMDE_FLOAT64_C(  999.92)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -218.27), SIMDE_FLOAT64_C(  952.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -402.87), SIMDE_FLOAT64_C( -852.22)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -218.27), SIMDE_FLOAT64_C(  952.36)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -324.97), SIMDE_FLOAT64_C(  -18.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -602.36), SIMDE_FLOAT64_C(  488.60)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -324.97), SIMDE_FLOAT64_C(  -18.67)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -224.88), SIMDE_FLOAT64_C(  278.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  861.73), SIMDE_FLOAT64_C( -326.54)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -224.88), SIMDE_FLOAT64_C(  278.88)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -160.74), SIMDE_FLOAT64_C(  611.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  370.13), SIMDE_FLOAT64_C(   18.16)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -160.74), SIMDE_FLOAT64_C(  611.30)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  914.20), SIMDE_FLOAT64_C(  278.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  703.64), SIMDE_FLOAT64_C( -975.84)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  914.20), SIMDE_FLOAT64_C(  278.69)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  392.89), SIMDE_FLOAT64_C(   45.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  713.78), SIMDE_FLOAT64_C(   -6.71)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  392.89), SIMDE_FLOAT64_C(   45.41)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpgt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpngt_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C( -195.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C(   18.27)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -563.65), SIMDE_FLOAT64_C(  884.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  467.71), SIMDE_FLOAT64_C( -906.63)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -553.85), SIMDE_FLOAT64_C(   49.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  731.88), SIMDE_FLOAT64_C(  974.91)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  492.98), SIMDE_FLOAT64_C(   64.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -392.36), SIMDE_FLOAT64_C( -188.43)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -248.75), SIMDE_FLOAT64_C( -404.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -495.92), SIMDE_FLOAT64_C( -819.81)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -932.57), SIMDE_FLOAT64_C(  741.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -307.42), SIMDE_FLOAT64_C(  170.69)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.20), SIMDE_FLOAT64_C( -314.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  138.12), SIMDE_FLOAT64_C(  517.19)),
      simde_x_mm_setone_pd() }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpngt_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpngt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -695.66), SIMDE_FLOAT64_C(  678.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  356.43), SIMDE_FLOAT64_C(  495.31)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -695.66), SIMDE_FLOAT64_C(  678.35)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -72.63), SIMDE_FLOAT64_C(  895.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -885.88), SIMDE_FLOAT64_C(  947.04)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  -72.63), SIMDE_FLOAT64_C(  895.56)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   72.92), SIMDE_FLOAT64_C( -711.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -242.49), SIMDE_FLOAT64_C( -686.51)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   72.92), SIMDE_FLOAT64_C( -711.12)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  520.17), SIMDE_FLOAT64_C(  176.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -442.78), SIMDE_FLOAT64_C( -956.19)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  520.17), SIMDE_FLOAT64_C(  176.32)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  949.11), SIMDE_FLOAT64_C(  112.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -212.07), SIMDE_FLOAT64_C(  851.84)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  949.11), SIMDE_FLOAT64_C(  112.35)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -142.01), SIMDE_FLOAT64_C( -216.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -467.63), SIMDE_FLOAT64_C(  481.36)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -142.01), SIMDE_FLOAT64_C( -216.70)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  918.90), SIMDE_FLOAT64_C(  481.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -147.11), SIMDE_FLOAT64_C(  677.03)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  918.90), SIMDE_FLOAT64_C(  481.59)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -143.49), SIMDE_FLOAT64_C(  447.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   50.06), SIMDE_FLOAT64_C(  827.25)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -143.49), SIMDE_FLOAT64_C(  447.22)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpngt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpge_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -649.61), SIMDE_FLOAT64_C(  366.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  333.59), SIMDE_FLOAT64_C(  116.88)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -619.22), SIMDE_FLOAT64_C( -854.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -854.79), SIMDE_FLOAT64_C(  863.33)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.10), SIMDE_FLOAT64_C(  381.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  844.77), SIMDE_FLOAT64_C( -217.11)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -925.79), SIMDE_FLOAT64_C( -916.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.99), SIMDE_FLOAT64_C(  826.72)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  639.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  448.67)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C( -582.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C(  186.24)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  532.21), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -677.14), SIMDE_FLOAT64_C(  145.56)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  459.86), SIMDE_FLOAT64_C(  265.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.43), SIMDE_FLOAT64_C(  334.48)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpge_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpge_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -315.45), SIMDE_FLOAT64_C(  193.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -204.45), SIMDE_FLOAT64_C(  887.13)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -315.45), SIMDE_FLOAT64_C(  193.79)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -670.47), SIMDE_FLOAT64_C(  937.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  343.22), SIMDE_FLOAT64_C( -308.01)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -670.47), SIMDE_FLOAT64_C(  937.31)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -903.63), SIMDE_FLOAT64_C( -850.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -838.64), SIMDE_FLOAT64_C( -936.46)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -903.63), SIMDE_FLOAT64_C( -850.53)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  236.33), SIMDE_FLOAT64_C(  126.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  872.82), SIMDE_FLOAT64_C( -512.42)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  236.33), SIMDE_FLOAT64_C(  126.98)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  811.87), SIMDE_FLOAT64_C(  -15.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -983.99), SIMDE_FLOAT64_C(  351.32)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  811.87), SIMDE_FLOAT64_C(  -15.62)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   42.47), SIMDE_FLOAT64_C( -523.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  286.68), SIMDE_FLOAT64_C(  254.00)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   42.47), SIMDE_FLOAT64_C( -523.00)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -219.91), SIMDE_FLOAT64_C( -253.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -554.73), SIMDE_FLOAT64_C(  225.44)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -219.91), SIMDE_FLOAT64_C( -253.29)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -901.30), SIMDE_FLOAT64_C( -538.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -584.99), SIMDE_FLOAT64_C(   91.26)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -901.30), SIMDE_FLOAT64_C( -538.38)), simde_mm_setzero_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpge_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnge_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C( -195.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C(   18.27)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -563.65), SIMDE_FLOAT64_C(  884.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  467.71), SIMDE_FLOAT64_C( -906.63)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -553.85), SIMDE_FLOAT64_C(   49.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  731.88), SIMDE_FLOAT64_C(  974.91)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  492.98), SIMDE_FLOAT64_C(   64.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -392.36), SIMDE_FLOAT64_C( -188.43)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -248.75), SIMDE_FLOAT64_C( -404.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -495.92), SIMDE_FLOAT64_C( -819.81)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -932.57), SIMDE_FLOAT64_C(  741.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -307.42), SIMDE_FLOAT64_C(  170.69)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.20), SIMDE_FLOAT64_C( -314.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  138.12), SIMDE_FLOAT64_C(  517.19)),
      simde_x_mm_setone_pd() }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnge_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpnge_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -695.66), SIMDE_FLOAT64_C(  678.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  356.43), SIMDE_FLOAT64_C(  495.31)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -695.66), SIMDE_FLOAT64_C(  678.35)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -72.63), SIMDE_FLOAT64_C(  895.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -885.88), SIMDE_FLOAT64_C(  947.04)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  -72.63), SIMDE_FLOAT64_C(  895.56)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   72.92), SIMDE_FLOAT64_C( -711.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -242.49), SIMDE_FLOAT64_C( -686.51)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(   72.92), SIMDE_FLOAT64_C( -711.12)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  520.17), SIMDE_FLOAT64_C(  176.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -442.78), SIMDE_FLOAT64_C( -956.19)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  520.17), SIMDE_FLOAT64_C(  176.32)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  949.11), SIMDE_FLOAT64_C(  112.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -212.07), SIMDE_FLOAT64_C(  851.84)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  949.11), SIMDE_FLOAT64_C(  112.35)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -142.01), SIMDE_FLOAT64_C( -216.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -467.63), SIMDE_FLOAT64_C(  481.36)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -142.01), SIMDE_FLOAT64_C( -216.70)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  918.90), SIMDE_FLOAT64_C(  481.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -147.11), SIMDE_FLOAT64_C(  677.03)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  918.90), SIMDE_FLOAT64_C(  481.59)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -143.49), SIMDE_FLOAT64_C(  447.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   50.06), SIMDE_FLOAT64_C(  827.25)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -143.49), SIMDE_FLOAT64_C(  447.22)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnge_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpord_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  107.72), SIMDE_FLOAT64_C( -915.48)),
      simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_FLOAT64_C( -303.84)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  173.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -817.33), SIMDE_FLOAT64_C(  659.40)),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -425.32), SIMDE_FLOAT64_C(  993.95)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -650.75), SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_FLOAT64_C( -971.81)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -761.29), SIMDE_FLOAT64_C( -694.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -709.09), SIMDE_FLOAT64_C(  614.12)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  498.19), SIMDE_FLOAT64_C( -379.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -247.48), SIMDE_FLOAT64_C( -578.21)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  101.51), SIMDE_FLOAT64_C(  387.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  215.97), SIMDE_FLOAT64_C(  173.76)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  729.13), SIMDE_FLOAT64_C(  771.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  902.43), SIMDE_FLOAT64_C( -416.43)),
      simde_x_mm_setone_pd() }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpord_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpord_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  602.71), SIMDE_FLOAT64_C( -732.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  116.21), SIMDE_FLOAT64_C( -560.07)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  602.71), SIMDE_FLOAT64_C( -732.62)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  947.95), SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.03), SIMDE_FLOAT64_C(  -86.78)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  947.95), SIMDE_FLOAT64_C(  775.29)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -455.06), SIMDE_FLOAT64_C(  579.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -960.88), SIMDE_MATH_NAN),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -455.06), SIMDE_FLOAT64_C(  579.65)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  782.89), SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -540.96), SIMDE_MATH_NAN),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  782.89), SIMDE_FLOAT64_C( -266.22)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -750.41), SIMDE_FLOAT64_C( -624.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -599.13), SIMDE_FLOAT64_C(  704.00)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -750.41), SIMDE_FLOAT64_C( -624.09)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  149.22), SIMDE_FLOAT64_C( -876.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  871.40), SIMDE_FLOAT64_C(  321.55)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  149.22), SIMDE_FLOAT64_C( -876.24)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -822.79), SIMDE_FLOAT64_C(  890.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -260.78), SIMDE_FLOAT64_C(  386.76)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -822.79), SIMDE_FLOAT64_C(  890.31)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -370.89), SIMDE_FLOAT64_C( -622.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  587.16), SIMDE_FLOAT64_C( -811.86)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -370.89), SIMDE_FLOAT64_C( -622.25)), simde_x_mm_setone_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpord_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpunord_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  670.49)),
      simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  826.75)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -774.95), SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  247.71), SIMDE_MATH_NAN),
      simde_mm_move_sd(simde_mm_setzero_pd(), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -88.77), SIMDE_FLOAT64_C(  116.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -32.79), SIMDE_FLOAT64_C( -442.07)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   71.71), SIMDE_FLOAT64_C(  549.42)),
      simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_FLOAT64_C( -288.27)),
      simde_mm_move_sd(simde_x_mm_setone_pd(), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -266.24), SIMDE_FLOAT64_C( -147.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  900.46), SIMDE_FLOAT64_C( -288.71)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  196.30), SIMDE_MATH_NAN),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -447.36), SIMDE_FLOAT64_C(  236.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -774.85), SIMDE_FLOAT64_C( -611.68)),
      simde_mm_setzero_pd() },
    { simde_mm_set_pd(SIMDE_MATH_NAN, SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  711.66), SIMDE_FLOAT64_C( -751.40)),
      simde_x_mm_setone_pd() }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpunord_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cmpunord_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -580.90), SIMDE_FLOAT64_C(  757.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -779.63), SIMDE_FLOAT64_C(   96.79)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -580.90), SIMDE_FLOAT64_C(  757.46)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.89), SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  751.46), SIMDE_FLOAT64_C(  753.64)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -607.89), SIMDE_FLOAT64_C( -882.75)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  177.62), SIMDE_FLOAT64_C( -618.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -958.41), SIMDE_MATH_NAN),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  177.62), SIMDE_FLOAT64_C( -618.39)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  910.88), SIMDE_MATH_NAN),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -924.01), SIMDE_MATH_NAN),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  910.88), SIMDE_FLOAT64_C(  313.76)), simde_x_mm_setone_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -778.12), SIMDE_FLOAT64_C( -472.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  400.92), SIMDE_FLOAT64_C( -453.41)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -778.12), SIMDE_FLOAT64_C( -472.40)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  933.47), SIMDE_FLOAT64_C( -426.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  836.37), SIMDE_FLOAT64_C(  329.66)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C(  933.47), SIMDE_FLOAT64_C( -426.60)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -563.76), SIMDE_FLOAT64_C(  455.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -169.32), SIMDE_FLOAT64_C( -459.10)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -563.76), SIMDE_FLOAT64_C(  455.35)), simde_mm_setzero_pd()) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -117.48), SIMDE_FLOAT64_C( -934.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  177.09), SIMDE_FLOAT64_C(  194.89)),
      simde_mm_move_sd(simde_mm_set_pd(SIMDE_FLOAT64_C( -117.48), SIMDE_FLOAT64_C( -934.82)), simde_mm_setzero_pd()) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpunord_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comieq_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -969.61), SIMDE_FLOAT64_C(  839.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -969.61), SIMDE_FLOAT64_C( -432.69)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  281.50), SIMDE_FLOAT64_C( -752.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  281.50), SIMDE_FLOAT64_C( -752.55)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  590.09), SIMDE_FLOAT64_C(  270.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -206.33), SIMDE_FLOAT64_C(  270.42)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  412.70), SIMDE_FLOAT64_C( -500.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  145.06), SIMDE_FLOAT64_C(  763.45)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -374.23), SIMDE_FLOAT64_C(  380.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -374.23), SIMDE_FLOAT64_C(  380.82)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -875.64), SIMDE_FLOAT64_C(   30.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -823.83), SIMDE_FLOAT64_C(   30.13)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.78), SIMDE_FLOAT64_C( -652.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  719.69), SIMDE_FLOAT64_C( -685.53)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  740.88), SIMDE_FLOAT64_C(  116.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -528.65), SIMDE_FLOAT64_C(  536.46)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comieq_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comige_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comige_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comigt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comigt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comile_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comile_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comilt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  766.54), SIMDE_FLOAT64_C(  -69.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  185.38), SIMDE_FLOAT64_C(  -69.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  489.65), SIMDE_FLOAT64_C(  372.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  489.65), SIMDE_FLOAT64_C(  372.98)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   79.48), SIMDE_FLOAT64_C( -168.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -648.03), SIMDE_FLOAT64_C( -710.04)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  907.60), SIMDE_FLOAT64_C(  955.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  907.60), SIMDE_FLOAT64_C( -965.39)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -237.33), SIMDE_FLOAT64_C(  558.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.12), SIMDE_FLOAT64_C(  558.83)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -796.13), SIMDE_FLOAT64_C(   18.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -796.13), SIMDE_FLOAT64_C(   18.69)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -380.36), SIMDE_FLOAT64_C( -737.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -380.36), SIMDE_FLOAT64_C( -737.73)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -975.15), SIMDE_FLOAT64_C( -296.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -975.15), SIMDE_FLOAT64_C( -296.93)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comilt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_comineq_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comineq_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_copysign_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 dest[2];
    const simde_float64 src[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -182.01), SIMDE_FLOAT64_C(   309.30) },
      { SIMDE_FLOAT64_C(  -125.98), SIMDE_FLOAT64_C(  -334.42) },
      { SIMDE_FLOAT64_C(  -182.01), SIMDE_FLOAT64_C(  -309.30) } },
    { { SIMDE_FLOAT64_C(  -339.97), SIMDE_FLOAT64_C(  -147.14) },
      { SIMDE_FLOAT64_C(   534.39), SIMDE_FLOAT64_C(  -377.91) },
      { SIMDE_FLOAT64_C(   339.97), SIMDE_FLOAT64_C(  -147.14) } },
    { { SIMDE_FLOAT64_C(  -466.30), SIMDE_FLOAT64_C(   794.64) },
      { SIMDE_FLOAT64_C(   936.51), SIMDE_FLOAT64_C(  -627.08) },
      { SIMDE_FLOAT64_C(   466.30), SIMDE_FLOAT64_C(  -794.64) } },
    { { SIMDE_FLOAT64_C(   644.80), SIMDE_FLOAT64_C(   412.58) },
      { SIMDE_FLOAT64_C(  -738.56), SIMDE_FLOAT64_C(  -987.18) },
      { SIMDE_FLOAT64_C(  -644.80), SIMDE_FLOAT64_C(  -412.58) } },
    { { SIMDE_FLOAT64_C(   -54.12), SIMDE_FLOAT64_C(  -858.45) },
      { SIMDE_FLOAT64_C(  -554.31), SIMDE_FLOAT64_C(   274.31) },
      { SIMDE_FLOAT64_C(   -54.12), SIMDE_FLOAT64_C(   858.45) } },
    { { SIMDE_FLOAT64_C(  -106.06), SIMDE_FLOAT64_C(  -482.09) },
      { SIMDE_FLOAT64_C(  -505.26), SIMDE_FLOAT64_C(  -310.15) },
      { SIMDE_FLOAT64_C(  -106.06), SIMDE_FLOAT64_C(  -482.09) } },
    { { SIMDE_FLOAT64_C(   726.18), SIMDE_FLOAT64_C(   941.28) },
      { SIMDE_FLOAT64_C(  -987.65), SIMDE_FLOAT64_C(  -463.18) },
      { SIMDE_FLOAT64_C(  -726.18), SIMDE_FLOAT64_C(  -941.28) } },
    { { SIMDE_FLOAT64_C(  -907.04), SIMDE_FLOAT64_C(  -842.82) },
      { SIMDE_FLOAT64_C(  -124.70), SIMDE_FLOAT64_C(   -89.06) },
      { SIMDE_FLOAT64_C(  -907.04), SIMDE_FLOAT64_C(  -842.82) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d dest = simde_mm_loadu_pd(test_vec[i].dest);
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__m128d r = simde_x_mm_copysign_pd(dest, src);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_x_mm_xorsign_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -998.44), SIMDE_FLOAT64_C(  -179.45) },
      { SIMDE_FLOAT64_C(    34.66), SIMDE_FLOAT64_C(   254.98) },
      { SIMDE_FLOAT64_C(  -998.44), SIMDE_FLOAT64_C(  -179.45) } },
    { { SIMDE_FLOAT64_C(  -220.74), SIMDE_FLOAT64_C(   718.77) },
      { SIMDE_FLOAT64_C(  -648.69), SIMDE_FLOAT64_C(  -598.91) },
      { SIMDE_FLOAT64_C(   220.74), SIMDE_FLOAT64_C(  -718.77) } },
    { { SIMDE_FLOAT64_C(    84.66), SIMDE_FLOAT64_C(  -602.04) },
      { SIMDE_FLOAT64_C(   631.55), SIMDE_FLOAT64_C(  -486.59) },
      { SIMDE_FLOAT64_C(    84.66), SIMDE_FLOAT64_C(   602.04) } },
    { { SIMDE_FLOAT64_C(   570.81), SIMDE_FLOAT64_C(   368.00) },
      { SIMDE_FLOAT64_C(   372.19), SIMDE_FLOAT64_C(  -832.84) },
      { SIMDE_FLOAT64_C(   570.81), SIMDE_FLOAT64_C(  -368.00) } },
    { { SIMDE_FLOAT64_C(  -996.05), SIMDE_FLOAT64_C(   875.71) },
      { SIMDE_FLOAT64_C(   198.29), SIMDE_FLOAT64_C(  -187.87) },
      { SIMDE_FLOAT64_C(  -996.05), SIMDE_FLOAT64_C(  -875.71) } },
    { { SIMDE_FLOAT64_C(  -462.20), SIMDE_FLOAT64_C(  -277.60) },
      { SIMDE_FLOAT64_C(   841.75), SIMDE_FLOAT64_C(   127.22) },
      { SIMDE_FLOAT64_C(  -462.20), SIMDE_FLOAT64_C(  -277.60) } },
    { { SIMDE_FLOAT64_C(  -669.20), SIMDE_FLOAT64_C(  -206.42) },
      { SIMDE_FLOAT64_C(   600.14), SIMDE_FLOAT64_C(    65.01) },
      { SIMDE_FLOAT64_C(  -669.20), SIMDE_FLOAT64_C(  -206.42) } },
    { { SIMDE_FLOAT64_C(   159.77), SIMDE_FLOAT64_C(  -896.78) },
      { SIMDE_FLOAT64_C(   642.72), SIMDE_FLOAT64_C(   161.33) },
      { SIMDE_FLOAT64_C(   159.77), SIMDE_FLOAT64_C(  -896.78) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_x_mm_xorsign_pd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_cvtepi32_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_epi32( 1668601445,     8850426,  1726684816, -1842005323),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1726684816.00), SIMDE_FLOAT64_C(-1842005323.00)) },
    { simde_mm_set_epi32(-1162443511,  1098837378,  -970075414,  1210551220),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-970075414.00), SIMDE_FLOAT64_C(1210551220.00)) },
    { simde_mm_set_epi32( 1014915875,   235168560,   691866984,  -431325465),
      simde_mm_set_pd(SIMDE_FLOAT64_C(691866984.00), SIMDE_FLOAT64_C(-431325465.00)) },
    { simde_mm_set_epi32( 1621419008,  1286931249, -1424446000,  -169673917),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1424446000.00), SIMDE_FLOAT64_C(-169673917.00)) },
    { simde_mm_set_epi32(  982570498,    31161721,   410129833,  1249524705),
      simde_mm_set_pd(SIMDE_FLOAT64_C(410129833.00), SIMDE_FLOAT64_C(1249524705.00)) },
    { simde_mm_set_epi32(-1807976526,   584564543,  1386856775,  -792093051),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1386856775.00), SIMDE_FLOAT64_C(-792093051.00)) },
    { simde_mm_set_epi32( 1927957259,   324939853,  1056227907,   960202603),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1056227907.00), SIMDE_FLOAT64_C(960202603.00)) },
    { simde_mm_set_epi32( 2096858414,  2117774841,   250894175,  1268045519),
      simde_mm_set_pd(SIMDE_FLOAT64_C(250894175.00), SIMDE_FLOAT64_C(1268045519.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtepi32_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtepi32_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_epi32( 332, -787,  -79, -785),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 332.00), SIMDE_FLOAT32_C(-787.00), SIMDE_FLOAT32_C( -79.00), SIMDE_FLOAT32_C(-785.00)) },
    { simde_mm_set_epi32( 394, -936, -733, -136),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 394.00), SIMDE_FLOAT32_C(-936.00), SIMDE_FLOAT32_C(-733.00), SIMDE_FLOAT32_C(-136.00)) },
    { simde_mm_set_epi32( 618, -416,  310,  183),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 618.00), SIMDE_FLOAT32_C(-416.00), SIMDE_FLOAT32_C( 310.00), SIMDE_FLOAT32_C( 183.00)) },
    { simde_mm_set_epi32(-748,  245,  533, -152),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-748.00), SIMDE_FLOAT32_C( 245.00), SIMDE_FLOAT32_C( 533.00), SIMDE_FLOAT32_C(-152.00)) },
    { simde_mm_set_epi32(  42,  893,  849, -741),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  42.00), SIMDE_FLOAT32_C( 893.00), SIMDE_FLOAT32_C( 849.00), SIMDE_FLOAT32_C(-741.00)) },
    { simde_mm_set_epi32( 657,  222, -709, -177),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 657.00), SIMDE_FLOAT32_C( 222.00), SIMDE_FLOAT32_C(-709.00), SIMDE_FLOAT32_C(-177.00)) },
    { simde_mm_set_epi32( 762, -586,  196,  717),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 762.00), SIMDE_FLOAT32_C(-586.00), SIMDE_FLOAT32_C( 196.00), SIMDE_FLOAT32_C( 717.00)) },
    { simde_mm_set_epi32( 322,  178,  766, -110),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 322.00), SIMDE_FLOAT32_C( 178.00), SIMDE_FLOAT32_C( 766.00), SIMDE_FLOAT32_C(-110.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtepi32_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtpd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const int32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN },
      {            INT32_MIN,             INT32_MIN,  INT32_C(           0),  INT32_C(           0) } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1), HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100) },
      {              INT32_MIN,  INT32_C(  2147483547),  INT32_C(           0),  INT32_C(           0) } },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1), HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100 },
      {              INT32_MIN, -INT32_C(  2147483548),  INT32_C(           0),  INT32_C(           0) } },
    #endif
    { { SIMDE_FLOAT64_C(  -220.31), SIMDE_FLOAT64_C(   685.08) },
      { -INT32_C(         220),  INT32_C(         685),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(  -164.88), SIMDE_FLOAT64_C(   725.51) },
      { -INT32_C(         165),  INT32_C(         726),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(   152.74), SIMDE_FLOAT64_C(   778.03) },
      {  INT32_C(         153),  INT32_C(         778),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(  -801.11), SIMDE_FLOAT64_C(  -331.66) },
      { -INT32_C(         801), -INT32_C(         332),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(  -834.04), SIMDE_FLOAT64_C(   -51.56) },
      { -INT32_C(         834), -INT32_C(          52),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(   737.22), SIMDE_FLOAT64_C(   205.77) },
      {  INT32_C(         737),  INT32_C(         206),  INT32_C(           0),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i r = simde_mm_cvtpd_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvtpd_pi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN },
      {            INT32_MIN,             INT32_MIN } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1), HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100) },
      {              INT32_MIN,  INT32_C(  2147483547) } },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1), HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100 },
      {              INT32_MIN, -INT32_C(  2147483548) } },
    #endif
    { { SIMDE_FLOAT64_C(  -220.31), SIMDE_FLOAT64_C(   685.08) },
      { -INT32_C(         220),  INT32_C(         685) } },
    { { SIMDE_FLOAT64_C(  -164.88), SIMDE_FLOAT64_C(   725.51) },
      { -INT32_C(         165),  INT32_C(         726) } },
    { { SIMDE_FLOAT64_C(   152.74), SIMDE_FLOAT64_C(   778.03) },
      {  INT32_C(         153),  INT32_C(         778) } },
    { { SIMDE_FLOAT64_C(  -801.11), SIMDE_FLOAT64_C(  -331.66) },
      { -INT32_C(         801), -INT32_C(         332) } },
    { { SIMDE_FLOAT64_C(  -834.04), SIMDE_FLOAT64_C(   -51.56) },
      { -INT32_C(         834), -INT32_C(          52) } },
    { { SIMDE_FLOAT64_C(   737.22), SIMDE_FLOAT64_C(   205.77) },
      {  INT32_C(         737),  INT32_C(         206) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m64 r = simde_mm_cvtpd_pi32(a);
    simde_test_x86_assert_equal_i32x2(r, simde_x_mm_loadu_si64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvtpd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  655.71), SIMDE_FLOAT64_C(  689.41)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  655.71), SIMDE_FLOAT32_C(  689.41)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.10), SIMDE_FLOAT64_C( -149.72)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C( -149.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  227.42), SIMDE_FLOAT64_C(  655.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  227.42), SIMDE_FLOAT32_C(  655.70)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -635.17), SIMDE_FLOAT64_C(  938.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -635.17), SIMDE_FLOAT32_C(  938.65)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  548.99), SIMDE_FLOAT64_C(  -18.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  548.99), SIMDE_FLOAT32_C(  -18.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -548.71), SIMDE_FLOAT64_C(   31.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -548.71), SIMDE_FLOAT32_C(   31.33)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -978.36), SIMDE_FLOAT64_C( -341.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -978.36), SIMDE_FLOAT32_C( -341.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  211.73), SIMDE_FLOAT64_C(  471.24)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  211.73), SIMDE_FLOAT32_C(  471.24)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtpd_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtpi32_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pi32(  -42,  -579),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -42.00), SIMDE_FLOAT64_C(-579.00)) },
    { simde_mm_set_pi32( -633,    29),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-633.00), SIMDE_FLOAT64_C(  29.00)) },
    { simde_mm_set_pi32( -149,   196),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-149.00), SIMDE_FLOAT64_C( 196.00)) },
    { simde_mm_set_pi32(  308,  -433),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 308.00), SIMDE_FLOAT64_C(-433.00)) },
    { simde_mm_set_pi32( -881,   358),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-881.00), SIMDE_FLOAT64_C( 358.00)) },
    { simde_mm_set_pi32(  723,   273),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 723.00), SIMDE_FLOAT64_C( 273.00)) },
    { simde_mm_set_pi32( -182,   457),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-182.00), SIMDE_FLOAT64_C( 457.00)) },
    { simde_mm_set_pi32( -239,  -577),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-239.00), SIMDE_FLOAT64_C(-577.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtpi32_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtps_epi32(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const int32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   718.49), SIMDE_FLOAT32_C(  -765.08) },
      {              INT32_MIN,              INT32_MIN,  INT32_C(         718), -INT32_C(         765) } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1),
        HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100),
        HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1),
        HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100), },
      {             INT32_MIN,  INT32_C(  2147483520),              INT32_MIN, -INT32_C(  2147483520) } },
    #endif
    #if !defined(SIMDE_FAST_ROUND_TIES)
    { { SIMDE_FLOAT32_C(    -1.50), SIMDE_FLOAT32_C(     1.50), SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { -INT32_C(           2),  INT32_C(           2), -INT32_C(           2),  INT32_C(         2) } },
    { { SIMDE_FLOAT32_C(    -3.50), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(    -4.50), SIMDE_FLOAT32_C(     4.50) },
      { -INT32_C(           4),  INT32_C(           4), -INT32_C(           4),  INT32_C(         4) } },
    #endif
    { { SIMDE_FLOAT32_C(   -95.52), SIMDE_FLOAT32_C(   603.57), SIMDE_FLOAT32_C(  -810.91), SIMDE_FLOAT32_C(   527.98) },
      { -INT32_C(          96),  INT32_C(         604), -INT32_C(         811),  INT32_C(         528) } },
    { { SIMDE_FLOAT32_C(  -768.18), SIMDE_FLOAT32_C(  -162.82), SIMDE_FLOAT32_C(  -159.43), SIMDE_FLOAT32_C(   588.60) },
      { -INT32_C(         768), -INT32_C(         163), -INT32_C(         159),  INT32_C(         589) } },
    { { SIMDE_FLOAT32_C(    84.90), SIMDE_FLOAT32_C(  -904.57), SIMDE_FLOAT32_C(  -209.20), SIMDE_FLOAT32_C(   264.55) },
      {  INT32_C(          85), -INT32_C(         905), -INT32_C(         209),  INT32_C(         265) } },
    { { SIMDE_FLOAT32_C(   -19.50), SIMDE_FLOAT32_C(  -416.92), SIMDE_FLOAT32_C(  -780.86), SIMDE_FLOAT32_C(   -31.81) },
      { -INT32_C(          20), -INT32_C(         417), -INT32_C(         781), -INT32_C(          32) } },
    { { SIMDE_FLOAT32_C(  -561.41), SIMDE_FLOAT32_C(  -689.14), SIMDE_FLOAT32_C(   434.56), SIMDE_FLOAT32_C(   432.69) },
      { -INT32_C(         561), -INT32_C(         689),  INT32_C(         435),  INT32_C(         433) } },
    { { SIMDE_FLOAT32_C(   170.13), SIMDE_FLOAT32_C(   594.22), SIMDE_FLOAT32_C(  -888.51), SIMDE_FLOAT32_C(   321.54) },
      {  INT32_C(         170),  INT32_C(         594), -INT32_C(         889),  INT32_C(         322) } },
    { { SIMDE_FLOAT32_C(   660.47), SIMDE_FLOAT32_C(  -124.04), SIMDE_FLOAT32_C(   493.83), SIMDE_FLOAT32_C(   250.16) },
      {  INT32_C(         660), -INT32_C(         124),  INT32_C(         494),  INT32_C(         250) } },
    { { SIMDE_FLOAT32_C(  -314.21), SIMDE_FLOAT32_C(   -16.38), SIMDE_FLOAT32_C(   852.78), SIMDE_FLOAT32_C(   590.27) },
      { -INT32_C(         314), -INT32_C(          16),  INT32_C(         853),  INT32_C(         590) } },
    { { SIMDE_FLOAT32_C(-2147483650.0), SIMDE_FLOAT32_C(-2147483650.0), SIMDE_FLOAT32_C(-2147483650.0), SIMDE_FLOAT32_C(-2147483650.0) },
      { -INT32_C(  2147483648), -INT32_C(  2147483648), -INT32_C(  2147483648), -INT32_C(  2147483648) } },
    { { SIMDE_FLOAT32_C( 2147483649.0), SIMDE_FLOAT32_C( 2147483649.0), SIMDE_FLOAT32_C( 2147483649.0), SIMDE_FLOAT32_C( 2147483649.0) },
      { -INT32_C(  2147483648), -INT32_C(  2147483648), -INT32_C(  2147483648), -INT32_C(  2147483648) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i r = simde_mm_cvtps_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvtps_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  295.41), SIMDE_FLOAT32_C( -909.65), SIMDE_FLOAT32_C(  156.64), SIMDE_FLOAT32_C( -802.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  156.64), SIMDE_FLOAT64_C( -802.16)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  649.83), SIMDE_FLOAT32_C( -763.68), SIMDE_FLOAT32_C(  364.80), SIMDE_FLOAT32_C(  389.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  364.80), SIMDE_FLOAT64_C(  389.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  269.92), SIMDE_FLOAT32_C( -207.13), SIMDE_FLOAT32_C(  538.63), SIMDE_FLOAT32_C(  487.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  538.63), SIMDE_FLOAT64_C(  487.11)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -982.29), SIMDE_FLOAT32_C(  234.64), SIMDE_FLOAT32_C(  -53.82), SIMDE_FLOAT32_C(  899.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.82), SIMDE_FLOAT64_C(  899.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  945.89), SIMDE_FLOAT32_C(  -98.53), SIMDE_FLOAT32_C(    1.57), SIMDE_FLOAT32_C(   49.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.57), SIMDE_FLOAT64_C(   49.07)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -47.73), SIMDE_FLOAT32_C(  806.42), SIMDE_FLOAT32_C(   11.76), SIMDE_FLOAT32_C(   -1.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   11.76), SIMDE_FLOAT64_C(   -1.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -961.08), SIMDE_FLOAT32_C( -192.05), SIMDE_FLOAT32_C(  553.30), SIMDE_FLOAT32_C( -994.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  553.30), SIMDE_FLOAT64_C( -994.71)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    9.30), SIMDE_FLOAT32_C( -203.20), SIMDE_FLOAT32_C( -196.20), SIMDE_FLOAT32_C(  707.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -196.20), SIMDE_FLOAT64_C(  707.05)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtps_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtsd_f64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde_float64 r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  298.96), SIMDE_FLOAT64_C(   39.67)),
      SIMDE_FLOAT64_C(  39.67) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -98.64), SIMDE_FLOAT64_C( -641.95)),
      SIMDE_FLOAT64_C(-641.95) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -307.30), SIMDE_FLOAT64_C( -193.04)),
      SIMDE_FLOAT64_C(-193.04) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -648.72), SIMDE_FLOAT64_C(  830.29)),
      SIMDE_FLOAT64_C( 830.29) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -701.20), SIMDE_FLOAT64_C( -501.79)),
      SIMDE_FLOAT64_C(-501.79) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  755.28), SIMDE_FLOAT64_C(  648.10)),
      SIMDE_FLOAT64_C( 648.10) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -664.63), SIMDE_FLOAT64_C(  220.54)),
      SIMDE_FLOAT64_C( 220.54) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -762.92), SIMDE_FLOAT64_C( -101.29)),
      SIMDE_FLOAT64_C(-101.29) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 r = simde_mm_cvtsd_f64(test_vec[i].a);
    simde_assert_equal_f64(r, test_vec[i].r, 2);
  }

  return 0;
}

static int
test_simde_mm_cvtsd_si32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -162.87) },
                 INT32_MIN },
    { {            -SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -905.13) },
                 INT32_MIN },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1), SIMDE_FLOAT64_C(   177.40) },
                  INT32_MIN },
    { { HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100, SIMDE_FLOAT64_C(  -906.88) },
       INT32_C(  2147483547) },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1), SIMDE_FLOAT64_C(   676.90) },
                   INT32_MIN },
    { { HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100, SIMDE_FLOAT64_C(  -848.13) },
      -INT32_C(  2147483548) },
    #endif
    { { SIMDE_FLOAT64_C(   353.29), SIMDE_FLOAT64_C(   -16.32) },
       INT32_C(         353) },
    { { SIMDE_FLOAT64_C(   477.70), SIMDE_FLOAT64_C(  -131.04) },
       INT32_C(         478) },
    { { SIMDE_FLOAT64_C(  -314.42), SIMDE_FLOAT64_C(  -351.80) },
      -INT32_C(         314) },
    { { SIMDE_FLOAT64_C(  -574.04), SIMDE_FLOAT64_C(  -761.46) },
      -INT32_C(         574) },
    { { SIMDE_FLOAT64_C(  -428.08), SIMDE_FLOAT64_C(   959.55) },
      -INT32_C(         428) },
    { { SIMDE_FLOAT64_C(   453.56), SIMDE_FLOAT64_C(  -261.91) },
       INT32_C(         454) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    int32_t r = simde_mm_cvtsd_si32(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsd_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  793.30), SIMDE_FLOAT64_C( -706.75)), -707 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   29.13), SIMDE_FLOAT64_C( -309.00)), -309 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   21.24), SIMDE_FLOAT64_C(  368.17)),  368 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -595.30), SIMDE_FLOAT64_C(  351.60)),  352 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -640.13), SIMDE_FLOAT64_C( -466.84)), -467 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -237.20), SIMDE_FLOAT64_C( -994.72)), -995 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -983.23), SIMDE_FLOAT64_C(  645.14)),  645 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -89.10), SIMDE_FLOAT64_C(  585.69)),  586 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtsd_si64(test_vec[i].a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsd_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128d b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  522.41), SIMDE_FLOAT32_C(  122.44), SIMDE_FLOAT32_C(  708.76), SIMDE_FLOAT32_C(  910.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -52.04), SIMDE_FLOAT64_C(  228.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  522.41), SIMDE_FLOAT32_C(  122.44), SIMDE_FLOAT32_C(  708.76), SIMDE_FLOAT32_C(  228.75)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -311.44), SIMDE_FLOAT32_C(  267.00), SIMDE_FLOAT32_C(  965.23), SIMDE_FLOAT32_C( -248.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -89.48), SIMDE_FLOAT64_C(  178.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -311.44), SIMDE_FLOAT32_C(  267.00), SIMDE_FLOAT32_C(  965.23), SIMDE_FLOAT32_C(  178.71)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  252.50), SIMDE_FLOAT32_C(  744.35), SIMDE_FLOAT32_C(  237.50), SIMDE_FLOAT32_C(  713.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -913.96), SIMDE_FLOAT64_C(  935.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  252.50), SIMDE_FLOAT32_C(  744.35), SIMDE_FLOAT32_C(  237.50), SIMDE_FLOAT32_C(  935.45)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  781.08), SIMDE_FLOAT32_C(  -50.03), SIMDE_FLOAT32_C( -658.11), SIMDE_FLOAT32_C(  945.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -556.84), SIMDE_FLOAT64_C(  452.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  781.08), SIMDE_FLOAT32_C(  -50.03), SIMDE_FLOAT32_C( -658.11), SIMDE_FLOAT32_C(  452.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  459.13), SIMDE_FLOAT32_C(  794.72), SIMDE_FLOAT32_C(  105.91), SIMDE_FLOAT32_C(  688.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -123.20), SIMDE_FLOAT64_C(  469.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  459.13), SIMDE_FLOAT32_C(  794.72), SIMDE_FLOAT32_C(  105.91), SIMDE_FLOAT32_C(  469.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -699.67), SIMDE_FLOAT32_C(  751.26), SIMDE_FLOAT32_C(   72.14), SIMDE_FLOAT32_C( -162.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  868.66), SIMDE_FLOAT64_C(  138.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -699.67), SIMDE_FLOAT32_C(  751.26), SIMDE_FLOAT32_C(   72.14), SIMDE_FLOAT32_C(  138.18)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -144.80), SIMDE_FLOAT32_C(  372.44), SIMDE_FLOAT32_C( -878.31), SIMDE_FLOAT32_C(  984.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -559.54), SIMDE_FLOAT64_C(  112.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -144.80), SIMDE_FLOAT32_C(  372.44), SIMDE_FLOAT32_C( -878.31), SIMDE_FLOAT32_C(  112.58)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -958.65), SIMDE_FLOAT32_C(  333.33), SIMDE_FLOAT32_C( -940.30), SIMDE_FLOAT32_C(  396.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  263.65), SIMDE_FLOAT64_C(  199.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -958.65), SIMDE_FLOAT32_C(  333.33), SIMDE_FLOAT32_C( -940.30), SIMDE_FLOAT32_C(  199.76)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtsd_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_x_mm_cvtsi128_si16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[8];
    const int16_t r;
  } test_vec[] = {
    { { -INT16_C( 30955),  INT16_C(   704), -INT16_C( 12934), -INT16_C( 10158),  INT16_C( 23505),  INT16_C( 18623), -INT16_C( 30715),  INT16_C( 30631) },
      -INT16_C( 30955) },
    { { -INT16_C( 18124), -INT16_C(  9599), -INT16_C( 23005), -INT16_C(  5882), -INT16_C( 24114),  INT16_C( 22410),  INT16_C( 23298),  INT16_C(  6106) },
      -INT16_C( 18124) },
    { { -INT16_C( 25630),  INT16_C( 23577),  INT16_C( 27496),  INT16_C( 14645), -INT16_C(  2874), -INT16_C( 13439),  INT16_C( 10620), -INT16_C( 20158) },
      -INT16_C( 25630) },
    { { -INT16_C( 15390),  INT16_C(  1675), -INT16_C( 28310),  INT16_C( 14575),  INT16_C( 31026),  INT16_C( 13455),  INT16_C( 27348), -INT16_C( 18613) },
      -INT16_C( 15390) },
    { {  INT16_C( 25605),  INT16_C( 27923),  INT16_C( 18639), -INT16_C( 27226),  INT16_C( 10301), -INT16_C( 18079), -INT16_C( 23727),  INT16_C( 13162) },
       INT16_C( 25605) },
    { { -INT16_C(  2713), -INT16_C( 11975),  INT16_C( 10630), -INT16_C( 18423), -INT16_C( 26206),  INT16_C( 30700),  INT16_C( 14083),  INT16_C(  2094) },
      -INT16_C(  2713) },
    { {  INT16_C( 16795),  INT16_C( 27253),  INT16_C(  7050), -INT16_C( 14592),  INT16_C( 24899), -INT16_C( 27520), -INT16_C(  5372),  INT16_C( 27592) },
       INT16_C( 16795) },
    { {  INT16_C(   480),  INT16_C( 26428),  INT16_C( 17962), -INT16_C( 13025),  INT16_C(  3295), -INT16_C(  7612),  INT16_C( 29251), -INT16_C(  8214) },
       INT16_C(   480) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    int16_t r = simde_x_mm_cvtsi128_si16(a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsi128_si32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_epi32(   26453550,  -127780894,   765191664, -1527053336), -1527053336 },
    { simde_mm_set_epi32(-2072408746,   654549051, -1035182329,  -310311602),  -310311602 },
    { simde_mm_set_epi32(-1491944780,  -848128842,   200170171,  -471300206),  -471300206 },
    { simde_mm_set_epi32(-1218501110,   680592926,  -869682471,  -297305797),  -297305797 },
    { simde_mm_set_epi32(-1884581495,  -571508262,  -111379645, -1274133785), -1274133785 },
    { simde_mm_set_epi32(  486988098,   416284528,  1359642222,   197671232),   197671232 },
    { simde_mm_set_epi32(  296562088, -1151305617, -1413122888, -1640910233), -1640910233 },
    { simde_mm_set_epi32(-1262725255, -1253335394,   -91416000, -1892793314), -1892793314 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_cvtsi128_si32(test_vec[i].a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsi64_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t a;
    simde__m128i r;
  } test_vec[8] = {
    { INT64_C(   6168135010467220065),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   6168135010467220065)) },
    { INT64_C(   3895170522828645721),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   3895170522828645721)) },
    { INT64_C(  -3378210069702593578),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(  -3378210069702593578)) },
    { INT64_C(   2750396577149404222),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   2750396577149404222)) },
    { INT64_C(   1438311486113044813),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   1438311486113044813)) },
    { INT64_C(   3416877519561179684),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   3416877519561179684)) },
    { INT64_C(   5633937201227624265),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   5633937201227624265)) },
    { INT64_C(  -3544191055453826903),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(  -3544191055453826903)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsi64_si128(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsi128_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(   6773505374496819552), INT64_C(   4667650958864037640)),
      INT64_C(   4667650958864037640) },
    { simde_mm_set_epi64x(INT64_C(   1327994882711935975), INT64_C(   6055234041306631062)),
      INT64_C(   6055234041306631062) },
    { simde_mm_set_epi64x(INT64_C(   8972445642279437044), INT64_C(  -4761409530754735793)),
      INT64_C(  -4761409530754735793) },
    { simde_mm_set_epi64x(INT64_C(   7460890732678939925), INT64_C(   5266150742597997743)),
      INT64_C(   5266150742597997743) },
    { simde_mm_set_epi64x(INT64_C(  -6075061397734634308), INT64_C(    487741331498539771)),
      INT64_C(    487741331498539771) },
    { simde_mm_set_epi64x(INT64_C(   2874947710909797095), INT64_C(   2287065406213692181)),
      INT64_C(   2287065406213692181) },
    { simde_mm_set_epi64x(INT64_C(   8598185467708417568), INT64_C(  -2745610728130306920)),
      INT64_C(  -2745610728130306920) },
    { simde_mm_set_epi64x(INT64_C(   6122366414867950497), INT64_C(    614503884136124395)),
      INT64_C(    614503884136124395) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtsi128_si64(test_vec[i].a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_cvtsi16_si128 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a;
    const int16_t r[8];
  } test_vec[] = {
    { -INT16_C( 17602),
      { -INT16_C( 17602),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C( 26279),
      {  INT16_C( 26279),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { -INT16_C( 15939),
      { -INT16_C( 15939),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { -INT16_C(  9973),
      { -INT16_C(  9973),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { -INT16_C(  7532),
      { -INT16_C(  7532),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C(  4549),
      {  INT16_C(  4549),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C(  6325),
      {  INT16_C(  6325),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { -INT16_C(  6958),
      { -INT16_C(  6958),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    simde__m128i r = simde_x_mm_cvtsi16_si128(a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvtsi32_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    int b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -601.07), SIMDE_FLOAT64_C(  516.34)),
      -768,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -601.07), SIMDE_FLOAT64_C( -768.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.83), SIMDE_FLOAT64_C(  135.41)),
      -383,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.83), SIMDE_FLOAT64_C( -383.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  503.65), SIMDE_FLOAT64_C(  859.44)),
       872,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.65), SIMDE_FLOAT64_C(  872.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.44), SIMDE_FLOAT64_C(  854.87)),
       613,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.44), SIMDE_FLOAT64_C(  613.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  520.67), SIMDE_FLOAT64_C( -993.40)),
       197,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  520.67), SIMDE_FLOAT64_C(  197.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  461.59), SIMDE_FLOAT64_C( -572.51)),
      -157,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  461.59), SIMDE_FLOAT64_C( -157.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -113.22), SIMDE_FLOAT64_C(  791.22)),
      -840,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -113.22), SIMDE_FLOAT64_C( -840.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  707.47), SIMDE_FLOAT64_C(  954.02)),
      -347,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  707.47), SIMDE_FLOAT64_C( -347.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtsi32_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtsi32_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t a;
    simde__m128i r;
  } test_vec[8] = {
    {   306582644, simde_mm_set_epi32(0, 0, 0,  306582644) },
    {  -365974780, simde_mm_set_epi32(0, 0, 0, -365974780) },
    {   -85065628, simde_mm_set_epi32(0, 0, 0,  -85065628) },
    {  1053254834, simde_mm_set_epi32(0, 0, 0, 1053254834) },
    {  -236294791, simde_mm_set_epi32(0, 0, 0, -236294791) },
    {  1341442607, simde_mm_set_epi32(0, 0, 0, 1341442607) },
    {   336976017, simde_mm_set_epi32(0, 0, 0,  336976017) },
    {  1400276059, simde_mm_set_epi32(0, 0, 0, 1400276059) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsi32_si128(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsi64_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    int64_t b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  229.24), SIMDE_FLOAT64_C(  177.04)),  637,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  229.24), SIMDE_FLOAT64_C(  637.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  401.10), SIMDE_FLOAT64_C(  284.52)), -162,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.10), SIMDE_FLOAT64_C( -162.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  499.46), SIMDE_FLOAT64_C(  321.47)), -540,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  499.46), SIMDE_FLOAT64_C( -540.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -710.92), SIMDE_FLOAT64_C(  858.14)),  -64,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -710.92), SIMDE_FLOAT64_C(  -64.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -289.27), SIMDE_FLOAT64_C( -887.54)), -238,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -289.27), SIMDE_FLOAT64_C( -238.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.34), SIMDE_FLOAT64_C(  242.15)),  121,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.34), SIMDE_FLOAT64_C(  121.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -376.10), SIMDE_FLOAT64_C( -965.52)),  315,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -376.10), SIMDE_FLOAT64_C(  315.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  673.51), SIMDE_FLOAT64_C( -882.88)),  -72,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  673.51), SIMDE_FLOAT64_C(  -72.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtsi64_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cvtss_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128 b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 546.48), SIMDE_FLOAT64_C( 729.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 142.68), SIMDE_FLOAT32_C( -75.76), SIMDE_FLOAT32_C(-648.72), SIMDE_FLOAT32_C( 148.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 546.48), SIMDE_FLOAT64_C( 148.36)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  79.60), SIMDE_FLOAT64_C( 648.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 631.34), SIMDE_FLOAT32_C( 902.53), SIMDE_FLOAT32_C( -54.65), SIMDE_FLOAT32_C( 614.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  79.60), SIMDE_FLOAT64_C( 614.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 811.47), SIMDE_FLOAT64_C( -95.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  13.27), SIMDE_FLOAT32_C( 315.63), SIMDE_FLOAT32_C( 407.80), SIMDE_FLOAT32_C(-826.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 811.47), SIMDE_FLOAT64_C(-826.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 315.42), SIMDE_FLOAT64_C( -69.06)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 775.15), SIMDE_FLOAT32_C( 935.54), SIMDE_FLOAT32_C(-964.44), SIMDE_FLOAT32_C( 659.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 315.42), SIMDE_FLOAT64_C( 659.62)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-579.75), SIMDE_FLOAT64_C(-291.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 533.61), SIMDE_FLOAT32_C( 565.53), SIMDE_FLOAT32_C( -36.93), SIMDE_FLOAT32_C(  57.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-579.75), SIMDE_FLOAT64_C(  57.54)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 979.09), SIMDE_FLOAT64_C(-471.44)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 927.62), SIMDE_FLOAT32_C( 955.93), SIMDE_FLOAT32_C(-964.80), SIMDE_FLOAT32_C( 823.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 979.09), SIMDE_FLOAT64_C( 823.88)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 172.44), SIMDE_FLOAT64_C(-427.74)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-343.18), SIMDE_FLOAT32_C(-352.03), SIMDE_FLOAT32_C(-836.30), SIMDE_FLOAT32_C( -61.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 172.44), SIMDE_FLOAT64_C( -61.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 975.42), SIMDE_FLOAT64_C( 394.72)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 748.90), SIMDE_FLOAT32_C(-410.84), SIMDE_FLOAT32_C( 636.92), SIMDE_FLOAT32_C( 230.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 975.42), SIMDE_FLOAT64_C( 230.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtss_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 2);
  }

  return 0;
}

static int
test_simde_mm_cvttpd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const int32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,           -SIMDE_MATH_NAN },
      {            INT32_MIN,              INT32_MIN,  INT32_C(           0),  INT32_C(           0) } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE) && 0
    { { SIMDE_FLOAT64_C(   524.21), SIMDE_FLOAT64_C(    51.51) },
      {  INT32_C(         524),  INT32_C(          51),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(   146.80), SIMDE_FLOAT64_C(  -434.11) },
      {  INT32_C(         146), -INT32_C(         434),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(  -150.72), SIMDE_FLOAT64_C(   743.64) },
    #endif
    { { SIMDE_FLOAT64_C(   788.74), SIMDE_FLOAT64_C(   212.17) },
      {  INT32_C(         788),  INT32_C(         212),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(  -172.36), SIMDE_FLOAT64_C(   455.86) },
      { -INT32_C(         172),  INT32_C(         455),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(  -728.09), SIMDE_FLOAT64_C(   893.73) },
      { -INT32_C(         728),  INT32_C(         893),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(   333.21), SIMDE_FLOAT64_C(  -914.29) },
      {  INT32_C(         333), -INT32_C(         914),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(     0.95), SIMDE_FLOAT64_C(   701.07) },
      {  INT32_C(           0),  INT32_C(         701),  INT32_C(           0),  INT32_C(           0) } },
    { { SIMDE_FLOAT64_C(   639.75), SIMDE_FLOAT64_C(  -803.13) },
      {  INT32_C(         639), -INT32_C(         803),  INT32_C(           0),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i r = simde_mm_cvttpd_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvttpd_pi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,           -SIMDE_MATH_NAN },
      {            INT32_MIN,              INT32_MIN } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1),
        HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100) },
      {             INT32_MIN,   INT32_C(   2147483547) } },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1),
        HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100) },
      {             INT32_MIN,  -INT32_C(   2147483548) } },
    #endif
    { { SIMDE_FLOAT64_C(   788.74), SIMDE_FLOAT64_C(   212.17) },
      {  INT32_C(         788),  INT32_C(         212) } },
    { { SIMDE_FLOAT64_C(  -172.36), SIMDE_FLOAT64_C(   455.86) },
      { -INT32_C(         172),  INT32_C(         455) } },
    { { SIMDE_FLOAT64_C(  -728.09), SIMDE_FLOAT64_C(   893.73) },
      { -INT32_C(         728),  INT32_C(         893) } },
    { { SIMDE_FLOAT64_C(   333.21), SIMDE_FLOAT64_C(  -914.29) },
      {  INT32_C(         333), -INT32_C(         914) } },
    { { SIMDE_FLOAT64_C(     0.95), SIMDE_FLOAT64_C(   701.07) },
      {  INT32_C(           0),  INT32_C(         701) } },
    { { SIMDE_FLOAT64_C(   639.75), SIMDE_FLOAT64_C(  -803.13) },
      {  INT32_C(         639), -INT32_C(         803) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m64 r = simde_mm_cvttpd_pi32(a);
    simde_test_x86_assert_equal_i32x2(r, simde_x_mm_load_si64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvttps_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const int32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -859.90),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -330.33) },
      {            INT32_MIN, -INT32_C(         859),            INT32_MIN, -INT32_C(         330) } },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1),
        HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100),
        HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1),
        HEDLEY_STATIC_CAST(simde_float32, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100) },
      {            INT32_MIN,  INT32_C(   2147483520),             INT32_MIN, -INT32_C(    2147483520) } },
    #endif
    { { SIMDE_FLOAT32_C(   884.61), SIMDE_FLOAT32_C(   424.21), SIMDE_FLOAT32_C(   434.23), SIMDE_FLOAT32_C(  -865.32) },
      {  INT32_C(         884),  INT32_C(         424),  INT32_C(         434), -INT32_C(         865) } },
    { { SIMDE_FLOAT32_C(     3.17), SIMDE_FLOAT32_C(  -163.40), SIMDE_FLOAT32_C(  -490.56), SIMDE_FLOAT32_C(   628.48) },
      {  INT32_C(           3), -INT32_C(         163), -INT32_C(         490),  INT32_C(         628) } },
    { { SIMDE_FLOAT32_C(   629.16), SIMDE_FLOAT32_C(   267.90), SIMDE_FLOAT32_C(   468.27), SIMDE_FLOAT32_C(   765.29) },
      {  INT32_C(         629),  INT32_C(         267),  INT32_C(         468),  INT32_C(         765) } },
    { { SIMDE_FLOAT32_C(  -532.39), SIMDE_FLOAT32_C(   448.09), SIMDE_FLOAT32_C(   543.36), SIMDE_FLOAT32_C(  -643.97) },
      { -INT32_C(         532),  INT32_C(         448),  INT32_C(         543), -INT32_C(         643) } },
    { { SIMDE_FLOAT32_C(  -958.61), SIMDE_FLOAT32_C(  -434.16), SIMDE_FLOAT32_C(   958.20), SIMDE_FLOAT32_C(   749.69) },
      { -INT32_C(         958), -INT32_C(         434),  INT32_C(         958),  INT32_C(         749) } },
    { { SIMDE_FLOAT32_C(   379.97), SIMDE_FLOAT32_C(  -697.16), SIMDE_FLOAT32_C(   790.54), SIMDE_FLOAT32_C(  -387.37) },
      {  INT32_C(         379), -INT32_C(         697),  INT32_C(         790), -INT32_C(         387) } },
    { { SIMDE_FLOAT32_C(  -785.26), SIMDE_FLOAT32_C(   403.54), SIMDE_FLOAT32_C(  -475.03), SIMDE_FLOAT32_C(  -577.41) },
      { -INT32_C(         785),  INT32_C(         403), -INT32_C(         475), -INT32_C(         577) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i r = simde_mm_cvttps_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cvttsd_si32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   248.78) },
                 INT32_MIN },
    { {            -SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   139.38) },
                 INT32_MIN },
    #endif
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) + 1),
        SIMDE_FLOAT64_C(  -850.89) },
      -INT32_C(  2147483648) },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) - 1),
        SIMDE_FLOAT64_C(   -30.56) },
      -INT32_C(  2147483648) },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MAX) - 100),
        SIMDE_FLOAT64_C(  -742.09) },
       INT32_C(  2147483547) },
    { { HEDLEY_STATIC_CAST(simde_float64, HEDLEY_STATIC_CAST(int64_t, INT32_MIN) + 100),
        SIMDE_FLOAT64_C(  -496.27) },
      -INT32_C(  2147483548) },
    #endif
    { { SIMDE_FLOAT64_C(   -57.42), SIMDE_FLOAT64_C(  -705.99) },
      -INT32_C(          57) },
    { { SIMDE_FLOAT64_C(   737.15), SIMDE_FLOAT64_C(  -394.42) },
       INT32_C(         737) },
    { { SIMDE_FLOAT64_C(  -193.78), SIMDE_FLOAT64_C(     0.85) },
      -INT32_C(         193) },
    { { SIMDE_FLOAT64_C(   -61.02), SIMDE_FLOAT64_C(   247.60) },
      -INT32_C(          61) },
    { { SIMDE_FLOAT64_C(   396.64), SIMDE_FLOAT64_C(   103.10) },
       INT32_C(         396) },
    { { SIMDE_FLOAT64_C(   606.36), SIMDE_FLOAT64_C(  -703.92) },
       INT32_C(         606) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    int32_t r = simde_mm_cvttsd_si32(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}


static int
test_simde_mm_cvttsd_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-345.97), SIMDE_FLOAT64_C( 664.87)),  664 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 648.27), SIMDE_FLOAT64_C(-390.19)), -390 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-500.63), SIMDE_FLOAT64_C(-258.15)), -258 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-109.22), SIMDE_FLOAT64_C(-784.27)), -784 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-688.79), SIMDE_FLOAT64_C(-698.22)), -698 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-914.25), SIMDE_FLOAT64_C(-650.88)), -650 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-228.35), SIMDE_FLOAT64_C(-603.46)), -603 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-556.94), SIMDE_FLOAT64_C( 694.64)),  694 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvttsd_si64(test_vec[i].a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_div_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -184.40), SIMDE_FLOAT64_C(  992.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  155.72), SIMDE_FLOAT64_C(  856.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.18), SIMDE_FLOAT64_C(    1.16)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.37), SIMDE_FLOAT64_C(  596.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -718.99), SIMDE_FLOAT64_C(  -17.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(  -33.19)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  797.64), SIMDE_FLOAT64_C(  669.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.55), SIMDE_FLOAT64_C(  857.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.91), SIMDE_FLOAT64_C(    0.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -864.62), SIMDE_FLOAT64_C(  635.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -556.59), SIMDE_FLOAT64_C(  676.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.55), SIMDE_FLOAT64_C(    0.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -635.32), SIMDE_FLOAT64_C(  518.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -426.58), SIMDE_FLOAT64_C( -331.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.49), SIMDE_FLOAT64_C(   -1.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -494.90), SIMDE_FLOAT64_C(  -42.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  432.98), SIMDE_FLOAT64_C(  277.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.14), SIMDE_FLOAT64_C(   -0.15)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -530.41), SIMDE_FLOAT64_C(  112.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -914.02), SIMDE_FLOAT64_C(   90.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.58), SIMDE_FLOAT64_C(    1.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -176.73), SIMDE_FLOAT64_C( -245.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  315.38), SIMDE_FLOAT64_C( -747.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.56), SIMDE_FLOAT64_C(    0.33)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_div_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_div_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -164.12), SIMDE_FLOAT64_C( -192.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -917.87), SIMDE_FLOAT64_C(  429.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -164.12), SIMDE_FLOAT64_C(   -0.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  658.48), SIMDE_FLOAT64_C(  164.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.79), SIMDE_FLOAT64_C(  356.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  658.48), SIMDE_FLOAT64_C(    0.46)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -450.41), SIMDE_FLOAT64_C(  587.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  553.54), SIMDE_FLOAT64_C( -684.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -450.41), SIMDE_FLOAT64_C(   -0.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -742.91), SIMDE_FLOAT64_C( -966.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  180.37), SIMDE_FLOAT64_C(  175.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -742.91), SIMDE_FLOAT64_C(   -5.49)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -280.67), SIMDE_FLOAT64_C(  415.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  495.86), SIMDE_FLOAT64_C( -819.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -280.67), SIMDE_FLOAT64_C(   -0.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  391.69), SIMDE_FLOAT64_C(  589.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -651.02), SIMDE_FLOAT64_C( -239.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  391.69), SIMDE_FLOAT64_C(   -2.46)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  423.52), SIMDE_FLOAT64_C(  419.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  336.50), SIMDE_FLOAT64_C(  431.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  423.52), SIMDE_FLOAT64_C(    0.97)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  235.17), SIMDE_FLOAT64_C( -333.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -715.21), SIMDE_FLOAT64_C(    4.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  235.17), SIMDE_FLOAT64_C(  -69.26)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_div_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_extract_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-22888), INT16_C(-26241), INT16_C( 16094), INT16_C( 25365),
                         INT16_C(-10975), INT16_C( -4323), INT16_C(  9478), INT16_C(-18966)), 54561 },
    { simde_mm_set_epi16(INT16_C( -4494), INT16_C(-23544), INT16_C( 12313), INT16_C( 19220),
                         INT16_C( 16921), INT16_C(  9248), INT16_C( -1076), INT16_C(-18617)), 16921 },
    { simde_mm_set_epi16(INT16_C(  5051), INT16_C( 30913), INT16_C( 18404), INT16_C(-11820),
                         INT16_C( 16495), INT16_C( 32647), INT16_C( 21150), INT16_C( 16664)), 16495 },
    { simde_mm_set_epi16(INT16_C(   987), INT16_C( 32176), INT16_C(-17758), INT16_C( 21096),
                         INT16_C(  -945), INT16_C(  5537), INT16_C(  5495), INT16_C(-18130)), 64591 },
    { simde_mm_set_epi16(INT16_C(-16046), INT16_C( 13714), INT16_C( 12272), INT16_C( 32151),
                         INT16_C(-14156), INT16_C(  8851), INT16_C(-19624), INT16_C( -2653)), 51380 },
    { simde_mm_set_epi16(INT16_C(-28172), INT16_C(  1666), INT16_C( 15569), INT16_C( -1622),
                         INT16_C( 22048), INT16_C(-24364), INT16_C(  2478), INT16_C( 20826)), 22048 },
    { simde_mm_set_epi16(INT16_C(-29653), INT16_C(-27750), INT16_C(  5027), INT16_C( -7816),
                         INT16_C(-20852), INT16_C(  3178), INT16_C(-27881), INT16_C(  3156)), 44684 },
    { simde_mm_set_epi16(INT16_C(-26280), INT16_C( 27067), INT16_C( 10815), INT16_C(-30178),
                         INT16_C(-26852), INT16_C( 26399), INT16_C(-30202), INT16_C(-11030)), 38684 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_extract_epi16(test_vec[i].a, 3);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_insert_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int16_t b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-18659), INT16_C( 19491), INT16_C(-30434), INT16_C( -6059),
                         INT16_C( 11985), INT16_C(  5369), INT16_C(-14188), INT16_C(  9668)),
       21712,
      simde_mm_set_epi16(INT16_C(-18659), INT16_C( 19491), INT16_C(-30434), INT16_C( -6059),
                         INT16_C( 21712), INT16_C(  5369), INT16_C(-14188), INT16_C(  9668)) },
    { simde_mm_set_epi16(INT16_C( 32684), INT16_C(-21716), INT16_C(  7657), INT16_C(  3627),
                         INT16_C( 12377), INT16_C( 30609), INT16_C(-12611), INT16_C(-11955)),
      -27473,
      simde_mm_set_epi16(INT16_C( 32684), INT16_C(-21716), INT16_C(  7657), INT16_C(  3627),
                         INT16_C(-27473), INT16_C( 30609), INT16_C(-12611), INT16_C(-11955)) },
    { simde_mm_set_epi16(INT16_C(-18344), INT16_C( -4896), INT16_C(-19094), INT16_C(  -638),
                         INT16_C(-30376), INT16_C(-17556), INT16_C(-31358), INT16_C(-17530)),
      -19116,
      simde_mm_set_epi16(INT16_C(-18344), INT16_C( -4896), INT16_C(-19094), INT16_C(  -638),
                         INT16_C(-19116), INT16_C(-17556), INT16_C(-31358), INT16_C(-17530)) },
    { simde_mm_set_epi16(INT16_C(-11121), INT16_C( 29288), INT16_C( -3915), INT16_C( 13306),
                         INT16_C( 30582), INT16_C(  4374), INT16_C( -9323), INT16_C( -2317)),
        5778,
      simde_mm_set_epi16(INT16_C(-11121), INT16_C( 29288), INT16_C( -3915), INT16_C( 13306),
                         INT16_C(  5778), INT16_C(  4374), INT16_C( -9323), INT16_C( -2317)) },
    { simde_mm_set_epi16(INT16_C(  7542), INT16_C(-16196), INT16_C(-24612), INT16_C(  8929),
                         INT16_C(-16460), INT16_C( 17259), INT16_C(   672), INT16_C(-18076)),
        -411,
      simde_mm_set_epi16(INT16_C(  7542), INT16_C(-16196), INT16_C(-24612), INT16_C(  8929),
                         INT16_C(  -411), INT16_C( 17259), INT16_C(   672), INT16_C(-18076)) },
    { simde_mm_set_epi16(INT16_C( 15913), INT16_C(-18873), INT16_C( 14978), INT16_C( 31946),
                         INT16_C( -6939), INT16_C( 26150), INT16_C( 18499), INT16_C(-16752)),
        1141,
      simde_mm_set_epi16(INT16_C( 15913), INT16_C(-18873), INT16_C( 14978), INT16_C( 31946),
                         INT16_C(  1141), INT16_C( 26150), INT16_C( 18499), INT16_C(-16752)) },
    { simde_mm_set_epi16(INT16_C(  1093), INT16_C( -6101), INT16_C(-30747), INT16_C(-18266),
                         INT16_C(  4085), INT16_C(-14478), INT16_C( -6279), INT16_C(-25531)),
      -18605,
      simde_mm_set_epi16(INT16_C(  1093), INT16_C( -6101), INT16_C(-30747), INT16_C(-18266),
                         INT16_C(-18605), INT16_C(-14478), INT16_C( -6279), INT16_C(-25531)) },
    { simde_mm_set_epi16(INT16_C( -2463), INT16_C( -3389), INT16_C( 28311), INT16_C( -5667),
                         INT16_C( 24886), INT16_C( 24368), INT16_C( 19484), INT16_C(-11581)),
      -17420,
      simde_mm_set_epi16(INT16_C( -2463), INT16_C( -3389), INT16_C( 28311), INT16_C( -5667),
                         INT16_C(-17420), INT16_C( 24368), INT16_C( 19484), INT16_C(-11581)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_insert_epi16(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_load_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 a[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   319.94), SIMDE_FLOAT64_C(   593.75) },
      { SIMDE_FLOAT64_C(   319.94), SIMDE_FLOAT64_C(   593.75) } },
    { { SIMDE_FLOAT64_C(  -220.38), SIMDE_FLOAT64_C(   646.62) },
      { SIMDE_FLOAT64_C(  -220.38), SIMDE_FLOAT64_C(   646.62) } },
    { { SIMDE_FLOAT64_C(   769.82), SIMDE_FLOAT64_C(   960.64) },
      { SIMDE_FLOAT64_C(   769.82), SIMDE_FLOAT64_C(   960.64) } },
    { { SIMDE_FLOAT64_C(  -283.67), SIMDE_FLOAT64_C(  -795.53) },
      { SIMDE_FLOAT64_C(  -283.67), SIMDE_FLOAT64_C(  -795.53) } },
    { { SIMDE_FLOAT64_C(  -643.22), SIMDE_FLOAT64_C(   246.89) },
      { SIMDE_FLOAT64_C(  -643.22), SIMDE_FLOAT64_C(   246.89) } },
    { { SIMDE_FLOAT64_C(  -842.54), SIMDE_FLOAT64_C(  -513.83) },
      { SIMDE_FLOAT64_C(  -842.54), SIMDE_FLOAT64_C(  -513.83) } },
    { { SIMDE_FLOAT64_C(   635.37), SIMDE_FLOAT64_C(   836.97) },
      { SIMDE_FLOAT64_C(   635.37), SIMDE_FLOAT64_C(   836.97) } },
    { { SIMDE_FLOAT64_C(   838.72), SIMDE_FLOAT64_C(  -197.92) },
      { SIMDE_FLOAT64_C(   838.72), SIMDE_FLOAT64_C(  -197.92) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_f64x2(simde_mm_load_pd(test_vec[i].r), simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_load_pd1(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    {SIMDE_FLOAT64_C( -639.28), simde_mm_set_pd(SIMDE_FLOAT64_C(-639.28), SIMDE_FLOAT64_C(-639.28)) },
    {SIMDE_FLOAT64_C(  754.31), simde_mm_set_pd(SIMDE_FLOAT64_C( 754.31), SIMDE_FLOAT64_C( 754.31)) },
    {SIMDE_FLOAT64_C( -143.09), simde_mm_set_pd(SIMDE_FLOAT64_C(-143.09), SIMDE_FLOAT64_C(-143.09)) },
    {SIMDE_FLOAT64_C( -509.95), simde_mm_set_pd(SIMDE_FLOAT64_C(-509.95), SIMDE_FLOAT64_C(-509.95)) },
    {SIMDE_FLOAT64_C(  357.11), simde_mm_set_pd(SIMDE_FLOAT64_C( 357.11), SIMDE_FLOAT64_C( 357.11)) },
    {SIMDE_FLOAT64_C(  414.83), simde_mm_set_pd(SIMDE_FLOAT64_C( 414.83), SIMDE_FLOAT64_C( 414.83)) },
    {SIMDE_FLOAT64_C(  416.46), simde_mm_set_pd(SIMDE_FLOAT64_C( 416.46), SIMDE_FLOAT64_C( 416.46)) },
    {SIMDE_FLOAT64_C(  167.42), simde_mm_set_pd(SIMDE_FLOAT64_C( 167.42), SIMDE_FLOAT64_C( 167.42)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_load_pd1(&test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_load_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    {SIMDE_FLOAT64_C(  883.59), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 883.59)) },
    {SIMDE_FLOAT64_C(  719.08), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 719.08)) },
    {SIMDE_FLOAT64_C(  -82.94), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( -82.94)) },
    {SIMDE_FLOAT64_C(  -87.79), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( -87.79)) },
    {SIMDE_FLOAT64_C(  309.31), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 309.31)) },
    {SIMDE_FLOAT64_C( -987.67), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C(-987.67)) },
    {SIMDE_FLOAT64_C(  196.18), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 196.18)) },
    {SIMDE_FLOAT64_C(  313.82), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 313.82)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_load_sd(&test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_load_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1485513264), INT32_C( 2130924320), INT32_C( 1226074611), INT32_C( -306486659)),
      simde_mm_set_epi32(INT32_C(-1485513264), INT32_C( 2130924320), INT32_C( 1226074611), INT32_C( -306486659)) },
    { simde_mm_set_epi32(INT32_C(  952258085), INT32_C( -534886765), INT32_C( -354984724), INT32_C(-1450427500)),
      simde_mm_set_epi32(INT32_C(  952258085), INT32_C( -534886765), INT32_C( -354984724), INT32_C(-1450427500)) },
    { simde_mm_set_epi32(INT32_C(-1417585996), INT32_C(  546041970), INT32_C(-1469146664), INT32_C(-2062567602)),
      simde_mm_set_epi32(INT32_C(-1417585996), INT32_C(  546041970), INT32_C(-1469146664), INT32_C(-2062567602)) },
    { simde_mm_set_epi32(INT32_C(-1482230799), INT32_C(-1421432180), INT32_C(-1588201284), INT32_C(-1267673212)),
      simde_mm_set_epi32(INT32_C(-1482230799), INT32_C(-1421432180), INT32_C(-1588201284), INT32_C(-1267673212)) },
    { simde_mm_set_epi32(INT32_C(-1153380991), INT32_C( 1838203743), INT32_C( -180063833), INT32_C( -699223421)),
      simde_mm_set_epi32(INT32_C(-1153380991), INT32_C( 1838203743), INT32_C( -180063833), INT32_C( -699223421)) },
    { simde_mm_set_epi32(INT32_C( -711752348), INT32_C(  464328511), INT32_C( 1773807699), INT32_C(  849844772)),
      simde_mm_set_epi32(INT32_C( -711752348), INT32_C(  464328511), INT32_C( 1773807699), INT32_C(  849844772)) },
    { simde_mm_set_epi32(INT32_C(-1083662155), INT32_C( -641783129), INT32_C(-1893537704), INT32_C( 1971283674)),
      simde_mm_set_epi32(INT32_C(-1083662155), INT32_C( -641783129), INT32_C(-1893537704), INT32_C( 1971283674)) },
    { simde_mm_set_epi32(INT32_C(-1329936037), INT32_C( -364329957), INT32_C(-1886427840), INT32_C(-1935682760)),
      simde_mm_set_epi32(INT32_C(-1329936037), INT32_C( -364329957), INT32_C(-1886427840), INT32_C(-1935682760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_load_si128(&test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_loadh_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde_float64 b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -625.39), SIMDE_FLOAT64_C( -212.79)),
SIMDE_FLOAT64_C(       -544.03),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -544.03), SIMDE_FLOAT64_C( -212.79)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  906.58), SIMDE_FLOAT64_C( -446.43)),
SIMDE_FLOAT64_C(       -955.62),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -955.62), SIMDE_FLOAT64_C( -446.43)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  575.38), SIMDE_FLOAT64_C( -468.21)),
SIMDE_FLOAT64_C(       -790.22),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -790.22), SIMDE_FLOAT64_C( -468.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  375.10), SIMDE_FLOAT64_C( -731.74)),
SIMDE_FLOAT64_C(        857.52),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  857.52), SIMDE_FLOAT64_C( -731.74)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -48.07), SIMDE_FLOAT64_C( -201.78)),
SIMDE_FLOAT64_C(       -122.99),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -122.99), SIMDE_FLOAT64_C( -201.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   97.66), SIMDE_FLOAT64_C( -743.76)),
SIMDE_FLOAT64_C(        123.61),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  123.61), SIMDE_FLOAT64_C( -743.76)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  622.43), SIMDE_FLOAT64_C( -815.78)),
SIMDE_FLOAT64_C(       -884.62),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -884.62), SIMDE_FLOAT64_C( -815.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  233.02), SIMDE_FLOAT64_C(  337.90)),
SIMDE_FLOAT64_C(        566.08),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  566.08), SIMDE_FLOAT64_C(  337.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadh_pd(test_vec[i].a, &test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_loadl_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a;
    const int64_t r[2];
  } test_vec[] = {
    { -INT64_C( 5374209034103506743),
      { -INT64_C( 5374209034103506743),  INT64_C(0) } },
    { -INT64_C( 8818261387786582106),
      { -INT64_C( 8818261387786582106),  INT64_C(0) } },
    {  INT64_C( 8778417490344874118),
      {  INT64_C( 8778417490344874118),  INT64_C(0) } },
    {  INT64_C( 1040805703196854697),
      {  INT64_C( 1040805703196854697),  INT64_C(0) } },
    { -INT64_C( 6883770744639848089),
      { -INT64_C( 6883770744639848089),  INT64_C(0) } },
    { -INT64_C( 6091281060752135947),
      { -INT64_C( 6091281060752135947),  INT64_C(0) } },
    {  INT64_C( 7649374694561713533),
      {  INT64_C( 7649374694561713533),  INT64_C(0) } },
    {  INT64_C( 9018079017176557522),
      {  INT64_C( 9018079017176557522),  INT64_C(0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_loadl_epi64(SIMDE_ALIGN_CAST(simde__m128i const*, &test_vec[i].a));
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_loadl_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde_float64 b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  398.25), SIMDE_FLOAT64_C(  169.44)),
SIMDE_FLOAT64_C(        512.14),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  398.25), SIMDE_FLOAT64_C(  512.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  747.05), SIMDE_FLOAT64_C(  122.36)),
SIMDE_FLOAT64_C(       -219.24),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  747.05), SIMDE_FLOAT64_C( -219.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  806.68), SIMDE_FLOAT64_C(  439.45)),
SIMDE_FLOAT64_C(        545.31),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  806.68), SIMDE_FLOAT64_C(  545.31)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -494.45), SIMDE_FLOAT64_C(  273.54)),
SIMDE_FLOAT64_C(        233.72),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -494.45), SIMDE_FLOAT64_C(  233.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -435.22), SIMDE_FLOAT64_C( -790.14)),
SIMDE_FLOAT64_C(        334.56),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -435.22), SIMDE_FLOAT64_C(  334.56)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -387.92), SIMDE_FLOAT64_C(  587.13)),
SIMDE_FLOAT64_C(        782.99),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -387.92), SIMDE_FLOAT64_C(  782.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -656.10), SIMDE_FLOAT64_C( -868.90)),
SIMDE_FLOAT64_C(       -241.17),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -656.10), SIMDE_FLOAT64_C( -241.17)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  155.11), SIMDE_FLOAT64_C( -412.38)),
SIMDE_FLOAT64_C(        606.64),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  155.11), SIMDE_FLOAT64_C(  606.64)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadl_pd(test_vec[i].a, &test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_loadr_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 mem_addr[2];
    simde__m128d r;
  } test_vec[8] = {
    { {SIMDE_FLOAT64_C(   808.22), SIMDE_FLOAT64_C( -538.55) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 808.22), SIMDE_FLOAT64_C(-538.55)) },
    { {SIMDE_FLOAT64_C(   475.76), SIMDE_FLOAT64_C(  878.69) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 475.76), SIMDE_FLOAT64_C( 878.69)) },
    { {SIMDE_FLOAT64_C(  -400.00), SIMDE_FLOAT64_C( -135.07) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-400.00), SIMDE_FLOAT64_C(-135.07)) },
    { {SIMDE_FLOAT64_C(   -32.33), SIMDE_FLOAT64_C( -148.19) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( -32.33), SIMDE_FLOAT64_C(-148.19)) },
    { {SIMDE_FLOAT64_C(  -971.23), SIMDE_FLOAT64_C( -835.90) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-971.23), SIMDE_FLOAT64_C(-835.90)) },
    { {SIMDE_FLOAT64_C(  -891.74), SIMDE_FLOAT64_C( -424.87) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-891.74), SIMDE_FLOAT64_C(-424.87)) },
    { {SIMDE_FLOAT64_C(  -199.77), SIMDE_FLOAT64_C(  631.45) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-199.77), SIMDE_FLOAT64_C( 631.45)) },
    { {SIMDE_FLOAT64_C(   410.30), SIMDE_FLOAT64_C(  721.68) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 410.30), SIMDE_FLOAT64_C( 721.68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadr_pd(test_vec[i].mem_addr);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_loadu_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 mem_addr[2];
    simde__m128d r;
  } test_vec[8] = {
    { {SIMDE_FLOAT64_C(  -578.02), SIMDE_FLOAT64_C(   20.66) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(  20.66), SIMDE_FLOAT64_C(-578.02)) },
    { {SIMDE_FLOAT64_C(   370.06), SIMDE_FLOAT64_C( -720.89) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-720.89), SIMDE_FLOAT64_C( 370.06)) },
    { {SIMDE_FLOAT64_C(   584.38), SIMDE_FLOAT64_C( -849.44) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-849.44), SIMDE_FLOAT64_C( 584.38)) },
    { {SIMDE_FLOAT64_C(   636.90), SIMDE_FLOAT64_C(  349.95) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 349.95), SIMDE_FLOAT64_C( 636.90)) },
    { {SIMDE_FLOAT64_C(  -617.52), SIMDE_FLOAT64_C(  599.47) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 599.47), SIMDE_FLOAT64_C(-617.52)) },
    { {SIMDE_FLOAT64_C(   633.70), SIMDE_FLOAT64_C(   30.57) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(  30.57), SIMDE_FLOAT64_C( 633.70)) },
    { {SIMDE_FLOAT64_C(  -333.40), SIMDE_FLOAT64_C(  592.38) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 592.38), SIMDE_FLOAT64_C(-333.40)) },
    { {SIMDE_FLOAT64_C(  -335.86), SIMDE_FLOAT64_C(  212.26) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 212.26), SIMDE_FLOAT64_C(-335.86)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadu_pd(test_vec[i].mem_addr);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_loadu_si128 (SIMDE_MUNIT_TEST_ARGS) {
  #if !defined(__clang__) || !defined(SIMDE_ARCH_ARM)
  static const struct {
    const int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(   431648212),  INT32_C(   784010008), -INT32_C(  1621020084),  INT32_C(  1563595920) } },
    { { -INT32_C(  2020743978),  INT32_C(   642031476), -INT32_C(  1168838661), -INT32_C(    71485745) } },
    { { -INT32_C(   505281848),  INT32_C(  1510972686),  INT32_C(  1626960080), -INT32_C(   608359675) } },
    { { -INT32_C(  2073933297), -INT32_C(   441800983),  INT32_C(  1688206997), -INT32_C(    44016587) } },
    { {  INT32_C(  1843282527), -INT32_C(  1345851937),  INT32_C(  1661976670), -INT32_C(    79770388) } },
    { {  INT32_C(     8364054), -INT32_C(   605738426),  INT32_C(  1564443688),  INT32_C(  1079746529) } },
    { { -INT32_C(  1045612063), -INT32_C(  2056227801),  INT32_C(   552108084),  INT32_C(  1662789196) } },
    { {  INT32_C(   207854534), -INT32_C(   286832443), -INT32_C(  1387583796), -INT32_C(  1477597498) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r[4];
    simde_mm_storeu_si128(SIMDE_ALIGN_CAST(simde__m128i*, r), simde_mm_loadu_si128(SIMDE_ALIGN_CAST(const simde__m128i*, test_vec[i].a)));
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].a);
  }
  #endif

  return 0;
}

static int
test_simde_mm_loadu_si16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a;
    const int16_t r[8];
  } test_vec[] = {
    { -INT16_C( 11138),
      { -INT16_C( 11138),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C( 23724),
      {  INT16_C( 23724),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C( 14484),
      {  INT16_C( 14484),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C( 13428),
      {  INT16_C( 13428),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { -INT16_C(  4679),
      { -INT16_C(  4679),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { -INT16_C( 27444),
      { -INT16_C( 27444),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C( 23920),
      {  INT16_C( 23920),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    {  INT16_C( 10692),
      {  INT16_C( 10692),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    simde__m128i r = HEDLEY_CONCAT(simde,_mm_loadu_si16)(&a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_loadu_si32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a;
    const int32_t r[4];
  } test_vec[] = {
    {  INT32_C(   418822831),
      {  INT32_C(   418822831),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    {  INT32_C(  1942173819),
      {  INT32_C(  1942173819),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    {  INT32_C(  1655488478),
      {  INT32_C(  1655488478),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { -INT32_C(  1203443910),
      { -INT32_C(  1203443910),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    {  INT32_C(  1326772667),
      {  INT32_C(  1326772667),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { -INT32_C(   494630871),
      { -INT32_C(   494630871),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { -INT32_C(   445230987),
      { -INT32_C(   445230987),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    {  INT32_C(  1544436653),
      {  INT32_C(  1544436653),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde__m128i r = HEDLEY_CONCAT(simde,_mm_loadu_si32)(&a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_loadu_si64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a;
    const int64_t r[2];
  } test_vec[] = {
    {  INT64_C( 1937454096935355637),
      {  INT64_C( 1937454096935355637),  INT64_C(                   0) } },
    {  INT64_C( 3668957564122271735),
      {  INT64_C( 3668957564122271735),  INT64_C(                   0) } },
    { -INT64_C(  235024424980250958),
      { -INT64_C(  235024424980250958),  INT64_C(                   0) } },
    {  INT64_C( 7233045361154208854),
      {  INT64_C( 7233045361154208854),  INT64_C(                   0) } },
    {  INT64_C(  309823741680211445),
      {  INT64_C(  309823741680211445),  INT64_C(                   0) } },
    {  INT64_C( 4463101911464528198),
      {  INT64_C( 4463101911464528198),  INT64_C(                   0) } },
    { -INT64_C( 3557326416991718882),
      { -INT64_C( 3557326416991718882),  INT64_C(                   0) } },
    {  INT64_C( 7628307720165229322),
      {  INT64_C( 7628307720165229322),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde__m128i r = HEDLEY_CONCAT(simde,_mm_loadu_si64)(&a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_madd_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 24289), INT16_C( 22642), INT16_C( 24338), INT16_C( 21466),
                         INT16_C(-21399), INT16_C(-25114), INT16_C(   -38), INT16_C( 24157)),
      simde_mm_set_epi16(INT16_C( -9939), INT16_C(-13077), INT16_C(-13691), INT16_C(-22496),
                         INT16_C( -7750), INT16_C(  2620), INT16_C(-25114), INT16_C(  6535)),
      simde_mm_set_epi32( -537497805,  -816110694,   100043570,   158820327) },
    { simde_mm_set_epi16(INT16_C( 13645), INT16_C( 20663), INT16_C( 21053), INT16_C(  5963),
                         INT16_C( -9189), INT16_C( -1395), INT16_C( 25221), INT16_C( 27070)),
      simde_mm_set_epi16(INT16_C(-28936), INT16_C(-24038), INT16_C(  6837), INT16_C( 18195),
                         INT16_C(-15316), INT16_C(-11637), INT16_C(  5200), INT16_C(  7885)),
      simde_mm_set_epi32( -891528914,   252436146,   156972339,   344596150) },
    { simde_mm_set_epi16(INT16_C(-31367), INT16_C(-13886), INT16_C( 25125), INT16_C(-12503),
                         INT16_C( 15451), INT16_C( -6370), INT16_C(-24113), INT16_C(  2653)),
      simde_mm_set_epi16(INT16_C(  5595), INT16_C(-23387), INT16_C(-11854), INT16_C(   264),
                         INT16_C( 15071), INT16_C(  3868), INT16_C(-30127), INT16_C(  2383)),
      simde_mm_set_epi32(  149253517,  -301132542,   208222861,   732774450) },
    { simde_mm_set_epi16(INT16_C(  6250), INT16_C(   794), INT16_C( -7973), INT16_C( 27046),
                         INT16_C( 13164), INT16_C( 16469), INT16_C(  1989), INT16_C(-24542)),
      simde_mm_set_epi16(INT16_C( 22452), INT16_C( -4402), INT16_C(-26550), INT16_C( 31252),
                         INT16_C(-29251), INT16_C( -1650), INT16_C(-13867), INT16_C( 26387)),
      simde_mm_set_epi32(  136829812,  1056924742,  -412234014,  -675171217) },
    { simde_mm_set_epi16(INT16_C(-17693), INT16_C(-18978), INT16_C( 22797), INT16_C( 31393),
                         INT16_C( 32262), INT16_C(-21009), INT16_C(  9435), INT16_C( 20059)),
      simde_mm_set_epi16(INT16_C( 20064), INT16_C(  4406), INT16_C(  1105), INT16_C(-32185),
                         INT16_C( 26331), INT16_C( -8672), INT16_C( 15113), INT16_C(-24381)),
      simde_mm_set_epi32( -438609420,  -985193020,  1031680770,  -346467324) },
    { simde_mm_set_epi16(INT16_C( -9214), INT16_C(-31455), INT16_C(-14871), INT16_C( -8603),
                         INT16_C( 17039), INT16_C(-27694), INT16_C( 18091), INT16_C( 27811)),
      simde_mm_set_epi16(INT16_C(  9903), INT16_C(  7626), INT16_C( -7009), INT16_C(-11696),
                         INT16_C(-31989), INT16_C( 28434), INT16_C(-24743), INT16_C(-27058)),
      simde_mm_set_epi32( -331122072,   204851527, -1332511767, -1200135651) },
    { simde_mm_set_epi16(INT16_C( 20741), INT16_C(  5382), INT16_C(-29692), INT16_C( 12589),
                         INT16_C( 21204), INT16_C(  3076), INT16_C(-24365), INT16_C( -1783)),
      simde_mm_set_epi16(INT16_C(-15203), INT16_C(-26894), INT16_C( -6878), INT16_C(-23472),
                         INT16_C(-18994), INT16_C( 11044), INT16_C( 15739), INT16_C(  -241)),
      simde_mm_set_epi32( -460068931,   -91267432,  -368777432,  -383051032) },
    { simde_mm_set_epi16(INT16_C( 24682), INT16_C( 17647), INT16_C(-19806), INT16_C(-13656),
                         INT16_C( 26394), INT16_C(  4814), INT16_C( -4589), INT16_C( 17983)),
      simde_mm_set_epi16(INT16_C(-32304), INT16_C(-30224), INT16_C(-20430), INT16_C(-28018),
                         INT16_C( 29012), INT16_C(  7494), INT16_C( -7871), INT16_C( 16228)),
      simde_mm_set_epi32(-1330690256,   787250388,   801818844,   327948143) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_madd_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_maskmoveu_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i mask;
    int8_t i[16];
    int8_t r[16];
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-127), INT8_C( 121), INT8_C(  33), INT8_C(  92), INT8_C(  95), INT8_C(  30), INT8_C( 117), INT8_C( 103),
                        INT8_C( -74), INT8_C( -18), INT8_C(  28), INT8_C(  15), INT8_C(-111), INT8_C( -65), INT8_C( 117), INT8_C(  -8)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(  73), INT8_C(   1), INT8_C( -97), INT8_C( -45), INT8_C(  24), INT8_C(  88), INT8_C( -76),
                        INT8_C(-109), INT8_C(  78), INT8_C( -80), INT8_C( -97), INT8_C(  85), INT8_C( 102), INT8_C(  36), INT8_C( -19)),
      {    0, -116,  -92,  122,  -68,   23,  -43,   86,
         -50,  -28,  -43,   -3,   19, -114,  122,   62 },
      {   -8, -116,  -92,  122,   15,   28,  -43,  -74,
         103,  -28,  -43,   95,   92, -114,  122,   62 } },
    { simde_mm_set_epi8(INT8_C(  70), INT8_C( 102), INT8_C( -59), INT8_C(   6), INT8_C( -83), INT8_C(  40), INT8_C( -32), INT8_C(  43),
                        INT8_C(  90), INT8_C(-118), INT8_C(  82), INT8_C(  24), INT8_C(-106), INT8_C( -61), INT8_C( -19), INT8_C(-101)),
      simde_mm_set_epi8(INT8_C(  17), INT8_C( -58), INT8_C( -68), INT8_C(  86), INT8_C(  20), INT8_C(  40), INT8_C(  60), INT8_C(  30),
                        INT8_C(  31), INT8_C(  30), INT8_C(  18), INT8_C(  67), INT8_C(  -9), INT8_C( 103), INT8_C(  21), INT8_C( -50)),
      { -125,  126,  -10,  -60,   19,   92,   -8, -124,
          81, -122,  122,   13,  -58,   49, -122,   24 },
      { -101,  126,  -10, -106,   19,   92,   -8, -124,
          81, -122,  122,   13,  -58,  -59,  102,   24 } },
    { simde_mm_set_epi8(INT8_C( -26), INT8_C(-127), INT8_C(  58), INT8_C( -79), INT8_C( -88), INT8_C(-105), INT8_C( -66), INT8_C(  41),
                        INT8_C(  75), INT8_C( -34), INT8_C(  97), INT8_C( -55), INT8_C( -65), INT8_C( -30), INT8_C(  23), INT8_C(  28)),
      simde_mm_set_epi8(INT8_C(-107), INT8_C(  69), INT8_C( -28), INT8_C( -40), INT8_C( 105), INT8_C(   0), INT8_C( 114), INT8_C( 113),
                        INT8_C( -65), INT8_C( -82), INT8_C(  87), INT8_C( -14), INT8_C( -36), INT8_C(  68), INT8_C(-120), INT8_C(  38)),
      { -114,   55,  -16,   51,  110,  -44,   59,   -6,
          43,  -95,  -82,  119,  -56,    9,  -47,  -20 },
      { -114,   23,  -16,  -65,  -55,  -44,  -34,   75,
          43,  -95,  -82,  119,  -79,   58,  -47,  -26 } },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C(  99), INT8_C(  22), INT8_C(  78), INT8_C(  93), INT8_C( -44), INT8_C( -98), INT8_C(  62),
                        INT8_C( -97), INT8_C( -50), INT8_C( -31), INT8_C(-109), INT8_C(  10), INT8_C( -86), INT8_C( -15), INT8_C(   7)),
      simde_mm_set_epi8(INT8_C(  96), INT8_C(  76), INT8_C(  14), INT8_C(-114), INT8_C(  84), INT8_C( -85), INT8_C(  61), INT8_C( -38),
                        INT8_C( -45), INT8_C( -83), INT8_C( -13), INT8_C( -50), INT8_C( -35), INT8_C(-111), INT8_C(-107), INT8_C( -50)),
      {   -8,   64,  -68,   23, -101,   35,  126,  119,
         -47,    4,   79,   23,  113,  117,  -76,   93 },
      {    7,  -15,  -86,   10, -109,  -31,  -50,  -97,
          62,    4,  -44,   23,   78,  117,  -76,   93 } },
    { simde_mm_set_epi8(INT8_C( -38), INT8_C(-119), INT8_C( -46), INT8_C( -13), INT8_C(  -3), INT8_C(-122), INT8_C(  75), INT8_C( 123),
                        INT8_C(  26), INT8_C( -71), INT8_C( -42), INT8_C(-124), INT8_C(  49), INT8_C(   1), INT8_C(   5), INT8_C( -90)),
      simde_mm_set_epi8(INT8_C( 116), INT8_C(  -8), INT8_C(  33), INT8_C(  63), INT8_C(-110), INT8_C( -94), INT8_C( -34), INT8_C(  66),
                        INT8_C(  51), INT8_C(-117), INT8_C(  28), INT8_C( -95), INT8_C( -52), INT8_C( 122), INT8_C( 118), INT8_C( -99)),
      {  -45,   85,   12,   62,  -89, -105,   90,  -19,
          48,   18,  -59,  -98,  -30, -113,   13,   91 },
      {  -90,   85,   12,   49, -124, -105,  -71,  -19,
          48,   75, -122,   -3,  -30, -113, -119,   91 } },
    { simde_mm_set_epi8(INT8_C(  52), INT8_C(  36), INT8_C( 112), INT8_C(  70), INT8_C( 110), INT8_C(  75), INT8_C(  -6), INT8_C(-101),
                        INT8_C(   3), INT8_C( 113), INT8_C( -32), INT8_C( 119), INT8_C( -19), INT8_C( 117), INT8_C(  31), INT8_C( 119)),
      simde_mm_set_epi8(INT8_C(  79), INT8_C(  39), INT8_C(   6), INT8_C(  30), INT8_C( 120), INT8_C( -75), INT8_C(  26), INT8_C(  57),
                        INT8_C( 123), INT8_C(  70), INT8_C(  40), INT8_C(  84), INT8_C( 111), INT8_C( -59), INT8_C( -79), INT8_C( -87)),
      {  -74,   -2, -124,   73,   44,   83,   18,  -48,
         -78,   27,   30,  -26,   -3,   56,   89,  125 },
      {  119,   31,  117,   73,   44,   83,   18,  -48,
         -78,   27,   75,  -26,   -3,   56,   89,  125 } },
    { simde_mm_set_epi8(INT8_C( -83), INT8_C( -42), INT8_C(-124), INT8_C( -81), INT8_C( -65), INT8_C(  46), INT8_C( -62), INT8_C( 102),
                        INT8_C(  50), INT8_C(   6), INT8_C(  -6), INT8_C( -21), INT8_C( -51), INT8_C(-114), INT8_C(-126), INT8_C(  74)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-119), INT8_C( -85), INT8_C(  95), INT8_C(  70), INT8_C( -40), INT8_C(  17), INT8_C( 124),
                        INT8_C( -61), INT8_C(-126), INT8_C( 117), INT8_C( -42), INT8_C(  62), INT8_C(-111), INT8_C(-103), INT8_C(  57)),
      {  108,   40, -118,  -12,   90,  -12,  -24,   50,
         104,   87,  -20,  -86,  -53,   25,  -94, -101 },
      {  108, -126, -114,  -12,  -21,  -12,    6,   50,
         104,   87,   46,  -86,  -53, -124,  -42, -101 } },
    { simde_mm_set_epi8(INT8_C( -23), INT8_C( -92), INT8_C(  93), INT8_C( -78), INT8_C( -39), INT8_C( -72), INT8_C( -43), INT8_C(   1),
                        INT8_C(-121), INT8_C( 103), INT8_C(  61), INT8_C(  82), INT8_C(  45), INT8_C(-120), INT8_C( -86), INT8_C(  51)),
      simde_mm_set_epi8(INT8_C( -82), INT8_C(  92), INT8_C( -46), INT8_C( -97), INT8_C(  59), INT8_C( -16), INT8_C(  95), INT8_C( -85),
                        INT8_C(  38), INT8_C(  36), INT8_C(-125), INT8_C(  74), INT8_C(  14), INT8_C(  75), INT8_C( -74), INT8_C( -25)),
      {  -53,   48,   63,  -44, -103,   12,   49,   -1,
         -58,   70,  -18, -117,  101,  -90,  121,  -31 },
      {   51,  -86,   63,  -44, -103,   61,   49,   -1,
           1,   70,  -72, -117,  -78,   93,  121,  -23 } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int8_t r[16];
    simde_memcpy(r, test_vec[i].i, 16);

    #if defined SIMDE_X86_SSE2_NATIVE && defined SIMDE_NATIVE_ALIASES_TESTING
      simde_mm_maskmoveu_si128(test_vec[i].a, test_vec[i].mask, HEDLEY_REINTERPRET_CAST(char *, r));
    #else
      simde_mm_maskmoveu_si128(test_vec[i].a, test_vec[i].mask, r);
    #endif

    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(164, 110, 116,  95,  43, 222, 122,  21,
                           12,  65, 208, 248, 108, 166, 116,  17),
      simde_x_mm_set_epu8( 56,  62, 214,  11, 248, 124,  69,   2,
                          198, 169, 227, 124, 192, 250, 140,  32),
      simde_x_mm_set_epu8( 56,  62, 116,  11,  43, 124,  69,   2,
                           12,  65, 208, 124, 108, 166, 116,  17) },
    { simde_x_mm_set_epu8(136, 183, 233,  96,  11,  36, 213, 146,
                          238, 174,  59, 229,  56, 186, 203,  28),
      simde_x_mm_set_epu8( 82,  12,   9, 200, 196, 116, 127, 247,
                            1,  69, 178, 128,  65,  11, 179, 176),
      simde_x_mm_set_epu8( 82,  12,   9,  96,  11,  36, 127, 146,
                            1,  69,  59, 128,  56,  11, 179,  28) },
    { simde_x_mm_set_epu8(164,  64, 195, 253,  35,  95, 119, 110,
                          106, 102,  21, 173,  49,  40, 101, 151),
      simde_x_mm_set_epu8(109,  25,  32, 203,  64,  71,  33,  98,
                           48,  43, 195,  67, 254, 158, 167, 217),
      simde_x_mm_set_epu8(109,  25,  32, 203,  35,  71,  33,  98,
                           48,  43,  21,  67,  49,  40, 101, 151) },
    { simde_x_mm_set_epu8(233, 255, 136, 159, 118, 246,  37,   8,
                          195,  35,  70,   7,  91,  37,  20, 112),
      simde_x_mm_set_epu8(  4,  91, 243, 163, 160,  26, 137, 208,
                          146, 195, 124, 148,  53,  99,  21, 240),
      simde_x_mm_set_epu8(  4,  91, 136, 159, 118,  26,  37,   8,
                          146,  35,  70,   7,  53,  37,  20, 112) },
    { simde_x_mm_set_epu8(196,   4, 110, 234,  88, 121, 133, 146,
                          127, 167, 173, 105, 205,   0, 197, 107),
      simde_x_mm_set_epu8(240, 105, 248,  55, 202, 217, 219, 230,
                          183, 240,  91, 164, 168,   6,  75, 186),
      simde_x_mm_set_epu8(196,   4, 110,  55,  88, 121, 133, 146,
                          127, 167,  91, 105, 168,   0,  75, 107) },
    { simde_x_mm_set_epu8(191, 108, 145, 178, 194, 118, 187, 175,
                           80, 196,  99, 239,   6, 206, 186, 130),
      simde_x_mm_set_epu8(109, 182, 208,  91, 232, 171,  41, 238,
                          121, 144, 203,  42, 182,  89,  69, 166),
      simde_x_mm_set_epu8(109, 108, 145,  91, 194, 118,  41, 175,
                           80, 144,  99,  42,   6,  89,  69, 130) },
    { simde_x_mm_set_epu8(  5, 152, 184, 251, 233,  22, 184, 152,
                           12, 126, 120,  80, 191,  98,  37,  36),
      simde_x_mm_set_epu8(194, 116, 229, 250, 247, 241, 153, 192,
                           20, 172, 224, 148, 240, 246, 120,   0),
      simde_x_mm_set_epu8(  5, 116, 184, 250, 233,  22, 153, 152,
                           12, 126, 120,  80, 191,  98,  37,   0) },
    { simde_x_mm_set_epu8(188, 102, 137, 134, 213,   1, 140, 166,
                          143, 171, 248,  89, 128,  81, 226, 136),
      simde_x_mm_set_epu8(246, 210,  83, 107,  44, 255, 100, 235,
                           99, 233, 199, 197,   1, 159,  61,  31),
      simde_x_mm_set_epu8(188, 102,  83, 107,  44,   1, 100, 166,
                           99, 171, 199,  89,   1,  81,  61,  31) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-23442), INT16_C( 29791), INT16_C( 11230), INT16_C( 31253),
                         INT16_C(  3137), INT16_C(-12040), INT16_C( 27814), INT16_C( 29713)),
      simde_mm_set_epi16(INT16_C( 14398), INT16_C(-10741), INT16_C( -1924), INT16_C( 17666),
                         INT16_C(-14679), INT16_C( -7300), INT16_C(-16134), INT16_C(-29664)),
      simde_mm_set_epi16(INT16_C(-23442), INT16_C(-10741), INT16_C( -1924), INT16_C( 17666),
                         INT16_C(-14679), INT16_C(-12040), INT16_C(-16134), INT16_C(-29664)) },
    { simde_mm_set_epi16(INT16_C(-30537), INT16_C( -5792), INT16_C(  2852), INT16_C(-10862),
                         INT16_C( -4434), INT16_C( 15333), INT16_C( 14522), INT16_C(-13540)),
      simde_mm_set_epi16(INT16_C( 21004), INT16_C(  2504), INT16_C(-15244), INT16_C( 32759),
                         INT16_C(   325), INT16_C(-19840), INT16_C( 16651), INT16_C(-19536)),
      simde_mm_set_epi16(INT16_C(-30537), INT16_C( -5792), INT16_C(-15244), INT16_C(-10862),
                         INT16_C( -4434), INT16_C(-19840), INT16_C( 14522), INT16_C(-19536)) },
    { simde_mm_set_epi16(INT16_C(-23488), INT16_C(-15363), INT16_C(  9055), INT16_C( 30574),
                         INT16_C( 27238), INT16_C(  5549), INT16_C( 12584), INT16_C( 26007)),
      simde_mm_set_epi16(INT16_C( 27929), INT16_C(  8395), INT16_C( 16455), INT16_C(  8546),
                         INT16_C( 12331), INT16_C(-15549), INT16_C(  -354), INT16_C(-22567)),
      simde_mm_set_epi16(INT16_C(-23488), INT16_C(-15363), INT16_C(  9055), INT16_C(  8546),
                         INT16_C( 12331), INT16_C(-15549), INT16_C(  -354), INT16_C(-22567)) },
    { simde_mm_set_epi16(INT16_C( -5633), INT16_C(-30561), INT16_C( 30454), INT16_C(  9480),
                         INT16_C(-15581), INT16_C( 17927), INT16_C( 23333), INT16_C(  5232)),
      simde_mm_set_epi16(INT16_C(  1115), INT16_C( -3165), INT16_C(-24550), INT16_C(-30256),
                         INT16_C(-27965), INT16_C( 31892), INT16_C( 13667), INT16_C(  5616)),
      simde_mm_set_epi16(INT16_C( -5633), INT16_C(-30561), INT16_C(-24550), INT16_C(-30256),
                         INT16_C(-27965), INT16_C( 17927), INT16_C( 13667), INT16_C(  5232)) },
    { simde_mm_set_epi16(INT16_C(-15356), INT16_C( 28394), INT16_C( 22649), INT16_C(-31342),
                         INT16_C( 32679), INT16_C(-21143), INT16_C(-13056), INT16_C(-14997)),
      simde_mm_set_epi16(INT16_C( -3991), INT16_C( -1993), INT16_C(-13607), INT16_C( -9242),
                         INT16_C(-18448), INT16_C( 23460), INT16_C(-22522), INT16_C( 19386)),
      simde_mm_set_epi16(INT16_C(-15356), INT16_C( -1993), INT16_C(-13607), INT16_C(-31342),
                         INT16_C(-18448), INT16_C(-21143), INT16_C(-22522), INT16_C(-14997)) },
    { simde_mm_set_epi16(INT16_C(-16532), INT16_C(-28238), INT16_C(-15754), INT16_C(-17489),
                         INT16_C( 20676), INT16_C( 25583), INT16_C(  1742), INT16_C(-17790)),
      simde_mm_set_epi16(INT16_C( 28086), INT16_C(-12197), INT16_C( -5973), INT16_C( 10734),
                         INT16_C( 31120), INT16_C(-13526), INT16_C(-18855), INT16_C( 17830)),
      simde_mm_set_epi16(INT16_C(-16532), INT16_C(-28238), INT16_C(-15754), INT16_C(-17489),
                         INT16_C( 20676), INT16_C(-13526), INT16_C(-18855), INT16_C(-17790)) },
    { simde_mm_set_epi16(INT16_C(  1432), INT16_C(-18181), INT16_C( -5866), INT16_C(-18280),
                         INT16_C(  3198), INT16_C( 30800), INT16_C(-16542), INT16_C(  9508)),
      simde_mm_set_epi16(INT16_C(-15756), INT16_C( -6662), INT16_C( -2063), INT16_C(-26176),
                         INT16_C(  5292), INT16_C( -8044), INT16_C( -3850), INT16_C( 30720)),
      simde_mm_set_epi16(INT16_C(-15756), INT16_C(-18181), INT16_C( -5866), INT16_C(-26176),
                         INT16_C(  3198), INT16_C( -8044), INT16_C(-16542), INT16_C(  9508)) },
    { simde_mm_set_epi16(INT16_C(-17306), INT16_C(-30330), INT16_C(-11007), INT16_C(-29530),
                         INT16_C(-28757), INT16_C( -1959), INT16_C(-32687), INT16_C( -7544)),
      simde_mm_set_epi16(INT16_C( -2350), INT16_C( 21355), INT16_C( 11519), INT16_C( 25835),
                         INT16_C( 25577), INT16_C(-14395), INT16_C(   415), INT16_C( 15647)),
      simde_mm_set_epi16(INT16_C(-17306), INT16_C(-30330), INT16_C(-11007), INT16_C(-29530),
                         INT16_C(-28757), INT16_C(-14395), INT16_C(-32687), INT16_C( -7544)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[10] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.71), SIMDE_FLOAT64_C(  927.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C(  925.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -589.60), SIMDE_FLOAT64_C( -498.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C( -498.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  572.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.04), SIMDE_FLOAT64_C(  293.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  293.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  321.70), SIMDE_FLOAT64_C( -283.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   60.35), SIMDE_FLOAT64_C( -248.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   60.35), SIMDE_FLOAT64_C( -283.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C(  763.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  150.47), SIMDE_FLOAT64_C( -773.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C( -773.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.86), SIMDE_FLOAT64_C(  169.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.89), SIMDE_FLOAT64_C(  325.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.89), SIMDE_FLOAT64_C(  169.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C(  883.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -450.39), SIMDE_FLOAT64_C( -249.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C( -249.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C(  415.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C( -567.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C( -567.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -567.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -567.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -567.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C(    0.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C(    0.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C(    0.00)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_min_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_min_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.71), SIMDE_FLOAT64_C(  927.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C(  925.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -589.60), SIMDE_FLOAT64_C( -498.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C( -498.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  572.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.04), SIMDE_FLOAT64_C(  293.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  293.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  321.70), SIMDE_FLOAT64_C( -283.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   60.35), SIMDE_FLOAT64_C( -248.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  321.70), SIMDE_FLOAT64_C( -283.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C(  763.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  150.47), SIMDE_FLOAT64_C( -773.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C( -773.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.86), SIMDE_FLOAT64_C(  169.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.89), SIMDE_FLOAT64_C(  325.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.86), SIMDE_FLOAT64_C(  169.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C(  883.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -450.39), SIMDE_FLOAT64_C( -249.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C( -249.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C(  415.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C( -567.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C( -567.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_min_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_max_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(168, 216, 116,  83,  89,  36,  70,  43,
                          213,  80, 178, 134,  66, 113, 243, 129),
      simde_x_mm_set_epu8(121,  26,  77, 212,  58, 167,  83, 180,
                          236,  50,  65, 112, 248, 228,  87, 231),
      simde_x_mm_set_epu8(168, 216, 116, 212,  89, 167,  83, 180,
                          236,  80, 178, 134, 248, 228, 243, 231) },
    { simde_x_mm_set_epu8(157, 143, 244, 146,  49, 140, 145, 221,
                           80,  79, 154,  71,  49, 213, 105,  22),
      simde_x_mm_set_epu8( 81,  58, 115, 104,  26, 180,  63,  33,
                           16, 205,  98, 228, 235, 156, 147, 109),
      simde_x_mm_set_epu8(157, 143, 244, 146,  49, 180, 145, 221,
                           80, 205, 154, 228, 235, 213, 147, 109) },
    { simde_x_mm_set_epu8(120, 153, 102, 244, 149, 171, 101, 141,
                          231, 205, 156,  11, 214, 255,  28, 215),
      simde_x_mm_set_epu8( 89, 227, 119,  48, 219,  88,   0,  68,
                          146, 196, 199,  34, 143, 246, 184,  31),
      simde_x_mm_set_epu8(120, 227, 119, 244, 219, 171, 101, 141,
                          231, 205, 199,  34, 214, 255, 184, 215) },
    { simde_x_mm_set_epu8(201, 221,  39,  38, 119, 106,  89, 236,
                            8,  81, 136,  17,  62,  33, 200,  24),
      simde_x_mm_set_epu8( 76, 153, 167,  42, 171, 206,  46, 181,
                           37, 117,  72, 251, 153,  91, 107,  96),
      simde_x_mm_set_epu8(201, 221, 167,  42, 171, 206,  89, 236,
                           37, 117, 136, 251, 153,  91, 200,  96) },
    { simde_x_mm_set_epu8( 34,  94, 125,  66, 238, 110, 110,  27,
                           90, 179, 184, 250, 202,  62, 132,  68),
      simde_x_mm_set_epu8(135, 208,  31,  76,  51,   5,  50, 220,
                           43, 120,  10, 131, 247, 241, 134, 232),
      simde_x_mm_set_epu8(135, 208, 125,  76, 238, 110, 110, 220,
                           90, 179, 184, 250, 247, 241, 134, 232) },
    { simde_x_mm_set_epu8( 12, 112,  35,  12, 111,   1,  16, 229,
                          119, 199,  69,  96, 220, 123, 153, 230),
      simde_x_mm_set_epu8(147, 155,  56, 136, 236,  16,  93,  16,
                           43, 253, 136, 239, 147,  44, 146,   0),
      simde_x_mm_set_epu8(147, 155,  56, 136, 236,  16,  93, 229,
                          119, 253, 136, 239, 220, 123, 153, 230) },
    { simde_x_mm_set_epu8(138, 177,  86, 183, 144, 112,  42,  67,
                          100, 123, 214, 234,  34, 240,  19,  10),
      simde_x_mm_set_epu8( 81,  53, 255, 195, 169, 127, 131, 109,
                          181, 161, 246, 113,  87,  20, 157, 194),
      simde_x_mm_set_epu8(138, 177, 255, 195, 169, 127, 131, 109,
                          181, 161, 246, 234,  87, 240, 157, 194) },
    { simde_x_mm_set_epu8(  5,  26, 135,  12, 151, 226, 187,  12,
                          213, 244, 209, 245, 136,  13, 164, 249),
      simde_x_mm_set_epu8( 92,  57, 200, 208, 212, 214, 211, 217,
                           65, 228, 179,  64,  34, 236, 220, 208),
      simde_x_mm_set_epu8( 92,  57, 200, 208, 212, 226, 211, 217,
                          213, 244, 209, 245, 136, 236, 220, 249) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_max_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-22312), INT16_C( 29779), INT16_C( 22820), INT16_C( 17963),
                         INT16_C(-10928), INT16_C(-19834), INT16_C( 17009), INT16_C( -3199)),
      simde_mm_set_epi16(INT16_C( 31002), INT16_C( 19924), INT16_C( 15015), INT16_C( 21428),
                         INT16_C( -5070), INT16_C( 16752), INT16_C( -1820), INT16_C( 22503)),
      simde_mm_set_epi16(INT16_C( 31002), INT16_C( 29779), INT16_C( 22820), INT16_C( 21428),
                         INT16_C( -5070), INT16_C( 16752), INT16_C( 17009), INT16_C( 22503)) },
    { simde_mm_set_epi16(INT16_C(-25201), INT16_C( -2926), INT16_C( 12684), INT16_C(-28195),
                         INT16_C( 20559), INT16_C(-26041), INT16_C( 12757), INT16_C( 26902)),
      simde_mm_set_epi16(INT16_C( 20794), INT16_C( 29544), INT16_C(  6836), INT16_C( 16161),
                         INT16_C(  4301), INT16_C( 25316), INT16_C( -5220), INT16_C(-27795)),
      simde_mm_set_epi16(INT16_C( 20794), INT16_C( 29544), INT16_C( 12684), INT16_C( 16161),
                         INT16_C( 20559), INT16_C( 25316), INT16_C( 12757), INT16_C( 26902)) },
    { simde_mm_set_epi16(INT16_C( 30873), INT16_C( 26356), INT16_C(-27221), INT16_C( 25997),
                         INT16_C( -6195), INT16_C(-25589), INT16_C(-10497), INT16_C(  7383)),
      simde_mm_set_epi16(INT16_C( 23011), INT16_C( 30512), INT16_C( -9384), INT16_C(    68),
                         INT16_C(-27964), INT16_C(-14558), INT16_C(-28682), INT16_C(-18401)),
      simde_mm_set_epi16(INT16_C( 30873), INT16_C( 30512), INT16_C( -9384), INT16_C( 25997),
                         INT16_C( -6195), INT16_C(-14558), INT16_C(-10497), INT16_C(  7383)) },
    { simde_mm_set_epi16(INT16_C(-13859), INT16_C( 10022), INT16_C( 30570), INT16_C( 23020),
                         INT16_C(  2129), INT16_C(-30703), INT16_C( 15905), INT16_C(-14312)),
      simde_mm_set_epi16(INT16_C( 19609), INT16_C(-22742), INT16_C(-21554), INT16_C( 11957),
                         INT16_C(  9589), INT16_C( 18683), INT16_C(-26277), INT16_C( 27488)),
      simde_mm_set_epi16(INT16_C( 19609), INT16_C( 10022), INT16_C( 30570), INT16_C( 23020),
                         INT16_C(  9589), INT16_C( 18683), INT16_C( 15905), INT16_C( 27488)) },
    { simde_mm_set_epi16(INT16_C(  8798), INT16_C( 32066), INT16_C( -4498), INT16_C( 28187),
                         INT16_C( 23219), INT16_C(-18182), INT16_C(-13762), INT16_C(-31676)),
      simde_mm_set_epi16(INT16_C(-30768), INT16_C(  8012), INT16_C( 13061), INT16_C( 13020),
                         INT16_C( 11128), INT16_C(  2691), INT16_C( -2063), INT16_C(-31000)),
      simde_mm_set_epi16(INT16_C(  8798), INT16_C( 32066), INT16_C( 13061), INT16_C( 28187),
                         INT16_C( 23219), INT16_C(  2691), INT16_C( -2063), INT16_C(-31000)) },
    { simde_mm_set_epi16(INT16_C(  3184), INT16_C(  8972), INT16_C( 28417), INT16_C(  4325),
                         INT16_C( 30663), INT16_C( 17760), INT16_C( -9093), INT16_C(-26138)),
      simde_mm_set_epi16(INT16_C(-27749), INT16_C( 14472), INT16_C( -5104), INT16_C( 23824),
                         INT16_C( 11261), INT16_C(-30481), INT16_C(-27860), INT16_C(-28160)),
      simde_mm_set_epi16(INT16_C(  3184), INT16_C( 14472), INT16_C( 28417), INT16_C( 23824),
                         INT16_C( 30663), INT16_C( 17760), INT16_C( -9093), INT16_C(-26138)) },
    { simde_mm_set_epi16(INT16_C(-30031), INT16_C( 22199), INT16_C(-28560), INT16_C( 10819),
                         INT16_C( 25723), INT16_C(-10518), INT16_C(  8944), INT16_C(  4874)),
      simde_mm_set_epi16(INT16_C( 20789), INT16_C(   -61), INT16_C(-22145), INT16_C(-31891),
                         INT16_C(-19039), INT16_C( -2447), INT16_C( 22292), INT16_C(-25150)),
      simde_mm_set_epi16(INT16_C( 20789), INT16_C( 22199), INT16_C(-22145), INT16_C( 10819),
                         INT16_C( 25723), INT16_C( -2447), INT16_C( 22292), INT16_C(  4874)) },
    { simde_mm_set_epi16(INT16_C(  1306), INT16_C(-30964), INT16_C(-26654), INT16_C(-17652),
                         INT16_C(-10764), INT16_C(-11787), INT16_C(-30707), INT16_C(-23303)),
      simde_mm_set_epi16(INT16_C( 23609), INT16_C(-14128), INT16_C(-11050), INT16_C(-11303),
                         INT16_C( 16868), INT16_C(-19648), INT16_C(  8940), INT16_C( -9008)),
      simde_mm_set_epi16(INT16_C( 23609), INT16_C(-14128), INT16_C(-11050), INT16_C(-11303),
                         INT16_C( 16868), INT16_C(-11787), INT16_C(  8940), INT16_C( -9008)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_max_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -303.58), SIMDE_FLOAT64_C( -480.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  319.11), SIMDE_FLOAT64_C(  666.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  319.11), SIMDE_FLOAT64_C(  666.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -541.77), SIMDE_FLOAT64_C(  944.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.88), SIMDE_FLOAT64_C(  845.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.88), SIMDE_FLOAT64_C(  944.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -612.90), SIMDE_FLOAT64_C( -610.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  230.96), SIMDE_FLOAT64_C( -372.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  230.96), SIMDE_FLOAT64_C( -372.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -791.37), SIMDE_FLOAT64_C(  840.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.40), SIMDE_FLOAT64_C( -868.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.40), SIMDE_FLOAT64_C(  840.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  679.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.82), SIMDE_FLOAT64_C(  810.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  810.96)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  124.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -297.75), SIMDE_FLOAT64_C(  146.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  146.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.07), SIMDE_FLOAT64_C( -514.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  577.06), SIMDE_FLOAT64_C( -935.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  577.06), SIMDE_FLOAT64_C( -514.59)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -401.56), SIMDE_FLOAT64_C( -707.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_max_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_max_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -303.58), SIMDE_FLOAT64_C( -480.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  319.11), SIMDE_FLOAT64_C(  666.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -303.58), SIMDE_FLOAT64_C(  666.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -541.77), SIMDE_FLOAT64_C(  944.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.88), SIMDE_FLOAT64_C(  845.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -541.77), SIMDE_FLOAT64_C(  944.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -612.90), SIMDE_FLOAT64_C( -610.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  230.96), SIMDE_FLOAT64_C( -372.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -612.90), SIMDE_FLOAT64_C( -372.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -791.37), SIMDE_FLOAT64_C(  840.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.40), SIMDE_FLOAT64_C( -868.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -791.37), SIMDE_FLOAT64_C(  840.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  679.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.82), SIMDE_FLOAT64_C(  810.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  810.96)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  124.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -297.75), SIMDE_FLOAT64_C(  146.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  146.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.07), SIMDE_FLOAT64_C( -514.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  577.06), SIMDE_FLOAT64_C( -935.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.07), SIMDE_FLOAT64_C( -514.59)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -401.56), SIMDE_FLOAT64_C( -707.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_max_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_move_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2982745844705455901), INT64_C( 4775804171231816037)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 4775804171231816037)) },
    { simde_mm_set_epi64x(INT64_C( 5762346410957661033), INT64_C( 2977172799723381810)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 2977172799723381810)) },
    { simde_mm_set_epi64x(INT64_C( 1008079402021318109), INT64_C( 2502061726771043310)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 2502061726771043310)) },
    { simde_mm_set_epi64x(INT64_C( 5339677830223010942), INT64_C( 8124798084034539527)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 8124798084034539527)) },
    { simde_mm_set_epi64x(INT64_C(-4521066662096167363), INT64_C( -947809468227977762)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( -947809468227977762)) },
    { simde_mm_set_epi64x(INT64_C(-1218747510360922612), INT64_C( 3122441631876631480)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 3122441631876631480)) },
    { simde_mm_set_epi64x(INT64_C(-3523922424397514946), INT64_C( -108841976580709576)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( -108841976580709576)) },
    { simde_mm_set_epi64x(INT64_C(-3961221708434347271), INT64_C(-1875395594913971276)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-1875395594913971276)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_move_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_move_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  570.81), SIMDE_FLOAT64_C( -941.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -875.32), SIMDE_FLOAT64_C( -356.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  570.81), SIMDE_FLOAT64_C( -356.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -816.08), SIMDE_FLOAT64_C(  126.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.56), SIMDE_FLOAT64_C(  985.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -816.08), SIMDE_FLOAT64_C(  985.06)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  358.01), SIMDE_FLOAT64_C(   59.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -61.40), SIMDE_FLOAT64_C( -717.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  358.01), SIMDE_FLOAT64_C( -717.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  110.04), SIMDE_FLOAT64_C(  -44.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -614.96), SIMDE_FLOAT64_C( -267.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  110.04), SIMDE_FLOAT64_C( -267.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C( -816.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  917.45), SIMDE_FLOAT64_C(  287.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C(  287.41)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  827.50), SIMDE_FLOAT64_C(  261.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  478.77), SIMDE_FLOAT64_C(   33.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  827.50), SIMDE_FLOAT64_C(   33.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -335.82), SIMDE_FLOAT64_C(  465.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -993.24), SIMDE_FLOAT64_C(  100.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -335.82), SIMDE_FLOAT64_C(  100.89)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  415.58), SIMDE_FLOAT64_C( -984.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  764.57), SIMDE_FLOAT64_C(  672.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.58), SIMDE_FLOAT64_C(  672.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_move_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_movemask_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[] = {
    { simde_mm_set_epi8(INT8_C(-125), INT8_C( -40), INT8_C(  -7), INT8_C( -71),
                        INT8_C( -75), INT8_C(  99), INT8_C( 101), INT8_C(  -5),
                        INT8_C( -71), INT8_C( -91), INT8_C( -60), INT8_C(   9),
                        INT8_C( -27), INT8_C( -81), INT8_C(   5), INT8_C(  97)),
      INT32_C(63980) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -98), INT8_C(  82), INT8_C(-127),
                        INT8_C( -28), INT8_C( 122), INT8_C( -22), INT8_C(  46),
                        INT8_C( -41), INT8_C( -35), INT8_C(  15), INT8_C(  43),
                        INT8_C( -37), INT8_C( -12), INT8_C(  17), INT8_C( -17)),
      INT32_C(23245) },
    { simde_mm_set_epi8(INT8_C( -53), INT8_C( -99), INT8_C(  91), INT8_C( -56),
                        INT8_C(  10), INT8_C( 114), INT8_C(-120), INT8_C(  67),
                        INT8_C( -82), INT8_C(  13), INT8_C( 104), INT8_C(   1),
                        INT8_C(  15), INT8_C(-115), INT8_C(  16), INT8_C(  33)),
      INT32_C(53892) },
    { simde_mm_set_epi8(INT8_C( 109), INT8_C(  -5), INT8_C( -45), INT8_C(  60),
                        INT8_C( -20), INT8_C(  -7), INT8_C( -24), INT8_C(  63),
                        INT8_C(  61), INT8_C( -94), INT8_C(-110), INT8_C(  16),
                        INT8_C( 117), INT8_C( -23), INT8_C( -49), INT8_C( -74)),
      INT32_C(28263) },
    { simde_mm_set_epi8(INT8_C( -88), INT8_C( 110), INT8_C(-108), INT8_C( -88),
                        INT8_C(  28), INT8_C( 110), INT8_C(   0), INT8_C( -12),
                        INT8_C( -90), INT8_C(  44), INT8_C( -42), INT8_C( -87),
                        INT8_C( -48), INT8_C( -87), INT8_C( -21), INT8_C( -64)),
      INT32_C(45503) },
    { simde_mm_set_epi8(INT8_C( 121), INT8_C(-111), INT8_C(  -1), INT8_C( -61),
                        INT8_C(  67), INT8_C(  90), INT8_C(  10), INT8_C(  65),
                        INT8_C(  36), INT8_C( -60), INT8_C(  93), INT8_C(  -3),
                        INT8_C(-112), INT8_C(  -8), INT8_C(  55), INT8_C( -49)),
      INT32_C(28765) },
    { simde_mm_set_epi8(INT8_C(  92), INT8_C( -27), INT8_C(  37), INT8_C( -87),
                        INT8_C(  58), INT8_C( 108), INT8_C( -50), INT8_C( -10),
                        INT8_C(   5), INT8_C(  21), INT8_C(  14), INT8_C(  72),
                        INT8_C( -76), INT8_C(  21), INT8_C(-104), INT8_C( 110)),
      INT32_C(21258) },
    { simde_mm_set_epi8(INT8_C( -60), INT8_C(  23), INT8_C( -54), INT8_C(  54),
                        INT8_C(  31), INT8_C(  13), INT8_C( -93), INT8_C(  18),
                        INT8_C( -62), INT8_C(-128), INT8_C(  70), INT8_C(  59),
                        INT8_C(  17), INT8_C(  49), INT8_C(  95), INT8_C( -96)),
      INT32_C(41665) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_movemask_epi8(test_vec[i].a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_movemask_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -532.45), SIMDE_FLOAT64_C(  863.01)),
      INT32_C(2) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -749.24), SIMDE_FLOAT64_C( -869.97)),
      INT32_C(3) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  994.23), SIMDE_FLOAT64_C(  351.47)),
      INT32_C(0) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  413.53), SIMDE_FLOAT64_C( -655.32)),
      INT32_C(1) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -253.74), SIMDE_FLOAT64_C(   -2.37)),
      INT32_C(3) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  696.22), SIMDE_FLOAT64_C( -699.75)),
      INT32_C(1) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   55.24), SIMDE_FLOAT64_C( -722.45)),
      INT32_C(1) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -592.60), SIMDE_FLOAT64_C(  141.10)),
      INT32_C(2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_movemask_pd(test_vec[i].a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_movepi64_pi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-3369091548753669372), INT64_C(-3862634862308997761)),
      simde_x_mm_set_pi64(INT64_C(-3862634862308997761)) },
    { simde_mm_set_epi64x(INT64_C( 1195923961730132400), INT64_C(-4203048506958717476)),
      simde_x_mm_set_pi64(INT64_C(-4203048506958717476)) },
    { simde_mm_set_epi64x(INT64_C( 4316262850566382732), INT64_C(  743544812785944809)),
      simde_x_mm_set_pi64(INT64_C(743544812785944809)) },
    { simde_mm_set_epi64x(INT64_C( 9153964415619232912), INT64_C( 7102186508934354546)),
      simde_x_mm_set_pi64(INT64_C(7102186508934354546)) },
    { simde_mm_set_epi64x(INT64_C( -149536427124813706), INT64_C(-2645616526676309339)),
      simde_x_mm_set_pi64(INT64_C(-2645616526676309339)) },
    { simde_mm_set_epi64x(INT64_C( 7660292028637459230), INT64_C(-4472173852492382560)),
      simde_x_mm_set_pi64(INT64_C(-4472173852492382560)) },
    { simde_mm_set_epi64x(INT64_C( 2373412759770157312), INT64_C( -249935199655019513)),
      simde_x_mm_set_pi64(INT64_C(-249935199655019513)) },
    { simde_mm_set_epi64x(INT64_C(-2495482311671930573), INT64_C( 7782795372632782061)),
      simde_x_mm_set_pi64(INT64_C(7782795372632782061)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_movepi64_pi64(test_vec[i].a);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_movpi64_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m128i r;
  } test_vec[8] = {
   { simde_x_mm_set_pi64(INT64_C(8307669974137432024)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 8307669974137432024)) },
    { simde_x_mm_set_pi64(INT64_C(-6174863101947913477)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-6174863101947913477)) },
    { simde_x_mm_set_pi64(INT64_C(-3709498539865079997)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-3709498539865079997)) },
    { simde_x_mm_set_pi64(INT64_C(-5655514474221449119)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-5655514474221449119)) },
    { simde_x_mm_set_pi64(INT64_C(-4407711847161442183)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-4407711847161442183)) },
    { simde_x_mm_set_pi64(INT64_C(-7730135383563833284)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-7730135383563833284)) },
    { simde_x_mm_set_pi64(INT64_C(1417829150564629578)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 1417829150564629578)) },
    { simde_x_mm_set_pi64(INT64_C(5667864625160412978)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 5667864625160412978)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movpi64_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mul_epu32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32 (UINT32_C(1251634950), UINT32_C( 3010014325), UINT32_C( 3844926313), UINT32_C(  887004237)),
      simde_x_mm_set_epu32 (UINT32_C( 771412494), UINT32_C(  328239887), UINT32_C( 3360452571), UINT32_C(  298292680)),
      simde_x_mm_set_epu64x(UINT64_C(  988006761906381275), UINT64_C(  264586871026085160)) },
    { simde_x_mm_set_epu32 (UINT32_C(4076207020), UINT32_C(  368393187), UINT32_C( 3498508084), UINT32_C(  981141316)),
      simde_x_mm_set_epu32 (UINT32_C(  81654802), UINT32_C(  140153335), UINT32_C( 2110173535), UINT32_C( 3134478151)),
      simde_x_mm_set_epu64x(UINT64_C(   51631533749328645), UINT64_C( 3075366018045386716)) },
    { simde_x_mm_set_epu32 (UINT32_C(4261415154), UINT32_C(  846454649), UINT32_C(  108194122), UINT32_C( 4167432393)),
      simde_x_mm_set_epu32 (UINT32_C(2698880481), UINT32_C( 1287129030), UINT32_C( 2616406220), UINT32_C( 1248265871)),
      simde_x_mm_set_epu64x(UINT64_C( 1089496351306360470), UINT64_C( 5202063625881759303)) },
    { simde_x_mm_set_epu32 (UINT32_C( 911193301), UINT32_C( 1110766386), UINT32_C( 3009613617), UINT32_C( 1645784878)),
      simde_x_mm_set_epu32 (UINT32_C(3094480659), UINT32_C( 3697181600), UINT32_C( 4236850839), UINT32_C( 2133678416)),
      simde_x_mm_set_epu64x(UINT64_C( 4106705044217697600), UINT64_C( 3511575671567793248)) },
    { simde_x_mm_set_epu32 (UINT32_C(2154112155), UINT32_C( 2960710803), UINT32_C( 2851801912), UINT32_C(  678710951)),
      simde_x_mm_set_epu32 (UINT32_C(4001207654), UINT32_C( 4056994829), UINT32_C( 1341523746), UINT32_C(  568161818)),
      simde_x_mm_set_epu64x(UINT64_C(12011588417935437687), UINT64_C(  385617647816668918)) },
    { simde_x_mm_set_epu32 (UINT32_C(3273494172), UINT32_C( 3612698350), UINT32_C( 4103906203), UINT32_C( 1678207566)),
      simde_x_mm_set_epu32 (UINT32_C(  48120942), UINT32_C(  160747207), UINT32_C( 2820564214), UINT32_C( 1404181744)),
      simde_x_mm_set_epu64x(UINT64_C(  580731169496008450), UINT64_C( 2356508426819875104)) },
    { simde_x_mm_set_epu32 (UINT32_C( 396392525), UINT32_C( 2486526122), UINT32_C( 1177281917), UINT32_C( 3038155803)),
      simde_x_mm_set_epu32 (UINT32_C( 760783698), UINT32_C( 1253190575), UINT32_C( 4064848310), UINT32_C( 1630883223)),
      simde_x_mm_set_epu64x(UINT64_C( 3116091100581700150), UINT64_C( 4954877327972793069)) },
    { simde_x_mm_set_epu32 (UINT32_C(1438827395), UINT32_C( 1294325524), UINT32_C( 3245229436), UINT32_C(  122146781)),
      simde_x_mm_set_epu32 (UINT32_C(1030238038), UINT32_C( 4273209339), UINT32_C(  197838277), UINT32_C( 1151380764)),
      simde_x_mm_set_epu64x(UINT64_C( 5530923916862868636), UINT64_C(  140637454027920684)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mul_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mul_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    602.19), SIMDE_FLOAT64_C(   -103.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -952.79), SIMDE_FLOAT64_C(   -150.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-573760.61), SIMDE_FLOAT64_C(  15616.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -140.84), SIMDE_FLOAT64_C(   -241.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    540.86), SIMDE_FLOAT64_C(   -754.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -76174.72), SIMDE_FLOAT64_C( 182524.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -648.21), SIMDE_FLOAT64_C(   -612.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -327.08), SIMDE_FLOAT64_C(   -865.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 212016.53), SIMDE_FLOAT64_C( 529683.27)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    518.61), SIMDE_FLOAT64_C(   -573.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -650.79), SIMDE_FLOAT64_C(    196.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-337506.20), SIMDE_FLOAT64_C(-112409.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -750.40), SIMDE_FLOAT64_C(    324.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    343.74), SIMDE_FLOAT64_C(     -4.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-257942.50), SIMDE_FLOAT64_C(  -1343.97)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    -48.73), SIMDE_FLOAT64_C(    769.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    268.16), SIMDE_FLOAT64_C(   -953.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -13067.44), SIMDE_FLOAT64_C(-733391.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    188.02), SIMDE_FLOAT64_C(    614.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    396.91), SIMDE_FLOAT64_C(   -399.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  74627.02), SIMDE_FLOAT64_C(-245751.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    813.52), SIMDE_FLOAT64_C(    480.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    664.31), SIMDE_FLOAT64_C(    447.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 540429.47), SIMDE_FLOAT64_C( 215022.79)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_mul_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_mul_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    815.66), SIMDE_FLOAT64_C(    839.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    748.66), SIMDE_FLOAT64_C(    -52.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    815.66), SIMDE_FLOAT64_C( -43740.67)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -714.36), SIMDE_FLOAT64_C(   -808.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    401.75), SIMDE_FLOAT64_C(    319.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -714.36), SIMDE_FLOAT64_C(-257857.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    453.36), SIMDE_FLOAT64_C(   -764.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -934.41), SIMDE_FLOAT64_C(   -454.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    453.36), SIMDE_FLOAT64_C( 347728.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    489.60), SIMDE_FLOAT64_C(    724.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -101.25), SIMDE_FLOAT64_C(    196.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    489.60), SIMDE_FLOAT64_C( 142638.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    187.03), SIMDE_FLOAT64_C(    665.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    487.15), SIMDE_FLOAT64_C(    851.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    187.03), SIMDE_FLOAT64_C( 566080.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    589.48), SIMDE_FLOAT64_C(    648.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -683.48), SIMDE_FLOAT64_C(    -59.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    589.48), SIMDE_FLOAT64_C( -38682.27)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    838.61), SIMDE_FLOAT64_C(    822.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -364.43), SIMDE_FLOAT64_C(    962.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    838.61), SIMDE_FLOAT64_C( 791150.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    530.83), SIMDE_FLOAT64_C(    379.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(     27.92), SIMDE_FLOAT64_C(    -56.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    530.83), SIMDE_FLOAT64_C( -21300.74)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_mul_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_mul_su32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu32(UINT32_C(3055040779), UINT32_C( 899100968)),
      simde_x_mm_set_pu32(UINT32_C(1940650668), UINT32_C(3777451497)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 3396310297525749096))) },
    { simde_x_mm_set_pu32(UINT32_C(2705843438), UINT32_C(2434885276)),
      simde_x_mm_set_pu32(UINT32_C(3024316392), UINT32_C(3861898348)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 9403279424953924048))) },
    { simde_x_mm_set_pu32(UINT32_C(3766308026), UINT32_C(1712773120)),
      simde_x_mm_set_pu32(UINT32_C( 817218479), UINT32_C(3651399110)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 6254018245999923200))) },
    { simde_x_mm_set_pu32(UINT32_C( 434012470), UINT32_C(1054365092)),
      simde_x_mm_set_pu32(UINT32_C(2682784668), UINT32_C(2536059630)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 2673932745102435960))) },
    { simde_x_mm_set_pu32(UINT32_C(3086788421), UINT32_C( 996821946)),
      simde_x_mm_set_pu32(UINT32_C(3201780597), UINT32_C(3958985305)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 3946403435915503530))) },
    { simde_x_mm_set_pu32(UINT32_C(3277786031), UINT32_C(4257890741)),
      simde_x_mm_set_pu32(UINT32_C(1195509971), UINT32_C(2579552899)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C(10983454404571808159))) },
    { simde_x_mm_set_pu32(UINT32_C(3106450314), UINT32_C(1125697671)),
      simde_x_mm_set_pu32(UINT32_C(2878635182), UINT32_C(3892244414)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 4381490471802559794))) },
    { simde_x_mm_set_pu32(UINT32_C(2670515723), UINT32_C(3917703761)),
      simde_x_mm_set_pu32(UINT32_C(3656211314), UINT32_C(2327792170)),
      simde_mm_cvtsi64_m64(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 9119600139235351370))) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_mul_su32(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mulhi_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-28198), INT16_C(-30713), INT16_C( 20992), INT16_C(-15285),
                         INT16_C( 16558), INT16_C(-12771), INT16_C(-10872), INT16_C(-32584)),
      simde_mm_set_epi16(INT16_C( -2396), INT16_C(-16729), INT16_C( 31162), INT16_C(-10205),
                         INT16_C( 24928), INT16_C(  5223), INT16_C(  7262), INT16_C( 25352)),
      simde_mm_set_epi16(INT16_C(  1030), INT16_C(  7839), INT16_C(  9981), INT16_C(  2380),
                         INT16_C(  6298), INT16_C( -1018), INT16_C( -1205), INT16_C(-12605)) },
    { simde_mm_set_epi16(INT16_C(-29475), INT16_C( -4667), INT16_C( 18782), INT16_C(-15431),
                         INT16_C(-27740), INT16_C( 28051), INT16_C(  4978), INT16_C(  1222)),
      simde_mm_set_epi16(INT16_C(-10541), INT16_C(-14468), INT16_C( 18685), INT16_C( 12375),
                         INT16_C( -5884), INT16_C(-11112), INT16_C( 23337), INT16_C( 12576)),
      simde_mm_set_epi16(INT16_C(  4740), INT16_C(  1030), INT16_C(  5354), INT16_C( -2914),
                         INT16_C(  2490), INT16_C( -4757), INT16_C(  1772), INT16_C(   234)) },
    { simde_mm_set_epi16(INT16_C( 27783), INT16_C(  6960), INT16_C( 17513), INT16_C( -7755),
                         INT16_C( 14695), INT16_C( 12404), INT16_C( -4129), INT16_C(-25366)),
      simde_mm_set_epi16(INT16_C( 29475), INT16_C( 25763), INT16_C( 29366), INT16_C( 12820),
                         INT16_C( -5355), INT16_C(  7751), INT16_C(-24426), INT16_C( -6617)),
      simde_mm_set_epi16(INT16_C( 12495), INT16_C(  2736), INT16_C(  7847), INT16_C( -1518),
                         INT16_C( -1201), INT16_C(  1467), INT16_C(  1538), INT16_C(  2561)) },
    { simde_mm_set_epi16(INT16_C(  8852), INT16_C( 11654), INT16_C( 12030), INT16_C( 21843),
                         INT16_C( 27012), INT16_C( 24122), INT16_C( -4121), INT16_C( 19864)),
      simde_mm_set_epi16(INT16_C(-24799), INT16_C(-30738), INT16_C( 19688), INT16_C(-21919),
                         INT16_C( 23874), INT16_C( -4632), INT16_C(-21648), INT16_C(-28317)),
      simde_mm_set_epi16(INT16_C( -3350), INT16_C( -5467), INT16_C(  3613), INT16_C( -7306),
                         INT16_C(  9840), INT16_C( -1705), INT16_C(  1361), INT16_C( -8583)) },
    { simde_mm_set_epi16(INT16_C(  2959), INT16_C(-18532), INT16_C(  4909), INT16_C( 17932),
                         INT16_C(  9150), INT16_C( 13660), INT16_C(-28547), INT16_C(  5006)),
      simde_mm_set_epi16(INT16_C( 16706), INT16_C(-30015), INT16_C(-32638), INT16_C( 13608),
                         INT16_C( -7846), INT16_C( 14914), INT16_C(-15409), INT16_C(-27711)),
      simde_mm_set_epi16(INT16_C(   754), INT16_C(  8487), INT16_C( -2445), INT16_C(  3723),
                         INT16_C( -1096), INT16_C(  3108), INT16_C(  6712), INT16_C( -2117)) },
    { simde_mm_set_epi16(INT16_C( 23854), INT16_C(-13644), INT16_C(-14015), INT16_C(-13375),
                         INT16_C(-26086), INT16_C( -6430), INT16_C( -5411), INT16_C(  7716)),
      simde_mm_set_epi16(INT16_C( -3281), INT16_C(-16733), INT16_C(-20310), INT16_C(   760),
                         INT16_C(-18586), INT16_C(  1673), INT16_C(-25298), INT16_C(-31758)),
      simde_mm_set_epi16(INT16_C( -1195), INT16_C(  3483), INT16_C(  4343), INT16_C(  -156),
                         INT16_C(  7397), INT16_C(  -165), INT16_C(  2088), INT16_C( -3740)) },
    { simde_mm_set_epi16(INT16_C(  5449), INT16_C(    38), INT16_C(  6018), INT16_C( 10627),
                         INT16_C( 20505), INT16_C( 28284), INT16_C(  4633), INT16_C(-26325)),
      simde_mm_set_epi16(INT16_C( 24784), INT16_C( 11314), INT16_C(  7455), INT16_C( 17813),
                         INT16_C( -6570), INT16_C(-17283), INT16_C( 30512), INT16_C(  2646)),
      simde_mm_set_epi16(INT16_C(  2060), INT16_C(     6), INT16_C(   684), INT16_C(  2888),
                         INT16_C( -2056), INT16_C( -7459), INT16_C(  2157), INT16_C( -1063)) },
    { simde_mm_set_epi16(INT16_C(-21624), INT16_C(  5121), INT16_C( 20041), INT16_C( 13722),
                         INT16_C(-24360), INT16_C(-19124), INT16_C(-16069), INT16_C( 19357)),
      simde_mm_set_epi16(INT16_C( -7842), INT16_C( 31372), INT16_C(-32681), INT16_C( 23520),
                         INT16_C( -3879), INT16_C( -7485), INT16_C( 22256), INT16_C( 12396)),
      simde_mm_set_epi16(INT16_C(  2587), INT16_C(  2451), INT16_C( -9994), INT16_C(  4924),
                         INT16_C(  1441), INT16_C(  2184), INT16_C( -5458), INT16_C(  3661)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mulhi_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mulhi_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(35566, 15689, 63042, 57362, 59041, 31224, 19546, 12829),
      simde_x_mm_set_epu16(51447, 14621, 39095, 25022,  7138, 40387, 23161, 61024),
      simde_x_mm_set_epu16(27919,  3500, 37607, 21901,  6430, 19241,  6907, 11945) },
    { simde_x_mm_set_epu16(38922,  8893,  7997, 20067, 60307, 12929, 44791, 36818),
      simde_x_mm_set_epu16(56115, 46352, 39645, 27986, 64864, 64084,  5079, 17389),
      simde_x_mm_set_epu16(33326,  6289,  4837,  8569, 59688, 12642,  3471,  9769) },
    { simde_x_mm_set_epu16(15336, 63669, 63771, 21657, 12681, 61746,  3959, 20213),
      simde_x_mm_set_epu16(61649,  7462, 20857, 18418, 43120, 17135, 41045, 26167),
      simde_x_mm_set_epu16(14426,  7249, 20295,  6086,  8343, 16144,  2479,  8070) },
    { simde_x_mm_set_epu16(18737, 50787, 58977, 18610,  8077,  2942, 26014, 51355),
      simde_x_mm_set_epu16( 1776,  1953, 55756, 22299, 19400, 25284, 34496, 57058),
      simde_x_mm_set_epu16(  507,  1513, 50175,  6332,  2390,  1135, 13692, 44711) },
    { simde_x_mm_set_epu16(10154, 39850, 18306, 55081, 15606, 51707, 30878, 20967),
      simde_x_mm_set_epu16(43083, 50945, 49120, 63736, 15921, 64165, 33035, 50764),
      simde_x_mm_set_epu16( 6675, 30977, 13720, 53568,  3791, 50625, 15564, 16240) },
    { simde_x_mm_set_epu16(12757,  5042, 57712, 50374, 33497, 44643,  9249, 27444),
      simde_x_mm_set_epu16( 5516, 28001, 37996, 50447,  2209, 25118, 63921,  7578),
      simde_x_mm_set_epu16( 1073,  2154, 33459, 38775,  1129, 17110,  9021,  3173) },
    { simde_x_mm_set_epu16( 6520, 35794, 15094, 63136, 22779, 57672,  2423,  7676),
      simde_x_mm_set_epu16(20640, 11808, 58236, 53501, 38005, 59820,  7041, 59845),
      simde_x_mm_set_epu16( 2053,  6449, 13412, 51541, 13209, 52641,   260,  7009) },
    { simde_x_mm_set_epu16(60138,  6017, 21659, 30716, 29807, 17606, 41408, 64807),
      simde_x_mm_set_epu16(25712,  8473, 49119, 61515, 61789, 54600, 37356, 34280),
      simde_x_mm_set_epu16(23594,   777, 16233, 28831, 28102, 14668, 23602, 33898) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mulhi_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mullo_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( -7862), INT16_C( 26852), INT16_C( 10752), INT16_C( -9273),
                         INT16_C( -9160), INT16_C( -7080), INT16_C(-16165), INT16_C( -8327)),
      simde_mm_set_epi16(INT16_C(-20410), INT16_C( 24193), INT16_C(-22278), INT16_C(  -948),
                         INT16_C(-31925), INT16_C( -8469), INT16_C(  5801), INT16_C( 10383)),
      simde_mm_set_epi16(INT16_C( 31292), INT16_C(-27932), INT16_C(  1024), INT16_C(  8980),
                         INT16_C( 11368), INT16_C( -4920), INT16_C(  8851), INT16_C(-17257)) },
    { simde_mm_set_epi16(INT16_C( 10435), INT16_C( 19268), INT16_C( 27420), INT16_C(  9542),
                         INT16_C(-22355), INT16_C( 22255), INT16_C(-32016), INT16_C( 23304)),
      simde_mm_set_epi16(INT16_C( -3883), INT16_C( 14714), INT16_C(-16367), INT16_C(  4175),
                         INT16_C( 13386), INT16_C( 20048), INT16_C(-30329), INT16_C(-26826)),
      simde_mm_set_epi16(INT16_C(-17857), INT16_C(   616), INT16_C(  7388), INT16_C( -8038),
                         INT16_C( -6654), INT16_C(  -848), INT16_C( 31888), INT16_C( -5200)) },
    { simde_mm_set_epi16(INT16_C( 16747), INT16_C(-31494), INT16_C( -6008), INT16_C(   256),
                         INT16_C( 13584), INT16_C( -2628), INT16_C( 32210), INT16_C(-21204)),
      simde_mm_set_epi16(INT16_C(  5844), INT16_C(-28058), INT16_C( -1961), INT16_C( -4057),
                         INT16_C(-28767), INT16_C(-15421), INT16_C(-28399), INT16_C(  6019)),
      simde_mm_set_epi16(INT16_C( 24220), INT16_C(-28772), INT16_C(-14792), INT16_C(  9984),
                         INT16_C( 20240), INT16_C( 25140), INT16_C( 19698), INT16_C(-28284)) },
    { simde_mm_set_epi16(INT16_C( -6420), INT16_C( -8597), INT16_C( -3796), INT16_C( 23244),
                         INT16_C(-31410), INT16_C(  -804), INT16_C( 31623), INT16_C(  -736)),
      simde_mm_set_epi16(INT16_C( -5973), INT16_C( -2870), INT16_C( -5873), INT16_C( -1641),
                         INT16_C( -1760), INT16_C( 10653), INT16_C(-28567), INT16_C( 14335)),
      simde_mm_set_epi16(INT16_C(  8100), INT16_C( 31854), INT16_C( 11668), INT16_C( -1452),
                         INT16_C(-30784), INT16_C( 20204), INT16_C(-26017), INT16_C(   736)) },
    { simde_mm_set_epi16(INT16_C(-30942), INT16_C( 23208), INT16_C(  -332), INT16_C(-26357),
                         INT16_C( -4575), INT16_C( 25713), INT16_C(-11436), INT16_C(-20469)),
      simde_mm_set_epi16(INT16_C( 10752), INT16_C( -6855), INT16_C(-32031), INT16_C( 11523),
                         INT16_C(   341), INT16_C( 13013), INT16_C( 12462), INT16_C(-19043)),
      simde_mm_set_epi16(INT16_C(-27648), INT16_C( 30568), INT16_C( 17460), INT16_C(-17887),
                         INT16_C( 12789), INT16_C(-23547), INT16_C( 25368), INT16_C(-16961)) },
    { simde_mm_set_epi16(INT16_C( -9419), INT16_C(-28719), INT16_C( 16604), INT16_C( 20761),
                         INT16_C(  7656), INT16_C( 31821), INT16_C( 14202), INT16_C(-12774)),
      simde_mm_set_epi16(INT16_C(-24440), INT16_C( -4751), INT16_C(-13213), INT16_C( 10351),
                         INT16_C( 25105), INT16_C( -3784), INT16_C(  2889), INT16_C( 15532)),
      simde_mm_set_epi16(INT16_C(-27608), INT16_C( -1983), INT16_C( 25876), INT16_C(  4567),
                         INT16_C(-13208), INT16_C(-21032), INT16_C(  4042), INT16_C(-28296)) },
    { simde_mm_set_epi16(INT16_C( 24274), INT16_C( 31467), INT16_C( 17654), INT16_C(-30184),
                         INT16_C( -7163), INT16_C( 32482), INT16_C( 19535), INT16_C(-21227)),
      simde_mm_set_epi16(INT16_C( 18405), INT16_C(-30234), INT16_C(  7564), INT16_C(-18060),
                         INT16_C( 16638), INT16_C(-17950), INT16_C(  -411), INT16_C(-23904)),
      simde_mm_set_epi16(INT16_C(  4058), INT16_C( 12834), INT16_C(-27512), INT16_C( -5408),
                         INT16_C( 31990), INT16_C( 21892), INT16_C( 32043), INT16_C( 30496)) },
    { simde_mm_set_epi16(INT16_C(-10768), INT16_C(-21062), INT16_C( 22181), INT16_C( 31606),
                         INT16_C( 16135), INT16_C(-14823), INT16_C(-19116), INT16_C(-13035)),
      simde_mm_set_epi16(INT16_C( 25288), INT16_C(-13107), INT16_C(-24173), INT16_C(-10010),
                         INT16_C(-10251), INT16_C(  9523), INT16_C( 29977), INT16_C(-13646)),
      simde_mm_set_epi16(INT16_C(   896), INT16_C( 22002), INT16_C(-31297), INT16_C( 31748),
                         INT16_C( 12979), INT16_C(  5115), INT16_C(  6452), INT16_C( 10906)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mullo_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_or_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    724.92), SIMDE_FLOAT64_C(    616.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    797.85), SIMDE_FLOAT64_C(    484.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    989.98), SIMDE_FLOAT64_C( 128062.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    482.51), SIMDE_FLOAT64_C(    841.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -558.83), SIMDE_FLOAT64_C(    997.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-129002.75), SIMDE_FLOAT64_C(   1005.87)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    741.60), SIMDE_FLOAT64_C(   -412.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -337.67), SIMDE_FLOAT64_C(   -516.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -95215.80), SIMDE_FLOAT64_C(-106109.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    724.85), SIMDE_FLOAT64_C(   -403.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -503.03), SIMDE_FLOAT64_C(   -699.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-130927.93), SIMDE_FLOAT64_C(-122827.50)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    231.42), SIMDE_FLOAT64_C(    688.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -373.50), SIMDE_FLOAT64_C(    983.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -511.84), SIMDE_FLOAT64_C(   1015.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    625.94), SIMDE_FLOAT64_C(   -703.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -942.06), SIMDE_FLOAT64_C(    249.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -1024.00), SIMDE_FLOAT64_C( -65535.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    -97.92), SIMDE_FLOAT64_C(    -70.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -510.77), SIMDE_FLOAT64_C(   -381.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -511.93), SIMDE_FLOAT64_C(   -383.36)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -350.87), SIMDE_FLOAT64_C(   -439.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(     66.40), SIMDE_FLOAT64_C(    195.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -351.87), SIMDE_FLOAT64_C(   -439.86)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_or_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_or_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(   3806780817851842454), INT64_C(   3002076500639794819)),
      simde_mm_set_epi64x(INT64_C(  -1576369425501019200), INT64_C(   5863973371898850910)),
      simde_mm_set_epi64x(INT64_C(    -81065909581643818), INT64_C(   8784698508288454367)) },
    { simde_mm_set_epi64x(INT64_C(   4358272343769327172), INT64_C(  -4254544166297055533)),
      simde_mm_set_epi64x(INT64_C(  -3870591542062132163), INT64_C(   8365983368440196218)),
      simde_mm_set_epi64x(INT64_C(   -109223286268234115), INT64_C(   -793210092996038917)) },
    { simde_mm_set_epi64x(INT64_C(  -8935978336450140157), INT64_C(  -4292132981830530492)),
      simde_mm_set_epi64x(INT64_C(  -5275996428160709349), INT64_C(   1809702168782653061)),
      simde_mm_set_epi64x(INT64_C(  -5188173984729010917), INT64_C(  -2486163139644895547)) },
    { simde_mm_set_epi64x(INT64_C(  -3617483608260678394), INT64_C(  -7299761588855953181)),
      simde_mm_set_epi64x(INT64_C(  -3679366837934484296), INT64_C(   5342128716508209170)),
      simde_mm_set_epi64x(INT64_C(  -3603900203459740226), INT64_C(  -2687789418219853581)) },
    { simde_mm_set_epi64x(INT64_C(   8613776548693408177), INT64_C(  -1221094295236221778)),
      simde_mm_set_epi64x(INT64_C(   8491744443283364215), INT64_C(   4783609441494973751)),
      simde_mm_set_epi64x(INT64_C(   8636493096189557239), INT64_C(  -1193507273608823361)) },
    { simde_mm_set_epi64x(INT64_C(   2256952633337952767), INT64_C(  -5574602856706714295)),
      simde_mm_set_epi64x(INT64_C(  -7711313128986328449), INT64_C(  -5631421726257218112)),
      simde_mm_set_epi64x(INT64_C(  -6918672559143650305), INT64_C(  -5477736148453327415)) },
    { simde_mm_set_epi64x(INT64_C(   6915809581026069253), INT64_C(  -4447049561909832301)),
      simde_mm_set_epi64x(INT64_C(   7606865206928880870), INT64_C(    526097040835303983)),
      simde_mm_set_epi64x(INT64_C(   9221656517182193639), INT64_C(  -4085336622434885697)) },
    { simde_mm_set_epi64x(INT64_C(   6255716227368614659), INT64_C(   3842255123517004943)),
      simde_mm_set_epi64x(INT64_C(  -2544504471973996098), INT64_C(   7324902981920444710)),
      simde_mm_set_epi64x(INT64_C(  -2382159098826458177), INT64_C(   8500384867471056303)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_or_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_packs_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-22268), INT16_C(   -16), INT16_C(   -49), INT16_C(     8),
                         INT16_C( 20029), INT16_C(-30901), INT16_C(-17364), INT16_C(   -65)),
      simde_mm_set_epi16(INT16_C(-20429), INT16_C(  4131), INT16_C(-19140), INT16_C( 23907),
                         INT16_C(   -87), INT16_C(-15818), INT16_C(   -93), INT16_C(   -34)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( -87), INT8_C(-128), INT8_C( -93), INT8_C( -34),
                        INT8_C(-128), INT8_C( -16), INT8_C( -49), INT8_C(   8), INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( -65)) },
    { simde_mm_set_epi16(INT16_C( -1320), INT16_C(    64), INT16_C(  7903), INT16_C(   -86),
                         INT16_C( 17775), INT16_C(   -29), INT16_C(-24347), INT16_C( 20534)),
      simde_mm_set_epi16(INT16_C(   -26), INT16_C( 32460), INT16_C(   -35), INT16_C(     9),
                         INT16_C(    97), INT16_C(-16116), INT16_C( 21908), INT16_C( 31051)),
      simde_mm_set_epi8(INT8_C( -26), INT8_C( 127), INT8_C( -35), INT8_C(   9), INT8_C(  97), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C(  64), INT8_C( 127), INT8_C( -86), INT8_C( 127), INT8_C( -29), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi16(INT16_C(    16), INT16_C(-23521), INT16_C(   107), INT16_C( 10693),
                         INT16_C(    37), INT16_C( 32277), INT16_C(  -120), INT16_C(   -13)),
      simde_mm_set_epi16(INT16_C(  7912), INT16_C(   127), INT16_C(-27046), INT16_C(  -104),
                         INT16_C(   114), INT16_C(   -54), INT16_C(   -26), INT16_C( 29057)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-104), INT8_C( 114), INT8_C( -54), INT8_C( -26), INT8_C( 127),
                        INT8_C(  16), INT8_C(-128), INT8_C( 107), INT8_C( 127), INT8_C(  37), INT8_C( 127), INT8_C(-120), INT8_C( -13)) },
    { simde_mm_set_epi16(INT16_C(     8), INT16_C(   -84), INT16_C(    26), INT16_C( -1727),
                         INT16_C(    53), INT16_C( 29056), INT16_C( -7932), INT16_C(    40)),
      simde_mm_set_epi16(INT16_C(-25560), INT16_C(    94), INT16_C( 19164), INT16_C(  -119),
                         INT16_C(-25450), INT16_C( 26043), INT16_C( -9549), INT16_C(   110)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C(  94), INT8_C( 127), INT8_C(-119), INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 110),
                        INT8_C(   8), INT8_C( -84), INT8_C(  26), INT8_C(-128), INT8_C(  53), INT8_C( 127), INT8_C(-128), INT8_C(  40)) },
    { simde_mm_set_epi16(INT16_C( 17087), INT16_C(     3), INT16_C( 26871), INT16_C(   126),
                         INT16_C(-10072), INT16_C(    95), INT16_C(   117), INT16_C(   110)),
      simde_mm_set_epi16(INT16_C(  7667), INT16_C( -3918), INT16_C(   -98), INT16_C(   -77),
                         INT16_C( 29383), INT16_C(-21060), INT16_C(-18775), INT16_C( 21121)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C( -98), INT8_C( -77), INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C(   3), INT8_C( 127), INT8_C( 126), INT8_C(-128), INT8_C(  95), INT8_C( 117), INT8_C( 110)) },
    { simde_mm_set_epi16(INT16_C(  -120), INT16_C(-29564), INT16_C(  -120), INT16_C(   -79),
                         INT16_C(   -93), INT16_C(-23649), INT16_C( 25423), INT16_C(-23661)),
      simde_mm_set_epi16(INT16_C(   109), INT16_C(-30808), INT16_C(    45), INT16_C(   -18),
                         INT16_C( -4268), INT16_C( 30580), INT16_C(    77), INT16_C( -1896)),
      simde_mm_set_epi8(INT8_C( 109), INT8_C(-128), INT8_C(  45), INT8_C( -18), INT8_C(-128), INT8_C( 127), INT8_C(  77), INT8_C(-128),
                        INT8_C(-120), INT8_C(-128), INT8_C(-120), INT8_C( -79), INT8_C( -93), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi16(INT16_C(    75), INT16_C(   -80), INT16_C(    -5), INT16_C(   -23),
                         INT16_C( -9879), INT16_C(   116), INT16_C(-20199), INT16_C(  5095)),
      simde_mm_set_epi16(INT16_C( -3339), INT16_C(   -48), INT16_C(  -117), INT16_C( -2107),
                         INT16_C( 11715), INT16_C(-13793), INT16_C(-31434), INT16_C( 25021)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( -48), INT8_C(-117), INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C(  75), INT8_C( -80), INT8_C(  -5), INT8_C( -23), INT8_C(-128), INT8_C( 116), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi16(INT16_C(   -15), INT16_C(   110), INT16_C(  -521), INT16_C(    75),
                         INT16_C( 12019), INT16_C(-30116), INT16_C( 17702), INT16_C( 14401)),
      simde_mm_set_epi16(INT16_C(-15008), INT16_C(   -80), INT16_C(  -127), INT16_C(-29333),
                         INT16_C(    -7), INT16_C(-17846), INT16_C(    83), INT16_C( 25637)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( -80), INT8_C(-127), INT8_C(-128), INT8_C(  -7), INT8_C(-128), INT8_C(  83), INT8_C( 127),
                        INT8_C( -15), INT8_C( 110), INT8_C(-128), INT8_C(  75), INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_packs_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1221393622), INT32_C(    1245122), INT32_C( -546439182), INT32_C( 1653967185)),
      simde_mm_set_epi32(INT32_C(   -5570627), INT32_C( 1604714526), INT32_C(    3276815), INT32_C( -865960168)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C(-1556742099), INT32_C(    3735602), INT32_C( -795913538), INT32_C(    5177351)),
      simde_mm_set_epi32(INT32_C(  230555532), INT32_C( -681902099), INT32_C(-1460947394), INT32_C( 1435959285)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                         INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( 1058013130), INT32_C( 1801350196), INT32_C(    3735625), INT32_C(     393200)),
      simde_mm_set_epi32(INT32_C(   -5046245), INT32_C( 1947557327), INT32_C( -390520293), INT32_C(-1060577736)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( 1625994666), INT32_C(  151157112), INT32_C(   -6356918), INT32_C(  574958135)),
      simde_mm_set_epi32(INT32_C( -878149423), INT32_C(   -1310820), INT32_C(    7694016), INT32_C(    1656093)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C(  906756004), INT32_C(  589883340), INT32_C(-1375993871), INT32_C(   -5221415)),
      simde_mm_set_epi32(INT32_C(-1492628097), INT32_C(   -7536518), INT32_C(    1834989), INT32_C(-2090880115)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi32(INT32_C( 1759910713), INT32_C( 2028743221), INT32_C( 1203039561), INT32_C(    3735524)),
      simde_mm_set_epi32(INT32_C(    5505016), INT32_C(   68681650), INT32_C(    3895727), INT32_C(-1084227687)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( 1249181759), INT32_C(  850460644), INT32_C(  643956807), INT32_C( 1402185830)),
      simde_mm_set_epi32(INT32_C(  503821785), INT32_C(   -1966044), INT32_C(   -1228291), INT32_C(    6420027)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( 1562990695), INT32_C(  134021098), INT32_C(-1071906850), INT32_C( -558152330)),
      simde_mm_set_epi32(INT32_C(-1746927677), INT32_C(    7209004), INT32_C(     917512), INT32_C(    4155429)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packs_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_packus_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(   217), INT16_C(-10893), INT16_C( 10007), INT16_C(-11974),
                         INT16_C(   134), INT16_C(    45), INT16_C(    21), INT16_C(   179)),
      simde_mm_set_epi16(INT16_C( 14829), INT16_C(    37), INT16_C(  2757), INT16_C(-26385),
                         INT16_C(    26), INT16_C(   196), INT16_C(  2768), INT16_C(   221)),
      simde_x_mm_set_epu8(255,  37, 255,   0,  26, 196, 255, 221,
                          217,   0, 255,   0, 134,  45,  21, 179) },
    { simde_mm_set_epi16(INT16_C(    84), INT16_C( 11197), INT16_C(    28), INT16_C(-18960),
                         INT16_C(     0), INT16_C(   243), INT16_C(   209), INT16_C(   115)),
      simde_mm_set_epi16(INT16_C( 26800), INT16_C(    44), INT16_C(   244), INT16_C(   114),
                         INT16_C(   234), INT16_C(  7269), INT16_C(  2441), INT16_C( -9419)),
      simde_x_mm_set_epu8(255,  44, 244, 114, 234, 255, 255,   0,
                           84, 255,  28,   0,   0, 243, 209, 115) },
    { simde_mm_set_epi16(INT16_C( 26559), INT16_C(-13811), INT16_C(   141), INT16_C(   130),
                         INT16_C(-24149), INT16_C(   185), INT16_C(  9120), INT16_C(-14604)),
      simde_mm_set_epi16(INT16_C(   190), INT16_C(   162), INT16_C(  3761), INT16_C(-10696),
                         INT16_C( 15175), INT16_C(  6926), INT16_C( 19649), INT16_C(    79)),
      simde_x_mm_set_epu8(190, 162, 255,   0, 255, 255, 255,  79,
                          255,   0, 141, 130,   0, 185, 255,   0) },
    { simde_mm_set_epi16(INT16_C(   250), INT16_C(-23643), INT16_C(-15994), INT16_C(   173),
                         INT16_C(    97), INT16_C(   158), INT16_C(    82), INT16_C(   231)),
      simde_mm_set_epi16(INT16_C(    70), INT16_C( 30022), INT16_C(     0), INT16_C( -8717),
                         INT16_C(     6), INT16_C(   206), INT16_C(-25401), INT16_C(   252)),
      simde_x_mm_set_epu8( 70, 255,   0,   0,   6, 206,   0, 252,
                          250,   0,   0, 173,  97, 158,  82, 231) },
    { simde_mm_set_epi16(INT16_C(    92), INT16_C(-13839), INT16_C(   243), INT16_C( -3624),
                         INT16_C(   252), INT16_C(-29405), INT16_C(     3), INT16_C(  6730)),
      simde_mm_set_epi16(INT16_C(  4496), INT16_C( 19200), INT16_C(    70), INT16_C(   128),
                         INT16_C(  2496), INT16_C(    60), INT16_C( 18531), INT16_C(-20006)),
      simde_x_mm_set_epu8(255, 255,  70, 128, 255,  60, 255,   0,
                           92,   0, 243,   0, 252,   0,   3, 255) },
    { simde_mm_set_epi16(INT16_C(    57), INT16_C(-14586), INT16_C( 21134), INT16_C(  7065),
                         INT16_C(     3), INT16_C(-16049), INT16_C( 26223), INT16_C(-20721)),
      simde_mm_set_epi16(INT16_C(   129), INT16_C(   105), INT16_C( -1899), INT16_C(   221),
                         INT16_C(-24446), INT16_C(-20297), INT16_C( 30906), INT16_C(   192)),
      simde_x_mm_set_epu8(129, 105,   0, 221,   0,   0, 255, 192,
                           57,   0, 255, 255,   3,   0, 255,   0) },
    { simde_mm_set_epi16(INT16_C(   128), INT16_C( 22639), INT16_C( -9670), INT16_C(  8168),
                         INT16_C( -1055), INT16_C(-24505), INT16_C( 32719), INT16_C( 16999)),
      simde_mm_set_epi16(INT16_C(-23185), INT16_C(   119), INT16_C(   108), INT16_C(    34),
                         INT16_C(-15892), INT16_C(  2641), INT16_C(   242), INT16_C( -7325)),
      simde_x_mm_set_epu8(  0, 119, 108,  34,   0, 255, 242,   0,
                          128, 255,   0, 255,   0,   0, 255, 255) },
    { simde_mm_set_epi16(INT16_C(    95), INT16_C(   145), INT16_C(   101), INT16_C(  5449),
                         INT16_C(   163), INT16_C( 19185), INT16_C(  3025), INT16_C(    52)),
      simde_mm_set_epi16(INT16_C(  2870), INT16_C(   140), INT16_C(   144), INT16_C(   254),
                         INT16_C(  8482), INT16_C(  4388), INT16_C(   201), INT16_C(-14867)),
      simde_x_mm_set_epu8(255, 140, 144, 254, 255, 255, 201,   0,
                           95, 145, 101, 255, 163, 255, 255,  52) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packus_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sad_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(215,  90,  59, 114, 199, 190,   5,  88,
                          189, 152,  95,  90,  71,  40,  85,  39),
      simde_x_mm_set_epu8( 54, 166, 154, 195, 131,  97, 225, 141,
                          107,   5,  50,  55, 194,  31, 223,  92),
      simde_mm_set_epi64x(INT64_C( 847), INT64_C( 632)) },
    { simde_x_mm_set_epu8( 73,   8,  35,  63,   9, 118, 137, 154,
                          163,  61,   8,   4,  96,  39, 181,  31),
      simde_x_mm_set_epu8(244,  64,  21,   0,  73,  79,  47, 148,
                          227,   0, 217, 151, 241, 123, 179, 200),
      simde_mm_set_epi64x(INT64_C( 503), INT64_C( 881)) },
    { simde_x_mm_set_epu8(188, 156, 164, 209,  37, 165, 186, 237,
                          157,  45, 141,   9, 227,   9,   6, 113),
      simde_x_mm_set_epu8(196,  12, 188, 136, 227,  14, 111, 188,
                           42, 252, 141, 251,  41,  42,  48,  10),
      simde_mm_set_epi64x(INT64_C( 714), INT64_C( 928)) },
    { simde_x_mm_set_epu8(221, 210, 203,  74, 151,  53, 237,  96,
                          105,  62,  32, 146, 208,  27, 214,  15),
      simde_x_mm_set_epu8(106, 143, 238,  35, 165, 158,  48,  47,
                           51, 172,  84,  44, 119, 233,  73,  10),
      simde_mm_set_epi64x(INT64_C( 613), INT64_C( 759)) },
    { simde_x_mm_set_epu8(158, 146, 218,  39,  84, 176,  15, 200,
                          114, 100, 110,  72,  37, 118, 124,  52),
      simde_x_mm_set_epu8(250, 173, 237, 165,  77, 193,  83,  68,
                          159, 214,  52, 182, 160, 117, 236, 237),
      simde_mm_set_epi64x(INT64_C( 488), INT64_C( 748)) },
    { simde_x_mm_set_epu8(116,  17,  11, 212,  41, 247, 182,  55,
                          218, 151,  38, 248,  87,   3, 108,   3),
      simde_x_mm_set_epu8(178, 255,   4, 183,  81, 104,  79, 156,
                          178, 174,  55, 110, 255,  70, 179, 129),
      simde_mm_set_epi64x(INT64_C( 723), INT64_C( 650)) },
    { simde_x_mm_set_epu8( 26, 112, 229,  82, 174, 243,  79,  54,
                          103,  25, 150, 156, 120,  47,  29, 212),
      simde_x_mm_set_epu8(155, 158, 100, 233, 190, 145,   4, 176,
                          236,  88,  45,  24, 159, 182,  83, 215),
      simde_mm_set_epi64x(INT64_C( 766), INT64_C( 664)) },
    { simde_x_mm_set_epu8( 29, 127,  97,  34, 247,  17,  64,  73,
                          255,  69, 189, 150, 155,  84, 174,  88),
      simde_x_mm_set_epu8(224, 212,  67, 184, 190,  48, 118, 149,
                          209, 255,   9, 200, 126, 242, 201,  30),
      simde_mm_set_epi64x(INT64_C( 678), INT64_C( 734)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sad_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_set_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int8_t e15;
    int8_t e14;
    int8_t e13;
    int8_t e12;
    int8_t e11;
    int8_t e10;
    int8_t e9;
    int8_t e8;
    int8_t e7;
    int8_t e6;
    int8_t e5;
    int8_t e4;
    int8_t e3;
    int8_t e2;
    int8_t e1;
    int8_t e0;
    simde__m128i r;
  } test_vec[8] = {
    {  -48,  -30,   88,  -96,    9,   89,   20,  -95,
        63,  -76,  126,   67,   85,   88,  -17, -107,
      simde_mm_set_epi8(INT8_C( -48), INT8_C( -30), INT8_C(  88), INT8_C( -96),
                        INT8_C(   9), INT8_C(  89), INT8_C(  20), INT8_C( -95),
                        INT8_C(  63), INT8_C( -76), INT8_C( 126), INT8_C(  67),
                        INT8_C(  85), INT8_C(  88), INT8_C( -17), INT8_C(-107)) },
    {   73,  -68,  -61,   58,  -37,    5,  -64,  -56,
        -5,   33,  -53,  -34,  -11,   57,   49,   12,
      simde_mm_set_epi8(INT8_C(  73), INT8_C( -68), INT8_C( -61), INT8_C(  58),
                        INT8_C( -37), INT8_C(   5), INT8_C( -64), INT8_C( -56),
                        INT8_C(  -5), INT8_C(  33), INT8_C( -53), INT8_C( -34),
                        INT8_C( -11), INT8_C(  57), INT8_C(  49), INT8_C(  12)) },
    {  -65, -108,   95, -117,   35,   45,   54,  -43,
       -45,  123,  113,   -6,   23,  -66,   77,   94,
      simde_mm_set_epi8(INT8_C( -65), INT8_C(-108), INT8_C(  95), INT8_C(-117),
                        INT8_C(  35), INT8_C(  45), INT8_C(  54), INT8_C( -43),
                        INT8_C( -45), INT8_C( 123), INT8_C( 113), INT8_C(  -6),
                        INT8_C(  23), INT8_C( -66), INT8_C(  77), INT8_C(  94)) },
    {  -72,   95,  112,   68,   56,  -74,  -97,  -55,
        22,   53,  -22,   68, -107,   99,   -5,  -94,
      simde_mm_set_epi8(INT8_C( -72), INT8_C(  95), INT8_C( 112), INT8_C(  68),
                        INT8_C(  56), INT8_C( -74), INT8_C( -97), INT8_C( -55),
                        INT8_C(  22), INT8_C(  53), INT8_C( -22), INT8_C(  68),
                        INT8_C(-107), INT8_C(  99), INT8_C(  -5), INT8_C( -94)) },
    {  -48,    6,  114,   89,  -57, -104,  -78,  -72,
       -32,  -41,  -27,  -58,   -1, -100, -126,  -52,
      simde_mm_set_epi8(INT8_C( -48), INT8_C(   6), INT8_C( 114), INT8_C(  89),
                        INT8_C( -57), INT8_C(-104), INT8_C( -78), INT8_C( -72),
                        INT8_C( -32), INT8_C( -41), INT8_C( -27), INT8_C( -58),
                        INT8_C(  -1), INT8_C(-100), INT8_C(-126), INT8_C( -52)) },
    {   75, -127,  -59,   90,  126,   -9,   88,   22,
        36,   75,  -11,  -10,   31,  -72,   19,  -30,
      simde_mm_set_epi8(INT8_C(  75), INT8_C(-127), INT8_C( -59), INT8_C(  90),
                        INT8_C( 126), INT8_C(  -9), INT8_C(  88), INT8_C(  22),
                        INT8_C(  36), INT8_C(  75), INT8_C( -11), INT8_C( -10),
                        INT8_C(  31), INT8_C( -72), INT8_C(  19), INT8_C( -30)) },
    {  -66,   57,   86,  -24, -102,   97,   37,   79,
        98,  -52,   75,  113,  -66,  -45,  -97,   50,
      simde_mm_set_epi8(INT8_C( -66), INT8_C(  57), INT8_C(  86), INT8_C( -24),
                        INT8_C(-102), INT8_C(  97), INT8_C(  37), INT8_C(  79),
                        INT8_C(  98), INT8_C( -52), INT8_C(  75), INT8_C( 113),
                        INT8_C( -66), INT8_C( -45), INT8_C( -97), INT8_C(  50)) },
    {  -14,  -31,   -3,   35,   62,   73,   10,   46,
        72,  110,  -30,   71,  -50,  -46,  106,  -75,
      simde_mm_set_epi8(INT8_C( -14), INT8_C( -31), INT8_C(  -3), INT8_C(  35),
                        INT8_C(  62), INT8_C(  73), INT8_C(  10), INT8_C(  46),
                        INT8_C(  72), INT8_C( 110), INT8_C( -30), INT8_C(  71),
                        INT8_C( -50), INT8_C( -46), INT8_C( 106), INT8_C( -75)) },
  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   int8_t e15 = munit_rand_uint32();
  //   int8_t e14 = munit_rand_uint32();
  //   int8_t e13 = munit_rand_uint32();
  //   int8_t e12 = munit_rand_uint32();
  //   int8_t e11 = munit_rand_uint32();
  //   int8_t e10 = munit_rand_uint32();
  //   int8_t e9 = munit_rand_uint32();
  //   int8_t e8 = munit_rand_uint32();
  //   int8_t e7 = munit_rand_uint32();
  //   int8_t e6 = munit_rand_uint32();
  //   int8_t e5 = munit_rand_uint32();
  //   int8_t e4 = munit_rand_uint32();
  //   int8_t e3 = munit_rand_uint32();
  //   int8_t e2 = munit_rand_uint32();
  //   int8_t e1 = munit_rand_uint32();
  //   int8_t e0 = munit_rand_uint32();
  //   simde__m128i_private r;

  //   r = simde__m128i_to_private(simde_mm_set_epi8(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0));

  //   printf("    { %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ",\n"
  //          "      %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ",\n",
  //          e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0);
  //   printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
  //          r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
  //          r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set_epi8(
        test_vec[i].e15, test_vec[i].e14, test_vec[i].e13, test_vec[i].e12,
        test_vec[i].e11, test_vec[i].e10, test_vec[i].e9, test_vec[i].e8,
        test_vec[i].e7, test_vec[i].e6, test_vec[i].e5, test_vec[i].e4,
        test_vec[i].e3, test_vec[i].e2, test_vec[i].e1, test_vec[i].e0);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}


static int
test_simde_mm_set_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int16_t e7;
    int16_t e6;
    int16_t e5;
    int16_t e4;
    int16_t e3;
    int16_t e2;
    int16_t e1;
    int16_t e0;
    simde__m128i r;
  } test_vec[8] = {
    { -12714, -18436,  19109,  27542,  -4031,  11847,  32066,   4849,
      simde_mm_set_epi16(INT16_C(-12714), INT16_C(-18436), INT16_C( 19109), INT16_C( 27542),
                         INT16_C( -4031), INT16_C( 11847), INT16_C( 32066), INT16_C(  4849)) },
    {  20812, -18306,  32711,   2248, -22144, -30920,  20888, -23709,
      simde_mm_set_epi16(INT16_C( 20812), INT16_C(-18306), INT16_C( 32711), INT16_C(  2248),
                         INT16_C(-22144), INT16_C(-30920), INT16_C( 20888), INT16_C(-23709)) },
    {   8868, -14625,  -5258, -12928, -11989,  31315,  -9098,  19222,
      simde_mm_set_epi16(INT16_C(  8868), INT16_C(-14625), INT16_C( -5258), INT16_C(-12928),
                         INT16_C(-11989), INT16_C( 31315), INT16_C( -9098), INT16_C( 19222)) },
    {  -5334,  23871,   3901,  14443, -13328,  23359, -24889,  28356,
      simde_mm_set_epi16(INT16_C( -5334), INT16_C( 23871), INT16_C(  3901), INT16_C( 14443),
                         INT16_C(-13328), INT16_C( 23359), INT16_C(-24889), INT16_C( 28356)) },
    {  10774, -19043,  31284,   4044,    862, -11938, -27554, -25119,
      simde_mm_set_epi16(INT16_C( 10774), INT16_C(-19043), INT16_C( 31284), INT16_C(  4044),
                         INT16_C(   862), INT16_C(-11938), INT16_C(-27554), INT16_C(-25119)) },
    {  20150, -31510, -29797,  -3272, -18019,  16111, -15969, -11740,
      simde_mm_set_epi16(INT16_C( 20150), INT16_C(-31510), INT16_C(-29797), INT16_C( -3272),
                         INT16_C(-18019), INT16_C( 16111), INT16_C(-15969), INT16_C(-11740)) },
    {  -3147, -24243, -28710,  -5510, -20724,  13872,  -9632,  -7728,
      simde_mm_set_epi16(INT16_C( -3147), INT16_C(-24243), INT16_C(-28710), INT16_C( -5510),
                         INT16_C(-20724), INT16_C( 13872), INT16_C( -9632), INT16_C( -7728)) },
    {   6318,  11524,  30789,  -2974,   3458, -10908, -25743, -20801,
      simde_mm_set_epi16(INT16_C(  6318), INT16_C( 11524), INT16_C( 30789), INT16_C( -2974),
                         INT16_C(  3458), INT16_C(-10908), INT16_C(-25743), INT16_C(-20801)) },
  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   int16_t e7 = munit_rand_uint32();
  //   int16_t e6 = munit_rand_uint32();
  //   int16_t e5 = munit_rand_uint32();
  //   int16_t e4 = munit_rand_uint32();
  //   int16_t e3 = munit_rand_uint32();
  //   int16_t e2 = munit_rand_uint32();
  //   int16_t e1 = munit_rand_uint32();
  //   int16_t e0 = munit_rand_uint32();
  //   simde__m128i_private r;

  //   r = simde__m128i_to_private(simde_mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0));

  //   printf("    { %6" PRId16 ", %6" PRId16 ", %6" PRId16 ", %6" PRId16 ", %6" PRId16 ", %6" PRId16 ", %6" PRId16 ", %6" PRId16 ",\n",
  //          e7, e6, e5, e4, e3, e2, e1, e0);
  //   printf("      simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	//    "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
  //          r.i16[7], r.i16[6], r.i16[5], r.i16[4], r.i16[3], r.i16[2], r.i16[1], r.i16[0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set_epi16(
        test_vec[i].e7, test_vec[i].e6, test_vec[i].e5, test_vec[i].e4,
        test_vec[i].e3, test_vec[i].e2, test_vec[i].e1, test_vec[i].e0);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_set_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t e3;
    int32_t e2;
    int32_t e1;
    int32_t e0;
    simde__m128i r;
  } test_vec[8] = {
    {   391721235,  1158362691,  2131167346, -1830589941,
      simde_mm_set_epi32(INT32_C(  391721235), INT32_C( 1158362691), INT32_C( 2131167346), INT32_C(-1830589941)) },
    {  2141048609,  2073510589,   924258053,   594030571,
      simde_mm_set_epi32(INT32_C( 2141048609), INT32_C( 2073510589), INT32_C(  924258053), INT32_C(  594030571)) },
    {  1247989717,   798714331, -1727766974,  1099259705,
      simde_mm_set_epi32(INT32_C( 1247989717), INT32_C(  798714331), INT32_C(-1727766974), INT32_C( 1099259705)) },
    {  1870669627,  1775697551, -2027090738, -1897466045,
      simde_mm_set_epi32(INT32_C( 1870669627), INT32_C( 1775697551), INT32_C(-2027090738), INT32_C(-1897466045)) },
    {  -584467290,  2134946541,   565373055,  -212717620,
      simde_mm_set_epi32(INT32_C( -584467290), INT32_C( 2134946541), INT32_C(  565373055), INT32_C( -212717620)) },
    {  2072276971,  1968759191,  2049222745,    64876297,
      simde_mm_set_epi32(INT32_C( 2072276971), INT32_C( 1968759191), INT32_C( 2049222745), INT32_C(   64876297)) },
    {  -285499155,  -775226349,  1401270915,  -476575867,
      simde_mm_set_epi32(INT32_C( -285499155), INT32_C( -775226349), INT32_C( 1401270915), INT32_C( -476575867)) },
    {  -135350759, -1402535212,  -799024597,  1171022108,
      simde_mm_set_epi32(INT32_C( -135350759), INT32_C(-1402535212), INT32_C( -799024597), INT32_C( 1171022108)) },

  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   int32_t e3 = munit_rand_uint32();
  //   int32_t e2 = munit_rand_uint32();
  //   int32_t e1 = munit_rand_uint32();
  //   int32_t e0 = munit_rand_uint32();
  //   simde__m128i_private r;

  //   r = simde__m128i_to_private(simde_mm_set_epi32(e3, e2, e1, e0));

  //   printf("    { %11" PRId32 ", %11" PRId32 ", %11" PRId32 ", %11" PRId32 ",\n",
  //       e3, e2, e1, e0);
  //   printf("      simde_mm_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
  //          r.i32[3], r.i32[2], r.i32[1], r.i32[0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set_epi32(
        test_vec[i].e3, test_vec[i].e2, test_vec[i].e1, test_vec[i].e0);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}


static int
test_simde_mm_set_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_pi64(INT64_C( -664890281848034973)),
      simde_x_mm_set_pi64(INT64_C(-2789670716680390611)),
      simde_mm_set_epi64x(INT64_C( -664890281848034973), INT64_C(-2789670716680390611)) },
    { simde_x_mm_set_pi64(INT64_C( 5148232775303872766)),
      simde_x_mm_set_pi64(INT64_C(-4313892930136448255)),
      simde_mm_set_epi64x(INT64_C( 5148232775303872766), INT64_C(-4313892930136448255)) },
    { simde_x_mm_set_pi64(INT64_C(-1888312870737326599)),
      simde_x_mm_set_pi64(INT64_C( 5248373813564878857)),
      simde_mm_set_epi64x(INT64_C(-1888312870737326599), INT64_C( 5248373813564878857)) },
    { simde_x_mm_set_pi64(INT64_C(-1560565807933837504)),
      simde_x_mm_set_pi64(INT64_C( 7268621988108136806)),
      simde_mm_set_epi64x(INT64_C(-1560565807933837504), INT64_C( 7268621988108136806)) },
    { simde_x_mm_set_pi64(INT64_C(-1956110667393926378)),
      simde_x_mm_set_pi64(INT64_C(  345154446382384077)),
      simde_mm_set_epi64x(INT64_C(-1956110667393926378), INT64_C(  345154446382384077)) },
    { simde_x_mm_set_pi64(INT64_C(-8505578167241709019)),
      simde_x_mm_set_pi64(INT64_C( 8252355195326597777)),
      simde_mm_set_epi64x(INT64_C(-8505578167241709019), INT64_C( 8252355195326597777)) },
    { simde_x_mm_set_pi64(INT64_C( 1122841158674863793)),
      simde_x_mm_set_pi64(INT64_C(-5697643761898453242)),
      simde_mm_set_epi64x(INT64_C( 1122841158674863793), INT64_C(-5697643761898453242)) },
    { simde_x_mm_set_pi64(INT64_C(-6130487997584440381)),
      simde_x_mm_set_pi64(INT64_C( 8349290391131198480)),
      simde_mm_set_epi64x(INT64_C(-6130487997584440381), INT64_C( 8349290391131198480)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}
static int
test_simde_mm_set_epi64x(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t e0;
    int64_t e1;
    simde__m128i r;
  } test_vec[8] = {
    {  4539993052502346892,  6550919315486945587,
      simde_mm_set_epi64x(INT64_C( 4539993052502346892), INT64_C( 6550919315486945587)) },
    { -8973439144672590874,  1846200258209621581,
      simde_mm_set_epi64x(INT64_C(-8973439144672590874), INT64_C( 1846200258209621581)) },
    {   771735515044186414, -5491872275643679405,
      simde_mm_set_epi64x(INT64_C(  771735515044186414), INT64_C(-5491872275643679405)) },
    {  3535609691698693035, -2659398015885158473,
      simde_mm_set_epi64x(INT64_C( 3535609691698693035), INT64_C(-2659398015885158473)) },
    { -5310489553719126486, -1326851720416490864,
      simde_mm_set_epi64x(INT64_C(-5310489553719126486), INT64_C(-1326851720416490864)) },
    { -1132069192689462333, -3126474808030937011,
      simde_mm_set_epi64x(INT64_C(-1132069192689462333), INT64_C(-3126474808030937011)) },
    {  3201360662826502659,  2894150994676591563,
      simde_mm_set_epi64x(INT64_C( 3201360662826502659), INT64_C( 2894150994676591563)) },
    {  5657213110111307867,  4054595932996548594,
      simde_mm_set_epi64x(INT64_C( 5657213110111307867), INT64_C( 4054595932996548594)) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set_epi64x(test_vec[i].e0, test_vec[i].e1);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_set1_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t a;
    const int8_t r[16];
  } test_vec[] = {
    { -INT8_C(  57),
      { -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57),
        -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57) } },
    { -INT8_C(  62),
      { -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62),
        -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62) } },
    { -INT8_C(  94),
      { -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94),
        -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94) } },
    { -INT8_C(  11),
      { -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11),
        -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11) } },
    { -INT8_C(  57),
      { -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57),
        -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57), -INT8_C(  57) } },
    {  INT8_C(  73),
      {  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),
         INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73),  INT8_C(  73) } },
    {  INT8_C(  60),
      {  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),
         INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60) } },
    { -INT8_C(   6),
      { -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6),
        -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_set1_epi8(test_vec[i].a);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_set1_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int16_t a;
    simde__m128i r;
  } test_vec[8] = {
    { -22932,
      simde_mm_set_epi16(INT16_C(-22932), INT16_C(-22932), INT16_C(-22932), INT16_C(-22932),
                         INT16_C(-22932), INT16_C(-22932), INT16_C(-22932), INT16_C(-22932)) },
    {  23064,
      simde_mm_set_epi16(INT16_C( 23064), INT16_C( 23064), INT16_C( 23064), INT16_C( 23064),
                         INT16_C( 23064), INT16_C( 23064), INT16_C( 23064), INT16_C( 23064)) },
    {  29063,
      simde_mm_set_epi16(INT16_C( 29063), INT16_C( 29063), INT16_C( 29063), INT16_C( 29063),
                         INT16_C( 29063), INT16_C( 29063), INT16_C( 29063), INT16_C( 29063)) },
    {  -6254,
      simde_mm_set_epi16(INT16_C( -6254), INT16_C( -6254), INT16_C( -6254), INT16_C( -6254),
                         INT16_C( -6254), INT16_C( -6254), INT16_C( -6254), INT16_C( -6254)) },
    {  23328,
      simde_mm_set_epi16(INT16_C( 23328), INT16_C( 23328), INT16_C( 23328), INT16_C( 23328),
                         INT16_C( 23328), INT16_C( 23328), INT16_C( 23328), INT16_C( 23328)) },
    {  12202,
      simde_mm_set_epi16(INT16_C( 12202), INT16_C( 12202), INT16_C( 12202), INT16_C( 12202),
                         INT16_C( 12202), INT16_C( 12202), INT16_C( 12202), INT16_C( 12202)) },
    {  26711,
      simde_mm_set_epi16(INT16_C( 26711), INT16_C( 26711), INT16_C( 26711), INT16_C( 26711),
                         INT16_C( 26711), INT16_C( 26711), INT16_C( 26711), INT16_C( 26711)) },
    {  -9629,
      simde_mm_set_epi16(INT16_C( -9629), INT16_C( -9629), INT16_C( -9629), INT16_C( -9629),
                         INT16_C( -9629), INT16_C( -9629), INT16_C( -9629), INT16_C( -9629)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set1_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_set1_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a;
    const int32_t r[4];
  } test_vec[] = {
    { -INT32_C(  1379277210),
      { -INT32_C(  1379277210), -INT32_C(  1379277210), -INT32_C(  1379277210), -INT32_C(  1379277210) } },
    {  INT32_C(  1628685468),
      {  INT32_C(  1628685468),  INT32_C(  1628685468),  INT32_C(  1628685468),  INT32_C(  1628685468) } },
    {  INT32_C(  1687738541),
      {  INT32_C(  1687738541),  INT32_C(  1687738541),  INT32_C(  1687738541),  INT32_C(  1687738541) } },
    {  INT32_C(  1891425133),
      {  INT32_C(  1891425133),  INT32_C(  1891425133),  INT32_C(  1891425133),  INT32_C(  1891425133) } },
    {  INT32_C(  1695660386),
      {  INT32_C(  1695660386),  INT32_C(  1695660386),  INT32_C(  1695660386),  INT32_C(  1695660386) } },
    {  INT32_C(  1846447439),
      {  INT32_C(  1846447439),  INT32_C(  1846447439),  INT32_C(  1846447439),  INT32_C(  1846447439) } },
    {  INT32_C(   958687000),
      {  INT32_C(   958687000),  INT32_C(   958687000),  INT32_C(   958687000),  INT32_C(   958687000) } },
    { -INT32_C(  1238079408),
      { -INT32_C(  1238079408), -INT32_C(  1238079408), -INT32_C(  1238079408), -INT32_C(  1238079408) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_set1_epi32(test_vec[i].a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_set1_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C(  922.45),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  922.45), SIMDE_FLOAT64_C(  922.45)) },
    { SIMDE_FLOAT64_C( -599.83),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -599.83), SIMDE_FLOAT64_C( -599.83)) },
    { SIMDE_FLOAT64_C( -398.06),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -398.06), SIMDE_FLOAT64_C( -398.06)) },
    { SIMDE_FLOAT64_C(  758.75),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  758.75), SIMDE_FLOAT64_C(  758.75)) },
    { SIMDE_FLOAT64_C( -273.82),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -273.82), SIMDE_FLOAT64_C( -273.82)) },
    { SIMDE_FLOAT64_C( -320.64),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -320.64), SIMDE_FLOAT64_C( -320.64)) },
    { SIMDE_FLOAT64_C(  627.18),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  627.18), SIMDE_FLOAT64_C(  627.18)) },
    { SIMDE_FLOAT64_C(  433.85),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  433.85), SIMDE_FLOAT64_C(  433.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_set1_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_set_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    double e0;
    double e1;
    simde__m128d r;
  } test_vec[8] = {
    { (1062807988.00), 4166063422.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(1062807988.00), SIMDE_FLOAT64_C(4166063422.00)) },
    { (4089462150.00), 3301875355.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(4089462150.00), SIMDE_FLOAT64_C(3301875355.00)) },
    { (2961047618.00), 1310362259.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(2961047618.00), SIMDE_FLOAT64_C(1310362259.00)) },
    { (491413403.00), 2980697460.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(491413403.00), SIMDE_FLOAT64_C(2980697460.00)) },
    { (3027292014.00), 1034055676.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(3027292014.00), SIMDE_FLOAT64_C(1034055676.00)) },
    { (133655993.00), 2416999239.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(133655993.00), SIMDE_FLOAT64_C(2416999239.00)) },
    { (2396615078.00), 517112175.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(2396615078.00), SIMDE_FLOAT64_C(517112175.00)) },
    { (628434760.00), 1544868779.00,
      simde_mm_set_pd(SIMDE_FLOAT64_C(628434760.00), SIMDE_FLOAT64_C(1544868779.00)) },
  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   double e0 = munit_rand_uint32() ;
  //   double e1 = munit_rand_uint32() ;
  //   simde__m128d_private r;

  //   r = simde__m128d_to_private(simde_mm_set_pd(e0, e1));

  //   printf("    { (%*.2f), %*.2f,\n", 8, e0, 8, e1);
  //   printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_set_pd(test_vec[i].e0, test_vec[i].e1);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_set_pd1(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    double a;
    simde__m128d r;
  } test_vec[8] = {
    { (983122077.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(983122077.00), SIMDE_FLOAT64_C(983122077.00)) },
    { (2243688041.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(2243688041.00), SIMDE_FLOAT64_C(2243688041.00)) },
    { (1259032742.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1259032742.00), SIMDE_FLOAT64_C(1259032742.00)) },
    { (945157531.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(945157531.00), SIMDE_FLOAT64_C(945157531.00)) },
    { (2547177525.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(2547177525.00), SIMDE_FLOAT64_C(2547177525.00)) },
    { (2112014239.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(2112014239.00), SIMDE_FLOAT64_C(2112014239.00)) },
    { (1570949017.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1570949017.00), SIMDE_FLOAT64_C(1570949017.00)) },
    { (1215464208.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1215464208.00), SIMDE_FLOAT64_C(1215464208.00)) },
  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   double a = munit_rand_uint32() ;
  //   simde__m128d_private r;

  //   r = simde__m128d_to_private(simde_mm_set_pd1(a));

  //   printf("    { (%*.2f),\n", 8, a);
  //   printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_set_pd1(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}


static int
test_simde_mm_set_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C( -222.00),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -222.00)) },
    { SIMDE_FLOAT64_C(  804.62),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  804.62)) },
    { SIMDE_FLOAT64_C(  845.92),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  845.92)) },
    { SIMDE_FLOAT64_C(  892.20),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  892.20)) },
    { SIMDE_FLOAT64_C(  233.47),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  233.47)) },
    { SIMDE_FLOAT64_C( -916.51),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -916.51)) },
    { SIMDE_FLOAT64_C(   -0.11),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.11)) },
    { SIMDE_FLOAT64_C( -843.72),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -843.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_set_sd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_set1_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_pi64(INT64_C(5509445936599134262)),
      simde_mm_set_epi64x(INT64_C(5509445936599134262), INT64_C(5509445936599134262)) },
    { simde_x_mm_set_pi64(INT64_C(6533321325309895597)),
      simde_mm_set_epi64x(INT64_C(6533321325309895597), INT64_C(6533321325309895597)) },
    { simde_x_mm_set_pi64(INT64_C(8570268616515205604)),
      simde_mm_set_epi64x(INT64_C(8570268616515205604), INT64_C(8570268616515205604)) },
    { simde_x_mm_set_pi64(INT64_C(6893954556242409981)),
      simde_mm_set_epi64x(INT64_C(6893954556242409981), INT64_C(6893954556242409981)) },
    { simde_x_mm_set_pi64(INT64_C( 479685313418970755)),
      simde_mm_set_epi64x(INT64_C( 479685313418970755), INT64_C( 479685313418970755)) },
    { simde_x_mm_set_pi64(INT64_C(1310625044422752521)),
      simde_mm_set_epi64x(INT64_C(1310625044422752521), INT64_C(1310625044422752521)) },
    { simde_x_mm_set_pi64(INT64_C(-9181800088333422881)),
      simde_mm_set_epi64x(INT64_C(-9181800088333422881), INT64_C(-9181800088333422881)) },
    { simde_x_mm_set_pi64(INT64_C(-4247659939651135559)),
      simde_mm_set_epi64x(INT64_C(-4247659939651135559), INT64_C(-4247659939651135559)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set1_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_set1_epi64x(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t a;
    simde__m128i r;
  } test_vec[8] = {
    { INT64_C(-7342192307236287075),
      simde_mm_set_epi64x(INT64_C(-7342192307236287075), INT64_C(-7342192307236287075)) },
    { INT64_C(-8079223173243549940),
      simde_mm_set_epi64x(INT64_C(-8079223173243549940), INT64_C(-8079223173243549940)) },
    { INT64_C(8128959178680760661),
      simde_mm_set_epi64x(INT64_C(8128959178680760661), INT64_C(8128959178680760661)) },
    { INT64_C(6271233176655491948),
      simde_mm_set_epi64x(INT64_C(6271233176655491948), INT64_C(6271233176655491948)) },
    { INT64_C(3474926301195230116),
      simde_mm_set_epi64x(INT64_C(3474926301195230116), INT64_C(3474926301195230116)) },
    { INT64_C(-5217363481586450008),
      simde_mm_set_epi64x(INT64_C(-5217363481586450008), INT64_C(-5217363481586450008)) },
    { INT64_C(-7156667910834929798),
      simde_mm_set_epi64x(INT64_C(-7156667910834929798), INT64_C(-7156667910834929798)) },
    { INT64_C(8467790055770652882),
      simde_mm_set_epi64x(INT64_C(8467790055770652882), INT64_C(8467790055770652882)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_set1_epi64x(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_setr_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int8_t a[16];
    simde__m128i r;
  } test_vec[8] = {
    { { -117,  101,  -68,  -84,   57,  -16,   14,  112,
          -4,  -62,   47,  -17,   21,   25,  -74,   93 },
      simde_mm_set_epi8(INT8_C(  93), INT8_C( -74), INT8_C(  25), INT8_C(  21), INT8_C( -17), INT8_C(  47), INT8_C( -62), INT8_C(  -4),
                        INT8_C( 112), INT8_C(  14), INT8_C( -16), INT8_C(  57), INT8_C( -84), INT8_C( -68), INT8_C( 101), INT8_C(-117)) },
    { { -121,  -99,   93,   75,  -45,   61,  -29,   21,
          43,  -55, -114,  120,    9,  -25,  107,  106 },
      simde_mm_set_epi8(INT8_C( 106), INT8_C( 107), INT8_C( -25), INT8_C(   9), INT8_C( 120), INT8_C(-114), INT8_C( -55), INT8_C(  43),
                        INT8_C(  21), INT8_C( -29), INT8_C(  61), INT8_C( -45), INT8_C(  75), INT8_C(  93), INT8_C( -99), INT8_C(-121)) },
    { {   17,  120,   33,  -15,  -38,  -48,   75,  -19,
         105,  -73,  -87,   91,   57,  125,   70,   11 },
      simde_mm_set_epi8(INT8_C(  11), INT8_C(  70), INT8_C( 125), INT8_C(  57), INT8_C(  91), INT8_C( -87), INT8_C( -73), INT8_C( 105),
                        INT8_C( -19), INT8_C(  75), INT8_C( -48), INT8_C( -38), INT8_C( -15), INT8_C(  33), INT8_C( 120), INT8_C(  17)) },
    { {   56,  -40,   93,   54,    0, -115,  -62,    6,
          10,  -58,  -12,   31,  -96,   67,   12,   19 },
      simde_mm_set_epi8(INT8_C(  19), INT8_C(  12), INT8_C(  67), INT8_C( -96), INT8_C(  31), INT8_C( -12), INT8_C( -58), INT8_C(  10),
                        INT8_C(   6), INT8_C( -62), INT8_C(-115), INT8_C(   0), INT8_C(  54), INT8_C(  93), INT8_C( -40), INT8_C(  56)) },
    { {   37,  -21,   96,  -83,   46,  -81,  -51,  -14,
         127,   26,  -91,  -48,   45,  -55, -111,  109 },
      simde_mm_set_epi8(INT8_C( 109), INT8_C(-111), INT8_C( -55), INT8_C(  45), INT8_C( -48), INT8_C( -91), INT8_C(  26), INT8_C( 127),
                        INT8_C( -14), INT8_C( -51), INT8_C( -81), INT8_C(  46), INT8_C( -83), INT8_C(  96), INT8_C( -21), INT8_C(  37)) },
    { {  -77,   43,  114,  -94,  -36,  -86,  -18,   18,
          14,   -4,   99,   78,   44,   70,  105,  -91 },
      simde_mm_set_epi8(INT8_C( -91), INT8_C( 105), INT8_C(  70), INT8_C(  44), INT8_C(  78), INT8_C(  99), INT8_C(  -4), INT8_C(  14),
                        INT8_C(  18), INT8_C( -18), INT8_C( -86), INT8_C( -36), INT8_C( -94), INT8_C( 114), INT8_C(  43), INT8_C( -77)) },
    { {  125,  -73,  -25, -106,   -9,  112,  -96,   59,
          61,  -50,   73,  -71,   13,    0,  -64,  -15 },
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -64), INT8_C(   0), INT8_C(  13), INT8_C( -71), INT8_C(  73), INT8_C( -50), INT8_C(  61),
                        INT8_C(  59), INT8_C( -96), INT8_C( 112), INT8_C(  -9), INT8_C(-106), INT8_C( -25), INT8_C( -73), INT8_C( 125)) },
    { {   76,   81,  -62,   21,   -3,   99,  -61,  126,
         -15,  -95,   99,  -34,   78,   36,   56,  -38 },
      simde_mm_set_epi8(INT8_C( -38), INT8_C(  56), INT8_C(  36), INT8_C(  78), INT8_C( -34), INT8_C(  99), INT8_C( -95), INT8_C( -15),
                        INT8_C( 126), INT8_C( -61), INT8_C(  99), INT8_C(  -3), INT8_C(  21), INT8_C( -62), INT8_C(  81), INT8_C(  76)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r =
      simde_mm_setr_epi8(test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
                         test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7],
                         test_vec[i].a[ 8], test_vec[i].a[ 9], test_vec[i].a[10], test_vec[i].a[11],
                         test_vec[i].a[12], test_vec[i].a[13], test_vec[i].a[14], test_vec[i].a[15]);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_setr_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int16_t a[8];
    simde__m128i r;
  } test_vec[8] = {
    { { -10562,  -1563,   3119,   8148, -20473,  28066,  19911,  32415 },
      simde_mm_set_epi16(INT16_C( 32415), INT16_C( 19911), INT16_C( 28066), INT16_C(-20473),
                         INT16_C(  8148), INT16_C(  3119), INT16_C( -1563), INT16_C(-10562)) },
    { {  -5842, -19524,  19809,  -4522, -18693, -13515,  10296, -11468 },
      simde_mm_set_epi16(INT16_C(-11468), INT16_C( 10296), INT16_C(-13515), INT16_C(-18693),
                         INT16_C( -4522), INT16_C( 19809), INT16_C(-19524), INT16_C( -5842)) },
    { {  21973, -10968, -22468,   4564,  15035,   4920,  15286,  10966 },
      simde_mm_set_epi16(INT16_C( 10966), INT16_C( 15286), INT16_C(  4920), INT16_C( 15035),
                         INT16_C(  4564), INT16_C(-22468), INT16_C(-10968), INT16_C( 21973)) },
    { { -30861,  17137,  12124,  23736,  -1854,  30822, -26631,  14095 },
      simde_mm_set_epi16(INT16_C( 14095), INT16_C(-26631), INT16_C( 30822), INT16_C( -1854),
                         INT16_C( 23736), INT16_C( 12124), INT16_C( 17137), INT16_C(-30861)) },
    { {  -8301, -14416, -32194,  -4341,   1212,  26290, -16654,  -9801 },
      simde_mm_set_epi16(INT16_C( -9801), INT16_C(-16654), INT16_C( 26290), INT16_C(  1212),
                         INT16_C( -4341), INT16_C(-32194), INT16_C(-14416), INT16_C( -8301)) },
    { {  -5842,  17831,    171,  10031,   7446,  23430,  -5408, -23387 },
      simde_mm_set_epi16(INT16_C(-23387), INT16_C( -5408), INT16_C( 23430), INT16_C(  7446),
                         INT16_C( 10031), INT16_C(   171), INT16_C( 17831), INT16_C( -5842)) },
    { {   3343, -24774,  -5050,  25934, -13848,  27661,  13484,  -5817 },
      simde_mm_set_epi16(INT16_C( -5817), INT16_C( 13484), INT16_C( 27661), INT16_C(-13848),
                         INT16_C( 25934), INT16_C( -5050), INT16_C(-24774), INT16_C(  3343)) },
    { {  27516, -24147, -18268,  10553,  12061, -22335,  29977, -25416 },
      simde_mm_set_epi16(INT16_C(-25416), INT16_C( 29977), INT16_C(-22335), INT16_C( 12061),
                         INT16_C( 10553), INT16_C(-18268), INT16_C(-24147), INT16_C( 27516)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r =
      simde_mm_setr_epi16(test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
                          test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7]);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_setr_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t a[4];
    simde__m128i r;
  } test_vec[8] = {
    { { INT32_C(  576930619), INT32_C(-1056617076), INT32_C( 1391020156), INT32_C( -119436850) },
      simde_mm_set_epi32(INT32_C( -119436850), INT32_C( 1391020156), INT32_C(-1056617076), INT32_C(  576930619)) },
    { { INT32_C(-2038323421), INT32_C(-1916700674), INT32_C( 1438851519), INT32_C( 1990196695) },
      simde_mm_set_epi32(INT32_C( 1990196695), INT32_C( 1438851519), INT32_C(-1916700674), INT32_C(-2038323421)) },
    { { INT32_C( 1146758814), INT32_C(  625179194), INT32_C(-1226824864), INT32_C(-1523319395) },
      simde_mm_set_epi32(INT32_C(-1523319395), INT32_C(-1226824864), INT32_C(  625179194), INT32_C( 1146758814)) },
    { { INT32_C( -276839793), INT32_C( 1178530072), INT32_C(-1956542830), INT32_C( -556652843) },
      simde_mm_set_epi32(INT32_C( -556652843), INT32_C(-1956542830), INT32_C( 1178530072), INT32_C( -276839793)) },
    { { INT32_C(-1720519476), INT32_C(  147115658), INT32_C(  736217848), INT32_C(-1149123643) },
      simde_mm_set_epi32(INT32_C(-1149123643), INT32_C(  736217848), INT32_C(  147115658), INT32_C(-1720519476)) },
    { { INT32_C( 1888725856), INT32_C( -696349459), INT32_C(-1872984731), INT32_C( 1198325431) },
      simde_mm_set_epi32(INT32_C( 1198325431), INT32_C(-1872984731), INT32_C( -696349459), INT32_C( 1888725856)) },
    { { INT32_C( 1999809110), INT32_C( -469856594), INT32_C(-1721902839), INT32_C(-1910021155) },
      simde_mm_set_epi32(INT32_C(-1910021155), INT32_C(-1721902839), INT32_C( -469856594), INT32_C( 1999809110)) },
    { { INT32_C(   57396463), INT32_C(-1219624618), INT32_C( -492678555), INT32_C(-1751286944) },
      simde_mm_set_epi32(INT32_C(-1751286944), INT32_C( -492678555), INT32_C(-1219624618), INT32_C(   57396463)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_setr_epi32(test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3]);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_setr_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 e1;
    simde__m64 e0;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(-4101257248168872649)),
      simde_mm_cvtsi64_m64(INT64_C(-2723834683478465794)),
      simde_mm_set_epi64x(INT64_C(-2723834683478465794), INT64_C(-4101257248168872649)) },
    { simde_mm_cvtsi64_m64(INT64_C(-2051996013747413745)),
      simde_mm_cvtsi64_m64(INT64_C(-3184937756541660331)),
      simde_mm_set_epi64x(INT64_C(-3184937756541660331), INT64_C(-2051996013747413745)) },
    { simde_mm_cvtsi64_m64(INT64_C(-1223296052051875883)),
      simde_mm_cvtsi64_m64(INT64_C( 3027248353112135930)),
      simde_mm_set_epi64x(INT64_C( 3027248353112135930), INT64_C(-1223296052051875883)) },
    { simde_mm_cvtsi64_m64(INT64_C(-8279962275226206621)),
      simde_mm_cvtsi64_m64(INT64_C(-2814925648380381958)),
      simde_mm_set_epi64x(INT64_C(-2814925648380381958), INT64_C(-8279962275226206621)) },
    { simde_mm_cvtsi64_m64(INT64_C( 6755033167475904984)),
      simde_mm_cvtsi64_m64(INT64_C(-8685825248847164354)),
      simde_mm_set_epi64x(INT64_C(-8685825248847164354), INT64_C( 6755033167475904984)) },
    { simde_mm_cvtsi64_m64(INT64_C( 1859833649283237251)),
      simde_mm_cvtsi64_m64(INT64_C( 4744285272371342192)),
      simde_mm_set_epi64x(INT64_C( 4744285272371342192), INT64_C( 1859833649283237251)) },
    { simde_mm_cvtsi64_m64(INT64_C(-2932310525767688549)),
      simde_mm_cvtsi64_m64(INT64_C(-5821145293930307405)),
      simde_mm_set_epi64x(INT64_C(-5821145293930307405), INT64_C(-2932310525767688549)) },
    { simde_mm_cvtsi64_m64(INT64_C( 6748921357249852483)),
      simde_mm_cvtsi64_m64(INT64_C(-4633625703225321444)),
      simde_mm_set_epi64x(INT64_C(-4633625703225321444), INT64_C( 6748921357249852483)) },
  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
  //   simde__m64_private a, b;
  //   simde__m128i_private r;

  //   munit_rand_memory(sizeof(a), (uint8_t*) &a);
  //   munit_rand_memory(sizeof(b), (uint8_t*) &b);

  //   r = simde__m128i_to_private(simde_mm_setr_epi64(simde__m64_from_private(a), simde__m64_from_private(b)));

  //   printf("    { simde_mm_cvtsi64_m64(INT64_C(%20" PRId64 ")),\n", a.i64[0]);
  //   printf("      simde_mm_cvtsi64_m64(INT64_C(%20" PRId64 ")),\n", b.i64[0]);
  //   printf("      simde_mm_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n", r.i64[1], r.i64[0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_setr_epi64(test_vec[i].e1, test_vec[i].e0);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_setzero_pd(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128d a = simde_mm_set1_pd(0);
  simde__m128d r = simde_mm_setzero_pd();

  simde_assert_m128d_equal(a, r);

  return 0;
}

static int
test_simde_mm_setzero_si128(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i a = simde_mm_set1_epi32(0);
  simde__m128i r = simde_mm_setzero_si128();

  simde_assert_m128i_i32(a, ==, r);

  return 0;
}

static int
test_simde_mm_shuffle_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -749480461), INT32_C(-1872761030), INT32_C( 1690143325), INT32_C( -258848374)),
      simde_mm_set_epi32(INT32_C(-1872761030), INT32_C(-1872761030), INT32_C(-1872761030), INT32_C(-1872761030)) },
    { simde_mm_set_epi32(INT32_C( 1030695986), INT32_C( 1932252260), INT32_C( 1962976759), INT32_C(-1621624916)),
      simde_mm_set_epi32(INT32_C( 1932252260), INT32_C( 1932252260), INT32_C( 1932252260), INT32_C( 1932252260)) },
    { simde_mm_set_epi32(INT32_C( -897180326), INT32_C( 1675136548), INT32_C( 1746269378), INT32_C( 1984702409)),
      simde_mm_set_epi32(INT32_C( 1675136548), INT32_C( 1675136548), INT32_C( 1675136548), INT32_C( 1675136548)) },
    { simde_mm_set_epi32(INT32_C(  -11612835), INT32_C(-1878653813), INT32_C(-2135957543), INT32_C( -134555953)),
      simde_mm_set_epi32(INT32_C(-1878653813), INT32_C(-1878653813), INT32_C(-1878653813), INT32_C(-1878653813)) },
    { simde_mm_set_epi32(INT32_C( 1051337342), INT32_C(  755742115), INT32_C(  338927136), INT32_C( 1410014436)),
      simde_mm_set_epi32(INT32_C(  755742115), INT32_C(  755742115), INT32_C(  755742115), INT32_C(  755742115)) },
    { simde_mm_set_epi32(INT32_C(-1826960183), INT32_C( -119444047), INT32_C(-1224980361), INT32_C( 1323381864)),
      simde_mm_set_epi32(INT32_C( -119444047), INT32_C( -119444047), INT32_C( -119444047), INT32_C( -119444047)) },
    { simde_mm_set_epi32(INT32_C( 1256541920), INT32_C( 1446192699), INT32_C( -117794523), INT32_C(-1904270778)),
      simde_mm_set_epi32(INT32_C( 1446192699), INT32_C( 1446192699), INT32_C( 1446192699), INT32_C( 1446192699)) },
    { simde_mm_set_epi32(INT32_C(  542509546), INT32_C(-1970305999), INT32_C(-1492486994), INT32_C( 1078541043)),
      simde_mm_set_epi32(INT32_C(-1970305999), INT32_C(-1970305999), INT32_C(-1970305999), INT32_C(-1970305999)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_shuffle_epi32(test_vec[i].a, 0xaa);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_setr_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    double e1;
    double e0;
    simde__m128d r;
  } test_vec[8] = {
    {     0.74,     0.57,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.57), SIMDE_FLOAT64_C(    0.74)) },
    {     0.52,     0.66,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.52)) },
    {     0.54,     0.56,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.56), SIMDE_FLOAT64_C(    0.54)) },
    {     0.95,     0.43,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.43), SIMDE_FLOAT64_C(    0.95)) },
    {     0.53,     0.46,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.46), SIMDE_FLOAT64_C(    0.53)) },
    {     0.33,     0.39,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(    0.33)) },
    {     0.48,     0.63,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.63), SIMDE_FLOAT64_C(    0.48)) },
    {     0.08,     0.44,
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(    0.08)) },
  };

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   double e1 = munit_rand_double();
  //   double e0 = munit_rand_double();
  //   simde__m128d_private r;

  //   r = simde__m128d_to_private(simde_mm_setr_pd(e1, e0));

  //   printf("    { %*.2f, %*.2f,\n", 8, e1 , 8, e0);
  //   printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_setr_pd(test_vec[i].e1, test_vec[i].e0);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_shuffle_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  897.05), SIMDE_FLOAT64_C(  524.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -346.39), SIMDE_FLOAT64_C( -595.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -595.93), SIMDE_FLOAT64_C(  524.15)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -684.88), SIMDE_FLOAT64_C(   62.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  765.70), SIMDE_FLOAT64_C( -126.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -126.52), SIMDE_FLOAT64_C(   62.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -871.69), SIMDE_FLOAT64_C( -753.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -923.31), SIMDE_FLOAT64_C( -103.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -103.97), SIMDE_FLOAT64_C( -753.55)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -377.03), SIMDE_FLOAT64_C(  701.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -672.47), SIMDE_FLOAT64_C( -328.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -328.63), SIMDE_FLOAT64_C(  701.23)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  238.70), SIMDE_FLOAT64_C(  837.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -429.19), SIMDE_FLOAT64_C(  106.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  106.67), SIMDE_FLOAT64_C(  837.56)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  571.83), SIMDE_FLOAT64_C( -389.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  447.48), SIMDE_FLOAT64_C(   -8.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -8.02), SIMDE_FLOAT64_C( -389.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -214.27), SIMDE_FLOAT64_C(  549.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -967.02), SIMDE_FLOAT64_C( -162.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -162.29), SIMDE_FLOAT64_C(  549.07)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -528.33), SIMDE_FLOAT64_C(  376.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -959.95), SIMDE_FLOAT64_C( -855.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -855.93), SIMDE_FLOAT64_C(  376.34)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_shuffle_pd(test_vec[i].a, test_vec[i].b, 0);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_shufflehi_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  3588), INT16_C(-23598), INT16_C( -2669), INT16_C( -7880),
                         INT16_C( 20391), INT16_C( 13327), INT16_C( 18868), INT16_C( 31239)),
      simde_mm_set_epi16(INT16_C(  3588), INT16_C(  3588), INT16_C( -2669), INT16_C( -2669),
                         INT16_C( 20391), INT16_C( 13327), INT16_C( 18868), INT16_C( 31239)) },
    { simde_mm_set_epi16(INT16_C(  5701), INT16_C( 15357), INT16_C( 27973), INT16_C(-26447),
                         INT16_C(-18797), INT16_C(-27249), INT16_C( -9707), INT16_C( -1950)),
      simde_mm_set_epi16(INT16_C(  5701), INT16_C(  5701), INT16_C( 27973), INT16_C( 27973),
                         INT16_C(-18797), INT16_C(-27249), INT16_C( -9707), INT16_C( -1950)) },
    { simde_mm_set_epi16(INT16_C(-14544), INT16_C( 26887), INT16_C( -7591), INT16_C( 22567),
                         INT16_C( -8366), INT16_C(-11381), INT16_C(  1736), INT16_C(-23069)),
      simde_mm_set_epi16(INT16_C(-14544), INT16_C(-14544), INT16_C( -7591), INT16_C( -7591),
                         INT16_C( -8366), INT16_C(-11381), INT16_C(  1736), INT16_C(-23069)) },
    { simde_mm_set_epi16(INT16_C( 31637), INT16_C( 12965), INT16_C(-23234), INT16_C(-12784),
                         INT16_C(   364), INT16_C(  7338), INT16_C( 16998), INT16_C(-14384)),
      simde_mm_set_epi16(INT16_C( 31637), INT16_C( 31637), INT16_C(-23234), INT16_C(-23234),
                         INT16_C(   364), INT16_C(  7338), INT16_C( 16998), INT16_C(-14384)) },
    { simde_mm_set_epi16(INT16_C( 20104), INT16_C(-31033), INT16_C( 12782), INT16_C( -8281),
                         INT16_C( 17249), INT16_C( -1757), INT16_C(-22510), INT16_C(-23902)),
      simde_mm_set_epi16(INT16_C( 20104), INT16_C( 20104), INT16_C( 12782), INT16_C( 12782),
                         INT16_C( 17249), INT16_C( -1757), INT16_C(-22510), INT16_C(-23902)) },
    { simde_mm_set_epi16(INT16_C( 28403), INT16_C(-26721), INT16_C( -6834), INT16_C(-28104),
                         INT16_C( -6404), INT16_C( -5723), INT16_C(-30154), INT16_C( -4442)),
      simde_mm_set_epi16(INT16_C( 28403), INT16_C( 28403), INT16_C( -6834), INT16_C( -6834),
                         INT16_C( -6404), INT16_C( -5723), INT16_C(-30154), INT16_C( -4442)) },
    { simde_mm_set_epi16(INT16_C( 18671), INT16_C( -6207), INT16_C( 14078), INT16_C(-30976),
                         INT16_C(-25644), INT16_C(-24126), INT16_C( 10939), INT16_C(-13801)),
      simde_mm_set_epi16(INT16_C( 18671), INT16_C( 18671), INT16_C( 14078), INT16_C( 14078),
                         INT16_C(-25644), INT16_C(-24126), INT16_C( 10939), INT16_C(-13801)) },
    { simde_mm_set_epi16(INT16_C(-28546), INT16_C( 12696), INT16_C(-10401), INT16_C( -8517),
                         INT16_C( 29702), INT16_C(-10694), INT16_C( 25940), INT16_C( 28112)),
      simde_mm_set_epi16(INT16_C(-28546), INT16_C(-28546), INT16_C(-10401), INT16_C(-10401),
                         INT16_C( 29702), INT16_C(-10694), INT16_C( 25940), INT16_C( 28112)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_shufflehi_epi16(test_vec[i].a, 245);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_shufflelo_epi16(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i a, r, e;

  a = simde_mm_set_epi16(INT16_C(-24821), INT16_C(-30256), INT16_C(  8570), INT16_C( 11360),
                          INT16_C(-20759), INT16_C(-23279), INT16_C(  9158), INT16_C( -6205));
  e = simde_mm_set_epi16(INT16_C(-24821), INT16_C(-30256), INT16_C(  8570), INT16_C( 11360),
                          INT16_C( -6205), INT16_C(-23279), INT16_C(  9158), INT16_C(-20759));
  r = simde_mm_shufflelo_epi16(a,  39);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C(-26644), INT16_C( -8695), INT16_C( -9741), INT16_C(-14158),
                          INT16_C( -3323), INT16_C(  7181), INT16_C( 10186), INT16_C(-16906));
  e = simde_mm_set_epi16(INT16_C(-26644), INT16_C( -8695), INT16_C( -9741), INT16_C(-14158),
                          INT16_C(  7181), INT16_C(-16906), INT16_C( 10186), INT16_C( -3323));
  r = simde_mm_shufflelo_epi16(a, 135);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C(-20225), INT16_C( 19920), INT16_C( -3607), INT16_C( 11889),
                          INT16_C( 12271), INT16_C(-20589), INT16_C( 17338), INT16_C( -7507));
  e = simde_mm_set_epi16(INT16_C(-20225), INT16_C( 19920), INT16_C( -3607), INT16_C( 11889),
                          INT16_C( 12271), INT16_C( 17338), INT16_C( 12271), INT16_C( -7507));
  r = simde_mm_shufflelo_epi16(a, 220);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C( -8042), INT16_C(-18261), INT16_C( 20990), INT16_C(-18752),
                          INT16_C( 26566), INT16_C(-27202), INT16_C( -3939), INT16_C( -1274));
  e = simde_mm_set_epi16(INT16_C( -8042), INT16_C(-18261), INT16_C( 20990), INT16_C(-18752),
                          INT16_C( -3939), INT16_C( 26566), INT16_C( -3939), INT16_C( -1274));
  r = simde_mm_shufflelo_epi16(a, 116);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C(  5383), INT16_C(-27918), INT16_C( 16559), INT16_C(-31608),
                          INT16_C(  6504), INT16_C(-11225), INT16_C(-13396), INT16_C( 20261));
  e = simde_mm_set_epi16(INT16_C(  5383), INT16_C(-27918), INT16_C( 16559), INT16_C(-31608),
                          INT16_C(-13396), INT16_C(-13396), INT16_C(-13396), INT16_C(-13396));
  r = simde_mm_shufflelo_epi16(a,  85);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C( -8905), INT16_C( 30480), INT16_C( 20250), INT16_C(    30),
                          INT16_C( 24188), INT16_C( 21861), INT16_C( -9955), INT16_C(  6282));
  e = simde_mm_set_epi16(INT16_C( -8905), INT16_C( 30480), INT16_C( 20250), INT16_C(    30),
                          INT16_C(  6282), INT16_C( 24188), INT16_C( 21861), INT16_C( 21861));
  r = simde_mm_shufflelo_epi16(a,  58);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C(  7654), INT16_C(  4685), INT16_C( 25749), INT16_C(-30088),
                          INT16_C( -7783), INT16_C( 10182), INT16_C( 23640), INT16_C(  4937));
  e = simde_mm_set_epi16(INT16_C(  7654), INT16_C(  4685), INT16_C( 25749), INT16_C(-30088),
                          INT16_C( -7783), INT16_C(  4937), INT16_C( 23640), INT16_C(  4937));
  r = simde_mm_shufflelo_epi16(a, 196);
  simde_assert_m128i_i16(r, ==, e);

  a = simde_mm_set_epi16(INT16_C(-26752), INT16_C(  9125), INT16_C(-14825), INT16_C( 13732),
                          INT16_C( 15859), INT16_C(-32053), INT16_C(-12419), INT16_C( 17722));
  e = simde_mm_set_epi16(INT16_C(-26752), INT16_C(  9125), INT16_C(-14825), INT16_C( 13732),
                          INT16_C( 15859), INT16_C( 17722), INT16_C(-12419), INT16_C(-32053));
  r = simde_mm_shufflelo_epi16(a, 198);
  simde_assert_m128i_i16(r, ==, e);

  return 0;
}

static int
test_simde_mm_sra_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 28258), INT16_C(  1159), INT16_C( 20634), INT16_C(-30158),
                         INT16_C( 10049), INT16_C(-31721), INT16_C(-26691), INT16_C(-28181)),
      simde_mm_set_epi16(INT16_C(    11), INT16_C(     6), INT16_C(    10), INT16_C(     8),
                         INT16_C(    15), INT16_C(     3), INT16_C(     8), INT16_C(     1)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C(-25682), INT16_C(  7964), INT16_C(  1259), INT16_C( 18017),
                         INT16_C( 10765), INT16_C(-10649), INT16_C( -9400), INT16_C( 12110)),
      simde_mm_set_epi16(INT16_C(     3), INT16_C(     8), INT16_C(     3), INT16_C(     2),
                         INT16_C(    10), INT16_C(     5), INT16_C(     2), INT16_C(     2)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C(-24685), INT16_C( 14370), INT16_C( 13079), INT16_C( -6409),
                         INT16_C(-18776), INT16_C( 20941), INT16_C( 22692), INT16_C(   312)),
      simde_mm_set_epi16(INT16_C(    13), INT16_C(    13), INT16_C(     0), INT16_C(     7),
                         INT16_C(     4), INT16_C(    10), INT16_C(    15), INT16_C(    11)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( 13442), INT16_C(-32489), INT16_C(-21378), INT16_C( 10156),
                         INT16_C( 15393), INT16_C( 20131), INT16_C( 15138), INT16_C(-12589)),
      simde_mm_set_epi16(INT16_C(     1), INT16_C(     3), INT16_C(     1), INT16_C(     8),
                         INT16_C(    12), INT16_C(     3), INT16_C(     4), INT16_C(     2)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( -9561), INT16_C( 25554), INT16_C( -5305), INT16_C( -7173),
                         INT16_C(-10064), INT16_C( 31075), INT16_C( 30218), INT16_C(-18929)),
      simde_mm_set_epi16(INT16_C(     5), INT16_C(    10), INT16_C(     8), INT16_C(     1),
                         INT16_C(    12), INT16_C(     3), INT16_C(    10), INT16_C(    10)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( 14091), INT16_C( 24202), INT16_C( -8543), INT16_C( -7482),
                         INT16_C(-26143), INT16_C( 20277), INT16_C(-27984), INT16_C(-32658)),
      simde_mm_set_epi16(INT16_C(     5), INT16_C(     7), INT16_C(     6), INT16_C(     6),
                         INT16_C(    10), INT16_C(     3), INT16_C(     7), INT16_C(    11)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C(-19726), INT16_C( 12311), INT16_C( 16279), INT16_C( -6277),
                         INT16_C( 19874), INT16_C(-27089), INT16_C( 14524), INT16_C(-14305)),
      simde_mm_set_epi16(INT16_C(     7), INT16_C(     7), INT16_C(     3), INT16_C(     1),
                         INT16_C(    12), INT16_C(     1), INT16_C(    10), INT16_C(     9)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( 19801), INT16_C(-12786), INT16_C( 31632), INT16_C( 19030),
                         INT16_C(-19420), INT16_C(-12406), INT16_C( 12426), INT16_C( 27612)),
      simde_mm_set_epi16(INT16_C(     2), INT16_C(     0), INT16_C(    10), INT16_C(     3),
                         INT16_C(     9), INT16_C(     0), INT16_C(     1), INT16_C(     8)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sra_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sll_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[] = {
    { simde_mm_set_epi16(INT16_C(-11777), INT16_C( 26803), INT16_C(-29366), INT16_C(-28135),
                         INT16_C( 26578), INT16_C(-22566), INT16_C(-18521), INT16_C( -1087)),
      simde_mm_set_epi64x(INT64_C(-1766274549416496901), ~INT64_C(0)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( 20694), INT16_C(-29451), INT16_C(-14684), INT16_C( 26977),
                         INT16_C(  9617), INT16_C(  4798), INT16_C(  6081), INT16_C( 26243)),
      simde_mm_set_epi64x(INT64_C(4317315664183993059), INT64_C(                  0)),
      simde_mm_set_epi16(INT16_C( 20694), INT16_C(-29451), INT16_C(-14684), INT16_C( 26977),
                         INT16_C(  9617), INT16_C(  4798), INT16_C(  6081), INT16_C( 26243)) },
    { simde_mm_set_epi16(INT16_C(-19602), INT16_C(-30869), INT16_C( -4506), INT16_C(  7721),
                         INT16_C( 10990), INT16_C(-12116), INT16_C( 29998), INT16_C(  -194)),
      simde_mm_set_epi64x(INT64_C(5323917981768999693), INT64_C(                  1)),
      simde_mm_set_epi16(INT16_C( 26332), INT16_C(  3798), INT16_C( -9012), INT16_C( 15442),
                         INT16_C( 21980), INT16_C(-24232), INT16_C( -5540), INT16_C(  -388)) },
    { simde_mm_set_epi16(INT16_C( -7669), INT16_C(-27334), INT16_C( 24496), INT16_C( 27065),
                         INT16_C( 13859), INT16_C(  2295), INT16_C( 31737), INT16_C( -2884)),
      simde_mm_set_epi64x(INT64_C(4743197663988711830), INT64_C(                  2)),
      simde_mm_set_epi16(INT16_C(-30676), INT16_C( 21736), INT16_C( 32448), INT16_C(-22812),
                         INT16_C(-10100), INT16_C(  9180), INT16_C( -4124), INT16_C(-11536)) },
    { simde_mm_set_epi16(INT16_C( -8360), INT16_C( 29662), INT16_C(  6226), INT16_C( 10396),
                         INT16_C(-32749), INT16_C( 20802), INT16_C( 12391), INT16_C(  4472)),
      simde_mm_set_epi64x(INT64_C(-4440768506472940517), INT64_C(                  3)),
      simde_mm_set_epi16(INT16_C( -1344), INT16_C(-24848), INT16_C(-15728), INT16_C( 17632),
                         INT16_C(   152), INT16_C(-30192), INT16_C(-31944), INT16_C(-29760)) },
    { simde_mm_set_epi16(INT16_C( 26979), INT16_C(  -773), INT16_C( 29656), INT16_C( 12973),
                         INT16_C(-28581), INT16_C( -1290), INT16_C( 25294), INT16_C(  -882)),
      simde_mm_set_epi64x(INT64_C(-8434753600973098893), INT64_C(                  4)),
      simde_mm_set_epi16(INT16_C(-27088), INT16_C(-12368), INT16_C( 15744), INT16_C( 10960),
                         INT16_C(  1456), INT16_C(-20640), INT16_C( 11488), INT16_C(-14112)) },
    { simde_mm_set_epi16(INT16_C(-20013), INT16_C( 14301), INT16_C(-17775), INT16_C(-12493),
                         INT16_C(-22187), INT16_C( -2203), INT16_C( 22935), INT16_C( -5230)),
      simde_mm_set_epi64x(INT64_C(-718166367052449426), INT64_C(                 13)),
      simde_mm_set_epi16(INT16_C( 24576), INT16_C(-24576), INT16_C(  8192), INT16_C( 24576),
                         INT16_C(-24576), INT16_C(-24576), INT16_C( -8192), INT16_C( 16384)) },
    { simde_mm_set_epi16(INT16_C( -9377), INT16_C(-13109), INT16_C(  2614), INT16_C(-17099),
                         INT16_C(-13260), INT16_C( 21790), INT16_C(  8183), INT16_C( 12820)),
      simde_mm_set_epi64x(INT64_C(-3082182550035776352), INT64_C(                 14)),
      simde_mm_set_epi16(INT16_C(-16384), INT16_C(-16384), INT16_C(-32768), INT16_C( 16384),
                         INT16_C(     0), INT16_C(-32768), INT16_C(-16384), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( 21339), INT16_C(-22944), INT16_C( 30792), INT16_C(-23288),
                         INT16_C(-13340), INT16_C(  7657), INT16_C(  8339), INT16_C( 10093)),
      simde_mm_set_epi64x(INT64_C(-8360903661682410487), INT64_C(                 15)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi16(INT16_C(-12198), INT16_C(  1510), INT16_C( -3241), INT16_C(-10552),
                         INT16_C(-10041), INT16_C( 23083), INT16_C( 11931), INT16_C( 10037)),
      simde_mm_set_epi64x(INT64_C(7382630779200792207), INT64_C(                 16)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { simde_mm_set_epi16(INT16_C( -4565), INT16_C(-19321), INT16_C( 29437), INT16_C( -8916),
                         INT16_C( 18870), INT16_C(-29403), INT16_C(   667), INT16_C(-22848)),
      simde_mm_set_epi64x(INT64_C(   7403670930710815), INT64_C(                 17)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sll_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sll_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[50] = {
    { simde_mm_set_epi32(INT32_C( 1847585989), INT32_C( -535718080), INT32_C(-1279093253), INT32_C(  656800013)),
      simde_x_mm_set_epu64x(UINT64_C( 2450913859380011969), UINT64_C(18446744073709551615)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(  894927109), INT32_C(  930856884), INT32_C(  350764320), INT32_C(  435252602)),
      simde_x_mm_set_epu64x(UINT64_C( 4964670149549210828), UINT64_C(                   0)),
      simde_mm_set_epi32(INT32_C(  894927109), INT32_C(  930856884), INT32_C(  350764320), INT32_C(  435252602)) },
    { simde_mm_set_epi32(INT32_C( -264520264), INT32_C( 2022498436), INT32_C(-1437067245), INT32_C(  482847980)),
      simde_x_mm_set_epu64x(UINT64_C( 7326459959939805716), UINT64_C(                   1)),
      simde_mm_set_epi32(INT32_C( -529040528), INT32_C( -249970424), INT32_C( 1420832806), INT32_C(  965695960)) },
    { simde_mm_set_epi32(INT32_C(  -73269821), INT32_C(-1137239147), INT32_C(  168132057), INT32_C( -131743227)),
      simde_x_mm_set_epu64x(UINT64_C( 1477135654656320870), UINT64_C(                   2)),
      simde_mm_set_epi32(INT32_C( -293079284), INT32_C( -253989292), INT32_C(  672528228), INT32_C( -526972908)) },
    { simde_mm_set_epi32(INT32_C(  676475770), INT32_C(  743649739), INT32_C( 1613393787), INT32_C(  257685631)),
      simde_x_mm_set_epu64x(UINT64_C(14989079754060836033), UINT64_C(                   3)),
      simde_mm_set_epi32(INT32_C( 1116838864), INT32_C( 1654230616), INT32_C(   22248408), INT32_C( 2061485048)) },
    { simde_mm_set_epi32(INT32_C( 1293905571), INT32_C(-1134008712), INT32_C(-1835354706), INT32_C( -173430307)),
      simde_x_mm_set_epu64x(UINT64_C(15716033284919086785), UINT64_C(                  29)),
      simde_mm_set_epi32(INT32_C( 1610612736), INT32_C(          0), INT32_C(-1073741824), INT32_C(-1610612736)) },
    { simde_mm_set_epi32(INT32_C(-1608827194), INT32_C( -758406839), INT32_C(-1895836042), INT32_C(-1122971027)),
      simde_x_mm_set_epu64x(UINT64_C(  240001894519477005), UINT64_C(                  30)),
      simde_mm_set_epi32(          INT32_MIN , INT32_C( 1073741824),           INT32_MIN , INT32_C( 1073741824)) },
    { simde_mm_set_epi32(INT32_C( 1629035853), INT32_C(  172553194), INT32_C(  533866060), INT32_C(  504662481)),
      simde_x_mm_set_epu64x(UINT64_C(16117634661514065169), UINT64_C(                  31)),
      simde_mm_set_epi32(          INT32_MIN , INT32_C(          0), INT32_C(          0),           INT32_MIN ) },
    { simde_mm_set_epi32(INT32_C(-1841013582), INT32_C(-1759681954), INT32_C(-1933278842), INT32_C( 1138123852)),
      simde_x_mm_set_epu64x(UINT64_C(16122278597987411920), UINT64_C(                  32)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C( 1016164793), INT32_C(  934378122), INT32_C( 1851284098), INT32_C(  118468072)),
      simde_x_mm_set_epu64x(UINT64_C( 9847102169886565139), UINT64_C(                  33)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sll_epi32(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sll_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C( 8055788268748421105), INT64_C(-9066834056558614160)),
      simde_mm_set_epi64x(INT64_C(-5262793264663215472), INT64_C(16)),
      simde_mm_set_epi64x(INT64_C(-1675408870841712640), INT64_C( 2483371706739064832)) },
    { simde_mm_set_epi64x(INT64_C( 2441732847819780871), INT64_C( -124127278813603777)),
      simde_mm_set_epi64x(INT64_C(-8018169735231443299), INT64_C( 1)),
      simde_mm_set_epi64x(INT64_C( 4883465695639561742), INT64_C( -248254557627207554)) },
    { simde_mm_set_epi64x(INT64_C(-2211386688605493428), INT64_C( -350563182553241755)),
      simde_mm_set_epi64x(INT64_C( 1150552132815785095), INT64_C(12)),
      simde_mm_set_epi64x(INT64_C( -488536336711237632), INT64_C( 2939242011266797568)) },
    { simde_mm_set_epi64x(INT64_C( 2987527187015640759), INT64_C(  638426944527652749)),
      simde_mm_set_epi64x(INT64_C(-1714103729784977145), INT64_C( 5)),
      simde_mm_set_epi64x(INT64_C( 3367149615952746208), INT64_C( 1982918151175336352)) },
    { simde_mm_set_epi64x(INT64_C( 4972525455608644218), INT64_C( 6137457836149854777)),
      simde_mm_set_epi64x(INT64_C(-8922909725876665702), INT64_C( 2)),
      simde_mm_set_epi64x(INT64_C( 1443357748725025256), INT64_C( 6103087270889867492)) },
    { simde_mm_set_epi64x(INT64_C(-6484089245702098359), INT64_C(  413459708861121590)),
      simde_mm_set_epi64x(INT64_C( 7011241116916112587), INT64_C(15)),
      simde_mm_set_epi64x(INT64_C(-1038162179743514624), INT64_C( 8337589858421374976)) },
    { simde_mm_set_epi64x(INT64_C(-1797418312522800237), INT64_C( 3481510514608785630)),
      simde_mm_set_epi64x(INT64_C( 4951339001913100627), INT64_C(13)),
      simde_mm_set_epi64x(INT64_C(-3949045366557351936), INT64_C( 1867797720205082624)) },
    { simde_mm_set_epi64x(INT64_C( 7626804351806608498), INT64_C(-4244380112569402483)),
      simde_mm_set_epi64x(INT64_C( 1577848631857250403), INT64_C( 4)),
      simde_mm_set_epi64x(INT64_C(-7098338887061125344), INT64_C( 5876894493727766736)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sll_epi64(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sqrt_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   481.04), SIMDE_FLOAT64_C(   845.64) },
      { SIMDE_FLOAT64_C(    21.93), SIMDE_FLOAT64_C(    29.08) } },
    { { SIMDE_FLOAT64_C(   520.60), SIMDE_FLOAT64_C(   759.12) },
      { SIMDE_FLOAT64_C(    22.82), SIMDE_FLOAT64_C(    27.55) } },
    { { SIMDE_FLOAT64_C(    35.64), SIMDE_FLOAT64_C(   486.89) },
      { SIMDE_FLOAT64_C(     5.97), SIMDE_FLOAT64_C(    22.07) } },
    { { SIMDE_FLOAT64_C(   -79.78), SIMDE_FLOAT64_C(   723.70) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    26.90) } },
    { { SIMDE_FLOAT64_C(   719.24), SIMDE_FLOAT64_C(   373.08) },
      { SIMDE_FLOAT64_C(    26.82), SIMDE_FLOAT64_C(    19.32) } },
    { { SIMDE_FLOAT64_C(   497.67), SIMDE_FLOAT64_C(   489.69) },
      { SIMDE_FLOAT64_C(    22.31), SIMDE_FLOAT64_C(    22.13) } },
    { { SIMDE_FLOAT64_C(   925.51), SIMDE_FLOAT64_C(   932.27) },
      { SIMDE_FLOAT64_C(    30.42), SIMDE_FLOAT64_C(    30.53) } },
    { { SIMDE_FLOAT64_C(   -49.82), SIMDE_FLOAT64_C(   705.12) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    26.55) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d r = simde_mm_sqrt_pd(a);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_sqrt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    1.82), SIMDE_FLOAT64_C(  868.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  180.11), SIMDE_FLOAT64_C(  621.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.82), SIMDE_FLOAT64_C(   24.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  458.20), SIMDE_FLOAT64_C(  211.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  430.02), SIMDE_FLOAT64_C(  152.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  458.20), SIMDE_FLOAT64_C(   12.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(  272.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.78), SIMDE_FLOAT64_C(  929.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(   30.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  103.00), SIMDE_FLOAT64_C(   65.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  542.46), SIMDE_FLOAT64_C(  784.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  103.00), SIMDE_FLOAT64_C(   28.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  373.53), SIMDE_FLOAT64_C(  698.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  142.54), SIMDE_FLOAT64_C(  348.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  373.53), SIMDE_FLOAT64_C(   18.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  528.07), SIMDE_FLOAT64_C(  477.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  384.87), SIMDE_FLOAT64_C(  433.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  528.07), SIMDE_FLOAT64_C(   20.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  241.09), SIMDE_FLOAT64_C(  679.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  322.35), SIMDE_FLOAT64_C(  620.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  241.09), SIMDE_FLOAT64_C(   24.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  651.18), SIMDE_FLOAT64_C(  446.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  886.36), SIMDE_FLOAT64_C(  269.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  651.18), SIMDE_FLOAT64_C(   16.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sqrt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_srl_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  1445), INT16_C( 14472), INT16_C(-18508), INT16_C( -4645),
                         INT16_C(-24581), INT16_C(-12656), INT16_C(  1275), INT16_C(-25245)),
      simde_mm_set_epi64x(INT64_C( 4678230141678036905), INT64_C( 4)),
      simde_mm_set_epi16(INT16_C(    90), INT16_C(   904), INT16_C(  2939), INT16_C(  3805),
                         INT16_C(  2559), INT16_C(  3305), INT16_C(    79), INT16_C(  2518)) },
    { simde_mm_set_epi16(INT16_C(   986), INT16_C( 31796), INT16_C(-12770), INT16_C(-28401),
                         INT16_C( 15186), INT16_C(-17595), INT16_C( 31992), INT16_C( 19329)),
      simde_mm_set_epi64x(INT64_C(  234386534661459961), INT64_C( 2)),
      simde_mm_set_epi16(INT16_C(   246), INT16_C(  7949), INT16_C( 13191), INT16_C(  9283),
                         INT16_C(  3796), INT16_C( 11985), INT16_C(  7998), INT16_C(  4832)) },
    { simde_mm_set_epi16(INT16_C(-23898), INT16_C(  7158), INT16_C( 21829), INT16_C(-16536),
                         INT16_C(  2052), INT16_C( -6635), INT16_C( 18408), INT16_C( -3755)),
      simde_mm_set_epi64x(INT64_C( 8276161762185938564), INT64_C( 7)),
      simde_mm_set_epi16(INT16_C(   325), INT16_C(    55), INT16_C(   170), INT16_C(   382),
                         INT16_C(    16), INT16_C(   460), INT16_C(   143), INT16_C(   482)) },
    { simde_mm_set_epi16(INT16_C(-19513), INT16_C(-10508), INT16_C(-12500), INT16_C( 22379),
                         INT16_C(  4775), INT16_C(  8063), INT16_C(  8132), INT16_C(  7840)),
      simde_mm_set_epi64x(INT64_C( 1101003055866698034), INT64_C( 6)),
      simde_mm_set_epi16(INT16_C(   719), INT16_C(   859), INT16_C(   828), INT16_C(   349),
                         INT16_C(    74), INT16_C(   125), INT16_C(   127), INT16_C(   122)) },
    { simde_mm_set_epi16(INT16_C(  9942), INT16_C( 29561), INT16_C( -4121), INT16_C(-26882),
                         INT16_C(-17939), INT16_C( 13186), INT16_C(  6796), INT16_C( 14206)),
      simde_mm_set_epi64x(INT64_C(  735258903315099979), INT64_C( 1)),
      simde_mm_set_epi16(INT16_C(  4971), INT16_C( 14780), INT16_C( 30707), INT16_C( 19327),
                         INT16_C( 23798), INT16_C(  6593), INT16_C(  3398), INT16_C(  7103)) },
    { simde_mm_set_epi16(INT16_C(  5648), INT16_C(-13469), INT16_C(-23201), INT16_C(  7029),
                         INT16_C(-28211), INT16_C(-14496), INT16_C( 31202), INT16_C(-32095)),
      simde_mm_set_epi64x(INT64_C( 4870695400140482879), INT64_C(13)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     6), INT16_C(     5), INT16_C(     0),
                         INT16_C(     4), INT16_C(     6), INT16_C(     3), INT16_C(     4)) },
    { simde_mm_set_epi16(INT16_C( 11526), INT16_C( 20336), INT16_C( 18003), INT16_C( 21727),
                         INT16_C(-28471), INT16_C(-32732), INT16_C(-25472), INT16_C( 12636)),
      simde_mm_set_epi64x(INT64_C(-6737308052137237000), INT64_C( 3)),
      simde_mm_set_epi16(INT16_C(  1440), INT16_C(  2542), INT16_C(  2250), INT16_C(  2715),
                         INT16_C(  4633), INT16_C(  4100), INT16_C(  5008), INT16_C(  1579)) },
    { simde_mm_set_epi16(INT16_C(-30386), INT16_C( -2761), INT16_C( 11467), INT16_C(  9929),
                         INT16_C(-19380), INT16_C(-12818), INT16_C( -4584), INT16_C( -6145)),
      simde_mm_set_epi64x(INT64_C(-2450775638354168945), INT64_C( 3)),
      simde_mm_set_epi16(INT16_C(  4393), INT16_C(  7846), INT16_C(  1433), INT16_C(  1241),
                         INT16_C(  5769), INT16_C(  6589), INT16_C(  7619), INT16_C(  7423)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srl_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_srl_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(   94713992), INT32_C(-1212879397), INT32_C(-1610887536), INT32_C(   83598691)),
      simde_mm_set_epi64x(INT64_C( 4678230141678036905), INT64_C( 4)),
      simde_mm_set_epi32(INT32_C(    5919624), INT32_C(  192630493), INT32_C(  167754985), INT32_C(    5224918)) },
    { simde_mm_set_epi32(INT32_C(   64650292), INT32_C( -836857585), INT32_C(  995277637), INT32_C( 2096647041)),
      simde_mm_set_epi64x(INT64_C(  234386534661459961), INT64_C( 2)),
      simde_mm_set_epi32(INT32_C(   16162573), INT32_C(  864527427), INT32_C(  248819409), INT32_C(  524161760)) },
    { simde_mm_set_epi32(INT32_C(-1566172170), INT32_C( 1430634344), INT32_C(  134538773), INT32_C( 1206448469)),
      simde_mm_set_epi64x(INT64_C( 8276161762185938564), INT64_C( 7)),
      simde_mm_set_epi32(INT32_C(   21318711), INT32_C(   11176830), INT32_C(    1051084), INT32_C(    9425378)) },
    { simde_mm_set_epi32(INT32_C(-1278748940), INT32_C( -819177621), INT32_C(  312942463), INT32_C(  532946592)),
      simde_mm_set_epi64x(INT64_C( 1101003055866698034), INT64_C( 6)),
      simde_mm_set_epi32(INT32_C(   47128411), INT32_C(   54309213), INT32_C(    4889725), INT32_C(    8327290)) },
    { simde_mm_set_epi32(INT32_C(  651588473), INT32_C( -270035202), INT32_C(-1175637118), INT32_C(  445396862)),
      simde_mm_set_epi64x(INT64_C(  735258903315099979), INT64_C( 1)),
      simde_mm_set_epi32(INT32_C(  325794236), INT32_C( 2012466047), INT32_C( 1559665089), INT32_C(  222698431)) },
    { simde_mm_set_epi32(INT32_C(  370199395), INT32_C(-1520493707), INT32_C(-1848785056), INT32_C( 2044887713)),
      simde_mm_set_epi64x(INT64_C( 4870695400140482879), INT64_C(13)),
      simde_mm_set_epi32(INT32_C(      45190), INT32_C(     338680), INT32_C(     298606), INT32_C(     249620)) },
    { simde_mm_set_epi32(INT32_C(  755388272), INT32_C( 1179866335), INT32_C(-1865842652), INT32_C(-1669320356)),
      simde_mm_set_epi64x(INT64_C(-6737308052137237000), INT64_C( 3)),
      simde_mm_set_epi32(INT32_C(   94423534), INT32_C(  147483291), INT32_C(  303640580), INT32_C(  328205867)) },
    { simde_mm_set_epi32(INT32_C(-1991314121), INT32_C(  751511241), INT32_C(-1270034962), INT32_C( -300357633)),
      simde_mm_set_epi64x(INT64_C(-2450775638354168945), INT64_C( 3)),
      simde_mm_set_epi32(INT32_C(  287956646), INT32_C(   93938905), INT32_C(  378116541), INT32_C(  499326207)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srl_epi32(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_srl_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(  406793501195693531), INT64_C(-6918709284570423965)),
      simde_mm_set_epi64x(INT64_C( 4678230141678036905), INT64_C( 4)),
      simde_mm_set_epi64x(INT64_C(   25424593824730845), INT64_C(  720502174321195478)) },
    { simde_mm_set_epi64x(INT64_C(  277670893274960143), INT64_C( 4274684903451806593)),
      simde_mm_set_epi64x(INT64_C(  234386534661459961), INT64_C( 2)),
      simde_mm_set_epi64x(INT64_C(   69417723318740035), INT64_C( 1068671225862951648)) },
    { simde_mm_set_epi64x(INT64_C(-6726658248624717976), INT64_C(  577839631285416277)),
      simde_mm_set_epi64x(INT64_C( 8276161762185938564), INT64_C( 7)),
      simde_mm_set_epi64x(INT64_C(   91563170508475262), INT64_C(    4514372119417314)) },
    { simde_mm_set_epi64x(INT64_C(-5492184873618876565), INT64_C( 1344077644647636640)),
      simde_mm_set_epi64x(INT64_C( 1101003055866698034), INT64_C( 6)),
      simde_mm_set_epi64x(INT64_C(  202414987501416797), INT64_C(   21001213197619322)) },
    { simde_mm_set_epi64x(INT64_C( 2798551186010511102), INT64_C(-5049322973328296066)),
      simde_mm_set_epi64x(INT64_C(  735258903315099979), INT64_C( 1)),
      simde_mm_set_epi64x(INT64_C( 1399275593005255551), INT64_C( 6698710550190627775)) },
    { simde_mm_set_epi64x(INT64_C( 1589994297298459509), INT64_C(-7940471350808640863)),
      simde_mm_set_epi64x(INT64_C( 4870695400140482879), INT64_C(13)),
      simde_mm_set_epi64x(INT64_C(     194091100744440), INT64_C(    1282503994494740)) },
    { simde_mm_set_epi64x(INT64_C( 3244367925201818847), INT64_C(-8013733167196262052)),
      simde_mm_set_epi64x(INT64_C(-6737308052137237000), INT64_C( 3)),
      simde_mm_set_epi64x(INT64_C(  405545990650227355), INT64_C( 1304126363314161195)) },
    { simde_mm_set_epi64x(INT64_C(-8552629025006475575), INT64_C(-5454758622571993089)),
      simde_mm_set_epi64x(INT64_C(-2450775638354168945), INT64_C( 3)),
      simde_mm_set_epi64x(INT64_C( 1236764381087884505), INT64_C( 1623998181392194815)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srl_epi64(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sra_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[] = {
    { simde_mm_set_epi32( -561103335,  1276754862,  1749589432,   517536789),
      simde_mm_set_epi64x(0,  3),
      simde_mm_set_epi32(  -70137917,   159594357,   218698679,    64692098) },
    { simde_mm_set_epi32( -159892315, -1509631224, -1642880399,  1227124763),
      simde_mm_set_epi64x(0, 31),
      simde_mm_set_epi32(         -1,          -1,          -1,           0) },
    { simde_mm_set_epi32(-1747665335, -1727232090, -1061986990, -1651964431),
      simde_mm_set_epi64x(0, 21),
      simde_mm_set_epi32(       -834,        -824,        -507,        -788) },
    { simde_mm_set_epi32(  -43034101,  1748997429, -1014034292,  -471404994),
      simde_mm_set_epi64x(0, 23),
      simde_mm_set_epi32(         -6,         208,        -121,         -57) },
    { simde_mm_set_epi32(  663988211,   279391652,   930358665,   693100359),
      simde_mm_set_epi64x(0, 31),
      simde_mm_set_epi32(          0,           0,           0,           0) },
    { simde_mm_set_epi32( 1596760027,  -525985264, -1328341949, -1278585249),
      simde_mm_set_epi64x(0, 30),
      simde_mm_set_epi32(          1,          -1,          -2,          -2) },
    { simde_mm_set_epi32( 2099244913,  -668946691, -1425692748,  1445785661),
      simde_mm_set_epi64x(0, 19),
      simde_mm_set_epi32(       4003,       -1276,       -2720,        2757) },
    { simde_mm_set_epi32( -572539662,  1511976084, -2125946535, -1043884202),
      simde_mm_set_epi64x(0,  4),
      simde_mm_set_epi32(  -35783729,    94498505,  -132871659,   -65242763) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sra_epi32(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_srai_epi16(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i a, e, r;

  a = simde_mm_set_epi16(INT16_C( 11440), INT16_C( 15930), INT16_C( -6862), INT16_C(-12095),
                         INT16_C(  2973), INT16_C(-25395), INT16_C(-12983), INT16_C(-25536));

  e = simde_mm_set_epi16(INT16_C( 11440), INT16_C( 15930), INT16_C( -6862), INT16_C(-12095),
                         INT16_C(  2973), INT16_C(-25395), INT16_C(-12983), INT16_C(-25536));
  r = simde_mm_srai_epi16(a, 0);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1));
  r = simde_mm_srai_epi16(a, 16);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1));
  r = simde_mm_srai_epi16(a, 42);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi16(INT16_C(    89), INT16_C(   124), INT16_C(   -54), INT16_C(   -95),
                         INT16_C(    23), INT16_C(  -199), INT16_C(  -102), INT16_C(  -200));
  r = simde_mm_srai_epi16(a, 7);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi16(INT16_C(     1), INT16_C(     1), INT16_C(    -1), INT16_C(    -2),
                         INT16_C(     0), INT16_C(    -4), INT16_C(    -2), INT16_C(    -4));
  r = simde_mm_srai_epi16(a, 13);
  simde_assert_m128i_i16(r, ==, e);

  #if 0
  e = simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1));
  r = simde_mm_srai_epi16(a, -7);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1));
  r = simde_mm_srai_epi16(a, -42);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1));
  r = simde_mm_srai_epi16(a, 1729);
  simde_assert_m128i_i16(r, ==, e);
  #endif

  return 0;
}

static int
test_simde_mm_srai_epi32(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i a, e, r;

  a = simde_mm_set_epi32(INT32_C(-1377123590), INT32_C( 1981969037), INT32_C( 1025592994), INT32_C( 1213959767));

  e = simde_mm_set_epi32(INT32_C(-1377123590), INT32_C( 1981969037), INT32_C( 1025592994), INT32_C( 1213959767));
  r = simde_mm_srai_epi32(a, 0);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0));
  r = simde_mm_srai_epi32(a, 32);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0));
  r = simde_mm_srai_epi32(a, 42);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi32(INT32_C(  -10758779), INT32_C(   15484133), INT32_C(    8012445), INT32_C(    9484060));
  r = simde_mm_srai_epi32(a, 7);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi32(INT32_C(    -168106), INT32_C(     241939), INT32_C(     125194), INT32_C(     148188));
  r = simde_mm_srai_epi32(a, 13);
  simde_assert_m128i_i16(r, ==, e);

  #if 0
  e = simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0));
  r = simde_mm_srai_epi32(a, -7);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0));
  r = simde_mm_srai_epi32(a, -42);
  simde_assert_m128i_i16(r, ==, e);

  e = simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0));
  r = simde_mm_srai_epi32(a, 1729);
  simde_assert_m128i_i16(r, ==, e);
  #endif

  return 0;
}

static int
test_simde_mm_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-29640), INT16_C( 27486), INT16_C(-30681), INT16_C( 22606),
                         INT16_C(-21221), INT16_C(  7042), INT16_C( -7099), INT16_C(-13884)),
      simde_mm_set_epi16(INT16_C( 25024), INT16_C( 23280), INT16_C( 16696), INT16_C(-15760),
                         INT16_C( 26840), INT16_C( -9200), INT16_C(  8744), INT16_C( 20000)) },
    { simde_mm_set_epi16(INT16_C( 15230), INT16_C( 23269), INT16_C(-21546), INT16_C( 15633),
                         INT16_C(  9645), INT16_C(-32001), INT16_C( -1446), INT16_C( -7049)),
      simde_mm_set_epi16(INT16_C( -9232), INT16_C(-10456), INT16_C( 24240), INT16_C( -6008),
                         INT16_C( 11624), INT16_C(  6136), INT16_C(-11568), INT16_C(  9144)) },
    { simde_mm_set_epi16(INT16_C( -4964), INT16_C( 29371), INT16_C( -7375), INT16_C(  7185),
                         INT16_C(-25257), INT16_C( 29335), INT16_C( 15023), INT16_C( 23258)),
      simde_mm_set_epi16(INT16_C( 25824), INT16_C(-27176), INT16_C(  6536), INT16_C( -8056),
                         INT16_C( -5448), INT16_C(-27464), INT16_C(-10888), INT16_C(-10544)) },
    { simde_mm_set_epi16(INT16_C(-29984), INT16_C(-17481), INT16_C(-31241), INT16_C( 11397),
                         INT16_C(  2926), INT16_C(-28904), INT16_C(-20560), INT16_C(-32448)),
      simde_mm_set_epi16(INT16_C( 22272), INT16_C( -8776), INT16_C( 12216), INT16_C( 25640),
                         INT16_C( 23408), INT16_C( 30912), INT16_C( 32128), INT16_C(  2560)) },
    { simde_mm_set_epi16(INT16_C(-18879), INT16_C(  5889), INT16_C(-27972), INT16_C( -4500),
                         INT16_C(-12683), INT16_C( 25849), INT16_C( 24809), INT16_C( 26782)),
      simde_mm_set_epi16(INT16_C(-19960), INT16_C(-18424), INT16_C(-27168), INT16_C( 29536),
                         INT16_C( 29608), INT16_C( 10184), INT16_C(  1864), INT16_C( 17648)) },
    { simde_mm_set_epi16(INT16_C(-12553), INT16_C(-22953), INT16_C( 21946), INT16_C( -9017),
                         INT16_C(-10462), INT16_C( -7608), INT16_C( 26015), INT16_C(-24893)),
      simde_mm_set_epi16(INT16_C( 30648), INT16_C( 12984), INT16_C(-21040), INT16_C( -6600),
                         INT16_C(-18160), INT16_C(  4672), INT16_C( 11512), INT16_C( -2536)) },
    { simde_mm_set_epi16(INT16_C( 23545), INT16_C(  -728), INT16_C( 17963), INT16_C(-24889),
                         INT16_C( 18443), INT16_C( 19433), INT16_C(-18886), INT16_C(-28120)),
      simde_mm_set_epi16(INT16_C( -8248), INT16_C( -5824), INT16_C( 12632), INT16_C( -2504),
                         INT16_C( 16472), INT16_C( 24392), INT16_C(-20016), INT16_C(-28352)) },
    { simde_mm_set_epi16(INT16_C(  1885), INT16_C(-18948), INT16_C(-21057), INT16_C(   636),
                         INT16_C( -9667), INT16_C(-20298), INT16_C( 25111), INT16_C( 30554)),
      simde_mm_set_epi16(INT16_C( 15080), INT16_C(-20512), INT16_C( 28152), INT16_C(  5088),
                         INT16_C(-11800), INT16_C(-31312), INT16_C(  4280), INT16_C(-17712)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    simde__m128i r = simde_mm_slli_epi16(test_vec[i].a, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);

    r = simde_mm_slli_epi16(test_vec[i].a, 0);
    simde_assert_m128i_i16(r, ==, test_vec[i].a);

    r = simde_mm_slli_epi16(test_vec[i].a, 32);
    simde_assert_m128i_i16(r, ==, zeros);

    r = simde_mm_slli_epi16(test_vec[i].a, 33);
    simde_assert_m128i_i16(r, ==, zeros);
  }

  return 0;
}

static int
test_simde_mm_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-29640), INT16_C( 27486), INT16_C(-30681), INT16_C( 22606),
                         INT16_C(-21221), INT16_C(  7042), INT16_C( -7099), INT16_C(-13884)),
      simde_mm_set_epi16(INT16_C(  4487), INT16_C(  3435), INT16_C(  4356), INT16_C(  2825),
                         INT16_C(  5539), INT16_C(   880), INT16_C(  7304), INT16_C(  6456)) },
    { simde_mm_set_epi16(INT16_C( 15230), INT16_C( 23269), INT16_C(-21546), INT16_C( 15633),
                         INT16_C(  9645), INT16_C(-32001), INT16_C( -1446), INT16_C( -7049)),
      simde_mm_set_epi16(INT16_C(  1903), INT16_C(  2908), INT16_C(  5498), INT16_C(  1954),
                         INT16_C(  1205), INT16_C(  4191), INT16_C(  8011), INT16_C(  7310)) },
    { simde_mm_set_epi16(INT16_C( -4964), INT16_C( 29371), INT16_C( -7375), INT16_C(  7185),
                         INT16_C(-25257), INT16_C( 29335), INT16_C( 15023), INT16_C( 23258)),
      simde_mm_set_epi16(INT16_C(  7571), INT16_C(  3671), INT16_C(  7270), INT16_C(   898),
                         INT16_C(  5034), INT16_C(  3666), INT16_C(  1877), INT16_C(  2907)) },
    { simde_mm_set_epi16(INT16_C(-29984), INT16_C(-17481), INT16_C(-31241), INT16_C( 11397),
                         INT16_C(  2926), INT16_C(-28904), INT16_C(-20560), INT16_C(-32448)),
      simde_mm_set_epi16(INT16_C(  4444), INT16_C(  6006), INT16_C(  4286), INT16_C(  1424),
                         INT16_C(   365), INT16_C(  4579), INT16_C(  5622), INT16_C(  4136)) },
    { simde_mm_set_epi16(INT16_C(-18879), INT16_C(  5889), INT16_C(-27972), INT16_C( -4500),
                         INT16_C(-12683), INT16_C( 25849), INT16_C( 24809), INT16_C( 26782)),
      simde_mm_set_epi16(INT16_C(  5832), INT16_C(   736), INT16_C(  4695), INT16_C(  7629),
                         INT16_C(  6606), INT16_C(  3231), INT16_C(  3101), INT16_C(  3347)) },
    { simde_mm_set_epi16(INT16_C(-12553), INT16_C(-22953), INT16_C( 21946), INT16_C( -9017),
                         INT16_C(-10462), INT16_C( -7608), INT16_C( 26015), INT16_C(-24893)),
      simde_mm_set_epi16(INT16_C(  6622), INT16_C(  5322), INT16_C(  2743), INT16_C(  7064),
                         INT16_C(  6884), INT16_C(  7241), INT16_C(  3251), INT16_C(  5080)) },
    { simde_mm_set_epi16(INT16_C( 23545), INT16_C(  -728), INT16_C( 17963), INT16_C(-24889),
                         INT16_C( 18443), INT16_C( 19433), INT16_C(-18886), INT16_C(-28120)),
      simde_mm_set_epi16(INT16_C(  2943), INT16_C(  8101), INT16_C(  2245), INT16_C(  5080),
                         INT16_C(  2305), INT16_C(  2429), INT16_C(  5831), INT16_C(  4677)) },
    { simde_mm_set_epi16(INT16_C(  1885), INT16_C(-18948), INT16_C(-21057), INT16_C(   636),
                         INT16_C( -9667), INT16_C(-20298), INT16_C( 25111), INT16_C( 30554)),
      simde_mm_set_epi16(INT16_C(   235), INT16_C(  5823), INT16_C(  5559), INT16_C(    79),
                         INT16_C(  6983), INT16_C(  5654), INT16_C(  3138), INT16_C(  3819)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    simde__m128i r = simde_mm_srli_epi16(test_vec[i].a, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);

    r = simde_mm_srli_epi16(test_vec[i].a, 0);
    simde_assert_m128i_i16(r, ==, test_vec[i].a);

    r = simde_mm_srli_epi16(test_vec[i].a, 16);
    simde_assert_m128i_i16(r, ==, zeros);

    r = simde_mm_srli_epi16(test_vec[i].a, 17);
    simde_assert_m128i_i16(r, ==, zeros);
  }

  return 0;
}

static int
test_simde_mm_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(-1285208672,  1618695439, -1484382898,    97979804),
      simde_mm_set_epi32( 1822995456,   258646496,  -255612480, -1159613568) },
    { simde_mm_set_epi32( -215274446, -1750972712, -2134111648,  -338295419),
      simde_mm_set_epi32( 1701152320,  -196551936,   427904000,  2059448480) },
    { simde_mm_set_epi32(  406577052, -1272707531,  -128013424,  1090211344),
      simde_mm_set_epi32(  125563776, -2071935328,   198537728,   527024640) },
    { simde_mm_set_epi32( -547315834,   386023226,   789460810, -2097507270),
      simde_mm_set_epi32( -334237504,  -532158656,  -507057856,  1599244096) },
    { simde_mm_set_epi32( 1943314584,   126005183,   199695502, -1431967820),
      simde_mm_set_epi32( 2056524544,  -262801440,  2095288768,  1421670016) },
    { simde_mm_set_epi32( 1899687789, -1162493730,  1537811436,   825134965),
      simde_mm_set_epi32(  660467104,  1454906304,  1965325696,   634515104) },
    { simde_mm_set_epi32(-1452393292, -1781210226, -1307434085, -2039047771),
      simde_mm_set_epi32(  768054912, -1164152384,  1111782240,  -825019232) },
    { simde_mm_set_epi32(-1646930836,   816193989, -1662050152,   347461227),
      simde_mm_set_epi32(-1162179200,   348403872, -1645997312, -1766142624) }
  };

  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec_18[] = {
    { {  INT32_C(  2018447505),  INT32_C(  2072485070), -INT32_C(  1063800373),  INT32_C(  1619529499) },
      {  INT32_C(  1111752704),  INT32_C(  1933049856), -INT32_C(   953417728),  INT32_C(  1013710848) } },
    { {  INT32_C(  1312528525), -INT32_C(  1886008265),  INT32_C(   615191858),  INT32_C(  1445629892) },
      {  INT32_C(  1647575040),  INT32_C(   819724288),  INT32_C(  1422393344),  INT32_C(  1058013184) } },
    { {  INT32_C(  1842248351), -INT32_C(   504867562),  INT32_C(   564232198),  INT32_C(   495004047) },
      { -INT32_C(   360972288),  INT32_C(  1415053312),  INT32_C(     1572864), -INT32_C(  1506017280) } },
    { { -INT32_C(   127157055), -INT32_C(  1148780408), -INT32_C(   622906602),  INT32_C(  1630538178) },
      { -INT32_C(   217841664),  INT32_C(    35651584), -INT32_C(   866648064),  INT32_C(   654835712) } },
    { { -INT32_C(  1714487421),  INT32_C(  1534834260), -INT32_C(   964944842),  INT32_C(   132382278) },
      { -INT32_C(    32768000), -INT32_C(   649068544),  INT32_C(  1893203968), -INT32_C(   115867648) } },
    { {  INT32_C(  1124093626),  INT32_C(  1711179599),  INT32_C(  2084560314),  INT32_C(  1792897254) },
      {  INT32_C(   988282880),  INT32_C(   490471424),  INT32_C(  1994915840), -INT32_C(  1013448704) } },
    { { -INT32_C(  1023169681), -INT32_C(  1742832030), -INT32_C(   513893477),  INT32_C(  1407730073) },
      { -INT32_C(  1380188160), -INT32_C(   108527616),  INT32_C(  1852571648),  INT32_C(   107216896) } },
    { { -INT32_C(   543758192),  INT32_C(   709137520),  INT32_C(  1487373169),  INT32_C(  1656915187) },
      { -INT32_C(  1572864000),  INT32_C(  1371537408),  INT32_C(   230948864),  INT32_C(   332136448) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    simde__m128i r = simde_mm_slli_epi32(test_vec[i].a, 5);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);

    r = simde_mm_slli_epi32(test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].a);

    r = simde_mm_slli_epi32(test_vec[i].a, 32);
    simde_assert_m128i_i32(r, ==, zeros);

    r = simde_mm_slli_epi32(test_vec[i].a, 33);
    simde_assert_m128i_i32(r, ==, zeros);
  }

  for (size_t i = 0 ; i < (sizeof(test_vec_18) / sizeof(test_vec_18[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec_18[i].a);
    simde__m128i r = simde_mm_slli_epi32(a, 18);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec_18[i].r));
  }

  return 0;
}

static int
test_simde_mm_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(   71624167,   617025209,  -286267780, -1151099730),
      simde_mm_set_epi32(    2238255,    19282037,   125271859,    98245861) },
    { simde_mm_set_epi32(-1660949423,    45505817,  1892774959,  -917815961),
      simde_mm_set_epi32(   82313058,     1422056,    59149217,   105535979) },
    { simde_mm_set_epi32( 1642659615,  -757986143, -1891097222,   940303240),
      simde_mm_set_epi32(   51333112,   110530661,    75120939,    29384476) },
    { simde_mm_set_epi32( 1761409447,   115333600,  -589319110, -1530115830),
      simde_mm_set_epi32(   55044045,     3604175,   115801505,    86401608) },
    { simde_mm_set_epi32( -502944468, -1500485927,    32222499,  1115657749),
      simde_mm_set_epi32(  118500713,    87327542,     1006953,    34864304) },
    { simde_mm_set_epi32( -545012251,   924477372, -1883097200,  1327167226),
      simde_mm_set_epi32(  117186095,    28889917,    75370940,    41473975) },
    { simde_mm_set_epi32(  995448668,   377764585, -1462273550,  1306007963),
      simde_mm_set_epi32(   31107770,    11805143,    88521679,    40812748) },
    { simde_mm_set_epi32( 1991954175,   665906947,  -606406775,  1678465696),
      simde_mm_set_epi32(   62248567,    20809592,   115267516,    52452053) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    simde__m128i r = simde_mm_srli_epi32(test_vec[i].a, 5);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);

    r = simde_mm_srli_epi32(test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].a);

    r = simde_mm_srli_epi32(test_vec[i].a, 64);
    simde_assert_m128i_i32(r, ==, zeros);

    r = simde_mm_srli_epi32(test_vec[i].a, 65);
    simde_assert_m128i_i32(r, ==, zeros);
  }

  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec_18[] = {
    { { -INT32_C(  1359328745), -INT32_C(   408445706),  INT32_C(   239121880),  INT32_C(   748205077) },
      {  INT32_C(       11198),  INT32_C(       14825),  INT32_C(         912),  INT32_C(        2854) } },
    { { -INT32_C(   345859164),  INT32_C(  1010393205),  INT32_C(  1843309992), -INT32_C(   446698290) },
      {  INT32_C(       15064),  INT32_C(        3854),  INT32_C(        7031),  INT32_C(       14679) } },
    { {  INT32_C(   764631350), -INT32_C(   837534730),  INT32_C(    98325744), -INT32_C(  1405979384) },
      {  INT32_C(        2916),  INT32_C(       13189),  INT32_C(         375),  INT32_C(       11020) } },
    { { -INT32_C(  2053663728), -INT32_C(  1648176907),  INT32_C(  1275764862), -INT32_C(  1020106099) },
      {  INT32_C(        8549),  INT32_C(       10096),  INT32_C(        4866),  INT32_C(       12492) } },
    { { -INT32_C(  1175403069), -INT32_C(   259586816),  INT32_C(  1660314713), -INT32_C(   384948007) },
      {  INT32_C(       11900),  INT32_C(       15393),  INT32_C(        6333),  INT32_C(       14915) } },
    { { -INT32_C(  1318148420), -INT32_C(   196136842),  INT32_C(  1581341137), -INT32_C(  2027850813) },
      {  INT32_C(       11355),  INT32_C(       15635),  INT32_C(        6032),  INT32_C(        8648) } },
    { {  INT32_C(   960500280),  INT32_C(  1881786391),  INT32_C(    97656620),  INT32_C(    82764103) },
      {  INT32_C(        3664),  INT32_C(        7178),  INT32_C(         372),  INT32_C(         315) } },
    { { -INT32_C(    38445945),  INT32_C(  1592919181),  INT32_C(   565982046), -INT32_C(   559358554) },
      {  INT32_C(       16237),  INT32_C(        6076),  INT32_C(        2159),  INT32_C(       14250) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec_18) / sizeof(test_vec_18[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec_18[i].a);
    simde__m128i r = simde_mm_srli_epi32(a, 18);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec_18[i].r));
  }

  return 0;
}

static int
test_simde_mm_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2315072815474662386), INT64_C( 6072154117607221746)),
      simde_mm_set_epi64x(INT64_C(-1181415201403959552), INT64_C( 2472475957923215616)) },
    { simde_mm_set_epi64x(INT64_C(-2150345518249743204), INT64_C( 3180241355952247476)),
      simde_mm_set_epi64x(INT64_C( 1456934769676144128), INT64_C( 1242523940277541376)) },
    { simde_mm_set_epi64x(INT64_C( 6492638483912689614), INT64_C( 7722522576063149658)),
      simde_mm_set_epi64x(INT64_C(  954242623894447872), INT64_C(-7641290244232631040)) },
    { simde_mm_set_epi64x(INT64_C(-3437371876454060839), INT64_C(-7472017034411611746)),
      simde_mm_set_epi64x(INT64_C( 2738257582909451392), INT64_C( 2812511428210380544)) },
    { simde_mm_set_epi64x(INT64_C(-2994435188669454779), INT64_C(-4713226846452985822)),
      simde_mm_set_epi64x(INT64_C( 4093921398210372224), INT64_C( 5449518086433018112)) },
    { simde_mm_set_epi64x(INT64_C(-1348831542752523511), INT64_C(-2794326256527200530)),
      simde_mm_set_epi64x(INT64_C(-6629740808937044864), INT64_C(-7185623435000187136)) },
    { simde_mm_set_epi64x(INT64_C(-5602242705933140185), INT64_C( 6492190109232091873)),
      simde_mm_set_epi64x(INT64_C( 2335952515230569344), INT64_C(  896850664777937024)) },
    { simde_mm_set_epi64x(INT64_C( 8003331601608352009), INT64_C(-5520322068937257120)),
      simde_mm_set_epi64x(INT64_C(-8591223121865833344), INT64_C(-5624950023005949952)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    simde__m128i r = simde_mm_slli_epi64(test_vec[i].a, 7);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);

    r = simde_mm_slli_epi64(test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].a);

    r = simde_mm_slli_epi64(test_vec[i].a, 64);
    simde_assert_m128i_i32(r, ==, zeros);

    r = simde_mm_slli_epi64(test_vec[i].a, 65);
    simde_assert_m128i_i32(r, ==, zeros);
  }

  return 0;
}

static int
test_simde_mm_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2315072815474662386), INT64_C( 6072154117607221746)),
      simde_mm_set_epi64x(INT64_C(  126028681704960072), INT64_C(   47438704043806419)) },
    { simde_mm_set_epi64x(INT64_C(-2150345518249743204), INT64_C( 3180241355952247476)),
      simde_mm_set_epi64x(INT64_C(  127315613714529753), INT64_C(   24845635593376933)) },
    { simde_mm_set_epi64x(INT64_C( 6492638483912689614), INT64_C( 7722522576063149658)),
      simde_mm_set_epi64x(INT64_C(   50723738155567887), INT64_C(   60332207625493356)) },
    { simde_mm_set_epi64x(INT64_C(-3437371876454060839), INT64_C(-7472017034411611746)),
      simde_mm_set_epi64x(INT64_C(  117260720291058521), INT64_C(   85740054994515155)) },
    { simde_mm_set_epi64x(INT64_C(-2994435188669454779), INT64_C(-4713226846452985822)),
      simde_mm_set_epi64x(INT64_C(  120721163164375756), INT64_C(  107293103337941920)) },
    { simde_mm_set_epi64x(INT64_C(-1348831542752523511), INT64_C(-2794326256527200530)),
      simde_mm_set_epi64x(INT64_C(  133577441648101782), INT64_C(  122284514196737117)) },
    { simde_mm_set_epi64x(INT64_C(-5602242705933140185), INT64_C( 6492190109232091873)),
      simde_mm_set_epi64x(INT64_C(  100347666935753214), INT64_C(   50720235228375717)) },
    { simde_mm_set_epi64x(INT64_C( 8003331601608352009), INT64_C(-5520322068937257120)),
      simde_mm_set_epi64x(INT64_C(   62526028137565250), INT64_C(  100987671912283550)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    /* r = simde_mm_srli_epi64(test_vec[i].a, -1); */
    /* simde_assert_m128i_i32(r, ==, zeros); */

    r = simde_mm_srli_epi64(test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].a);

    r = simde_mm_srli_epi64(test_vec[i].a, 7);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);

    r = simde_mm_srli_epi64(test_vec[i].a, 64);
    simde_assert_m128i_i32(r, ==, zeros);

    r = simde_mm_srli_epi64(test_vec[i].a, 65);
    simde_assert_m128i_i32(r, ==, zeros);
  }

  return 0;
}

static int
test_simde_mm_store_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  825.31), SIMDE_FLOAT64_C(  176.75)),
      {SIMDE_FLOAT64_C(   176.75), SIMDE_FLOAT64_C(  825.31) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -248.58), SIMDE_FLOAT64_C( -171.93)),
      {SIMDE_FLOAT64_C(  -171.93), SIMDE_FLOAT64_C( -248.58) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  419.77), SIMDE_FLOAT64_C(  712.85)),
      {SIMDE_FLOAT64_C(   712.85), SIMDE_FLOAT64_C(  419.77) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  785.55), SIMDE_FLOAT64_C(   78.74)),
      {SIMDE_FLOAT64_C(    78.74), SIMDE_FLOAT64_C(  785.55) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -963.92), SIMDE_FLOAT64_C(  614.28)),
      {SIMDE_FLOAT64_C(   614.28), SIMDE_FLOAT64_C( -963.92) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  624.62), SIMDE_FLOAT64_C( -260.28)),
      {SIMDE_FLOAT64_C(  -260.28), SIMDE_FLOAT64_C(  624.62) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -178.24), SIMDE_FLOAT64_C(  945.12)),
      {SIMDE_FLOAT64_C(   945.12), SIMDE_FLOAT64_C( -178.24) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -271.60), SIMDE_FLOAT64_C( -674.20)),
      {SIMDE_FLOAT64_C(  -674.20), SIMDE_FLOAT64_C( -271.60) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_mm_store_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_store_pd1(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  278.50), SIMDE_FLOAT64_C(  554.87)),
      {SIMDE_FLOAT64_C(   554.87), SIMDE_FLOAT64_C(  554.87) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -348.28), SIMDE_FLOAT64_C(  361.13)),
      {SIMDE_FLOAT64_C(   361.13), SIMDE_FLOAT64_C(  361.13) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -701.38), SIMDE_FLOAT64_C(  708.23)),
      {SIMDE_FLOAT64_C(   708.23), SIMDE_FLOAT64_C(  708.23) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -362.77), SIMDE_FLOAT64_C( -574.16)),
      {SIMDE_FLOAT64_C(  -574.16), SIMDE_FLOAT64_C( -574.16) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  420.63), SIMDE_FLOAT64_C(  850.70)),
      {SIMDE_FLOAT64_C(   850.70), SIMDE_FLOAT64_C(  850.70) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -223.78), SIMDE_FLOAT64_C(  845.58)),
      {SIMDE_FLOAT64_C(   845.58), SIMDE_FLOAT64_C(  845.58) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  948.70), SIMDE_FLOAT64_C(  544.62)),
      {SIMDE_FLOAT64_C(   544.62), SIMDE_FLOAT64_C(  544.62) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -216.79), SIMDE_FLOAT64_C( -830.24)),
      {SIMDE_FLOAT64_C(  -830.24), SIMDE_FLOAT64_C( -830.24) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_mm_store_pd1(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_store_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 b[2];
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -380.32), SIMDE_FLOAT64_C(  589.10)),
      {SIMDE_FLOAT64_C(  -886.38), SIMDE_FLOAT64_C(  706.27) },
      {SIMDE_FLOAT64_C(   589.10), SIMDE_FLOAT64_C(  706.27) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   97.55), SIMDE_FLOAT64_C( -921.93)),
      {SIMDE_FLOAT64_C(   175.08), SIMDE_FLOAT64_C( -498.43) },
      {SIMDE_FLOAT64_C(  -921.93), SIMDE_FLOAT64_C( -498.43) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -962.76), SIMDE_FLOAT64_C( -267.73)),
      {SIMDE_FLOAT64_C(  -505.37), SIMDE_FLOAT64_C( -729.92) },
      {SIMDE_FLOAT64_C(  -267.73), SIMDE_FLOAT64_C( -729.92) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  154.59), SIMDE_FLOAT64_C( -829.83)),
      {SIMDE_FLOAT64_C(   141.33), SIMDE_FLOAT64_C(  657.26) },
      {SIMDE_FLOAT64_C(  -829.83), SIMDE_FLOAT64_C(  657.26) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -623.49), SIMDE_FLOAT64_C( -306.50)),
      {SIMDE_FLOAT64_C(  -540.89), SIMDE_FLOAT64_C(  213.61) },
      {SIMDE_FLOAT64_C(  -306.50), SIMDE_FLOAT64_C(  213.61) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  708.57), SIMDE_FLOAT64_C( -626.05)),
      {SIMDE_FLOAT64_C(  -658.64), SIMDE_FLOAT64_C(  310.68) },
      {SIMDE_FLOAT64_C(  -626.05), SIMDE_FLOAT64_C(  310.68) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    7.10), SIMDE_FLOAT64_C(   84.59)),
      {SIMDE_FLOAT64_C(   191.88), SIMDE_FLOAT64_C( -258.06) },
      {SIMDE_FLOAT64_C(    84.59), SIMDE_FLOAT64_C( -258.06) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  399.99), SIMDE_FLOAT64_C( -337.50)),
      {SIMDE_FLOAT64_C(   733.91), SIMDE_FLOAT64_C( -756.49) },
      {SIMDE_FLOAT64_C(  -337.50), SIMDE_FLOAT64_C( -756.49) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_store_sd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_store_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1969078312), INT32_C( 1646650233), INT32_C(-1190611301), INT32_C(  889904733)),
      simde_mm_set_epi32(INT32_C(-1969078312), INT32_C( 1646650233), INT32_C(-1190611301), INT32_C(  889904733)) },
    { simde_mm_set_epi32(INT32_C(  361491951), INT32_C(-1497327260), INT32_C(-2092062445), INT32_C(-1242536811)),
      simde_mm_set_epi32(INT32_C(  361491951), INT32_C(-1497327260), INT32_C(-2092062445), INT32_C(-1242536811)) },
    { simde_mm_set_epi32(INT32_C(  790325756), INT32_C( -295457696), INT32_C(   30297459), INT32_C(  860807687)),
      simde_mm_set_epi32(INT32_C(  790325756), INT32_C( -295457696), INT32_C(   30297459), INT32_C(  860807687)) },
    { simde_mm_set_epi32(INT32_C(-1228048681), INT32_C( 1236867704), INT32_C(-1927827785), INT32_C(-1233913343)),
      simde_mm_set_epi32(INT32_C(-1228048681), INT32_C( 1236867704), INT32_C(-1927827785), INT32_C(-1233913343)) },
    { simde_mm_set_epi32(INT32_C( 1007412231), INT32_C( -296710614), INT32_C(-1416317108), INT32_C( -839008134)),
      simde_mm_set_epi32(INT32_C( 1007412231), INT32_C( -296710614), INT32_C(-1416317108), INT32_C( -839008134)) },
    { simde_mm_set_epi32(INT32_C( 1325410731), INT32_C( 2049780007), INT32_C(  190337706), INT32_C( 1948643128)),
      simde_mm_set_epi32(INT32_C( 1325410731), INT32_C( 2049780007), INT32_C(  190337706), INT32_C( 1948643128)) },
    { simde_mm_set_epi32(INT32_C(-1295145224), INT32_C( -913388140), INT32_C(-1185110338), INT32_C(  127220065)),
      simde_mm_set_epi32(INT32_C(-1295145224), INT32_C( -913388140), INT32_C(-1185110338), INT32_C(  127220065)) },
    { simde_mm_set_epi32(INT32_C(  479405479), INT32_C(  641965302), INT32_C(-1100092667), INT32_C( 1837148945)),
      simde_mm_set_epi32(INT32_C(  479405479), INT32_C(  641965302), INT32_C(-1100092667), INT32_C( 1837148945)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    simde_mm_store_si128(&r, test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_storeh_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 b[2];
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -154.79), SIMDE_FLOAT64_C(  689.59)),
      {SIMDE_FLOAT64_C(  -986.30), SIMDE_FLOAT64_C( -463.82) },
      {SIMDE_FLOAT64_C(  -154.79), SIMDE_FLOAT64_C( -463.82) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  944.07), SIMDE_FLOAT64_C( -598.47)),
      {SIMDE_FLOAT64_C(  -514.42), SIMDE_FLOAT64_C(  652.02) },
      {SIMDE_FLOAT64_C(   944.07), SIMDE_FLOAT64_C(  652.02) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.72), SIMDE_FLOAT64_C( -771.52)),
      {SIMDE_FLOAT64_C(   343.91), SIMDE_FLOAT64_C( -171.75) },
      {SIMDE_FLOAT64_C(   -34.72), SIMDE_FLOAT64_C( -171.75) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  305.40), SIMDE_FLOAT64_C( -671.87)),
      {SIMDE_FLOAT64_C(  -579.65), SIMDE_FLOAT64_C( -985.37) },
      {SIMDE_FLOAT64_C(   305.40), SIMDE_FLOAT64_C( -985.37) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  173.51), SIMDE_FLOAT64_C(  643.06)),
      {SIMDE_FLOAT64_C(   794.84), SIMDE_FLOAT64_C(  233.08) },
      {SIMDE_FLOAT64_C(   173.51), SIMDE_FLOAT64_C(  233.08) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -130.21), SIMDE_FLOAT64_C( -290.59)),
      {SIMDE_FLOAT64_C(   584.05), SIMDE_FLOAT64_C( -167.57) },
      {SIMDE_FLOAT64_C(  -130.21), SIMDE_FLOAT64_C( -167.57) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -759.48), SIMDE_FLOAT64_C(  428.70)),
      {SIMDE_FLOAT64_C(    36.98), SIMDE_FLOAT64_C( -189.97) },
      {SIMDE_FLOAT64_C(  -759.48), SIMDE_FLOAT64_C( -189.97) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  222.49), SIMDE_FLOAT64_C(  621.71)),
      {SIMDE_FLOAT64_C(  -467.95), SIMDE_FLOAT64_C( -910.73) },
      {SIMDE_FLOAT64_C(   222.49), SIMDE_FLOAT64_C( -910.73) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storeh_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_storel_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-8572402204481175152), INT64_C(-3565447379630862345)),
      simde_mm_set_epi64x(INT64_C(-5836787758646654491), INT64_C(  978262207997446536)),
      simde_mm_set_epi64x(INT64_C(-5836787758646654491), INT64_C(-3565447379630862345)) },
    { simde_mm_set_epi64x(INT64_C(  883894259135204982), INT64_C(-6785295924552521928)),
      simde_mm_set_epi64x(INT64_C( 5751908210058630765), INT64_C(-7999305285706001942)),
      simde_mm_set_epi64x(INT64_C( 5751908210058630765), INT64_C(-6785295924552521928)) },
    { simde_mm_set_epi64x(INT64_C( 4991496111910955453), INT64_C(-1947231678451890517)),
      simde_mm_set_epi64x(INT64_C( 1054715717267865334), INT64_C(-5199938312574175167)),
      simde_mm_set_epi64x(INT64_C( 1054715717267865334), INT64_C(-1947231678451890517)) },
    { simde_mm_set_epi64x(INT64_C(-6916286228894702079), INT64_C(-7888320918323423602)),
      simde_mm_set_epi64x(INT64_C(-4560271213984560857), INT64_C( 1030486561279856923)),
      simde_mm_set_epi64x(INT64_C(-4560271213984560857), INT64_C(-7888320918323423602)) },
    { simde_mm_set_epi64x(INT64_C(-5516402797122916761), INT64_C( 8516393373254709766)),
      simde_mm_set_epi64x(INT64_C(-8984432431227422893), INT64_C(-1285772213781786319)),
      simde_mm_set_epi64x(INT64_C(-8984432431227422893), INT64_C( 8516393373254709766)) },
    { simde_mm_set_epi64x(INT64_C( 1537881028582424966), INT64_C( 3855597324285413517)),
      simde_mm_set_epi64x(INT64_C(-1087659369158402202), INT64_C( 5504181592152866903)),
      simde_mm_set_epi64x(INT64_C(-1087659369158402202), INT64_C( 3855597324285413517)) },
    { simde_mm_set_epi64x(INT64_C(-1003754336566127903), INT64_C( 3155788073225494266)),
      simde_mm_set_epi64x(INT64_C( 7014294951579480267), INT64_C(-6777837266490471507)),
      simde_mm_set_epi64x(INT64_C( 7014294951579480267), INT64_C( 3155788073225494266)) },
    { simde_mm_set_epi64x(INT64_C( 7343239871058385173), INT64_C(-8089093160963830084)),
      simde_mm_set_epi64x(INT64_C(-7180996141698966448), INT64_C( 1747758344108352756)),
      simde_mm_set_epi64x(INT64_C(-7180996141698966448), INT64_C(-8089093160963830084)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    simde_memcpy(&r, &(test_vec[i].b), sizeof(r));
    simde_mm_storel_epi64(&r, test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_storel_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 b[2];
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -887.08), SIMDE_FLOAT64_C( -520.70)),
      {SIMDE_FLOAT64_C(  -258.49), SIMDE_FLOAT64_C(  913.00) },
      {SIMDE_FLOAT64_C(  -520.70), SIMDE_FLOAT64_C(  913.00) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  724.04), SIMDE_FLOAT64_C( -774.49)),
      {SIMDE_FLOAT64_C(   557.37), SIMDE_FLOAT64_C( -701.13) },
      {SIMDE_FLOAT64_C(  -774.49), SIMDE_FLOAT64_C( -701.13) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -366.90), SIMDE_FLOAT64_C( -168.25)),
      {SIMDE_FLOAT64_C(   485.14), SIMDE_FLOAT64_C(  500.94) },
      {SIMDE_FLOAT64_C(  -168.25), SIMDE_FLOAT64_C(  500.94) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -783.51), SIMDE_FLOAT64_C( -187.73)),
      {SIMDE_FLOAT64_C(  -391.92), SIMDE_FLOAT64_C( -506.74) },
      {SIMDE_FLOAT64_C(  -187.73), SIMDE_FLOAT64_C( -506.74) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.27), SIMDE_FLOAT64_C( -405.84)),
      {SIMDE_FLOAT64_C(  -733.12), SIMDE_FLOAT64_C( -697.37) },
      {SIMDE_FLOAT64_C(  -405.84), SIMDE_FLOAT64_C( -697.37) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -773.31), SIMDE_FLOAT64_C( -470.65)),
      {SIMDE_FLOAT64_C(   738.01), SIMDE_FLOAT64_C( -908.23) },
      {SIMDE_FLOAT64_C(  -470.65), SIMDE_FLOAT64_C( -908.23) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -43.07), SIMDE_FLOAT64_C( -143.29)),
      {SIMDE_FLOAT64_C(   985.95), SIMDE_FLOAT64_C(   19.70) },
      {SIMDE_FLOAT64_C(  -143.29), SIMDE_FLOAT64_C(   19.70) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  649.59), SIMDE_FLOAT64_C( -925.70)),
      {SIMDE_FLOAT64_C(   519.96), SIMDE_FLOAT64_C(  348.23) },
      {SIMDE_FLOAT64_C(  -925.70), SIMDE_FLOAT64_C(  348.23) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storel_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_storer_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 b[2];
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  765.90), SIMDE_FLOAT64_C( -392.20)),
      {SIMDE_FLOAT64_C(  -898.96), SIMDE_FLOAT64_C(  810.87) },
      {SIMDE_FLOAT64_C(   765.90), SIMDE_FLOAT64_C( -392.20) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  848.80), SIMDE_FLOAT64_C(  -20.45)),
      {SIMDE_FLOAT64_C(  -298.33), SIMDE_FLOAT64_C(  199.86) },
      {SIMDE_FLOAT64_C(   848.80), SIMDE_FLOAT64_C(  -20.45) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -770.38), SIMDE_FLOAT64_C(   73.29)),
      {SIMDE_FLOAT64_C(  -471.45), SIMDE_FLOAT64_C(   85.53) },
      {SIMDE_FLOAT64_C(  -770.38), SIMDE_FLOAT64_C(   73.29) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  181.32), SIMDE_FLOAT64_C( -528.68)),
      {SIMDE_FLOAT64_C(   925.12), SIMDE_FLOAT64_C(  -79.25) },
      {SIMDE_FLOAT64_C(   181.32), SIMDE_FLOAT64_C( -528.68) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  786.51), SIMDE_FLOAT64_C( -396.45)),
      {SIMDE_FLOAT64_C(  -196.75), SIMDE_FLOAT64_C( -493.37) },
      {SIMDE_FLOAT64_C(   786.51), SIMDE_FLOAT64_C( -396.45) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  379.82), SIMDE_FLOAT64_C( -482.63)),
      {SIMDE_FLOAT64_C(   356.61), SIMDE_FLOAT64_C(    6.76) },
      {SIMDE_FLOAT64_C(   379.82), SIMDE_FLOAT64_C( -482.63) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -597.31), SIMDE_FLOAT64_C( -427.66)),
      {SIMDE_FLOAT64_C(  -787.49), SIMDE_FLOAT64_C(  322.82) },
      {SIMDE_FLOAT64_C(  -597.31), SIMDE_FLOAT64_C( -427.66) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  515.42), SIMDE_FLOAT64_C(  801.05)),
      {SIMDE_FLOAT64_C(  -892.50), SIMDE_FLOAT64_C(  794.29) },
      {SIMDE_FLOAT64_C(   515.42), SIMDE_FLOAT64_C(  801.05) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storer_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_storeu_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -787.29), SIMDE_FLOAT64_C(  410.40)),
      {SIMDE_FLOAT64_C(   579.61), SIMDE_FLOAT64_C( -320.32) },
      {SIMDE_FLOAT64_C(   410.40), SIMDE_FLOAT64_C( -787.29) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  944.41), SIMDE_FLOAT64_C( -149.27)),
      {SIMDE_FLOAT64_C(   850.87), SIMDE_FLOAT64_C( -993.24) },
      {SIMDE_FLOAT64_C(  -149.27), SIMDE_FLOAT64_C(  944.41) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -415.98), SIMDE_FLOAT64_C( -916.88)),
      {SIMDE_FLOAT64_C(   966.39), SIMDE_FLOAT64_C( -183.52) },
      {SIMDE_FLOAT64_C(  -916.88), SIMDE_FLOAT64_C( -415.98) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  431.98), SIMDE_FLOAT64_C( -691.20)),
      {SIMDE_FLOAT64_C(  -659.73), SIMDE_FLOAT64_C(  -34.04) },
      {SIMDE_FLOAT64_C(  -691.20), SIMDE_FLOAT64_C(  431.98) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -483.35), SIMDE_FLOAT64_C(  766.13)),
      {SIMDE_FLOAT64_C(  -638.61), SIMDE_FLOAT64_C(  157.38) },
      {SIMDE_FLOAT64_C(   766.13), SIMDE_FLOAT64_C( -483.35) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  386.12), SIMDE_FLOAT64_C(  330.08)),
      {SIMDE_FLOAT64_C(   588.80), SIMDE_FLOAT64_C( -111.35) },
      {SIMDE_FLOAT64_C(   330.08), SIMDE_FLOAT64_C(  386.12) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   45.12), SIMDE_FLOAT64_C(  964.86)),
      {SIMDE_FLOAT64_C(   199.95), SIMDE_FLOAT64_C(  998.07) },
      {SIMDE_FLOAT64_C(   964.86), SIMDE_FLOAT64_C(   45.12) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -30.76), SIMDE_FLOAT64_C( -723.78)),
      {SIMDE_FLOAT64_C(    -8.78), SIMDE_FLOAT64_C(  410.81) },
      {SIMDE_FLOAT64_C(  -723.78), SIMDE_FLOAT64_C(  -30.76) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storeu_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_storeu_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  559775826), INT32_C( -953548695), INT32_C(  811731668), INT32_C(  717258119)),
      simde_mm_set_epi32(INT32_C(  559775826), INT32_C( -953548695), INT32_C(  811731668), INT32_C(  717258119)) },
    { simde_mm_set_epi32(INT32_C( -819991397), INT32_C(-1367017296), INT32_C( 1998597245), INT32_C( -194600747)),
      simde_mm_set_epi32(INT32_C( -819991397), INT32_C(-1367017296), INT32_C( 1998597245), INT32_C( -194600747)) },
    { simde_mm_set_epi32(INT32_C(-1983970353), INT32_C( 1036245224), INT32_C( 1208146280), INT32_C( 2086212378)),
      simde_mm_set_epi32(INT32_C(-1983970353), INT32_C( 1036245224), INT32_C( 1208146280), INT32_C( 2086212378)) },
    { simde_mm_set_epi32(INT32_C(-1115487208), INT32_C( 1901412157), INT32_C( -373768038), INT32_C( 1379732008)),
      simde_mm_set_epi32(INT32_C(-1115487208), INT32_C( 1901412157), INT32_C( -373768038), INT32_C( 1379732008)) },
    { simde_mm_set_epi32(INT32_C( -772363216), INT32_C( 1208166493), INT32_C( 2006133231), INT32_C( -567476934)),
      simde_mm_set_epi32(INT32_C( -772363216), INT32_C( 1208166493), INT32_C( 2006133231), INT32_C( -567476934)) },
    { simde_mm_set_epi32(INT32_C( -117502444), INT32_C(  175751722), INT32_C(-1353399970), INT32_C( -281466966)),
      simde_mm_set_epi32(INT32_C( -117502444), INT32_C(  175751722), INT32_C(-1353399970), INT32_C( -281466966)) },
    { simde_mm_set_epi32(INT32_C( 2118723593), INT32_C(-1657083210), INT32_C( 1907402314), INT32_C(  669913338)),
      simde_mm_set_epi32(INT32_C( 2118723593), INT32_C(-1657083210), INT32_C( 1907402314), INT32_C(  669913338)) },
    { simde_mm_set_epi32(INT32_C(  372135232), INT32_C( 1779530333), INT32_C(-1088754891), INT32_C( 1773872281)),
      simde_mm_set_epi32(INT32_C(  372135232), INT32_C( 1779530333), INT32_C(-1088754891), INT32_C( 1773872281)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    simde_mm_storeu_si128(&r, test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_storeu_si16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[8];
    const int16_t r;
  } test_vec[] = {
    { { -INT16_C(  6988),  INT16_C( 26153), -INT16_C(  2289), -INT16_C(  8118),  INT16_C( 29038),  INT16_C(  9460), -INT16_C( 25910), -INT16_C(  2208) },
      -INT16_C(  6988) },
    { {  INT16_C(  4717), -INT16_C( 14623),  INT16_C( 14017), -INT16_C( 21548),  INT16_C( 18960), -INT16_C( 20965),  INT16_C( 24253),  INT16_C( 29067) },
       INT16_C(  4717) },
    { { -INT16_C( 19389),  INT16_C( 21207),  INT16_C(  8619),  INT16_C(  6450),  INT16_C(  9874),  INT16_C( 23869), -INT16_C( 25152),  INT16_C( 11604) },
      -INT16_C( 19389) },
    { {  INT16_C( 14000),  INT16_C( 29171), -INT16_C( 14484),  INT16_C( 31772),  INT16_C( 14353), -INT16_C( 12758), -INT16_C( 19050), -INT16_C(  9920) },
       INT16_C( 14000) },
    { {  INT16_C(  5993),  INT16_C(  5163),  INT16_C( 23865), -INT16_C( 13523),  INT16_C( 27523),  INT16_C( 17448),  INT16_C( 32008), -INT16_C( 18319) },
       INT16_C(  5993) },
    { {  INT16_C( 26035),  INT16_C(  7977),  INT16_C( 17964),  INT16_C( 16027), -INT16_C( 14722),  INT16_C(  5132),  INT16_C( 19579), -INT16_C(  6674) },
       INT16_C( 26035) },
    { {  INT16_C(  6500), -INT16_C( 25095),  INT16_C( 10103), -INT16_C(  1432), -INT16_C( 28270), -INT16_C( 26050), -INT16_C( 20466), -INT16_C( 16045) },
       INT16_C(  6500) },
    { {  INT16_C( 31765),  INT16_C( 16864),  INT16_C( 31682),  INT16_C( 16511), -INT16_C( 29631), -INT16_C( 17067),  INT16_C( 17368),  INT16_C( 15522) },
       INT16_C( 31765) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    int16_t r;
    HEDLEY_CONCAT(simde,_mm_storeu_si16)(&r, a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_storeu_si32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[4];
    const int32_t r;
  } test_vec[] = {
    { { -INT32_C(   630341273), -INT32_C(   601100258),  INT32_C(   527009452),  INT32_C(   382213470) },
      -INT32_C(   630341273) },
    { {  INT32_C(   733254901),  INT32_C(   225181130), -INT32_C(   418546734), -INT32_C(  1459105470) },
       INT32_C(   733254901) },
    { { -INT32_C(  1333562222),  INT32_C(   277655396), -INT32_C(  1825508043),  INT32_C(   145356818) },
      -INT32_C(  1333562222) },
    { {  INT32_C(  1446207116),  INT32_C(   761503323),  INT32_C(  1544843545), -INT32_C(   721085374) },
       INT32_C(  1446207116) },
    { { -INT32_C(   175797872),  INT32_C(  1829048888),  INT32_C(   436286727), -INT32_C(  1188910547) },
      -INT32_C(   175797872) },
    { {  INT32_C(  1661949192),  INT32_C(   227570676),  INT32_C(   644457956),  INT32_C(  1375432641) },
       INT32_C(  1661949192) },
    { {  INT32_C(   809927160), -INT32_C(  1700967277), -INT32_C(  1347117439),  INT32_C(  1365825097) },
       INT32_C(   809927160) },
    { {  INT32_C(   548763692), -INT32_C(   819116565), -INT32_C(  1409968150), -INT32_C(    16912122) },
       INT32_C(   548763692) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    int32_t r;
    HEDLEY_CONCAT(simde,_mm_storeu_si32)(&r, a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_storeu_si64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[2];
    const int64_t r;
  } test_vec[] = {
    { {  INT64_C( 1269957435069449074),  INT64_C( 6198123151038108778) },
       INT64_C( 1269957435069449074) },
    { { -INT64_C( 1631810497504953952), -INT64_C( 5530541008416845765) },
      -INT64_C( 1631810497504953952) },
    { { -INT64_C( 6740103892576997931), -INT64_C(   59573331693324629) },
      -INT64_C( 6740103892576997931) },
    { { -INT64_C( 9008073061231320301), -INT64_C(  564917926918647499) },
      -INT64_C( 9008073061231320301) },
    { { -INT64_C( 1996551244505816721),  INT64_C(  965994603972566793) },
      -INT64_C( 1996551244505816721) },
    { {  INT64_C(  815745091936186761), -INT64_C( 8734544458042763860) },
       INT64_C(  815745091936186761) },
    { {  INT64_C(  191535998296794507), -INT64_C( 3305974968983330281) },
       INT64_C(  191535998296794507) },
    { {  INT64_C(  407001106525339075),  INT64_C( 6676759969134880266) },
       INT64_C(  407001106525339075) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    int64_t r;
    HEDLEY_CONCAT(simde,_mm_storeu_si64)(&r, a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_store1_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  291.96), SIMDE_FLOAT64_C(  -70.45)),
      { SIMDE_FLOAT64_C(  -70.45), SIMDE_FLOAT64_C(  -70.45) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  896.84), SIMDE_FLOAT64_C(  840.00)),
      { SIMDE_FLOAT64_C(  840.00), SIMDE_FLOAT64_C(  840.00) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  792.86), SIMDE_FLOAT64_C(  559.02)),
      { SIMDE_FLOAT64_C(  559.02), SIMDE_FLOAT64_C(  559.02) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  401.40), SIMDE_FLOAT64_C( -245.84)),
      { SIMDE_FLOAT64_C( -245.84), SIMDE_FLOAT64_C( -245.84) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  441.21), SIMDE_FLOAT64_C(  731.20)),
      { SIMDE_FLOAT64_C(  731.20), SIMDE_FLOAT64_C(  731.20) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  569.26), SIMDE_FLOAT64_C( -434.33)),
      { SIMDE_FLOAT64_C( -434.33), SIMDE_FLOAT64_C( -434.33) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -796.24), SIMDE_FLOAT64_C(  534.91)),
      { SIMDE_FLOAT64_C(  534.91), SIMDE_FLOAT64_C(  534.91) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -221.59), SIMDE_FLOAT64_C( -372.35)),
      { SIMDE_FLOAT64_C( -372.35), SIMDE_FLOAT64_C( -372.35) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2] ;
    simde_mm_store1_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 4);
  }

  return 0;
}

static int
test_simde_mm_stream_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -749.31), SIMDE_FLOAT64_C( -483.97)),
      {SIMDE_FLOAT64_C(  -483.97), SIMDE_FLOAT64_C( -749.31) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  587.52), SIMDE_FLOAT64_C( -903.15)),
      {SIMDE_FLOAT64_C(  -903.15), SIMDE_FLOAT64_C(  587.52) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -515.61), SIMDE_FLOAT64_C(  144.37)),
      {SIMDE_FLOAT64_C(   144.37), SIMDE_FLOAT64_C( -515.61) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -183.60), SIMDE_FLOAT64_C(  483.36)),
      {SIMDE_FLOAT64_C(   483.36), SIMDE_FLOAT64_C( -183.60) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   33.37), SIMDE_FLOAT64_C( -802.26)),
      {SIMDE_FLOAT64_C(  -802.26), SIMDE_FLOAT64_C(   33.37) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -131.42), SIMDE_FLOAT64_C( -156.48)),
      {SIMDE_FLOAT64_C(  -156.48), SIMDE_FLOAT64_C( -131.42) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -317.87), SIMDE_FLOAT64_C(  140.87)),
      {SIMDE_FLOAT64_C(   140.87), SIMDE_FLOAT64_C( -317.87) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  924.07), SIMDE_FLOAT64_C(  709.42)),
      {SIMDE_FLOAT64_C(   709.42), SIMDE_FLOAT64_C(  924.07) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN_LIKE_16(simde__m128d) simde_float64 r[2];
    simde_mm_stream_pd(r, test_vec[i].a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_stream_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(   34091183), INT32_C(  572850908), INT32_C(  428781754), INT32_C(-1984722387)),
      simde_mm_set_epi32(INT32_C(   34091183), INT32_C(  572850908), INT32_C(  428781754), INT32_C(-1984722387)) },
    { simde_mm_set_epi32(INT32_C( 2059236852), INT32_C(  436410728), INT32_C(  338757718), INT32_C( 1985336145)),
      simde_mm_set_epi32(INT32_C( 2059236852), INT32_C(  436410728), INT32_C(  338757718), INT32_C( 1985336145)) },
    { simde_mm_set_epi32(INT32_C( -559686487), INT32_C(  981390363), INT32_C(  629822759), INT32_C(   26629572)),
      simde_mm_set_epi32(INT32_C( -559686487), INT32_C(  981390363), INT32_C(  629822759), INT32_C(   26629572)) },
    { simde_mm_set_epi32(INT32_C( 1401959784), INT32_C( -900492538), INT32_C( -328421218), INT32_C(  452144845)),
      simde_mm_set_epi32(INT32_C( 1401959784), INT32_C( -900492538), INT32_C( -328421218), INT32_C(  452144845)) },
    { simde_mm_set_epi32(INT32_C( 1914664610), INT32_C( 1467736241), INT32_C(-2062482935), INT32_C(-1765775255)),
      simde_mm_set_epi32(INT32_C( 1914664610), INT32_C( 1467736241), INT32_C(-2062482935), INT32_C(-1765775255)) },
    { simde_mm_set_epi32(INT32_C(  659730578), INT32_C(  874862437), INT32_C( -487086426), INT32_C(-1161523548)),
      simde_mm_set_epi32(INT32_C(  659730578), INT32_C(  874862437), INT32_C( -487086426), INT32_C(-1161523548)) },
    { simde_mm_set_epi32(INT32_C( 1195652072), INT32_C( -415424127), INT32_C(   77100736), INT32_C( 1699618155)),
      simde_mm_set_epi32(INT32_C( 1195652072), INT32_C( -415424127), INT32_C(   77100736), INT32_C( 1699618155)) },
    { simde_mm_set_epi32(INT32_C( 1626943139), INT32_C( 1327578602), INT32_C(-1477047999), INT32_C( 1569415359)),
      simde_mm_set_epi32(INT32_C( 1626943139), INT32_C( 1327578602), INT32_C(-1477047999), INT32_C( 1569415359)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    simde_mm_stream_si128(&r, test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_stream_si32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t a;
    int32_t r;
  } test_vec[8] = {
    {  -895547977,  -895547977 },
    {  1712937231,  1712937231 },
    { -1086654689, -1086654689 },
    {  1855506850,  1855506850 },
    {  1870001810,  1870001810 },
    {  -396094407,  -396094407 },
    { -1262223993, -1262223993 },
    {  2015532253,  2015532253 }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    int32_t r;
    simde_mm_stream_si32(&r, test_vec[i].a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_stream_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t a;
    int64_t r;
  } test_vec[8] = {
    { INT64_C( -908741869362791955), INT64_C( -908741869362791955) },
    { INT64_C( 6977779886002528513), INT64_C( 6977779886002528513) },
    { INT64_C(-3803748866185605675), INT64_C(-3803748866185605675) },
    { INT64_C( 9126491633461219066), INT64_C( 9126491633461219066) },
    { INT64_C(-1680016917440909978), INT64_C(-1680016917440909978) },
    { INT64_C( 9194247506078439345), INT64_C( 9194247506078439345) },
    { INT64_C(-5911248664473270680), INT64_C(-5911248664473270680) },
    { INT64_C(-9131883318362768052), INT64_C(-9131883318362768052) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    int64_t r;

    #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_NATIVE_ALIASES_TESTING)
      simde_mm_stream_si64(HEDLEY_REINTERPRET_CAST(long long int*, &r), test_vec[i].a);
    #else
      simde_mm_stream_si64(&r, test_vec[i].a);
    #endif

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sub_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-114), INT8_C(-102), INT8_C( -21), INT8_C(  93),
                        INT8_C(-120), INT8_C( 125), INT8_C( -36), INT8_C( -23),
                        INT8_C( -12), INT8_C(  11), INT8_C(  22), INT8_C(  78),
                        INT8_C( -16), INT8_C(  57), INT8_C(  71), INT8_C( 112)),
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -47), INT8_C(   8), INT8_C(  73),
                        INT8_C(  45), INT8_C(  37), INT8_C(  27), INT8_C( -63),
                        INT8_C( -74), INT8_C( -76), INT8_C( -34), INT8_C(  78),
                        INT8_C( -50), INT8_C( 121), INT8_C(-113), INT8_C(-123)),
      simde_mm_set_epi8(INT8_C( -99), INT8_C( -55), INT8_C( -29), INT8_C(  20),
                        INT8_C(  91), INT8_C(  88), INT8_C( -63), INT8_C(  40),
                        INT8_C(  62), INT8_C(  87), INT8_C(  56), INT8_C(   0),
                        INT8_C(  34), INT8_C( -64), INT8_C( -72), INT8_C( -21)) },
    { simde_mm_set_epi8(INT8_C( -71), INT8_C( -77), INT8_C( -40), INT8_C(  99),
                        INT8_C( -40), INT8_C(  24), INT8_C(  45), INT8_C( 125),
                        INT8_C(  16), INT8_C(  82), INT8_C( -66), INT8_C( -93),
                        INT8_C(  92), INT8_C(  60), INT8_C(  65), INT8_C(  70)),
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -11), INT8_C(  41), INT8_C(  35),
                        INT8_C(  87), INT8_C( -22), INT8_C( -28), INT8_C( -74),
                        INT8_C(  88), INT8_C(-100), INT8_C(  28), INT8_C( -30),
                        INT8_C( 122), INT8_C( -93), INT8_C( -11), INT8_C(  47)),
      simde_mm_set_epi8(INT8_C( -56), INT8_C( -66), INT8_C( -81), INT8_C(  64),
                        INT8_C(-127), INT8_C(  46), INT8_C(  73), INT8_C( -57),
                        INT8_C( -72), INT8_C( -74), INT8_C( -94), INT8_C( -63),
                        INT8_C( -30), INT8_C(-103), INT8_C(  76), INT8_C(  23)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(   7), INT8_C(  21), INT8_C(  40),
                        INT8_C( -45), INT8_C( -52), INT8_C( 105), INT8_C(   9),
                        INT8_C( -65), INT8_C( -48), INT8_C(  74), INT8_C( -11),
                        INT8_C(  71), INT8_C( -73), INT8_C( -92), INT8_C(-128)),
      simde_mm_set_epi8(INT8_C(  51), INT8_C( -25), INT8_C(  14), INT8_C( -31),
                        INT8_C( -75), INT8_C(  81), INT8_C( 123), INT8_C( -32),
                        INT8_C( -73), INT8_C(-121), INT8_C(  36), INT8_C( -43),
                        INT8_C(  95), INT8_C(  -5), INT8_C(  71), INT8_C( -67)),
      simde_mm_set_epi8(INT8_C(  37), INT8_C(  32), INT8_C(   7), INT8_C(  71),
                        INT8_C(  30), INT8_C( 123), INT8_C( -18), INT8_C(  41),
                        INT8_C(   8), INT8_C(  73), INT8_C(  38), INT8_C(  32),
                        INT8_C( -24), INT8_C( -68), INT8_C(  93), INT8_C( -61)) },
    { simde_mm_set_epi8(INT8_C( -26), INT8_C( -30), INT8_C(-127), INT8_C( -96),
                        INT8_C( -93), INT8_C(  85), INT8_C( -61), INT8_C(  31),
                        INT8_C(  84), INT8_C(  86), INT8_C(  14), INT8_C(  51),
                        INT8_C( -75), INT8_C( -80), INT8_C(  35), INT8_C(  49)),
      simde_mm_set_epi8(INT8_C(-102), INT8_C(  55), INT8_C( 103), INT8_C(  19),
                        INT8_C(-107), INT8_C( -66), INT8_C(-128), INT8_C(  92),
                        INT8_C(-108), INT8_C( -59), INT8_C( -55), INT8_C(  84),
                        INT8_C( -42), INT8_C(  42), INT8_C( -85), INT8_C( -73)),
      simde_mm_set_epi8(INT8_C(  76), INT8_C( -85), INT8_C(  26), INT8_C(-115),
                        INT8_C(  14), INT8_C(-105), INT8_C(  67), INT8_C( -61),
                        INT8_C( -64), INT8_C(-111), INT8_C(  69), INT8_C( -33),
                        INT8_C( -33), INT8_C(-122), INT8_C( 120), INT8_C( 122)) },
    { simde_mm_set_epi8(INT8_C( -92), INT8_C(  56), INT8_C( -22), INT8_C( -76),
                        INT8_C( -77), INT8_C(-116), INT8_C( -11), INT8_C(  34),
                        INT8_C(  -7), INT8_C(  37), INT8_C( -64), INT8_C( -72),
                        INT8_C(  28), INT8_C(-107), INT8_C(-128), INT8_C(-117)),
      simde_mm_set_epi8(INT8_C( -56), INT8_C(  -3), INT8_C(  32), INT8_C(  22),
                        INT8_C(  49), INT8_C(-125), INT8_C( 122), INT8_C(  -3),
                        INT8_C(-111), INT8_C(  65), INT8_C( -17), INT8_C(  15),
                        INT8_C( -83), INT8_C( -49), INT8_C(  13), INT8_C(  98)),
      simde_mm_set_epi8(INT8_C( -36), INT8_C(  59), INT8_C( -54), INT8_C( -98),
                        INT8_C(-126), INT8_C(   9), INT8_C( 123), INT8_C(  37),
                        INT8_C( 104), INT8_C( -28), INT8_C( -47), INT8_C( -87),
                        INT8_C( 111), INT8_C( -58), INT8_C( 115), INT8_C(  41)) },
    { simde_mm_set_epi8(INT8_C(-104), INT8_C(   9), INT8_C(  90), INT8_C( -26),
                        INT8_C(-114), INT8_C(-100), INT8_C( -19), INT8_C(  82),
                        INT8_C(  96), INT8_C(  58), INT8_C(  39), INT8_C(   9),
                        INT8_C(  -4), INT8_C(  91), INT8_C( -93), INT8_C( -73)),
      simde_mm_set_epi8(INT8_C(  16), INT8_C(   2), INT8_C(  -9), INT8_C( 107),
                        INT8_C(-122), INT8_C(-106), INT8_C(  -7), INT8_C(  11),
                        INT8_C( 116), INT8_C( -40), INT8_C(  -9), INT8_C( -94),
                        INT8_C(  61), INT8_C( -90), INT8_C(  69), INT8_C(   0)),
      simde_mm_set_epi8(INT8_C(-120), INT8_C(   7), INT8_C(  99), INT8_C( 123),
                        INT8_C(   8), INT8_C(   6), INT8_C( -12), INT8_C(  71),
                        INT8_C( -20), INT8_C(  98), INT8_C(  48), INT8_C( 103),
                        INT8_C( -65), INT8_C( -75), INT8_C(  94), INT8_C( -73)) },
    { simde_mm_set_epi8(INT8_C( -61), INT8_C( -71), INT8_C( 103), INT8_C(  76),
                        INT8_C(  44), INT8_C(  98), INT8_C(  70), INT8_C(-120),
                        INT8_C(  17), INT8_C( 126), INT8_C( -43), INT8_C( 108),
                        INT8_C( -31), INT8_C(  12), INT8_C( -92), INT8_C( -28)),
      simde_mm_set_epi8(INT8_C(-114), INT8_C(  71), INT8_C(  -5), INT8_C(  -9),
                        INT8_C(  -6), INT8_C( 117), INT8_C( -23), INT8_C( -62),
                        INT8_C( -10), INT8_C( -22), INT8_C( 106), INT8_C(  35),
                        INT8_C( -63), INT8_C(  18), INT8_C(  58), INT8_C(  22)),
      simde_mm_set_epi8(INT8_C(  53), INT8_C( 114), INT8_C( 108), INT8_C(  85),
                        INT8_C(  50), INT8_C( -19), INT8_C(  93), INT8_C( -58),
                        INT8_C(  27), INT8_C(-108), INT8_C( 107), INT8_C(  73),
                        INT8_C(  32), INT8_C(  -6), INT8_C( 106), INT8_C( -50)) },
    { simde_mm_set_epi8(INT8_C(  19), INT8_C( -54), INT8_C(  71), INT8_C(   0),
                        INT8_C( -13), INT8_C(  85), INT8_C( 113), INT8_C(   7),
                        INT8_C( -78), INT8_C(-122), INT8_C( -69), INT8_C( -15),
                        INT8_C( -57), INT8_C(  -9), INT8_C(-125), INT8_C(  84)),
      simde_mm_set_epi8(INT8_C( -78), INT8_C( 106), INT8_C(-106), INT8_C(  60),
                        INT8_C(  36), INT8_C( 103), INT8_C( -55), INT8_C(  69),
                        INT8_C(-119), INT8_C( -53), INT8_C(  67), INT8_C( -86),
                        INT8_C( -37), INT8_C( -20), INT8_C( -58), INT8_C( -28)),
      simde_mm_set_epi8(INT8_C(  97), INT8_C(  96), INT8_C( -79), INT8_C( -60),
                        INT8_C( -49), INT8_C( -18), INT8_C( -88), INT8_C( -62),
                        INT8_C(  41), INT8_C( -69), INT8_C( 120), INT8_C(  71),
                        INT8_C( -20), INT8_C(  11), INT8_C( -67), INT8_C( 112)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sub_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  4649), INT16_C(-10562), INT16_C(-25917), INT16_C(  9425),
                         INT16_C( 27983), INT16_C( -7888), INT16_C(  3337), INT16_C(-19608)),
      simde_mm_set_epi16(INT16_C(-13637), INT16_C( -2631), INT16_C( 26607), INT16_C( 19784),
                         INT16_C(-32723), INT16_C(-19066), INT16_C( 18245), INT16_C(-23690)),
      simde_mm_set_epi16(INT16_C( 18286), INT16_C( -7931), INT16_C( 13012), INT16_C(-10359),
                         INT16_C( -4830), INT16_C( 11178), INT16_C(-14908), INT16_C(  4082)) },
    { simde_mm_set_epi16(INT16_C(   708), INT16_C( 11434), INT16_C( -1239), INT16_C(-25521),
                         INT16_C(-21333), INT16_C( 14389), INT16_C(  1705), INT16_C( 20680)),
      simde_mm_set_epi16(INT16_C(-28483), INT16_C(  8156), INT16_C(-22073), INT16_C( 17984),
                         INT16_C( 20902), INT16_C(  3569), INT16_C( 31387), INT16_C(  7806)),
      simde_mm_set_epi16(INT16_C( 29191), INT16_C(  3278), INT16_C( 20834), INT16_C( 22031),
                         INT16_C( 23301), INT16_C( 10820), INT16_C(-29682), INT16_C( 12874)) },
    { simde_mm_set_epi16(INT16_C( -3626), INT16_C(   757), INT16_C(   189), INT16_C(-19968),
                         INT16_C(  5676), INT16_C(  7663), INT16_C(  8524), INT16_C( 15372)),
      simde_mm_set_epi16(INT16_C( 20254), INT16_C(-31977), INT16_C( 18332), INT16_C(-14379),
                         INT16_C( -7613), INT16_C( 19737), INT16_C( 22035), INT16_C( -6952)),
      simde_mm_set_epi16(INT16_C(-23880), INT16_C( 32734), INT16_C(-18143), INT16_C( -5589),
                         INT16_C( 13289), INT16_C(-12074), INT16_C(-13511), INT16_C( 22324)) },
    { simde_mm_set_epi16(INT16_C(-12411), INT16_C( 25999), INT16_C(  8485), INT16_C( -8542),
                         INT16_C( 21018), INT16_C(-31213), INT16_C( 15766), INT16_C( 18574)),
      simde_mm_set_epi16(INT16_C(  6484), INT16_C(-10154), INT16_C( 20175), INT16_C( 32085),
                         INT16_C( 18950), INT16_C(-19405), INT16_C(-12089), INT16_C(  8199)),
      simde_mm_set_epi16(INT16_C(-18895), INT16_C(-29383), INT16_C(-11690), INT16_C( 24909),
                         INT16_C(  2068), INT16_C(-11808), INT16_C( 27855), INT16_C( 10375)) },
    { simde_mm_set_epi16(INT16_C(  7148), INT16_C(-25537), INT16_C(  5647), INT16_C(-25529),
                         INT16_C( -5324), INT16_C(-12025), INT16_C( 27072), INT16_C(-30360)),
      simde_mm_set_epi16(INT16_C(-24506), INT16_C( -9630), INT16_C( 25801), INT16_C( 32734),
                         INT16_C(  1516), INT16_C( 10059), INT16_C( 10693), INT16_C( 13623)),
      simde_mm_set_epi16(INT16_C( 31654), INT16_C(-15907), INT16_C(-20154), INT16_C(  7273),
                         INT16_C( -6840), INT16_C(-22084), INT16_C( 16379), INT16_C( 21553)) },
    { simde_mm_set_epi16(INT16_C(-24730), INT16_C(-23496), INT16_C(-16567), INT16_C(-13323),
                         INT16_C(-12986), INT16_C(-31808), INT16_C( 27730), INT16_C( -2264)),
      simde_mm_set_epi16(INT16_C(-13737), INT16_C(-18451), INT16_C(-16289), INT16_C( 22307),
                         INT16_C( -2961), INT16_C( 22412), INT16_C( 13917), INT16_C(  8259)),
      simde_mm_set_epi16(INT16_C(-10993), INT16_C( -5045), INT16_C(  -278), INT16_C( 29906),
                         INT16_C(-10025), INT16_C( 11316), INT16_C( 13813), INT16_C(-10523)) },
    { simde_mm_set_epi16(INT16_C(  5718), INT16_C( 31027), INT16_C( 29094), INT16_C(  1906),
                         INT16_C( -3938), INT16_C( -2339), INT16_C(-13536), INT16_C( 11931)),
      simde_mm_set_epi16(INT16_C(-23545), INT16_C(  2546), INT16_C( -2953), INT16_C( -8072),
                         INT16_C( 28237), INT16_C(-11239), INT16_C(-13996), INT16_C( 29497)),
      simde_mm_set_epi16(INT16_C( 29263), INT16_C( 28481), INT16_C( 32047), INT16_C(  9978),
                         INT16_C(-32175), INT16_C(  8900), INT16_C(   460), INT16_C(-17566)) },
    { simde_mm_set_epi16(INT16_C( 29491), INT16_C(-30965), INT16_C(  4748), INT16_C(-28809),
                         INT16_C(-21877), INT16_C(-21669), INT16_C(-28233), INT16_C(-28758)),
      simde_mm_set_epi16(INT16_C(  5029), INT16_C(  4694), INT16_C(-16956), INT16_C(-15561),
                         INT16_C(-23049), INT16_C(-31774), INT16_C(  3835), INT16_C(-12557)),
      simde_mm_set_epi16(INT16_C( 24462), INT16_C( 29877), INT16_C( 21704), INT16_C(-13248),
                         INT16_C(  1172), INT16_C( 10105), INT16_C(-32068), INT16_C(-16201)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sub_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  304731838, -1698487087,  1833951536,   218739560),
      simde_mm_set_epi32( -893651527,  1743736136, -2144488058,  1195746166),
      simde_mm_set_epi32( 1198383365,   852744073,  -316527702,  -977006606) },
    { simde_mm_set_epi32(   46410922,   -81159089, -1398065099,   111759560),
      simde_mm_set_epi32(-1866653732, -1446558144,  1369837041,  2056986238),
      simde_mm_set_epi32( 1913064654,  1365399055,  1527065156, -1945226678) },
    { simde_mm_set_epi32( -237632779,    12431872,   371989999,   558644236),
      simde_mm_set_epi32( 1327399703,  1201457109,  -498905831,  1444144344),
      simde_mm_set_epi32(-1565032482, -1189025237,   870895830,  -885500108) },
    { simde_mm_set_epi32( -813341297,   556129954,  1377469971,  1033259150),
      simde_mm_set_epi32(  424990806,  1322220885,  1241953331,  -792256505),
      simde_mm_set_epi32(-1238332103,  -766090931,   135516640,  1825515655) },
    { simde_mm_set_epi32(  468491327,   370121799,  -348860153,  1774225768),
      simde_mm_set_epi32(-1605969310,  1690927070,    99362635,   700790071),
      simde_mm_set_epi32( 2074460637, -1320805271,  -448222788,  1073435697) },
    { simde_mm_set_epi32(-1620663240, -1085682699,  -851016768,  1817376552),
      simde_mm_set_epi32( -900220947, -1067493597,  -194029684,   912072771),
      simde_mm_set_epi32( -720442293,   -18189102,  -656987084,   905303781) },
    { simde_mm_set_epi32(  374765875,  1906706290,  -258017571,  -887083365),
      simde_mm_set_epi32(-1543042574,  -193470344,  1850594329,  -917212359),
      simde_mm_set_epi32( 1917808449,  2100176634, -2108611900,    30128994) },
    { simde_mm_set_epi32( 1932756747,   311201655, -1433687205, -1850241110),
      simde_mm_set_epi32(  329585238, -1111178441, -1510505502,   251383539),
      simde_mm_set_epi32( 1603171509,  1422380096,    76818297, -2101624649) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sub_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-5763845342482697816), INT64_C( 2103077785434280804)),
      simde_mm_set_epi64x(INT64_C(  -84933559585222060), INT64_C(-2626653918467514964)),
      simde_mm_set_epi64x(INT64_C(-5678911782897475756), INT64_C( 4729731703901795768)) },
    { simde_mm_set_epi64x(INT64_C( 1527789798480118137), INT64_C( 8436112421047310932)),
      simde_mm_set_epi64x(INT64_C(-1700732467797798250), INT64_C(-3973336518996013340)),
      simde_mm_set_epi64x(INT64_C( 3228522266277916387), INT64_C(-6037295133666227344)) },
    { simde_mm_set_epi64x(INT64_C( 4851345631989659335), INT64_C(-7206764788471565568)),
      simde_mm_set_epi64x(INT64_C( 5406657072094052149), INT64_C( 1553917979932899417)),
      simde_mm_set_epi64x(INT64_C( -555311440104392814), INT64_C(-8760682768404464985)) },
    { simde_mm_set_epi64x(INT64_C( 4880585840903485916), INT64_C(-3214111508108965857)),
      simde_mm_set_epi64x(INT64_C(-9030069389987018552), INT64_C(-3395779442469856546)),
      simde_mm_set_epi64x(INT64_C(-4536088842819047148), INT64_C(  181667934360890689)) },
    { simde_mm_set_epi64x(INT64_C( 5848110560047382754), INT64_C( 5491947693722128435)),
      simde_mm_set_epi64x(INT64_C(  213782131019667117), INT64_C( -937970910639813333)),
      simde_mm_set_epi64x(INT64_C( 5634328429027715637), INT64_C( 6429918604361941768)) },
    { simde_mm_set_epi64x(INT64_C(-1470278109522038956), INT64_C(-7185464081677005028)),
      simde_mm_set_epi64x(INT64_C( 7512013344600346304), INT64_C(-1151368750409397152)),
      simde_mm_set_epi64x(INT64_C(-8982291454122385260), INT64_C(-6034095331267607876)) },
    { simde_mm_set_epi64x(INT64_C(-1414880571892272072), INT64_C(-5464559564131319132)),
      simde_mm_set_epi64x(INT64_C(-8460263392275774431), INT64_C( 3444946385257741717)),
      simde_mm_set_epi64x(INT64_C( 7045382820383502359), INT64_C(-8909505949389060849)) },
    { simde_mm_set_epi64x(INT64_C( 2041037654020608990), INT64_C(-5135476174064773616)),
      simde_mm_set_epi64x(INT64_C(-2250411574230731306), INT64_C( 6301008926808412830)),
      simde_mm_set_epi64x(INT64_C( 4291449228251340296), INT64_C( 7010258972836365170)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_sub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -989.09), SIMDE_FLOAT64_C(  415.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -630.71), SIMDE_FLOAT64_C(  755.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -358.38), SIMDE_FLOAT64_C( -339.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -609.69), SIMDE_FLOAT64_C( -266.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  904.74), SIMDE_FLOAT64_C(  704.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1514.43), SIMDE_FLOAT64_C( -970.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -864.69), SIMDE_FLOAT64_C( -728.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -549.96), SIMDE_FLOAT64_C(  478.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -314.73), SIMDE_FLOAT64_C(-1206.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.45), SIMDE_FLOAT64_C( -593.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -648.70), SIMDE_FLOAT64_C( -195.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   41.24), SIMDE_FLOAT64_C( -398.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -442.58), SIMDE_FLOAT64_C( -296.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  195.46), SIMDE_FLOAT64_C(  287.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -638.04), SIMDE_FLOAT64_C( -583.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -930.71), SIMDE_FLOAT64_C(  996.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -786.74), SIMDE_FLOAT64_C(   77.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -143.98), SIMDE_FLOAT64_C(  918.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.75), SIMDE_FLOAT64_C(  -28.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  970.37), SIMDE_FLOAT64_C( -443.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -267.62), SIMDE_FLOAT64_C(  415.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -369.79), SIMDE_FLOAT64_C(  539.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -404.57), SIMDE_FLOAT64_C( -587.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   34.78), SIMDE_FLOAT64_C( 1127.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_sub_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -989.09), SIMDE_FLOAT64_C(  415.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -630.71), SIMDE_FLOAT64_C(  755.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -989.09), SIMDE_FLOAT64_C( -339.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -609.69), SIMDE_FLOAT64_C( -266.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  904.74), SIMDE_FLOAT64_C(  704.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -609.69), SIMDE_FLOAT64_C( -970.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -864.69), SIMDE_FLOAT64_C( -728.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -549.96), SIMDE_FLOAT64_C(  478.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -864.69), SIMDE_FLOAT64_C(-1206.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.45), SIMDE_FLOAT64_C( -593.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -648.70), SIMDE_FLOAT64_C( -195.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -607.45), SIMDE_FLOAT64_C( -398.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -442.58), SIMDE_FLOAT64_C( -296.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  195.46), SIMDE_FLOAT64_C(  287.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -442.58), SIMDE_FLOAT64_C( -583.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -930.71), SIMDE_FLOAT64_C(  996.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -786.74), SIMDE_FLOAT64_C(   77.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -930.71), SIMDE_FLOAT64_C(  918.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.75), SIMDE_FLOAT64_C(  -28.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  970.37), SIMDE_FLOAT64_C( -443.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.75), SIMDE_FLOAT64_C(  415.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -369.79), SIMDE_FLOAT64_C(  539.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -404.57), SIMDE_FLOAT64_C( -587.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -369.79), SIMDE_FLOAT64_C( 1127.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sub_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_sub_si64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  -40015113898169895)),
      simde_mm_cvtsi64_m64(INT64_C( 3843942487505240466)),
      simde_mm_cvtsi64_m64(INT64_C(-3883957601403410361)), },
    { simde_mm_cvtsi64_m64(INT64_C( 8317116700671824816)),
      simde_mm_cvtsi64_m64(INT64_C( 2891842609034633421)),
      simde_mm_cvtsi64_m64(INT64_C( 5425274091637191395)), },
    { simde_mm_cvtsi64_m64(INT64_C(  922042182678065366)),
      simde_mm_cvtsi64_m64(INT64_C( 4937799652981992213)),
      simde_mm_cvtsi64_m64(INT64_C(-4015757470303926847)), },
    { simde_mm_cvtsi64_m64(INT64_C(  297526191920431793)),
      simde_mm_cvtsi64_m64(INT64_C(-8568639315346032946)),
      simde_mm_cvtsi64_m64(INT64_C( 8866165507266464739)), },
    { simde_mm_cvtsi64_m64(INT64_C(  944913740190663659)),
      simde_mm_cvtsi64_m64(INT64_C(-5569388163200780530)),
      simde_mm_cvtsi64_m64(INT64_C( 6514301903391444189)), },
    { simde_mm_cvtsi64_m64(INT64_C( 2756927115722410076)),
      simde_mm_cvtsi64_m64(INT64_C( 1302679549898517242)),
      simde_mm_cvtsi64_m64(INT64_C( 1454247565823892834)), },
    { simde_mm_cvtsi64_m64(INT64_C(  977005230827305840)),
      simde_mm_cvtsi64_m64(INT64_C( 4908563834369883454)),
      simde_mm_cvtsi64_m64(INT64_C(-3931558603542577614)), },
    { simde_mm_cvtsi64_m64(INT64_C(-7062092201406124762)),
      simde_mm_cvtsi64_m64(INT64_C( 2377066878085823882)),
      simde_mm_cvtsi64_m64(INT64_C( 9007584994217602972)), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sub_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_subs_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  77), INT8_C( -15), INT8_C( -74), INT8_C(  52), INT8_C( -61), INT8_C(  64), INT8_C(  59), INT8_C(  21),
                        INT8_C( -60), INT8_C( -67), INT8_C( -73), INT8_C( 104), INT8_C(  30), INT8_C( 107), INT8_C(  83), INT8_C(-117)),
      simde_mm_set_epi8(INT8_C(-110), INT8_C(-112), INT8_C( -53), INT8_C(  89), INT8_C(  74), INT8_C(  81), INT8_C( -22), INT8_C( -97),
                        INT8_C(-128), INT8_C( -54), INT8_C( 101), INT8_C(  96), INT8_C(  36), INT8_C(  87), INT8_C(-125), INT8_C(  28)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(  97), INT8_C( -21), INT8_C( -37), INT8_C(-128), INT8_C( -17), INT8_C(  81), INT8_C( 118),
                        INT8_C(  68), INT8_C( -13), INT8_C(-128), INT8_C(   8), INT8_C(  -6), INT8_C(  20), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C(  57), INT8_C(  79), INT8_C( 101), INT8_C(  47), INT8_C(  60), INT8_C(  12), INT8_C(   0), INT8_C( -19),
                        INT8_C(  63), INT8_C(  39), INT8_C(-108), INT8_C(  37), INT8_C(  92), INT8_C( 114), INT8_C(-110), INT8_C(  91)),
      simde_mm_set_epi8(INT8_C( -59), INT8_C( -81), INT8_C(  49), INT8_C( 126), INT8_C(  33), INT8_C( 120), INT8_C(-127), INT8_C(  80),
                        INT8_C( 109), INT8_C(-100), INT8_C(  21), INT8_C(-125), INT8_C(   7), INT8_C(  60), INT8_C(-122), INT8_C( -61)),
      simde_mm_set_epi8(INT8_C( 116), INT8_C( 127), INT8_C(  52), INT8_C( -79), INT8_C(  27), INT8_C(-108), INT8_C( 127), INT8_C( -99),
                        INT8_C( -46), INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(  85), INT8_C(  54), INT8_C(  12), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C(  84), INT8_C(-104), INT8_C( -82), INT8_C( 105), INT8_C( -43), INT8_C( -36), INT8_C(  16), INT8_C( -15),
                        INT8_C( -34), INT8_C( 120), INT8_C(-110), INT8_C(  90), INT8_C(  78), INT8_C(  45), INT8_C(-124), INT8_C( -84)),
      simde_mm_set_epi8(INT8_C( -66), INT8_C(  -1), INT8_C(  91), INT8_C(  74), INT8_C(  83), INT8_C( -91), INT8_C( -97), INT8_C( 115),
                        INT8_C( -29), INT8_C(  67), INT8_C( -98), INT8_C( -51), INT8_C( 110), INT8_C( -43), INT8_C( 125), INT8_C(  63)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-103), INT8_C(-128), INT8_C(  31), INT8_C(-126), INT8_C(  55), INT8_C( 113), INT8_C(-128),
                        INT8_C(  -5), INT8_C(  53), INT8_C( -12), INT8_C( 127), INT8_C( -32), INT8_C(  88), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C( -75), INT8_C(  37), INT8_C( 126), INT8_C(  21), INT8_C(  92), INT8_C(-124), INT8_C( -81), INT8_C(  -6),
                        INT8_C(-117), INT8_C( -14), INT8_C(  38), INT8_C( -68), INT8_C( -45), INT8_C( 114), INT8_C(  32), INT8_C( -13)),
      simde_mm_set_epi8(INT8_C(  80), INT8_C(-123), INT8_C( -25), INT8_C(  71), INT8_C(-108), INT8_C( -31), INT8_C(  98), INT8_C( -67),
                        INT8_C( -23), INT8_C(-112), INT8_C( -42), INT8_C( -16), INT8_C( -56), INT8_C( 107), INT8_C(   6), INT8_C(  16)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( -50), INT8_C( 127), INT8_C( -93), INT8_C(-128), INT8_C(  61),
                        INT8_C( -94), INT8_C(  98), INT8_C(  80), INT8_C( -52), INT8_C(  11), INT8_C(   7), INT8_C(  26), INT8_C( -29)) },
    { simde_mm_set_epi8(INT8_C(  85), INT8_C(  18), INT8_C(  15), INT8_C( 100), INT8_C( 107), INT8_C( -69), INT8_C( -96), INT8_C( -20),
                        INT8_C( -18), INT8_C(  42), INT8_C(  98), INT8_C( 104), INT8_C( -70), INT8_C(-121), INT8_C( -91), INT8_C(  77)),
      simde_mm_set_epi8(INT8_C( 103), INT8_C( -62), INT8_C( 107), INT8_C(-125), INT8_C( -86), INT8_C(-112), INT8_C( -45), INT8_C(   3),
                        INT8_C( -26), INT8_C(  96), INT8_C(  83), INT8_C(  23), INT8_C( 100), INT8_C( 127), INT8_C( -56), INT8_C( -52)),
      simde_mm_set_epi8(INT8_C( -18), INT8_C(  80), INT8_C( -92), INT8_C( 127), INT8_C( 127), INT8_C(  43), INT8_C( -51), INT8_C( -23),
                        INT8_C(   8), INT8_C( -54), INT8_C(  15), INT8_C(  81), INT8_C(-128), INT8_C(-128), INT8_C( -35), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C(  63), INT8_C(  16), INT8_C( 100), INT8_C( -10), INT8_C(  78), INT8_C( 116), INT8_C( -91), INT8_C(  21),
                        INT8_C( -10), INT8_C( -27), INT8_C( -92), INT8_C(  31), INT8_C( -23), INT8_C( -53), INT8_C(  -1), INT8_C(  -1)),
      simde_mm_set_epi8(INT8_C(  20), INT8_C(-123), INT8_C(  36), INT8_C( -10), INT8_C( 127), INT8_C(-111), INT8_C( -60), INT8_C(  54),
                        INT8_C(  92), INT8_C( 101), INT8_C( -13), INT8_C( -31), INT8_C(-124), INT8_C( 112), INT8_C(-118), INT8_C( -29)),
      simde_mm_set_epi8(INT8_C(  43), INT8_C( 127), INT8_C(  64), INT8_C(   0), INT8_C( -49), INT8_C( 127), INT8_C( -31), INT8_C( -33),
                        INT8_C(-102), INT8_C(-128), INT8_C( -79), INT8_C(  62), INT8_C( 101), INT8_C(-128), INT8_C( 117), INT8_C(  28)) },
    { simde_mm_set_epi8(INT8_C(   1), INT8_C( -28), INT8_C( -45), INT8_C( -32), INT8_C(-103), INT8_C(  27), INT8_C( -38), INT8_C(-127),
                        INT8_C( -89), INT8_C( -74), INT8_C(  47), INT8_C(  91), INT8_C(  46), INT8_C( -24), INT8_C(  60), INT8_C(  23)),
      simde_mm_set_epi8(INT8_C( -25), INT8_C( -68), INT8_C(-116), INT8_C(  92), INT8_C(  33), INT8_C(  -5), INT8_C( -35), INT8_C( -44),
                        INT8_C(  -9), INT8_C( -90), INT8_C(  63), INT8_C( 108), INT8_C(  36), INT8_C(  27), INT8_C( 112), INT8_C( -11)),
      simde_mm_set_epi8(INT8_C(  26), INT8_C(  40), INT8_C(  71), INT8_C(-124), INT8_C(-128), INT8_C(  32), INT8_C(  -3), INT8_C( -83),
                        INT8_C( -80), INT8_C(  16), INT8_C( -16), INT8_C( -17), INT8_C(  10), INT8_C( -51), INT8_C( -52), INT8_C(  34)) },
    { simde_mm_set_epi8(INT8_C(  29), INT8_C( 123), INT8_C(  -8), INT8_C( -35), INT8_C(   3), INT8_C( -97), INT8_C( 124), INT8_C(-121),
                        INT8_C(  52), INT8_C(  75), INT8_C( -93), INT8_C(-127), INT8_C( -78), INT8_C(  87), INT8_C( 102), INT8_C( 119)),
      simde_mm_set_epi8(INT8_C(  51), INT8_C( -89), INT8_C(  -6), INT8_C(   8), INT8_C( -19), INT8_C( -88), INT8_C(  22), INT8_C(  21),
                        INT8_C( -37), INT8_C( -42), INT8_C( -97), INT8_C(  58), INT8_C(  70), INT8_C( -92), INT8_C(-100), INT8_C(-124)),
      simde_mm_set_epi8(INT8_C( -22), INT8_C( 127), INT8_C(  -2), INT8_C( -43), INT8_C(  22), INT8_C(  -9), INT8_C( 102), INT8_C(-128),
                        INT8_C(  89), INT8_C( 117), INT8_C(   4), INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_subs_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  3087), INT16_C(-11046), INT16_C( 16009), INT16_C( -2784),
                         INT16_C( 23836), INT16_C(   341), INT16_C( 25120), INT16_C(   792)),
      simde_mm_set_epi16(INT16_C(-13938), INT16_C( 11942), INT16_C( 18967), INT16_C(-24666),
                         INT16_C(-12194), INT16_C(-15141), INT16_C( 27868), INT16_C(  7667)),
      simde_mm_set_epi16(INT16_C( 17025), INT16_C(-22988), INT16_C( -2958), INT16_C( 21882),
                         INT16_C( 32767), INT16_C( 15482), INT16_C( -2748), INT16_C( -6875)) },
    { simde_mm_set_epi16(INT16_C( 15944), INT16_C( 21174), INT16_C(-19487), INT16_C( 30166),
                         INT16_C(  9880), INT16_C(  2293), INT16_C(  1544), INT16_C(  6216)),
      simde_mm_set_epi16(INT16_C(-22637), INT16_C( 27460), INT16_C( 16112), INT16_C(-21899),
                         INT16_C( 28784), INT16_C(  -234), INT16_C( -5361), INT16_C( 25377)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C( -6286), INT16_C(-32768), INT16_C( 32767),
                         INT16_C(-18904), INT16_C(  2527), INT16_C(  6905), INT16_C(-19161)) },
    { simde_mm_set_epi16(INT16_C( 25177), INT16_C( 16000), INT16_C(-30398), INT16_C(-17760),
                         INT16_C( 16727), INT16_C( -4856), INT16_C(-10813), INT16_C( 11418)),
      simde_mm_set_epi16(INT16_C( 25832), INT16_C(-14964), INT16_C( 17267), INT16_C( -2360),
                         INT16_C( 15960), INT16_C( 12601), INT16_C(  9707), INT16_C( 24108)),
      simde_mm_set_epi16(INT16_C(  -655), INT16_C( 30964), INT16_C(-32768), INT16_C(-15400),
                         INT16_C(   767), INT16_C(-17457), INT16_C(-20520), INT16_C(-12690)) },
    { simde_mm_set_epi16(INT16_C(-19601), INT16_C(-21914), INT16_C(-30623), INT16_C( -8160),
                         INT16_C( 24427), INT16_C(-16073), INT16_C( 14239), INT16_C( 20391)),
      simde_mm_set_epi16(INT16_C(-19582), INT16_C(-27440), INT16_C( -9450), INT16_C(-25104),
                         INT16_C( 11842), INT16_C(  4749), INT16_C(  3094), INT16_C( 19163)),
      simde_mm_set_epi16(INT16_C(   -19), INT16_C(  5526), INT16_C(-21173), INT16_C( 16944),
                         INT16_C( 12585), INT16_C(-20822), INT16_C( 11145), INT16_C(  1228)) },
    { simde_mm_set_epi16(INT16_C(-10118), INT16_C( 25388), INT16_C(-18110), INT16_C( -8312),
                         INT16_C(  5249), INT16_C( 27800), INT16_C(  2023), INT16_C(   338)),
      simde_mm_set_epi16(INT16_C( 14501), INT16_C( 30804), INT16_C( 26885), INT16_C(-32444),
                         INT16_C(-27012), INT16_C(-14925), INT16_C(-31013), INT16_C( 10807)),
      simde_mm_set_epi16(INT16_C(-24619), INT16_C( -5416), INT16_C(-32768), INT16_C( 24132),
                         INT16_C( 32261), INT16_C( 32767), INT16_C( 32767), INT16_C(-10469)) },
    { simde_mm_set_epi16(INT16_C(-17246), INT16_C(-28624), INT16_C( 13423), INT16_C( 27394),
                         INT16_C(  7877), INT16_C(-20368), INT16_C(-24205), INT16_C(-15569)),
      simde_mm_set_epi16(INT16_C(-21987), INT16_C( -4056), INT16_C(  2917), INT16_C( 23573),
                         INT16_C( -2283), INT16_C( 21821), INT16_C( 32369), INT16_C( 26504)),
      simde_mm_set_epi16(INT16_C(  4741), INT16_C(-24568), INT16_C( 10506), INT16_C(  3821),
                         INT16_C( 10160), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi16(INT16_C(-10290), INT16_C( 29918), INT16_C(-29258), INT16_C(-28749),
                         INT16_C(  6048), INT16_C(-25677), INT16_C( 24207), INT16_C(   366)),
      simde_mm_set_epi16(INT16_C( 13339), INT16_C(-11229), INT16_C( 23811), INT16_C(  -333),
                         INT16_C(-29847), INT16_C( 21714), INT16_C(  2843), INT16_C( -2618)),
      simde_mm_set_epi16(INT16_C(-23629), INT16_C( 32767), INT16_C(-32768), INT16_C(-28416),
                         INT16_C( 32767), INT16_C(-32768), INT16_C( 21364), INT16_C(  2984)) },
    { simde_mm_set_epi16(INT16_C(   824), INT16_C( 19299), INT16_C(-14246), INT16_C(-19942),
                         INT16_C( 17549), INT16_C(  5220), INT16_C(-11590), INT16_C(-29570)),
      simde_mm_set_epi16(INT16_C( 30144), INT16_C(-11230), INT16_C(-24828), INT16_C( 29586),
                         INT16_C( 29999), INT16_C( 25519), INT16_C(  5645), INT16_C( 16976)),
      simde_mm_set_epi16(INT16_C(-29320), INT16_C( 30529), INT16_C( 10582), INT16_C(-32768),
                         INT16_C(-12450), INT16_C(-20299), INT16_C(-17235), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_subs_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8( 29,  76, 238,  61, 229, 243, 175, 238,
                           75,  27, 166, 154, 166, 157, 121, 248),
      simde_x_mm_set_epu8(129,  19, 253, 149,   9, 247,  10, 249,
                          105, 205, 179, 225, 124, 146,  91, 221),
      simde_x_mm_set_epu8(  0,  57,   0,   0, 220,   0, 165,   0,
                            0,   0,   0,   0,  42,  11,  30,  27) },
    { simde_x_mm_set_epu8(101, 150, 221,  18, 105, 115, 165,  92,
                          211,  64,  38,  72, 139,   6,  65, 201),
      simde_x_mm_set_epu8(124, 107, 110,  57, 116, 209, 153,  76,
                          122,  56,  60, 234, 120, 132,   4,  95),
      simde_x_mm_set_epu8(  0,  43, 111,   0,   0,   0,  12,  16,
                           89,   8,   0,   0,  19,   0,  61, 106) },
    { simde_x_mm_set_epu8(198, 232, 134,  13, 155, 189, 203,  84,
                          209, 255, 163, 211,  57, 177,  19,  86),
      simde_x_mm_set_epu8(205,  92, 216, 169, 196, 192,  93, 101,
                          208, 230, 232,  36,  70, 151, 125,  72),
      simde_x_mm_set_epu8(  0, 140,   0,   0,   0,   0, 110,   0,
                            1,  25,   0, 175,   0,  26,   0,  14) },
    { simde_x_mm_set_epu8(150, 141, 253,  10, 218, 100, 243,  17,
                           87,  99, 224, 222, 198, 181,  26,  41),
      simde_x_mm_set_epu8(221, 130, 146,  56,  57, 169,  46,  50,
                          234,  43,   8, 172,  95,  74,  51, 101),
      simde_x_mm_set_epu8(  0,  11, 107,   0, 161,   0, 197,   0,
                            0,  56, 216,  50, 103, 107,   0,   0) },
    { simde_x_mm_set_epu8( 91, 188, 127, 216,  55, 208,  83,  14,
                          153, 114,  48, 224,  59,  66, 100,  10),
      simde_x_mm_set_epu8( 88,  28,  13,  17,  78,  38,   8, 111,
                           57,  44, 184,  85, 188, 182, 235, 151),
      simde_x_mm_set_epu8(  3, 160, 114, 199,   0, 170,  75,   0,
                           96,  70,   0, 139,   0,   0,   0,   0) },
    { simde_x_mm_set_epu8(116,  32, 155, 196,  56,  42,  17, 217,
                           51, 162,   4,   4, 150,  83,  16, 147),
      simde_x_mm_set_epu8(216, 235, 181, 255,  89, 143,  40,  48,
                           52,  24, 160,   9, 162, 223, 243, 117),
      simde_x_mm_set_epu8(  0,   0,   0,   0,   0,   0,   0, 169,
                            0, 138,   0,   0,   0,   0,   0,  30) },
    { simde_x_mm_set_epu8(217, 238, 218, 168,  98, 146,  87, 217,
                          135, 103, 179, 182, 128,  74, 156,   3),
      simde_x_mm_set_epu8(157,   0, 179, 231, 176,  37, 226, 198,
                          145, 138, 239, 164,   0, 170,  52,  61),
      simde_x_mm_set_epu8( 60, 238,  39,   0,   0, 109,   0,  19,
                            0,   0,   0,  18, 128,   0, 104,   0) },
    { simde_x_mm_set_epu8(181,  83, 160, 141,  77, 119, 160, 171,
                          112,  95,  47,  88,   0,  90, 237,  18),
      simde_x_mm_set_epu8(139, 146,  25, 173,  34,  31, 251, 200,
                          190, 131,  23,  41, 246,  91,  98, 221),
      simde_x_mm_set_epu8( 42,   0, 135,   0,  43,  88,   0,   0,
                            0,   0,  24,  47,   0,   0, 139,   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_subs_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(55440, 59202, 42058, 53369, 32796,  7917, 33818, 17136),
      simde_x_mm_set_epu16(26104, 52689, 47050, 39249, 59785, 38246, 31610, 10518),
      simde_x_mm_set_epu16(29336,  6513,     0, 14120,     0,     0,  2208,  6618) },
    { simde_x_mm_set_epu16(34216, 34652, 60066, 36214,  4826, 65416, 55052, 33573),
      simde_x_mm_set_epu16(26443, 15803,  4000, 33420, 50076, 27556,  5522, 41665),
      simde_x_mm_set_epu16( 7773, 18849, 56066,  2794,     0, 37860, 49530,     0) },
    { simde_x_mm_set_epu16(64499, 21603, 35445, 16287, 15728, 23400, 23336, 39270),
      simde_x_mm_set_epu16(56255, 54924, 45249, 41636, 27152, 13319, 19428,   768),
      simde_x_mm_set_epu16( 8244,     0,     0,     0,     0, 10081,  3908, 38502) },
    { simde_x_mm_set_epu16( 1242, 22793, 21812, 57045, 22651, 26751, 59072, 30159),
      simde_x_mm_set_epu16(11521, 44413, 36849,   788, 57441, 54148,  2979, 46303),
      simde_x_mm_set_epu16(    0,     0,     0, 56257,     0,     0, 56093,     0) },
    { simde_x_mm_set_epu16(37620, 40488, 64998, 40075, 44204, 34122, 59592, 65445),
      simde_x_mm_set_epu16(40351, 64891, 27393, 62063,  1981, 56033, 30691, 62006),
      simde_x_mm_set_epu16(    0,     0, 37605,     0, 42223,     0, 28901,  3439) },
    { simde_x_mm_set_epu16(65230, 30209, 16765,  1470, 31101, 49860, 26882, 55440),
      simde_x_mm_set_epu16(49049, 44537, 10442, 42049,   271, 49034, 11746,  5994),
      simde_x_mm_set_epu16(16181,     0,  6323,     0, 30830,   826, 15136, 49446) },
    { simde_x_mm_set_epu16(37013,  9547, 22144, 27612, 32177, 62691, 50927, 50782),
      simde_x_mm_set_epu16(18153,  2530, 10375, 48140,  7056, 62459, 20700, 31971),
      simde_x_mm_set_epu16(18860,  7017, 11769,     0, 25121,   232, 30227, 18811) },
    { simde_x_mm_set_epu16( 9831, 28967, 28080, 17470, 59616, 18625, 64250, 31724),
      simde_x_mm_set_epu16(52094, 35298, 55420,  3659, 42707, 55727, 29250, 17787),
      simde_x_mm_set_epu16(    0,     0,     0, 13811, 16909,     0, 35000, 13937) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomieq_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomieq_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomige_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  214.53), SIMDE_FLOAT64_C(  606.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  814.33), SIMDE_FLOAT64_C(  606.90)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -487.58), SIMDE_FLOAT64_C(  444.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -781.36), SIMDE_FLOAT64_C(   30.46)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  605.28), SIMDE_FLOAT64_C( -943.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -943.32), SIMDE_FLOAT64_C( -943.32)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -981.47), SIMDE_FLOAT64_C(   31.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   31.75), SIMDE_FLOAT64_C(  299.12)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  480.83), SIMDE_FLOAT64_C(  255.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  946.90), SIMDE_FLOAT64_C(  608.16)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  634.58), SIMDE_FLOAT64_C(  320.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  320.38), SIMDE_FLOAT64_C(  942.24)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   98.67), SIMDE_FLOAT64_C(  118.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  118.05), SIMDE_FLOAT64_C(  118.05)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  544.57), SIMDE_FLOAT64_C(  783.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  636.80), SIMDE_FLOAT64_C(  783.14)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomige_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomigt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomigt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomile_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomile_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_ucomilt_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomilt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_undefined_pd(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128d z = simde_mm_setzero_pd();
  simde__m128d v = simde_mm_undefined_pd();
  v = simde_mm_xor_pd(v, v);

  simde_assert_m128d_equal(v, z);

  return 0;
}

static int
test_simde_mm_undefined_si128(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128i z = simde_mm_setzero_si128();
  simde__m128i v = simde_mm_undefined_si128();
  v = simde_mm_xor_si128(v, v);

  simde_assert_m128i_equal(v, z);

  return 0;
}


static int
test_simde_mm_ucomineq_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomineq_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpackhi_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -36), INT8_C(  95), INT8_C(  84), INT8_C(-106), INT8_C(  32), INT8_C( 120), INT8_C(  19), INT8_C( -16),
                        INT8_C(  46), INT8_C(-123), INT8_C(-117), INT8_C(  46), INT8_C(  18), INT8_C( -72), INT8_C( -36), INT8_C(  78)),
      simde_mm_set_epi8(INT8_C(  10), INT8_C(-106), INT8_C( -91), INT8_C( -62), INT8_C( -61), INT8_C( -62), INT8_C( -83), INT8_C( -45),
                        INT8_C( -36), INT8_C(  17), INT8_C(  58), INT8_C(-114), INT8_C(  96), INT8_C(-102), INT8_C( -89), INT8_C( -20)),
      simde_mm_set_epi8(INT8_C(  10), INT8_C( -36), INT8_C(-106), INT8_C(  95), INT8_C( -91), INT8_C(  84), INT8_C( -62), INT8_C(-106),
                        INT8_C( -61), INT8_C(  32), INT8_C( -62), INT8_C( 120), INT8_C( -83), INT8_C(  19), INT8_C( -45), INT8_C( -16)) },
    { simde_mm_set_epi8(INT8_C( -54), INT8_C(-123), INT8_C(  74), INT8_C(  62), INT8_C(  43), INT8_C(  85), INT8_C( -99), INT8_C( -95),
                        INT8_C( -93), INT8_C( -92), INT8_C( 121), INT8_C(  82), INT8_C(  61), INT8_C(-110), INT8_C(-111), INT8_C( -40)),
      simde_mm_set_epi8(INT8_C(  61), INT8_C( -50), INT8_C(  88), INT8_C( -56), INT8_C(  14), INT8_C( -92), INT8_C(-109), INT8_C( -80),
                        INT8_C( -22), INT8_C( -61), INT8_C(-108), INT8_C(  69), INT8_C( -82), INT8_C(  29), INT8_C(  38), INT8_C( -72)),
      simde_mm_set_epi8(INT8_C(  61), INT8_C( -54), INT8_C( -50), INT8_C(-123), INT8_C(  88), INT8_C(  74), INT8_C( -56), INT8_C(  62),
                        INT8_C(  14), INT8_C(  43), INT8_C( -92), INT8_C(  85), INT8_C(-109), INT8_C( -99), INT8_C( -80), INT8_C( -95)) },
    { simde_mm_set_epi8(INT8_C(-103), INT8_C( -78), INT8_C( -94), INT8_C( -12), INT8_C( -31), INT8_C( -92), INT8_C( -17), INT8_C(  16),
                        INT8_C(-122), INT8_C( 113), INT8_C( -48), INT8_C( -99), INT8_C(  32), INT8_C( -67), INT8_C( 124), INT8_C( 107)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(  65), INT8_C( -45), INT8_C( -19), INT8_C( -55), INT8_C( -49), INT8_C( -54), INT8_C(  56),
                        INT8_C( -67), INT8_C( -54), INT8_C(-109), INT8_C( -80), INT8_C( -85), INT8_C(  96), INT8_C( -36), INT8_C( -69)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(-103), INT8_C(  65), INT8_C( -78), INT8_C( -45), INT8_C( -94), INT8_C( -19), INT8_C( -12),
                        INT8_C( -55), INT8_C( -31), INT8_C( -49), INT8_C( -92), INT8_C( -54), INT8_C( -17), INT8_C(  56), INT8_C(  16)) },
    { simde_mm_set_epi8(INT8_C( -33), INT8_C(  -6), INT8_C( -31), INT8_C( -33), INT8_C( -45), INT8_C( -71), INT8_C( 119), INT8_C(  79),
                        INT8_C(  29), INT8_C(   8), INT8_C( -44), INT8_C( -42), INT8_C( 113), INT8_C( -23), INT8_C(  53), INT8_C(-118)),
      simde_mm_set_epi8(INT8_C(  -4), INT8_C( -47), INT8_C( -67), INT8_C(  41), INT8_C(  84), INT8_C(   5), INT8_C( -24), INT8_C( 123),
                        INT8_C( 102), INT8_C( -69), INT8_C(  66), INT8_C( 117), INT8_C(-128), INT8_C( 115), INT8_C(  -2), INT8_C( -19)),
      simde_mm_set_epi8(INT8_C(  -4), INT8_C( -33), INT8_C( -47), INT8_C(  -6), INT8_C( -67), INT8_C( -31), INT8_C(  41), INT8_C( -33),
                        INT8_C(  84), INT8_C( -45), INT8_C(   5), INT8_C( -71), INT8_C( -24), INT8_C( 119), INT8_C( 123), INT8_C(  79)) },
    { simde_mm_set_epi8(INT8_C(-100), INT8_C( -57), INT8_C(  -5), INT8_C(-111), INT8_C( 124), INT8_C(-127), INT8_C( -90), INT8_C( -88),
                        INT8_C(  23), INT8_C(-114), INT8_C( -41), INT8_C( -98), INT8_C(  73), INT8_C(  14), INT8_C(   5), INT8_C(  46)),
      simde_mm_set_epi8(INT8_C(  66), INT8_C(-115), INT8_C( -36), INT8_C( -25), INT8_C( -75), INT8_C(-124), INT8_C(  96), INT8_C(  16),
                        INT8_C(  14), INT8_C( 103), INT8_C( -98), INT8_C(-105), INT8_C( -21), INT8_C( -89), INT8_C( -87), INT8_C( -43)),
      simde_mm_set_epi8(INT8_C(  66), INT8_C(-100), INT8_C(-115), INT8_C( -57), INT8_C( -36), INT8_C(  -5), INT8_C( -25), INT8_C(-111),
                        INT8_C( -75), INT8_C( 124), INT8_C(-124), INT8_C(-127), INT8_C(  96), INT8_C( -90), INT8_C(  16), INT8_C( -88)) },
    { simde_mm_set_epi8(INT8_C( -66), INT8_C( -23), INT8_C( -71), INT8_C( 103), INT8_C(  67), INT8_C( -33), INT8_C(-118), INT8_C( -19),
                        INT8_C(  25), INT8_C( -53), INT8_C(  56), INT8_C(  16), INT8_C(-126), INT8_C( 121), INT8_C(  96), INT8_C(-121)),
      simde_mm_set_epi8(INT8_C( -16), INT8_C(  18), INT8_C(  55), INT8_C(-104), INT8_C(-120), INT8_C(  39), INT8_C( -14), INT8_C(  76),
                        INT8_C(  39), INT8_C(  41), INT8_C( -81), INT8_C(  -9), INT8_C( -56), INT8_C(-103), INT8_C(   3), INT8_C( -27)),
      simde_mm_set_epi8(INT8_C( -16), INT8_C( -66), INT8_C(  18), INT8_C( -23), INT8_C(  55), INT8_C( -71), INT8_C(-104), INT8_C( 103),
                        INT8_C(-120), INT8_C(  67), INT8_C(  39), INT8_C( -33), INT8_C( -14), INT8_C(-118), INT8_C(  76), INT8_C( -19)) },
    { simde_mm_set_epi8(INT8_C( 114), INT8_C( -36), INT8_C(  60), INT8_C( -26), INT8_C(  24), INT8_C( -63), INT8_C( -29), INT8_C( 114),
                        INT8_C(  74), INT8_C( -94), INT8_C(  33), INT8_C( -33), INT8_C(  38), INT8_C( 109), INT8_C(  31), INT8_C( -91)),
      simde_mm_set_epi8(INT8_C( -28), INT8_C( -92), INT8_C(  30), INT8_C(-101), INT8_C(  -7), INT8_C(   1), INT8_C(-108), INT8_C(  29),
                        INT8_C( 114), INT8_C(  44), INT8_C(  -8), INT8_C(-107), INT8_C( -68), INT8_C(  90), INT8_C( 100), INT8_C( -37)),
      simde_mm_set_epi8(INT8_C( -28), INT8_C( 114), INT8_C( -92), INT8_C( -36), INT8_C(  30), INT8_C(  60), INT8_C(-101), INT8_C( -26),
                        INT8_C(  -7), INT8_C(  24), INT8_C(   1), INT8_C( -63), INT8_C(-108), INT8_C( -29), INT8_C(  29), INT8_C( 114)) },
    { simde_mm_set_epi8(INT8_C(  83), INT8_C( -32), INT8_C( -17), INT8_C( -35), INT8_C(  52), INT8_C( -64), INT8_C(  46), INT8_C(  89),
                        INT8_C( -65), INT8_C( -27), INT8_C(-104), INT8_C(   5), INT8_C(  84), INT8_C(  41), INT8_C(  88), INT8_C(  34)),
      simde_mm_set_epi8(INT8_C( -95), INT8_C(  93), INT8_C(-118), INT8_C( -44), INT8_C(  65), INT8_C( 114), INT8_C(  28), INT8_C( -90),
                        INT8_C( -85), INT8_C( 102), INT8_C(  78), INT8_C( -99), INT8_C(-120), INT8_C(  43), INT8_C( -56), INT8_C(  25)),
      simde_mm_set_epi8(INT8_C( -95), INT8_C(  83), INT8_C(  93), INT8_C( -32), INT8_C(-118), INT8_C( -17), INT8_C( -44), INT8_C( -35),
                        INT8_C(  65), INT8_C(  52), INT8_C( 114), INT8_C( -64), INT8_C(  28), INT8_C(  46), INT8_C( -90), INT8_C(  89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpackhi_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 18787), INT16_C( 30957), INT16_C(  6745), INT16_C(  5288),
                         INT16_C(-10333), INT16_C( 29461), INT16_C(   961), INT16_C(-14007)),
      simde_mm_set_epi16(INT16_C(-29691), INT16_C( 32561), INT16_C(-16442), INT16_C( -4659),
                         INT16_C( 21222), INT16_C(-21527), INT16_C( 30610), INT16_C( 14168)),
      simde_mm_set_epi16(INT16_C(-29691), INT16_C( 18787), INT16_C( 32561), INT16_C( 30957),
                         INT16_C(-16442), INT16_C(  6745), INT16_C( -4659), INT16_C(  5288)) },
    { simde_mm_set_epi16(INT16_C( 14241), INT16_C(-17353), INT16_C( 15871), INT16_C(  3653),
                         INT16_C(-29200), INT16_C( -9979), INT16_C(-30607), INT16_C( 31741)),
      simde_mm_set_epi16(INT16_C( 16753), INT16_C( 10981), INT16_C( 24190), INT16_C( 25811),
                         INT16_C(  6793), INT16_C( -6051), INT16_C(  1979), INT16_C(-14675)),
      simde_mm_set_epi16(INT16_C( 16753), INT16_C( 14241), INT16_C( 10981), INT16_C(-17353),
                         INT16_C( 24190), INT16_C( 15871), INT16_C( 25811), INT16_C(  3653)) },
    { simde_mm_set_epi16(INT16_C( 24118), INT16_C( -7950), INT16_C(  8813), INT16_C( 23815),
                         INT16_C(-12880), INT16_C( 22441), INT16_C(-31736), INT16_C( 28417)),
      simde_mm_set_epi16(INT16_C( -2535), INT16_C(-21518), INT16_C( 10955), INT16_C(-16484),
                         INT16_C(-17119), INT16_C(  5667), INT16_C(  5018), INT16_C( -9313)),
      simde_mm_set_epi16(INT16_C( -2535), INT16_C( 24118), INT16_C(-21518), INT16_C( -7950),
                         INT16_C( 10955), INT16_C(  8813), INT16_C(-16484), INT16_C( 23815)) },
    { simde_mm_set_epi16(INT16_C(-15717), INT16_C(  7765), INT16_C(-27156), INT16_C( 26721),
                         INT16_C( -2021), INT16_C( -7166), INT16_C(   832), INT16_C(  3368)),
      simde_mm_set_epi16(INT16_C(-17604), INT16_C( -2433), INT16_C(-22343), INT16_C( -9047),
                         INT16_C( -8009), INT16_C(-14884), INT16_C(-31015), INT16_C(  9072)),
      simde_mm_set_epi16(INT16_C(-17604), INT16_C(-15717), INT16_C( -2433), INT16_C(  7765),
                         INT16_C(-22343), INT16_C(-27156), INT16_C( -9047), INT16_C( 26721)) },
    { simde_mm_set_epi16(INT16_C(  9613), INT16_C(-25734), INT16_C(-29111), INT16_C( -6271),
                         INT16_C( 28183), INT16_C(  5627), INT16_C( 23471), INT16_C(-31640)),
      simde_mm_set_epi16(INT16_C( 17448), INT16_C(-17387), INT16_C( 12535), INT16_C( 19499),
                         INT16_C( 11772), INT16_C(  2463), INT16_C( 20494), INT16_C( -6320)),
      simde_mm_set_epi16(INT16_C( 17448), INT16_C(  9613), INT16_C(-17387), INT16_C(-25734),
                         INT16_C( 12535), INT16_C(-29111), INT16_C( 19499), INT16_C( -6271)) },
    { simde_mm_set_epi16(INT16_C(-23597), INT16_C(-19655), INT16_C(-17057), INT16_C( 18059),
                         INT16_C(  9484), INT16_C(  5905), INT16_C( 26068), INT16_C(  7424)),
      simde_mm_set_epi16(INT16_C(-16983), INT16_C( -3720), INT16_C(-18613), INT16_C(  7615),
                         INT16_C(-29369), INT16_C(-17019), INT16_C(   736), INT16_C( 23842)),
      simde_mm_set_epi16(INT16_C(-16983), INT16_C(-23597), INT16_C( -3720), INT16_C(-19655),
                         INT16_C(-18613), INT16_C(-17057), INT16_C(  7615), INT16_C( 18059)) },
    { simde_mm_set_epi16(INT16_C( 10339), INT16_C(  5875), INT16_C(-28772), INT16_C(  4220),
                         INT16_C( 31801), INT16_C( 29049), INT16_C( 31270), INT16_C(-18878)),
      simde_mm_set_epi16(INT16_C(-18888), INT16_C( 24242), INT16_C(-31726), INT16_C(-29025),
                         INT16_C(   845), INT16_C( -8031), INT16_C(  4992), INT16_C( -3599)),
      simde_mm_set_epi16(INT16_C(-18888), INT16_C( 10339), INT16_C( 24242), INT16_C(  5875),
                         INT16_C(-31726), INT16_C(-28772), INT16_C(-29025), INT16_C(  4220)) },
    { simde_mm_set_epi16(INT16_C(-14097), INT16_C( 31063), INT16_C(-25063), INT16_C( 16951),
                         INT16_C(-20725), INT16_C(  5387), INT16_C( -3219), INT16_C(-20465)),
      simde_mm_set_epi16(INT16_C(-23465), INT16_C(-30434), INT16_C( 28479), INT16_C(-15276),
                         INT16_C(-28694), INT16_C( -9228), INT16_C( 22420), INT16_C(-31453)),
      simde_mm_set_epi16(INT16_C(-23465), INT16_C(-14097), INT16_C(-30434), INT16_C( 31063),
                         INT16_C( 28479), INT16_C(-25063), INT16_C(-15276), INT16_C( 16951)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpackhi_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  168291084), INT32_C(  803222516), INT32_C(-2059191165), INT32_C(  156619127)),
      simde_mm_set_epi32(INT32_C( 1247164255), INT32_C(-1585504202), INT32_C(   81979034), INT32_C(-1257437380)),
      simde_mm_set_epi32(INT32_C( 1247164255), INT32_C(  168291084), INT32_C(-1585504202), INT32_C(  803222516)) },
    { simde_mm_set_epi32(INT32_C(-1229392695), INT32_C( -447420261), INT32_C(  -26173961), INT32_C( 1549193795)),
      simde_mm_set_epi32(INT32_C(-1584985518), INT32_C(-1825626458), INT32_C( 1790250510), INT32_C( -280669042)),
      simde_mm_set_epi32(INT32_C(-1584985518), INT32_C(-1229392695), INT32_C(-1825626458), INT32_C( -447420261)) },
    { simde_mm_set_epi32(INT32_C( -648698663), INT32_C( 1485053046), INT32_C(-2125470397), INT32_C(  507664294)),
      simde_mm_set_epi32(INT32_C( -735759218), INT32_C( -710175418), INT32_C(-1695159870), INT32_C(-1167064304)),
      simde_mm_set_epi32(INT32_C( -735759218), INT32_C( -648698663), INT32_C( -710175418), INT32_C( 1485053046)) },
    { simde_mm_set_epi32(INT32_C( -103259786), INT32_C( -188357300), INT32_C(  452180145), INT32_C(-1396420115)),
      simde_mm_set_epi32(INT32_C( 1404727965), INT32_C( -804737565), INT32_C(-1054802326), INT32_C( 1642647928)),
      simde_mm_set_epi32(INT32_C( 1404727965), INT32_C( -103259786), INT32_C( -804737565), INT32_C( -188357300)) },
    { simde_mm_set_epi32(INT32_C( 1212827068), INT32_C( 1189440629), INT32_C(-1547155816), INT32_C( 1839063433)),
      simde_mm_set_epi32(INT32_C(  796540528), INT32_C( -982269468), INT32_C(  -40316418), INT32_C( -430354120)),
      simde_mm_set_epi32(INT32_C(  796540528), INT32_C( 1212827068), INT32_C( -982269468), INT32_C( 1189440629)) },
    { simde_mm_set_epi32(INT32_C( 1356454008), INT32_C( -215878264), INT32_C(-1695191474), INT32_C(  378220333)),
      simde_mm_set_epi32(INT32_C( -864195447), INT32_C(-1443486627), INT32_C(-2133730470), INT32_C(  373467456)),
      simde_mm_set_epi32(INT32_C( -864195447), INT32_C( 1356454008), INT32_C(-1443486627), INT32_C( -215878264)) },
    { simde_mm_set_epi32(INT32_C(  764442598), INT32_C( 1720554406), INT32_C( 1938751418), INT32_C( 1005471402)),
      simde_mm_set_epi32(INT32_C(  883878116), INT32_C(  255422854), INT32_C(  583152961), INT32_C( -594123403)),
      simde_mm_set_epi32(INT32_C(  883878116), INT32_C(  764442598), INT32_C(  255422854), INT32_C( 1720554406)) },
    { simde_mm_set_epi32(INT32_C( -822423451), INT32_C( -180339328), INT32_C( -689601673), INT32_C(-1524838623)),
      simde_mm_set_epi32(INT32_C( -665157473), INT32_C(-2141208691), INT32_C(-1935796365), INT32_C( -482464349)),
      simde_mm_set_epi32(INT32_C( -665157473), INT32_C( -822423451), INT32_C(-2141208691), INT32_C( -180339328)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpackhi_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(  722804702791611380), INT64_C(-8844158709730520713)),
      simde_mm_set_epi64x(INT64_C( 5356529690674667574), INT64_C(  352097273025201980)),
      simde_mm_set_epi64x(INT64_C( 5356529690674667574), INT64_C(  722804702791611380)) },
    { simde_mm_set_epi64x(INT64_C(-5280201415118755685), INT64_C( -112416304952585661)),
      simde_mm_set_epi64x(INT64_C(-6807460961974278490), INT64_C( 7689067396111619214)),
      simde_mm_set_epi64x(INT64_C(-6807460961974278490), INT64_C(-5280201415118755685)) },
    { simde_mm_set_epi64x(INT64_C(-2786139541058872202), INT64_C(-9128825843223472218)),
      simde_mm_set_epi64x(INT64_C(-3160061775455742650), INT64_C(-7280656200013708528)),
      simde_mm_set_epi64x(INT64_C(-3160061775455742650), INT64_C(-2786139541058872202)) },
    { simde_mm_set_epi64x(INT64_C( -443497399755348660), INT64_C( 1942098937574085101)),
      simde_mm_set_epi64x(INT64_C( 6033260672941862371), INT64_C(-4530341492272082568)),
      simde_mm_set_epi64x(INT64_C( 6033260672941862371), INT64_C( -443497399755348660)) },
    { simde_mm_set_epi64x(INT64_C( 5209052593953008757), INT64_C(-6644983629697130103)),
      simde_mm_set_epi64x(INT64_C( 3421115521011270116), INT64_C( -173157692937252552)),
      simde_mm_set_epi64x(INT64_C( 3421115521011270116), INT64_C( 5209052593953008757)) },
    { simde_mm_set_epi64x(INT64_C( 5825925606967211400), INT64_C(-7280791940909813971)),
      simde_mm_set_epi64x(INT64_C(-3711691179365620643), INT64_C(-9164302586755241664)),
      simde_mm_set_epi64x(INT64_C(-3711691179365620643), INT64_C( 5825925606967211400)) },
    { simde_mm_set_epi64x(INT64_C( 3283255959799829414), INT64_C( 8326873936389097130)),
      simde_mm_set_epi64x(INT64_C( 3796227602125517190), INT64_C( 2504622899761407349)),
      simde_mm_set_epi64x(INT64_C( 3796227602125517190), INT64_C( 3283255959799829414)) },
    { simde_mm_set_epi64x(INT64_C(-3532281821393830528), INT64_C(-2961816630031757535)),
      simde_mm_set_epi64x(INT64_C(-2856829591071244403), INT64_C(-8314182075578176093)),
      simde_mm_set_epi64x(INT64_C(-2856829591071244403), INT64_C(-3532281821393830528)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpackhi_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -788.38), SIMDE_FLOAT64_C(  -23.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -996.21), SIMDE_FLOAT64_C(  645.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -996.21), SIMDE_FLOAT64_C( -788.38)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -986.13), SIMDE_FLOAT64_C(  267.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.03), SIMDE_FLOAT64_C(  978.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.03), SIMDE_FLOAT64_C( -986.13)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -468.32), SIMDE_FLOAT64_C( -478.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -484.79), SIMDE_FLOAT64_C( -613.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -484.79), SIMDE_FLOAT64_C( -468.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  169.21), SIMDE_FLOAT64_C(  897.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.63), SIMDE_FLOAT64_C( -172.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.63), SIMDE_FLOAT64_C(  169.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  499.02), SIMDE_FLOAT64_C(   28.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  532.77), SIMDE_FLOAT64_C( -718.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  532.77), SIMDE_FLOAT64_C(  499.02)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  208.34), SIMDE_FLOAT64_C(  635.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -165.40), SIMDE_FLOAT64_C(  391.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -165.40), SIMDE_FLOAT64_C(  208.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -371.80), SIMDE_FLOAT64_C(  698.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  603.26), SIMDE_FLOAT64_C(  962.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  603.26), SIMDE_FLOAT64_C( -371.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.32), SIMDE_FLOAT64_C(  149.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  349.36), SIMDE_FLOAT64_C(  -60.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  349.36), SIMDE_FLOAT64_C( -939.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_unpackhi_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_unpacklo_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -46), INT8_C(  11), INT8_C( -95), INT8_C(  -6), INT8_C(-108), INT8_C(-107), INT8_C( -24), INT8_C( -94),
                        INT8_C( -54), INT8_C(   2), INT8_C( 111), INT8_C(  78), INT8_C(  16), INT8_C( -54), INT8_C( -31), INT8_C( -19)),
      simde_mm_set_epi8(INT8_C(  40), INT8_C( -29), INT8_C( -79), INT8_C( -49), INT8_C(  12), INT8_C( -63), INT8_C(  87), INT8_C(  55),
                        INT8_C( 121), INT8_C( 100), INT8_C( -21), INT8_C(  -2), INT8_C( -22), INT8_C(  29), INT8_C( 110), INT8_C(-110)),
      simde_mm_set_epi8(INT8_C( 121), INT8_C( -54), INT8_C( 100), INT8_C(   2), INT8_C( -21), INT8_C( 111), INT8_C(  -2), INT8_C(  78),
                        INT8_C( -22), INT8_C(  16), INT8_C(  29), INT8_C( -54), INT8_C( 110), INT8_C( -31), INT8_C(-110), INT8_C( -19)) },
    { simde_mm_set_epi8(INT8_C(  40), INT8_C( -52), INT8_C( -72), INT8_C(   9), INT8_C( -57), INT8_C( -62), INT8_C(-100), INT8_C( 119),
                        INT8_C( 120), INT8_C( -83), INT8_C( 102), INT8_C( -39), INT8_C( -78), INT8_C( -92), INT8_C( -76), INT8_C( 121)),
      simde_mm_set_epi8(INT8_C(   7), INT8_C( -69), INT8_C(-112), INT8_C(  84), INT8_C(  -8), INT8_C(  23), INT8_C(  71), INT8_C( -37),
                        INT8_C( 104), INT8_C(-121), INT8_C( -93), INT8_C(  99), INT8_C(  47), INT8_C(-114), INT8_C( -52), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C( 104), INT8_C( 120), INT8_C(-121), INT8_C( -83), INT8_C( -93), INT8_C( 102), INT8_C(  99), INT8_C( -39),
                        INT8_C(  47), INT8_C( -78), INT8_C(-114), INT8_C( -92), INT8_C( -52), INT8_C( -76), INT8_C( 101), INT8_C( 121)) },
    { simde_mm_set_epi8(INT8_C(  23), INT8_C(  31), INT8_C( -95), INT8_C( -23), INT8_C( -83), INT8_C(  40), INT8_C( -32), INT8_C(  -4),
                        INT8_C(  97), INT8_C( 107), INT8_C(-118), INT8_C(  28), INT8_C(  58), INT8_C( -42), INT8_C(   6), INT8_C(  14)),
      simde_mm_set_epi8(INT8_C(  87), INT8_C( -63), INT8_C(  17), INT8_C( -66), INT8_C( -73), INT8_C( -52), INT8_C(  21), INT8_C( -51),
                        INT8_C(  77), INT8_C( 127), INT8_C(-123), INT8_C(  35), INT8_C( -87), INT8_C(  10), INT8_C(-116), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C(  77), INT8_C(  97), INT8_C( 127), INT8_C( 107), INT8_C(-123), INT8_C(-118), INT8_C(  35), INT8_C(  28),
                        INT8_C( -87), INT8_C(  58), INT8_C(  10), INT8_C( -42), INT8_C(-116), INT8_C(   6), INT8_C( -15), INT8_C(  14)) },
    { simde_mm_set_epi8(INT8_C(  82), INT8_C( -82), INT8_C( 120), INT8_C(-117), INT8_C(  95), INT8_C(  34), INT8_C(  57), INT8_C(-126),
                        INT8_C( 125), INT8_C( -41), INT8_C(  26), INT8_C( -67), INT8_C( -28), INT8_C( 110), INT8_C(  56), INT8_C(   8)),
      simde_mm_set_epi8(INT8_C(  43), INT8_C(  84), INT8_C( -22), INT8_C( -23), INT8_C(-118), INT8_C( 101), INT8_C( -61), INT8_C(   0),
                        INT8_C( 102), INT8_C(  10), INT8_C( -14), INT8_C( -26), INT8_C( -16), INT8_C(  -9), INT8_C(-102), INT8_C(  -6)),
      simde_mm_set_epi8(INT8_C( 102), INT8_C( 125), INT8_C(  10), INT8_C( -41), INT8_C( -14), INT8_C(  26), INT8_C( -26), INT8_C( -67),
                        INT8_C( -16), INT8_C( -28), INT8_C(  -9), INT8_C( 110), INT8_C(-102), INT8_C(  56), INT8_C(  -6), INT8_C(   8)) },
    { simde_mm_set_epi8(INT8_C( -53), INT8_C( -22), INT8_C(  64), INT8_C( -17), INT8_C( -84), INT8_C(-128), INT8_C(-124), INT8_C( -98),
                        INT8_C( -10), INT8_C( -24), INT8_C(  47), INT8_C( 109), INT8_C(  15), INT8_C( -93), INT8_C(  -3), INT8_C( -83)),
      simde_mm_set_epi8(INT8_C( 102), INT8_C(  24), INT8_C(  10), INT8_C(  77), INT8_C( -47), INT8_C( 121), INT8_C(  -9), INT8_C(  31),
                        INT8_C(   5), INT8_C(  32), INT8_C( -40), INT8_C(  72), INT8_C(-114), INT8_C( -28), INT8_C(  76), INT8_C(  98)),
      simde_mm_set_epi8(INT8_C(   5), INT8_C( -10), INT8_C(  32), INT8_C( -24), INT8_C( -40), INT8_C(  47), INT8_C(  72), INT8_C( 109),
                        INT8_C(-114), INT8_C(  15), INT8_C( -28), INT8_C( -93), INT8_C(  76), INT8_C(  -3), INT8_C(  98), INT8_C( -83)) },
    { simde_mm_set_epi8(INT8_C(  42), INT8_C(-126), INT8_C( -81), INT8_C(  -3), INT8_C(  60), INT8_C( -79), INT8_C(  80), INT8_C( -92),
                        INT8_C( -48), INT8_C(  40), INT8_C(-125), INT8_C(  24), INT8_C(  38), INT8_C( -84), INT8_C( 120), INT8_C(  92)),
      simde_mm_set_epi8(INT8_C(-118), INT8_C(-121), INT8_C(  29), INT8_C(-128), INT8_C(-101), INT8_C(   4), INT8_C( -66), INT8_C(  29),
                        INT8_C(  -3), INT8_C(  82), INT8_C(  -7), INT8_C( -87), INT8_C(  76), INT8_C(  52), INT8_C(-124), INT8_C(  86)),
      simde_mm_set_epi8(INT8_C(  -3), INT8_C( -48), INT8_C(  82), INT8_C(  40), INT8_C(  -7), INT8_C(-125), INT8_C( -87), INT8_C(  24),
                        INT8_C(  76), INT8_C(  38), INT8_C(  52), INT8_C( -84), INT8_C(-124), INT8_C( 120), INT8_C(  86), INT8_C(  92)) },
    { simde_mm_set_epi8(INT8_C(-121), INT8_C( 102), INT8_C( -71), INT8_C(-105), INT8_C(-120), INT8_C( 124), INT8_C( -56), INT8_C(  80),
                        INT8_C( -23), INT8_C(  26), INT8_C(-103), INT8_C(  31), INT8_C( -30), INT8_C( -86), INT8_C( 103), INT8_C( -93)),
      simde_mm_set_epi8(INT8_C(-114), INT8_C(   9), INT8_C(  28), INT8_C( -23), INT8_C( 125), INT8_C(  28), INT8_C( -55), INT8_C( -13),
                        INT8_C( -41), INT8_C( 123), INT8_C( -52), INT8_C(  49), INT8_C( -94), INT8_C( -66), INT8_C(  69), INT8_C(  75)),
      simde_mm_set_epi8(INT8_C( -41), INT8_C( -23), INT8_C( 123), INT8_C(  26), INT8_C( -52), INT8_C(-103), INT8_C(  49), INT8_C(  31),
                        INT8_C( -94), INT8_C( -30), INT8_C( -66), INT8_C( -86), INT8_C(  69), INT8_C( 103), INT8_C(  75), INT8_C( -93)) },
    { simde_mm_set_epi8(INT8_C( -30), INT8_C(  56), INT8_C(  -7), INT8_C( -85), INT8_C(  -3), INT8_C( -30), INT8_C(  87), INT8_C( 101),
                        INT8_C(-112), INT8_C( -18), INT8_C(   7), INT8_C(  45), INT8_C(  32), INT8_C( 103), INT8_C(  -2), INT8_C( 100)),
      simde_mm_set_epi8(INT8_C(  75), INT8_C( -55), INT8_C(   1), INT8_C(  61), INT8_C(-126), INT8_C( -76), INT8_C(  61), INT8_C( -69),
                        INT8_C( -86), INT8_C( 110), INT8_C( -52), INT8_C( 110), INT8_C(  96), INT8_C( -55), INT8_C(  76), INT8_C(  15)),
      simde_mm_set_epi8(INT8_C( -86), INT8_C(-112), INT8_C( 110), INT8_C( -18), INT8_C( -52), INT8_C(   7), INT8_C( 110), INT8_C(  45),
                        INT8_C(  96), INT8_C(  32), INT8_C( -55), INT8_C( 103), INT8_C(  76), INT8_C(  -2), INT8_C(  15), INT8_C( 100)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpacklo_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-11765), INT16_C(-24070), INT16_C(-27499), INT16_C( -5982),
                         INT16_C(-13822), INT16_C( 28494), INT16_C(  4298), INT16_C( -7699)),
      simde_mm_set_epi16(INT16_C( 10467), INT16_C(-20017), INT16_C(  3265), INT16_C( 22327),
                         INT16_C( 31076), INT16_C( -5122), INT16_C( -5603), INT16_C( 28306)),
      simde_mm_set_epi16(INT16_C( 31076), INT16_C(-13822), INT16_C( -5122), INT16_C( 28494),
                         INT16_C( -5603), INT16_C(  4298), INT16_C( 28306), INT16_C( -7699)) },
    { simde_mm_set_epi16(INT16_C( 10444), INT16_C(-18423), INT16_C(-14398), INT16_C(-25481),
                         INT16_C( 30893), INT16_C( 26329), INT16_C(-19804), INT16_C(-19335)),
      simde_mm_set_epi16(INT16_C(  1979), INT16_C(-28588), INT16_C( -2025), INT16_C( 18395),
                         INT16_C( 26759), INT16_C(-23709), INT16_C( 12174), INT16_C(-13211)),
      simde_mm_set_epi16(INT16_C( 26759), INT16_C( 30893), INT16_C(-23709), INT16_C( 26329),
                         INT16_C( 12174), INT16_C(-19804), INT16_C(-13211), INT16_C(-19335)) },
    { simde_mm_set_epi16(INT16_C(  5919), INT16_C(-24087), INT16_C(-21208), INT16_C( -7940),
                         INT16_C( 24939), INT16_C(-30180), INT16_C( 15062), INT16_C(  1550)),
      simde_mm_set_epi16(INT16_C( 22465), INT16_C(  4542), INT16_C(-18484), INT16_C(  5581),
                         INT16_C( 19839), INT16_C(-31453), INT16_C(-22262), INT16_C(-29455)),
      simde_mm_set_epi16(INT16_C( 19839), INT16_C( 24939), INT16_C(-31453), INT16_C(-30180),
                         INT16_C(-22262), INT16_C( 15062), INT16_C(-29455), INT16_C(  1550)) },
    { simde_mm_set_epi16(INT16_C( 21166), INT16_C( 30859), INT16_C( 24354), INT16_C( 14722),
                         INT16_C( 32215), INT16_C(  6845), INT16_C( -7058), INT16_C( 14344)),
      simde_mm_set_epi16(INT16_C( 11092), INT16_C( -5399), INT16_C(-30107), INT16_C(-15616),
                         INT16_C( 26122), INT16_C( -3354), INT16_C( -3849), INT16_C(-25862)),
      simde_mm_set_epi16(INT16_C( 26122), INT16_C( 32215), INT16_C( -3354), INT16_C(  6845),
                         INT16_C( -3849), INT16_C( -7058), INT16_C(-25862), INT16_C( 14344)) },
    { simde_mm_set_epi16(INT16_C(-13334), INT16_C( 16623), INT16_C(-21376), INT16_C(-31586),
                         INT16_C( -2328), INT16_C( 12141), INT16_C(  4003), INT16_C(  -595)),
      simde_mm_set_epi16(INT16_C( 26136), INT16_C(  2637), INT16_C(-11911), INT16_C( -2273),
                         INT16_C(  1312), INT16_C(-10168), INT16_C(-28956), INT16_C( 19554)),
      simde_mm_set_epi16(INT16_C(  1312), INT16_C( -2328), INT16_C(-10168), INT16_C( 12141),
                         INT16_C(-28956), INT16_C(  4003), INT16_C( 19554), INT16_C(  -595)) },
    { simde_mm_set_epi16(INT16_C( 10882), INT16_C(-20483), INT16_C( 15537), INT16_C( 20644),
                         INT16_C(-12248), INT16_C(-31976), INT16_C(  9900), INT16_C( 30812)),
      simde_mm_set_epi16(INT16_C(-30073), INT16_C(  7552), INT16_C(-25852), INT16_C(-16867),
                         INT16_C(  -686), INT16_C( -1623), INT16_C( 19508), INT16_C(-31658)),
      simde_mm_set_epi16(INT16_C(  -686), INT16_C(-12248), INT16_C( -1623), INT16_C(-31976),
                         INT16_C( 19508), INT16_C(  9900), INT16_C(-31658), INT16_C( 30812)) },
    { simde_mm_set_epi16(INT16_C(-30874), INT16_C(-18025), INT16_C(-30596), INT16_C(-14256),
                         INT16_C( -5862), INT16_C(-26337), INT16_C( -7510), INT16_C( 26531)),
      simde_mm_set_epi16(INT16_C(-29175), INT16_C(  7401), INT16_C( 32028), INT16_C(-13837),
                         INT16_C(-10373), INT16_C(-13263), INT16_C(-23874), INT16_C( 17739)),
      simde_mm_set_epi16(INT16_C(-10373), INT16_C( -5862), INT16_C(-13263), INT16_C(-26337),
                         INT16_C(-23874), INT16_C( -7510), INT16_C( 17739), INT16_C( 26531)) },
    { simde_mm_set_epi16(INT16_C( -7624), INT16_C( -1621), INT16_C(  -542), INT16_C( 22373),
                         INT16_C(-28434), INT16_C(  1837), INT16_C(  8295), INT16_C(  -412)),
      simde_mm_set_epi16(INT16_C( 19401), INT16_C(   317), INT16_C(-32076), INT16_C( 15803),
                         INT16_C(-21906), INT16_C(-13202), INT16_C( 24777), INT16_C( 19471)),
      simde_mm_set_epi16(INT16_C(-21906), INT16_C(-28434), INT16_C(-13202), INT16_C(  1837),
                         INT16_C( 24777), INT16_C(  8295), INT16_C( 19471), INT16_C(  -412)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpacklo_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -770989574), INT32_C(-1802114910), INT32_C( -905810098), INT32_C(  281731565)),
      simde_mm_set_epi32(INT32_C(  686010831), INT32_C(  213997367), INT32_C( 2036657150), INT32_C( -367169902)),
      simde_mm_set_epi32(INT32_C( 2036657150), INT32_C( -905810098), INT32_C( -367169902), INT32_C(  281731565)) },
    { simde_mm_set_epi32(INT32_C(  684505097), INT32_C( -943547273), INT32_C( 2024629977), INT32_C(-1297828743)),
      simde_mm_set_epi32(INT32_C(  129732692), INT32_C( -132692005), INT32_C( 1753719651), INT32_C(  797887589)),
      simde_mm_set_epi32(INT32_C( 1753719651), INT32_C( 2024629977), INT32_C(  797887589), INT32_C(-1297828743)) },
    { simde_mm_set_epi32(INT32_C(  387949033), INT32_C(-1389829892), INT32_C( 1634437660), INT32_C(  987104782)),
      simde_mm_set_epi32(INT32_C( 1472270782), INT32_C(-1211361843), INT32_C( 1300202787), INT32_C(-1458926351)),
      simde_mm_set_epi32(INT32_C( 1300202787), INT32_C( 1634437660), INT32_C(-1458926351), INT32_C(  987104782)) },
    { simde_mm_set_epi32(INT32_C( 1387165835), INT32_C( 1596078466), INT32_C( 2111249085), INT32_C( -462538744)),
      simde_mm_set_epi32(INT32_C(  726985449), INT32_C(-1973042432), INT32_C( 1711993574), INT32_C( -252208390)),
      simde_mm_set_epi32(INT32_C( 1711993574), INT32_C( 2111249085), INT32_C( -252208390), INT32_C( -462538744)) },
    { simde_mm_set_epi32(INT32_C( -873840401), INT32_C(-1400863586), INT32_C( -152555667), INT32_C(  262405549)),
      simde_mm_set_epi32(INT32_C( 1712851533), INT32_C( -780536033), INT32_C(   86038600), INT32_C(-1897640862)),
      simde_mm_set_epi32(INT32_C(   86038600), INT32_C( -152555667), INT32_C(-1897640862), INT32_C(  262405549)) },
    { simde_mm_set_epi32(INT32_C(  713207805), INT32_C( 1018253476), INT32_C( -802651368), INT32_C(  648837212)),
      simde_mm_set_epi32(INT32_C(-1970856576), INT32_C(-1694188003), INT32_C(  -44893783), INT32_C( 1278510166)),
      simde_mm_set_epi32(INT32_C(  -44893783), INT32_C( -802651368), INT32_C( 1278510166), INT32_C(  648837212)) },
    { simde_mm_set_epi32(INT32_C(-2023310953), INT32_C(-2005088176), INT32_C( -384132833), INT32_C( -492148829)),
      simde_mm_set_epi32(INT32_C(-1912005399), INT32_C( 2099038707), INT32_C( -679752655), INT32_C(-1564588725)),
      simde_mm_set_epi32(INT32_C( -679752655), INT32_C( -384132833), INT32_C(-1564588725), INT32_C( -492148829)) },
    { simde_mm_set_epi32(INT32_C( -499582549), INT32_C(  -35498139), INT32_C(-1863448787), INT32_C(  543686244)),
      simde_mm_set_epi32(INT32_C( 1271464253), INT32_C(-2102116933), INT32_C(-1435579282), INT32_C( 1623804943)),
      simde_mm_set_epi32(INT32_C(-1435579282), INT32_C(-1863448787), INT32_C( 1623804943), INT32_C(  543686244)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpacklo_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-3311375003394119518), INT64_C(-3890424747014823443)),
      simde_mm_set_epi64x(INT64_C( 2946394084060780343), INT64_C( 8747375856342363794)),
      simde_mm_set_epi64x(INT64_C( 8747375856342363794), INT64_C(-3890424747014823443)) },
    { simde_mm_set_epi64x(INT64_C( 2939927008911727735), INT64_C( 8695719540713370745)),
      simde_mm_set_epi64x(INT64_C(  557197673524316123), INT64_C( 7532168548195421285)),
      simde_mm_set_epi64x(INT64_C( 7532168548195421285), INT64_C( 8695719540713370745)) },
    { simde_mm_set_epi64x(INT64_C( 1666228412154962172), INT64_C( 7019856298037872142)),
      simde_mm_set_epi64x(INT64_C( 6323354862629950925), INT64_C( 5584328451169094897)),
      simde_mm_set_epi64x(INT64_C( 5584328451169094897), INT64_C( 7019856298037872142)) },
    { simde_mm_set_epi64x(INT64_C( 5957831897049610626), INT64_C( 9067745777617352712)),
      simde_mm_set_epi64x(INT64_C( 3122378730444800768), INT64_C( 7352956415334914810)),
      simde_mm_set_epi64x(INT64_C( 7352956415334914810), INT64_C( 9067745777617352712)) },
    { simde_mm_set_epi64x(INT64_C(-3753115941324421986), INT64_C( -655221600322060883)),
      simde_mm_set_epi64x(INT64_C( 7356641320652896031), INT64_C(  369532975590952034)),
      simde_mm_set_epi64x(INT64_C(  369532975590952034), INT64_C( -655221600322060883)) },
    { simde_mm_set_epi64x(INT64_C( 3063204198745198756), INT64_C(-3447361375000823716)),
      simde_mm_set_epi64x(INT64_C(-8464764536425759203), INT64_C( -192817328500210602)),
      simde_mm_set_epi64x(INT64_C( -192817328500210602), INT64_C(-3447361375000823716)) },
    { simde_mm_set_epi64x(INT64_C(-8690054370483713968), INT64_C(-1649837951252011101)),
      simde_mm_set_epi64x(INT64_C(-8212000656381392397), INT64_C(-2919515419863792309)),
      simde_mm_set_epi64x(INT64_C(-2919515419863792309), INT64_C(-1649837951252011101)) },
    { simde_mm_set_epi64x(INT64_C(-2145690705347848347), INT64_C(-8003451597392183708)),
      simde_mm_set_epi64x(INT64_C( 5460897386860920251), INT64_C(-6165766065381356529)),
      simde_mm_set_epi64x(INT64_C(-6165766065381356529), INT64_C(-8003451597392183708)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_unpacklo_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  160.82), SIMDE_FLOAT64_C( -868.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  640.98), SIMDE_FLOAT64_C(  578.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  578.20), SIMDE_FLOAT64_C( -868.81)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.35), SIMDE_FLOAT64_C(  829.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -680.55), SIMDE_FLOAT64_C(  -51.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.61), SIMDE_FLOAT64_C(  829.02)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  560.63), SIMDE_FLOAT64_C(  395.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -681.25), SIMDE_FLOAT64_C(  -57.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.21), SIMDE_FLOAT64_C(  395.65)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.21), SIMDE_FLOAT64_C( -628.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.59), SIMDE_FLOAT64_C( -183.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -183.36), SIMDE_FLOAT64_C( -628.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  352.81), SIMDE_FLOAT64_C( -540.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -819.35), SIMDE_FLOAT64_C( -238.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -238.91), SIMDE_FLOAT64_C( -540.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  435.92), SIMDE_FLOAT64_C(  320.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -314.42), SIMDE_FLOAT64_C( -394.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.55), SIMDE_FLOAT64_C(  320.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -256.77), SIMDE_FLOAT64_C(  784.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -354.05), SIMDE_FLOAT64_C(  -16.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -16.87), SIMDE_FLOAT64_C(  784.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   81.23), SIMDE_FLOAT64_C(  882.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -661.47), SIMDE_FLOAT64_C( -202.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -202.79), SIMDE_FLOAT64_C(  882.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_unpacklo_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_xor_pd(SIMDE_MUNIT_TEST_ARGS) {
  simde__m128d
    all_set = simde_x_mm_setone_pd(),
    all_unset = simde_mm_setzero_pd();

  simde_assert_m128d_equal(simde_mm_xor_pd(all_set, all_unset), all_set);
  simde_assert_m128d_equal(simde_mm_xor_pd(all_set, all_set), all_unset);
  simde_assert_m128d_equal(simde_mm_xor_pd(all_unset, all_unset), all_unset);

  return 0;
}

static int
test_simde_mm_xor_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1623880239), INT32_C( 1318620160), INT32_C(-1283662193), INT32_C(-1453845482)),
      simde_mm_set_epi32(INT32_C(-1675083604), INT32_C(  603168286), INT32_C(  409798099), INT32_C(  632966287)),
      simde_mm_set_epi32(INT32_C(  -52284797), INT32_C( 1835733534), INT32_C(-1424893092), INT32_C(-1931323239)) },
    { simde_mm_set_epi32(INT32_C( 1509092554), INT32_C( 1648495442), INT32_C(-1486316171), INT32_C(  868417203)),
      simde_mm_set_epi32(INT32_C( 1183220554), INT32_C(-1650741405), INT32_C(-1277877547), INT32_C( -793058853)),
      simde_mm_set_epi32(INT32_C(  527724416), INT32_C(   -2513871), INT32_C(  347979680), INT32_C( -478666904)) },
    { simde_mm_set_epi32(INT32_C(  373711788), INT32_C(-1451210820), INT32_C( 1218370771), INT32_C( 1535794325)),
      simde_mm_set_epi32(INT32_C( -155546503), INT32_C(-2037105503), INT32_C( 1041195962), INT32_C(-1654529737)),
      simde_mm_set_epi32(INT32_C( -520294443), INT32_C(  789871389), INT32_C( 1989263209), INT32_C( -957629022)) },
    { simde_mm_set_epi32(INT32_C(-1223418601), INT32_C(  332961755), INT32_C(  688173092), INT32_C(  352304516)),
      simde_mm_set_epi32(INT32_C( -734452212), INT32_C( -791801405), INT32_C(  114386244), INT32_C(  996038140)),
      simde_mm_set_epi32(INT32_C( 1663908635), INT32_C(-1021934056), INT32_C(  802542944), INT32_C(  799139960)) },
    { simde_mm_set_epi32(INT32_C( 1204298996), INT32_C( 1777561493), INT32_C(  531158614), INT32_C(-1345218351)),
      simde_mm_set_epi32(INT32_C(  465699923), INT32_C(-1417149028), INT32_C(-1963684061), INT32_C( -837148929)),
      simde_mm_set_epi32(INT32_C( 1544167591), INT32_C(-1032099319), INT32_C(-1789109899), INT32_C( 1640728110)) },
    { simde_mm_set_epi32(INT32_C( 1401162168), INT32_C( -922039657), INT32_C( 1348044504), INT32_C( 1592606181)),
      simde_mm_set_epi32(INT32_C(-1635510345), INT32_C(-1462861610), INT32_C(-1206905626), INT32_C( -326154944)),
      simde_mm_set_epi32(INT32_C( -855630321), INT32_C( 1640254017), INT32_C( -397831618), INT32_C(-1302169435)) },
    { simde_mm_set_epi32(INT32_C(  882266138), INT32_C( 2140233068), INT32_C( -978476725), INT32_C( -962797184)),
      simde_mm_set_epi32(INT32_C( 1476434174), INT32_C(  732384170), INT32_C(  406886944), INT32_C( 1700501859)),
      simde_mm_set_epi32(INT32_C( 1821821156), INT32_C( 1412830918), INT32_C( -571655317), INT32_C(-1547208477)) },
    { simde_mm_set_epi32(INT32_C(  782585313), INT32_C( 1758933973), INT32_C(-1583302414), INT32_C(-1602193751)),
      simde_mm_set_epi32(INT32_C(  760188951), INT32_C(  624290102), INT32_C(  378021852), INT32_C(-1714147587)),
      simde_mm_set_epi32(INT32_C(   65723894), INT32_C( 1306712803), INT32_C(-1222074578), INT32_C(  961828948)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r = simde_mm_xor_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_not_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -817965525), INT32_C( 2140859656), INT32_C(  142941694), INT32_C(-1061432158)),
      simde_mm_set_epi32(INT32_C(  817965524), INT32_C(-2140859657), INT32_C( -142941695), INT32_C( 1061432157)) },
    { simde_mm_set_epi32(INT32_C( 1656377120), INT32_C( 1182756765), INT32_C(  499148047), INT32_C( 1939837842)),
      simde_mm_set_epi32(INT32_C(-1656377121), INT32_C(-1182756766), INT32_C( -499148048), INT32_C(-1939837843)) },
    { simde_mm_set_epi32(INT32_C(-1391390683), INT32_C( -880299242), INT32_C( 1262346433), INT32_C(-1162276292)),
      simde_mm_set_epi32(INT32_C( 1391390682), INT32_C(  880299241), INT32_C(-1262346434), INT32_C( 1162276291)) },
    { simde_mm_set_epi32(INT32_C(  402553699), INT32_C(-1406117325), INT32_C(-1620159472), INT32_C( 1950201834)),
      simde_mm_set_epi32(INT32_C( -402553700), INT32_C( 1406117324), INT32_C( 1620159471), INT32_C(-1950201835)) },
    { simde_mm_set_epi32(INT32_C( 1201512664), INT32_C( -722158977), INT32_C(-1427673018), INT32_C(-1348620069)),
      simde_mm_set_epi32(INT32_C(-1201512665), INT32_C(  722158976), INT32_C( 1427673017), INT32_C( 1348620068)) },
    { simde_mm_set_epi32(INT32_C( 2022239253), INT32_C(  336656978), INT32_C(-2043097029), INT32_C( 2060912582)),
      simde_mm_set_epi32(INT32_C(-2022239254), INT32_C( -336656979), INT32_C( 2043097028), INT32_C(-2060912583)) },
    { simde_mm_set_epi32(INT32_C(-1767401405), INT32_C(  988173440), INT32_C(  653493949), INT32_C( 1545873213)),
      simde_mm_set_epi32(INT32_C( 1767401404), INT32_C( -988173441), INT32_C( -653493950), INT32_C(-1545873214)) },
    { simde_mm_set_epi32(INT32_C(  164259681), INT32_C( 1625402133), INT32_C(  274817939), INT32_C( 1382941610)),
      simde_mm_set_epi32(INT32_C( -164259682), INT32_C(-1625402134), INT32_C( -274817940), INT32_C(-1382941611)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_not_si128(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_mul_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-6673265146157132667), INT64_C(-8036865195274064518)),
      simde_mm_set_epi64x(INT64_C( 4763310881806863840), INT64_C(-2953190602401137090)),
      simde_mm_set_epi64x(INT64_C(  804621865193403744), INT64_C( 7037306546512957324)) },
    { simde_mm_set_epi64x(INT64_C( 4912321112367014754), INT64_C( 5506077972841640415)),
      simde_mm_set_epi64x(INT64_C( 5790159379234202843), INT64_C(-7860297575342104977)),
      simde_mm_set_epi64x(INT64_C(-6503632121046397738), INT64_C(-1366099594229104207)) },
    { simde_mm_set_epi64x(INT64_C( 2749162021411530208), INT64_C(  408462426494202626)),
      simde_mm_set_epi64x(INT64_C( 8447492608754880299), INT64_C(-7046703966410124624)),
      simde_mm_set_epi64x(INT64_C(-4973831282761794400), INT64_C( 2599589224149726560)) },
    { simde_mm_set_epi64x(INT64_C(  -88834185851708236), INT64_C(-8089393205327952234)),
      simde_mm_set_epi64x(INT64_C(  381269932343520540), INT64_C( 2138325983301945876)),
      simde_mm_set_epi64x(INT64_C(-7088569628310845520), INT64_C( 1233235991476166584)) },
    { simde_mm_set_epi64x(INT64_C( -822706701071313394), INT64_C(-2759012498076821456)),
      simde_mm_set_epi64x(INT64_C( 3465917358098376677), INT64_C(-7954598628423398790)),
      simde_mm_set_epi64x(INT64_C(-6698232051336684410), INT64_C(-6956668788971772192)) },
    { simde_mm_set_epi64x(INT64_C( 8188114688325369058), INT64_C(-5073366312523094897)),
      simde_mm_set_epi64x(INT64_C(-8915693716470801407), INT64_C( 9186903668894606147)),
      simde_mm_set_epi64x(INT64_C( 3677373050832155874), INT64_C(-2924803137816977811)) },
    { simde_mm_set_epi64x(INT64_C(-5966336380315033651), INT64_C( 8263120995643775133)),
      simde_mm_set_epi64x(INT64_C(-4262947749795433008), INT64_C(-8185205248719856231)),
      simde_mm_set_epi64x(INT64_C(-5369329972927887472), INT64_C(-4868166633591505195)) },
    { simde_mm_set_epi64x(INT64_C( 2800078338557512603), INT64_C(-7382248080413965284)),
      simde_mm_set_epi64x(INT64_C( -645055313537887494), INT64_C( 2018860835012845242)),
      simde_mm_set_epi64x(INT64_C( 3796538949364005726), INT64_C(-1962708987484978088)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_mul_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_sub_epu32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C( 591915169), UINT32_C(1162556909), UINT32_C(2711661198), UINT32_C( 649386420)),
      simde_x_mm_set_epu32(UINT32_C(2963858433), UINT32_C( 387638488), UINT32_C(4276033779), UINT32_C(2372843734)),
      simde_x_mm_set_epu32(UINT32_C(1923024032), UINT32_C( 774918421), UINT32_C(2730594715), UINT32_C(2571509982)) },
    { simde_x_mm_set_epu32(UINT32_C( 445936307), UINT32_C(1465838226), UINT32_C(3055798709), UINT32_C(2785403539)),
      simde_x_mm_set_epu32(UINT32_C(2376292101), UINT32_C(2800453656), UINT32_C(2012288479), UINT32_C(1067663469)),
      simde_x_mm_set_epu32(UINT32_C(2364611502), UINT32_C(2960351866), UINT32_C(1043510230), UINT32_C(1717740070)) },
    { simde_x_mm_set_epu32(UINT32_C( 766825118), UINT32_C(3689178364), UINT32_C(1309713860), UINT32_C(1635279642)),
      simde_x_mm_set_epu32(UINT32_C(1287494965), UINT32_C(3931214929), UINT32_C( 130800549), UINT32_C(1579059128)),
      simde_x_mm_set_epu32(UINT32_C(3774297449), UINT32_C(4052930731), UINT32_C(1178913311), UINT32_C(  56220514)) },
    { simde_x_mm_set_epu32(UINT32_C(1521150506), UINT32_C( 229274390), UINT32_C(2137370048), UINT32_C(1343959137)),
      simde_x_mm_set_epu32(UINT32_C( 919906837), UINT32_C(4230649021), UINT32_C(2105941239), UINT32_C(3460244161)),
      simde_x_mm_set_epu32(UINT32_C( 601243669), UINT32_C( 293592665), UINT32_C(  31428809), UINT32_C(2178682272)) },
    { simde_x_mm_set_epu32(UINT32_C(1275529272), UINT32_C(2231818861), UINT32_C(2063802469), UINT32_C(3732401863)),
      simde_x_mm_set_epu32(UINT32_C(2896374047), UINT32_C(1493829257), UINT32_C(2939390855), UINT32_C(1941911553)),
      simde_x_mm_set_epu32(UINT32_C(2674122521), UINT32_C( 737989604), UINT32_C(3419378910), UINT32_C(1790490310)) },
    { simde_x_mm_set_epu32(UINT32_C(3017205359), UINT32_C(2429422013), UINT32_C(3351841835), UINT32_C(2341203472)),
      simde_x_mm_set_epu32(UINT32_C(3000898366), UINT32_C(1136654732), UINT32_C(2535059098), UINT32_C(  90134778)),
      simde_x_mm_set_epu32(UINT32_C(  16306993), UINT32_C(1292767281), UINT32_C( 816782737), UINT32_C(2251068694)) },
    { simde_x_mm_set_epu32(UINT32_C(  71842021), UINT32_C(1910901245), UINT32_C( 252676465), UINT32_C(3861146107)),
      simde_x_mm_set_epu32(UINT32_C(4061170475), UINT32_C(3890236125), UINT32_C(1645686841), UINT32_C(3708385897)),
      simde_x_mm_set_epu32(UINT32_C( 305638842), UINT32_C(2315632416), UINT32_C(2901956920), UINT32_C( 152760210)) },
    { simde_x_mm_set_epu32(UINT32_C(1390785465), UINT32_C( 237201350), UINT32_C(3330556421), UINT32_C( 382557765)),
      simde_x_mm_set_epu32(UINT32_C( 919261037), UINT32_C(4138415457), UINT32_C( 812238579), UINT32_C( 103076353)),
      simde_x_mm_set_epu32(UINT32_C( 471524428), UINT32_C( 393753189), UINT32_C(2518317842), UINT32_C( 279481412)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_sub_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_mod_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-8053187774363015445), INT64_C( 9050551738356525681)),
      simde_mm_set_epi64x(INT64_C(-5432362900125533563), INT64_C( 4656333831414330662)),
      simde_mm_set_epi64x(INT64_C(-2620824874237481882), INT64_C( 4394217906942195019)) },
    { simde_mm_set_epi64x(INT64_C( 3643434954039553447), INT64_C(-6234539097175065740)),
      simde_mm_set_epi64x(INT64_C(-1834126128625936904), INT64_C( 5974848154734978575)),
      simde_mm_set_epi64x(INT64_C( 1809308825413616543), INT64_C( -259690942440087165)) },
    { simde_mm_set_epi64x(INT64_C( 9161306297850640165), INT64_C(-8306180370740150176)),
      simde_mm_set_epi64x(INT64_C( 2055562205091916701), INT64_C(-6680168448646461201)),
      simde_mm_set_epi64x(INT64_C(  939057477482973361), INT64_C(-1626011922093688975)) },
    { simde_mm_set_epi64x(INT64_C(-8267679289606370918), INT64_C(-5928191487249150522)),
      simde_mm_set_epi64x(INT64_C( -367540592738432621), INT64_C(-9016984680455221058)),
      simde_mm_set_epi64x(INT64_C( -181786249360853256), INT64_C(-5928191487249150522)) },
    { simde_mm_set_epi64x(INT64_C(-5911217161035399691), INT64_C(-1038656028139092449)),
      simde_mm_set_epi64x(INT64_C(  170272479168034452), INT64_C( 6507756447489319344)),
      simde_mm_set_epi64x(INT64_C( -121952869322228323), INT64_C(-1038656028139092449)) },
    { simde_mm_set_epi64x(INT64_C(-8644627274378588029), INT64_C( 5613017538463476646)),
      simde_mm_set_epi64x(INT64_C(-8247421513208151154), INT64_C(-1150990985458942599)),
      simde_mm_set_epi64x(INT64_C( -397205761170436875), INT64_C( 1009053596627706250)) },
    { simde_mm_set_epi64x(INT64_C( 8688276933216716257), INT64_C( -409477294924409172)),
      simde_mm_set_epi64x(INT64_C( 7651480072460119172), INT64_C( 5980691967331237074)),
      simde_mm_set_epi64x(INT64_C( 1036796860756597085), INT64_C( -409477294924409172)) },
    { simde_mm_set_epi64x(INT64_C(-6308927419868714376), INT64_C( 6327163388033237975)),
      simde_mm_set_epi64x(INT64_C( 4310605020200368092), INT64_C( 1934689183910316990)),
      simde_mm_set_epi64x(INT64_C(-1998322399668346284), INT64_C(  523095836302287005)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_mod_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_pd1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set_epi64x)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_set1_epi64x)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setr_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setr_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setr_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setr_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setr_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setzero_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_setzero_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_abs_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_add_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_adds_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_adds_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_adds_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_adds_epu16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_and_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_andnot_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_andnot_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_avg_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_avg_epu16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_bslli_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_bsrli_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srli_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sra_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sra_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srai_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srai_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_pd1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeh_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storel_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storel_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storer_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_si16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_store1_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_si64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sub_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_subs_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_subs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_subs_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_subs_epu16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_sd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_su32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mulhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mulhi_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mullo_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmplt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnlt_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnlt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnle_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnle_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpgt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpngt_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpngt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnge_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpnge_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpord_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpord_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpunord_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpunord_sd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_castpd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_castps_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_castsi128_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_castsi128_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comieq_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comige_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comigt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comile_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comilt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comineq_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomieq_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomige_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomigt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomile_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomilt_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ucomineq_sd)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_copysign_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_xorsign_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi32_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi32_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpd_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpd_pi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtpi32_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsd_f64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsd_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsd_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsd_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cvtsi128_si16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi128_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi128_si64)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cvtsi16_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi32_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi32_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi64_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsi64_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtss_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttpd_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttpd_pi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttps_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttsd_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttsd_si64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_div_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_div_sd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_extract_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_insert_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_pd1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_load_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadh_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadl_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadl_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadr_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_si16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_si32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_si64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movemask_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movemask_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskmoveu_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_move_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_move_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movepi64_pi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movpi64_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_or_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_or_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_packs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_packs_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_packus_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_undefined_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_undefined_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_unpacklo_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shuffle_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shuffle_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shufflehi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shufflelo_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sll_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sll_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sll_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srl_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srl_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srl_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sqrt_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sqrt_sd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_madd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sad_epu8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_xor_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_xor_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_not_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_sub_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_mul_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_mod_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
