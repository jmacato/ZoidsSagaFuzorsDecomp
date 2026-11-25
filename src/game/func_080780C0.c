#include "types.h"

struct Transfer {
    u32 flags;
    u32 source;
    u32 sourceY;
    u32 sourceX;
    u32 sourceXY;
    u32 destination;
    u32 destinationY;
    u32 destinationX;
    u32 destinationXY;
    u8 countX;
    u8 countY;
    u8 width;
    u8 height;
    u8 widths[2];
    u8 heights[2];
};
extern struct Transfer D_030053CC[];
extern u16 D_0300004E[];
u32 func_080C8C80(u32, u32);

u32 func_080780C0(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5)
{
    volatile u32 mapWidth;
    volatile u32 mapHeight;
    register u32 source asm("r12");
    register u32 attributes asm("r9");
    register u32 width asm("r8");
    register u32 height asm("r10");
    register u32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 work3 asm("r3");
    register u32 work4 asm("r4");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register s32 shape asm("r3");
    u32 x, y;
    struct Transfer *transfer;
    u32 size;

    source = arg0;
    current = arg4;
    work4 = arg5;
    work1 = (u8)arg1;
    attributes = work1;
    x = (u16)arg2;
    y = (u16)arg3;
    current = (u16)current;
    width = current;
    work4 = (u16)work4;
    height = work4;
    work2 = 0;
    transfer = D_030053CC;
    current = transfer->flags;
    work1 = 1;
    current &= work1;
    if (current != 0) {
        size = 0x2C;
        pointer1 = (u8 *)transfer;
        work3 = 1;
find_free:
        current = work2 + 1;
        asm("" : "+r"(current));
        work2 = (u8)current;
        if (work2 > 15)
            goto found_free;
        current = work2;
        current *= size;
        transfer = (struct Transfer *)(current + (u32)pointer1);
        current = transfer->flags;
        current &= work3;
        if (current != 0)
            goto find_free;
    }
found_free:
    if (work2 == 16)
        return 0;
    current = 3;
    transfer->flags = current;
    current = source;
    transfer->source = current;
    pointer0 = &transfer->width;
    work1 = width;
    *pointer0 = work1;
    pointer0++;
    asm("" : "+r"(pointer0));
    work2 = height;
    *pointer0 = work2;
    work3 = attributes;
    asm("" : "+r"(work3));
    work1 = work3 << 1;
    pointer2 = (u8 *)D_0300004E;
    asm("" : "+r"(pointer2));
    pointer0 = (u8 *)(work1 + (u32)pointer2);
    current = *(u16 *)pointer0;
    size = 0xC000;
    work3 = size;
    work3 &= current;
    current = 0x4000;
    asm volatile("" : : "r"(current), "r"(work1));
    attributes = work1;
    switch (shape) {
    case 0:
        current = 32;
        mapHeight = current;
        work1 = 32;
        mapWidth = work1;
        break;
    case 0x4000:
        work2 = 64;
        mapWidth = work2;
        work3 = 32;
        mapHeight = work3;
        break;
    case 0x8000:
        current = 32;
        mapWidth = current;
        work1 = 64;
        mapHeight = work1;
        break;
    case 0xC000:
        work2 = 64;
        mapHeight = work2;
        work3 = 64;
        mapWidth = work3;
        break;
    }
    x = (u16)func_080C8C80(x, mapWidth);
    current = y;
    asm("" : "+r"(current));
    y = (u16)func_080C8C80(current, mapHeight);
    pointer0 = (u8 *)D_0300004E;
    pointer0 += attributes;
    work1 = *(u16 *)pointer0;
    current = 0x1F00;
    asm("" : "+r"(current));
    current &= work1;
    current <<= 3;
    work1 = 0x06000000;
    asm("" : "+r"(work1));
    work2 = current + work1;
    transfer->destination = work2;
    if (x <= 31) {
        work1 = x << 1;
        current = work2 + work1;
    } else {
        work1 = x << 1;
        work3 = 0x7C0;
        asm("" : "+r"(work3));
        current = work1 + work3;
        current = work2 + current;
    }
    transfer->destination = current;
    work3 = work1;
    current = mapWidth;
    if (current == 32 || y <= 31) {
        asm("" : "+r"(y));
        work1 = y << 6;
    } else {
        asm("" : "+r"(y));
        work1 = y << 6;
        work2 = 0x800;
        asm("" : "+r"(work2));
        work1 += work2;
    }
    current = transfer->destination;
    current += work1;
    transfer->destination = current;
    work1 = x >> 5;
    work2 = width;
    current = x + work2;
    current = (s32)current >> 5;
    if (work1 != current) {
        if (x <= 31)
            current = 32;
        else
            current = 64;
        current -= x;
        pointer1 = &transfer->widths[0];
        *pointer1 = current;
        current = *pointer1;
        work2 = width;
        current = work2 - current;
        pointer2 = &transfer->widths[1];
        *pointer2 = current;
        work1 = *pointer1;
        work1 <<= 1;
        current = transfer->source;
        current += work1;
        transfer->sourceX = current;
        current = mapWidth;
        if (current == 32) {
            current = transfer->destination;
            current -= work3;
        } else if (x <= 31) {
            current = transfer->destination;
            current -= work3;
            work1 = 0x800;
            asm("" : "+r"(work1));
            current += work1;
        } else {
            current = transfer->destination;
            current -= work3;
            work2 = (u32)-0x7C0;
            asm("" : "+r"(work2));
            current += work2;
        }
        transfer->destinationX = current;
        pointer1 = &transfer->countX;
        current = 2;
    } else {
        pointer0 = &transfer->widths[0];
        work3 = width;
        *pointer0 = work3;
        pointer1 = &transfer->countX;
        current = 1;
    }
    *pointer1 = current;
    pointer3 = pointer1;
    work1 = y >> 5;
    work2 = height;
    current = y + work2;
    current = (s32)current >> 5;
    if (work1 == current)
        goto single_y;
    if (y <= 31)
        current = 32;
    else
        current = 64;
    current -= y;
    pointer1 = &transfer->heights[0];
    *pointer1 = current;
    pointer2 = pointer1;
    current = *pointer2;
    work1 = height;
    current = work1 - current;
    pointer1 = &transfer->heights[1];
    *pointer1 = current;
    current = *pointer2;
    work1 = width;
    work1 *= current;
    work1 <<= 1;
    current = transfer->source;
    current += work1;
    transfer->sourceY = current;
    current = mapHeight;
    if (current == 32) {
        asm("" : "+r"(y));
        work1 = y << 6;
        current = transfer->destination;
        current -= work1;
    } else {
        work1 = mapWidth;
        if (work1 == 32) {
            if (y <= 31) {
                asm("" : "+r"(y));
                work1 = y << 6;
                current = transfer->destination;
                current -= work1;
                work1 = 0x800;
                asm("" : "+r"(work1));
            } else {
                work1 = y;
                work1 -= 32;
                work1 <<= 6;
                current = transfer->destination;
                current -= work1;
                work1 = (u32)-0x800;
                asm("" : "+r"(work1));
            }
        } else if (y <= 31) {
            asm("" : "+r"(y));
            work1 = y << 6;
            current = transfer->destination;
            current -= work1;
            work1 = 0x1000;
            asm("" : "+r"(work1));
        } else {
            work1 = y;
            work1 -= 32;
            work1 <<= 6;
            current = transfer->destination;
            current -= work1;
            work1 = (u32)-0x1000;
            asm("" : "+r"(work1));
        }
        current += work1;
    }
    transfer->destinationY = current;
    pointer1 = &transfer->countY;
    current = 2;
    *pointer1 = current;
    current = *pointer3;
    if (current != 2)
        goto done;
    current = *pointer2;
    work1 = width;
    work1 *= current;
    work1 <<= 1;
    current = transfer->sourceX;
    current += work1;
    transfer->sourceXY = current;
    work2 = mapHeight;
    if (work2 == 32) {
        asm("" : "+r"(y));
        work1 = y << 6;
        current = transfer->destinationX;
        current -= work1;
        transfer->destinationXY = current;
        goto done;
    }
    work3 = mapWidth;
    if (work3 == 32) {
        if (y <= 31) {
            asm("" : "+r"(y));
            work1 = y << 6;
            current = transfer->destinationX;
            current -= work1;
            work1 = 0x800;
            asm("" : "+r"(work1));
            goto set_xy;
        }
        asm("" : "+r"(y));
        work1 = y << 6;
        current = transfer->destinationX;
        current -= work1;
        work2 = (u32)-0x800;
        asm("" : "+r"(work2));
        current += work2;
        transfer->destinationXY = current;
        goto done;
    }
    if (y <= 31) {
        asm("" : "+r"(y));
        work1 = y << 6;
        current = transfer->destinationX;
        current -= work1;
        work3 = 0x1000;
        asm("" : "+r"(work3));
        current += work3;
        transfer->destinationXY = current;
        goto done;
    }
    asm("" : "+r"(y));
    work1 = y << 6;
    current = transfer->destinationX;
    current -= work1;
    work1 = (u32)-0x1000;
    asm("" : "+r"(work1));
set_xy:
    current += work1;
    transfer->destinationXY = current;
    goto done;
single_y:
    pointer0 = &transfer->heights[0];
    work2 = height;
    *pointer0 = work2;
    pointer1 = &transfer->countY;
    current = 1;
    *pointer1 = current;
done:
    return 1;
}
