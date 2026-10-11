#include "types.h"

void func_0807A1A4(void);
void func_0807BEF4(u32, u32, u32);
void func_0807C290(u32);
void func_08080390(u32, u32, u32);
u32 func_080803C4(void);
void func_080804DC(u32, u32, u32);
u32 func_08080510(void);
void func_08097344(void);
void func_08097B90(u32, u32);
void func_08098AC0(u32);
u8 *func_0809A908(u32, u32);
s32 func_0809A99C(u32, u32);
void func_0809A9F8(u32, u32);
void func_0809B26C(u32, u32, u32, u32, u32, u32, u32, u32, u32);
s32 func_0809B62C(u32, u32, u32);
void func_0809C284(u32, u32);
void func_0809D79C(void);
void func_0809F7CC(u32, u32);
void func_0809FCD4(u32, u32, u32, u32);
void func_080A0108(void);
void func_080B3A38(u32, u32);
void func_080B3B94(u32, u32, u32, u32);
void func_080B3C84(void);
void func_080BE06C(u32, u32);
void func_080BE0A0(u32, u32);
void func_080BE46C(u32, u32);
s32 func_080BF51C(u32, u32);
void func_080C05A4(u32, u32, u32, u32, u32);
void func_080C1B4C(u32, u32);
u32 func_080C1C68(u32, u32);
u32 func_080C1D04(u32, u32, u32);
u32 func_080C1DC8(u32, u32);
void func_080C3BF8(u32);
void func_080C3C20(u32);
void func_080C3D1C(u32, u32, u32);
void func_080C3F0C(u32, u32, u32, u32);
void func_080C3FE0(u32);
u32 func_080C40B8(u32, u32);
s32 func_080C8BAC(u32);
s32 func_080C8BE8(u32, u32);
void func_080C8FCC(u32);

#define BIND(value) asm("" : "+r"(value))
#define SET0(value)                                                                                \
    ({                                                                                             \
        current = (value);                                                                         \
        BIND(current);                                                                             \
        current;                                                                                   \
    })
#define STORE8(pointer, value)                                                                     \
    {                                                                                              \
        u8 *address;                                                                               \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = value;                                                                          \
        pointer = address;                                                                         \
    }
#define STORE16(pointer, value)                                                                    \
    {                                                                                              \
        u16 *address;                                                                              \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = value;                                                                          \
        pointer = (u8 *)address;                                                                   \
    }
#define STORE32(pointer, value)                                                                    \
    {                                                                                              \
        u32 *address;                                                                              \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = value;                                                                          \
        pointer = (u8 *)address;                                                                   \
    }
#define NEXT_SLOT(step)                                                                            \
    current = slot + step;                                                                         \
    current <<= 24;                                                                                \
    slot = (u32)current >> 24
#define SHOW(id, team, unit, amount) func_080B3B94(id, team, unit, amount)
#define EFFECT4(team, unit, id)                                                                    \
    func_0809B26C(team, unit, id, 0, SET0(1), SET0(0), work4, work4, work4)
#define EFFECT0(team, unit, id, amount)                                                            \
    func_0809B26C(team, unit, id, amount, SET0(1), SET0(0), SET0(255), current, current)
#define SELECT_UNIT(source, offset, team, result)                                                  \
    work##source = side;                                                                           \
    BIND(work##source);                                                                            \
    current = work##source << 3;                                                                   \
    current += side;                                                                               \
    current <<= 2;                                                                                 \
    work##offset = 0x4F8C;                                                                         \
    BIND(work##offset);                                                                            \
    pointer1 = pointer5 + work##offset;                                                            \
    pointer0 = (u8 *)(current + (u32)pointer1);                                                    \
    work1 = *pointer0;                                                                             \
    current = func_080C40B8(team, work1);                                                          \
    current <<= 24;                                                                                \
    result = (u32)current >> 24
#define SIMPLE_LOOP(team, id, begin, end)                                                          \
    slot = begin;                                                                                  \
    do {                                                                                           \
        SHOW(id, team, slot, 0);                                                                   \
        func_0809F7CC(team, slot);                                                                 \
        NEXT_SLOT(1);                                                                              \
    } while ((u32)slot <= end)
#define EFFECT_LOOP(team, id, display, begin, end)                                                 \
    slot = begin;                                                                                  \
    work4 = 255;                                                                                   \
    do {                                                                                           \
        EFFECT4(team, slot, id);                                                                   \
        SHOW(display, team, slot, 0);                                                              \
        func_0809F7CC(team, slot);                                                                 \
        NEXT_SLOT(1);                                                                              \
    } while ((u32)slot <= end)

#define SUMMON_BODY(kind, first_value, first_pointer)                                              \
    work5 = work2 << 6;                                                                            \
    work3 = 0x1D80;                                                                                \
    BIND(work3);                                                                                   \
    do {                                                                                           \
        work1 = *pointer6;                                                                         \
        current = work1 << 6;                                                                      \
        current += work5;                                                                          \
        current += (u32)pointer4;                                                                  \
        current += work3;                                                                          \
        current = *(u8 *)current;                                                                  \
        if (current == kind)                                                                       \
            break;                                                                                 \
        current = work1 + 1;                                                                       \
        STORE8(pointer6, current);                                                                 \
        current = (u8)current;                                                                     \
    } while ((u32)current <= 5);                                                                   \
    first_value = 0x248;                                                                           \
    BIND(first_value);                                                                             \
    first_pointer = (u8 *)(first_value + (u32)pointer4);                                           \
    BIND(first_pointer);                                                                           \
    pointer9 = first_pointer;                                                                      \
    work1 = work2 << 5;                                                                            \
    work1 = work2 + work1;                                                                         \
    work1 <<= 3;                                                                                   \
    current = slot << 5;                                                                           \
    current += slot;                                                                               \
    current <<= 3;                                                                                 \
    work3 = 0x258;                                                                                 \
    BIND(work3);                                                                                   \
    pointer2 = pointer4 + work3;                                                                   \
    current += (u32)pointer2;                                                                      \
    work1 += current;                                                                              \
    pointer0 = pointer9;                                                                           \
    STORE32(pointer0, work1);                                                                      \
    work2 = 0x24C;                                                                                 \
    BIND(work2);                                                                                   \
    pointer2 = (u8 *)(work2 + (u32)pointer4);                                                      \
    BIND(pointer2);                                                                                \
    pointer9 = pointer2;                                                                           \
    current = 0x65C;                                                                               \
    BIND(current);                                                                                 \
    work2 = side;                                                                                  \
    BIND(work2);                                                                                   \
    work2 *= current;                                                                              \
    work1 = *(u8 *)work1;                                                                          \
    current = 0x94;                                                                                \
    BIND(current);                                                                                 \
    current *= work1;                                                                              \
    work3 = 0x10C8;                                                                                \
    BIND(work3);                                                                                   \
    pointer1 = pointer4 + work3;                                                                   \
    current += (u32)pointer1;                                                                      \
    work2 += current;                                                                              \
    pointer0 = pointer9;                                                                           \
    STORE32(pointer0, work2);                                                                      \
    work1 = 0x250;                                                                                 \
    BIND(work1);                                                                                   \
    pointer2 = pointer4 + work1;                                                                   \
    current = *pointer6;                                                                           \
    current <<= 6;                                                                                 \
    work3 = 0x1D80;                                                                                \
    BIND(work3);                                                                                   \
    pointer1 = pointer4 + work3;                                                                   \
    current += (u32)pointer1;                                                                      \
    current = work5 + current;                                                                     \
    STORE32(pointer2, current);                                                                    \
    pointer0 = (u8 *)current;                                                                      \
    pointer0 += 0x3E;                                                                              \
    work5 = 0;                                                                                     \
    work1 = kind == 0x3B ? 2 : 1;                                                                  \
    STORE8(pointer0, work1);                                                                       \
    func_0809FCD4(5, side, slot, 0);                                                               \
    func_080A0108();                                                                               \
    work4 = 300;                                                                                   \
    BIND(work4);                                                                                   \
    other = work4;                                                                                 \
    func_0809B26C(side, slot, 3, other, work5, work5, ({                                           \
                      work4 = 255;                                                                 \
                      BIND(work4);                                                                 \
                      work4;                                                                       \
                  }),                                                                              \
                  work4, work4);                                                                   \
    func_0809B26C(side, slot, 7, 30, work5, work5, work4, work4, work4);                           \
    func_08097344();                                                                               \
    func_0809F7CC(side, slot);                                                                     \
    func_080B3A38(side, 2);                                                                        \
    SHOW(7, side, slot, other);                                                                    \
    func_080B3C84();                                                                               \
    SHOW(9, side, slot, 30);                                                                       \
    asm volatile("" : : "r"(slot));                                                                \
    goto finish_side

#define COMBINE_INIT(begin)                                                                        \
    pointer0 = (u8 *)0x02031A0C;                                                                   \
    BIND(pointer0);                                                                                \
    work2 = side;                                                                                  \
    BIND(work2);                                                                                   \
    work1 = work2 << 4;                                                                            \
    work3 = 0x4E72;                                                                                \
    BIND(work3);                                                                                   \
    pointer0 += work3;                                                                             \
    pointer0 = (u8 *)(work1 + (u32)pointer0);                                                      \
    STORE16(pointer0, slot);                                                                       \
    asm("" : "=r"(slot));                                                                          \
    slot = begin;                                                                                  \
    BIND(slot);                                                                                    \
    work2 <<= 3;                                                                                   \
    BIND(work2);                                                                                   \
    other = work2;                                                                                 \
    local.offset = work1;                                                                          \
    pointer4 = (u8 *)0x02031410;                                                                   \
    BIND(pointer4);                                                                                \
    pointer10 = pointer4;                                                                          \
    pointer5 = pointer0;                                                                           \
    pointer4 = pointer5;                                                                           \
    BIND(pointer4);                                                                                \
    pointer4 += 8

#define COMBINE_LOOP(mode, bound, condition)                                                       \
    do {                                                                                           \
        current = func_080C1D04(side, slot, mode);                                                 \
        current <<= 24;                                                                            \
        work6 = (u32)current >> 24;                                                                \
        pointer0 = func_0809A908(side, slot);                                                      \
        work1 = work6 << 2;                                                                        \
        pointer0 += work1;                                                                         \
        pointer0 += 0x76;                                                                          \
        current = *(u16 *)pointer0;                                                                \
        STORE16(pointer4, current);                                                                \
        if ((u32)slot condition bound) {                                                           \
            func_080C05A4(side, slot, 255, work6, ({                                               \
                              pointer0 = pointer10;                                                \
                              BIND(pointer0);                                                      \
                              (u32) pointer0;                                                      \
                          }));                                                                     \
            pointer1 = pointer10;                                                                  \
            BIND(pointer1);                                                                        \
            current = *(u16 *)(pointer1 + 12);                                                     \
            work2 = *(u16 *)pointer5;                                                              \
            current += work2;                                                                      \
            STORE16(pointer5, current);                                                            \
        }                                                                                          \
        NEXT_SLOT(2);                                                                              \
        pointer4 += 2;                                                                             \
    } while ((u32)slot <= 5)

#define COMBINE_STATS(a, b, c)                                                                     \
    work6 = 0;                                                                                     \
    pointer3 = (u8 *)0x02031A0C;                                                                   \
    BIND(pointer3);                                                                                \
    work4 = 0x4E74;                                                                                \
    BIND(work4);                                                                                   \
    pointer2 = pointer3 + work4;                                                                   \
    current = local.offset;                                                                        \
    pointer2 = (u8 *)(current + (u32)pointer2);                                                    \
    work1 = other;                                                                                 \
    BIND(work1);                                                                                   \
    work4 = side;                                                                                  \
    BIND(work4);                                                                                   \
    current = work1 - work4;                                                                       \
    work1 = current << 5;                                                                          \
    current += work1;                                                                              \
    current <<= 3;                                                                                 \
    pointer0 = (u8 *)(current + (u32)pointer3);                                                    \
    work4 = a;                                                                                     \
    BIND(work4);                                                                                   \
    pointer1 = pointer0 + work4;                                                                   \
    work1 = *pointer1;                                                                             \
    STORE16(pointer2, work1);                                                                      \
    work2 = 0x4E76;                                                                                \
    BIND(work2);                                                                                   \
    pointer1 = pointer3 + work2;                                                                   \
    work4 = local.offset;                                                                          \
    pointer1 = (u8 *)(work4 + (u32)pointer1);                                                      \
    work4 = b;                                                                                     \
    BIND(work4);                                                                                   \
    pointer2 = pointer0 + work4;                                                                   \
    work2 = *pointer2;                                                                             \
    STORE16(pointer1, work2);                                                                      \
    work1 = 0x4E78;                                                                                \
    BIND(work1);                                                                                   \
    pointer3 += work1;                                                                             \
    work2 = local.offset;                                                                          \
    pointer3 = (u8 *)(work2 + (u32)pointer3);                                                      \
    work4 = c;                                                                                     \
    BIND(work4);                                                                                   \
    pointer0 += work4;                                                                             \
    current = *pointer0;                                                                           \
    STORE16(pointer3, current)

#define COMBINE_EFFECT(unit, first, third)                                                         \
    func_0809B26C(side, unit, 0x28, 0, first, work6, third, work4, work4)

#define COMBINE_FAILURE(offset, test)                                                              \
    pointer0 = (u8 *)0x0200C4D8;                                                                   \
    pointer1 = (u8 *)0x02031A0C;                                                                   \
    BIND(pointer1);                                                                                \
    pointer1 = (u8 *)(work4 + (u32)pointer1);                                                      \
    work##offset = 0x4F85;                                                                         \
    BIND(work##offset);                                                                            \
    pointer1 += work##offset;                                                                      \
    work1 = *pointer1;                                                                             \
    STORE8(pointer0, work1);                                                                       \
    work##test = side;                                                                             \
    BIND(work##test);                                                                              \
    if (work##test == 0) {                                                                         \
        if (slot != 4)                                                                             \
            func_0807C290(0x08004AF5);                                                             \
        else                                                                                       \
            func_0807C290(0x08004B89);                                                             \
    } else {                                                                                       \
        if (slot != 4)                                                                             \
            func_0807C290(0x08004B3F);                                                             \
        else                                                                                       \
            func_0807C290(0x08004BD5);                                                             \
    }

void func_080C4104(u32 argument)
{
    volatile struct {
        u8 *saved;
        s32 offset;
    } local;
    u32 dispatch;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    register s32 work6 asm("r6");
    s32 slot;
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    register s32 side asm("r8");
    register s32 other asm("r9");
    register s32 work10 asm("r10");
    register u8 *pointer9 asm("r9");
    register u8 *pointer10 asm("r10");

    current = (u8)argument;
    side = current;
    current = 0;
    work1 = side;
    BIND(work1);
    if (work1 == 0)
        current = 1;
    other = current;
    pointer0 = (u8 *)0x02031A0C;
    BIND(pointer0);
    work3 = 0x4E6F;
    BIND(work3);
    pointer2 = pointer0 + work3;
    pointer2 += side;
    pointer4 = (u8 *)0x0200C4D8;
    work1 = side;
    BIND(work1);
    work3 = work1 << 2;
    pointer0 = (u8 *)(work3 + (u32)pointer0);
    work1 = 0x4F85;
    BIND(work1);
    pointer0 += work1;
    work1 = *pointer0;
    STORE8(pointer4, work1);
    current = *pointer0;
    STORE8(pointer2, current);
    work4 = work3;
    work2 = side;
    BIND(work2);
    if (work2 == 0)
        func_0807C290(0x0800484D);
    else
        func_0807C290(0x08004874);
    pointer0 = (u8 *)0x02031A0C;
    BIND(pointer0);
    pointer1 = (u8 *)(work4 + (u32)pointer0);
    work3 = 0x4F85;
    BIND(work3);
    pointer1 += work3;
    work1 = *pointer1;
    work1--;
    pointer5 = pointer0;
    asm("" : "=r"(current), "=r"(dispatch) : "1"(work1));
    switch (dispatch) {
    case 0:
        func_080C3BF8(side);
        slot = 0;
        do {
            current = func_0809A99C(side, slot);
            if (current != 0) {
                pointer0 = func_0809A908(side, slot);
                pointer5 = pointer0;
                pointer4 = pointer5;
                BIND(pointer4);
                pointer4 += 0x62;
                work1 = *(s16 *)pointer4;
                current = (u32)work1 >> 31;
                work1 += current;
                work1 >>= 1;
                func_080BE06C((u32)pointer5, work1);
                work3 = *(s16 *)pointer4;
                current = (u32)work3 >> 31;
                work3 += current;
                work3 >>= 1;
                SHOW(6, side, slot, work3);
                func_0809F7CC(side, slot);
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 1:
        func_080C3BF8(side);
        pointer1 = (u8 *)0x02031A0C;
        BIND(pointer1);
        work2 = side;
        BIND(work2);
        current = work2 << 3;
        current += side;
        current <<= 2;
        work3 = 0x4F8C;
        BIND(work3);
        pointer1 += work3;
        pointer0 = (u8 *)(current + (u32)pointer1);
        work1 = *pointer0;
        current = func_080C40B8(side, work1);
        current <<= 24;
        slot = (u32)current >> 24;
        if (slot != 255) {
            pointer0 = func_0809A908(side, slot);
            pointer5 = pointer0;
            pointer4 = pointer5;
            BIND(pointer4);
            pointer4 += 0x64;
            asm("" : "=r"(work1), "=r"(work2), "=r"(work6));
            work3 = *(s16 *)pointer4;
            asm("" : : "r"(work1), "r"(work2), "r"(work6));
            current = *(s16 *)(pointer5 + 8);
            work3 -= current;
            SHOW(8, side, slot, work3);
            func_0809F7CC(side, slot);
            current = *(u16 *)pointer4;
            *(u16 *)(pointer5 + 8) = current;
            func_080B3C84();
        }
        EFFECT_LOOP(side, 0x28, 3, 0, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 2:
        SELECT_UNIT(2, 3, side, work5);
        if (work5 == 255)
            goto done;
        func_080C3BF8(side);
        work4 = 0;
        slot = 0;
        do {
            current = func_0809A99C(side, slot);
            if (current != 0) {
                pointer0 = func_0809A908(side, slot);
                pointer0 += 0x66;
                work1 = (s16)work4;
                current = *(u16 *)pointer0;
                work1 += current;
                work1 <<= 16;
                work4 = (u32)work1 >> 16;
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        pointer0 = func_0809A908(side, work5);
        work4 = (s16)work4;
        BIND(work4);
        work1 = work4;
        func_080BE0A0((u32)pointer0, work1);
        SHOW(8, side, work5, work4);
        func_0809F7CC(side, work5);
        func_080B3C84();
        EFFECT0(side, work5, 0x28, 0);
        SHOW(3, side, work5, 0);
        func_0809F7CC(side, work5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 3:
        func_080C3BF8(side);
        slot = 0;
        do {
            current = func_0809A99C(side, slot);
            if (current != 0) {
                pointer0 = func_0809A908(side, slot);
                pointer5 = pointer0;
                pointer4 = pointer5;
                BIND(pointer4);
                pointer4 += 0x62;
                asm("" : "=r"(work1), "=r"(work2), "=r"(work6));
                work3 = *(s16 *)pointer4;
                asm("" : : "r"(work1), "r"(work2), "r"(work6));
                current = *(s16 *)(pointer5 + 6);
                work3 -= current;
                SHOW(6, side, slot, work3);
                func_0809F7CC(side, slot);
                current = *(u16 *)pointer4;
                *(u16 *)(pointer5 + 6) = current;
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        func_080B3C84();
        current = func_080C1C68(side, 1);
        current <<= 24;
        slot = (u32)current >> 24;
        EFFECT0(side, slot, 0x28, 0);
        SHOW(3, side, slot, 0);
        func_0809F7CC(side, slot);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 4:
        func_080C3BF8(side);
        slot = 0;
        do {
            current = func_080BF51C(side, slot);
            current <<= 24;
            if (current != 0) {
                func_0809A9F8(side, slot);
                SHOW(0x28, side, slot, 0);
                func_0809F7CC(side, slot);
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        func_080B3C84();
        current = func_080C1C68(side, 1);
        current <<= 24;
        slot = (u32)current >> 24;
        func_080B3A38(side, 1);
        pointer0 = func_0809A908(side, slot);
        pointer5 = pointer0;
        work2 = 0;
        *(u16 *)(pointer5 + 6) = work2;
        work1 = *(u16 *)(pointer5 + 4);
        current = 2;
        current |= work1;
        *(u16 *)(pointer5 + 4) = current;
        func_0809B26C(side, slot, 0x28, 0, SET0(1), work2, SET0(255), current, current);
        SHOW(4, side, slot, 0);
        func_0809F7CC(side, slot);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 5:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x20, 0x1D, 0, 5);
        func_080C3C20(side);
        func_080C3BF8(other);
        EFFECT_LOOP(other, 0x20, 0x1D, 0, 5);
        goto finish_other;
    case 6:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x1D, 0x1A, 0, 2);
        func_080B3C84();
        EFFECT_LOOP(side, 0x28, 3, 3, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 41:
        func_080C3BF8(side);
        SIMPLE_LOOP(side, 0x28, 0, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 14:
    case 15:
    case 21:
    case 33:
    case 34:
    case 48:
    case 49:
    case 50:
    case 51:
        func_080C3BF8(side);
        SIMPLE_LOOP(side, 0x2B, 0, 5);
        func_080C3C20(side);
    case 52:
        func_080C3BF8(other);
        SIMPLE_LOOP(other, 0x2B, 0, 5);
        goto finish_other;
    case 16:
        current = side;
        work1 = 1;
        goto effect_80;
    case 17:
        func_080C3D1C(side, 1, 0x40);
        goto done;
    case 18:
        current = side;
        work1 = 0;
        goto effect_zero;
    case 19:
        func_080C3D1C(side, 0, 4);
        goto done;
    case 20:
        SELECT_UNIT(2, 3, side, work5);
        func_080C3BF8(side);
        slot = 0;
        work4 = 255;
        do {
            if (work5 != slot) {
                EFFECT4(side, slot, 0x28);
                SHOW(3, side, slot, 0);
                func_0809F7CC(side, slot);
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        func_080C3C20(side);
        func_080C3BF8(other);
        EFFECT_LOOP(other, 0x28, 3, 0, 5);
        goto finish_other;
    case 22:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x28, 3, 0, 5);
        func_080C3C20(side);
        current = side;
        work1 = 9;
        asm volatile("" : : "r"(work1));
        goto effect_six_four;
    case 23:
        current = side;
        work1 = 9;
        work2 = 6;
        work3 = 5;
        goto effect_six;
    case 24:
        SELECT_UNIT(4, 2, side, slot);
        if (slot != 255) {
            func_080C3BF8(side);
            EFFECT0(side, slot, 0x28, 0);
            SHOW(3, side, slot, 0);
            func_0809F7CC(side, slot);
            func_080C3C20(side);
        }
        current = side;
        work1 = 9;
        asm volatile("" : : "r"(work1));
        goto effect_six_four;
    case 25:
        SELECT_UNIT(3, 4, side, slot);
        if (slot != 255) {
            func_080C3BF8(side);
            EFFECT0(side, slot, 0x28, 0);
            SHOW(3, side, slot, 0);
            func_0809F7CC(side, slot);
            func_080C3C20(side);
        }
        current = side;
        work1 = 10;
    effect_six_four:
        work2 = 6;
        work3 = 4;
    effect_six:
        func_080C3F0C(current, work1, work2, work3);
        func_080C3FE0(side);
        goto done;
    case 26:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x28, 3, 0, 5);
        func_080C3C20(side);
        current = side;
        BIND(current);
        if (current != 0)
            goto done;
        work1 = 0;
        pointer5 = (u8 *)0x02031A0C;
        BIND(pointer5);
        work2 = 0x4E5B;
        BIND(work2);
        pointer3 = pointer5 + work2;
        do {
            pointer2 = (u8 *)(work1 + (u32)pointer3);
            current = *pointer2;
            if (current == 0)
                goto store_available;
            current = work1 + 1;
            current <<= 24;
            work1 = (u32)current >> 24;
        } while ((u32)work1 <= 9);
        goto done;
    case 27:
        work3 = side;
        BIND(work3);
        if (work3 == 0) {
            func_080804DC(0x0200C4D8, 1, 0x080F5CA8);
            do {
                current = func_08080510();
                current <<= 24;
                work4 = (u32)current >> 24;
                func_080C8FCC(1);
            } while (work4 == 0);
            pointer0 = (u8 *)0x0200C4D8;
            current = *pointer0;
            if (current == 0) {
                func_0807C290(0x0800495E);
                goto done;
            }
            func_0807C290(0x080048EA);
            goto done;
        }
        work4 = 0;
        work6 = 0;
        pointer1 = (u8 *)0x02036867;
        BIND(pointer1);
        pointer2 = pointer1;
        BIND(pointer2);
        pointer2 += 10;
        do {
            pointer0 = (u8 *)(work6 + (u32)pointer1);
            current = *pointer0;
            if (current != 0) {
                pointer0 = (u8 *)(work4 + (u32)pointer2);
                STORE8(pointer0, work6);
                work4++;
            }
            work6++;
        } while (work6 <= 9);
        if (work4 == 0) {
            pointer0 = (u8 *)0x0200C4D8;
            STORE8(pointer0, work4);
        } else {
            pointer0 = (u8 *)0x03000010;
            current = *(u32 *)pointer0;
            current = func_080C8BAC(current);
            current *= work4;
            current = (u32)current >> 15;
            work4 = 0x4E65;
            BIND(work4);
            pointer1 = pointer5 + work4;
            pointer0 = (u8 *)(current + (u32)pointer1);
            pointer3 = (u8 *)0x0200C4D8;
            work2 = 0x4E5B;
            BIND(work2);
            pointer1 = pointer5 + work2;
            current = *pointer0;
            pointer1 += current;
            current = *pointer1;
            work2 = 0;
            STORE8(pointer3, current);
            STORE8(pointer1, work2);
        }
        func_08080390(0x0200C4D8, 1, 0x080F5CA8);
        do {
            current = func_080803C4();
            current <<= 24;
            work5 = (u32)current >> 24;
            func_080C8FCC(1);
        } while (work5 == 0);
        pointer0 = (u8 *)0x0200C4D8;
        current = *pointer0;
        if (current == 0) {
            func_0807C290(0x0800499B);
            goto done;
        }
        func_0807C290(0x08004928);
        goto done;
    case 28:
        work3 = side;
        BIND(work3);
        work1 = work3 << 3;
        work1 += side;
        work1 <<= 2;
        pointer0 = (u8 *)0x02036998;
        BIND(pointer0);
        work1 += (u32)pointer0;
        func_0809C284(side, work1);
        goto done;
    case 29:
        SELECT_UNIT(4, 2, side, slot);
        if (slot == 255)
            goto done;
        func_080C3BF8(side);
        SHOW(0x27, side, slot, 0);
        func_0809F7CC(side, slot);
        func_080C3C20(side);
        func_0809D79C();
        work6 = 0;
        work4 = 0;
        do {
            pointer0 = func_0809A908(side, slot);
            work1 = work6 << 2;
            pointer0 += work1;
            pointer0 += 0x76;
            work1 = 0;
            STORE16(pointer0, work1);
            work2 = (u8)work6;
            BIND(work2);
            current = func_0809B62C(side, slot, work2);
            work4 |= current;
            work6++;
        } while (work6 <= 3);
        if (work4 != 0)
            func_08098AC0(0);
        func_080BE46C(side, slot);
        goto done;
    case 30:
        SELECT_UNIT(3, 4, side, slot);
        if (slot == 255)
            goto done;
        func_080C3BF8(side);
        EFFECT0(side, slot, 0x27, 0);
        SHOW(0x28, side, slot, 0);
        func_0809F7CC(side, slot);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 31:
        func_080C3BF8(side);
        slot = 0;
        do {
            current = func_080C1C68(side, 1);
            current = (u8)current;
            if (current != slot) {
                SHOW(0x28, side, slot, 0);
                func_0809F7CC(side, slot);
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        func_080B3C84();
        current = func_080C1C68(side, 1);
        current <<= 24;
        slot = (u32)current >> 24;
        EFFECT0(side, slot, 0x28, 0);
        SHOW(3, side, slot, 0);
        func_0809F7CC(side, slot);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 32:
        work1 = side;
        BIND(work1);
        current = work1 << 3;
        current += side;
        work4 = current << 2;
        pointer6 = (u8 *)0x02036998;
        BIND(pointer6);
        pointer1 = (u8 *)(work4 + (u32)pointer6);
        func_0809C284(side, (u32)pointer1);
        pointer1 = pointer6 + 6;
        BIND(pointer1);
        pointer1 = (u8 *)(work4 + (u32)pointer1);
        func_0809C284(other, (u32)pointer1);
        work2 = 0xFFFFB074;
        BIND(work2);
        pointer1 = pointer6 + work2;
        work3 = pointer1[1];
        BIND(work3);
        if (other == work3)
            goto done;
        work2 = other;
        BIND(work2);
        current = work2 << 2;
        pointer1 = (u8 *)(current + (u32)pointer1);
        work3 = 0x4F84;
        BIND(work3);
        pointer0 = pointer1 + work3;
        current = *pointer0;
        if (current != 1)
            goto done;
        work2 = 0x4F85;
        BIND(work2);
        pointer0 = pointer1 + work2;
        current = *pointer0;
        if (current != 0x1D)
            goto done;
        slot = 0;
        work3 = other;
        BIND(work3);
        current = work3 << 3;
        current += other;
        work5 = current << 2;
        pointer2 = pointer6;
        work3 = work4 + 6;
        do {
            pointer1 = (u8 *)(slot + work5);
            pointer1 += (u32)pointer2;
            current = *pointer1;
            current += work3;
            pointer0 = (u8 *)(current + (u32)pointer2);
            current = *pointer0;
            STORE8(pointer1, current);
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        goto done;
    case 35:
        current = func_080C1C68(side, 0x3B);
        pointer2 = (u8 *)0x02031A0C;
        BIND(pointer2);
        work4 = 0x245;
        BIND(work4);
        pointer1 = pointer2 + work4;
        work3 = 0;
        STORE8(pointer1, current);
        current <<= 24;
        slot = (u32)current >> 24;
        work1 = 0x246;
        BIND(work1);
        pointer0 = pointer2 + work1;
        STORE8(pointer0, work3);
        work3 = side;
        BIND(work3);
        work3 <<= 3;
        BIND(work3);
        pointer4 = pointer2;
        pointer6 = pointer0;
        current = side;
        BIND(current);
        work2 = work3 - current;
        SUMMON_BODY(0x3B, work1, pointer1);
    case 36:
        current = func_080C1C68(side, 0x31);
        pointer2 = (u8 *)0x02031A0C;
        BIND(pointer2);
        work3 = 0x245;
        BIND(work3);
        pointer1 = pointer2 + work3;
        work3 = 0;
        STORE8(pointer1, current);
        current <<= 24;
        slot = (u32)current >> 24;
        work4 = 0x246;
        BIND(work4);
        pointer0 = pointer2 + work4;
        STORE8(pointer0, work3);
        work1 = side;
        BIND(work1);
        work1 <<= 3;
        BIND(work1);
        pointer4 = pointer2;
        pointer6 = pointer0;
        work3 = side;
        BIND(work3);
        work2 = work1 - work3;
        SUMMON_BODY(0x31, current, pointer0);
    case 37:
        current = func_080C1DC8(side, 0x26);
        current <<= 24;
        slot = (u32)current >> 24;
        if (slot != 0)
            goto combine_failure37;
        COMBINE_INIT(1);
        COMBINE_LOOP(0, 1, >);
        COMBINE_STATS(0x360, 0x570, 0x780);
        work5 = 1;
        BIND(work5);
        COMBINE_EFFECT(3, work5, ({
                           work4 = 255;
                           BIND(work4);
                           work4;
                       }));
        COMBINE_EFFECT(5, work5, work4);
        func_080C3BF8(side);
        SHOW(0x28, side, 1, 0);
        func_0809F7CC(side, 1);
        func_080B3C84();
        SHOW(3, side, 3, 0);
        func_0809F7CC(side, 3);
        SHOW(3, side, 5, 0);
        func_0809F7CC(side, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    combine_failure37:
        COMBINE_FAILURE(2, 3);
        pointer0 = (u8 *)0x02031A0C;
        BIND(pointer0);
        work4 = 0x4E6F;
        BIND(work4);
        pointer0 += work4;
        asm volatile("" : : "r"(pointer0));
        goto clear_effect;
    case 38:
        current = func_080C1DC8(side, 0x27);
        current <<= 24;
        slot = (u32)current >> 24;
        if (slot != 0)
            goto combine_failure38;
        COMBINE_INIT(0);
        COMBINE_LOOP(1, 2, <=);
        COMBINE_STATS(0x258, 0x468, 0x678);
        work5 = 1;
        BIND(work5);
        COMBINE_EFFECT(0, work5, ({
                           work4 = 255;
                           BIND(work4);
                           work4;
                       }));
        COMBINE_EFFECT(2, work5, work4);
        func_080C3BF8(side);
        SHOW(0x28, side, 4, 0);
        func_0809F7CC(side, 4);
        func_080B3C84();
        SHOW(3, side, 0, 0);
        func_0809F7CC(side, 0);
        SHOW(3, side, 2, 0);
        func_0809F7CC(side, 2);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    combine_failure38:
        COMBINE_FAILURE(2, 3);
        pointer0 = (u8 *)0x02031A0C;
        BIND(pointer0);
        work4 = 0x4E6F;
        BIND(work4);
        pointer0 += work4;
        asm volatile("" : : "r"(pointer0));
        goto clear_effect;
    case 39:
        current = func_080C1DC8(side, 0x28);
        current <<= 24;
        slot = (u32)current >> 24;
        if (slot != 0)
            goto combine_failure39;
        current = func_080C1D04(side, 4, 0);
        current <<= 24;
        work6 = (u32)current >> 24;
        pointer0 = func_0809A908(side, 4);
        pointer4 = (u8 *)0x02031A0C;
        BIND(pointer4);
        work1 = side;
        BIND(work1);
        work5 = work1 << 4;
        work3 = 0x4E78;
        BIND(work3);
        pointer2 = pointer4 + work3;
        pointer2 = (u8 *)(work5 + (u32)pointer2);
        work1 = work6 << 2;
        pointer0 += work1;
        pointer0 += 0x76;
        current = *(u16 *)pointer0;
        *(u16 *)pointer2 = current;
        pointer0 = (u8 *)0x02031410;
        pointer9 = pointer0;
        func_080C05A4(side, 4, 255, work6, (u32)pointer0);
        work1 = 0x4E72;
        BIND(work1);
        pointer0 = pointer4 + work1;
        pointer0 = (u8 *)(work5 + (u32)pointer0);
        pointer2 = pointer9;
        work1 = *(u16 *)(pointer2 + 12);
        *(u16 *)pointer0 = work1;
        work3 = 0x4E74;
        BIND(work3);
        pointer2 = pointer4 + work3;
        pointer2 = (u8 *)(work5 + (u32)pointer2);
        work1 = side;
        BIND(work1);
        current = work1 << 3;
        current -= work1;
        work1 = current << 5;
        current += work1;
        current <<= 3;
        pointer0 = (u8 *)(current + (u32)pointer4);
        work3 = 0x360;
        BIND(work3);
        pointer1 = pointer0 + work3;
        work1 = *pointer1;
        *(u16 *)pointer2 = work1;
        work1 = 0x4E76;
        BIND(work1);
        pointer4 += work1;
        pointer5 = (u8 *)(work5 + (u32)pointer4);
        work2 = 0x678;
        BIND(work2);
        pointer0 += work2;
        current = *pointer0;
        *(u16 *)pointer5 = current;
        func_0809B26C(side, 4, 0x28, 0, SET0(1), slot, SET0(255), current, current);
        func_080C3BF8(side);
        SHOW(0x28, side, 1, 0);
        func_0809F7CC(side, 1);
        func_080B3C84();
        SHOW(3, side, 4, 0);
        func_0809F7CC(side, 4);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    combine_failure39:
        COMBINE_FAILURE(3, 4);
        pointer0 = (u8 *)0x02031A0C;
        BIND(pointer0);
        work1 = 0x4E6F;
        BIND(work1);
        pointer0 += work1;
    clear_effect:
        pointer0 += side;
        work1 = 0;
        STORE8(pointer0, work1);
        goto done;
    case 40:
        work3 = side;
        BIND(work3);
        work2 = work3 << 4;
        work4 = 0x4E72;
        BIND(work4);
        pointer1 = pointer5 + work4;
        pointer1 = (u8 *)(work2 + (u32)pointer1);
        current = 0;
        STORE16(pointer1, current);
        work5 = 0;
        slot = 0;
        local.offset = work2;
        local.saved = pointer1;
        do {
            current = func_0809A99C(side, slot);
            if (current != 0) {
                work4 = 0;
                work6 = 0;
                work5++;
                BIND(work5);
                work10 = work5;
                do {
                    pointer0 = func_0809A908(side, slot);
                    work1 = work6 << 2;
                    pointer0 += work1;
                    pointer0 += 0x76;
                    current = *(u16 *)pointer0;
                    if (current != 0) {
                        pointer5 = (u8 *)0x02031410;
                        BIND(pointer5);
                        func_080C05A4(side, slot, 255, work6, (u32)pointer5);
                        work1 = *(u16 *)pointer5;
                        work2 = 0x801;
                        BIND(work2);
                        current = work2;
                        current &= work1;
                        if (current == 0) {
                            current = (s16)work4;
                            asm("" : "=r"(work2));
                            work1 = *(s16 *)(pointer5 + 12);
                            asm("" : : "r"(work2));
                            if (current < work1)
                                work4 = *(u16 *)(pointer5 + 12);
                        }
                    }
                    current = work6 + 1;
                    current <<= 24;
                    work6 = (u32)current >> 24;
                } while ((u32)work6 <= 7);
                current = (s16)work4;
                pointer4 = local.saved;
                work4 = *(u16 *)pointer4;
                current += work4;
                pointer1 = local.saved;
                STORE16(pointer1, current);
                work2 = work10;
                BIND(work2);
                current = work2 << 24;
                work5 = (u32)current >> 24;
            }
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        work4 = 0x02031A0C;
        BIND(work4);
        work3 = 0x4E72;
        BIND(work3);
        work4 += work3;
        current = local.offset;
        pointer4 = (u8 *)(current + work4);
        current = *(s16 *)pointer4;
        work1 = work5;
        current = func_080C8BE8(current, work1);
        STORE16(pointer4, current);
        func_080C3BF8(other);
        slot = 0;
        do {
            asm("" : "=r"(current), "=r"(work1), "=r"(work5), "=r"(work6));
            work3 = *(s16 *)pointer4;
            asm("" : : "r"(current), "r"(work1), "r"(work5), "r"(work6));
            work3 = -work3;
            SHOW(14, other, slot, work3);
            func_0809F7CC(other, slot);
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        goto finish_other;
    case 42:
        func_080C3D1C(side, 0, 1);
        goto done;
    case 43:
        func_080C3D1C(side, 0, 2);
        goto done;
    case 44:
        func_080C3D1C(side, 0, 3);
        goto done;
    case 45:
        current = side;
        work1 = 2;
    effect_80:
        work2 = 0x80;
        func_080C3D1C(current, work1, work2);
        goto done;
    case 46:
        current = func_080C1C68(side, 0x12);
        current <<= 24;
        slot = (u32)current >> 24;
        func_0809FCD4(5, side, slot, 0);
        func_080A0108();
        work3 = 300;
        BIND(work3);
        other = work3;
        work5 = 0;
        func_0809B26C(side, slot, 3, work3, work5, work5, ({
                          work4 = 255;
                          BIND(work4);
                          work4;
                      }),
                      work4, work4);
        func_0809B26C(side, slot, 7, 30, work5, work5, work4, work4, work4);
        pointer0 = func_0809A908(side, slot);
        pointer5 = pointer0;
        work1 = other;
        BIND(work1);
        func_080BE06C((u32)pointer0, work1);
        func_080BE0A0((u32)pointer5, 30);
        func_0809F7CC(side, slot);
        func_080B3A38(side, 2);
        SHOW(7, side, slot, other);
        func_080B3C84();
        SHOW(9, side, slot, 30);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 47:
        SELECT_UNIT(4, 2, side, slot);
        if (slot == 255)
            goto done;
        func_080C3BF8(side);
        EFFECT0(side, slot, 0x22, 1);
        SHOW(0x25, side, slot, 1);
        func_0809F7CC(side, slot);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 53:
        SELECT_UNIT(3, 4, other, slot);
        if (slot == 255)
            goto done;
        func_0809FCD4(2, other, 0, 0);
        func_080A0108();
        func_08097B90(other, slot);
        goto done;
    case 54:
        current = side;
        work1 = 3;
    effect_zero:
        work2 = 0;
        func_080C3D1C(current, work1, work2);
        goto done;
    case 55:
        func_080C3BF8(side);
        SIMPLE_LOOP(side, 0x28, 0, 2);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 56:
        func_080C3BF8(side);
        SIMPLE_LOOP(side, 0x28, 3, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 57:
        func_080C3BF8(side);
        slot = 0;
        do {
            func_080BE46C(side, slot);
            SHOW(0x2B, side, slot, 0);
            func_0809F7CC(side, slot);
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        func_080C3C20(side);
        func_080C3BF8(other);
        slot = 0;
        do {
            func_080BE46C(other, slot);
            SHOW(0x2B, other, slot, 0);
            func_0809F7CC(other, slot);
            NEXT_SLOT(1);
        } while ((u32)slot <= 5);
        goto finish_other;
    case 58:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x1F, 0x1C, 0, 5);
        func_080B3C84();
        EFFECT_LOOP(side, 0x1E, 0x1B, 0, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 59:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x19, 0x12, 0, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 60:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x1A, 0x14, 0, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 61:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x1B, 0x16, 0, 5);
        asm volatile("" : : "r"(slot));
        goto finish_side;
    case 62:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x1C, 0x18, 0, 5);
    finish_side:
        func_080C3C20(side);
        goto done;
    case 63:
        pointer4 = (u8 *)0x02036871;
        pointer5 = (u8 *)0x080F5CB4;
        pointer1 = pointer4;
        BIND(pointer1);
        pointer1 -= 10;
        work6 = 9;
        do {
            current = *pointer1;
            pointer1[10] = current;
            pointer1++;
            work6--;
        } while (work6 >= 0);
        func_08080390((u32)pointer4, 10, (u32)pointer5);
        pointer0 = pointer4;
        BIND(pointer0);
        pointer0 -= 10;
        func_080804DC((u32)pointer0, 10, (u32)pointer5);
        do {
            current = func_080803C4();
            current <<= 24;
            work5 = (u32)current >> 24;
            current = func_08080510();
            current <<= 24;
            work4 = (u32)current >> 24;
            func_080C8FCC(1);
        } while (work5 == 0 || work4 == 0);
        func_0807C290(0x08004249);
        work6 = 0;
        pointer5 = (u8 *)0x087A58C4;
        pointer4 = (u8 *)0x02036867;
        do {
            pointer0 = (u8 *)(work6 + (u32)pointer4);
            current = *pointer0;
            current <<= 2;
            pointer0 = (u8 *)(current + (u32)pointer5);
            work1 = *(u32 *)pointer0;
            func_0807BEF4(2, work1, 0);
            work6++;
        } while (work6 <= 9);
        pointer4 = (u8 *)0x02036871;
        goto selection_prompt63;
    selection_repeat63:
        pointer0 = (u8 *)0x0200C4A0;
        current = *pointer0;
        pointer0 = (u8 *)(current + (u32)pointer4);
        work1 = *pointer0;
        func_080C1B4C(3, work1);
    selection_prompt63:
        func_0807C290(0x08004265);
        pointer0 = (u8 *)0x0200C4A2;
        current = *pointer0;
        if (current == 0)
            goto selection_repeat63;
        goto selection_done;
    case 64:
        func_080C3BF8(side);
        EFFECT_LOOP(side, 0x21, 0x2A, 0, 5);
        func_080C3C20(side);
        func_080C3BF8(other);
        EFFECT_LOOP(other, 0x21, 0x2A, 0, 5);
    finish_other:
        func_080C3C20(other);
        goto done;
    case 65:
        current = side;
        BIND(current);
        if (current != 0)
            goto other_message;
        work1 = other;
        BIND(work1);
        current = work1 << 2;
        pointer2 = (u8 *)(current + (u32)pointer5);
        work3 = 0x4F84;
        BIND(work3);
        pointer0 = pointer2 + work3;
        current = *pointer0;
        if (current == 1) {
            pointer1 = (u8 *)0x0200C4D8;
            work4 = 0x4F85;
            BIND(work4);
            pointer0 = pointer2 + work4;
            current = *pointer0;
            STORE8(pointer1, current);
            func_0807C290(0x080049CE);
            goto done;
        }
        func_0807C290(0x08004A4A);
        goto done;
    other_message:
        work1 = other;
        BIND(work1);
        current = work1 << 2;
        pointer2 = (u8 *)(current + (u32)pointer5);
        work3 = 0x4F84;
        BIND(work3);
        pointer0 = pointer2 + work3;
        current = *pointer0;
        if (current == 1) {
            pointer1 = (u8 *)0x0200C4D8;
            work4 = 0x4F85;
            BIND(work4);
            pointer0 = pointer2 + work4;
            current = *pointer0;
            STORE8(pointer1, current);
            func_0807C290(0x08004A10);
            goto done;
        }
        func_0807C290(0x08004A89);
        goto done;
    case 66:
        current = side;
        BIND(current);
        if (current != 0)
            goto other_selection;
        func_080804DC(0x02036871, 10, 0x080F5CC0);
        do {
            current = func_08080510();
            current <<= 24;
            work4 = (u32)current >> 24;
            func_080C8FCC(1);
        } while (work4 == 0);
        func_0807C290(0x08004249);
        work6 = 0;
        pointer5 = (u8 *)0x087A58C4;
        pointer4 = (u8 *)0x02036871;
        do {
            pointer0 = (u8 *)(work6 + (u32)pointer4);
            current = *pointer0;
            current <<= 2;
            pointer0 = (u8 *)(current + (u32)pointer5);
            work1 = *(u32 *)pointer0;
            func_0807BEF4(2, work1, 0);
            work6++;
        } while (work6 <= 9);
        pointer4 = (u8 *)0x02036871;
        goto selection_prompt66;
    selection_repeat66:
        pointer0 = (u8 *)0x0200C4A0;
        current = *pointer0;
        pointer0 = (u8 *)(current + (u32)pointer4);
        work1 = *pointer0;
        func_080C1B4C(3, work1);
    selection_prompt66:
        func_0807C290(0x08004265);
        pointer0 = (u8 *)0x0200C4A2;
        current = *pointer0;
        if (current == 0)
            goto selection_repeat66;
    selection_done:
        func_0807C290(0x08004269);
        func_0807A1A4();
        goto done;
    store_available:
        work1 = 0x4F8C;
        BIND(work1);
        pointer0 = pointer5 + work1;
        current = *pointer0;
        STORE8(pointer2, current);
        goto done;
    other_selection:
        func_08080390(0x02036867, 10, 0x080F5CC0);
        do {
            current = func_080803C4();
            current <<= 24;
            work5 = (u32)current >> 24;
            func_080C8FCC(1);
        } while (work5 == 0);
        func_0807C290(0x08004ABE);
    default:
    done:
        return;
    }
}
