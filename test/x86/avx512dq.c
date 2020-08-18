/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX avx512dq
#include <simde/x86/avx512dq.h>
#include <test/x86/test-avx512.h>

static int
test_simde_mm512_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   260.00), SIMDE_FLOAT32_C(   472.07), SIMDE_FLOAT32_C(   343.37), SIMDE_FLOAT32_C(   668.63),
                         SIMDE_FLOAT32_C(    74.64), SIMDE_FLOAT32_C(  -166.33), SIMDE_FLOAT32_C(   962.01), SIMDE_FLOAT32_C(   120.25),
                         SIMDE_FLOAT32_C(  -633.54), SIMDE_FLOAT32_C(  -160.44), SIMDE_FLOAT32_C(  -754.35), SIMDE_FLOAT32_C(   920.06),
                         SIMDE_FLOAT32_C(  -752.65), SIMDE_FLOAT32_C(   -15.27), SIMDE_FLOAT32_C(   736.97), SIMDE_FLOAT32_C(   591.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   968.14), SIMDE_FLOAT32_C(   728.35), SIMDE_FLOAT32_C(  -574.47), SIMDE_FLOAT32_C(   770.03),
                         SIMDE_FLOAT32_C(  -456.43), SIMDE_FLOAT32_C(   727.04), SIMDE_FLOAT32_C(   -89.84), SIMDE_FLOAT32_C(   288.08),
                         SIMDE_FLOAT32_C(  -720.94), SIMDE_FLOAT32_C(  -964.02), SIMDE_FLOAT32_C(   974.54), SIMDE_FLOAT32_C(  -246.99),
                         SIMDE_FLOAT32_C(  -603.24), SIMDE_FLOAT32_C(  -592.85), SIMDE_FLOAT32_C(  -351.71), SIMDE_FLOAT32_C(   472.50)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(     2.18), SIMDE_FLOAT32_C(   512.00),
                         SIMDE_FLOAT32_C(    66.01), SIMDE_FLOAT32_C(     2.57), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(    72.00),
                         SIMDE_FLOAT32_C(  -592.50), SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(   706.03), SIMDE_FLOAT32_C(     3.59),
                         SIMDE_FLOAT32_C(  -592.14), SIMDE_FLOAT32_C(    -2.31), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     2.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -440.60), SIMDE_FLOAT32_C(   215.95), SIMDE_FLOAT32_C(  -449.65), SIMDE_FLOAT32_C(   426.70),
                         SIMDE_FLOAT32_C(   107.08), SIMDE_FLOAT32_C(  -345.64), SIMDE_FLOAT32_C(   226.40), SIMDE_FLOAT32_C(   712.58),
                         SIMDE_FLOAT32_C(  -396.23), SIMDE_FLOAT32_C(  -256.01), SIMDE_FLOAT32_C(   622.69), SIMDE_FLOAT32_C(  -188.83),
                         SIMDE_FLOAT32_C(   358.20), SIMDE_FLOAT32_C(  -542.16), SIMDE_FLOAT32_C(   982.13), SIMDE_FLOAT32_C(   702.83)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   347.10), SIMDE_FLOAT32_C(  -175.94), SIMDE_FLOAT32_C(   817.30), SIMDE_FLOAT32_C(  -721.72),
                         SIMDE_FLOAT32_C(   775.39), SIMDE_FLOAT32_C(  -218.71), SIMDE_FLOAT32_C(   919.20), SIMDE_FLOAT32_C(  -300.97),
                         SIMDE_FLOAT32_C(   919.48), SIMDE_FLOAT32_C(   -61.84), SIMDE_FLOAT32_C(   121.47), SIMDE_FLOAT32_C(   499.98),
                         SIMDE_FLOAT32_C(   538.40), SIMDE_FLOAT32_C(  -622.49), SIMDE_FLOAT32_C(  -852.24), SIMDE_FLOAT32_C(   445.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   280.10), SIMDE_FLOAT32_C(   135.94), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(     2.32),
                         SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(  -136.57), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     2.28),
                         SIMDE_FLOAT32_C(     3.06), SIMDE_FLOAT32_C(   -32.00), SIMDE_FLOAT32_C(     2.29), SIMDE_FLOAT32_C(   184.83),
                         SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(  -526.16), SIMDE_FLOAT32_C(   852.13), SIMDE_FLOAT32_C(     2.23)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -590.91), SIMDE_FLOAT32_C(  -663.88), SIMDE_FLOAT32_C(  -394.32), SIMDE_FLOAT32_C(  -991.87),
                         SIMDE_FLOAT32_C(   385.94), SIMDE_FLOAT32_C(  -349.46), SIMDE_FLOAT32_C(  -786.25), SIMDE_FLOAT32_C(   192.19),
                         SIMDE_FLOAT32_C(  -594.16), SIMDE_FLOAT32_C(  -602.03), SIMDE_FLOAT32_C(   176.16), SIMDE_FLOAT32_C(  -458.14),
                         SIMDE_FLOAT32_C(   335.26), SIMDE_FLOAT32_C(  -272.70), SIMDE_FLOAT32_C(   585.90), SIMDE_FLOAT32_C(  -571.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   530.04), SIMDE_FLOAT32_C(  -606.85), SIMDE_FLOAT32_C(   112.20), SIMDE_FLOAT32_C(  -437.59),
                         SIMDE_FLOAT32_C(  -396.36), SIMDE_FLOAT32_C(  -280.58), SIMDE_FLOAT32_C(   819.31), SIMDE_FLOAT32_C(  -726.73),
                         SIMDE_FLOAT32_C(  -263.24), SIMDE_FLOAT32_C(  -511.40), SIMDE_FLOAT32_C(  -175.25), SIMDE_FLOAT32_C(   728.37),
                         SIMDE_FLOAT32_C(   881.16), SIMDE_FLOAT32_C(   -49.97), SIMDE_FLOAT32_C(   618.76), SIMDE_FLOAT32_C(  -518.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   514.03), SIMDE_FLOAT32_C(  -534.75), SIMDE_FLOAT32_C(    96.06), SIMDE_FLOAT32_C(    -3.29),
                         SIMDE_FLOAT32_C(   384.31), SIMDE_FLOAT32_C(  -280.08), SIMDE_FLOAT32_C(   786.25), SIMDE_FLOAT32_C(     2.00),
                         SIMDE_FLOAT32_C(    -2.01), SIMDE_FLOAT32_C(    -2.35), SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(     2.56),
                         SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   -32.06), SIMDE_FLOAT32_C(   584.76), SIMDE_FLOAT32_C(  -514.56)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   515.17), SIMDE_FLOAT32_C(   324.54), SIMDE_FLOAT32_C(    91.18), SIMDE_FLOAT32_C(  -165.19),
                         SIMDE_FLOAT32_C(  -882.22), SIMDE_FLOAT32_C(   833.89), SIMDE_FLOAT32_C(   476.02), SIMDE_FLOAT32_C(   887.60),
                         SIMDE_FLOAT32_C(   229.74), SIMDE_FLOAT32_C(   342.64), SIMDE_FLOAT32_C(   541.23), SIMDE_FLOAT32_C(  -642.89),
                         SIMDE_FLOAT32_C(   701.90), SIMDE_FLOAT32_C(   393.90), SIMDE_FLOAT32_C(  -103.65), SIMDE_FLOAT32_C(   243.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    21.91), SIMDE_FLOAT32_C(  -134.28), SIMDE_FLOAT32_C(   125.14), SIMDE_FLOAT32_C(  -667.85),
                         SIMDE_FLOAT32_C(  -778.80), SIMDE_FLOAT32_C(  -220.75), SIMDE_FLOAT32_C(   348.36), SIMDE_FLOAT32_C(    29.88),
                         SIMDE_FLOAT32_C(  -634.89), SIMDE_FLOAT32_C(  -148.88), SIMDE_FLOAT32_C(   827.50), SIMDE_FLOAT32_C(  -532.87),
                         SIMDE_FLOAT32_C(  -762.33), SIMDE_FLOAT32_C(   247.69), SIMDE_FLOAT32_C(  -238.64), SIMDE_FLOAT32_C(   244.40)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(   130.27), SIMDE_FLOAT32_C(    89.13), SIMDE_FLOAT32_C(    -2.57),
                         SIMDE_FLOAT32_C(  -770.03), SIMDE_FLOAT32_C(     3.25), SIMDE_FLOAT32_C(   348.02), SIMDE_FLOAT32_C(     3.20),
                         SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   128.26), SIMDE_FLOAT32_C(   537.00), SIMDE_FLOAT32_C(  -512.76),
                         SIMDE_FLOAT32_C(   696.27), SIMDE_FLOAT32_C(   196.69), SIMDE_FLOAT32_C(   -51.50), SIMDE_FLOAT32_C(   240.25)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   139.73), SIMDE_FLOAT32_C(   808.22), SIMDE_FLOAT32_C(  -888.67), SIMDE_FLOAT32_C(   -90.81),
                         SIMDE_FLOAT32_C(    58.51), SIMDE_FLOAT32_C(  -297.55), SIMDE_FLOAT32_C(  -246.77), SIMDE_FLOAT32_C(  -391.18),
                         SIMDE_FLOAT32_C(   887.15), SIMDE_FLOAT32_C(   997.52), SIMDE_FLOAT32_C(   873.12), SIMDE_FLOAT32_C(  -969.73),
                         SIMDE_FLOAT32_C(   721.30), SIMDE_FLOAT32_C(  -128.28), SIMDE_FLOAT32_C(  -264.35), SIMDE_FLOAT32_C(  -432.42)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -80.65), SIMDE_FLOAT32_C(   -15.71), SIMDE_FLOAT32_C(    54.64), SIMDE_FLOAT32_C(  -420.79),
                         SIMDE_FLOAT32_C(  -573.45), SIMDE_FLOAT32_C(   578.20), SIMDE_FLOAT32_C(  -393.34), SIMDE_FLOAT32_C(   -79.47),
                         SIMDE_FLOAT32_C(  -837.77), SIMDE_FLOAT32_C(   169.23), SIMDE_FLOAT32_C(   110.87), SIMDE_FLOAT32_C(   428.31),
                         SIMDE_FLOAT32_C(   944.93), SIMDE_FLOAT32_C(   222.75), SIMDE_FLOAT32_C(  -792.23), SIMDE_FLOAT32_C(  -269.27)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    32.26), SIMDE_FLOAT32_C(     3.16), SIMDE_FLOAT32_C(     3.41), SIMDE_FLOAT32_C(   -72.01),
                         SIMDE_FLOAT32_C(     2.16), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(  -196.50), SIMDE_FLOAT32_C(   -65.28),
                         SIMDE_FLOAT32_C(   837.02), SIMDE_FLOAT32_C(     2.64), SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     3.28),
                         SIMDE_FLOAT32_C(   656.30), SIMDE_FLOAT32_C(   128.25), SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(  -256.25)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -807.89), SIMDE_FLOAT32_C(  -195.99), SIMDE_FLOAT32_C(  -460.22), SIMDE_FLOAT32_C(  -214.31),
                         SIMDE_FLOAT32_C(  -242.49), SIMDE_FLOAT32_C(   293.67), SIMDE_FLOAT32_C(   209.36), SIMDE_FLOAT32_C(   -28.16),
                         SIMDE_FLOAT32_C(   861.78), SIMDE_FLOAT32_C(  -349.18), SIMDE_FLOAT32_C(  -840.98), SIMDE_FLOAT32_C(   667.88),
                         SIMDE_FLOAT32_C(  -431.60), SIMDE_FLOAT32_C(  -312.68), SIMDE_FLOAT32_C(   469.25), SIMDE_FLOAT32_C(   584.01)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   881.42), SIMDE_FLOAT32_C(   703.51), SIMDE_FLOAT32_C(   112.91), SIMDE_FLOAT32_C(    92.78),
                         SIMDE_FLOAT32_C(   506.44), SIMDE_FLOAT32_C(   923.94), SIMDE_FLOAT32_C(  -577.40), SIMDE_FLOAT32_C(  -437.14),
                         SIMDE_FLOAT32_C(  -379.29), SIMDE_FLOAT32_C(   791.05), SIMDE_FLOAT32_C(   859.09), SIMDE_FLOAT32_C(   612.11),
                         SIMDE_FLOAT32_C(   687.78), SIMDE_FLOAT32_C(   712.98), SIMDE_FLOAT32_C(  -143.15), SIMDE_FLOAT32_C(  -972.86)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   801.39), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   112.03), SIMDE_FLOAT32_C(    36.01),
                         SIMDE_FLOAT32_C(   240.22), SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(   -24.00),
                         SIMDE_FLOAT32_C(     2.33), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   840.07), SIMDE_FLOAT32_C(   512.00),
                         SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(   138.12), SIMDE_FLOAT32_C(   584.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   278.01), SIMDE_FLOAT32_C(  -815.62), SIMDE_FLOAT32_C(   752.91), SIMDE_FLOAT32_C(   710.22),
                         SIMDE_FLOAT32_C(  -124.40), SIMDE_FLOAT32_C(  -338.82), SIMDE_FLOAT32_C(  -853.49), SIMDE_FLOAT32_C(   731.62),
                         SIMDE_FLOAT32_C(   168.07), SIMDE_FLOAT32_C(  -402.61), SIMDE_FLOAT32_C(  -908.62), SIMDE_FLOAT32_C(   912.24),
                         SIMDE_FLOAT32_C(   241.90), SIMDE_FLOAT32_C(   493.82), SIMDE_FLOAT32_C(  -948.44), SIMDE_FLOAT32_C(   522.79)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -401.28), SIMDE_FLOAT32_C(   383.51), SIMDE_FLOAT32_C(  -854.57), SIMDE_FLOAT32_C(  -237.48),
                         SIMDE_FLOAT32_C(  -426.55), SIMDE_FLOAT32_C(  -605.26), SIMDE_FLOAT32_C(   140.00), SIMDE_FLOAT32_C(  -626.79),
                         SIMDE_FLOAT32_C(   473.63), SIMDE_FLOAT32_C(   968.53), SIMDE_FLOAT32_C(  -767.62), SIMDE_FLOAT32_C(  -339.51),
                         SIMDE_FLOAT32_C(   144.17), SIMDE_FLOAT32_C(   -47.64), SIMDE_FLOAT32_C(  -130.89), SIMDE_FLOAT32_C(   -19.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   272.01), SIMDE_FLOAT32_C(     2.18), SIMDE_FLOAT32_C(   592.50), SIMDE_FLOAT32_C(     2.52),
                         SIMDE_FLOAT32_C(  -104.13), SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   594.54),
                         SIMDE_FLOAT32_C(   168.07), SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(  -652.62), SIMDE_FLOAT32_C(     2.50),
                         SIMDE_FLOAT32_C(   144.13), SIMDE_FLOAT32_C(    45.63), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.03)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   491.53), SIMDE_FLOAT32_C(   985.75), SIMDE_FLOAT32_C(  -390.64), SIMDE_FLOAT32_C(   517.90),
                         SIMDE_FLOAT32_C(  -725.16), SIMDE_FLOAT32_C(     9.87), SIMDE_FLOAT32_C(   943.82), SIMDE_FLOAT32_C(   279.49),
                         SIMDE_FLOAT32_C(  -942.01), SIMDE_FLOAT32_C(    63.94), SIMDE_FLOAT32_C(   920.28), SIMDE_FLOAT32_C(   132.72),
                         SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(   855.02), SIMDE_FLOAT32_C(   610.59), SIMDE_FLOAT32_C(   860.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -675.66), SIMDE_FLOAT32_C(   128.22), SIMDE_FLOAT32_C(  -915.29), SIMDE_FLOAT32_C(  -679.65),
                         SIMDE_FLOAT32_C(   537.51), SIMDE_FLOAT32_C(  -484.11), SIMDE_FLOAT32_C(   502.40), SIMDE_FLOAT32_C(  -785.39),
                         SIMDE_FLOAT32_C(  -128.17), SIMDE_FLOAT32_C(   101.31), SIMDE_FLOAT32_C(  -990.73), SIMDE_FLOAT32_C(  -514.82),
                         SIMDE_FLOAT32_C(   231.21), SIMDE_FLOAT32_C(   964.21), SIMDE_FLOAT32_C(  -258.81), SIMDE_FLOAT32_C(   355.88)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    -3.00), SIMDE_FLOAT32_C(   517.65),
                         SIMDE_FLOAT32_C(   529.00), SIMDE_FLOAT32_C(     9.00), SIMDE_FLOAT32_C(     3.67), SIMDE_FLOAT32_C(     2.00),
                         SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(    50.63), SIMDE_FLOAT32_C(   920.01), SIMDE_FLOAT32_C(     2.01),
                         SIMDE_FLOAT32_C(   227.20), SIMDE_FLOAT32_C(   836.02), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.27)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_and_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  266.26), SIMDE_FLOAT64_C(  537.32),
                         SIMDE_FLOAT64_C( -326.88), SIMDE_FLOAT64_C( -882.50),
                         SIMDE_FLOAT64_C(  -89.28), SIMDE_FLOAT64_C( -631.60),
                         SIMDE_FLOAT64_C( -243.67), SIMDE_FLOAT64_C(   78.08)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -676.48), SIMDE_FLOAT64_C( -545.20),
                         SIMDE_FLOAT64_C(  963.41), SIMDE_FLOAT64_C(  343.81),
                         SIMDE_FLOAT64_C( -406.87), SIMDE_FLOAT64_C( -689.93),
                         SIMDE_FLOAT64_C( -169.12), SIMDE_FLOAT64_C( -796.89)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(  513.07),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    2.13),
                         SIMDE_FLOAT64_C(  -65.03), SIMDE_FLOAT64_C( -561.53),
                         SIMDE_FLOAT64_C( -161.04), SIMDE_FLOAT64_C(    2.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -354.59), SIMDE_FLOAT64_C( -334.01),
                         SIMDE_FLOAT64_C( -406.82), SIMDE_FLOAT64_C( -535.93),
                         SIMDE_FLOAT64_C(  534.72), SIMDE_FLOAT64_C(  276.86),
                         SIMDE_FLOAT64_C(  401.00), SIMDE_FLOAT64_C(  921.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -20.44), SIMDE_FLOAT64_C( -778.21),
                         SIMDE_FLOAT64_C(  -61.28), SIMDE_FLOAT64_C(  788.42),
                         SIMDE_FLOAT64_C(  286.07), SIMDE_FLOAT64_C(  772.65),
                         SIMDE_FLOAT64_C( -788.54), SIMDE_FLOAT64_C(  755.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -20.13), SIMDE_FLOAT64_C(   -2.03),
                         SIMDE_FLOAT64_C(  -48.26), SIMDE_FLOAT64_C(  532.41),
                         SIMDE_FLOAT64_C(    2.08), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  657.31)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  197.60), SIMDE_FLOAT64_C( -669.73),
                         SIMDE_FLOAT64_C(  859.82), SIMDE_FLOAT64_C( -638.20),
                         SIMDE_FLOAT64_C( -808.24), SIMDE_FLOAT64_C(  961.25),
                         SIMDE_FLOAT64_C(  916.37), SIMDE_FLOAT64_C( -473.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.21), SIMDE_FLOAT64_C(   10.30),
                         SIMDE_FLOAT64_C(  402.59), SIMDE_FLOAT64_C( -919.31),
                         SIMDE_FLOAT64_C(  484.80), SIMDE_FLOAT64_C(  567.35),
                         SIMDE_FLOAT64_C( -979.89), SIMDE_FLOAT64_C(  784.39)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.08), SIMDE_FLOAT64_C(    2.57),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C( -534.01),
                         SIMDE_FLOAT64_C(    3.03), SIMDE_FLOAT64_C(  513.25),
                         SIMDE_FLOAT64_C(  912.26), SIMDE_FLOAT64_C(    3.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  188.83), SIMDE_FLOAT64_C( -479.33),
                         SIMDE_FLOAT64_C(  811.81), SIMDE_FLOAT64_C( -322.50),
                         SIMDE_FLOAT64_C(  884.11), SIMDE_FLOAT64_C(  808.53),
                         SIMDE_FLOAT64_C( -174.95), SIMDE_FLOAT64_C(  -68.05)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -882.86), SIMDE_FLOAT64_C( -939.93),
                         SIMDE_FLOAT64_C( -855.90), SIMDE_FLOAT64_C(  170.22),
                         SIMDE_FLOAT64_C(  115.99), SIMDE_FLOAT64_C(  297.62),
                         SIMDE_FLOAT64_C( -527.76), SIMDE_FLOAT64_C(  219.88)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.45), SIMDE_FLOAT64_C(   -3.67),
                         SIMDE_FLOAT64_C(  771.77), SIMDE_FLOAT64_C(  160.00),
                         SIMDE_FLOAT64_C(    3.08), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(   -2.05), SIMDE_FLOAT64_C(   34.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -659.02), SIMDE_FLOAT64_C(  607.91),
                         SIMDE_FLOAT64_C( -268.25), SIMDE_FLOAT64_C(  240.07),
                         SIMDE_FLOAT64_C(  471.39), SIMDE_FLOAT64_C( -501.59),
                         SIMDE_FLOAT64_C(  984.94), SIMDE_FLOAT64_C( -801.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -165.03), SIMDE_FLOAT64_C(  382.49),
                         SIMDE_FLOAT64_C( -663.11), SIMDE_FLOAT64_C(  675.92),
                         SIMDE_FLOAT64_C( -427.89), SIMDE_FLOAT64_C( -312.23),
                         SIMDE_FLOAT64_C(   47.19), SIMDE_FLOAT64_C( -273.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -2.56), SIMDE_FLOAT64_C(    2.36),
                         SIMDE_FLOAT64_C(   -2.06), SIMDE_FLOAT64_C(    2.50),
                         SIMDE_FLOAT64_C(  387.39), SIMDE_FLOAT64_C( -304.07),
                         SIMDE_FLOAT64_C(    2.81), SIMDE_FLOAT64_C(   -2.13)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -449.51), SIMDE_FLOAT64_C( -396.24),
                         SIMDE_FLOAT64_C( -106.23), SIMDE_FLOAT64_C( -648.77),
                         SIMDE_FLOAT64_C(  178.69), SIMDE_FLOAT64_C( -996.05),
                         SIMDE_FLOAT64_C(  315.07), SIMDE_FLOAT64_C( -247.28)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  515.02), SIMDE_FLOAT64_C(  228.66),
                         SIMDE_FLOAT64_C(  419.85), SIMDE_FLOAT64_C( -810.27),
                         SIMDE_FLOAT64_C(  162.64), SIMDE_FLOAT64_C(  495.48),
                         SIMDE_FLOAT64_C( -567.27), SIMDE_FLOAT64_C(  755.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  196.03),
                         SIMDE_FLOAT64_C(  104.20), SIMDE_FLOAT64_C( -520.27),
                         SIMDE_FLOAT64_C(  162.63), SIMDE_FLOAT64_C(    3.77),
                         SIMDE_FLOAT64_C(    2.21), SIMDE_FLOAT64_C(    2.82)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -506.18), SIMDE_FLOAT64_C(  153.12),
                         SIMDE_FLOAT64_C( -217.93), SIMDE_FLOAT64_C(    6.73),
                         SIMDE_FLOAT64_C(  358.11), SIMDE_FLOAT64_C( -136.37),
                         SIMDE_FLOAT64_C(  141.08), SIMDE_FLOAT64_C( -860.28)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -303.86), SIMDE_FLOAT64_C( -938.78),
                         SIMDE_FLOAT64_C(  386.83), SIMDE_FLOAT64_C( -590.09),
                         SIMDE_FLOAT64_C( -517.39), SIMDE_FLOAT64_C( -324.41),
                         SIMDE_FLOAT64_C(  515.48), SIMDE_FLOAT64_C(  674.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -298.05), SIMDE_FLOAT64_C(    2.13),
                         SIMDE_FLOAT64_C(  193.41), SIMDE_FLOAT64_C(    2.30),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C( -128.08),
                         SIMDE_FLOAT64_C(    2.00), SIMDE_FLOAT64_C(  512.03)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -571.57), SIMDE_FLOAT64_C( -865.77),
                         SIMDE_FLOAT64_C( -691.63), SIMDE_FLOAT64_C( -182.56),
                         SIMDE_FLOAT64_C(  -67.70), SIMDE_FLOAT64_C( -166.11),
                         SIMDE_FLOAT64_C( -833.08), SIMDE_FLOAT64_C( -401.07)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  341.96), SIMDE_FLOAT64_C(  615.56),
                         SIMDE_FLOAT64_C(  144.45), SIMDE_FLOAT64_C(  211.78),
                         SIMDE_FLOAT64_C(  -86.51), SIMDE_FLOAT64_C(  594.64),
                         SIMDE_FLOAT64_C(  523.21), SIMDE_FLOAT64_C( -747.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.17), SIMDE_FLOAT64_C(  609.52),
                         SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  146.53),
                         SIMDE_FLOAT64_C(  -66.51), SIMDE_FLOAT64_C(    2.06),
                         SIMDE_FLOAT64_C(  513.08), SIMDE_FLOAT64_C(   -2.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -343.60), SIMDE_FLOAT32_C(  -192.26), SIMDE_FLOAT32_C(  -375.10), SIMDE_FLOAT32_C(   810.28),
                         SIMDE_FLOAT32_C(  -388.15), SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(   547.95), SIMDE_FLOAT32_C(   151.06),
                         SIMDE_FLOAT32_C(  -920.74), SIMDE_FLOAT32_C(  -676.14), SIMDE_FLOAT32_C(  -545.26), SIMDE_FLOAT32_C(   -14.56),
                         SIMDE_FLOAT32_C(  -393.14), SIMDE_FLOAT32_C(   768.60), SIMDE_FLOAT32_C(  -177.89), SIMDE_FLOAT32_C(  -467.51)),
      UINT16_C(45944),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -651.37), SIMDE_FLOAT32_C(    37.95), SIMDE_FLOAT32_C(  -182.79), SIMDE_FLOAT32_C(   255.51),
                         SIMDE_FLOAT32_C(   476.70), SIMDE_FLOAT32_C(   371.61), SIMDE_FLOAT32_C(  -494.45), SIMDE_FLOAT32_C(    72.18),
                         SIMDE_FLOAT32_C(  -723.25), SIMDE_FLOAT32_C(   604.60), SIMDE_FLOAT32_C(   545.32), SIMDE_FLOAT32_C(  -399.73),
                         SIMDE_FLOAT32_C(  -975.39), SIMDE_FLOAT32_C(   419.30), SIMDE_FLOAT32_C(  -736.37), SIMDE_FLOAT32_C(   655.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -330.93), SIMDE_FLOAT32_C(   963.24), SIMDE_FLOAT32_C(   -62.45), SIMDE_FLOAT32_C(   625.74),
                         SIMDE_FLOAT32_C(  -826.45), SIMDE_FLOAT32_C(  -884.51), SIMDE_FLOAT32_C(   544.59), SIMDE_FLOAT32_C(   -22.39),
                         SIMDE_FLOAT32_C(   750.16), SIMDE_FLOAT32_C(  -751.51), SIMDE_FLOAT32_C(  -211.00), SIMDE_FLOAT32_C(   886.29),
                         SIMDE_FLOAT32_C(   666.91), SIMDE_FLOAT32_C(     8.70), SIMDE_FLOAT32_C(  -362.66), SIMDE_FLOAT32_C(  -451.03)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -2.51), SIMDE_FLOAT32_C(  -192.26), SIMDE_FLOAT32_C(   -44.20), SIMDE_FLOAT32_C(     2.44),
                         SIMDE_FLOAT32_C(  -388.15), SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     4.50),
                         SIMDE_FLOAT32_C(  -920.74), SIMDE_FLOAT32_C(   588.50), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     3.09),
                         SIMDE_FLOAT32_C(   650.38), SIMDE_FLOAT32_C(   768.60), SIMDE_FLOAT32_C(  -177.89), SIMDE_FLOAT32_C(  -467.51)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -702.08), SIMDE_FLOAT32_C(   457.26), SIMDE_FLOAT32_C(   193.10), SIMDE_FLOAT32_C(   655.72),
                         SIMDE_FLOAT32_C(   205.91), SIMDE_FLOAT32_C(   807.77), SIMDE_FLOAT32_C(  -545.40), SIMDE_FLOAT32_C(  -364.12),
                         SIMDE_FLOAT32_C(   -42.22), SIMDE_FLOAT32_C(  -523.42), SIMDE_FLOAT32_C(  -308.90), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(  -738.11), SIMDE_FLOAT32_C(   189.09), SIMDE_FLOAT32_C(  -448.58)),
      UINT16_C(10313),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -177.43), SIMDE_FLOAT32_C(   -28.38), SIMDE_FLOAT32_C(  -846.37), SIMDE_FLOAT32_C(   912.26),
                         SIMDE_FLOAT32_C(  -370.39), SIMDE_FLOAT32_C(   988.78), SIMDE_FLOAT32_C(  -359.74), SIMDE_FLOAT32_C(  -281.72),
                         SIMDE_FLOAT32_C(   166.18), SIMDE_FLOAT32_C(  -100.50), SIMDE_FLOAT32_C(  -909.51), SIMDE_FLOAT32_C(   -85.95),
                         SIMDE_FLOAT32_C(  -710.91), SIMDE_FLOAT32_C(  -813.11), SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(  -823.45)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   329.92), SIMDE_FLOAT32_C(   113.21), SIMDE_FLOAT32_C(   300.37), SIMDE_FLOAT32_C(  -777.20),
                         SIMDE_FLOAT32_C(   193.77), SIMDE_FLOAT32_C(  -864.32), SIMDE_FLOAT32_C(   579.99), SIMDE_FLOAT32_C(   488.59),
                         SIMDE_FLOAT32_C(  -684.28), SIMDE_FLOAT32_C(   -65.28), SIMDE_FLOAT32_C(   876.26), SIMDE_FLOAT32_C(   378.65),
                         SIMDE_FLOAT32_C(  -964.10), SIMDE_FLOAT32_C(   626.06), SIMDE_FLOAT32_C(    97.19), SIMDE_FLOAT32_C(   612.33)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -702.08), SIMDE_FLOAT32_C(   457.26), SIMDE_FLOAT32_C(     2.28), SIMDE_FLOAT32_C(   655.72),
                         SIMDE_FLOAT32_C(   129.00), SIMDE_FLOAT32_C(   807.77), SIMDE_FLOAT32_C(  -545.40), SIMDE_FLOAT32_C(  -364.12),
                         SIMDE_FLOAT32_C(   -42.22), SIMDE_FLOAT32_C(   -64.00), SIMDE_FLOAT32_C(  -308.90), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(  -708.03), SIMDE_FLOAT32_C(  -738.11), SIMDE_FLOAT32_C(   189.09), SIMDE_FLOAT32_C(   548.31)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   153.13), SIMDE_FLOAT32_C(    47.64), SIMDE_FLOAT32_C(  -104.37), SIMDE_FLOAT32_C(  -453.36),
                         SIMDE_FLOAT32_C(   -57.32), SIMDE_FLOAT32_C(  -673.06), SIMDE_FLOAT32_C(  -857.97), SIMDE_FLOAT32_C(  -158.69),
                         SIMDE_FLOAT32_C(   504.22), SIMDE_FLOAT32_C(   774.61), SIMDE_FLOAT32_C(   -50.26), SIMDE_FLOAT32_C(  -594.62),
                         SIMDE_FLOAT32_C(   628.86), SIMDE_FLOAT32_C(   362.00), SIMDE_FLOAT32_C(   770.65), SIMDE_FLOAT32_C(  -621.70)),
      UINT16_C( 5674),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -181.31), SIMDE_FLOAT32_C(  -271.84), SIMDE_FLOAT32_C(   138.26), SIMDE_FLOAT32_C(    59.10),
                         SIMDE_FLOAT32_C(   703.12), SIMDE_FLOAT32_C(   374.71), SIMDE_FLOAT32_C(  -674.86), SIMDE_FLOAT32_C(  -198.23),
                         SIMDE_FLOAT32_C(   769.31), SIMDE_FLOAT32_C(  -859.16), SIMDE_FLOAT32_C(   111.69), SIMDE_FLOAT32_C(  -420.38),
                         SIMDE_FLOAT32_C(   345.23), SIMDE_FLOAT32_C(  -263.27), SIMDE_FLOAT32_C(   122.33), SIMDE_FLOAT32_C(   -11.31)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    13.03), SIMDE_FLOAT32_C(   510.73), SIMDE_FLOAT32_C(    -6.19), SIMDE_FLOAT32_C(  -107.87),
                         SIMDE_FLOAT32_C(  -441.23), SIMDE_FLOAT32_C(   120.22), SIMDE_FLOAT32_C(   331.67), SIMDE_FLOAT32_C(  -661.48),
                         SIMDE_FLOAT32_C(   626.32), SIMDE_FLOAT32_C(   505.21), SIMDE_FLOAT32_C(  -161.83), SIMDE_FLOAT32_C(  -671.34),
                         SIMDE_FLOAT32_C(   514.06), SIMDE_FLOAT32_C(  -807.61), SIMDE_FLOAT32_C(  -556.61), SIMDE_FLOAT32_C(  -451.72)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   153.13), SIMDE_FLOAT32_C(    47.64), SIMDE_FLOAT32_C(  -104.37), SIMDE_FLOAT32_C(    49.04),
                         SIMDE_FLOAT32_C(   -57.32), SIMDE_FLOAT32_C(    88.16), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(  -158.69),
                         SIMDE_FLOAT32_C(   504.22), SIMDE_FLOAT32_C(   774.61), SIMDE_FLOAT32_C(    32.31), SIMDE_FLOAT32_C(  -594.62),
                         SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   362.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -621.70)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -175.84), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    85.61), SIMDE_FLOAT32_C(  -394.33),
                         SIMDE_FLOAT32_C(   358.35), SIMDE_FLOAT32_C(   605.54), SIMDE_FLOAT32_C(  -698.35), SIMDE_FLOAT32_C(  -764.09),
                         SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(  -893.53), SIMDE_FLOAT32_C(   171.50), SIMDE_FLOAT32_C(   629.19),
                         SIMDE_FLOAT32_C(    42.86), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(   198.87), SIMDE_FLOAT32_C(  -209.78)),
      UINT16_C(35386),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -72.35), SIMDE_FLOAT32_C(  -549.59), SIMDE_FLOAT32_C(   102.63), SIMDE_FLOAT32_C(   834.67),
                         SIMDE_FLOAT32_C(     4.81), SIMDE_FLOAT32_C(   910.94), SIMDE_FLOAT32_C(   192.67), SIMDE_FLOAT32_C(   180.42),
                         SIMDE_FLOAT32_C(   349.29), SIMDE_FLOAT32_C(   183.58), SIMDE_FLOAT32_C(   366.06), SIMDE_FLOAT32_C(  -157.87),
                         SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   182.79), SIMDE_FLOAT32_C(  -978.11), SIMDE_FLOAT32_C(    90.48)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(  -712.55), SIMDE_FLOAT32_C(  -809.33), SIMDE_FLOAT32_C(   698.74),
                         SIMDE_FLOAT32_C(   142.25), SIMDE_FLOAT32_C(  -727.89), SIMDE_FLOAT32_C(  -520.56), SIMDE_FLOAT32_C(   353.74),
                         SIMDE_FLOAT32_C(  -705.41), SIMDE_FLOAT32_C(  -196.42), SIMDE_FLOAT32_C(   407.84), SIMDE_FLOAT32_C(  -285.59),
                         SIMDE_FLOAT32_C(   496.15), SIMDE_FLOAT32_C(   800.83), SIMDE_FLOAT32_C(  -740.01), SIMDE_FLOAT32_C(   769.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    32.03), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    85.61), SIMDE_FLOAT32_C(  -394.33),
                         SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(   605.54), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -764.09),
                         SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(  -893.53), SIMDE_FLOAT32_C(   262.03), SIMDE_FLOAT32_C(  -140.79),
                         SIMDE_FLOAT32_C(   304.13), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(  -704.00), SIMDE_FLOAT32_C(  -209.78)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -273.10), SIMDE_FLOAT32_C(  -193.08), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   970.90),
                         SIMDE_FLOAT32_C(   -50.31), SIMDE_FLOAT32_C(   755.59), SIMDE_FLOAT32_C(  -119.92), SIMDE_FLOAT32_C(  -895.51),
                         SIMDE_FLOAT32_C(   692.21), SIMDE_FLOAT32_C(   544.09), SIMDE_FLOAT32_C(   740.64), SIMDE_FLOAT32_C(   817.79),
                         SIMDE_FLOAT32_C(   131.04), SIMDE_FLOAT32_C(   190.96), SIMDE_FLOAT32_C(   289.64), SIMDE_FLOAT32_C(  -908.35)),
      UINT16_C( 1662),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   563.69), SIMDE_FLOAT32_C(   374.34), SIMDE_FLOAT32_C(  -459.61), SIMDE_FLOAT32_C(   786.82),
                         SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(  -220.73), SIMDE_FLOAT32_C(  -903.10), SIMDE_FLOAT32_C(   520.58),
                         SIMDE_FLOAT32_C(  -858.27), SIMDE_FLOAT32_C(   784.57), SIMDE_FLOAT32_C(   832.81), SIMDE_FLOAT32_C(  -909.15),
                         SIMDE_FLOAT32_C(   909.58), SIMDE_FLOAT32_C(  -162.79), SIMDE_FLOAT32_C(   177.63), SIMDE_FLOAT32_C(    25.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   749.97), SIMDE_FLOAT32_C(   -58.76), SIMDE_FLOAT32_C(   952.36), SIMDE_FLOAT32_C(   549.26),
                         SIMDE_FLOAT32_C(   390.25), SIMDE_FLOAT32_C(  -490.70), SIMDE_FLOAT32_C(   974.89), SIMDE_FLOAT32_C(   114.95),
                         SIMDE_FLOAT32_C(   932.36), SIMDE_FLOAT32_C(  -895.93), SIMDE_FLOAT32_C(  -880.84), SIMDE_FLOAT32_C(  -351.20),
                         SIMDE_FLOAT32_C(  -500.77), SIMDE_FLOAT32_C(    42.49), SIMDE_FLOAT32_C(   588.62), SIMDE_FLOAT32_C(    67.54)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -273.10), SIMDE_FLOAT32_C(  -193.08), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   970.90),
                         SIMDE_FLOAT32_C(   -50.31), SIMDE_FLOAT32_C(  -212.10), SIMDE_FLOAT32_C(   902.01), SIMDE_FLOAT32_C(  -895.51),
                         SIMDE_FLOAT32_C(   692.21), SIMDE_FLOAT32_C(   784.50), SIMDE_FLOAT32_C(   832.78), SIMDE_FLOAT32_C(    -2.55),
                         SIMDE_FLOAT32_C(     3.54), SIMDE_FLOAT32_C(    40.19), SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(  -908.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   882.37), SIMDE_FLOAT32_C(   -29.48), SIMDE_FLOAT32_C(   208.93), SIMDE_FLOAT32_C(  -103.96),
                         SIMDE_FLOAT32_C(  -740.71), SIMDE_FLOAT32_C(   -48.33), SIMDE_FLOAT32_C(   -73.48), SIMDE_FLOAT32_C(   839.05),
                         SIMDE_FLOAT32_C(  -578.39), SIMDE_FLOAT32_C(  -527.30), SIMDE_FLOAT32_C(   808.78), SIMDE_FLOAT32_C(   273.31),
                         SIMDE_FLOAT32_C(  -212.18), SIMDE_FLOAT32_C(   358.44), SIMDE_FLOAT32_C(  -429.58), SIMDE_FLOAT32_C(   641.01)),
      UINT16_C(51954),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   159.89), SIMDE_FLOAT32_C(  -431.59), SIMDE_FLOAT32_C(   692.24), SIMDE_FLOAT32_C(  -189.31),
                         SIMDE_FLOAT32_C(    84.37), SIMDE_FLOAT32_C(  -971.33), SIMDE_FLOAT32_C(    50.60), SIMDE_FLOAT32_C(  -980.81),
                         SIMDE_FLOAT32_C(   362.99), SIMDE_FLOAT32_C(   722.54), SIMDE_FLOAT32_C(   564.98), SIMDE_FLOAT32_C(   242.21),
                         SIMDE_FLOAT32_C(  -393.24), SIMDE_FLOAT32_C(   738.28), SIMDE_FLOAT32_C(   192.78), SIMDE_FLOAT32_C(  -360.32)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -421.96), SIMDE_FLOAT32_C(  -741.98), SIMDE_FLOAT32_C(  -791.19), SIMDE_FLOAT32_C(   363.28),
                         SIMDE_FLOAT32_C(   168.15), SIMDE_FLOAT32_C(  -247.26), SIMDE_FLOAT32_C(   113.19), SIMDE_FLOAT32_C(   128.76),
                         SIMDE_FLOAT32_C(  -773.73), SIMDE_FLOAT32_C(   125.25), SIMDE_FLOAT32_C(   337.69), SIMDE_FLOAT32_C(  -644.22),
                         SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(   681.99), SIMDE_FLOAT32_C(   444.36), SIMDE_FLOAT32_C(   361.44)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   146.89), SIMDE_FLOAT32_C(    -2.27), SIMDE_FLOAT32_C(   208.93), SIMDE_FLOAT32_C(  -103.96),
                         SIMDE_FLOAT32_C(    42.04), SIMDE_FLOAT32_C(   -48.33), SIMDE_FLOAT32_C(    48.59), SIMDE_FLOAT32_C(   839.05),
                         SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(     2.50),
                         SIMDE_FLOAT32_C(  -212.18), SIMDE_FLOAT32_C(   358.44), SIMDE_FLOAT32_C(   192.02), SIMDE_FLOAT32_C(   641.01)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -829.72), SIMDE_FLOAT32_C(   349.95), SIMDE_FLOAT32_C(   480.03), SIMDE_FLOAT32_C(  -584.69),
                         SIMDE_FLOAT32_C(   943.11), SIMDE_FLOAT32_C(  -148.79), SIMDE_FLOAT32_C(  -861.78), SIMDE_FLOAT32_C(  -270.87),
                         SIMDE_FLOAT32_C(  -593.74), SIMDE_FLOAT32_C(  -232.02), SIMDE_FLOAT32_C(  -553.31), SIMDE_FLOAT32_C(   693.33),
                         SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(  -140.16), SIMDE_FLOAT32_C(   631.76)),
      UINT16_C(50263),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   173.33), SIMDE_FLOAT32_C(  -281.34), SIMDE_FLOAT32_C(   -45.38), SIMDE_FLOAT32_C(  -230.23),
                         SIMDE_FLOAT32_C(  -937.39), SIMDE_FLOAT32_C(    53.86), SIMDE_FLOAT32_C(  -719.43), SIMDE_FLOAT32_C(   465.60),
                         SIMDE_FLOAT32_C(   111.60), SIMDE_FLOAT32_C(   156.01), SIMDE_FLOAT32_C(  -703.23), SIMDE_FLOAT32_C(   763.33),
                         SIMDE_FLOAT32_C(   119.12), SIMDE_FLOAT32_C(  -295.56), SIMDE_FLOAT32_C(   313.51), SIMDE_FLOAT32_C(  -193.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   396.81), SIMDE_FLOAT32_C(  -330.26), SIMDE_FLOAT32_C(  -500.01), SIMDE_FLOAT32_C(  -117.27),
                         SIMDE_FLOAT32_C(   805.35), SIMDE_FLOAT32_C(   722.55), SIMDE_FLOAT32_C(   274.82), SIMDE_FLOAT32_C(    32.73),
                         SIMDE_FLOAT32_C(  -564.66), SIMDE_FLOAT32_C(   180.25), SIMDE_FLOAT32_C(  -307.87), SIMDE_FLOAT32_C(   888.96),
                         SIMDE_FLOAT32_C(   806.77), SIMDE_FLOAT32_C(  -526.35), SIMDE_FLOAT32_C(   889.50), SIMDE_FLOAT32_C(   196.92)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   132.27), SIMDE_FLOAT32_C(  -264.26), SIMDE_FLOAT32_C(   480.03), SIMDE_FLOAT32_C(  -584.69),
                         SIMDE_FLOAT32_C(   943.11), SIMDE_FLOAT32_C(     2.31), SIMDE_FLOAT32_C(  -861.78), SIMDE_FLOAT32_C(  -270.87),
                         SIMDE_FLOAT32_C(  -593.74), SIMDE_FLOAT32_C(   148.00), SIMDE_FLOAT32_C(  -553.31), SIMDE_FLOAT32_C(   632.33),
                         SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(     2.44), SIMDE_FLOAT32_C(   192.13)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   425.40), SIMDE_FLOAT32_C(  -281.85), SIMDE_FLOAT32_C(   596.53), SIMDE_FLOAT32_C(   231.55),
                         SIMDE_FLOAT32_C(  -189.24), SIMDE_FLOAT32_C(   962.54), SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(  -728.82),
                         SIMDE_FLOAT32_C(   -31.34), SIMDE_FLOAT32_C(  -498.28), SIMDE_FLOAT32_C(  -106.48), SIMDE_FLOAT32_C(  -850.40),
                         SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(   176.55), SIMDE_FLOAT32_C(   356.84), SIMDE_FLOAT32_C(   827.17)),
      UINT16_C(54643),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   761.43), SIMDE_FLOAT32_C(    95.69), SIMDE_FLOAT32_C(   888.39), SIMDE_FLOAT32_C(  -555.84),
                         SIMDE_FLOAT32_C(    40.33), SIMDE_FLOAT32_C(   358.74), SIMDE_FLOAT32_C(  -948.08), SIMDE_FLOAT32_C(   313.44),
                         SIMDE_FLOAT32_C(  -166.07), SIMDE_FLOAT32_C(  -218.95), SIMDE_FLOAT32_C(   360.34), SIMDE_FLOAT32_C(   989.68),
                         SIMDE_FLOAT32_C(   653.42), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   978.06), SIMDE_FLOAT32_C(   493.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   109.54), SIMDE_FLOAT32_C(   122.35), SIMDE_FLOAT32_C(   770.11), SIMDE_FLOAT32_C(   306.89),
                         SIMDE_FLOAT32_C(  -347.63), SIMDE_FLOAT32_C(   772.43), SIMDE_FLOAT32_C(   958.72), SIMDE_FLOAT32_C(  -435.18),
                         SIMDE_FLOAT32_C(  -680.27), SIMDE_FLOAT32_C(  -653.21), SIMDE_FLOAT32_C(   453.00), SIMDE_FLOAT32_C(   299.53),
                         SIMDE_FLOAT32_C(  -837.12), SIMDE_FLOAT32_C(    -8.00), SIMDE_FLOAT32_C(   561.63), SIMDE_FLOAT32_C(  -594.20)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.41), SIMDE_FLOAT32_C(    90.06), SIMDE_FLOAT32_C(   596.53), SIMDE_FLOAT32_C(     2.13),
                         SIMDE_FLOAT32_C(  -189.24), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(   305.13),
                         SIMDE_FLOAT32_C(   -31.34), SIMDE_FLOAT32_C(    -2.04), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(     2.33),
                         SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(   176.55), SIMDE_FLOAT32_C(   528.01), SIMDE_FLOAT32_C(     2.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_and_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -128.09), SIMDE_FLOAT64_C( -302.68),
                         SIMDE_FLOAT64_C(  129.66), SIMDE_FLOAT64_C( -400.28),
                         SIMDE_FLOAT64_C( -687.60), SIMDE_FLOAT64_C( -568.06),
                         SIMDE_FLOAT64_C( -974.67), SIMDE_FLOAT64_C(  814.47)),
      UINT8_C( 92),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -854.57), SIMDE_FLOAT64_C(  353.06),
                         SIMDE_FLOAT64_C(  903.81), SIMDE_FLOAT64_C( -723.16),
                         SIMDE_FLOAT64_C( -194.97), SIMDE_FLOAT64_C(  114.89),
                         SIMDE_FLOAT64_C(  497.66), SIMDE_FLOAT64_C( -446.09)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -876.89), SIMDE_FLOAT64_C( -283.08),
                         SIMDE_FLOAT64_C(  642.58), SIMDE_FLOAT64_C( -973.49),
                         SIMDE_FLOAT64_C(  853.14), SIMDE_FLOAT64_C(  647.44),
                         SIMDE_FLOAT64_C(  237.52), SIMDE_FLOAT64_C( -333.12)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -128.09), SIMDE_FLOAT64_C(  257.02),
                         SIMDE_FLOAT64_C(  129.66), SIMDE_FLOAT64_C( -705.16),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(    2.53),
                         SIMDE_FLOAT64_C( -974.67), SIMDE_FLOAT64_C(  814.47)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   61.63), SIMDE_FLOAT64_C(  987.28),
                         SIMDE_FLOAT64_C( -845.84), SIMDE_FLOAT64_C( -822.08),
                         SIMDE_FLOAT64_C( -946.95), SIMDE_FLOAT64_C( -157.17),
                         SIMDE_FLOAT64_C(  808.43), SIMDE_FLOAT64_C(  716.34)),
      UINT8_C(128),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.33),
                         SIMDE_FLOAT64_C(  842.44), SIMDE_FLOAT64_C( -417.76),
                         SIMDE_FLOAT64_C( -171.61), SIMDE_FLOAT64_C(  -96.79),
                         SIMDE_FLOAT64_C(   45.73), SIMDE_FLOAT64_C(  312.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   54.70), SIMDE_FLOAT64_C( -228.57),
                         SIMDE_FLOAT64_C( -133.57), SIMDE_FLOAT64_C( -803.47),
                         SIMDE_FLOAT64_C(  821.61), SIMDE_FLOAT64_C(  198.21),
                         SIMDE_FLOAT64_C(  476.20), SIMDE_FLOAT64_C(  925.71)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.41), SIMDE_FLOAT64_C(  987.28),
                         SIMDE_FLOAT64_C( -845.84), SIMDE_FLOAT64_C( -822.08),
                         SIMDE_FLOAT64_C( -946.95), SIMDE_FLOAT64_C( -157.17),
                         SIMDE_FLOAT64_C(  808.43), SIMDE_FLOAT64_C(  716.34)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -24.63), SIMDE_FLOAT64_C( -758.53),
                         SIMDE_FLOAT64_C(  216.18), SIMDE_FLOAT64_C( -869.86),
                         SIMDE_FLOAT64_C( -556.61), SIMDE_FLOAT64_C( -869.93),
                         SIMDE_FLOAT64_C(  935.72), SIMDE_FLOAT64_C(  467.65)),
      UINT8_C(132),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -373.41), SIMDE_FLOAT64_C(  558.94),
                         SIMDE_FLOAT64_C( -966.64), SIMDE_FLOAT64_C( -741.87),
                         SIMDE_FLOAT64_C( -915.12), SIMDE_FLOAT64_C( -226.56),
                         SIMDE_FLOAT64_C(  374.42), SIMDE_FLOAT64_C(  490.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  143.45), SIMDE_FLOAT64_C(   16.49),
                         SIMDE_FLOAT64_C(  323.05), SIMDE_FLOAT64_C( -564.38),
                         SIMDE_FLOAT64_C( -932.37), SIMDE_FLOAT64_C( -126.95),
                         SIMDE_FLOAT64_C(   46.50), SIMDE_FLOAT64_C(  812.07)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  138.19), SIMDE_FLOAT64_C( -758.53),
                         SIMDE_FLOAT64_C(  216.18), SIMDE_FLOAT64_C( -869.86),
                         SIMDE_FLOAT64_C( -556.61), SIMDE_FLOAT64_C(  -56.13),
                         SIMDE_FLOAT64_C(  935.72), SIMDE_FLOAT64_C(  467.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -587.51), SIMDE_FLOAT64_C( -331.04),
                         SIMDE_FLOAT64_C(  711.75), SIMDE_FLOAT64_C( -149.95),
                         SIMDE_FLOAT64_C( -625.31), SIMDE_FLOAT64_C(  387.07),
                         SIMDE_FLOAT64_C(  510.51), SIMDE_FLOAT64_C( -791.87)),
      UINT8_C(197),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -995.18), SIMDE_FLOAT64_C(  720.96),
                         SIMDE_FLOAT64_C(  859.59), SIMDE_FLOAT64_C(   20.65),
                         SIMDE_FLOAT64_C( -207.40), SIMDE_FLOAT64_C( -632.30),
                         SIMDE_FLOAT64_C( -783.67), SIMDE_FLOAT64_C(  389.24)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -619.09), SIMDE_FLOAT64_C(  681.55),
                         SIMDE_FLOAT64_C(  914.89), SIMDE_FLOAT64_C(  240.13),
                         SIMDE_FLOAT64_C(   14.06), SIMDE_FLOAT64_C( -669.70),
                         SIMDE_FLOAT64_C(  554.04), SIMDE_FLOAT64_C( -602.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -611.02), SIMDE_FLOAT64_C(  640.52),
                         SIMDE_FLOAT64_C(  711.75), SIMDE_FLOAT64_C( -149.95),
                         SIMDE_FLOAT64_C( -625.31), SIMDE_FLOAT64_C( -536.00),
                         SIMDE_FLOAT64_C(  510.51), SIMDE_FLOAT64_C(    2.04)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   28.17), SIMDE_FLOAT64_C( -545.33),
                         SIMDE_FLOAT64_C( -993.85), SIMDE_FLOAT64_C( -636.74),
                         SIMDE_FLOAT64_C(  315.22), SIMDE_FLOAT64_C( -560.48),
                         SIMDE_FLOAT64_C( -264.88), SIMDE_FLOAT64_C(  866.66)),
      UINT8_C(152),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -378.42), SIMDE_FLOAT64_C( -112.43),
                         SIMDE_FLOAT64_C( -147.85), SIMDE_FLOAT64_C(  481.16),
                         SIMDE_FLOAT64_C(  980.68), SIMDE_FLOAT64_C(  999.62),
                         SIMDE_FLOAT64_C( -784.92), SIMDE_FLOAT64_C( -245.05)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  838.26), SIMDE_FLOAT64_C( -863.14),
                         SIMDE_FLOAT64_C(  336.07), SIMDE_FLOAT64_C(  237.32),
                         SIMDE_FLOAT64_C( -803.75), SIMDE_FLOAT64_C(  816.96),
                         SIMDE_FLOAT64_C(  217.54), SIMDE_FLOAT64_C( -660.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.27), SIMDE_FLOAT64_C( -545.33),
                         SIMDE_FLOAT64_C( -993.85), SIMDE_FLOAT64_C(  224.06),
                         SIMDE_FLOAT64_C(  768.50), SIMDE_FLOAT64_C( -560.48),
                         SIMDE_FLOAT64_C( -264.88), SIMDE_FLOAT64_C(  866.66)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  106.10), SIMDE_FLOAT64_C(  605.57),
                         SIMDE_FLOAT64_C(  481.85), SIMDE_FLOAT64_C(  491.86),
                         SIMDE_FLOAT64_C(  -77.86), SIMDE_FLOAT64_C( -839.61),
                         SIMDE_FLOAT64_C(  936.76), SIMDE_FLOAT64_C( -659.60)),
      UINT8_C(  7),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  505.82), SIMDE_FLOAT64_C( -629.98),
                         SIMDE_FLOAT64_C( -555.91), SIMDE_FLOAT64_C( -911.21),
                         SIMDE_FLOAT64_C(  603.24), SIMDE_FLOAT64_C(  -95.72),
                         SIMDE_FLOAT64_C(  864.74), SIMDE_FLOAT64_C(  280.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  570.36), SIMDE_FLOAT64_C(  765.47),
                         SIMDE_FLOAT64_C(  327.71), SIMDE_FLOAT64_C( -605.34),
                         SIMDE_FLOAT64_C(  509.13), SIMDE_FLOAT64_C( -583.43),
                         SIMDE_FLOAT64_C( -208.99), SIMDE_FLOAT64_C(  835.11)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  106.10), SIMDE_FLOAT64_C(  605.57),
                         SIMDE_FLOAT64_C(  481.85), SIMDE_FLOAT64_C(  491.86),
                         SIMDE_FLOAT64_C(  -77.86), SIMDE_FLOAT64_C(   -2.27),
                         SIMDE_FLOAT64_C(    3.25), SIMDE_FLOAT64_C(    2.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -925.64), SIMDE_FLOAT64_C(  122.27),
                         SIMDE_FLOAT64_C( -971.29), SIMDE_FLOAT64_C( -200.64),
                         SIMDE_FLOAT64_C(  268.43), SIMDE_FLOAT64_C(  995.23),
                         SIMDE_FLOAT64_C(  958.62), SIMDE_FLOAT64_C( -530.89)),
      UINT8_C(252),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -311.17), SIMDE_FLOAT64_C( -787.17),
                         SIMDE_FLOAT64_C( -427.34), SIMDE_FLOAT64_C(  839.17),
                         SIMDE_FLOAT64_C( -404.83), SIMDE_FLOAT64_C(  559.72),
                         SIMDE_FLOAT64_C(  982.82), SIMDE_FLOAT64_C( -251.36)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  643.61), SIMDE_FLOAT64_C(  953.53),
                         SIMDE_FLOAT64_C( -469.49), SIMDE_FLOAT64_C(   -8.31),
                         SIMDE_FLOAT64_C(  325.63), SIMDE_FLOAT64_C( -753.50),
                         SIMDE_FLOAT64_C( -462.28), SIMDE_FLOAT64_C( -779.29)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  785.01),
                         SIMDE_FLOAT64_C( -385.33), SIMDE_FLOAT64_C(    2.01),
                         SIMDE_FLOAT64_C(  260.50), SIMDE_FLOAT64_C(  545.50),
                         SIMDE_FLOAT64_C(  958.62), SIMDE_FLOAT64_C( -530.89)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -62.82), SIMDE_FLOAT64_C(  -95.66),
                         SIMDE_FLOAT64_C(  484.39), SIMDE_FLOAT64_C( -736.85),
                         SIMDE_FLOAT64_C(  893.63), SIMDE_FLOAT64_C( -173.06),
                         SIMDE_FLOAT64_C(  113.69), SIMDE_FLOAT64_C(  198.15)),
      UINT8_C(239),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  440.07), SIMDE_FLOAT64_C(  639.74),
                         SIMDE_FLOAT64_C(  566.84), SIMDE_FLOAT64_C(  207.87),
                         SIMDE_FLOAT64_C( -578.31), SIMDE_FLOAT64_C( -772.29),
                         SIMDE_FLOAT64_C(   70.78), SIMDE_FLOAT64_C(  181.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -750.95), SIMDE_FLOAT64_C(  172.27),
                         SIMDE_FLOAT64_C( -538.71), SIMDE_FLOAT64_C( -512.10),
                         SIMDE_FLOAT64_C( -406.87), SIMDE_FLOAT64_C( -470.10),
                         SIMDE_FLOAT64_C( -652.40), SIMDE_FLOAT64_C( -121.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.38), SIMDE_FLOAT64_C(    2.19),
                         SIMDE_FLOAT64_C(  530.58), SIMDE_FLOAT64_C( -736.85),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(   -3.02),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(   44.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_and_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
   {  UINT16_C(57131),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   399.48), SIMDE_FLOAT32_C(  -238.06), SIMDE_FLOAT32_C(  -893.32), SIMDE_FLOAT32_C(  -435.26),
                         SIMDE_FLOAT32_C(   522.86), SIMDE_FLOAT32_C(  -612.44), SIMDE_FLOAT32_C(   652.00), SIMDE_FLOAT32_C(   895.17),
                         SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(   533.04), SIMDE_FLOAT32_C(   403.71), SIMDE_FLOAT32_C(   282.24),
                         SIMDE_FLOAT32_C(   883.67), SIMDE_FLOAT32_C(    22.67), SIMDE_FLOAT32_C(   804.53), SIMDE_FLOAT32_C(   307.97)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   932.69), SIMDE_FLOAT32_C(   912.86), SIMDE_FLOAT32_C(   409.21), SIMDE_FLOAT32_C(   585.68),
                         SIMDE_FLOAT32_C(   -59.99), SIMDE_FLOAT32_C(  -146.01), SIMDE_FLOAT32_C(   160.06), SIMDE_FLOAT32_C(  -248.23),
                         SIMDE_FLOAT32_C(   780.27), SIMDE_FLOAT32_C(  -642.04), SIMDE_FLOAT32_C(   -94.76), SIMDE_FLOAT32_C(   563.52),
                         SIMDE_FLOAT32_C(  -953.85), SIMDE_FLOAT32_C(  -735.06), SIMDE_FLOAT32_C(   312.07), SIMDE_FLOAT32_C(  -630.77)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.02), SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.25),
                         SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     3.38),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   817.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(     2.40)) },
   {  UINT16_C(37107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   145.79), SIMDE_FLOAT32_C(  -588.79), SIMDE_FLOAT32_C(   895.99), SIMDE_FLOAT32_C(  -454.35),
                         SIMDE_FLOAT32_C(   444.71), SIMDE_FLOAT32_C(   343.63), SIMDE_FLOAT32_C(   -33.93), SIMDE_FLOAT32_C(  -461.47),
                         SIMDE_FLOAT32_C(   -87.51), SIMDE_FLOAT32_C(  -587.34), SIMDE_FLOAT32_C(   -54.40), SIMDE_FLOAT32_C(  -339.84),
                         SIMDE_FLOAT32_C(  -976.14), SIMDE_FLOAT32_C(   850.15), SIMDE_FLOAT32_C(  -700.02), SIMDE_FLOAT32_C(  -579.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   720.42), SIMDE_FLOAT32_C(  -585.67), SIMDE_FLOAT32_C(  -388.81), SIMDE_FLOAT32_C(   165.49),
                         SIMDE_FLOAT32_C(   525.65), SIMDE_FLOAT32_C(   441.42), SIMDE_FLOAT32_C(   424.69), SIMDE_FLOAT32_C(   567.94),
                         SIMDE_FLOAT32_C(  -243.26), SIMDE_FLOAT32_C(   977.37), SIMDE_FLOAT32_C(  -705.87), SIMDE_FLOAT32_C(   365.97),
                         SIMDE_FLOAT32_C(  -511.37), SIMDE_FLOAT32_C(   335.33), SIMDE_FLOAT32_C(  -871.52), SIMDE_FLOAT32_C(  -805.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   161.17),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   -40.75), SIMDE_FLOAT32_C(   577.34), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(   321.81),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -548.02), SIMDE_FLOAT32_C(  -513.07)) },
   {  UINT16_C(56908),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   813.26), SIMDE_FLOAT32_C(  -716.74), SIMDE_FLOAT32_C(  -548.55), SIMDE_FLOAT32_C(   -83.12),
                         SIMDE_FLOAT32_C(   301.84), SIMDE_FLOAT32_C(  -843.69), SIMDE_FLOAT32_C(  -236.76), SIMDE_FLOAT32_C(   -34.42),
                         SIMDE_FLOAT32_C(  -591.83), SIMDE_FLOAT32_C(    11.80), SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -937.14),
                         SIMDE_FLOAT32_C(  -662.16), SIMDE_FLOAT32_C(  -974.03), SIMDE_FLOAT32_C(   576.46), SIMDE_FLOAT32_C(   704.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   914.44), SIMDE_FLOAT32_C(  -904.34), SIMDE_FLOAT32_C(    -4.84), SIMDE_FLOAT32_C(   -59.72),
                         SIMDE_FLOAT32_C(  -523.01), SIMDE_FLOAT32_C(   236.78), SIMDE_FLOAT32_C(    88.72), SIMDE_FLOAT32_C(  -251.99),
                         SIMDE_FLOAT32_C(  -782.65), SIMDE_FLOAT32_C(   -38.86), SIMDE_FLOAT32_C(   670.53), SIMDE_FLOAT32_C(   706.52),
                         SIMDE_FLOAT32_C(   990.40), SIMDE_FLOAT32_C(  -812.48), SIMDE_FLOAT32_C(  -152.33), SIMDE_FLOAT32_C(   172.86)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   768.25), SIMDE_FLOAT32_C(  -648.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -41.53),
                         SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(    40.06), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   662.13), SIMDE_FLOAT32_C(  -780.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(13045),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -696.33), SIMDE_FLOAT32_C(  -640.98), SIMDE_FLOAT32_C(  -234.04), SIMDE_FLOAT32_C(   691.30),
                         SIMDE_FLOAT32_C(   422.16), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(   150.98), SIMDE_FLOAT32_C(  -727.93),
                         SIMDE_FLOAT32_C(  -292.95), SIMDE_FLOAT32_C(  -168.48), SIMDE_FLOAT32_C(   430.75), SIMDE_FLOAT32_C(   298.75),
                         SIMDE_FLOAT32_C(  -938.39), SIMDE_FLOAT32_C(   166.50), SIMDE_FLOAT32_C(   295.10), SIMDE_FLOAT32_C(   -66.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   725.67), SIMDE_FLOAT32_C(   691.57), SIMDE_FLOAT32_C(   408.92), SIMDE_FLOAT32_C(  -190.91),
                         SIMDE_FLOAT32_C(   682.56), SIMDE_FLOAT32_C(   311.99), SIMDE_FLOAT32_C(  -213.61), SIMDE_FLOAT32_C(  -160.20),
                         SIMDE_FLOAT32_C(  -421.91), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(   657.47), SIMDE_FLOAT32_C(   816.91),
                         SIMDE_FLOAT32_C(   267.68), SIMDE_FLOAT32_C(   898.52), SIMDE_FLOAT32_C(   -80.12), SIMDE_FLOAT32_C(  -724.23)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   200.00), SIMDE_FLOAT32_C(     2.70),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   148.59), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -292.88), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(     2.06),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -2.08)) },
   {  UINT16_C(11913),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   315.17), SIMDE_FLOAT32_C(  -863.78), SIMDE_FLOAT32_C(   344.73), SIMDE_FLOAT32_C(  -570.00),
                         SIMDE_FLOAT32_C(  -265.79), SIMDE_FLOAT32_C(   403.67), SIMDE_FLOAT32_C(   -62.80), SIMDE_FLOAT32_C(   251.47),
                         SIMDE_FLOAT32_C(   143.15), SIMDE_FLOAT32_C(   960.55), SIMDE_FLOAT32_C(  -156.81), SIMDE_FLOAT32_C(   258.89),
                         SIMDE_FLOAT32_C(    14.13), SIMDE_FLOAT32_C(   117.08), SIMDE_FLOAT32_C(  -266.20), SIMDE_FLOAT32_C(   383.43)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -568.28), SIMDE_FLOAT32_C(  -745.49), SIMDE_FLOAT32_C(  -964.75), SIMDE_FLOAT32_C(   259.38),
                         SIMDE_FLOAT32_C(   750.99), SIMDE_FLOAT32_C(  -521.20), SIMDE_FLOAT32_C(   513.21), SIMDE_FLOAT32_C(   787.79),
                         SIMDE_FLOAT32_C(   316.72), SIMDE_FLOAT32_C(   -19.08), SIMDE_FLOAT32_C(  -845.60), SIMDE_FLOAT32_C(   815.31),
                         SIMDE_FLOAT32_C(  -301.01), SIMDE_FLOAT32_C(   479.36), SIMDE_FLOAT32_C(  -159.67), SIMDE_FLOAT32_C(  -155.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   142.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     8.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   155.69)) },
   {  UINT16_C(38742),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -500.21), SIMDE_FLOAT32_C(  -899.42), SIMDE_FLOAT32_C(   770.51), SIMDE_FLOAT32_C(   777.58),
                         SIMDE_FLOAT32_C(   547.07), SIMDE_FLOAT32_C(   747.18), SIMDE_FLOAT32_C(    16.17), SIMDE_FLOAT32_C(   859.01),
                         SIMDE_FLOAT32_C(    78.72), SIMDE_FLOAT32_C(  -378.16), SIMDE_FLOAT32_C(  -980.04), SIMDE_FLOAT32_C(   143.56),
                         SIMDE_FLOAT32_C(  -706.63), SIMDE_FLOAT32_C(  -986.84), SIMDE_FLOAT32_C(  -673.32), SIMDE_FLOAT32_C(  -774.96)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -321.38), SIMDE_FLOAT32_C(  -244.51), SIMDE_FLOAT32_C(   579.94), SIMDE_FLOAT32_C(   895.47),
                         SIMDE_FLOAT32_C(  -321.30), SIMDE_FLOAT32_C(    92.97), SIMDE_FLOAT32_C(  -270.40), SIMDE_FLOAT32_C(  -439.43),
                         SIMDE_FLOAT32_C(   971.85), SIMDE_FLOAT32_C(   799.33), SIMDE_FLOAT32_C(   -17.61), SIMDE_FLOAT32_C(  -762.15),
                         SIMDE_FLOAT32_C(  -813.48), SIMDE_FLOAT32_C(   494.42), SIMDE_FLOAT32_C(   374.64), SIMDE_FLOAT32_C(  -744.47)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -320.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   777.06),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.89), SIMDE_FLOAT32_C(    16.13), SIMDE_FLOAT32_C(     3.29),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.23),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     3.85), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(53846),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   400.20), SIMDE_FLOAT32_C(   275.50), SIMDE_FLOAT32_C(   916.86), SIMDE_FLOAT32_C(  -531.67),
                         SIMDE_FLOAT32_C(  -909.37), SIMDE_FLOAT32_C(   993.65), SIMDE_FLOAT32_C(   633.64), SIMDE_FLOAT32_C(  -178.42),
                         SIMDE_FLOAT32_C(   412.35), SIMDE_FLOAT32_C(  -571.03), SIMDE_FLOAT32_C(   345.26), SIMDE_FLOAT32_C(   493.12),
                         SIMDE_FLOAT32_C(  -719.68), SIMDE_FLOAT32_C(   769.35), SIMDE_FLOAT32_C(  -373.84), SIMDE_FLOAT32_C(  -540.22)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -282.19), SIMDE_FLOAT32_C(  -584.18), SIMDE_FLOAT32_C(   433.06), SIMDE_FLOAT32_C(   752.23),
                         SIMDE_FLOAT32_C(  -792.10), SIMDE_FLOAT32_C(   940.65), SIMDE_FLOAT32_C(  -237.54), SIMDE_FLOAT32_C(  -796.45),
                         SIMDE_FLOAT32_C(   821.11), SIMDE_FLOAT32_C(  -769.48), SIMDE_FLOAT32_C(   951.19), SIMDE_FLOAT32_C(   526.89),
                         SIMDE_FLOAT32_C(   481.01), SIMDE_FLOAT32_C(  -678.70), SIMDE_FLOAT32_C(   690.79), SIMDE_FLOAT32_C(  -617.07)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   272.19), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   528.17),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.19), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -513.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.04),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   512.07), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(45516),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -637.18), SIMDE_FLOAT32_C(   934.54), SIMDE_FLOAT32_C(   112.29), SIMDE_FLOAT32_C(   139.60),
                         SIMDE_FLOAT32_C(  -371.31), SIMDE_FLOAT32_C(  -676.65), SIMDE_FLOAT32_C(  -607.44), SIMDE_FLOAT32_C(  -108.80),
                         SIMDE_FLOAT32_C(  -631.32), SIMDE_FLOAT32_C(   553.47), SIMDE_FLOAT32_C(  -653.07), SIMDE_FLOAT32_C(  -272.71),
                         SIMDE_FLOAT32_C(  -438.05), SIMDE_FLOAT32_C(   -69.28), SIMDE_FLOAT32_C(   220.30), SIMDE_FLOAT32_C(  -879.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   695.29), SIMDE_FLOAT32_C(  -288.10), SIMDE_FLOAT32_C(     8.22), SIMDE_FLOAT32_C(   267.50),
                         SIMDE_FLOAT32_C(  -160.08), SIMDE_FLOAT32_C(   251.69), SIMDE_FLOAT32_C(   416.95), SIMDE_FLOAT32_C(   429.19),
                         SIMDE_FLOAT32_C(  -938.09), SIMDE_FLOAT32_C(  -996.83), SIMDE_FLOAT32_C(   772.01), SIMDE_FLOAT32_C(   -88.73),
                         SIMDE_FLOAT32_C(  -661.22), SIMDE_FLOAT32_C(  -945.44), SIMDE_FLOAT32_C(   528.59), SIMDE_FLOAT32_C(   677.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   565.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   129.50),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   104.30),
                         SIMDE_FLOAT32_C(  -546.07), SIMDE_FLOAT32_C(   544.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(    -2.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_maskz_and_ps(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
   {  UINT8_C( 62),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  337.23), SIMDE_FLOAT64_C( -706.51),
                         SIMDE_FLOAT64_C(  -51.03), SIMDE_FLOAT64_C(  -11.12),
                         SIMDE_FLOAT64_C(  780.39), SIMDE_FLOAT64_C(  482.32),
                         SIMDE_FLOAT64_C( -313.20), SIMDE_FLOAT64_C(  986.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -459.33), SIMDE_FLOAT64_C(  566.75),
                         SIMDE_FLOAT64_C(  454.16), SIMDE_FLOAT64_C( -566.29),
                         SIMDE_FLOAT64_C(  217.01), SIMDE_FLOAT64_C( -444.68),
                         SIMDE_FLOAT64_C(  725.53), SIMDE_FLOAT64_C( -673.17)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(   48.02), SIMDE_FLOAT64_C(   -2.02),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(  416.00),
                         SIMDE_FLOAT64_C(    2.31), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(178),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  988.70), SIMDE_FLOAT64_C(  952.56),
                         SIMDE_FLOAT64_C( -917.57), SIMDE_FLOAT64_C( -161.93),
                         SIMDE_FLOAT64_C(  553.05), SIMDE_FLOAT64_C(  358.83),
                         SIMDE_FLOAT64_C( -335.21), SIMDE_FLOAT64_C(  243.33)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  368.67), SIMDE_FLOAT64_C( -326.68),
                         SIMDE_FLOAT64_C( -767.44), SIMDE_FLOAT64_C( -965.45),
                         SIMDE_FLOAT64_C(  160.34), SIMDE_FLOAT64_C( -153.49),
                         SIMDE_FLOAT64_C(  842.87), SIMDE_FLOAT64_C( -959.77)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.75), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -661.06), SIMDE_FLOAT64_C(   -2.52),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    2.04), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(233),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  789.99), SIMDE_FLOAT64_C(   -0.83),
                         SIMDE_FLOAT64_C( -595.87), SIMDE_FLOAT64_C( -556.04),
                         SIMDE_FLOAT64_C( -673.58), SIMDE_FLOAT64_C(  820.52),
                         SIMDE_FLOAT64_C(  763.24), SIMDE_FLOAT64_C(  747.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -863.51), SIMDE_FLOAT64_C(  297.93),
                         SIMDE_FLOAT64_C(  664.70), SIMDE_FLOAT64_C(   43.00),
                         SIMDE_FLOAT64_C(  283.69), SIMDE_FLOAT64_C( -882.73),
                         SIMDE_FLOAT64_C(   56.70), SIMDE_FLOAT64_C( -683.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  789.50), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  528.57), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    2.13), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  683.04)) },
   {  UINT8_C( 29),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -942.62), SIMDE_FLOAT64_C(  810.42),
                         SIMDE_FLOAT64_C( -781.08), SIMDE_FLOAT64_C(  565.31),
                         SIMDE_FLOAT64_C( -528.23), SIMDE_FLOAT64_C( -642.03),
                         SIMDE_FLOAT64_C( -124.04), SIMDE_FLOAT64_C(  -13.65)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   20.85), SIMDE_FLOAT64_C( -517.24),
                         SIMDE_FLOAT64_C(  -21.32), SIMDE_FLOAT64_C(  729.98),
                         SIMDE_FLOAT64_C( -763.15), SIMDE_FLOAT64_C(  885.38),
                         SIMDE_FLOAT64_C(  783.63), SIMDE_FLOAT64_C(  470.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  529.29),
                         SIMDE_FLOAT64_C( -528.13), SIMDE_FLOAT64_C(  512.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   12.63)) },
   {  UINT8_C(102),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -36.60), SIMDE_FLOAT64_C(  -71.02),
                         SIMDE_FLOAT64_C(  654.55), SIMDE_FLOAT64_C( -335.18),
                         SIMDE_FLOAT64_C( -889.86), SIMDE_FLOAT64_C( -624.64),
                         SIMDE_FLOAT64_C(  369.01), SIMDE_FLOAT64_C(  798.90)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -217.14), SIMDE_FLOAT64_C( -334.27),
                         SIMDE_FLOAT64_C(  522.28), SIMDE_FLOAT64_C(  754.78),
                         SIMDE_FLOAT64_C( -987.63), SIMDE_FLOAT64_C(  746.58),
                         SIMDE_FLOAT64_C(  358.61), SIMDE_FLOAT64_C( -154.14)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  -67.00),
                         SIMDE_FLOAT64_C(  522.02), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  608.50),
                         SIMDE_FLOAT64_C(  352.00), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(126),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -16.31), SIMDE_FLOAT64_C(  -95.18),
                         SIMDE_FLOAT64_C(  860.06), SIMDE_FLOAT64_C(  464.41),
                         SIMDE_FLOAT64_C(  822.39), SIMDE_FLOAT64_C(  185.79),
                         SIMDE_FLOAT64_C(  959.83), SIMDE_FLOAT64_C(  -98.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -560.42), SIMDE_FLOAT64_C( -521.57),
                         SIMDE_FLOAT64_C( -947.45), SIMDE_FLOAT64_C(   99.55),
                         SIMDE_FLOAT64_C(  108.53), SIMDE_FLOAT64_C(  194.26),
                         SIMDE_FLOAT64_C(  449.89), SIMDE_FLOAT64_C(  718.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -2.04),
                         SIMDE_FLOAT64_C(  784.01), SIMDE_FLOAT64_C(   96.03),
                         SIMDE_FLOAT64_C(    3.14), SIMDE_FLOAT64_C(  128.26),
                         SIMDE_FLOAT64_C(    3.51), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(231),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -343.46), SIMDE_FLOAT64_C(  643.05),
                         SIMDE_FLOAT64_C(  758.23), SIMDE_FLOAT64_C(  243.41),
                         SIMDE_FLOAT64_C( -569.27), SIMDE_FLOAT64_C(   62.99),
                         SIMDE_FLOAT64_C(  403.36), SIMDE_FLOAT64_C( -111.26)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  594.69), SIMDE_FLOAT64_C(  416.92),
                         SIMDE_FLOAT64_C(  294.94), SIMDE_FLOAT64_C( -386.69),
                         SIMDE_FLOAT64_C(  444.27), SIMDE_FLOAT64_C(  112.48),
                         SIMDE_FLOAT64_C(  775.25), SIMDE_FLOAT64_C(  973.66)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(    2.27), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   56.24),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(    3.28)) },
   {  UINT8_C(248),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  559.94), SIMDE_FLOAT64_C( -177.36),
                         SIMDE_FLOAT64_C(  459.52), SIMDE_FLOAT64_C(  151.00),
                         SIMDE_FLOAT64_C( -261.20), SIMDE_FLOAT64_C(  619.75),
                         SIMDE_FLOAT64_C( -541.43), SIMDE_FLOAT64_C( -420.37)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  279.51), SIMDE_FLOAT64_C(  143.05),
                         SIMDE_FLOAT64_C(  835.37), SIMDE_FLOAT64_C( -486.11),
                         SIMDE_FLOAT64_C(  461.53), SIMDE_FLOAT64_C(  410.57),
                         SIMDE_FLOAT64_C( -362.30), SIMDE_FLOAT64_C( -345.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.18), SIMDE_FLOAT64_C(  129.05),
                         SIMDE_FLOAT64_C(    3.01), SIMDE_FLOAT64_C(  147.00),
                         SIMDE_FLOAT64_C(  261.01), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_maskz_and_pd(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_andnot_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  515723887), INT32_C( 1640697809), INT32_C(-1815268655), INT32_C( -855842079),
                            INT32_C( -876731021), INT32_C( -422224087), INT32_C( 1402147089), INT32_C(  791567468),
                            INT32_C( -405953943), INT32_C(  280958773), INT32_C(  359942894), INT32_C( -574064836),
                            INT32_C( 1041426019), INT32_C(  457085316), INT32_C( 1591682265), INT32_C( 1681068921)),
      simde_mm512_set_epi32(INT32_C(  219659736), INT32_C(  983393088), INT32_C(  175097612), INT32_C(-1948389752),
                            INT32_C(-1760046217), INT32_C(  996280401), INT32_C( -511102649), INT32_C(-1367446405),
                            INT32_C(-1955017682), INT32_C(-1962774388), INT32_C( -112156455), INT32_C( 1625681413),
                            INT32_C( -214953654), INT32_C(-1594240596), INT32_C( -837160883), INT32_C(   91929810)),
      simde_mm512_set_epi32(INT32_C(   16952720), INT32_C(  437542912), INT32_C(  136496396), INT32_C(   50400264),
                            INT32_C(  335663620), INT32_C(  421658704), INT32_C(-1610080186), INT32_C(-2142232557),
                            INT32_C(  137382918), INT32_C(-1962909560), INT32_C( -402612207), INT32_C(  539330561),
                            INT32_C(-1054863096), INT32_C(-1597947864), INT32_C(-2147430396), INT32_C(   21539970)) },
    { simde_mm512_set_epi32(INT32_C( -691442479), INT32_C(-1656332537), INT32_C( -736641091), INT32_C( 1498293216),
                            INT32_C( -507651370), INT32_C( 1481766884), INT32_C(-1911092113), INT32_C( -872210414),
                            INT32_C(  291047220), INT32_C(-1241987411), INT32_C( 1619041328), INT32_C( 1464413104),
                            INT32_C(-1017310468), INT32_C( 1540491270), INT32_C( 2102275128), INT32_C(-1414382909)),
      simde_mm512_set_epi32(INT32_C(  242206574), INT32_C(  555720064), INT32_C( -659215600), INT32_C( 1975929957),
                            INT32_C( 1131537123), INT32_C( 2072355897), INT32_C( 1377537047), INT32_C( 1623632095),
                            INT32_C(  536506999), INT32_C(-1382727392), INT32_C(   37097013), INT32_C( 2004578493),
                            INT32_C( 1803364246), INT32_C( 1342516983), INT32_C(  514234840), INT32_C(-1522858319)),
      simde_mm512_set_epi32(INT32_C(  136741678), INT32_C(  538542208), INT32_C(  144703488), INT32_C(  612387845),
                            INT32_C(   37756961), INT32_C(  595853337), INT32_C( 1342734352), INT32_C(  549750989),
                            INT32_C(  245526595), INT32_C(  134545664), INT32_C(   37093893), INT32_C(  540168205),
                            INT32_C(  673195266), INT32_C(     337649), INT32_C(   44077504), INT32_C(   67699760)) },
    { simde_mm512_set_epi32(INT32_C(  835536002), INT32_C(  -63027427), INT32_C( 2017135186), INT32_C(-1844829768),
                            INT32_C(  936597093), INT32_C( -389163916), INT32_C(-1786076372), INT32_C(   62625566),
                            INT32_C(-1459727459), INT32_C( 1125674521), INT32_C(-1286537639), INT32_C(  550088134),
                            INT32_C(  -31520277), INT32_C(-1814664190), INT32_C( 1588224923), INT32_C( 1901241906)),
      simde_mm512_set_epi32(INT32_C( -684209907), INT32_C( 1116413094), INT32_C(  -29612798), INT32_C(-1906935505),
                            INT32_C( 1879010472), INT32_C( -984076172), INT32_C( -987963932), INT32_C(-1705792694),
                            INT32_C( 1395521155), INT32_C( 2062716504), INT32_C( 1645135174), INT32_C(  273600119),
                            INT32_C( -650211201), INT32_C( 1039685180), INT32_C(-1680417560), INT32_C( -160711201)),
      simde_mm512_set_epi32(INT32_C( -969766643), INT32_C(   42014882), INT32_C(-2046548736), INT32_C(  206854151),
                            INT32_C( 1210853512), INT32_C(   84942848), INT32_C( 1075076288), INT32_C(-1740625856),
                            INT32_C( 1392616450), INT32_C(  954368064), INT32_C( 1074659590), INT32_C(  268845617),
                            INT32_C(   18911252), INT32_C(  740823612), INT32_C(-2125161376), INT32_C(-2044126771)) },
    { simde_mm512_set_epi32(INT32_C( -911319633), INT32_C(-1035947605), INT32_C(  -14347010), INT32_C(  135240154),
                            INT32_C( 1039097026), INT32_C(-1325726567), INT32_C( 1814577462), INT32_C( -309546152),
                            INT32_C( 2107794809), INT32_C( -690752206), INT32_C(-1567183976), INT32_C( 1570875131),
                            INT32_C( -359037430), INT32_C( 1064726494), INT32_C( -305221103), INT32_C( 2039553475)),
      simde_mm512_set_epi32(INT32_C( -358609490), INT32_C( 1748558231), INT32_C(  769947846), INT32_C(-2114787166),
                            INT32_C( 1221765938), INT32_C(-1846472677), INT32_C(  893676657), INT32_C(-2056337544),
                            INT32_C(-1125244927), INT32_C(-2123257127), INT32_C( 1395407144), INT32_C(-2100494303),
                            INT32_C(  123622128), INT32_C( -234312093), INT32_C( 1320504606), INT32_C( -696459867)),
      simde_mm512_set_epi32(INT32_C(  570425344), INT32_C(  674775060), INT32_C(   12609536), INT32_C(-2114953184),
                            INT32_C( 1074832176), INT32_C(   16781314), INT32_C(  289680449), INT32_C(    6439968),
                            INT32_C(-2142502912), INT32_C(   18877129), INT32_C( 1361580064), INT32_C(-2108948480),
                            INT32_C(   88494320), INT32_C(-1073184735), INT32_C(   36785422), INT32_C(-2039693276)) },
    { simde_mm512_set_epi32(INT32_C( 1741169869), INT32_C(-1806166644), INT32_C( 1030404360), INT32_C( 1645919232),
                            INT32_C( -724495967), INT32_C( 1251263729), INT32_C( -769398486), INT32_C(-1951408118),
                            INT32_C( 1006137744), INT32_C( -650052668), INT32_C( 1803988670), INT32_C( -565766270),
                            INT32_C(-2075332822), INT32_C(  -77783473), INT32_C( 1442895719), INT32_C( -423885068)),
      simde_mm512_set_epi32(INT32_C(-1467349800), INT32_C(-1486916034), INT32_C(  580711779), INT32_C( 1504148541),
                            INT32_C(  661197291), INT32_C( 2016703871), INT32_C(  459937445), INT32_C( 1081922115),
                            INT32_C(   93168137), INT32_C( -744509287), INT32_C(  -84767472), INT32_C( 1535078904),
                            INT32_C( 1804568444), INT32_C(-1641570308), INT32_C( 1307677448), INT32_C( -156993467)),
      simde_mm512_set_epi32(INT32_C(-2013134832), INT32_C(  587686450), INT32_C(   43271267), INT32_C(  430260285),
                            INT32_C(  589824074), INT32_C(  807416078), INT32_C(  155719301), INT32_C( 1078989377),
                            INT32_C(   67469833), INT32_C(   43974681), INT32_C(-1871707904), INT32_C(   20471928),
                            INT32_C( 1803747412), INT32_C(   69370288), INT32_C(  166789128), INT32_C(  268466177)) },
    { simde_mm512_set_epi32(INT32_C( -789590264), INT32_C( 1747530260), INT32_C(  250254813), INT32_C(  -46824160),
                            INT32_C( 1521185343), INT32_C( 1710396447), INT32_C( -401960034), INT32_C(  376331638),
                            INT32_C( -481899788), INT32_C(  951540577), INT32_C(-1886694025), INT32_C( -615462627),
                            INT32_C(-1246126101), INT32_C( 1628361415), INT32_C( 1197988194), INT32_C(-1740462923)),
      simde_mm512_set_epi32(INT32_C( 1235841465), INT32_C(-1524332124), INT32_C( 1158299501), INT32_C(-2030663913),
                            INT32_C( -368124005), INT32_C( -216689066), INT32_C( 2049678955), INT32_C(-1811053975),
                            INT32_C( -579248849), INT32_C(  817648154), INT32_C( 1351147076), INT32_C( -248769414),
                            INT32_C( 1542937557), INT32_C(-1429188342), INT32_C(  753897242), INT32_C( -407543559)),
      simde_mm512_set_epi32(INT32_C(  151007409), INT32_C(-2063300192), INT32_C( 1090529824), INT32_C(   46268951),
                            INT32_C(-1610314368), INT32_C(-1845165504), INT32_C(  304155745), INT32_C(-2147384823),
                            INT32_C(  473502987), INT32_C(     524314), INT32_C( 1342212608), INT32_C(  539759714),
                            INT32_C( 1246117908), INT32_C(-1966079736), INT32_C(  680003096), INT32_C( 1739931720)) },
    { simde_mm512_set_epi32(INT32_C( 1871269268), INT32_C(  408476277), INT32_C(  620349445), INT32_C(   85656022),
                            INT32_C(  530242315), INT32_C( 1600939321), INT32_C( 1166499662), INT32_C(  550456559),
                            INT32_C( 1205553840), INT32_C( -507718293), INT32_C( -629410605), INT32_C(-1400491933),
                            INT32_C(-1740280079), INT32_C(  470828561), INT32_C(  710611826), INT32_C( 1460766627)),
      simde_mm512_set_epi32(INT32_C(  132567711), INT32_C( -504432561), INT32_C( 1784336368), INT32_C(-1195419261),
                            INT32_C(-1432068840), INT32_C( -756951336), INT32_C(  519218456), INT32_C( 2068445443),
                            INT32_C( -769032976), INT32_C(-1464370595), INT32_C( -636201129), INT32_C(  798298919),
                            INT32_C(  605141360), INT32_C( 1690763202), INT32_C(  743563485), INT32_C( 1615889032)),
      simde_mm512_set_epi32(INT32_C(    6722059), INT32_C( -509206518), INT32_C( 1241647088), INT32_C(-1197189119),
                            INT32_C(-1608252400), INT32_C(-2138991936), INT32_C(  443588624), INT32_C( 1526771968),
                            INT32_C(-1876937664), INT32_C(  134425108), INT32_C(     262916), INT32_C(   51446532),
                            INT32_C(  605065472), INT32_C( 1623636418), INT32_C(   67166349), INT32_C(  541065224)) },
    { simde_mm512_set_epi32(INT32_C( 1287269628), INT32_C( 1003736038), INT32_C(  977850641), INT32_C(-1038923525),
                            INT32_C( -628842024), INT32_C( 1597060388), INT32_C( -643406365), INT32_C(-1390651863),
                            INT32_C( 1433162166), INT32_C(  -27649596), INT32_C( -695421854), INT32_C( 1977918902),
                            INT32_C(-1118619506), INT32_C(  218268934), INT32_C(  602753386), INT32_C( -663684258)),
      simde_mm512_set_epi32(INT32_C(  238738926), INT32_C( 1501256933), INT32_C( -668514921), INT32_C(  178997567),
                            INT32_C(  618897994), INT32_C(-1305584804), INT32_C(  287401445), INT32_C( -682321436),
                            INT32_C(-1248279406), INT32_C(-1232466621), INT32_C( 1932263578), INT32_C( 1672045836),
                            INT32_C(  -31634555), INT32_C( -429030840), INT32_C( 1478948841), INT32_C( -636575791)),
      simde_mm512_set_epi32(INT32_C(   33607938), INT32_C( 1076368385), INT32_C(-1071184762), INT32_C(  145228036),
                            INT32_C(  610468354), INT32_C(-1609676200), INT32_C(      65540), INT32_C( 1379961284),
                            INT32_C(-1601141760), INT32_C(    8389635), INT32_C(  555745432), INT32_C(   34160648),
                            INT32_C( 1108099841), INT32_C( -496172472), INT32_C( 1476572801), INT32_C(   34473089)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castps_si512(simde_mm512_andnot_ps(simde_mm512_castsi512_ps(test_vec[i].a), simde_mm512_castsi512_ps(test_vec[i].b)));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_andnot_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-5692392796256408556), INT64_C( 6556277497990144923),
                            INT64_C(-8451768093244871108), INT64_C( 2502789693644361692),
                            INT64_C( 1621880469938104082), INT64_C(-7297255235572331483),
                            INT64_C(-2352677665930074905), INT64_C( 4911158619134204312)),
      simde_mm512_set_epi64(INT64_C(-2565389980846007780), INT64_C( 3404730604833389160),
                            INT64_C( 1179026943527716274), INT64_C(-2906973067026822223),
                            INT64_C( 7260818647608791158), INT64_C( 5579870493016706466),
                            INT64_C( 3863525595432901356), INT64_C(-6057345860275027490)),
      simde_mm512_set_epi64(INT64_C( 5504912800215142920), INT64_C( 2666140128227367008),
                            INT64_C( 1173388089487589762), INT64_C(-3098395176816541663),
                            INT64_C( 6935978858541748324), INT64_C( 4991411844055941506),
                            INT64_C( 2343560720521648648), INT64_C(-6068587301518688186)) },
    { simde_mm512_set_epi64(INT64_C(-2759528052506956708), INT64_C(-5575162278173961328),
                            INT64_C(-8694367187788105741), INT64_C(-8990346118631710119),
                            INT64_C( 4592063463963295950), INT64_C( 8368804684692221223),
                            INT64_C(-6476206435262682842), INT64_C(-8876450871330607726)),
      simde_mm512_set_epi64(INT64_C(-6737293364691021911), INT64_C(-4204449908398867590),
                            INT64_C(  160841008688998741), INT64_C(-6365408201349652038),
                            INT64_C( 2001896472947132682), INT64_C(  -99471897253479533),
                            INT64_C(-1326129419939093389), INT64_C(-2924053864540399741)),
      simde_mm512_set_epi64(INT64_C( 2450046296219059105), INT64_C( 4973873968629295210),
                            INT64_C(   11267795499616260), INT64_C( 2630102325595865506),
                            INT64_C(   18051886326876416), INT64_C(-8458876851257732464),
                            INT64_C( 5296233507537044561), INT64_C( 5992932110406914561)) },
    { simde_mm512_set_epi64(INT64_C(-7457051575750248602), INT64_C( 6070335147558558873),
                            INT64_C(-7490477224728001543), INT64_C( 1279317055657379478),
                            INT64_C( 8751242136386772213), INT64_C(  637231009559692595),
                            INT64_C(-7114327187130069406), INT64_C( 1391778837665435621)),
      simde_mm512_set_epi64(INT64_C( 6308740259462318802), INT64_C(-9185391234602091403),
                            INT64_C( 7626881538428569222), INT64_C(-3068069010762250319),
                            INT64_C(-4951576282750300305), INT64_C(  128509774881067912),
                            INT64_C( 7892251767542575626), INT64_C(-8930995426443097321)),
      simde_mm512_set_epi64(INT64_C( 5119472124868954256), INT64_C(-9187125192365432732),
                            INT64_C( 7048133801267954694), INT64_C(-4311066996174143199),
                            INT64_C(-9076908839077919990), INT64_C(   74319038222733960),
                            INT64_C( 6954164901648707592), INT64_C(-8931156479129911278)) },
    { simde_mm512_set_epi64(INT64_C( 6964163421595280406), INT64_C( 8751199602933822917),
                            INT64_C( 3889132740347846858), INT64_C(-7126879543636862431),
                            INT64_C(-7513660375211080284), INT64_C( 6453129860776144209),
                            INT64_C(-5544576080495062479), INT64_C( 5873331717169095384)),
      simde_mm512_set_epi64(INT64_C( 8830709936142460331), INT64_C(-9018958152160609695),
                            INT64_C( 8077330800987365186), INT64_C(-8496831583043834543),
                            INT64_C(-8535629658492460138), INT64_C(-7680526102244966263),
                            INT64_C( -372932882462668779), INT64_C( 6329513109562115746)),
      simde_mm512_set_epi64(INT64_C( 1875839696979362217), INT64_C(-9042040235334956512),
                            INT64_C( 4611686019604422400), INT64_C(  145522704699106640),
                            INT64_C(  576814847044362770), INT64_C(-8907768133275565944),
                            INT64_C( 5247259266967930884), INT64_C(  456185876494468130)) },
    { simde_mm512_set_epi64(INT64_C( -351666990455047830), INT64_C(-7399285389685964954),
                            INT64_C(-5908952440536913792), INT64_C( -611732173843171755),
                            INT64_C( 7999973001790565510), INT64_C(-8075898444541975424),
                            INT64_C( 5770350522878101247), INT64_C( 1116848091668783433)),
      simde_mm512_set_epi64(INT64_C( 2217552425319516429), INT64_C(-8721047939211270856),
                            INT64_C(-2880324325532209431), INT64_C( -187231364083775137),
                            INT64_C( 6742854000402878536), INT64_C(     168773737674717),
                            INT64_C( 3418235066721438872), INT64_C( 4202828047673997422)),
      simde_mm512_set_epi64(INT64_C(  342365941483028485), INT64_C(  479783009225555992),
                            INT64_C( 5764607798056863337), INT64_C(  604680821040318730),
                            INT64_C( 1194123438370115656), INT64_C(      26768921351005),
                            INT64_C( 3413729087268849664), INT64_C( 3458800331700312102)) },
    { simde_mm512_set_epi64(INT64_C(-2132909336669479608), INT64_C(-1158827795013308041),
                            INT64_C(-7670914575902882420), INT64_C(  -69696623451151043),
                            INT64_C(-4047902191338288971), INT64_C( 7092767718101885012),
                            INT64_C( 5934909912424448575), INT64_C( 5411709750270769968)),
      simde_mm512_set_epi64(INT64_C(-7875865474019974757), INT64_C(-3285041077981983127),
                            INT64_C( 8063284926890959108), INT64_C(-3700459330126222884),
                            INT64_C(-7671356082612531796), INT64_C( 1792383659764879933),
                            INT64_C( 2583453571264272321), INT64_C( 8675197907294370872)),
      simde_mm512_set_epi64(INT64_C( 1193748656575226003), INT64_C( 1152974871187164680),
                            INT64_C( 7666393384072290304), INT64_C(   46461582121208000),
                            INT64_C( 1155463611999061256), INT64_C( 1770267941057597993),
                            INT64_C( 2414567396337178048), INT64_C( 3486980733385704456)) },
    { simde_mm512_set_epi64(INT64_C(-3578776133799908286), INT64_C(-1505161927362377530),
                            INT64_C( 1984257760933558326), INT64_C( -235993280127523291),
                            INT64_C(-5471198518359697501), INT64_C(-3736915368061275681),
                            INT64_C(-2239211533422890096), INT64_C(-3284418263843820488)),
      simde_mm512_set_epi64(INT64_C(-2978941464173404520), INT64_C( 4582889970668771380),
                            INT64_C( -557407531320217043), INT64_C( 5386308122944286215),
                            INT64_C(-2433611387892931894), INT64_C( 7741810302662188301),
                            INT64_C(   18824623009495704), INT64_C( 3999273364541981338)),
      simde_mm512_set_epi64(INT64_C( 1200223062730085016), INT64_C( 1477497354446704688),
                            INT64_C(-2287124905805331959), INT64_C(  162132485929502722),
                            INT64_C( 5343540817909325896), INT64_C( 2544569189669112832),
                            INT64_C(     633336187848712), INT64_C( 2702160884594393730)) },
    { simde_mm512_set_epi64(INT64_C(  352684271852599798), INT64_C( 4911474499221167587),
                            INT64_C( 1508056965830938497), INT64_C( 3074813921141815339),
                            INT64_C( 7701628738251481990), INT64_C( -466066103765916190),
                            INT64_C( 8562974168142071295), INT64_C( -919355185316238533)),
      simde_mm512_set_epi64(INT64_C( 4326901039471149930), INT64_C(-7137503476184318358),
                            INT64_C(-1078077923693263341), INT64_C(-1859594942180658021),
                            INT64_C(-4053912759805256064), INT64_C(-4136267192341554803),
                            INT64_C( 7711878059533707111), INT64_C(-6181901304080395815)),
      simde_mm512_set_epi64(INT64_C( 4037478715378254344), INT64_C(-7434758645930761720),
                            INT64_C(-2233710626472820718), INT64_C(-4318952040280619888),
                            INT64_C(-8855183721016321024), INT64_C(  437135751054956557),
                            INT64_C(  649099009830593024), INT64_C(  576514078768369856)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castpd_si512(simde_mm512_andnot_pd(simde_mm512_castsi512_pd(test_vec[i].a), simde_mm512_castsi512_pd(test_vec[i].b)));
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_andnot_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
     { simde_mm512_set_epi32(INT32_C(  483765022), INT32_C(-1234873154), INT32_C(-1289658932), INT32_C( 1557667178),
                            INT32_C( -573006378), INT32_C( -844585804), INT32_C(  908677468), INT32_C(  120945929),
                            INT32_C(-1595338087), INT32_C(-1433288415), INT32_C( 1272415402), INT32_C( 2052605464),
                            INT32_C(-1185243420), INT32_C(  696776161), INT32_C(  617510437), INT32_C( 1274220393)),
      UINT16_C(33954),
      simde_mm512_set_epi32(INT32_C( 1145617415), INT32_C( -605546679), INT32_C(    2927077), INT32_C(  -19849762),
                            INT32_C(-1597262180), INT32_C( -867043590), INT32_C( -107439489), INT32_C( 1287210357),
                            INT32_C( 1092392250), INT32_C( 1062404217), INT32_C( -979680700), INT32_C( 1129202470),
                            INT32_C( 1479969823), INT32_C( -738882529), INT32_C( 1249939660), INT32_C( -548556138)),
      simde_mm512_set_epi32(INT32_C(  283318882), INT32_C( 1846644474), INT32_C( 2020741558), INT32_C( 2084726692),
                            INT32_C(-1625067961), INT32_C( 1808817126), INT32_C(  188488265), INT32_C( -493292109),
                            INT32_C(-1012406283), INT32_C( 2120995640), INT32_C(-1978262848), INT32_C( -210107724),
                            INT32_C(  789544495), INT32_C(  -10089859), INT32_C( -531570606), INT32_C( 1286299547)),
      simde_mm512_set_epi32(INT32_C(  279118432), INT32_C(-1234873154), INT32_C(-1289658932), INT32_C( 1557667178),
                            INT32_C( -573006378), INT32_C(  595593476), INT32_C(  908677468), INT32_C(  120945929),
                            INT32_C(-2103221563), INT32_C(-1433288415), INT32_C(  168040576), INT32_C( 2052605464),
                            INT32_C(-1185243420), INT32_C(  696776161), INT32_C(-1605345262), INT32_C( 1274220393)) },
    { simde_mm512_set_epi32(INT32_C( -281178768), INT32_C( -360418194), INT32_C( 1198549209), INT32_C( -896335694),
                            INT32_C( 1796051299), INT32_C( -602464105), INT32_C( 1096879395), INT32_C( 2101844446),
                            INT32_C( 1483513958), INT32_C(   55530807), INT32_C(-1589480307), INT32_C(  -48228318),
                            INT32_C(  889897511), INT32_C( 1575441246), INT32_C(-1726327647), INT32_C(  657269965)),
      UINT16_C(34646),
      simde_mm512_set_epi32(INT32_C( 1170712187), INT32_C( 1365513540), INT32_C( -159824212), INT32_C(  976500494),
                            INT32_C(   -2253502), INT32_C( 1424815879), INT32_C( 1340211205), INT32_C(  478098159),
                            INT32_C(  545970493), INT32_C(-1738506699), INT32_C(  725751947), INT32_C(  876157308),
                            INT32_C(  729412496), INT32_C( 1316518940), INT32_C(  479437804), INT32_C( 1749631626)),
      simde_mm512_set_epi32(INT32_C( -544439732), INT32_C(  514265282), INT32_C(-1783487008), INT32_C(-1073881913),
                            INT32_C( -917759499), INT32_C(  721599990), INT32_C( 1403076580), INT32_C( -867638009),
                            INT32_C(-2070564498), INT32_C( 1494227565), INT32_C(  156325221), INT32_C( -117354474),
                            INT32_C(-2029550992), INT32_C( 1184377155), INT32_C( -325424585), INT32_C( -563054056)),
      simde_mm512_set_epi32(INT32_C(-1710751740), INT32_C( -360418194), INT32_C( 1198549209), INT32_C( -896335694),
                            INT32_C( 1796051299), INT32_C(  721553648), INT32_C(  268517344), INT32_C(-1073691392),
                            INT32_C( 1483513958), INT32_C( 1091567688), INT32_C(-1589480307), INT32_C( -922730494),
                            INT32_C(  889897511), INT32_C(    8388931), INT32_C( -536328173), INT32_C(  657269965)) },
    { simde_mm512_set_epi32(INT32_C(-1745677982), INT32_C(  235931267), INT32_C( -555741923), INT32_C(  150463911),
                            INT32_C(  354747494), INT32_C( 2006985747), INT32_C( 1517200768), INT32_C( -149674742),
                            INT32_C(-1301892689), INT32_C( 1164273534), INT32_C( -519614566), INT32_C( 1518672842),
                            INT32_C(-1430542782), INT32_C( -567985198), INT32_C( 1793594874), INT32_C( 1766364533)),
      UINT16_C(51458),
      simde_mm512_set_epi32(INT32_C(-1697411653), INT32_C(  213103619), INT32_C( 1166379858), INT32_C(  530625194),
                            INT32_C( 1706895557), INT32_C(-1311465088), INT32_C(  793729023), INT32_C(-1062948513),
                            INT32_C(  -58027177), INT32_C( -215831346), INT32_C(-1081872765), INT32_C(  617218322),
                            INT32_C( 1703489303), INT32_C( 1228468220), INT32_C(  705631662), INT32_C( 1003062693)),
      simde_mm512_set_epi32(INT32_C(-1197760733), INT32_C(-1777870117), INT32_C( 1151957666), INT32_C( -467243461),
                            INT32_C( 1044840108), INT32_C( 1467862627), INT32_C(  340861518), INT32_C( -683495543),
                            INT32_C( -171219649), INT32_C(-1277374003), INT32_C(-2049184175), INT32_C( -804992531),
                            INT32_C( 1254613706), INT32_C( -484210109), INT32_C( -976973176), INT32_C(  768220545)),
      simde_mm512_set_epi32(INT32_C(  537399808), INT32_C(-1845212456), INT32_C( -555741923), INT32_C(  150463911),
                            INT32_C(  440587816), INT32_C( 2006985747), INT32_C( 1517200768), INT32_C(  390205056),
                            INT32_C(-1301892689), INT32_C( 1164273534), INT32_C( -519614566), INT32_C( 1518672842),
                            INT32_C(-1430542782), INT32_C( -567985198), INT32_C( -977239552), INT32_C( 1766364533)) },
    { simde_mm512_set_epi32(INT32_C( 1636500168), INT32_C(  444177967), INT32_C(-1663266514), INT32_C(  191092965),
                            INT32_C(  488118829), INT32_C(-1542228246), INT32_C(-1543977108), INT32_C(-1747326233),
                            INT32_C(  472323781), INT32_C(  181690416), INT32_C(   -8111931), INT32_C(-1512462189),
                            INT32_C(-1412708648), INT32_C( -857864914), INT32_C(-1610668993), INT32_C( 2003858110)),
      UINT16_C( 5589),
      simde_mm512_set_epi32(INT32_C( -283174658), INT32_C(  170838247), INT32_C( -393103783), INT32_C( 2067132417),
                            INT32_C( -418400070), INT32_C(-1518152549), INT32_C( 1910825371), INT32_C(-1243038545),
                            INT32_C(  116520479), INT32_C( -366505216), INT32_C( 1914112492), INT32_C( 1911296968),
                            INT32_C( 2113218059), INT32_C( -692180631), INT32_C(-1020362892), INT32_C( -633211439)),
      simde_mm512_set_epi32(INT32_C( 1184440056), INT32_C(  166652038), INT32_C(-1574005475), INT32_C( 2085250974),
                            INT32_C(-1914483545), INT32_C( -801496013), INT32_C( 1887253581), INT32_C(-1389414117),
                            INT32_C(-1991582465), INT32_C(  878735212), INT32_C(-1594175370), INT32_C( 2077658842),
                            INT32_C(-1116765072), INT32_C( 1279728229), INT32_C( 1087544376), INT32_C( 2038214643)),
      simde_mm512_set_epi32(INT32_C( 1636500168), INT32_C(  444177967), INT32_C(-1663266514), INT32_C(   71960478),
                            INT32_C(  488118829), INT32_C( 1345855520), INT32_C(-1543977108), INT32_C(  134676752),
                            INT32_C(-1995831072), INT32_C(  339766380), INT32_C(   -8111931), INT32_C(  168987666),
                            INT32_C(-1412708648), INT32_C(  138482180), INT32_C(-1610668993), INT32_C(  557582882)) },
    { simde_mm512_set_epi32(INT32_C(  551147024), INT32_C( -687338198), INT32_C(   60918053), INT32_C( 1437206085),
                            INT32_C(  434041201), INT32_C( 1422808900), INT32_C(  419480808), INT32_C(-1939817409),
                            INT32_C(-1683817642), INT32_C( -409888460), INT32_C( 1718430638), INT32_C( 1457046604),
                            INT32_C(  734344028), INT32_C(  175091099), INT32_C(  770584551), INT32_C(  -95488435)),
      UINT16_C(29324),
      simde_mm512_set_epi32(INT32_C( 1939419432), INT32_C( -691029505), INT32_C( -442395497), INT32_C( -427009027),
                            INT32_C(  817522174), INT32_C(    8776211), INT32_C( 1606933870), INT32_C( -913009701),
                            INT32_C(-1219423042), INT32_C(  450853660), INT32_C(  761339041), INT32_C(  889962544),
                            INT32_C(-1736069360), INT32_C(-1763810886), INT32_C(-1763494181), INT32_C( 1322133292)),
      simde_mm512_set_epi32(INT32_C(  114683937), INT32_C( 1592723028), INT32_C(  623286176), INT32_C(-1573004789),
                            INT32_C(  386412089), INT32_C( 1236627295), INT32_C( -815669616), INT32_C( 2140872084),
                            INT32_C(-1844875837), INT32_C(  266739419), INT32_C(-1210833034), INT32_C( 1948981056),
                            INT32_C( -293676893), INT32_C( 1361522457), INT32_C(  417503278), INT32_C(  633831284)),
      simde_mm512_set_epi32(INT32_C(  551147024), INT32_C(  136316416), INT32_C(     394016), INT32_C(    3244034),
                            INT32_C(  434041201), INT32_C( 1422808900), INT32_C(-2145385840), INT32_C(-1939817409),
                            INT32_C(     551233), INT32_C( -409888460), INT32_C( 1718430638), INT32_C( 1457046604),
                            INT32_C( 1719292067), INT32_C( 1092685313), INT32_C(  770584551), INT32_C(  -95488435)) },
    { simde_mm512_set_epi32(INT32_C(-1371022440), INT32_C( 1457704499), INT32_C( -431597639), INT32_C(-1022830061),
                            INT32_C(   36727871), INT32_C(  132345530), INT32_C(-1160653220), INT32_C( 1075044178),
                            INT32_C( 1947162433), INT32_C(  484643153), INT32_C(-1413771472), INT32_C( -151443305),
                            INT32_C(  -82344071), INT32_C(-1396164880), INT32_C(  775295095), INT32_C( 1585972112)),
      UINT16_C(54244),
      simde_mm512_set_epi32(INT32_C( 1350970412), INT32_C(-1442308200), INT32_C( 1774467796), INT32_C( -258916798),
                            INT32_C(-1518028161), INT32_C( 1215654276), INT32_C(-1158758506), INT32_C(-1884048450),
                            INT32_C( -996858784), INT32_C( 1572275854), INT32_C(  -61363356), INT32_C(   71635930),
                            INT32_C(  890553866), INT32_C(-1657029576), INT32_C(  875900884), INT32_C(  232674574)),
      simde_mm512_set_epi32(INT32_C( -559322868), INT32_C(   26562494), INT32_C( 1556236736), INT32_C(  144590511),
                            INT32_C( 2137277580), INT32_C(-1485572616), INT32_C(  664308651), INT32_C(  525825403),
                            INT32_C( 1235000793), INT32_C(  818058128), INT32_C( 1639942075), INT32_C( 1363996226),
                            INT32_C(-1688385601), INT32_C(  521315224), INT32_C( -495140458), INT32_C( 2110266874)),
      simde_mm512_set_epi32(INT32_C(-1909899008), INT32_C(   26558502), INT32_C( -431597639), INT32_C(  135151789),
                            INT32_C(   36727871), INT32_C(  132345530), INT32_C(   84934697), INT32_C(  272909377),
                            INT32_C(  151558553), INT32_C(  541102352), INT32_C(   27788443), INT32_C( -151443305),
                            INT32_C(  -82344071), INT32_C(   33555328), INT32_C(  775295095), INT32_C( 1585972112)) },
    { simde_mm512_set_epi32(INT32_C(-1445633201), INT32_C(-1516803416), INT32_C( 2047415330), INT32_C(  756009385),
                            INT32_C(  795635255), INT32_C(  735619934), INT32_C(-1886661005), INT32_C( 1006199392),
                            INT32_C( -253641367), INT32_C(  505896362), INT32_C(  377279653), INT32_C(  782384760),
                            INT32_C(-2053863520), INT32_C(  173648830), INT32_C(-1212193602), INT32_C(  646275887)),
      UINT16_C( 3833),
      simde_mm512_set_epi32(INT32_C(-1717413045), INT32_C(   37772527), INT32_C(  997132272), INT32_C( 1212574322),
                            INT32_C(  -50264086), INT32_C( 1583086284), INT32_C(-1387426254), INT32_C(  542967980),
                            INT32_C(  321849276), INT32_C( 2124033808), INT32_C( 1752461294), INT32_C(-1726583281),
                            INT32_C( -438403938), INT32_C(-1226147069), INT32_C( 1033013441), INT32_C(-1845989576)),
      simde_mm512_set_epi32(INT32_C( -928885408), INT32_C( 1847851352), INT32_C(-1563646145), INT32_C(-1610113698),
                            INT32_C( -632488883), INT32_C( -579742459), INT32_C(  505595497), INT32_C( 1976491564),
                            INT32_C( 1357643236), INT32_C( -210153251), INT32_C(-1628647323), INT32_C(-1816082231),
                            INT32_C( 1251469965), INT32_C(-2146681250), INT32_C( 1797992596), INT32_C(-1790080236)),
      simde_mm512_set_epi32(INT32_C(-1445633201), INT32_C(-1516803416), INT32_C( 2047415330), INT32_C(  756009385),
                            INT32_C(   38598661), INT32_C(-2128607999), INT32_C(  304234569), INT32_C( 1006199392),
                            INT32_C( 1086388288), INT32_C(-2124328755), INT32_C(-1769435135), INT32_C(   46170304),
                            INT32_C(  167870977), INT32_C(  173648830), INT32_C(-1212193602), INT32_C(   67469316)) },
    { simde_mm512_set_epi32(INT32_C( -995130208), INT32_C(-1764606453), INT32_C( -537517512), INT32_C( 1451556674),
                            INT32_C(-2097109774), INT32_C(  404626699), INT32_C( 1345130097), INT32_C( 1798816735),
                            INT32_C(  621374452), INT32_C(  359481722), INT32_C( -121162344), INT32_C(-1051201334),
                            INT32_C( 1869160778), INT32_C( -582139350), INT32_C(  314118274), INT32_C(-1141503487)),
      UINT16_C(47272),
      simde_mm512_set_epi32(INT32_C( 1226690931), INT32_C(  775179034), INT32_C(-2065746086), INT32_C(  399353184),
                            INT32_C(  328691430), INT32_C(-1594470117), INT32_C(-1552077762), INT32_C(   88628502),
                            INT32_C(  772052572), INT32_C( 1376748436), INT32_C(-1273427356), INT32_C(  738624056),
                            INT32_C(  647794952), INT32_C(  804576006), INT32_C( 1968895876), INT32_C(  505069248)),
      simde_mm512_set_epi32(INT32_C(-1066067632), INT32_C( -638799863), INT32_C(-1513539525), INT32_C(-1037105416),
                            INT32_C(  605705140), INT32_C(-2097483540), INT32_C(   62474077), INT32_C( 2107466991),
                            INT32_C( 1856531921), INT32_C(  781853938), INT32_C( 1472528720), INT32_C( -275942665),
                            INT32_C(  990137373), INT32_C( 1633665081), INT32_C(  480667256), INT32_C( -831347442)),
      simde_mm512_set_epi32(INT32_C(-2141190144), INT32_C(-1764606453), INT32_C(  553650209), INT32_C(-1071512936),
                            INT32_C(  604508432), INT32_C(  404626699), INT32_C( 1345130097), INT32_C( 1798816735),
                            INT32_C( 1084778881), INT32_C(  359481722), INT32_C( 1136918800), INT32_C(-1051201334),
                            INT32_C(  419449877), INT32_C( -582139350), INT32_C(  314118274), INT32_C(-1141503487)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castps_si512(simde_mm512_mask_andnot_ps(simde_mm512_castsi512_ps(test_vec[i].src), test_vec[i].k, simde_mm512_castsi512_ps(test_vec[i].a), simde_mm512_castsi512_ps(test_vec[i].b)));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_andnot_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
  {   UINT16_C(41898),
      simde_mm512_set_epi32(INT32_C(-1595502197), INT32_C(-1527248547), INT32_C( 1075363080), INT32_C(-1963744626),
                            INT32_C( -841874568), INT32_C( 1348974030), INT32_C(  932258327), INT32_C(-1638556215),
                            INT32_C(  -69119366), INT32_C(-1406064931), INT32_C( -198162021), INT32_C( -674249080),
                            INT32_C( -972410055), INT32_C(-1112978451), INT32_C( -141156932), INT32_C(-1950860528)),
      simde_mm512_set_epi32(INT32_C( -211589013), INT32_C(  652089670), INT32_C( 1378847800), INT32_C(  904957231),
                            INT32_C(-1966320781), INT32_C(-1079187730), INT32_C( 1733727399), INT32_C(-1452272768),
                            INT32_C(-1073785858), INT32_C(  -63492051), INT32_C( 1043637479), INT32_C(-1013855000),
                            INT32_C(  942467481), INT32_C(-1080366077), INT32_C(  642537593), INT32_C(  818463971)),
      simde_mm512_set_epi32(INT32_C( 1392601184), INT32_C(          0), INT32_C(  304545840), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1078367392), INT32_C(  555745792),
                            INT32_C(   69075332), INT32_C(          0), INT32_C(  168076388), INT32_C(          0),
                            INT32_C(  941934720), INT32_C(          0), INT32_C(    4735041), INT32_C(          0)) },
  {   UINT16_C(54776),
      simde_mm512_set_epi32(INT32_C(-1423327830), INT32_C(  463002536), INT32_C( 1170361638), INT32_C( 1439896493),
                            INT32_C( -881601279), INT32_C(  439454207), INT32_C(  642703998), INT32_C( 1761947183),
                            INT32_C( 1210383154), INT32_C( -138151523), INT32_C(  263888472), INT32_C( 2142193967),
                            INT32_C( -741822666), INT32_C(  755920794), INT32_C(-1972313252), INT32_C(-1912811499)),
      simde_mm512_set_epi32(INT32_C(-1115388021), INT32_C(  769964125), INT32_C(  418227269), INT32_C(-1388492980),
                            INT32_C(  480660510), INT32_C( 1802844866), INT32_C( -429993967), INT32_C(  538553865),
                            INT32_C( 2013392956), INT32_C(  197176151), INT32_C( 2006567868), INT32_C( 1705115765),
                            INT32_C( 1202543157), INT32_C(-1263572444), INT32_C( 1425580745), INT32_C( 1097283836)),
      simde_mm512_set_epi32(INT32_C(  344195585), INT32_C(  610541653), INT32_C(          0), INT32_C(-1473493952),
                            INT32_C(          0), INT32_C( 1631859200), INT32_C(          0), INT32_C(    1605632),
                            INT32_C(  805371916), INT32_C(  134218306), INT32_C( 1879130532), INT32_C(         80),
                            INT32_C(   69554177), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
  {   UINT16_C(25126),
      simde_mm512_set_epi32(INT32_C(  633431361), INT32_C( 1663592688), INT32_C( 1399097521), INT32_C( -248917369),
                            INT32_C(-1131808104), INT32_C(  737246109), INT32_C( -548380687), INT32_C(-1607587862),
                            INT32_C(  223712677), INT32_C( -234850179), INT32_C( 1225779292), INT32_C(-1983080521),
                            INT32_C( 1083031306), INT32_C(  479812120), INT32_C( 1659393180), INT32_C( 1062780085)),
      simde_mm512_set_epi32(INT32_C(  112954855), INT32_C( 1790377254), INT32_C( 1893295646), INT32_C( -674583179),
                            INT32_C(   15401677), INT32_C( -641918434), INT32_C( -635981818), INT32_C( -342921360),
                            INT32_C( -977229164), INT32_C( -339160274), INT32_C(-1866080556), INT32_C(-1369988401),
                            INT32_C( 1985260264), INT32_C( 1810318993), INT32_C( -324233777), INT32_C(-1229418212)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  144086278), INT32_C(  546924046), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(     499718), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1866459520), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1667630209), INT32_C(-1945861821), INT32_C(          0)) },
  {   UINT16_C(40095),
      simde_mm512_set_epi32(INT32_C( -925173403), INT32_C(-1800856604), INT32_C(-1569556909), INT32_C(-2075468293),
                            INT32_C(-1622295859), INT32_C(  800838040), INT32_C(-1261125664), INT32_C(  225560714),
                            INT32_C( -249168174), INT32_C( -785821894), INT32_C(-1322298905), INT32_C( 1919393940),
                            INT32_C(  722048893), INT32_C(  667050909), INT32_C( -741637209), INT32_C(-1063733140)),
      simde_mm512_set_epi32(INT32_C(  283702321), INT32_C( 1760938946), INT32_C( 1862161708), INT32_C(  218779454),
                            INT32_C( 1870003832), INT32_C( -776472743), INT32_C(  235320856), INT32_C(-1927493256),
                            INT32_C( 2120699773), INT32_C( 1743164034), INT32_C(   92504126), INT32_C( -822461737),
                            INT32_C(   80989491), INT32_C( -825823244), INT32_C(   23436927), INT32_C(-1677273698)),
      simde_mm512_set_epi32(INT32_C(  270533648), INT32_C(          0), INT32_C(          0), INT32_C(  150995460),
                            INT32_C( 1613775920), INT32_C( -805034431), INT32_C(          0), INT32_C(          0),
                            INT32_C(  239206701), INT32_C(          0), INT32_C(          0), INT32_C(-1936188861),
                            INT32_C(   80889858), INT32_C( -939226016), INT32_C(    2366552), INT32_C(  470173074)) },
  {   UINT16_C(25708),
      simde_mm512_set_epi32(INT32_C( -419506034), INT32_C(-1634084803), INT32_C(-1791352038), INT32_C( 1397909248),
                            INT32_C( -128853850), INT32_C(-1917410935), INT32_C( 1700830870), INT32_C( 1339604709),
                            INT32_C(-1798365850), INT32_C(  -59209020), INT32_C(  731125713), INT32_C(  630650100),
                            INT32_C(-1338681832), INT32_C(   44002851), INT32_C( -812125291), INT32_C( 1028997312)),
      simde_mm512_set_epi32(INT32_C( -213890367), INT32_C( 2021869397), INT32_C( 1653460709), INT32_C(-1583015005),
                            INT32_C(-2111228672), INT32_C(  278487831), INT32_C(-1988085048), INT32_C(-1603254022),
                            INT32_C( 1778423041), INT32_C( 1070290908), INT32_C( 1862134929), INT32_C( 1387107310),
                            INT32_C(-1741926346), INT32_C(  476437588), INT32_C(  -64629687), INT32_C(  821283219)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1610745664), INT32_C( 1652935909), INT32_C(          0),
                            INT32_C(          0), INT32_C(  269042198), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(   58938648), INT32_C( 1147791360), INT32_C(          0),
                            INT32_C(  134742054), INT32_C(  476090452), INT32_C(          0), INT32_C(          0)) },
  {   UINT16_C(26454),
      simde_mm512_set_epi32(INT32_C(-1766483567), INT32_C(  -97069133), INT32_C( -984184350), INT32_C( -103594411),
                            INT32_C( 1542851117), INT32_C(  476137043), INT32_C( -197399951), INT32_C(-1770261666),
                            INT32_C(  -47794230), INT32_C( -491438206), INT32_C( -344435807), INT32_C(  255371302),
                            INT32_C( -725452804), INT32_C(  159027945), INT32_C(-1412516432), INT32_C( -472096495)),
      simde_mm512_set_epi32(INT32_C(  939183992), INT32_C(   45898803), INT32_C( -707307552), INT32_C( -411975944),
                            INT32_C(  630779143), INT32_C( 1898376282), INT32_C( 2124829976), INT32_C( -114883081),
                            INT32_C( 2093795280), INT32_C(-1982561427), INT32_C(  598306044), INT32_C( 1635474930),
                            INT32_C(-1398853653), INT32_C( 1652658661), INT32_C(-1858170883), INT32_C(  995216280)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(    8914944), INT32_C(  276911616), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1627826184), INT32_C(  176428296), INT32_C( 1761871009),
                            INT32_C(          0), INT32_C(  155222125), INT32_C(          0), INT32_C( 1615025616),
                            INT32_C(          0), INT32_C( 1652621572), INT32_C(  271583821), INT32_C(          0)) },
  {   UINT16_C(31670),
      simde_mm512_set_epi32(INT32_C(-1612308895), INT32_C( -722700317), INT32_C( 1003499766), INT32_C(  814072246),
                            INT32_C( 2008726943), INT32_C( 1223905210), INT32_C( -618135276), INT32_C(-2049729375),
                            INT32_C(  595839117), INT32_C( -226508565), INT32_C( 1598449683), INT32_C( -514630984),
                            INT32_C(  658541354), INT32_C(  567151600), INT32_C(  -71044409), INT32_C(-1688131700)),
      simde_mm512_set_epi32(INT32_C( 1317588071), INT32_C(-1153324271), INT32_C( 2046542506), INT32_C(  623240678),
                            INT32_C(  -39480028), INT32_C(  -33815034), INT32_C( 2056788636), INT32_C( 2095887515),
                            INT32_C( -281654456), INT32_C(-1621887341), INT32_C( 1362159003), INT32_C( 1103094461),
                            INT32_C( 1716020502), INT32_C(  102069928), INT32_C(  474901863), INT32_C(  367619581)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  721520656), INT32_C( 1076609544), INT32_C(   85992512),
                            INT32_C(-2012938208), INT32_C(          0), INT32_C(  546314888), INT32_C( 2016157722),
                            INT32_C( -869006528), INT32_C(          0), INT32_C(    3179912), INT32_C(   11313157),
                            INT32_C(          0), INT32_C(  101807112), INT32_C(   67898656), INT32_C(          0)) },
  {   UINT16_C(49857),
      simde_mm512_set_epi32(INT32_C(-2067220018), INT32_C( 1805947847), INT32_C( 2110487322), INT32_C( 1074104919),
                            INT32_C(-1112398120), INT32_C(  225474260), INT32_C( -545045472), INT32_C( -824857753),
                            INT32_C( -338758362), INT32_C(-1789466141), INT32_C( 1713747474), INT32_C(  808725130),
                            INT32_C( 1298412949), INT32_C(  260904797), INT32_C(  457183382), INT32_C( 2009286767)),
      simde_mm512_set_epi32(INT32_C(-2042099265), INT32_C( 1225391956), INT32_C( -841393362), INT32_C( -744679138),
                            INT32_C(  -30361081), INT32_C( 1490708305), INT32_C( 1603942577), INT32_C(-1226711411),
                            INT32_C( -720257963), INT32_C(  876066124), INT32_C( 1546499669), INT32_C( 1636147146),
                            INT32_C(    3608382), INT32_C( -404260643), INT32_C( 1874947312), INT32_C(-2040485747)),
      simde_mm512_set_epi32(INT32_C(   33554481), INT32_C(     617488), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(    1587345), INT32_C(          0),
                            INT32_C(  336660561), INT32_C(  539038732), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-2145345408)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castps_si512(simde_mm512_maskz_andnot_ps(test_vec[i].k, simde_mm512_castsi512_ps(test_vec[i].a), simde_mm512_castsi512_ps(test_vec[i].b)));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_andnot_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
     { simde_mm512_set_epi64(INT64_C( -343739447634695407), INT64_C( 6094193684923690615),
                            INT64_C(-7040634603669948000), INT64_C( 8872386007247991164),
                            INT64_C(-8252638392294099885), INT64_C( 6601029892750146432),
                            INT64_C( 7279352193089347864), INT64_C( 8662714795122682384)),
      UINT8_C( 55),
      simde_mm512_set_epi64(INT64_C(  599279934641474098), INT64_C( 7845412443385721442),
                            INT64_C(-2777121475968104316), INT64_C( 7314283605033033979),
                            INT64_C(-8886012248836695508), INT64_C( 3313585428802692877),
                            INT64_C(-1598467827595787694), INT64_C(-5223130400950906727)),
      simde_mm512_set_epi64(INT64_C( 4132377007718714638), INT64_C( 6722749807664954665),
                            INT64_C(-6834862606673078980), INT64_C(-8159527519597393212),
                            INT64_C( 1169770534052573165), INT64_C(-8496887971116687127),
                            INT64_C( 4795256091623648748), INT64_C( -534912108587925882)),
      simde_mm512_set_epi64(INT64_C( -343739447634695407), INT64_C( 6094193684923690615),
                            INT64_C( 2305860618582136120), INT64_C(-8484217854339937788),
                            INT64_C(-8252638392294099885), INT64_C(-9079040208459267872),
                            INT64_C(  147532470349213100), INT64_C( 5192659463408496134)) },
    { simde_mm512_set_epi64(INT64_C( 1137601381159569274), INT64_C( 3083515373590209262),
                            INT64_C( 7172644931946125494), INT64_C( 7709434742472783251),
                            INT64_C(-5570954806909339658), INT64_C( -271406020759376737),
                            INT64_C( 4799674771715911578), INT64_C(-1218830816677094379)),
      UINT8_C( 50),
      simde_mm512_set_epi64(INT64_C(-2731162171219972563), INT64_C( 4361435470291369786),
                            INT64_C( 4372980053959095777), INT64_C(-4964365409406827474),
                            INT64_C(-4887932848327267276), INT64_C( 5394909549222414797),
                            INT64_C( 8601793944421926823), INT64_C( 1320541430862898557)),
      simde_mm512_set_epi64(INT64_C( 3987127999885683210), INT64_C(  232842063033182789),
                            INT64_C(-8565159867474411189), INT64_C( 6112914526494565862),
                            INT64_C( 3462295888398647957), INT64_C( 2362909626677485241),
                            INT64_C( 1401365959932181466), INT64_C( 2959935140000245037)),
      simde_mm512_set_epi64(INT64_C( 1137601381159569274), INT64_C( 3083515373590209262),
                            INT64_C(-9151314120547500022), INT64_C( 4955199880194171328),
                            INT64_C(-5570954806909339658), INT64_C( -271406020759376737),
                            INT64_C(    9008205654194264), INT64_C(-1218830816677094379)) },
    { simde_mm512_set_epi64(INT64_C( 4893068556614144973), INT64_C( 8066183844976877919),
                            INT64_C( 8546857359160133238), INT64_C(-8267045803572214233),
                            INT64_C( 8915887943252268838), INT64_C(-4953676046754636494),
                            INT64_C( 1510704893512358974), INT64_C( 9024635443342747538)),
      UINT8_C(216),
      simde_mm512_set_epi64(INT64_C(-8634103598278842542), INT64_C(-6155398791521040805),
                            INT64_C( 7775580441978642644), INT64_C(-5899929856226471257),
                            INT64_C( 7028189811487947825), INT64_C(-6189665615261290781),
                            INT64_C(  907536080618458470), INT64_C( 3906704638875451620)),
      simde_mm512_set_epi64(INT64_C(-4094490793791238990), INT64_C(-2091977621380611033),
                            INT64_C( 2043918654743067438), INT64_C(-4515408626818342672),
                            INT64_C( 1196379185714011362), INT64_C( 1607300510948935937),
                            INT64_C( 1394814499359692419), INT64_C(-5198396047694847294)),
      simde_mm512_set_epi64(INT64_C( 5116214864772401312), INT64_C( 4639917106950488100),
                            INT64_C( 8546857359160133238), INT64_C( 4701761038926749776),
                            INT64_C( 1158058982756417730), INT64_C(-4953676046754636494),
                            INT64_C( 1510704893512358974), INT64_C( 9024635443342747538)) },
    { simde_mm512_set_epi64(INT64_C( -233515152413640809), INT64_C(-7711023580854835359),
                            INT64_C(  685057037117132470), INT64_C(-1053400672876430250),
                            INT64_C(-6008870355673260365), INT64_C( 6732010747677860150),
                            INT64_C( 7912723632945414242), INT64_C( 6629652157771519554)),
      UINT8_C(  7),
      simde_mm512_set_epi64(INT64_C(  418428539766329360), INT64_C( 1870466273027415797),
                            INT64_C( 7044646027925455043), INT64_C(-7541966937157619960),
                            INT64_C(-4455685474515493219), INT64_C(-3587901153898980536),
                            INT64_C( 5978767859636931605), INT64_C( 1520054098233920669)),
      simde_mm512_set_epi64(INT64_C( 3839280895408034825), INT64_C(-8206971788365754506),
                            INT64_C(-4439851259277562681), INT64_C(-6789849238744039634),
                            INT64_C(-1659448540825770878), INT64_C( 2745935889893417490),
                            INT64_C( 3715019098340555278), INT64_C(-7036562755259908130)),
      simde_mm512_set_epi64(INT64_C( -233515152413640809), INT64_C(-7711023580854835359),
                            INT64_C(  685057037117132470), INT64_C(-1053400672876430250),
                            INT64_C(-6008870355673260365), INT64_C( 2308798513734279186),
                            INT64_C( 2379631298345005578), INT64_C(-8484488882121788606)) },
    { simde_mm512_set_epi64(INT64_C(-2379770324367148032), INT64_C(  269951545548960285),
                            INT64_C(-5915450755405613469), INT64_C( 4377769456724035257),
                            INT64_C( 4963028952577306253), INT64_C( 5031417887689077714),
                            INT64_C( 5062535597864084892), INT64_C(-8442033713738522560)),
      UINT8_C(129),
      simde_mm512_set_epi64(INT64_C(-6217210315706132893), INT64_C(-5326659911006667991),
                            INT64_C( 1028086835571864351), INT64_C(-9190513903150593462),
                            INT64_C(-5132407930629667991), INT64_C( 3081908066365846241),
                            INT64_C( 1991874275422300444), INT64_C(-8267800556778760378)),
      simde_mm512_set_epi64(INT64_C(-7195920316169423191), INT64_C( 8855103613986981069),
                            INT64_C(-1079557804828513091), INT64_C(-7716984285220335090),
                            INT64_C(  760039564915644558), INT64_C( 5629267284662877438),
                            INT64_C(-8887844833591355405), INT64_C( 3227154889713027186)),
      simde_mm512_set_epi64(INT64_C( 1441983734462308488), INT64_C(  269951545548960285),
                            INT64_C(-5915450755405613469), INT64_C( 4377769456724035257),
                            INT64_C( 4963028952577306253), INT64_C( 5031417887689077714),
                            INT64_C( 5062535597864084892), INT64_C( 2344440558065420336)) },
    { simde_mm512_set_epi64(INT64_C(-1632349344831082760), INT64_C(-7746252227037734078),
                            INT64_C( 8307071850644138234), INT64_C(-8586546786041619015),
                            INT64_C(  404139822791089559), INT64_C(-1877631053848650154),
                            INT64_C( 7455727023947545561), INT64_C( 9065509561364139853)),
      UINT8_C(251),
      simde_mm512_set_epi64(INT64_C( 6876828378130175291), INT64_C( 4443252594681514716),
                            INT64_C(-6385840203869031352), INT64_C( 6938523062457490065),
                            INT64_C( -791901096126868688), INT64_C( 5787489911096576116),
                            INT64_C(-7854643813663956328), INT64_C( 5967336075130617342)),
      simde_mm512_set_epi64(INT64_C( 4146719804671055125), INT64_C( 2252037785239205430),
                            INT64_C( 8454374735321895014), INT64_C(-1381892347656312574),
                            INT64_C(  706165223560180728), INT64_C( -219143018686364756),
                            INT64_C(-1570739878098539061), INT64_C(-1561542974628641964)),
      simde_mm512_set_epi64(INT64_C( 2341899294765252612), INT64_C(  162200290615931938),
                            INT64_C( 5769965461718695974), INT64_C(-8318139676533907198),
                            INT64_C(  633958070103335112), INT64_C(-1877631053848650154),
                            INT64_C( 7494284887317302595), INT64_C(-6339871525209882112)) },
    { simde_mm512_set_epi64(INT64_C( 9026638934924851598), INT64_C(  230236376028734533),
                            INT64_C( 7791847925691209473), INT64_C( 5636683834883992106),
                            INT64_C( 4666417032316259140), INT64_C(-9020764089960395704),
                            INT64_C( 8213766780006614493), INT64_C(-6694788910086219877)),
      UINT8_C( 70),
      simde_mm512_set_epi64(INT64_C(-6498066308492480472), INT64_C( 5728364479291594350),
                            INT64_C(-5884149762497402782), INT64_C( 6387650260207408060),
                            INT64_C(-5128486331429717841), INT64_C( -868619985199698421),
                            INT64_C(-4214853307896141180), INT64_C( -465765039913276151)),
      simde_mm512_set_epi64(INT64_C(-5046884246860802318), INT64_C( 1004972136752522438),
                            INT64_C(-2378507232856704687), INT64_C( 5436650347587017589),
                            INT64_C(-2667790265994842517), INT64_C(-2085203105823883971),
                            INT64_C(-5490659216814537620), INT64_C(-8036188446954416194)),
      simde_mm512_set_epi64(INT64_C( 9026638934924851598), INT64_C(   36100064221372544),
                            INT64_C( 7791847925691209473), INT64_C( 5636683834883992106),
                            INT64_C( 4666417032316259140), INT64_C(    3892555578216756),
                            INT64_C( 3624274549258028136), INT64_C(-6694788910086219877)) },
    { simde_mm512_set_epi64(INT64_C(-5230007765170990668), INT64_C(  846507549899810342),
                            INT64_C(-7111962349683310649), INT64_C( -772191960312616388),
                            INT64_C( 3123285095915363891), INT64_C( 1623466873559833442),
                            INT64_C( -366019171342533610), INT64_C(-2494634274663155684)),
      UINT8_C( 35),
      simde_mm512_set_epi64(INT64_C( -975714944549474590), INT64_C( 1049564164032844619),
                            INT64_C( 7303689756219555946), INT64_C(-6372981973137131801),
                            INT64_C(-5489514128660043293), INT64_C(-7367882453491102610),
                            INT64_C( 6699088752588717529), INT64_C( 1411143637466671223)),
      simde_mm512_set_epi64(INT64_C(-2226860933844685600), INT64_C( 1920850149099678208),
                            INT64_C( 1690361552489070319), INT64_C( 6660992074283035646),
                            INT64_C(-5836455416301421815), INT64_C(-2339252903384749197),
                            INT64_C(-3541767763730411989), INT64_C( 1379523068058767230)),
      simde_mm512_set_epi64(INT64_C(-5230007765170990668), INT64_C(  846507549899810342),
                            INT64_C( 1307192606745607813), INT64_C( -772191960312616388),
                            INT64_C( 3123285095915363891), INT64_C( 1623466873559833442),
                            INT64_C(-9076991572345486814), INT64_C(    9020679430670088)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castpd_si512(simde_mm512_mask_andnot_pd(simde_mm512_castsi512_pd(test_vec[i].src), test_vec[i].k, simde_mm512_castsi512_pd(test_vec[i].a), simde_mm512_castsi512_pd(test_vec[i].b)));
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_andnot_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
  {   UINT8_C(227),
      simde_mm512_set_epi64(INT64_C(-4590720219282553470), INT64_C( 7052994564826635717),
                            INT64_C(  102182550423351600), INT64_C( 6550609573293042333),
                            INT64_C(-6537325874213497913), INT64_C( 8955563540957921573),
                            INT64_C( 8228815951810735558), INT64_C(-3823364876013971085)),
      simde_mm512_set_epi64(INT64_C( -740720849127296556), INT64_C( -933890699409471481),
                            INT64_C( 5755588500836856312), INT64_C(-7609758858126984395),
                            INT64_C( 5441557991346977587), INT64_C( -960797962792509213),
                            INT64_C(  199203171802884405), INT64_C( 1812346297232380541)),
      simde_mm512_set_epi64(INT64_C( 3868594310811889748), INT64_C(-7923482887668088830),
                            INT64_C( 5662415626724180168), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(   54349100887310385), INT64_C( 1226687842802237964)) },
  {   UINT8_C(150),
      simde_mm512_set_epi64(INT64_C( 8029427937579490996), INT64_C(-1016228199940301895),
                            INT64_C( 3581869483076202853), INT64_C( 4960784598491720813),
                            INT64_C(-7670184712449022296), INT64_C( 1368687340866524346),
                            INT64_C(   36158962521961508), INT64_C( 1367446093605161437)),
      simde_mm512_set_epi64(INT64_C(  210141022168102607), INT64_C(-5660044126052691316),
                            INT64_C( 8952190750537587177), INT64_C(-7520755716476597588),
                            INT64_C( 5025036600597137846), INT64_C( 1371349703128320142),
                            INT64_C( 1157825117202956749), INT64_C( 3947754344252009580)),
      simde_mm512_set_epi64(INT64_C(   36187148471246923), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-7845058891591449984),
                            INT64_C(                   0), INT64_C(   72059827504875524),
                            INT64_C( 1157717081520079305), INT64_C(                   0)) },
  {   UINT8_C(206),
      simde_mm512_set_epi64(INT64_C(-5447319738796629324), INT64_C( 7573553786407309883),
                            INT64_C( 3210166478679154113), INT64_C( -632818268169935629),
                            INT64_C( 2091039522714659767), INT64_C(-7890721085940980150),
                            INT64_C(-4051485337429119412), INT64_C(-3044005681324007212)),
      simde_mm512_set_epi64(INT64_C(-3107571465629414339), INT64_C(-5609659848016607327),
                            INT64_C( 3170884903864138535), INT64_C( 3780264979688453657),
                            INT64_C(-3200960942660399317), INT64_C( 5382084213528122877),
                            INT64_C(-4409193503472949179), INT64_C( 4723837911396640821)),
      simde_mm512_set_epi64(INT64_C( 4654611160413260809), INT64_C(-7916109799461190272),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-4426155929590676472), INT64_C( 5224458146534150581),
                            INT64_C(    2608396285542401), INT64_C(                   0)) },
  {   UINT8_C(125),
      simde_mm512_set_epi64(INT64_C( 4207278183660861960), INT64_C(-8995945069443043606),
                            INT64_C( 8554253801191868756), INT64_C( 3354059043086044373),
                            INT64_C( 1657475957423553689), INT64_C(-2556137084454595182),
                            INT64_C( 2422681642730518465), INT64_C(-8655840866694392843)),
      simde_mm512_set_epi64(INT64_C(-6233706215614972452), INT64_C( 2778576059313358974),
                            INT64_C(  521154595483651590), INT64_C(-2197561166428241391),
                            INT64_C(  751433836641726755), INT64_C( 5984411989878292578),
                            INT64_C(-2128282437357703049), INT64_C( 6129378286910417126)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C( 2632358518757523476),
                            INT64_C(   74594534185240066), INT64_C(-4539433801636773376),
                            INT64_C(  607176734235951394), INT64_C(  218459912932966496),
                            INT64_C(                   0), INT64_C( 5769015465569462274)) },
  {   UINT8_C( 71),
      simde_mm512_set_epi64(INT64_C(-8436437744293223076), INT64_C( -780741249760151942),
                            INT64_C( 4822350614887775462), INT64_C( 2188408541520193917),
                            INT64_C(-3082935350304813722), INT64_C(-5875221946234265673),
                            INT64_C(-5758090656392293952), INT64_C(-3302974504787286903)),
      simde_mm512_set_epi64(INT64_C(-7235195547697304884), INT64_C(-2099342694411362386),
                            INT64_C( 6587794971423114743), INT64_C(-8750716550526717441),
                            INT64_C(-6164466580259336301), INT64_C(-5605431759460432480),
                            INT64_C( 8610981953023941155), INT64_C(-5677351707943910012)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(  204210100791970180),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 1153063355977236480),
                            INT64_C( 5152215214393002531), INT64_C( 2383675803176042756)) },
  {   UINT8_C( 16),
      simde_mm512_set_epi64(INT64_C(-7454619922298182462), INT64_C(-4477515570225004692),
                            INT64_C( 3259262052820328758), INT64_C(-2323942451066306663),
                            INT64_C(-7533087570752357418), INT64_C(-2748624972946479401),
                            INT64_C(-7594508336042449203), INT64_C(-2829162199669149138)),
      simde_mm512_set_epi64(INT64_C(  231920182013128330), INT64_C( 2342360813276731434),
                            INT64_C(-3887471131024015317), INT64_C(-6063668553337722025),
                            INT64_C( 6394528685493045899), INT64_C( 7433558736916574563),
                            INT64_C(-8597186079760918784), INT64_C( 9218943275377121788)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 2323862976450265158),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
  {   UINT8_C(  0),
      simde_mm512_set_epi64(INT64_C(-1874339372436527846), INT64_C(-4874669033093832828),
                            INT64_C(-5258762659707925604), INT64_C( 1933045326528420333),
                            INT64_C( 8704229925049171123), INT64_C(-4249956245353677661),
                            INT64_C( 3155017878537816163), INT64_C( 8377752223970655488)),
      simde_mm512_set_epi64(INT64_C( 6639157720065498333), INT64_C( 7954402008564552716),
                            INT64_C(  220412799958481097), INT64_C( 3341210828844349470),
                            INT64_C(  930495958757986079), INT64_C(-5593607526362331219),
                            INT64_C( 1220298896193992740), INT64_C( 1285034736351616528)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
  {   UINT8_C( 29),
      simde_mm512_set_epi64(INT64_C( 6066305475956667844), INT64_C(-4992917222673652861),
                            INT64_C(-8395584014417236584), INT64_C( -142719058224734896),
                            INT64_C(  509377192188320240), INT64_C( 4417811606371822828),
                            INT64_C( 5101966917722654224), INT64_C(-9124380135803090931)),
      simde_mm512_set_epi64(INT64_C( 7887221249293377488), INT64_C( -182605916723991232),
                            INT64_C(  366071292133853300), INT64_C(-7235772882062384424),
                            INT64_C( 2002854046423029286), INT64_C(-3793561946903283248),
                            INT64_C(-8278200760223787155), INT64_C(-6807146722179486859)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(  112882606806164104),
                            INT64_C( 1786257950099998214), INT64_C(-4462918246344945392),
                            INT64_C(                   0), INT64_C( 2341880616049730416)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castpd_si512(simde_mm512_maskz_andnot_pd(test_vec[i].k, simde_mm512_castsi512_pd(test_vec[i].a), simde_mm512_castsi512_pd(test_vec[i].b)));
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_broadcast_f32x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -751.49), SIMDE_FLOAT32_C(  -275.35), SIMDE_FLOAT32_C(   260.73), SIMDE_FLOAT32_C(    40.02) },
      { SIMDE_FLOAT32_C(  -751.49), SIMDE_FLOAT32_C(  -275.35), SIMDE_FLOAT32_C(  -751.49), SIMDE_FLOAT32_C(  -275.35),
        SIMDE_FLOAT32_C(  -751.49), SIMDE_FLOAT32_C(  -275.35), SIMDE_FLOAT32_C(  -751.49), SIMDE_FLOAT32_C(  -275.35) } },
    { { SIMDE_FLOAT32_C(   629.63), SIMDE_FLOAT32_C(   163.39), SIMDE_FLOAT32_C(   167.23), SIMDE_FLOAT32_C(   652.38) },
      { SIMDE_FLOAT32_C(   629.63), SIMDE_FLOAT32_C(   163.39), SIMDE_FLOAT32_C(   629.63), SIMDE_FLOAT32_C(   163.39),
        SIMDE_FLOAT32_C(   629.63), SIMDE_FLOAT32_C(   163.39), SIMDE_FLOAT32_C(   629.63), SIMDE_FLOAT32_C(   163.39) } },
    { { SIMDE_FLOAT32_C(   574.73), SIMDE_FLOAT32_C(  -529.99), SIMDE_FLOAT32_C(   389.79), SIMDE_FLOAT32_C(  -875.04) },
      { SIMDE_FLOAT32_C(   574.73), SIMDE_FLOAT32_C(  -529.99), SIMDE_FLOAT32_C(   574.73), SIMDE_FLOAT32_C(  -529.99),
        SIMDE_FLOAT32_C(   574.73), SIMDE_FLOAT32_C(  -529.99), SIMDE_FLOAT32_C(   574.73), SIMDE_FLOAT32_C(  -529.99) } },
    { { SIMDE_FLOAT32_C(  -790.15), SIMDE_FLOAT32_C(     7.90), SIMDE_FLOAT32_C(   834.33), SIMDE_FLOAT32_C(   549.92) },
      { SIMDE_FLOAT32_C(  -790.15), SIMDE_FLOAT32_C(     7.90), SIMDE_FLOAT32_C(  -790.15), SIMDE_FLOAT32_C(     7.90),
        SIMDE_FLOAT32_C(  -790.15), SIMDE_FLOAT32_C(     7.90), SIMDE_FLOAT32_C(  -790.15), SIMDE_FLOAT32_C(     7.90) } },
    { { SIMDE_FLOAT32_C(   494.62), SIMDE_FLOAT32_C(  -875.96), SIMDE_FLOAT32_C(  -221.96), SIMDE_FLOAT32_C(  -519.70) },
      { SIMDE_FLOAT32_C(   494.62), SIMDE_FLOAT32_C(  -875.96), SIMDE_FLOAT32_C(   494.62), SIMDE_FLOAT32_C(  -875.96),
        SIMDE_FLOAT32_C(   494.62), SIMDE_FLOAT32_C(  -875.96), SIMDE_FLOAT32_C(   494.62), SIMDE_FLOAT32_C(  -875.96) } },
    { { SIMDE_FLOAT32_C(  -583.03), SIMDE_FLOAT32_C(  -938.00), SIMDE_FLOAT32_C(   973.38), SIMDE_FLOAT32_C(  -468.70) },
      { SIMDE_FLOAT32_C(  -583.03), SIMDE_FLOAT32_C(  -938.00), SIMDE_FLOAT32_C(  -583.03), SIMDE_FLOAT32_C(  -938.00),
        SIMDE_FLOAT32_C(  -583.03), SIMDE_FLOAT32_C(  -938.00), SIMDE_FLOAT32_C(  -583.03), SIMDE_FLOAT32_C(  -938.00) } },
    { { SIMDE_FLOAT32_C(   521.04), SIMDE_FLOAT32_C(  -960.21), SIMDE_FLOAT32_C(  -215.76), SIMDE_FLOAT32_C(  -218.82) },
      { SIMDE_FLOAT32_C(   521.04), SIMDE_FLOAT32_C(  -960.21), SIMDE_FLOAT32_C(   521.04), SIMDE_FLOAT32_C(  -960.21),
        SIMDE_FLOAT32_C(   521.04), SIMDE_FLOAT32_C(  -960.21), SIMDE_FLOAT32_C(   521.04), SIMDE_FLOAT32_C(  -960.21) } },
    { { SIMDE_FLOAT32_C(   315.04), SIMDE_FLOAT32_C(   872.51), SIMDE_FLOAT32_C(   318.60), SIMDE_FLOAT32_C(   720.27) },
      { SIMDE_FLOAT32_C(   315.04), SIMDE_FLOAT32_C(   872.51), SIMDE_FLOAT32_C(   315.04), SIMDE_FLOAT32_C(   872.51),
        SIMDE_FLOAT32_C(   315.04), SIMDE_FLOAT32_C(   872.51), SIMDE_FLOAT32_C(   315.04), SIMDE_FLOAT32_C(   872.51) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_broadcast_f32x2(a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_mask_broadcast_f32x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -155.94), SIMDE_FLOAT32_C(  -965.17), SIMDE_FLOAT32_C(   378.08), SIMDE_FLOAT32_C(   365.29),
        SIMDE_FLOAT32_C(  -495.97), SIMDE_FLOAT32_C(   311.10), SIMDE_FLOAT32_C(   575.79), SIMDE_FLOAT32_C(  -655.57) },
      UINT8_C( 85),
      { SIMDE_FLOAT32_C(   963.37), SIMDE_FLOAT32_C(  -596.05), SIMDE_FLOAT32_C(   183.95), SIMDE_FLOAT32_C(  -410.87) },
      { SIMDE_FLOAT32_C(   963.37), SIMDE_FLOAT32_C(  -965.17), SIMDE_FLOAT32_C(   963.37), SIMDE_FLOAT32_C(   365.29),
        SIMDE_FLOAT32_C(   963.37), SIMDE_FLOAT32_C(   311.10), SIMDE_FLOAT32_C(   963.37), SIMDE_FLOAT32_C(  -655.57) } },
    { { SIMDE_FLOAT32_C(   431.64), SIMDE_FLOAT32_C(   613.27), SIMDE_FLOAT32_C(  -834.97), SIMDE_FLOAT32_C(   711.68),
        SIMDE_FLOAT32_C(  -862.98), SIMDE_FLOAT32_C(   -74.52), SIMDE_FLOAT32_C(  -451.05), SIMDE_FLOAT32_C(  -751.41) },
      UINT8_C(193),
      { SIMDE_FLOAT32_C(   -39.01), SIMDE_FLOAT32_C(   325.90), SIMDE_FLOAT32_C(  -543.82), SIMDE_FLOAT32_C(    50.30) },
      { SIMDE_FLOAT32_C(   -39.01), SIMDE_FLOAT32_C(   613.27), SIMDE_FLOAT32_C(  -834.97), SIMDE_FLOAT32_C(   711.68),
        SIMDE_FLOAT32_C(  -862.98), SIMDE_FLOAT32_C(   -74.52), SIMDE_FLOAT32_C(   -39.01), SIMDE_FLOAT32_C(   325.90) } },
    { { SIMDE_FLOAT32_C(  -570.27), SIMDE_FLOAT32_C(  -600.03), SIMDE_FLOAT32_C(  -713.28), SIMDE_FLOAT32_C(   -16.45),
        SIMDE_FLOAT32_C(  -512.72), SIMDE_FLOAT32_C(   640.13), SIMDE_FLOAT32_C(   632.82), SIMDE_FLOAT32_C(  -156.53) },
      UINT8_C(110),
      { SIMDE_FLOAT32_C(   351.05), SIMDE_FLOAT32_C(    39.68), SIMDE_FLOAT32_C(   822.74), SIMDE_FLOAT32_C(  -140.05) },
      { SIMDE_FLOAT32_C(  -570.27), SIMDE_FLOAT32_C(    39.68), SIMDE_FLOAT32_C(   351.05), SIMDE_FLOAT32_C(    39.68),
        SIMDE_FLOAT32_C(  -512.72), SIMDE_FLOAT32_C(    39.68), SIMDE_FLOAT32_C(   351.05), SIMDE_FLOAT32_C(  -156.53) } },
    { { SIMDE_FLOAT32_C(   219.95), SIMDE_FLOAT32_C(   765.90), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(  -363.72),
        SIMDE_FLOAT32_C(   978.16), SIMDE_FLOAT32_C(   -55.83), SIMDE_FLOAT32_C(  -268.61), SIMDE_FLOAT32_C(  -471.94) },
      UINT8_C(194),
      { SIMDE_FLOAT32_C(   300.83), SIMDE_FLOAT32_C(   122.56), SIMDE_FLOAT32_C(  -137.37), SIMDE_FLOAT32_C(  -830.55) },
      { SIMDE_FLOAT32_C(   219.95), SIMDE_FLOAT32_C(   122.56), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(  -363.72),
        SIMDE_FLOAT32_C(   978.16), SIMDE_FLOAT32_C(   -55.83), SIMDE_FLOAT32_C(   300.83), SIMDE_FLOAT32_C(   122.56) } },
    { { SIMDE_FLOAT32_C(  -993.95), SIMDE_FLOAT32_C(   735.37), SIMDE_FLOAT32_C(  -715.04), SIMDE_FLOAT32_C(   363.48),
        SIMDE_FLOAT32_C(   997.38), SIMDE_FLOAT32_C(   957.48), SIMDE_FLOAT32_C(   411.04), SIMDE_FLOAT32_C(   318.40) },
      UINT8_C(  0),
      { SIMDE_FLOAT32_C(   944.29), SIMDE_FLOAT32_C(   688.98), SIMDE_FLOAT32_C(  -319.61), SIMDE_FLOAT32_C(   391.33) },
      { SIMDE_FLOAT32_C(  -993.95), SIMDE_FLOAT32_C(   735.37), SIMDE_FLOAT32_C(  -715.04), SIMDE_FLOAT32_C(   363.48),
        SIMDE_FLOAT32_C(   997.38), SIMDE_FLOAT32_C(   957.48), SIMDE_FLOAT32_C(   411.04), SIMDE_FLOAT32_C(   318.40) } },
    { { SIMDE_FLOAT32_C(  -917.62), SIMDE_FLOAT32_C(  -406.65), SIMDE_FLOAT32_C(  -532.97), SIMDE_FLOAT32_C(   298.17),
        SIMDE_FLOAT32_C(  -598.91), SIMDE_FLOAT32_C(   107.47), SIMDE_FLOAT32_C(   214.95), SIMDE_FLOAT32_C(   587.62) },
      UINT8_C(159),
      { SIMDE_FLOAT32_C(  -173.39), SIMDE_FLOAT32_C(  -170.67), SIMDE_FLOAT32_C(  -483.21), SIMDE_FLOAT32_C(   718.07) },
      { SIMDE_FLOAT32_C(  -173.39), SIMDE_FLOAT32_C(  -170.67), SIMDE_FLOAT32_C(  -173.39), SIMDE_FLOAT32_C(  -170.67),
        SIMDE_FLOAT32_C(  -173.39), SIMDE_FLOAT32_C(   107.47), SIMDE_FLOAT32_C(   214.95), SIMDE_FLOAT32_C(  -170.67) } },
    { { SIMDE_FLOAT32_C(   526.28), SIMDE_FLOAT32_C(  -786.80), SIMDE_FLOAT32_C(   286.87), SIMDE_FLOAT32_C(  -560.33),
        SIMDE_FLOAT32_C(   596.72), SIMDE_FLOAT32_C(   991.58), SIMDE_FLOAT32_C(  -572.23), SIMDE_FLOAT32_C(   587.29) },
      UINT8_C( 79),
      { SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(   117.18), SIMDE_FLOAT32_C(  -624.10), SIMDE_FLOAT32_C(   727.41) },
      { SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(   117.18), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(   117.18),
        SIMDE_FLOAT32_C(   596.72), SIMDE_FLOAT32_C(   991.58), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(   587.29) } },
    { { SIMDE_FLOAT32_C(  -473.57), SIMDE_FLOAT32_C(   647.70), SIMDE_FLOAT32_C(  -174.14), SIMDE_FLOAT32_C(  -701.99),
        SIMDE_FLOAT32_C(  -317.30), SIMDE_FLOAT32_C(  -833.25), SIMDE_FLOAT32_C(  -470.85), SIMDE_FLOAT32_C(   426.74) },
      UINT8_C(169),
      { SIMDE_FLOAT32_C(  -800.29), SIMDE_FLOAT32_C(  -506.53), SIMDE_FLOAT32_C(   682.63), SIMDE_FLOAT32_C(   942.35) },
      { SIMDE_FLOAT32_C(  -800.29), SIMDE_FLOAT32_C(   647.70), SIMDE_FLOAT32_C(  -174.14), SIMDE_FLOAT32_C(  -506.53),
        SIMDE_FLOAT32_C(  -317.30), SIMDE_FLOAT32_C(  -506.53), SIMDE_FLOAT32_C(  -470.85), SIMDE_FLOAT32_C(  -506.53) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_mask_broadcast_f32x2(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_maskz_broadcast_f32x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(167),
      { SIMDE_FLOAT32_C(   -73.48), SIMDE_FLOAT32_C(  -950.66), SIMDE_FLOAT32_C(   265.90), SIMDE_FLOAT32_C(  -988.50) },
      { SIMDE_FLOAT32_C(   -73.48), SIMDE_FLOAT32_C(  -950.66), SIMDE_FLOAT32_C(   -73.48), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -950.66), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -950.66) } },
    { UINT8_C(122),
      { SIMDE_FLOAT32_C(   490.14), SIMDE_FLOAT32_C(  -286.45), SIMDE_FLOAT32_C(  -424.27), SIMDE_FLOAT32_C(  -754.18) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -286.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -286.45),
        SIMDE_FLOAT32_C(   490.14), SIMDE_FLOAT32_C(  -286.45), SIMDE_FLOAT32_C(   490.14), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 66),
      { SIMDE_FLOAT32_C(  -622.52), SIMDE_FLOAT32_C(  -691.02), SIMDE_FLOAT32_C(    48.53), SIMDE_FLOAT32_C(  -368.74) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -691.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -622.52), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(140),
      { SIMDE_FLOAT32_C(   336.37), SIMDE_FLOAT32_C(  -709.34), SIMDE_FLOAT32_C(    65.79), SIMDE_FLOAT32_C(  -200.10) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   336.37), SIMDE_FLOAT32_C(  -709.34),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -709.34) } },
    { UINT8_C(151),
      { SIMDE_FLOAT32_C(   450.42), SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(  -507.45), SIMDE_FLOAT32_C(  -644.25) },
      { SIMDE_FLOAT32_C(   450.42), SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(   450.42), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   450.42), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   257.72) } },
    { UINT8_C( 11),
      { SIMDE_FLOAT32_C(  -161.31), SIMDE_FLOAT32_C(   845.16), SIMDE_FLOAT32_C(   584.32), SIMDE_FLOAT32_C(   641.28) },
      { SIMDE_FLOAT32_C(  -161.31), SIMDE_FLOAT32_C(   845.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   845.16),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 82),
      { SIMDE_FLOAT32_C(   565.26), SIMDE_FLOAT32_C(   325.20), SIMDE_FLOAT32_C(  -344.79), SIMDE_FLOAT32_C(  -940.47) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   325.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   565.26), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   565.26), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(152),
      { SIMDE_FLOAT32_C(   715.85), SIMDE_FLOAT32_C(  -726.67), SIMDE_FLOAT32_C(   812.36), SIMDE_FLOAT32_C(  -643.19) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -726.67),
        SIMDE_FLOAT32_C(   715.85), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -726.67) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_maskz_broadcast_f32x2(test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_broadcast_f32x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06), SIMDE_FLOAT32_C(    20.21), SIMDE_FLOAT32_C(  -317.28) },
      { SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06), SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06),
        SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06), SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06),
        SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06), SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06),
        SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06), SIMDE_FLOAT32_C(  -125.63), SIMDE_FLOAT32_C(   601.06) } },
    { { SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90), SIMDE_FLOAT32_C(   590.84), SIMDE_FLOAT32_C(   180.72) },
      { SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90), SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90),
        SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90), SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90),
        SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90), SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90),
        SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90), SIMDE_FLOAT32_C(  -590.78), SIMDE_FLOAT32_C(   832.90) } },
    { { SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02), SIMDE_FLOAT32_C(   218.93), SIMDE_FLOAT32_C(  -470.99) },
      { SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02), SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02),
        SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02), SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02),
        SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02), SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02),
        SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02), SIMDE_FLOAT32_C(  -605.74), SIMDE_FLOAT32_C(  -713.02) } },
    { { SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59), SIMDE_FLOAT32_C(   423.81), SIMDE_FLOAT32_C(   987.29) },
      { SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59), SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59),
        SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59), SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59),
        SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59), SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59),
        SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59), SIMDE_FLOAT32_C(    61.13), SIMDE_FLOAT32_C(  -592.59) } },
    { { SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23), SIMDE_FLOAT32_C(   300.10), SIMDE_FLOAT32_C(  -254.94) },
      { SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23), SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23),
        SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23), SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23),
        SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23), SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23),
        SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23), SIMDE_FLOAT32_C(  -608.09), SIMDE_FLOAT32_C(   -99.23) } },
    { { SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14), SIMDE_FLOAT32_C(   318.61), SIMDE_FLOAT32_C(   956.19) },
      { SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14), SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14),
        SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14), SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14),
        SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14), SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14),
        SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14), SIMDE_FLOAT32_C(  -727.78), SIMDE_FLOAT32_C(   285.14) } },
    { { SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40), SIMDE_FLOAT32_C(   301.28), SIMDE_FLOAT32_C(  -459.90) },
      { SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40), SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40),
        SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40), SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40),
        SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40), SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40),
        SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40), SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   738.40) } },
    { { SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17), SIMDE_FLOAT32_C(   172.39), SIMDE_FLOAT32_C(  -722.17) },
      { SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17), SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17),
        SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17), SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17),
        SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17), SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17),
        SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17), SIMDE_FLOAT32_C(   379.79), SIMDE_FLOAT32_C(  -819.17) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_broadcast_f32x2(a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_broadcast_f32x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    const simde_float32 a[4];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    16.97), SIMDE_FLOAT32_C(  -724.36), SIMDE_FLOAT32_C(  -251.03), SIMDE_FLOAT32_C(   955.86),
        SIMDE_FLOAT32_C(  -884.86), SIMDE_FLOAT32_C(    79.30), SIMDE_FLOAT32_C(   805.27), SIMDE_FLOAT32_C(   217.58),
        SIMDE_FLOAT32_C(   919.33), SIMDE_FLOAT32_C(  -770.42), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(  -528.80),
        SIMDE_FLOAT32_C(   387.46), SIMDE_FLOAT32_C(     8.94), SIMDE_FLOAT32_C(   238.55), SIMDE_FLOAT32_C(  -769.11) },
      UINT16_C(26495),
      { SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -832.82), SIMDE_FLOAT32_C(   858.15), SIMDE_FLOAT32_C(   988.45) },
      { SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -832.82), SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -832.82),
        SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -832.82), SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(   217.58),
        SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -832.82), SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -528.80),
        SIMDE_FLOAT32_C(   387.46), SIMDE_FLOAT32_C(  -832.82), SIMDE_FLOAT32_C(  -701.54), SIMDE_FLOAT32_C(  -769.11) } },
    { { SIMDE_FLOAT32_C(   886.30), SIMDE_FLOAT32_C(   115.75), SIMDE_FLOAT32_C(  -627.06), SIMDE_FLOAT32_C(  -987.33),
        SIMDE_FLOAT32_C(  -126.79), SIMDE_FLOAT32_C(   964.00), SIMDE_FLOAT32_C(  -128.64), SIMDE_FLOAT32_C(   -75.15),
        SIMDE_FLOAT32_C(   949.72), SIMDE_FLOAT32_C(  -114.82), SIMDE_FLOAT32_C(   286.01), SIMDE_FLOAT32_C(  -995.38),
        SIMDE_FLOAT32_C(   721.81), SIMDE_FLOAT32_C(  -531.94), SIMDE_FLOAT32_C(  -379.35), SIMDE_FLOAT32_C(   301.40) },
      UINT16_C(55066),
      { SIMDE_FLOAT32_C(  -112.99), SIMDE_FLOAT32_C(   933.42), SIMDE_FLOAT32_C(   -66.18), SIMDE_FLOAT32_C(  -307.32) },
      { SIMDE_FLOAT32_C(   886.30), SIMDE_FLOAT32_C(   933.42), SIMDE_FLOAT32_C(  -627.06), SIMDE_FLOAT32_C(   933.42),
        SIMDE_FLOAT32_C(  -112.99), SIMDE_FLOAT32_C(   964.00), SIMDE_FLOAT32_C(  -128.64), SIMDE_FLOAT32_C(   -75.15),
        SIMDE_FLOAT32_C(  -112.99), SIMDE_FLOAT32_C(   933.42), SIMDE_FLOAT32_C(  -112.99), SIMDE_FLOAT32_C(  -995.38),
        SIMDE_FLOAT32_C(  -112.99), SIMDE_FLOAT32_C(  -531.94), SIMDE_FLOAT32_C(  -112.99), SIMDE_FLOAT32_C(   933.42) } },
    { { SIMDE_FLOAT32_C(   858.06), SIMDE_FLOAT32_C(  -630.09), SIMDE_FLOAT32_C(    82.49), SIMDE_FLOAT32_C(   401.49),
        SIMDE_FLOAT32_C(  -226.24), SIMDE_FLOAT32_C(  -448.63), SIMDE_FLOAT32_C(  -200.28), SIMDE_FLOAT32_C(  -144.91),
        SIMDE_FLOAT32_C(   574.72), SIMDE_FLOAT32_C(  -647.66), SIMDE_FLOAT32_C(   850.68), SIMDE_FLOAT32_C(  -645.45),
        SIMDE_FLOAT32_C(  -136.23), SIMDE_FLOAT32_C(   385.26), SIMDE_FLOAT32_C(  -998.08), SIMDE_FLOAT32_C(  -718.84) },
      UINT16_C(39639),
      { SIMDE_FLOAT32_C(  -394.96), SIMDE_FLOAT32_C(   -89.93), SIMDE_FLOAT32_C(   511.24), SIMDE_FLOAT32_C(   328.98) },
      { SIMDE_FLOAT32_C(  -394.96), SIMDE_FLOAT32_C(   -89.93), SIMDE_FLOAT32_C(  -394.96), SIMDE_FLOAT32_C(   401.49),
        SIMDE_FLOAT32_C(  -394.96), SIMDE_FLOAT32_C(  -448.63), SIMDE_FLOAT32_C(  -394.96), SIMDE_FLOAT32_C(   -89.93),
        SIMDE_FLOAT32_C(   574.72), SIMDE_FLOAT32_C(   -89.93), SIMDE_FLOAT32_C(   850.68), SIMDE_FLOAT32_C(   -89.93),
        SIMDE_FLOAT32_C(  -394.96), SIMDE_FLOAT32_C(   385.26), SIMDE_FLOAT32_C(  -998.08), SIMDE_FLOAT32_C(   -89.93) } },
    { { SIMDE_FLOAT32_C(  -783.73), SIMDE_FLOAT32_C(  -210.92), SIMDE_FLOAT32_C(  -991.67), SIMDE_FLOAT32_C(   979.95),
        SIMDE_FLOAT32_C(    49.71), SIMDE_FLOAT32_C(  -489.71), SIMDE_FLOAT32_C(  -591.16), SIMDE_FLOAT32_C(   388.37),
        SIMDE_FLOAT32_C(  -622.36), SIMDE_FLOAT32_C(    45.42), SIMDE_FLOAT32_C(  -553.07), SIMDE_FLOAT32_C(   498.54),
        SIMDE_FLOAT32_C(   904.46), SIMDE_FLOAT32_C(  -795.68), SIMDE_FLOAT32_C(  -943.60), SIMDE_FLOAT32_C(   933.59) },
      UINT16_C(44422),
      { SIMDE_FLOAT32_C(   213.33), SIMDE_FLOAT32_C(  -541.90), SIMDE_FLOAT32_C(   310.55), SIMDE_FLOAT32_C(  -596.77) },
      { SIMDE_FLOAT32_C(  -783.73), SIMDE_FLOAT32_C(  -541.90), SIMDE_FLOAT32_C(   213.33), SIMDE_FLOAT32_C(   979.95),
        SIMDE_FLOAT32_C(    49.71), SIMDE_FLOAT32_C(  -489.71), SIMDE_FLOAT32_C(  -591.16), SIMDE_FLOAT32_C(  -541.90),
        SIMDE_FLOAT32_C(   213.33), SIMDE_FLOAT32_C(    45.42), SIMDE_FLOAT32_C(   213.33), SIMDE_FLOAT32_C(  -541.90),
        SIMDE_FLOAT32_C(   904.46), SIMDE_FLOAT32_C(  -541.90), SIMDE_FLOAT32_C(  -943.60), SIMDE_FLOAT32_C(  -541.90) } },
    { { SIMDE_FLOAT32_C(     4.43), SIMDE_FLOAT32_C(   378.61), SIMDE_FLOAT32_C(  -660.44), SIMDE_FLOAT32_C(   -60.44),
        SIMDE_FLOAT32_C(   265.90), SIMDE_FLOAT32_C(   922.57), SIMDE_FLOAT32_C(  -447.45), SIMDE_FLOAT32_C(  -208.75),
        SIMDE_FLOAT32_C(  -386.55), SIMDE_FLOAT32_C(  -791.16), SIMDE_FLOAT32_C(   993.63), SIMDE_FLOAT32_C(  -107.89),
        SIMDE_FLOAT32_C(   758.84), SIMDE_FLOAT32_C(  -215.37), SIMDE_FLOAT32_C(   198.46), SIMDE_FLOAT32_C(  -486.35) },
      UINT16_C(19819),
      { SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(   527.77), SIMDE_FLOAT32_C(   286.90), SIMDE_FLOAT32_C(   -50.52) },
      { SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(   527.77), SIMDE_FLOAT32_C(  -660.44), SIMDE_FLOAT32_C(   527.77),
        SIMDE_FLOAT32_C(   265.90), SIMDE_FLOAT32_C(   527.77), SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(  -208.75),
        SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(  -791.16), SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(   527.77),
        SIMDE_FLOAT32_C(   758.84), SIMDE_FLOAT32_C(  -215.37), SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(  -486.35) } },
    { { SIMDE_FLOAT32_C(   968.23), SIMDE_FLOAT32_C(  -877.74), SIMDE_FLOAT32_C(  -102.63), SIMDE_FLOAT32_C(  -954.86),
        SIMDE_FLOAT32_C(  -411.69), SIMDE_FLOAT32_C(   708.12), SIMDE_FLOAT32_C(  -635.17), SIMDE_FLOAT32_C(   743.77),
        SIMDE_FLOAT32_C(   622.65), SIMDE_FLOAT32_C(   851.75), SIMDE_FLOAT32_C(  -569.83), SIMDE_FLOAT32_C(   908.51),
        SIMDE_FLOAT32_C(  -674.71), SIMDE_FLOAT32_C(   173.61), SIMDE_FLOAT32_C(  -162.66), SIMDE_FLOAT32_C(   200.03) },
      UINT16_C(57825),
      { SIMDE_FLOAT32_C(  -696.94), SIMDE_FLOAT32_C(   529.84), SIMDE_FLOAT32_C(  -942.89), SIMDE_FLOAT32_C(   880.87) },
      { SIMDE_FLOAT32_C(  -696.94), SIMDE_FLOAT32_C(  -877.74), SIMDE_FLOAT32_C(  -102.63), SIMDE_FLOAT32_C(  -954.86),
        SIMDE_FLOAT32_C(  -411.69), SIMDE_FLOAT32_C(   529.84), SIMDE_FLOAT32_C(  -696.94), SIMDE_FLOAT32_C(   529.84),
        SIMDE_FLOAT32_C(  -696.94), SIMDE_FLOAT32_C(   851.75), SIMDE_FLOAT32_C(  -569.83), SIMDE_FLOAT32_C(   908.51),
        SIMDE_FLOAT32_C(  -674.71), SIMDE_FLOAT32_C(   529.84), SIMDE_FLOAT32_C(  -696.94), SIMDE_FLOAT32_C(   529.84) } },
    { { SIMDE_FLOAT32_C(   733.15), SIMDE_FLOAT32_C(    63.36), SIMDE_FLOAT32_C(   903.02), SIMDE_FLOAT32_C(  -977.76),
        SIMDE_FLOAT32_C(   704.77), SIMDE_FLOAT32_C(   985.75), SIMDE_FLOAT32_C(  -492.96), SIMDE_FLOAT32_C(   872.57),
        SIMDE_FLOAT32_C(  -697.69), SIMDE_FLOAT32_C(   -32.06), SIMDE_FLOAT32_C(  -826.65), SIMDE_FLOAT32_C(   423.95),
        SIMDE_FLOAT32_C(  -668.70), SIMDE_FLOAT32_C(  -777.46), SIMDE_FLOAT32_C(  -794.02), SIMDE_FLOAT32_C(   931.91) },
      UINT16_C(22885),
      { SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(  -340.95), SIMDE_FLOAT32_C(  -411.67), SIMDE_FLOAT32_C(  -904.01) },
      { SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(    63.36), SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(  -977.76),
        SIMDE_FLOAT32_C(   704.77), SIMDE_FLOAT32_C(  -340.95), SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(   872.57),
        SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(   -32.06), SIMDE_FLOAT32_C(  -826.65), SIMDE_FLOAT32_C(  -340.95),
        SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(  -777.46), SIMDE_FLOAT32_C(   241.78), SIMDE_FLOAT32_C(   931.91) } },
    { { SIMDE_FLOAT32_C(   377.61), SIMDE_FLOAT32_C(   543.54), SIMDE_FLOAT32_C(  -676.81), SIMDE_FLOAT32_C(   796.04),
        SIMDE_FLOAT32_C(  -952.55), SIMDE_FLOAT32_C(   439.69), SIMDE_FLOAT32_C(  -139.34), SIMDE_FLOAT32_C(   103.48),
        SIMDE_FLOAT32_C(  -782.74), SIMDE_FLOAT32_C(   562.99), SIMDE_FLOAT32_C(   161.99), SIMDE_FLOAT32_C(   620.38),
        SIMDE_FLOAT32_C(   696.86), SIMDE_FLOAT32_C(    88.47), SIMDE_FLOAT32_C(   998.69), SIMDE_FLOAT32_C(  -955.66) },
      UINT16_C(13591),
      { SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(  -372.87), SIMDE_FLOAT32_C(  -839.61), SIMDE_FLOAT32_C(   668.17) },
      { SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(  -372.87), SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(   796.04),
        SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(   439.69), SIMDE_FLOAT32_C(  -139.34), SIMDE_FLOAT32_C(   103.48),
        SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(   562.99), SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(   620.38),
        SIMDE_FLOAT32_C(  -395.69), SIMDE_FLOAT32_C(  -372.87), SIMDE_FLOAT32_C(   998.69), SIMDE_FLOAT32_C(  -955.66) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_mask_broadcast_f32x2(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_broadcast_f32x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[4];
    const simde_float32 r[16];
  } test_vec[] = {
            { UINT16_C(18884),
      { SIMDE_FLOAT32_C(   545.10), SIMDE_FLOAT32_C(  -550.17), SIMDE_FLOAT32_C(  -710.41), SIMDE_FLOAT32_C(   204.85) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   545.10), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   545.10), SIMDE_FLOAT32_C(  -550.17),
        SIMDE_FLOAT32_C(   545.10), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -550.17),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   545.10), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(16968),
      { SIMDE_FLOAT32_C(    51.85), SIMDE_FLOAT32_C(  -493.14), SIMDE_FLOAT32_C(  -214.52), SIMDE_FLOAT32_C(   484.86) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -493.14),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    51.85), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -493.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    51.85), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(55493),
      { SIMDE_FLOAT32_C(  -547.31), SIMDE_FLOAT32_C(  -681.83), SIMDE_FLOAT32_C(   567.76), SIMDE_FLOAT32_C(   376.14) },
      { SIMDE_FLOAT32_C(  -547.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -547.31), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -547.31), SIMDE_FLOAT32_C(  -681.83),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -681.83),
        SIMDE_FLOAT32_C(  -547.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -547.31), SIMDE_FLOAT32_C(  -681.83) } },
    { UINT16_C( 1280),
      { SIMDE_FLOAT32_C(   358.99), SIMDE_FLOAT32_C(  -507.35), SIMDE_FLOAT32_C(  -959.80), SIMDE_FLOAT32_C(   688.48) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   358.99), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   358.99), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(16569),
      { SIMDE_FLOAT32_C(  -988.71), SIMDE_FLOAT32_C(   789.03), SIMDE_FLOAT32_C(  -740.57), SIMDE_FLOAT32_C(  -739.46) },
      { SIMDE_FLOAT32_C(  -988.71), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   789.03),
        SIMDE_FLOAT32_C(  -988.71), SIMDE_FLOAT32_C(   789.03), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   789.03),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -988.71), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(26242),
      { SIMDE_FLOAT32_C(  -555.34), SIMDE_FLOAT32_C(   402.79), SIMDE_FLOAT32_C(  -274.64), SIMDE_FLOAT32_C(   159.53) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   402.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   402.79),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   402.79), SIMDE_FLOAT32_C(  -555.34), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   402.79), SIMDE_FLOAT32_C(  -555.34), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(39055),
      { SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(  -228.90), SIMDE_FLOAT32_C(   813.40), SIMDE_FLOAT32_C(   762.90) },
      { SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(  -228.90), SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(  -228.90),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -228.90),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -228.90),
        SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -228.90) } },
    { UINT16_C(53187),
      { SIMDE_FLOAT32_C(  -400.08), SIMDE_FLOAT32_C(  -173.64), SIMDE_FLOAT32_C(  -349.66), SIMDE_FLOAT32_C(  -663.64) },
      { SIMDE_FLOAT32_C(  -400.08), SIMDE_FLOAT32_C(  -173.64), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -400.08), SIMDE_FLOAT32_C(  -173.64),
        SIMDE_FLOAT32_C(  -400.08), SIMDE_FLOAT32_C(  -173.64), SIMDE_FLOAT32_C(  -400.08), SIMDE_FLOAT32_C(  -173.64),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -400.08), SIMDE_FLOAT32_C(  -173.64) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_maskz_broadcast_f32x2(test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_broadcast_f32x8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[8];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -416.45), SIMDE_FLOAT32_C(   711.04), SIMDE_FLOAT32_C(   494.08), SIMDE_FLOAT32_C(    55.06),
        SIMDE_FLOAT32_C(  -527.80), SIMDE_FLOAT32_C(  -810.11), SIMDE_FLOAT32_C(   486.30), SIMDE_FLOAT32_C(  -695.23) },
      { SIMDE_FLOAT32_C(  -416.45), SIMDE_FLOAT32_C(   711.04), SIMDE_FLOAT32_C(   494.08), SIMDE_FLOAT32_C(    55.06),
        SIMDE_FLOAT32_C(  -527.80), SIMDE_FLOAT32_C(  -810.11), SIMDE_FLOAT32_C(   486.30), SIMDE_FLOAT32_C(  -695.23),
        SIMDE_FLOAT32_C(  -416.45), SIMDE_FLOAT32_C(   711.04), SIMDE_FLOAT32_C(   494.08), SIMDE_FLOAT32_C(    55.06),
        SIMDE_FLOAT32_C(  -527.80), SIMDE_FLOAT32_C(  -810.11), SIMDE_FLOAT32_C(   486.30), SIMDE_FLOAT32_C(  -695.23) } },
    { { SIMDE_FLOAT32_C(  -800.88), SIMDE_FLOAT32_C(  -452.72), SIMDE_FLOAT32_C(  -904.66), SIMDE_FLOAT32_C(  -614.99),
        SIMDE_FLOAT32_C(  -172.17), SIMDE_FLOAT32_C(   311.84), SIMDE_FLOAT32_C(  -833.25), SIMDE_FLOAT32_C(  -503.53) },
      { SIMDE_FLOAT32_C(  -800.88), SIMDE_FLOAT32_C(  -452.72), SIMDE_FLOAT32_C(  -904.66), SIMDE_FLOAT32_C(  -614.99),
        SIMDE_FLOAT32_C(  -172.17), SIMDE_FLOAT32_C(   311.84), SIMDE_FLOAT32_C(  -833.25), SIMDE_FLOAT32_C(  -503.53),
        SIMDE_FLOAT32_C(  -800.88), SIMDE_FLOAT32_C(  -452.72), SIMDE_FLOAT32_C(  -904.66), SIMDE_FLOAT32_C(  -614.99),
        SIMDE_FLOAT32_C(  -172.17), SIMDE_FLOAT32_C(   311.84), SIMDE_FLOAT32_C(  -833.25), SIMDE_FLOAT32_C(  -503.53) } },
    { { SIMDE_FLOAT32_C(  -875.06), SIMDE_FLOAT32_C(   874.51), SIMDE_FLOAT32_C(  -123.24), SIMDE_FLOAT32_C(   657.48),
        SIMDE_FLOAT32_C(   309.07), SIMDE_FLOAT32_C(   484.03), SIMDE_FLOAT32_C(  -839.17), SIMDE_FLOAT32_C(    10.32) },
      { SIMDE_FLOAT32_C(  -875.06), SIMDE_FLOAT32_C(   874.51), SIMDE_FLOAT32_C(  -123.24), SIMDE_FLOAT32_C(   657.48),
        SIMDE_FLOAT32_C(   309.07), SIMDE_FLOAT32_C(   484.03), SIMDE_FLOAT32_C(  -839.17), SIMDE_FLOAT32_C(    10.32),
        SIMDE_FLOAT32_C(  -875.06), SIMDE_FLOAT32_C(   874.51), SIMDE_FLOAT32_C(  -123.24), SIMDE_FLOAT32_C(   657.48),
        SIMDE_FLOAT32_C(   309.07), SIMDE_FLOAT32_C(   484.03), SIMDE_FLOAT32_C(  -839.17), SIMDE_FLOAT32_C(    10.32) } },
    { { SIMDE_FLOAT32_C(  -515.09), SIMDE_FLOAT32_C(   924.58), SIMDE_FLOAT32_C(  -659.21), SIMDE_FLOAT32_C(   676.36),
        SIMDE_FLOAT32_C(  -421.41), SIMDE_FLOAT32_C(  -682.12), SIMDE_FLOAT32_C(  -306.00), SIMDE_FLOAT32_C(  -939.89) },
      { SIMDE_FLOAT32_C(  -515.09), SIMDE_FLOAT32_C(   924.58), SIMDE_FLOAT32_C(  -659.21), SIMDE_FLOAT32_C(   676.36),
        SIMDE_FLOAT32_C(  -421.41), SIMDE_FLOAT32_C(  -682.12), SIMDE_FLOAT32_C(  -306.00), SIMDE_FLOAT32_C(  -939.89),
        SIMDE_FLOAT32_C(  -515.09), SIMDE_FLOAT32_C(   924.58), SIMDE_FLOAT32_C(  -659.21), SIMDE_FLOAT32_C(   676.36),
        SIMDE_FLOAT32_C(  -421.41), SIMDE_FLOAT32_C(  -682.12), SIMDE_FLOAT32_C(  -306.00), SIMDE_FLOAT32_C(  -939.89) } },
    { { SIMDE_FLOAT32_C(  -812.70), SIMDE_FLOAT32_C(   906.23), SIMDE_FLOAT32_C(  -979.37), SIMDE_FLOAT32_C(  -275.20),
        SIMDE_FLOAT32_C(   664.08), SIMDE_FLOAT32_C(  -809.85), SIMDE_FLOAT32_C(   934.39), SIMDE_FLOAT32_C(   280.51) },
      { SIMDE_FLOAT32_C(  -812.70), SIMDE_FLOAT32_C(   906.23), SIMDE_FLOAT32_C(  -979.37), SIMDE_FLOAT32_C(  -275.20),
        SIMDE_FLOAT32_C(   664.08), SIMDE_FLOAT32_C(  -809.85), SIMDE_FLOAT32_C(   934.39), SIMDE_FLOAT32_C(   280.51),
        SIMDE_FLOAT32_C(  -812.70), SIMDE_FLOAT32_C(   906.23), SIMDE_FLOAT32_C(  -979.37), SIMDE_FLOAT32_C(  -275.20),
        SIMDE_FLOAT32_C(   664.08), SIMDE_FLOAT32_C(  -809.85), SIMDE_FLOAT32_C(   934.39), SIMDE_FLOAT32_C(   280.51) } },
    { { SIMDE_FLOAT32_C(   461.56), SIMDE_FLOAT32_C(  -484.84), SIMDE_FLOAT32_C(  -776.35), SIMDE_FLOAT32_C(   -37.28),
        SIMDE_FLOAT32_C(  -552.72), SIMDE_FLOAT32_C(   358.22), SIMDE_FLOAT32_C(   561.82), SIMDE_FLOAT32_C(   465.10) },
      { SIMDE_FLOAT32_C(   461.56), SIMDE_FLOAT32_C(  -484.84), SIMDE_FLOAT32_C(  -776.35), SIMDE_FLOAT32_C(   -37.28),
        SIMDE_FLOAT32_C(  -552.72), SIMDE_FLOAT32_C(   358.22), SIMDE_FLOAT32_C(   561.82), SIMDE_FLOAT32_C(   465.10),
        SIMDE_FLOAT32_C(   461.56), SIMDE_FLOAT32_C(  -484.84), SIMDE_FLOAT32_C(  -776.35), SIMDE_FLOAT32_C(   -37.28),
        SIMDE_FLOAT32_C(  -552.72), SIMDE_FLOAT32_C(   358.22), SIMDE_FLOAT32_C(   561.82), SIMDE_FLOAT32_C(   465.10) } },
    { { SIMDE_FLOAT32_C(   996.67), SIMDE_FLOAT32_C(  -908.09), SIMDE_FLOAT32_C(  -292.64), SIMDE_FLOAT32_C(  -421.79),
        SIMDE_FLOAT32_C(  -984.50), SIMDE_FLOAT32_C(  -529.88), SIMDE_FLOAT32_C(   228.67), SIMDE_FLOAT32_C(  -756.34) },
      { SIMDE_FLOAT32_C(   996.67), SIMDE_FLOAT32_C(  -908.09), SIMDE_FLOAT32_C(  -292.64), SIMDE_FLOAT32_C(  -421.79),
        SIMDE_FLOAT32_C(  -984.50), SIMDE_FLOAT32_C(  -529.88), SIMDE_FLOAT32_C(   228.67), SIMDE_FLOAT32_C(  -756.34),
        SIMDE_FLOAT32_C(   996.67), SIMDE_FLOAT32_C(  -908.09), SIMDE_FLOAT32_C(  -292.64), SIMDE_FLOAT32_C(  -421.79),
        SIMDE_FLOAT32_C(  -984.50), SIMDE_FLOAT32_C(  -529.88), SIMDE_FLOAT32_C(   228.67), SIMDE_FLOAT32_C(  -756.34) } },
    { { SIMDE_FLOAT32_C(   236.36), SIMDE_FLOAT32_C(   442.90), SIMDE_FLOAT32_C(  -175.57), SIMDE_FLOAT32_C(  -799.66),
        SIMDE_FLOAT32_C(    97.65), SIMDE_FLOAT32_C(  -822.08), SIMDE_FLOAT32_C(  -738.45), SIMDE_FLOAT32_C(   923.13) },
      { SIMDE_FLOAT32_C(   236.36), SIMDE_FLOAT32_C(   442.90), SIMDE_FLOAT32_C(  -175.57), SIMDE_FLOAT32_C(  -799.66),
        SIMDE_FLOAT32_C(    97.65), SIMDE_FLOAT32_C(  -822.08), SIMDE_FLOAT32_C(  -738.45), SIMDE_FLOAT32_C(   923.13),
        SIMDE_FLOAT32_C(   236.36), SIMDE_FLOAT32_C(   442.90), SIMDE_FLOAT32_C(  -175.57), SIMDE_FLOAT32_C(  -799.66),
        SIMDE_FLOAT32_C(    97.65), SIMDE_FLOAT32_C(  -822.08), SIMDE_FLOAT32_C(  -738.45), SIMDE_FLOAT32_C(   923.13) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_broadcast_f32x8(a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_broadcast_f32x8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    const simde_float32 a[8];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   280.29), SIMDE_FLOAT32_C(   838.38), SIMDE_FLOAT32_C(   622.29), SIMDE_FLOAT32_C(   762.17),
        SIMDE_FLOAT32_C(  -281.25), SIMDE_FLOAT32_C(   985.78), SIMDE_FLOAT32_C(    78.74), SIMDE_FLOAT32_C(  -555.08),
        SIMDE_FLOAT32_C(   759.89), SIMDE_FLOAT32_C(  -557.22), SIMDE_FLOAT32_C(   754.50), SIMDE_FLOAT32_C(   954.59),
        SIMDE_FLOAT32_C(  -153.57), SIMDE_FLOAT32_C(   932.38), SIMDE_FLOAT32_C(   449.83), SIMDE_FLOAT32_C(   378.57) },
      UINT16_C(36924),
      { SIMDE_FLOAT32_C(   598.39), SIMDE_FLOAT32_C(  -917.42), SIMDE_FLOAT32_C(   853.85), SIMDE_FLOAT32_C(   635.72),
        SIMDE_FLOAT32_C(   497.82), SIMDE_FLOAT32_C(   880.65), SIMDE_FLOAT32_C(  -930.36), SIMDE_FLOAT32_C(  -512.19) },
      { SIMDE_FLOAT32_C(   280.29), SIMDE_FLOAT32_C(   838.38), SIMDE_FLOAT32_C(   853.85), SIMDE_FLOAT32_C(   635.72),
        SIMDE_FLOAT32_C(   497.82), SIMDE_FLOAT32_C(   880.65), SIMDE_FLOAT32_C(    78.74), SIMDE_FLOAT32_C(  -555.08),
        SIMDE_FLOAT32_C(   759.89), SIMDE_FLOAT32_C(  -557.22), SIMDE_FLOAT32_C(   754.50), SIMDE_FLOAT32_C(   954.59),
        SIMDE_FLOAT32_C(   497.82), SIMDE_FLOAT32_C(   932.38), SIMDE_FLOAT32_C(   449.83), SIMDE_FLOAT32_C(  -512.19) } },
    { { SIMDE_FLOAT32_C(  -437.09), SIMDE_FLOAT32_C(  -187.22), SIMDE_FLOAT32_C(  -573.53), SIMDE_FLOAT32_C(   628.55),
        SIMDE_FLOAT32_C(    16.28), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(    13.33), SIMDE_FLOAT32_C(    92.74),
        SIMDE_FLOAT32_C(   617.88), SIMDE_FLOAT32_C(   659.02), SIMDE_FLOAT32_C(   114.72), SIMDE_FLOAT32_C(    86.74),
        SIMDE_FLOAT32_C(   -78.46), SIMDE_FLOAT32_C(  -669.19), SIMDE_FLOAT32_C(   913.81), SIMDE_FLOAT32_C(   480.88) },
      UINT16_C(25166),
      { SIMDE_FLOAT32_C(  -761.34), SIMDE_FLOAT32_C(   162.88), SIMDE_FLOAT32_C(  -410.95), SIMDE_FLOAT32_C(  -918.77),
        SIMDE_FLOAT32_C(   294.07), SIMDE_FLOAT32_C(   489.11), SIMDE_FLOAT32_C(   466.01), SIMDE_FLOAT32_C(   281.28) },
      { SIMDE_FLOAT32_C(  -437.09), SIMDE_FLOAT32_C(   162.88), SIMDE_FLOAT32_C(  -410.95), SIMDE_FLOAT32_C(  -918.77),
        SIMDE_FLOAT32_C(    16.28), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(   466.01), SIMDE_FLOAT32_C(    92.74),
        SIMDE_FLOAT32_C(   617.88), SIMDE_FLOAT32_C(   162.88), SIMDE_FLOAT32_C(   114.72), SIMDE_FLOAT32_C(    86.74),
        SIMDE_FLOAT32_C(   -78.46), SIMDE_FLOAT32_C(   489.11), SIMDE_FLOAT32_C(   466.01), SIMDE_FLOAT32_C(   480.88) } },
    { { SIMDE_FLOAT32_C(  -606.28), SIMDE_FLOAT32_C(   188.60), SIMDE_FLOAT32_C(  -142.85), SIMDE_FLOAT32_C(  -814.99),
        SIMDE_FLOAT32_C(   440.56), SIMDE_FLOAT32_C(   576.44), SIMDE_FLOAT32_C(   238.85), SIMDE_FLOAT32_C(   303.69),
        SIMDE_FLOAT32_C(   150.34), SIMDE_FLOAT32_C(   808.69), SIMDE_FLOAT32_C(  -362.83), SIMDE_FLOAT32_C(  -158.08),
        SIMDE_FLOAT32_C(  -803.96), SIMDE_FLOAT32_C(  -196.75), SIMDE_FLOAT32_C(  -727.89), SIMDE_FLOAT32_C(   308.53) },
      UINT16_C(23787),
      { SIMDE_FLOAT32_C(   944.26), SIMDE_FLOAT32_C(   110.45), SIMDE_FLOAT32_C(   407.09), SIMDE_FLOAT32_C(    45.91),
        SIMDE_FLOAT32_C(  -335.37), SIMDE_FLOAT32_C(  -560.84), SIMDE_FLOAT32_C(     3.97), SIMDE_FLOAT32_C(   760.14) },
      { SIMDE_FLOAT32_C(   944.26), SIMDE_FLOAT32_C(   110.45), SIMDE_FLOAT32_C(  -142.85), SIMDE_FLOAT32_C(    45.91),
        SIMDE_FLOAT32_C(   440.56), SIMDE_FLOAT32_C(  -560.84), SIMDE_FLOAT32_C(     3.97), SIMDE_FLOAT32_C(   760.14),
        SIMDE_FLOAT32_C(   150.34), SIMDE_FLOAT32_C(   808.69), SIMDE_FLOAT32_C(   407.09), SIMDE_FLOAT32_C(    45.91),
        SIMDE_FLOAT32_C(  -335.37), SIMDE_FLOAT32_C(  -196.75), SIMDE_FLOAT32_C(     3.97), SIMDE_FLOAT32_C(   308.53) } },
    { { SIMDE_FLOAT32_C(  -278.78), SIMDE_FLOAT32_C(   517.15), SIMDE_FLOAT32_C(  -283.92), SIMDE_FLOAT32_C(   114.05),
        SIMDE_FLOAT32_C(   798.05), SIMDE_FLOAT32_C(   868.23), SIMDE_FLOAT32_C(   258.92), SIMDE_FLOAT32_C(  -367.27),
        SIMDE_FLOAT32_C(  -720.23), SIMDE_FLOAT32_C(  -836.19), SIMDE_FLOAT32_C(   163.28), SIMDE_FLOAT32_C(   201.97),
        SIMDE_FLOAT32_C(   461.48), SIMDE_FLOAT32_C(    33.48), SIMDE_FLOAT32_C(   752.68), SIMDE_FLOAT32_C(   274.33) },
      UINT16_C( 9614),
      { SIMDE_FLOAT32_C(  -353.42), SIMDE_FLOAT32_C(    72.45), SIMDE_FLOAT32_C(  -313.79), SIMDE_FLOAT32_C(    54.95),
        SIMDE_FLOAT32_C(  -482.32), SIMDE_FLOAT32_C(  -268.09), SIMDE_FLOAT32_C(   146.77), SIMDE_FLOAT32_C(   772.72) },
      { SIMDE_FLOAT32_C(  -278.78), SIMDE_FLOAT32_C(    72.45), SIMDE_FLOAT32_C(  -313.79), SIMDE_FLOAT32_C(    54.95),
        SIMDE_FLOAT32_C(   798.05), SIMDE_FLOAT32_C(   868.23), SIMDE_FLOAT32_C(   258.92), SIMDE_FLOAT32_C(   772.72),
        SIMDE_FLOAT32_C(  -353.42), SIMDE_FLOAT32_C(  -836.19), SIMDE_FLOAT32_C(  -313.79), SIMDE_FLOAT32_C(   201.97),
        SIMDE_FLOAT32_C(   461.48), SIMDE_FLOAT32_C(  -268.09), SIMDE_FLOAT32_C(   752.68), SIMDE_FLOAT32_C(   274.33) } },
    { { SIMDE_FLOAT32_C(  -894.15), SIMDE_FLOAT32_C(    -6.16), SIMDE_FLOAT32_C(   455.15), SIMDE_FLOAT32_C(  -216.19),
        SIMDE_FLOAT32_C(   419.21), SIMDE_FLOAT32_C(  -283.83), SIMDE_FLOAT32_C(  -341.07), SIMDE_FLOAT32_C(  -431.79),
        SIMDE_FLOAT32_C(   825.19), SIMDE_FLOAT32_C(  -956.94), SIMDE_FLOAT32_C(   688.79), SIMDE_FLOAT32_C(   509.40),
        SIMDE_FLOAT32_C(  -511.22), SIMDE_FLOAT32_C(   -14.80), SIMDE_FLOAT32_C(  -763.30), SIMDE_FLOAT32_C(  -769.02) },
      UINT16_C(57357),
      { SIMDE_FLOAT32_C(  -152.14), SIMDE_FLOAT32_C(  -951.21), SIMDE_FLOAT32_C(   936.35), SIMDE_FLOAT32_C(  -713.46),
        SIMDE_FLOAT32_C(   933.97), SIMDE_FLOAT32_C(  -738.03), SIMDE_FLOAT32_C(     3.91), SIMDE_FLOAT32_C(  -225.68) },
      { SIMDE_FLOAT32_C(  -152.14), SIMDE_FLOAT32_C(    -6.16), SIMDE_FLOAT32_C(   936.35), SIMDE_FLOAT32_C(  -713.46),
        SIMDE_FLOAT32_C(   419.21), SIMDE_FLOAT32_C(  -283.83), SIMDE_FLOAT32_C(  -341.07), SIMDE_FLOAT32_C(  -431.79),
        SIMDE_FLOAT32_C(   825.19), SIMDE_FLOAT32_C(  -956.94), SIMDE_FLOAT32_C(   688.79), SIMDE_FLOAT32_C(   509.40),
        SIMDE_FLOAT32_C(  -511.22), SIMDE_FLOAT32_C(  -738.03), SIMDE_FLOAT32_C(     3.91), SIMDE_FLOAT32_C(  -225.68) } },
    { { SIMDE_FLOAT32_C(   958.35), SIMDE_FLOAT32_C(   959.55), SIMDE_FLOAT32_C(  -771.84), SIMDE_FLOAT32_C(  -312.71),
        SIMDE_FLOAT32_C(   261.02), SIMDE_FLOAT32_C(  -965.72), SIMDE_FLOAT32_C(  -898.55), SIMDE_FLOAT32_C(    98.86),
        SIMDE_FLOAT32_C(  -506.78), SIMDE_FLOAT32_C(   475.13), SIMDE_FLOAT32_C(  -561.78), SIMDE_FLOAT32_C(   145.04),
        SIMDE_FLOAT32_C(  -310.71), SIMDE_FLOAT32_C(  -100.99), SIMDE_FLOAT32_C(   656.93), SIMDE_FLOAT32_C(   955.62) },
      UINT16_C(55637),
      { SIMDE_FLOAT32_C(    64.66), SIMDE_FLOAT32_C(   704.14), SIMDE_FLOAT32_C(   421.81), SIMDE_FLOAT32_C(  -620.94),
        SIMDE_FLOAT32_C(  -124.06), SIMDE_FLOAT32_C(   858.04), SIMDE_FLOAT32_C(  -855.91), SIMDE_FLOAT32_C(   691.15) },
      { SIMDE_FLOAT32_C(    64.66), SIMDE_FLOAT32_C(   959.55), SIMDE_FLOAT32_C(   421.81), SIMDE_FLOAT32_C(  -312.71),
        SIMDE_FLOAT32_C(  -124.06), SIMDE_FLOAT32_C(  -965.72), SIMDE_FLOAT32_C(  -855.91), SIMDE_FLOAT32_C(    98.86),
        SIMDE_FLOAT32_C(    64.66), SIMDE_FLOAT32_C(   475.13), SIMDE_FLOAT32_C(  -561.78), SIMDE_FLOAT32_C(  -620.94),
        SIMDE_FLOAT32_C(  -124.06), SIMDE_FLOAT32_C(  -100.99), SIMDE_FLOAT32_C(  -855.91), SIMDE_FLOAT32_C(   691.15) } },
    { { SIMDE_FLOAT32_C(   165.52), SIMDE_FLOAT32_C(  -117.15), SIMDE_FLOAT32_C(  -914.50), SIMDE_FLOAT32_C(   -48.64),
        SIMDE_FLOAT32_C(   429.74), SIMDE_FLOAT32_C(   612.18), SIMDE_FLOAT32_C(   933.85), SIMDE_FLOAT32_C(  -778.14),
        SIMDE_FLOAT32_C(  -214.40), SIMDE_FLOAT32_C(   623.77), SIMDE_FLOAT32_C(  -288.84), SIMDE_FLOAT32_C(  -541.76),
        SIMDE_FLOAT32_C(   699.14), SIMDE_FLOAT32_C(   473.09), SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(  -518.42) },
      UINT16_C(63181),
      { SIMDE_FLOAT32_C(   188.68), SIMDE_FLOAT32_C(  -923.58), SIMDE_FLOAT32_C(  -542.98), SIMDE_FLOAT32_C(   193.71),
        SIMDE_FLOAT32_C(  -319.51), SIMDE_FLOAT32_C(    46.76), SIMDE_FLOAT32_C(   -44.67), SIMDE_FLOAT32_C(  -768.90) },
      { SIMDE_FLOAT32_C(   188.68), SIMDE_FLOAT32_C(  -117.15), SIMDE_FLOAT32_C(  -542.98), SIMDE_FLOAT32_C(   193.71),
        SIMDE_FLOAT32_C(   429.74), SIMDE_FLOAT32_C(   612.18), SIMDE_FLOAT32_C(   -44.67), SIMDE_FLOAT32_C(  -768.90),
        SIMDE_FLOAT32_C(  -214.40), SIMDE_FLOAT32_C(  -923.58), SIMDE_FLOAT32_C(  -542.98), SIMDE_FLOAT32_C(  -541.76),
        SIMDE_FLOAT32_C(  -319.51), SIMDE_FLOAT32_C(    46.76), SIMDE_FLOAT32_C(   -44.67), SIMDE_FLOAT32_C(  -768.90) } },
    { { SIMDE_FLOAT32_C(  -857.07), SIMDE_FLOAT32_C(  -775.77), SIMDE_FLOAT32_C(  -351.82), SIMDE_FLOAT32_C(   984.69),
        SIMDE_FLOAT32_C(  -320.14), SIMDE_FLOAT32_C(  -636.62), SIMDE_FLOAT32_C(   297.63), SIMDE_FLOAT32_C(   186.04),
        SIMDE_FLOAT32_C(   780.35), SIMDE_FLOAT32_C(  -693.20), SIMDE_FLOAT32_C(  -589.12), SIMDE_FLOAT32_C(   731.33),
        SIMDE_FLOAT32_C(  -601.90), SIMDE_FLOAT32_C(  -195.41), SIMDE_FLOAT32_C(  -239.98), SIMDE_FLOAT32_C(   675.16) },
      UINT16_C(63687),
      { SIMDE_FLOAT32_C(   751.41), SIMDE_FLOAT32_C(   926.41), SIMDE_FLOAT32_C(   149.18), SIMDE_FLOAT32_C(  -662.14),
        SIMDE_FLOAT32_C(  -649.07), SIMDE_FLOAT32_C(  -858.90), SIMDE_FLOAT32_C(   465.33), SIMDE_FLOAT32_C(   831.66) },
      { SIMDE_FLOAT32_C(   751.41), SIMDE_FLOAT32_C(   926.41), SIMDE_FLOAT32_C(   149.18), SIMDE_FLOAT32_C(   984.69),
        SIMDE_FLOAT32_C(  -320.14), SIMDE_FLOAT32_C(  -636.62), SIMDE_FLOAT32_C(   465.33), SIMDE_FLOAT32_C(   831.66),
        SIMDE_FLOAT32_C(   780.35), SIMDE_FLOAT32_C(  -693.20), SIMDE_FLOAT32_C(  -589.12), SIMDE_FLOAT32_C(  -662.14),
        SIMDE_FLOAT32_C(  -649.07), SIMDE_FLOAT32_C(  -858.90), SIMDE_FLOAT32_C(   465.33), SIMDE_FLOAT32_C(   831.66) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_mask_broadcast_f32x8(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_broadcast_f32x8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[8];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(49062),
      { SIMDE_FLOAT32_C(   -67.12), SIMDE_FLOAT32_C(  -144.98), SIMDE_FLOAT32_C(  -693.09), SIMDE_FLOAT32_C(  -717.03),
        SIMDE_FLOAT32_C(   833.33), SIMDE_FLOAT32_C(  -297.62), SIMDE_FLOAT32_C(  -166.55), SIMDE_FLOAT32_C(   748.74) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -144.98), SIMDE_FLOAT32_C(  -693.09), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -297.62), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   748.74),
        SIMDE_FLOAT32_C(   -67.12), SIMDE_FLOAT32_C(  -144.98), SIMDE_FLOAT32_C(  -693.09), SIMDE_FLOAT32_C(  -717.03),
        SIMDE_FLOAT32_C(   833.33), SIMDE_FLOAT32_C(  -297.62), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   748.74) } },
    { UINT16_C( 6586),
      { SIMDE_FLOAT32_C(  -140.91), SIMDE_FLOAT32_C(  -189.72), SIMDE_FLOAT32_C(  -663.50), SIMDE_FLOAT32_C(   613.12),
        SIMDE_FLOAT32_C(   772.89), SIMDE_FLOAT32_C(   -76.35), SIMDE_FLOAT32_C(   859.08), SIMDE_FLOAT32_C(   595.36) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -189.72), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   613.12),
        SIMDE_FLOAT32_C(   772.89), SIMDE_FLOAT32_C(   -76.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   595.36),
        SIMDE_FLOAT32_C(  -140.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   613.12),
        SIMDE_FLOAT32_C(   772.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(41380),
      { SIMDE_FLOAT32_C(  -218.39), SIMDE_FLOAT32_C(  -397.45), SIMDE_FLOAT32_C(    20.87), SIMDE_FLOAT32_C(   703.15),
        SIMDE_FLOAT32_C(  -126.69), SIMDE_FLOAT32_C(   776.77), SIMDE_FLOAT32_C(  -820.00), SIMDE_FLOAT32_C(   252.00) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    20.87), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   776.77), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   252.00),
        SIMDE_FLOAT32_C(  -218.39), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   776.77), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   252.00) } },
    { UINT16_C(14746),
      { SIMDE_FLOAT32_C(   488.59), SIMDE_FLOAT32_C(  -333.19), SIMDE_FLOAT32_C(    82.99), SIMDE_FLOAT32_C(   818.76),
        SIMDE_FLOAT32_C(   927.98), SIMDE_FLOAT32_C(   586.60), SIMDE_FLOAT32_C(   933.90), SIMDE_FLOAT32_C(    84.47) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -333.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   818.76),
        SIMDE_FLOAT32_C(   927.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    84.47),
        SIMDE_FLOAT32_C(   488.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   818.76),
        SIMDE_FLOAT32_C(   927.98), SIMDE_FLOAT32_C(   586.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(22430),
      { SIMDE_FLOAT32_C(  -788.60), SIMDE_FLOAT32_C(    -2.38), SIMDE_FLOAT32_C(   -57.26), SIMDE_FLOAT32_C(  -363.40),
        SIMDE_FLOAT32_C(   348.91), SIMDE_FLOAT32_C(   172.83), SIMDE_FLOAT32_C(   816.49), SIMDE_FLOAT32_C(   677.29) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -2.38), SIMDE_FLOAT32_C(   -57.26), SIMDE_FLOAT32_C(  -363.40),
        SIMDE_FLOAT32_C(   348.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   677.29),
        SIMDE_FLOAT32_C(  -788.60), SIMDE_FLOAT32_C(    -2.38), SIMDE_FLOAT32_C(   -57.26), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   348.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   816.49), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(53747),
      { SIMDE_FLOAT32_C(   -74.10), SIMDE_FLOAT32_C(   628.20), SIMDE_FLOAT32_C(   176.40), SIMDE_FLOAT32_C(   789.58),
        SIMDE_FLOAT32_C(   434.02), SIMDE_FLOAT32_C(   537.30), SIMDE_FLOAT32_C(   360.66), SIMDE_FLOAT32_C(  -306.64) },
      { SIMDE_FLOAT32_C(   -74.10), SIMDE_FLOAT32_C(   628.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   434.02), SIMDE_FLOAT32_C(   537.30), SIMDE_FLOAT32_C(   360.66), SIMDE_FLOAT32_C(  -306.64),
        SIMDE_FLOAT32_C(   -74.10), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   434.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   360.66), SIMDE_FLOAT32_C(  -306.64) } },
    { UINT16_C(57660),
      { SIMDE_FLOAT32_C(   529.43), SIMDE_FLOAT32_C(   185.72), SIMDE_FLOAT32_C(  -666.37), SIMDE_FLOAT32_C(   372.37),
        SIMDE_FLOAT32_C(   420.53), SIMDE_FLOAT32_C(   -76.09), SIMDE_FLOAT32_C(  -764.18), SIMDE_FLOAT32_C(   472.62) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -666.37), SIMDE_FLOAT32_C(   372.37),
        SIMDE_FLOAT32_C(   420.53), SIMDE_FLOAT32_C(   -76.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   529.43), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -76.09), SIMDE_FLOAT32_C(  -764.18), SIMDE_FLOAT32_C(   472.62) } },
    { UINT16_C(60506),
      { SIMDE_FLOAT32_C(  -796.21), SIMDE_FLOAT32_C(   148.32), SIMDE_FLOAT32_C(   781.59), SIMDE_FLOAT32_C(   218.77),
        SIMDE_FLOAT32_C(   802.35), SIMDE_FLOAT32_C(  -915.03), SIMDE_FLOAT32_C(  -953.21), SIMDE_FLOAT32_C(  -530.25) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   148.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   218.77),
        SIMDE_FLOAT32_C(   802.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -953.21), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   781.59), SIMDE_FLOAT32_C(   218.77),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -915.03), SIMDE_FLOAT32_C(  -953.21), SIMDE_FLOAT32_C(  -530.25) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_maskz_broadcast_f32x8(test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_broadcast_f64x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   715.32), SIMDE_FLOAT64_C(   317.58) },
      { SIMDE_FLOAT64_C(   715.32), SIMDE_FLOAT64_C(   317.58), SIMDE_FLOAT64_C(   715.32), SIMDE_FLOAT64_C(   317.58),
        SIMDE_FLOAT64_C(   715.32), SIMDE_FLOAT64_C(   317.58), SIMDE_FLOAT64_C(   715.32), SIMDE_FLOAT64_C(   317.58) } },
    { { SIMDE_FLOAT64_C(  -404.76), SIMDE_FLOAT64_C(  -835.80) },
      { SIMDE_FLOAT64_C(  -404.76), SIMDE_FLOAT64_C(  -835.80), SIMDE_FLOAT64_C(  -404.76), SIMDE_FLOAT64_C(  -835.80),
        SIMDE_FLOAT64_C(  -404.76), SIMDE_FLOAT64_C(  -835.80), SIMDE_FLOAT64_C(  -404.76), SIMDE_FLOAT64_C(  -835.80) } },
    { { SIMDE_FLOAT64_C(   653.97), SIMDE_FLOAT64_C(  -774.97) },
      { SIMDE_FLOAT64_C(   653.97), SIMDE_FLOAT64_C(  -774.97), SIMDE_FLOAT64_C(   653.97), SIMDE_FLOAT64_C(  -774.97),
        SIMDE_FLOAT64_C(   653.97), SIMDE_FLOAT64_C(  -774.97), SIMDE_FLOAT64_C(   653.97), SIMDE_FLOAT64_C(  -774.97) } },
    { { SIMDE_FLOAT64_C(  -843.04), SIMDE_FLOAT64_C(  -900.71) },
      { SIMDE_FLOAT64_C(  -843.04), SIMDE_FLOAT64_C(  -900.71), SIMDE_FLOAT64_C(  -843.04), SIMDE_FLOAT64_C(  -900.71),
        SIMDE_FLOAT64_C(  -843.04), SIMDE_FLOAT64_C(  -900.71), SIMDE_FLOAT64_C(  -843.04), SIMDE_FLOAT64_C(  -900.71) } },
    { { SIMDE_FLOAT64_C(  -197.71), SIMDE_FLOAT64_C(  -989.91) },
      { SIMDE_FLOAT64_C(  -197.71), SIMDE_FLOAT64_C(  -989.91), SIMDE_FLOAT64_C(  -197.71), SIMDE_FLOAT64_C(  -989.91),
        SIMDE_FLOAT64_C(  -197.71), SIMDE_FLOAT64_C(  -989.91), SIMDE_FLOAT64_C(  -197.71), SIMDE_FLOAT64_C(  -989.91) } },
    { { SIMDE_FLOAT64_C(   515.43), SIMDE_FLOAT64_C(   879.19) },
      { SIMDE_FLOAT64_C(   515.43), SIMDE_FLOAT64_C(   879.19), SIMDE_FLOAT64_C(   515.43), SIMDE_FLOAT64_C(   879.19),
        SIMDE_FLOAT64_C(   515.43), SIMDE_FLOAT64_C(   879.19), SIMDE_FLOAT64_C(   515.43), SIMDE_FLOAT64_C(   879.19) } },
    { { SIMDE_FLOAT64_C(   610.61), SIMDE_FLOAT64_C(   540.00) },
      { SIMDE_FLOAT64_C(   610.61), SIMDE_FLOAT64_C(   540.00), SIMDE_FLOAT64_C(   610.61), SIMDE_FLOAT64_C(   540.00),
        SIMDE_FLOAT64_C(   610.61), SIMDE_FLOAT64_C(   540.00), SIMDE_FLOAT64_C(   610.61), SIMDE_FLOAT64_C(   540.00) } },
    { { SIMDE_FLOAT64_C(  -234.86), SIMDE_FLOAT64_C(   751.29) },
      { SIMDE_FLOAT64_C(  -234.86), SIMDE_FLOAT64_C(   751.29), SIMDE_FLOAT64_C(  -234.86), SIMDE_FLOAT64_C(   751.29),
        SIMDE_FLOAT64_C(  -234.86), SIMDE_FLOAT64_C(   751.29), SIMDE_FLOAT64_C(  -234.86), SIMDE_FLOAT64_C(   751.29) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_broadcast_f64x2(a);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_broadcast_f64x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   749.13), SIMDE_FLOAT64_C(   675.39), SIMDE_FLOAT64_C(  -739.63), SIMDE_FLOAT64_C(  -916.53),
        SIMDE_FLOAT64_C(   -70.94), SIMDE_FLOAT64_C(  -224.46), SIMDE_FLOAT64_C(  -485.72), SIMDE_FLOAT64_C(   433.96) },
      UINT8_C(250),
      { SIMDE_FLOAT64_C(   424.19), SIMDE_FLOAT64_C(  -720.98) },
      { SIMDE_FLOAT64_C(   749.13), SIMDE_FLOAT64_C(  -720.98), SIMDE_FLOAT64_C(  -739.63), SIMDE_FLOAT64_C(  -720.98),
        SIMDE_FLOAT64_C(   424.19), SIMDE_FLOAT64_C(  -720.98), SIMDE_FLOAT64_C(   424.19), SIMDE_FLOAT64_C(  -720.98) } },
    { { SIMDE_FLOAT64_C(   461.33), SIMDE_FLOAT64_C(  -402.24), SIMDE_FLOAT64_C(  -437.75), SIMDE_FLOAT64_C(   785.96),
        SIMDE_FLOAT64_C(  -372.46), SIMDE_FLOAT64_C(   110.74), SIMDE_FLOAT64_C(  -831.39), SIMDE_FLOAT64_C(   846.99) },
      UINT8_C( 78),
      { SIMDE_FLOAT64_C(  -572.48), SIMDE_FLOAT64_C(   394.61) },
      { SIMDE_FLOAT64_C(   461.33), SIMDE_FLOAT64_C(   394.61), SIMDE_FLOAT64_C(  -572.48), SIMDE_FLOAT64_C(   394.61),
        SIMDE_FLOAT64_C(  -372.46), SIMDE_FLOAT64_C(   110.74), SIMDE_FLOAT64_C(  -572.48), SIMDE_FLOAT64_C(   846.99) } },
    { { SIMDE_FLOAT64_C(   215.35), SIMDE_FLOAT64_C(  -616.54), SIMDE_FLOAT64_C(  -262.30), SIMDE_FLOAT64_C(  -426.39),
        SIMDE_FLOAT64_C(  -336.22), SIMDE_FLOAT64_C(  -839.02), SIMDE_FLOAT64_C(   672.49), SIMDE_FLOAT64_C(   589.70) },
      UINT8_C(163),
      { SIMDE_FLOAT64_C(  -982.23), SIMDE_FLOAT64_C(  -416.77) },
      { SIMDE_FLOAT64_C(  -982.23), SIMDE_FLOAT64_C(  -416.77), SIMDE_FLOAT64_C(  -262.30), SIMDE_FLOAT64_C(  -426.39),
        SIMDE_FLOAT64_C(  -336.22), SIMDE_FLOAT64_C(  -416.77), SIMDE_FLOAT64_C(   672.49), SIMDE_FLOAT64_C(  -416.77) } },
    { { SIMDE_FLOAT64_C(  -578.35), SIMDE_FLOAT64_C(  -267.73), SIMDE_FLOAT64_C(   242.90), SIMDE_FLOAT64_C(   449.74),
        SIMDE_FLOAT64_C(   714.62), SIMDE_FLOAT64_C(   671.90), SIMDE_FLOAT64_C(   577.25), SIMDE_FLOAT64_C(   -88.86) },
      UINT8_C(222),
      { SIMDE_FLOAT64_C(   379.16), SIMDE_FLOAT64_C(   573.95) },
      { SIMDE_FLOAT64_C(  -578.35), SIMDE_FLOAT64_C(   573.95), SIMDE_FLOAT64_C(   379.16), SIMDE_FLOAT64_C(   573.95),
        SIMDE_FLOAT64_C(   379.16), SIMDE_FLOAT64_C(   671.90), SIMDE_FLOAT64_C(   379.16), SIMDE_FLOAT64_C(   573.95) } },
    { { SIMDE_FLOAT64_C(   428.10), SIMDE_FLOAT64_C(  -969.60), SIMDE_FLOAT64_C(  -117.58), SIMDE_FLOAT64_C(  -121.88),
        SIMDE_FLOAT64_C(  -513.12), SIMDE_FLOAT64_C(   -67.52), SIMDE_FLOAT64_C(  -880.81), SIMDE_FLOAT64_C(   257.25) },
      UINT8_C( 35),
      { SIMDE_FLOAT64_C(   -71.92), SIMDE_FLOAT64_C(  -682.64) },
      { SIMDE_FLOAT64_C(   -71.92), SIMDE_FLOAT64_C(  -682.64), SIMDE_FLOAT64_C(  -117.58), SIMDE_FLOAT64_C(  -121.88),
        SIMDE_FLOAT64_C(  -513.12), SIMDE_FLOAT64_C(  -682.64), SIMDE_FLOAT64_C(  -880.81), SIMDE_FLOAT64_C(   257.25) } },
    { { SIMDE_FLOAT64_C(   858.06), SIMDE_FLOAT64_C(  -576.56), SIMDE_FLOAT64_C(  -199.04), SIMDE_FLOAT64_C(   741.89),
        SIMDE_FLOAT64_C(   940.66), SIMDE_FLOAT64_C(  -320.73), SIMDE_FLOAT64_C(  -519.45), SIMDE_FLOAT64_C(  -359.73) },
      UINT8_C( 14),
      { SIMDE_FLOAT64_C(  -260.24), SIMDE_FLOAT64_C(   150.09) },
      { SIMDE_FLOAT64_C(   858.06), SIMDE_FLOAT64_C(   150.09), SIMDE_FLOAT64_C(  -260.24), SIMDE_FLOAT64_C(   150.09),
        SIMDE_FLOAT64_C(   940.66), SIMDE_FLOAT64_C(  -320.73), SIMDE_FLOAT64_C(  -519.45), SIMDE_FLOAT64_C(  -359.73) } },
    { { SIMDE_FLOAT64_C(   508.76), SIMDE_FLOAT64_C(   671.76), SIMDE_FLOAT64_C(   188.22), SIMDE_FLOAT64_C(  -524.84),
        SIMDE_FLOAT64_C(   958.74), SIMDE_FLOAT64_C(  -408.21), SIMDE_FLOAT64_C(  -756.34), SIMDE_FLOAT64_C(   260.63) },
      UINT8_C( 48),
      { SIMDE_FLOAT64_C(  -287.86), SIMDE_FLOAT64_C(   -66.95) },
      { SIMDE_FLOAT64_C(   508.76), SIMDE_FLOAT64_C(   671.76), SIMDE_FLOAT64_C(   188.22), SIMDE_FLOAT64_C(  -524.84),
        SIMDE_FLOAT64_C(  -287.86), SIMDE_FLOAT64_C(   -66.95), SIMDE_FLOAT64_C(  -756.34), SIMDE_FLOAT64_C(   260.63) } },
    { { SIMDE_FLOAT64_C(   741.62), SIMDE_FLOAT64_C(   389.31), SIMDE_FLOAT64_C(  -806.05), SIMDE_FLOAT64_C(   761.48),
        SIMDE_FLOAT64_C(   242.55), SIMDE_FLOAT64_C(   550.14), SIMDE_FLOAT64_C(   214.54), SIMDE_FLOAT64_C(  -176.03) },
      UINT8_C( 79),
      { SIMDE_FLOAT64_C(   639.90), SIMDE_FLOAT64_C(   881.52) },
      { SIMDE_FLOAT64_C(   639.90), SIMDE_FLOAT64_C(   881.52), SIMDE_FLOAT64_C(   639.90), SIMDE_FLOAT64_C(   881.52),
        SIMDE_FLOAT64_C(   242.55), SIMDE_FLOAT64_C(   550.14), SIMDE_FLOAT64_C(   639.90), SIMDE_FLOAT64_C(  -176.03) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_mask_broadcast_f64x2(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_broadcast_f64x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C( 32),
      { SIMDE_FLOAT64_C(    95.43), SIMDE_FLOAT64_C(  -111.80) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -111.80), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(212),
      { SIMDE_FLOAT64_C(   159.26), SIMDE_FLOAT64_C(   721.63) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   159.26), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   159.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   159.26), SIMDE_FLOAT64_C(   721.63) } },
    { UINT8_C(232),
      { SIMDE_FLOAT64_C(   -41.02), SIMDE_FLOAT64_C(   592.81) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   592.81),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   592.81), SIMDE_FLOAT64_C(   -41.02), SIMDE_FLOAT64_C(   592.81) } },
    { UINT8_C(112),
      { SIMDE_FLOAT64_C(    80.26), SIMDE_FLOAT64_C(   969.51) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(    80.26), SIMDE_FLOAT64_C(   969.51), SIMDE_FLOAT64_C(    80.26), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(215),
      { SIMDE_FLOAT64_C(   905.16), SIMDE_FLOAT64_C(  -968.55) },
      { SIMDE_FLOAT64_C(   905.16), SIMDE_FLOAT64_C(  -968.55), SIMDE_FLOAT64_C(   905.16), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   905.16), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   905.16), SIMDE_FLOAT64_C(  -968.55) } },
    { UINT8_C(135),
      { SIMDE_FLOAT64_C(   140.43), SIMDE_FLOAT64_C(   267.82) },
      { SIMDE_FLOAT64_C(   140.43), SIMDE_FLOAT64_C(   267.82), SIMDE_FLOAT64_C(   140.43), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   267.82) } },
    { UINT8_C(192),
      { SIMDE_FLOAT64_C(  -853.88), SIMDE_FLOAT64_C(   811.68) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -853.88), SIMDE_FLOAT64_C(   811.68) } },
    { UINT8_C( 17),
      { SIMDE_FLOAT64_C(  -661.24), SIMDE_FLOAT64_C(   561.84) },
      { SIMDE_FLOAT64_C(  -661.24), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(  -661.24), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_maskz_broadcast_f64x2(test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_or_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   480.60), SIMDE_FLOAT32_C(  -511.13), SIMDE_FLOAT32_C(  -479.78), SIMDE_FLOAT32_C(   269.24),
        SIMDE_FLOAT32_C(  -874.76), SIMDE_FLOAT32_C(   -72.46), SIMDE_FLOAT32_C(   197.37), SIMDE_FLOAT32_C(  -811.08),
        SIMDE_FLOAT32_C(    97.54), SIMDE_FLOAT32_C(  -611.27), SIMDE_FLOAT32_C(   407.81), SIMDE_FLOAT32_C(    -9.58),
        SIMDE_FLOAT32_C(  -941.56), SIMDE_FLOAT32_C(  -785.37), SIMDE_FLOAT32_C(   331.51), SIMDE_FLOAT32_C(  -275.33) },
      { SIMDE_FLOAT32_C(   603.88), SIMDE_FLOAT32_C(  -554.12), SIMDE_FLOAT32_C(   900.59), SIMDE_FLOAT32_C(   137.08),
        SIMDE_FLOAT32_C(  -120.48), SIMDE_FLOAT32_C(  -863.13), SIMDE_FLOAT32_C(  -707.03), SIMDE_FLOAT32_C(   972.38),
        SIMDE_FLOAT32_C(   820.00), SIMDE_FLOAT32_C(  -330.32), SIMDE_FLOAT32_C(   241.94), SIMDE_FLOAT32_C(   338.15),
        SIMDE_FLOAT32_C(  -659.11), SIMDE_FLOAT32_C(   398.68), SIMDE_FLOAT32_C(   573.47), SIMDE_FLOAT32_C(   358.72) },
      { SIMDE_FLOAT32_C(126457.74), SIMDE_FLOAT32_C(-130863.36), SIMDE_FLOAT32_C(-122831.68), SIMDE_FLOAT32_C(   287.24),
        SIMDE_FLOAT32_C(-32122.95), SIMDE_FLOAT32_C(-27637.92), SIMDE_FLOAT32_C(-62943.98), SIMDE_FLOAT32_C( -1007.46),
        SIMDE_FLOAT32_C( 26506.24), SIMDE_FLOAT32_C(-97267.98), SIMDE_FLOAT32_C(   503.93), SIMDE_FLOAT32_C(  -370.69),
        SIMDE_FLOAT32_C(  -959.62), SIMDE_FLOAT32_C(-102063.36), SIMDE_FLOAT32_C( 90046.72), SIMDE_FLOAT32_C(  -375.99) } },
    { { SIMDE_FLOAT32_C(   993.93), SIMDE_FLOAT32_C(  -985.03), SIMDE_FLOAT32_C(   659.60), SIMDE_FLOAT32_C(  -173.26),
        SIMDE_FLOAT32_C(    63.41), SIMDE_FLOAT32_C(  -232.36), SIMDE_FLOAT32_C(   790.92), SIMDE_FLOAT32_C(   958.34),
        SIMDE_FLOAT32_C(   817.72), SIMDE_FLOAT32_C(  -499.64), SIMDE_FLOAT32_C(   607.64), SIMDE_FLOAT32_C(   603.33),
        SIMDE_FLOAT32_C(   226.40), SIMDE_FLOAT32_C(  -876.92), SIMDE_FLOAT32_C(  -443.68), SIMDE_FLOAT32_C(  -893.18) },
      { SIMDE_FLOAT32_C(   265.66), SIMDE_FLOAT32_C(   933.56), SIMDE_FLOAT32_C(   320.39), SIMDE_FLOAT32_C(   825.80),
        SIMDE_FLOAT32_C(  -854.99), SIMDE_FLOAT32_C(   141.14), SIMDE_FLOAT32_C(   123.87), SIMDE_FLOAT32_C(  -184.24),
        SIMDE_FLOAT32_C(  -440.97), SIMDE_FLOAT32_C(   558.13), SIMDE_FLOAT32_C(   445.71), SIMDE_FLOAT32_C(  -893.22),
        SIMDE_FLOAT32_C(  -301.77), SIMDE_FLOAT32_C(   180.84), SIMDE_FLOAT32_C(  -576.68), SIMDE_FLOAT32_C(  -226.07) },
      { SIMDE_FLOAT32_C(129535.99), SIMDE_FLOAT32_C( -1021.56), SIMDE_FLOAT32_C( 84463.86), SIMDE_FLOAT32_C(-61299.75),
        SIMDE_FLOAT32_C(-16239.97), SIMDE_FLOAT32_C(  -237.50), SIMDE_FLOAT32_C( 31711.97), SIMDE_FLOAT32_C(-65469.95),
        SIMDE_FLOAT32_C(-112892.48), SIMDE_FLOAT32_C(-128947.98), SIMDE_FLOAT32_C(114677.93), SIMDE_FLOAT32_C(  -895.49),
        SIMDE_FLOAT32_C(  -493.80), SIMDE_FLOAT32_C(-65535.92), SIMDE_FLOAT32_C(-113663.12), SIMDE_FLOAT32_C(-65371.93) } },
    { { SIMDE_FLOAT32_C(   454.76), SIMDE_FLOAT32_C(  -837.79), SIMDE_FLOAT32_C(  -704.90), SIMDE_FLOAT32_C(   766.06),
        SIMDE_FLOAT32_C(  -788.99), SIMDE_FLOAT32_C(  -546.21), SIMDE_FLOAT32_C(  -221.91), SIMDE_FLOAT32_C(   380.98),
        SIMDE_FLOAT32_C(  -951.29), SIMDE_FLOAT32_C(  -366.31), SIMDE_FLOAT32_C(  -652.14), SIMDE_FLOAT32_C(  -549.49),
        SIMDE_FLOAT32_C(   782.12), SIMDE_FLOAT32_C(  -971.68), SIMDE_FLOAT32_C(   893.59), SIMDE_FLOAT32_C(   570.16) },
      { SIMDE_FLOAT32_C(   642.89), SIMDE_FLOAT32_C(  -941.41), SIMDE_FLOAT32_C(  -206.47), SIMDE_FLOAT32_C(  -125.77),
        SIMDE_FLOAT32_C(   256.81), SIMDE_FLOAT32_C(   243.45), SIMDE_FLOAT32_C(  -290.65), SIMDE_FLOAT32_C(  -982.09),
        SIMDE_FLOAT32_C(    -3.25), SIMDE_FLOAT32_C(  -692.16), SIMDE_FLOAT32_C(   812.74), SIMDE_FLOAT32_C(  -312.12),
        SIMDE_FLOAT32_C(   275.94), SIMDE_FLOAT32_C(  -213.58), SIMDE_FLOAT32_C(   384.73), SIMDE_FLOAT32_C(   236.37) },
      { SIMDE_FLOAT32_C(116723.98), SIMDE_FLOAT32_C( -1005.92), SIMDE_FLOAT32_C(-65145.85), SIMDE_FLOAT32_C(-32710.00),
        SIMDE_FLOAT32_C(-101119.98), SIMDE_FLOAT32_C(-64511.45), SIMDE_FLOAT32_C(  -443.97), SIMDE_FLOAT32_C(-131067.90),
        SIMDE_FLOAT32_C( -1015.29), SIMDE_FLOAT32_C(-97887.49), SIMDE_FLOAT32_C(  -940.75), SIMDE_FLOAT32_C(-80574.72),
        SIMDE_FLOAT32_C(104447.98), SIMDE_FLOAT32_C(-63488.00), SIMDE_FLOAT32_C(114427.90), SIMDE_FLOAT32_C( 61150.74) } },
    { { SIMDE_FLOAT32_C(   695.36), SIMDE_FLOAT32_C(   970.40), SIMDE_FLOAT32_C(  -483.18), SIMDE_FLOAT32_C(  -766.40),
        SIMDE_FLOAT32_C(  -816.54), SIMDE_FLOAT32_C(   446.99), SIMDE_FLOAT32_C(   488.36), SIMDE_FLOAT32_C(  -116.86),
        SIMDE_FLOAT32_C(  -123.76), SIMDE_FLOAT32_C(   -85.46), SIMDE_FLOAT32_C(  -395.60), SIMDE_FLOAT32_C(  -799.86),
        SIMDE_FLOAT32_C(   677.35), SIMDE_FLOAT32_C(   270.67), SIMDE_FLOAT32_C(  -887.56), SIMDE_FLOAT32_C(   725.18) },
      { SIMDE_FLOAT32_C(    61.47), SIMDE_FLOAT32_C(  -848.75), SIMDE_FLOAT32_C(  -941.17), SIMDE_FLOAT32_C(  -221.91),
        SIMDE_FLOAT32_C(   392.93), SIMDE_FLOAT32_C(    38.45), SIMDE_FLOAT32_C(   198.62), SIMDE_FLOAT32_C(   165.26),
        SIMDE_FLOAT32_C(  -481.15), SIMDE_FLOAT32_C(  -648.25), SIMDE_FLOAT32_C(   912.49), SIMDE_FLOAT32_C(   198.88),
        SIMDE_FLOAT32_C(   535.07), SIMDE_FLOAT32_C(   853.64), SIMDE_FLOAT32_C(  -950.23), SIMDE_FLOAT32_C(  -538.25) },
      { SIMDE_FLOAT32_C( 16253.82), SIMDE_FLOAT32_C(  -986.90), SIMDE_FLOAT32_C(-128959.84), SIMDE_FLOAT32_C(-65529.99),
        SIMDE_FLOAT32_C(-104687.12), SIMDE_FLOAT32_C(   447.99), SIMDE_FLOAT32_C(   493.49), SIMDE_FLOAT32_C(  -475.96),
        SIMDE_FLOAT32_C(  -495.18), SIMDE_FLOAT32_C(-21885.76), SIMDE_FLOAT32_C(-117695.73), SIMDE_FLOAT32_C(-51191.29),
        SIMDE_FLOAT32_C(   695.35), SIMDE_FLOAT32_C(110331.93), SIMDE_FLOAT32_C( -1015.75), SIMDE_FLOAT32_C(  -735.43) } },
    { { SIMDE_FLOAT32_C(  -410.72), SIMDE_FLOAT32_C(  -917.00), SIMDE_FLOAT32_C(   -67.17), SIMDE_FLOAT32_C(  -908.76),
        SIMDE_FLOAT32_C(   534.17), SIMDE_FLOAT32_C(  -240.43), SIMDE_FLOAT32_C(  -833.05), SIMDE_FLOAT32_C(   947.68),
        SIMDE_FLOAT32_C(  -393.55), SIMDE_FLOAT32_C(  -335.35), SIMDE_FLOAT32_C(  -257.27), SIMDE_FLOAT32_C(    91.70),
        SIMDE_FLOAT32_C(  -820.62), SIMDE_FLOAT32_C(  -157.46), SIMDE_FLOAT32_C(  -507.25), SIMDE_FLOAT32_C(   705.00) },
      { SIMDE_FLOAT32_C(   880.62), SIMDE_FLOAT32_C(   602.69), SIMDE_FLOAT32_C(  -582.79), SIMDE_FLOAT32_C(  -873.03),
        SIMDE_FLOAT32_C(   911.31), SIMDE_FLOAT32_C(   402.01), SIMDE_FLOAT32_C(   647.66), SIMDE_FLOAT32_C(  -853.70),
        SIMDE_FLOAT32_C(  -128.13), SIMDE_FLOAT32_C(   472.58), SIMDE_FLOAT32_C(   575.79), SIMDE_FLOAT32_C(  -650.07),
        SIMDE_FLOAT32_C(   200.59), SIMDE_FLOAT32_C(  -601.69), SIMDE_FLOAT32_C(  -623.66), SIMDE_FLOAT32_C(   186.55) },
      { SIMDE_FLOAT32_C(-113407.37), SIMDE_FLOAT32_C(  -991.69), SIMDE_FLOAT32_C(-19451.78), SIMDE_FLOAT32_C( -1005.78),
        SIMDE_FLOAT32_C(   927.44), SIMDE_FLOAT32_C(  -498.87), SIMDE_FLOAT32_C(  -967.68), SIMDE_FLOAT32_C( -1015.75),
        SIMDE_FLOAT32_C(  -393.81), SIMDE_FLOAT32_C(  -479.87), SIMDE_FLOAT32_C(-73701.12), SIMDE_FLOAT32_C(-23539.25),
        SIMDE_FLOAT32_C(-52663.68), SIMDE_FLOAT32_C(-40829.92), SIMDE_FLOAT32_C(-131028.48), SIMDE_FLOAT32_C( 47820.80) } },
    { { SIMDE_FLOAT32_C(  -701.53), SIMDE_FLOAT32_C(  -543.04), SIMDE_FLOAT32_C(  -823.70), SIMDE_FLOAT32_C(    31.11),
        SIMDE_FLOAT32_C(   866.09), SIMDE_FLOAT32_C(   355.48), SIMDE_FLOAT32_C(   555.77), SIMDE_FLOAT32_C(   886.63),
        SIMDE_FLOAT32_C(  -481.79), SIMDE_FLOAT32_C(   592.72), SIMDE_FLOAT32_C(  -189.48), SIMDE_FLOAT32_C(  -527.23),
        SIMDE_FLOAT32_C(   860.31), SIMDE_FLOAT32_C(  -791.91), SIMDE_FLOAT32_C(   352.98), SIMDE_FLOAT32_C(   475.12) },
      { SIMDE_FLOAT32_C(  -598.83), SIMDE_FLOAT32_C(  -554.85), SIMDE_FLOAT32_C(   653.69), SIMDE_FLOAT32_C(   649.29),
        SIMDE_FLOAT32_C(   536.82), SIMDE_FLOAT32_C(   402.83), SIMDE_FLOAT32_C(   333.46), SIMDE_FLOAT32_C(   382.59),
        SIMDE_FLOAT32_C(   275.47), SIMDE_FLOAT32_C(  -132.03), SIMDE_FLOAT32_C(   922.98), SIMDE_FLOAT32_C(   461.96),
        SIMDE_FLOAT32_C(    85.99), SIMDE_FLOAT32_C(  -806.33), SIMDE_FLOAT32_C(    56.71), SIMDE_FLOAT32_C(  -909.56) },
      { SIMDE_FLOAT32_C(  -767.84), SIMDE_FLOAT32_C(  -575.86), SIMDE_FLOAT32_C(  -959.70), SIMDE_FLOAT32_C(  8030.48),
        SIMDE_FLOAT32_C(   890.84), SIMDE_FLOAT32_C(   500.00), SIMDE_FLOAT32_C( 89591.82), SIMDE_FLOAT32_C(131031.68),
        SIMDE_FLOAT32_C(  -499.98), SIMDE_FLOAT32_C(-37935.74), SIMDE_FLOAT32_C(-65534.97), SIMDE_FLOAT32_C(-118781.95),
        SIMDE_FLOAT32_C( 32765.98), SIMDE_FLOAT32_C(  -823.99), SIMDE_FLOAT32_C(   486.00), SIMDE_FLOAT32_C(-122847.74) } },
    { { SIMDE_FLOAT32_C(   944.34), SIMDE_FLOAT32_C(  -560.36), SIMDE_FLOAT32_C(    -4.19), SIMDE_FLOAT32_C(  -479.80),
        SIMDE_FLOAT32_C(    51.14), SIMDE_FLOAT32_C(  -569.84), SIMDE_FLOAT32_C(   718.42), SIMDE_FLOAT32_C(   535.49),
        SIMDE_FLOAT32_C(    31.54), SIMDE_FLOAT32_C(   142.94), SIMDE_FLOAT32_C(   349.37), SIMDE_FLOAT32_C(  -194.12),
        SIMDE_FLOAT32_C(  -641.81), SIMDE_FLOAT32_C(  -963.18), SIMDE_FLOAT32_C(  -221.26), SIMDE_FLOAT32_C(  -763.94) },
      { SIMDE_FLOAT32_C(   382.41), SIMDE_FLOAT32_C(  -851.69), SIMDE_FLOAT32_C(  -422.97), SIMDE_FLOAT32_C(  -784.40),
        SIMDE_FLOAT32_C(   546.04), SIMDE_FLOAT32_C(  -653.53), SIMDE_FLOAT32_C(   109.51), SIMDE_FLOAT32_C(   533.50),
        SIMDE_FLOAT32_C(   473.25), SIMDE_FLOAT32_C(  -161.95), SIMDE_FLOAT32_C(    68.59), SIMDE_FLOAT32_C(   837.71),
        SIMDE_FLOAT32_C(  -640.75), SIMDE_FLOAT32_C(   889.72), SIMDE_FLOAT32_C(  -478.90), SIMDE_FLOAT32_C(  -840.17) },
      { SIMDE_FLOAT32_C(130667.96), SIMDE_FLOAT32_C(  -883.99), SIMDE_FLOAT32_C(  -430.97), SIMDE_FLOAT32_C(-122879.98),
        SIMDE_FLOAT32_C( 13091.97), SIMDE_FLOAT32_C(  -701.84), SIMDE_FLOAT32_C( 32208.00), SIMDE_FLOAT32_C(   535.99),
        SIMDE_FLOAT32_C(   505.89), SIMDE_FLOAT32_C(  -175.95), SIMDE_FLOAT32_C(   351.37), SIMDE_FLOAT32_C(-54143.97),
        SIMDE_FLOAT32_C(  -641.81), SIMDE_FLOAT32_C( -1019.74), SIMDE_FLOAT32_C(  -510.90), SIMDE_FLOAT32_C( -1019.98) } },
    { { SIMDE_FLOAT32_C(  -711.36), SIMDE_FLOAT32_C(   214.45), SIMDE_FLOAT32_C(   194.07), SIMDE_FLOAT32_C(  -275.37),
        SIMDE_FLOAT32_C(  -213.28), SIMDE_FLOAT32_C(  -677.66), SIMDE_FLOAT32_C(   637.68), SIMDE_FLOAT32_C(  -440.50),
        SIMDE_FLOAT32_C(   586.73), SIMDE_FLOAT32_C(  -829.70), SIMDE_FLOAT32_C(  -729.50), SIMDE_FLOAT32_C(  -650.44),
        SIMDE_FLOAT32_C(   123.67), SIMDE_FLOAT32_C(   515.02), SIMDE_FLOAT32_C(    23.03), SIMDE_FLOAT32_C(  -964.09) },
      { SIMDE_FLOAT32_C(   587.18), SIMDE_FLOAT32_C(   655.47), SIMDE_FLOAT32_C(   537.23), SIMDE_FLOAT32_C(  -697.87),
        SIMDE_FLOAT32_C(   944.44), SIMDE_FLOAT32_C(  -768.05), SIMDE_FLOAT32_C(  -535.33), SIMDE_FLOAT32_C(   695.04),
        SIMDE_FLOAT32_C(  -482.15), SIMDE_FLOAT32_C(   455.20), SIMDE_FLOAT32_C(   561.68), SIMDE_FLOAT32_C(   223.05),
        SIMDE_FLOAT32_C(   840.35), SIMDE_FLOAT32_C(  -187.16), SIMDE_FLOAT32_C(   369.47), SIMDE_FLOAT32_C(  -383.36) },
      { SIMDE_FLOAT32_C(  -719.49), SIMDE_FLOAT32_C( 63487.21), SIMDE_FLOAT32_C( 50783.98), SIMDE_FLOAT32_C(-90111.98),
        SIMDE_FLOAT32_C(-64863.68), SIMDE_FLOAT32_C(  -933.68), SIMDE_FLOAT32_C(  -639.99), SIMDE_FLOAT32_C(-129925.12),
        SIMDE_FLOAT32_C(-124799.46), SIMDE_FLOAT32_C(-122875.74), SIMDE_FLOAT32_C(  -761.68), SIMDE_FLOAT32_C(-65436.93),
        SIMDE_FLOAT32_C( 31659.71), SIMDE_FLOAT32_C(-48105.99), SIMDE_FLOAT32_C(   369.48), SIMDE_FLOAT32_C(-130911.68) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_or_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_or_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -40.48), SIMDE_FLOAT64_C(  -322.78), SIMDE_FLOAT64_C(  -915.31), SIMDE_FLOAT64_C(   424.37),
        SIMDE_FLOAT64_C(   358.24), SIMDE_FLOAT64_C(   951.77), SIMDE_FLOAT64_C(   466.94), SIMDE_FLOAT64_C(  -212.54) },
      { SIMDE_FLOAT64_C(  -206.62), SIMDE_FLOAT64_C(  -632.27), SIMDE_FLOAT64_C(  -561.37), SIMDE_FLOAT64_C(  -939.45),
        SIMDE_FLOAT64_C(   583.50), SIMDE_FLOAT64_C(   851.39), SIMDE_FLOAT64_C(  -748.10), SIMDE_FLOAT64_C(   610.87) },
      { SIMDE_FLOAT64_C(  -240.00), SIMDE_FLOAT64_C(-98023.69), SIMDE_FLOAT64_C(  -947.37), SIMDE_FLOAT64_C(-130559.73),
        SIMDE_FLOAT64_C( 92157.44), SIMDE_FLOAT64_C(  1015.91), SIMDE_FLOAT64_C(-128764.94), SIMDE_FLOAT64_C(-56511.75) } },
    { { SIMDE_FLOAT64_C(   883.05), SIMDE_FLOAT64_C(  -496.23), SIMDE_FLOAT64_C(  -209.68), SIMDE_FLOAT64_C(  -122.92),
        SIMDE_FLOAT64_C(    19.75), SIMDE_FLOAT64_C(   -49.24), SIMDE_FLOAT64_C(   492.96), SIMDE_FLOAT64_C(  -866.69) },
      { SIMDE_FLOAT64_C(  -385.90), SIMDE_FLOAT64_C(   247.26), SIMDE_FLOAT64_C(  -268.45), SIMDE_FLOAT64_C(   217.01),
        SIMDE_FLOAT64_C(  -674.00), SIMDE_FLOAT64_C(   155.01), SIMDE_FLOAT64_C(  -699.71), SIMDE_FLOAT64_C(  -101.01) },
      { SIMDE_FLOAT64_C(-113126.40), SIMDE_FLOAT64_C(  -510.75), SIMDE_FLOAT64_C(  -431.50), SIMDE_FLOAT64_C(  -507.68),
        SIMDE_FLOAT64_C( -6096.00), SIMDE_FLOAT64_C(  -223.97), SIMDE_FLOAT64_C(-130559.89), SIMDE_FLOAT64_C(-27990.62) } },
    { { SIMDE_FLOAT64_C(   290.86), SIMDE_FLOAT64_C(   407.11), SIMDE_FLOAT64_C(   359.33), SIMDE_FLOAT64_C(  -773.11),
        SIMDE_FLOAT64_C(   409.90), SIMDE_FLOAT64_C(  -892.84), SIMDE_FLOAT64_C(   -43.07), SIMDE_FLOAT64_C(   160.79) },
      { SIMDE_FLOAT64_C(   465.85), SIMDE_FLOAT64_C(  -467.47), SIMDE_FLOAT64_C(  -782.08), SIMDE_FLOAT64_C(  -490.24),
        SIMDE_FLOAT64_C(   592.42), SIMDE_FLOAT64_C(   806.95), SIMDE_FLOAT64_C(   470.98), SIMDE_FLOAT64_C(  -245.49) },
      { SIMDE_FLOAT64_C(   499.87), SIMDE_FLOAT64_C(  -471.49), SIMDE_FLOAT64_C(-124766.50), SIMDE_FLOAT64_C(-125631.46),
        SIMDE_FLOAT64_C(113143.90), SIMDE_FLOAT64_C(  -894.97), SIMDE_FLOAT64_C(  -479.00), SIMDE_FLOAT64_C(  -246.00) } },
    { { SIMDE_FLOAT64_C(    88.45), SIMDE_FLOAT64_C(   537.22), SIMDE_FLOAT64_C(  -949.80), SIMDE_FLOAT64_C(   743.04),
        SIMDE_FLOAT64_C(   296.63), SIMDE_FLOAT64_C(  -483.08), SIMDE_FLOAT64_C(   917.67), SIMDE_FLOAT64_C(  -778.36) },
      { SIMDE_FLOAT64_C(    89.00), SIMDE_FLOAT64_C(   -93.55), SIMDE_FLOAT64_C(  -328.25), SIMDE_FLOAT64_C(  -923.97),
        SIMDE_FLOAT64_C(   880.96), SIMDE_FLOAT64_C(   356.45), SIMDE_FLOAT64_C(   842.15), SIMDE_FLOAT64_C(    25.32) },
      { SIMDE_FLOAT64_C(    89.45), SIMDE_FLOAT64_C(-24495.81), SIMDE_FLOAT64_C(-121574.40), SIMDE_FLOAT64_C( -1023.98),
        SIMDE_FLOAT64_C(112891.91), SIMDE_FLOAT64_C(  -487.47), SIMDE_FLOAT64_C(   991.69), SIMDE_FLOAT64_C( -6483.92) } },
    { { SIMDE_FLOAT64_C(  -519.30), SIMDE_FLOAT64_C(    88.55), SIMDE_FLOAT64_C(   186.42), SIMDE_FLOAT64_C(  -780.93),
        SIMDE_FLOAT64_C(   918.96), SIMDE_FLOAT64_C(   887.03), SIMDE_FLOAT64_C(   360.26), SIMDE_FLOAT64_C(   873.25) },
      { SIMDE_FLOAT64_C(   651.35), SIMDE_FLOAT64_C(  -822.40), SIMDE_FLOAT64_C(   -37.73), SIMDE_FLOAT64_C(  -102.45),
        SIMDE_FLOAT64_C(   167.81), SIMDE_FLOAT64_C(   376.55), SIMDE_FLOAT64_C(   698.04), SIMDE_FLOAT64_C(    15.57) },
      { SIMDE_FLOAT64_C(  -655.37), SIMDE_FLOAT64_C(-32460.80), SIMDE_FLOAT64_C(  -190.92), SIMDE_FLOAT64_C(-26623.95),
        SIMDE_FLOAT64_C( 59391.49), SIMDE_FLOAT64_C(129935.87), SIMDE_FLOAT64_C( 97607.62), SIMDE_FLOAT64_C(  4021.92) } },
    { { SIMDE_FLOAT64_C(  -325.10), SIMDE_FLOAT64_C(    24.24), SIMDE_FLOAT64_C(  -628.64), SIMDE_FLOAT64_C(   379.01),
        SIMDE_FLOAT64_C(    98.66), SIMDE_FLOAT64_C(   182.61), SIMDE_FLOAT64_C(  -798.49), SIMDE_FLOAT64_C(  -146.70) },
      { SIMDE_FLOAT64_C(   387.34), SIMDE_FLOAT64_C(   -48.74), SIMDE_FLOAT64_C(   849.44), SIMDE_FLOAT64_C(   502.00),
        SIMDE_FLOAT64_C(  -892.81), SIMDE_FLOAT64_C(   587.22), SIMDE_FLOAT64_C(  -574.98), SIMDE_FLOAT64_C(   384.87) },
      { SIMDE_FLOAT64_C(  -455.37), SIMDE_FLOAT64_C(  -392.00), SIMDE_FLOAT64_C(  -885.95), SIMDE_FLOAT64_C(   511.01),
        SIMDE_FLOAT64_C(-28602.00), SIMDE_FLOAT64_C( 46814.24), SIMDE_FLOAT64_C(  -831.00), SIMDE_FLOAT64_C(  -422.00) } },
    { { SIMDE_FLOAT64_C(   462.25), SIMDE_FLOAT64_C(  -905.39), SIMDE_FLOAT64_C(  -831.12), SIMDE_FLOAT64_C(  -716.46),
        SIMDE_FLOAT64_C(   498.06), SIMDE_FLOAT64_C(   927.73), SIMDE_FLOAT64_C(   312.19), SIMDE_FLOAT64_C(  -955.24) },
      { SIMDE_FLOAT64_C(  -784.67), SIMDE_FLOAT64_C(    13.39), SIMDE_FLOAT64_C(   973.39), SIMDE_FLOAT64_C(  -224.05),
        SIMDE_FLOAT64_C(   392.29), SIMDE_FLOAT64_C(  -737.84), SIMDE_FLOAT64_C(  -812.63), SIMDE_FLOAT64_C(    85.02) },
      { SIMDE_FLOAT64_C(-118357.76), SIMDE_FLOAT64_C( -3943.87), SIMDE_FLOAT64_C( -1023.50), SIMDE_FLOAT64_C(-62237.99),
        SIMDE_FLOAT64_C(   506.31), SIMDE_FLOAT64_C( -1024.00), SIMDE_FLOAT64_C(-114288.64), SIMDE_FLOAT64_C(-30567.75) } },
    { { SIMDE_FLOAT64_C(   979.20), SIMDE_FLOAT64_C(  -512.78), SIMDE_FLOAT64_C(  -370.35), SIMDE_FLOAT64_C(  -474.08),
        SIMDE_FLOAT64_C(   129.12), SIMDE_FLOAT64_C(    46.51), SIMDE_FLOAT64_C(  -292.51), SIMDE_FLOAT64_C(  -218.79) },
      { SIMDE_FLOAT64_C(   798.26), SIMDE_FLOAT64_C(   278.63), SIMDE_FLOAT64_C(   902.40), SIMDE_FLOAT64_C(   696.72),
        SIMDE_FLOAT64_C(  -256.04), SIMDE_FLOAT64_C(   749.65), SIMDE_FLOAT64_C(  -619.61), SIMDE_FLOAT64_C(   269.84) },
      { SIMDE_FLOAT64_C(   991.45), SIMDE_FLOAT64_C(-71395.84), SIMDE_FLOAT64_C(-127867.73), SIMDE_FLOAT64_C(-122460.48),
        SIMDE_FLOAT64_C(  -258.25), SIMDE_FLOAT64_C( 11994.94), SIMDE_FLOAT64_C(-79310.62), SIMDE_FLOAT64_C(  -445.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_or_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_xor_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  2140215653),  INT32_C(  1293320897), -INT32_C(  1520002534),  INT32_C(   294609697),  INT32_C(  1091317370),  INT32_C(   313266332), -INT32_C(  1143786207),  INT32_C(  1969865590),
         INT32_C(  1062829004), -INT32_C(   597668763),  INT32_C(  1683087224),  INT32_C(   739479593), -INT32_C(   468073407), -INT32_C(   573950189), -INT32_C(   974763361),  INT32_C(   527665652) },
      {  INT32_C(   816665849),  INT32_C(  1611972509), -INT32_C(  1280024725), -INT32_C(  1519923382), -INT32_C(  1677919607), -INT32_C(  1493407047),  INT32_C(  1584582304), -INT32_C(  1720041634),
         INT32_C(    70381333),  INT32_C(   746736592), -INT32_C(  1868567415),  INT32_C(  1303201364),  INT32_C(  2110232181), -INT32_C(  1733384071),  INT32_C(    69343053), -INT32_C(  1142043763) },
      {  INT32_C(  1329352092),  INT32_C(   755121500),  INT32_C(   382911857), -INT32_C(  1259819925), -INT32_C(   621751053), -INT32_C(  1269794267), -INT32_C(   442369151), -INT32_C(   334234584),
         INT32_C(   996709593), -INT32_C(   253622347), -INT32_C(   187812879),  INT32_C(  1639896701), -INT32_C(  1713483212),  INT32_C(  1164222314), -INT32_C(  1044095534), -INT32_C(  1533132167) } },
    { { -INT32_C(  1116734570),  INT32_C(  1613310165),  INT32_C(   813802444),  INT32_C(   429161548), -INT32_C(  1674708291),  INT32_C(  1572063288),  INT32_C(   653388597), -INT32_C(   887480686),
         INT32_C(  1388041778), -INT32_C(   190487029),  INT32_C(   304982209),  INT32_C(   851454399), -INT32_C(   666906362),  INT32_C(  1120951633),  INT32_C(  2076068325),  INT32_C(  1217737327) },
      { -INT32_C(   807130602),  INT32_C(   590835955),  INT32_C(   594477440), -INT32_C(   617573334),  INT32_C(   291751240),  INT32_C(  1236534164),  INT32_C(   789759175), -INT32_C(    74502962),
        -INT32_C(   134459010), -INT32_C(  1974206140), -INT32_C(  1593126896), -INT32_C(   699738723), -INT32_C(   399365675), -INT32_C(  1537291680),  INT32_C(   615597302), -INT32_C(  1491990022) },
      {  INT32_C(  1921765760),  INT32_C(  1126062118),  INT32_C(   334406220), -INT32_C(  1029379994), -INT32_C(  1924251659),  INT32_C(   336055212),  INT32_C(   165883890),  INT32_C(   815084124),
        -INT32_C(  1522038964),  INT32_C(  2129749839), -INT32_C(  1289258799), -INT32_C(   460653534),  INT32_C(   806222035), -INT32_C(   426862799),  INT32_C(  1594821907), -INT32_C(   276350059) } },
    { { -INT32_C(   289806681),  INT32_C(  1144433863),  INT32_C(  2078393105), -INT32_C(   621193477),  INT32_C(   197942373), -INT32_C(   778195138), -INT32_C(  1500149552), -INT32_C(   376058582),
         INT32_C(  1008015921), -INT32_C(   817846632), -INT32_C(  1418259563), -INT32_C(  1728720625), -INT32_C(   875417463), -INT32_C(   433179879), -INT32_C(   401326522), -INT32_C(   293254336) },
      { -INT32_C(  1611473168),  INT32_C(  1779296220),  INT32_C(  1625584338),  INT32_C(  1628081346),  INT32_C(  1516234414), -INT32_C(    67171629),  INT32_C(  1608454162), -INT32_C(   114353618),
        -INT32_C(   353092690),  INT32_C(  1984997008),  INT32_C(  1607474741), -INT32_C(  1472407712), -INT32_C(     3064222),  INT32_C(   279389725), -INT32_C(  1869192019),  INT32_C(   302689758) },
      {  INT32_C(  1900755031),  INT32_C(   775637787),  INT32_C(   453358019), -INT32_C(  1141646791),  INT32_C(  1368636107),  INT32_C(   711108077), -INT32_C(   112551742),  INT32_C(   280680196),
        -INT32_C(   689888865), -INT32_C(  1190133752), -INT32_C(   190378592),  INT32_C(   818480751),  INT32_C(   872615659), -INT32_C(   158788348),  INT32_C(  2021808875), -INT32_C(    57678178) } },
    { {  INT32_C(   419761061),  INT32_C(  1205817843), -INT32_C(  1808728463), -INT32_C(   270741600),  INT32_C(    62568967), -INT32_C(  1758665902), -INT32_C(  1620063715),  INT32_C(   975059798),
         INT32_C(   672464530), -INT32_C(  1296717020),  INT32_C(   968463109), -INT32_C(   943239776),  INT32_C(  1563835967),  INT32_C(  1537408671),  INT32_C(   771343793),  INT32_C(  1593811067) },
      { -INT32_C(  1519602963),  INT32_C(  1238941430), -INT32_C(   210338261), -INT32_C(   240423445), -INT32_C(  1881846659),  INT32_C(   210890163),  INT32_C(   374811810), -INT32_C(  1712882298),
         INT32_C(  1497831658),  INT32_C(  2098029338), -INT32_C(   368469787),  INT32_C(  2040566000), -INT32_C(  1929731099),  INT32_C(  1291609713), -INT32_C(  1096372677), -INT32_C(   147699721) },
      { -INT32_C(  1133921976),  INT32_C(   235400965),  INT32_C(  1732673626),  INT32_C(   511156811), -INT32_C(  1938819462), -INT32_C(  1682108703), -INT32_C(  1992759617), -INT32_C(  1543944496),
         INT32_C(  1901323896), -INT32_C(   809973698), -INT32_C(   743437344), -INT32_C(  1100489392), -INT32_C(   775119398),  INT32_C(   392075502), -INT32_C(  1822463094), -INT32_C(  1446123636) } },
    { { -INT32_C(  1891676286), -INT32_C(  1841226010),  INT32_C(  1540983227), -INT32_C(  1986737150),  INT32_C(   397242270),  INT32_C(   823916557), -INT32_C(  1551338568),  INT32_C(  1077412441),
         INT32_C(  1885334403), -INT32_C(  1567613993), -INT32_C(  1973232663),  INT32_C(  1561190391),  INT32_C(   194947553),  INT32_C(   332812599),  INT32_C(  1009120275),  INT32_C(  1926064119) },
      { -INT32_C(  1175618672), -INT32_C(  1361499621),  INT32_C(  2080692609),  INT32_C(    36764393), -INT32_C(   844078996),  INT32_C(    35128981), -INT32_C(  1577126054), -INT32_C(  1409287093),
         INT32_C(  1241153522),  INT32_C(  1667693632), -INT32_C(  2140278031), -INT32_C(   250677594),  INT32_C(   771501117),  INT32_C(  1049317354), -INT32_C(   683384889),  INT32_C(  1735623030) },
      {  INT32_C(   919745554),  INT32_C(  1016607997),  INT32_C(   668815418), -INT32_C(  1952172309), -INT32_C(   635629582),  INT32_C(   855899800),  INT32_C(    41321698), -INT32_C(   339214830),
         INT32_C(   967152753), -INT32_C(  1040783465),  INT32_C(   168765720), -INT32_C(  1409078959),  INT32_C(   643991004),  INT32_C(   761077469), -INT32_C(   345920556),  INT32_C(   364832385) } },
    { { -INT32_C(  1727546569), -INT32_C(  2058639326),  INT32_C(  1338749765),  INT32_C(   373465026), -INT32_C(   671124678), -INT32_C(  1919302723), -INT32_C(  1233004256), -INT32_C(  1559179697),
        -INT32_C(   107798480), -INT32_C(   385456720), -INT32_C(   898044456), -INT32_C(  1625696711), -INT32_C(   376937145), -INT32_C(  1132367764),  INT32_C(   902481945),  INT32_C(   792056806) },
      { -INT32_C(  1841227009),  INT32_C(  1539669343), -INT32_C(   709735776),  INT32_C(  1652239698), -INT32_C(  1711680384), -INT32_C(  1429694270),  INT32_C(   525789643),  INT32_C(  1259471626),
         INT32_C(  1193841178),  INT32_C(   812285822),  INT32_C(   876026405),  INT32_C(   332646634), -INT32_C(  1055303881),  INT32_C(  1713064637), -INT32_C(  1819389369),  INT32_C(   379883641) },
      {  INT32_C(   189178312), -INT32_C(   561064579), -INT32_C(  1703282203),  INT32_C(  1949938320),  INT32_C(  1309059002),  INT32_C(   659643263), -INT32_C(  1445515029), -INT32_C(   402469563),
        -INT32_C(  1094995414), -INT32_C(   647226674), -INT32_C(    28313603), -INT32_C(  1932910893),  INT32_C(   680604272), -INT32_C(   627426607), -INT32_C(  1505453474),  INT32_C(   965821343) } },
    { { -INT32_C(   349030303),  INT32_C(  1785046111), -INT32_C(  1042757457),  INT32_C(  1737927527),  INT32_C(  1161594549),  INT32_C(  1160192042), -INT32_C(   184434809), -INT32_C(  1720055340),
        -INT32_C(   339521427), -INT32_C(  1970209792), -INT32_C(  1248287430), -INT32_C(   360789525),  INT32_C(  1913349951),  INT32_C(   360975298),  INT32_C(  1185309231),  INT32_C(  1025588088) },
      { -INT32_C(   388091286),  INT32_C(  1475451470), -INT32_C(   582153313), -INT32_C(  1991214562), -INT32_C(  1091731760), -INT32_C(   868334684), -INT32_C(  1166550823), -INT32_C(   734386821),
        -INT32_C(   499790847), -INT32_C(  1911490173),  INT32_C(   998569952),  INT32_C(  1668173516),  INT32_C(   240093475),  INT32_C(  1396415836),  INT32_C(  1050460006), -INT32_C(  1184904202) },
      {  INT32_C(    65800715),  INT32_C(  1033125393),  INT32_C(   479576880), -INT32_C(   288960135), -INT32_C(    70125467), -INT32_C(  1994824818),  INT32_C(  1333159774),  INT32_C(  1296051375),
         INT32_C(   167156844),  INT32_C(    75498883), -INT32_C(  1910746406), -INT32_C(  1995405529),  INT32_C(  2084892188),  INT32_C(  1186961054),  INT32_C(  2017123657), -INT32_C(  2072055666) } },
    { {  INT32_C(  1950700306), -INT32_C(   237283605), -INT32_C(  1190591724),  INT32_C(     2981687), -INT32_C(   576818779), -INT32_C(    20979385),  INT32_C(   750065778), -INT32_C(   830997516),
        -INT32_C(   852723094),  INT32_C(  1566901338),  INT32_C(   353305803),  INT32_C(     6679193),  INT32_C(  1342823370), -INT32_C(  1377161447),  INT32_C(  1791982968),  INT32_C(   243243187) },
      { -INT32_C(   928073445), -INT32_C(    35749180), -INT32_C(   356403761), -INT32_C(   863827258),  INT32_C(   822300177),  INT32_C(  1598338091), -INT32_C(  1771112626),  INT32_C(   117434161),
         INT32_C(   676273718),  INT32_C(   693777629),  INT32_C(   320965188),  INT32_C(  1812143731), -INT32_C(  1549201693), -INT32_C(  1144932349), -INT32_C(  2083228063),  INT32_C(  1723727495) },
      { -INT32_C(  1125389815),  INT32_C(   201708591),  INT32_C(  1405662939), -INT32_C(   860981775), -INT32_C(   325238860), -INT32_C(  1577364116), -INT32_C(  1159991492), -INT32_C(   930603835),
        -INT32_C(   446471076),  INT32_C(  1950298247),  INT32_C(   103714447),  INT32_C(  1818686698), -INT32_C(   207563479),  INT32_C(   371955482), -INT32_C(   384103655),  INT32_C(  1757570612) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_castps_si512(simde_mm512_xor_ps(simde_mm512_castsi512_ps(a), simde_mm512_castsi512_ps(b)));
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_xor_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 8917272025905183984), -INT64_C( 8866677502414823733),  INT64_C( 1464795012987523672),  INT64_C( 9076492970404562796),
        -INT64_C(  471420776636169871),  INT64_C( 3961263463326435322), -INT64_C( 4926361178749313089),  INT64_C( 6187424904041771752) },
      { -INT64_C( 6187074978812186357),  INT64_C( 9129308580762170105),  INT64_C( 6737626754639454484),  INT64_C( 8553348640616316182),
        -INT64_C( 7747167415395374764),  INT64_C( 2270104474263871152),  INT64_C( 8997904634902970919), -INT64_C( 1284389140319940514) },
      {  INT64_C( 3322640854544675355), -INT64_C(  413510917362488270),  INT64_C( 5319635821359362892),  INT64_C(  812256522989615738),
         INT64_C( 7856992465972914213),  INT64_C( 2988204169892698442), -INT64_C( 4072109430317720168), -INT64_C( 4903636269142318410) } },
    { { -INT64_C( 6505531527298525732),  INT64_C( 9073156322736741803),  INT64_C( 3499178133975168607),  INT64_C( 8184285759661098913),
         INT64_C( 3319482116807104653),  INT64_C( 6307874133959206792), -INT64_C( 1590393193835026219),  INT64_C( 3334991353612573190) },
      { -INT64_C(  189158219624270114),  INT64_C( 4609744475273820848),  INT64_C( 3508270164975553796), -INT64_C( 7960726155283276816),
         INT64_C( 2082343515212321040),  INT64_C( 4039683120892358364), -INT64_C( 7716078895957568331),  INT64_C( 8874843879011272792) },
      {  INT64_C( 6406454113495114498),  INT64_C( 4761230285051520795),  INT64_C(    9133478509509467), -INT64_C( 2300849903224578991),
         INT64_C( 3671791598235879837),  INT64_C( 8036045162057386324),  INT64_C( 9009225591048387680),  INT64_C( 6152343202689438302) } },
    { {  INT64_C( 1660001668875280251), -INT64_C( 6688666841194484293),  INT64_C(  866481487179763680), -INT64_C( 6014321076695304337),
        -INT64_C( 4943803188177761355),  INT64_C( 8602557963703392155),  INT64_C( 2348766465129802213), -INT64_C( 4226418528419391895) },
      { -INT64_C(  276208556333754517), -INT64_C( 8793904538853466362), -INT64_C( 1578788849987643064), -INT64_C( 1646247322702001477),
         INT64_C( 2188768063495513738),  INT64_C( 7993857117939491420), -INT64_C( 8683858962037236194),  INT64_C( 8744573975962379253) },
      { -INT64_C( 1503296891938387952),  INT64_C( 2799218735084909245), -INT64_C( 1868607137191635288),  INT64_C( 5021386112833600980),
        -INT64_C( 6556108815733478081),  INT64_C( 1841284304668030407), -INT64_C( 6348735240143046661), -INT64_C( 4899273116385921636) } },
    { { -INT64_C( 7645977387302788113), -INT64_C( 3352234231512672247),  INT64_C( 7099980801611090558),  INT64_C( 2943395267179314445),
        -INT64_C( 4607844101183449547), -INT64_C( 8977088685291950508),  INT64_C(  143793199971752471),  INT64_C( 1279544180712774249) },
      {  INT64_C( 5042683055231339073),  INT64_C(  106425879644314133), -INT64_C( 7957364987157442167),  INT64_C( 2375707624005304798),
         INT64_C( 1229740195508336126), -INT64_C( 4558434066425528247), -INT64_C( 6013628711494954681),  INT64_C(  863595646972066585) },
      { -INT64_C( 3449971071047439954), -INT64_C( 3458657327579413988), -INT64_C(  929447554171085833),  INT64_C(  585818806074473683),
        -INT64_C( 3378460560296254517),  INT64_C( 4888597167206592029), -INT64_C( 5947680971553895600),  INT64_C( 1890879682201149808) } },
    { {  INT64_C(   19342552227360650),  INT64_C( 9015339881571254999),  INT64_C( 2111175543395945328),  INT64_C( 1063893217915658645),
         INT64_C( 5113671542448273537),  INT64_C(  294076048327577819),  INT64_C( 4136299984689877214),  INT64_C( 6998346057415234657) },
      { -INT64_C( 5822897953418392471), -INT64_C( 2652605089542910307), -INT64_C( 6710896084442025600),  INT64_C(  482490459503952710),
        -INT64_C( 4249188140389718191),  INT64_C( 3686292135995040188), -INT64_C( 7820050545947625371), -INT64_C( 4155849880699296371) },
      { -INT64_C( 5803909723175885853), -INT64_C( 6472545252534039478), -INT64_C( 4642510373644240144),  INT64_C(  608429854075970259),
        -INT64_C( 8939450874709434416),  INT64_C( 3980218559741096295), -INT64_C( 6188350928172226373), -INT64_C( 6391617066844278292) } },
    { {  INT64_C( 6004850654787511453),  INT64_C( 5940721718117239162),  INT64_C( 8299177194198841098),  INT64_C( 8739678760146743174),
        -INT64_C(   33468914264828954),  INT64_C( 4810661481483717294), -INT64_C( 6371855048832433144),  INT64_C( 2475934475524100073) },
      {  INT64_C( 6400425042904156857),  INT64_C( 7634775463157369383), -INT64_C( 8012522724089233327),  INT64_C( 3036153849740553193),
        -INT64_C( 1737102447742047799), -INT64_C( 2861167923869488012),  INT64_C(  265573619744849241),  INT64_C( 8622106189528170193) },
      {  INT64_C(  830741991547514404),  INT64_C( 4288980697190663005), -INT64_C( 2026245280167086245),  INT64_C( 6010905068804162671),
         INT64_C( 1760215543021156911), -INT64_C( 7311046646325205286), -INT64_C( 6612095300032300719),  INT64_C( 6195711379304100152) } },
    { { -INT64_C(   64316270072716246),  INT64_C( 1935443446427172380), -INT64_C( 1091493333936354380), -INT64_C( 6895415197380722231),
        -INT64_C( 1805936298755591266),  INT64_C( 8997027290326566875), -INT64_C( 7447454384865349272),  INT64_C( 6845659238006585079) },
      { -INT64_C( 3918924663269530680), -INT64_C( 5736519009328467646),  INT64_C( 3896138832546275085),  INT64_C(  114649980956301072),
        -INT64_C( 3878013855955832913), -INT64_C( 8817041431659451413), -INT64_C( 3144109803129131596), -INT64_C( 3898751961541556299) },
      {  INT64_C( 3929019560870856674), -INT64_C( 6142951854191587490), -INT64_C( 4121953400583433031), -INT64_C( 6784178172063836455),
         INT64_C( 3233162805184420913), -INT64_C(  470539099348898768),  INT64_C( 5546380282716151004), -INT64_C( 7573801740836425406) } },
    { {  INT64_C( 4005776973137074199),  INT64_C( 7761109657262433250), -INT64_C( 4087271545684412689),  INT64_C( 8176212645445862943),
         INT64_C( 1663312718869912950), -INT64_C( 5987727983636667819), -INT64_C( 2064163572997672891),  INT64_C( 4576071772732176903) },
      {  INT64_C( 3480407709618747496),  INT64_C( 2300011067054476999),  INT64_C( 2573836082898378693), -INT64_C( 8237295633617103203),
         INT64_C( 8697230954808831974), -INT64_C( 7715133602037231102),  INT64_C( 1008851380274702642), -INT64_C( 7795902896402923754) },
      {  INT64_C(  566192077266575487),  INT64_C( 8385218711665306917), -INT64_C( 1945833864310642390), -INT64_C(  227289569249472382),
         INT64_C( 8045543724174291600),  INT64_C( 4037767070791741527), -INT64_C( 1343560506274506377), -INT64_C( 6030853617239309039) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_castpd_si512(simde_mm512_xor_pd(simde_mm512_castsi512_pd(a), simde_mm512_castsi512_pd(b)));
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_and_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_andnot_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_andnot_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_andnot_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_andnot_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_andnot_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_andnot_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_broadcast_f32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_broadcast_f32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_broadcast_f32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_broadcast_f32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_broadcast_f32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_broadcast_f32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_broadcast_f32x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_broadcast_f32x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_broadcast_f32x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_broadcast_f64x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_broadcast_f64x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_broadcast_f64x2)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_or_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_or_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_xor_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_xor_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
