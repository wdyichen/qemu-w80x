/*
 * Copyright (c) 2021 C-SKY Microsystems Co., Ltd. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License  *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "testsuite.h"
#include "rvv_insn.h"

struct rvv_reg src0[] =
{
    {
        .fixs8 =
        {
            {
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
            },
        },
    },
};

struct rvv_reg src1[] =
{
    {
        .fixs8 =
        {
            {
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
            },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs16 = {
            {
              0x0808, 0x0808, 0x0808, 0x0808,
              0xf0f0, 0xf0f0, 0xf0f0, 0xf0f0,
            }, {
              0x0808, 0x0808, 0x0808, 0x0808,
              0xf0f0, 0xf0f0, 0xf0f0, 0x1111,
            },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {
              0x0808, 0x1111, 0x0808, 0x1111,
              0xf0f0, 0x1111, 0xf0f0, 0x1111,
            }, {
              0x0808, 0x1111, 0x0808, 0x1111,
              0xf0f0, 0x1111, 0xf0f0, 0x1111,
            },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {
              0x1111, 0x0808, 0x1111, 0x0808,
              0x1111, 0xf0f0, 0x1111, 0xf0f0,
            }, {
              0x1111, 0x0808, 0x1111, 0x0808,
              0x1111, 0xf0f0, 0x1111, 0xf0f0,
            },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    init_testsuite("Testing insn vpwadd.vv\n");

    /* vpwadd.vv */
    test_vpwadd_vv(src0[0].fixs8[0], src1[0].fixs8[0], res.fixs16[0], &vma8, pad.fixs16[0]);
    result_compare_s16(res.fixs16[0], dst_vl[0].fixs16[0]);
    result_compare_s16(res.fixs16[1], dst_vl[0].fixs16[1]);

    test_vpwadd_vv(src0[0].fixs8[0], src1[0].fixs8[0], res.fixs16[0], &vme8, pad.fixs16[0]);
    result_compare_s16(res.fixs16[0], dst_even[0].fixs16[0]);
    result_compare_s16(res.fixs16[1], dst_even[0].fixs16[1]);

    test_vpwadd_vv(src0[0].fixs8[0], src1[0].fixs8[0], res.fixs16[0], &vmo8, pad.fixs16[0]);
    result_compare_s16(res.fixs16[0], dst_odd[0].fixs16[0]);
    result_compare_s16(res.fixs16[1], dst_odd[0].fixs16[1]);

    return done_testing();
}
