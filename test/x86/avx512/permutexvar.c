/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Christopher Moore <moore@free.fr>
 */

#define SIMDE_TEST_X86_AVX512_INSN permutexvar

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/permutexvar.h>

static int
test_simde_mm_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t idx[8];
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  6502), -INT16_C( 30001), -INT16_C( 24228),  INT16_C(  3581), -INT16_C(   616), -INT16_C(  1803),  INT16_C(  7078),  INT16_C( 16289) },
      { -INT16_C(  9505),  INT16_C(  1150),  INT16_C( 11629), -INT16_C(  6820),  INT16_C(  5125), -INT16_C(   892),  INT16_C( 21083), -INT16_C( 15937) },
      {  INT16_C( 21083), -INT16_C( 15937),  INT16_C(  5125), -INT16_C(   892), -INT16_C(  9505), -INT16_C(   892),  INT16_C( 21083),  INT16_C(  1150) } },
    { { -INT16_C( 29077), -INT16_C( 14517),  INT16_C( 18480), -INT16_C( 14124), -INT16_C( 14011), -INT16_C(  5184),  INT16_C( 25060), -INT16_C( 15574) },
      { -INT16_C( 22213), -INT16_C( 22328),  INT16_C(  9430), -INT16_C(  9075),  INT16_C(  4665), -INT16_C( 27432), -INT16_C( 26524), -INT16_C( 12459) },
      { -INT16_C(  9075), -INT16_C(  9075), -INT16_C( 22213),  INT16_C(  4665), -INT16_C( 27432), -INT16_C( 22213),  INT16_C(  4665),  INT16_C(  9430) } },
    { { -INT16_C( 24538),  INT16_C( 22166),  INT16_C( 27368),  INT16_C( 11550), -INT16_C(  8653),  INT16_C(  5912),  INT16_C( 17215),  INT16_C( 31450) },
      { -INT16_C( 23828), -INT16_C( 15838), -INT16_C( 20281),  INT16_C(   158),  INT16_C( 30658),  INT16_C(  9876), -INT16_C(  5873),  INT16_C( 13813) },
      { -INT16_C(  5873), -INT16_C(  5873), -INT16_C( 23828), -INT16_C(  5873),  INT16_C(   158), -INT16_C( 23828),  INT16_C( 13813), -INT16_C( 20281) } },
    { { -INT16_C( 29815),  INT16_C( 29068), -INT16_C( 21771),  INT16_C( 10398), -INT16_C( 18807), -INT16_C( 14273),  INT16_C(  6649), -INT16_C(  6845) },
      {  INT16_C( 26044), -INT16_C( 31832),  INT16_C( 17941), -INT16_C( 10365),  INT16_C(  6077), -INT16_C( 13059), -INT16_C(  3584), -INT16_C( 30462) },
      { -INT16_C( 31832),  INT16_C(  6077), -INT16_C( 13059), -INT16_C(  3584), -INT16_C( 31832), -INT16_C( 30462), -INT16_C( 31832), -INT16_C( 10365) } },
    { { -INT16_C( 29059),  INT16_C( 29434), -INT16_C( 26568), -INT16_C( 15974), -INT16_C(  9906),  INT16_C( 18570), -INT16_C( 12813), -INT16_C( 20691) },
      { -INT16_C( 10958),  INT16_C( 18482), -INT16_C( 19172), -INT16_C(  9953),  INT16_C(  7628), -INT16_C( 13146), -INT16_C( 22513), -INT16_C( 29355) },
      { -INT16_C( 13146), -INT16_C( 19172), -INT16_C( 10958), -INT16_C( 19172), -INT16_C( 22513), -INT16_C( 19172), -INT16_C(  9953), -INT16_C( 13146) } },
    { {  INT16_C( 20278),  INT16_C( 28415), -INT16_C( 25881),  INT16_C( 13616), -INT16_C( 17805),  INT16_C( 26237), -INT16_C( 21625), -INT16_C( 18155) },
      {  INT16_C( 18304), -INT16_C( 25599),  INT16_C(  8700), -INT16_C( 14218),  INT16_C(  7230),  INT16_C( 19860), -INT16_C(  5692), -INT16_C(  1318) },
      { -INT16_C(  5692), -INT16_C(  1318), -INT16_C(  1318),  INT16_C( 18304), -INT16_C( 14218),  INT16_C( 19860), -INT16_C(  1318),  INT16_C( 19860) } },
    { { -INT16_C(  9672),  INT16_C(  8040), -INT16_C( 26508), -INT16_C(  6315), -INT16_C( 11694), -INT16_C(  9906),  INT16_C( 25469), -INT16_C(   365) },
      { -INT16_C( 27477), -INT16_C( 22630),  INT16_C(  4277), -INT16_C(  3216),  INT16_C(  1068), -INT16_C(  4031),  INT16_C(  7150),  INT16_C(  9962) },
      { -INT16_C( 27477), -INT16_C( 27477),  INT16_C(  1068), -INT16_C(  4031),  INT16_C(  4277),  INT16_C(  7150), -INT16_C(  4031), -INT16_C(  3216) } },
    { {  INT16_C( 21493),  INT16_C( 26950), -INT16_C( 25621),  INT16_C( 15953), -INT16_C( 24723), -INT16_C(  5353), -INT16_C( 22014), -INT16_C( 21015) },
      { -INT16_C( 31937), -INT16_C(  2987), -INT16_C( 14956), -INT16_C( 16152),  INT16_C( 10697), -INT16_C( 18511), -INT16_C( 25788),  INT16_C( 15070) },
      { -INT16_C( 18511), -INT16_C( 25788), -INT16_C( 16152), -INT16_C(  2987), -INT16_C( 18511),  INT16_C( 15070), -INT16_C( 14956), -INT16_C(  2987) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_permutexvar_epi16(idx, a);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_permutexvar_epi16(idx, a);

    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t idx[8];
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  9454), -INT16_C(  9565), -INT16_C(  2881),  INT16_C( 11288),  INT16_C( 12179), -INT16_C( 27113),  INT16_C(   218),  INT16_C(  6467) },
      UINT8_C(132),
      {  INT16_C(  3480),  INT16_C( 23832), -INT16_C(  9995),  INT16_C(  7719), -INT16_C(  8567),  INT16_C(  9571), -INT16_C( 25156), -INT16_C(  8173) },
      { -INT16_C(  4800),  INT16_C( 13727), -INT16_C( 13307),  INT16_C( 13768),  INT16_C( 24291), -INT16_C(  7153),  INT16_C( 10402),  INT16_C( 14952) },
      {  INT16_C(  9454), -INT16_C(  9565), -INT16_C(  7153),  INT16_C( 11288),  INT16_C( 12179), -INT16_C( 27113),  INT16_C(   218),  INT16_C( 13768) } },
    { { -INT16_C( 32715),  INT16_C( 11160), -INT16_C( 16552), -INT16_C(  7607), -INT16_C( 21347),  INT16_C( 23047),  INT16_C(  6729), -INT16_C( 30150) },
      UINT8_C(  8),
      { -INT16_C( 16422), -INT16_C( 23027),  INT16_C( 17031), -INT16_C(  6519),  INT16_C( 27985),  INT16_C( 31112), -INT16_C( 15659),  INT16_C( 21935) },
      { -INT16_C(  9638),  INT16_C(  6574), -INT16_C( 28637), -INT16_C( 12105),  INT16_C(  4503), -INT16_C( 20199), -INT16_C( 23733),  INT16_C(  9657) },
      { -INT16_C( 32715),  INT16_C( 11160), -INT16_C( 16552),  INT16_C(  6574), -INT16_C( 21347),  INT16_C( 23047),  INT16_C(  6729), -INT16_C( 30150) } },
    { { -INT16_C( 14494), -INT16_C(  5429),  INT16_C( 21769),  INT16_C( 23504),  INT16_C( 22722), -INT16_C( 26412), -INT16_C( 31974),  INT16_C( 30189) },
      UINT8_C( 93),
      { -INT16_C( 29029),  INT16_C( 11137),  INT16_C( 20805),  INT16_C( 22210),  INT16_C( 29802),  INT16_C(  3746), -INT16_C( 14547), -INT16_C(  2960) },
      {  INT16_C( 23187), -INT16_C(  5890),  INT16_C( 22826), -INT16_C( 32086),  INT16_C( 16941), -INT16_C( 20067),  INT16_C(  4656), -INT16_C( 13554) },
      { -INT16_C( 32086), -INT16_C(  5429), -INT16_C( 20067),  INT16_C( 22826),  INT16_C( 22826), -INT16_C( 26412), -INT16_C( 20067),  INT16_C( 30189) } },
    { { -INT16_C( 28768), -INT16_C(  6409), -INT16_C( 17952),  INT16_C( 19260), -INT16_C(  8659),  INT16_C( 23385), -INT16_C( 13914),  INT16_C( 14671) },
      UINT8_C( 36),
      {  INT16_C(  8525), -INT16_C( 22962), -INT16_C( 11829),  INT16_C(  3796), -INT16_C( 31378), -INT16_C( 32706),  INT16_C(  2451),  INT16_C(  8992) },
      {  INT16_C(  1536), -INT16_C( 17917),  INT16_C( 20035),  INT16_C(  8679),  INT16_C( 17063),  INT16_C( 29127),  INT16_C(   146), -INT16_C(  8299) },
      { -INT16_C( 28768), -INT16_C(  6409),  INT16_C(  8679),  INT16_C( 19260), -INT16_C(  8659),  INT16_C(   146), -INT16_C( 13914),  INT16_C( 14671) } },
    { { -INT16_C(  7391), -INT16_C(  4730),  INT16_C( 23220),  INT16_C(  8955),  INT16_C( 14815),  INT16_C( 29346), -INT16_C( 15550),  INT16_C( 17301) },
      UINT8_C(201),
      { -INT16_C(   615), -INT16_C(  6388),  INT16_C( 12004),  INT16_C( 10127),  INT16_C(   245), -INT16_C(  2375), -INT16_C( 26475),  INT16_C( 30743) },
      {  INT16_C(  1054),  INT16_C( 30765),  INT16_C( 20479),  INT16_C( 14423), -INT16_C( 13582), -INT16_C( 19077), -INT16_C( 16801), -INT16_C(  1922) },
      {  INT16_C( 30765), -INT16_C(  4730),  INT16_C( 23220), -INT16_C(  1922),  INT16_C( 14815),  INT16_C( 29346), -INT16_C( 19077), -INT16_C(  1922) } },
    { { -INT16_C( 29765), -INT16_C( 24608),  INT16_C( 28601), -INT16_C( 20794),  INT16_C( 32623),  INT16_C(  1188), -INT16_C( 17384),  INT16_C( 13948) },
      UINT8_C(192),
      { -INT16_C( 20567), -INT16_C(  1600), -INT16_C(  2042), -INT16_C( 12053), -INT16_C( 24461),  INT16_C( 12592),  INT16_C( 10270), -INT16_C( 22036) },
      { -INT16_C( 29688),  INT16_C( 30562),  INT16_C(  4434), -INT16_C( 11546), -INT16_C(  5451),  INT16_C( 29162),  INT16_C(  8295),  INT16_C(  4146) },
      { -INT16_C( 29765), -INT16_C( 24608),  INT16_C( 28601), -INT16_C( 20794),  INT16_C( 32623),  INT16_C(  1188),  INT16_C(  8295), -INT16_C(  5451) } },
    { { -INT16_C(  3377), -INT16_C( 10743), -INT16_C(  2838),  INT16_C( 24230), -INT16_C( 10604), -INT16_C( 19569),  INT16_C( 31999),  INT16_C(  1884) },
      UINT8_C(  8),
      {  INT16_C( 32703), -INT16_C( 12198),  INT16_C( 11365),  INT16_C( 20613), -INT16_C(  2282),  INT16_C( 14263), -INT16_C( 14551),  INT16_C(  6918) },
      { -INT16_C(  9007), -INT16_C( 15099),  INT16_C( 25475),  INT16_C( 22874),  INT16_C(  3571),  INT16_C( 28504),  INT16_C( 24681),  INT16_C( 10359) },
      { -INT16_C(  3377), -INT16_C( 10743), -INT16_C(  2838),  INT16_C( 28504), -INT16_C( 10604), -INT16_C( 19569),  INT16_C( 31999),  INT16_C(  1884) } },
    { { -INT16_C( 11809),  INT16_C( 17656),  INT16_C( 32510),  INT16_C(  5268),  INT16_C( 19317), -INT16_C( 25013),  INT16_C( 21011), -INT16_C(  6983) },
      UINT8_C( 46),
      { -INT16_C( 22082),  INT16_C(  8881),  INT16_C(  2819),  INT16_C(  4117), -INT16_C( 31645), -INT16_C( 15494), -INT16_C( 23813), -INT16_C( 13150) },
      { -INT16_C(  6245),  INT16_C(  6602), -INT16_C(  8325), -INT16_C( 14450),  INT16_C( 11306),  INT16_C( 31962), -INT16_C( 16667), -INT16_C( 23637) },
      { -INT16_C( 11809),  INT16_C(  6602), -INT16_C( 14450),  INT16_C( 31962),  INT16_C( 19317), -INT16_C(  8325),  INT16_C( 21011), -INT16_C(  6983) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_mask_permutexvar_epi16(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_permutexvar_epi16(src, k, idx, a);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t idx[8];
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(103),
      { -INT16_C( 15012),  INT16_C( 26475),  INT16_C( 31706),  INT16_C( 24267), -INT16_C( 28939), -INT16_C( 26535),  INT16_C(  9777),  INT16_C(  6195) },
      {  INT16_C( 19696), -INT16_C( 12397),  INT16_C( 23258),  INT16_C(  1786),  INT16_C( 30260), -INT16_C(  3349), -INT16_C( 29151),  INT16_C( 32346) },
      {  INT16_C( 30260),  INT16_C(  1786),  INT16_C( 23258),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12397), -INT16_C( 12397),  INT16_C(     0) } },
    { UINT8_C( 84),
      { -INT16_C(  6715),  INT16_C( 16430), -INT16_C( 29264),  INT16_C( 16182), -INT16_C( 12570),  INT16_C(  3184), -INT16_C( 30719),  INT16_C( 19965) },
      { -INT16_C( 13285),  INT16_C( 30247),  INT16_C( 11718),  INT16_C( 15786), -INT16_C( 25320), -INT16_C( 22946), -INT16_C(  8969), -INT16_C( 17158) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 13285),  INT16_C(     0), -INT16_C(  8969),  INT16_C(     0),  INT16_C( 30247),  INT16_C(     0) } },
    { UINT8_C(194),
      { -INT16_C(   983), -INT16_C( 18830), -INT16_C( 20174),  INT16_C(   156), -INT16_C( 22239), -INT16_C( 22271),  INT16_C( 20134),  INT16_C( 29381) },
      {  INT16_C( 15221), -INT16_C( 24007),  INT16_C( 30437), -INT16_C( 32070),  INT16_C( 25044), -INT16_C( 20103),  INT16_C( 13659), -INT16_C( 31629) },
      {  INT16_C(     0),  INT16_C( 30437),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13659), -INT16_C( 20103) } },
    { UINT8_C( 50),
      {  INT16_C( 15077), -INT16_C( 26780),  INT16_C( 26071), -INT16_C( 32584),  INT16_C( 25190), -INT16_C( 19162), -INT16_C( 26585),  INT16_C( 25130) },
      { -INT16_C( 12847),  INT16_C( 18247), -INT16_C( 13689), -INT16_C(  6116), -INT16_C( 12989),  INT16_C( 31044), -INT16_C( 14272),  INT16_C(  9643) },
      {  INT16_C(     0), -INT16_C( 12989),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14272), -INT16_C( 14272),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(  3),
      { -INT16_C( 17393),  INT16_C( 29914),  INT16_C( 23157), -INT16_C( 10277), -INT16_C( 28544),  INT16_C(  6398),  INT16_C( 24762), -INT16_C( 30742) },
      {  INT16_C( 12711),  INT16_C( 28943), -INT16_C(  2227),  INT16_C(  6837),  INT16_C( 11835),  INT16_C(  1114), -INT16_C( 32551), -INT16_C(  6137) },
      { -INT16_C(  6137), -INT16_C(  2227),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C( 60),
      {  INT16_C( 24033),  INT16_C( 15281), -INT16_C( 30664), -INT16_C( 14149), -INT16_C( 11386), -INT16_C(  6526),  INT16_C(  2749), -INT16_C(  4210) },
      { -INT16_C(   231),  INT16_C(  4156),  INT16_C( 22452), -INT16_C(  7604),  INT16_C( 20657),  INT16_C( 12731), -INT16_C( 23465),  INT16_C( 14446) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(   231), -INT16_C(  7604), -INT16_C( 23465),  INT16_C( 22452),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(  1),
      {  INT16_C( 29471), -INT16_C( 22471),  INT16_C(   302),  INT16_C(   302),  INT16_C(  5507), -INT16_C( 29249), -INT16_C( 20829), -INT16_C( 23898) },
      { -INT16_C( 18454),  INT16_C( 16727),  INT16_C( 14595),  INT16_C( 21491),  INT16_C(  9461), -INT16_C( 26198), -INT16_C(  7534), -INT16_C( 19814) },
      { -INT16_C( 19814),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C( 85),
      {  INT16_C( 23251), -INT16_C( 11133), -INT16_C( 31608), -INT16_C( 25257), -INT16_C(  6845), -INT16_C(  3776), -INT16_C(  7285),  INT16_C( 17116) },
      {  INT16_C(  7482),  INT16_C( 29509), -INT16_C( 26608),  INT16_C( 13672),  INT16_C(   322),  INT16_C(  9415),  INT16_C( 31131),  INT16_C( 28281) },
      {  INT16_C( 13672),  INT16_C(     0),  INT16_C(  7482),  INT16_C(     0),  INT16_C( 13672),  INT16_C(     0),  INT16_C( 13672),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_permutexvar_epi16(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_permutexvar_epi16(k, idx, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t idx[16];
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  89),  INT8_C( 112),  INT8_C( 118),  INT8_C( 112),  INT8_C(  27), -INT8_C(  75), -INT8_C(  48), -INT8_C( 116),
         INT8_C(  48), -INT8_C( 117), -INT8_C( 112), -INT8_C(  23), -INT8_C( 119), -INT8_C(  91),  INT8_C(  15),  INT8_C(  59) },
      { -INT8_C(  71),  INT8_C( 114),  INT8_C( 108),  INT8_C(  13),  INT8_C(  18), -INT8_C(   6),  INT8_C( 114),  INT8_C( 113),
        -INT8_C(  41), -INT8_C(   3),  INT8_C(  44),  INT8_C(  29),  INT8_C(  73), -INT8_C( 122),  INT8_C(  24), -INT8_C(  15) },
      {  INT8_C( 113), -INT8_C(  71),  INT8_C( 114), -INT8_C(  71),  INT8_C(  29), -INT8_C(   6), -INT8_C(  71),  INT8_C(  73),
        -INT8_C(  71),  INT8_C(  29), -INT8_C(  71), -INT8_C(   3), -INT8_C(   3), -INT8_C(   6), -INT8_C(  15),  INT8_C(  29) } },
    { { -INT8_C(  10), -INT8_C( 114),  INT8_C(  97),  INT8_C(  18),  INT8_C(  67),  INT8_C(  49), -INT8_C(  98),  INT8_C( 115),
        -INT8_C(  67),  INT8_C(  47),  INT8_C(  92),  INT8_C(  70), -INT8_C(  44),  INT8_C( 108), -INT8_C( 127), -INT8_C( 114) },
      { -INT8_C(  34), -INT8_C(  19), -INT8_C( 101), -INT8_C(  15), -INT8_C(  24),  INT8_C(  13),  INT8_C(  98), -INT8_C(  65),
         INT8_C(  10), -INT8_C( 113), -INT8_C(  36),  INT8_C(  83),  INT8_C(  21), -INT8_C(  12),  INT8_C(  68),  INT8_C(  11) },
      {  INT8_C(  98),  INT8_C(  68), -INT8_C(  19), -INT8_C( 101), -INT8_C(  15), -INT8_C(  19),  INT8_C(  68), -INT8_C(  15),
        -INT8_C(  12),  INT8_C(  11),  INT8_C(  21),  INT8_C(  98), -INT8_C(  24),  INT8_C(  21), -INT8_C(  19),  INT8_C(  68) } },
    { { -INT8_C( 126), -INT8_C(  91),  INT8_C(  29), -INT8_C(  59), -INT8_C(  41), -INT8_C(  68),  INT8_C(  56), -INT8_C( 108),
        -INT8_C(  21), -INT8_C( 107), -INT8_C(  38), -INT8_C(  65),  INT8_C(   1),  INT8_C(  92),  INT8_C(  77), -INT8_C(  33) },
      {  INT8_C(  73), -INT8_C(  24), -INT8_C(  48),  INT8_C(  49), -INT8_C(  11),  INT8_C(  51), -INT8_C(  16), -INT8_C(   1),
        -INT8_C(  62), -INT8_C(  51),  INT8_C(  83), -INT8_C(  41), -INT8_C(  63), -INT8_C( 105), -INT8_C(  30),  INT8_C(  68) },
      { -INT8_C(  48),  INT8_C(  51), -INT8_C( 105),  INT8_C(  51), -INT8_C(   1), -INT8_C(  63), -INT8_C(  62), -INT8_C(  11),
        -INT8_C(  41),  INT8_C(  51),  INT8_C(  83),  INT8_C(  68), -INT8_C(  24), -INT8_C(  63), -INT8_C( 105),  INT8_C(  68) } },
    { {  INT8_C(  61),  INT8_C(   0),  INT8_C(   9),  INT8_C(  20), -INT8_C(  68),  INT8_C(  66), -INT8_C(  88), -INT8_C(  89),
        -INT8_C(  41), -INT8_C( 126),  INT8_C( 102), -INT8_C(  40), -INT8_C(  34), -INT8_C(  76), -INT8_C(  73),  INT8_C(  40) },
      { -INT8_C( 100), -INT8_C( 120),  INT8_C(  89), -INT8_C( 110), -INT8_C(  69),  INT8_C(  74), -INT8_C( 111),  INT8_C( 125),
         INT8_C(  23), -INT8_C(  28),  INT8_C(  84), -INT8_C(  40),  INT8_C( 124),  INT8_C(  54),  INT8_C(  28), -INT8_C(  71) },
      {  INT8_C(  54), -INT8_C( 100), -INT8_C(  28), -INT8_C(  69),  INT8_C( 124),  INT8_C(  89),  INT8_C(  23),  INT8_C( 125),
         INT8_C( 125),  INT8_C(  89), -INT8_C( 111),  INT8_C(  23),  INT8_C(  28), -INT8_C(  69),  INT8_C( 125),  INT8_C(  23) } },
    { {  INT8_C(  54),  INT8_C(  38), -INT8_C(  51), -INT8_C(  14),  INT8_C( 104),  INT8_C( 117), -INT8_C( 103),  INT8_C(  63),
        -INT8_C(   9),  INT8_C(   0),  INT8_C(  23), -INT8_C(  42), -INT8_C(  76), -INT8_C(  50), -INT8_C(   2),  INT8_C(  80) },
      {  INT8_C(  86),  INT8_C(  87), -INT8_C(  30),  INT8_C(  17), -INT8_C(  95),  INT8_C( 116), -INT8_C( 114), -INT8_C(  72),
         INT8_C(  88), -INT8_C(  30), -INT8_C( 111), -INT8_C(  44),  INT8_C(  25), -INT8_C(  83), -INT8_C( 115),  INT8_C(  79) },
      { -INT8_C( 114), -INT8_C( 114), -INT8_C(  83), -INT8_C(  30),  INT8_C(  88),  INT8_C( 116), -INT8_C(  30),  INT8_C(  79),
        -INT8_C(  72),  INT8_C(  86), -INT8_C(  72), -INT8_C( 114), -INT8_C(  95), -INT8_C( 115), -INT8_C( 115),  INT8_C(  86) } },
    { { -INT8_C(  45),  INT8_C(  90),  INT8_C(  66),  INT8_C(  59), -INT8_C(  49), -INT8_C(  37),  INT8_C( 122), -INT8_C(  57),
        -INT8_C(  37), -INT8_C( 111), -INT8_C(  99), -INT8_C( 113),  INT8_C(  96), -INT8_C( 101), -INT8_C(  32), -INT8_C(  74) },
      { -INT8_C(  14), -INT8_C(  62), -INT8_C(  56), -INT8_C( 108),  INT8_C(  54),  INT8_C(  86),  INT8_C(  76), -INT8_C( 113),
         INT8_C(  57), -INT8_C(  35),  INT8_C(  99),  INT8_C(  82), -INT8_C( 117), -INT8_C(  15), -INT8_C(  95),  INT8_C(  94) },
      { -INT8_C( 108),  INT8_C(  99), -INT8_C(  56),  INT8_C(  82),  INT8_C(  94),  INT8_C(  82),  INT8_C(  99), -INT8_C( 113),
         INT8_C(  82), -INT8_C(  62), -INT8_C(  15),  INT8_C(  94), -INT8_C(  14),  INT8_C(  82), -INT8_C(  14),  INT8_C(  76) } },
    { {  INT8_C(  75), -INT8_C(  29), -INT8_C( 102),  INT8_C(  27), -INT8_C(  65),  INT8_C(  20), -INT8_C(  30), -INT8_C( 102),
        -INT8_C(  90),      INT8_MAX,  INT8_C(  42),  INT8_C(   6),  INT8_C(  26),  INT8_C(  10), -INT8_C(  68),  INT8_C(  12) },
      { -INT8_C(  52), -INT8_C( 124), -INT8_C(  96),  INT8_C(   3), -INT8_C(  37), -INT8_C(  19), -INT8_C( 110),  INT8_C(  20),
        -INT8_C(  54), -INT8_C(  11),  INT8_C( 102),  INT8_C(  85), -INT8_C(  26),  INT8_C(   7), -INT8_C(  76),  INT8_C(  50) },
      {  INT8_C(  85),  INT8_C(   3),  INT8_C( 102),  INT8_C(  85),  INT8_C(  50), -INT8_C(  37), -INT8_C(  96),  INT8_C( 102),
        -INT8_C( 110),  INT8_C(  50),  INT8_C( 102), -INT8_C( 110),  INT8_C( 102),  INT8_C( 102), -INT8_C(  26), -INT8_C(  26) } },
    { { -INT8_C(  21),  INT8_C(  78),  INT8_C(  77), -INT8_C(  86),  INT8_C(  98),  INT8_C(  47),  INT8_C(  68),  INT8_C(   8),
        -INT8_C(  82),  INT8_C( 110),  INT8_C(  14), -INT8_C(  56),  INT8_C( 120), -INT8_C(  53), -INT8_C(  44),  INT8_C(  69) },
      {  INT8_C(  79),  INT8_C( 117),  INT8_C(  72),  INT8_C(  42),  INT8_C(  98), -INT8_C(  38),  INT8_C(  62),  INT8_C(  44),
        -INT8_C(  49), -INT8_C(  92), -INT8_C( 126), -INT8_C(  74), -INT8_C(  84),  INT8_C(  54), -INT8_C(  24), -INT8_C( 105) },
      { -INT8_C(  74), -INT8_C(  24),  INT8_C(  54), -INT8_C( 126),  INT8_C(  72), -INT8_C( 105),  INT8_C(  98), -INT8_C(  49),
        -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  49), -INT8_C(  49), -INT8_C(  74),  INT8_C(  98), -INT8_C(  38) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_permutexvar_epi8(idx, a);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_permutexvar_epi8(idx, a);

    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t idx[16];
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 124),  INT8_C(  53),  INT8_C(  65), -INT8_C(  26),  INT8_C( 100), -INT8_C( 123), -INT8_C(  17),  INT8_C(  18),
        -INT8_C(  12), -INT8_C(   3), -INT8_C(  38),  INT8_C( 108), -INT8_C(  56), -INT8_C(  82), -INT8_C(  79),  INT8_C(  24) },
      UINT16_C(63779),
      {  INT8_C(  66), -INT8_C( 123), -INT8_C(  45), -INT8_C( 127), -INT8_C(  78), -INT8_C(  93),  INT8_C(  37),  INT8_C(  52),
         INT8_C(  89), -INT8_C(  47),  INT8_C( 106),  INT8_C(  65),  INT8_C( 104), -INT8_C(  18),  INT8_C( 118), -INT8_C(  87) },
      { -INT8_C(  44), -INT8_C(  38),  INT8_C(  47), -INT8_C(  61), -INT8_C(  20),  INT8_C(  35), -INT8_C(  63), -INT8_C(  58),
        -INT8_C( 113), -INT8_C( 119),  INT8_C( 116),  INT8_C(  65), -INT8_C(  95), -INT8_C( 104),  INT8_C(  58), -INT8_C(  28) },
      {  INT8_C(  47),  INT8_C(  35),  INT8_C(  65), -INT8_C(  26),  INT8_C( 100), -INT8_C(  61), -INT8_C(  17),  INT8_C(  18),
        -INT8_C( 119), -INT8_C(   3), -INT8_C(  38), -INT8_C(  38), -INT8_C( 113),  INT8_C(  58), -INT8_C(  63), -INT8_C( 119) } },
    { {  INT8_C(  29),  INT8_C(  14),  INT8_C( 101), -INT8_C(  49), -INT8_C(  79), -INT8_C( 118),  INT8_C(   3),  INT8_C(  10),
         INT8_C(  92),  INT8_C( 109),  INT8_C(  75), -INT8_C(  60),  INT8_C(  91), -INT8_C(  63),  INT8_C( 110),  INT8_C(  48) },
      UINT16_C(40347),
      { -INT8_C(  13), -INT8_C( 121), -INT8_C(  64), -INT8_C(  76),  INT8_C(  77),  INT8_C(  79),  INT8_C(  62), -INT8_C(  63),
        -INT8_C( 112), -INT8_C(  33),  INT8_C(  89), -INT8_C(  53), -INT8_C(  61),  INT8_C( 119), -INT8_C(  39),  INT8_C(  40) },
      {  INT8_C(  70), -INT8_C( 118), -INT8_C(  77),  INT8_C(  74), -INT8_C( 108),  INT8_C(  15), -INT8_C(  73), -INT8_C(  33),
        -INT8_C(  45),  INT8_C(  19), -INT8_C(  96),  INT8_C(  65),  INT8_C(  67),  INT8_C(  59), -INT8_C(  34),  INT8_C(  54) },
      {  INT8_C(  74), -INT8_C(  33),  INT8_C( 101), -INT8_C( 108),  INT8_C(  59), -INT8_C( 118),  INT8_C(   3), -INT8_C( 118),
         INT8_C(  70),  INT8_C( 109),  INT8_C(  19),  INT8_C(  65),  INT8_C(  74), -INT8_C(  63),  INT8_C( 110), -INT8_C(  45) } },
    { { -INT8_C(  62), -INT8_C(  98), -INT8_C(  21),  INT8_C(  15), -INT8_C(  18),  INT8_C(  41), -INT8_C(  48),  INT8_C( 126),
         INT8_C(   8),  INT8_C(  42),  INT8_C(  73), -INT8_C(  52), -INT8_C(  95),  INT8_C(  34), -INT8_C(  12), -INT8_C(  25) },
      UINT16_C(42924),
      {  INT8_C(  49),  INT8_C(  64), -INT8_C(  74), -INT8_C(  23),  INT8_C(  31), -INT8_C( 118), -INT8_C(   4), -INT8_C(  65),
        -INT8_C(  53),  INT8_C(  63), -INT8_C(   6), -INT8_C(  86),  INT8_C( 117), -INT8_C(  68),  INT8_C(  72),  INT8_C(  96) },
      { -INT8_C(  53),  INT8_C(  54), -INT8_C( 119), -INT8_C( 100), -INT8_C(  75), -INT8_C( 110), -INT8_C(  58), -INT8_C(   2),
         INT8_C(  94),  INT8_C( 103),  INT8_C(  33),  INT8_C(  82),  INT8_C(  78), -INT8_C(  51), -INT8_C(   6),      INT8_MIN },
      { -INT8_C(  62), -INT8_C(  98), -INT8_C(  58),  INT8_C( 103), -INT8_C(  18),  INT8_C(  33), -INT8_C(  48),      INT8_MIN,
         INT8_C(  82),      INT8_MIN,  INT8_C(  33), -INT8_C(  52), -INT8_C(  95),  INT8_C(  78), -INT8_C(  12), -INT8_C(  53) } },
    { {  INT8_C(  14), -INT8_C(  80),  INT8_C( 105),  INT8_C(  45),  INT8_C(  58),  INT8_C( 101), -INT8_C(  19),  INT8_C(   6),
        -INT8_C(  92), -INT8_C(  25), -INT8_C(  80),  INT8_C(  25), -INT8_C(  92), -INT8_C(   8),  INT8_C( 122),  INT8_C( 111) },
      UINT16_C(  815),
      {  INT8_C(  11), -INT8_C(  28), -INT8_C( 107), -INT8_C(  47), -INT8_C(  30), -INT8_C(  13),  INT8_C(  56),  INT8_C(   3),
         INT8_C(  70), -INT8_C( 121), -INT8_C(  47),  INT8_C(  64),  INT8_C(   7), -INT8_C(  33), -INT8_C(  16),  INT8_C( 112) },
      {  INT8_C(  12),  INT8_C(  43), -INT8_C(  43), -INT8_C(   7),  INT8_C(  49),  INT8_C( 121), -INT8_C(  31), -INT8_C(  31),
        -INT8_C( 110), -INT8_C( 123), -INT8_C(  39),  INT8_C(  12), -INT8_C(  12),  INT8_C(   8),  INT8_C(  16),  INT8_C(   0) },
      {  INT8_C(  12),  INT8_C(  49),  INT8_C( 121),  INT8_C(  43),  INT8_C(  58), -INT8_C(   7), -INT8_C(  19),  INT8_C(   6),
        -INT8_C(  31), -INT8_C(  31), -INT8_C(  80),  INT8_C(  25), -INT8_C(  92), -INT8_C(   8),  INT8_C( 122),  INT8_C( 111) } },
    { { -INT8_C(  20), -INT8_C(  91), -INT8_C(  47), -INT8_C(  49), -INT8_C( 103),  INT8_C(  10), -INT8_C(  46), -INT8_C(  33),
        -INT8_C( 111), -INT8_C(  93),  INT8_C(  31), -INT8_C( 104), -INT8_C( 126),  INT8_C(  15),  INT8_C(   8), -INT8_C( 113) },
      UINT16_C(56634),
      { -INT8_C( 120),  INT8_C( 107),  INT8_C(  86),  INT8_C( 105),  INT8_C(  76), -INT8_C(  24), -INT8_C(  18),  INT8_C(  38),
        -INT8_C(  11), -INT8_C(  29),  INT8_C(  46),  INT8_C(   5), -INT8_C(  29),  INT8_C(  27), -INT8_C(  86), -INT8_C(  76) },
      { -INT8_C(  22),  INT8_C(  67), -INT8_C(  66), -INT8_C(  68),  INT8_C(  34),  INT8_C(  79),  INT8_C(  96),  INT8_C(  65),
        -INT8_C(  25), -INT8_C(  30),  INT8_C(  81), -INT8_C(  17),  INT8_C( 113), -INT8_C( 117), -INT8_C(  52), -INT8_C(   6) },
      { -INT8_C(  20), -INT8_C(  17), -INT8_C(  47), -INT8_C(  30),  INT8_C( 113), -INT8_C(  25), -INT8_C(  46), -INT8_C(  33),
         INT8_C(  79), -INT8_C(  93), -INT8_C(  52),  INT8_C(  79), -INT8_C(  68),  INT8_C(  15),  INT8_C(  81),  INT8_C(  34) } },
    { { -INT8_C(   9),  INT8_C(  34),  INT8_C(  99),  INT8_C(  67),  INT8_C(  11),  INT8_C(  82),  INT8_C( 105),  INT8_C(   0),
         INT8_C(  53), -INT8_C( 104),  INT8_C(   5),  INT8_C(  24), -INT8_C(  77), -INT8_C(  81), -INT8_C(  52), -INT8_C(  99) },
      UINT16_C(35827),
      {  INT8_C(  89),  INT8_C(  21), -INT8_C(  38), -INT8_C(  71),  INT8_C(  87), -INT8_C(  62), -INT8_C( 100), -INT8_C(  88),
        -INT8_C(  79),  INT8_C(  13),  INT8_C(  51),  INT8_C( 126),  INT8_C(   7),  INT8_C(  42), -INT8_C(  96),  INT8_C( 107) },
      {  INT8_C( 110), -INT8_C(  85), -INT8_C(  67), -INT8_C(  41), -INT8_C(  85), -INT8_C(  14),  INT8_C( 111), -INT8_C(  80),
         INT8_C(  10),  INT8_C(  34),  INT8_C(  96), -INT8_C(  42), -INT8_C(  65),  INT8_C(  83),  INT8_C(  97),  INT8_C(  25) },
      {  INT8_C(  34), -INT8_C(  14),  INT8_C(  99),  INT8_C(  67), -INT8_C(  80), -INT8_C(  67), -INT8_C(  65),  INT8_C(  10),
        -INT8_C(  85),  INT8_C(  83),  INT8_C(   5),  INT8_C(  97), -INT8_C(  77), -INT8_C(  81), -INT8_C(  52), -INT8_C(  42) } },
    { {  INT8_C( 104),  INT8_C(  60), -INT8_C(  46), -INT8_C(  65), -INT8_C(   2),  INT8_C( 110),  INT8_C( 103), -INT8_C(  81),
         INT8_C( 124), -INT8_C( 101),  INT8_C(  45), -INT8_C( 125), -INT8_C(  59), -INT8_C(  50), -INT8_C(  18),  INT8_C(  51) },
      UINT16_C(43897),
      {  INT8_C(  11),  INT8_C(  37), -INT8_C(  99),  INT8_C( 122), -INT8_C(  43), -INT8_C(  89), -INT8_C(  99),  INT8_C(  53),
         INT8_C( 126),  INT8_C(  92), -INT8_C( 120), -INT8_C(  33),  INT8_C( 117), -INT8_C(  15),  INT8_C(  27),  INT8_C(  72) },
      { -INT8_C(  80),  INT8_C(  25), -INT8_C(  74),  INT8_C(  24), -INT8_C(  55),  INT8_C(  50), -INT8_C(  77), -INT8_C(  10),
        -INT8_C(  74),  INT8_C( 120), -INT8_C(  60), -INT8_C(  92), -INT8_C(  84),  INT8_C(  62),  INT8_C(  80), -INT8_C(  73) },
      { -INT8_C(  92),  INT8_C(  60), -INT8_C(  46), -INT8_C(  60),  INT8_C(  50), -INT8_C(  10),  INT8_C(  62), -INT8_C(  81),
         INT8_C(  80), -INT8_C(  84),  INT8_C(  45), -INT8_C(  73), -INT8_C(  59),  INT8_C(  25), -INT8_C(  18), -INT8_C(  74) } },
    { {  INT8_C(  99), -INT8_C(  19),  INT8_C(  49),  INT8_C(  56), -INT8_C( 107), -INT8_C(  50),  INT8_C( 110),  INT8_C(  19),
         INT8_C(  43), -INT8_C(  10), -INT8_C(  14), -INT8_C(  96), -INT8_C(  25),  INT8_C(  14), -INT8_C(  24), -INT8_C( 104) },
      UINT16_C(40743),
      { -INT8_C(  80), -INT8_C(  16), -INT8_C(  47),  INT8_C(  99), -INT8_C(  25), -INT8_C( 121), -INT8_C(  37), -INT8_C(  85),
         INT8_C(  44), -INT8_C( 121), -INT8_C(  23),  INT8_C( 124),  INT8_C(  62),  INT8_C(  76),  INT8_C( 105),  INT8_C( 112) },
      { -INT8_C( 123), -INT8_C(   2),  INT8_C(  62), -INT8_C(  13),  INT8_C(  17),  INT8_C( 105), -INT8_C(  23),  INT8_C(   4),
         INT8_C(  10), -INT8_C(  47),  INT8_C(  18), -INT8_C(  14),  INT8_C( 105),  INT8_C(  57), -INT8_C( 111),  INT8_C(  25) },
      { -INT8_C( 123), -INT8_C( 123), -INT8_C(   2),  INT8_C(  56), -INT8_C( 107),  INT8_C(   4),  INT8_C( 110),  INT8_C(  19),
         INT8_C( 105),  INT8_C(   4), -INT8_C(  47),  INT8_C( 105), -INT8_C( 111),  INT8_C(  14), -INT8_C(  24), -INT8_C( 123) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi8(test_vec[i].src);
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_mask_permutexvar_epi8(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i8x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask_permutexvar_epi8(src, k, idx, a);

    simde_test_x86_write_i8x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t idx[16];
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(25386),
      {  INT8_C( 124),  INT8_C(  17), -INT8_C(  22),  INT8_C(  87), -INT8_C(  68),  INT8_C(  22), -INT8_C(  33), -INT8_C(  90),
        -INT8_C( 110),  INT8_C(  29), -INT8_C(  14), -INT8_C(   4), -INT8_C( 115),  INT8_C( 119), -INT8_C(   6), -INT8_C(  52) },
      {  INT8_C( 106),  INT8_C(  12),  INT8_C(  53),  INT8_C(  84),  INT8_C(  16),  INT8_C(  63),  INT8_C(  37),  INT8_C(  34),
         INT8_C(  50), -INT8_C( 114),  INT8_C(  91), -INT8_C(  61), -INT8_C(  89), -INT8_C( 123),  INT8_C(  38),  INT8_C(  35) },
      {  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),  INT8_C(  37),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  53), -INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34),  INT8_C(  91),  INT8_C(   0) } },
    { UINT16_C( 4502),
      {  INT8_C( 122),  INT8_C(  83),  INT8_C(  39),  INT8_C(  89), -INT8_C(   7), -INT8_C(  70),  INT8_C( 119), -INT8_C(  21),
        -INT8_C(  74),  INT8_C(   4),  INT8_C(  99), -INT8_C(  80), -INT8_C(  48), -INT8_C(  51), -INT8_C(  68),  INT8_C(   6) },
      {  INT8_C(  33), -INT8_C(  52),  INT8_C(  69),  INT8_C(  70), -INT8_C(  18),  INT8_C( 119), -INT8_C(  44),  INT8_C(  74),
         INT8_C(  59),  INT8_C( 123), -INT8_C(  49),  INT8_C(  97), -INT8_C(  98),  INT8_C( 102),  INT8_C( 114),  INT8_C(  25) },
      {  INT8_C(   0),  INT8_C(  70),  INT8_C(  74),  INT8_C(   0),  INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(  97),
        -INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(39609),
      {  INT8_C( 114), -INT8_C(  78),  INT8_C(  84), -INT8_C(  23), -INT8_C(  99),  INT8_C(  10), -INT8_C(  18),  INT8_C(   0),
        -INT8_C(  70), -INT8_C(  66), -INT8_C(  50),  INT8_C( 119), -INT8_C(  60), -INT8_C(  17),  INT8_C(  67),  INT8_C(  10) },
      {  INT8_C(  54),  INT8_C(  50), -INT8_C( 127),  INT8_C(  10),  INT8_C( 124), -INT8_C(  68), -INT8_C( 122),  INT8_C(  75),
         INT8_C(  30),  INT8_C(  36), -INT8_C(  79), -INT8_C( 112),  INT8_C(  61),  INT8_C( 106),  INT8_C(  42), -INT8_C(  80) },
      { -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),  INT8_C(  36),  INT8_C( 106), -INT8_C(  79),  INT8_C(   0),  INT8_C(  54),
         INT8_C(   0),  INT8_C(  42),  INT8_C(   0),  INT8_C(  75),  INT8_C( 124),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79) } },
    { UINT16_C(32284),
      { -INT8_C( 103), -INT8_C(  70), -INT8_C( 120), -INT8_C( 121), -INT8_C(  70),  INT8_C(  67),  INT8_C(  70), -INT8_C( 120),
        -INT8_C(  70),  INT8_C(  10),  INT8_C( 120), -INT8_C(   3),  INT8_C(  20), -INT8_C(  82),  INT8_C(  47), -INT8_C( 106) },
      { -INT8_C(  72), -INT8_C(  85),  INT8_C(  82),  INT8_C(  62), -INT8_C(   9),  INT8_C( 112),  INT8_C(  99), -INT8_C(  88),
         INT8_C(   1), -INT8_C(  96),  INT8_C(  19),  INT8_C(  43),  INT8_C(  80),  INT8_C(  47), -INT8_C(  86), -INT8_C(  22) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(  88),  INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  19),  INT8_C(   1),  INT8_C(  47), -INT8_C(   9), -INT8_C(  86), -INT8_C(  22),  INT8_C(   0) } },
    { UINT16_C(13033),
      {  INT8_C( 113), -INT8_C(  92),  INT8_C( 117), -INT8_C(  73),  INT8_C(  44),  INT8_C(  47), -INT8_C(  62), -INT8_C(  92),
         INT8_C(  45), -INT8_C(  42),  INT8_C(  82),  INT8_C(  92),  INT8_C( 108),  INT8_C(  11),  INT8_C(   8), -INT8_C(  65) },
      {  INT8_C(  73), -INT8_C(   1),  INT8_C(  47), -INT8_C(  84), -INT8_C(  89),  INT8_C(  48),  INT8_C(  77), -INT8_C(  70),
         INT8_C(  92), -INT8_C(  99), -INT8_C(  22),  INT8_C(   6), -INT8_C( 121), -INT8_C(  45),  INT8_C(  56), -INT8_C(   7) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(  70),  INT8_C(   0), -INT8_C(   7),  INT8_C(  47), -INT8_C(  89),
         INT8_C(   0),  INT8_C(  77),  INT8_C(   0),  INT8_C(   0), -INT8_C( 121),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(44663),
      { -INT8_C(  80), -INT8_C(  92), -INT8_C(  35),  INT8_C( 114),  INT8_C(  72),  INT8_C(  10),  INT8_C(  73), -INT8_C( 101),
         INT8_C( 103), -INT8_C(  75), -INT8_C(  90),  INT8_C( 111),  INT8_C( 116), -INT8_C(  17),  INT8_C( 110), -INT8_C(  92) },
      { -INT8_C( 100),  INT8_C(  21), -INT8_C(  44), -INT8_C(  23), -INT8_C(  48),  INT8_C(  48), -INT8_C( 122), -INT8_C(  70),
         INT8_C(  54),  INT8_C(  14), -INT8_C( 115),  INT8_C( 111),  INT8_C(   7),  INT8_C(   5),  INT8_C(  29), -INT8_C(  73) },
      { -INT8_C( 100), -INT8_C(  48),  INT8_C(   5),  INT8_C(   0),  INT8_C(  54), -INT8_C( 115),  INT8_C(  14),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  48), -INT8_C( 122), -INT8_C(  73),  INT8_C(   0), -INT8_C(  73),  INT8_C(   0), -INT8_C(  48) } },
    { UINT16_C(64169),
      {  INT8_C(  42), -INT8_C(  15),  INT8_C(   5),  INT8_C( 115), -INT8_C( 116),  INT8_C( 108),  INT8_C(  40),  INT8_C(  50),
        -INT8_C(  37), -INT8_C(  99),  INT8_C(  34),  INT8_C(  73),  INT8_C(  65), -INT8_C(  66),  INT8_C(  94),  INT8_C(  21) },
      { -INT8_C(  89),  INT8_C(  46),  INT8_C(  70),  INT8_C(  45), -INT8_C(  24),  INT8_C( 124),  INT8_C(  59),  INT8_C( 118),
        -INT8_C(  21),  INT8_C(  66),  INT8_C( 123),  INT8_C(   8), -INT8_C(   6),  INT8_C(  36),  INT8_C(   3),  INT8_C(  36) },
      {  INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(  45),  INT8_C(   0), -INT8_C(   6),  INT8_C(   0),  INT8_C(  70),
         INT8_C(   0),  INT8_C(  36),  INT8_C(   0),  INT8_C(  66),  INT8_C(  46),  INT8_C(   3),  INT8_C(   3),  INT8_C( 124) } },
    { UINT16_C( 2069),
      { -INT8_C( 105), -INT8_C(  94),  INT8_C( 116), -INT8_C(  65), -INT8_C(  44),  INT8_C(  79),  INT8_C(  92), -INT8_C(  10),
        -INT8_C( 104), -INT8_C(  99), -INT8_C(  76), -INT8_C(  10), -INT8_C(  77),  INT8_C(  91),  INT8_C(  37), -INT8_C(   7) },
      { -INT8_C( 119),  INT8_C(  13),  INT8_C( 117), -INT8_C(  60), -INT8_C( 125),  INT8_C(  97),  INT8_C(   7), -INT8_C(   2),
         INT8_C( 105),  INT8_C(   1),  INT8_C(  34),  INT8_C( 108),  INT8_C(  37),  INT8_C(  56),  INT8_C( 116), -INT8_C(  68) },
      { -INT8_C(   2),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_permutexvar_epi8(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_maskz_permutexvar_epi8(k, idx, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t idx[16];
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C(  5893), -INT16_C( 32362),  INT16_C( 15791), -INT16_C( 31311), -INT16_C( 29409), -INT16_C( 15393),  INT16_C(  6807), -INT16_C( 24848),
        -INT16_C( 12998),  INT16_C(  1199),  INT16_C(  9359),  INT16_C( 30035),  INT16_C( 14670), -INT16_C( 18355), -INT16_C( 18338),  INT16_C( 25575) },
      {  INT16_C( 32208),  INT16_C( 32740), -INT16_C( 27206), -INT16_C(  9980), -INT16_C(  7390), -INT16_C( 18019), -INT16_C( 29187),  INT16_C( 14423),
         INT16_C(  1626), -INT16_C(  5828), -INT16_C( 28886),  INT16_C( 31071), -INT16_C( 21304),  INT16_C(  9777),  INT16_C(  6244),  INT16_C( 13449) },
      { -INT16_C( 18019), -INT16_C( 29187),  INT16_C( 13449),  INT16_C( 32740),  INT16_C( 13449),  INT16_C( 13449),  INT16_C( 14423),  INT16_C( 32208),
        -INT16_C( 28886),  INT16_C( 13449),  INT16_C( 13449), -INT16_C(  9980),  INT16_C(  6244),  INT16_C(  9777),  INT16_C(  6244),  INT16_C( 14423) } },
    { {  INT16_C( 28053),  INT16_C( 20659), -INT16_C( 18430),  INT16_C(  9257), -INT16_C( 14693), -INT16_C( 26147),  INT16_C( 13395), -INT16_C( 20783),
         INT16_C(  3387),  INT16_C( 26007), -INT16_C(  2403),  INT16_C( 26078),  INT16_C(  4002),  INT16_C(  1932),  INT16_C(  5415), -INT16_C( 17093) },
      { -INT16_C(  4221), -INT16_C( 31475),  INT16_C( 13991),  INT16_C( 17066), -INT16_C( 30723),  INT16_C( 20699), -INT16_C( 21316), -INT16_C(  2050),
        -INT16_C( 26950),  INT16_C( 22364),  INT16_C( 15244),  INT16_C( 12220),  INT16_C( 18506),  INT16_C( 29238),  INT16_C( 29022), -INT16_C(  7889) },
      {  INT16_C( 20699),  INT16_C( 17066),  INT16_C( 13991),  INT16_C( 22364),  INT16_C( 12220),  INT16_C( 29238),  INT16_C( 17066), -INT16_C( 31475),
         INT16_C( 12220), -INT16_C(  2050),  INT16_C( 29238),  INT16_C( 29022),  INT16_C( 13991),  INT16_C( 18506), -INT16_C(  2050),  INT16_C( 12220) } },
    { {  INT16_C( 15456),  INT16_C(  1894),  INT16_C(  4210),  INT16_C( 28490),  INT16_C(  9624),  INT16_C( 21696), -INT16_C( 16686), -INT16_C( 29621),
        -INT16_C( 22700), -INT16_C(  7709), -INT16_C( 24606),  INT16_C( 11536),  INT16_C( 18152),  INT16_C( 18079), -INT16_C( 12617),  INT16_C(  6183) },
      { -INT16_C( 29430),  INT16_C( 31775),  INT16_C( 27038),  INT16_C( 14060), -INT16_C( 21361),  INT16_C( 24970), -INT16_C( 10902), -INT16_C( 16403),
        -INT16_C( 12164),  INT16_C( 24480), -INT16_C( 20369),  INT16_C( 22412),  INT16_C( 11254), -INT16_C( 21091), -INT16_C( 15111),  INT16_C(   965) },
      { -INT16_C( 29430), -INT16_C( 10902),  INT16_C( 27038), -INT16_C( 20369), -INT16_C( 12164), -INT16_C( 29430),  INT16_C( 27038),  INT16_C( 22412),
        -INT16_C( 21361),  INT16_C( 14060),  INT16_C( 27038), -INT16_C( 29430), -INT16_C( 12164),  INT16_C(   965), -INT16_C( 16403), -INT16_C( 16403) } },
    { { -INT16_C(  6830), -INT16_C(  3969),  INT16_C( 27470), -INT16_C(  8922), -INT16_C( 20457), -INT16_C( 32194),  INT16_C( 11141),  INT16_C(   321),
        -INT16_C(  7685),  INT16_C( 27488), -INT16_C(  4975), -INT16_C( 30782),  INT16_C( 24599),  INT16_C(  4148), -INT16_C(  1500),  INT16_C( 30227) },
      { -INT16_C( 27681),  INT16_C( 11622), -INT16_C( 29442),  INT16_C(  5643),  INT16_C( 18748), -INT16_C( 15976), -INT16_C(  9867),  INT16_C( 28867),
         INT16_C(  9146),  INT16_C( 19419), -INT16_C( 25072),  INT16_C( 10194),  INT16_C(  1790),  INT16_C(  8760),  INT16_C( 19200), -INT16_C(  8295) },
      { -INT16_C( 29442), -INT16_C(  8295),  INT16_C( 19200), -INT16_C(  9867),  INT16_C( 28867),  INT16_C( 19200), -INT16_C( 15976),  INT16_C( 11622),
         INT16_C( 10194), -INT16_C( 27681),  INT16_C( 11622), -INT16_C( 29442),  INT16_C( 28867),  INT16_C( 18748),  INT16_C( 18748),  INT16_C(  5643) } },
    { { -INT16_C(    34), -INT16_C(  8947),  INT16_C(  6284), -INT16_C( 14093), -INT16_C( 29855), -INT16_C( 10614),  INT16_C( 19812),  INT16_C(  7751),
         INT16_C(  8816), -INT16_C( 32663),  INT16_C( 15296), -INT16_C( 16728), -INT16_C(  8127),  INT16_C( 17121),  INT16_C( 31275),  INT16_C(  2593) },
      {  INT16_C( 11897),  INT16_C(  1511), -INT16_C(  9658), -INT16_C( 22322),  INT16_C( 22629), -INT16_C( 13954), -INT16_C( 14939),  INT16_C(  5607),
         INT16_C( 20712), -INT16_C( 22378),  INT16_C( 16011), -INT16_C( 13209),  INT16_C( 18462),  INT16_C( 18702),  INT16_C( 12482),  INT16_C( 15187) },
      {  INT16_C( 12482),  INT16_C( 18702),  INT16_C( 18462), -INT16_C( 22322),  INT16_C(  1511),  INT16_C( 16011),  INT16_C( 22629),  INT16_C(  5607),
         INT16_C( 11897), -INT16_C( 22378),  INT16_C( 11897),  INT16_C( 20712),  INT16_C(  1511),  INT16_C(  1511), -INT16_C( 13209),  INT16_C(  1511) } },
    { {  INT16_C( 14942), -INT16_C( 23231),  INT16_C(  3860),  INT16_C( 31053), -INT16_C( 13465),  INT16_C(  3138),  INT16_C( 10641),  INT16_C( 31009),
        -INT16_C( 18567),  INT16_C(  1057), -INT16_C( 30475),  INT16_C(  5073), -INT16_C(  8240), -INT16_C( 28067), -INT16_C( 20465),  INT16_C( 28366) },
      {  INT16_C(  4075), -INT16_C(   237),  INT16_C( 24606), -INT16_C( 31367), -INT16_C( 17621), -INT16_C( 17263), -INT16_C( 19739),  INT16_C( 24117),
         INT16_C( 22378),  INT16_C( 24419),  INT16_C( 13535), -INT16_C( 20365), -INT16_C( 12269),  INT16_C(  9026),  INT16_C(  4224),  INT16_C( 27537) },
      {  INT16_C(  4224), -INT16_C(   237), -INT16_C( 17621),  INT16_C(  9026),  INT16_C( 24117),  INT16_C( 24606), -INT16_C(   237), -INT16_C(   237),
         INT16_C( 24419), -INT16_C(   237), -INT16_C( 17263), -INT16_C(   237),  INT16_C(  4075),  INT16_C(  9026),  INT16_C( 27537),  INT16_C(  4224) } },
    { { -INT16_C( 23521),  INT16_C( 15723), -INT16_C(  7164),  INT16_C( 12226),  INT16_C( 21407), -INT16_C( 31508),  INT16_C(  8454),  INT16_C( 28899),
         INT16_C( 18040),  INT16_C( 22735),  INT16_C( 17018), -INT16_C( 29432),  INT16_C( 18962), -INT16_C( 27728),  INT16_C( 16731),  INT16_C( 31486) },
      {  INT16_C( 27109), -INT16_C(  5704),  INT16_C( 31309), -INT16_C(  4839),  INT16_C(  1486), -INT16_C( 11151),  INT16_C( 21542), -INT16_C( 24764),
         INT16_C(  5018),  INT16_C(  5367), -INT16_C(   170),  INT16_C( 26786),  INT16_C( 21065), -INT16_C( 23301), -INT16_C(  1388),  INT16_C( 31007) },
      {  INT16_C( 31007),  INT16_C( 26786),  INT16_C(  1486),  INT16_C( 31309),  INT16_C( 31007),  INT16_C( 21065),  INT16_C( 21542), -INT16_C(  4839),
         INT16_C(  5018),  INT16_C( 31007), -INT16_C(   170),  INT16_C(  5018),  INT16_C( 31309),  INT16_C( 27109),  INT16_C( 26786), -INT16_C(  1388) } },
    { { -INT16_C( 10397), -INT16_C( 20125),  INT16_C( 31825),  INT16_C(  8094),  INT16_C(  3969), -INT16_C( 22541),  INT16_C( 14180), -INT16_C(   442),
         INT16_C( 15691), -INT16_C( 24301), -INT16_C( 19140), -INT16_C( 31223),  INT16_C(  1287), -INT16_C( 25814),  INT16_C( 18943),  INT16_C( 25109) },
      {  INT16_C( 30752),  INT16_C( 29203), -INT16_C( 19980),  INT16_C( 30097), -INT16_C( 31295),  INT16_C(  9500),  INT16_C( 25532),  INT16_C(  1827),
         INT16_C( 13984), -INT16_C(  8792), -INT16_C( 19733), -INT16_C(  3229), -INT16_C( 29257), -INT16_C( 18802), -INT16_C( 23593), -INT16_C(  2280) },
      {  INT16_C( 30097),  INT16_C( 30097),  INT16_C( 29203), -INT16_C( 23593),  INT16_C( 29203),  INT16_C( 30097), -INT16_C( 31295),  INT16_C( 25532),
        -INT16_C(  3229),  INT16_C( 30097), -INT16_C( 29257), -INT16_C(  8792),  INT16_C(  1827), -INT16_C( 19733), -INT16_C(  2280),  INT16_C(  9500) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_permutexvar_epi16(idx, a);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_permutexvar_epi16(idx, a);

    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t idx[16];
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 11291),  INT16_C(  3945), -INT16_C(  1059), -INT16_C( 24956), -INT16_C( 24192),  INT16_C( 15555), -INT16_C(  6396), -INT16_C( 23484),
        -INT16_C(  5091),  INT16_C(  2433), -INT16_C(  7010),  INT16_C( 22012), -INT16_C( 30094),  INT16_C( 18699),  INT16_C(  9262),  INT16_C( 18752) },
      UINT16_C(43600),
      {  INT16_C( 11609), -INT16_C(  8795),  INT16_C(  9676), -INT16_C( 28802), -INT16_C( 32159), -INT16_C( 23178), -INT16_C( 27609), -INT16_C( 22382),
         INT16_C( 12445), -INT16_C( 26227), -INT16_C(   122), -INT16_C( 28381),  INT16_C( 20808), -INT16_C( 30539),  INT16_C(  1435), -INT16_C(  3022) },
      { -INT16_C( 10445), -INT16_C(    47),  INT16_C( 20732),  INT16_C( 24206),  INT16_C(  1490), -INT16_C(  1789), -INT16_C( 27239),  INT16_C( 13986),
         INT16_C( 12230),  INT16_C( 19663), -INT16_C(  3538),  INT16_C( 30429), -INT16_C( 27836), -INT16_C(  8194),  INT16_C( 12696), -INT16_C( 13357) },
      {  INT16_C( 11291),  INT16_C(  3945), -INT16_C(  1059), -INT16_C( 24956), -INT16_C(    47),  INT16_C( 15555),  INT16_C( 13986), -INT16_C( 23484),
        -INT16_C(  5091), -INT16_C(  8194), -INT16_C(  7010),  INT16_C( 24206), -INT16_C( 30094), -INT16_C(  1789),  INT16_C(  9262),  INT16_C( 20732) } },
    { { -INT16_C( 23544),  INT16_C(  1482),  INT16_C( 23028), -INT16_C( 14493),  INT16_C( 26206), -INT16_C(  2112),  INT16_C( 25340), -INT16_C( 15827),
        -INT16_C(   879), -INT16_C( 16626), -INT16_C(  5138),  INT16_C( 12853),  INT16_C( 13438),  INT16_C(  5905), -INT16_C(  7067),  INT16_C( 28130) },
      UINT16_C(44425),
      {  INT16_C( 32114), -INT16_C( 11002),  INT16_C( 25668),  INT16_C(  1340),  INT16_C( 14427), -INT16_C( 30617), -INT16_C(  1542),  INT16_C(  2180),
         INT16_C( 29368), -INT16_C(  4365),  INT16_C( 29349), -INT16_C( 18910), -INT16_C( 30839),  INT16_C( 27547),  INT16_C(  9460),  INT16_C( 26392) },
      {  INT16_C(  7841), -INT16_C(  6596),  INT16_C( 30850), -INT16_C(  8725),  INT16_C( 21168), -INT16_C( 21915), -INT16_C(  5813),  INT16_C(  1202),
        -INT16_C( 22948),  INT16_C(   498),  INT16_C(  5144), -INT16_C( 24137),  INT16_C( 21147), -INT16_C( 28916),  INT16_C(  9590),  INT16_C(  6390) },
      {  INT16_C( 30850),  INT16_C(  1482),  INT16_C( 23028),  INT16_C( 21147),  INT16_C( 26206), -INT16_C(  2112),  INT16_C( 25340),  INT16_C( 21168),
        -INT16_C( 22948), -INT16_C( 16626), -INT16_C( 21915),  INT16_C( 30850),  INT16_C( 13438), -INT16_C( 24137), -INT16_C(  7067), -INT16_C( 22948) } },
    { {  INT16_C( 13123), -INT16_C( 14594), -INT16_C(  5717),  INT16_C( 23715),  INT16_C(  2363), -INT16_C( 30970), -INT16_C( 17934),  INT16_C( 20107),
         INT16_C( 32095),  INT16_C( 30543),  INT16_C(  1937),  INT16_C( 11288),  INT16_C(  9305), -INT16_C( 12101), -INT16_C( 19895), -INT16_C( 29208) },
      UINT16_C(59109),
      { -INT16_C( 28589), -INT16_C(  2353),  INT16_C(  2796), -INT16_C(  3073), -INT16_C(  3439),  INT16_C(  7340),  INT16_C(  2880), -INT16_C( 28519),
         INT16_C( 10882), -INT16_C( 25961), -INT16_C(  4010),  INT16_C(  4798),  INT16_C(  2240), -INT16_C( 22332), -INT16_C( 22123), -INT16_C(  6002) },
      {  INT16_C( 23865),  INT16_C(  9950), -INT16_C(  8600), -INT16_C(  1767), -INT16_C( 14896),  INT16_C(  4118), -INT16_C( 20528),  INT16_C( 21152),
         INT16_C( 14298),  INT16_C( 12524), -INT16_C( 21976), -INT16_C(  6078),  INT16_C(  1714),  INT16_C( 18321),  INT16_C(  8111), -INT16_C(  5841) },
      { -INT16_C(  1767), -INT16_C( 14594),  INT16_C(  1714),  INT16_C( 23715),  INT16_C(  2363),  INT16_C(  1714),  INT16_C( 23865),  INT16_C( 12524),
         INT16_C( 32095),  INT16_C( 21152), -INT16_C( 20528),  INT16_C( 11288),  INT16_C(  9305), -INT16_C( 14896),  INT16_C(  4118),  INT16_C(  8111) } },
    { {  INT16_C(  3709), -INT16_C(  6897),  INT16_C( 10476), -INT16_C( 17186), -INT16_C(  2835), -INT16_C( 16948),  INT16_C( 28068),  INT16_C( 32271),
        -INT16_C(  1116), -INT16_C( 13138), -INT16_C(  3675),  INT16_C( 22709),  INT16_C( 18167), -INT16_C( 22625), -INT16_C( 12443), -INT16_C(  7536) },
      UINT16_C(40925),
      { -INT16_C( 13881), -INT16_C( 22841), -INT16_C( 19323),  INT16_C( 20890),  INT16_C( 15985), -INT16_C( 32578),  INT16_C( 25532),  INT16_C( 27515),
         INT16_C(  8239), -INT16_C(  7076),  INT16_C( 21368),  INT16_C(  6186), -INT16_C( 28422), -INT16_C( 29977), -INT16_C( 15246),  INT16_C( 14889) },
      { -INT16_C(  3955),  INT16_C(  4832),  INT16_C( 31396),  INT16_C(  5475),  INT16_C(  8889),  INT16_C( 30101),  INT16_C(  4229), -INT16_C( 19232),
         INT16_C( 15409), -INT16_C( 22119), -INT16_C( 15472), -INT16_C( 30015), -INT16_C( 22445), -INT16_C( 14827),  INT16_C( 15980), -INT16_C(  1792) },
      { -INT16_C( 19232), -INT16_C(  6897),  INT16_C( 30101), -INT16_C( 15472),  INT16_C(  4832), -INT16_C( 16948), -INT16_C( 22445), -INT16_C( 30015),
        -INT16_C(  1792), -INT16_C( 22445),  INT16_C( 15409), -INT16_C( 15472), -INT16_C( 15472), -INT16_C( 22625), -INT16_C( 12443), -INT16_C( 22119) } },
    { { -INT16_C(  8145), -INT16_C( 11509),  INT16_C( 28506),  INT16_C(  5097),  INT16_C( 32401),  INT16_C(  5769),  INT16_C( 27023), -INT16_C( 16182),
         INT16_C( 25510),  INT16_C( 13929),  INT16_C( 11047),  INT16_C( 31424), -INT16_C( 10797),  INT16_C( 16448),  INT16_C( 16404),  INT16_C( 17209) },
      UINT16_C(17696),
      {  INT16_C( 31510), -INT16_C(    76),  INT16_C( 17806),  INT16_C(  6014),  INT16_C(  3419),  INT16_C(  9601),  INT16_C( 10189),  INT16_C( 13961),
        -INT16_C( 20387),  INT16_C(  7521),  INT16_C( 13610),  INT16_C( 27635),  INT16_C(  1909), -INT16_C( 20821), -INT16_C( 13238),  INT16_C( 24819) },
      { -INT16_C( 22713), -INT16_C( 10912), -INT16_C(  8468),  INT16_C( 18413),  INT16_C( 28395), -INT16_C( 18323), -INT16_C(  2411), -INT16_C(  3346),
         INT16_C( 20646), -INT16_C( 12273),  INT16_C(   645), -INT16_C(  1477), -INT16_C(  6391),  INT16_C( 21416), -INT16_C( 25421), -INT16_C(  1356) },
      { -INT16_C(  8145), -INT16_C( 11509),  INT16_C( 28506),  INT16_C(  5097),  INT16_C( 32401), -INT16_C( 10912),  INT16_C( 27023), -INT16_C( 16182),
         INT16_C( 21416),  INT16_C( 13929),  INT16_C(   645),  INT16_C( 31424), -INT16_C( 10797),  INT16_C( 16448),  INT16_C(   645),  INT16_C( 17209) } },
    { {  INT16_C(  5187),  INT16_C( 12495), -INT16_C( 17166), -INT16_C(  8841), -INT16_C(  7126), -INT16_C( 16491), -INT16_C( 31782), -INT16_C( 32591),
        -INT16_C( 15917),  INT16_C( 22609), -INT16_C( 29501), -INT16_C( 12974), -INT16_C(  1165),  INT16_C(  9760), -INT16_C( 11113), -INT16_C(  9696) },
      UINT16_C(61672),
      { -INT16_C(  9718), -INT16_C( 32084), -INT16_C( 10313),  INT16_C( 19558),  INT16_C( 16790),  INT16_C( 18640), -INT16_C( 23615),  INT16_C(  4617),
        -INT16_C( 13060),  INT16_C( 20127),  INT16_C(  4761), -INT16_C( 17847), -INT16_C(  8135),  INT16_C( 22926),  INT16_C( 30651), -INT16_C( 15031) },
      { -INT16_C(  2479),  INT16_C(  2375), -INT16_C( 20787),  INT16_C( 25429),  INT16_C(  9711), -INT16_C( 20309), -INT16_C( 19255), -INT16_C( 14909),
         INT16_C( 25217),  INT16_C(  6675),  INT16_C( 23924), -INT16_C( 21036),  INT16_C( 25405), -INT16_C(  2041),  INT16_C( 20698),  INT16_C( 11198) },
      {  INT16_C(  5187),  INT16_C( 12495), -INT16_C( 17166), -INT16_C( 19255), -INT16_C(  7126), -INT16_C(  2479),  INT16_C(  2375),  INT16_C(  6675),
        -INT16_C( 15917),  INT16_C( 22609), -INT16_C( 29501), -INT16_C( 12974),  INT16_C(  6675),  INT16_C( 20698), -INT16_C( 21036),  INT16_C(  6675) } },
    { {  INT16_C(  1350),  INT16_C(  4916), -INT16_C( 30029), -INT16_C( 23945),  INT16_C(  8879),  INT16_C( 30803),  INT16_C(  5847),  INT16_C( 22589),
         INT16_C( 20856), -INT16_C(  5006),  INT16_C( 18350), -INT16_C(  5222), -INT16_C( 24150), -INT16_C( 31516), -INT16_C( 23823),  INT16_C( 14511) },
      UINT16_C(58535),
      {  INT16_C( 23371), -INT16_C( 15762),  INT16_C(  7677),  INT16_C( 20709), -INT16_C( 17258), -INT16_C( 11418), -INT16_C(  8684), -INT16_C( 31196),
        -INT16_C( 11573),  INT16_C( 26061),  INT16_C( 30654), -INT16_C( 24058), -INT16_C(  2053), -INT16_C( 21692), -INT16_C(  5329),  INT16_C( 31631) },
      { -INT16_C(   698),  INT16_C( 17469),  INT16_C(  8730), -INT16_C( 20332), -INT16_C(  1058), -INT16_C(  3452), -INT16_C( 22311), -INT16_C( 23431),
         INT16_C( 18043),  INT16_C( 14601),  INT16_C(  4030), -INT16_C( 17957),  INT16_C(  7943),  INT16_C( 13924), -INT16_C(  3318),  INT16_C( 20913) },
      { -INT16_C( 17957), -INT16_C(  3318),  INT16_C( 13924), -INT16_C( 23945),  INT16_C(  8879), -INT16_C( 22311),  INT16_C(  5847), -INT16_C(  1058),
         INT16_C( 20856), -INT16_C(  5006), -INT16_C(  3318), -INT16_C(  5222), -INT16_C( 24150), -INT16_C(  1058),  INT16_C( 20913),  INT16_C( 20913) } },
    { { -INT16_C(  4112),  INT16_C(  2965),  INT16_C( 10513), -INT16_C(  3909),  INT16_C( 16164), -INT16_C(   286),  INT16_C( 23528),  INT16_C( 25506),
        -INT16_C( 21342),  INT16_C( 24732),  INT16_C( 30651), -INT16_C( 15847),  INT16_C( 32406), -INT16_C( 24327), -INT16_C( 21903),  INT16_C( 25329) },
      UINT16_C(34457),
      { -INT16_C( 21651),  INT16_C( 10416), -INT16_C( 11109),  INT16_C( 32104),  INT16_C( 20690),  INT16_C( 30169),  INT16_C( 31667),  INT16_C( 20257),
        -INT16_C(  8997), -INT16_C(  2874),  INT16_C( 23711), -INT16_C( 26510), -INT16_C(  6916), -INT16_C(  4542), -INT16_C(  9146), -INT16_C( 19596) },
      {  INT16_C(  9351),  INT16_C(  8923),  INT16_C( 17401), -INT16_C( 13409),  INT16_C( 30867),  INT16_C( 17984),  INT16_C( 25075), -INT16_C( 12651),
         INT16_C( 23358), -INT16_C(  8765),  INT16_C( 13751), -INT16_C( 19339), -INT16_C( 18663),  INT16_C( 24482),  INT16_C(  5779),  INT16_C(  6674) },
      {  INT16_C( 24482),  INT16_C(  2965),  INT16_C( 10513),  INT16_C( 23358),  INT16_C( 17401), -INT16_C(   286),  INT16_C( 23528),  INT16_C(  8923),
        -INT16_C( 21342),  INT16_C( 25075),  INT16_C(  6674), -INT16_C( 15847),  INT16_C( 32406), -INT16_C( 24327), -INT16_C( 21903),  INT16_C( 30867) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_permutexvar_epi16(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_permutexvar_epi16(src, k, idx, a);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t idx[16];
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(60987),
      {  INT16_C( 13372), -INT16_C(  9167), -INT16_C( 14849),  INT16_C( 16468),  INT16_C( 18443), -INT16_C( 24159), -INT16_C(  8426), -INT16_C(  9732),
        -INT16_C( 19268),  INT16_C( 12559),  INT16_C( 10344),  INT16_C(  2793),  INT16_C( 31880), -INT16_C( 26080),  INT16_C( 23447), -INT16_C( 11384) },
      { -INT16_C( 17777), -INT16_C( 28753),  INT16_C(  1151), -INT16_C( 30001),  INT16_C( 28748),  INT16_C( 25131),  INT16_C( 10320),  INT16_C(  3132),
         INT16_C( 19420),  INT16_C( 17470),  INT16_C( 10099), -INT16_C(  1202),  INT16_C( 28323),  INT16_C( 14998),  INT16_C(  7882),  INT16_C( 22798) },
      {  INT16_C( 28323), -INT16_C( 28753),  INT16_C(     0),  INT16_C( 28748), -INT16_C(  1202), -INT16_C( 28753),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 22798),  INT16_C( 19420),  INT16_C( 17470),  INT16_C(     0), -INT16_C( 17777),  INT16_C(  3132),  INT16_C( 19420) } },
    { UINT16_C(48600),
      {  INT16_C( 22504), -INT16_C( 18495),  INT16_C(  3554),  INT16_C(  3368),  INT16_C( 30832), -INT16_C( 21451),  INT16_C(  4484), -INT16_C( 15625),
         INT16_C( 27221), -INT16_C( 23575), -INT16_C( 29338), -INT16_C(  1006), -INT16_C(  9017), -INT16_C( 10982), -INT16_C(  3275),  INT16_C(  7827) },
      {  INT16_C( 21578),  INT16_C( 11477), -INT16_C(   670), -INT16_C( 11718),  INT16_C( 28533), -INT16_C(  1410),  INT16_C( 30081), -INT16_C( 10564),
        -INT16_C( 22817),  INT16_C( 17786), -INT16_C( 29645), -INT16_C(  1471),  INT16_C( 23656), -INT16_C( 25136),  INT16_C( 25423), -INT16_C( 26181) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 22817),  INT16_C( 21578),  INT16_C(     0),  INT16_C( 28533), -INT16_C( 10564),
        -INT16_C(  1410),  INT16_C(     0),  INT16_C( 30081), -INT16_C(   670), -INT16_C( 10564), -INT16_C( 29645),  INT16_C(     0), -INT16_C( 11718) } },
    { UINT16_C(37303),
      {  INT16_C(  6598),  INT16_C(   142),  INT16_C(  1259),  INT16_C( 26991), -INT16_C(  3842), -INT16_C( 17698), -INT16_C( 16697),  INT16_C( 16736),
        -INT16_C( 27901),  INT16_C( 17869),  INT16_C( 13710),  INT16_C( 24225), -INT16_C(  3886), -INT16_C( 28991),  INT16_C( 30857),  INT16_C( 20255) },
      { -INT16_C( 21102),  INT16_C( 32079), -INT16_C( 16463), -INT16_C( 20505), -INT16_C( 14929),  INT16_C( 30314), -INT16_C( 13693), -INT16_C( 30793),
        -INT16_C( 31650), -INT16_C(  4916),  INT16_C( 28089), -INT16_C( 29622),  INT16_C(  2909), -INT16_C(  6630),  INT16_C( 14723),  INT16_C(  5430) },
      { -INT16_C( 13693),  INT16_C( 14723), -INT16_C( 29622),  INT16_C(     0),  INT16_C( 14723),  INT16_C( 14723),  INT16_C(     0), -INT16_C( 21102),
        -INT16_C( 20505),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16463),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5430) } },
    { UINT16_C(34278),
      { -INT16_C( 26477),  INT16_C( 31300), -INT16_C(  3001), -INT16_C( 20161), -INT16_C( 15510),  INT16_C(  8828), -INT16_C(  9654),  INT16_C(  5798),
         INT16_C( 24774),  INT16_C(  4227), -INT16_C(  7956),  INT16_C(  1563), -INT16_C( 24890), -INT16_C(   961),  INT16_C(  9652),  INT16_C( 18306) },
      { -INT16_C( 14659),  INT16_C(  1473),  INT16_C(   186),  INT16_C(  9654),  INT16_C( 12995),  INT16_C(  3399), -INT16_C(  4852), -INT16_C( 11741),
        -INT16_C( 22963),  INT16_C( 14818), -INT16_C(   634),  INT16_C( 19775),  INT16_C( 32412),  INT16_C( 20553), -INT16_C( 13404),  INT16_C( 24983) },
      {  INT16_C(     0),  INT16_C( 12995), -INT16_C( 11741),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32412), -INT16_C(   634), -INT16_C(  4852),
        -INT16_C(  4852),  INT16_C(     0),  INT16_C( 32412),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   186) } },
    { UINT16_C(22674),
      {  INT16_C( 19558),  INT16_C(  7512),  INT16_C(  7281), -INT16_C( 18353),  INT16_C( 23593),  INT16_C( 19878), -INT16_C(  3282),  INT16_C(  4595),
         INT16_C( 31277),  INT16_C( 27662), -INT16_C( 21817),  INT16_C(  4331), -INT16_C( 28678), -INT16_C( 28196),  INT16_C( 28400),  INT16_C( 22505) },
      {  INT16_C( 17082),  INT16_C( 11380), -INT16_C( 15522), -INT16_C( 30748), -INT16_C( 30177),  INT16_C( 20180), -INT16_C( 14210), -INT16_C( 21665),
         INT16_C( 27970),  INT16_C(  2327),  INT16_C(   536),  INT16_C(  4633), -INT16_C(  2671), -INT16_C( 32092), -INT16_C( 29341),  INT16_C(  7897) },
      {  INT16_C(     0),  INT16_C( 27970),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2327),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30748),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4633),  INT16_C(   536),  INT16_C(     0),  INT16_C( 17082),  INT16_C(     0) } },
    { UINT16_C(19919),
      {  INT16_C( 11594),  INT16_C( 11792),  INT16_C( 12469), -INT16_C( 30279),  INT16_C( 14206), -INT16_C(  8879), -INT16_C( 27678), -INT16_C(  1718),
         INT16_C( 25244), -INT16_C( 18692), -INT16_C( 29323),  INT16_C(  6571),  INT16_C(  3855), -INT16_C(  5978),  INT16_C( 30253),  INT16_C( 30517) },
      {  INT16_C( 18083),  INT16_C( 22693),  INT16_C( 24182), -INT16_C(  2846),  INT16_C( 13205),  INT16_C( 30673),  INT16_C(  7111),  INT16_C( 25457),
         INT16_C( 28030), -INT16_C(  3303), -INT16_C( 14854),  INT16_C(  2572), -INT16_C( 19756),  INT16_C(   498),  INT16_C( 10280), -INT16_C( 13192) },
      { -INT16_C( 14854),  INT16_C( 18083),  INT16_C( 30673), -INT16_C(  3303),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24182), -INT16_C( 14854),
        -INT16_C( 19756),  INT16_C(     0),  INT16_C( 30673),  INT16_C(  2572),  INT16_C(     0),  INT16_C(     0),  INT16_C(   498),  INT16_C(     0) } },
    { UINT16_C( 7534),
      { -INT16_C(  7132),  INT16_C(  1660),  INT16_C(  4568), -INT16_C( 22214),  INT16_C(   393), -INT16_C(  1340),  INT16_C( 16996),  INT16_C( 32359),
         INT16_C( 24885),  INT16_C( 16707),  INT16_C(  5995),  INT16_C( 24308),  INT16_C(  7192), -INT16_C( 28538), -INT16_C(  2840),  INT16_C(  3501) },
      {  INT16_C( 10712), -INT16_C( 20461),  INT16_C( 19771), -INT16_C( 15271),  INT16_C(  7502), -INT16_C( 19522),  INT16_C(  9568), -INT16_C( 27343),
         INT16_C( 29830), -INT16_C(  3369), -INT16_C( 13429), -INT16_C( 23728), -INT16_C( 10521), -INT16_C( 12237), -INT16_C(  7990), -INT16_C( 23843) },
      {  INT16_C(     0), -INT16_C( 10521),  INT16_C( 29830), -INT16_C( 13429),  INT16_C(     0),  INT16_C(  7502),  INT16_C(  7502),  INT16_C(     0),
        -INT16_C( 19522),  INT16_C(     0), -INT16_C( 23728),  INT16_C(  7502),  INT16_C( 29830),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(61450),
      {  INT16_C( 17746), -INT16_C( 21698), -INT16_C( 29687), -INT16_C( 14392),  INT16_C( 10303),  INT16_C( 28908),  INT16_C( 29374), -INT16_C( 27164),
         INT16_C( 28516), -INT16_C( 19360),  INT16_C( 18194),  INT16_C( 17802),  INT16_C( 21527), -INT16_C(  3034),  INT16_C( 12534),  INT16_C( 18661) },
      {  INT16_C(  9077),  INT16_C( 32499), -INT16_C( 17233), -INT16_C(  4283),  INT16_C( 12772), -INT16_C( 23969),  INT16_C( 17571),  INT16_C(  2103),
        -INT16_C( 26701), -INT16_C( 14660),  INT16_C( 18399), -INT16_C(  2549),  INT16_C( 12699), -INT16_C( 27925), -INT16_C( 12191), -INT16_C( 10534) },
      {  INT16_C(     0), -INT16_C( 12191),  INT16_C(     0), -INT16_C( 26701),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2103),  INT16_C( 17571),  INT16_C( 17571), -INT16_C( 23969) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_permutexvar_epi16(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_permutexvar_epi16(k, idx, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutexvar_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t idx[8];
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1307444235), -INT32_C(  1706430584), -INT32_C(   604486448), -INT32_C(  1741113544), -INT32_C(   524345514),  INT32_C(  1817309466), -INT32_C(  1187810749),  INT32_C(  1039629383) },
      { -INT32_C(     1111689), -INT32_C(   929482504), -INT32_C(  1264348804), -INT32_C(  1622287543),  INT32_C(   343870714),  INT32_C(  1082183933), -INT32_C(  1963281597), -INT32_C(  1496846033) },
      {  INT32_C(  1082183933), -INT32_C(     1111689), -INT32_C(     1111689), -INT32_C(     1111689), -INT32_C(  1963281597), -INT32_C(  1264348804), -INT32_C(  1622287543), -INT32_C(  1496846033) } },
    { { -INT32_C(   223954950),  INT32_C(  1824145391),  INT32_C(   438328785),  INT32_C(   867790137),  INT32_C(  2001222010),  INT32_C(  1287178249), -INT32_C(  1411927428), -INT32_C(  1638752605) },
      {  INT32_C(  1167128661),  INT32_C(   145836855), -INT32_C(   517811800), -INT32_C(  1189749697),  INT32_C(   506486037), -INT32_C(  1586763739),  INT32_C(  1045250714),  INT32_C(   920428512) },
      { -INT32_C(   517811800),  INT32_C(   920428512),  INT32_C(   145836855),  INT32_C(   145836855), -INT32_C(   517811800),  INT32_C(   145836855),  INT32_C(   506486037), -INT32_C(  1189749697) } },
    { { -INT32_C(   830772073),  INT32_C(  1624714423),  INT32_C(  1010956797), -INT32_C(   353020203), -INT32_C(   653711693), -INT32_C(  1451592690), -INT32_C(  1763194954), -INT32_C(    36912282) },
      { -INT32_C(   406042833),  INT32_C(  1900520307),  INT32_C(  1923975324), -INT32_C(  1839422497), -INT32_C(   680827447), -INT32_C(  1887377703),  INT32_C(   338061229),  INT32_C(  1511125546) },
      {  INT32_C(  1511125546),  INT32_C(  1511125546), -INT32_C(  1887377703), -INT32_C(  1887377703), -INT32_C(  1839422497),  INT32_C(   338061229),  INT32_C(   338061229),  INT32_C(   338061229) } },
    { { -INT32_C(  1388192454),  INT32_C(   488540288), -INT32_C(   275788784),  INT32_C(   948104047),  INT32_C(   705686865), -INT32_C(  2118479661),  INT32_C(   580247799),  INT32_C(   209495762) },
      {  INT32_C(    79347076),  INT32_C(  1428281413),  INT32_C(   323334308), -INT32_C(   313800804), -INT32_C(  2011735116), -INT32_C(   502672917), -INT32_C(  2080072015), -INT32_C(   930054076) },
      {  INT32_C(   323334308),  INT32_C(    79347076),  INT32_C(    79347076), -INT32_C(   930054076),  INT32_C(  1428281413), -INT32_C(   313800804), -INT32_C(   930054076),  INT32_C(   323334308) } },
    { { -INT32_C(  2100475331), -INT32_C(   942084573),  INT32_C(  1004215711), -INT32_C(  1742199068),  INT32_C(  1814052737), -INT32_C(  1034999535),  INT32_C(   205935559),  INT32_C(   299161556) },
      {  INT32_C(  1150591265),  INT32_C(   789343376),  INT32_C(  1835722633), -INT32_C(  1895460339), -INT32_C(   486857007),  INT32_C(   396708431),  INT32_C(  1914956702), -INT32_C(   461113406) },
      {  INT32_C(   396708431), -INT32_C(  1895460339), -INT32_C(   461113406), -INT32_C(   486857007),  INT32_C(   789343376),  INT32_C(   789343376), -INT32_C(   461113406), -INT32_C(   486857007) } },
    { {  INT32_C(   690493337),  INT32_C(   207107203),  INT32_C(   695845403),  INT32_C(   632848212), -INT32_C(   200756315), -INT32_C(  1676956162),  INT32_C(  1527656088), -INT32_C(  1086353114) },
      {  INT32_C(   753428393), -INT32_C(  1220984676),  INT32_C(  1457566210), -INT32_C(   696543183),  INT32_C(  1254851404), -INT32_C(   907618768),  INT32_C(   723842053),  INT32_C(   787112837) },
      { -INT32_C(  1220984676), -INT32_C(   696543183), -INT32_C(   696543183),  INT32_C(  1254851404), -INT32_C(   907618768),  INT32_C(   723842053),  INT32_C(   753428393),  INT32_C(   723842053) } },
    { {  INT32_C(  1717293770),  INT32_C(   337548306),  INT32_C(  2020277830), -INT32_C(   481368681), -INT32_C(  1725097623), -INT32_C(   178121744), -INT32_C(  1944025593), -INT32_C(  1262810391) },
      { -INT32_C(   300280100), -INT32_C(   268289878), -INT32_C(   832017353), -INT32_C(  1162758319), -INT32_C(  1068179760), -INT32_C(   122308879),  INT32_C(   646239549), -INT32_C(  1143324705) },
      { -INT32_C(   832017353), -INT32_C(   832017353),  INT32_C(   646239549), -INT32_C(  1143324705), -INT32_C(   268289878), -INT32_C(   300280100), -INT32_C(  1143324705), -INT32_C(   268289878) } },
    { { -INT32_C(     5638827),  INT32_C(  1693494061),  INT32_C(  1764907031), -INT32_C(   534519025), -INT32_C(  1298106431),  INT32_C(  1806325294),  INT32_C(   194064171), -INT32_C(   993629074) },
      { -INT32_C(  1899794335),  INT32_C(   871609115),  INT32_C(   463217932), -INT32_C(   889471223),  INT32_C(  1702730807),  INT32_C(   500180978), -INT32_C(   987209386),  INT32_C(   780791757) },
      {  INT32_C(   500180978),  INT32_C(   500180978),  INT32_C(   780791757),  INT32_C(   780791757),  INT32_C(   871609115), -INT32_C(   987209386), -INT32_C(   889471223), -INT32_C(   987209386) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_permutexvar_epi32(idx, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_permutexvar_epi32(idx, a);

    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutexvar_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t idx[8];
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  2059226207),  INT32_C(   212709376), -INT32_C(   567850539),  INT32_C(  1084826377), -INT32_C(  1314576705), -INT32_C(  1529973427), -INT32_C(  1536559146),  INT32_C(  1171452646) },
      UINT8_C( 62),
      {  INT32_C(  1061076879), -INT32_C(  1240118675), -INT32_C(  1782582414), -INT32_C(  1034616932),  INT32_C(   420480420), -INT32_C(   890194733),  INT32_C(   263230493), -INT32_C(   162663066) },
      {  INT32_C(   573934773),  INT32_C(  1222134486), -INT32_C(   623011778),  INT32_C(  1016934807),  INT32_C(   173387062),  INT32_C(  2127840609),  INT32_C(  1083016665),  INT32_C(   792124026) },
      {  INT32_C(  2059226207),  INT32_C(  2127840609), -INT32_C(   623011778),  INT32_C(   173387062),  INT32_C(   173387062),  INT32_C(  1016934807), -INT32_C(  1536559146),  INT32_C(  1171452646) } },
    { {  INT32_C(  1028746086), -INT32_C(   192599370),  INT32_C(  1506698178), -INT32_C(   879400044),  INT32_C(  2044062488),  INT32_C(   184002864), -INT32_C(  1454734290), -INT32_C(   975667105) },
      UINT8_C(235),
      {  INT32_C(  1419837994), -INT32_C(   350841464), -INT32_C(   813731996), -INT32_C(   253212155), -INT32_C(   920624865), -INT32_C(   571004327), -INT32_C(   197353356), -INT32_C(  1545600391) },
      { -INT32_C(  1929936636),  INT32_C(  2071399703), -INT32_C(  2125793412),  INT32_C(  1634808385), -INT32_C(   315977068),  INT32_C(   835330492),  INT32_C(   992282562),  INT32_C(   232654089) },
      { -INT32_C(  2125793412), -INT32_C(  1929936636),  INT32_C(  1506698178),  INT32_C(   835330492),  INT32_C(  2044062488),  INT32_C(  2071399703), -INT32_C(   315977068),  INT32_C(  2071399703) } },
    { { -INT32_C(  1634019961),  INT32_C(  1578701282),  INT32_C(  1256219400),  INT32_C(   715870614), -INT32_C(  1609050653), -INT32_C(  1194204682), -INT32_C(   235669784), -INT32_C(  2080386564) },
      UINT8_C(166),
      { -INT32_C(  1433919079), -INT32_C(  1649154246),  INT32_C(   406060487),  INT32_C(  2113691048),  INT32_C(  1450417268),  INT32_C(  1665018989), -INT32_C(   245420001), -INT32_C(   929570257) },
      {  INT32_C(  1030889475), -INT32_C(   824498937), -INT32_C(   890892766), -INT32_C(   532159892), -INT32_C(   348734594),  INT32_C(   105870823), -INT32_C(   721965403), -INT32_C(  1801678959) },
      { -INT32_C(  1634019961), -INT32_C(   890892766), -INT32_C(  1801678959),  INT32_C(   715870614), -INT32_C(  1609050653),  INT32_C(   105870823), -INT32_C(   235669784), -INT32_C(  1801678959) } },
    { { -INT32_C(  1227747665),  INT32_C(  1451535668),  INT32_C(   656501435), -INT32_C(   888641459),  INT32_C(   179781155),  INT32_C(  1477510835),  INT32_C(  1160513716),  INT32_C(  1188743319) },
      UINT8_C(215),
      {  INT32_C(  1493957804), -INT32_C(   350985856), -INT32_C(   348636030), -INT32_C(  2113010876), -INT32_C(  1070196294),  INT32_C(   846564906), -INT32_C(  2083865925),  INT32_C(  1079644308) },
      { -INT32_C(  1919326963),  INT32_C(  1232645831),  INT32_C(   775205098),  INT32_C(  1857045428), -INT32_C(  2043681188),  INT32_C(   817407093), -INT32_C(   206339490), -INT32_C(  1607266669) },
      { -INT32_C(  2043681188), -INT32_C(  1919326963),  INT32_C(   775205098), -INT32_C(   888641459),  INT32_C(   775205098),  INT32_C(  1477510835),  INT32_C(  1857045428), -INT32_C(  2043681188) } },
    { {  INT32_C(   976080243),  INT32_C(  1703192187),  INT32_C(   177453142),  INT32_C(  1467565051), -INT32_C(  1612863446), -INT32_C(  1429236148), -INT32_C(  1415740904),  INT32_C(    72077712) },
      UINT8_C(158),
      {  INT32_C(   521748089),  INT32_C(  2071297730),  INT32_C(  1417052177), -INT32_C(  1585524999),  INT32_C(  1106058667),  INT32_C(  1868208108),  INT32_C(   117376309), -INT32_C(   895220911) },
      {  INT32_C(    82427202),  INT32_C(  1283415611), -INT32_C(   677316898),  INT32_C(  1870143428),  INT32_C(   699491644),  INT32_C(   848825341),  INT32_C(  1631098640), -INT32_C(   584328037) },
      {  INT32_C(   976080243), -INT32_C(   677316898),  INT32_C(  1283415611),  INT32_C(  1283415611),  INT32_C(  1870143428), -INT32_C(  1429236148), -INT32_C(  1415740904),  INT32_C(  1283415611) } },
    { { -INT32_C(   723446631),  INT32_C(  1361076595),  INT32_C(   455721047),  INT32_C(   478847455),  INT32_C(    71645959),  INT32_C(  1463213382),  INT32_C(   263745140), -INT32_C(   471014326) },
      UINT8_C(248),
      {  INT32_C(   795588558), -INT32_C(  1752777257), -INT32_C(  2022202906),  INT32_C(  1737397035), -INT32_C(  1246915880),  INT32_C(   908657864), -INT32_C(  1585432131), -INT32_C(   208051419) },
      { -INT32_C(   249428710), -INT32_C(  1467373374),  INT32_C(  1966014537),  INT32_C(  1809628819),  INT32_C(   421562704),  INT32_C(  1263487374), -INT32_C(  1460875134),  INT32_C(  1318815027) },
      { -INT32_C(   723446631),  INT32_C(  1361076595),  INT32_C(   455721047),  INT32_C(  1809628819), -INT32_C(   249428710), -INT32_C(   249428710),  INT32_C(  1263487374),  INT32_C(  1263487374) } },
    { {  INT32_C(  1279245962), -INT32_C(  1326135194),  INT32_C(  1529160904),  INT32_C(   851837410),  INT32_C(   407627402), -INT32_C(  1302095056), -INT32_C(  1638248597),  INT32_C(  1609365205) },
      UINT8_C(180),
      { -INT32_C(   199578580), -INT32_C(   994194784), -INT32_C(   257550097), -INT32_C(   981739041), -INT32_C(  1074425052),  INT32_C(  1177200887), -INT32_C(   132396798), -INT32_C(   508789835) },
      { -INT32_C(   942225625), -INT32_C(  2121493615), -INT32_C(  1972292949),  INT32_C(   810609675),  INT32_C(  2012169600), -INT32_C(   256042259), -INT32_C(  1729570333),  INT32_C(  2071631188) },
      {  INT32_C(  1279245962), -INT32_C(  1326135194),  INT32_C(  2071631188),  INT32_C(   851837410),  INT32_C(  2012169600),  INT32_C(  2071631188), -INT32_C(  1638248597), -INT32_C(   256042259) } },
    { { -INT32_C(   314421156), -INT32_C(  1905340701),  INT32_C(   203022337),  INT32_C(  1279027660), -INT32_C(  1664930642),  INT32_C(   697073990), -INT32_C(  1363053478),  INT32_C(  1697200905) },
      UINT8_C(139),
      {  INT32_C(   980308843), -INT32_C(  1589903935),  INT32_C(  2137933590), -INT32_C(  1339180412), -INT32_C(      603778), -INT32_C(   900128939),  INT32_C(   483592160), -INT32_C(  1683539664) },
      {  INT32_C(  1305810572),  INT32_C(   703533075), -INT32_C(   592945832), -INT32_C(  1785932521), -INT32_C(   191593825), -INT32_C(  2118193759),  INT32_C(   614306548),  INT32_C(  1472218571) },
      { -INT32_C(  1785932521),  INT32_C(   703533075),  INT32_C(   203022337), -INT32_C(   191593825), -INT32_C(  1664930642),  INT32_C(   697073990), -INT32_C(  1363053478),  INT32_C(  1305810572) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_permutexvar_epi32(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_permutexvar_epi32(src, k, idx, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutexvar_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t idx[8];
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C( 91),
      { -INT32_C(  1502698347), -INT32_C(   251750509),  INT32_C(   336124479), -INT32_C(   390881946),  INT32_C(   529115186), -INT32_C(   132904346), -INT32_C(   305973080), -INT32_C(  1907877128) },
      {  INT32_C(  1379186367), -INT32_C(  1941753267),  INT32_C(  1923107596),  INT32_C(   442127592),  INT32_C(  1648026620), -INT32_C(  1789178131),  INT32_C(  2139233926), -INT32_C(   133313991) },
      { -INT32_C(  1789178131),  INT32_C(   442127592),  INT32_C(           0),  INT32_C(  2139233926),  INT32_C(  1923107596),  INT32_C(           0),  INT32_C(  1379186367),  INT32_C(           0) } },
    { UINT8_C(128),
      {  INT32_C(  1942833729), -INT32_C(   662742643),  INT32_C(  1321333242),  INT32_C(   776657739),  INT32_C(  1662757909),  INT32_C(   652914951), -INT32_C(    27301581), -INT32_C(  1216456842) },
      {  INT32_C(   791301281), -INT32_C(  1626887771), -INT32_C(   437401446), -INT32_C(  1189922908), -INT32_C(   350408988),  INT32_C(   319883231), -INT32_C(   435064720),  INT32_C(  1771933639) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   435064720) } },
    { UINT8_C(219),
      {  INT32_C(  1887541447),  INT32_C(  1745494175),  INT32_C(  1158475534),  INT32_C(   808043778), -INT32_C(   384821790), -INT32_C(  1755765978), -INT32_C(  1017233612), -INT32_C(  1549809700) },
      { -INT32_C(    15523745),  INT32_C(  1315380544),  INT32_C(   244609804),  INT32_C(   457162040), -INT32_C(   117157934), -INT32_C(  1500488078),  INT32_C(  2053762717),  INT32_C(   354224310) },
      {  INT32_C(   354224310),  INT32_C(   354224310),  INT32_C(           0),  INT32_C(   244609804),  INT32_C(   244609804),  INT32_C(           0), -INT32_C(   117157934), -INT32_C(   117157934) } },
    { UINT8_C( 40),
      {  INT32_C(  1315509297), -INT32_C(   295979141),  INT32_C(   153577803), -INT32_C(   136625496), -INT32_C(  1536568250),  INT32_C(  1396838244), -INT32_C(  2130068359),  INT32_C(   178921177) },
      { -INT32_C(  1369894093),  INT32_C(   379434186), -INT32_C(   970996707),  INT32_C(  1287518726),  INT32_C(   871442383), -INT32_C(  1350159562), -INT32_C(   936275985), -INT32_C(   506209362) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1369894093),  INT32_C(           0),  INT32_C(   871442383),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(238),
      { -INT32_C(   524775636), -INT32_C(   251802068), -INT32_C(   386481171), -INT32_C(  1464384639),  INT32_C(  1742662196),  INT32_C(     5672561), -INT32_C(  1699864897),  INT32_C(   495489009) },
      {  INT32_C(  1274888223), -INT32_C(    63112433),  INT32_C(  1071919806), -INT32_C(  1444439179), -INT32_C(   149895546),  INT32_C(   334980692),  INT32_C(  1991091845),  INT32_C(  1418999093) },
      {  INT32_C(           0), -INT32_C(   149895546),  INT32_C(   334980692), -INT32_C(    63112433),  INT32_C(           0), -INT32_C(    63112433),  INT32_C(  1418999093), -INT32_C(    63112433) } },
    { UINT8_C(117),
      { -INT32_C(  1937465199),  INT32_C(   239829468),  INT32_C(    25463397),  INT32_C(   948383090), -INT32_C(  1534296514),  INT32_C(   455712629), -INT32_C(  2125356980), -INT32_C(   973691596) },
      {  INT32_C(   559053637),  INT32_C(  1630576124), -INT32_C(  1721584601),  INT32_C(   533850593), -INT32_C(   574333593),  INT32_C(  1224273404), -INT32_C(  1043773043),  INT32_C(   881311983) },
      {  INT32_C(  1630576124),  INT32_C(           0),  INT32_C(  1224273404),  INT32_C(           0), -INT32_C(  1043773043),  INT32_C(  1224273404), -INT32_C(   574333593),  INT32_C(           0) } },
    { UINT8_C( 59),
      {  INT32_C(  1983338201),  INT32_C(   983406726), -INT32_C(   467978245),  INT32_C(  1716271880), -INT32_C(   329111041),  INT32_C(  1803201313),  INT32_C(   878328692), -INT32_C(  1687187774) },
      {  INT32_C(  1779541732),  INT32_C(   983871295), -INT32_C(   299974426), -INT32_C(    95130885), -INT32_C(  1243170925), -INT32_C(   702521246),  INT32_C(  1577810588), -INT32_C(   302351864) },
      {  INT32_C(   983871295),  INT32_C(  1577810588),  INT32_C(           0),  INT32_C(  1779541732), -INT32_C(   302351864),  INT32_C(   983871295),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 33),
      { -INT32_C(  1168091381), -INT32_C(  1130325252),  INT32_C(   599232440), -INT32_C(  1699302941), -INT32_C(   117675113),  INT32_C(    93639563),  INT32_C(  1477374686), -INT32_C(   126223380) },
      {  INT32_C(  1320343890),  INT32_C(   738874227), -INT32_C(   984628766),  INT32_C(   174065010), -INT32_C(    66954127),  INT32_C(   218273327),  INT32_C(  1969623176),  INT32_C(  1567481611) },
      {  INT32_C(   174065010),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   174065010),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_permutexvar_epi32(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_permutexvar_epi32(k, idx, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutexvar_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t idx[4];
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[8] = {
    { {  INT64_C( 3465447535646586345),  INT64_C( 3112574604386585021), -INT64_C( 3298717360923514682),  INT64_C( 5323359623116614530) },
      {  INT64_C( 5940711443930208020), -INT64_C( 6109672874813763858),  INT64_C( 1105777252857738108),  INT64_C( 5770626510813846893) },
      { -INT64_C( 6109672874813763858), -INT64_C( 6109672874813763858),  INT64_C( 1105777252857738108),  INT64_C( 1105777252857738108) } },
    { {  INT64_C( 3900401264022889273), -INT64_C( 7755349089616591920), -INT64_C( 7492176496441054870),  INT64_C( 2727909151360780622) },
      {  INT64_C( 4511785965612985374), -INT64_C( 4628483991183106535), -INT64_C( 7007675447010468101), -INT64_C( 4803647970284657595) },
      { -INT64_C( 4628483991183106535),  INT64_C( 4511785965612985374), -INT64_C( 7007675447010468101), -INT64_C( 7007675447010468101) } },
    { {  INT64_C( 8654722626887043695),  INT64_C( 6607463866478169758),  INT64_C( 7654221770983106635), -INT64_C( 3115662575998901914) },
      {  INT64_C( 4977548128634988091),  INT64_C( 8473499790535605467), -INT64_C( 4403595353433040557), -INT64_C( 6060566984611365205) },
      { -INT64_C( 6060566984611365205), -INT64_C( 4403595353433040557), -INT64_C( 6060566984611365205), -INT64_C( 4403595353433040557) } },
    { {  INT64_C( 4565342033187083888), -INT64_C( 3263400542231358442), -INT64_C( 4951375666792905173),  INT64_C(  777064012164305068) },
      {  INT64_C( 9217034901363166790), -INT64_C( 6745700139769306096), -INT64_C( 8716872267551101636), -INT64_C( 4096186034266254718) },
      {  INT64_C( 9217034901363166790), -INT64_C( 8716872267551101636), -INT64_C( 4096186034266254718),  INT64_C( 9217034901363166790) } },
    { { -INT64_C( 3070791090430719878), -INT64_C( 3181573684470668865), -INT64_C(  732355612710600332),  INT64_C( 7007947256713345784) },
      { -INT64_C( 3666591945649245566), -INT64_C( 4813825418525965625),  INT64_C( 7945724640348623068),  INT64_C( 1415301886787475293) },
      {  INT64_C( 7945724640348623068),  INT64_C( 1415301886787475293), -INT64_C( 3666591945649245566), -INT64_C( 3666591945649245566) } },
    { {  INT64_C( 6248314088218945755),  INT64_C( 8070704056713394682),  INT64_C( 5411923700867861558),  INT64_C(  648293139388236634) },
      { -INT64_C( 3746810366719337956), -INT64_C( 3358542259622529696), -INT64_C( 9127219581637745893),  INT64_C( 3734164790968116381) },
      {  INT64_C( 3734164790968116381), -INT64_C( 9127219581637745893), -INT64_C( 9127219581637745893), -INT64_C( 9127219581637745893) } },
    { { -INT64_C( 3862999505957895227), -INT64_C( 7205721465562434925), -INT64_C( 5265557781999092155), -INT64_C( 8490883141550974497) },
      {  INT64_C( 8811721370948929557),  INT64_C( 7932431214771177463), -INT64_C( 7640982706706597081), -INT64_C( 2563191643271564001) },
      {  INT64_C( 7932431214771177463), -INT64_C( 2563191643271564001),  INT64_C( 7932431214771177463), -INT64_C( 2563191643271564001) } },
    { {  INT64_C(  801258192282292158), -INT64_C( 7619357814459938901),  INT64_C(  117599237026749525), -INT64_C( 6780922528876188351) },
      { -INT64_C( 8070339593422618399),  INT64_C( 8372656936451409195),  INT64_C( 1487915019302602691), -INT64_C( 4696126461883675825) },
      {  INT64_C( 1487915019302602691), -INT64_C( 4696126461883675825),  INT64_C( 8372656936451409195),  INT64_C( 8372656936451409195) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_permutexvar_epi64(idx, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_permutexvar_epi64(idx, a);

    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutexvar_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t idx[4];
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[8] = {
    { { -INT64_C( 6145245807815484862), -INT64_C( 8661416298178864072), -INT64_C( 4727139763093681026), -INT64_C( 4181093611599723938) },
      UINT8_C(224),
      { -INT64_C( 4568891220371182420),  INT64_C(  595615055643734095),  INT64_C( 9037376429611259449),  INT64_C( 5533734961594607142) },
      { -INT64_C( 9000649239165130061), -INT64_C( 2163542389232657355), -INT64_C( 3775044921414815709),  INT64_C( 1723614651087298047) },
      { -INT64_C( 6145245807815484862), -INT64_C( 8661416298178864072), -INT64_C( 4727139763093681026), -INT64_C( 4181093611599723938) } },
    { {  INT64_C( 1325331378370156717),  INT64_C( 6821541915016801569), -INT64_C( 1162463134921942931), -INT64_C( 4309247653774977609) },
      UINT8_C( 18),
      { -INT64_C( 5312276096657414752),  INT64_C( 6011548742202757124), -INT64_C(  892782143459852084), -INT64_C( 8552951516681816127) },
      {  INT64_C( 4698651055233121396),  INT64_C( 4617508433955005702),  INT64_C( 5512619848525830191), -INT64_C( 3535935548222305414) },
      {  INT64_C( 1325331378370156717),  INT64_C( 4698651055233121396), -INT64_C( 1162463134921942931), -INT64_C( 4309247653774977609) } },
    { { -INT64_C( 7453033442925831150), -INT64_C( 5594756606993968218), -INT64_C( 4711116760529534522),  INT64_C(  969134818784781899) },
      UINT8_C(170),
      { -INT64_C( 4474372485495890496), -INT64_C( 2349483318866410961),  INT64_C( 8737231027810055477),  INT64_C( 1782442867293545731) },
      { -INT64_C(  248188577289471777), -INT64_C(  251639970792811965), -INT64_C( 8538770441765804877),  INT64_C( 6307104878424159510) },
      { -INT64_C( 7453033442925831150),  INT64_C( 6307104878424159510), -INT64_C( 4711116760529534522),  INT64_C( 6307104878424159510) } },
    { {  INT64_C( 7285050831330992463),  INT64_C( 7226457372175610757), -INT64_C( 8990332279521068244),  INT64_C( 8913038368937531105) },
      UINT8_C( 90),
      {  INT64_C( 7210230780587186390), -INT64_C( 2261517686396330775),  INT64_C( 7039918466464043237), -INT64_C( 7812045795274912574) },
      { -INT64_C( 2470739017216552287),  INT64_C( 3030337906147249031), -INT64_C( 1429421007458051524),  INT64_C( 7064387224332711865) },
      {  INT64_C( 7285050831330992463),  INT64_C( 3030337906147249031), -INT64_C( 8990332279521068244), -INT64_C( 1429421007458051524) } },
    { { -INT64_C( 2764529222298622256),  INT64_C( 1847905064078209334),  INT64_C(  541849563344969838),  INT64_C( 4315441763754880448) },
      UINT8_C(173),
      { -INT64_C( 7765937887782174569), -INT64_C(  405453318237604642),  INT64_C( 3041144148134000746),  INT64_C( 3459838291440154062) },
      { -INT64_C( 5185776384920649007),  INT64_C( 7886938757980059936), -INT64_C( 2618818936096834303), -INT64_C( 2408243768127898165) },
      { -INT64_C( 2408243768127898165),  INT64_C( 1847905064078209334), -INT64_C( 2618818936096834303), -INT64_C( 2618818936096834303) } },
    { {  INT64_C( 5964835402527458869),  INT64_C( 8882295261415371219),  INT64_C(  569038202891478525),  INT64_C( 9208453081059759838) },
      UINT8_C(197),
      { -INT64_C( 4086373076156576228), -INT64_C( 8479226529983684331),  INT64_C( 6427988257266884277),  INT64_C(  503315643414814520) },
      {  INT64_C( 6038701740289553584),  INT64_C( 9212390983602867944), -INT64_C( 6631821568448815526),  INT64_C( 7861269252833712681) },
      {  INT64_C( 6038701740289553584),  INT64_C( 8882295261415371219),  INT64_C( 9212390983602867944),  INT64_C( 9208453081059759838) } },
    { {  INT64_C( 4997660079327253962),  INT64_C( 6600424377078187087), -INT64_C( 6838733108989563127), -INT64_C( 7875444692090556021) },
      UINT8_C( 98),
      { -INT64_C(  452606310463071704), -INT64_C( 2662941931776388457), -INT64_C( 8662122382630879411), -INT64_C( 1308328928534916951) },
      {  INT64_C( 3632450635218458235),  INT64_C(  299560531238675169),  INT64_C( 1863939872889404352), -INT64_C( 8516757631211197156) },
      {  INT64_C( 4997660079327253962), -INT64_C( 8516757631211197156), -INT64_C( 6838733108989563127), -INT64_C( 7875444692090556021) } },
    { {  INT64_C( 1426060201470534909),  INT64_C(   36178607548202948), -INT64_C( 1545239560821751292), -INT64_C( 9153397452835185311) },
      UINT8_C(189),
      { -INT64_C( 2154968146796144399), -INT64_C( 2958827486221003933),  INT64_C( 1085243208166040697),  INT64_C( 7543269306760658521) },
      {  INT64_C(  428357227795750444), -INT64_C( 5813618019834719129), -INT64_C( 2573969351176751803),  INT64_C( 1930493853078313706) },
      { -INT64_C( 5813618019834719129),  INT64_C(   36178607548202948), -INT64_C( 5813618019834719129), -INT64_C( 5813618019834719129) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_permutexvar_epi64(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_permutexvar_epi64(src, k, idx, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutexvar_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t idx[4];
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[8] = {
    { UINT8_C( 27),
      {  INT64_C( 3369187414697126278), -INT64_C( 9018154180520100685),  INT64_C( 3731480067352891761),  INT64_C( 8739300992515910063) },
      {  INT64_C( 8839886327673718116), -INT64_C( 7430403753900109103),  INT64_C( 8684416486551775225),  INT64_C( 5176022328699823975) },
      {  INT64_C( 8684416486551775225),  INT64_C( 5176022328699823975),  INT64_C(                   0),  INT64_C( 5176022328699823975) } },
    { UINT8_C(241),
      { -INT64_C( 8787030352415111512),  INT64_C( 3900474958566747456), -INT64_C( 6962152737219906629),  INT64_C( 4105534155763399707) },
      {  INT64_C( 2632500097026732431),  INT64_C( 3924444501427107313),  INT64_C(  466283003580020192),  INT64_C( 5914923698406488653) },
      {  INT64_C( 2632500097026732431),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(184),
      {  INT64_C( 1369588916891178379),  INT64_C( 3268422251213373709), -INT64_C( 6353981294143589132),  INT64_C( 5903301870556524589) },
      {  INT64_C( 6269963180229888274),  INT64_C( 5370593499786940835), -INT64_C( 1317405420199894686), -INT64_C(  979236192142679470) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5370593499786940835) } },
    { UINT8_C(150),
      {  INT64_C( 8561405448582914762),  INT64_C( 6168547978405161738), -INT64_C( 8946116566893352219),  INT64_C( 2722238345616027939) },
      { -INT64_C( 1544134480098121929),  INT64_C( 6365483424972692813), -INT64_C( 8048574177363399832),  INT64_C( 4334863096951648425) },
      {  INT64_C(                   0), -INT64_C( 8048574177363399832),  INT64_C( 6365483424972692813),  INT64_C(                   0) } },
    { UINT8_C( 47),
      {  INT64_C( 5181665057797199994), -INT64_C( 6178918623323952869),  INT64_C(  527668101296622321), -INT64_C(  567936792988461464) },
      {  INT64_C( 4670650789240516000), -INT64_C( 8047833996201456538),  INT64_C( 8629332360195303267), -INT64_C( 5379121953059189278) },
      {  INT64_C( 8629332360195303267), -INT64_C( 5379121953059189278), -INT64_C( 8047833996201456538),  INT64_C( 4670650789240516000) } },
    { UINT8_C(178),
      { -INT64_C( 7075410026506534931),  INT64_C( 3237749231414113585),  INT64_C( 3995733465180645381),  INT64_C( 1823960239742767897) },
      {  INT64_C( 8138094958596007746), -INT64_C(  235900256028775481), -INT64_C( 4597330073135221615), -INT64_C( 4316226894482734893) },
      {  INT64_C(                   0), -INT64_C(  235900256028775481),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(213),
      {  INT64_C( 3726312010818066332), -INT64_C( 1082228419914480768), -INT64_C( 6231197197802146125),  INT64_C( 4339764287597479605) },
      {  INT64_C( 6071664643769323016),  INT64_C( 4976962000991906853), -INT64_C( 5295530570217379409), -INT64_C( 6421479277348671995) },
      {  INT64_C( 6071664643769323016),  INT64_C(                   0), -INT64_C( 6421479277348671995),  INT64_C(                   0) } },
    { UINT8_C(160),
      {  INT64_C( 7283667468859782669), -INT64_C( 1086144558918060667), -INT64_C(  740096361840458443),  INT64_C( 5742998000986513344) },
      {  INT64_C( 8380728246458525680), -INT64_C( 5134209665999944312),  INT64_C( 1630908168763388005),  INT64_C( 6996021448102459014) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_permutexvar_epi64(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_permutexvar_epi64(k, idx, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t idx[32];
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  68), -INT8_C(  19),  INT8_C( 106),  INT8_C(  42),  INT8_C(  79),  INT8_C(  38),  INT8_C(  16), -INT8_C( 110),
         INT8_C(  30), -INT8_C( 123), -INT8_C(  25), -INT8_C(  91), -INT8_C( 106),  INT8_C(  84), -INT8_C(  99),  INT8_C(  86),
         INT8_C( 104), -INT8_C(   2),  INT8_C(  83),  INT8_C(  91),  INT8_C( 103),  INT8_C(   0),  INT8_C(  29), -INT8_C(  11),
        -INT8_C(  51), -INT8_C(  11),  INT8_C(  85),  INT8_C(  85),  INT8_C( 102), -INT8_C(  55), -INT8_C(  18), -INT8_C(  86) },
      { -INT8_C(  74),  INT8_C(  88), -INT8_C(  44),  INT8_C(   5),  INT8_C( 126), -INT8_C(  27), -INT8_C( 105), -INT8_C( 100),
         INT8_C( 106),      INT8_MAX,  INT8_C(  65),  INT8_C(   0), -INT8_C(  45), -INT8_C(  33),  INT8_C(  87),  INT8_C(  59),
        -INT8_C(  35), -INT8_C(  86), -INT8_C( 106),  INT8_C(  68), -INT8_C(  86), -INT8_C(  77),  INT8_C(  57),  INT8_C( 120),
        -INT8_C(  88), -INT8_C( 113), -INT8_C(  51),  INT8_C(  14),  INT8_C(  88), -INT8_C(  69), -INT8_C(  71),  INT8_C(  14) },
      {  INT8_C( 126), -INT8_C(  33),  INT8_C(  65),  INT8_C(  65),  INT8_C(  59), -INT8_C( 105), -INT8_C(  35), -INT8_C( 106),
        -INT8_C(  71), -INT8_C(  27), -INT8_C( 100), -INT8_C(  27),  INT8_C(  57), -INT8_C(  86), -INT8_C(  69),  INT8_C(  57),
         INT8_C( 106), -INT8_C(  71),  INT8_C(  68),  INT8_C(  14), -INT8_C( 100), -INT8_C(  74), -INT8_C(  69), -INT8_C(  77),
        -INT8_C(  33), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C( 105),      INT8_MAX,  INT8_C(  87),  INT8_C(  65) } },
    { {  INT8_C(  19), -INT8_C( 115),  INT8_C(  19), -INT8_C( 111),  INT8_C( 114), -INT8_C(  86),  INT8_C(  45), -INT8_C(  36),
         INT8_C(  41),  INT8_C( 110), -INT8_C(  35), -INT8_C(   4),  INT8_C(  77),  INT8_C(  52),  INT8_C(  55),  INT8_C(  42),
        -INT8_C(  34), -INT8_C(  51),  INT8_C( 111), -INT8_C( 120),      INT8_MIN, -INT8_C(  88),  INT8_C(   0),  INT8_C(  40),
         INT8_C(  55), -INT8_C(  51),  INT8_C(  55), -INT8_C( 113), -INT8_C( 120), -INT8_C(  16), -INT8_C(  99), -INT8_C( 101) },
      {  INT8_C( 125), -INT8_C(  80),  INT8_C(  44), -INT8_C(  16),  INT8_C(  91),  INT8_C(  89), -INT8_C(  52), -INT8_C( 124),
        -INT8_C(  56), -INT8_C(  87), -INT8_C( 127),  INT8_C(  21), -INT8_C(  35), -INT8_C(  72),  INT8_C(  64), -INT8_C(  69),
        -INT8_C( 122), -INT8_C(  81),  INT8_C(  68),  INT8_C(   6),  INT8_C(  87),  INT8_C(  68),  INT8_C(  47), -INT8_C( 113),
         INT8_C(  18),  INT8_C( 102),  INT8_C(  30), -INT8_C( 102),  INT8_C(  86), -INT8_C(  68),  INT8_C(  54), -INT8_C(  45) },
      {  INT8_C(   6), -INT8_C(  72),  INT8_C(   6), -INT8_C(  81),  INT8_C(  68), -INT8_C( 127), -INT8_C(  72),  INT8_C(  86),
        -INT8_C(  87),  INT8_C(  64), -INT8_C(  68),  INT8_C(  86), -INT8_C(  72),  INT8_C(  87), -INT8_C( 113), -INT8_C( 127),
         INT8_C(  54), -INT8_C(  72), -INT8_C(  69), -INT8_C(  56),  INT8_C( 125), -INT8_C(  56),  INT8_C( 125), -INT8_C(  56),
        -INT8_C( 113), -INT8_C(  72), -INT8_C( 113), -INT8_C(  69), -INT8_C(  56), -INT8_C( 122), -INT8_C(  68), -INT8_C( 102) } },
    { {  INT8_C( 108),  INT8_C(  98), -INT8_C(  61), -INT8_C(  57), -INT8_C(  68), -INT8_C( 112),  INT8_C(  76), -INT8_C( 124),
         INT8_C(  57), -INT8_C(  51), -INT8_C( 103),  INT8_C(  23), -INT8_C( 123), -INT8_C(  39), -INT8_C(  46),  INT8_C(  11),
        -INT8_C( 120),  INT8_C(  22),  INT8_C(  18), -INT8_C(  32),  INT8_C(  91),  INT8_C(  65),  INT8_C( 111),  INT8_C( 109),
        -INT8_C(  89), -INT8_C( 115),  INT8_C(   7), -INT8_C(   3),  INT8_C(  73),  INT8_C(  61), -INT8_C(  48), -INT8_C(  74) },
      { -INT8_C(  96), -INT8_C( 108),  INT8_C( 125),  INT8_C(  92),  INT8_C(  36), -INT8_C(  55), -INT8_C(  32),  INT8_C(  93),
        -INT8_C( 106),  INT8_C( 121),  INT8_C( 116),  INT8_C(  28),  INT8_C(  83),  INT8_C(  71),  INT8_C(  39), -INT8_C(  37),
         INT8_C(  93),  INT8_C(  57), -INT8_C(  69), -INT8_C(  72),  INT8_C( 122),  INT8_C(  42),  INT8_C(  37),  INT8_C(  33),
        -INT8_C(  72),  INT8_C(  45),  INT8_C(  30),  INT8_C(   1),  INT8_C( 106), -INT8_C(  17), -INT8_C(  73),  INT8_C(  10) },
      {  INT8_C(  83),  INT8_C( 125),  INT8_C(  92),  INT8_C(  93),  INT8_C( 106),  INT8_C(  93),  INT8_C(  83),  INT8_C(  36),
         INT8_C(  45),  INT8_C(  71),  INT8_C(  45),  INT8_C(  33), -INT8_C(  55),  INT8_C(  45), -INT8_C(  69),  INT8_C(  28),
        -INT8_C( 106),  INT8_C(  37), -INT8_C(  69), -INT8_C(  96),  INT8_C(   1), -INT8_C( 108), -INT8_C(  37),  INT8_C(  71),
         INT8_C(  93),  INT8_C(  71),  INT8_C(  93), -INT8_C(  17),  INT8_C( 121), -INT8_C(  17),  INT8_C(  93),  INT8_C(  37) } },
    { { -INT8_C( 125),  INT8_C(  53),  INT8_C( 102), -INT8_C(  89), -INT8_C(   2),  INT8_C(  70),  INT8_C(   4), -INT8_C( 107),
        -INT8_C(  64),  INT8_C( 121), -INT8_C(  79),  INT8_C(  19), -INT8_C(  64), -INT8_C(  40), -INT8_C(  18),  INT8_C(  29),
         INT8_C(  18), -INT8_C(  86), -INT8_C(  42), -INT8_C( 116), -INT8_C(  44), -INT8_C(   5), -INT8_C(  82), -INT8_C( 116),
         INT8_C(  40), -INT8_C(  52), -INT8_C( 114), -INT8_C( 109), -INT8_C(  69),  INT8_C(  69), -INT8_C(  99),  INT8_C(  62) },
      {  INT8_C( 122),  INT8_C(   4), -INT8_C(  27),  INT8_C( 121),  INT8_C(  74), -INT8_C(  22),  INT8_C(  14),  INT8_C(  10),
         INT8_C(  99), -INT8_C(  65),  INT8_C(  29),  INT8_C(  35), -INT8_C( 105),  INT8_C(  12),  INT8_C(  64), -INT8_C(  87),
        -INT8_C(  74),  INT8_C(  22),  INT8_C(  54), -INT8_C( 118),  INT8_C(  18), -INT8_C(  28),  INT8_C(  23),  INT8_C(  58),
        -INT8_C(  80), -INT8_C(  91), -INT8_C(  51),  INT8_C( 108), -INT8_C(  22),  INT8_C( 107), -INT8_C(  86),  INT8_C( 101) },
      {  INT8_C( 121), -INT8_C(  28),  INT8_C(  14),  INT8_C(  10), -INT8_C(  86),  INT8_C(  14),  INT8_C(  74), -INT8_C(  28),
         INT8_C( 122), -INT8_C(  91),  INT8_C(  22), -INT8_C( 118),  INT8_C( 122), -INT8_C(  80),  INT8_C(  64),  INT8_C( 107),
         INT8_C(  54),  INT8_C(  29),  INT8_C(  23), -INT8_C( 105),  INT8_C(  18),  INT8_C( 108),  INT8_C(  64), -INT8_C( 105),
         INT8_C(  99), -INT8_C( 105),  INT8_C(  64), -INT8_C( 118),  INT8_C( 108), -INT8_C(  22),  INT8_C( 107), -INT8_C(  86) } },
    { {  INT8_C( 111), -INT8_C( 112), -INT8_C(  34), -INT8_C(  71),  INT8_C( 122), -INT8_C(  20), -INT8_C(  60), -INT8_C(  35),
        -INT8_C(  85), -INT8_C(  31),  INT8_C(   0),  INT8_C(  66), -INT8_C(  19),  INT8_C(  64), -INT8_C(  20), -INT8_C(  93),
         INT8_C(  87),  INT8_C(  34),  INT8_C(  46),  INT8_C( 105),  INT8_C(   6),  INT8_C(  69), -INT8_C(  93), -INT8_C(  74),
        -INT8_C(  22),  INT8_C( 113),  INT8_C(  34), -INT8_C(  44), -INT8_C(  36), -INT8_C(  51),  INT8_C(  57),  INT8_C(  75) },
      {  INT8_C(  93),  INT8_C(  23),  INT8_C(   4), -INT8_C(  41),  INT8_C(   3), -INT8_C(  56), -INT8_C(  76), -INT8_C(  82),
        -INT8_C(  86), -INT8_C(  76), -INT8_C(  15), -INT8_C( 105), -INT8_C(  12), -INT8_C(  35),  INT8_C(  59),  INT8_C(  75),
        -INT8_C(   1),  INT8_C( 105), -INT8_C(  76),  INT8_C(   5), -INT8_C(  82),  INT8_C(  88), -INT8_C(  69), -INT8_C( 104),
        -INT8_C(  55), -INT8_C(  34),  INT8_C( 108), -INT8_C(  91), -INT8_C(  85), -INT8_C(  90), -INT8_C(  16),  INT8_C(   8) },
      {  INT8_C(  75), -INT8_C(   1), -INT8_C(  16), -INT8_C(  34),  INT8_C( 108), -INT8_C(  12),  INT8_C(   3), -INT8_C(  90),
        -INT8_C( 105),  INT8_C(  23),  INT8_C(  93),  INT8_C(   4), -INT8_C(  35),  INT8_C(  93), -INT8_C(  12), -INT8_C(  41),
        -INT8_C( 104),  INT8_C(   4),  INT8_C(  59), -INT8_C(  76), -INT8_C(  76), -INT8_C(  56), -INT8_C(  41), -INT8_C(  69),
        -INT8_C(  15),  INT8_C( 105),  INT8_C(   4), -INT8_C(  82), -INT8_C(  85), -INT8_C(  35), -INT8_C(  34), -INT8_C( 105) } },
    { { -INT8_C(  67), -INT8_C(  12), -INT8_C(  33), -INT8_C(  63), -INT8_C(  67), -INT8_C( 109),  INT8_C( 111),  INT8_C( 103),
         INT8_C(  71),  INT8_C(  96), -INT8_C(   2),  INT8_C(  59),  INT8_C(  61),  INT8_C(  57), -INT8_C( 121),  INT8_C(  60),
        -INT8_C(  94),  INT8_C(  59),  INT8_C(  65),  INT8_C(  80), -INT8_C( 109), -INT8_C(   3), -INT8_C(  24),  INT8_C(  92),
        -INT8_C(  37),  INT8_C(  85),  INT8_C(   1), -INT8_C( 122), -INT8_C(   5), -INT8_C(  15), -INT8_C( 114), -INT8_C(  72) },
      { -INT8_C(  26),  INT8_C( 109),  INT8_C( 121), -INT8_C(  93),  INT8_C(   0), -INT8_C(  23),  INT8_C(  10),  INT8_C(  71),
         INT8_C(  73),  INT8_C(   8), -INT8_C( 126), -INT8_C( 121),  INT8_C(  66),  INT8_C(   9), -INT8_C(  61), -INT8_C(  28),
         INT8_C(  69),  INT8_C(   5),  INT8_C(  53), -INT8_C(  40),  INT8_C(   2),  INT8_C(  29),  INT8_C(  53), -INT8_C(  35),
         INT8_C( 114),  INT8_C(  54),  INT8_C(  99),  INT8_C( 109),  INT8_C(  40), -INT8_C(  15),  INT8_C(  38),  INT8_C(  14) },
      { -INT8_C(  15),  INT8_C(   2),  INT8_C(  14),  INT8_C( 109), -INT8_C(  15), -INT8_C(  40), -INT8_C(  28),  INT8_C(  71),
         INT8_C(  71), -INT8_C(  26),  INT8_C(  38),  INT8_C( 109), -INT8_C(  15),  INT8_C(  54),  INT8_C(  71),  INT8_C(  40),
         INT8_C( 121),  INT8_C( 109),  INT8_C( 109),  INT8_C(  69), -INT8_C(  40), -INT8_C(  15),  INT8_C(  73),  INT8_C(  40),
         INT8_C( 109),  INT8_C(  29),  INT8_C( 109),  INT8_C(  10),  INT8_C( 109),  INT8_C(   5), -INT8_C(  61),  INT8_C( 114) } },
    { {  INT8_C(  94), -INT8_C(  97), -INT8_C(  79),  INT8_C(  94), -INT8_C( 120), -INT8_C(  69), -INT8_C(  91), -INT8_C(  46),
        -INT8_C(  61),  INT8_C(  39),  INT8_C(  89),  INT8_C(   5),  INT8_C(  49),  INT8_C(  28), -INT8_C(  22),  INT8_C( 118),
         INT8_C(  33),  INT8_C(  31),  INT8_C(  78),  INT8_C(  35),  INT8_C(  60), -INT8_C( 125),  INT8_C(   0), -INT8_C(  81),
        -INT8_C(  70),  INT8_C(  99),  INT8_C(  28), -INT8_C(  30),  INT8_C(  84),  INT8_C(  66), -INT8_C(  16), -INT8_C(  78) },
      { -INT8_C(  30), -INT8_C(  95),  INT8_C(  16),  INT8_C( 106),  INT8_C(  92), -INT8_C(  75),  INT8_C(  60),  INT8_C(  31),
        -INT8_C(  35), -INT8_C( 107),  INT8_C(  37),  INT8_C(  14), -INT8_C(  78),  INT8_C(  15), -INT8_C( 124), -INT8_C(  45),
         INT8_C(  46), -INT8_C(  46), -INT8_C(   9),  INT8_C( 106),  INT8_C(  86), -INT8_C(   9),  INT8_C(  25),  INT8_C(  16),
         INT8_C(  91),  INT8_C(  54), -INT8_C(  14), -INT8_C(  81),  INT8_C( 120), -INT8_C(  30),  INT8_C(  98),  INT8_C(  90) },
      {  INT8_C(  98),  INT8_C(  90), -INT8_C(  46),  INT8_C(  98), -INT8_C(  35), -INT8_C(  81), -INT8_C(  75), -INT8_C(   9),
         INT8_C( 106),  INT8_C(  31),  INT8_C(  54), -INT8_C(  75), -INT8_C(  46),  INT8_C( 120),  INT8_C(  37),  INT8_C(  25),
        -INT8_C(  95),  INT8_C(  90), -INT8_C( 124),  INT8_C( 106),  INT8_C( 120),  INT8_C( 106), -INT8_C(  30), -INT8_C(  45),
        -INT8_C(  14),  INT8_C( 106),  INT8_C( 120),  INT8_C(  16),  INT8_C(  86),  INT8_C(  16),  INT8_C(  46), -INT8_C(   9) } },
    { { -INT8_C( 125),  INT8_C( 114), -INT8_C(  59), -INT8_C(  33),  INT8_C(  40),  INT8_C(   1), -INT8_C(   2),  INT8_C(   5),
        -INT8_C( 105),  INT8_C(  35),  INT8_C(  19),  INT8_C(  73),  INT8_C(  50), -INT8_C( 105),  INT8_C(  28),  INT8_C(  96),
         INT8_C( 105),  INT8_C(  19), -INT8_C(  53), -INT8_C(  65),  INT8_C(  11), -INT8_C(  28), -INT8_C(  49),  INT8_C( 102),
         INT8_C(  26), -INT8_C(  63),  INT8_C(  21), -INT8_C( 109), -INT8_C(  93),  INT8_C( 119), -INT8_C(  19),  INT8_C(  38) },
      { -INT8_C(  22), -INT8_C(  78),  INT8_C(   5),  INT8_C(  18), -INT8_C(  76),  INT8_C(   4),  INT8_C(  23),  INT8_C(  75),
         INT8_C(  39),  INT8_C(  42), -INT8_C( 108),  INT8_C(  90), -INT8_C(  63), -INT8_C(  80), -INT8_C(  70),  INT8_C(  42),
        -INT8_C(  60), -INT8_C( 123), -INT8_C(  22), -INT8_C(  49),  INT8_C( 106), -INT8_C(  71),  INT8_C(  53), -INT8_C( 124),
         INT8_C( 123),  INT8_C(  74),  INT8_C(  23),  INT8_C(  30), -INT8_C(  62),  INT8_C(   5),  INT8_C(  69), -INT8_C(  84) },
      {  INT8_C(  18), -INT8_C(  22),  INT8_C(   4), -INT8_C(  84),  INT8_C(  39), -INT8_C(  78),  INT8_C(  69),  INT8_C(   4),
        -INT8_C( 124),  INT8_C(  18), -INT8_C(  49),  INT8_C(  42), -INT8_C(  22), -INT8_C( 124), -INT8_C(  62), -INT8_C(  22),
         INT8_C(  42), -INT8_C(  49),  INT8_C(  90), -INT8_C(  84),  INT8_C(  90), -INT8_C(  76),  INT8_C(  42),  INT8_C(  23),
         INT8_C(  23), -INT8_C(  78), -INT8_C(  71), -INT8_C(  49),  INT8_C(  18), -INT8_C( 124), -INT8_C(  80),  INT8_C(  23) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i r = simde_mm256_permutexvar_epi8(idx, a);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_permutexvar_epi8(idx, a);

    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[32];
    const simde__mmask32 k;
    const int8_t idx[32];
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C(  73),  INT8_C(  74), -INT8_C(  66),  INT8_C( 107),  INT8_C(  78), -INT8_C(  43), -INT8_C(  74),  INT8_C( 118),
        -INT8_C(   1),  INT8_C(  74), -INT8_C(  48), -INT8_C(  64), -INT8_C(   5), -INT8_C( 118), -INT8_C(  22), -INT8_C(  65),
         INT8_C(  16), -INT8_C(  44), -INT8_C( 114),  INT8_C( 122), -INT8_C( 114), -INT8_C(  61), -INT8_C(   2),  INT8_C(   9),
         INT8_C(  13),  INT8_C(  22),  INT8_C(  39), -INT8_C(  49),  INT8_C(  27),  INT8_C( 108),  INT8_C( 123), -INT8_C(  46) },
      UINT32_C(  87964087),
      {  INT8_C(  14), -INT8_C(  12),  INT8_C( 123),  INT8_C(  13),  INT8_C(  63),  INT8_C(  75), -INT8_C(  51),  INT8_C(  58),
        -INT8_C(  42), -INT8_C(  72), -INT8_C(   7), -INT8_C(  26), -INT8_C( 116), -INT8_C( 121),  INT8_C(  96),  INT8_C(  26),
         INT8_C(  74),  INT8_C(  94),  INT8_C(  35),  INT8_C(  87),  INT8_C( 116),  INT8_C(  75),  INT8_C(  39), -INT8_C( 113),
        -INT8_C(  73), -INT8_C(  94),  INT8_C(  98),  INT8_C( 110), -INT8_C(  36), -INT8_C(  96),  INT8_C( 116), -INT8_C(  22) },
      { -INT8_C( 108), -INT8_C(  17), -INT8_C(   8), -INT8_C(  45),  INT8_C(  59), -INT8_C(  59),  INT8_C(  13),  INT8_C(  17),
         INT8_C( 125),  INT8_C(   6), -INT8_C(   9),  INT8_C(  10), -INT8_C( 115),  INT8_C(  87),  INT8_C(  36), -INT8_C(  41),
        -INT8_C(  75),  INT8_C(  72),  INT8_C(  47),  INT8_C(  42), -INT8_C( 109),  INT8_C(  86), -INT8_C(  71),  INT8_C(  74),
        -INT8_C(   8),  INT8_C(  27), -INT8_C(  71), -INT8_C(  44), -INT8_C(  69),  INT8_C(  45), -INT8_C(  65),  INT8_C(  80) },
      {  INT8_C(  36), -INT8_C( 109), -INT8_C(  44),  INT8_C( 107),  INT8_C(  80),  INT8_C(  10), -INT8_C(  74), -INT8_C(  71),
        -INT8_C(  71),  INT8_C(  74), -INT8_C(  48),  INT8_C(  13), -INT8_C( 115),  INT8_C(  17), -INT8_C(  22), -INT8_C(  65),
         INT8_C(  16), -INT8_C(  65), -INT8_C(  45),  INT8_C(  74), -INT8_C( 109),  INT8_C(  10), -INT8_C(   2),  INT8_C(   9),
         INT8_C(  74),  INT8_C(  22), -INT8_C(   8), -INT8_C(  49),  INT8_C(  27),  INT8_C( 108),  INT8_C( 123), -INT8_C(  46) } },
    { {  INT8_C(  28), -INT8_C(  73),  INT8_C(  35),  INT8_C(  87),  INT8_C( 124),  INT8_C(  49),  INT8_C( 104), -INT8_C(   6),
         INT8_C(  55),  INT8_C(  95),  INT8_C(   4), -INT8_C(  59), -INT8_C(  74),  INT8_C(  40), -INT8_C( 100),  INT8_C( 108),
         INT8_C( 112), -INT8_C(  53), -INT8_C( 106),  INT8_C(   3),  INT8_C(  33),  INT8_C(  79),  INT8_C(  78),  INT8_C(  26),
         INT8_C( 107),  INT8_C(   7), -INT8_C(  18),  INT8_C(  38),  INT8_C(  52), -INT8_C(  83),  INT8_C( 118),  INT8_C(  80) },
      UINT32_C(3785923172),
      { -INT8_C(  53),  INT8_C(  16), -INT8_C(  37),  INT8_C(   2),  INT8_C( 112), -INT8_C(  33), -INT8_C(  57),  INT8_C(  38),
         INT8_C(   7),  INT8_C( 100), -INT8_C( 110),  INT8_C( 120),  INT8_C(  47),  INT8_C(  40),  INT8_C( 123),  INT8_C(  81),
         INT8_C( 120), -INT8_C(  55),  INT8_C( 107), -INT8_C(  29), -INT8_C(  48),  INT8_C(  89),  INT8_C(   9),  INT8_C(   4),
         INT8_C(   7),      INT8_MIN,  INT8_C(  85),  INT8_C( 107),  INT8_C(  26), -INT8_C(   3),  INT8_C(  76), -INT8_C(  27) },
      {  INT8_C(  13),  INT8_C(  39), -INT8_C(  25),  INT8_C( 125),  INT8_C(   6), -INT8_C(  81), -INT8_C(  92),  INT8_C(  14),
         INT8_C(  19),  INT8_C(  54), -INT8_C( 122),  INT8_C(  66),  INT8_C(  95),  INT8_C(   1), -INT8_C( 109), -INT8_C(  41),
        -INT8_C(  53), -INT8_C(   2), -INT8_C(  70), -INT8_C( 101),  INT8_C(  88), -INT8_C(  61), -INT8_C(  96),  INT8_C(  95),
         INT8_C(  67), -INT8_C(  11), -INT8_C(  54),  INT8_C(  93), -INT8_C(  14),  INT8_C(  23),  INT8_C(  66), -INT8_C(   1) },
      {  INT8_C(  28), -INT8_C(  73),  INT8_C(  93),  INT8_C(  87),  INT8_C( 124), -INT8_C(   1),  INT8_C(  14), -INT8_C(   6),
         INT8_C(  55),  INT8_C(   6),  INT8_C(   4),  INT8_C(  67), -INT8_C(  41),  INT8_C(  40), -INT8_C( 100), -INT8_C(   2),
         INT8_C( 112), -INT8_C(  53), -INT8_C( 106),  INT8_C( 125),  INT8_C(  33), -INT8_C(  11),  INT8_C(  78),  INT8_C(   6),
         INT8_C(  14),  INT8_C(   7), -INT8_C(  18),  INT8_C(  38),  INT8_C(  52),  INT8_C(  23),  INT8_C(  95), -INT8_C(  81) } },
    { {  INT8_C(  62),  INT8_C(  42),  INT8_C( 125),  INT8_C(  69), -INT8_C(  39),  INT8_C(  33),  INT8_C(  83), -INT8_C(  20),
         INT8_C(  87), -INT8_C(  39),  INT8_C(  46), -INT8_C(  74), -INT8_C(  38), -INT8_C(  62), -INT8_C( 115), -INT8_C(  91),
        -INT8_C(  64),  INT8_C(  71),  INT8_C(  65),  INT8_C(  24),  INT8_C(  11), -INT8_C(  31),  INT8_C( 119),  INT8_C(  78),
        -INT8_C(  42),  INT8_C(  66), -INT8_C(  84), -INT8_C(  56),  INT8_C(  89), -INT8_C(  18), -INT8_C(  57), -INT8_C( 105) },
      UINT32_C(4057744408),
      {  INT8_C( 101),  INT8_C(  47), -INT8_C(  35), -INT8_C(  67),  INT8_C(   8),  INT8_C(  12),  INT8_C( 115), -INT8_C(  29),
        -INT8_C(  50),  INT8_C(   1), -INT8_C( 120), -INT8_C( 114),  INT8_C(  72), -INT8_C(  55), -INT8_C(  89),  INT8_C(  83),
        -INT8_C(  86),  INT8_C(  30), -INT8_C(  94),      INT8_MIN,  INT8_C(  96),  INT8_C(  78),  INT8_C(  72), -INT8_C(  71),
         INT8_C(  60),  INT8_C(  16),  INT8_C(  81),  INT8_C(  85),  INT8_C(  84),  INT8_C(  45),  INT8_C(  70), -INT8_C(  70) },
      {  INT8_C(  93),  INT8_C(  36),  INT8_C( 119),  INT8_C( 101),  INT8_C(  48), -INT8_C(  22),  INT8_C(  72), -INT8_C(   2),
        -INT8_C(  21), -INT8_C(  47), -INT8_C( 116),  INT8_C(  52), -INT8_C( 102),  INT8_C(  51), -INT8_C( 121),  INT8_C(  69),
         INT8_C(  82),  INT8_C(  41), -INT8_C(  59), -INT8_C(  78),  INT8_C( 119),  INT8_C(  14),  INT8_C( 108), -INT8_C(  76),
         INT8_C(  30), -INT8_C(  67),  INT8_C(   9),  INT8_C( 114), -INT8_C(  22),  INT8_C(  79),  INT8_C(  44),  INT8_C(  71) },
      {  INT8_C(  62),  INT8_C(  42),  INT8_C( 125),  INT8_C(  79), -INT8_C(  21),  INT8_C(  33),  INT8_C(  83), -INT8_C(  20),
         INT8_C(  87), -INT8_C(  39), -INT8_C(  21), -INT8_C(  74), -INT8_C(  38), -INT8_C(  62), -INT8_C(   2), -INT8_C(  91),
        -INT8_C(  64),  INT8_C(  71),  INT8_C( 119),  INT8_C(  93),  INT8_C(  93), -INT8_C(  31), -INT8_C(  21), -INT8_C(  67),
        -INT8_C(  22),  INT8_C(  66), -INT8_C(  84), -INT8_C(  56),  INT8_C( 119),  INT8_C(  51),  INT8_C(  72),  INT8_C(   9) } },
    { {  INT8_C( 115), -INT8_C(  93), -INT8_C(  83), -INT8_C(  93), -INT8_C( 114), -INT8_C(  11), -INT8_C(  95),  INT8_C( 121),
        -INT8_C(  58),  INT8_C(  46), -INT8_C(  83),  INT8_C(  97),  INT8_C(  97),  INT8_C(  53), -INT8_C(  90), -INT8_C(  77),
         INT8_C(  94),  INT8_C( 107),  INT8_C( 102), -INT8_C(  42),  INT8_C( 121), -INT8_C(  46), -INT8_C( 118), -INT8_C( 105),
        -INT8_C( 113), -INT8_C( 109),  INT8_C(  10),  INT8_C( 121), -INT8_C(  30),  INT8_C(  54), -INT8_C(  63),  INT8_C(  86) },
      UINT32_C(1761177306),
      {  INT8_C(  99), -INT8_C( 101), -INT8_C(  31),  INT8_C(  42), -INT8_C(  55), -INT8_C( 113), -INT8_C( 117),  INT8_C(  42),
        -INT8_C(  60),  INT8_C(  49), -INT8_C(  34),  INT8_C(  34), -INT8_C( 100),  INT8_C(  68), -INT8_C(   8),  INT8_C(  22),
         INT8_C(  22), -INT8_C( 126), -INT8_C(  83), -INT8_C(  91),  INT8_C(  21), -INT8_C(  73),  INT8_C(  30), -INT8_C(   8),
        -INT8_C(  18), -INT8_C(  33),  INT8_C(  78), -INT8_C(  56),  INT8_C(  77),  INT8_C(  71),  INT8_C(  48), -INT8_C(  79) },
      { -INT8_C(  30),  INT8_C(  17), -INT8_C(  37), -INT8_C(  85), -INT8_C(  96),  INT8_C( 102), -INT8_C(  42),  INT8_C( 100),
        -INT8_C( 105), -INT8_C(  76), -INT8_C( 121),  INT8_C(  51), -INT8_C(   8),      INT8_MAX,  INT8_C(  73),  INT8_C(  14),
         INT8_C(   2), -INT8_C(   9), -INT8_C(  77),  INT8_C(  23), -INT8_C(  82), -INT8_C(  47),  INT8_C(  15), -INT8_C( 100),
        -INT8_C(  79),  INT8_C(  93),  INT8_C( 100), -INT8_C(   2), -INT8_C(  91), -INT8_C( 108), -INT8_C(  81), -INT8_C( 121) },
      {  INT8_C( 115), -INT8_C(   2), -INT8_C(  83), -INT8_C( 121), -INT8_C(  76), -INT8_C(  11),  INT8_C(  51), -INT8_C( 121),
        -INT8_C(  58), -INT8_C(   9), -INT8_C(  81), -INT8_C(  37),  INT8_C(  97), -INT8_C(  96), -INT8_C(  79), -INT8_C(  77),
         INT8_C(  15),  INT8_C( 107),  INT8_C( 102),  INT8_C( 102), -INT8_C(  47), -INT8_C( 100), -INT8_C(  81), -INT8_C(  79),
        -INT8_C( 113), -INT8_C( 109),  INT8_C(  10), -INT8_C( 105), -INT8_C(  30),  INT8_C( 100),  INT8_C(   2),  INT8_C(  86) } },
    { { -INT8_C(  90), -INT8_C( 118),  INT8_C(  51),  INT8_C(  70), -INT8_C(  16),  INT8_C(   9), -INT8_C(  85), -INT8_C( 121),
        -INT8_C(  67),  INT8_C(  50), -INT8_C(  69), -INT8_C(  75), -INT8_C(  79),  INT8_C(   4), -INT8_C(  61), -INT8_C(  77),
        -INT8_C(   5),  INT8_C( 118), -INT8_C(  53), -INT8_C(  86),  INT8_C(  71), -INT8_C(  38),  INT8_C(  70), -INT8_C(   8),
         INT8_C(  56), -INT8_C(  85), -INT8_C(   9), -INT8_C(  35),  INT8_C(  63), -INT8_C(  90),  INT8_C( 100), -INT8_C(  27) },
      UINT32_C( 556570417),
      { -INT8_C(  96), -INT8_C(  41), -INT8_C(  87),  INT8_C(  93),  INT8_C(   9),  INT8_C( 100),  INT8_C(  18), -INT8_C(  70),
         INT8_C( 104), -INT8_C(  43),  INT8_C( 110),  INT8_C( 100),  INT8_C(  75),  INT8_C(  57),  INT8_C(  14), -INT8_C( 109),
         INT8_C(  19),  INT8_C(  84), -INT8_C( 117),  INT8_C(  75), -INT8_C(   1), -INT8_C( 126),  INT8_C(  40),  INT8_C(  63),
         INT8_C(  41), -INT8_C( 115),  INT8_C(  36),  INT8_C(  90),  INT8_C(  36),  INT8_C(  80),  INT8_C( 123), -INT8_C(  59) },
      {  INT8_C(  39),  INT8_C(  36),  INT8_C(  34),  INT8_C(  48), -INT8_C( 120),  INT8_C(  53), -INT8_C(  21), -INT8_C(  15),
         INT8_C(  10),  INT8_C(  89),  INT8_C(  85),  INT8_C(  86), -INT8_C( 110),  INT8_C(  99), -INT8_C(  23), -INT8_C(  91),
        -INT8_C(  73),  INT8_C( 116), -INT8_C(  15), -INT8_C(  73), -INT8_C(   9),  INT8_C(  25), -INT8_C(  10),  INT8_C(  32),
        -INT8_C(  90),  INT8_C(  26),  INT8_C( 122), -INT8_C(  53),  INT8_C( 107), -INT8_C(  11), -INT8_C( 112), -INT8_C( 110) },
      {  INT8_C(  39), -INT8_C( 118),  INT8_C(  51),  INT8_C(  70),  INT8_C(  89), -INT8_C( 120), -INT8_C(  85), -INT8_C( 121),
         INT8_C(  10),  INT8_C(  25), -INT8_C(  23), -INT8_C(  75),  INT8_C(  86),  INT8_C(   4), -INT8_C(  61), -INT8_C(  73),
        -INT8_C(   5),  INT8_C( 118),  INT8_C(  86),  INT8_C(  86),  INT8_C(  71),  INT8_C(  34),  INT8_C(  70), -INT8_C(   8),
         INT8_C(  89), -INT8_C(  85), -INT8_C(   9), -INT8_C(  35),  INT8_C(  63), -INT8_C(  73),  INT8_C( 100), -INT8_C(  27) } },
    { {  INT8_C(  26), -INT8_C(  78), -INT8_C(  61), -INT8_C(  94), -INT8_C(  25), -INT8_C(  82), -INT8_C( 109), -INT8_C(  14),
         INT8_C(   7), -INT8_C(  24),  INT8_C(  72), -INT8_C( 103),  INT8_C(  75),  INT8_C(  49),  INT8_C(  62),  INT8_C(   3),
        -INT8_C(  91),  INT8_C(  47), -INT8_C(  70), -INT8_C( 100),  INT8_C(  73), -INT8_C(  80), -INT8_C(  68), -INT8_C(  17),
        -INT8_C(  54),  INT8_C(  54), -INT8_C(  70),  INT8_C(  53),  INT8_C(  44),  INT8_C(  74), -INT8_C(  56),  INT8_C(  70) },
      UINT32_C(3840445437),
      {  INT8_C(  57),  INT8_C( 124), -INT8_C(  42),  INT8_C(  64),  INT8_C( 100),  INT8_C(  30), -INT8_C(  39), -INT8_C(  80),
         INT8_C(  79),  INT8_C(  23), -INT8_C(  77), -INT8_C(  11),  INT8_C(  71),  INT8_C( 109), -INT8_C( 111), -INT8_C( 112),
         INT8_C(  29),  INT8_C(  78),      INT8_MAX, -INT8_C(  25), -INT8_C( 124),  INT8_C(  58),  INT8_C(  29), -INT8_C(  80),
        -INT8_C( 124), -INT8_C(  27), -INT8_C(  10), -INT8_C( 127),  INT8_C( 112), -INT8_C(  33),  INT8_C( 102), -INT8_C(  87) },
      {  INT8_C(  91),  INT8_C(  60), -INT8_C(  23), -INT8_C(  65),  INT8_C(  91), -INT8_C(  62),  INT8_C( 111), -INT8_C(  86),
        -INT8_C(  39),  INT8_C(  34), -INT8_C(  97),  INT8_C(  32), -INT8_C( 113),  INT8_C(  49), -INT8_C(  80), -INT8_C(  84),
             INT8_MAX,  INT8_C(  48), -INT8_C( 108),  INT8_C(   3),  INT8_C( 106), -INT8_C(  79), -INT8_C(  76), -INT8_C(  18),
        -INT8_C( 106), -INT8_C(  86),  INT8_C( 112),  INT8_C(   6), -INT8_C( 119), -INT8_C(  42), -INT8_C(  81), -INT8_C(  28) },
      { -INT8_C(  86), -INT8_C(  78), -INT8_C(  76),  INT8_C(  91),  INT8_C(  91), -INT8_C(  81), -INT8_C(  86),      INT8_MAX,
        -INT8_C(  84), -INT8_C(  18),  INT8_C(  72), -INT8_C(  79),  INT8_C(  75),  INT8_C(  49),  INT8_C(  62),      INT8_MAX,
        -INT8_C(  91),  INT8_C(  47), -INT8_C(  70), -INT8_C(  86),  INT8_C(  73),  INT8_C( 112), -INT8_C(  42),      INT8_MAX,
        -INT8_C(  54),  INT8_C(  54), -INT8_C(  76),  INT8_C(  53),  INT8_C(  44), -INT8_C(  28),  INT8_C( 111),  INT8_C(  34) } },
    { {  INT8_C(  18), -INT8_C( 104), -INT8_C(  92),  INT8_C( 109),  INT8_C(  90),  INT8_C(  19),  INT8_C(  24),  INT8_C(  51),
         INT8_C(  54), -INT8_C(  73),  INT8_C(  84), -INT8_C(  59), -INT8_C(  24),  INT8_C(   4),  INT8_C( 114),  INT8_C( 103),
         INT8_C(  52),  INT8_C(   6),  INT8_C( 107), -INT8_C(  98), -INT8_C(  73),  INT8_C(  31), -INT8_C( 115),  INT8_C(  77),
        -INT8_C(  55), -INT8_C(   3),  INT8_C(  83),  INT8_C(  83), -INT8_C(  45),  INT8_C(   2),  INT8_C(  55), -INT8_C(  27) },
      UINT32_C(4099136410),
      { -INT8_C(  17),  INT8_C( 107),  INT8_C(  39),  INT8_C(  37),  INT8_C(  34),  INT8_C( 123), -INT8_C(  22),  INT8_C(  11),
             INT8_MIN,  INT8_C(  92),  INT8_C( 114), -INT8_C(  76),  INT8_C(  98), -INT8_C(  35),  INT8_C(  83),  INT8_C(  25),
        -INT8_C(   4), -INT8_C(  32),  INT8_C( 102), -INT8_C(  58), -INT8_C(  35), -INT8_C(  71),  INT8_C(  25), -INT8_C(  80),
        -INT8_C(  69),  INT8_C(  80), -INT8_C( 107),  INT8_C(  85),  INT8_C(  44), -INT8_C(  24),  INT8_C(  73),  INT8_C(  27) },
      {  INT8_C(  83),  INT8_C( 113),  INT8_C(  64),  INT8_C( 118), -INT8_C(  20),  INT8_C(  42), -INT8_C( 127),  INT8_C( 108),
        -INT8_C( 121), -INT8_C(  13),  INT8_C(  33), -INT8_C(  23), -INT8_C(  47),  INT8_C( 116),  INT8_C(   3), -INT8_C(  51),
         INT8_C(  84),  INT8_C( 105), -INT8_C( 109),  INT8_C(  49),  INT8_C(  35), -INT8_C(  84), -INT8_C(  31), -INT8_C(  34),
        -INT8_C(   3),  INT8_C( 118),  INT8_C(  52),  INT8_C(  41),  INT8_C(  95),  INT8_C( 125),  INT8_C(  68), -INT8_C(  78) },
      {  INT8_C(  18), -INT8_C(  23), -INT8_C(  92),  INT8_C(  42),  INT8_C(  64),  INT8_C(  19),  INT8_C(  24), -INT8_C(  23),
         INT8_C(  83),  INT8_C(  95),  INT8_C(  84),  INT8_C(  35),  INT8_C(  64),  INT8_C(   4),  INT8_C(  49),  INT8_C( 118),
         INT8_C(  95),  INT8_C(  83),  INT8_C( 107), -INT8_C(  98),  INT8_C( 125),  INT8_C(  31),  INT8_C( 118),  INT8_C(  77),
        -INT8_C(  55), -INT8_C(   3), -INT8_C(  84),  INT8_C(  83), -INT8_C(  47), -INT8_C( 121), -INT8_C(  13),  INT8_C(  41) } },
    { { -INT8_C(  18), -INT8_C( 124),  INT8_C(  40), -INT8_C(  37), -INT8_C(  82), -INT8_C(  87),  INT8_C(  71),  INT8_C(  53),
        -INT8_C(  99),  INT8_C( 104),  INT8_C(  31),  INT8_C( 110), -INT8_C(  36),  INT8_C(  34),  INT8_C(  59),  INT8_C(  48),
        -INT8_C( 117), -INT8_C(  49),  INT8_C(  97), -INT8_C(  82),  INT8_C( 123),  INT8_C(  66), -INT8_C( 115),  INT8_C( 120),
        -INT8_C(  71), -INT8_C(  63), -INT8_C(  95),  INT8_C(  24),  INT8_C(  62), -INT8_C(  27), -INT8_C(  54),  INT8_C(  45) },
      UINT32_C( 403239785),
      { -INT8_C( 100),  INT8_C(  79),  INT8_C(  77),  INT8_C(  57), -INT8_C(  72),  INT8_C( 108), -INT8_C(  89), -INT8_C( 108),
        -INT8_C( 114), -INT8_C(  29), -INT8_C(  59),  INT8_C(  26), -INT8_C(  78),  INT8_C(  38), -INT8_C(  56),  INT8_C(  45),
         INT8_C( 105),  INT8_C(  85), -INT8_C(  90),  INT8_C(  34),  INT8_C(  22),  INT8_C(  71),  INT8_C(  58),  INT8_C(  85),
         INT8_C(  45),  INT8_C(   4), -INT8_C( 126), -INT8_C( 106), -INT8_C(   9), -INT8_C( 118), -INT8_C(  82), -INT8_C( 108) },
      { -INT8_C(  39), -INT8_C(   4), -INT8_C(  51), -INT8_C( 111),  INT8_C( 104),  INT8_C( 117),  INT8_C(  38), -INT8_C(   9),
         INT8_C(  88), -INT8_C(  21),  INT8_C(  17),  INT8_C(  10),  INT8_C(  17), -INT8_C(  39),  INT8_C(  55),  INT8_C( 122),
         INT8_C(  47), -INT8_C(  35), -INT8_C( 100),  INT8_C(  69),  INT8_C(  37), -INT8_C(  42), -INT8_C( 102),  INT8_C(  82),
        -INT8_C(  37),  INT8_C(  28), -INT8_C(  24), -INT8_C(  46), -INT8_C(  90), -INT8_C( 105),  INT8_C( 102),      INT8_MIN },
      { -INT8_C(  90), -INT8_C( 124),  INT8_C(  40),  INT8_C(  28), -INT8_C(  82),  INT8_C(  17), -INT8_C(   9),  INT8_C(  53),
         INT8_C(  55), -INT8_C( 111),  INT8_C(  31),  INT8_C( 110), -INT8_C( 100),  INT8_C(  38),  INT8_C(  88), -INT8_C(  39),
        -INT8_C( 117), -INT8_C(  49),  INT8_C(  97), -INT8_C(  51),  INT8_C( 123),  INT8_C(  66), -INT8_C( 115),  INT8_C( 120),
        -INT8_C(  71), -INT8_C(  63), -INT8_C(  95), -INT8_C( 102),  INT8_C(  82), -INT8_C(  27), -INT8_C(  54),  INT8_C(  45) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi8(test_vec[i].src);
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_permutexvar_epi8(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i8x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask_permutexvar_epi8(src, k, idx, a);

    simde_test_x86_write_i8x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t idx[32];
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C(4212208787),
      { -INT8_C(  87),  INT8_C(  55), -INT8_C(  14),  INT8_C(   1),  INT8_C(  34),  INT8_C(   3),  INT8_C(  11),  INT8_C(  52),
        -INT8_C(  35),  INT8_C(  66), -INT8_C(  82),  INT8_C(  12),  INT8_C(  32),  INT8_C(  75),  INT8_C(  81),  INT8_C(  69),
         INT8_C(  33), -INT8_C(  20), -INT8_C( 105), -INT8_C(   4),  INT8_C(   8),      INT8_MAX, -INT8_C(  49), -INT8_C(  81),
         INT8_C(  22),  INT8_C(  53),  INT8_C(  47), -INT8_C(  87),  INT8_C( 105),  INT8_C(  64), -INT8_C(  91),  INT8_C(  18) },
      {  INT8_C( 120), -INT8_C( 105),  INT8_C(  19), -INT8_C( 102), -INT8_C( 101),  INT8_C(  30), -INT8_C(  50),  INT8_C( 120),
         INT8_C(  97),  INT8_C( 125), -INT8_C( 124), -INT8_C( 127), -INT8_C(  56), -INT8_C(  43), -INT8_C(  58), -INT8_C(  23),
        -INT8_C(  63),  INT8_C(  93), -INT8_C(  26), -INT8_C(  54), -INT8_C(  36), -INT8_C(  75),  INT8_C( 121), -INT8_C(  13),
        -INT8_C(  22), -INT8_C(  88), -INT8_C( 100),  INT8_C(  84), -INT8_C(  24),  INT8_C(  65),  INT8_C( 102),  INT8_C(  96) },
      {  INT8_C( 125), -INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C(  19),  INT8_C(   0),  INT8_C(   0), -INT8_C(  36),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  58),  INT8_C(   0),  INT8_C( 120), -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 105),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  97),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 121), -INT8_C(  75),  INT8_C(   0),  INT8_C( 125),  INT8_C( 125),  INT8_C( 120),  INT8_C(  30), -INT8_C(  26) } },
    { UINT32_C(1962638041),
      { -INT8_C( 104), -INT8_C(  55), -INT8_C(  20), -INT8_C(   7),  INT8_C(  70),  INT8_C( 112),  INT8_C( 122),  INT8_C(  14),
         INT8_C(  69),  INT8_C(  64), -INT8_C(   8),  INT8_C(   7), -INT8_C(  99), -INT8_C(  34), -INT8_C(  47),  INT8_C( 122),
        -INT8_C( 109),  INT8_C(  74),  INT8_C( 109),  INT8_C( 125), -INT8_C(  14),  INT8_C(   9), -INT8_C(  47), -INT8_C(  38),
         INT8_C(  75),  INT8_C(  56),  INT8_C(  59),  INT8_C(  36), -INT8_C(  78),  INT8_C(  54), -INT8_C( 104),  INT8_C(  74) },
      { -INT8_C(   1), -INT8_C( 124),  INT8_C(  68),  INT8_C(  70), -INT8_C(  12), -INT8_C(  66),  INT8_C(  84),  INT8_C(  57),
        -INT8_C(   1),  INT8_C(  76),  INT8_C(  64), -INT8_C( 100),  INT8_C(  42),  INT8_C(  17),  INT8_C(  22), -INT8_C(  67),
         INT8_C(  91), -INT8_C( 125),  INT8_C(  59),  INT8_C(  77), -INT8_C( 115),  INT8_C(  12),  INT8_C(  40), -INT8_C(  40),
         INT8_C(  68),  INT8_C(  99), -INT8_C(   4), -INT8_C(  10), -INT8_C( 103), -INT8_C( 108),  INT8_C(  65), -INT8_C( 104) },
      {  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),  INT8_C(  99),  INT8_C(  84),  INT8_C(   0), -INT8_C(   4),  INT8_C(  22),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(  57), -INT8_C( 108),  INT8_C(  65), -INT8_C( 125),  INT8_C(   0),
         INT8_C(  77),  INT8_C(  64),  INT8_C(   0), -INT8_C( 108),  INT8_C(  59),  INT8_C(  76), -INT8_C( 125), -INT8_C(   4),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0),  INT8_C(  59),  INT8_C(  40),  INT8_C(  68),  INT8_C(   0) } },
    { UINT32_C( 215909656),
      {  INT8_C(  67),  INT8_C(  51),  INT8_C(  69),  INT8_C(  66),      INT8_MAX, -INT8_C( 122), -INT8_C(  33), -INT8_C(  86),
        -INT8_C( 105), -INT8_C(  11),  INT8_C( 103), -INT8_C(  13),  INT8_C( 121), -INT8_C(  94),  INT8_C(  64),  INT8_C(   6),
        -INT8_C(  81),  INT8_C( 104), -INT8_C(  34), -INT8_C(  13), -INT8_C(  53), -INT8_C(  38), -INT8_C(  22),  INT8_C( 100),
         INT8_C( 110),  INT8_C(  43), -INT8_C(   3), -INT8_C( 122), -INT8_C(  80), -INT8_C(  37), -INT8_C( 110), -INT8_C(  13) },
      {  INT8_C(  14), -INT8_C(  41),  INT8_C(  54), -INT8_C( 114),  INT8_C(  93),  INT8_C(  21),  INT8_C(  56), -INT8_C(  11),
         INT8_C(  10), -INT8_C(  97), -INT8_C(  24), -INT8_C( 125),  INT8_C(  66),  INT8_C(  40), -INT8_C( 119), -INT8_C(  15),
        -INT8_C( 111),  INT8_C( 103), -INT8_C(  28),  INT8_C(  92),  INT8_C(  65), -INT8_C(  50), -INT8_C(  63), -INT8_C(  81),
        -INT8_C(   7), -INT8_C(  66),  INT8_C(  53), -INT8_C(  87), -INT8_C( 103), -INT8_C(  57), -INT8_C(  99), -INT8_C(  88) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  54), -INT8_C(  88),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  81),  INT8_C(   0), -INT8_C(  11),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  56),
         INT8_C(   0),  INT8_C(  10), -INT8_C(  99),  INT8_C(  92), -INT8_C( 125),  INT8_C(   0), -INT8_C(  24),  INT8_C(  93),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  57),  INT8_C(  56),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(4231451551),
      { -INT8_C(  24),  INT8_C( 110), -INT8_C(  15), -INT8_C(  14),  INT8_C(  13), -INT8_C(  39),  INT8_C( 118),  INT8_C(  79),
         INT8_C(   2), -INT8_C(   1),  INT8_C(  64), -INT8_C( 109),  INT8_C( 103),  INT8_C(  37), -INT8_C(  17), -INT8_C(  88),
        -INT8_C(  13), -INT8_C(  80),  INT8_C(  88), -INT8_C(  19),  INT8_C( 110), -INT8_C( 115), -INT8_C( 106),  INT8_C(   8),
         INT8_C(  85),  INT8_C(  51), -INT8_C(  80), -INT8_C(  12),  INT8_C(   6), -INT8_C(  26), -INT8_C(  16), -INT8_C(  18) },
      {  INT8_C(  84), -INT8_C(  30), -INT8_C(  31),  INT8_C(  97), -INT8_C(  69),  INT8_C(  87), -INT8_C(  79), -INT8_C(  67),
         INT8_C(  86), -INT8_C(  15),  INT8_C(  80), -INT8_C(  67),  INT8_C(  22),  INT8_C(  64),  INT8_C( 102),  INT8_C(  10),
        -INT8_C(  16), -INT8_C(  66), -INT8_C(   9),  INT8_C(  95),  INT8_C(  75), -INT8_C( 115),  INT8_C( 103), -INT8_C(  96),
        -INT8_C(  63),  INT8_C(  23), -INT8_C( 108), -INT8_C(  57), -INT8_C(   3), -INT8_C( 123), -INT8_C(  74),  INT8_C(  81) },
      {  INT8_C(  86),  INT8_C( 102), -INT8_C(  66), -INT8_C(   9),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(  10),
        -INT8_C(  31),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),  INT8_C(  10),  INT8_C(  86),
         INT8_C(   0), -INT8_C(  16), -INT8_C(  63),  INT8_C(   0),  INT8_C( 102),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  16),  INT8_C(  75), -INT8_C(  79), -INT8_C(  79), -INT8_C(  16),  INT8_C( 102) } },
    { UINT32_C( 582129511),
      { -INT8_C(  18),  INT8_C(  99), -INT8_C(  32),  INT8_C(  68),  INT8_C(  85),  INT8_C(  48),  INT8_C(   2),  INT8_C( 107),
         INT8_C( 112),  INT8_C( 104),  INT8_C( 117),  INT8_C(  97),  INT8_C(  38),  INT8_C( 108), -INT8_C(  64),  INT8_C( 113),
        -INT8_C(   6),  INT8_C(  39),  INT8_C(  18), -INT8_C(  69),  INT8_C(  62), -INT8_C(  90), -INT8_C( 126),  INT8_C(  59),
         INT8_C(  43),  INT8_C(  56), -INT8_C( 116), -INT8_C( 110), -INT8_C(  49),  INT8_C(  62), -INT8_C(  75), -INT8_C(  67) },
      { -INT8_C(  94), -INT8_C( 107),  INT8_C(   2), -INT8_C(   9), -INT8_C(  59),  INT8_C(   4),  INT8_C(  98),  INT8_C(  54),
         INT8_C( 108), -INT8_C(  40), -INT8_C( 105), -INT8_C( 110),  INT8_C(  68),  INT8_C(  87),  INT8_C(   3),  INT8_C(  62),
         INT8_C( 126),  INT8_C(  21), -INT8_C(   7), -INT8_C(  68), -INT8_C(  68),  INT8_C( 124), -INT8_C(   9), -INT8_C(  25),
        -INT8_C(  76), -INT8_C( 125),  INT8_C( 122), -INT8_C( 124), -INT8_C(  63),  INT8_C(  47),  INT8_C(  65),  INT8_C(  99) },
      {  INT8_C(   3), -INT8_C(   9), -INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C( 126),  INT8_C(   2),  INT8_C(   0),
         INT8_C( 126),  INT8_C( 108),  INT8_C( 124),  INT8_C(   0),  INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(  21),
         INT8_C(   0),  INT8_C(  54),  INT8_C(   0),  INT8_C(   0),  INT8_C(  65),  INT8_C(  98),  INT8_C(   0), -INT8_C( 124),
         INT8_C(   0), -INT8_C(  76),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  65),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(2304394180),
      {  INT8_C(  71), -INT8_C(  67), -INT8_C(  65), -INT8_C(  77), -INT8_C( 107),  INT8_C(  86),  INT8_C(  69), -INT8_C(  39),
        -INT8_C(  83),  INT8_C(  73),  INT8_C(  24),  INT8_C(  43),  INT8_C(  94),  INT8_C(  17), -INT8_C(  25),  INT8_C(  26),
        -INT8_C( 115), -INT8_C(  34),  INT8_C(   2),  INT8_C(  66),  INT8_C(  97),  INT8_C( 124), -INT8_C(  58),  INT8_C(  35),
        -INT8_C(  85),  INT8_C(   7), -INT8_C( 122),  INT8_C( 111),  INT8_C(  75), -INT8_C(  31), -INT8_C(   8), -INT8_C( 110) },
      { -INT8_C(  98), -INT8_C(  72),  INT8_C(  70),  INT8_C(  51),  INT8_C(  14), -INT8_C( 117),  INT8_C(  12), -INT8_C(  68),
        -INT8_C(  44),  INT8_C(  36), -INT8_C(  25),  INT8_C(  51),  INT8_C(  54), -INT8_C(  49),  INT8_C(  77), -INT8_C(  61),
        -INT8_C(  83),  INT8_C(  79),  INT8_C(   5),  INT8_C(  15), -INT8_C(  53), -INT8_C(  53),  INT8_C(  50),  INT8_C( 118),
        -INT8_C(  45), -INT8_C(  72), -INT8_C(  27),  INT8_C(  30), -INT8_C( 103), -INT8_C(  34), -INT8_C(  80),  INT8_C(  55) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117), -INT8_C(  72),
        -INT8_C(  49),  INT8_C(  36),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  68),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  80),  INT8_C(   0),  INT8_C(  70), -INT8_C(  72),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),
         INT8_C(  51),  INT8_C(   0),  INT8_C(   0), -INT8_C(  61),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5) } },
    { UINT32_C(2758473366),
      { -INT8_C( 126),  INT8_C( 119),  INT8_C(  96),  INT8_C(  86), -INT8_C( 101),  INT8_C(  72), -INT8_C( 119), -INT8_C(  47),
         INT8_C(  23), -INT8_C(  41), -INT8_C( 107), -INT8_C(  60),  INT8_C(  38), -INT8_C( 102), -INT8_C(  45), -INT8_C(  14),
         INT8_C( 102),  INT8_C(   5),  INT8_C( 104),  INT8_C(  57), -INT8_C(  66),  INT8_C(  78),  INT8_C(  87),  INT8_C(  87),
         INT8_C(  44),  INT8_C(   7), -INT8_C( 113), -INT8_C(  62), -INT8_C(   2), -INT8_C(   7),  INT8_C( 102),      INT8_MIN },
      {  INT8_C( 112), -INT8_C(  57), -INT8_C(  42),  INT8_C(  12),  INT8_C(  15),  INT8_C(  96), -INT8_C(  35),  INT8_C(  38),
         INT8_C(  55),  INT8_C( 114), -INT8_C(  22),  INT8_C(  93),  INT8_C(  13), -INT8_C(  66),  INT8_C(  79),  INT8_C( 115),
        -INT8_C(  61), -INT8_C(  72), -INT8_C(  84), -INT8_C( 127),  INT8_C(   6),  INT8_C(   3), -INT8_C(  39),  INT8_C(  50),
         INT8_C(  10),  INT8_C( 104), -INT8_C(  12),  INT8_C(   8),  INT8_C(  97),  INT8_C(  90), -INT8_C( 120), -INT8_C(  46) },
      {  INT8_C(   0),  INT8_C(  50),  INT8_C( 112),  INT8_C(   0),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0), -INT8_C(  72),
         INT8_C(   0),  INT8_C(  50),  INT8_C(   3),  INT8_C(   0), -INT8_C(  35), -INT8_C(  12), -INT8_C( 127), -INT8_C(  84),
         INT8_C(   0),  INT8_C(  96),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),  INT8_C(  79),  INT8_C(  50),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 115),  INT8_C(   0),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),  INT8_C( 112) } },
    { UINT32_C( 819879713),
      { -INT8_C(  65), -INT8_C(  69),  INT8_C(  86), -INT8_C(  10),  INT8_C(  46),  INT8_C(  65),  INT8_C(  83),  INT8_C(  59),
        -INT8_C(   1), -INT8_C(  93), -INT8_C(  82), -INT8_C(  62),  INT8_C(  91),  INT8_C(  90),  INT8_C(  68),  INT8_C(  97),
         INT8_C(  93),  INT8_C(  29), -INT8_C( 109),  INT8_C( 103), -INT8_C( 123), -INT8_C( 121),  INT8_C( 112), -INT8_C(  26),
        -INT8_C(  31), -INT8_C(   8), -INT8_C(  72),  INT8_C(   3),  INT8_C(  87), -INT8_C( 106),  INT8_C(  51),  INT8_C(  22) },
      {  INT8_C(  82), -INT8_C( 118),  INT8_C(  12),      INT8_MIN, -INT8_C(  53),  INT8_C(  96), -INT8_C(  69), -INT8_C(  54),
         INT8_C(   3),  INT8_C( 105), -INT8_C( 116),  INT8_C(  94), -INT8_C(  61), -INT8_C(  48), -INT8_C(  65),  INT8_C(  32),
        -INT8_C(  19),  INT8_C(  82), -INT8_C( 121),  INT8_C( 114), -INT8_C(  39), -INT8_C(   9),  INT8_C(  89), -INT8_C(  70),
        -INT8_C(  16),  INT8_C(  17), -INT8_C(  67),  INT8_C(  71), -INT8_C(  88), -INT8_C(  15),  INT8_C(  94), -INT8_C(   6) },
      { -INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 118),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   6),      INT8_MIN, -INT8_C(  65),  INT8_C(  12),  INT8_C(  71),  INT8_C(   0), -INT8_C(  53),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  15),  INT8_C( 114), -INT8_C(  54),  INT8_C(  96),  INT8_C(   0), -INT8_C(  19), -INT8_C(  69),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  70),  INT8_C(  89),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_permutexvar_epi8(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_maskz_permutexvar_epi8(k, idx, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutexvar_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t idx[4];
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[8] = {
    { { -INT64_C( 6723175484270992638), -INT64_C( 4563869859770635283),  INT64_C(  651974606270245935), -INT64_C( 8302155520550445577) },
      { SIMDE_FLOAT64_C(  -770.65), SIMDE_FLOAT64_C(    51.51), SIMDE_FLOAT64_C(  -565.74), SIMDE_FLOAT64_C(   -26.48) },
      { SIMDE_FLOAT64_C(  -565.74), SIMDE_FLOAT64_C(    51.51), SIMDE_FLOAT64_C(   -26.48), SIMDE_FLOAT64_C(   -26.48) } },
    { { -INT64_C( 3631628342071142227), -INT64_C( 2150787199714573635), -INT64_C( 7382396981396950491),  INT64_C( 3653346760470123590) },
      { SIMDE_FLOAT64_C(   723.79), SIMDE_FLOAT64_C(   211.57), SIMDE_FLOAT64_C(  -703.04), SIMDE_FLOAT64_C(   319.79) },
      { SIMDE_FLOAT64_C(   211.57), SIMDE_FLOAT64_C(   211.57), SIMDE_FLOAT64_C(   211.57), SIMDE_FLOAT64_C(  -703.04) } },
    { {  INT64_C( 1789830837432444459),  INT64_C( 4531154689147468959),  INT64_C( 5070206288598101338), -INT64_C( 8515948049036931256) },
      { SIMDE_FLOAT64_C(   745.53), SIMDE_FLOAT64_C(  -121.69), SIMDE_FLOAT64_C(   436.39), SIMDE_FLOAT64_C(  -375.64) },
      { SIMDE_FLOAT64_C(  -375.64), SIMDE_FLOAT64_C(  -375.64), SIMDE_FLOAT64_C(   436.39), SIMDE_FLOAT64_C(   745.53) } },
    { {  INT64_C( 8298558806840658118),  INT64_C( 4127699110275910476),  INT64_C( 1241015148471100549), -INT64_C( 3152505381425837762) },
      { SIMDE_FLOAT64_C(   290.53), SIMDE_FLOAT64_C(   233.57), SIMDE_FLOAT64_C(  -508.59), SIMDE_FLOAT64_C(  -457.88) },
      { SIMDE_FLOAT64_C(  -508.59), SIMDE_FLOAT64_C(   290.53), SIMDE_FLOAT64_C(   233.57), SIMDE_FLOAT64_C(  -508.59) } },
    { { -INT64_C( 1870754788895005931), -INT64_C( 6297545250883808953), -INT64_C( 1530847991345524073), -INT64_C( 4227763291079966366) },
      { SIMDE_FLOAT64_C(   157.81), SIMDE_FLOAT64_C(  -884.15), SIMDE_FLOAT64_C(    58.01), SIMDE_FLOAT64_C(  -253.60) },
      { SIMDE_FLOAT64_C(  -884.15), SIMDE_FLOAT64_C(  -253.60), SIMDE_FLOAT64_C(  -253.60), SIMDE_FLOAT64_C(    58.01) } },
    { {  INT64_C( 8517097999991582751),  INT64_C( 8925246739055561838),  INT64_C( 5640797697215929645),  INT64_C( 1963352818527214362) },
      { SIMDE_FLOAT64_C(   338.84), SIMDE_FLOAT64_C(  -454.50), SIMDE_FLOAT64_C(  -481.79), SIMDE_FLOAT64_C(   868.84) },
      { SIMDE_FLOAT64_C(   868.84), SIMDE_FLOAT64_C(  -481.79), SIMDE_FLOAT64_C(  -454.50), SIMDE_FLOAT64_C(  -481.79) } },
    { {  INT64_C( 2248280827481928638),  INT64_C( 5338454049758515032), -INT64_C(  742341901610885598), -INT64_C( 7045158274482507291) },
      { SIMDE_FLOAT64_C(   669.60), SIMDE_FLOAT64_C(   -19.61), SIMDE_FLOAT64_C(   253.69), SIMDE_FLOAT64_C(   272.69) },
      { SIMDE_FLOAT64_C(   253.69), SIMDE_FLOAT64_C(   669.60), SIMDE_FLOAT64_C(   253.69), SIMDE_FLOAT64_C(   -19.61) } },
    { { -INT64_C( 5046144786224579045),  INT64_C( 7339632008068599421),  INT64_C( 6808716401325083976),  INT64_C( 7928525928940812285) },
      { SIMDE_FLOAT64_C(  -743.17), SIMDE_FLOAT64_C(   904.38), SIMDE_FLOAT64_C(   600.61), SIMDE_FLOAT64_C(  -731.72) },
      { SIMDE_FLOAT64_C(  -731.72), SIMDE_FLOAT64_C(   904.38), SIMDE_FLOAT64_C(  -743.17), SIMDE_FLOAT64_C(   904.38) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_permutexvar_pd(idx, a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_permutexvar_pd(idx, a);

    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutexvar_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const int64_t idx[4];
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C(  -749.78), SIMDE_FLOAT64_C(   320.61), SIMDE_FLOAT64_C(  -674.06), SIMDE_FLOAT64_C(  -589.15) },
      UINT8_C(231),
      { -INT64_C( 1263618822685620846), -INT64_C( 2847177519672810476), -INT64_C( 5739950126254014776),  INT64_C( 5493265346248387706) },
      { SIMDE_FLOAT64_C(  -516.97), SIMDE_FLOAT64_C(  -674.45), SIMDE_FLOAT64_C(  -986.75), SIMDE_FLOAT64_C(  -900.24) },
      { SIMDE_FLOAT64_C(  -986.75), SIMDE_FLOAT64_C(  -516.97), SIMDE_FLOAT64_C(  -516.97), SIMDE_FLOAT64_C(  -589.15) } },
    { { SIMDE_FLOAT64_C(  -673.90), SIMDE_FLOAT64_C(  -543.83), SIMDE_FLOAT64_C(  -527.91), SIMDE_FLOAT64_C(   493.44) },
      UINT8_C(149),
      {  INT64_C( 1644533322731674431), -INT64_C( 1815358867884973126), -INT64_C( 1429070044781862234),  INT64_C( 2444769474548862823) },
      { SIMDE_FLOAT64_C(  -140.49), SIMDE_FLOAT64_C(  -448.35), SIMDE_FLOAT64_C(   133.99), SIMDE_FLOAT64_C(   549.40) },
      { SIMDE_FLOAT64_C(   549.40), SIMDE_FLOAT64_C(  -543.83), SIMDE_FLOAT64_C(   133.99), SIMDE_FLOAT64_C(   493.44) } },
    { { SIMDE_FLOAT64_C(  -678.26), SIMDE_FLOAT64_C(   381.11), SIMDE_FLOAT64_C(   667.04), SIMDE_FLOAT64_C(   575.51) },
      UINT8_C( 97),
      {  INT64_C( 3452292845339951030), -INT64_C( 4037906182301774173), -INT64_C( 2401883995933946195), -INT64_C(   47292980296388873) },
      { SIMDE_FLOAT64_C(   948.31), SIMDE_FLOAT64_C(   488.58), SIMDE_FLOAT64_C(   153.16), SIMDE_FLOAT64_C(   778.73) },
      { SIMDE_FLOAT64_C(   153.16), SIMDE_FLOAT64_C(   381.11), SIMDE_FLOAT64_C(   667.04), SIMDE_FLOAT64_C(   575.51) } },
    { { SIMDE_FLOAT64_C(  -963.94), SIMDE_FLOAT64_C(   996.32), SIMDE_FLOAT64_C(   531.49), SIMDE_FLOAT64_C(  -945.52) },
      UINT8_C(185),
      { -INT64_C( 1357490459819988989),  INT64_C( 9197765586491828195),  INT64_C( 7227652815215696407),  INT64_C( 1075782015956718601) },
      { SIMDE_FLOAT64_C(   437.45), SIMDE_FLOAT64_C(  -523.92), SIMDE_FLOAT64_C(  -270.27), SIMDE_FLOAT64_C(  -213.44) },
      { SIMDE_FLOAT64_C(  -213.44), SIMDE_FLOAT64_C(   996.32), SIMDE_FLOAT64_C(   531.49), SIMDE_FLOAT64_C(  -523.92) } },
    { { SIMDE_FLOAT64_C(  -557.45), SIMDE_FLOAT64_C(  -121.42), SIMDE_FLOAT64_C(   881.29), SIMDE_FLOAT64_C(   967.43) },
      UINT8_C( 27),
      {  INT64_C( 7596636677954349646),  INT64_C( 6936880209947492212), -INT64_C( 4240568522068232039), -INT64_C( 3111184124717670653) },
      { SIMDE_FLOAT64_C(  -412.42), SIMDE_FLOAT64_C(   611.71), SIMDE_FLOAT64_C(   321.78), SIMDE_FLOAT64_C(   605.43) },
      { SIMDE_FLOAT64_C(   321.78), SIMDE_FLOAT64_C(  -412.42), SIMDE_FLOAT64_C(   881.29), SIMDE_FLOAT64_C(   605.43) } },
    { { SIMDE_FLOAT64_C(  -459.52), SIMDE_FLOAT64_C(  -808.78), SIMDE_FLOAT64_C(  -336.07), SIMDE_FLOAT64_C(   279.61) },
      UINT8_C( 21),
      {  INT64_C( 1580835613247101335),  INT64_C(  156008206567177389), -INT64_C( 5657545105993047650),  INT64_C( 2535661328087666565) },
      { SIMDE_FLOAT64_C(   650.97), SIMDE_FLOAT64_C(   966.14), SIMDE_FLOAT64_C(   607.62), SIMDE_FLOAT64_C(  -257.27) },
      { SIMDE_FLOAT64_C(  -257.27), SIMDE_FLOAT64_C(  -808.78), SIMDE_FLOAT64_C(   607.62), SIMDE_FLOAT64_C(   279.61) } },
    { { SIMDE_FLOAT64_C(   110.41), SIMDE_FLOAT64_C(  -827.61), SIMDE_FLOAT64_C(  -943.00), SIMDE_FLOAT64_C(  -461.29) },
      UINT8_C(231),
      {  INT64_C( 3594026778983278082),  INT64_C( 2591424474769545236),  INT64_C( 5999024786878894578),  INT64_C( 4295772386389045835) },
      { SIMDE_FLOAT64_C(   829.81), SIMDE_FLOAT64_C(   151.31), SIMDE_FLOAT64_C(  -948.92), SIMDE_FLOAT64_C(   823.99) },
      { SIMDE_FLOAT64_C(  -948.92), SIMDE_FLOAT64_C(   829.81), SIMDE_FLOAT64_C(  -948.92), SIMDE_FLOAT64_C(  -461.29) } },
    { { SIMDE_FLOAT64_C(   -83.93), SIMDE_FLOAT64_C(   443.69), SIMDE_FLOAT64_C(   453.64), SIMDE_FLOAT64_C(  -121.53) },
      UINT8_C(181),
      {  INT64_C( 4664511156021966899),  INT64_C( 1907227610614736986), -INT64_C( 1013434392324657796), -INT64_C( 8134225108301181685) },
      { SIMDE_FLOAT64_C(  -243.67), SIMDE_FLOAT64_C(   980.91), SIMDE_FLOAT64_C(  -312.16), SIMDE_FLOAT64_C(   981.49) },
      { SIMDE_FLOAT64_C(   981.49), SIMDE_FLOAT64_C(   443.69), SIMDE_FLOAT64_C(  -243.67), SIMDE_FLOAT64_C(  -121.53) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_mask_permutexvar_pd(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask_permutexvar_pd(src, k, idx, a);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutexvar_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t idx[4];
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[8] = {
    { UINT8_C( 82),
      {  INT64_C( 7756845172501845012), -INT64_C( 6825194156430213296),  INT64_C( 5503985742234073849),  INT64_C( 6858073262148153907) },
      { SIMDE_FLOAT64_C(   348.35), SIMDE_FLOAT64_C(   624.29), SIMDE_FLOAT64_C(  -664.85), SIMDE_FLOAT64_C(   199.21) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   348.35), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(178),
      { -INT64_C( 3741505294702552255),  INT64_C( 8638691756592248265), -INT64_C( 1915010472295649745), -INT64_C( 6324410229484237904) },
      { SIMDE_FLOAT64_C(  -819.48), SIMDE_FLOAT64_C(   -45.29), SIMDE_FLOAT64_C(  -250.63), SIMDE_FLOAT64_C(  -204.86) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -45.29), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(190),
      {  INT64_C( 3085962307915192508),  INT64_C( 8771176944555871084), -INT64_C( 8423505512529027354),  INT64_C( 2875934750950081261) },
      { SIMDE_FLOAT64_C(   493.35), SIMDE_FLOAT64_C(  -846.35), SIMDE_FLOAT64_C(  -448.39), SIMDE_FLOAT64_C(  -858.20) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   493.35), SIMDE_FLOAT64_C(  -448.39), SIMDE_FLOAT64_C(  -846.35) } },
    { UINT8_C(250),
      {  INT64_C( 6101534005241741420),  INT64_C(  195321988682229433),  INT64_C( 3689323120464773126),  INT64_C( 6948633058193660420) },
      { SIMDE_FLOAT64_C(  -979.67), SIMDE_FLOAT64_C(    -4.00), SIMDE_FLOAT64_C(   936.36), SIMDE_FLOAT64_C(  -772.83) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -4.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -979.67) } },
    { UINT8_C(212),
      {  INT64_C( 6141754755641061060),  INT64_C( 5237162096522378650), -INT64_C( 8240250253156228522), -INT64_C( 2245492898981346258) },
      { SIMDE_FLOAT64_C(   244.04), SIMDE_FLOAT64_C(   477.58), SIMDE_FLOAT64_C(  -396.44), SIMDE_FLOAT64_C(   196.16) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -396.44), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 73),
      { -INT64_C( 3354690591741684986), -INT64_C( 4153207234733033107), -INT64_C( 2333999889224701572),  INT64_C( 5511126413861026766) },
      { SIMDE_FLOAT64_C(   527.73), SIMDE_FLOAT64_C(  -488.23), SIMDE_FLOAT64_C(    -9.01), SIMDE_FLOAT64_C(  -402.49) },
      { SIMDE_FLOAT64_C(    -9.01), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -9.01) } },
    { UINT8_C( 30),
      {  INT64_C( 5170372545627244289),  INT64_C( 8329200236232935222),  INT64_C( 6962692482878502622),  INT64_C( 9109829307771383279) },
      { SIMDE_FLOAT64_C(  -972.26), SIMDE_FLOAT64_C(   204.27), SIMDE_FLOAT64_C(   393.26), SIMDE_FLOAT64_C(   414.79) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   393.26), SIMDE_FLOAT64_C(   393.26), SIMDE_FLOAT64_C(   414.79) } },
    { UINT8_C(209),
      { -INT64_C( 6774496452643677191),  INT64_C( 2603319939733352382),  INT64_C( 5036258758730416250), -INT64_C( 7811635825436106034) },
      { SIMDE_FLOAT64_C(  -877.39), SIMDE_FLOAT64_C(   290.97), SIMDE_FLOAT64_C(   735.30), SIMDE_FLOAT64_C(  -604.30) },
      { SIMDE_FLOAT64_C(   290.97), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_maskz_permutexvar_pd(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_maskz_permutexvar_pd(k, idx, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutexvar_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t idx[8];
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[8] = {
    { { -INT32_C(  1003465647), -INT32_C(   514585522),  INT32_C(  1936858576), -INT32_C(  2075224162),  INT32_C(  1915012941),  INT32_C(  1612493475),  INT32_C(  2023952200), -INT32_C(  1918079684) },
      { SIMDE_FLOAT32_C(  -948.78), SIMDE_FLOAT32_C(  -410.03), SIMDE_FLOAT32_C(  -879.71), SIMDE_FLOAT32_C(   201.10),
        SIMDE_FLOAT32_C(   452.67), SIMDE_FLOAT32_C(   820.53), SIMDE_FLOAT32_C(   280.22), SIMDE_FLOAT32_C(   700.21) },
      { SIMDE_FLOAT32_C(  -410.03), SIMDE_FLOAT32_C(   280.22), SIMDE_FLOAT32_C(  -948.78), SIMDE_FLOAT32_C(   280.22),
        SIMDE_FLOAT32_C(   820.53), SIMDE_FLOAT32_C(   201.10), SIMDE_FLOAT32_C(  -948.78), SIMDE_FLOAT32_C(   452.67) } },
    { {  INT32_C(  1630364355),  INT32_C(  1206221817), -INT32_C(   440858046),  INT32_C(    71751100),  INT32_C(   561834469),  INT32_C(   414067030), -INT32_C(   282656762),  INT32_C(  1772689574) },
      { SIMDE_FLOAT32_C(   591.13), SIMDE_FLOAT32_C(  -529.69), SIMDE_FLOAT32_C(  -654.92), SIMDE_FLOAT32_C(   391.52),
        SIMDE_FLOAT32_C(    -8.88), SIMDE_FLOAT32_C(  -562.27), SIMDE_FLOAT32_C(   -53.46), SIMDE_FLOAT32_C(   344.19) },
      { SIMDE_FLOAT32_C(   391.52), SIMDE_FLOAT32_C(  -529.69), SIMDE_FLOAT32_C(  -654.92), SIMDE_FLOAT32_C(    -8.88),
        SIMDE_FLOAT32_C(  -562.27), SIMDE_FLOAT32_C(   -53.46), SIMDE_FLOAT32_C(   -53.46), SIMDE_FLOAT32_C(   -53.46) } },
    { {  INT32_C(  1987736762),  INT32_C(   796573770),  INT32_C(     5306281),  INT32_C(   639172128), -INT32_C(  1525334017), -INT32_C(   770719913), -INT32_C(   398009706),  INT32_C(  1165820298) },
      { SIMDE_FLOAT32_C(   502.30), SIMDE_FLOAT32_C(  -922.61), SIMDE_FLOAT32_C(  -408.74), SIMDE_FLOAT32_C(   423.84),
        SIMDE_FLOAT32_C(  -781.34), SIMDE_FLOAT32_C(   645.58), SIMDE_FLOAT32_C(  -578.41), SIMDE_FLOAT32_C(  -100.81) },
      { SIMDE_FLOAT32_C(  -408.74), SIMDE_FLOAT32_C(  -408.74), SIMDE_FLOAT32_C(  -922.61), SIMDE_FLOAT32_C(   502.30),
        SIMDE_FLOAT32_C(  -100.81), SIMDE_FLOAT32_C(  -100.81), SIMDE_FLOAT32_C(  -578.41), SIMDE_FLOAT32_C(  -408.74) } },
    { {  INT32_C(  1298284077),  INT32_C(  1014200893),  INT32_C(   299993273), -INT32_C(   572264377),  INT32_C(  1439050186), -INT32_C(  1617280214), -INT32_C(   195078853), -INT32_C(  1202303605) },
      { SIMDE_FLOAT32_C(   114.38), SIMDE_FLOAT32_C(  -407.95), SIMDE_FLOAT32_C(  -190.09), SIMDE_FLOAT32_C(  -913.09),
        SIMDE_FLOAT32_C(  -594.00), SIMDE_FLOAT32_C(  -805.95), SIMDE_FLOAT32_C(   896.02), SIMDE_FLOAT32_C(   706.50) },
      { SIMDE_FLOAT32_C(  -805.95), SIMDE_FLOAT32_C(  -805.95), SIMDE_FLOAT32_C(  -407.95), SIMDE_FLOAT32_C(   706.50),
        SIMDE_FLOAT32_C(  -190.09), SIMDE_FLOAT32_C(  -190.09), SIMDE_FLOAT32_C(  -913.09), SIMDE_FLOAT32_C(  -913.09) } },
    { {  INT32_C(  1224533505), -INT32_C(  1591287849),  INT32_C(   855043080),  INT32_C(  1808961583),  INT32_C(  1902064102),  INT32_C(   170571134), -INT32_C(  1613549715), -INT32_C(  1450518360) },
      { SIMDE_FLOAT32_C(   408.50), SIMDE_FLOAT32_C(   -14.37), SIMDE_FLOAT32_C(  -881.14), SIMDE_FLOAT32_C(  -158.53),
        SIMDE_FLOAT32_C(  -555.96), SIMDE_FLOAT32_C(  -372.25), SIMDE_FLOAT32_C(    52.25), SIMDE_FLOAT32_C(   336.52) },
      { SIMDE_FLOAT32_C(   -14.37), SIMDE_FLOAT32_C(   336.52), SIMDE_FLOAT32_C(   408.50), SIMDE_FLOAT32_C(   336.52),
        SIMDE_FLOAT32_C(    52.25), SIMDE_FLOAT32_C(    52.25), SIMDE_FLOAT32_C(  -372.25), SIMDE_FLOAT32_C(   408.50) } },
    { {  INT32_C(   866201091), -INT32_C(  1533119554),  INT32_C(   588709284),  INT32_C(   523059378),  INT32_C(   398328175), -INT32_C(  1732228903),  INT32_C(   909030095), -INT32_C(   844798263) },
      { SIMDE_FLOAT32_C(  -302.01), SIMDE_FLOAT32_C(  -152.55), SIMDE_FLOAT32_C(  -912.35), SIMDE_FLOAT32_C(  -238.55),
        SIMDE_FLOAT32_C(   120.82), SIMDE_FLOAT32_C(  -497.21), SIMDE_FLOAT32_C(  -204.10), SIMDE_FLOAT32_C(  -635.30) },
      { SIMDE_FLOAT32_C(  -238.55), SIMDE_FLOAT32_C(  -204.10), SIMDE_FLOAT32_C(   120.82), SIMDE_FLOAT32_C(  -912.35),
        SIMDE_FLOAT32_C(  -635.30), SIMDE_FLOAT32_C(  -152.55), SIMDE_FLOAT32_C(  -635.30), SIMDE_FLOAT32_C(  -152.55) } },
    { {  INT32_C(  1300303259), -INT32_C(  1133727923), -INT32_C(  1982584144),  INT32_C(  1109562482),  INT32_C(   276320326),  INT32_C(  1256005046),  INT32_C(   496885091),  INT32_C(   377263227) },
      { SIMDE_FLOAT32_C(  -910.92), SIMDE_FLOAT32_C(    41.77), SIMDE_FLOAT32_C(  -614.35), SIMDE_FLOAT32_C(   -51.13),
        SIMDE_FLOAT32_C(   612.93), SIMDE_FLOAT32_C(   716.33), SIMDE_FLOAT32_C(  -728.68), SIMDE_FLOAT32_C(  -652.05) },
      { SIMDE_FLOAT32_C(   -51.13), SIMDE_FLOAT32_C(   716.33), SIMDE_FLOAT32_C(  -910.92), SIMDE_FLOAT32_C(  -614.35),
        SIMDE_FLOAT32_C(  -728.68), SIMDE_FLOAT32_C(  -728.68), SIMDE_FLOAT32_C(   -51.13), SIMDE_FLOAT32_C(   -51.13) } },
    { {  INT32_C(  1810267897),  INT32_C(  1504512019),  INT32_C(   258549080), -INT32_C(  1504098750), -INT32_C(  1631324637),  INT32_C(   733233034), -INT32_C(   384231619), -INT32_C(   549010202) },
      { SIMDE_FLOAT32_C(  -556.70), SIMDE_FLOAT32_C(  -412.20), SIMDE_FLOAT32_C(  -513.11), SIMDE_FLOAT32_C(   461.90),
        SIMDE_FLOAT32_C(  -797.86), SIMDE_FLOAT32_C(  -380.85), SIMDE_FLOAT32_C(  -514.89), SIMDE_FLOAT32_C(  -402.18) },
      { SIMDE_FLOAT32_C(  -412.20), SIMDE_FLOAT32_C(   461.90), SIMDE_FLOAT32_C(  -556.70), SIMDE_FLOAT32_C(  -513.11),
        SIMDE_FLOAT32_C(   461.90), SIMDE_FLOAT32_C(  -513.11), SIMDE_FLOAT32_C(  -380.85), SIMDE_FLOAT32_C(  -514.89) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_permutexvar_ps(idx, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_permutexvar_ps(idx, a);

    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutexvar_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const int32_t idx[8];
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -2.13), SIMDE_FLOAT32_C(  -740.45), SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(   497.57),
        SIMDE_FLOAT32_C(   218.90), SIMDE_FLOAT32_C(  -632.82), SIMDE_FLOAT32_C(  -495.65), SIMDE_FLOAT32_C(   553.04) },
      UINT8_C(  9),
      { -INT32_C(   806795204),  INT32_C(   982691045), -INT32_C(   417966830), -INT32_C(    75699523),  INT32_C(   241326701),  INT32_C(  1998051949), -INT32_C(  2006706479), -INT32_C(   795763308) },
      { SIMDE_FLOAT32_C(  -328.16), SIMDE_FLOAT32_C(  -360.93), SIMDE_FLOAT32_C(   935.10), SIMDE_FLOAT32_C(  -329.17),
        SIMDE_FLOAT32_C(  -862.40), SIMDE_FLOAT32_C(   392.03), SIMDE_FLOAT32_C(   803.30), SIMDE_FLOAT32_C(    62.01) },
      { SIMDE_FLOAT32_C(  -862.40), SIMDE_FLOAT32_C(  -740.45), SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(   392.03),
        SIMDE_FLOAT32_C(   218.90), SIMDE_FLOAT32_C(  -632.82), SIMDE_FLOAT32_C(  -495.65), SIMDE_FLOAT32_C(   553.04) } },
    { { SIMDE_FLOAT32_C(    71.98), SIMDE_FLOAT32_C(   655.74), SIMDE_FLOAT32_C(  -706.91), SIMDE_FLOAT32_C(  -789.78),
        SIMDE_FLOAT32_C(  -487.45), SIMDE_FLOAT32_C(   980.26), SIMDE_FLOAT32_C(   767.91), SIMDE_FLOAT32_C(  -611.76) },
      UINT8_C(247),
      {  INT32_C(  2070184353), -INT32_C(  1370694504), -INT32_C(   565979840), -INT32_C(   507243674), -INT32_C(   452423757), -INT32_C(  1335082604), -INT32_C(    21581727), -INT32_C(  1862981137) },
      { SIMDE_FLOAT32_C(   667.85), SIMDE_FLOAT32_C(   476.90), SIMDE_FLOAT32_C(  -690.52), SIMDE_FLOAT32_C(  -472.40),
        SIMDE_FLOAT32_C(  -496.30), SIMDE_FLOAT32_C(     3.74), SIMDE_FLOAT32_C(   619.63), SIMDE_FLOAT32_C(  -839.28) },
      { SIMDE_FLOAT32_C(   476.90), SIMDE_FLOAT32_C(   667.85), SIMDE_FLOAT32_C(   667.85), SIMDE_FLOAT32_C(  -789.78),
        SIMDE_FLOAT32_C(  -472.40), SIMDE_FLOAT32_C(  -496.30), SIMDE_FLOAT32_C(   476.90), SIMDE_FLOAT32_C(  -839.28) } },
    { { SIMDE_FLOAT32_C(   681.67), SIMDE_FLOAT32_C(   448.27), SIMDE_FLOAT32_C(  -999.01), SIMDE_FLOAT32_C(   -32.65),
        SIMDE_FLOAT32_C(   871.55), SIMDE_FLOAT32_C(  -486.89), SIMDE_FLOAT32_C(  -107.91), SIMDE_FLOAT32_C(  -770.07) },
      UINT8_C(167),
      { -INT32_C(  1103371907), -INT32_C(    31462579), -INT32_C(   890430047),  INT32_C(  1819639314), -INT32_C(   492717942), -INT32_C(   569370711), -INT32_C(  2094619541), -INT32_C(  1775623911) },
      { SIMDE_FLOAT32_C(   366.81), SIMDE_FLOAT32_C(   789.20), SIMDE_FLOAT32_C(   755.17), SIMDE_FLOAT32_C(  -830.47),
        SIMDE_FLOAT32_C(   113.51), SIMDE_FLOAT32_C(   251.44), SIMDE_FLOAT32_C(  -995.14), SIMDE_FLOAT32_C(   592.37) },
      { SIMDE_FLOAT32_C(   251.44), SIMDE_FLOAT32_C(   251.44), SIMDE_FLOAT32_C(   789.20), SIMDE_FLOAT32_C(   -32.65),
        SIMDE_FLOAT32_C(   871.55), SIMDE_FLOAT32_C(   789.20), SIMDE_FLOAT32_C(  -107.91), SIMDE_FLOAT32_C(   789.20) } },
    { { SIMDE_FLOAT32_C(  -854.58), SIMDE_FLOAT32_C(  -359.30), SIMDE_FLOAT32_C(   614.00), SIMDE_FLOAT32_C(   -99.17),
        SIMDE_FLOAT32_C(  -491.72), SIMDE_FLOAT32_C(   303.49), SIMDE_FLOAT32_C(   133.14), SIMDE_FLOAT32_C(  -314.65) },
      UINT8_C(234),
      { -INT32_C(   929814863), -INT32_C(   634097098), -INT32_C(  1175210088),  INT32_C(  1220315618),  INT32_C(  1352207581), -INT32_C(  1780380582),  INT32_C(  2085586250),  INT32_C(  1164415636) },
      { SIMDE_FLOAT32_C(  -573.04), SIMDE_FLOAT32_C(  -528.28), SIMDE_FLOAT32_C(  -222.24), SIMDE_FLOAT32_C(   155.58),
        SIMDE_FLOAT32_C(   114.00), SIMDE_FLOAT32_C(  -558.66), SIMDE_FLOAT32_C(   714.03), SIMDE_FLOAT32_C(   -87.19) },
      { SIMDE_FLOAT32_C(  -854.58), SIMDE_FLOAT32_C(   714.03), SIMDE_FLOAT32_C(   614.00), SIMDE_FLOAT32_C(  -222.24),
        SIMDE_FLOAT32_C(  -491.72), SIMDE_FLOAT32_C(  -222.24), SIMDE_FLOAT32_C(  -222.24), SIMDE_FLOAT32_C(   114.00) } },
    { { SIMDE_FLOAT32_C(   515.75), SIMDE_FLOAT32_C(    -5.60), SIMDE_FLOAT32_C(  -901.90), SIMDE_FLOAT32_C(   697.05),
        SIMDE_FLOAT32_C(   951.14), SIMDE_FLOAT32_C(  -349.81), SIMDE_FLOAT32_C(   667.55), SIMDE_FLOAT32_C(  -336.95) },
      UINT8_C(134),
      {  INT32_C(  1239446205), -INT32_C(   661424557),  INT32_C(  1466765509),  INT32_C(  1913696887),  INT32_C(    48234176), -INT32_C(  2097355577),  INT32_C(   499636130), -INT32_C(  1197217541) },
      { SIMDE_FLOAT32_C(   433.29), SIMDE_FLOAT32_C(   143.53), SIMDE_FLOAT32_C(  -821.67), SIMDE_FLOAT32_C(  -831.55),
        SIMDE_FLOAT32_C(  -391.00), SIMDE_FLOAT32_C(   896.63), SIMDE_FLOAT32_C(   913.22), SIMDE_FLOAT32_C(   949.92) },
      { SIMDE_FLOAT32_C(   515.75), SIMDE_FLOAT32_C(  -831.55), SIMDE_FLOAT32_C(   896.63), SIMDE_FLOAT32_C(   697.05),
        SIMDE_FLOAT32_C(   951.14), SIMDE_FLOAT32_C(  -349.81), SIMDE_FLOAT32_C(   667.55), SIMDE_FLOAT32_C(  -831.55) } },
    { { SIMDE_FLOAT32_C(   208.80), SIMDE_FLOAT32_C(   800.73), SIMDE_FLOAT32_C(   851.65), SIMDE_FLOAT32_C(   635.40),
        SIMDE_FLOAT32_C(   700.13), SIMDE_FLOAT32_C(  -819.67), SIMDE_FLOAT32_C(  -466.27), SIMDE_FLOAT32_C(  -622.72) },
      UINT8_C( 37),
      {  INT32_C(  1374447981),  INT32_C(  1022586469),  INT32_C(   506925109),  INT32_C(   947449780), -INT32_C(  2043533583), -INT32_C(  1607732819),  INT32_C(   776357639),  INT32_C(  1112780245) },
      { SIMDE_FLOAT32_C(  -104.78), SIMDE_FLOAT32_C(   475.03), SIMDE_FLOAT32_C(  -319.30), SIMDE_FLOAT32_C(    25.24),
        SIMDE_FLOAT32_C(  -469.36), SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(   486.55), SIMDE_FLOAT32_C(   730.10) },
      { SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(   800.73), SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(   635.40),
        SIMDE_FLOAT32_C(   700.13), SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(  -466.27), SIMDE_FLOAT32_C(  -622.72) } },
    { { SIMDE_FLOAT32_C(   342.99), SIMDE_FLOAT32_C(   946.71), SIMDE_FLOAT32_C(   736.44), SIMDE_FLOAT32_C(  -443.90),
        SIMDE_FLOAT32_C(   157.26), SIMDE_FLOAT32_C(   176.08), SIMDE_FLOAT32_C(   -87.27), SIMDE_FLOAT32_C(  -453.86) },
      UINT8_C(160),
      { -INT32_C(  1504881227), -INT32_C(   944902784), -INT32_C(   509813964),  INT32_C(  1844960814), -INT32_C(   132418959),  INT32_C(   412089897),  INT32_C(  2029509375),  INT32_C(   303613533) },
      { SIMDE_FLOAT32_C(   -62.11), SIMDE_FLOAT32_C(  -141.29), SIMDE_FLOAT32_C(   668.54), SIMDE_FLOAT32_C(   263.85),
        SIMDE_FLOAT32_C(  -513.77), SIMDE_FLOAT32_C(   229.65), SIMDE_FLOAT32_C(   719.52), SIMDE_FLOAT32_C(   135.92) },
      { SIMDE_FLOAT32_C(   342.99), SIMDE_FLOAT32_C(   946.71), SIMDE_FLOAT32_C(   736.44), SIMDE_FLOAT32_C(  -443.90),
        SIMDE_FLOAT32_C(   157.26), SIMDE_FLOAT32_C(  -141.29), SIMDE_FLOAT32_C(   -87.27), SIMDE_FLOAT32_C(   229.65) } },
    { { SIMDE_FLOAT32_C(   738.29), SIMDE_FLOAT32_C(  -161.36), SIMDE_FLOAT32_C(   185.05), SIMDE_FLOAT32_C(  -140.93),
        SIMDE_FLOAT32_C(   167.26), SIMDE_FLOAT32_C(  -870.60), SIMDE_FLOAT32_C(   454.87), SIMDE_FLOAT32_C(  -823.43) },
      UINT8_C(209),
      { -INT32_C(   151369480), -INT32_C(  1309338665), -INT32_C(   804360950), -INT32_C(   336846714),  INT32_C(  1044285912), -INT32_C(   310393363), -INT32_C(  1932726739), -INT32_C(  1017307701) },
      { SIMDE_FLOAT32_C(    89.09), SIMDE_FLOAT32_C(   802.57), SIMDE_FLOAT32_C(  -187.53), SIMDE_FLOAT32_C(   -22.46),
        SIMDE_FLOAT32_C(  -239.46), SIMDE_FLOAT32_C(  -156.70), SIMDE_FLOAT32_C(   -50.47), SIMDE_FLOAT32_C(  -721.38) },
      { SIMDE_FLOAT32_C(    89.09), SIMDE_FLOAT32_C(  -161.36), SIMDE_FLOAT32_C(   185.05), SIMDE_FLOAT32_C(  -140.93),
        SIMDE_FLOAT32_C(    89.09), SIMDE_FLOAT32_C(  -870.60), SIMDE_FLOAT32_C(  -156.70), SIMDE_FLOAT32_C(   -22.46) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_mask_permutexvar_ps(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_mask_permutexvar_ps(src, k, idx, a);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutexvar_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t idx[8];
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[8] = {
    { UINT8_C( 70),
      { -INT32_C(   451449221),  INT32_C(   638291178), -INT32_C(  1683155451),  INT32_C(  1763935515), -INT32_C(  1057453855),  INT32_C(   204563644),  INT32_C(   641593323),  INT32_C(  1265392848) },
      { SIMDE_FLOAT32_C(  -564.32), SIMDE_FLOAT32_C(  -573.78), SIMDE_FLOAT32_C(   632.73), SIMDE_FLOAT32_C(   965.26),
        SIMDE_FLOAT32_C(   840.88), SIMDE_FLOAT32_C(   -46.96), SIMDE_FLOAT32_C(   249.88), SIMDE_FLOAT32_C(   458.77) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   632.73), SIMDE_FLOAT32_C(   -46.96), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   965.26), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 81),
      {  INT32_C(   225292424),  INT32_C(  1542379219),  INT32_C(   840478414), -INT32_C(   836950817), -INT32_C(  1113701279),  INT32_C(   881322416),  INT32_C(  1413692441), -INT32_C(  1616488425) },
      { SIMDE_FLOAT32_C(  -724.50), SIMDE_FLOAT32_C(    39.62), SIMDE_FLOAT32_C(   808.79), SIMDE_FLOAT32_C(  -136.37),
        SIMDE_FLOAT32_C(   834.12), SIMDE_FLOAT32_C(   972.60), SIMDE_FLOAT32_C(  -952.76), SIMDE_FLOAT32_C(  -309.86) },
      { SIMDE_FLOAT32_C(  -724.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    39.62), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    39.62), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 73),
      {  INT32_C(  1932061263),  INT32_C(  1272248071),  INT32_C(  2147258773),  INT32_C(  1436037145), -INT32_C(   865211021), -INT32_C(  1496052589),  INT32_C(  1401925817),  INT32_C(   932988648) },
      { SIMDE_FLOAT32_C(   220.62), SIMDE_FLOAT32_C(  -582.61), SIMDE_FLOAT32_C(   -37.83), SIMDE_FLOAT32_C(   328.48),
        SIMDE_FLOAT32_C(  -771.08), SIMDE_FLOAT32_C(  -354.91), SIMDE_FLOAT32_C(   -96.61), SIMDE_FLOAT32_C(  -734.93) },
      { SIMDE_FLOAT32_C(  -734.93), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -582.61),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -582.61), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 17),
      { -INT32_C(  1356148609),  INT32_C(  1445166953), -INT32_C(   102109204),  INT32_C(  1957859267),  INT32_C(  1683752222),  INT32_C(  1737855906), -INT32_C(  1104949954), -INT32_C(   791710640) },
      { SIMDE_FLOAT32_C(   550.64), SIMDE_FLOAT32_C(   877.66), SIMDE_FLOAT32_C(   194.12), SIMDE_FLOAT32_C(    80.38),
        SIMDE_FLOAT32_C(   546.98), SIMDE_FLOAT32_C(  -364.43), SIMDE_FLOAT32_C(  -575.59), SIMDE_FLOAT32_C(   188.77) },
      { SIMDE_FLOAT32_C(   188.77), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -575.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(145),
      {  INT32_C(  2085969645),  INT32_C(   362465552), -INT32_C(  1195901403),  INT32_C(  1626807955), -INT32_C(  1229867711),  INT32_C(  2113634692), -INT32_C(  1544181504), -INT32_C(  1707844947) },
      { SIMDE_FLOAT32_C(   669.10), SIMDE_FLOAT32_C(    62.35), SIMDE_FLOAT32_C(   322.64), SIMDE_FLOAT32_C(   659.77),
        SIMDE_FLOAT32_C(  -547.87), SIMDE_FLOAT32_C(   -17.71), SIMDE_FLOAT32_C(  -408.07), SIMDE_FLOAT32_C(   710.86) },
      { SIMDE_FLOAT32_C(   -17.71), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    62.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -17.71) } },
    { UINT8_C(174),
      { -INT32_C(  1270730603), -INT32_C(   587881945), -INT32_C(   731862189),  INT32_C(  1339415974),  INT32_C(   771520722),  INT32_C(   921015980),  INT32_C(  1552461484),  INT32_C(   554369164) },
      { SIMDE_FLOAT32_C(  -536.25), SIMDE_FLOAT32_C(   201.89), SIMDE_FLOAT32_C(   308.61), SIMDE_FLOAT32_C(  -264.78),
        SIMDE_FLOAT32_C(  -918.21), SIMDE_FLOAT32_C(    87.10), SIMDE_FLOAT32_C(   915.83), SIMDE_FLOAT32_C(   129.09) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   129.09), SIMDE_FLOAT32_C(  -264.78), SIMDE_FLOAT32_C(   915.83),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -918.21), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -918.21) } },
    { UINT8_C(118),
      {  INT32_C(  1880954771),  INT32_C(  1682074860), -INT32_C(    15634583),  INT32_C(    61622101), -INT32_C(   812709681),  INT32_C(  1627369491),  INT32_C(  1364219526),  INT32_C(   482841481) },
      { SIMDE_FLOAT32_C(  -554.85), SIMDE_FLOAT32_C(   513.70), SIMDE_FLOAT32_C(  -876.79), SIMDE_FLOAT32_C(   468.50),
        SIMDE_FLOAT32_C(  -252.10), SIMDE_FLOAT32_C(  -307.53), SIMDE_FLOAT32_C(   168.50), SIMDE_FLOAT32_C(  -616.11) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -252.10), SIMDE_FLOAT32_C(   513.70), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -616.11), SIMDE_FLOAT32_C(   468.50), SIMDE_FLOAT32_C(   168.50), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 62),
      {  INT32_C(  1402190092),  INT32_C(  1847826021), -INT32_C(   696126939),  INT32_C(  1214046962), -INT32_C(   976048846),  INT32_C(  1500507764),  INT32_C(  1252656763),  INT32_C(   243819522) },
      { SIMDE_FLOAT32_C(   673.48), SIMDE_FLOAT32_C(  -869.39), SIMDE_FLOAT32_C(   -10.67), SIMDE_FLOAT32_C(    -6.27),
        SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(  -652.01), SIMDE_FLOAT32_C(   919.28), SIMDE_FLOAT32_C(  -434.77) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -652.01), SIMDE_FLOAT32_C(  -652.01), SIMDE_FLOAT32_C(   -10.67),
        SIMDE_FLOAT32_C(   -10.67), SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_maskz_permutexvar_ps(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_maskz_permutexvar_ps(k, idx, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t idx[32];
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C(  6047),  INT16_C( 25507),  INT16_C( 23210),  INT16_C( 31289), -INT16_C(  8917),  INT16_C( 16161),  INT16_C( 31147), -INT16_C( 31366),
        -INT16_C( 14183), -INT16_C( 15429), -INT16_C( 20721),  INT16_C( 11147),  INT16_C(  6367), -INT16_C( 21463), -INT16_C(  4483), -INT16_C(  8577),
         INT16_C(  8918), -INT16_C( 32702),  INT16_C( 31613), -INT16_C( 22278),  INT16_C(  7256),  INT16_C(   999),  INT16_C( 24981),  INT16_C( 11912),
         INT16_C( 17450),  INT16_C( 14833),  INT16_C( 31987), -INT16_C( 11676), -INT16_C( 29036),  INT16_C(  4734), -INT16_C(   644),  INT16_C( 21232) },
      {  INT16_C( 12832), -INT16_C( 25134), -INT16_C( 12883),  INT16_C(  1349),  INT16_C( 11497),  INT16_C( 32264), -INT16_C( 28275), -INT16_C( 18516),
        -INT16_C( 25131), -INT16_C( 14095),  INT16_C( 21785), -INT16_C( 21094),  INT16_C(  6371),  INT16_C( 24511), -INT16_C( 20459),  INT16_C( 13745),
        -INT16_C( 31518), -INT16_C( 28462),  INT16_C(  5969),  INT16_C( 14997), -INT16_C( 25021), -INT16_C( 11848),  INT16_C( 25647),  INT16_C(  1160),
         INT16_C( 30977),  INT16_C(  6860),  INT16_C( 26319), -INT16_C( 19769), -INT16_C( 30850), -INT16_C( 27886), -INT16_C( 15561),  INT16_C(  6601) },
      { -INT16_C( 25134),  INT16_C(  1349),  INT16_C( 21785),  INT16_C(  6860), -INT16_C( 21094), -INT16_C( 25134), -INT16_C( 21094),  INT16_C( 26319),
         INT16_C(  6860), -INT16_C( 19769),  INT16_C( 13745), -INT16_C( 21094),  INT16_C(  6601), -INT16_C( 14095), -INT16_C( 27886),  INT16_C(  6601),
         INT16_C( 25647), -INT16_C( 12883), -INT16_C( 27886),  INT16_C( 26319),  INT16_C( 30977), -INT16_C( 18516), -INT16_C( 11848), -INT16_C( 25131),
         INT16_C( 21785), -INT16_C( 28462),  INT16_C( 14997),  INT16_C( 11497), -INT16_C( 25021), -INT16_C( 15561), -INT16_C( 30850), -INT16_C( 31518) } },
    { { -INT16_C( 25785), -INT16_C( 26455),  INT16_C( 16307), -INT16_C(  2350), -INT16_C( 29987),  INT16_C(  3271),  INT16_C( 20718), -INT16_C(  4336),
        -INT16_C(  9015), -INT16_C( 26615), -INT16_C( 11966), -INT16_C( 16309),  INT16_C( 23896), -INT16_C( 28845),  INT16_C(  7200),  INT16_C( 26792),
         INT16_C( 21176),  INT16_C( 27392), -INT16_C( 11375),  INT16_C( 28257),  INT16_C( 10589),  INT16_C( 19578), -INT16_C( 30087),  INT16_C( 16955),
         INT16_C( 17766), -INT16_C( 22309),  INT16_C(  9750),  INT16_C( 28264), -INT16_C( 17533), -INT16_C( 23555), -INT16_C( 23080), -INT16_C( 28661) },
      {  INT16_C(  3319), -INT16_C( 30469),  INT16_C( 23775),  INT16_C( 15606),  INT16_C( 28805), -INT16_C(   376), -INT16_C( 15110),  INT16_C( 24641),
         INT16_C(  7177),  INT16_C(  7944),  INT16_C( 28738), -INT16_C( 14963), -INT16_C( 30164),  INT16_C(  1128),  INT16_C( 29743),  INT16_C( 10132),
        -INT16_C( 28800),  INT16_C( 24495), -INT16_C( 22805),  INT16_C( 29083),  INT16_C(  9238),  INT16_C(  4463), -INT16_C( 20248), -INT16_C(  3727),
         INT16_C( 31436),  INT16_C(  3600), -INT16_C( 25110),  INT16_C(  5843),  INT16_C( 15399),  INT16_C( 22042), -INT16_C( 20816),  INT16_C( 12413) },
      {  INT16_C( 24641),  INT16_C(  7944),  INT16_C( 29083), -INT16_C( 22805),  INT16_C( 22042),  INT16_C( 24641),  INT16_C( 29743), -INT16_C( 28800),
         INT16_C(  7944),  INT16_C(  7944),  INT16_C( 23775), -INT16_C( 14963),  INT16_C( 31436),  INT16_C( 29083),  INT16_C(  3319),  INT16_C(  7177),
         INT16_C( 31436),  INT16_C(  3319),  INT16_C( 24495), -INT16_C( 30469),  INT16_C( 22042), -INT16_C( 25110),  INT16_C(  3600),  INT16_C(  5843),
        -INT16_C( 15110),  INT16_C(  5843), -INT16_C( 20248),  INT16_C(  7177),  INT16_C( 15606),  INT16_C( 22042),  INT16_C( 31436), -INT16_C( 14963) } },
    { {  INT16_C( 11581),  INT16_C( 10639),  INT16_C( 10963), -INT16_C(  5734),  INT16_C(  2382),  INT16_C( 14074),  INT16_C( 27834), -INT16_C( 31193),
         INT16_C( 14310), -INT16_C( 12139),  INT16_C( 26836), -INT16_C(  1049),  INT16_C(   420),  INT16_C( 21586), -INT16_C( 12368), -INT16_C(  4732),
         INT16_C(  5116), -INT16_C( 12522), -INT16_C( 20418), -INT16_C( 29511), -INT16_C( 19526),  INT16_C( 29891), -INT16_C(  5601),  INT16_C(  1530),
        -INT16_C( 28894), -INT16_C(  2346), -INT16_C( 16904), -INT16_C( 25358),  INT16_C( 17598),  INT16_C( 28401),  INT16_C( 29971),  INT16_C(  4188) },
      {  INT16_C( 29321), -INT16_C( 14369), -INT16_C( 26589), -INT16_C(  8877),  INT16_C(  5708),  INT16_C( 27473),  INT16_C( 19201),  INT16_C(  9073),
         INT16_C( 18395), -INT16_C( 11495),  INT16_C(  2820), -INT16_C( 15761),  INT16_C( 24655),  INT16_C( 25393), -INT16_C( 29226),  INT16_C( 24435),
         INT16_C( 21247),  INT16_C(  8742),  INT16_C( 31211),  INT16_C( 14335),  INT16_C( 20624), -INT16_C( 28254),  INT16_C(  5020),  INT16_C( 30644),
        -INT16_C( 12966),  INT16_C( 24138), -INT16_C( 17959),  INT16_C( 10273),  INT16_C( 21018), -INT16_C(  3957), -INT16_C(   289), -INT16_C(  8625) },
      { -INT16_C(  3957),  INT16_C( 24435),  INT16_C( 14335), -INT16_C( 17959), -INT16_C( 29226), -INT16_C( 17959), -INT16_C( 17959),  INT16_C(  9073),
         INT16_C( 19201), -INT16_C( 28254),  INT16_C( 20624),  INT16_C(  9073),  INT16_C(  5708),  INT16_C( 31211),  INT16_C( 21247),  INT16_C(  5708),
         INT16_C( 21018),  INT16_C(  5020), -INT16_C(   289),  INT16_C( 24138), -INT16_C( 17959), -INT16_C(  8877), -INT16_C(  8625), -INT16_C( 17959),
        -INT16_C( 26589),  INT16_C(  5020), -INT16_C( 12966),  INT16_C( 31211), -INT16_C(   289),  INT16_C(  8742),  INT16_C( 14335),  INT16_C( 21018) } },
    { {  INT16_C( 30033),  INT16_C( 15361),  INT16_C(   238),  INT16_C( 32371),  INT16_C(  5457), -INT16_C(  4849), -INT16_C( 15575), -INT16_C( 31900),
        -INT16_C( 20847),  INT16_C( 27362),  INT16_C(   871), -INT16_C( 32366),  INT16_C(  7765),  INT16_C( 13425), -INT16_C( 16356),  INT16_C( 27922),
         INT16_C(  4917),  INT16_C(  9385),  INT16_C(  7188),  INT16_C( 26018), -INT16_C( 19918),  INT16_C( 23378), -INT16_C( 18827),  INT16_C(  1758),
        -INT16_C( 16284), -INT16_C( 13456),  INT16_C(   963),  INT16_C(  6221), -INT16_C( 16863),  INT16_C( 15692),  INT16_C( 24447), -INT16_C( 19285) },
      {  INT16_C( 21618), -INT16_C( 31016),  INT16_C( 31601), -INT16_C( 23573),  INT16_C( 15661), -INT16_C( 23810), -INT16_C(  8973),  INT16_C( 22441),
         INT16_C(  6557),  INT16_C( 24611),  INT16_C( 28700),  INT16_C( 15737), -INT16_C( 15058), -INT16_C( 21125),  INT16_C(  9764), -INT16_C( 26782),
         INT16_C( 14970), -INT16_C(  5347),  INT16_C(  2485), -INT16_C(  7538), -INT16_C( 29626),  INT16_C( 14981),  INT16_C( 11881),  INT16_C(  1681),
        -INT16_C( 19385),  INT16_C( 25702), -INT16_C(  8412),  INT16_C( 21409),  INT16_C(  7333), -INT16_C( 14080),  INT16_C( 25154), -INT16_C( 17056) },
      { -INT16_C(  5347), -INT16_C( 31016),  INT16_C(  9764), -INT16_C(  7538), -INT16_C(  5347), -INT16_C( 26782),  INT16_C( 24611),  INT16_C( 15661),
        -INT16_C(  5347),  INT16_C( 31601),  INT16_C( 22441),  INT16_C(  2485),  INT16_C( 14981), -INT16_C(  5347),  INT16_C(  7333),  INT16_C(  2485),
         INT16_C( 14981),  INT16_C( 24611), -INT16_C( 29626),  INT16_C( 31601),  INT16_C(  2485),  INT16_C(  2485),  INT16_C( 14981),  INT16_C( 25154),
         INT16_C( 15661),  INT16_C( 14970), -INT16_C( 23573), -INT16_C( 21125), -INT16_C( 31016), -INT16_C( 15058), -INT16_C( 17056),  INT16_C( 15737) } },
    { {  INT16_C( 32413),  INT16_C( 21160),  INT16_C( 14215), -INT16_C( 13003), -INT16_C( 17725),  INT16_C( 11271), -INT16_C( 26136),  INT16_C( 12082),
        -INT16_C( 26291),  INT16_C( 29331),  INT16_C( 13688),  INT16_C(  7621), -INT16_C( 15023), -INT16_C( 27417),  INT16_C( 18216), -INT16_C( 15023),
        -INT16_C(  1595),  INT16_C( 19479),  INT16_C( 19504), -INT16_C(  3046),  INT16_C(  8454), -INT16_C(  4576),  INT16_C( 21434),  INT16_C(  2078),
        -INT16_C( 19988),  INT16_C( 25722),  INT16_C( 16358),  INT16_C( 14466),  INT16_C( 26884),  INT16_C( 11468),  INT16_C(  7600),  INT16_C( 30449) },
      {  INT16_C(  2326),  INT16_C( 18370), -INT16_C(  9131),  INT16_C( 23611),  INT16_C( 23550), -INT16_C( 18358),  INT16_C( 26798), -INT16_C( 25920),
         INT16_C( 14874),  INT16_C(   255), -INT16_C( 32391),  INT16_C( 32312),  INT16_C(  1258), -INT16_C( 25942), -INT16_C( 25567),  INT16_C( 14352),
        -INT16_C( 11355), -INT16_C(  1409), -INT16_C( 17745), -INT16_C( 21162), -INT16_C( 24299), -INT16_C( 15258),  INT16_C(  9737),  INT16_C(  9054),
         INT16_C( 23905), -INT16_C(  9692),  INT16_C( 23774), -INT16_C( 14248),  INT16_C(   865), -INT16_C( 32157),  INT16_C( 29599),  INT16_C( 17594) },
      { -INT16_C( 32157),  INT16_C( 14874), -INT16_C( 25920), -INT16_C( 15258),  INT16_C( 23611), -INT16_C( 25920),  INT16_C( 14874), -INT16_C( 17745),
        -INT16_C( 25942), -INT16_C( 21162),  INT16_C( 23905), -INT16_C( 18358), -INT16_C(  1409), -INT16_C( 25920),  INT16_C( 14874), -INT16_C(  1409),
        -INT16_C( 18358),  INT16_C(  9054), -INT16_C( 11355),  INT16_C( 23774),  INT16_C( 26798),  INT16_C(  2326),  INT16_C( 23774),  INT16_C( 29599),
         INT16_C(  1258),  INT16_C( 23774),  INT16_C( 26798), -INT16_C(  9131),  INT16_C( 23550),  INT16_C(  1258), -INT16_C( 11355), -INT16_C(  1409) } },
    { {  INT16_C( 14662), -INT16_C(  2498), -INT16_C( 27149),  INT16_C(  2467),  INT16_C(  2358),  INT16_C( 16333),  INT16_C( 11056), -INT16_C( 28317),
        -INT16_C( 30839),  INT16_C( 26475), -INT16_C( 15133),  INT16_C( 17456), -INT16_C( 27705),  INT16_C( 26311), -INT16_C( 32506),  INT16_C( 19882),
        -INT16_C(  5957), -INT16_C( 20925), -INT16_C(  6531), -INT16_C( 19529), -INT16_C( 31504),  INT16_C(  8435),  INT16_C( 22192),  INT16_C( 14769),
         INT16_C(  7389), -INT16_C( 16224), -INT16_C( 12064), -INT16_C( 22779), -INT16_C( 13213),  INT16_C( 27149), -INT16_C( 18611),  INT16_C(  2231) },
      { -INT16_C(  1376),  INT16_C(  7607),  INT16_C( 28384), -INT16_C( 12079), -INT16_C( 15117), -INT16_C( 23568), -INT16_C( 24294), -INT16_C(  2084),
         INT16_C( 31934), -INT16_C( 24905), -INT16_C( 17331), -INT16_C( 20410),  INT16_C( 21384), -INT16_C( 10726), -INT16_C( 12021), -INT16_C( 21538),
        -INT16_C( 27189), -INT16_C( 21304), -INT16_C( 26364), -INT16_C(  2180),  INT16_C( 27997),  INT16_C( 30618),  INT16_C( 30222), -INT16_C( 13202),
         INT16_C(  9970),  INT16_C( 16235), -INT16_C( 19998),  INT16_C( 27632),  INT16_C(  2564),  INT16_C(  3905),  INT16_C(  8156), -INT16_C( 22598) },
      { -INT16_C( 24294),  INT16_C(  8156), -INT16_C(  2180), -INT16_C( 12079),  INT16_C( 30222), -INT16_C( 10726), -INT16_C( 27189), -INT16_C( 12079),
        -INT16_C( 24905), -INT16_C( 20410), -INT16_C( 12079), -INT16_C( 27189), -INT16_C(  2084), -INT16_C(  2084), -INT16_C( 24294), -INT16_C( 17331),
         INT16_C( 27632), -INT16_C( 12079),  INT16_C(  3905), -INT16_C( 13202), -INT16_C( 27189), -INT16_C(  2180), -INT16_C( 27189), -INT16_C( 21304),
         INT16_C(  3905), -INT16_C(  1376), -INT16_C(  1376), -INT16_C( 23568), -INT16_C( 12079), -INT16_C( 10726), -INT16_C( 10726), -INT16_C( 13202) } },
    { { -INT16_C( 31819), -INT16_C( 18093), -INT16_C( 12260),  INT16_C( 31408),  INT16_C( 19005),  INT16_C( 19441),  INT16_C( 24768), -INT16_C( 19944),
        -INT16_C( 31866),  INT16_C( 26866), -INT16_C(  7628),  INT16_C( 14547),  INT16_C(  5356), -INT16_C( 14264),  INT16_C(   564), -INT16_C(  5776),
        -INT16_C( 15483), -INT16_C( 23902),  INT16_C( 21139), -INT16_C( 12260),  INT16_C(  3484),  INT16_C( 23580),  INT16_C( 13421), -INT16_C(  3314),
         INT16_C(   183), -INT16_C(  5284),  INT16_C( 12258), -INT16_C( 12509),  INT16_C( 27460),  INT16_C( 30871),  INT16_C(  1902), -INT16_C(  3231) },
      {  INT16_C(   971),  INT16_C( 24213), -INT16_C( 20139), -INT16_C(  3793),  INT16_C( 19391),  INT16_C( 11341),  INT16_C( 23423),  INT16_C( 13856),
         INT16_C( 31836),  INT16_C( 15905),  INT16_C( 17579), -INT16_C(  4339), -INT16_C( 23120),  INT16_C(  7783), -INT16_C( 14164),  INT16_C( 30481),
        -INT16_C( 22581),  INT16_C(  8406),  INT16_C(  1368),  INT16_C(  5905),  INT16_C( 24144), -INT16_C( 12476),  INT16_C( 25786),  INT16_C(  5637),
         INT16_C(  9952), -INT16_C( 29868),  INT16_C( 25194),  INT16_C(  6779), -INT16_C(  7673), -INT16_C( 19656),  INT16_C( 19115),  INT16_C( 30251) },
      { -INT16_C( 12476),  INT16_C(  5905), -INT16_C(  7673), -INT16_C( 22581), -INT16_C( 19656),  INT16_C(  8406),  INT16_C(   971),  INT16_C(  9952),
         INT16_C( 23423),  INT16_C(  1368),  INT16_C( 24144),  INT16_C(  5905), -INT16_C( 23120),  INT16_C( 31836),  INT16_C( 24144), -INT16_C( 22581),
         INT16_C( 11341), -INT16_C( 20139),  INT16_C(  5905), -INT16_C(  7673), -INT16_C(  7673), -INT16_C(  7673),  INT16_C(  7783), -INT16_C( 14164),
         INT16_C(  5637), -INT16_C(  7673), -INT16_C( 20139), -INT16_C(  3793),  INT16_C( 19391),  INT16_C(  5637), -INT16_C( 14164),  INT16_C( 24213) } },
    { {  INT16_C(   497),  INT16_C( 18839), -INT16_C( 22522),  INT16_C( 22113), -INT16_C( 23289), -INT16_C( 16091),  INT16_C( 10761), -INT16_C(  5673),
         INT16_C( 11088), -INT16_C( 17804), -INT16_C(  4211), -INT16_C( 27435),  INT16_C(  3538),  INT16_C( 32072),  INT16_C( 29527),  INT16_C( 18675),
        -INT16_C( 30092),  INT16_C( 31378), -INT16_C(  3277),  INT16_C( 15056), -INT16_C(  2664), -INT16_C( 24069), -INT16_C( 11745),  INT16_C( 28554),
        -INT16_C(   259), -INT16_C( 29911), -INT16_C(   274), -INT16_C( 16353),  INT16_C( 26380),  INT16_C( 25405),  INT16_C( 12506),  INT16_C( 20140) },
      {  INT16_C( 16059), -INT16_C(  4408), -INT16_C( 26575), -INT16_C( 14040),  INT16_C(  9101), -INT16_C( 21398), -INT16_C(  2827), -INT16_C(  3557),
         INT16_C( 17906), -INT16_C(  8067), -INT16_C( 25277),  INT16_C( 20384), -INT16_C(  8956), -INT16_C(  8269),  INT16_C( 24334), -INT16_C( 14035),
        -INT16_C(  2403), -INT16_C( 12617), -INT16_C(  8306),  INT16_C(  7319),  INT16_C(   258), -INT16_C(  2104), -INT16_C(  6923), -INT16_C(  6167),
         INT16_C( 26409),  INT16_C( 27848),  INT16_C( 26628),  INT16_C(  2236),  INT16_C( 28486),  INT16_C( 21735),  INT16_C(  5582),  INT16_C( 27421) },
      { -INT16_C( 12617), -INT16_C(  6167), -INT16_C(  2827), -INT16_C(  4408), -INT16_C(  3557), -INT16_C( 21398), -INT16_C(  8067), -INT16_C(  6167),
        -INT16_C(  2403),  INT16_C(   258), -INT16_C(  8269), -INT16_C(  2104), -INT16_C(  8306),  INT16_C( 17906), -INT16_C(  6167),  INT16_C(  7319),
         INT16_C(   258), -INT16_C(  8306),  INT16_C(  7319), -INT16_C(  2403),  INT16_C( 26409),  INT16_C(  2236),  INT16_C( 27421), -INT16_C( 25277),
         INT16_C( 21735), -INT16_C(  8067),  INT16_C( 24334),  INT16_C( 27421), -INT16_C(  8956),  INT16_C( 21735),  INT16_C( 26628), -INT16_C(  8956) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_permutexvar_epi16(idx, a);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_permutexvar_epi16(idx, a);

    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t idx[32];
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 11253), -INT16_C( 26311), -INT16_C( 12109), -INT16_C( 19019),  INT16_C( 32465), -INT16_C( 14676), -INT16_C( 27294), -INT16_C( 29779),
         INT16_C( 30204),  INT16_C(   247), -INT16_C( 19490),  INT16_C(  9225), -INT16_C(  4062), -INT16_C(  3976), -INT16_C( 27387),  INT16_C(  4187),
        -INT16_C( 27543),  INT16_C(  7338),  INT16_C( 24420),  INT16_C( 13777),  INT16_C( 32221),  INT16_C( 16379), -INT16_C( 22254),  INT16_C(  4042),
        -INT16_C( 15842), -INT16_C(  1009),  INT16_C(  6261), -INT16_C( 26592), -INT16_C( 26615),  INT16_C(  3720), -INT16_C(  7123), -INT16_C( 27105) },
      UINT32_C(3719481720),
      { -INT16_C( 31960),  INT16_C(  1554),  INT16_C(  3584),  INT16_C(  4933),  INT16_C(  4279), -INT16_C( 10974),  INT16_C( 12754),  INT16_C( 18386),
        -INT16_C(  3510),  INT16_C( 21471),  INT16_C( 26763), -INT16_C( 18335), -INT16_C( 32692), -INT16_C( 15281),  INT16_C(   329),  INT16_C( 29345),
        -INT16_C( 19323), -INT16_C( 31368), -INT16_C( 16958),  INT16_C( 31128), -INT16_C( 17715), -INT16_C( 24754),  INT16_C(  8428),  INT16_C( 14055),
        -INT16_C( 14829), -INT16_C( 24951), -INT16_C(  5586),  INT16_C( 31318), -INT16_C( 23189), -INT16_C( 19393), -INT16_C(  8025),  INT16_C( 11302) },
      { -INT16_C( 24940),  INT16_C( 22193),  INT16_C( 19036),  INT16_C( 10703),  INT16_C(  7684), -INT16_C(  3895), -INT16_C( 20418),  INT16_C( 20774),
        -INT16_C( 20618), -INT16_C( 23057),  INT16_C( 18074),  INT16_C(  1311),  INT16_C( 24299), -INT16_C( 27975), -INT16_C(  8129), -INT16_C( 11330),
         INT16_C( 28798), -INT16_C(  9686), -INT16_C(  1606), -INT16_C( 16892), -INT16_C( 13033),  INT16_C( 22191), -INT16_C( 10883), -INT16_C(  3161),
        -INT16_C( 26747),  INT16_C(  8088), -INT16_C( 18211), -INT16_C( 14300), -INT16_C(  8938),  INT16_C( 21851),  INT16_C(  6589),  INT16_C( 15401) },
      { -INT16_C( 11253), -INT16_C( 26311), -INT16_C( 12109), -INT16_C(  3895), -INT16_C(  3161),  INT16_C( 19036), -INT16_C(  1606), -INT16_C( 29779),
         INT16_C( 18074),  INT16_C(   247), -INT16_C( 19490),  INT16_C( 22193), -INT16_C(  4062), -INT16_C(  3976), -INT16_C( 23057),  INT16_C( 22193),
        -INT16_C( 27543), -INT16_C( 26747),  INT16_C( 24420),  INT16_C( 13777), -INT16_C( 27975), -INT16_C(  8129), -INT16_C( 22254),  INT16_C( 20774),
        -INT16_C( 16892), -INT16_C(  1009), -INT16_C(  8129), -INT16_C( 10883),  INT16_C(  1311),  INT16_C(  3720),  INT16_C( 20774), -INT16_C( 20418) } },
    { {  INT16_C( 21385),  INT16_C( 17174),  INT16_C(  6732),  INT16_C( 25602), -INT16_C( 19993),  INT16_C( 25786),  INT16_C( 24966),  INT16_C(  2904),
        -INT16_C(  3848), -INT16_C( 10966),  INT16_C( 20136), -INT16_C( 16482), -INT16_C(  1748), -INT16_C(  5868),  INT16_C( 15634), -INT16_C( 25563),
         INT16_C( 15504), -INT16_C(  8737), -INT16_C(  7850),  INT16_C( 15937), -INT16_C(  1134),  INT16_C(  6562), -INT16_C(  1444),  INT16_C( 21796),
         INT16_C( 20459), -INT16_C( 27862), -INT16_C( 14179), -INT16_C( 13998),  INT16_C( 26561), -INT16_C( 11085), -INT16_C( 10076),  INT16_C( 13680) },
      UINT32_C(1796362004),
      {  INT16_C( 21297), -INT16_C( 15447),  INT16_C( 19278), -INT16_C( 21796),  INT16_C(   326),  INT16_C( 12799),  INT16_C( 10832), -INT16_C(  4668),
         INT16_C(  6130), -INT16_C( 19273),  INT16_C( 27262),  INT16_C(  8840), -INT16_C(  1982),  INT16_C( 22359),  INT16_C( 26951),  INT16_C( 30914),
         INT16_C( 27580),  INT16_C(  2620),  INT16_C(  6326), -INT16_C(   843), -INT16_C( 19431),  INT16_C( 26925), -INT16_C(  3362), -INT16_C( 11945),
         INT16_C(  3593), -INT16_C( 30843),  INT16_C(  3448), -INT16_C( 17751),  INT16_C(   261),  INT16_C( 19473), -INT16_C( 11414),  INT16_C( 10181) },
      {  INT16_C(   318), -INT16_C(  2767), -INT16_C(  6631),  INT16_C( 13297),  INT16_C(  8091),  INT16_C( 31132), -INT16_C(  3311),  INT16_C(  6730),
        -INT16_C( 12543),  INT16_C( 31137),  INT16_C( 19164), -INT16_C(  7884),  INT16_C( 17739), -INT16_C( 18898), -INT16_C(  3303),  INT16_C( 22493),
         INT16_C(  3828),  INT16_C(  3404),  INT16_C( 16117), -INT16_C( 28608), -INT16_C(  8867),  INT16_C( 28169),  INT16_C( 21712), -INT16_C( 11640),
         INT16_C( 10531),  INT16_C(    75),  INT16_C( 32627), -INT16_C( 16415),  INT16_C(  4037), -INT16_C(  8587),  INT16_C( 20994), -INT16_C(  2507) },
      {  INT16_C( 21385),  INT16_C( 17174), -INT16_C(  3303),  INT16_C( 25602), -INT16_C(  3311),  INT16_C( 25786),  INT16_C( 24966),  INT16_C(  2904),
         INT16_C( 16117), -INT16_C( 11640),  INT16_C( 20994), -INT16_C( 12543), -INT16_C(  1748), -INT16_C(  5868),  INT16_C(  6730), -INT16_C( 25563),
         INT16_C( 15504),  INT16_C(  4037), -INT16_C(  7850),  INT16_C( 15937),  INT16_C(    75),  INT16_C(  6562), -INT16_C(  1444),  INT16_C( 21796),
         INT16_C( 31137),  INT16_C( 31132), -INT16_C( 14179),  INT16_C( 31137),  INT16_C( 26561),  INT16_C(  3404),  INT16_C( 19164),  INT16_C( 13680) } },
    { { -INT16_C( 32160),  INT16_C( 21764),  INT16_C( 17600),  INT16_C(  7653), -INT16_C(  4319), -INT16_C(  3445),  INT16_C(  4931),  INT16_C( 26308),
         INT16_C(  3900), -INT16_C( 20634),  INT16_C( 18575),  INT16_C( 21614), -INT16_C(  7337),  INT16_C( 23090),  INT16_C( 26421), -INT16_C( 27056),
         INT16_C( 21737), -INT16_C( 22037), -INT16_C( 11879), -INT16_C( 17722),  INT16_C( 20928),  INT16_C(   940),  INT16_C( 28772), -INT16_C( 24471),
        -INT16_C( 12160),  INT16_C(  3920), -INT16_C( 16872),  INT16_C( 28515), -INT16_C( 27230), -INT16_C( 10295),  INT16_C(  6908), -INT16_C(  6547) },
      UINT32_C( 126835054),
      {  INT16_C( 22058), -INT16_C(  5438),  INT16_C( 28327),  INT16_C(  3309),  INT16_C( 22239),  INT16_C( 24492), -INT16_C(   986),  INT16_C( 15982),
        -INT16_C( 11845),  INT16_C( 23982),  INT16_C( 30566),  INT16_C( 25140), -INT16_C( 23919),  INT16_C(    72), -INT16_C(  9989),  INT16_C(  9479),
        -INT16_C( 14034), -INT16_C( 10993), -INT16_C(   968),  INT16_C(  6113), -INT16_C( 29102),  INT16_C( 31094), -INT16_C(  7030),  INT16_C( 17847),
         INT16_C( 26037),  INT16_C(  7074), -INT16_C( 10275),  INT16_C( 28285), -INT16_C( 14727),  INT16_C( 29806),  INT16_C( 30366), -INT16_C( 13159) },
      { -INT16_C( 22465),  INT16_C( 30625), -INT16_C( 31836), -INT16_C(  2418),  INT16_C(  1041), -INT16_C( 25745),  INT16_C( 10216), -INT16_C( 25119),
        -INT16_C( 31860),  INT16_C( 27064),  INT16_C( 13914), -INT16_C( 11304),  INT16_C( 18172), -INT16_C( 26041), -INT16_C(  8004), -INT16_C(   922),
         INT16_C(  1928),  INT16_C( 11379),  INT16_C(   650), -INT16_C( 25821), -INT16_C( 28154), -INT16_C(  4297),  INT16_C(  6329),  INT16_C( 18060),
         INT16_C( 17819), -INT16_C(  2385), -INT16_C( 30853),  INT16_C( 30665),  INT16_C(  4558), -INT16_C( 30191),  INT16_C( 30705),  INT16_C( 31366) },
      { -INT16_C( 32160), -INT16_C( 31836), -INT16_C( 25119), -INT16_C( 26041), -INT16_C(  4319),  INT16_C( 18172),  INT16_C( 10216),  INT16_C( 26308),
         INT16_C( 30665), -INT16_C( 20634),  INT16_C( 18575), -INT16_C( 28154),  INT16_C( 11379),  INT16_C( 23090),  INT16_C( 30665), -INT16_C( 27056),
        -INT16_C(  8004), -INT16_C(   922),  INT16_C( 17819),  INT16_C( 30625),  INT16_C( 20928),  INT16_C(   940),  INT16_C( 28772),  INT16_C( 18060),
        -INT16_C(  4297), -INT16_C( 31836), -INT16_C( 30191),  INT16_C( 28515), -INT16_C( 27230), -INT16_C( 10295),  INT16_C(  6908), -INT16_C(  6547) } },
    { { -INT16_C(  1410),  INT16_C(  2470), -INT16_C( 13828),  INT16_C(   676), -INT16_C(  9380),  INT16_C(  5617),  INT16_C( 32499), -INT16_C( 28837),
         INT16_C(  3011),  INT16_C( 16005),  INT16_C( 20114),  INT16_C( 24757), -INT16_C( 14753),  INT16_C( 20971),  INT16_C( 28989), -INT16_C( 17461),
         INT16_C( 29035),  INT16_C( 26564),  INT16_C( 26939), -INT16_C( 26774),  INT16_C( 23364),  INT16_C( 14508),  INT16_C(  2265), -INT16_C( 25401),
         INT16_C( 19475), -INT16_C( 23078), -INT16_C( 28774), -INT16_C(  1530), -INT16_C(  3755), -INT16_C( 28085),  INT16_C(  5730), -INT16_C( 12722) },
      UINT32_C(3258258055),
      { -INT16_C( 24709), -INT16_C( 16295),  INT16_C(  1787), -INT16_C( 11016), -INT16_C( 16626),  INT16_C(  8561),  INT16_C( 19211), -INT16_C( 23098),
        -INT16_C( 13093),  INT16_C( 12447), -INT16_C(  5443),  INT16_C(  8387),  INT16_C(  4352), -INT16_C( 30482),  INT16_C(  8995), -INT16_C( 24758),
        -INT16_C( 23357), -INT16_C( 16801),  INT16_C( 22442), -INT16_C( 18286),  INT16_C(   790),  INT16_C(  8665), -INT16_C( 24753),  INT16_C( 10950),
         INT16_C( 26220),  INT16_C( 10586),  INT16_C(  7504),  INT16_C( 20809),  INT16_C( 14126),  INT16_C( 21209),  INT16_C(  9051),  INT16_C(  7921) },
      {  INT16_C( 20679),  INT16_C( 29148),  INT16_C( 28327), -INT16_C( 17111),  INT16_C(   626), -INT16_C( 15906), -INT16_C( 23390),  INT16_C(  3819),
         INT16_C( 17674),  INT16_C( 23351), -INT16_C( 32413), -INT16_C( 28244), -INT16_C( 31304),  INT16_C(  5091), -INT16_C( 11096),  INT16_C( 28721),
         INT16_C(  3364), -INT16_C( 13343),  INT16_C(  2940), -INT16_C(  4472),  INT16_C( 26125), -INT16_C( 20561), -INT16_C( 26101),  INT16_C(  5565),
        -INT16_C(  2593),  INT16_C( 17008),  INT16_C(  7286),  INT16_C( 11988), -INT16_C( 18527),  INT16_C( 19010),  INT16_C( 29580), -INT16_C( 20294) },
      {  INT16_C( 11988),  INT16_C( 17008),  INT16_C( 11988),  INT16_C(   676), -INT16_C(  9380),  INT16_C(  5617),  INT16_C( 32499), -INT16_C( 23390),
         INT16_C(  3011), -INT16_C( 20294),  INT16_C( 20114),  INT16_C( 24757),  INT16_C( 20679),  INT16_C( 20971),  INT16_C( 28989), -INT16_C( 17461),
        -INT16_C( 17111),  INT16_C( 26564), -INT16_C( 32413), -INT16_C( 26774), -INT16_C( 26101),  INT16_C( 17008),  INT16_C(  2265), -INT16_C( 25401),
         INT16_C( 19475),  INT16_C(  7286), -INT16_C( 28774), -INT16_C(  1530), -INT16_C(  3755), -INT16_C( 28085),  INT16_C( 11988), -INT16_C( 13343) } },
    { { -INT16_C( 25727), -INT16_C(   644),  INT16_C(  1190), -INT16_C( 19221), -INT16_C( 26005),  INT16_C( 30307),  INT16_C(  8500),  INT16_C(  5003),
        -INT16_C(  1002), -INT16_C( 29610),  INT16_C( 10776), -INT16_C( 17734), -INT16_C(   799),  INT16_C( 27908), -INT16_C( 16784), -INT16_C(  3810),
        -INT16_C( 26023),  INT16_C(   238), -INT16_C(  9826),  INT16_C(  2484),  INT16_C(  6003), -INT16_C( 22657),  INT16_C(  2872),  INT16_C( 20154),
         INT16_C(  4103),  INT16_C(  8154), -INT16_C( 27334),  INT16_C(  7385), -INT16_C(  8815),  INT16_C(   393), -INT16_C( 22629), -INT16_C(  2574) },
      UINT32_C(3774210113),
      { -INT16_C( 22087),  INT16_C( 11497),  INT16_C( 27072), -INT16_C(  1581), -INT16_C( 29068),  INT16_C( 31559),  INT16_C(  8862), -INT16_C(  9830),
         INT16_C( 29879),  INT16_C( 18677),  INT16_C( 32337), -INT16_C(  4790),  INT16_C( 15398),  INT16_C( 26594), -INT16_C( 10467), -INT16_C( 10681),
         INT16_C( 12672),  INT16_C( 16387), -INT16_C( 10598),  INT16_C(  3641), -INT16_C( 32412),  INT16_C(   905),  INT16_C(  9123),  INT16_C( 23260),
        -INT16_C( 11881), -INT16_C(  5726), -INT16_C(  5041),  INT16_C( 30166), -INT16_C( 18391),  INT16_C( 18141),  INT16_C(  9359),  INT16_C(  3868) },
      {  INT16_C(  8021), -INT16_C(  4273), -INT16_C( 30218),  INT16_C( 23293), -INT16_C( 31222), -INT16_C( 21155),  INT16_C( 14762),  INT16_C( 16647),
        -INT16_C( 22262),  INT16_C( 23082),  INT16_C(   150), -INT16_C( 16433), -INT16_C( 21320),  INT16_C( 18181),  INT16_C(  8657),  INT16_C(  9814),
        -INT16_C( 22975),  INT16_C( 14102),  INT16_C(  4911),  INT16_C( 14737), -INT16_C(  4198),  INT16_C( 17638), -INT16_C(  4824),  INT16_C( 13189),
        -INT16_C( 20330),  INT16_C( 11405),  INT16_C( 23728),  INT16_C( 27115), -INT16_C(  4087), -INT16_C(  9552),  INT16_C(  1810),  INT16_C( 21248) },
      {  INT16_C( 11405), -INT16_C(   644),  INT16_C(  1190), -INT16_C( 19221), -INT16_C( 26005),  INT16_C( 30307),  INT16_C(  1810),  INT16_C(  5003),
        -INT16_C(  1002), -INT16_C( 29610),  INT16_C( 10776), -INT16_C( 17734), -INT16_C(   799), -INT16_C( 30218), -INT16_C(  9552),  INT16_C( 16647),
         INT16_C(  8021),  INT16_C(   238),  INT16_C( 23728),  INT16_C(  2484), -INT16_C( 31222),  INT16_C( 23082),  INT16_C( 23293), -INT16_C(  4087),
         INT16_C(  4103),  INT16_C(  8154), -INT16_C( 27334),  INT16_C(  7385), -INT16_C(  8815), -INT16_C(  9552),  INT16_C(  9814), -INT16_C(  4087) } },
    { {  INT16_C(  5805), -INT16_C(  9078),  INT16_C(  6954), -INT16_C( 15339), -INT16_C(  1270),  INT16_C( 13064), -INT16_C( 29208),  INT16_C( 32358),
        -INT16_C(  3267), -INT16_C(  4437), -INT16_C( 27057),  INT16_C( 22615),  INT16_C(  1927), -INT16_C( 26318),  INT16_C( 13070), -INT16_C( 17428),
         INT16_C( 30281),  INT16_C( 29591), -INT16_C( 21359), -INT16_C( 25545),  INT16_C( 16295), -INT16_C( 28721),  INT16_C( 13773),  INT16_C(  2574),
        -INT16_C( 18136),  INT16_C( 30712),  INT16_C( 20303), -INT16_C( 10544),  INT16_C(   599),  INT16_C( 25967),  INT16_C( 23349),  INT16_C( 32545) },
      UINT32_C(1676851409),
      {  INT16_C( 10853),  INT16_C(  3327), -INT16_C( 12695),  INT16_C( 13980), -INT16_C( 22013),  INT16_C( 11073),  INT16_C( 14691), -INT16_C( 19806),
         INT16_C( 29321), -INT16_C(  8055), -INT16_C(  1931), -INT16_C( 21947),  INT16_C( 26196),  INT16_C(  9513),  INT16_C(  7199), -INT16_C( 31608),
        -INT16_C( 30906), -INT16_C( 20592),  INT16_C( 11349),  INT16_C( 22758),  INT16_C( 10198),  INT16_C( 14723),  INT16_C(  9824), -INT16_C(  5652),
         INT16_C( 30104),  INT16_C(  3529),  INT16_C(  3949), -INT16_C( 15944), -INT16_C(  7819), -INT16_C( 27417),  INT16_C( 28669),  INT16_C( 17176) },
      { -INT16_C( 22025),  INT16_C( 19699), -INT16_C(  9771), -INT16_C( 21339),  INT16_C( 10240),  INT16_C( 24805), -INT16_C( 11954), -INT16_C(  6326),
         INT16_C(  4934), -INT16_C( 19212), -INT16_C( 21470), -INT16_C( 26507),  INT16_C( 23694), -INT16_C( 29908),  INT16_C( 17868), -INT16_C( 15409),
        -INT16_C( 15634), -INT16_C( 15601), -INT16_C( 19301), -INT16_C( 25745),  INT16_C( 21981),  INT16_C( 11259),  INT16_C( 17702),  INT16_C( 27922),
         INT16_C(  1881),  INT16_C( 31521), -INT16_C( 26957),  INT16_C( 16659),  INT16_C( 16627), -INT16_C( 16435), -INT16_C( 25467),  INT16_C( 29570) },
      {  INT16_C( 24805), -INT16_C(  9078),  INT16_C(  6954), -INT16_C( 15339), -INT16_C( 21339),  INT16_C( 13064), -INT16_C( 21339), -INT16_C(  9771),
        -INT16_C(  3267), -INT16_C(  4437), -INT16_C( 27057),  INT16_C( 24805),  INT16_C( 21981), -INT16_C( 19212),  INT16_C( 13070),  INT16_C(  4934),
         INT16_C( 30281), -INT16_C( 15634), -INT16_C( 21359), -INT16_C( 25545),  INT16_C( 17702), -INT16_C( 21339), -INT16_C( 22025),  INT16_C( 23694),
         INT16_C(  1881), -INT16_C( 19212),  INT16_C( 20303), -INT16_C( 10544),  INT16_C(   599), -INT16_C(  6326), -INT16_C( 16435),  INT16_C( 32545) } },
    { { -INT16_C( 28322), -INT16_C(  1738), -INT16_C( 22970),  INT16_C(  9108), -INT16_C( 28677),  INT16_C(  8526),  INT16_C( 25045),  INT16_C( 11918),
        -INT16_C( 20632),  INT16_C(  7081), -INT16_C( 17082),  INT16_C( 14685),  INT16_C( 11005), -INT16_C( 32008),  INT16_C( 31430),  INT16_C(  9461),
         INT16_C( 11019),  INT16_C( 20765), -INT16_C( 20015), -INT16_C( 13196), -INT16_C( 15552),  INT16_C(  5614),  INT16_C( 31780), -INT16_C( 29629),
        -INT16_C(  4820),  INT16_C( 29351),  INT16_C(  1194), -INT16_C( 22613), -INT16_C( 23762), -INT16_C(  3031),  INT16_C(  7709),  INT16_C( 10264) },
      UINT32_C( 460993865),
      { -INT16_C(  4378),  INT16_C( 10215), -INT16_C( 10831), -INT16_C( 10948), -INT16_C( 32686),  INT16_C( 32353),  INT16_C(  2413),  INT16_C(  6128),
        -INT16_C( 25843),  INT16_C( 15550), -INT16_C(  6338),  INT16_C( 23344),  INT16_C( 18693),  INT16_C( 20099), -INT16_C(   642),  INT16_C( 25961),
         INT16_C( 20972), -INT16_C( 25204), -INT16_C( 14298),  INT16_C( 30835), -INT16_C( 11192), -INT16_C( 18954), -INT16_C(  6435), -INT16_C(  5172),
        -INT16_C( 30079), -INT16_C( 16601),  INT16_C( 22385),  INT16_C( 30234), -INT16_C( 24928),  INT16_C(  8133),  INT16_C( 11931), -INT16_C( 30844) },
      {  INT16_C(  4223), -INT16_C( 23003), -INT16_C( 26408),  INT16_C(  8478),  INT16_C(  5484),  INT16_C( 19158), -INT16_C( 23557),  INT16_C( 32053),
         INT16_C( 23597), -INT16_C( 24772),  INT16_C( 22451),  INT16_C( 21525), -INT16_C(  9483), -INT16_C( 28557), -INT16_C(  2295), -INT16_C( 30696),
         INT16_C( 15623), -INT16_C(  8402),  INT16_C( 19925),  INT16_C( 16640), -INT16_C( 10398),  INT16_C( 23947), -INT16_C( 16262), -INT16_C( 22566),
         INT16_C(  5916), -INT16_C( 12218),  INT16_C( 23662),  INT16_C( 25380), -INT16_C( 26826),  INT16_C( 16371),  INT16_C(  2958), -INT16_C( 27192) },
      { -INT16_C( 23557), -INT16_C(  1738), -INT16_C( 22970), -INT16_C( 26826), -INT16_C( 28677),  INT16_C(  8526), -INT16_C( 28557),  INT16_C( 11918),
        -INT16_C( 28557),  INT16_C(  7081),  INT16_C(  2958),  INT16_C( 14685),  INT16_C( 19158),  INT16_C(  8478),  INT16_C( 31430),  INT16_C(  9461),
         INT16_C( 11019), -INT16_C(  9483), -INT16_C( 20015),  INT16_C( 16640),  INT16_C( 23597), -INT16_C( 16262),  INT16_C( 16371), -INT16_C( 29629),
        -INT16_C( 23003),  INT16_C( 32053),  INT16_C(  1194),  INT16_C( 23662),  INT16_C(  4223), -INT16_C(  3031),  INT16_C(  7709),  INT16_C( 10264) } },
    { { -INT16_C(  2488),  INT16_C(  7540),  INT16_C( 30019), -INT16_C( 23201), -INT16_C(  5556), -INT16_C( 14845), -INT16_C(  8789), -INT16_C( 14483),
        -INT16_C( 19212),  INT16_C( 25239), -INT16_C( 17648),  INT16_C( 18117), -INT16_C( 18094), -INT16_C(  8058),  INT16_C( 20164),  INT16_C(  3445),
        -INT16_C(  5564), -INT16_C( 30678), -INT16_C( 30369), -INT16_C( 21715),  INT16_C( 12404),  INT16_C(  8049), -INT16_C(  8690),  INT16_C(   742),
         INT16_C( 32402), -INT16_C( 23963),  INT16_C( 10809), -INT16_C( 29463),  INT16_C( 28643), -INT16_C( 22420), -INT16_C(  7491),  INT16_C(   437) },
      UINT32_C( 730456012),
      { -INT16_C( 18583), -INT16_C(  8746),  INT16_C( 18407), -INT16_C(  2564), -INT16_C(  7643), -INT16_C( 18184),  INT16_C( 23904), -INT16_C( 26022),
         INT16_C( 17287),  INT16_C( 27430), -INT16_C( 27982),  INT16_C( 28435), -INT16_C( 14220),  INT16_C( 16497), -INT16_C(  1369),  INT16_C(  4203),
         INT16_C( 16817), -INT16_C( 26131), -INT16_C(  5752), -INT16_C( 20850), -INT16_C( 31028),  INT16_C( 11366), -INT16_C( 16157),  INT16_C( 27590),
        -INT16_C(  5116), -INT16_C( 18730), -INT16_C(  5761), -INT16_C(  3290), -INT16_C( 26703),  INT16_C( 22580), -INT16_C( 24687),  INT16_C( 17257) },
      {  INT16_C( 22241),  INT16_C( 27100),  INT16_C( 27200),  INT16_C(  3095),  INT16_C( 32241), -INT16_C( 11208), -INT16_C(   194),  INT16_C( 16959),
         INT16_C(  5611),  INT16_C( 27384),  INT16_C(  7934), -INT16_C( 20642), -INT16_C( 27979),  INT16_C( 18184),  INT16_C( 28977),  INT16_C(  4746),
         INT16_C( 26311),  INT16_C(  1916), -INT16_C( 27696), -INT16_C( 16109),  INT16_C( 19473),  INT16_C( 20374), -INT16_C( 10933),  INT16_C( 13969),
        -INT16_C( 30229), -INT16_C(  5727), -INT16_C(    88),  INT16_C( 23961), -INT16_C( 24175), -INT16_C( 15708),  INT16_C( 11794), -INT16_C(  9771) },
      { -INT16_C(  2488),  INT16_C(  7540),  INT16_C( 16959), -INT16_C( 24175), -INT16_C(  5556), -INT16_C( 14845),  INT16_C( 22241), -INT16_C(    88),
         INT16_C( 16959), -INT16_C(   194), -INT16_C( 27696), -INT16_C( 16109),  INT16_C( 19473), -INT16_C(  8058),  INT16_C( 16959), -INT16_C( 20642),
         INT16_C(  1916), -INT16_C( 30678), -INT16_C( 30369),  INT16_C( 28977),  INT16_C( 12404),  INT16_C(  8049), -INT16_C(  8690), -INT16_C(   194),
         INT16_C( 32241), -INT16_C( 10933),  INT16_C( 10809), -INT16_C(   194),  INT16_C( 28643),  INT16_C( 19473), -INT16_C(  7491),  INT16_C(   437) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_permutexvar_epi16(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_permutexvar_epi16(src, k, idx, a);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_permutexvar_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t idx[32];
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(1709265300),
      { -INT16_C(  2844), -INT16_C(  2778), -INT16_C( 17344), -INT16_C( 29884), -INT16_C( 10862),  INT16_C( 32194),  INT16_C( 25439),  INT16_C(  1894),
        -INT16_C(   158), -INT16_C(  3228),  INT16_C(  2464), -INT16_C( 19787), -INT16_C( 30153), -INT16_C( 13172),  INT16_C( 28123), -INT16_C( 16335),
         INT16_C( 22369), -INT16_C( 23883), -INT16_C(  1516), -INT16_C( 22995), -INT16_C(  4145),  INT16_C( 11811), -INT16_C( 30382), -INT16_C( 19403),
        -INT16_C( 25975),  INT16_C( 10663),  INT16_C( 23971), -INT16_C(  9508),  INT16_C( 26855), -INT16_C( 15450), -INT16_C( 10283),  INT16_C( 13955) },
      {  INT16_C( 14383),  INT16_C( 17368),  INT16_C(  1586),  INT16_C(   745),  INT16_C(  3317),  INT16_C( 18480),  INT16_C( 26261),  INT16_C(  7932),
        -INT16_C( 23552), -INT16_C( 23736),  INT16_C(  9217), -INT16_C(  6019),  INT16_C(  9356),  INT16_C( 25003),  INT16_C( 12027),  INT16_C( 10903),
         INT16_C( 28775), -INT16_C( 26259),  INT16_C( 22134),  INT16_C( 27547), -INT16_C( 13214), -INT16_C(  1869), -INT16_C( 20430),  INT16_C( 12822),
         INT16_C( 24148),  INT16_C( 21973),  INT16_C( 21122),  INT16_C(  3645), -INT16_C(  5770),  INT16_C( 29295),  INT16_C(  1815),  INT16_C( 32412) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 14383),  INT16_C(     0),  INT16_C( 22134),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26261),
         INT16_C(  1586),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12822),  INT16_C(     0),  INT16_C(  3645),  INT16_C(     0),
         INT16_C( 17368),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   745),  INT16_C( 22134), -INT16_C(  1869),
        -INT16_C( 23736),  INT16_C(     0),  INT16_C(   745),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26261), -INT16_C(  1869),  INT16_C(     0) } },
    { UINT32_C(3977775735),
      { -INT16_C( 19616), -INT16_C( 15528),  INT16_C(  3199), -INT16_C( 20037), -INT16_C( 11844),  INT16_C(  4323), -INT16_C( 18384), -INT16_C( 19867),
        -INT16_C( 24053), -INT16_C( 32319),  INT16_C( 12427), -INT16_C( 23565), -INT16_C( 28617), -INT16_C( 20959),  INT16_C( 14746), -INT16_C(  1381),
        -INT16_C(  2835),  INT16_C( 27837),  INT16_C( 30720), -INT16_C( 17378),  INT16_C(   330),  INT16_C( 31436),  INT16_C( 12730), -INT16_C( 15060),
        -INT16_C(  4653),  INT16_C( 24390),  INT16_C( 14878),  INT16_C( 21762),  INT16_C(  9162),  INT16_C( 25604), -INT16_C( 24739),  INT16_C( 19038) },
      {  INT16_C(  7315), -INT16_C( 27722), -INT16_C( 11116), -INT16_C(  8625),  INT16_C(  7126), -INT16_C( 28584), -INT16_C( 31412),  INT16_C(  8277),
        -INT16_C( 25742), -INT16_C( 28545), -INT16_C( 32299), -INT16_C( 24602), -INT16_C(  5468),  INT16_C(   259),  INT16_C( 25225),  INT16_C(  7499),
         INT16_C(   638),  INT16_C(  4784),  INT16_C(   214), -INT16_C( 21263),  INT16_C( 18715),  INT16_C( 26684), -INT16_C( 28210),  INT16_C( 16776),
         INT16_C(  1837),  INT16_C(   721), -INT16_C( 18552),  INT16_C( 11426), -INT16_C( 23135),  INT16_C( 11054),  INT16_C( 30983), -INT16_C( 31416) },
      {  INT16_C(  7315),  INT16_C(  1837), -INT16_C( 31416),  INT16_C(     0), -INT16_C( 23135), -INT16_C(  8625),  INT16_C(   638),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 27722),  INT16_C(     0), -INT16_C( 21263),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30983), -INT16_C( 32299),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 21263),  INT16_C(     0),  INT16_C( 30983), -INT16_C( 11116),  INT16_C(     0),  INT16_C(  7126),  INT16_C( 11054),  INT16_C( 30983) } },
    { UINT32_C(1385756795),
      { -INT16_C( 30216),  INT16_C(  5374),  INT16_C( 15314), -INT16_C( 24196),  INT16_C(  1228), -INT16_C(  1566), -INT16_C( 19701), -INT16_C( 27652),
        -INT16_C( 24981),  INT16_C(  3263), -INT16_C(  4797),  INT16_C( 19255),  INT16_C( 32615), -INT16_C(  7472),  INT16_C( 26744),  INT16_C( 28724),
         INT16_C( 13297), -INT16_C( 15228),  INT16_C(   110),  INT16_C( 14949),  INT16_C( 18180),  INT16_C(  3892),  INT16_C( 12538),  INT16_C( 26018),
         INT16_C( 25294),  INT16_C(  4466), -INT16_C( 22193), -INT16_C( 18852),  INT16_C( 11561), -INT16_C( 24167), -INT16_C( 12907), -INT16_C( 30959) },
      { -INT16_C( 27136),  INT16_C( 28235), -INT16_C( 20330), -INT16_C( 25687), -INT16_C(  8713), -INT16_C(  3670),  INT16_C( 19725), -INT16_C(  9385),
        -INT16_C( 13905), -INT16_C(   276),  INT16_C( 18802), -INT16_C( 25675),  INT16_C( 20086),  INT16_C(  2876),  INT16_C( 19995),  INT16_C(  7314),
        -INT16_C(  8732),  INT16_C( 31370),  INT16_C( 13197), -INT16_C( 31723), -INT16_C( 16368),  INT16_C(  7542), -INT16_C( 13043), -INT16_C( 17160),
        -INT16_C(  6762),  INT16_C(  2234),  INT16_C( 28462), -INT16_C( 23388), -INT16_C(  8003), -INT16_C(  9809),  INT16_C( 16942),  INT16_C(  4853) },
      { -INT16_C(  6762),  INT16_C( 16942),  INT16_C(     0), -INT16_C(  8003),  INT16_C( 20086), -INT16_C( 20330), -INT16_C( 25675),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17160), -INT16_C(  9385), -INT16_C(  8732), -INT16_C(  6762), -INT16_C( 16368),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3670), -INT16_C(  8713),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20330),
         INT16_C(     0),  INT16_C( 13197),  INT16_C(     0),  INT16_C(     0), -INT16_C(   276),  INT16_C(     0),  INT16_C(  7542),  INT16_C(     0) } },
    { UINT32_C(2911731487),
      { -INT16_C( 23885), -INT16_C( 15567), -INT16_C( 22686),  INT16_C( 28641), -INT16_C(  9868),  INT16_C(  2603), -INT16_C(  6466), -INT16_C(  5101),
        -INT16_C( 18603),  INT16_C(  5008),  INT16_C( 16535), -INT16_C( 14612), -INT16_C(  7806), -INT16_C( 24104),  INT16_C( 25952),  INT16_C(  4942),
        -INT16_C( 32760),  INT16_C( 27351), -INT16_C( 18393), -INT16_C( 25382),  INT16_C(  1425),  INT16_C( 20646), -INT16_C( 17941),  INT16_C( 16700),
        -INT16_C( 12944),  INT16_C(  2132),  INT16_C( 16397), -INT16_C( 28722), -INT16_C( 23007), -INT16_C( 32464),  INT16_C( 32524),  INT16_C(  5269) },
      {  INT16_C( 27903),  INT16_C(  9854),  INT16_C( 22564), -INT16_C( 19006),  INT16_C( 26974),  INT16_C( 18693),  INT16_C( 16930), -INT16_C( 27766),
        -INT16_C(  8689),  INT16_C(  7323),  INT16_C( 26910),  INT16_C( 16299), -INT16_C(  9457),  INT16_C(  7105),  INT16_C( 22106),  INT16_C( 22831),
        -INT16_C( 20798), -INT16_C(  6528),  INT16_C( 16902),  INT16_C( 25755), -INT16_C( 24149), -INT16_C( 12626),  INT16_C( 14563), -INT16_C(  3487),
        -INT16_C(  1001),  INT16_C( 13582), -INT16_C( 18075),  INT16_C( 29813),  INT16_C( 13972), -INT16_C(  4208), -INT16_C( 16500),  INT16_C( 20040) },
      {  INT16_C( 25755), -INT16_C(  6528),  INT16_C( 22564),  INT16_C(  9854), -INT16_C( 24149),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 12626), -INT16_C( 20798), -INT16_C(  3487), -INT16_C(  9457),  INT16_C( 22564), -INT16_C(  1001),  INT16_C( 27903),  INT16_C(     0),
        -INT16_C(  8689),  INT16_C(     0), -INT16_C( 27766), -INT16_C( 18075),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13972),
        -INT16_C( 20798),  INT16_C(     0),  INT16_C(  7105),  INT16_C( 22106),  INT16_C(     0), -INT16_C( 20798),  INT16_C(     0), -INT16_C( 12626) } },
    { UINT32_C(1949616237),
      { -INT16_C( 12533), -INT16_C( 18728), -INT16_C( 31120),  INT16_C( 21380), -INT16_C(  6721), -INT16_C( 10683),  INT16_C( 21473),  INT16_C( 17931),
        -INT16_C( 32756), -INT16_C( 24133),  INT16_C( 19382),  INT16_C( 17040), -INT16_C( 10230),  INT16_C( 30864), -INT16_C( 15199), -INT16_C( 21268),
        -INT16_C( 15212),  INT16_C(  1122), -INT16_C(  6325),  INT16_C(  2648), -INT16_C( 25140), -INT16_C( 20768), -INT16_C(  5135), -INT16_C(   524),
        -INT16_C( 20628),  INT16_C(  8862),  INT16_C( 12026),  INT16_C(  1381), -INT16_C(  2809), -INT16_C( 22403),  INT16_C( 27066),  INT16_C( 20052) },
      { -INT16_C( 18899),  INT16_C( 30802), -INT16_C( 21859),  INT16_C( 27266),  INT16_C( 25160),  INT16_C( 14616),  INT16_C(  3150), -INT16_C( 17866),
        -INT16_C( 10820), -INT16_C( 18724),  INT16_C( 16643),  INT16_C(  2747),  INT16_C( 14391), -INT16_C(  3662),  INT16_C(  1697), -INT16_C( 12481),
        -INT16_C( 28227),  INT16_C( 23111), -INT16_C( 13764), -INT16_C( 31548), -INT16_C(  9172),  INT16_C( 31421), -INT16_C(  3095), -INT16_C( 23244),
         INT16_C(  4552), -INT16_C( 13221),  INT16_C(  5970), -INT16_C( 30250), -INT16_C( 30385), -INT16_C(  3718), -INT16_C( 18033),  INT16_C( 19648) },
      {  INT16_C(  2747),  INT16_C(     0), -INT16_C( 28227),  INT16_C( 25160),  INT16_C(     0),  INT16_C( 14616),  INT16_C( 30802),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28227),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30802),  INT16_C( 14391),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  2747),  INT16_C(     0),  INT16_C( 14391), -INT16_C( 18899),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  5970),  INT16_C(     0), -INT16_C( 17866), -INT16_C(  3718),  INT16_C(  5970),  INT16_C(     0) } },
    { UINT32_C(2275870539),
      {  INT16_C( 27601), -INT16_C(   501), -INT16_C( 14264),  INT16_C( 12664), -INT16_C( 21061), -INT16_C( 31530),  INT16_C( 12734),  INT16_C(  4176),
         INT16_C(  9800), -INT16_C( 26470),  INT16_C(  5295),  INT16_C( 16265),  INT16_C( 18894),  INT16_C(  6539),  INT16_C( 12880),  INT16_C(  8864),
        -INT16_C( 21602), -INT16_C(  6624), -INT16_C( 26509),  INT16_C( 11799), -INT16_C(  4795),  INT16_C(   946),  INT16_C(   542),  INT16_C( 26388),
        -INT16_C( 20951), -INT16_C(  9985), -INT16_C( 30526), -INT16_C( 28649), -INT16_C( 23599),  INT16_C(  8617),  INT16_C( 18901),  INT16_C( 29507) },
      {  INT16_C( 25588),  INT16_C( 26457),  INT16_C( 28924),  INT16_C( 16790),  INT16_C( 18525),  INT16_C( 31813),  INT16_C( 22859),  INT16_C( 29923),
        -INT16_C(  7673), -INT16_C( 14004),  INT16_C( 25706),  INT16_C( 15194),  INT16_C(   775), -INT16_C(  9124), -INT16_C( 24499),  INT16_C( 16720),
        -INT16_C( 22269), -INT16_C(    87),  INT16_C( 16154),  INT16_C( 30529), -INT16_C( 31097), -INT16_C( 11533), -INT16_C( 10529), -INT16_C(  6586),
        -INT16_C( 27720),  INT16_C(  8879),  INT16_C(  2551), -INT16_C(   419), -INT16_C( 17907),  INT16_C( 23258),  INT16_C( 10842),  INT16_C( 23963) },
      { -INT16_C(    87),  INT16_C( 15194),  INT16_C(     0), -INT16_C( 27720),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10842),  INT16_C(     0),
        -INT16_C(  7673),  INT16_C(  2551),  INT16_C( 16720),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 10842),  INT16_C( 25588),  INT16_C( 30529),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16154),  INT16_C(     0), -INT16_C( 31097),
        -INT16_C( 14004),  INT16_C( 23963),  INT16_C( 28924),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16790) } },
    { UINT32_C(3999089876),
      { -INT16_C( 24957),  INT16_C(  2917),  INT16_C( 22820),  INT16_C(   989),  INT16_C(  9263), -INT16_C(  5911), -INT16_C( 26441), -INT16_C( 20982),
         INT16_C( 26786), -INT16_C( 20564), -INT16_C( 31198),  INT16_C( 31753), -INT16_C( 23375), -INT16_C( 31271),  INT16_C( 14057),  INT16_C( 27763),
        -INT16_C( 10028), -INT16_C(  1929),  INT16_C( 21809),  INT16_C( 25083), -INT16_C(  7047),  INT16_C( 12361),  INT16_C( 21373),  INT16_C(  8158),
        -INT16_C( 30021), -INT16_C(  8754), -INT16_C( 10480), -INT16_C( 16039),  INT16_C( 13179),  INT16_C( 25670), -INT16_C( 18071),  INT16_C( 16081) },
      {  INT16_C( 18578), -INT16_C( 15562),  INT16_C( 12957),  INT16_C(  5668),  INT16_C( 27926), -INT16_C( 27834),  INT16_C(  9409),  INT16_C( 31922),
        -INT16_C( 32594), -INT16_C( 16550), -INT16_C( 19625), -INT16_C( 11392), -INT16_C( 14362),  INT16_C( 20535),  INT16_C(  2176),  INT16_C(  4750),
        -INT16_C( 15279), -INT16_C(  4394), -INT16_C(  1290),  INT16_C(  3333),  INT16_C( 19304),  INT16_C( 10656),  INT16_C( 21360),  INT16_C(  7845),
        -INT16_C(    45),  INT16_C( 11229),  INT16_C( 24243), -INT16_C( 26114),  INT16_C( 13605), -INT16_C( 23063),  INT16_C( 30526), -INT16_C( 28744) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 27926),  INT16_C(     0),  INT16_C(  4750),  INT16_C(     0),  INT16_C(  7845), -INT16_C( 19625),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 12957),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16550),  INT16_C(     0),
         INT16_C( 19304),  INT16_C(     0), -INT16_C(  4394), -INT16_C( 26114),  INT16_C( 11229),  INT16_C(     0), -INT16_C( 23063),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  2176), -INT16_C( 15279),  INT16_C( 11229),  INT16_C(     0),  INT16_C(  9409), -INT16_C( 16550), -INT16_C(  4394) } },
    { UINT32_C( 847089212),
      { -INT16_C( 32120), -INT16_C(  4033), -INT16_C(  7986),  INT16_C( 15897), -INT16_C( 16589),  INT16_C(  1628),  INT16_C( 15038),  INT16_C( 28977),
         INT16_C( 12184), -INT16_C( 17141), -INT16_C(  2971), -INT16_C( 23710),  INT16_C(  6764), -INT16_C( 22478), -INT16_C( 20568),  INT16_C( 12762),
         INT16_C(  6706),  INT16_C(    33),  INT16_C( 15354),  INT16_C( 11582), -INT16_C( 25862), -INT16_C( 18381),  INT16_C( 26068),  INT16_C( 27690),
         INT16_C( 13716), -INT16_C(  1751), -INT16_C( 29655), -INT16_C( 27236), -INT16_C( 12634),  INT16_C( 20285),  INT16_C(  6270), -INT16_C( 20352) },
      { -INT16_C( 24270),  INT16_C( 11440), -INT16_C(  4388), -INT16_C( 10663), -INT16_C( 29560),  INT16_C( 23951), -INT16_C( 17935), -INT16_C( 31031),
        -INT16_C(  3090),  INT16_C(  6015),  INT16_C(  7295),  INT16_C(  9645), -INT16_C(  5398),  INT16_C( 26740), -INT16_C(  3070),  INT16_C( 13336),
        -INT16_C( 14186),  INT16_C( 29280), -INT16_C( 17994),  INT16_C( 16201), -INT16_C( 10170),  INT16_C( 14236),  INT16_C( 26001),  INT16_C( 32701),
         INT16_C( 15704), -INT16_C( 10346),  INT16_C( 17241),  INT16_C( 17405),  INT16_C( 28974),  INT16_C( 12460), -INT16_C( 15258), -INT16_C(   923) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(  3070), -INT16_C( 10346),  INT16_C( 16201),  INT16_C( 28974),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  9645),  INT16_C( 23951), -INT16_C(  4388),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17241),
        -INT16_C( 17994),  INT16_C(     0),  INT16_C( 17241), -INT16_C( 15258),  INT16_C( 17241),  INT16_C( 16201), -INT16_C( 10170),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  6015),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17935),  INT16_C( 12460),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_permutexvar_epi16(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_permutexvar_epi16(k, idx, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_permutexvar_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i idx;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1996766677), INT32_C(  914731069), INT32_C( 1945861252), INT32_C(  879354074),
                            INT32_C( -643998219), INT32_C( -855842922), INT32_C( 1434025670), INT32_C( -672258087),
                            INT32_C( 1290251647), INT32_C(-1094826982), INT32_C(  238338636), INT32_C( -252228416),
                            INT32_C(  122123135), INT32_C(  750368606), INT32_C( -381589944), INT32_C(  924273218)),
      simde_mm512_set_epi32(INT32_C( -879327216), INT32_C( 1748554959), INT32_C(-1487719285), INT32_C( 1548675310),
                            INT32_C( -557015483), INT32_C(-2047402472), INT32_C( -322319998), INT32_C( 1785739054),
                            INT32_C(  318403170), INT32_C(-1131639819), INT32_C(-1187670028), INT32_C(  146529946),
                            INT32_C(-1037158278), INT32_C(  297634970), INT32_C( 1928669860), INT32_C( -102995392)),
      simde_mm512_set_epi32(INT32_C(-1187670028), INT32_C(-1487719285), INT32_C(  146529946), INT32_C(-2047402472),
                            INT32_C(-1187670028), INT32_C(-1131639819), INT32_C(-1131639819), INT32_C( -322319998),
                            INT32_C( -879327216), INT32_C(-2047402472), INT32_C( 1548675310), INT32_C( -102995392),
                            INT32_C( -879327216), INT32_C( 1748554959), INT32_C( 1785739054), INT32_C(  297634970)) },
    { simde_mm512_set_epi32(INT32_C( 1106394199), INT32_C( 1786608232), INT32_C(  477078085), INT32_C(-1779632362),
                            INT32_C( -966979640), INT32_C( -998912797), INT32_C( 1045049163), INT32_C(-1292333722),
                            INT32_C( 1183794740), INT32_C( -731066686), INT32_C(  511551854), INT32_C( 1167565783),
                            INT32_C(  809184406), INT32_C(-1484085267), INT32_C( -106978631), INT32_C(-1748122897)),
      simde_mm512_set_epi32(INT32_C( -572206162), INT32_C(-1229665005), INT32_C(-2082924696), INT32_C( -649416979),
                            INT32_C( 2112092702), INT32_C( -909261280), INT32_C(-1418185146), INT32_C(-1714733997),
                            INT32_C( 1030181563), INT32_C( -291680665), INT32_C(-1617776213), INT32_C( 2112788110),
                            INT32_C(  207483507), INT32_C( 1144876369), INT32_C( 1177485782), INT32_C( 1952824319)),
      simde_mm512_set_epi32(INT32_C( 1030181563), INT32_C(-1714733997), INT32_C(-1617776213), INT32_C( -291680665),
                            INT32_C(-1714733997), INT32_C(  207483507), INT32_C( 2112092702), INT32_C( -291680665),
                            INT32_C( 2112788110), INT32_C( 1144876369), INT32_C(-1229665005), INT32_C( 1030181563),
                            INT32_C( -291680665), INT32_C(-2082924696), INT32_C(-1418185146), INT32_C( -572206162)) },
    { simde_mm512_set_epi32(INT32_C( -736462739), INT32_C( 1787530508), INT32_C( 1887757958), INT32_C(-2099529631),
                            INT32_C(  262676022), INT32_C(   53886530), INT32_C( 1760597059), INT32_C( 1505905484),
                            INT32_C(  774167251), INT32_C(  967143468), INT32_C(  868941550), INT32_C(-1213290419),
                            INT32_C( 1972608228), INT32_C(   11142680), INT32_C(-1446276724), INT32_C(-1200659658)),
      simde_mm512_set_epi32(INT32_C(-1351086746), INT32_C(-1617825510), INT32_C(  -53781400), INT32_C( -324253949),
                            INT32_C(  277157108), INT32_C(-1362182408), INT32_C( -600988389), INT32_C(-1661173616),
                            INT32_C(  988661733), INT32_C(-1651241157), INT32_C(  751941929), INT32_C(  -37019801),
                            INT32_C(  498171562), INT32_C( 2017003975), INT32_C(-1441476496), INT32_C(-1365008121)),
      simde_mm512_set_epi32(INT32_C(  -53781400), INT32_C( -324253949), INT32_C(-1651241157), INT32_C(-1441476496),
                            INT32_C(-1651241157), INT32_C( 2017003975), INT32_C(  498171562), INT32_C( -324253949),
                            INT32_C(  498171562), INT32_C( -324253949), INT32_C(-1617825510), INT32_C(  -53781400),
                            INT32_C(  -37019801), INT32_C(-1661173616), INT32_C( -324253949), INT32_C(-1651241157)) },
    { simde_mm512_set_epi32(INT32_C(-2111484726), INT32_C(-1666865657), INT32_C(  905297213), INT32_C(  873020550),
                            INT32_C(-1639789891), INT32_C(  587061870), INT32_C(-2122729525), INT32_C( 1912650916),
                            INT32_C(  -12276084), INT32_C(-1060302964), INT32_C(  650767651), INT32_C( -997283137),
                            INT32_C( 2144598253), INT32_C(  298450302), INT32_C( 1083198112), INT32_C( -506043419)),
      simde_mm512_set_epi32(INT32_C( -134982351), INT32_C(-1321868808), INT32_C( -899996596), INT32_C(-1289649119),
                            INT32_C( -206201920), INT32_C( 1680053368), INT32_C(-1305508907), INT32_C(-2067500681),
                            INT32_C(-1529397706), INT32_C( 1803067419), INT32_C( 1059939268), INT32_C(  399509097),
                            INT32_C( -338549599), INT32_C(  -31125095), INT32_C(-1633544688), INT32_C(-1398964227)),
      simde_mm512_set_epi32(INT32_C( 1680053368), INT32_C(-1529397706), INT32_C( -899996596), INT32_C( 1803067419),
                            INT32_C( -899996596), INT32_C(-1321868808), INT32_C( -206201920), INT32_C(  399509097),
                            INT32_C(-1289649119), INT32_C(-1289649119), INT32_C( -338549599), INT32_C( -134982351),
                            INT32_C( -899996596), INT32_C(-1321868808), INT32_C(-1398964227), INT32_C( 1059939268)) },
    { simde_mm512_set_epi32(INT32_C(-1660298113), INT32_C(   39258193), INT32_C( 1764960191), INT32_C( 1032976421),
                            INT32_C(-1057643771), INT32_C( 2071456034), INT32_C(-1085712390), INT32_C( 1506090338),
                            INT32_C(  367006319), INT32_C(-1863539807), INT32_C(-1111523249), INT32_C( 2019983201),
                            INT32_C(  566503151), INT32_C(  503973368), INT32_C(  315043487), INT32_C(  230467816)),
      simde_mm512_set_epi32(INT32_C(  506925802), INT32_C(  939863413), INT32_C(  -95691606), INT32_C(  -63021650),
                            INT32_C( 1460121332), INT32_C(-1770546120), INT32_C(  691111167), INT32_C( 1916845809),
                            INT32_C( -722416713), INT32_C( 1952309936), INT32_C( -635326036), INT32_C(-2071561697),
                            INT32_C(-1349311592), INT32_C(-1434371918), INT32_C( -908787181), INT32_C( 1027111311)),
      simde_mm512_set_epi32(INT32_C(  506925802), INT32_C( -908787181), INT32_C(  506925802), INT32_C( -635326036),
                            INT32_C( -635326036), INT32_C(-1434371918), INT32_C(-1770546120), INT32_C(-1434371918),
                            INT32_C(  506925802), INT32_C( -908787181), INT32_C(  506925802), INT32_C( -908787181),
                            INT32_C(  506925802), INT32_C( 1916845809), INT32_C(  506925802), INT32_C( 1916845809)) },
    { simde_mm512_set_epi32(INT32_C( -476274551), INT32_C(-1268946349), INT32_C( 1871428230), INT32_C( 1084413756),
                            INT32_C( 1221272409), INT32_C( 1604619894), INT32_C(  245162423), INT32_C( -879398063),
                            INT32_C(-1252847595), INT32_C(-1083417294), INT32_C(  -85733631), INT32_C( -568206760),
                            INT32_C( -433087356), INT32_C(  591211590), INT32_C(  216351398), INT32_C(  907563034)),
      simde_mm512_set_epi32(INT32_C(  553126451), INT32_C( 1865131028), INT32_C( -563146647), INT32_C( 1055479165),
                            INT32_C(-2116199302), INT32_C(  548546839), INT32_C(-1021995369), INT32_C(-1397392070),
                            INT32_C( 1911717085), INT32_C(-1893150233), INT32_C(-1174808283), INT32_C( 1158232544),
                            INT32_C( -280806326), INT32_C(  520223268), INT32_C(  603498036), INT32_C(  115278412)),
      simde_mm512_set_epi32(INT32_C(-1021995369), INT32_C( -280806326), INT32_C(-1893150233), INT32_C( 1055479165),
                            INT32_C(-1021995369), INT32_C(-1893150233), INT32_C( 1911717085), INT32_C(  603498036),
                            INT32_C(-1174808283), INT32_C(  520223268), INT32_C(  603498036), INT32_C(-1397392070),
                            INT32_C( 1158232544), INT32_C(-1893150233), INT32_C(-1893150233), INT32_C(  548546839)) },
    { simde_mm512_set_epi32(INT32_C( -195854029), INT32_C( 1958024187), INT32_C( 1003184214), INT32_C( 1306010047),
                            INT32_C(-1204461456), INT32_C(-1689382831), INT32_C(-1474151310), INT32_C( 1613100007),
                            INT32_C( 1060086708), INT32_C(-1444530803), INT32_C( 1862849170), INT32_C( -928808218),
                            INT32_C( -146523132), INT32_C(-1235988391), INT32_C( -964779679), INT32_C(   57349444)),
      simde_mm512_set_epi32(INT32_C(-2134067081), INT32_C( -882392805), INT32_C(  185789257), INT32_C(-2111603035),
                            INT32_C(  407162836), INT32_C(-1236510605), INT32_C(-1567423785), INT32_C(  780522762),
                            INT32_C(  -23120724), INT32_C(   92199108), INT32_C(   24805933), INT32_C( 1301060633),
                            INT32_C(-1139480237), INT32_C(  217822558), INT32_C(-1429367443), INT32_C(  465891853)),
      simde_mm512_set_epi32(INT32_C(-1139480237), INT32_C(  407162836), INT32_C(   92199108), INT32_C(-2134067081),
                            INT32_C(  465891853), INT32_C(-1429367443), INT32_C(  217822558), INT32_C(  -23120724),
                            INT32_C( 1301060633), INT32_C(  185789257), INT32_C(  217822558), INT32_C(   92199108),
                            INT32_C( 1301060633), INT32_C(-1567423785), INT32_C(-1429367443), INT32_C( 1301060633)) },
    { simde_mm512_set_epi32(INT32_C(  158027570), INT32_C(-1346235067), INT32_C( 1682432767), INT32_C( 1810962335),
                            INT32_C( 1067516501), INT32_C(-1082135268), INT32_C(  -56869560), INT32_C(-1195320775),
                            INT32_C( -393383799), INT32_C( -554410804), INT32_C( 1644924567), INT32_C(-1134386712),
                            INT32_C(-1030153866), INT32_C(  436830495), INT32_C(-1226346340), INT32_C( -700345341)),
      simde_mm512_set_epi32(INT32_C( -756862268), INT32_C( 1500443430), INT32_C(  463718589), INT32_C(  262081082),
                            INT32_C(  990406393), INT32_C(  114071142), INT32_C(-1625480036), INT32_C( -478582396),
                            INT32_C( -548991920), INT32_C( 1883825214), INT32_C(  -16488776), INT32_C( -956015081),
                            INT32_C(-1165588144), INT32_C( -540410051), INT32_C(  285110286), INT32_C( 1179668936)),
      simde_mm512_set_epi32(INT32_C( -540410051), INT32_C(  -16488776), INT32_C( -756862268), INT32_C( -756862268),
                            INT32_C(  -16488776), INT32_C(  262081082), INT32_C( -478582396), INT32_C(-1625480036),
                            INT32_C(-1625480036), INT32_C(  262081082), INT32_C( -548991920), INT32_C( -478582396),
                            INT32_C( 1883825214), INT32_C( -756862268), INT32_C(  262081082), INT32_C(-1165588144)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_permutexvar_epi32(test_vec[i].idx, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_permutexvar_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i idx;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126), INT32_C(-1306064352),
                            INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562), INT32_C( 1443901717),
                            INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932), INT32_C(-1302383354),
                            INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201), INT32_C( 1856459607)),
      UINT16_C(27455),
      simde_mm512_set_epi32(INT32_C(-1110068455), INT32_C( -207240031), INT32_C(-1649179267), INT32_C( 2054398444),
                            INT32_C( -483586503), INT32_C(-1481960002), INT32_C(  861125508), INT32_C( -330381203),
                            INT32_C(-1999224530), INT32_C( 1042470181), INT32_C( 1827473477), INT32_C(  298546792),
                            INT32_C(-1630396605), INT32_C( 1545554432), INT32_C(  344023940), INT32_C(-1871515754)),
      simde_mm512_set_epi32(INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373), INT32_C( -695949043),
                            INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093), INT32_C(-2045280751),
                            INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336), INT32_C(  564965997),
                            INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685), INT32_C( 1430356381)),
      simde_mm512_set_epi32(INT32_C(-1026363374), INT32_C( 1134735685), INT32_C( 1974152373), INT32_C(-1306064352),
                            INT32_C(-1166320093), INT32_C(  923442479), INT32_C(  564965997), INT32_C( 1974152373),
                            INT32_C( 1848749100), INT32_C( 1777333881), INT32_C(  282198336), INT32_C(-2045280751),
                            INT32_C(  169645898), INT32_C( 1430356381), INT32_C(  564965997), INT32_C(  223952317)) },
    { simde_mm512_set_epi32(INT32_C(-1423023772), INT32_C(-1185448755), INT32_C( 1549802795), INT32_C(  159583350),
                            INT32_C(  548883180), INT32_C( -605945909), INT32_C(-2063050181), INT32_C( 1095467003),
                            INT32_C(-2083755741), INT32_C( 2066979701), INT32_C( 1094609712), INT32_C( 1345059025),
                            INT32_C( -340318359), INT32_C( 1519671047), INT32_C(-1017461983), INT32_C(  353198331)),
      UINT16_C( 8253),
      simde_mm512_set_epi32(INT32_C( -888441293), INT32_C( -707551350), INT32_C(  513515868), INT32_C(-1825967755),
                            INT32_C(  822222164), INT32_C(-1689559027), INT32_C(  533478787), INT32_C(  907615417),
                            INT32_C( -199229058), INT32_C(  -91537812), INT32_C( 1375258232), INT32_C(  139748399),
                            INT32_C( 1688468565), INT32_C(  736544549), INT32_C(-1282057552), INT32_C(  795925067)),
      simde_mm512_set_epi32(INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417),
                            INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662),
                            INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205), INT32_C( -839037220),
                            INT32_C(  499633910), INT32_C( -260167255), INT32_C(  884163960), INT32_C( -329275629)),
      simde_mm512_set_epi32(INT32_C(-1423023772), INT32_C(-1185448755), INT32_C( 1469355417), INT32_C(  159583350),
                            INT32_C(  548883180), INT32_C( -605945909), INT32_C(-2063050181), INT32_C( 1095467003),
                            INT32_C(-2083755741), INT32_C( 2066979701), INT32_C( 1258747662), INT32_C( 1701079465),
                            INT32_C( -622852205), INT32_C( -622852205), INT32_C(-1017461983), INT32_C(-1849349632)) },
    { simde_mm512_set_epi32(INT32_C( -174985661), INT32_C(-1762469023), INT32_C( 1239606494), INT32_C(  -22119232),
                            INT32_C( 1216907749), INT32_C(  654527510), INT32_C(-2043358500), INT32_C(  459072440),
                            INT32_C( -430427651), INT32_C( -272088075), INT32_C(  386072301), INT32_C(-1628984154),
                            INT32_C(   87817524), INT32_C( 1219490517), INT32_C(-1569831145), INT32_C(  338985942)),
      UINT16_C(47186),
      simde_mm512_set_epi32(INT32_C(  730787370), INT32_C(-2034110695), INT32_C(-1088138491), INT32_C( -353174912),
                            INT32_C( -362301616), INT32_C(  617951303), INT32_C(  817116152), INT32_C(-1034835761),
                            INT32_C( -102069057), INT32_C( 1774242298), INT32_C( 1089620040), INT32_C(-1101477862),
                            INT32_C( 2001101785), INT32_C(-1759250988), INT32_C( -606254738), INT32_C( 1526367108)),
      simde_mm512_set_epi32(INT32_C(  204417556), INT32_C(-1329665093), INT32_C(-2039025377), INT32_C( 1639231015),
                            INT32_C( 1541217841), INT32_C( 1692413538), INT32_C(  738521275), INT32_C(  159429100),
                            INT32_C(  451955897), INT32_C(  181201098), INT32_C(  450627934), INT32_C( 2082954477),
                            INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946), INT32_C(-1087388220)),
      simde_mm512_set_epi32(INT32_C( 1692413538), INT32_C(-1762469023), INT32_C(  450627934), INT32_C(-1087388220),
                            INT32_C(-1087388220), INT32_C(  654527510), INT32_C(-2043358500), INT32_C(  459072440),
                            INT32_C( -430427651), INT32_C( 1692413538), INT32_C(  386072301), INT32_C( 1692413538),
                            INT32_C(   87817524), INT32_C( 1219490517), INT32_C(-1329665093), INT32_C(  338985942)) },
    { simde_mm512_set_epi32(INT32_C( 1928049651), INT32_C(  765730488), INT32_C(  -85899231), INT32_C( 1435935141),
                            INT32_C(-2098236580), INT32_C(-1991433794), INT32_C( 1298943776), INT32_C(  277470244),
                            INT32_C(-1834748849), INT32_C(  596054477), INT32_C( 1827419510), INT32_C(-1010527612),
                            INT32_C(-1687118128), INT32_C(  107945377), INT32_C( 1174128677), INT32_C(-1544325740)),
      UINT16_C(47807),
      simde_mm512_set_epi32(INT32_C( 1463729035), INT32_C( 2031968571), INT32_C(  333434400), INT32_C( -637142874),
                            INT32_C( -520435756), INT32_C( -148623413), INT32_C( -692754616), INT32_C(-1908406411),
                            INT32_C( 1391053429), INT32_C( 1767908668), INT32_C( 1117151413), INT32_C( 1466854108),
                            INT32_C( -852914371), INT32_C( -773785464), INT32_C(-2142007253), INT32_C(  466013192)),
      simde_mm512_set_epi32(INT32_C( -811849174), INT32_C(-1510825074), INT32_C( 1897985966), INT32_C( 1445172644),
                            INT32_C( -193622280), INT32_C( 2097959091), INT32_C( -652080500), INT32_C( 1943026961),
                            INT32_C(  763848022), INT32_C(-2124387583), INT32_C(-1102663841), INT32_C(  712044568),
                            INT32_C( 1641785760), INT32_C( 1696516135), INT32_C(-1123374630), INT32_C( -181070601)),
      simde_mm512_set_epi32(INT32_C( -193622280), INT32_C(  765730488), INT32_C( -181070601), INT32_C(-2124387583),
                            INT32_C(  712044568), INT32_C(-1991433794), INT32_C( 1943026961), INT32_C(  277470244),
                            INT32_C(-1102663841), INT32_C(  596054477), INT32_C(-1102663841), INT32_C( 1445172644),
                            INT32_C( 1897985966), INT32_C( 1943026961), INT32_C( -193622280), INT32_C( 1943026961)) },
    { simde_mm512_set_epi32(INT32_C(  729621709), INT32_C(-1241407128), INT32_C(  696721321), INT32_C( -603523965),
                            INT32_C( 1730687689), INT32_C(  290786615), INT32_C(-1827031380), INT32_C( 1429317129),
                            INT32_C(-1800615955), INT32_C( -728999228), INT32_C( -788606428), INT32_C( -539592973),
                            INT32_C(-1402526875), INT32_C(   -8263463), INT32_C(  478788156), INT32_C(  842200487)),
      UINT16_C(43569),
      simde_mm512_set_epi32(INT32_C(-1668086905), INT32_C( -770469750), INT32_C( 1013231130), INT32_C(  543156562),
                            INT32_C( -399740514), INT32_C(  509655415), INT32_C( -160537509), INT32_C( -549528402),
                            INT32_C( -323547130), INT32_C(-1395624565), INT32_C(-1905505546), INT32_C(-1268587914),
                            INT32_C( 1939823644), INT32_C(-1112752789), INT32_C( 2052878307), INT32_C( -856056848)),
      simde_mm512_set_epi32(INT32_C( 1969107101), INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053),
                            INT32_C( 1035482990), INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639),
                            INT32_C( -638430290), INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613),
                            INT32_C(  165266600), INT32_C( -798384264), INT32_C( 1607584815), INT32_C(-1324336584)),
      simde_mm512_set_epi32(INT32_C( -638430290), INT32_C(-1241407128), INT32_C( 1183910939), INT32_C( -603523965),
                            INT32_C(-2063427243), INT32_C(  290786615), INT32_C( 1035482990), INT32_C( 1429317129),
                            INT32_C(-1800615955), INT32_C( -728999228), INT32_C(-2007622482), INT32_C(-2007622482),
                            INT32_C(-1402526875), INT32_C(   -8263463), INT32_C(  478788156), INT32_C(-1324336584)) },
    { simde_mm512_set_epi32(INT32_C(-1349190316), INT32_C(-1403674818), INT32_C( -521443925), INT32_C(-1464291783),
                            INT32_C(-1686112999), INT32_C(-1290233716), INT32_C( -364563113), INT32_C( 1520783126),
                            INT32_C( -207159885), INT32_C( -104006691), INT32_C(  362759403), INT32_C(-1562242573),
                            INT32_C( -397133039), INT32_C(  568974515), INT32_C(-1726442446), INT32_C(-2134949944)),
      UINT16_C(54613),
      simde_mm512_set_epi32(INT32_C(-1929379353), INT32_C( -560036292), INT32_C(-1693642327), INT32_C(-1383827159),
                            INT32_C( 1804875719), INT32_C( 1179452315), INT32_C(-1509656190), INT32_C(-1409992701),
                            INT32_C(-1830359468), INT32_C(  635753031), INT32_C(  310246197), INT32_C(-1783943034),
                            INT32_C(-1307643183), INT32_C( -144888334), INT32_C(  621611179), INT32_C(  743650285)),
      simde_mm512_set_epi32(INT32_C(-2094713086), INT32_C(  197529411), INT32_C( 1055036471), INT32_C(  351897115),
                            INT32_C( 1594003471), INT32_C(-1709813294), INT32_C( -133653364), INT32_C(  -51462036),
                            INT32_C(   46796230), INT32_C(  989301899), INT32_C( -691937914), INT32_C( 1667629581),
                            INT32_C( -496700661), INT32_C(-1318801755), INT32_C( 1076515270), INT32_C(-1757573505)),
      simde_mm512_set_epi32(INT32_C(   46796230), INT32_C(  351897115), INT32_C( -521443925), INT32_C( -133653364),
                            INT32_C(-1686112999), INT32_C( 1594003471), INT32_C( -364563113), INT32_C( -496700661),
                            INT32_C( -207159885), INT32_C(   46796230), INT32_C(  362759403), INT32_C(  989301899),
                            INT32_C( -397133039), INT32_C(-1318801755), INT32_C(-1726442446), INT32_C( 1055036471)) },
    { simde_mm512_set_epi32(INT32_C( -662725541), INT32_C(  790228415), INT32_C(  -26753919), INT32_C( -495897274),
                            INT32_C( 1526994051), INT32_C( 1569343894), INT32_C(-1059990980), INT32_C( -490626870),
                            INT32_C( 1463745126), INT32_C( -957352131), INT32_C( 1122208393), INT32_C(-1814919780),
                            INT32_C(-1891682702), INT32_C( -176064246), INT32_C(-1293286075), INT32_C(-1398303881)),
      UINT16_C(12582),
      simde_mm512_set_epi32(INT32_C(-1664789378), INT32_C( -204514420), INT32_C( 1112369408), INT32_C( 2113109396),
                            INT32_C(-1679339682), INT32_C( 2128430529), INT32_C(-1262713143), INT32_C( 1026756660),
                            INT32_C(-1268083621), INT32_C(  337660693), INT32_C( 1524090799), INT32_C( -275653210),
                            INT32_C(-1422519849), INT32_C( -495051500), INT32_C( 1851182812), INT32_C(    5027269)),
      simde_mm512_set_epi32(INT32_C( -501257427), INT32_C(-1329431510), INT32_C( 1005777948), INT32_C(  616430734),
                            INT32_C( 1581162255), INT32_C( 1497456456), INT32_C(-1170808415), INT32_C(-1014503666),
                            INT32_C(-1157750165), INT32_C( 1691363299), INT32_C( 1100655145), INT32_C(  673265711),
                            INT32_C( 1544659928), INT32_C(-1956803094), INT32_C( 1970109422), INT32_C(-1197844366)),
      simde_mm512_set_epi32(INT32_C( -662725541), INT32_C(  790228415), INT32_C(-1197844366), INT32_C(  673265711),
                            INT32_C( 1526994051), INT32_C( 1569343894), INT32_C(-1059990980), INT32_C(  673265711),
                            INT32_C( 1463745126), INT32_C( -957352131), INT32_C( -501257427), INT32_C(-1814919780),
                            INT32_C(-1891682702), INT32_C(  673265711), INT32_C(  616430734), INT32_C(-1398303881)) },
    { simde_mm512_set_epi32(INT32_C(-1875196295), INT32_C( -129416454), INT32_C(  246939492), INT32_C(-1135915662),
                            INT32_C( -539014135), INT32_C( 1554320066), INT32_C( 1611314079), INT32_C(-1013292897),
                            INT32_C( 1135188428), INT32_C(-1903831246), INT32_C( 1207366326), INT32_C( -366505666),
                            INT32_C( 1379479886), INT32_C( 1577255779), INT32_C( -488475560), INT32_C(  143370041)),
      UINT16_C(29031),
      simde_mm512_set_epi32(INT32_C(   -7690721), INT32_C( -632623581), INT32_C(  612963145), INT32_C( 1824881051),
                            INT32_C(  582494706), INT32_C(-1899955415), INT32_C(  618457733), INT32_C( 1216635147),
                            INT32_C( 1404062051), INT32_C( 1905825928), INT32_C(-1635796069), INT32_C(  528096299),
                            INT32_C(  259240399), INT32_C(  271372102), INT32_C( 1305969598), INT32_C(  974818283)),
      simde_mm512_set_epi32(INT32_C( -675362282), INT32_C(-1218762696), INT32_C(-1400182216), INT32_C(-2088680370),
                            INT32_C(-1895497877), INT32_C( 1563893931), INT32_C( 1105770515), INT32_C(-1745770541),
                            INT32_C(-1255255240), INT32_C( 1238532704), INT32_C(  995946229), INT32_C(  119517601),
                            INT32_C( 1389614040), INT32_C(-2032996348), INT32_C( 1996749952), INT32_C(  450477794)),
      simde_mm512_set_epi32(INT32_C(-1875196295), INT32_C( 1389614040), INT32_C( 1105770515), INT32_C(-1895497877),
                            INT32_C( -539014135), INT32_C( 1554320066), INT32_C( 1611314079), INT32_C(-1895497877),
                            INT32_C( 1135188428), INT32_C(-1745770541), INT32_C(-1895497877), INT32_C( -366505666),
                            INT32_C( 1379479886), INT32_C( 1238532704), INT32_C(-1218762696), INT32_C(-1895497877)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_permutexvar_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_permutexvar_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i idx;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { UINT16_C(21335),
      simde_mm512_set_epi32(INT32_C(  951544639), INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126),
                            INT32_C(-1306064352), INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562),
                            INT32_C( 1443901717), INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932),
                            INT32_C(-1302383354), INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201)),
      simde_mm512_set_epi32(INT32_C(-1110068455), INT32_C( -207240031), INT32_C(-1649179267), INT32_C( 2054398444),
                            INT32_C( -483586503), INT32_C(-1481960002), INT32_C(  861125508), INT32_C( -330381203),
                            INT32_C(-1999224530), INT32_C( 1042470181), INT32_C( 1827473477), INT32_C(  298546792),
                            INT32_C(-1630396605), INT32_C( 1545554432), INT32_C(  344023940), INT32_C(-1871515754)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1545554432), INT32_C(          0), INT32_C( -207240031),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1110068455), INT32_C(-1481960002),
                            INT32_C(          0), INT32_C( 2054398444), INT32_C(          0), INT32_C(  298546792),
                            INT32_C(          0), INT32_C( 1042470181), INT32_C(-1110068455), INT32_C(-1999224530)) },
    { UINT16_C(33181),
      simde_mm512_set_epi32(INT32_C(  353198331), INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373),
                            INT32_C( -695949043), INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093),
                            INT32_C(-2045280751), INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336),
                            INT32_C(  564965997), INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685)),
      simde_mm512_set_epi32(INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755), INT32_C( 1549802795),
                            INT32_C(  159583350), INT32_C(  548883180), INT32_C( -605945909), INT32_C(-2063050181),
                            INT32_C( 1095467003), INT32_C(-2083755741), INT32_C( 2066979701), INT32_C( 1094609712),
                            INT32_C( 1345059025), INT32_C( -340318359), INT32_C( 1519671047), INT32_C(-1017461983)),
      simde_mm512_set_epi32(INT32_C(  159583350), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1345059025),
                            INT32_C( 1519671047), INT32_C(          0), INT32_C(          0), INT32_C(-1017461983),
                            INT32_C(-1185448755), INT32_C(  548883180), INT32_C(          0), INT32_C( 2066979701)) },
    { UINT16_C(55883),
      simde_mm512_set_epi32(INT32_C( -329275629), INT32_C( -888441293), INT32_C( -707551350), INT32_C(  513515868),
                            INT32_C(-1825967755), INT32_C(  822222164), INT32_C(-1689559027), INT32_C(  533478787),
                            INT32_C(  907615417), INT32_C( -199229058), INT32_C(  -91537812), INT32_C( 1375258232),
                            INT32_C(  139748399), INT32_C( 1688468565), INT32_C(  736544549), INT32_C(-1282057552)),
      simde_mm512_set_epi32(INT32_C(  338985942), INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315),
                            INT32_C( 1469355417), INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370),
                            INT32_C( 1258747662), INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205),
                            INT32_C( -839037220), INT32_C(  499633910), INT32_C( -260167255), INT32_C(  884163960)),
      simde_mm512_set_epi32(INT32_C( -839037220), INT32_C( -839037220), INT32_C(          0), INT32_C(  503748315),
                            INT32_C( -532007659), INT32_C(          0), INT32_C( -195770682), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1701079465), INT32_C(          0), INT32_C(          0),
                            INT32_C(  338985942), INT32_C(          0), INT32_C( -532007659), INT32_C(  884163960)) },
    { UINT16_C(18199),
      simde_mm512_set_epi32(INT32_C( 1526367108), INT32_C(  722122834), INT32_C( -174985661), INT32_C(-1762469023),
                            INT32_C( 1239606494), INT32_C(  -22119232), INT32_C( 1216907749), INT32_C(  654527510),
                            INT32_C(-2043358500), INT32_C(  459072440), INT32_C( -430427651), INT32_C( -272088075),
                            INT32_C(  386072301), INT32_C(-1628984154), INT32_C(   87817524), INT32_C( 1219490517)),
      simde_mm512_set_epi32(INT32_C(-1087388220), INT32_C(  730787370), INT32_C(-2034110695), INT32_C(-1088138491),
                            INT32_C( -353174912), INT32_C( -362301616), INT32_C(  617951303), INT32_C(  817116152),
                            INT32_C(-1034835761), INT32_C( -102069057), INT32_C( 1774242298), INT32_C( 1089620040),
                            INT32_C(-1101477862), INT32_C( 2001101785), INT32_C(-1759250988), INT32_C( -606254738)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 2001101785), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( -606254738), INT32_C( 1774242298), INT32_C( -102069057),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1774242298),
                            INT32_C(          0), INT32_C( -102069057), INT32_C( 1089620040), INT32_C( 1774242298)) },
    { UINT16_C(26926),
      simde_mm512_set_epi32(INT32_C( 1174128677), INT32_C(-1544325740), INT32_C(  204417556), INT32_C(-1329665093),
                            INT32_C(-2039025377), INT32_C( 1639231015), INT32_C( 1541217841), INT32_C( 1692413538),
                            INT32_C(  738521275), INT32_C(  159429100), INT32_C(  451955897), INT32_C(  181201098),
                            INT32_C(  450627934), INT32_C( 2082954477), INT32_C( 1254960767), INT32_C( 1995459397)),
      simde_mm512_set_epi32(INT32_C(  466013192), INT32_C( 1313258175), INT32_C( 1928049651), INT32_C(  765730488),
                            INT32_C(  -85899231), INT32_C( 1435935141), INT32_C(-2098236580), INT32_C(-1991433794),
                            INT32_C( 1298943776), INT32_C(  277470244), INT32_C(-1834748849), INT32_C(  596054477),
                            INT32_C( 1827419510), INT32_C(-1010527612), INT32_C(-1687118128), INT32_C(  107945377)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  596054477), INT32_C(  596054477), INT32_C(          0),
                            INT32_C(  466013192), INT32_C(          0), INT32_C(          0), INT32_C(-1010527612),
                            INT32_C(          0), INT32_C(          0), INT32_C(-2098236580), INT32_C(          0),
                            INT32_C( 1313258175), INT32_C( 1928049651), INT32_C(  466013192), INT32_C(          0)) },
    { UINT16_C(36907),
      simde_mm512_set_epi32(INT32_C(-1123374630), INT32_C( -181070601), INT32_C( 1463729035), INT32_C( 2031968571),
                            INT32_C(  333434400), INT32_C( -637142874), INT32_C( -520435756), INT32_C( -148623413),
                            INT32_C( -692754616), INT32_C(-1908406411), INT32_C( 1391053429), INT32_C( 1767908668),
                            INT32_C( 1117151413), INT32_C( 1466854108), INT32_C( -852914371), INT32_C( -773785464)),
      simde_mm512_set_epi32(INT32_C(  478788156), INT32_C(  842200487), INT32_C( -811849174), INT32_C(-1510825074),
                            INT32_C( 1897985966), INT32_C( 1445172644), INT32_C( -193622280), INT32_C( 2097959091),
                            INT32_C( -652080500), INT32_C( 1943026961), INT32_C(  763848022), INT32_C(-2124387583),
                            INT32_C(-1102663841), INT32_C(  712044568), INT32_C( 1641785760), INT32_C( 1696516135)),
      simde_mm512_set_epi32(INT32_C( 1445172644), INT32_C(          0), INT32_C(          0), INT32_C( 1897985966),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(  763848022), INT32_C(          0),
                            INT32_C(  763848022), INT32_C(          0), INT32_C( -811849174), INT32_C( 2097959091)) },
    { UINT16_C(59609),
      simde_mm512_set_epi32(INT32_C( 2052878307), INT32_C( -856056848), INT32_C(-1218860495), INT32_C(  729621709),
                            INT32_C(-1241407128), INT32_C(  696721321), INT32_C( -603523965), INT32_C( 1730687689),
                            INT32_C(  290786615), INT32_C(-1827031380), INT32_C( 1429317129), INT32_C(-1800615955),
                            INT32_C( -728999228), INT32_C( -788606428), INT32_C( -539592973), INT32_C(-1402526875)),
      simde_mm512_set_epi32(INT32_C( 1607584815), INT32_C(-1324336584), INT32_C(-1668086905), INT32_C( -770469750),
                            INT32_C( 1013231130), INT32_C(  543156562), INT32_C( -399740514), INT32_C(  509655415),
                            INT32_C( -160537509), INT32_C( -549528402), INT32_C( -323547130), INT32_C(-1395624565),
                            INT32_C(-1905505546), INT32_C(-1268587914), INT32_C( 1939823644), INT32_C(-1112752789)),
      simde_mm512_set_epi32(INT32_C(-1905505546), INT32_C(-1112752789), INT32_C( 1939823644), INT32_C(          0),
                            INT32_C(  509655415), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -160537509), INT32_C( -770469750), INT32_C(          0), INT32_C(-1668086905),
                            INT32_C(-1395624565), INT32_C(          0), INT32_C(          0), INT32_C( -323547130)) },
    { UINT16_C(40824),
      simde_mm512_set_epi32(INT32_C(  568974515), INT32_C(-1726442446), INT32_C(-2134949944), INT32_C( 1969107101),
                            INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053), INT32_C( 1035482990),
                            INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639), INT32_C( -638430290),
                            INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613), INT32_C(  165266600)),
      simde_mm512_set_epi32(INT32_C(  621611179), INT32_C(  743650285), INT32_C( 1845744981), INT32_C(-1349190316),
                            INT32_C(-1403674818), INT32_C( -521443925), INT32_C(-1464291783), INT32_C(-1686112999),
                            INT32_C(-1290233716), INT32_C( -364563113), INT32_C( 1520783126), INT32_C( -207159885),
                            INT32_C( -104006691), INT32_C(  362759403), INT32_C(-1562242573), INT32_C( -397133039)),
      simde_mm512_set_epi32(INT32_C( -104006691), INT32_C(          0), INT32_C(          0), INT32_C( 1845744981),
                            INT32_C( 1520783126), INT32_C(-1349190316), INT32_C( -104006691), INT32_C(  743650285),
                            INT32_C(          0), INT32_C(  743650285), INT32_C(-1464291783), INT32_C(  743650285),
                            INT32_C(  743650285), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_permutexvar_epi32(test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_permutexvar_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i idx;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-2671339936797273634), INT64_C(-6569724575104779065),
                            INT64_C( 6280671509806293744), INT64_C(-6564012982845614940),
                            INT64_C(-8218226210083292891), INT64_C(-1970878168494992951),
                            INT64_C(  623983056867500923), INT64_C( 8381435109868166325)),
      simde_mm512_set_epi64(INT64_C(-2238152008698912054), INT64_C(-6011307368237149167),
                            INT64_C( 7021013141387677756), INT64_C(  209431633592419129),
                            INT64_C(-2042251418947820180), INT64_C(-1637501592002869374),
                            INT64_C(-7968886780493171295), INT64_C( 7201832131237889915)),
      simde_mm512_set_epi64(INT64_C(-6011307368237149167), INT64_C(-2238152008698912054),
                            INT64_C( 7201832131237889915), INT64_C(  209431633592419129),
                            INT64_C( 7021013141387677756), INT64_C(-7968886780493171295),
                            INT64_C(-2042251418947820180), INT64_C( 7021013141387677756)) },
    { simde_mm512_set_epi64(INT64_C( 9078632813866954216), INT64_C( 5306066193622774721),
                            INT64_C( 6328033075457178183), INT64_C(-7841620825407880030),
                            INT64_C( 8494413761555835343), INT64_C(-6629030689949253425),
                            INT64_C(-3415199944519615656), INT64_C( 9203934858949759250)),
      simde_mm512_set_epi64(INT64_C( 2479803165234466245), INT64_C( 2661396061418991136),
                            INT64_C(-5715036345641082343), INT64_C( 1298703295811073042),
                            INT64_C( 5852540304039009511), INT64_C( 6078752793077415028),
                            INT64_C( 4402609795769289287), INT64_C( 6115701178487842322)),
      simde_mm512_set_epi64(INT64_C( 6115701178487842322), INT64_C( 4402609795769289287),
                            INT64_C( 2479803165234466245), INT64_C( 6078752793077415028),
                            INT64_C( 2479803165234466245), INT64_C( 2479803165234466245),
                            INT64_C( 6115701178487842322), INT64_C( 6078752793077415028)) },
    { simde_mm512_set_epi64(INT64_C(-4996537380140624007), INT64_C( 3942559966214732809),
                            INT64_C(-2671134702774502774), INT64_C( 8456382047897336120),
                            INT64_C( 6407530222969271406), INT64_C(  407141370872746761),
                            INT64_C( 8529772400902424249), INT64_C(-4246571771485464983)),
      simde_mm512_set_epi64(INT64_C(  834150414269389391), INT64_C( 2027953688477105836),
                            INT64_C( 4657551970593349995), INT64_C(-7093404930502337621),
                            INT64_C(-1111425946814561024), INT64_C(-6887525210431388893),
                            INT64_C( 7494759347392082910), INT64_C(-5042062261697149458)),
      simde_mm512_set_epi64(INT64_C( 7494759347392082910), INT64_C( 7494759347392082910),
                            INT64_C(-6887525210431388893), INT64_C(-5042062261697149458),
                            INT64_C( 2027953688477105836), INT64_C( 7494759347392082910),
                            INT64_C( 7494759347392082910), INT64_C( 7494759347392082910)) },
    { simde_mm512_set_epi64(INT64_C( 2040395228897941830), INT64_C( 2765121423290447296),
                            INT64_C( 2050656439718793919), INT64_C(-7162012369641923245),
                            INT64_C( -776125111083479372), INT64_C( 6485544818721995013),
                            INT64_C( 8129692823118117691), INT64_C(-8572576708578902442)),
      simde_mm512_set_epi64(INT64_C( 2289013539283677845), INT64_C(-5799540082455789735),
                            INT64_C( 2163632088234152524), INT64_C(-2186518714684028349),
                            INT64_C(-8831520715491995762), INT64_C( 3869803765755785917),
                            INT64_C( 8013865163596309228), INT64_C(-3584939450023784210)),
      simde_mm512_set_epi64(INT64_C(-5799540082455789735), INT64_C(-3584939450023784210),
                            INT64_C( 2289013539283677845), INT64_C(-8831520715491995762),
                            INT64_C(-2186518714684028349), INT64_C( 2163632088234152524),
                            INT64_C(-8831520715491995762), INT64_C(-5799540082455789735)) },
    { simde_mm512_set_epi64(INT64_C( 3677820960269215734), INT64_C(-6343206756900565591),
                            INT64_C( 8255445898463112459), INT64_C( 4852161483621128051),
                            INT64_C( 8099305670443807898), INT64_C(-8684281278489558074),
                            INT64_C( 3137344644687539915), INT64_C( 5523372352513099931)),
      simde_mm512_set_epi64(INT64_C( 4283186432542966059), INT64_C( 1170657112776090420),
                            INT64_C( 2518002084319668884), INT64_C( 4471327755299130682),
                            INT64_C( 2261821509900268313), INT64_C( 5692030531386538246),
                            INT64_C(-1483628367950291610), INT64_C( 6533622553555897345)),
      simde_mm512_set_epi64(INT64_C( 1170657112776090420), INT64_C(-1483628367950291610),
                            INT64_C( 2261821509900268313), INT64_C( 2261821509900268313),
                            INT64_C( 5692030531386538246), INT64_C( 1170657112776090420),
                            INT64_C( 2261821509900268313), INT64_C( 2261821509900268313)) },
    { simde_mm512_set_epi64(INT64_C( 2347171147608692871), INT64_C(-6783728424977598502),
                            INT64_C(-2041006483186382974), INT64_C( 8642864406765137587),
                            INT64_C(-1636657579614487452), INT64_C( 9207381314159514814),
                            INT64_C(-3687478572965330724), INT64_C(-9006129120063771595)),
      simde_mm512_set_epi64(INT64_C( 4701446694745358904), INT64_C( 5644218643369465634),
                            INT64_C( 3403557732929675228), INT64_C( 5349859821272859600),
                            INT64_C(-1653042609039941611), INT64_C(-4665914487571652764),
                            INT64_C( 3371940136328092430), INT64_C(-2406499600794803976)),
      simde_mm512_set_epi64(INT64_C( 4701446694745358904), INT64_C(-4665914487571652764),
                            INT64_C(-4665914487571652764), INT64_C(-1653042609039941611),
                            INT64_C( 5349859821272859600), INT64_C( 5644218643369465634),
                            INT64_C( 5349859821272859600), INT64_C( 3403557732929675228)) },
    { simde_mm512_set_epi64(INT64_C( 4782376392228385514), INT64_C(-1906708615590323735),
                            INT64_C(-3545169353098873151), INT64_C( 3265944245325513127),
                            INT64_C( 4131290265645096409), INT64_C(-4397904511930284448),
                            INT64_C(-2647251656339754605), INT64_C( 3315710643141776922)),
      simde_mm512_set_epi64(INT64_C(-6136398457404459673), INT64_C( -648409073018341138),
                            INT64_C(  958458472131577038), INT64_C(  368136538694245601),
                            INT64_C( 7267809600451931130), INT64_C( 7002668171940425391),
                            INT64_C(-7238180738987124127), INT64_C(-3577079750371726624)),
      simde_mm512_set_epi64(INT64_C( 7002668171940425391), INT64_C(-7238180738987124127),
                            INT64_C(-7238180738987124127), INT64_C(-6136398457404459673),
                            INT64_C(-7238180738987124127), INT64_C(-3577079750371726624),
                            INT64_C( 7267809600451931130), INT64_C( 7002668171940425391)) },
    { simde_mm512_set_epi64(INT64_C( 7177491025608125879), INT64_C( 2298304526936591870),
                            INT64_C( 4104659984995714948), INT64_C(-3124913163496554810),
                            INT64_C( 7421100574262603376), INT64_C( 5351476444327610551),
                            INT64_C(  110626773490384787), INT64_C( 8483452379448679247)),
      simde_mm512_set_epi64(INT64_C( 7070883828009365305), INT64_C(-8674554469467912700),
                            INT64_C( 4454911305585732940), INT64_C(-2880418777083904328),
                            INT64_C( 6809950466209546729), INT64_C( 2297778791052038555),
                            INT64_C( 3156218119380498044), INT64_C(-2342831745602989292)),
      simde_mm512_set_epi64(INT64_C( 7070883828009365305), INT64_C(-8674554469467912700),
                            INT64_C(-2880418777083904328), INT64_C(-8674554469467912700),
                            INT64_C(-2342831745602989292), INT64_C( 7070883828009365305),
                            INT64_C( 6809950466209546729), INT64_C( 7070883828009365305)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_permutexvar_epi64(test_vec[i].idx, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_permutexvar_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask8 k;
    simde__m512i idx;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-4408197122649025847), INT64_C(  624651997750430240),
                            INT64_C(-3688244718601593553), INT64_C( 4693564151120802069),
                            INT64_C( 7940316924786767481), INT64_C( 6743600876828439814),
                            INT64_C( 8561828216572109007), INT64_C(-8315109086095518889)),
      UINT8_C( 63),
      simde_mm512_set_epi64(INT64_C(-4767707706458520415), INT64_C(-7083171014951853588),
                            INT64_C(-2076988212358998594), INT64_C( 3698505898575972461),
                            INT64_C(-8586603972668500699), INT64_C( 7848938818320954984),
                            INT64_C(-7002500096438875648), INT64_C( 1477571573764517782)),
      simde_mm512_set_epi64(INT64_C( 7350668077567080689), INT64_C( 8478919882954811661),
                            INT64_C(-3394066222784588743), INT64_C(-5009306653852991983),
                            INT64_C(-8749971605870264899), INT64_C( 1212032624670585453),
                            INT64_C(  728623586565902494), INT64_C( 4873652658109514141)),
      simde_mm512_set_epi64(INT64_C(-4408197122649025847), INT64_C(  624651997750430240),
                            INT64_C( 8478919882954811661), INT64_C(-3394066222784588743),
                            INT64_C(-3394066222784588743), INT64_C( 4873652658109514141),
                            INT64_C( 4873652658109514141), INT64_C( 8478919882954811661)) },
    { simde_mm512_set_epi64(INT64_C(-6111840559061041971), INT64_C( 6656352319933975670),
                            INT64_C( 2357435311113502667), INT64_C(-8860733056306413573),
                            INT64_C(-8949662758380266635), INT64_C( 4701312916269037777),
                            INT64_C(-1461656220613716217), INT64_C(-4369965941555109637)),
      UINT8_C( 61),
      simde_mm512_set_epi64(INT64_C(-3815826294263537782), INT64_C( 2205533861506052469),
                            INT64_C( 3531417307031756813), INT64_C( 2291273944182365369),
                            INT64_C( -855682284319457684), INT64_C( 5906689130134529071),
                            INT64_C( 7251917267735594789), INT64_C(-5506395256633894325)),
      simde_mm512_set_epi64(INT64_C( 7306080674171373254), INT64_C( 2163582539809461657),
                            INT64_C(-7942896186346970451), INT64_C(-2775611318017263858),
                            INT64_C( 7897714815450887445), INT64_C(-2675129847260557604),
                            INT64_C( 2145911307457407401), INT64_C( 3797455296467543827)),
      simde_mm512_set_epi64(INT64_C(-6111840559061041971), INT64_C( 6656352319933975670),
                            INT64_C(-7942896186346970451), INT64_C( 2145911307457407401),
                            INT64_C(-2775611318017263858), INT64_C( 7306080674171373254),
                            INT64_C(-1461656220613716217), INT64_C( 7897714815450887445)) },
    { simde_mm512_set_epi64(INT64_C( -751557688731444383), INT64_C( 5324069355912068288),
                            INT64_C( 5226578984858504214), INT64_C(-8776157931044543560),
                            INT64_C(-1848672680316222475), INT64_C( 1658167909352451238),
                            INT64_C(  377173394815185621), INT64_C(-6742373427678247978)),
      UINT8_C( 82),
      simde_mm512_set_epi64(INT64_C( 3138707856740708121), INT64_C(-4673519228421997952),
                            INT64_C(-1556073591389999033), INT64_C( 3509487153133496527),
                            INT64_C( -438383259974317574), INT64_C( 4679882440059701274),
                            INT64_C( 8594666725077939668), INT64_C(-2603844271228681340)),
      simde_mm512_set_epi64(INT64_C(  877966720713550779), INT64_C(-8757547308289839577),
                            INT64_C( 6619480224799141474), INT64_C( 3171924723684651500),
                            INT64_C( 1941135797030545610), INT64_C( 1935432241277000941),
                            INT64_C( 5390015454023535429), INT64_C(  -49705421380794940)),
      simde_mm512_set_epi64(INT64_C( -751557688731444383), INT64_C(  -49705421380794940),
                            INT64_C( 5226578984858504214), INT64_C(  877966720713550779),
                            INT64_C(-1848672680316222475), INT64_C( 1658167909352451238),
                            INT64_C( 3171924723684651500), INT64_C(-6742373427678247978)) },
    { simde_mm512_set_epi64(INT64_C( 8280910196874944184), INT64_C( -368934386460614235),
                            INT64_C(-9011857488067354178), INT64_C( 5578921037540219940),
                            INT64_C(-7880186302232587827), INT64_C( 7848707034806784644),
                            INT64_C(-7246117184140796511), INT64_C( 5042844271761388948)),
      UINT8_C(191),
      simde_mm512_set_epi64(INT64_C( 6286668337562607931), INT64_C( 1432089847019206822),
                            INT64_C(-2235254547542691893), INT64_C(-2975358417486477451),
                            INT64_C( 5974528986311566652), INT64_C( 4798128784982043356),
                            INT64_C(-3663239326212228984), INT64_C(-9199851098963784696)),
      simde_mm512_set_epi64(INT64_C(-3486865648830471282), INT64_C( 8151787653682140580),
                            INT64_C( -831601358278995789), INT64_C(-2800664419916301039),
                            INT64_C( 3280702275774868225), INT64_C(-4735905134864699368),
                            INT64_C( 7051416147935021095), INT64_C(-4824857292892203785)),
      simde_mm512_set_epi64(INT64_C( 3280702275774868225), INT64_C( -368934386460614235),
                            INT64_C( 3280702275774868225), INT64_C( -831601358278995789),
                            INT64_C(-2800664419916301039), INT64_C(-2800664419916301039),
                            INT64_C(-4824857292892203785), INT64_C(-4824857292892203785)) },
    { simde_mm512_set_epi64(INT64_C( 3133701381660189032), INT64_C( 2992395291812361347),
                            INT64_C( 7433247024135605559), INT64_C(-7847040024436431351),
                            INT64_C(-7733586635814839612), INT64_C(-3387038813920004365),
                            INT64_C(-6023807055599376167), INT64_C( 2056379472574346663)),
      UINT8_C( 49),
      simde_mm512_set_epi64(INT64_C(-7164378700336361334), INT64_C( 4351794567182281042),
                            INT64_C(-1716872434006574729), INT64_C( -689503347190866770),
                            INT64_C(-1389624339165317749), INT64_C(-8184083999390244234),
                            INT64_C( 8331479114169761131), INT64_C( 8817045194671758320)),
      simde_mm512_set_epi64(INT64_C( 8457250603347908949), INT64_C(-2879367942796632989),
                            INT64_C( 4447365578798205979), INT64_C( 6508361231067538121),
                            INT64_C(-2742037214038451026), INT64_C(  735886283373328205),
                            INT64_C(  709814645617696632), INT64_C( 6904524208941840952)),
      simde_mm512_set_epi64(INT64_C( 3133701381660189032), INT64_C( 2992395291812361347),
                            INT64_C( 8457250603347908949), INT64_C(-2879367942796632989),
                            INT64_C(-7733586635814839612), INT64_C(-3387038813920004365),
                            INT64_C(-6023807055599376167), INT64_C( 6904524208941840952)) },
    { simde_mm512_set_epi64(INT64_C(-5794728280408613058), INT64_C(-2239584601742201287),
                            INT64_C(-7241800185060747124), INT64_C(-1565786646142169322),
                            INT64_C( -889744926927160355), INT64_C( 1558039774934209011),
                            INT64_C(-1705673414097118029), INT64_C(-7415013841836228664)),
      UINT8_C( 85),
      simde_mm512_set_epi64(INT64_C(-8286621218977708484), INT64_C(-7274138402675197655),
                            INT64_C( 7751882187628938139), INT64_C(-6483923961368987645),
                            INT64_C(-7861334054348205497), INT64_C( 1332497272334397574),
                            INT64_C(-5616284701672264206), INT64_C( 2669799685376652269)),
      simde_mm512_set_epi64(INT64_C(-8996724198675706045), INT64_C( 4531347139384149531),
                            INT64_C( 6846192780240638418), INT64_C( -574036823136878484),
                            INT64_C(  200988278415395979), INT64_C(-2971850709824830963),
                            INT64_C(-2133313091920417115), INT64_C( 4623597880832003711)),
      simde_mm512_set_epi64(INT64_C(-5794728280408613058), INT64_C(-2133313091920417115),
                            INT64_C(-7241800185060747124), INT64_C(  200988278415395979),
                            INT64_C( -889744926927160355), INT64_C( 4531347139384149531),
                            INT64_C(-1705673414097118029), INT64_C( 6846192780240638418)) },
    { simde_mm512_set_epi64(INT64_C(-2846384524028678721), INT64_C( -114907203345763002),
                            INT64_C( 6558389511800899990), INT64_C(-4552626589350649654),
                            INT64_C( 6286737449187014461), INT64_C( 4819848349711762844),
                            INT64_C(-8124715335380010742), INT64_C(-5554621393600539785)),
      UINT8_C( 38),
      simde_mm512_set_epi64(INT64_C(-7150215929147729012), INT64_C( 4777590230543990164),
                            INT64_C(-7212709010936609343), INT64_C(-5423311652387614668),
                            INT64_C(-5446377680450598123), INT64_C( 6545920141858823590),
                            INT64_C(-6109676225565942508), INT64_C( 7950769636462343621)),
      simde_mm512_set_epi64(INT64_C(-2152884252876571606), INT64_C( 4319783394314419342),
                            INT64_C( 6791040176392068936), INT64_C(-5028583849026132210),
                            INT64_C(-4972499093922240541), INT64_C( 4727277852622403631),
                            INT64_C( 6634263876539878890), INT64_C( 8461555540128585842)),
      simde_mm512_set_epi64(INT64_C(-2846384524028678721), INT64_C( -114907203345763002),
                            INT64_C( 6634263876539878890), INT64_C(-4552626589350649654),
                            INT64_C( 6286737449187014461), INT64_C( 4319783394314419342),
                            INT64_C(-5028583849026132210), INT64_C(-5554621393600539785)) },
    { simde_mm512_set_epi64(INT64_C(-8053906756439817478), INT64_C( 1060597045389905266),
                            INT64_C(-2315048080352408894), INT64_C( 6920541276171034783),
                            INT64_C( 4875597175448786738), INT64_C( 5185598888390136126),
                            INT64_C( 5924820997437064035), INT64_C(-2097986554951915719)),
      UINT8_C(103),
      simde_mm512_set_epi64(INT64_C(  -33031391515316701), INT64_C( 2632656663253186971),
                            INT64_C( 2501795714758146857), INT64_C( 2656255738409935115),
                            INT64_C( 6030400592505510024), INT64_C(-7025690618752263125),
                            INT64_C( 1113429035778363206), INT64_C( 5609096713955085291)),
      simde_mm512_set_epi64(INT64_C(-2900658911065724872), INT64_C(-6013736823954521010),
                            INT64_C(-8141101389788536661), INT64_C( 4749248201355274195),
                            INT64_C(-5391280202694098336), INT64_C( 4277556482249044385),
                            INT64_C( 5968346858124406788), INT64_C( 8575975742580047586)),
      simde_mm512_set_epi64(INT64_C(-8053906756439817478), INT64_C(-5391280202694098336),
                            INT64_C( 5968346858124406788), INT64_C( 6920541276171034783),
                            INT64_C( 4875597175448786738), INT64_C(-5391280202694098336),
                            INT64_C(-6013736823954521010), INT64_C(-5391280202694098336)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_permutexvar_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_permutexvar_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i idx;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { UINT8_C( 87),
      simde_mm512_set_epi64(INT64_C( 4086853108457730066), INT64_C(-7738570880062900818),
                            INT64_C(-5609503674875201288), INT64_C( 3966155248134972346),
                            INT64_C( 6201510655001996332), INT64_C( 7633590894537872708),
                            INT64_C(-5593693910291334810), INT64_C(-8884932670315115433)),
      simde_mm512_set_epi64(INT64_C(-4767707706458520415), INT64_C(-7083171014951853588),
                            INT64_C(-2076988212358998594), INT64_C( 3698505898575972461),
                            INT64_C(-8586603972668500699), INT64_C( 7848938818320954984),
                            INT64_C(-7002500096438875648), INT64_C( 1477571573764517782)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-7083171014951853588),
                            INT64_C(                   0), INT64_C( 7848938818320954984),
                            INT64_C(                   0), INT64_C( 3698505898575972461),
                            INT64_C(-7083171014951853588), INT64_C(-4767707706458520415)) },
    { UINT8_C(157),
      simde_mm512_set_epi64(INT64_C( 1516975282358243755), INT64_C(-3949523894747321163),
                            INT64_C(-2989078375862773056), INT64_C(-4700117291684372957),
                            INT64_C(-8784413934425613521), INT64_C(  961867877660623168),
                            INT64_C( 2426510480636680010), INT64_C(-6612602987193650875)),
      simde_mm512_set_epi64(INT64_C( 7391005387705442660), INT64_C(-5091463632259113685),
                            INT64_C(  685405269785004780), INT64_C(-2602517860068074949),
                            INT64_C( 4704994953943345443), INT64_C( 8877610218385468208),
                            INT64_C( 5776984527519295337), INT64_C( 6526937450820584225)),
      simde_mm512_set_epi64(INT64_C( 4704994953943345443), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 4704994953943345443),
                            INT64_C( 7391005387705442660), INT64_C( 6526937450820584225),
                            INT64_C(                   0), INT64_C(  685405269785004780)) },
    { UINT8_C( 75),
      simde_mm512_set_epi64(INT64_C(-1414228054518303181), INT64_C(-3038909907977133732),
                            INT64_C(-7842471790453318316), INT64_C(-7256600765093102205),
                            INT64_C( 3898178537456140670), INT64_C( -393151907512138120),
                            INT64_C(  600214805061827669), INT64_C( 3163434753014979248)),
      simde_mm512_set_epi64(INT64_C( 1455933536394832297), INT64_C( -840828676201867557),
                            INT64_C( 6310833464661060096), INT64_C( 8429580363859954742),
                            INT64_C( 5406280044045291975), INT64_C(-2284955492954404973),
                            INT64_C(-3603637419527123210), INT64_C(-1117409850830928520)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C( 8429580363859954742),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C( -840828676201867557), INT64_C(                   0),
                            INT64_C( 6310833464661060096), INT64_C(-1117409850830928520)) },
    { UINT8_C( 23),
      simde_mm512_set_epi64(INT64_C( 6555696811272222802), INT64_C( -751557688731444383),
                            INT64_C( 5324069355912068288), INT64_C( 5226578984858504214),
                            INT64_C(-8776157931044543560), INT64_C(-1848672680316222475),
                            INT64_C( 1658167909352451238), INT64_C(  377173394815185621)),
      simde_mm512_set_epi64(INT64_C(-4670296842224865750), INT64_C(-8736438908262001915),
                            INT64_C(-1516874692875012272), INT64_C( 2654080637722702840),
                            INT64_C(-4444585746033374017), INT64_C( 7620312646179506248),
                            INT64_C(-4730811392556899367), INT64_C(-7555925455226975890)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-8736438908262001915),
                            INT64_C(                   0), INT64_C(-1516874692875012272),
                            INT64_C(-8736438908262001915), INT64_C(-1516874692875012272)) },
    { UINT8_C( 46),
      simde_mm512_set_epi64(INT64_C( 5042844271761388948), INT64_C(  877966720713550779),
                            INT64_C(-8757547308289839577), INT64_C( 6619480224799141474),
                            INT64_C( 3171924723684651500), INT64_C( 1941135797030545610),
                            INT64_C( 1935432241277000941), INT64_C( 5390015454023535429)),
      simde_mm512_set_epi64(INT64_C( 2001511420457827007), INT64_C( 8280910196874944184),
                            INT64_C( -368934386460614235), INT64_C(-9011857488067354178),
                            INT64_C( 5578921037540219940), INT64_C(-7880186302232587827),
                            INT64_C( 7848707034806784644), INT64_C(-7246117184140796511)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 2001511420457827007), INT64_C(                   0),
                            INT64_C(-9011857488067354178), INT64_C(-7880186302232587827),
                            INT64_C( -368934386460614235), INT64_C(                   0)) },
    { UINT8_C( 43),
      simde_mm512_set_epi64(INT64_C(-4824857292892203785), INT64_C( 6286668337562607931),
                            INT64_C( 1432089847019206822), INT64_C(-2235254547542691893),
                            INT64_C(-2975358417486477451), INT64_C( 5974528986311566652),
                            INT64_C( 4798128784982043356), INT64_C(-3663239326212228984)),
      simde_mm512_set_epi64(INT64_C( 2056379472574346663), INT64_C(-3486865648830471282),
                            INT64_C( 8151787653682140580), INT64_C( -831601358278995789),
                            INT64_C(-2800664419916301039), INT64_C( 3280702275774868225),
                            INT64_C(-4735905134864699368), INT64_C( 7051416147935021095)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-3486865648830471282), INT64_C(                   0),
                            INT64_C( 8151787653682140580), INT64_C(                   0),
                            INT64_C( -831601358278995789), INT64_C( 7051416147935021095)) },
    { UINT8_C(217),
      simde_mm512_set_epi64(INT64_C( 8817045194671758320), INT64_C(-5234965963681749811),
                            INT64_C(-5331803015084564567), INT64_C(-2592115690296560951),
                            INT64_C( 1248919004007478956), INT64_C( 6138870327161964525),
                            INT64_C(-3131027839562886620), INT64_C(-2317534169293970587)),
      simde_mm512_set_epi64(INT64_C( 6904524208941840952), INT64_C(-7164378700336361334),
                            INT64_C( 4351794567182281042), INT64_C(-1716872434006574729),
                            INT64_C( -689503347190866770), INT64_C(-1389624339165317749),
                            INT64_C(-8184083999390244234), INT64_C( 8331479114169761131)),
      simde_mm512_set_epi64(INT64_C( 8331479114169761131), INT64_C( 4351794567182281042),
                            INT64_C(                   0), INT64_C(-8184083999390244234),
                            INT64_C(-1716872434006574729), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 4351794567182281042)) },
    { UINT8_C(120),
      simde_mm512_set_epi64(INT64_C( 2443726936750986290), INT64_C(-9169540186107924323),
                            INT64_C(-8862352522735882724), INT64_C(-8073374806940567698),
                            INT64_C( 5084858765896996878), INT64_C(-8091734011393453138),
                            INT64_C(-8622672902733011795), INT64_C(  255780820358907048)),
      simde_mm512_set_epi64(INT64_C( 2669799685376652269), INT64_C( 7927414333096918356),
                            INT64_C(-6028737433755228757), INT64_C(-6289085317177674471),
                            INT64_C(-5541511610486147753), INT64_C( 6531713794566454707),
                            INT64_C( -446705336047418133), INT64_C(-6709780755556058351)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-6028737433755228757),
                            INT64_C(-6289085317177674471), INT64_C( 7927414333096918356),
                            INT64_C( 7927414333096918356), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_permutexvar_epi64(test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t idx[64];
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  22),  INT8_C(  85), -INT8_C(  31),  INT8_C( 117), -INT8_C(  32), -INT8_C(  86), -INT8_C( 120), -INT8_C(  43),
         INT8_C(   4), -INT8_C(   3), -INT8_C(  53), -INT8_C(  80), -INT8_C( 109),  INT8_C(  15),  INT8_C( 125), -INT8_C(  41),
        -INT8_C( 115),  INT8_C(  37), -INT8_C(  14), -INT8_C( 111), -INT8_C(  68), -INT8_C( 101),  INT8_C(  66),  INT8_C(  26),
        -INT8_C( 110), -INT8_C( 106),  INT8_C(  19),  INT8_C(  91), -INT8_C(  27), -INT8_C(  92), -INT8_C( 115), -INT8_C(   5),
        -INT8_C(   7),  INT8_C( 111),  INT8_C( 112), -INT8_C(  39),  INT8_C(  25), -INT8_C(   8), -INT8_C(  81),  INT8_C(  29),
        -INT8_C(  11),  INT8_C( 122), -INT8_C(  50), -INT8_C( 119), -INT8_C( 119),  INT8_C(  75),  INT8_C(  96),  INT8_C(  22),
         INT8_C( 112),  INT8_C(  82), -INT8_C(  89),  INT8_C(  44), -INT8_C(  19), -INT8_C(  22),  INT8_C(  71),      INT8_MIN,
             INT8_MIN,  INT8_C(  90), -INT8_C(  37),  INT8_C( 101), -INT8_C(   2),  INT8_C( 104),  INT8_C(  96), -INT8_C(   8) },
      { -INT8_C(  41), -INT8_C(  48), -INT8_C(  47), -INT8_C(  15), -INT8_C(  56),      INT8_MIN,  INT8_C(  14), -INT8_C(  66),
        -INT8_C(   6), -INT8_C(  36),  INT8_C(  71), -INT8_C( 124),  INT8_C(  39), -INT8_C(  89), -INT8_C( 102), -INT8_C( 105),
        -INT8_C(   7),  INT8_C(  66), -INT8_C(  60), -INT8_C(  25),  INT8_C(  44),  INT8_C(  11),  INT8_C( 103), -INT8_C(  84),
         INT8_C( 101),  INT8_C(  66),  INT8_C(  17),  INT8_C( 100), -INT8_C(  86),  INT8_C( 113),  INT8_C(  92), -INT8_C( 126),
         INT8_C(  65),  INT8_C(  45),  INT8_C( 115),  INT8_C(   9), -INT8_C(  82), -INT8_C( 127), -INT8_C(  57), -INT8_C(  88),
         INT8_C(  94),  INT8_C(  14),  INT8_C(  44), -INT8_C( 123), -INT8_C(  75), -INT8_C(  57),  INT8_C(  29), -INT8_C(  81),
         INT8_C(   9), -INT8_C(  31), -INT8_C( 106),  INT8_C(  53), -INT8_C(  20), -INT8_C(   3), -INT8_C(  31),  INT8_C(  81),
         INT8_C(  63), -INT8_C(  14), -INT8_C(  75), -INT8_C(  23),  INT8_C(  99),  INT8_C(  17),  INT8_C( 107), -INT8_C(  92) },
      {  INT8_C( 103),  INT8_C(  11),  INT8_C(  45), -INT8_C(   3),  INT8_C(  65),  INT8_C(  44), -INT8_C(   6),  INT8_C(  11),
        -INT8_C(  56),  INT8_C(  17), -INT8_C( 124),  INT8_C(   9), -INT8_C(  25), -INT8_C( 105),  INT8_C(  17), -INT8_C(  84),
        -INT8_C(  89), -INT8_C( 127), -INT8_C( 106),  INT8_C(  66),  INT8_C(  99),  INT8_C( 100), -INT8_C(  47),  INT8_C(  17),
        -INT8_C(  60),  INT8_C( 103), -INT8_C(  25),  INT8_C( 100), -INT8_C( 127), -INT8_C(  82), -INT8_C(  89), -INT8_C(  23),
        -INT8_C(  14), -INT8_C(  81),  INT8_C(   9),  INT8_C(  66),  INT8_C(  66),  INT8_C(  63), -INT8_C(  81),  INT8_C( 113),
        -INT8_C(   3), -INT8_C(  75), -INT8_C( 102), -INT8_C(  36), -INT8_C(  36), -INT8_C( 124),  INT8_C(  65),  INT8_C( 103),
         INT8_C(   9), -INT8_C(  60), -INT8_C(  88), -INT8_C(  75), -INT8_C(  57),  INT8_C(  44), -INT8_C(  66), -INT8_C(  41),
        -INT8_C(  41),  INT8_C(  17),  INT8_C( 100), -INT8_C( 127),  INT8_C( 107),  INT8_C(  94),  INT8_C(  65),  INT8_C(  63) } },
    { {  INT8_C(  63), -INT8_C(  34), -INT8_C(  83), -INT8_C(  19),  INT8_C(  96),  INT8_C( 117), -INT8_C( 107), -INT8_C(  66),
        -INT8_C( 125), -INT8_C(  62),  INT8_C(  67),  INT8_C(  57), -INT8_C( 119),  INT8_C(  96), -INT8_C(  24), -INT8_C( 110),
         INT8_C(  65),  INT8_C( 126), -INT8_C(  57),  INT8_C(  45),  INT8_C( 123), -INT8_C(  88),      INT8_MAX, -INT8_C(  70),
        -INT8_C( 102),  INT8_C(  52), -INT8_C(  93), -INT8_C(   3),  INT8_C(  70),  INT8_C(  15), -INT8_C(  95), -INT8_C( 123),
        -INT8_C(  19),  INT8_C(  78),  INT8_C( 114),  INT8_C(  77), -INT8_C(  61),  INT8_C(   7),  INT8_C(  11),  INT8_C(  71),
        -INT8_C(  55),  INT8_C(  79),      INT8_MIN,  INT8_C(  82), -INT8_C(  81),  INT8_C( 104), -INT8_C(  28), -INT8_C(  15),
        -INT8_C(  26), -INT8_C(  85),  INT8_C(  30),  INT8_C(  97),  INT8_C(  83), -INT8_C(  99),  INT8_C(  27), -INT8_C(  19),
        -INT8_C(  46), -INT8_C(  66), -INT8_C(  22),  INT8_C(  24), -INT8_C(  51), -INT8_C( 117), -INT8_C(  99), -INT8_C(  69) },
      { -INT8_C(  38),  INT8_C(  15),  INT8_C(   8), -INT8_C(  99),  INT8_C(  22),  INT8_C(  20), -INT8_C(  28), -INT8_C(  32),
         INT8_C(  99),  INT8_C( 100),  INT8_C(  50),  INT8_C(  18), -INT8_C(  52),  INT8_C(  23),  INT8_C(   3), -INT8_C(  78),
        -INT8_C(  62),  INT8_C(  34),  INT8_C(  19),  INT8_C(  22), -INT8_C(  65),  INT8_C(  46),  INT8_C(   3), -INT8_C( 111),
        -INT8_C(  19), -INT8_C(  18), -INT8_C(  87), -INT8_C(  70),  INT8_C( 121),  INT8_C(  70),  INT8_C( 117),  INT8_C(  83),
         INT8_C(  85),  INT8_C( 126), -INT8_C(  15),  INT8_C( 108), -INT8_C( 110), -INT8_C(  43),  INT8_C(  76), -INT8_C(  11),
         INT8_C(  58),  INT8_C( 126),  INT8_C(   7),  INT8_C(   6), -INT8_C( 107),  INT8_C(  11), -INT8_C(  71),  INT8_C(  88),
         INT8_C(  45), -INT8_C(  52),  INT8_C( 110), -INT8_C(  20), -INT8_C(   5),  INT8_C( 113),  INT8_C( 126), -INT8_C(  24),
         INT8_C(  95),  INT8_C(  39), -INT8_C(  94), -INT8_C(  39),  INT8_C( 110),  INT8_C(  24),  INT8_C(  44), -INT8_C(  61) },
      { -INT8_C(  61),  INT8_C( 117),  INT8_C(  11),  INT8_C(  11),  INT8_C(  85),  INT8_C( 113),  INT8_C(  46),  INT8_C(  44),
        -INT8_C(  99),  INT8_C(   8), -INT8_C(  99),  INT8_C(  39),  INT8_C( 100),  INT8_C(  85),  INT8_C(  58),  INT8_C(  19),
         INT8_C(  15),  INT8_C(  44), -INT8_C(  32),  INT8_C(  11), -INT8_C(  39),  INT8_C(  58), -INT8_C(  61), -INT8_C(  94),
        -INT8_C(  87), -INT8_C(   5),  INT8_C( 108),  INT8_C(  24), -INT8_C(  28), -INT8_C(  78),  INT8_C( 126),  INT8_C(  20),
         INT8_C(  11),  INT8_C(   3),  INT8_C( 110),  INT8_C(  23), -INT8_C(  99), -INT8_C(  32),  INT8_C(  18), -INT8_C(  32),
         INT8_C( 100), -INT8_C(  78), -INT8_C(  38),  INT8_C(  19),  INT8_C(  88),  INT8_C(  58), -INT8_C( 110), -INT8_C(  52),
         INT8_C(  76),  INT8_C(   6),  INT8_C( 117),  INT8_C( 126),  INT8_C(  22),  INT8_C(  70), -INT8_C(  70),  INT8_C(  11),
         INT8_C(  19),  INT8_C(  44),  INT8_C(   7), -INT8_C(  19),  INT8_C(  23),  INT8_C(  18),  INT8_C(  70), -INT8_C(  39) } },
    { { -INT8_C( 106),  INT8_C(  29),  INT8_C(  47),  INT8_C(  40), -INT8_C(  13),  INT8_C( 123),  INT8_C(  29),  INT8_C(  45),
        -INT8_C(   6),  INT8_C(  36),  INT8_C(  51), -INT8_C( 113),  INT8_C(  47), -INT8_C(  20), -INT8_C(  25),  INT8_C(  92),
        -INT8_C(  71),  INT8_C(  85),  INT8_C(  73), -INT8_C(  76), -INT8_C(  57), -INT8_C(  57), -INT8_C( 100),  INT8_C(  38),
        -INT8_C(  18),  INT8_C(  62), -INT8_C(   1),  INT8_C(  92),  INT8_C(  86),  INT8_C(  44),  INT8_C(  32), -INT8_C(  20),
         INT8_C(  73),  INT8_C(  79),  INT8_C(  20),  INT8_C(  60), -INT8_C(  53),  INT8_C(  49),  INT8_C( 105), -INT8_C(  59),
         INT8_C(  86), -INT8_C(  99),  INT8_C(  84), -INT8_C( 123), -INT8_C( 119),  INT8_C(  60), -INT8_C(  30),  INT8_C(  66),
        -INT8_C( 111),  INT8_C(  43), -INT8_C(  10),  INT8_C(  88), -INT8_C(  14), -INT8_C( 110),      INT8_MAX, -INT8_C(  32),
        -INT8_C(  47),  INT8_C( 126),  INT8_C(  61),  INT8_C(  39), -INT8_C(  86),  INT8_C(  93),  INT8_C(  20), -INT8_C(  12) },
      { -INT8_C(  84),  INT8_C(  40),  INT8_C(  48),  INT8_C( 119),  INT8_C(  90), -INT8_C( 102),  INT8_C(  60), -INT8_C(  80),
         INT8_C(  55), -INT8_C( 111),  INT8_C(  53), -INT8_C(  64), -INT8_C(  51),  INT8_C(  23),  INT8_C(   3),  INT8_C(  94),
         INT8_C(  66), -INT8_C(   7), -INT8_C(  73),  INT8_C(  52), -INT8_C( 116),  INT8_C(  54),  INT8_C(  21),  INT8_C(  93),
        -INT8_C(  76),  INT8_C(  82), -INT8_C( 124),  INT8_C(  95), -INT8_C(  81), -INT8_C( 104),  INT8_C(  83),  INT8_C(  91),
        -INT8_C(  63), -INT8_C( 125), -INT8_C(  45),  INT8_C(  27),  INT8_C(  29),  INT8_C(  15), -INT8_C(  53),  INT8_C(  84),
        -INT8_C(  96),  INT8_C(   0),  INT8_C(  21),  INT8_C( 109),  INT8_C(  24),  INT8_C(  24), -INT8_C(  52),  INT8_C(  90),
         INT8_C(  17), -INT8_C( 125), -INT8_C( 113), -INT8_C(  99), -INT8_C(  71), -INT8_C(  92), -INT8_C(   6),  INT8_C( 109),
        -INT8_C(  10),      INT8_MAX, -INT8_C(  52), -INT8_C(  91),  INT8_C(  23),  INT8_C(  31),  INT8_C(   0), -INT8_C(  40) },
      {  INT8_C(  21), -INT8_C( 104),  INT8_C(  90), -INT8_C(  96), -INT8_C(  99), -INT8_C(  91), -INT8_C( 104),  INT8_C(  24),
        -INT8_C(  52),  INT8_C(  29), -INT8_C(  99),  INT8_C(  94),  INT8_C(  90),  INT8_C(  24),  INT8_C(  84), -INT8_C(  81),
             INT8_MAX,  INT8_C(  54), -INT8_C( 111), -INT8_C(  71), -INT8_C(  80), -INT8_C(  80), -INT8_C(  81), -INT8_C(  53),
        -INT8_C(  52),  INT8_C(   0), -INT8_C(  40), -INT8_C(  81),  INT8_C(  21),  INT8_C(  24), -INT8_C(  63),  INT8_C(  24),
        -INT8_C( 111),  INT8_C(  94), -INT8_C( 116),  INT8_C(  23), -INT8_C(  64), -INT8_C( 125),  INT8_C(   0), -INT8_C( 102),
         INT8_C(  21), -INT8_C( 104), -INT8_C( 116), -INT8_C( 102), -INT8_C( 111),  INT8_C(  23), -INT8_C(  45),  INT8_C(  48),
        -INT8_C(   7),  INT8_C( 109), -INT8_C(   6), -INT8_C(  76), -INT8_C( 113), -INT8_C(  73), -INT8_C(  40), -INT8_C(  63),
        -INT8_C(   7),  INT8_C(   0),  INT8_C(  31),  INT8_C(  84),  INT8_C(  21), -INT8_C( 104), -INT8_C( 116), -INT8_C(  71) } },
    { { -INT8_C(  93), -INT8_C(  45), -INT8_C(  13), -INT8_C(  64), -INT8_C(  29), -INT8_C(  66),  INT8_C(  21), -INT8_C( 125),
        -INT8_C(  65),  INT8_C(  42), -INT8_C(  15), -INT8_C(  41),  INT8_C(  66), -INT8_C(  67),  INT8_C(  49),  INT8_C(  83),
         INT8_C(  64), -INT8_C(  64), -INT8_C(  15), -INT8_C(   7),  INT8_C( 100), -INT8_C(  21),  INT8_C( 102),  INT8_C(  90),
         INT8_C( 106),  INT8_C(  51), -INT8_C(   1), -INT8_C( 126),  INT8_C(  82),  INT8_C(   0),  INT8_C(  90), -INT8_C(  11),
        -INT8_C(  45),  INT8_C(  78), -INT8_C(  74), -INT8_C(  74),  INT8_C(  12), -INT8_C(  53),  INT8_C(  58), -INT8_C(  53),
        -INT8_C(  11),  INT8_C(  43), -INT8_C(  94),  INT8_C(  55), -INT8_C(  24), -INT8_C(  44), -INT8_C( 118),  INT8_C(  40),
        -INT8_C( 108),  INT8_C( 123),  INT8_C(  33), -INT8_C(   7),  INT8_C( 103), -INT8_C( 121),  INT8_C(  83), -INT8_C(  47),
        -INT8_C(  70),  INT8_C(  83),  INT8_C(  83),  INT8_C(  13),  INT8_C(  83), -INT8_C(  82),  INT8_C(   2),  INT8_C(  38) },
      { -INT8_C(   4), -INT8_C(  72), -INT8_C(  35),  INT8_C(   8), -INT8_C( 125),  INT8_C(  23), -INT8_C(  44),  INT8_C( 120),
         INT8_C(  66),  INT8_C( 118), -INT8_C(  81),  INT8_C(  42),  INT8_C(  74),  INT8_C(  58),  INT8_C(  82), -INT8_C(  33),
        -INT8_C(  75),  INT8_C( 115), -INT8_C(  40),  INT8_C(  28), -INT8_C(   6),  INT8_C(  43), -INT8_C(  18), -INT8_C(  75),
         INT8_C( 126),  INT8_C(  65), -INT8_C(  62), -INT8_C(  47), -INT8_C(  17), -INT8_C(  60), -INT8_C(   8), -INT8_C(  21),
         INT8_C( 125), -INT8_C(  43), -INT8_C(  12),  INT8_C(   0), -INT8_C(  20), -INT8_C(  56),  INT8_C( 121),  INT8_C(  46),
         INT8_C(  62),  INT8_C(  40),  INT8_C(  88), -INT8_C( 119),  INT8_C(  98), -INT8_C(  86),  INT8_C( 104),  INT8_C(  24),
         INT8_C(  29),  INT8_C(  64),  INT8_C(  52),  INT8_C(  23),  INT8_C( 107),  INT8_C(  34), -INT8_C(  52), -INT8_C(  22),
         INT8_C( 100), -INT8_C( 114), -INT8_C(  69),  INT8_C(  83),  INT8_C(  83), -INT8_C(  77),  INT8_C(  63), -INT8_C(  48) },
      {  INT8_C(   0),  INT8_C(  28),  INT8_C(  23), -INT8_C(   4),  INT8_C(   0),  INT8_C(  63),  INT8_C(  43),  INT8_C(   8),
        -INT8_C(  48),  INT8_C(  88),  INT8_C(  64), -INT8_C(  75), -INT8_C(  35), -INT8_C(  77),  INT8_C(  64),  INT8_C(  28),
        -INT8_C(   4), -INT8_C(   4),  INT8_C(  64), -INT8_C( 114), -INT8_C(  20), -INT8_C( 119),  INT8_C( 121), -INT8_C(  62),
         INT8_C(  88),  INT8_C(  23), -INT8_C(  48), -INT8_C(  35), -INT8_C(  40), -INT8_C(   4), -INT8_C(  62),  INT8_C(  34),
         INT8_C(  28),  INT8_C(  82), -INT8_C(  52), -INT8_C(  52),  INT8_C(  74),  INT8_C(  42), -INT8_C(  69),  INT8_C(  42),
         INT8_C(  34), -INT8_C( 119), -INT8_C(  12), -INT8_C(  22),  INT8_C(  62), -INT8_C(   6), -INT8_C(  81),  INT8_C(  62),
        -INT8_C(   6),  INT8_C(  83), -INT8_C(  43), -INT8_C( 114),  INT8_C(  46),  INT8_C( 120),  INT8_C(  28),  INT8_C( 115),
        -INT8_C(  69),  INT8_C(  28),  INT8_C(  28),  INT8_C(  58),  INT8_C(  28),  INT8_C( 104), -INT8_C(  35),  INT8_C( 121) } },
    { { -INT8_C( 120),  INT8_C(  51), -INT8_C(  48),  INT8_C( 116), -INT8_C(   5),  INT8_C(  73), -INT8_C(  94),  INT8_C(  57),
         INT8_C( 114), -INT8_C(   6), -INT8_C(  62), -INT8_C(  44), -INT8_C(  92),  INT8_C(  42), -INT8_C(  20), -INT8_C(  63),
         INT8_C( 106),  INT8_C(  33), -INT8_C(  39), -INT8_C(  42),  INT8_C(  67), -INT8_C(  91), -INT8_C(  64), -INT8_C(  89),
         INT8_C(  52),  INT8_C( 123), -INT8_C(   5), -INT8_C( 121),  INT8_C(  47),  INT8_C(  58),  INT8_C(  87), -INT8_C(  73),
         INT8_C( 109),  INT8_C(  39),  INT8_C(  44),  INT8_C( 104),  INT8_C( 113), -INT8_C(  50), -INT8_C(  95), -INT8_C(  29),
        -INT8_C(  55),  INT8_C( 100), -INT8_C(  73),  INT8_C( 109), -INT8_C( 114), -INT8_C(  92),  INT8_C(  47), -INT8_C(   7),
        -INT8_C(  59),  INT8_C(   8), -INT8_C(  49),  INT8_C(   8), -INT8_C(  83), -INT8_C( 113), -INT8_C(  80), -INT8_C(  31),
         INT8_C(  10), -INT8_C(  85),  INT8_C( 104),  INT8_C(  57), -INT8_C(  27), -INT8_C(  65), -INT8_C(  15),  INT8_C(  82) },
      { -INT8_C(  25),  INT8_C(  29), -INT8_C(  70),  INT8_C(  88), -INT8_C(  21),  INT8_C(  91),  INT8_C(  59), -INT8_C(  76),
        -INT8_C(  65), -INT8_C(  14),  INT8_C(  34),  INT8_C(  78), -INT8_C( 106),  INT8_C(  81),  INT8_C(  71),  INT8_C(  91),
         INT8_C(  89),  INT8_C(  22),  INT8_C( 100),  INT8_C(   6), -INT8_C(  91),  INT8_C(  20), -INT8_C(  24), -INT8_C(  81),
        -INT8_C(  65),  INT8_C(  80), -INT8_C(  23), -INT8_C(  92),  INT8_C(  16), -INT8_C(  38), -INT8_C(  10), -INT8_C(   9),
        -INT8_C(   9), -INT8_C(  80),  INT8_C(  79), -INT8_C(  30),  INT8_C(  11), -INT8_C( 118), -INT8_C( 105), -INT8_C(  53),
         INT8_C( 124), -INT8_C(  71),  INT8_C(  25),  INT8_C(  19),  INT8_C(  10),  INT8_C(  96),  INT8_C( 110),  INT8_C(  99),
         INT8_C( 118), -INT8_C(  46),  INT8_C( 105),  INT8_C(  27), -INT8_C(  26),  INT8_C(  81), -INT8_C(  54), -INT8_C(  91),
        -INT8_C(  94), -INT8_C(  77),  INT8_C(  73), -INT8_C(  78), -INT8_C( 115),  INT8_C(  63), -INT8_C(  87), -INT8_C( 124) },
      { -INT8_C(  65),  INT8_C(  27),  INT8_C(  89), -INT8_C(  26), -INT8_C(  78), -INT8_C(  14),  INT8_C(  79), -INT8_C(  77),
         INT8_C( 105),  INT8_C(  73), -INT8_C(  70), -INT8_C(  91),  INT8_C(  11),  INT8_C(  25),  INT8_C(  10),  INT8_C(  29),
         INT8_C(  25), -INT8_C(  80),  INT8_C(  80), -INT8_C(  24),  INT8_C(  88), -INT8_C( 118), -INT8_C(  25), -INT8_C(  53),
        -INT8_C(  26), -INT8_C(  78), -INT8_C(  78), -INT8_C(  76),  INT8_C(  99),  INT8_C(  73), -INT8_C(  81), -INT8_C(  91),
         INT8_C(  96), -INT8_C(  53),  INT8_C(  10),  INT8_C( 124), -INT8_C(  46),  INT8_C(  71), -INT8_C(  80), -INT8_C(  30),
        -INT8_C(  14),  INT8_C(  11), -INT8_C(  91),  INT8_C(  96),  INT8_C(  71),  INT8_C(  11),  INT8_C(  99), -INT8_C(  77),
         INT8_C(  91), -INT8_C(  65),  INT8_C(  91), -INT8_C(  65),  INT8_C(  96),  INT8_C(  91),  INT8_C( 118), -INT8_C(  80),
         INT8_C(  34),  INT8_C(  19),  INT8_C( 124), -INT8_C(  77), -INT8_C( 118), -INT8_C( 124), -INT8_C(  46),  INT8_C( 100) } },
    { { -INT8_C(  17), -INT8_C(   8),  INT8_C( 103), -INT8_C(   5), -INT8_C( 126), -INT8_C(   2), -INT8_C(  58), -INT8_C(   2),
        -INT8_C(  73), -INT8_C(  33),  INT8_C(  17), -INT8_C(  63),  INT8_C(  63),      INT8_MIN,  INT8_C(  36), -INT8_C(  75),
         INT8_C(  82), -INT8_C( 115), -INT8_C(  48),  INT8_C(  57), -INT8_C(  33), -INT8_C( 102), -INT8_C(  34), -INT8_C( 127),
         INT8_C(  78),  INT8_C(  40),  INT8_C(  51), -INT8_C(  37),  INT8_C( 103), -INT8_C(  36),  INT8_C(  96),  INT8_C(  87),
        -INT8_C(  44), -INT8_C(  57),  INT8_C(  82),  INT8_C(  86), -INT8_C(  59),  INT8_C(  24),  INT8_C(  84),  INT8_C( 124),
        -INT8_C(   9),  INT8_C( 102),  INT8_C(  61),  INT8_C(  54), -INT8_C(  26),  INT8_C(  97), -INT8_C(  21),  INT8_C(  56),
        -INT8_C(  18), -INT8_C(  69),  INT8_C( 113), -INT8_C(  51),  INT8_C(  85),  INT8_C(  80),  INT8_C(  78), -INT8_C(  93),
         INT8_C( 120), -INT8_C( 127),      INT8_MAX, -INT8_C(  33),  INT8_C(  93), -INT8_C(  33),  INT8_C(  54),  INT8_C(  49) },
      { -INT8_C(  90), -INT8_C( 120), -INT8_C( 121),  INT8_C( 107), -INT8_C(  96), -INT8_C(  36), -INT8_C(  25), -INT8_C( 105),
         INT8_C(  66),  INT8_C(  36), -INT8_C(  51),  INT8_C(  40), -INT8_C( 123), -INT8_C(  72),  INT8_C(  96),  INT8_C( 115),
         INT8_C( 115), -INT8_C(  46),  INT8_C(  65), -INT8_C(  55),  INT8_C(  34), -INT8_C( 113),  INT8_C( 108), -INT8_C( 102),
         INT8_C(  17), -INT8_C(  21),  INT8_C( 121),  INT8_C( 110), -INT8_C(  54), -INT8_C(  80), -INT8_C(  96),  INT8_C( 112),
         INT8_C(  56),  INT8_C(  39), -INT8_C(  37), -INT8_C(  39),  INT8_C(   3), -INT8_C(  62),  INT8_C( 112),  INT8_C(  69),
        -INT8_C(  26),  INT8_C(  62),  INT8_C( 109),  INT8_C( 107), -INT8_C(  10), -INT8_C(  50), -INT8_C(  33),  INT8_C( 106),
        -INT8_C(  96),  INT8_C(  32),  INT8_C(  51), -INT8_C(  62), -INT8_C(  81), -INT8_C(  97),  INT8_C(  92), -INT8_C(  64),
        -INT8_C( 117), -INT8_C(  43),  INT8_C(  47),  INT8_C(  85), -INT8_C( 123), -INT8_C(  49), -INT8_C(  58), -INT8_C(  66) },
      {  INT8_C( 106), -INT8_C( 117),  INT8_C(  69),  INT8_C(  85), -INT8_C( 121), -INT8_C(  58), -INT8_C(  25), -INT8_C(  58),
        -INT8_C(  64),  INT8_C( 112), -INT8_C(  46), -INT8_C( 120), -INT8_C(  66), -INT8_C(  90),  INT8_C(   3), -INT8_C(  97),
         INT8_C(  65), -INT8_C(  72),  INT8_C( 115), -INT8_C(  43),  INT8_C( 112),  INT8_C( 121), -INT8_C(  96), -INT8_C( 120),
         INT8_C(  96), -INT8_C(  26), -INT8_C(  62),  INT8_C( 110),  INT8_C(  69), -INT8_C(  54),  INT8_C(  56), -INT8_C( 102),
         INT8_C(  34), -INT8_C( 105),  INT8_C(  65),  INT8_C( 108), -INT8_C(  36),  INT8_C(  17),  INT8_C(  34), -INT8_C( 123),
        -INT8_C(  64),  INT8_C( 112), -INT8_C(  49),  INT8_C(  92),  INT8_C( 112),  INT8_C(  39),  INT8_C( 107), -INT8_C( 117),
        -INT8_C(  33),  INT8_C(  85),  INT8_C(  32), -INT8_C(  72), -INT8_C( 113),  INT8_C( 115),  INT8_C(  96), -INT8_C(  39),
        -INT8_C( 117), -INT8_C( 120), -INT8_C(  66),  INT8_C( 112), -INT8_C(  80),  INT8_C( 112),  INT8_C(  92),  INT8_C(  32) } },
    { { -INT8_C(  10), -INT8_C(  95), -INT8_C( 105), -INT8_C(   6),  INT8_C( 100),  INT8_C(   7),  INT8_C(  63),  INT8_C(  74),
         INT8_C(  69), -INT8_C(  83), -INT8_C(  74),  INT8_C(  60),  INT8_C( 123), -INT8_C( 107), -INT8_C(  90),  INT8_C(  27),
        -INT8_C(  75), -INT8_C(  39), -INT8_C(  35),  INT8_C( 100),  INT8_C( 120),  INT8_C(  57),  INT8_C(  37),  INT8_C(   3),
         INT8_C(  14),  INT8_C(  84),  INT8_C(  89), -INT8_C( 108),  INT8_C(  35),  INT8_C(  31),  INT8_C(  82),  INT8_C(  25),
        -INT8_C(  64), -INT8_C(  23),  INT8_C(  19),  INT8_C(  36), -INT8_C(  16),  INT8_C(  83),  INT8_C( 111),  INT8_C(  54),
         INT8_C(   0),  INT8_C(  37),  INT8_C( 114),  INT8_C( 123), -INT8_C(  70),  INT8_C(  24), -INT8_C( 106),  INT8_C( 111),
        -INT8_C(  15),  INT8_C( 115), -INT8_C(  45),  INT8_C( 105), -INT8_C(  84), -INT8_C(   8),  INT8_C( 109), -INT8_C(  70),
         INT8_C(  76), -INT8_C(  58),  INT8_C(  78),  INT8_C( 111), -INT8_C(  27), -INT8_C(  96), -INT8_C( 119), -INT8_C(  91) },
      { -INT8_C( 119), -INT8_C( 100), -INT8_C(  54),  INT8_C( 122), -INT8_C(  17),  INT8_C(  57), -INT8_C(  80), -INT8_C(  17),
         INT8_C(  94),  INT8_C(  34),  INT8_C( 106),  INT8_C(  24),  INT8_C(  58),  INT8_C(   0), -INT8_C( 121),  INT8_C(  43),
         INT8_C( 115),  INT8_C(  90), -INT8_C( 108),  INT8_C(  31),  INT8_C(  83),  INT8_C(   1), -INT8_C(  38), -INT8_C(  97),
        -INT8_C(  57),  INT8_C(  40),  INT8_C(  15), -INT8_C(  84), -INT8_C(  55), -INT8_C( 104),  INT8_C(  82),  INT8_C(  82),
         INT8_C(  52),  INT8_C(  28), -INT8_C(  52),  INT8_C(  36),  INT8_C(  85),  INT8_C( 124),  INT8_C(  19), -INT8_C(  77),
        -INT8_C(  98),  INT8_C( 126), -INT8_C(  53), -INT8_C(  40),  INT8_C( 126),  INT8_C(  82),  INT8_C(   3), -INT8_C(  14),
        -INT8_C(  84), -INT8_C( 104),  INT8_C(  17), -INT8_C(   1), -INT8_C( 103), -INT8_C(  21), -INT8_C(  97),  INT8_C(  97),
         INT8_C(  20), -INT8_C(  82),  INT8_C(  13), -INT8_C(  35),  INT8_C(  70),  INT8_C(  95),  INT8_C(  47),  INT8_C( 122) },
      { -INT8_C(  97),  INT8_C(  28), -INT8_C(  97),  INT8_C(  13),  INT8_C(  85), -INT8_C(  17),  INT8_C( 122),  INT8_C( 106),
         INT8_C(  57),  INT8_C(  82), -INT8_C(  97),  INT8_C(  70), -INT8_C(  35),  INT8_C(   1),  INT8_C(  19), -INT8_C(  84),
        -INT8_C(  21),  INT8_C(  40), -INT8_C( 104),  INT8_C(  85),  INT8_C(  20), -INT8_C(  82),  INT8_C( 124),  INT8_C( 122),
        -INT8_C( 121),  INT8_C(  83),  INT8_C(  40),  INT8_C(  83),  INT8_C(  36),  INT8_C(  82), -INT8_C( 108),  INT8_C(  40),
        -INT8_C( 119),  INT8_C( 126),  INT8_C(  31),  INT8_C(  85), -INT8_C(  84),  INT8_C(  31), -INT8_C(  14), -INT8_C(  97),
        -INT8_C( 119),  INT8_C( 124),  INT8_C(  17), -INT8_C(  35),  INT8_C(  13), -INT8_C(  57), -INT8_C(  38), -INT8_C(  14),
        -INT8_C( 104), -INT8_C(   1),  INT8_C(  31),  INT8_C( 126),  INT8_C( 126),  INT8_C(  20),  INT8_C(  82),  INT8_C(  13),
         INT8_C(  58), -INT8_C(  80), -INT8_C( 121), -INT8_C(  14),  INT8_C( 124),  INT8_C(  52),  INT8_C(  34),  INT8_C( 124) } },
    { {  INT8_C( 123), -INT8_C(   4), -INT8_C(  98), -INT8_C(  48),  INT8_C( 120), -INT8_C(  78), -INT8_C( 125),  INT8_C(  23),
         INT8_C(  48),  INT8_C(  78), -INT8_C(  17), -INT8_C(  82), -INT8_C(  96), -INT8_C(  13), -INT8_C(  96),  INT8_C(  77),
        -INT8_C( 117), -INT8_C(  78),  INT8_C(  76),  INT8_C(  36), -INT8_C(  99), -INT8_C(  21), -INT8_C( 123), -INT8_C(  79),
        -INT8_C( 103), -INT8_C( 109), -INT8_C( 114), -INT8_C(  33), -INT8_C(  14), -INT8_C(  66),  INT8_C(  90),  INT8_C( 110),
        -INT8_C(  70), -INT8_C(   8),  INT8_C(  62),  INT8_C(  50), -INT8_C(  86), -INT8_C(  62),  INT8_C(  73), -INT8_C(  38),
         INT8_C(  16),  INT8_C(  57), -INT8_C( 119), -INT8_C(  79),  INT8_C(  44),  INT8_C(  41), -INT8_C(   2), -INT8_C(  73),
        -INT8_C(  37),  INT8_C(  74), -INT8_C(  37),  INT8_C( 121),  INT8_C(  54),  INT8_C(  97),  INT8_C(  42), -INT8_C(  49),
        -INT8_C(  12), -INT8_C(  71), -INT8_C(  81), -INT8_C(  26),  INT8_C( 119),  INT8_C(   9),  INT8_C(  84),  INT8_C(  49) },
      {  INT8_C(   1), -INT8_C( 109),  INT8_C(  99), -INT8_C(  84),  INT8_C(  85), -INT8_C(  83), -INT8_C( 122),  INT8_C( 101),
        -INT8_C(  26),  INT8_C(  15),  INT8_C(  22),  INT8_C(  18),  INT8_C(  57),  INT8_C(  20), -INT8_C(  55),  INT8_C(  20),
         INT8_C(  95), -INT8_C(  92), -INT8_C( 115), -INT8_C( 107),  INT8_C(   5), -INT8_C(  72),  INT8_C( 100), -INT8_C(   7),
         INT8_C( 113),  INT8_C(  19), -INT8_C(  32), -INT8_C(  24),  INT8_C(  28),  INT8_C(  52),  INT8_C(  25),  INT8_C(  30),
        -INT8_C(  57),  INT8_C( 124), -INT8_C(  54),  INT8_C(  28),  INT8_C(  41),  INT8_C(  80), -INT8_C( 126),  INT8_C(  15),
         INT8_C(  96), -INT8_C( 104),  INT8_C(  33), -INT8_C( 103), -INT8_C(  83), -INT8_C(  22), -INT8_C(  83),  INT8_C(  12),
        -INT8_C( 113),  INT8_C(  59), -INT8_C(  95), -INT8_C( 108), -INT8_C(  13),  INT8_C(   5), -INT8_C( 114),  INT8_C( 100),
         INT8_C(  25),  INT8_C( 110),  INT8_C(  76),  INT8_C(  53), -INT8_C(  94),  INT8_C( 101),  INT8_C(  83),  INT8_C( 106) },
      {  INT8_C(  53), -INT8_C(  94),  INT8_C(  25),  INT8_C(  95),  INT8_C(  25), -INT8_C(  95), -INT8_C(  84), -INT8_C(   7),
        -INT8_C( 113), -INT8_C(  55),  INT8_C(  12), -INT8_C(  83), -INT8_C(  57), -INT8_C( 108), -INT8_C(  57),  INT8_C(  20),
         INT8_C(  18), -INT8_C(  95),  INT8_C(  57),  INT8_C(  41),  INT8_C(  52), -INT8_C( 103), -INT8_C(  83),  INT8_C(  59),
         INT8_C(  19), -INT8_C( 107), -INT8_C(  55),  INT8_C(  30), -INT8_C(  95),  INT8_C(  83), -INT8_C(  32), -INT8_C(  83),
         INT8_C(  76),  INT8_C(  25),  INT8_C(  83), -INT8_C(  95),  INT8_C(  33),  INT8_C(  99),  INT8_C(  15), -INT8_C(  32),
         INT8_C(  95),  INT8_C( 110),  INT8_C(  15),  INT8_C(  59), -INT8_C(  83), -INT8_C( 104),  INT8_C(  83),  INT8_C( 100),
        -INT8_C(  24),  INT8_C(  22), -INT8_C(  24),  INT8_C( 110), -INT8_C( 114),  INT8_C( 124),  INT8_C(  33),  INT8_C(  20),
        -INT8_C(  13),  INT8_C( 110),  INT8_C(  12), -INT8_C( 126),  INT8_C( 100),  INT8_C(  15),  INT8_C(   5),  INT8_C(  59) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i r = simde_mm512_permutexvar_epi8(idx, a);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_permutexvar_epi8(idx, a);

    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    const int8_t idx[64];
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  31), -INT8_C(  83), -INT8_C(  33), -INT8_C( 110), -INT8_C(  67),  INT8_C(   2), -INT8_C(  29),  INT8_C(   6),
         INT8_C(  42), -INT8_C(   8),      INT8_MIN,  INT8_C(   3),  INT8_C( 107),  INT8_C(  77), -INT8_C(  49), -INT8_C(  47),
        -INT8_C(  17),  INT8_C( 121), -INT8_C( 107),  INT8_C( 106), -INT8_C(  11),  INT8_C(  45),  INT8_C(  39), -INT8_C( 113),
         INT8_C(  27), -INT8_C(  96),  INT8_C(  77), -INT8_C(  91), -INT8_C(  69), -INT8_C(  74), -INT8_C(  12), -INT8_C(  38),
         INT8_C(  99), -INT8_C(  44),  INT8_C( 109),  INT8_C(  32), -INT8_C(  42),  INT8_C(  80),  INT8_C(  39),  INT8_C(   1),
         INT8_C(  72), -INT8_C(  89),  INT8_C(   4), -INT8_C(  77), -INT8_C(  12), -INT8_C(  44), -INT8_C( 124), -INT8_C(  29),
         INT8_C(  77),  INT8_C(  25),  INT8_C(  77),  INT8_C(  66),  INT8_C(  71),  INT8_C( 116), -INT8_C(  47),  INT8_C(  98),
         INT8_C(  20),  INT8_C(  31),  INT8_C(   7), -INT8_C(  49), -INT8_C(  43), -INT8_C(   5), -INT8_C(  86),  INT8_C(  56) },
      UINT64_C(12729284054446839759),
      {  INT8_C(  39), -INT8_C(  85),  INT8_C(  99),  INT8_C(  27),      INT8_MAX, -INT8_C(  24), -INT8_C(   2), -INT8_C(  52),
         INT8_C(   1),  INT8_C(  75),  INT8_C(  14),  INT8_C(  72), -INT8_C(  64), -INT8_C(  32), -INT8_C(  86), -INT8_C(  44),
        -INT8_C(   1), -INT8_C(  79), -INT8_C(  92), -INT8_C(  44), -INT8_C(  83),  INT8_C(  78),  INT8_C(  12),  INT8_C( 124),
         INT8_C( 101),  INT8_C( 101),  INT8_C(  34), -INT8_C(  52), -INT8_C(  27), -INT8_C(  55),  INT8_C( 124),  INT8_C(  12),
         INT8_C( 117), -INT8_C(  32),  INT8_C(  39), -INT8_C(  12), -INT8_C(  56),  INT8_C(  37), -INT8_C(  63), -INT8_C(  55),
         INT8_C( 113), -INT8_C(  49),  INT8_C(  18),  INT8_C(  49), -INT8_C(  81), -INT8_C(  68),  INT8_C(   5), -INT8_C(  82),
         INT8_C( 110), -INT8_C(  87), -INT8_C( 126),  INT8_C(  27), -INT8_C(   9), -INT8_C( 113), -INT8_C( 105),  INT8_C(  92),
        -INT8_C(  12), -INT8_C(  70),  INT8_C(  41), -INT8_C(  38), -INT8_C( 125), -INT8_C(  91), -INT8_C(  26), -INT8_C(   8) },
      { -INT8_C( 123),  INT8_C(  14), -INT8_C(  19),  INT8_C(  77),  INT8_C(  51), -INT8_C(  82),  INT8_C(  23), -INT8_C(  92),
         INT8_C( 125),  INT8_C(  41), -INT8_C(  43),  INT8_C(  45), -INT8_C(  27), -INT8_C(  37), -INT8_C(  37),  INT8_C(  83),
        -INT8_C( 124),  INT8_C(  94),  INT8_C( 110),  INT8_C( 124), -INT8_C(  19),  INT8_C(   6), -INT8_C(  40), -INT8_C(  31),
        -INT8_C(  64),  INT8_C(   1), -INT8_C(  69),  INT8_C(  67), -INT8_C(  89), -INT8_C(  94),  INT8_C(  60),  INT8_C(  44),
        -INT8_C(  80),  INT8_C(  41),  INT8_C( 122), -INT8_C(  29), -INT8_C(  41), -INT8_C( 111), -INT8_C( 120),  INT8_C(  84),
        -INT8_C(  70),  INT8_C(  93), -INT8_C( 127), -INT8_C(  97),  INT8_C(  56),  INT8_C(  93), -INT8_C(  13), -INT8_C(  67),
        -INT8_C(  69),  INT8_C(  97),  INT8_C(  57), -INT8_C(  88),  INT8_C( 103),  INT8_C(  17), -INT8_C( 119),  INT8_C(  39),
         INT8_C(  19),  INT8_C(  69),  INT8_C( 107), -INT8_C(  70), -INT8_C(  25), -INT8_C(  89), -INT8_C(  26), -INT8_C( 105) },
      {  INT8_C(  84), -INT8_C(  97), -INT8_C(  29),  INT8_C(  67), -INT8_C(  67),  INT8_C(   2), -INT8_C(  26), -INT8_C(  27),
         INT8_C(  14),  INT8_C(  45), -INT8_C(  37),  INT8_C(   3), -INT8_C( 123),  INT8_C(  77), -INT8_C(  49), -INT8_C(  47),
        -INT8_C( 105),  INT8_C( 121), -INT8_C( 107), -INT8_C(  19),  INT8_C(  93),  INT8_C(  45), -INT8_C(  27), -INT8_C( 113),
         INT8_C(  27), -INT8_C( 111),  INT8_C( 122), -INT8_C(  91), -INT8_C(  69),  INT8_C(  41), -INT8_C(  12), -INT8_C(  27),
         INT8_C(  17), -INT8_C(  80),  INT8_C(  84),  INT8_C(  32), -INT8_C(  42), -INT8_C( 111),  INT8_C(  14),  INT8_C(   1),
         INT8_C(  72), -INT8_C(  89),  INT8_C(   4), -INT8_C(  77), -INT8_C(  12), -INT8_C(  44), -INT8_C( 124), -INT8_C(  13),
        -INT8_C(  13),  INT8_C(  93), -INT8_C(  19),  INT8_C(  66),  INT8_C(  71),  INT8_C(  83), -INT8_C(  47), -INT8_C(  89),
         INT8_C(  20),  INT8_C(  31),  INT8_C(   7), -INT8_C(  49),  INT8_C(  77), -INT8_C( 111), -INT8_C(  86),  INT8_C(  19) } },
    { { -INT8_C(  48),  INT8_C(  96),  INT8_C( 122), -INT8_C(  89), -INT8_C(  15),  INT8_C(   2), -INT8_C(   5), -INT8_C(  85),
         INT8_C(  96),  INT8_C( 125),  INT8_C(  75), -INT8_C( 104), -INT8_C(  38),  INT8_C(  62),  INT8_C(  85), -INT8_C( 107),
        -INT8_C(  97), -INT8_C( 114),  INT8_C(  61),  INT8_C(   7), -INT8_C(  96), -INT8_C(  58),  INT8_C(  46), -INT8_C(  77),
         INT8_C(  11), -INT8_C( 103),  INT8_C( 109), -INT8_C(  14),  INT8_C(  64),  INT8_C(  83), -INT8_C( 119),  INT8_C(  16),
        -INT8_C(  76),  INT8_C(   4), -INT8_C(  73), -INT8_C(  91),  INT8_C(   6), -INT8_C(  77),  INT8_C(  81),  INT8_C( 102),
         INT8_C(  48), -INT8_C( 100), -INT8_C(   1),  INT8_C(  10), -INT8_C(  38),  INT8_C(  84), -INT8_C(  97),  INT8_C( 121),
        -INT8_C(  29), -INT8_C(  36),      INT8_MIN, -INT8_C( 125), -INT8_C(  94), -INT8_C(  81),  INT8_C(  54), -INT8_C(  82),
         INT8_C(  72), -INT8_C(  93), -INT8_C(  96), -INT8_C( 119), -INT8_C(  10),  INT8_C(  42), -INT8_C( 103), -INT8_C(  86) },
      UINT64_C( 3790800550792024366),
      {  INT8_C(  61), -INT8_C( 102),  INT8_C(  62),  INT8_C(  23), -INT8_C(  18), -INT8_C(  35), -INT8_C( 112), -INT8_C(  47),
        -INT8_C(  71),  INT8_C(  17),  INT8_C(  84),  INT8_C(  91), -INT8_C(  64), -INT8_C( 118),  INT8_C(   9),  INT8_C(   8),
         INT8_C(  45), -INT8_C(  86), -INT8_C( 111),  INT8_C(  36), -INT8_C(  44),  INT8_C(  43), -INT8_C(  50),  INT8_C(   2),
         INT8_C( 124),  INT8_C(  30),  INT8_C(  54),      INT8_MIN, -INT8_C(  65), -INT8_C(  47), -INT8_C(  76), -INT8_C(   4),
         INT8_C( 107), -INT8_C(  14),  INT8_C(  19),  INT8_C(  90), -INT8_C(  49), -INT8_C(  92),  INT8_C(  43), -INT8_C( 120),
        -INT8_C(  75),      INT8_MIN, -INT8_C(  29),  INT8_C( 117),  INT8_C(  10), -INT8_C(  19),  INT8_C( 125),  INT8_C(  56),
        -INT8_C( 105),  INT8_C(  15),  INT8_C(  92),  INT8_C( 107),  INT8_C(  58),  INT8_C(  42),  INT8_C( 109), -INT8_C(  74),
         INT8_C(  73), -INT8_C(  93),  INT8_C(  54),  INT8_C(   8),  INT8_C( 117), -INT8_C(  22),  INT8_C(   5), -INT8_C(  32) },
      { -INT8_C(  36),  INT8_C(  24),  INT8_C(  58), -INT8_C(  85), -INT8_C(  68),  INT8_C( 102),  INT8_C(  51),  INT8_C( 113),
        -INT8_C(  26),  INT8_C(  22), -INT8_C(  26), -INT8_C(  16),  INT8_C(   3),  INT8_C( 100),  INT8_C(  40), -INT8_C( 102),
         INT8_C( 115), -INT8_C( 124),  INT8_C(   5), -INT8_C(  83), -INT8_C(  81),  INT8_C( 114),  INT8_C(  99), -INT8_C(   8),
         INT8_C(  22), -INT8_C( 103),  INT8_C(   0), -INT8_C( 117), -INT8_C( 125),  INT8_C(   5),  INT8_C( 107),  INT8_C(  95),
         INT8_C(  30), -INT8_C(  90),  INT8_C(  10), -INT8_C(  38),  INT8_C(  12),  INT8_C(  61),  INT8_C(  76), -INT8_C(  14),
         INT8_C(  83),  INT8_C(  50), -INT8_C(  30),  INT8_C(  87), -INT8_C( 106),  INT8_C(  11), -INT8_C(  15),  INT8_C(   9),
        -INT8_C( 113), -INT8_C(   9), -INT8_C(  74),  INT8_C(  62),  INT8_C( 105),  INT8_C(  25),  INT8_C(  54),      INT8_MAX,
        -INT8_C(  78),  INT8_C(  55),  INT8_C(  10),  INT8_C(  53),  INT8_C(  60),  INT8_C( 118), -INT8_C( 108),  INT8_C(  90) },
      { -INT8_C(  48),  INT8_C(   0), -INT8_C( 108), -INT8_C(   8), -INT8_C(  15),  INT8_C(   5), -INT8_C(   5), -INT8_C(  85),
         INT8_C(  55),  INT8_C( 125),  INT8_C(  75), -INT8_C( 104), -INT8_C(  36),  INT8_C(  62),  INT8_C(  22), -INT8_C( 107),
        -INT8_C(  97), -INT8_C( 114),  INT8_C(  61),  INT8_C(   7), -INT8_C(  81), -INT8_C(  58),  INT8_C(  40), -INT8_C(  77),
         INT8_C(  11), -INT8_C( 103),  INT8_C(  54), -INT8_C(  14),  INT8_C(  90), -INT8_C( 124), -INT8_C( 119),  INT8_C(  16),
        -INT8_C(  76),  INT8_C(   4), -INT8_C(  83), -INT8_C(  91),  INT8_C(   6), -INT8_C(  77),  INT8_C(  81),  INT8_C( 102),
         INT8_C(  25), -INT8_C( 100), -INT8_C(   1),  INT8_C(  10), -INT8_C(  38),  INT8_C(  11), -INT8_C(  97), -INT8_C(  78),
        -INT8_C(   8), -INT8_C( 102),      INT8_MIN,  INT8_C(  87),  INT8_C(  10), -INT8_C(  81),  INT8_C(  54),  INT8_C(  54),
         INT8_C(  72), -INT8_C(  93),  INT8_C(  54), -INT8_C( 119),  INT8_C(  25), -INT8_C(  30), -INT8_C( 103), -INT8_C(  86) } },
    { {  INT8_C(  28), -INT8_C(  98),  INT8_C(  53),  INT8_C(  40), -INT8_C(  37), -INT8_C( 127),  INT8_C(  26),  INT8_C(  47),
        -INT8_C(  77), -INT8_C(   4), -INT8_C( 122),  INT8_C(  74),  INT8_C(   7),  INT8_C( 119),  INT8_C(  83), -INT8_C( 105),
         INT8_C( 110),  INT8_C(  10), -INT8_C(  43), -INT8_C(  40),  INT8_C(  35),  INT8_C(  12),  INT8_C(  87), -INT8_C(  42),
         INT8_C(  67),  INT8_C(  98),  INT8_C(  11),      INT8_MAX, -INT8_C(  40), -INT8_C(  96), -INT8_C(  38), -INT8_C(  12),
         INT8_C(  62),  INT8_C(  15),  INT8_C(  28),  INT8_C(  26), -INT8_C( 112),  INT8_C(  54),  INT8_C(  73),  INT8_C(  67),
         INT8_C(  50), -INT8_C(  49), -INT8_C( 115),  INT8_C(  58),  INT8_C(  70), -INT8_C(  31), -INT8_C(  47), -INT8_C(  75),
        -INT8_C(  21), -INT8_C(  90), -INT8_C( 115),  INT8_C(  14), -INT8_C(  78), -INT8_C(  28), -INT8_C(  28), -INT8_C(  11),
         INT8_C(  70), -INT8_C(  16),  INT8_C( 117),  INT8_C(  30), -INT8_C( 112),  INT8_C(  79),  INT8_C(  18), -INT8_C(  50) },
      UINT64_C(10894543283160624734),
      {  INT8_C(   0), -INT8_C(  65), -INT8_C(  47),  INT8_C(  71), -INT8_C(  96), -INT8_C(  94), -INT8_C(   4), -INT8_C( 117),
         INT8_C(  72), -INT8_C( 119), -INT8_C( 103), -INT8_C(   5),  INT8_C( 109),  INT8_C( 126), -INT8_C(  16), -INT8_C(  76),
         INT8_C( 110),  INT8_C( 101), -INT8_C(  46), -INT8_C(   2), -INT8_C(  76), -INT8_C(  27), -INT8_C(  52),  INT8_C(  18),
         INT8_C(  19), -INT8_C(  75),  INT8_C(   0),  INT8_C( 120), -INT8_C(  26),  INT8_C(  50),  INT8_C(  15), -INT8_C(  25),
        -INT8_C(  15), -INT8_C(  32),  INT8_C(  46), -INT8_C( 111), -INT8_C( 126),  INT8_C(  42),  INT8_C(  28), -INT8_C(  54),
        -INT8_C(  77), -INT8_C(  75), -INT8_C(  59),  INT8_C(  32),  INT8_C(  51), -INT8_C(  74), -INT8_C(  44), -INT8_C(  95),
         INT8_C(  27), -INT8_C(  89), -INT8_C(  97), -INT8_C(  48), -INT8_C( 116),  INT8_C( 108), -INT8_C(  30), -INT8_C(  97),
         INT8_C(  33), -INT8_C(  29),  INT8_C(  23),  INT8_C(   7),  INT8_C(  21),  INT8_C(  38), -INT8_C(  18),  INT8_C(   6) },
      {  INT8_C(   6),  INT8_C(  28), -INT8_C( 105), -INT8_C( 120),  INT8_C(  70), -INT8_C(  77),  INT8_C(  83), -INT8_C(   7),
         INT8_C( 104),  INT8_C(  24),  INT8_C(  26), -INT8_C( 100), -INT8_C(  50), -INT8_C(  18),  INT8_C(  61), -INT8_C(  22),
        -INT8_C( 107), -INT8_C(  35), -INT8_C(  70),  INT8_C(  33),  INT8_C(  73), -INT8_C( 100), -INT8_C(  63),  INT8_C( 106),
             INT8_MAX, -INT8_C(  40),  INT8_C( 113), -INT8_C( 108), -INT8_C(   1),  INT8_C(  96), -INT8_C( 102),  INT8_C(   5),
         INT8_C( 124),  INT8_C(  49), -INT8_C( 114), -INT8_C(  61), -INT8_C(  28), -INT8_C(  31), -INT8_C(  68),  INT8_C(  77),
        -INT8_C(   7), -INT8_C(  42), -INT8_C(  23), -INT8_C(  56), -INT8_C(  59),  INT8_C(  38), -INT8_C(  78),  INT8_C(  90),
         INT8_C(   3),  INT8_C( 108),  INT8_C( 124),  INT8_C(  76),  INT8_C(   8),  INT8_C(  61), -INT8_C(  74), -INT8_C( 120),
         INT8_C(  21),  INT8_C(  40),  INT8_C(  28),  INT8_C(  20), -INT8_C( 120), -INT8_C(  73),  INT8_C(  26),  INT8_C(   4) },
      {  INT8_C(  28),  INT8_C(   4), -INT8_C(  35), -INT8_C(   7),  INT8_C( 124), -INT8_C( 127), -INT8_C( 120),  INT8_C(  47),
        -INT8_C(  77),  INT8_C(  24), -INT8_C(  40),  INT8_C(  20),  INT8_C(   7),  INT8_C(  26),  INT8_C(  83), -INT8_C( 105),
         INT8_C( 110),  INT8_C(  10), -INT8_C(  43),  INT8_C(  26),  INT8_C(  35), -INT8_C(  31), -INT8_C(  50), -INT8_C(  70),
         INT8_C(  67),  INT8_C(  61),  INT8_C(   6),  INT8_C(  21), -INT8_C(  40),  INT8_C( 124), -INT8_C(  22),  INT8_C(  77),
         INT8_C(  62),  INT8_C(  15), -INT8_C(  78),  INT8_C(  26), -INT8_C( 112), -INT8_C(  23), -INT8_C(   1),  INT8_C(  67),
         INT8_C(  76), -INT8_C(  49), -INT8_C( 115),  INT8_C(  58),  INT8_C(  76), -INT8_C(  74), -INT8_C(  47), -INT8_C(  75),
        -INT8_C( 108), -INT8_C(  90), -INT8_C( 115),  INT8_C(  14), -INT8_C(  50), -INT8_C(  59), -INT8_C(  28), -INT8_C(  11),
         INT8_C(  49), -INT8_C(  61),  INT8_C( 106),  INT8_C(  30), -INT8_C( 100),  INT8_C(  79),  INT8_C(  18),  INT8_C(  83) } },
    { { -INT8_C(  24), -INT8_C(  88), -INT8_C(  57), -INT8_C(  51), -INT8_C( 119), -INT8_C( 124),  INT8_C(  26), -INT8_C( 126),
         INT8_C(  90),  INT8_C(   3),  INT8_C(  74),  INT8_C(  31),  INT8_C(  41), -INT8_C(   4),  INT8_C( 122),  INT8_C(  45),
         INT8_C( 104), -INT8_C(  10),  INT8_C( 121),  INT8_C( 113),  INT8_C(  51),  INT8_C(  48), -INT8_C(   7),  INT8_C(  72),
         INT8_C(  88),  INT8_C(  21),  INT8_C(  93), -INT8_C(  32), -INT8_C(  52),  INT8_C( 119), -INT8_C(  28), -INT8_C(  75),
         INT8_C(  31), -INT8_C(  84), -INT8_C( 126), -INT8_C(  88),  INT8_C(  48), -INT8_C( 100),  INT8_C(  42), -INT8_C( 118),
        -INT8_C(  97),  INT8_C( 117), -INT8_C(  86), -INT8_C(  56),  INT8_C( 113),  INT8_C(  36), -INT8_C(  11), -INT8_C(  38),
         INT8_C(  26),  INT8_C( 111),  INT8_C(  75),  INT8_C(  77), -INT8_C(  97),  INT8_C(  68), -INT8_C( 107), -INT8_C(   9),
         INT8_C(  89), -INT8_C(  14), -INT8_C(  41),  INT8_C(  38),  INT8_C( 105), -INT8_C(  69), -INT8_C(  37), -INT8_C( 120) },
      UINT64_C(10962425570514722151),
      { -INT8_C(  48), -INT8_C(  52),  INT8_C(  96),  INT8_C(  65), -INT8_C(  16),  INT8_C(  86),  INT8_C(  27),  INT8_C(  10),
        -INT8_C(  59),  INT8_C( 102),  INT8_C(  87),  INT8_C( 100), -INT8_C(  86), -INT8_C(  20),  INT8_C(  91),  INT8_C(   4),
        -INT8_C(  33),  INT8_C(  50),  INT8_C(  42),  INT8_C(  72), -INT8_C(  19),  INT8_C(   5), -INT8_C(  47),  INT8_C(  85),
         INT8_C(  98),  INT8_C(   1), -INT8_C(  20),  INT8_C(  91),  INT8_C(  92),  INT8_C(  14), -INT8_C(  13),  INT8_C(  44),
        -INT8_C(  38),  INT8_C(  83),  INT8_C( 110), -INT8_C(  54), -INT8_C(  87), -INT8_C( 119), -INT8_C(  44),  INT8_C( 110),
        -INT8_C(  16),  INT8_C(  43), -INT8_C(  46), -INT8_C( 102),  INT8_C(  24),  INT8_C(  45), -INT8_C(  98), -INT8_C(   9),
         INT8_C(  95), -INT8_C(  56),  INT8_C(  63),  INT8_C(  77), -INT8_C(  51),  INT8_C(  16), -INT8_C(  94),  INT8_C(  47),
         INT8_C(  18), -INT8_C( 114), -INT8_C( 118),  INT8_C( 110), -INT8_C(  99),  INT8_C( 125), -INT8_C( 101),  INT8_C( 119) },
      { -INT8_C(  47),  INT8_C(   9),  INT8_C(  66),  INT8_C( 122), -INT8_C( 110),  INT8_C(  22), -INT8_C(  23), -INT8_C( 126),
         INT8_C(  66), -INT8_C(  69),  INT8_C(  29),  INT8_C(  90), -INT8_C(  23), -INT8_C(  69),  INT8_C(  81),  INT8_C(  72),
        -INT8_C( 124), -INT8_C( 112), -INT8_C( 107),  INT8_C(  81), -INT8_C(  95),  INT8_C(  55), -INT8_C( 127), -INT8_C(  77),
        -INT8_C(  58),  INT8_C(  11),  INT8_C(  33),  INT8_C(  99), -INT8_C( 119), -INT8_C(  68), -INT8_C(  38),  INT8_C(  90),
        -INT8_C(  59),  INT8_C(  28), -INT8_C(  44),  INT8_C(  88),  INT8_C(  51), -INT8_C(  67), -INT8_C(  38),  INT8_C( 117),
         INT8_C( 121), -INT8_C(   9), -INT8_C(  49),  INT8_C(  98), -INT8_C(  77),  INT8_C(  32), -INT8_C(  86),  INT8_C(  55),
        -INT8_C(  80),  INT8_C(  64), -INT8_C( 120),  INT8_C(  81),  INT8_C( 119),  INT8_C(   9),  INT8_C(   4),  INT8_C(  61),
         INT8_C(  21),  INT8_C(  38), -INT8_C(  96), -INT8_C(  98), -INT8_C(  30),  INT8_C( 123), -INT8_C(   8), -INT8_C(  88) },
      { -INT8_C( 124), -INT8_C(  23), -INT8_C(  59), -INT8_C(  51), -INT8_C( 119), -INT8_C( 127),  INT8_C(  99), -INT8_C( 126),
         INT8_C(  22),  INT8_C(   3), -INT8_C(  77),  INT8_C(  51), -INT8_C(  49), -INT8_C(   4),  INT8_C(  99),  INT8_C(  45),
         INT8_C( 104), -INT8_C(  10),  INT8_C( 121),  INT8_C( 113),  INT8_C(  32),  INT8_C(  22), -INT8_C(   7),  INT8_C(  72),
        -INT8_C(  44),  INT8_C(   9), -INT8_C(  77), -INT8_C(  32), -INT8_C( 119),  INT8_C( 119), -INT8_C(  28), -INT8_C(  77),
         INT8_C(  33), -INT8_C(  84), -INT8_C( 126),  INT8_C(  29), -INT8_C(   9), -INT8_C(  69), -INT8_C(  95), -INT8_C(  86),
        -INT8_C(  80),  INT8_C(  98), -INT8_C(  86),  INT8_C(  33), -INT8_C(  58),  INT8_C(  36), -INT8_C(  38), -INT8_C(  38),
         INT8_C(  26),  INT8_C(  66),  INT8_C(  75),  INT8_C(  77), -INT8_C(  97), -INT8_C( 124), -INT8_C( 107), -INT8_C(   9),
         INT8_C(  89), -INT8_C(  14), -INT8_C(  41), -INT8_C(  86), -INT8_C(  68), -INT8_C(  69), -INT8_C(  37),  INT8_C(  61) } },
    { { -INT8_C( 105), -INT8_C(  52),  INT8_C(   0), -INT8_C(  54), -INT8_C( 118), -INT8_C(  38),  INT8_C(  63),  INT8_C(   3),
        -INT8_C(  46),  INT8_C(  14),  INT8_C( 101), -INT8_C( 123),  INT8_C(  46),  INT8_C(  15), -INT8_C(  68), -INT8_C(  33),
         INT8_C(  79),  INT8_C(  68),  INT8_C(  48), -INT8_C(  57),  INT8_C(  78),  INT8_C(  53),  INT8_C(   4),  INT8_C(  99),
         INT8_C(  91), -INT8_C(  91),  INT8_C(   1),  INT8_C(  61),  INT8_C(  32), -INT8_C(   7), -INT8_C(  27), -INT8_C(  73),
        -INT8_C(  59), -INT8_C(  27), -INT8_C( 126),  INT8_C(  79), -INT8_C(  64), -INT8_C(  63),  INT8_C(  82), -INT8_C( 110),
        -INT8_C(  48), -INT8_C(  73),  INT8_C(  23), -INT8_C(   2), -INT8_C(  57), -INT8_C(  45), -INT8_C(  35),  INT8_C(  22),
         INT8_C(  23),  INT8_C(  14), -INT8_C(  35),  INT8_C( 101),  INT8_C(  67), -INT8_C(  30), -INT8_C(  56), -INT8_C(  98),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(  37), -INT8_C(  89), -INT8_C(  62), -INT8_C(  63),  INT8_C(  94), -INT8_C( 120) },
      UINT64_C( 8284418391546519718),
      { -INT8_C(  31),  INT8_C(  15),  INT8_C( 112), -INT8_C(  88), -INT8_C(  30),  INT8_C(  78), -INT8_C(  65), -INT8_C(   6),
         INT8_C(  92), -INT8_C( 100),  INT8_C(  95), -INT8_C(  97),  INT8_C( 126),  INT8_C(  40),  INT8_C(  61),  INT8_C(   5),
        -INT8_C(  15),  INT8_C(  24), -INT8_C(  84), -INT8_C(  76), -INT8_C(  39),  INT8_C(  11),  INT8_C(  60),      INT8_MIN,
        -INT8_C(  21),  INT8_C(  19), -INT8_C(  26), -INT8_C( 115),  INT8_C(  61), -INT8_C(  33), -INT8_C(   1),  INT8_C(  31),
        -INT8_C(  18),  INT8_C( 112), -INT8_C(  57), -INT8_C(  47), -INT8_C(  66), -INT8_C( 122), -INT8_C(  53),  INT8_C(  26),
         INT8_C(  35),  INT8_C(  42), -INT8_C(  71), -INT8_C(  95),  INT8_C(  82), -INT8_C(  10), -INT8_C(  89),  INT8_C(  68),
         INT8_C(  14),  INT8_C(  83), -INT8_C(   8), -INT8_C(  24),  INT8_C(  94),  INT8_C(  52),  INT8_C( 104),  INT8_C(  74),
         INT8_C(  71),  INT8_C(  78), -INT8_C(  41), -INT8_C( 123),  INT8_C(  45), -INT8_C(  41), -INT8_C(  92),  INT8_C(  28) },
      {  INT8_C(  71),  INT8_C( 107), -INT8_C(  19),  INT8_C(   5), -INT8_C(  14), -INT8_C(  72),  INT8_C(  31),  INT8_C(  21),
        -INT8_C(  30), -INT8_C(  40), -INT8_C(  74),  INT8_C(  53), -INT8_C(  50),  INT8_C(  93),  INT8_C( 121), -INT8_C(  36),
        -INT8_C(  79),  INT8_C( 113), -INT8_C(  60),  INT8_C(  15), -INT8_C(  91),  INT8_C(  44),  INT8_C(  89), -INT8_C(  20),
         INT8_C( 123),  INT8_C(  49),  INT8_C( 113), -INT8_C(  88),  INT8_C(   8),  INT8_C(  21), -INT8_C(  60),  INT8_C(  79),
        -INT8_C( 127), -INT8_C(  79),  INT8_C(  84),  INT8_C( 115),  INT8_C( 105),  INT8_C( 115), -INT8_C( 120),  INT8_C(  76),
         INT8_C(  75),  INT8_C(  62), -INT8_C( 127),  INT8_C(  25), -INT8_C( 100), -INT8_C(   6), -INT8_C(  11),  INT8_C(  77),
         INT8_C( 107), -INT8_C(  70),  INT8_C(  92),  INT8_C(  16), -INT8_C(  26), -INT8_C(  74), -INT8_C(   4),  INT8_C(  97),
        -INT8_C(  25),  INT8_C( 110),  INT8_C(  10), -INT8_C(  17), -INT8_C( 125), -INT8_C(  50),  INT8_C(  62),  INT8_C(   4) },
      { -INT8_C( 105), -INT8_C(  36),  INT8_C( 107), -INT8_C(  54), -INT8_C( 118),  INT8_C( 121),  INT8_C(  63),  INT8_C(  10),
        -INT8_C(  46),  INT8_C(  14),  INT8_C( 101), -INT8_C( 123),  INT8_C(  46),  INT8_C(  75), -INT8_C(  50), -INT8_C(  72),
        -INT8_C(  70),  INT8_C( 123), -INT8_C( 100), -INT8_C(  57),  INT8_C(  49),  INT8_C(  53), -INT8_C( 125),  INT8_C(  71),
         INT8_C(  91),  INT8_C(  15), -INT8_C( 120),  INT8_C(  61),  INT8_C(  32),  INT8_C(  79),  INT8_C(   4), -INT8_C(  73),
        -INT8_C(  59),  INT8_C( 107), -INT8_C( 126),  INT8_C(  79), -INT8_C(  64),  INT8_C(  31),  INT8_C(  82),  INT8_C( 113),
        -INT8_C(  48), -INT8_C( 127),  INT8_C(  23), -INT8_C(  79), -INT8_C(  57), -INT8_C(   4), -INT8_C(  35),  INT8_C(  22),
         INT8_C(  23),  INT8_C(  14), -INT8_C(  35),  INT8_C(  75), -INT8_C(  60), -INT8_C(  26),  INT8_C(  75), -INT8_C(  74),
        -INT8_C( 121),  INT8_C( 121), -INT8_C(  37), -INT8_C(  89), -INT8_C(   6), -INT8_C(  20),  INT8_C( 105), -INT8_C( 120) } },
    { {      INT8_MIN, -INT8_C( 110),  INT8_C( 119), -INT8_C(  23),  INT8_C(   5), -INT8_C(   1),  INT8_C(  53),  INT8_C(  80),
         INT8_C(  62), -INT8_C(  74),  INT8_C( 105), -INT8_C(  38), -INT8_C(  80),  INT8_C(  94),  INT8_C(  39),  INT8_C(  27),
         INT8_C(  24), -INT8_C( 125),  INT8_C(  43), -INT8_C(   1),  INT8_C(  57),  INT8_C(  40),  INT8_C(  96),  INT8_C(  32),
        -INT8_C( 106),  INT8_C( 106),  INT8_C(  15),  INT8_C(  25),  INT8_C(  57),  INT8_C(  77),  INT8_C(  30), -INT8_C(  71),
        -INT8_C(  33), -INT8_C( 107), -INT8_C(  94), -INT8_C(  28), -INT8_C( 107), -INT8_C(  40),  INT8_C(  52), -INT8_C(  45),
        -INT8_C( 114), -INT8_C(  99), -INT8_C(  83),  INT8_C(  63), -INT8_C(   4), -INT8_C(  44),  INT8_C(  90),  INT8_C(  20),
         INT8_C(  87), -INT8_C( 122),  INT8_C(  19), -INT8_C( 111), -INT8_C(  82),  INT8_C( 116), -INT8_C(  79),  INT8_C(  68),
        -INT8_C(  34), -INT8_C(  63),  INT8_C(  93),  INT8_C(  23),  INT8_C(  14),  INT8_C( 123), -INT8_C(  48), -INT8_C(  18) },
      UINT64_C(15670564399915102993),
      { -INT8_C(  92),  INT8_C(  38),  INT8_C(  24), -INT8_C(  96), -INT8_C(   6),  INT8_C( 115), -INT8_C(  75),  INT8_C(  81),
        -INT8_C(   7), -INT8_C(  56), -INT8_C(  30), -INT8_C(  89),  INT8_C(  60), -INT8_C( 108), -INT8_C(  21),  INT8_C(  27),
         INT8_C(  85),  INT8_C(  72),  INT8_C(  50),  INT8_C(  99), -INT8_C(  60),  INT8_C(   3),  INT8_C(  81), -INT8_C(  43),
         INT8_C( 118),  INT8_C(  36),  INT8_C( 123), -INT8_C(  63),  INT8_C(  43), -INT8_C(  12), -INT8_C( 102), -INT8_C(  49),
         INT8_C(  26), -INT8_C(  77),  INT8_C( 112),  INT8_C(  20),  INT8_C(  38),  INT8_C(  37),  INT8_C( 101),  INT8_C(  31),
        -INT8_C(  19),  INT8_C(  72), -INT8_C(  58),  INT8_C(  42), -INT8_C(  36), -INT8_C(  79),  INT8_C(  69),  INT8_C(  49),
        -INT8_C(   7),  INT8_C( 119), -INT8_C( 108), -INT8_C(  67),  INT8_C( 122), -INT8_C(  26), -INT8_C( 110), -INT8_C(  16),
         INT8_C(  10),  INT8_C(  13), -INT8_C(  79),  INT8_C(  53),  INT8_C(   1),  INT8_C(  76),  INT8_C(   4),  INT8_C(  27) },
      { -INT8_C(   1),  INT8_C( 116),  INT8_C(  47),  INT8_C(  37), -INT8_C( 103), -INT8_C( 107),  INT8_C(  68), -INT8_C( 121),
        -INT8_C(  35),  INT8_C(  10), -INT8_C(  79), -INT8_C(  71), -INT8_C(  69), -INT8_C(  10), -INT8_C(  22), -INT8_C(  76),
         INT8_C( 109),  INT8_C( 126),  INT8_C( 114), -INT8_C(  24),  INT8_C( 100),  INT8_C(   4), -INT8_C(  40),  INT8_C( 110),
         INT8_C(  18), -INT8_C( 118), -INT8_C(  93),  INT8_C(  19), -INT8_C(  42), -INT8_C(  88),  INT8_C(  47), -INT8_C(  43),
         INT8_C(  28),  INT8_C(  94), -INT8_C(   6), -INT8_C(  74), -INT8_C(  13),  INT8_C(  62),  INT8_C(  61), -INT8_C(  48),
         INT8_C(  72), -INT8_C(  18), -INT8_C( 119),  INT8_C(   3), -INT8_C(  28),  INT8_C( 115), -INT8_C(  73),  INT8_C(  81),
        -INT8_C(  14),  INT8_C(  41),  INT8_C(  57),  INT8_C(  86),  INT8_C(  46),  INT8_C(  18), -INT8_C(  59),  INT8_C(  64),
        -INT8_C( 100),  INT8_C( 104),  INT8_C(  83),  INT8_C( 114),  INT8_C(  16), -INT8_C( 126),  INT8_C(  71),  INT8_C(  45) },
      { -INT8_C(  13), -INT8_C( 110),  INT8_C( 119), -INT8_C(  23),  INT8_C(  83), -INT8_C(   1),  INT8_C(  53),  INT8_C(  80),
         INT8_C( 104), -INT8_C(  35),  INT8_C( 105), -INT8_C(  38),  INT8_C(  16),  INT8_C( 100),  INT8_C(   3),  INT8_C(  27),
         INT8_C(  24), -INT8_C(  35),  INT8_C(  43), -INT8_C(   1), -INT8_C( 103),  INT8_C(  40),  INT8_C( 126),  INT8_C(   4),
        -INT8_C( 106), -INT8_C(  13),  INT8_C( 114),  INT8_C(  25),  INT8_C(  57),  INT8_C(  46),  INT8_C(  30), -INT8_C(  76),
        -INT8_C(  93),  INT8_C(  86), -INT8_C(  94),  INT8_C( 100), -INT8_C( 107), -INT8_C(  40),  INT8_C(  62), -INT8_C(  45),
         INT8_C( 115), -INT8_C(  35),  INT8_C(  68),  INT8_C(  63), -INT8_C(   4), -INT8_C(  44),  INT8_C(  90),  INT8_C(  20),
         INT8_C( 104), -INT8_C( 122),  INT8_C(  19), -INT8_C( 126),  INT8_C(  83),  INT8_C(  61),  INT8_C( 114),  INT8_C(  68),
        -INT8_C(  79), -INT8_C(  63),  INT8_C(  93),  INT8_C(  18),  INT8_C( 116),  INT8_C( 123), -INT8_C( 103),  INT8_C(  19) } },
    { { -INT8_C(  31),  INT8_C(  65), -INT8_C(  29), -INT8_C(  44),      INT8_MAX,  INT8_C(  32), -INT8_C(  91), -INT8_C(  57),
         INT8_C(  14),  INT8_C(  46), -INT8_C(  54), -INT8_C(  14), -INT8_C(  94), -INT8_C( 127),  INT8_C(  67), -INT8_C( 108),
        -INT8_C(  85),  INT8_C( 125), -INT8_C(  22), -INT8_C(  39), -INT8_C( 113), -INT8_C(  81),  INT8_C(  25),  INT8_C(  43),
         INT8_C(  24),  INT8_C( 108), -INT8_C(  99),  INT8_C(  40), -INT8_C(  17), -INT8_C(  28),  INT8_C(  85), -INT8_C(  48),
         INT8_C(  37),  INT8_C(  56), -INT8_C(  92), -INT8_C(  92),  INT8_C(  88),  INT8_C(  73),  INT8_C( 107),  INT8_C( 102),
         INT8_C( 120),  INT8_C(  53),  INT8_C(  88),  INT8_C(  26), -INT8_C(  74), -INT8_C( 100), -INT8_C(  82),  INT8_C(  97),
         INT8_C(  25), -INT8_C( 104),  INT8_C(  58), -INT8_C(  88),  INT8_C(  72),  INT8_C(  83), -INT8_C(  45),  INT8_C(  96),
        -INT8_C(  64),  INT8_C( 112), -INT8_C( 120), -INT8_C(  81),  INT8_C(  84), -INT8_C(  34),      INT8_MAX,  INT8_C( 121) },
      UINT64_C(16561293208321860374),
      { -INT8_C(  67),  INT8_C(  46), -INT8_C(   1),  INT8_C( 115), -INT8_C(  54), -INT8_C(  83), -INT8_C(  43), -INT8_C(  29),
         INT8_C(  69),  INT8_C(  15), -INT8_C( 117), -INT8_C( 115),  INT8_C(  99),  INT8_C(  94), -INT8_C(  19),  INT8_C(  35),
        -INT8_C(  50),  INT8_C( 118), -INT8_C(  46),  INT8_C(  34),  INT8_C(  84),  INT8_C(  81), -INT8_C( 101),  INT8_C( 106),
         INT8_C( 116), -INT8_C(  72), -INT8_C(  39), -INT8_C(  31),  INT8_C(  64), -INT8_C(  81), -INT8_C(  58), -INT8_C(   3),
        -INT8_C(  35), -INT8_C(  59),  INT8_C( 112), -INT8_C(  89),  INT8_C( 114),  INT8_C(  69), -INT8_C( 118), -INT8_C(  72),
         INT8_C(  85),  INT8_C(  21),  INT8_C(  69), -INT8_C(  72),  INT8_C( 115),  INT8_C(  51), -INT8_C(  37),  INT8_C(  65),
        -INT8_C(  87), -INT8_C(  83),  INT8_C(  99), -INT8_C(   3), -INT8_C(   2), -INT8_C(   2),  INT8_C( 103),  INT8_C( 114),
        -INT8_C(  74),  INT8_C(  65),  INT8_C(  84), -INT8_C(  10), -INT8_C(  16),  INT8_C(  26), -INT8_C(  13), -INT8_C(  51) },
      { -INT8_C(  32),  INT8_C(  99),  INT8_C( 116),  INT8_C(  82), -INT8_C(  87), -INT8_C(   2),  INT8_C(  10), -INT8_C(   2),
         INT8_C(  19),  INT8_C(  80), -INT8_C(  74), -INT8_C( 122), -INT8_C( 125), -INT8_C( 111), -INT8_C(  57),  INT8_C(  44),
         INT8_C(  62),  INT8_C(  42),  INT8_C(  41),  INT8_C(  60),  INT8_C(  40), -INT8_C( 112), -INT8_C(  82), -INT8_C(  34),
        -INT8_C(  47),  INT8_C(   2), -INT8_C(  44), -INT8_C(  63),  INT8_C(  29), -INT8_C(  57), -INT8_C( 114), -INT8_C(   3),
         INT8_C(  42),  INT8_C(   2),  INT8_C(  79), -INT8_C(  45),  INT8_C(   0),  INT8_C(  90), -INT8_C(  47),  INT8_C(  19),
        -INT8_C(  86), -INT8_C( 121), -INT8_C( 103),  INT8_C(  45),  INT8_C(  24),  INT8_C(  96),  INT8_C(  89),  INT8_C(  86),
        -INT8_C( 118), -INT8_C( 126), -INT8_C( 110), -INT8_C(  78),  INT8_C(  18),  INT8_C(  65), -INT8_C( 112), -INT8_C(  28),
         INT8_C(  67),  INT8_C( 100), -INT8_C(  91),  INT8_C(  96),  INT8_C(  43),  INT8_C(  52),  INT8_C(  93),  INT8_C(  86) },
      { -INT8_C(  31),  INT8_C(  89),  INT8_C(  86), -INT8_C(  44), -INT8_C(  74),  INT8_C(  32), -INT8_C(  91), -INT8_C(  57),
        -INT8_C(   2),  INT8_C(  44), -INT8_C(  54), -INT8_C(  14), -INT8_C(  94), -INT8_C( 114),  INT8_C(  67), -INT8_C( 108),
        -INT8_C(  57),  INT8_C( 125),  INT8_C(  41),  INT8_C(  79),  INT8_C(  40), -INT8_C(  81),  INT8_C(  25),  INT8_C(  43),
         INT8_C(  18),  INT8_C(  67),  INT8_C(   2),  INT8_C(   2), -INT8_C(  17),  INT8_C(  86),  INT8_C(  10), -INT8_C(  48),
        -INT8_C(  57),  INT8_C(  56), -INT8_C( 118),  INT8_C(  19),  INT8_C(  88), -INT8_C(   2), -INT8_C(  74),  INT8_C( 102),
         INT8_C( 120),  INT8_C(  53),  INT8_C(  88),  INT8_C(  67), -INT8_C(  74), -INT8_C( 100), -INT8_C(  82),  INT8_C(  99),
        -INT8_C( 121), -INT8_C( 104), -INT8_C(  45), -INT8_C(  88),  INT8_C(  93),  INT8_C(  83),  INT8_C(  19), -INT8_C( 110),
        -INT8_C( 112),  INT8_C( 112),  INT8_C(  40), -INT8_C(  81),  INT8_C(  84), -INT8_C(  44), -INT8_C(  78), -INT8_C( 111) } },
    { {  INT8_C(  54), -INT8_C(  83),  INT8_C(  41),  INT8_C(  55),  INT8_C(   7), -INT8_C(   5),  INT8_C(  74), -INT8_C(  79),
        -INT8_C( 126), -INT8_C(  28), -INT8_C(  34), -INT8_C( 101),  INT8_C(  68),  INT8_C(  55), -INT8_C(  15), -INT8_C(  49),
        -INT8_C(  71), -INT8_C( 124), -INT8_C( 127), -INT8_C(  53), -INT8_C(  59),  INT8_C(  18), -INT8_C(  81),  INT8_C(   8),
         INT8_C( 118),  INT8_C(  85),  INT8_C( 105), -INT8_C(  94), -INT8_C( 119), -INT8_C(  58), -INT8_C(   8), -INT8_C(  65),
         INT8_C( 115),  INT8_C(  33), -INT8_C(  10),  INT8_C( 122),  INT8_C(  28),  INT8_C(  65),  INT8_C(  43), -INT8_C(  97),
         INT8_C(  37),  INT8_C(   9),  INT8_C(  58),  INT8_C( 105),  INT8_C(  64),  INT8_C(  43),  INT8_C(  56), -INT8_C(   7),
        -INT8_C(  81), -INT8_C(  70), -INT8_C(  59),  INT8_C( 116), -INT8_C(  52),  INT8_C( 116),  INT8_C( 125),  INT8_C(  66),
        -INT8_C(  55), -INT8_C(  26), -INT8_C(  28),  INT8_C(  82), -INT8_C(  84), -INT8_C(  36),  INT8_C(  18),  INT8_C(  32) },
      UINT64_C( 7978626232144759038),
      { -INT8_C(  49), -INT8_C(  13), -INT8_C(  40),  INT8_C(  16),  INT8_C(  31),  INT8_C(  16),  INT8_C(   9), -INT8_C(  50),
        -INT8_C(  54), -INT8_C(  50),  INT8_C(  67), -INT8_C( 106),  INT8_C(  67), -INT8_C(  64), -INT8_C(  39),  INT8_C(  12),
        -INT8_C(  90), -INT8_C(  67),  INT8_C(  95),  INT8_C(  82), -INT8_C( 102),  INT8_C( 113),  INT8_C( 114), -INT8_C( 104),
         INT8_C( 121),  INT8_C(  13), -INT8_C(  78), -INT8_C(  61), -INT8_C(  45),  INT8_C( 108),  INT8_C(  49), -INT8_C(  94),
         INT8_C(  95),  INT8_C(   9), -INT8_C(  78),  INT8_C( 126),  INT8_C(  26), -INT8_C(  68),  INT8_C(  77), -INT8_C(  28),
        -INT8_C( 118), -INT8_C( 112),  INT8_C( 123), -INT8_C(  51),  INT8_C(  80),  INT8_C(  84), -INT8_C(  38), -INT8_C(  10),
         INT8_C(  17),  INT8_C(  57),  INT8_C(  72), -INT8_C(  85), -INT8_C(  86), -INT8_C(  69),  INT8_C(  67),  INT8_C(  35),
        -INT8_C(  56), -INT8_C(  10), -INT8_C(  26), -INT8_C( 101),  INT8_C(  98),  INT8_C(  24),  INT8_C(  61), -INT8_C(  63) },
      {  INT8_C(  33), -INT8_C(  16),  INT8_C(  64),  INT8_C(  59), -INT8_C(  84), -INT8_C( 115),  INT8_C(  32),  INT8_C(  54),
         INT8_C(  29), -INT8_C( 101),  INT8_C(   4),  INT8_C( 109), -INT8_C(  17), -INT8_C(  34),  INT8_C(  99),  INT8_C(   0),
         INT8_C(  23), -INT8_C(  85), -INT8_C(  84), -INT8_C(  63),  INT8_C( 102), -INT8_C(  17), -INT8_C(  28),  INT8_C(  46),
        -INT8_C(  27), -INT8_C(  53), -INT8_C(  55),  INT8_C(  71), -INT8_C(  29),  INT8_C(   7),  INT8_C(   9),  INT8_C(   4),
        -INT8_C(   9),  INT8_C(  73),  INT8_C(  64), -INT8_C(  93), -INT8_C(  42),  INT8_C(  96), -INT8_C(  39), -INT8_C(  13),
        -INT8_C(   5), -INT8_C(  35),  INT8_C(  96), -INT8_C(  22), -INT8_C(  69), -INT8_C(  61), -INT8_C(  22), -INT8_C(  46),
         INT8_C( 110), -INT8_C( 106), -INT8_C( 109), -INT8_C(  43), -INT8_C( 122),  INT8_C( 120),  INT8_C(   3),  INT8_C( 107),
         INT8_C(  67), -INT8_C(  51), -INT8_C(  77),  INT8_C(  38), -INT8_C(  44), -INT8_C(  68),  INT8_C(  42), -INT8_C(  53) },
      {  INT8_C(  54), -INT8_C(  43), -INT8_C(  27),  INT8_C(  23),  INT8_C(   4),  INT8_C(  23), -INT8_C( 101),  INT8_C(  99),
        -INT8_C( 126), -INT8_C(  28), -INT8_C(  34), -INT8_C(  28),  INT8_C(  68),  INT8_C(  55), -INT8_C(  15), -INT8_C(  49),
        -INT8_C(  71), -INT8_C(  68), -INT8_C( 127), -INT8_C(  84), -INT8_C(  55),  INT8_C(  18), -INT8_C(  81), -INT8_C(  27),
         INT8_C( 118), -INT8_C(  34),  INT8_C( 105),  INT8_C(  59), -INT8_C(  63), -INT8_C(  58), -INT8_C(   8), -INT8_C(  65),
         INT8_C(   4),  INT8_C(  33), -INT8_C(  10),  INT8_C(  42),  INT8_C(  28),  INT8_C(  65), -INT8_C(  34), -INT8_C(  97),
         INT8_C(  37),  INT8_C(  23),  INT8_C(  38),  INT8_C( 105),  INT8_C(  64),  INT8_C(  43), -INT8_C(  55),  INT8_C(   3),
        -INT8_C(  85), -INT8_C(  70), -INT8_C(  59), -INT8_C(  22),  INT8_C(  96),  INT8_C(  38),  INT8_C( 125), -INT8_C(  93),
        -INT8_C(  55),  INT8_C(   3), -INT8_C(  39),  INT8_C(  71), -INT8_C(  84), -INT8_C(  27), -INT8_C(  68),  INT8_C(  32) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_permutexvar_epi8(src, test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i8x64();
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask_permutexvar_epi8(src, k, idx, a);

    simde_test_x86_write_i8x64(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_permutexvar_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t idx[64];
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C( 9857402488456260496),
      { -INT8_C(  87), -INT8_C(  18), -INT8_C(  21), -INT8_C(  97),  INT8_C( 108), -INT8_C(  78),  INT8_C(  96),  INT8_C(  73),
        -INT8_C(  16),  INT8_C(  37),  INT8_C(  82),  INT8_C( 112),  INT8_C(   4),  INT8_C( 125),  INT8_C(  95), -INT8_C(  19),
         INT8_C(  22),  INT8_C(   2),  INT8_C(  53), -INT8_C( 110),  INT8_C( 121),  INT8_C(  74), -INT8_C(  71),  INT8_C(   9),
        -INT8_C(  10),  INT8_C(  53),  INT8_C(  45),  INT8_C(  76), -INT8_C(  68), -INT8_C(   7), -INT8_C(  44),  INT8_C( 102),
        -INT8_C(  24), -INT8_C(  64),  INT8_C(   5),  INT8_C(  84),  INT8_C( 114),  INT8_C( 101), -INT8_C(  99),  INT8_C(  98),
        -INT8_C( 117), -INT8_C(  17), -INT8_C(  46), -INT8_C( 113),  INT8_C( 108),  INT8_C(  49),  INT8_C( 125), -INT8_C( 126),
         INT8_C(  52), -INT8_C(  78),  INT8_C(  20), -INT8_C(  83), -INT8_C(   4), -INT8_C(  51), -INT8_C(  74), -INT8_C(  14),
         INT8_C(   3), -INT8_C(  28),  INT8_C(  62), -INT8_C(  65), -INT8_C(  35),  INT8_C(  19),  INT8_C(  37), -INT8_C(  59) },
      { -INT8_C(  45),  INT8_C(  42),  INT8_C(  25),  INT8_C(  69), -INT8_C( 112), -INT8_C(  74), -INT8_C(  89),  INT8_C(  27),
        -INT8_C(  91),  INT8_C( 121), -INT8_C(  86),  INT8_C(  17), -INT8_C(  86),  INT8_C(  39), -INT8_C( 109), -INT8_C(  34),
        -INT8_C(  39), -INT8_C(  89), -INT8_C( 117), -INT8_C(  42),  INT8_C( 117),  INT8_C(  66), -INT8_C(  56),  INT8_C( 120),
         INT8_C(  38),  INT8_C(   7),  INT8_C(  55),  INT8_C(   3),  INT8_C(  26),  INT8_C(  93), -INT8_C(  55), -INT8_C(  19),
        -INT8_C( 121), -INT8_C(  30),  INT8_C(  50),  INT8_C(  23), -INT8_C( 103), -INT8_C(  39),  INT8_C(  50),  INT8_C(  62),
         INT8_C(  82), -INT8_C(  35),  INT8_C(  80), -INT8_C(   4),  INT8_C(   4), -INT8_C(  29), -INT8_C(  37), -INT8_C(  34),
        -INT8_C( 117),  INT8_C( 102), -INT8_C(  76),  INT8_C(   0), -INT8_C(  88),  INT8_C( 124),  INT8_C( 120), -INT8_C(  50),
        -INT8_C( 125), -INT8_C(  81), -INT8_C(  46), -INT8_C(  99),  INT8_C(  12), -INT8_C( 101), -INT8_C( 118), -INT8_C( 108) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C( 121),
        -INT8_C( 117), -INT8_C(  39),  INT8_C(   0), -INT8_C( 117),  INT8_C(   0), -INT8_C( 101),  INT8_C(   0), -INT8_C(  29),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 124), -INT8_C( 117), -INT8_C(  81), -INT8_C(  86), -INT8_C(  81),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  29),  INT8_C(   0),  INT8_C(   0), -INT8_C(  81),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  45), -INT8_C(  74),  INT8_C(   0), -INT8_C(  76),  INT8_C(   0),  INT8_C(  93),  INT8_C(   0),
         INT8_C(  17), -INT8_C(  34), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  25),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 117), -INT8_C(  29),  INT8_C(   0),  INT8_C(   0),  INT8_C( 120), -INT8_C(  76),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 108),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  74) } },
    { UINT64_C(16669474327693606013),
      { -INT8_C(  69), -INT8_C(  91), -INT8_C(  28), -INT8_C(  65), -INT8_C( 120), -INT8_C(  65), -INT8_C(  99),  INT8_C(  19),
         INT8_C(  37),  INT8_C(  81),  INT8_C(  19), -INT8_C(  50), -INT8_C(  50), -INT8_C( 117), -INT8_C( 100),  INT8_C(  81),
         INT8_C(  59),  INT8_C( 110), -INT8_C(  17),  INT8_C(  71),  INT8_C(   9),  INT8_C( 121), -INT8_C(  37), -INT8_C( 121),
         INT8_C(  54), -INT8_C( 121), -INT8_C(  99), -INT8_C(  53),  INT8_C( 101), -INT8_C(  14), -INT8_C(  77),  INT8_C(  32),
        -INT8_C( 105), -INT8_C( 105), -INT8_C(  33),  INT8_C(  32),  INT8_C(  86),  INT8_C( 125),  INT8_C(  51),  INT8_C( 123),
        -INT8_C(  50),  INT8_C(  71),  INT8_C(  73), -INT8_C( 100), -INT8_C(  46), -INT8_C(  26), -INT8_C(  18),  INT8_C(  13),
         INT8_C(  84), -INT8_C(  35),  INT8_C(  85),  INT8_C(  94),  INT8_C(  86),  INT8_C(  48), -INT8_C(  27), -INT8_C( 116),
        -INT8_C(  73), -INT8_C( 126),  INT8_C(  88),  INT8_C(  28),  INT8_C( 117),  INT8_C(  11),  INT8_C(  60),  INT8_C(  12) },
      { -INT8_C(  94),  INT8_C(  28),  INT8_C(  44), -INT8_C(   8), -INT8_C( 103),  INT8_C(  96),  INT8_C( 115),  INT8_C( 103),
        -INT8_C(  89), -INT8_C(  67),  INT8_C(   4),  INT8_C( 121), -INT8_C(  93), -INT8_C(  14), -INT8_C( 121), -INT8_C(   9),
        -INT8_C(  49), -INT8_C(  36),  INT8_C(  85),  INT8_C(  37),  INT8_C(  12),  INT8_C(  58), -INT8_C(  78), -INT8_C(  60),
        -INT8_C(  67),  INT8_C(  10), -INT8_C(  32),  INT8_C(  50),  INT8_C(  21),  INT8_C(  29),  INT8_C(  62), -INT8_C(  73),
         INT8_C(  57),  INT8_C( 107), -INT8_C(  81), -INT8_C(  46), -INT8_C(  53),  INT8_C(  34),  INT8_C(  57),  INT8_C( 114),
        -INT8_C(  33),  INT8_C(  61), -INT8_C(  21), -INT8_C( 126),  INT8_C(  47),  INT8_C( 114),  INT8_C( 122), -INT8_C(   2),
         INT8_C(  78), -INT8_C(  49),  INT8_C(  36),  INT8_C(  91),  INT8_C(  10), -INT8_C(  42),  INT8_C(  31), -INT8_C(  57),
        -INT8_C(  32), -INT8_C(   1), -INT8_C(   7), -INT8_C(  11),  INT8_C(  28),  INT8_C(  55), -INT8_C(  84),  INT8_C(  85) },
      { -INT8_C(  11),  INT8_C(   0), -INT8_C(  53),  INT8_C(  85), -INT8_C(  89),  INT8_C(  85),  INT8_C(  29),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  37), -INT8_C( 121), -INT8_C( 121),  INT8_C( 121),  INT8_C(   0), -INT8_C(  36),
        -INT8_C(  11),  INT8_C( 122),  INT8_C(   0),  INT8_C( 103),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C( 103),
         INT8_C(   0),  INT8_C( 103),  INT8_C(  29),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  60),  INT8_C(   0), -INT8_C(  73),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),  INT8_C(   0), -INT8_C(  11),
         INT8_C(   0),  INT8_C( 103), -INT8_C(  67),  INT8_C(  21),  INT8_C(  85),  INT8_C(   0),  INT8_C( 122), -INT8_C(  14),
         INT8_C(  12),  INT8_C(   0),  INT8_C(  58),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),
        -INT8_C(  57),  INT8_C(  44), -INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C( 121),  INT8_C(  28), -INT8_C(  93) } },
    { UINT64_C( 6764232356663876514),
      { -INT8_C(  98), -INT8_C(  53), -INT8_C(  33), -INT8_C(  50),  INT8_C(  61),  INT8_C(  89), -INT8_C(  52), -INT8_C( 116),
         INT8_C(  41), -INT8_C(  16), -INT8_C(  25),  INT8_C(  51), -INT8_C(  58),  INT8_C(   6), -INT8_C(   6), -INT8_C(  90),
         INT8_C(   5), -INT8_C(  13), -INT8_C( 101),  INT8_C(  34),  INT8_C(  42),  INT8_C(  71),  INT8_C( 119), -INT8_C(  51),
        -INT8_C(  94), -INT8_C(  97),  INT8_C(  58),  INT8_C(  32),  INT8_C(   0),  INT8_C(  26),  INT8_C( 125), -INT8_C(  98),
        -INT8_C(  27),  INT8_C(  92),  INT8_C( 108),  INT8_C(  34), -INT8_C(  74),  INT8_C(  57), -INT8_C(  82), -INT8_C(  33),
         INT8_C(  41), -INT8_C( 107),  INT8_C(  18), -INT8_C(  16), -INT8_C( 101),  INT8_C(  12), -INT8_C( 106), -INT8_C(  95),
        -INT8_C(   1),  INT8_C(  50), -INT8_C(  61),  INT8_C(  41),  INT8_C( 121),  INT8_C(  58), -INT8_C(  10),  INT8_C(  28),
        -INT8_C(  39),  INT8_C(  49),  INT8_C(  60), -INT8_C(  39),  INT8_C(  75), -INT8_C(  71),  INT8_C( 120),  INT8_C(  48) },
      {  INT8_C(  21), -INT8_C(  28),  INT8_C(  82), -INT8_C(  53),  INT8_C(  29),  INT8_C(   1), -INT8_C(  86),  INT8_C(  71),
        -INT8_C( 106), -INT8_C(  68),  INT8_C(  55),  INT8_C(  50), -INT8_C(  56), -INT8_C(  51), -INT8_C(  45), -INT8_C(  57),
        -INT8_C(   1), -INT8_C( 106), -INT8_C(  15),  INT8_C( 121), -INT8_C(  48), -INT8_C(  25), -INT8_C( 107), -INT8_C(  86),
         INT8_C(  24), -INT8_C(  47), -INT8_C( 125),  INT8_C(  99), -INT8_C( 118), -INT8_C(   5), -INT8_C( 109), -INT8_C(  97),
        -INT8_C(  32), -INT8_C(  26),  INT8_C( 107), -INT8_C(   3), -INT8_C(  25),  INT8_C(  21),  INT8_C(  68),  INT8_C( 125),
        -INT8_C(  46),  INT8_C( 123), -INT8_C(  81), -INT8_C( 102),  INT8_C(  73), -INT8_C( 126),  INT8_C(  98),  INT8_C(  72),
         INT8_C(  24),  INT8_C(  83), -INT8_C(  63), -INT8_C(  23),  INT8_C(  58),  INT8_C(  86), -INT8_C( 109),  INT8_C(  83),
         INT8_C(  39),  INT8_C(  22), -INT8_C(  74), -INT8_C(  79),  INT8_C(  18),  INT8_C(  74),  INT8_C(  81), -INT8_C(  14) },
      {  INT8_C(   0),  INT8_C(  50),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  47),  INT8_C(   0), -INT8_C(  56),
         INT8_C( 123),  INT8_C(  24),  INT8_C(   0), -INT8_C(  23), -INT8_C(  86),  INT8_C(   0), -INT8_C(  74),  INT8_C(   0),
         INT8_C(   1), -INT8_C(  23),  INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 107),  INT8_C(   0), -INT8_C(  74), -INT8_C(  32),  INT8_C(   0), -INT8_C( 125),  INT8_C(  74),  INT8_C(   0),
         INT8_C(  21),  INT8_C(   0),  INT8_C(  73),  INT8_C( 107), -INT8_C( 109),  INT8_C(  22),  INT8_C(  98),  INT8_C(   0),
         INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  56), -INT8_C( 107),  INT8_C(   0),
        -INT8_C(  14), -INT8_C(  63), -INT8_C(  53),  INT8_C( 123),  INT8_C(  22),  INT8_C(   0), -INT8_C( 109), -INT8_C( 118),
        -INT8_C(  47),  INT8_C(   0),  INT8_C(  18), -INT8_C(  47),  INT8_C(  50),  INT8_C(   0),  INT8_C(  39),  INT8_C(   0) } },
    { UINT64_C(11787104197389827120),
      { -INT8_C(  81),  INT8_C(  68),  INT8_C(  62), -INT8_C(   8), -INT8_C(  58), -INT8_C(  96),  INT8_C(  65), -INT8_C(  33),
        -INT8_C(  13),  INT8_C(   2), -INT8_C(  56),  INT8_C(  45),  INT8_C(  89),  INT8_C(  91),      INT8_MIN,      INT8_MIN,
         INT8_C( 113),  INT8_C(  55),  INT8_C(  50), -INT8_C( 125), -INT8_C( 127), -INT8_C( 125),  INT8_C( 117), -INT8_C(  79),
         INT8_C(  63),  INT8_C( 101), -INT8_C(  56),  INT8_C(  16), -INT8_C( 103),  INT8_C(  92), -INT8_C(  76),  INT8_C(  72),
        -INT8_C(  96), -INT8_C(  14),  INT8_C(  65),  INT8_C( 103), -INT8_C( 110), -INT8_C( 126),  INT8_C(  70), -INT8_C( 123),
        -INT8_C( 124),  INT8_C(  14), -INT8_C(  78), -INT8_C(  35),  INT8_C( 105),  INT8_C(  51),  INT8_C(  94), -INT8_C(  38),
         INT8_C( 106), -INT8_C( 112),  INT8_C(  94), -INT8_C(  21),  INT8_C(  19), -INT8_C(  45), -INT8_C( 100),  INT8_C(  82),
         INT8_C(  56),  INT8_C( 100),  INT8_C(  98), -INT8_C(  47), -INT8_C(  64),  INT8_C(  22),  INT8_C(  26),  INT8_C(  97) },
      {  INT8_C(   8),  INT8_C(  91), -INT8_C(  56), -INT8_C( 102), -INT8_C(  35),  INT8_C(  14),  INT8_C(  31),  INT8_C(  97),
         INT8_C(  28), -INT8_C(  46),  INT8_C(  63), -INT8_C( 123),  INT8_C(   5), -INT8_C(  99),  INT8_C(  95),  INT8_C( 111),
         INT8_C(  45), -INT8_C(  67),  INT8_C(  90),  INT8_C(  64), -INT8_C( 111), -INT8_C(  10), -INT8_C( 110), -INT8_C(  55),
         INT8_C(  90), -INT8_C(  12), -INT8_C( 101),  INT8_C(  26),  INT8_C(  11), -INT8_C(  75),  INT8_C( 123),  INT8_C(  19),
         INT8_C(  16),  INT8_C(  67), -INT8_C(  82), -INT8_C(  19),  INT8_C(  81), -INT8_C(  51),  INT8_C(  78),  INT8_C( 109),
        -INT8_C(  97), -INT8_C( 115), -INT8_C(  14), -INT8_C(  92),  INT8_C(  42),  INT8_C(  82),  INT8_C(  19),  INT8_C(  87),
         INT8_C(  15),  INT8_C( 109), -INT8_C( 105), -INT8_C(  96),  INT8_C(  99),  INT8_C(  41),  INT8_C( 106), -INT8_C(  67),
         INT8_C(  30),  INT8_C(   5), -INT8_C(  40),  INT8_C(  41), -INT8_C(  70),  INT8_C(  83),  INT8_C(  60), -INT8_C(  54) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  31),  INT8_C(  16),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  28),  INT8_C(  82), -INT8_C(  12),  INT8_C(  26),  INT8_C(   0),  INT8_C(   8),
         INT8_C( 109), -INT8_C(  67), -INT8_C( 105), -INT8_C( 102),  INT8_C(   0), -INT8_C( 102),  INT8_C(  41),  INT8_C( 109),
        -INT8_C(  54), -INT8_C(  51),  INT8_C(  28),  INT8_C(   0), -INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  16),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90),  INT8_C(   0),  INT8_C(  31),  INT8_C(  14),
         INT8_C(   0),  INT8_C(   0), -INT8_C( 105),  INT8_C(   0), -INT8_C( 115), -INT8_C(  96),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 123),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90),
         INT8_C(  30),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(  67) } },
    { UINT64_C( 6293223821033335447),
      { -INT8_C( 109),  INT8_C(  72), -INT8_C(   4), -INT8_C(  67), -INT8_C( 102),  INT8_C(  15),  INT8_C(  21), -INT8_C(  86),
         INT8_C( 125), -INT8_C(  84),  INT8_C(  74), -INT8_C(  32), -INT8_C(  42), -INT8_C(  76), -INT8_C(  98), -INT8_C(  12),
        -INT8_C(  71),  INT8_C( 118),  INT8_C(  29),  INT8_C( 115), -INT8_C(  55),  INT8_C(  89),  INT8_C(  61),  INT8_C(  96),
         INT8_C(  68), -INT8_C(  12),  INT8_C(  73), -INT8_C(   4), -INT8_C(   6), -INT8_C(  97),  INT8_C(  83), -INT8_C( 115),
        -INT8_C(  25),  INT8_C(  79),  INT8_C(  74), -INT8_C( 126),  INT8_C(  95),  INT8_C(  95),  INT8_C(  44), -INT8_C(  36),
         INT8_C(  12),  INT8_C( 118), -INT8_C(  68), -INT8_C(  30),  INT8_C(  43),  INT8_C(  90), -INT8_C(  42), -INT8_C(  28),
        -INT8_C(  48), -INT8_C(  13),  INT8_C(  88), -INT8_C( 102),  INT8_C(  76), -INT8_C( 107), -INT8_C(   6), -INT8_C( 112),
        -INT8_C( 118),  INT8_C(  67), -INT8_C( 116), -INT8_C( 124), -INT8_C(  30), -INT8_C(  32),  INT8_C(  17), -INT8_C(  54) },
      {  INT8_C(  47),  INT8_C(  91),  INT8_C(  76), -INT8_C( 114), -INT8_C(  69),  INT8_C( 120),  INT8_C( 106), -INT8_C(  57),
        -INT8_C(  18),  INT8_C(  39), -INT8_C(  87),  INT8_C(  25), -INT8_C( 127),      INT8_MAX, -INT8_C(   2),  INT8_C(  82),
         INT8_C( 114),  INT8_C(  86), -INT8_C(  20), -INT8_C(  66), -INT8_C(  21), -INT8_C(  26),  INT8_C(  79),  INT8_C( 117),
         INT8_C(  42), -INT8_C(  37), -INT8_C(   7),  INT8_C(  12), -INT8_C(  69),  INT8_C(  10), -INT8_C(  42), -INT8_C(  21),
         INT8_C( 102),  INT8_C(  34),  INT8_C( 121),  INT8_C(  33), -INT8_C( 102), -INT8_C(  28), -INT8_C(  24), -INT8_C( 119),
         INT8_C(  11), -INT8_C( 111), -INT8_C(  94), -INT8_C( 116),  INT8_C(  16), -INT8_C(  96), -INT8_C(  34), -INT8_C( 126),
        -INT8_C(  10), -INT8_C(  54),  INT8_C(  64), -INT8_C(  30), -INT8_C(  79), -INT8_C( 113),  INT8_C(  87), -INT8_C(  37),
         INT8_C( 107),  INT8_C(  81), -INT8_C(  25),  INT8_C(  38),  INT8_C(  91), -INT8_C(  66),  INT8_C(  17), -INT8_C(  63) },
      { -INT8_C(  66), -INT8_C(  18),  INT8_C(  91),  INT8_C(   0), -INT8_C(   7),  INT8_C(   0),  INT8_C(   0), -INT8_C(  94),
         INT8_C(   0),  INT8_C(  16),  INT8_C(   0),  INT8_C( 102),  INT8_C(   0), -INT8_C(  79), -INT8_C(  42), -INT8_C(  79),
         INT8_C(  81),  INT8_C(  87),  INT8_C(  10),  INT8_C(   0),  INT8_C(  39), -INT8_C(  37),  INT8_C(   0),  INT8_C( 102),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  91),  INT8_C(   0), -INT8_C(  21), -INT8_C(  66),      INT8_MAX,
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  76), -INT8_C(  21), -INT8_C(  21),  INT8_C(   0), -INT8_C(  69),
        -INT8_C( 127),  INT8_C(   0),  INT8_C(  91),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  30),  INT8_C(  42),  INT8_C(   0), -INT8_C( 127),  INT8_C(   0), -INT8_C(  25),  INT8_C(   0),
        -INT8_C(  87), -INT8_C( 114), -INT8_C( 127),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0),  INT8_C(  86),  INT8_C(   0) } },
    { UINT64_C( 8792374952702675936),
      {  INT8_C(  91), -INT8_C(  90),  INT8_C(   6),  INT8_C( 107),  INT8_C(  71), -INT8_C(  27), -INT8_C(  19),  INT8_C(  61),
        -INT8_C(  81),  INT8_C(  46),  INT8_C(  31),  INT8_C(  96), -INT8_C(  67),  INT8_C( 119),  INT8_C(  59),  INT8_C(  40),
        -INT8_C(  56),  INT8_C(  35),  INT8_C(  79),  INT8_C(  35), -INT8_C(  31),  INT8_C(  96), -INT8_C(  27), -INT8_C(  63),
        -INT8_C(  21), -INT8_C(  57),  INT8_C(  60),  INT8_C(  90), -INT8_C( 110),  INT8_C(  64), -INT8_C(  44), -INT8_C(  19),
        -INT8_C(  25), -INT8_C(  37),  INT8_C(  89),  INT8_C(  46), -INT8_C(  64),  INT8_C(  70),  INT8_C( 107),  INT8_C( 111),
         INT8_C( 116), -INT8_C( 117), -INT8_C(  48),  INT8_C(  50),  INT8_C(   2),  INT8_C(  11),  INT8_C(  90), -INT8_C(  54),
         INT8_C(  46), -INT8_C(  87), -INT8_C(  19),  INT8_C(  15),  INT8_C(  10), -INT8_C(  46), -INT8_C(  47), -INT8_C(  11),
        -INT8_C( 102),  INT8_C(  13),  INT8_C(  80),  INT8_C(  44),  INT8_C(  78),  INT8_C(  36),  INT8_C(  25),  INT8_C(  53) },
      { -INT8_C(   1),  INT8_C( 114),  INT8_C(  99), -INT8_C(  65), -INT8_C(  71), -INT8_C(  50),  INT8_C(  47),  INT8_C(  45),
         INT8_C(  89), -INT8_C(   1),  INT8_C(  95),  INT8_C(  91),  INT8_C(  10), -INT8_C(  70),  INT8_C(  37),  INT8_C(  57),
         INT8_C(  99),  INT8_C(  19),  INT8_C(  72),  INT8_C( 109), -INT8_C(  27),  INT8_C(  25),  INT8_C(  99),      INT8_MAX,
         INT8_C(  39), -INT8_C(  77), -INT8_C(  85),  INT8_C( 117), -INT8_C(  41), -INT8_C(  59), -INT8_C(  86), -INT8_C(  41),
         INT8_C(  55),  INT8_C(  13), -INT8_C( 106), -INT8_C(  16), -INT8_C(  37), -INT8_C(  59),  INT8_C(  30),  INT8_C(  53),
        -INT8_C(  60),  INT8_C( 125), -INT8_C( 112), -INT8_C(  49),  INT8_C(  55), -INT8_C(  74),  INT8_C(   8), -INT8_C( 101),
        -INT8_C(  55),  INT8_C(  80),  INT8_C(   8), -INT8_C(  82),  INT8_C( 106),  INT8_C( 107),  INT8_C(  46), -INT8_C( 111),
         INT8_C(  30), -INT8_C(  39),  INT8_C(   6), -INT8_C(  10), -INT8_C(  98), -INT8_C(  80), -INT8_C(  51), -INT8_C(  42) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  59), -INT8_C(  74), -INT8_C(  80),
        -INT8_C( 101),  INT8_C(   8),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  60),
         INT8_C(   0), -INT8_C(  16),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  55), -INT8_C(  59),  INT8_C( 114),
        -INT8_C(  49),  INT8_C(  45),  INT8_C(   0), -INT8_C(  85),  INT8_C(  72), -INT8_C(   1), -INT8_C(  27),  INT8_C(   0),
         INT8_C(  53),  INT8_C( 117), -INT8_C(  77),  INT8_C(   8),  INT8_C(   0),  INT8_C(  47), -INT8_C(  49),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  91),  INT8_C(   0),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0), -INT8_C(  85),  INT8_C(  95),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  70),  INT8_C(   0),  INT8_C(  55),  INT8_C(  37), -INT8_C(  37), -INT8_C(  77),  INT8_C(   0) } },
    { UINT64_C(17135603024522535869),
      {  INT8_C(  98),  INT8_C(  94), -INT8_C(  68), -INT8_C( 103),  INT8_C(  20), -INT8_C(  60),  INT8_C(  52), -INT8_C(  35),
         INT8_C(  21),  INT8_C(  61), -INT8_C( 117),      INT8_MAX, -INT8_C(  88), -INT8_C(  71),  INT8_C(  16), -INT8_C(  57),
        -INT8_C( 109),  INT8_C(  22), -INT8_C(  67),  INT8_C(  49), -INT8_C(  58), -INT8_C( 118),  INT8_C(   7), -INT8_C( 125),
        -INT8_C(  19), -INT8_C(  50),  INT8_C(  27),  INT8_C(  22), -INT8_C(  78), -INT8_C(  23),  INT8_C(   4),  INT8_C(  20),
         INT8_C(  71), -INT8_C(  64), -INT8_C(  82),  INT8_C(  91), -INT8_C( 123), -INT8_C(  30),  INT8_C(  56), -INT8_C( 102),
         INT8_C(  31), -INT8_C(  61),  INT8_C(  25), -INT8_C(  56),  INT8_C( 125),  INT8_C(  41), -INT8_C( 113),  INT8_C(  16),
         INT8_C(  63),  INT8_C(  76),  INT8_C(  65),  INT8_C(   5), -INT8_C(  42),  INT8_C(  73), -INT8_C( 120), -INT8_C(  61),
         INT8_C(  23), -INT8_C(  93), -INT8_C(  38), -INT8_C(  55), -INT8_C( 116), -INT8_C(  34), -INT8_C(  34), -INT8_C(  45) },
      { -INT8_C(  98), -INT8_C( 116),  INT8_C(  46),  INT8_C(  35),  INT8_C( 110),  INT8_C( 102), -INT8_C(  67), -INT8_C( 114),
         INT8_C(  42), -INT8_C(  42),  INT8_C(  86), -INT8_C(  89), -INT8_C(   1), -INT8_C(  27), -INT8_C(  73),  INT8_C(  62),
         INT8_C(  49), -INT8_C(   8),  INT8_C(  67),  INT8_C(   7),  INT8_C(  65), -INT8_C(  53), -INT8_C(  54),  INT8_C(  88),
         INT8_C( 111), -INT8_C(  92),  INT8_C(  34), -INT8_C(   5), -INT8_C( 126),  INT8_C(   0), -INT8_C(  49),  INT8_C(  33),
        -INT8_C( 116), -INT8_C(   3),  INT8_C(  68), -INT8_C(   6),  INT8_C( 100),  INT8_C(   2), -INT8_C( 120), -INT8_C( 114),
        -INT8_C(  40), -INT8_C(  34),  INT8_C(  53), -INT8_C(  40), -INT8_C(  61), -INT8_C(  20),  INT8_C(  22), -INT8_C(  12),
        -INT8_C(  28),  INT8_C(  90), -INT8_C(   5),  INT8_C(  38),  INT8_C(  37), -INT8_C(  58),  INT8_C( 126), -INT8_C( 108),
         INT8_C( 106), -INT8_C(  96), -INT8_C( 112), -INT8_C(  19), -INT8_C(  96),  INT8_C(  95),  INT8_C(  14),  INT8_C(  44) },
      {  INT8_C(  68),  INT8_C(   0), -INT8_C(  96), -INT8_C(  92),  INT8_C(  65),  INT8_C( 110),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  53),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  96),  INT8_C(  49),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  54),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 114),  INT8_C(  35),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  54), -INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(  65),
        -INT8_C( 114),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0),  INT8_C(   0), -INT8_C(  34),  INT8_C(  62),  INT8_C(  49),
         INT8_C(  44),  INT8_C(   0), -INT8_C( 116),  INT8_C( 102),  INT8_C(   0),  INT8_C(   0),  INT8_C(  42),  INT8_C(  35),
         INT8_C(  88),  INT8_C(   0),  INT8_C(  34), -INT8_C(  42),  INT8_C(   0), -INT8_C(  49), -INT8_C(  49),  INT8_C(   7) } },
    { UINT64_C( 3264739558426104412),
      { -INT8_C( 114), -INT8_C( 125),  INT8_C(   5),  INT8_C(  81),  INT8_C( 111),  INT8_C(  27),  INT8_C(  70),  INT8_C(  84),
         INT8_C( 117),  INT8_C(  65),  INT8_C( 122), -INT8_C( 101),  INT8_C(   7), -INT8_C(   8),  INT8_C(  47),  INT8_C( 114),
        -INT8_C( 103), -INT8_C(  65),  INT8_C(  95),  INT8_C(  57),  INT8_C(  30),  INT8_C( 109),  INT8_C( 102),  INT8_C( 123),
        -INT8_C(  65), -INT8_C( 115),  INT8_C(  59),  INT8_C(  20),  INT8_C(  60), -INT8_C( 118),  INT8_C(  65), -INT8_C(  54),
         INT8_C(  13),  INT8_C(  70),  INT8_C(  28),  INT8_C( 125),  INT8_C(  97),  INT8_C(  98), -INT8_C(  47), -INT8_C(  41),
        -INT8_C(  93),  INT8_C(  75),  INT8_C( 114), -INT8_C(  85),  INT8_C(  67), -INT8_C(  95),  INT8_C(  29), -INT8_C(  36),
         INT8_C(  97),  INT8_C( 124),  INT8_C(  22),      INT8_MAX, -INT8_C(  23),  INT8_C( 124), -INT8_C(   6), -INT8_C(  88),
         INT8_C(   9),  INT8_C(  54), -INT8_C(  68),  INT8_C(  69), -INT8_C(  64), -INT8_C(   3),  INT8_C(  16), -INT8_C(  51) },
      {  INT8_C(  67),  INT8_C(  44),  INT8_C(  74), -INT8_C(  91), -INT8_C( 114),  INT8_C(  27),  INT8_C( 124),  INT8_C(  49),
         INT8_C( 102), -INT8_C(  18), -INT8_C(  36), -INT8_C(  86), -INT8_C( 113), -INT8_C(   7), -INT8_C( 122), -INT8_C(  16),
         INT8_C( 117), -INT8_C( 100),  INT8_C( 112),  INT8_C(  94),  INT8_C(  24),  INT8_C( 106),  INT8_C(   7),  INT8_C(  33),
        -INT8_C(  96), -INT8_C(  61),  INT8_C( 103),  INT8_C(  96), -INT8_C(  63),  INT8_C( 119),  INT8_C(  46),  INT8_C(   4),
        -INT8_C(  93),  INT8_C( 120), -INT8_C(  87),  INT8_C(  49), -INT8_C( 108),  INT8_C(  37),  INT8_C(  98), -INT8_C(   6),
         INT8_C(  19),  INT8_C(  63), -INT8_C(  92), -INT8_C(  93),  INT8_C(  56),  INT8_C(  43), -INT8_C( 109), -INT8_C(  82),
        -INT8_C(  57),  INT8_C(   3),  INT8_C(  12), -INT8_C(  32),  INT8_C( 110),  INT8_C(  19),  INT8_C(   1),  INT8_C(  14),
        -INT8_C(  41),  INT8_C( 104),  INT8_C( 111), -INT8_C( 104), -INT8_C(  33), -INT8_C(  99), -INT8_C( 100), -INT8_C( 126) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  27), -INT8_C( 100), -INT8_C(  82),  INT8_C(   0),  INT8_C( 124),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0), -INT8_C(  82),  INT8_C(   0),
        -INT8_C(  61), -INT8_C( 126),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44), -INT8_C(  36),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  63),  INT8_C(   0),  INT8_C( 120),  INT8_C(   0), -INT8_C( 100),  INT8_C(   0),
         INT8_C(  49), -INT8_C(  86),  INT8_C(  12), -INT8_C(  93),  INT8_C(   0),  INT8_C( 120),  INT8_C(   0), -INT8_C(  63),
         INT8_C(   0), -INT8_C(  33),  INT8_C(   7), -INT8_C( 126),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),  INT8_C(   0),
        -INT8_C(  18),  INT8_C(   0), -INT8_C(  33),  INT8_C(  27),  INT8_C(   0), -INT8_C(  99),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_permutexvar_epi8(test_vec[i].k, idx, a);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_maskz_permutexvar_epi8(k, idx, a);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_permutexvar_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i idx;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 4022993628330696330), INT64_C( -564047204985781920),
                            INT64_C( 4934063986128071877), INT64_C( 8258886799903261224),
                            INT64_C( 5245738308211416456), INT64_C( 8690736315259258337),
                            INT64_C(-5183161890921602420), INT64_C(-2495336383094170141)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  355.11), SIMDE_FLOAT64_C( -787.72),
                         SIMDE_FLOAT64_C(  472.82), SIMDE_FLOAT64_C( -703.51),
                         SIMDE_FLOAT64_C( -202.49), SIMDE_FLOAT64_C( -470.36),
                         SIMDE_FLOAT64_C(  966.37), SIMDE_FLOAT64_C(  135.20)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -470.36), SIMDE_FLOAT64_C(  135.20),
                         SIMDE_FLOAT64_C(  472.82), SIMDE_FLOAT64_C(  135.20),
                         SIMDE_FLOAT64_C(  135.20), SIMDE_FLOAT64_C(  966.37),
                         SIMDE_FLOAT64_C( -703.51), SIMDE_FLOAT64_C( -202.49)) },
    { simde_mm512_set_epi64(INT64_C( 1295774678670654457), INT64_C(-8851107363323835123),
                            INT64_C( 2369486750103851747), INT64_C(-5139586436110975467),
                            INT64_C(-8115609027568940125), INT64_C( 3504612124823893047),
                            INT64_C(-7514888466798804666), INT64_C( 9113506312589344178)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  193.01), SIMDE_FLOAT64_C( -435.27),
                         SIMDE_FLOAT64_C(  -84.06), SIMDE_FLOAT64_C(  298.40),
                         SIMDE_FLOAT64_C(  208.07), SIMDE_FLOAT64_C(  -94.60),
                         SIMDE_FLOAT64_C(  834.28), SIMDE_FLOAT64_C(  260.50)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  834.28), SIMDE_FLOAT64_C(  -84.06),
                         SIMDE_FLOAT64_C(  208.07), SIMDE_FLOAT64_C(  -84.06),
                         SIMDE_FLOAT64_C(  208.07), SIMDE_FLOAT64_C(  193.01),
                         SIMDE_FLOAT64_C( -435.27), SIMDE_FLOAT64_C(  -94.60)) },
    { simde_mm512_set_epi64(INT64_C(-3094219001013742557), INT64_C(-3379016320921474793),
                            INT64_C( 7772273849745001049), INT64_C(-4229480058937372017),
                            INT64_C( 8318730560275653847), INT64_C(-2664412856586094061),
                            INT64_C( 2083707536546841162), INT64_C( 5404230241318444880)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -2.60), SIMDE_FLOAT64_C(  -38.88),
                         SIMDE_FLOAT64_C(  165.88), SIMDE_FLOAT64_C(  218.73),
                         SIMDE_FLOAT64_C(  375.27), SIMDE_FLOAT64_C( -966.90),
                         SIMDE_FLOAT64_C( -512.98), SIMDE_FLOAT64_C( -737.78)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  375.27), SIMDE_FLOAT64_C(   -2.60),
                         SIMDE_FLOAT64_C( -512.98), SIMDE_FLOAT64_C(   -2.60),
                         SIMDE_FLOAT64_C(   -2.60), SIMDE_FLOAT64_C(  375.27),
                         SIMDE_FLOAT64_C( -966.90), SIMDE_FLOAT64_C( -737.78)) },
    { simde_mm512_set_epi64(INT64_C( 2522518958303333112), INT64_C(-1668307566098600867),
                            INT64_C( 8306832211054389426), INT64_C(-4135341282024622606),
                            INT64_C(-7922172549839933132), INT64_C(   90826243433254935),
                            INT64_C( 1037923706586637130), INT64_C( 5568688997300093349)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -179.98), SIMDE_FLOAT64_C(  258.23),
                         SIMDE_FLOAT64_C(  246.22), SIMDE_FLOAT64_C(   97.85),
                         SIMDE_FLOAT64_C(  666.32), SIMDE_FLOAT64_C(  364.80),
                         SIMDE_FLOAT64_C(  759.27), SIMDE_FLOAT64_C( -524.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -524.19), SIMDE_FLOAT64_C(  246.22),
                         SIMDE_FLOAT64_C(  364.80), SIMDE_FLOAT64_C(  364.80),
                         SIMDE_FLOAT64_C(   97.85), SIMDE_FLOAT64_C( -179.98),
                         SIMDE_FLOAT64_C(  364.80), SIMDE_FLOAT64_C(  246.22)) },
    { simde_mm512_set_epi64(INT64_C(-6876215301736363293), INT64_C(-2253243373865166954),
                            INT64_C( 5866706473820467911), INT64_C(-1945184283153250111),
                            INT64_C(-6043663531296462836), INT64_C(-3201199251206898425),
                            INT64_C(-7517867743898200758), INT64_C( 5023666877462679332)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -846.10), SIMDE_FLOAT64_C( -248.07),
                         SIMDE_FLOAT64_C( -411.92), SIMDE_FLOAT64_C(  -88.91),
                         SIMDE_FLOAT64_C(  481.68), SIMDE_FLOAT64_C(  170.00),
                         SIMDE_FLOAT64_C( -341.91), SIMDE_FLOAT64_C(  366.57)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  481.68), SIMDE_FLOAT64_C( -248.07),
                         SIMDE_FLOAT64_C( -846.10), SIMDE_FLOAT64_C( -341.91),
                         SIMDE_FLOAT64_C(  -88.91), SIMDE_FLOAT64_C( -846.10),
                         SIMDE_FLOAT64_C(  170.00), SIMDE_FLOAT64_C(  -88.91)) },
    { simde_mm512_set_epi64(INT64_C( 5698026186558744964), INT64_C( 6269499859520580584),
                            INT64_C( 7385991043015762011), INT64_C( 2173549174497415259),
                            INT64_C(  135432210503006619), INT64_C(-7059566968128636366),
                            INT64_C(-1295026765047609725), INT64_C( 5447800525707046939)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  197.25), SIMDE_FLOAT64_C(  358.04),
                         SIMDE_FLOAT64_C(  348.19), SIMDE_FLOAT64_C( -974.37),
                         SIMDE_FLOAT64_C(  713.78), SIMDE_FLOAT64_C( -342.76),
                         SIMDE_FLOAT64_C( -632.29), SIMDE_FLOAT64_C( -698.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -974.37), SIMDE_FLOAT64_C( -698.47),
                         SIMDE_FLOAT64_C(  713.78), SIMDE_FLOAT64_C(  713.78),
                         SIMDE_FLOAT64_C(  713.78), SIMDE_FLOAT64_C( -342.76),
                         SIMDE_FLOAT64_C(  713.78), SIMDE_FLOAT64_C(  713.78)) },
    { simde_mm512_set_epi64(INT64_C(-7778482448656032654), INT64_C(-7388935565641111344),
                            INT64_C( 2154583157079273400), INT64_C( 4649728279138736034),
                            INT64_C( 1896125478609903946), INT64_C( 6795120210135498653),
                            INT64_C(-8532964392806396349), INT64_C(-8044512602622188161)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  151.19), SIMDE_FLOAT64_C(  763.12),
                         SIMDE_FLOAT64_C(   17.85), SIMDE_FLOAT64_C(  797.99),
                         SIMDE_FLOAT64_C(  280.96), SIMDE_FLOAT64_C(  291.55),
                         SIMDE_FLOAT64_C( -966.13), SIMDE_FLOAT64_C(  -93.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  291.55), SIMDE_FLOAT64_C(  -93.41),
                         SIMDE_FLOAT64_C(  -93.41), SIMDE_FLOAT64_C(  291.55),
                         SIMDE_FLOAT64_C(  291.55), SIMDE_FLOAT64_C(   17.85),
                         SIMDE_FLOAT64_C(  280.96), SIMDE_FLOAT64_C(  151.19)) },
    { simde_mm512_set_epi64(INT64_C(-8313572030703954107), INT64_C( 8197482817575228316),
                            INT64_C( 7734796813438689885), INT64_C(-7308014241195865956),
                            INT64_C( 8618855955534148826), INT64_C(-1358620153905394442),
                            INT64_C(-6300735262609682931), INT64_C(-6423460006708841158)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -747.31), SIMDE_FLOAT64_C(  206.83),
                         SIMDE_FLOAT64_C(  -77.03), SIMDE_FLOAT64_C( -852.95),
                         SIMDE_FLOAT64_C(  918.21), SIMDE_FLOAT64_C( -446.06),
                         SIMDE_FLOAT64_C(  363.23), SIMDE_FLOAT64_C( -141.96)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -77.03), SIMDE_FLOAT64_C( -852.95),
                         SIMDE_FLOAT64_C(  -77.03), SIMDE_FLOAT64_C( -852.95),
                         SIMDE_FLOAT64_C( -446.06), SIMDE_FLOAT64_C(  206.83),
                         SIMDE_FLOAT64_C(  -77.03), SIMDE_FLOAT64_C( -446.06)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_permutexvar_pd(test_vec[i].idx, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_permutexvar_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512i idx;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  903.50), SIMDE_FLOAT64_C(  -43.35),
                         SIMDE_FLOAT64_C(  309.91), SIMDE_FLOAT64_C(  846.15),
                         SIMDE_FLOAT64_C( -514.56), SIMDE_FLOAT64_C( -860.98),
                         SIMDE_FLOAT64_C( -280.30), SIMDE_FLOAT64_C(  128.51)),
      UINT8_C( 87),
      simde_mm512_set_epi64(INT64_C( 4086853108457730066), INT64_C(-7738570880062900818),
                            INT64_C(-5609503674875201288), INT64_C( 3966155248134972346),
                            INT64_C( 6201510655001996332), INT64_C( 7633590894537872708),
                            INT64_C(-5593693910291334810), INT64_C(-8884932670315115433)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  483.08), SIMDE_FLOAT64_C(  232.04),
                         SIMDE_FLOAT64_C(  774.81), SIMDE_FLOAT64_C( -599.01),
                         SIMDE_FLOAT64_C(   69.04), SIMDE_FLOAT64_C( -149.02),
                         SIMDE_FLOAT64_C(  240.79), SIMDE_FLOAT64_C( -839.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  903.50), SIMDE_FLOAT64_C(  232.04),
                         SIMDE_FLOAT64_C(  309.91), SIMDE_FLOAT64_C( -149.02),
                         SIMDE_FLOAT64_C( -514.56), SIMDE_FLOAT64_C( -599.01),
                         SIMDE_FLOAT64_C(  232.04), SIMDE_FLOAT64_C(  483.08)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  337.35), SIMDE_FLOAT64_C( -278.32),
                         SIMDE_FLOAT64_C( -744.41), SIMDE_FLOAT64_C(   39.32),
                         SIMDE_FLOAT64_C(   29.68), SIMDE_FLOAT64_C( -490.28),
                         SIMDE_FLOAT64_C(  841.53), SIMDE_FLOAT64_C(  526.21)),
      UINT8_C(157),
      simde_mm512_set_epi64(INT64_C( 1516975282358243755), INT64_C(-3949523894747321163),
                            INT64_C(-2989078375862773056), INT64_C(-4700117291684372957),
                            INT64_C(-8784413934425613521), INT64_C(  961867877660623168),
                            INT64_C( 2426510480636680010), INT64_C(-6612602987193650875)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -198.67), SIMDE_FLOAT64_C(  447.98),
                         SIMDE_FLOAT64_C( -925.69), SIMDE_FLOAT64_C(  717.83),
                         SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C(  -37.49),
                         SIMDE_FLOAT64_C( -373.66), SIMDE_FLOAT64_C( -292.35)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C( -278.32),
                         SIMDE_FLOAT64_C( -744.41), SIMDE_FLOAT64_C( -489.88),
                         SIMDE_FLOAT64_C( -198.67), SIMDE_FLOAT64_C( -292.35),
                         SIMDE_FLOAT64_C(  841.53), SIMDE_FLOAT64_C( -925.69)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -207.87), SIMDE_FLOAT64_C( -765.42),
                         SIMDE_FLOAT64_C(  138.83), SIMDE_FLOAT64_C(  699.07),
                         SIMDE_FLOAT64_C( -143.73), SIMDE_FLOAT64_C(  709.96),
                         SIMDE_FLOAT64_C( -767.34), SIMDE_FLOAT64_C( -588.28)),
      UINT8_C( 75),
      simde_mm512_set_epi64(INT64_C(-1414228054518303181), INT64_C(-3038909907977133732),
                            INT64_C(-7842471790453318316), INT64_C(-7256600765093102205),
                            INT64_C( 3898178537456140670), INT64_C( -393151907512138120),
                            INT64_C(  600214805061827669), INT64_C( 3163434753014979248)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -842.15), SIMDE_FLOAT64_C(  908.84),
                         SIMDE_FLOAT64_C( -315.78), SIMDE_FLOAT64_C(  -86.06),
                         SIMDE_FLOAT64_C( -413.85), SIMDE_FLOAT64_C(  752.26),
                         SIMDE_FLOAT64_C(  609.29), SIMDE_FLOAT64_C(  878.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -207.87), SIMDE_FLOAT64_C(  -86.06),
                         SIMDE_FLOAT64_C(  138.83), SIMDE_FLOAT64_C(  699.07),
                         SIMDE_FLOAT64_C(  908.84), SIMDE_FLOAT64_C(  709.96),
                         SIMDE_FLOAT64_C( -315.78), SIMDE_FLOAT64_C(  878.85)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -659.70), SIMDE_FLOAT64_C(  493.30),
                         SIMDE_FLOAT64_C(  831.29), SIMDE_FLOAT64_C( -619.50),
                         SIMDE_FLOAT64_C(  952.47), SIMDE_FLOAT64_C( -492.61),
                         SIMDE_FLOAT64_C(  -68.16), SIMDE_FLOAT64_C(  717.69)),
      UINT8_C( 23),
      simde_mm512_set_epi64(INT64_C( 6555696811272222802), INT64_C( -751557688731444383),
                            INT64_C( 5324069355912068288), INT64_C( 5226578984858504214),
                            INT64_C(-8776157931044543560), INT64_C(-1848672680316222475),
                            INT64_C( 1658167909352451238), INT64_C(  377173394815185621)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  493.65), SIMDE_FLOAT64_C(   52.79),
                         SIMDE_FLOAT64_C(  835.54), SIMDE_FLOAT64_C( -712.24),
                         SIMDE_FLOAT64_C(  518.12), SIMDE_FLOAT64_C( -173.80),
                         SIMDE_FLOAT64_C(  487.08), SIMDE_FLOAT64_C(  180.78)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -659.70), SIMDE_FLOAT64_C(  493.30),
                         SIMDE_FLOAT64_C(  831.29), SIMDE_FLOAT64_C(   52.79),
                         SIMDE_FLOAT64_C(  952.47), SIMDE_FLOAT64_C(  835.54),
                         SIMDE_FLOAT64_C(   52.79), SIMDE_FLOAT64_C(  835.54)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -388.47), SIMDE_FLOAT64_C( -643.43),
                         SIMDE_FLOAT64_C( -331.34), SIMDE_FLOAT64_C(   72.67),
                         SIMDE_FLOAT64_C( -870.79), SIMDE_FLOAT64_C( -722.44),
                         SIMDE_FLOAT64_C(  529.44), SIMDE_FLOAT64_C( -949.73)),
      UINT8_C( 46),
      simde_mm512_set_epi64(INT64_C( 5042844271761388948), INT64_C(  877966720713550779),
                            INT64_C(-8757547308289839577), INT64_C( 6619480224799141474),
                            INT64_C( 3171924723684651500), INT64_C( 1941135797030545610),
                            INT64_C( 1935432241277000941), INT64_C( 5390015454023535429)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -783.00), SIMDE_FLOAT64_C( -102.18),
                         SIMDE_FLOAT64_C(  960.00), SIMDE_FLOAT64_C(   22.93),
                         SIMDE_FLOAT64_C( -395.13), SIMDE_FLOAT64_C(  145.63),
                         SIMDE_FLOAT64_C( -149.04), SIMDE_FLOAT64_C(  214.37)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -388.47), SIMDE_FLOAT64_C( -643.43),
                         SIMDE_FLOAT64_C( -783.00), SIMDE_FLOAT64_C(   72.67),
                         SIMDE_FLOAT64_C(   22.93), SIMDE_FLOAT64_C(  145.63),
                         SIMDE_FLOAT64_C(  960.00), SIMDE_FLOAT64_C( -949.73)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -607.82), SIMDE_FLOAT64_C(  296.47),
                         SIMDE_FLOAT64_C( -327.04), SIMDE_FLOAT64_C(  -23.06),
                         SIMDE_FLOAT64_C(  -95.21), SIMDE_FLOAT64_C(   10.75),
                         SIMDE_FLOAT64_C( -668.43), SIMDE_FLOAT64_C( -210.00)),
      UINT8_C( 43),
      simde_mm512_set_epi64(INT64_C(-4824857292892203785), INT64_C( 6286668337562607931),
                            INT64_C( 1432089847019206822), INT64_C(-2235254547542691893),
                            INT64_C(-2975358417486477451), INT64_C( 5974528986311566652),
                            INT64_C( 4798128784982043356), INT64_C(-3663239326212228984)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -777.05), SIMDE_FLOAT64_C(  621.95),
                         SIMDE_FLOAT64_C( -116.18), SIMDE_FLOAT64_C(  909.84),
                         SIMDE_FLOAT64_C(  696.35), SIMDE_FLOAT64_C( -644.31),
                         SIMDE_FLOAT64_C(  486.53), SIMDE_FLOAT64_C( -235.48)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -607.82), SIMDE_FLOAT64_C(  296.47),
                         SIMDE_FLOAT64_C(  621.95), SIMDE_FLOAT64_C(  -23.06),
                         SIMDE_FLOAT64_C( -116.18), SIMDE_FLOAT64_C(   10.75),
                         SIMDE_FLOAT64_C(  909.84), SIMDE_FLOAT64_C( -235.48)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  383.31), SIMDE_FLOAT64_C(  641.22),
                         SIMDE_FLOAT64_C( -747.07), SIMDE_FLOAT64_C( -762.67),
                         SIMDE_FLOAT64_C(  744.11), SIMDE_FLOAT64_C(  350.11),
                         SIMDE_FLOAT64_C(  409.27), SIMDE_FLOAT64_C(  481.83)),
      UINT8_C(217),
      simde_mm512_set_epi64(INT64_C( 8817045194671758320), INT64_C(-5234965963681749811),
                            INT64_C(-5331803015084564567), INT64_C(-2592115690296560951),
                            INT64_C( 1248919004007478956), INT64_C( 6138870327161964525),
                            INT64_C(-3131027839562886620), INT64_C(-2317534169293970587)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -251.41), SIMDE_FLOAT64_C(  223.24),
                         SIMDE_FLOAT64_C( -528.18), SIMDE_FLOAT64_C(  813.86),
                         SIMDE_FLOAT64_C(  925.24), SIMDE_FLOAT64_C(  849.34),
                         SIMDE_FLOAT64_C(  112.68), SIMDE_FLOAT64_C(  -96.70)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -96.70), SIMDE_FLOAT64_C( -528.18),
                         SIMDE_FLOAT64_C( -747.07), SIMDE_FLOAT64_C(  112.68),
                         SIMDE_FLOAT64_C(  813.86), SIMDE_FLOAT64_C(  350.11),
                         SIMDE_FLOAT64_C(  409.27), SIMDE_FLOAT64_C( -528.18)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -653.71), SIMDE_FLOAT64_C(  371.73),
                         SIMDE_FLOAT64_C(  757.18), SIMDE_FLOAT64_C(  214.84),
                         SIMDE_FLOAT64_C(  830.24), SIMDE_FLOAT64_C(  903.53),
                         SIMDE_FLOAT64_C( -831.08), SIMDE_FLOAT64_C(  815.07)),
      UINT8_C(120),
      simde_mm512_set_epi64(INT64_C( 2443726936750986290), INT64_C(-9169540186107924323),
                            INT64_C(-8862352522735882724), INT64_C(-8073374806940567698),
                            INT64_C( 5084858765896996878), INT64_C(-8091734011393453138),
                            INT64_C(-8622672902733011795), INT64_C(  255780820358907048)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -710.54), SIMDE_FLOAT64_C( -140.51),
                         SIMDE_FLOAT64_C(  346.36), SIMDE_FLOAT64_C(  318.14),
                         SIMDE_FLOAT64_C(  399.19), SIMDE_FLOAT64_C( -291.83),
                         SIMDE_FLOAT64_C(  951.57), SIMDE_FLOAT64_C(  272.52)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -653.71), SIMDE_FLOAT64_C(  346.36),
                         SIMDE_FLOAT64_C(  318.14), SIMDE_FLOAT64_C( -140.51),
                         SIMDE_FLOAT64_C( -140.51), SIMDE_FLOAT64_C(  903.53),
                         SIMDE_FLOAT64_C( -831.08), SIMDE_FLOAT64_C(  815.07)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_permutexvar_pd(test_vec[i].src, test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_permutexvar_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i idx;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { UINT8_C( 87),
      simde_mm512_set_epi64(INT64_C( 4086853108457730066), INT64_C(-7738570880062900818),
                            INT64_C(-5609503674875201288), INT64_C( 3966155248134972346),
                            INT64_C( 6201510655001996332), INT64_C( 7633590894537872708),
                            INT64_C(-5593693910291334810), INT64_C(-8884932670315115433)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   69.04), SIMDE_FLOAT64_C( -514.56),
                         SIMDE_FLOAT64_C( -149.02), SIMDE_FLOAT64_C( -860.98),
                         SIMDE_FLOAT64_C(  240.79), SIMDE_FLOAT64_C( -280.30),
                         SIMDE_FLOAT64_C( -839.80), SIMDE_FLOAT64_C(  128.51)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -514.56),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -280.30),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -860.98),
                         SIMDE_FLOAT64_C( -514.56), SIMDE_FLOAT64_C(   69.04)) },
    { UINT8_C(109),
      simde_mm512_set_epi64(INT64_C(-8784413934425613521), INT64_C(  961867877660623168),
                            INT64_C( 2426510480636680010), INT64_C(-6612602987193650875),
                            INT64_C( 6143333881204814617), INT64_C( -890089152921238147),
                            INT64_C( 8823574133744668217), INT64_C(-6364969741708969084)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -835.53), SIMDE_FLOAT64_C( -203.04),
                         SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C(  -80.71),
                         SIMDE_FLOAT64_C(  675.92), SIMDE_FLOAT64_C(  632.01),
                         SIMDE_FLOAT64_C(  490.41), SIMDE_FLOAT64_C(  456.89)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  456.89),
                         SIMDE_FLOAT64_C(  632.01), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  490.41), SIMDE_FLOAT64_C(  571.79),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  -80.71)) },
    { UINT8_C( 33),
      simde_mm512_set_epi64(INT64_C( 3418472134552461373), INT64_C(-6111840559061041971),
                            INT64_C( 6656352319933975670), INT64_C( 2357435311113502667),
                            INT64_C(-8860733056306413573), INT64_C(-8949662758380266635),
                            INT64_C( 4701312916269037777), INT64_C(-1461656220613716217)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -577.36), SIMDE_FLOAT64_C(  907.23),
                         SIMDE_FLOAT64_C(  957.37), SIMDE_FLOAT64_C( -359.60),
                         SIMDE_FLOAT64_C( -934.92), SIMDE_FLOAT64_C( -213.75),
                         SIMDE_FLOAT64_C( -657.02), SIMDE_FLOAT64_C(  403.00)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  907.23), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -577.36)) },
    { UINT8_C(131),
      simde_mm512_set_epi64(INT64_C(-2775611318017263858), INT64_C( 7897714815450887445),
                            INT64_C(-2675129847260557604), INT64_C( 2145911307457407401),
                            INT64_C( 3797455296467543827), INT64_C(-3815826294263537782),
                            INT64_C( 2205533861506052469), INT64_C( 3531417307031756813)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  268.99), SIMDE_FLOAT64_C( -842.15),
                         SIMDE_FLOAT64_C( -207.87), SIMDE_FLOAT64_C(  908.84),
                         SIMDE_FLOAT64_C( -765.42), SIMDE_FLOAT64_C( -315.78),
                         SIMDE_FLOAT64_C(  138.83), SIMDE_FLOAT64_C(  -86.06)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -842.15), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -207.87), SIMDE_FLOAT64_C( -207.87)) },
    { UINT8_C(213),
      simde_mm512_set_epi64(INT64_C(-2603844271228681340), INT64_C( 3101493959844818499),
                            INT64_C(-7569746812758465314), INT64_C(  -95001376835728923),
                            INT64_C( 2811174252033921756), INT64_C( 1971701120159461885),
                            INT64_C(-1168609383370522899), INT64_C(-6996433667044410060)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -619.50), SIMDE_FLOAT64_C(  518.12),
                         SIMDE_FLOAT64_C(  952.47), SIMDE_FLOAT64_C( -173.80),
                         SIMDE_FLOAT64_C( -492.61), SIMDE_FLOAT64_C(  487.08),
                         SIMDE_FLOAT64_C(  -68.16), SIMDE_FLOAT64_C(  180.78)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -173.80), SIMDE_FLOAT64_C( -492.61),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  952.47),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  952.47),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -173.80)) },
    { UINT8_C( 71),
      simde_mm512_set_epi64(INT64_C( 7268860797756174523), INT64_C(  684742770982669497),
                            INT64_C(  778252790359918942), INT64_C( 8946221359026744959),
                            INT64_C( 8570432854894274862), INT64_C(-4670296842224865750),
                            INT64_C(-8736438908262001915), INT64_C(-1516874692875012272)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -949.73), SIMDE_FLOAT64_C( -453.25),
                         SIMDE_FLOAT64_C(  280.87), SIMDE_FLOAT64_C( -904.81),
                         SIMDE_FLOAT64_C(  380.83), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C( -236.67), SIMDE_FLOAT64_C( -282.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -236.67),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C(  280.87), SIMDE_FLOAT64_C( -282.31)) },
    { UINT8_C(208),
      simde_mm512_set_epi64(INT64_C(-3323383259847225301), INT64_C( 2001511420457827007),
                            INT64_C( 8280910196874944184), INT64_C( -368934386460614235),
                            INT64_C(-9011857488067354178), INT64_C( 5578921037540219940),
                            INT64_C(-7880186302232587827), INT64_C( 7848707034806784644)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  930.79), SIMDE_FLOAT64_C(  677.41),
                         SIMDE_FLOAT64_C(  111.33), SIMDE_FLOAT64_C( -352.24),
                         SIMDE_FLOAT64_C( -176.75), SIMDE_FLOAT64_C( -479.79),
                         SIMDE_FLOAT64_C( -316.94), SIMDE_FLOAT64_C(  602.83)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -176.75), SIMDE_FLOAT64_C(  930.79),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  111.33),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(212),
      simde_mm512_set_epi64(INT64_C( -831601358278995789), INT64_C(-2800664419916301039),
                            INT64_C( 3280702275774868225), INT64_C(-4735905134864699368),
                            INT64_C( 7051416147935021095), INT64_C(-4824857292892203785),
                            INT64_C( 6286668337562607931), INT64_C( 1432089847019206822)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  346.90), SIMDE_FLOAT64_C(  996.15),
                         SIMDE_FLOAT64_C( -777.05), SIMDE_FLOAT64_C( -607.82),
                         SIMDE_FLOAT64_C(  621.95), SIMDE_FLOAT64_C(  296.47),
                         SIMDE_FLOAT64_C( -116.18), SIMDE_FLOAT64_C( -327.04)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  621.95), SIMDE_FLOAT64_C( -116.18),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -327.04),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  346.90),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_maskz_permutexvar_pd(test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_permutexvar_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i idx;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  936676195), INT32_C( -430989686), INT32_C( -131327474), INT32_C(  910508384),
                            INT32_C( 1148801293), INT32_C(-1204409147), INT32_C( 1922921929), INT32_C( 2087027240),
                            INT32_C( 1221368626), INT32_C(-1114006136), INT32_C( 2023469730), INT32_C(  463308257),
                            INT32_C(-1206798920), INT32_C( -968449396), INT32_C( -580990777), INT32_C( -896508445)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   120.10), SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(  -620.03), SIMDE_FLOAT32_C(   559.81),
                         SIMDE_FLOAT32_C(   185.23), SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   -11.91), SIMDE_FLOAT32_C(   407.56),
                         SIMDE_FLOAT32_C(   355.11), SIMDE_FLOAT32_C(  -787.72), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(  -703.51),
                         SIMDE_FLOAT32_C(  -202.49), SIMDE_FLOAT32_C(  -470.36), SIMDE_FLOAT32_C(   966.37), SIMDE_FLOAT32_C(   135.20)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -202.49), SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(   135.20),
                         SIMDE_FLOAT32_C(  -620.03), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(   -11.91), SIMDE_FLOAT32_C(   407.56),
                         SIMDE_FLOAT32_C(  -470.36), SIMDE_FLOAT32_C(   407.56), SIMDE_FLOAT32_C(  -470.36), SIMDE_FLOAT32_C(   966.37),
                         SIMDE_FLOAT32_C(   407.56), SIMDE_FLOAT32_C(   559.81), SIMDE_FLOAT32_C(   355.11), SIMDE_FLOAT32_C(  -202.49)) },
    { simde_mm512_set_epi32(INT32_C(-1732993162), INT32_C( 1212743926), INT32_C( 1966971402), INT32_C(-1506668774),
                            INT32_C(-1700657265), INT32_C( 1944327234), INT32_C( -355879099), INT32_C(-1588067414),
                            INT32_C(  301696052), INT32_C( 1998339065), INT32_C(-2060809025), INT32_C(-1942156019),
                            INT32_C(  551689125), INT32_C(  669995747), INT32_C(-1196653219), INT32_C( -147816939)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(  -224.13), SIMDE_FLOAT32_C(   633.65), SIMDE_FLOAT32_C(  -834.15),
                         SIMDE_FLOAT32_C(  -157.33), SIMDE_FLOAT32_C(  -819.46), SIMDE_FLOAT32_C(   541.44), SIMDE_FLOAT32_C(   112.81),
                         SIMDE_FLOAT32_C(   -98.08), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(   282.83),
                         SIMDE_FLOAT32_C(  -774.08), SIMDE_FLOAT32_C(   841.24), SIMDE_FLOAT32_C(  -414.07), SIMDE_FLOAT32_C(    79.76)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(  -819.46), SIMDE_FLOAT32_C(  -819.46),
                         SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(   841.24), SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(  -819.46),
                         SIMDE_FLOAT32_C(   282.83), SIMDE_FLOAT32_C(   541.44), SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(   633.65),
                         SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(  -774.08), SIMDE_FLOAT32_C(   633.65), SIMDE_FLOAT32_C(   711.12)) },
    { simde_mm512_set_epi32(INT32_C(-1844524534), INT32_C(  359706932), INT32_C(   21147132), INT32_C(-1205907433),
                            INT32_C(  241660444), INT32_C(-1425169590), INT32_C( 1296561443), INT32_C(-1934442075),
                            INT32_C( 2141890625), INT32_C( 2063982974), INT32_C(-1791266937), INT32_C(-1677757015),
                            INT32_C(-1341587157), INT32_C(   71085124), INT32_C( 1045857655), INT32_C(  563120574)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -179.98), SIMDE_FLOAT32_C(   258.23), SIMDE_FLOAT32_C(   246.22), SIMDE_FLOAT32_C(    97.85),
                         SIMDE_FLOAT32_C(   666.32), SIMDE_FLOAT32_C(   364.80), SIMDE_FLOAT32_C(   759.27), SIMDE_FLOAT32_C(  -524.19),
                         SIMDE_FLOAT32_C(  -726.51), SIMDE_FLOAT32_C(   381.71), SIMDE_FLOAT32_C(   819.12), SIMDE_FLOAT32_C(   145.28),
                         SIMDE_FLOAT32_C(   -99.37), SIMDE_FLOAT32_C(  -151.02), SIMDE_FLOAT32_C(   551.65), SIMDE_FLOAT32_C(   155.58)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   364.80), SIMDE_FLOAT32_C(   145.28), SIMDE_FLOAT32_C(    97.85), SIMDE_FLOAT32_C(  -726.51),
                         SIMDE_FLOAT32_C(    97.85), SIMDE_FLOAT32_C(   364.80), SIMDE_FLOAT32_C(   -99.37), SIMDE_FLOAT32_C(   819.12),
                         SIMDE_FLOAT32_C(   551.65), SIMDE_FLOAT32_C(   258.23), SIMDE_FLOAT32_C(  -726.51), SIMDE_FLOAT32_C(   759.27),
                         SIMDE_FLOAT32_C(   666.32), SIMDE_FLOAT32_C(   145.28), SIMDE_FLOAT32_C(  -726.51), SIMDE_FLOAT32_C(   258.23)) },
    { simde_mm512_set_epi32(INT32_C(-1600993635), INT32_C( 1692797667), INT32_C( -524624106), INT32_C( -196896874),
                            INT32_C( 1365949044), INT32_C( 1838002887), INT32_C( -452898509), INT32_C( 1408911553),
                            INT32_C(-1407150071), INT32_C(  -82352116), INT32_C( -745337283), INT32_C( -527368953),
                            INT32_C(-1750389986), INT32_C( 1217697098), INT32_C( 1169663592), INT32_C(-1794175196)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -985.32), SIMDE_FLOAT32_C(   485.76), SIMDE_FLOAT32_C(   234.60), SIMDE_FLOAT32_C(   786.03),
                         SIMDE_FLOAT32_C(   859.59), SIMDE_FLOAT32_C(   489.95), SIMDE_FLOAT32_C(  -409.35), SIMDE_FLOAT32_C(   796.52),
                         SIMDE_FLOAT32_C(  -846.10), SIMDE_FLOAT32_C(  -248.07), SIMDE_FLOAT32_C(  -411.92), SIMDE_FLOAT32_C(   -88.91),
                         SIMDE_FLOAT32_C(   481.68), SIMDE_FLOAT32_C(   170.00), SIMDE_FLOAT32_C(  -341.91), SIMDE_FLOAT32_C(   366.57)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   234.60), SIMDE_FLOAT32_C(   481.68), SIMDE_FLOAT32_C(  -248.07), SIMDE_FLOAT32_C(  -248.07),
                         SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(  -846.10), SIMDE_FLOAT32_C(   481.68), SIMDE_FLOAT32_C(  -341.91),
                         SIMDE_FLOAT32_C(  -409.35), SIMDE_FLOAT32_C(   786.03), SIMDE_FLOAT32_C(   234.60), SIMDE_FLOAT32_C(  -846.10),
                         SIMDE_FLOAT32_C(   485.76), SIMDE_FLOAT32_C(   489.95), SIMDE_FLOAT32_C(   796.52), SIMDE_FLOAT32_C(   -88.91)) },
    { simde_mm512_set_epi32(INT32_C(-1723897302), INT32_C(-1378607382), INT32_C(-1399746280), INT32_C(   55039129),
                            INT32_C( -614650529), INT32_C( 1411406194), INT32_C(  789645610), INT32_C(  647523062),
                            INT32_C( 1326675104), INT32_C(-1833621116), INT32_C( 1459731687), INT32_C(-1374295064),
                            INT32_C( 1719685048), INT32_C(-1859395493), INT32_C(  506068853), INT32_C( 1338183771)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   156.66), SIMDE_FLOAT32_C(   658.18), SIMDE_FLOAT32_C(   198.89), SIMDE_FLOAT32_C(  -330.38),
                         SIMDE_FLOAT32_C(  -766.40), SIMDE_FLOAT32_C(  -462.89), SIMDE_FLOAT32_C(  -495.88), SIMDE_FLOAT32_C(  -905.06),
                         SIMDE_FLOAT32_C(  -794.42), SIMDE_FLOAT32_C(   266.49), SIMDE_FLOAT32_C(  -263.27), SIMDE_FLOAT32_C(  -537.47),
                         SIMDE_FLOAT32_C(    74.85), SIMDE_FLOAT32_C(  -705.33), SIMDE_FLOAT32_C(   127.81), SIMDE_FLOAT32_C(   699.62)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -462.89), SIMDE_FLOAT32_C(  -462.89), SIMDE_FLOAT32_C(  -905.06), SIMDE_FLOAT32_C(  -495.88),
                         SIMDE_FLOAT32_C(   156.66), SIMDE_FLOAT32_C(  -705.33), SIMDE_FLOAT32_C(  -462.89), SIMDE_FLOAT32_C(   266.49),
                         SIMDE_FLOAT32_C(   699.62), SIMDE_FLOAT32_C(  -537.47), SIMDE_FLOAT32_C(  -794.42), SIMDE_FLOAT32_C(  -905.06),
                         SIMDE_FLOAT32_C(  -905.06), SIMDE_FLOAT32_C(  -766.40), SIMDE_FLOAT32_C(  -263.27), SIMDE_FLOAT32_C(  -766.40)) },
    { simde_mm512_set_epi32(INT32_C( 2006733779), INT32_C(-1344310054), INT32_C( -316328405), INT32_C(  365448438),
                            INT32_C(-1467004247), INT32_C( 1348423181), INT32_C(-1495578328), INT32_C(  657519930),
                            INT32_C(-1822795869), INT32_C( -508699764), INT32_C(-2109145696), INT32_C( -433815627),
                            INT32_C(-1544129190), INT32_C(-1521382934), INT32_C(   72732953), INT32_C( 1946881855)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -747.31), SIMDE_FLOAT32_C(   206.83), SIMDE_FLOAT32_C(   -77.03), SIMDE_FLOAT32_C(  -852.95),
                         SIMDE_FLOAT32_C(   918.21), SIMDE_FLOAT32_C(  -446.06), SIMDE_FLOAT32_C(   363.23), SIMDE_FLOAT32_C(  -141.96),
                         SIMDE_FLOAT32_C(    98.64), SIMDE_FLOAT32_C(  -943.22), SIMDE_FLOAT32_C(  -111.23), SIMDE_FLOAT32_C(   515.15),
                         SIMDE_FLOAT32_C(  -161.39), SIMDE_FLOAT32_C(   209.66), SIMDE_FLOAT32_C(   207.66), SIMDE_FLOAT32_C(  -218.56)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -161.39), SIMDE_FLOAT32_C(  -446.06), SIMDE_FLOAT32_C(   918.21), SIMDE_FLOAT32_C(  -943.22),
                         SIMDE_FLOAT32_C(   363.23), SIMDE_FLOAT32_C(   -77.03), SIMDE_FLOAT32_C(  -141.96), SIMDE_FLOAT32_C(  -446.06),
                         SIMDE_FLOAT32_C(  -161.39), SIMDE_FLOAT32_C(  -852.95), SIMDE_FLOAT32_C(  -218.56), SIMDE_FLOAT32_C(  -111.23),
                         SIMDE_FLOAT32_C(  -446.06), SIMDE_FLOAT32_C(  -446.06), SIMDE_FLOAT32_C(   363.23), SIMDE_FLOAT32_C(  -747.31)) },
    { simde_mm512_set_epi32(INT32_C(-1976311223), INT32_C(-1733873773), INT32_C(  511400049), INT32_C(  500426498),
                            INT32_C( -644784401), INT32_C( 1570198900), INT32_C( 1945626784), INT32_C(-1332251479),
                            INT32_C( -316629202), INT32_C( -236250164), INT32_C(  893952031), INT32_C( -476733654),
                            INT32_C(-2008951329), INT32_C(-1854469611), INT32_C( -862339611), INT32_C(  546668760)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   366.70), SIMDE_FLOAT32_C(  -276.00), SIMDE_FLOAT32_C(   615.81), SIMDE_FLOAT32_C(  -317.53),
                         SIMDE_FLOAT32_C(  -673.63), SIMDE_FLOAT32_C(  -723.48), SIMDE_FLOAT32_C(   832.55), SIMDE_FLOAT32_C(  -792.04),
                         SIMDE_FLOAT32_C(   260.08), SIMDE_FLOAT32_C(  -284.98), SIMDE_FLOAT32_C(  -412.45), SIMDE_FLOAT32_C(   906.86),
                         SIMDE_FLOAT32_C(   245.05), SIMDE_FLOAT32_C(  -798.29), SIMDE_FLOAT32_C(  -913.68), SIMDE_FLOAT32_C(   122.95)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   832.55), SIMDE_FLOAT32_C(   245.05), SIMDE_FLOAT32_C(  -913.68), SIMDE_FLOAT32_C(  -798.29),
                         SIMDE_FLOAT32_C(   366.70), SIMDE_FLOAT32_C(   906.86), SIMDE_FLOAT32_C(   122.95), SIMDE_FLOAT32_C(   832.55),
                         SIMDE_FLOAT32_C(  -276.00), SIMDE_FLOAT32_C(  -317.53), SIMDE_FLOAT32_C(   366.70), SIMDE_FLOAT32_C(  -723.48),
                         SIMDE_FLOAT32_C(   366.70), SIMDE_FLOAT32_C(  -412.45), SIMDE_FLOAT32_C(  -412.45), SIMDE_FLOAT32_C(  -792.04)) },
    { simde_mm512_set_epi32(INT32_C( 1809884012), INT32_C( -191206140), INT32_C( -553702639), INT32_C(-1800209842),
                            INT32_C(  721509385), INT32_C(   -3110338), INT32_C(  629848436), INT32_C( 1833821522),
                            INT32_C( 1870762521), INT32_C( 1138301165), INT32_C(  499100111), INT32_C( -583483550),
                            INT32_C(  449841541), INT32_C( 1832272682), INT32_C( -100358742), INT32_C( 1797905164)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -239.16), SIMDE_FLOAT32_C(   579.20), SIMDE_FLOAT32_C(  -204.61), SIMDE_FLOAT32_C(  -391.63),
                         SIMDE_FLOAT32_C(   200.64), SIMDE_FLOAT32_C(   335.63), SIMDE_FLOAT32_C(  -634.66), SIMDE_FLOAT32_C(   738.93),
                         SIMDE_FLOAT32_C(   607.08), SIMDE_FLOAT32_C(   439.69), SIMDE_FLOAT32_C(  -668.91), SIMDE_FLOAT32_C(   930.40),
                         SIMDE_FLOAT32_C(  -886.74), SIMDE_FLOAT32_C(   273.66), SIMDE_FLOAT32_C(  -214.28), SIMDE_FLOAT32_C(   892.54)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -391.63), SIMDE_FLOAT32_C(   930.40), SIMDE_FLOAT32_C(  -214.28), SIMDE_FLOAT32_C(   579.20),
                         SIMDE_FLOAT32_C(  -634.66), SIMDE_FLOAT32_C(   579.20), SIMDE_FLOAT32_C(   930.40), SIMDE_FLOAT32_C(   273.66),
                         SIMDE_FLOAT32_C(  -634.66), SIMDE_FLOAT32_C(  -204.61), SIMDE_FLOAT32_C(  -239.16), SIMDE_FLOAT32_C(   273.66),
                         SIMDE_FLOAT32_C(  -668.91), SIMDE_FLOAT32_C(   335.63), SIMDE_FLOAT32_C(   335.63), SIMDE_FLOAT32_C(  -391.63)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_permutexvar_ps(test_vec[i].idx, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
 }

  return 0;
}

static int
test_simde_mm512_mask_permutexvar_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512i idx;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -126.54), SIMDE_FLOAT32_C(   486.54), SIMDE_FLOAT32_C(   115.89), SIMDE_FLOAT32_C(   387.13),
                         SIMDE_FLOAT32_C(  -862.52), SIMDE_FLOAT32_C(  -954.44), SIMDE_FLOAT32_C(   -62.35), SIMDE_FLOAT32_C(  -928.05),
                         SIMDE_FLOAT32_C(   553.71), SIMDE_FLOAT32_C(   241.48), SIMDE_FLOAT32_C(  -508.93), SIMDE_FLOAT32_C(   882.19),
                         SIMDE_FLOAT32_C(   -62.25), SIMDE_FLOAT32_C(   746.09), SIMDE_FLOAT32_C(   695.90), SIMDE_FLOAT32_C(   211.82)),
      UINT16_C(16928),
      simde_mm512_set_epi32(INT32_C(-1969848041), INT32_C(  986227924), INT32_C( 1136615869), INT32_C(-1528801648),
                            INT32_C( -812889932), INT32_C(-1855240790), INT32_C( 1844683884), INT32_C( -586741017),
                            INT32_C( 1867360941), INT32_C( -991976637), INT32_C( 1849718349), INT32_C( 1716834208),
                            INT32_C(-1194054110), INT32_C( 2134562344), INT32_C(-1402914588), INT32_C( -545264918)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -642.79), SIMDE_FLOAT32_C(    80.95), SIMDE_FLOAT32_C(   263.76), SIMDE_FLOAT32_C(  -849.20),
                         SIMDE_FLOAT32_C(   701.20), SIMDE_FLOAT32_C(  -187.10), SIMDE_FLOAT32_C(  -193.72), SIMDE_FLOAT32_C(  -482.55),
                         SIMDE_FLOAT32_C(   133.18), SIMDE_FLOAT32_C(  -425.61), SIMDE_FLOAT32_C(   934.88), SIMDE_FLOAT32_C(    29.19),
                         SIMDE_FLOAT32_C(  -215.85), SIMDE_FLOAT32_C(  -948.93), SIMDE_FLOAT32_C(  -669.86), SIMDE_FLOAT32_C(  -774.43)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -126.54), SIMDE_FLOAT32_C(    29.19), SIMDE_FLOAT32_C(   115.89), SIMDE_FLOAT32_C(   387.13),
                         SIMDE_FLOAT32_C(  -862.52), SIMDE_FLOAT32_C(  -954.44), SIMDE_FLOAT32_C(  -849.20), SIMDE_FLOAT32_C(  -928.05),
                         SIMDE_FLOAT32_C(   553.71), SIMDE_FLOAT32_C(   241.48), SIMDE_FLOAT32_C(   263.76), SIMDE_FLOAT32_C(   882.19),
                         SIMDE_FLOAT32_C(   -62.25), SIMDE_FLOAT32_C(   746.09), SIMDE_FLOAT32_C(   695.90), SIMDE_FLOAT32_C(   211.82)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   151.66), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(  -269.77), SIMDE_FLOAT32_C(   614.76),
                         SIMDE_FLOAT32_C(  -133.17), SIMDE_FLOAT32_C(  -180.83), SIMDE_FLOAT32_C(   194.81), SIMDE_FLOAT32_C(    42.31),
                         SIMDE_FLOAT32_C(   374.34), SIMDE_FLOAT32_C(  -656.44), SIMDE_FLOAT32_C(   548.30), SIMDE_FLOAT32_C(   222.71),
                         SIMDE_FLOAT32_C(  -984.87), SIMDE_FLOAT32_C(   443.22), SIMDE_FLOAT32_C(   673.00), SIMDE_FLOAT32_C(  -157.35)),
      UINT16_C(35439),
      simde_mm512_set_epi32(INT32_C( 1227892331), INT32_C(-1027676412), INT32_C(  359651495), INT32_C( 1118790944),
                            INT32_C(   91682217), INT32_C(-2133769799), INT32_C(-1769360502), INT32_C( -926475819),
                            INT32_C( 1573948348), INT32_C(-1072703852), INT32_C( -613174427), INT32_C( 2078566978),
                            INT32_C(-1129401521), INT32_C(-1989448771), INT32_C(-2043876227), INT32_C( 1692040296)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    56.76), SIMDE_FLOAT32_C(   152.42), SIMDE_FLOAT32_C(   481.26), SIMDE_FLOAT32_C(   801.28),
                         SIMDE_FLOAT32_C(   636.86), SIMDE_FLOAT32_C(   909.80), SIMDE_FLOAT32_C(   703.56), SIMDE_FLOAT32_C(   542.79),
                         SIMDE_FLOAT32_C(  -247.58), SIMDE_FLOAT32_C(  -687.87), SIMDE_FLOAT32_C(  -260.04), SIMDE_FLOAT32_C(  -901.34),
                         SIMDE_FLOAT32_C(  -209.58), SIMDE_FLOAT32_C(   661.31), SIMDE_FLOAT32_C(   996.67), SIMDE_FLOAT32_C(  -590.89)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   636.86), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(  -269.77), SIMDE_FLOAT32_C(   614.76),
                         SIMDE_FLOAT32_C(   703.56), SIMDE_FLOAT32_C(  -180.83), SIMDE_FLOAT32_C(   909.80), SIMDE_FLOAT32_C(    42.31),
                         SIMDE_FLOAT32_C(   374.34), SIMDE_FLOAT32_C(  -901.34), SIMDE_FLOAT32_C(  -260.04), SIMDE_FLOAT32_C(   222.71),
                         SIMDE_FLOAT32_C(    56.76), SIMDE_FLOAT32_C(   481.26), SIMDE_FLOAT32_C(   481.26), SIMDE_FLOAT32_C(   542.79)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -750.66), SIMDE_FLOAT32_C(  -458.79), SIMDE_FLOAT32_C(   673.71), SIMDE_FLOAT32_C(   151.27),
                         SIMDE_FLOAT32_C(   301.16), SIMDE_FLOAT32_C(   -17.04), SIMDE_FLOAT32_C(  -751.47), SIMDE_FLOAT32_C(   -39.79),
                         SIMDE_FLOAT32_C(  -478.79), SIMDE_FLOAT32_C(  -874.74), SIMDE_FLOAT32_C(    82.59), SIMDE_FLOAT32_C(   758.78),
                         SIMDE_FLOAT32_C(  -838.81), SIMDE_FLOAT32_C(  -454.98), SIMDE_FLOAT32_C(     5.20), SIMDE_FLOAT32_C(   523.36)),
      UINT16_C(36222),
      simde_mm512_set_epi32(INT32_C( 2006445721), INT32_C( 1432323599), INT32_C(  475511895), INT32_C( -589436639),
                            INT32_C(-2145227731), INT32_C(  339016017), INT32_C( 1108425812), INT32_C(-1667703848),
                            INT32_C( 1002175747), INT32_C( -280079864), INT32_C(   92142797), INT32_C( 1809366615),
                            INT32_C(-1928845693), INT32_C(-1066128967), INT32_C(-1068022325), INT32_C( -129380427)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -1.31), SIMDE_FLOAT32_C(   116.19), SIMDE_FLOAT32_C(   258.15), SIMDE_FLOAT32_C(  -933.38),
                         SIMDE_FLOAT32_C(  -512.69), SIMDE_FLOAT32_C(  -147.18), SIMDE_FLOAT32_C(   595.37), SIMDE_FLOAT32_C(   114.40),
                         SIMDE_FLOAT32_C(   621.76), SIMDE_FLOAT32_C(  -918.69), SIMDE_FLOAT32_C(  -162.22), SIMDE_FLOAT32_C(  -310.44),
                         SIMDE_FLOAT32_C(  -814.01), SIMDE_FLOAT32_C(  -464.51), SIMDE_FLOAT32_C(  -491.30), SIMDE_FLOAT32_C(  -261.98)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   595.37), SIMDE_FLOAT32_C(  -458.79), SIMDE_FLOAT32_C(   673.71), SIMDE_FLOAT32_C(   151.27),
                         SIMDE_FLOAT32_C(   258.15), SIMDE_FLOAT32_C(  -491.30), SIMDE_FLOAT32_C(  -751.47), SIMDE_FLOAT32_C(   114.40),
                         SIMDE_FLOAT32_C(  -478.79), SIMDE_FLOAT32_C(   114.40), SIMDE_FLOAT32_C(   258.15), SIMDE_FLOAT32_C(   621.76),
                         SIMDE_FLOAT32_C(  -814.01), SIMDE_FLOAT32_C(   595.37), SIMDE_FLOAT32_C(  -512.69), SIMDE_FLOAT32_C(   523.36)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -625.36), SIMDE_FLOAT32_C(   576.25), SIMDE_FLOAT32_C(  -491.19), SIMDE_FLOAT32_C(    36.67),
                         SIMDE_FLOAT32_C(   144.75), SIMDE_FLOAT32_C(  -337.24), SIMDE_FLOAT32_C(   923.33), SIMDE_FLOAT32_C(  -171.10),
                         SIMDE_FLOAT32_C(  -499.67), SIMDE_FLOAT32_C(  -489.63), SIMDE_FLOAT32_C(  -565.60), SIMDE_FLOAT32_C(   521.68),
                         SIMDE_FLOAT32_C(  -663.69), SIMDE_FLOAT32_C(   977.71), SIMDE_FLOAT32_C(   -68.19), SIMDE_FLOAT32_C(   621.30)),
      UINT16_C(37636),
      simde_mm512_set_epi32(INT32_C(-1855337133), INT32_C( -145365176), INT32_C( -898457281), INT32_C(-1771294387),
                            INT32_C( 1891153968), INT32_C( 1228490057), INT32_C( 1633049538), INT32_C(-1958946575),
                            INT32_C( 1185839426), INT32_C( -155257689), INT32_C( -468686279), INT32_C(  158817819),
                            INT32_C(-1241996695), INT32_C( 1151388076), INT32_C( 1858464278), INT32_C( 1759636985)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -890.16), SIMDE_FLOAT32_C(   541.77), SIMDE_FLOAT32_C(  -229.54), SIMDE_FLOAT32_C(  -351.71),
                         SIMDE_FLOAT32_C(  -174.86), SIMDE_FLOAT32_C(  -589.39), SIMDE_FLOAT32_C(   568.96), SIMDE_FLOAT32_C(   728.23),
                         SIMDE_FLOAT32_C(   762.97), SIMDE_FLOAT32_C(  -567.80), SIMDE_FLOAT32_C(  -772.48), SIMDE_FLOAT32_C(   342.73),
                         SIMDE_FLOAT32_C(   146.72), SIMDE_FLOAT32_C(  -732.03), SIMDE_FLOAT32_C(   502.49), SIMDE_FLOAT32_C(   705.12)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   146.72), SIMDE_FLOAT32_C(   576.25), SIMDE_FLOAT32_C(  -491.19), SIMDE_FLOAT32_C(  -229.54),
                         SIMDE_FLOAT32_C(   144.75), SIMDE_FLOAT32_C(  -337.24), SIMDE_FLOAT32_C(  -732.03), SIMDE_FLOAT32_C(   502.49),
                         SIMDE_FLOAT32_C(  -499.67), SIMDE_FLOAT32_C(  -489.63), SIMDE_FLOAT32_C(  -565.60), SIMDE_FLOAT32_C(   521.68),
                         SIMDE_FLOAT32_C(  -663.69), SIMDE_FLOAT32_C(  -351.71), SIMDE_FLOAT32_C(   -68.19), SIMDE_FLOAT32_C(   621.30)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   338.68), SIMDE_FLOAT32_C(   -26.37), SIMDE_FLOAT32_C(   688.52), SIMDE_FLOAT32_C(   895.19),
                         SIMDE_FLOAT32_C(  -756.53), SIMDE_FLOAT32_C(  -324.15), SIMDE_FLOAT32_C(  -353.65), SIMDE_FLOAT32_C(    29.09),
                         SIMDE_FLOAT32_C(   167.64), SIMDE_FLOAT32_C(   -10.77), SIMDE_FLOAT32_C(  -916.15), SIMDE_FLOAT32_C(  -222.63),
                         SIMDE_FLOAT32_C(   671.28), SIMDE_FLOAT32_C(   830.16), SIMDE_FLOAT32_C(   152.94), SIMDE_FLOAT32_C(   442.97)),
      UINT16_C( 7327),
      simde_mm512_set_epi32(INT32_C(-1635146322), INT32_C(-1549527285), INT32_C( -767681217), INT32_C(  200060997),
                            INT32_C( 1897816859), INT32_C(  -33590828), INT32_C( 1228456059), INT32_C(  363372158),
                            INT32_C(-1880249713), INT32_C(  563834696), INT32_C(  298711594), INT32_C(  675952191),
                            INT32_C(   93229580), INT32_C(-1903862955), INT32_C(  927507330), INT32_C(  735163498)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -225.51), SIMDE_FLOAT32_C(  -481.64), SIMDE_FLOAT32_C(  -505.22), SIMDE_FLOAT32_C(  -701.32),
                         SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(  -981.96), SIMDE_FLOAT32_C(   509.57), SIMDE_FLOAT32_C(  -514.74),
                         SIMDE_FLOAT32_C(  -731.84), SIMDE_FLOAT32_C(  -363.17), SIMDE_FLOAT32_C(   622.22), SIMDE_FLOAT32_C(   459.46),
                         SIMDE_FLOAT32_C(  -421.94), SIMDE_FLOAT32_C(  -833.19), SIMDE_FLOAT32_C(    52.45), SIMDE_FLOAT32_C(  -445.99)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   338.68), SIMDE_FLOAT32_C(   -26.37), SIMDE_FLOAT32_C(   688.52), SIMDE_FLOAT32_C(   622.22),
                         SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(   459.46), SIMDE_FLOAT32_C(  -353.65), SIMDE_FLOAT32_C(    29.09),
                         SIMDE_FLOAT32_C(  -225.51), SIMDE_FLOAT32_C(   -10.77), SIMDE_FLOAT32_C(  -916.15), SIMDE_FLOAT32_C(  -225.51),
                         SIMDE_FLOAT32_C(  -701.32), SIMDE_FLOAT32_C(   622.22), SIMDE_FLOAT32_C(  -833.19), SIMDE_FLOAT32_C(  -981.96)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   548.33), SIMDE_FLOAT32_C(   187.27), SIMDE_FLOAT32_C(    96.63), SIMDE_FLOAT32_C(   273.45),
                         SIMDE_FLOAT32_C(  -676.75), SIMDE_FLOAT32_C(   630.01), SIMDE_FLOAT32_C(  -273.70), SIMDE_FLOAT32_C(   595.19),
                         SIMDE_FLOAT32_C(  -827.09), SIMDE_FLOAT32_C(    -9.74), SIMDE_FLOAT32_C(   348.50), SIMDE_FLOAT32_C(  -287.28),
                         SIMDE_FLOAT32_C(  -214.23), SIMDE_FLOAT32_C(   252.31), SIMDE_FLOAT32_C(  -162.09), SIMDE_FLOAT32_C(   125.35)),
      UINT16_C(47269),
      simde_mm512_set_epi32(INT32_C(-1058548029), INT32_C( 1236526607), INT32_C( -254770193), INT32_C(   93180276),
                            INT32_C( 1350898601), INT32_C( 1804650502), INT32_C(  425106003), INT32_C( 1132369672),
                            INT32_C(-1843449231), INT32_C( 1221695547), INT32_C( -627121059), INT32_C(  837413942),
                            INT32_C(  535626003), INT32_C(-2017749884), INT32_C(-1177177868), INT32_C(-1219767649)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   707.49), SIMDE_FLOAT32_C(   251.70), SIMDE_FLOAT32_C(  -353.77), SIMDE_FLOAT32_C(   201.00),
                         SIMDE_FLOAT32_C(   254.86), SIMDE_FLOAT32_C(  -348.78), SIMDE_FLOAT32_C(   550.78), SIMDE_FLOAT32_C(  -277.90),
                         SIMDE_FLOAT32_C(  -324.13), SIMDE_FLOAT32_C(  -996.73), SIMDE_FLOAT32_C(  -839.66), SIMDE_FLOAT32_C(  -878.81),
                         SIMDE_FLOAT32_C(   809.40), SIMDE_FLOAT32_C(  -567.81), SIMDE_FLOAT32_C(   341.97), SIMDE_FLOAT32_C(   173.53)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   809.40), SIMDE_FLOAT32_C(   187.27), SIMDE_FLOAT32_C(   707.49), SIMDE_FLOAT32_C(  -878.81),
                         SIMDE_FLOAT32_C(   550.78), SIMDE_FLOAT32_C(   630.01), SIMDE_FLOAT32_C(  -273.70), SIMDE_FLOAT32_C(   595.19),
                         SIMDE_FLOAT32_C(   341.97), SIMDE_FLOAT32_C(    -9.74), SIMDE_FLOAT32_C(  -353.77), SIMDE_FLOAT32_C(  -287.28),
                         SIMDE_FLOAT32_C(  -214.23), SIMDE_FLOAT32_C(  -878.81), SIMDE_FLOAT32_C(  -162.09), SIMDE_FLOAT32_C(   707.49)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -667.18), SIMDE_FLOAT32_C(    47.15), SIMDE_FLOAT32_C(   840.15), SIMDE_FLOAT32_C(  -252.88),
                         SIMDE_FLOAT32_C(  -918.58), SIMDE_FLOAT32_C(  -332.91), SIMDE_FLOAT32_C(   -82.80), SIMDE_FLOAT32_C(   317.13),
                         SIMDE_FLOAT32_C(  -364.09), SIMDE_FLOAT32_C(  -815.93), SIMDE_FLOAT32_C(  -526.38), SIMDE_FLOAT32_C(   780.77),
                         SIMDE_FLOAT32_C(   785.63), SIMDE_FLOAT32_C(  -266.51), SIMDE_FLOAT32_C(   617.69), SIMDE_FLOAT32_C(  -648.38)),
      UINT16_C( 5176),
      simde_mm512_set_epi32(INT32_C( -812272178), INT32_C( 1938172163), INT32_C(-1629887879), INT32_C( 1699159582),
                            INT32_C( 1760153584), INT32_C(  448749626), INT32_C( 1866295090), INT32_C( 1060092543),
                            INT32_C(  607878771), INT32_C( 1797306818), INT32_C(  547150787), INT32_C( -708809478),
                            INT32_C( 1892985133), INT32_C(  766652099), INT32_C( 2132386901), INT32_C(  -87942209)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -617.36), SIMDE_FLOAT32_C(   242.43), SIMDE_FLOAT32_C(  -957.92), SIMDE_FLOAT32_C(  -328.75),
                         SIMDE_FLOAT32_C(  -790.98), SIMDE_FLOAT32_C(  -291.92), SIMDE_FLOAT32_C(   890.91), SIMDE_FLOAT32_C(   431.01),
                         SIMDE_FLOAT32_C(  -726.89), SIMDE_FLOAT32_C(   279.78), SIMDE_FLOAT32_C(  -463.41), SIMDE_FLOAT32_C(  -367.48),
                         SIMDE_FLOAT32_C(  -111.74), SIMDE_FLOAT32_C(  -359.87), SIMDE_FLOAT32_C(  -442.32), SIMDE_FLOAT32_C(  -340.55)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -667.18), SIMDE_FLOAT32_C(    47.15), SIMDE_FLOAT32_C(   840.15), SIMDE_FLOAT32_C(   242.43),
                         SIMDE_FLOAT32_C(  -918.58), SIMDE_FLOAT32_C(  -291.92), SIMDE_FLOAT32_C(   -82.80), SIMDE_FLOAT32_C(   317.13),
                         SIMDE_FLOAT32_C(  -364.09), SIMDE_FLOAT32_C(  -815.93), SIMDE_FLOAT32_C(  -111.74), SIMDE_FLOAT32_C(  -291.92),
                         SIMDE_FLOAT32_C(  -957.92), SIMDE_FLOAT32_C(  -266.51), SIMDE_FLOAT32_C(   617.69), SIMDE_FLOAT32_C(  -648.38)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   284.58), SIMDE_FLOAT32_C(   746.63), SIMDE_FLOAT32_C(   125.59), SIMDE_FLOAT32_C(     4.12),
                         SIMDE_FLOAT32_C(  -328.28), SIMDE_FLOAT32_C(   935.21), SIMDE_FLOAT32_C(  -572.72), SIMDE_FLOAT32_C(  -282.68),
                         SIMDE_FLOAT32_C(  -535.09), SIMDE_FLOAT32_C(  -455.20), SIMDE_FLOAT32_C(   284.53), SIMDE_FLOAT32_C(  -643.06),
                         SIMDE_FLOAT32_C(  -951.05), SIMDE_FLOAT32_C(  -691.81), SIMDE_FLOAT32_C(   546.43), SIMDE_FLOAT32_C(  -886.61)),
      UINT16_C( 9849),
      simde_mm512_set_epi32(INT32_C(  659357217), INT32_C(  516445967), INT32_C(-1793934445), INT32_C( -751346082),
                            INT32_C( 1615640988), INT32_C(-2047699786), INT32_C(  407764025), INT32_C( -531318026),
                            INT32_C( 2098775830), INT32_C(-1132806848), INT32_C(  515968910), INT32_C(  502727224),
                            INT32_C( -356346062), INT32_C(   26000082), INT32_C( -122568662), INT32_C( -797533991)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -159.63), SIMDE_FLOAT32_C(  -112.82), SIMDE_FLOAT32_C(   609.39), SIMDE_FLOAT32_C(   941.33),
                         SIMDE_FLOAT32_C(  -858.59), SIMDE_FLOAT32_C(  -584.34), SIMDE_FLOAT32_C(   842.06), SIMDE_FLOAT32_C(  -503.14),
                         SIMDE_FLOAT32_C(  -897.65), SIMDE_FLOAT32_C(  -249.26), SIMDE_FLOAT32_C(   159.94), SIMDE_FLOAT32_C(  -741.72),
                         SIMDE_FLOAT32_C(   417.02), SIMDE_FLOAT32_C(  -743.17), SIMDE_FLOAT32_C(  -364.29), SIMDE_FLOAT32_C(   495.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   284.58), SIMDE_FLOAT32_C(   746.63), SIMDE_FLOAT32_C(   417.02), SIMDE_FLOAT32_C(     4.12),
                         SIMDE_FLOAT32_C(  -328.28), SIMDE_FLOAT32_C(  -249.26), SIMDE_FLOAT32_C(   842.06), SIMDE_FLOAT32_C(  -282.68),
                         SIMDE_FLOAT32_C(  -535.09), SIMDE_FLOAT32_C(   495.38), SIMDE_FLOAT32_C(  -112.82), SIMDE_FLOAT32_C(  -503.14),
                         SIMDE_FLOAT32_C(  -743.17), SIMDE_FLOAT32_C(  -691.81), SIMDE_FLOAT32_C(   546.43), SIMDE_FLOAT32_C(   842.06)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_permutexvar_ps(test_vec[i].src, test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
 }

  return 0;
}

static int
test_simde_mm512_maskz_permutexvar_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i idx;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { UINT16_C(21335),
      simde_mm512_set_epi32(INT32_C(  951544639), INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126),
                            INT32_C(-1306064352), INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562),
                            INT32_C( 1443901717), INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932),
                            INT32_C(-1302383354), INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   483.08), SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(   232.04), SIMDE_FLOAT32_C(   -43.35),
                         SIMDE_FLOAT32_C(   774.81), SIMDE_FLOAT32_C(   309.91), SIMDE_FLOAT32_C(  -599.01), SIMDE_FLOAT32_C(   846.15),
                         SIMDE_FLOAT32_C(    69.04), SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(  -860.98),
                         SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(  -839.80), SIMDE_FLOAT32_C(   128.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   903.50),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   483.08), SIMDE_FLOAT32_C(   309.91),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -860.98),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(   483.08), SIMDE_FLOAT32_C(    69.04)) },
    { UINT16_C(33181),
      simde_mm512_set_epi32(INT32_C(  353198331), INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373),
                            INT32_C( -695949043), INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093),
                            INT32_C(-2045280751), INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336),
                            INT32_C(  564965997), INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -198.67), SIMDE_FLOAT32_C(   337.35), SIMDE_FLOAT32_C(   447.98), SIMDE_FLOAT32_C(  -278.32),
                         SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(  -744.41), SIMDE_FLOAT32_C(   717.83), SIMDE_FLOAT32_C(    39.32),
                         SIMDE_FLOAT32_C(  -489.88), SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(   -37.49), SIMDE_FLOAT32_C(  -490.28),
                         SIMDE_FLOAT32_C(  -373.66), SIMDE_FLOAT32_C(   841.53), SIMDE_FLOAT32_C(  -292.35), SIMDE_FLOAT32_C(   526.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -373.66),
                         SIMDE_FLOAT32_C(  -292.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   526.21),
                         SIMDE_FLOAT32_C(   447.98), SIMDE_FLOAT32_C(  -744.41), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -37.49)) },
    { UINT16_C(55883),
      simde_mm512_set_epi32(INT32_C( -329275629), INT32_C( -888441293), INT32_C( -707551350), INT32_C(  513515868),
                            INT32_C(-1825967755), INT32_C(  822222164), INT32_C(-1689559027), INT32_C(  533478787),
                            INT32_C(  907615417), INT32_C( -199229058), INT32_C(  -91537812), INT32_C( 1375258232),
                            INT32_C(  139748399), INT32_C( 1688468565), INT32_C(  736544549), INT32_C(-1282057552)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -842.15), SIMDE_FLOAT32_C(  -207.87), SIMDE_FLOAT32_C(   908.84), SIMDE_FLOAT32_C(  -765.42),
                         SIMDE_FLOAT32_C(  -315.78), SIMDE_FLOAT32_C(   138.83), SIMDE_FLOAT32_C(   -86.06), SIMDE_FLOAT32_C(   699.07),
                         SIMDE_FLOAT32_C(  -413.85), SIMDE_FLOAT32_C(  -143.73), SIMDE_FLOAT32_C(   752.26), SIMDE_FLOAT32_C(   709.96),
                         SIMDE_FLOAT32_C(   609.29), SIMDE_FLOAT32_C(  -767.34), SIMDE_FLOAT32_C(   878.85), SIMDE_FLOAT32_C(  -588.28)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   609.29), SIMDE_FLOAT32_C(   609.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -765.42),
                         SIMDE_FLOAT32_C(   752.26), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   908.84), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -207.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -842.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   752.26), SIMDE_FLOAT32_C(  -588.28)) },
    { UINT16_C(18199),
      simde_mm512_set_epi32(INT32_C( 1526367108), INT32_C(  722122834), INT32_C( -174985661), INT32_C(-1762469023),
                            INT32_C( 1239606494), INT32_C(  -22119232), INT32_C( 1216907749), INT32_C(  654527510),
                            INT32_C(-2043358500), INT32_C(  459072440), INT32_C( -430427651), INT32_C( -272088075),
                            INT32_C(  386072301), INT32_C(-1628984154), INT32_C(   87817524), INT32_C( 1219490517)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   493.65), SIMDE_FLOAT32_C(  -659.70), SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   493.30),
                         SIMDE_FLOAT32_C(   835.54), SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -712.24), SIMDE_FLOAT32_C(  -619.50),
                         SIMDE_FLOAT32_C(   518.12), SIMDE_FLOAT32_C(   952.47), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(  -492.61),
                         SIMDE_FLOAT32_C(   487.08), SIMDE_FLOAT32_C(   -68.16), SIMDE_FLOAT32_C(   180.78), SIMDE_FLOAT32_C(   717.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -68.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   717.69), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(   952.47),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -173.80),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   952.47), SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(  -173.80)) },
    { UINT16_C(26926),
      simde_mm512_set_epi32(INT32_C( 1174128677), INT32_C(-1544325740), INT32_C(  204417556), INT32_C(-1329665093),
                            INT32_C(-2039025377), INT32_C( 1639231015), INT32_C( 1541217841), INT32_C( 1692413538),
                            INT32_C(  738521275), INT32_C(  159429100), INT32_C(  451955897), INT32_C(  181201098),
                            INT32_C(  450627934), INT32_C( 2082954477), INT32_C( 1254960767), INT32_C( 1995459397)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -783.00), SIMDE_FLOAT32_C(  -388.47), SIMDE_FLOAT32_C(  -102.18), SIMDE_FLOAT32_C(  -643.43),
                         SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(  -331.34), SIMDE_FLOAT32_C(    22.93), SIMDE_FLOAT32_C(    72.67),
                         SIMDE_FLOAT32_C(  -395.13), SIMDE_FLOAT32_C(  -870.79), SIMDE_FLOAT32_C(   145.63), SIMDE_FLOAT32_C(  -722.44),
                         SIMDE_FLOAT32_C(  -149.04), SIMDE_FLOAT32_C(   529.44), SIMDE_FLOAT32_C(   214.37), SIMDE_FLOAT32_C(  -949.73)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -722.44), SIMDE_FLOAT32_C(  -722.44), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -783.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   529.44),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    22.93), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -388.47), SIMDE_FLOAT32_C(  -102.18), SIMDE_FLOAT32_C(  -783.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C(36907),
      simde_mm512_set_epi32(INT32_C(-1123374630), INT32_C( -181070601), INT32_C( 1463729035), INT32_C( 2031968571),
                            INT32_C(  333434400), INT32_C( -637142874), INT32_C( -520435756), INT32_C( -148623413),
                            INT32_C( -692754616), INT32_C(-1908406411), INT32_C( 1391053429), INT32_C( 1767908668),
                            INT32_C( 1117151413), INT32_C( 1466854108), INT32_C( -852914371), INT32_C( -773785464)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -777.05), SIMDE_FLOAT32_C(  -607.82), SIMDE_FLOAT32_C(   621.95), SIMDE_FLOAT32_C(   296.47),
                         SIMDE_FLOAT32_C(  -116.18), SIMDE_FLOAT32_C(  -327.04), SIMDE_FLOAT32_C(   909.84), SIMDE_FLOAT32_C(   -23.06),
                         SIMDE_FLOAT32_C(   696.35), SIMDE_FLOAT32_C(   -95.21), SIMDE_FLOAT32_C(  -644.31), SIMDE_FLOAT32_C(    10.75),
                         SIMDE_FLOAT32_C(   486.53), SIMDE_FLOAT32_C(  -668.43), SIMDE_FLOAT32_C(  -235.48), SIMDE_FLOAT32_C(  -210.00)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -327.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -116.18),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -644.31), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -644.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   621.95), SIMDE_FLOAT32_C(   -23.06)) },
    { UINT16_C(59609),
      simde_mm512_set_epi32(INT32_C( 2052878307), INT32_C( -856056848), INT32_C(-1218860495), INT32_C(  729621709),
                            INT32_C(-1241407128), INT32_C(  696721321), INT32_C( -603523965), INT32_C( 1730687689),
                            INT32_C(  290786615), INT32_C(-1827031380), INT32_C( 1429317129), INT32_C(-1800615955),
                            INT32_C( -728999228), INT32_C( -788606428), INT32_C( -539592973), INT32_C(-1402526875)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -251.41), SIMDE_FLOAT32_C(   383.31), SIMDE_FLOAT32_C(   223.24), SIMDE_FLOAT32_C(   641.22),
                         SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(  -747.07), SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(  -762.67),
                         SIMDE_FLOAT32_C(   925.24), SIMDE_FLOAT32_C(   744.11), SIMDE_FLOAT32_C(   849.34), SIMDE_FLOAT32_C(   350.11),
                         SIMDE_FLOAT32_C(   112.68), SIMDE_FLOAT32_C(   409.27), SIMDE_FLOAT32_C(   -96.70), SIMDE_FLOAT32_C(   481.83)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   112.68), SIMDE_FLOAT32_C(   481.83), SIMDE_FLOAT32_C(   -96.70), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -762.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   925.24), SIMDE_FLOAT32_C(   641.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   223.24),
                         SIMDE_FLOAT32_C(   350.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   849.34)) },
    { UINT16_C(40824),
      simde_mm512_set_epi32(INT32_C(  568974515), INT32_C(-1726442446), INT32_C(-2134949944), INT32_C( 1969107101),
                            INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053), INT32_C( 1035482990),
                            INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639), INT32_C( -638430290),
                            INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613), INT32_C(  165266600)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -710.54), SIMDE_FLOAT32_C(  -653.71), SIMDE_FLOAT32_C(  -140.51), SIMDE_FLOAT32_C(   371.73),
                         SIMDE_FLOAT32_C(   346.36), SIMDE_FLOAT32_C(   757.18), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(   214.84),
                         SIMDE_FLOAT32_C(   399.19), SIMDE_FLOAT32_C(   830.24), SIMDE_FLOAT32_C(  -291.83), SIMDE_FLOAT32_C(   903.53),
                         SIMDE_FLOAT32_C(   951.57), SIMDE_FLOAT32_C(  -831.08), SIMDE_FLOAT32_C(   272.52), SIMDE_FLOAT32_C(   815.07)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   951.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -140.51),
                         SIMDE_FLOAT32_C(  -291.83), SIMDE_FLOAT32_C(   371.73), SIMDE_FLOAT32_C(   951.57), SIMDE_FLOAT32_C(  -653.71),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -653.71), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(  -653.71),
                         SIMDE_FLOAT32_C(  -653.71), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_maskz_permutexvar_ps(test_vec[i].k, test_vec[i].idx, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
 }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutexvar_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutexvar_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutexvar_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutexvar_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutexvar_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutexvar_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutexvar_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutexvar_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutexvar_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutexvar_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutexvar_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutexvar_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutexvar_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutexvar_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutexvar_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutexvar_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutexvar_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutexvar_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutexvar_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutexvar_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutexvar_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutexvar_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutexvar_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutexvar_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutexvar_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutexvar_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutexvar_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutexvar_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutexvar_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutexvar_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutexvar_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutexvar_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutexvar_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutexvar_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutexvar_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutexvar_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutexvar_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutexvar_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutexvar_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutexvar_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutexvar_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutexvar_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
