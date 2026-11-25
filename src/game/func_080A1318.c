#include "types.h"

extern u8 D_02036E7C[];
extern u8 *D_02030B4C[];
extern s32 D_08735868[];
extern u8 D_03000060[];
u32 func_080A0B54(void);
void func_080A12B0(u32, u32);
u32 func_08075AAC(s32);
u32 func_08075AF8(s32);

register volatile s32 work2 asm("r2");

void func_080A1318(void)
{
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    s32 speed;
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    register u8 *pointer7 asm("r7");

    pointer1 = D_02036E7C;
    current = 0x8A4;
    pointer3 = pointer1 + current;
    work2 = *pointer3;
    current = 0x80;
    current &= work2;
    pointer4 = pointer1;
    if (current != 0)
        goto done;
    if (work2 == 19)
        goto done;
    work1 = 0x8F5;
    pointer0 = pointer4 + work1;
    current = *(volatile u8 *)pointer0;
    speed = 0x200;
    if (current != 13)
        speed = 0x80;
    current = *pointer3;
    current--;
    switch ((u32)current) {
    case 14:
        work2 = 0x200;
        speed += work2;
    case 0:
        pointer0 = D_02036E7C;
        work4 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer1 = pointer0 + work4;
        *(s32 *)pointer1 = speed;
        work5 = 0x8B4;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 += work5;
        work1 = -speed;
        {
            *(s32 *)pointer0 = work1;
        }
        goto update;
    case 15:
        current = 0x200;
        {
            register union {
                s32 word;
                u16 half;
            } guard asm("r0");
            guard.half = (u16)current;
            current = guard.word;
        }
        speed += current;
    case 1:
        pointer6 = D_02036E7C;
        work1 = 0x8B0;
        pointer0 = pointer6 + work1;
        {
            *(s32 *)pointer0 = speed;
        }
        work2 = 0x8B4;
        pointer1 = pointer6 + work2;
        current = -speed;
        *(s32 *)pointer1 = current;
        work4 = 0x8A8;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer5 = pointer6 + work4;
        work3 = 0x1000;
        current = -0x1000;
        work1 = *(s32 *)pointer5;
        if (work1 >= current)
            goto ease_out;
        work2 -= 0xB4;
        current = work1 + work2;
        *(s32 *)pointer5 = current;
        work5 = 0x8AC;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer1 = pointer6 + work5;
        current = *(s32 *)pointer1;
        current += work2;
        *(s32 *)pointer1 = current;
        goto update;
    ease_out:
        current = 0x8AC;
        pointer7 = pointer6 + current;
        current = work3 - work1;
        work4 = current;
        if (current < 0)
            current += 3;
        work2 = current >> 2;
        current = *(s32 *)pointer7;
        current += work2;
        *(s32 *)pointer7 = current;
        work1 += work2;
        *(s32 *)pointer5 = work1;
        current = work3;
        current -= 0x80;
        if (work1 <= current)
            goto update;
        *(s32 *)pointer5 = work3;
        work1 = 0x8A4;
        pointer0 = pointer6 + work1;
        current = *pointer0;
        if (current == 2)
            goto guarded_finish_one;
        current = 15;
        goto finish;
    case 2:
        work3 = 0x1000;
        pointer2 = D_02036E7C;
        work5 = 0x8AC;
        pointer4 = pointer2 + work5;
        current = 0x8A8;
        pointer5 = pointer2 + current;
        work1 = *(s32 *)pointer5;
        work3 -= work1;
        current = *(s32 *)pointer4;
        current += work3;
        *(s32 *)pointer4 = current;
        work1 += work3;
        *(s32 *)pointer5 = work1;
        work1 = 0x8B0;
        pointer0 = pointer2 + work1;
        {
            *(s32 *)pointer0 = speed;
        }
        work4 = 0x8B4;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer2 += work4;
        current = -speed;
        {
            *(s32 *)pointer2 = current;
        }
        goto finish_one;
    case 3:
        work5 = 0x8C0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 = pointer4 + work5;
        work3 = *(s32 *)pointer0;
        current = 0x8FFF;
        if (work3 > current)
            goto fixed_target;
        current = -0x9000;
        {
            register union {
                s32 word;
                u16 half;
            } guard asm("r0");
            guard.half = (u16)current;
            current = guard.word;
        }
        work3 += current;
        work1 = 0x8AC;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        pointer6 = pointer4 + work1;
        work2 = 0x8A8;
        pointer7 = pointer4 + work2;
        goto ease_target;
    fixed_target:
        work3 = 0x1000;
        work5 = 0x8AC;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer6 = pointer4 + work5;
        {
            union {
                s32 bits;
                float value;
            } stored;
            register float bound asm("r0");
            stored.bits = 0x8A8;
            bound = stored.value;
            stored.value = bound;
            current = stored.bits;
        }
        pointer7 = pointer4 + current;
    ease_target:
        work5 = *(s32 *)pointer7;
        current = work3 - work5;
        work2 = current;
        if (current < 0)
            current += 7;
        work1 = current >> 3;
        current = *(s32 *)pointer6;
        current += work1;
        *(s32 *)pointer6 = current;
        current = work5 + work1;
        *(s32 *)pointer7 = current;
        {
            union {
                s32 bits;
                float value;
            } stored;
            register float bound asm("r1");
            stored.bits = 0x8A8;
            bound = stored.value;
            stored.value = bound;
            work1 = stored.bits;
        }
        pointer0 = pointer4 + work1;
        work1 = *(s32 *)pointer0;
        if (work1 < work3)
            goto lower_target;
        current = work3;
        current += 0x80;
        if (work1 < current)
            goto snap_target;
        if (work1 <= work3)
            goto lower_target;
        goto update;
    lower_target:
        current = work3;
        current -= 0x80;
        if (work1 <= current)
            goto update;
    snap_target:
        pointer0 = D_02036E7C;
        {
            union {
                s32 bits;
                float value;
            } stored;
            register float bound asm("r2");
            stored.bits = 0x8A8;
            bound = stored.value;
            stored.value = bound;
            work2 = stored.bits;
        }
        pointer0 += work2;
        {
            *(s32 *)pointer0 = work3;
        }
        goto finish_one;
    case 4:
        work5 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 = pointer4 + work5;
        work1 = *pointer0;
        if ((u32)work1 > 1)
            goto backward_step;
        pointer2 = pointer4;
        pointer2 += 0x99;
        current = *pointer2;
        if ((u32)current > 2)
            goto forward_speed;
        pointer0 = pointer4;
        pointer0 += 0x98;
        current = *pointer0;
        if (current != 0)
            goto reflected_forward;
        if (work1 != 0)
            goto forward_small;
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current += 4;
        goto store_forward;
    forward_small:
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current += 2;
        goto store_forward;
    reflected_forward:
        if (work1 != 0)
            goto reflected_forward_small;
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current -= 4;
        goto store_forward;
    reflected_forward_small:
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current -= 2;
    store_forward:
        *(s32 *)(pointer1 + 4) = current;
    forward_speed:
        work1 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        pointer0 = pointer4 + work1;
        {
            *(s32 *)pointer0 = speed;
        }
        goto step_counter;
    backward_step:
        if ((u32)work1 <= 3)
            goto backward_speed;
        pointer2 = pointer4;
        pointer2 += 0x99;
        current = *pointer2;
        if ((u32)current > 2)
            goto backward_speed;
        pointer0 = pointer4;
        pointer0 += 0x98;
        current = *pointer0;
        if (current != 0)
            goto reflected_backward;
        if (work1 != 4)
            goto backward_small;
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current -= 4;
        goto store_backward;
    backward_small:
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current -= 2;
        goto store_backward;
    reflected_backward:
        if (work1 != 4)
            goto reflected_backward_small;
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current += 4;
        goto store_backward;
    reflected_backward_small:
        pointer1 = (u8 *)D_02030B4C;
        current = *pointer2;
        current <<= 2;
        current += (u32)pointer1;
        pointer1 = *(u8 **)current;
        current = *(s32 *)(pointer1 + 4);
        current += 2;
    store_backward:
        *(s32 *)(pointer1 + 4) = current;
    backward_speed:
        work2 = 0x8B0;
        pointer1 = pointer4 + work2;
        work5 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 = pointer4 + work5;
        current = *pointer0;
        current -= 6;
        current <<= 9;
        current += speed;
        *(s32 *)pointer1 = current;
    step_counter:
        pointer1 = D_02036E7C;
        current = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.high = (s32)pointer1;
            pointer1 = (u8 *)guard.part.high;
        }
        pointer1 += current;
        current = *pointer1;
        current++;
        *pointer1 = current;
        current = (u8)current;
        if (current != 6)
            goto update;
        goto finish_one;
    case 5:
        work1 = 0x8A5;
        pointer0 = pointer4 + work1;
        work2 = *pointer0;
        if ((u32)work2 > 16)
            goto finish_one;
        work5 = 0x911;
        pointer0 = pointer4 + work5;
        current = *pointer0;
        if (current == 0)
            goto table_offset;
        if (work2 != 0)
            goto table_offset;
        work1 += 0x2D;
        pointer0 = pointer4 + work1;
        work1 = 1;
        {
            *(u8 *)pointer0 = work1;
        }
        work5 -= 0x3E;
        pointer0 = pointer4 + work5;
        {
            *(u8 *)pointer0 = work2;
        }
    table_offset:
        pointer1 = D_02036E7C;
        current = 0x8B8;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.high = (s32)pointer1;
            pointer1 = (u8 *)guard.part.high;
        }
        pointer3 = pointer1 + current;
        pointer2 = (u8 *)D_08735868;
        work4 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer1 += work4;
        current = *pointer1;
        current = (u32)current >> 1;
        current <<= 2;
        current += (u32)pointer2;
        current = *(s32 *)current;
        {
            union {
                s32 bits;
                float value;
            } stored;
            stored.bits = current;
            *(float *)pointer3 = stored.value;
        }
        goto advance_counter;
    case 6:
        current = func_080A0B54();
        current <<= 24;
        if (current == 0)
            goto update;
        pointer2 = D_02036E7C;
        work5 = 0x8A8;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 = pointer2 + work5;
        work1 = *(s32 *)pointer0;
        current = 0x10000;
        if (work1 <= current)
            goto accelerate;
        current = 0x8B0;
        pointer1 = pointer2 + current;
        current -= 0xB0;
        *(s32 *)pointer1 = current;
        current = 0;
        work1 = 0;
        func_080A12B0(current, work1);
        goto vertical_speed;
    accelerate:
        work4 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer1 = pointer2 + work4;
        work2 = *(s32 *)pointer1;
        current = 0xFFF;
        if (work2 > current)
            goto vertical_speed;
        current = work2;
        current += 0x20;
        *(s32 *)pointer1 = current;
    vertical_speed:
        pointer0 = D_02036E7C;
        work5 = 0x8B4;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer2 = pointer0 + work5;
        work1 = *(s32 *)pointer2;
        current = -0x800;
        if (work1 <= current)
            goto update;
        current = work1;
        current -= 0x40;
        {
            *(s32 *)pointer2 = current;
        }
        goto update;
    case 7:
        work1 = 0x8A5;
        pointer0 = pointer4 + work1;
        work2 = *pointer0;
        if ((u32)work2 > 16)
            goto return_offset;
        work5 = 0x911;
        pointer0 = pointer4 + work5;
        current = *pointer0;
        if (current == 0)
            goto return_table;
        if (work2 != 0)
            goto return_table;
        work1 += 0x2D;
        pointer0 = pointer4 + work1;
        work1 = 1;
        {
            *(u8 *)pointer0 = work1;
        }
        work5 -= 0x3E;
        pointer0 = pointer4 + work5;
        {
            *(u8 *)pointer0 = work2;
        }
    return_table:
        pointer1 = D_02036E7C;
        current = 0x8B8;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.high = (s32)pointer1;
            pointer1 = (u8 *)guard.part.high;
        }
        pointer3 = pointer1 + current;
        pointer2 = (u8 *)D_08735868;
        work4 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer1 += work4;
        current = *pointer1;
        current = (u32)current >> 1;
        current <<= 2;
        current += (u32)pointer2;
        current = *(s32 *)current;
        *(s32 *)pointer3 = current;
        goto advance_counter;
    return_offset:
        if (work2 != 17)
            goto ease_return;
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer1 = pointer4 + work5;
        work2 = -0x800;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r1");
            guard.part.low = (s32)pointer1;
            pointer1 = (u8 *)guard.part.low;
        }
        current = speed + work2;
        goto store_return;
    ease_return:
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer1 = pointer4 + work5;
        current = *(s32 *)pointer1;
        current += 0x80;
    store_return:
        *(s32 *)pointer1 = current;
        pointer1 = D_02036E7C;
        current = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.high = (s32)pointer1;
            pointer1 = (u8 *)guard.part.high;
        }
        pointer2 = pointer1 + current;
        current = *pointer2;
        current++;
        *pointer2 = current;
        work2 = 0x8B0;
        pointer1 += work2;
        current = *(s32 *)pointer1;
        if (current != speed)
            goto update;
        asm volatile("" : : "r"(work2));
        goto finish_one;
    case 8:
        work5 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 = pointer4 + work5;
        work2 = *pointer0;
        if ((u32)work2 > 16)
            goto finish_one;
        work1 = 0x911;
        pointer0 = pointer4 + work1;
        current = *pointer0;
        if (current == 0)
            goto object_offset;
        if (work2 != 0)
            goto object_offset;
        work5 += 0x2D;
        pointer0 = pointer4 + work5;
        work1 = 1;
        {
            *(u8 *)pointer0 = work1;
        }
        work1 = 0x8D3;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        pointer0 = pointer4 + work1;
        {
            *(u8 *)pointer0 = work2;
        }
    object_offset:
        pointer1 = D_02036E7C;
        pointer0 = pointer1;
        pointer0 += 0x94;
        pointer3 = *(u8 **)pointer0;
        pointer2 = (u8 *)D_08735868;
        work4 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer1 += work4;
        current = *pointer1;
        current = (u32)current >> 1;
        current <<= 2;
        current += (u32)pointer2;
        current = *(s32 *)current;
        if (current < 0)
            current += 255;
        current >>= 8;
        *(u16 *)(pointer3 + 12) = current;
    advance_counter:
        current = *pointer1;
        current++;
        *pointer1 = current;
        goto update;
    case 9:
        pointer4 = D_02036E7C;
        {
            union {
                s32 bits;
                float value;
            } stored;
            register float bound asm("r0");
            stored.bits = 0x8A5;
            bound = stored.value;
            stored.value = bound;
            current = stored.bits;
        }
        pointer5 = pointer4 + current;
        current = *pointer5;
        if ((u32)current > 59)
            goto curve;
        work1 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        pointer2 = pointer4 + work1;
        work1 = 0x400;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        current = speed + work1;
        work1 = *(s32 *)pointer2;
        if (work1 >= current)
            goto curve_vertical;
        current = work1;
        current += 0x80;
        {
            *(s32 *)pointer2 = current;
        }
    curve_vertical:
        work2 = 0x8B4;
        pointer1 = pointer4 + work2;
        current = -speed;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.high = (s32)pointer1;
            pointer1 = (u8 *)guard.part.high;
        }
        work4 = -0x400;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        current += work4;
        work2 = *(s32 *)pointer1;
        if (work2 <= current)
            goto curve_counter;
        current = work2;
        current -= 0x20;
        *(s32 *)pointer1 = current;
        goto curve_counter;
    curve:
        if ((u32)current > 123)
            goto curve_done;
        current = *pointer5;
        current -= 60;
        current <<= 1;
        current = func_08075AAC(current);
        work1 = 0x8B0;
        pointer2 = pointer4 + work1;
        current = (s16)current;
        work1 = current << 2;
        work1 += current;
        current = work1 << 4;
        current -= work1;
        if (current < 0)
            current += 63;
        current >>= 6;
        work4 = -0x400;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        current += work4;
        current = speed - current;
        {
            *(s32 *)pointer2 = current;
        }
    curve_counter:
        current = *pointer5;
        current++;
        *pointer5 = current;
        goto update;
    curve_done:
        work5 = 0x8A8;
        pointer1 = pointer4 + work5;
        current = 0x1000;
        *(s32 *)pointer1 = current;
        current = 0x8B0;
        pointer1 = pointer4 + current;
        work2 = 0x400;
        current = speed + work2;
        *(s32 *)pointer1 = current;
        current = 0;
        goto finish;
    case 10:
        pointer0 = D_02036E7C;
        work4 = 0x8A5;
        pointer3 = pointer0 + work4;
        work2 = *pointer3;
        if (work2 != 0)
            goto lower_speed;
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 += work5;
        work1 = *(s32 *)pointer0;
        work4 -= 0xA5;
        goto start_delta;
    lower_speed:
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer1 = pointer0 + work5;
        current = *(s32 *)pointer1;
        work2 = -0x100;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r1");
            guard.part.low = (s32)pointer1;
            pointer1 = (u8 *)guard.part.low;
        }
        current += work2;
        *(s32 *)pointer1 = current;
        if (current != speed)
            goto update;
        goto guarded_finish_one;
    case 11:
        pointer0 = D_02036E7C;
        work4 = 0x8A5;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer3 = pointer0 + work4;
        work2 = *pointer3;
        if (work2 != 0)
            goto raise_speed;
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 += work5;
        work1 = *(s32 *)pointer0;
        work4 = -0x200;
    start_delta:
        work1 += work4;
        {
            *(s32 *)pointer0 = work1;
        }
        current = work2 + 1;
        *pointer3 = current;
        goto update;
    raise_speed:
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer1 = pointer0 + work5;
        current = *(s32 *)pointer1;
        current += 0x10;
        *(s32 *)pointer1 = current;
        if (current != speed)
            goto update;
        goto finish_one;
    case 12:
        pointer5 = D_02036E7C;
        {
            union {
                s32 bits;
                float value;
            } stored;
            register float bound asm("r0");
            stored.bits = 0x8A5;
            bound = stored.value;
            stored.value = bound;
            current = stored.bits;
        }
        pointer4 = pointer5 + current;
        current = *pointer4;
        if ((u32)current > 36)
            goto finish_one;
        work1 = current;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        current = work1 << 1;
        current += work1;
        current <<= 1;
        current = func_08075AF8(current);
        work2 = 0x8B0;
        pointer1 = pointer5 + work2;
        current <<= 16;
        current >>= 13;
        current = speed - current;
        *(s32 *)pointer1 = current;
        current = *pointer4;
        current++;
        *pointer4 = current;
        goto update;
    case 13:
        pointer2 = D_02036E7C;
        work4 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer0 = pointer2 + work4;
        work3 = 0;
        {
            *(s32 *)pointer0 = work3;
        }
        work5 = 0x8A8;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer0 = pointer2 + work5;
        work1 = *(s32 *)pointer0;
        current = 0xFFF;
        if (work1 > current)
            goto stop_vertical;
        current = 0x8B4;
        pointer1 = pointer2 + current;
        current -= 0xB4;
        *(s32 *)pointer1 = current;
        goto update;
    stop_vertical:
        work1 = 0x8B4;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r0");
            guard.part.low = current;
            current = guard.part.low;
        }
        pointer0 = pointer2 + work1;
        {
            *(s32 *)pointer0 = work3;
        }
        current = 0;
        goto finish;
    case 16:
        pointer2 = D_02036E7C;
        work4 = 0x8A8;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer0 = pointer2 + work4;
        work1 = *(s32 *)pointer0;
        current = -0x10000;
        if (work1 <= current)
            goto restore_speed;
        work5 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r5");
            guard.part.high = (s32)pointer6;
            pointer6 = (u8 *)guard.part.high;
        }
        pointer1 = pointer2 + work5;
        work2 = -0x800;
        current = speed + work2;
        *(s32 *)pointer1 = current;
        goto update;
    restore_speed:
        work4 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer0 = pointer2 + work4;
        {
            *(s32 *)pointer0 = speed;
        }
    guarded_finish_one:
        asm volatile("" : "+r"(work4));
    finish_one:
        current = 1;
    finish:
        work1 = 0;
        func_080A12B0(current, work1);
        goto update;
    case 17:
        pointer1 = D_02036E7C;
        work5 = 0x8B4;
        pointer3 = pointer1 + work5;
        work2 = *(s32 *)pointer3;
        current = -0x800;
        if (work2 <= current)
            goto finish_zero;
        work4 = 0x8B0;
        {
            register union {
                unsigned long long whole;
                struct {
                    s32 low, high;
                } part;
            } guard asm("r4");
            guard.part.high = work5;
            work5 = guard.part.high;
        }
        pointer0 = pointer1 + work4;
        work1 = *(s32 *)pointer0;
        work1 += 0x40;
        {
            *(s32 *)pointer0 = work1;
        }
        current = work2;
        current -= 0x40;
        *(s32 *)pointer3 = current;
        goto update;
    finish_zero:
        current = 0;
        work1 = 0;
        func_080A12B0(current, work1);
        break;
    }
update:
    pointer4 = D_02036E7C;
    work5 = 0x8A8;
    {
        register union {
            unsigned long long whole;
            struct {
                s32 low, high;
            } part;
        } guard asm("r5");
        guard.part.high = (s32)pointer6;
        pointer6 = (u8 *)guard.part.high;
    }
    pointer3 = pointer4 + work5;
    work1 = 0x8B0;
    pointer0 = pointer4 + work1;
    work2 = 0x8B4;
    pointer1 = pointer4 + work2;
    current = *(s32 *)pointer0;
    work2 = *(s32 *)pointer1;
    current += work2;
    work1 = *(s32 *)pointer3;
    work5 = work1 + current;
    *(s32 *)pointer3 = work5;
    current = 0x8AC;
    {
        register union {
            unsigned long long whole;
            struct {
                s32 low, high;
            } part;
        } guard asm("r0");
        guard.part.high = (s32)pointer1;
        pointer1 = (u8 *)guard.part.high;
    }
    pointer1 = pointer4 + current;
    current = *(s32 *)pointer1;
    work3 = current + work2;
    *(s32 *)pointer1 = work3;
    pointer0 = pointer4;
    pointer0 += 0x98;
    current = *pointer0;
    if (current != 0)
        goto reflected_output;
    pointer1 = D_03000060;
    work2 = 0x8B8;
    pointer0 = pointer4 + work2;
    current = *(s32 *)pointer0;
    current = work5 + current;
    *(s32 *)pointer1 = current;
    work5 = 0x8BC;
    pointer0 = pointer4 + work5;
    current = *(s32 *)pointer0;
    current = work3 + current;
    *(s32 *)(pointer1 + 0x10) = current;
    goto done;
reflected_output:
    pointer2 = D_03000060;
    work1 = 0x8B8;
    pointer0 = pointer4 + work1;
    current = *(s32 *)pointer0;
    work1 = 0x1000;
    current = work1 - current;
    current -= work5;
    *(s32 *)pointer2 = current;
    work5 = 0x8BC;
    pointer0 = pointer4 + work5;
    current = *(s32 *)pointer0;
    work1 -= current;
    work1 -= work3;
    *(s32 *)(pointer2 + 0x10) = work1;
done:
    return;
}
