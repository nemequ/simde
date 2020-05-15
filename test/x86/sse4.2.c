/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX sse4_2
#include <test/x86/test-x86-internal.h>
#include <simde/x86/sse4.2.h>

#if defined(SIMDE_X86_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm_cmpestrs_8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;
  const struct {
    simde__m128i a;
    int la;
    simde__m128i b;
    int lb;
    int r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-105), INT8_C(-116), INT8_C( -45), INT8_C(-102),
                        INT8_C(  -3), INT8_C(  92), INT8_C( -99), INT8_C( 100),
                        INT8_C(  30), INT8_C(-115), INT8_C(  82), INT8_C(  84),
                        INT8_C(-106), INT8_C(  66), INT8_C(-107), INT8_C( 116)),
      0 ,
      simde_mm_set_epi8(INT8_C( -89), INT8_C(  65), INT8_C(  68), INT8_C( -29),
                        INT8_C(-101), INT8_C( 113), INT8_C( -11), INT8_C(  53),
                        INT8_C(  -5), INT8_C( -76), INT8_C(  28), INT8_C(-120),
                        INT8_C(  64), INT8_C(  43), INT8_C(-127), INT8_C( -44)),
      2 ,
      1 },
    { simde_mm_set_epi8(INT8_C( 103), INT8_C(  89), INT8_C( 106), INT8_C( -90),
                        INT8_C(  18), INT8_C(  23), INT8_C( 117), INT8_C(   6),
                        INT8_C( -91), INT8_C( -40), INT8_C( 108), INT8_C(-127),
                        INT8_C( -29), INT8_C( -39), INT8_C(  49), INT8_C( -85)),
      5 ,
      simde_mm_set_epi8(INT8_C(-104), INT8_C( 100), INT8_C( -73), INT8_C( -23),
                        INT8_C( -48), INT8_C(  87), INT8_C(-118), INT8_C(  66),
                        INT8_C( -75), INT8_C(  35), INT8_C(  -1), INT8_C( 111),
                        INT8_C( -30), INT8_C(  -6), INT8_C(  10), INT8_C(  91)),
      10 ,
      1 },
    { simde_mm_set_epi8(INT8_C(  84), INT8_C(  21), INT8_C(  91), INT8_C( -41),
                        INT8_C(  25), INT8_C( -24), INT8_C(  93), INT8_C(-124),
                        INT8_C( -97), INT8_C( -88), INT8_C( 113), INT8_C(  85),
                        INT8_C(  42), INT8_C( -93), INT8_C( -37), INT8_C( -18)),
      8 ,
      simde_mm_set_epi8(INT8_C( 117), INT8_C( -42), INT8_C(-112), INT8_C( -67),
                        INT8_C(  -7), INT8_C( -85), INT8_C(  -4), INT8_C( 125),
                        INT8_C(-127), INT8_C( -75), INT8_C(-125), INT8_C( 109),
                        INT8_C(  50), INT8_C( -16), INT8_C(  22), INT8_C(  86)),
      12 ,
      1 },
    { simde_mm_set_epi8(INT8_C( 109), INT8_C(  78), INT8_C(  15), INT8_C( 113),
                        INT8_C(-118), INT8_C( -55), INT8_C(-119), INT8_C(  -4),
                        INT8_C(  29), INT8_C(  32), INT8_C(-107), INT8_C(-117),
                        INT8_C(  79), INT8_C(  29), INT8_C( 126), INT8_C( -75)),
      16 ,
      simde_mm_set_epi8(INT8_C(  -7), INT8_C(  48), INT8_C( 112), INT8_C(  -3),
                        INT8_C(  35), INT8_C( -21), INT8_C( -53), INT8_C(-114),
                        INT8_C( -78), INT8_C(  -5), INT8_C( -11), INT8_C(  91),
                        INT8_C(  53), INT8_C( -34), INT8_C( -19), INT8_C(  11)),
      8 ,
      0 },
    { simde_mm_set_epi8(INT8_C(  39), INT8_C(  98), INT8_C( -40), INT8_C( -94),
                        INT8_C( -37), INT8_C( -39), INT8_C(  -6), INT8_C( -18),
                        INT8_C( -44), INT8_C( 119), INT8_C( -96), INT8_C(  81),
                        INT8_C(-117), INT8_C(-126), INT8_C(  94), INT8_C( -52)),
      0 ,
      simde_mm_set_epi8(INT8_C(  52), INT8_C( -46), INT8_C(  -6), INT8_C( -85),
                        INT8_C(  63), INT8_C(  85), INT8_C( -29), INT8_C( -39),
                        INT8_C( -42), INT8_C(  92), INT8_C( -15), INT8_C(  -6),
                        INT8_C( -75), INT8_C( -86), INT8_C( -68), INT8_C( 108)),
      3 ,
      1 },
    { simde_mm_set_epi8(INT8_C(  60), INT8_C( -84), INT8_C(  55), INT8_C(  82),
                        INT8_C( -32), INT8_C( -86), INT8_C( -19), INT8_C(   6),
                        INT8_C( -73), INT8_C( -96), INT8_C(  56), INT8_C(-116),
                        INT8_C(  40), INT8_C( -91), INT8_C( -58), INT8_C( -53)),
      5 ,
      simde_mm_set_epi8(INT8_C(-125), INT8_C(-121), INT8_C(  94), INT8_C( -81),
                        INT8_C(  51), INT8_C( -18), INT8_C(  57), INT8_C( 114),
                        INT8_C(  65), INT8_C(  21), INT8_C(   1), INT8_C( 122),
                        INT8_C( -29), INT8_C( -17), INT8_C( 114), INT8_C(  17)),
      6 ,
      1 },
    { simde_mm_set_epi8(INT8_C(   7), INT8_C(-112), INT8_C(-109), INT8_C(  25),
                        INT8_C(  65), INT8_C(   3), INT8_C(  18), INT8_C( -17),
                        INT8_C(-117), INT8_C( -64), INT8_C( 123), INT8_C( 112),
                        INT8_C( -54), INT8_C( -32), INT8_C( -28), INT8_C( -54)),
      2 ,
      simde_mm_set_epi8(INT8_C(  20), INT8_C( -94), INT8_C( -95), INT8_C( -11),
                        INT8_C( -10), INT8_C(  45), INT8_C( -14), INT8_C(-103),
                        INT8_C(-109), INT8_C(-101), INT8_C( 112), INT8_C(  -4),
                        INT8_C(  62), INT8_C(-110), INT8_C( 100), INT8_C(  78)),
      14 ,
      1 },
    { simde_mm_set_epi8(INT8_C(  94), INT8_C( -96), INT8_C( -41), INT8_C(-127),
                        INT8_C( 109), INT8_C( -92), INT8_C(  60), INT8_C(  85),
                        INT8_C( -80), INT8_C( -69), INT8_C( -10), INT8_C( 113),
                        INT8_C( -86), INT8_C(  12), INT8_C( -11), INT8_C(  93)),
      0 ,
      simde_mm_set_epi8(INT8_C(  -1), INT8_C( -87), INT8_C( -78), INT8_C(  26),
                        INT8_C(  30), INT8_C( 110), INT8_C( -36), INT8_C(  70),
                        INT8_C(-126), INT8_C( -29), INT8_C( -65), INT8_C( -41),
                        INT8_C( -71), INT8_C(   1), INT8_C( 121), INT8_C(-119)),
      10 ,
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_cmpestrs(test_vec[i].a, test_vec[i].la, test_vec[i].b, test_vec[i].lb, 0);
    munit_assert_int(r, ==, test_vec[i].r);
  }
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpestrs_16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;
  const struct {
    simde__m128i a;
    int la;
    simde__m128i b;
    int lb;
    int r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-26740), INT16_C(-11366), INT16_C(  -676), INT16_C(-25244),
                         INT16_C(  7821), INT16_C( 21076), INT16_C(-27070), INT16_C(-27276)),
      6 ,
      simde_mm_set_epi16(INT16_C(-22719), INT16_C( 17635), INT16_C(-25743), INT16_C( -2763),
                         INT16_C( -1100), INT16_C(  7304), INT16_C( 16427), INT16_C(-32300)),
      7 ,
      1 },
    { simde_mm_set_epi16(INT16_C( 26457), INT16_C( 27302), INT16_C(  4631), INT16_C( 29958),
                         INT16_C(-23080), INT16_C( 27777), INT16_C( -7207), INT16_C( 12715)),
      5 ,
      simde_mm_set_epi16(INT16_C(-26524), INT16_C(-18455), INT16_C(-12201), INT16_C(-30142),
                         INT16_C(-19165), INT16_C(  -145), INT16_C( -7430), INT16_C(  2651)),
      7 ,
      1 },
    { simde_mm_set_epi16(INT16_C( 21525), INT16_C( 23511), INT16_C(  6632), INT16_C( 23940),
                         INT16_C(-24664), INT16_C( 29013), INT16_C( 10915), INT16_C( -9234)),
      5 ,
      simde_mm_set_epi16(INT16_C( 30166), INT16_C(-28483), INT16_C( -1621), INT16_C(  -899),
                         INT16_C(-32331), INT16_C(-31891), INT16_C( 13040), INT16_C(  5718)),
      6 ,
      1 },
    { simde_mm_set_epi16(INT16_C( 27982), INT16_C(  3953), INT16_C(-30007), INT16_C(-30212),
                         INT16_C(  7456), INT16_C(-27253), INT16_C( 20253), INT16_C( 32437)),
      7 ,
      simde_mm_set_epi16(INT16_C( -1744), INT16_C( 28925), INT16_C(  9195), INT16_C(-13426),
                         INT16_C(-19717), INT16_C( -2725), INT16_C( 13790), INT16_C( -4853)),
      5 ,
      1 },
    { simde_mm_set_epi16(INT16_C( 10082), INT16_C(-10078), INT16_C( -9255), INT16_C( -1298),
                         INT16_C(-11145), INT16_C(-24495), INT16_C(-29822), INT16_C( 24268)),
      2 ,
      simde_mm_set_epi16(INT16_C( 13522), INT16_C( -1365), INT16_C( 16213), INT16_C( -7207),
                         INT16_C(-10660), INT16_C( -3590), INT16_C(-19030), INT16_C(-17300)),
      7 ,
      1 },
    { simde_mm_set_epi16(INT16_C( 15532), INT16_C( 14162), INT16_C( -8022), INT16_C( -4858),
                         INT16_C(-18528), INT16_C( 14476), INT16_C( 10405), INT16_C(-14645)),
      7 ,
      simde_mm_set_epi16(INT16_C(-31865), INT16_C( 24239), INT16_C( 13294), INT16_C( 14706),
                         INT16_C( 16661), INT16_C(   378), INT16_C( -7185), INT16_C( 29201)),
      4 ,
      1 },
    { simde_mm_set_epi16(INT16_C(  1936), INT16_C(-27879), INT16_C( 16643), INT16_C(  4847),
                         INT16_C(-29760), INT16_C( 31600), INT16_C(-13600), INT16_C( -6966)),
      7 ,
      simde_mm_set_epi16(INT16_C(  5282), INT16_C(-24075), INT16_C( -2515), INT16_C( -3431),
                         INT16_C(-27749), INT16_C( 28924), INT16_C( 16018), INT16_C( 25678)),
      0 ,
      1 },
    { simde_mm_set_epi16(INT16_C( 24224), INT16_C(-10367), INT16_C( 28068), INT16_C( 15445),
                         INT16_C(-20293), INT16_C( -2447), INT16_C(-22004), INT16_C( -2723)),
      7 ,
      simde_mm_set_epi16(INT16_C(   -87), INT16_C(-19942), INT16_C(  7790), INT16_C( -9146),
                         INT16_C(-32029), INT16_C(-16425), INT16_C(-18175), INT16_C( 31113)),
      2 ,
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_cmpestrs(test_vec[i].a, test_vec[i].la, test_vec[i].b, test_vec[i].lb, 1);
    munit_assert_int(r, ==, test_vec[i].r);
  }
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2149331112921330677), INT64_C( 3189038460188560982)),
      simde_mm_set_epi64x(INT64_C( -996047549682722220), INT64_C(-3995545326609437904)),
      simde_mm_set_epi64x( INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C( 3213898448913237846), INT64_C( 9188286366666087308)),
      simde_mm_set_epi64x(INT64_C( 2918885787365950970), INT64_C( 6780053140456787494)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(-6480415937191367948), INT64_C( 6434069133602920016)),
      simde_mm_set_epi64x(INT64_C( 8054577307931165184), INT64_C( 2226222084862743618)),
      simde_mm_set_epi64x( INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(-6197561420805751907), INT64_C( 4778870285233423339)),
      simde_mm_set_epi64x(INT64_C( 1839658993612937599), INT64_C( -902367911293731861)),
      simde_mm_set_epi64x( INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C( 5091127324004768664), INT64_C(-2002251908801446460)),
      simde_mm_set_epi64x(INT64_C(-9056506211008935561), INT64_C(-6487933609077704174)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(-4743149223868910453), INT64_C(-4137271544350199785)),
      simde_mm_set_epi64x(INT64_C( 4762909370147937560), INT64_C( 6560801355595049799)),
      simde_mm_set_epi64x( INT64_C(0),  INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(  913044205052582612), INT64_C(-2362244502684338485)),
      simde_mm_set_epi64x(INT64_C( -603710511502052754), INT64_C(-3179203207537477667)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C( 6753725813089147170), INT64_C( 7031124288307654085)),
      simde_mm_set_epi64x(INT64_C( 5046765831366456160), INT64_C( 6981054579474564569)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpgt_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_X86_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

#if HEDLEY_HAS_WARNING("-Wold-style-cast")
  #pragma clang diagnostic ignored "-Wold-style-cast"
#endif
#if HEDLEY_HAS_WARNING("-Wzero-as-null-pointer-constant")
  #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_X86_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_cmpestrs_8),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpestrs_16),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_epi64),
#endif /* defined(SIMDE_X86_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

#if defined(SIMDE_TESTS_SINGLE_ISAX)
int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
#endif /* defined(SIMDE_TESTS_SINGLE_ISAX) */

HEDLEY_DIAGNOSTIC_POP
