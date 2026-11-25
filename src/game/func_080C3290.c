#include "types.h"

void func_08075F20(u32);
void func_0807C290(u32);
void func_0807BEF4(u32, u32, u32);
void func_08079544(u32, u32);
void func_0807970C(void);
void func_08091DB4(void);
void func_0809309C(void);
void func_080930C0(void);
void func_08093E24(u32, u32);
s32 func_08093E60(void);
u32 func_0809A99C(u32, u32);
u8 *func_0809A908(u32, u32);
u32 func_0809B834(u32, u32, u32, u32);
void func_0809AA44(u32);
void func_0809F7AC(u32);
void func_0809F9DC(u32);
void func_080A0244(u32);
void func_080A0358(void);
void func_080C1B4C(u32, u32);
u32 func_080C1C68(u32, u32);
u32 func_080C1DC8(u32, u32);
void func_080C2B7C(void);
u32 func_080C8BAC(u32);

u32 func_080C3290(u32 argument)
{
    volatile u8 scratch[36];
    u32 dispatch;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 index asm("r5");
    register s32 work6 asm("r6");
    register s32 work7 asm("r7");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    u8 *pointer7;
    register u8 *table8 asm("r8");
    register u8 *table9 asm("r9");
    register volatile u8 *stack_pointer asm("sp");

    current = argument;
    work1 = current;
    asm("" : "+r"(work1));
    work1 <<= 24;
    work2 = (u32)work1 >> 24;
    work1 = work2 - 1;
    asm("" : "=r"(dispatch) : "0"(work1));
    switch (dispatch) {
    case 1:
    case 2:
        func_0807C290(0x08004296);
        func_08093E24(0, 2);
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        pointer0 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer0));
        work1 = index << 5;
        work1 += index;
        work1 <<= 3;
        work1 += (u32)pointer0;
        work2 = 0x258;
        asm("" : "+r"(work2));
        work1 += work2;
        work1 = *(u8 *)work1;
        work3 = 0x4F8C;
        asm("" : "+r"(work3));
        pointer0 += work3;
        asm volatile("" : : "r"(pointer0));
        goto store_selection;
    case 3:
    case 31:
        current = func_080C1C68(0, 1);
        current <<= 24;
        current = (u32)current >> 24;
        if (current != 255)
            goto success;
        func_08075F20(0x114);
        pointer1 = (u8 *)0x0200C4C0;
        current = 1;
        asm volatile("" : : "r"(current));
        goto store_error;
    case 4:
        current = func_080C1C68(0, 1);
        current <<= 24;
        current = (u32)current >> 24;
        if (current == 255)
            goto missing_unit;
        index = 0;
        goto check_alive;
    next_alive:
        current = index + 1;
        current <<= 24;
        index = (u32)current >> 24;
    check_alive:
        if ((u32)index > 5)
            goto no_alive;
        pointer0 = func_0809A908(0, index);
        work1 = *(u16 *)(pointer0 + 4);
        current = 2;
        current &= work1;
        if (current == 0)
            goto next_alive;
    case 0:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 21:
    case 33:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 54:
    case 55:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 64:
    success:
        current = 1;
        goto done;
    no_alive:
        func_08075F20(0x114);
        current = 0x08004487;
        goto show_error;
    missing_unit:
        func_08075F20(0x114);
        pointer1 = (u8 *)0x0200C4C0;
        current = 1;
        goto store_error;
    case 6:
    case 56:
        index = 3;
        goto check_reserve;
    next_reserve:
        current = index + 1;
        current <<= 24;
        index = (u32)current >> 24;
    check_reserve:
        if ((u32)index > 5)
            goto no_reserve;
        current = func_0809A99C(0, index);
        if (current == 0)
            goto next_reserve;
        goto success;
    no_reserve:
        func_08075F20(0x114);
        current = 0x080044D4;
        goto show_error;
    case 20:
        func_0807C290(0x080042CD);
        func_08093E24(0, 2);
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        pointer0 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer0));
        work1 = index << 5;
        work1 += index;
        work1 <<= 3;
        work1 += (u32)pointer0;
        work4 = 0x258;
        asm("" : "+r"(work4));
        goto read_selection;
    case 22:
    case 23:
        pointer0 = (u8 *)0x02020E3C;
        current = pointer0[13];
        current -= 2;
        current <<= 24;
        current = (u32)current >> 24;
        if ((u32)current <= 3)
            goto mode_error_a;
        pointer0 = (u8 *)0x03000010;
        current = *(u32 *)pointer0;
        current = func_080C8BAC(current);
        pointer1 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer1));
        current = (u32)current >> 7;
        work3 = 0x4F8C;
        asm("" : "+r"(work3));
        pointer1 += work3;
        *pointer1 = current;
        goto success;
    mode_error_a:
        func_08075F20(0x114);
        current = 0x080047CB;
        asm volatile("" : : "r"(work1));
        goto show_error;
    case 25:
        pointer1 = (u8 *)0x02020E3C;
        current = *pointer1;
        if (current != 0)
            goto choose_pair;
        current = pointer1[1];
        if ((u32)current <= 13)
            goto compare_zone;
        if (current != 16)
            goto zone_error;
    compare_zone:
        pointer0 = (u8 *)0x020209D8;
        pointer1 = (u8 *)0x02020E4C;
        current = *(u16 *)(pointer0 + 0x1A);
        work1 = *(u16 *)(pointer1 + 0x24);
        if (current == work1)
            goto choose_pair;
    zone_error:
        func_08075F20(0x114);
        current = 0x0800480B;
        goto show_error;
    case 24:
    choose_pair:
        pointer0 = (u8 *)0x02020E3C;
        current = pointer0[13];
        current -= 2;
        current <<= 24;
        current = (u32)current >> 24;
        if ((u32)current <= 3)
            goto mode_error_b;
        func_0807C290(0x080043A1);
        func_08093E24(0, 2);
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        pointer4 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer4));
        current = index << 5;
        current += index;
        current <<= 3;
        current += (u32)pointer4;
        work1 = 0x258;
        asm("" : "+r"(work1));
        current += work1;
        work1 = *(u8 *)current;
        work2 = 0x4F8C;
        asm("" : "+r"(work2));
        pointer0 = pointer4 + work2;
        *pointer0 = work1;
        pointer0 = (u8 *)0x03000010;
        current = *(u32 *)pointer0;
        current = func_080C8BAC(current);
        current = (u32)current >> 7;
        work3 = 0x4F8D;
        asm("" : "+r"(work3));
        pointer4 += work3;
        *pointer4 = current;
        goto success;
    mode_error_b:
        func_08075F20(0x114);
        current = 0x080047CB;
        goto show_error;
    pick_item:
        work4 = 0x4F8C;
        asm("" : "+r"(work4));
        pointer0 = (u8 *)((u32)pointer2 + work4);
        *pointer0 = work3;
        work4 = 1;
        goto close_items;
    case 26:
        func_0807C290(0x08004899);
        index = 1;
        pointer0 = (u8 *)0x0202889C;
        table9 = pointer0;
        pointer7 = (u8 *)0x087A58C4;
        pointer1 = (u8 *)0x02036867;
        table8 = pointer1;
        asm volatile("" : : "r"(pointer0), "r"(pointer1));
    item_loop:
        work2 = (u32)index >> 5;
        work2 <<= 2;
        work2 += (u32)table9;
        current = 31;
        current &= index;
        work1 = 1;
        work1 <<= current;
        current = *(u32 *)work2;
        current &= work1;
        if (current == 0)
            goto absent_item;
        work4 = 0;
        work6 = index + 1;
        goto check_item_member;
    next_item_member:
        current = work4 + 1;
        current <<= 24;
        work4 = (u32)current >> 24;
    check_item_member:
        if ((u32)work4 > 9)
            goto item_member_done;
        pointer2 = table8;
        asm("" : "+r"(pointer2));
        pointer0 = (u8 *)(work4 + (u32)pointer2);
        current = *pointer0;
        if (current != index)
            goto next_item_member;
        current = index << 2;
        current += (u32)pointer7;
        work1 = *(u32 *)current;
        func_0807BEF4(5, work1, 2);
    item_member_done:
        if (work4 != 10)
            goto next_item;
        current = index << 2;
        current += (u32)pointer7;
        work1 = *(u32 *)current;
        func_0807BEF4(5, work1, 0);
        goto next_item;
    absent_item:
        work1 = *(u32 *)pointer7;
        func_0807BEF4(5, work1, 0);
        work6 = index + 1;
    next_item:
        current = work6 << 24;
        index = (u32)current >> 24;
        if ((u32)index <= 67)
            goto item_loop;
        func_0807C290(0x080048BC);
        pointer6 = (u8 *)0x0202889C;
        pointer5 = (u8 *)0x02036867;
    item_menu:
        func_0807C290(0x080048B5);
        pointer0 = (u8 *)0x0200C4A0;
        current = *pointer0;
        current++;
        work1 = current << 24;
        work3 = (u32)work1 >> 24;
        pointer0 = (u8 *)0x0200C4A2;
        work2 = *pointer0;
        if (work2 != 1)
            goto item_command;
        current = (u32)work1 >> 29;
        current <<= 2;
        current += (u32)pointer6;
        work1 = 31;
        work1 &= work3;
        work2 <<= work1;
        current = *(u32 *)current;
        current &= work2;
        if (current == 0)
            goto item_error;
        work4 = 0;
        current = *pointer5;
        pointer2 = (u8 *)0x02031A0C;
        if (current == work3)
            goto item_search_done;
        current = 0x4E5B;
        pointer1 = pointer2 + current;
    find_item:
        current = work4 + 1;
        current <<= 24;
        work4 = (u32)current >> 24;
        if ((u32)work4 > 9)
            goto item_search_done;
        pointer0 = (u8 *)(work4 + (u32)pointer1);
        current = *pointer0;
        if (current != work3)
            goto find_item;
    item_search_done:
        if (work4 == 10)
            goto pick_item;
    item_error:
        func_08075F20(0x114);
        goto item_menu;
    item_command:
        if (work2 == 2)
            goto cancel_items;
        func_080C1B4C(4, work3);
        goto item_menu;
    cancel_items:
        work4 = 0;
    close_items:
        func_0807C290(0x080048B9);
        current = work4;
        goto done;
    case 27:
    case 63:
    case 65:
    case 66:
        pointer0 = (u8 *)0x02020E3C;
        current = *pointer0;
        if (current == 2)
            goto success;
        func_08075F20(0x114);
        current = 0x08004523;
        goto show_error;
    case 28:
        func_08079544(2, 16);
        func_0807970C();
        func_080A0358();
        pointer4 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer4));
        work1 = 0x4F7B;
        asm("" : "+r"(work1));
        pointer2 = pointer4 + work1;
        work1 = *pointer2;
        current = 1;
        current |= work1;
        *pointer2 = current;
        func_08091DB4();
        func_08079544(15, 16);
        func_080C2B7C();
        index = 0;
        work3 = 0x4F8C;
        asm("" : "+r"(work3));
        pointer2 = pointer4 + work3;
        current = 0x2208;
        asm("" : "+r"(current));
        pointer4 += current;
    copy_side:
        pointer1 = (u8 *)(index + (u32)pointer2);
        pointer0 = (u8 *)(index + (u32)pointer4);
        current = *pointer0;
        *pointer1 = current;
        current = index + 1;
        current <<= 24;
        index = (u32)current >> 24;
        if ((u32)index <= 5)
            goto copy_side;
        func_08079544(16, 16);
        func_0807970C();
        pointer0 = (u8 *)0x02020E3C;
        current = pointer0[1];
        func_080A0244(current);
        func_0809AA44(0);
        func_0809AA44(1);
        func_0809F9DC(0);
        func_0809F9DC(1);
        func_0809F7AC(0);
        func_0809F7AC(1);
        func_0809309C();
        func_080930C0();
        pointer1 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer1));
        work2 = 0x4F7B;
        asm("" : "+r"(work2));
        pointer1 += work2;
        work2 = *pointer1;
        current = 0xFE;
        current &= work2;
        *pointer1 = current;
        func_08079544(1, 16);
        goto success;
    case 29:
        func_0807C290(0x080042F8);
        func_08093E24(0, 2);
        pointer4 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer4));
        work3 = 0x4F8C;
        asm("" : "+r"(work3));
        pointer6 = pointer4 + work3;
    weapon_menu:
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        work2 = index << 5;
        current = work2 + index;
        current <<= 3;
        current += (u32)pointer4;
        work1 = 0x258;
        asm("" : "+r"(work1));
        current += work1;
        work1 = *(u8 *)current;
        current = 0x94;
        current *= work1;
        pointer1 = (u8 *)(current + (u32)pointer4);
        work3 = 0x113E;
        pointer0 = pointer1 + work3;
        current = *(u16 *)pointer0;
        if (current != 0)
            goto has_weapon;
        work3 += 4;
        pointer0 = pointer1 + work3;
        current = *(u16 *)pointer0;
        if (current != 0)
            goto has_weapon;
        work3 += 4;
        pointer0 = pointer1 + work3;
        current = *(u16 *)pointer0;
        if (current != 0)
            goto has_weapon;
        work3 += 4;
        pointer0 = pointer1 + work3;
        current = *(u16 *)pointer0;
        if (current == 0)
            goto no_weapon;
    has_weapon:
        current = work2 + index;
        current <<= 3;
        current += (u32)pointer4;
        work4 = 0x258;
        asm("" : "+r"(work4));
        current += work4;
        current = *(u8 *)current;
        *pointer6 = current;
        goto success;
    no_weapon:
        func_08075F20(0x114);
        func_0807C290(0x0800477F);
        goto weapon_menu;
    case 30:
        func_0807C290(0x08004329);
        func_08093E24(0, 2);
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        pointer0 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer0));
        work1 = index << 5;
        work1 += index;
        work1 <<= 3;
        work1 += (u32)pointer0;
        work2 = 0x258;
        asm("" : "+r"(work2));
        work1 += work2;
        work1 = *(u8 *)work1;
        work3 = 0x4F8C;
        asm("" : "+r"(work3));
        pointer0 += work3;
        asm volatile("" : : "r"(work1));
        goto store_selection;
    case 32:
        index = 0;
        pointer7 = (u8 *)0x02036998;
    shuffle_side:
        work4 = 0;
        work6 = index + 1;
        current = index << 1;
        current += index;
        index = current << 1;
    shuffle_row:
        pointer0 = (u8 *)0x03000010;
        current = *(u32 *)pointer0;
        current = func_080C8BAC(current);
        current = (u32)current >> 14;
        if (current != 0)
            goto swap_row;
        current = index + work4;
        pointer1 = (u8 *)(current + (u32)pointer7);
        *pointer1 = work4;
        current += 3;
        pointer0 = (u8 *)(current + (u32)pointer7);
        work1 = work4 + 3;
        *pointer0 = work1;
        goto next_shuffle;
    swap_row:
        current = index + work4;
        pointer2 = (u8 *)(current + (u32)pointer7);
        work1 = work4 + 3;
        *pointer2 = work1;
        current += 3;
        pointer0 = (u8 *)(current + (u32)pointer7);
        *pointer0 = work4;
    next_shuffle:
        current = work4 + 1;
        current <<= 24;
        work4 = (u32)current >> 24;
        if ((u32)work4 <= 2)
            goto shuffle_row;
        current = work6 << 24;
        index = (u32)current >> 24;
        if ((u32)index <= 1)
            goto shuffle_side;
        goto success;
    case 34:
        index = 0;
    fill_deck:
        pointer4 = (u8 *)stack_pointer;
        asm("" : "+r"(pointer4));
        pointer0 = (u8 *)((u32)pointer4 + index);
        *pointer0 = index;
        current = index + 1;
        current <<= 24;
        index = (u32)current >> 24;
        if ((u32)index <= 35)
            goto fill_deck;
        index = 0;
        pointer0 = (u8 *)0x02036998;
        asm("" : "+r"(pointer0));
        table8 = pointer0;
        work7 = 35;
    shuffle_deck:
        pointer0 = (u8 *)0x03000010;
        current = *(u32 *)pointer0;
        current = func_080C8BAC(current);
        work1 = 36;
        work1 -= index;
        current *= work1;
        current = (u32)current >> 15;
        current <<= 24;
        work4 = (u32)current >> 24;
        pointer2 = table8;
        asm("" : "+r"(pointer2));
        pointer1 = (u8 *)(index + (u32)pointer2);
        pointer3 = (u8 *)stack_pointer;
        asm("" : "+r"(pointer3));
        pointer0 = pointer3 + work4;
        current = *pointer0;
        *pointer1 = current;
        current = work7 - index;
        work6 = index + 1;
        if (work4 >= current)
            goto next_card;
        work3 = current;
    slide_deck:
        pointer0 = (u8 *)stack_pointer;
        pointer2 = pointer0 + work4;
        work1 = work4 + 1;
        pointer0 += work1;
        current = *pointer0;
        *pointer2 = current;
        work1 <<= 24;
        work4 = (u32)work1 >> 24;
        if (work4 < work3)
            goto slide_deck;
    next_card:
        current = work6 << 24;
        index = (u32)current >> 24;
        if ((u32)index <= 35)
            goto shuffle_deck;
        goto success;
    case 35:
        current = func_080C1C68(0, 59);
        current <<= 24;
        current = (u32)current >> 24;
        if (current != 255)
            goto success;
        func_08075F20(0x114);
        pointer1 = (u8 *)0x0200C4C0;
        current = 59;
        goto store_error;
    case 36:
        current = func_080C1C68(0, 49);
        current <<= 24;
        current = (u32)current >> 24;
        if (current != 255)
            goto success;
        func_08075F20(0x114);
        pointer1 = (u8 *)0x0200C4C0;
        current = 49;
        goto store_error;
    case 37:
    case 38:
    case 39:
        current = func_080C1DC8(0, work2);
        work1 = current;
        asm("" : "+r"(work1));
        work1 <<= 24;
        work1 = (u32)work1 >> 24;
        asm("" : "=r"(dispatch) : "0"(work1));
        switch (dispatch) {
        case 0:
            goto success;
        case 1:
            func_08075F20(0x114);
            current = 0x0800464B;
            goto show_error;
        case 2:
            func_08075F20(0x114);
            current = 0x08004688;
            goto show_error;
        case 3:
            func_08075F20(0x114);
            current = 0x080046DD;
            goto show_error;
        case 4:
            func_08075F20(0x114);
            current = 0x0800472C;
            goto show_error;
        default:
            goto done;
        }
    case 46:
        current = func_080C1C68(0, 18);
        current <<= 24;
        current = (u32)current >> 24;
        if (current != 255)
            goto success;
        func_08075F20(0x114);
        pointer1 = (u8 *)0x0200C4C0;
        current = 18;
    store_error:
        *pointer1 = current;
        current = 0x080043FB;
    show_error:
        func_0807C290(current);
    failure:
        current = 0;
        goto done;
    store_member:
        pointer0 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer0));
        work1 = index << 5;
        work1 += index;
        work1 <<= 3;
        work1 += (u32)pointer0;
        work2 = 0x258;
        asm("" : "+r"(work2));
        work1 += work2;
        work1 = *(u8 *)work1;
        work3 = 0x4F8C;
        asm("" : "+r"(work3));
        pointer0 += work3;
        goto store_selection;
    store_reserve:
        pointer0 = (u8 *)0x02031A0C;
        asm("" : "+r"(pointer0));
        work1 = index << 5;
        work1 += index;
        work1 <<= 3;
        work1 += (u32)pointer0;
        work4 = 0x990;
    read_selection:
        work1 += work4;
        work1 = *(u8 *)work1;
        work2 = 0x4F8C;
        asm("" : "+r"(work2));
        pointer0 += work2;
    store_selection:
        *pointer0 = work1;
        goto success;
    case 47:
        func_0807C290(0x08004362);
        func_08093E24(0, 2);
    member_menu:
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        work1 = index << 24;
        work1 = (u32)work1 >> 24;
        current = func_0809B834(0, work1, 0x22, 0);
        current <<= 24;
        current = (u32)current >> 24;
        if (current == 255)
            goto store_member;
        func_08075F20(0x114);
        func_0807C290(0x08004570);
        goto member_menu;
    case 53:
        index = 0;
        goto check_enemy;
    next_enemy:
        current = index + 1;
        current <<= 24;
        index = (u32)current >> 24;
    check_enemy:
        if ((u32)index > 5)
            goto no_enemy;
        current = func_0809B834(1, index, 0x2A, 0);
        current <<= 24;
        current = (u32)current >> 24;
        if (current == 255)
            goto next_enemy;
        func_0807C290(0x080043D2);
        func_08093E24(1, 0);
    enemy_menu:
        index = func_08093E60();
        current = -1;
        if (index == current)
            goto failure;
        work1 = index << 24;
        work1 = (u32)work1 >> 24;
        current = func_0809B834(1, work1, 0x2A, 0);
        current <<= 24;
        current = (u32)current >> 24;
        if (current != 255)
            goto store_reserve;
        func_08075F20(0x114);
        func_0807C290(0x080045B6);
        goto enemy_menu;
    no_enemy:
        func_08075F20(0x114);
        func_0807C290(0x08004600);
        current = 0;
        asm volatile("" : : "r"(current));
    default:
        break;
    }
done:
    return current;
}
