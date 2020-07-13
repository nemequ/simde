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
 */

#if !defined(SIMDE_ARM_NEON_H)
#define SIMDE_ARM_NEON_H

#include "neon/types.h"

#include "neon/abs.h"
#include "neon/add.h"
#include "neon/addl.h"
#include "neon/addw.h"
#include "neon/and.h"
#include "neon/bsl.h"
#include "neon/cagt.h"
#include "neon/ceq.h"
#include "neon/ceqz.h"
#include "neon/cge.h"
#include "neon/cgez.h"
#include "neon/cgt.h"
#include "neon/cgtz.h"
#include "neon/cle.h"
#include "neon/clez.h"
#include "neon/clt.h"
#include "neon/cltz.h"
#include "neon/combine.h"
#include "neon/dup_n.h"
#include "neon/eor.h"
#include "neon/get_high.h"
#include "neon/get_lane.h"
#include "neon/get_low.h"
#include "neon/ld1.h"
#include "neon/max.h"
#include "neon/min.h"
#include "neon/mla.h"
#include "neon/mlal.h"
#include "neon/mlal_high.h"
#include "neon/movl.h"
#include "neon/movl_high.h"
#include "neon/movn.h"
#include "neon/mul.h"
#include "neon/mull.h"
#include "neon/mvn.h"
#include "neon/neg.h"
#include "neon/orr.h"
#include "neon/padal.h"
#include "neon/padd.h"
#include "neon/paddl.h"
#include "neon/pmax.h"
#include "neon/pmin.h"
#include "neon/qadd.h"
#include "neon/qmovn.h"
#include "neon/qmovn_high.h"
#include "neon/qshl.h"
#include "neon/reinterpret.h"
#include "neon/rshr_n.h"
#include "neon/rsra_n.h"
#include "neon/shl.h"
#include "neon/shl_n.h"
#include "neon/shr_n.h"
#include "neon/sra_n.h"
#include "neon/st1.h"
#include "neon/st1_lane.h"
#include "neon/sub.h"
#include "neon/trn.h"
#include "neon/trn1.h"
#include "neon/trn2.h"
#include "neon/tst.h"
#include "neon/uzp.h"
#include "neon/uzp1.h"
#include "neon/uzp2.h"
#include "neon/zip.h"
#include "neon/zip1.h"
#include "neon/zip2.h"

#endif /* SIMDE_ARM_NEON_H */
