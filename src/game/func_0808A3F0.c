#include "types.h"

extern u8 D_020310A2;
extern u8 D_08759BF4[];
extern u8 D_08741E44[];
extern u16 D_02030F92[];
extern u32 D_02028888[];
extern u8 D_02020E4C[];
extern u8 D_08735100[];
extern u8 D_0873FCC8[];

void func_0808A3F0(u32 arg0)
{
    volatile union {
        u32 word;
        u16 half;
    } saved;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 work3 asm("r3");
    register u32 prior asm("r4");
    register u32 upper asm("r8");
    register u8 *data asm("r9");
    register u8 *countAddress asm("r10");
    register u32 one asm("r12");
    register u32 previous asm("r12");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u32 filter asm("r4") = arg0;
    u8 *initialCount;
    register u32 mask asm("r6");
    u32 item;
    register u32 compare asm("r5");
    register u32 key asm("r6");
    u16 before;
    /* The partial pair write keeps r2 unavailable for the first signed load. */
    register union {
        unsigned long long whole;
        struct {
            u32 low, high;
        } part;
    } pair asm("r1");

    pointer1 = &D_020310A2;
    current = 0;
    asm("" : "=r"(initialCount) : "0"(pointer1));
    *initialCount = current;
    work2 = 0;
    countAddress = initialCount;
    current = 1;
    one = current;
    asm("" : "+r"(one));
    pointer1 = D_08759BF4;
    asm("" : "+r"(pointer1));
    data = pointer1;
    mask = 2;
    mask &= filter;
collect_loop:
    current = work2 << 16;
    work1 = current >> 16;
    pointer2 = D_08741E44;
    asm("" : "+r"(pointer2));
    pointer1 = (u8 *)(work1 + (u32)pointer2);
    item = *pointer1;
    work1 = filter;
    asm("" : "+r"(work1));
    work3 = one;
    asm("" : "+r"(work3));
    work1 &= work3;
    upper = current;
    if (work1 != 0) {
        current = item << 3;
        current += (u32)data;
        current = *(u8 *)(current + 2);
        if ((u32)current <= 199)
            goto next_item;
    }
    work1 = item << 16;
    asm("" : "+r"(work1));
    if (mask != 0) {
        current = work1 >> 13;
        current += (u32)data;
        current = *(u8 *)(current + 2);
        if ((u32)current > 199)
            goto next_item;
    }
    pointer3 = (u8 *)D_02030F92;
    pointer2 = countAddress;
    current = *pointer2;
    current <<= 1;
    current += (u32)pointer3;
    compare = 0;
    asm volatile("" : : "r"(compare));
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(current));
        *address = item;
    }
    work1 >>= 16;
    current = work1;
    if (work1 < 0)
        current += 31;
    current >>= 5;
    work2 = current << 2;
    item = (u32)D_02028888;
    asm("" : "+r"(item));
    work2 += item;
    current <<= 5;
    current = work1 - current;
    current = (s16)current;
    work1 = one;
    work1 <<= current;
    current = *(u32 *)work2;
    current &= work1;
    if (current == 0) {
        current = 4;
        current &= filter;
        if (current != 0)
            goto next_item;
        pointer1 = countAddress;
        current = *pointer1;
        current <<= 1;
        current += (u32)pointer3;
        work1 = *(u16 *)current;
        work3 = 0x8000;
        asm("" : "+r"(work3));
        work2 = work3;
        asm("" : "+r"(work2));
        work1 |= work2;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(current));
            *address = work1;
        }
    }
    item = (u32)countAddress;
    asm("" : "+r"(item));
    current = *(u8 *)item;
    current++;
    *(u8 *)item = current;
next_item:
    current = 0x10000;
    asm("" : "+r"(current));
    current += upper;
    work2 = (u32)current >> 16;
    current >>= 16;
    if (current <= 135)
        goto collect_loop;
    work2 = 1;
    pointer0 = countAddress;
    current = *pointer0;
    if ((s32)work2 >= current)
        return;
sort_loop:
    pointer3 = (u8 *)D_02030F92;
    work2 <<= 16;
    work1 = (s32)work2 >> 16;
    current = work1 << 1;
    current += (u32)pointer3;
    current = *(u16 *)current;
    saved.word = current;
    key = 0x7FFF;
    asm("" : "+r"(key));
    key &= current;
    work1--;
    before = (u16)work1;
    current = (u32)before << 16;
    upper = work2;
    data = pointer3;
    if (current < 0)
        goto insert;
compare_loop:
    current >>= 15;
    current += (u32)data;
    current = *(u16 *)current;
    previous = current;
    prior = 0x7FFF;
    asm("" : "+r"(prior));
    prior &= current;
    compare = 0;
    pointer1 = D_02020E4C;
    work2 = 0x7B47;
    asm("" : "+r"(work2));
    pointer0 = pointer1 + work2;
    current = *pointer0;
    switch (current) {
    case 0:
        pointer0 = D_08735100;
        pointer1 = (u8 *)(key + (u32)pointer0);
        pointer0 = (u8 *)(prior + (u32)pointer0);
        work1 = *pointer1;
        current = *pointer0;
        if ((u32)work1 < (u32)current) {
            asm volatile("" : : "r"(work1));
            goto ordered;
        }
        break;
    case 1:
        pointer2 = D_0873FCC8;
        work1 = 52;
        current = key;
        current *= work1;
        pointer3 = (u8 *)(current + (u32)pointer2);
        current = prior;
        current *= work1;
        pointer2 = (u8 *)(current + (u32)pointer2);
        work1 = *pointer3;
        current = *pointer2;
        if (work1 != current)
            goto compare_primary;
        current = pointer3[1];
        work2 = pointer2[1];
        if ((u32)current < work2) {
            asm volatile("" : : "r"(work2));
            goto ordered;
        }
        break;
    compare_primary:
        if ((u32)work1 >= (u32)current)
            goto primary_done;
        goto ordered;
    case 2:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(u8 *)(work1 + 2);
        current = *(u8 *)(current + 2);
        if ((u32)work1 >= (u32)current)
            goto compare_done;
        goto ordered;
    case 3:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        pair.part.low = *(s16 *)(work1 + 4);
        work1 = pair.part.low;
        current = *(s16 *)(current + 4);
        goto compare_signed;
    case 4:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(s16 *)(work1 + 6);
        current = *(s16 *)(current + 6);
        goto compare_signed;
    case 5:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(s16 *)(work1 + 8);
        current = *(s16 *)(current + 8);
        goto compare_signed;
    case 6:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(s16 *)(work1 + 10);
        current = *(s16 *)(current + 10);
        goto compare_signed;
    case 7:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(s16 *)(work1 + 12);
        current = *(s16 *)(current + 12);
        goto compare_signed;
    case 8:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(s16 *)(work1 + 14);
        current = *(s16 *)(current + 14);
        goto compare_signed;
    case 9:
        pointer2 = D_0873FCC8;
        current = 52;
        work1 = key;
        work1 *= current;
        work1 += (u32)pointer2;
        current *= prior;
        current += (u32)pointer2;
        work1 = *(s16 *)(work1 + 16);
        current = *(s16 *)(current + 16);
    compare_signed:
        if (work1 > current)
            goto ordered;
        break;
    ordered:
        compare = 1;
        break;
    }
primary_done:
    asm volatile("" : : "r"(work1));
compare_done:
    pointer3 = D_02020E4C;
    work1 = 0x7B48;
    asm("" : "+r"(work1));
    pointer0 = pointer3 + work1;
    current = *pointer0;
    if (current == compare)
        goto insert;
    work1 = (s16)before;
    current = work1 + 1;
    current <<= 1;
    current += (u32)data;
    work2 = previous;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(current));
        *address = work2;
    }
    work1--;
    before = (u16)work1;
    current = (u32)before << 16;
    if (current >= 0)
        goto compare_loop;
insert:
    current = (u32)before << 16;
    current >>= 15;
    current += 2;
    current += (u32)data;
    pointer3 = (u8 *)&saved;
    asm("" : "+r"(pointer3));
    work3 = *(u16 *)pointer3;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(current));
        *address = work3;
    }
    current = 0x10000;
    asm("" : "+r"(current));
    current += upper;
    work2 = (u32)current >> 16;
    current >>= 16;
    item = (u32)countAddress;
    asm("" : "+r"(item));
    item = *(u8 *)item;
    if (current < (s32)item)
        goto sort_loop;
}
