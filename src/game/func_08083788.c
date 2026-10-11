#include "types.h"

extern u8 D_02020811;
extern u8 D_02020818[];
extern u8 D_0201F6DC[];
extern s32 D_03000060[];
extern u8 D_02031A0C[];
extern u8 D_020209D8[];
extern u32 D_03000010;
extern s32 D_030025A8[];
u32 func_080C8BAC(u32);
void func_080C8FCC(u32);

void func_08083788(void)
{
    volatile u8 directions[4];
    volatile s32 distanceX;
    volatile s32 distanceY;
    volatile u32 elapsed;
    u32 *volatile randomSource;
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
    register s32 temporary4 asm("r4");
    register s32 temporary5 asm("r5");
    register s32 errorX asm("r6");
    s32 errorY;
    register s32 sumY asm("r7");
    register u8 *directionAddress asm("r10");
    register u8 *base asm("r9");
    register u32 nextElapsed asm("r8");
    register u8 *offsetX asm("r8");
    register u32 zero asm("r9");
    register u8 *objects asm("r8");
    register u32 nextSlot asm("r12");
    register s32 displacement asm("r4");
    u32 object;

    asm("" : "=r"(errorY));
    directionAddress = (u8 *)directions;
frame:
    pointer0 = &D_02020811;
    work3 = *pointer0;
    pointer1 = D_0201F6DC;
    asm("" : "+r"(pointer1));
    base = pointer1;
    if (work3 == 1)
        goto start;
    if (work3 == 2)
        goto move;
    goto shake;
start:
    pointer2 = D_0201F6DC;
    temporary4 = 0x1140;
    asm("" : "+r"(temporary4));
    pointer0 = pointer2 + temporary4;
    current = *(u16 *)pointer0;
    if (current == 0) {
        pointer5 = &D_02020811;
        *pointer5 = current;
        goto shake;
    }
    pointer1 = D_0201F6DC;
    work2 = 0x1138;
    pointer0 = pointer1 + work2;
    pointer4 = (u8 *)D_03000060;
    work1 = *(s32 *)pointer0;
    current = *(s32 *)pointer4;
    work1 -= current;
    if (work1 < 0)
        work1 += 255;
    work2 = work1 >> 8;
    distanceX = work2;
    pointer5 = D_02020818;
    work1 = *(s32 *)pointer5;
    current = *(s32 *)(pointer4 + 4);
    current = work1 - current;
    if (current < 0)
        current += 255;
    current >>= 8;
    distanceY = current;
    if (work2 >= 0) {
        current = 0;
        pointer1 = directionAddress;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = current;
            pointer1 = (u8 *)address;
        }
    } else {
        work2 = distanceX;
        work2 = -work2;
        distanceX = work2;
        pointer4 = directionAddress;
        *pointer4 = work3;
    }
    temporary5 = distanceY;
    if (temporary5 >= 0) {
        current = 0;
        pointer1 = directionAddress;
        pointer1[1] = current;
    } else {
        work2 = distanceY;
        work2 = -work2;
        distanceY = work2;
        current = 1;
        pointer3 = directionAddress;
        pointer3[1] = current;
    }
    errorY = 0;
    errorX = 0;
    temporary4 = 0;
    elapsed = temporary4;
    pointer5 = &D_02020811;
    current = *pointer5;
    current++;
    *pointer5 = current;
move:
    current = distanceX;
    errorX = current + errorX;
    work1 = distanceY;
    sumY = work1 + errorY;
    asm("" : "=r"(errorY) : "0"(sumY));
    current = 0x1140;
    current += (u32)base;
    pointer1 = (u8 *)D_03000060;
    work2 = elapsed;
    work2++;
    nextElapsed = work2;
    work3 = *(u16 *)current;
    asm("" : "+r"(work3));
    if (errorX < work3)
        goto move_y;
    pointer2 = pointer1;
    pointer3 = D_02031A0C;
    pointer4 = (u8 *)current;
move_x_loop:
    pointer5 = directionAddress;
    current = *pointer5;
    if (current == 0) {
        current = *(s32 *)pointer2;
        temporary5 = 256;
    } else {
        current = *(s32 *)pointer2;
        temporary5 = -256;
    }
    current += temporary5;
    {
        s32 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
        pointer2 = (u8 *)address;
    }
    current = *(s32 *)(pointer3 + 4);
    if (current != 0) {
        current = *(s32 *)(pointer1 + 8);
        current += temporary5;
        *(s32 *)(pointer1 + 8) = current;
    }
    current = *(u16 *)pointer4;
    errorX -= current;
    if (errorX >= current)
        goto move_x_loop;
move_y:
    current = 0x1140;
    current += (u32)base;
    work2 = *(u16 *)current;
    asm("" : "+r"(work2));
    if (errorY < work2)
        goto clamp;
    pointer2 = (u8 *)D_03000060;
    pointer3 = D_02031A0C;
    pointer4 = (u8 *)current;
move_y_loop:
    pointer5 = directionAddress;
    current = pointer5[1];
    if (current == 0) {
        current = *(s32 *)(pointer2 + 4);
        temporary5 = 256;
    } else {
        current = *(s32 *)(pointer2 + 4);
        temporary5 = -256;
    }
    current += temporary5;
    *(s32 *)(pointer2 + 4) = current;
    current = *(s32 *)(pointer3 + 4);
    if (current != 0) {
        current = *(s32 *)(pointer1 + 12);
        current += temporary5;
        *(s32 *)(pointer1 + 12) = current;
    }
    current = *(u16 *)pointer4;
    errorY -= current;
    if (errorY >= current)
        goto move_y_loop;
clamp:
    work2 = *(s32 *)pointer1;
    if (work2 < 0) {
        work2 = 0;
        {
            s32 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = work2;
            pointer1 = (u8 *)address;
        }
        pointer0 = D_02031A0C;
        current = *(s32 *)(pointer0 + 4);
        if (current != 0)
            *(s32 *)(pointer1 + 8) = work2;
        goto clamped_x;
    }
    pointer3 = D_020209D8;
    current = *(u16 *)(pointer3 + 0x14);
    current <<= 11;
    temporary4 = -0xF000;
    current += temporary4;
    if (work2 <= current)
        goto unclamped_x;
    {
        s32 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = current;
        pointer1 = (u8 *)address;
    }
    pointer0 = D_02031A0C;
    current = *(s32 *)(pointer0 + 4);
    if (current != 0) {
        current = *(u16 *)(pointer3 + 0x14);
        current <<= 11;
        current += temporary4;
        *(s32 *)(pointer1 + 8) = current;
    }
clamped_x:
    temporary4 = 1;
    goto clamp_y;
unclamped_x:
    temporary4 = 0;
clamp_y:
    work2 = *(s32 *)(pointer1 + 4);
    if (work2 < 0) {
        work2 = 0;
        *(s32 *)(pointer1 + 4) = work2;
        pointer0 = D_02031A0C;
        current = *(s32 *)(pointer0 + 4);
        if (current != 0)
            *(s32 *)(pointer1 + 12) = work2;
        goto clamped_y;
    }
    pointer3 = D_020209D8;
    current = *(u16 *)(pointer3 + 0x16);
    current <<= 11;
    temporary5 = -0xA000;
    current += temporary5;
    if (work2 <= current)
        goto check_clamps;
    *(s32 *)(pointer1 + 4) = current;
    pointer0 = D_02031A0C;
    current = *(s32 *)(pointer0 + 4);
    if (current != 0) {
        current = *(u16 *)(pointer3 + 0x16);
        current <<= 11;
        current += temporary5;
        *(s32 *)(pointer1 + 12) = current;
    }
clamped_y:
    current = temporary4 + 1;
    temporary4 = (u8)current;
check_clamps:
    if (temporary4 == 2) {
        current = 0;
        pointer1 = &D_02020811;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = current;
            pointer1 = (u8 *)address;
        }
    }
    work2 = nextElapsed;
    asm("" : "+r"(work2));
    current = (u16)work2;
    elapsed = current;
    current = 0x1140;
    current += (u32)base;
    work3 = elapsed;
    current = *(u16 *)current;
    if (work3 == current) {
        current = 0;
        pointer4 = &D_02020811;
        *pointer4 = current;
    }
shake:
    pointer5 = D_0201F6DC;
    work1 = 0x12F0;
    asm("" : "+r"(work1));
    pointer0 = pointer5 + work1;
    current = *pointer0;
    if (current == 0)
        goto objects_begin;
    work2 = pointer5[1];
    zero = work2;
    if (work2 != 0)
        goto screen_shake;
    pointer3 = (u8 *)&D_03000010;
    current = *(u32 *)pointer3;
    randomSource = (u32 *)pointer3;
    current = func_080C8BAC(current);
    work1 = current << 3;
    work1 -= current;
    work1 = (u32)work1 >> 15;
    work1 -= 3;
    work1 <<= 8;
    temporary4 = 0x12F4;
    asm("" : "+r"(temporary4));
    temporary4 += (u32)pointer5;
    offsetX = (u8 *)temporary4;
    work2 = *(s32 *)temporary4;
    current = work2;
    pointer3 = (u8 *)randomSource;
    if (work2 < 0)
        current += 255;
    current >>= 8;
    current <<= 8;
    displacement = work1 - current;
    current = *(u32 *)pointer3;
    current = func_080C8BAC(current);
    work1 = current << 3;
    work1 -= current;
    work1 = (u32)work1 >> 15;
    work1 -= 3;
    work1 <<= 8;
    current = 0x12F8;
    asm("" : "+r"(current));
    pointer5 += current;
    work3 = *(s32 *)pointer5;
    work2 = work3;
    if (work3 < 0)
        work2 += 255;
    work2 >>= 8;
    work2 <<= 8;
    work2 = work1 - work2;
    pointer1 = offsetX;
    current = *(s32 *)pointer1;
    current += displacement;
    *(s32 *)pointer1 = current;
    current = work3 + work2;
    *(s32 *)pointer5 = current;
    pointer1 = (u8 *)D_03000060;
    current = *(s32 *)pointer1;
    work3 = current + displacement;
    *(s32 *)pointer1 = work3;
    current = *(s32 *)(pointer1 + 4);
    current += work2;
    *(s32 *)(pointer1 + 4) = current;
    pointer0 = D_020209D8;
    work2 = pointer0[0x18];
    pointer4 = pointer0;
    if (work2 != 0)
        goto objects_begin;
    pointer0 = D_02031A0C;
    current = *(s32 *)(pointer0 + 4);
    if (current == 0)
        goto objects_begin;
    if (work3 < 0) {
        work2 = zero;
        asm("" : "+r"(work2));
        *(s32 *)pointer1 = work2;
        asm volatile("" : : "r"(work2));
    } else {
        current = *(u16 *)(pointer4 + 0x14);
        current <<= 11;
        temporary5 = -0xF000;
        asm("" : "+r"(temporary5));
        current += temporary5;
        if (work3 > current) *(s32 *)pointer1 = current;
    }
    work2 = *(s32 *)(pointer1 + 4);
    if (work2 < 0) {
        current = 0;
        goto shake_y_clamped;
    }
    current = *(u16 *)(pointer4 + 0x16);
    current <<= 11;
    work3 = -0xA000;
    asm("" : "+r"(work3));
    current += work3;
    if (work2 <= current)
        goto shake_copy;
shake_y_clamped:
    *(s32 *)(pointer1 + 4) = current;
shake_copy:
    current = *(s32 *)pointer1;
    *(s32 *)(pointer1 + 8) = current;
    current = *(s32 *)(pointer1 + 4);
    *(s32 *)(pointer1 + 12) = current;
    goto objects_begin;
screen_shake:
    temporary4 = zero;
    asm("" : "+r"(temporary4));
    if (temporary4 != 1)
        goto objects_begin;
    pointer4 = (u8 *)&D_03000010;
    current = *(u32 *)pointer4;
    current = func_080C8BAC(current);
    pointer5 = (u8 *)D_030025A8;
    work1 = current << 3;
    work1 -= current;
    work1 = (u32)work1 >> 15;
    work1 += 117;
    *(s32 *)(pointer5 + 0x14) = work1;
    current = *(u32 *)pointer4;
    current = func_080C8BAC(current);
    work1 = current << 3;
    work1 -= current;
    work1 = (u32)work1 >> 15;
    work1 += 85;
    *(s32 *)(pointer5 + 0x18) = work1;
objects_begin:
    work2 = 0;
    pointer5 = D_0201F6DC;
    asm("" : "+r"(pointer5));
    base = pointer5;
    current = 0x12AC;
    current += (u32)base;
    asm("" : "+r"(current));
    objects = (u8 *)current;
object_loop:
    current = work2 << 2;
    pointer1 = objects;
    asm("" : "+r"(pointer1));
    pointer3 = (u8 *)(current + (u32)pointer1);
    work1 = *(u32 *)pointer3;
    temporary4 = current;
    temporary5 = work2 + 1;
    asm("" : "+r"(temporary5));
    nextSlot = temporary5;
    asm("" : "=r"(object) : "0"(work1));
    if (object == 0)
        goto next_object;
    current = work2 << 4;
    work1 = 0x11AC;
    work1 += (u32)base;
    pointer2 = (u8 *)(current + work1);
    current = *pointer2;
    if (current == 0)
        goto next_object;
    current = *(u16 *)(pointer2 + 4);
    work1 = *(u16 *)(pointer2 + 8);
    current += work1;
    *(u16 *)(pointer2 + 8) = current;
    asm("" : "+r"(pointer2));
    current = *(s16 *)(pointer2 + 8);
    asm volatile("" : : "r"(work1));
    goto object_x_check;
object_x_loop:
    current = pointer2[1];
    if (current == 0) {
        pointer1 = *(u8 **)pointer3;
        current = *(s32 *)(pointer1 + 4);
        temporary5 = 256;
    } else {
        pointer1 = *(u8 **)pointer3;
        current = *(s32 *)(pointer1 + 4);
        temporary5 = -256;
    }
    current += temporary5;
    *(s32 *)(pointer1 + 4) = current;
    current = pointer2[12];
    work1 = *(u16 *)(pointer2 + 8);
    work1 -= current;
    *(u16 *)(pointer2 + 8) = work1;
    current = *(s16 *)(pointer2 + 8);
object_x_check:
    work1 = pointer2[12];
    if (current > work1)
        goto object_x_loop;
    asm("" : "+r"(pointer2));
    current = *(u16 *)(pointer2 + 6);
    work3 = *(u16 *)(pointer2 + 10);
    current += work3;
    *(u16 *)(pointer2 + 10) = current;
    asm("" : "+r"(pointer2));
    current = *(s16 *)(pointer2 + 10);
    asm volatile("" : : "r"(work3));
    if (current <= work1)
        goto object_tick;
    pointer0 = objects;
    pointer3 = (u8 *)(temporary4 + (u32)pointer0);
object_y_loop:
    current = pointer2[2];
    if (current == 0) {
        pointer1 = *(u8 **)pointer3;
        current = *(s32 *)(pointer1 + 8);
        temporary4 = 256;
        current += temporary4;
    } else {
        pointer1 = *(u8 **)pointer3;
        current = *(s32 *)(pointer1 + 8);
        temporary5 = -256;
        asm("" : "+r"(temporary5));
        current += temporary5;
    }
    *(s32 *)(pointer1 + 8) = current;
    current = pointer2[12];
    work1 = *(u16 *)(pointer2 + 10);
    work1 -= current;
    *(u16 *)(pointer2 + 10) = work1;
    asm("" : "=r"(temporary4), "=r"(temporary5));
    current = *(s16 *)(pointer2 + 10);
    asm volatile("" : : "r"(temporary4), "r"(temporary5));
    temporary4 = pointer2[12];
    asm("" : "+r"(temporary4));
    if (current > temporary4)
        goto object_y_loop;
object_tick:
    current = pointer2[13];
    current++;
    work1 = 0;
    pointer2[13] = current;
    asm("" : "+r"(current));
    current = (u8)current;
    temporary5 = pointer2[12];
    asm("" : "+r"(temporary5));
    if ((u32)current >= (u32)temporary5) {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = work1;
    }
next_object:
    work1 = nextSlot;
    asm("" : "+r"(work1));
    current = work1 << 24;
    work2 = (u32)current >> 24;
    if ((u32)work2 <= 15)
        goto object_loop;
    current = 1;
    func_080C8FCC(current);
    goto frame;
}
