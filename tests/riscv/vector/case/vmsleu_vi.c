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

struct rvv_reg src0[] = {
    {
        .fixu64 = {
            {0x3970b5993ab1f212, 0x000000000000000f, },
            {0x3970b5993ab1f212, 0xfffffffffffffff0, },
        },
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0x000f, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xfff0, },
        },
        .fixu16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0x000f, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xfff0, },
        },
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x0f, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0xf0, },
        },
    },
};
struct rvv_reg dst_vl[] = {
    {
        .fixu8 = {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
            {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        },
        .fixu16 = {
            {0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, },
            {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        },
        .fixu32 = {
            {0x00000000, 0x00010000, 0x00000000, 0x00000000, },
            {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        },
        .fixu64 = {
            {0x0000000100000000, 0x0000000000000000, },
            {0x1111111111111111, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu8 = {
            {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, },
            {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        },
        .fixu16 = {
            {0x1100, 0x1100, 0x1100, 0x1100, 0x1100, 0x1100, 0x1100, 0x1100, },
            {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        },
        .fixu32 = {
            {0x11110000, 0x11110000, 0x11110000, 0x11110000, },
            {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        },
        .fixu64 = {
            {0x1111111100000000, 0x1111111100000000, },
            {0x1111111111111111, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu8 = {
            {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, },
            {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        },
        .fixu16 = {
            {0x0011, 0x0011, 0x0011, 0x0111, 0x0011, 0x0011, 0x0011, 0x0011, },
            {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        },
        .fixu32 = {
            {0x00001111, 0x00011111, 0x00001111, 0x00001111, },
            {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        },
        .fixu64 = {
            {0x0000000111111111, 0x0000000011111111, },
            {0x1111111111111111, 0x1111111111111111, },
        },
    },
};

struct rvv_reg res;
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmsleu.vi\n");

    /* int8_t vmsleu */
    test_vmsleu_vi_8(vlmax_8 - 1, src0[i].fixu8[0], res.fixu8[0], vma.fixu8, pad.fixu8[0]);
    result_compare_u8_lmul(res.fixu8[0], dst_vl[i].fixu8[0]);

    test_vmsleu_vi_8_vm(src0[i].fixu8[0], res.fixu8[0], vme.fixu8, pad.fixu8[0]);
    result_compare_u8_lmul(res.fixu8[0], dst_even[i].fixu8[0]);

    test_vmsleu_vi_8_vm(src0[i].fixu8[0], res.fixu8[0], vmo.fixu8, pad.fixu8[0]);
    result_compare_u8_lmul(res.fixu8[0], dst_odd[i].fixu8[0]);

    /* int16_t vmsleu */
    test_vmsleu_vi_16(vlmax_16 - 1, src0[i].fixu16[0], res.fixu16[0], vma.fixu16, pad.fixu16[0]);
    result_compare_u16_lmul(res.fixu16[0], dst_vl[i].fixu16[0]);

    test_vmsleu_vi_16_vm(src0[i].fixu16[0], res.fixu16[0], vme.fixu16, pad.fixu16[0]);
    result_compare_u16_lmul(res.fixu16[0], dst_even[i].fixu16[0]);

    test_vmsleu_vi_16_vm(src0[i].fixu16[0], res.fixu16[0], vmo.fixu16, pad.fixu16[0]);
    result_compare_u16_lmul(res.fixu16[0], dst_odd[i].fixu16[0]);

    /* int32_t vmsleu */
    test_vmsleu_vi_32(vlmax_32 - 1, src0[i].fixu32[0], res.fixu32[0], vma.fixu32, pad.fixu32[0]);
    result_compare_u32_lmul(res.fixu32[0], dst_vl[i].fixu32[0]);

    test_vmsleu_vi_32_vm(src0[i].fixu32[0], res.fixu32[0], vme.fixu32, pad.fixu32[0]);
    result_compare_u32_lmul(res.fixu32[0], dst_even[i].fixu32[0]);

    test_vmsleu_vi_32_vm(src0[i].fixu32[0], res.fixu32[0], vmo.fixu32, pad.fixu32[0]);
    result_compare_u32_lmul(res.fixu32[0], dst_odd[i].fixu32[0]);

    /* int64_t vmsleu */
    test_vmsleu_vi_64(vlmax_64 - 1, src0[i].fixu64[0], res.fixu64[0], vma.fixu64, pad.fixu64[0]);
    result_compare_u64_lmul(res.fixu64[0], dst_vl[i].fixu64[0]);

    test_vmsleu_vi_64_vm(src0[i].fixu64[0], res.fixu64[0], vme.fixu64, pad.fixu64[0]);
    result_compare_u64_lmul(res.fixu64[0], dst_even[i].fixu64[0]);

    test_vmsleu_vi_64_vm(src0[i].fixu64[0], res.fixu64[0], vmo.fixu64, pad.fixu64[0]);
    result_compare_u64_lmul(res.fixu64[0], dst_odd[i].fixu64[0]);

    return done_testing();
}
