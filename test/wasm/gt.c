/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX simd128
#include <simde/wasm/simd128.h>
#include <test/wasm/test-simd128.h>

static int
test_simde_wasm_i8x16_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {  INT8_C( 120), -INT8_C( 104), -INT8_C(  37),  INT8_C(  28),  INT8_C(  93),  INT8_C( 123), -INT8_C(  70),  INT8_C(  51),
           INT8_C(  98), -INT8_C(  52), -INT8_C(   8),  INT8_C(  61), -INT8_C( 101), -INT8_C(  27), -INT8_C(  82), -INT8_C(  73) },
        { -INT8_C(  68),  INT8_C(  28),  INT8_C(  79),  INT8_C(  28), -INT8_C(  24), -INT8_C(  21),  INT8_C(  31), -INT8_C(  19),
          -INT8_C(  59), -INT8_C(  72), -INT8_C(  62),  INT8_C(  63), -INT8_C( 107),  INT8_C(  84), -INT8_C(  58), -INT8_C(  73) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  91),  INT8_C(  70),  INT8_C( 124), -INT8_C( 111), -INT8_C(  69),  INT8_C(  54),  INT8_C(   8),  INT8_C( 111),
          -INT8_C(  92),  INT8_C(  17),  INT8_C( 121), -INT8_C( 119), -INT8_C(  23),  INT8_C(  94),  INT8_C( 107),  INT8_C(  11) },
        { -INT8_C(  51),  INT8_C(  70),  INT8_C( 124), -INT8_C(  25),  INT8_C(  38),  INT8_C(  54),  INT8_C(  19), -INT8_C( 115),
          -INT8_C(  92), -INT8_C(  65),  INT8_C( 121), -INT8_C( 119), -INT8_C(  23),  INT8_C(  98),  INT8_C(   3),  INT8_C(  11) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C(  77),  INT8_C(  37), -INT8_C(  23),  INT8_C(   1),  INT8_C( 124), -INT8_C(  96),  INT8_C(  41),  INT8_C(  85),
          -INT8_C(  89), -INT8_C(  25), -INT8_C(  24),  INT8_C(   0), -INT8_C(  28), -INT8_C(  10),  INT8_C(  98), -INT8_C( 106) },
        {  INT8_C(  45), -INT8_C(  24), -INT8_C(  23),  INT8_C(   1), -INT8_C(  52), -INT8_C(  96), -INT8_C( 125), -INT8_C(  44),
          -INT8_C(  89),  INT8_C(  65),  INT8_C(  32), -INT8_C(  42),  INT8_C(  97),  INT8_C( 102),  INT8_C(  41),  INT8_C(  22) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C( 112),  INT8_C(  42),  INT8_C(   2), -INT8_C( 105), -INT8_C(  89), -INT8_C(  10), -INT8_C(  56),  INT8_C(   0),
           INT8_C(  27), -INT8_C( 105), -INT8_C(  75),      INT8_MIN,  INT8_C(  51), -INT8_C(  98), -INT8_C(  59),  INT8_C(  63) },
        { -INT8_C(  69),  INT8_C(  42),  INT8_C(   2),  INT8_C(  48), -INT8_C( 104),  INT8_C( 116),  INT8_C(  37),  INT8_C( 112),
          -INT8_C(  44),  INT8_C(  79), -INT8_C(  59),  INT8_C(  75), -INT8_C(  12),  INT8_C(  20),  INT8_C(  81), -INT8_C(  15) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
      { { -INT8_C(  85),  INT8_C(  78), -INT8_C(  68),  INT8_C(  49),  INT8_C( 106), -INT8_C(  42), -INT8_C(  13), -INT8_C(  93),
           INT8_C(  61), -INT8_C(  18),  INT8_C(  83), -INT8_C(  84),  INT8_C(  45), -INT8_C(  69),  INT8_C(  49),  INT8_C(  99) },
        {  INT8_C(  75),  INT8_C(  77),  INT8_C(  41), -INT8_C(  64),  INT8_C( 121), -INT8_C(  20), -INT8_C(   5),  INT8_C(  85),
          -INT8_C(  90), -INT8_C(  18),  INT8_C(  83), -INT8_C(  92),  INT8_C(  36), -INT8_C(  15), -INT8_C(  41), -INT8_C(  52) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C(   8),  INT8_C(  33),  INT8_C(  55),  INT8_C(   7),  INT8_C(  14), -INT8_C(  42),  INT8_C(   6),  INT8_C(   4),
          -INT8_C(  88),  INT8_C(  53),  INT8_C(  60), -INT8_C(  24),  INT8_C(  28),  INT8_C(  94), -INT8_C( 106),      INT8_MIN },
        {  INT8_C( 110),  INT8_C(  80), -INT8_C( 104), -INT8_C(  95),  INT8_C(  82),  INT8_C(  27),  INT8_C( 102),  INT8_C(  50),
           INT8_C(  10),  INT8_C(  53),  INT8_C(  60), -INT8_C( 104), -INT8_C(  17),  INT8_C(  94), -INT8_C(  89),      INT8_MIN },
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  28), -INT8_C(  54),  INT8_C(  94), -INT8_C(  44), -INT8_C(  39),  INT8_C(  85),  INT8_C( 118),  INT8_C( 107),
          -INT8_C( 119),  INT8_C(  57),  INT8_C(  63), -INT8_C(  84),  INT8_C(  63),  INT8_C( 120), -INT8_C(  51),  INT8_C(  12) },
        { -INT8_C(  28), -INT8_C(  59),  INT8_C(  94),  INT8_C(  34),  INT8_C(  52), -INT8_C(  82), -INT8_C( 109), -INT8_C(  43),
          -INT8_C(  81),  INT8_C(  57),  INT8_C(  63),  INT8_C(  30), -INT8_C(  90),  INT8_C( 120), -INT8_C(  81), -INT8_C(  79) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C( 110), -INT8_C(  35), -INT8_C( 124),  INT8_C(  27),  INT8_C( 104),  INT8_C(   6),  INT8_C(  17),  INT8_C( 122),
          -INT8_C(  96), -INT8_C(   4), -INT8_C( 108), -INT8_C(  99),  INT8_C(   0), -INT8_C( 112),  INT8_C(  78), -INT8_C(   4) },
        { -INT8_C(  21),  INT8_C(  49),  INT8_C(  96), -INT8_C(   2), -INT8_C( 122), -INT8_C(  58), -INT8_C(  40),  INT8_C(   0),
           INT8_C(  39), -INT8_C(   4),  INT8_C( 121),  INT8_C(  30),  INT8_C(  55), -INT8_C(  57), -INT8_C(   3), -INT8_C( 107) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_gt(a, b);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a_[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b_[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i8x16_gt(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { { -INT16_C( 27878), -INT16_C(  3954), -INT16_C( 15609),  INT16_C( 29201), -INT16_C( 31843), -INT16_C(  2506),  INT16_C( 30424),  INT16_C( 30605) },
        { -INT16_C( 27878),  INT16_C(    14),  INT16_C( 14511),  INT16_C( 10099), -INT16_C( 32335), -INT16_C(  2156),  INT16_C( 30424),  INT16_C( 23803) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { {  INT16_C( 28754), -INT16_C( 29154), -INT16_C( 25464),  INT16_C( 16122), -INT16_C(  9208), -INT16_C( 10715),  INT16_C(  4466),  INT16_C( 27560) },
        {  INT16_C( 14667), -INT16_C( 16384),  INT16_C( 28791),  INT16_C( 14975), -INT16_C(  4668),  INT16_C( 15260), -INT16_C(  2134),  INT16_C( 27560) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 13086), -INT16_C( 21981), -INT16_C( 22291), -INT16_C(  5347),  INT16_C(  6252), -INT16_C( 16974),  INT16_C( 22019), -INT16_C( 13990) },
        {  INT16_C( 13086),  INT16_C(  9318), -INT16_C(  4202), -INT16_C(  2719),  INT16_C( 31514),  INT16_C( 22550),  INT16_C( 27029), -INT16_C( 13990) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C(  4600), -INT16_C( 20613), -INT16_C( 23513),  INT16_C( 10764), -INT16_C( 23014), -INT16_C(  1008),  INT16_C(  6593),  INT16_C(  6963) },
        { -INT16_C( 29411),  INT16_C(  7887), -INT16_C(  4937),  INT16_C( 31470),  INT16_C(  4995),  INT16_C( 32412),  INT16_C( 23234), -INT16_C( 21517) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C(   297),  INT16_C( 12831),  INT16_C( 22603), -INT16_C( 26136), -INT16_C( 15500),  INT16_C( 32303), -INT16_C(  1014), -INT16_C( 21224) },
        {  INT16_C( 31604),  INT16_C( 12831), -INT16_C(  8216), -INT16_C( 18709),  INT16_C(  5697),  INT16_C( 27004),  INT16_C( 21187),  INT16_C( 11538) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 13425),  INT16_C( 20822),  INT16_C( 17768),  INT16_C( 23191),  INT16_C( 24498),  INT16_C(  5752),  INT16_C(  5811), -INT16_C(  8299) },
        { -INT16_C( 17421), -INT16_C( 21397), -INT16_C( 13326), -INT16_C( 22702),  INT16_C( 24498),  INT16_C(  5752),  INT16_C( 15910), -INT16_C(  8299) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C(  7160), -INT16_C( 29292),  INT16_C(  7127),  INT16_C(  8955), -INT16_C( 20557),  INT16_C(  2443), -INT16_C( 18112), -INT16_C( 19386) },
        { -INT16_C( 25710), -INT16_C( 11642), -INT16_C(  2212),  INT16_C( 32060),  INT16_C( 25931), -INT16_C( 14754),  INT16_C(  5644), -INT16_C( 10268) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 27468), -INT16_C( 14413), -INT16_C( 22324),  INT16_C( 13677),  INT16_C( 29560), -INT16_C(  2116), -INT16_C( 31338),  INT16_C( 26767) },
        { -INT16_C( 27468), -INT16_C( 14413), -INT16_C( 24954), -INT16_C( 17311),  INT16_C( 29560),  INT16_C( 24449), -INT16_C(  1834),  INT16_C(  2936) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_gt(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a_[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b_[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i16x8_gt(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(   585754791), -INT32_C(  1422463462),  INT32_C(   845196096), -INT32_C(   786973175) },
        {  INT32_C(   675930469), -INT32_C(  1968971350), -INT32_C(   231548217), -INT32_C(   786973175) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   623183880),  INT32_C(  1357702556),  INT32_C(  1005708208),  INT32_C(  1734772658) },
        {  INT32_C(   603577638), -INT32_C(   425140975),  INT32_C(  1005708208),  INT32_C(   489779981) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(    15472369),  INT32_C(  2105574877), -INT32_C(  1420369661), -INT32_C(  1638450800) },
        {  INT32_C(  2013991617), -INT32_C(  1896741416), -INT32_C(  2057875434),  INT32_C(  1088390214) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   167974981),  INT32_C(   309776056), -INT32_C(  1121810496),  INT32_C(  1922200829) },
        {  INT32_C(   167974981),  INT32_C(   300946559),  INT32_C(   489429762),  INT32_C(   818103913) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(   994859684),  INT32_C(   522775052), -INT32_C(   208693728),  INT32_C(   514465742) },
        { -INT32_C(   994859684),  INT32_C(  1988783829), -INT32_C(  1542162100),  INT32_C(    28632828) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(  1442584401),  INT32_C(  1140942803),  INT32_C(  2007671099),  INT32_C(   639900796) },
        { -INT32_C(  1442584401),  INT32_C(  1001890932), -INT32_C(  1647814219),  INT32_C(   616201031) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(   732197036),  INT32_C(  1518198776), -INT32_C(   342237284), -INT32_C(  1415389865) },
        { -INT32_C(  1219916322),  INT32_C(  1518198776),  INT32_C(  2138690440), -INT32_C(  1415389865) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { {  INT32_C(   356302798),  INT32_C(  1033519531),  INT32_C(   256964056), -INT32_C(   309231831) },
        { -INT32_C(    50961522),  INT32_C(  1033519531), -INT32_C(   860135596), -INT32_C(   309231831) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_gt(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a_[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b_[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i32x4_gt(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -919.54),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -471.64) },
        { SIMDE_FLOAT32_C(   508.37),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -471.64) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   449.10), SIMDE_FLOAT32_C(   969.37), SIMDE_FLOAT32_C(  -434.52), SIMDE_FLOAT32_C(   387.61) },
        { SIMDE_FLOAT32_C(  -544.94), SIMDE_FLOAT32_C(    65.41), SIMDE_FLOAT32_C(   -23.24), SIMDE_FLOAT32_C(   972.81) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -528.49), SIMDE_FLOAT32_C(    97.69), SIMDE_FLOAT32_C(   428.79), SIMDE_FLOAT32_C(  -755.67) },
        { SIMDE_FLOAT32_C(  -375.14), SIMDE_FLOAT32_C(  -313.14), SIMDE_FLOAT32_C(  -926.31), SIMDE_FLOAT32_C(  -684.00) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   321.01), SIMDE_FLOAT32_C(   291.68), SIMDE_FLOAT32_C(   429.59), SIMDE_FLOAT32_C(   962.87) },
        { SIMDE_FLOAT32_C(  -274.18), SIMDE_FLOAT32_C(  -215.26), SIMDE_FLOAT32_C(  -797.89), SIMDE_FLOAT32_C(   -24.82) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   768.64), SIMDE_FLOAT32_C(  -762.74), SIMDE_FLOAT32_C(   914.92), SIMDE_FLOAT32_C(   165.89) },
        { SIMDE_FLOAT32_C(  -132.13), SIMDE_FLOAT32_C(   495.38), SIMDE_FLOAT32_C(   384.80), SIMDE_FLOAT32_C(   625.12) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -554.31), SIMDE_FLOAT32_C(   212.38), SIMDE_FLOAT32_C(  -323.57), SIMDE_FLOAT32_C(   317.38) },
        { SIMDE_FLOAT32_C(   188.95), SIMDE_FLOAT32_C(  -151.08), SIMDE_FLOAT32_C(  -685.80), SIMDE_FLOAT32_C(  -653.47) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(    43.67), SIMDE_FLOAT32_C(   575.14), SIMDE_FLOAT32_C(  -368.30), SIMDE_FLOAT32_C(  -868.74) },
        { SIMDE_FLOAT32_C(  -536.03), SIMDE_FLOAT32_C(  -295.32), SIMDE_FLOAT32_C(   806.02), SIMDE_FLOAT32_C(  -500.26) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -894.97), SIMDE_FLOAT32_C(   110.82), SIMDE_FLOAT32_C(   465.41), SIMDE_FLOAT32_C(  -715.46) },
        { SIMDE_FLOAT32_C(  -396.79), SIMDE_FLOAT32_C(   439.57), SIMDE_FLOAT32_C(  -202.11), SIMDE_FLOAT32_C(  -693.34) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_gt(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 2, inputs, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f32x4_gt(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -31.51) },
        { SIMDE_FLOAT64_C(   753.52),             SIMDE_MATH_NAN },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   954.21) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   954.21) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -779.71), SIMDE_FLOAT64_C(  -746.16) },
        { SIMDE_FLOAT64_C(  -771.36), SIMDE_FLOAT64_C(   720.67) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(    81.89), SIMDE_FLOAT64_C(   330.16) },
        { SIMDE_FLOAT64_C(   189.62), SIMDE_FLOAT64_C(   559.77) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -942.57), SIMDE_FLOAT64_C(  -166.72) },
        { SIMDE_FLOAT64_C(   890.50), SIMDE_FLOAT64_C(   821.01) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -775.44), SIMDE_FLOAT64_C(  -913.65) },
        { SIMDE_FLOAT64_C(    87.66), SIMDE_FLOAT64_C(  -473.75) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   781.63), SIMDE_FLOAT64_C(   668.06) },
        { SIMDE_FLOAT64_C(    62.56), SIMDE_FLOAT64_C(   400.66) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -213.51), SIMDE_FLOAT64_C(   315.94) },
        { SIMDE_FLOAT64_C(  -554.51), SIMDE_FLOAT64_C(   596.58) },
        { -INT64_C(                   1),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_gt(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_gt(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_gt)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
