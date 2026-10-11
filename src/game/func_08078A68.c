#include "types.h"

extern u8 *D_030056B0;
extern u8 D_030056B6;
extern u8 D_02000000[];
extern u8 D_02000A00[];
void func_080C8B78(const void *, void *, u32);

void func_08078A68(void)
{
    volatile u32 fill;
    volatile s32 minimum;
    volatile s32 maximum;
    volatile u32 next;
    volatile s32 step;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *points asm("r8");
    register u8 *scratch asm("r10");
    register u32 xDirection asm("r12");
    register u32 yDirection asm("r9");
    register s32 dx asm("r6");
    register s32 dy asm("r4");
    register s32 error asm("r5");
    u32 nextPoint;
    register s32 temporary asm("r7");
    register u8 *pointer7 asm("r7");
    register u8 *destination asm("r4");
    register u8 *nextRow asm("r9");
    register u32 packed asm("r12");
    register u32 empty asm("r10");
    register u32 row asm("r5");
    register u32 interval asm("r7");
    register u32 left asm("r6");
    register u32 oldLeft asm("r5");
    s32 direction;
    s32 count;
    s32 maximumRow;
    u32 index;
    register u32 initialIndex asm("r5") = 0;
    register u32 initialOne asm("r4");
    u8 *rows;
    u8 *flip;
    u32 one;

    asm("" : "=r"(index) : "0"(initialIndex));
    pointer0 = (u8 *)&D_030056B0;
    points = pointer0;
    rows = D_02000000;
    flip = &D_030056B6;
    initialOne = 1;
    asm("" : "=r"(one) : "0"(initialOne));
    work3 = -1;
clear:
    work2 = index << 3;
    current = *flip;
    work1 = one;
    work1 ^= current;
    current = work1 << 2;
    current += work1;
    current <<= 8;
    work2 += current;
    work2 += (u32)rows;
    *(u32 *)work2 = work3;
    index++;
    if (index <= 159)
        goto clear;
    pointer1 = points;
    pointer1 = *(u8 **)pointer1;
    points = pointer1;
    current = *(s16 *)pointer1;
    if (current == 0)
        return;
polygon:
    current = 0xFF00FF00;
    fill = current;
    pointer0 = (u8 *)&fill;
    pointer1 = D_02000A00;
    work2 = 0x01000050;
    func_080C8B78(pointer0, pointer1, work2);
    error = 0;
    pointer3 = points;
    asm("" : "=r"(dy), "=r"(dx));
    current = *(s16 *)pointer3;
    asm volatile("" : : "r"(work1), "r"(work2), "r"(dy), "r"(dx));
    if ((u32)error >= (u32)current)
        goto merge;
    pointer1 = D_02000A00;
    asm("" : "+r"(pointer1));
    scratch = pointer1;
edge:
    current--;
    nextPoint = 0;
    work2 = error + 1;
    next = work2;
    if ((u32)error < (u32)current)
        nextPoint = work2;
    current = error << 2;
    current += (u32)points;
    asm("" : "=r"(work1), "=r"(dy), "=r"(dx));
    work2 = *(s16 *)(current + 2);
    asm volatile("" : : "r"(work1));
    work1 = *(s16 *)(current + 4);
    asm volatile("" : : "r"(dy), "r"(dx));
    current = nextPoint << 2;
    current += (u32)points;
    asm("" : "=r"(dy));
    dx = *(s16 *)(current + 2);
    asm volatile("" : : "r"(dy));
    dy = *(s16 *)(current + 4);
    if (error == 0) {
        if (work1 < 0) {
            current = 0;
            maximum = current;
            work3 = 0;
            minimum = work3;
        } else if (work1 > 159) {
            current = 159;
            maximum = current;
            work3 = 159;
            minimum = work3;
        } else {
            maximum = work1;
            minimum = work1;
        }
    }
    if (work2 == dx && work1 == dy)
        goto next_edge;
    if (dx >= work2) {
        dx -= work2;
        current = 0;
        xDirection = current;
    } else {
        dx = work2 - dx;
        work3 = 1;
        xDirection = work3;
    }
    if (dy >= work1) {
        if (nextPoint != 0) {
            temporary = maximum;
            if (dy > temporary) {
                current = 159;
                maximum = current;
                if (dy <= 159)
                    maximum = dy;
            }
        }
        dy -= work1;
        work3 = 0;
    } else {
        if (nextPoint != 0) {
            temporary = minimum;
            if (dy < temporary) {
                current = 0;
                minimum = current;
                if (dy >= 0)
                    minimum = dy;
            }
        }
        dy = work1 - dy;
        work3 = 1;
    }
    yDirection = work3;
    error = 0;
    if (dx < dy)
        goto vertical;
    if (dy != 0)
        goto horizontal;
    if ((u32)work1 > 159)
        goto next_edge;
    current = work1 << 1;
    pointer7 = scratch;
    pointer3 = (u8 *)(current + (u32)pointer7);
    current = xDirection;
    asm("" : "+r"(current));
    if (current == 0) {
        current = work2;
        if (current < 0)
            current = 0;
        else if (current > 239)
            current = 239;
        current <<= 8;
        *(u16 *)pointer3 = current;
        current = work2 + dx;
        if (current < 0)
            goto right_zero;
        goto clamp_right;
    }
    current = work2 - dx;
    if (current < 0)
        current = 0;
    else if (current > 239)
        current = 239;
    current <<= 8;
    *(u16 *)pointer3 = current;
    current = work2;
    if (current >= 0)
        goto clamp_right;
right_zero:
    current = 0;
    goto store_right;
clamp_right:
    if (current > 239)
        current = 239;
store_right:
    current++;
    work1 = *(u16 *)pointer3;
    current |= work1;
    *(u16 *)pointer3 = current;
    goto next_edge;
horizontal:
    current = work1 << 1;
    pointer7 = scratch;
    pointer3 = (u8 *)(current + (u32)pointer7);
    current = 0;
    step = current;
    if (error >= dx)
        goto next_edge;
horizontal_loop:
    if ((u32)work1 <= 159) {
        current = work2;
        if (current < 0)
            current = 0;
        else if (current > 239)
            current = 239;
        temporary = pointer3[1];
        if (current < temporary)
            pointer3[1] = current;
        temporary = pointer3[0];
        if (current >= temporary) {
            current++;
            pointer3[0] = current;
        }
    }
    current = xDirection;
    asm("" : "+r"(current));
    if (current == 0)
        work2++;
    else
        work2--;
    error += dy;
    if (error >= dx) {
        asm("" : "=r"(current));
        direction = yDirection;
        if (direction == 0) {
            if (work1 > 158)
                goto next_edge;
            work1++;
            pointer3 += 2;
        } else {
            if (work1 <= 0)
                goto next_edge;
            work1--;
            pointer3 -= 2;
        }
        asm volatile("" : : "r"(current));
        error -= dx;
    }
    current = step;
    current++;
    step = current;
    if (current < dx)
        goto horizontal_loop;
    goto next_edge;
vertical:
    current = work1 << 1;
    pointer7 = scratch;
    pointer3 = (u8 *)(current + (u32)pointer7);
    current = 0;
    goto vertical_check;
vertical_forward:
    work1++;
    pointer3 += 2;
    goto vertical_error;
vertical_reverse:
    if (work1 <= 0)
        goto next_edge;
    work1--;
    pointer3 -= 2;
vertical_error:
    error += dx;
    if (error >= dy) {
        asm("" : "=r"(current));
        direction = xDirection;
        if (direction == 0)
            work2++;
        else
            work2--;
        asm volatile("" : : "r"(current));
        error -= dy;
    }
    current = step;
    current++;
vertical_check:
    step = current;
    temporary = step;
    if (temporary >= dy)
        goto next_edge;
    if ((u32)work1 <= 159) {
        current = work2;
        if (current < 0)
            current = 0;
        else if (current > 239)
            current = 239;
        temporary = pointer3[1];
        if (current < temporary)
            pointer3[1] = current;
        temporary = pointer3[0];
        if (current >= temporary) {
            current++;
            pointer3[0] = current;
        }
    }
    current = yDirection;
    if (current != 0)
        goto vertical_reverse;
    if (work1 <= 158)
        goto vertical_forward;
next_edge:
    error = next;
    pointer1 = points;
    current = *(s16 *)pointer1;
    if ((u32)error < (u32)current)
        goto edge;
merge:
    pointer0 = &D_030056B6;
    work1 = *pointer0;
    current = 1;
    current ^= work1;
    work2 = current << 2;
    work2 += current;
    work2 <<= 8;
    work3 = minimum;
    current = work3 << 3;
    pointer1 = D_02000000;
    current += (u32)pointer1;
    destination = (u8 *)(work2 + current);
    work1 = work3 << 1;
    pointer0 = D_02000A00;
    pointer3 = (u8 *)(work1 + (u32)pointer0);
    row = minimum;
    asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(dx));
    maximumRow = maximum;
    asm volatile("" : : "r"(current), "r"(work1), "r"(work2), "r"(dx));
    if (row > (u32)maximumRow)
        goto advance_polygon;
    current = 0xFFFF;
    asm("" : "+r"(current));
    empty = current;
merge_row:
    interval = 0;
    current = *(u16 *)pointer3;
    work1 = current;
    row++;
    next = row;
    packed = current;
    pointer2 = pointer3 + 2;
    asm("" : "+r"(pointer2));
    nextRow = pointer2;
    current = 0xFF00;
    if (work1 == current || work1 == 1)
        goto merged;
    current = 0xEFF0;
    if (work1 == current)
        goto merged;
    current = *(u16 *)destination;
    if ((u32)current != empty)
        goto compare_interval;
    work1 = packed;
    *(u16 *)destination = work1;
    goto merged;
replace_interval:
    work2 = packed;
    *(u16 *)destination = work2;
    goto merged;
extend_right:
    destination[0] = work1;
    goto merged;
extend_left:
    destination[1] = left;
    goto merged;
compare_interval:
    left = pointer3[1];
    oldLeft = destination[1];
    work2 = left;
    work1 = pointer3[0];
    current = destination[0];
    if (oldLeft <= (u32)work2 && (u32)work1 <= (u32)current)
        goto merged;
    if ((u32)work2 <= oldLeft && (u32)current <= (u32)work1)
        goto replace_interval;
    if ((u32)work2 <= (u32)current && (u32)work1 > (u32)current)
        goto extend_right;
    if ((u32)work1 >= oldLeft && (u32)work2 < oldLeft)
        goto extend_left;
    destination += 2;
    interval++;
    if (interval > 1)
        goto merged;
    current = *(u16 *)destination;
    if ((u32)current != empty)
        goto compare_interval;
    work3 = packed;
    *(u16 *)destination = work3;
merged:
    current = 4;
    current -= interval;
    current <<= 1;
    destination += current;
    pointer3 = nextRow;
    row = next;
    asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(dx));
    maximumRow = maximum;
    asm volatile("" : : "r"(current), "r"(work1), "r"(work2), "r"(dx));
    if (row <= (u32)maximumRow)
        goto merge_row;
advance_polygon:
    pointer1 = points;
    asm("" : "=r"(work3), "=r"(dy), "=r"(error));
    count = *(s16 *)pointer1;
    asm("" : "=r"(current) : "0"(count));
    asm volatile("" : : "r"(work3), "r"(dy), "r"(error), "r"(maximumRow));
    current <<= 2;
    current += 2;
    points += current;
    pointer3 = points;
    asm("" : "=r"(work1), "=r"(work2), "=r"(dy), "=r"(dx), "=r"(error));
    current = *(s16 *)pointer3;
    asm volatile("" : : "r"(work1), "r"(work2), "r"(dy), "r"(dx), "r"(error));
    if (current != 0)
        goto polygon;
}
