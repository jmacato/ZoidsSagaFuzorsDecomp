#include "types.h"

extern u8 D_02031A0C[];
extern u8 D_02031408[];
extern u8 D_02031C64[];
u32 func_0809A99C(u32, u32);
u32 func_0809B834(u32, u32, u32, void *);
void func_0809AC04(u32, u32, u32, s32);
void func_080C8B7C(const void *, void *, u32);

void func_0809AD80(void)
{
    u8 ids[4];
    u16 values[4];
    volatile u32 chance;
    volatile u32 savedId;
    volatile u32 side;
    volatile u32 member;
    volatile u32 repeats;
    volatile u32 nextMember;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    u8 *pointer7;
    register s32 index asm("r4");
    register s32 group asm("r6");
    register s32 offset asm("r5");
    register s32 highIndex asm("r7");
    register s32 previous asm("r6");
    register s32 count asm("r10");
    register u8 *data asm("r8");
    register u32 key asm("r9");
    register s32 signedKey asm("r12");
    register u32 nextSide asm("r12");
    register u8 *context asm("r9");
    register u8 *temporary asm("r10");
    register s32 boundary asm("r8");

    pointer1 = D_02031A0C;
    current = 0;
    pointer1[2] = current;
    side = current;
side_loop:
    work1 = 0;
    member = work1;
member_loop:
    current = side;
    work1 = member;
    current = func_0809A99C(current, work1);
    work2 = member;
    work2++;
    nextMember = work2;
    if (current == 0)
        goto next_member;
    current = side;
    work1 = member;
    work2 = 0x26;
    pointer3 = 0;
    current = func_0809B834(current, work1, work2, pointer3);
    current = (u8)current;
    if (current != 0xFF)
        goto next_member;
    current = side;
    work1 = member;
    work2 = 0x28;
    pointer3 = 0;
    current = func_0809B834(current, work1, work2, pointer3);
    current = (u8)current;
    if (current != 0xFF)
        goto next_member;
    work3 = 1;
    repeats = work3;
    pointer4 = D_02031408;
    current = side;
    work1 = member;
    work2 = 0x22;
    pointer3 = pointer4;
    current = func_0809B834(current, work1, work2, pointer3);
    current = (u8)current;
    if (current != 0xFF) {
        current = pointer4[6];
        current++;
        current = (u8)current;
        repeats = current;
    }
    index = side;
    current = index << 3;
    group = current - index;
    work2 = group << 5;
    work2 = group + work2;
    work2 <<= 3;
    work1 = member;
    current = work1 << 5;
    current += work1;
    current <<= 3;
    pointer3 = D_02031C64;
    current += (u32)pointer3;
    work2 += current;
    work1 = *(u8 *)work2;
    current = 0x94;
    current *= work1;
    work1 = 0x65C;
    work1 *= index;
    current += work1;
    pointer4 = D_02031A0C;
    current += (u32)pointer4;
    work1 = 0x1130;
    current += work1;
    current = *(u16 *)current;
    chance = current;
    work3 = 0;
    count = work3;
    index = 0;
    pointer3 = (u8 *)work2 + 1;
    current = *(u8 *)(work2 + 1);
    if (current == 0xFF)
        goto sort;
    pointer7 = (u8 *)values;
    pointer0 = D_02031A0C;
    data = pointer0;
    offset = group << 6;
    pointer6 = pointer3;
collect:
    pointer2 = ids;
    pointer2 += count;
    work1 = (s8)index;
    pointer3 = pointer6 + work1;
    current = *pointer3;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    index = count;
    work2 = index << 1;
    work2 = (u32)pointer7 + work2;
    current = *pointer3;
    current <<= 6;
    current += offset;
    current += (u32)data;
    work3 = 0x1DB6;
    current += work3;
    current = *(u16 *)current;
    *(u16 *)work2 = current;
    current = count;
    current++;
    current = (u8)current;
    count = current;
    work1++;
    work1 <<= 24;
    index = (u32)work1 >> 24;
    current = work1 >> 24;
    if (current > 3)
        goto sort;
    pointer0 = pointer6 + current;
    current = *pointer0;
    if (current != 0xFF)
        goto collect;
sort:
    index = 1;
    if (index >= count)
        goto apply;
    pointer5 = (u8 *)values;
sort_loop:
    work2 = index << 24;
    work1 = work2 >> 24;
    pointer4 = ids;
    pointer0 = pointer4 + work1;
    current = *pointer0;
    savedId = current;
    current = work1 << 1;
    current = (u32)pointer5 + current;
    current = *(u16 *)current;
    key = current;
    work1--;
    previous = (u8)work1;
    work1 = previous << 24;
    highIndex = work2;
    if (work1 < 0)
        goto insert;
    data = pointer5;
    current = (s16)current;
    signedKey = current;
sort_compare:
    work3 = work1 >> 24;
    current = work3 << 1;
    pointer1 = data;
    pointer4 = pointer1 + current;
    current = *(s16 *)pointer4;
    if (signedKey <= current)
        goto insert;
    work1 = work3 + 1;
    pointer6 = ids;
    pointer2 = pointer6 + work1;
    pointer0 = pointer6 + work3;
    current = *pointer0;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    work1 <<= 1;
    work1 = (u32)pointer5 + work1;
    current = *(u16 *)pointer4;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(work1));
        *address = current;
    }
    current = work3 - 1;
    previous = (u8)current;
    work1 = previous << 24;
    if (work1 >= 0)
        goto sort_compare;
insert:
    current = (s8)previous;
    current++;
    pointer2 = ids;
    asm("" : "+r"(pointer2));
    pointer1 = pointer2 + current;
    work3 = pointer2[16];
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = work3;
    }
    current <<= 1;
    current = (u32)pointer5 + current;
    index = key;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(current));
        *address = index;
    }
    previous = 0x1000000;
    asm("" : "+r"(previous));
    current = highIndex + previous;
    index = (u32)current >> 24;
    current >>= 24;
    if (current < count)
        goto sort_loop;
apply:
    index = 0;
    if (index >= count)
        goto next_member;
apply_next:
    previous = 0;
    highIndex = index << 24;
    goto repeat_check;
apply_repeat:
    current = highIndex >> 24;
    current += (u32)ids;
    work2 = *(u8 *)current;
    current = chance;
    offset = current << 16;
    index = offset >> 16;
    current = side;
    work1 = member;
    work3 = index;
    func_0809AC04(current, work1, work2, work3);
    offset = (u32)offset >> 31;
    index += offset;
    index <<= 15;
    index = (u32)index >> 16;
    chance = index;
    current = previous << 24;
    work1 = 0x1000000;
    asm("" : "+r"(work1));
    current += work1;
    previous = (u32)current >> 24;
repeat_check:
    current = (s8)previous;
    if (highIndex != 0)
        goto once;
    work2 = repeats;
    if (current < work2)
        goto apply_repeat;
    goto next_apply;
once:
    if (current <= 0)
        goto apply_repeat;
next_apply:
    work3 = 0x1000000;
    asm("" : "+r"(work3));
    current = highIndex + work3;
    index = (u32)current >> 24;
    current >>= 24;
    if (current < count)
        goto apply_next;
next_member:
    index = nextMember;
    current = (u8)index;
    member = current;
    if ((u32)current <= 5)
        goto member_loop;
    current = side;
    current++;
    current = (u8)current;
    side = current;
    if ((u32)current <= 1)
        goto side_loop;
    previous = 0;
    side = previous;
order_side:
    current = side;
    if (current == 0) {
        pointer1 = D_02031A0C;
        work1 = pointer1[1];
    } else {
        work1 = 0;
        pointer2 = D_02031A0C;
        current = pointer2[1];
        if (current == 0)
            work1 = 1;
    }
    savedId = work1;
    pointer3 = D_02031A0C;
    index = 0x4E6F;
    pointer0 = pointer3 + index;
    previous = savedId;
    pointer0 = (u8 *)(previous + (u32)pointer0);
    current = *pointer0;
    if (current == 0x38)
        goto order_small;
    if (current > 0x38)
        goto order_high;
    if (current == 0x22)
        goto reverse;
    if (current == 0x23)
        goto lookup;
    current = side;
    current++;
    nextSide = current;
    goto ordered;
order_high:
    if (current == 0x39)
        goto order_large;
    work1 = side;
    work1++;
    nextSide = work1;
    goto ordered;
reverse:
    index = 0;
    pointer2 = D_02031A0C;
    current = pointer2[2];
    current = (u32)current >> 1;
    work3 = side;
    work3++;
    nextSide = work3;
    if (index >= current)
        goto ordered;
    pointer5 = pointer2;
    current = 0x124;
    pointer6 = pointer2 + current;
reverse_loop:
    work2 = ~index;
    work1 = pointer5[2];
    work2 += work1;
    work3 = (s8)index;
    index = work3 << 3;
    index += (u32)pointer5;
    current = *(u32 *)(index + 4);
    work1 = *(u32 *)(index + 8);
    *(u32 *)pointer6 = current;
    *(u32 *)(pointer6 + 4) = work1;
    work2 <<= 24;
    work2 >>= 21;
    work2 += (u32)pointer5;
    current = *(u32 *)(work2 + 4);
    work1 = *(u32 *)(work2 + 8);
    *(u32 *)(index + 4) = current;
    *(u32 *)(index + 8) = work1;
    current = *(u32 *)pointer6;
    work1 = *(u32 *)(pointer6 + 4);
    *(u32 *)(work2 + 4) = current;
    *(u32 *)(work2 + 8) = work1;
    work3++;
    work3 <<= 24;
    index = (u32)work3 >> 24;
    work3 >>= 24;
    current = pointer5[2];
    current = (u32)current >> 1;
    if (work3 < current)
        goto reverse_loop;
    goto ordered;
lookup:
    pointer0 = D_02031A0C;
    pointer0 += 4;
    pointer2 = D_02031A0C;
    work3 = 0x124;
    pointer1 = pointer2 + work3;
    work2 = 0x04000048;
    func_080C8B7C(pointer0, pointer1, work2);
    index = 0;
    previous = 0;
    current = side;
    current++;
    nextSide = current;
    work1 = savedId;
    current = work1 << 3;
    pointer5 = D_02031A0C;
    current += work1;
    highIndex = current << 2;
    pointer2 = pointer5;
    asm("" : "+r"(pointer2));
    work3 = 0x4F8C;
    asm("" : "+r"(work3));
    pointer2 += work3;
    data = pointer2;
lookup_loop:
    current = index << 24;
    index = current >> 24;
    current = index + highIndex;
    pointer2 = data;
    pointer1 = (u8 *)(current + (u32)pointer2);
    current = *pointer1;
    work3 = pointer5[2];
    if ((u32)current >= (u32)work3)
        goto lookup_next;
    work2 = (s8)previous;
    work3 = work2 << 3;
    work3 += (u32)pointer5;
    current <<= 3;
    current += (u32)pointer5;
    previous = 0x124;
    asm("" : "+r"(previous));
    current += previous;
    work1 = *(u32 *)(current + 4);
    current = *(u32 *)current;
    *(u32 *)(work3 + 4) = current;
    *(u32 *)(work3 + 8) = work1;
    work2++;
    previous = (u8)work2;
lookup_next:
    current = index + 1;
    current <<= 24;
    index = (u32)current >> 24;
    current >>= 24;
    if (current <= 35)
        goto lookup_loop;
    goto ordered;
order_small:
    index = 0;
    work3 = 0;
    current = side;
    current++;
    nextSide = current;
    pointer1 = D_02031A0C;
    work1 = pointer1[2];
    if (index >= work1)
        goto ordered;
    pointer2 = D_02031A0C;
    context = pointer2;
    previous = 0x124;
    asm("" : "+r"(previous));
    pointer2 += previous;
    asm("" : "+r"(pointer2));
    temporary = pointer2;
small_loop:
    current = index << 24;
    work1 = current >> 21;
    pointer4 = context;
    pointer2 = (u8 *)(work1 + (u32)pointer4);
    work1 = pointer2[4];
    highIndex = current;
    previous = savedId;
    if (work1 != previous)
        goto small_next;
    current = pointer2[5];
    if ((u32)current > 2)
        goto small_next;
    current = *(u32 *)(pointer2 + 4);
    work1 = *(u32 *)(pointer2 + 8);
    pointer2 = temporary;
    {
        u32 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
        pointer2 = (u8 *)address;
    }
    *(u32 *)(pointer2 + 4) = work1;
    previous = (u32)highIndex >> 24;
    work2 = previous << 24;
    current = work3 << 24;
    work1 = current >> 24;
    index = current;
    if (work2 <= index)
        goto small_insert;
    pointer5 = D_02031A0C;
    boundary = work1;
small_shift:
    work2 >>= 24;
    work3 = work2 << 3;
    work3 += (u32)pointer5;
    work2--;
    current = work2 << 3;
    current += (u32)pointer5;
    work1 = *(u32 *)(current + 8);
    current = *(u32 *)(current + 4);
    *(u32 *)(work3 + 4) = current;
    *(u32 *)(work3 + 8) = work1;
    work2 <<= 24;
    previous = (u32)work2 >> 24;
    work2 = previous << 24;
    current = work2 >> 24;
    if (current > boundary)
        goto small_shift;
small_insert:
    current = previous << 24;
    current >>= 21;
    current += (u32)context;
    pointer3 = temporary;
    work1 = *(u32 *)pointer3;
    work2 = *(u32 *)(pointer3 + 4);
    *(u32 *)(current + 4) = work1;
    *(u32 *)(current + 8) = work2;
    previous = 0x1000000;
    asm("" : "+r"(previous));
    current = index + previous;
    work3 = (u32)current >> 24;
small_next:
    work1 = 0x1000000;
    current = highIndex + work1;
    index = (u32)current >> 24;
    current >>= 24;
    pointer2 = context;
    work2 = pointer2[2];
    if (current < work2)
        goto small_loop;
    goto ordered;
order_large:
    index = 0;
    work3 = 0;
    previous = side;
    previous++;
    nextSide = previous;
    pointer0 = D_02031A0C;
    current = pointer0[2];
    if (index >= current)
        goto ordered;
    pointer1 = D_02031A0C;
    context = pointer1;
    work2 = 0x124;
    pointer1 += work2;
    asm("" : "+r"(pointer1));
    temporary = pointer1;
large_loop:
    current = index << 24;
    work1 = current >> 21;
    pointer4 = context;
    pointer2 = (u8 *)(work1 + (u32)pointer4);
    work1 = pointer2[4];
    highIndex = current;
    previous = savedId;
    if (work1 != previous)
        goto large_next;
    current = pointer2[5];
    if ((u32)current <= 2)
        goto large_next;
    current = *(u32 *)(pointer2 + 4);
    work1 = *(u32 *)(pointer2 + 8);
    pointer2 = temporary;
    {
        u32 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
        pointer2 = (u8 *)address;
    }
    *(u32 *)(pointer2 + 4) = work1;
    previous = (u32)highIndex >> 24;
    work2 = previous << 24;
    current = work3 << 24;
    work1 = current >> 24;
    index = current;
    if (work2 <= index)
        goto large_insert;
    pointer5 = D_02031A0C;
    boundary = work1;
large_shift:
    work2 >>= 24;
    work3 = work2 << 3;
    work3 += (u32)pointer5;
    work2--;
    current = work2 << 3;
    current += (u32)pointer5;
    work1 = *(u32 *)(current + 8);
    current = *(u32 *)(current + 4);
    *(u32 *)(work3 + 4) = current;
    *(u32 *)(work3 + 8) = work1;
    work2 <<= 24;
    previous = (u32)work2 >> 24;
    work2 = previous << 24;
    current = work2 >> 24;
    if (current > boundary)
        goto large_shift;
large_insert:
    current = previous << 24;
    current >>= 21;
    current += (u32)context;
    pointer3 = temporary;
    work1 = *(u32 *)pointer3;
    work2 = *(u32 *)(pointer3 + 4);
    *(u32 *)(current + 4) = work1;
    *(u32 *)(current + 8) = work2;
    previous = 0x1000000;
    asm("" : "+r"(previous));
    current = index + previous;
    work3 = (u32)current >> 24;
large_next:
    work1 = 0x1000000;
    current = highIndex + work1;
    index = (u32)current >> 24;
    current >>= 24;
    pointer2 = context;
    work2 = pointer2[2];
    if (current < work2)
        goto large_loop;
ordered:
    work3 = nextSide;
    asm("" : "+r"(work3));
    current = (u8)work3;
    side = current;
    if ((u32)current <= 1)
        goto order_side;
    current = 0;
    pointer4 = D_02031A0C;
    pointer4[3] = current;
}
