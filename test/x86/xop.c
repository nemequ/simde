/* Copyright (c) 2020 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX xop
#include <simde/x86/xop.h>
#include <test/x86/test-avx.h>

static int
test_simde_mm_cmov_si128 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   500254467), -INT32_C(   199025237), -INT32_C(   819815926), -INT32_C(  1605995992) },
      { -INT32_C(   723927998),  INT32_C(  2062677536), -INT32_C(  1465824605),  INT32_C(   443551646) },
      {  INT32_C(   487232486), -INT32_C(  1422518099), -INT32_C(   670557173),  INT32_C(  1834540766) },
      { -INT32_C(   573493502), -INT32_C(   253493591), -INT32_C(   392078678),  INT32_C(   845173512) } },
    { { -INT32_C(   764207660),  INT32_C(   823075782), -INT32_C(   662371768), -INT32_C(   549839234) },
      {  INT32_C(   190769969), -INT32_C(   203753439),  INT32_C(  1635986845), -INT32_C(    74165934) },
      {  INT32_C(   593219169),  INT32_C(   456309172),  INT32_C(  1840319889), -INT32_C(  1977469073) },
      {  INT32_C(   173485392), -INT32_C(   238395003),  INT32_C(  1216552972), -INT32_C(    71936386) } },
    { { -INT32_C(  1321871351),  INT32_C(   318162610),  INT32_C(   888886504), -INT32_C(  1797074133) },
      { -INT32_C(  1879353328), -INT32_C(  2126397295),  INT32_C(   797962919),  INT32_C(  1645241371) },
      { -INT32_C(   705109608),  INT32_C(  1366395142),  INT32_C(   400038163),  INT32_C(  2116709394) },
      { -INT32_C(  1691101176), -INT32_C(  1871658861),  INT32_C(  1021309604),  INT32_C(   338837515) } },
    { { -INT32_C(   575061495), -INT32_C(  1423687419), -INT32_C(   444253775), -INT32_C(  1326666713) },
      {  INT32_C(  1074630150), -INT32_C(   130725435), -INT32_C(   746388409),  INT32_C(    39069103) },
      { -INT32_C(   671148939), -INT32_C(   507297094),  INT32_C(  1509780440), -INT32_C(  1130489794) },
      { -INT32_C(   709260797), -INT32_C(  1187755707), -INT32_C(  1014551145), -INT32_C(  1295241817) } },
    { { -INT32_C(  1159895173),  INT32_C(  1328090776),  INT32_C(   811769515),  INT32_C(  1749550505) },
      {  INT32_C(  1127503740),  INT32_C(  1795608149),  INT32_C(  1365118788), -INT32_C(   837833210) },
      {  INT32_C(   198243614), -INT32_C(  1640636121), -INT32_C(   169972120), -INT32_C(   118549335) },
      {  INT32_C(  1257531258),  INT32_C(  1864568400),  INT32_C(   809635628),  INT32_C(  1850257071) } },
    { { -INT32_C(   356543931), -INT32_C(  1865028991), -INT32_C(  1777292004),  INT32_C(   774207527) },
      { -INT32_C(    95437033),  INT32_C(   742508825), -INT32_C(   329188187), -INT32_C(    97559722) },
      { -INT32_C(  1811264007), -INT32_C(  1709661980), -INT32_C(   260321911),  INT32_C(   617184842) },
      { -INT32_C(   363875769), -INT32_C(  1269700199), -INT32_C(  1676624596), -INT32_C(    30967530) } },
    { {  INT32_C(  1354780047),  INT32_C(  1110822678), -INT32_C(   615591541), -INT32_C(  1242439335) },
      {  INT32_C(   142348735), -INT32_C(   810027226),  INT32_C(   638056626), -INT32_C(   136001769) },
      { -INT32_C(   712234834),  INT32_C(   687471304), -INT32_C(  1961790398),  INT32_C(  1914613593) },
      {  INT32_C(  1492130207), -INT32_C(   952643802), -INT32_C(  1358505806), -INT32_C(  1242504865) } },
    { {  INT32_C(   276653248),  INT32_C(  2023422192),  INT32_C(    35435968), -INT32_C(   262382795) },
      {  INT32_C(  1360844699),  INT32_C(   645288660), -INT32_C(  1005425167),  INT32_C(  2040318975) },
      {  INT32_C(  1920323875), -INT32_C(   592860694),  INT32_C(  1243778522),  INT32_C(  1461404237) },
      {  INT32_C(   293422744),  INT32_C(  2061433588), -INT32_C(  2045712927),  INT32_C(  2023541687) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_cmov_si128(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_cmov_si128(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmov_si256 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const int32_t c[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  2048228304), -INT32_C(   943376558),  INT32_C(   916505603), -INT32_C(  1560329864),  INT32_C(  1119380968),  INT32_C(   798876684),  INT32_C(   882820511), -INT32_C(  2078087596) },
      { -INT32_C(  1123480214),  INT32_C(  1199885892),  INT32_C(   175973522),  INT32_C(  1303149925), -INT32_C(   292526622), -INT32_C(   400741047),  INT32_C(  1193065714),  INT32_C(   231423906) },
      { -INT32_C(  1865755316),  INT32_C(   920145571), -INT32_C(   666872462), -INT32_C(  1272582702), -INT32_C(  1683835566), -INT32_C(   712785694),  INT32_C(   505192316),  INT32_C(   707520478) },
      { -INT32_C(  1379169246),  INT32_C(  1204061766),  INT32_C(   306013314), -INT32_C(   374517387),  INT32_C(  1722836448),  INT32_C(   765324553),  INT32_C(  1427940766),  INT32_C(    98762356) } },
    { {  INT32_C(  1622930876), -INT32_C(  1231645885), -INT32_C(  1148266776),  INT32_C(   359642051),  INT32_C(  1269830249),  INT32_C(  1310733266), -INT32_C(  1318306605), -INT32_C(   522414044) },
      { -INT32_C(   784296051),  INT32_C(   310892074),  INT32_C(  1892488621),  INT32_C(   830881224),  INT32_C(   561854031),  INT32_C(  1030724970), -INT32_C(    17900582),  INT32_C(    31378035) },
      { -INT32_C(  1949163679), -INT32_C(  1566680587),  INT32_C(   907242350), -INT32_C(   144139864),  INT32_C(   957933007),  INT32_C(  1551271810), -INT32_C(   698718877), -INT32_C(  1848166097) },
      {  INT32_C(  1351783852), -INT32_C(  1298688181),  INT32_C(  1926125289),  INT32_C(   367965632),  INT32_C(   158667337),  INT32_C(  1831410666), -INT32_C(  1192444197), -INT32_C(  2133009804) } },
    { {  INT32_C(  1293723992),  INT32_C(  1894824450), -INT32_C(   827915482),  INT32_C(  1808142236),  INT32_C(  1990582004), -INT32_C(   908911770), -INT32_C(  1331745408), -INT32_C(  1103005850) },
      {  INT32_C(   588012832),  INT32_C(  1049885720), -INT32_C(  1693697281),  INT32_C(  1023857225),  INT32_C(   397716401),  INT32_C(  1205897159),  INT32_C(   469204916),  INT32_C(   400111862) },
      { -INT32_C(  1371871850), -INT32_C(   521351711),  INT32_C(  1367078920),  INT32_C(  2089779915), -INT32_C(   191675603),  INT32_C(  2117891018), -INT32_C(   375835662),  INT32_C(    33583980) },
      {  INT32_C(   219986224),  INT32_C(  2129901592), -INT32_C(   903413001),  INT32_C(  1770410632),  INT32_C(  2007362228),  INT32_C(  1238406983), -INT32_C(  1291883132),  INT32_C(   400129014) } },
    { {  INT32_C(   984627800),  INT32_C(   253402119),  INT32_C(  1600231060),  INT32_C(  1172041752), -INT32_C(    46502349), -INT32_C(   730106143),  INT32_C(   364713385), -INT32_C(   535315064) },
      { -INT32_C(    31799305), -INT32_C(   133286557), -INT32_C(   480809013), -INT32_C(  1842859169), -INT32_C(  2087755103), -INT32_C(  2108224808), -INT32_C(  1483271137), -INT32_C(   930566191) },
      { -INT32_C(   624516490), -INT32_C(  1563241257), -INT32_C(  1568331453), -INT32_C(    30101924), -INT32_C(   377371888), -INT32_C(   311699250), -INT32_C(  1114307860),  INT32_C(   679812529) },
      {  INT32_C(  1050175441),  INT32_C(  1511961895),  INT32_C(  1129531016),  INT32_C(  1142468891), -INT32_C(   351378767), -INT32_C(   964734256),  INT32_C(   395777211), -INT32_C(   535969856) } },
    { { -INT32_C(  1761457217),  INT32_C(  1664734240),  INT32_C(  1510391805),  INT32_C(  2102934125), -INT32_C(   865674754), -INT32_C(  1648766543), -INT32_C(  2057679148),  INT32_C(   732815211) },
      {  INT32_C(  1254272810), -INT32_C(  2119238781),  INT32_C(   668710074), -INT32_C(   324717586), -INT32_C(  1112012020), -INT32_C(  1319472419),  INT32_C(   741782720), -INT32_C(  1118313325) },
      {  INT32_C(   386406803), -INT32_C(   812075500),  INT32_C(  1492546410), -INT32_C(  1304061018), -INT32_C(  2073035353),  INT32_C(   808831343),  INT32_C(   274492285), -INT32_C(   473058481) },
      {  INT32_C(  1606594491),  INT32_C(  1128193411),  INT32_C(  2131736568),  INT32_C(  2095069804), -INT32_C(  1107895378), -INT32_C(  1854147663),  INT32_C(   746249940),  INT32_C(  1067440091) } },
    { { -INT32_C(   520432180), -INT32_C(   173043061), -INT32_C(  1420909051), -INT32_C(   396520639),  INT32_C(     7130256),  INT32_C(   305176981),  INT32_C(  1545767949),  INT32_C(   188739391) },
      {  INT32_C(  1357593029), -INT32_C(   800678965), -INT32_C(  2105830335), -INT32_C(  1217669081),  INT32_C(   968349604), -INT32_C(  2041845895), -INT32_C(  1293783693),  INT32_C(   582820445) },
      {  INT32_C(   661825883), -INT32_C(  2047363004),  INT32_C(  1929868108), -INT32_C(   265588149), -INT32_C(  1020665270),  INT32_C(  1028224458),  INT32_C(  1072704482), -INT32_C(  1453216435) },
      {  INT32_C(  1895535052), -INT32_C(   710438005), -INT32_C(  1551981051), -INT32_C(   414606747),  INT32_C(   952030628), -INT32_C(  1845320783), -INT32_C(  1675473903),  INT32_C(   196980509) } },
    { { -INT32_C(  1697590186), -INT32_C(   652228724), -INT32_C(  2041829574), -INT32_C(   478775399),  INT32_C(   614899546), -INT32_C(   144576748),  INT32_C(  1748390171),  INT32_C(  1427216639) },
      { -INT32_C(   118431380), -INT32_C(   472838231), -INT32_C(   798417354), -INT32_C(   273424491), -INT32_C(  1827448193),  INT32_C(  1686795593), -INT32_C(   976371258), -INT32_C(   988029351) },
      {  INT32_C(  1773996992),  INT32_C(  1363971866),  INT32_C(  1109505709),  INT32_C(   338875541),  INT32_C(  2024293678), -INT32_C(  2116275526),  INT32_C(  1279699443),  INT32_C(  1209098632) },
      { -INT32_C(  1731141524), -INT32_C(   207779927), -INT32_C(  1840763334), -INT32_C(   340566127), -INT32_C(  1548542117), -INT32_C(   448633007), -INT32_C(   913358569), -INT32_C(   988045607) } },
    { { -INT32_C(  2018390164),  INT32_C(   198770014),  INT32_C(  1229846963), -INT32_C(    60981299),  INT32_C(  2138310085),  INT32_C(   721440824), -INT32_C(  2106046470),  INT32_C(   365595048) },
      { -INT32_C(  1231258792),  INT32_C(   750875768),  INT32_C(   980750189),  INT32_C(  1396101774),  INT32_C(   282307288), -INT32_C(   180628485), -INT32_C(  1015565542), -INT32_C(  1780989635) },
      {  INT32_C(   877425852),  INT32_C(  1432358376), -INT32_C(  1416637156), -INT32_C(  2130786648),  INT32_C(  1804652912), -INT32_C(  1084175451), -INT32_C(  1132275841), -INT32_C(   732866024) },
      { -INT32_C(  2037362836),  INT32_C(   700546392),  INT32_C(   427678577), -INT32_C(   748923250),  INT32_C(  2069048264),  INT32_C(  1796952186), -INT32_C(  1015715974),  INT32_C(   365431085) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i c = simde_mm256_loadu_epi32(test_vec[i].c);
    simde__m256i r = simde_mm256_cmov_si256(a, b, c);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i c = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_cmov_si256(a, b, c);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   9),  INT8_C(  95),  INT8_C(  12), -INT8_C(  23), -INT8_C(  38), -INT8_C(  37),  INT8_C(  12), -INT8_C(  46),
        -INT8_C(  96),  INT8_C(  66), -INT8_C(  19),  INT8_C(  41), -INT8_C(  21), -INT8_C(  79), -INT8_C(  19), -INT8_C( 122) },
      {  INT8_C(   9),  INT8_C(  95),  INT8_C(  12), -INT8_C(  23), -INT8_C(  38), -INT8_C(  37),  INT8_C(  12), -INT8_C(  46),
        -INT8_C(  96),  INT8_C(  66), -INT8_C(  19),  INT8_C(  41), -INT8_C(  21), -INT8_C(  79), -INT8_C(  19), -INT8_C( 122) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(   3),  INT8_C(  38), -INT8_C(  98),  INT8_C( 126),  INT8_C(  51), -INT8_C( 121), -INT8_C(  33), -INT8_C(  55),
         INT8_C( 103), -INT8_C(  25),  INT8_C(  11), -INT8_C(  92), -INT8_C(   6),  INT8_C(   6),  INT8_C( 112),  INT8_C( 117) },
      { -INT8_C(  55),  INT8_C(  22),  INT8_C(   3), -INT8_C(  82), -INT8_C( 116), -INT8_C(  59),  INT8_C(  81), -INT8_C(  13),
         INT8_C( 102),  INT8_C( 119), -INT8_C(  71),      INT8_MAX, -INT8_C(  70), -INT8_C(  45), -INT8_C(  39), -INT8_C(  60) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  65), -INT8_C( 126),  INT8_C(  70),  INT8_C(  81),  INT8_C(  89),  INT8_C(  51),      INT8_MIN, -INT8_C(   7),
        -INT8_C(  96), -INT8_C(  29),  INT8_C(  37),  INT8_C(  50), -INT8_C(  62),  INT8_C(  91),  INT8_C( 100), -INT8_C(  69) },
      { -INT8_C( 113), -INT8_C(   6), -INT8_C(  75), -INT8_C( 126),  INT8_C(  81), -INT8_C(  76), -INT8_C(  57), -INT8_C(  60),
         INT8_C(  92),  INT8_C(  91), -INT8_C(  70),  INT8_C( 118), -INT8_C(  26),  INT8_C(  29), -INT8_C( 113), -INT8_C(  28) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  25),  INT8_C(  79), -INT8_C(  35), -INT8_C( 104),  INT8_C( 103),  INT8_C( 105), -INT8_C(  59),  INT8_C( 125),
         INT8_C(  30),  INT8_C(  81),  INT8_C(  39),  INT8_C(  68),  INT8_C(  60), -INT8_C(  36),  INT8_C(  22),  INT8_C(   7) },
      { -INT8_C( 124), -INT8_C( 110), -INT8_C( 118),  INT8_C(  44), -INT8_C(  47), -INT8_C(  79),  INT8_C(  85), -INT8_C( 115),
        -INT8_C(  85),  INT8_C( 117),  INT8_C(  89), -INT8_C(  43),  INT8_C(  24), -INT8_C( 105), -INT8_C(   9),  INT8_C(  45) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  76),  INT8_C(  19), -INT8_C(  53),  INT8_C(  25),  INT8_C(   4),  INT8_C(  47), -INT8_C( 106), -INT8_C( 100),
         INT8_C(   8), -INT8_C(  71),  INT8_C( 123), -INT8_C(  93),  INT8_C(  15), -INT8_C( 112),  INT8_C( 111), -INT8_C(  95) },
      { -INT8_C(  49),  INT8_C( 102), -INT8_C(  21),  INT8_C( 118), -INT8_C(  75), -INT8_C(  61), -INT8_C(  29), -INT8_C( 107),
         INT8_C( 122),  INT8_C(  77), -INT8_C(   4),  INT8_C( 102), -INT8_C(   9),  INT8_C(  72), -INT8_C(   6), -INT8_C(  23) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  58),  INT8_C(  89),  INT8_C( 119), -INT8_C(  99), -INT8_C(  39), -INT8_C( 113), -INT8_C(  37), -INT8_C(  96),
        -INT8_C( 122), -INT8_C(  93), -INT8_C( 120),  INT8_C(  23), -INT8_C(  28),      INT8_MAX,  INT8_C(  85), -INT8_C(  48) },
      { -INT8_C( 102), -INT8_C(   2),  INT8_C(  62),  INT8_C(  38), -INT8_C(  91), -INT8_C(  13),  INT8_C(  90),  INT8_C(  37),
        -INT8_C(  14),  INT8_C( 108),  INT8_C(  13), -INT8_C(  17),  INT8_C(  44),  INT8_C(  56),  INT8_C( 126),  INT8_C(  94) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  45), -INT8_C(  90),  INT8_C(  75), -INT8_C(  21), -INT8_C( 114), -INT8_C( 112),  INT8_C( 124), -INT8_C(  49),
        -INT8_C(  62), -INT8_C( 104), -INT8_C(  74),  INT8_C( 104),  INT8_C(  99), -INT8_C(  78), -INT8_C(  79), -INT8_C(  35) },
      {  INT8_C(  10), -INT8_C(  29), -INT8_C(  20),  INT8_C(   5),  INT8_C(  72),  INT8_C(  72), -INT8_C(  96), -INT8_C( 123),
         INT8_C(  59),  INT8_C(  89), -INT8_C(  14),  INT8_C(  57),  INT8_C(  94),  INT8_C( 111),  INT8_C( 108), -INT8_C(  42) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  91), -INT8_C( 124), -INT8_C(  82), -INT8_C(  51), -INT8_C(  54),  INT8_C(  58),  INT8_C(  97),  INT8_C( 114),
        -INT8_C(  31),  INT8_C(  31),  INT8_C( 109),  INT8_C(  93),  INT8_C(  51),  INT8_C(  48),  INT8_C( 108),  INT8_C(  16) },
      {  INT8_C(  73), -INT8_C( 100),  INT8_C(  94), -INT8_C(  37),  INT8_C(  71), -INT8_C(  54), -INT8_C(  98), -INT8_C(   3),
         INT8_C( 124), -INT8_C( 100),  INT8_C(  21),  INT8_C(  12),  INT8_C(  54), -INT8_C(  10), -INT8_C(  83), -INT8_C( 105) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comeq_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 31451),  INT16_C(  2312), -INT16_C( 27083), -INT16_C( 12173), -INT16_C( 16114), -INT16_C( 16619),  INT16_C(   509), -INT16_C( 20116) },
      {  INT16_C( 31451),  INT16_C(  2312), -INT16_C( 27083), -INT16_C( 12173), -INT16_C( 16114), -INT16_C( 16619),  INT16_C(   509), -INT16_C( 20116) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 20097),  INT16_C( 28923), -INT16_C( 32439), -INT16_C( 10948), -INT16_C( 16675),  INT16_C( 12508), -INT16_C( 11172), -INT16_C(  5849) },
      {  INT16_C(  4507),  INT16_C( 26818), -INT16_C( 21640),  INT16_C( 13208),  INT16_C(  1391),  INT16_C( 22038),  INT16_C( 11880),  INT16_C(  2203) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 21805), -INT16_C( 29910),  INT16_C( 30455),  INT16_C( 21603),  INT16_C( 18055),  INT16_C( 27825),  INT16_C(  4471),  INT16_C(  5828) },
      { -INT16_C( 12531), -INT16_C( 19902), -INT16_C( 32197), -INT16_C(  7751),  INT16_C( 29484), -INT16_C(  5415), -INT16_C( 16867),  INT16_C( 24032) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  4206), -INT16_C(  2475), -INT16_C( 20231), -INT16_C( 15367), -INT16_C( 17246), -INT16_C( 30213), -INT16_C( 18897),  INT16_C( 25963) },
      {  INT16_C( 16219), -INT16_C( 20495),  INT16_C(  8485),  INT16_C(  9151), -INT16_C( 27794),  INT16_C( 17348), -INT16_C( 17981), -INT16_C(  2270) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 27512),  INT16_C( 30691),  INT16_C( 14326),  INT16_C( 27367), -INT16_C( 22187),  INT16_C( 20513), -INT16_C( 14034),  INT16_C(  7428) },
      { -INT16_C(  6486),  INT16_C(  9783), -INT16_C( 27937),  INT16_C( 16784), -INT16_C(  4515),  INT16_C( 10304),  INT16_C( 10243),  INT16_C(  8011) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 16664), -INT16_C( 10436),  INT16_C(  5271), -INT16_C( 28394), -INT16_C( 27447), -INT16_C( 31091),  INT16_C( 21785), -INT16_C( 30858) },
      {  INT16_C( 20005), -INT16_C(  7811), -INT16_C(  8943), -INT16_C( 31978),  INT16_C(  2848),  INT16_C( 25526),  INT16_C(  4741),  INT16_C(  7490) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  7286), -INT16_C(  8760),  INT16_C( 20099), -INT16_C( 32659),  INT16_C(  1318), -INT16_C(  2394),  INT16_C( 24475), -INT16_C(  5205) },
      { -INT16_C(   271), -INT16_C( 22999),  INT16_C(  2146),  INT16_C( 12599),  INT16_C( 29408), -INT16_C( 17780),  INT16_C( 32752),  INT16_C( 14831) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 31813),  INT16_C( 21486), -INT16_C(  4766),  INT16_C( 32467), -INT16_C( 31597),  INT16_C( 26580), -INT16_C(  3750), -INT16_C( 28278) },
      {  INT16_C( 32313),  INT16_C( 16037),  INT16_C(  7546), -INT16_C( 27939), -INT16_C( 21308), -INT16_C(  2516),  INT16_C( 30701), -INT16_C( 17606) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comeq_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(    15073521), -INT32_C(   718079266), -INT32_C(  1602250184), -INT32_C(  1057287426) },
      { -INT32_C(    15073521), -INT32_C(   718079266), -INT32_C(  1602250184), -INT32_C(  1057287426) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1901549347), -INT32_C(   269540606), -INT32_C(   537116427), -INT32_C(   368377053) },
      { -INT32_C(  1414654055), -INT32_C(   881755235),  INT32_C(  1779420734), -INT32_C(  1041839312) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   111743191), -INT32_C(  1873468510),  INT32_C(  1013364378),  INT32_C(   256518715) },
      {  INT32_C(   488002434), -INT32_C(  1451721913), -INT32_C(  1913869875), -INT32_C(   583851112) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   956157570), -INT32_C(  1107876863), -INT32_C(   674195492),  INT32_C(  1927280092) },
      {  INT32_C(   515455985), -INT32_C(  1221591163), -INT32_C(   780160500),  INT32_C(  1506484957) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  2060010048), -INT32_C(  1094897976),  INT32_C(  1990486755),  INT32_C(  1538419375) },
      {  INT32_C(  1979668495),  INT32_C(  1014895103), -INT32_C(    30510812), -INT32_C(  2137730905) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   395785148), -INT32_C(   628143714), -INT32_C(   498485290),  INT32_C(   313300059) },
      { -INT32_C(   330223356), -INT32_C(  2108835748), -INT32_C(   614306243), -INT32_C(  1720240480) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   649701453),  INT32_C(  1532329516), -INT32_C(   483981347), -INT32_C(   558663543) },
      {  INT32_C(  1226133239), -INT32_C(   813367996),  INT32_C(   830747261), -INT32_C(   346268818) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   365652404), -INT32_C(  2013801446),  INT32_C(  1084678178),  INT32_C(   162537697) },
      {  INT32_C(  1437939728),  INT32_C(  1812719201), -INT32_C(   923122673), -INT32_C(  1087617095) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comeq_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6386856271473046416), -INT64_C( 2770677996306117174) },
      { -INT64_C( 6386856271473046416), -INT64_C( 2770677996306117174) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 6788474568251574663),  INT64_C( 6759062096424348697) },
      {  INT64_C(  175365179203798799), -INT64_C( 7553141662136446208) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 5356527267312463785),  INT64_C(  948454573608432580) },
      { -INT64_C( 2155271835253202248), -INT64_C( 8467335260177564438) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C(  967758818504798251),  INT64_C( 1668311107114934327) },
      { -INT64_C( 8270831391516285293), -INT64_C(  260363254095917136) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 7032190541284410856), -INT64_C( 4418485408765625445) },
      {  INT64_C( 5530014961812003529),  INT64_C( 3730934318756385915) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(  150940866752567627),  INT64_C( 6388544662910520343) },
      {  INT64_C( 7462839796774061954),  INT64_C( 8687675780418114675) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 7388068351796983188),  INT64_C( 2304976088930770132) },
      {  INT64_C( 2780819029497181157),  INT64_C( 1416578837790889663) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1269734626711540763),  INT64_C( 6958671260799070969) },
      { -INT64_C( 3334082415450527717),  INT64_C( 5545782954997113480) },
      {  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comeq_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  9), UINT8_C(  1), UINT8_C( 63), UINT8_C( 11), UINT8_C( 67), UINT8_C( 52), UINT8_C( 70), UINT8_C( 77),
        UINT8_C(175), UINT8_C(151), UINT8_C(100), UINT8_C( 94), UINT8_C(124), UINT8_C(113), UINT8_C( 82), UINT8_C( 98) },
      { UINT8_C(  9), UINT8_C(  1), UINT8_C( 63), UINT8_C( 11), UINT8_C( 67), UINT8_C( 52), UINT8_C( 70), UINT8_C( 77),
        UINT8_C(175), UINT8_C(151), UINT8_C(100), UINT8_C( 94), UINT8_C(124), UINT8_C(113), UINT8_C( 82), UINT8_C( 98) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 75), UINT8_C(174), UINT8_C(221), UINT8_C( 60), UINT8_C(135), UINT8_C(223), UINT8_C(225), UINT8_C(175),
        UINT8_C(245), UINT8_C(129), UINT8_C(116), UINT8_C(195), UINT8_C(140), UINT8_C(130), UINT8_C( 98), UINT8_C(107) },
      { UINT8_C(134), UINT8_C(  1), UINT8_C(218), UINT8_C(100), UINT8_C(183), UINT8_C( 86), UINT8_C(102), UINT8_C( 96),
        UINT8_C( 30), UINT8_C( 82), UINT8_C( 32), UINT8_C(100), UINT8_C(186), UINT8_C(199), UINT8_C( 36), UINT8_C(111) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(158), UINT8_C( 75), UINT8_C( 65), UINT8_C( 92), UINT8_C( 72), UINT8_C( 58), UINT8_C(244), UINT8_C(  9),
        UINT8_C( 47), UINT8_C(250), UINT8_C(150), UINT8_C(185), UINT8_C(155), UINT8_C(131), UINT8_C(212), UINT8_C(183) },
      { UINT8_C(185), UINT8_C( 30), UINT8_C( 96), UINT8_C( 61), UINT8_C(239), UINT8_C(108), UINT8_C(230), UINT8_C(147),
        UINT8_C(109), UINT8_C(171), UINT8_C( 66), UINT8_C(123), UINT8_C(  5), UINT8_C( 53), UINT8_C(240), UINT8_C(205) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 60), UINT8_C( 73), UINT8_C(195), UINT8_C( 95), UINT8_C(161), UINT8_C( 14), UINT8_C(218), UINT8_C( 39),
        UINT8_C( 93), UINT8_C(213), UINT8_C(209), UINT8_C(164), UINT8_C( 12), UINT8_C(159), UINT8_C( 52), UINT8_C(121) },
      { UINT8_C(203), UINT8_C(223), UINT8_C( 57), UINT8_C( 92), UINT8_C(146), UINT8_C(129), UINT8_C(174), UINT8_C( 46),
        UINT8_C(197), UINT8_C( 42), UINT8_C( 48), UINT8_C(107), UINT8_C(  5), UINT8_C(194), UINT8_C(158), UINT8_C(197) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 76), UINT8_C( 48), UINT8_C(205), UINT8_C( 12), UINT8_C( 57), UINT8_C(100), UINT8_C(125), UINT8_C( 81),
        UINT8_C(168), UINT8_C(155), UINT8_C(140), UINT8_C( 75), UINT8_C(134), UINT8_C(222), UINT8_C(106), UINT8_C(250) },
      { UINT8_C(228), UINT8_C(204), UINT8_C(205), UINT8_C(137), UINT8_C( 73), UINT8_C(154), UINT8_C(166), UINT8_C(121),
        UINT8_C( 77), UINT8_C( 88), UINT8_C( 83), UINT8_C(252), UINT8_C( 99), UINT8_C(118), UINT8_C( 22), UINT8_C(159) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(247), UINT8_C(134), UINT8_C(198), UINT8_C( 44), UINT8_C(185), UINT8_C( 67), UINT8_C(196), UINT8_C(207),
        UINT8_C( 56), UINT8_C(211), UINT8_C( 49), UINT8_C(119), UINT8_C(178), UINT8_C( 73), UINT8_C( 94), UINT8_C(127) },
      { UINT8_C( 42), UINT8_C(110), UINT8_C(132), UINT8_C(142), UINT8_C(188), UINT8_C(193), UINT8_C(182), UINT8_C(188),
        UINT8_C( 46), UINT8_C(188), UINT8_C( 19), UINT8_C(246), UINT8_C(199), UINT8_C( 89), UINT8_C( 64), UINT8_C(163) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(100), UINT8_C(213), UINT8_C( 22), UINT8_C(135), UINT8_C(200), UINT8_C(180), UINT8_C(151), UINT8_C(232),
        UINT8_C( 52), UINT8_C(  5), UINT8_C( 39), UINT8_C(240), UINT8_C( 55), UINT8_C(231), UINT8_C(249), UINT8_C( 83) },
      { UINT8_C(200), UINT8_C( 76), UINT8_C(199), UINT8_C( 50), UINT8_C(146), UINT8_C(253), UINT8_C(198), UINT8_C( 62),
        UINT8_C(143), UINT8_C(223), UINT8_C(217), UINT8_C( 32), UINT8_C(216), UINT8_C(116), UINT8_C(  4), UINT8_C( 25) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(188), UINT8_C(164), UINT8_C( 36), UINT8_C(229), UINT8_C( 15), UINT8_C(190), UINT8_C(222), UINT8_C(230),
        UINT8_C(196), UINT8_C(186), UINT8_C(214), UINT8_C(126), UINT8_C(191), UINT8_C(193), UINT8_C( 33), UINT8_C(189) },
      { UINT8_C(228), UINT8_C(239), UINT8_C(252), UINT8_C( 60), UINT8_C(116), UINT8_C( 87), UINT8_C(190), UINT8_C( 72),
        UINT8_C(153), UINT8_C( 71), UINT8_C( 11), UINT8_C( 67), UINT8_C( 63), UINT8_C(206), UINT8_C( 75), UINT8_C( 72) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comeq_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(31782), UINT16_C( 3674), UINT16_C(26933), UINT16_C( 3969), UINT16_C(30738), UINT16_C(59814), UINT16_C(56815), UINT16_C( 1215) },
      { UINT16_C(31782), UINT16_C( 3674), UINT16_C(26933), UINT16_C( 3969), UINT16_C(30738), UINT16_C(59814), UINT16_C(56815), UINT16_C( 1215) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(56743), UINT16_C(30093), UINT16_C(54537), UINT16_C( 8838), UINT16_C(32371), UINT16_C(10003), UINT16_C(28580), UINT16_C(31227) },
      { UINT16_C(58571), UINT16_C(51487), UINT16_C(48611), UINT16_C(44137), UINT16_C(51779), UINT16_C(63743), UINT16_C(17777), UINT16_C(29116) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(41016), UINT16_C(42464), UINT16_C(33530), UINT16_C( 5126), UINT16_C( 3143), UINT16_C(37975), UINT16_C(24749), UINT16_C(62718) },
      { UINT16_C(25810), UINT16_C(57563), UINT16_C(50113), UINT16_C( 1148), UINT16_C(13698), UINT16_C(30025), UINT16_C(  493), UINT16_C(19710) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(49343), UINT16_C(37983), UINT16_C(25582), UINT16_C(26151), UINT16_C(30522), UINT16_C(21057), UINT16_C(43013), UINT16_C(  314) },
      { UINT16_C(33892), UINT16_C( 6647), UINT16_C(33398), UINT16_C(24995), UINT16_C(17397), UINT16_C( 9964), UINT16_C( 5898), UINT16_C(56687) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(50022), UINT16_C( 2416), UINT16_C(33422), UINT16_C(24527), UINT16_C(18806), UINT16_C(10295), UINT16_C(20306), UINT16_C(59545) },
      { UINT16_C(52649), UINT16_C(15833), UINT16_C(  683), UINT16_C( 2503), UINT16_C(31684), UINT16_C(54096), UINT16_C(37233), UINT16_C(27638) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(13139), UINT16_C(52605), UINT16_C(59010), UINT16_C(18663), UINT16_C( 2339), UINT16_C(57507), UINT16_C(24125), UINT16_C(61442) },
      { UINT16_C(50888), UINT16_C( 5354), UINT16_C(19463), UINT16_C(17870), UINT16_C(25880), UINT16_C(18141), UINT16_C(30410), UINT16_C(16506) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(38830), UINT16_C(43501), UINT16_C(38769), UINT16_C(26968), UINT16_C(16488), UINT16_C(16620), UINT16_C(56429), UINT16_C(25180) },
      { UINT16_C(63722), UINT16_C(26002), UINT16_C(26419), UINT16_C(23970), UINT16_C(35353), UINT16_C(18172), UINT16_C(53180), UINT16_C(41701) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(30880), UINT16_C(25128), UINT16_C(40451), UINT16_C( 2568), UINT16_C(30062), UINT16_C( 4474), UINT16_C(53643), UINT16_C(34449) },
      { UINT16_C(59702), UINT16_C(64058), UINT16_C(23510), UINT16_C(39209), UINT16_C(29166), UINT16_C(39443), UINT16_C(41967), UINT16_C(55838) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comeq_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3281411409), UINT32_C(1944126177), UINT32_C( 448082013), UINT32_C(2760394302) },
      { UINT32_C(3281411409), UINT32_C(1944126177), UINT32_C( 448082013), UINT32_C(2760394302) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2571641813), UINT32_C(1095578009), UINT32_C( 193766336), UINT32_C( 789445132) },
      { UINT32_C(2476723944), UINT32_C(3972713395), UINT32_C( 621148764), UINT32_C(  69812527) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 187051758), UINT32_C(2633297956), UINT32_C(1640867510), UINT32_C(3952795067) },
      { UINT32_C(2578142093), UINT32_C(3165258016), UINT32_C(4174535059), UINT32_C(3999059205) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 389714090), UINT32_C(4077428766), UINT32_C(1681917177), UINT32_C(1420645027) },
      { UINT32_C(2653058410), UINT32_C( 745254353), UINT32_C(1568986923), UINT32_C(2836000617) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2280575793), UINT32_C(2389723696), UINT32_C(3679143088), UINT32_C(3022939245) },
      { UINT32_C(1785510820), UINT32_C(2230638446), UINT32_C( 428080204), UINT32_C(2115547395) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 581533354), UINT32_C(3038049537), UINT32_C(2421747460), UINT32_C(1359288512) },
      { UINT32_C(3320950374), UINT32_C( 204309918), UINT32_C(4147597085), UINT32_C(3044088442) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2949782077), UINT32_C(2967251258), UINT32_C(1238273053), UINT32_C(1947891781) },
      { UINT32_C(1998181590), UINT32_C( 201244937), UINT32_C(3188283591), UINT32_C(2533175927) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(4157812244), UINT32_C(3333451394), UINT32_C(3474301730), UINT32_C(1683327908) },
      { UINT32_C(1196275740), UINT32_C(3410989656), UINT32_C( 895459185), UINT32_C(1755447969) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comeq_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comeq_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4717605833667723860), UINT64_C( 7755015510761520443) },
      { UINT64_C( 4717605833667723860), UINT64_C( 7755015510761520443) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(10522661852200296289), UINT64_C( 8451446297061403972) },
      { UINT64_C( 7429899117640998696), UINT64_C(14978668403143041426) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(12182540738121552845), UINT64_C(  278071019023567208) },
      { UINT64_C( 9332715478955625654), UINT64_C(15707509216151344972) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 6364383605199281031), UINT64_C( 6574707631012723460) },
      { UINT64_C(15463621001561887014), UINT64_C(15122938829150578580) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16623996341821456312), UINT64_C(14221252935795067969) },
      { UINT64_C(12700545457662277281), UINT64_C(18406638509938956944) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(11321345988371400583), UINT64_C( 9807686704852845382) },
      { UINT64_C( 6153389593585271887), UINT64_C(12292702122824497000) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(14084578606058126365), UINT64_C(17178323387740530748) },
      { UINT64_C( 1075896664901780055), UINT64_C( 2035148905074804293) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(11648630285130147489), UINT64_C( 4404905146264912970) },
      { UINT64_C( 2576844816584833249), UINT64_C(11189786944117821519) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comeq_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comeq_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  60),  INT8_C(  11),  INT8_C(  54), -INT8_C(  32), -INT8_C( 110), -INT8_C(  37), -INT8_C( 102),      INT8_MAX,
        -INT8_C( 103),  INT8_C(  93), -INT8_C( 120), -INT8_C( 114),  INT8_C(  27),  INT8_C(   7),  INT8_C(  55), -INT8_C(  66) },
      {  INT8_C(  60),  INT8_C(  11),  INT8_C(  54), -INT8_C(  32), -INT8_C( 110), -INT8_C(  37), -INT8_C( 102),      INT8_MAX,
        -INT8_C( 103),  INT8_C(  93), -INT8_C( 120), -INT8_C( 114),  INT8_C(  27),  INT8_C(   7),  INT8_C(  55), -INT8_C(  66) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  23), -INT8_C(  81), -INT8_C(  80),  INT8_C(  62),  INT8_C(  17), -INT8_C( 109), -INT8_C(  53), -INT8_C(  36),
        -INT8_C(  83), -INT8_C( 100),  INT8_C(  90),  INT8_C( 110),  INT8_C( 124), -INT8_C(  28), -INT8_C(  92),  INT8_C( 112) },
      {  INT8_C(  22),  INT8_C( 117),  INT8_C(  21), -INT8_C(  18),  INT8_C( 105),  INT8_C(  84),  INT8_C(  51), -INT8_C(  91),
         INT8_C(  80), -INT8_C(  66), -INT8_C(  44),  INT8_C( 101),  INT8_C( 104), -INT8_C(  79), -INT8_C( 114), -INT8_C(  71) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  31), -INT8_C(  82),  INT8_C( 112), -INT8_C(  54),  INT8_C(  13), -INT8_C(  66), -INT8_C(  17), -INT8_C( 127),
        -INT8_C( 120), -INT8_C(  77),  INT8_C(  35), -INT8_C(  20),  INT8_C( 114), -INT8_C(  80),  INT8_C(  52), -INT8_C(  29) },
      {  INT8_C(  86), -INT8_C(  21),  INT8_C(  15), -INT8_C(  21), -INT8_C(  77), -INT8_C(  78),  INT8_C(  93),  INT8_C(  90),
        -INT8_C( 104), -INT8_C(  84), -INT8_C(  75), -INT8_C(  68),  INT8_C( 113),  INT8_C(  98),  INT8_C(  16),  INT8_C( 118) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  33), -INT8_C(   3),  INT8_C( 126), -INT8_C(  87),  INT8_C(  81),  INT8_C(  81),  INT8_C(  24),  INT8_C(  89),
         INT8_C(   7),  INT8_C(  27),  INT8_C(  54), -INT8_C(  49),  INT8_C( 122), -INT8_C( 121), -INT8_C(  30),  INT8_C(  59) },
      {  INT8_C(  37), -INT8_C(  10), -INT8_C( 116), -INT8_C(  98),  INT8_C(  26), -INT8_C(   3), -INT8_C(   1), -INT8_C(  25),
        -INT8_C( 103), -INT8_C(  79), -INT8_C( 109),  INT8_C(  92), -INT8_C(  31),  INT8_C(  34), -INT8_C(  92),  INT8_C(  60) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  70),  INT8_C(  37),  INT8_C(  68), -INT8_C(  93), -INT8_C( 124),  INT8_C(  87),  INT8_C(  45), -INT8_C(  83),
         INT8_C(  83),  INT8_C(  94), -INT8_C(   7), -INT8_C(  34),  INT8_C(  59),  INT8_C( 114), -INT8_C( 106), -INT8_C(  62) },
      { -INT8_C(  86),  INT8_C(  29), -INT8_C(  12), -INT8_C(  48),  INT8_C(  68),  INT8_C(  62),  INT8_C(   0), -INT8_C( 108),
         INT8_C( 122),  INT8_C(  84), -INT8_C(  42),  INT8_C(  14),  INT8_C(  94), -INT8_C(   7),  INT8_C(  50),  INT8_C(  85) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  75), -INT8_C(  83),  INT8_C(  40),      INT8_MAX,  INT8_C(  78), -INT8_C(  43),  INT8_C(  22), -INT8_C(  59),
        -INT8_C( 109),  INT8_C(   3), -INT8_C(  42), -INT8_C(  29),  INT8_C(  94),  INT8_C( 120),  INT8_C(  56), -INT8_C(  66) },
      {  INT8_C(  14), -INT8_C(  24), -INT8_C(  81),  INT8_C(  73), -INT8_C(  39),  INT8_C( 125),  INT8_C(  74), -INT8_C(  87),
         INT8_C( 100),  INT8_C(  30), -INT8_C(  26), -INT8_C( 104), -INT8_C( 112), -INT8_C(  16), -INT8_C(  93),  INT8_C(   7) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C( 105),  INT8_C(  29), -INT8_C( 108),  INT8_C(   7),  INT8_C(  89), -INT8_C(  43), -INT8_C(  69), -INT8_C(  23),
        -INT8_C(  16), -INT8_C( 109),  INT8_C(  52), -INT8_C(  92), -INT8_C( 118), -INT8_C(  94), -INT8_C(  80),  INT8_C( 120) },
      {  INT8_C( 120), -INT8_C(  33),  INT8_C(  37), -INT8_C(  47), -INT8_C( 126), -INT8_C(  64), -INT8_C(  60),  INT8_C( 110),
         INT8_C( 126), -INT8_C( 107),  INT8_C(  44), -INT8_C(  62),  INT8_C(  33),  INT8_C(  14), -INT8_C(  35), -INT8_C( 101) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  20), -INT8_C(   2), -INT8_C(  17),  INT8_C(   1),  INT8_C(  74),  INT8_C(  94),  INT8_C(   4),  INT8_C(  97),
        -INT8_C( 110), -INT8_C( 107),  INT8_C( 123), -INT8_C(  21),  INT8_C( 104), -INT8_C(   9), -INT8_C(  26),  INT8_C(  56) },
      {  INT8_C(  17), -INT8_C( 117), -INT8_C(  66),  INT8_C(  48), -INT8_C(  25),  INT8_C(  17),  INT8_C(  86),  INT8_C(  43),
        -INT8_C(  15),  INT8_C(  67),  INT8_C(  14),  INT8_C(  86), -INT8_C(  74),  INT8_C(  92), -INT8_C(  55),  INT8_C(  89) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comneq_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 10413),  INT16_C( 13985),  INT16_C( 31180),  INT16_C( 29913), -INT16_C( 28256),  INT16_C( 32274),  INT16_C( 32672),  INT16_C( 18114) },
      { -INT16_C( 10413),  INT16_C( 13985),  INT16_C( 31180),  INT16_C( 29913), -INT16_C( 28256),  INT16_C( 32274),  INT16_C( 32672),  INT16_C( 18114) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 29440),  INT16_C( 11747),  INT16_C( 30639),  INT16_C( 10216), -INT16_C( 20252),  INT16_C(  6901), -INT16_C(  7942), -INT16_C( 30641) },
      {  INT16_C( 12413),  INT16_C( 28178),  INT16_C( 11653),  INT16_C( 27682),  INT16_C(  4162),  INT16_C(  9571),  INT16_C( 17113), -INT16_C(  5843) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  8046), -INT16_C( 27910), -INT16_C(  1150), -INT16_C( 21662),  INT16_C( 25216), -INT16_C( 10166), -INT16_C( 23406),  INT16_C( 29016) },
      { -INT16_C( 28231),  INT16_C( 29098), -INT16_C( 32227), -INT16_C( 28729), -INT16_C( 26206), -INT16_C( 21803),  INT16_C( 18875),  INT16_C( 27149) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  6275),  INT16_C(  9581), -INT16_C( 23798), -INT16_C(    84), -INT16_C(  7188),  INT16_C( 22131), -INT16_C( 20439),  INT16_C( 24010) },
      { -INT16_C( 31952),  INT16_C(  1745), -INT16_C( 32707),  INT16_C(  9904), -INT16_C( 19227), -INT16_C( 11056), -INT16_C( 25616),  INT16_C(  4428) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C(  6810), -INT16_C( 20574),  INT16_C( 31212),  INT16_C( 27567), -INT16_C( 17583),  INT16_C( 24026),  INT16_C(  2661), -INT16_C( 28017) },
      { -INT16_C( 29430), -INT16_C(  2065),  INT16_C( 12429),  INT16_C( 30917), -INT16_C(  5834),  INT16_C( 27324),  INT16_C( 16413),  INT16_C(  9936) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  3648), -INT16_C(  2301), -INT16_C( 31277),  INT16_C( 14161),  INT16_C( 28887), -INT16_C( 19227), -INT16_C( 17170),  INT16_C( 22925) },
      {  INT16_C( 14446),  INT16_C(  2668), -INT16_C( 26188), -INT16_C( 12305), -INT16_C( 15941),  INT16_C( 13570),  INT16_C( 16877), -INT16_C(  3709) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  7224), -INT16_C( 14346), -INT16_C( 12699), -INT16_C( 21893), -INT16_C( 29531),  INT16_C(  9726), -INT16_C( 12691), -INT16_C(  1618) },
      {  INT16_C(  2948),  INT16_C(  2224), -INT16_C( 15525),  INT16_C( 28948), -INT16_C( 15460), -INT16_C(   760), -INT16_C( 23291), -INT16_C( 17845) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 27017), -INT16_C(  6683),  INT16_C( 23626),  INT16_C(  3350), -INT16_C( 26652),  INT16_C( 30348),  INT16_C( 18058), -INT16_C( 17192) },
      { -INT16_C( 29067), -INT16_C( 18397), -INT16_C( 18647), -INT16_C( 22755),  INT16_C( 30722), -INT16_C( 30409),  INT16_C( 29712), -INT16_C( 14318) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comneq_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   439813157), -INT32_C(  1475856597),  INT32_C(  1895241659), -INT32_C(   386584852) },
      {  INT32_C(   439813157), -INT32_C(  1475856597),  INT32_C(  1895241659), -INT32_C(   386584852) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   466794135), -INT32_C(  1175225145), -INT32_C(  1544067563),  INT32_C(  1690285748) },
      {  INT32_C(   777317993), -INT32_C(  1019516752), -INT32_C(   609839533), -INT32_C(   957575876) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1379386759), -INT32_C(   277079332),  INT32_C(   296818684), -INT32_C(   700812135) },
      { -INT32_C(   375071381), -INT32_C(  1500121472),  INT32_C(  2130942932), -INT32_C(  1633326047) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   878212616), -INT32_C(  1851614703), -INT32_C(  1664412704),  INT32_C(  1718335080) },
      {  INT32_C(   328161620), -INT32_C(  1727993532),  INT32_C(   594915173), -INT32_C(  1207381436) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(   401022436), -INT32_C(   431226098),  INT32_C(   212852968),  INT32_C(  1547338441) },
      {  INT32_C(  1937631308), -INT32_C(   480032349), -INT32_C(  1855694546),  INT32_C(  1543358284) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(    27456910),  INT32_C(   929193338),  INT32_C(   700647485), -INT32_C(     7347613) },
      { -INT32_C(   757721990), -INT32_C(   844816570), -INT32_C(  1892146856), -INT32_C(   798206750) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1215551434), -INT32_C(   859065859), -INT32_C(  1150217466), -INT32_C(  1739399713) },
      { -INT32_C(   134061049), -INT32_C(  1615826220), -INT32_C(   430272757),  INT32_C(  1614643118) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1131410411), -INT32_C(   311359936), -INT32_C(  1994356884),  INT32_C(  1869315044) },
      { -INT32_C(  1385603046), -INT32_C(  1586803722),  INT32_C(  1580215406),  INT32_C(  1347965527) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comneq_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 2145009836426055045), -INT64_C( 3692172023188427113) },
      { -INT64_C( 2145009836426055045), -INT64_C( 3692172023188427113) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1927172668007879132), -INT64_C( 1466531328946896982) },
      { -INT64_C( 1003788530826162141), -INT64_C(  630571924344221778) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 6093841530576535157),  INT64_C( 8650587926085505254) },
      {  INT64_C( 7483676463588208182),  INT64_C( 4020443149158757337) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 7652666475017031668),  INT64_C( 4500793761105799243) },
      { -INT64_C( 8682651005132106533), -INT64_C( 3004755848539594430) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 2763101731854593481), -INT64_C( 8733947786854461951) },
      { -INT64_C( 7211148372848030917),  INT64_C( 1921978243298205966) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 5700269870367375317), -INT64_C( 7426619846471480785) },
      { -INT64_C( 1584459702047040899),  INT64_C( 5535302230343596904) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 6340521394491436376), -INT64_C( 4841440811628337666) },
      { -INT64_C( 4707356538522662197), -INT64_C( 5501906473491040138) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 8581209791696617351),  INT64_C( 4201864310067635861) },
      {  INT64_C( 6760919033000960586), -INT64_C( 7417949586054127776) },
      { -INT64_C(                   1), -INT64_C(                   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comneq_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 97), UINT8_C( 63), UINT8_C(177), UINT8_C( 41), UINT8_C(135), UINT8_C(142), UINT8_C(197), UINT8_C( 40),
        UINT8_C( 29), UINT8_C( 85), UINT8_C( 24), UINT8_C(121), UINT8_C(136), UINT8_C( 51), UINT8_C( 92), UINT8_C( 89) },
      { UINT8_C( 97), UINT8_C( 63), UINT8_C(177), UINT8_C( 41), UINT8_C(135), UINT8_C(142), UINT8_C(197), UINT8_C( 40),
        UINT8_C( 29), UINT8_C( 85), UINT8_C( 24), UINT8_C(121), UINT8_C(136), UINT8_C( 51), UINT8_C( 92), UINT8_C( 89) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 36), UINT8_C(234), UINT8_C(216), UINT8_C( 67), UINT8_C(146), UINT8_C(101), UINT8_C( 93), UINT8_C( 16),
        UINT8_C( 79), UINT8_C(249), UINT8_C(124), UINT8_C( 99), UINT8_C(139), UINT8_C(235), UINT8_C(246), UINT8_C( 68) },
      { UINT8_C( 56), UINT8_C( 50), UINT8_C(116), UINT8_C( 11), UINT8_C( 97), UINT8_C(127), UINT8_C(120), UINT8_C(128),
        UINT8_C(189), UINT8_C(123), UINT8_C(148), UINT8_C( 64), UINT8_C(132), UINT8_C( 79), UINT8_C(218), UINT8_C( 99) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(129), UINT8_C(106), UINT8_C(147), UINT8_C( 91), UINT8_C(105), UINT8_C(126), UINT8_C( 52), UINT8_C( 31),
        UINT8_C(107), UINT8_C(204), UINT8_C(141), UINT8_C(138), UINT8_C(  8), UINT8_C(162), UINT8_C( 68), UINT8_C(253) },
      { UINT8_C( 37), UINT8_C( 34), UINT8_C(130), UINT8_C( 76), UINT8_C( 94), UINT8_C( 68), UINT8_C(236), UINT8_C(216),
        UINT8_C(158), UINT8_C( 31), UINT8_C(213), UINT8_C(248), UINT8_C(236), UINT8_C(100), UINT8_C(177), UINT8_C(158) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(136), UINT8_C( 43), UINT8_C(205), UINT8_C( 55), UINT8_C( 55), UINT8_C(242), UINT8_C( 62), UINT8_C(210),
        UINT8_C(219), UINT8_C(226), UINT8_C( 24), UINT8_C(133), UINT8_C( 70), UINT8_C( 85), UINT8_C(224), UINT8_C( 12) },
      { UINT8_C( 80), UINT8_C(150), UINT8_C( 67), UINT8_C(180), UINT8_C( 39), UINT8_C(231), UINT8_C(  7), UINT8_C(120),
        UINT8_C(231), UINT8_C(201), UINT8_C( 67), UINT8_C(105), UINT8_C(107), UINT8_C(119), UINT8_C(203), UINT8_C( 83) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 98), UINT8_C(180), UINT8_C(239), UINT8_C(157), UINT8_C(165), UINT8_C(198), UINT8_C(101), UINT8_C(113),
        UINT8_C(200), UINT8_C(195), UINT8_C(131), UINT8_C( 29), UINT8_C(238), UINT8_C( 11), UINT8_C(177), UINT8_C(185) },
      { UINT8_C(226), UINT8_C( 22), UINT8_C( 31), UINT8_C( 10), UINT8_C(100), UINT8_C(112), UINT8_C(179), UINT8_C(167),
        UINT8_C(193), UINT8_C(  1), UINT8_C( 70), UINT8_C( 90), UINT8_C(167), UINT8_C(146), UINT8_C( 15), UINT8_C(201) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 54), UINT8_C(141), UINT8_C( 95), UINT8_C( 86), UINT8_C( 90), UINT8_C(  4), UINT8_C(143), UINT8_C( 67),
        UINT8_C( 89), UINT8_C(245), UINT8_C( 55), UINT8_C( 26), UINT8_C(168), UINT8_C(205), UINT8_C(161), UINT8_C( 76) },
      { UINT8_C(  3), UINT8_C( 42), UINT8_C(126), UINT8_C( 24), UINT8_C(188), UINT8_C(229), UINT8_C(215), UINT8_C(174),
        UINT8_C( 84), UINT8_C( 80), UINT8_C( 70), UINT8_C(149), UINT8_C( 72), UINT8_C(188), UINT8_C(101), UINT8_C( 74) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 45), UINT8_C( 63), UINT8_C(135), UINT8_C( 42),    UINT8_MAX, UINT8_C(180), UINT8_C(166), UINT8_C(145),
        UINT8_C(183), UINT8_C(  2), UINT8_C(157), UINT8_C( 68), UINT8_C( 27), UINT8_C(162), UINT8_C(151), UINT8_C( 12) },
      { UINT8_C(218), UINT8_C( 91), UINT8_C(200), UINT8_C(164), UINT8_C(216), UINT8_C( 80), UINT8_C( 91), UINT8_C(213),
        UINT8_C(199), UINT8_C( 61), UINT8_C(171), UINT8_C(224), UINT8_C(247), UINT8_C(254), UINT8_C(181), UINT8_C( 28) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(111), UINT8_C( 81), UINT8_C(206), UINT8_C(224), UINT8_C( 60), UINT8_C(220), UINT8_C(145), UINT8_C(163),
        UINT8_C(  9), UINT8_C(114), UINT8_C( 28), UINT8_C( 98), UINT8_C(240), UINT8_C(146), UINT8_C(124), UINT8_C( 67) },
      { UINT8_C(144), UINT8_C( 48), UINT8_C(101), UINT8_C(119), UINT8_C( 96), UINT8_C(184), UINT8_C( 38), UINT8_C(100),
        UINT8_C( 66), UINT8_C( 81), UINT8_C(221), UINT8_C(  4), UINT8_C( 92), UINT8_C( 95), UINT8_C(231), UINT8_C(136) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comneq_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(19235), UINT16_C(17051), UINT16_C(34488), UINT16_C(49464), UINT16_C(52088), UINT16_C(15899), UINT16_C(42447), UINT16_C(14134) },
      { UINT16_C(19235), UINT16_C(17051), UINT16_C(34488), UINT16_C(49464), UINT16_C(52088), UINT16_C(15899), UINT16_C(42447), UINT16_C(14134) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(12876), UINT16_C(22973), UINT16_C( 9979), UINT16_C(41762), UINT16_C( 4847), UINT16_C(51524), UINT16_C(59166), UINT16_C(55012) },
      { UINT16_C(46706), UINT16_C( 5720), UINT16_C(47388), UINT16_C(13187), UINT16_C(38700), UINT16_C(40452), UINT16_C(58462), UINT16_C(12462) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(59191), UINT16_C( 4664), UINT16_C(41297), UINT16_C(55862), UINT16_C( 2804), UINT16_C(63048), UINT16_C(40677), UINT16_C(20114) },
      { UINT16_C( 6275), UINT16_C( 9580), UINT16_C(32271), UINT16_C(16474), UINT16_C(23884), UINT16_C(19262), UINT16_C(22088), UINT16_C(30924) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(55673), UINT16_C(26943), UINT16_C(12555), UINT16_C(20554), UINT16_C(49529), UINT16_C(21842), UINT16_C(36187), UINT16_C(14554) },
      { UINT16_C(64639), UINT16_C(14143), UINT16_C(56378), UINT16_C(12965), UINT16_C(42496), UINT16_C( 3377), UINT16_C(  819), UINT16_C(22137) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(36921), UINT16_C(10040), UINT16_C(57041), UINT16_C(20039), UINT16_C(48807), UINT16_C(44232), UINT16_C(47910), UINT16_C(56228) },
      { UINT16_C(59277), UINT16_C( 5177), UINT16_C(56133), UINT16_C(20300), UINT16_C(63858), UINT16_C(43845), UINT16_C(62664), UINT16_C( 4507) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(37791), UINT16_C( 5261), UINT16_C(45386), UINT16_C( 7187), UINT16_C(35237), UINT16_C(50196), UINT16_C(12526), UINT16_C(32985) },
      { UINT16_C(25558), UINT16_C(33730), UINT16_C(33751), UINT16_C(57399), UINT16_C(57031), UINT16_C(61410), UINT16_C(12462), UINT16_C(61979) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(27349), UINT16_C(63652), UINT16_C(45343), UINT16_C(  663), UINT16_C(43676), UINT16_C(26012), UINT16_C(62812), UINT16_C(28511) },
      { UINT16_C(63361), UINT16_C(19778), UINT16_C(56728), UINT16_C(11343), UINT16_C(56618), UINT16_C(40816), UINT16_C(49037), UINT16_C(16866) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(40192), UINT16_C(39911), UINT16_C(59384), UINT16_C(18619), UINT16_C(43444), UINT16_C(22218), UINT16_C( 4375), UINT16_C(61472) },
      { UINT16_C(11447), UINT16_C(14881), UINT16_C(61490), UINT16_C(32122), UINT16_C(32705), UINT16_C(33879), UINT16_C(43535), UINT16_C(18135) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comneq_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3317478475), UINT32_C( 896031099), UINT32_C(1627721492), UINT32_C(1258523848) },
      { UINT32_C(3317478475), UINT32_C( 896031099), UINT32_C(1627721492), UINT32_C(1258523848) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 315066528), UINT32_C( 430031946), UINT32_C(1728007092), UINT32_C(1222768858) },
      { UINT32_C(1032665308), UINT32_C( 310645075), UINT32_C(1286890725), UINT32_C(3354357527) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2644284771), UINT32_C(1236099723), UINT32_C( 231852588), UINT32_C(2448077206) },
      { UINT32_C(3435246043), UINT32_C( 670570278), UINT32_C(3762368078), UINT32_C(2916008363) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2735332137), UINT32_C(1434767770), UINT32_C(1077117521), UINT32_C(1742331628) },
      { UINT32_C( 985703793), UINT32_C(3165483421), UINT32_C(3843291000), UINT32_C(1166510637) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3950305561), UINT32_C(2232424738), UINT32_C(3381591370), UINT32_C( 328631939) },
      { UINT32_C(1341300422), UINT32_C( 428484959), UINT32_C( 596788875), UINT32_C(3607286340) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1044787036), UINT32_C( 557269961), UINT32_C(1850458944), UINT32_C(3691557125) },
      { UINT32_C(3535741697), UINT32_C(2255898389), UINT32_C(1646699694), UINT32_C(2871501465) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1692945689), UINT32_C(1893946935), UINT32_C(4174404186), UINT32_C( 202991383) },
      { UINT32_C(2375007562), UINT32_C(1247531366), UINT32_C(1765251081), UINT32_C( 165544404) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 633390201), UINT32_C(3153811989), UINT32_C( 780618945), UINT32_C(3937448291) },
      { UINT32_C(1187705547), UINT32_C(2921386491), UINT32_C(  19770053), UINT32_C( 940570780) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comneq_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comneq_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 5361350686904162980), UINT64_C(13669997797138899356) },
      { UINT64_C( 5361350686904162980), UINT64_C(13669997797138899356) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(18063179973976935849), UINT64_C( 9341185368968421898) },
      { UINT64_C( 7282134507660499649), UINT64_C(14848683848067669780) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8568750919223694095), UINT64_C( 3206505158861670911) },
      { UINT64_C( 6114586325512653304), UINT64_C( 7325759221035798609) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 7620057443402157603), UINT64_C( 9335601207311263437) },
      { UINT64_C( 6823929844010168691), UINT64_C(14513196095610043258) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 2095306404218111245), UINT64_C(14391353092876059035) },
      { UINT64_C(14807743135612787031), UINT64_C( 4915358179487967671) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(15623489378715681014), UINT64_C( 5252251355818517394) },
      { UINT64_C(16656562333259696847), UINT64_C( 2088054659659145522) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(16419614906668926982), UINT64_C( 5402323566441812954) },
      { UINT64_C(17695625336589536000), UINT64_C(11140625531488398096) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 9665645717917344868), UINT64_C( 1648566707567335834) },
      { UINT64_C( 4515750840144995349), UINT64_C(  433321513721155452) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comneq_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comneq_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  57),  INT8_C(  92),  INT8_C( 113), -INT8_C(  91), -INT8_C(  30),  INT8_C(  16), -INT8_C( 120),  INT8_C(   8),
        -INT8_C(   5),  INT8_C(  62), -INT8_C(  44), -INT8_C(  32), -INT8_C( 124), -INT8_C(  77), -INT8_C( 127), -INT8_C(  12) },
      {  INT8_C(  57),  INT8_C(  92),  INT8_C( 113), -INT8_C(  91), -INT8_C(  30),  INT8_C(  16), -INT8_C( 120),  INT8_C(   8),
        -INT8_C(   5),  INT8_C(  62), -INT8_C(  44), -INT8_C(  32), -INT8_C( 124), -INT8_C(  77), -INT8_C( 127), -INT8_C(  12) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  52),  INT8_C(  29),  INT8_C(  19),  INT8_C(  11), -INT8_C(  56),  INT8_C(  19),  INT8_C(  88),  INT8_C(  12),
        -INT8_C( 100),  INT8_C(  86), -INT8_C( 102),  INT8_C( 100),  INT8_C( 120),  INT8_C(  87),  INT8_C(  24), -INT8_C(  88) },
      { -INT8_C(  84), -INT8_C(   7), -INT8_C(  72),  INT8_C( 123),  INT8_C(  95), -INT8_C( 105), -INT8_C(  10), -INT8_C(  77),
         INT8_C(  36),  INT8_C(  73),  INT8_C(  32), -INT8_C(  73), -INT8_C(  50),  INT8_C(  99), -INT8_C(  59),  INT8_C(  43) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C( 122),  INT8_C(  63),  INT8_C( 107), -INT8_C(  48),  INT8_C(  26),  INT8_C(  61),      INT8_MIN, -INT8_C(  91),
        -INT8_C( 104),  INT8_C(   7), -INT8_C( 109),  INT8_C(  83),  INT8_C(  28),  INT8_C(  26), -INT8_C(  60), -INT8_C(  57) },
      { -INT8_C(  26), -INT8_C( 126),  INT8_C( 121),  INT8_C(  33), -INT8_C(  81), -INT8_C(  28),  INT8_C(  83), -INT8_C(  51),
         INT8_C(  61), -INT8_C(  62),  INT8_C(  97), -INT8_C(  17),  INT8_C(  54), -INT8_C(   5), -INT8_C( 109),  INT8_C(   5) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  50), -INT8_C( 111),  INT8_C( 113), -INT8_C(  56),  INT8_C(  19), -INT8_C(  81),  INT8_C(  12),  INT8_C(  82),
        -INT8_C( 103), -INT8_C(  21),  INT8_C(  53), -INT8_C( 122),  INT8_C(  49), -INT8_C(  56), -INT8_C(  18), -INT8_C(  83) },
      {  INT8_C(  14),      INT8_MAX,  INT8_C(  30),  INT8_C(  93),  INT8_C( 123), -INT8_C(   1), -INT8_C( 119), -INT8_C(  97),
         INT8_C( 112),  INT8_C(  50), -INT8_C(   2),  INT8_C(  80),  INT8_C(  99), -INT8_C( 126), -INT8_C(  46), -INT8_C(  56) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  96), -INT8_C( 100), -INT8_C( 114), -INT8_C(  70),  INT8_C(  92),  INT8_C( 115), -INT8_C(  27),  INT8_C(  91),
        -INT8_C(  57), -INT8_C( 120), -INT8_C(  23), -INT8_C(  57),  INT8_C(  96),  INT8_C( 106),  INT8_C( 126), -INT8_C(  96) },
      {  INT8_C(  77),  INT8_C( 120),  INT8_C(  14), -INT8_C(   8),  INT8_C( 107), -INT8_C(  18),  INT8_C( 126),  INT8_C( 113),
        -INT8_C(  29),  INT8_C(  32),  INT8_C(  97), -INT8_C(  94), -INT8_C(   2),  INT8_C(   0),  INT8_C( 108), -INT8_C(  67) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  58), -INT8_C(  26),  INT8_C(  42),  INT8_C( 111), -INT8_C(  99), -INT8_C( 111), -INT8_C(  15),  INT8_C(   8),
         INT8_C(  73),  INT8_C( 105),  INT8_C(  21), -INT8_C(  36),  INT8_C(  81),  INT8_C(   6),  INT8_C(  91), -INT8_C(  23) },
      { -INT8_C(  53), -INT8_C(  10), -INT8_C(  79), -INT8_C(  70),  INT8_C(  38), -INT8_C(  69),  INT8_C(  28), -INT8_C( 117),
        -INT8_C(  66),  INT8_C(  20), -INT8_C(  15), -INT8_C(  83), -INT8_C(  82),  INT8_C( 126),  INT8_C(  72),  INT8_C(  44) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  27), -INT8_C(   7), -INT8_C(  82), -INT8_C(  80),  INT8_C( 125),  INT8_C(  15),  INT8_C(  26), -INT8_C(  95),
         INT8_C(  72),  INT8_C(  19),  INT8_C(  35), -INT8_C( 114), -INT8_C(  85), -INT8_C(  89),  INT8_C( 111), -INT8_C(  48) },
      { -INT8_C(  81),      INT8_MIN,  INT8_C( 111),  INT8_C( 106),  INT8_C(  85),  INT8_C( 110),  INT8_C(  73),  INT8_C(  52),
         INT8_C(  42), -INT8_C( 106),  INT8_C(  22),  INT8_C(  57),  INT8_C(  28),  INT8_C(   2),  INT8_C(  78),  INT8_C(  93) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C( 116),  INT8_C(  93),      INT8_MIN,  INT8_C(  67), -INT8_C(  92), -INT8_C(   9),  INT8_C(  71),  INT8_C( 109),
        -INT8_C(  21),  INT8_C(  16),  INT8_C( 121), -INT8_C(  91),  INT8_C(  22),  INT8_C(  82), -INT8_C(  95), -INT8_C( 100) },
      {  INT8_C(  34), -INT8_C(  97), -INT8_C(  80), -INT8_C(  46), -INT8_C(  97),  INT8_C(  13), -INT8_C(  17), -INT8_C(  75),
         INT8_C(  79),  INT8_C(  47),  INT8_C(  56),  INT8_C(  13), -INT8_C(  17), -INT8_C( 105),  INT8_C( 102), -INT8_C( 105) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comge_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 26539), -INT16_C(  4086),  INT16_C( 20923), -INT16_C( 19104), -INT16_C(  6565), -INT16_C(  5759),  INT16_C(  4412), -INT16_C( 26663) },
      { -INT16_C( 26539), -INT16_C(  4086),  INT16_C( 20923), -INT16_C( 19104), -INT16_C(  6565), -INT16_C(  5759),  INT16_C(  4412), -INT16_C( 26663) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C(  9653), -INT16_C( 18212), -INT16_C( 23891),  INT16_C( 22261),  INT16_C( 26196), -INT16_C(  3393),  INT16_C( 17104),  INT16_C(  9336) },
      {  INT16_C( 13416), -INT16_C( 32333),  INT16_C(  9066), -INT16_C( 16052),  INT16_C(  8383),  INT16_C(  8865), -INT16_C(  5182),  INT16_C(  2047) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 18093), -INT16_C(  6821),  INT16_C( 13350),  INT16_C( 24387), -INT16_C( 15263), -INT16_C( 20460),  INT16_C(  3431),  INT16_C( 19052) },
      { -INT16_C( 17938), -INT16_C( 17182),  INT16_C( 30552), -INT16_C(  9739),  INT16_C( 17216),  INT16_C(  5955), -INT16_C(  5805),  INT16_C( 13820) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 15263),  INT16_C(  8597), -INT16_C( 13133),  INT16_C(  6337), -INT16_C( 12128),  INT16_C(  3997), -INT16_C(   165),  INT16_C( 21034) },
      { -INT16_C( 21233),  INT16_C( 27393),  INT16_C( 21550),  INT16_C( 17730), -INT16_C(  9978), -INT16_C( 28210),  INT16_C(  4501),  INT16_C( 27062) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 31586),  INT16_C( 13299),  INT16_C( 29180), -INT16_C( 13993),  INT16_C(  4663), -INT16_C( 10301),  INT16_C(  8277), -INT16_C( 31589) },
      { -INT16_C( 25870),  INT16_C( 21623), -INT16_C( 15469),  INT16_C( 19483),  INT16_C( 27192),  INT16_C( 22698),  INT16_C( 27952), -INT16_C(  5354) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 32719), -INT16_C(  6693),  INT16_C( 11176), -INT16_C( 17939),  INT16_C(  4686), -INT16_C( 12306),  INT16_C( 31228),  INT16_C( 10149) },
      {  INT16_C(  1984),  INT16_C( 16556), -INT16_C( 13776),  INT16_C( 14440),  INT16_C( 31998),  INT16_C( 13374),  INT16_C(  1485),  INT16_C(   516) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 16451), -INT16_C(   586),  INT16_C(   608),  INT16_C( 12651),  INT16_C( 22798), -INT16_C( 16249),  INT16_C(  4601), -INT16_C( 31439) },
      {  INT16_C( 32160), -INT16_C(  2552),  INT16_C( 29869),  INT16_C( 20241), -INT16_C( 26239), -INT16_C(  4620), -INT16_C(  8428), -INT16_C(  2199) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 19964),  INT16_C( 17645), -INT16_C(    53),  INT16_C( 31161),  INT16_C( 28318),  INT16_C( 29428), -INT16_C(  3597), -INT16_C(  7128) },
      { -INT16_C( 31813),  INT16_C( 16627), -INT16_C( 14671), -INT16_C(  9473),  INT16_C( 18665),  INT16_C( 18995),  INT16_C(  1452),  INT16_C(  4651) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comge_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  2098844029), -INT32_C(   641783406), -INT32_C(  1382033113), -INT32_C(  1922031725) },
      { -INT32_C(  2098844029), -INT32_C(   641783406), -INT32_C(  1382033113), -INT32_C(  1922031725) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   455761607),  INT32_C(   538495716),  INT32_C(   342102622), -INT32_C(  1691058370) },
      {  INT32_C(  2131454721), -INT32_C(  1721333412),  INT32_C(   971908049), -INT32_C(   923556479) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1424597183),  INT32_C(  1799718895),  INT32_C(   334331143), -INT32_C(   630566031) },
      {  INT32_C(    46370205),  INT32_C(     9709010), -INT32_C(   582233149), -INT32_C(   594048156) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1562265339),  INT32_C(    24053114),  INT32_C(   255267596),  INT32_C(   397904878) },
      { -INT32_C(   713745536),  INT32_C(  1462896540),  INT32_C(  1646096678),  INT32_C(   323409892) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1034560112),  INT32_C(   729566508), -INT32_C(   794141546), -INT32_C(  1727910052) },
      { -INT32_C(  1098146351), -INT32_C(   433506463), -INT32_C(  1848867551), -INT32_C(  1276669014) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(  1591432152),  INT32_C(   827745966),  INT32_C(   497999821), -INT32_C(  1456257692) },
      { -INT32_C(  2039702343), -INT32_C(   178275383),  INT32_C(   817928413),  INT32_C(    90359390) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   990823190),  INT32_C(  1541626023), -INT32_C(  1062460200), -INT32_C(  1892558930) },
      { -INT32_C(   176119968), -INT32_C(   859923074),  INT32_C(   123744642),  INT32_C(  1369405864) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   249228033), -INT32_C(   250794816),  INT32_C(  2131407839), -INT32_C(  1813582623) },
      { -INT32_C(   768659731), -INT32_C(  1288837851), -INT32_C(   535373513), -INT32_C(   544885970) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comge_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4231951681613053327), -INT64_C(  199972968041671412) },
      {  INT64_C( 4231951681613053327), -INT64_C(  199972968041671412) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 1039318408851500663), -INT64_C(  648944288963881180) },
      {  INT64_C( 9211154201577831873),  INT64_C( 1446431342413402501) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 3469245127459991205), -INT64_C( 2309541123369831566) },
      {  INT64_C(  595107754553482941),  INT64_C( 2403110769458442098) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 7644461919772969588), -INT64_C( 2069442768328493751) },
      {  INT64_C( 2156352861533824940),  INT64_C( 7851466218311481340) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 8383284232392702397),  INT64_C( 5253030957281289936) },
      {  INT64_C(  484869302557483446),  INT64_C( 4454658751047889483) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C(  504594842707768663),  INT64_C( 6248703133163752752) },
      {  INT64_C(  762337237287621378), -INT64_C( 2534416100243281786) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 2798601033062927334),  INT64_C( 6314863776929002384) },
      {  INT64_C( 8314271650882946489), -INT64_C( 8006698707022159915) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 6563306511736312097), -INT64_C( 7957661828417413607) },
      { -INT64_C( 8715528813258751998), -INT64_C( 6635828572573114015) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comge_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(130), UINT8_C( 34), UINT8_C( 53), UINT8_C( 20), UINT8_C( 99), UINT8_C( 30), UINT8_C(164), UINT8_C(224),
        UINT8_C(243), UINT8_C(216), UINT8_C(125), UINT8_C(129), UINT8_C(206), UINT8_C( 73), UINT8_C(103), UINT8_C( 77) },
      { UINT8_C(130), UINT8_C( 34), UINT8_C( 53), UINT8_C( 20), UINT8_C( 99), UINT8_C( 30), UINT8_C(164), UINT8_C(224),
        UINT8_C(243), UINT8_C(216), UINT8_C(125), UINT8_C(129), UINT8_C(206), UINT8_C( 73), UINT8_C(103), UINT8_C( 77) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  6), UINT8_C( 10), UINT8_C( 35), UINT8_C( 86), UINT8_C(117), UINT8_C( 95), UINT8_C(122), UINT8_C(143),
        UINT8_C( 82), UINT8_C(117), UINT8_C(116), UINT8_C( 48), UINT8_C(  3), UINT8_C(232), UINT8_C(203), UINT8_C( 91) },
      { UINT8_C( 50), UINT8_C(136), UINT8_C(159),    UINT8_MAX, UINT8_C( 35), UINT8_C( 93), UINT8_C(107), UINT8_C(253),
        UINT8_C( 69), UINT8_C(233), UINT8_C( 56), UINT8_C(137), UINT8_C(  7), UINT8_C(172), UINT8_C( 17), UINT8_C(211) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(236), UINT8_C(238), UINT8_C(182), UINT8_C(231), UINT8_C(226), UINT8_C(184), UINT8_C(149), UINT8_C(210),
        UINT8_C(208), UINT8_C( 36), UINT8_C(245), UINT8_C(  7), UINT8_C(110), UINT8_C(214), UINT8_C(117), UINT8_C(  1) },
      { UINT8_C( 89), UINT8_C(203), UINT8_C(181), UINT8_C( 41), UINT8_C(103), UINT8_C( 82), UINT8_C( 83), UINT8_C(249),
        UINT8_C( 55), UINT8_C( 87), UINT8_C( 25), UINT8_C( 98), UINT8_C( 13), UINT8_C(231), UINT8_C(116), UINT8_C(107) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(221), UINT8_C(241), UINT8_C( 40), UINT8_C( 28), UINT8_C(166), UINT8_C( 74), UINT8_C( 67), UINT8_C(154),
        UINT8_C(  2), UINT8_C(244), UINT8_C( 79), UINT8_C(147), UINT8_C(250), UINT8_C(160), UINT8_C(204), UINT8_C(220) },
      { UINT8_C( 30), UINT8_C(113), UINT8_C(222), UINT8_C( 89), UINT8_C(214), UINT8_C(  3), UINT8_C( 66), UINT8_C( 30),
        UINT8_C(243), UINT8_C(172), UINT8_C(134), UINT8_C(211), UINT8_C(137), UINT8_C(  2), UINT8_C(122), UINT8_C( 93) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  1), UINT8_C(157), UINT8_C(226), UINT8_C(187), UINT8_C(106), UINT8_C( 30), UINT8_C(109), UINT8_C( 45),
        UINT8_C( 16), UINT8_C(111), UINT8_C(235), UINT8_C(156), UINT8_C( 80), UINT8_C( 77), UINT8_C(186), UINT8_C( 54) },
      { UINT8_C(170), UINT8_C(  4), UINT8_C(129), UINT8_C( 89), UINT8_C( 24), UINT8_C(122), UINT8_C( 33), UINT8_C(178),
        UINT8_C(158), UINT8_C(111), UINT8_C(233), UINT8_C(166), UINT8_C( 35), UINT8_C(  3), UINT8_C( 10), UINT8_C(240) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(127), UINT8_C(121), UINT8_C( 74), UINT8_C(140), UINT8_C(213), UINT8_C( 58), UINT8_C(252), UINT8_C(212),
        UINT8_C( 35), UINT8_C( 29), UINT8_C( 47), UINT8_C(234), UINT8_C( 23), UINT8_C(229), UINT8_C( 38), UINT8_C( 85) },
      { UINT8_C( 37), UINT8_C( 12), UINT8_C(  8), UINT8_C(239), UINT8_C(214), UINT8_C(191), UINT8_C(217), UINT8_C(254),
        UINT8_C( 99), UINT8_C( 41), UINT8_C(169), UINT8_C(161), UINT8_C(130), UINT8_C(244), UINT8_C( 11), UINT8_C(110) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(128), UINT8_C( 13), UINT8_C(201), UINT8_C( 89), UINT8_C(144), UINT8_C(168), UINT8_C(214), UINT8_C(215),
        UINT8_C( 99), UINT8_C(133), UINT8_C(132), UINT8_C( 68), UINT8_C(248), UINT8_C(113), UINT8_C(247), UINT8_C(130) },
      { UINT8_C(182), UINT8_C( 15), UINT8_C(218), UINT8_C(228), UINT8_C(184), UINT8_C(216), UINT8_C( 80), UINT8_C( 74),
        UINT8_C(104), UINT8_C( 97), UINT8_C( 46), UINT8_C(141), UINT8_C( 79), UINT8_C(220), UINT8_C(103), UINT8_C( 29) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 43), UINT8_C(226), UINT8_C(200), UINT8_C(232), UINT8_C( 66), UINT8_C(112), UINT8_C(229), UINT8_C(126),
        UINT8_C(247), UINT8_C( 47), UINT8_C( 83), UINT8_C(115), UINT8_C(155), UINT8_C(248), UINT8_C( 23), UINT8_C(  5) },
      { UINT8_C(133), UINT8_C(151), UINT8_C( 95),    UINT8_MAX, UINT8_C(101), UINT8_C(207), UINT8_C(112), UINT8_C(222),
        UINT8_C(213), UINT8_C(159), UINT8_C(224), UINT8_C( 49), UINT8_C( 49), UINT8_C(196), UINT8_C(  5), UINT8_C( 70) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comge_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(32681), UINT16_C(  685), UINT16_C(39060), UINT16_C( 4367), UINT16_C(41735), UINT16_C(16386), UINT16_C(33447), UINT16_C( 9837) },
      { UINT16_C(32681), UINT16_C(  685), UINT16_C(39060), UINT16_C( 4367), UINT16_C(41735), UINT16_C(16386), UINT16_C(33447), UINT16_C( 9837) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(11195), UINT16_C( 2815), UINT16_C(44166), UINT16_C(  288), UINT16_C(27859), UINT16_C(22311), UINT16_C(46033), UINT16_C(12493) },
      { UINT16_C(27681), UINT16_C(28641), UINT16_C(10798), UINT16_C(55102), UINT16_C(27325), UINT16_C(28923), UINT16_C( 6341), UINT16_C(11745) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(21632), UINT16_C(52002), UINT16_C(30146), UINT16_C(64583), UINT16_C(20106), UINT16_C(50539), UINT16_C(45526), UINT16_C( 9639) },
      { UINT16_C(12988), UINT16_C(63437), UINT16_C(11703), UINT16_C( 6489), UINT16_C( 2879), UINT16_C(52900), UINT16_C(49308), UINT16_C(24923) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(39163), UINT16_C( 3120), UINT16_C(13506), UINT16_C( 6095), UINT16_C(53025), UINT16_C(17428), UINT16_C(51177), UINT16_C(27515) },
      { UINT16_C(22690), UINT16_C(25304), UINT16_C(43736), UINT16_C( 8008), UINT16_C( 3765), UINT16_C( 8551), UINT16_C(34005), UINT16_C( 3267) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(33365), UINT16_C(37777), UINT16_C(61485), UINT16_C(39583), UINT16_C(30656), UINT16_C(40074), UINT16_C(64434), UINT16_C(19249) },
      { UINT16_C(26362), UINT16_C(30569), UINT16_C(43064), UINT16_C(12787), UINT16_C(64584), UINT16_C(12459), UINT16_C(27671), UINT16_C(29697) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(38837), UINT16_C(10413), UINT16_C(45740), UINT16_C(52639), UINT16_C(52625), UINT16_C(38197), UINT16_C(22488), UINT16_C( 3505) },
      { UINT16_C(58860), UINT16_C(65514), UINT16_C(12160), UINT16_C(38722), UINT16_C(23327), UINT16_C(50391), UINT16_C(32523), UINT16_C(57854) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(24900), UINT16_C(38381), UINT16_C(33255), UINT16_C(63671), UINT16_C(22969), UINT16_C(63358), UINT16_C(58116), UINT16_C(63971) },
      { UINT16_C(23714), UINT16_C(50114), UINT16_C(18519), UINT16_C(38941), UINT16_C(46692), UINT16_C(42325), UINT16_C(50520), UINT16_C(40352) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(26410), UINT16_C(41399), UINT16_C(25989), UINT16_C(25295), UINT16_C(41827), UINT16_C(35275), UINT16_C(42717), UINT16_C(22448) },
      { UINT16_C(21313), UINT16_C(34905), UINT16_C(63846), UINT16_C(32364), UINT16_C(37436), UINT16_C(39820), UINT16_C(18087), UINT16_C(61392) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comge_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 326381966), UINT32_C(1422878255), UINT32_C( 344274101), UINT32_C(1862182924) },
      { UINT32_C( 326381966), UINT32_C(1422878255), UINT32_C( 344274101), UINT32_C(1862182924) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 420958964), UINT32_C(2400668756), UINT32_C(1860467153), UINT32_C( 511118240) },
      { UINT32_C(3029158040), UINT32_C( 379555212), UINT32_C(1612026839), UINT32_C(2276979000) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1030021857), UINT32_C( 335956426), UINT32_C(3854955083), UINT32_C(1937447914) },
      { UINT32_C(1281897330), UINT32_C(4029210949), UINT32_C( 903956722), UINT32_C(3938552330) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3148384816), UINT32_C(1411512176), UINT32_C(3398928082), UINT32_C( 918978094) },
      { UINT32_C(2741992001), UINT32_C( 709913089), UINT32_C(1532222510), UINT32_C(3741743658) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1548473098), UINT32_C(2572246765), UINT32_C(3821190028), UINT32_C(2940091667) },
      { UINT32_C(2148116016), UINT32_C( 184562025), UINT32_C(2580731570), UINT32_C(2926364991) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3904193687), UINT32_C( 696026858), UINT32_C(4188937380), UINT32_C( 634216258) },
      { UINT32_C(2895986276), UINT32_C(3693165860), UINT32_C(3116744359), UINT32_C(2665316337) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 659449342), UINT32_C(1300985870), UINT32_C(3552849472), UINT32_C(3797609570) },
      { UINT32_C(4036348424), UINT32_C(3868825563), UINT32_C(2174098740), UINT32_C(4164986346) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3766468200), UINT32_C(1298610946), UINT32_C( 996834185), UINT32_C( 751627548) },
      { UINT32_C( 307810882), UINT32_C(1850885430), UINT32_C(3131865474), UINT32_C(  92029903) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comge_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comge_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 8211987837427308796), UINT64_C( 5480151877524490918) },
      { UINT64_C( 8211987837427308796), UINT64_C( 5480151877524490918) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(13777164219077025594), UINT64_C(  755302138987371961) },
      { UINT64_C(   81722270716082915), UINT64_C( 9945189316467286975) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 2315908445777131546), UINT64_C( 5918859128641900032) },
      { UINT64_C( 4959233173195746372), UINT64_C( 3285923985569812478) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(15567995769879471623), UINT64_C( 2620873581216454271) },
      { UINT64_C( 9506557910353180488), UINT64_C( 9201997689620698505) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 3518706747851305003), UINT64_C(14345092700155837535) },
      { UINT64_C(  458634775754859030), UINT64_C(14284795380240678280) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8099097797183463086), UINT64_C( 9523822594807941320) },
      { UINT64_C( 1515945609713235416), UINT64_C( 5412243535409106980) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(16187658354348390584), UINT64_C(11785212616360215521) },
      { UINT64_C(17931385931382127027), UINT64_C( 6213328243168416900) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(14375210412457215855), UINT64_C( 7791293546164876499) },
      { UINT64_C(17777258666399839697), UINT64_C( 3350089076668880082) },
      { UINT64_C(                   0),                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comge_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comge_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   2),  INT8_C(  82), -INT8_C(  67),  INT8_C(  54), -INT8_C(  53),  INT8_C( 122), -INT8_C(  40),  INT8_C( 111),
        -INT8_C(  59), -INT8_C(  28), -INT8_C(  47),  INT8_C(  30),  INT8_C(  38), -INT8_C(  76), -INT8_C(  51),  INT8_C(  38) },
      { -INT8_C(   2),  INT8_C(  82), -INT8_C(  67),  INT8_C(  54), -INT8_C(  53),  INT8_C( 122), -INT8_C(  40),  INT8_C( 111),
        -INT8_C(  59), -INT8_C(  28), -INT8_C(  47),  INT8_C(  30),  INT8_C(  38), -INT8_C(  76), -INT8_C(  51),  INT8_C(  38) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  90),  INT8_C( 113), -INT8_C(  57), -INT8_C(  27),  INT8_C(  89),  INT8_C(   9), -INT8_C( 123),  INT8_C(  89),
         INT8_C(  51),  INT8_C(  21), -INT8_C(  53), -INT8_C( 121), -INT8_C(  20),  INT8_C(  95), -INT8_C(  50),  INT8_C(  29) },
      { -INT8_C( 117), -INT8_C(  95), -INT8_C(  21),  INT8_C(  86),  INT8_C( 110), -INT8_C( 112), -INT8_C( 103),  INT8_C(  30),
        -INT8_C(  32),  INT8_C(  25), -INT8_C(  99),  INT8_C( 119), -INT8_C(  18), -INT8_C(  21),  INT8_C( 125),  INT8_C(  27) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C( 118),  INT8_C(  53),  INT8_C(  54),  INT8_C(  98),      INT8_MIN, -INT8_C(  79),  INT8_C(  49),  INT8_C( 103),
        -INT8_C(  47), -INT8_C(  31),  INT8_C( 116),  INT8_C( 102), -INT8_C(  66), -INT8_C( 103),  INT8_C(  22),  INT8_C( 105) },
      {  INT8_C(  63), -INT8_C(  67), -INT8_C(  11),  INT8_C(  36),  INT8_C(  68),  INT8_C(  76), -INT8_C(  85),  INT8_C(  29),
         INT8_C(  76), -INT8_C(  99), -INT8_C(  67),  INT8_C(  16),  INT8_C(  51), -INT8_C(  23),  INT8_C(  22), -INT8_C( 111) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  75),  INT8_C(  10), -INT8_C(  76), -INT8_C(  13), -INT8_C(  81), -INT8_C( 126), -INT8_C(  94),  INT8_C( 105),
        -INT8_C(  44), -INT8_C(  65),  INT8_C(  38),  INT8_C( 107),  INT8_C(  97), -INT8_C(  98),  INT8_C(  59),  INT8_C(  91) },
      {  INT8_C(  65),  INT8_C(  45),  INT8_C(  65),  INT8_C( 105), -INT8_C(  10), -INT8_C(  75), -INT8_C(  12), -INT8_C(  76),
         INT8_C(  48), -INT8_C(   8), -INT8_C( 101), -INT8_C(  79), -INT8_C(  98), -INT8_C(  73), -INT8_C( 127), -INT8_C(  47) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(   4),  INT8_C( 119), -INT8_C(  87),  INT8_C(  94), -INT8_C( 114), -INT8_C( 123), -INT8_C(  66), -INT8_C(  90),
         INT8_C( 100),  INT8_C(  56),  INT8_C(  73),  INT8_C(  92),  INT8_C( 126),  INT8_C( 118),  INT8_C(  39),  INT8_C(  59) },
      { -INT8_C(  70),  INT8_C( 121),  INT8_C(  57), -INT8_C(  20),  INT8_C(  43), -INT8_C(  45),  INT8_C(  93),  INT8_C(  42),
        -INT8_C(  76), -INT8_C(  80), -INT8_C(  99),  INT8_C(  36), -INT8_C(  42),  INT8_C(  92), -INT8_C(  89),  INT8_C(  35) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  57),  INT8_C(   5),  INT8_C( 125),  INT8_C( 108), -INT8_C(  60), -INT8_C(  63),  INT8_C( 110),  INT8_C( 104),
        -INT8_C(  89), -INT8_C(  45),  INT8_C(  69),  INT8_C(   2), -INT8_C(  68),  INT8_C(  42), -INT8_C(  64),  INT8_C(  81) },
      { -INT8_C(  47),  INT8_C(  42),  INT8_C(  68),  INT8_C( 119), -INT8_C( 116), -INT8_C(  81), -INT8_C(  50), -INT8_C(  55),
         INT8_C(   2),  INT8_C(  79),  INT8_C(  45),  INT8_C(  48), -INT8_C( 124), -INT8_C(  32),  INT8_C( 111), -INT8_C(  50) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { { -INT8_C(  68),  INT8_C(  58), -INT8_C( 103), -INT8_C(  27), -INT8_C(   6),  INT8_C(  62), -INT8_C( 101), -INT8_C(  11),
        -INT8_C(  56),  INT8_C(  24), -INT8_C( 126),  INT8_C(  37), -INT8_C(  60), -INT8_C(  64), -INT8_C(  16), -INT8_C(  28) },
      { -INT8_C(  81), -INT8_C(  57), -INT8_C(  55), -INT8_C(  48), -INT8_C(  63),  INT8_C(  80),  INT8_C(  48), -INT8_C(  41),
         INT8_C(  63),  INT8_C(  93), -INT8_C(  78), -INT8_C( 100),  INT8_C(  80),  INT8_C(  76), -INT8_C(  64),  INT8_C(  28) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  13), -INT8_C(  95),  INT8_C(  99), -INT8_C( 111), -INT8_C(  41),  INT8_C(   5),  INT8_C(  43), -INT8_C( 105),
        -INT8_C(  19), -INT8_C( 113),  INT8_C( 105), -INT8_C( 115),  INT8_C(  61),  INT8_C(  67), -INT8_C(  99),  INT8_C(  62) },
      {  INT8_C( 123), -INT8_C(  40),  INT8_C(  50), -INT8_C(  64),  INT8_C( 113), -INT8_C(  65),  INT8_C( 105), -INT8_C(  99),
        -INT8_C( 106),  INT8_C(  96), -INT8_C( 108),  INT8_C(  49), -INT8_C(  31), -INT8_C(  89), -INT8_C( 124),  INT8_C(  83) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comgt_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 16417),  INT16_C( 14404),  INT16_C(  7428), -INT16_C( 27896), -INT16_C( 16065),  INT16_C(   352), -INT16_C( 18224), -INT16_C( 23119) },
      { -INT16_C( 16417),  INT16_C( 14404),  INT16_C(  7428), -INT16_C( 27896), -INT16_C( 16065),  INT16_C(   352), -INT16_C( 18224), -INT16_C( 23119) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  6562),  INT16_C(  4070),  INT16_C(   580),  INT16_C( 25443), -INT16_C(  7635), -INT16_C( 18630), -INT16_C(  1568), -INT16_C( 17246) },
      {  INT16_C(  7773), -INT16_C( 24155), -INT16_C( 29144),  INT16_C( 13336),  INT16_C( 13797),  INT16_C( 19408),  INT16_C( 10533),  INT16_C( 25107) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 30848), -INT16_C( 31411),  INT16_C(  9188),  INT16_C( 28932),  INT16_C( 27180), -INT16_C(  2546),  INT16_C( 19188), -INT16_C( 24830) },
      {  INT16_C( 17836), -INT16_C( 27156),  INT16_C( 25068), -INT16_C( 16059),  INT16_C( 29447),  INT16_C( 12578), -INT16_C( 25117), -INT16_C( 16981) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C(  5640), -INT16_C(  5425),  INT16_C( 10742),  INT16_C(  3638), -INT16_C( 32324), -INT16_C( 19081), -INT16_C( 23610),  INT16_C( 17548) },
      { -INT16_C( 17161), -INT16_C(  9085), -INT16_C( 25096), -INT16_C( 32395),  INT16_C(  1231),  INT16_C( 31932),  INT16_C(  7603), -INT16_C(   671) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 18462),  INT16_C(  1492),  INT16_C(  7461), -INT16_C( 31776), -INT16_C( 21243), -INT16_C( 16675),  INT16_C(  3070), -INT16_C(  3544) },
      {  INT16_C(  3172),  INT16_C( 16080),  INT16_C( 19187), -INT16_C( 17006),  INT16_C( 28515), -INT16_C(  3064), -INT16_C( 20420),  INT16_C( 27677) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C( 26644), -INT16_C( 24636),  INT16_C(  1558),  INT16_C(  6634),  INT16_C( 31022), -INT16_C( 10328), -INT16_C( 29885), -INT16_C(  3138) },
      { -INT16_C( 17381), -INT16_C( 31939),  INT16_C( 29061), -INT16_C( 16765),  INT16_C( 15595),  INT16_C( 24684),  INT16_C( 24103),  INT16_C( 20679) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 30057), -INT16_C( 32761), -INT16_C(  5004),  INT16_C(  5435),  INT16_C( 27231), -INT16_C( 14015),  INT16_C( 10813), -INT16_C( 29386) },
      {  INT16_C( 21573),  INT16_C( 29232),  INT16_C(  6487), -INT16_C( 14032), -INT16_C(  2928), -INT16_C( 30382),  INT16_C( 12059), -INT16_C(  3513) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 21942),  INT16_C( 28677), -INT16_C( 10011), -INT16_C( 15683),  INT16_C(  2754),  INT16_C( 23310), -INT16_C(  3947),  INT16_C(  2424) },
      {  INT16_C( 23562), -INT16_C( 11245),  INT16_C( 18961),  INT16_C( 10625),  INT16_C(  7801),  INT16_C( 14369),  INT16_C( 11457), -INT16_C( 25979) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comgt_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   925334827),  INT32_C(  1733808145),  INT32_C(  1467539580), -INT32_C(  1351817741) },
      {  INT32_C(   925334827),  INT32_C(  1733808145),  INT32_C(  1467539580), -INT32_C(  1351817741) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1900895633),  INT32_C(   610143323),  INT32_C(   859914960), -INT32_C(  1872077631) },
      { -INT32_C(  1663857310),  INT32_C(  1274142626), -INT32_C(  2081917768), -INT32_C(   956624130) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(   289857283),  INT32_C(    78604507),  INT32_C(  1109059770),  INT32_C(   467454146) },
      {  INT32_C(  1769103896), -INT32_C(  1217131971), -INT32_C(  1446752356), -INT32_C(  1744077217) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  2087086215),  INT32_C(   257713468),  INT32_C(   789879137), -INT32_C(  2067499412) },
      {  INT32_C(  1684898421), -INT32_C(   205104244), -INT32_C(  1888094128),  INT32_C(  1803891134) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  2031452742), -INT32_C(  1907553244), -INT32_C(  1047012115),  INT32_C(   336293992) },
      {  INT32_C(  1445623712),  INT32_C(  1204869431), -INT32_C(    26937347), -INT32_C(  2007878463) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(   759450520), -INT32_C(   932486084), -INT32_C(  1089783162),  INT32_C(   278380126) },
      {  INT32_C(   101960130), -INT32_C(    75854618), -INT32_C(  1107765813),  INT32_C(   928550419) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1304462868),  INT32_C(   127694123), -INT32_C(   220710318), -INT32_C(  1018009867) },
      {  INT32_C(  1049624066),  INT32_C(  1454210368), -INT32_C(  1768416799), -INT32_C(  1082046630) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1282637454), -INT32_C(  1849079911),  INT32_C(   577135740),  INT32_C(  1948480214) },
      { -INT32_C(  1006264183), -INT32_C(  1588612115),  INT32_C(  1336822632),  INT32_C(  1790208063) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comgt_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5702714704422032213),  INT64_C( 7706197349837389866) },
      { -INT64_C( 5702714704422032213),  INT64_C( 7706197349837389866) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 2686738672218224510),  INT64_C( 9140610051560567943) },
      { -INT64_C( 6217130683109076761), -INT64_C( 1250078657332488315) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 2847418335753423114),  INT64_C( 4960714446316608359) },
      { -INT64_C( 4086288290319453363),  INT64_C( 5199751851530465460) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C(  943709202321481643),  INT64_C(  331162107166771247) },
      {  INT64_C( 5870370027943010054), -INT64_C( 4584062603918486561) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 3649639699874643066),  INT64_C(  433351727370470152) },
      { -INT64_C( 8202798520132215751), -INT64_C( 7045432456963077840) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C(   16632113310352442), -INT64_C( 7998338059497122534) },
      { -INT64_C( 4087067891782225905),  INT64_C( 2996758406856088013) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C( 3382370887748153796), -INT64_C( 1263429811204012660) },
      {  INT64_C( 5024271936180938160), -INT64_C( 6169576172347208738) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 8421059571642366447),  INT64_C( 7372456205302914183) },
      {  INT64_C( 5577648488510702403),  INT64_C( 7602790810320267404) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comgt_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(108), UINT8_C(171), UINT8_C(201), UINT8_C(204), UINT8_C(217), UINT8_C(227), UINT8_C(229), UINT8_C(117),
        UINT8_C( 50), UINT8_C( 32), UINT8_C(146), UINT8_C(119), UINT8_C( 76), UINT8_C(180), UINT8_C(115), UINT8_C( 63) },
      { UINT8_C(108), UINT8_C(171), UINT8_C(201), UINT8_C(204), UINT8_C(217), UINT8_C(227), UINT8_C(229), UINT8_C(117),
        UINT8_C( 50), UINT8_C( 32), UINT8_C(146), UINT8_C(119), UINT8_C( 76), UINT8_C(180), UINT8_C(115), UINT8_C( 63) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(241), UINT8_C( 16), UINT8_C(192), UINT8_C(119), UINT8_C( 50), UINT8_C(207), UINT8_C( 57), UINT8_C( 42),
        UINT8_C(254), UINT8_C(247), UINT8_C( 94), UINT8_C( 41), UINT8_C(244), UINT8_C(123), UINT8_C(225), UINT8_C(174) },
      { UINT8_C(118), UINT8_C(  4), UINT8_C( 92), UINT8_C( 64),    UINT8_MAX, UINT8_C(240), UINT8_C( 64), UINT8_C(214),
        UINT8_C(182), UINT8_C(155), UINT8_C( 13), UINT8_C( 63), UINT8_C( 67), UINT8_C(222), UINT8_C(201), UINT8_C(193) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(225), UINT8_C(214), UINT8_C(171), UINT8_C(  1), UINT8_C(180), UINT8_C(231), UINT8_C( 23), UINT8_C( 34),
        UINT8_C( 94), UINT8_C(  0), UINT8_C(207), UINT8_C( 49), UINT8_C(205), UINT8_C( 32), UINT8_C(103), UINT8_C(193) },
      { UINT8_C( 86), UINT8_C( 25), UINT8_C(249), UINT8_C(210), UINT8_C(  8), UINT8_C(148), UINT8_C( 27), UINT8_C(248),
        UINT8_C( 58), UINT8_C( 85), UINT8_C( 14), UINT8_C(185), UINT8_C(103), UINT8_C(192), UINT8_C( 56), UINT8_C( 54) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 60), UINT8_C(156), UINT8_C(212), UINT8_C( 14), UINT8_C(238), UINT8_C( 24), UINT8_C(233), UINT8_C(127),
        UINT8_C(209), UINT8_C( 11), UINT8_C(120), UINT8_C(206), UINT8_C( 39), UINT8_C(128), UINT8_C(250), UINT8_C(233) },
      { UINT8_C( 53), UINT8_C(114), UINT8_C( 10), UINT8_C( 76), UINT8_C(157), UINT8_C(212), UINT8_C( 94), UINT8_C( 33),
        UINT8_C(231), UINT8_C(213), UINT8_C(251), UINT8_C(171), UINT8_C( 97), UINT8_C( 97), UINT8_C(169), UINT8_C(228) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 41), UINT8_C(235), UINT8_C(165), UINT8_C(101), UINT8_C(136), UINT8_C(106), UINT8_C(151), UINT8_C(135),
        UINT8_C(129), UINT8_C(161), UINT8_C(195), UINT8_C(200), UINT8_C(170), UINT8_C(164), UINT8_C(131), UINT8_C(112) },
      { UINT8_C( 59), UINT8_C(152), UINT8_C(245), UINT8_C(116), UINT8_C(101), UINT8_C(186), UINT8_C(241), UINT8_C(154),
        UINT8_C(229), UINT8_C(163), UINT8_C( 62), UINT8_C(222), UINT8_C(216), UINT8_C(202), UINT8_C(  5), UINT8_C( 20) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(209), UINT8_C( 74), UINT8_C(133), UINT8_C(208), UINT8_C( 41), UINT8_C(229), UINT8_C(  9), UINT8_C(131),
        UINT8_C(150), UINT8_C( 73), UINT8_C( 23), UINT8_C(230),    UINT8_MAX, UINT8_C(147), UINT8_C(235), UINT8_C(156) },
      { UINT8_C(143), UINT8_C( 18), UINT8_C( 36), UINT8_C( 19), UINT8_C(  9), UINT8_C( 77), UINT8_C(188), UINT8_C(171),
        UINT8_C( 91), UINT8_C( 71), UINT8_C( 61), UINT8_C( 26), UINT8_C(117), UINT8_C(  1), UINT8_C( 50), UINT8_C( 15) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 91), UINT8_C( 65), UINT8_C(220), UINT8_C( 21), UINT8_C(121), UINT8_C(146), UINT8_C( 39), UINT8_C(186),
        UINT8_C( 56), UINT8_C(140), UINT8_C(220), UINT8_C(241), UINT8_C(206), UINT8_C( 85), UINT8_C( 24), UINT8_C(182) },
      { UINT8_C( 90), UINT8_C(104), UINT8_C(253), UINT8_C(240), UINT8_C( 48), UINT8_C(149), UINT8_C(167), UINT8_C(155),
        UINT8_C(113), UINT8_C( 73), UINT8_C( 98), UINT8_C( 38), UINT8_C(224), UINT8_C( 16), UINT8_C( 26), UINT8_C( 26) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(240), UINT8_C( 88), UINT8_C( 19), UINT8_C(253), UINT8_C( 34), UINT8_C(120), UINT8_C(218), UINT8_C(118),
        UINT8_C(141), UINT8_C(241), UINT8_C(123), UINT8_C(178), UINT8_C(190), UINT8_C(243), UINT8_C(244), UINT8_C(  5) },
      { UINT8_C(195), UINT8_C( 35), UINT8_C(234), UINT8_C(213), UINT8_C(131), UINT8_C(155), UINT8_C(155), UINT8_C(180),
        UINT8_C( 81), UINT8_C( 50), UINT8_C( 20), UINT8_C(204), UINT8_C(192), UINT8_C(254), UINT8_C(163), UINT8_C(128) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comgt_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 6328), UINT16_C(20624), UINT16_C(40905), UINT16_C(64776), UINT16_C(  192), UINT16_C(61018), UINT16_C(29816), UINT16_C(54118) },
      { UINT16_C( 6328), UINT16_C(20624), UINT16_C(40905), UINT16_C(64776), UINT16_C(  192), UINT16_C(61018), UINT16_C(29816), UINT16_C(54118) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(51955), UINT16_C(34897), UINT16_C(26281), UINT16_C(15486), UINT16_C(35360), UINT16_C(53946), UINT16_C(54461), UINT16_C(34743) },
      { UINT16_C( 2266), UINT16_C(54972), UINT16_C( 4121), UINT16_C(39322), UINT16_C(16887), UINT16_C(28898), UINT16_C(57508), UINT16_C(26197) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(58642), UINT16_C(53916), UINT16_C(65099), UINT16_C(31802), UINT16_C(55049), UINT16_C(  446), UINT16_C(39296), UINT16_C(31037) },
      { UINT16_C(45439), UINT16_C(22271), UINT16_C(53943), UINT16_C(36729), UINT16_C(15706), UINT16_C(65403), UINT16_C(16617), UINT16_C( 2219) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(64583), UINT16_C(31538), UINT16_C(27665), UINT16_C(48309), UINT16_C(41778), UINT16_C( 8583), UINT16_C(21937), UINT16_C(39965) },
      { UINT16_C(39374), UINT16_C(39618), UINT16_C(60750), UINT16_C(10891), UINT16_C(31507), UINT16_C(25230), UINT16_C(39919), UINT16_C(65103) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(39098), UINT16_C(19323), UINT16_C(47010), UINT16_C(17625), UINT16_C(30147), UINT16_C(64125), UINT16_C( 4600), UINT16_C(14655) },
      { UINT16_C(19184), UINT16_C(26731), UINT16_C(27268), UINT16_C(45498), UINT16_C(33607), UINT16_C(25217), UINT16_C(63839), UINT16_C(37673) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(16532), UINT16_C( 2783), UINT16_C(59303), UINT16_C(23436), UINT16_C(55013), UINT16_C(21256), UINT16_C(54523), UINT16_C(38795) },
      { UINT16_C(19468), UINT16_C(35172), UINT16_C(20481), UINT16_C(27629), UINT16_C(56865), UINT16_C(51134), UINT16_C(25313), UINT16_C( 3617) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(32253), UINT16_C(32710), UINT16_C( 1479), UINT16_C(19128), UINT16_C(19903), UINT16_C(63120), UINT16_C(42597), UINT16_C(  233) },
      { UINT16_C( 9547), UINT16_C(50451), UINT16_C(42862), UINT16_C(41228), UINT16_C( 5062), UINT16_C(22955), UINT16_C(57116), UINT16_C(46623) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(54812), UINT16_C(29592), UINT16_C( 6315), UINT16_C(23108), UINT16_C(25211), UINT16_C(43389), UINT16_C(36828), UINT16_C(47681) },
      { UINT16_C(24533), UINT16_C(58338), UINT16_C(30835), UINT16_C(40190), UINT16_C(43617), UINT16_C(57266), UINT16_C(30649), UINT16_C(54539) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comgt_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2931675930), UINT32_C(3491244283), UINT32_C( 892837182), UINT32_C( 242980872) },
      { UINT32_C(2931675930), UINT32_C(3491244283), UINT32_C( 892837182), UINT32_C( 242980872) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2906161617), UINT32_C(2712521399), UINT32_C( 591014936), UINT32_C(2983015263) },
      { UINT32_C(4171168798), UINT32_C(4145823326), UINT32_C(1646692147), UINT32_C(1149225107) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3917223015), UINT32_C(4211123683), UINT32_C(3953795091), UINT32_C(2454526391) },
      { UINT32_C( 430037585), UINT32_C( 372793468), UINT32_C(4155746175), UINT32_C(2754947106) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1612226497), UINT32_C(4041150878), UINT32_C(   7081595), UINT32_C(3262395497) },
      { UINT32_C(3627021531), UINT32_C(1951701502), UINT32_C(3192161613), UINT32_C(1988476512) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3665013252), UINT32_C(3392280465), UINT32_C( 719814264), UINT32_C(2284357916) },
      { UINT32_C(4273066723), UINT32_C(1515777676), UINT32_C(2101586627), UINT32_C(  22582514) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 536198747), UINT32_C(3487678052), UINT32_C( 813955377), UINT32_C( 726803064) },
      { UINT32_C(1401814417), UINT32_C( 271346125), UINT32_C(4246117641), UINT32_C(2392109699) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(4127613676), UINT32_C(1221922750), UINT32_C(3701999311), UINT32_C(4107994663) },
      { UINT32_C(2670590990), UINT32_C(3736605034), UINT32_C( 103278152), UINT32_C(1696800441) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 672014047), UINT32_C(2096369735), UINT32_C(4106104441), UINT32_C( 732511694) },
      { UINT32_C(2868336514), UINT32_C( 216395274), UINT32_C(1625034408), UINT32_C(3471565372) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comgt_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comgt_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(13053625969493244509), UINT64_C( 1776335905635563608) },
      { UINT64_C(13053625969493244509), UINT64_C( 1776335905635563608) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16256034595954595605), UINT64_C( 1285222121653378128) },
      { UINT64_C( 4131850939565080462), UINT64_C(  196125019575610516) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(12014875886658405357), UINT64_C( 8488037129192413289) },
      { UINT64_C( 5938715815015691417), UINT64_C( 3731556851665834580) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(11833795783221175093), UINT64_C( 4877831776391334682) },
      { UINT64_C( 4992985007803179430), UINT64_C(17420199667699905472) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 2375114234258259987), UINT64_C(14155653048210685068) },
      { UINT64_C( 6763726840653205471), UINT64_C( 9621179381699646978) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 7339593446906798511), UINT64_C( 4464734439121646566) },
      { UINT64_C(16216730157518636394), UINT64_C( 3963201710570668863) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(13461328380725022258), UINT64_C(17952021491942488145) },
      { UINT64_C( 1783462140442348399), UINT64_C( 5627667542317712290) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 7402917169343205316), UINT64_C( 4603078424171451637) },
      { UINT64_C( 5467596465290160663), UINT64_C( 1493066304789536080) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comgt_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comgt_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 116), -INT8_C(  19),  INT8_C(  26), -INT8_C( 107),  INT8_C(  78),  INT8_C(  25), -INT8_C( 119), -INT8_C(  78),
        -INT8_C(   7),  INT8_C(  78),      INT8_MAX,  INT8_C(  74),  INT8_C(   0),  INT8_C(   9),  INT8_C(  26),  INT8_C(  86) },
      { -INT8_C( 116), -INT8_C(  19),  INT8_C(  26), -INT8_C( 107),  INT8_C(  78),  INT8_C(  25), -INT8_C( 119), -INT8_C(  78),
        -INT8_C(   7),  INT8_C(  78),      INT8_MAX,  INT8_C(  74),  INT8_C(   0),  INT8_C(   9),  INT8_C(  26),  INT8_C(  86) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C( 119), -INT8_C(  87), -INT8_C(  52), -INT8_C(  52), -INT8_C(  62),  INT8_C( 115),  INT8_C(  84), -INT8_C(  61),
         INT8_C( 116), -INT8_C(  39), -INT8_C(  19), -INT8_C(  41), -INT8_C(  38), -INT8_C(   4), -INT8_C(  59), -INT8_C(  49) },
      { -INT8_C(  77),  INT8_C( 111), -INT8_C(  80),  INT8_C( 125), -INT8_C( 106),  INT8_C(  62),  INT8_C(  30), -INT8_C(  26),
        -INT8_C( 122),  INT8_C(  47),  INT8_C(  75), -INT8_C(  93), -INT8_C(  58),  INT8_C(  71), -INT8_C(  75), -INT8_C( 121) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  18), -INT8_C( 112), -INT8_C(  45), -INT8_C( 126),  INT8_C(  63),  INT8_C(  26),  INT8_C(   4), -INT8_C(  59),
         INT8_C(  52),  INT8_C(  64), -INT8_C(  58),  INT8_C(  39),  INT8_C(  89),  INT8_C(  44),  INT8_C(  40), -INT8_C(  56) },
      {  INT8_C(  96), -INT8_C(  98), -INT8_C( 126), -INT8_C(  12),  INT8_C( 114), -INT8_C(  24),  INT8_C(  99),  INT8_C(  74),
        -INT8_C(  61),  INT8_C(  62), -INT8_C(  53),  INT8_C(  29),  INT8_C( 105),  INT8_C(  44), -INT8_C( 102),  INT8_C(  26) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C( 110),  INT8_C( 104),  INT8_C(  73),  INT8_C(  43),  INT8_C(  36), -INT8_C(  54), -INT8_C(  40), -INT8_C( 100),
        -INT8_C(  72), -INT8_C( 103),  INT8_C(   7),  INT8_C( 125),  INT8_C(  10),  INT8_C(   8), -INT8_C(  55),  INT8_C(  71) },
      { -INT8_C(  68),  INT8_C(   0), -INT8_C(  10), -INT8_C(  62), -INT8_C( 118),  INT8_C(  32),  INT8_C(  64),  INT8_C(  37),
        -INT8_C(  39),  INT8_C(   3),  INT8_C( 104),      INT8_MAX, -INT8_C( 110), -INT8_C(  63), -INT8_C(  78),  INT8_C(  87) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  48), -INT8_C(  72), -INT8_C( 106), -INT8_C( 113),  INT8_C(  24), -INT8_C( 116), -INT8_C(  72), -INT8_C( 113),
         INT8_C(  41),  INT8_C( 108),  INT8_C(  26), -INT8_C(  97), -INT8_C( 107), -INT8_C( 105), -INT8_C( 112), -INT8_C( 109) },
      { -INT8_C(  17),  INT8_C(  31),  INT8_C( 117), -INT8_C(  82), -INT8_C( 123), -INT8_C(  19), -INT8_C(  99), -INT8_C(  63),
        -INT8_C(  17),  INT8_C(   6), -INT8_C( 118), -INT8_C( 109), -INT8_C(  24),  INT8_C(  13), -INT8_C(  29), -INT8_C( 123) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  93),  INT8_C(   8),  INT8_C(  33),  INT8_C( 118), -INT8_C(  60),  INT8_C( 103), -INT8_C( 116), -INT8_C(  27),
        -INT8_C(  81),  INT8_C(  66),  INT8_C( 102),  INT8_C(  85), -INT8_C(  95), -INT8_C(  30),  INT8_C( 102), -INT8_C(  10) },
      {  INT8_C(  32), -INT8_C( 125),  INT8_C( 104), -INT8_C( 127),  INT8_C(  11),  INT8_C(  88),  INT8_C(  98),  INT8_C( 100),
         INT8_C(  46), -INT8_C(  48), -INT8_C( 102),  INT8_C(  31),  INT8_C(  20),  INT8_C(  24),  INT8_C(  22), -INT8_C(  18) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  28), -INT8_C(  31),  INT8_C(  84), -INT8_C(  88), -INT8_C(  49),  INT8_C(  99),  INT8_C(  60), -INT8_C(  25),
         INT8_C( 113), -INT8_C(  95),  INT8_C(  83),  INT8_C( 105), -INT8_C(  42), -INT8_C(  17),  INT8_C(  49), -INT8_C(  74) },
      {  INT8_C( 120), -INT8_C(  78),  INT8_C(  53),  INT8_C(   3), -INT8_C(  58),  INT8_C( 104),  INT8_C( 119),  INT8_C(  87),
        -INT8_C(  66), -INT8_C(  24), -INT8_C(   2), -INT8_C(  20), -INT8_C(  67), -INT8_C(  22),  INT8_C(  52), -INT8_C(  40) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C( 106), -INT8_C(  55), -INT8_C( 106), -INT8_C(  20), -INT8_C(  30), -INT8_C( 120), -INT8_C(  80), -INT8_C(  35),
        -INT8_C( 104),  INT8_C(  20),  INT8_C(  73), -INT8_C(  95), -INT8_C(  34), -INT8_C(  56), -INT8_C(  37),  INT8_C(  28) },
      {  INT8_C(  30),  INT8_C(  54),  INT8_C(  70), -INT8_C(   4),  INT8_C(  91),  INT8_C(  37), -INT8_C(  60), -INT8_C(  30),
        -INT8_C(  58), -INT8_C(  42),  INT8_C(  32), -INT8_C(  62), -INT8_C( 116), -INT8_C( 116),  INT8_C(  35), -INT8_C( 116) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comle_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 19187),  INT16_C(  3152), -INT16_C(  8283),  INT16_C(  4049),  INT16_C(  8267), -INT16_C( 14416),  INT16_C( 30046),  INT16_C( 28746) },
      {  INT16_C( 19187),  INT16_C(  3152), -INT16_C(  8283),  INT16_C(  4049),  INT16_C(  8267), -INT16_C( 14416),  INT16_C( 30046),  INT16_C( 28746) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 26822),  INT16_C( 13313), -INT16_C( 26763),  INT16_C( 19506),  INT16_C(  9070),  INT16_C( 26983),  INT16_C(  1321),  INT16_C( 21197) },
      { -INT16_C(  5030), -INT16_C( 12568),  INT16_C( 28607), -INT16_C( 15227),  INT16_C( 20403), -INT16_C( 24080), -INT16_C(  1023), -INT16_C(  1432) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 23542),  INT16_C( 29648), -INT16_C( 14406), -INT16_C(  8281),  INT16_C( 22240), -INT16_C( 22470),  INT16_C( 23867),  INT16_C( 28952) },
      {  INT16_C( 14067), -INT16_C(  1081),  INT16_C( 16601),  INT16_C( 17845),  INT16_C( 10488), -INT16_C(  1935),  INT16_C( 26476),  INT16_C(   283) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C(  3192), -INT16_C( 32742), -INT16_C( 17198), -INT16_C(  7924), -INT16_C(  2239),  INT16_C( 18435), -INT16_C( 25494),  INT16_C( 13294) },
      { -INT16_C( 20249),  INT16_C( 23381),  INT16_C( 23450), -INT16_C(  9398),  INT16_C( 13121), -INT16_C( 27748), -INT16_C( 16822), -INT16_C( 12467) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 12776),  INT16_C(  9286),  INT16_C( 32358), -INT16_C( 25782), -INT16_C( 28996),  INT16_C(  4649), -INT16_C( 13472), -INT16_C(  8650) },
      { -INT16_C(  7586), -INT16_C( 18950), -INT16_C( 14421), -INT16_C( 13270), -INT16_C(  1610),  INT16_C( 15575),  INT16_C(  1857), -INT16_C( 21787) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 21359),  INT16_C( 10174),  INT16_C(  5662),  INT16_C( 21831), -INT16_C( 23434), -INT16_C( 13548), -INT16_C(  3390), -INT16_C( 17448) },
      {  INT16_C( 21887), -INT16_C( 11745), -INT16_C( 29517),  INT16_C( 24639),  INT16_C(   385), -INT16_C( 18037),  INT16_C( 19705), -INT16_C(  9269) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C(  1739),  INT16_C( 20969), -INT16_C( 29791),  INT16_C( 22509), -INT16_C( 16230),  INT16_C( 15915),  INT16_C(  5947),  INT16_C(  4795) },
      { -INT16_C( 28557),  INT16_C( 31530), -INT16_C( 19621), -INT16_C(  7825), -INT16_C( 11321), -INT16_C( 11487), -INT16_C( 27620), -INT16_C( 21785) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 21663),  INT16_C( 26927), -INT16_C(  6760), -INT16_C(  6109),  INT16_C( 27470),  INT16_C( 13016),  INT16_C( 17521),  INT16_C( 11209) },
      {  INT16_C(  7010),  INT16_C( 30341),  INT16_C( 17227), -INT16_C( 27228), -INT16_C(  1869),  INT16_C( 21247), -INT16_C(  6065),  INT16_C( 24097) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comle_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   972616219),  INT32_C(  1372597674),  INT32_C(  1854090426),  INT32_C(  1307148300) },
      {  INT32_C(   972616219),  INT32_C(  1372597674),  INT32_C(  1854090426),  INT32_C(  1307148300) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1953071245), -INT32_C(   960150486), -INT32_C(    24119446),  INT32_C(  1096896316) },
      { -INT32_C(  2018749299), -INT32_C(   606180736), -INT32_C(  1148024056), -INT32_C(  1039936331) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  2067315762), -INT32_C(  1162166367), -INT32_C(  1623697385), -INT32_C(  1718627957) },
      {  INT32_C(   481516508), -INT32_C(   885742399), -INT32_C(   512880547), -INT32_C(   805288428) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(   679473052), -INT32_C(  1184122281), -INT32_C(    60709664), -INT32_C(  1349290268) },
      { -INT32_C(  1065971917),  INT32_C(  1824187158), -INT32_C(  1468054300), -INT32_C(  1060707888) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { {  INT32_C(  1042615301),  INT32_C(   230703349), -INT32_C(   562797843), -INT32_C(   883603475) },
      {  INT32_C(   979072952),  INT32_C(    89665575), -INT32_C(   668094782), -INT32_C(   633427311) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1893523152), -INT32_C(    39758302),  INT32_C(   232266343),  INT32_C(   901598033) },
      {  INT32_C(  1422629779), -INT32_C(   571043173),  INT32_C(   954324770),  INT32_C(  1699785473) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   471812538), -INT32_C(   789182841),  INT32_C(  1375032694),  INT32_C(   884247222) },
      { -INT32_C(   735083539),  INT32_C(  1031541275), -INT32_C(  1862187734), -INT32_C(  1410995258) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(    29643630), -INT32_C(   811116597),  INT32_C(  1915984193),  INT32_C(   287313349) },
      { -INT32_C(  2081572626),  INT32_C(  1842526030), -INT32_C(  1409842686), -INT32_C(   219975032) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comle_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4799802114370404817),  INT64_C( 1579597047222923761) },
      {  INT64_C( 4799802114370404817),  INT64_C( 1579597047222923761) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 5340836100108729923), -INT64_C( 8992481259499743533) },
      {  INT64_C( 8195985707901241238), -INT64_C( 8792156227641384275) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 6741765975996835459), -INT64_C( 6431571666177783867) },
      { -INT64_C( 6632849631960453402), -INT64_C( 6036378782141253986) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 5997152387731853209), -INT64_C( 6743291274089635841) },
      {  INT64_C( 2388185130225810921), -INT64_C( 3346638795333847828) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 1482705454389385582), -INT64_C( 4530065313621924438) },
      {  INT64_C( 3763171127669193926),  INT64_C( 4314911291741316286) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 7163598407174705195),  INT64_C( 5317164735680373485) },
      {  INT64_C( 2457621231182050214),  INT64_C( 3682365343409229628) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 6460805075322074715), -INT64_C( 8985463405146890767) },
      {  INT64_C( 3724710257396886448),  INT64_C(   81519815510080656) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 1733865481417793866), -INT64_C( 5218947715972768035) },
      { -INT64_C( 5628849588688246003), -INT64_C( 1306506982751341601) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comle_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 31), UINT8_C(216), UINT8_C(111), UINT8_C( 81), UINT8_C(232), UINT8_C(220), UINT8_C(134), UINT8_C(231),
        UINT8_C(218), UINT8_C( 46), UINT8_C( 89), UINT8_C( 89), UINT8_C(  3), UINT8_C(116), UINT8_C(129), UINT8_C( 45) },
      { UINT8_C( 31), UINT8_C(216), UINT8_C(111), UINT8_C( 81), UINT8_C(232), UINT8_C(220), UINT8_C(134), UINT8_C(231),
        UINT8_C(218), UINT8_C( 46), UINT8_C( 89), UINT8_C( 89), UINT8_C(  3), UINT8_C(116), UINT8_C(129), UINT8_C( 45) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(228), UINT8_C(251), UINT8_C(173), UINT8_C(164), UINT8_C(200), UINT8_C(180), UINT8_C(152), UINT8_C(226),
        UINT8_C( 84), UINT8_C(125), UINT8_C( 56), UINT8_C( 80), UINT8_C( 94), UINT8_C(162), UINT8_C( 57), UINT8_C( 63) },
      { UINT8_C(  3), UINT8_C(164), UINT8_C(169), UINT8_C(206), UINT8_C(243), UINT8_C( 57), UINT8_C(245), UINT8_C( 13),
        UINT8_C( 16), UINT8_C(147), UINT8_C( 20), UINT8_C( 98), UINT8_C( 56), UINT8_C(229), UINT8_C(  2), UINT8_C( 44) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 94), UINT8_C( 36), UINT8_C(112), UINT8_C(167), UINT8_C(224), UINT8_C( 11), UINT8_C(186), UINT8_C( 16),
        UINT8_C( 20), UINT8_C( 97), UINT8_C( 25), UINT8_C(  9), UINT8_C( 36), UINT8_C(126), UINT8_C( 26), UINT8_C( 62) },
      { UINT8_C( 29), UINT8_C( 12), UINT8_C( 78), UINT8_C( 73), UINT8_C( 66), UINT8_C( 11), UINT8_C( 67), UINT8_C(211),
        UINT8_C(166), UINT8_C( 23), UINT8_C(180), UINT8_C(252), UINT8_C(250), UINT8_C(238), UINT8_C(253), UINT8_C(253) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(163), UINT8_C( 45), UINT8_C(209), UINT8_C( 12), UINT8_C( 16), UINT8_C( 90), UINT8_C( 47), UINT8_C(129),
        UINT8_C( 74), UINT8_C( 39), UINT8_C(146), UINT8_C( 54), UINT8_C(204), UINT8_C(245), UINT8_C(105), UINT8_C( 51) },
      { UINT8_C(150), UINT8_C(152), UINT8_C(198), UINT8_C(139), UINT8_C(125), UINT8_C( 90), UINT8_C( 90), UINT8_C(129),
        UINT8_C(197), UINT8_C( 66), UINT8_C(161), UINT8_C(239), UINT8_C(241), UINT8_C(150), UINT8_C( 90), UINT8_C(233) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(218), UINT8_C(158), UINT8_C( 58), UINT8_C(157),    UINT8_MAX, UINT8_C(171), UINT8_C(225), UINT8_C(125),
        UINT8_C( 28), UINT8_C( 88), UINT8_C( 13), UINT8_C(161), UINT8_C(254), UINT8_C( 16), UINT8_C( 14), UINT8_C(102) },
      { UINT8_C(149), UINT8_C(208), UINT8_C(122), UINT8_C( 92), UINT8_C( 75), UINT8_C( 46), UINT8_C( 33), UINT8_C( 95),
        UINT8_C(148), UINT8_C(155), UINT8_C( 67), UINT8_C(  3), UINT8_C(198), UINT8_C(229), UINT8_C(  1), UINT8_C( 54) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 44), UINT8_C(  0), UINT8_C( 18), UINT8_C( 32), UINT8_C( 85), UINT8_C(  5), UINT8_C(183), UINT8_C( 78),
        UINT8_C(178), UINT8_C(123), UINT8_C(241), UINT8_C( 16), UINT8_C( 97), UINT8_C(214), UINT8_C(241), UINT8_C( 31) },
      { UINT8_C( 67), UINT8_C( 61), UINT8_C(208), UINT8_C(131), UINT8_C( 84), UINT8_C(144), UINT8_C(128), UINT8_C(180),
        UINT8_C( 60), UINT8_C(170), UINT8_C(  3), UINT8_C(  0), UINT8_C( 33), UINT8_C(227), UINT8_C(218), UINT8_C( 44) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(192), UINT8_C(217), UINT8_C(193), UINT8_C( 94), UINT8_C(188), UINT8_C(113), UINT8_C(153), UINT8_C( 59),
        UINT8_C( 53), UINT8_C( 24), UINT8_C(166), UINT8_C( 76), UINT8_C(157), UINT8_C( 79), UINT8_C(250), UINT8_C(166) },
      { UINT8_C(199), UINT8_C(102), UINT8_C( 49), UINT8_C(202), UINT8_C( 65), UINT8_C(135), UINT8_C( 95), UINT8_C(202),
        UINT8_C(228), UINT8_C(247), UINT8_C( 71), UINT8_C(173), UINT8_C(169), UINT8_C(153), UINT8_C(206), UINT8_C( 21) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(191), UINT8_C(180), UINT8_C(175), UINT8_C( 31), UINT8_C(218), UINT8_C(245), UINT8_C(111), UINT8_C(139),
        UINT8_C(205), UINT8_C(184), UINT8_C(148), UINT8_C( 29), UINT8_C( 91), UINT8_C(131), UINT8_C( 18), UINT8_C( 66) },
      { UINT8_C( 74), UINT8_C(211), UINT8_C(  6), UINT8_C(247), UINT8_C(186), UINT8_C( 28), UINT8_C(166), UINT8_C(231),
        UINT8_C(181), UINT8_C( 11), UINT8_C(120), UINT8_C(211), UINT8_C(  7), UINT8_C( 14), UINT8_C(195), UINT8_C( 55) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comle_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 5712), UINT16_C(11076), UINT16_C(40023), UINT16_C(34593), UINT16_C(58017), UINT16_C(18979), UINT16_C(31555), UINT16_C(15647) },
      { UINT16_C( 5712), UINT16_C(11076), UINT16_C(40023), UINT16_C(34593), UINT16_C(58017), UINT16_C(18979), UINT16_C(31555), UINT16_C(15647) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 3572), UINT16_C(54197), UINT16_C(22118), UINT16_C(21565), UINT16_C(28119), UINT16_C(15103), UINT16_C(19171), UINT16_C(56482) },
      { UINT16_C(35228), UINT16_C(18920), UINT16_C(27612), UINT16_C(30616), UINT16_C( 7898), UINT16_C(40379), UINT16_C(16124), UINT16_C(56586) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(39916), UINT16_C( 9896), UINT16_C(15854), UINT16_C(22797), UINT16_C(42353), UINT16_C(43586), UINT16_C(22243), UINT16_C(19028) },
      { UINT16_C(38090), UINT16_C(17155), UINT16_C(27665), UINT16_C(41914), UINT16_C(62623), UINT16_C(56516), UINT16_C(54319), UINT16_C(27580) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1371), UINT16_C(47173), UINT16_C(55801), UINT16_C(15868), UINT16_C(15531), UINT16_C(60331), UINT16_C(14770), UINT16_C(51648) },
      { UINT16_C(49155), UINT16_C(57341), UINT16_C(42653), UINT16_C(21104), UINT16_C(60697), UINT16_C(53414), UINT16_C(18051), UINT16_C(11804) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(54376), UINT16_C(20726), UINT16_C(13104), UINT16_C(19187), UINT16_C(47534), UINT16_C(50337), UINT16_C(64502), UINT16_C(41933) },
      { UINT16_C(37743), UINT16_C(58942), UINT16_C( 8489), UINT16_C(52643), UINT16_C(36976), UINT16_C(16841), UINT16_C(39841), UINT16_C(28689) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(36668), UINT16_C(47138), UINT16_C(21051), UINT16_C(50907), UINT16_C(42146), UINT16_C(65419), UINT16_C(42328), UINT16_C( 7781) },
      { UINT16_C(38709), UINT16_C( 7982), UINT16_C(58972), UINT16_C(23865), UINT16_C(26059), UINT16_C(63381), UINT16_C(56112), UINT16_C(30597) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(48894), UINT16_C(46640), UINT16_C(16065), UINT16_C(64154), UINT16_C(34479), UINT16_C(25299), UINT16_C(15999), UINT16_C(33903) },
      { UINT16_C(21630), UINT16_C(21557), UINT16_C(64735), UINT16_C(18460), UINT16_C(62802), UINT16_C(47475), UINT16_C( 3801), UINT16_C(36191) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(60119), UINT16_C( 5002), UINT16_C(  106), UINT16_C(11802), UINT16_C(58875), UINT16_C(46816), UINT16_C(52756), UINT16_C( 7122) },
      { UINT16_C(20849), UINT16_C(19388), UINT16_C(27481), UINT16_C(54834), UINT16_C(50991), UINT16_C(20681), UINT16_C(15684), UINT16_C(63623) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comle_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2526517999), UINT32_C(2856427488), UINT32_C(3256503473), UINT32_C( 746086078) },
      { UINT32_C(2526517999), UINT32_C(2856427488), UINT32_C(3256503473), UINT32_C( 746086078) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3442021943), UINT32_C(1365589107), UINT32_C(2231395463), UINT32_C(  14970904) },
      { UINT32_C( 163534445), UINT32_C(3053003720), UINT32_C(1357463799), UINT32_C(4266193958) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2732993527), UINT32_C(4288378581), UINT32_C( 511791749), UINT32_C(4016090621) },
      { UINT32_C( 845850234), UINT32_C(2552862157), UINT32_C( 649415669), UINT32_C(3677002739) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2455312858), UINT32_C( 717103398), UINT32_C(3820165966), UINT32_C( 199425693) },
      { UINT32_C(3674215229), UINT32_C(2629434517), UINT32_C( 233239765), UINT32_C( 151410894) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1709991688), UINT32_C( 414533134), UINT32_C(2667398669), UINT32_C(2656266909) },
      { UINT32_C(3404276959), UINT32_C( 110125256), UINT32_C(3454321596), UINT32_C(3519296863) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3792084392), UINT32_C( 292088631), UINT32_C( 365518056), UINT32_C(4003068328) },
      { UINT32_C(3364774535), UINT32_C( 563661071), UINT32_C( 773341652), UINT32_C(2068658509) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3540927458), UINT32_C(1606359878), UINT32_C( 293528583), UINT32_C(1151186020) },
      { UINT32_C(2622837598), UINT32_C( 884490258), UINT32_C(4176016709), UINT32_C(1334275137) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(4268679904), UINT32_C(1235409894), UINT32_C(1518560915), UINT32_C(3880231545) },
      { UINT32_C( 279413132), UINT32_C(2262355064), UINT32_C(4072499255), UINT32_C(2505824226) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comle_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comle_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 1655413424631120327), UINT64_C( 2414154322209303476) },
      { UINT64_C( 1655413424631120327), UINT64_C( 2414154322209303476) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 6980710169465156664), UINT64_C(10714487761357775057) },
      { UINT64_C( 1129330877660342722), UINT64_C( 4048235039675284113) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(  772724745883726474), UINT64_C(10768796985887008571) },
      { UINT64_C( 8981255941545058806), UINT64_C( 8447328362611546963) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(14720368943566013867), UINT64_C(16178253019982103966) },
      { UINT64_C(11945562851780112782), UINT64_C( 2345808535136622113) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(17183891286428431811), UINT64_C(13677796347659763746) },
      { UINT64_C(15131594902348964272), UINT64_C( 9299478155659654180) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(13200861144104929529), UINT64_C( 8376768063846769390) },
      { UINT64_C( 5274007808018332293), UINT64_C(16115053827258694788) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 8168005558465349750), UINT64_C( 5528346279398634283) },
      { UINT64_C( 6217680072136131380), UINT64_C( 9527755318477125480) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 7123170988958547042), UINT64_C(10242152464707090688) },
      { UINT64_C( 4479972021671527909), UINT64_C(13165159143517481976) },
      { UINT64_C(                   0),                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comle_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comle_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  28),  INT8_C(  45), -INT8_C( 120), -INT8_C(  63),  INT8_C( 105), -INT8_C(  19), -INT8_C( 101), -INT8_C(  46),
        -INT8_C( 106),  INT8_C( 126), -INT8_C(  34),  INT8_C(  99),  INT8_C(  20), -INT8_C(  76),  INT8_C( 104), -INT8_C( 125) },
      { -INT8_C(  28),  INT8_C(  45), -INT8_C( 120), -INT8_C(  63),  INT8_C( 105), -INT8_C(  19), -INT8_C( 101), -INT8_C(  46),
        -INT8_C( 106),  INT8_C( 126), -INT8_C(  34),  INT8_C(  99),  INT8_C(  20), -INT8_C(  76),  INT8_C( 104), -INT8_C( 125) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  62), -INT8_C(  58),  INT8_C(  34), -INT8_C(  64),  INT8_C(   4),  INT8_C(  83), -INT8_C(  60),  INT8_C(  73),
         INT8_C(  94), -INT8_C(  94),  INT8_C(   0),  INT8_C(  84),  INT8_C(  65),  INT8_C(  46), -INT8_C(   4), -INT8_C(  66) },
      {  INT8_C(  36),  INT8_C(  98),  INT8_C(   6), -INT8_C(  15), -INT8_C(  41), -INT8_C(  95), -INT8_C( 124),  INT8_C(  11),
         INT8_C(  20), -INT8_C( 119),  INT8_C(  41),  INT8_C(  61),  INT8_C(  88),  INT8_C( 121),  INT8_C( 111),  INT8_C( 112) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  16),  INT8_C(  80),  INT8_C(  65),  INT8_C(  47),  INT8_C(  87),  INT8_C( 120), -INT8_C(   9), -INT8_C(  63),
        -INT8_C(  65),  INT8_C(  36), -INT8_C( 120), -INT8_C( 107), -INT8_C(  18), -INT8_C(  43), -INT8_C(   5), -INT8_C(  28) },
      {  INT8_C(  75),  INT8_C(  35),  INT8_C(  31), -INT8_C( 111),  INT8_C(  57), -INT8_C(  70),  INT8_C( 124),  INT8_C(  84),
        -INT8_C(  93), -INT8_C(  93), -INT8_C( 119),  INT8_C(  23), -INT8_C(  40), -INT8_C(  59),  INT8_C(  32), -INT8_C(  96) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C( 102), -INT8_C(  85),  INT8_C(  46),  INT8_C( 113),  INT8_C( 113), -INT8_C( 121), -INT8_C(  81), -INT8_C(  20),
         INT8_C(  70),  INT8_C( 119), -INT8_C(  38), -INT8_C(  69),  INT8_C(  44),  INT8_C(   8), -INT8_C( 104),  INT8_C( 111) },
      { -INT8_C( 127), -INT8_C(   7),  INT8_C(  59),  INT8_C( 103),  INT8_C(  54),  INT8_C(  65),  INT8_C( 109), -INT8_C(  12),
         INT8_C( 107),  INT8_C(  82),  INT8_C( 102), -INT8_C(  70),  INT8_C(  63), -INT8_C(  96),  INT8_C(  99),  INT8_C(  90) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  26),  INT8_C(  93),  INT8_C(  83),  INT8_C(  78), -INT8_C(   4), -INT8_C( 121), -INT8_C(  45),  INT8_C(  20),
         INT8_C(  24),  INT8_C(  37),  INT8_C(  92), -INT8_C( 114), -INT8_C(  91), -INT8_C(  50), -INT8_C(  69), -INT8_C(  87) },
      { -INT8_C(  19),  INT8_C( 106), -INT8_C(  62),  INT8_C(  61),  INT8_C( 119),  INT8_C(  61),  INT8_C(  62),  INT8_C(  52),
        -INT8_C( 109),  INT8_C(  33),  INT8_C(  41), -INT8_C(  17),  INT8_C(  51),  INT8_C(  18),  INT8_C(  32), -INT8_C(  27) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(   4), -INT8_C(  16),  INT8_C(  23), -INT8_C( 115), -INT8_C(  99), -INT8_C( 127),  INT8_C(  75),      INT8_MAX,
         INT8_C(  96), -INT8_C(  74),  INT8_C( 120), -INT8_C(  42), -INT8_C(   2),  INT8_C(  47),  INT8_C(  76), -INT8_C(  40) },
      { -INT8_C(  72),  INT8_C(   0),  INT8_C(  28), -INT8_C(  39), -INT8_C(  93), -INT8_C(  74), -INT8_C(  41),  INT8_C(  92),
         INT8_C(  68), -INT8_C( 107),  INT8_C(  56),  INT8_C( 124),  INT8_C(  92),  INT8_C(  36),  INT8_C(  63), -INT8_C( 118) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(   5), -INT8_C(  20), -INT8_C(  31), -INT8_C(   8), -INT8_C(   2),  INT8_C( 124), -INT8_C(   1),  INT8_C( 117),
         INT8_C(  68), -INT8_C(  80), -INT8_C( 107),  INT8_C(  90), -INT8_C(  30),  INT8_C(  51),  INT8_C(  52),  INT8_C(  69) },
      {  INT8_C(   9),  INT8_C(  67), -INT8_C(  78),  INT8_C(   3),  INT8_C(  99), -INT8_C(  76),  INT8_C(  32), -INT8_C(  76),
        -INT8_C(  91),  INT8_C(  56), -INT8_C(   4),  INT8_C(  41),  INT8_C( 100), -INT8_C(  35), -INT8_C(  88), -INT8_C( 111) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  41), -INT8_C(  41),  INT8_C(  27),  INT8_C(  85), -INT8_C(  57),      INT8_MIN, -INT8_C(  41),  INT8_C(  64),
        -INT8_C(  20), -INT8_C(  99),  INT8_C(  26), -INT8_C(  29), -INT8_C(   9), -INT8_C(  29),  INT8_C(  89),  INT8_C(  56) },
      {  INT8_C(   9), -INT8_C(  70), -INT8_C(  22), -INT8_C( 123),  INT8_C(  95),  INT8_C(  64),  INT8_C(   1), -INT8_C( 125),
        -INT8_C(  33), -INT8_C( 111), -INT8_C(  35), -INT8_C(  64), -INT8_C(  16),  INT8_C(  70),  INT8_C(  67),  INT8_C(  66) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comlt_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 15247),  INT16_C( 27948), -INT16_C( 26976),  INT16_C( 10171),  INT16_C(  1153),  INT16_C( 14705),  INT16_C( 18149), -INT16_C(  1884) },
      {  INT16_C( 15247),  INT16_C( 27948), -INT16_C( 26976),  INT16_C( 10171),  INT16_C(  1153),  INT16_C( 14705),  INT16_C( 18149), -INT16_C(  1884) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  4640),  INT16_C(  9773),  INT16_C( 24894),  INT16_C(  4962),  INT16_C( 10265),  INT16_C(  1860),  INT16_C( 26027), -INT16_C(  6919) },
      { -INT16_C( 24736),  INT16_C(  2172), -INT16_C( 15313),  INT16_C( 29075),  INT16_C( 28203),  INT16_C(  9217),  INT16_C( 25685), -INT16_C( 12291) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 25781), -INT16_C( 21020),  INT16_C(  8361), -INT16_C( 21973), -INT16_C( 31108), -INT16_C( 14185),  INT16_C( 17466), -INT16_C( 15952) },
      { -INT16_C( 29501), -INT16_C(  4493),  INT16_C(  5151),  INT16_C( 26439),  INT16_C( 25105),  INT16_C( 27698),  INT16_C( 18159),  INT16_C(   845) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 22352), -INT16_C(  7307), -INT16_C( 31929), -INT16_C( 28348),  INT16_C( 12848), -INT16_C( 14017), -INT16_C(  5304),  INT16_C(  8017) },
      { -INT16_C( 30239), -INT16_C(  6535), -INT16_C( 29162),  INT16_C( 20927),  INT16_C( 26716), -INT16_C( 10132), -INT16_C(  3238), -INT16_C(  8838) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 16635), -INT16_C( 28598), -INT16_C( 27199),  INT16_C(  4245), -INT16_C( 19364), -INT16_C( 11355),  INT16_C( 24699),  INT16_C( 18373) },
      {  INT16_C(  7906), -INT16_C( 17930),  INT16_C( 14780),  INT16_C( 30691),  INT16_C(  2099),  INT16_C( 12567),  INT16_C( 29503), -INT16_C( 23186) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C( 19269),  INT16_C( 31945),  INT16_C( 23486),  INT16_C( 28166), -INT16_C( 27352), -INT16_C( 21200), -INT16_C( 21125), -INT16_C( 32270) },
      { -INT16_C( 11283),  INT16_C( 12114),  INT16_C(  7611),  INT16_C(  8348), -INT16_C( 13377),  INT16_C( 16283), -INT16_C( 12475), -INT16_C( 23793) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 29413),  INT16_C( 28252), -INT16_C(  8217), -INT16_C(  2688),  INT16_C( 23741),  INT16_C(  8519), -INT16_C(  9487),  INT16_C(  5570) },
      {  INT16_C( 12586),  INT16_C(  4341),  INT16_C( 17080), -INT16_C( 27184),  INT16_C( 14376), -INT16_C( 13727),  INT16_C(  3605),  INT16_C(  8007) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 21057),  INT16_C( 12138),  INT16_C( 10468), -INT16_C(  5143), -INT16_C( 28349), -INT16_C(  2732), -INT16_C(  4731),  INT16_C( 18972) },
      { -INT16_C( 16446),  INT16_C(  9287), -INT16_C( 20130),  INT16_C(  8040), -INT16_C( 10091), -INT16_C( 25905),  INT16_C( 14422),  INT16_C( 24829) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comlt_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  2007266475), -INT32_C(  1725219236), -INT32_C(   222380575),  INT32_C(  1776808158) },
      { -INT32_C(  2007266475), -INT32_C(  1725219236), -INT32_C(   222380575),  INT32_C(  1776808158) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   867239389),  INT32_C(    72184146),  INT32_C(  1984835886), -INT32_C(  1357293903) },
      {  INT32_C(  1050067072),  INT32_C(  1194076919), -INT32_C(   521312320), -INT32_C(  1173493083) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { {  INT32_C(    77171874), -INT32_C(  1939502529),  INT32_C(   675794205),  INT32_C(  1417834446) },
      {  INT32_C(   478509801),  INT32_C(  1037497182), -INT32_C(  2025253112), -INT32_C(  2055871359) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1617484602),  INT32_C(    26871243),  INT32_C(  1981822087), -INT32_C(  1759343788) },
      { -INT32_C(   376487750), -INT32_C(  1039163079), -INT32_C(  1371908640),  INT32_C(   302507291) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
    { {  INT32_C(   260537293), -INT32_C(  1445729890),  INT32_C(   692317335), -INT32_C(  1075793172) },
      {  INT32_C(  1813814040),  INT32_C(   532757807),  INT32_C(   522758768), -INT32_C(  1465125606) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   648220030), -INT32_C(   822591903),  INT32_C(   152469362),  INT32_C(   379907389) },
      {  INT32_C(  1855197741), -INT32_C(  1647063575), -INT32_C(  1602511391), -INT32_C(  1857479641) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  2041460095), -INT32_C(  1225782084), -INT32_C(   586975933), -INT32_C(   497662992) },
      { -INT32_C(  1218433759), -INT32_C(  2110956529), -INT32_C(    90458277),  INT32_C(   331965418) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   573732109), -INT32_C(  1448780714),  INT32_C(  1869632560),  INT32_C(  1826602412) },
      {  INT32_C(   266761244),  INT32_C(   381153096), -INT32_C(   168788475),  INT32_C(  1997787402) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comlt_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 1009310061849691392), -INT64_C(  277707935960291743) },
      { -INT64_C( 1009310061849691392), -INT64_C(  277707935960291743) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 6676146384178024379),  INT64_C(  364913823257426952) },
      { -INT64_C( 3034404798427700017), -INT64_C( 2733338756895476993) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 8069120759030851780),  INT64_C(  335030005951773068) },
      { -INT64_C( 7188690367506903671),  INT64_C( 5587645156847305010) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 4358047410867690302), -INT64_C( 4702224012875514696) },
      { -INT64_C( 8074591999440568491), -INT64_C( 7026560871118497247) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1738651072766022297),  INT64_C( 8737461920207474100) },
      { -INT64_C(  654263243386552228),  INT64_C( 1642202949236884981) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 2589914495479646938),  INT64_C( 9085271308915061929) },
      {  INT64_C( 1806110484765072325), -INT64_C(  333482292974875947) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4637417923057319100),  INT64_C( 1523448370915064255) },
      {  INT64_C( 4560264752526579129), -INT64_C( 7700718862329793814) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C(  206652225637310924), -INT64_C( 8839227657813777123) },
      { -INT64_C( 5656579576308303776),  INT64_C( 3385089157130093660) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comlt_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(155), UINT8_C(171), UINT8_C( 38), UINT8_C(163), UINT8_C(144), UINT8_C( 11), UINT8_C(136), UINT8_C( 54),
        UINT8_C(236), UINT8_C(  0), UINT8_C(208), UINT8_C( 40), UINT8_C(243), UINT8_C(137), UINT8_C(143), UINT8_C( 24) },
      { UINT8_C(155), UINT8_C(171), UINT8_C( 38), UINT8_C(163), UINT8_C(144), UINT8_C( 11), UINT8_C(136), UINT8_C( 54),
        UINT8_C(236), UINT8_C(  0), UINT8_C(208), UINT8_C( 40), UINT8_C(243), UINT8_C(137), UINT8_C(143), UINT8_C( 24) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(225), UINT8_C(203), UINT8_C(236), UINT8_C(222), UINT8_C( 54), UINT8_C( 14), UINT8_C(152), UINT8_C(184),
        UINT8_C( 82), UINT8_C(  9), UINT8_C(  4), UINT8_C(164), UINT8_C( 65), UINT8_C( 95), UINT8_C(209), UINT8_C( 12) },
      { UINT8_C(216), UINT8_C(105), UINT8_C(136), UINT8_C(168), UINT8_C(  1), UINT8_C( 54), UINT8_C(139), UINT8_C(161),
        UINT8_C( 83), UINT8_C(208), UINT8_C( 75), UINT8_C(242), UINT8_C(230), UINT8_C(193), UINT8_C(188), UINT8_C( 20) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(101), UINT8_C(214), UINT8_C(  6), UINT8_C(218), UINT8_C(100), UINT8_C( 35), UINT8_C(126), UINT8_C(154),
        UINT8_C(244), UINT8_C( 71), UINT8_C(212), UINT8_C(141), UINT8_C(117), UINT8_C(242), UINT8_C(141), UINT8_C(120) },
      { UINT8_C(172), UINT8_C(164), UINT8_C(180), UINT8_C(140), UINT8_C( 22), UINT8_C(183), UINT8_C(205), UINT8_C(139),
        UINT8_C(123), UINT8_C(159), UINT8_C( 11), UINT8_C( 45), UINT8_C(197), UINT8_C(113), UINT8_C(195), UINT8_C(194) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 19), UINT8_C(162), UINT8_C( 31), UINT8_C( 24), UINT8_C( 10), UINT8_C( 17), UINT8_C( 23), UINT8_C(159),
        UINT8_C(107), UINT8_C( 72), UINT8_C(157), UINT8_C(203), UINT8_C(235),    UINT8_MAX, UINT8_C( 24), UINT8_C(186) },
      { UINT8_C( 63), UINT8_C(226), UINT8_C( 20), UINT8_C( 23), UINT8_C(118), UINT8_C(149), UINT8_C( 56), UINT8_C( 62),
        UINT8_C(139), UINT8_C(244), UINT8_C(120), UINT8_C(161), UINT8_C( 59), UINT8_C(159), UINT8_C(140), UINT8_C(106) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 20), UINT8_C(182), UINT8_C(160), UINT8_C( 98), UINT8_C(207), UINT8_C(225), UINT8_C( 77), UINT8_C( 17),
        UINT8_C(223), UINT8_C(148), UINT8_C(200), UINT8_C( 39), UINT8_C( 74), UINT8_C(145), UINT8_C( 89), UINT8_C( 26) },
      { UINT8_C(184), UINT8_C(174), UINT8_C( 15), UINT8_C( 17), UINT8_C(201), UINT8_C(216), UINT8_C(179), UINT8_C(  1),
        UINT8_C(172), UINT8_C( 88), UINT8_C(250), UINT8_C( 21), UINT8_C(238), UINT8_C( 85), UINT8_C(254), UINT8_C( 84) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(143), UINT8_C(154), UINT8_C(239), UINT8_C(126), UINT8_C( 91), UINT8_C(154), UINT8_C(  6), UINT8_C( 54),
        UINT8_C(119), UINT8_C(177), UINT8_C(187), UINT8_C(102), UINT8_C( 59), UINT8_C(173), UINT8_C( 56), UINT8_C(224) },
      { UINT8_C( 63), UINT8_C(141), UINT8_C( 13), UINT8_C( 65), UINT8_C(185), UINT8_C(137), UINT8_C( 37), UINT8_C( 27),
        UINT8_C(  6), UINT8_C( 82), UINT8_C(249), UINT8_C( 83), UINT8_C(134), UINT8_C(154), UINT8_C(  3), UINT8_C(199) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(173), UINT8_C(215), UINT8_C(118), UINT8_C( 52), UINT8_C( 87), UINT8_C( 68), UINT8_C( 44), UINT8_C( 88),
        UINT8_C( 92), UINT8_C( 41), UINT8_C(224), UINT8_C( 83), UINT8_C(101), UINT8_C( 93), UINT8_C(157), UINT8_C( 83) },
      { UINT8_C(254), UINT8_C(  9), UINT8_C(118), UINT8_C(112), UINT8_C(236), UINT8_C(174), UINT8_C(120), UINT8_C(213),
        UINT8_C(192), UINT8_C(106), UINT8_C(221), UINT8_C( 33), UINT8_C(172), UINT8_C(119), UINT8_C(130), UINT8_C( 13) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(150), UINT8_C(244), UINT8_C(156), UINT8_C( 78), UINT8_C(107), UINT8_C(232), UINT8_C(166), UINT8_C(189),
        UINT8_C(182), UINT8_C(132), UINT8_C(158), UINT8_C(181), UINT8_C(113), UINT8_C(168), UINT8_C(112), UINT8_C(188) },
      { UINT8_C( 26), UINT8_C(169), UINT8_C(179), UINT8_C(102), UINT8_C( 10), UINT8_C( 82), UINT8_C(147), UINT8_C(119),
        UINT8_C(  3), UINT8_C( 40), UINT8_C( 14), UINT8_C( 72), UINT8_C(  8), UINT8_C(242), UINT8_C(100), UINT8_C(108) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comlt_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(31089), UINT16_C(37576), UINT16_C(36158), UINT16_C(44380), UINT16_C(18604), UINT16_C(21340), UINT16_C(38662), UINT16_C(25497) },
      { UINT16_C(31089), UINT16_C(37576), UINT16_C(36158), UINT16_C(44380), UINT16_C(18604), UINT16_C(21340), UINT16_C(38662), UINT16_C(25497) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(62910), UINT16_C(60202), UINT16_C(31420), UINT16_C(18782), UINT16_C( 5622), UINT16_C(37109), UINT16_C( 5697), UINT16_C(11663) },
      { UINT16_C(61286), UINT16_C(51812), UINT16_C(15225), UINT16_C(29238), UINT16_C(65382), UINT16_C(63108), UINT16_C(12493), UINT16_C(36865) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(30224), UINT16_C(51012), UINT16_C(12458), UINT16_C(37569), UINT16_C(47298), UINT16_C(49400), UINT16_C(59647), UINT16_C(38892) },
      { UINT16_C(56735), UINT16_C(48343), UINT16_C(64195), UINT16_C(21276), UINT16_C(12301), UINT16_C(26237), UINT16_C(32109), UINT16_C(35726) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(45880), UINT16_C(49513), UINT16_C(31611), UINT16_C(40100), UINT16_C(39310), UINT16_C(41600), UINT16_C(29420), UINT16_C(62563) },
      { UINT16_C(52033), UINT16_C(12681), UINT16_C(54213), UINT16_C(38902), UINT16_C(25801), UINT16_C(27567), UINT16_C(34447), UINT16_C(39721) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(13663), UINT16_C(41730), UINT16_C(25815), UINT16_C(44527), UINT16_C(16771), UINT16_C(64758), UINT16_C(48046), UINT16_C(35549) },
      { UINT16_C(16759), UINT16_C(61666), UINT16_C(52519), UINT16_C(34732), UINT16_C( 8897), UINT16_C(52610), UINT16_C(21211), UINT16_C( 2747) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(33453), UINT16_C(13173), UINT16_C(61800), UINT16_C( 3722), UINT16_C(14281), UINT16_C(38848), UINT16_C(52205), UINT16_C(41792) },
      { UINT16_C(51303), UINT16_C(49994), UINT16_C(61840), UINT16_C(27430), UINT16_C(61982), UINT16_C(21342), UINT16_C(59896), UINT16_C( 7722) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 9289), UINT16_C(14892), UINT16_C(11475), UINT16_C( 1885), UINT16_C(  903), UINT16_C(15176), UINT16_C(43858), UINT16_C(34166) },
      { UINT16_C(59193), UINT16_C(28713), UINT16_C(18088), UINT16_C(35661), UINT16_C(23559), UINT16_C(51115), UINT16_C(21391), UINT16_C( 8288) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(41820), UINT16_C(32653), UINT16_C( 7619), UINT16_C(57169), UINT16_C(12005), UINT16_C(45044), UINT16_C(25220), UINT16_C(30821) },
      { UINT16_C(10006), UINT16_C(49383), UINT16_C(54296), UINT16_C(11783), UINT16_C(59813), UINT16_C(61393), UINT16_C(38983), UINT16_C(22339) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comlt_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3422717197), UINT32_C(3763129310), UINT32_C(3173924620), UINT32_C(3338139692) },
      { UINT32_C(3422717197), UINT32_C(3763129310), UINT32_C(3173924620), UINT32_C(3338139692) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2079067942), UINT32_C(2638062472), UINT32_C(2469928992), UINT32_C( 230539721) },
      { UINT32_C(3891418245), UINT32_C(1345797836), UINT32_C( 727563812), UINT32_C(3037886194) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1772103568), UINT32_C( 567852191), UINT32_C(2101906079), UINT32_C(2293618365) },
      { UINT32_C(2579863531), UINT32_C(2029747766), UINT32_C(3269997652), UINT32_C(2409685885) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1366095741), UINT32_C(  12461574), UINT32_C(1953148234), UINT32_C( 303226313) },
      { UINT32_C(2866993000), UINT32_C(2692650180), UINT32_C(1245259973), UINT32_C(2592622454) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(4256565268), UINT32_C(2195319141), UINT32_C(1057231690), UINT32_C(4055818392) },
      { UINT32_C(3803421476), UINT32_C( 279611165), UINT32_C(2344034975), UINT32_C( 531802756) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 870834558), UINT32_C(4044295779), UINT32_C(2810201287), UINT32_C(1839261392) },
      { UINT32_C( 161442630), UINT32_C( 258367466), UINT32_C(1305127433), UINT32_C(1694897488) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3160935138), UINT32_C(2471140264), UINT32_C(1950664680), UINT32_C(3500210202) },
      { UINT32_C(3859730423), UINT32_C(3868796114), UINT32_C(1473923371), UINT32_C(3060567938) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1621101673), UINT32_C(2993789917), UINT32_C(1857692630), UINT32_C(1621499165) },
      { UINT32_C(1114132574), UINT32_C(3727548286), UINT32_C(1917814318), UINT32_C(1489772993) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comlt_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comlt_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(10694944839838363194), UINT64_C( 7465382146795430841) },
      { UINT64_C(10694944839838363194), UINT64_C( 7465382146795430841) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 4398214280665003428), UINT64_C(10668696243839101498) },
      { UINT64_C( 9305296330829379711), UINT64_C( 3126836178466671800) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 5410324813019269104), UINT64_C(12833757039398878326) },
      { UINT64_C(14086855747445027677), UINT64_C(17720907039855716603) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 5924802686951738731), UINT64_C(18075392130194162699) },
      { UINT64_C(11629883228059608830), UINT64_C(  872310240276364971) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(10978932502879473468), UINT64_C(12984423513631115809) },
      { UINT64_C( 7115779669251021194), UINT64_C(13463246126398199792) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 7379709048895640973), UINT64_C( 2813464160161863646) },
      { UINT64_C( 5726224131170604072), UINT64_C( 4974875778945776369) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(  307687679989737603), UINT64_C(11263558847133430381) },
      { UINT64_C(12714394728952127489), UINT64_C(17769756759069503447) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(13464197959855214408), UINT64_C( 6622059559939810292) },
      { UINT64_C(14814948272629236797), UINT64_C( 1545221821489315785) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comlt_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comlt_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   4),  INT8_C(  18),  INT8_C(   7), -INT8_C(  71),  INT8_C(  29), -INT8_C(  10),  INT8_C(  14), -INT8_C(  48),
        -INT8_C( 100),  INT8_C( 115), -INT8_C(  17),  INT8_C( 105),  INT8_C(  97), -INT8_C(  76), -INT8_C(  73), -INT8_C(  84) },
      {  INT8_C(   4),  INT8_C(  18),  INT8_C(   7), -INT8_C(  71),  INT8_C(  29), -INT8_C(  10),  INT8_C(  14), -INT8_C(  48),
        -INT8_C( 100),  INT8_C( 115), -INT8_C(  17),  INT8_C( 105),  INT8_C(  97), -INT8_C(  76), -INT8_C(  73), -INT8_C(  84) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(   3), -INT8_C(  55), -INT8_C(  55), -INT8_C(  63),  INT8_C(  31), -INT8_C(  89), -INT8_C(  43), -INT8_C(  19),
        -INT8_C(  16),  INT8_C( 112),  INT8_C(   4), -INT8_C(   2),  INT8_C(  32), -INT8_C(  11),  INT8_C( 117), -INT8_C(  22) },
      { -INT8_C(  34),  INT8_C( 122), -INT8_C(  19), -INT8_C(  77),  INT8_C(  49), -INT8_C(  71), -INT8_C(  54), -INT8_C( 115),
        -INT8_C( 116),  INT8_C(  41),  INT8_C(  57),  INT8_C(  67), -INT8_C(  94),      INT8_MAX, -INT8_C(  87), -INT8_C(  41) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C( 123),  INT8_C( 117),      INT8_MIN,  INT8_C( 105), -INT8_C(  56), -INT8_C(  53),  INT8_C(  12),  INT8_C(  89),
         INT8_C( 116), -INT8_C( 116), -INT8_C(  68), -INT8_C(  80),  INT8_C( 123), -INT8_C( 109), -INT8_C( 112), -INT8_C(  68) },
      { -INT8_C(   1),  INT8_C(  77), -INT8_C(  50), -INT8_C(   5), -INT8_C( 103), -INT8_C(  63), -INT8_C(   9),  INT8_C(  59),
        -INT8_C(  19), -INT8_C(  51), -INT8_C(   7), -INT8_C(   2), -INT8_C( 127), -INT8_C(  78), -INT8_C(  90),  INT8_C(  35) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  49), -INT8_C(  45),  INT8_C( 101), -INT8_C(  61), -INT8_C( 104), -INT8_C(  71),  INT8_C(  39),  INT8_C(  90),
         INT8_C( 124),  INT8_C(  91), -INT8_C(  99),  INT8_C(  39), -INT8_C(  56), -INT8_C( 100), -INT8_C(  87), -INT8_C(  43) },
      { -INT8_C( 113),  INT8_C(  22),  INT8_C(  18),  INT8_C(  90), -INT8_C(   4),  INT8_C(  22),  INT8_C( 123),  INT8_C(  32),
        -INT8_C(  26), -INT8_C(  25), -INT8_C( 106),  INT8_C(  98), -INT8_C(  91),  INT8_C(  84), -INT8_C( 107), -INT8_C(  38) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  36),  INT8_C( 104), -INT8_C(  31), -INT8_C( 103),  INT8_C(  56),  INT8_C( 120),  INT8_C(  15),  INT8_C(  54),
         INT8_C(  48),  INT8_C( 100),  INT8_C(  16),  INT8_C(  42), -INT8_C(  82),  INT8_C(  25), -INT8_C(  89),  INT8_C( 123) },
      { -INT8_C(  75),  INT8_C(  90),  INT8_C(  32), -INT8_C( 104),  INT8_C(   2), -INT8_C(  63),  INT8_C(  64), -INT8_C( 124),
        -INT8_C(  96),  INT8_C(   0),  INT8_C( 120),  INT8_C(  55), -INT8_C(  73),  INT8_C( 109),  INT8_C(  93),  INT8_C(  66) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  91), -INT8_C(  66),  INT8_C(  93), -INT8_C(  79),  INT8_C(  79),  INT8_C(  16), -INT8_C(  86),  INT8_C(  53),
        -INT8_C(  71),  INT8_C(  47),  INT8_C( 123), -INT8_C( 125), -INT8_C(  43),  INT8_C(  17),  INT8_C( 116), -INT8_C(   9) },
      { -INT8_C( 103), -INT8_C(  93),  INT8_C(  98),  INT8_C( 125),  INT8_C(  84), -INT8_C(  55),  INT8_C(  44), -INT8_C(  79),
         INT8_C(  66), -INT8_C(  97),  INT8_C(   7),  INT8_C(  69),  INT8_C(  94),  INT8_C(   6), -INT8_C(  24), -INT8_C(  93) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C( 119),  INT8_C(  92),  INT8_C(  63), -INT8_C(  44), -INT8_C( 122), -INT8_C( 118), -INT8_C(  30), -INT8_C(  95),
         INT8_C(  63),  INT8_C(  68),  INT8_C(  71), -INT8_C(   8), -INT8_C(  26), -INT8_C( 116), -INT8_C(   9), -INT8_C( 111) },
      {  INT8_C( 100),  INT8_C( 120),  INT8_C(  63), -INT8_C(  48), -INT8_C( 102),  INT8_C(  54),  INT8_C(  41), -INT8_C(  18),
        -INT8_C(  11),  INT8_C(  77), -INT8_C(  85),  INT8_C(  84),  INT8_C(  67),  INT8_C(  37),  INT8_C(  29),  INT8_C(  71) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  59), -INT8_C(  54), -INT8_C(  16), -INT8_C(  54), -INT8_C( 123), -INT8_C(  19), -INT8_C(  98), -INT8_C(  64),
        -INT8_C(  23),  INT8_C(  44), -INT8_C(  35),  INT8_C(  82), -INT8_C( 119), -INT8_C( 109),  INT8_C(  24), -INT8_C( 112) },
      {  INT8_C(  62),  INT8_C(  98),  INT8_C(  31),  INT8_C(  91),  INT8_C( 123),  INT8_C(  16),  INT8_C(  30), -INT8_C( 126),
        -INT8_C(  31), -INT8_C( 111), -INT8_C(  52),  INT8_C(  43),  INT8_C(  13), -INT8_C(  43), -INT8_C(  28),  INT8_C( 117) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comtrue_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 28235),  INT16_C( 23513),  INT16_C( 16883), -INT16_C(  9018),  INT16_C( 28384),  INT16_C( 22691),  INT16_C( 11365),  INT16_C( 16063) },
      { -INT16_C( 28235),  INT16_C( 23513),  INT16_C( 16883), -INT16_C(  9018),  INT16_C( 28384),  INT16_C( 22691),  INT16_C( 11365),  INT16_C( 16063) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C(  6066), -INT16_C(  7062),  INT16_C( 24736), -INT16_C( 18702), -INT16_C(  3283), -INT16_C( 27694),  INT16_C(  7013),  INT16_C( 29733) },
      {  INT16_C( 14447),  INT16_C( 20321), -INT16_C( 28807),  INT16_C( 15169), -INT16_C( 28084), -INT16_C( 11261),  INT16_C( 25123), -INT16_C(  7724) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 27971),  INT16_C( 13449),  INT16_C( 11953), -INT16_C( 11633), -INT16_C(  1278),  INT16_C( 21541),  INT16_C(   499), -INT16_C( 29240) },
      {  INT16_C( 18204),  INT16_C( 28143), -INT16_C(  8514),  INT16_C(  9721),  INT16_C(  8276), -INT16_C( 29596),  INT16_C( 14954), -INT16_C( 15809) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C(  5966),  INT16_C(  5090), -INT16_C( 32683),  INT16_C(  7900),  INT16_C( 12935),  INT16_C( 13869), -INT16_C( 29090),  INT16_C(  2230) },
      {  INT16_C( 18148),  INT16_C( 32493),  INT16_C( 13931), -INT16_C(  6955), -INT16_C( 24288),  INT16_C( 18990), -INT16_C( 16669),  INT16_C( 10728) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 29526),  INT16_C( 18910),  INT16_C( 24628), -INT16_C(  7743),  INT16_C(  8165),  INT16_C(   338), -INT16_C( 13745),  INT16_C( 11733) },
      { -INT16_C( 16658),  INT16_C( 19138), -INT16_C( 24793), -INT16_C( 16451), -INT16_C( 25127), -INT16_C( 11064), -INT16_C(  2762),  INT16_C( 23992) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 17711), -INT16_C( 25115), -INT16_C( 10761),  INT16_C( 25894),  INT16_C( 19267),  INT16_C( 31997), -INT16_C( 16787),  INT16_C( 17166) },
      {  INT16_C( 14179), -INT16_C( 26154),  INT16_C(  8859), -INT16_C(   615), -INT16_C( 25945), -INT16_C(  3428), -INT16_C(  6390), -INT16_C( 22379) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 17738), -INT16_C( 10144), -INT16_C(  6330), -INT16_C(  3853),  INT16_C( 15562),  INT16_C( 28820),  INT16_C( 29025), -INT16_C( 27574) },
      {  INT16_C( 14186),  INT16_C( 13201), -INT16_C( 14738), -INT16_C(  6319),  INT16_C(  8881),  INT16_C( 28177), -INT16_C( 25337),  INT16_C( 20584) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 25111), -INT16_C( 15691), -INT16_C( 24632), -INT16_C( 13552),  INT16_C( 31905), -INT16_C( 23167), -INT16_C(  5166),  INT16_C( 26223) },
      {  INT16_C( 18476), -INT16_C(  8101), -INT16_C( 27575), -INT16_C( 14898), -INT16_C( 17376),  INT16_C(  3983),  INT16_C(  7894), -INT16_C( 25062) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comtrue_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   592333272),  INT32_C(  1046873126), -INT32_C(   483748878),  INT32_C(    40252777) },
      {  INT32_C(   592333272),  INT32_C(  1046873126), -INT32_C(   483748878),  INT32_C(    40252777) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1738338769), -INT32_C(   537488684), -INT32_C(  1669402341), -INT32_C(   628002273) },
      { -INT32_C(  1013853892), -INT32_C(  1864687864), -INT32_C(   218560542), -INT32_C(  1340582194) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1849902208),  INT32_C(  2092092086), -INT32_C(   565753909),  INT32_C(  1287103113) },
      {  INT32_C(  1793637952),  INT32_C(   190379540), -INT32_C(  1722522981), -INT32_C(  1200859480) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(   639839329), -INT32_C(   437566312), -INT32_C(  1655682984),  INT32_C(  1014216125) },
      { -INT32_C(   541419767), -INT32_C(   171535115), -INT32_C(  1583011003),  INT32_C(  1632190111) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   298201443),  INT32_C(  1669793569), -INT32_C(  1610449687), -INT32_C(   240340125) },
      { -INT32_C(   344988478), -INT32_C(  1760821679), -INT32_C(   749475065), -INT32_C(   191294116) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1335416484),  INT32_C(  1013980154), -INT32_C(  1312462170), -INT32_C(  1270045406) },
      {  INT32_C(  1450126993),  INT32_C(   957431505), -INT32_C(   171562742), -INT32_C(  1186733177) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(   907264965), -INT32_C(  1198749494), -INT32_C(  1778214216), -INT32_C(   851799390) },
      { -INT32_C(   400426082),  INT32_C(   599677468), -INT32_C(   815370890), -INT32_C(   131092024) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1185359361),  INT32_C(   566580794),  INT32_C(   404722759), -INT32_C(  2074180980) },
      {  INT32_C(  1760548370), -INT32_C(  1661182501),  INT32_C(   731594866), -INT32_C(   112884027) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comtrue_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 4827420152686847433),  INT64_C( 2351017032843452794) },
      { -INT64_C( 4827420152686847433),  INT64_C( 2351017032843452794) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 1318907397904776171),  INT64_C(  246970282387777574) },
      { -INT64_C( 3014534770133342832), -INT64_C( 1447753086249662342) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 6901820662948417486),  INT64_C( 6957891663631265723) },
      { -INT64_C( 5609414929122897612),  INT64_C( 3107121265309028719) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 4045661127513538150),  INT64_C( 6238471471275466073) },
      { -INT64_C( 7358602143334717878),  INT64_C( 2966188204622873984) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 4561025498887071483),  INT64_C( 3342166001191074087) },
      { -INT64_C( 3081258487602582789),  INT64_C( 3311408266836896469) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 4709059121473874385),  INT64_C( 3522154446598982478) },
      { -INT64_C( 5969826206700296338),  INT64_C( 9179788988322859927) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C(  144109204175369717), -INT64_C( 6630182630353298442) },
      {  INT64_C( 7530936525393257676),  INT64_C( 7377758891505561070) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 5299929538076591767), -INT64_C( 3343706590326083003) },
      {  INT64_C( 5709504304017058364),  INT64_C( 3231116635510249985) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comtrue_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(224), UINT8_C( 34), UINT8_C(237), UINT8_C(194), UINT8_C(209), UINT8_C(110), UINT8_C(236), UINT8_C( 97),
        UINT8_C(102), UINT8_C(151), UINT8_C(249), UINT8_C(228), UINT8_C( 29), UINT8_C(244), UINT8_C(158), UINT8_C(  0) },
      { UINT8_C(224), UINT8_C( 34), UINT8_C(237), UINT8_C(194), UINT8_C(209), UINT8_C(110), UINT8_C(236), UINT8_C( 97),
        UINT8_C(102), UINT8_C(151), UINT8_C(249), UINT8_C(228), UINT8_C( 29), UINT8_C(244), UINT8_C(158), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(231), UINT8_C(128), UINT8_C(123), UINT8_C( 38), UINT8_C(126), UINT8_C(221), UINT8_C( 57), UINT8_C(170),
        UINT8_C(249), UINT8_C(153), UINT8_C(192), UINT8_C( 36), UINT8_C(158), UINT8_C(177), UINT8_C(170), UINT8_C( 23) },
      { UINT8_C(247), UINT8_C( 83), UINT8_C(247), UINT8_C(208), UINT8_C( 40), UINT8_C(232), UINT8_C(  2), UINT8_C(145),
        UINT8_C(127), UINT8_C( 82), UINT8_C(179), UINT8_C(239), UINT8_C( 77), UINT8_C(114), UINT8_C(247), UINT8_C(121) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(244), UINT8_C(238), UINT8_C(109), UINT8_C(154), UINT8_C( 66), UINT8_C( 49), UINT8_C( 99), UINT8_C(193),
        UINT8_C(253), UINT8_C(179), UINT8_C(  0), UINT8_C(190), UINT8_C(191), UINT8_C(122), UINT8_C(194), UINT8_C(112) },
      { UINT8_C(  4), UINT8_C(225), UINT8_C( 44), UINT8_C(157), UINT8_C(130), UINT8_C(152), UINT8_C(184), UINT8_C( 33),
        UINT8_C(185), UINT8_C(236), UINT8_C( 19), UINT8_C( 75), UINT8_C(202), UINT8_C( 72), UINT8_C(137), UINT8_C(132) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(140), UINT8_C(252), UINT8_C(190), UINT8_C( 49), UINT8_C(221), UINT8_C( 62), UINT8_C(160), UINT8_C(219),
        UINT8_C( 54), UINT8_C(110), UINT8_C(153), UINT8_C(141), UINT8_C(131), UINT8_C(159), UINT8_C(  9), UINT8_C(126) },
      { UINT8_C( 49), UINT8_C( 82), UINT8_C(243), UINT8_C(240), UINT8_C(136), UINT8_C(132), UINT8_C(247), UINT8_C( 88),
        UINT8_C( 59), UINT8_C(236), UINT8_C(128), UINT8_C(191), UINT8_C( 61), UINT8_C(126), UINT8_C( 62), UINT8_C(104) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(215), UINT8_C( 51), UINT8_C(215), UINT8_C(179), UINT8_C(248), UINT8_C( 12), UINT8_C(217), UINT8_C( 65),
        UINT8_C(204), UINT8_C( 85), UINT8_C(244), UINT8_C( 89), UINT8_C(143), UINT8_C( 39), UINT8_C(102), UINT8_C(139) },
      { UINT8_C(164), UINT8_C( 48), UINT8_C(182), UINT8_C(147), UINT8_C(225), UINT8_C(182), UINT8_C(165), UINT8_C(128),
        UINT8_C( 46), UINT8_C(218), UINT8_C( 98), UINT8_C( 21), UINT8_C( 78), UINT8_C( 26), UINT8_C(253), UINT8_C(111) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(252), UINT8_C( 26), UINT8_C( 30), UINT8_C(232), UINT8_C( 58), UINT8_C(164), UINT8_C(247), UINT8_C( 60),
        UINT8_C(230), UINT8_C(237), UINT8_C(119), UINT8_C(234), UINT8_C(142), UINT8_C( 26), UINT8_C(192), UINT8_C(221) },
      { UINT8_C(133), UINT8_C(  2), UINT8_C(220), UINT8_C( 76), UINT8_C( 54), UINT8_C( 54), UINT8_C(171), UINT8_C(223),
        UINT8_C(185), UINT8_C( 63), UINT8_C( 32), UINT8_C( 19), UINT8_C(164), UINT8_C( 38), UINT8_C(173), UINT8_C(223) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 36), UINT8_C( 58), UINT8_C(252), UINT8_C(152), UINT8_C( 76), UINT8_C( 13), UINT8_C(224), UINT8_C( 18),
        UINT8_C(172), UINT8_C(192), UINT8_C(139), UINT8_C(  8), UINT8_C( 38), UINT8_C(128), UINT8_C(  1), UINT8_C(189) },
      { UINT8_C(253), UINT8_C( 81), UINT8_C(205), UINT8_C(228), UINT8_C( 47), UINT8_C( 10), UINT8_C(242), UINT8_C(189),
        UINT8_C(  5), UINT8_C(161), UINT8_C( 36), UINT8_C(130), UINT8_C(232), UINT8_C(169), UINT8_C( 56), UINT8_C(  1) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(118), UINT8_C( 25), UINT8_C(218), UINT8_C(138), UINT8_C(213), UINT8_C( 79), UINT8_C(126), UINT8_C( 11),
        UINT8_C( 71), UINT8_C( 85), UINT8_C(153), UINT8_C(122),    UINT8_MAX, UINT8_C( 98), UINT8_C( 16), UINT8_C(115) },
      { UINT8_C( 52), UINT8_C(164), UINT8_C(240), UINT8_C( 35), UINT8_C(115), UINT8_C( 60), UINT8_C( 97), UINT8_C(100),
        UINT8_C( 57), UINT8_C(139), UINT8_C(213), UINT8_C( 41), UINT8_C(193), UINT8_C(172), UINT8_C(133), UINT8_C( 29) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comtrue_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(16667), UINT16_C(34590), UINT16_C(29566), UINT16_C(29111), UINT16_C(13535), UINT16_C( 2311), UINT16_C(51138), UINT16_C(18389) },
      { UINT16_C(16667), UINT16_C(34590), UINT16_C(29566), UINT16_C(29111), UINT16_C(13535), UINT16_C( 2311), UINT16_C(51138), UINT16_C(18389) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(33617), UINT16_C(53423), UINT16_C(54443), UINT16_C( 7135), UINT16_C(33406), UINT16_C(53915), UINT16_C(14040), UINT16_C(31612) },
      { UINT16_C(14906), UINT16_C(22322), UINT16_C(33007), UINT16_C(35445), UINT16_C(59035), UINT16_C(32062), UINT16_C(47127), UINT16_C(33080) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(30332), UINT16_C(46449), UINT16_C(55422), UINT16_C(10582), UINT16_C( 4348), UINT16_C(17374), UINT16_C(20436), UINT16_C(25093) },
      { UINT16_C(35580), UINT16_C(49788), UINT16_C(32463), UINT16_C(41119), UINT16_C(62116), UINT16_C(40615), UINT16_C(15525), UINT16_C(26657) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1759), UINT16_C(39071), UINT16_C(21141), UINT16_C(55213), UINT16_C(48346), UINT16_C(17670), UINT16_C(65375), UINT16_C( 7176) },
      { UINT16_C(48009), UINT16_C(36966), UINT16_C(30406), UINT16_C(63773), UINT16_C(57378), UINT16_C(13225), UINT16_C(23317), UINT16_C(17784) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(47775), UINT16_C(17055), UINT16_C(18839), UINT16_C(28108), UINT16_C( 3649), UINT16_C(41083), UINT16_C(20254), UINT16_C(61293) },
      { UINT16_C(21768), UINT16_C(34902), UINT16_C(28542), UINT16_C(56791), UINT16_C(14652), UINT16_C( 1707), UINT16_C( 7438), UINT16_C(24613) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 7143), UINT16_C(31706), UINT16_C(50733), UINT16_C(13211), UINT16_C(36696), UINT16_C( 7334), UINT16_C(18107), UINT16_C( 9244) },
      { UINT16_C(56993), UINT16_C(29622), UINT16_C(29084), UINT16_C(38580), UINT16_C(33562), UINT16_C(56599), UINT16_C(35641), UINT16_C(  272) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(45277), UINT16_C( 2744), UINT16_C(53503), UINT16_C(28673), UINT16_C(50760), UINT16_C(33261), UINT16_C(60894), UINT16_C(  766) },
      { UINT16_C(57470), UINT16_C( 6637), UINT16_C(33995), UINT16_C(27551), UINT16_C(18917), UINT16_C(33108), UINT16_C(44094), UINT16_C(28706) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(  425), UINT16_C(47522), UINT16_C(28596), UINT16_C(28393), UINT16_C(15416), UINT16_C(38585), UINT16_C(18990), UINT16_C(54265) },
      { UINT16_C(58052), UINT16_C(16995), UINT16_C(45489), UINT16_C(41853), UINT16_C( 4293), UINT16_C(47818), UINT16_C(35268), UINT16_C(62529) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comtrue_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1325307508), UINT32_C(1933093877), UINT32_C( 611546961), UINT32_C(3723913300) },
      { UINT32_C(1325307508), UINT32_C(1933093877), UINT32_C( 611546961), UINT32_C(3723913300) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3061869982), UINT32_C(2268594166), UINT32_C(1340170977), UINT32_C(3612747891) },
      { UINT32_C(2453010534), UINT32_C(3369569641), UINT32_C(4085318074), UINT32_C(1792953591) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1017907250), UINT32_C(1605728067), UINT32_C( 167888482), UINT32_C(1598723061) },
      { UINT32_C(1303424678), UINT32_C(3048086713), UINT32_C(3410846364), UINT32_C(3231121600) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2655992744), UINT32_C(1944002368), UINT32_C(2979186031), UINT32_C(3573797615) },
      { UINT32_C(1205223517), UINT32_C(2175099276), UINT32_C(1950162975), UINT32_C( 655067991) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2731642409), UINT32_C( 178061716), UINT32_C( 234677809), UINT32_C(2171333388) },
      { UINT32_C(1192114098), UINT32_C(1990550155), UINT32_C(3048981866), UINT32_C(3911251299) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 295340765), UINT32_C(1842882023), UINT32_C(3869749712), UINT32_C(2859067633) },
      { UINT32_C( 398596558), UINT32_C(3667143006), UINT32_C(1479465382), UINT32_C(1304446605) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2987570923), UINT32_C(3849753059), UINT32_C(  83668595), UINT32_C(2581909577) },
      { UINT32_C(2103013848), UINT32_C(4133273260), UINT32_C( 603906810), UINT32_C(2597488508) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1336056443), UINT32_C(3093385006), UINT32_C( 778135106), UINT32_C(2546379962) },
      { UINT32_C(1111213305), UINT32_C( 316876573), UINT32_C(3750914703), UINT32_C( 423543000) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comtrue_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comtrue_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 3350510381451755447), UINT64_C(16930864899557384294) },
      { UINT64_C( 3350510381451755447), UINT64_C(16930864899557384294) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8508265454644468825), UINT64_C( 1363736690095880333) },
      { UINT64_C(10500951027009105093), UINT64_C(15734554044523291655) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 7625327590781190175), UINT64_C(14754978182317413659) },
      { UINT64_C( 2880546174294223309), UINT64_C(12817318442109975372) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 3750008482140780916), UINT64_C(10497191513006491489) },
      { UINT64_C( 4189497283825827832), UINT64_C(13072326418065599582) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 2351656805455728255), UINT64_C(12074971609072998792) },
      { UINT64_C( 1162739342028862829), UINT64_C( 3522466258036686693) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8323443085463963497), UINT64_C( 6293901481351254200) },
      { UINT64_C(17428138038975976277), UINT64_C( 7507649261918993800) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8472081730515119193), UINT64_C(16854752128826783256) },
      { UINT64_C( 2827141321774572248), UINT64_C(11978707203669650927) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8122805138361239160), UINT64_C(11901595990489207505) },
      { UINT64_C(17953440984500758813), UINT64_C( 3597954551509030851) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comtrue_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comtrue_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  19), -INT8_C( 100), -INT8_C( 104),      INT8_MAX,  INT8_C( 106),  INT8_C(  52), -INT8_C(  30), -INT8_C(  86),
         INT8_C(  10),  INT8_C(  44), -INT8_C(  80),  INT8_C(  91), -INT8_C(  25),  INT8_C(   9),  INT8_C(   6), -INT8_C(  45) },
      { -INT8_C(  19), -INT8_C( 100), -INT8_C( 104),      INT8_MAX,  INT8_C( 106),  INT8_C(  52), -INT8_C(  30), -INT8_C(  86),
         INT8_C(  10),  INT8_C(  44), -INT8_C(  80),  INT8_C(  91), -INT8_C(  25),  INT8_C(   9),  INT8_C(   6), -INT8_C(  45) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  77), -INT8_C(  80), -INT8_C(  63), -INT8_C(  49),  INT8_C(  19),  INT8_C( 112), -INT8_C( 122), -INT8_C(  82),
         INT8_C(  44),  INT8_C(  67), -INT8_C(   7), -INT8_C(  43),  INT8_C( 121),  INT8_C(  81),  INT8_C(  47),  INT8_C(  83) },
      { -INT8_C(  31), -INT8_C(  74),  INT8_C( 101), -INT8_C(  63), -INT8_C(  92), -INT8_C( 123), -INT8_C(  14),  INT8_C( 108),
        -INT8_C(  20),  INT8_C(  13),  INT8_C( 122), -INT8_C(  73), -INT8_C(  90),  INT8_C(  91),  INT8_C( 101), -INT8_C(  70) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 113),  INT8_C(   0), -INT8_C( 113),  INT8_C(  47), -INT8_C( 110),  INT8_C(  20),  INT8_C(  65), -INT8_C( 113),
         INT8_C(  81),  INT8_C( 122),  INT8_C(  97),  INT8_C( 120),  INT8_C(   2),  INT8_C( 102), -INT8_C(  27),  INT8_C(  82) },
      {  INT8_C( 124),  INT8_C(  29), -INT8_C( 115),  INT8_C(  50), -INT8_C( 111), -INT8_C(   4), -INT8_C(  46), -INT8_C(   2),
        -INT8_C(  97), -INT8_C(  68),  INT8_C(  26), -INT8_C(  45),  INT8_C(  98), -INT8_C(  12),  INT8_C(  45), -INT8_C(  93) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  12), -INT8_C(  33), -INT8_C(  20),  INT8_C(  35), -INT8_C( 104),  INT8_C(  96),  INT8_C(  65), -INT8_C(  28),
         INT8_C(  91),  INT8_C(  67),  INT8_C(  82), -INT8_C(  65), -INT8_C(  36), -INT8_C(  58), -INT8_C(   6),  INT8_C( 119) },
      { -INT8_C(  27),  INT8_C(  88),  INT8_C( 121), -INT8_C( 102), -INT8_C(  38), -INT8_C(  96),  INT8_C( 106), -INT8_C(  88),
         INT8_C(  74), -INT8_C(  63), -INT8_C(  10),  INT8_C( 119), -INT8_C(  60), -INT8_C(  35),  INT8_C(  72), -INT8_C(  42) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  20), -INT8_C(  40),  INT8_C(  64),  INT8_C( 113), -INT8_C(  51),  INT8_C(  94),  INT8_C( 108), -INT8_C(  11),
         INT8_C( 113),  INT8_C(  39),  INT8_C(  52),  INT8_C( 116), -INT8_C(  81),  INT8_C( 121),  INT8_C(  84),  INT8_C(  10) },
      {  INT8_C(  69), -INT8_C(  17), -INT8_C( 112), -INT8_C(  63),  INT8_C(  39),  INT8_C( 122), -INT8_C(  94), -INT8_C(  78),
         INT8_C(  22), -INT8_C(  91),  INT8_C( 120),  INT8_C( 109),  INT8_C( 115),  INT8_C(  29), -INT8_C( 100), -INT8_C( 101) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  86),  INT8_C( 112), -INT8_C(  12), -INT8_C(  30), -INT8_C(  37),  INT8_C(  21), -INT8_C(  85),  INT8_C(   9),
        -INT8_C(  68), -INT8_C(  83),  INT8_C( 111),  INT8_C(  93),  INT8_C(  37), -INT8_C( 120), -INT8_C(  35),  INT8_C(  83) },
      { -INT8_C(  61),  INT8_C( 107),  INT8_C(  57),  INT8_C( 110),  INT8_C(  31), -INT8_C( 112),  INT8_C(  99),  INT8_C(  99),
         INT8_C(  42), -INT8_C(  17),  INT8_C(   6),  INT8_C( 124),  INT8_C(  24), -INT8_C(  68),  INT8_C(  19),  INT8_C(  58) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 114),  INT8_C(  49),  INT8_C( 110),  INT8_C(  62),  INT8_C( 103), -INT8_C( 115), -INT8_C(  25),  INT8_C( 105),
         INT8_C( 100),  INT8_C(  93),  INT8_C( 107),  INT8_C(  67), -INT8_C(  28), -INT8_C(   6),  INT8_C( 123), -INT8_C( 103) },
      { -INT8_C( 120),  INT8_C(  83), -INT8_C(  34),  INT8_C( 107),  INT8_C( 106), -INT8_C(  20), -INT8_C( 109),  INT8_C(   5),
        -INT8_C(  81),  INT8_C(  39),  INT8_C(  10),  INT8_C( 107),  INT8_C(  91), -INT8_C(  61), -INT8_C( 108), -INT8_C(   6) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 105), -INT8_C(  94),  INT8_C(  23),  INT8_C(  77),  INT8_C(  28), -INT8_C(  49),  INT8_C(   6),  INT8_C(  94),
        -INT8_C( 112), -INT8_C(  65), -INT8_C( 112), -INT8_C(  19), -INT8_C( 108), -INT8_C(  41),  INT8_C(  24),  INT8_C(  38) },
      { -INT8_C(  68),  INT8_C(  47), -INT8_C(  26),  INT8_C( 126), -INT8_C(  79), -INT8_C( 106),  INT8_C(  28), -INT8_C(  34),
        -INT8_C(  52), -INT8_C(  42), -INT8_C(  21),  INT8_C(   3), -INT8_C(  29),  INT8_C(  57),  INT8_C(   6),  INT8_C(  37) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_comfalse_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 19299), -INT16_C( 10665), -INT16_C(  7521),  INT16_C( 12018),  INT16_C( 23656),  INT16_C(  9543),  INT16_C( 10462),  INT16_C( 16539) },
      {  INT16_C( 19299), -INT16_C( 10665), -INT16_C(  7521),  INT16_C( 12018),  INT16_C( 23656),  INT16_C(  9543),  INT16_C( 10462),  INT16_C( 16539) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 30587),  INT16_C( 28857), -INT16_C( 27492),  INT16_C( 14308), -INT16_C( 31830),  INT16_C(  3089),  INT16_C(  9817),  INT16_C(   339) },
      { -INT16_C( 19065), -INT16_C( 23657), -INT16_C( 12645),  INT16_C(  8593), -INT16_C( 17643), -INT16_C( 19978), -INT16_C(  2966),  INT16_C( 12524) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  7154),  INT16_C(  2239), -INT16_C(  3886),  INT16_C( 22485), -INT16_C( 18832),  INT16_C( 20196), -INT16_C( 28060), -INT16_C( 10398) },
      {  INT16_C( 26622),  INT16_C( 31293), -INT16_C( 25418), -INT16_C( 32307),  INT16_C( 25791),  INT16_C( 23047),  INT16_C( 17375),  INT16_C( 16115) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 12675),  INT16_C(  4192), -INT16_C( 19716), -INT16_C( 30506), -INT16_C(  2233), -INT16_C( 28468), -INT16_C( 31059), -INT16_C(  4581) },
      { -INT16_C(  5648),  INT16_C(  9395),  INT16_C( 21400), -INT16_C( 27508), -INT16_C(  8051), -INT16_C(  5920),  INT16_C(  7653), -INT16_C( 20072) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 13317),  INT16_C( 19972), -INT16_C(  7999),  INT16_C(  4302), -INT16_C( 12457), -INT16_C( 25551),  INT16_C(  2524), -INT16_C( 28570) },
      { -INT16_C( 15228),  INT16_C( 26975), -INT16_C(  1046), -INT16_C( 23368), -INT16_C( 18776),  INT16_C(  9195), -INT16_C( 29914), -INT16_C( 11325) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 26031), -INT16_C( 29677), -INT16_C( 31542),  INT16_C( 14503), -INT16_C( 14905),  INT16_C( 14459),  INT16_C(  9368),  INT16_C(   811) },
      {  INT16_C( 32738),  INT16_C(  4267), -INT16_C( 25260), -INT16_C(  2248),  INT16_C( 28216), -INT16_C( 11378), -INT16_C( 27577), -INT16_C(  5540) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  9154), -INT16_C( 28427), -INT16_C( 23106),  INT16_C( 18504),  INT16_C( 25280),  INT16_C( 11538), -INT16_C(  8567), -INT16_C( 28590) },
      { -INT16_C( 24013), -INT16_C(  7170),  INT16_C( 16253), -INT16_C( 10764), -INT16_C( 28316), -INT16_C( 16589),  INT16_C( 16883),  INT16_C( 16203) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 29349),  INT16_C(  8722),  INT16_C( 19526), -INT16_C( 30567),  INT16_C( 11369),  INT16_C( 16990),  INT16_C( 16216),  INT16_C( 32707) },
      { -INT16_C( 18785), -INT16_C( 22337), -INT16_C(  5106), -INT16_C( 30508), -INT16_C( 22956), -INT16_C( 20415), -INT16_C( 26160),  INT16_C(  6776) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_comfalse_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   215100579),  INT32_C(  1065517066),  INT32_C(  1103670763),  INT32_C(   409423789) },
      {  INT32_C(   215100579),  INT32_C(  1065517066),  INT32_C(  1103670763),  INT32_C(   409423789) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   676872781),  INT32_C(  1472244142),  INT32_C(  1847604529), -INT32_C(  1026841466) },
      {  INT32_C(   362710978), -INT32_C(  1209316943), -INT32_C(   256479891), -INT32_C(  1557915857) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   724618854), -INT32_C(  1985970170), -INT32_C(  1053309405), -INT32_C(  2127729986) },
      {  INT32_C(    81536991),  INT32_C(   918335460),  INT32_C(   428995352),  INT32_C(  1742970503) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  2041569809),  INT32_C(  1734113470),  INT32_C(  1911611985), -INT32_C(  1652231136) },
      { -INT32_C(  1560899038),  INT32_C(    98417482), -INT32_C(  2101164269), -INT32_C(  1383207843) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   650311817),  INT32_C(   970758525),  INT32_C(  1169297636),  INT32_C(  1606043987) },
      { -INT32_C(  1219341644),  INT32_C(  1815508108), -INT32_C(   189828729), -INT32_C(  1123546536) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   339920063),  INT32_C(  1191832811),  INT32_C(   115792131),  INT32_C(   263549184) },
      {  INT32_C(   190508989), -INT32_C(  1297030319),  INT32_C(   918714780), -INT32_C(   549519584) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   232349166), -INT32_C(   657885007),  INT32_C(  2096284887), -INT32_C(   178293298) },
      {  INT32_C(  1702162276),  INT32_C(   556863042),  INT32_C(   308439161),  INT32_C(  1528157022) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   995174552),  INT32_C(   889538167),  INT32_C(  1866422664),  INT32_C(  1503550566) },
      { -INT32_C(  1911890734), -INT32_C(     6095098),  INT32_C(  1324795463),  INT32_C(  2021101498) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_comfalse_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6366298885846147464), -INT64_C( 9053310093840015299) },
      { -INT64_C( 6366298885846147464), -INT64_C( 9053310093840015299) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 7643525258363585233),  INT64_C( 9172489781360728365) },
      {  INT64_C( 8399992451541847259), -INT64_C( 5079792567336525282) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 3167527705361488802), -INT64_C( 5153845950562702508) },
      { -INT64_C( 1967080906568107032),  INT64_C( 5112346950309340756) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(  695738907731328339),  INT64_C( 7775603355661091812) },
      {  INT64_C( 4751201580733526728),  INT64_C( 8185989162854183943) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 8568407790313302891), -INT64_C( 2269208996944795132) },
      { -INT64_C( 3373138648826693214), -INT64_C( 9052155927955122850) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4854216040627442414),  INT64_C( 6858664712003037148) },
      { -INT64_C( 2423726253071017569), -INT64_C( 4599253573658439550) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 2430982534606457967),  INT64_C( 3446570983174816405) },
      { -INT64_C( 5882078299363616281),  INT64_C( 8423466024813833627) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1288368508354637909), -INT64_C( 7395581740469386409) },
      { -INT64_C( 8567077577994681951), -INT64_C( 1840201770462104112) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_comfalse_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(237), UINT8_C( 63), UINT8_C(198), UINT8_C(174), UINT8_C(171), UINT8_C(  7), UINT8_C(176), UINT8_C(106),
        UINT8_C( 73), UINT8_C(243), UINT8_C(211), UINT8_C(142), UINT8_C(127), UINT8_C(179), UINT8_C(175), UINT8_C(229) },
      { UINT8_C(237), UINT8_C( 63), UINT8_C(198), UINT8_C(174), UINT8_C(171), UINT8_C(  7), UINT8_C(176), UINT8_C(106),
        UINT8_C( 73), UINT8_C(243), UINT8_C(211), UINT8_C(142), UINT8_C(127), UINT8_C(179), UINT8_C(175), UINT8_C(229) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(246), UINT8_C( 26), UINT8_C( 92), UINT8_C(122), UINT8_C(159), UINT8_C( 33), UINT8_C(123), UINT8_C(185),
        UINT8_C( 73), UINT8_C( 47), UINT8_C(110), UINT8_C(210), UINT8_C(115), UINT8_C(151), UINT8_C(196), UINT8_C( 94) },
      { UINT8_C( 94), UINT8_C( 98), UINT8_C(247), UINT8_C( 69), UINT8_C(103), UINT8_C( 80), UINT8_C( 90), UINT8_C(223),
        UINT8_C(148), UINT8_C( 25), UINT8_C( 77), UINT8_C( 89), UINT8_C(109), UINT8_C(248), UINT8_C(179), UINT8_C( 91) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 13), UINT8_C(106), UINT8_C(166), UINT8_C(231), UINT8_C(120), UINT8_C( 52), UINT8_C(105), UINT8_C(133),
        UINT8_C( 47), UINT8_C(163), UINT8_C(157), UINT8_C(157), UINT8_C(  2), UINT8_C( 23), UINT8_C(184), UINT8_C( 36) },
      { UINT8_C( 38), UINT8_C(195), UINT8_C(180), UINT8_C(122), UINT8_C(135), UINT8_C(174), UINT8_C(  4), UINT8_C(147),
        UINT8_C( 95), UINT8_C(253), UINT8_C(204), UINT8_C( 86), UINT8_C(  8), UINT8_C(117), UINT8_C( 81), UINT8_C( 66) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 15), UINT8_C( 60), UINT8_C(175), UINT8_C( 87), UINT8_C(137), UINT8_C(223), UINT8_C(202), UINT8_C( 52),
        UINT8_C(170), UINT8_C(153), UINT8_C(134), UINT8_C(125), UINT8_C(147), UINT8_C(211), UINT8_C( 59), UINT8_C(127) },
      { UINT8_C(108), UINT8_C(231), UINT8_C( 99), UINT8_C( 23), UINT8_C(179), UINT8_C( 41), UINT8_C(150), UINT8_C(207),
        UINT8_C(211), UINT8_C( 40), UINT8_C(185), UINT8_C( 75), UINT8_C(249), UINT8_C( 49), UINT8_C(114), UINT8_C(228) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 35), UINT8_C( 21), UINT8_C(222), UINT8_C(146), UINT8_C(122), UINT8_C( 44), UINT8_C(135), UINT8_C( 15),
        UINT8_C(225), UINT8_C(154), UINT8_C(144), UINT8_C( 57), UINT8_C(206), UINT8_C(209), UINT8_C( 51), UINT8_C(185) },
      { UINT8_C( 88), UINT8_C( 88), UINT8_C(110), UINT8_C(226), UINT8_C(146), UINT8_C(202), UINT8_C(248), UINT8_C(219),
        UINT8_C( 24), UINT8_C( 33), UINT8_C(122), UINT8_C(  1), UINT8_C(231), UINT8_C( 52), UINT8_C(252), UINT8_C(135) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(114), UINT8_C(127), UINT8_C(157), UINT8_C( 95), UINT8_C(242), UINT8_C( 35), UINT8_C(136), UINT8_C( 94),
        UINT8_C(253), UINT8_C( 45), UINT8_C( 35), UINT8_C(155), UINT8_C( 90), UINT8_C( 27), UINT8_C(138), UINT8_C( 24) },
      { UINT8_C( 20), UINT8_C(157), UINT8_C( 59), UINT8_C(164), UINT8_C(205), UINT8_C(152), UINT8_C( 19),    UINT8_MAX,
        UINT8_C( 85), UINT8_C(112), UINT8_C(121), UINT8_C( 64), UINT8_C(123), UINT8_C(135), UINT8_C(217), UINT8_C(116) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 35), UINT8_C(  1), UINT8_C( 84), UINT8_C(136), UINT8_C(153), UINT8_C(203), UINT8_C(181), UINT8_C(105),
        UINT8_C( 37), UINT8_C(219), UINT8_C(167), UINT8_C(105), UINT8_C(224), UINT8_C(185), UINT8_C( 38), UINT8_C(229) },
      { UINT8_C(197), UINT8_C( 62), UINT8_C( 52), UINT8_C( 36), UINT8_C( 11), UINT8_C(155), UINT8_C(205), UINT8_C(131),
        UINT8_C(179), UINT8_C(158), UINT8_C( 28), UINT8_C(207), UINT8_C( 93), UINT8_C( 49), UINT8_C(239), UINT8_C(243) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 95), UINT8_C( 36), UINT8_C(105), UINT8_C(211), UINT8_C( 24), UINT8_C( 44), UINT8_C(246), UINT8_C(119),
        UINT8_C(130), UINT8_C( 43), UINT8_C(132), UINT8_C(108), UINT8_C(  7), UINT8_C(177), UINT8_C(241), UINT8_C(103) },
      { UINT8_C(150), UINT8_C(195), UINT8_C(191), UINT8_C( 44), UINT8_C(245), UINT8_C(220), UINT8_C( 15), UINT8_C(174),
        UINT8_C( 89), UINT8_C( 50), UINT8_C(205), UINT8_C(120), UINT8_C( 52), UINT8_C( 58), UINT8_C( 40), UINT8_C( 75) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_comfalse_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(28238), UINT16_C( 2373), UINT16_C(19991), UINT16_C(53556), UINT16_C(42300), UINT16_C(27683), UINT16_C( 3448), UINT16_C(59601) },
      { UINT16_C(28238), UINT16_C( 2373), UINT16_C(19991), UINT16_C(53556), UINT16_C(42300), UINT16_C(27683), UINT16_C( 3448), UINT16_C(59601) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(46509), UINT16_C(33350), UINT16_C(25139), UINT16_C(51906), UINT16_C(46191), UINT16_C(  499), UINT16_C(43944), UINT16_C(50794) },
      { UINT16_C(26903), UINT16_C(62032), UINT16_C(14909), UINT16_C(49237), UINT16_C(53626), UINT16_C(12778), UINT16_C(54746), UINT16_C(44720) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(39986), UINT16_C(61232), UINT16_C(13932), UINT16_C( 7628), UINT16_C(44319), UINT16_C(13301), UINT16_C(35683), UINT16_C(43679) },
      { UINT16_C(40419), UINT16_C(22002), UINT16_C(63283), UINT16_C(35395), UINT16_C(14436), UINT16_C(33346), UINT16_C( 4054), UINT16_C(  629) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(65102), UINT16_C(15333), UINT16_C(24136), UINT16_C(61463), UINT16_C(42127), UINT16_C(54845), UINT16_C(57866), UINT16_C(16558) },
      { UINT16_C(37337), UINT16_C(64404), UINT16_C(36257), UINT16_C(30692), UINT16_C(24867), UINT16_C(10388), UINT16_C(50452), UINT16_C(11272) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(25896), UINT16_C(11981), UINT16_C(58481), UINT16_C(35465), UINT16_C( 8679), UINT16_C(45618), UINT16_C(47432), UINT16_C(53375) },
      { UINT16_C(52514), UINT16_C(44444), UINT16_C( 1325), UINT16_C(53538), UINT16_C(54495), UINT16_C(60486), UINT16_C(65083), UINT16_C(29777) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(22762), UINT16_C(36944), UINT16_C(53132), UINT16_C(13580), UINT16_C(44112), UINT16_C(36412), UINT16_C( 6082), UINT16_C(41722) },
      { UINT16_C(55781), UINT16_C(12660), UINT16_C(26242), UINT16_C(57060), UINT16_C( 6847), UINT16_C(38082), UINT16_C(50163), UINT16_C( 8759) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(24761), UINT16_C(10454), UINT16_C(10308), UINT16_C(14215), UINT16_C(52978), UINT16_C(13507), UINT16_C( 1059), UINT16_C(64775) },
      { UINT16_C(15947), UINT16_C(20354), UINT16_C(47174), UINT16_C(59409), UINT16_C(47852), UINT16_C(59502), UINT16_C( 7142), UINT16_C(32165) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 1216), UINT16_C(49095), UINT16_C(63038), UINT16_C(55777), UINT16_C( 3828), UINT16_C(27183), UINT16_C(34833), UINT16_C(11150) },
      { UINT16_C(33660), UINT16_C(53552), UINT16_C(  802), UINT16_C(13715), UINT16_C(15502), UINT16_C(45748), UINT16_C( 3770), UINT16_C(52864) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_comfalse_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 495701028), UINT32_C(1661223205), UINT32_C(4192859518), UINT32_C(1920445492) },
      { UINT32_C( 495701028), UINT32_C(1661223205), UINT32_C(4192859518), UINT32_C(1920445492) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2112172191), UINT32_C( 223432893), UINT32_C(3103467980), UINT32_C(1571922967) },
      { UINT32_C( 176832528), UINT32_C( 500634271), UINT32_C(2841053882), UINT32_C( 464156470) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 487116252), UINT32_C(3123947200), UINT32_C(3282700494), UINT32_C(1914758822) },
      { UINT32_C(1311566250), UINT32_C(1312976980), UINT32_C(1105384910), UINT32_C(1829761724) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1996743516), UINT32_C(2199981778), UINT32_C(2603311549), UINT32_C(1437981454) },
      { UINT32_C(2967096858), UINT32_C(1076716526), UINT32_C(2347949794), UINT32_C(2995725169) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1413347655), UINT32_C(2936246172), UINT32_C( 149274049), UINT32_C(1297714168) },
      { UINT32_C(4210751369), UINT32_C( 964752146), UINT32_C(1307618847), UINT32_C( 806360314) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2065602757), UINT32_C(2277585349), UINT32_C(3527451137), UINT32_C(2767388428) },
      { UINT32_C(4076236063), UINT32_C(2183342442), UINT32_C(1346555052), UINT32_C( 830196994) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3054389244), UINT32_C(1397030134), UINT32_C(3232013222), UINT32_C(2691251953) },
      { UINT32_C(1630811907), UINT32_C(1677659294), UINT32_C(1548927154), UINT32_C(4223226927) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3413478935), UINT32_C(1534261719), UINT32_C(2625187287), UINT32_C(2326220880) },
      { UINT32_C( 236903774), UINT32_C( 603628630), UINT32_C( 965153625), UINT32_C(3601969961) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_comfalse_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_comfalse_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(16587935071193527612), UINT64_C(12291236871839146685) },
      { UINT64_C(16587935071193527612), UINT64_C(12291236871839146685) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(  936179423556331607), UINT64_C(  885787018599615688) },
      { UINT64_C( 4428066784809584020), UINT64_C( 5121735281528422783) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 7273618990605459223), UINT64_C(16460119146588271400) },
      { UINT64_C(12183757784063755590), UINT64_C(12255644603997213255) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 8411877623334783685), UINT64_C(11890677820861681824) },
      { UINT64_C( 8071428364446482042), UINT64_C( 2052088554210205242) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9532074734755492490), UINT64_C(11021214541104852057) },
      { UINT64_C(15719502767937189466), UINT64_C(16370063756630862978) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(15887387323360124302), UINT64_C(  370777384618741371) },
      { UINT64_C( 3559445977505232651), UINT64_C( 5122796480762872903) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(14069199249831139064), UINT64_C( 3783401529332825901) },
      { UINT64_C(13522030736708520376), UINT64_C(10529289842004242352) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9474241958379987696), UINT64_C( 7849626402426275479) },
      { UINT64_C(14039565349656785543), UINT64_C(  733341401437713638) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_comfalse_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = (i == 0) ? a : simde_test_x86_random_u64x2();
    simde__m128i r = simde_mm_comfalse_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_frcz_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    12.42),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -45.81) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.42),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.81) } },
    { { SIMDE_FLOAT32_C(    -0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { SIMDE_FLOAT32_C(    -0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { { SIMDE_FLOAT32_C(  -267.43), SIMDE_FLOAT32_C(   697.99), SIMDE_FLOAT32_C(   720.88), SIMDE_FLOAT32_C(   488.02) },
      { SIMDE_FLOAT32_C(    -0.43), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(     0.02) } },
    { { SIMDE_FLOAT32_C(   -83.96), SIMDE_FLOAT32_C(   757.62), SIMDE_FLOAT32_C(   563.16), SIMDE_FLOAT32_C(  -657.64) },
      { SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(    -0.64) } },
    { { SIMDE_FLOAT32_C(  -248.94), SIMDE_FLOAT32_C(  -920.22), SIMDE_FLOAT32_C(   216.77), SIMDE_FLOAT32_C(   216.41) },
      { SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(     0.41) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_frcz_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 1 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 1, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 r = simde_mm_frcz_ps(a);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_frcz_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   721.61), SIMDE_FLOAT64_C(  -998.54) },
      { SIMDE_FLOAT64_C(     0.61), SIMDE_FLOAT64_C(    -0.54) } },
    { { SIMDE_FLOAT64_C(   303.63), SIMDE_FLOAT64_C(  -654.53) },
      { SIMDE_FLOAT64_C(     0.63), SIMDE_FLOAT64_C(    -0.53) } },
    { { SIMDE_FLOAT64_C(   252.97), SIMDE_FLOAT64_C(  -202.67) },
      { SIMDE_FLOAT64_C(     0.97), SIMDE_FLOAT64_C(    -0.67) } },
    { { SIMDE_FLOAT64_C(   265.30), SIMDE_FLOAT64_C(   854.12) },
      { SIMDE_FLOAT64_C(     0.30), SIMDE_FLOAT64_C(     0.12) } },
    { { SIMDE_FLOAT64_C(   222.08), SIMDE_FLOAT64_C(   378.34) },
      { SIMDE_FLOAT64_C(     0.08), SIMDE_FLOAT64_C(     0.34) } },
    { { SIMDE_FLOAT64_C(  -860.59), SIMDE_FLOAT64_C(   134.25) },
      { SIMDE_FLOAT64_C(    -0.59), SIMDE_FLOAT64_C(     0.25) } },
    { { SIMDE_FLOAT64_C(  -587.76), SIMDE_FLOAT64_C(  -499.31) },
      { SIMDE_FLOAT64_C(    -0.76), SIMDE_FLOAT64_C(    -0.31) } },
    { { SIMDE_FLOAT64_C(   337.99), SIMDE_FLOAT64_C(   907.90) },
      { SIMDE_FLOAT64_C(     0.99), SIMDE_FLOAT64_C(     0.90) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d r = simde_mm_frcz_pd(a);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_frcz_pd(a);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_frcz_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   905.27),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -960.75) },
      { SIMDE_FLOAT32_C(   948.61),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -509.69) },
      { SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(   905.27),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -960.75) } },
    #endif
    { { SIMDE_FLOAT32_C(  -447.80), SIMDE_FLOAT32_C(   686.39), SIMDE_FLOAT32_C(  -727.16), SIMDE_FLOAT32_C(   702.02) },
      { SIMDE_FLOAT32_C(   382.92), SIMDE_FLOAT32_C(  -167.09), SIMDE_FLOAT32_C(  -187.72), SIMDE_FLOAT32_C(   463.24) },
      { SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(   686.39), SIMDE_FLOAT32_C(  -727.16), SIMDE_FLOAT32_C(   702.02) } },
    { { SIMDE_FLOAT32_C(  -988.16), SIMDE_FLOAT32_C(    55.76), SIMDE_FLOAT32_C(  -728.63), SIMDE_FLOAT32_C(   331.46) },
      { SIMDE_FLOAT32_C(   783.44), SIMDE_FLOAT32_C(   272.32), SIMDE_FLOAT32_C(  -952.27), SIMDE_FLOAT32_C(   666.01) },
      { SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    55.76), SIMDE_FLOAT32_C(  -728.63), SIMDE_FLOAT32_C(   331.46) } },
    { { SIMDE_FLOAT32_C(   -35.49), SIMDE_FLOAT32_C(   647.51), SIMDE_FLOAT32_C(   748.77), SIMDE_FLOAT32_C(  -662.83) },
      { SIMDE_FLOAT32_C(  -133.03), SIMDE_FLOAT32_C(  -522.75), SIMDE_FLOAT32_C(  -207.62), SIMDE_FLOAT32_C(   173.86) },
      { SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(   647.51), SIMDE_FLOAT32_C(   748.77), SIMDE_FLOAT32_C(  -662.83) } },
    { { SIMDE_FLOAT32_C(  -244.91), SIMDE_FLOAT32_C(  -284.10), SIMDE_FLOAT32_C(    74.56), SIMDE_FLOAT32_C(   211.89) },
      { SIMDE_FLOAT32_C(  -649.34), SIMDE_FLOAT32_C(   710.75), SIMDE_FLOAT32_C(  -984.68), SIMDE_FLOAT32_C(  -194.62) },
      { SIMDE_FLOAT32_C(    -0.34), SIMDE_FLOAT32_C(  -284.10), SIMDE_FLOAT32_C(    74.56), SIMDE_FLOAT32_C(   211.89) } },
    { { SIMDE_FLOAT32_C(   748.28), SIMDE_FLOAT32_C(  -293.86), SIMDE_FLOAT32_C(  -703.67), SIMDE_FLOAT32_C(   664.42) },
      { SIMDE_FLOAT32_C(   553.33), SIMDE_FLOAT32_C(   680.04), SIMDE_FLOAT32_C(   602.34), SIMDE_FLOAT32_C(  -119.66) },
      { SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(  -293.86), SIMDE_FLOAT32_C(  -703.67), SIMDE_FLOAT32_C(   664.42) } },
    { { SIMDE_FLOAT32_C(    55.02), SIMDE_FLOAT32_C(  -925.84), SIMDE_FLOAT32_C(  -321.21), SIMDE_FLOAT32_C(  -997.62) },
      { SIMDE_FLOAT32_C(   247.23), SIMDE_FLOAT32_C(   -17.61), SIMDE_FLOAT32_C(    19.20), SIMDE_FLOAT32_C(   227.45) },
      { SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(  -925.84), SIMDE_FLOAT32_C(  -321.21), SIMDE_FLOAT32_C(  -997.62) } },
    { { SIMDE_FLOAT32_C(  -490.77), SIMDE_FLOAT32_C(   357.46), SIMDE_FLOAT32_C(  -507.37), SIMDE_FLOAT32_C(   765.25) },
      { SIMDE_FLOAT32_C(   759.58), SIMDE_FLOAT32_C(   800.53), SIMDE_FLOAT32_C(  -773.67), SIMDE_FLOAT32_C(  -557.60) },
      { SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(   357.46), SIMDE_FLOAT32_C(  -507.37), SIMDE_FLOAT32_C(   765.25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_frcz_ss(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_frcz_ss(a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_frcz_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -505.11) },
      { SIMDE_FLOAT64_C(    53.80),             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(     0.80), SIMDE_FLOAT64_C(  -505.11) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -152.81) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -604.42) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -152.81) } },
    #endif
    { { SIMDE_FLOAT64_C(  -580.37), SIMDE_FLOAT64_C(   397.44) },
      { SIMDE_FLOAT64_C(    12.30), SIMDE_FLOAT64_C(  -571.64) },
      { SIMDE_FLOAT64_C(     0.30), SIMDE_FLOAT64_C(   397.44) } },
    { { SIMDE_FLOAT64_C(  -317.73), SIMDE_FLOAT64_C(   561.51) },
      { SIMDE_FLOAT64_C(   558.76), SIMDE_FLOAT64_C(   989.68) },
      { SIMDE_FLOAT64_C(     0.76), SIMDE_FLOAT64_C(   561.51) } },
    { { SIMDE_FLOAT64_C(   447.19), SIMDE_FLOAT64_C(   768.18) },
      { SIMDE_FLOAT64_C(  -108.37), SIMDE_FLOAT64_C(   761.16) },
      { SIMDE_FLOAT64_C(    -0.37), SIMDE_FLOAT64_C(   768.18) } },
    { { SIMDE_FLOAT64_C(   935.85), SIMDE_FLOAT64_C(   553.27) },
      { SIMDE_FLOAT64_C(   803.16), SIMDE_FLOAT64_C(  -832.27) },
      { SIMDE_FLOAT64_C(     0.16), SIMDE_FLOAT64_C(   553.27) } },
    { { SIMDE_FLOAT64_C(   468.06), SIMDE_FLOAT64_C(  -827.20) },
      { SIMDE_FLOAT64_C(   877.56), SIMDE_FLOAT64_C(   399.46) },
      { SIMDE_FLOAT64_C(     0.56), SIMDE_FLOAT64_C(  -827.20) } },
    { { SIMDE_FLOAT64_C(   647.08), SIMDE_FLOAT64_C(   298.93) },
      { SIMDE_FLOAT64_C(   654.10), SIMDE_FLOAT64_C(  -828.97) },
      { SIMDE_FLOAT64_C(     0.10), SIMDE_FLOAT64_C(   298.93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_frcz_sd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_frcz_sd(a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_frcz_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -670.89), SIMDE_FLOAT32_C(  -640.19), SIMDE_FLOAT32_C(  -142.80), SIMDE_FLOAT32_C(  -716.79),
        SIMDE_FLOAT32_C(  -808.65), SIMDE_FLOAT32_C(  -913.21), SIMDE_FLOAT32_C(  -995.30), SIMDE_FLOAT32_C(    46.54) },
      { SIMDE_FLOAT32_C(    -0.89), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(    -0.79),
        SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(     0.54) } },
    { { SIMDE_FLOAT32_C(   709.52), SIMDE_FLOAT32_C(  -168.92), SIMDE_FLOAT32_C(   708.30), SIMDE_FLOAT32_C(  -368.88),
        SIMDE_FLOAT32_C(   358.26), SIMDE_FLOAT32_C(   212.20), SIMDE_FLOAT32_C(   -23.04), SIMDE_FLOAT32_C(  -594.96) },
      { SIMDE_FLOAT32_C(     0.52), SIMDE_FLOAT32_C(    -0.92), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.88),
        SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     0.20), SIMDE_FLOAT32_C(    -0.04), SIMDE_FLOAT32_C(    -0.96) } },
    { { SIMDE_FLOAT32_C(  -152.93), SIMDE_FLOAT32_C(   661.67), SIMDE_FLOAT32_C(  -162.02), SIMDE_FLOAT32_C(   323.10),
        SIMDE_FLOAT32_C(  -796.75), SIMDE_FLOAT32_C(  -577.32), SIMDE_FLOAT32_C(  -414.41), SIMDE_FLOAT32_C(  -571.15) },
      { SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(     0.10),
        SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(    -0.15) } },
    { { SIMDE_FLOAT32_C(  -484.73), SIMDE_FLOAT32_C(  -429.49), SIMDE_FLOAT32_C(   -27.86), SIMDE_FLOAT32_C(  -466.84),
        SIMDE_FLOAT32_C(   149.21), SIMDE_FLOAT32_C(   613.76), SIMDE_FLOAT32_C(   652.27), SIMDE_FLOAT32_C(   129.73) },
      { SIMDE_FLOAT32_C(    -0.73), SIMDE_FLOAT32_C(    -0.49), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.84),
        SIMDE_FLOAT32_C(     0.21), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(     0.73) } },
    { { SIMDE_FLOAT32_C(   249.43), SIMDE_FLOAT32_C(  -759.09), SIMDE_FLOAT32_C(   194.25), SIMDE_FLOAT32_C(   612.66),
        SIMDE_FLOAT32_C(  -662.04), SIMDE_FLOAT32_C(   773.80), SIMDE_FLOAT32_C(   -30.49), SIMDE_FLOAT32_C(  -143.59) },
      { SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(     0.66),
        SIMDE_FLOAT32_C(    -0.04), SIMDE_FLOAT32_C(     0.80), SIMDE_FLOAT32_C(    -0.49), SIMDE_FLOAT32_C(    -0.59) } },
    { { SIMDE_FLOAT32_C(   823.36), SIMDE_FLOAT32_C(  -109.71), SIMDE_FLOAT32_C(   234.41), SIMDE_FLOAT32_C(  -777.64),
        SIMDE_FLOAT32_C(  -767.94), SIMDE_FLOAT32_C(   179.54), SIMDE_FLOAT32_C(  -285.07), SIMDE_FLOAT32_C(  -947.33) },
      { SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(     0.41), SIMDE_FLOAT32_C(    -0.64),
        SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(     0.54), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(    -0.33) } },
    { { SIMDE_FLOAT32_C(   975.95), SIMDE_FLOAT32_C(  -909.05), SIMDE_FLOAT32_C(  -991.33), SIMDE_FLOAT32_C(  -284.04),
        SIMDE_FLOAT32_C(  -533.98), SIMDE_FLOAT32_C(  -158.67), SIMDE_FLOAT32_C(  -884.82), SIMDE_FLOAT32_C(  -734.86) },
      { SIMDE_FLOAT32_C(     0.95), SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(    -0.04),
        SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(    -0.67), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(    -0.86) } },
    { { SIMDE_FLOAT32_C(   387.80), SIMDE_FLOAT32_C(   840.27), SIMDE_FLOAT32_C(  -592.09), SIMDE_FLOAT32_C(   772.45),
        SIMDE_FLOAT32_C(   -51.97), SIMDE_FLOAT32_C(   198.58), SIMDE_FLOAT32_C(   360.09), SIMDE_FLOAT32_C(  -598.99) },
      { SIMDE_FLOAT32_C(     0.80), SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(     0.45),
        SIMDE_FLOAT32_C(    -0.97), SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(    -0.99) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_frcz_ps(a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_frcz_ps(a);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_frcz_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -92.32), SIMDE_FLOAT64_C(  -119.17), SIMDE_FLOAT64_C(  -663.14), SIMDE_FLOAT64_C(   279.09) },
      { SIMDE_FLOAT64_C(    -0.32), SIMDE_FLOAT64_C(    -0.17), SIMDE_FLOAT64_C(    -0.14), SIMDE_FLOAT64_C(     0.09) } },
    { { SIMDE_FLOAT64_C(   211.65), SIMDE_FLOAT64_C(  -935.18), SIMDE_FLOAT64_C(   766.59), SIMDE_FLOAT64_C(  -764.15) },
      { SIMDE_FLOAT64_C(     0.65), SIMDE_FLOAT64_C(    -0.18), SIMDE_FLOAT64_C(     0.59), SIMDE_FLOAT64_C(    -0.15) } },
    { { SIMDE_FLOAT64_C(  -970.76), SIMDE_FLOAT64_C(  -729.00), SIMDE_FLOAT64_C(  -996.77), SIMDE_FLOAT64_C(  -535.75) },
      { SIMDE_FLOAT64_C(    -0.76), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.77), SIMDE_FLOAT64_C(    -0.75) } },
    { { SIMDE_FLOAT64_C(  -982.91), SIMDE_FLOAT64_C(   823.36), SIMDE_FLOAT64_C(  -807.06), SIMDE_FLOAT64_C(   171.42) },
      { SIMDE_FLOAT64_C(    -0.91), SIMDE_FLOAT64_C(     0.36), SIMDE_FLOAT64_C(    -0.06), SIMDE_FLOAT64_C(     0.42) } },
    { { SIMDE_FLOAT64_C(  -382.67), SIMDE_FLOAT64_C(  -794.85), SIMDE_FLOAT64_C(   456.89), SIMDE_FLOAT64_C(   280.19) },
      { SIMDE_FLOAT64_C(    -0.67), SIMDE_FLOAT64_C(    -0.85), SIMDE_FLOAT64_C(     0.89), SIMDE_FLOAT64_C(     0.19) } },
    { { SIMDE_FLOAT64_C(   203.16), SIMDE_FLOAT64_C(   872.13), SIMDE_FLOAT64_C(   702.87), SIMDE_FLOAT64_C(  -756.46) },
      { SIMDE_FLOAT64_C(     0.16), SIMDE_FLOAT64_C(     0.13), SIMDE_FLOAT64_C(     0.87), SIMDE_FLOAT64_C(    -0.46) } },
    { { SIMDE_FLOAT64_C(  -115.21), SIMDE_FLOAT64_C(  -916.01), SIMDE_FLOAT64_C(  -621.39), SIMDE_FLOAT64_C(    35.68) },
      { SIMDE_FLOAT64_C(    -0.21), SIMDE_FLOAT64_C(    -0.01), SIMDE_FLOAT64_C(    -0.39), SIMDE_FLOAT64_C(     0.68) } },
    { { SIMDE_FLOAT64_C(   788.26), SIMDE_FLOAT64_C(  -680.53), SIMDE_FLOAT64_C(  -520.92), SIMDE_FLOAT64_C(   379.99) },
      { SIMDE_FLOAT64_C(     0.26), SIMDE_FLOAT64_C(    -0.53), SIMDE_FLOAT64_C(    -0.92), SIMDE_FLOAT64_C(     0.99) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_frcz_pd(a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_frcz_pd(a);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddw_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT8_C( 101),  INT8_C( 107), -INT8_C(  89), -INT8_C(  33), -INT8_C(  91),  INT8_C( 120),  INT8_C(  62),  INT8_C(  29),
         INT8_C(  25), -INT8_C(  49),  INT8_C(  91), -INT8_C(  98),  INT8_C(  80),  INT8_C(  56),  INT8_C(  56), -INT8_C(   1) },
      {  INT16_C(     6), -INT16_C(   122),  INT16_C(    29),  INT16_C(    91), -INT16_C(    24), -INT16_C(     7),  INT16_C(   136),  INT16_C(    55) } },
    { { -INT8_C( 122), -INT8_C(  52),  INT8_C(  24), -INT8_C(  56),  INT8_C(  48), -INT8_C(   3),  INT8_C(  55), -INT8_C( 108),
        -INT8_C( 113), -INT8_C(  41),  INT8_C(   1),  INT8_C( 114), -INT8_C( 122), -INT8_C( 122), -INT8_C( 126), -INT8_C( 118) },
      { -INT16_C(   174), -INT16_C(    32),  INT16_C(    45), -INT16_C(    53), -INT16_C(   154),  INT16_C(   115), -INT16_C(   244), -INT16_C(   244) } },
    { { -INT8_C(  87),  INT8_C(  23),  INT8_C(  30),  INT8_C(   4), -INT8_C( 106), -INT8_C( 125), -INT8_C( 126),  INT8_C(  37),
        -INT8_C( 120), -INT8_C(  23), -INT8_C(  38), -INT8_C(  69),  INT8_C(  41),  INT8_C(  27),  INT8_C(  68), -INT8_C(  68) },
      { -INT16_C(    64),  INT16_C(    34), -INT16_C(   231), -INT16_C(    89), -INT16_C(   143), -INT16_C(   107),  INT16_C(    68),  INT16_C(     0) } },
    { { -INT8_C(  88),  INT8_C(  92), -INT8_C( 123),  INT8_C(  42),  INT8_C(  12),  INT8_C( 104), -INT8_C(   4),  INT8_C(  57),
        -INT8_C(  56), -INT8_C(  75), -INT8_C(  44), -INT8_C(  76), -INT8_C( 113), -INT8_C(   7),  INT8_C( 125), -INT8_C(  99) },
      {  INT16_C(     4), -INT16_C(    81),  INT16_C(   116),  INT16_C(    53), -INT16_C(   131), -INT16_C(   120), -INT16_C(   120),  INT16_C(    26) } },
    { {  INT8_C( 105), -INT8_C(  20),  INT8_C(  92),  INT8_C(  20),  INT8_C(   7),  INT8_C(  79), -INT8_C(  63),  INT8_C( 121),
         INT8_C(  83),  INT8_C(  45),  INT8_C(  26), -INT8_C(  43),  INT8_C(  76),  INT8_C(  97),  INT8_C( 103),  INT8_C( 118) },
      {  INT16_C(    85),  INT16_C(   112),  INT16_C(    86),  INT16_C(    58),  INT16_C(   128), -INT16_C(    17),  INT16_C(   173),  INT16_C(   221) } },
    { {  INT8_C(  17),  INT8_C(  88), -INT8_C(  18), -INT8_C(  38),  INT8_C(  59),  INT8_C(  24),  INT8_C(  48), -INT8_C(  49),
         INT8_C( 112), -INT8_C( 127),  INT8_C(  27), -INT8_C(  41),  INT8_C(  54), -INT8_C(  45), -INT8_C( 127), -INT8_C(  47) },
      {  INT16_C(   105), -INT16_C(    56),  INT16_C(    83), -INT16_C(     1), -INT16_C(    15), -INT16_C(    14),  INT16_C(     9), -INT16_C(   174) } },
    { {  INT8_C(   4),  INT8_C( 113), -INT8_C(  55), -INT8_C(  42), -INT8_C(  97), -INT8_C(  27), -INT8_C(  27),  INT8_C(  98),
        -INT8_C(  92),  INT8_C(  35), -INT8_C( 124), -INT8_C(  76),  INT8_C(  96),  INT8_C(  18), -INT8_C( 120),  INT8_C( 119) },
      {  INT16_C(   117), -INT16_C(    97), -INT16_C(   124),  INT16_C(    71), -INT16_C(    57), -INT16_C(   200),  INT16_C(   114), -INT16_C(     1) } },
    { { -INT8_C(  24),  INT8_C(  72), -INT8_C(  70), -INT8_C(  95),  INT8_C( 102),  INT8_C(  21), -INT8_C(  68), -INT8_C( 100),
        -INT8_C(  78), -INT8_C(  60),  INT8_C(  64), -INT8_C(  92),  INT8_C(  34),  INT8_C(  29),  INT8_C( 120),  INT8_C( 112) },
      {  INT16_C(    48), -INT16_C(   165),  INT16_C(   123), -INT16_C(   168), -INT16_C(   138), -INT16_C(    28),  INT16_C(    63),  INT16_C(   232) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_haddw_epi8(a);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_haddw_epi8(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddw_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C(162), UINT8_C( 47), UINT8_C(205), UINT8_C( 20), UINT8_C(  7), UINT8_C( 76), UINT8_C(212), UINT8_C( 38),
        UINT8_C(160), UINT8_C( 84), UINT8_C(126), UINT8_C( 31), UINT8_C( 14), UINT8_C( 55), UINT8_C(143), UINT8_C(  5) },
      { UINT16_C(  209), UINT16_C(  225), UINT16_C(   83), UINT16_C(  250), UINT16_C(  244), UINT16_C(  157), UINT16_C(   69), UINT16_C(  148) } },
    { { UINT8_C( 86), UINT8_C(181), UINT8_C( 81), UINT8_C( 71), UINT8_C( 53), UINT8_C(104), UINT8_C(137), UINT8_C(233),
        UINT8_C(180), UINT8_C(  5), UINT8_C(170), UINT8_C(224), UINT8_C(251), UINT8_C(223), UINT8_C( 73), UINT8_C(192) },
      { UINT16_C(  267), UINT16_C(  152), UINT16_C(  157), UINT16_C(  370), UINT16_C(  185), UINT16_C(  394), UINT16_C(  474), UINT16_C(  265) } },
    { { UINT8_C(106), UINT8_C(172), UINT8_C(209), UINT8_C(148), UINT8_C(230), UINT8_C(140), UINT8_C(120), UINT8_C( 13),
        UINT8_C(113), UINT8_C( 71), UINT8_C(113), UINT8_C(224), UINT8_C(254), UINT8_C(214), UINT8_C( 99), UINT8_C(105) },
      { UINT16_C(  278), UINT16_C(  357), UINT16_C(  370), UINT16_C(  133), UINT16_C(  184), UINT16_C(  337), UINT16_C(  468), UINT16_C(  204) } },
    { { UINT8_C(131), UINT8_C( 38), UINT8_C( 27), UINT8_C(148), UINT8_C( 79), UINT8_C( 24), UINT8_C(126), UINT8_C(253),
        UINT8_C(158), UINT8_C(204), UINT8_C(193), UINT8_C( 86), UINT8_C(107), UINT8_C( 31), UINT8_C(220), UINT8_C( 10) },
      { UINT16_C(  169), UINT16_C(  175), UINT16_C(  103), UINT16_C(  379), UINT16_C(  362), UINT16_C(  279), UINT16_C(  138), UINT16_C(  230) } },
    { { UINT8_C(133), UINT8_C(114), UINT8_C( 59), UINT8_C( 31), UINT8_C(229), UINT8_C(174), UINT8_C(183), UINT8_C( 97),
        UINT8_C( 63), UINT8_C(132), UINT8_C(198), UINT8_C(189), UINT8_C(215), UINT8_C(250), UINT8_C(238), UINT8_C(235) },
      { UINT16_C(  247), UINT16_C(   90), UINT16_C(  403), UINT16_C(  280), UINT16_C(  195), UINT16_C(  387), UINT16_C(  465), UINT16_C(  473) } },
    { { UINT8_C(150), UINT8_C( 35), UINT8_C(128), UINT8_C( 80), UINT8_C( 93), UINT8_C( 45), UINT8_C(130), UINT8_C( 34),
        UINT8_C(153), UINT8_C(162), UINT8_C(237), UINT8_C(205), UINT8_C( 24), UINT8_C(231), UINT8_C( 25), UINT8_C(149) },
      { UINT16_C(  185), UINT16_C(  208), UINT16_C(  138), UINT16_C(  164), UINT16_C(  315), UINT16_C(  442), UINT16_C(  255), UINT16_C(  174) } },
    { { UINT8_C( 27), UINT8_C(  9), UINT8_C(117), UINT8_C(125), UINT8_C(172), UINT8_C(184), UINT8_C(123), UINT8_C(104),
        UINT8_C( 49), UINT8_C(148), UINT8_C(227), UINT8_C(127), UINT8_C( 66), UINT8_C(168), UINT8_C( 23), UINT8_C(210) },
      { UINT16_C(   36), UINT16_C(  242), UINT16_C(  356), UINT16_C(  227), UINT16_C(  197), UINT16_C(  354), UINT16_C(  234), UINT16_C(  233) } },
    { { UINT8_C(184), UINT8_C( 52), UINT8_C(232), UINT8_C( 66), UINT8_C(  6), UINT8_C(176), UINT8_C(127), UINT8_C(158),
        UINT8_C(205), UINT8_C( 13), UINT8_C(150), UINT8_C( 12), UINT8_C(170), UINT8_C( 62), UINT8_C(232), UINT8_C(171) },
      { UINT16_C(  236), UINT16_C(  298), UINT16_C(  182), UINT16_C(  285), UINT16_C(  218), UINT16_C(  162), UINT16_C(  232), UINT16_C(  403) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_haddw_epu8(a);
    simde_test_x86_assert_equal_u16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_haddw_epu8(a);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddd_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT8_C(  83), -INT8_C(   9), -INT8_C(  27),  INT8_C( 118), -INT8_C(  30), -INT8_C(  75), -INT8_C(  85),  INT8_C( 108),
         INT8_C( 112), -INT8_C(   2),  INT8_C(  50), -INT8_C(  18), -INT8_C(  26), -INT8_C(  22), -INT8_C(  58),  INT8_C( 104) },
      {  INT32_C(         165), -INT32_C(          82),  INT32_C(         142), -INT32_C(           2) } },
    { {  INT8_C(  16), -INT8_C(  30), -INT8_C(  69),  INT8_C(  51), -INT8_C(  13), -INT8_C(  88),  INT8_C(  92), -INT8_C(  70),
         INT8_C(  97), -INT8_C( 105),  INT8_C(  36), -INT8_C(  36), -INT8_C(  54),  INT8_C(  45),  INT8_C(  49), -INT8_C( 110) },
      { -INT32_C(          32), -INT32_C(          79), -INT32_C(           8), -INT32_C(          70) } },
    { {  INT8_C(  85), -INT8_C(  58), -INT8_C(  11), -INT8_C(  46),  INT8_C(  47), -INT8_C(  86),  INT8_C(  47), -INT8_C(  77),
         INT8_C(  35),  INT8_C(  74),  INT8_C(  25), -INT8_C(  47),  INT8_C( 108), -INT8_C(  57), -INT8_C(  29), -INT8_C(  13) },
      { -INT32_C(          30), -INT32_C(          69),  INT32_C(          87),  INT32_C(           9) } },
    { { -INT8_C(  57), -INT8_C(  76),  INT8_C(  97), -INT8_C(  21), -INT8_C(  52),  INT8_C(  29),  INT8_C(   1), -INT8_C(  66),
         INT8_C( 125), -INT8_C(  56), -INT8_C(   1),  INT8_C(   5),  INT8_C(  32), -INT8_C(  70), -INT8_C(  36), -INT8_C( 109) },
      { -INT32_C(          57), -INT32_C(          88),  INT32_C(          73), -INT32_C(         183) } },
    { {  INT8_C(  74), -INT8_C(   3),  INT8_C(  12),  INT8_C(  88),  INT8_C(  61), -INT8_C(  95), -INT8_C(  17), -INT8_C( 123),
         INT8_C( 115),  INT8_C(   1),  INT8_C(   2), -INT8_C(  15),  INT8_C( 123),  INT8_C(  72),  INT8_C(  87), -INT8_C(  68) },
      {  INT32_C(         171), -INT32_C(         174),  INT32_C(         103),  INT32_C(         214) } },
    { {  INT8_C(   4),  INT8_C(  51),  INT8_C(  66),  INT8_C(  50),  INT8_C(  56),  INT8_C(  24),  INT8_C(  86), -INT8_C(  14),
         INT8_C(  75),  INT8_C(  39), -INT8_C( 113),  INT8_C(  79),  INT8_C(  83), -INT8_C(  16), -INT8_C(  47), -INT8_C(  10) },
      {  INT32_C(         171),  INT32_C(         152),  INT32_C(          80),  INT32_C(          10) } },
    { {  INT8_C(  90),  INT8_C(  37), -INT8_C( 111), -INT8_C(  47), -INT8_C(  79), -INT8_C(  95), -INT8_C(  46),  INT8_C(  44),
        -INT8_C( 120), -INT8_C(  86),  INT8_C(  84),  INT8_C(  23), -INT8_C(  68),  INT8_C( 115),  INT8_C(   8),  INT8_C(  11) },
      { -INT32_C(          31), -INT32_C(         176), -INT32_C(          99),  INT32_C(          66) } },
    { { -INT8_C(  16), -INT8_C(  27), -INT8_C(  58), -INT8_C(  48), -INT8_C(  33), -INT8_C(  97),  INT8_C(  66), -INT8_C(  99),
        -INT8_C(  16),  INT8_C(  60),  INT8_C(  61), -INT8_C( 126),  INT8_C(  12), -INT8_C(  44), -INT8_C(   8),  INT8_C(   3) },
      { -INT32_C(         149), -INT32_C(         163), -INT32_C(          21), -INT32_C(          37) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_haddd_epi8(a);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_haddd_epi8(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT16_C( 14932),  INT16_C(  1774), -INT16_C( 19658), -INT16_C(  4158), -INT16_C( 12919),  INT16_C(  2423),  INT16_C( 21206),  INT16_C( 10463) },
      { -INT32_C(       13158), -INT32_C(       23816), -INT32_C(       10496),  INT32_C(       31669) } },
    { {  INT16_C( 21683), -INT16_C( 29610), -INT16_C( 17046),  INT16_C(  2480), -INT16_C( 28777),  INT16_C( 25967),  INT16_C( 28914),  INT16_C(   569) },
      { -INT32_C(        7927), -INT32_C(       14566), -INT32_C(        2810),  INT32_C(       29483) } },
    { {  INT16_C( 25961), -INT16_C( 17270), -INT16_C(  8590),  INT16_C(  5543), -INT16_C(  3169), -INT16_C( 28461), -INT16_C(  4750),  INT16_C( 23236) },
      {  INT32_C(        8691), -INT32_C(        3047), -INT32_C(       31630),  INT32_C(       18486) } },
    { {  INT16_C(  2164),  INT16_C( 12120),  INT16_C( 30593),  INT16_C( 31877), -INT16_C( 22170), -INT16_C( 15986), -INT16_C( 13394),  INT16_C( 14973) },
      {  INT32_C(       14284),  INT32_C(       62470), -INT32_C(       38156),  INT32_C(        1579) } },
    { { -INT16_C( 29000), -INT16_C( 16691),  INT16_C( 10765), -INT16_C(  6297), -INT16_C( 23567),  INT16_C( 29648),  INT16_C( 19000), -INT16_C(  5472) },
      { -INT32_C(       45691),  INT32_C(        4468),  INT32_C(        6081),  INT32_C(       13528) } },
    { { -INT16_C( 30629), -INT16_C( 32458), -INT16_C( 10293),  INT16_C( 16298),  INT16_C(  4485),  INT16_C( 24067), -INT16_C(  4633), -INT16_C(  2902) },
      { -INT32_C(       63087),  INT32_C(        6005),  INT32_C(       28552), -INT32_C(        7535) } },
    { { -INT16_C( 14654), -INT16_C( 11489), -INT16_C( 24656), -INT16_C( 21013),  INT16_C( 26024),  INT16_C( 31958),  INT16_C( 29647),  INT16_C(  8281) },
      { -INT32_C(       26143), -INT32_C(       45669),  INT32_C(       57982),  INT32_C(       37928) } },
    { {  INT16_C( 23697),  INT16_C( 19030), -INT16_C(  6927), -INT16_C( 26105),  INT16_C( 20253),  INT16_C(  1077), -INT16_C(  8378),  INT16_C( 30890) },
      {  INT32_C(       42727), -INT32_C(       33032),  INT32_C(       21330),  INT32_C(       22512) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_haddd_epi16(a);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_haddd_epi16(a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddd_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT8_C(174), UINT8_C(152), UINT8_C(232), UINT8_C(194), UINT8_C(  3), UINT8_C( 70), UINT8_C( 27), UINT8_C(175),
        UINT8_C(235), UINT8_C(193), UINT8_C( 77), UINT8_C(113), UINT8_C(224), UINT8_C(112), UINT8_C(217), UINT8_C( 68) },
      { UINT32_C(       752), UINT32_C(       275), UINT32_C(       618), UINT32_C(       621) } },
    { { UINT8_C( 62), UINT8_C( 12), UINT8_C( 34), UINT8_C( 82), UINT8_C(154), UINT8_C(166), UINT8_C(132), UINT8_C(212),
        UINT8_C( 86), UINT8_C(236), UINT8_C(139), UINT8_C(123), UINT8_C(114), UINT8_C(168), UINT8_C( 99), UINT8_C( 14) },
      { UINT32_C(       190), UINT32_C(       664), UINT32_C(       584), UINT32_C(       395) } },
    { { UINT8_C(165), UINT8_C(137), UINT8_C(144), UINT8_C( 84), UINT8_C(173), UINT8_C( 38), UINT8_C(223), UINT8_C( 52),
        UINT8_C(227), UINT8_C( 64), UINT8_C(157), UINT8_C( 27), UINT8_C( 18), UINT8_C( 71), UINT8_C(  6), UINT8_C(158) },
      { UINT32_C(       530), UINT32_C(       486), UINT32_C(       475), UINT32_C(       253) } },
    { { UINT8_C(137), UINT8_C( 32), UINT8_C(  0), UINT8_C( 97), UINT8_C(111), UINT8_C( 38), UINT8_C( 10), UINT8_C( 55),
        UINT8_C( 87), UINT8_C(111), UINT8_C(111), UINT8_C(138), UINT8_C( 20), UINT8_C( 80), UINT8_C(191), UINT8_C(254) },
      { UINT32_C(       266), UINT32_C(       214), UINT32_C(       447), UINT32_C(       545) } },
    { { UINT8_C(207), UINT8_C( 35), UINT8_C(127), UINT8_C( 81), UINT8_C( 87), UINT8_C( 71), UINT8_C( 32), UINT8_C(134),
        UINT8_C(183), UINT8_C(105), UINT8_C( 46), UINT8_C( 66), UINT8_C( 14), UINT8_C(  2), UINT8_C(202), UINT8_C(118) },
      { UINT32_C(       450), UINT32_C(       324), UINT32_C(       400), UINT32_C(       336) } },
    { { UINT8_C(155), UINT8_C( 33), UINT8_C( 90), UINT8_C( 62), UINT8_C( 24), UINT8_C(107), UINT8_C(127), UINT8_C(  9),
        UINT8_C( 73), UINT8_C( 96), UINT8_C( 72), UINT8_C(251), UINT8_C(212), UINT8_C(224), UINT8_C(165), UINT8_C(143) },
      { UINT32_C(       340), UINT32_C(       267), UINT32_C(       492), UINT32_C(       744) } },
    { { UINT8_C( 83), UINT8_C(237), UINT8_C( 30), UINT8_C(129), UINT8_C(168), UINT8_C(178), UINT8_C(196), UINT8_C(235),
        UINT8_C(144), UINT8_C(196), UINT8_C(104), UINT8_C(174), UINT8_C(124), UINT8_C(169), UINT8_C( 12), UINT8_C( 19) },
      { UINT32_C(       479), UINT32_C(       777), UINT32_C(       618), UINT32_C(       324) } },
    { { UINT8_C(156), UINT8_C(151), UINT8_C(151), UINT8_C(178), UINT8_C( 60), UINT8_C(125), UINT8_C(205), UINT8_C(147),
        UINT8_C( 83), UINT8_C( 72), UINT8_C(125), UINT8_C(148), UINT8_C( 89), UINT8_C( 95), UINT8_C(252), UINT8_C( 10) },
      { UINT32_C(       636), UINT32_C(       537), UINT32_C(       428), UINT32_C(       446) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_haddd_epu8(a);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_haddd_epu8(a);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddd_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(28506), UINT16_C(43987), UINT16_C(28233), UINT16_C(44213), UINT16_C(55958), UINT16_C( 9908), UINT16_C(16898), UINT16_C(48820) },
      { UINT32_C(     72493), UINT32_C(     72446), UINT32_C(     65866), UINT32_C(     65718) } },
    { { UINT16_C( 2227), UINT16_C(34079), UINT16_C(25987), UINT16_C( 7642), UINT16_C(44446), UINT16_C( 7800), UINT16_C(54604), UINT16_C(47022) },
      { UINT32_C(     36306), UINT32_C(     33629), UINT32_C(     52246), UINT32_C(    101626) } },
    { { UINT16_C(12811), UINT16_C(39175), UINT16_C(33761), UINT16_C( 4313), UINT16_C(13040), UINT16_C(29560), UINT16_C(55115), UINT16_C(49065) },
      { UINT32_C(     51986), UINT32_C(     38074), UINT32_C(     42600), UINT32_C(    104180) } },
    { { UINT16_C(65032), UINT16_C(32602), UINT16_C(10903), UINT16_C(61328), UINT16_C( 6738), UINT16_C(24736), UINT16_C(19028), UINT16_C(56994) },
      { UINT32_C(     97634), UINT32_C(     72231), UINT32_C(     31474), UINT32_C(     76022) } },
    { { UINT16_C(48527), UINT16_C( 4387), UINT16_C(64025), UINT16_C(24858), UINT16_C(21959), UINT16_C(23837), UINT16_C(28669), UINT16_C(24277) },
      { UINT32_C(     52914), UINT32_C(     88883), UINT32_C(     45796), UINT32_C(     52946) } },
    { { UINT16_C(  196), UINT16_C(26544), UINT16_C(54301), UINT16_C(20693), UINT16_C( 5270), UINT16_C( 9309), UINT16_C(50970), UINT16_C(51136) },
      { UINT32_C(     26740), UINT32_C(     74994), UINT32_C(     14579), UINT32_C(    102106) } },
    { { UINT16_C(38925), UINT16_C(56461), UINT16_C(55961), UINT16_C(58719), UINT16_C(51522), UINT16_C(44044), UINT16_C( 5057), UINT16_C(58143) },
      { UINT32_C(     95386), UINT32_C(    114680), UINT32_C(     95566), UINT32_C(     63200) } },
    { { UINT16_C(38671), UINT16_C( 1929), UINT16_C(27840), UINT16_C(35475), UINT16_C( 9618), UINT16_C(12311), UINT16_C(21318), UINT16_C(47856) },
      { UINT32_C(     40600), UINT32_C(     63315), UINT32_C(     21929), UINT32_C(     69174) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_haddd_epu16(a);
    simde_test_x86_assert_equal_u32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_haddd_epu16(a);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddq_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT8_C(  82),  INT8_C(  76), -INT8_C(  81), -INT8_C(  62),  INT8_C(   8),  INT8_C(  43), -INT8_C( 113), -INT8_C(  26),
        -INT8_C( 118),  INT8_C(  24), -INT8_C(  84),  INT8_C(  40),  INT8_C(  62), -INT8_C(  54),  INT8_C( 111), -INT8_C( 107) },
      { -INT64_C(                 237), -INT64_C(                 126) } },
    { {  INT8_C(  16),  INT8_C(  73),  INT8_C(  77),  INT8_C(  37),  INT8_C(  38), -INT8_C(   7), -INT8_C(  79), -INT8_C(  29),
         INT8_C( 111), -INT8_C(  44),  INT8_C(  54),  INT8_C(  77),      INT8_MAX, -INT8_C(   9),  INT8_C(  26), -INT8_C(   2) },
      {  INT64_C(                 126),  INT64_C(                 340) } },
    { { -INT8_C( 102),  INT8_C(  96), -INT8_C(  16), -INT8_C( 118),  INT8_C(  14), -INT8_C(  10), -INT8_C( 108), -INT8_C(  86),
        -INT8_C(  58), -INT8_C(  55),  INT8_C( 100), -INT8_C( 103),  INT8_C(  29), -INT8_C( 100), -INT8_C(  83), -INT8_C(  67) },
      { -INT64_C(                 330), -INT64_C(                 337) } },
    { { -INT8_C(  16), -INT8_C(  95),  INT8_C( 100), -INT8_C( 118), -INT8_C(   9), -INT8_C( 125),  INT8_C(  23), -INT8_C(  92),
         INT8_C(  85), -INT8_C(  87),  INT8_C(  34),  INT8_C(  67),  INT8_C( 109), -INT8_C(  70),  INT8_C(  38), -INT8_C(  36) },
      { -INT64_C(                 332),  INT64_C(                 140) } },
    { { -INT8_C(   8),  INT8_C(  92), -INT8_C(  73), -INT8_C(   2),  INT8_C(  84),  INT8_C(  66),  INT8_C(  85),  INT8_C( 122),
         INT8_C(  31),  INT8_C( 101), -INT8_C(  98), -INT8_C(  58),  INT8_C(   5), -INT8_C( 111), -INT8_C(  63), -INT8_C(  93) },
      {  INT64_C(                 366), -INT64_C(                 286) } },
    { { -INT8_C(  42),  INT8_C(  36),  INT8_C(  54), -INT8_C(   2), -INT8_C(  36),  INT8_C(  19), -INT8_C(  83),  INT8_C(  20),
         INT8_C( 107),  INT8_C(  45),  INT8_C(  68), -INT8_C(  38), -INT8_C(  71), -INT8_C(  92), -INT8_C(   4), -INT8_C( 100) },
      { -INT64_C(                  34), -INT64_C(                  85) } },
    { { -INT8_C(  16), -INT8_C(  55),  INT8_C( 110), -INT8_C(  28), -INT8_C( 126),  INT8_C(  23), -INT8_C(  70), -INT8_C(  99),
        -INT8_C(  67),  INT8_C( 115), -INT8_C(  63),  INT8_C( 120), -INT8_C(  97), -INT8_C(  78), -INT8_C( 108), -INT8_C( 113) },
      { -INT64_C(                 261), -INT64_C(                 291) } },
    { { -INT8_C(  21),  INT8_C(  92),  INT8_C(  43),  INT8_C(  73),  INT8_C( 124), -INT8_C(  81),  INT8_C(  91),  INT8_C( 125),
        -INT8_C(  38), -INT8_C(  25),  INT8_C(   2), -INT8_C(  38),  INT8_C(  11), -INT8_C(  67), -INT8_C( 123), -INT8_C( 122) },
      {  INT64_C(                 446), -INT64_C(                 400) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_haddq_epi8(a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_haddq_epi8(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddq_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT16_C( 11948),  INT16_C(  1404),  INT16_C( 32064),  INT16_C( 23979),  INT16_C( 31687),  INT16_C( 30517),  INT16_C(  1683), -INT16_C( 14068) },
      {  INT64_C(               69395),  INT64_C(               49819) } },
    { { -INT16_C( 12201),  INT16_C( 12972),  INT16_C( 25217),  INT16_C(  9481),  INT16_C( 24777),  INT16_C(  2757),  INT16_C(  3594), -INT16_C(  7769) },
      {  INT64_C(               35469),  INT64_C(               23359) } },
    { {  INT16_C(  4945),  INT16_C( 10569),  INT16_C( 32052),  INT16_C(    16),  INT16_C(  1638), -INT16_C( 29855), -INT16_C( 27256), -INT16_C( 26606) },
      {  INT64_C(               47582), -INT64_C(               82079) } },
    { {  INT16_C(  2113), -INT16_C( 32225),  INT16_C( 12688),  INT16_C( 21919),  INT16_C(  7777),  INT16_C( 13302), -INT16_C( 24993), -INT16_C(  2229) },
      {  INT64_C(                4495), -INT64_C(                6143) } },
    { {  INT16_C(    10),  INT16_C(  5949),  INT16_C(  7689), -INT16_C( 12335), -INT16_C( 25663),  INT16_C( 31919),  INT16_C( 26662),  INT16_C( 18063) },
      {  INT64_C(                1313),  INT64_C(               50981) } },
    { { -INT16_C( 29231),  INT16_C(   494),  INT16_C(  9812),  INT16_C( 21765), -INT16_C( 21558),  INT16_C(  7675),  INT16_C( 30130),  INT16_C(  3674) },
      {  INT64_C(                2840),  INT64_C(               19921) } },
    { {  INT16_C( 32509), -INT16_C( 26176),  INT16_C( 26981),  INT16_C(  4823), -INT16_C( 15871),  INT16_C(  4486), -INT16_C( 31210),  INT16_C(  6505) },
      {  INT64_C(               38137), -INT64_C(               36090) } },
    { { -INT16_C(  6607),  INT16_C( 30591),  INT16_C( 18546),  INT16_C( 27939), -INT16_C( 28885), -INT16_C( 28610), -INT16_C( 25430),  INT16_C( 28602) },
      {  INT64_C(               70469), -INT64_C(               54323) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_haddq_epi16(a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_haddq_epi16(a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddq_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1966740562),  INT32_C(   285762801),  INT32_C(   323879757),  INT32_C(  1519056640) },
      {  INT64_C(          2252503363),  INT64_C(          1842936397) } },
    { { -INT32_C(  1405314170), -INT32_C(   438198379),  INT32_C(  1411731628),  INT32_C(  1649744623) },
      { -INT64_C(          1843512549),  INT64_C(          3061476251) } },
    { {  INT32_C(  1947421490),  INT32_C(   323819860),  INT32_C(  1265690574),  INT32_C(  1356383371) },
      {  INT64_C(          2271241350),  INT64_C(          2622073945) } },
    { {  INT32_C(  1754019323),  INT32_C(    69743715),  INT32_C(   807041143),  INT32_C(   772929322) },
      {  INT64_C(          1823763038),  INT64_C(          1579970465) } },
    { {  INT32_C(  1588832965),  INT32_C(  1653575734),  INT32_C(  2119366059),  INT32_C(  1161688160) },
      {  INT64_C(          3242408699),  INT64_C(          3281054219) } },
    { {  INT32_C(  1926642613),  INT32_C(   350097028), -INT32_C(   293302351),  INT32_C(   500710403) },
      {  INT64_C(          2276739641),  INT64_C(           207408052) } },
    { { -INT32_C(    75318990),  INT32_C(  1152700481),  INT32_C(  2002630157),  INT32_C(  2141228839) },
      {  INT64_C(          1077381491),  INT64_C(          4143858996) } },
    { { -INT32_C(  1820052001),  INT32_C(  1542272417),  INT32_C(  1422596997),  INT32_C(  1972498465) },
      { -INT64_C(           277779584),  INT64_C(          3395095462) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_haddq_epi32(a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_haddq_epi32(a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddq_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT8_C(162), UINT8_C(  0), UINT8_C(233), UINT8_C( 19), UINT8_C( 27), UINT8_C(225), UINT8_C(165), UINT8_C(  2),
        UINT8_C( 28), UINT8_C(176), UINT8_C(249), UINT8_C(253), UINT8_C(135), UINT8_C(158), UINT8_C(232), UINT8_C( 71) },
      { UINT64_C(                 833), UINT64_C(                1302) } },
    { { UINT8_C(159), UINT8_C(171), UINT8_C(253), UINT8_C(147), UINT8_C( 98), UINT8_C(178), UINT8_C( 59), UINT8_C( 34),
        UINT8_C( 25), UINT8_C(166), UINT8_C( 86), UINT8_C( 43), UINT8_C( 45), UINT8_C( 27), UINT8_C( 36), UINT8_C(127) },
      { UINT64_C(                1099), UINT64_C(                 555) } },
    { { UINT8_C( 60), UINT8_C(  8), UINT8_C( 78), UINT8_C(109), UINT8_C(108), UINT8_C(203), UINT8_C( 75), UINT8_C(227),
           UINT8_MAX, UINT8_C(109), UINT8_C(143), UINT8_C(215), UINT8_C( 40), UINT8_C( 40),    UINT8_MAX, UINT8_C(229) },
      { UINT64_C(                 868), UINT64_C(                1286) } },
    { { UINT8_C( 29), UINT8_C( 38), UINT8_C(169), UINT8_C( 58), UINT8_C(110), UINT8_C(140), UINT8_C(178), UINT8_C(176),
        UINT8_C(149), UINT8_C(183), UINT8_C(143), UINT8_C( 58), UINT8_C(206), UINT8_C(197), UINT8_C(120), UINT8_C(131) },
      { UINT64_C(                 898), UINT64_C(                1187) } },
    { { UINT8_C( 41), UINT8_C( 88), UINT8_C( 26), UINT8_C(210), UINT8_C(221), UINT8_C(150), UINT8_C(141), UINT8_C( 49),
        UINT8_C(223), UINT8_C(117), UINT8_C(133), UINT8_C(206), UINT8_C(179), UINT8_C( 53), UINT8_C(204), UINT8_C(161) },
      { UINT64_C(                 926), UINT64_C(                1276) } },
    { { UINT8_C(131), UINT8_C( 46), UINT8_C(240), UINT8_C( 79), UINT8_C(110), UINT8_C(203), UINT8_C( 57), UINT8_C( 79),
        UINT8_C( 34), UINT8_C(215), UINT8_C(221), UINT8_C( 75), UINT8_C(173), UINT8_C(247), UINT8_C(119), UINT8_C(201) },
      { UINT64_C(                 945), UINT64_C(                1285) } },
    { { UINT8_C(144), UINT8_C(120), UINT8_C(182), UINT8_C( 10), UINT8_C( 21), UINT8_C( 75), UINT8_C( 82), UINT8_C( 50),
        UINT8_C(227), UINT8_C( 78), UINT8_C( 69), UINT8_C(170), UINT8_C(208), UINT8_C(206), UINT8_C( 55), UINT8_C(195) },
      { UINT64_C(                 684), UINT64_C(                1208) } },
    { { UINT8_C(246), UINT8_C( 73), UINT8_C( 58), UINT8_C(156), UINT8_C(  9), UINT8_C(120), UINT8_C(183), UINT8_C( 69),
        UINT8_C(232), UINT8_C(140), UINT8_C(168), UINT8_C( 36), UINT8_C(113), UINT8_C(185), UINT8_C(  8), UINT8_C(152) },
      { UINT64_C(                 914), UINT64_C(                1034) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_haddq_epu8(a);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i r = simde_mm_haddq_epu8(a);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddq_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT16_C(61850), UINT16_C(56712), UINT16_C(62141), UINT16_C(12420), UINT16_C(33332), UINT16_C(13109), UINT16_C(63782), UINT16_C(37416) },
      { UINT64_C(              193123), UINT64_C(              147639) } },
    { { UINT16_C(  416), UINT16_C(59375), UINT16_C(39656), UINT16_C(56086), UINT16_C(24846), UINT16_C(36441), UINT16_C( 4547), UINT16_C(14867) },
      { UINT64_C(              155533), UINT64_C(               80701) } },
    { { UINT16_C(19054), UINT16_C( 5114), UINT16_C(37245), UINT16_C(28938), UINT16_C(39417), UINT16_C(12479), UINT16_C(49246), UINT16_C(22407) },
      { UINT64_C(               90351), UINT64_C(              123549) } },
    { { UINT16_C(56745), UINT16_C(63863), UINT16_C(14770), UINT16_C(22845), UINT16_C(56252), UINT16_C(20822), UINT16_C( 2379), UINT16_C(62849) },
      { UINT64_C(              158223), UINT64_C(              142302) } },
    { { UINT16_C( 2870), UINT16_C(29555), UINT16_C(13052), UINT16_C(16076), UINT16_C( 6491), UINT16_C(27466), UINT16_C(11039), UINT16_C(23356) },
      { UINT64_C(               61553), UINT64_C(               68352) } },
    { { UINT16_C(25913), UINT16_C(39482), UINT16_C(23824), UINT16_C( 1812), UINT16_C(33820), UINT16_C(13576), UINT16_C(43184), UINT16_C( 4664) },
      { UINT64_C(               91031), UINT64_C(               95244) } },
    { { UINT16_C(48407), UINT16_C(50779), UINT16_C(56547), UINT16_C(57010), UINT16_C(35970), UINT16_C(43581), UINT16_C(16658), UINT16_C(58160) },
      { UINT64_C(              212743), UINT64_C(              154369) } },
    { { UINT16_C( 8822), UINT16_C(37281), UINT16_C( 4010), UINT16_C(11395), UINT16_C(58195), UINT16_C(  727), UINT16_C(63131), UINT16_C(55329) },
      { UINT64_C(               61508), UINT64_C(              177382) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_haddq_epu16(a);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i r = simde_mm_haddq_epu16(a);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_haddq_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(3558467387), UINT32_C(2611255513), UINT32_C(3053615509), UINT32_C( 977865439) },
      { UINT64_C(          6169722900), UINT64_C(          4031480948) } },
    { { UINT32_C(2819791755), UINT32_C( 309483047), UINT32_C(2133622924), UINT32_C(2435120307) },
      { UINT64_C(          3129274802), UINT64_C(          4568743231) } },
    { { UINT32_C(1696010698), UINT32_C(3146411399), UINT32_C(1459644861), UINT32_C(2809171501) },
      { UINT64_C(          4842422097), UINT64_C(          4268816362) } },
    { { UINT32_C(2784385182), UINT32_C(4291377968), UINT32_C(1970136301), UINT32_C(2200617377) },
      { UINT64_C(          7075763150), UINT64_C(          4170753678) } },
    { { UINT32_C(1102889963), UINT32_C(2269930389), UINT32_C(1419764513), UINT32_C(1905186468) },
      { UINT64_C(          3372820352), UINT64_C(          3324950981) } },
    { { UINT32_C(1370940120), UINT32_C(1014023532), UINT32_C(2902759070), UINT32_C(4162407692) },
      { UINT64_C(          2384963652), UINT64_C(          7065166762) } },
    { { UINT32_C( 795903687), UINT32_C(1204978346), UINT32_C(2001170410), UINT32_C(3783911917) },
      { UINT64_C(          2000882033), UINT64_C(          5785082327) } },
    { { UINT32_C(1958264928), UINT32_C( 290454660), UINT32_C(3965132488), UINT32_C( 920365469) },
      { UINT64_C(          2248719588), UINT64_C(          4885497957) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_haddq_epu32(a);
    simde_test_x86_assert_equal_u64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i r = simde_mm_haddq_epu32(a);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_hsubw_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT8_C( 122), -INT8_C(  31), -INT8_C( 101), -INT8_C(   7),  INT8_C( 110), -INT8_C(  45),  INT8_C(   4),  INT8_C(  67),
         INT8_C(  63), -INT8_C( 107),  INT8_C(  96), -INT8_C( 122), -INT8_C(  80), -INT8_C(  49),  INT8_C(  75),  INT8_C(  63) },
      { -INT16_C(    91), -INT16_C(    94),  INT16_C(   155), -INT16_C(    63),  INT16_C(   170),  INT16_C(   218), -INT16_C(    31),  INT16_C(    12) } },
    { {  INT8_C(  95),  INT8_C( 122),  INT8_C( 102), -INT8_C(  42),  INT8_C(  31), -INT8_C(  24),  INT8_C(  79), -INT8_C(  59),
        -INT8_C( 109),  INT8_C(   5), -INT8_C(  48), -INT8_C(   3), -INT8_C(   4), -INT8_C(  36),  INT8_C(  86), -INT8_C( 123) },
      { -INT16_C(    27),  INT16_C(   144),  INT16_C(    55),  INT16_C(   138), -INT16_C(   114), -INT16_C(    45),  INT16_C(    32),  INT16_C(   209) } },
    { {  INT8_C(  79),  INT8_C(  93), -INT8_C(  91),  INT8_C( 101), -INT8_C( 117),  INT8_C(  93), -INT8_C(  53), -INT8_C(  62),
         INT8_C(  73), -INT8_C(  34),  INT8_C(  82),  INT8_C(  74), -INT8_C( 108), -INT8_C( 111), -INT8_C(  70), -INT8_C(  45) },
      { -INT16_C(    14), -INT16_C(   192), -INT16_C(   210),  INT16_C(     9),  INT16_C(   107),  INT16_C(     8),  INT16_C(     3), -INT16_C(    25) } },
    { { -INT8_C(   4), -INT8_C( 103),  INT8_C(  39),  INT8_C(  62), -INT8_C(  26), -INT8_C( 110),  INT8_C(  86), -INT8_C(  94),
         INT8_C(  38), -INT8_C(  46), -INT8_C(  43), -INT8_C(  89), -INT8_C(  48), -INT8_C(  18),  INT8_C( 116),  INT8_C(  47) },
      {  INT16_C(    99), -INT16_C(    23),  INT16_C(    84),  INT16_C(   180),  INT16_C(    84),  INT16_C(    46), -INT16_C(    30),  INT16_C(    69) } },
    { {  INT8_C(  74),      INT8_MIN, -INT8_C(   9),  INT8_C(  60), -INT8_C(  90),  INT8_C(  40),  INT8_C(  13),  INT8_C(  14),
         INT8_C(  47), -INT8_C(  47), -INT8_C( 122), -INT8_C( 117),  INT8_C(  66),  INT8_C(  54), -INT8_C(  64), -INT8_C(  28) },
      {  INT16_C(   202), -INT16_C(    69), -INT16_C(   130), -INT16_C(     1),  INT16_C(    94), -INT16_C(     5),  INT16_C(    12), -INT16_C(    36) } },
    { {  INT8_C(  96), -INT8_C(  92),  INT8_C(  98),  INT8_C( 118),      INT8_MIN,  INT8_C(   1),  INT8_C(  77), -INT8_C(  18),
        -INT8_C(  86),  INT8_C(  13), -INT8_C(  48), -INT8_C(  79), -INT8_C(  63), -INT8_C(  24),  INT8_C(  27),  INT8_C( 123) },
      {  INT16_C(   188), -INT16_C(    20), -INT16_C(   129),  INT16_C(    95), -INT16_C(    99),  INT16_C(    31), -INT16_C(    39), -INT16_C(    96) } },
    { { -INT8_C(  95), -INT8_C(  43), -INT8_C(   9),  INT8_C(  69),  INT8_C( 106),  INT8_C(  61), -INT8_C(  76),  INT8_C( 109),
         INT8_C(  26), -INT8_C(   9),  INT8_C(  98),  INT8_C(  17),  INT8_C(  98), -INT8_C(  58),  INT8_C(  68), -INT8_C(  69) },
      { -INT16_C(    52), -INT16_C(    78),  INT16_C(    45), -INT16_C(   185),  INT16_C(    35),  INT16_C(    81),  INT16_C(   156),  INT16_C(   137) } },
    { { -INT8_C(  78),  INT8_C(  35), -INT8_C( 127),  INT8_C(  68), -INT8_C( 105),  INT8_C(  61),  INT8_C(  29), -INT8_C(  14),
         INT8_C(  70),  INT8_C(  63),  INT8_C(  40), -INT8_C(  28),  INT8_C( 121), -INT8_C(  47),  INT8_C(  53), -INT8_C(  80) },
      { -INT16_C(   113), -INT16_C(   195), -INT16_C(   166),  INT16_C(    43),  INT16_C(     7),  INT16_C(    68),  INT16_C(   168),  INT16_C(   133) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_hsubw_epi8(a);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_hsubw_epi8(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_hsubd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT16_C(  7815),  INT16_C( 18958), -INT16_C( 23684),  INT16_C( 10406), -INT16_C( 10702), -INT16_C( 23729),  INT16_C( 19099), -INT16_C( 24275) },
      { -INT32_C(       26773), -INT32_C(       34090),  INT32_C(       13027),  INT32_C(       43374) } },
    { { -INT16_C( 24805),  INT16_C( 29163),  INT16_C( 20432), -INT16_C(  2388), -INT16_C(  4317),  INT16_C(  2117), -INT16_C( 20067),  INT16_C(  6057) },
      { -INT32_C(       53968),  INT32_C(       22820), -INT32_C(        6434), -INT32_C(       26124) } },
    { {  INT16_C( 12029),  INT16_C(  4516),  INT16_C( 25223), -INT16_C( 31027), -INT16_C(  1890),  INT16_C(  2998), -INT16_C( 14187), -INT16_C(  9115) },
      {  INT32_C(        7513),  INT32_C(       56250), -INT32_C(        4888), -INT32_C(        5072) } },
    { { -INT16_C( 24637), -INT16_C( 15096),  INT16_C( 16085),  INT16_C( 17124), -INT16_C( 23192), -INT16_C(  6769), -INT16_C( 28200), -INT16_C(  1953) },
      { -INT32_C(        9541), -INT32_C(        1039), -INT32_C(       16423), -INT32_C(       26247) } },
    { {  INT16_C( 17234),  INT16_C( 25634), -INT16_C( 31951), -INT16_C( 12017), -INT16_C(  6777),  INT16_C(  4093),  INT16_C( 19449), -INT16_C( 19245) },
      { -INT32_C(        8400), -INT32_C(       19934), -INT32_C(       10870),  INT32_C(       38694) } },
    { { -INT16_C( 21551),  INT16_C(  1856),  INT16_C(  4686),  INT16_C(  7596), -INT16_C(  5826),  INT16_C( 17006),  INT16_C( 30927), -INT16_C( 25793) },
      { -INT32_C(       23407), -INT32_C(        2910), -INT32_C(       22832),  INT32_C(       56720) } },
    { { -INT16_C( 22365),  INT16_C(  2542),  INT16_C(  3362),  INT16_C( 20310),  INT16_C(  8980),  INT16_C( 30862), -INT16_C( 10129),  INT16_C( 29535) },
      { -INT32_C(       24907), -INT32_C(       16948), -INT32_C(       21882), -INT32_C(       39664) } },
    { {  INT16_C( 19309),  INT16_C(   507), -INT16_C( 11038), -INT16_C( 11797),  INT16_C( 17613), -INT16_C(  6070),  INT16_C( 28205),  INT16_C( 18225) },
      {  INT32_C(       18802),  INT32_C(         759),  INT32_C(       23683),  INT32_C(        9980) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_hsubd_epi16(a);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_hsubd_epi16(a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_hsubq_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(   931994090),  INT32_C(  1250494467),  INT32_C(   231685230),  INT32_C(  1609660830) },
      { -INT64_C(          2182488557), -INT64_C(          1377975600) } },
    { {  INT32_C(  2040596673), -INT32_C(  1534358726), -INT32_C(  1601487556),  INT32_C(  1159560088) },
      {  INT64_C(          3574955399), -INT64_C(          2761047644) } },
    { {  INT32_C(  1796572371),  INT32_C(   143687036), -INT32_C(  1742030660), -INT32_C(  1032768209) },
      {  INT64_C(          1652885335), -INT64_C(           709262451) } },
    { {  INT32_C(   949643762), -INT32_C(   546095106),  INT32_C(   815357364), -INT32_C(   554981192) },
      {  INT64_C(          1495738868),  INT64_C(          1370338556) } },
    { { -INT32_C(  1203893757), -INT32_C(   766282956), -INT32_C(   553247449), -INT32_C(   490269239) },
      { -INT64_C(           437610801), -INT64_C(            62978210) } },
    { {  INT32_C(   105838379), -INT32_C(   913573675),  INT32_C(  1625041500),  INT32_C(  1468267575) },
      {  INT64_C(          1019412054),  INT64_C(           156773925) } },
    { {  INT32_C(  2035744974), -INT32_C(   273026348), -INT32_C(  1395984937),  INT32_C(   148643605) },
      {  INT64_C(          2308771322), -INT64_C(          1544628542) } },
    { { -INT32_C(  1440335726), -INT32_C(  1396981913), -INT32_C(    88265123), -INT32_C(    70418246) },
      { -INT64_C(            43353813), -INT64_C(            17846877) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_hsubq_epi32(a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_hsubq_epi32(a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_macc_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t c[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  4261),  INT16_C( 29895),  INT16_C(   515), -INT16_C( 22100), -INT16_C( 14349), -INT16_C( 14880),  INT16_C( 23995),  INT16_C( 31638) },
      { -INT16_C( 18865), -INT16_C(  4472), -INT16_C( 25763), -INT16_C( 12565), -INT16_C(  3618), -INT16_C( 15198),  INT16_C( 15084),  INT16_C(  4530) },
      {  INT16_C( 24531),  INT16_C( 29430), -INT16_C( 21398),  INT16_C( 17940),  INT16_C(  7332), -INT16_C(  3409), -INT16_C( 10398), -INT16_C( 31266) },
      { -INT16_C(  4376),  INT16_C( 32430),  INT16_C( 14465),  INT16_C( 28408),  INT16_C( 17502), -INT16_C( 21905), -INT16_C( 25146),  INT16_C( 27178) } },
    { { -INT16_C(  1653), -INT16_C( 26403), -INT16_C( 27297),  INT16_C( 30979), -INT16_C(  1528), -INT16_C( 30476),  INT16_C( 13426), -INT16_C(  8168) },
      { -INT16_C( 10659),  INT16_C( 14924), -INT16_C(  2127),  INT16_C(  4055),  INT16_C( 31505), -INT16_C(   609), -INT16_C( 27470),  INT16_C( 27805) },
      { -INT16_C( 30866),  INT16_C( 29070), -INT16_C( 19436), -INT16_C(  3093), -INT16_C( 12029),  INT16_C(  3100),  INT16_C( 30455), -INT16_C( 19991) },
      {  INT16_C( 24813), -INT16_C(  6870), -INT16_C( 23613), -INT16_C( 15760),  INT16_C( 17291),  INT16_C( 16296), -INT16_C( 10693),  INT16_C( 16545) } },
    { { -INT16_C(  8670), -INT16_C( 27087), -INT16_C(  4993),  INT16_C( 19678),  INT16_C( 27747), -INT16_C( 21480), -INT16_C( 25515),  INT16_C( 31161) },
      { -INT16_C(  5601),  INT16_C( 16641),  INT16_C(    37), -INT16_C( 31604), -INT16_C(   266),  INT16_C(  6528),  INT16_C(  1569), -INT16_C( 13301) },
      { -INT16_C(   438),  INT16_C( 19469), -INT16_C( 28292),  INT16_C( 17681),  INT16_C( 30657), -INT16_C( 13950), -INT16_C(  2064), -INT16_C(  3044) },
      { -INT16_C(  1944),  INT16_C( 21310), -INT16_C( 16425), -INT16_C( 14727), -INT16_C( 10013),  INT16_C( 11650),  INT16_C(  7397), -INT16_C( 25841) } },
    { { -INT16_C( 21817), -INT16_C( 12128), -INT16_C( 32455),  INT16_C( 30412),  INT16_C(  2313),  INT16_C( 30346), -INT16_C(  4456),  INT16_C( 31080) },
      { -INT16_C( 16388),  INT16_C(  9544), -INT16_C(  4015),  INT16_C( 16728),  INT16_C(  9556),  INT16_C(  6725), -INT16_C( 20946),  INT16_C(  9644) },
      {  INT16_C( 19853), -INT16_C(  6702),  INT16_C( 16633),  INT16_C(  3988),  INT16_C( 31590), -INT16_C(  4703),  INT16_C( 13829),  INT16_C(   230) },
      { -INT16_C(  7567), -INT16_C( 19758), -INT16_C( 27646), -INT16_C( 20044), -INT16_C( 16550), -INT16_C(  6957),  INT16_C( 25941), -INT16_C( 25914) } },
    { { -INT16_C( 22688), -INT16_C(  5814),  INT16_C(  4518), -INT16_C( 30052), -INT16_C(   701),  INT16_C( 26825), -INT16_C( 14412),  INT16_C( 21331) },
      {  INT16_C( 23962),  INT16_C( 19198),  INT16_C( 17421), -INT16_C( 26163), -INT16_C(  9166),  INT16_C( 17452), -INT16_C(  7152), -INT16_C( 22417) },
      {  INT16_C( 16543),  INT16_C( 24699), -INT16_C(  1502),  INT16_C( 26307), -INT16_C( 30537),  INT16_C( 31351),  INT16_C( 19757), -INT16_C( 14089) },
      { -INT16_C( 12193),  INT16_C( 15335), -INT16_C(  2160), -INT16_C( 24145), -INT16_C( 27699), -INT16_C(  7933),  INT16_C(  6253),  INT16_C( 25076) } },
    { {  INT16_C( 25109), -INT16_C( 14962), -INT16_C( 27364),  INT16_C( 23133), -INT16_C( 19816),  INT16_C( 17557),  INT16_C(   608), -INT16_C( 17430) },
      {  INT16_C(  4833),  INT16_C( 20804), -INT16_C( 19090),  INT16_C(  7863),  INT16_C( 19672),  INT16_C(  6837),  INT16_C( 17727), -INT16_C( 13694) },
      { -INT16_C(  7641),  INT16_C(  8169),  INT16_C( 15566), -INT16_C( 25810), -INT16_C( 30786), -INT16_C( 19133), -INT16_C( 26722),  INT16_C( 32574) },
      { -INT16_C( 28516), -INT16_C( 30815),  INT16_C(  6870),  INT16_C(  6569),  INT16_C( 22526),  INT16_C( 21660),  INT16_C(  3390), -INT16_C( 28654) } },
    { { -INT16_C( 23731), -INT16_C( 31221),  INT16_C( 18994), -INT16_C(  1698), -INT16_C( 11315),  INT16_C(  3820), -INT16_C( 18030), -INT16_C( 23845) },
      {  INT16_C( 26616),  INT16_C(  8311),  INT16_C( 16589), -INT16_C( 23770), -INT16_C(  7476),  INT16_C( 24478), -INT16_C( 21391),  INT16_C( 15701) },
      {  INT16_C( 32268), -INT16_C( 15047), -INT16_C( 16619),  INT16_C( 16802), -INT16_C( 23105),  INT16_C(  8069), -INT16_C( 20273), -INT16_C( 26390) },
      { -INT16_C( 21596),  INT16_C( 29782), -INT16_C( 22241),  INT16_C(  8086),  INT16_C( 26395), -INT16_C(  5843), -INT16_C( 19903), -INT16_C(  9567) } },
    { {  INT16_C( 30895), -INT16_C( 28768), -INT16_C( 22082), -INT16_C( 17361),  INT16_C( 19691),  INT16_C(  2318),  INT16_C( 18562),  INT16_C( 15382) },
      {  INT16_C( 10309), -INT16_C( 10441),  INT16_C(  7871),  INT16_C( 15466),  INT16_C( 18645),  INT16_C(  5606),  INT16_C( 13214), -INT16_C(  3177) },
      { -INT16_C( 24971),  INT16_C( 13772), -INT16_C( 32692),  INT16_C( 11312),  INT16_C( 19523),  INT16_C( 32251),  INT16_C( 29561), -INT16_C( 14743) },
      {  INT16_C( 32160),  INT16_C( 28972),  INT16_C( 26894),  INT16_C(  7078),  INT16_C( 25546), -INT16_C( 14705),  INT16_C(  6581),  INT16_C(  6499) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi16(test_vec[i].c);
    simde__m128i r = simde_mm_macc_epi16(a, b, c);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i c = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_macc_epi16(a, b, c);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_macc_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  2073286111),  INT32_C(   882733017), -INT32_C(  1200011720), -INT32_C(    37074522) },
      { -INT32_C(   614244495),  INT32_C(  1007733789), -INT32_C(  2117244165),  INT32_C(   557200893) },
      { -INT32_C(  1824584248),  INT32_C(  1864742923), -INT32_C(   794482929), -INT32_C(    60032368) },
      { -INT32_C(  1335696039), -INT32_C(  1280553056),  INT32_C(  1501048823), -INT32_C(  1650843234) } },
    { {  INT32_C(  1204635340),  INT32_C(   884577753), -INT32_C(   554947013), -INT32_C(  1771726922) },
      { -INT32_C(   837133983),  INT32_C(   921240572),  INT32_C(   617705859),  INT32_C(   962743811) },
      {  INT32_C(  1114822829),  INT32_C(  1544741673),  INT32_C(  1556160813),  INT32_C(  1843372109) },
      {  INT32_C(   764385273), -INT32_C(  1744506939), -INT32_C(  1171270562), -INT32_C(  1091183761) } },
    { { -INT32_C(    77294571), -INT32_C(   791586987),  INT32_C(  2103946940), -INT32_C(    57192792) },
      { -INT32_C(  1816420547), -INT32_C(    83640395), -INT32_C(  1028470026), -INT32_C(   292923030) },
      { -INT32_C(   477870069), -INT32_C(  2017083971), -INT32_C(  1546754591), -INT32_C(  1913454297) },
      {  INT32_C(  2093718540), -INT32_C(  1192237098), -INT32_C(   334977399),  INT32_C(  1434581687) } },
    { {  INT32_C(    68035235),  INT32_C(  1534341156), -INT32_C(   634867263),  INT32_C(  1632618676) },
      {  INT32_C(  1323629676), -INT32_C(  1582482467),  INT32_C(  1584275227),  INT32_C(   861696039) },
      {  INT32_C(  1540679944), -INT32_C(  1035124962),  INT32_C(  1787584436),  INT32_C(   219674580) },
      {  INT32_C(  2131753420), -INT32_C(  1459152334), -INT32_C(  1723105777), -INT32_C(   994161856) } },
    { {  INT32_C(    82524511),  INT32_C(  1735515229),  INT32_C(  1991205777),  INT32_C(   935043408) },
      {  INT32_C(  1635155348),  INT32_C(  2037838669),  INT32_C(   994335735),  INT32_C(  1003023985) },
      { -INT32_C(   872315379),  INT32_C(   570074596), -INT32_C(  1292256916), -INT32_C(   503734708) },
      { -INT32_C(   271838215), -INT32_C(   616287011),  INT32_C(  1813730643),  INT32_C(  1648636572) } },
    { { -INT32_C(   564501138), -INT32_C(   925346730),  INT32_C(   364522931),  INT32_C(   860599348) },
      {  INT32_C(  1871604637),  INT32_C(   388931610), -INT32_C(   608917037),  INT32_C(  2046586816) },
      { -INT32_C(  1695929921), -INT32_C(   161912092), -INT32_C(  1084989936),  INT32_C(  1032409285) },
      { -INT32_C(  1245489099),  INT32_C(  1920711584), -INT32_C(   758172775), -INT32_C(  2136800315) } },
    { { -INT32_C(  1225101256), -INT32_C(  1862871896), -INT32_C(  1186415377),  INT32_C(  1202592343) },
      {  INT32_C(  1552765614),  INT32_C(  1306672797),  INT32_C(    58488117), -INT32_C(  1586901557) },
      {  INT32_C(  1722686982), -INT32_C(   700757706),  INT32_C(   337476071), -INT32_C(  1812551241) },
      { -INT32_C(   340765674), -INT32_C(   915643330), -INT32_C(    11939230),  INT32_C(  1523333044) } },
    { { -INT32_C(   307599516),  INT32_C(   324851497), -INT32_C(  1483081141), -INT32_C(  1496174353) },
      {  INT32_C(  1242627118),  INT32_C(   803407979), -INT32_C(  1264883228), -INT32_C(  1531239544) },
      {  INT32_C(   380366857), -INT32_C(  1850917583),  INT32_C(  1947367033), -INT32_C(  1783725096) },
      { -INT32_C(   414125055), -INT32_C(   527469740),  INT32_C(   675750981), -INT32_C(   862048304) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_macc_epi32(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_macc_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maccd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 29565),  INT16_C( 13902),  INT16_C( 11781),  INT16_C( 25700),  INT16_C( 28267),  INT16_C( 20370), -INT16_C( 22899),  INT16_C(  8272) },
      {  INT16_C( 30523), -INT16_C( 28273),  INT16_C( 32411),  INT16_C( 23874),  INT16_C( 29131), -INT16_C(  3043),  INT16_C( 27337),  INT16_C( 29852) },
      { -INT32_C(   716668272),  INT32_C(  1664524932),  INT32_C(  1926272528),  INT32_C(  1305961358) },
      {  INT32_C(   185744223),  INT32_C(  2046358923), -INT32_C(  1545248791),  INT32_C(   679971395) } },
    { { -INT16_C(  9369),  INT16_C( 28585),  INT16_C( 28283), -INT16_C(  2368),  INT16_C( 17347),  INT16_C( 21628), -INT16_C( 30668),  INT16_C( 18466) },
      {  INT16_C(  1767),  INT16_C(  3364), -INT16_C(  1928), -INT16_C( 11869),  INT16_C(  7596),  INT16_C( 26674),  INT16_C(  3158),  INT16_C( 17117) },
      { -INT32_C(  1704277893), -INT32_C(   237071180), -INT32_C(  1153234732),  INT32_C(  1487496651) },
      { -INT32_C(  1720832916), -INT32_C(   291600804), -INT32_C(  1021466920),  INT32_C(  1390647107) } },
    { {  INT16_C(  9930),  INT16_C( 17771), -INT16_C( 10328), -INT16_C( 27469),  INT16_C( 10885), -INT16_C( 26304),  INT16_C( 18605), -INT16_C(  6297) },
      {  INT16_C( 26046),  INT16_C( 31576), -INT16_C( 26866),  INT16_C( 13987), -INT16_C(  6073), -INT16_C( 28165), -INT16_C( 21932), -INT16_C( 29639) },
      { -INT32_C(   408679807), -INT32_C(  1787828003),  INT32_C(  1854138083),  INT32_C(   612351834) },
      { -INT32_C(   150043027), -INT32_C(  1510355955),  INT32_C(  1788033478),  INT32_C(   204306974) } },
    { { -INT16_C(  9350),  INT16_C( 30973),  INT16_C(  8272), -INT16_C( 21224),  INT16_C(  2660),  INT16_C( 15659), -INT16_C(   360), -INT16_C( 13094) },
      { -INT16_C(  9389),  INT16_C( 23127), -INT16_C( 11297), -INT16_C( 17186),  INT16_C( 30992),  INT16_C( 19842),  INT16_C(  6695), -INT16_C(  7892) },
      { -INT32_C(    85896715),  INT32_C(  1061410372),  INT32_C(   693868402),  INT32_C(     9767519) },
      {  INT32_C(     1890435),  INT32_C(   967961588),  INT32_C(   776307122),  INT32_C(     7357319) } },
    { { -INT16_C( 15990),  INT16_C(  1548),  INT16_C( 16246), -INT16_C(  3576),  INT16_C(  2643), -INT16_C( 24635),  INT16_C(   474),  INT16_C(  1655) },
      { -INT16_C(  3975),  INT16_C( 27274),  INT16_C( 25264), -INT16_C( 11730), -INT16_C( 18757), -INT16_C( 17389),  INT16_C( 30065),  INT16_C(  4209) },
      {  INT32_C(  1397547884),  INT32_C(   502715498), -INT32_C(   841629197),  INT32_C(  2070289212) },
      {  INT32_C(  1461108134),  INT32_C(   913154442), -INT32_C(   891203948),  INT32_C(  2084540022) } },
    { { -INT16_C(  8372),  INT16_C( 11906),  INT16_C( 27485),  INT16_C( 20449), -INT16_C( 28539),  INT16_C( 24284), -INT16_C(  5995), -INT16_C(  7049) },
      {  INT16_C( 27202), -INT16_C( 22114),  INT16_C( 15234),  INT16_C(  9903), -INT16_C( 14535),  INT16_C( 15673),  INT16_C(  4373),  INT16_C( 10244) },
      { -INT32_C(  1336850506), -INT32_C(  1620927981),  INT32_C(  2000506137),  INT32_C(  1689127829) },
      { -INT32_C(  1564585650), -INT32_C(  1202221491), -INT32_C(  1879646794),  INT32_C(  1662911694) } },
    { {  INT16_C( 32083),  INT16_C( 28811),  INT16_C(  7303), -INT16_C(  2501),  INT16_C( 17517),  INT16_C( 22905), -INT16_C( 30163), -INT16_C(  2730) },
      {  INT16_C( 20481),  INT16_C( 22141), -INT16_C( 26727), -INT16_C( 22341),  INT16_C(  5311),  INT16_C( 28607), -INT16_C( 31433),  INT16_C( 31006) },
      {  INT32_C(   278545897),  INT32_C(  1956847170), -INT32_C(  2011275305), -INT32_C(   882495669) },
      {  INT32_C(   935637820),  INT32_C(  1761659889), -INT32_C(  1918242518),  INT32_C(    65617910) } },
    { {  INT16_C(  8563), -INT16_C( 30064),  INT16_C(  2489),  INT16_C( 21748),  INT16_C(  3518), -INT16_C( 20504), -INT16_C(   188),  INT16_C(  2511) },
      { -INT16_C(  5558), -INT16_C(  3757), -INT16_C(  5512), -INT16_C( 30738),  INT16_C( 16830),  INT16_C( 12719), -INT16_C( 22471), -INT16_C( 28613) },
      { -INT32_C(  1290607786), -INT32_C(  1978427335), -INT32_C(  1656528544), -INT32_C(    37085053) },
      { -INT32_C(  1338200940), -INT32_C(  1992146703), -INT32_C(  1597320604), -INT32_C(    32860505) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_maccd_epi16(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maccd_epi16(a, b, c);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_macclo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int64_t c[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  2067698623),  INT32_C(   421800180), -INT32_C(  1095495060),  INT32_C(   786275517) },
      {  INT32_C(   948551152),  INT32_C(   841149922), -INT32_C(  1571473173),  INT32_C(  1041666494) },
      {  INT64_C( 1247074322076690576), -INT64_C( 8406614527600821977) },
      {  INT64_C( 3208392232912154272), -INT64_C( 6685073429656796597) } },
    { { -INT32_C(  2088773494),  INT32_C(   858304636),  INT32_C(   665369000), -INT32_C(  1279526469) },
      {  INT32_C(   734827013),  INT32_C(  1450416090),  INT32_C(   557588024), -INT32_C(  1851091031) },
      {  INT64_C( 8587953065812515947),  INT64_C( 4882466335759732191) },
      {  INT64_C( 7053065878382922525),  INT64_C( 5253468121700588191) } },
    { {  INT32_C(   561920358), -INT32_C(   761587244), -INT32_C(   942757145),  INT32_C(   652537250) },
      {  INT32_C(   134639837), -INT32_C(   449110366),  INT32_C(  1278106584), -INT32_C(   667791074) },
      {  INT64_C( 7840394437456004346),  INT64_C( 3750478494743971195) },
      {  INT64_C( 7916051302864105992),  INT64_C( 2545534380606428515) } },
    { {  INT32_C(   312949798),  INT32_C(  1700207295), -INT32_C(  1099772710),  INT32_C(  1494454292) },
      {  INT32_C(  1331862538),  INT32_C(   202767039),  INT32_C(    70751806), -INT32_C(  1574398336) },
      { -INT64_C( 2339017557766903409), -INT64_C( 5949986363266398162) },
      { -INT64_C( 1922211445536036085), -INT64_C( 6027797268688412422) } },
    { {  INT32_C(  1470343646), -INT32_C(  1703433921),  INT32_C(  1797146230),  INT32_C(  1480800245) },
      { -INT32_C(  1102340256),  INT32_C(  1004397042),  INT32_C(  1721939485), -INT32_C(  1102480016) },
      { -INT64_C(     737231642832194),  INT64_C( 4495415384873303148) },
      { -INT64_C( 1621556222782445570),  INT64_C( 7589992438629194698) } },
    { {  INT32_C(   794789345),  INT32_C(  1633156761),  INT32_C(  1839103981),  INT32_C(  1940814439) },
      {  INT32_C(  1416445938),  INT32_C(   565103423), -INT32_C(   738598552),  INT32_C(  1016028627) },
      {  INT64_C( 4179656736626033754), -INT64_C( 5429924323381802266) },
      {  INT64_C( 5305432875916964364), -INT64_C( 6788283860725837778) } },
    { {  INT32_C(   402987457), -INT32_C(   376271026), -INT32_C(  1543692879),  INT32_C(   986788301) },
      {  INT32_C(  1353810706), -INT32_C(  1394479383), -INT32_C(   402030510),  INT32_C(  1765133771) },
      {  INT64_C( 4589542346372122741),  INT64_C( 2319653070256396177) },
      {  INT64_C( 5135111080042437383),  INT64_C( 2940264705684134467) } },
    { { -INT32_C(   788468910), -INT32_C(  1610476766),  INT32_C(   746981495),  INT32_C(  2053534154) },
      {  INT32_C(   860140372),  INT32_C(   202687090), -INT32_C(  2049296306), -INT32_C(   692738884) },
      { -INT64_C(   42443226956880798), -INT64_C( 3440577092560565345) },
      { -INT64_C(  720637168514715318), -INT64_C( 4971363510914422815) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi64(test_vec[i].c);
    simde__m128i r = simde_mm_macclo_epi32(a, b, c);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_macclo_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_macchi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int64_t c[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1526449063),  INT32_C(   918716952),  INT32_C(  1724081969),  INT32_C(  1147638338) },
      { -INT32_C(  1181723254), -INT32_C(  1356792161), -INT32_C(   910495728),  INT32_C(  1372387656) },
      { -INT64_C( 6358172095904620619),  INT64_C( 6003163645105245314) },
      { -INT64_C( 7604680054556033891),  INT64_C( 7578168333728801042) } },
    { { -INT32_C(   236804334), -INT32_C(  1708256397), -INT32_C(   226385902), -INT32_C(   435082153) },
      { -INT32_C(   482266936),  INT32_C(  1159763825),  INT32_C(   322097545), -INT32_C(   378264750) },
      { -INT64_C( 6441521447753334463),  INT64_C( 8653630751799968751) },
      { -INT64_C( 8422695420818772988),  INT64_C( 8818206993633975501) } },
    { {  INT32_C(   366992934), -INT32_C(    85967691), -INT32_C(  1379378034), -INT32_C(   270658452) },
      { -INT32_C(   280999072), -INT32_C(  1116747988),  INT32_C(    17711341), -INT32_C(   303580674) },
      { -INT64_C( 5977451265524821992),  INT64_C( 5662433887479092696) },
      { -INT64_C( 5881447019567566284),  INT64_C( 5744600562761049344) } },
    { { -INT32_C(  2040664137), -INT32_C(   961301086), -INT32_C(  1192853418),  INT32_C(   797467429) },
      {  INT32_C(  1572531942),  INT32_C(  1185547091),  INT32_C(  1952048560), -INT32_C(   324889938) },
      { -INT64_C( 6237606939636247666),  INT64_C( 2594782091165952624) },
      { -INT64_C( 7377274645718688492),  INT64_C( 2335692947601123222) } },
    { {  INT32_C(  1107796440), -INT32_C(  1396476866),  INT32_C(  1885615198), -INT32_C(  1291030940) },
      { -INT32_C(   350642387),  INT32_C(  1319699113), -INT32_C(  1990350972), -INT32_C(  1235303163) },
      { -INT64_C( 3935636701793332938), -INT64_C( 8441084314015536854) },
      { -INT64_C( 5778565983178552796), -INT64_C( 6846269710302673634) } },
    { { -INT32_C(  1983316773), -INT32_C(  1653886518),  INT32_C(  1963908825), -INT32_C(   861680051) },
      { -INT32_C(  1744296633), -INT32_C(  2071348175), -INT32_C(  1582846885),  INT32_C(  1477945830) },
      {  INT64_C( 9132250782254404322),  INT64_C( 5609591985390663865) },
      { -INT64_C( 5888718470738742644),  INT64_C( 4336075547221026535) } },
    { { -INT32_C(   657701292), -INT32_C(   985275703), -INT32_C(  1494341829),  INT32_C(   130635842) },
      { -INT32_C(  1535997816), -INT32_C(   643471571),  INT32_C(  1509907818),  INT32_C(   587847029) },
      {  INT64_C( 8402849216899243173),  INT64_C( 9149610631410482960) },
      {  INT64_C( 9036846121376782586), -INT64_C( 9220339550698455238) } },
    { { -INT32_C(   243464682), -INT32_C(  1775452416),  INT32_C(   575796277),  INT32_C(   893002982) },
      { -INT32_C(  1920790910),  INT32_C(  2056747809), -INT32_C(  1854709981), -INT32_C(  1515380716) },
      { -INT64_C( 7107536778999548205),  INT64_C( 7743054767455380834) },
      {  INT64_C( 7687549428118246867),  INT64_C( 6389815269202085722) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi64(test_vec[i].c);
    simde__m128i r = simde_mm_macchi_epi32(a, b, c);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_macchi_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maccs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t c[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  9819), -INT16_C( 26952), -INT16_C( 32069), -INT16_C( 11717),  INT16_C( 17910), -INT16_C( 26410), -INT16_C( 26593), -INT16_C( 19019) },
      {  INT16_C( 17890), -INT16_C(  8183),  INT16_C( 28196), -INT16_C(  6656), -INT16_C( 12394),  INT16_C(  1268),  INT16_C( 17546), -INT16_C( 27421) },
      { -INT16_C( 29946), -INT16_C(  4833),  INT16_C( 18967), -INT16_C( 31674),  INT16_C( 21608),  INT16_C( 22389),  INT16_C( 10259), -INT16_C( 29767) },
      {       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MAX } },
    { { -INT16_C( 17481),  INT16_C( 21446),  INT16_C( 30667),  INT16_C(  5612), -INT16_C( 31950), -INT16_C( 14266),  INT16_C( 17679), -INT16_C( 24267) },
      {  INT16_C(  9690), -INT16_C(  4596), -INT16_C( 27468),  INT16_C( 16909),  INT16_C( 19959), -INT16_C( 11627), -INT16_C(  9454),  INT16_C(  8083) },
      {  INT16_C( 23700), -INT16_C( 10946), -INT16_C( 31610), -INT16_C(  3320), -INT16_C(  6658),  INT16_C( 11725),  INT16_C( 28145), -INT16_C( 28847) },
      {       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C( 12361),  INT16_C( 25321),  INT16_C( 26423),  INT16_C( 21368), -INT16_C( 17973), -INT16_C( 11619), -INT16_C( 17726), -INT16_C( 18133) },
      { -INT16_C( 19809),  INT16_C( 11994), -INT16_C( 24579), -INT16_C( 13764),  INT16_C( 32035), -INT16_C(  1038), -INT16_C( 15143), -INT16_C( 23009) },
      {  INT16_C( 13178),  INT16_C(  4381), -INT16_C( 13237),  INT16_C(   367),  INT16_C(  8203),  INT16_C(  8183), -INT16_C( 13109), -INT16_C( 24471) },
      {       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MAX,       INT16_MAX } },
    { {  INT16_C( 17408),  INT16_C(  9472), -INT16_C( 12329), -INT16_C(  8080), -INT16_C( 11320), -INT16_C(  1765),  INT16_C( 21358),  INT16_C( 12423) },
      { -INT16_C( 18794), -INT16_C( 15600), -INT16_C( 13674), -INT16_C( 27942),  INT16_C(  2272), -INT16_C( 32502),  INT16_C(  6870),  INT16_C(  7734) },
      { -INT16_C( 25888), -INT16_C( 31719),  INT16_C(  7612),  INT16_C( 32652),  INT16_C( 28694), -INT16_C(  3918),  INT16_C(  8537),  INT16_C( 29554) },
      {       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MAX,       INT16_MAX } },
    { {  INT16_C( 16836),  INT16_C( 16426),  INT16_C( 27072),  INT16_C( 20385), -INT16_C(  1167), -INT16_C( 16322), -INT16_C( 21877),  INT16_C( 31096) },
      {  INT16_C( 15719),  INT16_C(  4494), -INT16_C( 28842), -INT16_C(  4744), -INT16_C(  9419), -INT16_C( 22499),  INT16_C( 13889), -INT16_C( 18234) },
      {  INT16_C( 23853),  INT16_C( 20435), -INT16_C( 20110), -INT16_C( 32595), -INT16_C( 32537), -INT16_C( 23557), -INT16_C( 31087), -INT16_C(  1511) },
      {       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MIN } },
    { { -INT16_C( 19268), -INT16_C( 27195),  INT16_C( 12362),  INT16_C( 29212), -INT16_C( 25524), -INT16_C(  5690), -INT16_C( 25649),  INT16_C( 18285) },
      { -INT16_C( 28168), -INT16_C( 17805), -INT16_C( 21676),  INT16_C( 28132),  INT16_C(  8297), -INT16_C(  3159), -INT16_C( 18799), -INT16_C(  5633) },
      { -INT16_C( 30968), -INT16_C( 10456),  INT16_C(  1347),  INT16_C( 22624),  INT16_C( 15491),  INT16_C( 31507),  INT16_C( 22443),  INT16_C( 26701) },
      {       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MAX,       INT16_MIN } },
    { {  INT16_C( 26190),  INT16_C( 18290),  INT16_C( 24077),  INT16_C( 23855),  INT16_C( 24864),  INT16_C( 30896),  INT16_C( 16434), -INT16_C( 29164) },
      {  INT16_C( 16242), -INT16_C( 24290),  INT16_C(  6375), -INT16_C(  6867),  INT16_C( 16899),  INT16_C(  9582),  INT16_C( 29308),  INT16_C( 25424) },
      {  INT16_C( 25431), -INT16_C( 16584), -INT16_C( 11450), -INT16_C( 25993), -INT16_C( 12749), -INT16_C(  1415),  INT16_C( 11805),  INT16_C( 12350) },
      {       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MIN,       INT16_MAX,       INT16_MAX,       INT16_MAX,       INT16_MIN } },
    { {  INT16_C( 25379), -INT16_C( 18162),  INT16_C( 28894),  INT16_C( 25449),  INT16_C( 14068), -INT16_C( 20418), -INT16_C(  2582),  INT16_C( 32605) },
      {  INT16_C(  4154), -INT16_C(  5843),  INT16_C(  4262),  INT16_C( 27298), -INT16_C(  4917),  INT16_C( 16746), -INT16_C( 30471),  INT16_C(  6503) },
      {  INT16_C( 31554), -INT16_C(  6046),  INT16_C(  5585),  INT16_C(  6398), -INT16_C( 24194), -INT16_C(  6678), -INT16_C(  6241),  INT16_C(  1627) },
      {       INT16_MAX,       INT16_MAX,       INT16_MAX,       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi16(test_vec[i].c);
    simde__m128i r = simde_mm_maccs_epi16(a, b, c);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i c = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maccs_epi16(a, b, c);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maccs_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1883572960),  INT32_C(   379133910),  INT32_C(   351028496), -INT32_C(  1888070545) },
      { -INT32_C(   159313928),  INT32_C(  1305612392), -INT32_C(  1982068281),  INT32_C(  1043615808) },
      {  INT32_C(  2001050416), -INT32_C(   448460675),  INT32_C(  1030250537), -INT32_C(   615277529) },
      {            INT32_MAX,            INT32_MAX,            INT32_MIN,            INT32_MIN } },
    { { -INT32_C(  1412192147),  INT32_C(  1238329418),  INT32_C(  1736178170),  INT32_C(  1892628856) },
      {  INT32_C(  1782090131),  INT32_C(   562942276), -INT32_C(  2109422273),  INT32_C(  1172727752) },
      { -INT32_C(   809447992),  INT32_C(  1457268000),  INT32_C(  1177548349), -INT32_C(   485185044) },
      {            INT32_MIN,            INT32_MAX,            INT32_MIN,            INT32_MAX } },
    { {  INT32_C(   821643120),  INT32_C(   274236627), -INT32_C(  1393885831),  INT32_C(   337100539) },
      {  INT32_C(   699402034), -INT32_C(  1159704431), -INT32_C(   312440136), -INT32_C(   504649657) },
      { -INT32_C(  1846386960), -INT32_C(    57661231), -INT32_C(  2084532480), -INT32_C(  1831950233) },
      {            INT32_MAX,            INT32_MIN,            INT32_MAX,            INT32_MIN } },
    { { -INT32_C(  2113151534), -INT32_C(  1094324410),  INT32_C(   628505749), -INT32_C(  1338229201) },
      {  INT32_C(  1435063611),  INT32_C(   723306214), -INT32_C(   835714053),  INT32_C(    99823029) },
      { -INT32_C(  1573267503), -INT32_C(  1435365914), -INT32_C(  1227254535), -INT32_C(  1712360372) },
      {            INT32_MIN,            INT32_MIN,            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(  1126741112), -INT32_C(   421239365),  INT32_C(  1470161555), -INT32_C(  1234283124) },
      {  INT32_C(  1369603414), -INT32_C(   959467750),  INT32_C(  1760697102), -INT32_C(   454274744) },
      {  INT32_C(   624297168),  INT32_C(  1959792120), -INT32_C(   461720848), -INT32_C(   316200555) },
      {            INT32_MAX,            INT32_MAX,            INT32_MAX,            INT32_MAX } },
    { {  INT32_C(  1471109258),  INT32_C(  1506074506),  INT32_C(    52910332), -INT32_C(   652485176) },
      { -INT32_C(  1055143062),  INT32_C(   533251653),  INT32_C(  1042677305), -INT32_C(   234442633) },
      {  INT32_C(  2076635028), -INT32_C(  1388731171),  INT32_C(  1323422955), -INT32_C(  1067114121) },
      {            INT32_MIN,            INT32_MAX,            INT32_MAX,            INT32_MAX } },
    { { -INT32_C(   549546897),  INT32_C(   766810440),  INT32_C(   755583895),  INT32_C(   217379547) },
      { -INT32_C(  2041460067),  INT32_C(   135661500),  INT32_C(   310973698), -INT32_C(   525327110) },
      {  INT32_C(  1225384966), -INT32_C(   411267668),  INT32_C(  2022581041), -INT32_C(  2066220951) },
      {            INT32_MAX,            INT32_MAX,            INT32_MAX,            INT32_MIN } },
    { {  INT32_C(  1102475981), -INT32_C(  1287450930),  INT32_C(   394634601), -INT32_C(  2098794500) },
      { -INT32_C(   958184104), -INT32_C(  1794594025), -INT32_C(   384037584), -INT32_C(  1566979640) },
      {  INT32_C(  1902079563), -INT32_C(   156712004),  INT32_C(   624888905), -INT32_C(   286423005) },
      {            INT32_MIN,            INT32_MAX,            INT32_MIN,            INT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_maccs_epi32(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maccs_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maccsd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  1075), -INT16_C( 11898),  INT16_C( 15985), -INT16_C( 17092),  INT16_C( 28092),  INT16_C( 18624), -INT16_C( 30180),  INT16_C( 25839) },
      {  INT16_C( 15881),  INT16_C(  4772), -INT16_C( 20528), -INT16_C( 10694), -INT16_C( 26055),  INT16_C( 26700), -INT16_C( 23961), -INT16_C( 21057) },
      { -INT32_C(   452728833),  INT32_C(   647355277),  INT32_C(   164188451), -INT32_C(  1547249853) },
      { -INT32_C(   435656758),  INT32_C(   319215197), -INT32_C(   567748609), -INT32_C(   824106873) } },
    { {  INT16_C( 18174), -INT16_C( 18478), -INT16_C( 26786),  INT16_C( 10704), -INT16_C(  2046), -INT16_C( 18938),  INT16_C(  7944), -INT16_C(  7388) },
      { -INT16_C(  8400),  INT16_C( 13186), -INT16_C(  1731), -INT16_C( 25174),  INT16_C( 13471),  INT16_C( 15638), -INT16_C( 20400),  INT16_C( 19003) },
      {  INT32_C(  1220966396),  INT32_C(  2133153124), -INT32_C(  1421219324), -INT32_C(   173343245) },
      {  INT32_C(  1068304796),            INT32_MAX, -INT32_C(  1448780990), -INT32_C(   335400845) } },
    { {  INT16_C(  4876),  INT16_C(  8844),  INT16_C( 16459),  INT16_C(  2945),  INT16_C( 15993),  INT16_C( 19760), -INT16_C( 17396),  INT16_C( 16724) },
      { -INT16_C(  1975),  INT16_C( 12040), -INT16_C( 28501), -INT16_C( 16831), -INT16_C( 27000), -INT16_C( 20580), -INT16_C(  7438), -INT16_C( 13478) },
      {  INT32_C(   447261916),  INT32_C(  1445223037), -INT32_C(  1616996614),  INT32_C(  1880859711) },
      {  INT32_C(   437631816),  INT32_C(   976125078), -INT32_C(  2048807614),  INT32_C(  2010251159) } },
    { { -INT16_C(  3539), -INT16_C( 11744), -INT16_C(  3589), -INT16_C( 12243),  INT16_C(  9430),  INT16_C( 10887),  INT16_C( 30667),  INT16_C( 20026) },
      { -INT16_C( 11801), -INT16_C( 31905), -INT16_C(  4963),  INT16_C( 26779),  INT16_C( 25959), -INT16_C( 25112),  INT16_C(  4016), -INT16_C( 16232) },
      { -INT32_C(  1684566542), -INT32_C(  1678761956), -INT32_C(  2070758090),  INT32_C(  1683317575) },
      { -INT32_C(  1642802803), -INT32_C(  1660949749), -INT32_C(  1825964720),  INT32_C(  1806476247) } },
    { { -INT16_C( 21641), -INT16_C( 14792), -INT16_C( 24207),  INT16_C( 10220), -INT16_C( 11765), -INT16_C( 20841), -INT16_C( 22999),  INT16_C(  6098) },
      { -INT16_C(  3874), -INT16_C(  3597), -INT16_C( 15147),  INT16_C(  2450), -INT16_C( 30224),  INT16_C(  9798),  INT16_C( 20014), -INT16_C(  2384) },
      {  INT32_C(  1237017298),  INT32_C(  2099322562),  INT32_C(   959579693),  INT32_C(  1607537008) },
      {  INT32_C(  1320854532),            INT32_MAX,  INT32_C(  1315165053),  INT32_C(  1147235022) } },
    { {  INT16_C( 17467),  INT16_C( 15295), -INT16_C( 31249),  INT16_C(   284), -INT16_C( 20661),  INT16_C( 30250), -INT16_C(  7608), -INT16_C(  4779) },
      {  INT16_C(  7489),  INT16_C( 30064),  INT16_C(  3671),  INT16_C( 20802),  INT16_C( 10260), -INT16_C( 22463), -INT16_C(  2225),  INT16_C( 32413) },
      { -INT32_C(   478105521),  INT32_C(  1788153139), -INT32_C(   574138480),  INT32_C(   793494621) },
      { -INT32_C(   347295158),  INT32_C(  1673438060), -INT32_C(   786120340),  INT32_C(   810422421) } },
    { {  INT16_C(  1036), -INT16_C( 19744),  INT16_C(  6138), -INT16_C( 30123),  INT16_C( 24841),  INT16_C( 25164),  INT16_C(   139),  INT16_C( 24127) },
      {  INT16_C( 23907),  INT16_C( 20672),  INT16_C(   358),  INT16_C( 11781), -INT16_C( 21752), -INT16_C( 15197), -INT16_C( 24780), -INT16_C( 22886) },
      {  INT32_C(  1771192443),  INT32_C(   308601201), -INT32_C(   807610028), -INT32_C(   440478225) },
      {  INT32_C(  1795960095),  INT32_C(   310798605), -INT32_C(  1347951460), -INT32_C(   443922645) } },
    { {  INT16_C( 29630), -INT16_C(  5626),  INT16_C(  3155),  INT16_C( 13428), -INT16_C( 12040), -INT16_C( 28344),  INT16_C(  6550),  INT16_C( 14411) },
      { -INT16_C(  1578),  INT16_C(    14),  INT16_C(  5509), -INT16_C( 12170), -INT16_C( 18627),  INT16_C( 22392),  INT16_C(  7746), -INT16_C(   734) },
      {  INT32_C(   433789354),  INT32_C(  1693177025), -INT32_C(  1371606613), -INT32_C(   815474101) },
      {  INT32_C(   387033214),  INT32_C(  1710557920), -INT32_C(  1147337533), -INT32_C(   764737801) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_maccsd_epi16(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maccsd_epi16(a, b, c);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maccslo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int64_t c[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(   505588124), -INT32_C(  1399563266),  INT32_C(  1655251980), -INT32_C(  1921809845) },
      {  INT32_C(  1170634605), -INT32_C(  1502543497), -INT32_C(  2129972120),  INT32_C(  1391495963) },
      { -INT64_C( 8159015487569231762),  INT64_C( 8987683831078602504) },
      { -INT64_C( 8750874441400662782),  INT64_C( 5462043262103804904) } },
    { { -INT32_C(   699419056), -INT32_C(   502318018),  INT32_C(  1949942134), -INT32_C(  1443572530) },
      {  INT32_C(   496082748),  INT32_C(  1578220351), -INT32_C(  1578677894), -INT32_C(  1258340702) },
      {  INT64_C(   57471327644090011), -INT64_C( 4865475103685557986) },
      { -INT64_C(  289498399659955877), -INT64_C( 7943805645210543782) } },
    { {  INT32_C(  1233639958),  INT32_C(    75507094), -INT32_C(  1526443606),  INT32_C(   474539392) },
      { -INT32_C(   950241642), -INT32_C(   391087329),  INT32_C(  1456889000),  INT32_C(  1938410747) },
      {  INT64_C( 7573719157811665220), -INT64_C( 7160926586083571488) },
      {  INT64_C( 6401463098484934184),                     INT64_MIN } },
    { { -INT32_C(   118470775), -INT32_C(  2084319543),  INT32_C(   374716764), -INT32_C(  1238709498) },
      { -INT32_C(  1018084083),  INT32_C(  1944696731),  INT32_C(  2145654116),  INT32_C(   470486408) },
      { -INT64_C( 5256034315837204293),  INT64_C( 7882427535233122689) },
      { -INT64_C( 5135421105509029968),  INT64_C( 8686440102243923313) } },
    { { -INT32_C(   499792197),  INT32_C(   200421081),  INT32_C(   615915901), -INT32_C(  2070552765) },
      { -INT32_C(   807693707),  INT32_C(  1838688118),  INT32_C(   995908449), -INT32_C(  2143348243) },
      {  INT64_C( 1891318278482297748), -INT64_C( 4880947430363376523) },
      {  INT64_C( 2294997290806902027), -INT64_C( 4267551580684028974) } },
    { {  INT32_C(  1195531775), -INT32_C(  1905689846),  INT32_C(  1895100482), -INT32_C(   675039400) },
      { -INT32_C(   341432863), -INT32_C(  2032680525), -INT32_C(   389524078), -INT32_C(  1390459636) },
      {  INT64_C(   38972361394823329),  INT64_C( 6555416003921373293) },
      { -INT64_C(  369221475350898496),  INT64_C( 5817228735952967697) } },
    { { -INT32_C(  1522445335),  INT32_C(   969092319), -INT32_C(   686306019),  INT32_C(  1026632362) },
      {  INT32_C(  1436222627), -INT32_C(  1392329579),  INT32_C(   670329386), -INT32_C(   219665912) },
      {  INT64_C( 1804037175386289910),  INT64_C( 6161128594745287517) },
      { -INT64_C(  382533263111305135),  INT64_C( 5701077502420913183) } },
    { { -INT32_C(  1130549172),  INT32_C(  2077882651),  INT32_C(  2037227201), -INT32_C(  2053615908) },
      { -INT32_C(  1914210738),  INT32_C(   280203678), -INT32_C(   706002788), -INT32_C(   569074364) },
      {  INT64_C( 6059826960292236517), -INT64_C(  282992977157640839) },
      {  INT64_C( 8223936325171645453), -INT64_C( 1721281060853077227) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi64(test_vec[i].c);
    simde__m128i r = simde_mm_maccslo_epi32(a, b, c);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maccslo_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maccshi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int64_t c[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1979598278),  INT32_C(    97049025), -INT32_C(  1249932512), -INT32_C(  1091207985) },
      {  INT32_C(  1358168758),  INT32_C(   533132435),  INT32_C(   335003547),  INT32_C(  1079883364) },
      { -INT64_C( 2354895035724027390), -INT64_C( 2365235082378056397) },
      { -INT64_C( 2303155052711401515), -INT64_C( 3543612432043517937) } },
    { {  INT32_C(  1314519047), -INT32_C(   991231468),  INT32_C(   706345839),  INT32_C(   947997352) },
      { -INT32_C(  1603440658), -INT32_C(  2007638411),  INT32_C(  1051004443),  INT32_C(   666881354) },
      {  INT64_C( 3067133650308224544), -INT64_C( 3780774117716555203) },
      {  INT64_C( 5057168019656941892), -INT64_C( 3148572360026380595) } },
    { { -INT32_C(  1999752890), -INT32_C(   404951914), -INT32_C(  1220111072), -INT32_C(  2135322678) },
      { -INT32_C(  1187134136),  INT32_C(  1002145416), -INT32_C(   155347891), -INT32_C(   478775526) },
      { -INT64_C( 1950187710052165807), -INT64_C( 3377721160132514932) },
      { -INT64_C( 2356008414367692031), -INT64_C( 2355380921793336304) } },
    { { -INT32_C(   154276407), -INT32_C(   562606837),  INT32_C(  2068857062),  INT32_C(  1733714390) },
      {  INT32_C(   479218264),  INT32_C(  1737777743),  INT32_C(   441317285),  INT32_C(    50040117) },
      { -INT64_C(  303534344943995415),  INT64_C( 4481191540110374482) },
      { -INT64_C( 1281219984342224306),  INT64_C( 4567946811030558112) } },
    { { -INT32_C(  1744768349),  INT32_C(  1490361462), -INT32_C(   725409099), -INT32_C(    95151695) },
      { -INT32_C(  2016377359),  INT32_C(  2075863692), -INT32_C(   912384041),  INT32_C(  1376461888) },
      { -INT64_C( 6937125781946813062), -INT64_C( 6686937538711071998) },
      { -INT64_C( 3843338535024975358), -INT64_C( 6817910220457172158) } },
    { { -INT32_C(  1403828439),  INT32_C(  1146392858),  INT32_C(  1667933118), -INT32_C(  1964028546) },
      { -INT32_C(    89637339),  INT32_C(   625660996),  INT32_C(  1648112597), -INT32_C(   459303650) },
      {  INT64_C( 4583677685977113048), -INT64_C( 3538556661785532081) },
      {  INT64_C( 5300930983320679616), -INT64_C( 2636471181903539181) } },
    { { -INT32_C(  1309723669), -INT32_C(   796056710),  INT32_C(    89090677), -INT32_C(  1516186466) },
      { -INT32_C(  1291617465),  INT32_C(  1419548856), -INT32_C(  2081252655),  INT32_C(   116618737) },
      { -INT64_C( 8535461188367467242), -INT64_C( 3585254504269373652) },
      {                     INT64_MIN, -INT64_C( 3762070254990787094) } },
    { {  INT32_C(  1732329151),  INT32_C(  1817938008), -INT32_C(   624992882),  INT32_C(   438551990) },
      {  INT32_C(   839681004),  INT32_C(   961408364),  INT32_C(   231406144),  INT32_C(  1216519452) },
      {  INT64_C( 7917879246931710342), -INT64_C(  901532948814373940) },
      {                     INT64_MAX, -INT64_C(  368025922266064460) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi64(test_vec[i].c);
    simde__m128i r = simde_mm_maccshi_epi32(a, b, c);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maccshi_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maddd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 10359),  INT16_C( 17786), -INT16_C(  2101), -INT16_C( 26389),  INT16_C( 18210),  INT16_C(  6206), -INT16_C(  6276), -INT16_C( 21611) },
      {  INT16_C( 31037), -INT16_C( 24421),  INT16_C( 30595), -INT16_C(  9610),  INT16_C( 29623),  INT16_C( 12791), -INT16_C( 23710),  INT16_C(  5396) },
      {  INT32_C(  1956224066), -INT32_C(   568697186), -INT32_C(   399732266), -INT32_C(   824897986) },
      {  INT32_C(  1843384443), -INT32_C(   379378991),  INT32_C(   219083510), -INT32_C(   792706982) } },
    { { -INT16_C( 24276),  INT16_C( 23616),  INT16_C(  3408),  INT16_C(  3765),  INT16_C( 20804),  INT16_C( 30409),  INT16_C( 10852), -INT16_C(  8494) },
      { -INT16_C(  9760),  INT16_C( 12190),  INT16_C(  9744),  INT16_C(  4453), -INT16_C( 23289),  INT16_C( 21755),  INT16_C( 14442), -INT16_C( 28854) },
      {  INT32_C(   100717955), -INT32_C(   779777391),  INT32_C(   993050210),  INT32_C(  1773844772) },
      {  INT32_C(   625530755), -INT32_C(   729804294),  INT32_C(  1170093649), -INT32_C(  2119312064) } },
    { {  INT16_C( 26489),  INT16_C( 15603),  INT16_C( 22729),  INT16_C( 30643),  INT16_C(  3292),  INT16_C(  9492),  INT16_C( 28328),  INT16_C( 13790) },
      { -INT16_C( 24985),  INT16_C( 26691), -INT16_C(  3091),  INT16_C( 28109),  INT16_C( 16697),  INT16_C( 19092),  INT16_C( 22346), -INT16_C(   588) },
      {  INT32_C(  1677642804),  INT32_C(  1525611634),  INT32_C(   584928638),  INT32_C(   175683487) },
      {  INT32_C(  1432274812), -INT32_C(  1978266914),  INT32_C(   821116426),  INT32_C(   800592455) } },
    { { -INT16_C( 31998),  INT16_C( 18545),  INT16_C( 21005),  INT16_C( 10357),  INT16_C( 25328),  INT16_C( 26973),  INT16_C(  3453), -INT16_C(  7256) },
      { -INT16_C( 28103),  INT16_C( 28201),  INT16_C(  6323),  INT16_C(   253), -INT16_C(  4076),  INT16_C(  5568),  INT16_C(  7160),  INT16_C( 21504) },
      {  INT32_C(  1878133884),  INT32_C(  1264889496),  INT32_C(  1643358640),  INT32_C(  1686037093) },
      { -INT32_C(   994606073),  INT32_C(  1400324432),  INT32_C(  1690307376),  INT32_C(  1554727549) } },
    { {  INT16_C( 16561),  INT16_C(  9179), -INT16_C( 18893), -INT16_C( 19768),  INT16_C( 32455), -INT16_C( 15324), -INT16_C( 23974),  INT16_C( 23647) },
      { -INT16_C( 15875), -INT16_C( 23249),  INT16_C(  4151),  INT16_C(  7556), -INT16_C( 24672), -INT16_C(  1601), -INT16_C(  8533), -INT16_C( 14818) },
      {  INT32_C(  1283153860), -INT32_C(  1221075557), -INT32_C(   110002497),  INT32_C(  1786467694) },
      {  INT32_C(   806845414), -INT32_C(  1448867408), -INT32_C(   886198533),  INT32_C(  1640636590) } },
    { {  INT16_C( 11180), -INT16_C( 20082),  INT16_C( 32658), -INT16_C(  5956), -INT16_C( 13335), -INT16_C(  1241),  INT16_C(  2551),  INT16_C( 20849) },
      {  INT16_C( 30361), -INT16_C( 20621), -INT16_C( 26990),  INT16_C( 22834),  INT16_C( 30755),  INT16_C( 31246),  INT16_C( 15324), -INT16_C( 15043) },
      {  INT32_C(  1568199089), -INT32_C(   218889392),  INT32_C(   764720562),  INT32_C(  1331522800) },
      { -INT32_C(  1973221305), -INT32_C(  1236328116),  INT32_C(   315826351),  INT32_C(  1056982817) } },
    { {  INT16_C(  3417),  INT16_C(  5418), -INT16_C(  5951), -INT16_C(  8543), -INT16_C(  3045),  INT16_C(  3941),  INT16_C( 23627), -INT16_C( 18547) },
      {  INT16_C( 15157),  INT16_C( 28502), -INT16_C( 23526), -INT16_C( 31468), -INT16_C(  6620),  INT16_C( 22895),  INT16_C(  3647),  INT16_C(  1739) },
      {  INT32_C(  1158196523), -INT32_C(  1888691249), -INT32_C(  2099414063), -INT32_C(  2041265821) },
      {  INT32_C(  1364411828), -INT32_C(  1479856899), -INT32_C(  1989026968), -INT32_C(  1987351385) } },
    { { -INT16_C(  3488), -INT16_C( 20338),  INT16_C( 27543), -INT16_C(  6395), -INT16_C(  6809),  INT16_C( 17694), -INT16_C(  2164), -INT16_C( 16476) },
      { -INT16_C(  9160),  INT16_C(  2421),  INT16_C( 30565), -INT16_C( 19333), -INT16_C( 27542), -INT16_C( 25890),  INT16_C( 29133),  INT16_C( 31608) },
      { -INT32_C(   393577127),  INT32_C(  1621974896), -INT32_C(  1173669214), -INT32_C(  1026674562) },
      { -INT32_C(   410865345), -INT32_C(  1707506070), -INT32_C(  1444233396), -INT32_C(  1610491782) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_maddd_epi16(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maddd_epi16(a, b, c);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maddsd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  9639),  INT16_C( 10201), -INT16_C( 15061), -INT16_C( 27210), -INT16_C( 14319),  INT16_C(  7888),  INT16_C( 29745), -INT16_C(  8477) },
      {  INT16_C( 25673), -INT16_C(  8272), -INT16_C( 30388),  INT16_C( 15093),  INT16_C( 28413),  INT16_C( 32668), -INT16_C( 16195),  INT16_C( 22323) },
      {  INT32_C(  1755057569),  INT32_C(  2030488776), -INT32_C(   685990164), -INT32_C(   142879946) },
      {  INT32_C(  1918136944),  INT32_C(  2077481914), -INT32_C(   835150727), -INT32_C(   813832292) } },
    { {  INT16_C( 12375),  INT16_C( 23658), -INT16_C(  4140), -INT16_C( 17467),  INT16_C(  2209),  INT16_C( 24123), -INT16_C( 20494), -INT16_C( 14662) },
      {  INT16_C(  7758), -INT16_C( 27610), -INT16_C( 27419), -INT16_C( 21935), -INT16_C( 25053), -INT16_C( 29400), -INT16_C( 27259),  INT16_C(  3370) },
      {  INT32_C(   689924268),  INT32_C(   755407792),  INT32_C(   491753654),  INT32_C(  1447691973) },
      {  INT32_C(   132732138),  INT32_C(  1252061097), -INT32_C(   272804623),  INT32_C(  1956926979) } },
    { { -INT16_C(  8235),  INT16_C( 29664),  INT16_C(  9769),  INT16_C( 28289),  INT16_C( 20703),  INT16_C(  1885), -INT16_C( 15674),  INT16_C( 27351) },
      { -INT16_C( 27537),  INT16_C(  3126), -INT16_C( 27257), -INT16_C( 10594), -INT16_C( 28829), -INT16_C( 31424), -INT16_C( 13091),  INT16_C( 20941) },
      { -INT32_C(   869214113),  INT32_C(   243042621),  INT32_C(   253967688),  INT32_C(  1416258464) },
      { -INT32_C(   549717254), -INT32_C(   322924678), -INT32_C(   402113339),            INT32_MAX } },
    { {  INT16_C( 15817), -INT16_C( 12775), -INT16_C(  7423), -INT16_C(   137), -INT16_C( 29487),  INT16_C( 24181),  INT16_C(  2531), -INT16_C(   726) },
      { -INT16_C( 28141),  INT16_C( 27007), -INT16_C( 14904), -INT16_C( 11988), -INT16_C(  4987),  INT16_C( 27619),  INT16_C( 32699),  INT16_C(  5322) },
      {  INT32_C(   925887202), -INT32_C(   277311545),  INT32_C(  1884819240), -INT32_C(  1555446402) },
      {  INT32_C(   135766580), -INT32_C(   165036797),            INT32_MAX, -INT32_C(  1476549005) } },
    { { -INT16_C( 27622),  INT16_C(  4150), -INT16_C(  7309),  INT16_C(   375), -INT16_C(  6721), -INT16_C(  7165),  INT16_C(  7872), -INT16_C(  3359) },
      {  INT16_C(  9185),  INT16_C(  3808), -INT16_C( 24191), -INT16_C(  3960), -INT16_C( 24433), -INT16_C( 32176),  INT16_C(  2391), -INT16_C( 30190) },
      { -INT32_C(  1967429989), -INT32_C(   465048858),  INT32_C(  1122873629),  INT32_C(   899041367) },
      {            INT32_MIN, -INT32_C(   289721839),  INT32_C(  1517628862),  INT32_C(  1019271529) } },
    { {  INT16_C( 28910),  INT16_C(  7572),  INT16_C(  8151),  INT16_C( 18577), -INT16_C( 14290),  INT16_C( 24261), -INT16_C(  9195), -INT16_C(   915) },
      { -INT16_C( 28225), -INT16_C( 24712), -INT16_C(  7480), -INT16_C( 15229), -INT16_C( 10296),  INT16_C( 19719),  INT16_C(  1575),  INT16_C( 10193) },
      {  INT32_C(   716397107),  INT32_C(  1081742191), -INT32_C(   903934418),  INT32_C(  1061308257) },
      { -INT32_C(   286706907),  INT32_C(   737863578), -INT32_C(   278401919),  INT32_C(  1037499537) } },
    { { -INT16_C( 25426),  INT16_C(  5843), -INT16_C( 11070), -INT16_C(  6381), -INT16_C(  8217), -INT16_C( 12869),  INT16_C( 24537),  INT16_C(  3706) },
      {  INT16_C( 26837), -INT16_C(   347), -INT16_C( 31500),  INT16_C(  8235), -INT16_C(  1097), -INT16_C( 28729),  INT16_C( 20963), -INT16_C( 25479) },
      { -INT32_C(  1187639409), -INT32_C(  1763719301), -INT32_C(  1989127517),  INT32_C(   863656980) },
      { -INT32_C(  1872024492), -INT32_C(  1467561836), -INT32_C(  1610399967),  INT32_C(  1283600937) } },
    { {  INT16_C(  9215),  INT16_C( 25043),  INT16_C( 31500),  INT16_C( 12427),  INT16_C(  5872),  INT16_C( 29987),  INT16_C(   578),  INT16_C( 23546) },
      {  INT16_C( 29578),  INT16_C( 19976), -INT16_C( 15460),  INT16_C(  6350), -INT16_C( 18652),  INT16_C( 19085),  INT16_C(  1153), -INT16_C(  8521) },
      {  INT32_C(   446894551), -INT32_C(  1199243425),  INT32_C(  1134356226), -INT32_C(   995270105) },
      {  INT32_C(  1219714789), -INT32_C(  1607321975),  INT32_C(  1597133577), -INT32_C(  1195239137) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_maddsd_epi16(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maddsd_epi16(a, b, c);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_sha_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  55),  INT8_C(  79), -INT8_C(  79), -INT8_C(  98), -INT8_C(  52), -INT8_C(  48), -INT8_C(  54), -INT8_C(  73),
        -INT8_C( 111), -INT8_C( 106),  INT8_C( 124), -INT8_C(  40), -INT8_C(  56),  INT8_C(  95),  INT8_C(  26),  INT8_C(  87) },
      { -INT8_C(   5), -INT8_C(   4),  INT8_C(   6), -INT8_C(   3), -INT8_C(   6),  INT8_C(   0), -INT8_C(   5), -INT8_C(   7),
         INT8_C(   5), -INT8_C(   6), -INT8_C(   3), -INT8_C(   3),  INT8_C(   1),  INT8_C(   2),  INT8_C(   2),  INT8_C(   7) },
      { -INT8_C(   2),  INT8_C(   4),  INT8_C(  64), -INT8_C(  13), -INT8_C(   1), -INT8_C(  48), -INT8_C(   2), -INT8_C(   1),
         INT8_C(  32), -INT8_C(   2),  INT8_C(  15), -INT8_C(   5), -INT8_C( 112),  INT8_C( 124),  INT8_C( 104),      INT8_MIN } },
    { {  INT8_C( 113),  INT8_C(  43), -INT8_C( 103),  INT8_C( 113), -INT8_C(  76), -INT8_C(   9), -INT8_C(  69), -INT8_C(  71),
         INT8_C(  18),  INT8_C( 120), -INT8_C(  92), -INT8_C(   5), -INT8_C( 112),  INT8_C( 117), -INT8_C( 117), -INT8_C(  27) },
      {  INT8_C(   2), -INT8_C(   4), -INT8_C(   5), -INT8_C(   2),  INT8_C(   1), -INT8_C(   6), -INT8_C(   7),  INT8_C(   6),
         INT8_C(   7), -INT8_C(   4), -INT8_C(   6), -INT8_C(   3),  INT8_C(   1),  INT8_C(   1),  INT8_C(   2), -INT8_C(   3) },
      { -INT8_C(  60),  INT8_C(   2), -INT8_C(   4),  INT8_C(  28),  INT8_C( 104), -INT8_C(   1), -INT8_C(   1),  INT8_C(  64),
         INT8_C(   0),  INT8_C(   7), -INT8_C(   2), -INT8_C(   1),  INT8_C(  32), -INT8_C(  22),  INT8_C(  44), -INT8_C(   4) } },
    { { -INT8_C(  83), -INT8_C( 113),  INT8_C(  40), -INT8_C( 113), -INT8_C(   5),  INT8_C(  63), -INT8_C( 121),  INT8_C( 103),
        -INT8_C(  47), -INT8_C(  29),  INT8_C( 109),  INT8_C( 123), -INT8_C( 127),  INT8_C(  79), -INT8_C(  13), -INT8_C(  47) },
      {  INT8_C(   6),  INT8_C(   7), -INT8_C(   6),  INT8_C(   0),  INT8_C(   7),  INT8_C(   2),  INT8_C(   0), -INT8_C(   5),
        -INT8_C(   3),  INT8_C(   0), -INT8_C(   6), -INT8_C(   4), -INT8_C(   6), -INT8_C(   7),  INT8_C(   3), -INT8_C(   1) },
      {  INT8_C(  64),      INT8_MIN,  INT8_C(   0), -INT8_C( 113),      INT8_MIN, -INT8_C(   4), -INT8_C( 121),  INT8_C(   3),
        -INT8_C(   6), -INT8_C(  29),  INT8_C(   1),  INT8_C(   7), -INT8_C(   2),  INT8_C(   0), -INT8_C( 104), -INT8_C(  24) } },
    { { -INT8_C(  93),  INT8_C(   4), -INT8_C(  58), -INT8_C(  65),  INT8_C(  74), -INT8_C(  79),  INT8_C(  23),  INT8_C(   9),
        -INT8_C(  13),  INT8_C(  98),  INT8_C(  63),  INT8_C(  31),  INT8_C(  68), -INT8_C(  12),  INT8_C(  56),  INT8_C( 100) },
      {  INT8_C(   0),  INT8_C(   7),  INT8_C(   3),  INT8_C(   5),  INT8_C(   1),  INT8_C(   3),  INT8_C(   1),  INT8_C(   4),
        -INT8_C(   7), -INT8_C(   2), -INT8_C(   4),  INT8_C(   6),  INT8_C(   1),  INT8_C(   5), -INT8_C(   7), -INT8_C(   1) },
      { -INT8_C(  93),  INT8_C(   0),  INT8_C(  48), -INT8_C(  32), -INT8_C( 108), -INT8_C( 120),  INT8_C(  46), -INT8_C( 112),
        -INT8_C(   1),  INT8_C(  24),  INT8_C(   3), -INT8_C(  64), -INT8_C( 120),      INT8_MIN,  INT8_C(   0),  INT8_C(  50) } },
    { {  INT8_C( 123),  INT8_C(  17), -INT8_C(  37), -INT8_C(  54),  INT8_C(  73),  INT8_C(  83),  INT8_C(  83), -INT8_C(  25),
        -INT8_C(  93),  INT8_C( 122), -INT8_C( 126), -INT8_C(  80), -INT8_C( 127),  INT8_C( 108),  INT8_C(  68), -INT8_C(  29) },
      { -INT8_C(   1),  INT8_C(   4),  INT8_C(   2),  INT8_C(   1),  INT8_C(   7), -INT8_C(   2),  INT8_C(   2),  INT8_C(   3),
        -INT8_C(   4),  INT8_C(   3), -INT8_C(   7),  INT8_C(   0),  INT8_C(   2), -INT8_C(   2), -INT8_C(   4), -INT8_C(   3) },
      {  INT8_C(  61),  INT8_C(  16),  INT8_C( 108), -INT8_C( 108),      INT8_MIN,  INT8_C(  20),  INT8_C(  76),  INT8_C(  56),
        -INT8_C(   6), -INT8_C(  48), -INT8_C(   1), -INT8_C(  80),  INT8_C(   4),  INT8_C(  27),  INT8_C(   4), -INT8_C(   4) } },
    { {  INT8_C(  94),  INT8_C(  63), -INT8_C(  49),  INT8_C( 121), -INT8_C(  97),  INT8_C(  47),  INT8_C(  35),  INT8_C(  72),
         INT8_C(   7), -INT8_C(  75), -INT8_C(  98), -INT8_C(   9), -INT8_C(  33), -INT8_C(  64), -INT8_C(   3), -INT8_C( 103) },
      {  INT8_C(   0), -INT8_C(   4), -INT8_C(   5),  INT8_C(   3), -INT8_C(   7),  INT8_C(   5), -INT8_C(   4),  INT8_C(   1),
        -INT8_C(   1), -INT8_C(   2), -INT8_C(   6), -INT8_C(   4),  INT8_C(   0), -INT8_C(   6), -INT8_C(   4), -INT8_C(   7) },
      {  INT8_C(  94),  INT8_C(   3), -INT8_C(   2), -INT8_C(  56), -INT8_C(   1), -INT8_C(  32),  INT8_C(   2), -INT8_C( 112),
         INT8_C(   3), -INT8_C(  19), -INT8_C(   2), -INT8_C(   1), -INT8_C(  33), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C( 116),  INT8_C(  21),  INT8_C(  10), -INT8_C( 110), -INT8_C(  11),  INT8_C(  77),  INT8_C( 112),  INT8_C( 118),
         INT8_C(  71), -INT8_C( 102), -INT8_C(   4), -INT8_C(  71),  INT8_C(   7), -INT8_C(   9),  INT8_C(  77), -INT8_C(  51) },
      { -INT8_C(   6), -INT8_C(   1),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4), -INT8_C(   6),  INT8_C(   5),  INT8_C(   7),
         INT8_C(   7),  INT8_C(   7),  INT8_C(   3),  INT8_C(   0),  INT8_C(   3), -INT8_C(   2),  INT8_C(   6), -INT8_C(   4) },
      {  INT8_C(   1),  INT8_C(  10),  INT8_C(  80),  INT8_C(  64),  INT8_C(  80),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
             INT8_MIN,  INT8_C(   0), -INT8_C(  32), -INT8_C(  71),  INT8_C(  56), -INT8_C(   3),  INT8_C(  64), -INT8_C(   4) } },
    { { -INT8_C(  28),  INT8_C(  27), -INT8_C(  12), -INT8_C(  35), -INT8_C(  14), -INT8_C(  77),  INT8_C(  32), -INT8_C(  73),
        -INT8_C( 116), -INT8_C(  79),  INT8_C(   2), -INT8_C(  63), -INT8_C(  95),  INT8_C(  25),  INT8_C(  27), -INT8_C(  58) },
      { -INT8_C(   2), -INT8_C(   2), -INT8_C(   3), -INT8_C(   5),  INT8_C(   4), -INT8_C(   5),  INT8_C(   7), -INT8_C(   5),
        -INT8_C(   5), -INT8_C(   2),  INT8_C(   5),  INT8_C(   5), -INT8_C(   5), -INT8_C(   5),  INT8_C(   1), -INT8_C(   3) },
      { -INT8_C(   7),  INT8_C(   6), -INT8_C(   2), -INT8_C(   2),  INT8_C(  32), -INT8_C(   3),  INT8_C(   0), -INT8_C(   3),
        -INT8_C(   4), -INT8_C(  20),  INT8_C(  64),  INT8_C(  32), -INT8_C(   3),  INT8_C(   0),  INT8_C(  54), -INT8_C(   8) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_sha_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();

    simde__m128i nmask = simde_mm_cmplt_epi8(b, simde_mm_setzero_si128());
    b = simde_mm_and_si128(b, simde_mm_set1_epi8(7));
    b = simde_mm_or_si128(simde_mm_and_si128(nmask, simde_mm_sub_epi8(simde_mm_setzero_si128(), b)), simde_mm_andnot_si128(nmask, b));

    simde__m128i r = simde_mm_sha_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_sha_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  9769),  INT16_C(  9461),  INT16_C( 27455),  INT16_C( 21533), -INT16_C( 31746), -INT16_C( 10727),  INT16_C( 12116), -INT16_C( 12978) },
      {  INT16_C(    10), -INT16_C(     7), -INT16_C(    12), -INT16_C(     2), -INT16_C(     2),  INT16_C(    11), -INT16_C(     9), -INT16_C(    10) },
      {  INT16_C( 23552),  INT16_C(    73),  INT16_C(     6),  INT16_C(  5383), -INT16_C(  7937), -INT16_C( 14336),  INT16_C(    23), -INT16_C(    13) } },
    { { -INT16_C( 10124),  INT16_C( 11638),  INT16_C( 32131), -INT16_C( 27315), -INT16_C( 26684), -INT16_C( 16471),  INT16_C( 16328),  INT16_C( 10960) },
      { -INT16_C(    16), -INT16_C(     4),  INT16_C(    12), -INT16_C(    12),  INT16_C(     3),  INT16_C(     7), -INT16_C(    10),  INT16_C(     6) },
      { -INT16_C(     1),  INT16_C(   727),  INT16_C( 12288), -INT16_C(     7), -INT16_C( 16864), -INT16_C( 11136),  INT16_C(    15), -INT16_C( 19456) } },
    { { -INT16_C( 24604), -INT16_C( 15907), -INT16_C(  4249), -INT16_C( 15974),  INT16_C( 29959),  INT16_C( 17691),  INT16_C( 21670),  INT16_C(  9608) },
      { -INT16_C(     8), -INT16_C(     4),  INT16_C(     1), -INT16_C(     5), -INT16_C(     6), -INT16_C(    13), -INT16_C(    11),  INT16_C(    15) },
      { -INT16_C(    97), -INT16_C(   995), -INT16_C(  8498), -INT16_C(   500),  INT16_C(   468),  INT16_C(     2),  INT16_C(    10),  INT16_C(     0) } },
    { { -INT16_C( 18866), -INT16_C( 22380), -INT16_C( 13421),  INT16_C(  8939), -INT16_C( 22802),  INT16_C( 12501),  INT16_C( 29590),  INT16_C(  1630) },
      { -INT16_C(    14), -INT16_C(    12), -INT16_C(    13), -INT16_C(     2), -INT16_C(    12),  INT16_C(     8), -INT16_C(    10), -INT16_C(     7) },
      { -INT16_C(     2), -INT16_C(     6), -INT16_C(     2),  INT16_C(  2234), -INT16_C(     6), -INT16_C( 11008),  INT16_C(    28),  INT16_C(    12) } },
    { { -INT16_C( 22821), -INT16_C( 22015),  INT16_C(  6574), -INT16_C(   473), -INT16_C( 20062),  INT16_C( 18497), -INT16_C( 22977),  INT16_C(  5178) },
      { -INT16_C(    16), -INT16_C(     5),  INT16_C(     4),  INT16_C(     5),  INT16_C(     1), -INT16_C(     1), -INT16_C(     6),  INT16_C(    13) },
      { -INT16_C(     1), -INT16_C(   688), -INT16_C( 25888), -INT16_C( 15136),  INT16_C( 25412),  INT16_C(  9248), -INT16_C(   360),  INT16_C( 16384) } },
    { { -INT16_C(  2382), -INT16_C( 28786), -INT16_C(  8352), -INT16_C( 25032),  INT16_C(  7754),  INT16_C( 21702), -INT16_C(  2998), -INT16_C( 26620) },
      {  INT16_C(     2),  INT16_C(    11), -INT16_C(    11), -INT16_C(     8), -INT16_C(    13), -INT16_C(    15),  INT16_C(     2), -INT16_C(    12) },
      { -INT16_C(  9528),  INT16_C( 28672), -INT16_C(     5), -INT16_C(    98),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11992), -INT16_C(     7) } },
    { {  INT16_C( 12029),  INT16_C(  7842),  INT16_C( 10067),  INT16_C( 18949),  INT16_C( 30223),  INT16_C(  7883),  INT16_C( 26206), -INT16_C(  9564) },
      { -INT16_C(     6), -INT16_C(     3),  INT16_C(     6),  INT16_C(     2), -INT16_C(     5), -INT16_C(     8),  INT16_C(    14), -INT16_C(     8) },
      {  INT16_C(   187),  INT16_C(   980), -INT16_C( 11072),  INT16_C( 10260),  INT16_C(   944),  INT16_C(    30),       INT16_MIN, -INT16_C(    38) } },
    { { -INT16_C( 10271),  INT16_C(  8356), -INT16_C(  2004),  INT16_C( 18806),  INT16_C( 16409),  INT16_C( 27834),  INT16_C(   548),  INT16_C(  8707) },
      {  INT16_C(     9),  INT16_C(    10), -INT16_C(     7),  INT16_C(    10),  INT16_C(    10),  INT16_C(    11),  INT16_C(     1),  INT16_C(     0) },
      { -INT16_C( 15872), -INT16_C( 28672), -INT16_C(    16), -INT16_C( 10240),  INT16_C( 25600), -INT16_C( 12288),  INT16_C(  1096),  INT16_C(  8707) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_sha_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_srai_epi16(simde_test_x86_random_i16x8(), 11);
    simde__m128i r = simde_mm_sha_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_sha_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   376500546),  INT32_C(   246411337), -INT32_C(   550133744),  INT32_C(  2017512208) },
      { -INT32_C(          12), -INT32_C(           2), -INT32_C(          21),  INT32_C(          27) },
      { -INT32_C(       91920),  INT32_C(    61602834), -INT32_C(         263),            INT32_MIN } },
    { { -INT32_C(  1923793596),  INT32_C(  1033569325), -INT32_C(  1273114460), -INT32_C(  1909695076) },
      {  INT32_C(          16), -INT32_C(           9), -INT32_C(           8), -INT32_C(          29) },
      {  INT32_C(  1027866624),  INT32_C(     2018690), -INT32_C(     4973104), -INT32_C(           4) } },
    { { -INT32_C(  1491295367),  INT32_C(  1273280423),  INT32_C(   620691848), -INT32_C(  1062065314) },
      {  INT32_C(          21),  INT32_C(           6), -INT32_C(          24),  INT32_C(          29) },
      {  INT32_C(  1864368128), -INT32_C(   114431552),  INT32_C(          36), -INT32_C(  1073741824) } },
    { { -INT32_C(  1809953555), -INT32_C(  1931541756),  INT32_C(  1672535556), -INT32_C(  1759288823) },
      {  INT32_C(          23), -INT32_C(          17), -INT32_C(           8), -INT32_C(          21) },
      {  INT32_C(  1988100096), -INT32_C(       14737),  INT32_C(     6533342), -INT32_C(         839) } },
    { { -INT32_C(   582977575),  INT32_C(  2137596026),  INT32_C(   149035518), -INT32_C(   224459397) },
      { -INT32_C(          27), -INT32_C(          28), -INT32_C(           2),  INT32_C(           4) },
      { -INT32_C(           5),  INT32_C(           7),  INT32_C(    37258879),  INT32_C(   703616944) } },
    { { -INT32_C(  1091574461),  INT32_C(    71129093), -INT32_C(   334749839),  INT32_C(  1373547300) },
      { -INT32_C(           7),  INT32_C(          11),  INT32_C(           6), -INT32_C(           2) },
      { -INT32_C(     8527926), -INT32_C(   356505600),  INT32_C(    50846784),  INT32_C(   343386825) } },
    { { -INT32_C(  1212670798), -INT32_C(   440666764),  INT32_C(   953272084), -INT32_C(  1416974221) },
      { -INT32_C(          12), -INT32_C(          31), -INT32_C(          22), -INT32_C(          23) },
      { -INT32_C(      296063), -INT32_C(           1),  INT32_C(         227), -INT32_C(         169) } },
    { {  INT32_C(  1599953899),  INT32_C(  1682184528),  INT32_C(  1402803680), -INT32_C(  1543624763) },
      {  INT32_C(          14), -INT32_C(          30), -INT32_C(          28),  INT32_C(           7) },
      {  INT32_C(  1459273728),  INT32_C(           1),  INT32_C(           5), -INT32_C(    15474048) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_sha_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_srai_epi32(simde_test_x86_random_i32x4(), 26);
    simde__m128i r = simde_mm_sha_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_sha_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 8221108173063482573),  INT64_C( 4845837656533272023) },
      {  INT64_C(                   3), -INT64_C(                  30) },
      {  INT64_C( 8018110910330345880),  INT64_C(          4513038002) } },
    { {  INT64_C(  961305450510644510), -INT64_C( 8812443758950205245) },
      { -INT64_C(                  29),  INT64_C(                  12) },
      {  INT64_C(          1790570934),  INT64_C( 4508515589551828992) } },
    { { -INT64_C( 6151448808215369635), -INT64_C( 3278957846999708703) },
      {  INT64_C(                  56),  INT64_C(                   5) },
      {  INT64_C( 6701356245527298048),  INT64_C( 5753813338266631200) } },
    { { -INT64_C( 3451738709977447032), -INT64_C(  123770926729252287) },
      {  INT64_C(                  60),  INT64_C(                   3) },
      {                     INT64_MIN, -INT64_C(  990167413834018296) } },
    { {  INT64_C( 2263339044755073193), -INT64_C( 4094091507247271888) },
      { -INT64_C(                  31),  INT64_C(                   3) },
      {  INT64_C(          1053949373),  INT64_C( 4140756089440928128) } },
    { {  INT64_C( 5500381801624903000), -INT64_C( 8739328771901035912) },
      { -INT64_C(                  18), -INT64_C(                  59) },
      {  INT64_C(      20982291418552), -INT64_C(                  16) } },
    { { -INT64_C( 3312094770503019871),  INT64_C( 8524321440793789949) },
      {  INT64_C(                  20), -INT64_C(                   7) },
      {  INT64_C( 3867426396428042240),  INT64_C(   66596261256201483) } },
    { {  INT64_C( 8596504695728662048), -INT64_C(  642457255756951952) },
      { -INT64_C(                  30), -INT64_C(                  57) },
      {  INT64_C(          8006118885), -INT64_C(                   5) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_sha_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_cvtepi32_epi64(simde_mm_srai_epi32(simde_test_x86_random_i32x4(), 25));
    simde__m128i r = simde_mm_sha_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_shl_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  40), -INT8_C(  16),  INT8_C(  92), -INT8_C(  19), -INT8_C(  16),  INT8_C(  53),  INT8_C(  44), -INT8_C(  29),
         INT8_C(  29), -INT8_C(  62), -INT8_C( 120),  INT8_C(   6),  INT8_C(  80), -INT8_C( 106),  INT8_C(   4), -INT8_C(  23) },
      { -INT8_C(   6), -INT8_C(   3), -INT8_C(   2), -INT8_C(   6), -INT8_C(   3),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   2),  INT8_C(   7), -INT8_C(   7),  INT8_C(   5),  INT8_C(   2), -INT8_C(   6), -INT8_C(   5),  INT8_C(   6) },
      {  INT8_C(   3),  INT8_C(  30),  INT8_C(  23),  INT8_C(   3),  INT8_C(  30), -INT8_C(  44),  INT8_C(  44), -INT8_C(  29),
         INT8_C(   7),  INT8_C(   0),  INT8_C(   1), -INT8_C(  64),  INT8_C(  64),  INT8_C(   2),  INT8_C(   0),  INT8_C(  64) } },
    { {  INT8_C(  83),  INT8_C(  87), -INT8_C(  90), -INT8_C( 102),  INT8_C(  74),  INT8_C(   6),  INT8_C(  30), -INT8_C(  33),
        -INT8_C(  80),  INT8_C( 110),  INT8_C(  82),  INT8_C(  66), -INT8_C(  54), -INT8_C( 106), -INT8_C(  73), -INT8_C(  78) },
      { -INT8_C(   5),  INT8_C(   4), -INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2), -INT8_C(   3),  INT8_C(   1),
         INT8_C(   6), -INT8_C(   7), -INT8_C(   5), -INT8_C(   7), -INT8_C(   4), -INT8_C(   7),  INT8_C(   7),  INT8_C(   5) },
      {  INT8_C(   2),  INT8_C( 112),  INT8_C(  20), -INT8_C( 102),  INT8_C(  74),  INT8_C(  24),  INT8_C(   3), -INT8_C(  66),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(  12),  INT8_C(   1),      INT8_MIN,  INT8_C(  64) } },
    { {  INT8_C(  96),  INT8_C(  69), -INT8_C( 105), -INT8_C( 111),  INT8_C(   3), -INT8_C(   8), -INT8_C(  20), -INT8_C( 121),
        -INT8_C( 127), -INT8_C(  93), -INT8_C(  67), -INT8_C(  36),  INT8_C( 110),  INT8_C(  90),  INT8_C(  97), -INT8_C(  40) },
      {  INT8_C(   2),  INT8_C(   2), -INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   2),
         INT8_C(   4), -INT8_C(   5),  INT8_C(   7), -INT8_C(   2),  INT8_C(   3),  INT8_C(   0), -INT8_C(   2),  INT8_C(   5) },
      {      INT8_MIN,  INT8_C(  20),  INT8_C(   2), -INT8_C( 111),  INT8_C(   3), -INT8_C(   8),  INT8_C(   0),  INT8_C(  28),
         INT8_C(  16),  INT8_C(   5),      INT8_MIN,  INT8_C(  55),  INT8_C( 112),  INT8_C(  90),  INT8_C(  24),  INT8_C(   0) } },
    { {  INT8_C(  40),  INT8_C(  68), -INT8_C( 105), -INT8_C( 100), -INT8_C(  60),  INT8_C(  19),  INT8_C( 126),  INT8_C(  35),
        -INT8_C(  75), -INT8_C(  20),  INT8_C(  49), -INT8_C( 102), -INT8_C(  29), -INT8_C(  23), -INT8_C(  24), -INT8_C(  92) },
      {  INT8_C(   7),  INT8_C(   4),  INT8_C(   5), -INT8_C(   7),  INT8_C(   4), -INT8_C(   3),  INT8_C(   1),  INT8_C(   3),
         INT8_C(   2),  INT8_C(   1),  INT8_C(   7), -INT8_C(   6),  INT8_C(   0), -INT8_C(   7),  INT8_C(   0), -INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(  64), -INT8_C(  32),  INT8_C(   1),  INT8_C(  64),  INT8_C(   2), -INT8_C(   4),  INT8_C(  24),
        -INT8_C(  44), -INT8_C(  40),      INT8_MIN,  INT8_C(   2), -INT8_C(  29),  INT8_C(   1), -INT8_C(  24),  INT8_C(   1) } },
    { { -INT8_C(  45), -INT8_C(  37),  INT8_C(  14), -INT8_C( 127),  INT8_C(  53),  INT8_C(  96), -INT8_C(  68), -INT8_C(   5),
         INT8_C( 119), -INT8_C(  50),  INT8_C(  22),  INT8_C(  70), -INT8_C(  47),  INT8_C(  76),  INT8_C(  54),  INT8_C(  94) },
      {  INT8_C(   1),  INT8_C(   2),  INT8_C(   6),  INT8_C(   4),  INT8_C(   3), -INT8_C(   4),  INT8_C(   5), -INT8_C(   4),
         INT8_C(   1), -INT8_C(   4), -INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   6),  INT8_C(   7), -INT8_C(   3) },
      { -INT8_C(  90),  INT8_C( 108),      INT8_MIN,  INT8_C(  16), -INT8_C(  88),  INT8_C(   6),      INT8_MIN,  INT8_C(  15),
        -INT8_C(  18),  INT8_C(  12),  INT8_C(   2),  INT8_C(  48), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(  11) } },
    { { -INT8_C( 120), -INT8_C( 109),  INT8_C( 100),  INT8_C(   9), -INT8_C(   3), -INT8_C(  26), -INT8_C( 113),  INT8_C(  86),
        -INT8_C(  19), -INT8_C(  45), -INT8_C(  44), -INT8_C(  90), -INT8_C(  30), -INT8_C( 119),  INT8_C(  49),  INT8_C(  78) },
      { -INT8_C(   3), -INT8_C(   5),  INT8_C(   3), -INT8_C(   1), -INT8_C(   6),  INT8_C(   1),  INT8_C(   0),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3), -INT8_C(   5), -INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(  17),  INT8_C(   4),  INT8_C(  32),  INT8_C(   4),  INT8_C(   3), -INT8_C(  52), -INT8_C( 113),  INT8_C(  96),
        -INT8_C(  19),  INT8_C(  96),      INT8_MIN, -INT8_C(  90),  INT8_C(  16),  INT8_C(   4),  INT8_C(  24),  INT8_C(  78) } },
    { {  INT8_C( 111), -INT8_C(  14),  INT8_C(   1), -INT8_C(   4), -INT8_C(  60), -INT8_C(  82), -INT8_C(  35),  INT8_C( 126),
         INT8_C(  63), -INT8_C( 126), -INT8_C(  45), -INT8_C( 125), -INT8_C(  68), -INT8_C(  86), -INT8_C(  61), -INT8_C(  69) },
      {  INT8_C(   2), -INT8_C(   4), -INT8_C(   3),  INT8_C(   4),  INT8_C(   5), -INT8_C(   4),  INT8_C(   3), -INT8_C(   4),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   4),  INT8_C(   6), -INT8_C(   1),  INT8_C(   2),  INT8_C(   4),  INT8_C(   0) },
      { -INT8_C(  68),  INT8_C(  15),  INT8_C(   0), -INT8_C(  64),      INT8_MIN,  INT8_C(  10), -INT8_C(  24),  INT8_C(   7),
         INT8_C(  63),  INT8_C(  32),  INT8_C(  48), -INT8_C(  64),  INT8_C(  94), -INT8_C(  88),  INT8_C(  48), -INT8_C(  69) } },
    { { -INT8_C(  79), -INT8_C( 126),  INT8_C(  77),  INT8_C(  34),  INT8_C(  52), -INT8_C(  66), -INT8_C( 112), -INT8_C(  71),
        -INT8_C( 106),  INT8_C(  99),  INT8_C( 123), -INT8_C(  92),  INT8_C(   7), -INT8_C(  74), -INT8_C(  45), -INT8_C(  17) },
      {  INT8_C(   1), -INT8_C(   7),  INT8_C(   6), -INT8_C(   6), -INT8_C(   7), -INT8_C(   5),  INT8_C(   7),  INT8_C(   4),
         INT8_C(   0),  INT8_C(   1),  INT8_C(   7),  INT8_C(   6),  INT8_C(   4), -INT8_C(   7), -INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(  98),  INT8_C(   1),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0), -INT8_C( 112),
        -INT8_C( 106), -INT8_C(  58),      INT8_MIN,  INT8_C(   0),  INT8_C( 112),  INT8_C(   1),  INT8_C(  52),  INT8_C( 119) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_shl_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();

    simde__m128i nmask = simde_mm_cmplt_epi8(b, simde_mm_setzero_si128());
    b = simde_mm_and_si128(b, simde_mm_set1_epi8(7));
    b = simde_mm_or_si128(simde_mm_and_si128(nmask, simde_mm_sub_epi8(simde_mm_setzero_si128(), b)), simde_mm_andnot_si128(nmask, b));

    simde__m128i r = simde_mm_shl_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_shl_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 13450),  INT16_C( 17329),  INT16_C(  8435),  INT16_C( 20622), -INT16_C(   230), -INT16_C( 11467), -INT16_C( 18836),  INT16_C( 12360) },
      {  INT16_C(    12),  INT16_C(     6),  INT16_C(     1),  INT16_C(     9), -INT16_C(    10), -INT16_C(     8),  INT16_C(     3), -INT16_C(    14) },
      {  INT16_C( 24576), -INT16_C(  5056),  INT16_C( 16870),  INT16_C(  7168),  INT16_C(    63),  INT16_C(   211), -INT16_C( 19616),  INT16_C(     0) } },
    { {  INT16_C( 21733),  INT16_C(  9875), -INT16_C(  9047), -INT16_C( 29759), -INT16_C(  8718), -INT16_C( 10649), -INT16_C( 20078), -INT16_C( 14580) },
      { -INT16_C(    12), -INT16_C(    12), -INT16_C(     2),  INT16_C(    14),  INT16_C(     5),  INT16_C(     7),  INT16_C(    14), -INT16_C(     6) },
      {  INT16_C(     5),  INT16_C(     2),  INT16_C( 14122),  INT16_C( 16384), -INT16_C( 16832),  INT16_C( 13184),       INT16_MIN,  INT16_C(   796) } },
    { { -INT16_C( 23257), -INT16_C( 27556), -INT16_C(  1793), -INT16_C( 20209), -INT16_C( 31161),  INT16_C( 30331), -INT16_C( 20701), -INT16_C(  1018) },
      { -INT16_C(     3),  INT16_C(     0), -INT16_C(     8),  INT16_C(     5),  INT16_C(     5),  INT16_C(     7), -INT16_C(     5), -INT16_C(     6) },
      {  INT16_C(  5284), -INT16_C( 27556),  INT16_C(   248),  INT16_C(  8672), -INT16_C( 14112),  INT16_C( 15744),  INT16_C(  1401),  INT16_C(  1008) } },
    { {  INT16_C( 18019),  INT16_C( 21877),  INT16_C( 32412),  INT16_C(  3170), -INT16_C( 32704),  INT16_C( 31703), -INT16_C( 17980),  INT16_C(  5662) },
      { -INT16_C(     8),  INT16_C(     3), -INT16_C(    16), -INT16_C(     9),  INT16_C(     7),  INT16_C(    15),  INT16_C(     9), -INT16_C(     5) },
      {  INT16_C(    70), -INT16_C( 21592),  INT16_C(     0),  INT16_C(     6),  INT16_C(  8192),       INT16_MIN, -INT16_C( 30720),  INT16_C(   176) } },
    { { -INT16_C( 16190),  INT16_C( 12612),  INT16_C( 29994), -INT16_C(  7519),  INT16_C( 21766), -INT16_C( 21019), -INT16_C( 10977),  INT16_C( 24380) },
      { -INT16_C(     8), -INT16_C(    11),  INT16_C(     6),  INT16_C(    13), -INT16_C(     2), -INT16_C(     7), -INT16_C(     6),  INT16_C(     6) },
      {  INT16_C(   192),  INT16_C(     6),  INT16_C( 19072),  INT16_C(  8192),  INT16_C(  5441),  INT16_C(   347),  INT16_C(   852), -INT16_C( 12544) } },
    { { -INT16_C( 26260), -INT16_C(  4045), -INT16_C(  6578),  INT16_C( 31924), -INT16_C( 29504), -INT16_C( 11253),  INT16_C(  3804),  INT16_C(  7496) },
      {  INT16_C(    11), -INT16_C(    15), -INT16_C(     4), -INT16_C(    16), -INT16_C(     7), -INT16_C(     1),  INT16_C(    15),  INT16_C(     4) },
      {  INT16_C( 24576),  INT16_C(     1),  INT16_C(  3684),  INT16_C(     0),  INT16_C(   281),  INT16_C( 27141),  INT16_C(     0), -INT16_C( 11136) } },
    { {  INT16_C( 23688),  INT16_C( 22953), -INT16_C( 10062),  INT16_C(  8834), -INT16_C( 20841), -INT16_C( 18509),  INT16_C( 27043), -INT16_C( 26326) },
      {  INT16_C(     4),  INT16_C(    14), -INT16_C(    13),  INT16_C(     8),  INT16_C(    11), -INT16_C(     8),  INT16_C(     9), -INT16_C(     1) },
      { -INT16_C( 14208),  INT16_C( 16384),  INT16_C(     6), -INT16_C( 32256), -INT16_C( 18432),  INT16_C(   183),  INT16_C( 17920),  INT16_C( 19605) } },
    { { -INT16_C( 29121),  INT16_C( 13582),  INT16_C( 21502),  INT16_C(  7157),  INT16_C( 17075),  INT16_C(  8004), -INT16_C(  4070),  INT16_C(  7115) },
      { -INT16_C(    12),  INT16_C(     6),  INT16_C(    11),  INT16_C(     0),  INT16_C(     3), -INT16_C(     1),  INT16_C(     9), -INT16_C(     1) },
      {  INT16_C(     8),  INT16_C( 17280), -INT16_C(  4096),  INT16_C(  7157),  INT16_C(  5528),  INT16_C(  4002),  INT16_C( 13312),  INT16_C(  3557) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_shl_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_srai_epi16(simde_test_x86_random_i16x8(), 11);
    simde__m128i r = simde_mm_shl_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_shl_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   506189050), -INT32_C(  1680558282),  INT32_C(  2102138628), -INT32_C(  2040021441) },
      {  INT32_C(          31),  INT32_C(          14),  INT32_C(          24),  INT32_C(           6) },
      {  INT32_C(           0),  INT32_C(   768442368),  INT32_C(    67108864), -INT32_C(  1712353344) } },
    { { -INT32_C(   755302501), -INT32_C(  1167208778),  INT32_C(   624474598), -INT32_C(  2035572872) },
      { -INT32_C(           8), -INT32_C(          26),  INT32_C(          27),  INT32_C(           0) },
      {  INT32_C(    13826815),  INT32_C(          46),  INT32_C(   805306368), -INT32_C(  2035572872) } },
    { { -INT32_C(   539656151),  INT32_C(   899236431),  INT32_C(  1952109052),  INT32_C(  2063206001) },
      { -INT32_C(          27),  INT32_C(          21), -INT32_C(          11), -INT32_C(          32) },
      {  INT32_C(          27),  INT32_C(  1239416832),  INT32_C(      953178),  INT32_C(           0) } },
    { {  INT32_C(   442674635), -INT32_C(   347079441),  INT32_C(  1046456781),  INT32_C(   666458799) },
      {  INT32_C(          21), -INT32_C(           4),  INT32_C(          30), -INT32_C(          31) },
      { -INT32_C(  1184890880),  INT32_C(   246742990),  INT32_C(  1073741824),  INT32_C(           0) } },
    { {  INT32_C(  1000300364),  INT32_C(   690482779),  INT32_C(  1197967000),  INT32_C(   980295904) },
      { -INT32_C(          18),  INT32_C(          14),  INT32_C(          25),  INT32_C(          24) },
      {  INT32_C(        3815), -INT32_C(    74006528),  INT32_C(   805306368), -INT32_C(   536870912) } },
    { {  INT32_C(  1788709647),  INT32_C(   294896761),  INT32_C(   727317322),  INT32_C(  1332070171) },
      {  INT32_C(           3), -INT32_C(          10),  INT32_C(          17), -INT32_C(          19) },
      {  INT32_C(  1424775288),  INT32_C(      287985), -INT32_C(   158072832),  INT32_C(        2540) } },
    { {  INT32_C(   824263864),  INT32_C(  1396946184), -INT32_C(   880894800),  INT32_C(  1444668259) },
      {  INT32_C(           1),  INT32_C(           4),  INT32_C(          18),  INT32_C(           2) },
      {  INT32_C(  1648527728),  INT32_C(   876302464),  INT32_C(  1925185536),  INT32_C(  1483705740) } },
    { {  INT32_C(  1262166594), -INT32_C(  2019655977),  INT32_C(  2102598682), -INT32_C(   690721025) },
      {  INT32_C(          29), -INT32_C(          32),  INT32_C(          13),  INT32_C(           6) },
      {  INT32_C(  1073741824), -INT32_C(           0),  INT32_C(  1669545984), -INT32_C(  1256472640) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_shl_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_srai_epi32(simde_test_x86_random_i32x4(), 26);
    simde__m128i r = simde_mm_shl_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_shl_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 1391336280736300016), -INT64_C( 6559944687295028704) },
      {  INT64_C(                  62),  INT64_C(                  61) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C(  541940659597814931),  INT64_C( 1007413717779286854) },
      {  INT64_C(                  59),  INT64_C(                  20) },
      {  INT64_C( 7493989779944505344), -INT64_C( 2952846843981070336) } },
    { { -INT64_C( 4789328101045054279), -INT64_C( 8112091591502159633) },
      { -INT64_C(                  23), -INT64_C(                  19) },
      {  INT64_C(       1628090855200),  INT64_C(      19711785282530) } },
    { {  INT64_C( 7734700898225788962), -INT64_C( 7131107535778845747) },
      { -INT64_C(                  40), -INT64_C(                  49) },
      {  INT64_C(             7034669),  INT64_C(               20100) } },
    { { -INT64_C( 1262209519863925612), -INT64_C( 6179375759096265433) },
      { -INT64_C(                  61), -INT64_C(                   3) },
      {  INT64_C(                   7),  INT64_C( 1533421039326660772) } },
    { { -INT64_C(  682282357267360903), -INT64_C( 1983599911717310127) },
      { -INT64_C(                  49), -INT64_C(                   6) },
      {  INT64_C(               31556),  INT64_C(  257236627531128773) } },
    { { -INT64_C( 2710056978198528354),  INT64_C( 6136472046163000034) },
      { -INT64_C(                  43), -INT64_C(                  47) },
      {  INT64_C(             1789054),  INT64_C(               43602) } },
    { { -INT64_C( 5052911414569539972), -INT64_C( 7308454166727325587) },
      { -INT64_C(                  17),  INT64_C(                  55) },
      {  INT64_C(     102186833642120),  INT64_C( 3927138875067072512) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_shl_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_cvtepi32_epi64(simde_mm_srai_epi32(simde_test_x86_random_i32x4(), 25));
    simde__m128i r = simde_mm_shl_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_rot_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  40), -INT8_C(  46),  INT8_C(  71),  INT8_C( 124),  INT8_C(  83), -INT8_C(  38), -INT8_C(  51),  INT8_C(  79),
        -INT8_C(  23),  INT8_C(  46), -INT8_C(  45),  INT8_C( 115),  INT8_C(  24),  INT8_C(  13),  INT8_C(  46), -INT8_C(  68) },
      {  INT8_C(   6), -INT8_C(   2),  INT8_C(   6),  INT8_C(   2),  INT8_C(   0), -INT8_C(   4), -INT8_C(   2),  INT8_C(   1),
         INT8_C(   6),  INT8_C(   0),  INT8_C(   4),  INT8_C(   7), -INT8_C(   3), -INT8_C(   3),  INT8_C(   0),  INT8_C(   6) },
      {  INT8_C(  10), -INT8_C(  76), -INT8_C(  47), -INT8_C(  15),  INT8_C(  83), -INT8_C(  83),  INT8_C( 115), -INT8_C(  98),
         INT8_C( 122),  INT8_C(  46),  INT8_C(  61), -INT8_C(  71),  INT8_C(   3), -INT8_C(  95),  INT8_C(  46),  INT8_C(  47) } },
    { {  INT8_C( 116), -INT8_C(  62), -INT8_C(  13),  INT8_C(   3),  INT8_C(  31),  INT8_C(  85), -INT8_C(  63),  INT8_C(  69),
        -INT8_C( 114), -INT8_C(  92),  INT8_C(  63), -INT8_C(  54),  INT8_C(  68), -INT8_C(   8),  INT8_C(  35), -INT8_C(  66) },
      { -INT8_C(   7), -INT8_C(   5),  INT8_C(   1), -INT8_C(   6), -INT8_C(   7), -INT8_C(   6), -INT8_C(   7), -INT8_C(   4),
        -INT8_C(   5), -INT8_C(   2), -INT8_C(   3),  INT8_C(   3),  INT8_C(   7),  INT8_C(   6), -INT8_C(   3), -INT8_C(   6) },
      { -INT8_C(  24),  INT8_C(  22), -INT8_C(  25),  INT8_C(  12),  INT8_C(  62),  INT8_C(  85), -INT8_C( 125),  INT8_C(  84),
         INT8_C( 116),  INT8_C(  41), -INT8_C(  25),  INT8_C(  86),  INT8_C(  34),  INT8_C(  62),  INT8_C( 100), -INT8_C(   6) } },
    { {  INT8_C(  84),  INT8_C(  59),  INT8_C(  70), -INT8_C(  44),  INT8_C(  75), -INT8_C(  15), -INT8_C( 111), -INT8_C(  25),
         INT8_C( 113), -INT8_C(  92),  INT8_C(  76),  INT8_C( 125), -INT8_C( 102), -INT8_C(  90),  INT8_C(  14),  INT8_C(  30) },
      {  INT8_C(   7),  INT8_C(   5),  INT8_C(   6),  INT8_C(   0), -INT8_C(   1),  INT8_C(   6), -INT8_C(   4),  INT8_C(   7),
         INT8_C(   5),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(  42),  INT8_C( 103), -INT8_C( 111), -INT8_C(  44), -INT8_C(  91),  INT8_C( 124),  INT8_C(  25), -INT8_C(  13),
         INT8_C(  46), -INT8_C( 110),  INT8_C(  76),  INT8_C( 125),  INT8_C(  53), -INT8_C(  90),  INT8_C(  28),  INT8_C(  30) } },
    { { -INT8_C(  18), -INT8_C(  60), -INT8_C(  88), -INT8_C(  71),  INT8_C( 126), -INT8_C(  74),  INT8_C(  38),  INT8_C( 125),
        -INT8_C(  73), -INT8_C(  74),  INT8_C(  98),  INT8_C(  86), -INT8_C(  63),  INT8_C(  31), -INT8_C(  40),  INT8_C(  37) },
      {  INT8_C(   5), -INT8_C(   1),  INT8_C(   7), -INT8_C(   1), -INT8_C(   7), -INT8_C(   3),  INT8_C(   2),  INT8_C(   2),
         INT8_C(   5),  INT8_C(   0),  INT8_C(   1),  INT8_C(   6),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   4) },
      { -INT8_C(  35),  INT8_C(  98),  INT8_C(  84), -INT8_C(  36), -INT8_C(   4), -INT8_C(  42), -INT8_C( 104), -INT8_C(  11),
        -INT8_C(  10), -INT8_C(  74), -INT8_C(  60), -INT8_C( 107), -INT8_C(  63),  INT8_C( 124), -INT8_C(  40),  INT8_C(  82) } },
    { {  INT8_C( 106), -INT8_C(  27), -INT8_C( 127),  INT8_C( 120),  INT8_C(  96), -INT8_C(  83),  INT8_C( 102),  INT8_C(  79),
        -INT8_C( 117),  INT8_C(  98), -INT8_C(  23),  INT8_C(  27),  INT8_C(  98),  INT8_C( 107),  INT8_C( 103),  INT8_C(  24) },
      {  INT8_C(   2), -INT8_C(   1),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5), -INT8_C(   7),  INT8_C(   5),
         INT8_C(   6), -INT8_C(   5),  INT8_C(   0), -INT8_C(   5), -INT8_C(   4),  INT8_C(   3), -INT8_C(   2), -INT8_C(   2) },
      { -INT8_C(  87), -INT8_C(  14),  INT8_C(   6),  INT8_C( 120),  INT8_C(  96),  INT8_C( 109), -INT8_C(  52), -INT8_C(  23),
        -INT8_C(  30),  INT8_C(  19), -INT8_C(  23), -INT8_C(  40),  INT8_C(  38),  INT8_C(  91), -INT8_C(  39),  INT8_C(   6) } },
    { { -INT8_C(  15),  INT8_C(  38),  INT8_C(  57), -INT8_C(  38), -INT8_C( 102), -INT8_C(  35),  INT8_C(  58), -INT8_C(  92),
         INT8_C(  19),  INT8_C(  49),  INT8_C(  73), -INT8_C( 107),  INT8_C(  36), -INT8_C( 109), -INT8_C(  91),  INT8_C(  66) },
      {  INT8_C(   5), -INT8_C(   6),  INT8_C(   1),  INT8_C(   7),  INT8_C(   5), -INT8_C(   5),  INT8_C(   4), -INT8_C(   7),
        -INT8_C(   7),  INT8_C(   0), -INT8_C(   3),  INT8_C(   4), -INT8_C(   6),  INT8_C(   3),  INT8_C(   6), -INT8_C(   2) },
      {  INT8_C(  62), -INT8_C( 104),  INT8_C( 114),  INT8_C( 109),  INT8_C(  83), -INT8_C(  18), -INT8_C(  93),  INT8_C(  73),
         INT8_C(  38),  INT8_C(  49),  INT8_C(  41),  INT8_C(  89), -INT8_C( 112), -INT8_C( 100),  INT8_C( 105), -INT8_C( 112) } },
    { { -INT8_C(  85),  INT8_C(  16),  INT8_C(  56), -INT8_C(  89), -INT8_C(  44),  INT8_C(  79), -INT8_C( 118), -INT8_C(  58),
         INT8_C( 119), -INT8_C(  86), -INT8_C(  21), -INT8_C( 116), -INT8_C(  80), -INT8_C(  98),  INT8_C( 121), -INT8_C(  22) },
      { -INT8_C(   7),  INT8_C(   6), -INT8_C(   3), -INT8_C(   4),  INT8_C(   5),  INT8_C(   2), -INT8_C(   2),  INT8_C(   1),
         INT8_C(   1), -INT8_C(   1), -INT8_C(   4), -INT8_C(   5),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3), -INT8_C(   3) },
      {  INT8_C(  87),  INT8_C(   4),  INT8_C(   7),  INT8_C( 122), -INT8_C( 102),  INT8_C(  61), -INT8_C(  94), -INT8_C( 115),
        -INT8_C(  18),  INT8_C(  85), -INT8_C(  66),  INT8_C( 100),  INT8_C(  44), -INT8_C(  12), -INT8_C(  53),  INT8_C(  93) } },
    { { -INT8_C(  65),  INT8_C(  42), -INT8_C(  26), -INT8_C(  89), -INT8_C(  75),  INT8_C(   9),  INT8_C(  63), -INT8_C(   5),
        -INT8_C(  32),  INT8_C(  86),  INT8_C(  53), -INT8_C(  56), -INT8_C(  83), -INT8_C( 108), -INT8_C(  54),  INT8_C(  87) },
      {  INT8_C(   7), -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   5),  INT8_C(   7), -INT8_C(   3),
        -INT8_C(   3),  INT8_C(   1), -INT8_C(   2),  INT8_C(   6),  INT8_C(   3), -INT8_C(   2), -INT8_C(   3),  INT8_C(   6) },
      { -INT8_C(  33), -INT8_C(  94), -INT8_C(  26), -INT8_C(  89),  INT8_C( 107),  INT8_C(  33), -INT8_C(  97),      INT8_MAX,
         INT8_C(  28), -INT8_C(  84),  INT8_C(  77),  INT8_C(  50),  INT8_C( 109),  INT8_C(  37),  INT8_C(  89), -INT8_C(  43) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_rot_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();

    simde__m128i nmask = simde_mm_cmplt_epi8(b, simde_mm_setzero_si128());
    b = simde_mm_and_si128(b, simde_mm_set1_epi8(7));
    b = simde_mm_or_si128(simde_mm_and_si128(nmask, simde_mm_sub_epi8(simde_mm_setzero_si128(), b)), simde_mm_andnot_si128(nmask, b));

    simde__m128i r = simde_mm_rot_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_rot_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(   939), -INT16_C( 24148),  INT16_C(  5606), -INT16_C( 29633), -INT16_C( 17546),  INT16_C(  4240),  INT16_C( 32196), -INT16_C( 11646) },
      { -INT16_C(     9), -INT16_C(     4), -INT16_C(    10), -INT16_C(     4), -INT16_C(    10),  INT16_C(    14), -INT16_C(     9), -INT16_C(    10) },
      {  INT16_C( 11006), -INT16_C( 13798),  INT16_C( 31109), -INT16_C(  1853), -INT16_C(  8786),  INT16_C(  1060), -INT16_C(  7618), -INT16_C( 24396) } },
    { {  INT16_C(  3991),  INT16_C( 24560),  INT16_C( 31503), -INT16_C( 16012),  INT16_C( 25440),  INT16_C( 11621),  INT16_C( 25245), -INT16_C( 23672) },
      {  INT16_C(     0), -INT16_C(    11), -INT16_C(     7), -INT16_C(    16),  INT16_C(    14), -INT16_C(    16),  INT16_C(    15), -INT16_C(    11) },
      {  INT16_C(  3991), -INT16_C(   501),  INT16_C(  7926), -INT16_C( 16012),  INT16_C(  6360),  INT16_C( 11621), -INT16_C( 20146),  INT16_C( 28948) } },
    { { -INT16_C(  5461), -INT16_C( 22757),  INT16_C( 16855), -INT16_C(  7739), -INT16_C( 10553), -INT16_C(  6118),  INT16_C( 19167),  INT16_C(  4804) },
      {  INT16_C(    10),  INT16_C(    12), -INT16_C(     8), -INT16_C(     9), -INT16_C(     9),  INT16_C(     2),  INT16_C(     9),  INT16_C(    12) },
      { -INT16_C( 20566), -INT16_C( 17807), -INT16_C( 10431), -INT16_C(  7440),  INT16_C( 25579), -INT16_C( 24469), -INT16_C( 16747),  INT16_C( 16684) } },
    { {  INT16_C(  5817),  INT16_C( 17046),  INT16_C( 29158),  INT16_C( 13849), -INT16_C( 25902),  INT16_C(  1817),  INT16_C( 15922),  INT16_C( 26398) },
      {  INT16_C(     7), -INT16_C(     6), -INT16_C(    11), -INT16_C(     8),  INT16_C(     3), -INT16_C(     2),  INT16_C(     4),  INT16_C(     4) },
      {  INT16_C( 23691),  INT16_C( 22794),  INT16_C( 15566),  INT16_C(  6454), -INT16_C( 10604),  INT16_C( 16838), -INT16_C(  7389),  INT16_C( 29158) } },
    { {  INT16_C(  6634), -INT16_C(  1848),  INT16_C(  4837),  INT16_C(  1626),  INT16_C( 14762),  INT16_C( 21192),  INT16_C( 17728), -INT16_C(  5762) },
      {  INT16_C(     7), -INT16_C(     8), -INT16_C(    15), -INT16_C(     3),  INT16_C(     3), -INT16_C(     5),  INT16_C(     3),  INT16_C(     7) },
      { -INT16_C(  2804), -INT16_C( 14088),  INT16_C(  9674),  INT16_C( 16587), -INT16_C( 12975),  INT16_C( 17046),  INT16_C( 10754), -INT16_C( 16524) } },
    { {  INT16_C( 32101), -INT16_C( 28648),  INT16_C( 11644), -INT16_C( 26001),  INT16_C( 15222), -INT16_C( 27759),  INT16_C( 26542), -INT16_C(  7732) },
      { -INT16_C(     4), -INT16_C(     1),  INT16_C(    12),  INT16_C(    15),  INT16_C(     8), -INT16_C(    12),  INT16_C(     5), -INT16_C(     3) },
      {  INT16_C( 22486),  INT16_C( 18444), -INT16_C( 15657), -INT16_C( 13001),  INT16_C( 30267),  INT16_C( 14617), -INT16_C(  2612), -INT16_C( 25543) } },
    { { -INT16_C( 13997), -INT16_C( 11024), -INT16_C( 13998),  INT16_C( 14912),  INT16_C(  9823), -INT16_C( 28453), -INT16_C( 21465), -INT16_C( 26640) },
      { -INT16_C(     9),  INT16_C(     7),  INT16_C(     8), -INT16_C(     9),  INT16_C(     2),  INT16_C(     1),  INT16_C(    12),  INT16_C(    15) },
      { -INT16_C( 22044),  INT16_C( 30826),  INT16_C( 21193),  INT16_C(  8221), -INT16_C( 26244),  INT16_C(  8631),  INT16_C( 31426),  INT16_C( 19448) } },
    { { -INT16_C( 31012), -INT16_C( 30025), -INT16_C(  4592),  INT16_C( 11701), -INT16_C( 31603),  INT16_C(  4621),  INT16_C(  7505),  INT16_C( 21458) },
      {  INT16_C(     8),  INT16_C(    10),  INT16_C(     5), -INT16_C(     2),  INT16_C(     4), -INT16_C(     5), -INT16_C(     6),  INT16_C(     6) },
      { -INT16_C(  9082), -INT16_C(  8662), -INT16_C( 15843),  INT16_C( 19309),  INT16_C( 18648),  INT16_C( 26768),  INT16_C( 17525), -INT16_C(  2924) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_rot_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_srai_epi16(simde_test_x86_random_i16x8(), 11);
    simde__m128i r = simde_mm_rot_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_rot_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1216512066),  INT32_C(  1579107551),  INT32_C(   618115230),  INT32_C(    73084345) },
      { -INT32_C(          28),  INT32_C(           3),  INT32_C(          15), -INT32_C(           1) },
      {  INT32_C(  2010643435), -INT32_C(   252041478), -INT32_C(   665906581), -INT32_C(  2110941476) } },
    { {  INT32_C(   850848595), -INT32_C(   846146257),  INT32_C(  1056073605),  INT32_C(   507661716) },
      {  INT32_C(           7), -INT32_C(          15),  INT32_C(          19),  INT32_C(           1) },
      {  INT32_C(  1534437785), -INT32_C(  1436574943),  INT32_C(  1009383315),  INT32_C(  1015323432) } },
    { { -INT32_C(  1925709218),  INT32_C(  1566296280), -INT32_C(   996389585),  INT32_C(   736288410) },
      { -INT32_C(          13), -INT32_C(          25),  INT32_C(           0),  INT32_C(          27) },
      {  INT32_C(   318007744), -INT32_C(  1377539026), -INT32_C(   996389585), -INT32_C(   782297356) } },
    { {  INT32_C(   301679161),  INT32_C(   980309514),  INT32_C(  1040059043), -INT32_C(   496443159) },
      {  INT32_C(           0),  INT32_C(          27), -INT32_C(           3), -INT32_C(           2) },
      {  INT32_C(   301679161),  INT32_C(  1372811952),  INT32_C(  1740620116),  INT32_C(  2023372858) } },
    { { -INT32_C(   955621956),  INT32_C(  1442937011),  INT32_C(  1821638531),  INT32_C(  1380907999) },
      { -INT32_C(          14),  INT32_C(          11),  INT32_C(          15), -INT32_C(           9) },
      {  INT32_C(  1995643945),  INT32_C(   197499568), -INT32_C(     4082103), -INT32_C(   274126979) } },
    { { -INT32_C(  1750711836),  INT32_C(  1022273465), -INT32_C(  2052554330),  INT32_C(   668465021) },
      {  INT32_C(          16), -INT32_C(          25), -INT32_C(           4), -INT32_C(           1) },
      {  INT32_C(  1105500070),  INT32_C(  2001984670),  INT32_C(  1750763546), -INT32_C(  1813251138) } },
    { {  INT32_C(   244741972), -INT32_C(  1001749474), -INT32_C(  2109082875), -INT32_C(   508944150) },
      {  INT32_C(          27), -INT32_C(          28),  INT32_C(          16),  INT32_C(          19) },
      { -INT32_C(  1602964550),  INT32_C(  1151877612), -INT32_C(   217742775),  INT32_C(   123145553) } },
    { { -INT32_C(   379726389),  INT32_C(  1605216345), -INT32_C(  2048788837),  INT32_C(  1650887446) },
      { -INT32_C(           6),  INT32_C(          16), -INT32_C(          17),  INT32_C(           7) },
      {  INT32_C(   799373143), -INT32_C(  1470537811), -INT32_C(    78789904),  INT32_C(   860195633) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_rot_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_srai_epi32(simde_test_x86_random_i32x4(), 26);
    simde__m128i r = simde_mm_rot_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_rot_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6030121911897921128), -INT64_C( 2079650662157569366) },
      {  INT64_C(                  30), -INT64_C(                  57) },
      {  INT64_C( 8953607297789340932), -INT64_C( 7940867724235156111) } },
    { {  INT64_C( 1548849507772250048),  INT64_C( 7526071637542088656) },
      { -INT64_C(                  36), -INT64_C(                  31) },
      { -INT64_C( 4821987975361992218),  INT64_C( 1994355354299004047) } },
    { {  INT64_C(   18004709759095486), -INT64_C(  263461609286003289) },
      { -INT64_C(                  34),  INT64_C(                  34) },
      {  INT64_C(  747145293120667084), -INT64_C( 5028173739009770433) } },
    { {  INT64_C( 3834259340609951493), -INT64_C(  133001585811471333) },
      { -INT64_C(                  53),  INT64_C(                  50) },
      { -INT64_C( 5749845831088330327),  INT64_C( 1184438584225868947) } },
    { {  INT64_C( 8670532492798023567),  INT64_C( 7598077189004949423) },
      {  INT64_C(                  63),  INT64_C(                  62) },
      { -INT64_C( 4888105790455764025), -INT64_C( 2712166721176150549) } },
    { {  INT64_C( 3399013202374530133),  INT64_C( 4579055370049277488) },
      { -INT64_C(                  45),  INT64_C(                  37) },
      { -INT64_C( 4324138247288948387),  INT64_C( 6069099710277374756) } },
    { { -INT64_C( 5923707415603657701), -INT64_C( 4797921855550821486) },
      {  INT64_C(                  39),  INT64_C(                  21) },
      { -INT64_C( 3719395125632057651),  INT64_C( 8053977569354558795) } },
    { {  INT64_C( 9120434576701794664), -INT64_C( 6561721854230699595) },
      {  INT64_C(                   3), -INT64_C(                   5) },
      { -INT64_C(  823499681223849149), -INT64_C( 5969661330978944243) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_rot_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_cvtepi32_epi64(simde_mm_srai_epi32(simde_test_x86_random_i32x4(), 25));
    simde__m128i r = simde_mm_rot_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_perm_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t c[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  73), -INT8_C(  12),  INT8_C( 114),  INT8_C(  74), -INT8_C(   9), -INT8_C(  65), -INT8_C(  82), -INT8_C(   5),
        -INT8_C(  11), -INT8_C(  38),  INT8_C(  95),  INT8_C(  32),  INT8_C(  32), -INT8_C(  59), -INT8_C( 104), -INT8_C(  50) },
      {  INT8_C(  79), -INT8_C(  48), -INT8_C(  13), -INT8_C( 122),  INT8_C(  13),  INT8_C(  38), -INT8_C( 124),  INT8_C(  90),
         INT8_C(  51),  INT8_C(   9),  INT8_C(  16),  INT8_C(  81), -INT8_C(  67),  INT8_C(  95),  INT8_C( 123),  INT8_C(  13) },
      { -INT8_C(  42),  INT8_C( 110),      INT8_MIN, -INT8_C(  85),  INT8_C(  53), -INT8_C(  28), -INT8_C(  91), -INT8_C(  21),
        -INT8_C(  84),  INT8_C(  26),  INT8_C( 109), -INT8_C( 111), -INT8_C(   2), -INT8_C( 103), -INT8_C(  49),  INT8_C(  11) },
      { -INT8_C(   1), -INT8_C(  26),  INT8_C(   0), -INT8_C(   1), -INT8_C(  39),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(  16),  INT8_C(  92),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(  32) } },
    { { -INT8_C(  14), -INT8_C(  34), -INT8_C(  25),  INT8_C(  83), -INT8_C(  91),  INT8_C(  90), -INT8_C(  20),  INT8_C(  23),
         INT8_C(  36), -INT8_C(  67),  INT8_C(  98),  INT8_C(  24),  INT8_C(  58),  INT8_C( 116), -INT8_C( 112), -INT8_C(  48) },
      { -INT8_C( 121),  INT8_C( 112),  INT8_C(  53),  INT8_C(  87), -INT8_C(  46),  INT8_C(  42),  INT8_C( 119), -INT8_C( 121),
        -INT8_C(  95), -INT8_C(  28),  INT8_C(  28),  INT8_C(  95),  INT8_C(   6),  INT8_C(  49), -INT8_C(   4), -INT8_C(  91) },
      { -INT8_C(  69), -INT8_C(  73), -INT8_C(  74), -INT8_C(  49),  INT8_C( 113),  INT8_C(  52), -INT8_C(  93),  INT8_C(  36),
         INT8_C( 102), -INT8_C(  65),  INT8_C(   8),  INT8_C(  31),  INT8_C(  54),  INT8_C(  81), -INT8_C( 112),  INT8_C(  20) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(  15),  INT8_C(  45), -INT8_C(   1),  INT8_C(  90),
        -INT8_C(  56), -INT8_C(   1),  INT8_C(  36), -INT8_C(  91), -INT8_C( 120),  INT8_C(  14),  INT8_C(   0), -INT8_C(  46) } },
    { { -INT8_C(  13), -INT8_C( 125), -INT8_C(   7),  INT8_C(  21),  INT8_C( 119), -INT8_C( 103),  INT8_C(  13),  INT8_C(  23),
        -INT8_C(   7), -INT8_C(  64), -INT8_C(  44),  INT8_C(  81), -INT8_C(  33), -INT8_C( 108),  INT8_C(   8), -INT8_C(  27) },
      { -INT8_C(  45), -INT8_C(  27), -INT8_C(  55), -INT8_C(  62),  INT8_C(  25), -INT8_C(  69), -INT8_C( 110), -INT8_C(  55),
         INT8_C(  32), -INT8_C( 105),  INT8_C( 108),  INT8_C(  47),  INT8_C(  87), -INT8_C(   4),  INT8_C(  97),  INT8_C(  34) },
      {  INT8_C(  65),  INT8_C(  46),  INT8_C(  52), -INT8_C(  81), -INT8_C(  52),  INT8_C(  58),  INT8_C(  79), -INT8_C(  29),
        -INT8_C(  33),  INT8_C(  54), -INT8_C(   3),  INT8_C(  48),  INT8_C(  50), -INT8_C(  54), -INT8_C(  39),  INT8_C(  19) },
      { -INT8_C(  63), -INT8_C(   9), -INT8_C(  26), -INT8_C(   1), -INT8_C(   1), -INT8_C( 109), -INT8_C(  89), -INT8_C(   1),
         INT8_C(   0),  INT8_C( 109),  INT8_C(   0),  INT8_C(  44),  INT8_C(  54), -INT8_C(   1), -INT8_C(   1), -INT8_C(  62) } },
    { {  INT8_C(  98), -INT8_C(  16), -INT8_C( 121), -INT8_C(  12),  INT8_C(  69), -INT8_C(   9), -INT8_C(  95),  INT8_C(  78),
         INT8_C( 123), -INT8_C(  50), -INT8_C(  12),  INT8_C(  15),  INT8_C(  69),      INT8_MAX, -INT8_C(  19),  INT8_C(  66) },
      { -INT8_C( 102), -INT8_C(   6),  INT8_C(  78), -INT8_C(  21),  INT8_C( 120),  INT8_C(  20),  INT8_C(  37),  INT8_C(  50),
         INT8_C( 121), -INT8_C(  49), -INT8_C(   1), -INT8_C(  60), -INT8_C(  90), -INT8_C(  36),  INT8_C(  89),  INT8_C( 119) },
      { -INT8_C( 113),  INT8_C(  94),  INT8_C(  87),  INT8_C(  45), -INT8_C( 100), -INT8_C(  15), -INT8_C(  71), -INT8_C(   6),
        -INT8_C(  98), -INT8_C(  21),  INT8_C(  10), -INT8_C( 119), -INT8_C(  87), -INT8_C(  30),  INT8_C(  26), -INT8_C(  69) },
      {  INT8_C(   0), -INT8_C( 102),  INT8_C(  76),      INT8_MIN,  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(  12),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  38),  INT8_C( 110), -INT8_C(  81), -INT8_C( 110),  INT8_C(  36),  INT8_C(  47),  INT8_C( 120),  INT8_C(  78),
        -INT8_C(  17),  INT8_C(  18),  INT8_C(  66), -INT8_C(  43), -INT8_C(  28), -INT8_C(  47),  INT8_C( 110),  INT8_C(  88) },
      { -INT8_C( 125), -INT8_C(  71), -INT8_C(  93),  INT8_C(  52), -INT8_C(  58), -INT8_C(  80), -INT8_C(  64),  INT8_C(  22),
        -INT8_C(  79),  INT8_C( 118),  INT8_C(  21),  INT8_C(  99),  INT8_C(  43),  INT8_C(  43), -INT8_C(  46), -INT8_C(  41) },
      {  INT8_C(  12),  INT8_C(  18), -INT8_C(  65),  INT8_C( 108),  INT8_C( 119), -INT8_C( 108),  INT8_C(  46),  INT8_C( 125),
         INT8_C( 106), -INT8_C( 120),  INT8_C(  47),  INT8_C(  43), -INT8_C( 109), -INT8_C(  79),  INT8_C(   2),  INT8_C(   0) },
      { -INT8_C(  28), -INT8_C(  93), -INT8_C(   1), -INT8_C(  40), -INT8_C( 105),  INT8_C(   0), -INT8_C( 111),  INT8_C(  43),
        -INT8_C(  67),  INT8_C(   0), -INT8_C(  89),  INT8_C(  42),  INT8_C(   0), -INT8_C(   1), -INT8_C(  81),  INT8_C(  38) } },
    { {  INT8_C( 102), -INT8_C( 120), -INT8_C(  46), -INT8_C(  46),  INT8_C( 108),  INT8_C(  60), -INT8_C(  96), -INT8_C(  22),
        -INT8_C(  34), -INT8_C(   8),  INT8_C( 125),  INT8_C( 102),  INT8_C( 114),  INT8_C( 100), -INT8_C(   4), -INT8_C(  36) },
      {  INT8_C( 117),  INT8_C( 110), -INT8_C(  25),  INT8_C(  64),  INT8_C(  26),  INT8_C(  74),  INT8_C(  49),  INT8_C(   8),
         INT8_C(  18), -INT8_C(  73),  INT8_C(  44), -INT8_C( 115),  INT8_C(  92), -INT8_C( 123), -INT8_C(   4), -INT8_C(  75) },
      {  INT8_C(  95),  INT8_C(  84),  INT8_C(  76), -INT8_C(  49),  INT8_C(  54), -INT8_C(  98),  INT8_C(  63), -INT8_C(  66),
         INT8_C(  75), -INT8_C(   8), -INT8_C(  87),  INT8_C(  90),  INT8_C(  39), -INT8_C( 108),      INT8_MIN,  INT8_C(  19) },
      { -INT8_C(  83),  INT8_C(  88),  INT8_C(  78), -INT8_C(   1), -INT8_C(  50),  INT8_C(   0),  INT8_C(  74), -INT8_C(   1),
         INT8_C( 102), -INT8_C(   1), -INT8_C(   1),  INT8_C(  52),  INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64) } },
    { { -INT8_C( 120),  INT8_C(  11), -INT8_C( 115), -INT8_C(  40), -INT8_C(  76),  INT8_C(  89),  INT8_C( 103),  INT8_C(  55),
         INT8_C(  14),  INT8_C(  41), -INT8_C(  94), -INT8_C(  59), -INT8_C(  25),  INT8_C(  84),  INT8_C(  68), -INT8_C(  64) },
      { -INT8_C( 106), -INT8_C(  92),  INT8_C( 120), -INT8_C(  13), -INT8_C(  53), -INT8_C(  35), -INT8_C( 121), -INT8_C(  38),
         INT8_C(  32), -INT8_C(   2),  INT8_C(   3),  INT8_C(   7), -INT8_C(  15), -INT8_C(  60),  INT8_C(  70), -INT8_C(  60) },
      {  INT8_C( 110),  INT8_C( 112),  INT8_C(  27), -INT8_C(   6), -INT8_C(  18), -INT8_C(  54), -INT8_C(  70),  INT8_C(  81),
        -INT8_C( 121),  INT8_C( 102), -INT8_C(   6), -INT8_C( 103), -INT8_C(  37),  INT8_C(  38), -INT8_C(  62),  INT8_C( 105) },
      { -INT8_C(  35), -INT8_C( 106),  INT8_C(   7), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(  37),
         INT8_C(   0),  INT8_C(  25), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104), -INT8_C(   1),  INT8_C( 107) } },
    { {  INT8_C(  52),  INT8_C(   0), -INT8_C(  64),  INT8_C(   5), -INT8_C(  44),  INT8_C(   1),  INT8_C(  94), -INT8_C( 123),
        -INT8_C( 122), -INT8_C( 110), -INT8_C(  14),  INT8_C(  52),  INT8_C( 121), -INT8_C(   5),  INT8_C(  53),  INT8_C(  55) },
      {  INT8_C(  78),  INT8_C(  37), -INT8_C(   9),  INT8_C( 111),  INT8_C( 112), -INT8_C(  92),  INT8_C(  17), -INT8_C(  96),
        -INT8_C(  92), -INT8_C(  12), -INT8_C( 102), -INT8_C(  46), -INT8_C(  31),  INT8_C(   3),  INT8_C(  94), -INT8_C(   9) },
      {  INT8_C(  97), -INT8_C(  16), -INT8_C( 117), -INT8_C(  49), -INT8_C(   8),  INT8_C(  19), -INT8_C(  82),  INT8_C(   9),
        -INT8_C(  91),  INT8_C(  61), -INT8_C(  34), -INT8_C(  85),  INT8_C( 103),  INT8_C(  65),  INT8_C(  55), -INT8_C(  77) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111), -INT8_C(   1), -INT8_C( 110),
        -INT8_C(   1), -INT8_C(   4),  INT8_C(   0), -INT8_C(   1),  INT8_C(  94),  INT8_C(   0),  INT8_C(  95), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi8(test_vec[i].c);
    simde__m128i r = simde_mm_perm_epi8(a, b, c);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i c = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_perm_epi8(a, b, c);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permute2_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int d;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   129.98), SIMDE_FLOAT32_C(   401.59), SIMDE_FLOAT32_C(   867.92), SIMDE_FLOAT32_C(   437.42) },
      { SIMDE_FLOAT32_C(  -611.26), SIMDE_FLOAT32_C(   858.39), SIMDE_FLOAT32_C(   567.61), SIMDE_FLOAT32_C(   819.03) },
      {  INT32_C(          14),  INT32_C(           0),  INT32_C(           4),  INT32_C(           0) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   567.61), SIMDE_FLOAT32_C(   129.98), SIMDE_FLOAT32_C(  -611.26), SIMDE_FLOAT32_C(   129.98) } },
    { { SIMDE_FLOAT32_C(  -835.57), SIMDE_FLOAT32_C(  -684.62), SIMDE_FLOAT32_C(   721.85), SIMDE_FLOAT32_C(   146.64) },
      { SIMDE_FLOAT32_C(   275.31), SIMDE_FLOAT32_C(  -324.99), SIMDE_FLOAT32_C(   132.97), SIMDE_FLOAT32_C(  -255.90) },
      {  INT32_C(           1),  INT32_C(           4),  INT32_C(           9),  INT32_C(           0) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(  -684.62), SIMDE_FLOAT32_C(   275.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -835.57) } },
    { { SIMDE_FLOAT32_C(  -432.91), SIMDE_FLOAT32_C(  -489.85), SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   470.63) },
      { SIMDE_FLOAT32_C(  -541.61), SIMDE_FLOAT32_C(  -363.81), SIMDE_FLOAT32_C(   791.74), SIMDE_FLOAT32_C(   -78.71) },
      {  INT32_C(          14),  INT32_C(           2),  INT32_C(           7),  INT32_C(          13) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   -78.71), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(   432.29), SIMDE_FLOAT32_C(  -485.64), SIMDE_FLOAT32_C(  -528.31), SIMDE_FLOAT32_C(  -203.71) },
      { SIMDE_FLOAT32_C(  -190.04), SIMDE_FLOAT32_C(  -924.92), SIMDE_FLOAT32_C(  -444.56), SIMDE_FLOAT32_C(  -295.94) },
      {  INT32_C(           4),  INT32_C(           2),  INT32_C(           3),  INT32_C(           4) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(   506.03), SIMDE_FLOAT32_C(  -284.59), SIMDE_FLOAT32_C(   589.16), SIMDE_FLOAT32_C(  -679.74) },
      { SIMDE_FLOAT32_C(  -505.42), SIMDE_FLOAT32_C(  -405.87), SIMDE_FLOAT32_C(  -748.59), SIMDE_FLOAT32_C(   -58.20) },
      {  INT32_C(           7),  INT32_C(           5),  INT32_C(          13),  INT32_C(           5) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   -58.20), SIMDE_FLOAT32_C(  -405.87), SIMDE_FLOAT32_C(  -405.87), SIMDE_FLOAT32_C(  -405.87) } },
    { { SIMDE_FLOAT32_C(  -741.02), SIMDE_FLOAT32_C(   126.26), SIMDE_FLOAT32_C(   -83.53), SIMDE_FLOAT32_C(   950.68) },
      { SIMDE_FLOAT32_C(   890.50), SIMDE_FLOAT32_C(   173.80), SIMDE_FLOAT32_C(  -673.21), SIMDE_FLOAT32_C(   923.95) },
      {  INT32_C(           9),  INT32_C(           8),  INT32_C(           9),  INT32_C(          12) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(   126.26), SIMDE_FLOAT32_C(  -741.02), SIMDE_FLOAT32_C(   126.26), SIMDE_FLOAT32_C(   890.50) } },
    { { SIMDE_FLOAT32_C(  -296.98), SIMDE_FLOAT32_C(   579.52), SIMDE_FLOAT32_C(  -101.17), SIMDE_FLOAT32_C(  -117.53) },
      { SIMDE_FLOAT32_C(  -257.36), SIMDE_FLOAT32_C(   821.77), SIMDE_FLOAT32_C(   327.49), SIMDE_FLOAT32_C(   415.88) },
      {  INT32_C(           8),  INT32_C(          14),  INT32_C(          14),  INT32_C(          12) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  -296.98), SIMDE_FLOAT32_C(   327.49), SIMDE_FLOAT32_C(   327.49), SIMDE_FLOAT32_C(  -257.36) } },
    { { SIMDE_FLOAT32_C(   920.53), SIMDE_FLOAT32_C(   154.27), SIMDE_FLOAT32_C(  -820.43), SIMDE_FLOAT32_C(   -34.27) },
      { SIMDE_FLOAT32_C(   894.96), SIMDE_FLOAT32_C(   622.43), SIMDE_FLOAT32_C(  -238.99), SIMDE_FLOAT32_C(   783.62) },
      {  INT32_C(           1),  INT32_C(          10),  INT32_C(          12),  INT32_C(           0) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -820.43), SIMDE_FLOAT32_C(   894.96), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi32(test_vec[i].c);
    simde__m128 r;
    SIMDE_CONSTIFY_4_(simde_mm_permute2_ps, r, (HEDLEY_UNREACHABLE(), simde_mm_setzero_ps ()), test_vec[i].d, a, b, c);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128i c = simde_mm_and_si128(simde_test_x86_random_i32x4(), simde_mm_set1_epi32(0x0f));
    int d = simde_test_codegen_rand() & 0x03;
    simde__m128 r;
    SIMDE_CONSTIFY_4_(simde_mm_permute2_ps, r, (HEDLEY_UNREACHABLE(), simde_mm_setzero_ps ()), d, a, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, d), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_permute2_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int64_t c[2];
    const int d;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   946.41), SIMDE_FLOAT64_C(  -601.79) },
      { SIMDE_FLOAT64_C(    79.87), SIMDE_FLOAT64_C(   578.60) },
      {  INT64_C(                   4),  INT64_C(                  10) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(    79.87), SIMDE_FLOAT64_C(  -601.79) } },
    { { SIMDE_FLOAT64_C(  -898.86), SIMDE_FLOAT64_C(   677.72) },
      { SIMDE_FLOAT64_C(  -628.04), SIMDE_FLOAT64_C(  -776.48) },
      {  INT64_C(                  10),  INT64_C(                  12) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   677.72), SIMDE_FLOAT64_C(  -628.04) } },
    { { SIMDE_FLOAT64_C(   204.26), SIMDE_FLOAT64_C(   493.15) },
      { SIMDE_FLOAT64_C(  -801.08), SIMDE_FLOAT64_C(   980.47) },
      {  INT64_C(                  14),  INT64_C(                   2) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   980.47), SIMDE_FLOAT64_C(   493.15) } },
    { { SIMDE_FLOAT64_C(   217.14), SIMDE_FLOAT64_C(   271.58) },
      { SIMDE_FLOAT64_C(    17.12), SIMDE_FLOAT64_C(   251.93) },
      {  INT64_C(                   2),  INT64_C(                  14) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   271.58), SIMDE_FLOAT64_C(   251.93) } },
    { { SIMDE_FLOAT64_C(    91.95), SIMDE_FLOAT64_C(   368.27) },
      { SIMDE_FLOAT64_C(   859.31), SIMDE_FLOAT64_C(   440.78) },
      {  INT64_C(                   6),  INT64_C(                   4) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(   440.78), SIMDE_FLOAT64_C(   859.31) } },
    { { SIMDE_FLOAT64_C(   876.22), SIMDE_FLOAT64_C(  -296.73) },
      { SIMDE_FLOAT64_C(   325.42), SIMDE_FLOAT64_C(  -973.69) },
      {  INT64_C(                  14),  INT64_C(                   8) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -973.69), SIMDE_FLOAT64_C(   876.22) } },
    { { SIMDE_FLOAT64_C(  -874.63), SIMDE_FLOAT64_C(  -143.89) },
      { SIMDE_FLOAT64_C(  -952.94), SIMDE_FLOAT64_C(   675.71) },
      {  INT64_C(                   6),  INT64_C(                  14) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(   675.71), SIMDE_FLOAT64_C(   675.71) } },
    { { SIMDE_FLOAT64_C(   733.82), SIMDE_FLOAT64_C(   710.62) },
      { SIMDE_FLOAT64_C(    96.16), SIMDE_FLOAT64_C(  -263.28) },
      {  INT64_C(                   4),  INT64_C(                   6) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(    96.16), SIMDE_FLOAT64_C(  -263.28) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi64(test_vec[i].c);
    simde__m128d r;
    SIMDE_CONSTIFY_4_(simde_mm_permute2_pd, r, (HEDLEY_UNREACHABLE(), simde_mm_setzero_pd ()), test_vec[i].d, a, b, c);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i c = simde_mm_and_si128(simde_test_x86_random_i64x2(), simde_mm_set1_epi64x(0x0e));
    int d = simde_test_codegen_rand() & 0x03;
    simde__m128d r;
    SIMDE_CONSTIFY_4_(simde_mm_permute2_pd, r, (HEDLEY_UNREACHABLE(), simde_mm_setzero_pd ()), d, a, b, c);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, d), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permute2_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 b[8];
    const int32_t c[8];
    const int d;
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    59.18), SIMDE_FLOAT32_C(  -800.35), SIMDE_FLOAT32_C(   138.65), SIMDE_FLOAT32_C(  -635.55),
        SIMDE_FLOAT32_C(  -813.41), SIMDE_FLOAT32_C(  -662.83), SIMDE_FLOAT32_C(   685.60), SIMDE_FLOAT32_C(   286.29) },
      { SIMDE_FLOAT32_C(   409.16), SIMDE_FLOAT32_C(   678.46), SIMDE_FLOAT32_C(   717.46), SIMDE_FLOAT32_C(   777.76),
        SIMDE_FLOAT32_C(   911.80), SIMDE_FLOAT32_C(    24.75), SIMDE_FLOAT32_C(  -239.23), SIMDE_FLOAT32_C(  -532.76) },
      {  INT32_C(          12),  INT32_C(          12),  INT32_C(           8),  INT32_C(           0),  INT32_C(          10),  INT32_C(           4),  INT32_C(           4),  INT32_C(           6) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   409.16), SIMDE_FLOAT32_C(   409.16), SIMDE_FLOAT32_C(    59.18), SIMDE_FLOAT32_C(    59.18),
        SIMDE_FLOAT32_C(   685.60), SIMDE_FLOAT32_C(   911.80), SIMDE_FLOAT32_C(   911.80), SIMDE_FLOAT32_C(  -239.23) } },
    { { SIMDE_FLOAT32_C(   648.55), SIMDE_FLOAT32_C(   686.82), SIMDE_FLOAT32_C(   957.82), SIMDE_FLOAT32_C(   927.73),
        SIMDE_FLOAT32_C(  -152.26), SIMDE_FLOAT32_C(    62.11), SIMDE_FLOAT32_C(  -895.87), SIMDE_FLOAT32_C(    97.51) },
      { SIMDE_FLOAT32_C(   234.72), SIMDE_FLOAT32_C(  -955.50), SIMDE_FLOAT32_C(   230.99), SIMDE_FLOAT32_C(   982.73),
        SIMDE_FLOAT32_C(  -683.34), SIMDE_FLOAT32_C(   980.16), SIMDE_FLOAT32_C(  -304.30), SIMDE_FLOAT32_C(   324.93) },
      {  INT32_C(          12),  INT32_C(          14),  INT32_C(          10),  INT32_C(          14),  INT32_C(          10),  INT32_C(           6),  INT32_C(           6),  INT32_C(          12) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   234.72), SIMDE_FLOAT32_C(   230.99), SIMDE_FLOAT32_C(   957.82), SIMDE_FLOAT32_C(   230.99),
        SIMDE_FLOAT32_C(  -895.87), SIMDE_FLOAT32_C(  -304.30), SIMDE_FLOAT32_C(  -304.30), SIMDE_FLOAT32_C(  -683.34) } },
    { { SIMDE_FLOAT32_C(  -138.65), SIMDE_FLOAT32_C(   743.03), SIMDE_FLOAT32_C(   879.21), SIMDE_FLOAT32_C(   368.69),
        SIMDE_FLOAT32_C(   482.53), SIMDE_FLOAT32_C(   564.75), SIMDE_FLOAT32_C(  -465.62), SIMDE_FLOAT32_C(   515.00) },
      { SIMDE_FLOAT32_C(   290.26), SIMDE_FLOAT32_C(   656.00), SIMDE_FLOAT32_C(   -44.16), SIMDE_FLOAT32_C(  -550.10),
        SIMDE_FLOAT32_C(    32.07), SIMDE_FLOAT32_C(   356.98), SIMDE_FLOAT32_C(   374.13), SIMDE_FLOAT32_C(   728.87) },
      {  INT32_C(           0),  INT32_C(           4),  INT32_C(           2),  INT32_C(           6),  INT32_C(          12),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(  -138.65), SIMDE_FLOAT32_C(   290.26), SIMDE_FLOAT32_C(   879.21), SIMDE_FLOAT32_C(   -44.16),
        SIMDE_FLOAT32_C(    32.07), SIMDE_FLOAT32_C(  -465.62), SIMDE_FLOAT32_C(   482.53), SIMDE_FLOAT32_C(   482.53) } },
    { { SIMDE_FLOAT32_C(   636.40), SIMDE_FLOAT32_C(   479.96), SIMDE_FLOAT32_C(  -979.13), SIMDE_FLOAT32_C(   272.01),
        SIMDE_FLOAT32_C(  -369.85), SIMDE_FLOAT32_C(    21.03), SIMDE_FLOAT32_C(  -946.78), SIMDE_FLOAT32_C(  -459.58) },
      { SIMDE_FLOAT32_C(  -267.43), SIMDE_FLOAT32_C(   -20.97), SIMDE_FLOAT32_C(   418.26), SIMDE_FLOAT32_C(  -377.36),
        SIMDE_FLOAT32_C(  -729.42), SIMDE_FLOAT32_C(  -938.23), SIMDE_FLOAT32_C(   927.12), SIMDE_FLOAT32_C(   281.53) },
      {  INT32_C(           8),  INT32_C(           4),  INT32_C(           2),  INT32_C(          12),  INT32_C(           8),  INT32_C(          14),  INT32_C(          10),  INT32_C(           0) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   636.40), SIMDE_FLOAT32_C(  -267.43), SIMDE_FLOAT32_C(  -979.13), SIMDE_FLOAT32_C(  -267.43),
        SIMDE_FLOAT32_C(  -369.85), SIMDE_FLOAT32_C(   927.12), SIMDE_FLOAT32_C(  -946.78), SIMDE_FLOAT32_C(  -369.85) } },
    { { SIMDE_FLOAT32_C(  -514.69), SIMDE_FLOAT32_C(   975.89), SIMDE_FLOAT32_C(   603.32), SIMDE_FLOAT32_C(   719.54),
        SIMDE_FLOAT32_C(   487.53), SIMDE_FLOAT32_C(   496.57), SIMDE_FLOAT32_C(   541.12), SIMDE_FLOAT32_C(  -839.84) },
      { SIMDE_FLOAT32_C(  -858.39), SIMDE_FLOAT32_C(   391.28), SIMDE_FLOAT32_C(   -69.55), SIMDE_FLOAT32_C(  -161.96),
        SIMDE_FLOAT32_C(   370.95), SIMDE_FLOAT32_C(  -487.90), SIMDE_FLOAT32_C(   348.80), SIMDE_FLOAT32_C(   619.43) },
      {  INT32_C(          10),  INT32_C(           2),  INT32_C(           4),  INT32_C(           0),  INT32_C(          14),  INT32_C(           4),  INT32_C(           6),  INT32_C(           0) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   603.32), SIMDE_FLOAT32_C(  -858.39), SIMDE_FLOAT32_C(  -514.69),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   370.95), SIMDE_FLOAT32_C(   348.80), SIMDE_FLOAT32_C(   487.53) } },
    { { SIMDE_FLOAT32_C(  -794.06), SIMDE_FLOAT32_C(  -753.17), SIMDE_FLOAT32_C(   459.03), SIMDE_FLOAT32_C(  -757.07),
        SIMDE_FLOAT32_C(  -644.58), SIMDE_FLOAT32_C(  -551.50), SIMDE_FLOAT32_C(  -592.33), SIMDE_FLOAT32_C(  -775.75) },
      { SIMDE_FLOAT32_C(   464.46), SIMDE_FLOAT32_C(   356.85), SIMDE_FLOAT32_C(  -207.01), SIMDE_FLOAT32_C(  -711.84),
        SIMDE_FLOAT32_C(   961.24), SIMDE_FLOAT32_C(  -241.49), SIMDE_FLOAT32_C(    41.11), SIMDE_FLOAT32_C(  -202.49) },
      {  INT32_C(          14),  INT32_C(           2),  INT32_C(          12),  INT32_C(           4),  INT32_C(           4),  INT32_C(           6),  INT32_C(          12),  INT32_C(           6) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(  -207.01), SIMDE_FLOAT32_C(   459.03), SIMDE_FLOAT32_C(   464.46), SIMDE_FLOAT32_C(   464.46),
        SIMDE_FLOAT32_C(   961.24), SIMDE_FLOAT32_C(    41.11), SIMDE_FLOAT32_C(   961.24), SIMDE_FLOAT32_C(    41.11) } },
    { { SIMDE_FLOAT32_C(   320.78), SIMDE_FLOAT32_C(   431.87), SIMDE_FLOAT32_C(  -274.88), SIMDE_FLOAT32_C(   753.65),
        SIMDE_FLOAT32_C(   578.97), SIMDE_FLOAT32_C(   463.67), SIMDE_FLOAT32_C(  -550.89), SIMDE_FLOAT32_C(  -591.05) },
      { SIMDE_FLOAT32_C(  -724.23), SIMDE_FLOAT32_C(   -48.98), SIMDE_FLOAT32_C(  -445.84), SIMDE_FLOAT32_C(  -510.12),
        SIMDE_FLOAT32_C(  -448.41), SIMDE_FLOAT32_C(   446.58), SIMDE_FLOAT32_C(  -538.38), SIMDE_FLOAT32_C(  -504.68) },
      {  INT32_C(           8),  INT32_C(          10),  INT32_C(          10),  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(          12),  INT32_C(           4) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   320.78), SIMDE_FLOAT32_C(  -274.88), SIMDE_FLOAT32_C(  -274.88), SIMDE_FLOAT32_C(  -724.23),
        SIMDE_FLOAT32_C(   578.97), SIMDE_FLOAT32_C(   578.97), SIMDE_FLOAT32_C(  -448.41), SIMDE_FLOAT32_C(  -448.41) } },
    { { SIMDE_FLOAT32_C(   -71.81), SIMDE_FLOAT32_C(   251.01), SIMDE_FLOAT32_C(  -822.02), SIMDE_FLOAT32_C(   158.91),
        SIMDE_FLOAT32_C(   585.99), SIMDE_FLOAT32_C(   229.65), SIMDE_FLOAT32_C(   421.67), SIMDE_FLOAT32_C(  -216.16) },
      { SIMDE_FLOAT32_C(   959.72), SIMDE_FLOAT32_C(  -586.41), SIMDE_FLOAT32_C(  -198.10), SIMDE_FLOAT32_C(  -695.91),
        SIMDE_FLOAT32_C(    44.89), SIMDE_FLOAT32_C(  -666.86), SIMDE_FLOAT32_C(   177.89), SIMDE_FLOAT32_C(   791.62) },
      {  INT32_C(           0),  INT32_C(          12),  INT32_C(           6),  INT32_C(           2),  INT32_C(           0),  INT32_C(          12),  INT32_C(           6),  INT32_C(          12) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   -71.81), SIMDE_FLOAT32_C(   959.72), SIMDE_FLOAT32_C(  -198.10), SIMDE_FLOAT32_C(  -822.02),
        SIMDE_FLOAT32_C(   585.99), SIMDE_FLOAT32_C(    44.89), SIMDE_FLOAT32_C(   177.89), SIMDE_FLOAT32_C(    44.89) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256i c = simde_mm256_loadu_epi32(test_vec[i].c);
    simde__m256 r;
    SIMDE_CONSTIFY_4_(simde_mm256_permute2_ps, r, (HEDLEY_UNREACHABLE(), simde_mm256_setzero_ps ()), test_vec[i].d, a, b, c);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256i c = simde_mm256_and_si256(simde_test_x86_random_i32x8(), simde_mm256_set1_epi32(0x0e));
    int d = simde_test_codegen_rand() & 0x03;
    simde__m256 r;
    SIMDE_CONSTIFY_4_(simde_mm256_permute2_ps, r, (HEDLEY_UNREACHABLE(), simde_mm256_setzero_ps ()), d, a, b, c);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, d), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_permute2_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde_float64 b[4];
    const int64_t c[4];
    const int d;
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -861.88), SIMDE_FLOAT64_C(   169.72), SIMDE_FLOAT64_C(  -503.45), SIMDE_FLOAT64_C(  -428.77) },
      { SIMDE_FLOAT64_C(   479.43), SIMDE_FLOAT64_C(   641.29), SIMDE_FLOAT64_C(  -720.10), SIMDE_FLOAT64_C(   728.91) },
      {  INT64_C(                  11),  INT64_C(                  15),  INT64_C(                   5),  INT64_C(                   3) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(   169.72), SIMDE_FLOAT64_C(   641.29), SIMDE_FLOAT64_C(  -720.10), SIMDE_FLOAT64_C(  -428.77) } },
    { { SIMDE_FLOAT64_C(   645.52), SIMDE_FLOAT64_C(  -415.41), SIMDE_FLOAT64_C(  -431.99), SIMDE_FLOAT64_C(   760.01) },
      { SIMDE_FLOAT64_C(   919.67), SIMDE_FLOAT64_C(  -555.51), SIMDE_FLOAT64_C(   257.61), SIMDE_FLOAT64_C(  -404.79) },
      {  INT64_C(                   6),  INT64_C(                   6),  INT64_C(                   0),  INT64_C(                   3) },
       INT8_C(   3),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(   -12.31), SIMDE_FLOAT64_C(   278.90), SIMDE_FLOAT64_C(  -825.23), SIMDE_FLOAT64_C(  -451.80) },
      { SIMDE_FLOAT64_C(  -871.35), SIMDE_FLOAT64_C(   507.62), SIMDE_FLOAT64_C(   803.50), SIMDE_FLOAT64_C(   809.62) },
      {  INT64_C(                   6),  INT64_C(                   7),  INT64_C(                   6),  INT64_C(                   1) },
       INT8_C(   2),
      { SIMDE_FLOAT64_C(   507.62), SIMDE_FLOAT64_C(   507.62), SIMDE_FLOAT64_C(   809.62), SIMDE_FLOAT64_C(  -825.23) } },
    { { SIMDE_FLOAT64_C(   284.05), SIMDE_FLOAT64_C(  -424.20), SIMDE_FLOAT64_C(  -550.91), SIMDE_FLOAT64_C(   124.32) },
      { SIMDE_FLOAT64_C(   646.87), SIMDE_FLOAT64_C(   711.77), SIMDE_FLOAT64_C(   452.09), SIMDE_FLOAT64_C(   607.04) },
      {  INT64_C(                   2),  INT64_C(                  12),  INT64_C(                   8),  INT64_C(                   5) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -424.20), SIMDE_FLOAT64_C(   646.87), SIMDE_FLOAT64_C(  -550.91), SIMDE_FLOAT64_C(   452.09) } },
    { { SIMDE_FLOAT64_C(   575.86), SIMDE_FLOAT64_C(  -948.33), SIMDE_FLOAT64_C(  -144.40), SIMDE_FLOAT64_C(  -665.48) },
      { SIMDE_FLOAT64_C(   780.15), SIMDE_FLOAT64_C(  -663.76), SIMDE_FLOAT64_C(   297.14), SIMDE_FLOAT64_C(  -826.42) },
      {  INT64_C(                  11),  INT64_C(                  11),  INT64_C(                   8),  INT64_C(                  14) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -948.33), SIMDE_FLOAT64_C(  -948.33), SIMDE_FLOAT64_C(  -144.40), SIMDE_FLOAT64_C(  -826.42) } },
    { { SIMDE_FLOAT64_C(  -749.92), SIMDE_FLOAT64_C(  -255.38), SIMDE_FLOAT64_C(   354.52), SIMDE_FLOAT64_C(   451.14) },
      { SIMDE_FLOAT64_C(   617.73), SIMDE_FLOAT64_C(  -381.72), SIMDE_FLOAT64_C(   -31.35), SIMDE_FLOAT64_C(  -776.43) },
      {  INT64_C(                  12),  INT64_C(                  15),  INT64_C(                   5),  INT64_C(                   5) },
       INT8_C(   3),
      { SIMDE_FLOAT64_C(   617.73), SIMDE_FLOAT64_C(  -381.72), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(   782.01), SIMDE_FLOAT64_C(   926.32), SIMDE_FLOAT64_C(  -413.97), SIMDE_FLOAT64_C(   703.31) },
      { SIMDE_FLOAT64_C(   -36.46), SIMDE_FLOAT64_C(   228.48), SIMDE_FLOAT64_C(  -122.64), SIMDE_FLOAT64_C(  -415.16) },
      {  INT64_C(                   2),  INT64_C(                  15),  INT64_C(                  11),  INT64_C(                   5) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   926.32), SIMDE_FLOAT64_C(   228.48), SIMDE_FLOAT64_C(   703.31), SIMDE_FLOAT64_C(  -122.64) } },
    { { SIMDE_FLOAT64_C(    20.90), SIMDE_FLOAT64_C(  -217.15), SIMDE_FLOAT64_C(  -187.65), SIMDE_FLOAT64_C(  -111.33) },
      { SIMDE_FLOAT64_C(  -137.06), SIMDE_FLOAT64_C(    81.39), SIMDE_FLOAT64_C(   609.90), SIMDE_FLOAT64_C(   520.68) },
      {  INT64_C(                  13),  INT64_C(                   5),  INT64_C(                   1),  INT64_C(                   6) },
       INT8_C(   3),
      { SIMDE_FLOAT64_C(  -137.06), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256i c = simde_mm256_loadu_epi64(test_vec[i].c);
    simde__m256d r;
    SIMDE_CONSTIFY_4_(simde_mm256_permute2_pd, r, (HEDLEY_UNREACHABLE(), simde_mm256_setzero_pd ()), test_vec[i].d, a, b, c);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256i c = simde_mm256_and_si256(simde_test_x86_random_i64x4(), simde_mm256_set1_epi64x(0x0f));
    int d = simde_test_codegen_rand() & 0x03;
    simde__m256d r;
    SIMDE_CONSTIFY_4_(simde_mm256_permute2_pd, r, (HEDLEY_UNREACHABLE(), simde_mm256_setzero_pd ()), d, a, b, c);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, d), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmov_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmov_si256)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comeq_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comneq_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comge_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comgt_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comle_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comlt_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comtrue_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_comfalse_epu64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_frcz_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_frcz_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_frcz_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_frcz_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_frcz_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_frcz_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddw_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddw_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddd_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddd_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddd_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddq_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddq_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddq_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddq_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddq_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_haddq_epu32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hsubw_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hsubd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hsubq_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_macc_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_macc_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maccd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_macclo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_macchi_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maccs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maccs_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maccsd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maccslo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maccshi_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maddd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maddsd_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sha_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sha_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sha_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_sha_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shl_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shl_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shl_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shl_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rot_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rot_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rot_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rot_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_perm_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permute2_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_permute2_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permute2_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_permute2_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
