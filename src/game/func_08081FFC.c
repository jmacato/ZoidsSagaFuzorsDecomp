#include "types.h"

u16 func_08081F04(u32, s32, s32);
s32 func_08081FB0(u32, u32, s32, s32);
u32 func_08082E58(u8 *);

#define BIND(value) asm("" : "+r"(value))
#define TILE3 current = func_08081F04(current, work1, work2)
#define TILE4 current = func_08081FB0(current, work1, work2, work3)

void func_08081FFC(u8 *argument)
{
    volatile struct {
        s32 x;
        s32 y;
        s32 dx;
        s32 dy;
        u32 first;
        u32 middle;
        u32 last;
    } local;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    register u8 *record asm("r6");
    s32 work7;
    register u8 *pointer0 asm("r0");
    register u32 fraction8 asm("r8");
    register s32 tile_x asm("r9");
    register s32 tile_y asm("r10");

    record = argument;
    current = record[3];
    current -= 6;
    current = (u8)current;
    if ((u32)current <= 1)
        goto done;
    work1 = *record;
    current = 4;
    current &= work1;
    if (current != 0)
        goto done;
    current = *(s32 *)(record + 12);
    local.dx = current;
    work1 = *(s32 *)(record + 16);
    local.dy = work1;
    pointer0 = (u8 *)0x020209D8;
    current = pointer0[24];
    work3 = local.dx;
    work2 = work1;
    BIND(work2);
    if (current == 0)
        goto L82508;
    if (work3 == 0)
        goto L82284;
    current = *(s32 *)(record + 4);
    if (work3 <= 0)
        goto L82058;
    work2 = 0x800;
    BIND(work2);
    work2 = current + work2;
    local.x = work2;
    goto L8205E;
L82058:
    work4 = -0x800;
    BIND(work4);
    work4 = current + work4;
    local.x = work4;
L8205E:
    current = *(s32 *)(record + 8);
    local.y = current;
    work1 = local.x;
    work5 = work1 + work3;
    work1 = work5;
    BIND(work1);
    if (work5 >= 0)
        goto L82070;
    work2 = 0xFFF;
    BIND(work2);
    work1 = work5 + work2;
L82070:
    work1 >>= 12;
    tile_x = work1;
    work2 = local.y;
    if (work2 >= 0)
        goto L8207E;
    work3 = 0xFFF;
    BIND(work3);
    work2 += work3;
L8207E:
    work2 >>= 12;
    tile_y = work2;
    current = record[1];
    work2--;
    work1 = tile_x;
    TILE3;
    current = (u16)current;
    local.first = current;
    current = record[1];
    work1 = tile_x;
    work2 = tile_y;
    TILE3;
    current = (u16)current;
    local.middle = current;
    current = record[1];
    work2 = tile_y;
    BIND(work2);
    work2++;
    work1 = tile_x;
    TILE3;
    current = (u16)current;
    local.last = current;
    work4 = 0xFFF;
    BIND(work4);
    current = work4;
    BIND(current);
    work7 = local.y;
    work7 &= current;
    current = 0x7FF;
    BIND(current);
    if ((u32)work7 > (u32)current)
        goto L820CE;
    current = local.middle;
    if (current != 0)
        goto L820E2;
    work1 = local.first;
    if (work1 != 0)
        goto L820E2;
L820CE:
    work2 = local.middle;
    if (work2 != 0)
        goto L820E2;
    current = 0x800;
    BIND(current);
    if ((u32)work7 <= (u32)current)
        goto L82120;
    work3 = local.last;
    if (work3 == 0)
        goto L82120;
L820E2:
    current = *(s32 *)(record + 12);
    if (current <= 0)
        goto L82108;
    current = work5;
    BIND(current);
    if (work5 >= 0)
        goto L820F2;
    work4 = 0xFFF;
    BIND(work4);
    current = work5 + work4;
L820F2:
    current >>= 12;
    current <<= 12;
    work1 = local.x;
    goto L8211C;
L82108:
    current = work5;
    BIND(current);
    if (work5 >= 0)
        goto L82112;
    work2 = 0xFFF;
    BIND(work2);
    current = work5 + work2;
L82112:
    current >>= 12;
    current <<= 12;
    work3 = local.x;
    work4 = -0x1000;
    BIND(work4);
    work1 = work3 + work4;
L8211C:
    current -= work1;
    local.dx = current;
L82120:
    work2 = *(s32 *)(record + 16);
    if (work2 > 0)
        goto L821DA;
    current = 0x800;
    BIND(current);
    if ((u32)work7 > (u32)current)
        goto L8218A;
    current = local.first;
    if (current != 0)
        goto L82180;
    work1 = local.middle;
    if (work1 == 0)
        goto L82180;
    work3 = record[1];
    current = *(s32 *)(record + 12);
    work1 = tile_x;
    BIND(work1);
    work1++;
    if (current <= 0)
        goto L82148;
    work1 -= 2;
L82148:
    work2 = tile_y;
    BIND(work2);
    work2--;
    current = work3;
    TILE3;
    current <<= 16;
    if (current != 0)
        goto L82180;
    current = record[20];
    if (current != 2)
        goto L82170;
    work2 = -0xB5;
    local.dy = work2;
    work2 = *(s32 *)(record + 16);
    goto L821D6;
L82170:
    work2 = *(s32 *)(record + 16);
    if (current != 3)
        goto L821D6;
    work3 = -0x16A;
    local.dy = work3;
    goto L821D6;
L82180:
    current = 0x800;
    BIND(current);
    work2 = *(s32 *)(record + 16);
    if ((u32)work7 <= (u32)current)
        goto L821D6;
L8218A:
    work4 = local.middle;
    if (work4 != 0)
        goto L821D6;
    current = local.last;
    if (current == 0)
        goto L821D6;
    current = record[20];
    if (current != 2)
        goto L821B4;
    current = 0x7FF;
    BIND(current);
    work1 = -0xB5;
    local.dy = work1;
    if ((u32)work7 <= (u32)current)
        goto L821D6;
    current = local.y;
    current -= 0xB5;
    goto L821C6;
L821B4:
    if (current != 3)
        goto L821D6;
    current = 0x7FF;
    BIND(current);
    work3 = -0x16A;
    BIND(work3);
    local.dy = work3;
    if ((u32)work7 <= (u32)current)
        goto L821D6;
    work4 = local.y;
    current = work4 + work3;
L821C6:
    work1 = 0xFFF;
    BIND(work1);
    current &= work1;
    work1 = 0x800;
    BIND(work1);
    if (current > work1)
        goto L821D6;
    work1 -= work7;
    local.dy = work1;
L821D6:
    if (work2 < 0)
        goto L8228C;
L821DA:
    current = 0x7FF;
    BIND(current);
    if ((u32)work7 <= (u32)current)
        goto L82238;
    current = local.last;
    if (current != 0)
        goto L82230;
    work1 = local.middle;
    if (work1 == 0)
        goto L82230;
    work3 = record[1];
    current = *(s32 *)(record + 12);
    work1 = tile_x;
    BIND(work1);
    work1++;
    if (current <= 0)
        goto L821FA;
    work1 -= 2;
L821FA:
    work2 = tile_y;
    BIND(work2);
    work2++;
    current = work3;
    TILE3;
    current <<= 16;
    if (current != 0)
        goto L82230;
    current = record[20];
    if (current != 2)
        goto L82224;
    work2 = 0xB5;
    local.dy = work2;
    work2 = *(s32 *)(record + 16);
    goto L82284;
L82224:
    work2 = *(s32 *)(record + 16);
    if (current != 3)
        goto L82284;
    work3 = 0x16A;
    goto L82282;
L82230:
    current = 0x7FF;
    BIND(current);
    work2 = *(s32 *)(record + 16);
    if ((u32)work7 > (u32)current)
        goto L82284;
L82238:
    work4 = local.middle;
    if (work4 != 0)
        goto L82284;
    current = local.first;
    if (current == 0)
        goto L82284;
    current = record[20];
    if (current != 2)
        goto L82260;
    work3 = 0x800;
    BIND(work3);
    work1 = 0xB5;
    local.dy = work1;
    if ((u32)work7 > (u32)work3)
        goto L82284;
    current = local.y;
    current += 0xB5;
    goto L82276;
L82260:
    if (current != 3)
        goto L82284;
    work3 = 0x800;
    BIND(work3);
    work4 = 0x16A;
    BIND(work4);
    local.dy = work4;
    if ((u32)work7 > (u32)work3)
        goto L82284;
    work1 = local.y;
    current = work1 + work4;
L82276:
    work1 = 0xFFF;
    BIND(work1);
    current &= work1;
    work1 = 0x7FF;
    BIND(work1);
    if (current <= work1)
        goto L82284;
    work3 -= work7;
L82282:
    local.dy = work3;
L82284:
    if (work2 == 0)
        goto store_velocity;
L8228C:
    current = *(s32 *)(record + 4);
    work3 = local.dx;
    current += work3;
    local.x = current;
    current = *(s32 *)(record + 8);
    if (work2 <= 0)
        goto L822AC;
    work4 = 0x800;
    BIND(work4);
    work4 = current + work4;
    local.y = work4;
    goto L822B2;
L822AC:
    work1 = -0x800;
    BIND(work1);
    work1 = current + work1;
    local.y = work1;
L822B2:
    work3 = local.y;
    work7 = work3 + work2;
    work1 = local.x;
    if (work1 >= 0)
        goto L822C0;
    work4 = 0xFFF;
    BIND(work4);
    work1 += work4;
L822C0:
    work1 >>= 12;
    tile_x = work1;
    work2 = work7;
    BIND(work2);
    if (work7 >= 0)
        goto L822CE;
    current = 0xFFF;
    BIND(current);
    work2 = work7 + current;
L822CE:
    work2 >>= 12;
    tile_y = work2;
    current = record[1];
    work5 = tile_x;
    BIND(work5);
    work5--;
    work1 = work5;
    TILE3;
    current = (u16)current;
    local.first = current;
    current = record[1];
    work1 = tile_x;
    work2 = tile_y;
    TILE3;
    current = (u16)current;
    local.middle = current;
    current = record[1];
    work4 = tile_x;
    BIND(work4);
    work4++;
    work1 = work4;
    work2 = tile_y;
    TILE3;
    current = (u16)current;
    local.last = current;
    work1 = 0xFFF;
    BIND(work1);
    current = work1;
    BIND(current);
    work2 = local.x;
    fraction8 = work2;
    BIND(fraction8);
    work3 = fraction8;
    work3 &= current;
    BIND(work3);
    fraction8 = work3;
    current = 0x7FF;
    BIND(current);
    if (fraction8 > (u32)current)
        goto L82322;
    current = local.first;
    if (current != 0)
        goto L82336;
L82322:
    work1 = local.middle;
    if (work1 != 0)
        goto L82336;
    current = 0x800;
    BIND(current);
    if (fraction8 <= (u32)current)
        goto L82374;
    work2 = local.last;
    if (work2 == 0)
        goto L82374;
L82336:
    current = *(s32 *)(record + 16);
    if (current <= 0)
        goto L8235C;
    current = work7;
    BIND(current);
    if (work7 >= 0)
        goto L82346;
    work3 = 0xFFF;
    BIND(work3);
    current = work7 + work3;
L82346:
    current >>= 12;
    current <<= 12;
    work1 = local.y;
    goto L82370;
L8235C:
    current = work7;
    BIND(current);
    if (work7 >= 0)
        goto L82366;
    work2 = 0xFFF;
    BIND(work2);
    current = work7 + work2;
L82366:
    current >>= 12;
    current <<= 12;
    work3 = local.y;
    work2 = -0x1000;
    BIND(work2);
    work1 = work3 + work2;
L82370:
    current -= work1;
    local.dy = current;
L82374:
    work3 = *(s32 *)(record + 12);
    if (work3 > 0)
        goto L82432;
    current = 0x800;
    BIND(current);
    if (fraction8 > (u32)current)
        goto L823DE;
    work3 = local.first;
    if (work3 != 0)
        goto L823D4;
    current = local.middle;
    if (current == 0)
        goto L823D4;
    work1 = record[1];
    current = *(s32 *)(record + 16);
    work2 = tile_y;
    BIND(work2);
    work2++;
    if (current <= 0)
        goto L8239C;
    work2 -= 2;
L8239C:
    current = work1;
    work1 = work5;
    TILE3;
    current <<= 16;
    if (current != 0)
        goto L823D4;
    current = record[20];
    if (current != 2)
        goto L823C4;
    work1 = -0xB5;
    local.dx = work1;
    work3 = *(s32 *)(record + 12);
    goto L8242C;
L823C4:
    work3 = *(s32 *)(record + 12);
    if (current != 3)
        goto L8242C;
    work2 = -0x16A;
    local.dx = work2;
    goto L8242C;
L823D4:
    current = 0x800;
    BIND(current);
    work3 = *(s32 *)(record + 12);
    if (fraction8 <= (u32)current)
        goto L8242C;
L823DE:
    current = local.middle;
    if (current != 0)
        goto L8242C;
    work1 = local.last;
    if (work1 == 0)
        goto L8242C;
    current = record[20];
    if (current != 2)
        goto L82408;
    current = 0x7FF;
    BIND(current);
    work2 = -0xB5;
    local.dx = work2;
    if (fraction8 <= (u32)current)
        goto L8242C;
    current = local.x;
    current -= 0xB5;
    goto L8241A;
L82408:
    if (current != 3)
        goto L8242C;
    current = 0x7FF;
    BIND(current);
    work1 = -0x16A;
    BIND(work1);
    local.dx = work1;
    if (fraction8 <= (u32)current)
        goto L8242C;
    work2 = local.x;
    current = work2 + work1;
L8241A:
    work1 = 0xFFF;
    BIND(work1);
    current &= work1;
    work1 = 0x800;
    BIND(work1);
    if (current > work1)
        goto L8242C;
    current = fraction8;
    BIND(current);
    current = work1 - current;
    local.dx = current;
L8242C:
    if (work3 < 0)
        goto store_velocity;
L82432:
    current = 0x7FF;
    BIND(current);
    if (fraction8 <= (u32)current)
        goto L8248E;
    work1 = local.last;
    if (work1 != 0)
        goto L82486;
    work2 = local.middle;
    if (work2 == 0)
        goto L82486;
    work1 = record[1];
    current = *(s32 *)(record + 16);
    work2 = tile_y;
    BIND(work2);
    work2++;
    if (current <= 0)
        goto L82452;
    work2 -= 2;
L82452:
    current = work1;
    work1 = work4;
    TILE3;
    current <<= 16;
    if (current != 0)
        goto L82486;
    current = record[20];
    if (current != 2)
        goto L82478;
    work3 = 0xB5;
    asm volatile("" : : "r"(work3));
    goto store_dx3;
L82478:
    if (current != 3)
        goto store_velocity;
    work4 = 0x16A;
    local.dx = work4;
    goto store_velocity;
L82486:
    current = 0x7FF;
    BIND(current);
    if (fraction8 > (u32)current)
        goto store_velocity;
L8248E:
    current = local.middle;
    if (current != 0)
        goto store_velocity;
    work1 = local.first;
    if (work1 == 0)
        goto store_velocity;
    current = record[20];
    if (current != 2)
        goto L824D4;
    work2 = 0x800;
    BIND(work2);
    work3 = 0xB5;
    local.dx = work3;
    if (fraction8 > (u32)work2)
        goto store_velocity;
    current = local.x;
    current += 0xB5;
    work1 = 0xFFF;
    BIND(work1);
    current &= work1;
    work1 = 0x7FF;
    BIND(work1);
    if (current <= work1)
        goto store_velocity;
    work4 = fraction8;
    BIND(work4);
    work4 = work2 - work4;
    local.dx = work4;
    goto store_velocity;
L824D4:
    if (current != 3)
        goto store_velocity;
    work2 = 0x800;
    BIND(work2);
    current = 0x16A;
    BIND(current);
    local.dx = current;
    if (fraction8 > (u32)work2)
        goto store_velocity;
    work1 = local.x;
    current = work1 + current;
    work1 = 0xFFF;
    BIND(work1);
    current &= work1;
    work1 = 0x7FF;
    BIND(work1);
    if (current <= work1)
        goto store_velocity;
    work3 = fraction8;
    BIND(work3);
    work3 = work2 - work3;
    goto store_dx3;
L82508:
    work4 = local.dx;
    if (work4 == 0)
        goto L82818;
    current = *(s32 *)(record + 4);
    if (work4 <= 0)
        goto L82520;
    work1 = 0x800;
    BIND(work1);
    work1 = current + work1;
    local.x = work1;
    goto L82526;
L82520:
    work2 = -0x800;
    BIND(work2);
    work2 = current + work2;
    local.x = work2;
L82526:
    work4 = *(s32 *)(record + 8);
    local.y = work4;
    current = local.x;
    work5 = current + work3;
    work1 = work5;
    BIND(work1);
    if (work5 >= 0)
        goto L82538;
    work2 = 0x7FF;
    BIND(work2);
    work1 = work5 + work2;
L82538:
    work1 >>= 11;
    tile_x = work1;
    work4 = local.y;
    if (work4 >= 0)
        goto L82546;
    work3 = 0x7FF;
    BIND(work3);
    work4 += work3;
L82546:
    work4 >>= 11;
    current = func_08082E58(record);
    current <<= 24;
    tile_y = work4;
    if (current != 0)
        goto L8255A;
    work4 = 1;
    BIND(work4);
    tile_y += work4;
L8255A:
    current = record[1];
    work1 = record[3];
    work3 = tile_y;
    BIND(work3);
    work3--;
    work2 = tile_x;
    TILE4;
    current = (u16)current;
    local.first = current;
    current = record[1];
    work1 = record[3];
    work2 = tile_x;
    work3 = tile_y;
    TILE4;
    current = (u16)current;
    local.middle = current;
    current = record[1];
    work1 = record[3];
    work4 = tile_y;
    BIND(work4);
    work4++;
    work2 = tile_x;
    work3 = work4;
    TILE4;
    current = (u16)current;
    local.last = current;
    work1 = 0x7FF;
    BIND(work1);
    current = work1;
    BIND(current);
    work7 = local.y;
    work7 &= current;
    work2 = local.first;
    if (work2 != 0)
        goto L825B4;
    work3 = local.middle;
    if (work3 != 0)
        goto L825B4;
    if (work7 == 0)
        goto L825F0;
    current = local.last;
    if (current == 0)
        goto L825F0;
L825B4:
    current = *(s32 *)(record + 12);
    if (current <= 0)
        goto L825D8;
    current = work5;
    BIND(current);
    if (work5 >= 0)
        goto L825C4;
    work1 = 0x7FF;
    BIND(work1);
    current = work5 + work1;
L825C4:
    current >>= 11;
    current <<= 11;
    work2 = local.x;
    current -= work2;
    goto L825EE;
L825D8:
    current = work5;
    BIND(current);
    if (work5 >= 0)
        goto L825E2;
    work3 = 0x7FF;
    BIND(work3);
    current = work5 + work3;
L825E2:
    current >>= 11;
    current <<= 11;
    work2 = local.x;
    work3 = -0x800;
    BIND(work3);
    work1 = work2 + work3;
    current -= work1;
L825EE:
    local.dx = current;
L825F0:
    current = *(s32 *)(record + 16);
    if (current > 0)
        goto L826EC;
    if (work7 == 0)
        goto L82670;
    current = local.first;
    if (current != 0)
        goto L826E4;
    work1 = local.middle;
    if (work1 != 0)
        goto L82670;
    work2 = local.last;
    if (work2 == 0)
        goto L82670;
    current = record[20];
    if (current != 2)
        goto L82640;
    current = 0x3FF;
    work3 = -0xB5;
    local.dy = work3;
    if ((u32)work7 > (u32)current)
        goto L826E4;
    current = local.y;
    current -= 0xB5;
    work1 = 0x7FF;
    current &= work1;
    work1 = 0x400;
    if (current <= work1)
        goto L826E4;
    current = -work7;
    local.dy = current;
    goto L826E4;
L82640:
    if (current != 3)
        goto L826E4;
    current = 0x3FF;
    work1 = -0x16A;
    local.dy = work1;
    if ((u32)work7 > (u32)current)
        goto L826E4;
    work2 = local.y;
    current = work2 + work1;
    work1 = 0x7FF;
    current &= work1;
    work1 = 0x400;
    if (current <= work1)
        goto L826E4;
    work3 = -work7;
    goto L826E2;
L82670:
    current = local.first;
    if (current != 0)
        goto L826E4;
    work1 = local.middle;
    if (work1 == 0)
        goto L826E4;
    current = record[1];
    work1 = record[3];
    work5 = tile_y;
    work5 -= 2;
    work2 = tile_x;
    work3 = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L826E4;
    work3 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 12);
    work2 = tile_x;
    work2++;
    if (current <= 0)
        goto L826A2;
    work2 -= 2;
L826A2:
    current = work3;
    work3 = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L826E4;
    work3 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 12);
    work2 = tile_x;
    work2 += 2;
    if (current <= 0)
        goto L826C0;
    work2 -= 4;
L826C0:
    current = work3;
    work3 = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L826E4;
    current = record[20];
    if (current != 2)
        goto L826DC;
    work2 = -0xB5;
    local.dy = work2;
    goto L826E4;
L826DC:
    if (current != 3)
        goto L826E4;
    work3 = -0x16A;
L826E2:
    local.dy = work3;
L826E4:
    work2 = *(s32 *)(record + 16);
    if (work2 < 0)
        goto L82820;
L826EC:
    current = local.first;
    if (current == 0)
        goto L827A0;
    work1 = local.middle;
    if (work1 != 0)
        goto L827A0;
    work2 = local.last;
    if (work2 != 0)
        goto L827A0;
    work5 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 12);
    work2 = tile_x;
    BIND(work2);
    work2++;
    if (current <= 0)
        goto L8270E;
    work2 -= 2;
L8270E:
    work3 = work4;
    current = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L827A0;
    work3 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 12);
    work2 = tile_x;
    BIND(work2);
    work2 += 2;
    if (current <= 0)
        goto L8272C;
    work2 -= 4;
L8272C:
    current = work3;
    work3 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L827A0;
    current = record[20];
    if (current != 2)
        goto L82768;
    current = 0x400;
    BIND(current);
    if ((u32)work7 <= (u32)current)
        goto L82756;
    current = local.y;
    current += 0xB5;
    work1 = 0x7FF;
    BIND(work1);
    current &= work1;
    work1 = 0x3FF;
    BIND(work1);
    if (current <= work1)
        goto L82786;
L82756:
    work3 = 0xB5;
    local.dy = work3;
    goto L82818;
L82768:
    if (current != 3)
        goto L82818;
    current = 0x400;
    BIND(current);
    if ((u32)work7 <= (u32)current)
        goto L82798;
    work4 = local.y;
    work1 = 0x16A;
    BIND(work1);
    current = work4 + work1;
    work1 = 0x7FF;
    BIND(work1);
    current &= work1;
    work1 = 0x3FF;
    BIND(work1);
    if (current > work1)
        goto L82798;
L82786:
    current = 0x800;
    BIND(current);
    current -= work7;
    local.dy = current;
    goto L82818;
L82798:
    work2 = 0x16A;
    local.dy = work2;
    goto L82818;
L827A0:
    if (work7 == 0)
        goto L82818;
    work3 = local.middle;
    if (work3 == 0)
        goto L82818;
    work4 = local.last;
    if (work4 != 0)
        goto L82818;
    current = record[1];
    work1 = record[3];
    work4 = tile_y;
    BIND(work4);
    work4 += 2;
    work2 = tile_x;
    work3 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82818;
    work3 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 12);
    work2 = tile_x;
    BIND(work2);
    work2++;
    if (current <= 0)
        goto L827D6;
    work2 -= 2;
L827D6:
    current = work3;
    work3 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82818;
    work3 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 12);
    work2 = tile_x;
    BIND(work2);
    work2 += 2;
    if (current <= 0)
        goto L827F4;
    work2 -= 4;
L827F4:
    current = work3;
    work3 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82818;
    current = record[20];
    if (current != 2)
        goto L8280E;
    current = 0xB5;
    local.dy = current;
    goto L82818;
L8280E:
    if (current != 3)
        goto L82818;
    work1 = 0x16A;
    local.dy = work1;
L82818:
    work2 = *(s32 *)(record + 16);
    if (work2 == 0)
        goto store_velocity;
L82820:
    current = *(s32 *)(record + 4);
    work3 = local.dx;
    current += work3;
    local.x = current;
    current = *(s32 *)(record + 8);
    if (work2 <= 0)
        goto L82838;
    work4 = 0x800;
    BIND(work4);
    work4 = current + work4;
    local.y = work4;
    goto L8283E;
L82838:
    work1 = -0x800;
    BIND(work1);
    work1 = current + work1;
    local.y = work1;
L8283E:
    work3 = local.y;
    work7 = work3 + work2;
    work1 = local.x;
    if (work1 >= 0)
        goto L8284C;
    work4 = 0x7FF;
    BIND(work4);
    work1 += work4;
L8284C:
    work1 >>= 11;
    tile_x = work1;
    work4 = work7;
    BIND(work4);
    if (work7 >= 0)
        goto L8285A;
    current = 0x7FF;
    BIND(current);
    work4 = work7 + current;
L8285A:
    work4 >>= 11;
    current = func_08082E58(record);
    current <<= 24;
    tile_y = work4;
    if (current != 0)
        goto L8286E;
    work1 = 1;
    BIND(work1);
    tile_y += work1;
L8286E:
    current = record[1];
    work1 = record[3];
    work2 = tile_x;
    BIND(work2);
    work2--;
    work3 = tile_y;
    TILE4;
    current = (u16)current;
    local.first = current;
    current = record[1];
    work1 = record[3];
    work2 = tile_x;
    work3 = tile_y;
    TILE4;
    current = (u16)current;
    local.middle = current;
    current = record[1];
    work1 = record[3];
    work4 = tile_x;
    BIND(work4);
    work4++;
    work2 = work4;
    work3 = tile_y;
    TILE4;
    current = (u16)current;
    local.last = current;
    work2 = 0x7FF;
    BIND(work2);
    current = work2;
    BIND(current);
    work3 = local.x;
    fraction8 = work3;
    BIND(fraction8);
    work1 = fraction8;
    work1 &= current;
    fraction8 = work1;
    work2 = local.first;
    if (work2 != 0)
        goto L828CE;
    work3 = local.middle;
    if (work3 != 0)
        goto L828CE;
    if (work1 == 0)
        goto L82908;
    current = local.last;
    if (current == 0)
        goto L82908;
L828CE:
    current = *(s32 *)(record + 16);
    if (current <= 0)
        goto L828F0;
    current = work7;
    BIND(current);
    if (work7 >= 0)
        goto L828DE;
    work1 = 0x7FF;
    BIND(work1);
    current = work7 + work1;
L828DE:
    current >>= 11;
    current <<= 11;
    work2 = local.y;
    current -= work2;
    goto L82906;
L828F0:
    current = work7;
    BIND(current);
    if (work7 >= 0)
        goto L828FA;
    work3 = 0x7FF;
    BIND(work3);
    current = work7 + work3;
L828FA:
    current >>= 11;
    current <<= 11;
    work2 = local.y;
    work3 = -0x800;
    BIND(work3);
    work1 = work2 + work3;
    current -= work1;
L82906:
    local.dy = current;
L82908:
    current = *(s32 *)(record + 12);
    if (current > 0)
        goto L82A08;
    current = fraction8;
    BIND(current);
    if (current == 0)
        goto L8298C;
    work1 = local.first;
    if (work1 != 0)
        goto L82A00;
    work2 = local.middle;
    if (work2 != 0)
        goto L8298C;
    work3 = local.last;
    if (work3 == 0)
        goto L8298C;
    current = record[20];
    if (current != 2)
        goto L8295C;
    current = 0x3FF;
    work1 = -0xB5;
    local.dx = work1;
    if (fraction8 > (u32)current)
        goto L82A00;
    current = local.x;
    current -= 0xB5;
    work1 = 0x7FF;
    current &= work1;
    work1 = 0x400;
    if (current <= work1)
        goto L82A00;
    work2 = fraction8;
    BIND(work2);
    work2 = -work2;
    asm volatile("" : : "r"(work2));
    goto L829FE;
L8295C:
    if (current != 3)
        goto L82A00;
    current = 0x3FF;
    work3 = -0x16A;
    local.dx = work3;
    if (fraction8 > (u32)current)
        goto L82A00;
    work1 = local.x;
    current = work1 + work3;
    work1 = 0x7FF;
    current &= work1;
    work1 = 0x400;
    if (current <= work1)
        goto L82A00;
    work2 = fraction8;
    BIND(work2);
    work2 = -work2;
    goto L829FE;
L8298C:
    work3 = local.first;
    if (work3 != 0)
        goto L82A00;
    current = local.middle;
    if (current == 0)
        goto L82A00;
    current = record[1];
    work1 = record[3];
    work5 = tile_x;
    work5 -= 2;
    work2 = work5;
    work3 = tile_y;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82A00;
    work2 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 16);
    work3 = tile_y;
    work3++;
    if (current <= 0)
        goto L829BE;
    work3 -= 2;
L829BE:
    current = work2;
    work2 = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82A00;
    work2 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 16);
    work3 = tile_y;
    work3 += 2;
    if (current <= 0)
        goto L829DC;
    work3 -= 4;
L829DC:
    current = work2;
    work2 = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82A00;
    current = record[20];
    if (current != 2)
        goto L829F8;
    work1 = -0xB5;
    local.dx = work1;
    goto L82A00;
L829F8:
    if (current != 3)
        goto L82A00;
    work2 = -0x16A;
L829FE:
    local.dx = work2;
L82A00:
    current = *(s32 *)(record + 12);
    if (current < 0)
        goto store_velocity;
L82A08:
    work3 = local.first;
    if (work3 == 0)
        goto L82AB8;
    current = local.middle;
    if (current != 0)
        goto L82AB8;
    work1 = local.last;
    if (work1 != 0)
        goto L82AB8;
    work5 = record[1];
    work1 = record[3];
    work2 = work4;
    current = *(s32 *)(record + 16);
    work3 = tile_y;
    BIND(work3);
    work3++;
    if (current <= 0)
        goto L82A2C;
    work3 -= 2;
L82A2C:
    current = work5;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82AB8;
    work2 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 16);
    work3 = tile_y;
    BIND(work3);
    work3 += 2;
    if (current <= 0)
        goto L82A48;
    work3 -= 4;
L82A48:
    current = work2;
    work2 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto L82AB8;
    current = record[20];
    if (current != 2)
        goto L82A84;
    current = 0x400;
    BIND(current);
    if (fraction8 <= (u32)current)
        goto L82A72;
    current = local.x;
    current += 0xB5;
    work1 = 0x7FF;
    BIND(work1);
    current &= work1;
    work1 = 0x3FF;
    BIND(work1);
    if (current <= work1)
        goto L82AA2;
L82A72:
    work3 = 0xB5;
    goto store_dx3;
L82A84:
    if (current != 3)
        goto store_velocity;
    current = 0x400;
    BIND(current);
    if (fraction8 <= (u32)current)
        goto L82B2C;
    work4 = local.x;
    work1 = 0x16A;
    BIND(work1);
    current = work4 + work1;
    work1 = 0x7FF;
    BIND(work1);
    current &= work1;
    work1 = 0x3FF;
    BIND(work1);
    if (current > work1)
        goto L82B2C;
L82AA2:
    current = 0x800;
    BIND(current);
    work2 = fraction8;
    BIND(work2);
    work2 = current - work2;
    local.dx = work2;
    goto store_velocity;
L82AB8:
    work4 = fraction8;
    BIND(work4);
    if (work4 == 0)
        goto store_velocity;
    current = local.middle;
    if (current == 0)
        goto store_velocity;
    work1 = local.last;
    if (work1 != 0)
        goto store_velocity;
    current = record[1];
    work1 = record[3];
    work4 = tile_x;
    BIND(work4);
    work4 += 2;
    work2 = work4;
    work3 = tile_y;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto store_velocity;
    work2 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 16);
    work3 = tile_y;
    BIND(work3);
    work3++;
    if (current <= 0)
        goto L82AF0;
    work3 -= 2;
L82AF0:
    current = work2;
    work2 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto store_velocity;
    work2 = record[1];
    work1 = record[3];
    current = *(s32 *)(record + 16);
    work3 = tile_y;
    BIND(work3);
    work3 += 2;
    if (current <= 0)
        goto L82B0E;
    work3 -= 4;
L82B0E:
    current = work2;
    work2 = work4;
    TILE4;
    current <<= 16;
    if (current != 0)
        goto store_velocity;
    current = record[20];
    if (current != 2)
        goto L82B28;
    work2 = 0xB5;
    local.dx = work2;
    goto store_velocity;
L82B28:
    if (current != 3)
        goto store_velocity;
L82B2C:
    work3 = 0x16A;
store_dx3:
    local.dx = work3;
store_velocity:
    work4 = local.dx;
    *(s32 *)(record + 12) = work4;
    current = local.dy;
    *(s32 *)(record + 16) = current;
done:
}
