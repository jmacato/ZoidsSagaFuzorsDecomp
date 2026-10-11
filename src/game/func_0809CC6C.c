#include "types.h"

u8 *func_0809A954(u32, u32, u32);
void func_0809B26C(u32, u32, u32, s32, u32, u32, u32, u32, u32);
void func_0809B480(u32, u32, u32, s32);
void func_0809B4D0(u32, u32, u32);
void func_0809B62C(u32, u32, u32);
u32 func_0809B834(u32, u32, u32, u32);
s32 func_080BD2F4(s32, s32);
void func_080BE06C(u8 *, s32);
void func_080BE0A0(u8 *, s32);
void func_080BE46C(u32, u32);
void func_080BFFA4(u32, u32, u32);
void func_080C08F0(u32, u32, u32, u32, u32, u8 *, volatile u32 *);
void func_080C280C(u32, u32, u8 *, u8 *);

#define BIND(value) asm("" : "+r"(value))
#define STORE16(pointer, value)                                                                    \
    {                                                                                              \
        u16 *address;                                                                              \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = value;                                                                          \
        pointer = (u8 *)address;                                                                   \
    }
#define EFFECT(id, amount, a, b, c, d, e) func_0809B26C(side, slot, id, amount, a, b, c, d, e)
#define LOAD_AMOUNT6                                                                               \
    asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(pointer5));                             \
    work3 = *(s16 *)(pointer7 + 12);                                                               \
    asm("" : : "r"(current), "r"(work1), "r"(work2), "r"(pointer5))
#define LOAD_AMOUNT2                                                                               \
    asm("" : "=r"(current), "=r"(work1), "=r"(pointer5), "=r"(work6));                             \
    work3 = *(s16 *)(pointer7 + 12);                                                               \
    asm("" : : "r"(current), "r"(work1), "r"(pointer5), "r"(work6))
#define SIMPLE_EFFECT(id)                                                                          \
    LOAD_AMOUNT6;                                                                                  \
    EFFECT(id, work3, ({                                                                           \
               current = pointer7[10];                                                             \
               BIND(current);                                                                      \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               current = 0;                                                                        \
               BIND(current);                                                                      \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               work1 = 0x244;                                                                      \
               BIND(work1);                                                                        \
               pointer0 = pointer4 + work1;                                                        \
               current = *pointer0;                                                                \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               work2 = 0x245;                                                                      \
               BIND(work2);                                                                        \
               pointer0 = pointer4 + work2;                                                        \
               current = *pointer0;                                                                \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               work4 = local.selector;                                                             \
               work4;                                                                              \
           }))
#define FIRST_EFFECT(id)                                                                           \
    LOAD_AMOUNT6;                                                                                  \
    EFFECT(id, work3, ({                                                                           \
               current = pointer7[10];                                                             \
               BIND(current);                                                                      \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               work6 = 0;                                                                          \
               BIND(work6);                                                                        \
               work6;                                                                              \
           }),                                                                                     \
           ({                                                                                      \
               current = 0x244;                                                                    \
               BIND(current);                                                                      \
               pointer5 = pointer4 + current;                                                      \
               current = *pointer5;                                                                \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               work1 = 0x245;                                                                      \
               BIND(work1);                                                                        \
               pointer4 += work1;                                                                  \
               current = *pointer4;                                                                \
               current;                                                                            \
           }),                                                                                     \
           ({                                                                                      \
               work2 = local.selector;                                                             \
               work2;                                                                              \
           }))

u32 func_0809CC6C(u32 argument0, u32 argument1, u32 argument2)
{
    volatile struct {
        u32 result;
        u32 argument;
        u8 *unit_record;
        u32 selector;
        u32 zero;
        u8 *flags;
        u32 active;
        u32 doubled;
    } local;
    struct Block24 {
        u32 words[6];
    };
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work6 asm("r6");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    u8 *pointer7;
    register u32 side asm("r8");
    register u32 slot asm("r9");
    register u8 *unit asm("r10");
    register u8 *offset_table asm("r12");
    register u8 *stack_pointer asm("sp");
    u32 dispatch;

    current = (u8)argument0;
    local.argument = current;
    work1 = (u8)argument1;
    side = work1;
    work2 = (u8)argument2;
    slot = work2;
    pointer3 = (u8 *)0x02031A0C;
    BIND(pointer3);
    pointer1 = (u8 *)0x02031C50;
    current = *pointer1;
    current <<= 2;
    work2 = local.argument;
    current = work2 + current;
    work4 = 0x4F85;
    BIND(work4);
    pointer4 = (u8 *)(work4 + (u32)pointer3);
    offset_table = pointer4;
    pointer0 = (u8 *)(current + (u32)offset_table);
    work2 = *pointer0;
    current = 7;
    work6 = 7;
    work6 &= work2;
    local.selector = work6;
    work2 = (u32)work2 >> 3;
    work2 &= current;
    current = work6 << 2;
    current += work6;
    current <<= 3;
    current -= work6;
    current <<= 4;
    work4 = 0x222C;
    BIND(work4);
    pointer1 = pointer3 + work4;
    pointer7 = (u8 *)(current + (u32)pointer1);
    current = 100;
    work1 = work2;
    work1 *= current;
    work1 += 24;
    pointer1 = (u8 *)((u32)pointer7 + work1);
    work6 = side;
    BIND(work6);
    current = work6 << 1;
    work6 = current + work6;
    current = work6 << 4;
    current += 4;
    pointer1 += current;
    work2 = slot;
    current = work2 << 3;
    pointer1 += current;
    current = *pointer1;
    pointer4 = pointer3;
    if (current == 0)
        goto unavailable;
    work2 = work6 << 7;
    work2 = work6 + work2;
    work2 <<= 3;
    work3 = slot;
    current = work3 << 7;
    current += slot;
    current <<= 2;
    work3 = 0x35AC;
    BIND(work3);
    pointer1 = pointer4 + work3;
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer5 = (u8 *)(work2 + (u32)pointer0);
    work1 = *(u16 *)pointer5;
    current = 1;
    BIND(current);
    work3 = 0;
    pointer2 = stack_pointer;
    BIND(pointer2);
    *(u16 *)(pointer2 + 0x24) = work3;
    work3 = current;
    work3 |= work1;
    *(u16 *)pointer5 = work3;
    work1 = work6 << 1;
    work1 += slot;
    work6 = local.argument;
    work2 = work6 << 1;
    current = work2 + work6;
    current <<= 2;
    work1 += current;
    work6 = 0x4FD4;
    BIND(work6);
    pointer0 = pointer4 + work6;
    pointer1 = (u8 *)(work1 + (u32)pointer0);
    local.flags = pointer1;
    work1 = *pointer1;
    current = 16;
    current &= work1;
    local.doubled = work2;
    if (current == 0)
        goto inactive_target;
    current = 4;
    work3 |= current;
    pointer0 = stack_pointer;
    BIND(pointer0);
    current = *(u16 *)(pointer0 + 0x24);
    work3 |= current;
    *(u16 *)pointer5 = work3;
    work2 = side;
    BIND(work2);
    work1 = work2 << 3;
    work1 -= work2;
    current = work1 << 5;
    work1 += current;
    work1 <<= 3;
    work6 = slot;
    BIND(work6);
    current = work6 << 5;
    current += slot;
    current <<= 3;
    work6 = 0x258;
    BIND(work6);
    pointer2 = pointer4 + work6;
    pointer0 = (u8 *)(current + (u32)pointer2);
    pointer1 = (u8 *)(work1 + (u32)pointer0);
    local.unit_record = pointer1;
    current = 0x65C;
    BIND(current);
    work2 = side;
    work2 *= current;
    work1 = *pointer1;
    current = 0x94;
    current *= work1;
    work6 = 0x10C8;
    BIND(work6);
    pointer1 = pointer4 + work6;
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer2 = (u8 *)(work2 + (u32)pointer0);
    BIND(pointer2);
    unit = pointer2;
    current = *pointer7;
    work1 = 1;
    work1 &= current;
    local.active = work1;
    if (work1 != 0)
        goto active_action;
    current = 2;
    work3 |= current;
    *(u16 *)pointer5 = work3;
    pointer1 = (u8 *)0x02031410;
    BIND(pointer1);
    pointer0 = pointer7;
    BIND(pointer0);
    *(struct Block24 *)pointer1 = *(struct Block24 *)pointer0;
    current = side;
    BIND(current);
    work2 = current << 2;
    pointer2 = (u8 *)(work2 + (u32)offset_table);
    current = local.argument;
    work1 = local.selector;
    pointer3 = (u8 *)0x02031410;
    func_080C280C(current, work1, pointer2, pointer3);
    current = func_0809B834(side, slot, 0x27, 0);
    work6 = (u8)current;
    if (work6 == 0xFF)
        goto check_equipment;
    func_0809B4D0(side, slot, work6);
    current = 2;
    goto done;
check_equipment:
    current = func_0809B834(side, slot, 0x23, 0);
    work6 = (u8)current;
    pointer1 = (u8 *)0x02031C50;
    current = *pointer1;
    work2 = 0x245;
    BIND(work2);
    pointer1 = pointer4 + work2;
    work1 = *pointer1;
    func_080C08F0(current, work1, side, slot, work6, ({
                      pointer3 = (u8 *)0x02031410;
                      BIND(pointer3);
                      pointer3;
                  }),
                  ({
                      pointer4 = (u8 *)&local.result;
                      BIND(pointer4);
                      (volatile u32 *)pointer4;
                  }));
    if (work6 == 0xFF)
        goto damage_unit;
    pointer0 = (u8 *)0x02031410;
    work1 = *(u16 *)(pointer0 + 2);
    current = 2;
    current &= work1;
    if (current == 0)
        goto damage_equipment;
damage_unit:
    pointer2 = local.flags;
    work1 = *pointer2;
    current = 0x40;
    current &= work1;
    if (current == 0)
        goto subtract_health;
    current = 0xC;
    current &= work1;
    work2 = (u32)current >> 2;
    pointer0 = (u8 *)(current + (u32)unit);
    pointer0 += 0x76;
    pointer3 = stack_pointer;
    BIND(pointer3);
    work3 = *(u16 *)(pointer3 + 0x2C);
    STORE16(pointer0, work3);
    func_0809B62C(side, slot, work2);
    func_080BE46C(side, slot);
    current = *(u16 *)pointer5;
    work1 = 0x10;
    current |= work1;
    *(u16 *)pointer5 = current;
subtract_health:
    pointer4 = local.flags;
    work1 = *pointer4;
    current = 0x20;
    current &= work1;
    if (current != 0)
        goto subtract_second;
    pointer1 = (u8 *)&local.result;
    BIND(pointer1);
    pointer6 = unit;
    current = *(u16 *)(pointer6 + 6);
    work1 = *(u16 *)pointer1;
    current -= work1;
    *(u16 *)(pointer6 + 6) = current;
    pointer0 = (u8 *)&local.result;
    BIND(pointer0);
    current = *(u16 *)pointer0;
    work1 = *(u16 *)(pointer5 + 2);
    current += work1;
    goto store_damage;
subtract_second:
    pointer1 = (u8 *)&local.result;
    BIND(pointer1);
    pointer2 = unit;
    current = *(u16 *)(pointer2 + 6);
    work1 = *(u16 *)(pointer1 + 2);
    current -= work1;
    *(u16 *)(pointer2 + 6) = current;
    pointer0 = (u8 *)&local.result;
    BIND(pointer0);
    current = *(u16 *)(pointer0 + 2);
    work3 = *(u16 *)(pointer5 + 2);
    current += work3;
store_damage:
    *(u16 *)(pointer5 + 2) = current;
    pointer2 = (u8 *)0x02031A0C;
    BIND(pointer2);
    work4 = side;
    BIND(work4);
    current = work4 << 1;
    current += side;
    current <<= 1;
    current += slot;
    work6 = local.doubled;
    work3 = local.argument;
    work1 = work6 + work3;
    work1 <<= 2;
    current += work1;
    work4 = 0x4FD4;
    BIND(work4);
    pointer2 += work4;
    pointer0 = (u8 *)(current + (u32)pointer2);
    work1 = *pointer0;
    current = 0x80;
    current &= work1;
    if (current == 0)
        goto accumulate_damage;
    pointer4 = (u8 *)0x02031410;
    work1 = *(u16 *)(pointer4 + 2);
    current = 4;
    current &= work1;
    if (current == 0)
        goto apply_second_effect;
    pointer0 = unit;
    pointer0 += 0x6C;
    current = *(s16 *)pointer0;
    work1 = *(s16 *)(pointer4 + 0x14);
    current = func_080BD2F4(current, work1);
    work3 = current;
    BIND(work3);
    work3 <<= 16;
    work3 >>= 16;
    EFFECT(0x10, work3, ({
               current = pointer4[10];
               BIND(current);
               current;
           }),
           ({
               current = 0;
               BIND(current);
               current;
           }),
           ({
               current = 0xFF;
               BIND(current);
               current;
           }),
           current, current);
apply_second_effect:
    work1 = *(u16 *)(pointer4 + 2);
    current = 8;
    current &= work1;
    if (current == 0)
        goto apply_third_effect;
    work3 = *(s16 *)(pointer4 + 0x14);
    EFFECT(0x25, work3, ({
               current = pointer4[10];
               BIND(current);
               current;
           }),
           ({
               current = 0;
               BIND(current);
               current;
           }),
           ({
               current = 0xFF;
               BIND(current);
               current;
           }),
           current, current);
apply_third_effect:
    work1 = *(u16 *)(pointer4 + 2);
    current = 0x10;
    current &= work1;
    if (current == 0)
        goto accumulate_damage;
    EFFECT(0x26, 0, ({
               current = pointer4[10];
               BIND(current);
               current;
           }),
           ({
               current = 0;
               BIND(current);
               current;
           }),
           ({
               current = 0xFF;
               BIND(current);
               current;
           }),
           current, current);
    goto accumulate_damage;
damage_equipment:
    current = work6 << 3;
    current += 8;
    pointer1 = local.unit_record;
    pointer2 = pointer1 + current;
    pointer3 = local.flags;
    work1 = *pointer3;
    current = 0x20;
    current &= work1;
    if (current != 0)
        goto damage_equipment_second;
    pointer0 = (u8 *)&local.result;
    BIND(pointer0);
    work1 = *(u16 *)(pointer2 + 6);
    current = *(u16 *)pointer0;
    goto store_equipment_damage;
damage_equipment_second:
    pointer0 = (u8 *)&local.result;
    BIND(pointer0);
    work1 = *(u16 *)(pointer2 + 6);
    current = *(u16 *)(pointer0 + 2);
store_equipment_damage:
    work1 -= current;
    *(u16 *)(pointer2 + 6) = work1;
    asm("" : "=r"(work1), "=r"(work3));
    current = *(s16 *)(pointer2 + 6);
    asm("" : : "r"(work1), "r"(work3));
    if (current > 0)
        goto accumulate_damage;
    func_0809B4D0(side, slot, work6);
accumulate_damage:
    work1 = 0;
    work6 = side;
    BIND(work6);
    if (work6 == 0)
        work1 = 1;
    work4 = work1;
    pointer0 = (u8 *)0x02031A0C;
    BIND(pointer0);
    work1 = work4 << 2;
    work2 = 0x4F7C;
    BIND(work2);
    pointer0 += work2;
    pointer2 = (u8 *)(work1 + (u32)pointer0);
    asm("" : "=r"(current), "=r"(work6));
    work1 = *(s16 *)(pointer5 + 2);
    asm("" : : "r"(current), "r"(work6));
    current = *(u32 *)pointer2;
    work1 = current + work1;
    *(u32 *)pointer2 = work1;
    pointer6 = unit;
    current = *(s16 *)(pointer6 + 6);
    if (current > 0)
        goto cap_damage;
    current = work1 + current;
    *(u32 *)pointer2 = current;
    current = 0;
    *(u16 *)(pointer6 + 6) = current;
    work1 = *(u16 *)pointer5;
    current = 8;
    current |= work1;
    *(u16 *)pointer5 = current;
    pointer0 = (u8 *)0x02020E3C;
    current = pointer0[13];
    if (current != 1)
        goto second_story_battle;
    work6 = side;
    BIND(work6);
    if (work6 != 1)
        goto cap_damage;
    pointer0 = func_0809A954(1, slot, 0);
    current = *pointer0;
    if (current != 0x19)
        goto cap_damage;
    pointer0 = unit;
    *(u16 *)(pointer0 + 6) = work6;
    goto survive;
second_story_battle:
    if (current != 2)
        goto third_story_battle;
    work1 = side;
    BIND(work1);
    if (work1 != 1)
        goto cap_damage;
    pointer0 = func_0809A954(1, slot, 0);
    current = *pointer0;
    if (current != 6)
        goto cap_damage;
    work3 = side;
    pointer2 = unit;
    *(u16 *)(pointer2 + 6) = work3;
    goto survive;
third_story_battle:
    if (current != 3)
        goto cap_damage;
    work6 = side;
    BIND(work6);
    if (work6 != 1)
        goto cap_damage;
    pointer0 = func_0809A954(1, slot, 0);
    current = *pointer0;
    if (current == 0x21)
        goto restore_health;
    pointer0 = func_0809A954(1, slot, 0);
    current = *pointer0;
    if (current != 0x20)
        goto cap_damage;
restore_health:
    work1 = side;
    pointer0 = unit;
    *(u16 *)(pointer0 + 6) = work1;
survive:
    work1 = *(u16 *)pointer5;
    current = 0xFFF7;
    current &= work1;
    *(u16 *)pointer5 = current;
cap_damage:
    pointer0 = (u8 *)0x02031A0C;
    BIND(pointer0);
    work1 = work4 << 2;
    work2 = 0x4F7C;
    BIND(work2);
    pointer0 += work2;
    pointer1 = (u8 *)(work1 + (u32)pointer0);
    current = *(u32 *)pointer1;
    work2 = 0x3B9AC9FF;
    BIND(work2);
    if ((u32)current <= (u32)work2)
        goto available;
    *(u32 *)pointer1 = work2;
    goto available;
active_action:
    current = *(u16 *)(pointer7 + 2);
    current--;
    asm("" : "=r"(dispatch) : "0"(current));
    switch (dispatch) {
    case 0:
        SIMPLE_EFFECT(0xF);
        goto available;
    case 1:
        SIMPLE_EFFECT(0xB);
        goto available;
    case 2:
        LOAD_AMOUNT6;
        EFFECT(0xD, work3, ({
                   current = pointer7[10];
                   BIND(current);
                   current;
               }),
               ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               ({
                   work1 = 0x244;
                   BIND(work1);
                   pointer0 = pointer4 + work1;
                   current = *pointer0;
                   current;
               }),
               ({
                   work2 = 0x245;
                   BIND(work2);
                   pointer0 = pointer4 + work2;
                   current = *pointer0;
                   current;
               }),
               ({
                   work4 = local.selector;
                   work4;
               }));
        goto available;
    case 3:
        FIRST_EFFECT(0xB);
        work3 = *(s16 *)(pointer7 + 14);
        EFFECT(0xD, work3, ({
                   current = pointer7[10];
                   BIND(current);
                   current;
               }),
               work6, ({
                   current = *pointer5;
                   BIND(current);
                   current;
               }),
               ({
                   current = *pointer4;
                   BIND(current);
                   current;
               }),
               ({
                   work1 = local.selector;
                   work1;
               }));
        goto available;
    case 4:
        LOAD_AMOUNT2;
        EFFECT(0x13, work3, ({
                   current = pointer7[10];
                   BIND(current);
                   current;
               }),
               ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               ({
                   work6 = 0x244;
                   BIND(work6);
                   pointer0 = pointer4 + work6;
                   current = *pointer0;
                   current;
               }),
               ({
                   work1 = 0x245;
                   BIND(work1);
                   pointer0 = pointer4 + work1;
                   current = *pointer0;
                   current;
               }),
               ({
                   work2 = local.selector;
                   work2;
               }));
        goto available;
    case 5:
        SIMPLE_EFFECT(0x15);
        goto available;
    case 6:
        FIRST_EFFECT(0x13);
        work3 = *(s16 *)(pointer7 + 14);
        EFFECT(0x15, work3, ({
                   current = pointer7[10];
                   BIND(current);
                   current;
               }),
               work6, ({
                   current = *pointer5;
                   BIND(current);
                   current;
               }),
               ({
                   current = *pointer4;
                   BIND(current);
                   current;
               }),
               ({
                   work1 = local.selector;
                   work1;
               }));
        goto available;
    case 7:
        LOAD_AMOUNT2;
        EFFECT(9, work3, ({
                   current = pointer7[10];
                   BIND(current);
                   current;
               }),
               ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               ({
                   work6 = 0x244;
                   BIND(work6);
                   pointer0 = pointer4 + work6;
                   current = *pointer0;
                   current;
               }),
               ({
                   work1 = 0x245;
                   BIND(work1);
                   pointer0 = pointer4 + work1;
                   current = *pointer0;
                   current;
               }),
               ({
                   work2 = local.selector;
                   work2;
               }));
        goto available;
    case 8:
        SIMPLE_EFFECT(0x17);
        goto available;
    case 9:
        SIMPLE_EFFECT(3);
        goto available;
    case 10:
        SIMPLE_EFFECT(7);
        goto available;
    case 11:
        FIRST_EFFECT(3);
        work3 = *(s16 *)(pointer7 + 14);
        EFFECT(7, work3, ({
                   current = pointer7[10];
                   BIND(current);
                   current;
               }),
               work6, ({
                   current = *pointer5;
                   BIND(current);
                   current;
               }),
               ({
                   current = *pointer4;
                   BIND(current);
                   current;
               }),
               ({
                   work1 = local.selector;
                   work1;
               }));
        goto available;
    case 12:
        work1 = *(s16 *)(pointer7 + 12);
        func_080BE06C(unit, work1);
        current = *(s16 *)(pointer7 + 10);
        if (current == 0)
            goto heal_without_animation;
        work3 = *(s16 *)(pointer7 + 12);
        EFFECT(1, work3, ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               current, ({
                   pointer0 = (u8 *)0x02031A0C;
                   BIND(pointer0);
                   work6 = 0x244;
                   BIND(work6);
                   pointer1 = pointer0 + work6;
                   work1 = *pointer1;
                   work1;
               }),
               ({
                   work1 = 0x245;
                   BIND(work1);
                   pointer0 += work1;
                   current = *pointer0;
                   current;
               }),
               ({
                   work2 = local.selector;
                   work2;
               }));
        goto available;
    heal_without_animation:
        asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(pointer5), "=r"(work6));
        work3 = *(s16 *)(pointer7 + 12);
        asm("" : : "r"(current), "r"(work1), "r"(work2), "r"(pointer5), "r"(work6));
        func_0809B480(side, slot, 1, work3);
        goto available;
    case 13:
        asm("" : "=r"(current), "=r"(work2), "=r"(work3), "=r"(pointer4), "=r"(pointer5));
        work1 = *(s16 *)(pointer7 + 12);
        asm("" : : "r"(current), "r"(work2), "r"(work3), "r"(pointer4), "r"(pointer5));
        func_080BE0A0(unit, work1);
        asm("" : "=r"(work1), "=r"(work2), "=r"(pointer4), "=r"(pointer5), "=r"(work6));
        work3 = *(s16 *)(pointer7 + 12);
        asm("" : : "r"(work1), "r"(work2), "r"(pointer4), "r"(pointer5), "r"(work6));
        func_0809B480(side, slot, 5, work3);
        goto available;
    case 14:
        work1 = *(s16 *)(pointer7 + 12);
        func_080BE06C(unit, work1);
        work1 = *(s16 *)(pointer7 + 14);
        func_080BE0A0(unit, work1);
        work3 = *(s16 *)(pointer7 + 12);
        func_0809B480(side, slot, 1, work3);
        work3 = *(s16 *)(pointer7 + 14);
        func_0809B480(side, slot, 5, work3);
        goto available;
    case 15:
        work3 = *(s16 *)(pointer7 + 12);
        EFFECT(0x23, work3, ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               ({
                   current = pointer7[4];
                   BIND(current);
                   current;
               }),
               ({
                   work1 = 0x244;
                   BIND(work1);
                   pointer6 = pointer4 + work1;
                   current = *pointer6;
                   current;
               }),
               ({
                   work2 = 0x245;
                   BIND(work2);
                   pointer5 = pointer4 + work2;
                   current = *pointer5;
                   current;
               }),
               ({
                   current = local.selector;
                   BIND(current);
                   current;
               }));
        work1 = 0x24C;
        BIND(work1);
        pointer0 = pointer4 + work1;
        pointer0 = *(u8 **)pointer0;
        work2 = local.selector;
        work1 = work2 << 2;
        pointer0 += work1;
        pointer0 += 0x76;
        work1 = *(u16 *)pointer0;
        current = work1 << 1;
        current += work1;
        current <<= 5;
        pointer1 = (u8 *)0x0878C790;
        BIND(pointer1);
        pointer2 = (u8 *)(current + (u32)pointer1);
        current = local.selector;
        current--;
        current = (u8)current;
        if ((u32)current > 2)
            goto equipment_stats;
        pointer2 += 12;
    equipment_stats:
        pointer0 = *(u8 **)pointer2;
        work1 = *(s16 *)pointer0;
        work2 = *(u16 *)(pointer2 + 4);
        current = 3;
        current &= work2;
        work1 += current;
        work2 = work1 << 3;
        work2 -= work1;
        work2 <<= 2;
        pointer0 = (u8 *)0x087863EC;
        BIND(pointer0);
        pointer2 = (u8 *)(work2 + (u32)pointer0);
        current = *pointer5;
        work3 = current << 5;
        work3 += current;
        work1 = *pointer6;
        current = work1 << 3;
        current -= work1;
        work1 = current << 5;
        current += work1;
        current += work3;
        current <<= 3;
        pointer0 = (u8 *)(current + (u32)pointer4);
        work1 = *(u16 *)(pointer2 + 2);
        work1++;
        work4 = 0x25E;
        BIND(work4);
        pointer0 += work4;
        STORE16(pointer0, work1);
        goto available;
    case 16:
        LOAD_AMOUNT6;
        EFFECT(0x22, work3, ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               ({
                   current = pointer7[4];
                   BIND(current);
                   current;
               }),
               ({
                   work1 = 0x244;
                   BIND(work1);
                   pointer0 = pointer4 + work1;
                   current = *pointer0;
                   current;
               }),
               ({
                   work2 = 0x245;
                   BIND(work2);
                   pointer0 = pointer4 + work2;
                   current = *pointer0;
                   current;
               }),
               ({
                   work4 = local.selector;
                   work4;
               }));
        goto available;
    case 17:
        work6 = 0x250;
        BIND(work6);
        pointer0 = pointer4 + work6;
        pointer1 = *(u8 **)pointer0;
        current = pointer7[12];
        current += 5;
        pointer1 += 0x3E;
        *pointer1 = current;
        work1 = 0x244;
        BIND(work1);
        pointer0 = pointer4 + work1;
        current = *pointer0;
        work2 = 0x245;
        BIND(work2);
        pointer1 = pointer4 + work2;
        work1 = *pointer1;
        work3 = 0x246;
        BIND(work3);
        pointer2 = pointer4 + work3;
        work2 = *pointer2;
        func_080BFFA4(current, work1, work2);
        func_0809B480(side, slot, 0x2B, 0);
        goto available;
    case 18:
        LOAD_AMOUNT6;
        EFFECT(0x2C, work3, ({
                   current = 0;
                   BIND(current);
                   current;
               }),
               ({
                   current = pointer7[4];
                   BIND(current);
                   current;
               }),
               ({
                   work1 = 0x244;
                   BIND(work1);
                   pointer0 = pointer4 + work1;
                   current = *pointer0;
                   current;
               }),
               ({
                   work2 = 0x245;
                   BIND(work2);
                   pointer0 = pointer4 + work2;
                   current = *pointer0;
                   current;
               }),
               ({
                   work4 = local.selector;
                   work4;
               }));
        goto available;
    default:
        goto available;
    }
inactive_target:
    work1 = *pointer7;
    current = 1;
    current &= work1;
    if (current != 0)
        goto available;
    current = 2;
    work3 |= current;
    *(u16 *)pointer5 = work3;
available:
    current = 1;
    goto done;
unavailable:
    current = 0;
done:
    return current;
}
