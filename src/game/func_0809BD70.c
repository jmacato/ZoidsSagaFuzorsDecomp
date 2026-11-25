#include "types.h"

extern u8 D_02031A0C[];
extern u16 D_030057EC;
extern u16 D_0300000E;
void func_080C8FCC(u32);
void func_08075F20(u32);
u32 func_0809A99C(u32, u32);
u32 func_080C8C80(s32, s32);
u32 func_080C8BE8(s32, s32);

s32 func_0809BD70(u32 arg0)
{
    volatile u32 allowSide;
    volatile s32 savedStep;
    volatile s32 savedStart;
    register s32 current asm("r0") = arg0;
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer6 asm("r6");
    u8 *pointer7;
    register s32 highIndex asm("r4");
    register s32 candidate asm("r5");
    register s32 limit asm("r6");
    register s32 one asm("r7");
    register u8 *side asm("r9");
    register u8 *member asm("r10");
    register s32 selected asm("r8");

    current = (u8)current;
    allowSide = current;
    pointer0 = D_02031A0C;
    work1 = 0x4E9C;
    pointer0 += work1;
    asm("" : "+r"(pointer0));
    side = pointer0;
    pointer2 = D_02031A0C;
    work3 = 0x4E9D;
    asm("" : "+r"(work3));
    pointer2 += work3;
    asm("" : "+r"(pointer2));
    member = pointer2;
frame:
    current = 1;
    func_080C8FCC(current);
    current = 0;
    asm("" : "+r"(current));
    selected = current;
    pointer0 = (u8 *)&D_030057EC;
    work1 = *(u16 *)pointer0;
    current = 0x40;
    current &= work1;
    if (current == 0)
        goto up_second_key;
    pointer2 = side;
    current = *(s8 *)pointer2;
    pointer3 = D_02031A0C;
    if (current == 0)
        goto up;
up_second_key:
    current = 0x80;
    current &= work1;
    if (current == 0)
        goto down_keys;
    pointer3 = side;
    current = *(s8 *)pointer3;
    pointer3 = D_02031A0C;
    if (current == 0)
        goto down_keys;
up:
    current = 0x4E9D;
    asm("" : "+r"(current));
    pointer4 = pointer3 + current;
    current = *(s8 *)pointer4;
    work1 = 3;
    current = func_080C8C80(current, work1);
    work2 = current;
    current = work2 << 24;
    if (current == 0)
        goto frame_end;
    current = *pointer4;
    work1 = current - 1;
    current -= work2;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    highIndex = candidate << 24;
    current <<= 24;
    work1 = current >> 24;
    if (highIndex < current)
        goto up_wrap_check;
    limit = work1;
up_loop:
    pointer1 = side;
    current = *pointer1;
    work1 = (u32)highIndex >> 24;
    current = func_0809A99C(current, work1);
    if (current != 0)
        goto up_found;
    work2 = 0xFF000000;
    asm("" : "+r"(work2));
    current = highIndex + work2;
    candidate = (u32)current >> 24;
    highIndex = candidate << 24;
    current = highIndex >> 24;
    if (current >= limit)
        goto up_loop;
up_wrap_check:
    work3 = selected;
    asm("" : "+r"(work3));
    if (work3 != 0)
        goto changed;
    pointer0 = D_02031A0C;
    work2 = 0x4E9D;
    pointer1 = pointer0 + work2;
    current = *(s8 *)pointer1;
    work2 = 0;
    if (current <= 2)
        work2 = 3;
    current = *(s8 *)pointer1;
    work1 = 3;
    savedStep = work2;
    current = func_080C8C80(current, work1);
    work2 = savedStep;
    work1 = work2 - 1;
    current += work1;
    current <<= 24;
    candidate = (u32)current >> 24;
    highIndex = candidate << 24;
    current = highIndex >> 24;
    if (current < work2)
        goto frame_end;
    limit = work2;
up_wrap_loop:
    pointer3 = side;
    current = *pointer3;
    work1 = (u32)highIndex >> 24;
    current = func_0809A99C(current, work1);
    if (current != 0)
        goto wrap_up_found;
    work1 = 0xFF000000;
    current = highIndex + work1;
    candidate = (u32)current >> 24;
    highIndex = candidate << 24;
    current = highIndex >> 24;
    if (current >= limit)
        goto up_wrap_loop;
    goto frame_end;
up_found:
    {
        u8 *address = member;
        *address = candidate;
    }
    work3 = 1;
    asm("" : "+r"(work3) : "r"(current), "r"(work1));
    selected = work3;
    current = 0xCC;
    func_08075F20(current);
    goto up_wrap_check;
down_found:
    pointer0 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer0));
        *address = candidate;
    }
    work1 = 1;
    asm("" : "+r"(work1));
    selected = work1;
    current = 0xCC;
    func_08075F20(current);
    goto down_wrap_check;
down_keys:
    pointer1 = (u8 *)&D_030057EC;
    work2 = *(u16 *)pointer1;
    current = 0x40;
    current &= work2;
    if (current == 0)
        goto down_second_key;
    pointer3 = side;
    current = *(s8 *)pointer3;
    pointer3 = D_02031A0C;
    if (current != 0)
        goto down;
down_second_key:
    current = 0x80;
    current &= work2;
    if (current == 0)
        goto left_keys;
    pointer2 = side;
    current = *(s8 *)pointer2;
    pointer3 = D_02031A0C;
    if (current != 0)
        goto left_keys;
down:
    current = 0x4E9D;
    asm("" : "+r"(current));
    pointer6 = pointer3 + current;
    current = *(s8 *)pointer6;
    work1 = 3;
    current = func_080C8C80(current, work1);
    work2 = current;
    current = (s8)work2;
    if (current > 1)
        goto frame_end;
    current = *pointer6;
    work1 = current + 1;
    current -= work2;
    current += 3;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    highIndex = candidate << 24;
    current <<= 24;
    work1 = current >> 24;
    if (highIndex >= current)
        goto down_wrap_check;
    pointer7 = pointer6 - 1;
    limit = work1;
down_loop:
    current = *pointer7;
    work1 = (u32)highIndex >> 24;
    current = func_0809A99C(current, work1);
    if (current != 0)
        goto down_found;
    work1 = 0x1000000;
    asm("" : "+r"(work1));
    current = highIndex + work1;
    candidate = (u32)current >> 24;
    highIndex = candidate << 24;
    current = highIndex >> 24;
    if (current < limit)
        goto down_loop;
down_wrap_check:
    work2 = selected;
    asm("" : "+r"(work2));
    if (work2 != 0)
        goto changed;
    pointer3 = D_02031A0C;
    current = 0x4E9D;
    asm("" : "+r"(current));
    pointer1 = pointer3 + current;
    current = *(s8 *)pointer1;
    work2 = 0;
    if (current <= 2)
        work2 = 3;
    current = *(s8 *)pointer1;
    work1 = 3;
    savedStep = work2;
    current = func_080C8C80(current, work1);
    work2 = savedStep;
    work1 = work2 + 1;
    current += work1;
    current <<= 24;
    candidate = (u32)current >> 24;
    highIndex = candidate << 24;
    current = highIndex >> 24;
    work1 = work2 + 3;
    if (current >= work1)
        goto frame_end;
    limit = work1;
down_wrap_loop:
    pointer1 = side;
    current = *pointer1;
    work1 = (u32)highIndex >> 24;
    current = func_0809A99C(current, work1);
    if (current != 0)
        goto wrap_down_found;
    work2 = 0x1000000;
    asm("" : "+r"(work2));
    current = highIndex + work2;
    candidate = (u32)current >> 24;
    highIndex = candidate << 24;
    current = highIndex >> 24;
    if (current < limit)
        goto down_wrap_loop;
    goto frame_end;
left_keys:
    work2 = *(u16 *)pointer1;
    current = 0x20;
    current &= work2;
    if (current == 0)
        goto left_second_key;
    pointer3 = side;
    current = *(s8 *)pointer3;
    if (current == 0)
        goto left;
left_second_key:
    current = 0x10;
    current &= work2;
    if (current == 0)
        goto right_keys;
    pointer2 = side;
    current = *(s8 *)pointer2;
    if (current == 0)
        goto right_keys;
left:
    pointer3 = member;
    highIndex = *(s8 *)pointer3;
    current = highIndex;
    work1 = 3;
    current = func_080C8BE8(current, work1);
    current <<= 24;
    if (current == 0)
        goto left_side;
    current = highIndex;
    work1 = 3;
    current = func_080C8C80(current, work1);
    current <<= 24;
    candidate = (u32)current >> 24;
    work3 = candidate;
    current = candidate << 24;
    work2 = 0xFF;
    if (current == 0)
        work2 = 1;
    highIndex = current;
    goto left_check;
left_next:
    work1 = highIndex >> 24;
    current = (s8)work2;
    work1 += current;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    work1 >>= 24;
    if (work1 == 3) {
        candidate = 0;
        goto left_compare;
    }
    current = -1;
    if (work1 == current)
        candidate = 2;
left_compare:
    current = candidate << 24;
    asm("" : "+r"(current));
    work1 = work3 << 24;
    highIndex = current;
    if (highIndex == work1)
        goto left_done;
left_check:
    pointer1 = side;
    current = *pointer1;
    work1 = (u32)highIndex >> 24;
    savedStep = work2;
    savedStart = work3;
    current = func_0809A99C(current, work1);
    work2 = savedStep;
    work3 = savedStart;
    if (current == 0)
        goto left_next;
    pointer2 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = candidate;
    }
    work3 = 1;
    asm("" : "+r"(work3));
    selected = work3;
    current = 0xCC;
    func_08075F20(current);
left_done:
    current = selected;
    asm("" : "+r"(current));
    if (current == 0) {
        pointer1 = member;
        current = *pointer1;
        current -= 3;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = current;
        }
    }
left_side:
    work2 = allowSide;
    if (work2 == 0)
        goto frame_end;
    pointer3 = member;
    highIndex = *(s8 *)pointer3;
    current = highIndex;
    work1 = 3;
    current = func_080C8BE8(current, work1);
    current <<= 24;
    if (current != 0)
        goto frame_end;
    current = selected;
    asm("" : "+r"(current));
    if (current != 0)
        goto changed;
    current = highIndex;
    work1 = 3;
    current = func_080C8C80(current, work1);
    work1 = 2;
    work1 -= current;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    work3 = candidate;
    current = candidate << 24;
    work2 = 0xFF;
    if (current == 0)
        work2 = 1;
    highIndex = current;
    goto other_small_check;
other_small_next:
    work1 = highIndex >> 24;
    current = (s8)work2;
    work1 += current;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    work1 >>= 24;
    if (work1 == 3) {
        candidate = 0;
        goto other_small_compare;
    }
    current = -1;
    if (work1 == current)
        candidate = 2;
other_small_compare:
    current = candidate << 24;
    asm("" : "+r"(current));
    work1 = work3 << 24;
    highIndex = current;
    if (highIndex == work1)
        goto other_small_done;
other_small_check:
    pointer0 = D_02031A0C;
    work1 = 0x4E9C;
    pointer6 = pointer0 + work1;
    current = *pointer6;
    one = 1;
    current ^= one;
    work1 = (u32)highIndex >> 24;
    savedStep = work2;
    savedStart = work3;
    current = func_0809A99C(current, work1);
    work2 = savedStep;
    work3 = savedStart;
    if (current == 0)
        goto other_small_next;
    current = *pointer6;
    current ^= one;
    *pointer6 = current;
    pointer2 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = candidate;
    }
    work3 = 1;
    asm("" : "+r"(work3));
    selected = work3;
    current = 0xCC;
    func_08075F20(current);
other_small_done:
    current = selected;
    asm("" : "+r"(current));
    if (current != 0)
        goto changed;
    pointer1 = member;
    current = *(s8 *)pointer1;
    work1 = 3;
    current = func_080C8C80(current, work1);
    work1 = 5;
    work1 -= current;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    work3 = candidate;
    current = candidate << 24;
    work2 = 0xFF;
    if (current == 0)
        work2 = 1;
    highIndex = current;
    goto other_large_check;
other_large_next:
    work1 = highIndex >> 24;
    current = (s8)work2;
    work1 += current;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    current = work1 >> 24;
    if (current == 6) {
        candidate = 3;
        goto other_large_compare;
    }
    if (current == 2)
        candidate = 5;
other_large_compare:
    current = candidate << 24;
    asm("" : "+r"(current));
    work1 = work3 << 24;
    highIndex = current;
    if (highIndex == work1)
        goto frame_end;
other_large_check:
    pointer0 = D_02031A0C;
    work1 = 0x4E9C;
    pointer6 = pointer0 + work1;
    current = *pointer6;
    one = 1;
    current ^= one;
    work1 = (u32)highIndex >> 24;
    savedStep = work2;
    savedStart = work3;
    current = func_0809A99C(current, work1);
    work2 = savedStep;
    work3 = savedStart;
    if (current == 0)
        goto other_large_next;
    current = *pointer6;
    current ^= one;
    *pointer6 = current;
    pointer2 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = candidate;
    }
    work3 = 1;
    asm("" : "+r"(work3));
    selected = work3;
    goto changed_sound;
right_keys:
    asm("" : "+r"(pointer1));
    work1 = *(u16 *)pointer1;
    current = 0x20;
    current &= work1;
    if (current == 0)
        goto right_second_key;
    pointer2 = side;
    current = *(s8 *)pointer2;
    pointer3 = D_02031A0C;
    if (current != 0)
        goto right;
right_second_key:
    current = 0x10;
    current &= work1;
    if (current == 0)
        goto confirm;
    pointer3 = side;
    current = *(s8 *)pointer3;
    pointer3 = D_02031A0C;
    if (current != 0)
        goto confirm;
right:
    current = 0x4E9D;
    asm("" : "+r"(current));
    pointer4 = pointer3 + current;
    current = *(s8 *)pointer4;
    work1 = 3;
    current = func_080C8BE8(current, work1);
    current <<= 24;
    if (current != 0)
        goto frame_end;
    current = *pointer4;
    current += 3;
    current <<= 24;
    candidate = (u32)current >> 24;
    work3 = candidate;
    current = candidate << 24;
    work2 = 0xFF;
    if (candidate == 3)
        work2 = 1;
    highIndex = current;
    goto right_check;
right_next:
    work1 = highIndex >> 24;
    current = (s8)work2;
    work1 += current;
    work1 <<= 24;
    candidate = (u32)work1 >> 24;
    current = work1 >> 24;
    if (current == 6) {
        candidate = 3;
        goto right_compare;
    }
    if (current == 2)
        candidate = 5;
right_compare:
    current = candidate << 24;
    asm("" : "+r"(current));
    work1 = work3 << 24;
    highIndex = current;
    if (highIndex == work1)
        goto frame_end;
right_check:
    pointer1 = side;
    current = *pointer1;
    work1 = (u32)highIndex >> 24;
    savedStep = work2;
    savedStart = work3;
    current = func_0809A99C(current, work1);
    work2 = savedStep;
    work3 = savedStart;
    if (current == 0)
        goto right_next;
    pointer2 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = candidate;
    }
    work3 = 1;
    asm("" : "+r"(work3));
    selected = work3;
    goto changed_sound;
confirm:
    pointer0 = (u8 *)&D_0300000E;
    work1 = *(u16 *)pointer0;
    current = 1;
    current &= work1;
    if (current != 0) {
        current = 0xCA;
        func_08075F20(current);
        return 1;
    }
    current = 2;
    current &= work1;
    if (current == 0)
        goto frame_end;
    current = 0xCB;
    func_08075F20(current);
    return 2;
wrap_down_found:
    pointer0 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer0));
        *address = candidate;
    }
    work1 = 1;
    asm("" : "+r"(work1));
    selected = work1;
changed_sound:
    current = 0xCC;
    func_08075F20(current);
    goto frame_end;
wrap_up_found:
    {
        u8 *address = member;
        *address = candidate;
    }
    work3 = 1;
    asm("" : "+r"(work3) : "r"(current), "r"(work1));
    selected = work3;
    current = 0xCC;
    func_08075F20(current);
frame_end:
    current = selected;
    asm("" : "+r"(current));
    if (current == 0)
        goto frame;
changed:
    return 0;
}
