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

#define SIMDE_TEST_X86_AVX512_INSN permutex2var

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/permutex2var.h>

static int
test_simde_mm_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t idx[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 10061), -INT16_C(  7066),  INT16_C( 16449),  INT16_C( 17680), -INT16_C(  6998),  INT16_C( 23576), -INT16_C(  4794),  INT16_C( 22165) },
      {  INT16_C( 27840), -INT16_C( 18743),  INT16_C( 13054), -INT16_C( 26623),  INT16_C( 14386), -INT16_C( 31790),  INT16_C( 31964),  INT16_C( 10654) },
      {  INT16_C(  1188), -INT16_C(  6899),  INT16_C(  7492), -INT16_C(  4310),  INT16_C( 17153),  INT16_C( 18507), -INT16_C(  8144), -INT16_C(  3938) },
      {  INT16_C( 10061), -INT16_C(  6899), -INT16_C(  8144), -INT16_C(  7066),  INT16_C( 16449),  INT16_C( 16449),  INT16_C( 17153), -INT16_C(  8144) } },
    { {  INT16_C( 26700),  INT16_C( 19366), -INT16_C( 22374), -INT16_C( 13085), -INT16_C( 18976), -INT16_C( 17328), -INT16_C(  4559), -INT16_C( 10779) },
      { -INT16_C(  3086),  INT16_C( 14010), -INT16_C(  6896),  INT16_C(  4645),  INT16_C( 28968),  INT16_C( 22618), -INT16_C(  1967), -INT16_C( 25016) },
      { -INT16_C(  4512), -INT16_C(  1303), -INT16_C( 13162),  INT16_C( 30407),  INT16_C(  6017), -INT16_C( 19918),  INT16_C(  6149), -INT16_C(  2168) },
      { -INT16_C( 22374), -INT16_C( 13162),  INT16_C( 26700), -INT16_C( 17328), -INT16_C(  4512), -INT16_C( 13162),  INT16_C( 19366), -INT16_C(  4512) } },
    { {  INT16_C( 16907),  INT16_C(  6957),  INT16_C( 21287),  INT16_C( 20269), -INT16_C( 30780),  INT16_C(  5543), -INT16_C(  4224), -INT16_C(  8013) },
      { -INT16_C( 25378),  INT16_C( 29915), -INT16_C( 23960), -INT16_C(  5653),  INT16_C(  7609), -INT16_C( 16740),  INT16_C(  9269),  INT16_C( 16565) },
      { -INT16_C(  7578), -INT16_C( 29092), -INT16_C( 30411), -INT16_C(  1571), -INT16_C( 31471), -INT16_C( 28401), -INT16_C( 15756),  INT16_C( 21105) },
      { -INT16_C( 15756), -INT16_C(  1571), -INT16_C(  7578), -INT16_C(  1571), -INT16_C( 29092), -INT16_C( 31471),  INT16_C(  5543),  INT16_C(  5543) } },
    { {  INT16_C( 19551), -INT16_C( 14393), -INT16_C( 19730), -INT16_C( 22607),  INT16_C( 19919),  INT16_C(  1381),  INT16_C(  6769), -INT16_C( 10427) },
      { -INT16_C( 24067),  INT16_C( 12901),  INT16_C( 17195),  INT16_C( 15404),  INT16_C( 15304),  INT16_C( 15565),  INT16_C( 16125),  INT16_C( 23695) },
      {  INT16_C( 22155),  INT16_C( 31012), -INT16_C( 11000), -INT16_C( 10463), -INT16_C( 31198), -INT16_C( 27684),  INT16_C(  8865), -INT16_C( 24982) },
      { -INT16_C( 27684),  INT16_C(  1381), -INT16_C( 10463), -INT16_C( 31198),  INT16_C( 22155), -INT16_C( 27684), -INT16_C( 27684), -INT16_C( 24982) } },
    { { -INT16_C( 12093), -INT16_C(  4400), -INT16_C(  1005), -INT16_C(  9430), -INT16_C(  2249),  INT16_C( 13591), -INT16_C( 22986), -INT16_C( 15983) },
      { -INT16_C( 18948),  INT16_C(  1082),  INT16_C( 23434), -INT16_C( 21284), -INT16_C( 18206), -INT16_C( 31937), -INT16_C( 21798), -INT16_C( 25055) },
      { -INT16_C(  3718), -INT16_C( 29300), -INT16_C( 18450),  INT16_C(  9576),  INT16_C( 32686), -INT16_C(  7078), -INT16_C(  5082),  INT16_C(  8869) },
      {  INT16_C( 32686), -INT16_C( 18450), -INT16_C( 18450),  INT16_C( 32686), -INT16_C(  1005),  INT16_C(  8869), -INT16_C( 18450), -INT16_C(  4400) } },
    { { -INT16_C(  8031),  INT16_C( 11303),  INT16_C(   827),  INT16_C(  7640),  INT16_C(  6331), -INT16_C( 26976), -INT16_C( 15934),  INT16_C( 15412) },
      { -INT16_C( 16205), -INT16_C( 24119),  INT16_C( 12663),  INT16_C(  9926),  INT16_C(  8624), -INT16_C( 10742), -INT16_C( 20467), -INT16_C( 20743) },
      {  INT16_C(  8336), -INT16_C( 13350), -INT16_C( 19677), -INT16_C(  8471), -INT16_C( 30261), -INT16_C( 29324), -INT16_C( 22453), -INT16_C(   311) },
      {  INT16_C(  7640), -INT16_C( 13350),  INT16_C( 15412), -INT16_C( 15934), -INT16_C(  8031), -INT16_C( 19677), -INT16_C( 29324), -INT16_C( 13350) } },
    { { -INT16_C( 28055), -INT16_C(  8033),  INT16_C( 26051),  INT16_C( 29446),  INT16_C(  4486), -INT16_C( 27830),  INT16_C( 17345),  INT16_C( 20802) },
      {  INT16_C(  7267), -INT16_C( 31204),  INT16_C(  1487), -INT16_C( 26012), -INT16_C(  9841), -INT16_C(  9689), -INT16_C(  3967), -INT16_C(  5416) },
      {  INT16_C( 30594),  INT16_C( 17867), -INT16_C( 11812),  INT16_C( 25529),  INT16_C(   994), -INT16_C( 23562),  INT16_C( 14406), -INT16_C( 22028) },
      {  INT16_C( 29446),  INT16_C(   994), -INT16_C( 22028),  INT16_C(  4486), -INT16_C( 22028),  INT16_C( 20802), -INT16_C(  8033),  INT16_C( 30594) } },
    { {  INT16_C(  4437),  INT16_C(  9263), -INT16_C( 27882), -INT16_C( 23105), -INT16_C(  6548), -INT16_C(  4481),  INT16_C( 22487),  INT16_C( 23000) },
      { -INT16_C( 23602), -INT16_C( 21601),  INT16_C( 22645),  INT16_C( 22286),  INT16_C(  1115), -INT16_C( 24069), -INT16_C(  4291), -INT16_C( 28086) },
      {  INT16_C( 30976),  INT16_C(  6070),  INT16_C( 29964),  INT16_C( 31164),  INT16_C( 15452),  INT16_C( 13159),  INT16_C( 16275),  INT16_C( 25228) },
      {  INT16_C( 16275),  INT16_C( 25228), -INT16_C(  4481),  INT16_C( 16275),  INT16_C( 31164),  INT16_C( 31164),  INT16_C( 13159),  INT16_C( 29964) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_permutex2var_epi16(a, idx, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_permutex2var_epi16(a, idx, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const simde__mmask8 k;
    const int16_t idx[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 11235),  INT16_C( 22541),  INT16_C(  7043), -INT16_C(  8529), -INT16_C( 21985),  INT16_C( 23679), -INT16_C( 13926), -INT16_C( 25874) },
      UINT8_C( 66),
      { -INT16_C( 20059),  INT16_C(  6735), -INT16_C( 14226), -INT16_C( 21898), -INT16_C( 22225),  INT16_C( 28221), -INT16_C( 24778),  INT16_C( 24913) },
      { -INT16_C( 22100), -INT16_C( 14363), -INT16_C( 15527),  INT16_C(   999),  INT16_C( 17219),  INT16_C(  3229),  INT16_C( 14386), -INT16_C( 10417) },
      {  INT16_C( 11235), -INT16_C( 10417),  INT16_C(  7043), -INT16_C(  8529), -INT16_C( 21985),  INT16_C( 23679), -INT16_C( 13926), -INT16_C( 25874) } },
    { { -INT16_C( 24855),  INT16_C( 22513),  INT16_C( 26726), -INT16_C( 27391),  INT16_C( 16145),  INT16_C( 18179),  INT16_C( 21982), -INT16_C( 29783) },
      UINT8_C(254),
      {  INT16_C( 21134),  INT16_C( 20823),  INT16_C( 23353),  INT16_C( 32148), -INT16_C( 24072),  INT16_C( 12463), -INT16_C( 30992), -INT16_C( 29158) },
      {  INT16_C( 29047), -INT16_C(  8204), -INT16_C( 30349), -INT16_C( 19727),  INT16_C( 14476), -INT16_C(  7792),  INT16_C(  7137),  INT16_C( 28640) },
      { -INT16_C( 24855), -INT16_C( 29783), -INT16_C(  8204),  INT16_C( 16145),  INT16_C( 29047),  INT16_C( 28640), -INT16_C( 24855), -INT16_C( 30349) } },
    { {  INT16_C( 14190), -INT16_C( 22591),  INT16_C( 21906), -INT16_C( 29916), -INT16_C( 11274), -INT16_C(  6469), -INT16_C( 10919), -INT16_C( 11916) },
      UINT8_C( 71),
      { -INT16_C( 20376), -INT16_C(  3654),  INT16_C( 27809), -INT16_C(  9602),  INT16_C( 24572),  INT16_C(  6331),  INT16_C( 11071),  INT16_C( 30598) },
      {  INT16_C( 11756),  INT16_C( 16649), -INT16_C( 27566),  INT16_C(  9528),  INT16_C(  7760),  INT16_C(  9599),  INT16_C( 20627), -INT16_C(  1172) },
      {  INT16_C( 11756), -INT16_C( 27566), -INT16_C( 22591), -INT16_C( 29916), -INT16_C( 11274), -INT16_C(  6469), -INT16_C(  1172), -INT16_C( 11916) } },
    { {  INT16_C(  9728), -INT16_C( 23827),  INT16_C( 27538), -INT16_C( 28804),  INT16_C( 14282),  INT16_C(  2727),  INT16_C( 11618),  INT16_C( 20097) },
      UINT8_C( 90),
      { -INT16_C( 28534),  INT16_C(  8108), -INT16_C( 11576), -INT16_C(  6545), -INT16_C( 27567), -INT16_C( 24199),  INT16_C( 29953),  INT16_C( 10145) },
      {  INT16_C( 17250), -INT16_C( 12870),  INT16_C( 18879), -INT16_C(  2153), -INT16_C( 24080),  INT16_C(  7513), -INT16_C( 22494), -INT16_C( 21129) },
      {  INT16_C(  9728), -INT16_C( 24080),  INT16_C( 27538), -INT16_C( 21129), -INT16_C( 23827),  INT16_C(  2727), -INT16_C( 23827),  INT16_C( 20097) } },
    { {  INT16_C(  9272),  INT16_C(   204),  INT16_C( 15350),  INT16_C( 18406),  INT16_C( 24783), -INT16_C( 12056), -INT16_C( 30251),  INT16_C( 14328) },
      UINT8_C(205),
      {  INT16_C(  1202), -INT16_C(  1140), -INT16_C( 31845),  INT16_C( 15851),  INT16_C(  2269), -INT16_C( 31393),  INT16_C(  3199), -INT16_C( 23619) },
      { -INT16_C( 16936),  INT16_C(  5017), -INT16_C(  8029),  INT16_C(   995), -INT16_C( 19512),  INT16_C( 21208),  INT16_C(  4011),  INT16_C( 23839) },
      {  INT16_C( 15350),  INT16_C(   204),  INT16_C(   995),  INT16_C(   995),  INT16_C( 24783), -INT16_C( 12056),  INT16_C( 23839),  INT16_C( 21208) } },
    { { -INT16_C( 21741), -INT16_C( 20648),  INT16_C( 17199),  INT16_C(  3308),  INT16_C( 19275), -INT16_C( 13423),  INT16_C( 20056),  INT16_C( 12398) },
      UINT8_C( 11),
      {  INT16_C( 17416), -INT16_C(  5970), -INT16_C( 19929), -INT16_C(  9551),  INT16_C(   906), -INT16_C( 25978), -INT16_C(  7390), -INT16_C( 12883) },
      {  INT16_C( 23612),  INT16_C( 32764),  INT16_C(  2120), -INT16_C( 27445), -INT16_C( 26983), -INT16_C(  6164),  INT16_C(  7172),  INT16_C(  3314) },
      {  INT16_C( 23612),  INT16_C(  7172),  INT16_C( 17199), -INT16_C( 20648),  INT16_C( 19275), -INT16_C( 13423),  INT16_C( 20056),  INT16_C( 12398) } },
    { { -INT16_C( 24224), -INT16_C( 30731), -INT16_C( 22957), -INT16_C(  8862), -INT16_C(  5975), -INT16_C( 13449),  INT16_C(  9675),  INT16_C(  1944) },
      UINT8_C(129),
      { -INT16_C( 30827), -INT16_C( 25142),  INT16_C( 24146), -INT16_C(  6089),  INT16_C(  7754),  INT16_C( 26348), -INT16_C(  1775), -INT16_C( 19769) },
      {  INT16_C( 20206), -INT16_C( 27643), -INT16_C(  7504), -INT16_C( 26563),  INT16_C(  2138),  INT16_C( 32612),  INT16_C( 27552),  INT16_C( 13568) },
      { -INT16_C( 13449), -INT16_C( 30731), -INT16_C( 22957), -INT16_C(  8862), -INT16_C(  5975), -INT16_C( 13449),  INT16_C(  9675),  INT16_C(  1944) } },
    { { -INT16_C( 13582),  INT16_C( 17619),  INT16_C(  2600),  INT16_C( 29228),  INT16_C(  6440),  INT16_C( 14809), -INT16_C( 24558),  INT16_C(   235) },
      UINT8_C(238),
      { -INT16_C( 27408), -INT16_C( 11361),  INT16_C( 14289), -INT16_C(  9939), -INT16_C( 21349),  INT16_C(  1913), -INT16_C( 20564),  INT16_C( 30713) },
      {  INT16_C( 16002), -INT16_C( 29537),  INT16_C(  4714), -INT16_C( 31820), -INT16_C(  4373), -INT16_C( 29803), -INT16_C( 27175), -INT16_C( 13703) },
      { -INT16_C( 13582), -INT16_C( 13703),  INT16_C( 17619), -INT16_C( 29803),  INT16_C(  6440), -INT16_C( 29537), -INT16_C(  4373), -INT16_C( 29537) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_permutex2var_epi16(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_permutex2var_epi16(a, k, idx, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask2_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t idx[16];
    const simde__mmask8 k;
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C(  6185), -INT16_C(  1379), -INT16_C( 13744), -INT16_C(  5165),  INT16_C( 19830),  INT16_C(  8946), -INT16_C(  4868),  INT16_C( 32409) },
      {  INT16_C( 14634), -INT16_C( 27638), -INT16_C( 16821),  INT16_C( 13848), -INT16_C( 21076), -INT16_C( 31039),  INT16_C( 14915),  INT16_C( 27728) },
      UINT8_C( 83),
      {  INT16_C( 26605), -INT16_C( 18525), -INT16_C( 29126), -INT16_C( 30931),  INT16_C( 20353),  INT16_C( 28035),  INT16_C(   489),  INT16_C(  8855) },
      { -INT16_C( 29126), -INT16_C( 29126), -INT16_C( 16821),  INT16_C( 13848),  INT16_C( 20353), -INT16_C( 31039), -INT16_C(  5165),  INT16_C( 27728) } },
    { {  INT16_C( 11019), -INT16_C( 13715), -INT16_C( 23741), -INT16_C(  3722), -INT16_C(   924), -INT16_C( 25036), -INT16_C( 24500),  INT16_C( 14833) },
      { -INT16_C( 27641),  INT16_C( 17136),  INT16_C(  7459), -INT16_C( 23351),  INT16_C( 19821),  INT16_C( 22033), -INT16_C( 22450),  INT16_C( 23160) },
      UINT8_C(211),
      {  INT16_C(  9445), -INT16_C( 30697),  INT16_C(  2202), -INT16_C( 26644), -INT16_C( 30148), -INT16_C(  8989),  INT16_C(  7548),  INT16_C(  4324) },
      {  INT16_C( 14833),  INT16_C( 11019),  INT16_C(  7459), -INT16_C( 23351), -INT16_C(  8989),  INT16_C( 22033),  INT16_C(  7548),  INT16_C(  9445) } },
    { {  INT16_C(  9741),  INT16_C( 11059), -INT16_C( 10257),  INT16_C( 15512), -INT16_C(  4376), -INT16_C( 28533), -INT16_C(  6810),  INT16_C( 19300) },
      {  INT16_C( 31497), -INT16_C( 23597), -INT16_C( 16509), -INT16_C( 16582),  INT16_C(  7753), -INT16_C( 14949),  INT16_C( 32571),  INT16_C( 18646) },
      UINT8_C(165),
      {  INT16_C( 29449), -INT16_C(  7787), -INT16_C( 12021), -INT16_C(  1591),  INT16_C( 23132),  INT16_C( 16735), -INT16_C( 21826),  INT16_C( 14666) },
      { -INT16_C(  7787), -INT16_C( 23597),  INT16_C( 15512), -INT16_C( 16582),  INT16_C(  7753), -INT16_C(  1591),  INT16_C( 32571), -INT16_C(  6810) } },
    { { -INT16_C(  4483),  INT16_C( 15548),  INT16_C( 31528),  INT16_C( 18054),  INT16_C( 19222), -INT16_C( 27007), -INT16_C( 13791),  INT16_C( 11067) },
      { -INT16_C( 12227),  INT16_C( 18700), -INT16_C( 10846), -INT16_C(   446), -INT16_C( 24017), -INT16_C(  4800), -INT16_C( 30132), -INT16_C( 13786) },
      UINT8_C(120),
      {  INT16_C(  1762),  INT16_C( 23969), -INT16_C(  6260), -INT16_C( 10124),  INT16_C(  2665),  INT16_C( 13305),  INT16_C(  9285),  INT16_C(  5744) },
      { -INT16_C( 12227),  INT16_C( 18700), -INT16_C( 10846),  INT16_C( 31528),  INT16_C(  5744), -INT16_C(  4483),  INT16_C(  2665), -INT16_C( 13786) } },
    { { -INT16_C( 18128),  INT16_C(  1720), -INT16_C( 18692), -INT16_C( 25035),  INT16_C(  9206), -INT16_C( 32278), -INT16_C( 19383),  INT16_C( 11513) },
      { -INT16_C( 25925),  INT16_C( 18313), -INT16_C(   638), -INT16_C(  5345),  INT16_C(  6407),  INT16_C( 19742), -INT16_C( 29123),  INT16_C( 28259) },
      UINT8_C( 72),
      {  INT16_C( 29723), -INT16_C( 11964), -INT16_C(  7511), -INT16_C( 13112),  INT16_C( 18892), -INT16_C( 32490),  INT16_C( 16962), -INT16_C(  8900) },
      { -INT16_C( 25925),  INT16_C( 18313), -INT16_C(   638), -INT16_C(  8900),  INT16_C(  6407),  INT16_C( 19742), -INT16_C( 32490),  INT16_C( 28259) } },
    { { -INT16_C( 31797), -INT16_C( 13985),  INT16_C( 19107), -INT16_C( 17200),  INT16_C(  7528), -INT16_C(  2311),  INT16_C( 26496), -INT16_C( 25794) },
      { -INT16_C( 32037), -INT16_C( 31379),  INT16_C( 13668),  INT16_C( 12625),  INT16_C( 26494), -INT16_C( 16206), -INT16_C(  4439),  INT16_C( 30109) },
      UINT8_C(113),
      {  INT16_C( 16124),  INT16_C( 17940), -INT16_C( 12274),  INT16_C( 11438), -INT16_C( 23094),  INT16_C( 12716),  INT16_C( 18659),  INT16_C( 26125) },
      {  INT16_C( 11438), -INT16_C( 31379),  INT16_C( 13668),  INT16_C( 12625),  INT16_C( 18659),  INT16_C( 19107),  INT16_C( 17940),  INT16_C( 30109) } },
    { { -INT16_C( 27979), -INT16_C(  5430), -INT16_C(  1053),  INT16_C( 19304),  INT16_C( 10413), -INT16_C( 25612),  INT16_C( 27078), -INT16_C( 15859) },
      {  INT16_C(  8615), -INT16_C( 18935), -INT16_C( 18446), -INT16_C( 17182), -INT16_C( 29092),  INT16_C( 16621), -INT16_C(  1322), -INT16_C( 29786) },
      UINT8_C(140),
      {  INT16_C( 30064),  INT16_C( 27760), -INT16_C( 17443),  INT16_C(  1561), -INT16_C( 19025),  INT16_C(  6604), -INT16_C( 28990), -INT16_C(  7232) },
      {  INT16_C(  8615), -INT16_C( 18935), -INT16_C(  1053), -INT16_C(  1053), -INT16_C( 29092),  INT16_C( 16621), -INT16_C(  1322),  INT16_C( 27078) } },
    { {  INT16_C( 30359),  INT16_C( 20437), -INT16_C( 28328), -INT16_C(  6229), -INT16_C(  5249),  INT16_C( 31165),  INT16_C( 18833),  INT16_C(   518) },
      {  INT16_C( 30398), -INT16_C( 25490), -INT16_C( 30927), -INT16_C(  8030),  INT16_C( 28220), -INT16_C(   263), -INT16_C( 17668), -INT16_C( 27422) },
      UINT8_C( 48),
      { -INT16_C(  7241),  INT16_C( 18825),  INT16_C( 28814),  INT16_C( 31432),  INT16_C( 16685),  INT16_C( 30219),  INT16_C(  3399), -INT16_C( 17099) },
      {  INT16_C( 30398), -INT16_C( 25490), -INT16_C( 30927), -INT16_C(  8030),  INT16_C( 16685),  INT16_C( 18825), -INT16_C( 17668), -INT16_C( 27422) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask2_permutex2var_epi16(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask2_permutex2var_epi16(a, idx, k, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[16];
    const int16_t idx[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT8_C(123),
      { -INT16_C(  4399),  INT16_C( 29443),  INT16_C( 16335), -INT16_C( 14111), -INT16_C(  8898),  INT16_C(  8322), -INT16_C( 19599),  INT16_C( 21719) },
      {  INT16_C(  8252), -INT16_C( 21277),  INT16_C( 24040),  INT16_C( 10969),  INT16_C( 20584),  INT16_C( 30321),  INT16_C( 12165),  INT16_C( 22257) },
      { -INT16_C(  3043), -INT16_C(  4919), -INT16_C( 21964),  INT16_C( 29365),  INT16_C( 14215), -INT16_C(  1646),  INT16_C( 27114),  INT16_C(  9805) },
      {  INT16_C( 14215), -INT16_C( 14111),  INT16_C(     0), -INT16_C(  4919), -INT16_C(  3043),  INT16_C( 29443),  INT16_C(  8322),  INT16_C(     0) } },
    { UINT8_C(138),
      { -INT16_C( 11728), -INT16_C( 29326), -INT16_C( 25428), -INT16_C(   778),  INT16_C( 27662),  INT16_C( 15745), -INT16_C( 10403),  INT16_C( 21082) },
      {  INT16_C( 18336),  INT16_C( 19078), -INT16_C(  1796),  INT16_C( 13265), -INT16_C( 13686), -INT16_C(  3298),  INT16_C( 17432),  INT16_C( 18557) },
      { -INT16_C(  4073), -INT16_C( 15402), -INT16_C( 13172), -INT16_C( 25921),  INT16_C( 16440), -INT16_C( 27177),  INT16_C( 12823), -INT16_C( 18457) },
      {  INT16_C(     0), -INT16_C( 10403),  INT16_C(     0), -INT16_C( 29326),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27177) } },
    { UINT8_C(121),
      {  INT16_C(   365),  INT16_C( 25973), -INT16_C( 22318), -INT16_C( 25105), -INT16_C(  7226),  INT16_C(  2997), -INT16_C(   672),  INT16_C( 20514) },
      { -INT16_C(  6701), -INT16_C( 24611),  INT16_C( 30628), -INT16_C(  6953),  INT16_C( 27983), -INT16_C( 32261), -INT16_C( 19884), -INT16_C( 15622) },
      {  INT16_C( 28595), -INT16_C( 31449),  INT16_C(  5911), -INT16_C(  8670), -INT16_C( 10246),  INT16_C( 23273),  INT16_C(  3029), -INT16_C( 22357) },
      { -INT16_C( 25105),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20514), -INT16_C( 22357), -INT16_C(  8670), -INT16_C(  7226),  INT16_C(     0) } },
    { UINT8_C(240),
      {  INT16_C( 18568), -INT16_C(   108),  INT16_C( 30751), -INT16_C( 29618), -INT16_C( 12429),  INT16_C(  9697), -INT16_C( 23607),  INT16_C( 14552) },
      {  INT16_C( 24010), -INT16_C(  7856),  INT16_C( 11904),  INT16_C( 22491),  INT16_C( 13847),  INT16_C(  8748), -INT16_C( 10783),  INT16_C( 26898) },
      { -INT16_C( 23011),  INT16_C( 15464), -INT16_C( 18658), -INT16_C( 28215), -INT16_C( 21882),  INT16_C( 20662), -INT16_C( 29107),  INT16_C(  6024) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14552), -INT16_C( 21882), -INT16_C(   108),  INT16_C( 30751) } },
    { UINT8_C(235),
      { -INT16_C(  1576),  INT16_C(  1643), -INT16_C( 15404),  INT16_C(  2589),  INT16_C( 16367), -INT16_C( 15125),  INT16_C( 21585), -INT16_C(  2079) },
      {  INT16_C(  7869),  INT16_C( 29717), -INT16_C( 22809), -INT16_C( 28166),  INT16_C( 19036), -INT16_C(  5410), -INT16_C(  2605), -INT16_C( 21546) },
      {  INT16_C( 16878), -INT16_C( 15438), -INT16_C( 12540), -INT16_C(  2867), -INT16_C( 18161),  INT16_C( 24760), -INT16_C( 26099), -INT16_C( 13736) },
      {  INT16_C( 24760), -INT16_C( 15125),  INT16_C(     0), -INT16_C( 12540),  INT16_C(     0), -INT16_C( 26099),  INT16_C(  2589),  INT16_C( 21585) } },
    { UINT8_C(184),
      {  INT16_C( 15981),  INT16_C(  5279),  INT16_C( 12345), -INT16_C( 31888),  INT16_C( 23310),  INT16_C(   854),  INT16_C(   561),  INT16_C( 29426) },
      { -INT16_C( 19020), -INT16_C( 31881),  INT16_C( 27522),  INT16_C( 15250), -INT16_C(  3293), -INT16_C( 17079),  INT16_C(  4939), -INT16_C( 18315) },
      {  INT16_C(  5202), -INT16_C( 29748),  INT16_C( 15684),  INT16_C( 21006),  INT16_C( 26008), -INT16_C( 13994),  INT16_C( 18535),  INT16_C(  6971) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12345), -INT16_C( 31888), -INT16_C( 29748),  INT16_C(     0),  INT16_C(   854) } },
    { UINT8_C(253),
      { -INT16_C( 24910),  INT16_C(  7551), -INT16_C( 17615),  INT16_C(  9281), -INT16_C(   508),  INT16_C(  5999),  INT16_C( 10100), -INT16_C( 30615) },
      { -INT16_C(  2828),  INT16_C( 12749),  INT16_C(  7939),  INT16_C( 26825), -INT16_C( 28043), -INT16_C( 16945), -INT16_C(  5427), -INT16_C( 32582) },
      {  INT16_C( 14984), -INT16_C( 18019), -INT16_C(  8459), -INT16_C(  1571),  INT16_C( 19677),  INT16_C( 20752),  INT16_C( 31348),  INT16_C( 26841) },
      { -INT16_C(   508),  INT16_C(     0),  INT16_C(  9281), -INT16_C( 18019),  INT16_C(  5999),  INT16_C( 26841),  INT16_C( 20752), -INT16_C(  8459) } },
    { UINT8_C(110),
      { -INT16_C( 26202), -INT16_C( 14735), -INT16_C(  9886), -INT16_C(  3013), -INT16_C(  1624), -INT16_C( 27967),  INT16_C( 16819), -INT16_C(  4837) },
      { -INT16_C( 11041), -INT16_C( 16926), -INT16_C(  9294), -INT16_C(   358), -INT16_C(  5140),  INT16_C( 26226), -INT16_C(  9531),  INT16_C( 27604) },
      {  INT16_C( 18035), -INT16_C( 10959),  INT16_C( 27935), -INT16_C( 14135), -INT16_C( 29850),  INT16_C(  6490),  INT16_C( 30156), -INT16_C( 21753) },
      {  INT16_C(     0), -INT16_C(  9886), -INT16_C(  9886),  INT16_C( 27935),  INT16_C(     0), -INT16_C(  9886), -INT16_C( 27967),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi16(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_permutex2var_epi16(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i idx = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_permutex2var_epi16(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const int32_t idx[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(    60167862), -INT32_C(  1309015099), -INT32_C(  1273532945), -INT32_C(  1155536057) },
      {  INT32_C(  1368412465),  INT32_C(   605641406), -INT32_C(  1321372699),  INT32_C(   861750505) },
      { -INT32_C(   214972882), -INT32_C(  1197200951), -INT32_C(   563299434), -INT32_C(   661025626) },
      { -INT32_C(  1309015099), -INT32_C(   563299434), -INT32_C(  1197200951), -INT32_C(  1309015099) } },
    { { -INT32_C(  1691801123),  INT32_C(  1757364867), -INT32_C(  1642398539),  INT32_C(  1875998529) },
      {  INT32_C(   107085885), -INT32_C(  1061222870),  INT32_C(  1738419137), -INT32_C(  1807796297) },
      { -INT32_C(   466655135),  INT32_C(  1615720106),  INT32_C(   754870251),  INT32_C(   463196382) },
      {  INT32_C(  1615720106), -INT32_C(  1642398539),  INT32_C(  1757364867),  INT32_C(   463196382) } },
    { { -INT32_C(    98435632), -INT32_C(   994320381), -INT32_C(  1020569332), -INT32_C(   229086319) },
      {  INT32_C(  2127988691),  INT32_C(  1641948022),  INT32_C(  1754127498),  INT32_C(  2105747628) },
      {  INT32_C(   678929701), -INT32_C(  1846791547),  INT32_C(   492115852),  INT32_C(  1443868034) },
      { -INT32_C(   229086319),  INT32_C(   492115852), -INT32_C(  1020569332),  INT32_C(   678929701) } },
    { { -INT32_C(  1428888268), -INT32_C(  1827950071),  INT32_C(  1006409870), -INT32_C(   440893504) },
      { -INT32_C(  1441976540), -INT32_C(   298059422), -INT32_C(  1827958767),  INT32_C(  1927879229) },
      {  INT32_C(   136101375), -INT32_C(    23320465), -INT32_C(  2126931776),  INT32_C(  1013379351) },
      {  INT32_C(   136101375),  INT32_C(  1006409870), -INT32_C(  1827950071), -INT32_C(    23320465) } },
    { { -INT32_C(  2098826208),  INT32_C(  2121277805), -INT32_C(   284001358), -INT32_C(  1788740715) },
      {  INT32_C(   681410233),  INT32_C(  1713781158), -INT32_C(   370712623),  INT32_C(  1898270288) },
      {  INT32_C(   804457410), -INT32_C(   558996436),  INT32_C(  1976484063),  INT32_C(  1946824635) },
      {  INT32_C(  2121277805),  INT32_C(  1976484063),  INT32_C(  2121277805), -INT32_C(  2098826208) } },
    { {  INT32_C(  1402841005), -INT32_C(  1296383007),  INT32_C(  1939579171), -INT32_C(  1310408465) },
      { -INT32_C(   119416629),  INT32_C(   467046204),  INT32_C(   177251407), -INT32_C(  2122343724) },
      {  INT32_C(   601168962),  INT32_C(    47550431),  INT32_C(   544633136), -INT32_C(    36611535) },
      { -INT32_C(  1310408465),  INT32_C(   601168962), -INT32_C(    36611535),  INT32_C(   601168962) } },
    { {  INT32_C(  1861595698), -INT32_C(  1869952191),  INT32_C(  1151015536), -INT32_C(   138077515) },
      {  INT32_C(   354064950),  INT32_C(  1511583529), -INT32_C(  1837461920),  INT32_C(   462375912) },
      {  INT32_C(  1065977086), -INT32_C(  1076882609), -INT32_C(   486315218), -INT32_C(  1143289467) },
      { -INT32_C(   486315218), -INT32_C(  1869952191),  INT32_C(  1861595698),  INT32_C(  1861595698) } },
    { { -INT32_C(  1915685789),  INT32_C(  1156049123),  INT32_C(  1607885174), -INT32_C(  1434819156) },
      {  INT32_C(   954860521),  INT32_C(  1173928471), -INT32_C(  1440154843),  INT32_C(   677708484) },
      { -INT32_C(   642435594), -INT32_C(  1809998818), -INT32_C(  1443630083),  INT32_C(  1096052056) },
      {  INT32_C(  1156049123),  INT32_C(  1096052056), -INT32_C(  1809998818), -INT32_C(   642435594) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_permutex2var_epi32(a, idx, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_permutex2var_epi32(a, idx, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const simde__mmask8 k;
    const int32_t idx[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  2005254543),  INT32_C(   500003576),  INT32_C(   851965293), -INT32_C(   312857353) },
      UINT8_C( 97),
      { -INT32_C(  1417689585), -INT32_C(   676850460),  INT32_C(  1966100743), -INT32_C(   471436891) },
      {  INT32_C(  1574661867),  INT32_C(   818673723), -INT32_C(   349700673),  INT32_C(  1716327511) },
      {  INT32_C(  1716327511),  INT32_C(   500003576),  INT32_C(   851965293), -INT32_C(   312857353) } },
    { { -INT32_C(  1106129702), -INT32_C(   392775200), -INT32_C(  1336031734),  INT32_C(   596853559) },
      UINT8_C(177),
      {  INT32_C(  1743552623),  INT32_C(  1210522699),  INT32_C(  1470042691),  INT32_C(   741410143) },
      { -INT32_C(   821235690),  INT32_C(  1289417862), -INT32_C(  1803318703), -INT32_C(  1941592547) },
      { -INT32_C(  1941592547), -INT32_C(   392775200), -INT32_C(  1336031734),  INT32_C(   596853559) } },
    { {  INT32_C(  1928605991), -INT32_C(  1866785971), -INT32_C(  1914217939),  INT32_C(  1991842144) },
      UINT8_C(  9),
      { -INT32_C(  1165015355), -INT32_C(  1442063584),  INT32_C(    96968798),  INT32_C(   388781285) },
      {  INT32_C(  1667538504), -INT32_C(  1265568423), -INT32_C(   183231012), -INT32_C(  1661039914) },
      { -INT32_C(  1265568423), -INT32_C(  1866785971), -INT32_C(  1914217939), -INT32_C(  1265568423) } },
    { { -INT32_C(   262763056), -INT32_C(   946183832), -INT32_C(   406035967), -INT32_C(    16844618) },
      UINT8_C(150),
      {  INT32_C(  1475371362),  INT32_C(   255108337),  INT32_C(  1122314680), -INT32_C(  1257012952) },
      {  INT32_C(   958268375),  INT32_C(     3859870), -INT32_C(  1447681615), -INT32_C(  2109754337) },
      { -INT32_C(   262763056), -INT32_C(   946183832), -INT32_C(   262763056), -INT32_C(    16844618) } },
    { {  INT32_C(   114896661), -INT32_C(  1961554477),  INT32_C(  1607400247),  INT32_C(  1410654588) },
      UINT8_C(228),
      {  INT32_C(   394431794), -INT32_C(   372735289), -INT32_C(   334991048), -INT32_C(   536769871) },
      {  INT32_C(  1907624036),  INT32_C(   413679389), -INT32_C(   292223219),  INT32_C(  1322510620) },
      {  INT32_C(   114896661), -INT32_C(  1961554477),  INT32_C(   114896661),  INT32_C(  1410654588) } },
    { {  INT32_C(  1030116726),  INT32_C(   270937816),  INT32_C(  1375547296),  INT32_C(   489815737) },
      UINT8_C(  6),
      {  INT32_C(   623153125),  INT32_C(  1060256823), -INT32_C(  1168432687),  INT32_C(  1227926004) },
      {  INT32_C(  1042378255), -INT32_C(  1008848236),  INT32_C(   763178799),  INT32_C(  1177852512) },
      {  INT32_C(  1030116726),  INT32_C(  1177852512),  INT32_C(   270937816),  INT32_C(   489815737) } },
    { {  INT32_C(  1634424873),  INT32_C(  1721802132), -INT32_C(  1306461250), -INT32_C(  1258532444) },
      UINT8_C(191),
      {  INT32_C(  1330901533), -INT32_C(     8513584),  INT32_C(   778022036),  INT32_C(   945333728) },
      { -INT32_C(  1362314992),  INT32_C(  1416376921), -INT32_C(  1527242925),  INT32_C(   946056219) },
      {  INT32_C(  1416376921),  INT32_C(  1634424873), -INT32_C(  1362314992),  INT32_C(  1634424873) } },
    { {  INT32_C(  1854453406),  INT32_C(  1634535117), -INT32_C(  1836003918), -INT32_C(  2083854222) },
      UINT8_C(161),
      { -INT32_C(   906350185), -INT32_C(  1138995555), -INT32_C(   203964346), -INT32_C(   628027357) },
      { -INT32_C(  1633222504),  INT32_C(   978389357), -INT32_C(  2119310439),  INT32_C(  1159868590) },
      {  INT32_C(  1159868590),  INT32_C(  1634535117), -INT32_C(  1836003918), -INT32_C(  2083854222) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_permutex2var_epi32(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_permutex2var_epi32(a, k, idx, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask2_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const int32_t idx[8];
    const simde__mmask8 k;
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(    32629663), -INT32_C(  1329910934),  INT32_C(   262378219),  INT32_C(   988362146) },
      { -INT32_C(  1562800075),  INT32_C(   853355161), -INT32_C(  1145861619),  INT32_C(   453039546) },
      UINT8_C(241),
      {  INT32_C(   979048719),  INT32_C(  1730481364), -INT32_C(   469158737), -INT32_C(  1374075875) },
      {  INT32_C(  1730481364),  INT32_C(   853355161), -INT32_C(  1145861619),  INT32_C(   453039546) } },
    { {  INT32_C(  1195883549),  INT32_C(   592738969),  INT32_C(    64819245),  INT32_C(   536147984) },
      { -INT32_C(   430354415),  INT32_C(   189628252), -INT32_C(   772778317), -INT32_C(  1216411238) },
      UINT8_C(197),
      {  INT32_C(  1079967430),  INT32_C(  1668186451),  INT32_C(  1450406238), -INT32_C(  1251437723) },
      {  INT32_C(   592738969),  INT32_C(   189628252),  INT32_C(   536147984), -INT32_C(  1216411238) } },
    { {  INT32_C(  1796296428), -INT32_C(   249619045),  INT32_C(   378335245),  INT32_C(   903627631) },
      { -INT32_C(  1787413950),  INT32_C(   452519100), -INT32_C(  1166972075), -INT32_C(   344925698) },
      UINT8_C( 39),
      { -INT32_C(  1631431039),  INT32_C(  1705751413), -INT32_C(  2083208641), -INT32_C(   658175330) },
      {  INT32_C(   378335245), -INT32_C(  1631431039),  INT32_C(  1705751413), -INT32_C(   344925698) } },
    { {  INT32_C(  1687444096), -INT32_C(  1111904430), -INT32_C(   105090272),  INT32_C(  1696638947) },
      {  INT32_C(  1929634557), -INT32_C(   707219563),  INT32_C(   257469809),  INT32_C(   937893303) },
      UINT8_C(119),
      {  INT32_C(   734632828), -INT32_C(   951351724), -INT32_C(   374651838),  INT32_C(  1189548132) },
      { -INT32_C(   951351724), -INT32_C(   951351724), -INT32_C(  1111904430),  INT32_C(   937893303) } },
    { { -INT32_C(  1025811949), -INT32_C(   550260686),  INT32_C(   630604296), -INT32_C(  1499673302) },
      { -INT32_C(  1127127704),  INT32_C(   780410092), -INT32_C(  1005047968),  INT32_C(  1376452415) },
      UINT8_C( 89),
      { -INT32_C(  1769269787), -INT32_C(  1952552120), -INT32_C(   810171391), -INT32_C(   969450656) },
      { -INT32_C(  1025811949),  INT32_C(   780410092), -INT32_C(  1005047968), -INT32_C(   969450656) } },
    { {  INT32_C(  1219687468), -INT32_C(  1482104712), -INT32_C(   135893768),  INT32_C(  1531983990) },
      { -INT32_C(  1762534323),  INT32_C(  1210159175), -INT32_C(  1273506220),  INT32_C(  1568296753) },
      UINT8_C( 67),
      {  INT32_C(   230401324), -INT32_C(  1190829491), -INT32_C(  2144338616),  INT32_C(   701401677) },
      { -INT32_C(  1190829491),  INT32_C(   701401677), -INT32_C(  1273506220),  INT32_C(  1568296753) } },
    { {  INT32_C(   208692348),  INT32_C(  1533065605),  INT32_C(   529274064), -INT32_C(  1151145585) },
      { -INT32_C(   607642226), -INT32_C(   946549121),  INT32_C(   407421899), -INT32_C(   918415795) },
      UINT8_C(122),
      {  INT32_C(  1811928498),  INT32_C(  1245469237), -INT32_C(   807838746), -INT32_C(   614624066) },
      { -INT32_C(   607642226), -INT32_C(   614624066),  INT32_C(   407421899),  INT32_C(  1245469237) } },
    { {  INT32_C(   727398493), -INT32_C(  1879694644), -INT32_C(  2133062038),  INT32_C(    66758224) },
      { -INT32_C(  1318127237),  INT32_C(   972794451), -INT32_C(  1006054394), -INT32_C(   979409560) },
      UINT8_C(157),
      {  INT32_C(   493482234), -INT32_C(   175638298),  INT32_C(  2068121813), -INT32_C(    50968574) },
      {  INT32_C(    66758224),  INT32_C(   972794451),  INT32_C(  2068121813),  INT32_C(   727398493) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask2_permutex2var_epi32(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask2_permutex2var_epi32(a, idx, k, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t idx[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(183),
      { -INT32_C(  1570680921), -INT32_C(  1854511223), -INT32_C(   872947925), -INT32_C(  1782213468) },
      { -INT32_C(   159653122),  INT32_C(  1925935210), -INT32_C(    25934154), -INT32_C(   457871299) },
      {  INT32_C(  1233590208), -INT32_C(  1428488834), -INT32_C(  2122984996),  INT32_C(  1679178342) },
      { -INT32_C(  2122984996), -INT32_C(   872947925), -INT32_C(  2122984996),  INT32_C(           0) } },
    { UINT8_C( 29),
      {  INT32_C(    42424977),  INT32_C(  1824061734), -INT32_C(   559303059), -INT32_C(  2086760852) },
      {  INT32_C(   302114581), -INT32_C(  1813009471),  INT32_C(  1543073824),  INT32_C(   393764230) },
      { -INT32_C(   585498697),  INT32_C(  1699402232), -INT32_C(   196873336), -INT32_C(  1770528383) },
      {  INT32_C(  1699402232),  INT32_C(           0),  INT32_C(    42424977), -INT32_C(   196873336) } },
    { UINT8_C(200),
      {  INT32_C(   613067128),  INT32_C(   138681752),  INT32_C(  1938726678),  INT32_C(   371893527) },
      { -INT32_C(  1878128449),  INT32_C(  1159230546), -INT32_C(  1715008329), -INT32_C(    60727933) },
      { -INT32_C(  1642009850),  INT32_C(   514221064),  INT32_C(   462500868), -INT32_C(  1724728102) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   371893527) } },
    { UINT8_C(196),
      { -INT32_C(  1273616064),  INT32_C(  1315724098), -INT32_C(  2133719774),  INT32_C(  1384566374) },
      {  INT32_C(  1381639662),  INT32_C(     5667275), -INT32_C(   958762486), -INT32_C(   460688476) },
      { -INT32_C(   560357220),  INT32_C(   506267132),  INT32_C(  1889468170), -INT32_C(  1144904243) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  2133719774),  INT32_C(           0) } },
    { UINT8_C( 74),
      { -INT32_C(  1777005283), -INT32_C(   694151836),  INT32_C(  1652189167), -INT32_C(  1828757775) },
      { -INT32_C(    57745929),  INT32_C(   151432202),  INT32_C(  1893103435),  INT32_C(  1455067449) },
      {  INT32_C(    65851295), -INT32_C(   723939867), -INT32_C(   449358860), -INT32_C(  1451805007) },
      {  INT32_C(           0),  INT32_C(  1652189167),  INT32_C(           0), -INT32_C(   694151836) } },
    { UINT8_C( 19),
      { -INT32_C(  1306614523),  INT32_C(   603793324), -INT32_C(  1889767938), -INT32_C(   164711641) },
      {  INT32_C(   752562591),  INT32_C(  1562423306),  INT32_C(   487524071), -INT32_C(  2093959043) },
      {  INT32_C(   154488413),  INT32_C(  1949053558), -INT32_C(   972846689), -INT32_C(   608423364) },
      { -INT32_C(   608423364), -INT32_C(  1889767938),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 99),
      {  INT32_C(  1215170712),  INT32_C(   774884136), -INT32_C(  1834201894), -INT32_C(   873451652) },
      { -INT32_C(  1774061212), -INT32_C(  1355434714), -INT32_C(   353633352),  INT32_C(  1330562743) },
      { -INT32_C(   141050674),  INT32_C(  1646642823), -INT32_C(  1879781102),  INT32_C(  1683678208) },
      { -INT32_C(   141050674), -INT32_C(  1879781102),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(222),
      {  INT32_C(  1342503579),  INT32_C(   705213231),  INT32_C(  1692595102), -INT32_C(    46976703) },
      { -INT32_C(  1887163703),  INT32_C(   564323919), -INT32_C(  1088343589),  INT32_C(   647857803) },
      { -INT32_C(  1334402688), -INT32_C(   220561836), -INT32_C(  1302872975), -INT32_C(  1213232402) },
      {  INT32_C(           0), -INT32_C(  1213232402), -INT32_C(    46976703), -INT32_C(    46976703) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_permutex2var_epi32(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_permutex2var_epi32(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const int64_t idx[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C(  782245236833897292),  INT64_C( 5533326131068225049) },
      {  INT64_C( 3475608754009686260), -INT64_C( 3442841263988829549) },
      { -INT64_C( 9090805672746713146), -INT64_C( 3290177641303930050) },
      { -INT64_C(  782245236833897292), -INT64_C( 3290177641303930050) } },
    { { -INT64_C( 4818757958397963472),  INT64_C( 6688821353463612391) },
      { -INT64_C( 2459225296319174666),  INT64_C( 2688435622857082015) },
      { -INT64_C( 6451348468142937712),  INT64_C( 2677809093420955447) },
      { -INT64_C( 6451348468142937712),  INT64_C( 2677809093420955447) } },
    { {  INT64_C( 1774526528294708772),  INT64_C( 6161175826539054950) },
      {  INT64_C(   50534417920201806), -INT64_C(   30690825137726145) },
      { -INT64_C( 2382857786477046436), -INT64_C( 5330650724638817045) },
      { -INT64_C( 2382857786477046436), -INT64_C( 5330650724638817045) } },
    { { -INT64_C( 2587467944325606067),  INT64_C( 4012668629107270868) },
      { -INT64_C( 4591423301560208654), -INT64_C( 8674084366207385472) },
      { -INT64_C( 5907116491427454325),  INT64_C( 2209873427225726873) },
      { -INT64_C( 5907116491427454325), -INT64_C( 2587467944325606067) } },
    { {  INT64_C( 3824910361258604926), -INT64_C( 8786315084476611249) },
      { -INT64_C(  313363687371985633), -INT64_C( 8120524421268044796) },
      { -INT64_C(  811220067518523693), -INT64_C( 5260611633037845636) },
      { -INT64_C( 5260611633037845636),  INT64_C( 3824910361258604926) } },
    { {  INT64_C( 7464810264407289147), -INT64_C(  722293234019661991) },
      {  INT64_C( 5788598675114417340), -INT64_C( 7249452481136569578) },
      { -INT64_C( 4450453183076494477),  INT64_C( 8569828625907242199) },
      {  INT64_C( 7464810264407289147), -INT64_C( 4450453183076494477) } },
    { { -INT64_C( 4889734200370435327),  INT64_C( 2664950865741933823) },
      { -INT64_C( 2590917768572685087),  INT64_C( 6717896597383231242) },
      {  INT64_C( 4436421935801438510), -INT64_C( 6190028595149276350) },
      {  INT64_C( 2664950865741933823),  INT64_C( 4436421935801438510) } },
    { {  INT64_C( 6029756168639091405),  INT64_C( 8426606836560986679) },
      { -INT64_C( 4836907258824023196), -INT64_C( 2068621079329341994) },
      {  INT64_C( 8392284445376528091),  INT64_C( 5088779378738368484) },
      {  INT64_C( 6029756168639091405),  INT64_C( 8392284445376528091) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_permutex2var_epi64(a, idx, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_permutex2var_epi64(a, idx, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const simde__mmask8 k;
    const int64_t idx[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 7543028266611185892), -INT64_C( 6539928377775161020) },
      UINT8_C(191),
      { -INT64_C( 3442877394007045646), -INT64_C( 1761197723447303559) },
      {  INT64_C( 8569295065047442400),  INT64_C( 8554558376476952183) },
      {  INT64_C( 8569295065047442400), -INT64_C( 6539928377775161020) } },
    { { -INT64_C( 7007880133205117778),  INT64_C( 5282052113479790949) },
      UINT8_C(193),
      {  INT64_C( 2571183598589112566),  INT64_C( 1333379257793488621) },
      { -INT64_C( 6895339577704746777), -INT64_C(  629287881478130459) },
      { -INT64_C( 6895339577704746777),  INT64_C( 5282052113479790949) } },
    { {  INT64_C( 1532027788627639107), -INT64_C( 1300860764580943486) },
      UINT8_C(218),
      { -INT64_C( 2746164267613235415),  INT64_C( 2686909180892833460) },
      { -INT64_C( 7684157274447844865),  INT64_C( 6309693911654415435) },
      {  INT64_C( 1532027788627639107),  INT64_C( 1532027788627639107) } },
    { { -INT64_C(  549658762569999776),  INT64_C(  751617401140754846) },
      UINT8_C(177),
      {  INT64_C( 9037301963785364668),  INT64_C( 5365480060888031373) },
      { -INT64_C( 7768560529860264871), -INT64_C( 6665140635439236730) },
      { -INT64_C(  549658762569999776),  INT64_C(  751617401140754846) } },
    { {  INT64_C( 6650741120286514574),  INT64_C( 6145137489363597389) },
      UINT8_C(229),
      { -INT64_C( 8078660489535494443),  INT64_C( 1057248810792104308) },
      { -INT64_C( 4587134168409998371),  INT64_C( 8105091314329867436) },
      {  INT64_C( 6145137489363597389),  INT64_C( 6145137489363597389) } },
    { {  INT64_C(  404672579086695671),  INT64_C(  909673452957537376) },
      UINT8_C( 74),
      { -INT64_C( 4511812508023908740),  INT64_C( 3501210561589082254) },
      {  INT64_C( 6244740346333471897),  INT64_C( 6270296949807987690) },
      {  INT64_C(  404672579086695671),  INT64_C( 6244740346333471897) } },
    { {  INT64_C( 8562873309074364071), -INT64_C( 7562480563159486104) },
      UINT8_C( 80),
      { -INT64_C( 4215957994269908787),  INT64_C( 5883942175734970222) },
      { -INT64_C( 4405734771213616381), -INT64_C( 8016591215279425596) },
      {  INT64_C( 8562873309074364071), -INT64_C( 7562480563159486104) } },
    { { -INT64_C( 6302891879744450248),  INT64_C( 2406133987713427416) },
      UINT8_C( 10),
      {  INT64_C( 2742794905676649629), -INT64_C( 8021340572815360226) },
      {  INT64_C( 2239822800200823196),  INT64_C( 2986553460037330970) },
      { -INT64_C( 6302891879744450248),  INT64_C( 2239822800200823196) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_permutex2var_epi64(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_permutex2var_epi64(a, k, idx, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask2_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const int64_t idx[4];
    const simde__mmask8 k;
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 2801679457820638586),  INT64_C(  203457781086025645) },
      { -INT64_C( 8465992442779047437),  INT64_C( 4024974182712644857) },
      UINT8_C( 22),
      { -INT64_C( 3238562174574543118),  INT64_C( 7602529172184444603) },
      { -INT64_C( 8465992442779047437),  INT64_C(  203457781086025645) } },
    { { -INT64_C(  551499208236670305), -INT64_C( 3815426458027164062) },
      { -INT64_C( 8192545992161328225),  INT64_C( 2581580203438172265) },
      UINT8_C(127),
      { -INT64_C( 2808033006703115529), -INT64_C( 8285077360635282043) },
      { -INT64_C( 8285077360635282043), -INT64_C( 3815426458027164062) } },
    { { -INT64_C( 5237985640399732565), -INT64_C( 9067893895777765365) },
      {  INT64_C( 7896269098771221728),  INT64_C( 8197072242104092715) },
      UINT8_C( 90),
      {  INT64_C( 6709484544437344034), -INT64_C(  407176718820260581) },
      {  INT64_C( 7896269098771221728), -INT64_C(  407176718820260581) } },
    { { -INT64_C(  942853577198398063),  INT64_C(  168650656867426083) },
      {  INT64_C( 8900291953104748673),  INT64_C( 7556281339435314421) },
      UINT8_C( 98),
      {  INT64_C( 3545175210209323199),  INT64_C(  459952681479450551) },
      {  INT64_C( 8900291953104748673),  INT64_C(  168650656867426083) } },
    { {  INT64_C( 8740889894934972456), -INT64_C( 3565241159132368427) },
      {  INT64_C( 5126239391095558880),  INT64_C( 8344196267645613631) },
      UINT8_C( 19),
      {  INT64_C( 5325955263526587186),  INT64_C( 2630426068575063272) },
      {  INT64_C( 8740889894934972456),  INT64_C( 2630426068575063272) } },
    { { -INT64_C( 3507744900370893821),  INT64_C( 1567971629313169188) },
      {  INT64_C( 7114019977990627672),  INT64_C( 4311498696811549215) },
      UINT8_C(249),
      { -INT64_C( 5284302775468798326), -INT64_C(  188395703719339652) },
      { -INT64_C( 3507744900370893821),  INT64_C( 4311498696811549215) } },
    { { -INT64_C( 6914193595038182440),  INT64_C( 2043249474898869469) },
      { -INT64_C( 3695119587732165022), -INT64_C( 2756703242194365786) },
      UINT8_C( 12),
      { -INT64_C( 8292187049094888139), -INT64_C( 7526857854022693356) },
      { -INT64_C( 3695119587732165022), -INT64_C( 2756703242194365786) } },
    { { -INT64_C( 7507583844654543396), -INT64_C( 8876469178637709174) },
      { -INT64_C( 5074572008342984137), -INT64_C( 3959106160021032243) },
      UINT8_C(250),
      {  INT64_C( 5851539042646094582),  INT64_C( 3609676646046562415) },
      { -INT64_C( 5074572008342984137), -INT64_C( 8876469178637709174) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask2_permutex2var_epi64(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask2_permutex2var_epi64(a, idx, k, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t idx[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(184),
      {  INT64_C( 8315058410344732703),  INT64_C(  901241208001548668) },
      {  INT64_C( 6296066776003062554),  INT64_C( 8835308594298569407) },
      {  INT64_C( 6282401473346000170),  INT64_C(  291154986868543459) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(142),
      { -INT64_C( 7514742692686989864),  INT64_C(  999918108119571300) },
      { -INT64_C( 2734178881431429991), -INT64_C( 1219974020720227296) },
      { -INT64_C( 6293045713091231811), -INT64_C( 6810499231030207433) },
      {  INT64_C(                   0), -INT64_C( 7514742692686989864) } },
    { UINT8_C(219),
      { -INT64_C( 1746409450162959260),  INT64_C( 6326411064036443717) },
      {  INT64_C( 2713211558092857043), -INT64_C(  595091341681223774) },
      {  INT64_C( 3052980837539275932),  INT64_C( 2184813489316978083) },
      {  INT64_C( 2184813489316978083),  INT64_C( 3052980837539275932) } },
    { UINT8_C(226),
      {  INT64_C( 5535928024616898285), -INT64_C( 2942302515214895681) },
      {  INT64_C( 6733697284015169905), -INT64_C( 5979155501241897697) },
      { -INT64_C( 4479478530377354925), -INT64_C(   94159367526435481) },
      {  INT64_C(                   0), -INT64_C(   94159367526435481) } },
    { UINT8_C( 27),
      { -INT64_C( 6020336063474840211),  INT64_C(  880764458998994464) },
      {  INT64_C( 5553729540801348344),  INT64_C(  843537205922819103) },
      {  INT64_C( 7535034862078513317),  INT64_C( 1157573637160500584) },
      { -INT64_C( 6020336063474840211),  INT64_C( 1157573637160500584) } },
    { UINT8_C( 73),
      { -INT64_C( 5112379643791361505),  INT64_C( 3136020862278804999) },
      { -INT64_C(  505004610110133566),  INT64_C( 3529168518355353898) },
      {  INT64_C( 1107933924008385242), -INT64_C( 2640950955453990957) },
      {  INT64_C( 1107933924008385242),  INT64_C(                   0) } },
    { UINT8_C(223),
      {  INT64_C( 7985676457707466956),  INT64_C( 6403468296150025186) },
      { -INT64_C( 7219710123367693105),  INT64_C( 2500500916436008031) },
      {  INT64_C( 4817617259592322304), -INT64_C( 2740966993719698912) },
      { -INT64_C( 2740966993719698912), -INT64_C( 2740966993719698912) } },
    { UINT8_C(165),
      { -INT64_C( 6907355642667084458),  INT64_C( 4064806163663157465) },
      {  INT64_C(  837628511598991074), -INT64_C( 8510132917449114338) },
      {  INT64_C( 7784599032857325508), -INT64_C(  625932087889363604) },
      {  INT64_C( 7784599032857325508),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_permutex2var_epi64(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_permutex2var_epi64(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t idx[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  20), -INT8_C(  24),  INT8_C( 118), -INT8_C(  59), -INT8_C(  62),  INT8_C(  21), -INT8_C(  47), -INT8_C(  32),
         INT8_C(  83), -INT8_C(  25),  INT8_C(  32), -INT8_C( 122), -INT8_C(  42),  INT8_C(   6),  INT8_C(  16), -INT8_C( 101) },
      {  INT8_C( 117),  INT8_C(  95),  INT8_C(   3),  INT8_C(   8), -INT8_C(  46),  INT8_C(  11),  INT8_C( 117),  INT8_C(  62),
         INT8_C(   8),  INT8_C(  74),  INT8_C(  86),  INT8_C(  29), -INT8_C( 119), -INT8_C(  90),  INT8_C(  20), -INT8_C(  99) },
      { -INT8_C( 114), -INT8_C( 118),  INT8_C(  99),  INT8_C(  80), -INT8_C(  96),  INT8_C(  52),  INT8_C(  48), -INT8_C(  13),
         INT8_C(  27),  INT8_C(  81),  INT8_C( 121), -INT8_C(  15),  INT8_C(  87), -INT8_C( 119), -INT8_C( 116), -INT8_C(  52) },
      {  INT8_C(  52), -INT8_C(  52), -INT8_C(  59),  INT8_C(  83),  INT8_C(  99), -INT8_C( 122),  INT8_C(  52), -INT8_C( 116),
         INT8_C(  83),  INT8_C(  32),  INT8_C(  48), -INT8_C( 119), -INT8_C(  25), -INT8_C(  47), -INT8_C(  96), -INT8_C( 119) } },
    { { -INT8_C(  24), -INT8_C( 113), -INT8_C(  44), -INT8_C(  69), -INT8_C( 102),  INT8_C(  73), -INT8_C(   7), -INT8_C(  93),
        -INT8_C( 108),  INT8_C(  79), -INT8_C(  64),  INT8_C(  29), -INT8_C(  11), -INT8_C(  43), -INT8_C(  70), -INT8_C( 125) },
      {  INT8_C(  95),  INT8_C(  29), -INT8_C(  45), -INT8_C(   1),  INT8_C(  81),  INT8_C(   4), -INT8_C(  14),  INT8_C( 108),
         INT8_C(  85),  INT8_C( 108),  INT8_C(  94), -INT8_C(  84), -INT8_C(  11), -INT8_C(  22),  INT8_C( 120), -INT8_C(  34) },
      {  INT8_C( 122),  INT8_C(  76), -INT8_C( 103),  INT8_C(  20), -INT8_C( 106), -INT8_C( 110), -INT8_C(  73),  INT8_C(  42),
        -INT8_C(  30),  INT8_C( 120),  INT8_C(  71), -INT8_C(  41),  INT8_C(  77),  INT8_C(   1),  INT8_C(  91), -INT8_C(  84) },
      { -INT8_C(  84),  INT8_C(   1),  INT8_C(  20), -INT8_C(  84),  INT8_C(  76), -INT8_C( 102), -INT8_C( 103), -INT8_C(  11),
        -INT8_C( 110), -INT8_C(  11),  INT8_C(  91), -INT8_C(  11), -INT8_C( 110), -INT8_C(  64), -INT8_C(  30),  INT8_C(  91) } },
    { {  INT8_C(  31),  INT8_C(  46), -INT8_C(  84),  INT8_C( 112),  INT8_C(  50), -INT8_C(  98), -INT8_C(  35), -INT8_C( 121),
         INT8_C(  10),  INT8_C(  59),  INT8_C(  51),  INT8_C(   0),  INT8_C(  37), -INT8_C(  85), -INT8_C(  34), -INT8_C(  97) },
      { -INT8_C(   8),  INT8_C( 119), -INT8_C(  76), -INT8_C( 114),  INT8_C(   9),  INT8_C( 107), -INT8_C(  72), -INT8_C(  21),
        -INT8_C(  29), -INT8_C(   1), -INT8_C(  61),  INT8_C(  48),  INT8_C(   0),  INT8_C(  30), -INT8_C(  35),  INT8_C(  31) },
      {  INT8_C(  76), -INT8_C( 119), -INT8_C( 112),      INT8_MAX,  INT8_C(  39),  INT8_C( 109),  INT8_C(   6),  INT8_C(  50),
        -INT8_C(  88),  INT8_C(  58),  INT8_C(  50), -INT8_C(  51), -INT8_C(  27),  INT8_C(  16),  INT8_C( 109), -INT8_C(  35) },
      { -INT8_C(  88),  INT8_C(  50),  INT8_C(  39), -INT8_C(  34),  INT8_C(  59),  INT8_C(   0), -INT8_C(  88),  INT8_C(   0),
         INT8_C( 112), -INT8_C(  35),  INT8_C( 112),  INT8_C(  76),  INT8_C(  31),  INT8_C( 109),  INT8_C(  16), -INT8_C(  35) } },
    { { -INT8_C( 121),  INT8_C(  33),  INT8_C( 107), -INT8_C( 112), -INT8_C( 116),  INT8_C(  35),  INT8_C( 124),  INT8_C( 112),
         INT8_C(  34),  INT8_C(  63), -INT8_C(  96),  INT8_C(  35),  INT8_C(  93),  INT8_C( 125),  INT8_C(  66), -INT8_C(  87) },
      {  INT8_C(   6), -INT8_C(  46),  INT8_C(  40),  INT8_C(  46),  INT8_C(  63),  INT8_C(  47),  INT8_C(  96), -INT8_C(  25),
         INT8_C( 105), -INT8_C( 110), -INT8_C(  75),  INT8_C(  78), -INT8_C(  94),  INT8_C(  34),  INT8_C(  44),  INT8_C(  41) },
      {  INT8_C(  67), -INT8_C( 105), -INT8_C(  71), -INT8_C(  49), -INT8_C(  69),  INT8_C(  53),  INT8_C(  63), -INT8_C(  35),
         INT8_C( 116), -INT8_C(  32),  INT8_C(   0), -INT8_C(  47),  INT8_C(  93),  INT8_C(  67),  INT8_C( 123),  INT8_C( 100) },
      {  INT8_C( 124), -INT8_C(  71),  INT8_C(  34),  INT8_C(  66),  INT8_C( 100), -INT8_C(  87), -INT8_C( 121),  INT8_C( 112),
         INT8_C(  63), -INT8_C(  71),  INT8_C(  53),  INT8_C(  66),  INT8_C( 107),  INT8_C( 107),  INT8_C(  93),  INT8_C(  63) } },
    { {  INT8_C(  21), -INT8_C(  93), -INT8_C( 110),  INT8_C(  85), -INT8_C(  46), -INT8_C(  14),  INT8_C(  60),  INT8_C(  59),
        -INT8_C( 124), -INT8_C(  15), -INT8_C( 118),  INT8_C(  38),  INT8_C(  19), -INT8_C(  74),  INT8_C(  79),  INT8_C(  86) },
      {  INT8_C(  77),  INT8_C(   8),  INT8_C(  38),  INT8_C(   8),  INT8_C(  62),  INT8_C( 101), -INT8_C(  26), -INT8_C(  78),
         INT8_C(  69), -INT8_C(  26), -INT8_C( 124), -INT8_C(  93),  INT8_C(  41), -INT8_C(   1),  INT8_C(   7),  INT8_C(  63) },
      { -INT8_C(  94), -INT8_C( 103), -INT8_C( 108),  INT8_C( 117), -INT8_C( 117), -INT8_C(  48), -INT8_C(  80),  INT8_C(  15),
        -INT8_C(  62),  INT8_C(  58),  INT8_C(  53), -INT8_C(  43), -INT8_C(  16), -INT8_C( 124),  INT8_C(  44),  INT8_C(  62) },
      { -INT8_C(  74), -INT8_C( 124),  INT8_C(  60), -INT8_C( 124),  INT8_C(  44), -INT8_C(  14),  INT8_C(  60), -INT8_C( 108),
        -INT8_C(  14),  INT8_C(  60), -INT8_C(  46),  INT8_C(  85), -INT8_C(  15),  INT8_C(  62),  INT8_C(  59),  INT8_C(  62) } },
    { { -INT8_C( 116),  INT8_C(  82),  INT8_C(  70), -INT8_C(  54), -INT8_C(  73),  INT8_C(  44),  INT8_C( 125), -INT8_C(   3),
         INT8_C(  19),  INT8_C(   1), -INT8_C(  96),  INT8_C(  60),  INT8_C(   0), -INT8_C(  89),  INT8_C( 123), -INT8_C(  94) },
      {  INT8_C(  64),  INT8_C(  15),  INT8_C(  23), -INT8_C(  53), -INT8_C(  32), -INT8_C(  56), -INT8_C(  38), -INT8_C(  94),
         INT8_C(   2),  INT8_C(  15),  INT8_C( 119), -INT8_C(  13), -INT8_C( 109), -INT8_C(  93),  INT8_C(  49),  INT8_C(  31) },
      { -INT8_C(  11),  INT8_C( 119), -INT8_C(  22), -INT8_C(  83), -INT8_C(  92),  INT8_C( 103), -INT8_C(  86), -INT8_C(  73),
         INT8_C( 104),  INT8_C(  74), -INT8_C(  13),  INT8_C( 104), -INT8_C(  15),  INT8_C( 111),  INT8_C(  10),  INT8_C(  49) },
      { -INT8_C( 116), -INT8_C(  94), -INT8_C(  73),  INT8_C(  60), -INT8_C( 116),  INT8_C(  19), -INT8_C(  13),  INT8_C(  70),
         INT8_C(  70), -INT8_C(  94), -INT8_C(  73), -INT8_C(  83), -INT8_C(  83), -INT8_C(  54),  INT8_C( 119),  INT8_C(  49) } },
    { {  INT8_C( 126),  INT8_C(  34), -INT8_C(   4),  INT8_C(  94), -INT8_C(  22), -INT8_C(  42),  INT8_C(   0), -INT8_C(  20),
        -INT8_C(  27),  INT8_C( 120), -INT8_C(  33),  INT8_C( 120),  INT8_C(  27),  INT8_C(  16), -INT8_C( 105),  INT8_C(  17) },
      { -INT8_C( 120), -INT8_C( 127), -INT8_C(  66),  INT8_C(  44), -INT8_C(  24),  INT8_C( 104), -INT8_C(  29),  INT8_C(  80),
        -INT8_C(  78), -INT8_C(  42), -INT8_C(  72), -INT8_C(  93),  INT8_C(  69), -INT8_C(  61), -INT8_C(  44), -INT8_C(  60) },
      { -INT8_C(  27), -INT8_C(  48),  INT8_C(  34), -INT8_C(  49), -INT8_C(  90),  INT8_C(  35), -INT8_C(  69), -INT8_C( 117),
        -INT8_C( 101), -INT8_C( 101),  INT8_C(   3), -INT8_C(  74), -INT8_C(  85), -INT8_C( 102), -INT8_C(  57),  INT8_C(  51) },
      { -INT8_C(  27),  INT8_C(  34), -INT8_C(  57),  INT8_C(  27), -INT8_C(  27), -INT8_C(  27),  INT8_C(  94), -INT8_C(  27),
         INT8_C(  34), -INT8_C(  69), -INT8_C( 101),  INT8_C(  94), -INT8_C(  42),  INT8_C(  94), -INT8_C(  90), -INT8_C(  22) } },
    { {  INT8_C(  28), -INT8_C( 123),  INT8_C(  95),  INT8_C(   4), -INT8_C(  19),  INT8_C(  66),  INT8_C(  85), -INT8_C(  97),
         INT8_C(  25),  INT8_C(  13),  INT8_C(  66),  INT8_C(  94), -INT8_C(  48),  INT8_C(  22),  INT8_C(  34), -INT8_C(  75) },
      { -INT8_C(  26),  INT8_C(  69), -INT8_C( 124), -INT8_C( 116),  INT8_C( 104),  INT8_C(  64),  INT8_C(  23),  INT8_C(   3),
        -INT8_C(  37),  INT8_C(  26), -INT8_C(  71), -INT8_C( 122), -INT8_C(  75), -INT8_C( 127), -INT8_C(  70), -INT8_C(  47) },
      {  INT8_C(   6),  INT8_C(  25), -INT8_C(  43), -INT8_C(  12),  INT8_C(  92),  INT8_C(  42), -INT8_C( 109),  INT8_C( 117),
         INT8_C(  56), -INT8_C(  42), -INT8_C(  45),  INT8_C(   8), -INT8_C(  20), -INT8_C(  10), -INT8_C(  66), -INT8_C(  45) },
      {  INT8_C(  85),  INT8_C(  66), -INT8_C(  19), -INT8_C(  48),  INT8_C(  25),  INT8_C(  28),  INT8_C( 117),  INT8_C(   4),
         INT8_C(   8), -INT8_C(  45), -INT8_C(  42),  INT8_C(  85),  INT8_C(  42), -INT8_C( 123), -INT8_C(  45),  INT8_C(  25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_permutex2var_epi8(a, idx, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_permutex2var_epi8(a, idx, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const simde__mmask16 k;
    const int8_t idx[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  59),  INT8_C(  66),  INT8_C(  95), -INT8_C(  93), -INT8_C( 126),  INT8_C( 119), -INT8_C(  90),  INT8_C(  93),
        -INT8_C( 111),  INT8_C(  95), -INT8_C(  28),  INT8_C(  70), -INT8_C(  32), -INT8_C(  98),  INT8_C(  23), -INT8_C(  25) },
      UINT16_C(60855),
      { -INT8_C(  37),  INT8_C(  19),  INT8_C(  23),  INT8_C( 110), -INT8_C( 120),  INT8_C(  79),  INT8_C(  68),  INT8_C(  92),
         INT8_C(  88),  INT8_C(  49),  INT8_C(  82),  INT8_C(  22),  INT8_C(   4), -INT8_C( 115),  INT8_C(  88),  INT8_C(  99) },
      {  INT8_C(  48), -INT8_C(  37), -INT8_C(  38), -INT8_C(  42),  INT8_C(  56),  INT8_C( 108),  INT8_C(  53),  INT8_C(  28),
        -INT8_C(  78),  INT8_C(  22), -INT8_C(  70), -INT8_C(  54), -INT8_C(   3),  INT8_C( 114), -INT8_C(  73), -INT8_C(  40) },
      { -INT8_C(  54), -INT8_C(  42),  INT8_C(  28), -INT8_C(  93), -INT8_C( 111), -INT8_C(  25), -INT8_C(  90), -INT8_C(   3),
        -INT8_C(  78),  INT8_C(  95), -INT8_C(  38),  INT8_C(  53), -INT8_C(  32), -INT8_C(  98), -INT8_C(  78), -INT8_C(  93) } },
    { { -INT8_C( 123), -INT8_C(  50),  INT8_C(  70),  INT8_C(  14),  INT8_C(  30), -INT8_C( 117),  INT8_C( 106),  INT8_C( 118),
        -INT8_C(  68), -INT8_C(  68), -INT8_C( 116), -INT8_C(  64),  INT8_C(  73), -INT8_C(  28),  INT8_C(  35),  INT8_C( 121) },
      UINT16_C(65215),
      {  INT8_C(  79), -INT8_C(   8),  INT8_C( 106), -INT8_C( 124),  INT8_C(  20),  INT8_C(  28), -INT8_C( 102), -INT8_C(  49),
        -INT8_C(  26), -INT8_C( 105),  INT8_C(  65), -INT8_C(  99),  INT8_C( 111), -INT8_C(  58),  INT8_C( 108), -INT8_C(  74) },
      { -INT8_C(  44), -INT8_C( 118),  INT8_C(  65),  INT8_C(  62),  INT8_C(   0), -INT8_C(   3), -INT8_C(   6), -INT8_C( 116),
        -INT8_C(  67),  INT8_C(  67),  INT8_C( 112), -INT8_C(  32), -INT8_C(  68),  INT8_C(  48), -INT8_C(  34),  INT8_C(  11) },
      {  INT8_C( 121), -INT8_C(  67), -INT8_C( 116),  INT8_C(  30),  INT8_C(   0), -INT8_C(  68),  INT8_C( 106),  INT8_C( 121),
        -INT8_C(  68), -INT8_C( 116), -INT8_C(  50),  INT8_C(  48),  INT8_C( 121),  INT8_C( 106),  INT8_C(  73), -INT8_C(   6) } },
    { {  INT8_C(  40),  INT8_C(  72), -INT8_C( 112),  INT8_C(  60),  INT8_C( 101),  INT8_C(  42),  INT8_C(  11),  INT8_C(  75),
        -INT8_C(  62),  INT8_C(  76), -INT8_C(  23),  INT8_C(  49),  INT8_C(  19),  INT8_C(  85), -INT8_C(  25), -INT8_C(  25) },
      UINT16_C(10463),
      {  INT8_C(  38), -INT8_C(  33),  INT8_C(  37),  INT8_C(  32),  INT8_C( 107), -INT8_C(  30),  INT8_C( 100), -INT8_C(  37),
        -INT8_C(  61),  INT8_C(  32),  INT8_C(  11), -INT8_C(  95),  INT8_C(  44),  INT8_C(  51), -INT8_C(  22), -INT8_C(  68) },
      {  INT8_C( 112),  INT8_C(  79), -INT8_C(  26),  INT8_C( 123), -INT8_C( 102), -INT8_C(  88), -INT8_C(  56), -INT8_C( 125),
        -INT8_C(  38), -INT8_C(  37), -INT8_C(  40), -INT8_C(  63), -INT8_C(  62), -INT8_C(  73), -INT8_C(  22), -INT8_C(  24) },
      {  INT8_C(  11), -INT8_C(  24),  INT8_C(  42),  INT8_C(  40),  INT8_C(  49),  INT8_C(  42),  INT8_C( 101), -INT8_C(  63),
        -INT8_C(  62),  INT8_C(  76), -INT8_C(  23),  INT8_C(  72),  INT8_C(  19),  INT8_C( 123), -INT8_C(  25), -INT8_C(  25) } },
    { { -INT8_C( 106),  INT8_C(  15),  INT8_C(   9),  INT8_C(   1), -INT8_C(  14),  INT8_C( 109), -INT8_C(  35), -INT8_C(  75),
        -INT8_C( 115), -INT8_C(  24),  INT8_C(  86), -INT8_C(  71),  INT8_C(  28),  INT8_C(  64),  INT8_C( 117), -INT8_C( 116) },
      UINT16_C(23695),
      {  INT8_C(   7),  INT8_C(  42),  INT8_C(   4), -INT8_C(  49), -INT8_C(  83), -INT8_C(  34), -INT8_C(  86), -INT8_C( 122),
        -INT8_C(  96),  INT8_C( 109),  INT8_C(  61), -INT8_C( 118),  INT8_C(  85), -INT8_C(  44), -INT8_C( 103),  INT8_C(  94) },
      { -INT8_C(  43), -INT8_C( 117), -INT8_C(  53), -INT8_C(  78),  INT8_C(  64),  INT8_C(  89), -INT8_C( 101), -INT8_C( 105),
         INT8_C(  18), -INT8_C(  73), -INT8_C(  41), -INT8_C( 120),  INT8_C(  67),  INT8_C( 103), -INT8_C(  28),  INT8_C(  74) },
      { -INT8_C(  75),  INT8_C(  86), -INT8_C(  14), -INT8_C( 116), -INT8_C(  14),  INT8_C( 109), -INT8_C(  35), -INT8_C(  35),
        -INT8_C( 115), -INT8_C(  24),  INT8_C( 103),  INT8_C(  86),  INT8_C(  89),  INT8_C(  64), -INT8_C(  73), -INT8_C( 116) } },
    { { -INT8_C( 111), -INT8_C(  24),  INT8_C(  26),  INT8_C(  62), -INT8_C(  57), -INT8_C(  60), -INT8_C(  60),  INT8_C( 103),
         INT8_C(  49),  INT8_C(   2), -INT8_C(  15), -INT8_C( 121), -INT8_C(  42), -INT8_C( 118), -INT8_C(  27), -INT8_C(  85) },
      UINT16_C(45334),
      {  INT8_C(  94),  INT8_C(  86),  INT8_C(  10), -INT8_C(   7), -INT8_C(  19),  INT8_C(  28), -INT8_C(  80), -INT8_C(  59),
        -INT8_C(  92), -INT8_C(  13),  INT8_C(  44), -INT8_C( 120),  INT8_C(  61), -INT8_C(  67),  INT8_C( 113),  INT8_C(  87) },
      { -INT8_C(   5),  INT8_C(  56),  INT8_C(  28), -INT8_C(  64), -INT8_C(  97),  INT8_C(  77), -INT8_C(  62), -INT8_C( 112),
        -INT8_C(  44), -INT8_C( 104),  INT8_C(  26), -INT8_C(  70),  INT8_C(  67),  INT8_C(  48),  INT8_C( 107), -INT8_C(  95) },
      { -INT8_C( 111), -INT8_C(  62), -INT8_C(  15),  INT8_C(  62), -INT8_C( 118), -INT8_C(  60), -INT8_C(  60),  INT8_C( 103),
        -INT8_C(  57),  INT8_C(   2), -INT8_C(  15), -INT8_C( 121),  INT8_C(  48),  INT8_C(  48), -INT8_C(  27), -INT8_C( 112) } },
    { { -INT8_C( 121),  INT8_C( 117), -INT8_C( 102),  INT8_C( 116), -INT8_C( 111),  INT8_C(  74),  INT8_C(  57),  INT8_C(  54),
         INT8_C(  61),  INT8_C( 101), -INT8_C(  66),  INT8_C( 123),  INT8_C(  34),  INT8_C(  47), -INT8_C(  46),  INT8_C(  30) },
      UINT16_C(61031),
      { -INT8_C(  34),  INT8_C(   6),  INT8_C(  60), -INT8_C(  96), -INT8_C( 106),  INT8_C(  16),  INT8_C(  56), -INT8_C(  79),
        -INT8_C(  54),  INT8_C( 123), -INT8_C(  31),  INT8_C(  53),  INT8_C(  29),  INT8_C( 104), -INT8_C(  86), -INT8_C(  73) },
      { -INT8_C(  35),  INT8_C(  60),  INT8_C(   2),  INT8_C(  22),  INT8_C( 114),  INT8_C(  63),  INT8_C( 124),  INT8_C(  48),
        -INT8_C(  70), -INT8_C(  98),  INT8_C(  96), -INT8_C( 115), -INT8_C(  68), -INT8_C(  57),  INT8_C( 123), -INT8_C( 102) },
      {  INT8_C( 123),  INT8_C(  57), -INT8_C(  68),  INT8_C( 116), -INT8_C( 111), -INT8_C(  35), -INT8_C(  70),  INT8_C(  54),
         INT8_C(  61), -INT8_C( 115),  INT8_C( 117),  INT8_C(  63),  INT8_C(  34),  INT8_C(  61), -INT8_C(  66),  INT8_C(  48) } },
    { { -INT8_C(  50), -INT8_C(  73),  INT8_C(  58),  INT8_C( 100), -INT8_C(  56),  INT8_C( 114),  INT8_C(  21), -INT8_C( 110),
        -INT8_C(  18), -INT8_C(   9), -INT8_C(  56),  INT8_C(  11),  INT8_C(  95),  INT8_C( 114), -INT8_C(  62),  INT8_C(  60) },
      UINT16_C(50350),
      {  INT8_C(  83),  INT8_C(  32),  INT8_C(   4), -INT8_C(  49),  INT8_C(  81), -INT8_C(  66),  INT8_C( 109), -INT8_C(  79),
         INT8_C(  75),  INT8_C(  42),  INT8_C( 120), -INT8_C(  57), -INT8_C(  60),  INT8_C(  70),  INT8_C( 126), -INT8_C(   1) },
      { -INT8_C(  85),  INT8_C(  70),  INT8_C( 113), -INT8_C(  64), -INT8_C(  39),  INT8_C(  95), -INT8_C(  73), -INT8_C(  95),
         INT8_C( 106),  INT8_C(  23),  INT8_C(  19),  INT8_C(  45),  INT8_C(  83), -INT8_C(  62), -INT8_C(  15), -INT8_C(  90) },
      { -INT8_C(  50), -INT8_C(  50), -INT8_C(  56),  INT8_C(  60), -INT8_C(  56), -INT8_C(  15),  INT8_C(  21),  INT8_C(  70),
        -INT8_C(  18), -INT8_C(   9),  INT8_C( 106),  INT8_C(  11),  INT8_C(  95),  INT8_C( 114), -INT8_C(  15), -INT8_C(  90) } },
    { { -INT8_C(  30), -INT8_C(  11),  INT8_C( 117),  INT8_C(  51), -INT8_C(  76), -INT8_C(  29), -INT8_C(  28), -INT8_C(   1),
         INT8_C(  13),  INT8_C(  93), -INT8_C(  58), -INT8_C(  47), -INT8_C(  93),  INT8_C(  69), -INT8_C(  48),  INT8_C(  78) },
      UINT16_C(17035),
      {  INT8_C(  15),  INT8_C( 100), -INT8_C(  95), -INT8_C(  58),  INT8_C(   5),  INT8_C(  12), -INT8_C(  35),  INT8_C(  25),
         INT8_C(  57),  INT8_C(  49), -INT8_C(  37),  INT8_C(  42), -INT8_C(  41), -INT8_C(  67),  INT8_C(  32),  INT8_C(  77) },
      { -INT8_C(  15), -INT8_C(  44),  INT8_C(  48), -INT8_C(  43), -INT8_C(  45),  INT8_C(  61),  INT8_C(  50), -INT8_C( 102),
         INT8_C(  14), -INT8_C(  42), -INT8_C(  33), -INT8_C(  33),  INT8_C(  36),  INT8_C( 106),  INT8_C(  33),  INT8_C(  51) },
      {  INT8_C(  78), -INT8_C(  76),  INT8_C( 117), -INT8_C(  28), -INT8_C(  76), -INT8_C(  29), -INT8_C(  28), -INT8_C(  42),
         INT8_C(  13), -INT8_C(  44), -INT8_C(  58), -INT8_C(  47), -INT8_C(  93),  INT8_C(  69), -INT8_C(  30),  INT8_C(  78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_permutex2var_epi8(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask_permutex2var_epi8(a, k, idx, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask2_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t idx[32];
    const simde__mmask16 k;
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C(  49), -INT8_C(  62), -INT8_C(   6), -INT8_C(  44), -INT8_C(  50), -INT8_C(  41), -INT8_C(  19),  INT8_C(   7),
         INT8_C(   8), -INT8_C(  56),  INT8_C(  50), -INT8_C(  32), -INT8_C( 122),  INT8_C(  82),  INT8_C(  45),  INT8_C( 119) },
      {  INT8_C(  38),  INT8_C(  93),  INT8_C(  76), -INT8_C(   7), -INT8_C( 102),      INT8_MAX, -INT8_C( 109), -INT8_C(  88),
         INT8_C(  85),  INT8_C( 114), -INT8_C( 121),  INT8_C( 121), -INT8_C(  35), -INT8_C(  88), -INT8_C(  83), -INT8_C(  84) },
      UINT16_C(42859),
      {      INT8_MIN,  INT8_C(  57),  INT8_C( 126),  INT8_C( 110),  INT8_C(  65), -INT8_C( 121),  INT8_C(  54),  INT8_C( 115),
         INT8_C( 103), -INT8_C(  68), -INT8_C(  59), -INT8_C( 108),  INT8_C(  51), -INT8_C(  21), -INT8_C(  15),      INT8_MIN },
      { -INT8_C(  19), -INT8_C(  21),  INT8_C(  76), -INT8_C(  68), -INT8_C( 102),      INT8_MIN,  INT8_C( 110), -INT8_C(  88),
        -INT8_C( 121),  INT8_C( 126),  INT8_C(   7),  INT8_C( 121), -INT8_C(  35),  INT8_C(   8), -INT8_C(  83), -INT8_C( 122) } },
    { { -INT8_C(  28), -INT8_C( 117), -INT8_C(   1),  INT8_C( 120),  INT8_C(  51),  INT8_C(  84), -INT8_C(  22), -INT8_C(  69),
        -INT8_C(  51), -INT8_C(  57),  INT8_C(  99),  INT8_C( 122),  INT8_C( 115), -INT8_C(  50),  INT8_C(  33), -INT8_C(  12) },
      {  INT8_C(   8), -INT8_C(  96),  INT8_C(  98),  INT8_C(  73),  INT8_C(  39), -INT8_C( 104), -INT8_C(  68), -INT8_C( 114),
         INT8_C(  85), -INT8_C( 127),  INT8_C(  34), -INT8_C( 120),  INT8_C( 108),  INT8_C(  19),  INT8_C(   8),  INT8_C(  80) },
      UINT16_C( 1950),
      { -INT8_C(  56), -INT8_C(  47),  INT8_C(  91), -INT8_C(  77), -INT8_C( 116),  INT8_C(  41),  INT8_C( 122), -INT8_C(  16),
        -INT8_C(  93), -INT8_C(  18), -INT8_C(  66), -INT8_C(  59), -INT8_C(  30), -INT8_C(  58),  INT8_C( 101),  INT8_C(  68) },
      {  INT8_C(   8), -INT8_C(  28), -INT8_C(   1), -INT8_C(  57), -INT8_C(  69), -INT8_C( 104), -INT8_C(  68),  INT8_C(  33),
         INT8_C(  41), -INT8_C( 117), -INT8_C(   1), -INT8_C( 120),  INT8_C( 108),  INT8_C(  19),  INT8_C(   8),  INT8_C(  80) } },
    { {  INT8_C(  15), -INT8_C( 116), -INT8_C(  36), -INT8_C(  53),  INT8_C(  26),  INT8_C(  49),  INT8_C(  76),  INT8_C(  60),
        -INT8_C(  70), -INT8_C(  72),  INT8_C(  79), -INT8_C(  62),  INT8_C(   9), -INT8_C(  19), -INT8_C(  54), -INT8_C(  47) },
      { -INT8_C(  66),  INT8_C(  37), -INT8_C( 124),  INT8_C(  75),  INT8_C(  78), -INT8_C(   1),  INT8_C(  59), -INT8_C(  14),
        -INT8_C(  19), -INT8_C(   7), -INT8_C(  73), -INT8_C(  49), -INT8_C(  64),  INT8_C(  28),  INT8_C(  19), -INT8_C(  49) },
      UINT16_C(61352),
      { -INT8_C( 101), -INT8_C(  62),  INT8_C(  33), -INT8_C(  25), -INT8_C(   2), -INT8_C(  37), -INT8_C(  96),  INT8_C(  77),
        -INT8_C(  99), -INT8_C(  87),  INT8_C(  58),  INT8_C( 103),  INT8_C( 122), -INT8_C(   8), -INT8_C( 115), -INT8_C(   1) },
      { -INT8_C(  66),  INT8_C(  37), -INT8_C( 124), -INT8_C(  62),  INT8_C(  78), -INT8_C(   1),  INT8_C(  59),  INT8_C(  33),
        -INT8_C(  19), -INT8_C(  87),  INT8_C(  77), -INT8_C(  47), -INT8_C(  64),  INT8_C( 122), -INT8_C(  25), -INT8_C(  47) } },
    { {  INT8_C(  67), -INT8_C(  37), -INT8_C(   2),  INT8_C( 126), -INT8_C(  51), -INT8_C(  21),  INT8_C( 120), -INT8_C( 124),
        -INT8_C(  70),  INT8_C(  56), -INT8_C(  96), -INT8_C(  51),  INT8_C(   7),  INT8_C(  72), -INT8_C(  68), -INT8_C(  94) },
      {  INT8_C(  10), -INT8_C(  35), -INT8_C( 118),  INT8_C(   8), -INT8_C(  72),  INT8_C(  42),  INT8_C(  85),  INT8_C(  86),
        -INT8_C(  45), -INT8_C( 113), -INT8_C(  67),  INT8_C(  77), -INT8_C( 120),  INT8_C(  74),  INT8_C(  76), -INT8_C(  53) },
      UINT16_C(18982),
      {  INT8_C(  74), -INT8_C(  13),  INT8_C(  53), -INT8_C(  62),  INT8_C( 120), -INT8_C(  17), -INT8_C(   6),  INT8_C(  24),
        -INT8_C(  68),  INT8_C(   1),  INT8_C(  97),  INT8_C( 121), -INT8_C(  92),  INT8_C( 107),  INT8_C(  86),  INT8_C(  46) },
      {  INT8_C(  10),  INT8_C( 107), -INT8_C(  96),  INT8_C(   8), -INT8_C(  72), -INT8_C(  96),  INT8_C(  85),  INT8_C(  86),
        -INT8_C(  45), -INT8_C(  94), -INT8_C(  67),  INT8_C(  72), -INT8_C( 120),  INT8_C(  74),  INT8_C(   7), -INT8_C(  53) } },
    { {  INT8_C( 116),  INT8_C(  15),  INT8_C(  88), -INT8_C(  55),  INT8_C( 101),  INT8_C(  43),  INT8_C(  89),  INT8_C(  34),
         INT8_C( 120), -INT8_C(  31),  INT8_C( 109), -INT8_C(  59), -INT8_C(  84), -INT8_C( 109),  INT8_C(  15), -INT8_C(  10) },
      { -INT8_C( 122),  INT8_C(  69), -INT8_C(  72), -INT8_C(   2),  INT8_C(  52), -INT8_C(  78),  INT8_C(  23), -INT8_C(  15),
        -INT8_C(  76),  INT8_C( 120),  INT8_C( 106),  INT8_C(  88), -INT8_C(  29), -INT8_C(  64), -INT8_C( 122),  INT8_C(  87) },
      UINT16_C(57039),
      {  INT8_C(  33),  INT8_C(  52),  INT8_C(   9),  INT8_C( 122),  INT8_C(  87), -INT8_C( 127),  INT8_C(  91), -INT8_C(  60),
         INT8_C(  70),  INT8_C(   7),  INT8_C(  87),  INT8_C(  86), -INT8_C(   2), -INT8_C(  35), -INT8_C( 101), -INT8_C(  74) },
      {  INT8_C(  89),  INT8_C(  43),  INT8_C(  70), -INT8_C( 101),  INT8_C(  52), -INT8_C(  78), -INT8_C(  60),  INT8_C(  52),
        -INT8_C(  76),  INT8_C(  70),  INT8_C( 109),  INT8_C(  70), -INT8_C(  55), -INT8_C(  64),  INT8_C(  89), -INT8_C(  60) } },
    { { -INT8_C(  36), -INT8_C(  49),  INT8_C( 105), -INT8_C(  13), -INT8_C(  64),  INT8_C(  29),  INT8_C( 107),  INT8_C(  42),
         INT8_C( 117),  INT8_C(  78), -INT8_C(  21), -INT8_C(   5), -INT8_C(  90), -INT8_C(  70), -INT8_C(  39), -INT8_C(  57) },
      { -INT8_C(  17), -INT8_C(  30),  INT8_C(  65),  INT8_C(  70),  INT8_C(  99), -INT8_C( 100),  INT8_C(  10), -INT8_C(  86),
        -INT8_C(  93),  INT8_C(  97),  INT8_C(   0), -INT8_C(  95),  INT8_C(  62), -INT8_C( 101),  INT8_C(  88),  INT8_C(  26) },
      UINT16_C(49514),
      {  INT8_C(  13),  INT8_C(  43), -INT8_C(  34),  INT8_C( 120),  INT8_C(  85),  INT8_C(  83), -INT8_C(  57),  INT8_C(  64),
         INT8_C(  78),  INT8_C( 109), -INT8_C(   5),  INT8_C(  39),  INT8_C(  52), -INT8_C(  22),  INT8_C(   9),  INT8_C( 117) },
      { -INT8_C(  17),  INT8_C( 105),  INT8_C(  65),  INT8_C( 107),  INT8_C(  99),  INT8_C(  52), -INT8_C(  21), -INT8_C(  86),
        -INT8_C(  13),  INT8_C(  97),  INT8_C(   0), -INT8_C(  95),  INT8_C(  62), -INT8_C( 101),  INT8_C(  78), -INT8_C(   5) } },
    { {  INT8_C(  48),  INT8_C( 108),  INT8_C(  17),  INT8_C(  58),  INT8_C(  22), -INT8_C(  76), -INT8_C( 101),  INT8_C(  22),
         INT8_C(  86), -INT8_C(  39), -INT8_C(  79), -INT8_C(  82), -INT8_C(  12),  INT8_C(  28),  INT8_C( 111),  INT8_C(   1) },
      {  INT8_C(  71),  INT8_C(  77),  INT8_C( 122), -INT8_C( 100), -INT8_C(  96),  INT8_C(  65), -INT8_C(  35), -INT8_C(  18),
        -INT8_C(  82), -INT8_C(  40),  INT8_C(  21), -INT8_C(  30), -INT8_C(  62),  INT8_C(  30),  INT8_C(  87), -INT8_C(  14) },
      UINT16_C(26762),
      {  INT8_C(  44), -INT8_C(  95),  INT8_C(  28), -INT8_C(  57), -INT8_C(  73),  INT8_C( 114), -INT8_C(  96),  INT8_C( 105),
         INT8_C(  32), -INT8_C( 108), -INT8_C( 123), -INT8_C( 113), -INT8_C( 106), -INT8_C(  52), -INT8_C(  36),  INT8_C(  16) },
      {  INT8_C(  71),  INT8_C(  28),  INT8_C( 122), -INT8_C( 106), -INT8_C(  96),  INT8_C(  65), -INT8_C(  35),  INT8_C( 111),
        -INT8_C(  82), -INT8_C(  40),  INT8_C(  21),  INT8_C(  17), -INT8_C(  62), -INT8_C(  36),  INT8_C( 105), -INT8_C(  14) } },
    { {  INT8_C( 104),  INT8_C( 124),  INT8_C(  81),  INT8_C(  69),  INT8_C( 106), -INT8_C(   1),  INT8_C(  29),      INT8_MAX,
        -INT8_C(  31), -INT8_C(  33), -INT8_C(  99),  INT8_C(  56), -INT8_C(  47),  INT8_C(  40), -INT8_C(  96), -INT8_C(   3) },
      { -INT8_C(  55), -INT8_C(  68), -INT8_C(  60),      INT8_MIN,  INT8_C(  47),  INT8_C( 101), -INT8_C(  23),  INT8_C(  79),
        -INT8_C(   7),  INT8_C( 110), -INT8_C(  33), -INT8_C( 113),  INT8_C(  58), -INT8_C(  69), -INT8_C(  97), -INT8_C(  93) },
      UINT16_C(61496),
      { -INT8_C(  24), -INT8_C(  94), -INT8_C(  17),  INT8_C(   6),  INT8_C(  34), -INT8_C(  48), -INT8_C(  27), -INT8_C(  65),
         INT8_C(   8), -INT8_C(  73), -INT8_C(  25), -INT8_C(  88), -INT8_C(  76), -INT8_C(  80),  INT8_C( 101),  INT8_C( 121) },
      { -INT8_C(  55), -INT8_C(  68), -INT8_C(  60),  INT8_C( 104), -INT8_C(   3), -INT8_C(   1), -INT8_C(  23),  INT8_C(  79),
        -INT8_C(   7),  INT8_C( 110), -INT8_C(  33), -INT8_C( 113), -INT8_C(  25), -INT8_C(  88),  INT8_C( 121),  INT8_C(  69) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask2_permutex2var_epi8(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask2_permutex2var_epi8(a, idx, k, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[32];
    const int8_t idx[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT16_C(37937),
      { -INT8_C(  34),  INT8_C(  26), -INT8_C(  29), -INT8_C(  41), -INT8_C( 119), -INT8_C(  62),  INT8_C( 103), -INT8_C(  61),
         INT8_C( 126),  INT8_C(   6),  INT8_C( 102), -INT8_C(  74), -INT8_C(   9),  INT8_C(  79),  INT8_C(  88), -INT8_C(  26) },
      {  INT8_C(  85),  INT8_C( 122), -INT8_C(  73),  INT8_C(  58),  INT8_C(  58), -INT8_C(  65), -INT8_C(  15),  INT8_C(  33),
         INT8_C( 104), -INT8_C(  90), -INT8_C(  46), -INT8_C(  51),  INT8_C(  31),  INT8_C(   3),  INT8_C(  97), -INT8_C(   3) },
      {  INT8_C(  29),  INT8_C(  68), -INT8_C(  44), -INT8_C(  90),  INT8_C(   7),  INT8_C(  59),  INT8_C( 106), -INT8_C( 123),
         INT8_C(  66), -INT8_C(  48),  INT8_C(  59),  INT8_C(  57),  INT8_C(  31), -INT8_C( 109),  INT8_C(  31),  INT8_C( 116) },
      {  INT8_C(  59),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  59),  INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  44),  INT8_C(   0),  INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 109) } },
    { UINT16_C(54798),
      { -INT8_C(  81),  INT8_C(  72), -INT8_C( 106), -INT8_C(  96),  INT8_C( 105), -INT8_C(   2),  INT8_C(  70),  INT8_C(  59),
        -INT8_C(  53),  INT8_C( 101),  INT8_C(  62),  INT8_C(  44),  INT8_C(  98),  INT8_C(  92),  INT8_C( 112),  INT8_C(  55) },
      {  INT8_C(   2),  INT8_C( 119),  INT8_C( 114),  INT8_C( 108), -INT8_C(   4), -INT8_C(  76),  INT8_C(  61),  INT8_C(  55),
        -INT8_C(  19),  INT8_C(  92), -INT8_C(  53),  INT8_C(  13), -INT8_C(  47), -INT8_C(  39), -INT8_C(  29),      INT8_MIN },
      {  INT8_C(  33),  INT8_C( 121),  INT8_C(  32), -INT8_C( 118),  INT8_C( 119),  INT8_C( 103), -INT8_C(  58),  INT8_C(  66),
        -INT8_C(  52),  INT8_C(   4),  INT8_C( 110),  INT8_C(  47),  INT8_C(  96), -INT8_C(  33),  INT8_C( 102),  INT8_C(  99) },
      {  INT8_C(   0),  INT8_C(  66),  INT8_C(  32),  INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  96),  INT8_C(  44),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0), -INT8_C(  96), -INT8_C(  81) } },
    { UINT16_C(55382),
      { -INT8_C(  49),  INT8_C(  83), -INT8_C( 115),  INT8_C(  12), -INT8_C( 118),  INT8_C( 122),  INT8_C( 105),  INT8_C(  85),
        -INT8_C( 121),  INT8_C(  58),  INT8_C(  46),  INT8_C( 107), -INT8_C(  70),  INT8_C(  79), -INT8_C(  28), -INT8_C(  38) },
      { -INT8_C(  38),  INT8_C(  92),  INT8_C(  65), -INT8_C(  96), -INT8_C(  98),  INT8_C(  14), -INT8_C(  92),  INT8_C(  13),
         INT8_C(  61),  INT8_C(   5), -INT8_C(  20), -INT8_C(  93),  INT8_C( 104),  INT8_C(  66),  INT8_C( 123),  INT8_C(  55) },
      { -INT8_C( 107),  INT8_C(   8),  INT8_C(  68),  INT8_C(  32), -INT8_C( 125), -INT8_C(  83),  INT8_C( 117),  INT8_C(  10),
        -INT8_C(  25), -INT8_C(  92),  INT8_C( 117), -INT8_C(  95), -INT8_C(  13),  INT8_C(  90),  INT8_C( 123), -INT8_C(  51) },
      {  INT8_C(   0), -INT8_C(  13),  INT8_C(  83),  INT8_C(   0),  INT8_C( 123),  INT8_C(   0), -INT8_C( 118),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  12), -INT8_C( 121),  INT8_C(   0), -INT8_C(  95),  INT8_C(  10) } },
    { UINT16_C(48566),
      {  INT8_C( 109),  INT8_C(  84), -INT8_C(  53),  INT8_C(  18),  INT8_C(  97),  INT8_C(   8),  INT8_C(  23),  INT8_C(  77),
        -INT8_C(  85),      INT8_MAX, -INT8_C( 112),  INT8_C(  38), -INT8_C(  74),  INT8_C(  37),  INT8_C(  47), -INT8_C(   6) },
      {  INT8_C(  69), -INT8_C(  78), -INT8_C(  89), -INT8_C(  69), -INT8_C(  68), -INT8_C( 114),  INT8_C(  95),  INT8_C(  50),
         INT8_C(  47),  INT8_C(  82), -INT8_C( 116), -INT8_C(  85),  INT8_C(  32),  INT8_C(  66),  INT8_C( 104), -INT8_C( 115) },
      { -INT8_C( 106),  INT8_C(  51), -INT8_C(  97), -INT8_C(   8),  INT8_C(  59), -INT8_C(  74),  INT8_C(  69), -INT8_C(  26),
         INT8_C(  53), -INT8_C(  43),  INT8_C(  12), -INT8_C(  20), -INT8_C(   5),  INT8_C(  59), -INT8_C(  26),  INT8_C(  64) },
      {  INT8_C(   0), -INT8_C(  97),  INT8_C(  77),  INT8_C(   0), -INT8_C(   5),  INT8_C(  47),  INT8_C(   0), -INT8_C(  97),
        -INT8_C(   6),  INT8_C(   0), -INT8_C(  74),  INT8_C(  38),  INT8_C( 109), -INT8_C(  53),  INT8_C(   0),  INT8_C(  37) } },
    { UINT16_C(36589),
      { -INT8_C(   5), -INT8_C(  86),  INT8_C(  28),  INT8_C(  90), -INT8_C(  36),  INT8_C(  76), -INT8_C(  83),  INT8_C( 104),
        -INT8_C(   9), -INT8_C(  51), -INT8_C(  86),  INT8_C(  95),  INT8_C(  90),  INT8_C(  64), -INT8_C( 110), -INT8_C(   6) },
      {  INT8_C(  56), -INT8_C(  51), -INT8_C(  80),  INT8_C( 126), -INT8_C(  77), -INT8_C(  26),  INT8_C(  83), -INT8_C(  65),
        -INT8_C(  46),  INT8_C(  78), -INT8_C(   5), -INT8_C(  72), -INT8_C( 113), -INT8_C(  24),  INT8_C(  70), -INT8_C( 118) },
      { -INT8_C( 110),  INT8_C(  99), -INT8_C(  27),  INT8_C( 110), -INT8_C(  81), -INT8_C( 110), -INT8_C(  42), -INT8_C(  90),
         INT8_C(  95),      INT8_MIN,  INT8_C(   5), -INT8_C(  71), -INT8_C(  63), -INT8_C( 105), -INT8_C(  77), -INT8_C(   7) },
      {  INT8_C(  95),  INT8_C(   0), -INT8_C( 110), -INT8_C(  77),  INT8_C(   0), -INT8_C(  83),  INT8_C( 110), -INT8_C(   7),
         INT8_C(   0), -INT8_C( 110), -INT8_C(  71),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  86) } },
    { UINT16_C(25700),
      {  INT8_C( 119),  INT8_C(  23),  INT8_C(  74), -INT8_C(  53), -INT8_C(  42),  INT8_C(  28),  INT8_C(  25), -INT8_C(  47),
        -INT8_C(  44), -INT8_C(  88), -INT8_C(  70),  INT8_C(  27),  INT8_C(  51),  INT8_C(  76),  INT8_C( 126),  INT8_C(  24) },
      { -INT8_C(  69),  INT8_C(  45), -INT8_C(  86), -INT8_C( 111), -INT8_C(  45),  INT8_C(   9),  INT8_C(  18), -INT8_C(  40),
        -INT8_C(  62), -INT8_C(  45),  INT8_C( 111),  INT8_C( 118), -INT8_C(  52), -INT8_C(  45), -INT8_C(  38),  INT8_C(  68) },
      { -INT8_C(  22),  INT8_C(  36),  INT8_C(  15), -INT8_C(  64),  INT8_C(  64),  INT8_C(  40), -INT8_C( 110),  INT8_C(  20),
        -INT8_C(  47),  INT8_C(  76),  INT8_C(  47),  INT8_C(   4), -INT8_C( 104), -INT8_C(  83),  INT8_C(  28),  INT8_C(  83) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  70),  INT8_C(   0),  INT8_C(   0), -INT8_C(  88),  INT8_C(  15),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(  47),  INT8_C(   0) } },
    { UINT16_C(50906),
      { -INT8_C(  27), -INT8_C(  83), -INT8_C(  49), -INT8_C(   9), -INT8_C( 123), -INT8_C( 111), -INT8_C(  54), -INT8_C(  12),
         INT8_C(   7), -INT8_C( 106), -INT8_C(  57), -INT8_C(  31), -INT8_C(  38), -INT8_C(  79),  INT8_C(   5), -INT8_C(  23) },
      {  INT8_C( 114),  INT8_C(  69),  INT8_C(  18),  INT8_C(   4),  INT8_C(  90), -INT8_C(  29),  INT8_C(  80), -INT8_C( 119),
        -INT8_C(  25), -INT8_C(  24),  INT8_C(  55),  INT8_C(   3),  INT8_C(  60),  INT8_C(  17), -INT8_C(  55),  INT8_C(  33) },
      { -INT8_C(  65), -INT8_C( 104),  INT8_C(  24),  INT8_C(  68),  INT8_C(  41), -INT8_C(  30),  INT8_C(  57),  INT8_C(  49),
         INT8_C( 120),  INT8_C(   0),  INT8_C(  18),  INT8_C(  83), -INT8_C(  78),  INT8_C(  24),  INT8_C(  60),  INT8_C(  36) },
      {  INT8_C(   0), -INT8_C( 111),  INT8_C(   0), -INT8_C( 123),  INT8_C(  18),  INT8_C(   0), -INT8_C(  65), -INT8_C( 106),
         INT8_C(   0),  INT8_C(   7),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 106), -INT8_C(  83) } },
    { UINT16_C(20061),
      {  INT8_C(  40), -INT8_C(  73),  INT8_C(  49),  INT8_C( 120),  INT8_C(  65),  INT8_C(  24),  INT8_C(  96),  INT8_C( 120),
         INT8_C(  27), -INT8_C( 100), -INT8_C( 119), -INT8_C(  28), -INT8_C(  67),  INT8_C(  72),  INT8_C( 124), -INT8_C(  43) },
      { -INT8_C( 115), -INT8_C(  90), -INT8_C(  73), -INT8_C(  58), -INT8_C(  41),  INT8_C(  48), -INT8_C(  58), -INT8_C(  23),
        -INT8_C( 125),  INT8_C( 120),  INT8_C(   1), -INT8_C(  65), -INT8_C( 100),  INT8_C(  95),  INT8_C(  14), -INT8_C(  60) },
      {  INT8_C(  22),  INT8_C(  63),  INT8_C(  60),  INT8_C(  87),  INT8_C(  88), -INT8_C(  99), -INT8_C(  49),  INT8_C( 115),
         INT8_C(  57),  INT8_C(  89),  INT8_C(  88), -INT8_C(   9), -INT8_C(  95), -INT8_C(  44), -INT8_C(  52),  INT8_C(  46) },
      {  INT8_C(  72),  INT8_C(   0),  INT8_C( 115),  INT8_C(  96),  INT8_C( 115),  INT8_C(   0),  INT8_C(  96),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  57), -INT8_C(  73),  INT8_C(  46),  INT8_C(   0),  INT8_C(   0),  INT8_C( 124),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi8(test_vec[i].idx);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_permutex2var_epi8(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i idx = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_maskz_permutex2var_epi8(k, a, idx, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 a[4];
    const int64_t idx[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   266.06), SIMDE_FLOAT64_C(   744.58) },
      {  INT64_C( 2866518622857575137), -INT64_C(   70274485513066767) },
      { SIMDE_FLOAT64_C(  -564.11), SIMDE_FLOAT64_C(   228.84) },
      { SIMDE_FLOAT64_C(   744.58), SIMDE_FLOAT64_C(   744.58) } },
    { { SIMDE_FLOAT64_C(  -667.55), SIMDE_FLOAT64_C(   -62.50) },
      {  INT64_C( 2359109570743171007),  INT64_C( 1888561416568168530) },
      { SIMDE_FLOAT64_C(    32.27), SIMDE_FLOAT64_C(  -339.12) },
      { SIMDE_FLOAT64_C(  -339.12), SIMDE_FLOAT64_C(    32.27) } },
    { { SIMDE_FLOAT64_C(   368.54), SIMDE_FLOAT64_C(   616.08) },
      {  INT64_C( 3682737025744534114), -INT64_C( 3543321188468379579) },
      { SIMDE_FLOAT64_C(   916.80), SIMDE_FLOAT64_C(  -773.58) },
      { SIMDE_FLOAT64_C(   916.80), SIMDE_FLOAT64_C(   616.08) } },
    { { SIMDE_FLOAT64_C(   267.08), SIMDE_FLOAT64_C(  -489.27) },
      { -INT64_C( 1214123070397285263), -INT64_C( 5616835484101678963) },
      { SIMDE_FLOAT64_C(   601.50), SIMDE_FLOAT64_C(   563.87) },
      { SIMDE_FLOAT64_C(  -489.27), SIMDE_FLOAT64_C(  -489.27) } },
    { { SIMDE_FLOAT64_C(    53.28), SIMDE_FLOAT64_C(  -121.26) },
      { -INT64_C( 8120324682462519208), -INT64_C( 5054143542780805793) },
      { SIMDE_FLOAT64_C(   -86.54), SIMDE_FLOAT64_C(  -771.73) },
      { SIMDE_FLOAT64_C(    53.28), SIMDE_FLOAT64_C(  -771.73) } },
    { { SIMDE_FLOAT64_C(   696.37), SIMDE_FLOAT64_C(  -449.91) },
      { -INT64_C( 6341298119235143830), -INT64_C( 4742401433874209450) },
      { SIMDE_FLOAT64_C(  -228.37), SIMDE_FLOAT64_C(  -420.09) },
      { SIMDE_FLOAT64_C(  -228.37), SIMDE_FLOAT64_C(  -228.37) } },
    { { SIMDE_FLOAT64_C(    68.99), SIMDE_FLOAT64_C(    66.57) },
      { -INT64_C( 4778752305038490181),  INT64_C( 4840825679982319224) },
      { SIMDE_FLOAT64_C(  -375.97), SIMDE_FLOAT64_C(  -736.00) },
      { SIMDE_FLOAT64_C(  -736.00), SIMDE_FLOAT64_C(    68.99) } },
    { { SIMDE_FLOAT64_C(  -140.34), SIMDE_FLOAT64_C(  -974.54) },
      { -INT64_C( 8154202376932849390),  INT64_C( 4729327344514770161) },
      { SIMDE_FLOAT64_C(  -658.78), SIMDE_FLOAT64_C(   358.05) },
      { SIMDE_FLOAT64_C(  -658.78), SIMDE_FLOAT64_C(  -974.54) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_permutex2var_pd(a, idx, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_permutex2var_pd(a, idx, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 a[4];
    const simde__mmask8 k;
    const int64_t idx[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -885.68), SIMDE_FLOAT64_C(   794.73) },
      UINT8_C(165),
      {  INT64_C( 2179239678391337709), -INT64_C( 8228278719115897823) },
      { SIMDE_FLOAT64_C(  -869.89), SIMDE_FLOAT64_C(   -18.96) },
      { SIMDE_FLOAT64_C(   794.73), SIMDE_FLOAT64_C(   794.73) } },
    { { SIMDE_FLOAT64_C(  -460.41), SIMDE_FLOAT64_C(  -989.41) },
      UINT8_C(181),
      { -INT64_C( 6045220835677475797), -INT64_C( 1539500220766109457) },
      { SIMDE_FLOAT64_C(   457.21), SIMDE_FLOAT64_C(   356.40) },
      { SIMDE_FLOAT64_C(   356.40), SIMDE_FLOAT64_C(  -989.41) } },
    { { SIMDE_FLOAT64_C(  -388.55), SIMDE_FLOAT64_C(  -109.59) },
      UINT8_C(240),
      { -INT64_C( 3539169254304005194),  INT64_C( 5743432299311634587) },
      { SIMDE_FLOAT64_C(  -644.32), SIMDE_FLOAT64_C(  -714.64) },
      { SIMDE_FLOAT64_C(  -388.55), SIMDE_FLOAT64_C(  -109.59) } },
    { { SIMDE_FLOAT64_C(   410.34), SIMDE_FLOAT64_C(   625.69) },
      UINT8_C(250),
      {  INT64_C( 5427515123186161136), -INT64_C( 3232029291155733998) },
      { SIMDE_FLOAT64_C(   741.50), SIMDE_FLOAT64_C(  -336.20) },
      { SIMDE_FLOAT64_C(   410.34), SIMDE_FLOAT64_C(   741.50) } },
    { { SIMDE_FLOAT64_C(  -542.46), SIMDE_FLOAT64_C(   978.14) },
      UINT8_C(237),
      { -INT64_C( 3635931506042322827),  INT64_C( 9135638802339824692) },
      { SIMDE_FLOAT64_C(  -632.49), SIMDE_FLOAT64_C(  -921.53) },
      { SIMDE_FLOAT64_C(   978.14), SIMDE_FLOAT64_C(   978.14) } },
    { { SIMDE_FLOAT64_C(   780.08), SIMDE_FLOAT64_C(  -493.39) },
      UINT8_C( 20),
      { -INT64_C( 6810002066634023067), -INT64_C( 5705426183989531901) },
      { SIMDE_FLOAT64_C(  -300.37), SIMDE_FLOAT64_C(   736.42) },
      { SIMDE_FLOAT64_C(   780.08), SIMDE_FLOAT64_C(  -493.39) } },
    { { SIMDE_FLOAT64_C(   269.97), SIMDE_FLOAT64_C(   873.11) },
      UINT8_C( 93),
      {  INT64_C( 8451372922109257325), -INT64_C(  304725281487495630) },
      { SIMDE_FLOAT64_C(   286.92), SIMDE_FLOAT64_C(  -246.02) },
      { SIMDE_FLOAT64_C(   873.11), SIMDE_FLOAT64_C(   873.11) } },
    { { SIMDE_FLOAT64_C(   -82.47), SIMDE_FLOAT64_C(  -217.25) },
      UINT8_C(125),
      {  INT64_C(  123156418051075138),  INT64_C( 1019402031995949786) },
      { SIMDE_FLOAT64_C(   -85.30), SIMDE_FLOAT64_C(   529.62) },
      { SIMDE_FLOAT64_C(   -85.30), SIMDE_FLOAT64_C(  -217.25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask_permutex2var_pd(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_mask_permutex2var_pd(a, k, idx, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask2_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 a[4];
    const int64_t idx[4];
    const simde__mmask8 k;
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   830.45), SIMDE_FLOAT64_C(  -172.42) },
      {  INT64_C( 4650192850772568310), -INT64_C( 4573139603663607562) },
      UINT8_C( 68),
      { SIMDE_FLOAT64_C(  -762.66), SIMDE_FLOAT64_C(   535.67) },
      { SIMDE_FLOAT64_C(   793.72), SIMDE_FLOAT64_C(  -798.22) } },
    { { SIMDE_FLOAT64_C(   938.33), SIMDE_FLOAT64_C(   524.27) },
      { -INT64_C( 4573912516357468979), -INT64_C( 4584096544897651180) },
      UINT8_C( 13),
      { SIMDE_FLOAT64_C(  -216.11), SIMDE_FLOAT64_C(   121.15) },
      { SIMDE_FLOAT64_C(   524.27), SIMDE_FLOAT64_C(  -144.14) } },
    { { SIMDE_FLOAT64_C(   731.29), SIMDE_FLOAT64_C(  -644.61) },
      { -INT64_C( 4573329423351026811),  INT64_C( 4643958531882148168) },
      UINT8_C(196),
      { SIMDE_FLOAT64_C(    62.00), SIMDE_FLOAT64_C(  -864.37) },
      { SIMDE_FLOAT64_C(  -776.64), SIMDE_FLOAT64_C(   298.48) } },
    { { SIMDE_FLOAT64_C(  -229.25), SIMDE_FLOAT64_C(   143.95) },
      { -INT64_C( 4575088026228956856),  INT64_C( 4648156115433276047) },
      UINT8_C( 29),
      { SIMDE_FLOAT64_C(   985.24), SIMDE_FLOAT64_C(  -167.35) },
      { SIMDE_FLOAT64_C(  -229.25), SIMDE_FLOAT64_C(   562.17) } },
    { { SIMDE_FLOAT64_C(  -817.77), SIMDE_FLOAT64_C(  -100.06) },
      { -INT64_C( 4574551288632741724), -INT64_C( 4571476262473108029) },
      UINT8_C(228),
      { SIMDE_FLOAT64_C(  -844.00), SIMDE_FLOAT64_C(  -785.54) },
      { SIMDE_FLOAT64_C(  -637.73), SIMDE_FLOAT64_C(  -987.32) } },
    { { SIMDE_FLOAT64_C(   649.13), SIMDE_FLOAT64_C(  -606.66) },
      {  INT64_C( 4649809429077730263),  INT64_C( 4648378568625807688) },
      UINT8_C(175),
      { SIMDE_FLOAT64_C(  -960.22), SIMDE_FLOAT64_C(  -556.68) },
      { SIMDE_FLOAT64_C(  -556.68), SIMDE_FLOAT64_C(   649.13) } },
    { { SIMDE_FLOAT64_C(  -775.38), SIMDE_FLOAT64_C(  -176.33) },
      {  INT64_C( 4648176258486296904),  INT64_C( 4651619577060770447) },
      UINT8_C(137),
      { SIMDE_FLOAT64_C(   787.83), SIMDE_FLOAT64_C(   254.39) },
      { SIMDE_FLOAT64_C(  -775.38), SIMDE_FLOAT64_C(   955.92) } },
    { { SIMDE_FLOAT64_C(   805.57), SIMDE_FLOAT64_C(  -150.17) },
      {  INT64_C( 4645568920592654008), -INT64_C( 4577210963279866757) },
      UINT8_C(105),
      { SIMDE_FLOAT64_C(   813.31), SIMDE_FLOAT64_C(  -861.51) },
      { SIMDE_FLOAT64_C(   805.57), SIMDE_FLOAT64_C(  -423.68) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask2_permutex2var_pd(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i idx = simde_mm_castpd_si128(simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_mask2_permutex2var_pd(a, idx, k, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const int64_t idx[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(134),
      { SIMDE_FLOAT64_C(   798.55), SIMDE_FLOAT64_C(   -28.86) },
      { -INT64_C( 5234165115708920910),  INT64_C( 6259940836224545394) },
      { SIMDE_FLOAT64_C(   670.39), SIMDE_FLOAT64_C(   980.89) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   670.39) } },
    { UINT8_C(223),
      { SIMDE_FLOAT64_C(   458.22), SIMDE_FLOAT64_C(   235.28) },
      { -INT64_C( 6133148272475915475), -INT64_C( 6918802135733980991) },
      { SIMDE_FLOAT64_C(   976.22), SIMDE_FLOAT64_C(   436.82) },
      { SIMDE_FLOAT64_C(   235.28), SIMDE_FLOAT64_C(   235.28) } },
    { UINT8_C( 18),
      { SIMDE_FLOAT64_C(  -142.32), SIMDE_FLOAT64_C(    99.43) },
      {  INT64_C( 4983386258217242676), -INT64_C(  136643658833065413) },
      { SIMDE_FLOAT64_C(   927.46), SIMDE_FLOAT64_C(   967.68) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   967.68) } },
    { UINT8_C(192),
      { SIMDE_FLOAT64_C(  -657.07), SIMDE_FLOAT64_C(   895.69) },
      { -INT64_C( 1307324981216330964), -INT64_C( 3174417301149471108) },
      { SIMDE_FLOAT64_C(   246.17), SIMDE_FLOAT64_C(   324.96) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 14),
      { SIMDE_FLOAT64_C(   408.71), SIMDE_FLOAT64_C(  -497.75) },
      {  INT64_C( 8494812220930504452),  INT64_C( 1357776601162581184) },
      { SIMDE_FLOAT64_C(  -755.26), SIMDE_FLOAT64_C(   128.82) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   408.71) } },
    { UINT8_C(142),
      { SIMDE_FLOAT64_C(  -458.03), SIMDE_FLOAT64_C(  -498.64) },
      {  INT64_C( 9026187197985430298), -INT64_C( 4230674304573706788) },
      { SIMDE_FLOAT64_C(    53.78), SIMDE_FLOAT64_C(   981.38) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -458.03) } },
    { UINT8_C(133),
      { SIMDE_FLOAT64_C(   215.38), SIMDE_FLOAT64_C(   267.34) },
      { -INT64_C( 4099173715614750847), -INT64_C( 8057523459168599774) },
      { SIMDE_FLOAT64_C(   649.79), SIMDE_FLOAT64_C(  -296.26) },
      { SIMDE_FLOAT64_C(   267.34), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(108),
      { SIMDE_FLOAT64_C(   -98.98), SIMDE_FLOAT64_C(   193.37) },
      { -INT64_C( 8428680193957347328),  INT64_C( 7077518496431368408) },
      { SIMDE_FLOAT64_C(  -565.11), SIMDE_FLOAT64_C(    34.47) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi64(test_vec[i].idx);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_maskz_permutex2var_pd(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i idx = simde_test_x86_random_i64x2();
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_maskz_permutex2var_pd(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float32 a[8];
    const int32_t idx[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -588.11), SIMDE_FLOAT32_C(  -504.46), SIMDE_FLOAT32_C(  -488.73), SIMDE_FLOAT32_C(   557.45) },
      {  INT32_C(   762301853),  INT32_C(   463084285),  INT32_C(   324835910), -INT32_C(   362520093) },
      { SIMDE_FLOAT32_C(  -920.04), SIMDE_FLOAT32_C(  -710.31), SIMDE_FLOAT32_C(   637.33), SIMDE_FLOAT32_C(  -474.92) },
      { SIMDE_FLOAT32_C(  -710.31), SIMDE_FLOAT32_C(  -710.31), SIMDE_FLOAT32_C(   637.33), SIMDE_FLOAT32_C(   557.45) } },
    { { SIMDE_FLOAT32_C(  -342.35), SIMDE_FLOAT32_C(  -610.76), SIMDE_FLOAT32_C(   400.68), SIMDE_FLOAT32_C(  -237.86) },
      { -INT32_C(   881664185),  INT32_C(      938594),  INT32_C(   472743199), -INT32_C(   566704233) },
      { SIMDE_FLOAT32_C(   618.15), SIMDE_FLOAT32_C(   845.27), SIMDE_FLOAT32_C(  -347.60), SIMDE_FLOAT32_C(   647.55) },
      { SIMDE_FLOAT32_C(   647.55), SIMDE_FLOAT32_C(   400.68), SIMDE_FLOAT32_C(   647.55), SIMDE_FLOAT32_C(   647.55) } },
    { { SIMDE_FLOAT32_C(   232.91), SIMDE_FLOAT32_C(  -308.31), SIMDE_FLOAT32_C(  -152.75), SIMDE_FLOAT32_C(   312.87) },
      { -INT32_C(   858029679), -INT32_C(  1388365466),  INT32_C(  2071572760),  INT32_C(   578520835) },
      { SIMDE_FLOAT32_C(   150.94), SIMDE_FLOAT32_C(   144.27), SIMDE_FLOAT32_C(     7.48), SIMDE_FLOAT32_C(   776.03) },
      { SIMDE_FLOAT32_C(  -308.31), SIMDE_FLOAT32_C(     7.48), SIMDE_FLOAT32_C(   232.91), SIMDE_FLOAT32_C(   312.87) } },
    { { SIMDE_FLOAT32_C(   921.94), SIMDE_FLOAT32_C(   752.21), SIMDE_FLOAT32_C(   424.16), SIMDE_FLOAT32_C(   540.08) },
      {  INT32_C(     1469195),  INT32_C(  1390560705),  INT32_C(   757054918),  INT32_C(   265969398) },
      { SIMDE_FLOAT32_C(   987.63), SIMDE_FLOAT32_C(  -346.72), SIMDE_FLOAT32_C(   699.38), SIMDE_FLOAT32_C(  -506.70) },
      { SIMDE_FLOAT32_C(   540.08), SIMDE_FLOAT32_C(   752.21), SIMDE_FLOAT32_C(   699.38), SIMDE_FLOAT32_C(   699.38) } },
    { { SIMDE_FLOAT32_C(     8.80), SIMDE_FLOAT32_C(  -187.71), SIMDE_FLOAT32_C(  -281.06), SIMDE_FLOAT32_C(  -840.26) },
      {  INT32_C(   494630317), -INT32_C(   135268884),  INT32_C(   569836896),  INT32_C(   276093514) },
      { SIMDE_FLOAT32_C(  -969.03), SIMDE_FLOAT32_C(   343.07), SIMDE_FLOAT32_C(  -446.19), SIMDE_FLOAT32_C(   250.81) },
      { SIMDE_FLOAT32_C(   343.07), SIMDE_FLOAT32_C(  -969.03), SIMDE_FLOAT32_C(     8.80), SIMDE_FLOAT32_C(  -281.06) } },
    { { SIMDE_FLOAT32_C(   132.92), SIMDE_FLOAT32_C(  -478.94), SIMDE_FLOAT32_C(   544.87), SIMDE_FLOAT32_C(   120.55) },
      {  INT32_C(  1175791467), -INT32_C(   651867348), -INT32_C(  1393057600), -INT32_C(   173807979) },
      { SIMDE_FLOAT32_C(   916.37), SIMDE_FLOAT32_C(  -479.54), SIMDE_FLOAT32_C(   279.87), SIMDE_FLOAT32_C(  -442.55) },
      { SIMDE_FLOAT32_C(   120.55), SIMDE_FLOAT32_C(   916.37), SIMDE_FLOAT32_C(   132.92), SIMDE_FLOAT32_C(  -479.54) } },
    { { SIMDE_FLOAT32_C(  -429.78), SIMDE_FLOAT32_C(   234.27), SIMDE_FLOAT32_C(   717.98), SIMDE_FLOAT32_C(  -398.81) },
      {  INT32_C(   261784350),  INT32_C(   101791643), -INT32_C(  1974720930),  INT32_C(   828600689) },
      { SIMDE_FLOAT32_C(  -228.13), SIMDE_FLOAT32_C(  -397.66), SIMDE_FLOAT32_C(  -625.50), SIMDE_FLOAT32_C(  -589.53) },
      { SIMDE_FLOAT32_C(  -625.50), SIMDE_FLOAT32_C(  -398.81), SIMDE_FLOAT32_C(  -625.50), SIMDE_FLOAT32_C(   234.27) } },
    { { SIMDE_FLOAT32_C(   912.50), SIMDE_FLOAT32_C(   -11.54), SIMDE_FLOAT32_C(   485.57), SIMDE_FLOAT32_C(   828.88) },
      { -INT32_C(  1889488102),  INT32_C(  1553704510), -INT32_C(   999606999), -INT32_C(   892699540) },
      { SIMDE_FLOAT32_C(   562.77), SIMDE_FLOAT32_C(   286.45), SIMDE_FLOAT32_C(   267.97), SIMDE_FLOAT32_C(  -659.79) },
      { SIMDE_FLOAT32_C(   485.57), SIMDE_FLOAT32_C(   267.97), SIMDE_FLOAT32_C(   -11.54), SIMDE_FLOAT32_C(   562.77) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_permutex2var_ps(a, idx, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 r = simde_mm_permutex2var_ps(a, idx, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float32 a[8];
    const simde__mmask8 k;
    const int32_t idx[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   779.66), SIMDE_FLOAT32_C(   978.72), SIMDE_FLOAT32_C(   176.87), SIMDE_FLOAT32_C(  -448.47) },
      UINT8_C( 18),
      { -INT32_C(  1588445151), -INT32_C(  1883472164), -INT32_C(  2066920482),  INT32_C(   464333286) },
      { SIMDE_FLOAT32_C(  -922.94), SIMDE_FLOAT32_C(  -641.88), SIMDE_FLOAT32_C(   269.76), SIMDE_FLOAT32_C(   195.17) },
      { SIMDE_FLOAT32_C(   779.66), SIMDE_FLOAT32_C(  -922.94), SIMDE_FLOAT32_C(   176.87), SIMDE_FLOAT32_C(  -448.47) } },
    { { SIMDE_FLOAT32_C(   494.25), SIMDE_FLOAT32_C(   840.08), SIMDE_FLOAT32_C(  -242.06), SIMDE_FLOAT32_C(  -219.30) },
      UINT8_C(165),
      {  INT32_C(   207412167), -INT32_C(  1238536587),  INT32_C(  1066586049), -INT32_C(   702733685) },
      { SIMDE_FLOAT32_C(   -52.87), SIMDE_FLOAT32_C(  -994.31), SIMDE_FLOAT32_C(   351.07), SIMDE_FLOAT32_C(  -263.12) },
      { SIMDE_FLOAT32_C(  -263.12), SIMDE_FLOAT32_C(   840.08), SIMDE_FLOAT32_C(   840.08), SIMDE_FLOAT32_C(  -219.30) } },
    { { SIMDE_FLOAT32_C(   194.86), SIMDE_FLOAT32_C(  -308.38), SIMDE_FLOAT32_C(  -186.07), SIMDE_FLOAT32_C(   552.98) },
      UINT8_C( 94),
      {  INT32_C(  1940913599),  INT32_C(   725308496),  INT32_C(   530663344),  INT32_C(  1138775924) },
      { SIMDE_FLOAT32_C(  -904.51), SIMDE_FLOAT32_C(  -690.64), SIMDE_FLOAT32_C(  -252.21), SIMDE_FLOAT32_C(   829.92) },
      { SIMDE_FLOAT32_C(   194.86), SIMDE_FLOAT32_C(   194.86), SIMDE_FLOAT32_C(   194.86), SIMDE_FLOAT32_C(  -904.51) } },
    { { SIMDE_FLOAT32_C(   501.97), SIMDE_FLOAT32_C(   290.64), SIMDE_FLOAT32_C(  -222.95), SIMDE_FLOAT32_C(   507.66) },
      UINT8_C( 96),
      { -INT32_C(  1036571116), -INT32_C(   327051793), -INT32_C(  1740835516),  INT32_C(  2001299248) },
      { SIMDE_FLOAT32_C(    19.16), SIMDE_FLOAT32_C(   666.10), SIMDE_FLOAT32_C(    76.00), SIMDE_FLOAT32_C(  -406.79) },
      { SIMDE_FLOAT32_C(   501.97), SIMDE_FLOAT32_C(   290.64), SIMDE_FLOAT32_C(  -222.95), SIMDE_FLOAT32_C(   507.66) } },
    { { SIMDE_FLOAT32_C(   491.62), SIMDE_FLOAT32_C(   408.83), SIMDE_FLOAT32_C(  -311.30), SIMDE_FLOAT32_C(   800.98) },
      UINT8_C(253),
      {  INT32_C(  1336058708), -INT32_C(  1335688574), -INT32_C(   811653830), -INT32_C(  1676375129) },
      { SIMDE_FLOAT32_C(  -797.91), SIMDE_FLOAT32_C(   818.85), SIMDE_FLOAT32_C(   547.59), SIMDE_FLOAT32_C(   721.06) },
      { SIMDE_FLOAT32_C(  -797.91), SIMDE_FLOAT32_C(   408.83), SIMDE_FLOAT32_C(  -311.30), SIMDE_FLOAT32_C(   721.06) } },
    { { SIMDE_FLOAT32_C(   820.82), SIMDE_FLOAT32_C(  -343.01), SIMDE_FLOAT32_C(  -259.78), SIMDE_FLOAT32_C(   486.92) },
      UINT8_C( 46),
      { -INT32_C(   547510890), -INT32_C(  1338746100), -INT32_C(    13466627),  INT32_C(   205120231) },
      { SIMDE_FLOAT32_C(  -825.08), SIMDE_FLOAT32_C(   -26.06), SIMDE_FLOAT32_C(   257.90), SIMDE_FLOAT32_C(   246.32) },
      { SIMDE_FLOAT32_C(   820.82), SIMDE_FLOAT32_C(  -825.08), SIMDE_FLOAT32_C(   -26.06), SIMDE_FLOAT32_C(   246.32) } },
    { { SIMDE_FLOAT32_C(  -212.89), SIMDE_FLOAT32_C(   836.31), SIMDE_FLOAT32_C(   448.41), SIMDE_FLOAT32_C(  -394.05) },
      UINT8_C( 27),
      {  INT32_C(   945733377), -INT32_C(  1026585316),  INT32_C(  1171173098),  INT32_C(  1715633890) },
      { SIMDE_FLOAT32_C(  -352.66), SIMDE_FLOAT32_C(   794.50), SIMDE_FLOAT32_C(  -711.52), SIMDE_FLOAT32_C(    53.59) },
      { SIMDE_FLOAT32_C(   836.31), SIMDE_FLOAT32_C(  -352.66), SIMDE_FLOAT32_C(   448.41), SIMDE_FLOAT32_C(   448.41) } },
    { { SIMDE_FLOAT32_C(  -948.56), SIMDE_FLOAT32_C(  -928.04), SIMDE_FLOAT32_C(   228.50), SIMDE_FLOAT32_C(    25.38) },
      UINT8_C( 13),
      { -INT32_C(   228810465),  INT32_C(   720664683),  INT32_C(  1665543382), -INT32_C(  1437726469) },
      { SIMDE_FLOAT32_C(   322.90), SIMDE_FLOAT32_C(   494.70), SIMDE_FLOAT32_C(   316.80), SIMDE_FLOAT32_C(    77.13) },
      { SIMDE_FLOAT32_C(    77.13), SIMDE_FLOAT32_C(  -928.04), SIMDE_FLOAT32_C(   316.80), SIMDE_FLOAT32_C(    25.38) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_permutex2var_ps(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 r = simde_mm_mask_permutex2var_ps(a, k, idx, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask2_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float32 a[8];
    const int32_t idx[8];
    const simde__mmask8 k;
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -545.46), SIMDE_FLOAT32_C(   -40.75), SIMDE_FLOAT32_C(   724.47), SIMDE_FLOAT32_C(  -750.96) },
      {  INT32_C(  1131919442), -INT32_C(  1017253724), -INT32_C(  1003560632),  INT32_C(  1134549074) },
      UINT8_C(172),
      { SIMDE_FLOAT32_C(   325.85), SIMDE_FLOAT32_C(  -350.45), SIMDE_FLOAT32_C(  -518.61), SIMDE_FLOAT32_C(   138.34) },
      { SIMDE_FLOAT32_C(   247.72), SIMDE_FLOAT32_C(  -221.94), SIMDE_FLOAT32_C(  -545.46), SIMDE_FLOAT32_C(   724.47) } },
    { { SIMDE_FLOAT32_C(   815.72), SIMDE_FLOAT32_C(  -595.37), SIMDE_FLOAT32_C(   556.77), SIMDE_FLOAT32_C(  -634.22) },
      {  INT32_C(  1140370309), -INT32_C(  1005223772), -INT32_C(  1037235651), -INT32_C(  1007017984) },
      UINT8_C(149),
      { SIMDE_FLOAT32_C(   321.58), SIMDE_FLOAT32_C(  -254.72), SIMDE_FLOAT32_C(  -187.96), SIMDE_FLOAT32_C(  -397.87) },
      { SIMDE_FLOAT32_C(  -254.72), SIMDE_FLOAT32_C(  -598.01), SIMDE_FLOAT32_C(  -254.72), SIMDE_FLOAT32_C(  -500.25) } },
    { { SIMDE_FLOAT32_C(  -743.94), SIMDE_FLOAT32_C(  -865.07), SIMDE_FLOAT32_C(  -903.17), SIMDE_FLOAT32_C(   572.86) },
      {  INT32_C(  1129582428), -INT32_C(  1008709796), -INT32_C(  1008078356), -INT32_C(  1031937720) },
      UINT8_C(132),
      { SIMDE_FLOAT32_C(   779.83), SIMDE_FLOAT32_C(   714.59), SIMDE_FLOAT32_C(   100.89), SIMDE_FLOAT32_C(    99.52) },
      { SIMDE_FLOAT32_C(   212.06), SIMDE_FLOAT32_C(  -448.62), SIMDE_FLOAT32_C(   779.83), SIMDE_FLOAT32_C(   -63.47) } },
    { { SIMDE_FLOAT32_C(   721.15), SIMDE_FLOAT32_C(  -573.25), SIMDE_FLOAT32_C(   749.07), SIMDE_FLOAT32_C(  -797.46) },
      {  INT32_C(  1141720351),  INT32_C(  1141715599), -INT32_C(  1010537595),  INT32_C(  1123268690) },
      UINT8_C(254),
      { SIMDE_FLOAT32_C(  -895.49), SIMDE_FLOAT32_C(   523.85), SIMDE_FLOAT32_C(  -112.69), SIMDE_FLOAT32_C(  -395.75) },
      { SIMDE_FLOAT32_C(   565.08), SIMDE_FLOAT32_C(  -395.75), SIMDE_FLOAT32_C(   523.85), SIMDE_FLOAT32_C(   749.07) } },
    { { SIMDE_FLOAT32_C(  -315.26), SIMDE_FLOAT32_C(  -791.11), SIMDE_FLOAT32_C(   349.53), SIMDE_FLOAT32_C(   496.78) },
      { -INT32_C(  1019414446),  INT32_C(  1142384067),  INT32_C(  1142812180), -INT32_C(  1028110418) },
      UINT8_C(157),
      { SIMDE_FLOAT32_C(  -156.22), SIMDE_FLOAT32_C(   459.24), SIMDE_FLOAT32_C(   710.56), SIMDE_FLOAT32_C(   780.31) },
      { SIMDE_FLOAT32_C(   349.53), SIMDE_FLOAT32_C(   605.59), SIMDE_FLOAT32_C(  -156.22), SIMDE_FLOAT32_C(   710.56) } },
    { { SIMDE_FLOAT32_C(  -740.35), SIMDE_FLOAT32_C(   490.39), SIMDE_FLOAT32_C(   494.90), SIMDE_FLOAT32_C(   360.54) },
      { -INT32_C(  1009972347),  INT32_C(  1129843917),  INT32_C(  1145361039), -INT32_C(  1004191416) },
      UINT8_C(250),
      { SIMDE_FLOAT32_C(   352.37), SIMDE_FLOAT32_C(   903.77), SIMDE_FLOAT32_C(  -974.25), SIMDE_FLOAT32_C(  -525.77) },
      { SIMDE_FLOAT32_C(  -410.09), SIMDE_FLOAT32_C(   903.77), SIMDE_FLOAT32_C(   787.29), SIMDE_FLOAT32_C(  -740.35) } },
    { { SIMDE_FLOAT32_C(   834.34), SIMDE_FLOAT32_C(  -869.75), SIMDE_FLOAT32_C(   998.08), SIMDE_FLOAT32_C(  -278.35) },
      { -INT32_C(  1014710600), -INT32_C(  1013016822), -INT32_C(  1031083131), -INT32_C(  1000014479) },
      UINT8_C(165),
      { SIMDE_FLOAT32_C(   741.57), SIMDE_FLOAT32_C(   689.62), SIMDE_FLOAT32_C(   811.33), SIMDE_FLOAT32_C(  -350.56) },
      { SIMDE_FLOAT32_C(   834.34), SIMDE_FLOAT32_C(  -317.18), SIMDE_FLOAT32_C(   689.62), SIMDE_FLOAT32_C(  -915.96) } },
    { { SIMDE_FLOAT32_C(  -131.93), SIMDE_FLOAT32_C(  -344.89), SIMDE_FLOAT32_C(  -891.33), SIMDE_FLOAT32_C(  -421.37) },
      { -INT32_C(  1005771489), -INT32_C(  1004672287), -INT32_C(   999768392),  INT32_C(  1147704443) },
      UINT8_C(241),
      { SIMDE_FLOAT32_C(  -341.07), SIMDE_FLOAT32_C(   146.37), SIMDE_FLOAT32_C(   516.16), SIMDE_FLOAT32_C(    -2.09) },
      { SIMDE_FLOAT32_C(    -2.09), SIMDE_FLOAT32_C(  -631.67), SIMDE_FLOAT32_C(  -930.98), SIMDE_FLOAT32_C(   930.32) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask2_permutex2var_ps(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i idx = simde_mm_castps_si128(simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 r = simde_mm_mask2_permutex2var_ps(a, idx, k, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const int32_t idx[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C( 44),
      { SIMDE_FLOAT32_C(  -131.47), SIMDE_FLOAT32_C(   -98.32), SIMDE_FLOAT32_C(  -409.30), SIMDE_FLOAT32_C(   342.76) },
      {  INT32_C(  1601285198), -INT32_C(   512390974), -INT32_C(   695365330),  INT32_C(   172807497) },
      { SIMDE_FLOAT32_C(  -324.18), SIMDE_FLOAT32_C(   105.12), SIMDE_FLOAT32_C(   256.22), SIMDE_FLOAT32_C(  -255.16) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   256.22), SIMDE_FLOAT32_C(   -98.32) } },
    { UINT8_C(118),
      { SIMDE_FLOAT32_C(   -14.91), SIMDE_FLOAT32_C(   403.77), SIMDE_FLOAT32_C(  -818.19), SIMDE_FLOAT32_C(  -498.75) },
      {  INT32_C(  1720767706),  INT32_C(  1152703384), -INT32_C(   720956339),  INT32_C(   436463753) },
      { SIMDE_FLOAT32_C(  -717.52), SIMDE_FLOAT32_C(  -705.08), SIMDE_FLOAT32_C(  -205.73), SIMDE_FLOAT32_C(  -620.33) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -14.91), SIMDE_FLOAT32_C(  -705.08), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 38),
      { SIMDE_FLOAT32_C(   682.17), SIMDE_FLOAT32_C(    55.49), SIMDE_FLOAT32_C(  -930.26), SIMDE_FLOAT32_C(   -61.61) },
      { -INT32_C(  1542456430),  INT32_C(  2021531299), -INT32_C(  1995381330), -INT32_C(  1378462311) },
      { SIMDE_FLOAT32_C(   -56.50), SIMDE_FLOAT32_C(  -362.49), SIMDE_FLOAT32_C(  -669.14), SIMDE_FLOAT32_C(   996.86) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -61.61), SIMDE_FLOAT32_C(  -669.14), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(175),
      { SIMDE_FLOAT32_C(  -654.09), SIMDE_FLOAT32_C(  -720.66), SIMDE_FLOAT32_C(   212.74), SIMDE_FLOAT32_C(   140.18) },
      {  INT32_C(   237154053),  INT32_C(   799074356),  INT32_C(   366101751), -INT32_C(  1480373566) },
      { SIMDE_FLOAT32_C(  -955.72), SIMDE_FLOAT32_C(  -589.43), SIMDE_FLOAT32_C(  -817.55), SIMDE_FLOAT32_C(   473.91) },
      { SIMDE_FLOAT32_C(  -589.43), SIMDE_FLOAT32_C(  -955.72), SIMDE_FLOAT32_C(   473.91), SIMDE_FLOAT32_C(   212.74) } },
    { UINT8_C( 35),
      { SIMDE_FLOAT32_C(  -371.95), SIMDE_FLOAT32_C(  -582.60), SIMDE_FLOAT32_C(   608.54), SIMDE_FLOAT32_C(   -41.09) },
      {  INT32_C(   175472464), -INT32_C(  1206966008),  INT32_C(   871112011),  INT32_C(    19602365) },
      { SIMDE_FLOAT32_C(  -844.84), SIMDE_FLOAT32_C(  -178.68), SIMDE_FLOAT32_C(   625.63), SIMDE_FLOAT32_C(  -171.78) },
      { SIMDE_FLOAT32_C(  -371.95), SIMDE_FLOAT32_C(  -371.95), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  4),
      { SIMDE_FLOAT32_C(  -140.46), SIMDE_FLOAT32_C(  -127.51), SIMDE_FLOAT32_C(   135.39), SIMDE_FLOAT32_C(    41.99) },
      {  INT32_C(  1335587907), -INT32_C(  1012940732),  INT32_C(  1607182901), -INT32_C(   676691015) },
      { SIMDE_FLOAT32_C(  -939.53), SIMDE_FLOAT32_C(  -325.78), SIMDE_FLOAT32_C(  -126.70), SIMDE_FLOAT32_C(   576.34) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -325.78), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  9),
      { SIMDE_FLOAT32_C(  -825.82), SIMDE_FLOAT32_C(   731.50), SIMDE_FLOAT32_C(  -792.13), SIMDE_FLOAT32_C(   799.81) },
      {  INT32_C(  1137003952),  INT32_C(   327578270), -INT32_C(   849881843),  INT32_C(   503454324) },
      { SIMDE_FLOAT32_C(  -888.78), SIMDE_FLOAT32_C(  -687.15), SIMDE_FLOAT32_C(  -183.62), SIMDE_FLOAT32_C(  -991.89) },
      { SIMDE_FLOAT32_C(  -825.82), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -888.78) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(   107.74), SIMDE_FLOAT32_C(  -931.41), SIMDE_FLOAT32_C(  -366.82), SIMDE_FLOAT32_C(   981.04) },
      { -INT32_C(   606473373), -INT32_C(  1970588868),  INT32_C(  1797836537),  INT32_C(   695745364) },
      { SIMDE_FLOAT32_C(   292.34), SIMDE_FLOAT32_C(   687.44), SIMDE_FLOAT32_C(   409.85), SIMDE_FLOAT32_C(   423.13) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -931.41), SIMDE_FLOAT32_C(   292.34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i idx = simde_mm_loadu_epi32(test_vec[i].idx);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_maskz_permutex2var_ps(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i idx = simde_test_x86_random_i32x4();
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 r = simde_mm_maskz_permutex2var_ps(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t idx[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 32651), -INT16_C(  5922), -INT16_C( 29589),  INT16_C( 29469),  INT16_C( 29393),  INT16_C( 32711),  INT16_C(  5048), -INT16_C( 29164),
         INT16_C( 14884), -INT16_C( 14540),  INT16_C( 19202), -INT16_C( 31858),  INT16_C( 30405), -INT16_C(   327), -INT16_C(  4310), -INT16_C( 24631) },
      { -INT16_C( 22672), -INT16_C(  9337), -INT16_C( 23245),  INT16_C(  1102),  INT16_C(  5399), -INT16_C( 12413), -INT16_C( 26584),  INT16_C( 19549),
        -INT16_C( 28206), -INT16_C( 10988), -INT16_C( 23844), -INT16_C( 24232),  INT16_C(  4376),  INT16_C( 17055),  INT16_C( 26625),  INT16_C( 29154) },
      {  INT16_C( 26895),  INT16_C( 16972), -INT16_C( 26098),  INT16_C(  9542), -INT16_C( 13648), -INT16_C(  9995),  INT16_C( 21090),  INT16_C( 13349),
         INT16_C( 14820), -INT16_C( 16375),  INT16_C( 25307), -INT16_C(  3230),  INT16_C(   371),  INT16_C( 29749),  INT16_C(  5994),  INT16_C( 31205) },
      {  INT16_C( 26895), -INT16_C( 29164),  INT16_C(  9542), -INT16_C(  4310),  INT16_C( 13349),  INT16_C( 29469),  INT16_C( 14884),  INT16_C( 29749),
        -INT16_C( 26098), -INT16_C( 13648),  INT16_C(   371),  INT16_C( 14820),  INT16_C( 14820),  INT16_C( 31205), -INT16_C(  5922), -INT16_C( 29589) } },
    { {  INT16_C( 12673), -INT16_C( 28740),  INT16_C(   716),  INT16_C( 31925), -INT16_C( 21812),  INT16_C( 11860),  INT16_C( 31228), -INT16_C(  8093),
         INT16_C( 27826), -INT16_C( 29279),  INT16_C(   974),  INT16_C( 17024), -INT16_C( 18940),  INT16_C( 28342), -INT16_C( 25395),  INT16_C( 20200) },
      { -INT16_C( 23347), -INT16_C( 26146), -INT16_C( 27738),  INT16_C( 29461),  INT16_C( 27197),  INT16_C( 14753),  INT16_C(  1251), -INT16_C( 27110),
        -INT16_C( 17551),  INT16_C( 16163), -INT16_C( 23362), -INT16_C( 15743),  INT16_C( 14426),  INT16_C( 10033),  INT16_C(  6612), -INT16_C( 24202) },
      {  INT16_C( 21693),  INT16_C( 25403),  INT16_C( 20711),  INT16_C(  9430),  INT16_C( 30906), -INT16_C( 24995),  INT16_C( 30588), -INT16_C(  4812),
         INT16_C( 22322), -INT16_C(  4051), -INT16_C( 20741),  INT16_C( 21939), -INT16_C(  6938), -INT16_C( 17795), -INT16_C(  3075), -INT16_C( 17828) },
      {  INT16_C( 28342), -INT16_C(  3075),  INT16_C( 31228), -INT16_C( 24995), -INT16_C( 17795), -INT16_C( 28740),  INT16_C( 31925), -INT16_C( 20741),
         INT16_C( 25403),  INT16_C( 31925), -INT16_C(  3075), -INT16_C( 28740), -INT16_C( 20741),  INT16_C( 25403),  INT16_C( 30906),  INT16_C( 30588) } },
    { { -INT16_C( 26809),  INT16_C( 11805), -INT16_C(  2841), -INT16_C( 23982), -INT16_C( 20628), -INT16_C(  6080),  INT16_C( 29735),  INT16_C( 22998),
         INT16_C(   971), -INT16_C( 14518), -INT16_C(   591), -INT16_C( 26596), -INT16_C( 26143), -INT16_C(  8622), -INT16_C( 20852), -INT16_C( 11368) },
      { -INT16_C( 19131),  INT16_C( 11521),  INT16_C( 21417),  INT16_C(  5583),  INT16_C(  3843),  INT16_C( 11006), -INT16_C( 11133),  INT16_C( 20099),
        -INT16_C( 12841), -INT16_C( 30699),  INT16_C( 13002), -INT16_C( 21728),  INT16_C( 29643),  INT16_C( 22665),  INT16_C(  8481),  INT16_C( 26411) },
      {  INT16_C( 11735), -INT16_C( 32620),  INT16_C( 25472), -INT16_C( 31850), -INT16_C( 27534), -INT16_C(  2643),  INT16_C( 12648),  INT16_C( 16195),
         INT16_C( 23038), -INT16_C( 13881), -INT16_C(  6005),  INT16_C( 22132), -INT16_C(   421),  INT16_C( 31918), -INT16_C(  9697), -INT16_C(  2333) },
      { -INT16_C(  6080),  INT16_C( 11805), -INT16_C( 14518), -INT16_C( 11368), -INT16_C( 23982), -INT16_C(  9697), -INT16_C( 23982), -INT16_C( 23982),
         INT16_C( 16195), -INT16_C(  2643), -INT16_C(   591), -INT16_C( 26809), -INT16_C( 26596), -INT16_C( 14518),  INT16_C( 11805), -INT16_C( 26596) } },
    { {  INT16_C( 30471), -INT16_C( 30857),  INT16_C(  3546),  INT16_C( 19467), -INT16_C( 18271),  INT16_C(  2369), -INT16_C( 31255), -INT16_C(  6072),
         INT16_C(  4062),  INT16_C( 27057),  INT16_C(  9719),  INT16_C( 21183),  INT16_C( 28195),  INT16_C( 17359), -INT16_C( 19896),  INT16_C( 20281) },
      { -INT16_C( 20438),  INT16_C(  1238), -INT16_C(  7747),  INT16_C( 24145), -INT16_C( 28006), -INT16_C( 31897), -INT16_C( 20713), -INT16_C(  2709),
         INT16_C(  7359), -INT16_C( 18850),  INT16_C(  7746),  INT16_C( 25865), -INT16_C( 10100), -INT16_C( 11096), -INT16_C(  7542), -INT16_C( 19421) },
      { -INT16_C(  1646),  INT16_C( 20665),  INT16_C(  2779),  INT16_C( 30126),  INT16_C(  5788), -INT16_C( 19208),  INT16_C( 25797), -INT16_C( 31575),
         INT16_C(  2176), -INT16_C( 15813),  INT16_C( 17446), -INT16_C( 19928), -INT16_C( 12260), -INT16_C( 22906), -INT16_C( 22094),  INT16_C( 17755) },
      {  INT16_C(  9719),  INT16_C( 25797), -INT16_C( 22906),  INT16_C( 20665),  INT16_C( 17446), -INT16_C(  6072), -INT16_C( 31575),  INT16_C( 21183),
         INT16_C( 17755), -INT16_C( 22094),  INT16_C(  3546),  INT16_C( 27057),  INT16_C( 28195),  INT16_C(  4062),  INT16_C(  9719),  INT16_C( 19467) } },
    { {  INT16_C(  5282),  INT16_C( 32149),  INT16_C( 17182), -INT16_C( 17678), -INT16_C(  5287),  INT16_C(  8046),  INT16_C(  6223), -INT16_C( 12381),
        -INT16_C(  8672),  INT16_C( 18066), -INT16_C( 17886),  INT16_C( 16120),  INT16_C( 32394),  INT16_C( 15845),  INT16_C( 16423), -INT16_C( 13950) },
      {  INT16_C(  5972),  INT16_C( 29255),  INT16_C( 14682), -INT16_C( 19412), -INT16_C( 25820),  INT16_C( 29651),  INT16_C( 30387), -INT16_C( 11453),
        -INT16_C( 10923),  INT16_C( 30489),  INT16_C(  4495),  INT16_C(  6582), -INT16_C( 25713), -INT16_C( 18858), -INT16_C( 10021),  INT16_C( 12159) },
      { -INT16_C( 14609),  INT16_C( 19105), -INT16_C( 13056),  INT16_C(  9470), -INT16_C( 11928),  INT16_C(  7064), -INT16_C(  9401), -INT16_C( 25362),
         INT16_C(  1968),  INT16_C( 16148), -INT16_C( 13800), -INT16_C( 22696), -INT16_C( 20635),  INT16_C( 16477), -INT16_C(  8825),  INT16_C( 30575) },
      { -INT16_C( 11928), -INT16_C( 12381), -INT16_C( 13800),  INT16_C( 32394), -INT16_C(  5287),  INT16_C(  9470),  INT16_C(  9470), -INT16_C( 17678),
         INT16_C(  7064),  INT16_C( 16148), -INT16_C( 13950), -INT16_C(  9401), -INT16_C( 13950), -INT16_C(  9401), -INT16_C( 22696),  INT16_C( 30575) } },
    { {  INT16_C(  4259), -INT16_C( 23615), -INT16_C( 16419),  INT16_C( 18120),  INT16_C( 24720), -INT16_C( 10399),  INT16_C( 20539), -INT16_C(  5260),
        -INT16_C( 30633),  INT16_C( 28714), -INT16_C( 32174), -INT16_C( 18665),  INT16_C( 30001), -INT16_C( 17929),  INT16_C( 26194), -INT16_C(  2768) },
      { -INT16_C(  3722),  INT16_C( 21401),  INT16_C( 25008),  INT16_C( 16537), -INT16_C(  1087), -INT16_C(  1001), -INT16_C( 29877), -INT16_C( 23833),
         INT16_C(  4371),  INT16_C( 25874),  INT16_C( 10899), -INT16_C( 15076),  INT16_C(  5023), -INT16_C(  3714), -INT16_C( 20871), -INT16_C(  4122) },
      {  INT16_C( 32671),  INT16_C( 20291), -INT16_C(  8992), -INT16_C( 24177), -INT16_C( 22825),  INT16_C(  8861), -INT16_C( 31694),  INT16_C( 17861),
        -INT16_C( 10347),  INT16_C( 10667), -INT16_C( 14591), -INT16_C( 24338),  INT16_C( 27867),  INT16_C( 21649),  INT16_C( 30746), -INT16_C( 18108) },
      { -INT16_C( 31694),  INT16_C( 10667),  INT16_C( 32671),  INT16_C( 10667), -INT16_C( 23615),  INT16_C( 17861), -INT16_C( 18665), -INT16_C(  5260),
        -INT16_C( 24177), -INT16_C(  8992), -INT16_C( 24177),  INT16_C( 27867), -INT16_C( 18108),  INT16_C( 30746),  INT16_C( 10667),  INT16_C( 20539) } },
    { { -INT16_C( 30729), -INT16_C( 10232), -INT16_C( 26781),  INT16_C( 15225),  INT16_C(  5949),  INT16_C( 28509),  INT16_C(  8859),  INT16_C( 12725),
         INT16_C( 24826), -INT16_C(  1190),  INT16_C( 18471),  INT16_C(   668),  INT16_C( 11700), -INT16_C( 12713), -INT16_C( 25691), -INT16_C( 25209) },
      { -INT16_C( 28894), -INT16_C( 31371), -INT16_C(  4570),  INT16_C( 25536),  INT16_C(  7685), -INT16_C( 24109), -INT16_C( 30656),  INT16_C( 15058),
         INT16_C( 11496),  INT16_C(  3894), -INT16_C( 11660),  INT16_C( 10258),  INT16_C( 27135), -INT16_C( 23050),  INT16_C( 32004),  INT16_C(  9794) },
      { -INT16_C( 18676),  INT16_C( 12971),  INT16_C( 27813), -INT16_C( 21611),  INT16_C( 26762), -INT16_C( 13748),  INT16_C(  7920), -INT16_C( 10235),
         INT16_C( 15178), -INT16_C( 16664), -INT16_C(  1523),  INT16_C(  3302), -INT16_C(  9117),  INT16_C( 26545), -INT16_C(  3239),  INT16_C( 25997) },
      { -INT16_C( 26781), -INT16_C( 13748),  INT16_C(  8859), -INT16_C( 30729),  INT16_C( 28509), -INT16_C( 21611), -INT16_C( 30729),  INT16_C( 27813),
         INT16_C( 24826),  INT16_C(  7920),  INT16_C( 26762),  INT16_C( 27813),  INT16_C( 25997),  INT16_C(  7920),  INT16_C(  5949), -INT16_C( 26781) } },
    { {  INT16_C( 14506),  INT16_C( 20631),  INT16_C( 11428),  INT16_C( 12027),  INT16_C( 18325), -INT16_C( 31239), -INT16_C(   411), -INT16_C( 20642),
         INT16_C( 17977),  INT16_C( 18029),  INT16_C( 21312), -INT16_C( 23726),  INT16_C(  1071), -INT16_C( 30710), -INT16_C( 26633), -INT16_C( 23827) },
      { -INT16_C( 31537),  INT16_C( 29938), -INT16_C(  4688),  INT16_C( 17826), -INT16_C( 25804), -INT16_C( 26165),  INT16_C( 10649), -INT16_C( 11704),
        -INT16_C( 19089), -INT16_C( 20712),  INT16_C( 27400),  INT16_C( 14162),  INT16_C( 23663),  INT16_C( 26303), -INT16_C( 21261), -INT16_C( 15864) },
      { -INT16_C(  1488), -INT16_C(  8138), -INT16_C(  9753),  INT16_C(  6950), -INT16_C(  3724),  INT16_C(  3764), -INT16_C(   998), -INT16_C( 30240),
        -INT16_C(  1615), -INT16_C( 18120), -INT16_C( 30108), -INT16_C( 11280), -INT16_C( 20506), -INT16_C(  9927),  INT16_C( 16987), -INT16_C( 29797) },
      { -INT16_C( 23827), -INT16_C(  9753), -INT16_C(  1488),  INT16_C( 11428), -INT16_C(  3724), -INT16_C( 23726), -INT16_C( 18120),  INT16_C( 17977),
        -INT16_C( 23827), -INT16_C(  1615),  INT16_C( 17977), -INT16_C(  9753), -INT16_C( 23827), -INT16_C( 29797),  INT16_C(  6950),  INT16_C( 17977) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_permutex2var_epi16(a, idx, b);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_permutex2var_epi16(a, idx, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const simde__mmask16 k;
    const int16_t idx[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 11716),  INT16_C(  9324), -INT16_C( 27989),  INT16_C(  7999), -INT16_C(  2941), -INT16_C( 25299),  INT16_C(  3824), -INT16_C( 24026),
         INT16_C( 24071),  INT16_C( 27483),  INT16_C( 19688), -INT16_C( 12738),  INT16_C( 30715),  INT16_C( 22439),  INT16_C( 17081), -INT16_C(  2334) },
      UINT16_C(19988),
      { -INT16_C( 16614),  INT16_C( 23008),  INT16_C( 25567),  INT16_C(  3149),  INT16_C( 15872),  INT16_C(  9754),  INT16_C(  8672),  INT16_C( 15236),
         INT16_C( 27788), -INT16_C( 13689), -INT16_C( 31942), -INT16_C(  7870), -INT16_C(  1062), -INT16_C( 17372),  INT16_C( 14577),  INT16_C(  2827) },
      { -INT16_C(  5128), -INT16_C( 10395), -INT16_C( 19889),  INT16_C( 20451), -INT16_C(   272), -INT16_C( 12170), -INT16_C(  1505), -INT16_C( 21492),
        -INT16_C( 27801), -INT16_C( 24202), -INT16_C( 18410), -INT16_C(  3965), -INT16_C( 22604), -INT16_C( 23123), -INT16_C( 18209), -INT16_C( 10319) },
      { -INT16_C( 11716),  INT16_C(  9324), -INT16_C( 10319),  INT16_C(  7999), -INT16_C( 11716), -INT16_C( 25299),  INT16_C(  3824), -INT16_C( 24026),
         INT16_C( 24071), -INT16_C( 24026), -INT16_C( 18410), -INT16_C( 27989),  INT16_C( 30715),  INT16_C( 22439), -INT16_C( 10395), -INT16_C(  2334) } },
    { {  INT16_C(  5795), -INT16_C(  3410), -INT16_C( 27960), -INT16_C( 18110), -INT16_C( 18288), -INT16_C( 20599), -INT16_C( 27214),  INT16_C(  6491),
        -INT16_C( 11735),  INT16_C( 16315),  INT16_C( 16010),  INT16_C( 15920), -INT16_C(  8731), -INT16_C( 15132), -INT16_C( 27243),  INT16_C( 14492) },
      UINT16_C(19115),
      {  INT16_C( 29483),  INT16_C( 28124),  INT16_C( 27692), -INT16_C( 18907), -INT16_C( 10468),  INT16_C( 30539),  INT16_C( 29937), -INT16_C( 21431),
        -INT16_C( 11084), -INT16_C(  6934), -INT16_C( 12526), -INT16_C(  2367),  INT16_C( 22163),  INT16_C( 12171),  INT16_C( 13966), -INT16_C( 18054) },
      {  INT16_C( 22186), -INT16_C( 10714),  INT16_C( 19395), -INT16_C(  8308), -INT16_C( 10205),  INT16_C(  5206), -INT16_C( 24500),  INT16_C(   192),
        -INT16_C( 21900), -INT16_C( 31004), -INT16_C( 23175),  INT16_C(  3197),  INT16_C(  2299), -INT16_C( 30148), -INT16_C( 18881), -INT16_C(  5821) },
      {  INT16_C( 15920),  INT16_C(  2299), -INT16_C( 27960), -INT16_C( 20599), -INT16_C( 18288),  INT16_C( 15920), -INT16_C( 27214),  INT16_C( 16315),
        -INT16_C( 11735),  INT16_C( 16010),  INT16_C( 16010), -INT16_C(  3410), -INT16_C(  8731), -INT16_C( 15132), -INT16_C( 27243),  INT16_C( 14492) } },
    { {  INT16_C( 27148), -INT16_C( 12353),  INT16_C( 19637), -INT16_C( 10066),  INT16_C(  1316),  INT16_C( 28908), -INT16_C( 21339),  INT16_C(  6513),
         INT16_C( 21846), -INT16_C( 12385),  INT16_C(  7419), -INT16_C(  2340),  INT16_C(  6181),  INT16_C( 25728), -INT16_C( 15154), -INT16_C(  9651) },
      UINT16_C( 3118),
      { -INT16_C(  7254),  INT16_C( 22616),  INT16_C( 31932), -INT16_C( 22435),  INT16_C(   749),  INT16_C( 24149), -INT16_C( 21733), -INT16_C( 17485),
        -INT16_C( 20869),  INT16_C( 22487), -INT16_C(   859),  INT16_C(  9583),  INT16_C( 15712), -INT16_C( 21015),  INT16_C(  5911), -INT16_C( 15942) },
      {  INT16_C(  4859), -INT16_C( 18662),  INT16_C( 30607),  INT16_C( 31839), -INT16_C( 19334), -INT16_C( 27174), -INT16_C( 29344), -INT16_C(  9392),
         INT16_C( 10300), -INT16_C(  7886), -INT16_C( 24284), -INT16_C( 31482), -INT16_C(  3874), -INT16_C(  2766), -INT16_C(  5113),  INT16_C(   695) },
      {  INT16_C( 27148),  INT16_C( 10300), -INT16_C(  3874), -INT16_C(  2766),  INT16_C(  1316), -INT16_C( 27174), -INT16_C( 21339),  INT16_C(  6513),
         INT16_C( 21846), -INT16_C( 12385),  INT16_C( 28908), -INT16_C(  9651),  INT16_C(  6181),  INT16_C( 25728), -INT16_C( 15154), -INT16_C(  9651) } },
    { { -INT16_C( 11777), -INT16_C( 28999),  INT16_C(  6472), -INT16_C( 15862), -INT16_C(  6963),  INT16_C( 11608), -INT16_C( 22415), -INT16_C( 21240),
         INT16_C( 15056), -INT16_C(  2674), -INT16_C( 27173), -INT16_C( 18054), -INT16_C( 21371), -INT16_C( 29521),  INT16_C( 26265), -INT16_C( 26481) },
      UINT16_C(18487),
      {  INT16_C( 32550),  INT16_C( 12385),  INT16_C( 12098), -INT16_C( 26092), -INT16_C( 31396),  INT16_C( 25922),  INT16_C(  4915), -INT16_C( 15969),
         INT16_C( 31496), -INT16_C( 32170), -INT16_C(  9420), -INT16_C(  7378), -INT16_C( 14488), -INT16_C(  2231), -INT16_C( 32673), -INT16_C( 31425) },
      { -INT16_C( 24320),  INT16_C( 17077), -INT16_C( 13872),  INT16_C( 11484),  INT16_C(  7759), -INT16_C( 32111),  INT16_C( 12593),  INT16_C( 14659),
        -INT16_C( 25940), -INT16_C(  8005), -INT16_C(  5515), -INT16_C(  8764),  INT16_C(  3505),  INT16_C(  4564),  INT16_C(  5262), -INT16_C( 29034) },
      { -INT16_C( 22415), -INT16_C( 28999),  INT16_C(  6472), -INT16_C( 15862),  INT16_C(  3505),  INT16_C(  6472), -INT16_C( 22415), -INT16_C( 21240),
         INT16_C( 15056), -INT16_C(  2674), -INT16_C( 27173),  INT16_C( 26265), -INT16_C( 21371), -INT16_C( 29521), -INT16_C( 29034), -INT16_C( 26481) } },
    { {  INT16_C( 19637), -INT16_C( 31280), -INT16_C( 21483),  INT16_C( 25777),  INT16_C( 17354), -INT16_C(   794),  INT16_C( 10868),  INT16_C(  8245),
        -INT16_C(  3644),  INT16_C( 14592), -INT16_C( 15141), -INT16_C( 29673), -INT16_C(  5166),  INT16_C( 24733),  INT16_C( 13567), -INT16_C( 19218) },
      UINT16_C(48768),
      { -INT16_C( 27335), -INT16_C(  5270),  INT16_C( 13562), -INT16_C(  8146), -INT16_C( 24016),  INT16_C( 26122), -INT16_C( 12606), -INT16_C( 15785),
         INT16_C( 12808),  INT16_C(  8071),  INT16_C( 22974),  INT16_C( 23562),  INT16_C(  2745), -INT16_C( 22640),  INT16_C(  4286), -INT16_C(  1947) },
      { -INT16_C( 12379), -INT16_C( 24605),  INT16_C(  4355),  INT16_C( 13440), -INT16_C( 30029),  INT16_C( 30106), -INT16_C(  3751),  INT16_C( 24887),
        -INT16_C( 16861), -INT16_C(  7808), -INT16_C( 30185), -INT16_C( 12227), -INT16_C( 12908),  INT16_C( 21367), -INT16_C(  8995), -INT16_C( 31925) },
      {  INT16_C( 19637), -INT16_C( 31280), -INT16_C( 21483),  INT16_C( 25777),  INT16_C( 17354), -INT16_C(   794),  INT16_C( 10868),  INT16_C( 24887),
        -INT16_C(  3644),  INT16_C(  8245), -INT16_C(  8995), -INT16_C( 15141), -INT16_C(  7808), -INT16_C( 12379),  INT16_C( 13567), -INT16_C(   794) } },
    { {  INT16_C( 11947), -INT16_C( 20702), -INT16_C( 24001), -INT16_C(  3357),  INT16_C( 32045), -INT16_C( 31129), -INT16_C( 24978), -INT16_C( 28185),
         INT16_C( 26461),  INT16_C( 29810), -INT16_C( 20239), -INT16_C( 31163), -INT16_C( 17283),  INT16_C( 23513),  INT16_C(  9369),  INT16_C( 17630) },
      UINT16_C(   82),
      { -INT16_C( 28173), -INT16_C( 10589), -INT16_C( 12157), -INT16_C(  5549), -INT16_C( 16042),  INT16_C( 15752), -INT16_C(  6830), -INT16_C( 14940),
        -INT16_C( 27302), -INT16_C( 24715), -INT16_C(  3557), -INT16_C(  2981), -INT16_C(  2995),  INT16_C( 11032),  INT16_C( 27193),  INT16_C( 11308) },
      { -INT16_C( 12293),  INT16_C( 32259),  INT16_C( 22175), -INT16_C(  2712), -INT16_C(  3816),  INT16_C( 27186), -INT16_C( 10538),  INT16_C( 12335),
        -INT16_C( 23445), -INT16_C( 30769),  INT16_C( 11159), -INT16_C(  7045), -INT16_C( 27617),  INT16_C( 22544),  INT16_C( 15614), -INT16_C(  1403) },
      {  INT16_C( 11947), -INT16_C(  3357), -INT16_C( 24001), -INT16_C(  3357), -INT16_C( 10538), -INT16_C( 31129),  INT16_C( 22175), -INT16_C( 28185),
         INT16_C( 26461),  INT16_C( 29810), -INT16_C( 20239), -INT16_C( 31163), -INT16_C( 17283),  INT16_C( 23513),  INT16_C(  9369),  INT16_C( 17630) } },
    { { -INT16_C( 30709), -INT16_C( 21896), -INT16_C(  7714), -INT16_C(  2401), -INT16_C( 11822), -INT16_C( 22431), -INT16_C( 28505),  INT16_C(  4825),
        -INT16_C( 22475), -INT16_C( 13159),  INT16_C(  5587), -INT16_C(  3152), -INT16_C( 16215), -INT16_C( 22709), -INT16_C( 12036),  INT16_C(  1953) },
      UINT16_C( 6744),
      {  INT16_C( 14257),  INT16_C( 20731), -INT16_C( 13011), -INT16_C( 29151), -INT16_C( 14219),  INT16_C( 19999),  INT16_C( 21723),  INT16_C( 29943),
        -INT16_C( 13792), -INT16_C( 12151),  INT16_C( 12989),  INT16_C(  2449), -INT16_C( 29222),  INT16_C( 31705),  INT16_C( 12949),  INT16_C( 18069) },
      { -INT16_C( 28567), -INT16_C( 26985), -INT16_C( 18339), -INT16_C( 11483),  INT16_C( 17537),  INT16_C( 23585),  INT16_C(  6296), -INT16_C( 18224),
         INT16_C( 23267), -INT16_C( 24440),  INT16_C(  6540),  INT16_C( 26281), -INT16_C( 31833),  INT16_C( 15586),  INT16_C( 30645),  INT16_C(  7810) },
      { -INT16_C( 30709), -INT16_C( 21896), -INT16_C(  7714), -INT16_C( 21896),  INT16_C( 23585), -INT16_C( 22431),  INT16_C( 26281),  INT16_C(  4825),
        -INT16_C( 22475), -INT16_C( 13159),  INT16_C(  5587), -INT16_C( 26985),  INT16_C(  6540), -INT16_C( 22709), -INT16_C( 12036),  INT16_C(  1953) } },
    { {  INT16_C(  6408),  INT16_C( 26036), -INT16_C(  9774),  INT16_C( 21304),  INT16_C( 23069), -INT16_C( 19025),  INT16_C( 32626),  INT16_C( 21869),
        -INT16_C(  2343),  INT16_C( 26358), -INT16_C( 24817), -INT16_C( 18740), -INT16_C( 20958), -INT16_C( 10254),  INT16_C( 29990),  INT16_C( 12021) },
      UINT16_C(43662),
      {  INT16_C( 24723), -INT16_C( 13181), -INT16_C( 24141),  INT16_C( 25126), -INT16_C( 26538), -INT16_C( 15134), -INT16_C( 17426), -INT16_C(  6982),
        -INT16_C( 14047), -INT16_C(  4477), -INT16_C( 22912),  INT16_C( 29340), -INT16_C( 15747),  INT16_C( 29671),  INT16_C( 30448), -INT16_C( 31715) },
      { -INT16_C( 24362), -INT16_C( 30128),  INT16_C( 30273), -INT16_C( 26388), -INT16_C( 12786), -INT16_C(   932),  INT16_C(  5770), -INT16_C( 21536),
         INT16_C( 25823),  INT16_C( 24473),  INT16_C( 13834), -INT16_C( 30766), -INT16_C( 17928), -INT16_C(  5638),  INT16_C(  5935),  INT16_C(  1645) },
      {  INT16_C(  6408),  INT16_C( 21304), -INT16_C( 26388),  INT16_C( 32626),  INT16_C( 23069), -INT16_C( 19025),  INT16_C( 32626),  INT16_C( 13834),
        -INT16_C(  2343),  INT16_C( 21304), -INT16_C( 24817), -INT16_C( 17928), -INT16_C( 20958),  INT16_C( 21869),  INT16_C( 29990), -INT16_C(  5638) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_permutex2var_epi16(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_permutex2var_epi16(a, k, idx, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask2_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t idx[16];
    const simde__mmask16 k;
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 16968), -INT16_C(  1648),  INT16_C( 31795),  INT16_C( 16785), -INT16_C(  4789), -INT16_C( 10946),  INT16_C(  7683), -INT16_C(  7296),
         INT16_C(  6786), -INT16_C( 29630),  INT16_C(  5200),  INT16_C( 18452),  INT16_C(  3790), -INT16_C(   719), -INT16_C( 25050), -INT16_C(  8701) },
      { -INT16_C( 27813), -INT16_C( 28969),  INT16_C( 26896),  INT16_C( 23504),  INT16_C(  3670),  INT16_C( 23088), -INT16_C( 20436), -INT16_C( 20675),
         INT16_C( 32714),  INT16_C(  6715),  INT16_C( 20372),  INT16_C( 25187), -INT16_C( 27554), -INT16_C( 31649),  INT16_C( 25395), -INT16_C( 29086) },
      UINT16_C(14838),
      {  INT16_C(  1565), -INT16_C(  4702), -INT16_C(  1695), -INT16_C( 28165),  INT16_C( 10067), -INT16_C( 28606),  INT16_C(  3286),  INT16_C(  4623),
        -INT16_C( 23769), -INT16_C( 30111), -INT16_C( 16635),  INT16_C( 25886),  INT16_C( 20803), -INT16_C( 23096), -INT16_C( 16672), -INT16_C(   545) },
      { -INT16_C( 27813),  INT16_C(  4623),  INT16_C(  1565),  INT16_C( 23504),  INT16_C(  3286),  INT16_C(  1565),  INT16_C(  3790), -INT16_C( 23096),
         INT16_C(  5200),  INT16_C(  6715),  INT16_C( 20372),  INT16_C( 16785), -INT16_C( 16672), -INT16_C(   545),  INT16_C( 25395), -INT16_C( 29086) } },
    { { -INT16_C( 32315),  INT16_C(  9962), -INT16_C(  6790), -INT16_C( 12872), -INT16_C(  1524), -INT16_C(  7331),  INT16_C( 27910),  INT16_C( 11765),
         INT16_C( 22032),  INT16_C(  5815), -INT16_C( 10730),  INT16_C( 22907),  INT16_C( 17191),  INT16_C(  2047), -INT16_C(  8703), -INT16_C( 14844) },
      { -INT16_C(  4513), -INT16_C(  9491), -INT16_C( 23085), -INT16_C(  8025),  INT16_C(  1439), -INT16_C( 23101), -INT16_C( 18318), -INT16_C( 32045),
        -INT16_C( 30194),  INT16_C(  9368),  INT16_C(  4960), -INT16_C( 30594),  INT16_C( 32086),  INT16_C( 22671), -INT16_C( 27557), -INT16_C( 17890) },
      UINT16_C( 2946),
      {  INT16_C( 22164),  INT16_C( 15536),  INT16_C( 20278), -INT16_C(  1727), -INT16_C( 19467), -INT16_C( 14159), -INT16_C( 16587), -INT16_C( 12718),
        -INT16_C( 19484),  INT16_C( 25313),  INT16_C( 14395), -INT16_C( 13601),  INT16_C( 14992), -INT16_C( 20898), -INT16_C(  7692), -INT16_C( 30278) },
      { -INT16_C(  4513),  INT16_C(  2047), -INT16_C( 23085), -INT16_C(  8025),  INT16_C(  1439), -INT16_C( 23101), -INT16_C( 18318), -INT16_C(  1727),
        -INT16_C(  8703), -INT16_C( 19484),  INT16_C(  4960), -INT16_C(  7692),  INT16_C( 32086),  INT16_C( 22671), -INT16_C( 27557), -INT16_C( 17890) } },
    { {  INT16_C( 27191),  INT16_C( 28101),  INT16_C(  1722), -INT16_C( 20634),  INT16_C(  6073), -INT16_C(  4489), -INT16_C( 13866), -INT16_C( 17732),
        -INT16_C( 24964), -INT16_C( 18660), -INT16_C(  1066),  INT16_C( 26242), -INT16_C(  8139),  INT16_C( 10772), -INT16_C( 12607), -INT16_C(  1869) },
      {  INT16_C( 30777), -INT16_C(  3227), -INT16_C( 13442),  INT16_C( 14242),  INT16_C(  6626), -INT16_C( 18139), -INT16_C(  7454),  INT16_C( 24435),
        -INT16_C( 28544),  INT16_C( 22038), -INT16_C( 26485), -INT16_C( 15940), -INT16_C( 12167),  INT16_C( 15083), -INT16_C( 24929), -INT16_C( 10189) },
      UINT16_C(38934),
      { -INT16_C( 27445),  INT16_C( 28004),  INT16_C( 18123), -INT16_C(  3962),  INT16_C( 26879),  INT16_C( 29650),  INT16_C( 21191), -INT16_C(  8701),
        -INT16_C( 29016),  INT16_C( 25718), -INT16_C(  4273),  INT16_C( 14901), -INT16_C( 11222),  INT16_C( 24024), -INT16_C(  4436),  INT16_C( 30709) },
      {  INT16_C( 30777), -INT16_C(  4489), -INT16_C(  4436),  INT16_C( 14242),  INT16_C(  1722), -INT16_C( 18139), -INT16_C(  7454),  INT16_C( 24435),
        -INT16_C( 28544),  INT16_C( 22038), -INT16_C( 26485), -INT16_C( 11222),  INT16_C( 25718),  INT16_C( 15083), -INT16_C( 24929), -INT16_C(  3962) } },
    { {  INT16_C( 22914),  INT16_C( 19940),  INT16_C( 27296), -INT16_C( 24770),  INT16_C(  4306), -INT16_C( 26094),  INT16_C(  5475),  INT16_C(  2936),
        -INT16_C(  4444), -INT16_C(  3216), -INT16_C( 23074),  INT16_C(  2094),  INT16_C(  1657),  INT16_C(  9573),  INT16_C( 23285),  INT16_C( 30620) },
      { -INT16_C( 32588),  INT16_C( 21701),  INT16_C(  1002), -INT16_C( 17165),  INT16_C(  1555),  INT16_C( 30294), -INT16_C( 12773), -INT16_C( 16510),
        -INT16_C(  3395), -INT16_C( 25677), -INT16_C(  7785),  INT16_C(  4259),  INT16_C(  2279), -INT16_C(  9163), -INT16_C( 11934),  INT16_C(  5716) },
      UINT16_C( 6481),
      {  INT16_C( 15210),  INT16_C( 24092),  INT16_C( 12279),  INT16_C( 20068),  INT16_C( 32678),  INT16_C( 10268), -INT16_C(  9921), -INT16_C(  3558),
        -INT16_C( 20108),  INT16_C(  6099), -INT16_C( 17727), -INT16_C(  2529), -INT16_C( 32105), -INT16_C(  5177),  INT16_C(  6296),  INT16_C(   772) },
      {  INT16_C( 32678),  INT16_C( 21701),  INT16_C(  1002), -INT16_C( 17165),  INT16_C( 20068),  INT16_C( 30294), -INT16_C(  2529), -INT16_C( 16510),
        -INT16_C(  5177), -INT16_C( 25677), -INT16_C(  7785), -INT16_C( 24770),  INT16_C(  2936), -INT16_C(  9163), -INT16_C( 11934),  INT16_C(  5716) } },
    { {  INT16_C(  8275),  INT16_C( 19041), -INT16_C( 15025), -INT16_C(  2664), -INT16_C( 19132), -INT16_C( 31971),  INT16_C( 14222),  INT16_C(   885),
         INT16_C( 18664), -INT16_C( 22246),  INT16_C( 14851), -INT16_C( 25953),  INT16_C( 26300),  INT16_C( 21637), -INT16_C( 30338), -INT16_C( 11945) },
      { -INT16_C( 18263), -INT16_C(  2020), -INT16_C( 19331), -INT16_C( 15634),  INT16_C(  2921), -INT16_C(  1979), -INT16_C( 17597),  INT16_C( 11259),
         INT16_C(  5379),  INT16_C(  1749),  INT16_C( 29775),  INT16_C(  2976),  INT16_C(  9691),  INT16_C( 22880), -INT16_C( 18514),  INT16_C( 22315) },
      UINT16_C(18288),
      { -INT16_C(  4784),  INT16_C( 16123),  INT16_C( 26031), -INT16_C(  2743), -INT16_C( 29603),  INT16_C( 22704), -INT16_C( 19528), -INT16_C( 29331),
        -INT16_C( 16966),  INT16_C( 23041), -INT16_C(  9016),  INT16_C( 10368),  INT16_C( 11830),  INT16_C( 25056),  INT16_C( 20614), -INT16_C( 10584) },
      { -INT16_C( 18263), -INT16_C(  2020), -INT16_C( 19331), -INT16_C( 15634), -INT16_C( 22246), -INT16_C( 31971), -INT16_C(  2664),  INT16_C( 11259),
        -INT16_C(  2664),  INT16_C( 22704), -INT16_C( 11945),  INT16_C(  2976),  INT16_C(  9691),  INT16_C( 22880), -INT16_C( 30338),  INT16_C( 22315) } },
    { { -INT16_C( 23747), -INT16_C(  4844),  INT16_C( 23816),  INT16_C( 26082), -INT16_C( 27926), -INT16_C( 23875),  INT16_C( 11077), -INT16_C(   209),
         INT16_C( 12520), -INT16_C( 20390), -INT16_C(  9715),  INT16_C( 17369), -INT16_C( 18168), -INT16_C( 29020),  INT16_C( 19465),  INT16_C( 18020) },
      {  INT16_C( 30959), -INT16_C(  1997),  INT16_C(  5590), -INT16_C( 16291),  INT16_C(  7079), -INT16_C(  4766), -INT16_C( 28346),  INT16_C( 12012),
         INT16_C( 18113), -INT16_C( 12578), -INT16_C( 18656),  INT16_C( 10513), -INT16_C( 19088),  INT16_C( 31159),  INT16_C(  7169), -INT16_C(  3648) },
      UINT16_C(62356),
      {  INT16_C( 27369),  INT16_C( 17929), -INT16_C( 20438), -INT16_C( 29599), -INT16_C( 22627), -INT16_C( 30179), -INT16_C(  8235), -INT16_C( 19248),
        -INT16_C(  3667), -INT16_C( 16533), -INT16_C(  9190), -INT16_C( 11916),  INT16_C( 30293),  INT16_C(  5613), -INT16_C( 32153),  INT16_C( 20489) },
      {  INT16_C( 30959), -INT16_C(  1997), -INT16_C(  8235), -INT16_C( 16291), -INT16_C(   209), -INT16_C(  4766), -INT16_C( 28346), -INT16_C( 18168),
        -INT16_C(  4844), -INT16_C( 32153), -INT16_C( 18656),  INT16_C( 10513),  INT16_C( 27369), -INT16_C( 19248), -INT16_C(  4844), -INT16_C( 23747) } },
    { {  INT16_C(  4844),  INT16_C(  6038), -INT16_C(  1854),  INT16_C( 24739), -INT16_C( 15969),  INT16_C( 30186), -INT16_C( 17760),  INT16_C( 19753),
        -INT16_C( 27477), -INT16_C( 15092), -INT16_C( 32400), -INT16_C( 14697), -INT16_C( 31497),  INT16_C( 24283), -INT16_C(  7162), -INT16_C(  3154) },
      {  INT16_C( 17654), -INT16_C( 18166), -INT16_C( 21188), -INT16_C(  9191),  INT16_C(   878),  INT16_C(  3665),  INT16_C( 31421),  INT16_C( 26972),
         INT16_C( 26638),  INT16_C( 32558), -INT16_C( 14871), -INT16_C(  8123),  INT16_C(  8266),  INT16_C( 20542), -INT16_C(  5115), -INT16_C(  1213) },
      UINT16_C(19761),
      {  INT16_C( 28084), -INT16_C( 12805),  INT16_C( 26953), -INT16_C( 25904), -INT16_C( 29064), -INT16_C( 11244),  INT16_C(  9207),  INT16_C(  9532),
         INT16_C(  9890), -INT16_C(  6165),  INT16_C( 13574),  INT16_C( 17671),  INT16_C(  3205), -INT16_C( 14031),  INT16_C( 25096), -INT16_C( 17386) },
      {  INT16_C(  9207), -INT16_C( 18166), -INT16_C( 21188), -INT16_C(  9191), -INT16_C(  7162), -INT16_C( 12805),  INT16_C( 31421),  INT16_C( 26972),
        -INT16_C(  7162),  INT16_C( 32558), -INT16_C( 15092),  INT16_C( 30186),  INT16_C(  8266),  INT16_C( 20542),  INT16_C( 30186), -INT16_C(  1213) } },
    { {  INT16_C(  4560),  INT16_C(  6538),  INT16_C( 23163), -INT16_C(  3148), -INT16_C( 14104), -INT16_C(  8249),  INT16_C(  1003), -INT16_C( 29435),
        -INT16_C(  4055),  INT16_C( 12404),  INT16_C( 31781), -INT16_C( 21899), -INT16_C( 22904), -INT16_C( 28557), -INT16_C( 30199), -INT16_C(  9907) },
      { -INT16_C( 10341),  INT16_C(  5874), -INT16_C( 22991),  INT16_C(  6665), -INT16_C( 12177),  INT16_C( 23289), -INT16_C(   300), -INT16_C(   536),
         INT16_C( 23790),  INT16_C(  4909), -INT16_C( 23848),  INT16_C( 25022),  INT16_C( 12617),  INT16_C( 21233),  INT16_C( 16059),  INT16_C( 22315) },
      UINT16_C( 7445),
      {  INT16_C( 18285),  INT16_C( 30660),  INT16_C( 13153),  INT16_C( 23111),  INT16_C(  7053),  INT16_C( 30041),  INT16_C( 18201),  INT16_C( 18130),
        -INT16_C( 21925),  INT16_C(  6633),  INT16_C( 12811), -INT16_C(   694),  INT16_C(  1668), -INT16_C( 20677),  INT16_C( 20829), -INT16_C( 13620) },
      { -INT16_C(   694),  INT16_C(  5874),  INT16_C( 30660),  INT16_C(  6665), -INT16_C(  9907),  INT16_C( 23289), -INT16_C(   300), -INT16_C(   536),
        -INT16_C( 30199),  INT16_C(  4909), -INT16_C( 21925),  INT16_C( 20829),  INT16_C( 12404),  INT16_C( 21233),  INT16_C( 16059),  INT16_C( 22315) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask2_permutex2var_epi16(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask2_permutex2var_epi16(a, idx, k, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t idx[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(37016),
      { -INT16_C(  1727), -INT16_C( 30269),  INT16_C( 20819), -INT16_C( 21340), -INT16_C( 16954), -INT16_C( 26380),  INT16_C( 20228), -INT16_C(  4797),
         INT16_C( 20072), -INT16_C( 19937), -INT16_C( 23733), -INT16_C( 30792),  INT16_C(  5458),  INT16_C(  7896),  INT16_C( 28896),  INT16_C(  8623) },
      {  INT16_C( 29289), -INT16_C( 17238),  INT16_C( 20419), -INT16_C( 30103),  INT16_C( 23820),  INT16_C(  4130),  INT16_C( 26028),  INT16_C(  5373),
         INT16_C(  7348), -INT16_C(    58),  INT16_C( 32703),  INT16_C(  4486),  INT16_C( 24212),  INT16_C( 29744), -INT16_C(  8242),  INT16_C( 14230) },
      {  INT16_C( 16465),  INT16_C(  5620),  INT16_C( 23951), -INT16_C( 25441), -INT16_C( 15942),  INT16_C( 26284), -INT16_C( 21977), -INT16_C(  9350),
         INT16_C( 16582), -INT16_C( 31014),  INT16_C( 25023),  INT16_C( 21655), -INT16_C( 14401), -INT16_C( 28984),  INT16_C( 24230), -INT16_C(  1851) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19937),  INT16_C(  5458),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28984),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 15942),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21977) } },
    { UINT16_C(47519),
      {  INT16_C( 11789), -INT16_C( 21482), -INT16_C( 12086),  INT16_C( 30573), -INT16_C( 27594), -INT16_C( 20447), -INT16_C(  6289),  INT16_C( 19185),
        -INT16_C( 20371),  INT16_C(  1451),  INT16_C( 27140), -INT16_C( 12852),  INT16_C( 29688), -INT16_C( 16853), -INT16_C( 13717),  INT16_C( 30839) },
      { -INT16_C( 28935), -INT16_C( 15580), -INT16_C( 28322), -INT16_C( 27334),  INT16_C( 23334), -INT16_C( 27323),  INT16_C( 13891), -INT16_C( 20257),
        -INT16_C( 29977), -INT16_C(  5195), -INT16_C( 32011), -INT16_C(  4680), -INT16_C(  6923),  INT16_C( 24747),  INT16_C(  9134), -INT16_C( 22568) },
      { -INT16_C(   847),  INT16_C(  3947), -INT16_C( 23155), -INT16_C( 19548), -INT16_C(  5631),  INT16_C( 17481),  INT16_C( 10272),  INT16_C(  2036),
        -INT16_C( 21837), -INT16_C( 22285), -INT16_C( 21716),  INT16_C(  8597),  INT16_C( 16783),  INT16_C( 16001),  INT16_C( 22884),  INT16_C(  5605) },
      { -INT16_C( 22285), -INT16_C( 27594),  INT16_C( 22884), -INT16_C( 21716), -INT16_C(  6289),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5605),
         INT16_C( 19185),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21837),  INT16_C( 17481), -INT16_C( 12852),  INT16_C(     0), -INT16_C( 21837) } },
    { UINT16_C(20565),
      { -INT16_C(  7644), -INT16_C( 13834), -INT16_C(  2154), -INT16_C(  8269), -INT16_C( 11461),  INT16_C( 12039), -INT16_C( 17701), -INT16_C( 12583),
         INT16_C(  1378), -INT16_C(  1927),  INT16_C(  2342), -INT16_C( 22727), -INT16_C( 25273),  INT16_C( 11264),  INT16_C( 21938), -INT16_C( 10627) },
      {  INT16_C( 29496), -INT16_C( 12641),  INT16_C( 21098), -INT16_C( 23123), -INT16_C( 19418),  INT16_C(   468), -INT16_C( 20881), -INT16_C( 11825),
         INT16_C( 18611), -INT16_C(  9527),  INT16_C(   593), -INT16_C( 26495), -INT16_C( 32097),  INT16_C( 20933),  INT16_C( 17111),  INT16_C(  3880) },
      { -INT16_C( 14411),  INT16_C(  8157), -INT16_C( 30182),  INT16_C( 16580), -INT16_C( 26561), -INT16_C( 20927),  INT16_C(  4166), -INT16_C(  1409),
         INT16_C( 18776), -INT16_C( 21804),  INT16_C( 21835), -INT16_C(  5310),  INT16_C(  2007), -INT16_C( 20676),  INT16_C( 25673), -INT16_C(   322) },
      {  INT16_C( 18776),  INT16_C(     0),  INT16_C(  2342),  INT16_C(     0), -INT16_C( 17701),  INT16_C(     0), -INT16_C( 10627),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(   322),  INT16_C(     0), -INT16_C(  1409),  INT16_C(     0) } },
    { UINT16_C(39980),
      {  INT16_C( 17949), -INT16_C(  7898),  INT16_C( 25990), -INT16_C( 14470), -INT16_C( 16365), -INT16_C( 27689),  INT16_C( 12218), -INT16_C( 28964),
         INT16_C( 10201),  INT16_C(  7396), -INT16_C( 17646),  INT16_C( 20259),  INT16_C( 28010),  INT16_C( 10675), -INT16_C(  8341), -INT16_C( 30267) },
      { -INT16_C(  5339), -INT16_C( 21654), -INT16_C(  7087),  INT16_C( 25714),  INT16_C( 18853),  INT16_C( 24567), -INT16_C( 11399),  INT16_C( 21230),
        -INT16_C( 11525),  INT16_C(  3438), -INT16_C( 28019), -INT16_C(  1956),  INT16_C(  4351),  INT16_C( 27169), -INT16_C(  6417),  INT16_C(  5619) },
      {  INT16_C( 24273),  INT16_C(  8896),  INT16_C( 13122), -INT16_C(  6265),  INT16_C( 32380), -INT16_C(  2745),  INT16_C( 13650),  INT16_C( 19784),
        -INT16_C( 18937), -INT16_C( 27558), -INT16_C( 18616),  INT16_C( 18316), -INT16_C( 21049), -INT16_C( 18766), -INT16_C( 23149),  INT16_C( 26059) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  8896),  INT16_C( 13122),  INT16_C(     0),  INT16_C( 19784),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 10675), -INT16_C( 21049),  INT16_C( 26059),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6265) } },
    { UINT16_C(35843),
      {  INT16_C( 18055),  INT16_C(  3775),  INT16_C( 15149),  INT16_C( 29837), -INT16_C(  8399),  INT16_C( 31145), -INT16_C( 20436), -INT16_C( 31185),
         INT16_C( 30789), -INT16_C( 11971),  INT16_C(  1215),  INT16_C( 29055),  INT16_C(  4795), -INT16_C( 31209),  INT16_C(  6775), -INT16_C(   238) },
      { -INT16_C( 11936), -INT16_C( 29171), -INT16_C( 26099),  INT16_C( 15874), -INT16_C( 21383), -INT16_C( 23113), -INT16_C(  6564), -INT16_C( 24276),
         INT16_C( 26974),  INT16_C(  7795), -INT16_C(  3474),  INT16_C( 10639), -INT16_C( 23036),  INT16_C( 31919), -INT16_C( 15679),  INT16_C(  8571) },
      { -INT16_C( 30573), -INT16_C( 24401), -INT16_C( 19933), -INT16_C( 25378), -INT16_C( 27298), -INT16_C( 17854),  INT16_C( 28284), -INT16_C(  9636),
        -INT16_C( 12329),  INT16_C( 17912), -INT16_C( 30527), -INT16_C( 14994),  INT16_C(  7726), -INT16_C(  4287), -INT16_C( 17184),  INT16_C( 29457) },
      {  INT16_C( 18055), -INT16_C( 31209),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  6775), -INT16_C(   238),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14994) } },
    { UINT16_C(49221),
      {  INT16_C( 26644), -INT16_C(  3470), -INT16_C( 12284),  INT16_C( 18056),  INT16_C(  1163), -INT16_C(  6220), -INT16_C( 29474), -INT16_C( 10314),
         INT16_C( 30673),  INT16_C( 16479), -INT16_C( 29380),  INT16_C( 32350),  INT16_C( 15997), -INT16_C( 29126),  INT16_C( 32689), -INT16_C( 15026) },
      { -INT16_C( 15897), -INT16_C(  4936),  INT16_C( 16529),  INT16_C(  7218), -INT16_C(  6332),  INT16_C(  8707), -INT16_C( 18061),  INT16_C( 17657),
         INT16_C( 22576),  INT16_C( 28036), -INT16_C(  7450),  INT16_C( 25579),  INT16_C(  9504), -INT16_C( 11535),  INT16_C( 16293), -INT16_C( 29545) },
      {  INT16_C( 20224), -INT16_C( 28040), -INT16_C( 21617), -INT16_C( 11346), -INT16_C( 19822),  INT16_C(  1526), -INT16_C(  4245), -INT16_C( 25527),
        -INT16_C( 12728),  INT16_C( 11785), -INT16_C(  2896), -INT16_C( 11887), -INT16_C( 32231), -INT16_C( 16733),  INT16_C( 15041), -INT16_C( 15797) },
      { -INT16_C( 10314),  INT16_C(     0), -INT16_C( 28040),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11346),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6220), -INT16_C( 25527) } },
    { UINT16_C(50058),
      {  INT16_C(  6484),  INT16_C(   622),  INT16_C(   237), -INT16_C(  7244),  INT16_C(  8197),  INT16_C( 20434),  INT16_C(  6844), -INT16_C( 15075),
        -INT16_C( 12984), -INT16_C(  9799), -INT16_C( 11618),  INT16_C( 16731),  INT16_C(  7569), -INT16_C(  9092),  INT16_C(  1759),  INT16_C( 13215) },
      {  INT16_C(  3615),  INT16_C(  3125), -INT16_C(  5618),  INT16_C(  5359), -INT16_C( 15862), -INT16_C( 14749), -INT16_C( 32548),  INT16_C(  9611),
         INT16_C( 17485), -INT16_C(  4866),  INT16_C( 23062), -INT16_C( 22739), -INT16_C( 22153),  INT16_C( 22147),  INT16_C(  9135), -INT16_C( 12407) },
      { -INT16_C( 16847),  INT16_C( 16347), -INT16_C( 13400), -INT16_C( 19885), -INT16_C( 18803),  INT16_C( 27000),  INT16_C(   822), -INT16_C( 31602),
        -INT16_C( 29369),  INT16_C( 24176), -INT16_C( 25113),  INT16_C( 24069), -INT16_C( 30393), -INT16_C(  2380),  INT16_C( 15788), -INT16_C(  8763) },
      {  INT16_C(     0),  INT16_C( 27000),  INT16_C(     0),  INT16_C( 13215),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16731),
        -INT16_C(  9092),  INT16_C( 15788),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13215), -INT16_C(  9799) } },
    { UINT16_C(41467),
      { -INT16_C( 23524),  INT16_C( 28780), -INT16_C(  1706), -INT16_C( 12506),  INT16_C( 23906), -INT16_C(  3630),  INT16_C(  6881),  INT16_C( 20862),
         INT16_C( 25976),  INT16_C( 32238),  INT16_C( 13763),  INT16_C( 30470), -INT16_C( 19924), -INT16_C(  3660), -INT16_C( 20593), -INT16_C( 21358) },
      { -INT16_C(   429), -INT16_C( 21988),  INT16_C( 17143),  INT16_C( 23161),  INT16_C( 19359), -INT16_C( 32693), -INT16_C( 13979), -INT16_C(  8751),
        -INT16_C( 16338), -INT16_C(  3749),  INT16_C( 25077),  INT16_C(  8552),  INT16_C(  7188), -INT16_C( 23789), -INT16_C( 23093),  INT16_C(  8015) },
      {  INT16_C( 27556), -INT16_C( 25655),  INT16_C( 17070),  INT16_C( 19957),  INT16_C( 16525), -INT16_C(  3122), -INT16_C( 24823),  INT16_C( 14288),
         INT16_C( 11103),  INT16_C( 21800), -INT16_C( 28531), -INT16_C( 24202), -INT16_C( 30292),  INT16_C( 30788), -INT16_C( 27601), -INT16_C( 11369) },
      {  INT16_C( 19957), -INT16_C( 30292),  INT16_C(     0),  INT16_C( 21800), -INT16_C( 11369),  INT16_C( 30470), -INT16_C(  3630), -INT16_C( 25655),
        -INT16_C( 20593),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19957),  INT16_C(     0), -INT16_C( 21358) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi16(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_permutex2var_epi16(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i idx = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_permutex2var_epi16(k, a, idx, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const int32_t idx[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1385275137),  INT32_C(   805004450), -INT32_C(  1373451868), -INT32_C(   924454040), -INT32_C(  1424159202),  INT32_C(  1263309726),  INT32_C(  1287885085),  INT32_C(   606034469) },
      {  INT32_C(  1557302714), -INT32_C(  1769222671), -INT32_C(    29053290), -INT32_C(  1077532255), -INT32_C(   697572553), -INT32_C(  1809729673),  INT32_C(  1843455048), -INT32_C(   124584130) },
      {  INT32_C(  2119459980), -INT32_C(   954933455),  INT32_C(   784685197), -INT32_C(  1175548799), -INT32_C(   426813073),  INT32_C(  1501212688), -INT32_C(   758752620), -INT32_C(   422946727) },
      {  INT32_C(   784685197),  INT32_C(   805004450),  INT32_C(  1287885085),  INT32_C(   805004450),  INT32_C(   606034469),  INT32_C(   606034469),  INT32_C(  2119459980), -INT32_C(   758752620) } },
    { { -INT32_C(   312205636), -INT32_C(  1951106819),  INT32_C(  1371110096),  INT32_C(  1963632390),  INT32_C(   291281152), -INT32_C(   580200887), -INT32_C(  1968230351),  INT32_C(  1164999049) },
      { -INT32_C(  1791765353),  INT32_C(   471918412),  INT32_C(  1735317857), -INT32_C(  2116192127),  INT32_C(  1536309522),  INT32_C(  1077541903), -INT32_C(  1228150739), -INT32_C(   100975774) },
      {  INT32_C(  1552821776),  INT32_C(  2004463126),  INT32_C(   165668744),  INT32_C(  1904917599),  INT32_C(    80551413),  INT32_C(  1178928665),  INT32_C(  1358696686),  INT32_C(  1531639883) },
      {  INT32_C(  1164999049),  INT32_C(    80551413), -INT32_C(  1951106819), -INT32_C(  1951106819),  INT32_C(  1371110096),  INT32_C(  1531639883),  INT32_C(  1178928665),  INT32_C(  1371110096) } },
    { {  INT32_C(  1018746918),  INT32_C(   263467399),  INT32_C(  1998099224),  INT32_C(  1156162127), -INT32_C(   649546049), -INT32_C(  1440772676), -INT32_C(   369419107),  INT32_C(   977552660) },
      { -INT32_C(  1535640547),  INT32_C(  1169369901),  INT32_C(   230542270),  INT32_C(   760325742),  INT32_C(   403085660), -INT32_C(   993909209),  INT32_C(  1454226754),  INT32_C(   546370050) },
      {  INT32_C(   482609134), -INT32_C(   262047694), -INT32_C(  1308811709),  INT32_C(   551505604),  INT32_C(   255387112),  INT32_C(  1305737995), -INT32_C(  1146912328),  INT32_C(  1641755763) },
      {  INT32_C(  1305737995),  INT32_C(  1305737995), -INT32_C(  1146912328), -INT32_C(  1146912328),  INT32_C(   255387112),  INT32_C(   977552660),  INT32_C(  1998099224),  INT32_C(  1998099224) } },
    { {  INT32_C(  1853726523),  INT32_C(  1532944151), -INT32_C(  1039377155), -INT32_C(  1830622294), -INT32_C(   593421359), -INT32_C(   836078314),  INT32_C(  1770638838),  INT32_C(  1036674049) },
      {  INT32_C(   464209924),  INT32_C(   611715367),  INT32_C(   283542373),  INT32_C(  1067633006), -INT32_C(    98810652), -INT32_C(  1345829191),  INT32_C(   353915411), -INT32_C(  1168973130) },
      {  INT32_C(  1373044010),  INT32_C(  1819692038),  INT32_C(  1048337615),  INT32_C(   159194661),  INT32_C(   453220706), -INT32_C(   204813089), -INT32_C(   737615330), -INT32_C(   275817787) },
      { -INT32_C(   593421359),  INT32_C(  1036674049), -INT32_C(   836078314), -INT32_C(   737615330), -INT32_C(   593421359),  INT32_C(  1819692038), -INT32_C(  1830622294),  INT32_C(  1770638838) } },
    { {  INT32_C(  1564566871), -INT32_C(  2117486671),  INT32_C(   968836371), -INT32_C(   968737692), -INT32_C(  1243461930),  INT32_C(   816360466),  INT32_C(  1409593487),  INT32_C(  1631818506) },
      { -INT32_C(  1430289160),  INT32_C(  1328252987),  INT32_C(   847833806), -INT32_C(    50804186),  INT32_C(   582146576),  INT32_C(   374495879),  INT32_C(   359290635), -INT32_C(   478695958) },
      {  INT32_C(  1837970994), -INT32_C(  1933788994), -INT32_C(   927054686),  INT32_C(   533051151),  INT32_C(   407009169), -INT32_C(   600927023), -INT32_C(   688744213),  INT32_C(  2025417030) },
      {  INT32_C(  1837970994),  INT32_C(   533051151), -INT32_C(   688744213),  INT32_C(  1409593487),  INT32_C(  1564566871),  INT32_C(  1631818506),  INT32_C(   533051151), -INT32_C(   927054686) } },
    { {  INT32_C(  1575306911), -INT32_C(  1595235586), -INT32_C(   177690394), -INT32_C(   250270369),  INT32_C(  1980323748), -INT32_C(   682477333),  INT32_C(   380454096),  INT32_C(  1284400813) },
      { -INT32_C(  1431669588), -INT32_C(    62221290), -INT32_C(  1661816260), -INT32_C(  2071132192),  INT32_C(  1241159262), -INT32_C(  1625272882),  INT32_C(  1068879249), -INT32_C(   544521165) },
      { -INT32_C(   829868616),  INT32_C(   113955785),  INT32_C(  1721941126),  INT32_C(   568995779), -INT32_C(  1804868155), -INT32_C(  1020032206), -INT32_C(  1945966503), -INT32_C(   462647764) },
      { -INT32_C(  1804868155),  INT32_C(   380454096), -INT32_C(  1804868155),  INT32_C(  1575306911), -INT32_C(  1945966503), -INT32_C(  1945966503), -INT32_C(  1595235586), -INT32_C(   250270369) } },
    { { -INT32_C(  1917651517),  INT32_C(  1335066057), -INT32_C(    38456007),  INT32_C(   689872740), -INT32_C(  1229092476),  INT32_C(  1853550613),  INT32_C(   100302041), -INT32_C(   823499254) },
      {  INT32_C(   626760796),  INT32_C(  1400172057), -INT32_C(  2024789725),  INT32_C(  1303408328),  INT32_C(   218328824),  INT32_C(   930839902),  INT32_C(    71136762),  INT32_C(   953296860) },
      { -INT32_C(   581095997),  INT32_C(  1043386651), -INT32_C(  1027243782), -INT32_C(   435194130),  INT32_C(  1123226596), -INT32_C(  1971687792), -INT32_C(  1064323100), -INT32_C(  1577557538) },
      {  INT32_C(  1123226596),  INT32_C(  1043386651),  INT32_C(   689872740), -INT32_C(   581095997), -INT32_C(   581095997), -INT32_C(  1064323100), -INT32_C(  1027243782),  INT32_C(  1123226596) } },
    { { -INT32_C(  1434561137),  INT32_C(   552185382),  INT32_C(   501394990),  INT32_C(   134476324), -INT32_C(  1790183675),  INT32_C(  1226884453),  INT32_C(  1510584188), -INT32_C(  1610940144) },
      {  INT32_C(  2085255766),  INT32_C(  1469854504),  INT32_C(   108298209),  INT32_C(  1980659569), -INT32_C(   737453714), -INT32_C(  1709364450), -INT32_C(   336320550),  INT32_C(  2139811880) },
      { -INT32_C(  1828989846), -INT32_C(   370567161), -INT32_C(  1997578985),  INT32_C(  1140784597),  INT32_C(  1964443991),  INT32_C(   252720437), -INT32_C(  2063989668),  INT32_C(  1577289204) },
      {  INT32_C(  1510584188), -INT32_C(  1828989846),  INT32_C(   552185382),  INT32_C(   552185382), -INT32_C(  2063989668), -INT32_C(  2063989668), -INT32_C(  1997578985), -INT32_C(  1828989846) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_permutex2var_epi32(a, idx, b);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_permutex2var_epi32(a, idx, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const simde__mmask8 k;
    const int32_t idx[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1643249497), -INT32_C(  1370826089),  INT32_C(   221657400), -INT32_C(  1924123594),  INT32_C(  1912825917), -INT32_C(   108915811),  INT32_C(   209550359),  INT32_C(  1533706497) },
      UINT8_C(128),
      {  INT32_C(   907525211),  INT32_C(  1064224006),  INT32_C(   796228603),  INT32_C(   862716875),  INT32_C(   433118982), -INT32_C(   584005279), -INT32_C(   924894137),  INT32_C(    38288039) },
      { -INT32_C(    63414282),  INT32_C(   524002852), -INT32_C(   313610207), -INT32_C(  1189037389), -INT32_C(    86838887),  INT32_C(    30933946), -INT32_C(   422987969), -INT32_C(   404155919) },
      {  INT32_C(  1643249497), -INT32_C(  1370826089),  INT32_C(   221657400), -INT32_C(  1924123594),  INT32_C(  1912825917), -INT32_C(   108915811),  INT32_C(   209550359),  INT32_C(  1533706497) } },
    { { -INT32_C(  1797054096), -INT32_C(   374137144), -INT32_C(  2099904050),  INT32_C(  1429993404), -INT32_C(  1571811608),  INT32_C(  1352935441), -INT32_C(   801673761), -INT32_C(   273211265) },
      UINT8_C( 65),
      { -INT32_C(  1207335782),  INT32_C(   965145399), -INT32_C(  1057683255),  INT32_C(  1386760772), -INT32_C(  1033679974),  INT32_C(  1554101231),  INT32_C(   182153706), -INT32_C(  1035154648) },
      { -INT32_C(  2038803121),  INT32_C(   314507592),  INT32_C(  1305654281), -INT32_C(  1717601281), -INT32_C(  1252261178), -INT32_C(  1609433674), -INT32_C(  1750340241),  INT32_C(   123402168) },
      {  INT32_C(  1305654281), -INT32_C(   374137144), -INT32_C(  2099904050),  INT32_C(  1429993404), -INT32_C(  1571811608),  INT32_C(  1352935441),  INT32_C(  1305654281), -INT32_C(   273211265) } },
    { { -INT32_C(  1785867188), -INT32_C(   542683691),  INT32_C(     2914561), -INT32_C(  1164260108), -INT32_C(  2073037106),  INT32_C(  1646625267),  INT32_C(   653971566),  INT32_C(   321737927) },
      UINT8_C( 40),
      {  INT32_C(   134129850), -INT32_C(   922100401), -INT32_C(   709031671), -INT32_C(  1717274461),  INT32_C(  1754081511),  INT32_C(   500625229),  INT32_C(  1038417129), -INT32_C(   463013847) },
      { -INT32_C(   253008736),  INT32_C(  1253700673), -INT32_C(  1591707906), -INT32_C(   700726034),  INT32_C(   977193196), -INT32_C(  1588128329),  INT32_C(  1004420113), -INT32_C(   736148428) },
      { -INT32_C(  1785867188), -INT32_C(   542683691),  INT32_C(     2914561), -INT32_C(  1164260108), -INT32_C(  2073037106), -INT32_C(  1588128329),  INT32_C(   653971566),  INT32_C(   321737927) } },
    { { -INT32_C(   373028184), -INT32_C(    46891521), -INT32_C(   492940044),  INT32_C(    79223064),  INT32_C(  1497298849),  INT32_C(   502961676),  INT32_C(   106485970), -INT32_C(   975538403) },
      UINT8_C(130),
      {  INT32_C(   478261151),  INT32_C(   923827939), -INT32_C(   162532580), -INT32_C(  1567140949),  INT32_C(   682553490), -INT32_C(  1006973718), -INT32_C(  1663041500),  INT32_C(  2032051674) },
      {  INT32_C(   932618068),  INT32_C(   963552797),  INT32_C(  1160756633), -INT32_C(  1545091311), -INT32_C(  1563715913), -INT32_C(  2040150686), -INT32_C(  1625143867),  INT32_C(  1058619626) },
      { -INT32_C(   373028184),  INT32_C(    79223064), -INT32_C(   492940044),  INT32_C(    79223064),  INT32_C(  1497298849),  INT32_C(   502961676),  INT32_C(   106485970),  INT32_C(  1160756633) } },
    { { -INT32_C(    59330593), -INT32_C(   281615019), -INT32_C(  1288411742), -INT32_C(   464118996),  INT32_C(   327557553), -INT32_C(  1415910426),  INT32_C(   441170992), -INT32_C(   598121219) },
      UINT8_C( 19),
      { -INT32_C(  1251419696),  INT32_C(  1951880975), -INT32_C(  1482617973), -INT32_C(  2091350687), -INT32_C(   160863221), -INT32_C(  1037691642), -INT32_C(   994099104),  INT32_C(  1792515226) },
      { -INT32_C(  2078326923),  INT32_C(   586708631), -INT32_C(   473327231),  INT32_C(   694559262), -INT32_C(  1809854578),  INT32_C(  1146504676),  INT32_C(   537400966),  INT32_C(   663412658) },
      { -INT32_C(    59330593),  INT32_C(   663412658), -INT32_C(  1288411742), -INT32_C(   464118996),  INT32_C(   694559262), -INT32_C(  1415910426),  INT32_C(   441170992), -INT32_C(   598121219) } },
    { { -INT32_C(  1230264033), -INT32_C(  1579637985),  INT32_C(  1535418941),  INT32_C(  1384508100), -INT32_C(  1629051719),  INT32_C(  1893874922),  INT32_C(    76606290), -INT32_C(   383051062) },
      UINT8_C(195),
      {  INT32_C(  2061672406),  INT32_C(   448234360), -INT32_C(   237104633),  INT32_C(  1017852055),  INT32_C(  1378240790),  INT32_C(   379950635),  INT32_C(  1088530726), -INT32_C(  1425814827) },
      { -INT32_C(   500832918),  INT32_C(  1895619689), -INT32_C(  2040341777),  INT32_C(   549588234), -INT32_C(  2123175850), -INT32_C(  1533536386), -INT32_C(  1763411519), -INT32_C(  1388189885) },
      {  INT32_C(    76606290), -INT32_C(   500832918),  INT32_C(  1535418941),  INT32_C(  1384508100), -INT32_C(  1629051719),  INT32_C(  1893874922),  INT32_C(    76606290),  INT32_C(  1893874922) } },
    { {  INT32_C(   915367885),  INT32_C(   849775427),  INT32_C(  1874397285),  INT32_C(  1804565269), -INT32_C(   487783836), -INT32_C(   628652775),  INT32_C(  1097886718),  INT32_C(   552579667) },
      UINT8_C( 25),
      {  INT32_C(   173823614),  INT32_C(    91197436), -INT32_C(  1021649080),  INT32_C(  1881638510), -INT32_C(   125171085), -INT32_C(    50961263), -INT32_C(  2024851499), -INT32_C(  1516212442) },
      { -INT32_C(  1028653883), -INT32_C(   741925237),  INT32_C(  1821893117), -INT32_C(   623067545),  INT32_C(  1506961096), -INT32_C(  1604925237),  INT32_C(   640132352), -INT32_C(   624179435) },
      {  INT32_C(   640132352),  INT32_C(   849775427),  INT32_C(  1874397285),  INT32_C(   640132352),  INT32_C(  1804565269), -INT32_C(   628652775),  INT32_C(  1097886718),  INT32_C(   552579667) } },
    { {  INT32_C(  1335655107), -INT32_C(  1776131175), -INT32_C(  1409107643),  INT32_C(  1082646392),  INT32_C(   278550853),  INT32_C(   582021154), -INT32_C(  1438066795),  INT32_C(  1652888734) },
      UINT8_C(142),
      { -INT32_C(  2060996319), -INT32_C(  1916092717), -INT32_C(  1627031872),  INT32_C(  1474643453), -INT32_C(   814090785),  INT32_C(  2103810982), -INT32_C(   149155869), -INT32_C(  1232699756) },
      {  INT32_C(    37465391),  INT32_C(   747570539),  INT32_C(  2043384955), -INT32_C(  1177505574),  INT32_C(  1284065702), -INT32_C(   943067420), -INT32_C(  1832917507), -INT32_C(  1840757405) },
      {  INT32_C(  1335655107),  INT32_C(  1082646392),  INT32_C(  1335655107), -INT32_C(   943067420),  INT32_C(   278550853),  INT32_C(   582021154), -INT32_C(  1438066795),  INT32_C(   278550853) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_permutex2var_epi32(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_permutex2var_epi32(a, k, idx, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask2_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const int32_t idx[8];
    const simde__mmask8 k;
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1586856946),  INT32_C(    59384968), -INT32_C(  1820568135), -INT32_C(  1404285946),  INT32_C(  2046350741), -INT32_C(  1052655165),  INT32_C(   173211815),  INT32_C(   933075781) },
      { -INT32_C(  1500171746),  INT32_C(   262741846),  INT32_C(  2074224245),  INT32_C(   136834930), -INT32_C(  2004803644), -INT32_C(  2025209120),  INT32_C(   127048898),  INT32_C(  1430204215) },
      UINT8_C( 97),
      { -INT32_C(   189269036), -INT32_C(   899037276),  INT32_C(  1480451177),  INT32_C(   706561291), -INT32_C(  1995790906), -INT32_C(  1974758674),  INT32_C(  1405178660),  INT32_C(  1723078290) },
      {  INT32_C(  1405178660),  INT32_C(   262741846),  INT32_C(  2074224245),  INT32_C(   136834930), -INT32_C(  2004803644),  INT32_C(  1586856946), -INT32_C(  1820568135),  INT32_C(  1430204215) } },
    { { -INT32_C(  1252365551), -INT32_C(  1669283022), -INT32_C(  1292583513), -INT32_C(   925101822), -INT32_C(  1538136138), -INT32_C(  1657889415), -INT32_C(  2098139152),  INT32_C(   384345093) },
      {  INT32_C(  1120682767), -INT32_C(  1361163258),  INT32_C(   190894601), -INT32_C(  1697432092), -INT32_C(  1656806108), -INT32_C(  1304793662),  INT32_C(  1647585885), -INT32_C(   579265330) },
      UINT8_C( 95),
      { -INT32_C(  1855578299), -INT32_C(   795208451), -INT32_C(  1313561228), -INT32_C(  1646965128), -INT32_C(    77630835), -INT32_C(   698871380),  INT32_C(  1654962757),  INT32_C(  2025947699) },
      {  INT32_C(  2025947699), -INT32_C(  2098139152), -INT32_C(   795208451), -INT32_C(  1538136138), -INT32_C(  1538136138), -INT32_C(  1304793662), -INT32_C(   698871380), -INT32_C(   579265330) } },
    { { -INT32_C(  1626789983), -INT32_C(  1334860997), -INT32_C(  1050598584), -INT32_C(    10602639),  INT32_C(  1459273385),  INT32_C(   355226319),  INT32_C(  1081594124), -INT32_C(   189253549) },
      { -INT32_C(  1684815264), -INT32_C(  1370815899), -INT32_C(  1754288859), -INT32_C(  1919496732),  INT32_C(  1541640331), -INT32_C(   294645534),  INT32_C(   875489249),  INT32_C(  2133387039) },
      UINT8_C(169),
      { -INT32_C(  1106371652),  INT32_C(   333757542), -INT32_C(   101221589), -INT32_C(  1585150703),  INT32_C(  2021908328),  INT32_C(   911831375), -INT32_C(  2024370784),  INT32_C(  1915803062) },
      { -INT32_C(  1626789983), -INT32_C(  1370815899), -INT32_C(  1754288859),  INT32_C(  1459273385),  INT32_C(  1541640331), -INT32_C(  1050598584),  INT32_C(   875489249),  INT32_C(  1915803062) } },
    { {  INT32_C(  1462779632),  INT32_C(   644486395), -INT32_C(  1608555889),  INT32_C(  1329702119), -INT32_C(   741817213), -INT32_C(   704044746),  INT32_C(  1700618159),  INT32_C(   634883381) },
      { -INT32_C(   964950069), -INT32_C(  1410472164),  INT32_C(   810290249),  INT32_C(   880774576), -INT32_C(  2012788910),  INT32_C(   408817769), -INT32_C(  1518486672),  INT32_C(   332026952) },
      UINT8_C( 91),
      {  INT32_C(   779606599), -INT32_C(   747166777), -INT32_C(    58415249),  INT32_C(  1850652710), -INT32_C(   807938369), -INT32_C(   281022668), -INT32_C(  1070078868), -INT32_C(   165983313) },
      {  INT32_C(  1850652710), -INT32_C(   807938369),  INT32_C(   810290249),  INT32_C(  1462779632), -INT32_C(  1608555889),  INT32_C(   408817769),  INT32_C(  1462779632),  INT32_C(   332026952) } },
    { { -INT32_C(   333147355),  INT32_C(   633314230),  INT32_C(  1747010370), -INT32_C(  1160351493),  INT32_C(  2072685894),  INT32_C(   141216156),  INT32_C(  1573429934),  INT32_C(   307487981) },
      {  INT32_C(   771651447),  INT32_C(  1414708498), -INT32_C(    54758655),  INT32_C(   716674019), -INT32_C(   576372416), -INT32_C(  1192947958), -INT32_C(  1642746191),  INT32_C(   162556050) },
      UINT8_C(223),
      {  INT32_C(  1827747502), -INT32_C(    76724856), -INT32_C(  1780520702),  INT32_C(  1641351456), -INT32_C(  1116949842),  INT32_C(  1181688984), -INT32_C(  1562899142),  INT32_C(  1820516798) },
      {  INT32_C(   307487981),  INT32_C(  1747010370),  INT32_C(   633314230), -INT32_C(  1160351493), -INT32_C(   333147355), -INT32_C(  1192947958),  INT32_C(   633314230),  INT32_C(  1747010370) } },
    { { -INT32_C(  1613204713), -INT32_C(  1147517511), -INT32_C(   816809553),  INT32_C(   808527234),  INT32_C(  1894686168), -INT32_C(    71934527),  INT32_C(   681479786), -INT32_C(  2037047185) },
      {  INT32_C(  1277521299),  INT32_C(  1644674995), -INT32_C(  1154394311),  INT32_C(  1441555069), -INT32_C(  1043997953), -INT32_C(  1581483209),  INT32_C(  2026527241),  INT32_C(   251551610) },
      UINT8_C(204),
      { -INT32_C(   494970333), -INT32_C(  1189355166),  INT32_C(  1966528275), -INT32_C(  1653240893), -INT32_C(   875284912),  INT32_C(  1305769458), -INT32_C(  1631105985),  INT32_C(  1835783498) },
      {  INT32_C(  1277521299),  INT32_C(  1644674995), -INT32_C(  1189355166),  INT32_C(  1305769458), -INT32_C(  1043997953), -INT32_C(  1581483209), -INT32_C(  1189355166),  INT32_C(  1966528275) } },
    { { -INT32_C(  1840190928), -INT32_C(   548705332),  INT32_C(    89424450),  INT32_C(  1587726605), -INT32_C(   232163585),  INT32_C(   725614316), -INT32_C(  1781922230),  INT32_C(   201471452) },
      { -INT32_C(   341945825),  INT32_C(    13298110),  INT32_C(  2030444395), -INT32_C(   388519704),  INT32_C(   198836255),  INT32_C(  1228282366), -INT32_C(    69337057),  INT32_C(  1426579509) },
      UINT8_C( 51),
      { -INT32_C(  1880014683),  INT32_C(   721088779), -INT32_C(  1609403401),  INT32_C(  1270872650), -INT32_C(   313931052),  INT32_C(    17666560),  INT32_C(  1362495600), -INT32_C(  1249604848) },
      { -INT32_C(  1249604848),  INT32_C(  1362495600),  INT32_C(  2030444395), -INT32_C(   388519704), -INT32_C(  1249604848),  INT32_C(  1362495600), -INT32_C(    69337057),  INT32_C(  1426579509) } },
    { { -INT32_C(   683379252),  INT32_C(  1577140070), -INT32_C(    33680462), -INT32_C(   498549490), -INT32_C(  2016374393), -INT32_C(  1802969820), -INT32_C(   169492507),  INT32_C(   380332362) },
      {  INT32_C(  1173221342), -INT32_C(   509350354),  INT32_C(   283025666), -INT32_C(   437115298), -INT32_C(   613629257), -INT32_C(  2056194657), -INT32_C(    25537100), -INT32_C(  1659558465) },
      UINT8_C( 21),
      { -INT32_C(   247209470),  INT32_C(   653468805),  INT32_C(   679740162), -INT32_C(  1193252363), -INT32_C(   883442730), -INT32_C(  2122326997),  INT32_C(  2084601175), -INT32_C(  1785602670) },
      {  INT32_C(  2084601175), -INT32_C(   509350354), -INT32_C(    33680462), -INT32_C(   437115298),  INT32_C(   380332362), -INT32_C(  2056194657), -INT32_C(    25537100), -INT32_C(  1659558465) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask2_permutex2var_epi32(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask2_permutex2var_epi32(a, idx, k, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t idx[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(192),
      { -INT32_C(   112884011),  INT32_C(  2096917625),  INT32_C(  1517364464), -INT32_C(  1070585596),  INT32_C(  1575746433), -INT32_C(   139170694), -INT32_C(  1970654804), -INT32_C(  1756749886) },
      {  INT32_C(   512855973), -INT32_C(   325415429), -INT32_C(  1236923471), -INT32_C(  1233750475), -INT32_C(   351051407),  INT32_C(  2061682894), -INT32_C(  1157337863),  INT32_C(   810765963) },
      { -INT32_C(   649141026),  INT32_C(   583395441),  INT32_C(   702024692), -INT32_C(   220246399),  INT32_C(  2128474800), -INT32_C(  1275543366), -INT32_C(  1200620244),  INT32_C(   703119947) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   583395441), -INT32_C(   220246399) } },
    { UINT8_C(166),
      {  INT32_C(   521601847), -INT32_C(   736937528),  INT32_C(  1616198674),  INT32_C(   235948059), -INT32_C(   439841243), -INT32_C(  2079163257), -INT32_C(  1378891029), -INT32_C(   380372558) },
      { -INT32_C(  1006015748), -INT32_C(  1248322397),  INT32_C(  1947659865),  INT32_C(  1535256118),  INT32_C(  1010912181), -INT32_C(  1296018489), -INT32_C(   815821027), -INT32_C(  2068204920) },
      { -INT32_C(  1085685220),  INT32_C(   930472414),  INT32_C(    95194063),  INT32_C(  1717644977),  INT32_C(  1084400249),  INT32_C(   317874933),  INT32_C(  2061586930),  INT32_C(   536844803) },
      {  INT32_C(           0),  INT32_C(   235948059),  INT32_C(   930472414),  INT32_C(           0),  INT32_C(           0), -INT32_C(   380372558),  INT32_C(           0), -INT32_C(  1085685220) } },
    { UINT8_C( 92),
      {  INT32_C(   691789640), -INT32_C(   537300396),  INT32_C(  1301347870),  INT32_C(    29816671), -INT32_C(    50985063),  INT32_C(  1273891065), -INT32_C(  2075236118), -INT32_C(  1344180633) },
      { -INT32_C(  1579606963), -INT32_C(  1384066418),  INT32_C(   821694672), -INT32_C(  1590575097), -INT32_C(  1046665017),  INT32_C(   437029680),  INT32_C(  1537170163),  INT32_C(   353009864) },
      {  INT32_C(   716628892), -INT32_C(  2032716107),  INT32_C(  1320603975),  INT32_C(  1508894610),  INT32_C(  1075481615),  INT32_C(   190457367),  INT32_C(  1231485313),  INT32_C(   358576249) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   691789640), -INT32_C(  1344180633), -INT32_C(  1344180633),  INT32_C(           0),  INT32_C(    29816671),  INT32_C(           0) } },
    { UINT8_C( 84),
      {  INT32_C(  1275674645), -INT32_C(   376205545),  INT32_C(   763093317),  INT32_C(  1564267729),  INT32_C(   360021231), -INT32_C(   795442985),  INT32_C(  1447747814),  INT32_C(  1420451647) },
      { -INT32_C(  1214204769), -INT32_C(  1985989821), -INT32_C(   424273131), -INT32_C(   565972241),  INT32_C(  1190443119),  INT32_C(   504793656), -INT32_C(  1451925398),  INT32_C(  1610489792) },
      {  INT32_C(   387358419), -INT32_C(   408897838), -INT32_C(  1043507503), -INT32_C(  1214312376),  INT32_C(    33395657), -INT32_C(  2011163618),  INT32_C(   875730292), -INT32_C(  2003554124) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   795442985),  INT32_C(           0), -INT32_C(  2003554124),  INT32_C(           0), -INT32_C(  1043507503),  INT32_C(           0) } },
    { UINT8_C(206),
      {  INT32_C(  1637916586), -INT32_C(  1791850689),  INT32_C(  1709044564),  INT32_C(   640587155), -INT32_C(  1505480814), -INT32_C(   467940017),  INT32_C(   798576639), -INT32_C(  1896013341) },
      { -INT32_C(     1073472),  INT32_C(  2056528165), -INT32_C(  1461751531), -INT32_C(  1714549498), -INT32_C(  1942023364), -INT32_C(   546284832), -INT32_C(  1928459862), -INT32_C(   367326422) },
      { -INT32_C(   806810967),  INT32_C(  1095335212), -INT32_C(   169269009),  INT32_C(  1905178421), -INT32_C(  1426207030), -INT32_C(   762745304), -INT32_C(  1570728073),  INT32_C(  1284275107) },
      {  INT32_C(           0), -INT32_C(   467940017), -INT32_C(   467940017),  INT32_C(   798576639),  INT32_C(           0),  INT32_C(           0), -INT32_C(   169269009), -INT32_C(   169269009) } },
    { UINT8_C(134),
      { -INT32_C(   206431370), -INT32_C(  1931283612), -INT32_C(  1816012580),  INT32_C(   878588774), -INT32_C(  1638070224),  INT32_C(   689319826),  INT32_C(   197965967), -INT32_C(  1164895932) },
      { -INT32_C(  1716632780),  INT32_C(   304451638), -INT32_C(   811210904),  INT32_C(  1241711386), -INT32_C(  1628872692),  INT32_C(   533200784), -INT32_C(    81095497), -INT32_C(   508118099) },
      {  INT32_C(   880436478),  INT32_C(  1564909812), -INT32_C(  1590891385), -INT32_C(    68472849),  INT32_C(   546952336), -INT32_C(  1975557677), -INT32_C(  1568249099),  INT32_C(   612580389) },
      {  INT32_C(           0),  INT32_C(   197965967),  INT32_C(   880436478),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1975557677) } },
    { UINT8_C(160),
      { -INT32_C(  1634445058), -INT32_C(  1960447585),  INT32_C(  1299891741), -INT32_C(  2032306511),  INT32_C(  1884945679), -INT32_C(  1503271876), -INT32_C(  1496578198), -INT32_C(  1991839605) },
      { -INT32_C(   416818616), -INT32_C(   378385204), -INT32_C(  1019810542),  INT32_C(  1917391715),  INT32_C(  1306764048), -INT32_C(   235714425), -INT32_C(   610812080), -INT32_C(   127607377) },
      { -INT32_C(  2082501705), -INT32_C(   378711337), -INT32_C(  1565744321), -INT32_C(   954927433),  INT32_C(   538245017), -INT32_C(  1877931968),  INT32_C(  2003544263),  INT32_C(  1013960581) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1991839605),  INT32_C(           0),  INT32_C(  1013960581) } },
    { UINT8_C( 90),
      { -INT32_C(  1607352242), -INT32_C(   790685139), -INT32_C(  1131970106), -INT32_C(  1923788906),  INT32_C(  1808627043),  INT32_C(   775118214), -INT32_C(  1749833016),  INT32_C(  1743908889) },
      { -INT32_C(   586669392),  INT32_C(    61728572), -INT32_C(     4246167), -INT32_C(   410249852),  INT32_C(   290675338), -INT32_C(  2143320393),  INT32_C(  1226306352), -INT32_C(  1817179677) },
      {  INT32_C(  1752217643),  INT32_C(   158014880), -INT32_C(   704107950), -INT32_C(   893479873), -INT32_C(  1495592466), -INT32_C(   953804137), -INT32_C(   267371251),  INT32_C(  1921237062) },
      {  INT32_C(           0), -INT32_C(  1495592466),  INT32_C(           0),  INT32_C(  1808627043), -INT32_C(   704107950),  INT32_C(           0), -INT32_C(  1607352242),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_permutex2var_epi32(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_permutex2var_epi32(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const int64_t idx[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 9105563135040303212),  INT64_C( 5126126908757411805),  INT64_C( 4131066676902922608), -INT64_C( 6896356776144442388) },
      { -INT64_C( 5036235093458267641),  INT64_C( 4883165139464366394),  INT64_C( 8034689480396833797),  INT64_C( 5551719280306818399) },
      {  INT64_C(  546344913464597502),  INT64_C( 8016486956781595946),  INT64_C( 3548333835470430028),  INT64_C( 5248284879331565123) },
      {  INT64_C( 5248284879331565123),  INT64_C( 4131066676902922608),  INT64_C( 8016486956781595946),  INT64_C( 5248284879331565123) } },
    { { -INT64_C( 1686676411120370494), -INT64_C( 5657042970237133659), -INT64_C( 5978318039748168700),  INT64_C( 1076091259815568477) },
      {  INT64_C( 8100910073168925383),  INT64_C( 8820297081538171218),  INT64_C(  308595150875125809),  INT64_C( 5717490736600743421) },
      {  INT64_C( 9144629603125753518), -INT64_C( 7673117386660812910),  INT64_C( 3040061883868566660),  INT64_C( 2724339638200491254) },
      {  INT64_C( 2724339638200491254), -INT64_C( 5978318039748168700), -INT64_C( 5657042970237133659), -INT64_C( 7673117386660812910) } },
    { {  INT64_C( 8389509990101983938), -INT64_C( 4330210769749826834), -INT64_C( 8706830746927556396),  INT64_C( 3357665980632637435) },
      { -INT64_C( 6139379650476034443),  INT64_C( 2103151654529222957),  INT64_C( 4041217868872687357),  INT64_C( 7242707316660444137) },
      {  INT64_C( 6332210790954475641), -INT64_C( 4667431523777782318), -INT64_C( 8392629836110211311), -INT64_C( 1238099066544442754) },
      { -INT64_C( 4667431523777782318), -INT64_C( 4667431523777782318), -INT64_C( 4667431523777782318), -INT64_C( 4330210769749826834) } },
    { { -INT64_C( 1763999190047486717),  INT64_C( 5576085515473733857), -INT64_C( 7872253578937847661),  INT64_C(  484928624621756502) },
      { -INT64_C( 4369977205674746275),  INT64_C( 3281374363985009921), -INT64_C( 6980823198101002887),  INT64_C( 5605614773420564418) },
      { -INT64_C( 5141111072500941310),  INT64_C( 5710140835441675640), -INT64_C( 8895739824324173661),  INT64_C( 2114180652148061722) },
      {  INT64_C( 5710140835441675640),  INT64_C( 5576085515473733857),  INT64_C( 5576085515473733857), -INT64_C( 7872253578937847661) } },
    { { -INT64_C( 6232232903019784429), -INT64_C( 7432071931316439370), -INT64_C( 3611587063637035110),  INT64_C( 5925943533358230022) },
      { -INT64_C( 7052462295194255547),  INT64_C( 8043717921512086292),  INT64_C( 4269038842336191934), -INT64_C( 8473354181185628457) },
      {  INT64_C( 3917886633969550552),  INT64_C( 5639035121051863805), -INT64_C( 8036674938494579706),  INT64_C( 5035603191860220692) },
      {  INT64_C( 5639035121051863805),  INT64_C( 3917886633969550552), -INT64_C( 8036674938494579706),  INT64_C( 5035603191860220692) } },
    { {  INT64_C(  210090308284048274),  INT64_C( 1210647009670998766), -INT64_C( 6959535268717359839), -INT64_C( 5744382977254158186) },
      { -INT64_C( 6862272307316634179), -INT64_C( 3488903581331908487),  INT64_C( 4153185971756195961),  INT64_C( 3671422660899478308) },
      {  INT64_C( 2315335812536162512), -INT64_C( 6427138947509174190), -INT64_C( 5696122737359357929), -INT64_C( 9038188223872684055) },
      { -INT64_C( 6427138947509174190),  INT64_C( 1210647009670998766),  INT64_C( 1210647009670998766),  INT64_C( 2315335812536162512) } },
    { { -INT64_C( 7996663131977578945), -INT64_C(  560311256199616155),  INT64_C( 2023424867947504855),  INT64_C( 3245138125600196565) },
      { -INT64_C( 7538435120218042991),  INT64_C( 3070438256847549379), -INT64_C( 3776933532995268793), -INT64_C( 5925228461146566487) },
      { -INT64_C( 5389716996436862615),  INT64_C(  527473936533380564),  INT64_C( 3100471612772769605),  INT64_C( 2372984370039577126) },
      { -INT64_C(  560311256199616155),  INT64_C( 3245138125600196565),  INT64_C( 2372984370039577126), -INT64_C(  560311256199616155) } },
    { {  INT64_C( 2380695893943479393), -INT64_C( 7056409058415713461), -INT64_C( 3520159413545823367), -INT64_C( 3309583386299799493) },
      {  INT64_C(  565536811018276203),  INT64_C( 3785879925808046483), -INT64_C( 9209768581012757320), -INT64_C( 6088722386688786372) },
      {  INT64_C( 7571463388080088656),  INT64_C(  166035370139788638),  INT64_C(  867668402106498116),  INT64_C( 5818151540614659284) },
      { -INT64_C( 3309583386299799493), -INT64_C( 3309583386299799493),  INT64_C( 2380695893943479393),  INT64_C( 7571463388080088656) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_permutex2var_epi64(a, idx, b);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_permutex2var_epi64(a, idx, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const simde__mmask8 k;
    const int64_t idx[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 4818729144397585696), -INT64_C( 7286221291590814059), -INT64_C( 5945543322123352672),  INT64_C( 5907736937392781227) },
      UINT8_C(161),
      { -INT64_C( 6963201461698164648),  INT64_C( 7230968038851689620),  INT64_C( 9119483889947888308), -INT64_C( 8157637173652276566) },
      {  INT64_C( 2022595106281278025),  INT64_C( 5292344829359228656),  INT64_C( 4953602907035185145),  INT64_C( 3943245540026592757) },
      { -INT64_C( 4818729144397585696), -INT64_C( 7286221291590814059), -INT64_C( 5945543322123352672),  INT64_C( 5907736937392781227) } },
    { { -INT64_C( 5501224170313740286), -INT64_C( 6584767694686225217),  INT64_C( 8917587435691756516),  INT64_C( 7598521893324730191) },
      UINT8_C(111),
      {  INT64_C( 1699517991373501468),  INT64_C( 6035218813186992808),  INT64_C( 3404250731322621516),  INT64_C(  777433809885232122) },
      { -INT64_C( 8383884036088464141),  INT64_C( 2034265633900226911),  INT64_C( 7176285248304125032),  INT64_C( 2359190405859061188) },
      { -INT64_C( 8383884036088464141), -INT64_C( 5501224170313740286), -INT64_C( 8383884036088464141),  INT64_C( 8917587435691756516) } },
    { {  INT64_C( 8210717508658699651), -INT64_C( 1393138937184625987), -INT64_C( 4434660256608111192),  INT64_C( 4351658911245611544) },
      UINT8_C(207),
      { -INT64_C( 1214473722860035309),  INT64_C( 1433938385448448938), -INT64_C( 7082239805314959437),  INT64_C( 8235556906900847433) },
      {  INT64_C( 2862881428903439158),  INT64_C( 4693396830894239410),  INT64_C( 5857940704363230274),  INT64_C( 7738053005681664657) },
      {  INT64_C( 4351658911245611544), -INT64_C( 4434660256608111192),  INT64_C( 4351658911245611544), -INT64_C( 1393138937184625987) } },
    { { -INT64_C( 1232314779336032959), -INT64_C( 2743500766479299810), -INT64_C(  887822231621088172), -INT64_C( 3453056331930109580) },
      UINT8_C(132),
      { -INT64_C( 4730558123629048246), -INT64_C( 4674966267858975317), -INT64_C( 6774516475662074955),  INT64_C(  343400271527847417) },
      { -INT64_C( 2467804155733900146), -INT64_C(  553722561634429538),  INT64_C( 9155392009278615876), -INT64_C( 3611742590858215903) },
      { -INT64_C( 1232314779336032959), -INT64_C( 2743500766479299810), -INT64_C(  553722561634429538), -INT64_C( 3453056331930109580) } },
    { {  INT64_C( 6275643726682332935), -INT64_C( 3683600859521302363), -INT64_C(   22720457791151703), -INT64_C(  391044665780310139) },
      UINT8_C(218),
      {  INT64_C(  763335169952330593), -INT64_C( 4345024345105268527),  INT64_C(  100662019851608984),  INT64_C( 2093873364588571002) },
      {  INT64_C( 6662694712678195489),  INT64_C(   92913583836694821),  INT64_C(  328558858737937147), -INT64_C( 7833933000428977297) },
      {  INT64_C( 6275643726682332935), -INT64_C( 3683600859521302363), -INT64_C(   22720457791151703), -INT64_C(   22720457791151703) } },
    { {  INT64_C( 2436014175575561960),  INT64_C( 5253996852439168127), -INT64_C( 9193143093210723619), -INT64_C( 3247671568395164695) },
      UINT8_C( 73),
      {  INT64_C( 5179534379403527660),  INT64_C( 9070210831653062927),  INT64_C( 6052852953441453746),  INT64_C( 3888032857112665016) },
      { -INT64_C( 5642596223445157290), -INT64_C( 3210905859794975423), -INT64_C( 4260991237631508776), -INT64_C( 8879862414130078650) },
      { -INT64_C( 5642596223445157290),  INT64_C( 5253996852439168127), -INT64_C( 9193143093210723619),  INT64_C( 2436014175575561960) } },
    { {  INT64_C( 1509164179333733279),  INT64_C( 1070300034895422693), -INT64_C(  628967167704447626), -INT64_C( 5168924997866572399) },
      UINT8_C(165),
      { -INT64_C( 8090561790389716686),  INT64_C( 6882296934384910228), -INT64_C(  112019026857688213), -INT64_C( 6305373223716966002) },
      {  INT64_C( 1675957552568530633),  INT64_C( 5182136687888894193), -INT64_C( 8075066273720370520), -INT64_C( 6851691545877805109) },
      { -INT64_C(  628967167704447626),  INT64_C( 1070300034895422693), -INT64_C( 5168924997866572399), -INT64_C( 5168924997866572399) } },
    { { -INT64_C( 8685589258748861476), -INT64_C( 1746837835176830562),  INT64_C( 5730769519993481718), -INT64_C( 5600655128059121713) },
      UINT8_C(220),
      {  INT64_C( 2435878436295807385), -INT64_C(  936952093332191476),  INT64_C( 7977780943068264223),  INT64_C( 4371577567422209109) },
      {  INT64_C( 2571899635558456583),  INT64_C( 8609805346395656576),  INT64_C(  869500081506611747),  INT64_C( 5931386167254209906) },
      { -INT64_C( 8685589258748861476), -INT64_C( 1746837835176830562),  INT64_C( 5931386167254209906),  INT64_C( 8609805346395656576) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_permutex2var_epi64(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_permutex2var_epi64(a, k, idx, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask2_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const int64_t idx[4];
    const simde__mmask8 k;
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 8492825680892050593),  INT64_C( 6373573365172471972),  INT64_C( 6498707353976361581),  INT64_C( 3530469777387424352) },
      {  INT64_C( 1721998432633675899), -INT64_C( 3721795874446908211), -INT64_C( 4568021803536984999),  INT64_C( 4893558780939929898) },
      UINT8_C( 73),
      {  INT64_C( 9035297934047753169),  INT64_C( 1352955373423518950), -INT64_C( 6060383148574701670),  INT64_C( 6363788064031284893) },
      {  INT64_C( 3530469777387424352), -INT64_C( 3721795874446908211), -INT64_C( 4568021803536984999),  INT64_C( 6498707353976361581) } },
    { { -INT64_C( 4142940159606911893), -INT64_C( 6735422377981419850), -INT64_C( 4157313758942923008), -INT64_C( 1963819604768931105) },
      { -INT64_C( 5345936589050041047), -INT64_C(  183891134409800760), -INT64_C( 1110721076618342490), -INT64_C( 6409443063074757969) },
      UINT8_C(195),
      { -INT64_C( 8995808862409674506),  INT64_C( 4248438623831062944), -INT64_C( 4847778265998572260), -INT64_C( 1915469172561943919) },
      { -INT64_C( 6735422377981419850), -INT64_C( 4142940159606911893), -INT64_C( 1110721076618342490), -INT64_C( 6409443063074757969) } },
    { {  INT64_C( 4870201693729795219), -INT64_C( 5904914471745088153),  INT64_C( 2622063187536074828),  INT64_C( 1452188234137968210) },
      {  INT64_C( 4775994678214880609), -INT64_C( 5975677053392594478), -INT64_C( 8272628481048393095), -INT64_C( 7787860432377611178) },
      UINT8_C( 99),
      { -INT64_C( 5070348531722708974), -INT64_C( 2075940514974529899),  INT64_C( 7650114305729051676),  INT64_C(   59443916928975481) },
      { -INT64_C( 5904914471745088153),  INT64_C( 2622063187536074828), -INT64_C( 8272628481048393095), -INT64_C( 7787860432377611178) } },
    { {  INT64_C( 2837392639937942215),  INT64_C( 6734023017608673912), -INT64_C( 5394647987778383542), -INT64_C( 5382934132027965858) },
      {  INT64_C(  343888258685213451), -INT64_C(  300323142330113226), -INT64_C( 4572044901185550693), -INT64_C( 5316965915948174701) },
      UINT8_C(114),
      { -INT64_C( 4934815888751766638), -INT64_C( 2937076136688157799),  INT64_C( 6018210575517553691), -INT64_C( 3616192333705509626) },
      {  INT64_C(  343888258685213451),  INT64_C( 6018210575517553691), -INT64_C( 4572044901185550693), -INT64_C( 5316965915948174701) } },
    { {  INT64_C( 7771981306788564743), -INT64_C( 3800391914464851813),  INT64_C( 8958857533837835360),  INT64_C(  959171091083383366) },
      { -INT64_C( 6506002671874512008),  INT64_C( 8127962755699426385),  INT64_C( 1207463647651137999), -INT64_C( 4815788069337523433) },
      UINT8_C( 77),
      { -INT64_C( 8956817714767787944),  INT64_C(  590256871795045134), -INT64_C( 3219823902942136716), -INT64_C( 1178583455997923979) },
      {  INT64_C( 7771981306788564743),  INT64_C( 8127962755699426385), -INT64_C( 1178583455997923979), -INT64_C( 1178583455997923979) } },
    { {  INT64_C(  512850678642703580),  INT64_C( 2899642734365684149),  INT64_C( 7501785262765182992), -INT64_C( 2043116871665831394) },
      { -INT64_C( 5953586116916480672),  INT64_C( 8226141799679445325),  INT64_C( 6452485341117581872),  INT64_C( 1221237117230729992) },
      UINT8_C(169),
      { -INT64_C( 7828575798022804879),  INT64_C( 1189346702712527921),  INT64_C( 8863265696407921699),  INT64_C( 8291755844977758132) },
      {  INT64_C(  512850678642703580),  INT64_C( 8226141799679445325),  INT64_C( 6452485341117581872),  INT64_C(  512850678642703580) } },
    { {  INT64_C( 3748361593402995622), -INT64_C( 8805092100778100168),  INT64_C( 8383308598154762923),  INT64_C( 7206867430476186254) },
      { -INT64_C( 7504728299208866910),  INT64_C( 1277653836883123923),  INT64_C( 5004136593497012542), -INT64_C( 2167963982574039098) },
      UINT8_C( 92),
      { -INT64_C( 4797931882488822082), -INT64_C( 7851968385777426521), -INT64_C( 4023244466054035936),  INT64_C( 6168498375915712102) },
      { -INT64_C( 7504728299208866910),  INT64_C( 1277653836883123923), -INT64_C( 4023244466054035936), -INT64_C( 4023244466054035936) } },
    { {  INT64_C( 5659431160458794350),  INT64_C(  208328734361103862),  INT64_C( 2695845004678934312), -INT64_C( 4166957372693778370) },
      {  INT64_C( 7226622014085339220), -INT64_C( 6003410983132503093), -INT64_C( 2040773134561503800),  INT64_C( 7153656912871493927) },
      UINT8_C(253),
      {  INT64_C(  919808177349550042),  INT64_C( 3811801338481766533),  INT64_C( 3128239336657087882),  INT64_C(  673462070523193718) },
      {  INT64_C(  919808177349550042), -INT64_C( 6003410983132503093),  INT64_C( 5659431160458794350),  INT64_C(  673462070523193718) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask2_permutex2var_epi64(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask2_permutex2var_epi64(a, idx, k, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t idx[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(253),
      {  INT64_C( 3826285920100155844), -INT64_C( 8499830586908264637), -INT64_C( 7019193492854977437),  INT64_C( 1056049353334845963) },
      {  INT64_C( 4887455631946174168),  INT64_C( 1484726287040981234),  INT64_C( 1976459080246771482), -INT64_C( 1578955798946170179) },
      {  INT64_C( 7421468693362096314), -INT64_C( 6176668677397101950),  INT64_C(  394599640868683087),  INT64_C( 7285736415853035040) },
      {  INT64_C( 3826285920100155844),  INT64_C(                   0), -INT64_C( 7019193492854977437), -INT64_C( 6176668677397101950) } },
    { UINT8_C(219),
      { -INT64_C( 2197557469141589853),  INT64_C( 8829900793851261995), -INT64_C( 6801905061409396332), -INT64_C( 8299657024144356141) },
      {  INT64_C(  131179253143838930), -INT64_C(  993387458089696321), -INT64_C( 7875943905623213904), -INT64_C( 8987115911504134189) },
      { -INT64_C( 7255221087654063751),  INT64_C(  277408243563072649),  INT64_C( 2222184791255958917),  INT64_C( 3674129947223023561) },
      { -INT64_C( 6801905061409396332),  INT64_C( 3674129947223023561),  INT64_C(                   0), -INT64_C( 8299657024144356141) } },
    { UINT8_C(243),
      {  INT64_C( 6719488093001318769),  INT64_C( 5031563122116208577),  INT64_C( 5502747754651195338),  INT64_C( 5016226946485704585) },
      { -INT64_C( 7501241237203293000),  INT64_C( 1632757503154820963),  INT64_C( 8072992498939214031), -INT64_C(  146445853385879842) },
      { -INT64_C( 7884838469744790747),  INT64_C(   29164757738420228), -INT64_C(  635351584041266730),  INT64_C( 2745120999013501397) },
      {  INT64_C( 6719488093001318769),  INT64_C( 5016226946485704585),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(149),
      {  INT64_C( 3247191766449005215), -INT64_C( 2756097655420591796), -INT64_C(  812360233779036900), -INT64_C( 8373848756298787692) },
      {  INT64_C( 3612354086010588990), -INT64_C(  312194374599672055),  INT64_C( 2016090389376572762),  INT64_C( 5468244112393171051) },
      {  INT64_C( 3225244889499204522),  INT64_C( 1565185295299502047), -INT64_C( 7285112056504936636), -INT64_C(  262100129829210363) },
      { -INT64_C( 7285112056504936636),  INT64_C(                   0), -INT64_C(  812360233779036900),  INT64_C(                   0) } },
    { UINT8_C( 80),
      {  INT64_C( 3303846963211111579), -INT64_C( 1834937231741446244),  INT64_C( 8157056014514213913),  INT64_C( 4379679862844245409) },
      {  INT64_C( 8558828147917142603), -INT64_C( 3972944873216364377),  INT64_C( 4774706904443646615),  INT64_C( 1246794260040713839) },
      {  INT64_C( 4326678953301083322), -INT64_C( 6945939270704839389),  INT64_C( 3235753579611525635), -INT64_C( 2624883760608468806) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 15),
      {  INT64_C( 4671605531044245309), -INT64_C( 3231077366142294508),  INT64_C( 6181116499391991129),  INT64_C( 1698510008422385913) },
      {  INT64_C( 3133269589367469760),  INT64_C(  312851377180164930), -INT64_C( 7183002107340789946), -INT64_C( 2877041395869104607) },
      { -INT64_C( 5103829115235738903),  INT64_C( 4107728110785231697),  INT64_C(  989813267296949116),  INT64_C( 8591489912988556363) },
      {  INT64_C( 4671605531044245309),  INT64_C( 6181116499391991129),  INT64_C(  989813267296949116), -INT64_C( 3231077366142294508) } },
    { UINT8_C(245),
      {  INT64_C( 2102376882953221966),  INT64_C( 4571798128701811297),  INT64_C( 2976659782148788607),  INT64_C( 4273687267873698368) },
      {  INT64_C( 4712812360372829095),  INT64_C( 4745291810681092207),  INT64_C( 9057184417130546490),  INT64_C( 4643254754805836103) },
      {  INT64_C( 4324564833728563426),  INT64_C( 2120266213347572328), -INT64_C( 8182100131426487624),  INT64_C( 6168018830397492160) },
      {  INT64_C( 6168018830397492160),  INT64_C(                   0),  INT64_C( 2976659782148788607),  INT64_C(                   0) } },
    { UINT8_C(188),
      {  INT64_C( 6087957512085640995), -INT64_C( 4249053806497126499), -INT64_C( 4967018007314498054),  INT64_C( 2832345271318244190) },
      {  INT64_C( 4181794141975074714), -INT64_C( 8270981028679893154),  INT64_C( 4448695368223179664),  INT64_C(  542435735229164123) },
      { -INT64_C( 2896444058409123083),  INT64_C( 8801018742315702018),  INT64_C( 5538925003136434627), -INT64_C( 4497913174193033696) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 6087957512085640995),  INT64_C( 2832345271318244190) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_permutex2var_epi64(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_permutex2var_epi64(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t idx[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  52),  INT8_C(  20),  INT8_C(  74),  INT8_C( 119),  INT8_C( 101),  INT8_C(  73),  INT8_C(  52),  INT8_C(  74),
         INT8_C(  78),  INT8_C(  78), -INT8_C(  28), -INT8_C(  65), -INT8_C( 125), -INT8_C(   4),  INT8_C(  43),  INT8_C(  80),
         INT8_C(  68), -INT8_C(  17), -INT8_C(  46),  INT8_C(  34), -INT8_C(  97),  INT8_C(  38), -INT8_C(  48), -INT8_C( 123),
        -INT8_C(  88),  INT8_C(  83),  INT8_C( 108),  INT8_C(  60),  INT8_C(  79), -INT8_C( 125), -INT8_C(  93), -INT8_C( 125) },
      { -INT8_C( 105), -INT8_C(  19), -INT8_C(   6), -INT8_C(   3),  INT8_C(  55),  INT8_C(  46),  INT8_C(  71), -INT8_C( 123),
         INT8_C( 124),  INT8_C(  44),  INT8_C(  68),  INT8_C(   0),  INT8_C(  40),  INT8_C( 111),  INT8_C(  80),  INT8_C( 108),
         INT8_C(  94),  INT8_C(  34), -INT8_C( 114), -INT8_C(   2),  INT8_C(  72),  INT8_C(  94), -INT8_C( 125), -INT8_C(  16),
        -INT8_C(  79), -INT8_C(  17),  INT8_C(  44),  INT8_C(   0),  INT8_C( 115), -INT8_C(  48), -INT8_C( 125),  INT8_C(  10) },
      { -INT8_C(  67),  INT8_C( 126),  INT8_C(   7), -INT8_C(  12), -INT8_C(  84),  INT8_C(  79),  INT8_C( 121),  INT8_C(  41),
         INT8_C( 123), -INT8_C(  66),  INT8_C(  41), -INT8_C(  93),  INT8_C(  45),  INT8_C( 121),  INT8_C(  15), -INT8_C( 116),
        -INT8_C( 101), -INT8_C(  98), -INT8_C( 118), -INT8_C(  29), -INT8_C(   4),  INT8_C(  13), -INT8_C(  45), -INT8_C(  82),
        -INT8_C(   3), -INT8_C(   1), -INT8_C(  82),  INT8_C( 112), -INT8_C(  49),  INT8_C(  50),  INT8_C( 122), -INT8_C( 115) },
      { -INT8_C( 123),  INT8_C( 121), -INT8_C(  82),  INT8_C(  50), -INT8_C(  82),  INT8_C(  15),  INT8_C(  74),  INT8_C(  73),
        -INT8_C(  49),  INT8_C(  45),  INT8_C( 101),  INT8_C(  52),  INT8_C( 123), -INT8_C( 116),  INT8_C(  68),  INT8_C(  45),
        -INT8_C(  93),  INT8_C(   7),  INT8_C(  43),  INT8_C( 122),  INT8_C(  78), -INT8_C(  93),  INT8_C( 119), -INT8_C( 101),
        -INT8_C(  98), -INT8_C( 116),  INT8_C(  45),  INT8_C(  52), -INT8_C(  29),  INT8_C(  68),  INT8_C( 119), -INT8_C(  28) } },
    { { -INT8_C(  80), -INT8_C( 126), -INT8_C( 127),  INT8_C(  92), -INT8_C(  47), -INT8_C(   5), -INT8_C( 123),  INT8_C(  76),
        -INT8_C(  71), -INT8_C(  82), -INT8_C(  17), -INT8_C(  26),  INT8_C(  39), -INT8_C(   2),  INT8_C( 114), -INT8_C(  62),
        -INT8_C( 100), -INT8_C(   4), -INT8_C(  91), -INT8_C( 103),  INT8_C(  10),  INT8_C( 120),  INT8_C(  71),  INT8_C(   7),
         INT8_C( 120), -INT8_C(  11),  INT8_C( 119),  INT8_C(  71),  INT8_C(  39), -INT8_C(  15), -INT8_C(  44), -INT8_C(  41) },
      {  INT8_C( 115),  INT8_C(  86),  INT8_C(  52),  INT8_C(  68),  INT8_C(  81), -INT8_C(  71), -INT8_C( 112),  INT8_C(  10),
         INT8_C( 104),      INT8_MAX, -INT8_C(  16), -INT8_C( 113),  INT8_C( 126),  INT8_C(  99),  INT8_C(  82),  INT8_C(  26),
         INT8_C(  95), -INT8_C(   9), -INT8_C(  77),  INT8_C( 105),  INT8_C( 112), -INT8_C(   6),  INT8_C( 112), -INT8_C(  24),
        -INT8_C(  16), -INT8_C(  25),  INT8_C(  47),  INT8_C(  23), -INT8_C(  39),  INT8_C(   4), -INT8_C(  17),  INT8_C(  76) },
      {  INT8_C(  90),  INT8_C(  35), -INT8_C( 111), -INT8_C(  85), -INT8_C(  36),  INT8_C(  33), -INT8_C(  75),  INT8_C(  68),
        -INT8_C(  95), -INT8_C(  91), -INT8_C(  44),  INT8_C(  31),  INT8_C(   8),  INT8_C(  38),  INT8_C(  57),  INT8_C( 104),
         INT8_C(  29), -INT8_C(  19), -INT8_C(  47), -INT8_C( 115), -INT8_C(  25),  INT8_C(  66),  INT8_C( 117), -INT8_C(  41),
         INT8_C(  41), -INT8_C(  91), -INT8_C(  17),  INT8_C(   2), -INT8_C(  87), -INT8_C(  34),  INT8_C(  79),  INT8_C(   3) },
      { -INT8_C( 115),  INT8_C(  71), -INT8_C(  25), -INT8_C(  47), -INT8_C(   4), -INT8_C(  91), -INT8_C( 100), -INT8_C(  17),
        -INT8_C(  95),  INT8_C(   3),  INT8_C(  29), -INT8_C(  62),  INT8_C(  79), -INT8_C(  85), -INT8_C(  91),  INT8_C( 119),
        -INT8_C(  41), -INT8_C(  41), -INT8_C( 115), -INT8_C(  91),  INT8_C(  29), -INT8_C(  17),  INT8_C(  29), -INT8_C(  95),
         INT8_C(  29),  INT8_C(  68),  INT8_C( 104),  INT8_C(   7), -INT8_C(  11), -INT8_C(  47),  INT8_C( 104),  INT8_C(  39) } },
    { {  INT8_C(   1), -INT8_C(  32), -INT8_C(  82), -INT8_C(  35),  INT8_C(   1),  INT8_C(  99),  INT8_C(  34), -INT8_C(  94),
         INT8_C(   8), -INT8_C(  10), -INT8_C(  63),  INT8_C(  17),  INT8_C(  28), -INT8_C(   5),  INT8_C( 121),  INT8_C(  57),
        -INT8_C(  24),  INT8_C(  74), -INT8_C(  57), -INT8_C(  49), -INT8_C( 116),  INT8_C(  60), -INT8_C(  89), -INT8_C(  74),
        -INT8_C(  31), -INT8_C( 106), -INT8_C(  72), -INT8_C( 118),  INT8_C( 116),  INT8_C(   7), -INT8_C( 115),  INT8_C( 117) },
      { -INT8_C(  25),  INT8_C(  59),  INT8_C(  82), -INT8_C(  23), -INT8_C(  98),  INT8_C( 116), -INT8_C( 117), -INT8_C(  89),
         INT8_C( 106),  INT8_C(  77), -INT8_C(  72), -INT8_C( 122),  INT8_C(  72),  INT8_C(  49), -INT8_C(  64),  INT8_C(  48),
         INT8_C( 123), -INT8_C( 121), -INT8_C(   1),  INT8_C(   8), -INT8_C(  61), -INT8_C(  90), -INT8_C(  66), -INT8_C(  91),
         INT8_C(  60),  INT8_C( 118),  INT8_C(  47), -INT8_C(  80),  INT8_C( 126), -INT8_C(  67),  INT8_C(  37),  INT8_C( 101) },
      { -INT8_C(   8),  INT8_C( 120),  INT8_C(  78), -INT8_C( 105), -INT8_C(  20), -INT8_C(  38),  INT8_C(  62),  INT8_C(  87),
         INT8_C(  39), -INT8_C(  10), -INT8_C(  35),  INT8_C( 111),  INT8_C(  39), -INT8_C(  99), -INT8_C(  97), -INT8_C(  94),
         INT8_C(  36), -INT8_C(  98), -INT8_C(  86), -INT8_C(  24),  INT8_C(  69),  INT8_C( 104), -INT8_C( 115), -INT8_C( 127),
        -INT8_C(  33), -INT8_C(  68),  INT8_C(  50),  INT8_C(  93),  INT8_C( 121),  INT8_C(  87), -INT8_C(  62),  INT8_C( 114) },
      {  INT8_C(  87),  INT8_C(  93), -INT8_C(  57), -INT8_C(  10), -INT8_C( 115),  INT8_C(  69),  INT8_C(  17),  INT8_C(  87),
        -INT8_C(  35), -INT8_C(   5), -INT8_C(  33),  INT8_C(  34),  INT8_C(   8), -INT8_C(  98),  INT8_C(   1),  INT8_C(  36),
         INT8_C(  93), -INT8_C(  94),  INT8_C( 114),  INT8_C(   8), -INT8_C(  35),  INT8_C(  62), -INT8_C(  62), -INT8_C(  38),
         INT8_C( 121), -INT8_C( 115), -INT8_C(  94),  INT8_C(  36), -INT8_C(  62),  INT8_C(  87), -INT8_C(  38), -INT8_C(  38) } },
    { { -INT8_C(  49),  INT8_C(  17),  INT8_C(   9), -INT8_C(  68), -INT8_C(  21),  INT8_C(  71),  INT8_C(  19),  INT8_C(  18),
         INT8_C(  61), -INT8_C(  16), -INT8_C( 127),  INT8_C( 100), -INT8_C( 114),  INT8_C(  32),  INT8_C(   6), -INT8_C(  78),
        -INT8_C(  66), -INT8_C(  79), -INT8_C( 102),  INT8_C(   3),  INT8_C(  25),  INT8_C(  39), -INT8_C( 123), -INT8_C(   8),
        -INT8_C(  28), -INT8_C(  73),  INT8_C(  85),  INT8_C(  93),  INT8_C(  14),  INT8_C(  24), -INT8_C(  49), -INT8_C(  34) },
      {  INT8_C(  41), -INT8_C(  40), -INT8_C( 102),  INT8_C(  20),  INT8_C(  31), -INT8_C(  83),  INT8_C(  38),  INT8_C(  92),
        -INT8_C(  99), -INT8_C(  89), -INT8_C(  64),  INT8_C(  43), -INT8_C(  57), -INT8_C(  57), -INT8_C(  34), -INT8_C( 123),
         INT8_C( 120),  INT8_C( 120), -INT8_C( 119), -INT8_C( 111), -INT8_C(  96),  INT8_C(  14), -INT8_C( 118), -INT8_C( 124),
        -INT8_C(  59), -INT8_C(  33), -INT8_C(  31), -INT8_C(  45), -INT8_C(   9), -INT8_C(  79), -INT8_C(  79),  INT8_C(  32) },
      { -INT8_C( 119),  INT8_C(  75),  INT8_C(  52), -INT8_C(  87), -INT8_C(   8),  INT8_C(  90),  INT8_C(   5), -INT8_C( 106),
         INT8_C(   1), -INT8_C(  58), -INT8_C(  63), -INT8_C(  56), -INT8_C( 115), -INT8_C(  97),  INT8_C(  78),  INT8_C(   5),
         INT8_C(  24), -INT8_C(  41), -INT8_C( 106), -INT8_C(  72), -INT8_C(  27),  INT8_C(  32),  INT8_C(  60), -INT8_C(  86),
         INT8_C(   0),  INT8_C(  29),  INT8_C( 125), -INT8_C(   9), -INT8_C(  50),  INT8_C(  47),  INT8_C(  24),  INT8_C(  88) },
      { -INT8_C(  58), -INT8_C(  28),  INT8_C(  85),  INT8_C(  25), -INT8_C(  34), -INT8_C(  97),  INT8_C(   5),  INT8_C(  14),
         INT8_C(  24), -INT8_C( 106), -INT8_C(  49), -INT8_C(  56),  INT8_C(  18),  INT8_C(  18), -INT8_C(  49),  INT8_C(  71),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  16), -INT8_C(  79), -INT8_C( 119),  INT8_C(   6), -INT8_C( 127), -INT8_C(  21),
         INT8_C(  71), -INT8_C(  34),  INT8_C(  75),  INT8_C(   3), -INT8_C(  86), -INT8_C(  41), -INT8_C(  41), -INT8_C( 119) } },
    { {  INT8_C( 122),  INT8_C(  76),  INT8_C(   1),  INT8_C( 115), -INT8_C(  89),  INT8_C(   6),  INT8_C(   9), -INT8_C(  88),
        -INT8_C(  52), -INT8_C(  54),  INT8_C( 113),  INT8_C(  89),  INT8_C( 106), -INT8_C(  65),  INT8_C(  94), -INT8_C( 126),
        -INT8_C( 106), -INT8_C(  11),  INT8_C(  58),  INT8_C( 123),  INT8_C(  21),  INT8_C( 118),  INT8_C(  37),  INT8_C(  21),
        -INT8_C( 109), -INT8_C(  94),  INT8_C(  13),  INT8_C(  98), -INT8_C(  47),  INT8_C(  37), -INT8_C(  70),  INT8_C(  76) },
      {  INT8_C( 113), -INT8_C(  69), -INT8_C(  65),  INT8_C(  24), -INT8_C(  63), -INT8_C(  56), -INT8_C(  63), -INT8_C( 114),
        -INT8_C( 110),  INT8_C(  50), -INT8_C(  25), -INT8_C(   4), -INT8_C(  15),  INT8_C(  70),  INT8_C( 126), -INT8_C( 121),
         INT8_C(  59), -INT8_C(  72),  INT8_C(   2),  INT8_C(  80),  INT8_C(  46),  INT8_C(  39),  INT8_C( 102), -INT8_C(  62),
        -INT8_C(  55),  INT8_C( 115),  INT8_C(  36), -INT8_C( 101), -INT8_C( 104), -INT8_C(  34), -INT8_C(  25),  INT8_C(   9) },
      { -INT8_C( 103), -INT8_C(  90),  INT8_C(  34),  INT8_C(  90),  INT8_C( 110), -INT8_C(  29), -INT8_C(  24),  INT8_C(   0),
         INT8_C(  21), -INT8_C(  48), -INT8_C(   3),  INT8_C(   6),  INT8_C(  22),  INT8_C( 123), -INT8_C( 115),  INT8_C(  81),
         INT8_C(  52), -INT8_C( 113), -INT8_C(  95),  INT8_C(  98), -INT8_C(  74),  INT8_C(   7),  INT8_C(  36),      INT8_MAX,
         INT8_C( 122),  INT8_C(  72),  INT8_C(  26),  INT8_C(  18),  INT8_C(  38),  INT8_C(   1),  INT8_C(  28), -INT8_C(  65) },
      { -INT8_C( 113),  INT8_C(  18), -INT8_C(  65), -INT8_C( 109),  INT8_C(  76), -INT8_C(  52),  INT8_C(  76),  INT8_C(  94),
         INT8_C(  58), -INT8_C(  95),  INT8_C(   0),  INT8_C(  38), -INT8_C( 113),  INT8_C(   9),  INT8_C(  28), -INT8_C(  88),
         INT8_C(  18),  INT8_C( 122),  INT8_C(   1), -INT8_C( 106), -INT8_C( 115),  INT8_C(   0), -INT8_C(  24),  INT8_C(   1),
        -INT8_C(  54),  INT8_C(  98),  INT8_C( 110),  INT8_C(  98), -INT8_C( 109), -INT8_C(  70),  INT8_C(   0), -INT8_C(  54) } },
    { { -INT8_C(  89),  INT8_C(  62),  INT8_C(  26),  INT8_C(  21),  INT8_C(  33),  INT8_C(   2),  INT8_C(  22),  INT8_C(  54),
        -INT8_C(  46),  INT8_C(  19),  INT8_C(  60), -INT8_C(  24), -INT8_C( 114), -INT8_C(  55),  INT8_C(  57), -INT8_C(  62),
         INT8_C(  88), -INT8_C(  37),  INT8_C(  37),  INT8_C(  14), -INT8_C(  30),  INT8_C(  73), -INT8_C( 115),  INT8_C(  93),
        -INT8_C( 110), -INT8_C(  88),  INT8_C( 111), -INT8_C(  72), -INT8_C(  87), -INT8_C( 117),  INT8_C( 120),  INT8_C(  81) },
      { -INT8_C(  55), -INT8_C( 110),  INT8_C( 102), -INT8_C(  22), -INT8_C( 108),  INT8_C( 124),  INT8_C(  32),  INT8_C( 103),
        -INT8_C( 113),  INT8_C(  92),  INT8_C(  79),  INT8_C(  30),  INT8_C(  37), -INT8_C( 119), -INT8_C(  32),  INT8_C( 125),
         INT8_C( 100),  INT8_C(   5), -INT8_C( 117),  INT8_C(  70),  INT8_C(  79),  INT8_C(  25), -INT8_C(  93), -INT8_C(  31),
        -INT8_C(  63),  INT8_C(  19), -INT8_C( 103),  INT8_C( 106), -INT8_C(  98),  INT8_C(  17), -INT8_C(  69),  INT8_C( 104) },
      { -INT8_C(  93),  INT8_C(  34),  INT8_C(  82),  INT8_C(  56), -INT8_C(  98),  INT8_C( 115), -INT8_C(  97),  INT8_C(  46),
        -INT8_C(  49), -INT8_C(  18),  INT8_C(  76), -INT8_C(  11),  INT8_C( 119),  INT8_C(  44),  INT8_C( 114), -INT8_C(  37),
         INT8_C(  50), -INT8_C(   2),  INT8_C(  34), -INT8_C( 127),  INT8_C(  23), -INT8_C(  59),  INT8_C(  98), -INT8_C(  40),
        -INT8_C(  40), -INT8_C(   5),  INT8_C(  66),  INT8_C( 119),  INT8_C(  13), -INT8_C(   2), -INT8_C(  33), -INT8_C(  80) },
      {  INT8_C(  19),  INT8_C(  37), -INT8_C(  97),  INT8_C(  76), -INT8_C(  30),  INT8_C(  13), -INT8_C(  93),  INT8_C(  46),
        -INT8_C(  62), -INT8_C(  87), -INT8_C(  62),  INT8_C( 120),  INT8_C( 115),  INT8_C(  19), -INT8_C(  93), -INT8_C(   2),
        -INT8_C(  98),  INT8_C(   2), -INT8_C(  24),  INT8_C(  22), -INT8_C(  62), -INT8_C(  88),  INT8_C(  56),  INT8_C(  34),
         INT8_C(  62),  INT8_C(  14), -INT8_C(  88),  INT8_C(  76),  INT8_C( 120), -INT8_C(  37),  INT8_C( 119), -INT8_C(  49) } },
    { {  INT8_C(  32),  INT8_C(  49), -INT8_C(  24), -INT8_C(  66), -INT8_C(  92), -INT8_C( 121), -INT8_C(  20),  INT8_C( 116),
         INT8_C( 118),  INT8_C(  56),  INT8_C( 105), -INT8_C(  19),  INT8_C( 101), -INT8_C(  37), -INT8_C(  55), -INT8_C( 105),
        -INT8_C(  39), -INT8_C(  21),  INT8_C(  24), -INT8_C(  16), -INT8_C(  80),  INT8_C( 122), -INT8_C(  56), -INT8_C( 119),
         INT8_C( 117),  INT8_C(  11),  INT8_C(   0), -INT8_C( 126),  INT8_C(   9), -INT8_C(  33),  INT8_C(  51),  INT8_C(  41) },
      {  INT8_C(  16),  INT8_C(  27), -INT8_C(  25), -INT8_C(  75), -INT8_C(  93), -INT8_C(  44),  INT8_C(  41),  INT8_C(  25),
         INT8_C(  12), -INT8_C( 110),  INT8_C(   6),  INT8_C( 113),  INT8_C( 109), -INT8_C(  49),  INT8_C(   8),  INT8_C(  71),
        -INT8_C(  70),  INT8_C(  32),  INT8_C(  55),  INT8_C( 107), -INT8_C( 102),  INT8_C(   0), -INT8_C(  12),  INT8_C(  16),
         INT8_C(  11), -INT8_C(  12), -INT8_C( 110),  INT8_C(  20), -INT8_C(  45), -INT8_C(  59),  INT8_C(  61), -INT8_C(  29) },
      { -INT8_C(  31),  INT8_C(  36), -INT8_C( 104), -INT8_C( 124), -INT8_C(   8), -INT8_C(  63), -INT8_C(  99),  INT8_C(   5),
         INT8_C(  83), -INT8_C(  93),  INT8_C( 118), -INT8_C(  63),  INT8_C( 115),      INT8_MAX,  INT8_C(   8),  INT8_C(  45),
        -INT8_C(  97),  INT8_C(  63), -INT8_C( 104),  INT8_C(  58),  INT8_C(  63), -INT8_C( 116),  INT8_C(  74),  INT8_C(  74),
             INT8_MIN, -INT8_C(  36),  INT8_C(  94),  INT8_C(  83), -INT8_C(  94), -INT8_C( 101),  INT8_C(  55), -INT8_C( 125) },
      { -INT8_C(  39), -INT8_C( 126),  INT8_C(   5), -INT8_C( 116), -INT8_C( 124), -INT8_C(  80), -INT8_C(  93),  INT8_C(  11),
         INT8_C( 101),  INT8_C(  24), -INT8_C(  20),  INT8_C(  63),      INT8_MAX, -INT8_C( 105),  INT8_C( 118),  INT8_C( 116),
         INT8_C(  94), -INT8_C(  31),  INT8_C(  74), -INT8_C(  63),  INT8_C(   0),  INT8_C(  32),  INT8_C(  63), -INT8_C(  39),
        -INT8_C(  19),  INT8_C(  63),  INT8_C(  24), -INT8_C(  80), -INT8_C(  16), -INT8_C( 121), -INT8_C( 101), -INT8_C( 124) } },
    { { -INT8_C(  64), -INT8_C(  49),  INT8_C(   7), -INT8_C(  72), -INT8_C( 111), -INT8_C(  92), -INT8_C(  67), -INT8_C(  28),
         INT8_C(  71),  INT8_C(  52), -INT8_C(  91), -INT8_C(  70), -INT8_C(  77), -INT8_C(  83), -INT8_C(  24),  INT8_C(  82),
        -INT8_C(  19),      INT8_MIN, -INT8_C( 116),  INT8_C(  44),  INT8_C(  13), -INT8_C(  42),  INT8_C( 119), -INT8_C( 115),
        -INT8_C(  77), -INT8_C(  43), -INT8_C(  31),  INT8_C(  85),  INT8_C( 113),  INT8_C(  24), -INT8_C(  40),  INT8_C(  49) },
      { -INT8_C(  25), -INT8_C(  33), -INT8_C(  23),  INT8_C( 120), -INT8_C( 125), -INT8_C(  89),  INT8_C(  93), -INT8_C(  54),
        -INT8_C(  37),  INT8_C(   2), -INT8_C( 123), -INT8_C( 114), -INT8_C(  80),  INT8_C( 109), -INT8_C(  32), -INT8_C(  99),
        -INT8_C(  19),  INT8_C( 109), -INT8_C(  55), -INT8_C(   6),  INT8_C(  67),  INT8_C(  64), -INT8_C( 120), -INT8_C(  10),
         INT8_C(  22),  INT8_C( 105),  INT8_C(  75), -INT8_C( 121), -INT8_C( 127),  INT8_C(  35), -INT8_C(  72),  INT8_C( 104) },
      {  INT8_C(   2), -INT8_C(  95), -INT8_C(  31), -INT8_C( 123),  INT8_C(  72),  INT8_C(  62),  INT8_C(  80),  INT8_C(  35),
         INT8_C(  64), -INT8_C(  43), -INT8_C(  79), -INT8_C(  16),  INT8_C(  66), -INT8_C( 110), -INT8_C( 115),  INT8_C(  47),
        -INT8_C(   1),  INT8_C(  87),  INT8_C(  42),  INT8_C(  66), -INT8_C( 105), -INT8_C(  78),  INT8_C(  57), -INT8_C(  83),
         INT8_C(  27), -INT8_C( 124),  INT8_C(  52), -INT8_C( 100), -INT8_C(  88), -INT8_C(  20),  INT8_C(   4), -INT8_C(  86) },
      {  INT8_C(  35),  INT8_C(  49), -INT8_C(  43),  INT8_C(  27), -INT8_C(  72),  INT8_C(  35),  INT8_C(  24), -INT8_C(  91),
         INT8_C(  85),  INT8_C(   7), -INT8_C(  92), -INT8_C(  24), -INT8_C(   1), -INT8_C( 110),  INT8_C(   2),  INT8_C(  24),
        -INT8_C( 110), -INT8_C( 110),  INT8_C(  52),  INT8_C(  52), -INT8_C(  72), -INT8_C(  64),  INT8_C(  71),  INT8_C(  57),
         INT8_C( 119), -INT8_C(  43), -INT8_C(  70), -INT8_C(  28), -INT8_C(  49), -INT8_C( 123),  INT8_C(  27),  INT8_C(  64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_permutex2var_epi8(a, idx, b);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_permutex2var_epi8(a, idx, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const simde__mmask32 k;
    const int8_t idx[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C( 114), -INT8_C(  27),  INT8_C(  48), -INT8_C(  42),  INT8_C(  35),      INT8_MIN, -INT8_C(   6),  INT8_C( 100),
         INT8_C(  85), -INT8_C(  85),  INT8_C(  84), -INT8_C( 105),  INT8_C(  61), -INT8_C(  30), -INT8_C(  58),  INT8_C(  60),
         INT8_C(  57), -INT8_C(  16),      INT8_MAX, -INT8_C(  48), -INT8_C(  94), -INT8_C(  72),  INT8_C( 126), -INT8_C(  67),
         INT8_C(  60), -INT8_C(  78),  INT8_C(  89), -INT8_C(  28), -INT8_C(  97),  INT8_C(  94), -INT8_C( 113),  INT8_C(  45) },
      UINT32_C(1728298819),
      {  INT8_C(  63), -INT8_C(   3), -INT8_C(  53), -INT8_C( 108), -INT8_C(  87),  INT8_C(  31),  INT8_C(  43), -INT8_C(  26),
         INT8_C(   1), -INT8_C(  15),  INT8_C(  35),  INT8_C(  58), -INT8_C(  30), -INT8_C(  94),  INT8_C(  11), -INT8_C( 124),
         INT8_C(  90), -INT8_C( 119),  INT8_C(  66), -INT8_C( 106),  INT8_C(  59), -INT8_C( 101),  INT8_C( 123), -INT8_C(  38),
        -INT8_C(   7),  INT8_C(  10),  INT8_C(   7),  INT8_C(  61), -INT8_C(  55),  INT8_C(  11), -INT8_C(  92),  INT8_C(   8) },
      {  INT8_C(   8),  INT8_C( 111), -INT8_C( 100), -INT8_C(  79), -INT8_C( 114), -INT8_C(  57), -INT8_C( 104), -INT8_C( 112),
        -INT8_C(  72), -INT8_C(  69), -INT8_C(  54), -INT8_C( 102),  INT8_C(  93), -INT8_C(  43),  INT8_C(  31), -INT8_C(  73),
         INT8_C(  94),  INT8_C(  97),  INT8_C(  77), -INT8_C( 102), -INT8_C(   4), -INT8_C(  56),  INT8_C( 116), -INT8_C(  10),
        -INT8_C(  46),  INT8_C( 124),  INT8_C(  51), -INT8_C( 101), -INT8_C( 121), -INT8_C(  41), -INT8_C(  93), -INT8_C( 113) },
      { -INT8_C( 113), -INT8_C(  41),  INT8_C(  48), -INT8_C(  42),  INT8_C(  35),      INT8_MIN, -INT8_C( 102),  INT8_C( 100),
        -INT8_C(  27),  INT8_C(  97), -INT8_C(  79),  INT8_C(  51), -INT8_C( 100), -INT8_C( 100), -INT8_C(  58),  INT8_C(  35),
         INT8_C(  89), -INT8_C(  85),      INT8_MAX, -INT8_C(  48), -INT8_C(  94), -INT8_C(  72),  INT8_C( 126), -INT8_C(  67),
         INT8_C( 124),  INT8_C(  84),  INT8_C( 100), -INT8_C(  28), -INT8_C(  97), -INT8_C( 105), -INT8_C( 114),  INT8_C(  45) } },
    { {  INT8_C(  70),  INT8_C(  63),  INT8_C(  65), -INT8_C(  44),  INT8_C(   6), -INT8_C(  39),  INT8_C( 100), -INT8_C(  65),
        -INT8_C( 108),  INT8_C(  47),  INT8_C(  89), -INT8_C(  15),  INT8_C(   4),  INT8_C( 120), -INT8_C(  88),  INT8_C(  99),
        -INT8_C(  39), -INT8_C(  11), -INT8_C(   3), -INT8_C(  42), -INT8_C(  66),  INT8_C( 113), -INT8_C(  52), -INT8_C( 112),
        -INT8_C(  19), -INT8_C(   1),  INT8_C(  44),  INT8_C( 116), -INT8_C(  42), -INT8_C(  49),  INT8_C(   4),  INT8_C(  28) },
      UINT32_C( 368067855),
      {  INT8_C(  30),  INT8_C(  85), -INT8_C(  44), -INT8_C(  78), -INT8_C( 124),  INT8_C(  46), -INT8_C(  93), -INT8_C( 120),
        -INT8_C(  90),  INT8_C(  75), -INT8_C(  21),      INT8_MIN,  INT8_C(  64), -INT8_C(  24),  INT8_C(  86), -INT8_C(   2),
         INT8_C(  90),  INT8_C(  34), -INT8_C( 113),  INT8_C(  71),  INT8_C(  33), -INT8_C(  69), -INT8_C(  68), -INT8_C(   9),
        -INT8_C( 118), -INT8_C(  64),  INT8_C(  19), -INT8_C( 103),  INT8_C(   5),  INT8_C(   3), -INT8_C(  81),  INT8_C(  35) },
      {  INT8_C(  88), -INT8_C( 125), -INT8_C(  43), -INT8_C(  36), -INT8_C(  79),  INT8_C( 120),  INT8_C( 101),  INT8_C(  88),
        -INT8_C(  61),  INT8_C(  80), -INT8_C(  40),  INT8_C(   3),  INT8_C(  57),  INT8_C(  46),  INT8_C(   2), -INT8_C( 109),
         INT8_C(  80), -INT8_C( 111), -INT8_C(  38),  INT8_C( 113),  INT8_C(  76), -INT8_C( 106),  INT8_C( 104), -INT8_C(  42),
         INT8_C(  86),  INT8_C( 123),  INT8_C( 112),  INT8_C(  91),  INT8_C( 126),  INT8_C(  31),  INT8_C( 126), -INT8_C(  41) },
      {  INT8_C(   4),  INT8_C( 113), -INT8_C(  66), -INT8_C(  38),  INT8_C(   6), -INT8_C(  39),  INT8_C( 100), -INT8_C(  65),
         INT8_C( 101),  INT8_C(  47),  INT8_C(   3), -INT8_C(  15),  INT8_C(   4),  INT8_C( 120), -INT8_C(  52),  INT8_C(  99),
        -INT8_C(  39), -INT8_C(  11), -INT8_C(   3), -INT8_C(  42), -INT8_C( 125),  INT8_C(  91),  INT8_C( 126), -INT8_C(  42),
         INT8_C(  89), -INT8_C(   1), -INT8_C(  42),  INT8_C( 116), -INT8_C(  39), -INT8_C(  49),  INT8_C(   4),  INT8_C(  28) } },
    { { -INT8_C(  94),  INT8_C(  83), -INT8_C(  77),  INT8_C(  84), -INT8_C(  53),  INT8_C(  24), -INT8_C(  84), -INT8_C( 114),
         INT8_C( 105), -INT8_C( 124), -INT8_C( 110), -INT8_C(  94), -INT8_C(  78), -INT8_C( 108),  INT8_C(  53),  INT8_C(   2),
         INT8_C(  37),  INT8_C(  15),  INT8_C( 115),  INT8_C( 113), -INT8_C(  90), -INT8_C(  37),  INT8_C(  71), -INT8_C(   4),
         INT8_C(  86), -INT8_C(  73),  INT8_C(  88), -INT8_C(  44), -INT8_C(  42), -INT8_C(  42), -INT8_C(  85),  INT8_C( 121) },
      UINT32_C(4123877162),
      {  INT8_C( 119),  INT8_C( 121), -INT8_C( 124), -INT8_C(  32), -INT8_C(   3),  INT8_C(  22), -INT8_C( 126), -INT8_C(  81),
        -INT8_C(  86), -INT8_C(  73), -INT8_C(  79), -INT8_C(  49), -INT8_C(  57),  INT8_C(  36),  INT8_C(  64),  INT8_C( 109),
        -INT8_C(   1), -INT8_C( 121),  INT8_C( 105),  INT8_C(  85),  INT8_C(  63), -INT8_C(  63),  INT8_C(  41),  INT8_C(  21),
        -INT8_C( 104), -INT8_C(  43), -INT8_C( 114), -INT8_C(  62),  INT8_C(  52),  INT8_C(  91), -INT8_C(  73), -INT8_C(  85) },
      { -INT8_C(  44),  INT8_C(  59), -INT8_C( 116), -INT8_C(  47),  INT8_C(  81),  INT8_C(  14),      INT8_MIN, -INT8_C(   5),
        -INT8_C(  58),  INT8_C(  49), -INT8_C(  54), -INT8_C( 115),  INT8_C(  85),  INT8_C(  10), -INT8_C(   6),  INT8_C(  84),
        -INT8_C( 110),  INT8_C(  99), -INT8_C(  87), -INT8_C(  47),  INT8_C(  37), -INT8_C(  45), -INT8_C(  26), -INT8_C(  67),
        -INT8_C(  88),  INT8_C( 117),      INT8_MAX, -INT8_C(  36), -INT8_C(  48),  INT8_C(  54), -INT8_C( 121), -INT8_C(  91) },
      { -INT8_C(  94),  INT8_C( 117), -INT8_C(  77), -INT8_C(  44), -INT8_C(  53),  INT8_C(  71), -INT8_C(  84), -INT8_C( 114),
        -INT8_C(  54), -INT8_C(  67),  INT8_C(  99),  INT8_C(   2), -INT8_C( 114), -INT8_C( 108), -INT8_C(  94),  INT8_C(   2),
        -INT8_C(  91),  INT8_C(  15),  INT8_C(  49), -INT8_C(  37), -INT8_C(  90), -INT8_C(  37),  INT8_C(  49), -INT8_C(  37),
         INT8_C(  86), -INT8_C(  73),  INT8_C(  53), -INT8_C(  44),  INT8_C(  37), -INT8_C(  44), -INT8_C(  67), -INT8_C( 115) } },
    { {  INT8_C( 114),  INT8_C(  19),  INT8_C( 118), -INT8_C(  61),  INT8_C(  34), -INT8_C(   9), -INT8_C(  65), -INT8_C(  24),
         INT8_C(  40), -INT8_C( 119),  INT8_C( 117),  INT8_C( 126), -INT8_C( 108),  INT8_C( 111), -INT8_C(  46),  INT8_C(  38),
        -INT8_C(  46),  INT8_C( 124), -INT8_C(   9), -INT8_C(   9),  INT8_C(  79), -INT8_C(  35), -INT8_C(  76), -INT8_C(   9),
         INT8_C(  82),  INT8_C(  51), -INT8_C(  45),  INT8_C(  35),  INT8_C( 106),  INT8_C(  90), -INT8_C(  56), -INT8_C(  36) },
      UINT32_C(2426355310),
      {  INT8_C(  53),  INT8_C(  94),  INT8_C( 120),  INT8_C(  94), -INT8_C(  24), -INT8_C(  19), -INT8_C(  36),  INT8_C( 124),
         INT8_C(  92), -INT8_C(  82), -INT8_C(  94),  INT8_C(  46),  INT8_C(  42), -INT8_C( 103),  INT8_C(  38),  INT8_C( 121),
         INT8_C( 118), -INT8_C(  38),  INT8_C( 112), -INT8_C(  55),  INT8_C(  14),  INT8_C(  67), -INT8_C(  20),  INT8_C( 120),
        -INT8_C(  98), -INT8_C(  76),  INT8_C(  84),  INT8_C(  12), -INT8_C(  14), -INT8_C(  13), -INT8_C( 100),  INT8_C(  40) },
      {  INT8_C(  82),  INT8_C(  20), -INT8_C( 122),  INT8_C(  58),  INT8_C(   1),  INT8_C(  98), -INT8_C(  74),  INT8_C(  93),
         INT8_C(  16),  INT8_C(  88), -INT8_C( 117),  INT8_C(  59), -INT8_C(  15), -INT8_C(  79), -INT8_C(  76),  INT8_C( 103),
        -INT8_C( 116),  INT8_C(  37),  INT8_C(  48), -INT8_C( 102),  INT8_C( 104),  INT8_C(  28),  INT8_C(  18),  INT8_C(   6),
        -INT8_C(  48),  INT8_C( 102),  INT8_C(  18), -INT8_C(  61),  INT8_C(  89), -INT8_C(  82), -INT8_C(  21), -INT8_C(  85) },
      {  INT8_C( 114), -INT8_C(  56), -INT8_C(  48), -INT8_C(  56),  INT8_C(  34), -INT8_C(  79),  INT8_C( 106), -INT8_C(  24),
         INT8_C(  40), -INT8_C(  76), -INT8_C( 122), -INT8_C(  76), -INT8_C( 117),  INT8_C(  51), -INT8_C(  46),  INT8_C(  38),
         INT8_C(  18), -INT8_C(  45), -INT8_C( 116), -INT8_C( 119), -INT8_C(  46), -INT8_C(  35), -INT8_C(  76), -INT8_C(  48),
         INT8_C(  82),  INT8_C(  51), -INT8_C(  45),  INT8_C(  35),  INT8_C(  48),  INT8_C(  90), -INT8_C(  56),  INT8_C(  16) } },
    { { -INT8_C(  62),  INT8_C( 113), -INT8_C(  27), -INT8_C(  61), -INT8_C(  45), -INT8_C( 101),  INT8_C(  32), -INT8_C(  29),
        -INT8_C(  13), -INT8_C(  84),  INT8_C(  30), -INT8_C(  28),  INT8_C(  93), -INT8_C(  45),  INT8_C(  76), -INT8_C(  23),
        -INT8_C(   8),  INT8_C( 124), -INT8_C( 125),  INT8_C(  96), -INT8_C( 103), -INT8_C( 107),  INT8_C( 103),  INT8_C( 105),
        -INT8_C(   5),  INT8_C( 121),  INT8_C(  44),  INT8_C(  85),  INT8_C(  40),  INT8_C(  23),  INT8_C(   0), -INT8_C(  22) },
      UINT32_C(1538188936),
      { -INT8_C( 127), -INT8_C(  50),  INT8_C(  63),  INT8_C( 117),  INT8_C( 122),  INT8_C(  93),  INT8_C(  89), -INT8_C(  40),
         INT8_C(  48), -INT8_C(  91), -INT8_C(  63),  INT8_C(  40),  INT8_C(  34),  INT8_C(  69), -INT8_C( 119), -INT8_C(  69),
        -INT8_C(  38), -INT8_C(  16),  INT8_C(  36), -INT8_C(  42),  INT8_C( 105),  INT8_C(  81),  INT8_C(  43), -INT8_C( 111),
         INT8_C( 104),  INT8_C(  43),  INT8_C( 124), -INT8_C(  15),  INT8_C(  17),  INT8_C(  42),  INT8_C(  76), -INT8_C( 109) },
      { -INT8_C(   8), -INT8_C( 117),  INT8_C(   8),  INT8_C( 115), -INT8_C(  23),  INT8_C(  97),  INT8_C(  75),  INT8_C(  25),
         INT8_C(   7),  INT8_C(  12),  INT8_C(  66),  INT8_C(  41),  INT8_C(  81), -INT8_C(  53), -INT8_C(  28),  INT8_C(  44),
        -INT8_C(  69),  INT8_C(   8),  INT8_C(   2),  INT8_C(  36),  INT8_C(  89),  INT8_C(  45), -INT8_C(  74), -INT8_C(  62),
         INT8_C(  88),  INT8_C(  50), -INT8_C(  77),  INT8_C( 106),  INT8_C(  92), -INT8_C(   1), -INT8_C(   3),  INT8_C(  84) },
      { -INT8_C(  62),  INT8_C( 113), -INT8_C(  27),  INT8_C(  45), -INT8_C(  45), -INT8_C( 101),  INT8_C(  32), -INT8_C(   5),
        -INT8_C(  13),  INT8_C(  97),  INT8_C( 113), -INT8_C(  28),  INT8_C(  93), -INT8_C( 101), -INT8_C(  84),  INT8_C( 106),
        -INT8_C(   8), -INT8_C(  69), -INT8_C(  23),  INT8_C( 103), -INT8_C( 103),  INT8_C( 124),  INT8_C( 103),  INT8_C( 124),
         INT8_C(   7),  INT8_C(  41),  INT8_C(  44),  INT8_C(   8),  INT8_C( 124),  INT8_C(  23),  INT8_C(  93), -INT8_C(  22) } },
    { { -INT8_C( 117),  INT8_C(   5), -INT8_C(  57),  INT8_C( 116),  INT8_C( 102),  INT8_C(  18), -INT8_C( 115),  INT8_C( 109),
         INT8_C(  31), -INT8_C(  49), -INT8_C( 106),  INT8_C( 112), -INT8_C( 102),  INT8_C( 122), -INT8_C( 100),  INT8_C(  85),
        -INT8_C( 125), -INT8_C(  98),  INT8_C( 122), -INT8_C(  36), -INT8_C(  53),  INT8_C(  48), -INT8_C(  98),  INT8_C(  36),
         INT8_C(  98),  INT8_C(  81), -INT8_C( 114), -INT8_C(  66),  INT8_C(  81), -INT8_C( 117),  INT8_C(  18), -INT8_C(  36) },
      UINT32_C(4132493968),
      { -INT8_C(  20), -INT8_C(  35),  INT8_C( 100),  INT8_C(  11), -INT8_C(  83), -INT8_C(   6),  INT8_C( 124),  INT8_C(  71),
         INT8_C( 117),  INT8_C(  24), -INT8_C(  99), -INT8_C(   8), -INT8_C(  73),  INT8_C(  23), -INT8_C(  44), -INT8_C( 126),
         INT8_C(  71),  INT8_C( 115), -INT8_C(  90), -INT8_C(  87), -INT8_C(  60),  INT8_C(  52),  INT8_C( 103),  INT8_C(  21),
        -INT8_C(  65),  INT8_C( 121), -INT8_C(  15),  INT8_C(  79),  INT8_C(  83),  INT8_C(  65),  INT8_C(  70),  INT8_C(  64) },
      {  INT8_C(  31), -INT8_C(  86),  INT8_C(  75), -INT8_C(  52), -INT8_C(  92), -INT8_C(  57),  INT8_C(  19),  INT8_C(  25),
        -INT8_C(  32), -INT8_C(  80),  INT8_C(  17), -INT8_C( 105), -INT8_C(  57), -INT8_C(  26),  INT8_C(  25),  INT8_C(  14),
         INT8_C(  89), -INT8_C(  64), -INT8_C(  73),  INT8_C(  29), -INT8_C(  12),  INT8_C(  30),  INT8_C(  51), -INT8_C(  76),
        -INT8_C( 104),  INT8_C(  36),  INT8_C(   3), -INT8_C(  21),  INT8_C( 102),  INT8_C(  73),  INT8_C(  43), -INT8_C( 123) },
      { -INT8_C( 117),  INT8_C(   5), -INT8_C(  57),  INT8_C( 116), -INT8_C(  26),  INT8_C(  18), -INT8_C( 115),  INT8_C( 109),
         INT8_C(  31),  INT8_C(  98), -INT8_C( 106), -INT8_C( 104), -INT8_C(  76),  INT8_C( 122), -INT8_C(  53), -INT8_C(  57),
        -INT8_C( 125), -INT8_C(  98),  INT8_C( 122), -INT8_C(  36),  INT8_C( 102),  INT8_C(  48),  INT8_C(  25),  INT8_C(  36),
         INT8_C(  98),  INT8_C(  36), -INT8_C(  64), -INT8_C(  66), -INT8_C(  36),  INT8_C(   5), -INT8_C( 115), -INT8_C( 117) } },
    { { -INT8_C(  13),  INT8_C( 119),  INT8_C(  81), -INT8_C( 104),  INT8_C(  62),  INT8_C( 100), -INT8_C(  79),  INT8_C(  30),
         INT8_C(  21), -INT8_C(  61), -INT8_C(  75), -INT8_C(  36), -INT8_C(  87), -INT8_C(  49), -INT8_C(  21),  INT8_C(   2),
        -INT8_C( 113), -INT8_C(  94),  INT8_C(  31), -INT8_C( 125), -INT8_C(  63),  INT8_C(  82),  INT8_C(  55),  INT8_C(  89),
         INT8_C( 119),  INT8_C(  59),  INT8_C(  68), -INT8_C(  35), -INT8_C( 124),  INT8_C( 112),  INT8_C(  98),  INT8_C( 120) },
      UINT32_C( 621851623),
      {  INT8_C(  23), -INT8_C(  63),  INT8_C(  68),  INT8_C(  44), -INT8_C( 124), -INT8_C(   7),  INT8_C(   9),  INT8_C(  45),
        -INT8_C(  56), -INT8_C(  12),  INT8_C(  47),  INT8_C(  87), -INT8_C( 106),  INT8_C(  79), -INT8_C(  37),  INT8_C(  87),
        -INT8_C(  95),  INT8_C(  18), -INT8_C(  80),  INT8_C(  24),  INT8_C(  77), -INT8_C(  11), -INT8_C(  11), -INT8_C(  46),
         INT8_C( 101),  INT8_C(  87),  INT8_C(  74),  INT8_C(  76),  INT8_C(  10),  INT8_C(  90),  INT8_C( 113),  INT8_C(  34) },
      {  INT8_C(  27), -INT8_C(  75),  INT8_C(  78), -INT8_C(  96), -INT8_C(  81),  INT8_C(  87), -INT8_C(  51),  INT8_C( 119),
         INT8_C(  75), -INT8_C(   3), -INT8_C(  49), -INT8_C(  30),  INT8_C(  76), -INT8_C(  86),  INT8_C(  57), -INT8_C(  19),
        -INT8_C(  68), -INT8_C(  22),  INT8_C(   6),  INT8_C(  10), -INT8_C(  33), -INT8_C(   5), -INT8_C(  36),  INT8_C(  68),
         INT8_C(  83),  INT8_C(  38), -INT8_C( 112),  INT8_C(  93),      INT8_MIN,  INT8_C(   1),      INT8_MAX, -INT8_C( 101) },
      {  INT8_C(  89),  INT8_C( 119),  INT8_C(  62), -INT8_C( 104),  INT8_C(  62),  INT8_C(  38), -INT8_C(  61), -INT8_C(  86),
         INT8_C(  21), -INT8_C(  33), -INT8_C(  75), -INT8_C(  36),  INT8_C(  55),  INT8_C(   2), -INT8_C(  21),  INT8_C(  89),
        -INT8_C( 113), -INT8_C(  94),  INT8_C(  31), -INT8_C( 125), -INT8_C(  49),  INT8_C(  82),  INT8_C(  55),  INT8_C(  89),
         INT8_C(  87),  INT8_C(  59), -INT8_C(  75), -INT8_C(  35), -INT8_C( 124),  INT8_C(  68),  INT8_C(  98),  INT8_C( 120) } },
    { { -INT8_C(  73), -INT8_C(  50),  INT8_C(  59),  INT8_C( 102),  INT8_C(  37),  INT8_C(   9), -INT8_C(  35),  INT8_C( 113),
         INT8_C(   6), -INT8_C(  84),  INT8_C(  83),  INT8_C(  82),  INT8_C(  86), -INT8_C( 116),  INT8_C(  63),  INT8_C(  19),
         INT8_C( 118),  INT8_C(  69),  INT8_C(  29),  INT8_C(  85),  INT8_C(  65), -INT8_C(   7), -INT8_C( 103), -INT8_C( 108),
         INT8_C(  31),  INT8_C(  41), -INT8_C(  15), -INT8_C(  97),  INT8_C(  43),  INT8_C( 113),  INT8_C(  58), -INT8_C(  30) },
      UINT32_C(1682470463),
      {      INT8_MAX,  INT8_C(  37), -INT8_C(  43), -INT8_C( 123), -INT8_C(  46),  INT8_C(  40), -INT8_C(  41),  INT8_C(  40),
        -INT8_C(  75),  INT8_C(  22),  INT8_C(  59),  INT8_C(  43),  INT8_C(  92),  INT8_C(  88), -INT8_C( 127), -INT8_C(  99),
         INT8_C(  81),  INT8_C(  26),  INT8_C(  49),  INT8_C( 112),  INT8_C(  68),  INT8_C(  34),  INT8_C(  15),  INT8_C( 111),
        -INT8_C( 109),  INT8_C(  74),  INT8_C(  81), -INT8_C(  46), -INT8_C(  64), -INT8_C( 103),  INT8_C(  55),  INT8_C(  63) },
      { -INT8_C(  66),  INT8_C(  12), -INT8_C(  60), -INT8_C( 112),  INT8_C(  53), -INT8_C( 101), -INT8_C(  71), -INT8_C(  22),
        -INT8_C(  79), -INT8_C(  12),  INT8_C(  21),  INT8_C(  13),  INT8_C(  77), -INT8_C( 106), -INT8_C(  86), -INT8_C(  98),
        -INT8_C(  79), -INT8_C(  37),  INT8_C(  15), -INT8_C(  11), -INT8_C(   2),  INT8_C(  30),  INT8_C( 100), -INT8_C( 111),
         INT8_C( 104), -INT8_C(  75),  INT8_C( 100),  INT8_C(  40),  INT8_C(  78), -INT8_C( 101),  INT8_C( 103),  INT8_C(  12) },
      {  INT8_C(  12), -INT8_C( 101), -INT8_C(   7),  INT8_C(   9),  INT8_C(  29), -INT8_C(  79), -INT8_C(  35),  INT8_C( 113),
         INT8_C(   6), -INT8_C( 103),  INT8_C(  40),  INT8_C(  82),  INT8_C(  43),  INT8_C(  31), -INT8_C(  50),  INT8_C(  19),
         INT8_C( 118),  INT8_C(  69),  INT8_C(  29), -INT8_C(  79),  INT8_C(  65), -INT8_C(   7),  INT8_C(  19), -INT8_C( 108),
         INT8_C(  31),  INT8_C(  41),  INT8_C(  69), -INT8_C(  97),  INT8_C(  43),  INT8_C(  41), -INT8_C( 111), -INT8_C(  30) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_permutex2var_epi8(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask_permutex2var_epi8(a, k, idx, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask2_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t idx[32];
    const simde__mmask32 k;
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C(  89),  INT8_C(  43), -INT8_C(  99), -INT8_C(  36), -INT8_C(  58),  INT8_C(  86), -INT8_C(  58),  INT8_C( 120),
         INT8_C(  74), -INT8_C(  36), -INT8_C( 123), -INT8_C( 105),  INT8_C( 114),  INT8_C(  48),  INT8_C(  54),  INT8_C(  35),
         INT8_C(  11),  INT8_C(  69),  INT8_C(  24),  INT8_C(   9),  INT8_C(  99),  INT8_C( 124), -INT8_C( 101), -INT8_C(  52),
         INT8_C(  49), -INT8_C(   1), -INT8_C(  12),      INT8_MAX, -INT8_C( 102),  INT8_C(  92), -INT8_C( 116),  INT8_C(  65) },
      { -INT8_C( 121),  INT8_C(  41),  INT8_C(  30),  INT8_C(  78),      INT8_MAX, -INT8_C(  28), -INT8_C(  58), -INT8_C(  55),
        -INT8_C(  64),  INT8_C(  75),  INT8_C(  97),  INT8_C(  51),  INT8_C( 123), -INT8_C( 105),  INT8_C(  86), -INT8_C( 121),
        -INT8_C(  36),  INT8_C( 111), -INT8_C( 112),  INT8_C(  63), -INT8_C(  21),  INT8_C(  43),  INT8_C(  11),  INT8_C(  29),
         INT8_C(  42),  INT8_C(   0), -INT8_C( 100), -INT8_C(  60),  INT8_C(  92),  INT8_C(  40),  INT8_C(   6), -INT8_C(  29) },
      UINT32_C(3492881489),
      {  INT8_C(   8), -INT8_C(   9), -INT8_C( 102), -INT8_C(  55),  INT8_C(  67), -INT8_C(   5), -INT8_C(   4), -INT8_C(  66),
        -INT8_C( 110),  INT8_C(  82),  INT8_C(  69),  INT8_C( 110), -INT8_C(  63), -INT8_C(  42), -INT8_C(  83), -INT8_C(  83),
         INT8_C(   1), -INT8_C(  71), -INT8_C(  54),  INT8_C(  44), -INT8_C(  71),  INT8_C( 102), -INT8_C(  16),  INT8_C(  21),
        -INT8_C( 113), -INT8_C(  10), -INT8_C(   8), -INT8_C(  32),  INT8_C(  26),  INT8_C(  42), -INT8_C(  79),  INT8_C(  35) },
      {  INT8_C( 120),  INT8_C(  41),  INT8_C(  30),  INT8_C(  78),  INT8_C(  35), -INT8_C(  28), -INT8_C(  58), -INT8_C(  55),
        -INT8_C(  64),  INT8_C(  75), -INT8_C(   9),  INT8_C(  51),  INT8_C( 123), -INT8_C(  52),  INT8_C(  86), -INT8_C( 121),
        -INT8_C( 102),  INT8_C( 111), -INT8_C( 112),  INT8_C(  63),  INT8_C( 110),  INT8_C( 110),  INT8_C(  11),  INT8_C(  29),
         INT8_C(  42),  INT8_C(   0), -INT8_C( 100), -INT8_C(  60), -INT8_C( 102),  INT8_C(  40), -INT8_C(  58), -INT8_C(  55) } },
    { {  INT8_C(  33),  INT8_C(  75), -INT8_C(  20),  INT8_C( 100),  INT8_C(  70), -INT8_C(  24),  INT8_C(  35), -INT8_C(  40),
         INT8_C(  58),  INT8_C( 104),  INT8_C(  70), -INT8_C(   4),  INT8_C(  62), -INT8_C(  13), -INT8_C(  87),  INT8_C(  64),
        -INT8_C(  84),  INT8_C( 115),  INT8_C( 108),  INT8_C( 101), -INT8_C(  39),  INT8_C(  92),  INT8_C( 122),  INT8_C( 104),
         INT8_C(  83),  INT8_C( 115),  INT8_C(  73),  INT8_C( 109), -INT8_C(  99), -INT8_C(   6), -INT8_C( 112), -INT8_C(  66) },
      {  INT8_C(  69),  INT8_C( 124),  INT8_C(  35), -INT8_C( 117),  INT8_C( 100),  INT8_C(  70),  INT8_C(  99), -INT8_C(  97),
        -INT8_C(  82), -INT8_C(  87), -INT8_C( 101), -INT8_C(  19), -INT8_C( 100),  INT8_C(  68),  INT8_C(  45),  INT8_C(  73),
        -INT8_C(  73), -INT8_C( 103), -INT8_C(  82), -INT8_C( 112), -INT8_C(  11),  INT8_C(  41), -INT8_C(   7),  INT8_C(  72),
        -INT8_C( 100),  INT8_C(  66), -INT8_C(  74),  INT8_C(  57),  INT8_C(  60),  INT8_C(  70), -INT8_C(   9), -INT8_C( 127) },
      UINT32_C( 655104707),
      {  INT8_C(  96),  INT8_C( 111), -INT8_C(  58),  INT8_C(  15),  INT8_C(  24),  INT8_C(  97), -INT8_C(   4), -INT8_C(  76),
        -INT8_C(  91),  INT8_C(  41), -INT8_C(   3),  INT8_C(  92), -INT8_C(  62), -INT8_C(  84), -INT8_C(  19), -INT8_C(  73),
        -INT8_C(  43), -INT8_C(  26),  INT8_C(   0),  INT8_C( 113),  INT8_C(  40), -INT8_C(  74), -INT8_C(  86),  INT8_C( 100),
        -INT8_C(   4), -INT8_C(  95), -INT8_C(  27), -INT8_C(  65), -INT8_C(  68), -INT8_C(  15), -INT8_C(  25),  INT8_C(  28) },
      { -INT8_C(  24), -INT8_C(  68),  INT8_C(  35), -INT8_C( 117),  INT8_C( 100),  INT8_C(  70),  INT8_C(  15), -INT8_C(  66),
        -INT8_C(  82),  INT8_C(  41), -INT8_C( 101), -INT8_C(  84), -INT8_C(  99),  INT8_C(  68),  INT8_C(  45),  INT8_C(  73),
        -INT8_C(  73), -INT8_C( 103), -INT8_C(  19), -INT8_C(  84), -INT8_C(  11),  INT8_C(  41), -INT8_C(   7),  INT8_C(  72),
        -INT8_C(  99), -INT8_C(  20), -INT8_C(  86),  INT8_C(  57),  INT8_C(  60),  INT8_C(  35), -INT8_C(   9), -INT8_C( 127) } },
    { {  INT8_C(  96), -INT8_C(  83),  INT8_C(  43),  INT8_C( 120),  INT8_C(  15),  INT8_C(  39),  INT8_C(  44), -INT8_C(  76),
         INT8_C(  80),  INT8_C(  42),  INT8_C(  17),  INT8_C(  18), -INT8_C(  42), -INT8_C(   2), -INT8_C(  54), -INT8_C(  85),
        -INT8_C(  28), -INT8_C(  54),  INT8_C(  28),  INT8_C(  12),      INT8_MIN, -INT8_C(  58),  INT8_C( 112),  INT8_C( 124),
         INT8_C( 103),  INT8_C(  85),  INT8_C(  60),  INT8_C(  35),  INT8_C(  70),  INT8_C(  35),  INT8_C(  64), -INT8_C(  90) },
      { -INT8_C(  48),  INT8_C( 107),  INT8_C(  30), -INT8_C(  33), -INT8_C( 109),  INT8_C(  74), -INT8_C( 108), -INT8_C(  29),
         INT8_C( 116), -INT8_C(  91), -INT8_C(  10),  INT8_C(  74), -INT8_C(  93), -INT8_C(  64), -INT8_C(  11), -INT8_C( 121),
        -INT8_C( 118),  INT8_C(  17), -INT8_C( 109),  INT8_C(  10), -INT8_C(  41),  INT8_C(   3), -INT8_C( 122),  INT8_C(  63),
         INT8_C(  88), -INT8_C(  62),  INT8_C(  98), -INT8_C(  98), -INT8_C(  27), -INT8_C(  94),  INT8_C(  68), -INT8_C(  74) },
      UINT32_C(2710921742),
      { -INT8_C(  84),  INT8_C(  41), -INT8_C( 124),  INT8_C(  33), -INT8_C(  50),  INT8_C( 122),  INT8_C( 107),  INT8_C( 113),
         INT8_C(  58),  INT8_C(  97), -INT8_C(   8), -INT8_C(  60),  INT8_C( 114), -INT8_C( 117), -INT8_C(  50),  INT8_C(  74),
        -INT8_C( 114),  INT8_C(  85), -INT8_C( 119), -INT8_C(  26),  INT8_C(  23), -INT8_C(  21), -INT8_C( 124), -INT8_C(   3),
        -INT8_C( 114), -INT8_C(  56), -INT8_C(  77), -INT8_C( 100),  INT8_C(  42),  INT8_C(  72),  INT8_C(  61), -INT8_C(  41) },
      { -INT8_C(  48), -INT8_C(  60),  INT8_C(  64), -INT8_C(  90), -INT8_C( 109),  INT8_C(  74), -INT8_C( 108), -INT8_C(  29),
         INT8_C( 116),  INT8_C( 122), -INT8_C(  10),  INT8_C(  74), -INT8_C(  93),  INT8_C(  96), -INT8_C(  21), -INT8_C( 121),
         INT8_C(  17),  INT8_C(  17),  INT8_C(  12),  INT8_C(  10),  INT8_C( 124),  INT8_C(   3), -INT8_C( 122), -INT8_C(  41),
         INT8_C( 103), -INT8_C(  62),  INT8_C(  98), -INT8_C(  98), -INT8_C(  27), -INT8_C( 124),  INT8_C(  68), -INT8_C( 124) } },
    { {  INT8_C( 114), -INT8_C(  63), -INT8_C(   8),  INT8_C(  64),  INT8_C(  60),  INT8_C(  99), -INT8_C(  78),  INT8_C( 118),
        -INT8_C(  60), -INT8_C(  86),  INT8_C(  59),  INT8_C(  55),  INT8_C(  54),  INT8_C(   9), -INT8_C( 127), -INT8_C(  60),
         INT8_C(  94),  INT8_C(  10), -INT8_C(  85),  INT8_C( 118), -INT8_C(  11),  INT8_C(  47),  INT8_C( 115), -INT8_C( 125),
        -INT8_C(   8),  INT8_C(  38),  INT8_C(  31),  INT8_C(  34),  INT8_C( 110),  INT8_C(  92), -INT8_C(   7), -INT8_C(  32) },
      {  INT8_C(  30), -INT8_C(  15),  INT8_C(  33),  INT8_C(  90),  INT8_C(  85), -INT8_C(  45), -INT8_C(  48),  INT8_C(  25),
         INT8_C( 125),  INT8_C(  11),  INT8_C(  80), -INT8_C(  77),  INT8_C(  21), -INT8_C(  47),  INT8_C( 120),  INT8_C( 115),
        -INT8_C(  37),  INT8_C(  35), -INT8_C(  23), -INT8_C(  47),  INT8_C(  82),  INT8_C(  92),  INT8_C(  84),  INT8_C(  74),
        -INT8_C( 126),  INT8_C( 116),  INT8_C( 109), -INT8_C(  15), -INT8_C(  48),  INT8_C( 102), -INT8_C(  47), -INT8_C(  18) },
      UINT32_C(2907239000),
      { -INT8_C(  59),  INT8_C(  25), -INT8_C(  58),  INT8_C(  67),  INT8_C(  36),  INT8_C(  23), -INT8_C(  10),  INT8_C(  57),
        -INT8_C(  24),  INT8_C( 110), -INT8_C(  83), -INT8_C(  60), -INT8_C( 111), -INT8_C( 106), -INT8_C( 107), -INT8_C(  28),
        -INT8_C(  13), -INT8_C(  23),  INT8_C(  46),  INT8_C( 117),  INT8_C(  93), -INT8_C( 101),  INT8_C( 102),  INT8_C(  46),
         INT8_C(   2),  INT8_C(  56),  INT8_C(  28),  INT8_C(  90),  INT8_C(  42),  INT8_C( 101),  INT8_C(   7), -INT8_C(  16) },
      {  INT8_C(  30), -INT8_C(  15),  INT8_C(  33),  INT8_C(  31),  INT8_C(  47), -INT8_C(  45),  INT8_C(  94),  INT8_C(  25),
         INT8_C( 125),  INT8_C(  55),  INT8_C(  80), -INT8_C(  77),  INT8_C(  47),  INT8_C(  10),  INT8_C(   2),  INT8_C( 117),
        -INT8_C(  37),  INT8_C(  35), -INT8_C(  23),  INT8_C(  10),  INT8_C(  82),  INT8_C(  92), -INT8_C(  11),  INT8_C(  74),
        -INT8_C(   8),  INT8_C( 116), -INT8_C( 106), -INT8_C(  23), -INT8_C(  48), -INT8_C(  10), -INT8_C(  47), -INT8_C( 107) } },
    { {  INT8_C( 126), -INT8_C(  51),  INT8_C(  51), -INT8_C(  94), -INT8_C(  28),  INT8_C(  41), -INT8_C(  36), -INT8_C(  51),
        -INT8_C( 104), -INT8_C( 119), -INT8_C( 111),  INT8_C(  41),  INT8_C(  31),  INT8_C(  38),  INT8_C(  13),  INT8_C(  18),
         INT8_C(  15),  INT8_C(  60), -INT8_C( 120),  INT8_C( 109), -INT8_C(  41), -INT8_C(  18), -INT8_C( 101), -INT8_C(  39),
         INT8_C(  38), -INT8_C(  73),  INT8_C(  51),  INT8_C(  81),  INT8_C(  28),  INT8_C(  58),  INT8_C(  65), -INT8_C( 102) },
      {  INT8_C(   8),  INT8_C( 116),  INT8_C(  61), -INT8_C(  20), -INT8_C(  99),  INT8_C(  25), -INT8_C(  71),  INT8_C(  53),
        -INT8_C(  94),  INT8_C(  74),  INT8_C(  95), -INT8_C(  63),  INT8_C( 112),  INT8_C( 108), -INT8_C(  44),      INT8_MIN,
        -INT8_C(  88),  INT8_C(  92), -INT8_C(  19),      INT8_MIN,  INT8_C(  74), -INT8_C( 120),  INT8_C(  89),  INT8_C( 113),
         INT8_C(  63), -INT8_C( 115), -INT8_C(  62),  INT8_C(  92), -INT8_C(  57),  INT8_C(   3), -INT8_C(  10), -INT8_C(  49) },
      UINT32_C( 347878263),
      {  INT8_C(  76),  INT8_C( 117),  INT8_C(  74), -INT8_C(  18), -INT8_C(  64), -INT8_C(  87), -INT8_C(  80),  INT8_C(  48),
         INT8_C(  21), -INT8_C( 124), -INT8_C(  80), -INT8_C(  66), -INT8_C(  32), -INT8_C(  99),  INT8_C(  62),  INT8_C(  42),
         INT8_C(  37), -INT8_C( 105), -INT8_C( 101),  INT8_C( 101),  INT8_C(  36),  INT8_C(  93), -INT8_C(  63), -INT8_C(  20),
         INT8_C(  96), -INT8_C(  73), -INT8_C(  69), -INT8_C(  41), -INT8_C(  21),  INT8_C( 119), -INT8_C(  20),  INT8_C(  55) },
      { -INT8_C( 104),  INT8_C(  36),  INT8_C( 119), -INT8_C(  20),  INT8_C(  58), -INT8_C(  73), -INT8_C(  73),  INT8_C(  53),
         INT8_C(  74), -INT8_C( 111),  INT8_C(  95), -INT8_C(  63),  INT8_C(  37), -INT8_C(  32), -INT8_C(  44),      INT8_MIN,
        -INT8_C(  88),  INT8_C(  92), -INT8_C(  99),  INT8_C( 126), -INT8_C( 111), -INT8_C( 104),  INT8_C(  89), -INT8_C( 105),
         INT8_C(  63), -INT8_C( 115),  INT8_C(  51),  INT8_C(  92), -INT8_C(  51),  INT8_C(   3), -INT8_C(  10), -INT8_C(  49) } },
    { { -INT8_C(  19),  INT8_C(  54),  INT8_C(  38), -INT8_C(  83), -INT8_C(  33), -INT8_C(  42), -INT8_C(  35), -INT8_C(  12),
         INT8_C(  90), -INT8_C( 114), -INT8_C(  78),  INT8_C(  58),  INT8_C(  43), -INT8_C(  16),  INT8_C( 100),  INT8_C(  81),
        -INT8_C( 120),  INT8_C(   0), -INT8_C(  74), -INT8_C(  84),  INT8_C(  93),  INT8_C( 119), -INT8_C( 104), -INT8_C(  66),
         INT8_C(  46),  INT8_C(  84), -INT8_C( 107),  INT8_C(  25), -INT8_C(  53), -INT8_C( 127),  INT8_C(  81), -INT8_C(  72) },
      { -INT8_C(  73),  INT8_C( 119),  INT8_C( 101), -INT8_C( 106),  INT8_C(  77),  INT8_C(  67), -INT8_C( 117), -INT8_C(  89),
        -INT8_C(  47),  INT8_C(  61), -INT8_C(  31), -INT8_C(   4),  INT8_C(  46),  INT8_C(  69),  INT8_C(  77), -INT8_C(  74),
         INT8_C(  69),  INT8_C(   3),  INT8_C(  98), -INT8_C(  93),  INT8_C( 122), -INT8_C(   5),  INT8_C(  97), -INT8_C(  87),
         INT8_C(  79), -INT8_C(  10), -INT8_C(  62),  INT8_C(  26),  INT8_C( 120),  INT8_C(  19), -INT8_C(  45),  INT8_C(  47) },
      UINT32_C(3620092042),
      {  INT8_C( 123),  INT8_C(  81),  INT8_C( 126),  INT8_C(  76), -INT8_C( 114),  INT8_C(  95),  INT8_C(  73), -INT8_C(  68),
        -INT8_C(  91), -INT8_C( 106),  INT8_C( 114), -INT8_C(  22), -INT8_C( 102), -INT8_C(  43), -INT8_C( 115),  INT8_C(  20),
        -INT8_C(  48), -INT8_C(  18), -INT8_C(  67),  INT8_C(  31), -INT8_C(  27),      INT8_MIN,  INT8_C(  57),  INT8_C(  93),
        -INT8_C( 109),  INT8_C(  12), -INT8_C( 116),  INT8_C(  30),  INT8_C(  69),  INT8_C(  82), -INT8_C(  11), -INT8_C(  64) },
      { -INT8_C(  73),  INT8_C(  93),  INT8_C( 101), -INT8_C( 104),  INT8_C(  77),  INT8_C(  67), -INT8_C( 117), -INT8_C(  68),
        -INT8_C(  47),  INT8_C(  61), -INT8_C(  31),  INT8_C(  69), -INT8_C( 115), -INT8_C(  42),  INT8_C(  77), -INT8_C(  74),
         INT8_C(  69), -INT8_C(  83),  INT8_C( 126), -INT8_C(  93),  INT8_C( 122), -INT8_C(   5),  INT8_C(  81), -INT8_C( 106),
         INT8_C(  81),  INT8_C(  57),  INT8_C(  38),  INT8_C(  26), -INT8_C( 109),  INT8_C(  19), -INT8_C(  84),  INT8_C(  20) } },
    { { -INT8_C(  93),  INT8_C( 116),  INT8_C(  13),  INT8_C(  50), -INT8_C(  45),  INT8_C(  86), -INT8_C(  18),  INT8_C( 120),
        -INT8_C(  20),  INT8_C(  97),  INT8_C(  99), -INT8_C( 122),  INT8_C(  54), -INT8_C(  16), -INT8_C( 101),  INT8_C(   6),
        -INT8_C(  33),  INT8_C(  88),  INT8_C(  37), -INT8_C(  60), -INT8_C(  40),  INT8_C(  94),  INT8_C(  33),  INT8_C( 108),
         INT8_C( 107), -INT8_C(  83), -INT8_C( 118), -INT8_C(  80),  INT8_C(   0),      INT8_MAX,  INT8_C( 112), -INT8_C(  93) },
      { -INT8_C(  13),  INT8_C( 125), -INT8_C(  43), -INT8_C(  57), -INT8_C(  45), -INT8_C(  60),  INT8_C(  63), -INT8_C(  64),
         INT8_C(  37), -INT8_C(  94),  INT8_C(  70),  INT8_C(  91), -INT8_C( 109), -INT8_C(  31),  INT8_C(  97),  INT8_C( 114),
         INT8_C(  58), -INT8_C( 122),  INT8_C(  54),  INT8_C(  18), -INT8_C(  28),  INT8_C(  87),  INT8_C( 126),  INT8_C(  79),
         INT8_C(   4),  INT8_C(   8), -INT8_C(   1),  INT8_C(   4), -INT8_C( 120),  INT8_C( 112), -INT8_C(  88),  INT8_C( 123) },
      UINT32_C(3242360301),
      {  INT8_C(  65), -INT8_C( 126), -INT8_C( 127),  INT8_C( 102),  INT8_C(  36), -INT8_C(  57), -INT8_C(  63), -INT8_C(  73),
        -INT8_C(  87),  INT8_C(  34),  INT8_C(  41), -INT8_C(  29), -INT8_C(  88),  INT8_C(  95), -INT8_C(  11), -INT8_C( 115),
        -INT8_C(  74),  INT8_C( 116), -INT8_C(  36), -INT8_C(  69),  INT8_C( 124), -INT8_C(  36), -INT8_C(  65),  INT8_C(   4),
         INT8_C(  76),  INT8_C( 103),      INT8_MIN,  INT8_C(  57), -INT8_C(  27), -INT8_C(  62), -INT8_C(   6),  INT8_C(  38) },
      { -INT8_C(  69),  INT8_C( 125),  INT8_C(  94),  INT8_C( 120), -INT8_C(  45), -INT8_C(  45),  INT8_C(  38), -INT8_C(  93),
        -INT8_C(  57), -INT8_C(  94), -INT8_C(  18), -INT8_C(  80), -INT8_C(  60), -INT8_C( 126), -INT8_C( 126),  INT8_C( 114),
         INT8_C(  58), -INT8_C(  18),  INT8_C(  54),  INT8_C(  18), -INT8_C(  28),  INT8_C(  87), -INT8_C(   6),  INT8_C(  79),
        -INT8_C(  45),  INT8_C(   8), -INT8_C(   1),  INT8_C(   4), -INT8_C( 120),  INT8_C( 112), -INT8_C(  87),  INT8_C(  57) } },
    { {  INT8_C(  68),  INT8_C( 123), -INT8_C( 115),  INT8_C( 105),  INT8_C(  67),  INT8_C(  78),  INT8_C(  32), -INT8_C(  20),
         INT8_C( 113),  INT8_C(  74), -INT8_C(  49),  INT8_C(  25), -INT8_C(  87), -INT8_C(  60), -INT8_C(  90),  INT8_C(  96),
         INT8_C(  56), -INT8_C( 125),  INT8_C(  27), -INT8_C(  75),  INT8_C(  95), -INT8_C(  38), -INT8_C(  71), -INT8_C(  85),
         INT8_C(  66),  INT8_C(  57), -INT8_C(  28),  INT8_C(  39), -INT8_C(   4), -INT8_C(  33),  INT8_C(  77),  INT8_C(  64) },
      {  INT8_C(  90), -INT8_C(  38), -INT8_C(  87), -INT8_C(  99),  INT8_C(  41), -INT8_C(  54), -INT8_C( 119), -INT8_C( 102),
         INT8_C(  20),  INT8_C(  88), -INT8_C(  77), -INT8_C(  67),  INT8_C(  29),  INT8_C(  90),  INT8_C(  29),  INT8_C(  85),
        -INT8_C(  35),  INT8_C(  56),  INT8_C(  10),  INT8_C(  60),  INT8_C(  19), -INT8_C(  60), -INT8_C(  25),  INT8_C(  85),
        -INT8_C(   3), -INT8_C(  53),  INT8_C( 124), -INT8_C(   7), -INT8_C(  86), -INT8_C(  55),  INT8_C(  58),  INT8_C(   5) },
      UINT32_C(3450004388),
      { -INT8_C(  83),  INT8_C(  44),  INT8_C( 103), -INT8_C(  63), -INT8_C( 124),  INT8_C(  26),      INT8_MAX, -INT8_C(  95),
         INT8_C( 116), -INT8_C( 100), -INT8_C(   9),  INT8_C(  81), -INT8_C(  43),  INT8_C(   1), -INT8_C( 115), -INT8_C(  24),
        -INT8_C(  59),  INT8_C( 116),  INT8_C(  61), -INT8_C(  61),  INT8_C(  64), -INT8_C(  71), -INT8_C(  68), -INT8_C(  22),
        -INT8_C( 126), -INT8_C(  10), -INT8_C(  17),  INT8_C(  38), -INT8_C(  38), -INT8_C( 110), -INT8_C(  13), -INT8_C( 121) },
      {  INT8_C(  90), -INT8_C(  38), -INT8_C( 100), -INT8_C(  99),  INT8_C(  41), -INT8_C(  49), -INT8_C( 119), -INT8_C(  28),
         INT8_C(  95),  INT8_C(  66), -INT8_C(  77), -INT8_C(  67),  INT8_C(  29), -INT8_C(  28), -INT8_C(  33), -INT8_C(  38),
        -INT8_C(  35), -INT8_C( 126),  INT8_C(  10),  INT8_C(  60),  INT8_C(  19),  INT8_C(  67), -INT8_C(  25), -INT8_C(  38),
        -INT8_C( 110), -INT8_C(  53), -INT8_C(  38), -INT8_C(  10), -INT8_C(  86), -INT8_C(  55), -INT8_C(  17),  INT8_C(  78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_mask2_permutex2var_epi8(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask2_permutex2var_epi8(a, idx, k, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t idx[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C(1112103614),
      {  INT8_C( 117), -INT8_C(  56), -INT8_C(  28), -INT8_C(  23),  INT8_C( 100), -INT8_C(  37),  INT8_C(  59),  INT8_C(  57),
        -INT8_C(  36), -INT8_C(  56),  INT8_C(  33), -INT8_C(  94),  INT8_C(  61),  INT8_C(  94),  INT8_C( 101),  INT8_C( 125),
         INT8_C(  23),  INT8_C(  33),  INT8_C( 103), -INT8_C( 102),  INT8_C(  24),  INT8_C(  87), -INT8_C(  64), -INT8_C(  14),
        -INT8_C(  23), -INT8_C(  76),  INT8_C( 121), -INT8_C(  89),  INT8_C(  14), -INT8_C(  62), -INT8_C(  23), -INT8_C( 125) },
      { -INT8_C( 118), -INT8_C(  51),  INT8_C( 109), -INT8_C(  17), -INT8_C(  88), -INT8_C(  88),  INT8_C(  40), -INT8_C( 123),
         INT8_C( 112),  INT8_C(  74),  INT8_C(  39), -INT8_C(  83), -INT8_C(  88), -INT8_C( 116),  INT8_C(  42), -INT8_C(  64),
        -INT8_C(  83), -INT8_C( 110),  INT8_C(  90), -INT8_C(  59), -INT8_C(  23),  INT8_C(  26), -INT8_C(  73), -INT8_C(  46),
        -INT8_C(  50),  INT8_C(  49),  INT8_C( 121), -INT8_C(  35), -INT8_C(  13),  INT8_C(  98),  INT8_C(  96),  INT8_C( 126) },
      {  INT8_C(  48), -INT8_C(  51),  INT8_C( 109), -INT8_C(  40),  INT8_C( 117), -INT8_C( 107),  INT8_C(  93), -INT8_C(  26),
        -INT8_C(  33), -INT8_C( 124), -INT8_C( 109), -INT8_C( 120),  INT8_C(  16), -INT8_C(  66),  INT8_C(  72), -INT8_C(  66),
         INT8_C(  80), -INT8_C(  94), -INT8_C( 125),  INT8_C(  57), -INT8_C(  68),  INT8_C(  59),  INT8_C(  11), -INT8_C( 117),
         INT8_C( 108), -INT8_C( 124),  INT8_C( 104),  INT8_C(  95), -INT8_C(  26), -INT8_C(  56), -INT8_C(  35),  INT8_C(  22) },
      {  INT8_C(   0),  INT8_C(  94), -INT8_C(  66), -INT8_C(  66), -INT8_C(  33), -INT8_C(  33),  INT8_C(   0), -INT8_C(  37),
         INT8_C(   0),  INT8_C(  33),  INT8_C(   0), -INT8_C(  66), -INT8_C(  33),  INT8_C(   0), -INT8_C( 109),  INT8_C(   0),
        -INT8_C(  66),  INT8_C(   0),  INT8_C(   0), -INT8_C(  37),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  48),  INT8_C(   0) } },
    { UINT32_C( 200231574),
      { -INT8_C(  32),  INT8_C(  76), -INT8_C(  15), -INT8_C(  65), -INT8_C(  47), -INT8_C( 123),  INT8_C(  71), -INT8_C(  31),
         INT8_C(  67), -INT8_C( 113), -INT8_C(  97), -INT8_C( 109),  INT8_C(  49),  INT8_C(  35), -INT8_C(  52), -INT8_C(  18),
         INT8_C(  94), -INT8_C(  41),  INT8_C( 121), -INT8_C(  54),  INT8_C(  91), -INT8_C(  31),  INT8_C(  41),  INT8_C(  65),
        -INT8_C(  87),  INT8_C(   7),  INT8_C(  88),  INT8_C(  63),  INT8_C(  81),  INT8_C(  71),  INT8_C(  75),  INT8_C(  49) },
      { -INT8_C( 109),  INT8_C(  60), -INT8_C(  15),  INT8_C( 100), -INT8_C(  63),  INT8_C(  56),  INT8_C(  70),  INT8_C(   4),
        -INT8_C(  56), -INT8_C(  27), -INT8_C( 105), -INT8_C(   7),  INT8_C(   8),  INT8_C(  99), -INT8_C(  25),  INT8_C( 102),
         INT8_C(  58),  INT8_C(  96),  INT8_C(  48), -INT8_C( 107),  INT8_C(  65),  INT8_C(  90), -INT8_C(  41), -INT8_C(  21),
         INT8_C(  97),  INT8_C(  47),  INT8_C(  42), -INT8_C(  78),  INT8_C( 118),  INT8_C( 117), -INT8_C(  28),  INT8_C(   9) },
      { -INT8_C(  78), -INT8_C(  43),  INT8_C( 110),  INT8_C( 115),  INT8_C(  13), -INT8_C(  76),  INT8_C( 120), -INT8_C(  43),
        -INT8_C( 103),  INT8_C(  15), -INT8_C(  49), -INT8_C(  94),  INT8_C( 115), -INT8_C(  74),  INT8_C(   8), -INT8_C(  83),
         INT8_C(  23),  INT8_C(  57),  INT8_C(  67),  INT8_C(  88), -INT8_C( 109),  INT8_C(  26),  INT8_C(  67), -INT8_C(  12),
         INT8_C(  73),  INT8_C( 110), -INT8_C(  90), -INT8_C(  65), -INT8_C(  29), -INT8_C( 118), -INT8_C(  56), -INT8_C( 107) },
      {  INT8_C(   0), -INT8_C(  29),  INT8_C(  57),  INT8_C(   0),  INT8_C(  76),  INT8_C(   0),  INT8_C(   0), -INT8_C(  47),
         INT8_C(   0), -INT8_C(  76),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0),  INT8_C(   0), -INT8_C(  43),  INT8_C(   0),
        -INT8_C(  90), -INT8_C(  78),  INT8_C(  23), -INT8_C(  31),  INT8_C(   0),  INT8_C(  88),  INT8_C(  65), -INT8_C(  94),
        -INT8_C(  43), -INT8_C(  83),  INT8_C(   0),  INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1829320287),
      { -INT8_C(  22), -INT8_C( 127),  INT8_C(  66), -INT8_C( 124), -INT8_C( 112),  INT8_C(  17),  INT8_C(  38),  INT8_C(   3),
        -INT8_C(  56),  INT8_C(  46), -INT8_C(  79), -INT8_C(  33),  INT8_C( 103), -INT8_C(  12),  INT8_C(  55), -INT8_C(   6),
         INT8_C(  14),  INT8_C( 123), -INT8_C(  18),  INT8_C(  87), -INT8_C(  23), -INT8_C( 107),  INT8_C(  22), -INT8_C(  52),
         INT8_C(  31), -INT8_C(  34),  INT8_C(  98),      INT8_MAX,  INT8_C(  21),  INT8_C( 107), -INT8_C(  20), -INT8_C(   1) },
      { -INT8_C(  20),  INT8_C(  46), -INT8_C( 125),  INT8_C( 124),  INT8_C(  64), -INT8_C(  87),      INT8_MIN,  INT8_C(   8),
        -INT8_C(  40),  INT8_C(  49), -INT8_C(  25),  INT8_C(  63),  INT8_C(  37),  INT8_C(  30),  INT8_C(  58),  INT8_C(  51),
        -INT8_C( 103),  INT8_C(  40), -INT8_C( 118), -INT8_C( 126), -INT8_C(  67), -INT8_C(  96),  INT8_C(  79), -INT8_C(  35),
         INT8_C( 126), -INT8_C(  79),  INT8_C(  92), -INT8_C( 109),  INT8_C(  28),  INT8_C(  72), -INT8_C( 109),  INT8_C(   8) },
      {  INT8_C( 118),  INT8_C(  22), -INT8_C( 124), -INT8_C(  74), -INT8_C(  64),  INT8_C(   4), -INT8_C(  66), -INT8_C( 104),
         INT8_C(  53), -INT8_C(  91), -INT8_C(  41),  INT8_C(  90), -INT8_C(  60),  INT8_C(  17), -INT8_C( 115),  INT8_C(  93),
         INT8_C(  58),  INT8_C(  23), -INT8_C(  32), -INT8_C(   9), -INT8_C(  73),  INT8_C(  47), -INT8_C(  44),  INT8_C(  54),
        -INT8_C(  32),  INT8_C(  48), -INT8_C(  55), -INT8_C(   4),  INT8_C( 120),  INT8_C(  92),  INT8_C(   4), -INT8_C(  17) },
      { -INT8_C(  60), -INT8_C( 115), -INT8_C( 124),  INT8_C( 120), -INT8_C(  22),  INT8_C(   0), -INT8_C(  22),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  23), -INT8_C( 104),  INT8_C(   0),  INT8_C(   4), -INT8_C(  20),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  34),  INT8_C(   0),  INT8_C(   0),  INT8_C(  66),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   0),  INT8_C(  21),  INT8_C(  87),  INT8_C(   0), -INT8_C(  56),  INT8_C(  87),  INT8_C(   0) } },
    { UINT32_C( 866486387),
      { -INT8_C( 115),  INT8_C( 100), -INT8_C(  53), -INT8_C(  62),  INT8_C(   9), -INT8_C(  94),  INT8_C(  29), -INT8_C(  51),
        -INT8_C(  76), -INT8_C(  86),  INT8_C(  43), -INT8_C(  18), -INT8_C(  62),  INT8_C(  11), -INT8_C(  27),  INT8_C( 121),
         INT8_C(  58), -INT8_C(  70), -INT8_C(  81),  INT8_C(  26), -INT8_C(  22),  INT8_C( 121),  INT8_C(  22),  INT8_C(  99),
        -INT8_C(  43),  INT8_C(  26),  INT8_C(  82),  INT8_C(  72), -INT8_C(  94), -INT8_C(   9),  INT8_C( 123),  INT8_C(  47) },
      {  INT8_C(  91),  INT8_C(  70), -INT8_C(  14),  INT8_C( 101), -INT8_C(  23),  INT8_C(  15),  INT8_C(  50), -INT8_C(  99),
        -INT8_C(  71),  INT8_C(  93), -INT8_C( 117),  INT8_C( 123),  INT8_C( 104),  INT8_C( 112), -INT8_C(  11), -INT8_C(  94),
         INT8_C(  42), -INT8_C(  92), -INT8_C(  68),  INT8_C(  21),  INT8_C(  29), -INT8_C(  46),  INT8_C( 120), -INT8_C(  13),
        -INT8_C(  20), -INT8_C(  54),  INT8_C(  59), -INT8_C( 113), -INT8_C(  63), -INT8_C(  73), -INT8_C(  66),  INT8_C(  29) },
      { -INT8_C(   3), -INT8_C(  80), -INT8_C( 126), -INT8_C(  26), -INT8_C(  65), -INT8_C(  76), -INT8_C( 125),  INT8_C( 121),
         INT8_C(  18),  INT8_C(  14), -INT8_C(  12),  INT8_C( 122),      INT8_MAX, -INT8_C(  23),  INT8_C(  29), -INT8_C(  87),
        -INT8_C( 114), -INT8_C(  39), -INT8_C(  66), -INT8_C(  85), -INT8_C(  84),  INT8_C(  54), -INT8_C(  98), -INT8_C( 104),
         INT8_C(   0), -INT8_C(  38),  INT8_C(  39), -INT8_C(  62), -INT8_C( 111), -INT8_C(  26), -INT8_C(  33), -INT8_C( 114) },
      {  INT8_C(  72),  INT8_C(  29),  INT8_C(   0),  INT8_C(   0),  INT8_C(  14),  INT8_C( 121), -INT8_C(  66),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 126),
        -INT8_C(  12),  INT8_C(   0), -INT8_C( 111),  INT8_C(   0),  INT8_C(   0), -INT8_C(  81),  INT8_C(   0), -INT8_C(  85),
             INT8_MAX,  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C( 100), -INT8_C( 104),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1450533270),
      {  INT8_C(  21), -INT8_C(   8), -INT8_C(  49),  INT8_C(  39),  INT8_C(   7), -INT8_C(  61), -INT8_C(  94), -INT8_C( 122),
        -INT8_C(  83), -INT8_C(  65),  INT8_C(  47),  INT8_C(  59), -INT8_C( 104), -INT8_C(  18), -INT8_C(  26),  INT8_C(  68),
         INT8_C(  36), -INT8_C( 123), -INT8_C(  35),  INT8_C(  37),  INT8_C(  95),  INT8_C(   4), -INT8_C(  25), -INT8_C(  16),
        -INT8_C(  22), -INT8_C(  58),  INT8_C( 126), -INT8_C( 127),  INT8_C(  39), -INT8_C(  13), -INT8_C(  41),  INT8_C(  60) },
      { -INT8_C(  20), -INT8_C(  90),  INT8_C( 100), -INT8_C(  13),  INT8_C( 105),  INT8_C(   6),  INT8_C( 121),  INT8_C(  22),
        -INT8_C(  59), -INT8_C(  88),  INT8_C(  81),  INT8_C(  93), -INT8_C( 106),  INT8_C(  56), -INT8_C(  94), -INT8_C(  69),
        -INT8_C(  67),      INT8_MAX, -INT8_C(  32),  INT8_C(  28), -INT8_C( 125), -INT8_C(  57),  INT8_C(  12),  INT8_C( 110),
        -INT8_C( 115), -INT8_C( 118), -INT8_C(  17), -INT8_C(  76),  INT8_C( 126), -INT8_C(  58), -INT8_C(  16),  INT8_C( 106) },
      {  INT8_C( 108),  INT8_C(  84),  INT8_C(  93), -INT8_C(  43),  INT8_C(  90), -INT8_C(  42), -INT8_C(  20),  INT8_C(  31),
         INT8_C( 126),  INT8_C(  61),  INT8_C( 125),  INT8_C(  21),  INT8_C( 117),  INT8_C(  31), -INT8_C(  48),  INT8_C(  50),
        -INT8_C(  98), -INT8_C(  80),  INT8_C(  78),  INT8_C(  33),  INT8_C( 119),  INT8_C(  90), -INT8_C( 113),  INT8_C(   4),
        -INT8_C(  27),  INT8_C( 126), -INT8_C(  72),  INT8_C(  99),  INT8_C(  68), -INT8_C(  88), -INT8_C(  51), -INT8_C(  80) },
      {  INT8_C(   0), -INT8_C(  20),  INT8_C(  90),  INT8_C(   0),  INT8_C(  61),  INT8_C(   0),  INT8_C(   0), -INT8_C(  25),
        -INT8_C(  61),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  27),  INT8_C(  93),  INT8_C(   0),
        -INT8_C(  88),  INT8_C(   0),  INT8_C( 108),  INT8_C(   0),  INT8_C(  39), -INT8_C( 122), -INT8_C( 104),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  47),  INT8_C(  50),  INT8_C(   0), -INT8_C(  51),  INT8_C(   0), -INT8_C(  98),  INT8_C(   0) } },
    { UINT32_C(1468410621),
      {  INT8_C(   0),  INT8_C( 114),  INT8_C( 119),  INT8_C( 126), -INT8_C(  81), -INT8_C(  12), -INT8_C( 109),  INT8_C(  37),
         INT8_C(  19),  INT8_C(  99),  INT8_C(  87), -INT8_C(  79),  INT8_C(  19), -INT8_C(  90), -INT8_C(  46), -INT8_C( 118),
         INT8_C(   0),  INT8_C(  98), -INT8_C( 114), -INT8_C(  27), -INT8_C(  32),  INT8_C(  70),  INT8_C(  72),  INT8_C(  37),
        -INT8_C(  17),  INT8_C(  21), -INT8_C(  43), -INT8_C(  20),  INT8_C(  63),  INT8_C(  91),  INT8_C(  67),  INT8_C(  63) },
      { -INT8_C(  51), -INT8_C(  70), -INT8_C(  66),  INT8_C( 125), -INT8_C(  82),  INT8_C(  81), -INT8_C(  94), -INT8_C(  63),
        -INT8_C(  75), -INT8_C(   7),  INT8_C( 114), -INT8_C(  56), -INT8_C(  97),  INT8_C(  69),  INT8_C(  83), -INT8_C(  96),
        -INT8_C(  89), -INT8_C(  31), -INT8_C( 123), -INT8_C( 121),  INT8_C(  40), -INT8_C(  50), -INT8_C(  84),  INT8_C(  23),
        -INT8_C(  29), -INT8_C( 126),  INT8_C(   3),  INT8_C(  35), -INT8_C(  35),  INT8_C(  70),  INT8_C(  98), -INT8_C(  85) },
      {  INT8_C(   1),  INT8_C(  32),  INT8_C(  40), -INT8_C(  81),  INT8_C( 114), -INT8_C(  54),  INT8_C( 113),  INT8_C(  39),
        -INT8_C(  61), -INT8_C(  29), -INT8_C(  17),  INT8_C(  99),  INT8_C(  40),  INT8_C(  66),  INT8_C(   3), -INT8_C(  49),
         INT8_C(  36), -INT8_C( 120),  INT8_C(  87),  INT8_C(  76),  INT8_C(  86),  INT8_C(   3),  INT8_C(  99),  INT8_C(  58),
        -INT8_C( 123),  INT8_C( 102),  INT8_C(  93),  INT8_C(  99), -INT8_C(  84), -INT8_C(  65),  INT8_C(  14), -INT8_C(  83) },
      { -INT8_C(  90),  INT8_C(   0),  INT8_C(  14), -INT8_C(  65),  INT8_C(   3),  INT8_C(  98),  INT8_C(  40),  INT8_C( 114),
         INT8_C(   0),  INT8_C( 102),  INT8_C(   0),  INT8_C(  19),  INT8_C(   0), -INT8_C(  12),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  32), -INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  37),
        -INT8_C(  81),  INT8_C( 119),  INT8_C( 126),  INT8_C(   0),  INT8_C(  91),  INT8_C(   0),  INT8_C(  40),  INT8_C(   0) } },
    { UINT32_C(1381840608),
      {  INT8_C(   0), -INT8_C(  50),  INT8_C( 121), -INT8_C(  61), -INT8_C(  79),  INT8_C( 104),  INT8_C(  38), -INT8_C(  38),
        -INT8_C(  85),  INT8_C(  41), -INT8_C(  87), -INT8_C(  49), -INT8_C(  78),  INT8_C(   0),  INT8_C(  27),  INT8_C(   8),
         INT8_C(   4),  INT8_C( 126),  INT8_C(  66), -INT8_C( 119), -INT8_C(  28), -INT8_C(  97), -INT8_C(  20), -INT8_C( 112),
         INT8_C(  95), -INT8_C(   6),  INT8_C(  62),  INT8_C(  63),  INT8_C(  48), -INT8_C( 101), -INT8_C( 111),  INT8_C(  48) },
      {  INT8_C( 105),  INT8_C(  10), -INT8_C(  12),  INT8_C(  26),  INT8_C( 114),  INT8_C(  26), -INT8_C(  12),  INT8_C(  29),
         INT8_C(  68), -INT8_C(  98), -INT8_C(  20), -INT8_C(  10), -INT8_C(  98),  INT8_C(   7), -INT8_C(   2), -INT8_C(  94),
        -INT8_C( 123),  INT8_C(  65),  INT8_C(  44),  INT8_C( 105), -INT8_C(  32),  INT8_C(  24), -INT8_C(   6),  INT8_C(  63),
         INT8_C(  19),  INT8_C(  56),  INT8_C( 126),  INT8_C(  67), -INT8_C(  45),  INT8_C(  15),  INT8_C( 116),  INT8_C(  60) },
      {  INT8_C(  25),  INT8_C( 104),  INT8_C(  86), -INT8_C( 116), -INT8_C( 126),  INT8_C(  75), -INT8_C(  87), -INT8_C(  58),
        -INT8_C(  23), -INT8_C( 106), -INT8_C(  68), -INT8_C( 121), -INT8_C(  99), -INT8_C(  69),  INT8_C(  42),  INT8_C(  35),
        -INT8_C(   4),  INT8_C(  86), -INT8_C( 116), -INT8_C(  36),  INT8_C( 110), -INT8_C( 122),  INT8_C(  28), -INT8_C( 127),
        -INT8_C(  66), -INT8_C( 102), -INT8_C(  59), -INT8_C( 111), -INT8_C(  86),  INT8_C(  57), -INT8_C(  51), -INT8_C(  61) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  62),  INT8_C( 110), -INT8_C( 101),
         INT8_C(   0), -INT8_C( 111), -INT8_C(  99),  INT8_C(   0), -INT8_C( 111), -INT8_C(  38),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 104),  INT8_C(   0), -INT8_C(  99), -INT8_C( 106),  INT8_C(  25),  INT8_C(   0), -INT8_C(  59),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  66),  INT8_C(   0),  INT8_C(   0), -INT8_C( 119),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0) } },
    { UINT32_C( 592389281),
      {  INT8_C( 111), -INT8_C(   7), -INT8_C(  22),  INT8_C(  88), -INT8_C( 113), -INT8_C(  90), -INT8_C(  33),  INT8_C(  44),
         INT8_C(  97),  INT8_C(   9),  INT8_C(  79),  INT8_C(  93),  INT8_C(  95), -INT8_C(  36),  INT8_C(  58), -INT8_C(  50),
         INT8_C(  98),  INT8_C(  86),  INT8_C(  79),  INT8_C(  33), -INT8_C(  16),  INT8_C(  20), -INT8_C(  78), -INT8_C( 102),
         INT8_C(  77),      INT8_MIN,  INT8_C(  94), -INT8_C(  18), -INT8_C(  92), -INT8_C(  83),  INT8_C(  18),  INT8_C(  19) },
      { -INT8_C(  90), -INT8_C(   4),  INT8_C( 107),  INT8_C(  53), -INT8_C(  94),  INT8_C(  74),  INT8_C(  98),  INT8_C(   4),
         INT8_C(  84), -INT8_C(  79),  INT8_C(  97), -INT8_C(  77), -INT8_C( 115), -INT8_C( 101), -INT8_C( 127), -INT8_C(  16),
        -INT8_C(  15), -INT8_C(  47),  INT8_C(  17), -INT8_C(  30), -INT8_C(  27), -INT8_C(  61),  INT8_C( 124),  INT8_C(  51),
         INT8_C(  67), -INT8_C(  38),  INT8_C(  33), -INT8_C(  25), -INT8_C( 120),  INT8_C(  51), -INT8_C(   6),  INT8_C(  46) },
      {  INT8_C(  47),  INT8_C( 101),  INT8_C( 100), -INT8_C(  46), -INT8_C(  80), -INT8_C(  58), -INT8_C(  42),  INT8_C(   4),
         INT8_C( 119),  INT8_C(  55), -INT8_C(  73),  INT8_C(   5), -INT8_C(  45),  INT8_C(  57), -INT8_C(  11), -INT8_C(  60),
         INT8_C(  10),  INT8_C(   6), -INT8_C(  90), -INT8_C(  17), -INT8_C(  55),  INT8_C(  35),  INT8_C(  34),  INT8_C(  13),
        -INT8_C(   3),  INT8_C(  68), -INT8_C(  12), -INT8_C( 123),  INT8_C( 119), -INT8_C(  17), -INT8_C(  76), -INT8_C(  89) },
      { -INT8_C(  42),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  79),  INT8_C(   0), -INT8_C( 113),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 101),  INT8_C(   0),  INT8_C(   0), -INT8_C(  18),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   6),  INT8_C(  86),  INT8_C(  86),  INT8_C( 100),  INT8_C(   0),  INT8_C(   0),  INT8_C( 119),  INT8_C(   0),
         INT8_C(  88),  INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi8(test_vec[i].idx);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_permutex2var_epi8(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i idx = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_maskz_permutex2var_epi8(k, a, idx, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 a[4];
    const int64_t idx[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   653.52), SIMDE_FLOAT64_C(    37.34), SIMDE_FLOAT64_C(  -869.77), SIMDE_FLOAT64_C(   249.43) },
      { -INT64_C( 1249660299835300958), -INT64_C( 6783122132230687666),  INT64_C( 8762372594894733093),  INT64_C( 2397211869628714028) },
      { SIMDE_FLOAT64_C(  -550.23), SIMDE_FLOAT64_C(   836.05), SIMDE_FLOAT64_C(  -350.30), SIMDE_FLOAT64_C(  -131.37) },
      { SIMDE_FLOAT64_C(  -869.77), SIMDE_FLOAT64_C(  -350.30), SIMDE_FLOAT64_C(   836.05), SIMDE_FLOAT64_C(  -550.23) } },
    { { SIMDE_FLOAT64_C(  -919.01), SIMDE_FLOAT64_C(  -940.91), SIMDE_FLOAT64_C(   697.78), SIMDE_FLOAT64_C(  -496.83) },
      { -INT64_C( 5439186647591482232),  INT64_C( 3786545457428747679), -INT64_C(  653289433062695601),  INT64_C( 8574723873881791160) },
      { SIMDE_FLOAT64_C(   431.03), SIMDE_FLOAT64_C(  -983.72), SIMDE_FLOAT64_C(   -53.49), SIMDE_FLOAT64_C(  -124.98) },
      { SIMDE_FLOAT64_C(  -919.01), SIMDE_FLOAT64_C(  -124.98), SIMDE_FLOAT64_C(  -124.98), SIMDE_FLOAT64_C(  -919.01) } },
    { { SIMDE_FLOAT64_C(   487.29), SIMDE_FLOAT64_C(  -601.59), SIMDE_FLOAT64_C(   255.35), SIMDE_FLOAT64_C(   815.21) },
      { -INT64_C( 7715051790792277326),  INT64_C( 8965630858134468542),  INT64_C( 6183777361766462828), -INT64_C( 4983423165255767437) },
      { SIMDE_FLOAT64_C(  -811.29), SIMDE_FLOAT64_C(   642.31), SIMDE_FLOAT64_C(   802.34), SIMDE_FLOAT64_C(   362.56) },
      { SIMDE_FLOAT64_C(   255.35), SIMDE_FLOAT64_C(   802.34), SIMDE_FLOAT64_C(  -811.29), SIMDE_FLOAT64_C(   815.21) } },
    { { SIMDE_FLOAT64_C(  -225.44), SIMDE_FLOAT64_C(   766.27), SIMDE_FLOAT64_C(  -341.10), SIMDE_FLOAT64_C(  -245.01) },
      {  INT64_C( 1106247939824636186),  INT64_C( 3348209423383890787),  INT64_C( 6496402078733496677),  INT64_C( 1918995237581462728) },
      { SIMDE_FLOAT64_C(  -669.64), SIMDE_FLOAT64_C(  -902.85), SIMDE_FLOAT64_C(  -323.30), SIMDE_FLOAT64_C(   455.88) },
      { SIMDE_FLOAT64_C(  -341.10), SIMDE_FLOAT64_C(  -245.01), SIMDE_FLOAT64_C(  -902.85), SIMDE_FLOAT64_C(  -225.44) } },
    { { SIMDE_FLOAT64_C(   416.46), SIMDE_FLOAT64_C(    73.37), SIMDE_FLOAT64_C(   -22.74), SIMDE_FLOAT64_C(  -361.93) },
      { -INT64_C( 5708437547326762531),  INT64_C( 8007195249340173183),  INT64_C( 7925321014123484385),  INT64_C( 2615656005526549704) },
      { SIMDE_FLOAT64_C(   543.78), SIMDE_FLOAT64_C(   -89.88), SIMDE_FLOAT64_C(   339.30), SIMDE_FLOAT64_C(  -527.65) },
      { SIMDE_FLOAT64_C(   -89.88), SIMDE_FLOAT64_C(  -527.65), SIMDE_FLOAT64_C(    73.37), SIMDE_FLOAT64_C(   416.46) } },
    { { SIMDE_FLOAT64_C(  -668.42), SIMDE_FLOAT64_C(   629.47), SIMDE_FLOAT64_C(   346.35), SIMDE_FLOAT64_C(   620.84) },
      { -INT64_C(  115312252773083056),  INT64_C( 6344969963767343912),  INT64_C( 9168481947187483600), -INT64_C( 3476140653052036768) },
      { SIMDE_FLOAT64_C(   -79.85), SIMDE_FLOAT64_C(  -613.21), SIMDE_FLOAT64_C(   554.92), SIMDE_FLOAT64_C(   759.78) },
      { SIMDE_FLOAT64_C(  -668.42), SIMDE_FLOAT64_C(  -668.42), SIMDE_FLOAT64_C(  -668.42), SIMDE_FLOAT64_C(  -668.42) } },
    { { SIMDE_FLOAT64_C(   971.65), SIMDE_FLOAT64_C(   672.93), SIMDE_FLOAT64_C(  -151.29), SIMDE_FLOAT64_C(   782.54) },
      { -INT64_C( 4305123536846776488),  INT64_C( 5797284939722125876),  INT64_C( 6799981624904777233), -INT64_C( 6189970833459960486) },
      { SIMDE_FLOAT64_C(  -861.21), SIMDE_FLOAT64_C(  -653.94), SIMDE_FLOAT64_C(   293.52), SIMDE_FLOAT64_C(  -423.18) },
      { SIMDE_FLOAT64_C(   971.65), SIMDE_FLOAT64_C(  -861.21), SIMDE_FLOAT64_C(   672.93), SIMDE_FLOAT64_C(  -151.29) } },
    { { SIMDE_FLOAT64_C(  -413.93), SIMDE_FLOAT64_C(    60.42), SIMDE_FLOAT64_C(  -250.99), SIMDE_FLOAT64_C(   258.92) },
      { -INT64_C( 6843807250990663227),  INT64_C( 7243915799452296935), -INT64_C( 3193013734401761612), -INT64_C( 2586673575026212018) },
      { SIMDE_FLOAT64_C(   961.25), SIMDE_FLOAT64_C(   165.72), SIMDE_FLOAT64_C(  -922.46), SIMDE_FLOAT64_C(   131.70) },
      { SIMDE_FLOAT64_C(   165.72), SIMDE_FLOAT64_C(   131.70), SIMDE_FLOAT64_C(   961.25), SIMDE_FLOAT64_C(  -922.46) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_permutex2var_pd(a, idx, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_permutex2var_pd(a, idx, b);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 a[4];
    const simde__mmask8 k;
    const int64_t idx[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   408.46), SIMDE_FLOAT64_C(  -602.21), SIMDE_FLOAT64_C(   -10.41), SIMDE_FLOAT64_C(   978.30) },
      UINT8_C( 60),
      {  INT64_C( 3416731359858034982),  INT64_C( 7216436906553012405),  INT64_C( 7541654544883302300),  INT64_C( 1709751513995410663) },
      { SIMDE_FLOAT64_C(  -397.99), SIMDE_FLOAT64_C(  -628.51), SIMDE_FLOAT64_C(   977.27), SIMDE_FLOAT64_C(   803.25) },
      { SIMDE_FLOAT64_C(   408.46), SIMDE_FLOAT64_C(  -602.21), SIMDE_FLOAT64_C(  -397.99), SIMDE_FLOAT64_C(   803.25) } },
    { { SIMDE_FLOAT64_C(   542.89), SIMDE_FLOAT64_C(    82.07), SIMDE_FLOAT64_C(  -662.48), SIMDE_FLOAT64_C(   808.21) },
      UINT8_C(167),
      {  INT64_C( 2140103026273695783),  INT64_C( 4532133341351549351),  INT64_C( 2110859038105297472),  INT64_C( 6481569584712787732) },
      { SIMDE_FLOAT64_C(  -276.74), SIMDE_FLOAT64_C(  -885.51), SIMDE_FLOAT64_C(   201.17), SIMDE_FLOAT64_C(  -557.48) },
      { SIMDE_FLOAT64_C(  -557.48), SIMDE_FLOAT64_C(  -557.48), SIMDE_FLOAT64_C(   542.89), SIMDE_FLOAT64_C(   808.21) } },
    { { SIMDE_FLOAT64_C(   249.98), SIMDE_FLOAT64_C(   630.88), SIMDE_FLOAT64_C(  -260.35), SIMDE_FLOAT64_C(   653.16) },
      UINT8_C(188),
      { -INT64_C( 3138659908921160494),  INT64_C( 7262350432791491181), -INT64_C( 4368227721405917994), -INT64_C( 3728915643820728736) },
      { SIMDE_FLOAT64_C(    90.23), SIMDE_FLOAT64_C(   801.44), SIMDE_FLOAT64_C(   328.73), SIMDE_FLOAT64_C(  -572.13) },
      { SIMDE_FLOAT64_C(   249.98), SIMDE_FLOAT64_C(   630.88), SIMDE_FLOAT64_C(   328.73), SIMDE_FLOAT64_C(   249.98) } },
    { { SIMDE_FLOAT64_C(  -158.58), SIMDE_FLOAT64_C(  -452.42), SIMDE_FLOAT64_C(   522.14), SIMDE_FLOAT64_C(  -149.14) },
      UINT8_C( 96),
      {  INT64_C( 8926137098736344572),  INT64_C( 6767016054276415384), -INT64_C( 1373277184724603408),  INT64_C( 3597902442779912480) },
      { SIMDE_FLOAT64_C(   404.05), SIMDE_FLOAT64_C(   374.29), SIMDE_FLOAT64_C(   776.88), SIMDE_FLOAT64_C(  -254.86) },
      { SIMDE_FLOAT64_C(  -158.58), SIMDE_FLOAT64_C(  -452.42), SIMDE_FLOAT64_C(   522.14), SIMDE_FLOAT64_C(  -149.14) } },
    { { SIMDE_FLOAT64_C(   453.36), SIMDE_FLOAT64_C(  -266.79), SIMDE_FLOAT64_C(   626.35), SIMDE_FLOAT64_C(  -321.54) },
      UINT8_C(250),
      {  INT64_C(  399016723643739987), -INT64_C( 3660688020061637650),  INT64_C( 4271722174278189319), -INT64_C( 4501927894904627857) },
      { SIMDE_FLOAT64_C(   510.82), SIMDE_FLOAT64_C(  -911.97), SIMDE_FLOAT64_C(  -156.49), SIMDE_FLOAT64_C(     3.35) },
      { SIMDE_FLOAT64_C(   453.36), SIMDE_FLOAT64_C(  -156.49), SIMDE_FLOAT64_C(   626.35), SIMDE_FLOAT64_C(     3.35) } },
    { { SIMDE_FLOAT64_C(  -104.93), SIMDE_FLOAT64_C(   203.31), SIMDE_FLOAT64_C(   -83.08), SIMDE_FLOAT64_C(  -818.74) },
      UINT8_C(150),
      {  INT64_C( 5374211117209507566), -INT64_C( 3193556578658030070),  INT64_C( 9046890245521488382), -INT64_C( 1165280014248983460) },
      { SIMDE_FLOAT64_C(  -241.97), SIMDE_FLOAT64_C(   998.95), SIMDE_FLOAT64_C(   954.06), SIMDE_FLOAT64_C(  -258.08) },
      { SIMDE_FLOAT64_C(  -104.93), SIMDE_FLOAT64_C(   -83.08), SIMDE_FLOAT64_C(   954.06), SIMDE_FLOAT64_C(  -818.74) } },
    { { SIMDE_FLOAT64_C(  -767.52), SIMDE_FLOAT64_C(  -830.63), SIMDE_FLOAT64_C(   118.56), SIMDE_FLOAT64_C(   309.23) },
         UINT8_MAX,
      {  INT64_C( 5147061381747793979), -INT64_C( 5788950803670278838), -INT64_C( 3756671982009063594),  INT64_C( 5849053409824658459) },
      { SIMDE_FLOAT64_C(   669.56), SIMDE_FLOAT64_C(  -178.67), SIMDE_FLOAT64_C(   767.90), SIMDE_FLOAT64_C(   281.87) },
      { SIMDE_FLOAT64_C(   309.23), SIMDE_FLOAT64_C(   118.56), SIMDE_FLOAT64_C(   767.90), SIMDE_FLOAT64_C(   309.23) } },
    { { SIMDE_FLOAT64_C(   -48.74), SIMDE_FLOAT64_C(   874.09), SIMDE_FLOAT64_C(  -369.38), SIMDE_FLOAT64_C(   530.18) },
      UINT8_C(140),
      { -INT64_C( 7883790105709182274), -INT64_C( 5219924978399574315),  INT64_C( 5287822894264335355),  INT64_C( 5376005530964972767) },
      { SIMDE_FLOAT64_C(  -103.84), SIMDE_FLOAT64_C(  -761.48), SIMDE_FLOAT64_C(   439.85), SIMDE_FLOAT64_C(  -949.21) },
      { SIMDE_FLOAT64_C(   -48.74), SIMDE_FLOAT64_C(   874.09), SIMDE_FLOAT64_C(   530.18), SIMDE_FLOAT64_C(  -949.21) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_mask_permutex2var_pd(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask_permutex2var_pd(a, k, idx, b);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask2_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float64 a[4];
    const int64_t idx[4];
    const simde__mmask8 k;
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   601.13), SIMDE_FLOAT64_C(  -769.86), SIMDE_FLOAT64_C(  -702.22), SIMDE_FLOAT64_C(   615.42) },
      {  INT64_C( 4642678524425556460),  INT64_C( 4647447238296616305),  INT64_C( 4629981891913580544),  INT64_C( 4642297477675834409) },
      UINT8_C( 16),
      { SIMDE_FLOAT64_C(   810.92), SIMDE_FLOAT64_C(   -60.42), SIMDE_FLOAT64_C(   -19.80), SIMDE_FLOAT64_C(  -884.45) },
      { SIMDE_FLOAT64_C(   240.86), SIMDE_FLOAT64_C(   496.79), SIMDE_FLOAT64_C(    34.00), SIMDE_FLOAT64_C(   230.03) } },
    { { SIMDE_FLOAT64_C(   488.07), SIMDE_FLOAT64_C(  -193.68), SIMDE_FLOAT64_C(    58.80), SIMDE_FLOAT64_C(   417.59) },
      { -INT64_C( 4574021060145363026), -INT64_C( 4582953756492205916),  INT64_C( 4637794933579626578),  INT64_C( 4635296843161319506) },
      UINT8_C(176),
      { SIMDE_FLOAT64_C(  -313.45), SIMDE_FLOAT64_C(  -512.31), SIMDE_FLOAT64_C(   785.24), SIMDE_FLOAT64_C(  -489.28) },
      { SIMDE_FLOAT64_C(  -698.01), SIMDE_FLOAT64_C(  -176.62), SIMDE_FLOAT64_C(   115.03), SIMDE_FLOAT64_C(    79.53) } },
    { { SIMDE_FLOAT64_C(  -965.74), SIMDE_FLOAT64_C(  -318.60), SIMDE_FLOAT64_C(  -250.76), SIMDE_FLOAT64_C(   474.11) },
      { -INT64_C( 4579953057318609879), -INT64_C( 4574446615125777449),  INT64_C( 4649405864329871360),  INT64_C( 4629129022734147256) },
      UINT8_C(146),
      { SIMDE_FLOAT64_C(   -54.89), SIMDE_FLOAT64_C(  -473.24), SIMDE_FLOAT64_C(    -0.21), SIMDE_FLOAT64_C(  -824.86) },
      { SIMDE_FLOAT64_C(  -267.81), SIMDE_FLOAT64_C(  -824.86), SIMDE_FLOAT64_C(   704.25), SIMDE_FLOAT64_C(    29.97) } },
    { { SIMDE_FLOAT64_C(  -826.47), SIMDE_FLOAT64_C(  -189.29), SIMDE_FLOAT64_C(   114.72), SIMDE_FLOAT64_C(   153.74) },
      { -INT64_C( 4588482628722244977), -INT64_C( 4577676452522602004),  INT64_C( 4651655904924952166),  INT64_C( 4651875895211437588) },
         UINT8_MAX,
      { SIMDE_FLOAT64_C(  -737.96), SIMDE_FLOAT64_C(  -191.56), SIMDE_FLOAT64_C(   135.40), SIMDE_FLOAT64_C(   341.57) },
      { SIMDE_FLOAT64_C(   341.57), SIMDE_FLOAT64_C(  -737.96), SIMDE_FLOAT64_C(   135.40), SIMDE_FLOAT64_C(  -737.96) } },
    { { SIMDE_FLOAT64_C(  -652.34), SIMDE_FLOAT64_C(   821.95), SIMDE_FLOAT64_C(   829.26), SIMDE_FLOAT64_C(  -867.09) },
      { -INT64_C( 4574290924279284367),  INT64_C( 4650806818065518428), -INT64_C( 4582634634237360210),  INT64_C( 4635464320772462346) },
      UINT8_C(148),
      { SIMDE_FLOAT64_C(   546.50), SIMDE_FLOAT64_C(   432.28), SIMDE_FLOAT64_C(    41.87), SIMDE_FLOAT64_C(  -423.53) },
      { SIMDE_FLOAT64_C(  -667.33), SIMDE_FLOAT64_C(   863.52), SIMDE_FLOAT64_C(    41.87), SIMDE_FLOAT64_C(    81.91) } },
    { { SIMDE_FLOAT64_C(   398.07), SIMDE_FLOAT64_C(   986.98), SIMDE_FLOAT64_C(   103.23), SIMDE_FLOAT64_C(  -602.14) },
      { -INT64_C( 4572790662653416571),  INT64_C( 4643576429601263452),  INT64_C( 4641542421050808074),  INT64_C( 4643577661054286561) },
      UINT8_C(156),
      { SIMDE_FLOAT64_C(  -865.17), SIMDE_FLOAT64_C(   879.61), SIMDE_FLOAT64_C(  -609.45), SIMDE_FLOAT64_C(  -880.11) },
      { SIMDE_FLOAT64_C(  -837.89), SIMDE_FLOAT64_C(   276.76), SIMDE_FLOAT64_C(   103.23), SIMDE_FLOAT64_C(   986.98) } },
    { { SIMDE_FLOAT64_C(   899.99), SIMDE_FLOAT64_C(  -347.41), SIMDE_FLOAT64_C(   -71.66), SIMDE_FLOAT64_C(    35.39) },
      {  INT64_C( 4651955939657939681),  INT64_C( 4643563059539869696), -INT64_C( 4584148969612063539),  INT64_C( 4650454094735327887) },
      UINT8_C(254),
      { SIMDE_FLOAT64_C(   190.02), SIMDE_FLOAT64_C(   686.93), SIMDE_FLOAT64_C(  -776.79), SIMDE_FLOAT64_C(  -728.07) },
      { SIMDE_FLOAT64_C(   994.16), SIMDE_FLOAT64_C(   899.99), SIMDE_FLOAT64_C(   686.93), SIMDE_FLOAT64_C(  -728.07) } },
    { { SIMDE_FLOAT64_C(    24.56), SIMDE_FLOAT64_C(   769.71), SIMDE_FLOAT64_C(   704.21), SIMDE_FLOAT64_C(  -933.57) },
      { -INT64_C( 4574409759496014397),  INT64_C( 4636897028403919585), -INT64_C( 4571834527341902561),  INT64_C( 4646613896443692319) },
      UINT8_C(  4),
      { SIMDE_FLOAT64_C(  -784.48), SIMDE_FLOAT64_C(  -273.82), SIMDE_FLOAT64_C(  -291.30), SIMDE_FLOAT64_C(   492.35) },
      { SIMDE_FLOAT64_C(  -653.82), SIMDE_FLOAT64_C(   102.27), SIMDE_FLOAT64_C(   492.35), SIMDE_FLOAT64_C(   449.42) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_mask2_permutex2var_pd(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i idx = simde_mm256_castpd_si256(simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask2_permutex2var_pd(a, idx, k, b);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const int64_t idx[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C( 39),
      { SIMDE_FLOAT64_C(  -156.47), SIMDE_FLOAT64_C(   371.97), SIMDE_FLOAT64_C(   547.23), SIMDE_FLOAT64_C(   -36.58) },
      {  INT64_C( 6753824616870176200), -INT64_C( 5347421650059644827), -INT64_C( 2766651298058335315), -INT64_C(  829751754638706200) },
      { SIMDE_FLOAT64_C(   995.09), SIMDE_FLOAT64_C(   340.65), SIMDE_FLOAT64_C(   507.87), SIMDE_FLOAT64_C(  -810.93) },
      { SIMDE_FLOAT64_C(  -156.47), SIMDE_FLOAT64_C(   340.65), SIMDE_FLOAT64_C(   340.65), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(185),
      { SIMDE_FLOAT64_C(  -327.43), SIMDE_FLOAT64_C(  -793.54), SIMDE_FLOAT64_C(    85.07), SIMDE_FLOAT64_C(    27.28) },
      {  INT64_C( 5107248257967419662), -INT64_C( 5387029748258741901), -INT64_C( 1110745756586663315),  INT64_C( 8528066622377250933) },
      { SIMDE_FLOAT64_C(  -253.49), SIMDE_FLOAT64_C(   895.28), SIMDE_FLOAT64_C(   811.24), SIMDE_FLOAT64_C(   201.04) },
      { SIMDE_FLOAT64_C(   811.24), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   895.28) } },
    { UINT8_C(210),
      { SIMDE_FLOAT64_C(   246.22), SIMDE_FLOAT64_C(  -428.67), SIMDE_FLOAT64_C(   297.94), SIMDE_FLOAT64_C(   529.93) },
      { -INT64_C(  493534658799625651), -INT64_C( 7293148268721621634),  INT64_C( 3256516990520695089), -INT64_C( 6082316498808888030) },
      { SIMDE_FLOAT64_C(  -631.46), SIMDE_FLOAT64_C(  -104.08), SIMDE_FLOAT64_C(   913.70), SIMDE_FLOAT64_C(  -989.30) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   913.70), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 27),
      { SIMDE_FLOAT64_C(  -877.75), SIMDE_FLOAT64_C(  -868.59), SIMDE_FLOAT64_C(  -706.07), SIMDE_FLOAT64_C(   200.96) },
      {  INT64_C( 5764647894897061190), -INT64_C( 3476374108990408410), -INT64_C( 8965583818938487441),  INT64_C( 4542505815359047998) },
      { SIMDE_FLOAT64_C(  -607.72), SIMDE_FLOAT64_C(  -219.18), SIMDE_FLOAT64_C(    53.42), SIMDE_FLOAT64_C(  -473.84) },
      { SIMDE_FLOAT64_C(    53.42), SIMDE_FLOAT64_C(    53.42), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    53.42) } },
    { UINT8_C(185),
      { SIMDE_FLOAT64_C(   642.03), SIMDE_FLOAT64_C(  -935.14), SIMDE_FLOAT64_C(   326.35), SIMDE_FLOAT64_C(  -815.01) },
      { -INT64_C( 5958543503365406865), -INT64_C( 2286080838041795794), -INT64_C( 5750507269739966252), -INT64_C( 6036713302604050651) },
      { SIMDE_FLOAT64_C(   166.43), SIMDE_FLOAT64_C(  -281.36), SIMDE_FLOAT64_C(  -331.66), SIMDE_FLOAT64_C(   400.53) },
      { SIMDE_FLOAT64_C(   400.53), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -281.36) } },
    { UINT8_C(107),
      { SIMDE_FLOAT64_C(  -207.66), SIMDE_FLOAT64_C(   197.53), SIMDE_FLOAT64_C(   486.60), SIMDE_FLOAT64_C(   783.69) },
      { -INT64_C(  544841097366101657), -INT64_C( 4725186751456117714),  INT64_C( 4845776272224919341),  INT64_C( 7271985175501621042) },
      { SIMDE_FLOAT64_C(  -819.08), SIMDE_FLOAT64_C(  -481.47), SIMDE_FLOAT64_C(  -484.90), SIMDE_FLOAT64_C(   165.06) },
      { SIMDE_FLOAT64_C(   165.06), SIMDE_FLOAT64_C(  -484.90), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   486.60) } },
    { UINT8_C(181),
      { SIMDE_FLOAT64_C(   -44.60), SIMDE_FLOAT64_C(   489.25), SIMDE_FLOAT64_C(  -660.13), SIMDE_FLOAT64_C(   854.87) },
      {  INT64_C( 3876854457221982941), -INT64_C( 3878072601808059307), -INT64_C( 8777749705325593601), -INT64_C( 6374809217983053781) },
      { SIMDE_FLOAT64_C(   679.12), SIMDE_FLOAT64_C(    77.15), SIMDE_FLOAT64_C(  -278.01), SIMDE_FLOAT64_C(   -26.22) },
      { SIMDE_FLOAT64_C(    77.15), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -26.22), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(125),
      { SIMDE_FLOAT64_C(  -694.07), SIMDE_FLOAT64_C(   582.10), SIMDE_FLOAT64_C(   116.74), SIMDE_FLOAT64_C(   634.71) },
      {  INT64_C( 4068059970956742180), -INT64_C( 1457506108626191506),  INT64_C(  904199777799200801), -INT64_C( 6336181479927091805) },
      { SIMDE_FLOAT64_C(  -926.60), SIMDE_FLOAT64_C(   256.82), SIMDE_FLOAT64_C(  -405.58), SIMDE_FLOAT64_C(  -741.28) },
      { SIMDE_FLOAT64_C(  -926.60), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   582.10), SIMDE_FLOAT64_C(   634.71) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi64(test_vec[i].idx);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_maskz_permutex2var_pd(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i idx = simde_test_x86_random_i64x4();
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_maskz_permutex2var_pd(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float32 a[8];
    const int32_t idx[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -687.18), SIMDE_FLOAT32_C(  -361.35), SIMDE_FLOAT32_C(   960.68), SIMDE_FLOAT32_C(  -862.21),
        SIMDE_FLOAT32_C(   644.38), SIMDE_FLOAT32_C(   382.40), SIMDE_FLOAT32_C(  -700.96), SIMDE_FLOAT32_C(   517.36) },
      {  INT32_C(   808957085),  INT32_C(    35976047), -INT32_C(  1090028281),  INT32_C(   389976670), -INT32_C(  1879169113),  INT32_C(  1012962718), -INT32_C(   622028337), -INT32_C(  1727159556) },
      { SIMDE_FLOAT32_C(  -464.67), SIMDE_FLOAT32_C(   179.59), SIMDE_FLOAT32_C(  -237.40), SIMDE_FLOAT32_C(  -125.05),
        SIMDE_FLOAT32_C(   -58.30), SIMDE_FLOAT32_C(   453.65), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   962.17) },
      { SIMDE_FLOAT32_C(   453.65), SIMDE_FLOAT32_C(   962.17), SIMDE_FLOAT32_C(   517.36), SIMDE_FLOAT32_C(   655.67),
        SIMDE_FLOAT32_C(   517.36), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   962.17), SIMDE_FLOAT32_C(   -58.30) } },
    { { SIMDE_FLOAT32_C(   246.84), SIMDE_FLOAT32_C(  -174.75), SIMDE_FLOAT32_C(   263.04), SIMDE_FLOAT32_C(  -474.89),
        SIMDE_FLOAT32_C(   715.74), SIMDE_FLOAT32_C(   512.37), SIMDE_FLOAT32_C(   563.60), SIMDE_FLOAT32_C(  -502.42) },
      {  INT32_C(    26795619),  INT32_C(  1128135028), -INT32_C(  1910691182),  INT32_C(   589769420), -INT32_C(  1494617746),  INT32_C(  1239724510), -INT32_C(   502078848), -INT32_C(  2132020707) },
      { SIMDE_FLOAT32_C(   104.27), SIMDE_FLOAT32_C(   -73.64), SIMDE_FLOAT32_C(  -115.24), SIMDE_FLOAT32_C(   385.75),
        SIMDE_FLOAT32_C(   409.86), SIMDE_FLOAT32_C(   398.20), SIMDE_FLOAT32_C(  -391.56), SIMDE_FLOAT32_C(   420.42) },
      { SIMDE_FLOAT32_C(  -474.89), SIMDE_FLOAT32_C(   715.74), SIMDE_FLOAT32_C(   263.04), SIMDE_FLOAT32_C(   409.86),
        SIMDE_FLOAT32_C(  -391.56), SIMDE_FLOAT32_C(  -391.56), SIMDE_FLOAT32_C(   246.84), SIMDE_FLOAT32_C(   398.20) } },
    { { SIMDE_FLOAT32_C(  -542.23), SIMDE_FLOAT32_C(  -583.29), SIMDE_FLOAT32_C(  -659.54), SIMDE_FLOAT32_C(  -637.49),
        SIMDE_FLOAT32_C(  -672.07), SIMDE_FLOAT32_C(   914.01), SIMDE_FLOAT32_C(  -197.42), SIMDE_FLOAT32_C(   418.73) },
      { -INT32_C(  1796881994), -INT32_C(   203503246), -INT32_C(   908726101), -INT32_C(  1270234909), -INT32_C(  1057371325),  INT32_C(  1942978954), -INT32_C(   131568601), -INT32_C(   415825615) },
      { SIMDE_FLOAT32_C(  -723.20), SIMDE_FLOAT32_C(  -523.25), SIMDE_FLOAT32_C(  -293.61), SIMDE_FLOAT32_C(   365.09),
        SIMDE_FLOAT32_C(   922.67), SIMDE_FLOAT32_C(   782.98), SIMDE_FLOAT32_C(  -750.69), SIMDE_FLOAT32_C(  -373.69) },
      { SIMDE_FLOAT32_C(  -197.42), SIMDE_FLOAT32_C(  -659.54), SIMDE_FLOAT32_C(   365.09), SIMDE_FLOAT32_C(  -637.49),
        SIMDE_FLOAT32_C(  -637.49), SIMDE_FLOAT32_C(  -293.61), SIMDE_FLOAT32_C(   418.73), SIMDE_FLOAT32_C(  -583.29) } },
    { { SIMDE_FLOAT32_C(  -578.69), SIMDE_FLOAT32_C(  -354.78), SIMDE_FLOAT32_C(  -899.97), SIMDE_FLOAT32_C(  -815.01),
        SIMDE_FLOAT32_C(    50.38), SIMDE_FLOAT32_C(  -646.57), SIMDE_FLOAT32_C(    52.93), SIMDE_FLOAT32_C(  -618.09) },
      { -INT32_C(   121578898), -INT32_C(  2090102948),  INT32_C(   763073788),  INT32_C(  1461039765), -INT32_C(  1265856050),  INT32_C(   893760747),  INT32_C(  1852022705), -INT32_C(  1318108094) },
      { SIMDE_FLOAT32_C(  -674.67), SIMDE_FLOAT32_C(   629.91), SIMDE_FLOAT32_C(    78.57), SIMDE_FLOAT32_C(  -505.91),
        SIMDE_FLOAT32_C(   -84.98), SIMDE_FLOAT32_C(  -899.37), SIMDE_FLOAT32_C(   941.69), SIMDE_FLOAT32_C(  -297.60) },
      { SIMDE_FLOAT32_C(   941.69), SIMDE_FLOAT32_C(   -84.98), SIMDE_FLOAT32_C(   -84.98), SIMDE_FLOAT32_C(  -646.57),
        SIMDE_FLOAT32_C(   941.69), SIMDE_FLOAT32_C(  -505.91), SIMDE_FLOAT32_C(  -354.78), SIMDE_FLOAT32_C(  -899.97) } },
    { { SIMDE_FLOAT32_C(  -520.68), SIMDE_FLOAT32_C(    -3.94), SIMDE_FLOAT32_C(   -93.93), SIMDE_FLOAT32_C(    17.21),
        SIMDE_FLOAT32_C(    75.93), SIMDE_FLOAT32_C(   776.17), SIMDE_FLOAT32_C(   831.91), SIMDE_FLOAT32_C(   632.54) },
      {  INT32_C(  2041520782), -INT32_C(  2001734442), -INT32_C(   705293677),  INT32_C(  1971742038),  INT32_C(  1425027221), -INT32_C(   300945595), -INT32_C(  1792215191), -INT32_C(  2087665163) },
      { SIMDE_FLOAT32_C(   552.07), SIMDE_FLOAT32_C(  -945.13), SIMDE_FLOAT32_C(  -859.22), SIMDE_FLOAT32_C(   992.87),
        SIMDE_FLOAT32_C(   272.29), SIMDE_FLOAT32_C(  -366.30), SIMDE_FLOAT32_C(   507.98), SIMDE_FLOAT32_C(   695.32) },
      { SIMDE_FLOAT32_C(   507.98), SIMDE_FLOAT32_C(   831.91), SIMDE_FLOAT32_C(    17.21), SIMDE_FLOAT32_C(   831.91),
        SIMDE_FLOAT32_C(   776.17), SIMDE_FLOAT32_C(   776.17), SIMDE_FLOAT32_C(  -945.13), SIMDE_FLOAT32_C(   776.17) } },
    { { SIMDE_FLOAT32_C(    92.39), SIMDE_FLOAT32_C(   147.79), SIMDE_FLOAT32_C(   677.41), SIMDE_FLOAT32_C(  -430.22),
        SIMDE_FLOAT32_C(   294.21), SIMDE_FLOAT32_C(  -289.87), SIMDE_FLOAT32_C(  -627.49), SIMDE_FLOAT32_C(    70.54) },
      { -INT32_C(  1752729006), -INT32_C(   762997143), -INT32_C(  2107068019),  INT32_C(  1443297395),  INT32_C(  1796211512),  INT32_C(  1832014511),  INT32_C(   696372875),  INT32_C(  1130105840) },
      { SIMDE_FLOAT32_C(  -561.40), SIMDE_FLOAT32_C(   300.74), SIMDE_FLOAT32_C(   660.73), SIMDE_FLOAT32_C(   346.43),
        SIMDE_FLOAT32_C(  -543.60), SIMDE_FLOAT32_C(   385.30), SIMDE_FLOAT32_C(   488.84), SIMDE_FLOAT32_C(   911.87) },
      { SIMDE_FLOAT32_C(   677.41), SIMDE_FLOAT32_C(   300.74), SIMDE_FLOAT32_C(   385.30), SIMDE_FLOAT32_C(  -430.22),
        SIMDE_FLOAT32_C(  -561.40), SIMDE_FLOAT32_C(   911.87), SIMDE_FLOAT32_C(   346.43), SIMDE_FLOAT32_C(    92.39) } },
    { { SIMDE_FLOAT32_C(  -181.68), SIMDE_FLOAT32_C(   941.75), SIMDE_FLOAT32_C(   443.33), SIMDE_FLOAT32_C(   791.70),
        SIMDE_FLOAT32_C(  -662.30), SIMDE_FLOAT32_C(  -596.55), SIMDE_FLOAT32_C(  -682.85), SIMDE_FLOAT32_C(  -211.48) },
      {  INT32_C(  1103555474), -INT32_C(   911280066), -INT32_C(  1225642042), -INT32_C(  1040626117), -INT32_C(  1431251919),  INT32_C(  1169191476), -INT32_C(  1077266020),  INT32_C(  1511630280) },
      { SIMDE_FLOAT32_C(  -732.06), SIMDE_FLOAT32_C(  -914.56), SIMDE_FLOAT32_C(  -697.91), SIMDE_FLOAT32_C(   129.71),
        SIMDE_FLOAT32_C(  -984.49), SIMDE_FLOAT32_C(  -631.99), SIMDE_FLOAT32_C(   165.58), SIMDE_FLOAT32_C(    41.42) },
      { SIMDE_FLOAT32_C(   443.33), SIMDE_FLOAT32_C(   165.58), SIMDE_FLOAT32_C(  -682.85), SIMDE_FLOAT32_C(   129.71),
        SIMDE_FLOAT32_C(   941.75), SIMDE_FLOAT32_C(  -662.30), SIMDE_FLOAT32_C(  -984.49), SIMDE_FLOAT32_C(  -732.06) } },
    { { SIMDE_FLOAT32_C(   830.69), SIMDE_FLOAT32_C(   669.75), SIMDE_FLOAT32_C(   873.30), SIMDE_FLOAT32_C(    62.65),
        SIMDE_FLOAT32_C(   712.76), SIMDE_FLOAT32_C(   332.57), SIMDE_FLOAT32_C(  -266.79), SIMDE_FLOAT32_C(    56.52) },
      {  INT32_C(  1437738273),  INT32_C(   882598808),  INT32_C(  1710450076), -INT32_C(  1698755318), -INT32_C(   999728148),  INT32_C(   492896420),  INT32_C(  1641133450),  INT32_C(   610944515) },
      { SIMDE_FLOAT32_C(  -607.11), SIMDE_FLOAT32_C(  -311.81), SIMDE_FLOAT32_C(  -178.60), SIMDE_FLOAT32_C(  -351.06),
        SIMDE_FLOAT32_C(   256.90), SIMDE_FLOAT32_C(   102.87), SIMDE_FLOAT32_C(   352.56), SIMDE_FLOAT32_C(   -19.03) },
      { SIMDE_FLOAT32_C(   669.75), SIMDE_FLOAT32_C(  -607.11), SIMDE_FLOAT32_C(   256.90), SIMDE_FLOAT32_C(  -178.60),
        SIMDE_FLOAT32_C(   256.90), SIMDE_FLOAT32_C(   712.76), SIMDE_FLOAT32_C(  -178.60), SIMDE_FLOAT32_C(    62.65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_permutex2var_ps(a, idx, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_permutex2var_ps(a, idx, b);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float32 a[8];
    const simde__mmask8 k;
    const int32_t idx[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -500.35), SIMDE_FLOAT32_C(  -158.53), SIMDE_FLOAT32_C(  -736.15), SIMDE_FLOAT32_C(   328.90),
        SIMDE_FLOAT32_C(   904.19), SIMDE_FLOAT32_C(  -390.12), SIMDE_FLOAT32_C(  -573.91), SIMDE_FLOAT32_C(    52.35) },
      UINT8_C(155),
      { -INT32_C(  2009011833),  INT32_C(     1203531),  INT32_C(  1963160367), -INT32_C(    85907235), -INT32_C(  1216748126),  INT32_C(  1244763422),  INT32_C(  1468249366),  INT32_C(  1542629587) },
      { SIMDE_FLOAT32_C(  -918.50), SIMDE_FLOAT32_C(    46.12), SIMDE_FLOAT32_C(  -348.62), SIMDE_FLOAT32_C(  -497.40),
        SIMDE_FLOAT32_C(  -832.95), SIMDE_FLOAT32_C(   759.08), SIMDE_FLOAT32_C(     2.10), SIMDE_FLOAT32_C(   197.46) },
      { SIMDE_FLOAT32_C(    52.35), SIMDE_FLOAT32_C(  -497.40), SIMDE_FLOAT32_C(  -736.15), SIMDE_FLOAT32_C(   759.08),
        SIMDE_FLOAT32_C(  -736.15), SIMDE_FLOAT32_C(  -390.12), SIMDE_FLOAT32_C(  -573.91), SIMDE_FLOAT32_C(   328.90) } },
    { { SIMDE_FLOAT32_C(   641.76), SIMDE_FLOAT32_C(   -87.43), SIMDE_FLOAT32_C(  -129.45), SIMDE_FLOAT32_C(   355.96),
        SIMDE_FLOAT32_C(  -313.43), SIMDE_FLOAT32_C(   -63.46), SIMDE_FLOAT32_C(   758.35), SIMDE_FLOAT32_C(   281.97) },
      UINT8_C(251),
      {  INT32_C(  1327063737),  INT32_C(  1214604179), -INT32_C(  1894007578), -INT32_C(   517900625),  INT32_C(  1316093529), -INT32_C(  1128845093),  INT32_C(  2076573029), -INT32_C(   160010179) },
      { SIMDE_FLOAT32_C(  -245.94), SIMDE_FLOAT32_C(  -163.82), SIMDE_FLOAT32_C(   905.91), SIMDE_FLOAT32_C(   932.22),
        SIMDE_FLOAT32_C(   464.07), SIMDE_FLOAT32_C(  -132.05), SIMDE_FLOAT32_C(  -362.79), SIMDE_FLOAT32_C(   -94.89) },
      { SIMDE_FLOAT32_C(  -163.82), SIMDE_FLOAT32_C(   355.96), SIMDE_FLOAT32_C(  -129.45), SIMDE_FLOAT32_C(   -94.89),
        SIMDE_FLOAT32_C(  -163.82), SIMDE_FLOAT32_C(   932.22), SIMDE_FLOAT32_C(   -63.46), SIMDE_FLOAT32_C(  -132.05) } },
    { { SIMDE_FLOAT32_C(   343.99), SIMDE_FLOAT32_C(   295.12), SIMDE_FLOAT32_C(  -788.38), SIMDE_FLOAT32_C(  -407.97),
        SIMDE_FLOAT32_C(  -441.06), SIMDE_FLOAT32_C(   599.63), SIMDE_FLOAT32_C(  -113.82), SIMDE_FLOAT32_C(  -525.86) },
      UINT8_C(136),
      { -INT32_C(  1704728727), -INT32_C(  1677778786),  INT32_C(  1457027813), -INT32_C(  2144808976), -INT32_C(  1082880492),  INT32_C(    69684795),  INT32_C(  1094991287), -INT32_C(  1614160587) },
      { SIMDE_FLOAT32_C(  -745.97), SIMDE_FLOAT32_C(     8.13), SIMDE_FLOAT32_C(  -635.67), SIMDE_FLOAT32_C(   718.50),
        SIMDE_FLOAT32_C(   196.38), SIMDE_FLOAT32_C(   899.62), SIMDE_FLOAT32_C(   854.97), SIMDE_FLOAT32_C(   876.49) },
      { SIMDE_FLOAT32_C(   343.99), SIMDE_FLOAT32_C(   295.12), SIMDE_FLOAT32_C(  -788.38), SIMDE_FLOAT32_C(   343.99),
        SIMDE_FLOAT32_C(  -441.06), SIMDE_FLOAT32_C(   599.63), SIMDE_FLOAT32_C(  -113.82), SIMDE_FLOAT32_C(   599.63) } },
    { { SIMDE_FLOAT32_C(   -99.32), SIMDE_FLOAT32_C(  -578.21), SIMDE_FLOAT32_C(  -669.58), SIMDE_FLOAT32_C(    18.98),
        SIMDE_FLOAT32_C(  -163.39), SIMDE_FLOAT32_C(   538.40), SIMDE_FLOAT32_C(   973.44), SIMDE_FLOAT32_C(   157.34) },
      UINT8_C( 62),
      { -INT32_C(   444958057), -INT32_C(   560169311), -INT32_C(  1626022462), -INT32_C(   765152346),  INT32_C(   606062572), -INT32_C(  1663675963), -INT32_C(  1992132391),  INT32_C(   852032923) },
      { SIMDE_FLOAT32_C(   854.86), SIMDE_FLOAT32_C(  -904.59), SIMDE_FLOAT32_C(   637.20), SIMDE_FLOAT32_C(  -266.46),
        SIMDE_FLOAT32_C(   623.95), SIMDE_FLOAT32_C(  -111.90), SIMDE_FLOAT32_C(  -263.09), SIMDE_FLOAT32_C(  -216.04) },
      { SIMDE_FLOAT32_C(   -99.32), SIMDE_FLOAT32_C(  -578.21), SIMDE_FLOAT32_C(  -669.58), SIMDE_FLOAT32_C(   973.44),
        SIMDE_FLOAT32_C(   623.95), SIMDE_FLOAT32_C(   538.40), SIMDE_FLOAT32_C(   973.44), SIMDE_FLOAT32_C(   157.34) } },
    { { SIMDE_FLOAT32_C(   273.91), SIMDE_FLOAT32_C(  -248.84), SIMDE_FLOAT32_C(  -950.43), SIMDE_FLOAT32_C(  -715.12),
        SIMDE_FLOAT32_C(  -876.33), SIMDE_FLOAT32_C(   569.21), SIMDE_FLOAT32_C(  -696.03), SIMDE_FLOAT32_C(   860.52) },
      UINT8_C( 77),
      {  INT32_C(  2031340840),  INT32_C(   475180963), -INT32_C(   273163278), -INT32_C(   446240093), -INT32_C(  1247379967),  INT32_C(  2135239028), -INT32_C(   767787957), -INT32_C(  1390418299) },
      { SIMDE_FLOAT32_C(  -166.66), SIMDE_FLOAT32_C(   463.92), SIMDE_FLOAT32_C(   560.35), SIMDE_FLOAT32_C(  -132.52),
        SIMDE_FLOAT32_C(  -120.73), SIMDE_FLOAT32_C(   594.17), SIMDE_FLOAT32_C(  -542.24), SIMDE_FLOAT32_C(  -353.88) },
      { SIMDE_FLOAT32_C(  -166.66), SIMDE_FLOAT32_C(  -248.84), SIMDE_FLOAT32_C(  -950.43), SIMDE_FLOAT32_C(  -715.12),
        SIMDE_FLOAT32_C(  -876.33), SIMDE_FLOAT32_C(   569.21), SIMDE_FLOAT32_C(  -132.52), SIMDE_FLOAT32_C(   860.52) } },
    { { SIMDE_FLOAT32_C(  -411.22), SIMDE_FLOAT32_C(   577.61), SIMDE_FLOAT32_C(   921.81), SIMDE_FLOAT32_C(   222.79),
        SIMDE_FLOAT32_C(  -380.98), SIMDE_FLOAT32_C(    52.37), SIMDE_FLOAT32_C(   952.21), SIMDE_FLOAT32_C(   297.63) },
      UINT8_C(167),
      { -INT32_C(  1424241790), -INT32_C(  1929930224), -INT32_C(  1122907689),  INT32_C(   460373736),  INT32_C(  1560135652),  INT32_C(  1706086714), -INT32_C(  1116100716),  INT32_C(   107253635) },
      { SIMDE_FLOAT32_C(  -801.01), SIMDE_FLOAT32_C(   346.78), SIMDE_FLOAT32_C(   875.66), SIMDE_FLOAT32_C(   903.96),
        SIMDE_FLOAT32_C(  -783.60), SIMDE_FLOAT32_C(  -494.54), SIMDE_FLOAT32_C(  -265.57), SIMDE_FLOAT32_C(  -438.13) },
      { SIMDE_FLOAT32_C(   921.81), SIMDE_FLOAT32_C(  -411.22), SIMDE_FLOAT32_C(   297.63), SIMDE_FLOAT32_C(   222.79),
        SIMDE_FLOAT32_C(  -380.98), SIMDE_FLOAT32_C(   875.66), SIMDE_FLOAT32_C(   952.21), SIMDE_FLOAT32_C(   222.79) } },
    { { SIMDE_FLOAT32_C(   891.37), SIMDE_FLOAT32_C(    -5.63), SIMDE_FLOAT32_C(  -756.32), SIMDE_FLOAT32_C(  -159.26),
        SIMDE_FLOAT32_C(  -796.75), SIMDE_FLOAT32_C(  -241.17), SIMDE_FLOAT32_C(   254.03), SIMDE_FLOAT32_C(   -27.53) },
      UINT8_C(230),
      {  INT32_C(  1126172786),  INT32_C(  1607959992), -INT32_C(  1897687809),  INT32_C(  2011818488),  INT32_C(  1133597850),  INT32_C(  1421115979),  INT32_C(  1327238704), -INT32_C(   181024637) },
      { SIMDE_FLOAT32_C(   114.82), SIMDE_FLOAT32_C(  -661.23), SIMDE_FLOAT32_C(  -577.95), SIMDE_FLOAT32_C(   402.87),
        SIMDE_FLOAT32_C(   738.60), SIMDE_FLOAT32_C(  -232.21), SIMDE_FLOAT32_C(   865.88), SIMDE_FLOAT32_C(   175.45) },
      { SIMDE_FLOAT32_C(   891.37), SIMDE_FLOAT32_C(   114.82), SIMDE_FLOAT32_C(   175.45), SIMDE_FLOAT32_C(  -159.26),
        SIMDE_FLOAT32_C(  -796.75), SIMDE_FLOAT32_C(   402.87), SIMDE_FLOAT32_C(   891.37), SIMDE_FLOAT32_C(  -159.26) } },
    { { SIMDE_FLOAT32_C(  -973.61), SIMDE_FLOAT32_C(  -543.93), SIMDE_FLOAT32_C(   946.95), SIMDE_FLOAT32_C(   114.30),
        SIMDE_FLOAT32_C(   479.02), SIMDE_FLOAT32_C(   -82.57), SIMDE_FLOAT32_C(   548.99), SIMDE_FLOAT32_C(  -622.38) },
      UINT8_C(165),
      {  INT32_C(   670143140),  INT32_C(  1431782726),  INT32_C(   702064225),  INT32_C(   838520539),  INT32_C(   369918726),  INT32_C(   934930027), -INT32_C(  1595189938),  INT32_C(   205863528) },
      { SIMDE_FLOAT32_C(    67.38), SIMDE_FLOAT32_C(  -248.12), SIMDE_FLOAT32_C(  -967.07), SIMDE_FLOAT32_C(  -855.49),
        SIMDE_FLOAT32_C(  -244.14), SIMDE_FLOAT32_C(   -97.40), SIMDE_FLOAT32_C(   357.81), SIMDE_FLOAT32_C(   566.31) },
      { SIMDE_FLOAT32_C(   479.02), SIMDE_FLOAT32_C(  -543.93), SIMDE_FLOAT32_C(  -543.93), SIMDE_FLOAT32_C(   114.30),
        SIMDE_FLOAT32_C(   479.02), SIMDE_FLOAT32_C(  -855.49), SIMDE_FLOAT32_C(   548.99), SIMDE_FLOAT32_C(    67.38) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_mask_permutex2var_ps(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_mask_permutex2var_ps(a, k, idx, b);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask2_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde_float32 a[8];
    const int32_t idx[8];
    const simde__mmask8 k;
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   987.74), SIMDE_FLOAT32_C(   961.33), SIMDE_FLOAT32_C(  -844.27), SIMDE_FLOAT32_C(   429.80),
        SIMDE_FLOAT32_C(  -498.37), SIMDE_FLOAT32_C(   859.96), SIMDE_FLOAT32_C(   210.63), SIMDE_FLOAT32_C(   463.98) },
      { -INT32_C(  1039940977), -INT32_C(  1014564454),  INT32_C(  1128406712),  INT32_C(  1147863859),  INT32_C(  1137997906), -INT32_C(  1035639194),  INT32_C(  1136168141), -INT32_C(   999731528) },
      UINT8_C( 57),
      { SIMDE_FLOAT32_C(  -722.82), SIMDE_FLOAT32_C(   626.03), SIMDE_FLOAT32_C(  -758.72), SIMDE_FLOAT32_C(   562.87),
        SIMDE_FLOAT32_C(   -22.83), SIMDE_FLOAT32_C(  -138.83), SIMDE_FLOAT32_C(  -369.75), SIMDE_FLOAT32_C(   729.06) },
      { SIMDE_FLOAT32_C(   729.06), SIMDE_FLOAT32_C(  -269.95), SIMDE_FLOAT32_C(   194.12), SIMDE_FLOAT32_C(   429.80),
        SIMDE_FLOAT32_C(  -844.27), SIMDE_FLOAT32_C(   210.63), SIMDE_FLOAT32_C(   369.10), SIMDE_FLOAT32_C(  -933.23) } },
    { { SIMDE_FLOAT32_C(  -105.90), SIMDE_FLOAT32_C(  -225.25), SIMDE_FLOAT32_C(  -515.09), SIMDE_FLOAT32_C(   796.70),
        SIMDE_FLOAT32_C(  -867.43), SIMDE_FLOAT32_C(  -948.77), SIMDE_FLOAT32_C(   784.44), SIMDE_FLOAT32_C(  -906.11) },
      { -INT32_C(  1002028237),  INT32_C(  1129725297), -INT32_C(  1010156175), -INT32_C(   999733821), -INT32_C(  1005598638), -INT32_C(   999612416),  INT32_C(  1107815301),  INT32_C(  1125837701) },
      UINT8_C( 35),
      { SIMDE_FLOAT32_C(   -25.98), SIMDE_FLOAT32_C(  -420.14), SIMDE_FLOAT32_C(  -795.74), SIMDE_FLOAT32_C(  -656.87),
        SIMDE_FLOAT32_C(  -353.37), SIMDE_FLOAT32_C(  -974.27), SIMDE_FLOAT32_C(  -379.69), SIMDE_FLOAT32_C(  -727.34) },
      { SIMDE_FLOAT32_C(   796.70), SIMDE_FLOAT32_C(  -225.25), SIMDE_FLOAT32_C(  -404.48), SIMDE_FLOAT32_C(  -933.09),
        SIMDE_FLOAT32_C(  -575.13), SIMDE_FLOAT32_C(  -105.90), SIMDE_FLOAT32_C(    33.98), SIMDE_FLOAT32_C(   154.92) } },
    { { SIMDE_FLOAT32_C(  -732.99), SIMDE_FLOAT32_C(  -816.83), SIMDE_FLOAT32_C(   249.84), SIMDE_FLOAT32_C(   128.18),
        SIMDE_FLOAT32_C(  -186.58), SIMDE_FLOAT32_C(   -21.11), SIMDE_FLOAT32_C(  -977.72), SIMDE_FLOAT32_C(   588.18) },
      {  INT32_C(  1139271598),  INT32_C(  1145880248),  INT32_C(  1144270684),  INT32_C(  1140900332),  INT32_C(  1142348513),  INT32_C(  1145808978),  INT32_C(  1144291000), -INT32_C(  1019849605) },
      UINT8_C(133),
      { SIMDE_FLOAT32_C(   788.90), SIMDE_FLOAT32_C(   242.54), SIMDE_FLOAT32_C(  -530.35), SIMDE_FLOAT32_C(  -177.13),
        SIMDE_FLOAT32_C(  -602.54), SIMDE_FLOAT32_C(   723.27), SIMDE_FLOAT32_C(   796.90), SIMDE_FLOAT32_C(   -22.68) },
      { SIMDE_FLOAT32_C(   796.90), SIMDE_FLOAT32_C(   818.98), SIMDE_FLOAT32_C(  -602.54), SIMDE_FLOAT32_C(   515.03),
        SIMDE_FLOAT32_C(   603.42), SIMDE_FLOAT32_C(   814.63), SIMDE_FLOAT32_C(   721.98), SIMDE_FLOAT32_C(  -177.13) } },
    { { SIMDE_FLOAT32_C(   927.53), SIMDE_FLOAT32_C(  -859.97), SIMDE_FLOAT32_C(   623.95), SIMDE_FLOAT32_C(   953.27),
        SIMDE_FLOAT32_C(  -239.67), SIMDE_FLOAT32_C(   896.61), SIMDE_FLOAT32_C(  -779.72), SIMDE_FLOAT32_C(   -56.50) },
      {  INT32_C(  1125282611),  INT32_C(  1135491809),  INT32_C(  1144863621), -INT32_C(  1000691139),  INT32_C(  1136221880),  INT32_C(  1135381709),  INT32_C(  1142114714),  INT32_C(  1128118354) },
      UINT8_C( 54),
      { SIMDE_FLOAT32_C(   104.18), SIMDE_FLOAT32_C(  -206.85), SIMDE_FLOAT32_C(  -119.52), SIMDE_FLOAT32_C(  -173.84),
        SIMDE_FLOAT32_C(   610.81), SIMDE_FLOAT32_C(   290.63), SIMDE_FLOAT32_C(  -384.94), SIMDE_FLOAT32_C(  -146.65) },
      { SIMDE_FLOAT32_C(   146.45), SIMDE_FLOAT32_C(  -859.97), SIMDE_FLOAT32_C(   896.61), SIMDE_FLOAT32_C(  -874.66),
        SIMDE_FLOAT32_C(   104.18), SIMDE_FLOAT32_C(   290.63), SIMDE_FLOAT32_C(   589.15), SIMDE_FLOAT32_C(   189.72) } },
    { { SIMDE_FLOAT32_C(   760.28), SIMDE_FLOAT32_C(   437.93), SIMDE_FLOAT32_C(   250.81), SIMDE_FLOAT32_C(   483.55),
        SIMDE_FLOAT32_C(   234.83), SIMDE_FLOAT32_C(  -771.87), SIMDE_FLOAT32_C(   411.08), SIMDE_FLOAT32_C(   374.86) },
      {  INT32_C(  1146422559),  INT32_C(  1136012165), -INT32_C(  1000852521),  INT32_C(  1144728617),  INT32_C(  1142040494),  INT32_C(  1117610312), -INT32_C(  1026443182), -INT32_C(  1031417364) },
      UINT8_C(128),
      { SIMDE_FLOAT32_C(    20.49), SIMDE_FLOAT32_C(  -696.17), SIMDE_FLOAT32_C(  -819.28), SIMDE_FLOAT32_C(  -390.37),
        SIMDE_FLOAT32_C(   493.55), SIMDE_FLOAT32_C(   246.56), SIMDE_FLOAT32_C(   713.81), SIMDE_FLOAT32_C(  -713.30) },
      { SIMDE_FLOAT32_C(   852.08), SIMDE_FLOAT32_C(   364.34), SIMDE_FLOAT32_C(  -864.81), SIMDE_FLOAT32_C(   748.69),
        SIMDE_FLOAT32_C(   584.62), SIMDE_FLOAT32_C(    78.69), SIMDE_FLOAT32_C(  -104.86), SIMDE_FLOAT32_C(   493.55) } },
    { { SIMDE_FLOAT32_C(  -872.96), SIMDE_FLOAT32_C(  -460.02), SIMDE_FLOAT32_C(   897.52), SIMDE_FLOAT32_C(   417.67),
        SIMDE_FLOAT32_C(   155.04), SIMDE_FLOAT32_C(  -249.13), SIMDE_FLOAT32_C(   177.95), SIMDE_FLOAT32_C(  -407.03) },
      { -INT32_C(   998665093), -INT32_C(  1012317880),  INT32_C(  1146024755), -INT32_C(  1002402775), -INT32_C(   999826555),  INT32_C(  1128966390), -INT32_C(   999979254),  INT32_C(  1138390467) },
      UINT8_C(139),
      { SIMDE_FLOAT32_C(   830.58), SIMDE_FLOAT32_C(    21.54), SIMDE_FLOAT32_C(  -583.47), SIMDE_FLOAT32_C(  -274.27),
        SIMDE_FLOAT32_C(   954.63), SIMDE_FLOAT32_C(   252.15), SIMDE_FLOAT32_C(   746.21), SIMDE_FLOAT32_C(  -741.54) },
      { SIMDE_FLOAT32_C(  -274.27), SIMDE_FLOAT32_C(   830.58), SIMDE_FLOAT32_C(   827.80), SIMDE_FLOAT32_C(    21.54),
        SIMDE_FLOAT32_C(  -927.43), SIMDE_FLOAT32_C(   202.66), SIMDE_FLOAT32_C(  -918.11), SIMDE_FLOAT32_C(   417.67) } },
    { { SIMDE_FLOAT32_C(   432.87), SIMDE_FLOAT32_C(  -644.16), SIMDE_FLOAT32_C(   752.01), SIMDE_FLOAT32_C(  -320.56),
        SIMDE_FLOAT32_C(  -930.34), SIMDE_FLOAT32_C(  -961.29), SIMDE_FLOAT32_C(  -193.52), SIMDE_FLOAT32_C(  -390.37) },
      {  INT32_C(  1147801272), -INT32_C(  1002309878),  INT32_C(  1144990433), -INT32_C(  1013156741),  INT32_C(  1137249157), -INT32_C(  1004497142), -INT32_C(  1013211791), -INT32_C(   999679263) },
      UINT8_C( 80),
      { SIMDE_FLOAT32_C(   -81.42), SIMDE_FLOAT32_C(  -863.85), SIMDE_FLOAT32_C(   388.10), SIMDE_FLOAT32_C(     0.47),
        SIMDE_FLOAT32_C(   573.07), SIMDE_FLOAT32_C(  -274.06), SIMDE_FLOAT32_C(  -168.95), SIMDE_FLOAT32_C(  -405.39) },
      { SIMDE_FLOAT32_C(   936.23), SIMDE_FLOAT32_C(  -775.86), SIMDE_FLOAT32_C(   764.67), SIMDE_FLOAT32_C(  -312.91),
        SIMDE_FLOAT32_C(  -961.29), SIMDE_FLOAT32_C(  -642.36), SIMDE_FLOAT32_C(  -644.16), SIMDE_FLOAT32_C(  -936.42) } },
    { { SIMDE_FLOAT32_C(   142.47), SIMDE_FLOAT32_C(   556.78), SIMDE_FLOAT32_C(  -450.77), SIMDE_FLOAT32_C(  -605.38),
        SIMDE_FLOAT32_C(   302.99), SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(   827.49), SIMDE_FLOAT32_C(   658.83) },
      { -INT32_C(  1008982426), -INT32_C(  1007253258),  INT32_C(  1144397660), -INT32_C(  1010250875),  INT32_C(  1134343291), -INT32_C(  1004177326), -INT32_C(  1008161260),  INT32_C(  1141269299) },
      UINT8_C( 29),
      { SIMDE_FLOAT32_C(   221.73), SIMDE_FLOAT32_C(   -60.36), SIMDE_FLOAT32_C(  -539.57), SIMDE_FLOAT32_C(   910.50),
        SIMDE_FLOAT32_C(     3.22), SIMDE_FLOAT32_C(  -354.13), SIMDE_FLOAT32_C(  -170.93), SIMDE_FLOAT32_C(   139.37) },
      { SIMDE_FLOAT32_C(   827.49), SIMDE_FLOAT32_C(  -493.07), SIMDE_FLOAT32_C(     3.22), SIMDE_FLOAT32_C(  -192.31),
        SIMDE_FLOAT32_C(   910.50), SIMDE_FLOAT32_C(  -661.88), SIMDE_FLOAT32_C(  -465.36), SIMDE_FLOAT32_C(   537.55) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_mask2_permutex2var_ps(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i idx = simde_mm256_castps_si256(simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_mask2_permutex2var_ps(a, idx, k, b);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const int32_t idx[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(154),
      { SIMDE_FLOAT32_C(  -270.29), SIMDE_FLOAT32_C(  -118.45), SIMDE_FLOAT32_C(   527.46), SIMDE_FLOAT32_C(  -793.46),
        SIMDE_FLOAT32_C(  -217.24), SIMDE_FLOAT32_C(   139.69), SIMDE_FLOAT32_C(   175.32), SIMDE_FLOAT32_C(  -568.86) },
      { -INT32_C(   307649416), -INT32_C(   956032053), -INT32_C(  1754201414),  INT32_C(   494816139), -INT32_C(   807894669), -INT32_C(   211153711), -INT32_C(  1251366856),  INT32_C(   551614120) },
      { SIMDE_FLOAT32_C(   280.16), SIMDE_FLOAT32_C(  -576.05), SIMDE_FLOAT32_C(   981.41), SIMDE_FLOAT32_C(   341.99),
        SIMDE_FLOAT32_C(   -28.10), SIMDE_FLOAT32_C(   523.12), SIMDE_FLOAT32_C(   828.32), SIMDE_FLOAT32_C(  -577.67) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   341.99), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   341.99),
        SIMDE_FLOAT32_C(  -793.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   280.16) } },
    { UINT8_C( 19),
      { SIMDE_FLOAT32_C(   603.04), SIMDE_FLOAT32_C(   131.16), SIMDE_FLOAT32_C(    49.79), SIMDE_FLOAT32_C(   387.47),
        SIMDE_FLOAT32_C(   705.16), SIMDE_FLOAT32_C(  -554.95), SIMDE_FLOAT32_C(   975.16), SIMDE_FLOAT32_C(  -444.72) },
      { -INT32_C(  1580847979),  INT32_C(  1054522006),  INT32_C(   451317539), -INT32_C(   105642385),  INT32_C(   631052819), -INT32_C(   432473017),  INT32_C(  1724897266),  INT32_C(   693906580) },
      { SIMDE_FLOAT32_C(   650.48), SIMDE_FLOAT32_C(   262.11), SIMDE_FLOAT32_C(  -891.18), SIMDE_FLOAT32_C(   678.55),
        SIMDE_FLOAT32_C(  -182.42), SIMDE_FLOAT32_C(   821.73), SIMDE_FLOAT32_C(   901.56), SIMDE_FLOAT32_C(  -555.48) },
      { SIMDE_FLOAT32_C(  -554.95), SIMDE_FLOAT32_C(   975.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   387.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 52),
      { SIMDE_FLOAT32_C(   459.21), SIMDE_FLOAT32_C(   318.28), SIMDE_FLOAT32_C(  -994.67), SIMDE_FLOAT32_C(   210.17),
        SIMDE_FLOAT32_C(   472.19), SIMDE_FLOAT32_C(  -208.90), SIMDE_FLOAT32_C(   -57.46), SIMDE_FLOAT32_C(   -31.91) },
      {  INT32_C(   909135930),  INT32_C(  1613305481),  INT32_C(   318017510),  INT32_C(   241835499), -INT32_C(  1930798872), -INT32_C(  1765741948), -INT32_C(   743545852),  INT32_C(   985454848) },
      { SIMDE_FLOAT32_C(  -135.29), SIMDE_FLOAT32_C(   202.89), SIMDE_FLOAT32_C(   -32.45), SIMDE_FLOAT32_C(   347.68),
        SIMDE_FLOAT32_C(  -577.55), SIMDE_FLOAT32_C(     7.46), SIMDE_FLOAT32_C(   165.40), SIMDE_FLOAT32_C(   956.73) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -57.46), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -135.29), SIMDE_FLOAT32_C(   472.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 41),
      { SIMDE_FLOAT32_C(  -237.09), SIMDE_FLOAT32_C(   780.91), SIMDE_FLOAT32_C(  -308.51), SIMDE_FLOAT32_C(  -917.56),
        SIMDE_FLOAT32_C(   255.56), SIMDE_FLOAT32_C(  -418.58), SIMDE_FLOAT32_C(   510.78), SIMDE_FLOAT32_C(  -591.24) },
      { -INT32_C(   129918451), -INT32_C(  1090726054),  INT32_C(  1589628805),  INT32_C(  2022242699),  INT32_C(    75185002),  INT32_C(  1462658127), -INT32_C(   998489249),  INT32_C(  1937869414) },
      { SIMDE_FLOAT32_C(  -136.89), SIMDE_FLOAT32_C(  -744.82), SIMDE_FLOAT32_C(   523.71), SIMDE_FLOAT32_C(  -482.42),
        SIMDE_FLOAT32_C(  -767.32), SIMDE_FLOAT32_C(  -565.02), SIMDE_FLOAT32_C(    70.98), SIMDE_FLOAT32_C(   934.33) },
      { SIMDE_FLOAT32_C(  -565.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -482.42),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   934.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 55),
      { SIMDE_FLOAT32_C(   314.41), SIMDE_FLOAT32_C(  -697.33), SIMDE_FLOAT32_C(    53.09), SIMDE_FLOAT32_C(   796.64),
        SIMDE_FLOAT32_C(   535.71), SIMDE_FLOAT32_C(  -979.67), SIMDE_FLOAT32_C(   246.41), SIMDE_FLOAT32_C(  -883.56) },
      {  INT32_C(   445605046), -INT32_C(   713431406), -INT32_C(   314884765), -INT32_C(  2146324546), -INT32_C(  2112254182), -INT32_C(   927320116), -INT32_C(  1195475533),  INT32_C(  1861820088) },
      { SIMDE_FLOAT32_C(   578.08), SIMDE_FLOAT32_C(   297.87), SIMDE_FLOAT32_C(  -199.20), SIMDE_FLOAT32_C(   802.62),
        SIMDE_FLOAT32_C(   669.47), SIMDE_FLOAT32_C(  -315.45), SIMDE_FLOAT32_C(   239.56), SIMDE_FLOAT32_C(  -367.47) },
      { SIMDE_FLOAT32_C(   246.41), SIMDE_FLOAT32_C(    53.09), SIMDE_FLOAT32_C(   796.64), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -199.20), SIMDE_FLOAT32_C(   669.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 62),
      { SIMDE_FLOAT32_C(  -529.68), SIMDE_FLOAT32_C(   697.84), SIMDE_FLOAT32_C(  -990.51), SIMDE_FLOAT32_C(  -216.18),
        SIMDE_FLOAT32_C(   626.27), SIMDE_FLOAT32_C(   322.97), SIMDE_FLOAT32_C(  -378.98), SIMDE_FLOAT32_C(  -927.72) },
      { -INT32_C(   869502315), -INT32_C(  1451232212), -INT32_C(   798934862), -INT32_C(  1185689807),  INT32_C(  1479043159),  INT32_C(  2023160402), -INT32_C(  1991404871), -INT32_C(  1544995570) },
      { SIMDE_FLOAT32_C(  -688.25), SIMDE_FLOAT32_C(   472.47), SIMDE_FLOAT32_C(  -265.39), SIMDE_FLOAT32_C(  -234.11),
        SIMDE_FLOAT32_C(   893.13), SIMDE_FLOAT32_C(  -132.62), SIMDE_FLOAT32_C(   834.04), SIMDE_FLOAT32_C(   -58.19) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   893.13), SIMDE_FLOAT32_C(  -990.51), SIMDE_FLOAT32_C(   697.84),
        SIMDE_FLOAT32_C(  -927.72), SIMDE_FLOAT32_C(  -990.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 38),
      { SIMDE_FLOAT32_C(   536.54), SIMDE_FLOAT32_C(   864.94), SIMDE_FLOAT32_C(   205.98), SIMDE_FLOAT32_C(   283.41),
        SIMDE_FLOAT32_C(  -633.86), SIMDE_FLOAT32_C(   390.80), SIMDE_FLOAT32_C(   831.07), SIMDE_FLOAT32_C(  -330.03) },
      {  INT32_C(   882533177), -INT32_C(  1947397383), -INT32_C(  1650886816),  INT32_C(  1967930464), -INT32_C(  1719785557), -INT32_C(  1866450261), -INT32_C(  1505486905),  INT32_C(  1659785000) },
      { SIMDE_FLOAT32_C(    69.15), SIMDE_FLOAT32_C(    32.54), SIMDE_FLOAT32_C(  -164.74), SIMDE_FLOAT32_C(  -684.15),
        SIMDE_FLOAT32_C(   259.61), SIMDE_FLOAT32_C(  -248.18), SIMDE_FLOAT32_C(   755.46), SIMDE_FLOAT32_C(  -715.79) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    32.54), SIMDE_FLOAT32_C(   536.54), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -684.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(250),
      { SIMDE_FLOAT32_C(  -289.06), SIMDE_FLOAT32_C(  -272.65), SIMDE_FLOAT32_C(  -909.98), SIMDE_FLOAT32_C(  -948.59),
        SIMDE_FLOAT32_C(   482.26), SIMDE_FLOAT32_C(   173.20), SIMDE_FLOAT32_C(  -873.51), SIMDE_FLOAT32_C(     3.04) },
      { -INT32_C(  2001383602),  INT32_C(   659506447), -INT32_C(   665848183),  INT32_C(  1821028836), -INT32_C(   888785593),  INT32_C(   985989483),  INT32_C(  2084905112),  INT32_C(  1032256495) },
      { SIMDE_FLOAT32_C(  -471.86), SIMDE_FLOAT32_C(   -34.05), SIMDE_FLOAT32_C(   306.29), SIMDE_FLOAT32_C(  -141.42),
        SIMDE_FLOAT32_C(  -784.81), SIMDE_FLOAT32_C(   156.97), SIMDE_FLOAT32_C(   656.49), SIMDE_FLOAT32_C(   639.22) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   639.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   482.26),
        SIMDE_FLOAT32_C(     3.04), SIMDE_FLOAT32_C(  -141.42), SIMDE_FLOAT32_C(  -471.86), SIMDE_FLOAT32_C(   639.22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256i idx = simde_mm256_loadu_epi32(test_vec[i].idx);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_maskz_permutex2var_ps(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i idx = simde_test_x86_random_i32x8();
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_maskz_permutex2var_ps(k, a, idx, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t idx[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 18651),  INT16_C( 19875), -INT16_C(  4478),  INT16_C( 31873),  INT16_C( 26710), -INT16_C( 10451),  INT16_C(  2377),  INT16_C( 28991),
         INT16_C( 20239),  INT16_C( 31981),  INT16_C( 18651), -INT16_C(  9085),  INT16_C( 11710), -INT16_C( 26943),  INT16_C(  2876),  INT16_C( 25170),
        -INT16_C(  2622),  INT16_C( 17839),  INT16_C( 12515),  INT16_C( 14785), -INT16_C(  4456), -INT16_C(  7920),  INT16_C( 20471),  INT16_C(  1618),
         INT16_C( 16287),  INT16_C( 31362),  INT16_C(  1671),  INT16_C( 17750),  INT16_C(  5939),  INT16_C( 28636),  INT16_C( 11810), -INT16_C(  6703) },
      { -INT16_C( 32733),  INT16_C(  1578), -INT16_C(  5200),  INT16_C( 18496),  INT16_C( 20697), -INT16_C( 12247),  INT16_C( 31648),  INT16_C( 16342),
         INT16_C( 22971),  INT16_C( 17081),  INT16_C(  3935), -INT16_C( 28024),  INT16_C( 25639),  INT16_C( 18689), -INT16_C( 11374), -INT16_C( 19154),
         INT16_C( 22611),  INT16_C(  1211), -INT16_C(  1213),  INT16_C(  7244),  INT16_C( 30284), -INT16_C(  4884), -INT16_C( 15375), -INT16_C( 21461),
        -INT16_C(  7140),  INT16_C( 31727),  INT16_C( 30707),  INT16_C(  6669),  INT16_C(  3803),  INT16_C( 28004), -INT16_C( 27935),  INT16_C( 13602) },
      { -INT16_C(  8725),  INT16_C( 11833), -INT16_C( 31271),  INT16_C(  9547),  INT16_C( 14331), -INT16_C(  4847),  INT16_C( 15610),  INT16_C(  5785),
        -INT16_C( 30688),  INT16_C(  5009), -INT16_C( 24833), -INT16_C(  9682), -INT16_C( 27987), -INT16_C( 29113),  INT16_C( 26916),  INT16_C(  4035),
        -INT16_C(   953),  INT16_C(  8254), -INT16_C( 30334),  INT16_C( 32069),  INT16_C( 22208), -INT16_C( 17558),  INT16_C(  1170), -INT16_C( 19759),
         INT16_C( 25484), -INT16_C( 29499), -INT16_C(  3327), -INT16_C( 20890), -INT16_C( 20859), -INT16_C( 21955),  INT16_C(    23),  INT16_C( 24249) },
      {  INT16_C(  9547), -INT16_C( 24833), -INT16_C(   953), -INT16_C( 18651),  INT16_C( 31362),  INT16_C(  5009), -INT16_C(  8725),  INT16_C( 20471),
        -INT16_C( 20890), -INT16_C( 29499), -INT16_C(  6703),  INT16_C( 20239),  INT16_C(  5785),  INT16_C( 19875),  INT16_C( 12515),  INT16_C( 26916),
         INT16_C( 14785), -INT16_C( 20890),  INT16_C( 31873),  INT16_C( 11710),  INT16_C( 11710), -INT16_C( 27987),  INT16_C(  8254), -INT16_C(  9682),
         INT16_C(  5939),  INT16_C(  4035),  INT16_C( 32069), -INT16_C( 26943),  INT16_C( 17750),  INT16_C( 14331),  INT16_C( 11833), -INT16_C( 31271) } },
    { { -INT16_C(  2051),  INT16_C( 32638), -INT16_C( 15488),  INT16_C( 16892),  INT16_C( 26393), -INT16_C( 21508), -INT16_C( 12949), -INT16_C(  2211),
         INT16_C(  9008),  INT16_C( 12931), -INT16_C(  5610), -INT16_C( 25376),  INT16_C(  7576), -INT16_C( 20666), -INT16_C(   226),  INT16_C(  6926),
        -INT16_C( 29449),  INT16_C( 30618), -INT16_C( 27056),  INT16_C( 27064), -INT16_C( 19203),  INT16_C( 26645),  INT16_C( 29314), -INT16_C( 19872),
        -INT16_C(  7275), -INT16_C( 21276), -INT16_C( 14899),  INT16_C( 25928), -INT16_C( 28958),  INT16_C(    21),  INT16_C(  9101), -INT16_C( 31717) },
      { -INT16_C( 19025), -INT16_C(     4), -INT16_C( 19380),  INT16_C( 18793),  INT16_C( 32361), -INT16_C(  5198),  INT16_C(  4848), -INT16_C( 31075),
        -INT16_C( 32011), -INT16_C( 15566),  INT16_C( 31303),  INT16_C( 10536),  INT16_C( 15624), -INT16_C( 27350),  INT16_C( 17760),  INT16_C(  4122),
         INT16_C(  5883),  INT16_C( 18191),  INT16_C( 30922),  INT16_C( 13200),  INT16_C( 17142), -INT16_C(  6370), -INT16_C( 17324),  INT16_C( 19053),
        -INT16_C( 24770), -INT16_C( 31475),  INT16_C( 13593),  INT16_C(  8622), -INT16_C( 10125), -INT16_C( 11338), -INT16_C( 12258),  INT16_C(  6627) },
      { -INT16_C(  3098), -INT16_C( 20128), -INT16_C(  3989),  INT16_C( 25316),  INT16_C(   819), -INT16_C( 30903), -INT16_C( 18753), -INT16_C(   559),
        -INT16_C(  8619),  INT16_C( 28290),  INT16_C( 12308), -INT16_C( 30833),  INT16_C( 17673),  INT16_C( 10074),  INT16_C( 15894), -INT16_C(   960),
        -INT16_C( 24527), -INT16_C( 25427), -INT16_C( 28016), -INT16_C( 15362),  INT16_C( 18325),  INT16_C( 21579),  INT16_C(  7421),  INT16_C( 21073),
        -INT16_C( 11269),  INT16_C(  4032),  INT16_C( 20227),  INT16_C(  3222), -INT16_C(  3947), -INT16_C( 21709),  INT16_C( 29486),  INT16_C( 24487) },
      { -INT16_C(   960), -INT16_C(  3947),  INT16_C(  7576),  INT16_C( 28290),  INT16_C( 28290), -INT16_C( 28016), -INT16_C( 24527),  INT16_C(    21),
         INT16_C( 21579), -INT16_C( 28016), -INT16_C(  2211), -INT16_C(  8619),  INT16_C(  9008),  INT16_C( 12308), -INT16_C(  3098), -INT16_C( 14899),
         INT16_C(  3222),  INT16_C(  6926), -INT16_C(  5610), -INT16_C( 29449),  INT16_C(  7421),  INT16_C(  9101), -INT16_C( 19203),  INT16_C( 10074),
         INT16_C( 29486), -INT16_C( 20666), -INT16_C( 21276),  INT16_C( 15894), -INT16_C( 15362),  INT16_C(  7421),  INT16_C(  9101),  INT16_C( 25316) } },
    { {  INT16_C( 21779), -INT16_C( 23300), -INT16_C(  1305),  INT16_C( 31847), -INT16_C( 19902),  INT16_C( 16336),  INT16_C(  8655), -INT16_C( 13678),
         INT16_C( 21236), -INT16_C(  2087),  INT16_C( 28578),  INT16_C( 14084),  INT16_C( 14175), -INT16_C( 28958), -INT16_C( 30293), -INT16_C( 16659),
        -INT16_C(  5666), -INT16_C( 15006), -INT16_C( 13596),  INT16_C(  9793),  INT16_C(  4476),  INT16_C( 19301), -INT16_C(  2254),  INT16_C(  9749),
        -INT16_C(  4534), -INT16_C(  5090),  INT16_C(  8797), -INT16_C( 17117),  INT16_C(  1369),  INT16_C(  1099),  INT16_C( 14478),  INT16_C( 28099) },
      {  INT16_C(  9506),  INT16_C(  1586),  INT16_C( 29935),  INT16_C( 27692), -INT16_C( 28283), -INT16_C( 18249), -INT16_C( 12919), -INT16_C( 11298),
        -INT16_C(   837),  INT16_C(  6591), -INT16_C(  7650),  INT16_C( 30934),  INT16_C(  8679),  INT16_C( 30076),  INT16_C( 16217),  INT16_C( 31714),
         INT16_C(  5477),  INT16_C( 21633), -INT16_C( 21111),  INT16_C(  3776),  INT16_C( 30783), -INT16_C( 14138), -INT16_C( 23227),  INT16_C(   155),
         INT16_C( 23201), -INT16_C( 16359), -INT16_C(  4292),  INT16_C(  9016), -INT16_C( 19440),  INT16_C( 27288),  INT16_C( 31732),  INT16_C( 23013) },
      {  INT16_C( 26512),  INT16_C(  6573),  INT16_C( 28180),  INT16_C( 21287), -INT16_C(  4378),  INT16_C( 11035), -INT16_C( 18797),  INT16_C( 13355),
         INT16_C( 17680),  INT16_C( 19700),  INT16_C( 11316),  INT16_C( 17775),  INT16_C(  2273), -INT16_C( 10833), -INT16_C( 27517),  INT16_C(  4910),
        -INT16_C(  9221),  INT16_C(  4140),  INT16_C( 21321),  INT16_C( 12131),  INT16_C( 32577), -INT16_C( 11174), -INT16_C( 31179),  INT16_C( 17929),
        -INT16_C(   565), -INT16_C(   110),  INT16_C(   554),  INT16_C(  2884), -INT16_C(  3318), -INT16_C( 29216),  INT16_C(  3720), -INT16_C( 31840) },
      {  INT16_C( 28180),  INT16_C( 21321),  INT16_C(  4910),  INT16_C(  2273),  INT16_C( 16336),  INT16_C( 17929), -INT16_C(  2087),  INT16_C( 14478),
         INT16_C(  2884), -INT16_C( 31840),  INT16_C( 14478), -INT16_C(  2254),  INT16_C( 13355), -INT16_C(  3318), -INT16_C(  5090),  INT16_C( 28180),
         INT16_C( 11035), -INT16_C( 23300), -INT16_C(  2087),  INT16_C( 21779), -INT16_C( 31840),  INT16_C(  8655),  INT16_C( 16336), -INT16_C( 17117),
         INT16_C(  6573), -INT16_C(  5090), -INT16_C(  3318), -INT16_C(   565), -INT16_C(  5666), -INT16_C(  4534),  INT16_C( 32577),  INT16_C( 11035) } },
    { { -INT16_C( 13079),  INT16_C( 13203), -INT16_C(  2273),  INT16_C( 24930), -INT16_C( 17034), -INT16_C( 21707),  INT16_C( 15939),  INT16_C(  3825),
        -INT16_C( 31684),  INT16_C( 26125),  INT16_C( 21126), -INT16_C( 28559),  INT16_C( 20805), -INT16_C( 13027), -INT16_C( 17057),  INT16_C( 18513),
        -INT16_C(  7031), -INT16_C( 22405), -INT16_C(  8485),  INT16_C( 20745),  INT16_C( 16283), -INT16_C(  8451), -INT16_C(  4483), -INT16_C( 17940),
        -INT16_C(  1678), -INT16_C(  2017), -INT16_C( 28597), -INT16_C( 28280), -INT16_C( 23071),  INT16_C( 16478), -INT16_C( 20638), -INT16_C(  5239) },
      {  INT16_C(  1172),  INT16_C( 28564), -INT16_C( 25118),  INT16_C( 32193), -INT16_C( 16676),  INT16_C( 23131),  INT16_C( 18348),  INT16_C(  7955),
         INT16_C( 13121), -INT16_C( 29673), -INT16_C( 24381), -INT16_C( 23267),  INT16_C( 31813), -INT16_C( 22299),  INT16_C( 28203), -INT16_C( 16493),
         INT16_C( 10099),  INT16_C( 21807), -INT16_C(  3899), -INT16_C( 24109),  INT16_C( 11950),  INT16_C( 23291),  INT16_C(  3958), -INT16_C( 18567),
        -INT16_C( 28350),  INT16_C(  1347),  INT16_C( 24881),  INT16_C( 30378), -INT16_C( 28451),  INT16_C(  2078), -INT16_C( 19714),  INT16_C( 29128) },
      { -INT16_C(  2087), -INT16_C( 24889), -INT16_C( 25881), -INT16_C( 27328),  INT16_C( 15304),  INT16_C( 16111),  INT16_C( 26954), -INT16_C( 29451),
         INT16_C( 14842),  INT16_C( 11154),  INT16_C( 15514),  INT16_C( 30625), -INT16_C( 16180), -INT16_C( 13441),  INT16_C( 18290),  INT16_C( 19260),
         INT16_C(   830),  INT16_C(  9706),  INT16_C( 10909),  INT16_C( 26298), -INT16_C( 21915), -INT16_C( 20316), -INT16_C( 26093),  INT16_C(  3388),
        -INT16_C( 12589),  INT16_C( 27960), -INT16_C(  9973), -INT16_C( 10268),  INT16_C( 25497),  INT16_C(  2978), -INT16_C(  8277), -INT16_C(  5801) },
      {  INT16_C( 16283),  INT16_C( 16283), -INT16_C( 25881),  INT16_C( 13203), -INT16_C( 23071), -INT16_C( 28280), -INT16_C( 16180),  INT16_C( 20745),
         INT16_C( 13203), -INT16_C( 17940),  INT16_C( 24930),  INT16_C( 16478), -INT16_C( 21707),  INT16_C( 16111),  INT16_C( 30625),  INT16_C( 20745),
         INT16_C( 26298),  INT16_C( 19260), -INT16_C( 21707),  INT16_C( 20745),  INT16_C( 18290), -INT16_C( 10268), -INT16_C( 26093),  INT16_C( 27960),
        -INT16_C(  2273),  INT16_C( 24930),  INT16_C(  9706),  INT16_C( 15514),  INT16_C( 16478), -INT16_C( 20638), -INT16_C(  8277), -INT16_C( 31684) } },
    { {  INT16_C( 16866), -INT16_C( 32753), -INT16_C( 13973), -INT16_C( 12058), -INT16_C( 30093), -INT16_C( 31104), -INT16_C( 17116), -INT16_C(  2157),
        -INT16_C( 13429), -INT16_C( 27036),  INT16_C( 18597),  INT16_C( 15982),  INT16_C(  4268),  INT16_C( 22346), -INT16_C( 24081), -INT16_C( 11712),
         INT16_C( 20450),  INT16_C( 19794),  INT16_C( 14361), -INT16_C( 29667), -INT16_C( 24894), -INT16_C(  6381), -INT16_C( 22949), -INT16_C(  6434),
         INT16_C( 17266),  INT16_C(  6013), -INT16_C(  5237),  INT16_C( 14165), -INT16_C( 24581), -INT16_C(  5234), -INT16_C( 12480),  INT16_C(  8893) },
      {  INT16_C(  3870),  INT16_C( 14191), -INT16_C( 29369),  INT16_C(  2500), -INT16_C( 10453), -INT16_C( 30992), -INT16_C( 12419), -INT16_C(  4244),
        -INT16_C(  5870), -INT16_C( 25338),  INT16_C( 23764), -INT16_C( 12075),  INT16_C( 25595),  INT16_C( 15547),  INT16_C( 30770),  INT16_C( 20830),
        -INT16_C( 12665), -INT16_C( 12664),  INT16_C( 19547), -INT16_C( 31017), -INT16_C( 14301), -INT16_C( 24308),  INT16_C( 30871), -INT16_C( 22128),
        -INT16_C( 26782),  INT16_C( 13894),  INT16_C(  7155), -INT16_C(  4602), -INT16_C( 16001), -INT16_C( 20182), -INT16_C( 30407), -INT16_C( 16382) },
      { -INT16_C( 29865), -INT16_C( 19826),  INT16_C( 26327), -INT16_C(  1224),  INT16_C( 17454), -INT16_C( 14948),  INT16_C( 11452),  INT16_C(  7790),
        -INT16_C( 19261), -INT16_C( 18859),  INT16_C( 23504),  INT16_C( 20389), -INT16_C( 12515),  INT16_C( 22016),  INT16_C(   856), -INT16_C( 20713),
        -INT16_C( 23154),  INT16_C( 25953), -INT16_C( 26357),  INT16_C( 14688), -INT16_C(   803), -INT16_C( 25858),  INT16_C( 27689), -INT16_C(  4936),
         INT16_C(  3361), -INT16_C(  3677),  INT16_C( 18537), -INT16_C( 31168),  INT16_C( 16407),  INT16_C( 28892), -INT16_C(  3261), -INT16_C( 12001) },
      { -INT16_C( 12480), -INT16_C( 20713), -INT16_C(  2157), -INT16_C( 30093),  INT16_C( 20389), -INT16_C( 23154),  INT16_C( 28892), -INT16_C( 12515),
         INT16_C( 14361), -INT16_C( 17116), -INT16_C( 24894), -INT16_C(  6381), -INT16_C( 31168), -INT16_C( 31168), -INT16_C( 26357), -INT16_C( 12480),
        -INT16_C(  2157), -INT16_C( 13429),  INT16_C( 14165), -INT16_C(  6434), -INT16_C(  1224),  INT16_C(  4268), -INT16_C(  6434),  INT16_C( 20450),
         INT16_C( 26327), -INT16_C( 17116),  INT16_C( 14688), -INT16_C( 17116), -INT16_C( 12001),  INT16_C( 23504), -INT16_C(  3677), -INT16_C( 13973) } },
    { { -INT16_C( 32359), -INT16_C( 23497), -INT16_C( 26854), -INT16_C(  1826), -INT16_C(  9068), -INT16_C( 17006),  INT16_C( 19017),  INT16_C( 27305),
         INT16_C( 19544), -INT16_C( 16037), -INT16_C( 25708), -INT16_C( 21433),  INT16_C(  9179),  INT16_C(  7964),  INT16_C( 15127), -INT16_C( 20240),
         INT16_C( 10172), -INT16_C( 10412),  INT16_C( 12991),  INT16_C( 21455),  INT16_C( 24847),  INT16_C( 22544), -INT16_C( 18005),  INT16_C(   962),
         INT16_C(  7430), -INT16_C( 25916),  INT16_C(  3000), -INT16_C( 27834),  INT16_C( 25135),  INT16_C( 18098), -INT16_C( 23650),  INT16_C( 23286) },
      {  INT16_C( 19146), -INT16_C( 30415),  INT16_C(   125), -INT16_C( 29476), -INT16_C(  5023),  INT16_C(  3556), -INT16_C( 22874), -INT16_C( 21488),
        -INT16_C( 10813),  INT16_C( 31558), -INT16_C( 29216),  INT16_C(  3854), -INT16_C( 15889), -INT16_C( 29355),  INT16_C( 19300),  INT16_C( 12008),
         INT16_C(  6550),  INT16_C(  5048), -INT16_C( 27622),  INT16_C( 31647), -INT16_C( 31871),  INT16_C( 10120), -INT16_C( 26327), -INT16_C(  4909),
         INT16_C(  6510),  INT16_C( 20071),  INT16_C( 30118), -INT16_C( 27042), -INT16_C( 19658), -INT16_C( 26077),  INT16_C(  3071), -INT16_C( 27191) },
      { -INT16_C( 32475),  INT16_C( 16296),  INT16_C( 18197), -INT16_C( 26950),  INT16_C( 17354), -INT16_C(  3139), -INT16_C( 28452),  INT16_C( 19167),
         INT16_C( 18090),  INT16_C( 20632), -INT16_C(  2373), -INT16_C(  3354),  INT16_C(  2730), -INT16_C( 22132),  INT16_C( 21781),  INT16_C( 14910),
        -INT16_C(  6442), -INT16_C(  4999),  INT16_C( 13357), -INT16_C(  2174),  INT16_C( 16503),  INT16_C( 21482), -INT16_C( 13872),  INT16_C( 31389),
         INT16_C( 13583), -INT16_C( 13621), -INT16_C( 20180), -INT16_C( 10564),  INT16_C( 18875), -INT16_C( 11905), -INT16_C( 16994),  INT16_C( 29963) },
      { -INT16_C( 25708), -INT16_C(  4999), -INT16_C( 11905),  INT16_C( 25135),  INT16_C( 16296),  INT16_C( 17354), -INT16_C( 28452),  INT16_C( 10172),
        -INT16_C(  1826),  INT16_C( 19017), -INT16_C( 32475),  INT16_C( 15127),  INT16_C( 14910),  INT16_C( 22544),  INT16_C( 17354),  INT16_C( 18090),
        -INT16_C( 18005),  INT16_C( 13583),  INT16_C(  3000),  INT16_C( 23286), -INT16_C( 23497),  INT16_C( 19544),  INT16_C( 20632),  INT16_C( 21455),
         INT16_C( 21781),  INT16_C( 19167), -INT16_C( 28452), -INT16_C( 23650), -INT16_C( 13872), -INT16_C( 26950),  INT16_C( 29963), -INT16_C( 16037) } },
    { { -INT16_C( 31325), -INT16_C( 12191), -INT16_C(  7239),  INT16_C( 12487), -INT16_C( 20189), -INT16_C(  2941),  INT16_C(  8314), -INT16_C( 30354),
         INT16_C( 14677), -INT16_C( 32429),  INT16_C(  4331), -INT16_C( 22953), -INT16_C( 10663), -INT16_C(  2185), -INT16_C( 31853),  INT16_C( 13932),
        -INT16_C( 13048), -INT16_C( 16122), -INT16_C( 12879), -INT16_C( 11023),  INT16_C( 29822), -INT16_C(  1848),  INT16_C( 14228), -INT16_C(  5759),
        -INT16_C( 10896),  INT16_C( 23403), -INT16_C( 15643),  INT16_C( 15874),  INT16_C( 31129),  INT16_C( 11317), -INT16_C( 23812),  INT16_C(  1123) },
      {  INT16_C( 26991),  INT16_C(  8389), -INT16_C( 18889), -INT16_C( 18955), -INT16_C( 17110), -INT16_C( 16722),  INT16_C( 12276),  INT16_C( 26024),
         INT16_C(  4868), -INT16_C(  5696), -INT16_C( 15659),  INT16_C( 28199),  INT16_C( 23868),  INT16_C( 14491), -INT16_C(   257),  INT16_C( 28221),
         INT16_C(   615), -INT16_C( 24945), -INT16_C( 31559), -INT16_C(  7340),  INT16_C(   577),  INT16_C( 13986),  INT16_C( 18993),  INT16_C( 13979),
         INT16_C( 23389),  INT16_C( 12831),  INT16_C( 18206),  INT16_C( 23201),  INT16_C( 15524), -INT16_C( 23662), -INT16_C( 12486), -INT16_C( 24303) },
      { -INT16_C( 24366), -INT16_C( 29888), -INT16_C( 27612),  INT16_C( 26222),  INT16_C(  4246), -INT16_C( 14436),  INT16_C( 14170), -INT16_C( 18435),
         INT16_C(  7570), -INT16_C( 20246), -INT16_C( 29852),  INT16_C(  2058), -INT16_C( 25145),  INT16_C(   427), -INT16_C( 17300),  INT16_C( 16034),
        -INT16_C(  7587), -INT16_C( 32311),  INT16_C( 14454),  INT16_C(  3303), -INT16_C( 31928), -INT16_C( 23596), -INT16_C( 11846),  INT16_C( 19802),
         INT16_C( 17646),  INT16_C( 21245),  INT16_C(  2255), -INT16_C( 27046),  INT16_C(  1445),  INT16_C(  4503),  INT16_C( 15042),  INT16_C(  8016) },
      {  INT16_C( 16034), -INT16_C(  2941),  INT16_C( 19802), -INT16_C( 23596), -INT16_C( 29852), -INT16_C( 17300), -INT16_C( 31928),  INT16_C(  7570),
        -INT16_C( 20189), -INT16_C( 31325), -INT16_C(  1848), -INT16_C( 18435),  INT16_C(  1445),  INT16_C( 15874),  INT16_C(  8016),  INT16_C(  4503),
        -INT16_C( 18435),  INT16_C( 13932),  INT16_C( 21245),  INT16_C( 29822), -INT16_C( 12191), -INT16_C( 27612), -INT16_C( 32311),  INT16_C( 15874),
         INT16_C( 11317),  INT16_C(  1123), -INT16_C( 23812), -INT16_C( 29888),  INT16_C(  4246), -INT16_C( 12879),  INT16_C(  2255), -INT16_C( 16122) } },
    { {  INT16_C(  6428), -INT16_C( 27744), -INT16_C( 30639), -INT16_C( 25953),  INT16_C( 29451), -INT16_C( 14787), -INT16_C( 26811),  INT16_C( 13075),
         INT16_C(  4316), -INT16_C( 21626), -INT16_C(  8168), -INT16_C( 17086), -INT16_C(  9754), -INT16_C( 22321),  INT16_C(  7955),  INT16_C( 12487),
         INT16_C( 26424), -INT16_C( 30013),  INT16_C( 25327), -INT16_C(  1244),  INT16_C( 25046),  INT16_C(  7105), -INT16_C( 11016), -INT16_C( 11186),
        -INT16_C( 11036), -INT16_C(   640), -INT16_C( 15691), -INT16_C( 25670), -INT16_C( 30309), -INT16_C( 20669),  INT16_C(  2728), -INT16_C(  7713) },
      { -INT16_C( 23951),  INT16_C( 24939), -INT16_C( 28924), -INT16_C(  9636),  INT16_C(  7664), -INT16_C(  5899),  INT16_C( 17649), -INT16_C( 10819),
         INT16_C( 15640), -INT16_C( 12846), -INT16_C( 29185), -INT16_C( 26008), -INT16_C( 21738), -INT16_C( 16567),  INT16_C( 10421),  INT16_C( 10144),
         INT16_C(  3018), -INT16_C( 12408), -INT16_C(  7014), -INT16_C( 30039), -INT16_C( 24831), -INT16_C(  3470),  INT16_C( 12259), -INT16_C(  1081),
        -INT16_C( 26004),  INT16_C( 27593),  INT16_C( 12583),  INT16_C( 15622),  INT16_C( 20445), -INT16_C( 27908), -INT16_C( 25480),  INT16_C( 17081) },
      {  INT16_C( 16807),  INT16_C( 16657), -INT16_C( 17627),  INT16_C(  9931),  INT16_C( 15962),  INT16_C( 15640), -INT16_C(  8083), -INT16_C(  9672),
         INT16_C(   378), -INT16_C( 24251),  INT16_C( 19251),  INT16_C(  4318), -INT16_C(  9317),  INT16_C(  5026),  INT16_C( 23671),  INT16_C(  8021),
         INT16_C( 26525), -INT16_C( 15520),  INT16_C( 11298),  INT16_C( 31977),  INT16_C(   618), -INT16_C( 10311), -INT16_C(  3614),  INT16_C( 23729),
        -INT16_C(  2061),  INT16_C(  9981), -INT16_C(  9406), -INT16_C(  8906), -INT16_C( 10058),  INT16_C( 12016),  INT16_C( 17972), -INT16_C( 11699) },
      { -INT16_C( 15520),  INT16_C(  4318),  INT16_C( 29451), -INT16_C( 30309),  INT16_C( 26525), -INT16_C( 10311), -INT16_C( 15520),  INT16_C( 12016),
        -INT16_C( 11036),  INT16_C( 25327), -INT16_C( 11699),  INT16_C(   378), -INT16_C( 11016), -INT16_C( 21626), -INT16_C( 10311),  INT16_C( 16807),
        -INT16_C(  8168),  INT16_C(  4316), -INT16_C( 15691), -INT16_C( 24251), -INT16_C( 27744),  INT16_C( 11298),  INT16_C(  9931),  INT16_C( 13075),
        -INT16_C(  9317), -INT16_C( 21626), -INT16_C(  9672), -INT16_C( 26811), -INT16_C( 20669), -INT16_C( 10058), -INT16_C(  2061),  INT16_C(  9981) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_permutex2var_epi16(a, idx, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_permutex2var_epi16(a, idx, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const simde__mmask32 k;
    const int16_t idx[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 21075), -INT16_C( 12395),  INT16_C( 32473),  INT16_C( 17227),  INT16_C(  1152),  INT16_C( 25115), -INT16_C( 13067), -INT16_C(  5954),
        -INT16_C( 17469),  INT16_C(  1550),  INT16_C( 17559),  INT16_C( 19939), -INT16_C( 11235),  INT16_C( 20859), -INT16_C( 14310), -INT16_C( 14557),
        -INT16_C( 18314),  INT16_C( 20374), -INT16_C(  7881), -INT16_C( 18541), -INT16_C( 20763), -INT16_C(  9702), -INT16_C( 10118),  INT16_C( 16067),
        -INT16_C( 11884),  INT16_C( 11076),  INT16_C( 10006),  INT16_C( 13176), -INT16_C(  2821),  INT16_C(  5508), -INT16_C( 22340),  INT16_C( 13020) },
      UINT32_C(2541908576),
      {  INT16_C(  5459),  INT16_C( 14415),  INT16_C( 27075),  INT16_C( 15635), -INT16_C( 10687), -INT16_C( 10885), -INT16_C( 16473), -INT16_C( 17152),
         INT16_C( 31207), -INT16_C(  7440),  INT16_C( 30061),  INT16_C( 10744), -INT16_C( 11235),  INT16_C( 32092), -INT16_C(  8633), -INT16_C( 26091),
         INT16_C( 25843), -INT16_C( 18733), -INT16_C(  6451),  INT16_C(  3827),  INT16_C( 28604),  INT16_C( 25572), -INT16_C(  7122),  INT16_C(  5409),
         INT16_C(  4445), -INT16_C( 13576), -INT16_C(  3962), -INT16_C( 23564),  INT16_C( 20676),  INT16_C(  2849),  INT16_C( 13870),  INT16_C(  8614) },
      {  INT16_C( 31130),  INT16_C( 26583), -INT16_C( 13729),  INT16_C(  7029),  INT16_C( 22841),  INT16_C( 26750), -INT16_C( 24770), -INT16_C( 25731),
         INT16_C( 30129),  INT16_C( 14182),  INT16_C( 23141),  INT16_C( 10971), -INT16_C(   854), -INT16_C( 10187), -INT16_C(  9422), -INT16_C( 13063),
        -INT16_C( 12204), -INT16_C( 19661), -INT16_C( 22374), -INT16_C( 11058),  INT16_C( 19714),  INT16_C( 16444), -INT16_C( 17940), -INT16_C( 25125),
         INT16_C( 16687), -INT16_C( 27435), -INT16_C( 20325),  INT16_C( 17854), -INT16_C(  2900), -INT16_C(  8675),  INT16_C(  5839),  INT16_C(  9386) },
      { -INT16_C( 21075), -INT16_C( 12395),  INT16_C( 32473),  INT16_C( 17227),  INT16_C(  1152),  INT16_C( 17854), -INT16_C( 25731), -INT16_C(  5954),
        -INT16_C( 17469), -INT16_C( 12204),  INT16_C( 17559),  INT16_C( 19939),  INT16_C(  5508), -INT16_C(  2821), -INT16_C(  5954), -INT16_C( 14557),
        -INT16_C( 18314), -INT16_C( 18541), -INT16_C(  7881), -INT16_C( 18541), -INT16_C( 20763), -INT16_C(  9702), -INT16_C( 10118),  INT16_C( 26583),
         INT16_C(  5508),  INT16_C( 16687), -INT16_C( 13067),  INT16_C( 13176),  INT16_C(  1152),  INT16_C(  5508), -INT16_C( 22340), -INT16_C( 24770) } },
    { { -INT16_C(  8730), -INT16_C( 32297), -INT16_C( 22907), -INT16_C( 30891), -INT16_C( 28173), -INT16_C(  8249), -INT16_C( 23734),  INT16_C( 31101),
         INT16_C( 21220), -INT16_C( 32754), -INT16_C( 13310), -INT16_C( 20795), -INT16_C(  7232), -INT16_C( 28532),  INT16_C( 14073), -INT16_C(  8012),
        -INT16_C( 29933), -INT16_C( 26527), -INT16_C( 18895),  INT16_C(  9248), -INT16_C(  6329), -INT16_C( 28412), -INT16_C( 32374),  INT16_C( 28427),
         INT16_C(  6611), -INT16_C( 10769), -INT16_C( 19227), -INT16_C( 22909),  INT16_C(  3991), -INT16_C( 28362), -INT16_C(  5563),  INT16_C( 22641) },
      UINT32_C(2817577589),
      {  INT16_C(  4232), -INT16_C( 12341), -INT16_C( 12296), -INT16_C( 32160),  INT16_C( 27472),  INT16_C(  9201), -INT16_C(  8060),  INT16_C( 27384),
         INT16_C( 31637),  INT16_C( 11280),  INT16_C( 18058), -INT16_C( 12355),  INT16_C( 11824), -INT16_C( 23257),  INT16_C(  6144), -INT16_C( 30644),
         INT16_C(  6184),  INT16_C(  8279), -INT16_C( 18201),  INT16_C( 14499), -INT16_C( 27613), -INT16_C( 22437),  INT16_C( 21621),  INT16_C(  2578),
         INT16_C(  8911),  INT16_C( 23094), -INT16_C(  2968), -INT16_C( 26583),  INT16_C( 20770),  INT16_C(  9021), -INT16_C( 30103), -INT16_C( 28245) },
      {  INT16_C(   930), -INT16_C( 30286),  INT16_C( 21947), -INT16_C(  8511),  INT16_C(  7657),  INT16_C( 24198), -INT16_C( 26511),  INT16_C( 16488),
        -INT16_C( 24646),  INT16_C(  8858), -INT16_C( 15213), -INT16_C( 19014), -INT16_C(  2027),  INT16_C( 32472), -INT16_C( 31614),  INT16_C(  9231),
        -INT16_C( 15993),  INT16_C( 17069),  INT16_C( 28438),  INT16_C(    32), -INT16_C( 22644), -INT16_C(   674), -INT16_C( 14529), -INT16_C(  1475),
        -INT16_C( 10138), -INT16_C(  1764), -INT16_C( 10340), -INT16_C( 20050), -INT16_C( 30769),  INT16_C( 20783),  INT16_C( 15883), -INT16_C( 28043) },
      {  INT16_C( 21220), -INT16_C( 32297), -INT16_C( 10138), -INT16_C( 30891), -INT16_C( 29933),  INT16_C( 17069), -INT16_C( 28173),  INT16_C( 31101),
         INT16_C( 21220), -INT16_C( 29933), -INT16_C( 13310), -INT16_C( 20795), -INT16_C( 15993), -INT16_C( 28532), -INT16_C(  8730), -INT16_C(  7232),
        -INT16_C( 29933), -INT16_C( 26527), -INT16_C( 18895),  INT16_C(  9248), -INT16_C(  8511), -INT16_C( 22909), -INT16_C(   674), -INT16_C( 18895),
        -INT16_C(  8012), -INT16_C( 14529), -INT16_C( 24646), -INT16_C( 22909),  INT16_C(  3991),  INT16_C( 20783), -INT16_C(  5563), -INT16_C( 19014) } },
    { {  INT16_C(  8704),  INT16_C(  5844), -INT16_C(  2927),  INT16_C(  7446),  INT16_C( 30107), -INT16_C(  9446),  INT16_C( 22588), -INT16_C( 23851),
        -INT16_C(  3792), -INT16_C( 13157),  INT16_C( 18888), -INT16_C( 26755), -INT16_C( 21296), -INT16_C(  9240),  INT16_C( 24042), -INT16_C(  5523),
         INT16_C( 16768),  INT16_C(  4353),  INT16_C(  5942), -INT16_C( 11985),  INT16_C( 18828), -INT16_C( 14164), -INT16_C( 32351), -INT16_C( 11926),
         INT16_C(  1395),  INT16_C( 15261),  INT16_C(  6735),  INT16_C(  8147), -INT16_C( 17466), -INT16_C( 19973),  INT16_C( 26649), -INT16_C( 26213) },
      UINT32_C(3769277610),
      { -INT16_C(  9804),  INT16_C( 16561),  INT16_C( 24099), -INT16_C( 15351),  INT16_C( 29663),  INT16_C( 21142),  INT16_C( 13177), -INT16_C( 14194),
         INT16_C( 24910),  INT16_C(  5351), -INT16_C(  7652),  INT16_C( 13765),  INT16_C( 24907), -INT16_C(  2610),  INT16_C( 31229), -INT16_C( 20011),
        -INT16_C( 31150),  INT16_C( 30194), -INT16_C(  1052), -INT16_C( 15302), -INT16_C( 12178), -INT16_C(  6378), -INT16_C( 23549),  INT16_C( 20911),
        -INT16_C( 26875),  INT16_C(  8806),  INT16_C( 11129), -INT16_C( 15273),  INT16_C(  9868), -INT16_C( 30023), -INT16_C( 29025), -INT16_C(  3781) },
      {  INT16_C( 11541), -INT16_C(  1689), -INT16_C( 24280), -INT16_C( 26691), -INT16_C( 11151),  INT16_C( 29822),  INT16_C( 11896),  INT16_C( 32454),
         INT16_C( 11461),  INT16_C( 16032), -INT16_C(  2217), -INT16_C(  7165), -INT16_C( 17379), -INT16_C( 17298), -INT16_C( 22197),  INT16_C( 24750),
         INT16_C(  5591), -INT16_C(   167),  INT16_C(  6070),  INT16_C( 10134),  INT16_C(  5611),  INT16_C( 25499),  INT16_C( 24899),  INT16_C(  2273),
        -INT16_C( 32371), -INT16_C(  6842),  INT16_C( 18809), -INT16_C( 26935),  INT16_C( 14086),  INT16_C( 20819),  INT16_C(   480), -INT16_C( 18511) },
      {  INT16_C(  8704), -INT16_C(   167), -INT16_C(  2927), -INT16_C( 13157),  INT16_C( 30107), -INT16_C( 32351),  INT16_C( 22588),  INT16_C( 24042),
        -INT16_C(  3792), -INT16_C( 13157), -INT16_C( 17466), -INT16_C(  9446), -INT16_C( 26755), -INT16_C(  9240),  INT16_C( 24042), -INT16_C( 14164),
         INT16_C( 16768),  INT16_C(  6070),  INT16_C(  5942),  INT16_C( 18809),  INT16_C( 18828), -INT16_C( 32351), -INT16_C( 32351),  INT16_C( 24750),
         INT16_C(  1395),  INT16_C( 15261),  INT16_C(  6735),  INT16_C(  8147), -INT16_C( 17466), -INT16_C(  6842), -INT16_C( 26213), -INT16_C( 26935) } },
    { {  INT16_C(  2582), -INT16_C( 13129),  INT16_C( 19745),  INT16_C(  3315), -INT16_C( 29086), -INT16_C( 23184),  INT16_C( 20976),  INT16_C( 32173),
        -INT16_C(  2861),  INT16_C( 19554),  INT16_C( 11069),  INT16_C( 17378),  INT16_C( 13666),  INT16_C( 17300),  INT16_C( 17718),  INT16_C( 19706),
        -INT16_C( 20144),  INT16_C( 28952),  INT16_C(  3071),  INT16_C( 24958), -INT16_C(  4454), -INT16_C( 30201), -INT16_C( 19393),  INT16_C(  4615),
         INT16_C( 27304), -INT16_C(  6562),  INT16_C( 16789), -INT16_C(  2007), -INT16_C( 16778), -INT16_C( 21189),  INT16_C( 13571),  INT16_C( 21497) },
      UINT32_C(3871675111),
      {  INT16_C( 17181), -INT16_C( 18617),  INT16_C( 20017),  INT16_C( 28737),  INT16_C( 18691), -INT16_C( 21629), -INT16_C(  7757),  INT16_C( 18577),
        -INT16_C( 17630), -INT16_C( 26304),  INT16_C( 31609),  INT16_C( 31814),  INT16_C( 16305), -INT16_C( 26416), -INT16_C( 27311),  INT16_C( 28542),
        -INT16_C( 14888),  INT16_C(  2342),  INT16_C( 26644),  INT16_C(  6009), -INT16_C(   847),  INT16_C( 25794),  INT16_C( 21726),  INT16_C(   172),
        -INT16_C(  4849), -INT16_C( 30567), -INT16_C(  8344),  INT16_C(  6404), -INT16_C( 11233),  INT16_C( 28849),  INT16_C( 12137),  INT16_C( 16863) },
      {  INT16_C(  1781),  INT16_C(  2378), -INT16_C( 15250),  INT16_C(  7968), -INT16_C(  7488), -INT16_C( 24957),  INT16_C( 12086),  INT16_C( 17823),
         INT16_C( 14364), -INT16_C( 31283), -INT16_C( 11752),  INT16_C( 14238),  INT16_C( 20646),  INT16_C(  4263), -INT16_C( 30849),  INT16_C( 29777),
        -INT16_C( 25459), -INT16_C(  1155), -INT16_C( 25248),  INT16_C(  8218), -INT16_C( 25216), -INT16_C( 18753),  INT16_C( 24268), -INT16_C(  5636),
        -INT16_C( 13930), -INT16_C( 20882),  INT16_C(  3227),  INT16_C( 17125), -INT16_C( 29348), -INT16_C(  9134), -INT16_C( 23788), -INT16_C( 24240) },
      { -INT16_C( 21189),  INT16_C( 32173), -INT16_C(  1155),  INT16_C(  3315), -INT16_C( 29086),  INT16_C(  3315),  INT16_C(  8218),  INT16_C( 28952),
        -INT16_C(  2861),  INT16_C(  2582),  INT16_C( 11069),  INT16_C( 17378), -INT16_C(  1155),  INT16_C( 17300),  INT16_C( 17718),  INT16_C( 19706),
         INT16_C( 27304),  INT16_C( 28952), -INT16_C(  4454),  INT16_C( 24958), -INT16_C(  4454), -INT16_C( 30201),  INT16_C( 13571),  INT16_C( 20646),
         INT16_C( 27304), -INT16_C(  6562),  INT16_C( 14364), -INT16_C(  2007), -INT16_C( 16778), -INT16_C(  1155), -INT16_C( 31283),  INT16_C( 21497) } },
    { { -INT16_C( 12737), -INT16_C( 24676), -INT16_C( 18837), -INT16_C(  5184),  INT16_C( 32595),  INT16_C(  8098), -INT16_C( 24867),  INT16_C( 29448),
         INT16_C( 30311),  INT16_C(   802),  INT16_C(  1923), -INT16_C(  8379), -INT16_C( 26732), -INT16_C( 22341),  INT16_C(  3130),  INT16_C( 31305),
        -INT16_C(  6694),  INT16_C( 17689), -INT16_C(  9829), -INT16_C(  4559), -INT16_C( 11432),  INT16_C( 13582),  INT16_C(  5745), -INT16_C( 10071),
        -INT16_C( 13427),  INT16_C(  4315),  INT16_C(  8402),  INT16_C( 26607), -INT16_C( 21577), -INT16_C(  3569),  INT16_C( 22967), -INT16_C( 28308) },
      UINT32_C(3671491902),
      {  INT16_C(  1887), -INT16_C( 18488), -INT16_C( 10534),  INT16_C( 19437), -INT16_C( 26899),  INT16_C( 31268), -INT16_C(   159),  INT16_C( 13194),
         INT16_C( 31008), -INT16_C( 10342), -INT16_C( 21980), -INT16_C(  9271),  INT16_C( 13571),  INT16_C( 16748),  INT16_C( 17339),  INT16_C(  6683),
        -INT16_C(  7094),  INT16_C(  9681), -INT16_C( 16710), -INT16_C( 22672), -INT16_C( 27564), -INT16_C( 19167), -INT16_C( 21612), -INT16_C( 19223),
        -INT16_C( 31963),  INT16_C( 18827),  INT16_C( 21805),  INT16_C( 12325), -INT16_C( 28278),  INT16_C( 17778), -INT16_C( 29228),  INT16_C(  8031) },
      {  INT16_C( 12657),  INT16_C( 11332), -INT16_C( 19217),  INT16_C( 17619), -INT16_C(  2743), -INT16_C(  8711), -INT16_C(  7520), -INT16_C( 14959),
         INT16_C(  7270), -INT16_C( 27889),  INT16_C( 13425), -INT16_C(   828),  INT16_C( 14021), -INT16_C( 26047), -INT16_C( 24125),  INT16_C( 13753),
        -INT16_C(   558), -INT16_C( 16031),  INT16_C( 13489), -INT16_C(  1531), -INT16_C(   215), -INT16_C( 13609),  INT16_C( 26849),  INT16_C( 18319),
        -INT16_C( 24955), -INT16_C(  2341), -INT16_C( 24622), -INT16_C( 26382),  INT16_C( 13525), -INT16_C( 26574), -INT16_C(  5163), -INT16_C( 22579) },
      { -INT16_C( 12737),  INT16_C( 30311),  INT16_C(  8402), -INT16_C( 26047), -INT16_C( 26047), -INT16_C(  2743), -INT16_C( 24867),  INT16_C( 29448),
         INT16_C( 12657),  INT16_C(   802), -INT16_C(  2743), -INT16_C(  8379), -INT16_C( 26732), -INT16_C( 22341),  INT16_C(  3130),  INT16_C( 26607),
        -INT16_C(  6694),  INT16_C( 17689), -INT16_C( 24622), -INT16_C(  4559), -INT16_C( 11432),  INT16_C( 13582), -INT16_C( 11432), -INT16_C( 27889),
        -INT16_C( 13427), -INT16_C(  8379),  INT16_C(  8402), -INT16_C(  8711),  INT16_C(  1923), -INT16_C(  3569), -INT16_C( 11432), -INT16_C( 28308) } },
    { {  INT16_C( 12008), -INT16_C( 26264),  INT16_C( 28259), -INT16_C( 29548),  INT16_C( 27501),  INT16_C( 20054), -INT16_C(  6444),  INT16_C( 22934),
         INT16_C( 29060),  INT16_C( 22351),  INT16_C( 16912), -INT16_C(  6673),  INT16_C(  8566),  INT16_C( 19325),  INT16_C( 19212), -INT16_C(  2830),
         INT16_C( 23161), -INT16_C(  9075),  INT16_C(  8648),  INT16_C( 13673), -INT16_C( 16499),  INT16_C( 24964),  INT16_C(  6821),  INT16_C( 10938),
         INT16_C(  2443), -INT16_C( 25727),  INT16_C( 28747), -INT16_C( 16000), -INT16_C(   623), -INT16_C( 25332), -INT16_C(   440), -INT16_C( 15727) },
      UINT32_C( 564010585),
      {  INT16_C(  1856), -INT16_C( 12969), -INT16_C(  9273),  INT16_C( 27694), -INT16_C(  5899), -INT16_C( 32618),  INT16_C(  6129),  INT16_C( 15643),
        -INT16_C( 25721),  INT16_C(  6398),  INT16_C(  2968), -INT16_C(  7755),  INT16_C( 17929),  INT16_C( 25251),  INT16_C( 16741), -INT16_C( 23164),
        -INT16_C(  9399),  INT16_C(  4210), -INT16_C( 24394), -INT16_C( 21636),  INT16_C(  5000),  INT16_C( 31019),  INT16_C( 17962), -INT16_C( 19786),
        -INT16_C( 18975),  INT16_C( 31178), -INT16_C( 32576), -INT16_C( 13990), -INT16_C(   570),  INT16_C( 11052), -INT16_C( 20417), -INT16_C( 30512) },
      {  INT16_C( 17035),  INT16_C( 16792),  INT16_C(  5346),  INT16_C( 27372),  INT16_C(  5927),  INT16_C( 21220), -INT16_C( 26019),  INT16_C( 15876),
        -INT16_C( 12721),  INT16_C(  4023),  INT16_C(  4686),  INT16_C(  5593),  INT16_C(  1295),  INT16_C( 20032),  INT16_C(  4533),  INT16_C( 16598),
         INT16_C( 28243),  INT16_C( 13953),  INT16_C( 28035), -INT16_C( 21856), -INT16_C( 31612), -INT16_C(  7684),  INT16_C(    31),  INT16_C( 28191),
        -INT16_C( 10545),  INT16_C(  7550),  INT16_C( 22504), -INT16_C(  1998),  INT16_C( 29532),  INT16_C(  4422),  INT16_C(  7556), -INT16_C( 10415) },
      {  INT16_C( 12008), -INT16_C( 26264),  INT16_C( 28259),  INT16_C(  4533), -INT16_C(  7684),  INT16_C( 20054),  INT16_C( 13953),  INT16_C( 22934),
         INT16_C( 29060),  INT16_C(  7556),  INT16_C(  2443), -INT16_C(  7684),  INT16_C( 22351),  INT16_C( 19325),  INT16_C( 19212), -INT16_C(  2830),
         INT16_C( 23161),  INT16_C( 28035),  INT16_C(    31),  INT16_C( 29532),  INT16_C( 29060),  INT16_C( 24964),  INT16_C(  6821),  INT16_C(    31),
         INT16_C( 16792), -INT16_C( 25727),  INT16_C( 28747), -INT16_C( 16000), -INT16_C(   623),  INT16_C(  1295), -INT16_C(   440), -INT16_C( 15727) } },
    { { -INT16_C( 11637),  INT16_C(  3597), -INT16_C( 20929), -INT16_C( 15431), -INT16_C( 19150),  INT16_C( 20900), -INT16_C( 15434), -INT16_C( 31296),
         INT16_C( 16025), -INT16_C( 32094), -INT16_C( 10859), -INT16_C(  3718), -INT16_C( 16312), -INT16_C( 13310),  INT16_C( 21469),  INT16_C( 27043),
        -INT16_C( 20187),  INT16_C( 25719),  INT16_C( 12383), -INT16_C( 28377), -INT16_C( 13338), -INT16_C( 25373), -INT16_C( 23666),  INT16_C( 10017),
        -INT16_C( 15391),  INT16_C( 30377),  INT16_C(  9112), -INT16_C(  8089),  INT16_C( 27108), -INT16_C( 15956),  INT16_C( 20668), -INT16_C(  7894) },
      UINT32_C(1615176193),
      {  INT16_C( 27858), -INT16_C( 18191), -INT16_C( 11209), -INT16_C( 15020),  INT16_C( 30071),  INT16_C( 22764), -INT16_C( 27079), -INT16_C( 11826),
         INT16_C( 13753), -INT16_C( 25166),  INT16_C( 24222),  INT16_C( 23135), -INT16_C( 30290), -INT16_C( 20677), -INT16_C( 32725), -INT16_C(   497),
         INT16_C(   492),  INT16_C(  9142),  INT16_C(  3029),  INT16_C( 19944), -INT16_C( 10880), -INT16_C( 18011),  INT16_C( 29803),  INT16_C(  9355),
         INT16_C( 15785),  INT16_C( 18626),  INT16_C(  8603),  INT16_C( 19106), -INT16_C(  8534), -INT16_C( 10503),  INT16_C(  2398),  INT16_C( 19412) },
      { -INT16_C( 30198), -INT16_C(  8338),  INT16_C( 22421),  INT16_C(  5676), -INT16_C( 11732), -INT16_C( 26673),  INT16_C( 23110), -INT16_C(  4165),
         INT16_C( 32151),  INT16_C( 13111), -INT16_C(  9570),  INT16_C( 18813),  INT16_C( 30392),  INT16_C(  5663), -INT16_C(  3201), -INT16_C( 30367),
        -INT16_C( 12163),  INT16_C(  4969), -INT16_C( 27353),  INT16_C( 21289), -INT16_C(  1945), -INT16_C( 21014), -INT16_C( 23213), -INT16_C(  5475),
        -INT16_C( 11229), -INT16_C( 16099), -INT16_C( 25938),  INT16_C( 26122),  INT16_C( 10513), -INT16_C( 28547), -INT16_C(  8676), -INT16_C( 26086) },
      {  INT16_C( 12383),  INT16_C(  3597), -INT16_C( 20929), -INT16_C( 15431), -INT16_C( 19150),  INT16_C( 20900), -INT16_C( 15434), -INT16_C( 31296),
         INT16_C( 16025), -INT16_C( 27353), -INT16_C( 10859), -INT16_C(  3718), -INT16_C( 16312),  INT16_C( 26122),  INT16_C( 21469),  INT16_C( 27043),
         INT16_C( 30392),  INT16_C( 25719), -INT16_C( 25373), -INT16_C( 28377), -INT16_C( 13338), -INT16_C( 25373),  INT16_C( 18813),  INT16_C( 10017),
        -INT16_C( 15391),  INT16_C( 30377),  INT16_C(  9112), -INT16_C(  8089),  INT16_C( 27108), -INT16_C( 16099),  INT16_C( 20668), -INT16_C(  7894) } },
    { { -INT16_C( 31826), -INT16_C( 10835), -INT16_C( 10728), -INT16_C( 32728),  INT16_C(  4814),  INT16_C(  8493), -INT16_C( 13640), -INT16_C(  9460),
         INT16_C( 10655),  INT16_C( 19868), -INT16_C( 22588), -INT16_C( 10828),  INT16_C( 12752), -INT16_C(  4763),  INT16_C( 32527), -INT16_C( 16761),
         INT16_C( 13314),  INT16_C(  7059), -INT16_C( 17398), -INT16_C( 10085), -INT16_C( 14130), -INT16_C( 30982),  INT16_C(  1683),  INT16_C( 12897),
        -INT16_C(   465), -INT16_C(  3201),  INT16_C( 13221),  INT16_C( 30152),  INT16_C( 11876),  INT16_C( 29794), -INT16_C(  5715), -INT16_C( 20430) },
      UINT32_C( 667665693),
      {  INT16_C( 26241),  INT16_C( 20480), -INT16_C(  1490), -INT16_C( 15914),  INT16_C( 14336),  INT16_C( 12275),  INT16_C( 29494), -INT16_C(  9437),
        -INT16_C(  5210),  INT16_C(  2896), -INT16_C( 19687), -INT16_C( 14465), -INT16_C( 20068), -INT16_C( 17801),  INT16_C( 17014), -INT16_C(  1823),
        -INT16_C(  7768), -INT16_C( 10680),  INT16_C(  7899), -INT16_C(  9320), -INT16_C( 29866), -INT16_C( 29685),  INT16_C( 12030), -INT16_C( 23193),
        -INT16_C( 18407),  INT16_C( 13232),  INT16_C( 12139),  INT16_C(  2042),  INT16_C( 29152),  INT16_C( 22209), -INT16_C( 23629),  INT16_C( 23374) },
      { -INT16_C( 27004),  INT16_C( 24625), -INT16_C( 13899),  INT16_C(  2875),  INT16_C( 18005),  INT16_C( 21400), -INT16_C(   140), -INT16_C( 28936),
        -INT16_C( 22345),  INT16_C(  8897), -INT16_C( 17449), -INT16_C( 18646), -INT16_C(  5332), -INT16_C(  8434),  INT16_C( 23694),  INT16_C(  4922),
         INT16_C( 27635), -INT16_C( 22413), -INT16_C( 20939), -INT16_C( 30029),  INT16_C( 19445),  INT16_C( 27101), -INT16_C( 10677),  INT16_C(   759),
        -INT16_C( 18306),  INT16_C( 22053),  INT16_C( 20339), -INT16_C( 24819),  INT16_C(  6970), -INT16_C( 13954), -INT16_C( 18312),  INT16_C( 27612) },
      { -INT16_C( 10835), -INT16_C( 10835),  INT16_C( 23694),  INT16_C(  1683), -INT16_C( 31826),  INT16_C(  8493), -INT16_C( 13640), -INT16_C(  9460),
        -INT16_C(   140),  INT16_C( 19868), -INT16_C(  3201), -INT16_C( 10828),  INT16_C( 12752), -INT16_C(  4763), -INT16_C( 10677),  INT16_C( 24625),
        -INT16_C( 22345),  INT16_C( 10655), -INT16_C( 17398), -INT16_C(   465), -INT16_C( 14130), -INT16_C( 30982), -INT16_C( 18312), -INT16_C( 28936),
        -INT16_C(  3201),  INT16_C( 27635), -INT16_C( 18646),  INT16_C( 30152),  INT16_C( 11876), -INT16_C( 10835), -INT16_C(  5715), -INT16_C( 20430) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_permutex2var_epi16(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_permutex2var_epi16(a, k, idx, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask2_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t idx[32];
    const simde__mmask32 k;
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 20260),  INT16_C( 22803), -INT16_C( 14595), -INT16_C(  3357), -INT16_C( 16366),  INT16_C( 23900),  INT16_C( 21398),  INT16_C(  5471),
        -INT16_C( 31732),  INT16_C( 32619),  INT16_C( 30931),  INT16_C(  3615), -INT16_C( 25196),  INT16_C(  3287), -INT16_C( 19626),  INT16_C( 31351),
        -INT16_C( 30206), -INT16_C(    45), -INT16_C( 18864),  INT16_C( 25330),  INT16_C( 20086),  INT16_C(  3519),  INT16_C(  8097), -INT16_C( 21214),
        -INT16_C( 29277),  INT16_C( 30509),  INT16_C( 19461), -INT16_C( 26235),  INT16_C( 23785),  INT16_C( 16293),  INT16_C(  7183),  INT16_C(  4537) },
      { -INT16_C( 29530), -INT16_C(  2288),  INT16_C(   578), -INT16_C( 18087),  INT16_C(  6480), -INT16_C(  3386), -INT16_C(  6088), -INT16_C(  9313),
        -INT16_C( 13195),  INT16_C( 31314), -INT16_C( 10472),  INT16_C(   532), -INT16_C( 18125),  INT16_C( 16961), -INT16_C(  1066),  INT16_C( 31827),
         INT16_C( 25735), -INT16_C( 13709), -INT16_C( 12954), -INT16_C( 18557),  INT16_C( 18918),  INT16_C(  7849),  INT16_C( 18481), -INT16_C( 22791),
         INT16_C( 19477),  INT16_C( 11552),  INT16_C( 13347),  INT16_C( 22319),  INT16_C( 29166), -INT16_C( 15207), -INT16_C(  4756), -INT16_C(  3264) },
      UINT32_C(3082662993),
      {  INT16_C( 16513),  INT16_C( 26478),  INT16_C(  6025), -INT16_C( 17787),  INT16_C( 32352),  INT16_C( 30048), -INT16_C( 32310), -INT16_C(  4446),
        -INT16_C( 11595), -INT16_C( 23739), -INT16_C(  8637), -INT16_C( 20633), -INT16_C( 22325),  INT16_C(  7330),  INT16_C( 24668), -INT16_C(  8748),
         INT16_C( 17056),  INT16_C( 10820), -INT16_C( 13990), -INT16_C( 17692),  INT16_C( 17735),  INT16_C(  4655), -INT16_C( 11834),  INT16_C( 31488),
         INT16_C( 17827), -INT16_C(  6625), -INT16_C( 31197), -INT16_C(  4203),  INT16_C( 14382), -INT16_C( 30197), -INT16_C(  8296),  INT16_C( 14439) },
      { -INT16_C( 32310), -INT16_C(  2288),  INT16_C(   578), -INT16_C( 18087), -INT16_C( 30206), -INT16_C(  3386),  INT16_C( 17827), -INT16_C(  9313),
        -INT16_C( 13195),  INT16_C( 31314), -INT16_C( 29277),  INT16_C(   532), -INT16_C( 17692),  INT16_C( 22803), -INT16_C(  1066),  INT16_C( 25330),
         INT16_C(  5471), -INT16_C( 13709), -INT16_C( 32310), -INT16_C(  3357), -INT16_C( 32310), -INT16_C( 23739),  INT16_C( 18481), -INT16_C(  6625),
         INT16_C(  3519),  INT16_C( 16513), -INT16_C( 17787),  INT16_C( 22319),  INT16_C( 24668),  INT16_C( 30509), -INT16_C(  4756),  INT16_C( 20260) } },
    { { -INT16_C( 21726),  INT16_C( 31842),  INT16_C( 18292), -INT16_C( 17354),  INT16_C( 25996),  INT16_C( 21198), -INT16_C( 12746), -INT16_C(  9523),
        -INT16_C(  5101),  INT16_C( 14016),  INT16_C( 22131), -INT16_C( 24283),  INT16_C( 12686),  INT16_C(  9772), -INT16_C( 27888),  INT16_C( 12894),
        -INT16_C( 16065), -INT16_C( 19538), -INT16_C(  7160), -INT16_C( 27537),  INT16_C( 15689), -INT16_C( 32538), -INT16_C( 19701),  INT16_C(  7770),
         INT16_C(  6816),  INT16_C(  4949),  INT16_C( 31344), -INT16_C(   332), -INT16_C(  8021), -INT16_C( 17372), -INT16_C( 31884), -INT16_C( 19474) },
      { -INT16_C( 25276),  INT16_C( 19558), -INT16_C( 10623), -INT16_C( 13344), -INT16_C( 14829),  INT16_C(  8011), -INT16_C( 23175),  INT16_C(  6461),
        -INT16_C( 27969),  INT16_C( 12332), -INT16_C(  7923), -INT16_C( 18386),  INT16_C( 21441),  INT16_C( 13684),  INT16_C( 25558),  INT16_C(  6888),
         INT16_C( 20224), -INT16_C( 32410),  INT16_C( 17957),  INT16_C( 14412), -INT16_C( 26868), -INT16_C( 31401), -INT16_C( 27332), -INT16_C(   865),
        -INT16_C( 13529),  INT16_C( 13356),  INT16_C( 23212),  INT16_C( 28397),  INT16_C( 25005), -INT16_C( 31837), -INT16_C( 29500), -INT16_C( 15203) },
      UINT32_C(   4588507),
      { -INT16_C( 28087),  INT16_C( 21816), -INT16_C( 28630),  INT16_C( 26331),  INT16_C( 31269),  INT16_C( 19554), -INT16_C( 29115), -INT16_C(  3455),
         INT16_C( 28393), -INT16_C( 27040),  INT16_C(   975), -INT16_C( 27622), -INT16_C( 18545),  INT16_C( 27224), -INT16_C( 24901),  INT16_C(  1130),
        -INT16_C( 23759),  INT16_C( 23386),  INT16_C( 13619),  INT16_C( 22721),  INT16_C(  9391), -INT16_C(  2908),  INT16_C(  9650), -INT16_C( 25626),
         INT16_C( 18067),  INT16_C( 25394),  INT16_C( 19530), -INT16_C(  9737),  INT16_C( 20227), -INT16_C( 16828), -INT16_C( 20754),  INT16_C(  8131) },
      {  INT16_C( 25996), -INT16_C( 29115), -INT16_C( 10623), -INT16_C( 28087), -INT16_C( 27537),  INT16_C(  8011),  INT16_C( 25394), -INT16_C( 16828),
         INT16_C(  8131), -INT16_C( 18545), -INT16_C(  7923), -INT16_C( 18386),  INT16_C( 21441),  INT16_C( 13684),  INT16_C( 25558),  INT16_C(  6888),
         INT16_C( 20224), -INT16_C( 29115),  INT16_C( 19554),  INT16_C( 14412), -INT16_C( 26868), -INT16_C( 31401),  INT16_C( 20227), -INT16_C(   865),
        -INT16_C( 13529),  INT16_C( 13356),  INT16_C( 23212),  INT16_C( 28397),  INT16_C( 25005), -INT16_C( 31837), -INT16_C( 29500), -INT16_C( 15203) } },
    { {  INT16_C(  7505), -INT16_C( 31622),  INT16_C( 15186),  INT16_C(   476), -INT16_C( 32417),  INT16_C(  4853), -INT16_C(  9050),  INT16_C( 15021),
        -INT16_C(  8414),  INT16_C( 27805), -INT16_C( 27605),  INT16_C( 12102), -INT16_C( 29981), -INT16_C( 11795), -INT16_C( 20424), -INT16_C( 29968),
         INT16_C( 27341),  INT16_C(  7950), -INT16_C(  5210),  INT16_C(  1312),  INT16_C(  5740),  INT16_C(  4631), -INT16_C( 14862),  INT16_C(  5196),
        -INT16_C(  5724), -INT16_C( 12159), -INT16_C( 14467),  INT16_C( 25087), -INT16_C(  5039), -INT16_C( 30414),  INT16_C(  9117),  INT16_C( 27155) },
      {  INT16_C(  8845),  INT16_C( 13194), -INT16_C( 22003),  INT16_C( 31033),  INT16_C( 20672), -INT16_C( 19829), -INT16_C( 10219), -INT16_C( 17721),
         INT16_C( 18625),  INT16_C( 16266), -INT16_C( 30449),  INT16_C( 24736), -INT16_C( 11659),  INT16_C(  4841), -INT16_C(   523), -INT16_C( 31875),
         INT16_C(  1823),  INT16_C( 11446), -INT16_C(  4175),  INT16_C( 29349),  INT16_C( 12352),  INT16_C( 21796), -INT16_C(  5368), -INT16_C( 13809),
        -INT16_C( 26317),  INT16_C( 16905), -INT16_C( 22238), -INT16_C( 26462), -INT16_C( 29573),  INT16_C( 29098),  INT16_C( 10121), -INT16_C( 22284) },
      UINT32_C(3772033582),
      {  INT16_C( 31130), -INT16_C(  9646),  INT16_C( 30377), -INT16_C( 19921),  INT16_C( 16226), -INT16_C( 27268), -INT16_C( 31272), -INT16_C(  1064),
         INT16_C( 31278), -INT16_C( 22125),  INT16_C( 15622), -INT16_C( 28902),  INT16_C(  3685), -INT16_C( 27849),  INT16_C(  3001),  INT16_C( 21363),
        -INT16_C( 14972),  INT16_C( 11821),  INT16_C( 23612), -INT16_C( 24864),  INT16_C( 23707),  INT16_C( 29747),  INT16_C(  3041),  INT16_C(  3951),
         INT16_C(   646), -INT16_C( 29512), -INT16_C( 11457), -INT16_C( 23524),  INT16_C( 21473), -INT16_C( 26056), -INT16_C( 21665), -INT16_C(  7187) },
      {  INT16_C(  8845), -INT16_C( 27605), -INT16_C( 11795), -INT16_C( 29512),  INT16_C( 20672),  INT16_C( 12102), -INT16_C( 10219), -INT16_C( 17721),
         INT16_C( 18625), -INT16_C( 27605), -INT16_C( 30449),  INT16_C( 31130), -INT16_C( 11659), -INT16_C( 22125), -INT16_C(   523), -INT16_C( 26056),
         INT16_C(  1823),  INT16_C( 11446),  INT16_C( 11821),  INT16_C( 29349),  INT16_C(  7505),  INT16_C( 21796), -INT16_C(  8414), -INT16_C( 29968),
        -INT16_C( 26317),  INT16_C( 16905), -INT16_C( 22238), -INT16_C( 26462), -INT16_C( 29573),  INT16_C( 15622),  INT16_C( 27805),  INT16_C( 23707) } },
    { {  INT16_C(  6769), -INT16_C( 21231), -INT16_C(  3721),  INT16_C(  4683),  INT16_C( 32333),  INT16_C( 11910), -INT16_C(  2678),  INT16_C(  4157),
        -INT16_C(  2313),  INT16_C( 14236), -INT16_C( 18231), -INT16_C( 21797),  INT16_C(  4876),  INT16_C( 27461),  INT16_C( 12991),  INT16_C( 12366),
         INT16_C( 24653), -INT16_C( 15139),  INT16_C( 10321), -INT16_C( 24618),  INT16_C( 23974),  INT16_C( 12493),  INT16_C(  2898),  INT16_C( 19008),
        -INT16_C(  8959), -INT16_C( 13695),  INT16_C( 23701), -INT16_C( 24204), -INT16_C( 18064),  INT16_C( 12044),  INT16_C( 23532),  INT16_C( 14687) },
      {  INT16_C( 15547),  INT16_C(  3325), -INT16_C( 11420),  INT16_C(  2731),  INT16_C( 31024), -INT16_C( 31941),  INT16_C( 31620), -INT16_C( 31283),
         INT16_C( 20056), -INT16_C(  4529), -INT16_C( 15446),  INT16_C(  6799), -INT16_C( 25475),  INT16_C( 26953), -INT16_C( 22281), -INT16_C( 19806),
        -INT16_C( 24604),  INT16_C( 18622),  INT16_C( 27250), -INT16_C( 23725), -INT16_C( 28957),  INT16_C( 26406), -INT16_C(  3319),  INT16_C( 25324),
         INT16_C( 15169), -INT16_C(  5296), -INT16_C(  8194),  INT16_C( 31494),  INT16_C( 20347),  INT16_C( 29412), -INT16_C( 30984), -INT16_C(  9180) },
      UINT32_C(2552619813),
      {  INT16_C( 30797),  INT16_C( 12347),  INT16_C( 24838),  INT16_C(  3991), -INT16_C( 31916), -INT16_C( 27279), -INT16_C( 15938), -INT16_C( 17280),
        -INT16_C( 31071),  INT16_C(  7224),  INT16_C(  7382), -INT16_C( 12657), -INT16_C( 19549), -INT16_C( 14166), -INT16_C( 12394), -INT16_C(  7328),
        -INT16_C( 25785),  INT16_C( 19731), -INT16_C( 21764),  INT16_C( 20573), -INT16_C( 12755), -INT16_C(  5147),  INT16_C( 26256),  INT16_C( 12712),
        -INT16_C(  7956), -INT16_C( 15795), -INT16_C(  8964), -INT16_C( 24688),  INT16_C( 15248),  INT16_C(  9832), -INT16_C( 14326),  INT16_C( 21002) },
      { -INT16_C( 24688),  INT16_C(  3325), -INT16_C( 31916),  INT16_C(  2731),  INT16_C( 31024), -INT16_C( 24688),  INT16_C( 31620), -INT16_C( 31283),
        -INT16_C(  8959),  INT16_C( 12366), -INT16_C( 15446),  INT16_C(  6799), -INT16_C( 25475),  INT16_C( 14236),  INT16_C( 12712),  INT16_C( 24838),
        -INT16_C( 31916),  INT16_C( 18622), -INT16_C( 21764), -INT16_C( 23725), -INT16_C( 28957), -INT16_C( 15938), -INT16_C(  3319),  INT16_C( 25324),
         INT16_C( 15169), -INT16_C(  5296), -INT16_C(  8194), -INT16_C(  2678), -INT16_C( 24688),  INT16_C( 29412), -INT16_C( 30984), -INT16_C( 31916) } },
    { {  INT16_C(  7524),  INT16_C( 24735), -INT16_C(   824), -INT16_C(  2639), -INT16_C( 26933),  INT16_C( 23521), -INT16_C( 30212), -INT16_C(  5748),
        -INT16_C(  9879),  INT16_C( 26027),  INT16_C( 15542),  INT16_C( 17925),  INT16_C( 28023), -INT16_C( 32404),  INT16_C( 30261), -INT16_C( 26157),
         INT16_C( 29588),  INT16_C( 23802), -INT16_C( 21649),  INT16_C( 14929),  INT16_C( 12865),  INT16_C( 16021),  INT16_C(  8635),  INT16_C(  9255),
        -INT16_C( 11525), -INT16_C( 20086), -INT16_C( 28914), -INT16_C( 31241),  INT16_C( 25596),  INT16_C( 12551), -INT16_C(  9510),  INT16_C( 28363) },
      { -INT16_C( 15027), -INT16_C( 16950),  INT16_C(  7024), -INT16_C( 19977), -INT16_C( 29362),  INT16_C(  2543),  INT16_C(  5806), -INT16_C( 22226),
        -INT16_C( 18199), -INT16_C(  2214),  INT16_C( 20807),  INT16_C( 17277), -INT16_C( 31563), -INT16_C( 28812),  INT16_C( 16222), -INT16_C( 21251),
        -INT16_C( 14588),  INT16_C( 29801),  INT16_C( 24802),  INT16_C( 12326),  INT16_C(  5613), -INT16_C( 25542),  INT16_C( 26668),  INT16_C(  5445),
        -INT16_C( 24544),  INT16_C( 26380), -INT16_C( 30223), -INT16_C( 22870),  INT16_C(  7693),  INT16_C( 27701),  INT16_C( 12894),  INT16_C( 25112) },
      UINT32_C(3705111033),
      { -INT16_C(   543), -INT16_C( 12532),  INT16_C( 17938),  INT16_C( 15979), -INT16_C( 20306), -INT16_C( 12717),  INT16_C( 24656),  INT16_C( 16949),
        -INT16_C(  8215), -INT16_C(  2072),  INT16_C(  7934),  INT16_C( 23651),  INT16_C( 31568),  INT16_C( 19134), -INT16_C( 27140), -INT16_C(  8922),
         INT16_C( 12946), -INT16_C( 23124),  INT16_C(  6009),  INT16_C( 10211),  INT16_C( 14280),  INT16_C(  6390),  INT16_C( 11159), -INT16_C( 32678),
         INT16_C( 17163),  INT16_C(  2423), -INT16_C(  9631), -INT16_C( 20123),  INT16_C(  9045),  INT16_C( 20987),  INT16_C(  8633),  INT16_C( 19247) },
      { -INT16_C( 32404), -INT16_C( 16950),  INT16_C(  7024), -INT16_C( 32678),  INT16_C( 30261), -INT16_C(  8922), -INT16_C( 27140), -INT16_C( 27140),
        -INT16_C(  2072), -INT16_C(  2214),  INT16_C( 20807),  INT16_C( 17277), -INT16_C( 31563), -INT16_C( 28812),  INT16_C( 16222),  INT16_C( 20987),
        -INT16_C( 26933), -INT16_C(  2072),  INT16_C( 17938),  INT16_C( 12326),  INT16_C( 19134), -INT16_C( 25542),  INT16_C( 31568),  INT16_C( 23521),
        -INT16_C( 24544),  INT16_C( 26380), -INT16_C( 23124),  INT16_C(  7934), -INT16_C( 32404),  INT16_C( 27701), -INT16_C(  9510), -INT16_C( 11525) } },
    { { -INT16_C(  9388), -INT16_C( 12816), -INT16_C( 11021), -INT16_C( 17420), -INT16_C(  5621), -INT16_C( 23853),  INT16_C( 11798),  INT16_C(  8482),
        -INT16_C( 25999), -INT16_C( 11734), -INT16_C( 28812), -INT16_C( 13693),  INT16_C( 32690),  INT16_C( 27419),  INT16_C( 19104), -INT16_C(  2889),
        -INT16_C( 22746),  INT16_C(  6593), -INT16_C( 18821), -INT16_C( 31020), -INT16_C( 22624), -INT16_C( 18904),  INT16_C( 19413),  INT16_C( 18135),
         INT16_C(   485),  INT16_C( 22808), -INT16_C( 25456),  INT16_C( 17187),  INT16_C( 16155), -INT16_C( 17490),  INT16_C( 25993), -INT16_C( 20560) },
      {  INT16_C( 28941), -INT16_C( 30520), -INT16_C( 25561), -INT16_C( 14321),  INT16_C( 14148),  INT16_C(  6526),  INT16_C( 22146),  INT16_C( 26464),
         INT16_C( 30807), -INT16_C(  5951), -INT16_C(  7148),  INT16_C( 12075), -INT16_C(  9949), -INT16_C( 21013), -INT16_C( 25793),  INT16_C( 19548),
         INT16_C(  9484),  INT16_C( 13524), -INT16_C(  7231),  INT16_C(  1532),  INT16_C( 31259), -INT16_C( 25313),  INT16_C( 32720),  INT16_C( 10245),
        -INT16_C( 14601),  INT16_C(  3088),  INT16_C( 15274), -INT16_C( 12741),  INT16_C(  9748),  INT16_C( 21371), -INT16_C( 10303), -INT16_C( 12641) },
      UINT32_C(3187832060),
      { -INT16_C(   425),  INT16_C( 29379), -INT16_C(  7560),  INT16_C( 18704),  INT16_C(  5473),  INT16_C( 22897), -INT16_C( 32293), -INT16_C( 31387),
        -INT16_C( 24388), -INT16_C( 12205), -INT16_C( 12601), -INT16_C( 30684), -INT16_C( 15450), -INT16_C( 23978),  INT16_C( 22583), -INT16_C( 28832),
         INT16_C(  9302), -INT16_C( 12543),  INT16_C(  4358),  INT16_C( 26648), -INT16_C( 30426),  INT16_C(   449),  INT16_C(  9738), -INT16_C( 14713),
        -INT16_C(  9530), -INT16_C( 29290), -INT16_C( 17751),  INT16_C( 20246),  INT16_C( 27774), -INT16_C( 18959),  INT16_C( 21189),  INT16_C(  6980) },
      {  INT16_C( 28941), -INT16_C( 30520), -INT16_C( 31387), -INT16_C(  2889), -INT16_C(  5621),  INT16_C( 21189), -INT16_C( 11021), -INT16_C(   425),
         INT16_C( 30807), -INT16_C(  5951), -INT16_C( 22624),  INT16_C( 12075),  INT16_C( 18704), -INT16_C( 30684),  INT16_C(  6980),  INT16_C( 19548),
         INT16_C(  9484), -INT16_C( 22624), -INT16_C(  7231),  INT16_C(  1532),  INT16_C( 31259), -INT16_C( 25313),  INT16_C( 32720),  INT16_C( 10245),
        -INT16_C( 14601), -INT16_C( 22746), -INT16_C( 12601),  INT16_C( 20246), -INT16_C( 22624),  INT16_C( 20246), -INT16_C( 10303), -INT16_C( 20560) } },
    { {  INT16_C( 18038),  INT16_C( 31978),  INT16_C(   599),  INT16_C( 32484), -INT16_C( 23157), -INT16_C( 27265),  INT16_C(  1739), -INT16_C( 28069),
        -INT16_C(  3359), -INT16_C( 30177),  INT16_C( 13740),  INT16_C( 10969), -INT16_C( 13662),  INT16_C( 26592),  INT16_C(  9244), -INT16_C( 28030),
         INT16_C( 28010), -INT16_C( 15857), -INT16_C(  3217), -INT16_C(  1216), -INT16_C( 16487),  INT16_C( 25744), -INT16_C(  4922), -INT16_C( 22538),
         INT16_C(  5854), -INT16_C( 30159),  INT16_C(  2635), -INT16_C(  4683), -INT16_C( 27180), -INT16_C(  3756), -INT16_C( 10311),  INT16_C(  9347) },
      { -INT16_C( 28092), -INT16_C( 19482),  INT16_C(  9862),  INT16_C(  8110),  INT16_C( 16357), -INT16_C( 21629),  INT16_C( 31275),  INT16_C(  2386),
        -INT16_C( 31856), -INT16_C(  9325),  INT16_C( 18573),  INT16_C( 25289),  INT16_C(  7645), -INT16_C( 26797), -INT16_C( 10508),  INT16_C( 14523),
        -INT16_C( 24215), -INT16_C(  4116), -INT16_C( 25913), -INT16_C( 21490), -INT16_C( 28199),  INT16_C(  1112), -INT16_C( 22005), -INT16_C( 25843),
        -INT16_C( 24274), -INT16_C( 17545),  INT16_C( 16617), -INT16_C( 14563),  INT16_C( 28765),  INT16_C( 21086),  INT16_C(  6471), -INT16_C( 20342) },
      UINT32_C(2174711482),
      { -INT16_C( 21231), -INT16_C(  5587), -INT16_C( 31426),  INT16_C( 19183), -INT16_C(   976),  INT16_C( 24293),  INT16_C( 23709), -INT16_C( 30951),
         INT16_C( 14236), -INT16_C(  1458), -INT16_C( 21337), -INT16_C(  4532), -INT16_C( 10555),  INT16_C( 32670),  INT16_C( 15693),  INT16_C( 24064),
         INT16_C( 11754),  INT16_C( 10568),  INT16_C( 14259), -INT16_C(  7309),  INT16_C( 22580), -INT16_C( 11967),  INT16_C( 23221),  INT16_C( 20824),
        -INT16_C( 22895),  INT16_C( 14667), -INT16_C( 26798),  INT16_C(  5927), -INT16_C( 14738), -INT16_C( 17514), -INT16_C( 27133), -INT16_C(  4583) },
      { -INT16_C( 28092),  INT16_C( 23709),  INT16_C(  9862),  INT16_C( 15693),  INT16_C( 24293),  INT16_C( 32484),  INT16_C( 31275), -INT16_C(  3217),
        -INT16_C( 31856), -INT16_C(  1216),  INT16_C( 26592),  INT16_C( 25289), -INT16_C(  3756), -INT16_C(  1216),  INT16_C( 22580),  INT16_C( 14523),
        -INT16_C(  1458), -INT16_C( 10555), -INT16_C( 28069),  INT16_C(  9244), -INT16_C( 30159),  INT16_C(  1112), -INT16_C( 22005),  INT16_C( 26592),
         INT16_C( 15693), -INT16_C( 17545),  INT16_C( 16617), -INT16_C( 14563),  INT16_C( 28765),  INT16_C( 21086),  INT16_C(  6471),  INT16_C( 13740) } },
    { {  INT16_C( 25028),  INT16_C( 30487), -INT16_C( 30055), -INT16_C( 12966), -INT16_C( 25630), -INT16_C( 26722), -INT16_C(  2059), -INT16_C( 30743),
         INT16_C( 13469), -INT16_C(  3904), -INT16_C(  6196),  INT16_C( 14855), -INT16_C( 24915), -INT16_C( 19979),  INT16_C(  3636), -INT16_C(  1889),
        -INT16_C( 18833),  INT16_C(  2159), -INT16_C( 14016),  INT16_C(  8917),  INT16_C( 29796),  INT16_C( 23226), -INT16_C( 23701),  INT16_C(  2273),
        -INT16_C( 24105), -INT16_C( 23560),  INT16_C(   136),  INT16_C( 14045), -INT16_C( 11618), -INT16_C( 11545), -INT16_C( 31008),  INT16_C( 20683) },
      {  INT16_C( 14908),  INT16_C( 31832),  INT16_C( 11780),  INT16_C( 26782),  INT16_C( 22690),  INT16_C(  3522), -INT16_C( 23557), -INT16_C( 11499),
         INT16_C(  3652), -INT16_C( 12938),  INT16_C( 21518), -INT16_C( 21501), -INT16_C(  5594),  INT16_C(  1918),  INT16_C( 18800), -INT16_C( 21417),
        -INT16_C( 20604), -INT16_C( 30680), -INT16_C( 14627),  INT16_C( 32752), -INT16_C( 19681),  INT16_C(  6796), -INT16_C( 23978), -INT16_C( 25619),
         INT16_C( 25776), -INT16_C( 16792),  INT16_C( 27576), -INT16_C(  8598), -INT16_C(  6059), -INT16_C( 14875),  INT16_C( 15410), -INT16_C( 18831) },
      UINT32_C(3376323052),
      {  INT16_C( 11871),  INT16_C( 32329), -INT16_C( 10783),  INT16_C( 14489), -INT16_C( 31113),  INT16_C( 10195),  INT16_C( 15338), -INT16_C( 23835),
         INT16_C( 20390), -INT16_C(  1151),  INT16_C( 26168),  INT16_C( 27328),  INT16_C( 12707), -INT16_C( 28896),  INT16_C( 24266),  INT16_C( 10584),
        -INT16_C( 24180),  INT16_C( 28328),  INT16_C( 16759), -INT16_C(  4442),  INT16_C( 31175), -INT16_C( 19946), -INT16_C(  1100),  INT16_C( 23124),
        -INT16_C( 10933), -INT16_C( 31915),  INT16_C(  5436), -INT16_C(  8211),  INT16_C(  3398),  INT16_C(  4206), -INT16_C( 14741), -INT16_C(  2247) },
      {  INT16_C( 14908),  INT16_C( 31832), -INT16_C( 25630), -INT16_C( 31008),  INT16_C( 22690), -INT16_C( 30055), -INT16_C(  8211),  INT16_C( 23226),
        -INT16_C( 25630), -INT16_C( 12938),  INT16_C( 21518), -INT16_C( 12966),  INT16_C( 15338),  INT16_C(  1918),  INT16_C( 18800),  INT16_C(  2273),
        -INT16_C( 20604),  INT16_C( 20390), -INT16_C( 11545), -INT16_C( 24180),  INT16_C( 20683), -INT16_C( 24915), -INT16_C( 23978), -INT16_C( 25619),
        -INT16_C( 24180), -INT16_C( 16792),  INT16_C( 27576),  INT16_C( 26168), -INT16_C(  6059), -INT16_C( 14875),  INT16_C( 16759),  INT16_C( 28328) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask2_permutex2var_epi16(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask2_permutex2var_epi16(a, idx, k, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_permutex2var_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t idx[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(4126477146),
      {  INT16_C(  7449),  INT16_C( 15175), -INT16_C( 25698), -INT16_C(  6637),  INT16_C( 26912), -INT16_C( 32056),  INT16_C( 14295), -INT16_C(  9209),
        -INT16_C( 32337),  INT16_C( 31179), -INT16_C( 15345), -INT16_C(  8630),  INT16_C( 32637), -INT16_C( 10444),  INT16_C( 10634), -INT16_C( 23348),
         INT16_C(  4934), -INT16_C(  6945), -INT16_C(  3410), -INT16_C( 12598), -INT16_C( 27812),  INT16_C( 13136),  INT16_C( 22730),  INT16_C( 30991),
        -INT16_C(  9255), -INT16_C(  5646),  INT16_C( 15519),  INT16_C(  7367), -INT16_C(  1092),  INT16_C( 18163), -INT16_C( 16348),  INT16_C( 27626) },
      { -INT16_C( 13613), -INT16_C( 32177),  INT16_C(  6844),  INT16_C(  6224), -INT16_C( 24147),  INT16_C( 30539),  INT16_C( 23545), -INT16_C( 11536),
        -INT16_C(  7626), -INT16_C( 10821), -INT16_C( 31970), -INT16_C(  9486), -INT16_C(  6786), -INT16_C( 23775),  INT16_C(  2981),  INT16_C( 30990),
         INT16_C( 24021), -INT16_C( 27909),  INT16_C( 19319),  INT16_C(  9386), -INT16_C(  2324), -INT16_C(  6757), -INT16_C( 29871), -INT16_C( 30792),
         INT16_C( 29549), -INT16_C( 29604),  INT16_C( 20214),  INT16_C( 30054), -INT16_C( 30924), -INT16_C(  9960),  INT16_C(  9875),  INT16_C( 26706) },
      {  INT16_C( 19843), -INT16_C(  1030), -INT16_C( 23143), -INT16_C( 31457), -INT16_C( 17509), -INT16_C(  5013),  INT16_C(  9030), -INT16_C( 19341),
        -INT16_C( 12394), -INT16_C( 29376), -INT16_C( 23010),  INT16_C( 20994),  INT16_C(  6702), -INT16_C( 16085),  INT16_C( 32320), -INT16_C( 15575),
         INT16_C(  9419),  INT16_C( 25790), -INT16_C(  8503),  INT16_C( 25834),  INT16_C( 21913), -INT16_C(  8368), -INT16_C( 15496),  INT16_C(  3731),
        -INT16_C( 11374), -INT16_C( 20325), -INT16_C( 25222), -INT16_C( 22526),  INT16_C( 11959), -INT16_C(  2199), -INT16_C( 27988),  INT16_C( 30651) },
      {  INT16_C(     0), -INT16_C( 23348),  INT16_C(     0),  INT16_C(  4934), -INT16_C( 16085),  INT16_C(     0), -INT16_C( 20325),  INT16_C(     0),
        -INT16_C( 15496), -INT16_C( 22526),  INT16_C(     0), -INT16_C(  8503),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 13136),  INT16_C(     0),  INT16_C(  3731),  INT16_C(     0),  INT16_C(  6702),  INT16_C(  7367), -INT16_C(  6945), -INT16_C( 11374),
        -INT16_C( 16085),  INT16_C(     0), -INT16_C( 15496),  INT16_C(     0),  INT16_C( 21913), -INT16_C(  9255), -INT16_C( 12598), -INT16_C(  3410) } },
    { UINT32_C(2145155510),
      { -INT16_C( 14761), -INT16_C(  3869),  INT16_C( 13083), -INT16_C( 27696),  INT16_C( 25590), -INT16_C( 30303),  INT16_C( 15671), -INT16_C( 20167),
         INT16_C( 15578), -INT16_C( 28071), -INT16_C( 15766),  INT16_C(  5769),  INT16_C( 17492),  INT16_C(  2957),  INT16_C( 27070),  INT16_C(  5514),
         INT16_C( 28207),  INT16_C( 18950), -INT16_C( 10591), -INT16_C( 26403),  INT16_C( 32569),  INT16_C( 28705),  INT16_C( 23228), -INT16_C( 27103),
         INT16_C( 31382),  INT16_C(    40), -INT16_C( 19908), -INT16_C( 28394), -INT16_C( 23306), -INT16_C( 19300),  INT16_C(  9741),  INT16_C( 15818) },
      { -INT16_C( 12140),  INT16_C( 13959),  INT16_C( 26022), -INT16_C(  8242), -INT16_C(  4124), -INT16_C( 24496),  INT16_C( 29001), -INT16_C(  8138),
         INT16_C( 24556),  INT16_C( 10464), -INT16_C(  2287),  INT16_C(  1977),  INT16_C( 21915), -INT16_C( 22340), -INT16_C( 31108),  INT16_C(  4325),
         INT16_C( 27990), -INT16_C(   954),  INT16_C(  5330), -INT16_C( 18725),  INT16_C( 11011),  INT16_C( 19798), -INT16_C( 29539), -INT16_C( 30419),
         INT16_C(  3563), -INT16_C(   847),  INT16_C( 27396), -INT16_C( 24828), -INT16_C( 16192),  INT16_C( 15432),  INT16_C( 11590), -INT16_C( 25523) },
      { -INT16_C( 27750),  INT16_C( 27800),  INT16_C( 29608), -INT16_C( 21726),  INT16_C( 30879),  INT16_C( 15608),  INT16_C(  9477), -INT16_C(  3899),
         INT16_C( 30259),  INT16_C( 14317), -INT16_C(  3615), -INT16_C( 23849),  INT16_C(  8113), -INT16_C(  2082),  INT16_C( 11084), -INT16_C(  6253),
         INT16_C( 11199),  INT16_C( 26451),  INT16_C( 30366),  INT16_C( 15634),  INT16_C(  3054), -INT16_C(  3207),  INT16_C( 15920),  INT16_C( 25572),
        -INT16_C( 11851), -INT16_C( 26981),  INT16_C( 29378),  INT16_C( 29496),  INT16_C(  6033), -INT16_C(  8854), -INT16_C(   702),  INT16_C(   452) },
      {  INT16_C(     0), -INT16_C( 20167),  INT16_C(  9477),  INT16_C(     0),  INT16_C( 30879),  INT16_C( 28207),  INT16_C(     0),  INT16_C( 15920),
         INT16_C(  8113),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26981), -INT16_C( 28394),  INT16_C(  6033),  INT16_C(  6033),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 10591), -INT16_C( 28394), -INT16_C( 27696),  INT16_C(     0), -INT16_C( 19300), -INT16_C(  2082),
        -INT16_C( 23849),  INT16_C( 26451),  INT16_C( 25590),  INT16_C( 25590), -INT16_C( 14761),  INT16_C( 15578),  INT16_C( 15671),  INT16_C(     0) } },
    { UINT32_C(3328710696),
      {  INT16_C( 31630),  INT16_C( 31748),  INT16_C( 32134), -INT16_C( 18832),  INT16_C( 21692),  INT16_C( 28954), -INT16_C( 19163), -INT16_C(  6393),
         INT16_C( 16423), -INT16_C( 18342), -INT16_C( 15273), -INT16_C( 26219),  INT16_C( 23233), -INT16_C(  5733),  INT16_C(   882),  INT16_C(   175),
        -INT16_C( 19586),  INT16_C(  1148), -INT16_C(  5071), -INT16_C(  4677), -INT16_C( 10944),  INT16_C( 25950),  INT16_C( 25994), -INT16_C( 20148),
        -INT16_C( 22875), -INT16_C(   919), -INT16_C(   406),  INT16_C( 11158),  INT16_C( 12632), -INT16_C( 13804), -INT16_C( 15308), -INT16_C( 19510) },
      {  INT16_C( 18295), -INT16_C( 22345),  INT16_C( 29235),  INT16_C( 29845), -INT16_C(  3257), -INT16_C( 11815),  INT16_C(  9817), -INT16_C(   382),
        -INT16_C(  5172),  INT16_C( 14331), -INT16_C( 28182),  INT16_C( 16994),  INT16_C( 30658), -INT16_C(  2547), -INT16_C( 10437), -INT16_C( 19799),
         INT16_C( 24862),  INT16_C( 21083), -INT16_C(  3885),  INT16_C(  7110), -INT16_C( 24604),  INT16_C( 15852),  INT16_C( 28613), -INT16_C( 28101),
         INT16_C( 13914),  INT16_C( 17609),  INT16_C( 11207), -INT16_C( 30329), -INT16_C( 27486), -INT16_C(  8832),  INT16_C( 10603), -INT16_C( 30064) },
      { -INT16_C(  5238),  INT16_C( 24284), -INT16_C( 23845), -INT16_C( 16519),  INT16_C( 25921),  INT16_C(  2044),  INT16_C( 14548),  INT16_C( 12185),
         INT16_C( 25198),  INT16_C( 13939), -INT16_C(  1395),  INT16_C( 12479),  INT16_C( 16270), -INT16_C(  1523), -INT16_C( 25239), -INT16_C(  3196),
         INT16_C( 24712),  INT16_C( 25681), -INT16_C( 13822),  INT16_C( 17187),  INT16_C(  8240),  INT16_C(  1098), -INT16_C(  7336), -INT16_C( 14797),
        -INT16_C( 22715), -INT16_C( 11268), -INT16_C( 17247),  INT16_C( 12291),  INT16_C(  4347),  INT16_C( 25642), -INT16_C( 20818),  INT16_C( 13912) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25950),  INT16_C(     0), -INT16_C(   919),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23845),  INT16_C( 32134),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19163),  INT16_C(     0),  INT16_C( 16270),  INT16_C( 28954),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 18342), -INT16_C(  6393),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12479), -INT16_C( 19586) } },
    { UINT32_C( 278571278),
      { -INT16_C( 16780), -INT16_C( 23469), -INT16_C( 24866),  INT16_C( 13992), -INT16_C(  9087), -INT16_C( 14340), -INT16_C(  1661),  INT16_C(  9370),
        -INT16_C( 25163), -INT16_C( 20396),  INT16_C( 32429),  INT16_C( 23317),  INT16_C( 27948),  INT16_C( 14994),  INT16_C( 11286), -INT16_C( 30134),
        -INT16_C( 24854), -INT16_C( 14290), -INT16_C( 10436), -INT16_C( 16898), -INT16_C(  1101),  INT16_C( 13956),  INT16_C(  7924), -INT16_C( 22182),
        -INT16_C( 20549),  INT16_C( 26969),  INT16_C( 28205),  INT16_C( 23236),  INT16_C( 22235), -INT16_C(  3436), -INT16_C(  8317),  INT16_C( 28028) },
      { -INT16_C( 21635), -INT16_C( 18122),  INT16_C( 13442),  INT16_C( 13686), -INT16_C(  1233),  INT16_C(  9067), -INT16_C( 15079), -INT16_C( 10804),
         INT16_C(  9844), -INT16_C( 24002),  INT16_C(   660),  INT16_C( 28924), -INT16_C( 28583), -INT16_C(  9118), -INT16_C(  8593), -INT16_C(  5047),
         INT16_C( 32649),  INT16_C(  2981),  INT16_C(  7348), -INT16_C(  7360), -INT16_C( 21737),  INT16_C( 12295), -INT16_C( 11407), -INT16_C(  6907),
         INT16_C( 17401), -INT16_C( 29049), -INT16_C( 31930), -INT16_C( 24578),  INT16_C( 24596), -INT16_C( 31877), -INT16_C( 15298), -INT16_C( 14224) },
      {  INT16_C(  5444), -INT16_C(  1837),  INT16_C(  5169),  INT16_C( 18651), -INT16_C(  7489),  INT16_C( 12409),  INT16_C( 32438), -INT16_C( 20714),
        -INT16_C( 25150),  INT16_C(  2109),  INT16_C( 15137),  INT16_C( 13735),  INT16_C(  8859), -INT16_C(  9544),  INT16_C( 10470),  INT16_C( 10914),
         INT16_C( 30014),  INT16_C( 28450), -INT16_C(   375),  INT16_C( 18872),  INT16_C( 12768), -INT16_C( 27015), -INT16_C( 28753),  INT16_C( 28998),
        -INT16_C( 31955),  INT16_C( 20089),  INT16_C(  8383),  INT16_C( 23171),  INT16_C( 15170),  INT16_C( 10548), -INT16_C( 10652), -INT16_C( 23981) },
      {  INT16_C(     0), -INT16_C( 28753), -INT16_C( 24866), -INT16_C( 28753),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 12768),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15170),  INT16_C(     0),  INT16_C(  5169),  INT16_C(     0), -INT16_C( 20396),
         INT16_C(     0),  INT16_C( 12409),  INT16_C(     0), -INT16_C( 16780), -INT16_C( 22182),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14340),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1101),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3574691404),
      { -INT16_C( 13964),  INT16_C( 21534), -INT16_C( 26374), -INT16_C( 21781),  INT16_C( 12583),  INT16_C( 21531), -INT16_C( 27212),  INT16_C( 29602),
         INT16_C(  9653), -INT16_C(  1842),  INT16_C(   609), -INT16_C( 15071),  INT16_C( 29913),  INT16_C(  9575),  INT16_C( 30954),  INT16_C( 24314),
         INT16_C(  6466),  INT16_C( 15539), -INT16_C( 24911), -INT16_C( 10010),  INT16_C(   719), -INT16_C( 31955), -INT16_C( 12393),  INT16_C( 19703),
        -INT16_C( 14859),  INT16_C( 22084),  INT16_C( 26055), -INT16_C( 24549), -INT16_C( 32038), -INT16_C( 15163), -INT16_C( 16134),  INT16_C( 15395) },
      { -INT16_C( 10535), -INT16_C( 30087),  INT16_C( 24436),  INT16_C( 17250), -INT16_C( 28831), -INT16_C(  1850), -INT16_C( 17057),  INT16_C( 21573),
        -INT16_C( 30334),  INT16_C( 19114), -INT16_C( 14865), -INT16_C( 13846), -INT16_C( 20409),  INT16_C( 16781), -INT16_C( 20368),  INT16_C( 18814),
        -INT16_C(  2170), -INT16_C(  1325),  INT16_C( 13654), -INT16_C( 18371),  INT16_C(  1221),  INT16_C(  9392), -INT16_C(  2623),  INT16_C( 17528),
         INT16_C(  8831),  INT16_C( 28302),  INT16_C( 30951),  INT16_C( 11831), -INT16_C( 15320), -INT16_C( 26513), -INT16_C(  4747), -INT16_C(  1055) },
      { -INT16_C( 19228),  INT16_C( 15350),  INT16_C( 13290), -INT16_C( 20493), -INT16_C( 23753), -INT16_C(  1581),  INT16_C( 19353),  INT16_C(  6205),
        -INT16_C( 13459),  INT16_C( 21638), -INT16_C( 17085),  INT16_C( 27778), -INT16_C(  3711), -INT16_C(  2556), -INT16_C(  6433), -INT16_C( 15374),
        -INT16_C(  5990), -INT16_C( 31490), -INT16_C(  3813),  INT16_C( 21299),  INT16_C(  1685),  INT16_C( 11852), -INT16_C( 30383), -INT16_C( 16826),
        -INT16_C( 13228), -INT16_C( 26862), -INT16_C( 27511),  INT16_C(  2563),  INT16_C(  2182),  INT16_C( 25857), -INT16_C(  3090), -INT16_C( 30680) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  1685),  INT16_C( 13290),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15395),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 17085), -INT16_C( 15374),  INT16_C(     0),  INT16_C( 29602),  INT16_C(  9575), -INT16_C(  5990),  INT16_C(     0),
        -INT16_C( 27212),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21531),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 30680),  INT16_C(     0),  INT16_C(  6205),  INT16_C(     0), -INT16_C( 13459),  INT16_C(     0),  INT16_C( 11852),  INT16_C( 15350) } },
    { UINT32_C(4128057307),
      {  INT16_C( 16408), -INT16_C( 21175), -INT16_C( 27321), -INT16_C( 26405),  INT16_C(  8478),  INT16_C( 29271),  INT16_C( 27117),  INT16_C( 30218),
         INT16_C(  3582), -INT16_C( 31615), -INT16_C( 32235),  INT16_C(  1001),  INT16_C(  4469),  INT16_C( 20620), -INT16_C( 26312),  INT16_C( 20806),
        -INT16_C( 28455),  INT16_C(  8446), -INT16_C(  9691),  INT16_C( 17593),  INT16_C(  4347), -INT16_C(  5706), -INT16_C( 16263),  INT16_C( 30559),
        -INT16_C(  7986), -INT16_C(  7173), -INT16_C(  7070), -INT16_C( 10265),  INT16_C( 29686),  INT16_C( 11815),  INT16_C( 28172), -INT16_C(  6785) },
      {  INT16_C( 32510),  INT16_C(  8966), -INT16_C( 16552),  INT16_C( 21351),  INT16_C(  7887),  INT16_C( 18492), -INT16_C( 25378), -INT16_C( 21312),
        -INT16_C( 17540), -INT16_C(  8304),  INT16_C( 30624), -INT16_C( 26954), -INT16_C(  8470), -INT16_C(  2364),  INT16_C( 17484),  INT16_C( 19163),
        -INT16_C(  7742),  INT16_C(  6765), -INT16_C( 10848),  INT16_C( 28525), -INT16_C( 21773), -INT16_C( 11848),  INT16_C( 30790), -INT16_C( 15746),
         INT16_C(  3635), -INT16_C( 11359),  INT16_C( 22661),  INT16_C( 28521),  INT16_C( 11830), -INT16_C( 32155),  INT16_C( 16498),  INT16_C( 13516) },
      {  INT16_C( 14626), -INT16_C( 15794), -INT16_C( 17650),  INT16_C(   306), -INT16_C(  5531), -INT16_C( 21549),  INT16_C( 20834), -INT16_C( 27282),
         INT16_C(  3935), -INT16_C(  7063), -INT16_C( 11673), -INT16_C( 25261), -INT16_C( 18432),  INT16_C( 29215), -INT16_C(  5128),  INT16_C(  6822),
        -INT16_C(  3035),  INT16_C( 13277),  INT16_C(  4016),  INT16_C(  5429),  INT16_C(  2297),  INT16_C( 23489),  INT16_C( 12121), -INT16_C( 18192),
         INT16_C( 22846), -INT16_C( 22884), -INT16_C(  4308),  INT16_C( 11331),  INT16_C( 25511), -INT16_C( 24673),  INT16_C( 17742),  INT16_C( 29626) },
      {  INT16_C( 17742),  INT16_C( 27117),  INT16_C(     0), -INT16_C( 27282),  INT16_C( 20806),  INT16_C(     0),  INT16_C( 28172),  INT16_C( 16408),
         INT16_C( 25511), -INT16_C( 28455),  INT16_C( 14626),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8478),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 27321),  INT16_C(     0),  INT16_C( 14626),  INT16_C( 29215),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 15794),  INT16_C( 29271),  INT16_C(     0),  INT16_C( 12121), -INT16_C( 21549),  INT16_C(  4016),  INT16_C(  4469) } },
    { UINT32_C(3936851770),
      { -INT16_C(  9050), -INT16_C( 24577), -INT16_C( 16156),  INT16_C( 15866), -INT16_C(  5393),  INT16_C( 12021), -INT16_C( 28348),  INT16_C( 28884),
         INT16_C(  6016),  INT16_C( 10140),  INT16_C( 15226), -INT16_C( 13882), -INT16_C( 32639), -INT16_C( 17604), -INT16_C(  7401), -INT16_C( 16987),
        -INT16_C( 23361), -INT16_C( 23716),  INT16_C( 22117),  INT16_C( 21728), -INT16_C( 10943), -INT16_C( 31358),  INT16_C( 22118), -INT16_C(  6411),
        -INT16_C( 28306), -INT16_C(  6131), -INT16_C( 11059),  INT16_C( 20145), -INT16_C(  4524),  INT16_C( 27657), -INT16_C( 20783), -INT16_C( 28375) },
      { -INT16_C( 31150), -INT16_C( 18636),  INT16_C(  5596),  INT16_C(  7436), -INT16_C( 28950),  INT16_C( 20898), -INT16_C( 26651),  INT16_C( 21303),
         INT16_C( 17705), -INT16_C(  2501), -INT16_C(  4839),  INT16_C( 27972),  INT16_C( 19931), -INT16_C( 21287),  INT16_C(  1019),  INT16_C( 19773),
         INT16_C( 29321),  INT16_C( 25861),  INT16_C(  4487),  INT16_C( 29059),  INT16_C(  9631), -INT16_C( 31550), -INT16_C(  1347), -INT16_C(  6441),
         INT16_C(  4927),  INT16_C( 22748),  INT16_C(  8192), -INT16_C(  9275), -INT16_C( 24723),  INT16_C( 26759), -INT16_C( 14942),  INT16_C( 11189) },
      { -INT16_C( 17865), -INT16_C( 16752),  INT16_C(  5067),  INT16_C( 27439), -INT16_C(  3527), -INT16_C(  2321), -INT16_C( 14356),  INT16_C( 11228),
        -INT16_C( 18214), -INT16_C(  9597),  INT16_C( 18648),  INT16_C( 17845),  INT16_C( 15591), -INT16_C( 30291),  INT16_C( 25089),  INT16_C( 14516),
         INT16_C( 17693), -INT16_C(  5898),  INT16_C(  9816), -INT16_C( 28333),  INT16_C( 17176),  INT16_C(  1159),  INT16_C( 25354), -INT16_C(  7121),
        -INT16_C( 19941), -INT16_C(  3138),  INT16_C( 29690), -INT16_C(  7624), -INT16_C(  6737), -INT16_C( 20117),  INT16_C(  8264),  INT16_C( 26089) },
      {  INT16_C(     0),  INT16_C( 17176),  INT16_C(     0), -INT16_C( 32639),  INT16_C( 18648),  INT16_C(  5067),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  9597), -INT16_C(  7624), -INT16_C(  6131),  INT16_C(     0),  INT16_C( 20145),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20117),
         INT16_C( 10140),  INT16_C( 12021),  INT16_C( 28884),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16156),  INT16_C(     0), -INT16_C(  6411),
         INT16_C(     0), -INT16_C(  4524),  INT16_C(     0),  INT16_C( 12021),  INT16_C(     0),  INT16_C( 28884),  INT16_C(  5067),  INT16_C(  1159) } },
    { UINT32_C(3175997541),
      { -INT16_C( 24314),  INT16_C(  7759), -INT16_C( 10524), -INT16_C(  4574),  INT16_C( 20794),  INT16_C( 21970), -INT16_C( 28669), -INT16_C(   695),
        -INT16_C( 32509), -INT16_C( 19745),  INT16_C( 19303), -INT16_C( 20637),  INT16_C( 19819), -INT16_C( 12268),  INT16_C( 24877),  INT16_C( 13197),
        -INT16_C(  9214), -INT16_C(  6575),  INT16_C( 29619), -INT16_C(  4652), -INT16_C( 22844), -INT16_C( 14526), -INT16_C( 29898),  INT16_C( 14788),
        -INT16_C( 23539),  INT16_C( 29932),  INT16_C( 20463),  INT16_C( 23075),  INT16_C( 14236), -INT16_C( 14038), -INT16_C( 18536), -INT16_C( 25604) },
      {  INT16_C( 19860),  INT16_C( 18305),  INT16_C( 22208), -INT16_C( 31692),  INT16_C( 30460),  INT16_C( 13131),  INT16_C(  4098),  INT16_C(  3948),
         INT16_C( 22708), -INT16_C( 23677), -INT16_C( 22872),  INT16_C( 17661),  INT16_C( 10205),  INT16_C( 29966),  INT16_C(  2782),  INT16_C( 29200),
        -INT16_C( 28072),  INT16_C(  6329), -INT16_C(  4632), -INT16_C(  7011), -INT16_C(  6044),  INT16_C( 26135), -INT16_C( 31496), -INT16_C( 21387),
        -INT16_C(  1828), -INT16_C( 31665),  INT16_C( 19614),  INT16_C( 31689), -INT16_C( 10381),  INT16_C( 21232),  INT16_C(   481),  INT16_C( 14788) },
      {  INT16_C( 32403),  INT16_C( 31570), -INT16_C(  4245), -INT16_C( 12449),  INT16_C( 30679), -INT16_C( 12235), -INT16_C( 21765), -INT16_C( 10372),
        -INT16_C( 13150),  INT16_C( 16476),  INT16_C(  9496), -INT16_C( 29509), -INT16_C( 21252), -INT16_C(  8738), -INT16_C( 23891),  INT16_C( 16407),
         INT16_C( 26912), -INT16_C( 29509),  INT16_C(  6744),  INT16_C( 12123), -INT16_C( 28271), -INT16_C( 29441),  INT16_C( 31803), -INT16_C(  8604),
        -INT16_C( 16312),  INT16_C( 24606), -INT16_C(  9499), -INT16_C(  7700), -INT16_C( 13690),  INT16_C( 13246), -INT16_C( 10899), -INT16_C( 29325) },
      { -INT16_C( 22844),  INT16_C(     0), -INT16_C( 24314),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20637), -INT16_C( 10524),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24877), -INT16_C( 18536), -INT16_C(  9214),
        -INT16_C( 23539),  INT16_C(     0), -INT16_C( 13150), -INT16_C( 14038),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16312),  INT16_C(     0),
         INT16_C( 14236),  INT16_C(     0), -INT16_C( 18536), -INT16_C( 19745),  INT16_C( 12123),  INT16_C( 26912),  INT16_C(     0),  INT16_C( 20794) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi16(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_permutex2var_epi16(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i idx = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_permutex2var_epi16(k, a, idx, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i idx;
    simde__m512i b;
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
      simde_mm512_set_epi32(INT32_C( 1106394199), INT32_C( 1786608232), INT32_C(  477078085), INT32_C(-1779632362),
                            INT32_C( -966979640), INT32_C( -998912797), INT32_C( 1045049163), INT32_C(-1292333722),
                            INT32_C( 1183794740), INT32_C( -731066686), INT32_C(  511551854), INT32_C( 1167565783),
                            INT32_C(  809184406), INT32_C(-1484085267), INT32_C( -106978631), INT32_C(-1748122897)),
      simde_mm512_set_epi32(INT32_C(-1748122897), INT32_C( 1996766677), INT32_C( -643998219), INT32_C(  914731069),
                            INT32_C(  238338636), INT32_C(-1292333722), INT32_C(  750368606), INT32_C(  914731069),
                            INT32_C(  750368606), INT32_C(  511551854), INT32_C( 1167565783), INT32_C( -998912797),
                            INT32_C( -998912797), INT32_C( -998912797), INT32_C( -252228416), INT32_C(  924273218)) },
    { simde_mm512_set_epi32(INT32_C( -572206162), INT32_C(-1229665005), INT32_C(-2082924696), INT32_C( -649416979),
                            INT32_C( 2112092702), INT32_C( -909261280), INT32_C(-1418185146), INT32_C(-1714733997),
                            INT32_C( 1030181563), INT32_C( -291680665), INT32_C(-1617776213), INT32_C( 2112788110),
                            INT32_C(  207483507), INT32_C( 1144876369), INT32_C( 1177485782), INT32_C( 1952824319)),
      simde_mm512_set_epi32(INT32_C( -736462739), INT32_C( 1787530508), INT32_C( 1887757958), INT32_C(-2099529631),
                            INT32_C(  262676022), INT32_C(   53886530), INT32_C( 1760597059), INT32_C( 1505905484),
                            INT32_C(  774167251), INT32_C(  967143468), INT32_C(  868941550), INT32_C(-1213290419),
                            INT32_C( 1972608228), INT32_C(   11142680), INT32_C(-1446276724), INT32_C(-1200659658)),
      simde_mm512_set_epi32(INT32_C(-1351086746), INT32_C(-1617825510), INT32_C(  -53781400), INT32_C( -324253949),
                            INT32_C(  277157108), INT32_C(-1362182408), INT32_C( -600988389), INT32_C(-1661173616),
                            INT32_C(  988661733), INT32_C(-1651241157), INT32_C(  751941929), INT32_C(  -37019801),
                            INT32_C(  498171562), INT32_C( 2017003975), INT32_C(-1441476496), INT32_C(-1365008121)),
      simde_mm512_set_epi32(INT32_C(-2082924696), INT32_C( -649416979), INT32_C( -291680665), INT32_C( 1177485782),
                            INT32_C(-1651241157), INT32_C( 1144876369), INT32_C(  207483507), INT32_C( -649416979),
                            INT32_C(  498171562), INT32_C( -649416979), INT32_C(-1229665005), INT32_C(-2082924696),
                            INT32_C( 2112788110), INT32_C(-1661173616), INT32_C( -649416979), INT32_C(-1651241157)) },
    { simde_mm512_set_epi32(INT32_C(-2111484726), INT32_C(-1666865657), INT32_C(  905297213), INT32_C(  873020550),
                            INT32_C(-1639789891), INT32_C(  587061870), INT32_C(-2122729525), INT32_C( 1912650916),
                            INT32_C(  -12276084), INT32_C(-1060302964), INT32_C(  650767651), INT32_C( -997283137),
                            INT32_C( 2144598253), INT32_C(  298450302), INT32_C( 1083198112), INT32_C( -506043419)),
      simde_mm512_set_epi32(INT32_C( -134982351), INT32_C(-1321868808), INT32_C( -899996596), INT32_C(-1289649119),
                            INT32_C( -206201920), INT32_C( 1680053368), INT32_C(-1305508907), INT32_C(-2067500681),
                            INT32_C(-1529397706), INT32_C( 1803067419), INT32_C( 1059939268), INT32_C(  399509097),
                            INT32_C( -338549599), INT32_C(  -31125095), INT32_C(-1633544688), INT32_C(-1398964227)),
      simde_mm512_set_epi32(INT32_C(-1660298113), INT32_C(   39258193), INT32_C( 1764960191), INT32_C( 1032976421),
                            INT32_C(-1057643771), INT32_C( 2071456034), INT32_C(-1085712390), INT32_C( 1506090338),
                            INT32_C(  367006319), INT32_C(-1863539807), INT32_C(-1111523249), INT32_C( 2019983201),
                            INT32_C(  566503151), INT32_C(  503973368), INT32_C(  315043487), INT32_C(  230467816)),
      simde_mm512_set_epi32(INT32_C(  315043487), INT32_C( 1506090338), INT32_C(  873020550), INT32_C( 1083198112),
                            INT32_C( -506043419), INT32_C( 1506090338), INT32_C(-1111523249), INT32_C(  367006319),
                            INT32_C(-1863539807), INT32_C(-1057643771), INT32_C( -997283137), INT32_C(-2122729525),
                            INT32_C( 1083198112), INT32_C(-1085712390), INT32_C(  230467816), INT32_C( 1764960191)) },
    { simde_mm512_set_epi32(INT32_C(  506925802), INT32_C(  939863413), INT32_C(  -95691606), INT32_C(  -63021650),
                            INT32_C( 1460121332), INT32_C(-1770546120), INT32_C(  691111167), INT32_C( 1916845809),
                            INT32_C( -722416713), INT32_C( 1952309936), INT32_C( -635326036), INT32_C(-2071561697),
                            INT32_C(-1349311592), INT32_C(-1434371918), INT32_C( -908787181), INT32_C( 1027111311)),
      simde_mm512_set_epi32(INT32_C( -476274551), INT32_C(-1268946349), INT32_C( 1871428230), INT32_C( 1084413756),
                            INT32_C( 1221272409), INT32_C( 1604619894), INT32_C(  245162423), INT32_C( -879398063),
                            INT32_C(-1252847595), INT32_C(-1083417294), INT32_C(  -85733631), INT32_C( -568206760),
                            INT32_C( -433087356), INT32_C(  591211590), INT32_C(  216351398), INT32_C(  907563034)),
      simde_mm512_set_epi32(INT32_C(  553126451), INT32_C( 1865131028), INT32_C( -563146647), INT32_C( 1055479165),
                            INT32_C(-2116199302), INT32_C(  548546839), INT32_C(-1021995369), INT32_C(-1397392070),
                            INT32_C( 1911717085), INT32_C(-1893150233), INT32_C(-1174808283), INT32_C( 1158232544),
                            INT32_C( -280806326), INT32_C(  520223268), INT32_C(  603498036), INT32_C(  115278412)),
      simde_mm512_set_epi32(INT32_C(  691111167), INT32_C( -280806326), INT32_C( 1952309936), INT32_C( 1055479165),
                            INT32_C(-1021995369), INT32_C(-1893150233), INT32_C( 1911717085), INT32_C(  603498036),
                            INT32_C(-1174808283), INT32_C(  520223268), INT32_C( -908787181), INT32_C(-1397392070),
                            INT32_C(-2071561697), INT32_C( 1952309936), INT32_C( 1952309936), INT32_C(  548546839)) },
    { simde_mm512_set_epi32(INT32_C( -195854029), INT32_C( 1958024187), INT32_C( 1003184214), INT32_C( 1306010047),
                            INT32_C(-1204461456), INT32_C(-1689382831), INT32_C(-1474151310), INT32_C( 1613100007),
                            INT32_C( 1060086708), INT32_C(-1444530803), INT32_C( 1862849170), INT32_C( -928808218),
                            INT32_C( -146523132), INT32_C(-1235988391), INT32_C( -964779679), INT32_C(   57349444)),
      simde_mm512_set_epi32(INT32_C(-2134067081), INT32_C( -882392805), INT32_C(  185789257), INT32_C(-2111603035),
                            INT32_C(  407162836), INT32_C(-1236510605), INT32_C(-1567423785), INT32_C(  780522762),
                            INT32_C(  -23120724), INT32_C(   92199108), INT32_C(   24805933), INT32_C( 1301060633),
                            INT32_C(-1139480237), INT32_C(  217822558), INT32_C(-1429367443), INT32_C(  465891853)),
      simde_mm512_set_epi32(INT32_C(  158027570), INT32_C(-1346235067), INT32_C( 1682432767), INT32_C( 1810962335),
                            INT32_C( 1067516501), INT32_C(-1082135268), INT32_C(  -56869560), INT32_C(-1195320775),
                            INT32_C( -393383799), INT32_C( -554410804), INT32_C( 1644924567), INT32_C(-1134386712),
                            INT32_C(-1030153866), INT32_C(  436830495), INT32_C(-1226346340), INT32_C( -700345341)),
      simde_mm512_set_epi32(INT32_C( -393383799), INT32_C( 1067516501), INT32_C(-1474151310), INT32_C( 1862849170),
                            INT32_C(-1134386712), INT32_C(-1030153866), INT32_C( -393383799), INT32_C(-1689382831),
                            INT32_C( 1306010047), INT32_C( -928808218), INT32_C( 1003184214), INT32_C(  -56869560),
                            INT32_C(-1030153866), INT32_C(-1346235067), INT32_C( 1003184214), INT32_C( 1003184214)) },
    { simde_mm512_set_epi32(INT32_C( -756862268), INT32_C( 1500443430), INT32_C(  463718589), INT32_C(  262081082),
                            INT32_C(  990406393), INT32_C(  114071142), INT32_C(-1625480036), INT32_C( -478582396),
                            INT32_C( -548991920), INT32_C( 1883825214), INT32_C(  -16488776), INT32_C( -956015081),
                            INT32_C(-1165588144), INT32_C( -540410051), INT32_C(  285110286), INT32_C( 1179668936)),
      simde_mm512_set_epi32(INT32_C(  947326740), INT32_C( 1951776493), INT32_C( 1846700305), INT32_C(-1461724216),
                            INT32_C(  885687075), INT32_C(-2137900171), INT32_C( -224346810), INT32_C( -527126852),
                            INT32_C( 1999299634), INT32_C( -946177834), INT32_C(  996138255), INT32_C(  230639176),
                            INT32_C(  644992332), INT32_C(  587140266), INT32_C(-1686393253), INT32_C(  834603009)),
      simde_mm512_set_epi32(INT32_C( -565016612), INT32_C(-1511643506), INT32_C(-1182806527), INT32_C( 2039339451),
                            INT32_C( 1136224105), INT32_C(-1359466004), INT32_C( -867898302), INT32_C( 1835028244),
                            INT32_C(  225198660), INT32_C(-1493291743), INT32_C( 1406350672), INT32_C(  420428866),
                            INT32_C( -890727392), INT32_C(  555626838), INT32_C(  641882471), INT32_C(-1439329545)),
      simde_mm512_set_epi32(INT32_C(  420428866), INT32_C(  463718589), INT32_C(  641882471), INT32_C( -478582396),
                            INT32_C(-1165588144), INT32_C( 1406350672), INT32_C( 1883825214), INT32_C( 2039339451),
                            INT32_C(  555626838), INT32_C(-1493291743), INT32_C( -756862268), INT32_C( -478582396),
                            INT32_C(  262081082), INT32_C(  114071142), INT32_C( 1136224105), INT32_C(  285110286)) },
    { simde_mm512_set_epi32(INT32_C(-1531947751), INT32_C( -721959716), INT32_C(  537876613), INT32_C( 2069004024),
                            INT32_C(-1968092173), INT32_C(  857387582), INT32_C(-1694386201), INT32_C(   75306944),
                            INT32_C(-1259042358), INT32_C(  909781307), INT32_C( 1903022709), INT32_C( 1362794737),
                            INT32_C(-1814837932), INT32_C( -304499521), INT32_C(-1173731613), INT32_C(-1043888074)),
      simde_mm512_set_epi32(INT32_C( 1190479058), INT32_C(  648305778), INT32_C(-2081630262), INT32_C(  656381823),
                            INT32_C(-1582102069), INT32_C( 1943788808), INT32_C(  -48840894), INT32_C( 1268696790),
                            INT32_C(  678074994), INT32_C(-1453607052), INT32_C( 1809911494), INT32_C( -679308165),
                            INT32_C( 1323625235), INT32_C( -182774520), INT32_C(-1281289570), INT32_C(-1278212722)),
      simde_mm512_set_epi32(INT32_C( -829128497), INT32_C(  553616479), INT32_C( 2081281560), INT32_C( 1621929085),
                            INT32_C(  502983658), INT32_C( -152394738), INT32_C(-1678301674), INT32_C( 1357386696),
                            INT32_C(-1943547354), INT32_C(  -79733129), INT32_C(-2108182551), INT32_C( -331487526),
                            INT32_C( -808116279), INT32_C( -531514769), INT32_C(  375648558), INT32_C(-1499104175)),
      simde_mm512_set_epi32(INT32_C( -531514769), INT32_C( -531514769), INT32_C(  857387582), INT32_C( -829128497),
                            INT32_C(-1968092173), INT32_C(   75306944), INT32_C( -304499521), INT32_C(  -79733129),
                            INT32_C( -531514769), INT32_C( -331487526), INT32_C(  909781307), INT32_C(  502983658),
                            INT32_C( -808116279), INT32_C(   75306944), INT32_C(  553616479), INT32_C( -721959716)) },
    { simde_mm512_set_epi32(INT32_C( -868402874), INT32_C( 1365551587), INT32_C( -286078647), INT32_C(  535680374),
                            INT32_C( -347356302), INT32_C(  423616503), INT32_C( 2101835176), INT32_C(  135041412),
                            INT32_C(-1857111698), INT32_C( 1860240848), INT32_C(  582285428), INT32_C(-1871232648),
                            INT32_C(-1985705707), INT32_C(  949080599), INT32_C( 1320997888), INT32_C( 1175065355)),
      simde_mm512_set_epi32(INT32_C( 1519347951), INT32_C( 1690235053), INT32_C(  992814047), INT32_C(-2023351849),
                            INT32_C( -939539212), INT32_C(  -83602250), INT32_C( 1391682826), INT32_C( 2110848055),
                            INT32_C( 1264988325), INT32_C(   82278637), INT32_C(-2138890389), INT32_C(-1738286108),
                            INT32_C(  841364839), INT32_C(-1629840866), INT32_C( -232831502), INT32_C( 1761703668)),
      simde_mm512_set_epi32(INT32_C(  511852650), INT32_C( 1504302381), INT32_C( -226523906), INT32_C(-1237330962),
                            INT32_C( 1280120077), INT32_C(  865002127), INT32_C( -203493997), INT32_C(  956618200),
                            INT32_C(   33546873), INT32_C( -965377912), INT32_C( 1970918143), INT32_C(  528719680),
                            INT32_C(   12592404), INT32_C( 1306075002), INT32_C(-2040787420), INT32_C(-1677403893)),
      simde_mm512_set_epi32(INT32_C( -868402874), INT32_C( -286078647), INT32_C(  511852650), INT32_C(   33546873),
                            INT32_C(  528719680), INT32_C( -965377912), INT32_C(  423616503), INT32_C(   33546873),
                            INT32_C(  582285428), INT32_C( -286078647), INT32_C( -347356302), INT32_C(-1871232648),
                            INT32_C(-1857111698), INT32_C( 1504302381), INT32_C( 1306075002), INT32_C(  528719680)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_permutex2var_epi32(test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask16 k;
    simde__m512i idx;
    simde__m512i b;
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
      simde_mm512_set_epi32(INT32_C(-1026363374), INT32_C(-1936012201), INT32_C( 1974152373), INT32_C(-1306064352),
                            INT32_C(-1166320093), INT32_C(  923442479), INT32_C(-1302383354), INT32_C(  145438126),
                            INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932), INT32_C( 1443901717),
                            INT32_C( 1993455974), INT32_C( 1856459607), INT32_C(-1302383354), INT32_C(  223952317)) },
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
                            INT32_C(-2083755741), INT32_C( 2066979701), INT32_C( 1258747662), INT32_C(-1423023772),
                            INT32_C( -622852205), INT32_C( 1094609712), INT32_C(-1017461983), INT32_C(  548883180)) },
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
      simde_mm512_set_epi32(INT32_C(  654527510), INT32_C(-1762469023), INT32_C(  386072301), INT32_C(  338985942),
                            INT32_C(-1087388220), INT32_C(  654527510), INT32_C(-2043358500), INT32_C(  459072440),
                            INT32_C( -430427651), INT32_C( 1692413538), INT32_C(  386072301), INT32_C( 1692413538),
                            INT32_C(   87817524), INT32_C( 1219490517), INT32_C(-1762469023), INT32_C(  338985942)) },
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
      simde_mm512_set_epi32(INT32_C(-2098236580), INT32_C(  765730488), INT32_C(-1544325740), INT32_C(  596054477),
                            INT32_C(  712044568), INT32_C(-1991433794), INT32_C(  277470244), INT32_C(  277470244),
                            INT32_C(-1102663841), INT32_C(  596054477), INT32_C(-1102663841), INT32_C( 1445172644),
                            INT32_C( 1897985966), INT32_C(  277470244), INT32_C(-2098236580), INT32_C(  277470244)) },
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
      simde_mm512_set_epi32(INT32_C(-1800615955), INT32_C(-1241407128), INT32_C( 1183910939), INT32_C( -603523965),
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
      simde_mm512_set_epi32(INT32_C( -207159885), INT32_C(  351897115), INT32_C( -521443925), INT32_C( -364563113),
                            INT32_C(-1686112999), INT32_C( 1594003471), INT32_C( -364563113), INT32_C( -397133039),
                            INT32_C( -207159885), INT32_C( -207159885), INT32_C(  362759403), INT32_C( -104006691),
                            INT32_C( -397133039), INT32_C(-1318801755), INT32_C(-1726442446), INT32_C( -521443925)) },
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
      simde_mm512_set_epi32(INT32_C( -662725541), INT32_C(  790228415), INT32_C(-1398303881), INT32_C(  673265711),
                            INT32_C( 1526994051), INT32_C( 1569343894), INT32_C(-1059990980), INT32_C(  673265711),
                            INT32_C( 1463745126), INT32_C( -957352131), INT32_C( -662725541), INT32_C(-1814919780),
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
      simde_mm512_set_epi32(INT32_C(-1875196295), INT32_C( 1379479886), INT32_C( 1611314079), INT32_C(-1895497877),
                            INT32_C( -539014135), INT32_C( 1554320066), INT32_C( 1611314079), INT32_C( -539014135),
                            INT32_C( 1135188428), INT32_C(-1013292897), INT32_C(-1895497877), INT32_C( -366505666),
                            INT32_C( 1379479886), INT32_C(-1903831246), INT32_C(-1218762696), INT32_C( -539014135)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_permutex2var_epi32(test_vec[i].a, test_vec[i].k, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask2_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i idx;
    simde__mmask16 k;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126), INT32_C(-1306064352),
                            INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562), INT32_C( 1443901717),
                            INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932), INT32_C(-1302383354),
                            INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201), INT32_C( 1856459607)),
      simde_mm512_set_epi32(INT32_C( -207240031), INT32_C(-1649179267), INT32_C( 2054398444), INT32_C( -483586503),
                            INT32_C(-1481960002), INT32_C(  861125508), INT32_C( -330381203), INT32_C(-1999224530),
                            INT32_C( 1042470181), INT32_C( 1827473477), INT32_C(  298546792), INT32_C(-1630396605),
                            INT32_C( 1545554432), INT32_C(  344023940), INT32_C(-1871515754), INT32_C(  951544639)),
      UINT16_C(45849),
      simde_mm512_set_epi32(INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373), INT32_C( -695949043),
                            INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093), INT32_C(-2045280751),
                            INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336), INT32_C(  564965997),
                            INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685), INT32_C( 1430356381)),
      simde_mm512_set_epi32(INT32_C(-1936012201), INT32_C(-1649179267), INT32_C(-1306064352), INT32_C(-1166320093),
                            INT32_C(-1481960002), INT32_C(  861125508), INT32_C(  145438126), INT32_C(-1801776439),
                            INT32_C( 1042470181), INT32_C( 1827473477), INT32_C(  298546792), INT32_C( 1993455974),
                            INT32_C( 1856459607), INT32_C(  344023940), INT32_C(-1871515754), INT32_C( 1711460779)) },
    { simde_mm512_set_epi32(INT32_C(-1423023772), INT32_C(-1185448755), INT32_C( 1549802795), INT32_C(  159583350),
                            INT32_C(  548883180), INT32_C( -605945909), INT32_C(-2063050181), INT32_C( 1095467003),
                            INT32_C(-2083755741), INT32_C( 2066979701), INT32_C( 1094609712), INT32_C( 1345059025),
                            INT32_C( -340318359), INT32_C( 1519671047), INT32_C(-1017461983), INT32_C(  353198331)),
      simde_mm512_set_epi32(INT32_C( -707551350), INT32_C(  513515868), INT32_C(-1825967755), INT32_C(  822222164),
                            INT32_C(-1689559027), INT32_C(  533478787), INT32_C(  907615417), INT32_C( -199229058),
                            INT32_C(  -91537812), INT32_C( 1375258232), INT32_C(  139748399), INT32_C( 1688468565),
                            INT32_C(  736544549), INT32_C(-1282057552), INT32_C(  795925067), INT32_C( 1720852541)),
      UINT16_C(30259),
      simde_mm512_set_epi32(INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417),
                            INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662),
                            INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205), INT32_C( -839037220),
                            INT32_C(  499633910), INT32_C( -260167255), INT32_C(  884163960), INT32_C( -329275629)),
      simde_mm512_set_epi32(INT32_C( -707551350), INT32_C( 1469355417), INT32_C( -622852205), INT32_C( -839037220),
                            INT32_C(-1689559027), INT32_C( -340318359), INT32_C( -646247370), INT32_C( -199229058),
                            INT32_C(  -91537812), INT32_C( 1375258232), INT32_C(-1423023772), INT32_C( -622852205),
                            INT32_C(  736544549), INT32_C(-1282057552), INT32_C(  548883180), INT32_C(  503748315)) },
    { simde_mm512_set_epi32(INT32_C( -174985661), INT32_C(-1762469023), INT32_C( 1239606494), INT32_C(  -22119232),
                            INT32_C( 1216907749), INT32_C(  654527510), INT32_C(-2043358500), INT32_C(  459072440),
                            INT32_C( -430427651), INT32_C( -272088075), INT32_C(  386072301), INT32_C(-1628984154),
                            INT32_C(   87817524), INT32_C( 1219490517), INT32_C(-1569831145), INT32_C(  338985942)),
      simde_mm512_set_epi32(INT32_C(-2034110695), INT32_C(-1088138491), INT32_C( -353174912), INT32_C( -362301616),
                            INT32_C(  617951303), INT32_C(  817116152), INT32_C(-1034835761), INT32_C( -102069057),
                            INT32_C( 1774242298), INT32_C( 1089620040), INT32_C(-1101477862), INT32_C( 2001101785),
                            INT32_C(-1759250988), INT32_C( -606254738), INT32_C( 1526367108), INT32_C(  722122834)),
      UINT16_C(60970),
      simde_mm512_set_epi32(INT32_C(  204417556), INT32_C(-1329665093), INT32_C(-2039025377), INT32_C( 1639231015),
                            INT32_C( 1541217841), INT32_C( 1692413538), INT32_C(  738521275), INT32_C(  159429100),
                            INT32_C(  451955897), INT32_C(  181201098), INT32_C(  450627934), INT32_C( 2082954477),
                            INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946), INT32_C(-1087388220)),
      simde_mm512_set_epi32(INT32_C(  738521275), INT32_C(  386072301), INT32_C(  338985942), INT32_C( -362301616),
                            INT32_C( -430427651), INT32_C(  159429100), INT32_C( -174985661), INT32_C( -102069057),
                            INT32_C( 1774242298), INT32_C( 1089620040), INT32_C( 1692413538), INT32_C( 2001101785),
                            INT32_C( 2082954477), INT32_C( -606254738), INT32_C(-1628984154), INT32_C(  722122834)) },
    { simde_mm512_set_epi32(INT32_C( 1928049651), INT32_C(  765730488), INT32_C(  -85899231), INT32_C( 1435935141),
                            INT32_C(-2098236580), INT32_C(-1991433794), INT32_C( 1298943776), INT32_C(  277470244),
                            INT32_C(-1834748849), INT32_C(  596054477), INT32_C( 1827419510), INT32_C(-1010527612),
                            INT32_C(-1687118128), INT32_C(  107945377), INT32_C( 1174128677), INT32_C(-1544325740)),
      simde_mm512_set_epi32(INT32_C( 2031968571), INT32_C(  333434400), INT32_C( -637142874), INT32_C( -520435756),
                            INT32_C( -148623413), INT32_C( -692754616), INT32_C(-1908406411), INT32_C( 1391053429),
                            INT32_C( 1767908668), INT32_C( 1117151413), INT32_C( 1466854108), INT32_C( -852914371),
                            INT32_C( -773785464), INT32_C(-2142007253), INT32_C(  466013192), INT32_C( 1313258175)),
      UINT16_C(48011),
      simde_mm512_set_epi32(INT32_C( -811849174), INT32_C(-1510825074), INT32_C( 1897985966), INT32_C( 1445172644),
                            INT32_C( -193622280), INT32_C( 2097959091), INT32_C( -652080500), INT32_C( 1943026961),
                            INT32_C(  763848022), INT32_C(-2124387583), INT32_C(-1102663841), INT32_C(  712044568),
                            INT32_C( 1641785760), INT32_C( 1696516135), INT32_C(-1123374630), INT32_C( -181070601)),
      simde_mm512_set_epi32(INT32_C( -193622280), INT32_C(  333434400), INT32_C(  596054477), INT32_C(  712044568),
                            INT32_C(-2098236580), INT32_C( -692754616), INT32_C(-1102663841), INT32_C(-1102663841),
                            INT32_C( 1445172644), INT32_C( 1117151413), INT32_C( 1466854108), INT32_C( -852914371),
                            INT32_C(  277470244), INT32_C(-2142007253), INT32_C(  277470244), INT32_C( -811849174)) },
    { simde_mm512_set_epi32(INT32_C(  729621709), INT32_C(-1241407128), INT32_C(  696721321), INT32_C( -603523965),
                            INT32_C( 1730687689), INT32_C(  290786615), INT32_C(-1827031380), INT32_C( 1429317129),
                            INT32_C(-1800615955), INT32_C( -728999228), INT32_C( -788606428), INT32_C( -539592973),
                            INT32_C(-1402526875), INT32_C(   -8263463), INT32_C(  478788156), INT32_C(  842200487)),
      simde_mm512_set_epi32(INT32_C( -770469750), INT32_C( 1013231130), INT32_C(  543156562), INT32_C( -399740514),
                            INT32_C(  509655415), INT32_C( -160537509), INT32_C( -549528402), INT32_C( -323547130),
                            INT32_C(-1395624565), INT32_C(-1905505546), INT32_C(-1268587914), INT32_C( 1939823644),
                            INT32_C(-1112752789), INT32_C( 2052878307), INT32_C( -856056848), INT32_C(-1218860495)),
      UINT16_C(  903),
      simde_mm512_set_epi32(INT32_C( 1969107101), INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053),
                            INT32_C( 1035482990), INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639),
                            INT32_C( -638430290), INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613),
                            INT32_C(  165266600), INT32_C( -798384264), INT32_C( 1607584815), INT32_C(-1324336584)),
      simde_mm512_set_epi32(INT32_C( -770469750), INT32_C( 1013231130), INT32_C(  543156562), INT32_C( -399740514),
                            INT32_C(  509655415), INT32_C( -160537509), INT32_C(-1241407128), INT32_C( -728999228),
                            INT32_C( 1730687689), INT32_C(-1905505546), INT32_C(-1268587914), INT32_C( 1939823644),
                            INT32_C(-1112752789), INT32_C(-1402526875), INT32_C(-1324336584), INT32_C( 1607584815)) },
    { simde_mm512_set_epi32(INT32_C(-1349190316), INT32_C(-1403674818), INT32_C( -521443925), INT32_C(-1464291783),
                            INT32_C(-1686112999), INT32_C(-1290233716), INT32_C( -364563113), INT32_C( 1520783126),
                            INT32_C( -207159885), INT32_C( -104006691), INT32_C(  362759403), INT32_C(-1562242573),
                            INT32_C( -397133039), INT32_C(  568974515), INT32_C(-1726442446), INT32_C(-2134949944)),
      simde_mm512_set_epi32(INT32_C( -560036292), INT32_C(-1693642327), INT32_C(-1383827159), INT32_C( 1804875719),
                            INT32_C( 1179452315), INT32_C(-1509656190), INT32_C(-1409992701), INT32_C(-1830359468),
                            INT32_C(  635753031), INT32_C(  310246197), INT32_C(-1783943034), INT32_C(-1307643183),
                            INT32_C( -144888334), INT32_C(  621611179), INT32_C(  743650285), INT32_C( 1845744981)),
      UINT16_C(  487),
      simde_mm512_set_epi32(INT32_C(-2094713086), INT32_C(  197529411), INT32_C( 1055036471), INT32_C(  351897115),
                            INT32_C( 1594003471), INT32_C(-1709813294), INT32_C( -133653364), INT32_C(  -51462036),
                            INT32_C(   46796230), INT32_C(  989301899), INT32_C( -691937914), INT32_C( 1667629581),
                            INT32_C( -496700661), INT32_C(-1318801755), INT32_C( 1076515270), INT32_C(-1757573505)),
      simde_mm512_set_epi32(INT32_C( -560036292), INT32_C(-1693642327), INT32_C(-1383827159), INT32_C( 1804875719),
                            INT32_C( 1179452315), INT32_C(-1509656190), INT32_C(-1409992701), INT32_C( 1667629581),
                            INT32_C( -207159885), INT32_C( -691937914), INT32_C( -104006691), INT32_C(-1307643183),
                            INT32_C( -144888334), INT32_C(-1686112999), INT32_C( -521443925), INT32_C( -691937914)) },
    { simde_mm512_set_epi32(INT32_C( -662725541), INT32_C(  790228415), INT32_C(  -26753919), INT32_C( -495897274),
                            INT32_C( 1526994051), INT32_C( 1569343894), INT32_C(-1059990980), INT32_C( -490626870),
                            INT32_C( 1463745126), INT32_C( -957352131), INT32_C( 1122208393), INT32_C(-1814919780),
                            INT32_C(-1891682702), INT32_C( -176064246), INT32_C(-1293286075), INT32_C(-1398303881)),
      simde_mm512_set_epi32(INT32_C( -204514420), INT32_C( 1112369408), INT32_C( 2113109396), INT32_C(-1679339682),
                            INT32_C( 2128430529), INT32_C(-1262713143), INT32_C( 1026756660), INT32_C(-1268083621),
                            INT32_C(  337660693), INT32_C( 1524090799), INT32_C( -275653210), INT32_C(-1422519849),
                            INT32_C( -495051500), INT32_C( 1851182812), INT32_C(    5027269), INT32_C( -594726618)),
      UINT16_C(21630),
      simde_mm512_set_epi32(INT32_C( -501257427), INT32_C(-1329431510), INT32_C( 1005777948), INT32_C(  616430734),
                            INT32_C( 1581162255), INT32_C( 1497456456), INT32_C(-1170808415), INT32_C(-1014503666),
                            INT32_C(-1157750165), INT32_C( 1691363299), INT32_C( 1100655145), INT32_C(  673265711),
                            INT32_C( 1544659928), INT32_C(-1956803094), INT32_C( 1970109422), INT32_C(-1197844366)),
      simde_mm512_set_epi32(INT32_C( -204514420), INT32_C(-1398303881), INT32_C( 2113109396), INT32_C(-1329431510),
                            INT32_C( 2128430529), INT32_C(-1059990980), INT32_C( 1026756660), INT32_C(-1268083621),
                            INT32_C(  337660693), INT32_C( -662725541), INT32_C( -957352131), INT32_C(-1157750165),
                            INT32_C(  673265711), INT32_C(  616430734), INT32_C( 1122208393), INT32_C( -594726618)) },
    { simde_mm512_set_epi32(INT32_C(-1875196295), INT32_C( -129416454), INT32_C(  246939492), INT32_C(-1135915662),
                            INT32_C( -539014135), INT32_C( 1554320066), INT32_C( 1611314079), INT32_C(-1013292897),
                            INT32_C( 1135188428), INT32_C(-1903831246), INT32_C( 1207366326), INT32_C( -366505666),
                            INT32_C( 1379479886), INT32_C( 1577255779), INT32_C( -488475560), INT32_C(  143370041)),
      simde_mm512_set_epi32(INT32_C( -632623581), INT32_C(  612963145), INT32_C( 1824881051), INT32_C(  582494706),
                            INT32_C(-1899955415), INT32_C(  618457733), INT32_C( 1216635147), INT32_C( 1404062051),
                            INT32_C( 1905825928), INT32_C(-1635796069), INT32_C(  528096299), INT32_C(  259240399),
                            INT32_C(  271372102), INT32_C( 1305969598), INT32_C(  974818283), INT32_C(  377057639)),
      UINT16_C(42527),
      simde_mm512_set_epi32(INT32_C( -675362282), INT32_C(-1218762696), INT32_C(-1400182216), INT32_C(-2088680370),
                            INT32_C(-1895497877), INT32_C( 1563893931), INT32_C( 1105770515), INT32_C(-1745770541),
                            INT32_C(-1255255240), INT32_C( 1238532704), INT32_C(  995946229), INT32_C(  119517601),
                            INT32_C( 1389614040), INT32_C(-2032996348), INT32_C( 1996749952), INT32_C(  450477794)),
      simde_mm512_set_epi32(INT32_C( 1379479886), INT32_C(  612963145), INT32_C(-1895497877), INT32_C(  582494706),
                            INT32_C(-1899955415), INT32_C( 1207366326), INT32_C( -539014135), INT32_C( 1404062051),
                            INT32_C( 1905825928), INT32_C(-1635796069), INT32_C(  528096299), INT32_C(-1875196295),
                            INT32_C(-1903831246), INT32_C(-1218762696), INT32_C( -539014135), INT32_C( 1135188428)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask2_permutex2var_epi32(test_vec[i].a, test_vec[i].idx, test_vec[i].k, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_permutex2var_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i idx;
    simde__m512i b;
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
      simde_mm512_set_epi32(INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373), INT32_C( -695949043),
                            INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093), INT32_C(-2045280751),
                            INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336), INT32_C(  564965997),
                            INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685), INT32_C( 1430356381)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(-2068684593), INT32_C(          0), INT32_C(  145438126),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1570116932), INT32_C(-1801776439),
                            INT32_C(          0), INT32_C( 1777333881), INT32_C(          0), INT32_C( 1092805562),
                            INT32_C(          0), INT32_C(-1936012201), INT32_C( 1570116932), INT32_C(  223952317)) },
    { UINT16_C(24827),
      simde_mm512_set_epi32(INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755), INT32_C( 1549802795),
                            INT32_C(  159583350), INT32_C(  548883180), INT32_C( -605945909), INT32_C(-2063050181),
                            INT32_C( 1095467003), INT32_C(-2083755741), INT32_C( 2066979701), INT32_C( 1094609712),
                            INT32_C( 1345059025), INT32_C( -340318359), INT32_C( 1519671047), INT32_C(-1017461983)),
      simde_mm512_set_epi32(INT32_C( -888441293), INT32_C( -707551350), INT32_C(  513515868), INT32_C(-1825967755),
                            INT32_C(  822222164), INT32_C(-1689559027), INT32_C(  533478787), INT32_C(  907615417),
                            INT32_C( -199229058), INT32_C(  -91537812), INT32_C( 1375258232), INT32_C(  139748399),
                            INT32_C( 1688468565), INT32_C(  736544549), INT32_C(-1282057552), INT32_C(  795925067)),
      simde_mm512_set_epi32(INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417),
                            INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662),
                            INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205), INT32_C( -839037220),
                            INT32_C(  499633910), INT32_C( -260167255), INT32_C(  884163960), INT32_C( -329275629)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  548883180), INT32_C( 1469355417), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -195770682), INT32_C( 1549802795), INT32_C( 1258747662), INT32_C( 1720852541),
                            INT32_C( -622852205), INT32_C(          0), INT32_C( -329275629), INT32_C(  159583350)) },
    { UINT16_C(33750),
      simde_mm512_set_epi32(INT32_C(  722122834), INT32_C( -174985661), INT32_C(-1762469023), INT32_C( 1239606494),
                            INT32_C(  -22119232), INT32_C( 1216907749), INT32_C(  654527510), INT32_C(-2043358500),
                            INT32_C(  459072440), INT32_C( -430427651), INT32_C( -272088075), INT32_C(  386072301),
                            INT32_C(-1628984154), INT32_C(   87817524), INT32_C( 1219490517), INT32_C(-1569831145)),
      simde_mm512_set_epi32(INT32_C(  730787370), INT32_C(-2034110695), INT32_C(-1088138491), INT32_C( -353174912),
                            INT32_C( -362301616), INT32_C(  617951303), INT32_C(  817116152), INT32_C(-1034835761),
                            INT32_C( -102069057), INT32_C( 1774242298), INT32_C( 1089620040), INT32_C(-1101477862),
                            INT32_C( 2001101785), INT32_C(-1759250988), INT32_C( -606254738), INT32_C( 1526367108)),
      simde_mm512_set_epi32(INT32_C(  204417556), INT32_C(-1329665093), INT32_C(-2039025377), INT32_C( 1639231015),
                            INT32_C( 1541217841), INT32_C( 1692413538), INT32_C(  738521275), INT32_C(  159429100),
                            INT32_C(  451955897), INT32_C(  181201098), INT32_C(  450627934), INT32_C( 2082954477),
                            INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946), INT32_C(-1087388220)),
      simde_mm512_set_epi32(INT32_C( 1216907749), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(  159429100), INT32_C(  722122834),
                            INT32_C(  204417556), INT32_C( 1692413538), INT32_C(          0), INT32_C( 1692413538),
                            INT32_C(          0), INT32_C( 2082954477), INT32_C( -174985661), INT32_C(          0)) },
    { UINT16_C(30100),
      simde_mm512_set_epi32(INT32_C( 1313258175), INT32_C( 1928049651), INT32_C(  765730488), INT32_C(  -85899231),
                            INT32_C( 1435935141), INT32_C(-2098236580), INT32_C(-1991433794), INT32_C( 1298943776),
                            INT32_C(  277470244), INT32_C(-1834748849), INT32_C(  596054477), INT32_C( 1827419510),
                            INT32_C(-1010527612), INT32_C(-1687118128), INT32_C(  107945377), INT32_C( 1174128677)),
      simde_mm512_set_epi32(INT32_C( 1463729035), INT32_C( 2031968571), INT32_C(  333434400), INT32_C( -637142874),
                            INT32_C( -520435756), INT32_C( -148623413), INT32_C( -692754616), INT32_C(-1908406411),
                            INT32_C( 1391053429), INT32_C( 1767908668), INT32_C( 1117151413), INT32_C( 1466854108),
                            INT32_C( -852914371), INT32_C( -773785464), INT32_C(-2142007253), INT32_C(  466013192)),
      simde_mm512_set_epi32(INT32_C( -811849174), INT32_C(-1510825074), INT32_C( 1897985966), INT32_C( 1445172644),
                            INT32_C( -193622280), INT32_C( 2097959091), INT32_C( -652080500), INT32_C( 1943026961),
                            INT32_C(  763848022), INT32_C(-2124387583), INT32_C(-1102663841), INT32_C(  712044568),
                            INT32_C( 1641785760), INT32_C( 1696516135), INT32_C(-1123374630), INT32_C( -181070601)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( -193622280), INT32_C( 1174128677), INT32_C(-1834748849),
                            INT32_C(          0), INT32_C( 1435935141), INT32_C(          0), INT32_C(-1102663841),
                            INT32_C(-1102663841), INT32_C(          0), INT32_C(          0), INT32_C( 1445172644),
                            INT32_C(          0), INT32_C( 1298943776), INT32_C(          0), INT32_C(          0)) },
    { UINT16_C(62887),
      simde_mm512_set_epi32(INT32_C(-1218860495), INT32_C(  729621709), INT32_C(-1241407128), INT32_C(  696721321),
                            INT32_C( -603523965), INT32_C( 1730687689), INT32_C(  290786615), INT32_C(-1827031380),
                            INT32_C( 1429317129), INT32_C(-1800615955), INT32_C( -728999228), INT32_C( -788606428),
                            INT32_C( -539592973), INT32_C(-1402526875), INT32_C(   -8263463), INT32_C(  478788156)),
      simde_mm512_set_epi32(INT32_C(-1668086905), INT32_C( -770469750), INT32_C( 1013231130), INT32_C(  543156562),
                            INT32_C( -399740514), INT32_C(  509655415), INT32_C( -160537509), INT32_C( -549528402),
                            INT32_C( -323547130), INT32_C(-1395624565), INT32_C(-1905505546), INT32_C(-1268587914),
                            INT32_C( 1939823644), INT32_C(-1112752789), INT32_C( 2052878307), INT32_C( -856056848)),
      simde_mm512_set_epi32(INT32_C( 1969107101), INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053),
                            INT32_C( 1035482990), INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639),
                            INT32_C( -638430290), INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613),
                            INT32_C(  165266600), INT32_C( -798384264), INT32_C( 1607584815), INT32_C(-1324336584)),
      simde_mm512_set_epi32(INT32_C( 1429317129), INT32_C( 1730687689), INT32_C( 1183910939), INT32_C( -798384264),
                            INT32_C(          0), INT32_C( -638430290), INT32_C(          0), INT32_C(  729621709),
                            INT32_C(-1800615955), INT32_C(          0), INT32_C(-2007622482), INT32_C(          0),
                            INT32_C(          0), INT32_C( -603523965), INT32_C( -539592973), INT32_C(-1324336584)) },
    { UINT16_C(16328),
      simde_mm512_set_epi32(INT32_C( 1845744981), INT32_C(-1349190316), INT32_C(-1403674818), INT32_C( -521443925),
                            INT32_C(-1464291783), INT32_C(-1686112999), INT32_C(-1290233716), INT32_C( -364563113),
                            INT32_C( 1520783126), INT32_C( -207159885), INT32_C( -104006691), INT32_C(  362759403),
                            INT32_C(-1562242573), INT32_C( -397133039), INT32_C(  568974515), INT32_C(-1726442446)),
      simde_mm512_set_epi32(INT32_C(-1929379353), INT32_C( -560036292), INT32_C(-1693642327), INT32_C(-1383827159),
                            INT32_C( 1804875719), INT32_C( 1179452315), INT32_C(-1509656190), INT32_C(-1409992701),
                            INT32_C(-1830359468), INT32_C(  635753031), INT32_C(  310246197), INT32_C(-1783943034),
                            INT32_C(-1307643183), INT32_C( -144888334), INT32_C(  621611179), INT32_C(  743650285)),
      simde_mm512_set_epi32(INT32_C(-2094713086), INT32_C(  197529411), INT32_C( 1055036471), INT32_C(  351897115),
                            INT32_C( 1594003471), INT32_C(-1709813294), INT32_C( -133653364), INT32_C(  -51462036),
                            INT32_C(   46796230), INT32_C(  989301899), INT32_C( -691937914), INT32_C( 1667629581),
                            INT32_C( -496700661), INT32_C(-1318801755), INT32_C( 1076515270), INT32_C(-1757573505)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(-1290233716), INT32_C(-1290233716),
                            INT32_C( 1520783126), INT32_C( 1594003471), INT32_C( -397133039), INT32_C(-1562242573),
                            INT32_C( 1667629581), INT32_C( 1520783126), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1076515270), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT16_C(37751),
      simde_mm512_set_epi32(INT32_C( -594726618), INT32_C( -662725541), INT32_C(  790228415), INT32_C(  -26753919),
                            INT32_C( -495897274), INT32_C( 1526994051), INT32_C( 1569343894), INT32_C(-1059990980),
                            INT32_C( -490626870), INT32_C( 1463745126), INT32_C( -957352131), INT32_C( 1122208393),
                            INT32_C(-1814919780), INT32_C(-1891682702), INT32_C( -176064246), INT32_C(-1293286075)),
      simde_mm512_set_epi32(INT32_C(-1664789378), INT32_C( -204514420), INT32_C( 1112369408), INT32_C( 2113109396),
                            INT32_C(-1679339682), INT32_C( 2128430529), INT32_C(-1262713143), INT32_C( 1026756660),
                            INT32_C(-1268083621), INT32_C(  337660693), INT32_C( 1524090799), INT32_C( -275653210),
                            INT32_C(-1422519849), INT32_C( -495051500), INT32_C( 1851182812), INT32_C(    5027269)),
      simde_mm512_set_epi32(INT32_C( -501257427), INT32_C(-1329431510), INT32_C( 1005777948), INT32_C(  616430734),
                            INT32_C( 1581162255), INT32_C( 1497456456), INT32_C(-1170808415), INT32_C(-1014503666),
                            INT32_C(-1157750165), INT32_C( 1691363299), INT32_C( 1100655145), INT32_C(  673265711),
                            INT32_C( 1544659928), INT32_C(-1956803094), INT32_C( 1970109422), INT32_C(-1197844366)),
      simde_mm512_set_epi32(INT32_C(-1329431510), INT32_C(          0), INT32_C(          0), INT32_C(  673265711),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1569343894), INT32_C(  673265711),
                            INT32_C(          0), INT32_C( 1100655145), INT32_C( -594726618), INT32_C( 1463745126),
                            INT32_C(          0), INT32_C(  673265711), INT32_C(  616430734), INT32_C( -957352131)) },
    { UINT16_C(42809),
      simde_mm512_set_epi32(INT32_C(  377057639), INT32_C(-1875196295), INT32_C( -129416454), INT32_C(  246939492),
                            INT32_C(-1135915662), INT32_C( -539014135), INT32_C( 1554320066), INT32_C( 1611314079),
                            INT32_C(-1013292897), INT32_C( 1135188428), INT32_C(-1903831246), INT32_C( 1207366326),
                            INT32_C( -366505666), INT32_C( 1379479886), INT32_C( 1577255779), INT32_C( -488475560)),
      simde_mm512_set_epi32(INT32_C(   -7690721), INT32_C( -632623581), INT32_C(  612963145), INT32_C( 1824881051),
                            INT32_C(  582494706), INT32_C(-1899955415), INT32_C(  618457733), INT32_C( 1216635147),
                            INT32_C( 1404062051), INT32_C( 1905825928), INT32_C(-1635796069), INT32_C(  528096299),
                            INT32_C(  259240399), INT32_C(  271372102), INT32_C( 1305969598), INT32_C(  974818283)),
      simde_mm512_set_epi32(INT32_C( -675362282), INT32_C(-1218762696), INT32_C(-1400182216), INT32_C(-2088680370),
                            INT32_C(-1895497877), INT32_C( 1563893931), INT32_C( 1105770515), INT32_C(-1745770541),
                            INT32_C(-1255255240), INT32_C( 1238532704), INT32_C(  995946229), INT32_C(  119517601),
                            INT32_C( 1389614040), INT32_C(-2032996348), INT32_C( 1996749952), INT32_C(  450477794)),
      simde_mm512_set_epi32(INT32_C( -675362282), INT32_C(          0), INT32_C( 1554320066), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1554320066), INT32_C(-1903831246), INT32_C(-1135915662),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1895497877), INT32_C(-1135915662),
                            INT32_C(  377057639), INT32_C(          0), INT32_C(          0), INT32_C(-1135915662)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_permutex2var_epi32(test_vec[i].k, test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i idx;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 4022993628330696330), INT64_C( -564047204985781920),
                            INT64_C( 4934063986128071877), INT64_C( 8258886799903261224),
                            INT64_C( 5245738308211416456), INT64_C( 8690736315259258337),
                            INT64_C(-5183161890921602420), INT64_C(-2495336383094170141)),
      simde_mm512_set_epi64(INT64_C(-8115609027568940125), INT64_C( 3504612124823893047),
                            INT64_C(-7514888466798804666), INT64_C( 9113506312589344178),
                            INT64_C(-5948029684411535130), INT64_C(-4862378680423071053),
                            INT64_C( 7355766231574189317), INT64_C( -310150959079746096)),
      simde_mm512_set_epi64(INT64_C(-7443148953768886026), INT64_C( 8448077846545567514),
                            INT64_C(-7304267332935478206), INT64_C(-1528489088828046422),
                            INT64_C( 1295774678670654457), INT64_C(-8851107363323835123),
                            INT64_C( 2369486750103851747), INT64_C(-5139586436110975467)),
      simde_mm512_set_epi64(INT64_C( 5245738308211416456), INT64_C( 4022993628330696330),
                            INT64_C( -564047204985781920), INT64_C( 8690736315259258337),
                            INT64_C( -564047204985781920), INT64_C( 5245738308211416456),
                            INT64_C( 4934063986128071877), INT64_C(-2495336383094170141)) },
    { simde_mm512_set_epi64(INT64_C(-3094219001013742557), INT64_C(-3379016320921474793),
                            INT64_C( 7772273849745001049), INT64_C(-4229480058937372017),
                            INT64_C( 8318730560275653847), INT64_C(-2664412856586094061),
                            INT64_C( 2083707536546841162), INT64_C( 5404230241318444880)),
      simde_mm512_set_epi64(INT64_C(-7922172549839933132), INT64_C(   90826243433254935),
                            INT64_C( 1037923706586637130), INT64_C( 5568688997300093349),
                            INT64_C( 9199350188047982974), INT64_C(-7693432910203882071),
                            INT64_C(-5762072963977532348), INT64_C( 4491924425059371454)),
      simde_mm512_set_epi64(INT64_C( 7563354526679147255), INT64_C(-6952412028107066884),
                            INT64_C(-3077616107881632928), INT64_C(-2220298267656761827),
                            INT64_C( 2522518958303333112), INT64_C(-1668307566098600867),
                            INT64_C( 8306832211054389426), INT64_C(-4135341282024622606)),
      simde_mm512_set_epi64(INT64_C(-4229480058937372017), INT64_C(-3094219001013742557),
                            INT64_C(-1668307566098600867), INT64_C( 7772273849745001049),
                            INT64_C(-6952412028107066884), INT64_C( 8306832211054389426),
                            INT64_C(-4229480058937372017), INT64_C(-6952412028107066884)) },
    { simde_mm512_set_epi64(INT64_C(-6876215301736363293), INT64_C(-2253243373865166954),
                            INT64_C( 5866706473820467911), INT64_C(-1945184283153250111),
                            INT64_C(-6043663531296462836), INT64_C(-3201199251206898425),
                            INT64_C(-7517867743898200758), INT64_C( 5023666877462679332)),
      simde_mm512_set_epi64(INT64_C(  135432210503006619), INT64_C(-7059566968128636366),
                            INT64_C(-1295026765047609725), INT64_C( 5447800525707046939),
                            INT64_C( 1419500527032411112), INT64_C( 5424087511148175828),
                            INT64_C(-4780701435803039630), INT64_C( 6069825193561024149)),
      simde_mm512_set_epi64(INT64_C(-7404082530836275478), INT64_C(-6011864495242619751),
                            INT64_C(-2639903919112693390), INT64_C( 3391502071027493622),
                            INT64_C( 5698026186558744964), INT64_C( 6269499859520580584),
                            INT64_C( 7385991043015762011), INT64_C( 2173549174497415259)),
      simde_mm512_set_epi64(INT64_C( 5698026186558744964), INT64_C(-3201199251206898425),
                            INT64_C(-6043663531296462836), INT64_C( 5698026186558744964),
                            INT64_C( 2173549174497415259), INT64_C(-1945184283153250111),
                            INT64_C(-3201199251206898425), INT64_C( 5866706473820467911)) },
    { simde_mm512_set_epi64(INT64_C(-7778482448656032654), INT64_C(-7388935565641111344),
                            INT64_C( 2154583157079273400), INT64_C( 4649728279138736034),
                            INT64_C( 1896125478609903946), INT64_C( 6795120210135498653),
                            INT64_C(-8532964392806396349), INT64_C(-8044512602622188161)),
      simde_mm512_set_epi64(INT64_C( 8618855955534148826), INT64_C(-1358620153905394442),
                            INT64_C(-6300735262609682931), INT64_C(-6423460006708841158),
                            INT64_C(-7828848640852632692), INT64_C(-9058711782958006347),
                            INT64_C(-6631984369075385878), INT64_C(  312385656423386943)),
      simde_mm512_set_epi64(INT64_C( 2330675318709913935), INT64_C( 8512876982035459145),
                            INT64_C( -754385814369639096), INT64_C(-5873166547629617678),
                            INT64_C(-8313572030703954107), INT64_C( 8197482817575228316),
                            INT64_C( 7734796813438689885), INT64_C(-7308014241195865956)),
      simde_mm512_set_epi64(INT64_C( 8197482817575228316), INT64_C(-7388935565641111344),
                            INT64_C( -754385814369639096), INT64_C( 8197482817575228316),
                            INT64_C(-5873166547629617678), INT64_C( 2154583157079273400),
                            INT64_C( 8197482817575228316), INT64_C( 2330675318709913935)) },
    { simde_mm512_set_epi64(INT64_C(-8488192066941669485), INT64_C( 2196446486128224002),
                            INT64_C(-2769327913695750796), INT64_C( 8356403410464371881),
                            INT64_C(-1359912063489860660), INT64_C( 3839494741156011818),
                            INT64_C(-8628380254870238699), INT64_C(-3703720426743693096)),
      simde_mm512_set_epi64(INT64_C(-5841170484671274964), INT64_C(-3543508984518726324),
                            INT64_C( 3010243785522476560), INT64_C(-1544427551515059156),
                            INT64_C(-6824560769606762223), INT64_C( 5419183893290153987),
                            INT64_C(-6963147146169039734), INT64_C(  796151810828840161)),
      simde_mm512_set_epi64(INT64_C( 7773392645197032708), INT64_C(-2378134723719136690),
                            INT64_C( 3098859216623929918), INT64_C( 2705178435890570578),
                            INT64_C( 8034863847415814381), INT64_C( 2143618657886453602),
                            INT64_C( 1932054708809515818), INT64_C( -431037512959796468)),
      simde_mm512_set_epi64(INT64_C( 2705178435890570578), INT64_C( 2705178435890570578),
                            INT64_C(-3703720426743693096), INT64_C( 2705178435890570578),
                            INT64_C(-8628380254870238699), INT64_C(-1359912063489860660),
                            INT64_C( 2143618657886453602), INT64_C(-8628380254870238699)) },
    { simde_mm512_set_epi64(INT64_C( 7017505342718424326), INT64_C( 7336144214089986511),
                            INT64_C(-7372811814600044225), INT64_C( 3369678464815021090),
                            INT64_C(-3624005186939786961), INT64_C( 3053727983599056138),
                            INT64_C( 1044677486690381786), INT64_C( 7246985488966277586)),
      simde_mm512_set_epi64(INT64_C(-7724828277596580344), INT64_C(-6390405785894387099),
                            INT64_C( 1370770444668698151), INT64_C(  397783669977726534),
                            INT64_C(  618616089164357310), INT64_C(-2236191700094566243),
                            INT64_C(  606989345560642948), INT64_C(-5888219196601577993)),
      simde_mm512_set_epi64(INT64_C( 6890380242518530506), INT64_C( 7812910065385095491),
                            INT64_C( 6573936547803745655), INT64_C( 5624455476374850044),
                            INT64_C(-8202159596651692767), INT64_C(-5134690790763765861),
                            INT64_C( 6771966217713905101), INT64_C( 5500799798135763834)),
      simde_mm512_set_epi64(INT64_C( 5500799798135763834), INT64_C(-7372811814600044225),
                            INT64_C( 7017505342718424326), INT64_C( 7336144214089986511),
                            INT64_C( 7812910065385095491), INT64_C( 6573936547803745655),
                            INT64_C( 3369678464815021090), INT64_C( 7017505342718424326)) },
    { simde_mm512_set_epi64(INT64_C( 9087942297620858697), INT64_C(-5062502778264465278),
                            INT64_C( 4940486863427147430), INT64_C(-8466656670106113805),
                            INT64_C( 8779594976999061301), INT64_C(-6871795698650725249),
                            INT64_C( 7737606421984431976), INT64_C( 4256585739398952106)),
      simde_mm512_set_epi64(INT64_C( 3159639098800136017), INT64_C( 7547309067228210654),
                            INT64_C(  986058858743442499), INT64_C( -131493493066513451),
                            INT64_C( 4714195534976331711), INT64_C(-2919200212626154268),
                            INT64_C(-6480751279152247349), INT64_C(-8406130515310490191)),
      simde_mm512_set_epi64(INT64_C(-3303730405560337432), INT64_C( 1832719708746018971),
                            INT64_C( 7156376354960526422), INT64_C( 2595303813823857983),
                            INT64_C(   86688370885605369), INT64_C( 4396380977508135743),
                            INT64_C( 7341255277548419375), INT64_C( 7383808788818698409)),
      simde_mm512_set_epi64(INT64_C( 7737606421984431976), INT64_C( 1832719708746018971),
                            INT64_C( 8779594976999061301), INT64_C( 4940486863427147430),
                            INT64_C(-3303730405560337432), INT64_C(-8466656670106113805),
                            INT64_C(   86688370885605369), INT64_C( 7737606421984431976)) },
    { simde_mm512_set_epi64(INT64_C( 5459696121657899945), INT64_C( 2994903846606128408),
                            INT64_C( 5904359179218034313), INT64_C(-2066889829135543468),
                            INT64_C( 6803831723224696242), INT64_C(-1121730792444760624),
                            INT64_C(-7265999827078260931), INT64_C( 1814191055697415083)),
      simde_mm512_set_epi64(INT64_C(  199279425141616266), INT64_C( 3221796949435356069),
                            INT64_C(-1875768603448185105), INT64_C(  830129211732438864),
                            INT64_C( 3257319649738390908), INT64_C( 4257114197692508298),
                            INT64_C( 8024289238579469643), INT64_C( 2840131019362087365)),
      simde_mm512_set_epi64(INT64_C( 2502509311262690711), INT64_C( 5723836460071094920),
                            INT64_C( 7759612686570582771), INT64_C( 8703685710852381059),
                            INT64_C( 6587534258249310175), INT64_C( 2710240672169765174),
                            INT64_C( 8721065329514012238), INT64_C( 5835087168664292514)),
      simde_mm512_set_epi64(INT64_C( 2710240672169765174), INT64_C( 5904359179218034313),
                            INT64_C( 2502509311262690711), INT64_C( 1814191055697415083),
                            INT64_C( 8703685710852381059), INT64_C( 2710240672169765174),
                            INT64_C( 6587534258249310175), INT64_C( 5904359179218034313)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_permutex2var_epi64(test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask8 k;
    simde__m512i idx;
    simde__m512i b;
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
                            INT64_C(-3688244718601593553), INT64_C( 4873652658109514141),
                            INT64_C(-8315109086095518889), INT64_C(  624651997750430240)) },
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
      simde_mm512_set_epi64(INT64_C( -751557688731444383), INT64_C(-6742373427678247978),
                            INT64_C( 5226578984858504214), INT64_C(  877966720713550779),
                            INT64_C(-1848672680316222475), INT64_C( 1658167909352451238),
                            INT64_C(-8776157931044543560), INT64_C(-6742373427678247978)) },
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
                            INT64_C( 3280702275774868225), INT64_C(-9011857488067354178),
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
                            INT64_C( 3133701381660189032), INT64_C(-2879367942796632989),
                            INT64_C(-7733586635814839612), INT64_C(-3387038813920004365),
                            INT64_C(-6023807055599376167), INT64_C( 2056379472574346663)) },
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
                            INT64_C(-7241800185060747124), INT64_C( -889744926927160355),
                            INT64_C( -889744926927160355), INT64_C(-2239584601742201287),
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
                            INT64_C(-8124715335380010742), INT64_C(-4552626589350649654),
                            INT64_C( 6286737449187014461), INT64_C( -114907203345763002),
                            INT64_C(-4552626589350649654), INT64_C(-5554621393600539785)) },
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
                            INT64_C( 1060597045389905266), INT64_C(-5391280202694098336)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_permutex2var_epi64(test_vec[i].a, test_vec[i].k, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask2_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i idx;
    simde__mmask8 k;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-4408197122649025847), INT64_C(  624651997750430240),
                            INT64_C(-3688244718601593553), INT64_C( 4693564151120802069),
                            INT64_C( 7940316924786767481), INT64_C( 6743600876828439814),
                            INT64_C( 8561828216572109007), INT64_C(-8315109086095518889)),
      simde_mm512_set_epi64(INT64_C( -890089152921238147), INT64_C( 8823574133744668217),
                            INT64_C(-6364969741708969084), INT64_C(-1418976459802394322),
                            INT64_C( 4477375336277674053), INT64_C( 1282248710630285123),
                            INT64_C( 6638105739971879812), INT64_C(-8038098956427236545)),
      UINT8_C( 25),
      simde_mm512_set_epi64(INT64_C( 7350668077567080689), INT64_C( 8478919882954811661),
                            INT64_C(-3394066222784588743), INT64_C(-5009306653852991983),
                            INT64_C(-8749971605870264899), INT64_C( 1212032624670585453),
                            INT64_C(  728623586565902494), INT64_C( 4873652658109514141)),
      simde_mm512_set_epi64(INT64_C( -890089152921238147), INT64_C( 8823574133744668217),
                            INT64_C(-6364969741708969084), INT64_C( 8478919882954811661),
                            INT64_C(-3688244718601593553), INT64_C( 1282248710630285123),
                            INT64_C( 6638105739971879812), INT64_C( 7350668077567080689)) },
    { simde_mm512_set_epi64(INT64_C(-6111840559061041971), INT64_C( 6656352319933975670),
                            INT64_C( 2357435311113502667), INT64_C(-8860733056306413573),
                            INT64_C(-8949662758380266635), INT64_C( 4701312916269037777),
                            INT64_C(-1461656220613716217), INT64_C(-4369965941555109637)),
      simde_mm512_set_epi64(INT64_C(-3038909907977133732), INT64_C(-7842471790453318316),
                            INT64_C(-7256600765093102205), INT64_C( 3898178537456140670),
                            INT64_C( -393151907512138120), INT64_C(  600214805061827669),
                            INT64_C( 3163434753014979248), INT64_C( 3418472134552461373)),
      UINT8_C( 51),
      simde_mm512_set_epi64(INT64_C( 7306080674171373254), INT64_C( 2163582539809461657),
                            INT64_C(-7942896186346970451), INT64_C(-2775611318017263858),
                            INT64_C( 7897714815450887445), INT64_C(-2675129847260557604),
                            INT64_C( 2145911307457407401), INT64_C( 3797455296467543827)),
      simde_mm512_set_epi64(INT64_C(-3038909907977133732), INT64_C(-7842471790453318316),
                            INT64_C(-8949662758380266635), INT64_C( 2163582539809461657),
                            INT64_C( -393151907512138120), INT64_C(  600214805061827669),
                            INT64_C(-4369965941555109637), INT64_C(-7942896186346970451)) },
    { simde_mm512_set_epi64(INT64_C( -751557688731444383), INT64_C( 5324069355912068288),
                            INT64_C( 5226578984858504214), INT64_C(-8776157931044543560),
                            INT64_C(-1848672680316222475), INT64_C( 1658167909352451238),
                            INT64_C(  377173394815185621), INT64_C(-6742373427678247978)),
      simde_mm512_set_epi64(INT64_C(-8736438908262001915), INT64_C(-1516874692875012272),
                            INT64_C( 2654080637722702840), INT64_C(-4444585746033374017),
                            INT64_C( 7620312646179506248), INT64_C(-4730811392556899367),
                            INT64_C(-7555925455226975890), INT64_C( 6555696811272222802)),
      UINT8_C( 42),
      simde_mm512_set_epi64(INT64_C(  877966720713550779), INT64_C(-8757547308289839577),
                            INT64_C( 6619480224799141474), INT64_C( 3171924723684651500),
                            INT64_C( 1941135797030545610), INT64_C( 1935432241277000941),
                            INT64_C( 5390015454023535429), INT64_C(  -49705421380794940)),
      simde_mm512_set_epi64(INT64_C(-8736438908262001915), INT64_C(-1516874692875012272),
                            INT64_C(  -49705421380794940), INT64_C(-4444585746033374017),
                            INT64_C(  -49705421380794940), INT64_C(-4730811392556899367),
                            INT64_C(-8757547308289839577), INT64_C( 6555696811272222802)) },
    { simde_mm512_set_epi64(INT64_C( 8280910196874944184), INT64_C( -368934386460614235),
                            INT64_C(-9011857488067354178), INT64_C( 5578921037540219940),
                            INT64_C(-7880186302232587827), INT64_C( 7848707034806784644),
                            INT64_C(-7246117184140796511), INT64_C( 5042844271761388948)),
      simde_mm512_set_epi64(INT64_C( 8727238559278288416), INT64_C(-2736507802934917164),
                            INT64_C( -638332694652688568), INT64_C(-8196543121330681227),
                            INT64_C( 7593109912492073141), INT64_C( 6300090425305304893),
                            INT64_C(-3323383259847225301), INT64_C( 2001511420457827007)),
      UINT8_C(139),
      simde_mm512_set_epi64(INT64_C(-3486865648830471282), INT64_C( 8151787653682140580),
                            INT64_C( -831601358278995789), INT64_C(-2800664419916301039),
                            INT64_C( 3280702275774868225), INT64_C(-4735905134864699368),
                            INT64_C( 7051416147935021095), INT64_C(-4824857292892203785)),
      simde_mm512_set_epi64(INT64_C( 5042844271761388948), INT64_C(-2736507802934917164),
                            INT64_C( -638332694652688568), INT64_C(-8196543121330681227),
                            INT64_C(-9011857488067354178), INT64_C( 6300090425305304893),
                            INT64_C( 3280702275774868225), INT64_C(-3486865648830471282)) },
    { simde_mm512_set_epi64(INT64_C( 3133701381660189032), INT64_C( 2992395291812361347),
                            INT64_C( 7433247024135605559), INT64_C(-7847040024436431351),
                            INT64_C(-7733586635814839612), INT64_C(-3387038813920004365),
                            INT64_C(-6023807055599376167), INT64_C( 2056379472574346663)),
      simde_mm512_set_epi64(INT64_C(-3309142377794064870), INT64_C( 2332839674293023134),
                            INT64_C( 2188953343788737627), INT64_C(-2360206510841720826),
                            INT64_C(-5994161861779764490), INT64_C(-5448543600791036900),
                            INT64_C(-4779236835234910237), INT64_C(-3676736162600736207)),
      UINT8_C(135),
      simde_mm512_set_epi64(INT64_C( 8457250603347908949), INT64_C(-2879367942796632989),
                            INT64_C( 4447365578798205979), INT64_C( 6508361231067538121),
                            INT64_C(-2742037214038451026), INT64_C(  735886283373328205),
                            INT64_C(  709814645617696632), INT64_C( 6904524208941840952)),
      simde_mm512_set_epi64(INT64_C(  735886283373328205), INT64_C( 2332839674293023134),
                            INT64_C( 2188953343788737627), INT64_C(-2360206510841720826),
                            INT64_C(-5994161861779764490), INT64_C( 6508361231067538121),
                            INT64_C(-7733586635814839612), INT64_C(-6023807055599376167)) },
    { simde_mm512_set_epi64(INT64_C(-5794728280408613058), INT64_C(-2239584601742201287),
                            INT64_C(-7241800185060747124), INT64_C(-1565786646142169322),
                            INT64_C( -889744926927160355), INT64_C( 1558039774934209011),
                            INT64_C(-1705673414097118029), INT64_C(-7415013841836228664)),
      simde_mm512_set_epi64(INT64_C(-2405337556111781463), INT64_C(-5943492389416716345),
                            INT64_C( 5065709122901801346), INT64_C(-6055872535929098668),
                            INT64_C( 2730538476788120373), INT64_C(-7661976985969691951),
                            INT64_C( -622290655480313685), INT64_C( 3193953655581824341)),
      UINT8_C(231),
      simde_mm512_set_epi64(INT64_C(-8996724198675706045), INT64_C( 4531347139384149531),
                            INT64_C( 6846192780240638418), INT64_C( -574036823136878484),
                            INT64_C(  200988278415395979), INT64_C(-2971850709824830963),
                            INT64_C(-2133313091920417115), INT64_C( 4623597880832003711)),
      simde_mm512_set_epi64(INT64_C(-2133313091920417115), INT64_C(-5794728280408613058),
                            INT64_C( 1558039774934209011), INT64_C(-6055872535929098668),
                            INT64_C( 2730538476788120373), INT64_C(-1705673414097118029),
                            INT64_C(  200988278415395979), INT64_C(-7241800185060747124)) },
    { simde_mm512_set_epi64(INT64_C(-2846384524028678721), INT64_C( -114907203345763002),
                            INT64_C( 6558389511800899990), INT64_C(-4552626589350649654),
                            INT64_C( 6286737449187014461), INT64_C( 4819848349711762844),
                            INT64_C(-8124715335380010742), INT64_C(-5554621393600539785)),
      simde_mm512_set_epi64(INT64_C( -878382744348038912), INT64_C( 9075735751305940830),
                            INT64_C( 9141539516895233737), INT64_C( 4409886278677075035),
                            INT64_C( 1450241635103786927), INT64_C(-1183921519114972713),
                            INT64_C(-2126230000484561188), INT64_C(   21591959643435302)),
      UINT8_C(126),
      simde_mm512_set_epi64(INT64_C(-2152884252876571606), INT64_C( 4319783394314419342),
                            INT64_C( 6791040176392068936), INT64_C(-5028583849026132210),
                            INT64_C(-4972499093922240541), INT64_C( 4727277852622403631),
                            INT64_C( 6634263876539878890), INT64_C( 8461555540128585842)),
      simde_mm512_set_epi64(INT64_C( -878382744348038912), INT64_C( 4319783394314419342),
                            INT64_C( 6634263876539878890), INT64_C(-4972499093922240541),
                            INT64_C(-2152884252876571606), INT64_C(-2846384524028678721),
                            INT64_C(-5028583849026132210), INT64_C(   21591959643435302)) },
    { simde_mm512_set_epi64(INT64_C(-8053906756439817478), INT64_C( 1060597045389905266),
                            INT64_C(-2315048080352408894), INT64_C( 6920541276171034783),
                            INT64_C( 4875597175448786738), INT64_C( 5185598888390136126),
                            INT64_C( 5924820997437064035), INT64_C(-2097986554951915719)),
      simde_mm512_set_epi64(INT64_C(-2717097590460443831), INT64_C( 7837804433717602802),
                            INT64_C(-8160246370664650107), INT64_C( 5225408168933214563),
                            INT64_C( 8185460035288021915), INT64_C( 2268156333602877903),
                            INT64_C( 1165534304442745790), INT64_C( 4186812645404930407)),
      UINT8_C( 31),
      simde_mm512_set_epi64(INT64_C(-2900658911065724872), INT64_C(-6013736823954521010),
                            INT64_C(-8141101389788536661), INT64_C( 4749248201355274195),
                            INT64_C(-5391280202694098336), INT64_C( 4277556482249044385),
                            INT64_C( 5968346858124406788), INT64_C( 8575975742580047586)),
      simde_mm512_set_epi64(INT64_C(-2717097590460443831), INT64_C( 7837804433717602802),
                            INT64_C(-8160246370664650107), INT64_C( 4875597175448786738),
                            INT64_C(-5391280202694098336), INT64_C(-2900658911065724872),
                            INT64_C(-6013736823954521010), INT64_C(-8053906756439817478)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask2_permutex2var_epi64(test_vec[i].a, test_vec[i].idx, test_vec[i].k, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_permutex2var_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i idx;
    simde__m512i b;
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
      simde_mm512_set_epi64(INT64_C( 7350668077567080689), INT64_C( 8478919882954811661),
                            INT64_C(-3394066222784588743), INT64_C(-5009306653852991983),
                            INT64_C(-8749971605870264899), INT64_C( 1212032624670585453),
                            INT64_C(  728623586565902494), INT64_C( 4873652658109514141)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-5009306653852991983),
                            INT64_C(                   0), INT64_C(-3394066222784588743),
                            INT64_C(                   0), INT64_C( 4873652658109514141),
                            INT64_C(-8884932670315115433), INT64_C(-7738570880062900818)) },
    { UINT8_C(251),
      simde_mm512_set_epi64(INT64_C( 7391005387705442660), INT64_C(-5091463632259113685),
                            INT64_C(  685405269785004780), INT64_C(-2602517860068074949),
                            INT64_C( 4704994953943345443), INT64_C( 8877610218385468208),
                            INT64_C( 5776984527519295337), INT64_C( 6526937450820584225)),
      simde_mm512_set_epi64(INT64_C(-3815826294263537782), INT64_C( 2205533861506052469),
                            INT64_C( 3531417307031756813), INT64_C( 2291273944182365369),
                            INT64_C( -855682284319457684), INT64_C( 5906689130134529071),
                            INT64_C( 7251917267735594789), INT64_C(-5506395256633894325)),
      simde_mm512_set_epi64(INT64_C( 7306080674171373254), INT64_C( 2163582539809461657),
                            INT64_C(-7942896186346970451), INT64_C(-2775611318017263858),
                            INT64_C( 7897714815450887445), INT64_C(-2675129847260557604),
                            INT64_C( 2145911307457407401), INT64_C( 3797455296467543827)),
      simde_mm512_set_epi64(INT64_C(-2675129847260557604), INT64_C(  685405269785004780),
                            INT64_C(-7942896186346970451), INT64_C( 2145911307457407401),
                            INT64_C(-2775611318017263858), INT64_C(                   0),
                            INT64_C(  685405269785004780), INT64_C( 7897714815450887445)) },
    { UINT8_C(214),
      simde_mm512_set_epi64(INT64_C( 3101493959844818499), INT64_C(-7569746812758465314),
                            INT64_C(  -95001376835728923), INT64_C( 2811174252033921756),
                            INT64_C( 1971701120159461885), INT64_C(-1168609383370522899),
                            INT64_C(-6996433667044410060), INT64_C( 5237671891022268183)),
      simde_mm512_set_epi64(INT64_C( 3138707856740708121), INT64_C(-4673519228421997952),
                            INT64_C(-1556073591389999033), INT64_C( 3509487153133496527),
                            INT64_C( -438383259974317574), INT64_C( 4679882440059701274),
                            INT64_C( 8594666725077939668), INT64_C(-2603844271228681340)),
      simde_mm512_set_epi64(INT64_C(  877966720713550779), INT64_C(-8757547308289839577),
                            INT64_C( 6619480224799141474), INT64_C( 3171924723684651500),
                            INT64_C( 1941135797030545610), INT64_C( 1935432241277000941),
                            INT64_C( 5390015454023535429), INT64_C(  -49705421380794940)),
      simde_mm512_set_epi64(INT64_C( 5390015454023535429), INT64_C( 5237671891022268183),
                            INT64_C(                   0), INT64_C(  877966720713550779),
                            INT64_C(                   0), INT64_C( 1935432241277000941),
                            INT64_C( 2811174252033921756), INT64_C(                   0)) },
    { UINT8_C(148),
      simde_mm512_set_epi64(INT64_C( 5640400914757694451), INT64_C( 3288787407719188513),
                            INT64_C( 6167294471968879452), INT64_C(-8553143016080257248),
                            INT64_C( 1191725626053358671), INT64_C( 2560034487176803702),
                            INT64_C(-4340183042637127984), INT64_C(  463621865143519269)),
      simde_mm512_set_epi64(INT64_C( 6286668337562607931), INT64_C( 1432089847019206822),
                            INT64_C(-2235254547542691893), INT64_C(-2975358417486477451),
                            INT64_C( 5974528986311566652), INT64_C( 4798128784982043356),
                            INT64_C(-3663239326212228984), INT64_C(-9199851098963784696)),
      simde_mm512_set_epi64(INT64_C(-3486865648830471282), INT64_C( 8151787653682140580),
                            INT64_C( -831601358278995789), INT64_C(-2800664419916301039),
                            INT64_C( 3280702275774868225), INT64_C(-4735905134864699368),
                            INT64_C( 7051416147935021095), INT64_C(-4824857292892203785)),
      simde_mm512_set_epi64(INT64_C( 3280702275774868225), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 6167294471968879452),
                            INT64_C(                   0), INT64_C(-2800664419916301039),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(167),
      simde_mm512_set_epi64(INT64_C(-5234965963681749811), INT64_C(-5331803015084564567),
                            INT64_C(-2592115690296560951), INT64_C( 1248919004007478956),
                            INT64_C( 6138870327161964525), INT64_C(-3131027839562886620),
                            INT64_C(-2317534169293970587), INT64_C(  -35491302857917892)),
      simde_mm512_set_epi64(INT64_C(-7164378700336361334), INT64_C( 4351794567182281042),
                            INT64_C(-1716872434006574729), INT64_C( -689503347190866770),
                            INT64_C(-1389624339165317749), INT64_C(-8184083999390244234),
                            INT64_C( 8331479114169761131), INT64_C( 8817045194671758320)),
      simde_mm512_set_epi64(INT64_C( 8457250603347908949), INT64_C(-2879367942796632989),
                            INT64_C( 4447365578798205979), INT64_C( 6508361231067538121),
                            INT64_C(-2742037214038451026), INT64_C(  735886283373328205),
                            INT64_C(  709814645617696632), INT64_C( 6904524208941840952)),
      simde_mm512_set_epi64(INT64_C(  735886283373328205), INT64_C(                   0),
                            INT64_C(-5234965963681749811), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-5331803015084564567),
                            INT64_C(-2742037214038451026), INT64_C(  -35491302857917892)) },
    { UINT8_C(200),
      simde_mm512_set_epi64(INT64_C( 7927414333096918356), INT64_C(-6028737433755228757),
                            INT64_C(-6289085317177674471), INT64_C(-5541511610486147753),
                            INT64_C( 6531713794566454707), INT64_C( -446705336047418133),
                            INT64_C(-6709780755556058351), INT64_C( 2443726936750986290)),
      simde_mm512_set_epi64(INT64_C(-8286621218977708484), INT64_C(-7274138402675197655),
                            INT64_C( 7751882187628938139), INT64_C(-6483923961368987645),
                            INT64_C(-7861334054348205497), INT64_C( 1332497272334397574),
                            INT64_C(-5616284701672264206), INT64_C( 2669799685376652269)),
      simde_mm512_set_epi64(INT64_C(-8996724198675706045), INT64_C( 4531347139384149531),
                            INT64_C( 6846192780240638418), INT64_C( -574036823136878484),
                            INT64_C(  200988278415395979), INT64_C(-2971850709824830963),
                            INT64_C(-2133313091920417115), INT64_C( 4623597880832003711)),
      simde_mm512_set_epi64(INT64_C( -574036823136878484), INT64_C(-2133313091920417115),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 7927414333096918356), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(119),
      simde_mm512_set_epi64(INT64_C(-2554331370738443173), INT64_C( 3394005203063129217),
                            INT64_C(-2129862572478557053), INT64_C( 6740280704142266940),
                            INT64_C(-2107226359725098394), INT64_C(-4111796092278699383),
                            INT64_C(-7795021097560230286), INT64_C( -756190175563217595)),
      simde_mm512_set_epi64(INT64_C(-7150215929147729012), INT64_C( 4777590230543990164),
                            INT64_C(-7212709010936609343), INT64_C(-5423311652387614668),
                            INT64_C(-5446377680450598123), INT64_C( 6545920141858823590),
                            INT64_C(-6109676225565942508), INT64_C( 7950769636462343621)),
      simde_mm512_set_epi64(INT64_C(-2152884252876571606), INT64_C( 4319783394314419342),
                            INT64_C( 6791040176392068936), INT64_C(-5028583849026132210),
                            INT64_C(-4972499093922240541), INT64_C( 4727277852622403631),
                            INT64_C( 6634263876539878890), INT64_C( 8461555540128585842)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C( 6740280704142266940),
                            INT64_C(-7795021097560230286), INT64_C( 6740280704142266940),
                            INT64_C(                   0), INT64_C( 3394005203063129217),
                            INT64_C( 6740280704142266940), INT64_C(-2129862572478557053)) },
    { UINT8_C( 57),
      simde_mm512_set_epi64(INT64_C( 1619450230631745145), INT64_C( -555839437247348892),
                            INT64_C(-4878720615548236791), INT64_C( 6675753852597875615),
                            INT64_C(-4352059852748908084), INT64_C(-8176892937465564490),
                            INT64_C(-1574129847889219250), INT64_C( 6774261992038495320)),
      simde_mm512_set_epi64(INT64_C(  -33031391515316701), INT64_C( 2632656663253186971),
                            INT64_C( 2501795714758146857), INT64_C( 2656255738409935115),
                            INT64_C( 6030400592505510024), INT64_C(-7025690618752263125),
                            INT64_C( 1113429035778363206), INT64_C( 5609096713955085291)),
      simde_mm512_set_epi64(INT64_C(-2900658911065724872), INT64_C(-6013736823954521010),
                            INT64_C(-8141101389788536661), INT64_C( 4749248201355274195),
                            INT64_C(-5391280202694098336), INT64_C( 4277556482249044385),
                            INT64_C( 5968346858124406788), INT64_C( 8575975742580047586)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 5968346858124406788), INT64_C(-5391280202694098336),
                            INT64_C( 8575975742580047586), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-5391280202694098336)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_permutex2var_epi64(test_vec[i].k, test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t idx[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  94), -INT8_C(  25),  INT8_C(   8), -INT8_C(  65),  INT8_C(  59), -INT8_C(  67), -INT8_C(  63),  INT8_C(   4),
         INT8_C(  65),  INT8_C( 103), -INT8_C( 120),  INT8_C( 124), -INT8_C(  25),  INT8_C(  12),  INT8_C(  58),  INT8_C(   2),
         INT8_C(   8), -INT8_C( 112),  INT8_C(  93), -INT8_C( 118),  INT8_C( 116),  INT8_C( 122),  INT8_C( 121), -INT8_C( 110),
        -INT8_C(  13),  INT8_C( 108),  INT8_C(  80),  INT8_C( 119), -INT8_C(  53),  INT8_C( 104),  INT8_C( 114),  INT8_C(  41),
         INT8_C(  79),  INT8_C( 122), -INT8_C(  24), -INT8_C( 118),  INT8_C(  55), -INT8_C(  87), -INT8_C( 114),  INT8_C( 120),
         INT8_C(  16),  INT8_C(  22), -INT8_C(  11), -INT8_C(   9),  INT8_C(  34),  INT8_C(  47), -INT8_C(   7),  INT8_C(  43),
        -INT8_C(  65),  INT8_C(  86), -INT8_C(  75),  INT8_C(  51), -INT8_C(  47),  INT8_C(  46), -INT8_C(  58), -INT8_C(  60),
        -INT8_C( 102),  INT8_C(  22),  INT8_C(  59),  INT8_C( 101),      INT8_MAX, -INT8_C(  83), -INT8_C( 114), -INT8_C(  50) },
      {  INT8_C(  39),  INT8_C( 118),  INT8_C(  89),  INT8_C(  95),  INT8_C(  31), -INT8_C(  25), -INT8_C(  41),  INT8_C(  47),
        -INT8_C(   2), -INT8_C(  52),  INT8_C(  39),  INT8_C(  32), -INT8_C(   5),  INT8_C(  32),  INT8_C(  75), -INT8_C(  70),
         INT8_C( 119),  INT8_C(   1), -INT8_C(  18),  INT8_C(  72),  INT8_C(  47), -INT8_C(  76),  INT8_C(  12), -INT8_C(  54),
        -INT8_C(  54),  INT8_C(  72),  INT8_C(  47),  INT8_C(  73), -INT8_C(  11), -INT8_C(  66),  INT8_C(  24),  INT8_C(  29),
         INT8_C(  52),  INT8_C( 113),  INT8_C( 124),  INT8_C(  84),  INT8_C(  88),  INT8_C(  83), -INT8_C( 125),  INT8_C(  86),
         INT8_C(  32), -INT8_C(  86),  INT8_C( 119),  INT8_C(  27), -INT8_C(  53), -INT8_C(  62), -INT8_C(  42),  INT8_C(  66),
        -INT8_C(  61), -INT8_C(  60), -INT8_C( 118), -INT8_C(  13),  INT8_C( 120), -INT8_C( 106), -INT8_C(  67),  INT8_C(  66),
        -INT8_C(  34), -INT8_C(  20), -INT8_C( 116), -INT8_C(  44), -INT8_C(  86), -INT8_C(  92), -INT8_C(  15), -INT8_C(  33) },
      {  INT8_C(  21),  INT8_C( 109),  INT8_C(  51),  INT8_C( 109), -INT8_C(  64), -INT8_C(  74), -INT8_C(  60), -INT8_C(  32),
         INT8_C(  97),  INT8_C(  59), -INT8_C(   4),  INT8_C(  44), -INT8_C(   3), -INT8_C(  46),  INT8_C( 110), -INT8_C(  63),
        -INT8_C( 106), -INT8_C(   8), -INT8_C(  76),  INT8_C(  14), -INT8_C( 114),  INT8_C( 113),  INT8_C(  80),  INT8_C( 109),
         INT8_C(  93), -INT8_C(  36),  INT8_C(  65),  INT8_C(   8),      INT8_MIN,  INT8_C(  50), -INT8_C(  25), -INT8_C( 107),
        -INT8_C(  97),  INT8_C(  26),  INT8_C(   3),  INT8_C(  95), -INT8_C(  48), -INT8_C(  57),  INT8_C(  64),  INT8_C(  49),
         INT8_C(   2),  INT8_C(  60),  INT8_C(  93), -INT8_C(   1),  INT8_C(  14), -INT8_C(  53), -INT8_C(  64), -INT8_C(  92),
        -INT8_C(  61),  INT8_C( 116), -INT8_C(  78),  INT8_C(  82), -INT8_C(  27),  INT8_C(   2), -INT8_C(  65),  INT8_C(  67),
        -INT8_C(  33),  INT8_C(   0),  INT8_C(  75),  INT8_C(  95),  INT8_C(  50),  INT8_C(  50), -INT8_C(  11), -INT8_C(  47) },
      {  INT8_C( 120), -INT8_C(  65), -INT8_C(  36), -INT8_C( 107),  INT8_C(  41),  INT8_C(  49),  INT8_C( 109),  INT8_C(  43),
        -INT8_C(  11), -INT8_C(   3),  INT8_C( 120),  INT8_C(  79),  INT8_C(  95),  INT8_C(  79),  INT8_C(  44),  INT8_C(  59),
         INT8_C(  67), -INT8_C(  25), -INT8_C(  64),  INT8_C(  97),  INT8_C(  43), -INT8_C(  47), -INT8_C(  25), -INT8_C(   4),
        -INT8_C(   4),  INT8_C(  97),  INT8_C(  43),  INT8_C(  59),  INT8_C(   2), -INT8_C( 114), -INT8_C(  13),  INT8_C( 104),
        -INT8_C(  47),  INT8_C( 116),  INT8_C(  50), -INT8_C( 114),  INT8_C(  93),  INT8_C(  14), -INT8_C(  65),  INT8_C(  80),
         INT8_C(  79), -INT8_C(  11),  INT8_C(  67),  INT8_C( 119),  INT8_C(  44),  INT8_C(  51),  INT8_C(  80),  INT8_C(  51),
         INT8_C( 109), -INT8_C(  64), -INT8_C( 120),  INT8_C(  82), -INT8_C(  33),  INT8_C( 121), -INT8_C(  83),  INT8_C(  51),
        -INT8_C(  25),  INT8_C(  14), -INT8_C(  25), -INT8_C( 114), -INT8_C(  11),  INT8_C(  55),  INT8_C( 116), -INT8_C( 107) } },
    { {  INT8_C(  76), -INT8_C(   8),  INT8_C(  48),  INT8_C(  28), -INT8_C(  65),  INT8_C( 112),  INT8_C(  78), -INT8_C(  63),
        -INT8_C(  84), -INT8_C(  85), -INT8_C(  64), -INT8_C(  70),  INT8_C( 119), -INT8_C( 127),  INT8_C(  94),  INT8_C(  58),
        -INT8_C(  11),  INT8_C(  16), -INT8_C( 116), -INT8_C(  37),  INT8_C(  19),  INT8_C(  75),  INT8_C(  30), -INT8_C(  14),
         INT8_C(  75),  INT8_C( 105),  INT8_C(  81),  INT8_C( 125), -INT8_C( 101),  INT8_C(  70),  INT8_C(  78), -INT8_C(  25),
         INT8_C(  62),      INT8_MAX,  INT8_C(   3), -INT8_C(   3), -INT8_C(  17),  INT8_C(  81), -INT8_C(  66), -INT8_C( 100),
        -INT8_C(   3),      INT8_MAX,  INT8_C(  86),  INT8_C( 116),  INT8_C(   0), -INT8_C(  75), -INT8_C(  82), -INT8_C(  11),
        -INT8_C(  59),  INT8_C(  59), -INT8_C(  48), -INT8_C(  40), -INT8_C( 122), -INT8_C(  18), -INT8_C(  54), -INT8_C(  46),
         INT8_C(  87),  INT8_C(  28),  INT8_C(  79), -INT8_C(  14),  INT8_C(  98), -INT8_C(  98), -INT8_C(  39), -INT8_C(  95) },
      {  INT8_C(  29), -INT8_C(  35), -INT8_C(  98),  INT8_C(  12),  INT8_C(  46),  INT8_C(  93), -INT8_C(  88),  INT8_C(  43),
        -INT8_C(  36), -INT8_C(   1), -INT8_C(  97), -INT8_C(  36), -INT8_C(  76),  INT8_C(  78), -INT8_C(  47),  INT8_C( 121),
        -INT8_C( 119), -INT8_C(  94),  INT8_C(  82),  INT8_C(  15), -INT8_C( 112),  INT8_C(  28), -INT8_C(  31), -INT8_C(  24),
         INT8_C(  56),  INT8_C(  49), -INT8_C(  38), -INT8_C( 101), -INT8_C(  49), -INT8_C(  76),  INT8_C(  60), -INT8_C(  20),
        -INT8_C( 111), -INT8_C(  38), -INT8_C(   8), -INT8_C(  65),  INT8_C(  55), -INT8_C(  95), -INT8_C(  21),  INT8_C(  19),
        -INT8_C(  96), -INT8_C( 118), -INT8_C(  17),  INT8_C(  84), -INT8_C(  40), -INT8_C(  63), -INT8_C(  51),  INT8_C(  97),
         INT8_C(  99),  INT8_C(  31),  INT8_C( 113), -INT8_C(  13),  INT8_C(  60),  INT8_C(  82), -INT8_C(  37),  INT8_C( 116),
        -INT8_C( 125), -INT8_C(  74),  INT8_C(  15),  INT8_C(  82),  INT8_C( 106),  INT8_C(  75),  INT8_C(  62), -INT8_C(   5) },
      {  INT8_C(  38),  INT8_C(  55), -INT8_C(  70),  INT8_C(  93), -INT8_C(  40), -INT8_C(  91),  INT8_C( 113),  INT8_C( 120),
         INT8_C(  48),  INT8_C(  96), -INT8_C(  52),  INT8_C(   8),  INT8_C(  33), -INT8_C( 103),  INT8_C( 106), -INT8_C( 124),
        -INT8_C(  71), -INT8_C(  37),  INT8_C( 120), -INT8_C(  11),  INT8_C(  45),  INT8_C(  83),  INT8_C( 105), -INT8_C(  79),
         INT8_C(   9),  INT8_C( 121),  INT8_C(   3),  INT8_C( 115), -INT8_C(  60),  INT8_C(  66),  INT8_C( 110), -INT8_C(  22),
         INT8_C( 121),  INT8_C(  41),  INT8_C(  72),  INT8_C(  81), -INT8_C(  50), -INT8_C(  71), -INT8_C(  55), -INT8_C(   2),
         INT8_C(  25), -INT8_C( 107),  INT8_C(   7),  INT8_C(  59),  INT8_C(  46),  INT8_C( 113), -INT8_C(  65), -INT8_C(  25),
         INT8_C(  76),  INT8_C(  55), -INT8_C(  36),  INT8_C( 121), -INT8_C( 117),  INT8_C(  70),  INT8_C(  42), -INT8_C( 108),
        -INT8_C(  65),  INT8_C(  46),  INT8_C(   8), -INT8_C( 125),  INT8_C( 112),  INT8_C( 118),  INT8_C( 110), -INT8_C(  23) },
      {  INT8_C(  70),  INT8_C(  66),  INT8_C(  78),  INT8_C( 119), -INT8_C(  82),  INT8_C(  66), -INT8_C(   3),  INT8_C( 116),
        -INT8_C(  60), -INT8_C(  23), -INT8_C(  25), -INT8_C(  60), -INT8_C( 122),  INT8_C( 106), -INT8_C(  37),  INT8_C(  46),
        -INT8_C(  85),  INT8_C(   3),  INT8_C( 120),  INT8_C(  58), -INT8_C(  11), -INT8_C( 101),  INT8_C(  41),  INT8_C(  25),
         INT8_C(  87),  INT8_C(  59),  INT8_C(   3),  INT8_C( 125), -INT8_C( 124), -INT8_C( 122),  INT8_C(  98),  INT8_C(  46),
         INT8_C(  16),  INT8_C(   3), -INT8_C(  65), -INT8_C(  95), -INT8_C(  46),      INT8_MAX,  INT8_C(  59), -INT8_C(  37),
         INT8_C(  62), -INT8_C(  64), -INT8_C(  25),  INT8_C(  45),  INT8_C(   9),  INT8_C(  55), -INT8_C( 103),  INT8_C(  41),
         INT8_C(  81), -INT8_C(  25),  INT8_C(  55),  INT8_C( 121),  INT8_C(  98),  INT8_C( 120),  INT8_C( 115), -INT8_C( 117),
         INT8_C(  28), -INT8_C(  54),  INT8_C(  58),  INT8_C( 120),  INT8_C(   7),  INT8_C(   8), -INT8_C(  39), -INT8_C( 125) } },
    { { -INT8_C(  97), -INT8_C(  74),  INT8_C(  58),  INT8_C( 110),  INT8_C( 111),  INT8_C(   3),  INT8_C( 108), -INT8_C( 120),
        -INT8_C( 104),  INT8_C( 115), -INT8_C(  61), -INT8_C(  58), -INT8_C(  28), -INT8_C( 125), -INT8_C(  82),  INT8_C(  48),
        -INT8_C(  70), -INT8_C( 118), -INT8_C(  86),  INT8_C(  69), -INT8_C(  48), -INT8_C(  44), -INT8_C(  38), -INT8_C( 113),
         INT8_C(   2), -INT8_C(  30),  INT8_C(  19),  INT8_C( 114),  INT8_C(  88), -INT8_C( 127),  INT8_C(  91), -INT8_C(   8),
         INT8_C(  55), -INT8_C( 107),  INT8_C( 102), -INT8_C(  90), -INT8_C( 104), -INT8_C(  46),  INT8_C(  46),  INT8_C(  48),
         INT8_C(  70), -INT8_C(  14), -INT8_C(   9),  INT8_C(  42),  INT8_C( 117), -INT8_C(  91),  INT8_C(  91),  INT8_C(  47),
         INT8_C(  47),  INT8_C(   5),  INT8_C( 117),  INT8_C(   0), -INT8_C(  39),  INT8_C(  79), -INT8_C( 113), -INT8_C(  36),
         INT8_C(  49), -INT8_C(  94),  INT8_C(  78), -INT8_C( 119),  INT8_C(  35), -INT8_C(  86), -INT8_C( 127),  INT8_C(  90) },
      {  INT8_C(  63), -INT8_C(  25),  INT8_C(   0), -INT8_C(  40), -INT8_C(  70),  INT8_C(  47),  INT8_C(   8),  INT8_C(   0),
         INT8_C(  33), -INT8_C(   1),  INT8_C(  42), -INT8_C( 106), -INT8_C(  92), -INT8_C( 123), -INT8_C(  59), -INT8_C(  44),
        -INT8_C( 118),  INT8_C(  58), -INT8_C(  44),  INT8_C( 100), -INT8_C( 119),  INT8_C(  99),  INT8_C(  64), -INT8_C(  70),
         INT8_C(   6), -INT8_C( 114),  INT8_C(  68),  INT8_C(  41),  INT8_C(  56), -INT8_C(  59), -INT8_C( 124),  INT8_C( 120),
        -INT8_C(  83), -INT8_C( 124),  INT8_C(  80),  INT8_C( 103), -INT8_C(  77),  INT8_C(  88),  INT8_C( 103), -INT8_C(  44),
         INT8_C(  88), -INT8_C( 111),  INT8_C( 106), -INT8_C(   4),  INT8_C(  23),  INT8_C(  48), -INT8_C(  48), -INT8_C(  95),
         INT8_C( 106), -INT8_C(  92),  INT8_C(   5), -INT8_C(  12),  INT8_C(   8),  INT8_C(  69), -INT8_C(  82),  INT8_C(  14),
        -INT8_C(  44), -INT8_C(  14),  INT8_C(  55),  INT8_C(  12), -INT8_C(  72), -INT8_C(  69), -INT8_C( 124),  INT8_C( 101) },
      {  INT8_C(  64), -INT8_C(  44), -INT8_C(  52), -INT8_C(  13),  INT8_C(  45),  INT8_C(  51), -INT8_C(  56), -INT8_C( 123),
        -INT8_C(  60),  INT8_C(  50), -INT8_C( 127), -INT8_C(  37),  INT8_C(  98),  INT8_C(  82),  INT8_C( 125), -INT8_C(  51),
        -INT8_C(  10), -INT8_C( 126), -INT8_C(  63), -INT8_C(   2), -INT8_C(  56),  INT8_C( 111),  INT8_C(  12), -INT8_C( 100),
         INT8_C(  98),  INT8_C(  68), -INT8_C(  88),  INT8_C(  26), -INT8_C(   1),  INT8_C(  45),      INT8_MAX,  INT8_C(  63),
         INT8_C(   1),  INT8_C(  75),  INT8_C(  51),  INT8_C(  46),  INT8_C( 126), -INT8_C(   5), -INT8_C(  77),  INT8_C(  66),
         INT8_C(  45),  INT8_C(  53),  INT8_C(  30), -INT8_C( 112), -INT8_C( 121), -INT8_C( 101),  INT8_C(  93),  INT8_C( 125),
         INT8_C(  29),  INT8_C(  30),  INT8_C( 124), -INT8_C(  27), -INT8_C( 115), -INT8_C( 120), -INT8_C( 127), -INT8_C(  17),
        -INT8_C(  52),  INT8_C(  42),  INT8_C(   9), -INT8_C(  52),  INT8_C(  87), -INT8_C( 120),  INT8_C(  11),  INT8_C(  88) },
      {  INT8_C(  90),  INT8_C(  66), -INT8_C(  97),  INT8_C(  98),  INT8_C(  78),  INT8_C(  47), -INT8_C( 104), -INT8_C(  97),
        -INT8_C( 107),  INT8_C(  88), -INT8_C(   9), -INT8_C(  38), -INT8_C( 104),  INT8_C(   3),  INT8_C(  51), -INT8_C(  56),
        -INT8_C(  61),  INT8_C(  78), -INT8_C(  56),  INT8_C( 126),  INT8_C( 115),  INT8_C(  46),  INT8_C(  64),  INT8_C(  78),
         INT8_C( 108), -INT8_C(  82),  INT8_C(  45), -INT8_C(  14),  INT8_C(  49),  INT8_C(  51),  INT8_C( 111), -INT8_C(  52),
        -INT8_C(  91),  INT8_C( 111), -INT8_C(  10),  INT8_C(  66),  INT8_C(   0),  INT8_C(  98),  INT8_C(  66), -INT8_C(  56),
         INT8_C(  98), -INT8_C( 118),  INT8_C(  30),  INT8_C(  87), -INT8_C( 113),  INT8_C(  47), -INT8_C(  10), -INT8_C( 107),
         INT8_C(  30), -INT8_C( 104),  INT8_C(   3), -INT8_C( 115), -INT8_C( 104),  INT8_C(  51),  INT8_C(  91), -INT8_C(  82),
        -INT8_C(  56),  INT8_C( 124), -INT8_C(  36), -INT8_C(  28),  INT8_C(  49), -INT8_C( 119),  INT8_C( 111), -INT8_C(   5) } },
    { { -INT8_C(  45),  INT8_C(  62), -INT8_C( 121),  INT8_C(  81),  INT8_C(  57),  INT8_C(  58), -INT8_C( 108),  INT8_C( 103),
         INT8_C( 111), -INT8_C(  78), -INT8_C(   9), -INT8_C(  10),  INT8_C(  77),  INT8_C(  84),  INT8_C( 116),  INT8_C( 106),
         INT8_C( 114), -INT8_C(  16),  INT8_C(  80), -INT8_C(   1),  INT8_C( 120), -INT8_C(  47), -INT8_C(  17),  INT8_C(  69),
        -INT8_C(   5), -INT8_C(   8),  INT8_C(  17),  INT8_C(  82), -INT8_C( 127),  INT8_C(  28), -INT8_C(  85),  INT8_C(  84),
         INT8_C(  91),  INT8_C(  50), -INT8_C(  90), -INT8_C( 108),  INT8_C( 108),  INT8_C(  58), -INT8_C(   5), -INT8_C(  36),
        -INT8_C(  20), -INT8_C(  14), -INT8_C(  46),  INT8_C(  57),  INT8_C(  70),  INT8_C(  70), -INT8_C(  93), -INT8_C(  72),
         INT8_C(  54), -INT8_C(  13), -INT8_C(  72), -INT8_C(  81), -INT8_C(  59), -INT8_C(  89), -INT8_C(  12), -INT8_C(  64),
        -INT8_C(  97),  INT8_C(   5),  INT8_C(  19),  INT8_C(  32),  INT8_C(  33), -INT8_C(  66),  INT8_C( 117),  INT8_C( 124) },
      { -INT8_C(  16),  INT8_C(  27),  INT8_C(  17),  INT8_C(  92),  INT8_C(  85),  INT8_C(  12),  INT8_C(  56),  INT8_C(  65),
        -INT8_C(   1),  INT8_C(  11),  INT8_C( 122),  INT8_C(  69),  INT8_C(  81),  INT8_C(  29), -INT8_C(   2), -INT8_C( 120),
         INT8_C(  17), -INT8_C(  74),  INT8_C(  55), -INT8_C(  42),  INT8_C(  93),  INT8_C(  43), -INT8_C( 106), -INT8_C(   4),
         INT8_C(  48), -INT8_C(  87),  INT8_C(  29),  INT8_C(  81),  INT8_C( 103), -INT8_C( 110), -INT8_C(  50),  INT8_C(  87),
        -INT8_C(  83), -INT8_C(  33), -INT8_C(  76),  INT8_C(   2), -INT8_C(  21), -INT8_C(  20),  INT8_C(  67), -INT8_C(  22),
        -INT8_C(   9), -INT8_C(  67),  INT8_C(  48),  INT8_C(  73), -INT8_C(  38),  INT8_C(  46), -INT8_C(  47), -INT8_C(  21),
        -INT8_C(  28),  INT8_C(   8), -INT8_C(  63),  INT8_C(  65),  INT8_C(  51),  INT8_C(  88),  INT8_C(  61),  INT8_C(  99),
         INT8_C(   1),  INT8_C(  90), -INT8_C(  76),  INT8_C( 105), -INT8_C(  20), -INT8_C( 126), -INT8_C(  64), -INT8_C( 103) },
      {  INT8_C(  97),  INT8_C( 116), -INT8_C( 101),  INT8_C(  77),  INT8_C(  97), -INT8_C(  34),  INT8_C(  55),  INT8_C(  88),
        -INT8_C( 101),  INT8_C( 103), -INT8_C(  95),  INT8_C( 118), -INT8_C( 107),  INT8_C( 114),  INT8_C(  97),  INT8_C( 121),
         INT8_C( 122),  INT8_C(  35), -INT8_C(  70), -INT8_C(  83),  INT8_C( 123), -INT8_C(   8),  INT8_C(  16),  INT8_C( 124),
         INT8_C(  82), -INT8_C(  59), -INT8_C(  27),  INT8_C(  63),  INT8_C(  71), -INT8_C(  90), -INT8_C(  40), -INT8_C(  87),
         INT8_C(  26),  INT8_C( 116), -INT8_C(  10),  INT8_C( 123),  INT8_C(  82),  INT8_C(  45), -INT8_C(  44), -INT8_C(  18),
        -INT8_C( 107),  INT8_C( 117),  INT8_C( 100),  INT8_C(  42), -INT8_C(  24), -INT8_C(  59), -INT8_C(  92),  INT8_C(  98),
        -INT8_C(  24),  INT8_C(  94),  INT8_C(  16),  INT8_C(  99),  INT8_C(  86),  INT8_C(  32), -INT8_C(  32), -INT8_C(  87),
        -INT8_C(  27), -INT8_C(  59), -INT8_C(  24),  INT8_C(  45),  INT8_C( 107), -INT8_C(  64), -INT8_C(  42), -INT8_C( 122) },
      { -INT8_C(  24),  INT8_C(  82), -INT8_C(  16),  INT8_C(  71), -INT8_C(   8),  INT8_C(  77), -INT8_C(  97),  INT8_C( 116),
        -INT8_C( 122), -INT8_C(  10), -INT8_C(  24), -INT8_C(  34),  INT8_C(  35),  INT8_C(  28), -INT8_C(  42),  INT8_C( 111),
        -INT8_C(  16), -INT8_C(  12), -INT8_C(  64),  INT8_C(  16), -INT8_C(  90),  INT8_C(  57), -INT8_C(  17),  INT8_C( 107),
         INT8_C(  54), -INT8_C(  14),  INT8_C(  28),  INT8_C(  35), -INT8_C(  18),  INT8_C(  80),  INT8_C(  97),  INT8_C( 124),
         INT8_C(  70), -INT8_C(  87), -INT8_C(  59), -INT8_C( 121),  INT8_C(  42), -INT8_C(  24),  INT8_C(  77),  INT8_C( 100),
        -INT8_C(  87), -INT8_C(  66),  INT8_C(  54),  INT8_C( 103), -INT8_C(  27), -INT8_C(  93),  INT8_C(  35),  INT8_C(  42),
         INT8_C(  82),  INT8_C( 111),  INT8_C( 116),  INT8_C( 116), -INT8_C(  81),  INT8_C(  82), -INT8_C(  66),  INT8_C( 123),
         INT8_C(  62), -INT8_C(  27), -INT8_C(  59),  INT8_C( 117), -INT8_C(  24), -INT8_C( 121),  INT8_C(  97), -INT8_C(   8) } },
    { {  INT8_C(  52), -INT8_C(  52),  INT8_C(   1), -INT8_C( 121), -INT8_C(   7), -INT8_C(  43),  INT8_C( 117), -INT8_C( 114),
         INT8_C(  75), -INT8_C(  39), -INT8_C(  71),  INT8_C(  51), -INT8_C(  98),  INT8_C(  93), -INT8_C( 107), -INT8_C( 121),
        -INT8_C(  69), -INT8_C(  91), -INT8_C(  22),  INT8_C(  18), -INT8_C(  58), -INT8_C(  54), -INT8_C(  69), -INT8_C(  85),
        -INT8_C( 112), -INT8_C(  93), -INT8_C(  40), -INT8_C(   5),  INT8_C(  99), -INT8_C(  82), -INT8_C( 127), -INT8_C( 104),
         INT8_C( 122), -INT8_C( 125),  INT8_C(  31),  INT8_C( 116),  INT8_C(  88), -INT8_C( 108),  INT8_C(   2), -INT8_C(  93),
         INT8_C( 109), -INT8_C(  69), -INT8_C(  42),  INT8_C(  11),  INT8_C(  24),  INT8_C( 108), -INT8_C( 110), -INT8_C(  44),
         INT8_C(  17),  INT8_C( 125), -INT8_C(  26), -INT8_C(  41),  INT8_C(  71), -INT8_C(  95), -INT8_C( 125), -INT8_C(  41),
         INT8_C(  68),  INT8_C(  91), -INT8_C(  45), -INT8_C(  89),  INT8_C(  10),  INT8_C(  84),  INT8_C(  63), -INT8_C( 124) },
      { -INT8_C(  41),  INT8_C(  94), -INT8_C(   8),  INT8_C(  48), -INT8_C(  14), -INT8_C(   5), -INT8_C(  45),  INT8_C(  95),
        -INT8_C(  74), -INT8_C(  86),  INT8_C( 107), -INT8_C(  49),  INT8_C(  22), -INT8_C(   3), -INT8_C(  93),  INT8_C(  39),
         INT8_C( 122), -INT8_C( 119), -INT8_C(   1), -INT8_C(  62),  INT8_C(  42), -INT8_C( 126), -INT8_C( 103),  INT8_C( 110),
        -INT8_C(  35),  INT8_C( 108),  INT8_C(  21), -INT8_C(  25), -INT8_C(  63),  INT8_C(  85),  INT8_C( 108), -INT8_C( 104),
        -INT8_C(  77),  INT8_C( 100), -INT8_C(  56), -INT8_C(  90),  INT8_C(  95), -INT8_C( 100),  INT8_C(   5),  INT8_C(  22),
         INT8_C(  70),  INT8_C( 112), -INT8_C(  27),  INT8_C(  92),  INT8_C( 110), -INT8_C( 120), -INT8_C( 125), -INT8_C(  24),
         INT8_C(  17), -INT8_C( 126), -INT8_C(  86),  INT8_C(  59),  INT8_C(   4),  INT8_C(  68), -INT8_C(  87), -INT8_C(  30),
        -INT8_C(  80), -INT8_C(  66), -INT8_C(  55),  INT8_C( 113),  INT8_C(  19),  INT8_C(  53),  INT8_C(  10), -INT8_C(  57) },
      { -INT8_C( 102), -INT8_C(  46),  INT8_C( 109), -INT8_C(   7),  INT8_C( 110),  INT8_C( 114),  INT8_C(  15), -INT8_C(  76),
        -INT8_C(  29), -INT8_C(  12),  INT8_C(  16),  INT8_C(  81),  INT8_C( 124), -INT8_C( 108),  INT8_C(  57), -INT8_C( 115),
         INT8_C(  22), -INT8_C(  28), -INT8_C(  56),  INT8_C(  27),  INT8_C(  40),  INT8_C( 113), -INT8_C(   3), -INT8_C(  40),
         INT8_C(  48), -INT8_C(  58),  INT8_C(  74),  INT8_C(  67), -INT8_C(   4),  INT8_C(  84),  INT8_C(  10), -INT8_C( 106),
         INT8_C(  38),  INT8_C( 119), -INT8_C( 113), -INT8_C( 107), -INT8_C(  22), -INT8_C(  97),  INT8_C(  73), -INT8_C(  51),
        -INT8_C( 109),  INT8_C(  90),  INT8_C(  30),  INT8_C(  16), -INT8_C(  18),  INT8_C(  87), -INT8_C(  99),  INT8_C(   4),
         INT8_C(  59),  INT8_C( 102),  INT8_C(  31),  INT8_C(  99), -INT8_C(  41),  INT8_C(  28),  INT8_C(  60),  INT8_C(   7),
        -INT8_C(  29), -INT8_C( 122),  INT8_C(  75), -INT8_C(  33), -INT8_C(  38),  INT8_C(  85),  INT8_C( 117),  INT8_C(   0) },
      { -INT8_C(  40),  INT8_C(  10), -INT8_C(  29),  INT8_C(  17),  INT8_C(  31), -INT8_C(  33),  INT8_C(  27), -INT8_C( 106),
        -INT8_C( 125), -INT8_C(  42),  INT8_C(  16), -INT8_C( 115), -INT8_C(  69),  INT8_C(  85),  INT8_C( 116), -INT8_C(  93),
         INT8_C(  75), -INT8_C(  39),  INT8_C(   0),  INT8_C( 109), -INT8_C(  42),  INT8_C(   1), -INT8_C(  93), -INT8_C(  99),
         INT8_C(  84), -INT8_C(  18), -INT8_C(  54), -INT8_C(  51), -INT8_C(  46),  INT8_C( 113), -INT8_C(  18), -INT8_C( 112),
        -INT8_C(  41), -INT8_C(  22), -INT8_C(  29),  INT8_C(   2), -INT8_C( 106),  INT8_C(  99), -INT8_C(  43), -INT8_C(  69),
         INT8_C(  15),  INT8_C(  59), -INT8_C(  97), -INT8_C(   4), -INT8_C(  99),  INT8_C(  75), -INT8_C( 121), -INT8_C( 109),
        -INT8_C(  91),  INT8_C(   1), -INT8_C(  42), -INT8_C(  89), -INT8_C(   7),  INT8_C( 110), -INT8_C(  69), -INT8_C( 113),
         INT8_C(  17),  INT8_C(  63), -INT8_C(  12),  INT8_C( 102),  INT8_C(  18), -INT8_C(  95), -INT8_C(  71), -INT8_C(  76) } },
    { { -INT8_C(  51),  INT8_C(   4), -INT8_C( 107), -INT8_C(  73), -INT8_C(  93), -INT8_C(  33), -INT8_C( 124),  INT8_C(  55),
         INT8_C(  57), -INT8_C(  94),  INT8_C(  71),  INT8_C(  39), -INT8_C(   7), -INT8_C(  28),  INT8_C(  43),  INT8_C(  53),
         INT8_C(  74),  INT8_C(  75), -INT8_C( 104),  INT8_C(  34),  INT8_C( 103), -INT8_C(  44),  INT8_C(  41),  INT8_C(  74),
         INT8_C(  90),  INT8_C( 116),  INT8_C(  41),  INT8_C(  52), -INT8_C(  54), -INT8_C(  98),  INT8_C(  53), -INT8_C( 105),
        -INT8_C(  93), -INT8_C(  54),  INT8_C(  78),  INT8_C(  70), -INT8_C(  87), -INT8_C(  46),  INT8_C( 125), -INT8_C(  30),
         INT8_C( 116), -INT8_C(  60),  INT8_C(   9),  INT8_C( 109), -INT8_C(  87),  INT8_C(  53), -INT8_C(  94), -INT8_C(  13),
             INT8_MIN,  INT8_C(  59),  INT8_C(  21), -INT8_C(  25),  INT8_C(  15),  INT8_C(  63),  INT8_C(  50),  INT8_C( 106),
        -INT8_C(  77),  INT8_C(  91), -INT8_C(  98),  INT8_C( 125), -INT8_C(   6), -INT8_C(  45),  INT8_C(  20), -INT8_C(  99) },
      { -INT8_C(  98),  INT8_C(  98), -INT8_C(  29),  INT8_C(  71),  INT8_C(  52),  INT8_C(  97),  INT8_C(  42), -INT8_C(  88),
         INT8_C(  37),  INT8_C(  51),  INT8_C(  22), -INT8_C(  50),  INT8_C( 104), -INT8_C(  72), -INT8_C(  62), -INT8_C(  24),
        -INT8_C(  13), -INT8_C(  41), -INT8_C(  48),  INT8_C(   3),  INT8_C(  22),  INT8_C(   2),  INT8_C( 109), -INT8_C(  54),
         INT8_C(  93),  INT8_C(  11),  INT8_C(  71),  INT8_C(  87), -INT8_C(  33),  INT8_C(  92), -INT8_C(  12),  INT8_C( 125),
        -INT8_C(  66), -INT8_C(  40), -INT8_C(  60), -INT8_C(  13),  INT8_C(  57), -INT8_C(  18), -INT8_C( 101),  INT8_C(  94),
         INT8_C(  34), -INT8_C(  79),  INT8_C(  45), -INT8_C( 118),  INT8_C( 106), -INT8_C(  17),  INT8_C( 115),  INT8_C(  93),
        -INT8_C(  58),  INT8_C(  67),  INT8_C(  96), -INT8_C(  35),  INT8_C(  69), -INT8_C(  51), -INT8_C(  89), -INT8_C(  94),
        -INT8_C(  39), -INT8_C(  18), -INT8_C(   6), -INT8_C(  72),  INT8_C(  74), -INT8_C(  18),  INT8_C(  53),  INT8_C(   9) },
      { -INT8_C(  58), -INT8_C(   7), -INT8_C(   4), -INT8_C(   1), -INT8_C(  24), -INT8_C( 105),  INT8_C(  94),  INT8_C(  10),
         INT8_C(  73), -INT8_C( 117), -INT8_C( 108), -INT8_C(  77),  INT8_C( 122),  INT8_C(   7),  INT8_C(  16),  INT8_C(  64),
         INT8_C(  74),  INT8_C( 113),  INT8_C(  29), -INT8_C( 113),  INT8_C(  62), -INT8_C(  60),  INT8_C(  50),  INT8_C(  23),
        -INT8_C(  77),  INT8_C(  44), -INT8_C(  49), -INT8_C(   3),  INT8_C(  26),  INT8_C(   4),  INT8_C(   6), -INT8_C(  31),
        -INT8_C(   2),  INT8_C(   2), -INT8_C(  32), -INT8_C(  26), -INT8_C( 102),  INT8_C(  62), -INT8_C(  16), -INT8_C(  29),
        -INT8_C(  55), -INT8_C( 124), -INT8_C( 106),  INT8_C(  67), -INT8_C( 116), -INT8_C(  90), -INT8_C( 124), -INT8_C(  42),
         INT8_C(  23), -INT8_C(  95),  INT8_C( 102),  INT8_C(  86),  INT8_C( 102), -INT8_C( 104),  INT8_C( 109),  INT8_C(  25),
        -INT8_C(  60),  INT8_C(  61),  INT8_C(  22), -INT8_C(  34),  INT8_C(  65),  INT8_C(  29), -INT8_C(  65),  INT8_C(  63) },
      {  INT8_C(  53), -INT8_C(  32), -INT8_C(  26),  INT8_C(  10),  INT8_C(  15),  INT8_C(   2),  INT8_C(   9),  INT8_C( 116),
        -INT8_C(  46), -INT8_C(  25),  INT8_C(  41),  INT8_C(  16), -INT8_C(  55), -INT8_C(  77), -INT8_C(   4), -INT8_C(  55),
         INT8_C(  86),  INT8_C(  23),  INT8_C(  74), -INT8_C(  73),  INT8_C(  41), -INT8_C( 107), -INT8_C(  90), -INT8_C( 108),
         INT8_C(   4),  INT8_C(  39),  INT8_C(  10),  INT8_C(  23), -INT8_C(  31),  INT8_C(  26),  INT8_C( 102),  INT8_C(  29),
         INT8_C(  20), -INT8_C(  77), -INT8_C(  24),  INT8_C(  86),  INT8_C(  91), -INT8_C( 124),  INT8_C(  52),  INT8_C(   6),
         INT8_C(  78),  INT8_C(  59),  INT8_C(  53),  INT8_C(  71), -INT8_C( 106), -INT8_C(  42),  INT8_C(  86),  INT8_C(   4),
         INT8_C(  94), -INT8_C(   1), -INT8_C(   2),  INT8_C(   4), -INT8_C( 105),  INT8_C(   7), -INT8_C(  30),  INT8_C(  78),
         INT8_C(  44), -INT8_C( 124),  INT8_C(  22), -INT8_C(  77), -INT8_C( 108), -INT8_C( 124),  INT8_C(  63), -INT8_C(  94) } },
    { {  INT8_C(  31), -INT8_C(  96),  INT8_C(  37), -INT8_C(  71), -INT8_C(  34),  INT8_C(  21), -INT8_C( 100), -INT8_C(  88),
        -INT8_C( 102),  INT8_C(  50), -INT8_C(  21),  INT8_C(  38), -INT8_C(  39),  INT8_C( 111), -INT8_C(   4), -INT8_C(  16),
         INT8_C(  17),  INT8_C(  98),  INT8_C(  70),  INT8_C( 119), -INT8_C(   6), -INT8_C(  76), -INT8_C( 112), -INT8_C(  66),
        -INT8_C(  15), -INT8_C(  90), -INT8_C(  99),  INT8_C(  50), -INT8_C(  61),  INT8_C(  92),  INT8_C( 114), -INT8_C(  29),
        -INT8_C(   4), -INT8_C( 105), -INT8_C( 100), -INT8_C(  37), -INT8_C(  83),  INT8_C(  57), -INT8_C( 125),  INT8_C(  71),
         INT8_C( 107),  INT8_C( 110),  INT8_C( 109),  INT8_C(  68), -INT8_C(  34),  INT8_C( 105),  INT8_C(  53), -INT8_C(  17),
        -INT8_C(  52),  INT8_C( 123),  INT8_C( 102), -INT8_C(  58),  INT8_C(  47), -INT8_C(  10), -INT8_C( 123),  INT8_C(  32),
        -INT8_C( 100),  INT8_C(  34),  INT8_C(  83),  INT8_C(  96),  INT8_C( 126), -INT8_C(  59),  INT8_C(  67),  INT8_C( 123) },
      {  INT8_C(  92), -INT8_C(  33),  INT8_C(  86),  INT8_C(   9),  INT8_C(  24), -INT8_C(  39),  INT8_C(  80), -INT8_C( 124),
         INT8_C(  71), -INT8_C(  67), -INT8_C(  56),  INT8_C(  37),  INT8_C(  39), -INT8_C(   3),  INT8_C(  20), -INT8_C(  13),
         INT8_C( 121),  INT8_C( 122), -INT8_C(  71), -INT8_C(  88),  INT8_C( 112),  INT8_C(  62), -INT8_C(  55),  INT8_C(  13),
         INT8_C(  96),  INT8_C(  28),  INT8_C( 109), -INT8_C(  33), -INT8_C(  31), -INT8_C(  80),  INT8_C(  90),  INT8_C(  61),
        -INT8_C( 113), -INT8_C(  80),  INT8_C(  71), -INT8_C(  88), -INT8_C( 119), -INT8_C( 105),  INT8_C(  44), -INT8_C(  48),
         INT8_C(  85), -INT8_C(  12), -INT8_C(  10),  INT8_C( 124), -INT8_C(  14),  INT8_C(  10),  INT8_C( 111),  INT8_C( 107),
        -INT8_C( 123),  INT8_C(  40),  INT8_C(  19), -INT8_C(  11),  INT8_C( 103), -INT8_C(  36),  INT8_C(   2), -INT8_C(  57),
        -INT8_C(   8),  INT8_C( 111), -INT8_C(  90), -INT8_C(  39),  INT8_C(  31),  INT8_C(   0),  INT8_C(  23), -INT8_C(  81) },
      { -INT8_C(  80),  INT8_C(  94),  INT8_C(  87),  INT8_C(  57), -INT8_C(  11), -INT8_C( 125),  INT8_C(  10),  INT8_C(  74),
         INT8_C( 119),  INT8_C(   0), -INT8_C(  58),  INT8_C( 105),  INT8_C(  10),  INT8_C(  53), -INT8_C(  44), -INT8_C( 113),
         INT8_C(  94), -INT8_C(  24), -INT8_C( 123), -INT8_C(  59), -INT8_C(  60), -INT8_C( 121), -INT8_C( 116), -INT8_C(  67),
        -INT8_C(   9),  INT8_C(  51), -INT8_C( 106),  INT8_C(  22),  INT8_C(  51), -INT8_C(  83), -INT8_C(  59), -INT8_C(  28),
         INT8_C(  11),  INT8_C(  28),  INT8_C(  29),  INT8_C(   1), -INT8_C(  97),  INT8_C(  39),  INT8_C(  75),  INT8_C(  23),
         INT8_C(  39),  INT8_C(  18),      INT8_MIN,  INT8_C(  50),  INT8_C(  71),  INT8_C(  85), -INT8_C(  63), -INT8_C(  91),
         INT8_C(  61),  INT8_C(  70),  INT8_C( 106),  INT8_C(   1), -INT8_C(  50), -INT8_C(   9), -INT8_C(  66), -INT8_C(  59),
         INT8_C(  42),  INT8_C(  85), -INT8_C(  37),  INT8_C(  93),  INT8_C(   2), -INT8_C(  95),  INT8_C(  65),  INT8_C(  14) },
      {  INT8_C(  51), -INT8_C(  28), -INT8_C( 116),  INT8_C(  50), -INT8_C(  15),  INT8_C(  51),  INT8_C(  94), -INT8_C(  34),
         INT8_C(  74), -INT8_C(  59),  INT8_C( 119),  INT8_C(  57),  INT8_C(  71), -INT8_C(  95), -INT8_C(   6),  INT8_C(   1),
         INT8_C(  85), -INT8_C(  37),  INT8_C(  34),  INT8_C( 107),  INT8_C(  61),  INT8_C(  67),  INT8_C(   0),  INT8_C( 111),
         INT8_C(  11), -INT8_C(  61),  INT8_C(  85), -INT8_C(  28),  INT8_C(  28), -INT8_C(  52), -INT8_C( 106), -INT8_C(  59),
        -INT8_C(  16), -INT8_C(  52),  INT8_C(  74),  INT8_C( 107),  INT8_C(  50), -INT8_C(  66), -INT8_C(  34),  INT8_C(  94),
        -INT8_C( 121), -INT8_C(  50), -INT8_C(  66),  INT8_C(   2),  INT8_C( 106), -INT8_C(  21), -INT8_C(  91),  INT8_C(  50),
         INT8_C(  21),  INT8_C( 107),  INT8_C( 119), -INT8_C(   9),  INT8_C(  23),  INT8_C(  51),  INT8_C(  37),  INT8_C(  74),
         INT8_C(  42), -INT8_C(  91), -INT8_C( 125),  INT8_C(  51), -INT8_C(  29),  INT8_C(  31), -INT8_C(  66), -INT8_C(  17) } },
    { { -INT8_C(  67),  INT8_C(  95),  INT8_C(  15),  INT8_C(  93), -INT8_C( 122),  INT8_C(  90),  INT8_C( 116), -INT8_C(  82),
         INT8_C( 108), -INT8_C(  12), -INT8_C(  32), -INT8_C(  76),  INT8_C(  73), -INT8_C(  95),  INT8_C(  89), -INT8_C( 122),
        -INT8_C(  24), -INT8_C(  60), -INT8_C( 120), -INT8_C(  74), -INT8_C(  69),  INT8_C(  70),  INT8_C( 123), -INT8_C(  27),
        -INT8_C( 101),  INT8_C(  86),  INT8_C(  66), -INT8_C(  98), -INT8_C(   9), -INT8_C( 124), -INT8_C(  84), -INT8_C(  75),
        -INT8_C(  29), -INT8_C(  69),  INT8_C(  18),  INT8_C( 105),  INT8_C(  21), -INT8_C( 122),  INT8_C(  23), -INT8_C( 126),
         INT8_C( 122), -INT8_C(   9),  INT8_C(  54), -INT8_C(  60), -INT8_C( 103), -INT8_C( 113),  INT8_C(  74), -INT8_C( 127),
         INT8_C(  83), -INT8_C(  46),  INT8_C(  55),  INT8_C(  14),  INT8_C(  25), -INT8_C(  78), -INT8_C(  13), -INT8_C(  76),
         INT8_C(   8),  INT8_C(  54),  INT8_C(  82),  INT8_C(   0), -INT8_C(  70), -INT8_C(   2), -INT8_C(  75), -INT8_C(  99) },
      { -INT8_C(  71), -INT8_C(  57),  INT8_C(   6), -INT8_C(  49),  INT8_C(  77),  INT8_C(  30),  INT8_C(  81), -INT8_C(  57),
         INT8_C(  21), -INT8_C( 121), -INT8_C( 117), -INT8_C(  82),  INT8_C(  22), -INT8_C(  42),  INT8_C(  47),  INT8_C( 106),
        -INT8_C(  88),  INT8_C( 102),  INT8_C( 120), -INT8_C(  63),  INT8_C(  24),  INT8_C( 108),  INT8_C( 118),  INT8_C(  33),
        -INT8_C(  94), -INT8_C(  56),  INT8_C(  33),  INT8_C(  92), -INT8_C(  57), -INT8_C(  42), -INT8_C(   7),      INT8_MIN,
        -INT8_C(  99), -INT8_C(   1),  INT8_C(  79), -INT8_C(  22),  INT8_C(  29), -INT8_C(  96), -INT8_C(  79),  INT8_C(  51),
         INT8_C(  39),  INT8_C(  61), -INT8_C(  31),  INT8_C(  62),  INT8_C(  19),  INT8_C(  17), -INT8_C(  88), -INT8_C(  69),
         INT8_C( 119),  INT8_C(  32),  INT8_C( 125), -INT8_C( 112), -INT8_C( 116), -INT8_C(  13), -INT8_C(  79),  INT8_C(  46),
        -INT8_C(  69), -INT8_C(  46), -INT8_C( 118), -INT8_C( 126), -INT8_C(  88), -INT8_C( 125),  INT8_C(   3),  INT8_C(  69) },
      { -INT8_C( 125),  INT8_C(  82),  INT8_C(  47), -INT8_C(  96), -INT8_C(  13), -INT8_C(  32), -INT8_C(  45),  INT8_C(  26),
         INT8_C(  29), -INT8_C(  75),  INT8_C(  88),  INT8_C(  48), -INT8_C(  58),  INT8_C(   0), -INT8_C(  20),  INT8_C(  61),
         INT8_C(  33),  INT8_C( 105), -INT8_C(  51), -INT8_C(  83),  INT8_C(  92),  INT8_C( 126), -INT8_C(  36),  INT8_C(  23),
         INT8_C(  80),  INT8_C( 102), -INT8_C( 102), -INT8_C(   8), -INT8_C(  22), -INT8_C(  99),  INT8_C(  61),  INT8_C( 109),
        -INT8_C(  17),  INT8_C( 108),  INT8_C(  13), -INT8_C(  30),  INT8_C(  77), -INT8_C(  31), -INT8_C(   3),  INT8_C( 106),
        -INT8_C( 106),  INT8_C(  85), -INT8_C( 101),  INT8_C(  92),  INT8_C(  86), -INT8_C( 121), -INT8_C( 103),  INT8_C( 119),
        -INT8_C(  16),  INT8_C( 103),  INT8_C(  36),  INT8_C(  76), -INT8_C(  27),  INT8_C(   0),  INT8_C(  99),  INT8_C(  54),
         INT8_C( 103), -INT8_C(   3),  INT8_C(  46),  INT8_C(  81), -INT8_C( 102),  INT8_C( 108), -INT8_C(  66), -INT8_C( 118) },
      {  INT8_C(  54),  INT8_C(  26),  INT8_C( 116),  INT8_C(  61),  INT8_C(   0), -INT8_C(  84),  INT8_C( 105),  INT8_C(  26),
         INT8_C(  70), -INT8_C(  82), -INT8_C(  76),  INT8_C(  74),  INT8_C( 123), -INT8_C(  36), -INT8_C( 127), -INT8_C( 101),
         INT8_C( 122), -INT8_C(   3),  INT8_C( 103),  INT8_C(  82), -INT8_C( 101),  INT8_C(  86),  INT8_C(  99), -INT8_C(  69),
         INT8_C(  18),  INT8_C(  29), -INT8_C(  69), -INT8_C(  22),  INT8_C(  26), -INT8_C(  36), -INT8_C(   3), -INT8_C(  67),
        -INT8_C( 124), -INT8_C( 118),  INT8_C(  61), -INT8_C( 101), -INT8_C( 124), -INT8_C(  29), -INT8_C(  46),  INT8_C(  14),
        -INT8_C( 126), -INT8_C(   2),  INT8_C( 108), -INT8_C(  75), -INT8_C(  74), -INT8_C(  60),  INT8_C( 122),  INT8_C(   0),
         INT8_C(  54), -INT8_C(  29),  INT8_C( 108), -INT8_C(  24),  INT8_C(  73),  INT8_C(  76), -INT8_C(  46),  INT8_C(  74),
         INT8_C(   0), -INT8_C(  51), -INT8_C(  32),  INT8_C(  15),  INT8_C( 122),  INT8_C(  93),  INT8_C(  93), -INT8_C(  32) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_permutex2var_epi8(a, idx, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_permutex2var_epi8(a, idx, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const simde__mmask64 k;
    const int8_t idx[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  82),  INT8_C(  85),  INT8_C(  49),  INT8_C(   4), -INT8_C(  40),  INT8_C(  25),  INT8_C(  35), -INT8_C(  64),
        -INT8_C(  90),  INT8_C(  61),  INT8_C( 110),  INT8_C(  91),  INT8_C( 116),  INT8_C(  61),  INT8_C(  86),  INT8_C(  91),
        -INT8_C(  53),  INT8_C( 122), -INT8_C(  75), -INT8_C(  28),  INT8_C(  85), -INT8_C( 102), -INT8_C(  83), -INT8_C(  28),
        -INT8_C(  21),  INT8_C( 105),  INT8_C(  58), -INT8_C( 118),  INT8_C(  34), -INT8_C(  34),  INT8_C(  13),  INT8_C( 116),
         INT8_C(  51),  INT8_C(  62),  INT8_C( 120),  INT8_C(  12),  INT8_C(  87), -INT8_C( 101), -INT8_C(  52), -INT8_C(   2),
        -INT8_C(  40),  INT8_C(  59),  INT8_C(  89),  INT8_C(  76),  INT8_C( 120), -INT8_C(  80), -INT8_C(  89),  INT8_C(  67),
         INT8_C(  42),  INT8_C(  93),  INT8_C(  39),      INT8_MAX, -INT8_C(   9), -INT8_C(  44),  INT8_C(  99), -INT8_C(  29),
         INT8_C(  61), -INT8_C(  98),  INT8_C( 109),  INT8_C(  95),  INT8_C( 124),  INT8_C( 122), -INT8_C(  45), -INT8_C(  80) },
      UINT64_C(13839149230955711673),
      { -INT8_C(  61),  INT8_C( 104),  INT8_C(  12),  INT8_C(  59),  INT8_C(  24), -INT8_C(  76),  INT8_C( 126),  INT8_C(  66),
         INT8_C(  17), -INT8_C(  91), -INT8_C(  63),  INT8_C(   8),  INT8_C( 121),  INT8_C(  37), -INT8_C(  21), -INT8_C(  74),
        -INT8_C(  61),  INT8_C(  89),  INT8_C(  21),  INT8_C(  63), -INT8_C(  45), -INT8_C(  23), -INT8_C(  17), -INT8_C( 116),
         INT8_C(  53), -INT8_C(  85), -INT8_C(  99),  INT8_C(  28),  INT8_C(  52), -INT8_C(  85), -INT8_C(  36), -INT8_C(   9),
         INT8_C(  19), -INT8_C(  23),  INT8_C(  51),  INT8_C(  43), -INT8_C(  99), -INT8_C(  79),  INT8_C( 109), -INT8_C(  82),
         INT8_C(  87),  INT8_C(  47), -INT8_C(  74), -INT8_C(  48),  INT8_C(  84), -INT8_C(  94), -INT8_C( 121),  INT8_C(  23),
        -INT8_C(   5), -INT8_C( 100),  INT8_C(  86), -INT8_C(  50), -INT8_C( 123),  INT8_C(  70),  INT8_C(  91), -INT8_C(  70),
        -INT8_C(  15), -INT8_C(   8), -INT8_C(  41),  INT8_C(  37), -INT8_C(  93), -INT8_C(  77),  INT8_C(  29), -INT8_C(  73) },
      { -INT8_C( 100),  INT8_C(  80), -INT8_C(  30),  INT8_C(  57),  INT8_C(   1),  INT8_C(  80), -INT8_C(  25),  INT8_C(  88),
             INT8_MAX, -INT8_C(  98),  INT8_C(  41), -INT8_C(  45),  INT8_C(  64), -INT8_C(  80), -INT8_C(  22),  INT8_C(  59),
         INT8_C(  76),  INT8_C(  64),  INT8_C(   9), -INT8_C(  46), -INT8_C( 122),  INT8_C( 100), -INT8_C( 116),  INT8_C( 120),
         INT8_C(  92),  INT8_C(  99), -INT8_C(  99),  INT8_C(   0),  INT8_C(  23), -INT8_C(  70), -INT8_C(  73), -INT8_C(  77),
         INT8_C(  10), -INT8_C( 103), -INT8_C(  19),  INT8_C(  12), -INT8_C(  23), -INT8_C(  44),  INT8_C( 100),  INT8_C( 104),
         INT8_C( 114), -INT8_C( 115),  INT8_C(  59), -INT8_C(  78),  INT8_C(  61),  INT8_C(  37), -INT8_C(  19), -INT8_C( 118),
         INT8_C( 102), -INT8_C(   9),  INT8_C(  92), -INT8_C(  20),  INT8_C(  91), -INT8_C(  24),  INT8_C( 100), -INT8_C(  72),
         INT8_C(  76),  INT8_C(   2), -INT8_C(  72),  INT8_C(  99), -INT8_C(  68),  INT8_C( 111),  INT8_C(  22), -INT8_C(  57) },
      {  INT8_C(  57),  INT8_C(  85),  INT8_C(  49),  INT8_C(  95), -INT8_C(  21), -INT8_C(   9),  INT8_C(  35), -INT8_C(  30),
        -INT8_C(  90),  INT8_C(  61),  INT8_C(  80), -INT8_C(  90),  INT8_C( 116),  INT8_C(  61), -INT8_C(  78),  INT8_C(  91),
        -INT8_C(  53),  INT8_C( 122), -INT8_C( 102), -INT8_C(  80), -INT8_C(  46), -INT8_C( 115), -INT8_C(  83),  INT8_C( 116),
        -INT8_C(  21),  INT8_C( 105),  INT8_C(  58), -INT8_C( 118), -INT8_C(   9), -INT8_C(  34),  INT8_C(  13),  INT8_C( 116),
        -INT8_C(  28), -INT8_C( 115),      INT8_MAX,  INT8_C(  12),  INT8_C(  87),  INT8_C(  93),  INT8_C(  37), -INT8_C(  89),
        -INT8_C(  40),  INT8_C(  59),  INT8_C(  89),  INT8_C(  76),  INT8_C( 120), -INT8_C(  80), -INT8_C(  89), -INT8_C(  28),
         INT8_C(  42),  INT8_C(  34), -INT8_C( 116), -INT8_C(  22), -INT8_C(   9), -INT8_C(  44),  INT8_C(  99), -INT8_C(  29),
         INT8_C(  61), -INT8_C(  98),  INT8_C( 109),  INT8_C(  95),  INT8_C( 124),  INT8_C( 122), -INT8_C(  34), -INT8_C(  29) } },
    { {  INT8_C(   8),  INT8_C(   3), -INT8_C(  45), -INT8_C(  14), -INT8_C(  40),  INT8_C(  55),  INT8_C(  90),  INT8_C(  74),
        -INT8_C(  59), -INT8_C( 106), -INT8_C(   3),  INT8_C(   2), -INT8_C(  69), -INT8_C(  22), -INT8_C( 116),  INT8_C(  33),
        -INT8_C(  31), -INT8_C(  24),  INT8_C(  14),  INT8_C(  61), -INT8_C(  47),  INT8_C( 114), -INT8_C(  11),  INT8_C(  29),
         INT8_C( 116), -INT8_C(  83),      INT8_MIN,  INT8_C(  49),  INT8_C(  28), -INT8_C( 106), -INT8_C(   8),  INT8_C(  36),
        -INT8_C( 102), -INT8_C(  53),  INT8_C(  22),  INT8_C( 114),  INT8_C(   2),  INT8_C( 113), -INT8_C(  68), -INT8_C(  57),
         INT8_C(   7), -INT8_C(  71), -INT8_C(  54), -INT8_C(  62), -INT8_C(  92),  INT8_C(  86), -INT8_C(  28), -INT8_C( 123),
         INT8_C(  63), -INT8_C(  14), -INT8_C(  62),  INT8_C(  16),  INT8_C( 100), -INT8_C(  73),  INT8_C(  45), -INT8_C(  39),
         INT8_C( 100), -INT8_C(  83),  INT8_C(  10),      INT8_MIN,  INT8_C(  67),  INT8_C(   2), -INT8_C(  91), -INT8_C(  35) },
      UINT64_C( 3717453404013837261),
      { -INT8_C(  59),  INT8_C(  97), -INT8_C(  10),  INT8_C( 105), -INT8_C(  73), -INT8_C(  38), -INT8_C(  17), -INT8_C(  10),
        -INT8_C(  52), -INT8_C(  79),  INT8_C(   6),  INT8_C(  48),  INT8_C( 105),  INT8_C(  51),  INT8_C(   9), -INT8_C(  51),
        -INT8_C(  32),  INT8_C(  19),  INT8_C(  78),  INT8_C(  36),  INT8_C(  21), -INT8_C(  13),  INT8_C(   1), -INT8_C(  30),
        -INT8_C(  82),  INT8_C(  81), -INT8_C(  78), -INT8_C(  37),  INT8_C(  93),  INT8_C(  73),  INT8_C(  14),  INT8_C(  34),
        -INT8_C(  86),  INT8_C(   4), -INT8_C( 116),  INT8_C(  97), -INT8_C(  34),  INT8_C( 123),  INT8_C(  88), -INT8_C(  86),
         INT8_C(  44),  INT8_C(  94), -INT8_C(  37), -INT8_C( 107), -INT8_C( 110), -INT8_C(  28),  INT8_C(  99),  INT8_C( 114),
        -INT8_C(   8), -INT8_C(  79), -INT8_C( 106),  INT8_C(  13), -INT8_C(  92), -INT8_C( 104), -INT8_C(  16),  INT8_C(  82),
        -INT8_C(  23), -INT8_C(  94),  INT8_C(  45),  INT8_C(  70), -INT8_C(  21),  INT8_C(  60),  INT8_C( 104), -INT8_C( 107) },
      {  INT8_C(  64), -INT8_C(  12), -INT8_C(  10),  INT8_C(  31),  INT8_C( 111),  INT8_C(  78), -INT8_C(  55), -INT8_C( 100),
        -INT8_C(  83), -INT8_C(  92),  INT8_C(  49),  INT8_C(  63), -INT8_C( 119), -INT8_C( 108), -INT8_C(  79), -INT8_C( 127),
         INT8_C(  69),  INT8_C(  72), -INT8_C( 114), -INT8_C(  23), -INT8_C(  32),  INT8_C( 126),  INT8_C(  60), -INT8_C(  55),
         INT8_C(  32),  INT8_C( 105),  INT8_C(  15),  INT8_C(  11), -INT8_C(  91),  INT8_C( 119), -INT8_C(  96), -INT8_C(  26),
         INT8_C( 108), -INT8_C( 105),  INT8_C(   5), -INT8_C(  37), -INT8_C(  27), -INT8_C(  50),  INT8_C( 119), -INT8_C( 110),
         INT8_C( 115), -INT8_C(  87), -INT8_C(  47), -INT8_C(   4),  INT8_C(  61), -INT8_C( 125),  INT8_C( 125), -INT8_C( 125),
        -INT8_C(  53),  INT8_C(  11),  INT8_C( 108), -INT8_C(  85), -INT8_C( 118), -INT8_C(  88),  INT8_C( 116), -INT8_C(  86),
         INT8_C(  18), -INT8_C( 125), -INT8_C(  74), -INT8_C(  73), -INT8_C(   6),  INT8_C(  86), -INT8_C(  99),  INT8_C( 102) },
      {  INT8_C(  78),  INT8_C(   3),  INT8_C( 116), -INT8_C(  87), -INT8_C(  40),  INT8_C(  55), -INT8_C( 125),  INT8_C( 116),
        -INT8_C( 119), -INT8_C(  14), -INT8_C(   3),  INT8_C(  63), -INT8_C(  87),  INT8_C(  16), -INT8_C( 116), -INT8_C( 108),
         INT8_C( 108),  INT8_C(  61), -INT8_C(  79),  INT8_C(   2), -INT8_C(  47),  INT8_C( 114),  INT8_C(   3),  INT8_C(  29),
        -INT8_C(  28),  INT8_C(  72), -INT8_C(  62),  INT8_C(  11),  INT8_C(  28), -INT8_C( 106), -INT8_C( 116),  INT8_C(  22),
        -INT8_C( 102), -INT8_C(  53), -INT8_C(  69), -INT8_C( 105),  INT8_C(   2), -INT8_C(  73), -INT8_C(  68), -INT8_C(  57),
         INT8_C(   7), -INT8_C(  71),  INT8_C(  11),  INT8_C( 114), -INT8_C(  92),  INT8_C(  86), -INT8_C(  28), -INT8_C( 123),
         INT8_C(  18), -INT8_C(  14), -INT8_C(  11),  INT8_C(  16),  INT8_C(   2), -INT8_C(  73),  INT8_C(  45), -INT8_C( 114),
        -INT8_C(  87),  INT8_C(  22),  INT8_C(  10),      INT8_MIN, -INT8_C(   4),  INT8_C(  67), -INT8_C(  91), -INT8_C(  35) } },
    { { -INT8_C(  19), -INT8_C(  94),  INT8_C(  66), -INT8_C(  45),  INT8_C( 113), -INT8_C(  71),  INT8_C( 101), -INT8_C(  28),
         INT8_C(  98),  INT8_C(  55), -INT8_C(  32), -INT8_C(  96), -INT8_C(  70),  INT8_C(  93),  INT8_C(  35), -INT8_C( 123),
         INT8_C( 104), -INT8_C( 113),  INT8_C(  48), -INT8_C(  14),  INT8_C(  56), -INT8_C(  92), -INT8_C(  99),  INT8_C(  74),
         INT8_C(  39),  INT8_C(  83),  INT8_C(   1),  INT8_C(  33), -INT8_C(  87), -INT8_C(  97), -INT8_C( 120), -INT8_C( 105),
         INT8_C(  65), -INT8_C(  54),  INT8_C( 106), -INT8_C(  78), -INT8_C( 125), -INT8_C(  49), -INT8_C( 106), -INT8_C(  26),
         INT8_C(   6),  INT8_C( 118), -INT8_C( 122), -INT8_C(  64), -INT8_C(  45), -INT8_C(  87),  INT8_C(  69),  INT8_C(  60),
         INT8_C(  56),  INT8_C( 117),  INT8_C(  46),  INT8_C( 112),  INT8_C(  25), -INT8_C(  53), -INT8_C(  70),  INT8_C(  64),
         INT8_C(  30), -INT8_C(  68),  INT8_C(  98), -INT8_C(  56),  INT8_C(  91), -INT8_C(  22),  INT8_C(  95), -INT8_C( 100) },
      UINT64_C(11465572668280916404),
      {  INT8_C(  92), -INT8_C(  93),  INT8_C(  95),  INT8_C(  47),  INT8_C(  76), -INT8_C(  91),  INT8_C( 107), -INT8_C( 123),
         INT8_C(  26), -INT8_C( 102), -INT8_C(  11),  INT8_C(  52),  INT8_C( 101), -INT8_C(  80),  INT8_C( 116), -INT8_C( 124),
         INT8_C( 108), -INT8_C(  42),  INT8_C(  76), -INT8_C(  57), -INT8_C(  64), -INT8_C(  85),  INT8_C(  99),  INT8_C( 116),
         INT8_C( 116), -INT8_C(  78), -INT8_C(  84),  INT8_C(  12), -INT8_C( 104), -INT8_C(  55), -INT8_C(  85), -INT8_C(  12),
         INT8_C( 109),  INT8_C(  11),  INT8_C(  35), -INT8_C(  71), -INT8_C(  80), -INT8_C( 113),  INT8_C(  62), -INT8_C(  54),
         INT8_C(  41),  INT8_C(  52), -INT8_C(   2), -INT8_C( 114), -INT8_C(  28),  INT8_C( 115),  INT8_C(  18),  INT8_C(  80),
         INT8_C(  73),  INT8_C(  94),  INT8_C(  23),  INT8_C(  10),  INT8_C(   9),  INT8_C( 122),  INT8_C( 126),  INT8_C( 125),
         INT8_C(  45),  INT8_C(  42), -INT8_C( 118), -INT8_C(  59), -INT8_C(  12),  INT8_C(  53), -INT8_C(  71),  INT8_C(  97) },
      {  INT8_C(  64), -INT8_C(  36),  INT8_C(  26), -INT8_C(  16),  INT8_C( 107),  INT8_C(  89), -INT8_C(  69), -INT8_C( 108),
        -INT8_C( 115), -INT8_C(  71),  INT8_C(  35),  INT8_C( 113),  INT8_C(  44),  INT8_C(  53), -INT8_C(  63),  INT8_C( 118),
        -INT8_C( 108), -INT8_C(  40),      INT8_MIN, -INT8_C(  99),  INT8_C(  82), -INT8_C(   2),  INT8_C(  27),      INT8_MAX,
         INT8_C(  41), -INT8_C(  91),  INT8_C(  68),  INT8_C(  29), -INT8_C(  38), -INT8_C(   3),  INT8_C( 126),  INT8_C(  27),
        -INT8_C(  38), -INT8_C( 104),  INT8_C(  11),  INT8_C(  69), -INT8_C(  15), -INT8_C(  58), -INT8_C(  38),  INT8_C( 126),
             INT8_MIN, -INT8_C(   3), -INT8_C(  17), -INT8_C(  84),  INT8_C(  50), -INT8_C(  80),  INT8_C(  34), -INT8_C(  58),
        -INT8_C( 120), -INT8_C(  94),  INT8_C( 100), -INT8_C(  37), -INT8_C(  95),      INT8_MAX,  INT8_C(  90), -INT8_C(  54),
         INT8_C(  36), -INT8_C(  97), -INT8_C(  25), -INT8_C(   2), -INT8_C( 100),  INT8_C( 101),  INT8_C(  25),  INT8_C( 118) },
      { -INT8_C(  19), -INT8_C(  94),  INT8_C(  27), -INT8_C(  45),  INT8_C(  44), -INT8_C(  49),  INT8_C( 101), -INT8_C(  71),
         INT8_C(   1),  INT8_C(  55), -INT8_C(  32),  INT8_C(  25), -INT8_C(  70),  INT8_C(  93), -INT8_C(  95),  INT8_C( 113),
         INT8_C(  50),  INT8_C(  27),  INT8_C(  44), -INT8_C( 108),  INT8_C(  56), -INT8_C(  92),  INT8_C(  69),  INT8_C(  74),
        -INT8_C(  95),  INT8_C(  46), -INT8_C(  45),  INT8_C(  33),  INT8_C(  39), -INT8_C(  71), -INT8_C( 120), -INT8_C( 105),
         INT8_C(  65), -INT8_C(  54),  INT8_C( 106), -INT8_C(  68),  INT8_C(  56), -INT8_C(  49), -INT8_C( 106),  INT8_C(  35),
         INT8_C( 118),  INT8_C( 118),  INT8_C(  25), -INT8_C(  64), -INT8_C(  45), -INT8_C(  37),  INT8_C(  48), -INT8_C( 108),
        -INT8_C(  71),  INT8_C( 117),  INT8_C(  74), -INT8_C(  32),  INT8_C(  55), -INT8_C(  53), -INT8_C(  70),  INT8_C(  64),
        -INT8_C(  87), -INT8_C( 122), -INT8_C(  32),  INT8_C(  89), -INT8_C(  95), -INT8_C(  22),  INT8_C(  95), -INT8_C( 104) } },
    { { -INT8_C(   3),  INT8_C(  37), -INT8_C(  68), -INT8_C(  17), -INT8_C(  21), -INT8_C( 106),  INT8_C( 109),  INT8_C( 107),
        -INT8_C( 109),  INT8_C(  93),  INT8_C(  24), -INT8_C(  59),  INT8_C(  13),  INT8_C(  58), -INT8_C( 116), -INT8_C( 106),
        -INT8_C(  35), -INT8_C(  16),  INT8_C( 113),  INT8_C( 126),  INT8_C( 111), -INT8_C(  53),  INT8_C(  72), -INT8_C( 109),
         INT8_C( 106),  INT8_C(  47), -INT8_C( 111),  INT8_C(   7), -INT8_C( 108), -INT8_C(  85),  INT8_C( 125), -INT8_C( 111),
        -INT8_C(  48),  INT8_C(  57),      INT8_MIN, -INT8_C(  69), -INT8_C(  49), -INT8_C(  18),  INT8_C(  39),  INT8_C(  98),
         INT8_C(  75),  INT8_C(  63),  INT8_C(  40),  INT8_C(  88),  INT8_C( 121), -INT8_C(  76), -INT8_C(  18),  INT8_C(  86),
        -INT8_C(  92),  INT8_C(  95), -INT8_C(  44),  INT8_C(  19),  INT8_C(  43),  INT8_C(  28), -INT8_C(  90), -INT8_C( 107),
         INT8_C(  75),  INT8_C(  55), -INT8_C( 100), -INT8_C(  33), -INT8_C(  30),  INT8_C(  26),  INT8_C( 113), -INT8_C(  78) },
      UINT64_C( 3064019907100209491),
      { -INT8_C(  44), -INT8_C(  83), -INT8_C( 125),  INT8_C(  77),  INT8_C(  97),  INT8_C( 113), -INT8_C(  92),  INT8_C(   5),
        -INT8_C(  47),  INT8_C( 120),  INT8_C(  24), -INT8_C(   4), -INT8_C( 107), -INT8_C(  66), -INT8_C( 111), -INT8_C(  32),
        -INT8_C(  10),  INT8_C(  46), -INT8_C(  64), -INT8_C(  40),  INT8_C(  72),  INT8_C(  49), -INT8_C( 117), -INT8_C( 101),
         INT8_C(  34), -INT8_C(   7), -INT8_C(  66),  INT8_C(   2), -INT8_C( 114),  INT8_C(  68),  INT8_C(  44),  INT8_C(  98),
        -INT8_C(  15), -INT8_C(  81), -INT8_C(  81),  INT8_C(  83),  INT8_C(  33),  INT8_C(  83),  INT8_C(  88), -INT8_C(  14),
        -INT8_C(  52),  INT8_C( 113), -INT8_C(  18),  INT8_C(  97),  INT8_C(  47),      INT8_MAX,  INT8_C(  65),  INT8_C(  37),
        -INT8_C(  83),  INT8_C(   1), -INT8_C(   2), -INT8_C(  11),  INT8_C(  50), -INT8_C( 119), -INT8_C( 111),  INT8_C(  85),
        -INT8_C( 126),  INT8_C(  79),  INT8_C(  87),  INT8_C(  16), -INT8_C( 109), -INT8_C( 125),  INT8_C( 114), -INT8_C( 123) },
      {  INT8_C(  51),  INT8_C(  33), -INT8_C(  40),  INT8_C(  84),  INT8_C( 117),  INT8_C(  48),  INT8_C(  70),  INT8_C(  65),
        -INT8_C(  95),  INT8_C(  52), -INT8_C(  94), -INT8_C(  47), -INT8_C(  77), -INT8_C(  29), -INT8_C(  10),  INT8_C(  97),
        -INT8_C(  27), -INT8_C(  12),  INT8_C(  86),  INT8_C(  23),  INT8_C( 125), -INT8_C(  25),  INT8_C( 108), -INT8_C(   1),
         INT8_C(  55), -INT8_C(  61),  INT8_C(  15), -INT8_C(  54),  INT8_C(  71), -INT8_C( 127),  INT8_C(  79),  INT8_C( 122),
        -INT8_C(  93),  INT8_C(  39), -INT8_C(  50),  INT8_C(  24),  INT8_C(  88),  INT8_C(  20),  INT8_C(  89), -INT8_C(   7),
         INT8_C(  72), -INT8_C(   5), -INT8_C(  54), -INT8_C(   5), -INT8_C(  34), -INT8_C(  63),  INT8_C(  92), -INT8_C(  61),
        -INT8_C(  75), -INT8_C(  77), -INT8_C(  37),  INT8_C(  51), -INT8_C( 102),  INT8_C(  71),  INT8_C(  50), -INT8_C(  47),
         INT8_C(  11),  INT8_C(  66), -INT8_C( 100),  INT8_C(  82), -INT8_C(  61), -INT8_C(  21), -INT8_C(  52),  INT8_C( 102) },
      {  INT8_C( 125), -INT8_C(  76), -INT8_C(  68), -INT8_C(  17),  INT8_C(  39), -INT8_C( 106), -INT8_C(  49),  INT8_C( 107),
        -INT8_C(  12),  INT8_C(  93),  INT8_C(  24), -INT8_C(  59), -INT8_C(  53),  INT8_C( 113), -INT8_C(  16), -INT8_C(  93),
        -INT8_C(  35), -INT8_C(  18),  INT8_C(  51),  INT8_C(  55),  INT8_C( 111),  INT8_C(  95), -INT8_C(  59), -INT8_C( 109),
             INT8_MIN,  INT8_C(  66), -INT8_C( 111),  INT8_C(   7), -INT8_C( 108),  INT8_C( 117),  INT8_C( 125), -INT8_C( 111),
        -INT8_C(  77),  INT8_C(  86),  INT8_C(  86),  INT8_C(  23),  INT8_C(  57), -INT8_C(  18),  INT8_C(  55), -INT8_C(  37),
        -INT8_C(  77),  INT8_C(  63),  INT8_C(  92),  INT8_C(  88),  INT8_C(  86), -INT8_C(  76), -INT8_C(  18), -INT8_C(  18),
        -INT8_C(  76),  INT8_C(  95), -INT8_C(  52),  INT8_C(  19),  INT8_C(  43),  INT8_C(  28), -INT8_C(  90), -INT8_C(  25),
         INT8_C(  75),  INT8_C(  97), -INT8_C( 100), -INT8_C(  35), -INT8_C(  30), -INT8_C(  17),  INT8_C( 113), -INT8_C(  78) } },
    { {  INT8_C(  19), -INT8_C( 102),  INT8_C( 126),  INT8_C( 107), -INT8_C(  82), -INT8_C(  41),  INT8_C( 100), -INT8_C(  10),
        -INT8_C(  46),  INT8_C(  47), -INT8_C(  15), -INT8_C(  79), -INT8_C(  16),  INT8_C(  78),  INT8_C( 116), -INT8_C(  91),
         INT8_C(   1),  INT8_C(  79), -INT8_C(  40), -INT8_C( 101), -INT8_C( 105),  INT8_C(  11),  INT8_C( 109), -INT8_C(  94),
         INT8_C(  77),  INT8_C(   9), -INT8_C(  12),  INT8_C(  16), -INT8_C(  12), -INT8_C(  64),  INT8_C( 119),  INT8_C(   7),
         INT8_C(  90), -INT8_C(  11),  INT8_C( 114),  INT8_C(   8), -INT8_C(  51), -INT8_C(  41), -INT8_C(   2), -INT8_C(  97),
         INT8_C(   6), -INT8_C(  17),  INT8_C(  80), -INT8_C(  10),  INT8_C(  61), -INT8_C(  59), -INT8_C( 101),  INT8_C(  62),
         INT8_C(  20),  INT8_C( 116), -INT8_C(  38), -INT8_C(  85),      INT8_MAX,  INT8_C(  71),  INT8_C(  77), -INT8_C(  52),
         INT8_C(  80),  INT8_C(  65), -INT8_C(  36),  INT8_C(  68),  INT8_C(   1),  INT8_C(  83),  INT8_C(  76),  INT8_C(  91) },
      UINT64_C(11219981339617115721),
      {  INT8_C(  81),  INT8_C(   6), -INT8_C( 111), -INT8_C( 114), -INT8_C(  53),  INT8_C(  45), -INT8_C(  51), -INT8_C(  33),
        -INT8_C(  95), -INT8_C(  89), -INT8_C( 117),  INT8_C(  32), -INT8_C(  18), -INT8_C(  40), -INT8_C(  20),  INT8_C(  62),
         INT8_C(  26), -INT8_C(  56), -INT8_C( 126),  INT8_C(  27),  INT8_C(  28), -INT8_C(  50),  INT8_C( 119),  INT8_C( 101),
        -INT8_C( 115), -INT8_C(  38),  INT8_C( 123),  INT8_C(  34),  INT8_C(  60),  INT8_C(  48), -INT8_C(  66), -INT8_C( 115),
         INT8_C(  54),  INT8_C(  79),  INT8_C(  27),  INT8_C(   1),  INT8_C( 124), -INT8_C(  24), -INT8_C(  31),  INT8_C(  29),
        -INT8_C( 113),  INT8_C( 108),  INT8_C(  61),  INT8_C( 125),  INT8_C(  68),  INT8_C(  41), -INT8_C(  69),  INT8_C(  94),
        -INT8_C(  14),  INT8_C(  62),  INT8_C( 122),  INT8_C(  14),  INT8_C(  12), -INT8_C(  15),  INT8_C( 115), -INT8_C( 103),
        -INT8_C(  53), -INT8_C(  18), -INT8_C(  68),  INT8_C(   7),  INT8_C(  30),  INT8_C( 122), -INT8_C( 108),  INT8_C(  85) },
      { -INT8_C(  55), -INT8_C(  80),  INT8_C(  86),  INT8_C(  70), -INT8_C( 104),  INT8_C(  55),  INT8_C(  99),  INT8_C(  40),
        -INT8_C(  93), -INT8_C(  95), -INT8_C(  91), -INT8_C(  24), -INT8_C(  54),  INT8_C(  97),  INT8_C(  70), -INT8_C(  68),
        -INT8_C(  97), -INT8_C(  64), -INT8_C(  54), -INT8_C(  85), -INT8_C(  79),  INT8_C(  61),  INT8_C(  69),  INT8_C( 125),
         INT8_C(  43),  INT8_C(   1), -INT8_C( 124),  INT8_C(  74),  INT8_C( 123),  INT8_C(  25), -INT8_C(  97),  INT8_C(  68),
        -INT8_C(  55), -INT8_C(  11), -INT8_C( 118),  INT8_C(  97),  INT8_C(  45), -INT8_C(  18), -INT8_C( 119), -INT8_C(  48),
        -INT8_C( 113),  INT8_C(  47), -INT8_C(  72),  INT8_C(  89), -INT8_C( 112), -INT8_C(   1),  INT8_C(  22),  INT8_C(  47),
        -INT8_C(  65), -INT8_C(  32), -INT8_C(  38),  INT8_C( 113),  INT8_C(  30),  INT8_C(  31), -INT8_C(  18),  INT8_C(  73),
         INT8_C(  32),  INT8_C( 114), -INT8_C( 109), -INT8_C( 101), -INT8_C( 117),  INT8_C(  50), -INT8_C(  32),  INT8_C(  84) },
      { -INT8_C(  64), -INT8_C( 102),  INT8_C( 126),  INT8_C( 116), -INT8_C(  82), -INT8_C(  41),  INT8_C(  97), -INT8_C(  10),
        -INT8_C(  46), -INT8_C(  97), -INT8_C(  79),  INT8_C(  90),  INT8_C(  22),  INT8_C(  43),  INT8_C( 116),  INT8_C(  76),
        -INT8_C(  12), -INT8_C(  93), -INT8_C(  40), -INT8_C( 101), -INT8_C( 105),  INT8_C(  70),  INT8_C(  73), -INT8_C(  94),
         INT8_C(  77), -INT8_C( 124), -INT8_C( 101),  INT8_C(  16),  INT8_C(   1), -INT8_C(  64),  INT8_C( 119),  INT8_C(   7),
         INT8_C(  77), -INT8_C(  11),  INT8_C(  16),  INT8_C(   8), -INT8_C( 117), -INT8_C(  41), -INT8_C(   2), -INT8_C(  64),
        -INT8_C(  91), -INT8_C(  17),  INT8_C(  80), -INT8_C(  10),  INT8_C(  61), -INT8_C(  17),  INT8_C(  68),  INT8_C(  62),
        -INT8_C(  38),  INT8_C( 116), -INT8_C( 109), -INT8_C(  85), -INT8_C(  16), -INT8_C(  32),  INT8_C(  77),  INT8_C(   9),
        -INT8_C(  24),  INT8_C(  22), -INT8_C(  36), -INT8_C(  10),  INT8_C( 119),  INT8_C(  83),  INT8_C(  76),  INT8_C(  61) } },
    { {  INT8_C(  40),  INT8_C( 106), -INT8_C(  74),  INT8_C(  85),  INT8_C(  88),  INT8_C(  63),  INT8_C(  37), -INT8_C(  25),
         INT8_C( 110), -INT8_C(  34),  INT8_C(  65), -INT8_C(   2), -INT8_C(  35),  INT8_C(  87),  INT8_C(  45), -INT8_C( 100),
         INT8_C(  55),  INT8_C(   8),  INT8_C(  13),  INT8_C(  85),  INT8_C(  39), -INT8_C(   5), -INT8_C(  97),  INT8_C(  72),
         INT8_C( 110),  INT8_C(  50), -INT8_C(  29), -INT8_C(   7),  INT8_C( 101), -INT8_C(  61),  INT8_C(  78), -INT8_C( 115),
         INT8_C(  46),  INT8_C(   4), -INT8_C(  30), -INT8_C( 122),  INT8_C(  67),  INT8_C(   7),  INT8_C( 110), -INT8_C(  78),
        -INT8_C(  27), -INT8_C(  81), -INT8_C(  80), -INT8_C(  62),  INT8_C(   6), -INT8_C(  34),  INT8_C(  95),  INT8_C(  61),
        -INT8_C(  26),  INT8_C( 108), -INT8_C( 109),  INT8_C(  13),  INT8_C( 104),  INT8_C(  50),  INT8_C(  85), -INT8_C(  42),
         INT8_C( 100),  INT8_C(  57), -INT8_C(  49), -INT8_C(  55), -INT8_C(   4),  INT8_C(  29),  INT8_C(  86),  INT8_C(  42) },
      UINT64_C( 2672639265312159777),
      { -INT8_C(  50), -INT8_C(  57), -INT8_C(  24), -INT8_C(  44), -INT8_C(  91),  INT8_C(  71),  INT8_C(  17), -INT8_C( 117),
        -INT8_C(  77), -INT8_C(  92), -INT8_C( 103),  INT8_C(  27), -INT8_C(  42), -INT8_C(  18), -INT8_C(  15),  INT8_C(  59),
         INT8_C(  39), -INT8_C(  63),  INT8_C(   4),  INT8_C(  36), -INT8_C(  34),  INT8_C(  91),  INT8_C(  78),  INT8_C(   0),
        -INT8_C( 109), -INT8_C(   1),  INT8_C( 101), -INT8_C(  45),  INT8_C(  30),  INT8_C( 124), -INT8_C(   7), -INT8_C(  20),
         INT8_C(  67), -INT8_C(  31), -INT8_C(  64), -INT8_C(  23),  INT8_C(  40), -INT8_C(  46),  INT8_C( 116), -INT8_C(  37),
         INT8_C( 118),  INT8_C(  13), -INT8_C(   9),  INT8_C(  77), -INT8_C(   4), -INT8_C(  24), -INT8_C( 120),  INT8_C(  35),
        -INT8_C(  87), -INT8_C( 116),  INT8_C(  71), -INT8_C( 120), -INT8_C(  25), -INT8_C( 106), -INT8_C( 120),  INT8_C( 123),
        -INT8_C( 107), -INT8_C(  19),  INT8_C(  78), -INT8_C(  76),  INT8_C( 105),  INT8_C(  71), -INT8_C(  96), -INT8_C(  84) },
      {  INT8_C(  40),  INT8_C(  97), -INT8_C( 107),  INT8_C(  80),  INT8_C(  51),  INT8_C(  10),  INT8_C(  44), -INT8_C(  87),
         INT8_C(  23),  INT8_C(  35), -INT8_C(  10),  INT8_C(  19),  INT8_C(  11),  INT8_C( 126),  INT8_C(  55), -INT8_C(  75),
         INT8_C(  11),  INT8_C( 126),  INT8_C(  61), -INT8_C(  14),  INT8_C(  20), -INT8_C(  59),  INT8_C( 109), -INT8_C(  86),
        -INT8_C(  78), -INT8_C(  68),  INT8_C(  94),  INT8_C(  27),  INT8_C(   3), -INT8_C(   2), -INT8_C(  57),  INT8_C(  44),
         INT8_C(  95),  INT8_C(  93),  INT8_C( 124), -INT8_C( 110),  INT8_C( 103), -INT8_C(  88),  INT8_C(  60),  INT8_C( 126),
        -INT8_C(  53),  INT8_C(  50), -INT8_C( 110), -INT8_C(  41), -INT8_C(  79), -INT8_C(  55), -INT8_C( 116), -INT8_C(  68),
         INT8_C(  71), -INT8_C(  55), -INT8_C(  82),  INT8_C(  92), -INT8_C( 114),  INT8_C(  28),  INT8_C(   6),  INT8_C(  64),
        -INT8_C(  40),  INT8_C( 100),  INT8_C(  91), -INT8_C(  37),  INT8_C(  98),  INT8_C(  34),  INT8_C(   7), -INT8_C(  62) },
      {  INT8_C(  55),  INT8_C( 106), -INT8_C(  74),  INT8_C(  85),  INT8_C(  88), -INT8_C(  87),  INT8_C(  37), -INT8_C(  25),
         INT8_C( 110), -INT8_C(  34),  INT8_C(  65), -INT8_C(   7),  INT8_C( 109), -INT8_C( 116),  INT8_C(  45), -INT8_C( 100),
        -INT8_C(  78),  INT8_C(   8),  INT8_C(  13),  INT8_C(  85), -INT8_C(  57),  INT8_C(  27), -INT8_C(  97),  INT8_C(  40),
         INT8_C(  85),  INT8_C(  50), -INT8_C(  88), -INT8_C(   7),  INT8_C( 101),  INT8_C(  98),  INT8_C( 100), -INT8_C( 115),
         INT8_C(  46),  INT8_C(   4), -INT8_C(  30), -INT8_C( 122),  INT8_C(  67),  INT8_C(   7), -INT8_C( 114), -INT8_C(  78),
         INT8_C(   6),  INT8_C(  87),  INT8_C(  64),  INT8_C( 126),  INT8_C(  98), -INT8_C(  34),  INT8_C(  95),  INT8_C(  61),
        -INT8_C(  81), -INT8_C(  35), -INT8_C(  87),  INT8_C(  13),  INT8_C( 126),  INT8_C(  50),  INT8_C(  85), -INT8_C(  42),
        -INT8_C(   5),  INT8_C(  57),  INT8_C(  55), -INT8_C(  55), -INT8_C(   4), -INT8_C(  87),  INT8_C(  86),  INT8_C(  42) } },
    { {      INT8_MAX, -INT8_C( 124),  INT8_C(  84), -INT8_C(  26),  INT8_C(  44), -INT8_C( 112),  INT8_C( 101), -INT8_C(   8),
        -INT8_C(  61), -INT8_C(   9), -INT8_C(  49),  INT8_C( 116), -INT8_C(  64),  INT8_C(  91),  INT8_C(  48),  INT8_C(   7),
         INT8_C(  36), -INT8_C(  34),  INT8_C(  99), -INT8_C(  78), -INT8_C(   6),  INT8_C( 105), -INT8_C(  14), -INT8_C(  46),
        -INT8_C(  51),  INT8_C(  77), -INT8_C(  82),  INT8_C(  48),  INT8_C( 111), -INT8_C(  75), -INT8_C(  14), -INT8_C(  17),
         INT8_C(  57),  INT8_C(  70), -INT8_C(  43),  INT8_C( 102), -INT8_C(  41),  INT8_C(  58),  INT8_C(  94), -INT8_C( 102),
         INT8_C(  49),  INT8_C(  45),  INT8_C(  14), -INT8_C(  15), -INT8_C( 120),  INT8_C(  62), -INT8_C(   7), -INT8_C(  84),
         INT8_C(  28),  INT8_C(  92),  INT8_C(  94),  INT8_C(  23), -INT8_C(  58),  INT8_C(  80), -INT8_C(  23), -INT8_C( 109),
        -INT8_C(  99), -INT8_C( 105), -INT8_C(  61),  INT8_C(  12),  INT8_C(  77), -INT8_C(  75), -INT8_C(   5), -INT8_C( 122) },
      UINT64_C( 4426275423435674108),
      {  INT8_C( 119),  INT8_C( 123),  INT8_C(  46), -INT8_C(   1), -INT8_C(  71),  INT8_C(  39), -INT8_C(  85), -INT8_C(  43),
        -INT8_C( 124),  INT8_C(   9), -INT8_C(  20),  INT8_C(  74),  INT8_C(  89), -INT8_C(  42), -INT8_C(  35), -INT8_C(  10),
         INT8_C( 109), -INT8_C(  95),  INT8_C(   3), -INT8_C(  70),  INT8_C(  86), -INT8_C(   2),  INT8_C(  65),  INT8_C(  82),
        -INT8_C(  49),  INT8_C(  45),  INT8_C(  37), -INT8_C(  37),  INT8_C( 120), -INT8_C( 110),  INT8_C(  24), -INT8_C(  17),
         INT8_C(  13),  INT8_C(  70), -INT8_C(  17), -INT8_C(  58),  INT8_C( 110), -INT8_C( 102), -INT8_C( 100), -INT8_C(  14),
        -INT8_C(  92), -INT8_C( 120),  INT8_C(  60), -INT8_C(   3),  INT8_C(  94),  INT8_C(  25), -INT8_C(  12), -INT8_C(  52),
        -INT8_C(  70), -INT8_C(   9), -INT8_C( 122),  INT8_C(  17), -INT8_C(  11), -INT8_C(  57),  INT8_C(  99), -INT8_C(  59),
        -INT8_C(  11), -INT8_C( 119), -INT8_C(  96),  INT8_C( 109),  INT8_C(  27), -INT8_C(  72),  INT8_C(  92),  INT8_C(  41) },
      { -INT8_C(   2),  INT8_C(  75), -INT8_C(  17),  INT8_C( 108), -INT8_C(  26), -INT8_C( 117),  INT8_C(  94), -INT8_C( 118),
         INT8_C(  20), -INT8_C( 102), -INT8_C( 121),  INT8_C( 114), -INT8_C(  76),  INT8_C( 123),  INT8_C(  62),  INT8_C( 110),
         INT8_C( 114), -INT8_C(  59),      INT8_MAX,  INT8_C( 104), -INT8_C( 116), -INT8_C(  29),  INT8_C(  45), -INT8_C( 127),
         INT8_C( 108), -INT8_C(  51), -INT8_C(  18), -INT8_C( 121), -INT8_C( 123),  INT8_C(  75), -INT8_C(  80), -INT8_C( 125),
        -INT8_C( 106), -INT8_C(  96), -INT8_C(  16),  INT8_C( 124),  INT8_C(  43),  INT8_C(  78),  INT8_C(   6),  INT8_C(  63),
        -INT8_C(  23), -INT8_C( 114), -INT8_C(  78), -INT8_C(  99),  INT8_C(   9), -INT8_C(  16),  INT8_C(  11),  INT8_C( 124),
        -INT8_C(  75), -INT8_C( 117), -INT8_C(  28),  INT8_C(  66),  INT8_C( 110),  INT8_C(  17), -INT8_C(  61), -INT8_C(  38),
        -INT8_C(  34), -INT8_C(  78),  INT8_C(  97),  INT8_C(  99), -INT8_C(   3),  INT8_C(  18), -INT8_C(  26), -INT8_C( 109) },
      {      INT8_MAX, -INT8_C( 124), -INT8_C(   7), -INT8_C( 109), -INT8_C( 105), -INT8_C( 102), -INT8_C(  15), -INT8_C(  29),
         INT8_C(  44), -INT8_C(   9), -INT8_C(  49),  INT8_C( 116), -INT8_C(  51),  INT8_C(  91),  INT8_C(  75), -INT8_C(  61),
         INT8_C(  36), -INT8_C(  34), -INT8_C(  26), -INT8_C(  61), -INT8_C(   6), -INT8_C(  26),  INT8_C(  75),      INT8_MAX,
         INT8_C( 110),  INT8_C(  62), -INT8_C(  82),  INT8_C(  48), -INT8_C(  34), -INT8_C(  75), -INT8_C(  51),  INT8_C( 124),
         INT8_C(  91),  INT8_C(  94), -INT8_C(  43),  INT8_C(  94), -INT8_C(  41),  INT8_C(  58),  INT8_C(  94), -INT8_C( 102),
         INT8_C(  49), -INT8_C(  61),  INT8_C(  14),  INT8_C(  18), -INT8_C( 120),  INT8_C(  62),  INT8_C( 110), -INT8_C(  84),
        -INT8_C(  61),  INT8_C(  92),  INT8_C( 101), -INT8_C(  34), -INT8_C(  58), -INT8_C( 118),  INT8_C( 124), -INT8_C( 109),
         INT8_C(  17), -INT8_C( 105),  INT8_C(  57), -INT8_C(  16),  INT8_C(  48), -INT8_C(  99), -INT8_C(   5), -INT8_C( 122) } },
    { { -INT8_C(  78), -INT8_C(  42),  INT8_C(  16), -INT8_C(  35),  INT8_C(  37),  INT8_C(  22),  INT8_C(  29),  INT8_C(  14),
        -INT8_C(  92), -INT8_C(  49), -INT8_C(  85), -INT8_C(  82), -INT8_C(  65), -INT8_C(  74),  INT8_C(  42),  INT8_C( 117),
         INT8_C(  65),  INT8_C(  14), -INT8_C(  73), -INT8_C(  81),  INT8_C(  31),  INT8_C( 122), -INT8_C( 119), -INT8_C(   3),
         INT8_C(  44), -INT8_C(  21),  INT8_C(  96),  INT8_C(  41), -INT8_C(   3),  INT8_C(  70), -INT8_C(  67), -INT8_C(  81),
         INT8_C(  29), -INT8_C(  51), -INT8_C( 116),  INT8_C(  66), -INT8_C(  29), -INT8_C(  87),  INT8_C(  80), -INT8_C( 120),
         INT8_C( 120), -INT8_C(   5),  INT8_C(  54),  INT8_C(  56), -INT8_C(  79),  INT8_C(  96), -INT8_C(  83), -INT8_C(  13),
         INT8_C( 110),  INT8_C( 100), -INT8_C(  94), -INT8_C( 115), -INT8_C(  34),  INT8_C(  44), -INT8_C( 118),  INT8_C(  11),
         INT8_C(  23), -INT8_C(  22),  INT8_C(  52),  INT8_C(  20),  INT8_C(  48), -INT8_C(  15), -INT8_C(  61),  INT8_C(  77) },
      UINT64_C( 8154576338574856126),
      { -INT8_C(  38),  INT8_C(  96), -INT8_C(  87), -INT8_C( 116), -INT8_C(  64),  INT8_C(  86),      INT8_MAX,  INT8_C(  46),
        -INT8_C(  70),  INT8_C(  33), -INT8_C(  69), -INT8_C( 103),  INT8_C(  77),  INT8_C(  69), -INT8_C(  92),  INT8_C( 100),
         INT8_C(  47), -INT8_C(  40),  INT8_C( 120),  INT8_C(  95), -INT8_C(  54),  INT8_C(  59), -INT8_C(  83), -INT8_C( 120),
        -INT8_C( 117),  INT8_C(  60),  INT8_C(  42), -INT8_C( 124),  INT8_C(  28),  INT8_C(  84), -INT8_C(  11), -INT8_C(  10),
        -INT8_C(  76), -INT8_C(  97), -INT8_C( 126),  INT8_C( 116), -INT8_C(  11),  INT8_C(   1), -INT8_C(  94), -INT8_C(  80),
         INT8_C(  35),  INT8_C(  93),  INT8_C(  73),  INT8_C( 112), -INT8_C(  94), -INT8_C(  19), -INT8_C(  43), -INT8_C(  47),
        -INT8_C(  59),  INT8_C(  77),  INT8_C(  49), -INT8_C( 113), -INT8_C( 119), -INT8_C(  34),  INT8_C(  24),  INT8_C(  20),
         INT8_C(  26),  INT8_C(  66), -INT8_C( 104),  INT8_C(  54), -INT8_C( 105), -INT8_C( 115),  INT8_C(  45),  INT8_C(  75) },
      {  INT8_C(  44), -INT8_C(  81), -INT8_C(  64),  INT8_C(  34), -INT8_C(  79),  INT8_C(  98), -INT8_C(  46), -INT8_C(  44),
        -INT8_C(  64),  INT8_C(  27),  INT8_C(  68),  INT8_C(  98),  INT8_C(   8),  INT8_C(  25),  INT8_C(  52), -INT8_C(  51),
         INT8_C( 103),  INT8_C( 101),  INT8_C(  93), -INT8_C(  16),  INT8_C(  67),  INT8_C( 117),  INT8_C(   4),  INT8_C(  93),
        -INT8_C(  73), -INT8_C( 100), -INT8_C( 108),  INT8_C(  78),  INT8_C(  41), -INT8_C(  63), -INT8_C( 102),  INT8_C(  86),
         INT8_C( 112),  INT8_C(  90),  INT8_C( 120),  INT8_C(  33), -INT8_C(  68),  INT8_C(  74), -INT8_C(  11),  INT8_C( 124),
         INT8_C( 101),  INT8_C(  58), -INT8_C(  33),  INT8_C( 109),  INT8_C(  83),  INT8_C(  19),  INT8_C(  58), -INT8_C(  70),
         INT8_C( 120), -INT8_C( 105), -INT8_C(  86), -INT8_C(  69),  INT8_C(  12), -INT8_C(  82),  INT8_C(  24), -INT8_C(  60),
         INT8_C(  74), -INT8_C(  84),  INT8_C(  18),  INT8_C( 116),  INT8_C( 109), -INT8_C(  84), -INT8_C(  54), -INT8_C(  34) },
      { -INT8_C(  78),  INT8_C( 112), -INT8_C(   5), -INT8_C(  65),  INT8_C(  44),  INT8_C(   4),  INT8_C(  29), -INT8_C(  83),
         INT8_C(  52), -INT8_C(  51),  INT8_C(  20), -INT8_C(  21), -INT8_C(  65), -INT8_C(  74), -INT8_C(  29),  INT8_C( 117),
        -INT8_C(  13), -INT8_C(  73),  INT8_C(  74),  INT8_C(  86),  INT8_C(  31),  INT8_C( 122), -INT8_C( 119), -INT8_C(  92),
         INT8_C(  44),  INT8_C(  48),  INT8_C(  96),  INT8_C(  41), -INT8_C(   3),  INT8_C(  67), -INT8_C(  67),  INT8_C(  24),
        -INT8_C(  34), -INT8_C(  51), -INT8_C( 116),  INT8_C(  12), -INT8_C(  82), -INT8_C(  42), -INT8_C( 116),  INT8_C( 110),
         INT8_C(  66), -INT8_C(  63),  INT8_C(  27),  INT8_C( 120), -INT8_C( 116),  INT8_C(  96),  INT8_C( 117),  INT8_C( 101),
         INT8_C( 110),  INT8_C(  25), -INT8_C(  94),  INT8_C( 117), -INT8_C(  34), -INT8_C( 102), -INT8_C( 118),  INT8_C(  11),
         INT8_C(  96), -INT8_C(  22),  INT8_C(  52),  INT8_C(  20), -INT8_C(   3), -INT8_C(  74),  INT8_C(  96),  INT8_C(  77) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_permutex2var_epi8(a, test_vec[i].k, idx, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask_permutex2var_epi8(a, k, idx, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask2_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t idx[64];
    const simde__mmask64 k;
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(   5),      INT8_MIN, -INT8_C(  25),  INT8_C(  34), -INT8_C(   7), -INT8_C( 104),  INT8_C(  19), -INT8_C(  70),
         INT8_C(  61),  INT8_C(  43),  INT8_C(  11),  INT8_C(  24),  INT8_C( 118),  INT8_C(  77), -INT8_C(  57), -INT8_C( 122),
        -INT8_C(  36),  INT8_C(  87),  INT8_C(  24), -INT8_C( 115), -INT8_C(  15), -INT8_C(  25),  INT8_C( 107),  INT8_C(  86),
         INT8_C(   9),  INT8_C(  42), -INT8_C( 104),  INT8_C(  70), -INT8_C(   1), -INT8_C(  20), -INT8_C( 114),  INT8_C(   5),
         INT8_C( 108),  INT8_C( 118),  INT8_C(  39),  INT8_C( 101),  INT8_C(  14),  INT8_C(  58),  INT8_C(  31),  INT8_C(  75),
         INT8_C( 101),  INT8_C(  43),  INT8_C(  99), -INT8_C(  37),  INT8_C( 120),  INT8_C(  43),  INT8_C(  98),  INT8_C(  84),
        -INT8_C( 126),  INT8_C( 122), -INT8_C(  30),  INT8_C( 115),  INT8_C(  97),  INT8_C(  77), -INT8_C(  55),  INT8_C( 106),
         INT8_C( 119),  INT8_C(  97), -INT8_C(  80),  INT8_C( 119),  INT8_C(  77),  INT8_C(  63),  INT8_C( 124), -INT8_C(  70) },
      { -INT8_C(  75), -INT8_C(  93),  INT8_C(  31), -INT8_C(  61), -INT8_C(  35),  INT8_C(  63),  INT8_C(  14),  INT8_C(  66),
         INT8_C( 106),  INT8_C( 114),  INT8_C(  30), -INT8_C(  30), -INT8_C(  99),      INT8_MIN,  INT8_C(  55),  INT8_C(  31),
        -INT8_C(   6),  INT8_C(  25), -INT8_C( 110),  INT8_C(  92),  INT8_C( 102),  INT8_C(  91), -INT8_C(  58), -INT8_C(  35),
        -INT8_C(  68),  INT8_C( 119),  INT8_C(  84),  INT8_C(   9), -INT8_C(  74), -INT8_C(  48), -INT8_C(  61),  INT8_C( 107),
         INT8_C( 115), -INT8_C(  29),  INT8_C(  46),  INT8_C(  80),  INT8_C(  34),  INT8_C(  60), -INT8_C( 109), -INT8_C( 116),
        -INT8_C(  82), -INT8_C(  79),  INT8_C( 110),  INT8_C(  75),  INT8_C(  49), -INT8_C(  91),  INT8_C( 106),  INT8_C(  43),
        -INT8_C(  66), -INT8_C(   4), -INT8_C( 121),  INT8_C(  36),  INT8_C(  87),  INT8_C(  78),  INT8_C(   2),  INT8_C(  19),
        -INT8_C(  59),  INT8_C(  86),  INT8_C(  29),  INT8_C( 123),  INT8_C(  39), -INT8_C(  32), -INT8_C(  26), -INT8_C( 102) },
      UINT64_C(18406632037959800003),
      {  INT8_C(  47), -INT8_C(  32),  INT8_C(  74),  INT8_C(  96), -INT8_C( 123), -INT8_C(  75), -INT8_C( 117),  INT8_C(  68),
        -INT8_C(  79),  INT8_C(  19),  INT8_C( 104),  INT8_C(   9),  INT8_C(  97),  INT8_C( 106),  INT8_C(  28),  INT8_C(  38),
        -INT8_C(  63),  INT8_C(  57), -INT8_C(  95), -INT8_C(  24),  INT8_C(  26), -INT8_C( 121), -INT8_C( 126), -INT8_C(  35),
        -INT8_C( 101),  INT8_C( 109), -INT8_C(  61), -INT8_C(  21), -INT8_C(  21),  INT8_C(  52), -INT8_C(  22),  INT8_C(  26),
         INT8_C(  20),  INT8_C(  53),  INT8_C( 122), -INT8_C( 102), -INT8_C(  22),  INT8_C(   6), -INT8_C(  34), -INT8_C( 101),
         INT8_C(  25),  INT8_C(  70), -INT8_C(  92),  INT8_C( 122), -INT8_C(  79), -INT8_C(  63), -INT8_C(  96),  INT8_C( 114),
        -INT8_C(   6),  INT8_C(  65),  INT8_C(  90),  INT8_C(  20), -INT8_C(  56), -INT8_C(  36), -INT8_C(  14),  INT8_C(  99),
         INT8_C(  74), -INT8_C(  75),  INT8_C(  78),  INT8_C(  53), -INT8_C(  23),  INT8_C(  57),  INT8_C(  80), -INT8_C(   2) },
      {  INT8_C(  77),  INT8_C( 101),  INT8_C(  31), -INT8_C(  61), -INT8_C(  35),  INT8_C(  63), -INT8_C(  57),  INT8_C(  74),
         INT8_C( 106),  INT8_C( 114), -INT8_C( 114), -INT8_C(  30), -INT8_C(  20),      INT8_MIN,  INT8_C(  55),  INT8_C(  31),
         INT8_C(  78),  INT8_C(  42), -INT8_C( 110), -INT8_C(  21),  INT8_C( 102), -INT8_C(  21), -INT8_C( 117),  INT8_C(  52),
         INT8_C(  77),  INT8_C( 119),  INT8_C(  26),  INT8_C(   9), -INT8_C(  74), -INT8_C(  63),  INT8_C(  96),  INT8_C( 122),
         INT8_C( 115), -INT8_C(  29),  INT8_C(  46),  INT8_C(  80),  INT8_C(  39),  INT8_C(  60), -INT8_C( 115), -INT8_C( 116),
        -INT8_C(  82),  INT8_C( 122), -INT8_C(  96),  INT8_C(   9),  INT8_C( 122),  INT8_C(  58), -INT8_C(  92),  INT8_C(  43),
         INT8_C( 124), -INT8_C(   4), -INT8_C( 121),  INT8_C(  36), -INT8_C(  35),  INT8_C(  28), -INT8_C(  25),  INT8_C(  19),
        -INT8_C(  75), -INT8_C( 126), -INT8_C(  20),  INT8_C(  53),  INT8_C(  75),  INT8_C(  20), -INT8_C(  34), -INT8_C( 104) } },
    { {  INT8_C( 110), -INT8_C(  54), -INT8_C( 104),  INT8_C(  88), -INT8_C(  48),  INT8_C( 118), -INT8_C(  13), -INT8_C(  23),
        -INT8_C(  68), -INT8_C( 104),  INT8_C(  99),  INT8_C( 109),  INT8_C(  89),  INT8_C(   3), -INT8_C(  33),  INT8_C(  83),
         INT8_C(  68),  INT8_C(  57),  INT8_C( 104),  INT8_C(  12),  INT8_C(  22),  INT8_C(  90),  INT8_C( 111),  INT8_C(  96),
         INT8_C(  15), -INT8_C(  66), -INT8_C( 107), -INT8_C(   8), -INT8_C(   9), -INT8_C(  27), -INT8_C(  10),  INT8_C( 101),
        -INT8_C(  80), -INT8_C( 114), -INT8_C(  67),      INT8_MIN,  INT8_C(   4), -INT8_C(  80),  INT8_C( 106), -INT8_C(  63),
         INT8_C(  72), -INT8_C(  51),  INT8_C(  46), -INT8_C(  95), -INT8_C(  47),  INT8_C(  14), -INT8_C(  11),  INT8_C(  21),
         INT8_C(  71),  INT8_C(  93),  INT8_C(  34),  INT8_C(  93), -INT8_C(  73), -INT8_C( 111), -INT8_C(  67), -INT8_C(  58),
         INT8_C(  79),  INT8_C(  83), -INT8_C(  66),  INT8_C(  70),  INT8_C(  56), -INT8_C(  75), -INT8_C(  85), -INT8_C(  24) },
      {  INT8_C(  67),  INT8_C( 104),  INT8_C( 105),  INT8_C(  72),  INT8_C(  25), -INT8_C(  45),  INT8_C(   9),  INT8_C(  97),
        -INT8_C(  96),  INT8_C(  55),  INT8_C(   3),  INT8_C( 113),  INT8_C(  69), -INT8_C(   8), -INT8_C( 121), -INT8_C( 115),
         INT8_C(  85), -INT8_C(  87), -INT8_C(  22),  INT8_C(  12),  INT8_C(  58), -INT8_C(  88), -INT8_C(  46), -INT8_C( 118),
        -INT8_C(   5), -INT8_C( 112), -INT8_C(  48),  INT8_C(  51),  INT8_C(  69),  INT8_C( 124),  INT8_C(  28), -INT8_C( 119),
        -INT8_C(  28), -INT8_C( 123), -INT8_C(  47), -INT8_C(   3),  INT8_C(  88), -INT8_C(  38),  INT8_C(  95), -INT8_C(   8),
         INT8_C(  17),  INT8_C(  98),  INT8_C( 106),  INT8_C(  87),  INT8_C(  90), -INT8_C(  15), -INT8_C(  28), -INT8_C(  81),
        -INT8_C( 102), -INT8_C(  50), -INT8_C(  69), -INT8_C(  44),  INT8_C( 118), -INT8_C( 115),  INT8_C(  94),  INT8_C( 113),
         INT8_C(  29),  INT8_C(  47), -INT8_C(  91),  INT8_C(  99), -INT8_C(  85), -INT8_C(  63), -INT8_C(  20), -INT8_C( 113) },
      UINT64_C(12148157180822797638),
      {  INT8_C(  78),  INT8_C(   0), -INT8_C(   1), -INT8_C(  88), -INT8_C(  15), -INT8_C(  29),  INT8_C(  87), -INT8_C( 117),
        -INT8_C(  78),  INT8_C(  18),  INT8_C(  96),  INT8_C(  40), -INT8_C(  97), -INT8_C(  66), -INT8_C( 102), -INT8_C(  68),
        -INT8_C(  19),  INT8_C(  63),  INT8_C(  31), -INT8_C( 104),  INT8_C(   0),  INT8_C(  11),  INT8_C(  40),  INT8_C(  70),
        -INT8_C(  56), -INT8_C(  75), -INT8_C(  28),  INT8_C(  95), -INT8_C(  95),  INT8_C( 122),  INT8_C(   8), -INT8_C(  17),
         INT8_C( 123),  INT8_C(   7), -INT8_C( 105),  INT8_C( 108), -INT8_C(  21), -INT8_C(  18), -INT8_C(   8), -INT8_C(  99),
         INT8_C(   0),  INT8_C(  88), -INT8_C(  59), -INT8_C(  97),  INT8_C(  22),  INT8_C(  95),  INT8_C(  91),  INT8_C(   4),
        -INT8_C(  98),  INT8_C( 123), -INT8_C( 100), -INT8_C(  98), -INT8_C( 122), -INT8_C(  60), -INT8_C(  28),  INT8_C(  79),
         INT8_C( 121), -INT8_C(  56), -INT8_C(  82),  INT8_C(  26),  INT8_C(  67), -INT8_C(  74),  INT8_C(   9), -INT8_C(  66) },
      {  INT8_C(  67),  INT8_C(   0),  INT8_C(  88),  INT8_C(  72),  INT8_C(  25), -INT8_C(  45), -INT8_C( 104),  INT8_C(  97),
        -INT8_C(  80),  INT8_C(  55),  INT8_C(  88),  INT8_C( 123), -INT8_C(  29),  INT8_C( 121), -INT8_C( 121),  INT8_C(   3),
         INT8_C(  11), -INT8_C(  87), -INT8_C(  59),  INT8_C(  89),  INT8_C(  58), -INT8_C(  88), -INT8_C(  46),  INT8_C(  99),
        -INT8_C(   5),  INT8_C(  68), -INT8_C(  19),  INT8_C(  93), -INT8_C(  29),  INT8_C( 124),  INT8_C(  28), -INT8_C( 104),
        -INT8_C(  21),  INT8_C( 118),  INT8_C(  63), -INT8_C(   3), -INT8_C(  56), -INT8_C(  38),  INT8_C(  95),  INT8_C( 121),
         INT8_C(  17),  INT8_C(  98), -INT8_C(  59),  INT8_C(  70),  INT8_C(  90),  INT8_C( 123), -INT8_C(  21),  INT8_C(  21),
        -INT8_C( 102), -INT8_C( 102),  INT8_C(  70), -INT8_C(  44), -INT8_C(  28), -INT8_C( 115),  INT8_C(  94),  INT8_C( 123),
         INT8_C(  29),  INT8_C(  47), -INT8_C(  91),  INT8_C( 108), -INT8_C(  85),  INT8_C(   0), -INT8_C(  20),  INT8_C(  83) } },
    { { -INT8_C(  66), -INT8_C(  96),  INT8_C(  42), -INT8_C(  87), -INT8_C( 114),  INT8_C(  34),  INT8_C(  70), -INT8_C( 114),
         INT8_C( 122),  INT8_C(  11),  INT8_C(  45), -INT8_C( 111),  INT8_C( 107), -INT8_C( 119), -INT8_C( 107),  INT8_C(   9),
         INT8_C(   4),  INT8_C(  49), -INT8_C(  88), -INT8_C( 118), -INT8_C(  10), -INT8_C( 116), -INT8_C(  39),  INT8_C( 111),
         INT8_C(  85), -INT8_C( 120), -INT8_C( 118), -INT8_C( 104),  INT8_C(  62), -INT8_C( 109),  INT8_C(  86), -INT8_C(   4),
         INT8_C(  52),      INT8_MIN, -INT8_C(  91), -INT8_C(  62), -INT8_C(  93), -INT8_C(  21),  INT8_C(  81),  INT8_C(  29),
        -INT8_C(   9),  INT8_C( 126), -INT8_C(  82),  INT8_C(  98),  INT8_C(   7),  INT8_C(  67),  INT8_C( 107),  INT8_C(  11),
         INT8_C( 117),  INT8_C(  19), -INT8_C( 106),  INT8_C( 107), -INT8_C(  96),  INT8_C( 111), -INT8_C(  38), -INT8_C(  11),
        -INT8_C(   9),  INT8_C( 100), -INT8_C( 115),  INT8_C(  54), -INT8_C(   8), -INT8_C(  29),  INT8_C(  50),  INT8_C(  44) },
      {  INT8_C(  99), -INT8_C(  40), -INT8_C(  18),  INT8_C(   6), -INT8_C(  61),  INT8_C(  63),  INT8_C(  36), -INT8_C(  70),
        -INT8_C(  66), -INT8_C(  46),  INT8_C(  28), -INT8_C(  59),  INT8_C(  22), -INT8_C( 120), -INT8_C(  47), -INT8_C( 117),
        -INT8_C( 101),  INT8_C( 103), -INT8_C(  10),  INT8_C(  59), -INT8_C(  42), -INT8_C(  48),  INT8_C(  48), -INT8_C(  50),
         INT8_C(  53), -INT8_C(  67),  INT8_C(   4),  INT8_C(  45), -INT8_C(  96),  INT8_C(  54),  INT8_C(  89),  INT8_C(   4),
         INT8_C(  14),  INT8_C(  71),  INT8_C(  10), -INT8_C(  46), -INT8_C( 121),  INT8_C(  46), -INT8_C( 116),  INT8_C(  69),
         INT8_C(   1), -INT8_C(  87),  INT8_C(  10),  INT8_C(  23),  INT8_C(  49), -INT8_C(  37), -INT8_C(  94), -INT8_C(  52),
         INT8_C(  66), -INT8_C( 104),  INT8_C(   8),  INT8_C(  25),  INT8_C( 104),  INT8_C(  56), -INT8_C(  25), -INT8_C(  99),
        -INT8_C(  10), -INT8_C(  21), -INT8_C(  54), -INT8_C( 106),  INT8_C(  33),  INT8_C(  35), -INT8_C( 102),  INT8_C(  48) },
      UINT64_C(15291848100709311851),
      {  INT8_C(  55),  INT8_C(  65), -INT8_C(  21),  INT8_C( 104),  INT8_C(  29), -INT8_C( 115),  INT8_C(  53),  INT8_C(  95),
         INT8_C(  37),  INT8_C(  61),  INT8_C( 120), -INT8_C( 114),  INT8_C( 117),  INT8_C(  95),  INT8_C(  43),  INT8_C( 107),
         INT8_C(  74), -INT8_C(  10),  INT8_C(   2),  INT8_C( 108),  INT8_C(  25), -INT8_C( 100), -INT8_C( 100), -INT8_C( 124),
         INT8_C(  65), -INT8_C(  98),  INT8_C( 118),  INT8_C(  21),  INT8_C(  44), -INT8_C(  83), -INT8_C(  23),  INT8_C( 100),
        -INT8_C(  17), -INT8_C(  43), -INT8_C(  52),  INT8_C(  12),  INT8_C(  98),  INT8_C(   1),  INT8_C( 107), -INT8_C( 120),
         INT8_C(  62), -INT8_C(  28),  INT8_C(  22), -INT8_C(  76),  INT8_C(  67),  INT8_C(  65),  INT8_C(  31), -INT8_C( 114),
         INT8_C(  55),  INT8_C(  33), -INT8_C(   6),  INT8_C(  81), -INT8_C(  66), -INT8_C( 106), -INT8_C(  43), -INT8_C(   1),
         INT8_C(  52),  INT8_C(  76),  INT8_C(  20),  INT8_C(  96), -INT8_C(   7), -INT8_C(   2), -INT8_C(  60), -INT8_C(  24) },
      {  INT8_C(  12),  INT8_C(  65), -INT8_C(  18),  INT8_C(  70), -INT8_C(  61),  INT8_C(  44), -INT8_C(  93), -INT8_C(  70),
         INT8_C(  50), -INT8_C(  46),  INT8_C(  62), -INT8_C(  59),  INT8_C(  22),  INT8_C( 122), -INT8_C(  47), -INT8_C( 111),
        -INT8_C( 101), -INT8_C( 120), -INT8_C(  10),  INT8_C(  59), -INT8_C(  42), -INT8_C(  48),  INT8_C(  48), -INT8_C(  50),
         INT8_C(  53), -INT8_C(  29),  INT8_C(   4),  INT8_C(  45),  INT8_C(  52), -INT8_C(  38), -INT8_C(  98), -INT8_C( 114),
        -INT8_C( 107),  INT8_C(  95),  INT8_C(  10), -INT8_C(  46), -INT8_C( 114),  INT8_C(  46),  INT8_C( 107), -INT8_C( 115),
         INT8_C(   1),  INT8_C( 126),  INT8_C(  45),  INT8_C( 111),  INT8_C(  49), -INT8_C(  37), -INT8_C(  94),  INT8_C( 117),
        -INT8_C(  21),  INT8_C(  85),  INT8_C( 122),  INT8_C(  25),  INT8_C(  62), -INT8_C(   9), -INT8_C(  25), -INT8_C(  99),
        -INT8_C(  10), -INT8_C(  21),  INT8_C( 120), -INT8_C( 106),      INT8_MIN,  INT8_C(  35), -INT8_C( 118),  INT8_C( 117) } },
    { { -INT8_C(  45), -INT8_C( 111), -INT8_C(  12),  INT8_C(  53), -INT8_C( 110),  INT8_C(  96), -INT8_C(  67), -INT8_C(  47),
         INT8_C(  68), -INT8_C(  45), -INT8_C( 123), -INT8_C( 121),  INT8_C(  21), -INT8_C(  92),  INT8_C(  21),  INT8_C(  76),
        -INT8_C(  58),  INT8_C(  15), -INT8_C(  99), -INT8_C( 124), -INT8_C(  91),  INT8_C( 115), -INT8_C( 125), -INT8_C(  39),
        -INT8_C(  65), -INT8_C( 104),  INT8_C(  58), -INT8_C(  72), -INT8_C( 106), -INT8_C(   2), -INT8_C(  95),  INT8_C( 105),
        -INT8_C( 113), -INT8_C( 107), -INT8_C(  98),  INT8_C(  34), -INT8_C(  11),  INT8_C(  92), -INT8_C(  13),  INT8_C(  57),
         INT8_C(  47),  INT8_C( 120), -INT8_C(  63),  INT8_C(  68),  INT8_C(  28), -INT8_C(  42), -INT8_C( 111), -INT8_C(  30),
        -INT8_C(  26),  INT8_C(  46),  INT8_C( 102), -INT8_C( 117), -INT8_C(  95), -INT8_C(  22),  INT8_C( 101),  INT8_C(  96),
        -INT8_C( 126), -INT8_C(  97),  INT8_C(  25),  INT8_C(  24), -INT8_C(  99), -INT8_C(  70), -INT8_C( 127),  INT8_C(  45) },
      {  INT8_C(  79),  INT8_C(  31),  INT8_C(  79),  INT8_C(  69),  INT8_C( 123),  INT8_C(  66),  INT8_C( 126), -INT8_C(  85),
        -INT8_C(  70),  INT8_C(  63), -INT8_C(  17), -INT8_C(  42),  INT8_C(  22),      INT8_MIN, -INT8_C(  71), -INT8_C(   4),
        -INT8_C(  81),  INT8_C(  31), -INT8_C( 121),  INT8_C(  80),  INT8_C(   9), -INT8_C(  20), -INT8_C(  79), -INT8_C( 117),
        -INT8_C( 117), -INT8_C(  54), -INT8_C(  93),  INT8_C(  41), -INT8_C( 124),  INT8_C(  36),  INT8_C(  86), -INT8_C(  45),
         INT8_C(  68), -INT8_C(  91),  INT8_C(  24), -INT8_C(  65), -INT8_C(  25), -INT8_C( 105),  INT8_C( 106), -INT8_C(  95),
        -INT8_C(  42),  INT8_C(  90),  INT8_C( 119), -INT8_C(  20), -INT8_C(  38),  INT8_C(  48), -INT8_C(  24), -INT8_C( 119),
         INT8_C(  80),  INT8_C( 112), -INT8_C(  38),  INT8_C(  89),  INT8_C(  92), -INT8_C( 117), -INT8_C(  27), -INT8_C(  24),
         INT8_C(  85), -INT8_C( 120),  INT8_C(  17), -INT8_C(  39), -INT8_C(  83),  INT8_C( 103), -INT8_C(  84), -INT8_C(  15) },
      UINT64_C( 3644568084488963340),
      {  INT8_C( 117),  INT8_C(  11),  INT8_C(  31),  INT8_C(  79),  INT8_C(  60),  INT8_C(   7), -INT8_C(  39), -INT8_C( 116),
         INT8_C( 119), -INT8_C(  77), -INT8_C(  27), -INT8_C(  44),  INT8_C(  62), -INT8_C(  54), -INT8_C(  68), -INT8_C( 109),
         INT8_C(  83), -INT8_C(  51),  INT8_C( 108),  INT8_C(   0),  INT8_C(  52),  INT8_C(  24), -INT8_C(  15),  INT8_C(  64),
        -INT8_C(  35), -INT8_C(  95),  INT8_C(  51),  INT8_C(  57), -INT8_C(  68), -INT8_C(  57),  INT8_C( 108),  INT8_C(  49),
        -INT8_C(  46), -INT8_C( 117), -INT8_C( 127),  INT8_C(  14), -INT8_C( 110),  INT8_C(  90), -INT8_C( 102),  INT8_C(  10),
         INT8_C(  13),      INT8_MIN, -INT8_C(  34),  INT8_C(  75),  INT8_C(  74), -INT8_C( 102), -INT8_C(  34), -INT8_C(  99),
         INT8_C( 103),  INT8_C(  74), -INT8_C(  99), -INT8_C( 101),  INT8_C(  98), -INT8_C( 114), -INT8_C(  37),  INT8_C(  64),
         INT8_C(  48),  INT8_C(  14),  INT8_C( 121), -INT8_C(  20), -INT8_C(  43), -INT8_C(  27),  INT8_C(  30), -INT8_C(  89) },
      {  INT8_C(  79),  INT8_C(  31), -INT8_C( 109),  INT8_C(   7),  INT8_C( 123),  INT8_C(  66),  INT8_C( 126), -INT8_C(  85),
         INT8_C(  25),  INT8_C(  63), -INT8_C(  99), -INT8_C(  42),  INT8_C(  22),      INT8_MIN, -INT8_C(  97), -INT8_C(  43),
        -INT8_C(  81),  INT8_C(  31), -INT8_C( 121),  INT8_C(  80), -INT8_C(  45),  INT8_C(  74), -INT8_C(  79), -INT8_C( 121),
        -INT8_C( 121), -INT8_C(  27), -INT8_C(  93),  INT8_C(  41), -INT8_C( 110), -INT8_C(  11), -INT8_C(  15),  INT8_C(   0),
         INT8_C(  68), -INT8_C(  91), -INT8_C(  65),  INT8_C(  45),  INT8_C(  10), -INT8_C( 105), -INT8_C(  34), -INT8_C(  95),
        -INT8_C(  15),  INT8_C(  51),  INT8_C( 119),  INT8_C(  74),  INT8_C(  51),  INT8_C(  48), -INT8_C(  24), -INT8_C( 119),
         INT8_C(  80),  INT8_C( 112),  INT8_C(  51),  INT8_C(  89), -INT8_C(  68), -INT8_C( 117), -INT8_C(  27),  INT8_C(  13),
         INT8_C(  85),  INT8_C(  68),  INT8_C(  17), -INT8_C(  39), -INT8_C(  42),  INT8_C(  10), -INT8_C(  84), -INT8_C(  15) } },
    { {  INT8_C( 112), -INT8_C(  97), -INT8_C(  74),  INT8_C(   3), -INT8_C(   7),  INT8_C(  80),  INT8_C(  13),  INT8_C(   6),
        -INT8_C(  48), -INT8_C(  21),  INT8_C(  81),  INT8_C(  27), -INT8_C( 123),  INT8_C(  47), -INT8_C(  72), -INT8_C(  20),
         INT8_C( 121),  INT8_C(  86), -INT8_C( 121), -INT8_C(  37), -INT8_C(  28),  INT8_C(  98),  INT8_C(  27),  INT8_C(  20),
         INT8_C( 112), -INT8_C( 107),  INT8_C(   1),  INT8_C(  69),  INT8_C( 122),  INT8_C(  31), -INT8_C(  20), -INT8_C(  21),
        -INT8_C(  66), -INT8_C(  94), -INT8_C(  18), -INT8_C(  73), -INT8_C(  13), -INT8_C(   5), -INT8_C(  67), -INT8_C(  61),
        -INT8_C(  26),  INT8_C(  14), -INT8_C(  34),  INT8_C( 107),  INT8_C(  61), -INT8_C( 105),  INT8_C(  87), -INT8_C(  74),
        -INT8_C(  19), -INT8_C(  34), -INT8_C( 111), -INT8_C(  47),  INT8_C(  64), -INT8_C(  83), -INT8_C(  26), -INT8_C(  80),
         INT8_C(  66), -INT8_C(  25), -INT8_C(  11), -INT8_C(  68),  INT8_C(   6), -INT8_C(  31), -INT8_C(  89), -INT8_C(  60) },
      { -INT8_C( 124), -INT8_C( 107),  INT8_C( 123),  INT8_C( 119), -INT8_C( 112),  INT8_C(  56),  INT8_C(  58),  INT8_C( 118),
         INT8_C(  70),  INT8_C(  25), -INT8_C(  31), -INT8_C( 125), -INT8_C(  80),  INT8_C(  56),  INT8_C(  57), -INT8_C(  99),
         INT8_C(  22), -INT8_C(  54),  INT8_C( 110),  INT8_C(  86),  INT8_C( 119),  INT8_C(  84),  INT8_C(   6), -INT8_C(  71),
         INT8_C(  59), -INT8_C(   5),  INT8_C( 118),  INT8_C(  65), -INT8_C(  35),  INT8_C(  29),  INT8_C(   5),  INT8_C(  97),
        -INT8_C(  77),      INT8_MIN, -INT8_C(  40),  INT8_C(  67), -INT8_C(  72),  INT8_C(  18), -INT8_C(  70), -INT8_C(   2),
         INT8_C(  43), -INT8_C( 101), -INT8_C( 127), -INT8_C(  37), -INT8_C(  44), -INT8_C(  70),  INT8_C( 120), -INT8_C(  22),
        -INT8_C( 123), -INT8_C(  25),  INT8_C(  65), -INT8_C(   4),  INT8_C(  59),  INT8_C(  71), -INT8_C(  74),  INT8_C( 119),
         INT8_C(  67),  INT8_C(  44), -INT8_C(  72),  INT8_C(  32),  INT8_C(  73), -INT8_C(  66), -INT8_C( 127), -INT8_C(   4) },
      UINT64_C(10949933410637863230),
      { -INT8_C( 107),  INT8_C( 119),  INT8_C( 114),  INT8_C( 105),  INT8_C(  49), -INT8_C(  21),  INT8_C(  84), -INT8_C(  74),
        -INT8_C(  46), -INT8_C( 107), -INT8_C(  77),  INT8_C(  13), -INT8_C(  36),  INT8_C( 105), -INT8_C( 124),  INT8_C(  31),
        -INT8_C( 107),  INT8_C(  61),  INT8_C(  63), -INT8_C(  34), -INT8_C(   5), -INT8_C(  64), -INT8_C(  37),  INT8_C(  57),
         INT8_C(  25),  INT8_C(  27),  INT8_C(  48), -INT8_C( 123),  INT8_C(  21),  INT8_C(  38),  INT8_C(  28), -INT8_C(  86),
        -INT8_C(  99), -INT8_C( 114),  INT8_C(  20), -INT8_C(  50),  INT8_C( 121),  INT8_C( 104), -INT8_C( 123),  INT8_C(  75),
        -INT8_C(   3),  INT8_C(  56),  INT8_C(  89), -INT8_C(  39), -INT8_C(  95), -INT8_C(  35), -INT8_C(   7),  INT8_C(  54),
         INT8_C(  26),  INT8_C(  56),  INT8_C(  20),  INT8_C(  21), -INT8_C(   7), -INT8_C(  17),  INT8_C(  79),  INT8_C(  18),
         INT8_C(  10),      INT8_MAX, -INT8_C( 105),  INT8_C(  31), -INT8_C(  91), -INT8_C(  77), -INT8_C(  54),  INT8_C(  66) },
      { -INT8_C( 124),  INT8_C(  98),  INT8_C(  31),  INT8_C(  18),  INT8_C( 121),  INT8_C(  66),  INT8_C(  58),  INT8_C( 118),
         INT8_C(  84),  INT8_C(  25), -INT8_C(  31),  INT8_C(   3), -INT8_C(  19),  INT8_C(  56), -INT8_C(  25), -INT8_C(  99),
         INT8_C(  22), -INT8_C(  54),  INT8_C( 110),  INT8_C(  86),  INT8_C( 119),  INT8_C(  84),  INT8_C(  13), -INT8_C(  71),
        -INT8_C(  68),  INT8_C(  31),  INT8_C(  79),  INT8_C(  65),  INT8_C(  38),  INT8_C(  31),  INT8_C(  80), -INT8_C( 114),
        -INT8_C(  47),  INT8_C( 112), -INT8_C(  40),  INT8_C( 105), -INT8_C(  72), -INT8_C( 121), -INT8_C(  11), -INT8_C(   2),
         INT8_C(  43),  INT8_C(  69), -INT8_C( 127), -INT8_C( 123), -INT8_C(   5), -INT8_C(  11),  INT8_C(  10),  INT8_C(  89),
         INT8_C(  80), -INT8_C(  25),  INT8_C( 119), -INT8_C(   4), -INT8_C(  68), -INT8_C(  74), -INT8_C(  26),  INT8_C(  18),
         INT8_C( 105),  INT8_C(  61),  INT8_C(  66),  INT8_C(  32), -INT8_C( 107), -INT8_C(  66), -INT8_C( 127), -INT8_C(  91) } },
    { {  INT8_C(  66), -INT8_C(  34),  INT8_C(  17), -INT8_C(  69),  INT8_C(  70), -INT8_C( 106),  INT8_C(   7),  INT8_C(  67),
        -INT8_C(  50),  INT8_C(  96),  INT8_C(  28),  INT8_C( 111),  INT8_C(  61),  INT8_C(  21), -INT8_C(  91),  INT8_C(  88),
         INT8_C(  78), -INT8_C(  71),  INT8_C( 109),  INT8_C(  71), -INT8_C(  87), -INT8_C(  68),  INT8_C(  89), -INT8_C(  77),
         INT8_C(  60), -INT8_C(  15), -INT8_C(  45), -INT8_C(  31), -INT8_C(  92), -INT8_C(  99),  INT8_C(  36), -INT8_C(  26),
         INT8_C( 123),  INT8_C(  53), -INT8_C(  94), -INT8_C(  63), -INT8_C(  53), -INT8_C(  87),  INT8_C(   4), -INT8_C( 103),
         INT8_C(   9),  INT8_C(  32),  INT8_C(   8),  INT8_C(  70),  INT8_C(  54), -INT8_C(  83), -INT8_C(  98), -INT8_C( 124),
         INT8_C( 102),  INT8_C(  12), -INT8_C(  53),  INT8_C(  15), -INT8_C(  56),  INT8_C(  36), -INT8_C(  61),  INT8_C(   4),
         INT8_C(  21), -INT8_C( 106), -INT8_C(  26), -INT8_C(  70),  INT8_C(  51),  INT8_C(  10), -INT8_C(  96), -INT8_C(  82) },
      {  INT8_C(  63),  INT8_C(  66),  INT8_C( 111),  INT8_C(  10), -INT8_C(  21),  INT8_C( 115), -INT8_C(  93), -INT8_C(  12),
        -INT8_C( 109), -INT8_C(  85),  INT8_C(  59), -INT8_C(  55),  INT8_C(  88), -INT8_C(  39),  INT8_C(  77), -INT8_C(  66),
        -INT8_C(  27),  INT8_C(  24), -INT8_C(  50), -INT8_C(  82),  INT8_C(  61), -INT8_C( 111), -INT8_C(  78),  INT8_C(  82),
         INT8_C(  39), -INT8_C( 104),  INT8_C(  12),  INT8_C(  90), -INT8_C(  94), -INT8_C(  83),  INT8_C(   8), -INT8_C(  31),
        -INT8_C(  17),  INT8_C( 119), -INT8_C(  21), -INT8_C(  37), -INT8_C(  22), -INT8_C( 114), -INT8_C(  49),  INT8_C( 125),
         INT8_C(  57),  INT8_C(  10),  INT8_C(  71), -INT8_C( 111), -INT8_C(  28), -INT8_C( 108),  INT8_C(  80), -INT8_C(  55),
        -INT8_C(  83),  INT8_C(  30),  INT8_C( 119), -INT8_C(  22), -INT8_C(  81),  INT8_C(  42),  INT8_C(  60), -INT8_C(  42),
        -INT8_C(  62),  INT8_C(  73),  INT8_C(  48),  INT8_C( 101), -INT8_C(  10),  INT8_C(  56),  INT8_C(  70), -INT8_C(  27) },
      UINT64_C(18020750115857248943),
      { -INT8_C( 102),  INT8_C(  93), -INT8_C( 117),  INT8_C( 126), -INT8_C(  14), -INT8_C(  37),  INT8_C(  72), -INT8_C(  97),
        -INT8_C(   7), -INT8_C(  65), -INT8_C( 119), -INT8_C(  88), -INT8_C(  23), -INT8_C(  59),  INT8_C( 126), -INT8_C(  84),
         INT8_C(  14), -INT8_C(  82),  INT8_C(  17),  INT8_C(   4), -INT8_C(  26),  INT8_C(  87), -INT8_C(  22), -INT8_C( 107),
        -INT8_C( 119), -INT8_C(  86),  INT8_C(  46),  INT8_C(  74),  INT8_C(  58),  INT8_C(  69),  INT8_C(  68), -INT8_C(  43),
        -INT8_C(  94), -INT8_C(  49),  INT8_C(  83), -INT8_C( 108), -INT8_C(  85), -INT8_C( 101),  INT8_C(  51), -INT8_C(  92),
         INT8_C(  91), -INT8_C(  68),  INT8_C(  77),  INT8_C(  68), -INT8_C( 126), -INT8_C(  53), -INT8_C(  16), -INT8_C( 112),
         INT8_C( 122),  INT8_C(   1), -INT8_C( 107),  INT8_C(  96),  INT8_C(  89),      INT8_MAX, -INT8_C(  10), -INT8_C(  30),
         INT8_C(  41),  INT8_C(  36),  INT8_C(  44),  INT8_C( 100),  INT8_C( 105),  INT8_C( 112),  INT8_C(  57),  INT8_C(  12) },
      { -INT8_C(  82), -INT8_C( 117), -INT8_C( 112),  INT8_C(  28), -INT8_C(  21),  INT8_C(  96), -INT8_C(  93),  INT8_C(  89),
        -INT8_C( 109),  INT8_C(  70),  INT8_C(  59), -INT8_C(  55), -INT8_C( 119), -INT8_C(  86),  INT8_C(  77), -INT8_C(  66),
        -INT8_C(  27),  INT8_C(  24), -INT8_C(  50), -INT8_C(  82),  INT8_C(  61), -INT8_C( 111), -INT8_C(  53),  INT8_C(  17),
        -INT8_C( 103), -INT8_C( 104),  INT8_C(  12),  INT8_C(  46), -INT8_C(  94), -INT8_C(  83),  INT8_C(   8), -INT8_C(  49),
        -INT8_C(  17),  INT8_C( 119), -INT8_C(  21), -INT8_C(  37), -INT8_C(  22), -INT8_C( 114), -INT8_C(  84),  INT8_C( 112),
         INT8_C(  57),  INT8_C(  10),  INT8_C(  71), -INT8_C( 111), -INT8_C(  85), -INT8_C( 108),  INT8_C(  80), -INT8_C(  65),
        -INT8_C(  83),  INT8_C(  36), -INT8_C(  30), -INT8_C(  22), -INT8_C( 124),  INT8_C(  42),  INT8_C(  60), -INT8_C(  42),
        -INT8_C(  62), -INT8_C(  65),  INT8_C(  48), -INT8_C( 101), -INT8_C(  10),  INT8_C(  21),  INT8_C(  72), -INT8_C( 101) } },
    { {  INT8_C(  64), -INT8_C( 116), -INT8_C(  96), -INT8_C(  21),  INT8_C(  40), -INT8_C(  44), -INT8_C( 113), -INT8_C( 125),
        -INT8_C( 112), -INT8_C(  36), -INT8_C(  57),  INT8_C(  18), -INT8_C(  88), -INT8_C(  72), -INT8_C(  93),  INT8_C(  34),
        -INT8_C(  71),  INT8_C(  56), -INT8_C( 126),  INT8_C(  18), -INT8_C(  73),  INT8_C( 120), -INT8_C(  11), -INT8_C(  32),
        -INT8_C(  99),  INT8_C(  33),  INT8_C(  68),  INT8_C(   6), -INT8_C( 110),  INT8_C( 125),  INT8_C(  18), -INT8_C(  46),
         INT8_C(  10), -INT8_C(  77), -INT8_C(  67),  INT8_C(  50), -INT8_C( 121),  INT8_C(  76), -INT8_C(  75),  INT8_C(  23),
         INT8_C(  41),  INT8_C( 124),  INT8_C(  42), -INT8_C(  47),  INT8_C(  52), -INT8_C(  51), -INT8_C(  13), -INT8_C(  18),
         INT8_C(   5),  INT8_C( 117),  INT8_C(   0), -INT8_C(  68), -INT8_C(  18), -INT8_C(  11), -INT8_C( 100), -INT8_C( 117),
         INT8_C(  23), -INT8_C(  31), -INT8_C( 111), -INT8_C(  87),  INT8_C(  94), -INT8_C(  92),  INT8_C( 123),  INT8_C( 104) },
      {  INT8_C(  87),  INT8_C(  56), -INT8_C( 102), -INT8_C(  34), -INT8_C( 124),  INT8_C(  79), -INT8_C(  11), -INT8_C(  83),
        -INT8_C(  52),  INT8_C(  31),  INT8_C( 126),  INT8_C(   0), -INT8_C(  20),  INT8_C( 113), -INT8_C(  18), -INT8_C(  15),
        -INT8_C(  25), -INT8_C(  17), -INT8_C(  83), -INT8_C(  43), -INT8_C(  28),  INT8_C(  74),  INT8_C(  96), -INT8_C(   5),
         INT8_C(  43), -INT8_C(  15), -INT8_C(  92), -INT8_C( 119), -INT8_C( 107),  INT8_C(  31), -INT8_C(  14), -INT8_C(  20),
         INT8_C(  87), -INT8_C( 116), -INT8_C(  54), -INT8_C(  36), -INT8_C(  36), -INT8_C(  64), -INT8_C( 119), -INT8_C(  88),
        -INT8_C(  33),  INT8_C(   8), -INT8_C(  88), -INT8_C(  52),  INT8_C( 121), -INT8_C( 105), -INT8_C(  67),  INT8_C(  96),
        -INT8_C( 122),  INT8_C( 107),  INT8_C(  53),  INT8_C( 106), -INT8_C(  75), -INT8_C( 107),  INT8_C( 102), -INT8_C(  32),
        -INT8_C( 121),  INT8_C(  10),  INT8_C( 105),  INT8_C(  28),  INT8_C(  42),  INT8_C(  91),  INT8_C(   9), -INT8_C( 127) },
      UINT64_C( 8317277233687155688),
      { -INT8_C(  17),  INT8_C(  20),  INT8_C(  63),  INT8_C( 104), -INT8_C(  85), -INT8_C(   4), -INT8_C(  55),  INT8_C(  49),
         INT8_C( 103), -INT8_C(   2), -INT8_C( 100),  INT8_C(  28), -INT8_C( 108),  INT8_C(   2), -INT8_C(   4),  INT8_C(  27),
         INT8_C(  12),  INT8_C( 102),  INT8_C(  55),  INT8_C(  54), -INT8_C(  63),  INT8_C(  64), -INT8_C(  72), -INT8_C(  87),
         INT8_C(  20),  INT8_C(  21),  INT8_C( 109), -INT8_C(  89), -INT8_C(   4), -INT8_C(  39),  INT8_C(  26), -INT8_C(  21),
        -INT8_C(  18),  INT8_C(  89),  INT8_C(  84), -INT8_C( 103),  INT8_C(  86),  INT8_C(  29), -INT8_C(  53), -INT8_C(  67),
         INT8_C(  27),  INT8_C( 103), -INT8_C(  38), -INT8_C(  81),  INT8_C( 105), -INT8_C(  42), -INT8_C(  54),  INT8_C( 117),
         INT8_C(  60),  INT8_C(   2), -INT8_C(  84), -INT8_C(   2),  INT8_C(  66),  INT8_C( 100), -INT8_C(  89),  INT8_C(  86),
         INT8_C( 121),  INT8_C(  21), -INT8_C(   2),  INT8_C( 118), -INT8_C(  18),  INT8_C(  24),  INT8_C(  97), -INT8_C(  36) },
      {  INT8_C(  87),  INT8_C(  56), -INT8_C( 102),  INT8_C(  26), -INT8_C( 124),  INT8_C(  27),  INT8_C( 100), -INT8_C(  51),
        -INT8_C( 108), -INT8_C(  46),  INT8_C( 126),  INT8_C(   0),  INT8_C( 105),  INT8_C( 113), -INT8_C(  54),  INT8_C(   2),
        -INT8_C(  67), -INT8_C(  17), -INT8_C(  51),  INT8_C(  64),  INT8_C(  86),  INT8_C(  74), -INT8_C(  18), -INT8_C(   5),
         INT8_C(  43), -INT8_C(  15), -INT8_C( 121), -INT8_C( 119), -INT8_C( 107),  INT8_C(  31), -INT8_C(  84),  INT8_C( 105),
        -INT8_C(  87), -INT8_C(  88), -INT8_C(  54), -INT8_C(  36), -INT8_C(   4), -INT8_C(  64), -INT8_C( 119),  INT8_C(  41),
        -INT8_C(  21), -INT8_C( 112),  INT8_C(  41), -INT8_C(  52),  INT8_C( 121), -INT8_C(  32), -INT8_C(  92), -INT8_C(  18),
        -INT8_C( 122),  INT8_C( 107), -INT8_C(  11), -INT8_C(  38), -INT8_C(  75),  INT8_C( 120), -INT8_C(  53), -INT8_C(  32),
        -INT8_C( 125), -INT8_C(  57),  INT8_C( 105),  INT8_C(  28),  INT8_C(  42), -INT8_C(  89), -INT8_C(  36), -INT8_C( 127) } },
    { {  INT8_C( 114), -INT8_C(  75),  INT8_C( 118), -INT8_C(  56), -INT8_C(  46),  INT8_C(  65), -INT8_C( 123), -INT8_C(  18),
        -INT8_C(  88),  INT8_C(  95), -INT8_C(  99),  INT8_C(  17),  INT8_C(  54),  INT8_C( 104), -INT8_C( 122),  INT8_C( 114),
         INT8_C( 106),  INT8_C(  50),  INT8_C( 112), -INT8_C(  84), -INT8_C( 106),  INT8_C(  24),  INT8_C(   3),  INT8_C(  16),
         INT8_C(  45),  INT8_C(   1), -INT8_C( 122),  INT8_C(  27),  INT8_C(  25), -INT8_C(  25), -INT8_C(   8), -INT8_C( 117),
        -INT8_C(  99),  INT8_C( 110),  INT8_C(  83),  INT8_C( 111), -INT8_C(  81), -INT8_C(  39),  INT8_C(  93),  INT8_C(  87),
         INT8_C(  56), -INT8_C(   5),  INT8_C( 104),  INT8_C( 110),  INT8_C(  99), -INT8_C(  18), -INT8_C(  31), -INT8_C(  51),
         INT8_C(  33),  INT8_C(  81),  INT8_C( 121), -INT8_C(  73),  INT8_C( 105),  INT8_C( 124), -INT8_C(  57), -INT8_C( 106),
         INT8_C( 125),  INT8_C(  77), -INT8_C(  78), -INT8_C( 105),  INT8_C(  53), -INT8_C(  86),  INT8_C(  34), -INT8_C(  46) },
      {  INT8_C(  24),  INT8_C( 118),  INT8_C(  65), -INT8_C(  57),  INT8_C(  79), -INT8_C(  97),  INT8_C(  30), -INT8_C( 121),
        -INT8_C( 102), -INT8_C( 122), -INT8_C(  10), -INT8_C(   3),  INT8_C( 116), -INT8_C(  41), -INT8_C(  54), -INT8_C( 107),
         INT8_C(  40),  INT8_C(  67),  INT8_C(  77), -INT8_C( 110), -INT8_C(  64),  INT8_C(  20),  INT8_C(  40),  INT8_C(  61),
         INT8_C(  98), -INT8_C(  38), -INT8_C(  44), -INT8_C( 105), -INT8_C( 124), -INT8_C(   9),  INT8_C( 105), -INT8_C( 100),
         INT8_C( 109), -INT8_C(  86),  INT8_C(  99), -INT8_C(  68),  INT8_C(  73), -INT8_C( 127),  INT8_C(  67), -INT8_C(  29),
         INT8_C(   7),  INT8_C(  57), -INT8_C(  32),  INT8_C( 124),  INT8_C(  16), -INT8_C(  86),  INT8_C(  17),  INT8_C(  57),
        -INT8_C(  18),  INT8_C(  94), -INT8_C(  53), -INT8_C(  82),  INT8_C( 115), -INT8_C(  13), -INT8_C(  21), -INT8_C(  43),
        -INT8_C(  50), -INT8_C(  64),  INT8_C( 108),  INT8_C(  82), -INT8_C(  73), -INT8_C(  43), -INT8_C(  17),  INT8_C(  36) },
      UINT64_C(15829066187127411327),
      {  INT8_C(  93), -INT8_C( 115),  INT8_C(  87),  INT8_C( 109),  INT8_C(  55),  INT8_C( 105), -INT8_C(  90),  INT8_C(  37),
        -INT8_C(  57),  INT8_C( 113), -INT8_C(  45),  INT8_C(  58),  INT8_C( 101), -INT8_C(  65),  INT8_C(  15),  INT8_C(  51),
             INT8_MAX,  INT8_C( 123), -INT8_C( 123),  INT8_C(  54),  INT8_C(  80),  INT8_C( 116),  INT8_C(  90), -INT8_C(  48),
        -INT8_C(  57),  INT8_C(  58), -INT8_C( 103), -INT8_C( 101),  INT8_C(  93),  INT8_C(  69),  INT8_C( 118), -INT8_C(  70),
        -INT8_C(  46), -INT8_C(  50),  INT8_C(  40),  INT8_C(  10),  INT8_C(  55), -INT8_C(  50),  INT8_C(  47), -INT8_C(   2),
         INT8_C(  64),  INT8_C(   3),  INT8_C(  57), -INT8_C(  91), -INT8_C(  62),  INT8_C(  72), -INT8_C(  40),  INT8_C(  65),
        -INT8_C(  60),  INT8_C(  93),  INT8_C( 119),  INT8_C(  20), -INT8_C(  46), -INT8_C(  47), -INT8_C(  28), -INT8_C( 103),
         INT8_C(  11),  INT8_C( 125),  INT8_C(  52),  INT8_C( 104), -INT8_C(  61), -INT8_C(  86),  INT8_C(  35), -INT8_C( 107) },
      {  INT8_C(  45), -INT8_C(  28), -INT8_C( 115),  INT8_C(  37),  INT8_C(  51), -INT8_C( 117), -INT8_C(   8), -INT8_C( 121),
        -INT8_C( 102), -INT8_C( 123), -INT8_C(  10), -INT8_C(   3), -INT8_C(  46), -INT8_C(  41), -INT8_C(  45), -INT8_C( 107),
         INT8_C(  40),  INT8_C(  67),  INT8_C(  77), -INT8_C( 110), -INT8_C(  64), -INT8_C( 106),  INT8_C(  56), -INT8_C(  86),
         INT8_C(  40), -INT8_C(  38), -INT8_C(  44),  INT8_C(  16), -INT8_C( 124), -INT8_C(   9),  INT8_C(   3),  INT8_C(  25),
         INT8_C( 109), -INT8_C(  86),  INT8_C(  10), -INT8_C(  68),  INT8_C( 113), -INT8_C( 127),  INT8_C( 109),  INT8_C(  10),
        -INT8_C(  18),  INT8_C(  77), -INT8_C(  32),  INT8_C( 124),  INT8_C(  16),  INT8_C( 104),  INT8_C(  17),  INT8_C(  57),
        -INT8_C(  18),  INT8_C(  94),  INT8_C(  58), -INT8_C(  31),  INT8_C( 115),  INT8_C(  20), -INT8_C(  21),  INT8_C( 116),
         INT8_C(  15),  INT8_C(  93),  INT8_C( 108), -INT8_C( 123), -INT8_C( 106), -INT8_C(  43),  INT8_C(  65), -INT8_C(  81) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask2_permutex2var_epi8(a, idx, test_vec[i].k, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask2_permutex2var_epi8(a, idx, k, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_permutex2var_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t idx[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C( 9543929041240957228),
      { -INT8_C(  56),  INT8_C(  90), -INT8_C(  17), -INT8_C(  59),  INT8_C(  52), -INT8_C( 102), -INT8_C(  59), -INT8_C(  11),
         INT8_C(  59), -INT8_C(  90), -INT8_C(  38), -INT8_C(   2), -INT8_C(  89), -INT8_C(  71), -INT8_C( 100),  INT8_C(  28),
         INT8_C(  76),  INT8_C( 122), -INT8_C(  36),  INT8_C(   7),  INT8_C(   4),  INT8_C(  31),  INT8_C( 102),  INT8_C(  48),
        -INT8_C(  64),  INT8_C(  25), -INT8_C(  40), -INT8_C(  90), -INT8_C(  15),  INT8_C(  74),  INT8_C(  42), -INT8_C(  71),
        -INT8_C(  92),  INT8_C(  25),      INT8_MAX, -INT8_C(  40), -INT8_C(  77),  INT8_C(  68), -INT8_C(  50), -INT8_C(  18),
        -INT8_C(  21), -INT8_C(  88), -INT8_C(  20), -INT8_C( 110),  INT8_C(  98), -INT8_C( 119), -INT8_C(  82), -INT8_C(  82),
         INT8_C(   3), -INT8_C( 118), -INT8_C(  75),  INT8_C(   7), -INT8_C(  86),  INT8_C(  27),  INT8_C(  55),  INT8_C( 106),
         INT8_C(  53),  INT8_C(  15),  INT8_C(  16),  INT8_C(  38),  INT8_C(  89),  INT8_C(  59), -INT8_C(  32), -INT8_C(   3) },
      {  INT8_C(  84),  INT8_C(  95), -INT8_C(  42),  INT8_C(   8), -INT8_C(  93), -INT8_C(  92), -INT8_C(  10), -INT8_C( 114),
         INT8_C(  76), -INT8_C(  29),  INT8_C(  33), -INT8_C(  82),  INT8_C( 108), -INT8_C(  49),  INT8_C(  93),  INT8_C( 111),
         INT8_C(  90),  INT8_C(  18),  INT8_C( 118),  INT8_C(   4),  INT8_C(  46), -INT8_C(  83),  INT8_C( 110),  INT8_C(  99),
        -INT8_C(  68),      INT8_MAX, -INT8_C( 119),  INT8_C(  21), -INT8_C(  70),  INT8_C( 105),  INT8_C(  18),  INT8_C(  14),
        -INT8_C(  56), -INT8_C(  24),  INT8_C(  22),  INT8_C( 108), -INT8_C( 116),  INT8_C(  13), -INT8_C(   6), -INT8_C(  39),
        -INT8_C(  16),  INT8_C(  27), -INT8_C( 121),  INT8_C(  92), -INT8_C(  21), -INT8_C(  28), -INT8_C(  53),  INT8_C(  69),
        -INT8_C(   9),  INT8_C(  65),  INT8_C(  73),  INT8_C(  37), -INT8_C(  18), -INT8_C(  73), -INT8_C( 120), -INT8_C(  86),
         INT8_C(  54),  INT8_C(  17), -INT8_C(  65), -INT8_C(  16),  INT8_C( 123), -INT8_C(  47), -INT8_C(   1),  INT8_C(  67) },
      { -INT8_C(  70),  INT8_C(  21), -INT8_C(  81),  INT8_C(  70),  INT8_C(  34), -INT8_C(  86),  INT8_C(  31),  INT8_C(  18),
        -INT8_C(  59), -INT8_C(  89),  INT8_C( 110), -INT8_C(  80), -INT8_C( 117),  INT8_C(  57), -INT8_C(  11), -INT8_C( 126),
         INT8_C( 122),  INT8_C(  62), -INT8_C(  89),  INT8_C( 104), -INT8_C(  10),  INT8_C(  47),  INT8_C(  18),  INT8_C(  44),
         INT8_C(  65), -INT8_C(  47),  INT8_C(  29), -INT8_C(  68), -INT8_C(  93),  INT8_C(  28), -INT8_C(   1),  INT8_C(  93),
         INT8_C(  49), -INT8_C(  81), -INT8_C(  93),  INT8_C(  84),  INT8_C(  89), -INT8_C(  61),  INT8_C( 102),  INT8_C(  30),
         INT8_C( 106), -INT8_C(  43), -INT8_C(  49), -INT8_C(  11),  INT8_C(  14), -INT8_C(  60),  INT8_C( 120), -INT8_C( 119),
         INT8_C(   3),  INT8_C(  31), -INT8_C(  15), -INT8_C(   7),  INT8_C(  79),  INT8_C(   4),  INT8_C(  37), -INT8_C( 112),
        -INT8_C(  43),  INT8_C(  66),  INT8_C(  76),  INT8_C( 120),  INT8_C(  94),  INT8_C(  75), -INT8_C(  43), -INT8_C( 112) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  18),  INT8_C(  59),  INT8_C(   0), -INT8_C(  77),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 126),  INT8_C(   0), -INT8_C( 119),
         INT8_C(  29), -INT8_C(  36),  INT8_C(   0),  INT8_C(   0), -INT8_C(  82), -INT8_C( 119),  INT8_C(   0),  INT8_C(  84),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  31),  INT8_C(   0), -INT8_C(  43),  INT8_C(   0), -INT8_C( 100),
        -INT8_C(  59),  INT8_C(   0),  INT8_C( 102),  INT8_C(   0),  INT8_C(   0), -INT8_C(  71),  INT8_C(  76), -INT8_C(  47),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  93), -INT8_C(  11),  INT8_C(   0), -INT8_C(  80), -INT8_C(  86),
         INT8_C(   0),  INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C( 120),  INT8_C( 106),  INT8_C(  59),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  70) } },
    { UINT64_C(11993730380607027706),
      {  INT8_C(  31),  INT8_C(  65), -INT8_C( 101),  INT8_C(  46),  INT8_C(   5),  INT8_C(  19), -INT8_C(  73),  INT8_C(   8),
         INT8_C(  51), -INT8_C(  88),  INT8_C(   1), -INT8_C( 126), -INT8_C(  84),  INT8_C(  39),  INT8_C(  18), -INT8_C( 126),
         INT8_C( 105),  INT8_C(  94), -INT8_C(   6), -INT8_C(  56), -INT8_C(  87), -INT8_C(  48),  INT8_C(  88), -INT8_C(  92),
         INT8_C(  73),  INT8_C(  60), -INT8_C(   9), -INT8_C( 123), -INT8_C( 122),  INT8_C( 105),  INT8_C(  43), -INT8_C(  90),
        -INT8_C(  86), -INT8_C(  58), -INT8_C(  44), -INT8_C(  80), -INT8_C(  38), -INT8_C( 117), -INT8_C(  72),  INT8_C(  13),
         INT8_C(  51), -INT8_C(  70), -INT8_C( 113), -INT8_C(  32), -INT8_C(  31), -INT8_C(  95),  INT8_C(  98),  INT8_C(  74),
        -INT8_C(   1),  INT8_C(  92),  INT8_C(  18), -INT8_C(  88),  INT8_C(  44),  INT8_C( 106),  INT8_C(  76),  INT8_C( 117),
        -INT8_C(  90),  INT8_C(  68), -INT8_C(   6),  INT8_C(  45), -INT8_C(  83),  INT8_C(  37), -INT8_C(  45),  INT8_C(  88) },
      { -INT8_C(  20), -INT8_C(  89),  INT8_C(   8), -INT8_C(  58),  INT8_C(  50), -INT8_C(  64), -INT8_C(  45),  INT8_C( 101),
         INT8_C( 122),  INT8_C(  98),  INT8_C(  69),  INT8_C(  91),  INT8_C(   3), -INT8_C(  89), -INT8_C(  90),  INT8_C(   2),
         INT8_C(   4), -INT8_C(  72), -INT8_C(  86),  INT8_C(  48),  INT8_C(  35), -INT8_C(   9), -INT8_C(  90), -INT8_C(  55),
         INT8_C(  59), -INT8_C(  96), -INT8_C(  10), -INT8_C(  24), -INT8_C(  58), -INT8_C(  55),  INT8_C(  64), -INT8_C(  78),
         INT8_C( 112),  INT8_C(  72),  INT8_C( 120), -INT8_C(  94),  INT8_C(   9),  INT8_C(  75),  INT8_C(   8), -INT8_C( 125),
        -INT8_C(  83),  INT8_C(  77), -INT8_C(  33), -INT8_C(  80), -INT8_C(  11), -INT8_C( 123), -INT8_C(  78), -INT8_C(   7),
         INT8_C(  61),  INT8_C(  92),  INT8_C(  41),  INT8_C(  96),  INT8_C(  83), -INT8_C(  49),  INT8_C(  42), -INT8_C( 114),
         INT8_C( 112),  INT8_C(  32),  INT8_C( 119),  INT8_C(  54), -INT8_C(  22), -INT8_C(  73), -INT8_C(  24),  INT8_C(  90) },
      {  INT8_C(   0),  INT8_C(  96), -INT8_C(   3),  INT8_C(   9), -INT8_C(  85),  INT8_C(   5), -INT8_C( 116),  INT8_C(  88),
         INT8_C(  82),  INT8_C( 107),  INT8_C(   8),  INT8_C(  71), -INT8_C(  16), -INT8_C(  70),  INT8_C(  64),  INT8_C(  46),
         INT8_C(  22),  INT8_C( 106), -INT8_C( 114),  INT8_C( 106),  INT8_C(  57), -INT8_C(  72), -INT8_C(   8), -INT8_C(  87),
        -INT8_C(  39),  INT8_C( 111), -INT8_C(  33), -INT8_C(  61),  INT8_C(  39), -INT8_C(  57),  INT8_C(  29),  INT8_C(  39),
         INT8_C(  39),  INT8_C(  26),  INT8_C(  48), -INT8_C(  46),  INT8_C(  31), -INT8_C(  68),  INT8_C(  42),  INT8_C( 114),
         INT8_C(  40),  INT8_C(  50), -INT8_C(  71),  INT8_C(  24), -INT8_C(  20), -INT8_C(   6),  INT8_C(  70),  INT8_C(   3),
         INT8_C( 100), -INT8_C(  43),  INT8_C( 109), -INT8_C(  99), -INT8_C( 115),  INT8_C( 101),  INT8_C(  71),  INT8_C( 102),
        -INT8_C(  43),  INT8_C(  38),  INT8_C(  41), -INT8_C(   4), -INT8_C(  18),  INT8_C(  71),  INT8_C(  35),  INT8_C(  21) },
      {  INT8_C(   0),  INT8_C(  13),  INT8_C(   0), -INT8_C( 116),  INT8_C(  18),  INT8_C(   0),  INT8_C( 106), -INT8_C(  68),
         INT8_C(  41),  INT8_C(   0),  INT8_C(   0), -INT8_C(  61),  INT8_C(  46),  INT8_C(  13), -INT8_C(  72),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C( 102), -INT8_C(  72),  INT8_C( 107),
         INT8_C(  45), -INT8_C(  86),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  43), -INT8_C(  44), -INT8_C(  88),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  70),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(  18),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106),  INT8_C(  46), -INT8_C( 113),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  86),  INT8_C( 102),  INT8_C(   0),  INT8_C(   0),  INT8_C( 117),  INT8_C(   0), -INT8_C(  33) } },
    { UINT64_C( 4031585949240021857),
      {  INT8_C(  69), -INT8_C(  84),  INT8_C(  80),  INT8_C(  49), -INT8_C(  90), -INT8_C( 106),  INT8_C(  52),  INT8_C(  10),
         INT8_C( 107), -INT8_C(  95), -INT8_C(  88), -INT8_C(   7),  INT8_C(   7), -INT8_C(  17),  INT8_C(  95), -INT8_C(  36),
         INT8_C(  21), -INT8_C( 119), -INT8_C(  40),  INT8_C(   3), -INT8_C(  48), -INT8_C(   5),  INT8_C(  25),  INT8_C(  49),
         INT8_C(  78),  INT8_C(   1), -INT8_C(  78),  INT8_C(  93),  INT8_C(  19), -INT8_C(  91), -INT8_C( 107),  INT8_C(  88),
         INT8_C(  82), -INT8_C(  27), -INT8_C( 118), -INT8_C(   8),  INT8_C( 123), -INT8_C(  66),  INT8_C(   3), -INT8_C(  25),
         INT8_C(  96), -INT8_C(  85), -INT8_C(  32),  INT8_C( 103), -INT8_C( 102),  INT8_C(  63),  INT8_C(  67), -INT8_C(  81),
        -INT8_C(  56),  INT8_C(  27), -INT8_C(  77), -INT8_C( 104),  INT8_C(  22), -INT8_C(  52), -INT8_C(  54),  INT8_C( 100),
        -INT8_C(  51),  INT8_C( 124), -INT8_C(  63), -INT8_C(  32),  INT8_C(  34),  INT8_C(  86),  INT8_C(  57),  INT8_C( 116) },
      {  INT8_C(  59), -INT8_C(  61),  INT8_C( 108), -INT8_C(  73), -INT8_C( 127),  INT8_C( 111), -INT8_C(  98), -INT8_C(  31),
         INT8_C(  26),  INT8_C( 126),  INT8_C(  72), -INT8_C(  76), -INT8_C(  67), -INT8_C( 117),  INT8_C( 100), -INT8_C( 122),
        -INT8_C(  90),  INT8_C(  23),  INT8_C(  30), -INT8_C(  68), -INT8_C(  29), -INT8_C(  24),  INT8_C(  32), -INT8_C(  80),
         INT8_C( 101), -INT8_C(  30), -INT8_C( 112), -INT8_C( 121),  INT8_C(  56), -INT8_C(  55), -INT8_C(   5),  INT8_C( 116),
        -INT8_C( 116),  INT8_C( 103),  INT8_C(  43),  INT8_C(  14), -INT8_C(  41), -INT8_C(  55), -INT8_C(  17), -INT8_C(  15),
         INT8_C(  71),  INT8_C(  56), -INT8_C(  90),  INT8_C(   4), -INT8_C(  61),  INT8_C(  10), -INT8_C( 118),  INT8_C( 106),
         INT8_C(  33), -INT8_C(  87),  INT8_C(  38),  INT8_C(   4), -INT8_C( 111),  INT8_C(  71), -INT8_C(  76), -INT8_C(  10),
         INT8_C(  41),  INT8_C(  68),  INT8_C( 125),  INT8_C(  97),  INT8_C(  14),  INT8_C( 120), -INT8_C(  43), -INT8_C( 102) },
      { -INT8_C(  32),  INT8_C(   0), -INT8_C(  88), -INT8_C(  73), -INT8_C(  55), -INT8_C( 104), -INT8_C(  88),  INT8_C(  16),
        -INT8_C(  48),  INT8_C(  78),  INT8_C(  21), -INT8_C( 109),  INT8_C(  88), -INT8_C(  97), -INT8_C(   3),  INT8_C( 121),
         INT8_C(  72),  INT8_C(  36),  INT8_C( 125), -INT8_C(  38),  INT8_C( 107),  INT8_C(  49), -INT8_C(  48), -INT8_C( 108),
         INT8_C( 118),  INT8_C(  78), -INT8_C(  11), -INT8_C( 124), -INT8_C(  58), -INT8_C(  53),  INT8_C(  30), -INT8_C(  90),
        -INT8_C(  53), -INT8_C(  57),  INT8_C(  93), -INT8_C( 107),  INT8_C(  95),  INT8_C(   6), -INT8_C(  91),  INT8_C(  47),
         INT8_C(  84), -INT8_C(  70), -INT8_C(  62), -INT8_C(  83),  INT8_C(  90), -INT8_C(  64),  INT8_C(  38), -INT8_C(  94),
        -INT8_C(  28), -INT8_C(  92),  INT8_C( 124),  INT8_C(  79), -INT8_C(  43),  INT8_C(  77), -INT8_C(  29),  INT8_C(  75),
        -INT8_C( 101), -INT8_C(  40), -INT8_C(  49),  INT8_C(  97), -INT8_C(  93), -INT8_C(  18),  INT8_C(   8),  INT8_C( 111) },
      { -INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  94), -INT8_C( 107),  INT8_C(   0),
        -INT8_C(  78),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(  86),  INT8_C(   0),  INT8_C(  95),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),  INT8_C(  84),  INT8_C(  82), -INT8_C(  56),
         INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  43),
         INT8_C(   7),  INT8_C(  47),  INT8_C( 103),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  51),  INT8_C(   0),  INT8_C(   0), -INT8_C(  73),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  27), -INT8_C(  85),  INT8_C(   0),  INT8_C(   0), -INT8_C( 119),  INT8_C(  16),  INT8_C(  22), -INT8_C(  29),
        -INT8_C(  85), -INT8_C(  55), -INT8_C(  18),  INT8_C(   0),  INT8_C(  95), -INT8_C( 101),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C(13854103156084204981),
      {  INT8_C( 100),  INT8_C(   5),  INT8_C( 109), -INT8_C(  66), -INT8_C(  59), -INT8_C( 109),  INT8_C(  96), -INT8_C(  87),
         INT8_C(  55), -INT8_C(  35), -INT8_C(   8),  INT8_C(  13),  INT8_C(  42), -INT8_C(  37),  INT8_C(  88), -INT8_C(  59),
        -INT8_C(  76),  INT8_C(  40),  INT8_C(  38),  INT8_C(  87),  INT8_C(  22),  INT8_C(  46), -INT8_C(  58), -INT8_C(  53),
        -INT8_C( 108), -INT8_C(  54), -INT8_C(  33), -INT8_C(   1),  INT8_C( 116),  INT8_C(  34), -INT8_C(  65), -INT8_C(  40),
         INT8_C(  39),  INT8_C(  44), -INT8_C( 106), -INT8_C(  19), -INT8_C(  64), -INT8_C(  10), -INT8_C( 106), -INT8_C(   9),
        -INT8_C(  45), -INT8_C( 113),  INT8_C(   4), -INT8_C(   3),  INT8_C( 106),  INT8_C(  93), -INT8_C(  62),  INT8_C(  30),
        -INT8_C( 123), -INT8_C(  23),  INT8_C( 118), -INT8_C( 101),  INT8_C(  23),  INT8_C(  60),  INT8_C( 102), -INT8_C(  85),
         INT8_C(   7),  INT8_C(  69), -INT8_C(  85),  INT8_C( 123),  INT8_C( 103),  INT8_C( 106),  INT8_C(  83), -INT8_C( 114) },
      { -INT8_C( 105), -INT8_C(  23),  INT8_C( 123),  INT8_C(  87), -INT8_C(  33),  INT8_C(  18),  INT8_C(  78), -INT8_C(  77),
        -INT8_C(  95),  INT8_C(  83), -INT8_C(  80),  INT8_C(  11), -INT8_C(  80),  INT8_C( 115),  INT8_C(  42),  INT8_C(  53),
         INT8_C(  92), -INT8_C(  96), -INT8_C(  48),  INT8_C( 115), -INT8_C(  36),  INT8_C(  54),  INT8_C(  31), -INT8_C(  29),
         INT8_C( 123), -INT8_C(  54),  INT8_C(  94), -INT8_C(  30),  INT8_C(  52), -INT8_C(  79),  INT8_C( 112), -INT8_C(  53),
        -INT8_C( 102), -INT8_C(  20),  INT8_C(  34),  INT8_C( 122), -INT8_C(   2),  INT8_C( 113),  INT8_C(  45), -INT8_C(  97),
        -INT8_C(  60), -INT8_C(  35), -INT8_C(  86),  INT8_C( 116),  INT8_C(  80), -INT8_C(  44), -INT8_C(  87), -INT8_C(  84),
         INT8_C( 116),  INT8_C( 121),  INT8_C(  32),  INT8_C(  81), -INT8_C(  81),  INT8_C(  63),  INT8_C(  52),  INT8_C(  42),
         INT8_C(   9), -INT8_C( 109),  INT8_C(  12),  INT8_C(  61),  INT8_C(  68),  INT8_C( 124),  INT8_C(   9), -INT8_C(  33) },
      {  INT8_C( 104),  INT8_C(  43),  INT8_C(  89),  INT8_C( 102), -INT8_C( 100), -INT8_C( 122),  INT8_C(   5),  INT8_C(  96),
         INT8_C(  99), -INT8_C(  80), -INT8_C(  44), -INT8_C(  76), -INT8_C( 124),  INT8_C( 125),  INT8_C(  96), -INT8_C(   7),
        -INT8_C(  10),      INT8_MIN,  INT8_C(  74), -INT8_C(  91), -INT8_C(  65),  INT8_C( 126), -INT8_C(  49), -INT8_C(  56),
         INT8_C(  17), -INT8_C(  37),  INT8_C(   6),  INT8_C(  86),  INT8_C(  88),  INT8_C(  15),  INT8_C(  53), -INT8_C(  64),
         INT8_C(  58), -INT8_C( 114),  INT8_C(  39), -INT8_C(  41),  INT8_C(  20),  INT8_C(  44),  INT8_C(  55),  INT8_C( 119),
        -INT8_C(  36),  INT8_C(  12),  INT8_C(  43),  INT8_C(  97), -INT8_C( 119), -INT8_C( 116),  INT8_C(  90),      INT8_MIN,
         INT8_C(  12), -INT8_C(  92),  INT8_C(  37), -INT8_C(  52),  INT8_C(  34), -INT8_C(  11), -INT8_C( 108),  INT8_C(  52),
        -INT8_C(  48), -INT8_C( 102), -INT8_C( 118),  INT8_C(  40), -INT8_C(  87), -INT8_C(  65), -INT8_C(  23), -INT8_C(  28) },
      { -INT8_C(  53),  INT8_C(   0),  INT8_C(  40),  INT8_C(   0), -INT8_C(  64),  INT8_C(  38),  INT8_C(   0), -INT8_C( 101),
         INT8_C(  44),  INT8_C(   0), -INT8_C( 123),  INT8_C(   0),  INT8_C(   0), -INT8_C(  52),  INT8_C(   4),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  53),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  33), -INT8_C( 119),  INT8_C(   0), -INT8_C( 118),  INT8_C(   0), -INT8_C(  92),  INT8_C(  93),  INT8_C(   0),
        -INT8_C( 100),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C( 106),
         INT8_C(  34), -INT8_C( 102),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  35), -INT8_C(  64) } },
    { UINT64_C( 1862504787069309005),
      { -INT8_C(   2),  INT8_C(   4),  INT8_C( 122), -INT8_C( 120), -INT8_C( 112), -INT8_C(  44),  INT8_C(   8), -INT8_C( 100),
         INT8_C( 120),  INT8_C(  45),  INT8_C( 104), -INT8_C( 102),  INT8_C(  34), -INT8_C(   3), -INT8_C(  50), -INT8_C(  13),
        -INT8_C( 105),  INT8_C(  88),  INT8_C(  27),  INT8_C(  65),  INT8_C(  23),  INT8_C(   4),  INT8_C(  37),  INT8_C( 100),
         INT8_C(  20), -INT8_C(  32), -INT8_C(  59),  INT8_C(  81), -INT8_C(  46), -INT8_C(  98),  INT8_C( 106), -INT8_C(  47),
        -INT8_C(  94), -INT8_C(  28),  INT8_C(  89),  INT8_C(  50), -INT8_C(  72),  INT8_C(  97), -INT8_C(  50),  INT8_C(  48),
        -INT8_C( 114),  INT8_C(  55), -INT8_C(  54), -INT8_C(  79),  INT8_C(  52), -INT8_C( 103), -INT8_C(  92), -INT8_C(  53),
        -INT8_C(  15), -INT8_C(  65),  INT8_C(  12),  INT8_C(   9), -INT8_C(  60),  INT8_C(  49),  INT8_C( 109), -INT8_C(  40),
         INT8_C(  17),  INT8_C(  51),  INT8_C(  41), -INT8_C(  28), -INT8_C(  47), -INT8_C( 109), -INT8_C(  75),  INT8_C( 115) },
      {  INT8_C( 119),  INT8_C(  14), -INT8_C(  91),  INT8_C(  47),  INT8_C( 111),  INT8_C( 115),  INT8_C(  95), -INT8_C(   3),
        -INT8_C(  86),  INT8_C(  42), -INT8_C(  82), -INT8_C(  34), -INT8_C(  61),  INT8_C(  82), -INT8_C(  86), -INT8_C(  76),
         INT8_C(  18), -INT8_C(  74), -INT8_C(  67), -INT8_C(  42), -INT8_C(  24),  INT8_C(  43), -INT8_C(  82), -INT8_C(   7),
         INT8_C(  94), -INT8_C(  40), -INT8_C(  35),  INT8_C(  47),  INT8_C( 107), -INT8_C( 110), -INT8_C(  94), -INT8_C(  29),
        -INT8_C(  96),  INT8_C(  71),  INT8_C(  18),  INT8_C(  15), -INT8_C(  70),  INT8_C( 114),  INT8_C(  13),  INT8_C( 101),
        -INT8_C( 100), -INT8_C(  69),  INT8_C(  67),  INT8_C(  95),  INT8_C(  14), -INT8_C(  19),  INT8_C(  19),  INT8_C(  32),
        -INT8_C(  92), -INT8_C(  47), -INT8_C(  10), -INT8_C( 116), -INT8_C(   4), -INT8_C(  92), -INT8_C( 123),  INT8_C(  90),
         INT8_C( 124),  INT8_C(  99), -INT8_C( 119), -INT8_C(  24), -INT8_C(  11),  INT8_C(  43), -INT8_C(  53), -INT8_C( 106) },
      {  INT8_C( 114), -INT8_C(  35), -INT8_C(  91),  INT8_C(  44),  INT8_C(  79), -INT8_C(  78), -INT8_C( 111), -INT8_C(  21),
         INT8_C( 110), -INT8_C(  43),  INT8_C(  74),  INT8_C( 124), -INT8_C(  62),  INT8_C(  94), -INT8_C( 100),  INT8_C( 102),
         INT8_C(  47), -INT8_C( 110), -INT8_C(  14),  INT8_C(  43),  INT8_C(  54),  INT8_C( 120), -INT8_C( 123), -INT8_C(  77),
        -INT8_C(  37),  INT8_C(  14), -INT8_C( 101), -INT8_C(  48),  INT8_C(  57),  INT8_C( 102),  INT8_C( 102), -INT8_C(  85),
         INT8_C(  67),  INT8_C(  12), -INT8_C(  41), -INT8_C( 109), -INT8_C(  66),  INT8_C( 105),  INT8_C( 126),  INT8_C(  44),
         INT8_C(  62), -INT8_C(  55), -INT8_C(  88),  INT8_C(   0),  INT8_C(  39),  INT8_C(  68),  INT8_C( 103),  INT8_C(  86),
        -INT8_C(  42),  INT8_C(  89), -INT8_C( 127),  INT8_C(  13), -INT8_C(  47),  INT8_C(   6), -INT8_C(  64), -INT8_C(  84),
         INT8_C(  20),  INT8_C(  91),  INT8_C( 125),  INT8_C(  77), -INT8_C(  63), -INT8_C(  29), -INT8_C(   8),  INT8_C(   4) },
      { -INT8_C(  84),  INT8_C(   0),  INT8_C(  97), -INT8_C(  53),  INT8_C(   0),  INT8_C(   0), -INT8_C(  85),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  27),  INT8_C( 109),  INT8_C(   0), -INT8_C( 123),  INT8_C(  62), -INT8_C(  79),  INT8_C(   0),  INT8_C(  91),
         INT8_C( 102),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  27),  INT8_C(  89),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  27), -INT8_C(  13),  INT8_C(  41), -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0), -INT8_C(  50),  INT8_C(  68),  INT8_C(  65), -INT8_C(  94),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34), -INT8_C(  63),  INT8_C(   0), -INT8_C(  44), -INT8_C( 101),
        -INT8_C(  63),  INT8_C(   0),  INT8_C(   0),  INT8_C(  62),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C( 8564182074101583855),
      { -INT8_C(  33), -INT8_C( 125),  INT8_C( 119),  INT8_C(   6), -INT8_C(  57), -INT8_C(  34),  INT8_C(  92), -INT8_C(  98),
         INT8_C(  55), -INT8_C(  35), -INT8_C(  85),  INT8_C(   9), -INT8_C(  29),  INT8_C( 107), -INT8_C(  75), -INT8_C(   9),
        -INT8_C(  58),  INT8_C(  50),  INT8_C(  68), -INT8_C( 121),  INT8_C(  22),  INT8_C(  60), -INT8_C( 117),  INT8_C(   5),
         INT8_C(  11),  INT8_C(  35), -INT8_C(  77),  INT8_C(  68),  INT8_C(  57), -INT8_C( 114), -INT8_C(  70),  INT8_C(  24),
         INT8_C(  17),  INT8_C(  49),  INT8_C(  30), -INT8_C(  40),  INT8_C(  15),  INT8_C( 122),  INT8_C( 118),  INT8_C(  71),
         INT8_C(  87),  INT8_C(  33),  INT8_C(  80),  INT8_C(  58), -INT8_C( 116),  INT8_C(   5),  INT8_C(  49),  INT8_C(  82),
         INT8_C(  56),  INT8_C( 117), -INT8_C(  39),  INT8_C(  78), -INT8_C(  79),  INT8_C( 101),  INT8_C(  83), -INT8_C(  68),
        -INT8_C( 120),  INT8_C(   7),  INT8_C(   0), -INT8_C(  63), -INT8_C( 107), -INT8_C(  69), -INT8_C(  39), -INT8_C(  90) },
      { -INT8_C(  20), -INT8_C(   9),  INT8_C( 126), -INT8_C(   4),  INT8_C( 113), -INT8_C(  11),  INT8_C(  67), -INT8_C(  56),
         INT8_C(  22), -INT8_C( 109),  INT8_C(   2), -INT8_C(  93), -INT8_C( 104),  INT8_C(  51), -INT8_C(  11), -INT8_C(  48),
        -INT8_C(  88), -INT8_C(  49),  INT8_C(  30),  INT8_C(  89),  INT8_C(  52),  INT8_C( 114),  INT8_C(  21), -INT8_C(  68),
         INT8_C( 121),  INT8_C(  22),  INT8_C( 125),  INT8_C(  14), -INT8_C(  47),  INT8_C(  86), -INT8_C(  76), -INT8_C(  67),
         INT8_C(  77),  INT8_C(  50), -INT8_C(  71), -INT8_C(  66),  INT8_C(  39), -INT8_C(   4), -INT8_C( 122),  INT8_C(  62),
        -INT8_C( 113), -INT8_C( 120), -INT8_C(  31),  INT8_C(  40), -INT8_C(  69), -INT8_C(  42), -INT8_C(   8),  INT8_C(  99),
        -INT8_C(  91),  INT8_C(  23), -INT8_C(  68), -INT8_C(  39), -INT8_C( 119), -INT8_C(  47), -INT8_C( 107),  INT8_C(   2),
        -INT8_C(  25),  INT8_C(  18),  INT8_C(  16), -INT8_C(  72),  INT8_C( 104), -INT8_C(  60),  INT8_C( 118), -INT8_C(  75) },
      { -INT8_C(  10),  INT8_C(  47),  INT8_C( 115),  INT8_C(  30),  INT8_C(  44), -INT8_C(   7),  INT8_C(  92), -INT8_C(  69),
        -INT8_C( 127),  INT8_C(  61), -INT8_C(  29),  INT8_C(  60),  INT8_C(  19), -INT8_C(  36), -INT8_C(  97), -INT8_C(  71),
        -INT8_C(  13),  INT8_C(  91), -INT8_C( 110),  INT8_C( 124),  INT8_C(  45),  INT8_C(  40),  INT8_C( 126),  INT8_C(  20),
         INT8_C(  58), -INT8_C( 114), -INT8_C(  51), -INT8_C(  93),  INT8_C(  82),  INT8_C(  67),  INT8_C(  88),  INT8_C(  72),
         INT8_C( 114), -INT8_C(  52),  INT8_C( 102), -INT8_C(  98), -INT8_C(  59), -INT8_C(  62),  INT8_C(  90),  INT8_C(  71),
        -INT8_C(   1),  INT8_C(  61), -INT8_C( 125),  INT8_C(  19),  INT8_C(  25),  INT8_C(  35), -INT8_C(  52),  INT8_C(  12),
         INT8_C( 126),  INT8_C(  94), -INT8_C( 120), -INT8_C(  85), -INT8_C( 122),  INT8_C(   6), -INT8_C(  64), -INT8_C(  63),
        -INT8_C( 108), -INT8_C( 115),  INT8_C( 100), -INT8_C(  26), -INT8_C(  48), -INT8_C(  68),  INT8_C(  47),  INT8_C(  66) },
      {  INT8_C(  25), -INT8_C(  63),  INT8_C(  47), -INT8_C(  48),  INT8_C(   0),  INT8_C(   6),  INT8_C(  30), -INT8_C( 127),
        -INT8_C( 117), -INT8_C( 121),  INT8_C( 119), -INT8_C(  40),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6), -INT8_C(  13),
         INT8_C(  87), -INT8_C(  71), -INT8_C(  70),  INT8_C(   0), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0), -INT8_C( 107),
         INT8_C(   0), -INT8_C( 117), -INT8_C(  68), -INT8_C(  75),  INT8_C(   0),  INT8_C( 126),  INT8_C(   0), -INT8_C(  69),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  39),  INT8_C(  71), -INT8_C(  48),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  55), -INT8_C(  52),  INT8_C(   0), -INT8_C(  63),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   0), -INT8_C( 114), -INT8_C(  35),  INT8_C(   0),  INT8_C(  60),  INT8_C( 119),
         INT8_C(   0),  INT8_C(  68), -INT8_C(  58),  INT8_C(   0), -INT8_C(   1),  INT8_C(  44), -INT8_C(  64),  INT8_C(   0) } },
    { UINT64_C( 6311015703296185736),
      {  INT8_C( 120),  INT8_C(  24),  INT8_C( 106), -INT8_C( 110),  INT8_C(  59),  INT8_C(  54), -INT8_C(  98), -INT8_C(  70),
        -INT8_C( 107),  INT8_C(  39),  INT8_C( 101),  INT8_C(  27),  INT8_C(  45),  INT8_C(  37), -INT8_C(  36), -INT8_C(  62),
        -INT8_C(  78),  INT8_C(  64), -INT8_C(  88), -INT8_C( 126), -INT8_C(   3), -INT8_C(  41), -INT8_C(  59), -INT8_C( 123),
         INT8_C( 109), -INT8_C(  90), -INT8_C(  45), -INT8_C(  59), -INT8_C(  31),  INT8_C( 104),  INT8_C(  28),  INT8_C(  89),
        -INT8_C( 127), -INT8_C( 121), -INT8_C(  21), -INT8_C(  68), -INT8_C(  67), -INT8_C( 118),  INT8_C( 118),  INT8_C(  82),
        -INT8_C(  79), -INT8_C(  36),  INT8_C( 110), -INT8_C(  34),  INT8_C(   1),  INT8_C(  74), -INT8_C(  96), -INT8_C(  76),
        -INT8_C( 117),  INT8_C(  73),  INT8_C(  54), -INT8_C( 120),  INT8_C(  32), -INT8_C(   5),  INT8_C(  13), -INT8_C( 115),
        -INT8_C(  95), -INT8_C(  31),  INT8_C(  82), -INT8_C( 126),  INT8_C(  73),  INT8_C( 111), -INT8_C(  36), -INT8_C(  54) },
      { -INT8_C(  10), -INT8_C(  57), -INT8_C( 121), -INT8_C(  77),  INT8_C(  81), -INT8_C(   3),  INT8_C(   6),  INT8_C(   2),
        -INT8_C(  39),  INT8_C( 116), -INT8_C(  31), -INT8_C(  37), -INT8_C(  66), -INT8_C( 127), -INT8_C( 113),  INT8_C(  73),
        -INT8_C(  54), -INT8_C(  59), -INT8_C(  47), -INT8_C(  21), -INT8_C(  63), -INT8_C(  33),  INT8_C( 120),  INT8_C(  98),
        -INT8_C(  64), -INT8_C(  53), -INT8_C(  27),  INT8_C(   9),  INT8_C(  58), -INT8_C(  63), -INT8_C(  44),  INT8_C(  48),
        -INT8_C( 120),  INT8_C(  91), -INT8_C(  29), -INT8_C(  38),  INT8_C(  88), -INT8_C(  23), -INT8_C(  36),  INT8_C(  50),
         INT8_C(  93), -INT8_C(  67),  INT8_C(  13),  INT8_C(  28),  INT8_C(  63), -INT8_C( 100),  INT8_C( 101),  INT8_C(   9),
         INT8_C(  97),  INT8_C(  55), -INT8_C(  12),  INT8_C(  34),  INT8_C(  22),  INT8_C( 109), -INT8_C( 123), -INT8_C(  42),
         INT8_C(  56),  INT8_C( 106), -INT8_C(  33),  INT8_C( 114),  INT8_C(  43), -INT8_C(  77), -INT8_C(  94), -INT8_C(  77) },
      {  INT8_C(  14), -INT8_C( 123), -INT8_C( 115),  INT8_C( 103),  INT8_C( 111),  INT8_C( 106), -INT8_C( 103), -INT8_C(  52),
         INT8_C(  39), -INT8_C(  90), -INT8_C(  24),  INT8_C( 102),  INT8_C(  66),  INT8_C(  78),  INT8_C( 112), -INT8_C(  93),
        -INT8_C( 123),  INT8_C( 100), -INT8_C(  58), -INT8_C( 101), -INT8_C(  47),  INT8_C(  75),  INT8_C( 113),  INT8_C(   9),
        -INT8_C(  75),  INT8_C(  80),  INT8_C( 123), -INT8_C(  32),  INT8_C(   4),  INT8_C(  29), -INT8_C( 109),  INT8_C(  18),
        -INT8_C(  93),  INT8_C(  33),  INT8_C( 121),  INT8_C(  18), -INT8_C( 117),  INT8_C(  18), -INT8_C(  34), -INT8_C(  78),
        -INT8_C(  72), -INT8_C(  57),  INT8_C(  25), -INT8_C(   6),  INT8_C(  21), -INT8_C( 119), -INT8_C(  98), -INT8_C( 102),
        -INT8_C(  19),  INT8_C( 100),  INT8_C(  53), -INT8_C(  65), -INT8_C(  81), -INT8_C(  90), -INT8_C(  56),  INT8_C( 100),
        -INT8_C(  10),  INT8_C(  68),  INT8_C(  68), -INT8_C(   6),  INT8_C(  97), -INT8_C(  41),  INT8_C(  13),  INT8_C(   4) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106),
         INT8_C(  80),  INT8_C(   0),  INT8_C(  33),  INT8_C(   0), -INT8_C(  36),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90),
        -INT8_C(  24),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  18), -INT8_C(  10),  INT8_C( 121),
         INT8_C(   0),  INT8_C( 102),  INT8_C(  18),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0), -INT8_C(  47),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 123), -INT8_C(  75),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),
         INT8_C(  29),  INT8_C( 111),  INT8_C(   0), -INT8_C(  31), -INT8_C(  54), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  33),  INT8_C(   0), -INT8_C(  81),  INT8_C(   0), -INT8_C(  59),  INT8_C(   0),  INT8_C(   0),  INT8_C( 113),
        -INT8_C(  95),  INT8_C(  25),  INT8_C(  18),  INT8_C(   0), -INT8_C(  34),  INT8_C(   0), -INT8_C(  21),  INT8_C(   0) } },
    { UINT64_C( 5852134805492631288),
      { -INT8_C(  68),  INT8_C(  79),  INT8_C(  76), -INT8_C(  47), -INT8_C(  40), -INT8_C(  22),  INT8_C( 107), -INT8_C(  59),
         INT8_C(  78), -INT8_C(  96), -INT8_C( 124), -INT8_C(   3),  INT8_C(  70),  INT8_C(  77),  INT8_C(  97),  INT8_C(  60),
        -INT8_C( 111), -INT8_C(  91),  INT8_C(  55), -INT8_C(  14),  INT8_C( 124),  INT8_C(  68), -INT8_C(   9),  INT8_C( 117),
        -INT8_C(  54),  INT8_C(  13), -INT8_C(   8),  INT8_C(  99),  INT8_C(   2),  INT8_C(  46), -INT8_C(  75), -INT8_C(  66),
         INT8_C( 125),  INT8_C(   1), -INT8_C( 113),  INT8_C(  85), -INT8_C(  21), -INT8_C(   6),  INT8_C(  27),  INT8_C(  57),
        -INT8_C( 102), -INT8_C(  97),  INT8_C(  54), -INT8_C(  32), -INT8_C(  20), -INT8_C( 105),  INT8_C(  29),  INT8_C( 125),
         INT8_C(  60),  INT8_C(  84),  INT8_C( 112), -INT8_C(  72), -INT8_C( 104),  INT8_C( 103),  INT8_C(  45),  INT8_C(  98),
         INT8_C( 116),  INT8_C(  38), -INT8_C(  58),  INT8_C( 119),  INT8_C(  84),  INT8_C( 123),  INT8_C(  53), -INT8_C(  46) },
      {  INT8_C( 124), -INT8_C(  59),  INT8_C(  39),  INT8_C( 103), -INT8_C(  65),  INT8_C(  66), -INT8_C(  96),  INT8_C(  90),
        -INT8_C(  30), -INT8_C(  42),  INT8_C(  58), -INT8_C(  50),  INT8_C( 109),  INT8_C(  87),  INT8_C(  76), -INT8_C(  87),
        -INT8_C(  85), -INT8_C(  68),  INT8_C(  97),  INT8_C(  67),  INT8_C(  35), -INT8_C( 113), -INT8_C(  90), -INT8_C( 105),
        -INT8_C(  75),  INT8_C( 108),  INT8_C(  14),  INT8_C(   9), -INT8_C(  25),  INT8_C(  68), -INT8_C(  37),  INT8_C(  99),
         INT8_C(   9),  INT8_C(   3), -INT8_C(  54), -INT8_C(  56),  INT8_C(  69),  INT8_C( 106),  INT8_C(  34),  INT8_C(  39),
         INT8_C(  64),  INT8_C(  93), -INT8_C(  10), -INT8_C(  83), -INT8_C(  76),  INT8_C(  66),  INT8_C(  86),  INT8_C(  96),
        -INT8_C(   2), -INT8_C(  73), -INT8_C(  93),  INT8_C(  33),  INT8_C(  70),  INT8_C(  73), -INT8_C(  72), -INT8_C(   5),
        -INT8_C(  75), -INT8_C(  57),  INT8_C(   5), -INT8_C( 100),  INT8_C(  11), -INT8_C(  32), -INT8_C(   1),  INT8_C(  20) },
      { -INT8_C(  29), -INT8_C(  55), -INT8_C(  36),  INT8_C(  41),  INT8_C(  51), -INT8_C(   1),  INT8_C(  80),  INT8_C( 115),
         INT8_C(  92),  INT8_C(  70),  INT8_C(  32),  INT8_C(  16), -INT8_C( 120),  INT8_C( 118),  INT8_C( 112), -INT8_C( 122),
         INT8_C(  46),  INT8_C(  20), -INT8_C(  89),  INT8_C( 116),  INT8_C(  93),  INT8_C(  96),  INT8_C( 112),  INT8_C(  19),
         INT8_C(  39),  INT8_C( 117), -INT8_C(  81),  INT8_C(  50),  INT8_C(  85), -INT8_C(  81),  INT8_C(  70),  INT8_C(  57),
         INT8_C( 120),  INT8_C(  34),  INT8_C(  98), -INT8_C(  84),  INT8_C(  33), -INT8_C(  78),  INT8_C(  31),  INT8_C( 125),
        -INT8_C(   7),  INT8_C(  64), -INT8_C( 114), -INT8_C( 127), -INT8_C(  74), -INT8_C(   2),  INT8_C(   8), -INT8_C(  28),
         INT8_C(  18), -INT8_C(  81),  INT8_C(  89),  INT8_C( 112),  INT8_C(  15), -INT8_C(  55), -INT8_C( 125),  INT8_C(  54),
         INT8_C(  62),  INT8_C(  50),  INT8_C( 104), -INT8_C( 109), -INT8_C(  31), -INT8_C(  82), -INT8_C(  52),  INT8_C(  90) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 125), -INT8_C(  46), -INT8_C(  36),  INT8_C( 125), -INT8_C(  81),
         INT8_C(   0),  INT8_C( 112), -INT8_C(  58),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  97),
         INT8_C(   0),  INT8_C(  84),  INT8_C(  34),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 103), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),
        -INT8_C(  96),  INT8_C(   0),  INT8_C(   0),  INT8_C(  92), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(  57),
        -INT8_C(  29),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0), -INT8_C( 104), -INT8_C(  36),  INT8_C( 112),  INT8_C( 120),
         INT8_C(   0),  INT8_C(  98),  INT8_C(  85),  INT8_C(   0),  INT8_C(  80),  INT8_C(  70),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 103),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(  90),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i idx = simde_mm512_loadu_epi8(test_vec[i].idx);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_permutex2var_epi8(test_vec[i].k, a, idx, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i idx = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_maskz_permutex2var_epi8(k, a, idx, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d a;
    simde__m512i idx;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  799.30), SIMDE_FLOAT64_C( -576.01),
                         SIMDE_FLOAT64_C(  439.15), SIMDE_FLOAT64_C(  -28.15),
                         SIMDE_FLOAT64_C(  481.25), SIMDE_FLOAT64_C( -784.26),
                         SIMDE_FLOAT64_C(  549.03), SIMDE_FLOAT64_C(  582.53)),
      simde_mm512_set_epi64(INT64_C(-8115609027568940125), INT64_C( 3504612124823893047),
                            INT64_C(-7514888466798804666), INT64_C( 9113506312589344178),
                            INT64_C(-5948029684411535130), INT64_C(-4862378680423071053),
                            INT64_C( 7355766231574189317), INT64_C( -310150959079746096)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -563.83), SIMDE_FLOAT64_C(  938.85),
                         SIMDE_FLOAT64_C( -465.05), SIMDE_FLOAT64_C( -104.57),
                         SIMDE_FLOAT64_C( -431.26), SIMDE_FLOAT64_C(  -57.75),
                         SIMDE_FLOAT64_C(  438.04), SIMDE_FLOAT64_C(  729.46)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  481.25), SIMDE_FLOAT64_C(  799.30),
                         SIMDE_FLOAT64_C( -576.01), SIMDE_FLOAT64_C( -784.26),
                         SIMDE_FLOAT64_C( -576.01), SIMDE_FLOAT64_C(  481.25),
                         SIMDE_FLOAT64_C(  439.15), SIMDE_FLOAT64_C(  582.53)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -435.27), SIMDE_FLOAT64_C(  298.40),
                         SIMDE_FLOAT64_C(  -94.60), SIMDE_FLOAT64_C(  260.50),
                         SIMDE_FLOAT64_C(  -69.45), SIMDE_FLOAT64_C(   95.61),
                         SIMDE_FLOAT64_C( -688.01), SIMDE_FLOAT64_C(  931.17)),
      simde_mm512_set_epi64(INT64_C(-3094219001013742557), INT64_C(-3379016320921474793),
                            INT64_C( 7772273849745001049), INT64_C(-4229480058937372017),
                            INT64_C( 8318730560275653847), INT64_C(-2664412856586094061),
                            INT64_C( 2083707536546841162), INT64_C( 5404230241318444880)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  193.01), SIMDE_FLOAT64_C(  -84.06),
                         SIMDE_FLOAT64_C(  208.07), SIMDE_FLOAT64_C(  834.28),
                         SIMDE_FLOAT64_C( -859.51), SIMDE_FLOAT64_C(   40.36),
                         SIMDE_FLOAT64_C( -743.10), SIMDE_FLOAT64_C(  442.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -69.45), SIMDE_FLOAT64_C( -435.27),
                         SIMDE_FLOAT64_C( -743.10), SIMDE_FLOAT64_C(  193.01),
                         SIMDE_FLOAT64_C( -435.27), SIMDE_FLOAT64_C(  -69.45),
                         SIMDE_FLOAT64_C(   40.36), SIMDE_FLOAT64_C(  931.17)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -832.50), SIMDE_FLOAT64_C(  438.46),
                         SIMDE_FLOAT64_C(  336.35), SIMDE_FLOAT64_C(   99.21),
                         SIMDE_FLOAT64_C(  -38.88), SIMDE_FLOAT64_C(  218.73),
                         SIMDE_FLOAT64_C( -966.90), SIMDE_FLOAT64_C( -737.78)),
      simde_mm512_set_epi64(INT64_C( 7563354526679147255), INT64_C(-6952412028107066884),
                            INT64_C(-3077616107881632928), INT64_C(-2220298267656761827),
                            INT64_C( 2522518958303333112), INT64_C(-1668307566098600867),
                            INT64_C( 8306832211054389426), INT64_C(-4135341282024622606)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  141.08), SIMDE_FLOAT64_C( -990.15),
                         SIMDE_FLOAT64_C( -887.47), SIMDE_FLOAT64_C( -396.24),
                         SIMDE_FLOAT64_C(   -2.60), SIMDE_FLOAT64_C(  165.88),
                         SIMDE_FLOAT64_C(  375.27), SIMDE_FLOAT64_C( -512.98)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -832.50), SIMDE_FLOAT64_C( -396.24),
                         SIMDE_FLOAT64_C( -737.78), SIMDE_FLOAT64_C( -887.47),
                         SIMDE_FLOAT64_C( -512.98), SIMDE_FLOAT64_C( -887.47),
                         SIMDE_FLOAT64_C(  218.73), SIMDE_FLOAT64_C(  218.73)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -211.73), SIMDE_FLOAT64_C(  908.31),
                         SIMDE_FLOAT64_C( -144.11), SIMDE_FLOAT64_C( -343.92),
                         SIMDE_FLOAT64_C(  961.65), SIMDE_FLOAT64_C(  754.42),
                         SIMDE_FLOAT64_C( -432.97), SIMDE_FLOAT64_C(  164.52)),
      simde_mm512_set_epi64(INT64_C(  135432210503006619), INT64_C(-7059566968128636366),
                            INT64_C(-1295026765047609725), INT64_C( 5447800525707046939),
                            INT64_C( 1419500527032411112), INT64_C( 5424087511148175828),
                            INT64_C(-4780701435803039630), INT64_C( 6069825193561024149)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  254.48), SIMDE_FLOAT64_C(  755.70),
                         SIMDE_FLOAT64_C( -363.93), SIMDE_FLOAT64_C(  789.10),
                         SIMDE_FLOAT64_C(  344.74), SIMDE_FLOAT64_C(  652.93),
                         SIMDE_FLOAT64_C(  184.91), SIMDE_FLOAT64_C( -455.33)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  344.74), SIMDE_FLOAT64_C(  754.42),
                         SIMDE_FLOAT64_C(  961.65), SIMDE_FLOAT64_C(  344.74),
                         SIMDE_FLOAT64_C( -455.33), SIMDE_FLOAT64_C( -343.92),
                         SIMDE_FLOAT64_C(  754.42), SIMDE_FLOAT64_C( -144.11)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  358.04), SIMDE_FLOAT64_C( -974.37),
                         SIMDE_FLOAT64_C( -342.76), SIMDE_FLOAT64_C( -698.47),
                         SIMDE_FLOAT64_C(  146.15), SIMDE_FLOAT64_C(  360.04),
                         SIMDE_FLOAT64_C(  134.15), SIMDE_FLOAT64_C( -376.86)),
      simde_mm512_set_epi64(INT64_C(-7778482448656032654), INT64_C(-7388935565641111344),
                            INT64_C( 2154583157079273400), INT64_C( 4649728279138736034),
                            INT64_C( 1896125478609903946), INT64_C( 6795120210135498653),
                            INT64_C(-8532964392806396349), INT64_C(-8044512602622188161)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  197.25), SIMDE_FLOAT64_C(  348.19),
                         SIMDE_FLOAT64_C(  713.78), SIMDE_FLOAT64_C( -632.29),
                         SIMDE_FLOAT64_C( -382.22), SIMDE_FLOAT64_C( -320.26),
                         SIMDE_FLOAT64_C( -199.21), SIMDE_FLOAT64_C( -764.34)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  360.04), SIMDE_FLOAT64_C( -376.86),
                         SIMDE_FLOAT64_C( -764.34), SIMDE_FLOAT64_C(  360.04),
                         SIMDE_FLOAT64_C( -320.26), SIMDE_FLOAT64_C(  713.78),
                         SIMDE_FLOAT64_C(  146.15), SIMDE_FLOAT64_C(  197.25)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  374.01), SIMDE_FLOAT64_C( -829.82),
                         SIMDE_FLOAT64_C( -372.09), SIMDE_FLOAT64_C( -693.82),
                         SIMDE_FLOAT64_C(  763.12), SIMDE_FLOAT64_C(  797.99),
                         SIMDE_FLOAT64_C(  291.55), SIMDE_FLOAT64_C(  -93.41)),
      simde_mm512_set_epi64(INT64_C( 2330675318709913935), INT64_C( 8512876982035459145),
                            INT64_C( -754385814369639096), INT64_C(-5873166547629617678),
                            INT64_C(-8313572030703954107), INT64_C( 8197482817575228316),
                            INT64_C( 7734796813438689885), INT64_C(-7308014241195865956)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -65.54), SIMDE_FLOAT64_C(  852.70),
                         SIMDE_FLOAT64_C(  316.87), SIMDE_FLOAT64_C(  303.57),
                         SIMDE_FLOAT64_C(  151.19), SIMDE_FLOAT64_C(   17.85),
                         SIMDE_FLOAT64_C(  280.96), SIMDE_FLOAT64_C( -966.13)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -65.54), SIMDE_FLOAT64_C(  280.96),
                         SIMDE_FLOAT64_C( -966.13), SIMDE_FLOAT64_C(  797.99),
                         SIMDE_FLOAT64_C( -372.09), SIMDE_FLOAT64_C(  303.57),
                         SIMDE_FLOAT64_C(  316.87), SIMDE_FLOAT64_C(  303.57)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  192.60), SIMDE_FLOAT64_C( -766.97),
                         SIMDE_FLOAT64_C( -268.82), SIMDE_FLOAT64_C(  379.62),
                         SIMDE_FLOAT64_C(  889.99), SIMDE_FLOAT64_C(  778.00),
                         SIMDE_FLOAT64_C(  136.45), SIMDE_FLOAT64_C( -745.44)),
      simde_mm512_set_epi64(INT64_C(-5841170484671274964), INT64_C(-3543508984518726324),
                            INT64_C( 3010243785522476560), INT64_C(-1544427551515059156),
                            INT64_C(-6824560769606762223), INT64_C( 5419183893290153987),
                            INT64_C(-6963147146169039734), INT64_C(  796151810828840161)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   79.71), SIMDE_FLOAT64_C( -761.86),
                         SIMDE_FLOAT64_C(  699.75), SIMDE_FLOAT64_C(  -94.00),
                         SIMDE_FLOAT64_C(  852.56), SIMDE_FLOAT64_C( -583.72),
                         SIMDE_FLOAT64_C(   64.51), SIMDE_FLOAT64_C(  598.44)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -94.00), SIMDE_FLOAT64_C(  -94.00),
                         SIMDE_FLOAT64_C( -745.44), SIMDE_FLOAT64_C(  -94.00),
                         SIMDE_FLOAT64_C(  136.45), SIMDE_FLOAT64_C(  889.99),
                         SIMDE_FLOAT64_C( -583.72), SIMDE_FLOAT64_C(  136.45)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  910.96), SIMDE_FLOAT64_C(  161.71),
                         SIMDE_FLOAT64_C(  998.55), SIMDE_FLOAT64_C( -146.06),
                         SIMDE_FLOAT64_C( -469.94), SIMDE_FLOAT64_C(  728.29),
                         SIMDE_FLOAT64_C( -146.78), SIMDE_FLOAT64_C( -162.79)),
      simde_mm512_set_epi64(INT64_C( 7017505342718424326), INT64_C( 7336144214089986511),
                            INT64_C(-7372811814600044225), INT64_C( 3369678464815021090),
                            INT64_C(-3624005186939786961), INT64_C( 3053727983599056138),
                            INT64_C( 1044677486690381786), INT64_C( 7246985488966277586)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -157.21), SIMDE_FLOAT64_C(  742.16),
                         SIMDE_FLOAT64_C( -664.02), SIMDE_FLOAT64_C( -706.70),
                         SIMDE_FLOAT64_C( -128.86), SIMDE_FLOAT64_C( -767.59),
                         SIMDE_FLOAT64_C( -790.53), SIMDE_FLOAT64_C(  953.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  161.71), SIMDE_FLOAT64_C( -157.21),
                         SIMDE_FLOAT64_C( -157.21), SIMDE_FLOAT64_C(  728.29),
                         SIMDE_FLOAT64_C( -157.21), SIMDE_FLOAT64_C( -767.59),
                         SIMDE_FLOAT64_C( -767.59), SIMDE_FLOAT64_C(  728.29)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_permutex2var_pd(test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d a;
    simde__mmask8 k;
    simde__m512i idx;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  160.98), SIMDE_FLOAT64_C(  391.82),
                         SIMDE_FLOAT64_C( -569.99), SIMDE_FLOAT64_C( -327.63),
                         SIMDE_FLOAT64_C( -172.36), SIMDE_FLOAT64_C(  393.53),
                         SIMDE_FLOAT64_C(   36.69), SIMDE_FLOAT64_C( -135.52)),
      UINT8_C( 63),
      simde_mm512_set_epi64(INT64_C(-4767707706458520415), INT64_C(-7083171014951853588),
                            INT64_C(-2076988212358998594), INT64_C( 3698505898575972461),
                            INT64_C(-8586603972668500699), INT64_C( 7848938818320954984),
                            INT64_C(-7002500096438875648), INT64_C( 1477571573764517782)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  522.06), SIMDE_FLOAT64_C( -932.28),
                         SIMDE_FLOAT64_C(  600.12), SIMDE_FLOAT64_C( -491.12),
                         SIMDE_FLOAT64_C( -139.11), SIMDE_FLOAT64_C( -268.86),
                         SIMDE_FLOAT64_C(  -71.72), SIMDE_FLOAT64_C(   98.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  160.98), SIMDE_FLOAT64_C(  391.82),
                         SIMDE_FLOAT64_C( -932.28), SIMDE_FLOAT64_C(  600.12),
                         SIMDE_FLOAT64_C( -569.99), SIMDE_FLOAT64_C(   98.47),
                         SIMDE_FLOAT64_C( -135.52), SIMDE_FLOAT64_C(  391.82)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C(  675.92),
                         SIMDE_FLOAT64_C(  490.41), SIMDE_FLOAT64_C(   47.59),
                         SIMDE_FLOAT64_C( -895.71), SIMDE_FLOAT64_C( -736.92),
                         SIMDE_FLOAT64_C(  283.06), SIMDE_FLOAT64_C( -333.94)),
      UINT8_C(251),
      simde_mm512_set_epi64(INT64_C( 7391005387705442660), INT64_C(-5091463632259113685),
                            INT64_C(  685405269785004780), INT64_C(-2602517860068074949),
                            INT64_C( 4704994953943345443), INT64_C( 8877610218385468208),
                            INT64_C( 5776984527519295337), INT64_C( 6526937450820584225)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -203.04), SIMDE_FLOAT64_C(  -80.71),
                         SIMDE_FLOAT64_C(  632.01), SIMDE_FLOAT64_C(  456.89),
                         SIMDE_FLOAT64_C(   51.33), SIMDE_FLOAT64_C( -868.59),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C( -471.60)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   47.59), SIMDE_FLOAT64_C(   51.33),
                         SIMDE_FLOAT64_C(  456.89), SIMDE_FLOAT64_C(   51.33),
                         SIMDE_FLOAT64_C( -895.71), SIMDE_FLOAT64_C( -736.92),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C(  283.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  670.52), SIMDE_FLOAT64_C(  149.72),
                         SIMDE_FLOAT64_C(  213.24), SIMDE_FLOAT64_C( -577.36),
                         SIMDE_FLOAT64_C(  957.37), SIMDE_FLOAT64_C( -934.92),
                         SIMDE_FLOAT64_C( -657.02), SIMDE_FLOAT64_C( -629.37)),
      UINT8_C( 19),
      simde_mm512_set_epi64(INT64_C( 1455933536394832297), INT64_C( -840828676201867557),
                            INT64_C( 6310833464661060096), INT64_C( 8429580363859954742),
                            INT64_C( 5406280044045291975), INT64_C(-2284955492954404973),
                            INT64_C(-3603637419527123210), INT64_C(-1117409850830928520)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  586.29), SIMDE_FLOAT64_C( -760.88),
                         SIMDE_FLOAT64_C( -617.12), SIMDE_FLOAT64_C( -751.58),
                         SIMDE_FLOAT64_C(  907.23), SIMDE_FLOAT64_C( -359.60),
                         SIMDE_FLOAT64_C( -213.75), SIMDE_FLOAT64_C(  403.00)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  670.52), SIMDE_FLOAT64_C(  149.72),
                         SIMDE_FLOAT64_C(  213.24), SIMDE_FLOAT64_C(  149.72),
                         SIMDE_FLOAT64_C(  957.37), SIMDE_FLOAT64_C( -934.92),
                         SIMDE_FLOAT64_C(  149.72), SIMDE_FLOAT64_C(  403.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  918.52), SIMDE_FLOAT64_C( -422.76),
                         SIMDE_FLOAT64_C( -433.33), SIMDE_FLOAT64_C(   48.49),
                         SIMDE_FLOAT64_C(  799.57), SIMDE_FLOAT64_C( -820.22),
                         SIMDE_FLOAT64_C( -959.11), SIMDE_FLOAT64_C(  268.99)),
      UINT8_C(132),
      simde_mm512_set_epi64(INT64_C(-4670296842224865750), INT64_C(-8736438908262001915),
                            INT64_C(-1516874692875012272), INT64_C( 2654080637722702840),
                            INT64_C(-4444585746033374017), INT64_C( 7620312646179506248),
                            INT64_C(-4730811392556899367), INT64_C(-7555925455226975890)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -663.74), SIMDE_FLOAT64_C(  179.29),
                         SIMDE_FLOAT64_C(  989.70), SIMDE_FLOAT64_C( -695.21),
                         SIMDE_FLOAT64_C( -786.23), SIMDE_FLOAT64_C(  873.30),
                         SIMDE_FLOAT64_C(  241.45), SIMDE_FLOAT64_C( -432.13)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  873.30), SIMDE_FLOAT64_C( -422.76),
                         SIMDE_FLOAT64_C( -433.33), SIMDE_FLOAT64_C(   48.49),
                         SIMDE_FLOAT64_C(  799.57), SIMDE_FLOAT64_C( -432.13),
                         SIMDE_FLOAT64_C( -959.11), SIMDE_FLOAT64_C(  268.99)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -904.81), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C( -282.31), SIMDE_FLOAT64_C( -656.10),
                         SIMDE_FLOAT64_C( -789.54), SIMDE_FLOAT64_C( -790.16),
                         SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C(  994.61)),
      UINT8_C( 37),
      simde_mm512_set_epi64(INT64_C( 2001511420457827007), INT64_C( 8280910196874944184),
                            INT64_C( -368934386460614235), INT64_C(-9011857488067354178),
                            INT64_C( 5578921037540219940), INT64_C(-7880186302232587827),
                            INT64_C( 7848707034806784644), INT64_C(-7246117184140796511)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  280.87), SIMDE_FLOAT64_C(  380.83),
                         SIMDE_FLOAT64_C( -236.67), SIMDE_FLOAT64_C( -211.91),
                         SIMDE_FLOAT64_C( -925.76), SIMDE_FLOAT64_C( -915.62),
                         SIMDE_FLOAT64_C(  -30.05), SIMDE_FLOAT64_C(  -70.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -904.81), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C( -282.31), SIMDE_FLOAT64_C( -656.10),
                         SIMDE_FLOAT64_C( -789.54), SIMDE_FLOAT64_C( -236.67),
                         SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C( -415.61)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -318.40), SIMDE_FLOAT64_C( -844.73),
                         SIMDE_FLOAT64_C(  757.65), SIMDE_FLOAT64_C(  677.41),
                         SIMDE_FLOAT64_C( -352.24), SIMDE_FLOAT64_C( -479.79),
                         SIMDE_FLOAT64_C(  602.83), SIMDE_FLOAT64_C(    2.55)),
      UINT8_C(218),
      simde_mm512_set_epi64(INT64_C( 2056379472574346663), INT64_C(-3486865648830471282),
                            INT64_C( 8151787653682140580), INT64_C( -831601358278995789),
                            INT64_C(-2800664419916301039), INT64_C( 3280702275774868225),
                            INT64_C(-4735905134864699368), INT64_C( 7051416147935021095)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  915.68), SIMDE_FLOAT64_C(  -53.79),
                         SIMDE_FLOAT64_C(  703.31), SIMDE_FLOAT64_C(  930.79),
                         SIMDE_FLOAT64_C(  111.33), SIMDE_FLOAT64_C( -176.75),
                         SIMDE_FLOAT64_C( -316.94), SIMDE_FLOAT64_C(  639.68)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -318.40), SIMDE_FLOAT64_C(  -53.79),
                         SIMDE_FLOAT64_C(  757.65), SIMDE_FLOAT64_C( -352.24),
                         SIMDE_FLOAT64_C(  602.83), SIMDE_FLOAT64_C( -479.79),
                         SIMDE_FLOAT64_C(  639.68), SIMDE_FLOAT64_C(    2.55)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  432.42), SIMDE_FLOAT64_C(  421.92),
                         SIMDE_FLOAT64_C(  718.96), SIMDE_FLOAT64_C( -864.59),
                         SIMDE_FLOAT64_C( -334.42), SIMDE_FLOAT64_C(  660.53),
                         SIMDE_FLOAT64_C(  748.73), SIMDE_FLOAT64_C(  996.15)),
      UINT8_C(227),
      simde_mm512_set_epi64(INT64_C( 6904524208941840952), INT64_C(-7164378700336361334),
                            INT64_C( 4351794567182281042), INT64_C(-1716872434006574729),
                            INT64_C( -689503347190866770), INT64_C(-1389624339165317749),
                            INT64_C(-8184083999390244234), INT64_C( 8331479114169761131)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  601.37), SIMDE_FLOAT64_C( -660.24),
                         SIMDE_FLOAT64_C( -675.56), SIMDE_FLOAT64_C( -194.09),
                         SIMDE_FLOAT64_C(  149.22), SIMDE_FLOAT64_C(  161.52),
                         SIMDE_FLOAT64_C(  632.78), SIMDE_FLOAT64_C(  346.90)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  346.90), SIMDE_FLOAT64_C(  161.52),
                         SIMDE_FLOAT64_C(  660.53), SIMDE_FLOAT64_C( -864.59),
                         SIMDE_FLOAT64_C( -334.42), SIMDE_FLOAT64_C(  660.53),
                         SIMDE_FLOAT64_C(  421.92), SIMDE_FLOAT64_C(  149.22)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.84), SIMDE_FLOAT64_C(   39.14),
                         SIMDE_FLOAT64_C(  124.68), SIMDE_FLOAT64_C( -448.70),
                         SIMDE_FLOAT64_C(  122.69), SIMDE_FLOAT64_C(   65.13),
                         SIMDE_FLOAT64_C( -972.27), SIMDE_FLOAT64_C(  628.22)),
      UINT8_C(179),
      simde_mm512_set_epi64(INT64_C( 2669799685376652269), INT64_C( 7927414333096918356),
                            INT64_C(-6028737433755228757), INT64_C(-6289085317177674471),
                            INT64_C(-5541511610486147753), INT64_C( 6531713794566454707),
                            INT64_C( -446705336047418133), INT64_C(-6709780755556058351)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  196.06), SIMDE_FLOAT64_C(  -83.06),
                         SIMDE_FLOAT64_C(  687.82), SIMDE_FLOAT64_C( -517.82),
                         SIMDE_FLOAT64_C( -294.36), SIMDE_FLOAT64_C(  702.71),
                         SIMDE_FLOAT64_C( -920.22), SIMDE_FLOAT64_C( -923.04)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  687.82), SIMDE_FLOAT64_C(   39.14),
                         SIMDE_FLOAT64_C( -294.36), SIMDE_FLOAT64_C( -920.22),
                         SIMDE_FLOAT64_C(  122.69), SIMDE_FLOAT64_C(   65.13),
                         SIMDE_FLOAT64_C( -294.36), SIMDE_FLOAT64_C( -972.27)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_permutex2var_pd(test_vec[i].a, test_vec[i].k, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask2_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d a;
    simde__m512i idx;
    simde__mmask8 k;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  824.77), SIMDE_FLOAT64_C(  172.30),
                         SIMDE_FLOAT64_C( -660.39), SIMDE_FLOAT64_C( -605.88),
                         SIMDE_FLOAT64_C( -689.22), SIMDE_FLOAT64_C(  -25.12),
                         SIMDE_FLOAT64_C(  921.58), SIMDE_FLOAT64_C(  433.31)),
      simde_mm512_set_epi64(INT64_C( 4651624766755653550), INT64_C( 4649285006011746222),
                            INT64_C( 4650293302154881925), INT64_C( 4621571419609466143),
                            INT64_C(-4573265035950104248), INT64_C( 4648839571861101609),
                            INT64_C(-4574838041265265705), INT64_C(-4573884896625379246)),
      UINT8_C(198),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -867.63), SIMDE_FLOAT64_C(  -65.75),
                         SIMDE_FLOAT64_C(  137.16), SIMDE_FLOAT64_C(  -73.36),
                         SIMDE_FLOAT64_C( -396.53), SIMDE_FLOAT64_C( -409.15),
                         SIMDE_FLOAT64_C(  672.29), SIMDE_FLOAT64_C(  992.21)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -65.75), SIMDE_FLOAT64_C(  -65.75),
                         SIMDE_FLOAT64_C(  805.14), SIMDE_FLOAT64_C(    9.56),
                         SIMDE_FLOAT64_C( -783.96), SIMDE_FLOAT64_C(  672.29),
                         SIMDE_FLOAT64_C(  824.77), SIMDE_FLOAT64_C( -713.49)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  784.21), SIMDE_FLOAT64_C(  732.58),
                         SIMDE_FLOAT64_C( -862.95), SIMDE_FLOAT64_C( -241.44),
                         SIMDE_FLOAT64_C( -318.72), SIMDE_FLOAT64_C(  630.11),
                         SIMDE_FLOAT64_C( -645.10), SIMDE_FLOAT64_C( -230.29)),
      simde_mm512_set_epi64(INT64_C( 4646939703729234903), INT64_C( 4639186123652018995),
                            INT64_C( 4627437358124116214), INT64_C(-4583138122601951396),
                            INT64_C(-4586200570348563333), INT64_C(-4573672822822613811),
                            INT64_C(-4584207727513451889), INT64_C(-4573688391907263119)),
      UINT8_C(222),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -947.87), SIMDE_FLOAT64_C(  877.96),
                         SIMDE_FLOAT64_C(  184.43), SIMDE_FLOAT64_C(  375.34),
                         SIMDE_FLOAT64_C(  389.76), SIMDE_FLOAT64_C(  437.16),
                         SIMDE_FLOAT64_C( -638.93), SIMDE_FLOAT64_C(  773.45)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  784.21), SIMDE_FLOAT64_C( -318.72),
                         SIMDE_FLOAT64_C(   23.96), SIMDE_FLOAT64_C(  375.34),
                         SIMDE_FLOAT64_C(  389.76), SIMDE_FLOAT64_C(  184.43),
                         SIMDE_FLOAT64_C( -947.87), SIMDE_FLOAT64_C( -735.83)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  853.65), SIMDE_FLOAT64_C(  495.16),
                         SIMDE_FLOAT64_C( -991.61), SIMDE_FLOAT64_C(  120.75),
                         SIMDE_FLOAT64_C( -451.25), SIMDE_FLOAT64_C( -719.73),
                         SIMDE_FLOAT64_C( -295.20), SIMDE_FLOAT64_C(  405.97)),
      simde_mm512_set_epi64(INT64_C(-4571849568660970537), INT64_C(-4573624268389131223),
                            INT64_C( 4649833882216332001), INT64_C(-4576057267719073956),
                            INT64_C( 4639950680057509315), INT64_C( 4648192795141178655),
                            INT64_C(-4582991755614061855), INT64_C(-4572918030080378143)),
      UINT8_C( 61),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -475.08), SIMDE_FLOAT64_C(  601.08),
                         SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C(  446.98),
                         SIMDE_FLOAT64_C(   51.90), SIMDE_FLOAT64_C(  597.18),
                         SIMDE_FLOAT64_C(  -19.20), SIMDE_FLOAT64_C( -536.51)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -944.88), SIMDE_FLOAT64_C( -743.12),
                         SIMDE_FLOAT64_C( -295.20), SIMDE_FLOAT64_C(  446.98),
                         SIMDE_FLOAT64_C( -451.25), SIMDE_FLOAT64_C( -475.08),
                         SIMDE_FLOAT64_C( -175.54), SIMDE_FLOAT64_C( -295.20)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  985.03), SIMDE_FLOAT64_C(  291.60),
                         SIMDE_FLOAT64_C( -732.66), SIMDE_FLOAT64_C(  106.36),
                         SIMDE_FLOAT64_C(  883.40), SIMDE_FLOAT64_C(    8.63),
                         SIMDE_FLOAT64_C(  178.77), SIMDE_FLOAT64_C( -118.91)),
      simde_mm512_set_epi64(INT64_C(-4574823439750848840), INT64_C(-4582104757593702400),
                            INT64_C(-4583336210616811520), INT64_C(-4580375093861815419),
                            INT64_C(-4577720432987713044), INT64_C( 4649427062914054881),
                            INT64_C(-4573213578805924332), INT64_C(-4581494660581682053)),
      UINT8_C(193),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  557.43), SIMDE_FLOAT64_C(  547.40),
                         SIMDE_FLOAT64_C( -994.90), SIMDE_FLOAT64_C( -527.55),
                         SIMDE_FLOAT64_C(  290.76), SIMDE_FLOAT64_C( -839.12),
                         SIMDE_FLOAT64_C(  702.81), SIMDE_FLOAT64_C( -129.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -129.54), SIMDE_FLOAT64_C( -118.91),
                         SIMDE_FLOAT64_C( -165.75), SIMDE_FLOAT64_C( -249.91),
                         SIMDE_FLOAT64_C( -394.72), SIMDE_FLOAT64_C(  706.66),
                         SIMDE_FLOAT64_C( -789.81), SIMDE_FLOAT64_C(  290.76)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -733.70), SIMDE_FLOAT64_C(  -80.62),
                         SIMDE_FLOAT64_C(  200.37), SIMDE_FLOAT64_C( -613.00),
                         SIMDE_FLOAT64_C( -530.37), SIMDE_FLOAT64_C(  940.29),
                         SIMDE_FLOAT64_C( -837.65), SIMDE_FLOAT64_C( -127.38)),
      simde_mm512_set_epi64(INT64_C( 4651252164255232819), INT64_C( 4644570915878354289),
                            INT64_C( 4649897126125161677), INT64_C( 4645692593660546253),
                            INT64_C( 4644974304704352748), INT64_C(-4606788353832622490),
                            INT64_C( 4645887339160057938), INT64_C( 4635970272043099750)),
      UINT8_C( 81),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -742.43), SIMDE_FLOAT64_C(  171.75),
                         SIMDE_FLOAT64_C(  896.83), SIMDE_FLOAT64_C(  381.31),
                         SIMDE_FLOAT64_C( -468.20), SIMDE_FLOAT64_C( -182.38),
                         SIMDE_FLOAT64_C( -642.39), SIMDE_FLOAT64_C( -912.51)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  914.15), SIMDE_FLOAT64_C( -837.65),
                         SIMDE_FLOAT64_C(  760.10), SIMDE_FLOAT64_C(  896.83),
                         SIMDE_FLOAT64_C(  356.22), SIMDE_FLOAT64_C(   -4.35),
                         SIMDE_FLOAT64_C(  408.12), SIMDE_FLOAT64_C(  -80.62)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  566.99), SIMDE_FLOAT64_C( -242.78),
                         SIMDE_FLOAT64_C(  250.83), SIMDE_FLOAT64_C( -818.85),
                         SIMDE_FLOAT64_C( -959.57), SIMDE_FLOAT64_C(  925.03),
                         SIMDE_FLOAT64_C( -644.70), SIMDE_FLOAT64_C( -800.67)),
      simde_mm512_set_epi64(INT64_C(-4573614680647737016), INT64_C(-4572547362720422298),
                            INT64_C(-4579978038222792950), INT64_C(-4573175139879417283),
                            INT64_C(-4572733488048772219), INT64_C(-4575215833460569539),
                            INT64_C(-4582412972693200568), INT64_C(-4572092340828383478)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  519.90), SIMDE_FLOAT64_C( -645.40),
                         SIMDE_FLOAT64_C( -442.29), SIMDE_FLOAT64_C( -336.85),
                         SIMDE_FLOAT64_C( -152.85), SIMDE_FLOAT64_C( -363.79),
                         SIMDE_FLOAT64_C( -614.03), SIMDE_FLOAT64_C( -923.13)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -923.13), SIMDE_FLOAT64_C( -865.55),
                         SIMDE_FLOAT64_C( -266.39), SIMDE_FLOAT64_C( -442.29),
                         SIMDE_FLOAT64_C( -844.39), SIMDE_FLOAT64_C( -562.18),
                         SIMDE_FLOAT64_C( -191.99), SIMDE_FLOAT64_C( -363.79)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -748.43), SIMDE_FLOAT64_C(  -53.25),
                         SIMDE_FLOAT64_C( -132.01), SIMDE_FLOAT64_C( -767.78),
                         SIMDE_FLOAT64_C(   -9.36), SIMDE_FLOAT64_C( -226.72),
                         SIMDE_FLOAT64_C( -661.68), SIMDE_FLOAT64_C( -655.84)),
      simde_mm512_set_epi64(INT64_C( 4636324226826313400), INT64_C(-4582681781295959245),
                            INT64_C(-4588763400011513856), INT64_C(-4578054508600696504),
                            INT64_C( 4643285630765949256), INT64_C(-4577793440559797371),
                            INT64_C( 4641318648444323103), INT64_C(-4573035194039433953)),
      UINT8_C( 44),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  845.75), SIMDE_FLOAT64_C(   43.86),
                         SIMDE_FLOAT64_C( -170.77), SIMDE_FLOAT64_C(  428.74),
                         SIMDE_FLOAT64_C(  695.01), SIMDE_FLOAT64_C( -702.60),
                         SIMDE_FLOAT64_C( -231.45), SIMDE_FLOAT64_C( -416.99)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   94.13), SIMDE_FLOAT64_C( -184.35),
                         SIMDE_FLOAT64_C( -655.84), SIMDE_FLOAT64_C( -375.73),
                         SIMDE_FLOAT64_C( -416.99), SIMDE_FLOAT64_C( -132.01),
                         SIMDE_FLOAT64_C(  202.21), SIMDE_FLOAT64_C( -810.09)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -797.03), SIMDE_FLOAT64_C( -987.00),
                         SIMDE_FLOAT64_C(  679.83), SIMDE_FLOAT64_C( -872.18),
                         SIMDE_FLOAT64_C(   58.63), SIMDE_FLOAT64_C( -398.86),
                         SIMDE_FLOAT64_C( -816.03), SIMDE_FLOAT64_C(  667.01)),
      simde_mm512_set_epi64(INT64_C(-4573879706930496143), INT64_C(-4575599870881919140),
                            INT64_C( 4646298820391636828), INT64_C( 4636687329546270147),
                            INT64_C( 4651451571684046275), INT64_C(-4586695966307574088),
                            INT64_C(-4575178010260574044), INT64_C( 4649362675513132319)),
      UINT8_C( 86),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  312.31), SIMDE_FLOAT64_C(  578.29),
                         SIMDE_FLOAT64_C(  419.61), SIMDE_FLOAT64_C( -753.42),
                         SIMDE_FLOAT64_C(  687.05), SIMDE_FLOAT64_C(  241.87),
                         SIMDE_FLOAT64_C(  -80.26), SIMDE_FLOAT64_C( -667.68)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -714.08), SIMDE_FLOAT64_C( -753.42),
                         SIMDE_FLOAT64_C(  431.51), SIMDE_FLOAT64_C(   58.63),
                         SIMDE_FLOAT64_C(  936.82), SIMDE_FLOAT64_C( -667.68),
                         SIMDE_FLOAT64_C( -872.18), SIMDE_FLOAT64_C(  699.34)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask2_permutex2var_pd(test_vec[i].a, test_vec[i].idx, test_vec[i].k, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_permutex2var_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512i idx;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { UINT8_C( 63),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  160.98), SIMDE_FLOAT64_C(  391.82),
                         SIMDE_FLOAT64_C( -569.99), SIMDE_FLOAT64_C( -327.63),
                         SIMDE_FLOAT64_C( -172.36), SIMDE_FLOAT64_C(  393.53),
                         SIMDE_FLOAT64_C(   36.69), SIMDE_FLOAT64_C( -135.52)),
      simde_mm512_set_epi64(INT64_C(-4767707706458520415), INT64_C(-7083171014951853588),
                            INT64_C(-2076988212358998594), INT64_C( 3698505898575972461),
                            INT64_C(-8586603972668500699), INT64_C( 7848938818320954984),
                            INT64_C(-7002500096438875648), INT64_C( 1477571573764517782)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  522.06), SIMDE_FLOAT64_C( -932.28),
                         SIMDE_FLOAT64_C(  600.12), SIMDE_FLOAT64_C( -491.12),
                         SIMDE_FLOAT64_C( -139.11), SIMDE_FLOAT64_C( -268.86),
                         SIMDE_FLOAT64_C(  -71.72), SIMDE_FLOAT64_C(   98.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -932.28), SIMDE_FLOAT64_C(  600.12),
                         SIMDE_FLOAT64_C( -569.99), SIMDE_FLOAT64_C(   98.47),
                         SIMDE_FLOAT64_C( -135.52), SIMDE_FLOAT64_C(  391.82)) },
    { UINT8_C(251),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C(  675.92),
                         SIMDE_FLOAT64_C(  490.41), SIMDE_FLOAT64_C(   47.59),
                         SIMDE_FLOAT64_C( -895.71), SIMDE_FLOAT64_C( -736.92),
                         SIMDE_FLOAT64_C(  283.06), SIMDE_FLOAT64_C( -333.94)),
      simde_mm512_set_epi64(INT64_C( 7391005387705442660), INT64_C(-5091463632259113685),
                            INT64_C(  685405269785004780), INT64_C(-2602517860068074949),
                            INT64_C( 4704994953943345443), INT64_C( 8877610218385468208),
                            INT64_C( 5776984527519295337), INT64_C( 6526937450820584225)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -203.04), SIMDE_FLOAT64_C(  -80.71),
                         SIMDE_FLOAT64_C(  632.01), SIMDE_FLOAT64_C(  456.89),
                         SIMDE_FLOAT64_C(   51.33), SIMDE_FLOAT64_C( -868.59),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C( -471.60)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   47.59), SIMDE_FLOAT64_C(   51.33),
                         SIMDE_FLOAT64_C(  456.89), SIMDE_FLOAT64_C(   51.33),
                         SIMDE_FLOAT64_C( -895.71), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C(  283.06)) },
    { UINT8_C( 19),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  670.52), SIMDE_FLOAT64_C(  149.72),
                         SIMDE_FLOAT64_C(  213.24), SIMDE_FLOAT64_C( -577.36),
                         SIMDE_FLOAT64_C(  957.37), SIMDE_FLOAT64_C( -934.92),
                         SIMDE_FLOAT64_C( -657.02), SIMDE_FLOAT64_C( -629.37)),
      simde_mm512_set_epi64(INT64_C( 1455933536394832297), INT64_C( -840828676201867557),
                            INT64_C( 6310833464661060096), INT64_C( 8429580363859954742),
                            INT64_C( 5406280044045291975), INT64_C(-2284955492954404973),
                            INT64_C(-3603637419527123210), INT64_C(-1117409850830928520)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  586.29), SIMDE_FLOAT64_C( -760.88),
                         SIMDE_FLOAT64_C( -617.12), SIMDE_FLOAT64_C( -751.58),
                         SIMDE_FLOAT64_C(  907.23), SIMDE_FLOAT64_C( -359.60),
                         SIMDE_FLOAT64_C( -213.75), SIMDE_FLOAT64_C(  403.00)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  149.72),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  149.72), SIMDE_FLOAT64_C(  403.00)) },
    { UINT8_C(132),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  918.52), SIMDE_FLOAT64_C( -422.76),
                         SIMDE_FLOAT64_C( -433.33), SIMDE_FLOAT64_C(   48.49),
                         SIMDE_FLOAT64_C(  799.57), SIMDE_FLOAT64_C( -820.22),
                         SIMDE_FLOAT64_C( -959.11), SIMDE_FLOAT64_C(  268.99)),
      simde_mm512_set_epi64(INT64_C(-4670296842224865750), INT64_C(-8736438908262001915),
                            INT64_C(-1516874692875012272), INT64_C( 2654080637722702840),
                            INT64_C(-4444585746033374017), INT64_C( 7620312646179506248),
                            INT64_C(-4730811392556899367), INT64_C(-7555925455226975890)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -663.74), SIMDE_FLOAT64_C(  179.29),
                         SIMDE_FLOAT64_C(  989.70), SIMDE_FLOAT64_C( -695.21),
                         SIMDE_FLOAT64_C( -786.23), SIMDE_FLOAT64_C(  873.30),
                         SIMDE_FLOAT64_C(  241.45), SIMDE_FLOAT64_C( -432.13)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  873.30), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -432.13),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C( 37),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -904.81), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C( -282.31), SIMDE_FLOAT64_C( -656.10),
                         SIMDE_FLOAT64_C( -789.54), SIMDE_FLOAT64_C( -790.16),
                         SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C(  994.61)),
      simde_mm512_set_epi64(INT64_C( 2001511420457827007), INT64_C( 8280910196874944184),
                            INT64_C( -368934386460614235), INT64_C(-9011857488067354178),
                            INT64_C( 5578921037540219940), INT64_C(-7880186302232587827),
                            INT64_C( 7848707034806784644), INT64_C(-7246117184140796511)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  280.87), SIMDE_FLOAT64_C(  380.83),
                         SIMDE_FLOAT64_C( -236.67), SIMDE_FLOAT64_C( -211.91),
                         SIMDE_FLOAT64_C( -925.76), SIMDE_FLOAT64_C( -915.62),
                         SIMDE_FLOAT64_C(  -30.05), SIMDE_FLOAT64_C(  -70.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -282.31), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -236.67),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -415.61)) },
    { UINT8_C(218),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -318.40), SIMDE_FLOAT64_C( -844.73),
                         SIMDE_FLOAT64_C(  757.65), SIMDE_FLOAT64_C(  677.41),
                         SIMDE_FLOAT64_C( -352.24), SIMDE_FLOAT64_C( -479.79),
                         SIMDE_FLOAT64_C(  602.83), SIMDE_FLOAT64_C(    2.55)),
      simde_mm512_set_epi64(INT64_C( 2056379472574346663), INT64_C(-3486865648830471282),
                            INT64_C( 8151787653682140580), INT64_C( -831601358278995789),
                            INT64_C(-2800664419916301039), INT64_C( 3280702275774868225),
                            INT64_C(-4735905134864699368), INT64_C( 7051416147935021095)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  915.68), SIMDE_FLOAT64_C(  -53.79),
                         SIMDE_FLOAT64_C(  703.31), SIMDE_FLOAT64_C(  930.79),
                         SIMDE_FLOAT64_C(  111.33), SIMDE_FLOAT64_C( -176.75),
                         SIMDE_FLOAT64_C( -316.94), SIMDE_FLOAT64_C(  639.68)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -318.40), SIMDE_FLOAT64_C(  -53.79),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -352.24),
                         SIMDE_FLOAT64_C(  602.83), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  639.68), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(227),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  432.42), SIMDE_FLOAT64_C(  421.92),
                         SIMDE_FLOAT64_C(  718.96), SIMDE_FLOAT64_C( -864.59),
                         SIMDE_FLOAT64_C( -334.42), SIMDE_FLOAT64_C(  660.53),
                         SIMDE_FLOAT64_C(  748.73), SIMDE_FLOAT64_C(  996.15)),
      simde_mm512_set_epi64(INT64_C( 6904524208941840952), INT64_C(-7164378700336361334),
                            INT64_C( 4351794567182281042), INT64_C(-1716872434006574729),
                            INT64_C( -689503347190866770), INT64_C(-1389624339165317749),
                            INT64_C(-8184083999390244234), INT64_C( 8331479114169761131)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  601.37), SIMDE_FLOAT64_C( -660.24),
                         SIMDE_FLOAT64_C( -675.56), SIMDE_FLOAT64_C( -194.09),
                         SIMDE_FLOAT64_C(  149.22), SIMDE_FLOAT64_C(  161.52),
                         SIMDE_FLOAT64_C(  632.78), SIMDE_FLOAT64_C(  346.90)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  346.90), SIMDE_FLOAT64_C(  161.52),
                         SIMDE_FLOAT64_C(  660.53), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  421.92), SIMDE_FLOAT64_C(  149.22)) },
    { UINT8_C(179),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.84), SIMDE_FLOAT64_C(   39.14),
                         SIMDE_FLOAT64_C(  124.68), SIMDE_FLOAT64_C( -448.70),
                         SIMDE_FLOAT64_C(  122.69), SIMDE_FLOAT64_C(   65.13),
                         SIMDE_FLOAT64_C( -972.27), SIMDE_FLOAT64_C(  628.22)),
      simde_mm512_set_epi64(INT64_C( 2669799685376652269), INT64_C( 7927414333096918356),
                            INT64_C(-6028737433755228757), INT64_C(-6289085317177674471),
                            INT64_C(-5541511610486147753), INT64_C( 6531713794566454707),
                            INT64_C( -446705336047418133), INT64_C(-6709780755556058351)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  196.06), SIMDE_FLOAT64_C(  -83.06),
                         SIMDE_FLOAT64_C(  687.82), SIMDE_FLOAT64_C( -517.82),
                         SIMDE_FLOAT64_C( -294.36), SIMDE_FLOAT64_C(  702.71),
                         SIMDE_FLOAT64_C( -920.22), SIMDE_FLOAT64_C( -923.04)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  687.82), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -294.36), SIMDE_FLOAT64_C( -920.22),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -294.36), SIMDE_FLOAT64_C( -972.27)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_maskz_permutex2var_pd(test_vec[i].k, test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__m512i idx;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(   559.81), SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   407.56),
                         SIMDE_FLOAT32_C(  -787.72), SIMDE_FLOAT32_C(  -703.51), SIMDE_FLOAT32_C(  -470.36), SIMDE_FLOAT32_C(   135.20),
                         SIMDE_FLOAT32_C(   799.30), SIMDE_FLOAT32_C(  -576.01), SIMDE_FLOAT32_C(   439.15), SIMDE_FLOAT32_C(   -28.15),
                         SIMDE_FLOAT32_C(   481.25), SIMDE_FLOAT32_C(  -784.26), SIMDE_FLOAT32_C(   549.03), SIMDE_FLOAT32_C(   582.53)),
      simde_mm512_set_epi32(INT32_C(-1732993162), INT32_C( 1212743926), INT32_C( 1966971402), INT32_C(-1506668774),
                            INT32_C(-1700657265), INT32_C( 1944327234), INT32_C( -355879099), INT32_C(-1588067414),
                            INT32_C(  301696052), INT32_C( 1998339065), INT32_C(-2060809025), INT32_C(-1942156019),
                            INT32_C(  551689125), INT32_C(  669995747), INT32_C(-1196653219), INT32_C( -147816939)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   120.10), SIMDE_FLOAT32_C(  -620.03), SIMDE_FLOAT32_C(   185.23), SIMDE_FLOAT32_C(   -11.91),
                         SIMDE_FLOAT32_C(   355.11), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(  -202.49), SIMDE_FLOAT32_C(   966.37),
                         SIMDE_FLOAT32_C(  -563.83), SIMDE_FLOAT32_C(   938.85), SIMDE_FLOAT32_C(  -465.05), SIMDE_FLOAT32_C(  -104.57),
                         SIMDE_FLOAT32_C(  -431.26), SIMDE_FLOAT32_C(   -57.75), SIMDE_FLOAT32_C(   438.04), SIMDE_FLOAT32_C(   729.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   938.85), SIMDE_FLOAT32_C(   938.85), SIMDE_FLOAT32_C(  -703.51), SIMDE_FLOAT32_C(   472.82),
                         SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(  -784.26), SIMDE_FLOAT32_C(   439.15), SIMDE_FLOAT32_C(  -703.51),
                         SIMDE_FLOAT32_C(  -104.57), SIMDE_FLOAT32_C(  -202.49), SIMDE_FLOAT32_C(   120.10), SIMDE_FLOAT32_C(  -423.61),
                         SIMDE_FLOAT32_C(   439.15), SIMDE_FLOAT32_C(   481.25), SIMDE_FLOAT32_C(   185.23), SIMDE_FLOAT32_C(  -465.05)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -832.50), SIMDE_FLOAT32_C(   438.46), SIMDE_FLOAT32_C(   336.35), SIMDE_FLOAT32_C(    99.21),
                         SIMDE_FLOAT32_C(   -38.88), SIMDE_FLOAT32_C(   218.73), SIMDE_FLOAT32_C(  -966.90), SIMDE_FLOAT32_C(  -737.78),
                         SIMDE_FLOAT32_C(  -224.13), SIMDE_FLOAT32_C(  -834.15), SIMDE_FLOAT32_C(  -819.46), SIMDE_FLOAT32_C(   112.81),
                         SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(   282.83), SIMDE_FLOAT32_C(   841.24), SIMDE_FLOAT32_C(    79.76)),
      simde_mm512_set_epi32(INT32_C( 1760980702), INT32_C(-1592941833), INT32_C(-1618734568), INT32_C(-1937346052),
                            INT32_C( -716563340), INT32_C(-1364071584), INT32_C( -516953475), INT32_C( 1021791773),
                            INT32_C(  587319712), INT32_C(-1327772936), INT32_C( -388433125), INT32_C(-1835488163),
                            INT32_C( 1934085090), INT32_C( 1823172786), INT32_C( -962834173), INT32_C(-1813383694)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   141.08), SIMDE_FLOAT32_C(  -990.15), SIMDE_FLOAT32_C(  -887.47), SIMDE_FLOAT32_C(  -396.24),
                         SIMDE_FLOAT32_C(    -2.60), SIMDE_FLOAT32_C(   165.88), SIMDE_FLOAT32_C(   375.27), SIMDE_FLOAT32_C(  -512.98),
                         SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(   633.65), SIMDE_FLOAT32_C(  -157.33), SIMDE_FLOAT32_C(   541.44),
                         SIMDE_FLOAT32_C(   -98.08), SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(  -774.08), SIMDE_FLOAT32_C(  -414.07)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -990.15), SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(  -512.98), SIMDE_FLOAT32_C(  -396.24),
                         SIMDE_FLOAT32_C(   541.44), SIMDE_FLOAT32_C(    79.76), SIMDE_FLOAT32_C(  -887.47), SIMDE_FLOAT32_C(  -887.47),
                         SIMDE_FLOAT32_C(    79.76), SIMDE_FLOAT32_C(  -512.98), SIMDE_FLOAT32_C(    -2.60), SIMDE_FLOAT32_C(  -887.47),
                         SIMDE_FLOAT32_C(   282.83), SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(   711.12)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   485.76), SIMDE_FLOAT32_C(   786.03), SIMDE_FLOAT32_C(   489.95), SIMDE_FLOAT32_C(   796.52),
                         SIMDE_FLOAT32_C(  -248.07), SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(   170.00), SIMDE_FLOAT32_C(   366.57),
                         SIMDE_FLOAT32_C(  -211.73), SIMDE_FLOAT32_C(   908.31), SIMDE_FLOAT32_C(  -144.11), SIMDE_FLOAT32_C(  -343.92),
                         SIMDE_FLOAT32_C(   961.65), SIMDE_FLOAT32_C(   754.42), SIMDE_FLOAT32_C(  -432.97), SIMDE_FLOAT32_C(   164.52)),
      simde_mm512_set_epi32(INT32_C(-1723897302), INT32_C(-1378607382), INT32_C(-1399746280), INT32_C(   55039129),
                            INT32_C( -614650529), INT32_C( 1411406194), INT32_C(  789645610), INT32_C(  647523062),
                            INT32_C( 1326675104), INT32_C(-1833621116), INT32_C( 1459731687), INT32_C(-1374295064),
                            INT32_C( 1719685048), INT32_C(-1859395493), INT32_C(  506068853), INT32_C( 1338183771)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -985.32), SIMDE_FLOAT32_C(   234.60), SIMDE_FLOAT32_C(   859.59), SIMDE_FLOAT32_C(  -409.35),
                         SIMDE_FLOAT32_C(  -846.10), SIMDE_FLOAT32_C(  -411.92), SIMDE_FLOAT32_C(   481.68), SIMDE_FLOAT32_C(  -341.91),
                         SIMDE_FLOAT32_C(   254.48), SIMDE_FLOAT32_C(   755.70), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(   789.10),
                         SIMDE_FLOAT32_C(   344.74), SIMDE_FLOAT32_C(   652.93), SIMDE_FLOAT32_C(   184.91), SIMDE_FLOAT32_C(  -455.33)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(  -341.91), SIMDE_FLOAT32_C(   481.68),
                         SIMDE_FLOAT32_C(  -985.32), SIMDE_FLOAT32_C(   652.93), SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(   755.70),
                         SIMDE_FLOAT32_C(   164.52), SIMDE_FLOAT32_C(  -343.92), SIMDE_FLOAT32_C(  -211.73), SIMDE_FLOAT32_C(   366.57),
                         SIMDE_FLOAT32_C(  -341.91), SIMDE_FLOAT32_C(  -846.10), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(  -846.10)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   374.01), SIMDE_FLOAT32_C(  -829.82), SIMDE_FLOAT32_C(  -372.09), SIMDE_FLOAT32_C(  -693.82),
                         SIMDE_FLOAT32_C(   763.12), SIMDE_FLOAT32_C(   797.99), SIMDE_FLOAT32_C(   291.55), SIMDE_FLOAT32_C(   -93.41),
                         SIMDE_FLOAT32_C(   658.18), SIMDE_FLOAT32_C(  -330.38), SIMDE_FLOAT32_C(  -462.89), SIMDE_FLOAT32_C(  -905.06),
                         SIMDE_FLOAT32_C(   266.49), SIMDE_FLOAT32_C(  -537.47), SIMDE_FLOAT32_C(  -705.33), SIMDE_FLOAT32_C(   699.62)),
      simde_mm512_set_epi32(INT32_C(  542652634), INT32_C(-1703311025), INT32_C( 1982058627), INT32_C(  315796553),
                            INT32_C( -175644135), INT32_C( 1189569864), INT32_C(-1367453148), INT32_C( 1842630130),
                            INT32_C(-1935654327), INT32_C(  121935685), INT32_C( 1908625200), INT32_C(-1041198180),
                            INT32_C( 1800897720), INT32_C(-1697242531), INT32_C(-1701529660), INT32_C( 1678133404)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -65.54), SIMDE_FLOAT32_C(   852.70), SIMDE_FLOAT32_C(   316.87), SIMDE_FLOAT32_C(   303.57),
                         SIMDE_FLOAT32_C(   151.19), SIMDE_FLOAT32_C(    17.85), SIMDE_FLOAT32_C(   280.96), SIMDE_FLOAT32_C(  -966.13),
                         SIMDE_FLOAT32_C(   156.66), SIMDE_FLOAT32_C(   198.89), SIMDE_FLOAT32_C(  -766.40), SIMDE_FLOAT32_C(  -495.88),
                         SIMDE_FLOAT32_C(  -794.42), SIMDE_FLOAT32_C(  -263.27), SIMDE_FLOAT32_C(    74.85), SIMDE_FLOAT32_C(   127.81)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    17.85), SIMDE_FLOAT32_C(   374.01), SIMDE_FLOAT32_C(   266.49), SIMDE_FLOAT32_C(   291.55),
                         SIMDE_FLOAT32_C(   280.96), SIMDE_FLOAT32_C(   -93.41), SIMDE_FLOAT32_C(  -905.06), SIMDE_FLOAT32_C(  -263.27),
                         SIMDE_FLOAT32_C(   291.55), SIMDE_FLOAT32_C(  -462.89), SIMDE_FLOAT32_C(   127.81), SIMDE_FLOAT32_C(   303.57),
                         SIMDE_FLOAT32_C(  -966.13), SIMDE_FLOAT32_C(   316.87), SIMDE_FLOAT32_C(  -905.06), SIMDE_FLOAT32_C(   303.57)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -276.00), SIMDE_FLOAT32_C(  -317.53), SIMDE_FLOAT32_C(  -723.48), SIMDE_FLOAT32_C(  -792.04),
                         SIMDE_FLOAT32_C(  -284.98), SIMDE_FLOAT32_C(   906.86), SIMDE_FLOAT32_C(  -798.29), SIMDE_FLOAT32_C(   122.95),
                         SIMDE_FLOAT32_C(   192.60), SIMDE_FLOAT32_C(  -766.97), SIMDE_FLOAT32_C(  -268.82), SIMDE_FLOAT32_C(   379.62),
                         SIMDE_FLOAT32_C(   889.99), SIMDE_FLOAT32_C(   778.00), SIMDE_FLOAT32_C(   136.45), SIMDE_FLOAT32_C(  -745.44)),
      simde_mm512_set_epi32(INT32_C( 1809884012), INT32_C( -191206140), INT32_C( -553702639), INT32_C(-1800209842),
                            INT32_C(  721509385), INT32_C(   -3110338), INT32_C(  629848436), INT32_C( 1833821522),
                            INT32_C( 1870762521), INT32_C( 1138301165), INT32_C(  499100111), INT32_C( -583483550),
                            INT32_C(  449841541), INT32_C( 1832272682), INT32_C( -100358742), INT32_C( 1797905164)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   366.70), SIMDE_FLOAT32_C(   615.81), SIMDE_FLOAT32_C(  -673.63), SIMDE_FLOAT32_C(   832.55),
                         SIMDE_FLOAT32_C(   260.08), SIMDE_FLOAT32_C(  -412.45), SIMDE_FLOAT32_C(   245.05), SIMDE_FLOAT32_C(  -913.68),
                         SIMDE_FLOAT32_C(    79.71), SIMDE_FLOAT32_C(  -761.86), SIMDE_FLOAT32_C(   699.75), SIMDE_FLOAT32_C(   -94.00),
                         SIMDE_FLOAT32_C(   852.56), SIMDE_FLOAT32_C(  -583.72), SIMDE_FLOAT32_C(    64.51), SIMDE_FLOAT32_C(   598.44)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -792.04), SIMDE_FLOAT32_C(   379.62), SIMDE_FLOAT32_C(    64.51), SIMDE_FLOAT32_C(  -317.53),
                         SIMDE_FLOAT32_C(  -798.29), SIMDE_FLOAT32_C(   615.81), SIMDE_FLOAT32_C(   -94.00), SIMDE_FLOAT32_C(  -583.72),
                         SIMDE_FLOAT32_C(   245.05), SIMDE_FLOAT32_C(  -723.48), SIMDE_FLOAT32_C(  -276.00), SIMDE_FLOAT32_C(   778.00),
                         SIMDE_FLOAT32_C(  -268.82), SIMDE_FLOAT32_C(   906.86), SIMDE_FLOAT32_C(   906.86), SIMDE_FLOAT32_C(  -792.04)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -976.85), SIMDE_FLOAT32_C(   321.59), SIMDE_FLOAT32_C(   867.83), SIMDE_FLOAT32_C(   831.83),
                         SIMDE_FLOAT32_C(  -570.45), SIMDE_FLOAT32_C(  -732.92), SIMDE_FLOAT32_C(  -964.15), SIMDE_FLOAT32_C(   -39.63),
                         SIMDE_FLOAT32_C(   579.20), SIMDE_FLOAT32_C(  -391.63), SIMDE_FLOAT32_C(   335.63), SIMDE_FLOAT32_C(   738.93),
                         SIMDE_FLOAT32_C(   439.69), SIMDE_FLOAT32_C(   930.40), SIMDE_FLOAT32_C(   273.66), SIMDE_FLOAT32_C(   892.54)),
      simde_mm512_set_epi32(INT32_C( 1604291666), INT32_C( -491791926), INT32_C( 1819084879), INT32_C( 1431978307),
                            INT32_C( 1530613877), INT32_C(-1009988233), INT32_C( 1309545588), INT32_C(-1001207300),
                            INT32_C(-1909714099), INT32_C(-1031553759), INT32_C(-1195513362), INT32_C(  957243291),
                            INT32_C( 1576721253), INT32_C( 1170763213), INT32_C( 1280754757), INT32_C(-1670630534)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   162.47), SIMDE_FLOAT32_C(   307.15), SIMDE_FLOAT32_C(  -851.38), SIMDE_FLOAT32_C(  -956.87),
                         SIMDE_FLOAT32_C(  -932.93), SIMDE_FLOAT32_C(   757.55), SIMDE_FLOAT32_C(  -934.19), SIMDE_FLOAT32_C(   361.60),
                         SIMDE_FLOAT32_C(  -239.16), SIMDE_FLOAT32_C(  -204.61), SIMDE_FLOAT32_C(   200.64), SIMDE_FLOAT32_C(  -634.66),
                         SIMDE_FLOAT32_C(   607.08), SIMDE_FLOAT32_C(  -668.91), SIMDE_FLOAT32_C(  -886.74), SIMDE_FLOAT32_C(  -214.28)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -668.91), SIMDE_FLOAT32_C(  -732.92), SIMDE_FLOAT32_C(  -976.85), SIMDE_FLOAT32_C(   439.69),
                         SIMDE_FLOAT32_C(   200.64), SIMDE_FLOAT32_C(  -239.16), SIMDE_FLOAT32_C(  -634.66), SIMDE_FLOAT32_C(  -956.87),
                         SIMDE_FLOAT32_C(   867.83), SIMDE_FLOAT32_C(   273.66), SIMDE_FLOAT32_C(   321.59), SIMDE_FLOAT32_C(  -932.93),
                         SIMDE_FLOAT32_C(   335.63), SIMDE_FLOAT32_C(   867.83), SIMDE_FLOAT32_C(   335.63), SIMDE_FLOAT32_C(   757.55)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -824.86), SIMDE_FLOAT32_C(   954.86), SIMDE_FLOAT32_C(   523.67), SIMDE_FLOAT32_C(  -253.94),
                         SIMDE_FLOAT32_C(   437.48), SIMDE_FLOAT32_C(    79.48), SIMDE_FLOAT32_C(  -371.31), SIMDE_FLOAT32_C(   -36.35),
                         SIMDE_FLOAT32_C(   288.58), SIMDE_FLOAT32_C(   274.36), SIMDE_FLOAT32_C(  -249.54), SIMDE_FLOAT32_C(   805.73),
                         SIMDE_FLOAT32_C(    29.94), SIMDE_FLOAT32_C(  -149.48), SIMDE_FLOAT32_C(   141.90), SIMDE_FLOAT32_C(   -55.72)),
      simde_mm512_set_epi32(INT32_C( -769209677), INT32_C(  921385960), INT32_C(  426713309), INT32_C( 1823076507),
                            INT32_C( 1666223712), INT32_C( -194163626), INT32_C(  604266257), INT32_C( 1932526911),
                            INT32_C(   20183709), INT32_C(  818624505), INT32_C( 1023612212), INT32_C(-1113050305),
                            INT32_C( 1709269191), INT32_C( 2143041839), INT32_C( 1719176952), INT32_C( -353230679)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -657.43), SIMDE_FLOAT32_C(  -181.72), SIMDE_FLOAT32_C(  -893.09), SIMDE_FLOAT32_C(   985.74),
                         SIMDE_FLOAT32_C(  -488.89), SIMDE_FLOAT32_C(   683.50), SIMDE_FLOAT32_C(   297.36), SIMDE_FLOAT32_C(    88.61),
                         SIMDE_FLOAT32_C(   -14.68), SIMDE_FLOAT32_C(   451.12), SIMDE_FLOAT32_C(  -464.35), SIMDE_FLOAT32_C(    82.04),
                         SIMDE_FLOAT32_C(   -48.11), SIMDE_FLOAT32_C(   254.96), SIMDE_FLOAT32_C(  -161.09), SIMDE_FLOAT32_C(  -538.50)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -48.11), SIMDE_FLOAT32_C(   -36.35), SIMDE_FLOAT32_C(  -893.09), SIMDE_FLOAT32_C(  -488.89),
                         SIMDE_FLOAT32_C(   -55.72), SIMDE_FLOAT32_C(   451.12), SIMDE_FLOAT32_C(  -161.09), SIMDE_FLOAT32_C(  -657.43),
                         SIMDE_FLOAT32_C(  -893.09), SIMDE_FLOAT32_C(   297.36), SIMDE_FLOAT32_C(    82.04), SIMDE_FLOAT32_C(  -657.43),
                         SIMDE_FLOAT32_C(   288.58), SIMDE_FLOAT32_C(  -824.86), SIMDE_FLOAT32_C(    88.61), SIMDE_FLOAT32_C(  -371.31)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   645.39), SIMDE_FLOAT32_C(   -81.78), SIMDE_FLOAT32_C(   426.88), SIMDE_FLOAT32_C(   367.09),
                         SIMDE_FLOAT32_C(   269.97), SIMDE_FLOAT32_C(   513.55), SIMDE_FLOAT32_C(  -433.45), SIMDE_FLOAT32_C(  -401.21),
                         SIMDE_FLOAT32_C(  -679.71), SIMDE_FLOAT32_C(  -426.49), SIMDE_FLOAT32_C(  -878.06), SIMDE_FLOAT32_C(   441.47),
                         SIMDE_FLOAT32_C(  -137.95), SIMDE_FLOAT32_C(   177.44), SIMDE_FLOAT32_C(   -55.07), SIMDE_FLOAT32_C(  -581.76)),
      simde_mm512_set_epi32(INT32_C(  582660853), INT32_C(-1326740073), INT32_C( 1332684527), INT32_C(  720865928),
                            INT32_C( 1806675616), INT32_C( 1369928435), INT32_C( 2026484746), INT32_C(  939514243),
                            INT32_C( 1533779841), INT32_C( 1890230239), INT32_C(  631027080), INT32_C(  679389494),
                            INT32_C( 2030531254), INT32_C(   78143054), INT32_C( 1358587101), INT32_C( 1101843618)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -978.39), SIMDE_FLOAT32_C(  -650.69), SIMDE_FLOAT32_C(   796.63), SIMDE_FLOAT32_C(  -910.00),
                         SIMDE_FLOAT32_C(  -646.84), SIMDE_FLOAT32_C(  -538.44), SIMDE_FLOAT32_C(  -130.00), SIMDE_FLOAT32_C(  -692.07),
                         SIMDE_FLOAT32_C(  -408.06), SIMDE_FLOAT32_C(  -675.29), SIMDE_FLOAT32_C(  -359.85), SIMDE_FLOAT32_C(   775.91),
                         SIMDE_FLOAT32_C(  -262.33), SIMDE_FLOAT32_C(   878.38), SIMDE_FLOAT32_C(   212.22), SIMDE_FLOAT32_C(  -803.31)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -359.85), SIMDE_FLOAT32_C(  -408.06), SIMDE_FLOAT32_C(   645.39), SIMDE_FLOAT32_C(  -401.21),
                         SIMDE_FLOAT32_C(  -581.76), SIMDE_FLOAT32_C(  -262.33), SIMDE_FLOAT32_C(   513.55), SIMDE_FLOAT32_C(  -137.95),
                         SIMDE_FLOAT32_C(   -55.07), SIMDE_FLOAT32_C(  -978.39), SIMDE_FLOAT32_C(  -401.21), SIMDE_FLOAT32_C(  -675.29),
                         SIMDE_FLOAT32_C(  -675.29), SIMDE_FLOAT32_C(   -81.78), SIMDE_FLOAT32_C(   796.63), SIMDE_FLOAT32_C(   177.44)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_permutex2var_ps(test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    #if defined(__EMSCRIPTEN__)
    (void) r;
    #else
    simde_assert_m512_close(r, test_vec[i].r, 1);
    #endif
 }

  return 0;
}

static int
test_simde_mm512_mask_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__mmask16 k;
    simde__m512i idx;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   232.04), SIMDE_FLOAT32_C(   774.81), SIMDE_FLOAT32_C(  -599.01), SIMDE_FLOAT32_C(    69.04),
                         SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(  -839.80), SIMDE_FLOAT32_C(  -556.90),
                         SIMDE_FLOAT32_C(   160.98), SIMDE_FLOAT32_C(   391.82), SIMDE_FLOAT32_C(  -569.99), SIMDE_FLOAT32_C(  -327.63),
                         SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(  -135.52)),
      UINT16_C(45849),
      simde_mm512_set_epi32(INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373), INT32_C( -695949043),
                            INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093), INT32_C(-2045280751),
                            INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336), INT32_C(  564965997),
                            INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685), INT32_C( 1430356381)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(   309.91), SIMDE_FLOAT32_C(   846.15),
                         SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(  -860.98), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(   128.51),
                         SIMDE_FLOAT32_C(   522.06), SIMDE_FLOAT32_C(  -932.28), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -491.12),
                         SIMDE_FLOAT32_C(  -139.11), SIMDE_FLOAT32_C(  -268.86), SIMDE_FLOAT32_C(   -71.72), SIMDE_FLOAT32_C(    98.47)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(   774.81), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -599.01),
                         SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(   -71.72),
                         SIMDE_FLOAT32_C(   160.98), SIMDE_FLOAT32_C(   391.82), SIMDE_FLOAT32_C(  -569.99), SIMDE_FLOAT32_C(  -599.01),
                         SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(   309.91)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(  -617.12), SIMDE_FLOAT32_C(  -751.58), SIMDE_FLOAT32_C(   907.23),
                         SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(  -213.75), SIMDE_FLOAT32_C(   403.00), SIMDE_FLOAT32_C(  -198.67),
                         SIMDE_FLOAT32_C(   447.98), SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(   717.83), SIMDE_FLOAT32_C(  -489.88),
                         SIMDE_FLOAT32_C(   -37.49), SIMDE_FLOAT32_C(  -373.66), SIMDE_FLOAT32_C(  -292.35), SIMDE_FLOAT32_C(  -835.53)),
      UINT16_C(30259),
      simde_mm512_set_epi32(INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417),
                            INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662),
                            INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205), INT32_C( -839037220),
                            INT32_C(  499633910), INT32_C( -260167255), INT32_C(  884163960), INT32_C( -329275629)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   670.52), SIMDE_FLOAT32_C(   149.72), SIMDE_FLOAT32_C(   213.24), SIMDE_FLOAT32_C(  -577.36),
                         SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -934.92), SIMDE_FLOAT32_C(  -657.02), SIMDE_FLOAT32_C(  -629.37),
                         SIMDE_FLOAT32_C(   337.35), SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(  -744.41), SIMDE_FLOAT32_C(    39.32),
                         SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(  -490.28), SIMDE_FLOAT32_C(   841.53), SIMDE_FLOAT32_C(   526.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -657.02),
                         SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(  -751.58), SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(  -198.67),
                         SIMDE_FLOAT32_C(   447.98), SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(  -577.36),
                         SIMDE_FLOAT32_C(   -37.49), SIMDE_FLOAT32_C(  -373.66), SIMDE_FLOAT32_C(  -629.37), SIMDE_FLOAT32_C(    29.68)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   493.30), SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -619.50), SIMDE_FLOAT32_C(   952.47),
                         SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(   -68.16), SIMDE_FLOAT32_C(   717.69), SIMDE_FLOAT32_C(  -663.74),
                         SIMDE_FLOAT32_C(   179.29), SIMDE_FLOAT32_C(   989.70), SIMDE_FLOAT32_C(  -695.21), SIMDE_FLOAT32_C(  -786.23),
                         SIMDE_FLOAT32_C(   873.30), SIMDE_FLOAT32_C(   241.45), SIMDE_FLOAT32_C(  -432.13), SIMDE_FLOAT32_C(  -842.15)),
      UINT16_C(60970),
      simde_mm512_set_epi32(INT32_C(  204417556), INT32_C(-1329665093), INT32_C(-2039025377), INT32_C( 1639231015),
                            INT32_C( 1541217841), INT32_C( 1692413538), INT32_C(  738521275), INT32_C(  159429100),
                            INT32_C(  451955897), INT32_C(  181201098), INT32_C(  450627934), INT32_C( 2082954477),
                            INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946), INT32_C(-1087388220)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   835.54), SIMDE_FLOAT32_C(  -712.24), SIMDE_FLOAT32_C(   518.12),
                         SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(   487.08), SIMDE_FLOAT32_C(   180.78), SIMDE_FLOAT32_C(  -289.23),
                         SIMDE_FLOAT32_C(   918.52), SIMDE_FLOAT32_C(  -422.76), SIMDE_FLOAT32_C(  -433.33), SIMDE_FLOAT32_C(    48.49),
                         SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(  -820.22), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   952.47),
                         SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   241.45), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(  -663.74),
                         SIMDE_FLOAT32_C(   179.29), SIMDE_FLOAT32_C(   989.70), SIMDE_FLOAT32_C(   835.54), SIMDE_FLOAT32_C(  -786.23),
                         SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   241.45), SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -842.15)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -844.73), SIMDE_FLOAT32_C(   757.65), SIMDE_FLOAT32_C(   677.41), SIMDE_FLOAT32_C(  -352.24),
                         SIMDE_FLOAT32_C(  -479.79), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55), SIMDE_FLOAT32_C(  -388.47),
                         SIMDE_FLOAT32_C(  -643.43), SIMDE_FLOAT32_C(  -331.34), SIMDE_FLOAT32_C(    72.67), SIMDE_FLOAT32_C(  -870.79),
                         SIMDE_FLOAT32_C(  -722.44), SIMDE_FLOAT32_C(   529.44), SIMDE_FLOAT32_C(  -949.73), SIMDE_FLOAT32_C(   280.87)),
      UINT16_C(48011),
      simde_mm512_set_epi32(INT32_C( -811849174), INT32_C(-1510825074), INT32_C( 1897985966), INT32_C( 1445172644),
                            INT32_C( -193622280), INT32_C( 2097959091), INT32_C( -652080500), INT32_C( 1943026961),
                            INT32_C(  763848022), INT32_C(-2124387583), INT32_C(-1102663841), INT32_C(  712044568),
                            INT32_C( 1641785760), INT32_C( 1696516135), INT32_C(-1123374630), INT32_C( -181070601)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -53.79), SIMDE_FLOAT32_C(   703.31), SIMDE_FLOAT32_C(   930.79), SIMDE_FLOAT32_C(   111.33),
                         SIMDE_FLOAT32_C(  -176.75), SIMDE_FLOAT32_C(  -316.94), SIMDE_FLOAT32_C(   639.68), SIMDE_FLOAT32_C(  -783.00),
                         SIMDE_FLOAT32_C(  -102.18), SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(    22.93), SIMDE_FLOAT32_C(  -395.13),
                         SIMDE_FLOAT32_C(   145.63), SIMDE_FLOAT32_C(  -149.04), SIMDE_FLOAT32_C(   214.37), SIMDE_FLOAT32_C(  -453.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(   757.65), SIMDE_FLOAT32_C(   757.65), SIMDE_FLOAT32_C(  -870.79),
                         SIMDE_FLOAT32_C(  -783.00), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(  -352.24), SIMDE_FLOAT32_C(   214.37),
                         SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(  -331.34), SIMDE_FLOAT32_C(    72.67), SIMDE_FLOAT32_C(  -870.79),
                         SIMDE_FLOAT32_C(   280.87), SIMDE_FLOAT32_C(   529.44), SIMDE_FLOAT32_C(  -316.94), SIMDE_FLOAT32_C(  -102.18)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(   925.24), SIMDE_FLOAT32_C(   849.34),
                         SIMDE_FLOAT32_C(   112.68), SIMDE_FLOAT32_C(   -96.70), SIMDE_FLOAT32_C(   -44.05), SIMDE_FLOAT32_C(   432.42),
                         SIMDE_FLOAT32_C(   421.92), SIMDE_FLOAT32_C(   718.96), SIMDE_FLOAT32_C(  -864.59), SIMDE_FLOAT32_C(  -334.42),
                         SIMDE_FLOAT32_C(   660.53), SIMDE_FLOAT32_C(   748.73), SIMDE_FLOAT32_C(   996.15), SIMDE_FLOAT32_C(  -607.82)),
      UINT16_C(  903),
      simde_mm512_set_epi32(INT32_C( 1969107101), INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053),
                            INT32_C( 1035482990), INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639),
                            INT32_C( -638430290), INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613),
                            INT32_C(  165266600), INT32_C( -798384264), INT32_C( 1607584815), INT32_C(-1324336584)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   641.22), SIMDE_FLOAT32_C(  -747.07), SIMDE_FLOAT32_C(  -762.67), SIMDE_FLOAT32_C(   744.11),
                         SIMDE_FLOAT32_C(   350.11), SIMDE_FLOAT32_C(   409.27), SIMDE_FLOAT32_C(   481.83), SIMDE_FLOAT32_C(   601.37),
                         SIMDE_FLOAT32_C(  -660.24), SIMDE_FLOAT32_C(  -675.56), SIMDE_FLOAT32_C(  -194.09), SIMDE_FLOAT32_C(   149.22),
                         SIMDE_FLOAT32_C(   161.52), SIMDE_FLOAT32_C(   632.78), SIMDE_FLOAT32_C(   346.90), SIMDE_FLOAT32_C(  -777.05)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(   925.24), SIMDE_FLOAT32_C(   849.34),
                         SIMDE_FLOAT32_C(   112.68), SIMDE_FLOAT32_C(   -96.70), SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(   -44.05),
                         SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(   718.96), SIMDE_FLOAT32_C(  -864.59), SIMDE_FLOAT32_C(  -334.42),
                         SIMDE_FLOAT32_C(   660.53), SIMDE_FLOAT32_C(   601.37), SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(   601.37)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   211.34), SIMDE_FLOAT32_C(  -159.54), SIMDE_FLOAT32_C(   297.01), SIMDE_FLOAT32_C(   147.67),
                         SIMDE_FLOAT32_C(  -855.53), SIMDE_FLOAT32_C(   391.08), SIMDE_FLOAT32_C(  -710.54), SIMDE_FLOAT32_C(  -140.51),
                         SIMDE_FLOAT32_C(   346.36), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(   399.19), SIMDE_FLOAT32_C(  -291.83),
                         SIMDE_FLOAT32_C(   951.57), SIMDE_FLOAT32_C(   272.52), SIMDE_FLOAT32_C(  -735.05), SIMDE_FLOAT32_C(     5.84)),
      UINT16_C(  487),
      simde_mm512_set_epi32(INT32_C(-2094713086), INT32_C(  197529411), INT32_C( 1055036471), INT32_C(  351897115),
                            INT32_C( 1594003471), INT32_C(-1709813294), INT32_C( -133653364), INT32_C(  -51462036),
                            INT32_C(   46796230), INT32_C(  989301899), INT32_C( -691937914), INT32_C( 1667629581),
                            INT32_C( -496700661), INT32_C(-1318801755), INT32_C( 1076515270), INT32_C(-1757573505)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   739.21), SIMDE_FLOAT32_C(   355.61), SIMDE_FLOAT32_C(  -450.77), SIMDE_FLOAT32_C(   343.42),
                         SIMDE_FLOAT32_C(  -703.95), SIMDE_FLOAT32_C(   169.29), SIMDE_FLOAT32_C(   932.53), SIMDE_FLOAT32_C(  -653.71),
                         SIMDE_FLOAT32_C(   371.73), SIMDE_FLOAT32_C(   757.18), SIMDE_FLOAT32_C(   214.84), SIMDE_FLOAT32_C(   830.24),
                         SIMDE_FLOAT32_C(   903.53), SIMDE_FLOAT32_C(  -831.08), SIMDE_FLOAT32_C(   815.07), SIMDE_FLOAT32_C(   196.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   211.34), SIMDE_FLOAT32_C(  -159.54), SIMDE_FLOAT32_C(   297.01), SIMDE_FLOAT32_C(   147.67),
                         SIMDE_FLOAT32_C(  -855.53), SIMDE_FLOAT32_C(   391.08), SIMDE_FLOAT32_C(  -710.54), SIMDE_FLOAT32_C(   147.67),
                         SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(  -855.53), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(  -291.83),
                         SIMDE_FLOAT32_C(   951.57), SIMDE_FLOAT32_C(   399.19), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(   739.21)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -482.01), SIMDE_FLOAT32_C(   218.00), SIMDE_FLOAT32_C(   412.00), SIMDE_FLOAT32_C(   409.50),
                         SIMDE_FLOAT32_C(  -290.29), SIMDE_FLOAT32_C(   337.59), SIMDE_FLOAT32_C(  -137.98), SIMDE_FLOAT32_C(   723.06),
                         SIMDE_FLOAT32_C(  -632.02), SIMDE_FLOAT32_C(   769.08), SIMDE_FLOAT32_C(  -269.22), SIMDE_FLOAT32_C(   771.53),
                         SIMDE_FLOAT32_C(   554.20), SIMDE_FLOAT32_C(   154.86), SIMDE_FLOAT32_C(   918.01), SIMDE_FLOAT32_C(   348.86)),
      UINT16_C(21630),
      simde_mm512_set_epi32(INT32_C( -501257427), INT32_C(-1329431510), INT32_C( 1005777948), INT32_C(  616430734),
                            INT32_C( 1581162255), INT32_C( 1497456456), INT32_C(-1170808415), INT32_C(-1014503666),
                            INT32_C(-1157750165), INT32_C( 1691363299), INT32_C( 1100655145), INT32_C(  673265711),
                            INT32_C( 1544659928), INT32_C(-1956803094), INT32_C( 1970109422), INT32_C(-1197844366)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   904.77), SIMDE_FLOAT32_C(   -16.01), SIMDE_FLOAT32_C(    -8.87), SIMDE_FLOAT32_C(  -521.88),
                         SIMDE_FLOAT32_C(  -842.76), SIMDE_FLOAT32_C(   871.64), SIMDE_FLOAT32_C(   769.47), SIMDE_FLOAT32_C(  -997.66),
                         SIMDE_FLOAT32_C(   691.39), SIMDE_FLOAT32_C(   987.54), SIMDE_FLOAT32_C(  -288.94), SIMDE_FLOAT32_C(   506.40),
                         SIMDE_FLOAT32_C(  -318.39), SIMDE_FLOAT32_C(  -477.43), SIMDE_FLOAT32_C(   119.12), SIMDE_FLOAT32_C(   397.77)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -482.01), SIMDE_FLOAT32_C(   337.59), SIMDE_FLOAT32_C(   412.00), SIMDE_FLOAT32_C(   218.00),
                         SIMDE_FLOAT32_C(  -290.29), SIMDE_FLOAT32_C(   723.06), SIMDE_FLOAT32_C(  -137.98), SIMDE_FLOAT32_C(   723.06),
                         SIMDE_FLOAT32_C(  -632.02), SIMDE_FLOAT32_C(   554.20), SIMDE_FLOAT32_C(  -137.98), SIMDE_FLOAT32_C(  -482.01),
                         SIMDE_FLOAT32_C(  -997.66), SIMDE_FLOAT32_C(   337.59), SIMDE_FLOAT32_C(   218.00), SIMDE_FLOAT32_C(   348.86)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -714.57), SIMDE_FLOAT32_C(  -728.75), SIMDE_FLOAT32_C(  -712.01), SIMDE_FLOAT32_C(  -346.18),
                         SIMDE_FLOAT32_C(   238.27), SIMDE_FLOAT32_C(  -879.28), SIMDE_FLOAT32_C(  -391.86), SIMDE_FLOAT32_C(  -824.42),
                         SIMDE_FLOAT32_C(   939.74), SIMDE_FLOAT32_C(   471.05), SIMDE_FLOAT32_C(  -276.21), SIMDE_FLOAT32_C(   528.15),
                         SIMDE_FLOAT32_C(   113.46), SIMDE_FLOAT32_C(   829.33), SIMDE_FLOAT32_C(  -265.53), SIMDE_FLOAT32_C(  -933.24)),
      UINT16_C(42527),
      simde_mm512_set_epi32(INT32_C( -675362282), INT32_C(-1218762696), INT32_C(-1400182216), INT32_C(-2088680370),
                            INT32_C(-1895497877), INT32_C( 1563893931), INT32_C( 1105770515), INT32_C(-1745770541),
                            INT32_C(-1255255240), INT32_C( 1238532704), INT32_C(  995946229), INT32_C(  119517601),
                            INT32_C( 1389614040), INT32_C(-2032996348), INT32_C( 1996749952), INT32_C(  450477794)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   705.41), SIMDE_FLOAT32_C(  -150.22), SIMDE_FLOAT32_C(   115.26), SIMDE_FLOAT32_C(  -433.46),
                         SIMDE_FLOAT32_C(  -112.53), SIMDE_FLOAT32_C(  -754.09), SIMDE_FLOAT32_C(  -873.63), SIMDE_FLOAT32_C(  -546.06),
                         SIMDE_FLOAT32_C(   126.79), SIMDE_FLOAT32_C(  -885.01), SIMDE_FLOAT32_C(   749.00), SIMDE_FLOAT32_C(  -249.67),
                         SIMDE_FLOAT32_C(  -471.39), SIMDE_FLOAT32_C(  -437.78), SIMDE_FLOAT32_C(  -357.63), SIMDE_FLOAT32_C(   772.54)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -885.01), SIMDE_FLOAT32_C(  -728.75), SIMDE_FLOAT32_C(  -546.06), SIMDE_FLOAT32_C(  -346.18),
                         SIMDE_FLOAT32_C(   238.27), SIMDE_FLOAT32_C(   238.27), SIMDE_FLOAT32_C(  -471.39), SIMDE_FLOAT32_C(  -824.42),
                         SIMDE_FLOAT32_C(   939.74), SIMDE_FLOAT32_C(   471.05), SIMDE_FLOAT32_C(  -276.21), SIMDE_FLOAT32_C(  -265.53),
                         SIMDE_FLOAT32_C(  -546.06), SIMDE_FLOAT32_C(   528.15), SIMDE_FLOAT32_C(  -933.24), SIMDE_FLOAT32_C(   829.33)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_permutex2var_ps(test_vec[i].a, test_vec[i].k, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
 }

  return 0;
}

static int
test_simde_mm512_mask2_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__m512i idx;
    simde__mmask16 k;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   877.96), SIMDE_FLOAT32_C(   184.43), SIMDE_FLOAT32_C(   375.34), SIMDE_FLOAT32_C(   389.76),
                         SIMDE_FLOAT32_C(   437.16), SIMDE_FLOAT32_C(  -638.93), SIMDE_FLOAT32_C(   773.45), SIMDE_FLOAT32_C(   109.31),
                         SIMDE_FLOAT32_C(   824.77), SIMDE_FLOAT32_C(   172.30), SIMDE_FLOAT32_C(  -660.39), SIMDE_FLOAT32_C(  -605.88),
                         SIMDE_FLOAT32_C(  -689.22), SIMDE_FLOAT32_C(   -25.12), SIMDE_FLOAT32_C(   921.58), SIMDE_FLOAT32_C(   433.31)),
      simde_mm512_set_epi32(INT32_C( 1145310577), INT32_C( 1144464671), INT32_C(-1000882995), INT32_C(-1015975772),
                            INT32_C(-1012966359), INT32_C( 1142785802), INT32_C(-1004452250), INT32_C(-1016706499),
                            INT32_C( 1148133540), INT32_C( 1143775396), INT32_C( 1145653494), INT32_C( 1092154819),
                            INT32_C(-1002177167), INT32_C( 1142945710), INT32_C(-1005107118), INT32_C(-1003331748)),
      UINT16_C( 7750),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   467.94), SIMDE_FLOAT32_C(   141.60), SIMDE_FLOAT32_C(    23.96), SIMDE_FLOAT32_C(  -171.38),
                         SIMDE_FLOAT32_C(  -106.17), SIMDE_FLOAT32_C(  -737.60), SIMDE_FLOAT32_C(  -140.98), SIMDE_FLOAT32_C(  -735.83),
                         SIMDE_FLOAT32_C(  -867.63), SIMDE_FLOAT32_C(   -65.75), SIMDE_FLOAT32_C(   137.16), SIMDE_FLOAT32_C(   -73.36),
                         SIMDE_FLOAT32_C(  -396.53), SIMDE_FLOAT32_C(  -409.15), SIMDE_FLOAT32_C(   672.29), SIMDE_FLOAT32_C(   992.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   784.21), SIMDE_FLOAT32_C(   732.58), SIMDE_FLOAT32_C(  -862.95), SIMDE_FLOAT32_C(  -605.88),
                         SIMDE_FLOAT32_C(   773.45), SIMDE_FLOAT32_C(  -638.93), SIMDE_FLOAT32_C(   172.30), SIMDE_FLOAT32_C(  -230.29),
                         SIMDE_FLOAT32_C(   956.51), SIMDE_FLOAT32_C(  -605.88), SIMDE_FLOAT32_C(   805.14), SIMDE_FLOAT32_C(     9.56),
                         SIMDE_FLOAT32_C(  -783.96), SIMDE_FLOAT32_C(   184.43), SIMDE_FLOAT32_C(  -409.15), SIMDE_FLOAT32_C(  -713.49)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -200.75), SIMDE_FLOAT32_C(  -165.75), SIMDE_FLOAT32_C(  -249.91), SIMDE_FLOAT32_C(  -394.72),
                         SIMDE_FLOAT32_C(   706.66), SIMDE_FLOAT32_C(  -789.81), SIMDE_FLOAT32_C(  -218.09), SIMDE_FLOAT32_C(  -475.08),
                         SIMDE_FLOAT32_C(   601.08), SIMDE_FLOAT32_C(  -590.62), SIMDE_FLOAT32_C(   446.98), SIMDE_FLOAT32_C(    51.90),
                         SIMDE_FLOAT32_C(   597.18), SIMDE_FLOAT32_C(   -19.20), SIMDE_FLOAT32_C(  -536.51), SIMDE_FLOAT32_C(   510.31)),
      simde_mm512_set_epi32(INT32_C( 1141430682), INT32_C( -998721126), INT32_C(-1006378189), INT32_C( 1133601096),
                            INT32_C(-1001273426), INT32_C( 1143976919), INT32_C(-1023309251), INT32_C( 1140917043),
                            INT32_C( 1146448282), INT32_C( 1140298875), INT32_C( -998775030), INT32_C( 1123123200),
                            INT32_C(-1008623616), INT32_C(-1003229512), INT32_C(-1013737062), INT32_C( 1137376297)),
      UINT16_C(36885),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   985.03), SIMDE_FLOAT32_C(   291.60), SIMDE_FLOAT32_C(  -732.66), SIMDE_FLOAT32_C(   106.36),
                         SIMDE_FLOAT32_C(   883.40), SIMDE_FLOAT32_C(     8.63), SIMDE_FLOAT32_C(   178.77), SIMDE_FLOAT32_C(  -118.91),
                         SIMDE_FLOAT32_C(  -944.88), SIMDE_FLOAT32_C(  -743.12), SIMDE_FLOAT32_C(   752.91), SIMDE_FLOAT32_C(  -489.26),
                         SIMDE_FLOAT32_C(   163.33), SIMDE_FLOAT32_C(   566.34), SIMDE_FLOAT32_C(  -175.54), SIMDE_FLOAT32_C(  -823.41)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     8.63), SIMDE_FLOAT32_C(  -994.90), SIMDE_FLOAT32_C(  -527.55), SIMDE_FLOAT32_C(  -475.08),
                         SIMDE_FLOAT32_C(  -839.12), SIMDE_FLOAT32_C(   702.81), SIMDE_FLOAT32_C(  -129.54), SIMDE_FLOAT32_C(   516.05),
                         SIMDE_FLOAT32_C(   853.65), SIMDE_FLOAT32_C(   495.16), SIMDE_FLOAT32_C(  -991.61), SIMDE_FLOAT32_C(   510.31),
                         SIMDE_FLOAT32_C(  -451.25), SIMDE_FLOAT32_C(  -118.91), SIMDE_FLOAT32_C(  -295.20), SIMDE_FLOAT32_C(  -218.09)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -242.78), SIMDE_FLOAT32_C(   250.83), SIMDE_FLOAT32_C(  -818.85), SIMDE_FLOAT32_C(  -959.57),
                         SIMDE_FLOAT32_C(   925.03), SIMDE_FLOAT32_C(  -644.70), SIMDE_FLOAT32_C(  -800.67), SIMDE_FLOAT32_C(   914.15),
                         SIMDE_FLOAT32_C(   333.29), SIMDE_FLOAT32_C(   760.10), SIMDE_FLOAT32_C(   397.05), SIMDE_FLOAT32_C(   356.22),
                         SIMDE_FLOAT32_C(    -4.35), SIMDE_FLOAT32_C(   408.12), SIMDE_FLOAT32_C(    89.10), SIMDE_FLOAT32_C(   557.43)),
      simde_mm512_set_epi32(INT32_C(-1000840397), INT32_C(-1014681108), INT32_C(-1002009723), INT32_C(-1001187082),
                            INT32_C(-1005810811), INT32_C(-1019216527), INT32_C( -999992852), INT32_C(-1002857595),
                            INT32_C( 1126940672), INT32_C( 1147155743), INT32_C( 1136568238), INT32_C(-1008068198),
                            INT32_C(-1019846328), INT32_C(-1004496650), INT32_C(-1000071004), INT32_C(-1004023153)),
      UINT16_C( 3523),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -645.40), SIMDE_FLOAT32_C(  -442.29), SIMDE_FLOAT32_C(  -336.85), SIMDE_FLOAT32_C(  -152.85),
                         SIMDE_FLOAT32_C(  -363.79), SIMDE_FLOAT32_C(  -614.03), SIMDE_FLOAT32_C(  -923.13), SIMDE_FLOAT32_C(   985.40),
                         SIMDE_FLOAT32_C(  -733.70), SIMDE_FLOAT32_C(   -80.62), SIMDE_FLOAT32_C(   200.37), SIMDE_FLOAT32_C(  -613.00),
                         SIMDE_FLOAT32_C(  -530.37), SIMDE_FLOAT32_C(   940.29), SIMDE_FLOAT32_C(  -837.65), SIMDE_FLOAT32_C(  -127.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -865.55), SIMDE_FLOAT32_C(  -266.39), SIMDE_FLOAT32_C(  -794.18), SIMDE_FLOAT32_C(  -844.39),
                         SIMDE_FLOAT32_C(   397.05), SIMDE_FLOAT32_C(  -837.65), SIMDE_FLOAT32_C(  -917.28), SIMDE_FLOAT32_C(   397.05),
                         SIMDE_FLOAT32_C(   557.43), SIMDE_FLOAT32_C(  -645.40), SIMDE_FLOAT32_C(   381.31), SIMDE_FLOAT32_C(  -468.20),
                         SIMDE_FLOAT32_C(  -182.38), SIMDE_FLOAT32_C(  -642.39), SIMDE_FLOAT32_C(   356.22), SIMDE_FLOAT32_C(  -242.78)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   419.61), SIMDE_FLOAT32_C(  -753.42), SIMDE_FLOAT32_C(   687.05), SIMDE_FLOAT32_C(   241.87),
                         SIMDE_FLOAT32_C(   -80.26), SIMDE_FLOAT32_C(  -667.68), SIMDE_FLOAT32_C(   776.25), SIMDE_FLOAT32_C(  -748.43),
                         SIMDE_FLOAT32_C(   -53.25), SIMDE_FLOAT32_C(  -132.01), SIMDE_FLOAT32_C(  -767.78), SIMDE_FLOAT32_C(    -9.36),
                         SIMDE_FLOAT32_C(  -226.72), SIMDE_FLOAT32_C(  -661.68), SIMDE_FLOAT32_C(  -655.84), SIMDE_FLOAT32_C(  -744.21)),
      simde_mm512_set_epi32(INT32_C( -998850560), INT32_C( 1143600415), INT32_C(-1000731771), INT32_C( 1114277151),
                            INT32_C(-1010340332), INT32_C(-1001651732), INT32_C( 1143390372), INT32_C( 1119634063),
                            INT32_C(-1019717222), INT32_C(-1031045120), INT32_C(-1011098255), INT32_C( 1132600689),
                            INT32_C(-1010611978), INT32_C( 1128936899), INT32_C(-1001749053), INT32_C( 1140980122)),
      UINT16_C(37204),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -518.52), SIMDE_FLOAT32_C(   431.51), SIMDE_FLOAT32_C(    99.29), SIMDE_FLOAT32_C(   936.82),
                         SIMDE_FLOAT32_C(   -99.13), SIMDE_FLOAT32_C(  -566.48), SIMDE_FLOAT32_C(   699.34), SIMDE_FLOAT32_C(   845.75),
                         SIMDE_FLOAT32_C(    43.86), SIMDE_FLOAT32_C(  -170.77), SIMDE_FLOAT32_C(   428.74), SIMDE_FLOAT32_C(   695.01),
                         SIMDE_FLOAT32_C(  -702.60), SIMDE_FLOAT32_C(  -231.45), SIMDE_FLOAT32_C(  -416.99), SIMDE_FLOAT32_C(   838.71)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -744.21), SIMDE_FLOAT32_C(   679.83), SIMDE_FLOAT32_C(  -872.18), SIMDE_FLOAT32_C(  -518.52),
                         SIMDE_FLOAT32_C(  -398.86), SIMDE_FLOAT32_C(  -816.03), SIMDE_FLOAT32_C(   667.01), SIMDE_FLOAT32_C(   419.61),
                         SIMDE_FLOAT32_C(  -184.35), SIMDE_FLOAT32_C(  -744.21), SIMDE_FLOAT32_C(  -375.73), SIMDE_FLOAT32_C(  -416.99),
                         SIMDE_FLOAT32_C(  -390.57), SIMDE_FLOAT32_C(  -226.72), SIMDE_FLOAT32_C(  -810.09), SIMDE_FLOAT32_C(   519.90)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   924.35), SIMDE_FLOAT32_C(  -647.29), SIMDE_FLOAT32_C(  -651.10), SIMDE_FLOAT32_C(   678.72),
                         SIMDE_FLOAT32_C(   318.50), SIMDE_FLOAT32_C(   607.02), SIMDE_FLOAT32_C(   959.46), SIMDE_FLOAT32_C(   708.40),
                         SIMDE_FLOAT32_C(   684.78), SIMDE_FLOAT32_C(   938.65), SIMDE_FLOAT32_C(    79.72), SIMDE_FLOAT32_C(  -367.19),
                         SIMDE_FLOAT32_C(  -848.84), SIMDE_FLOAT32_C(  -319.22), SIMDE_FLOAT32_C(   807.26), SIMDE_FLOAT32_C(  -797.03)),
      simde_mm512_set_epi32(INT32_C( 1144478269), INT32_C(-1014431089), INT32_C( 1145887785), INT32_C(-1000062648),
                            INT32_C(-1004164383), INT32_C(-1038973665), INT32_C(-1013049590), INT32_C( 1139362365),
                            INT32_C( 1143090545), INT32_C( 1142120612), INT32_C(-1031333478), INT32_C( 1146798899),
                            INT32_C( 1148490383), INT32_C( 1146840351), INT32_C(-1034768876), INT32_C(-1003322081)),
      UINT16_C(41858),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   538.68), SIMDE_FLOAT32_C(  -878.56), SIMDE_FLOAT32_C(    48.75), SIMDE_FLOAT32_C(  -299.81),
                         SIMDE_FLOAT32_C(  -177.03), SIMDE_FLOAT32_C(  -530.47), SIMDE_FLOAT32_C(   848.40), SIMDE_FLOAT32_C(  -491.55),
                         SIMDE_FLOAT32_C(   978.68), SIMDE_FLOAT32_C(   838.38), SIMDE_FLOAT32_C(   198.53), SIMDE_FLOAT32_C(  -129.15),
                         SIMDE_FLOAT32_C(  -588.91), SIMDE_FLOAT32_C(   399.94), SIMDE_FLOAT32_C(    44.96), SIMDE_FLOAT32_C(   312.31)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    48.75), SIMDE_FLOAT32_C(  -274.02), SIMDE_FLOAT32_C(   959.46), SIMDE_FLOAT32_C(  -913.02),
                         SIMDE_FLOAT32_C(  -662.67), SIMDE_FLOAT32_C(   -36.63), SIMDE_FLOAT32_C(   607.02), SIMDE_FLOAT32_C(    48.75),
                         SIMDE_FLOAT32_C(    44.96), SIMDE_FLOAT32_C(   589.51), SIMDE_FLOAT32_C(   -67.55), SIMDE_FLOAT32_C(   875.05),
                         SIMDE_FLOAT32_C(   978.29), SIMDE_FLOAT32_C(   877.58), SIMDE_FLOAT32_C(  -129.15), SIMDE_FLOAT32_C(  -714.08)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -944.36), SIMDE_FLOAT32_C(  -838.63), SIMDE_FLOAT32_C(    38.26), SIMDE_FLOAT32_C(  -152.44),
                         SIMDE_FLOAT32_C(   946.95), SIMDE_FLOAT32_C(  -423.59), SIMDE_FLOAT32_C(  -297.05), SIMDE_FLOAT32_C(  -205.88),
                         SIMDE_FLOAT32_C(  -253.64), SIMDE_FLOAT32_C(  -501.33), SIMDE_FLOAT32_C(   -37.12), SIMDE_FLOAT32_C(  -369.82),
                         SIMDE_FLOAT32_C(  -496.81), SIMDE_FLOAT32_C(   -47.73), SIMDE_FLOAT32_C(  -743.25), SIMDE_FLOAT32_C(  -913.65)),
      simde_mm512_set_epi32(INT32_C( 1148280996), INT32_C( 1141096448), INT32_C( 1147594179), INT32_C( 1133745603),
                            INT32_C( 1142890004), INT32_C(-1013119386), INT32_C( 1142369157), INT32_C( 1137598792),
                            INT32_C( -999746929), INT32_C(-1011464274), INT32_C( 1136544645), INT32_C( 1147671675),
                            INT32_C( 1148562964), INT32_C( 1137554883), INT32_C(-1006904934), INT32_C(-1018696172)),
      UINT16_C(58593),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -84.19), SIMDE_FLOAT32_C(   399.10), SIMDE_FLOAT32_C(  -610.29), SIMDE_FLOAT32_C(   149.87),
                         SIMDE_FLOAT32_C(   820.28), SIMDE_FLOAT32_C(  -278.06), SIMDE_FLOAT32_C(   765.67), SIMDE_FLOAT32_C(   664.38),
                         SIMDE_FLOAT32_C(  -117.33), SIMDE_FLOAT32_C(   617.04), SIMDE_FLOAT32_C(   690.47), SIMDE_FLOAT32_C(   983.05),
                         SIMDE_FLOAT32_C(   980.92), SIMDE_FLOAT32_C(  -996.65), SIMDE_FLOAT32_C(   209.60), SIMDE_FLOAT32_C(  -480.53)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -369.82), SIMDE_FLOAT32_C(  -913.65), SIMDE_FLOAT32_C(  -496.81), SIMDE_FLOAT32_C(   295.17),
                         SIMDE_FLOAT32_C(   636.47), SIMDE_FLOAT32_C(  -501.33), SIMDE_FLOAT32_C(   604.68), SIMDE_FLOAT32_C(   412.76),
                         SIMDE_FLOAT32_C(  -944.36), SIMDE_FLOAT32_C(  -838.63), SIMDE_FLOAT32_C(   -37.12), SIMDE_FLOAT32_C(   928.32),
                         SIMDE_FLOAT32_C(   982.72), SIMDE_FLOAT32_C(   411.42), SIMDE_FLOAT32_C(  -503.70), SIMDE_FLOAT32_C(   983.05)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -918.50), SIMDE_FLOAT32_C(  -515.44), SIMDE_FLOAT32_C(  -137.15), SIMDE_FLOAT32_C(   561.32),
                         SIMDE_FLOAT32_C(   501.72), SIMDE_FLOAT32_C(  -843.67), SIMDE_FLOAT32_C(  -326.79), SIMDE_FLOAT32_C(   106.60),
                         SIMDE_FLOAT32_C(   380.78), SIMDE_FLOAT32_C(     2.64), SIMDE_FLOAT32_C(  -699.45), SIMDE_FLOAT32_C(   503.17),
                         SIMDE_FLOAT32_C(  -803.82), SIMDE_FLOAT32_C(    78.52), SIMDE_FLOAT32_C(   647.26), SIMDE_FLOAT32_C(  -393.01)),
      simde_mm512_set_epi32(INT32_C( -999928627), INT32_C( 1129960571), INT32_C( 1099662623), INT32_C(-1017545359),
                            INT32_C( -999118602), INT32_C( 1144669635), INT32_C(-1000925266), INT32_C(-1002151281),
                            INT32_C(-1020877210), INT32_C(-1027625452), INT32_C(-1004458476), INT32_C(-1004674089),
                            INT32_C(-1004804342), INT32_C( 1143535534), INT32_C( 1125517230), INT32_C( 1132990300)),
      UINT16_C(14071),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -663.05), SIMDE_FLOAT32_C(  -657.03), SIMDE_FLOAT32_C(  -368.45), SIMDE_FLOAT32_C(   822.35),
                         SIMDE_FLOAT32_C(   469.97), SIMDE_FLOAT32_C(   973.10), SIMDE_FLOAT32_C(   419.44), SIMDE_FLOAT32_C(  -510.97),
                         SIMDE_FLOAT32_C(  -448.70), SIMDE_FLOAT32_C(  -780.36), SIMDE_FLOAT32_C(   722.25), SIMDE_FLOAT32_C(   745.47),
                         SIMDE_FLOAT32_C(   381.61), SIMDE_FLOAT32_C(   670.39), SIMDE_FLOAT32_C(    71.28), SIMDE_FLOAT32_C(  -178.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -921.20), SIMDE_FLOAT32_C(   217.83), SIMDE_FLOAT32_C(  -663.05), SIMDE_FLOAT32_C(    71.28),
                         SIMDE_FLOAT32_C(  -970.64), SIMDE_FLOAT32_C(  -803.82), SIMDE_FLOAT32_C(  -515.44), SIMDE_FLOAT32_C(  -785.54),
                         SIMDE_FLOAT32_C(     2.64), SIMDE_FLOAT32_C(   745.47), SIMDE_FLOAT32_C(   745.47), SIMDE_FLOAT32_C(  -448.70),
                         SIMDE_FLOAT32_C(  -623.61), SIMDE_FLOAT32_C(  -515.44), SIMDE_FLOAT32_C(  -515.44), SIMDE_FLOAT32_C(   822.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -199.95), SIMDE_FLOAT32_C(  -694.07), SIMDE_FLOAT32_C(   741.25), SIMDE_FLOAT32_C(  -612.71),
                         SIMDE_FLOAT32_C(   316.26), SIMDE_FLOAT32_C(  -621.79), SIMDE_FLOAT32_C(   163.37), SIMDE_FLOAT32_C(   389.35),
                         SIMDE_FLOAT32_C(   146.51), SIMDE_FLOAT32_C(   723.78), SIMDE_FLOAT32_C(   687.77), SIMDE_FLOAT32_C(   582.14),
                         SIMDE_FLOAT32_C(   891.09), SIMDE_FLOAT32_C(  -226.06), SIMDE_FLOAT32_C(   206.62), SIMDE_FLOAT32_C(   608.43)),
      simde_mm512_set_epi32(INT32_C( 1143844536), INT32_C(-1020415181), INT32_C(-1053032448), INT32_C( 1138942607),
                            INT32_C( 1134596915), INT32_C( 1146536264), INT32_C( 1145270436), INT32_C( 1147929395),
                            INT32_C( 1143444111), INT32_C( 1126843679), INT32_C(-1004511724), INT32_C( 1141078753),
                            INT32_C(-1010149949), INT32_C(-1005574062), INT32_C(-1016484332), INT32_C(-1003633050)),
      UINT16_C(28924),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   725.47), SIMDE_FLOAT32_C(   989.71), SIMDE_FLOAT32_C(   233.61), SIMDE_FLOAT32_C(   876.86),
                         SIMDE_FLOAT32_C(  -135.15), SIMDE_FLOAT32_C(   476.19), SIMDE_FLOAT32_C(   231.31), SIMDE_FLOAT32_C(   -79.03),
                         SIMDE_FLOAT32_C(  -501.37), SIMDE_FLOAT32_C(   310.62), SIMDE_FLOAT32_C(   652.20), SIMDE_FLOAT32_C(  -426.66),
                         SIMDE_FLOAT32_C(  -323.40), SIMDE_FLOAT32_C(  -305.08), SIMDE_FLOAT32_C(    -4.94), SIMDE_FLOAT32_C(   -30.71)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   694.73), SIMDE_FLOAT32_C(  -323.40), SIMDE_FLOAT32_C(   608.43), SIMDE_FLOAT32_C(  -199.95),
                         SIMDE_FLOAT32_C(   321.15), SIMDE_FLOAT32_C(   859.02), SIMDE_FLOAT32_C(   781.76), SIMDE_FLOAT32_C(   944.05),
                         SIMDE_FLOAT32_C(  -199.95), SIMDE_FLOAT32_C(   725.47), SIMDE_FLOAT32_C(  -426.66), SIMDE_FLOAT32_C(   206.62),
                         SIMDE_FLOAT32_C(   891.09), SIMDE_FLOAT32_C(  -305.08), SIMDE_FLOAT32_C(  -233.68), SIMDE_FLOAT32_C(  -695.10)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask2_permutex2var_ps(test_vec[i].a, test_vec[i].idx, test_vec[i].k, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
 }

  return 0;
}

static int
test_simde_mm512_maskz_permutex2var_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512i idx;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { UINT16_C(45849),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   232.04), SIMDE_FLOAT32_C(   774.81), SIMDE_FLOAT32_C(  -599.01), SIMDE_FLOAT32_C(    69.04),
                         SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(  -839.80), SIMDE_FLOAT32_C(  -556.90),
                         SIMDE_FLOAT32_C(   160.98), SIMDE_FLOAT32_C(   391.82), SIMDE_FLOAT32_C(  -569.99), SIMDE_FLOAT32_C(  -327.63),
                         SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(  -135.52)),
      simde_mm512_set_epi32(INT32_C( 1711460779), INT32_C( -919570191), INT32_C( 1974152373), INT32_C( -695949043),
                            INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093), INT32_C(-2045280751),
                            INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336), INT32_C(  564965997),
                            INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685), INT32_C( 1430356381)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(   309.91), SIMDE_FLOAT32_C(   846.15),
                         SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(  -860.98), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(   128.51),
                         SIMDE_FLOAT32_C(   522.06), SIMDE_FLOAT32_C(  -932.28), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -491.12),
                         SIMDE_FLOAT32_C(  -139.11), SIMDE_FLOAT32_C(  -268.86), SIMDE_FLOAT32_C(   -71.72), SIMDE_FLOAT32_C(    98.47)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -599.01),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(   -71.72),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -599.01),
                         SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   309.91)) },
    { UINT16_C(30259),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(  -617.12), SIMDE_FLOAT32_C(  -751.58), SIMDE_FLOAT32_C(   907.23),
                         SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(  -213.75), SIMDE_FLOAT32_C(   403.00), SIMDE_FLOAT32_C(  -198.67),
                         SIMDE_FLOAT32_C(   447.98), SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(   717.83), SIMDE_FLOAT32_C(  -489.88),
                         SIMDE_FLOAT32_C(   -37.49), SIMDE_FLOAT32_C(  -373.66), SIMDE_FLOAT32_C(  -292.35), SIMDE_FLOAT32_C(  -835.53)),
      simde_mm512_set_epi32(INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417),
                            INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662),
                            INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205), INT32_C( -839037220),
                            INT32_C(  499633910), INT32_C( -260167255), INT32_C(  884163960), INT32_C( -329275629)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   670.52), SIMDE_FLOAT32_C(   149.72), SIMDE_FLOAT32_C(   213.24), SIMDE_FLOAT32_C(  -577.36),
                         SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -934.92), SIMDE_FLOAT32_C(  -657.02), SIMDE_FLOAT32_C(  -629.37),
                         SIMDE_FLOAT32_C(   337.35), SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(  -744.41), SIMDE_FLOAT32_C(    39.32),
                         SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(  -490.28), SIMDE_FLOAT32_C(   841.53), SIMDE_FLOAT32_C(   526.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -657.02),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -751.58), SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(  -577.36),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -629.37), SIMDE_FLOAT32_C(    29.68)) },
    { UINT16_C(60970),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   493.30), SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -619.50), SIMDE_FLOAT32_C(   952.47),
                         SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(   -68.16), SIMDE_FLOAT32_C(   717.69), SIMDE_FLOAT32_C(  -663.74),
                         SIMDE_FLOAT32_C(   179.29), SIMDE_FLOAT32_C(   989.70), SIMDE_FLOAT32_C(  -695.21), SIMDE_FLOAT32_C(  -786.23),
                         SIMDE_FLOAT32_C(   873.30), SIMDE_FLOAT32_C(   241.45), SIMDE_FLOAT32_C(  -432.13), SIMDE_FLOAT32_C(  -842.15)),
      simde_mm512_set_epi32(INT32_C(  204417556), INT32_C(-1329665093), INT32_C(-2039025377), INT32_C( 1639231015),
                            INT32_C( 1541217841), INT32_C( 1692413538), INT32_C(  738521275), INT32_C(  159429100),
                            INT32_C(  451955897), INT32_C(  181201098), INT32_C(  450627934), INT32_C( 2082954477),
                            INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946), INT32_C(-1087388220)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   835.54), SIMDE_FLOAT32_C(  -712.24), SIMDE_FLOAT32_C(   518.12),
                         SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(   487.08), SIMDE_FLOAT32_C(   180.78), SIMDE_FLOAT32_C(  -289.23),
                         SIMDE_FLOAT32_C(   918.52), SIMDE_FLOAT32_C(  -422.76), SIMDE_FLOAT32_C(  -433.33), SIMDE_FLOAT32_C(    48.49),
                         SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(  -820.22), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   241.45), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   835.54), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C(48011),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -844.73), SIMDE_FLOAT32_C(   757.65), SIMDE_FLOAT32_C(   677.41), SIMDE_FLOAT32_C(  -352.24),
                         SIMDE_FLOAT32_C(  -479.79), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55), SIMDE_FLOAT32_C(  -388.47),
                         SIMDE_FLOAT32_C(  -643.43), SIMDE_FLOAT32_C(  -331.34), SIMDE_FLOAT32_C(    72.67), SIMDE_FLOAT32_C(  -870.79),
                         SIMDE_FLOAT32_C(  -722.44), SIMDE_FLOAT32_C(   529.44), SIMDE_FLOAT32_C(  -949.73), SIMDE_FLOAT32_C(   280.87)),
      simde_mm512_set_epi32(INT32_C( -811849174), INT32_C(-1510825074), INT32_C( 1897985966), INT32_C( 1445172644),
                            INT32_C( -193622280), INT32_C( 2097959091), INT32_C( -652080500), INT32_C( 1943026961),
                            INT32_C(  763848022), INT32_C(-2124387583), INT32_C(-1102663841), INT32_C(  712044568),
                            INT32_C( 1641785760), INT32_C( 1696516135), INT32_C(-1123374630), INT32_C( -181070601)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -53.79), SIMDE_FLOAT32_C(   703.31), SIMDE_FLOAT32_C(   930.79), SIMDE_FLOAT32_C(   111.33),
                         SIMDE_FLOAT32_C(  -176.75), SIMDE_FLOAT32_C(  -316.94), SIMDE_FLOAT32_C(   639.68), SIMDE_FLOAT32_C(  -783.00),
                         SIMDE_FLOAT32_C(  -102.18), SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(    22.93), SIMDE_FLOAT32_C(  -395.13),
                         SIMDE_FLOAT32_C(   145.63), SIMDE_FLOAT32_C(  -149.04), SIMDE_FLOAT32_C(   214.37), SIMDE_FLOAT32_C(  -453.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   757.65), SIMDE_FLOAT32_C(  -870.79),
                         SIMDE_FLOAT32_C(  -783.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -352.24), SIMDE_FLOAT32_C(   214.37),
                         SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   280.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -316.94), SIMDE_FLOAT32_C(  -102.18)) },
    { UINT16_C(  903),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(   925.24), SIMDE_FLOAT32_C(   849.34),
                         SIMDE_FLOAT32_C(   112.68), SIMDE_FLOAT32_C(   -96.70), SIMDE_FLOAT32_C(   -44.05), SIMDE_FLOAT32_C(   432.42),
                         SIMDE_FLOAT32_C(   421.92), SIMDE_FLOAT32_C(   718.96), SIMDE_FLOAT32_C(  -864.59), SIMDE_FLOAT32_C(  -334.42),
                         SIMDE_FLOAT32_C(   660.53), SIMDE_FLOAT32_C(   748.73), SIMDE_FLOAT32_C(   996.15), SIMDE_FLOAT32_C(  -607.82)),
      simde_mm512_set_epi32(INT32_C( 1969107101), INT32_C(-2063427243), INT32_C( -670405092), INT32_C(-1879729053),
                            INT32_C( 1035482990), INT32_C( 1183910939), INT32_C( 1515345934), INT32_C(-1884003639),
                            INT32_C( -638430290), INT32_C(-2007622482), INT32_C(  171336877), INT32_C(   59553613),
                            INT32_C(  165266600), INT32_C( -798384264), INT32_C( 1607584815), INT32_C(-1324336584)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   641.22), SIMDE_FLOAT32_C(  -747.07), SIMDE_FLOAT32_C(  -762.67), SIMDE_FLOAT32_C(   744.11),
                         SIMDE_FLOAT32_C(   350.11), SIMDE_FLOAT32_C(   409.27), SIMDE_FLOAT32_C(   481.83), SIMDE_FLOAT32_C(   601.37),
                         SIMDE_FLOAT32_C(  -660.24), SIMDE_FLOAT32_C(  -675.56), SIMDE_FLOAT32_C(  -194.09), SIMDE_FLOAT32_C(   149.22),
                         SIMDE_FLOAT32_C(   161.52), SIMDE_FLOAT32_C(   632.78), SIMDE_FLOAT32_C(   346.90), SIMDE_FLOAT32_C(  -777.05)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(   -44.05),
                         SIMDE_FLOAT32_C(   813.86), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   601.37), SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(   601.37)) },
    { UINT16_C(  487),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   211.34), SIMDE_FLOAT32_C(  -159.54), SIMDE_FLOAT32_C(   297.01), SIMDE_FLOAT32_C(   147.67),
                         SIMDE_FLOAT32_C(  -855.53), SIMDE_FLOAT32_C(   391.08), SIMDE_FLOAT32_C(  -710.54), SIMDE_FLOAT32_C(  -140.51),
                         SIMDE_FLOAT32_C(   346.36), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(   399.19), SIMDE_FLOAT32_C(  -291.83),
                         SIMDE_FLOAT32_C(   951.57), SIMDE_FLOAT32_C(   272.52), SIMDE_FLOAT32_C(  -735.05), SIMDE_FLOAT32_C(     5.84)),
      simde_mm512_set_epi32(INT32_C(-2094713086), INT32_C(  197529411), INT32_C( 1055036471), INT32_C(  351897115),
                            INT32_C( 1594003471), INT32_C(-1709813294), INT32_C( -133653364), INT32_C(  -51462036),
                            INT32_C(   46796230), INT32_C(  989301899), INT32_C( -691937914), INT32_C( 1667629581),
                            INT32_C( -496700661), INT32_C(-1318801755), INT32_C( 1076515270), INT32_C(-1757573505)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   739.21), SIMDE_FLOAT32_C(   355.61), SIMDE_FLOAT32_C(  -450.77), SIMDE_FLOAT32_C(   343.42),
                         SIMDE_FLOAT32_C(  -703.95), SIMDE_FLOAT32_C(   169.29), SIMDE_FLOAT32_C(   932.53), SIMDE_FLOAT32_C(  -653.71),
                         SIMDE_FLOAT32_C(   371.73), SIMDE_FLOAT32_C(   757.18), SIMDE_FLOAT32_C(   214.84), SIMDE_FLOAT32_C(   830.24),
                         SIMDE_FLOAT32_C(   903.53), SIMDE_FLOAT32_C(  -831.08), SIMDE_FLOAT32_C(   815.07), SIMDE_FLOAT32_C(   196.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   147.67),
                         SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(  -855.53), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   399.19), SIMDE_FLOAT32_C(   318.14), SIMDE_FLOAT32_C(   739.21)) },
    { UINT16_C(21630),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -482.01), SIMDE_FLOAT32_C(   218.00), SIMDE_FLOAT32_C(   412.00), SIMDE_FLOAT32_C(   409.50),
                         SIMDE_FLOAT32_C(  -290.29), SIMDE_FLOAT32_C(   337.59), SIMDE_FLOAT32_C(  -137.98), SIMDE_FLOAT32_C(   723.06),
                         SIMDE_FLOAT32_C(  -632.02), SIMDE_FLOAT32_C(   769.08), SIMDE_FLOAT32_C(  -269.22), SIMDE_FLOAT32_C(   771.53),
                         SIMDE_FLOAT32_C(   554.20), SIMDE_FLOAT32_C(   154.86), SIMDE_FLOAT32_C(   918.01), SIMDE_FLOAT32_C(   348.86)),
      simde_mm512_set_epi32(INT32_C( -501257427), INT32_C(-1329431510), INT32_C( 1005777948), INT32_C(  616430734),
                            INT32_C( 1581162255), INT32_C( 1497456456), INT32_C(-1170808415), INT32_C(-1014503666),
                            INT32_C(-1157750165), INT32_C( 1691363299), INT32_C( 1100655145), INT32_C(  673265711),
                            INT32_C( 1544659928), INT32_C(-1956803094), INT32_C( 1970109422), INT32_C(-1197844366)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   904.77), SIMDE_FLOAT32_C(   -16.01), SIMDE_FLOAT32_C(    -8.87), SIMDE_FLOAT32_C(  -521.88),
                         SIMDE_FLOAT32_C(  -842.76), SIMDE_FLOAT32_C(   871.64), SIMDE_FLOAT32_C(   769.47), SIMDE_FLOAT32_C(  -997.66),
                         SIMDE_FLOAT32_C(   691.39), SIMDE_FLOAT32_C(   987.54), SIMDE_FLOAT32_C(  -288.94), SIMDE_FLOAT32_C(   506.40),
                         SIMDE_FLOAT32_C(  -318.39), SIMDE_FLOAT32_C(  -477.43), SIMDE_FLOAT32_C(   119.12), SIMDE_FLOAT32_C(   397.77)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   337.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   218.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   723.06), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   554.20), SIMDE_FLOAT32_C(  -137.98), SIMDE_FLOAT32_C(  -482.01),
                         SIMDE_FLOAT32_C(  -997.66), SIMDE_FLOAT32_C(   337.59), SIMDE_FLOAT32_C(   218.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C(42527),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -714.57), SIMDE_FLOAT32_C(  -728.75), SIMDE_FLOAT32_C(  -712.01), SIMDE_FLOAT32_C(  -346.18),
                         SIMDE_FLOAT32_C(   238.27), SIMDE_FLOAT32_C(  -879.28), SIMDE_FLOAT32_C(  -391.86), SIMDE_FLOAT32_C(  -824.42),
                         SIMDE_FLOAT32_C(   939.74), SIMDE_FLOAT32_C(   471.05), SIMDE_FLOAT32_C(  -276.21), SIMDE_FLOAT32_C(   528.15),
                         SIMDE_FLOAT32_C(   113.46), SIMDE_FLOAT32_C(   829.33), SIMDE_FLOAT32_C(  -265.53), SIMDE_FLOAT32_C(  -933.24)),
      simde_mm512_set_epi32(INT32_C( -675362282), INT32_C(-1218762696), INT32_C(-1400182216), INT32_C(-2088680370),
                            INT32_C(-1895497877), INT32_C( 1563893931), INT32_C( 1105770515), INT32_C(-1745770541),
                            INT32_C(-1255255240), INT32_C( 1238532704), INT32_C(  995946229), INT32_C(  119517601),
                            INT32_C( 1389614040), INT32_C(-2032996348), INT32_C( 1996749952), INT32_C(  450477794)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   705.41), SIMDE_FLOAT32_C(  -150.22), SIMDE_FLOAT32_C(   115.26), SIMDE_FLOAT32_C(  -433.46),
                         SIMDE_FLOAT32_C(  -112.53), SIMDE_FLOAT32_C(  -754.09), SIMDE_FLOAT32_C(  -873.63), SIMDE_FLOAT32_C(  -546.06),
                         SIMDE_FLOAT32_C(   126.79), SIMDE_FLOAT32_C(  -885.01), SIMDE_FLOAT32_C(   749.00), SIMDE_FLOAT32_C(  -249.67),
                         SIMDE_FLOAT32_C(  -471.39), SIMDE_FLOAT32_C(  -437.78), SIMDE_FLOAT32_C(  -357.63), SIMDE_FLOAT32_C(   772.54)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -885.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -546.06), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   238.27), SIMDE_FLOAT32_C(  -471.39), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -265.53),
                         SIMDE_FLOAT32_C(  -546.06), SIMDE_FLOAT32_C(   528.15), SIMDE_FLOAT32_C(  -933.24), SIMDE_FLOAT32_C(   829.33)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_maskz_permutex2var_ps(test_vec[i].k, test_vec[i].a, test_vec[i].idx, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
 }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask2_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutex2var_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask2_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutex2var_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask2_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutex2var_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask2_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutex2var_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask2_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutex2var_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask2_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_permutex2var_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask2_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutex2var_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask2_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutex2var_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask2_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutex2var_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask2_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutex2var_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask2_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutex2var_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask2_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_permutex2var_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask2_permutex2var_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutex2var_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask2_permutex2var_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutex2var_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask2_permutex2var_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutex2var_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask2_permutex2var_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutex2var_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask2_permutex2var_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutex2var_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask2_permutex2var_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_permutex2var_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
