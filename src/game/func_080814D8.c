#include "types.h"

extern u8 D_0201F6DC[];
extern u8 D_08734B8C[];
extern u8 D_087B28A0[];
void func_0808148C(u32);
void func_080771F4(u8 *);
void func_08080974(u8 *);
s32 func_080C8BE8(s32, s32);
u32 func_080C8B74(s32, s32);
u32 func_080C8B8C(s32);
u8 *func_08076FE0(u8 *, u32, u32, s32, s32, u32, u32, u32, u32);

void func_080814D8(u32 arg0, u8 *arg1)
{
    volatile u32 savedIndex;
    register s32 current asm("r0") = arg0;
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 offset asm("r5");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *state asm("r6") = arg1;
    u8 *entry;
    register u8 *table asm("r8");
    register u8 *base asm("r10");
    register s32 indexOffset asm("r9");

    current = (u8)current;
    savedIndex = current;
    work1 = state[0];
    current = 2;
    current &= work1;
    if (current != 0) {
        current = 0;
        state[0x14] = current;
        goto done;
    }
    pointer0 = D_0201F6DC;
    base = pointer0;
    work1 = savedIndex;
    work1 <<= 1;
    indexOffset = work1;
    goto read_wait;
decrement_wait:
    current = state[0x14];
    asm("" : "+r"(current));
    work3 = current;
    if (work3 == 8)
        goto object_wait;
    current = work1 - 1;
    *(u16 *)pointer2 = current;
check_wait:
    current = state[0x14];
    asm("" : "+r"(current));
    work3 = current;
    if (work3 == 8)
        goto object_wait;
    pointer0 = D_0201F6DC;
    work2 = 0x10CC;
    asm("" : "+r"(work2));
    pointer0 += work2;
    pointer0 += indexOffset;
    current = *(u16 *)pointer0;
    if (current == 0)
        goto complete;
    goto refresh_wait;
object_wait:
    pointer0 = *(u8 **)(state + 0x1C);
    current = *(u32 *)pointer0;
    work1 = 4;
    current &= work1;
    if (current == 0)
        goto refresh_wait;
complete:
    current = work3 - 1;
    current = (u8)current;
    if ((u32)current > 2)
        goto complete_mode;
    work1 = state[0x16];
    current = 1;
    current &= work1;
    if (current == 0)
        goto complete_mode;
    work1 = *(s32 *)(state + 4);
    work2 = 0x7FF;
    work2 &= work1;
    current = 0x400;
    if (work2 <= current)
        goto round_x_down;
    work4 = 0x800;
    current = work1 + work4;
    current -= work2;
    goto store_x;
round_x_down:
    current = work1 - work2;
store_x:
    *(s32 *)(state + 4) = current;
    work1 = *(s32 *)(state + 8);
    work2 = 0x7FF;
    work2 &= work1;
    current = 0x400;
    if (work2 <= current)
        goto round_y_down;
    work4 = 0x800;
    current = work1 + work4;
    current -= work2;
    goto store_y;
round_y_down:
    current = work1 - work2;
store_y:
    *(s32 *)(state + 8) = current;
complete_mode:
    current = work3;
    if (current != 8)
        goto clear_mode;
    pointer0 = D_0201F6DC;
    work1 = 0x10CC;
    pointer0 += work1;
    pointer0 += indexOffset;
    work1 = 0;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer0));
        *address = work1;
    }
    goto advance;
clear_mode:
    if (current == 0)
        goto advance;
    if (current == 9)
        goto advance;
    current = 0;
    state[0x14] = current;
advance:
    current = savedIndex;
    func_0808148C(current);
refresh_wait:
    pointer0 = D_0201F6DC;
    work2 = 0x10CC;
    pointer1 = pointer0 + work2;
    pointer1 += indexOffset;
    work1 = *(u16 *)pointer1;
    base = pointer0;
    if (work1 == 0)
        goto read_wait;
    goto done;
read_wait:
    current = 0x10CC;
    current += (u32)base;
    work3 = indexOffset;
    asm("" : "+r"(work3));
    pointer2 = (u8 *)(work3 + current);
    work1 = *(u16 *)pointer2;
    if (work1 != 0)
        goto decrement_wait;
    work4 = savedIndex;
    work1 = work4 << 8;
    current = 0x2CC;
    current += (u32)base;
    pointer0 = (u8 *)(work1 + current);
    work4 = *(u16 *)pointer0;
    offset = work1;
    if (work4 == 0)
        goto no_command;
    current = state[0x14];
    if (current != 8)
        goto dispatch;
    if (work4 == 0x8A)
        goto dispatch;
    pointer0 = *(u8 **)(state + 0x1C);
    func_080771F4(pointer0);
    pointer0 = *(u8 **)(state + 0x20);
    if (pointer0 != 0)
        func_080771F4(pointer0);
    pointer0 = state;
    func_08080974(pointer0);
dispatch:
    pointer0 = D_0201F6DC;
    work2 = 0x2CC;
    asm("" : "+r"(work2));
    pointer1 = pointer0 + work2;
    pointer1 = (u8 *)(offset + (u32)pointer1);
    work1 = *(u16 *)pointer1;
    work1 -= 0x38;
    base = pointer0;
    {
    u32 command;
    asm("" : "=r"(command) : "0"(work1) : "r0");
    switch (command) {
    case 0:
        current = 0;
        state[0x14] = current;
        pointer1 = D_0201F6DC;
        work3 = 0x2CE;
        asm("" : "+r"(work3));
        pointer0 = pointer1 + work3;
        pointer0 = (u8 *)(offset + (u32)pointer0);
        current = *(u16 *)pointer0;
        state[0x16] = current;
        work4 = 0x10CC;
        asm("" : "+r"(work4));
        pointer2 = pointer1 + work4;
        pointer2 += indexOffset;
        current = 0x2D0;
        asm("" : "+r"(current));
        pointer1 += current;
        pointer1 = (u8 *)(offset + (u32)pointer1);
        current = *(u16 *)pointer1;
        *(u16 *)pointer2 = current;
        work1 = state[0];
        current = 0x20;
        current &= work1;
        if (current == 0)
            goto check_wait;
        goto clear_turn;
    case 1:
        current = 1;
        state[0x14] = current;
        work1 = 0x2CE;
        work1 += (u32)base;
        pointer1 = (u8 *)(offset + work1);
        work1 = *(u16 *)pointer1;
        state[0x16] = work1;
        current &= work1;
        if (current != 0)
            goto slow_first;
        current = 0x10CC;
        current += (u32)base;
        pointer0 = (u8 *)(current + indexOffset);
        work1 = 0x2D0;
        work1 += (u32)base;
        pointer1 = (u8 *)(offset + work1);
        work1 = *(u16 *)pointer1;
        work1 <<= 4;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        goto first_turn;
slow_first:
        work4 = 0x10CC;
        work4 += (u32)base;
        pointer4 = (u8 *)(work4 + indexOffset);
        current = 0x2D0;
        current += (u32)base;
        pointer0 = (u8 *)(offset + current);
        current = *(u16 *)pointer0;
        current <<= 11;
        work1 = 90;
        current = func_080C8BE8(current, work1);
        *(u16 *)pointer4 = current;
first_turn:
        pointer0 = D_0201F6DC;
        work1 = 0x2D2;
        asm("" : "+r"(work1));
        pointer0 += work1;
turn_check:
        pointer0 = (u8 *)(offset + (u32)pointer0);
        current = *(u16 *)pointer0;
        if (current == 0)
            goto read_turn;
        goto set_turn;
    case 2:
        current = 2;
        state[0x14] = current;
        current = 0x2CE;
        current += (u32)base;
        pointer0 = (u8 *)(offset + current);
        work1 = *(u16 *)pointer0;
        state[0x16] = work1;
        current = 1;
        current &= work1;
        if (current != 0)
            goto slow_second;
        current = 0x10CC;
        current += (u32)base;
        pointer0 = (u8 *)(current + indexOffset);
        work1 = 0x2D0;
        work1 += (u32)base;
        pointer1 = (u8 *)(offset + work1);
        work1 = *(u16 *)pointer1;
        work1 <<= 3;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        goto second_turn;
slow_second:
        work4 = 0x10CC;
        work4 += (u32)base;
        pointer4 = (u8 *)(work4 + indexOffset);
        current = 0x2D0;
        current += (u32)base;
        pointer0 = (u8 *)(offset + current);
        current = *(u16 *)pointer0;
        current <<= 11;
        work1 = 181;
        current = func_080C8BE8(current, work1);
        *(u16 *)pointer4 = current;
second_turn:
        pointer0 = D_0201F6DC;
        work2 = 0x2D2;
        asm("" : "+r"(work2));
        pointer0 += work2;
        goto turn_check;
    case 3:
        current = 3;
        state[0x14] = current;
        current = 0x2CE;
        current += (u32)base;
        pointer0 = (u8 *)(offset + current);
        work1 = *(u16 *)pointer0;
        state[0x16] = work1;
        current = 1;
        current &= work1;
        if (current != 0)
            goto slow_third;
        current = 0x10CC;
        current += (u32)base;
        pointer0 = (u8 *)(current + indexOffset);
        work1 = 0x2D0;
        work1 += (u32)base;
        pointer1 = (u8 *)(offset + work1);
        work1 = *(u16 *)pointer1;
        work1 <<= 2;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        goto third_turn;
slow_third:
        work4 = 0x10CC;
        work4 += (u32)base;
        pointer4 = (u8 *)(work4 + indexOffset);
        current = 0x2D0;
        current += (u32)base;
        pointer0 = (u8 *)(offset + current);
        current = *(u16 *)pointer0;
        current <<= 11;
        work1 = 362;
        current = func_080C8BE8(current, work1);
        *(u16 *)pointer4 = current;
third_turn:
        pointer0 = D_0201F6DC;
        work3 = 0x2D2;
        asm("" : "+r"(work3));
        pointer0 += work3;
        goto turn_check;
    case 4:
    case 5:
    case 6:
        current = 0x2CC;
        current += (u32)base;
        pointer0 = (u8 *)(offset + current);
        current = *(u16 *)pointer0;
        switch (current) {
        case 0x3C:
            current = 4;
            goto store_mode;
        case 0x3D:
            current = 5;
            goto store_mode;
        case 0x3E:
            current = 6;
store_mode:
            state[0x14] = current;
        }
        pointer2 = D_0201F6DC;
        work4 = 0x2CE;
        asm("" : "+r"(work4));
        pointer0 = pointer2 + work4;
        pointer0 = (u8 *)(offset + (u32)pointer0);
        current = *(u16 *)pointer0;
        work1 = current << 3;
        current = *(s32 *)(state + 4);
        if (current < 0)
            current += 255;
        current >>= 8;
        work1 -= current;
        *(s32 *)(state + 0x24) = work1;
        work3 = 0x2D0;
        asm("" : "+r"(work3));
        pointer0 = pointer2 + work3;
        pointer0 = (u8 *)(offset + (u32)pointer0);
        current = *(u16 *)pointer0;
        work2 = current << 3;
        current = *(s32 *)(state + 8);
        if (current < 0)
            current += 255;
        current >>= 8;
        current = work2 - current;
        *(s32 *)(state + 0x28) = current;
        current = -current;
        current = (s16)current;
        work1 = (s16)work1;
        current = func_080C8B74(current, work1);
        current <<= 16;
        work1 = (u32)current >> 16;
        work4 = 0x1000;
        asm("" : "+r"(work4));
        current = work1 + work4;
        work1 = current >> 13;
        current = work1;
        asm("" : "+r"(current));
        current >>= 3;
        current <<= 3;
        current = work1 - current;
        work1 = 0;
        state[0x16] = current;
        current = *(s32 *)(state + 0x24);
        if (current < 0)
            goto negative_x;
        *(s32 *)(state + 0x2C) = work1;
        goto sign_y;
negative_x:
        current = -current;
        *(s32 *)(state + 0x24) = current;
        current = 1;
        *(s32 *)(state + 0x2C) = current;
sign_y:
        current = *(s32 *)(state + 0x28);
        if (current < 0)
            goto negative_y;
        current = 0;
        goto store_sign_y;
negative_y:
        current = -current;
        *(s32 *)(state + 0x28) = current;
        current = 1;
store_sign_y:
        *(s32 *)(state + 0x30) = current;
        current = 0;
        *(s32 *)(state + 0x38) = current;
        *(s32 *)(state + 0x34) = current;
        current = *(s32 *)(state + 0x24);
        work3 = current;
        work3 *= current;
        asm("" : "+r"(work3));
        current = work3;
        asm("" : "+r"(current));
        work1 = *(s32 *)(state + 0x28);
        work4 = work1;
        work4 *= work1;
        asm("" : "+r"(work4));
        work1 = work4;
        asm("" : "+r"(work1));
        current += work1;
        current = func_080C8B8C(current);
        work2 = current << 16;
        work1 = (u32)work2 >> 16;
        *(s32 *)(state + 0x3C) = work1;
        pointer0 = D_0201F6DC;
        work3 = 0x2CC;
        asm("" : "+r"(work3));
        pointer0 += work3;
        pointer0 = (u8 *)(offset + (u32)pointer0);
        current = *(u16 *)pointer0;
        if (current != 0x3C)
            goto check_half_speed;
        current = work1 << 1;
        goto store_speed;
check_half_speed:
        if (current != 0x3E)
            goto movement_wait;
        current = (u32)work2 >> 17;
store_speed:
        *(s32 *)(state + 0x3C) = current;
movement_wait:
        pointer2 = D_0201F6DC;
        work4 = 0x10CC;
        asm("" : "+r"(work4));
        pointer0 = pointer2 + work4;
        pointer0 += indexOffset;
        work1 = *(s32 *)(state + 0x3C);
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        current = 0x2D2;
        asm("" : "+r"(current));
        pointer2 += current;
        pointer2 = (u8 *)(offset + (u32)pointer2);
        current = *(u16 *)pointer2;
        if (current != 0)
            goto set_turn;
read_turn:
        work1 = state[0];
clear_turn:
        current = 0xDF;
        current &= work1;
        state[0] = current;
        goto check_wait;
set_turn:
        work1 = state[0];
        current = 0x20;
        current |= work1;
        state[0] = current;
        goto check_wait;
    case 7:
        current = 7;
        state[0x14] = current;
        pointer0 = D_0201F6DC;
        work1 = 0x10CC;
        asm("" : "+r"(work1));
        pointer0 += work1;
        pointer0 += indexOffset;
        work1 = 14;
        *(s32 *)(state + 0x24) = work1;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        goto check_wait;
    case 8:
        work2 = 0;
        pointer3 = D_08734B8C;
        asm("" : "+r"(pointer3));
        table = pointer3;
        pointer4 = table;
        work3 = state[1];
        goto find_entry;
next_entry:
        current = work2 + 1;
        work2 = (u8)current;
        current = work2 << 3;
        current += work2;
        current <<= 2;
        pointer0 = (u8 *)(current + (u32)pointer4);
        table = pointer0;
        current = *pointer0;
        if (current != 255)
            goto find_entry;
        goto refresh_wait;
find_entry:
        pointer1 = table;
        current = *pointer1;
        if (current != work3)
            goto next_entry;
        current = 0x2CE;
        current += (u32)base;
        pointer1 = (u8 *)(offset + current);
        current = *(u16 *)pointer1;
        if ((u32)current > 7)
            goto next_entry;
        current <<= 2;
        current += 4;
        pointer1 = table;
        entry = pointer1 + current;
        current = *entry;
        if (current == 255)
            goto next_entry;
        offset = 0;
        current = 8;
        state[0x14] = current;
        pointer0 = *(u8 **)(state + 0x1C);
        func_080771F4(pointer0);
        pointer0 = D_087B28A0;
        work1 = entry[0];
        work2 = entry[1];
        work3 = *(s32 *)(state + 4);
        pointer0 = func_08076FE0(pointer0, work1, work2, work3,
            *(s32 *)(state + 8), state[2] << 4, state[2], 0x4412D0, offset);
        pointer1 = pointer0;
        *(u8 **)(state + 0x1C) = pointer1;
        current = entry[3];
        if (current != 0)
            goto check_attachment;
        current = *(u16 *)(pointer1 + 0xE);
        current -= 2;
        *(u16 *)(pointer1 + 0xE) = current;
check_attachment:
        work4 = entry[2];
        if (work4 != 0)
            goto entry_wait;
        pointer0 = *(u8 **)(state + 0x20);
        func_080771F4(pointer0);
        *(s32 *)(state + 0x20) = work4;
entry_wait:
        current = 0x10CC;
        current += (u32)base;
        pointer0 = (u8 *)(current + indexOffset);
        work1 = 1;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        pointer2 = table;
        current = *pointer2;
        if (current != 255)
            goto entry_done;
        goto refresh_wait;
entry_done:
        goto check_wait;
    case 0x52:
        work2 = 0;
        current = 9;
        state[0x14] = current;
        pointer0 = D_0201F6DC;
        work3 = 0x10CC;
        asm("" : "+r"(work3));
        pointer0 += work3;
        pointer0 += indexOffset;
        work1 = 120;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        *(s32 *)(state + 0x24) = work2;
        current = 1;
        *(s32 *)(state + 0x2C) = current;
        *(s32 *)(state + 0x28) = current;
        goto check_wait;
    default:
        goto check_wait;
    }
}
no_command:
    work3 = state[0];
    current = 0x20;
    current &= work3;
    if (current == 0)
        goto done;
    work1 = state[0x16];
    work2 = work1 + 4;
    current = work2;
    asm("" : "+r"(current));
    current >>= 3;
    current <<= 3;
    current = work2 - current;
    state[0x16] = current;
    current = 0xDF;
    current &= work3;
    state[0] = current;
done:
    return;
}
