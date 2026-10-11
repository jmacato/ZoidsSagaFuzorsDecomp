#include "types.h"

void func_08075F20(u32);
void func_08097B90(u32, u32);
void func_0809AA44(u32);
void func_0809D714(u32);
void func_0809F764(u32);
void func_0809F7AC(u32);
void func_0809F7CC(u32, u32);
void func_0809F9DC(u32);
void func_0809FCD4(u32, u32, u32, u32);
void func_0809FEE4(volatile s32 *, volatile s32 *, u32);
void func_080A0108(void);
void func_080B3A38(u32, u32);
void func_080B3B94(u32, u32, u32, s32);
void func_080B3C84(void);

#define BIND(value) asm("" : "+r"(value))
#define POSITIVE(id)                                                                               \
    asm("" : "=r"(work1));                                                                         \
    pointer0 = pointer4 + offset7;                                                                 \
    work3 = *(s16 *)(pointer0 + 10);                                                               \
    current = id;                                                                                  \
    asm volatile("" : : "r"(current), "r"(work1));                                                 \
    goto first_amount
#define NEGATIVE(id)                                                                               \
    pointer0 = pointer4 + offset7;                                                                 \
    work3 = *(s16 *)(pointer0 + 10);                                                               \
    work3 = -work3;                                                                                \
    current = id;                                                                                  \
    goto first_amount
#define DELAY_NEGATIVE(id)                                                                         \
    pointer0 = pointer4 + offset7;                                                                 \
    work1 = 0x10A;                                                                                 \
    BIND(work1);                                                                                   \
    pointer0 += work1;                                                                             \
    work3 = *(s16 *)pointer0;                                                                      \
    asm("" : : "r"(work1));                                                                        \
    work3 = -work3;                                                                                \
    current = id;                                                                                  \
    asm volatile("" : : "r"(current));                                                             \
    goto second_amount
#define DELAY_POSITIVE(id)                                                                         \
    pointer0 = pointer4 + offset7;                                                                 \
    work1 = 0x10A;                                                                                 \
    BIND(work1);                                                                                   \
    pointer0 += work1;                                                                             \
    work3 = *(s16 *)pointer0;                                                                      \
    asm("" : : "r"(work1));                                                                        \
    current = id;                                                                                  \
    goto second_amount

void func_08098AC0(u32 argument)
{
    volatile struct {
        s32 cost;
        s32 duration;
        s32 parameter0;
        s32 parameter1;
        s32 parameter2;
        u32 argument;
        s32 saved;
        u32 doubled;
    } local;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    register s32 side asm("r6");
    u32 offset7;
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    u8 *pointer7;
    register u32 index8 asm("r8");
    register u32 index9 asm("r9");
    register u8 *table9 asm("r9");
    register u8 *parameters10 asm("r10");
    register u32 offset12 asm("r12");
    register u8 *stack_pointer asm("sp");
    u32 dispatch;

    current = (u8)argument;
    local.argument = current;
    pointer0 = (u8 *)0x02031A0C;
    BIND(pointer0);
    work1 = 0x244;
    BIND(work1);
    pointer0 += work1;
    side = *pointer0;
side_loop:
    work5 = 0;
    index8 = work5;
    work2 = side << 1;
    local.doubled = work2;
    current = work2 + side;
    work1 = current << 7;
    current += work1;
    offset7 = current << 3;
scan_units:
    work1 = index8;
    BIND(work1);
    current = work1 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(offset7 + (u32)pointer0);
    work1 = *(u16 *)pointer4;
    current = 1;
    current &= work1;
    if (current == 0)
        goto next_scan_unit;
    work2 = 0x104;
    BIND(work2);
    pointer0 = pointer4 + work2;
    current = *pointer0;
    if (current != 0x2A)
        goto scan_action;
    work1 = 0x10C;
    BIND(work1);
    pointer0 = pointer4 + work1;
    current = *pointer0;
    if (current == 0)
        goto next_scan_unit;
scan_action:
    func_0809F7CC(side, index8);
    current = 1;
    work5 |= current;
    work1 = *(u16 *)pointer4;
    current = 2;
    current &= work1;
    if (current == 0)
        goto next_scan_unit;
    current = 2;
    work5 |= current;
    current = work5 << 24;
    BIND(current);
    work5 = (u32)current >> 24;
next_scan_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto scan_units;
    if (work5 == 0)
        goto clear_delayed;
    current = 0;
    BIND(current);
    local.cost = current;
    index8 = current;
    pointer2 = (u8 *)0x087357D8;
    BIND(pointer2);
    table9 = pointer2;
    current = local.parameter1;
    local.saved = current;
    pointer1 = (u8 *)&local.parameter1;
    BIND(pointer1);
    parameters10 = pointer1;
    current = local.doubled;
    work2 = current + side;
    current = work2 << 7;
    current = work2 + current;
    current <<= 3;
    offset12 = current;
    current = side << 3;
    current += side;
    current <<= 3;
    pointer1 = table9;
    BIND(pointer1);
    pointer7 = (u8 *)(current + (u32)pointer1);
    current = work2 << 1;
    work3 = current + 3;
cost_loop:
    work1 = index8;
    BIND(work1);
    current = work1 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    work1 = offset12;
    BIND(work1);
    pointer4 = (u8 *)(work1 + (u32)pointer0);
    work1 = *(u16 *)pointer4;
    current = 1;
    current &= work1;
    if (current == 0)
        goto next_cost_unit;
    work1 = 0x104;
    BIND(work1);
    pointer0 = pointer4 + work1;
    current = *pointer0;
    if (current != 0x2A)
        goto cost_action;
    work1 += 8;
    pointer0 = pointer4 + work1;
    current = *pointer0;
    if (current == 0)
        goto next_cost_unit;
cost_action:
    current = index8;
    BIND(current);
    if ((u32)current <= 2)
        goto front_unit_cost;
    work1 = local.cost;
    if (work1 == 0)
        goto rear_unit_cost;
    current = work3 << 1;
    current += work3;
    current <<= 2;
    pointer2 = (u8 *)0x087357D8;
    BIND(pointer2);
    pointer0 = (u8 *)(current + (u32)pointer2);
    current = *(u32 *)pointer0;
    current = work1 + current;
    work1 = (u32)current >> 31;
    current += work1;
    current >>= 1;
    local.cost = current;
    goto cost_ready;
front_unit_cost:
    current = local.cost;
    if (current != 0)
        goto next_cost_unit;
    current = *(u32 *)pointer7;
    local.cost = current;
    work1 = 2;
    BIND(work1);
    index8 = work1;
next_cost_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto cost_loop;
cost_ready:
    if (side != 0)
        goto rear_duration;
    pointer1 = table9;
    BIND(pointer1);
    current = *(u32 *)(pointer1 + 8);
    goto duration_ready;
rear_unit_cost:
    current = work2 << 1;
    current += 3;
    work1 = current << 1;
    work1 += current;
    work1 <<= 2;
    pointer1 = (u8 *)(work1 + (u32)table9);
    current = *(u32 *)pointer1;
    local.cost = current;
    goto cost_ready;
rear_duration:
    work2 = local.doubled;
    work1 = work2 + side;
    work1 <<= 1;
    work1 += 2;
    current = work1 << 1;
    current += work1;
    current <<= 2;
    pointer1 = table9;
    BIND(pointer1);
    pointer1 += 8;
    pointer0 = (u8 *)(current + (u32)pointer1);
    current = *(u32 *)pointer0;
duration_ready:
    local.duration = current;
    current = 0;
    BIND(current);
    index8 = current;
    work2 = local.doubled;
    work1 = work2 + side;
    current = work1 << 7;
    current = work1 + current;
    work3 = current << 3;
    work2 = work1 << 1;
    pointer7 = (u8 *)0x087357E0;
duration_loop:
    work1 = index8;
    BIND(work1);
    current = work1 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(work3 + (u32)pointer0);
    work1 = *(u16 *)pointer4;
    current = 1;
    current &= work1;
    if (current == 0)
        goto next_duration_unit;
    work1 = 0x104;
    BIND(work1);
    pointer0 = pointer4 + work1;
    current = *pointer0;
    if (current != 0x2A)
        goto duration_action;
    work1 += 8;
    pointer0 = pointer4 + work1;
    current = *pointer0;
    if (current == 0)
        goto next_duration_unit;
duration_action:
    work1 = index8;
    BIND(work1);
    current = work2 + work1;
    work1 = current << 1;
    work1 += current;
    work1 <<= 2;
    pointer1 = (u8 *)(work1 + (u32)pointer7);
    current = local.duration;
    work1 = *(u32 *)pointer1;
    if (current >= work1)
        goto next_duration_unit;
    local.duration = work1;
next_duration_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto duration_loop;
    current = 0x8000;
    local.parameter0 = current;
    work2 = 0xFFFF0000;
    BIND(work2);
    current = work2;
    BIND(current);
    work1 = local.saved;
    current &= work1;
    work1 = 0x20;
    current |= work1;
    local.parameter1 = current;
    pointer1 = parameters10;
    BIND(pointer1);
    current = *(u32 *)(pointer1 + 4);
    current &= work2;
    {
        u32 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        address[1] = current;
        pointer1 = (u8 *)address;
    }
    work1 = 0xFFFF;
    BIND(work1);
    current = local.parameter1;
    current &= work1;
    local.parameter1 = current;
    pointer0 = stack_pointer;
    pointer1 = parameters10;
    func_0809FEE4((volatile s32 *)pointer0, (volatile s32 *)pointer1, 0);
    func_080A0108();
    current = 0;
    if (side == 0)
        current = 1;
    func_0809F764(current);
    current = 2;
    work5 &= current;
    if (work5 == 0)
        goto show_status;
    func_080B3A38(side, 0);
    offset7 = 1;
    work2 = 0;
    BIND(work2);
    index8 = work2;
    work1 = local.doubled;
    current = work1 + side;
    work1 = current << 7;
    current += work1;
    work5 = current << 3;
show_damage:
    work2 = index8;
    BIND(work2);
    current = work2 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(work5 + (u32)pointer0);
    work1 = *(u16 *)pointer4;
    current = 1;
    current &= work1;
    if (current == 0)
        goto next_damage_unit;
    current = 2;
    current &= work1;
    if (current == 0)
        goto next_damage_unit;
    current = 4;
    current &= work1;
    if (current == 0)
        goto missed_unit;
    work3 = *(s16 *)(pointer4 + 2);
    func_080B3B94(1, side, work2, work3);
    offset7 = 0;
    goto next_damage_unit;
missed_unit:
    func_080B3B94(2, side, index8, 0);
next_damage_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto show_damage;
    if (offset7 == 0)
        goto finish_damage;
    func_08075F20(0xE9);
finish_damage:
    func_080B3C84();
show_status:
    func_080B3A38(side, 2);
    work3 = 0;
    BIND(work3);
    index8 = work3;
    pointer5 = (u8 *)0x02031A0C;
    work1 = local.doubled;
    current = work1 + side;
    work1 = current << 7;
    current += work1;
    work4 = current << 3;
status_loop:
    work2 = index8;
    BIND(work2);
    current = work2 << 7;
    current += index8;
    current <<= 2;
    current += work4;
    pointer0 = (u8 *)(current + (u32)pointer5);
    work1 = 0x35AC;
    BIND(work1);
    pointer0 += work1;
    work1 = *(u16 *)pointer0;
    current = 0x10;
    current &= work1;
    if (current == 0)
        goto next_status_unit;
    func_080B3B94(0x27, side, work2, 0);
    work3 = 1;
next_status_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto status_loop;
    if (work3 == 0)
        goto first_effects;
    func_080B3C84();
first_effects:
    work2 = 0;
    BIND(work2);
    index9 = work2;
first_effect_row:
    work3 = 0;
    BIND(work3);
    index8 = work3;
    current = index9;
    BIND(current);
    offset7 = current << 3;
first_effect_unit:
    work1 = local.doubled;
    work2 = work1 + side;
    current = work2 << 7;
    work2 += current;
    work2 <<= 3;
    work1 = index8;
    BIND(work1);
    current = work1 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(work2 + (u32)pointer0);
    pointer5 = pointer4 + offset7;
    BIND(pointer5);
    current = pointer5[4];
    if (current == 0)
        goto next_first_unit;
    func_0809F7CC(side, index8);
    current = pointer5[4];
    current--;
    asm("" : "=r"(dispatch) : "0"(current));
    switch (dispatch) {
    case 0:
        POSITIVE(6);
    case 1:
        NEGATIVE(6);
    case 2:
        POSITIVE(7);
    case 3:
        NEGATIVE(7);
    case 4:
        POSITIVE(8);
    case 5:
        NEGATIVE(8);
    case 6:
        POSITIVE(9);
    case 7:
        NEGATIVE(9);
    case 8:
        POSITIVE(10);
    case 9:
        NEGATIVE(10);
    case 10:
        POSITIVE(11);
    case 11:
        NEGATIVE(11);
    case 12:
        POSITIVE(12);
    case 13:
        NEGATIVE(12);
    case 14:
        POSITIVE(13);
    case 15:
        NEGATIVE(13);
    case 16:
        POSITIVE(14);
    case 17:
        NEGATIVE(14);
    case 18:
        POSITIVE(15);
    case 19:
        NEGATIVE(15);
    case 20:
        POSITIVE(16);
    case 21:
        NEGATIVE(16);
    case 22:
    case 43:
        POSITIVE(17);
    case 23:
        NEGATIVE(17);
    case 24:
        current = 0x12;
        goto first_zero;
    case 25:
        current = 0x14;
        goto first_zero;
    case 26:
        current = 0x16;
        goto first_zero;
    case 27:
        current = 0x18;
        goto first_zero;
    case 28:
        current = 0x1A;
        goto first_zero;
    case 29:
        current = 0x1B;
        goto first_zero;
    case 30:
        current = 0x1C;
        goto first_zero;
    case 31:
        current = 0x1D;
        goto first_zero;
    case 33:
        POSITIVE(0x25);
    case 34:
        current = 0x1E;
        goto first_zero;
    case 35:
        current = 0x20;
        goto first_zero;
    case 36:
        NEGATIVE(0x23);
    first_amount:
        func_080B3B94(current, side, index8, work3);
        goto first_effect_done;
    case 37:
        current = 5;
    first_zero:
        func_080B3B94(current, side, index8, 0);
        goto first_effect_done;
    case 42:
        func_080B3B94(0x22, side, index8, 0);
        break;
    default:
        break;
    }
first_effect_done:
    work3 = 1;
next_first_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto first_effect_unit;
    if (work3 == 0)
        goto second_effects;
    func_080B3C84();
    current = index9;
    BIND(current);
    current++;
    current = (u8)current;
    index9 = current;
    if ((u32)current <= 31)
        goto first_effect_row;
second_effects:
    work2 = 0;
    BIND(work2);
    index9 = work2;
second_effect_row:
    work3 = 0;
    BIND(work3);
    index8 = work3;
    current = index9;
    BIND(current);
    offset7 = current << 3;
second_effect_unit:
    work1 = local.doubled;
    work2 = work1 + side;
    current = work2 << 7;
    work2 += current;
    work2 <<= 3;
    work1 = index8;
    BIND(work1);
    current = work1 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(work2 + (u32)pointer0);
    pointer0 = pointer4 + offset7;
    work2 = 0x104;
    BIND(work2);
    pointer5 = pointer0 + work2;
    BIND(pointer5);
    current = *pointer5;
    if (current == 0)
        goto next_second_unit;
    func_0809F7CC(side, index8);
    current = *pointer5;
    current--;
    asm("" : "=r"(dispatch) : "0"(current));
    switch (dispatch) {
    case 0:
        DELAY_NEGATIVE(6);
    case 1:
        DELAY_POSITIVE(6);
    case 2:
        DELAY_NEGATIVE(7);
    case 3:
        DELAY_POSITIVE(7);
    case 4:
        DELAY_NEGATIVE(8);
    case 5:
        DELAY_POSITIVE(8);
    case 6:
        DELAY_NEGATIVE(9);
    case 7:
        DELAY_POSITIVE(9);
    case 8:
        DELAY_NEGATIVE(10);
    case 9:
        DELAY_POSITIVE(10);
    case 10:
        DELAY_NEGATIVE(11);
    case 11:
        DELAY_POSITIVE(11);
    case 12:
        DELAY_NEGATIVE(12);
    case 13:
        DELAY_POSITIVE(12);
    case 14:
        DELAY_NEGATIVE(13);
    case 15:
        DELAY_POSITIVE(13);
    case 16:
        DELAY_NEGATIVE(14);
    case 17:
        DELAY_POSITIVE(14);
    case 18:
        DELAY_NEGATIVE(15);
    case 19:
        DELAY_POSITIVE(15);
    case 20:
        DELAY_NEGATIVE(16);
    case 21:
        DELAY_POSITIVE(16);
    case 22:
    case 43:
        DELAY_NEGATIVE(17);
    case 23:
        DELAY_POSITIVE(17);
    case 24:
        current = 0x13;
        goto second_zero;
    case 25:
        current = 0x15;
        goto second_zero;
    case 26:
        current = 0x17;
        goto second_zero;
    case 27:
        current = 0x19;
        goto second_zero;
    case 28:
        current = 0x1B;
        goto second_zero;
    case 29:
        current = 0x1A;
        goto second_zero;
    case 30:
        current = 0x1D;
        goto second_zero;
    case 31:
        current = 0x1C;
        goto second_zero;
    case 33:
        DELAY_NEGATIVE(0x26);
    case 34:
        current = 0x1F;
        goto second_zero;
    case 35:
        current = 0x20;
    second_zero:
        func_080B3B94(current, side, index8, 0);
        goto second_effect_done;
    case 36:
        DELAY_POSITIVE(0x24);
    second_amount:
        func_080B3B94(current, side, index8, work3);
        goto second_effect_done;
    case 37:
        func_080B3B94(0x29, side, index8, 0);
        break;
    default:
        break;
    }
second_effect_done:
    work3 = 1;
next_second_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto second_effect_unit;
    if (work3 == 0)
        goto show_destroyed;
    func_080B3C84();
    current = index9;
    BIND(current);
    current++;
    current = (u8)current;
    index9 = current;
    if ((u32)current <= 31)
        goto second_effect_row;
show_destroyed:
    func_080B3A38(side, 1);
    work3 = 0;
    BIND(work3);
    index8 = work3;
    work1 = local.doubled;
    current = work1 + side;
    work1 = current << 7;
    current += work1;
    work5 = current << 3;
destroyed_loop:
    work2 = index8;
    BIND(work2);
    current = work2 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(work5 + (u32)pointer0);
    work1 = *(u16 *)pointer4;
    current = 9;
    current &= work1;
    if (current != 9)
        goto next_destroyed_unit;
    func_080B3B94(4, side, work2, 0);
    work3 = 1;
next_destroyed_unit:
    current = index8;
    BIND(current);
    current++;
    current = (u8)current;
    index8 = current;
    if ((u32)current <= 5)
        goto destroyed_loop;
    if (work3 == 0)
        goto resolve_side;
    func_080B3C84();
resolve_side:
    func_0809D714(side);
    current = local.argument;
    if (current != 0)
        goto resolve_other_side;
    func_0809F9DC(side);
    func_0809F7AC(side);
resolve_other_side:
    work4 = 0;
    if (side == 0)
        work4 = 1;
    func_0809AA44(work4);
    work1 = local.argument;
    if (work1 != 0)
        goto clear_delayed;
    func_0809F9DC(work4);
    func_0809F7AC(work4);
clear_delayed:
    work2 = 0;
    BIND(work2);
    index8 = work2;
    work1 = local.doubled;
    current = work1 + side;
    work1 = current << 7;
    current += work1;
    offset7 = current << 3;
clear_delayed_unit:
    work2 = index8;
    BIND(work2);
    current = work2 << 7;
    current += index8;
    current <<= 2;
    pointer1 = (u8 *)0x02034FB8;
    BIND(pointer1);
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer4 = (u8 *)(offset7 + (u32)pointer0);
    work1 = *(u16 *)pointer4;
    current = 1;
    current &= work1;
    work5 = index8;
    BIND(work5);
    work5++;
    if (current == 0)
        goto next_delayed_unit;
    current = 0;
    goto check_delayed_index;
next_delayed_index:
    current = index9;
    BIND(current);
    current++;
    current = (u8)current;
check_delayed_index:
    index9 = current;
    work1 = index9;
    BIND(work1);
    if ((u32)work1 > 31)
        goto next_delayed_unit;
    current = work1 << 3;
    pointer0 = pointer4 + current;
    work2 = 0x104;
    BIND(work2);
    pointer0 += work2;
    current = *pointer0;
    if (current != 0x2A)
        goto next_delayed_index;
    func_0809FCD4(2, side, 0, 0);
    func_080A0108();
    func_08097B90(side, index8);
next_delayed_unit:
    current = work5 << 24;
    current = (u32)current >> 24;
    index8 = current;
    if ((u32)current <= 5)
        goto clear_delayed_unit;
    current = 0;
    if (side == 0)
        current = 1;
    side = current;
    pointer0 = (u8 *)0x02031A0C;
    BIND(pointer0);
    work1 = 0x244;
    BIND(work1);
    pointer0 += work1;
    current = *pointer0;
    if (side != current)
        goto side_loop;
}
