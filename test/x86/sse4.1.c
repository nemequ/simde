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

#define SIMDE_TESTS_CURRENT_ISAX sse4_1
#include <simde/x86/sse4.1.h>
#include <test/x86/test-sse2.h>

static int
test_simde_mm_blendv_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i mask;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -85), INT8_C( -39), INT8_C(-107), INT8_C( -76),
                        INT8_C( -25), INT8_C( -32), INT8_C( -50), INT8_C(-115),
                        INT8_C( -54), INT8_C( -26), INT8_C(  56), INT8_C(  16),
                        INT8_C( -17), INT8_C(  98), INT8_C( -10), INT8_C( -86)),
      simde_mm_set_epi8(INT8_C( 111), INT8_C( -17), INT8_C(  70), INT8_C( -98),
                        INT8_C(  38), INT8_C(  75), INT8_C(  17), INT8_C( -50),
                        INT8_C( -64), INT8_C(  25), INT8_C(  -4), INT8_C(  42),
                        INT8_C(  13), INT8_C( 109), INT8_C( 122), INT8_C(-104)),
      simde_mm_set_epi8(INT8_C( -13), INT8_C(  21), INT8_C( 111), INT8_C(  -8),
                        INT8_C(  32), INT8_C( -14), INT8_C(  25), INT8_C(  45),
                        INT8_C(  34), INT8_C( -43), INT8_C( -81), INT8_C(  26),
                        INT8_C(-105), INT8_C(  63), INT8_C( -61), INT8_C( -38)),
      simde_mm_set_epi8(INT8_C( 111), INT8_C( -39), INT8_C(-107), INT8_C( -98),
                        INT8_C( -25), INT8_C(  75), INT8_C( -50), INT8_C(-115),
                        INT8_C( -54), INT8_C(  25), INT8_C(  -4), INT8_C(  16),
                        INT8_C(  13), INT8_C(  98), INT8_C( 122), INT8_C(-104)) },
    { simde_mm_set_epi8(INT8_C( -79), INT8_C(  12), INT8_C( 105), INT8_C( -95),
                        INT8_C( -27), INT8_C(  97), INT8_C( 123), INT8_C(  -2),
                        INT8_C( -75), INT8_C( -82), INT8_C( -63), INT8_C( 121),
                        INT8_C(  39), INT8_C( -40), INT8_C(-103), INT8_C( -72)),
      simde_mm_set_epi8(INT8_C( -77), INT8_C( -58), INT8_C( -15), INT8_C( -99),
                        INT8_C(-120), INT8_C( 124), INT8_C(  40), INT8_C(  82),
                        INT8_C( 121), INT8_C(  50), INT8_C(-103), INT8_C( -45),
                        INT8_C(-125), INT8_C( -55), INT8_C( -57), INT8_C( -95)),
      simde_mm_set_epi8(INT8_C( -97), INT8_C( -10), INT8_C( 107), INT8_C(  95),
                        INT8_C(  99), INT8_C(-103), INT8_C( 112), INT8_C( -80),
                        INT8_C( -21), INT8_C(  52), INT8_C(-128), INT8_C(   9),
                        INT8_C(  47), INT8_C( -45), INT8_C( -98), INT8_C(  67)),
      simde_mm_set_epi8(INT8_C( -77), INT8_C( -58), INT8_C( 105), INT8_C( -95),
                        INT8_C( -27), INT8_C( 124), INT8_C( 123), INT8_C(  82),
                        INT8_C( 121), INT8_C( -82), INT8_C(-103), INT8_C( 121),
                        INT8_C(  39), INT8_C( -55), INT8_C( -57), INT8_C( -72)) },
    { simde_mm_set_epi8(INT8_C(  65), INT8_C(  33), INT8_C( -24), INT8_C( -68),
                        INT8_C( -81), INT8_C( 103), INT8_C( -77), INT8_C( -49),
                        INT8_C(  99), INT8_C(  55), INT8_C(  98), INT8_C(  36),
                        INT8_C(  31), INT8_C(  86), INT8_C( -79), INT8_C( 106)),
      simde_mm_set_epi8(INT8_C( 101), INT8_C(  91), INT8_C( -24), INT8_C(  33),
                        INT8_C( -68), INT8_C(-109), INT8_C( -92), INT8_C( -49),
                        INT8_C( -88), INT8_C(  86), INT8_C( 106), INT8_C( 125),
                        INT8_C(  81), INT8_C( -60), INT8_C( -32), INT8_C(  38)),
      simde_mm_set_epi8(INT8_C(   3), INT8_C(  58), INT8_C(  40), INT8_C(  64),
                        INT8_C(   7), INT8_C(-123), INT8_C(  47), INT8_C(  24),
                        INT8_C( -14), INT8_C( 119), INT8_C(   8), INT8_C( 126),
                        INT8_C( 123), INT8_C(  25), INT8_C(  42), INT8_C(-118)),
      simde_mm_set_epi8(INT8_C(  65), INT8_C(  33), INT8_C( -24), INT8_C( -68),
                        INT8_C( -81), INT8_C(-109), INT8_C( -77), INT8_C( -49),
                        INT8_C( -88), INT8_C(  55), INT8_C(  98), INT8_C(  36),
                        INT8_C(  31), INT8_C(  86), INT8_C( -79), INT8_C(  38)) },
    { simde_mm_set_epi8(INT8_C(  34), INT8_C(-102), INT8_C(  26), INT8_C(   6),
                        INT8_C( -98), INT8_C(-126), INT8_C(  34), INT8_C( 109),
                        INT8_C( -65), INT8_C( -47), INT8_C(  54), INT8_C(-102),
                        INT8_C(  52), INT8_C(  72), INT8_C(  95), INT8_C(-117)),
      simde_mm_set_epi8(INT8_C( -47), INT8_C(   2), INT8_C(  12), INT8_C(  -2),
                        INT8_C( 113), INT8_C(  15), INT8_C( -36), INT8_C(  63),
                        INT8_C(  39), INT8_C(  47), INT8_C( -65), INT8_C(  45),
                        INT8_C( -99), INT8_C(  91), INT8_C(-116), INT8_C(  94)),
      simde_mm_set_epi8(INT8_C( -98), INT8_C(  39), INT8_C(  27), INT8_C(-110),
                        INT8_C( -56), INT8_C( 121), INT8_C(  15), INT8_C( 100),
                        INT8_C(  94), INT8_C(   8), INT8_C(-121), INT8_C( 116),
                        INT8_C(  47), INT8_C(-128), INT8_C(  82), INT8_C(  52)),
      simde_mm_set_epi8(INT8_C( -47), INT8_C(-102), INT8_C(  26), INT8_C(  -2),
                        INT8_C( 113), INT8_C(-126), INT8_C(  34), INT8_C( 109),
                        INT8_C( -65), INT8_C( -47), INT8_C( -65), INT8_C(-102),
                        INT8_C(  52), INT8_C(  91), INT8_C(  95), INT8_C(-117)) },
    { simde_mm_set_epi8(INT8_C( 114), INT8_C(-111), INT8_C(  -9), INT8_C( -74),
                        INT8_C(  56), INT8_C( -88), INT8_C( 102), INT8_C(   9),
                        INT8_C( 123), INT8_C(-124), INT8_C(   2), INT8_C( -90),
                        INT8_C( -87), INT8_C(-122), INT8_C( -39), INT8_C(-114)),
      simde_mm_set_epi8(INT8_C( -81), INT8_C( -26), INT8_C(  59), INT8_C(   3),
                        INT8_C( 113), INT8_C( -96), INT8_C(-108), INT8_C(  77),
                        INT8_C( -17), INT8_C(  59), INT8_C( -35), INT8_C(  43),
                        INT8_C( 117), INT8_C(  11), INT8_C(-103), INT8_C( -21)),
      simde_mm_set_epi8(INT8_C(-116), INT8_C( 124), INT8_C( -23), INT8_C( -24),
                        INT8_C(-105), INT8_C( -39), INT8_C(  45), INT8_C( -32),
                        INT8_C(   5), INT8_C( -60), INT8_C( -98), INT8_C( 111),
                        INT8_C(-112), INT8_C( -60), INT8_C(   8), INT8_C(  13)),
      simde_mm_set_epi8(INT8_C( -81), INT8_C(-111), INT8_C(  59), INT8_C(   3),
                        INT8_C( 113), INT8_C( -96), INT8_C( 102), INT8_C(  77),
                        INT8_C( 123), INT8_C(  59), INT8_C( -35), INT8_C( -90),
                        INT8_C( 117), INT8_C(  11), INT8_C( -39), INT8_C(-114)) },
    { simde_mm_set_epi8(INT8_C(  53), INT8_C( -97), INT8_C(  79), INT8_C( -93),
                        INT8_C(  55), INT8_C(-115), INT8_C( -80), INT8_C( -27),
                        INT8_C( 104), INT8_C( 109), INT8_C( -16), INT8_C( -75),
                        INT8_C( 125), INT8_C(   6), INT8_C(  38), INT8_C( -55)),
      simde_mm_set_epi8(INT8_C(  48), INT8_C(  25), INT8_C(  24), INT8_C( -17),
                        INT8_C(-102), INT8_C( -66), INT8_C(  -6), INT8_C(  22),
                        INT8_C(-100), INT8_C( -56), INT8_C(  25), INT8_C( -26),
                        INT8_C( -37), INT8_C(  49), INT8_C(   8), INT8_C(  -6)),
      simde_mm_set_epi8(INT8_C(-114), INT8_C(  27), INT8_C( -68), INT8_C(   3),
                        INT8_C(  88), INT8_C(  71), INT8_C(  77), INT8_C( 108),
                        INT8_C(-112), INT8_C( 117), INT8_C(-100), INT8_C( -26),
                        INT8_C(  86), INT8_C( -48), INT8_C( -34), INT8_C( -71)),
      simde_mm_set_epi8(INT8_C(  48), INT8_C( -97), INT8_C(  24), INT8_C( -93),
                        INT8_C(  55), INT8_C(-115), INT8_C( -80), INT8_C( -27),
                        INT8_C(-100), INT8_C( 109), INT8_C(  25), INT8_C( -26),
                        INT8_C( 125), INT8_C(  49), INT8_C(   8), INT8_C(  -6)) },
    { simde_mm_set_epi8(INT8_C(-121), INT8_C(  29), INT8_C( -87), INT8_C(  80),
                        INT8_C(  19), INT8_C(  64), INT8_C( 104), INT8_C(  67),
                        INT8_C( -22), INT8_C( -16), INT8_C( -57), INT8_C( -78),
                        INT8_C( -96), INT8_C(-113), INT8_C( 114), INT8_C(  15)),
      simde_mm_set_epi8(INT8_C(  99), INT8_C( -98), INT8_C( 122), INT8_C( 119),
                        INT8_C(  80), INT8_C( -87), INT8_C( -77), INT8_C( -36),
                        INT8_C(  10), INT8_C(  99), INT8_C( 114), INT8_C( -46),
                        INT8_C( -79), INT8_C( -58), INT8_C( -87), INT8_C( 106)),
      simde_mm_set_epi8(INT8_C( -96), INT8_C(  67), INT8_C( -85), INT8_C(  80),
                        INT8_C( 107), INT8_C(   9), INT8_C(  20), INT8_C(  91),
                        INT8_C( -58), INT8_C(  -6), INT8_C( 120), INT8_C( -24),
                        INT8_C(  26), INT8_C( -94), INT8_C( -17), INT8_C(  25)),
      simde_mm_set_epi8(INT8_C(  99), INT8_C(  29), INT8_C( 122), INT8_C(  80),
                        INT8_C(  19), INT8_C(  64), INT8_C( 104), INT8_C(  67),
                        INT8_C(  10), INT8_C(  99), INT8_C( -57), INT8_C( -46),
                        INT8_C( -96), INT8_C( -58), INT8_C( -87), INT8_C(  15)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C(  28), INT8_C( -62), INT8_C( 108),
                        INT8_C( -15), INT8_C(  17), INT8_C( -48), INT8_C(  13),
                        INT8_C(  32), INT8_C( -56), INT8_C(  83), INT8_C( -65),
                        INT8_C(  73), INT8_C(-114), INT8_C(  47), INT8_C(  99)),
      simde_mm_set_epi8(INT8_C(  84), INT8_C( -32), INT8_C(  -4), INT8_C(   8),
                        INT8_C(  66), INT8_C( -71), INT8_C( -69), INT8_C( -41),
                        INT8_C( -21), INT8_C( -40), INT8_C(  64), INT8_C( -47),
                        INT8_C(  16), INT8_C( -61), INT8_C(   3), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C(  27), INT8_C( 104), INT8_C( -26), INT8_C( -51),
                        INT8_C( 114), INT8_C(  -9), INT8_C( -56), INT8_C( 125),
                        INT8_C(  41), INT8_C( -51), INT8_C(  26), INT8_C( 121),
                        INT8_C( -16), INT8_C( -59), INT8_C(  93), INT8_C( -56)),
      simde_mm_set_epi8(INT8_C( -13), INT8_C(  28), INT8_C(  -4), INT8_C(   8),
                        INT8_C( -15), INT8_C( -71), INT8_C( -69), INT8_C(  13),
                        INT8_C(  32), INT8_C( -40), INT8_C(  83), INT8_C( -65),
                        INT8_C(  16), INT8_C( -61), INT8_C(  47), INT8_C( -15)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_blendv_epi8(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_blendv_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i mask;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( -5889), INT16_C( -9240), INT16_C( 13406), INT16_C( 23197),
                         INT16_C( 25390), INT16_C( 20613), INT16_C( -3211), INT16_C( -5281)),
      simde_mm_set_epi16(INT16_C( -5787), INT16_C(   260), INT16_C(-28529), INT16_C(  -341),
                         INT16_C( 26074), INT16_C(-30339), INT16_C( -9562), INT16_C( -4010)),
      simde_mm_set_epi16(INT16_C( 11580), INT16_C(-26297), INT16_C(  8234), INT16_C( -6769),
                         INT16_C( -3010), INT16_C( 26987), INT16_C( 26235), INT16_C(-23439)),
      simde_mm_set_epi16(INT16_C( -5889), INT16_C(   260), INT16_C( 13406), INT16_C(  -341),
                         INT16_C( 26074), INT16_C( 20613), INT16_C( -3211), INT16_C( -4010)) },
    { simde_mm_set_epi16(INT16_C(-10477), INT16_C(  1551), INT16_C(-16362), INT16_C(-15016),
                         INT16_C( -3374), INT16_C(-19084), INT16_C(  -221), INT16_C(-19089)),
      simde_mm_set_epi16(INT16_C(  8603), INT16_C(  8519), INT16_C(  4642), INT16_C(  1129),
                         INT16_C(  6053), INT16_C( 28257), INT16_C( 10987), INT16_C(-17611)),
      simde_mm_set_epi16(INT16_C(-14703), INT16_C( 23402), INT16_C( -5363), INT16_C( 25451),
                         INT16_C(  4787), INT16_C(  6143), INT16_C( -8049), INT16_C(-25291)),
      simde_mm_set_epi16(INT16_C(  8603), INT16_C(  1551), INT16_C(  4642), INT16_C(-15016),
                         INT16_C( -3374), INT16_C(-19084), INT16_C( 10987), INT16_C(-17611)) },
    { simde_mm_set_epi16(INT16_C(-10958), INT16_C(   239), INT16_C(-29416), INT16_C( 25642),
                         INT16_C(-31255), INT16_C( 18557), INT16_C( 17603), INT16_C(  9411)),
      simde_mm_set_epi16(INT16_C(-22204), INT16_C(-12104), INT16_C( 21385), INT16_C(   163),
                         INT16_C(-13806), INT16_C( -4673), INT16_C(-31502), INT16_C( 30113)),
      simde_mm_set_epi16(INT16_C( 26590), INT16_C(-27173), INT16_C(  3052), INT16_C( 29423),
                         INT16_C( 14159), INT16_C( 16581), INT16_C( 15114), INT16_C( 31350)),
      simde_mm_set_epi16(INT16_C(-10958), INT16_C(-12104), INT16_C(-29416), INT16_C( 25642),
                         INT16_C(-31255), INT16_C( 18557), INT16_C( 17603), INT16_C(  9411)) },
    { simde_mm_set_epi16(INT16_C( -8795), INT16_C(-24496), INT16_C(-21018), INT16_C(-23768),
                         INT16_C( 25939), INT16_C( -2265), INT16_C( 13801), INT16_C( 28390)),
      simde_mm_set_epi16(INT16_C(-31776), INT16_C(  7886), INT16_C( 19773), INT16_C( 11337),
                         INT16_C( -9683), INT16_C(-15212), INT16_C(-11745), INT16_C(-21367)),
      simde_mm_set_epi16(INT16_C(-30437), INT16_C( -4024), INT16_C(-15989), INT16_C( -4852),
                         INT16_C( 20067), INT16_C( 28092), INT16_C(-20772), INT16_C( 17444)),
      simde_mm_set_epi16(INT16_C(-31776), INT16_C(  7886), INT16_C( 19773), INT16_C( 11337),
                         INT16_C( 25939), INT16_C( -2265), INT16_C(-11745), INT16_C( 28390)) },
    { simde_mm_set_epi16(INT16_C( 11712), INT16_C( 21433), INT16_C( -1195), INT16_C( 25259),
                         INT16_C( 18957), INT16_C(  5262), INT16_C( -9688), INT16_C(-14506)),
      simde_mm_set_epi16(INT16_C( 24574), INT16_C(  2777), INT16_C(-18691), INT16_C(  4928),
                         INT16_C( 32122), INT16_C(-10541), INT16_C(  2746), INT16_C(  8282)),
      simde_mm_set_epi16(INT16_C(  5301), INT16_C( 12242), INT16_C( 18664), INT16_C( 26110),
                         INT16_C(-14367), INT16_C( -9137), INT16_C( -7209), INT16_C( 24768)),
      simde_mm_set_epi16(INT16_C( 11712), INT16_C( 21433), INT16_C( -1195), INT16_C( 25259),
                         INT16_C( 32122), INT16_C(-10541), INT16_C(  2746), INT16_C(-14506)) },
    { simde_mm_set_epi16(INT16_C(-20542), INT16_C(  3332), INT16_C( 24354), INT16_C(-23695),
                         INT16_C(-10493), INT16_C( 32452), INT16_C(-26923), INT16_C( 16579)),
      simde_mm_set_epi16(INT16_C( 29156), INT16_C(  8347), INT16_C(-32604), INT16_C(-24707),
                         INT16_C(-20393), INT16_C(-18566), INT16_C( 17032), INT16_C(-18520)),
      simde_mm_set_epi16(INT16_C(-23886), INT16_C( 30820), INT16_C( 12721), INT16_C(-28893),
                         INT16_C( -7688), INT16_C( 11154), INT16_C(-11967), INT16_C( 31969)),
      simde_mm_set_epi16(INT16_C( 29156), INT16_C(  3332), INT16_C( 24354), INT16_C(-24707),
                         INT16_C(-20393), INT16_C( 32452), INT16_C( 17032), INT16_C( 16579)) },
    { simde_mm_set_epi16(INT16_C( 22583), INT16_C(  4415), INT16_C(-24878), INT16_C(-15401),
                         INT16_C(-29840), INT16_C(-16999), INT16_C(-23406), INT16_C(-32259)),
      simde_mm_set_epi16(INT16_C( 31553), INT16_C( 23166), INT16_C(-15560), INT16_C( 31886),
                         INT16_C(  7368), INT16_C(-15822), INT16_C(-17797), INT16_C(  1487)),
      simde_mm_set_epi16(INT16_C(-12147), INT16_C(  2989), INT16_C(-24661), INT16_C(-22664),
                         INT16_C(-16476), INT16_C(   408), INT16_C(-13750), INT16_C(-15888)),
      simde_mm_set_epi16(INT16_C( 31553), INT16_C(  4415), INT16_C(-15560), INT16_C( 31886),
                         INT16_C(  7368), INT16_C(-16999), INT16_C(-17797), INT16_C(  1487)) },
    { simde_mm_set_epi16(INT16_C( 32299), INT16_C(  7492), INT16_C( 26066), INT16_C( 30675),
                         INT16_C( 26958), INT16_C(  8712), INT16_C(-17582), INT16_C(-18062)),
      simde_mm_set_epi16(INT16_C( 25592), INT16_C(  2248), INT16_C(-21774), INT16_C(  7511),
                         INT16_C(  6101), INT16_C( 18791), INT16_C(-31731), INT16_C( 22067)),
      simde_mm_set_epi16(INT16_C(-26320), INT16_C( 16537), INT16_C(-11326), INT16_C(  8393),
                         INT16_C(-25832), INT16_C( 24810), INT16_C(-17206), INT16_C(-26982)),
      simde_mm_set_epi16(INT16_C( 25592), INT16_C(  7492), INT16_C(-21774), INT16_C( 30675),
                         INT16_C(  6101), INT16_C(  8712), INT16_C(-31731), INT16_C( 22067)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_blendv_epi16(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_blendv_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i mask;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -385885208), INT32_C(  878598813), INT32_C( 1663979653), INT32_C( -210375841)),
      simde_mm_set_epi32(INT32_C( -379256572), INT32_C(-1869611349), INT32_C( 1708820861), INT32_C( -626593706)),
      simde_mm_set_epi32(INT32_C(  758946119), INT32_C(  539682191), INT32_C( -197236373), INT32_C( 1719379057)),
      simde_mm_set_epi32(INT32_C( -385885208), INT32_C(  878598813), INT32_C( 1708820861), INT32_C( -210375841)) },
    { simde_mm_set_epi32(INT32_C( -686619121), INT32_C(-1072249512), INT32_C( -221072012), INT32_C(  -14437009)),
      simde_mm_set_epi32(INT32_C(  563814727), INT32_C(  304219241), INT32_C(  396717665), INT32_C(  720091957)),
      simde_mm_set_epi32(INT32_C( -963552406), INT32_C( -351444117), INT32_C(  313726975), INT32_C( -527459019)),
      simde_mm_set_epi32(INT32_C(  563814727), INT32_C(  304219241), INT32_C( -221072012), INT32_C(  720091957)) },
    { simde_mm_set_epi32(INT32_C( -718143249), INT32_C(-1927781334), INT32_C(-2048309123), INT32_C( 1153639619)),
      simde_mm_set_epi32(INT32_C(-1455107912), INT32_C( 1401487523), INT32_C( -904729153), INT32_C(-2064484959)),
      simde_mm_set_epi32(INT32_C( 1742640603), INT32_C(  200045295), INT32_C(  927940805), INT32_C(  990542454)),
      simde_mm_set_epi32(INT32_C( -718143249), INT32_C(-1927781334), INT32_C(-2048309123), INT32_C( 1153639619)) },
    { simde_mm_set_epi32(INT32_C( -576348080), INT32_C(-1377393880), INT32_C( 1700001575), INT32_C(  904490726)),
      simde_mm_set_epi32(INT32_C(-2082464050), INT32_C( 1295854665), INT32_C( -634534764), INT32_C( -769676151)),
      simde_mm_set_epi32(INT32_C(-1994657720), INT32_C(-1047794420), INT32_C( 1315139004), INT32_C(-1361296348)),
      simde_mm_set_epi32(INT32_C(-2082464050), INT32_C( 1295854665), INT32_C( 1700001575), INT32_C( -769676151)) },
    { simde_mm_set_epi32(INT32_C(  767579065), INT32_C(  -78290261), INT32_C( 1242371214), INT32_C( -634861738)),
      simde_mm_set_epi32(INT32_C( 1610484441), INT32_C(-1224928448), INT32_C( 2105202387), INT32_C(  179970138)),
      simde_mm_set_epi32(INT32_C(  347418578), INT32_C( 1223190014), INT32_C( -941499313), INT32_C( -472424256)),
      simde_mm_set_epi32(INT32_C(  767579065), INT32_C(  -78290261), INT32_C( 2105202387), INT32_C(  179970138)) },
    { simde_mm_set_epi32(INT32_C(-1346237180), INT32_C( 1596105585), INT32_C( -687636796), INT32_C(-1764409149)),
      simde_mm_set_epi32(INT32_C( 1910775963), INT32_C(-2136694915), INT32_C(-1336428678), INT32_C( 1116256168)),
      simde_mm_set_epi32(INT32_C(-1565362076), INT32_C(  833720099), INT32_C( -503829614), INT32_C( -784237343)),
      simde_mm_set_epi32(INT32_C( 1910775963), INT32_C( 1596105585), INT32_C(-1336428678), INT32_C( 1116256168)) },
    { simde_mm_set_epi32(INT32_C( 1480003903), INT32_C(-1630354473), INT32_C(-1955545703), INT32_C(-1533902339)),
      simde_mm_set_epi32(INT32_C( 2067880574), INT32_C(-1019708274), INT32_C(  482918962), INT32_C(-1166342705)),
      simde_mm_set_epi32(INT32_C( -796062803), INT32_C(-1616140424), INT32_C(-1079770728), INT32_C( -901070352)),
      simde_mm_set_epi32(INT32_C( 2067880574), INT32_C(-1019708274), INT32_C(  482918962), INT32_C(-1166342705)) },
    { simde_mm_set_epi32(INT32_C( 2116754756), INT32_C( 1708292051), INT32_C( 1766728200), INT32_C(-1152206478)),
      simde_mm_set_epi32(INT32_C( 1677199560), INT32_C(-1426973353), INT32_C(  399853927), INT32_C(-2079500749)),
      simde_mm_set_epi32(INT32_C(-1724890983), INT32_C( -742252343), INT32_C(-1692901142), INT32_C(-1127573862)),
      simde_mm_set_epi32(INT32_C( 1677199560), INT32_C(-1426973353), INT32_C(  399853927), INT32_C(-2079500749)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_blendv_epi32(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_blendv_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i mask;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-1657364347491558755), INT64_C( 7146738194929019743)),
      simde_mm_set_epi64x(INT64_C(-1628894571107713365), INT64_C( 7339329716385935446)),
      simde_mm_set_epi64x(INT64_C( 3259648761070806415), INT64_C( -847123769897278351)),
      simde_mm_set_epi64x(INT64_C(-1657364347491558755), INT64_C( 7339329716385935446)) },
    { simde_mm_set_epi64x(INT64_C(-2949006666280549032), INT64_C( -949497057320389265)),
      simde_mm_set_epi64x(INT64_C( 2421565813772387433), INT64_C( 1703889397640575797)),
      simde_mm_set_epi64x(INT64_C(-4138426067808590997), INT64_C( 1347447101265517877)),
      simde_mm_set_epi64x(INT64_C( 2421565813772387433), INT64_C( -949497057320389265)) },
    { simde_mm_set_epi64x(INT64_C(-3084401765930998742), INT64_C(-8797420694229801789)),
      simde_mm_set_epi64x(INT64_C(-6249640892789358429), INT64_C(-3885782121642297951)),
      simde_mm_set_epi64x(INT64_C( 7484584398766764783), INT64_C( 3985475411089455734)),
      simde_mm_set_epi64x(INT64_C(-3084401765930998742), INT64_C(-8797420694229801789)) },
    { simde_mm_set_epi64x(INT64_C(-2475396151794818264), INT64_C( 7301451168677981926)),
      simde_mm_set_epi64x(INT64_C(-8944114988549854135), INT64_C(-2725306056029786999)),
      simde_mm_set_epi64x(INT64_C(-8566989670866752244), INT64_C( 5648479014807684132)),
      simde_mm_set_epi64x(INT64_C(-8944114988549854135), INT64_C( 7301451168677981926)) },
    { simde_mm_set_epi64x(INT64_C( 3296726985485935275), INT64_C( 5335943737281922902)),
      simde_mm_set_epi64x(INT64_C( 6916978007881880384), INT64_C( 9041775403806105690)),
      simde_mm_set_epi64x(INT64_C( 1492151431756015102), INT64_C(-4043708754718924608)),
      simde_mm_set_epi64x(INT64_C( 3296726985485935275), INT64_C( 9041775403806105690)) },
    { simde_mm_set_epi64x(INT64_C(-5782044659163159695), INT64_C(-2953377547815665469)),
      simde_mm_set_epi64x(INT64_C( 8206720273226178429), INT64_C(-5739917464330258520)),
      simde_mm_set_epi64x(INT64_C(-6723178921984946397), INT64_C(-2163931711375573791)),
      simde_mm_set_epi64x(INT64_C( 8206720273226178429), INT64_C(-5739917464330258520)) },
    { simde_mm_set_epi64x(INT64_C( 6356568364001969111), INT64_C(-8399004837457264131)),
      simde_mm_set_epi64x(INT64_C( 8881479440638966926), INT64_C( 2074121151536891343)),
      simde_mm_set_epi64x(INT64_C(-3419063701768263816), INT64_C(-4637579960544214544)),
      simde_mm_set_epi64x(INT64_C( 8881479440638966926), INT64_C( 2074121151536891343)) },
    { simde_mm_set_epi64x(INT64_C( 9091392452380751827), INT64_C( 7588039843063708018)),
      simde_mm_set_epi64x(INT64_C( 7203517261933583703), INT64_C( 1717359541857637939)),
      simde_mm_set_epi64x(INT64_C(-7408350357597577015), INT64_C(-7270955037083658598)),
      simde_mm_set_epi64x(INT64_C( 7203517261933583703), INT64_C( 1717359541857637939)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_blendv_epi64(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_blend_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 13825), INT16_C(-17802), INT16_C( -1598), INT16_C( 25326),
                         INT16_C( 14943), INT16_C( -8227), INT16_C( 21745), INT16_C(  9989)),
      simde_mm_set_epi16(INT16_C(-11058), INT16_C(  4192), INT16_C(-28252), INT16_C( 10795),
                         INT16_C( 19700), INT16_C( 29704), INT16_C( -7052), INT16_C( 16432)),
      simde_mm_set_epi16(INT16_C( 13825), INT16_C(-17802), INT16_C( -1598), INT16_C( 25326),
                         INT16_C( 14943), INT16_C( -8227), INT16_C( -7052), INT16_C( 16432)) },
    { simde_mm_set_epi16(INT16_C(-17914), INT16_C(-32103), INT16_C( 17164), INT16_C(  -187),
                         INT16_C( 21942), INT16_C(-25306), INT16_C( -7849), INT16_C(-11297)),
      simde_mm_set_epi16(INT16_C( -9027), INT16_C(-14363), INT16_C( 16126), INT16_C( 30921),
                         INT16_C(  3730), INT16_C(-20492), INT16_C( -5510), INT16_C( 32723)),
      simde_mm_set_epi16(INT16_C(-17914), INT16_C(-32103), INT16_C( 17164), INT16_C(  -187),
                         INT16_C( 21942), INT16_C(-25306), INT16_C( -5510), INT16_C( 32723)) },
    { simde_mm_set_epi16(INT16_C(-25152), INT16_C( 30665), INT16_C( 26270), INT16_C( 23820),
                         INT16_C(-24322), INT16_C(   706), INT16_C(-26336), INT16_C(-13296)),
      simde_mm_set_epi16(INT16_C(-24671), INT16_C(-19680), INT16_C( 10653), INT16_C( -9500),
                         INT16_C(-16899), INT16_C(   495), INT16_C( 26780), INT16_C(-11315)),
      simde_mm_set_epi16(INT16_C(-25152), INT16_C( 30665), INT16_C( 26270), INT16_C( 23820),
                         INT16_C(-24322), INT16_C(   706), INT16_C( 26780), INT16_C(-11315)) },
    { simde_mm_set_epi16(INT16_C( 20562), INT16_C(-19834), INT16_C(  5180), INT16_C( -5117),
                         INT16_C( 16168), INT16_C( 23520), INT16_C(-16838), INT16_C( 28892)),
      simde_mm_set_epi16(INT16_C(  2860), INT16_C( -6670), INT16_C(-25365), INT16_C( -4954),
                         INT16_C( 30912), INT16_C(  6045), INT16_C(  2749), INT16_C(  4401)),
      simde_mm_set_epi16(INT16_C( 20562), INT16_C(-19834), INT16_C(  5180), INT16_C( -5117),
                         INT16_C( 16168), INT16_C( 23520), INT16_C(  2749), INT16_C(  4401)) },
    { simde_mm_set_epi16(INT16_C( 25997), INT16_C( -1860), INT16_C( -9126), INT16_C( 12214),
                         INT16_C(  7159), INT16_C( -2303), INT16_C(  7182), INT16_C(-20779)),
      simde_mm_set_epi16(INT16_C( -7432), INT16_C(   954), INT16_C(-26453), INT16_C( -2062),
                         INT16_C( 14984), INT16_C( -7563), INT16_C( 13369), INT16_C( -4134)),
      simde_mm_set_epi16(INT16_C( 25997), INT16_C( -1860), INT16_C( -9126), INT16_C( 12214),
                         INT16_C(  7159), INT16_C( -2303), INT16_C( 13369), INT16_C( -4134)) },
    { simde_mm_set_epi16(INT16_C( -6104), INT16_C(-18564), INT16_C(  5298), INT16_C( -6001),
                         INT16_C( -6122), INT16_C( 14804), INT16_C(-32440), INT16_C(-10960)),
      simde_mm_set_epi16(INT16_C(  8197), INT16_C( 14220), INT16_C(-10924), INT16_C( 17196),
                         INT16_C( 21768), INT16_C(  7639), INT16_C( -4935), INT16_C(  -993)),
      simde_mm_set_epi16(INT16_C( -6104), INT16_C(-18564), INT16_C(  5298), INT16_C( -6001),
                         INT16_C( -6122), INT16_C( 14804), INT16_C( -4935), INT16_C(  -993)) },
    { simde_mm_set_epi16(INT16_C(  6003), INT16_C( -5880), INT16_C( 31967), INT16_C(-28984),
                         INT16_C( -9503), INT16_C( 30320), INT16_C(-19146), INT16_C( 32146)),
      simde_mm_set_epi16(INT16_C(  4317), INT16_C( 22644), INT16_C(-25807), INT16_C(-30524),
                         INT16_C(   223), INT16_C( -7098), INT16_C(  9867), INT16_C( -9190)),
      simde_mm_set_epi16(INT16_C(  6003), INT16_C( -5880), INT16_C( 31967), INT16_C(-28984),
                         INT16_C( -9503), INT16_C( 30320), INT16_C(  9867), INT16_C( -9190)) },
    { simde_mm_set_epi16(INT16_C( 12033), INT16_C( 14639), INT16_C( 28420), INT16_C( 14334),
                         INT16_C( -3029), INT16_C(-20328), INT16_C(  8988), INT16_C( 23547)),
      simde_mm_set_epi16(INT16_C(  9966), INT16_C(-21867), INT16_C(   738), INT16_C(-29688),
                         INT16_C(  9349), INT16_C(  2360), INT16_C(-12771), INT16_C(-15402)),
      simde_mm_set_epi16(INT16_C( 12033), INT16_C( 14639), INT16_C( 28420), INT16_C( 14334),
                         INT16_C( -3029), INT16_C(-20328), INT16_C(-12771), INT16_C(-15402)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_blend_epi16(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_blend_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  307.09), SIMDE_FLOAT64_C( -991.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -252.92), SIMDE_FLOAT64_C(  -56.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  307.09), SIMDE_FLOAT64_C(  -56.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  263.25), SIMDE_FLOAT64_C(  576.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -398.47), SIMDE_FLOAT64_C( -845.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  263.25), SIMDE_FLOAT64_C( -845.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -156.21), SIMDE_FLOAT64_C(  805.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -712.32), SIMDE_FLOAT64_C( -557.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -156.21), SIMDE_FLOAT64_C( -557.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  191.78), SIMDE_FLOAT64_C( -309.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -997.82), SIMDE_FLOAT64_C( -493.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  191.78), SIMDE_FLOAT64_C( -493.58)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -933.58), SIMDE_FLOAT64_C( -486.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  880.67), SIMDE_FLOAT64_C(  791.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -933.58), SIMDE_FLOAT64_C(  791.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   45.45), SIMDE_FLOAT64_C( -436.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  211.82), SIMDE_FLOAT64_C(  653.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   45.45), SIMDE_FLOAT64_C(  653.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  915.51), SIMDE_FLOAT64_C( -445.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -69.14), SIMDE_FLOAT64_C( -345.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  915.51), SIMDE_FLOAT64_C( -345.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -603.21), SIMDE_FLOAT64_C( -182.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -463.45), SIMDE_FLOAT64_C(  929.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -603.21), SIMDE_FLOAT64_C(  929.21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_blend_pd(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_blend_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  263.25), SIMDE_FLOAT32_C(  576.67), SIMDE_FLOAT32_C(  307.09), SIMDE_FLOAT32_C( -991.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -398.47), SIMDE_FLOAT32_C( -845.00), SIMDE_FLOAT32_C( -252.92), SIMDE_FLOAT32_C(  -56.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  263.25), SIMDE_FLOAT32_C(  576.67), SIMDE_FLOAT32_C( -252.92), SIMDE_FLOAT32_C( -991.93)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  191.78), SIMDE_FLOAT32_C( -309.61), SIMDE_FLOAT32_C( -156.21), SIMDE_FLOAT32_C(  805.98)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -997.82), SIMDE_FLOAT32_C( -493.58), SIMDE_FLOAT32_C( -712.32), SIMDE_FLOAT32_C( -557.85)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  191.78), SIMDE_FLOAT32_C( -309.61), SIMDE_FLOAT32_C( -712.32), SIMDE_FLOAT32_C(  805.98)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   45.45), SIMDE_FLOAT32_C( -436.38), SIMDE_FLOAT32_C( -933.58), SIMDE_FLOAT32_C( -486.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  211.82), SIMDE_FLOAT32_C(  653.98), SIMDE_FLOAT32_C(  880.67), SIMDE_FLOAT32_C(  791.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.45), SIMDE_FLOAT32_C( -436.38), SIMDE_FLOAT32_C(  880.67), SIMDE_FLOAT32_C( -486.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -603.21), SIMDE_FLOAT32_C( -182.69), SIMDE_FLOAT32_C(  915.51), SIMDE_FLOAT32_C( -445.43)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -463.45), SIMDE_FLOAT32_C(  929.21), SIMDE_FLOAT32_C(  -69.14), SIMDE_FLOAT32_C( -345.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -603.21), SIMDE_FLOAT32_C( -182.69), SIMDE_FLOAT32_C(  -69.14), SIMDE_FLOAT32_C( -445.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  898.89), SIMDE_FLOAT32_C(  -75.69), SIMDE_FLOAT32_C(  396.94), SIMDE_FLOAT32_C( -959.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -419.62), SIMDE_FLOAT32_C( -299.33), SIMDE_FLOAT32_C( -147.28), SIMDE_FLOAT32_C( -458.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  898.89), SIMDE_FLOAT32_C(  -75.69), SIMDE_FLOAT32_C( -147.28), SIMDE_FLOAT32_C( -959.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  480.97), SIMDE_FLOAT32_C(  316.97), SIMDE_FLOAT32_C( -700.74), SIMDE_FLOAT32_C(  -81.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -930.08), SIMDE_FLOAT32_C(   58.79), SIMDE_FLOAT32_C( -729.84), SIMDE_FLOAT32_C(  572.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  480.97), SIMDE_FLOAT32_C(  316.97), SIMDE_FLOAT32_C( -729.84), SIMDE_FLOAT32_C(  -81.35)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.53), SIMDE_FLOAT32_C(  742.30), SIMDE_FLOAT32_C(  440.93), SIMDE_FLOAT32_C( -885.24)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  883.38), SIMDE_FLOAT32_C( -314.94), SIMDE_FLOAT32_C( -805.26), SIMDE_FLOAT32_C(  843.17)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.53), SIMDE_FLOAT32_C(  742.30), SIMDE_FLOAT32_C( -805.26), SIMDE_FLOAT32_C( -885.24)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  812.23), SIMDE_FLOAT32_C( -335.37), SIMDE_FLOAT32_C(  369.92), SIMDE_FLOAT32_C( -137.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  119.89), SIMDE_FLOAT32_C(  901.62), SIMDE_FLOAT32_C( -234.15), SIMDE_FLOAT32_C(  494.86)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  812.23), SIMDE_FLOAT32_C( -335.37), SIMDE_FLOAT32_C( -234.15), SIMDE_FLOAT32_C( -137.19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_blend_ps(test_vec[i].a, test_vec[i].b, 2);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_blendv_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i mask;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  290.02), SIMDE_FLOAT64_C( -775.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  567.65), SIMDE_FLOAT64_C(  339.87)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  290.02), SIMDE_FLOAT64_C( -775.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.24), SIMDE_FLOAT64_C( -371.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  899.02), SIMDE_FLOAT64_C( -664.73)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.24), SIMDE_FLOAT64_C( -371.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  403.27), SIMDE_FLOAT64_C( -740.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  975.40), SIMDE_FLOAT64_C( -480.24)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  403.27), SIMDE_FLOAT64_C( -740.87)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -417.67), SIMDE_FLOAT64_C(  711.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -897.21), SIMDE_FLOAT64_C( -402.59)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -417.67), SIMDE_FLOAT64_C(  711.92)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  578.89), SIMDE_FLOAT64_C( -895.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -800.50), SIMDE_FLOAT64_C( -144.28)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  578.89), SIMDE_FLOAT64_C( -895.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  546.78), SIMDE_FLOAT64_C(  883.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.01), SIMDE_FLOAT64_C(  773.21)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  546.78), SIMDE_FLOAT64_C(  883.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   26.01), SIMDE_FLOAT64_C(  -59.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -530.26), SIMDE_FLOAT64_C(  580.89)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   26.01), SIMDE_FLOAT64_C(  -59.50)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -344.22), SIMDE_FLOAT64_C(  626.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  752.48), SIMDE_FLOAT64_C(  453.28)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -344.22), SIMDE_FLOAT64_C(  626.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_blendv_pd(test_vec[i].a, test_vec[i].b, simde_mm_castsi128_pd(test_vec[i].mask));
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_blendv_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128i mask;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -155.18), SIMDE_FLOAT32_C( -698.08), SIMDE_FLOAT32_C( -535.18), SIMDE_FLOAT32_C( -144.32)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -362.54), SIMDE_FLOAT32_C( -779.39), SIMDE_FLOAT32_C(  825.01), SIMDE_FLOAT32_C( -777.93)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -155.18), SIMDE_FLOAT32_C( -698.08), SIMDE_FLOAT32_C( -535.18), SIMDE_FLOAT32_C( -144.32)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -284.42), SIMDE_FLOAT32_C(  692.24), SIMDE_FLOAT32_C(  101.85), SIMDE_FLOAT32_C( -819.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  327.10), SIMDE_FLOAT32_C(  184.40), SIMDE_FLOAT32_C(  440.54), SIMDE_FLOAT32_C(  732.07)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         1)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -284.42), SIMDE_FLOAT32_C(  692.24), SIMDE_FLOAT32_C(  101.85), SIMDE_FLOAT32_C( -819.28)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  264.15), SIMDE_FLOAT32_C( -480.80), SIMDE_FLOAT32_C( -304.32), SIMDE_FLOAT32_C(  862.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  230.55), SIMDE_FLOAT32_C( -649.28), SIMDE_FLOAT32_C(  827.43), SIMDE_FLOAT32_C( -462.60)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  264.15), SIMDE_FLOAT32_C( -480.80), SIMDE_FLOAT32_C( -304.32), SIMDE_FLOAT32_C(  862.50)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  235.66), SIMDE_FLOAT32_C(  478.16), SIMDE_FLOAT32_C(  480.58), SIMDE_FLOAT32_C(  -53.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  982.67), SIMDE_FLOAT32_C( -772.62), SIMDE_FLOAT32_C( -150.10), SIMDE_FLOAT32_C( -737.86)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         0), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  235.66), SIMDE_FLOAT32_C(  478.16), SIMDE_FLOAT32_C(  480.58), SIMDE_FLOAT32_C(  -53.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  121.52), SIMDE_FLOAT32_C(  798.57), SIMDE_FLOAT32_C(  563.90), SIMDE_FLOAT32_C(  845.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  593.41), SIMDE_FLOAT32_C(  201.43), SIMDE_FLOAT32_C( -263.22), SIMDE_FLOAT32_C(   41.51)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  121.52), SIMDE_FLOAT32_C(  798.57), SIMDE_FLOAT32_C(  563.90), SIMDE_FLOAT32_C(  845.42)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -938.86), SIMDE_FLOAT32_C( -190.10), SIMDE_FLOAT32_C( -729.05), SIMDE_FLOAT32_C(  956.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  574.98), SIMDE_FLOAT32_C(  -82.92), SIMDE_FLOAT32_C(  247.07), SIMDE_FLOAT32_C( -802.43)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -938.86), SIMDE_FLOAT32_C( -190.10), SIMDE_FLOAT32_C( -729.05), SIMDE_FLOAT32_C(  956.23)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -592.31), SIMDE_FLOAT32_C( -123.91), SIMDE_FLOAT32_C(  105.67), SIMDE_FLOAT32_C(  596.25)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -99.40), SIMDE_FLOAT32_C(   86.32), SIMDE_FLOAT32_C( -827.82), SIMDE_FLOAT32_C(  443.02)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -592.31), SIMDE_FLOAT32_C( -123.91), SIMDE_FLOAT32_C(  105.67), SIMDE_FLOAT32_C(  596.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   59.00), SIMDE_FLOAT32_C(  -93.37), SIMDE_FLOAT32_C( -934.05), SIMDE_FLOAT32_C(  930.21)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -592.32), SIMDE_FLOAT32_C(  420.31), SIMDE_FLOAT32_C( -235.36), SIMDE_FLOAT32_C( -335.98)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         1)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   59.00), SIMDE_FLOAT32_C(  -93.37), SIMDE_FLOAT32_C( -934.05), SIMDE_FLOAT32_C(  930.21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_blendv_ps(test_vec[i].a, test_vec[i].b, simde_mm_castsi128_ps(test_vec[i].mask));
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_ceil_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  241.39), SIMDE_FLOAT64_C(  553.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  242.00), SIMDE_FLOAT64_C(  554.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  307.83), SIMDE_FLOAT64_C(  377.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  308.00), SIMDE_FLOAT64_C(  378.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  558.16), SIMDE_FLOAT64_C( -404.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  559.00), SIMDE_FLOAT64_C( -404.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  219.15), SIMDE_FLOAT64_C(  818.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  220.00), SIMDE_FLOAT64_C(  819.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   25.83), SIMDE_FLOAT64_C( -230.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   26.00), SIMDE_FLOAT64_C( -230.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  173.52), SIMDE_FLOAT64_C(   64.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  174.00), SIMDE_FLOAT64_C(   65.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -453.11), SIMDE_FLOAT64_C( -845.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -453.00), SIMDE_FLOAT64_C( -845.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.98), SIMDE_FLOAT64_C( -179.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.00), SIMDE_FLOAT64_C( -179.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_ceil_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_ceil_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -624.94), SIMDE_FLOAT32_C( -243.25), SIMDE_FLOAT32_C(  -61.63), SIMDE_FLOAT32_C( -948.73)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -624.00), SIMDE_FLOAT32_C( -243.00), SIMDE_FLOAT32_C(  -61.00), SIMDE_FLOAT32_C( -948.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -906.63), SIMDE_FLOAT32_C( -236.42), SIMDE_FLOAT32_C(  571.51), SIMDE_FLOAT32_C(  624.62)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -906.00), SIMDE_FLOAT32_C( -236.00), SIMDE_FLOAT32_C(  572.00), SIMDE_FLOAT32_C(  625.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  503.85), SIMDE_FLOAT32_C( -317.51), SIMDE_FLOAT32_C( -529.30), SIMDE_FLOAT32_C( -871.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  504.00), SIMDE_FLOAT32_C( -317.00), SIMDE_FLOAT32_C( -529.00), SIMDE_FLOAT32_C( -871.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  571.49), SIMDE_FLOAT32_C( -129.77), SIMDE_FLOAT32_C( -739.71), SIMDE_FLOAT32_C(  413.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  572.00), SIMDE_FLOAT32_C( -129.00), SIMDE_FLOAT32_C( -739.00), SIMDE_FLOAT32_C(  414.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  438.35), SIMDE_FLOAT32_C(  517.03), SIMDE_FLOAT32_C(  278.46), SIMDE_FLOAT32_C( -656.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  439.00), SIMDE_FLOAT32_C(  518.00), SIMDE_FLOAT32_C(  279.00), SIMDE_FLOAT32_C( -656.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -159.40), SIMDE_FLOAT32_C( -802.82), SIMDE_FLOAT32_C(  663.71), SIMDE_FLOAT32_C(  186.86)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -159.00), SIMDE_FLOAT32_C( -802.00), SIMDE_FLOAT32_C(  664.00), SIMDE_FLOAT32_C(  187.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -163.74), SIMDE_FLOAT32_C(  485.54), SIMDE_FLOAT32_C(  138.17), SIMDE_FLOAT32_C(  794.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -163.00), SIMDE_FLOAT32_C(  486.00), SIMDE_FLOAT32_C(  139.00), SIMDE_FLOAT32_C(  795.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -469.36), SIMDE_FLOAT32_C( -418.24), SIMDE_FLOAT32_C( -419.25), SIMDE_FLOAT32_C(  390.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -469.00), SIMDE_FLOAT32_C( -418.00), SIMDE_FLOAT32_C( -419.00), SIMDE_FLOAT32_C(  391.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_ceil_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_ceil_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -610.18), SIMDE_FLOAT64_C(  172.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  234.40), SIMDE_FLOAT64_C( -339.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -610.18), SIMDE_FLOAT64_C( -339.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -467.52), SIMDE_FLOAT64_C(  904.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -527.39), SIMDE_FLOAT64_C( -115.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -467.52), SIMDE_FLOAT64_C( -115.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  191.24), SIMDE_FLOAT64_C(  823.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  835.27), SIMDE_FLOAT64_C(  744.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  191.24), SIMDE_FLOAT64_C(  745.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.25), SIMDE_FLOAT64_C( -695.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  800.62), SIMDE_FLOAT64_C(  853.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.25), SIMDE_FLOAT64_C(  854.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  668.83), SIMDE_FLOAT64_C( -182.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -875.46), SIMDE_FLOAT64_C(  752.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  668.83), SIMDE_FLOAT64_C(  753.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  242.57), SIMDE_FLOAT64_C( -906.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -816.22), SIMDE_FLOAT64_C(  339.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  242.57), SIMDE_FLOAT64_C(  340.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -745.15), SIMDE_FLOAT64_C( -744.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -802.81), SIMDE_FLOAT64_C(  890.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -745.15), SIMDE_FLOAT64_C(  891.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  238.48), SIMDE_FLOAT64_C( -167.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -484.51), SIMDE_FLOAT64_C(  175.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  238.48), SIMDE_FLOAT64_C(  176.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_ceil_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_ceil_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -124.45), SIMDE_FLOAT32_C(  911.12), SIMDE_FLOAT32_C(  900.52), SIMDE_FLOAT32_C( -468.92)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -31.56), SIMDE_FLOAT32_C(  -29.76), SIMDE_FLOAT32_C( -939.35), SIMDE_FLOAT32_C(  459.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -124.45), SIMDE_FLOAT32_C(  911.12), SIMDE_FLOAT32_C(  900.52), SIMDE_FLOAT32_C(  460.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  514.22), SIMDE_FLOAT32_C( -972.44), SIMDE_FLOAT32_C( -908.76), SIMDE_FLOAT32_C( -817.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -711.78), SIMDE_FLOAT32_C(  489.62), SIMDE_FLOAT32_C( -109.52), SIMDE_FLOAT32_C(   -2.01)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  514.22), SIMDE_FLOAT32_C( -972.44), SIMDE_FLOAT32_C( -908.76), SIMDE_FLOAT32_C(   -2.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -269.88), SIMDE_FLOAT32_C( -875.85), SIMDE_FLOAT32_C( -139.27), SIMDE_FLOAT32_C( -841.56)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  501.05), SIMDE_FLOAT32_C(  280.43), SIMDE_FLOAT32_C( -173.91), SIMDE_FLOAT32_C(  644.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -269.88), SIMDE_FLOAT32_C( -875.85), SIMDE_FLOAT32_C( -139.27), SIMDE_FLOAT32_C(  645.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -643.26), SIMDE_FLOAT32_C(  616.48), SIMDE_FLOAT32_C(  835.28), SIMDE_FLOAT32_C(  527.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  636.48), SIMDE_FLOAT32_C(  -46.56), SIMDE_FLOAT32_C( -891.84), SIMDE_FLOAT32_C(  948.43)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -643.26), SIMDE_FLOAT32_C(  616.48), SIMDE_FLOAT32_C(  835.28), SIMDE_FLOAT32_C(  949.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    3.13), SIMDE_FLOAT32_C( -654.36), SIMDE_FLOAT32_C( -994.98), SIMDE_FLOAT32_C( -148.95)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  806.15), SIMDE_FLOAT32_C(  529.29), SIMDE_FLOAT32_C( -804.42), SIMDE_FLOAT32_C(  408.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    3.13), SIMDE_FLOAT32_C( -654.36), SIMDE_FLOAT32_C( -994.98), SIMDE_FLOAT32_C(  409.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -138.18), SIMDE_FLOAT32_C( -446.48), SIMDE_FLOAT32_C( -413.95), SIMDE_FLOAT32_C( -252.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  957.68), SIMDE_FLOAT32_C(  373.35), SIMDE_FLOAT32_C(  271.98), SIMDE_FLOAT32_C( -653.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -138.18), SIMDE_FLOAT32_C( -446.48), SIMDE_FLOAT32_C( -413.95), SIMDE_FLOAT32_C( -653.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  124.40), SIMDE_FLOAT32_C( -866.66), SIMDE_FLOAT32_C(  288.57), SIMDE_FLOAT32_C( -708.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  685.14), SIMDE_FLOAT32_C(  776.00), SIMDE_FLOAT32_C(  453.56), SIMDE_FLOAT32_C( -112.81)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  124.40), SIMDE_FLOAT32_C( -866.66), SIMDE_FLOAT32_C(  288.57), SIMDE_FLOAT32_C( -112.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -232.75), SIMDE_FLOAT32_C( -137.55), SIMDE_FLOAT32_C(   50.26), SIMDE_FLOAT32_C( -189.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -288.67), SIMDE_FLOAT32_C( -112.95), SIMDE_FLOAT32_C(  792.47), SIMDE_FLOAT32_C( -200.27)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -232.75), SIMDE_FLOAT32_C( -137.55), SIMDE_FLOAT32_C(   50.26), SIMDE_FLOAT32_C( -200.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_ceil_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu64x(UINT64_C(13269709557652540150), UINT64_C( 5229646237911669536)),
      simde_x_mm_set_epu64x(UINT64_C(13269709557652540150), UINT64_C( 5229646237911669536)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C(14039735832537203737), UINT64_C(18065414586371585158)),
      simde_x_mm_set_epu64x(UINT64_C( 7896134184979754273), UINT64_C(18065414586371585158)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C( 8088434365645432882), UINT64_C( 2110149590601129498)),
      simde_x_mm_set_epu64x(UINT64_C(12894308138858138936), UINT64_C( 7645444803376971084)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(                   0)) },
    { simde_x_mm_set_epu64x(UINT64_C( 6900998750312547586), UINT64_C(11115665826166806875)),
      simde_x_mm_set_epu64x(UINT64_C(  253910074237567150), UINT64_C(11115665826166806875)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C(15513947591537518317), UINT64_C( 6346622963553980783)),
      simde_x_mm_set_epu64x(UINT64_C( 1894817647097843127), UINT64_C( 9019647896255166506)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(                   0)) },
    { simde_x_mm_set_epu64x(UINT64_C(  189073800069710221), UINT64_C( 5830713182261233236)),
      simde_x_mm_set_epu64x(UINT64_C(  189073800069710221), UINT64_C( 8422068610497871432)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(                   0)) },
    { simde_x_mm_set_epu64x(UINT64_C(17115829668729212386), UINT64_C(11158226665026575121)),
      simde_x_mm_set_epu64x(UINT64_C(17115829668729212386), UINT64_C(11158226665026575121)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C( 9543887299291080046), UINT64_C(14913997234931691871)),
      simde_x_mm_set_epu64x(UINT64_C( 9543887299291080046), UINT64_C(12485648986158046833)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(                   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepi16_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-15854,      0, -12807,   5951,  29318, -11078,  -2252,  10096),
      simde_mm_set_epi32( 29318, -11078,  -2252,  10096) },
    { simde_mm_set_epi16( 24388,  32521, -30980, -12289,  27092,  24521,  12106, -27709),
      simde_mm_set_epi32( 27092,  24521,  12106, -27709) },
    { simde_mm_set_epi16(-11871,  15750,  -7986,   4594,  22346,   1400, -21386,   7662),
      simde_mm_set_epi32( 22346,   1400, -21386,   7662) },
    { simde_mm_set_epi16(-15687, -15477, -26077, -28781, -29737, -30311,  16950,  14614),
      simde_mm_set_epi32(-29737, -30311,  16950,  14614) },
    { simde_mm_set_epi16(-30646,  13049, -24166,    637,   7297,   -627,   6143, -26200),
      simde_mm_set_epi32(  7297,   -627,   6143, -26200) },
    { simde_mm_set_epi16( 30171,   1922,   -122, -17991,  30806,  12552, -28515,  -9185),
      simde_mm_set_epi32( 30806,  12552, -28515,  -9185) },
    { simde_mm_set_epi16( 29385,  21267, -10152,  25553,  20674,   6661, -29222, -19848),
      simde_mm_set_epi32( 20674,   6661, -29222, -19848) },
    { simde_mm_set_epi16( 24527,  18305,  30094,  -5437, -26652,  20361,  10408,  -4948),
      simde_mm_set_epi32(-26652,  20361,  10408,  -4948) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi16_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepi16_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-25288), INT16_C(   737), INT16_C(-31366), INT16_C(-21360),
                         INT16_C(  1927), INT16_C( 32195), INT16_C( -4472), INT16_C( -2085)),
      simde_mm_set_epi64x(INT64_C(               -4472), INT64_C(               -2085)) },
    { simde_mm_set_epi16(INT16_C(-30817), INT16_C(  5734), INT16_C( -6209), INT16_C(-18846),
                         INT16_C( 14970), INT16_C( 30345), INT16_C( -8853), INT16_C(-31121)),
      simde_mm_set_epi64x(INT64_C(               -8853), INT64_C(              -31121)) },
    { simde_mm_set_epi16(INT16_C(  -970), INT16_C(-11861), INT16_C(-11667), INT16_C( 14936),
                         INT16_C( 21732), INT16_C(-17006), INT16_C( -2668), INT16_C( 30170)),
      simde_mm_set_epi64x(INT64_C(               -2668), INT64_C(               30170)) },
    { simde_mm_set_epi16(INT16_C(  2721), INT16_C(-13375), INT16_C( -1976), INT16_C( 30833),
                         INT16_C(-18247), INT16_C( 16242), INT16_C(  4569), INT16_C( 10132)),
      simde_mm_set_epi64x(INT64_C(                4569), INT64_C(               10132)) },
    { simde_mm_set_epi16(INT16_C(-22879), INT16_C(-24842), INT16_C(-29886), INT16_C(-13312),
                         INT16_C( 24862), INT16_C(-30679), INT16_C(  6258), INT16_C(-19461)),
      simde_mm_set_epi64x(INT64_C(                6258), INT64_C(              -19461)) },
    { simde_mm_set_epi16(INT16_C( 15048), INT16_C(  5334), INT16_C( 21517), INT16_C( 10106),
                         INT16_C(-25890), INT16_C( -8759), INT16_C( 21361), INT16_C( 17584)),
      simde_mm_set_epi64x(INT64_C(               21361), INT64_C(               17584)) },
    { simde_mm_set_epi16(INT16_C( 18353), INT16_C(  9848), INT16_C( 20583), INT16_C(-28706),
                         INT16_C( 28353), INT16_C(   979), INT16_C(-15312), INT16_C( -4296)),
      simde_mm_set_epi64x(INT64_C(              -15312), INT64_C(               -4296)) },
    { simde_mm_set_epi16(INT16_C( 21066), INT16_C( 26185), INT16_C( 29520), INT16_C( -9848),
                         INT16_C(-20587), INT16_C(  -254), INT16_C(-19969), INT16_C( -2307)),
      simde_mm_set_epi64x(INT64_C(              -19969), INT64_C(               -2307)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi16_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepi32_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1750586859), INT32_C( 1743108010), INT32_C(  -56370522), INT32_C(  214732685)),
      simde_mm_set_epi64x(INT64_C(           -56370522), INT64_C(           214732685)) },
    { simde_mm_set_epi32(INT32_C( 1019578476), INT32_C( 2006962808), INT32_C( 1356966666), INT32_C(  443191452)),
      simde_mm_set_epi64x(INT64_C(          1356966666), INT64_C(           443191452)) },
    { simde_mm_set_epi32(INT32_C(  811952499), INT32_C( 1388789927), INT32_C( 1562076587), INT32_C( 1374574189)),
      simde_mm_set_epi64x(INT64_C(          1562076587), INT64_C(          1374574189)) },
    { simde_mm_set_epi32(INT32_C(-1130424581), INT32_C( -754503048), INT32_C( -175987570), INT32_C(  252857640)),
      simde_mm_set_epi64x(INT64_C(          -175987570), INT64_C(           252857640)) },
    { simde_mm_set_epi32(INT32_C( -662885345), INT32_C( -469769762), INT32_C( 1876427062), INT32_C(-1227144336)),
      simde_mm_set_epi64x(INT64_C(          1876427062), INT64_C(         -1227144336)) },
    { simde_mm_set_epi32(INT32_C(-1459145913), INT32_C( -624950308), INT32_C(-1740403350), INT32_C(-2023012954)),
      simde_mm_set_epi64x(INT64_C(         -1740403350), INT64_C(         -2023012954)) },
    { simde_mm_set_epi32(INT32_C(  807996884), INT32_C( -721517626), INT32_C(-1345085365), INT32_C(    3500292)),
      simde_mm_set_epi64x(INT64_C(         -1345085365), INT64_C(             3500292)) },
    { simde_mm_set_epi32(INT32_C( 1631614297), INT32_C(-2082769218), INT32_C(  285385405), INT32_C(-1874296921)),
      simde_mm_set_epi64x(INT64_C(           285385405), INT64_C(         -1874296921)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi32_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepi8_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -34), INT8_C(  20), INT8_C(  53), INT8_C(  81),
                        INT8_C(  37), INT8_C( -97), INT8_C( -59), INT8_C( 127),
                        INT8_C( -43), INT8_C( -82), INT8_C(  84), INT8_C(-127),
                        INT8_C(  11), INT8_C( 120), INT8_C( -98), INT8_C( -80)),
      simde_mm_set_epi16(INT16_C(   -43), INT16_C(   -82), INT16_C(    84), INT16_C(  -127),
                         INT16_C(    11), INT16_C(   120), INT16_C(   -98), INT16_C(   -80)) },
    { simde_mm_set_epi8(INT8_C(  66), INT8_C(  57), INT8_C(  40), INT8_C(-113),
                        INT8_C(  71), INT8_C(  -5), INT8_C(  70), INT8_C(  22),
                        INT8_C( -70), INT8_C(  14), INT8_C( -76), INT8_C(-101),
                        INT8_C(  13), INT8_C(  64), INT8_C( -86), INT8_C(  34)),
      simde_mm_set_epi16(INT16_C(   -70), INT16_C(    14), INT16_C(   -76), INT16_C(  -101),
                         INT16_C(    13), INT16_C(    64), INT16_C(   -86), INT16_C(    34)) },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C( 115), INT8_C( 108), INT8_C( -88),
                        INT8_C( 113), INT8_C(  91), INT8_C( -95), INT8_C( -69),
                        INT8_C(  32), INT8_C(  98), INT8_C( -16), INT8_C( -55),
                        INT8_C(  11), INT8_C( -23), INT8_C(  72), INT8_C( 121)),
      simde_mm_set_epi16(INT16_C(    32), INT16_C(    98), INT16_C(   -16), INT16_C(   -55),
                         INT16_C(    11), INT16_C(   -23), INT16_C(    72), INT16_C(   121)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(  68), INT8_C( -76), INT8_C(  35),
                        INT8_C(-119), INT8_C( -67), INT8_C(  52), INT8_C(  58),
                        INT8_C(   7), INT8_C(  70), INT8_C( -26), INT8_C(  55),
                        INT8_C( 126), INT8_C(  69), INT8_C( 105), INT8_C(  40)),
      simde_mm_set_epi16(INT16_C(     7), INT16_C(    70), INT16_C(   -26), INT16_C(    55),
                         INT16_C(   126), INT16_C(    69), INT16_C(   105), INT16_C(    40)) },
    { simde_mm_set_epi8(INT8_C( 110), INT8_C(  -4), INT8_C(  41), INT8_C( -98),
                        INT8_C( -91), INT8_C( 117), INT8_C( -33), INT8_C(-110),
                        INT8_C( 126), INT8_C( -63), INT8_C( -65), INT8_C( -86),
                        INT8_C(-108), INT8_C( -64), INT8_C(  -4), INT8_C(  25)),
      simde_mm_set_epi16(INT16_C(   126), INT16_C(   -63), INT16_C(   -65), INT16_C(   -86),
                         INT16_C(  -108), INT16_C(   -64), INT16_C(    -4), INT16_C(    25)) },
    { simde_mm_set_epi8(INT8_C( 105), INT8_C( -31), INT8_C( -57), INT8_C( -74),
                        INT8_C( 119), INT8_C(  56), INT8_C( -36), INT8_C(-128),
                        INT8_C( 102), INT8_C(  57), INT8_C( -27), INT8_C(  19),
                        INT8_C( -50), INT8_C( -15), INT8_C(  36), INT8_C(-124)),
      simde_mm_set_epi16(INT16_C(   102), INT16_C(    57), INT16_C(   -27), INT16_C(    19),
                         INT16_C(   -50), INT16_C(   -15), INT16_C(    36), INT16_C(  -124)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -84), INT8_C( -61), INT8_C(  59),
                        INT8_C(  18), INT8_C(-118), INT8_C(   6), INT8_C(  56),
                        INT8_C( -11), INT8_C(  78), INT8_C( -64), INT8_C( -28),
                        INT8_C( -85), INT8_C( -77), INT8_C( -25), INT8_C(-100)),
      simde_mm_set_epi16(INT16_C(   -11), INT16_C(    78), INT16_C(   -64), INT16_C(   -28),
                         INT16_C(   -85), INT16_C(   -77), INT16_C(   -25), INT16_C(  -100)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -24), INT8_C(  94), INT8_C(  58),
                        INT8_C(   1), INT8_C( -14), INT8_C( -90), INT8_C(-123),
                        INT8_C(-101), INT8_C(  71), INT8_C( -51), INT8_C(  87),
                        INT8_C( -34), INT8_C(  77), INT8_C( 124), INT8_C( -63)),
      simde_mm_set_epi16(INT16_C(  -101), INT16_C(    71), INT16_C(   -51), INT16_C(    87),
                         INT16_C(   -34), INT16_C(    77), INT16_C(   124), INT16_C(   -63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi8_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepi8_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -34), INT8_C(  20), INT8_C(  53), INT8_C(  81),
                        INT8_C(  37), INT8_C( -97), INT8_C( -59), INT8_C( 127),
                        INT8_C( -43), INT8_C( -82), INT8_C(  84), INT8_C(-127),
                        INT8_C(  11), INT8_C( 120), INT8_C( -98), INT8_C( -80)),
      simde_mm_set_epi32(INT32_C(         11), INT32_C(        120), INT32_C(        -98), INT32_C(        -80)) },
    { simde_mm_set_epi8(INT8_C(  66), INT8_C(  57), INT8_C(  40), INT8_C(-113),
                        INT8_C(  71), INT8_C(  -5), INT8_C(  70), INT8_C(  22),
                        INT8_C( -70), INT8_C(  14), INT8_C( -76), INT8_C(-101),
                        INT8_C(  13), INT8_C(  64), INT8_C( -86), INT8_C(  34)),
      simde_mm_set_epi32(INT32_C(         13), INT32_C(         64), INT32_C(        -86), INT32_C(         34)) },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C( 115), INT8_C( 108), INT8_C( -88),
                        INT8_C( 113), INT8_C(  91), INT8_C( -95), INT8_C( -69),
                        INT8_C(  32), INT8_C(  98), INT8_C( -16), INT8_C( -55),
                        INT8_C(  11), INT8_C( -23), INT8_C(  72), INT8_C( 121)),
      simde_mm_set_epi32(INT32_C(         11), INT32_C(        -23), INT32_C(         72), INT32_C(        121)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(  68), INT8_C( -76), INT8_C(  35),
                        INT8_C(-119), INT8_C( -67), INT8_C(  52), INT8_C(  58),
                        INT8_C(   7), INT8_C(  70), INT8_C( -26), INT8_C(  55),
                        INT8_C( 126), INT8_C(  69), INT8_C( 105), INT8_C(  40)),
      simde_mm_set_epi32(INT32_C(        126), INT32_C(         69), INT32_C(        105), INT32_C(         40)) },
    { simde_mm_set_epi8(INT8_C( 110), INT8_C(  -4), INT8_C(  41), INT8_C( -98),
                        INT8_C( -91), INT8_C( 117), INT8_C( -33), INT8_C(-110),
                        INT8_C( 126), INT8_C( -63), INT8_C( -65), INT8_C( -86),
                        INT8_C(-108), INT8_C( -64), INT8_C(  -4), INT8_C(  25)),
      simde_mm_set_epi32(INT32_C(       -108), INT32_C(        -64), INT32_C(         -4), INT32_C(         25)) },
    { simde_mm_set_epi8(INT8_C( 105), INT8_C( -31), INT8_C( -57), INT8_C( -74),
                        INT8_C( 119), INT8_C(  56), INT8_C( -36), INT8_C(-128),
                        INT8_C( 102), INT8_C(  57), INT8_C( -27), INT8_C(  19),
                        INT8_C( -50), INT8_C( -15), INT8_C(  36), INT8_C(-124)),
      simde_mm_set_epi32(INT32_C(        -50), INT32_C(        -15), INT32_C(         36), INT32_C(       -124)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -84), INT8_C( -61), INT8_C(  59),
                        INT8_C(  18), INT8_C(-118), INT8_C(   6), INT8_C(  56),
                        INT8_C( -11), INT8_C(  78), INT8_C( -64), INT8_C( -28),
                        INT8_C( -85), INT8_C( -77), INT8_C( -25), INT8_C(-100)),
      simde_mm_set_epi32(INT32_C(        -85), INT32_C(        -77), INT32_C(        -25), INT32_C(       -100)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -24), INT8_C(  94), INT8_C(  58),
                        INT8_C(   1), INT8_C( -14), INT8_C( -90), INT8_C(-123),
                        INT8_C(-101), INT8_C(  71), INT8_C( -51), INT8_C(  87),
                        INT8_C( -34), INT8_C(  77), INT8_C( 124), INT8_C( -63)),
      simde_mm_set_epi32(INT32_C(        -34), INT32_C(         77), INT32_C(        124), INT32_C(        -63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi8_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepi8_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -34), INT8_C(  20), INT8_C(  53), INT8_C(  81),
                        INT8_C(  37), INT8_C( -97), INT8_C( -59), INT8_C( 127),
                        INT8_C( -43), INT8_C( -82), INT8_C(  84), INT8_C(-127),
                        INT8_C(  11), INT8_C( 120), INT8_C( -98), INT8_C( -80)),
      simde_mm_set_epi64x(INT64_C(                 -98), INT64_C(                 -80)) },
    { simde_mm_set_epi8(INT8_C(  66), INT8_C(  57), INT8_C(  40), INT8_C(-113),
                        INT8_C(  71), INT8_C(  -5), INT8_C(  70), INT8_C(  22),
                        INT8_C( -70), INT8_C(  14), INT8_C( -76), INT8_C(-101),
                        INT8_C(  13), INT8_C(  64), INT8_C( -86), INT8_C(  34)),
      simde_mm_set_epi64x(INT64_C(                 -86), INT64_C(                  34)) },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C( 115), INT8_C( 108), INT8_C( -88),
                        INT8_C( 113), INT8_C(  91), INT8_C( -95), INT8_C( -69),
                        INT8_C(  32), INT8_C(  98), INT8_C( -16), INT8_C( -55),
                        INT8_C(  11), INT8_C( -23), INT8_C(  72), INT8_C( 121)),
      simde_mm_set_epi64x(INT64_C(                  72), INT64_C(                 121)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(  68), INT8_C( -76), INT8_C(  35),
                        INT8_C(-119), INT8_C( -67), INT8_C(  52), INT8_C(  58),
                        INT8_C(   7), INT8_C(  70), INT8_C( -26), INT8_C(  55),
                        INT8_C( 126), INT8_C(  69), INT8_C( 105), INT8_C(  40)),
      simde_mm_set_epi64x(INT64_C(                 105), INT64_C(                  40)) },
    { simde_mm_set_epi8(INT8_C( 110), INT8_C(  -4), INT8_C(  41), INT8_C( -98),
                        INT8_C( -91), INT8_C( 117), INT8_C( -33), INT8_C(-110),
                        INT8_C( 126), INT8_C( -63), INT8_C( -65), INT8_C( -86),
                        INT8_C(-108), INT8_C( -64), INT8_C(  -4), INT8_C(  25)),
      simde_mm_set_epi64x(INT64_C(                  -4), INT64_C(                  25)) },
    { simde_mm_set_epi8(INT8_C( 105), INT8_C( -31), INT8_C( -57), INT8_C( -74),
                        INT8_C( 119), INT8_C(  56), INT8_C( -36), INT8_C(-128),
                        INT8_C( 102), INT8_C(  57), INT8_C( -27), INT8_C(  19),
                        INT8_C( -50), INT8_C( -15), INT8_C(  36), INT8_C(-124)),
      simde_mm_set_epi64x(INT64_C(                  36), INT64_C(                -124)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -84), INT8_C( -61), INT8_C(  59),
                        INT8_C(  18), INT8_C(-118), INT8_C(   6), INT8_C(  56),
                        INT8_C( -11), INT8_C(  78), INT8_C( -64), INT8_C( -28),
                        INT8_C( -85), INT8_C( -77), INT8_C( -25), INT8_C(-100)),
      simde_mm_set_epi64x(INT64_C(                 -25), INT64_C(                -100)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -24), INT8_C(  94), INT8_C(  58),
                        INT8_C(   1), INT8_C( -14), INT8_C( -90), INT8_C(-123),
                        INT8_C(-101), INT8_C(  71), INT8_C( -51), INT8_C(  87),
                        INT8_C( -34), INT8_C(  77), INT8_C( 124), INT8_C( -63)),
      simde_mm_set_epi64x(INT64_C(                 124), INT64_C(                 -63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi8_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepu8_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(133), UINT8_C( 55), UINT8_C(102), UINT8_C(130),
                          UINT8_C(197), UINT8_C( 52), UINT8_C(225), UINT8_C( 87),
                          UINT8_C(218), UINT8_C( 15), UINT8_C(214), UINT8_C(152),
                          UINT8_C(108), UINT8_C( 18), UINT8_C(104), UINT8_C(  3)),
      simde_mm_set_epi16(INT16_C(   218), INT16_C(    15), INT16_C(   214), INT16_C(   152),
                         INT16_C(   108), INT16_C(    18), INT16_C(   104), INT16_C(     3)) },
    { simde_x_mm_set_epu8(UINT8_C( 51), UINT8_C(122), UINT8_C(167), UINT8_C(232),
                          UINT8_C(  3), UINT8_C(167), UINT8_C( 89), UINT8_C(206),
                          UINT8_C( 96), UINT8_C(235), UINT8_C(128), UINT8_C(134),
                          UINT8_C(187), UINT8_C(190), UINT8_C(232), UINT8_C(112)),
      simde_mm_set_epi16(INT16_C(    96), INT16_C(   235), INT16_C(   128), INT16_C(   134),
                         INT16_C(   187), INT16_C(   190), INT16_C(   232), INT16_C(   112)) },
    { simde_x_mm_set_epu8(UINT8_C( 15), UINT8_C( 99), UINT8_C(228), UINT8_C( 12),
                          UINT8_C(155), UINT8_C(138), UINT8_C( 87), UINT8_C( 96),
                          UINT8_C( 98), UINT8_C( 66), UINT8_C( 96), UINT8_C( 53),
                          UINT8_C( 65), UINT8_C(187), UINT8_C(183), UINT8_C(114)),
      simde_mm_set_epi16(INT16_C(    98), INT16_C(    66), INT16_C(    96), INT16_C(    53),
                         INT16_C(    65), INT16_C(   187), INT16_C(   183), INT16_C(   114)) },
    { simde_x_mm_set_epu8(UINT8_C( 58), UINT8_C( 51), UINT8_C(210), UINT8_C( 42),
                          UINT8_C(132), UINT8_C(100), UINT8_C( 83), UINT8_C( 44),
                          UINT8_C(115), UINT8_C(204), UINT8_C(195), UINT8_C( 11),
                          UINT8_C( 48), UINT8_C( 39), UINT8_C( 37), UINT8_C(183)),
      simde_mm_set_epi16(INT16_C(   115), INT16_C(   204), INT16_C(   195), INT16_C(    11),
                         INT16_C(    48), INT16_C(    39), INT16_C(    37), INT16_C(   183)) },
    { simde_x_mm_set_epu8(UINT8_C( 56), UINT8_C(101), UINT8_C(162), UINT8_C(107),
                          UINT8_C( 59), UINT8_C( 91), UINT8_C( 63), UINT8_C(129),
                          UINT8_C(189), UINT8_C(  4), UINT8_C(  9), UINT8_C(155),
                          UINT8_C(150), UINT8_C( 39), UINT8_C(140), UINT8_C( 87)),
      simde_mm_set_epi16(INT16_C(   189), INT16_C(     4), INT16_C(     9), INT16_C(   155),
                         INT16_C(   150), INT16_C(    39), INT16_C(   140), INT16_C(    87)) },
    { simde_x_mm_set_epu8(UINT8_C(203), UINT8_C(158), UINT8_C(175), UINT8_C(  0),
                          UINT8_C( 27), UINT8_C( 64), UINT8_C(129), UINT8_C( 41),
                          UINT8_C(208), UINT8_C(180), UINT8_C(174), UINT8_C( 83),
                          UINT8_C(142), UINT8_C(198), UINT8_C( 36), UINT8_C(158)),
      simde_mm_set_epi16(INT16_C(   208), INT16_C(   180), INT16_C(   174), INT16_C(    83),
                         INT16_C(   142), INT16_C(   198), INT16_C(    36), INT16_C(   158)) },
    { simde_x_mm_set_epu8(UINT8_C( 48), UINT8_C(139), UINT8_C( 69), UINT8_C( 42),
                          UINT8_C(239), UINT8_C(255), UINT8_C( 84), UINT8_C(226),
                          UINT8_C(180), UINT8_C(204), UINT8_C( 81), UINT8_C(133),
                          UINT8_C(230), UINT8_C( 25), UINT8_C(218), UINT8_C(139)),
      simde_mm_set_epi16(INT16_C(   180), INT16_C(   204), INT16_C(    81), INT16_C(   133),
                         INT16_C(   230), INT16_C(    25), INT16_C(   218), INT16_C(   139)) },
    { simde_x_mm_set_epu8(UINT8_C(213), UINT8_C(  5), UINT8_C( 37), UINT8_C(243),
                          UINT8_C(196), UINT8_C(241), UINT8_C( 11), UINT8_C( 32),
                          UINT8_C(137), UINT8_C(  5), UINT8_C(216), UINT8_C(243),
                          UINT8_C( 25), UINT8_C( 23), UINT8_C(212), UINT8_C( 57)),
      simde_mm_set_epi16(INT16_C(   137), INT16_C(     5), INT16_C(   216), INT16_C(   243),
                         INT16_C(    25), INT16_C(    23), INT16_C(   212), INT16_C(    57)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepu8_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(216,  58,  77, 216, 179, 254,  83,  42,
                          179, 211,  84, 116, 211, 142,  19, 247),
      simde_mm_set_epi32(211, 142,  19, 247) },
    { simde_x_mm_set_epu8(161,  70,  71,  24,  62,  44,  28,  40,
                           34, 181, 114,  59,  33, 122,  68, 198),
      simde_mm_set_epi32( 33, 122,  68, 198) },
    { simde_x_mm_set_epu8(145, 160,  60, 140,  53, 127,  68, 235,
                          225, 143, 244,  79,  20,  67, 173, 209),
      simde_mm_set_epi32( 20,  67, 173, 209) },
    { simde_x_mm_set_epu8(117, 146, 120,  54, 143, 242, 141, 149,
                           73,  58,  87,  32, 199, 183, 202,  12),
      simde_mm_set_epi32(199, 183, 202,  12) },
    { simde_x_mm_set_epu8( 40,  57,  16,  79, 103, 249, 143, 197,
                          214,  78, 201,  95,  85,  53, 247, 134),
      simde_mm_set_epi32( 85,  53, 247, 134) },
    { simde_x_mm_set_epu8( 72, 163, 211, 103, 152, 114,   2, 140,
                           52,  64,   1,   9, 184, 145, 190, 245),
      simde_mm_set_epi32(184, 145, 190, 245) },
    { simde_x_mm_set_epu8(  7,  28, 147,   3,  70,  73, 159,  19,
                          118, 122, 100,  52, 236,  17, 135, 121),
      simde_mm_set_epi32(236,  17, 135, 121) },
    { simde_x_mm_set_epu8(100, 233, 199,  97, 158, 240, 121, 115,
                          142, 146, 159, 107, 202, 224, 156, 149),
      simde_mm_set_epi32(202, 224, 156, 149) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepu8_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(165), UINT8_C(138), UINT8_C(  9), UINT8_C(193),
                          UINT8_C(199), UINT8_C(213), UINT8_C(108), UINT8_C(127),
                          UINT8_C( 76), UINT8_C( 44), UINT8_C( 97), UINT8_C( 43),
                          UINT8_C( 10), UINT8_C( 41), UINT8_C(226), UINT8_C(134)),
      simde_mm_set_epi64x(INT64_C(                 226), INT64_C(                 134)) },
    { simde_x_mm_set_epu8(UINT8_C(206), UINT8_C(216), UINT8_C(228), UINT8_C( 95),
                          UINT8_C( 16), UINT8_C(235), UINT8_C(117), UINT8_C(249),
                          UINT8_C(118), UINT8_C(169), UINT8_C( 43), UINT8_C(125),
                          UINT8_C(139), UINT8_C(  7), UINT8_C( 78), UINT8_C( 91)),
      simde_mm_set_epi64x(INT64_C(                  78), INT64_C(                  91)) },
    { simde_x_mm_set_epu8(UINT8_C(217), UINT8_C( 54), UINT8_C( 70), UINT8_C( 24),
                          UINT8_C( 18), UINT8_C(185), UINT8_C(  8), UINT8_C( 83),
                          UINT8_C(138), UINT8_C(127), UINT8_C(171), UINT8_C(232),
                          UINT8_C( 25), UINT8_C( 28), UINT8_C(187), UINT8_C(172)),
      simde_mm_set_epi64x(INT64_C(                 187), INT64_C(                 172)) },
    { simde_x_mm_set_epu8(UINT8_C(139), UINT8_C(164), UINT8_C(130), UINT8_C(202),
                          UINT8_C(244), UINT8_C(121), UINT8_C( 41), UINT8_C(156),
                          UINT8_C(187), UINT8_C( 51), UINT8_C( 98), UINT8_C( 32),
                          UINT8_C(179), UINT8_C(192), UINT8_C(214), UINT8_C(180)),
      simde_mm_set_epi64x(INT64_C(                 214), INT64_C(                 180)) },
    { simde_x_mm_set_epu8(UINT8_C(216), UINT8_C( 40), UINT8_C(253), UINT8_C(179),
                          UINT8_C(134), UINT8_C(199), UINT8_C(  8), UINT8_C( 38),
                          UINT8_C(169), UINT8_C(253), UINT8_C(114), UINT8_C( 51),
                          UINT8_C(228), UINT8_C(119), UINT8_C(103), UINT8_C(155)),
      simde_mm_set_epi64x(INT64_C(                 103), INT64_C(                 155)) },
    { simde_x_mm_set_epu8(UINT8_C(197), UINT8_C(169), UINT8_C( 70), UINT8_C(235),
                          UINT8_C(100), UINT8_C(250), UINT8_C( 64), UINT8_C(127),
                          UINT8_C(118), UINT8_C(162), UINT8_C( 19), UINT8_C(173),
                          UINT8_C(116), UINT8_C(180), UINT8_C(  7), UINT8_C(216)),
      simde_mm_set_epi64x(INT64_C(                   7), INT64_C(                 216)) },
    { simde_x_mm_set_epu8(UINT8_C( 50), UINT8_C( 69), UINT8_C( 69), UINT8_C(227),
                          UINT8_C( 69), UINT8_C(  0), UINT8_C( 34), UINT8_C(232),
                          UINT8_C( 24), UINT8_C( 46), UINT8_C(141), UINT8_C(128),
                          UINT8_C(115), UINT8_C(157), UINT8_C(112), UINT8_C( 71)),
      simde_mm_set_epi64x(INT64_C(                 112), INT64_C(                  71)) },
    { simde_x_mm_set_epu8(UINT8_C(120), UINT8_C(  3), UINT8_C(197), UINT8_C(139),
                          UINT8_C( 31), UINT8_C(200), UINT8_C(250), UINT8_C(106),
                          UINT8_C(219), UINT8_C(  4), UINT8_C(206), UINT8_C( 64),
                          UINT8_C(217), UINT8_C(231), UINT8_C(229), UINT8_C( 14)),
      simde_mm_set_epi64x(INT64_C(                 229), INT64_C(                  14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepu16_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(45997), UINT16_C(54881), UINT16_C( 8073), UINT16_C(50053),
                           UINT16_C(33513), UINT16_C(60494), UINT16_C(44453), UINT16_C(35449)),
      simde_mm_set_epi32(INT32_C(      33513), INT32_C(      60494), INT32_C(      44453), INT32_C(      35449)) },
    { simde_x_mm_set_epu16(UINT16_C(29322), UINT16_C(60312), UINT16_C(23894), UINT16_C( 5611),
                           UINT16_C(43169), UINT16_C(36178), UINT16_C(30857), UINT16_C(27437)),
      simde_mm_set_epi32(INT32_C(      43169), INT32_C(      36178), INT32_C(      30857), INT32_C(      27437)) },
    { simde_x_mm_set_epu16(UINT16_C(36165), UINT16_C(32250), UINT16_C(32420), UINT16_C(54083),
                           UINT16_C(37595), UINT16_C( 6323), UINT16_C(24868), UINT16_C(13806)),
      simde_mm_set_epi32(INT32_C(      37595), INT32_C(       6323), INT32_C(      24868), INT32_C(      13806)) },
    { simde_x_mm_set_epu16(UINT16_C(47473), UINT16_C(25142), UINT16_C(53974), UINT16_C(29717),
                           UINT16_C(38600), UINT16_C(37432), UINT16_C(33857), UINT16_C( 7799)),
      simde_mm_set_epi32(INT32_C(      38600), INT32_C(      37432), INT32_C(      33857), INT32_C(       7799)) },
    { simde_x_mm_set_epu16(UINT16_C( 9476), UINT16_C(49162), UINT16_C(59100), UINT16_C(46196),
                           UINT16_C(39403), UINT16_C(33179), UINT16_C(42032), UINT16_C(16407)),
      simde_mm_set_epi32(INT32_C(      39403), INT32_C(      33179), INT32_C(      42032), INT32_C(      16407)) },
    { simde_x_mm_set_epu16(UINT16_C(13947), UINT16_C(14884), UINT16_C(63463), UINT16_C(60885),
                           UINT16_C(44795), UINT16_C(57577), UINT16_C( 9399), UINT16_C(54740)),
      simde_mm_set_epi32(INT32_C(      44795), INT32_C(      57577), INT32_C(       9399), INT32_C(      54740)) },
    { simde_x_mm_set_epu16(UINT16_C(16348), UINT16_C(41263), UINT16_C(29933), UINT16_C( 7966),
                           UINT16_C(11747), UINT16_C(45808), UINT16_C(10076), UINT16_C(52634)),
      simde_mm_set_epi32(INT32_C(      11747), INT32_C(      45808), INT32_C(      10076), INT32_C(      52634)) },
    { simde_x_mm_set_epu16(UINT16_C(44921), UINT16_C(31426), UINT16_C(50653), UINT16_C(39011),
                           UINT16_C(15796), UINT16_C(28031), UINT16_C(50348), UINT16_C(35430)),
      simde_mm_set_epi32(INT32_C(      15796), INT32_C(      28031), INT32_C(      50348), INT32_C(      35430)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu16_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepu16_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(36944), UINT16_C(47640), UINT16_C( 2187), UINT16_C(10560),
                           UINT16_C( 1923), UINT16_C(52017), UINT16_C(41190), UINT16_C(51381)),
      simde_mm_set_epi64x(INT64_C(               41190), INT64_C(               51381)) },
    { simde_x_mm_set_epu16(UINT16_C(59110), UINT16_C(  781), UINT16_C( 2267), UINT16_C(32518),
                           UINT16_C(16361), UINT16_C(14242), UINT16_C(28197), UINT16_C(27455)),
      simde_mm_set_epi64x(INT64_C(               28197), INT64_C(               27455)) },
    { simde_x_mm_set_epu16(UINT16_C(45312), UINT16_C( 9417), UINT16_C(53316), UINT16_C(54914),
                           UINT16_C( 6651), UINT16_C(32993), UINT16_C(51134), UINT16_C(31066)),
      simde_mm_set_epi64x(INT64_C(               51134), INT64_C(               31066)) },
    { simde_x_mm_set_epu16(UINT16_C( 6198), UINT16_C(41996), UINT16_C(34257), UINT16_C( 1856),
                           UINT16_C(54306), UINT16_C(57993), UINT16_C(28922), UINT16_C(25456)),
      simde_mm_set_epi64x(INT64_C(               28922), INT64_C(               25456)) },
    { simde_x_mm_set_epu16(UINT16_C(52812), UINT16_C(10727), UINT16_C(10105), UINT16_C(31173),
                           UINT16_C( 2196), UINT16_C(38149), UINT16_C(12797), UINT16_C(56721)),
      simde_mm_set_epi64x(INT64_C(               12797), INT64_C(               56721)) },
    { simde_x_mm_set_epu16(UINT16_C(43893), UINT16_C(22212), UINT16_C(55173), UINT16_C(39507),
                           UINT16_C(17371), UINT16_C( 1379), UINT16_C(37505), UINT16_C(51758)),
      simde_mm_set_epi64x(INT64_C(               37505), INT64_C(               51758)) },
    { simde_x_mm_set_epu16(UINT16_C(10102), UINT16_C(59029), UINT16_C(11878), UINT16_C(57288),
                           UINT16_C(63955), UINT16_C(62443), UINT16_C( 1106), UINT16_C(32843)),
      simde_mm_set_epi64x(INT64_C(                1106), INT64_C(               32843)) },
    { simde_x_mm_set_epu16(UINT16_C( 7384), UINT16_C(18925), UINT16_C(61664), UINT16_C(62156),
                           UINT16_C(64229), UINT16_C(12260), UINT16_C(17269), UINT16_C(  165)),
      simde_mm_set_epi64x(INT64_C(               17269), INT64_C(                 165)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu16_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtepu32_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(1089356158), UINT32_C( 716812601), UINT32_C(2600352285), UINT32_C( 851998215)),
      simde_mm_set_epi64x(INT64_C(          2600352285), INT64_C(           851998215)) },
    { simde_x_mm_set_epu32(UINT32_C(2083471993), UINT32_C(3995663695), UINT32_C( 718227173), UINT32_C(3645469582)),
      simde_mm_set_epi64x(INT64_C(           718227173), INT64_C(          3645469582)) },
    { simde_x_mm_set_epu32(UINT32_C(3121544286), UINT32_C( 583537062), UINT32_C( 362422775), UINT32_C(3876080612)),
      simde_mm_set_epi64x(INT64_C(           362422775), INT64_C(          3876080612)) },
    { simde_x_mm_set_epu32(UINT32_C( 336299187), UINT32_C(1772325077), UINT32_C(4159021368), UINT32_C(3897849224)),
      simde_mm_set_epi64x(INT64_C(          4159021368), INT64_C(          3897849224)) },
    { simde_x_mm_set_epu32(UINT32_C(2614142766), UINT32_C(3735995755), UINT32_C(2880699788), UINT32_C( 410975381)),
      simde_mm_set_epi64x(INT64_C(          2880699788), INT64_C(           410975381)) },
    { simde_x_mm_set_epu32(UINT32_C(2584819359), UINT32_C(2278276482), UINT32_C(3087779260), UINT32_C(2573826343)),
      simde_mm_set_epi64x(INT64_C(          3087779260), INT64_C(          2573826343)) },
    { simde_x_mm_set_epu32(UINT32_C( 809379705), UINT32_C( 343015345), UINT32_C( 434582428), UINT32_C( 776037113)),
      simde_mm_set_epi64x(INT64_C(           434582428), INT64_C(           776037113)) },
    { simde_x_mm_set_epu32(UINT32_C(2474833343), UINT32_C(1439643533), UINT32_C(3207542234), UINT32_C(2907982947)),
      simde_mm_set_epi64x(INT64_C(          3207542234), INT64_C(          2907982947)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu32_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_dp_pd(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 rff[2];
    const simde_float64 r13[2];
    const simde_float64 r42[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -185.10), SIMDE_FLOAT64_C(  -814.31) },
      { SIMDE_FLOAT64_C(  -633.40), SIMDE_FLOAT64_C(   264.07) },
      { SIMDE_FLOAT64_C(-97792.50), SIMDE_FLOAT64_C(-97792.50) },
      { SIMDE_FLOAT64_C(117242.34), SIMDE_FLOAT64_C(117242.34) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(  -565.06), SIMDE_FLOAT64_C(    69.81) },
      { SIMDE_FLOAT64_C(  -630.02), SIMDE_FLOAT64_C(   685.88) },
      { SIMDE_FLOAT64_C(403880.38), SIMDE_FLOAT64_C(403880.38) },
      { SIMDE_FLOAT64_C(355999.10), SIMDE_FLOAT64_C(355999.10) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(  -912.18), SIMDE_FLOAT64_C(  -668.17) },
      { SIMDE_FLOAT64_C(   101.41), SIMDE_FLOAT64_C(  -269.03) },
      { SIMDE_FLOAT64_C( 87253.60), SIMDE_FLOAT64_C( 87253.60) },
      { SIMDE_FLOAT64_C(-92504.17), SIMDE_FLOAT64_C(-92504.17) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(   285.64), SIMDE_FLOAT64_C(   880.46) },
      { SIMDE_FLOAT64_C(  -816.65), SIMDE_FLOAT64_C(  -835.72) },
      { SIMDE_FLOAT64_C(-969085.94), SIMDE_FLOAT64_C(-969085.94) },
      { SIMDE_FLOAT64_C(-233267.91), SIMDE_FLOAT64_C(-233267.91) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(  -436.25), SIMDE_FLOAT64_C(  -256.84) },
      { SIMDE_FLOAT64_C(  -171.01), SIMDE_FLOAT64_C(  -191.74) },
      { SIMDE_FLOAT64_C(123849.61), SIMDE_FLOAT64_C(123849.61) },
      { SIMDE_FLOAT64_C( 74603.11), SIMDE_FLOAT64_C( 74603.11) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(  -839.33), SIMDE_FLOAT64_C(   848.18) },
      { SIMDE_FLOAT64_C(  -470.04), SIMDE_FLOAT64_C(   103.69) },
      { SIMDE_FLOAT64_C(482466.46), SIMDE_FLOAT64_C(482466.46) },
      { SIMDE_FLOAT64_C(394518.67), SIMDE_FLOAT64_C(394518.67) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(  -686.56), SIMDE_FLOAT64_C(  -717.77) },
      { SIMDE_FLOAT64_C(   891.14), SIMDE_FLOAT64_C(   567.91) },
      { SIMDE_FLOAT64_C(-1019449.84), SIMDE_FLOAT64_C(-1019449.84) },
      { SIMDE_FLOAT64_C(-611821.08), SIMDE_FLOAT64_C(-611821.08) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(   596.26), SIMDE_FLOAT64_C(   722.67) },
      { SIMDE_FLOAT64_C(  -828.42), SIMDE_FLOAT64_C(  -588.84) },
      { SIMDE_FLOAT64_C(-919490.71), SIMDE_FLOAT64_C(-919490.71) },
      { SIMDE_FLOAT64_C(-493953.71), SIMDE_FLOAT64_C(-493953.71) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r;

    r = simde_mm_dp_pd(a, b, 0xff);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].rff), 1);
    r = simde_mm_dp_pd(a, b, 0x13);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r13), 1);
    r = simde_mm_dp_pd(a, b, 0x42);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r42), 1);
  }

  return 0;
}

static int
test_simde_mm_dp_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 rff[4];
    const simde_float32 r7f[4];
    const simde_float32 r2a[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -84.89),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    74.29) },
      { SIMDE_FLOAT32_C(   -51.70),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    82.57) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF },
      { SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF } },
    #endif
    { { SIMDE_FLOAT32_C(    23.12), SIMDE_FLOAT32_C(    22.36), SIMDE_FLOAT32_C(   -14.55), SIMDE_FLOAT32_C(    26.71) },
      { SIMDE_FLOAT32_C(    54.23), SIMDE_FLOAT32_C(   -31.26), SIMDE_FLOAT32_C(    26.29), SIMDE_FLOAT32_C(    36.85) },
      { SIMDE_FLOAT32_C(  1156.57), SIMDE_FLOAT32_C(  1156.57), SIMDE_FLOAT32_C(  1156.57), SIMDE_FLOAT32_C(  1156.57) },
      { SIMDE_FLOAT32_C(   172.30), SIMDE_FLOAT32_C(   172.30), SIMDE_FLOAT32_C(   172.30), SIMDE_FLOAT32_C(   172.30) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -698.97), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -698.97) } },
    { { SIMDE_FLOAT32_C(   -56.71), SIMDE_FLOAT32_C(    75.82), SIMDE_FLOAT32_C(    51.12), SIMDE_FLOAT32_C(   -94.58) },
      { SIMDE_FLOAT32_C(   -30.60), SIMDE_FLOAT32_C(    39.38), SIMDE_FLOAT32_C(    88.71), SIMDE_FLOAT32_C(   -29.94) },
      { SIMDE_FLOAT32_C( 12087.70), SIMDE_FLOAT32_C( 12087.70), SIMDE_FLOAT32_C( 12087.70), SIMDE_FLOAT32_C( 12087.70) },
      { SIMDE_FLOAT32_C(  9255.97), SIMDE_FLOAT32_C(  9255.97), SIMDE_FLOAT32_C(  9255.97), SIMDE_FLOAT32_C(  9255.97) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  2985.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  2985.79) } },
    { { SIMDE_FLOAT32_C(   -53.71), SIMDE_FLOAT32_C(   -37.29), SIMDE_FLOAT32_C(    41.85), SIMDE_FLOAT32_C(   -92.59) },
      { SIMDE_FLOAT32_C(   -16.40), SIMDE_FLOAT32_C(   -27.78), SIMDE_FLOAT32_C(   -72.83), SIMDE_FLOAT32_C(     3.70) },
      { SIMDE_FLOAT32_C( -1473.76), SIMDE_FLOAT32_C( -1473.76), SIMDE_FLOAT32_C( -1473.76), SIMDE_FLOAT32_C( -1473.76) },
      { SIMDE_FLOAT32_C( -1131.18), SIMDE_FLOAT32_C( -1131.18), SIMDE_FLOAT32_C( -1131.18), SIMDE_FLOAT32_C( -1131.18) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1035.92), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1035.92) } },
    { { SIMDE_FLOAT32_C(   -12.67), SIMDE_FLOAT32_C(     0.28), SIMDE_FLOAT32_C(   -22.01), SIMDE_FLOAT32_C(    35.63) },
      { SIMDE_FLOAT32_C(    32.23), SIMDE_FLOAT32_C(    30.33), SIMDE_FLOAT32_C(    18.20), SIMDE_FLOAT32_C(   -44.65) },
      { SIMDE_FLOAT32_C( -2391.32), SIMDE_FLOAT32_C( -2391.32), SIMDE_FLOAT32_C( -2391.32), SIMDE_FLOAT32_C( -2391.32) },
      { SIMDE_FLOAT32_C(  -800.44), SIMDE_FLOAT32_C(  -800.44), SIMDE_FLOAT32_C(  -800.44), SIMDE_FLOAT32_C(  -800.44) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     8.49), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     8.49) } },
    { { SIMDE_FLOAT32_C(   -47.31), SIMDE_FLOAT32_C(   -96.35), SIMDE_FLOAT32_C(    82.06), SIMDE_FLOAT32_C(   -93.08) },
      { SIMDE_FLOAT32_C(   -27.61), SIMDE_FLOAT32_C(     8.35), SIMDE_FLOAT32_C(    43.77), SIMDE_FLOAT32_C(    15.68) },
      { SIMDE_FLOAT32_C(  2633.98), SIMDE_FLOAT32_C(  2633.98), SIMDE_FLOAT32_C(  2633.98), SIMDE_FLOAT32_C(  2633.98) },
      { SIMDE_FLOAT32_C(  4093.47), SIMDE_FLOAT32_C(  4093.47), SIMDE_FLOAT32_C(  4093.47), SIMDE_FLOAT32_C(  4093.47) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -804.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -804.52) } },
    { { SIMDE_FLOAT32_C(   -15.82), SIMDE_FLOAT32_C(    -5.11), SIMDE_FLOAT32_C(    21.10), SIMDE_FLOAT32_C(    53.57) },
      { SIMDE_FLOAT32_C(   -65.73), SIMDE_FLOAT32_C(     9.81), SIMDE_FLOAT32_C(   -76.36), SIMDE_FLOAT32_C(   -19.43) },
      { SIMDE_FLOAT32_C( -1662.34), SIMDE_FLOAT32_C( -1662.34), SIMDE_FLOAT32_C( -1662.34), SIMDE_FLOAT32_C( -1662.34) },
      { SIMDE_FLOAT32_C(  -621.48), SIMDE_FLOAT32_C(  -621.48), SIMDE_FLOAT32_C(  -621.48), SIMDE_FLOAT32_C(  -621.48) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -50.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -50.13) } },
    { { SIMDE_FLOAT32_C(    72.52), SIMDE_FLOAT32_C(    65.48), SIMDE_FLOAT32_C(   -12.02), SIMDE_FLOAT32_C(   -43.88) },
      { SIMDE_FLOAT32_C(   -62.30), SIMDE_FLOAT32_C(    15.15), SIMDE_FLOAT32_C(    59.82), SIMDE_FLOAT32_C(    25.03) },
      { SIMDE_FLOAT32_C( -5343.33), SIMDE_FLOAT32_C( -5343.33), SIMDE_FLOAT32_C( -5343.33), SIMDE_FLOAT32_C( -5343.33) },
      { SIMDE_FLOAT32_C( -4245.01), SIMDE_FLOAT32_C( -4245.01), SIMDE_FLOAT32_C( -4245.01), SIMDE_FLOAT32_C( -4245.01) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   992.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   992.02) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde_test_x86_assert_equal_f32x4(simde_mm_dp_ps(a, b, 0xff), simde_mm_loadu_ps(test_vec[i].rff), 1);
    simde_test_x86_assert_equal_f32x4(simde_mm_dp_ps(a, b, 0x7f), simde_mm_loadu_ps(test_vec[i].r7f), 1);
    simde_test_x86_assert_equal_f32x4(simde_mm_dp_ps(a, b, 0x2a), simde_mm_loadu_ps(test_vec[i].r2a), 1);
  }

  return 0;
}

static int
test_simde_mm_extract_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int8_t r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-105), INT8_C(-107), INT8_C( -84), INT8_C( -57),
                        INT8_C(  13), INT8_C(-101), INT8_C( -59), INT8_C( -93),
                        INT8_C(  53), INT8_C(  83), INT8_C( -28), INT8_C( 126),
                        INT8_C(-111), INT8_C( -97), INT8_C(  25), INT8_C( -72)),
      INT8_C(-97) },
    { simde_mm_set_epi8(INT8_C( -76), INT8_C( -25), INT8_C(  36), INT8_C( -92),
                        INT8_C(  -6), INT8_C(  77), INT8_C( -49), INT8_C(-126),
                        INT8_C( -50), INT8_C(  79), INT8_C( -93), INT8_C( -95),
                        INT8_C( -54), INT8_C(-116), INT8_C( -84), INT8_C(  66)),
      INT8_C(-116) },
    { simde_mm_set_epi8(INT8_C(  83), INT8_C( 123), INT8_C( 120), INT8_C( -66),
                        INT8_C(  -3), INT8_C(  66), INT8_C( 110), INT8_C(  76),
                        INT8_C(   0), INT8_C(  83), INT8_C(  20), INT8_C( -12),
                        INT8_C(  83), INT8_C(   4), INT8_C( -39), INT8_C( 118)),
      INT8_C(4) },
    { simde_mm_set_epi8(INT8_C(  32), INT8_C(  30), INT8_C( 127), INT8_C( -79),
                        INT8_C( -10), INT8_C(  64), INT8_C( -45), INT8_C( 101),
                        INT8_C(  44), INT8_C( -25), INT8_C(-110), INT8_C( 105),
                        INT8_C(  83), INT8_C(  27), INT8_C(  15), INT8_C(   3)),
      INT8_C(27) },
    { simde_mm_set_epi8(INT8_C(  79), INT8_C(  95), INT8_C(-109), INT8_C(  26),
                        INT8_C( -81), INT8_C(  -5), INT8_C( -84), INT8_C( 115),
                        INT8_C( -48), INT8_C( 104), INT8_C(  67), INT8_C(  26),
                        INT8_C( -41), INT8_C( -30), INT8_C(  94), INT8_C( -19)),
      INT8_C(-30) },
    { simde_mm_set_epi8(INT8_C( -81), INT8_C( -80), INT8_C(-109), INT8_C( -14),
                        INT8_C(  65), INT8_C(  10), INT8_C(  95), INT8_C(  83),
                        INT8_C( 123), INT8_C(  45), INT8_C(  39), INT8_C( 106),
                        INT8_C( -16), INT8_C(-123), INT8_C( -27), INT8_C(  56)),
      INT8_C(-123) },
    { simde_mm_set_epi8(INT8_C(  86), INT8_C(  79), INT8_C(  41), INT8_C( -51),
                        INT8_C(  97), INT8_C(  42), INT8_C( 117), INT8_C(-119),
                        INT8_C( -18), INT8_C(-127), INT8_C(  28), INT8_C( -21),
                        INT8_C(-101), INT8_C( -61), INT8_C( -63), INT8_C(  13)),
      INT8_C(-61) },
    { simde_mm_set_epi8(INT8_C( -22), INT8_C( -42), INT8_C( 109), INT8_C( -75),
                        INT8_C( -84), INT8_C(  60), INT8_C( -44), INT8_C(   8),
                        INT8_C( 118), INT8_C( 102), INT8_C(  -6), INT8_C(   0),
                        INT8_C( -28), INT8_C( -81), INT8_C(   2), INT8_C(  94)),
      INT8_C(-81) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int8_t r = HEDLEY_STATIC_CAST(int8_t, simde_mm_extract_epi8(test_vec[i].a, 2));
    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_extract_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -989914365), INT32_C( -320568713), INT32_C(  764201252), INT32_C( -823076780)),
      -320568713 },
    { simde_mm_set_epi32(INT32_C( 1872661147), INT32_C( 1704933787), INT32_C( -552294669), INT32_C(-1494809408)),
      1704933787 },
    { simde_mm_set_epi32(INT32_C( 1741332044), INT32_C(  170998046), INT32_C( 1368723621), INT32_C(-2071088920)),
      170998046 },
    { simde_mm_set_epi32(INT32_C(-1942216470), INT32_C(-1426359243), INT32_C(  862877610), INT32_C(  898094861)),
      -1426359243 },
    { simde_mm_set_epi32(INT32_C(  998704029), INT32_C( 2083244310), INT32_C( 1997200410), INT32_C( -459833332)),
      2083244310 },
    { simde_mm_set_epi32(INT32_C( 1256369906), INT32_C(  953394288), INT32_C( 1499034833), INT32_C(  990189413)),
      953394288 },
    { simde_mm_set_epi32(INT32_C( 1704589159), INT32_C( -719174981), INT32_C( -821402820), INT32_C( -969954348)),
      -719174981 },
    { simde_mm_set_epi32(INT32_C(   29062750), INT32_C( 1388055657), INT32_C( 1520861645), INT32_C(-1651761160)),
      1388055657 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_extract_epi32(test_vec[i].a, 2);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_extract_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(   3272238239526171606), INT64_C(   1654850679014379440)),
      INT64_C(   3272238239526171606) },
    { simde_mm_set_epi64x(INT64_C(  -6129313439874067621), INT64_C(   8613384435853876616)),
      INT64_C(  -6129313439874067621) },
    { simde_mm_set_epi64x(INT64_C(  -6049641799095753965), INT64_C(  -2810493496227171537)),
      INT64_C(  -6049641799095753965) },
    { simde_mm_set_epi64x(INT64_C(   1486209521702266950), INT64_C(  -7779883419844099734)),
      INT64_C(   1486209521702266950) },
    { simde_mm_set_epi64x(INT64_C(  -4910022048576872084), INT64_C(  -5820696718361059251)),
      INT64_C(  -4910022048576872084) },
    { simde_mm_set_epi64x(INT64_C(  -1923881977407946859), INT64_C(  -5589720307210562868)),
      INT64_C(  -1923881977407946859) },
    { simde_mm_set_epi64x(INT64_C(  -3527421069943215520), INT64_C(   4545940692351426251)),
      INT64_C(  -3527421069943215520) },
    { simde_mm_set_epi64x(INT64_C(   6123229719758625458), INT64_C(   1813312819011147191)),
      INT64_C(   6123229719758625458) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_extract_epi64(test_vec[i].a, 1);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_extract_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    int32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -849.36), SIMDE_FLOAT32_C(  -598.79), SIMDE_FLOAT32_C(  -735.05), SIMDE_FLOAT32_C(   435.26) },
      -INT32_C(  1001105654) },
    { { SIMDE_FLOAT32_C(  -991.80), SIMDE_FLOAT32_C(  -606.95), SIMDE_FLOAT32_C(   532.00), SIMDE_FLOAT32_C(  -243.65) },
      -INT32_C(   998771917) },
    { { SIMDE_FLOAT32_C(   652.00), SIMDE_FLOAT32_C(  -803.65), SIMDE_FLOAT32_C(   853.23), SIMDE_FLOAT32_C(  -479.16) },
       INT32_C(  1143144448) },
    { { SIMDE_FLOAT32_C(  -496.01), SIMDE_FLOAT32_C(  -449.26), SIMDE_FLOAT32_C(   824.10), SIMDE_FLOAT32_C(   206.32) },
      -INT32_C(  1007156920) },
    { { SIMDE_FLOAT32_C(  -549.74), SIMDE_FLOAT32_C(    14.08), SIMDE_FLOAT32_C(   893.37), SIMDE_FLOAT32_C(   921.66) },
      -INT32_C(  1006014628) },
    { { SIMDE_FLOAT32_C(  -296.23), SIMDE_FLOAT32_C(   133.06), SIMDE_FLOAT32_C(  -137.87), SIMDE_FLOAT32_C(  -577.55) },
      -INT32_C(  1013703311) },
    { { SIMDE_FLOAT32_C(   -98.04), SIMDE_FLOAT32_C(   744.07), SIMDE_FLOAT32_C(    68.13), SIMDE_FLOAT32_C(   315.55) },
      -INT32_C(  1027337093) },
    { { SIMDE_FLOAT32_C(  -258.15), SIMDE_FLOAT32_C(   588.77), SIMDE_FLOAT32_C(  -722.13), SIMDE_FLOAT32_C(  -107.51) },
      -INT32_C(  1014951117) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    int32_t r = simde_mm_extract_ps(a, 0);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_floor_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -638.24), SIMDE_FLOAT64_C(  771.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -639.00), SIMDE_FLOAT64_C(  771.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.94), SIMDE_FLOAT64_C(  536.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -80.00), SIMDE_FLOAT64_C(  536.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  145.74), SIMDE_FLOAT64_C(  124.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  145.00), SIMDE_FLOAT64_C(  124.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  309.89), SIMDE_FLOAT64_C( -929.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  309.00), SIMDE_FLOAT64_C( -930.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  138.72), SIMDE_FLOAT64_C(  502.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  138.00), SIMDE_FLOAT64_C(  502.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  512.22), SIMDE_FLOAT64_C(  187.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  512.00), SIMDE_FLOAT64_C(  187.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  560.17), SIMDE_FLOAT64_C(  420.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  560.00), SIMDE_FLOAT64_C(  420.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  367.30), SIMDE_FLOAT64_C(  619.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  367.00), SIMDE_FLOAT64_C(  619.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_floor_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_floor_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   50.80), SIMDE_FLOAT32_C(  459.30), SIMDE_FLOAT32_C( -834.21), SIMDE_FLOAT32_C(  808.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   50.00), SIMDE_FLOAT32_C(  459.00), SIMDE_FLOAT32_C( -835.00), SIMDE_FLOAT32_C(  808.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -648.20), SIMDE_FLOAT32_C(  768.10), SIMDE_FLOAT32_C( -885.11), SIMDE_FLOAT32_C( -162.62)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -649.00), SIMDE_FLOAT32_C(  768.00), SIMDE_FLOAT32_C( -886.00), SIMDE_FLOAT32_C( -163.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -136.33), SIMDE_FLOAT32_C(  361.95), SIMDE_FLOAT32_C( -729.16), SIMDE_FLOAT32_C( -786.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -137.00), SIMDE_FLOAT32_C(  361.00), SIMDE_FLOAT32_C( -730.00), SIMDE_FLOAT32_C( -787.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -579.89), SIMDE_FLOAT32_C(   55.32), SIMDE_FLOAT32_C( -998.01), SIMDE_FLOAT32_C(  191.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -580.00), SIMDE_FLOAT32_C(   55.00), SIMDE_FLOAT32_C( -999.00), SIMDE_FLOAT32_C(  191.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  781.10), SIMDE_FLOAT32_C(  884.98), SIMDE_FLOAT32_C(  903.22), SIMDE_FLOAT32_C(  964.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  781.00), SIMDE_FLOAT32_C(  884.00), SIMDE_FLOAT32_C(  903.00), SIMDE_FLOAT32_C(  964.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  255.11), SIMDE_FLOAT32_C(  929.26), SIMDE_FLOAT32_C(  869.55), SIMDE_FLOAT32_C( -749.47)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  255.00), SIMDE_FLOAT32_C(  929.00), SIMDE_FLOAT32_C(  869.00), SIMDE_FLOAT32_C( -750.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -859.43), SIMDE_FLOAT32_C(  380.85), SIMDE_FLOAT32_C( -956.74), SIMDE_FLOAT32_C( -486.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -860.00), SIMDE_FLOAT32_C(  380.00), SIMDE_FLOAT32_C( -957.00), SIMDE_FLOAT32_C( -487.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  154.98), SIMDE_FLOAT32_C(  341.89), SIMDE_FLOAT32_C( -431.03), SIMDE_FLOAT32_C( -687.74)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  154.00), SIMDE_FLOAT32_C(  341.00), SIMDE_FLOAT32_C( -432.00), SIMDE_FLOAT32_C( -688.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_floor_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_floor_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -651.87), SIMDE_FLOAT64_C(  624.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  634.56), SIMDE_FLOAT64_C( -443.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -651.87), SIMDE_FLOAT64_C( -444.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -650.57), SIMDE_FLOAT64_C( -388.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  862.67), SIMDE_FLOAT64_C( -847.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -650.57), SIMDE_FLOAT64_C( -848.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -429.60), SIMDE_FLOAT64_C( -927.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  516.52), SIMDE_FLOAT64_C( -109.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -429.60), SIMDE_FLOAT64_C( -110.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  119.92), SIMDE_FLOAT64_C(  571.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   15.01), SIMDE_FLOAT64_C(  819.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  119.92), SIMDE_FLOAT64_C(  819.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -625.27), SIMDE_FLOAT64_C(  998.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -570.19), SIMDE_FLOAT64_C(  -85.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -625.27), SIMDE_FLOAT64_C(  -86.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.61), SIMDE_FLOAT64_C( -345.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -705.02), SIMDE_FLOAT64_C(  -93.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.61), SIMDE_FLOAT64_C(  -94.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -824.97), SIMDE_FLOAT64_C( -396.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -840.00), SIMDE_FLOAT64_C(  609.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -824.97), SIMDE_FLOAT64_C(  609.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  488.09), SIMDE_FLOAT64_C(  -64.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   92.99), SIMDE_FLOAT64_C(  531.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  488.09), SIMDE_FLOAT64_C(  531.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_floor_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_floor_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  932.95), SIMDE_FLOAT32_C(  946.85), SIMDE_FLOAT32_C( -866.96), SIMDE_FLOAT32_C(  383.68)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   82.96), SIMDE_FLOAT32_C(  541.21), SIMDE_FLOAT32_C(  296.52), SIMDE_FLOAT32_C(  677.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  932.95), SIMDE_FLOAT32_C(  946.85), SIMDE_FLOAT32_C( -866.96), SIMDE_FLOAT32_C(  677.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -824.32), SIMDE_FLOAT32_C( -924.44), SIMDE_FLOAT32_C(  -44.45), SIMDE_FLOAT32_C(  340.62)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  771.85), SIMDE_FLOAT32_C( -635.91), SIMDE_FLOAT32_C(  706.67), SIMDE_FLOAT32_C(  477.32)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -824.32), SIMDE_FLOAT32_C( -924.44), SIMDE_FLOAT32_C(  -44.45), SIMDE_FLOAT32_C(  477.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  991.94), SIMDE_FLOAT32_C(  918.28), SIMDE_FLOAT32_C( -617.36), SIMDE_FLOAT32_C(  932.02)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -21.99), SIMDE_FLOAT32_C(  274.28), SIMDE_FLOAT32_C(  819.55), SIMDE_FLOAT32_C( -957.22)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  991.94), SIMDE_FLOAT32_C(  918.28), SIMDE_FLOAT32_C( -617.36), SIMDE_FLOAT32_C( -958.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  178.34), SIMDE_FLOAT32_C( -961.13), SIMDE_FLOAT32_C(  949.60), SIMDE_FLOAT32_C( -711.62)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -951.61), SIMDE_FLOAT32_C(   53.93), SIMDE_FLOAT32_C(  376.79), SIMDE_FLOAT32_C( -892.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  178.34), SIMDE_FLOAT32_C( -961.13), SIMDE_FLOAT32_C(  949.60), SIMDE_FLOAT32_C( -893.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -858.80), SIMDE_FLOAT32_C(  721.75), SIMDE_FLOAT32_C(  422.70), SIMDE_FLOAT32_C( -573.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  473.81), SIMDE_FLOAT32_C( -473.48), SIMDE_FLOAT32_C(  815.69), SIMDE_FLOAT32_C(  520.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -858.80), SIMDE_FLOAT32_C(  721.75), SIMDE_FLOAT32_C(  422.70), SIMDE_FLOAT32_C(  520.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -849.38), SIMDE_FLOAT32_C(    6.45), SIMDE_FLOAT32_C( -927.45), SIMDE_FLOAT32_C( -143.78)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  593.59), SIMDE_FLOAT32_C(  314.52), SIMDE_FLOAT32_C(  115.80), SIMDE_FLOAT32_C(  369.25)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -849.38), SIMDE_FLOAT32_C(    6.45), SIMDE_FLOAT32_C( -927.45), SIMDE_FLOAT32_C(  369.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -22.36), SIMDE_FLOAT32_C(  891.64), SIMDE_FLOAT32_C(  742.10), SIMDE_FLOAT32_C(   13.68)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  900.76), SIMDE_FLOAT32_C( -733.09), SIMDE_FLOAT32_C( -137.10), SIMDE_FLOAT32_C(  -90.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -22.36), SIMDE_FLOAT32_C(  891.64), SIMDE_FLOAT32_C(  742.10), SIMDE_FLOAT32_C(  -91.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -977.22), SIMDE_FLOAT32_C(  -98.98), SIMDE_FLOAT32_C( -253.27), SIMDE_FLOAT32_C(  664.01)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  252.97), SIMDE_FLOAT32_C(  266.57), SIMDE_FLOAT32_C(  -16.11), SIMDE_FLOAT32_C( -404.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -977.22), SIMDE_FLOAT32_C(  -98.98), SIMDE_FLOAT32_C( -253.27), SIMDE_FLOAT32_C( -405.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_floor_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_insert_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  10), INT8_C( -18), INT8_C(-117), INT8_C(  95),
                        INT8_C(-108), INT8_C(  57), INT8_C(  54), INT8_C( -50),
                        INT8_C(  60), INT8_C( -68), INT8_C( 115), INT8_C(  14),
                        INT8_C( -71), INT8_C( -40), INT8_C(  34), INT8_C( 112)),
      6,
      simde_mm_set_epi8(INT8_C(  10), INT8_C( -18), INT8_C(-117), INT8_C(   6),
                        INT8_C(-108), INT8_C(  57), INT8_C(  54), INT8_C( -50),
                        INT8_C(  60), INT8_C( -68), INT8_C( 115), INT8_C(  14),
                        INT8_C( -71), INT8_C( -40), INT8_C(  34), INT8_C( 112)) },
    { simde_mm_set_epi8(INT8_C(-117), INT8_C(  67), INT8_C(-105), INT8_C(  26),
                        INT8_C( 118), INT8_C(  67), INT8_C(  72), INT8_C( 120),
                        INT8_C( -74), INT8_C(  -8), INT8_C(-126), INT8_C( -39),
                        INT8_C(  53), INT8_C(  74), INT8_C(  64), INT8_C( -74)),
      13,
      simde_mm_set_epi8(INT8_C(-117), INT8_C(  67), INT8_C(-105), INT8_C(  13),
                        INT8_C( 118), INT8_C(  67), INT8_C(  72), INT8_C( 120),
                        INT8_C( -74), INT8_C(  -8), INT8_C(-126), INT8_C( -39),
                        INT8_C(  53), INT8_C(  74), INT8_C(  64), INT8_C( -74)) },
    { simde_mm_set_epi8(INT8_C(  10), INT8_C(-114), INT8_C( 116), INT8_C(-108),
                        INT8_C(  36), INT8_C( -74), INT8_C(  76), INT8_C(  -2),
                        INT8_C( 118), INT8_C( -60), INT8_C(   3), INT8_C(  48),
                        INT8_C(  76), INT8_C( -18), INT8_C( -69), INT8_C(-110)),
      13,
      simde_mm_set_epi8(INT8_C(  10), INT8_C(-114), INT8_C( 116), INT8_C(  13),
                        INT8_C(  36), INT8_C( -74), INT8_C(  76), INT8_C(  -2),
                        INT8_C( 118), INT8_C( -60), INT8_C(   3), INT8_C(  48),
                        INT8_C(  76), INT8_C( -18), INT8_C( -69), INT8_C(-110)) },
    { simde_mm_set_epi8(INT8_C( -48), INT8_C( -33), INT8_C(  -9), INT8_C( -27),
                        INT8_C( -99), INT8_C(  29), INT8_C( 111), INT8_C(  85),
                        INT8_C( 104), INT8_C( -59), INT8_C( -17), INT8_C(  23),
                        INT8_C( 113), INT8_C(   8), INT8_C(  94), INT8_C( -32)),
      0,
      simde_mm_set_epi8(INT8_C( -48), INT8_C( -33), INT8_C(  -9), INT8_C(   0),
                        INT8_C( -99), INT8_C(  29), INT8_C( 111), INT8_C(  85),
                        INT8_C( 104), INT8_C( -59), INT8_C( -17), INT8_C(  23),
                        INT8_C( 113), INT8_C(   8), INT8_C(  94), INT8_C( -32)) },
    { simde_mm_set_epi8(INT8_C( -15), INT8_C(-126), INT8_C(  63), INT8_C(  14),
                        INT8_C(   2), INT8_C(  88), INT8_C( -73), INT8_C(  22),
                        INT8_C( -36), INT8_C(  60), INT8_C( -75), INT8_C( -26),
                        INT8_C( -12), INT8_C(-126), INT8_C(  44), INT8_C( -36)),
      8,
      simde_mm_set_epi8(INT8_C( -15), INT8_C(-126), INT8_C(  63), INT8_C(   8),
                        INT8_C(   2), INT8_C(  88), INT8_C( -73), INT8_C(  22),
                        INT8_C( -36), INT8_C(  60), INT8_C( -75), INT8_C( -26),
                        INT8_C( -12), INT8_C(-126), INT8_C(  44), INT8_C( -36)) },
    { simde_mm_set_epi8(INT8_C(  41), INT8_C(-102), INT8_C( 115), INT8_C(  65),
                        INT8_C(  22), INT8_C( -32), INT8_C( -29), INT8_C(  85),
                        INT8_C( -61), INT8_C(  79), INT8_C(-107), INT8_C(  -9),
                        INT8_C(  89), INT8_C(  -3), INT8_C(-124), INT8_C(  71)),
      4,
      simde_mm_set_epi8(INT8_C(  41), INT8_C(-102), INT8_C( 115), INT8_C(   4),
                        INT8_C(  22), INT8_C( -32), INT8_C( -29), INT8_C(  85),
                        INT8_C( -61), INT8_C(  79), INT8_C(-107), INT8_C(  -9),
                        INT8_C(  89), INT8_C(  -3), INT8_C(-124), INT8_C(  71)) },
    { simde_mm_set_epi8(INT8_C( 109), INT8_C( -46), INT8_C( -71), INT8_C( 107),
                        INT8_C( 105), INT8_C( 123), INT8_C( -72), INT8_C(  72),
                        INT8_C( -43), INT8_C( 111), INT8_C(  75), INT8_C(  60),
                        INT8_C(  47), INT8_C(  78), INT8_C( -45), INT8_C(-101)),
      7,
      simde_mm_set_epi8(INT8_C( 109), INT8_C( -46), INT8_C( -71), INT8_C(   7),
                        INT8_C( 105), INT8_C( 123), INT8_C( -72), INT8_C(  72),
                        INT8_C( -43), INT8_C( 111), INT8_C(  75), INT8_C(  60),
                        INT8_C(  47), INT8_C(  78), INT8_C( -45), INT8_C(-101)) },
    { simde_mm_set_epi8(INT8_C( -15), INT8_C( -23), INT8_C(  43), INT8_C(  15),
                        INT8_C(-126), INT8_C( 102), INT8_C( 109), INT8_C(  84),
                        INT8_C( -63), INT8_C(  80), INT8_C(-127), INT8_C( -46),
                        INT8_C(-119), INT8_C( 111), INT8_C( -57), INT8_C(  55)),
      15,
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -23), INT8_C(  43), INT8_C(  15),
                        INT8_C(-126), INT8_C( 102), INT8_C( 109), INT8_C(  84),
                        INT8_C( -63), INT8_C(  80), INT8_C(-127), INT8_C( -46),
                        INT8_C(-119), INT8_C( 111), INT8_C( -57), INT8_C(  55)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_insert_epi8(test_vec[i].a, test_vec[i].b, 12);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_insert_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int32_t b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1714139829), INT32_C(  980372706), INT32_C(-2140490700), INT32_C( 1671335242)),
      INT32_C( -570572581),
      simde_mm_set_epi32(INT32_C( -570572581), INT32_C(  980372706), INT32_C(-2140490700), INT32_C( 1671335242)) },
    { simde_mm_set_epi32(INT32_C( -385110226), INT32_C( 1048550831), INT32_C( -768686987), INT32_C( -197993270)),
      INT32_C(  292040766),
      simde_mm_set_epi32(INT32_C(  292040766), INT32_C( 1048550831), INT32_C( -768686987), INT32_C( -197993270)) },
    { simde_mm_set_epi32(INT32_C( 1804855856), INT32_C( -940421248), INT32_C(-2104492113), INT32_C(  529461525)),
      INT32_C(  514665012),
      simde_mm_set_epi32(INT32_C(  514665012), INT32_C( -940421248), INT32_C(-2104492113), INT32_C(  529461525)) },
    { simde_mm_set_epi32(INT32_C(  -85551175), INT32_C(  885869319), INT32_C( 2003605165), INT32_C( -219227805)),
      INT32_C( 1214139778),
      simde_mm_set_epi32(INT32_C( 1214139778), INT32_C(  885869319), INT32_C( 2003605165), INT32_C( -219227805)) },
    { simde_mm_set_epi32(INT32_C( -682699624), INT32_C( -729535744), INT32_C( -714850455), INT32_C(  418841580)),
      INT32_C( -606767281),
      simde_mm_set_epi32(INT32_C( -606767281), INT32_C( -729535744), INT32_C( -714850455), INT32_C(  418841580)) },
    { simde_mm_set_epi32(INT32_C( 1844877442), INT32_C(-1305620543), INT32_C( -803345723), INT32_C(-1617611400)),
      INT32_C(  166894477),
      simde_mm_set_epi32(INT32_C(  166894477), INT32_C(-1305620543), INT32_C( -803345723), INT32_C(-1617611400)) },
    { simde_mm_set_epi32(INT32_C( 1121577587), INT32_C( 1868325196), INT32_C(  567002451), INT32_C(-2029289287)),
      INT32_C(  566028624),
      simde_mm_set_epi32(INT32_C(  566028624), INT32_C( 1868325196), INT32_C(  567002451), INT32_C(-2029289287)) },
    { simde_mm_set_epi32(INT32_C( 1745932520), INT32_C(   83968460), INT32_C(-1677360074), INT32_C( -664327669)),
      INT32_C(-2041481189),
      simde_mm_set_epi32(INT32_C(-2041481189), INT32_C(   83968460), INT32_C(-1677360074), INT32_C( -664327669)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_insert_epi32(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_insert_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int64_t b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C( 7362174507306405090), INT64_C(-9193337552220811958)),
      INT64_C( -850374615753703205),
      simde_mm_set_epi64x(INT64_C( -850374615753703205), INT64_C(-9193337552220811958)) },
    { simde_mm_set_epi64x(INT64_C( 1254305542978645806), INT64_C( 4503491530864903285)),
      INT64_C(-9038724799495474923),
      simde_mm_set_epi64x(INT64_C(-9038724799495474923), INT64_C( 4503491530864903285)) },
    { simde_mm_set_epi64x(INT64_C( -941576252334200268), INT64_C( 7751796878868631424)),
      INT64_C( 3804779755638396589),
      simde_mm_set_epi64x(INT64_C( 3804779755638396589), INT64_C( 7751796878868631424)) },
    { simde_mm_set_epi64x(INT64_C(-3070259325336878100), INT64_C( 5214690643492116409)),
      INT64_C(-2932172554506065152),
      simde_mm_set_epi64x(INT64_C(-2932172554506065152), INT64_C( 5214690643492116409)) },
    { simde_mm_set_epi64x(INT64_C(-5607597529679140155), INT64_C(-6947588056948574385)),
      INT64_C(  716806322442901634),
      simde_mm_set_epi64x(INT64_C(  716806322442901634), INT64_C(-6947588056948574385)) },
    { simde_mm_set_epi64x(INT64_C( 4817139057959919948), INT64_C( 2435256986062520505)),
      INT64_C(-2853265611616884400),
      simde_mm_set_epi64x(INT64_C(-2853265611616884400), INT64_C( 2435256986062520505)) },
    { simde_mm_set_epi64x(INT64_C(-8768094940408262424), INT64_C(  360641792213091382)),
      INT64_C(-4200371864439390341),
      simde_mm_set_epi64x(INT64_C(-4200371864439390341), INT64_C(  360641792213091382)) },
    { simde_mm_set_epi64x(INT64_C(-6597763380374804743), INT64_C( 8897544020142746680)),
      INT64_C( 6543676199726157119),
      simde_mm_set_epi64x(INT64_C( 6543676199726157119), INT64_C( 8897544020142746680)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_insert_epi64(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_insert_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -841.30), SIMDE_FLOAT32_C(  235.25), SIMDE_FLOAT32_C( -673.83), SIMDE_FLOAT32_C( -700.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   92.06), SIMDE_FLOAT32_C(  735.95), SIMDE_FLOAT32_C(  171.76), SIMDE_FLOAT32_C(  644.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -841.30), SIMDE_FLOAT32_C(  235.25), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  658.47), SIMDE_FLOAT32_C( -385.89), SIMDE_FLOAT32_C(  916.54), SIMDE_FLOAT32_C( -937.06)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -209.24), SIMDE_FLOAT32_C( -655.00), SIMDE_FLOAT32_C( -722.53), SIMDE_FLOAT32_C( -502.41)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  658.47), SIMDE_FLOAT32_C( -385.89), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  364.58), SIMDE_FLOAT32_C( -402.45), SIMDE_FLOAT32_C( -252.76), SIMDE_FLOAT32_C(  525.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -670.47), SIMDE_FLOAT32_C(  704.70), SIMDE_FLOAT32_C(  -13.52), SIMDE_FLOAT32_C( -328.78)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  364.58), SIMDE_FLOAT32_C( -402.45), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  313.55), SIMDE_FLOAT32_C(  334.89), SIMDE_FLOAT32_C( -877.87), SIMDE_FLOAT32_C( -974.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  708.89), SIMDE_FLOAT32_C(   60.29), SIMDE_FLOAT32_C(  416.58), SIMDE_FLOAT32_C( -180.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  313.55), SIMDE_FLOAT32_C(  334.89), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  857.51), SIMDE_FLOAT32_C(  674.21), SIMDE_FLOAT32_C(  882.64), SIMDE_FLOAT32_C(  238.47)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  556.45), SIMDE_FLOAT32_C( -280.75), SIMDE_FLOAT32_C( -829.81), SIMDE_FLOAT32_C(  113.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  857.51), SIMDE_FLOAT32_C(  674.21), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  520.41), SIMDE_FLOAT32_C( -251.34), SIMDE_FLOAT32_C(  896.76), SIMDE_FLOAT32_C( -419.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   87.20), SIMDE_FLOAT32_C(  358.54), SIMDE_FLOAT32_C(  859.02), SIMDE_FLOAT32_C( -278.34)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  520.41), SIMDE_FLOAT32_C( -251.34), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  533.51), SIMDE_FLOAT32_C(  968.42), SIMDE_FLOAT32_C( -332.89), SIMDE_FLOAT32_C(  137.03)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -277.45), SIMDE_FLOAT32_C(  701.40), SIMDE_FLOAT32_C( -500.07), SIMDE_FLOAT32_C( -788.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  533.51), SIMDE_FLOAT32_C(  968.42), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -468.51), SIMDE_FLOAT32_C( -644.45), SIMDE_FLOAT32_C( -325.06), SIMDE_FLOAT32_C(  994.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  290.72), SIMDE_FLOAT32_C(  585.35), SIMDE_FLOAT32_C(  669.48), SIMDE_FLOAT32_C(   65.07)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -468.51), SIMDE_FLOAT32_C( -644.45), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_insert_ps(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_max_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -83), INT8_C(  29), INT8_C(   3), INT8_C(  84), INT8_C(  22), INT8_C(  -7), INT8_C( 112), INT8_C(-107),
                        INT8_C( -53), INT8_C(-125), INT8_C( -41), INT8_C( -27), INT8_C(-118), INT8_C(  43), INT8_C(  44), INT8_C(  16)),
      simde_mm_set_epi8(INT8_C( -80), INT8_C( -52), INT8_C(  93), INT8_C(  71), INT8_C(  45), INT8_C( -99), INT8_C( -14), INT8_C( -97),
                        INT8_C(  11), INT8_C(  62), INT8_C( 111), INT8_C(  17), INT8_C(-108), INT8_C(  -6), INT8_C(  95), INT8_C(   1)),
      simde_mm_set_epi8(INT8_C( -80), INT8_C(  29), INT8_C(  93), INT8_C(  84), INT8_C(  45), INT8_C(  -7), INT8_C( 112), INT8_C( -97),
                        INT8_C(  11), INT8_C(  62), INT8_C( 111), INT8_C(  17), INT8_C(-108), INT8_C(  43), INT8_C(  95), INT8_C(  16)) },
    { simde_mm_set_epi8(INT8_C(  61), INT8_C(-100), INT8_C(  79), INT8_C(  19), INT8_C( -86), INT8_C( 116), INT8_C( -34), INT8_C(  96),
                        INT8_C(  70), INT8_C( -48), INT8_C( -13), INT8_C( 103), INT8_C(-107), INT8_C(  79), INT8_C(  24), INT8_C( -71)),
      simde_mm_set_epi8(INT8_C(  39), INT8_C( -53), INT8_C(-117), INT8_C(  65), INT8_C( -55), INT8_C(  21), INT8_C(  49), INT8_C( -22),
                        INT8_C( 118), INT8_C( -71), INT8_C(-113), INT8_C(   2), INT8_C( -83), INT8_C( -74), INT8_C( -11), INT8_C(  85)),
      simde_mm_set_epi8(INT8_C(  61), INT8_C( -53), INT8_C(  79), INT8_C(  65), INT8_C( -55), INT8_C( 116), INT8_C(  49), INT8_C(  96),
                        INT8_C( 118), INT8_C( -48), INT8_C( -13), INT8_C( 103), INT8_C( -83), INT8_C(  79), INT8_C(  24), INT8_C(  85)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C(-124), INT8_C(-110), INT8_C(  22), INT8_C(-109), INT8_C( 127), INT8_C( -45), INT8_C( -62),
                        INT8_C(   0), INT8_C(  51), INT8_C( -98), INT8_C( -11), INT8_C( -54), INT8_C( -75), INT8_C(-101), INT8_C(-109)),
      simde_mm_set_epi8(INT8_C( -28), INT8_C(-120), INT8_C(  90), INT8_C( -89), INT8_C( -72), INT8_C(  93), INT8_C( -68), INT8_C(-105),
                        INT8_C(  39), INT8_C(  46), INT8_C(   2), INT8_C(   5), INT8_C(  16), INT8_C(  34), INT8_C( -99), INT8_C(  64)),
      simde_mm_set_epi8(INT8_C( -13), INT8_C(-120), INT8_C(  90), INT8_C(  22), INT8_C( -72), INT8_C( 127), INT8_C( -45), INT8_C( -62),
                        INT8_C(  39), INT8_C(  51), INT8_C(   2), INT8_C(   5), INT8_C(  16), INT8_C(  34), INT8_C( -99), INT8_C(  64)) },
    { simde_mm_set_epi8(INT8_C( -43), INT8_C(-102), INT8_C( 111), INT8_C(  97), INT8_C( -69), INT8_C( 104), INT8_C( -24), INT8_C(  -6),
                        INT8_C(  29), INT8_C(  43), INT8_C(  65), INT8_C(  47), INT8_C( -60), INT8_C(  52), INT8_C(   2), INT8_C( -40)),
      simde_mm_set_epi8(INT8_C(  -7), INT8_C(  85), INT8_C( -63), INT8_C(  48), INT8_C(-117), INT8_C(  19), INT8_C(  99), INT8_C(  67),
                        INT8_C( -50), INT8_C(-116), INT8_C(   5), INT8_C(   2), INT8_C( -96), INT8_C( 125), INT8_C( -95), INT8_C(   0)),
      simde_mm_set_epi8(INT8_C(  -7), INT8_C(  85), INT8_C( 111), INT8_C(  97), INT8_C( -69), INT8_C( 104), INT8_C(  99), INT8_C(  67),
                        INT8_C(  29), INT8_C(  43), INT8_C(  65), INT8_C(  47), INT8_C( -60), INT8_C( 125), INT8_C(   2), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  98), INT8_C(  -7), INT8_C( -56), INT8_C(   9), INT8_C(  74), INT8_C(  50), INT8_C( -95), INT8_C( 127),
                        INT8_C( 114), INT8_C( 118), INT8_C( -76), INT8_C( 110), INT8_C( -48), INT8_C( -50), INT8_C(  57), INT8_C( -47)),
      simde_mm_set_epi8(INT8_C(  47), INT8_C( -82), INT8_C(  66), INT8_C( -76), INT8_C(   6), INT8_C( 117), INT8_C(  80), INT8_C( -13),
                        INT8_C(  80), INT8_C(-109), INT8_C( 126), INT8_C(  70), INT8_C(  60), INT8_C(  40), INT8_C( -54), INT8_C(   3)),
      simde_mm_set_epi8(INT8_C(  98), INT8_C(  -7), INT8_C(  66), INT8_C(   9), INT8_C(  74), INT8_C( 117), INT8_C(  80), INT8_C( 127),
                        INT8_C( 114), INT8_C( 118), INT8_C( 126), INT8_C( 110), INT8_C(  60), INT8_C(  40), INT8_C(  57), INT8_C(   3)) },
    { simde_mm_set_epi8(INT8_C( -80), INT8_C( -39), INT8_C( 113), INT8_C( -58), INT8_C(  58), INT8_C( -88), INT8_C(  22), INT8_C( -99),
                        INT8_C( 112), INT8_C( -21), INT8_C(  44), INT8_C( -31), INT8_C(  -2), INT8_C( 109), INT8_C(  19), INT8_C( -74)),
      simde_mm_set_epi8(INT8_C(  71), INT8_C( -38), INT8_C(  47), INT8_C( -92), INT8_C(   8), INT8_C(  48), INT8_C( 105), INT8_C( -82),
                        INT8_C(  35), INT8_C(  54), INT8_C(  25), INT8_C(  36), INT8_C( 111), INT8_C(  -7), INT8_C( -12), INT8_C( -75)),
      simde_mm_set_epi8(INT8_C(  71), INT8_C( -38), INT8_C( 113), INT8_C( -58), INT8_C(  58), INT8_C(  48), INT8_C( 105), INT8_C( -82),
                        INT8_C( 112), INT8_C(  54), INT8_C(  44), INT8_C(  36), INT8_C( 111), INT8_C( 109), INT8_C(  19), INT8_C( -74)) },
    { simde_mm_set_epi8(INT8_C(  18), INT8_C( -41), INT8_C( -74), INT8_C(  60), INT8_C( -63), INT8_C( -55), INT8_C( -71), INT8_C( 118),
                        INT8_C(  46), INT8_C( -19), INT8_C(  19), INT8_C(  -7), INT8_C( -55), INT8_C( -75), INT8_C( 125), INT8_C( -82)),
      simde_mm_set_epi8(INT8_C(-125), INT8_C(-106), INT8_C(-127), INT8_C( -23), INT8_C( -63), INT8_C(   0), INT8_C(  56), INT8_C( -23),
                        INT8_C( -34), INT8_C( -32), INT8_C(  33), INT8_C( 127), INT8_C(  39), INT8_C( -68), INT8_C(-103), INT8_C( 126)),
      simde_mm_set_epi8(INT8_C(  18), INT8_C( -41), INT8_C( -74), INT8_C(  60), INT8_C( -63), INT8_C(   0), INT8_C(  56), INT8_C( 118),
                        INT8_C(  46), INT8_C( -19), INT8_C(  33), INT8_C( 127), INT8_C(  39), INT8_C( -68), INT8_C( 125), INT8_C( 126)) },
    { simde_mm_set_epi8(INT8_C( -90), INT8_C( -81), INT8_C(  72), INT8_C( -34), INT8_C( -85), INT8_C( 108), INT8_C(  42), INT8_C(  34),
                        INT8_C( -79), INT8_C( -48), INT8_C(   3), INT8_C( 113), INT8_C( -62), INT8_C(  25), INT8_C( -74), INT8_C(  13)),
      simde_mm_set_epi8(INT8_C( -44), INT8_C( -22), INT8_C(  26), INT8_C( -52), INT8_C(  29), INT8_C(  96), INT8_C( -97), INT8_C(  88),
                        INT8_C( -11), INT8_C(-125), INT8_C( -60), INT8_C(  88), INT8_C( -55), INT8_C(  40), INT8_C(  76), INT8_C( -80)),
      simde_mm_set_epi8(INT8_C( -44), INT8_C( -22), INT8_C(  72), INT8_C( -34), INT8_C(  29), INT8_C( 108), INT8_C(  42), INT8_C(  88),
                        INT8_C( -11), INT8_C( -48), INT8_C(   3), INT8_C( 113), INT8_C( -55), INT8_C(  40), INT8_C(  76), INT8_C(  13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_max_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  477039853), INT32_C( 1555162887), INT32_C(  960008067), INT32_C(-2078514865)),
      simde_mm_set_epi32(INT32_C( -346254872), INT32_C(   70690131), INT32_C( -249580279), INT32_C( -297974983)),
      simde_mm_set_epi32(INT32_C(  477039853), INT32_C( 1555162887), INT32_C(  960008067), INT32_C( -297974983)) },
    { simde_mm_set_epi32(INT32_C( 1946076095), INT32_C( 1626099315), INT32_C(  367020053), INT32_C( -768900730)),
      simde_mm_set_epi32(INT32_C( -534331032), INT32_C(-1542646073), INT32_C(  900332023), INT32_C( 1625404528)),
      simde_mm_set_epi32(INT32_C( 1946076095), INT32_C( 1626099315), INT32_C(  900332023), INT32_C( 1625404528)) },
    { simde_mm_set_epi32(INT32_C( 1785938855), INT32_C(  217054136), INT32_C(    6277613), INT32_C( 1323071612)),
      simde_mm_set_epi32(INT32_C(-1842447194), INT32_C( 1202045241), INT32_C(  391997517), INT32_C(  904511960)),
      simde_mm_set_epi32(INT32_C( 1785938855), INT32_C( 1202045241), INT32_C(  391997517), INT32_C( 1323071612)) },
    { simde_mm_set_epi32(INT32_C( -303416903), INT32_C(  131247622), INT32_C(-2038528381), INT32_C(-1774779832)),
      simde_mm_set_epi32(INT32_C(  307942484), INT32_C(-1408988466), INT32_C(-1799017519), INT32_C( 1885804693)),
      simde_mm_set_epi32(INT32_C(  307942484), INT32_C(  131247622), INT32_C(-1799017519), INT32_C( 1885804693)) },
    { simde_mm_set_epi32(INT32_C( -424176665), INT32_C(  531131808), INT32_C( -752351935), INT32_C(  650848232)),
      simde_mm_set_epi32(INT32_C(-1513144536), INT32_C( -875213417), INT32_C(-1592044131), INT32_C(-1714853090)),
      simde_mm_set_epi32(INT32_C( -424176665), INT32_C(  531131808), INT32_C( -752351935), INT32_C(  650848232)) },
    { simde_mm_set_epi32(INT32_C( 1901471013), INT32_C(-1928782687), INT32_C(-1204237637), INT32_C(-1735607658)),
      simde_mm_set_epi32(INT32_C( 1526238167), INT32_C( 1155872155), INT32_C( -981128645), INT32_C(-1655952235)),
      simde_mm_set_epi32(INT32_C( 1901471013), INT32_C( 1155872155), INT32_C( -981128645), INT32_C(-1655952235)) },
    { simde_mm_set_epi32(INT32_C( 2067002242), INT32_C( -967820279), INT32_C(-1842332164), INT32_C( 1466140749)),
      simde_mm_set_epi32(INT32_C(  -25857443), INT32_C(-1417095277), INT32_C(  -31302876), INT32_C(-1114441571)),
      simde_mm_set_epi32(INT32_C( 2067002242), INT32_C( -967820279), INT32_C(  -31302876), INT32_C( 1466140749)) },
    { simde_mm_set_epi32(INT32_C( -515864750), INT32_C( 1885657427), INT32_C(-1627411585), INT32_C( -455970760)),
      simde_mm_set_epi32(INT32_C( -505553594), INT32_C(-1363391302), INT32_C( 1929235496), INT32_C(-1212934452)),
      simde_mm_set_epi32(INT32_C( -505553594), INT32_C( 1885657427), INT32_C( 1929235496), INT32_C( -455970760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_max_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(31378), UINT16_C(24380), UINT16_C(40255), UINT16_C(13201),
                           UINT16_C(58870), UINT16_C(49460), UINT16_C(64732), UINT16_C(36111)),
      simde_x_mm_set_epu16(UINT16_C(64055), UINT16_C(45511), UINT16_C(61004), UINT16_C(49058),
                           UINT16_C(25195), UINT16_C(65082), UINT16_C(  861), UINT16_C( 2148)),
      simde_x_mm_set_epu16(UINT16_C(64055), UINT16_C(45511), UINT16_C(61004), UINT16_C(49058),
                           UINT16_C(58870), UINT16_C(65082), UINT16_C(64732), UINT16_C(36111)) },
    { simde_x_mm_set_epu16(UINT16_C(17034), UINT16_C(61660), UINT16_C(37691), UINT16_C(48256),
                           UINT16_C(52466), UINT16_C(59150), UINT16_C(48524), UINT16_C(48932)),
      simde_x_mm_set_epu16(UINT16_C( 9311), UINT16_C(52954), UINT16_C(59922), UINT16_C(37439),
                           UINT16_C(48521), UINT16_C(44576), UINT16_C(58557), UINT16_C( 4347)),
      simde_x_mm_set_epu16(UINT16_C(17034), UINT16_C(61660), UINT16_C(59922), UINT16_C(48256),
                           UINT16_C(52466), UINT16_C(59150), UINT16_C(58557), UINT16_C(48932)) },
    { simde_x_mm_set_epu16(UINT16_C( 3717), UINT16_C(65479), UINT16_C(47591), UINT16_C(37591),
                           UINT16_C(56498), UINT16_C(64377), UINT16_C( 4742), UINT16_C(26061)),
      simde_x_mm_set_epu16(UINT16_C(53135), UINT16_C(25263), UINT16_C(35893), UINT16_C(43723),
                           UINT16_C(55550), UINT16_C(13729), UINT16_C(44168), UINT16_C(18708)),
      simde_x_mm_set_epu16(UINT16_C(53135), UINT16_C(65479), UINT16_C(47591), UINT16_C(43723),
                           UINT16_C(56498), UINT16_C(64377), UINT16_C(44168), UINT16_C(26061)) },
    { simde_x_mm_set_epu16(UINT16_C(32738), UINT16_C(32324), UINT16_C(12257), UINT16_C( 4392),
                           UINT16_C(48941), UINT16_C(15991), UINT16_C(56181), UINT16_C(64839)),
      simde_x_mm_set_epu16(UINT16_C(54182), UINT16_C(32645), UINT16_C(19389), UINT16_C(64736),
                           UINT16_C(55568), UINT16_C(54741), UINT16_C(47863), UINT16_C(26870)),
      simde_x_mm_set_epu16(UINT16_C(54182), UINT16_C(32645), UINT16_C(19389), UINT16_C(64736),
                           UINT16_C(55568), UINT16_C(54741), UINT16_C(56181), UINT16_C(64839)) },
    { simde_x_mm_set_epu16(UINT16_C(25092), UINT16_C( 2337), UINT16_C(41136), UINT16_C(62054),
                           UINT16_C(31692), UINT16_C(47896), UINT16_C(26455), UINT16_C(41876)),
      simde_x_mm_set_epu16(UINT16_C(57533), UINT16_C( 4966), UINT16_C(21312), UINT16_C(22488),
                           UINT16_C(59621), UINT16_C( 4501), UINT16_C(18372), UINT16_C(62293)),
      simde_x_mm_set_epu16(UINT16_C(57533), UINT16_C( 4966), UINT16_C(41136), UINT16_C(62054),
                           UINT16_C(59621), UINT16_C(47896), UINT16_C(26455), UINT16_C(62293)) },
    { simde_x_mm_set_epu16(UINT16_C(48994), UINT16_C(54179), UINT16_C(26228), UINT16_C(61187),
                           UINT16_C(44854), UINT16_C(57084), UINT16_C(16902), UINT16_C( 1404)),
      simde_x_mm_set_epu16(UINT16_C( 4826), UINT16_C(23694), UINT16_C(32546), UINT16_C(41184),
                           UINT16_C(  725), UINT16_C(27358), UINT16_C(30444), UINT16_C(27027)),
      simde_x_mm_set_epu16(UINT16_C(48994), UINT16_C(54179), UINT16_C(32546), UINT16_C(61187),
                           UINT16_C(44854), UINT16_C(57084), UINT16_C(30444), UINT16_C(27027)) },
    { simde_x_mm_set_epu16(UINT16_C(60922), UINT16_C(51825), UINT16_C( 9165), UINT16_C(16534),
                           UINT16_C( 2526), UINT16_C(29939), UINT16_C(61826), UINT16_C(45025)),
      simde_x_mm_set_epu16(UINT16_C(10446), UINT16_C(28319), UINT16_C(61630), UINT16_C(32182),
                           UINT16_C(17860), UINT16_C(15017), UINT16_C(59067), UINT16_C(19548)),
      simde_x_mm_set_epu16(UINT16_C(60922), UINT16_C(51825), UINT16_C(61630), UINT16_C(32182),
                           UINT16_C(17860), UINT16_C(29939), UINT16_C(61826), UINT16_C(45025)) },
    { simde_x_mm_set_epu16(UINT16_C(34011), UINT16_C(36834), UINT16_C(12993), UINT16_C(21384),
                           UINT16_C(62643), UINT16_C(55943), UINT16_C(12296), UINT16_C(62062)),
      simde_x_mm_set_epu16(UINT16_C(22645), UINT16_C(31782), UINT16_C(42377), UINT16_C(17805),
                           UINT16_C(55262), UINT16_C(50550), UINT16_C(53828), UINT16_C(32401)),
      simde_x_mm_set_epu16(UINT16_C(34011), UINT16_C(36834), UINT16_C(42377), UINT16_C(21384),
                           UINT16_C(62643), UINT16_C(55943), UINT16_C(53828), UINT16_C(62062)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_max_epu32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(2532888443), UINT32_C( 529927089), UINT32_C(4207752004), UINT32_C(3510207683)),
      simde_x_mm_set_epu32(UINT32_C( 574626150), UINT32_C(1395025810), UINT32_C(1034901368), UINT32_C(3021400990)),
      simde_x_mm_set_epu32(UINT32_C(2532888443), UINT32_C(1395025810), UINT32_C(4207752004), UINT32_C(3510207683)) },
    { simde_x_mm_set_epu32(UINT32_C(2363706693), UINT32_C(3928702803), UINT32_C( 881772043), UINT32_C(  57971440)),
      simde_x_mm_set_epu32(UINT32_C(4216913656), UINT32_C(3303535239), UINT32_C( 568980555), UINT32_C( 308523788)),
      simde_x_mm_set_epu32(UINT32_C(4216913656), UINT32_C(3928702803), UINT32_C( 881772043), UINT32_C( 308523788)) },
    { simde_x_mm_set_epu32(UINT32_C( 548389896), UINT32_C(2976724828), UINT32_C(3723033325), UINT32_C(1050716143)),
      simde_x_mm_set_epu32(UINT32_C(3591135284), UINT32_C( 856620101), UINT32_C( 833768684), UINT32_C( 203883279)),
      simde_x_mm_set_epu32(UINT32_C(3591135284), UINT32_C(2976724828), UINT32_C(3723033325), UINT32_C(1050716143)) },
    { simde_x_mm_set_epu32(UINT32_C(3717602953), UINT32_C(2736045656), UINT32_C(2539339865), UINT32_C(2199825857)),
      simde_x_mm_set_epu32(UINT32_C(3331243307), UINT32_C(1452685186), UINT32_C(2337560284), UINT32_C(3592613020)),
      simde_x_mm_set_epu32(UINT32_C(3717602953), UINT32_C(2736045656), UINT32_C(2539339865), UINT32_C(3592613020)) },
    { simde_x_mm_set_epu32(UINT32_C(2462641628), UINT32_C(4101106468), UINT32_C(2939293383), UINT32_C( 448332726)),
      simde_x_mm_set_epu32(UINT32_C(4091790581), UINT32_C( 227177150), UINT32_C(4294101921), UINT32_C(1459100736)),
      simde_x_mm_set_epu32(UINT32_C(4091790581), UINT32_C(4101106468), UINT32_C(4294101921), UINT32_C(1459100736)) },
    { simde_x_mm_set_epu32(UINT32_C(1973671448), UINT32_C(1498045863), UINT32_C(1898038098), UINT32_C(1965060938)),
      simde_x_mm_set_epu32(UINT32_C(  29809850), UINT32_C( 861011023), UINT32_C(  63413124), UINT32_C(2176922492)),
      simde_x_mm_set_epu32(UINT32_C(1973671448), UINT32_C(1498045863), UINT32_C(1898038098), UINT32_C(2176922492)) },
    { simde_x_mm_set_epu32(UINT32_C( 526896309), UINT32_C( 817143907), UINT32_C(1563490657), UINT32_C(3681037749)),
      simde_x_mm_set_epu32(UINT32_C(3002623714), UINT32_C(3298584662), UINT32_C(1905485247), UINT32_C( 108377847)),
      simde_x_mm_set_epu32(UINT32_C(3002623714), UINT32_C(3298584662), UINT32_C(1905485247), UINT32_C(3681037749)) },
    { simde_x_mm_set_epu32(UINT32_C( 749402761), UINT32_C(3319236993), UINT32_C(3240012333), UINT32_C(1509228324)),
      simde_x_mm_set_epu32(UINT32_C(3285355124), UINT32_C(3206151128), UINT32_C(2987263147), UINT32_C(3706118926)),
      simde_x_mm_set_epu32(UINT32_C(3285355124), UINT32_C(3319236993), UINT32_C(3240012333), UINT32_C(3706118926)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -85), INT8_C( 106), INT8_C( -97), INT8_C( -26),
                        INT8_C(  -5), INT8_C(  83), INT8_C(-106), INT8_C(-116),
                        INT8_C(-113), INT8_C( -34), INT8_C( -81), INT8_C( 109),
                        INT8_C( -25), INT8_C( -16), INT8_C(  28), INT8_C( -76)),
      simde_mm_set_epi8(INT8_C( -69), INT8_C(  -4), INT8_C(  73), INT8_C( -90),
                        INT8_C(  93), INT8_C(-116), INT8_C(  19), INT8_C( 124),
                        INT8_C( -67), INT8_C(  48), INT8_C(  38), INT8_C(  11),
                        INT8_C(  21), INT8_C(  91), INT8_C( 118), INT8_C( 103)),
      simde_mm_set_epi8(INT8_C( -85), INT8_C(  -4), INT8_C( -97), INT8_C( -90),
                        INT8_C(  -5), INT8_C(-116), INT8_C(-106), INT8_C(-116),
                        INT8_C(-113), INT8_C( -34), INT8_C( -81), INT8_C(  11),
                        INT8_C( -25), INT8_C( -16), INT8_C(  28), INT8_C( -76)) },
    { simde_mm_set_epi8(INT8_C( -69), INT8_C( -84), INT8_C(  37), INT8_C( -17),
                        INT8_C(  36), INT8_C( -34), INT8_C(-104), INT8_C( 112),
                        INT8_C(  13), INT8_C(  47), INT8_C( -94), INT8_C( -38),
                        INT8_C( 111), INT8_C( -44), INT8_C( -90), INT8_C( -86)),
      simde_mm_set_epi8(INT8_C(-125), INT8_C(  55), INT8_C(   5), INT8_C( 113),
                        INT8_C( 100), INT8_C( -35), INT8_C(  -4), INT8_C(  29),
                        INT8_C(  60), INT8_C( 120), INT8_C( -36), INT8_C(  72),
                        INT8_C(  92), INT8_C(  31), INT8_C(  11), INT8_C(-106)),
      simde_mm_set_epi8(INT8_C(-125), INT8_C( -84), INT8_C(   5), INT8_C( -17),
                        INT8_C(  36), INT8_C( -35), INT8_C(-104), INT8_C(  29),
                        INT8_C(  13), INT8_C(  47), INT8_C( -94), INT8_C( -38),
                        INT8_C(  92), INT8_C( -44), INT8_C( -90), INT8_C(-106)) },
    { simde_mm_set_epi8(INT8_C(  49), INT8_C(-113), INT8_C( -25), INT8_C( -86),
                        INT8_C( 106), INT8_C(  71), INT8_C(  43), INT8_C(  81),
                        INT8_C( -66), INT8_C( 111), INT8_C(  40), INT8_C(  35),
                        INT8_C(  15), INT8_C(  51), INT8_C(  21), INT8_C(  60)),
      simde_mm_set_epi8(INT8_C(  37), INT8_C( -84), INT8_C( 110), INT8_C( -46),
                        INT8_C( -27), INT8_C( -56), INT8_C( 104), INT8_C(   2),
                        INT8_C(-105), INT8_C(  65), INT8_C(  54), INT8_C(  75),
                        INT8_C( 113), INT8_C(  29), INT8_C( -47), INT8_C(  84)),
      simde_mm_set_epi8(INT8_C(  37), INT8_C(-113), INT8_C( -25), INT8_C( -86),
                        INT8_C( -27), INT8_C( -56), INT8_C(  43), INT8_C(   2),
                        INT8_C(-105), INT8_C(  65), INT8_C(  40), INT8_C(  35),
                        INT8_C(  15), INT8_C(  29), INT8_C( -47), INT8_C(  60)) },
    { simde_mm_set_epi8(INT8_C(  -9), INT8_C( -51), INT8_C(  -8), INT8_C( -23),
                        INT8_C(  42), INT8_C(  26), INT8_C( -68), INT8_C( -93),
                        INT8_C( -78), INT8_C( -45), INT8_C( -36), INT8_C( -34),
                        INT8_C( -79), INT8_C( -94), INT8_C(  80), INT8_C(  99)),
      simde_mm_set_epi8(INT8_C(  27), INT8_C(  45), INT8_C(  48), INT8_C( -73),
                        INT8_C( -21), INT8_C(  86), INT8_C(  54), INT8_C( -39),
                        INT8_C(  -2), INT8_C( 108), INT8_C( -19), INT8_C( -81),
                        INT8_C( -52), INT8_C( 118), INT8_C(  61), INT8_C( -36)),
      simde_mm_set_epi8(INT8_C(  -9), INT8_C( -51), INT8_C(  -8), INT8_C( -73),
                        INT8_C( -21), INT8_C(  26), INT8_C( -68), INT8_C( -93),
                        INT8_C( -78), INT8_C( -45), INT8_C( -36), INT8_C( -81),
                        INT8_C( -79), INT8_C( -94), INT8_C(  61), INT8_C( -36)) },
    { simde_mm_set_epi8(INT8_C(  75), INT8_C(   2), INT8_C( -37), INT8_C( -22),
                        INT8_C( 110), INT8_C(-125), INT8_C(  33), INT8_C( -94),
                        INT8_C(  -5), INT8_C( -67), INT8_C( -78), INT8_C( -46),
                        INT8_C(  43), INT8_C( -89), INT8_C(  74), INT8_C(  18)),
      simde_mm_set_epi8(INT8_C(  84), INT8_C( -44), INT8_C(-115), INT8_C(  29),
                        INT8_C(-121), INT8_C(  22), INT8_C(  43), INT8_C(-123),
                        INT8_C( -63), INT8_C( -73), INT8_C(  36), INT8_C( -60),
                        INT8_C( -96), INT8_C( -58), INT8_C( -42), INT8_C(  78)),
      simde_mm_set_epi8(INT8_C(  75), INT8_C( -44), INT8_C(-115), INT8_C( -22),
                        INT8_C(-121), INT8_C(-125), INT8_C(  33), INT8_C(-123),
                        INT8_C( -63), INT8_C( -73), INT8_C( -78), INT8_C( -60),
                        INT8_C( -96), INT8_C( -89), INT8_C( -42), INT8_C(  18)) },
    { simde_mm_set_epi8(INT8_C( -82), INT8_C( -34), INT8_C(  74), INT8_C(  86),
                        INT8_C(  -7), INT8_C(  93), INT8_C( -99), INT8_C(  -7),
                        INT8_C( 127), INT8_C(  26), INT8_C( -51), INT8_C(  41),
                        INT8_C(  71), INT8_C(  67), INT8_C(-102), INT8_C(-119)),
      simde_mm_set_epi8(INT8_C(  -8), INT8_C(  88), INT8_C(  46), INT8_C( 105),
                        INT8_C( -43), INT8_C(-109), INT8_C(  38), INT8_C( -35),
                        INT8_C( -17), INT8_C(  -4), INT8_C(-122), INT8_C(-112),
                        INT8_C( -62), INT8_C( 100), INT8_C(  89), INT8_C( -83)),
      simde_mm_set_epi8(INT8_C( -82), INT8_C( -34), INT8_C(  46), INT8_C(  86),
                        INT8_C( -43), INT8_C(-109), INT8_C( -99), INT8_C( -35),
                        INT8_C( -17), INT8_C(  -4), INT8_C(-122), INT8_C(-112),
                        INT8_C( -62), INT8_C(  67), INT8_C(-102), INT8_C(-119)) },
    { simde_mm_set_epi8(INT8_C(  21), INT8_C( -83), INT8_C(  -9), INT8_C( -66),
                        INT8_C( -50), INT8_C( -47), INT8_C( -30), INT8_C(   4),
                        INT8_C( -60), INT8_C(  23), INT8_C( 126), INT8_C(  69),
                        INT8_C(  56), INT8_C(   4), INT8_C(  32), INT8_C(  31)),
      simde_mm_set_epi8(INT8_C(  76), INT8_C( -95), INT8_C(  81), INT8_C(   9),
                        INT8_C(-106), INT8_C( -75), INT8_C(  46), INT8_C( 117),
                        INT8_C(-119), INT8_C( -56), INT8_C(-115), INT8_C( -97),
                        INT8_C( -52), INT8_C( -81), INT8_C(-123), INT8_C(  54)),
      simde_mm_set_epi8(INT8_C(  21), INT8_C( -95), INT8_C(  -9), INT8_C( -66),
                        INT8_C(-106), INT8_C( -75), INT8_C( -30), INT8_C(   4),
                        INT8_C(-119), INT8_C( -56), INT8_C(-115), INT8_C( -97),
                        INT8_C( -52), INT8_C( -81), INT8_C(-123), INT8_C(  31)) },
    { simde_mm_set_epi8(INT8_C( -56), INT8_C(-107), INT8_C(  36), INT8_C( -66),
                        INT8_C( -22), INT8_C(-112), INT8_C(  57), INT8_C(  12),
                        INT8_C( -40), INT8_C(-109), INT8_C( -85), INT8_C(  86),
                        INT8_C( -31), INT8_C( -66), INT8_C(  99), INT8_C( -10)),
      simde_mm_set_epi8(INT8_C(  57), INT8_C(-109), INT8_C(  45), INT8_C(  32),
                        INT8_C(  94), INT8_C( -27), INT8_C(  11), INT8_C(  67),
                        INT8_C(-114), INT8_C( -40), INT8_C(-125), INT8_C(-106),
                        INT8_C(  72), INT8_C( -34), INT8_C(-102), INT8_C(  18)),
      simde_mm_set_epi8(INT8_C( -56), INT8_C(-109), INT8_C(  36), INT8_C( -66),
                        INT8_C( -22), INT8_C(-112), INT8_C(  11), INT8_C(  12),
                        INT8_C(-114), INT8_C(-109), INT8_C(-125), INT8_C(-106),
                        INT8_C( -31), INT8_C( -66), INT8_C(-102), INT8_C( -10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1390607532), INT32_C(  385446037), INT32_C( -880551963), INT32_C(-1976882160)),
      simde_mm_set_epi32(INT32_C(-1328784057), INT32_C(  765325983), INT32_C(  188641041), INT32_C(-1795531007)),
      simde_mm_set_epi32(INT32_C(-1390607532), INT32_C(  385446037), INT32_C( -880551963), INT32_C(-1976882160)) },
    { simde_mm_set_epi32(INT32_C( 1033654035), INT32_C(-1435181472), INT32_C( 1188098919), INT32_C(-1789978439)),
      simde_mm_set_epi32(INT32_C(  667650881), INT32_C( -921357846), INT32_C( 1991872258), INT32_C(-1380518571)),
      simde_mm_set_epi32(INT32_C(  667650881), INT32_C(-1435181472), INT32_C( 1188098919), INT32_C(-1789978439)) },
    { simde_mm_set_epi32(INT32_C( -209415658), INT32_C(-1820339262), INT32_C(    3383029), INT32_C( -894067821)),
      simde_mm_set_epi32(INT32_C( -460825945), INT32_C(-1201816425), INT32_C(  657326597), INT32_C(  270703936)),
      simde_mm_set_epi32(INT32_C( -460825945), INT32_C(-1820339262), INT32_C(    3383029), INT32_C( -894067821)) },
    { simde_mm_set_epi32(INT32_C( -711299231), INT32_C(-1150752518), INT32_C(  489373999), INT32_C(-1003224360)),
      simde_mm_set_epi32(INT32_C( -111820496), INT32_C(-1961663677), INT32_C( -829684478), INT32_C(-1602379520)),
      simde_mm_set_epi32(INT32_C( -711299231), INT32_C(-1961663677), INT32_C( -829684478), INT32_C(-1602379520)) },
    { simde_mm_set_epi32(INT32_C( 1660536841), INT32_C( 1244832127), INT32_C( 1920382062), INT32_C( -791791151)),
      simde_mm_set_epi32(INT32_C(  799949492), INT32_C(  108351731), INT32_C( 1351843398), INT32_C( 1009306115)),
      simde_mm_set_epi32(INT32_C(  799949492), INT32_C(  108351731), INT32_C( 1351843398), INT32_C( -791791151)) },
    { simde_mm_set_epi32(INT32_C(-1327926842), INT32_C(  984094365), INT32_C( 1894460641), INT32_C(  -26405962)),
      simde_mm_set_epi32(INT32_C( 1205481380), INT32_C(  137390510), INT32_C(  590747940), INT32_C( 1878652085)),
      simde_mm_set_epi32(INT32_C(-1327926842), INT32_C(  137390510), INT32_C(  590747940), INT32_C(  -26405962)) },
    { simde_mm_set_epi32(INT32_C(  316126780), INT32_C(-1043744394), INT32_C(  787289081), INT32_C( -910852690)),
      simde_mm_set_epi32(INT32_C(-2087288343), INT32_C(-1056950039), INT32_C( -555736705), INT32_C(  666671486)),
      simde_mm_set_epi32(INT32_C(-2087288343), INT32_C(-1056950039), INT32_C( -555736705), INT32_C( -910852690)) },
    { simde_mm_set_epi32(INT32_C(-1498461986), INT32_C(-1418974686), INT32_C(-1311767695), INT32_C(-1038502387)),
      simde_mm_set_epi32(INT32_C( -722855220), INT32_C(  492871512), INT32_C( -175913896), INT32_C( -920105808)),
      simde_mm_set_epi32(INT32_C(-1498461986), INT32_C(-1418974686), INT32_C(-1311767695), INT32_C(-1038502387)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(51368), UINT16_C(47248), UINT16_C( 2518), UINT16_C(59587),
                           UINT16_C(64433), UINT16_C(45544), UINT16_C( 8944), UINT16_C(56380)),
      simde_x_mm_set_epu16(UINT16_C(35287), UINT16_C( 4953), UINT16_C(55160), UINT16_C(11599),
                           UINT16_C( 1282), UINT16_C(22629), UINT16_C( 1908), UINT16_C(57232)),
      simde_x_mm_set_epu16(UINT16_C(35287), UINT16_C( 4953), UINT16_C( 2518), UINT16_C(11599),
                           UINT16_C( 1282), UINT16_C(22629), UINT16_C( 1908), UINT16_C(56380)) },
    { simde_x_mm_set_epu16(UINT16_C(51082), UINT16_C(41324), UINT16_C(63856), UINT16_C(49625),
                           UINT16_C(47646), UINT16_C(40071), UINT16_C(43894), UINT16_C( 6845)),
      simde_x_mm_set_epu16(UINT16_C(29622), UINT16_C(57397), UINT16_C(58908), UINT16_C(15516),
                           UINT16_C(57300), UINT16_C(16770), UINT16_C( 6179), UINT16_C(31976)),
      simde_x_mm_set_epu16(UINT16_C(29622), UINT16_C(41324), UINT16_C(58908), UINT16_C(15516),
                           UINT16_C(47646), UINT16_C(16770), UINT16_C( 6179), UINT16_C( 6845)) },
    { simde_x_mm_set_epu16(UINT16_C( 7791), UINT16_C( 9357), UINT16_C(51414), UINT16_C(32085),
                           UINT16_C( 5803), UINT16_C(15112), UINT16_C( 4983), UINT16_C(62284)),
      simde_x_mm_set_epu16(UINT16_C(19191), UINT16_C(53664), UINT16_C(31350), UINT16_C(59818),
                           UINT16_C(36846), UINT16_C(44912), UINT16_C(44597), UINT16_C(18257)),
      simde_x_mm_set_epu16(UINT16_C( 7791), UINT16_C( 9357), UINT16_C(31350), UINT16_C(32085),
                           UINT16_C( 5803), UINT16_C(15112), UINT16_C( 4983), UINT16_C(18257)) },
    { simde_x_mm_set_epu16(UINT16_C(23178), UINT16_C(52616), UINT16_C(54786), UINT16_C(18857),
                           UINT16_C(64323), UINT16_C(44008), UINT16_C(12675), UINT16_C(13653)),
      simde_x_mm_set_epu16(UINT16_C(16010), UINT16_C(49432), UINT16_C(46679), UINT16_C(33525),
                           UINT16_C(47161), UINT16_C(64878), UINT16_C(40685), UINT16_C(46136)),
      simde_x_mm_set_epu16(UINT16_C(16010), UINT16_C(49432), UINT16_C(46679), UINT16_C(18857),
                           UINT16_C(47161), UINT16_C(44008), UINT16_C(12675), UINT16_C(13653)) },
    { simde_x_mm_set_epu16(UINT16_C(33571), UINT16_C(12594), UINT16_C( 3662), UINT16_C(56380),
                           UINT16_C(54926), UINT16_C(32164), UINT16_C( 3421), UINT16_C(38714)),
      simde_x_mm_set_epu16(UINT16_C(65175), UINT16_C(47536), UINT16_C(21879), UINT16_C(12881),
                           UINT16_C(50915), UINT16_C(31304), UINT16_C(10941), UINT16_C(57984)),
      simde_x_mm_set_epu16(UINT16_C(33571), UINT16_C(12594), UINT16_C( 3662), UINT16_C(12881),
                           UINT16_C(50915), UINT16_C(31304), UINT16_C( 3421), UINT16_C(38714)) },
    { simde_x_mm_set_epu16(UINT16_C(17540), UINT16_C(62844), UINT16_C(46558), UINT16_C(45098),
                           UINT16_C(32389), UINT16_C(20250), UINT16_C(19285), UINT16_C(40862)),
      simde_x_mm_set_epu16(UINT16_C(17361), UINT16_C( 8131), UINT16_C(50246), UINT16_C(30481),
                           UINT16_C(30265), UINT16_C(57439), UINT16_C(42358), UINT16_C(24996)),
      simde_x_mm_set_epu16(UINT16_C(17361), UINT16_C( 8131), UINT16_C(46558), UINT16_C(30481),
                           UINT16_C(30265), UINT16_C(20250), UINT16_C(19285), UINT16_C(24996)) },
    { simde_x_mm_set_epu16(UINT16_C(11573), UINT16_C(56754), UINT16_C(38860), UINT16_C(26669),
                           UINT16_C(21209), UINT16_C( 2072), UINT16_C(19855), UINT16_C(11067)),
      simde_x_mm_set_epu16(UINT16_C( 4235), UINT16_C(30280), UINT16_C(23335), UINT16_C(17584),
                           UINT16_C( 3445), UINT16_C( 1117), UINT16_C(46968), UINT16_C(58704)),
      simde_x_mm_set_epu16(UINT16_C( 4235), UINT16_C(30280), UINT16_C(23335), UINT16_C(17584),
                           UINT16_C( 3445), UINT16_C( 1117), UINT16_C(19855), UINT16_C(11067)) },
    { simde_x_mm_set_epu16(UINT16_C( 1826), UINT16_C(34774), UINT16_C(17130), UINT16_C(44175),
                           UINT16_C(60865), UINT16_C(54658), UINT16_C(62552), UINT16_C(62233)),
      simde_x_mm_set_epu16(UINT16_C(15183), UINT16_C(55598), UINT16_C( 5779), UINT16_C(28145),
                           UINT16_C(24471), UINT16_C(50174), UINT16_C(53029), UINT16_C(43004)),
      simde_x_mm_set_epu16(UINT16_C( 1826), UINT16_C(34774), UINT16_C( 5779), UINT16_C(28145),
                           UINT16_C(24471), UINT16_C(50174), UINT16_C(53029), UINT16_C(43004)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_min_epu32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C( 788201309), UINT32_C(2071601612), UINT32_C(3123609508), UINT32_C(1344608341)),
      simde_x_mm_set_epu32(UINT32_C(3982697916), UINT32_C( 968486606), UINT32_C(1116860132), UINT32_C(2825138301)),
      simde_x_mm_set_epu32(UINT32_C( 788201309), UINT32_C( 968486606), UINT32_C(1116860132), UINT32_C(1344608341)) },
    { simde_x_mm_set_epu32(UINT32_C( 384132137), UINT32_C(1977877021), UINT32_C(4289747748), UINT32_C(2515962526)),
      simde_x_mm_set_epu32(UINT32_C(3869012810), UINT32_C( 645527240), UINT32_C(4230349530), UINT32_C(1145244296)),
      simde_x_mm_set_epu32(UINT32_C( 384132137), UINT32_C( 645527240), UINT32_C(4230349530), UINT32_C(1145244296)) },
    { simde_x_mm_set_epu32(UINT32_C(3974730728), UINT32_C(3242218332), UINT32_C(1720053534), UINT32_C(3159005428)),
      simde_x_mm_set_epu32(UINT32_C(3856942180), UINT32_C(4205396871), UINT32_C(2272972736), UINT32_C(4113553543)),
      simde_x_mm_set_epu32(UINT32_C(3856942180), UINT32_C(3242218332), UINT32_C(1720053534), UINT32_C(3159005428)) },
    { simde_x_mm_set_epu32(UINT32_C(3254877076), UINT32_C(2399148141), UINT32_C(2938842657), UINT32_C(1961058722)),
      simde_x_mm_set_epu32(UINT32_C(1528033433), UINT32_C( 461232656), UINT32_C(1948639979), UINT32_C(1593317844)),
      simde_x_mm_set_epu32(UINT32_C(1528033433), UINT32_C( 461232656), UINT32_C(1948639979), UINT32_C(1593317844)) },
    { simde_x_mm_set_epu32(UINT32_C(1721814381), UINT32_C(3279771329), UINT32_C(1032528892), UINT32_C(1770589845)),
      simde_x_mm_set_epu32(UINT32_C( 338961476), UINT32_C(1015681646), UINT32_C(2529171351), UINT32_C(1474803551)),
      simde_x_mm_set_epu32(UINT32_C( 338961476), UINT32_C(1015681646), UINT32_C(1032528892), UINT32_C(1474803551)) },
    { simde_x_mm_set_epu32(UINT32_C(2865994869), UINT32_C(3359283004), UINT32_C(2376950903), UINT32_C(2025629636)),
      simde_x_mm_set_epu32(UINT32_C(1089016862), UINT32_C(3251738064), UINT32_C(2393163457), UINT32_C( 147184464)),
      simde_x_mm_set_epu32(UINT32_C(1089016862), UINT32_C(3251738064), UINT32_C(2376950903), UINT32_C( 147184464)) },
    { simde_x_mm_set_epu32(UINT32_C(1041113949), UINT32_C(2410530901), UINT32_C( 131686205), UINT32_C(3148398563)),
      simde_x_mm_set_epu32(UINT32_C(1539533337), UINT32_C(3899801708), UINT32_C(3357338729), UINT32_C( 465532279)),
      simde_x_mm_set_epu32(UINT32_C(1041113949), UINT32_C(2410530901), UINT32_C( 131686205), UINT32_C( 465532279)) },
    { simde_x_mm_set_epu32(UINT32_C(2571079475), UINT32_C(4121171595), UINT32_C(3849859490), UINT32_C(2510281154)),
      simde_x_mm_set_epu32(UINT32_C(2596335814), UINT32_C(2240823510), UINT32_C(2609625051), UINT32_C(1259317116)),
      simde_x_mm_set_epu32(UINT32_C(2571079475), UINT32_C(2240823510), UINT32_C(2609625051), UINT32_C(1259317116)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_minpos_epu16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(40818), UINT16_C(13812), UINT16_C(10872), UINT16_C(54124),
                           UINT16_C(15100), UINT16_C(22810), UINT16_C(31798), UINT16_C(58017)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    5), UINT16_C(10872)) },
    { simde_x_mm_set_epu16(UINT16_C(37656), UINT16_C(38804), UINT16_C(35573), UINT16_C(33536),
                           UINT16_C(16030), UINT16_C(50431), UINT16_C(35836), UINT16_C(37491)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    3), UINT16_C(16030)) },
    { simde_x_mm_set_epu16(UINT16_C(56214), UINT16_C(56676), UINT16_C(56044), UINT16_C(59619),
                           UINT16_C(21150), UINT16_C(47982), UINT16_C(   92), UINT16_C(46668)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(   92)) },
    { simde_x_mm_set_epu16(UINT16_C(30841), UINT16_C(41481), UINT16_C(22332), UINT16_C(20377),
                           UINT16_C( 8461), UINT16_C(16174), UINT16_C(46168), UINT16_C(38746)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    3), UINT16_C( 8461)) },
    { simde_x_mm_set_epu16(UINT16_C(38550), UINT16_C(63031), UINT16_C(12859), UINT16_C(36699),
                           UINT16_C(19386), UINT16_C(49588), UINT16_C(27067), UINT16_C(12812)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(12812)) },
    { simde_x_mm_set_epu16(UINT16_C(20747), UINT16_C(29576), UINT16_C( 5460), UINT16_C(38860),
                           UINT16_C(52108), UINT16_C(  149), UINT16_C(63981), UINT16_C(19000)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    2), UINT16_C(  149)) },
    { simde_x_mm_set_epu16(UINT16_C(31686), UINT16_C( 5758), UINT16_C(64324), UINT16_C(55924),
                           UINT16_C(43567), UINT16_C(17467), UINT16_C(18633), UINT16_C(20456)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    6), UINT16_C( 5758)) },
    { simde_x_mm_set_epu16(UINT16_C(13431), UINT16_C(48627), UINT16_C(23340), UINT16_C(23935),
                           UINT16_C(12927), UINT16_C(48412), UINT16_C(33835), UINT16_C(15901)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    3), UINT16_C(12927)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_minpos_epu16(test_vec[i].a);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mpsadbw_epu8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(226), UINT8_C(204), UINT8_C(132), UINT8_C(191),
                          UINT8_C(109), UINT8_C(  5), UINT8_C( 22), UINT8_C(209),
                          UINT8_C(243), UINT8_C(105), UINT8_C(186), UINT8_C(151),
                          UINT8_C( 27), UINT8_C( 30), UINT8_C(223), UINT8_C( 88)),
      simde_x_mm_set_epu8(UINT8_C(139), UINT8_C(113), UINT8_C( 31), UINT8_C( 64),
                          UINT8_C(155), UINT8_C( 28), UINT8_C(223), UINT8_C(195),
                          UINT8_C(151), UINT8_C( 30), UINT8_C( 86), UINT8_C( 95),
                          UINT8_C(158), UINT8_C( 54), UINT8_C( 10), UINT8_C( 66)),
      simde_x_mm_set_epu16(UINT16_C(  289), UINT16_C(  222), UINT16_C(  124), UINT16_C(  292),
                           UINT16_C(  582), UINT16_C(  466), UINT16_C(  396), UINT16_C(  354)) },
    { simde_x_mm_set_epu8(UINT8_C(171), UINT8_C( 80), UINT8_C(108), UINT8_C(236),
                          UINT8_C(239), UINT8_C(191), UINT8_C(219), UINT8_C(208),
                          UINT8_C(165), UINT8_C( 30), UINT8_C(251), UINT8_C(196),
                          UINT8_C( 25), UINT8_C(255), UINT8_C( 78), UINT8_C( 81)),
      simde_x_mm_set_epu8(UINT8_C( 98), UINT8_C( 67), UINT8_C(141), UINT8_C(239),
                          UINT8_C( 33), UINT8_C(138), UINT8_C(161), UINT8_C(132),
                          UINT8_C( 23), UINT8_C( 84), UINT8_C(170), UINT8_C(230),
                          UINT8_C(214), UINT8_C(115), UINT8_C( 58), UINT8_C(130)),
      simde_x_mm_set_epu16(UINT16_C(  154), UINT16_C(  325), UINT16_C(  380), UINT16_C(  374),
                           UINT16_C(  386), UINT16_C(  495), UINT16_C(  331), UINT16_C(  257)) },
    { simde_x_mm_set_epu8(UINT8_C( 36), UINT8_C(  1), UINT8_C(  5), UINT8_C( 22),
                          UINT8_C( 73), UINT8_C(242), UINT8_C( 47), UINT8_C(  2),
                          UINT8_C(204), UINT8_C(245), UINT8_C( 42), UINT8_C( 38),
                          UINT8_C( 36), UINT8_C(136), UINT8_C( 36), UINT8_C(163)),
      simde_x_mm_set_epu8(UINT8_C(168), UINT8_C(213), UINT8_C(  2), UINT8_C( 30),
                          UINT8_C( 25), UINT8_C(127), UINT8_C( 31), UINT8_C(133),
                          UINT8_C(118), UINT8_C(121), UINT8_C(113), UINT8_C(231),
                          UINT8_C( 34), UINT8_C( 80), UINT8_C(116), UINT8_C( 25)),
      simde_x_mm_set_epu16(UINT16_C(  438), UINT16_C(  637), UINT16_C(  543), UINT16_C(  197),
                           UINT16_C(  414), UINT16_C(  749), UINT16_C(  430), UINT16_C(  116)) },
    { simde_x_mm_set_epu8(UINT8_C( 29), UINT8_C( 29), UINT8_C(199), UINT8_C(141),
                          UINT8_C(153), UINT8_C(161), UINT8_C(202), UINT8_C( 57),
                          UINT8_C( 56), UINT8_C( 10), UINT8_C(125), UINT8_C( 91),
                          UINT8_C(212), UINT8_C(168), UINT8_C( 43), UINT8_C(108)),
      simde_x_mm_set_epu8(UINT8_C( 54), UINT8_C( 56), UINT8_C(193), UINT8_C(184),
                          UINT8_C( 44), UINT8_C( 35), UINT8_C(133), UINT8_C( 78),
                          UINT8_C( 34), UINT8_C(199), UINT8_C(192), UINT8_C(116),
                          UINT8_C( 79), UINT8_C(137), UINT8_C(150), UINT8_C( 19)),
      simde_x_mm_set_epu16(UINT16_C(  251), UINT16_C(  293), UINT16_C(  234), UINT16_C(  340),
                           UINT16_C(  517), UINT16_C(  460), UINT16_C(  245), UINT16_C(  209)) },
    { simde_x_mm_set_epu8(UINT8_C(211), UINT8_C(227), UINT8_C(150), UINT8_C( 37),
                          UINT8_C(162), UINT8_C(249), UINT8_C(215), UINT8_C(195),
                          UINT8_C( 63), UINT8_C(183), UINT8_C(196), UINT8_C( 97),
                          UINT8_C( 60), UINT8_C(192), UINT8_C(194), UINT8_C(164)),
      simde_x_mm_set_epu8(UINT8_C(120), UINT8_C( 70), UINT8_C(238), UINT8_C(106),
                          UINT8_C( 29), UINT8_C( 66), UINT8_C( 80), UINT8_C(174),
                          UINT8_C( 76), UINT8_C(151), UINT8_C( 56), UINT8_C( 77),
                          UINT8_C( 36), UINT8_C(138), UINT8_C(170), UINT8_C(105)),
      simde_x_mm_set_epu16(UINT16_C(  444), UINT16_C(  282), UINT16_C(  295), UINT16_C(  333),
                           UINT16_C(  360), UINT16_C(  472), UINT16_C(  227), UINT16_C(  221)) },
    { simde_x_mm_set_epu8(UINT8_C(167), UINT8_C(231), UINT8_C(129), UINT8_C(236),
                          UINT8_C(158), UINT8_C( 34), UINT8_C(219), UINT8_C( 52),
                          UINT8_C(201), UINT8_C( 55), UINT8_C( 88), UINT8_C( 76),
                          UINT8_C( 91), UINT8_C(192), UINT8_C( 80), UINT8_C(141)),
      simde_x_mm_set_epu8(UINT8_C(215), UINT8_C(  0), UINT8_C( 39), UINT8_C(166),
                          UINT8_C( 94), UINT8_C(231), UINT8_C(224), UINT8_C(140),
                          UINT8_C(153), UINT8_C( 38), UINT8_C(229), UINT8_C(239),
                          UINT8_C(167), UINT8_C( 85), UINT8_C(242), UINT8_C(231)),
      simde_x_mm_set_epu16(UINT16_C(  350), UINT16_C(  573), UINT16_C(  237), UINT16_C(  385),
                           UINT16_C(  448), UINT16_C(  329), UINT16_C(  458), UINT16_C(  208)) },
    { simde_x_mm_set_epu8(UINT8_C(125), UINT8_C( 70), UINT8_C(248), UINT8_C(193),
                          UINT8_C(244), UINT8_C( 76), UINT8_C(163), UINT8_C(150),
                          UINT8_C(169), UINT8_C( 24), UINT8_C(114), UINT8_C( 21),
                          UINT8_C(171), UINT8_C( 13), UINT8_C(157), UINT8_C(178)),
      simde_x_mm_set_epu8(UINT8_C(198), UINT8_C(153), UINT8_C(205), UINT8_C(219),
                          UINT8_C(198), UINT8_C( 83), UINT8_C( 62), UINT8_C( 96),
                          UINT8_C(119), UINT8_C(213), UINT8_C( 90), UINT8_C(147),
                          UINT8_C(232), UINT8_C( 64), UINT8_C(164), UINT8_C(129)),
      simde_x_mm_set_epu16(UINT16_C(  260), UINT16_C(  272), UINT16_C(  281), UINT16_C(  234),
                           UINT16_C(  237), UINT16_C(  269), UINT16_C(  350), UINT16_C(  447)) },
    { simde_x_mm_set_epu8(UINT8_C( 35), UINT8_C(118), UINT8_C(198), UINT8_C( 85),
                          UINT8_C(  8), UINT8_C(150), UINT8_C(121), UINT8_C(243),
                          UINT8_C( 16), UINT8_C(221), UINT8_C(227), UINT8_C( 37),
                          UINT8_C( 87), UINT8_C( 66), UINT8_C(216), UINT8_C(177)),
      simde_x_mm_set_epu8(UINT8_C(148), UINT8_C(250), UINT8_C(  9), UINT8_C(204),
                          UINT8_C(136), UINT8_C(106), UINT8_C( 76), UINT8_C(162),
                          UINT8_C(111), UINT8_C( 61), UINT8_C( 51), UINT8_C(174),
                          UINT8_C(202), UINT8_C(248), UINT8_C( 64), UINT8_C(174)),
      simde_x_mm_set_epu16(UINT16_C(  354), UINT16_C(  270), UINT16_C(  529), UINT16_C(  391),
                           UINT16_C(  553), UINT16_C(   58), UINT16_C(  564), UINT16_C(  546)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mpsadbw_epu8(test_vec[i].a, test_vec[i].b, 7);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mul_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1795240134), INT32_C( -225235276), INT32_C(  260214100), INT32_C(-1437997118)),
      simde_mm_set_epi32(INT32_C(-1930516827), INT32_C(-2112091397), INT32_C(-2111031164), INT32_C( 1337416900)),
      simde_mm_set_epi64x(INT64_C(  475717488740520572), INT64_C(-1923201647764494200)) },
    { simde_mm_set_epi32(INT32_C(-2008734650), INT32_C( 1987866784), INT32_C( 1460586541), INT32_C( -308079008)),
      simde_mm_set_epi32(INT32_C( 1619497162), INT32_C( 1948444521), INT32_C(-1962326453), INT32_C(  355525826)),
      simde_mm_set_epi64x(INT64_C( 3873248143762690464), INT64_C( -109530043792460608)) },
    { simde_mm_set_epi32(INT32_C( -967525151), INT32_C(  610102911), INT32_C(  -82193087), INT32_C(  610685272)),
      simde_mm_set_epi32(INT32_C( -464555473), INT32_C( 1911406284), INT32_C( 1504403418), INT32_C( 1044708348)),
      simde_mm_set_epi64x(INT64_C( 1166154537972092724), INT64_C(  637988001659050656)) },
    { simde_mm_set_epi32(INT32_C(  734959886), INT32_C(  727387476), INT32_C(-1178464916), INT32_C(  759159032)),
      simde_mm_set_epi32(INT32_C(  227151790), INT32_C( 2027589232), INT32_C( -510665157), INT32_C(  664410245)),
      simde_mm_set_epi64x(INT64_C( 1474843013829258432), INT64_C(  504393038445082840)) },
    { simde_mm_set_epi32(INT32_C( -981875510), INT32_C(-1517853387), INT32_C(  645890048), INT32_C( 1483649404)),
      simde_mm_set_epi32(INT32_C(-1176179108), INT32_C( -884770028), INT32_C( 1667209942), INT32_C( -150484050)),
      simde_mm_set_epi64x(INT64_C( 1342951183715884836), INT64_C( -223265571094006200)) },
    { simde_mm_set_epi32(INT32_C( -229613172), INT32_C( -220620915), INT32_C( 1178015644), INT32_C(-1087297921)),
      simde_mm_set_epi32(INT32_C(-1751226172), INT32_C(-1807182523), INT32_C(  804591673), INT32_C( -413406506)),
      simde_mm_set_epi64x(INT64_C(  398702261796268545), INT64_C(  449496034501674026)) },
    { simde_mm_set_epi32(INT32_C(-1537480837), INT32_C( -185479936), INT32_C(  386155243), INT32_C(  479622311)),
      simde_mm_set_epi32(INT32_C( -579116298), INT32_C( -674452315), INT32_C( -142346909), INT32_C(-1350064613)),
      simde_mm_set_epi64x(INT64_C(  125097372221251840), INT64_C( -647521109686380643)) },
    { simde_mm_set_epi32(INT32_C( 2146108348), INT32_C(  341648975), INT32_C(  901701854), INT32_C(  -45673158)),
      simde_mm_set_epi32(INT32_C(  723948067), INT32_C( 1076365190), INT32_C( -693273363), INT32_C(  420311114)),
      simde_mm_set_epi64x(INT64_C(  367739063889180250), INT64_C(  -19196935918878012)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mul_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mullo_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1431531471), INT32_C(-1934656662), INT32_C( -638668877), INT32_C( 1966621031)),
      simde_mm_set_epi32(INT32_C( -646581607), INT32_C( 1232530244), INT32_C(  841047033), INT32_C(-1472432488)),
      simde_mm_set_epi32(INT32_C( 1865056439), INT32_C(-1849485784), INT32_C( 1840285211), INT32_C( 1940934440)) },
    { simde_mm_set_epi32(INT32_C( 2119691862), INT32_C( 1656188631), INT32_C(  949015012), INT32_C( -645064268)),
      simde_mm_set_epi32(INT32_C( 1854664684), INT32_C( 1364588379), INT32_C( -185048322), INT32_C( 1546431794)),
      simde_mm_set_epi32(INT32_C( -314310328), INT32_C( -410462355), INT32_C(  887719992), INT32_C( -220354264)) },
    { simde_mm_set_epi32(INT32_C(  390191893), INT32_C( 1246080619), INT32_C( 2032818940), INT32_C(-1664549536)),
      simde_mm_set_epi32(INT32_C( 1802476280), INT32_C(-1492538899), INT32_C( -866846002), INT32_C(-1929477089)),
      simde_mm_set_epi32(INT32_C( -357441960), INT32_C(-1318446065), INT32_C(-2019602744), INT32_C(-2076430688)) },
    { simde_mm_set_epi32(INT32_C( -629988407), INT32_C(-1719063308), INT32_C( -231912988), INT32_C( 1462330866)),
      simde_mm_set_epi32(INT32_C(-1320599620), INT32_C( -769970788), INT32_C( -625134420), INT32_C(  293199422)),
      simde_mm_set_epi32(INT32_C( -273826148), INT32_C(-1841674064), INT32_C(-1631324880), INT32_C( 1137740956)) },
    { simde_mm_set_epi32(INT32_C(-1221152076), INT32_C(-1223458578), INT32_C(-1263311025), INT32_C( 2089857790)),
      simde_mm_set_epi32(INT32_C(-2068401725), INT32_C( 1531524331), INT32_C( 1064638153), INT32_C( -843878287)),
      simde_mm_set_epi32(INT32_C( 1009816348), INT32_C( 1660269178), INT32_C( -203954425), INT32_C( -674749922)) },
    { simde_mm_set_epi32(INT32_C(-1283522478), INT32_C(  524522527), INT32_C( 1152886109), INT32_C( -438302719)),
      simde_mm_set_epi32(INT32_C(-2012975476), INT32_C(  -67951228), INT32_C(  258710699), INT32_C(  -25585755)),
      simde_mm_set_epi32(INT32_C( 1289709784), INT32_C( -508699908), INT32_C( 1615798559), INT32_C(  345423781)) },
    { simde_mm_set_epi32(INT32_C(  199098300), INT32_C(-1941350427), INT32_C(-1170519288), INT32_C( 2117275260)),
      simde_mm_set_epi32(INT32_C( 1736533752), INT32_C(  668304389), INT32_C(-1871663356), INT32_C( -231105582)),
      simde_mm_set_epi32(INT32_C( 1957733920), INT32_C(-1823880327), INT32_C( -994597856), INT32_C( -515705416)) },
    { simde_mm_set_epi32(INT32_C(  796248112), INT32_C(  -74441002), INT32_C(  756194998), INT32_C(  128690934)),
      simde_mm_set_epi32(INT32_C( -934813484), INT32_C( 1495167051), INT32_C(  549239917), INT32_C( 1315900336)),
      simde_mm_set_epi32(INT32_C( 1644414912), INT32_C(-1010128718), INT32_C(  723729278), INT32_C(-1157096672)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mullo_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_x_mm_mullo_epu32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(3025185092), UINT32_C(1071139209), UINT32_C(4112016578), UINT32_C(2016123065)),
      simde_x_mm_set_epu32(UINT32_C( 290328727), UINT32_C(2226082336), UINT32_C( 501526514), UINT32_C(1649328035)),
      simde_x_mm_set_epu32(UINT32_C(2095060764), UINT32_C( 725488416), UINT32_C( 347594084), UINT32_C(1695696075)) },
    { simde_x_mm_set_epu32(UINT32_C(3106040714), UINT32_C(3664680000), UINT32_C( 790276509), UINT32_C(3508971009)),
      simde_x_mm_set_epu32(UINT32_C(1699381529), UINT32_C( 875841923), UINT32_C(3450881837), UINT32_C(1814797908)),
      simde_x_mm_set_epu32(UINT32_C(4101048954), UINT32_C(1809587392), UINT32_C(  27941785), UINT32_C(3377337940)) },
    { simde_x_mm_set_epu32(UINT32_C(2893750485), UINT32_C(1249313952), UINT32_C(3305249000), UINT32_C(2880865177)),
      simde_x_mm_set_epu32(UINT32_C(  24592541), UINT32_C( 966747003), UINT32_C(3635146633), UINT32_C(4165399857)),
      simde_x_mm_set_epu32(UINT32_C(2814075553), UINT32_C(1297684704), UINT32_C(3327650856), UINT32_C(3182861641)) },
    { simde_x_mm_set_epu32(UINT32_C( 189392542), UINT32_C(3720757090), UINT32_C(3597240564), UINT32_C(1088106434)),
      simde_x_mm_set_epu32(UINT32_C(3260872370), UINT32_C(1980368114), UINT32_C(4105157694), UINT32_C(  87964330)),
      simde_x_mm_set_epu32(UINT32_C(2043031004), UINT32_C(1681486500), UINT32_C(2632866584), UINT32_C( 358329044)) },
    { simde_x_mm_set_epu32(UINT32_C(3751593359), UINT32_C( 552022460), UINT32_C(2369123294), UINT32_C(1803067683)),
      simde_x_mm_set_epu32(UINT32_C(3768762282), UINT32_C(1316515183), UINT32_C(3641532283), UINT32_C(3816235830)),
      simde_x_mm_set_epu32(UINT32_C(2583618038), UINT32_C(1284217988), UINT32_C(1857129898), UINT32_C( 431933026)) },
    { simde_x_mm_set_epu32(UINT32_C(1492473270), UINT32_C(1074984006), UINT32_C(4252907716), UINT32_C(1202847242)),
      simde_x_mm_set_epu32(UINT32_C(3343508230), UINT32_C(2110123114), UINT32_C( 454026106), UINT32_C( 903743904)),
      simde_x_mm_set_epu32(UINT32_C(2342937668), UINT32_C( 686271740), UINT32_C(3120093544), UINT32_C(1876500544)) },
    { simde_x_mm_set_epu32(UINT32_C( 998872003), UINT32_C(1287827774), UINT32_C( 838516167), UINT32_C( 572896344)),
      simde_x_mm_set_epu32(UINT32_C(1333196355), UINT32_C(3474739513), UINT32_C(2465428766), UINT32_C( 183148961)),
      simde_x_mm_set_epu32(UINT32_C( 299961865), UINT32_C( 909513934), UINT32_C( 369307730), UINT32_C(2022818648)) },
    { simde_x_mm_set_epu32(UINT32_C(2381114005), UINT32_C(  17395766), UINT32_C(1942367476), UINT32_C( 903009655)),
      simde_x_mm_set_epu32(UINT32_C(2255462391), UINT32_C( 872948613), UINT32_C(1238590873), UINT32_C(2084494234)),
      simde_x_mm_set_epu32(UINT32_C(3387154627), UINT32_C(1307487758), UINT32_C(  38347220), UINT32_C( 339949206)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_mullo_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_packus_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1174506975), INT32_C(-1622542395), INT32_C( -228565455), INT32_C( 1722092951)),
      simde_mm_set_epi32(INT32_C( -188735178), INT32_C( -859437923), INT32_C(      40707), INT32_C(-2078308106)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(40707), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535)) },
    { simde_mm_set_epi32(INT32_C(  279157042), INT32_C( -664033471), INT32_C( 1210432777), INT32_C(-1162534366)),
      simde_mm_set_epi32(INT32_C(  330673804), INT32_C(-1666667776), INT32_C(-1924642427), INT32_C(-1118465206)),
      simde_x_mm_set_epu16(UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0)) },
    { simde_mm_set_epi32(INT32_C(-1675273454), INT32_C(  252374167), INT32_C(-1898193118), INT32_C(-2121147721)),
      simde_mm_set_epi32(INT32_C(-1175340609), INT32_C( 1859609595), INT32_C(  305301369), INT32_C( 1936442403)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
                           UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0)) },
    { simde_mm_set_epi32(INT32_C( -372493069), INT32_C(-1071911212), INT32_C(  122218483), INT32_C( 1644546153)),
      simde_mm_set_epi32(INT32_C( -603471664), INT32_C( -435236634), INT32_C(-1237577227), INT32_C(      40156)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(40156),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535)) },
    { simde_mm_set_epi32(INT32_C( -132052641), INT32_C( 1567528732), INT32_C(   -1505776), INT32_C(  422872655)),
      simde_mm_set_epi32(INT32_C( 1525337323), INT32_C(-1409556892), INT32_C( -388396270), INT32_C(-2086963765)),
      simde_x_mm_set_epu16(UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535)) },
    { simde_mm_set_epi32(INT32_C(-1206563380), INT32_C( 1557268555), INT32_C( -872999034), INT32_C(  234221095)),
      simde_mm_set_epi32(INT32_C(  723455818), INT32_C(  773436940), INT32_C(  326719262), INT32_C( -826281673)),
      simde_x_mm_set_epu16(UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535)) },
    { simde_mm_set_epi32(INT32_C( -738729427), INT32_C( 1061139854), INT32_C(-2031157453), INT32_C( 2064098327)),
      simde_mm_set_epi32(INT32_C(-1034678142), INT32_C(   97345786), INT32_C( 1187222665), INT32_C(      61643)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(61643),
                           UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535)) },
    { simde_mm_set_epi32(INT32_C(-2037944282), INT32_C( -355400074), INT32_C( -341422900), INT32_C(-1605623445)),
      simde_mm_set_epi32(INT32_C(  629990551), INT32_C(  397893118), INT32_C(-1310491239), INT32_C(-2050362652)),
      simde_x_mm_set_epu16(UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0),
                           UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packus_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_round_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    int rounding;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  959.46), SIMDE_FLOAT64_C( -646.56)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  959.00), SIMDE_FLOAT64_C( -647.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -813.43), SIMDE_FLOAT64_C(  515.75)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -813.00), SIMDE_FLOAT64_C(  516.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -365.43), SIMDE_FLOAT64_C(  840.28)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -366.00), SIMDE_FLOAT64_C(  840.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -843.69), SIMDE_FLOAT64_C( -641.36)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -844.00), SIMDE_FLOAT64_C( -642.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -542.64), SIMDE_FLOAT64_C( -757.34)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -542.00), SIMDE_FLOAT64_C( -757.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -593.16), SIMDE_FLOAT64_C(  973.59)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -593.00), SIMDE_FLOAT64_C(  974.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   54.67), SIMDE_FLOAT64_C(  -54.55)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_pd(SIMDE_FLOAT64_C(   54.00), SIMDE_FLOAT64_C(  -54.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -31.89), SIMDE_FLOAT64_C(  136.86)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -31.00), SIMDE_FLOAT64_C(  136.00)) }
  };

  for (size_t i = 0 ; i < 2 ; i++) {
    simde__m128d r = simde_mm_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 2 ; i < 4 ; i++) {
    simde__m128d r = simde_mm_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 4 ; i < 6 ; i++) {
    simde__m128d r = simde_mm_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 6 ; i < 8 ; i++) {
    simde__m128d r = simde_mm_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_round_ps_nearest (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   942.50), SIMDE_FLOAT32_C(  -170.00), SIMDE_FLOAT32_C(  -707.50), SIMDE_FLOAT32_C(  -141.50) },
      { SIMDE_FLOAT32_C(   942.00), SIMDE_FLOAT32_C(  -170.00), SIMDE_FLOAT32_C(  -708.00), SIMDE_FLOAT32_C(  -142.00) } },
    { { SIMDE_FLOAT32_C(   730.50), SIMDE_FLOAT32_C(  -382.50), SIMDE_FLOAT32_C(  -584.75), SIMDE_FLOAT32_C(   316.00) },
      { SIMDE_FLOAT32_C(   730.00), SIMDE_FLOAT32_C(  -382.00), SIMDE_FLOAT32_C(  -585.00), SIMDE_FLOAT32_C(   316.00) } },
    { { SIMDE_FLOAT32_C(   664.50), SIMDE_FLOAT32_C(   102.50), SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(   350.50) },
      { SIMDE_FLOAT32_C(   664.00), SIMDE_FLOAT32_C(   102.00), SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(   350.00) } },
    { { SIMDE_FLOAT32_C(   658.50), SIMDE_FLOAT32_C(   697.50), SIMDE_FLOAT32_C(  -634.50), SIMDE_FLOAT32_C(  -560.00) },
      { SIMDE_FLOAT32_C(   658.00), SIMDE_FLOAT32_C(   698.00), SIMDE_FLOAT32_C(  -634.00), SIMDE_FLOAT32_C(  -560.00) } },
    { { SIMDE_FLOAT32_C(   909.50), SIMDE_FLOAT32_C(   418.80), SIMDE_FLOAT32_C(  -300.50), SIMDE_FLOAT32_C(   899.00) },
      { SIMDE_FLOAT32_C(   910.00), SIMDE_FLOAT32_C(   419.00), SIMDE_FLOAT32_C(  -300.00), SIMDE_FLOAT32_C(   899.00) } },
    { { SIMDE_FLOAT32_C(  -435.50), SIMDE_FLOAT32_C(  -752.50), SIMDE_FLOAT32_C(   535.50), SIMDE_FLOAT32_C(  -728.50) },
      { SIMDE_FLOAT32_C(  -436.00), SIMDE_FLOAT32_C(  -752.00), SIMDE_FLOAT32_C(   536.00), SIMDE_FLOAT32_C(  -728.00) } },
    { { SIMDE_FLOAT32_C(   455.50), SIMDE_FLOAT32_C(  -826.50), SIMDE_FLOAT32_C(   474.00), SIMDE_FLOAT32_C(    43.62) },
      { SIMDE_FLOAT32_C(   456.00), SIMDE_FLOAT32_C(  -826.00), SIMDE_FLOAT32_C(   474.00), SIMDE_FLOAT32_C(    44.00) } },
    { { SIMDE_FLOAT32_C(  -224.50), SIMDE_FLOAT32_C(   195.50), SIMDE_FLOAT32_C(   634.46), SIMDE_FLOAT32_C(  -670.50) },
      { SIMDE_FLOAT32_C(  -224.00), SIMDE_FLOAT32_C(   196.00), SIMDE_FLOAT32_C(   634.00), SIMDE_FLOAT32_C(  -670.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_ROUND);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 1, 0, values);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_NEAREST_INT);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_round_ps_ninf (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   457.50), SIMDE_FLOAT32_C(   497.50), SIMDE_FLOAT32_C(  -429.50), SIMDE_FLOAT32_C(    34.50) },
      { SIMDE_FLOAT32_C(   457.00), SIMDE_FLOAT32_C(   497.00), SIMDE_FLOAT32_C(  -430.00), SIMDE_FLOAT32_C(    34.00) } },
    { { SIMDE_FLOAT32_C(   657.50), SIMDE_FLOAT32_C(   359.50), SIMDE_FLOAT32_C(  -832.50), SIMDE_FLOAT32_C(  -675.50) },
      { SIMDE_FLOAT32_C(   657.00), SIMDE_FLOAT32_C(   359.00), SIMDE_FLOAT32_C(  -833.00), SIMDE_FLOAT32_C(  -676.00) } },
    { { SIMDE_FLOAT32_C(  -712.50), SIMDE_FLOAT32_C(    -7.50), SIMDE_FLOAT32_C(   505.50), SIMDE_FLOAT32_C(   -33.50) },
      { SIMDE_FLOAT32_C(  -713.00), SIMDE_FLOAT32_C(    -8.00), SIMDE_FLOAT32_C(   505.00), SIMDE_FLOAT32_C(   -34.00) } },
    { { SIMDE_FLOAT32_C(   866.50), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -890.50), SIMDE_FLOAT32_C(  -118.50) },
      { SIMDE_FLOAT32_C(   866.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -891.00), SIMDE_FLOAT32_C(  -119.00) } },
    { { SIMDE_FLOAT32_C(  -593.50), SIMDE_FLOAT32_C(  -471.50), SIMDE_FLOAT32_C(  -382.50), SIMDE_FLOAT32_C(  -230.50) },
      { SIMDE_FLOAT32_C(  -594.00), SIMDE_FLOAT32_C(  -472.00), SIMDE_FLOAT32_C(  -383.00), SIMDE_FLOAT32_C(  -231.00) } },
    { { SIMDE_FLOAT32_C(   438.44), SIMDE_FLOAT32_C(   337.97), SIMDE_FLOAT32_C(    -5.50), SIMDE_FLOAT32_C(  -139.50) },
      { SIMDE_FLOAT32_C(   438.00), SIMDE_FLOAT32_C(   337.00), SIMDE_FLOAT32_C(    -6.00), SIMDE_FLOAT32_C(  -140.00) } },
    { { SIMDE_FLOAT32_C(   860.50), SIMDE_FLOAT32_C(   968.50), SIMDE_FLOAT32_C(  -150.91), SIMDE_FLOAT32_C(   701.26) },
      { SIMDE_FLOAT32_C(   860.00), SIMDE_FLOAT32_C(   968.00), SIMDE_FLOAT32_C(  -151.00), SIMDE_FLOAT32_C(   701.00) } },
    { { SIMDE_FLOAT32_C(   575.50), SIMDE_FLOAT32_C(  -179.50), SIMDE_FLOAT32_C(  -648.50), SIMDE_FLOAT32_C(  -126.48) },
      { SIMDE_FLOAT32_C(   575.00), SIMDE_FLOAT32_C(  -180.00), SIMDE_FLOAT32_C(  -649.00), SIMDE_FLOAT32_C(  -127.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_ROUND);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 1, 0, values);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_NEG_INF);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_round_ps_pinf (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -941.50), SIMDE_FLOAT32_C(  -625.50), SIMDE_FLOAT32_C(   506.50), SIMDE_FLOAT32_C(  -181.00) },
      { SIMDE_FLOAT32_C(  -941.00), SIMDE_FLOAT32_C(  -625.00), SIMDE_FLOAT32_C(   507.00), SIMDE_FLOAT32_C(  -181.00) } },
    { { SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   573.50), SIMDE_FLOAT32_C(   234.50), SIMDE_FLOAT32_C(  -404.50) },
      { SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   574.00), SIMDE_FLOAT32_C(   235.00), SIMDE_FLOAT32_C(  -404.00) } },
    { { SIMDE_FLOAT32_C(   433.50), SIMDE_FLOAT32_C(  -592.50), SIMDE_FLOAT32_C(  -199.50), SIMDE_FLOAT32_C(   615.00) },
      { SIMDE_FLOAT32_C(   434.00), SIMDE_FLOAT32_C(  -592.00), SIMDE_FLOAT32_C(  -199.00), SIMDE_FLOAT32_C(   615.00) } },
    { { SIMDE_FLOAT32_C(   -78.50), SIMDE_FLOAT32_C(    36.50), SIMDE_FLOAT32_C(    27.00), SIMDE_FLOAT32_C(   205.50) },
      { SIMDE_FLOAT32_C(   -78.00), SIMDE_FLOAT32_C(    37.00), SIMDE_FLOAT32_C(    27.00), SIMDE_FLOAT32_C(   206.00) } },
    { { SIMDE_FLOAT32_C(    34.50), SIMDE_FLOAT32_C(   775.75), SIMDE_FLOAT32_C(  -628.50), SIMDE_FLOAT32_C(  -753.50) },
      { SIMDE_FLOAT32_C(    35.00), SIMDE_FLOAT32_C(   776.00), SIMDE_FLOAT32_C(  -628.00), SIMDE_FLOAT32_C(  -753.00) } },
    { { SIMDE_FLOAT32_C(  -492.50), SIMDE_FLOAT32_C(  -172.50), SIMDE_FLOAT32_C(   519.50), SIMDE_FLOAT32_C(   718.50) },
      { SIMDE_FLOAT32_C(  -492.00), SIMDE_FLOAT32_C(  -172.00), SIMDE_FLOAT32_C(   520.00), SIMDE_FLOAT32_C(   719.00) } },
    { { SIMDE_FLOAT32_C(  -261.50), SIMDE_FLOAT32_C(  -189.00), SIMDE_FLOAT32_C(  -542.50), SIMDE_FLOAT32_C(   337.00) },
      { SIMDE_FLOAT32_C(  -261.00), SIMDE_FLOAT32_C(  -189.00), SIMDE_FLOAT32_C(  -542.00), SIMDE_FLOAT32_C(   337.00) } },
    { { SIMDE_FLOAT32_C(  -186.50), SIMDE_FLOAT32_C(   720.50), SIMDE_FLOAT32_C(    36.50), SIMDE_FLOAT32_C(   150.50) },
      { SIMDE_FLOAT32_C(  -186.00), SIMDE_FLOAT32_C(   721.00), SIMDE_FLOAT32_C(    37.00), SIMDE_FLOAT32_C(   151.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_ROUND);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 1, 0, values);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_POS_INF);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_round_ps_zero (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -732.50), SIMDE_FLOAT32_C(   255.50), SIMDE_FLOAT32_C(  -865.00), SIMDE_FLOAT32_C(   272.50) },
      { SIMDE_FLOAT32_C(  -732.00), SIMDE_FLOAT32_C(   255.00), SIMDE_FLOAT32_C(  -865.00), SIMDE_FLOAT32_C(   272.00) } },
    { { SIMDE_FLOAT32_C(   850.50), SIMDE_FLOAT32_C(   506.50), SIMDE_FLOAT32_C(   215.50), SIMDE_FLOAT32_C(  -237.54) },
      { SIMDE_FLOAT32_C(   850.00), SIMDE_FLOAT32_C(   506.00), SIMDE_FLOAT32_C(   215.00), SIMDE_FLOAT32_C(  -237.00) } },
    { { SIMDE_FLOAT32_C(   585.52), SIMDE_FLOAT32_C(   750.50), SIMDE_FLOAT32_C(   284.50), SIMDE_FLOAT32_C(   551.50) },
      { SIMDE_FLOAT32_C(   585.00), SIMDE_FLOAT32_C(   750.00), SIMDE_FLOAT32_C(   284.00), SIMDE_FLOAT32_C(   551.00) } },
    { { SIMDE_FLOAT32_C(  -191.50), SIMDE_FLOAT32_C(   -57.50), SIMDE_FLOAT32_C(  -785.50), SIMDE_FLOAT32_C(  -934.50) },
      { SIMDE_FLOAT32_C(  -191.00), SIMDE_FLOAT32_C(   -57.00), SIMDE_FLOAT32_C(  -785.00), SIMDE_FLOAT32_C(  -934.00) } },
    { { SIMDE_FLOAT32_C(   571.50), SIMDE_FLOAT32_C(  -212.50), SIMDE_FLOAT32_C(   548.50), SIMDE_FLOAT32_C(   205.50) },
      { SIMDE_FLOAT32_C(   571.00), SIMDE_FLOAT32_C(  -212.00), SIMDE_FLOAT32_C(   548.00), SIMDE_FLOAT32_C(   205.00) } },
    { { SIMDE_FLOAT32_C(   646.50), SIMDE_FLOAT32_C(  -543.50), SIMDE_FLOAT32_C(   793.50), SIMDE_FLOAT32_C(   926.50) },
      { SIMDE_FLOAT32_C(   646.00), SIMDE_FLOAT32_C(  -543.00), SIMDE_FLOAT32_C(   793.00), SIMDE_FLOAT32_C(   926.00) } },
    { { SIMDE_FLOAT32_C(  -551.50), SIMDE_FLOAT32_C(  -790.50), SIMDE_FLOAT32_C(   174.00), SIMDE_FLOAT32_C(   230.50) },
      { SIMDE_FLOAT32_C(  -551.00), SIMDE_FLOAT32_C(  -790.00), SIMDE_FLOAT32_C(   174.00), SIMDE_FLOAT32_C(   230.00) } },
    { { SIMDE_FLOAT32_C(   725.50), SIMDE_FLOAT32_C(   805.50), SIMDE_FLOAT32_C(  -665.00), SIMDE_FLOAT32_C(  -370.50) },
      { SIMDE_FLOAT32_C(   725.00), SIMDE_FLOAT32_C(   805.00), SIMDE_FLOAT32_C(  -665.00), SIMDE_FLOAT32_C(  -370.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_ZERO);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_ROUND);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 1, 0, values);
    simde__m128 r = simde_mm_round_ps(a, SIMDE_MM_FROUND_TO_ZERO);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_round_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    int rounding;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  201.21), SIMDE_FLOAT32_C( -972.67), SIMDE_FLOAT32_C( -880.37), SIMDE_FLOAT32_C(  126.05)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_ps(SIMDE_FLOAT32_C(  201.00), SIMDE_FLOAT32_C( -973.00), SIMDE_FLOAT32_C( -880.00), SIMDE_FLOAT32_C(  126.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -339.94), SIMDE_FLOAT32_C(   81.10), SIMDE_FLOAT32_C(  664.61), SIMDE_FLOAT32_C(  207.74)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -340.00), SIMDE_FLOAT32_C(   81.00), SIMDE_FLOAT32_C(  665.00), SIMDE_FLOAT32_C(  208.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -476.74), SIMDE_FLOAT32_C(  320.44), SIMDE_FLOAT32_C(  -89.85), SIMDE_FLOAT32_C( -531.60)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -477.00), SIMDE_FLOAT32_C(  320.00), SIMDE_FLOAT32_C(  -90.00), SIMDE_FLOAT32_C( -532.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -802.32), SIMDE_FLOAT32_C( -381.83), SIMDE_FLOAT32_C( -743.96), SIMDE_FLOAT32_C( -180.00)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -803.00), SIMDE_FLOAT32_C( -382.00), SIMDE_FLOAT32_C( -744.00), SIMDE_FLOAT32_C( -180.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  231.59), SIMDE_FLOAT32_C(  681.41), SIMDE_FLOAT32_C(  561.95), SIMDE_FLOAT32_C( -598.34)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C(  232.00), SIMDE_FLOAT32_C(  682.00), SIMDE_FLOAT32_C(  562.00), SIMDE_FLOAT32_C( -598.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -440.45), SIMDE_FLOAT32_C(  343.18), SIMDE_FLOAT32_C(   88.66), SIMDE_FLOAT32_C(  -98.54)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -440.00), SIMDE_FLOAT32_C(  344.00), SIMDE_FLOAT32_C(   89.00), SIMDE_FLOAT32_C(  -98.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -128.87), SIMDE_FLOAT32_C( -558.72), SIMDE_FLOAT32_C(  864.66), SIMDE_FLOAT32_C( -576.19)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -128.00), SIMDE_FLOAT32_C( -558.00), SIMDE_FLOAT32_C(  864.00), SIMDE_FLOAT32_C( -576.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  669.69), SIMDE_FLOAT32_C(  902.50), SIMDE_FLOAT32_C( -479.42), SIMDE_FLOAT32_C(  565.85)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_ps(SIMDE_FLOAT32_C(  669.00), SIMDE_FLOAT32_C(  902.00), SIMDE_FLOAT32_C( -479.00), SIMDE_FLOAT32_C(  565.00)) }
  };

  for (size_t i = 0 ; i < 2 ; i++) {
    simde__m128 r = simde_mm_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 2 ; i < 4 ; i++) {
    simde__m128 r = simde_mm_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 4 ; i < 6 ; i++) {
    simde__m128 r = simde_mm_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 6 ; i < 8 ; i++) {
    simde__m128 r = simde_mm_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_round_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    int rounding;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.59), SIMDE_FLOAT64_C(  -91.48)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -114.01), SIMDE_FLOAT64_C(  129.18)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.59), SIMDE_FLOAT64_C(  129.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  367.02), SIMDE_FLOAT64_C( -228.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -106.57), SIMDE_FLOAT64_C( -248.85)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  367.02), SIMDE_FLOAT64_C( -249.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  218.19), SIMDE_FLOAT64_C( -121.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -367.84), SIMDE_FLOAT64_C( -492.19)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  218.19), SIMDE_FLOAT64_C( -493.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  706.26), SIMDE_FLOAT64_C(  710.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -391.17), SIMDE_FLOAT64_C( -834.44)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  706.26), SIMDE_FLOAT64_C( -835.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -784.90), SIMDE_FLOAT64_C( -810.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -554.44), SIMDE_FLOAT64_C( -463.60)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -784.90), SIMDE_FLOAT64_C( -463.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -997.83), SIMDE_FLOAT64_C(    6.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.24), SIMDE_FLOAT64_C( -801.09)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -997.83), SIMDE_FLOAT64_C( -801.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -237.53), SIMDE_FLOAT64_C(  215.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -338.32), SIMDE_FLOAT64_C( -289.00)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -237.53), SIMDE_FLOAT64_C( -289.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  964.37), SIMDE_FLOAT64_C( -304.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  237.14), SIMDE_FLOAT64_C(  621.16)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  964.37), SIMDE_FLOAT64_C(  621.00)) }
  };

  for (size_t i = 0 ; i < 2 ; i++) {
    simde__m128d r = simde_mm_round_sd(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 2 ; i < 4 ; i++) {
    simde__m128d r = simde_mm_round_sd(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 4 ; i < 6 ; i++) {
    simde__m128d r = simde_mm_round_sd(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 6 ; i < 8 ; i++) {
    simde__m128d r = simde_mm_round_sd(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_round_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    int rounding;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -963.12), SIMDE_FLOAT32_C( -638.96), SIMDE_FLOAT32_C( -855.75), SIMDE_FLOAT32_C(  789.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  969.82), SIMDE_FLOAT32_C(   14.36), SIMDE_FLOAT32_C(   60.33), SIMDE_FLOAT32_C( -666.61)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -963.12), SIMDE_FLOAT32_C( -638.96), SIMDE_FLOAT32_C( -855.75), SIMDE_FLOAT32_C( -667.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -53.45), SIMDE_FLOAT32_C(  397.58), SIMDE_FLOAT32_C(  386.64), SIMDE_FLOAT32_C(  779.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  497.83), SIMDE_FLOAT32_C( -657.35), SIMDE_FLOAT32_C( -712.13), SIMDE_FLOAT32_C(  600.92)),
      SIMDE_MM_FROUND_TO_NEAREST_INT,
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -53.45), SIMDE_FLOAT32_C(  397.58), SIMDE_FLOAT32_C(  386.64), SIMDE_FLOAT32_C(  601.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -527.69), SIMDE_FLOAT32_C( -487.47), SIMDE_FLOAT32_C(  -52.23), SIMDE_FLOAT32_C(   18.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -912.96), SIMDE_FLOAT32_C(  897.40), SIMDE_FLOAT32_C( -873.59), SIMDE_FLOAT32_C(   52.18)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -527.69), SIMDE_FLOAT32_C( -487.47), SIMDE_FLOAT32_C(  -52.23), SIMDE_FLOAT32_C(   52.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  857.48), SIMDE_FLOAT32_C( -849.82), SIMDE_FLOAT32_C(  971.09), SIMDE_FLOAT32_C( -929.13)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  871.04), SIMDE_FLOAT32_C(  284.36), SIMDE_FLOAT32_C(  561.82), SIMDE_FLOAT32_C( -146.68)),
      SIMDE_MM_FROUND_TO_NEG_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C(  857.48), SIMDE_FLOAT32_C( -849.82), SIMDE_FLOAT32_C(  971.09), SIMDE_FLOAT32_C( -147.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -859.81), SIMDE_FLOAT32_C( -105.89), SIMDE_FLOAT32_C(  -18.60), SIMDE_FLOAT32_C( -214.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -360.47), SIMDE_FLOAT32_C(  472.18), SIMDE_FLOAT32_C(  960.99), SIMDE_FLOAT32_C( -396.53)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -859.81), SIMDE_FLOAT32_C( -105.89), SIMDE_FLOAT32_C(  -18.60), SIMDE_FLOAT32_C( -396.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -657.82), SIMDE_FLOAT32_C( -922.27), SIMDE_FLOAT32_C( -130.03), SIMDE_FLOAT32_C(  877.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -413.60), SIMDE_FLOAT32_C(  824.69), SIMDE_FLOAT32_C(  124.72), SIMDE_FLOAT32_C(  312.34)),
      SIMDE_MM_FROUND_TO_POS_INF,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -657.82), SIMDE_FLOAT32_C( -922.27), SIMDE_FLOAT32_C( -130.03), SIMDE_FLOAT32_C(  313.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -636.42), SIMDE_FLOAT32_C( -978.69), SIMDE_FLOAT32_C(  787.73), SIMDE_FLOAT32_C( -705.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -179.55), SIMDE_FLOAT32_C(  391.06), SIMDE_FLOAT32_C( -805.63), SIMDE_FLOAT32_C(  831.10)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_ps(SIMDE_FLOAT32_C( -636.42), SIMDE_FLOAT32_C( -978.69), SIMDE_FLOAT32_C(  787.73), SIMDE_FLOAT32_C(  831.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  529.08), SIMDE_FLOAT32_C( -665.00), SIMDE_FLOAT32_C(  786.13), SIMDE_FLOAT32_C(  843.11)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -295.93), SIMDE_FLOAT32_C( -148.90), SIMDE_FLOAT32_C(  483.10), SIMDE_FLOAT32_C( -790.07)),
      SIMDE_MM_FROUND_TO_ZERO,
      simde_mm_set_ps(SIMDE_FLOAT32_C(  529.08), SIMDE_FLOAT32_C( -665.00), SIMDE_FLOAT32_C(  786.13), SIMDE_FLOAT32_C( -790.00)) }
  };

  for (size_t i = 0 ; i < 2 ; i++) {
    simde__m128 r = simde_mm_round_ss(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 2 ; i < 4 ; i++) {
    simde__m128 r = simde_mm_round_ss(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 4 ; i < 6 ; i++) {
    simde__m128 r = simde_mm_round_ss(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }
  for (size_t i = 6 ; i < 8 ; i++) {
    simde__m128 r = simde_mm_round_ss(test_vec[i].a, test_vec[i].b, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_stream_load_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -547904967), INT32_C(-1362990942), INT32_C( 2066137598), INT32_C(-1778922116)),
      simde_mm_set_epi32(INT32_C( -547904967), INT32_C(-1362990942), INT32_C( 2066137598), INT32_C(-1778922116)) },
    { simde_mm_set_epi32(INT32_C(-2087163583), INT32_C( 2115433203), INT32_C(-1978815624), INT32_C( 1025228414)),
      simde_mm_set_epi32(INT32_C(-2087163583), INT32_C( 2115433203), INT32_C(-1978815624), INT32_C( 1025228414)) },
    { simde_mm_set_epi32(INT32_C(-1244490055), INT32_C( 1943548537), INT32_C(  589236062), INT32_C( -751161899)),
      simde_mm_set_epi32(INT32_C(-1244490055), INT32_C( 1943548537), INT32_C(  589236062), INT32_C( -751161899)) },
    { simde_mm_set_epi32(INT32_C(-1274215918), INT32_C(-1858225286), INT32_C( -472727069), INT32_C(  528679049)),
      simde_mm_set_epi32(INT32_C(-1274215918), INT32_C(-1858225286), INT32_C( -472727069), INT32_C(  528679049)) },
    { simde_mm_set_epi32(INT32_C(-1568552575), INT32_C(  411221897), INT32_C(-1334506552), INT32_C( 1554165859)),
      simde_mm_set_epi32(INT32_C(-1568552575), INT32_C(  411221897), INT32_C(-1334506552), INT32_C( 1554165859)) },
    { simde_mm_set_epi32(INT32_C( 1044144940), INT32_C(-1916851863), INT32_C( -589120926), INT32_C(  651795910)),
      simde_mm_set_epi32(INT32_C( 1044144940), INT32_C(-1916851863), INT32_C( -589120926), INT32_C(  651795910)) },
    { simde_mm_set_epi32(INT32_C(  -25575503), INT32_C(-1782121708), INT32_C(  751836326), INT32_C( 1005598033)),
      simde_mm_set_epi32(INT32_C(  -25575503), INT32_C(-1782121708), INT32_C(  751836326), INT32_C( 1005598033)) },
    { simde_mm_set_epi32(INT32_C(-1873195901), INT32_C( -450900536), INT32_C(  904584108), INT32_C(  251416593)),
      simde_mm_set_epi32(INT32_C(-1873195901), INT32_C( -450900536), INT32_C(  904584108), INT32_C(  251416593)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    #if defined(SIMDE_X86_SSE4_1_NATIVE) && defined(SIMDE_NATIVE_ALIASES_TESTING)
      simde__m128i r = simde_mm_stream_load_si128((__m128i*)&(test_vec[i].a));
    #else
      simde__m128i r = simde_mm_stream_load_si128(&(test_vec[i].a));
    #endif
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_test_all_ones(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    int r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(~UINT32_C(        0), UINT32_C(1993838502), UINT32_C(1216384299), UINT32_C(2484321284)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C( 708002161), ~UINT32_C(        0), UINT32_C(1641125312), UINT32_C(1784735378)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(3153393974), UINT32_C(3299961049), ~UINT32_C(        0), UINT32_C( 256198680)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(3219291087), UINT32_C(2995285646), UINT32_C(3353269087), ~UINT32_C(        0)),
      0 },
    { simde_x_mm_set_epu32(~UINT32_C(        0), UINT32_C(1590943288), UINT32_C(4263015539), UINT32_C(1245312939)),
      0 },
    { simde_x_mm_set_epu32(~UINT32_C(        0), ~UINT32_C(        0), UINT32_C( 453365074), UINT32_C(  94225678)),
      0 },
    { simde_x_mm_set_epu32(~UINT32_C(        0), ~UINT32_C(        0), ~UINT32_C(        0), UINT32_C(3354153743)),
      0 },
    { simde_x_mm_set_epu32(~UINT32_C(        0), ~UINT32_C(        0), ~UINT32_C(        0), ~UINT32_C(        0)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_test_all_ones(test_vec[i].a);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_test_all_zeros(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    int r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(1201894317), UINT32_C(2319231887), UINT32_C(1402528928), UINT32_C(3687328034)),
      simde_x_mm_set_epu32(UINT32_C(1967137742), UINT32_C(1472851836), UINT32_C(2181608867), UINT32_C(1889365185)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(2135448036), UINT32_C(1619848109), UINT32_C(2289839916), UINT32_C(3523984647)),
      simde_x_mm_set_epu32(UINT32_C(2046676780), UINT32_C(1214034345), UINT32_C( 106141409), UINT32_C(4219215983)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C( 657893603), UINT32_C(3270868697), UINT32_C(1314977284), UINT32_C(2544509951)),
      simde_x_mm_set_epu32(UINT32_C(2424312328), UINT32_C( 687898658), UINT32_C(2425031026), UINT32_C( 672223232)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(3537640743), UINT32_C( 372152333), UINT32_C(4133234814), UINT32_C( 396143667)),
      simde_x_mm_set_epu32(UINT32_C( 671105736), UINT32_C(3909093360), UINT32_C(   8553473), UINT32_C( 541283144)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(2182578541), UINT32_C(4064427053), UINT32_C(2602515508), UINT32_C(4049235221)),
      simde_x_mm_set_epu32(UINT32_C( 203975314), UINT32_C( 227393856), UINT32_C( 536871690), UINT32_C(  75760138)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C( 152354605), UINT32_C(2176274914), UINT32_C(3011079004), UINT32_C(3847789567)),
      simde_x_mm_set_epu32(UINT32_C(1562291537), UINT32_C( 354162251), UINT32_C(1134881489), UINT32_C(2956892685)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(2096532328), UINT32_C(1165454747), UINT32_C(3275710596), UINT32_C(1593733565)),
      simde_x_mm_set_epu32(UINT32_C(1988174269), UINT32_C(1339821769), UINT32_C(1810810088), UINT32_C( 840755548)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(3588833624), UINT32_C( 610042197), UINT32_C(1310204993), UINT32_C(1509811379)),
      simde_x_mm_set_epu32(UINT32_C( 571869223), UINT32_C(1235317762), UINT32_C(  29362474), UINT32_C( 570561100)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_test_all_zeros(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_test_mix_ones_zeros(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    int r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C( 817555810), UINT32_C(3902491734), UINT32_C(3977937498), UINT32_C(2772762421)),
      simde_x_mm_set_epu32(UINT32_C(1924103348), UINT32_C(1357836992), UINT32_C(4064253767), UINT32_C(3196943489)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(1969146297), UINT32_C(3716202658), UINT32_C( 759743671), UINT32_C(2926294225)),
      simde_x_mm_set_epu32(UINT32_C(2325820998), UINT32_C( 578764637), UINT32_C(3535223624), UINT32_C(1368673070)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(3794246328), UINT32_C(2295817460), UINT32_C(2963593754), UINT32_C(2249033119)),
      simde_x_mm_set_epu32(UINT32_C(1810964868), UINT32_C(3773017844), UINT32_C(1790481610), UINT32_C(4104297207)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(3721359930), UINT32_C(2092677361), UINT32_C(2672746089), UINT32_C(2784499405)),
      simde_x_mm_set_epu32(UINT32_C( 573607365), UINT32_C(2202289934), UINT32_C(1622221206), UINT32_C(1510467890)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(1688049548), UINT32_C( 227731129), UINT32_C(2187006143), UINT32_C(2191704962)),
      simde_x_mm_set_epu32(UINT32_C(3739754335), UINT32_C(1136006144), UINT32_C(2036111421), UINT32_C(3950298731)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(2420605154), UINT32_C(1034465439), UINT32_C( 270210360), UINT32_C(1245331438)),
      simde_x_mm_set_epu32(UINT32_C(1874362141), UINT32_C(3260501856), UINT32_C(4024756935), UINT32_C(3049635857)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(2202152506), UINT32_C( 285372976), UINT32_C(4113851867), UINT32_C(1775650196)),
      simde_x_mm_set_epu32(UINT32_C(2951443467), UINT32_C(1206063205), UINT32_C(2278810499), UINT32_C(1561806132)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(2386514979), UINT32_C(2103226597), UINT32_C( 427456035), UINT32_C(2075844151)),
      simde_x_mm_set_epu32(UINT32_C(2028307641), UINT32_C(3795980391), UINT32_C(1321164258), UINT32_C(1543009672)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_test_mix_ones_zeros(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_testc_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    int r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(2830619595), UINT32_C(3721899845), UINT32_C(1506484780), UINT32_C(3754634237)),
      simde_x_mm_set_epu32(UINT32_C( 135762121), UINT32_C(1485021188), UINT32_C(     66080), UINT32_C(1279789969)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C( 193385482), UINT32_C(2729396552), UINT32_C(3295558360), UINT32_C(1810466520)),
      simde_x_mm_set_epu32(UINT32_C(2126857072), UINT32_C(2130569152), UINT32_C( 589776977), UINT32_C(3538187411)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C( 786883487), UINT32_C(1935834902), UINT32_C(1176572533), UINT32_C(2648243675)),
      simde_x_mm_set_epu32(UINT32_C( 782262300), UINT32_C(1617050388), UINT32_C(  33620084), UINT32_C( 294672713)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(1041307471), UINT32_C(  45744950), UINT32_C(1982345789), UINT32_C(3152632048)),
      simde_x_mm_set_epu32(UINT32_C(1387031193), UINT32_C( 524221074), UINT32_C(2963552394), UINT32_C(  26167124)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(4096311220), UINT32_C(1013684968), UINT32_C(3348640547), UINT32_C(2194828263)),
      simde_x_mm_set_epu32(UINT32_C(3288368404), UINT32_C( 873007168), UINT32_C( 127402785), UINT32_C(  43000416)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(3620270306), UINT32_C( 102683939), UINT32_C(1921801133), UINT32_C(4285709000)),
      simde_x_mm_set_epu32(UINT32_C(2218828002), UINT32_C(  67671297), UINT32_C(1384665613), UINT32_C(2030217920)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C( 948424904), UINT32_C(1962159425), UINT32_C(1599818052), UINT32_C( 324039513)),
      simde_x_mm_set_epu32(UINT32_C( 671486144), UINT32_C(1888759104), UINT32_C(1191182592), UINT32_C( 319836488)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(2926329185), UINT32_C(3270382597), UINT32_C( 628918622), UINT32_C(3097066353)),
      simde_x_mm_set_epu32(UINT32_C(2282240352), UINT32_C(3265794053), UINT32_C(  71305480), UINT32_C( 948529457)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testc_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_testnzc_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    int r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(1875425415), UINT32_C(3970564046), UINT32_C(3151364481), UINT32_C(3646821095)),
      simde_x_mm_set_epu32(UINT32_C( 939391786), UINT32_C(1418582693), UINT32_C(3583579146), UINT32_C(2978542122)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(1948733162), UINT32_C(3713693944), UINT32_C(2694213253), UINT32_C(1663204587)),
      simde_x_mm_set_epu32(UINT32_C(1140998794), UINT32_C(1141393520), UINT32_C(2685534720), UINT32_C(1124213826)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(1383702507), UINT32_C(4170492791), UINT32_C(  81283149), UINT32_C(2572004949)),
      simde_x_mm_set_epu32(UINT32_C(1383112482), UINT32_C(   1049365), UINT32_C(  67110920), UINT32_C(     33301)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C( 122650173), UINT32_C(3420397620), UINT32_C(2510350310), UINT32_C(1202770589)),
      simde_x_mm_set_epu32(UINT32_C(3675302012), UINT32_C( 291962269), UINT32_C(1109447557), UINT32_C( 739260950)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(1579102285), UINT32_C( 270245457), UINT32_C(1078977019), UINT32_C(2085912657)),
      simde_x_mm_set_epu32(UINT32_C(1242112064), UINT32_C(   1606145), UINT32_C(    688393), UINT32_C( 402685968)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(3394408789), UINT32_C(2660724232), UINT32_C(2317277326), UINT32_C(3204989336)),
      simde_x_mm_set_epu32(UINT32_C(1819319362), UINT32_C( 329857933), UINT32_C(3391127410), UINT32_C( 743662239)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(4125624985), UINT32_C(   2864942), UINT32_C( 875515634), UINT32_C(2091317004)),
      simde_x_mm_set_epu32(UINT32_C( 617089160), UINT32_C(    112418), UINT32_C( 606079728), UINT32_C(1881276672)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(2421997128), UINT32_C(3685823722), UINT32_C(2588454762), UINT32_C(2067412407)),
      simde_x_mm_set_epu32(UINT32_C(3926740437), UINT32_C( 589344338), UINT32_C(2958265721), UINT32_C(1121386306)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testnzc_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_testz_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i b;
    int r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(3990889899), UINT32_C(4230789057), UINT32_C(3808461042), UINT32_C(3371427410)),
      simde_x_mm_set_epu32(UINT32_C(    331792), UINT32_C(  63127558), UINT32_C( 483990789), UINT32_C(    530828)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(3603350831), UINT32_C(2431793515), UINT32_C(1875486201), UINT32_C(3530533257)),
      simde_x_mm_set_epu32(UINT32_C(  19933776), UINT32_C(1174733824), UINT32_C(2147880964), UINT32_C(   8393234)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(3124097223), UINT32_C(4066616999), UINT32_C(2076362673), UINT32_C( 124456258)),
      simde_x_mm_set_epu32(UINT32_C(1170213928), UINT32_C(  84416520), UINT32_C(2150893634), UINT32_C(3499413545)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(4156796004), UINT32_C(1994002854), UINT32_C(4034407880), UINT32_C( 600089084)),
      simde_x_mm_set_epu32(UINT32_C(2971079954), UINT32_C(3997808651), UINT32_C( 222740062), UINT32_C(3989806580)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(4130552440), UINT32_C( 812777701), UINT32_C(2016424386), UINT32_C( 886379222)),
      simde_x_mm_set_epu32(UINT32_C(  70177905), UINT32_C(2046022589), UINT32_C( 670901459), UINT32_C(2978865170)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C( 192532312), UINT32_C(1467133872), UINT32_C(1075139299), UINT32_C( 191167596)),
      simde_x_mm_set_epu32(UINT32_C(1026534956), UINT32_C(4130843248), UINT32_C(3619306010), UINT32_C(3598027302)),
      0 },
    { simde_x_mm_set_epu32(UINT32_C(2410417876), UINT32_C(  74289906), UINT32_C(4031840239), UINT32_C(2837881625)),
      simde_x_mm_set_epu32(UINT32_C( 542327083), UINT32_C( 680656909), UINT32_C( 184549392), UINT32_C(1421938882)),
      1 },
    { simde_x_mm_set_epu32(UINT32_C(3782150825), UINT32_C(3325635017), UINT32_C(1617333560), UINT32_C(3634437083)),
      simde_x_mm_set_epu32(UINT32_C( 167825730), UINT32_C( 294047748), UINT32_C( 126906945), UINT32_C(  17884164)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testz_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i(r, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_blend_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_blend_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_blend_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_blendv_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_blendv_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_blendv_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_blendv_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_blendv_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_blendv_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ceil_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ceil_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ceil_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ceil_ss)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi8_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi8_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi8_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepu8_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepu8_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepu8_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi16_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi16_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepu16_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepu16_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi32_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepu32_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dp_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dp_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_extract_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_extract_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_extract_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_extract_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_floor_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_floor_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_floor_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_floor_ss)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_insert_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_insert_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_insert_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_insert_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_max_epu32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_min_epu32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_minpos_epu16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mpsadbw_epu8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mul_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mullo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_mullo_epu32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_packus_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_ss)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_ps_nearest)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_ps_ninf)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_ps_pinf)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_round_ps_zero)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_stream_load_si128)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_test_all_ones)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_test_all_zeros)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_test_mix_ones_zeros)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_testc_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_testnzc_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_testz_si128)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
