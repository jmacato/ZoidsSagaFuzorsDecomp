#include "types.h"

void func_080755F4(void);
void func_0807560C(void);
void func_08075E80(u32);
void func_08075EC4(void);
void func_08075EE0(u32);
void func_08075F20(u32);
u32 func_080771BC(u8 *, u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(u32);
void func_0807A1A4(void);
void func_0807BA24(u32, u32, u32, u32, u32, u32, u32);
void func_0807BAD4(u32, u32, u32, u32, u32, u32);
void func_0807C290(u8 *);
u32 func_0807DB48(void);
void func_0807F2D4(u32);
void func_080892C8(void);
u32 func_0809B834(u32, u32, u32, u32);
void func_0809E34C(u32);
void func_0809E89C(void);
void func_080BDDE4(u8 *, u8 *, u32);
void func_080BDEB0(u32, u32, u32, u32);
void func_080BF170(u32, u32);
u32 func_080BF8F0(u32, u32);
void func_080C8FCC(u32);

register u32 work2 asm("r2");

#define BIND(value) asm("" : "+r"(value))
#define MESSAGE(value) func_0807C290((u8 *)(value))
#define PRINT_PAIR(first, second)                                                                  \
    current = *(u32 *)pointer4;                                                                    \
    func_0807BA24(current, 9, first, 18, ({                                                        \
                      work1 = 2;                                                                   \
                      work1;                                                                       \
                  }),                                                                              \
                  ({                                                                               \
                      work5 = 4;                                                                   \
                      work5;                                                                       \
                  }),                                                                              \
                  ({                                                                               \
                      work4 = 0;                                                                   \
                      work4;                                                                       \
                  }));                                                                             \
    current = *(u32 *)pointer6;                                                                    \
    func_0807BA24(current, 9, second, 18, ({                                                       \
                      work1 = 3;                                                                   \
                      work1;                                                                       \
                  }),                                                                              \
                  work5, work4)
#define PRINT_EXTRA(first, second)                                                                 \
    current = *(u32 *)pointer7;                                                                    \
    func_0807BA24(current, 9, first, 18, ({                                                        \
                      work1 = 5;                                                                   \
                      work1;                                                                       \
                  }),                                                                              \
                  work5, work4);                                                                   \
    pointer1 = table8;                                                                             \
    current = *(u32 *)pointer1;                                                                    \
    func_0807BA24(current, 9, second, 18, ({                                                       \
                      work1 = 6;                                                                   \
                      work1;                                                                       \
                  }),                                                                              \
                  work5, work4)

u32 func_0809EC70(u32 argument)
{
    volatile struct {
        u8 counts[4];
        u32 selector;
        u32 object;
    } local;
    register u32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work3 asm("r3");
    register u32 work4 asm("r4");
    register u32 work5 asm("r5");
    register u32 index6 asm("r6");
    u32 index7;
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    register u8 *pointer7 asm("r7");
    register u32 work8 asm("r8");
    register u32 sum9 asm("r9");
    register u32 next10 asm("r10");
    register u8 *table8 asm("r8");
    register u8 *table9 asm("r9");
    register u8 *table10 asm("r10");
    register u8 *base asm("r12");
    register u32 offset asm("r12");
    register u8 *stack_pointer asm("sp");
    u32 dispatch;

    current = (u8)argument;
    local.selector = current;
    pointer0 = (u8 *)0x02020E3C;
    current = *pointer0;
    if (current != 0)
        goto select;
    index6 = 0;
clear_units:
    current = func_0809B834(0, index6, 0x2A, 0);
    current = (u8)current;
    if (current != 0xFF)
        func_080BF170(0, index6);
    current = index6 + 1;
    index6 = (u8)current;
    if (index6 <= 5)
        goto clear_units;
    index6 = 0;
copy_units:
    index7 = 0;
    current = index6 + 1;
    work8 = current;
    current = index6 << 1;
    work2 = current + index6;
    pointer4 = (u8 *)0x0202897C;
    pointer3 = (u8 *)0x02033C1A;
copy_unit_bytes:
    current = index7 + work2;
    pointer1 = (u8 *)(current + (u32)pointer4);
    pointer0 = (u8 *)(current + (u32)pointer3);
    current = *pointer0;
    *pointer1 = current;
    current = index7 + 1;
    index7 = (u8)current;
    if (index7 <= 2)
        goto copy_unit_bytes;
    pointer7 = (u8 *)0x02020E4C;
    work1 = 0x7A6A;
    pointer0 = (u8 *)((u32)pointer7 + work1);
    pointer1 = (u8 *)(index6 + (u32)pointer0);
    current = *pointer1;
    if (current == 0)
        goto copied_unit;
    work2 = 0x94;
    work1 = current;
    work1 *= work2;
    pointer0 = pointer7 + 0x3C;
    pointer4 = (u8 *)(work1 + (u32)pointer0);
    work1 = index6;
    work1 *= work2;
    pointer0 = (u8 *)0x02032AD4;
    pointer5 = (u8 *)(work1 + (u32)pointer0);
    current = *(u16 *)(pointer5 + 6);
    work3 = 0;
    *(u16 *)(pointer4 + 6) = current;
    work1 = *(u16 *)(pointer5 + 4);
    work2 = 2;
    current = 2;
    current &= work1;
    if (current != 0) {
        current = *(u16 *)(pointer4 + 4);
        current |= work2;
        *(u16 *)(pointer4 + 4) = current;
        func_080BDEB0(index6, work1, work2, work3);
    }
    current = *pointer5;
    *pointer4 = current;
    current = pointer4[2];
    if (current == 0xFF)
        goto copy_without_part;
    work1 = current;
    BIND(work1);
    work1 <<= 6;
    work2 = 0x6BC4;
    pointer0 = pointer7;
    pointer0 += work2;
    pointer1 = (u8 *)(work1 + (u32)pointer0);
    func_080BDDE4(pointer4, pointer1, 0);
    goto copied_unit;
copy_without_part:
    func_080BDDE4(pointer4, 0, 0);
copied_unit:
    work1 = work8;
    current = work1 << 24;
    index6 = current >> 24;
    if (index6 <= 5)
        goto copy_units;
    index7 = 0;
    work2 = 0x02031A0C;
    base = (u8 *)work2;
    pointer3 = (u8 *)0x02028818;
    work2 = 0x4E92;
    pointer2 = (u8 *)(work2 + (u32)base);
copy_selection:
    pointer1 = (u8 *)(index7 + (u32)pointer3);
    pointer0 = (u8 *)(index7 + (u32)pointer2);
    current = *pointer0;
    *pointer1 = current;
    current = index7 + 1;
    index7 = (u8)current;
    if (index7 <= 9)
        goto copy_selection;
select:
    current = local.selector;
    current--;
    asm("" : "=r"(dispatch) : "0"(current));
    switch (dispatch) {
    case 0:
        pointer4 = (u8 *)0x02020E3C;
        current = pointer4[13];
        current--;
        current = (u8)current;
        if (current <= 2)
            goto done;
        func_08075EC4();
        func_08075E80(0x69);
        MESSAGE(0x08004F26);
        current = *pointer4;
        if (current != 0)
            goto finish;
        current = 0;
        sum9 = current;
        work8 = current;
        index6 = 0;
        pointer1 = (u8 *)0x02031A0C;
        BIND(pointer1);
        base = pointer1;
        pointer3 = (u8 *)0x0875A0C4;
        BIND(pointer3);
        pointer2 = (u8 *)0x0200C4AC;
        BIND(pointer2);
        table10 = pointer2;
        pointer7 = pointer3;
        work1 = pointer4[3];
        current = work1 << 3;
        current += work1;
        current <<= 3;
        current += work1;
        work5 = current << 2;
        work1 = pointer4[2];
        current = 0x111C;
        work1 *= current;
    reward_sum:
        current = index6 << 1;
        current += index6;
        current <<= 4;
        current += work5;
        work2 = current + work1;
        pointer0 = (u8 *)(work2 + (u32)pointer7);
        current = pointer0[4];
        if (current != 0) {
            pointer0 = pointer3 + 0x2C;
            pointer0 = (u8 *)(work2 + (u32)pointer0);
            current = *(u32 *)pointer0;
            work8 += current;
            pointer0 = pointer3 + 0x30;
            pointer0 = (u8 *)(work2 + (u32)pointer0);
            current = *(u32 *)pointer0;
            sum9 += current;
        }
        current = index6 + 1;
        index6 = (u8)current;
        if (index6 <= 5)
            goto reward_sum;
        current = 0x4E6F;
        BIND(current);
        pointer0 = (u8 *)(current + (u32)base);
        current = *pointer0;
        if (current == 13) {
            work1 = sum9;
            work1 <<= 1;
            sum9 = work1;
        }
        if (current == 14) {
            work2 = work8;
            work2 <<= 1;
            work8 = work2;
        }
        index7 = 1;
        current = work8;
        BIND(current);
        index6 = current >> 1;
        pointer4 = (u8 *)0x02020E4C;
        work3 = 0x6BC4;
        BIND(work3);
        work2 = 0x6BC7;
    find_part:
        current = index7 << 6;
        pointer1 = (u8 *)(current + (u32)pointer4);
        pointer0 = pointer1 + work3;
        current = *pointer0;
        if (current == 0)
            goto next_part;
        pointer0 = pointer1 + work2;
        work1 = *pointer0;
        current = 1;
        current &= work1;
        if (current == 0)
            goto found_part;
    next_part:
        current = index7 + 1;
        index7 = (u8)current;
        if (index7 <= 52)
            goto find_part;
    found_part:
        work1 = work8;
        BIND(work1);
        pointer2 = table10;
        *(u32 *)pointer2 = work1;
        *(u32 *)(pointer2 + 4) = index6;
        current = sum9;
        BIND(current);
        *(u32 *)(pointer2 + 8) = current;
        if (index7 > 52)
            goto no_new_part;
        MESSAGE(0x08004FCE);
        goto give_rewards;
    no_new_part:
        MESSAGE(0x08005090);
    give_rewards:
        work5 = 0;
        index7 = 1;
        pointer1 = (u8 *)0x02027A10;
        BIND(pointer1);
        table10 = pointer1;
    reward_part:
        current = index7 << 6;
        pointer2 = table10;
        BIND(pointer2);
        pointer4 = (u8 *)(current + (u32)pointer2);
        current = *pointer4;
        if (current == 0)
            goto next_reward;
        work2 = work8;
        work1 = pointer4[3];
        current = 1;
        current &= work1;
        if (current == 0)
            work2 = index6;
        current = func_080BF8F0(index7, work2);
        if (current == 0)
            goto next_reward;
        if (work5 == 0) {
            MESSAGE(0x08005240);
            asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work3));
            asm("" : "+r"(pointer4), "+r"(work5), "+r"(index6), "+r"(index7));
            current =
                func_080771BC((u8 *)0x085ECCF0, (u8 *)0x085ECCFC, 0, 24, ({
                                  current = 40;
                                  BIND(current);
                                  current;
                              }),
                              ({
                                  current = 0x300;
                                  BIND(current);
                                  current;
                              }),
                              ({
                                  current = 12;
                                  BIND(current);
                                  current;
                              }),
                              ({
                                  current = 8;
                                  BIND(current);
                                  current;
                              }),
                              ({
                                  asm volatile(""
                                               :
                                               : "r"(current), "r"(work1), "r"(work2), "r"(work3),
                                                 "r"(pointer4), "r"(work5), "r"(index6), "r"(index7)
                                               : "r11", "r12");
                                  work5;
                              }));
            local.object = current;
            work5 = 1;
        }
        func_0809E34C(index7);
        pointer1 = pointer4 + 0x2E;
        current = *pointer1;
        if (current != 0) {
            work1 = current;
            current = 0x94;
            current *= work1;
            pointer1 = (u8 *)0x02020E88;
            pointer0 = (u8 *)(current + (u32)pointer1);
            func_080BDDE4(pointer0, pointer4, 0);
        }
    next_reward:
        current = index7 + 1;
        index7 = (u8)current;
        if (index7 <= 52)
            goto reward_part;
        if (work5 != 0) {
            current = local.object;
            func_080771F4(current);
            MESSAGE(0x08005259);
        }
        current = sum9;
        func_0807F2D4(current);
        func_0809E89C();
        index7 = 0;
        pointer5 = (u8 *)0x02020E4C;
        work2 = 0x6BC4;
        pointer6 = pointer5 + work2;
    update_units:
        work1 = 0x7A6A;
        BIND(work1);
        pointer0 = pointer5 + work1;
        pointer1 = (u8 *)(index7 + (u32)pointer0);
        current = *pointer1;
        if (current == 0)
            goto updated_unit;
        work1 = current;
        current = 0x94;
        work1 *= current;
        pointer0 = pointer5 + 0x3C;
        pointer4 = (u8 *)(work1 + (u32)pointer0);
        work1 = *(u32 *)(pointer4 + 0x70);
        current = 0x3B9AC9FE;
        if (work1 > current)
            goto updated_unit;
        current = work1 + 1;
        *(u32 *)(pointer4 + 0x70) = current;
        current = pointer4[2];
        if (current == 0xFF)
            goto update_without_part;
        work1 = current;
        BIND(work1);
        work1 <<= 6;
        pointer1 = (u8 *)(work1 + (u32)pointer6);
        func_080BDDE4(pointer4, pointer1, 0);
        goto updated_unit;
    update_without_part:
        func_080BDDE4(pointer4, 0, 0);
    updated_unit:
        current = index7 + 1;
        index7 = (u8)current;
        if (index7 <= 5)
            goto update_units;
        pointer1 = (u8 *)0x02020E4C;
        BIND(pointer1);
        current = 0x7B49;
        BIND(current);
        pointer2 = pointer1 + current;
        current = *pointer2;
        if (current == 0)
            goto finish;
        current = 0;
        sum9 = current;
        index7 = 0;
    count_types:
        pointer3 = stack_pointer;
        BIND(pointer3);
        pointer3 += index7;
        pointer3 += 20;
        BIND(pointer3);
        current = 0;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer3));
            *address = current;
            pointer3 = address;
        }
        work4 = index7 << 2;
        pointer2 = (u8 *)0x02028996;
        work1 = *pointer2;
        work1 <<= 4;
        work1 = work4 + work1;
        pointer0 = (u8 *)0x02028995;
        work2 = *pointer0;
        current = work2 << 2;
        current += work2;
        current <<= 5;
        work1 += current;
        pointer2 = (u8 *)0x0877C7FC;
        BIND(pointer2);
        pointer1 = (u8 *)(work1 + (u32)pointer2);
        current = *pointer1;
        work1 = index7 + 1;
        BIND(work1);
        next10 = work1;
        if (current == 0)
            goto counted_type;
        index6 = 0;
        pointer2 = (u8 *)0x02020E3C;
        work1 = pointer2[3];
        current = work1 << 3;
        current += work1;
        current <<= 3;
        current += work1;
        current <<= 2;
        BIND(current);
        work8 = current;
        work1 = pointer2[2];
        current = 0x111C;
        work2 = work1;
        work2 *= current;
        offset = work2;
        work5 = work4;
    count_units:
        current = index6 << 1;
        current += index6;
        current <<= 4;
        current += work8;
        current += offset;
        pointer1 = (u8 *)0x0875A0C4;
        pointer4 = (u8 *)(current + (u32)pointer1);
        current = pointer4[8];
        if (current != 0)
            goto counted_unit;
        pointer0 = (u8 *)0x02028996;
        BIND(pointer0);
        work2 = *pointer0;
        work2 <<= 4;
        work2 = work5 + work2;
        pointer0 = (u8 *)0x02028995;
        BIND(pointer0);
        work1 = *pointer0;
        current = work1 << 2;
        current += work1;
        current <<= 5;
        work2 += current;
        pointer1 = (u8 *)0x0877C7FC;
        BIND(pointer1);
        pointer2 = (u8 *)(work2 + (u32)pointer1);
        current = pointer4[4];
        work2 = *pointer2;
        if (current != work2)
            goto counted_unit;
        pointer2 = (u8 *)0x02028997;
        BIND(pointer2);
        pointer0 = (u8 *)(index7 + (u32)pointer2);
        work1 = *pointer3;
        current = *pointer0;
        if (current <= work1)
            goto counted_unit;
        current = work1 + 1;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer3));
            *address = current;
            pointer3 = address;
        }
    counted_unit:
        current = index6 + 1;
        index6 = (u8)current;
        if (index6 <= 5)
            goto count_units;
    counted_type:
        work3 = *pointer3;
        if (work3 == 0)
            goto next_type;
        pointer1 = (u8 *)0x02028997;
        pointer0 = (u8 *)(index7 + (u32)pointer1);
        work1 = *pointer0;
        work1 -= work3;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        current = sum9;
        current += 2;
        current = (u8)current;
        sum9 = current;
        work1 <<= 24;
        if (work1 == 0) {
            current += 2;
            current = (u8)current;
            sum9 = current;
        }
    next_type:
        work2 = next10;
        current = work2 << 24;
        index7 = current >> 24;
        if (index7 <= 1)
            goto count_types;
        current = sum9;
        if (current == 0)
            goto finish;
        current += 2;
        current = (u8)current;
        sum9 = current;
        func_08075EE0(0x68);
        MESSAGE(0x0800536F);
        work2 = 16;
        work1 = sum9;
        work2 -= work1;
        current = work2 >> 31;
        work2 += current;
        work2 = (s32)work2 >> 1;
        work2 <<= 24;
        work2 >>= 24;
        func_0807BAD4(5, 2, work2, 26, work1, 0);
        index7 = 0;
        pointer2 = (u8 *)0x02020E4C;
        BIND(pointer2);
        table8 = pointer2;
        current = 0;
        next10 = current;
        pointer1 = (u8 *)0x02009480;
        BIND(pointer1);
        table9 = pointer1;
    show_types:
        pointer3 = stack_pointer;
        BIND(pointer3);
        pointer3 += index7;
        pointer3 += 20;
        BIND(pointer3);
        current = *pointer3;
        if (current == 0)
            goto next_shown_type;
        work2 = index7 << 2;
        current = 0x7B4A;
        BIND(current);
        pointer0 = (u8 *)(current + (u32)table8);
        current = *pointer0;
        current <<= 4;
        work2 += current;
        current = 0x7B49;
        BIND(current);
        pointer0 = (u8 *)(current + (u32)table8);
        work1 = *pointer0;
        current = work1 << 2;
        current += work1;
        current <<= 5;
        work2 += current;
        pointer0 = (u8 *)0x0877C7FC;
        BIND(pointer0);
        pointer2 = (u8 *)(work2 + (u32)pointer0);
        current = *pointer2;
        pointer1 = (u8 *)0x0200C4BC;
        BIND(pointer1);
        *pointer1 = current;
        pointer1 = (u8 *)0x0200C4AC;
        BIND(pointer1);
        current = *pointer3;
        *(u32 *)pointer1 = current;
        MESSAGE(0x08005389);
        pointer6 = (u8 *)0x181C;
        BIND(pointer6);
        pointer6 += (u32)table9;
        work2 = next10;
        *(u16 *)pointer6 = work2;
        work5 = 0x181E;
        BIND(work5);
        pointer5 = (u8 *)work5;
        pointer5 += (u32)table9;
        current = *(u16 *)pointer5;
        current += 2;
        *(u16 *)pointer5 = current;
        pointer1 = (u8 *)0x02028997;
        pointer0 = (u8 *)(index7 + (u32)pointer1);
        work4 = *pointer0;
        if (work4 != 0)
            goto next_shown_type;
        MESSAGE(0x080053A7);
        *(u16 *)pointer6 = work4;
        current = *(u16 *)pointer5;
        current += 2;
        *(u16 *)pointer5 = current;
    next_shown_type:
        current = index7 + 1;
        index7 = (u8)current;
        if (index7 <= 1)
            goto show_types;
        func_0807A1A4();
        pointer4 = (u8 *)0x0300000E;
        work5 = 3;
    wait_input:
        func_080C8FCC(1);
        work1 = *(u16 *)pointer4;
        current = work5;
        current &= work1;
        if (current == 0)
            goto wait_input;
        func_08075F20(0xCD);
        goto finish;
    case 1:
        func_08075EC4();
        func_08075E80(0x6A);
        MESSAGE(0x08004F56);
        pointer0 = (u8 *)0x02020E3C;
        current = *pointer0;
        if (current != 0)
            goto finish;
        func_080892C8();
        goto finish;
    case 2:
        MESSAGE(0x08004FB8);
        goto finish;
    case 3:
        func_08075F20(0xE5);
        MESSAGE(0x080041E5);
        goto finish;
    case 4:
        pointer0 = (u8 *)0x02031A0C;
        work2 = 0x4F7C;
        pointer4 = pointer0 + work2;
        work1 = 0x4F80;
        BIND(work1);
        pointer6 = pointer0 + work1;
        work2 = *(u32 *)pointer4;
        work1 = *(u32 *)pointer6;
        if (work2 <= work1)
            goto score_not_greater;
        func_08075EC4();
        func_08075E80(0x69);
        MESSAGE(0x080053C3);
        PRINT_PAIR(2, 0);
        MESSAGE(0x08004F26);
        asm volatile("" : : "r"(work4));
        work2 = 1;
        goto store_result;
    score_not_greater:
        if (work2 >= work1)
            goto equal_score;
        func_08075EC4();
        func_08075E80(0x6A);
        MESSAGE(0x080053C3);
        PRINT_PAIR(0, 2);
        MESSAGE(0x08004F84);
        current = 2;
        local.selector = current;
        goto finish;
    equal_score:
        work1 = 0x5410;
        BIND(work1);
        pointer7 = pointer0 + work1;
        work2 = 0x5414;
        pointer2 = (u8 *)(work2 + (u32)pointer0);
        BIND(pointer2);
        table8 = pointer2;
        work1 = *(u32 *)pointer7;
        current = *(u32 *)pointer2;
        if (work1 >= current)
            goto time_not_less;
        func_08075EC4();
        func_08075E80(0x69);
        MESSAGE(0x08005438);
        PRINT_PAIR(0, 0);
        PRINT_EXTRA(2, 0);
        MESSAGE(0x08004F26);
        work2 = 1;
        goto store_result;
    time_not_less:
        if (work1 <= current)
            goto equal_time;
        func_08075EC4();
        func_08075E80(0x6A);
        MESSAGE(0x08005438);
        PRINT_PAIR(0, 0);
        PRINT_EXTRA(0, 2);
        MESSAGE(0x08004F84);
        work2 = 2;
        goto store_result;
    equal_time:
        MESSAGE(0x08005438);
        PRINT_PAIR(0, 0);
        PRINT_EXTRA(0, 0);
        MESSAGE(0x08004FB8);
        work2 = 3;
    store_result:
        local.selector = work2;
    }
finish:
    pointer0 = (u8 *)0x02020E3C;
    current = *pointer0;
    if (current != 2)
        goto done;
    current = local.selector;
    if (current != 1)
        goto check_loss;
    pointer1 = (u8 *)0x020309A4;
    current = *(u16 *)pointer1;
    current++;
    *(u16 *)pointer1 = current;
    goto result_counted;
check_loss:
    work1 = local.selector;
    if (work1 != 2)
        goto result_counted;
    pointer1 = (u8 *)0x020309A4;
    current = *(u16 *)(pointer1 + 2);
    current++;
    *(u16 *)(pointer1 + 2) = current;
result_counted:
    func_0807560C();
    current = func_0807DB48();
    current <<= 24;
    if (current != 0)
        goto restore;
    func_080755F4();
    func_08075F20(0x114);
    MESSAGE(0x0800551B);
    goto done;
restore:
    func_080755F4();
done:
    return local.selector;
}
