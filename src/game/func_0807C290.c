#include "types.h"

void func_08075F20(u32);
u8 *func_080771BC(u32, u32, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(u32);
void func_08077204(u32, u32);
void func_0807A0C8(u32);
void func_0807A1A4(void);
void func_0807AA34(u32);
u8 *func_0807B048(u32, u32);
void func_0807BAD4(u32, u32, u32, u32, u32, u32);
void func_0807BC68(u32, u32, u32, u32, u32);
void func_0807BD4C(u32);
void func_0807BD8C(u32);
void func_0807BE80(u32);
void func_080C8FCC(u32);

#define BIND(value) asm("" : "+r"(value))
#define H(offset) (*(u16 *)(record + (offset)))
#define SH(offset) (*(s16 *)(record + (offset)))
#define W(offset) (*(u32 *)(record + (offset)))
#define BYTE(offset) (record[offset])
#define STORE8(pointer, value)                                                                     \
    {                                                                                              \
        u8 *address;                                                                               \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = (value);                                                                        \
        pointer = address;                                                                         \
    }
#define STORE16(pointer, value)                                                                    \
    {                                                                                              \
        u16 *address;                                                                              \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = (value);                                                                        \
        pointer = (u8 *)address;                                                                   \
    }
#define STORE32(pointer, value)                                                                    \
    {                                                                                              \
        u32 *address;                                                                              \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = (u32)(value);                                                                   \
        pointer = (u8 *)address;                                                                   \
    }
#define HALF0                                                                                      \
    current = *(volatile u16 *)(record + 10);                                                      \
    current -= 2;                                                                                  \
    work1 = (u32)current >> 31;                                                                    \
    current += work1;                                                                              \
    current >>= 1
#define TEXT_INDEX                                                                                 \
    current = work1 << 3;                                                                          \
    current += work1;                                                                              \
    current <<= 2;                                                                                 \
    current += work1;                                                                              \
    current += count9
#define TEXT_FIRST                                                                                 \
    pointer5 = (u8 *)0x0200C62E;                                                                   \
    BIND(pointer5);                                                                                \
    pointer3 = (u8 *)0x0200C624;                                                                   \
    BIND(pointer3);                                                                                \
    work2 = BYTE(19);                                                                              \
    pointer0 = (u8 *)(work2 + (u32)pointer3);                                                      \
    work1 = *pointer0;                                                                             \
    TEXT_INDEX;                                                                                    \
    work4 = 0x1E5A;                                                                                \
    BIND(work4);                                                                                   \
    work1 = work2;                                                                                 \
    BIND(work1);                                                                                   \
    work1 *= work4;                                                                                \
    current += work1;                                                                              \
    pointer0 = (u8 *)(current + (u32)pointer5);                                                    \
    pointer6 = text8;                                                                              \
    BIND(pointer6);                                                                                \
    work1 = *pointer6;                                                                             \
    STORE8(pointer0, work1);                                                                       \
    current = 1;                                                                                   \
    BIND(current);                                                                                 \
    text8 += current
#define TEXT_MIDDLE                                                                                \
    work2 = BYTE(19);                                                                              \
    pointer0 = (u8 *)(work2 + (u32)pointer3);                                                      \
    work1 = *pointer0;                                                                             \
    TEXT_INDEX;                                                                                    \
    work1 = work2;                                                                                 \
    BIND(work1);                                                                                   \
    work1 *= work4;                                                                                \
    current += work1;                                                                              \
    pointer0 = (u8 *)(current + (u32)pointer5);                                                    \
    pointer2 = text8;                                                                              \
    BIND(pointer2);                                                                                \
    work1 = *pointer2;                                                                             \
    STORE8(pointer0, work1)
#define TEXT_LAST                                                                                  \
    work2 = BYTE(19);                                                                              \
    pointer3 = (u8 *)(work2 + (u32)pointer3);                                                      \
    work1 = *pointer3;                                                                             \
    TEXT_INDEX;                                                                                    \
    work1 = work2;                                                                                 \
    BIND(work1);                                                                                   \
    work1 *= work4;                                                                                \
    current += work1;                                                                              \
    pointer0 = (u8 *)(current + (u32)pointer5)
#define MARK_CHANGED                                                                               \
    current = W(0);                                                                                \
    work1 = 2;                                                                                     \
    current |= work1;                                                                              \
    W(0) = current
#define PLAY_MOVE                                                                                  \
    MARK_CHANGED;                                                                                  \
    func_08075F20(0xCC)
#define TILE_FREE                                                                                  \
    pointer0 = (u8 *)0x0201F5D0;                                                                   \
    current = *(u32 *)pointer0;                                                                    \
    current = work1 - current;                                                                     \
    current = (u16)current;                                                                        \
    func_0807AA34(current)
#define DRAW_TEXT                                                                                  \
    current = 0x1E5A;                                                                              \
    BIND(current);                                                                                 \
    work1 = work5;                                                                                 \
    BIND(work1);                                                                                   \
    work1 *= current;                                                                              \
    work2 = work4 + work6;                                                                         \
    current = work2 << 3;                                                                          \
    current += work2;                                                                              \
    current <<= 2;                                                                                 \
    current += work2;                                                                              \
    pointer2 = (u8 *)0x0200C62E;                                                                   \
    BIND(pointer2);                                                                                \
    current += (u32)pointer2;                                                                      \
    work1 += current;                                                                              \
    func_0807B048((u32)record, work1)
#define DELETE_WINDOWS                                                                             \
    pointer0 = (u8 *)0x0200C4E8;                                                                   \
    current = *(u32 *)pointer0;                                                                    \
    func_080771F4(current);                                                                        \
    pointer1 = (u8 *)0x0200C4EC;                                                                   \
    BIND(pointer1);                                                                                \
    current = *(u32 *)pointer1;                                                                    \
    func_080771F4(current);                                                                        \
    pointer2 = (u8 *)0x0200C4EC;                                                                   \
    BIND(pointer2);                                                                                \
    current = *(u32 *)(pointer2 + 4);                                                              \
    func_080771F4(current);                                                                        \
    pointer3 = (u8 *)0x0200C4EC;                                                                   \
    BIND(pointer3);                                                                                \
    current = *(u32 *)(pointer3 + 8);                                                              \
    func_080771F4(current);                                                                        \
    pointer4 = (u8 *)0x0200C4EC;                                                                   \
    BIND(pointer4);                                                                                \
    current = *(u32 *)(pointer4 + 12);                                                             \
    func_080771F4(current)

#define SPRITE_TILE(add)                                                                           \
    ({                                                                                             \
        pointer3 = (u8 *)0x0201F5CC;                                                               \
        BIND(pointer3);                                                                            \
        work2 = *(u16 *)pointer3;                                                                  \
        work2 += add;                                                                              \
        work2 = (u16)work2;                                                                        \
        work2;                                                                                     \
    })
#define SPRITE_PALETTE                                                                             \
    ({                                                                                             \
        pointer4 = (u8 *)0x0201F5CE;                                                               \
        BIND(pointer4);                                                                            \
        work2 = *(u16 *)pointer4;                                                                  \
        work2;                                                                                     \
    })
#define SPRITE_FLAGS                                                                               \
    ({                                                                                             \
        pointer2 = (u8 *)0x0201F5CB;                                                               \
        BIND(pointer2);                                                                            \
        work4 = *pointer2;                                                                         \
        work4 <<= 6;                                                                               \
        pointer3 = pointer9;                                                                       \
        BIND(pointer3);                                                                            \
        work2 = *pointer3;                                                                         \
        work2 <<= 13;                                                                              \
        work2 |= work6;                                                                            \
        work4 |= work2;                                                                            \
        work4;                                                                                     \
    })
#define SPRITE_ZERO                                                                                \
    ({                                                                                             \
        work4 = work8;                                                                             \
        BIND(work4);                                                                               \
        work4;                                                                                     \
    })
#define SPRITE_Y(sub)                                                                              \
    ({                                                                                             \
        work2 = H(6);                                                                              \
        work4 = H(10);                                                                             \
        work2 += work4;                                                                            \
        work2 -= sub;                                                                              \
        work2 <<= 19;                                                                              \
        work2 >>= 16;                                                                              \
        work2;                                                                                     \
    })
#define COPY_FORWARD(step, reload_width, first_load, second_load)                                  \
    first_load;                                                                                    \
    second_load;                                                                                   \
    current = work4 + step;                                                                        \
    BIND(current);                                                                                 \
    reload_width;                                                                                  \
    work2 = current;                                                                               \
    BIND(work2);                                                                                   \
    work2 *= work5;                                                                                \
    work2++;                                                                                       \
    work2 = work3 + work2;                                                                         \
    work2 <<= 1;                                                                                   \
    pointer2 = (u8 *)((u32)pointer6 + work2);                                                      \
    current = BYTE(20);                                                                            \
    work1 = BYTE(21);                                                                              \
    current -= work1;                                                                              \
    current <<= 1;                                                                                 \
    current += step;                                                                               \
    work4 += current;                                                                              \
    BIND(work4);                                                                                   \
    current = work4;                                                                               \
    BIND(current);                                                                                 \
    current *= work5;                                                                              \
    current++;                                                                                     \
    work3 += current;                                                                              \
    work3 <<= 1;                                                                                   \
    pointer3 = (u8 *)((u32)pointer6 + work3);                                                      \
    current = *(u16 *)pointer3;                                                                    \
    STORE16(pointer2, current)
#define LOAD3_1                                                                                    \
    asm("" : "=r"(current), "=r"(work2), "=r"(work4));                                             \
    work3 = SH(12);                                                                                \
    asm("" : : "r"(current), "r"(work2), "r"(work4))
#define LOAD4_2                                                                                    \
    asm("" : "=r"(current), "=r"(work1));                                                          \
    work4 = SH(14);                                                                                \
    asm("" : : "r"(current), "r"(work1))
#define LOAD3_4                                                                                    \
    asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work5));                                \
    work3 = SH(12);                                                                                \
    asm("" : : "r"(current), "r"(work1), "r"(work2), "r"(work5))
#define LOAD4_5                                                                                    \
    asm("" : "=r"(current), "=r"(work1), "=r"(work2));                                             \
    work4 = SH(14);                                                                                \
    asm("" : : "r"(current), "r"(work1), "r"(work2))
#define LOAD3_0                                                                                    \
    asm("" : "=r"(work1), "=r"(work2), "=r"(work4));                                               \
    work3 = SH(12);                                                                                \
    asm("" : : "r"(work1), "r"(work2), "r"(work4))
#define LOAD4_1                                                                                    \
    asm("" : "=r"(current), "=r"(work2));                                                          \
    work4 = SH(14);                                                                                \
    asm("" : : "r"(current), "r"(work2))
#define LOAD3_2                                                                                    \
    asm("" : "=r"(current), "=r"(work1), "=r"(work4), "=r"(work5));                                \
    work3 = SH(12);                                                                                \
    asm("" : : "r"(current), "r"(work1), "r"(work4), "r"(work5))
#define COPY_BACK(step, reload_width, first_load, second_load)                                     \
    first_load;                                                                                    \
    second_load;                                                                                   \
    current = work4 + step;                                                                        \
    BIND(current);                                                                                 \
    reload_width;                                                                                  \
    work2 = current;                                                                               \
    BIND(work2);                                                                                   \
    work2 *= work5;                                                                                \
    work2++;                                                                                       \
    work2 = work3 + work2;                                                                         \
    work2 <<= 1;                                                                                   \
    pointer2 = (u8 *)((u32)pointer6 + work2);                                                      \
    current = BYTE(21);                                                                            \
    work1 = BYTE(20);                                                                              \
    current -= work1;                                                                              \
    current <<= 1;                                                                                 \
    current -= step;                                                                               \
    work4 -= current;                                                                              \
    BIND(work4);                                                                                   \
    current = work4;                                                                               \
    BIND(current);                                                                                 \
    current *= work5;                                                                              \
    current++;                                                                                     \
    work3 += current;                                                                              \
    work3 <<= 1;                                                                                   \
    pointer3 = (u8 *)((u32)pointer6 + work3);                                                      \
    current = *(u16 *)pointer3;                                                                    \
    STORE16(pointer2, current)

void func_0807C290(u8 *argument)
{
    volatile struct {
        u32 flag;
        u8 *saved;
        s32 next;
    } local;
    register s32 current asm("r0");
    register u16 half0 asm("r0");
    register u16 half1 asm("r1");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    register s32 work6 asm("r6");
    register s32 work7 asm("r7");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    u8 *record;
    register u8 *text8 asm("r8");
    register s32 work8 asm("r8");
    register s32 count9 asm("r9");
    register u8 *pointer9 asm("r9");
    register u8 *script asm("r10");
    register s32 work12 asm("r12");
    register u8 *pointer12 asm("r12");

    script = argument;
next_command:
    pointer1 = script;
    BIND(pointer1);
    current = *pointer1;
    switch ((u32)current) {
    case 0:
        goto done;
    case 1:
        pointer2 = script;
        BIND(pointer2);
        current = pointer2[1];
        work1 = pointer2[2];
        work2 = pointer2[3];
        pointer4 = script;
        BIND(pointer4);
        work3 = pointer4[4];
        func_0807BAD4(current, work1, work2, work3, ({
                          work4 = pointer4[5];
                          BIND(work4);
                          work4;
                      }),
                      ({
                          pointer6 = script;
                          BIND(pointer6);
                          work5 = pointer6[9];
                          work5 <<= 24;
                          work4 = pointer6[8];
                          work4 <<= 16;
                          work5 |= work4;
                          work4 = pointer6[7];
                          work4 <<= 8;
                          work5 |= work4;
                          work4 = pointer6[6];
                          work5 |= work4;
                          work5;
                      }));
        current = 10;
        BIND(current);
        script += current;
        goto continue_script;
    case 2:
        pointer1 = script;
        BIND(pointer1);
        current = pointer1[1];
        func_0807BD4C(current);
        goto advance_two;
    case 3:
        pointer3 = script;
        BIND(pointer3);
        current = pointer3[1];
        work1 = pointer3[2];
        work2 = pointer3[3];
        work3 = pointer3[4];
        func_0807BC68(current, work1, work2, work3, ({
                          pointer5 = script;
                          BIND(pointer5);
                          work4 = pointer5[5];
                          work4;
                      }));
        work6 = 6;
        BIND(work6);
        script += work6;
        goto continue_script;
    case 4:
        pointer1 = script;
        BIND(pointer1);
        current = pointer1[1];
        func_0807BD8C(current);
    advance_two:
        work2 = 2;
        BIND(work2);
        script += work2;
        goto continue_script;
    case 5:
        func_0807A1A4();
        func_080C8FCC(1);
        work3 = 1;
        BIND(work3);
        script += work3;
        goto continue_script;
    case 6:
    case 7:
        pointer4 = script;
        BIND(pointer4);
        work1 = pointer4[1];
        current = 0x4D0;
        BIND(current);
        work1 *= current;
        pointer0 = (u8 *)0x02009480;
        BIND(pointer0);
        record = (u8 *)(work1 + (u32)pointer0);
        current = *pointer4;
        if (current == 6) {
            work5 = 2;
            BIND(work5);
            pointer5 = script + work5;
            BIND(pointer5);
            text8 = pointer5;
        } else {
            pointer0 = (u8 *)0x0200C4A8;
            pointer0 = *(u8 **)pointer0;
            text8 = pointer0;
        }
        current = W(0);
        work1 = 0x80;
        current &= work1;
        if (current == 0) {
            pointer0 = func_0807B048((u32)record, (u32)text8);
            text8 = pointer0;
            goto text_done;
        }
        work6 = 0;
        BIND(work6);
        count9 = work6;
        pointer1 = text8;
        BIND(pointer1);
        current = *pointer1;
        if (current == 0)
            goto text_done;
    text_read:
        pointer2 = text8;
        BIND(pointer2);
        work3 = *pointer2;
    text_dispatch:
        if ((u32)work3 > 31)
            goto text_character;
        pointer3 = text8;
        BIND(pointer3);
        current = *pointer3;
        current--;
        switch ((u32)current) {
        case 0:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            TEXT_FIRST;
            asm volatile("" : : "r"(pointer3));
            goto text_parameter;
        case 1:
            TEXT_FIRST;
            TEXT_MIDDLE;
            work6 = 1;
            BIND(work6);
            text8 += work6;
        text_parameter:
            TEXT_LAST;
            pointer2 = text8;
            BIND(pointer2);
            work1 = *pointer2;
            STORE8(pointer0, work1);
            goto text_advance;
        case 2:
            pointer3 = (u8 *)0x0200C62E;
            BIND(pointer3);
            pointer0 = (u8 *)0x0200C624;
            BIND(pointer0);
            work2 = BYTE(19);
            pointer0 = (u8 *)(work2 + (u32)pointer0);
            work1 = *pointer0;
            TEXT_INDEX;
            work1 = 0x1E5A;
            BIND(work1);
            work1 *= work2;
            current += work1;
            pointer0 = (u8 *)(current + (u32)pointer3);
            goto text_store;
        case 3:
        case 4:
            TEXT_FIRST;
            TEXT_MIDDLE;
            work6 = 1;
            BIND(work6);
            text8 += work6;
            TEXT_MIDDLE;
            text8 += work6;
            TEXT_LAST;
        text_store:
            pointer3 = text8;
            BIND(pointer3);
            work1 = *pointer3;
            STORE8(pointer0, work1);
            goto text_advance;
        case 9:
            pointer3 = (u8 *)0x0200C62E;
            BIND(pointer3);
            pointer4 = (u8 *)0x0200C624;
            BIND(pointer4);
            work2 = BYTE(19);
            pointer0 = (u8 *)(work2 + (u32)pointer4);
            work1 = *pointer0;
            TEXT_INDEX;
            work1 = 0x1E5A;
            BIND(work1);
            work1 *= work2;
            current += work1;
            pointer0 = (u8 *)(current + (u32)pointer3);
            work1 = 0;
            STORE8(pointer0, work1);
            func_0807BE80((u32)record);
            work1 = BYTE(19);
            pointer1 = (u8 *)(work1 + (u32)pointer4);
            current = *pointer1;
            current++;
            STORE8(pointer1, current);
            work4 = 0;
            BIND(work4);
            count9 = work4;
        default:
        text_advance:
            work5 = 1;
            BIND(work5);
            text8 += work5;
            goto text_check;
        }
    text_character:
        pointer6 = (u8 *)0x0200C62E;
        BIND(pointer6);
        pointer5 = (u8 *)0x0200C624;
        BIND(pointer5);
        work2 = BYTE(19);
        pointer0 = (u8 *)(work2 + (u32)pointer5);
        work1 = *pointer0;
        TEXT_INDEX;
        work4 = 0x1E5A;
        BIND(work4);
        work1 = work2;
        BIND(work1);
        work1 *= work4;
        current += work1;
        pointer0 = (u8 *)(current + (u32)pointer6);
        STORE8(pointer0, work3);
        current = count9;
        current++;
        current = (u8)current;
        count9 = current;
        current = 1;
        BIND(current);
        text8 += current;
        pointer1 = text8;
        BIND(pointer1);
        work3 = *pointer1;
        if (work3 != 0)
            goto text_read;
        work2 = BYTE(19);
        pointer0 = (u8 *)(work2 + (u32)pointer5);
        work1 = *pointer0;
        TEXT_INDEX;
        work1 = work2;
        BIND(work1);
        work1 *= work4;
        current += work1;
        pointer0 = (u8 *)(current + (u32)pointer6);
        STORE8(pointer0, work3);
        func_0807BE80((u32)record);
        work1 = BYTE(19);
        pointer1 = (u8 *)(work1 + (u32)pointer5);
        current = *pointer1;
        current++;
        STORE8(pointer1, current);
        work2 = 0;
        BIND(work2);
        count9 = work2;
    text_check:
        pointer3 = text8;
        BIND(pointer3);
        current = *pointer3;
        BIND(current);
        work3 = current;
        BIND(work3);
        if (work3 != 0)
            goto text_dispatch;
    text_done:
        work1 = W(0);
        current = 0x20;
        work1 &= current;
        pointer6 = text8;
        BIND(pointer6);
        pointer6++;
        if (work1 == 0)
            goto text_finish;
        current = 0x080C9470;
        BIND(current);
        work1 = 0x080C9498;
        BIND(work1);
        asm("" : "=r"(work2));
        work3 = SH(12);
        asm("" : : "r"(work2));
        work3++;
        work5 = H(4);
        BIND(work5);
        work3 += work5;
        work3 <<= 19;
        work3 >>= 16;
        pointer0 = func_080771BC(current, work1, 1, work3, ({
                                     asm("" : "=r"(work5));
                                     work2 = SH(14);
                                     asm("" : : "r"(work5));
                                     work2++;
                                     work7 = H(6);
                                     work2 += work7;
                                     work2 <<= 19;
                                     work5 = 0x80000;
                                     BIND(work5);
                                     work2 += work5;
                                     work2 >>= 16;
                                     work2;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CC;
                                     BIND(pointer2);
                                     work2 = *(u16 *)pointer2;
                                     work2 += 2;
                                     work2 = (u16)work2;
                                     work2;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CE;
                                     BIND(pointer2);
                                     work2 = *(u16 *)pointer2;
                                     work2;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CB;
                                     BIND(pointer2);
                                     work5 = *pointer2;
                                     work5 <<= 6;
                                     pointer2 = (u8 *)0x0201F5CA;
                                     BIND(pointer2);
                                     work2 = *pointer2;
                                     work2 <<= 13;
                                     work4 = 0x1020;
                                     BIND(work4);
                                     work2 |= work4;
                                     work5 |= work2;
                                     work5;
                                 }),
                                 ({
                                     work2 = 0;
                                     BIND(work2);
                                     work2;
                                 }));
        pointer1 = (u8 *)0x0200C4EC;
        BIND(pointer1);
        *(u32 *)(pointer1 + 4) = (u32)pointer0;
        func_0807A1A4();
        pointer4 = (u8 *)0x0300000E;
        work5 = 3;
        do {
            func_080C8FCC(1);
            work1 = *(u16 *)pointer4;
            current = work5;
            current &= work1;
        } while (current == 0);
        pointer0 = (u8 *)0x0200C4EC;
        current = *(u32 *)(pointer0 + 4);
        func_080771F4(current);
        func_08075F20(0xCD);
    text_finish:
        pointer1 = script;
        BIND(pointer1);
        current = pointer1[1];
        func_0807A0C8(current);
        text8 = pointer6;
        pointer2 = script;
        BIND(pointer2);
        current = *pointer2;
        if (current == 6)
            goto script_from_text;
        work3 = 2;
        BIND(work3);
        script += work3;
        goto continue_script;
    case 10:
        pointer4 = script;
        BIND(pointer4);
        work1 = pointer4[1];
        current = 0x4D0;
        BIND(current);
        work1 *= current;
        pointer0 = (u8 *)0x02009480;
        BIND(pointer0);
        record = (u8 *)(work1 + (u32)pointer0);
        pointer4 = record;
        BIND(pointer4);
        pointer4 += 0x22;
        work5 = 1;
        BIND(work5);
        count9 = work5;
        current = H(8);
        current--;
        work6 = 2;
        BIND(work6);
        pointer6 = script + work6;
        BIND(pointer6);
        text8 = pointer6;
        if (count9 < current) {
            pointer5 = (u8 *)0x0201F5C4;
            do {
                work1 = *(u16 *)pointer4;
                work2 = 0x3FF;
                BIND(work2);
                current = work2;
                BIND(current);
                work1 &= current;
                current = *(u32 *)pointer5;
                if ((u32)work1 < (u32)current)
                    goto tile_free10;
                current += 0x40;
                if ((u32)work1 >= (u32)current) {
                tile_free10:
                    TILE_FREE;
                }
                current = *(u32 *)pointer5;
                current += 6;
                pointer1 = (u8 *)0x0201F5C8;
                BIND(pointer1);
                work1 = *(u16 *)pointer1;
                current |= work1;
                STORE16(pointer4, current);
                pointer4 += 2;
                work3 = 1;
                BIND(work3);
                count9 += work3;
                current = H(8);
                current--;
            } while (count9 < current);
        }
        work4 = H(12);
        work5 = H(14);
        work6 = BYTE(18);
        work1 = 0;
        current = 0;
        H(12) = current;
        current = 0xFFFF;
        BIND(current);
        H(14) = current;
        BYTE(18) = work1;
        pointer1 = (u8 *)0x080C9794;
        BIND(pointer1);
        func_0807B048((u32)record, (u32)pointer1);
        pointer0 = func_0807B048((u32)record, (u32)text8);
        text8 = pointer0;
        BIND(text8);
        MARK_CHANGED;
        current = 1;
        BIND(current);
        pointer0 = text8 + current;
        BIND(pointer0);
        script = pointer0;
        H(12) = work4;
        H(14) = work5;
        BYTE(18) = work6;
        goto continue_script;
    case 11:
        pointer2 = script;
        BIND(pointer2);
        work1 = pointer2[1];
        current = 0x4D0;
        BIND(current);
        work1 *= current;
        pointer0 = (u8 *)0x02009480;
        BIND(pointer0);
        record = (u8 *)(work1 + (u32)pointer0);
        pointer4 = record;
        BIND(pointer4);
        pointer4 += 0x22;
        work3 = 1;
        BIND(work3);
        count9 = work3;
        current = H(8);
        current--;
        work5 = 2;
        BIND(work5);
        pointer5 = script + work5;
        BIND(pointer5);
        text8 = pointer5;
        if (count9 < current) {
            pointer5 = (u8 *)0x0201F5C4;
            do {
                work1 = *(u16 *)pointer4;
                work6 = 0x3FF;
                BIND(work6);
                current = work6;
                BIND(current);
                work1 &= current;
                current = *(u32 *)pointer5;
                if ((u32)work1 < (u32)current)
                    goto tile_free11;
                current += 0x40;
                if ((u32)work1 >= (u32)current) {
                tile_free11:
                    TILE_FREE;
                }
                current = *(u32 *)pointer5;
                current += 6;
                pointer1 = (u8 *)0x0201F5C8;
                BIND(pointer1);
                work1 = *(u16 *)pointer1;
                current |= work1;
                STORE16(pointer4, current);
                pointer4 += 2;
                current = 1;
                BIND(current);
                count9 += current;
                current = H(8);
                current--;
            } while (count9 < current);
        }
    script_from_text:
        script = text8;
        goto continue_script;
    case 8:
        pointer1 = script;
        BIND(pointer1);
        current = pointer1[1];
        func_0807A0C8(current);
        pointer0 = (u8 *)0x0200C4FC;
        record = *(u8 **)pointer0;
        pointer2 = script;
        BIND(pointer2);
        work1 = pointer2[2];
        current = 0x3E;
        current &= work1;
        if (current == 0)
            BYTE(23) = 255;
        current = BYTE(23);
        if (current != 255)
            goto window_ready;
        current = 0x080C9748;
        BIND(current);
        work1 = 0x080C977C;
        BIND(work1);
        work3 = H(4);
        work3 <<= 19;
        work3 >>= 16;
        pointer0 = func_080771BC(current, work1, 0, work3, ({
                                     work5 = H(6);
                                     work4 = H(10);
                                     work6 = 1;
                                     BIND(work6);
                                     work2 = work6;
                                     BIND(work2);
                                     work2 &= work4;
                                     work2++;
                                     work5 += work2;
                                     work5 <<= 3;
                                     work2 = BYTE(22);
                                     work4 = BYTE(20);
                                     work2 -= work4;
                                     work2 <<= 4;
                                     work5 += work2;
                                     work5 = (s16)work5;
                                     work5;
                                 }),
                                 ({
                                     pointer4 = (u8 *)0x0201F5CC;
                                     BIND(pointer4);
                                     work2 = *(u16 *)pointer4;
                                     work2 += 14;
                                     work2 = (u16)work2;
                                     work2;
                                 }),
                                 ({
                                     pointer5 = (u8 *)0x0201F5CE;
                                     BIND(pointer5);
                                     work2 = *(u16 *)pointer5;
                                     work2;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CB;
                                     BIND(pointer2);
                                     work5 = *pointer2;
                                     work5 <<= 6;
                                     pointer4 = (u8 *)0x0201F5CA;
                                     BIND(pointer4);
                                     pointer9 = pointer4;
                                     work2 = *pointer4;
                                     work2 <<= 13;
                                     work4 = 0x1020;
                                     BIND(work4);
                                     work2 |= work4;
                                     work5 |= work2;
                                     work5;
                                 }),
                                 ({
                                     work5 = 0;
                                     BIND(work5);
                                     work8 = work5;
                                     work5;
                                 }));
        pointer1 = (u8 *)0x0200C4E8;
        BIND(pointer1);
        STORE32(pointer1, pointer0);
        current = 0x080C93C8;
        BIND(current);
        work1 = 0x080C93F0;
        BIND(work1);
        work3 = H(4);
        work2 = H(8);
        work3 += work2;
        work3--;
        work3 <<= 19;
        work3 >>= 16;
        pointer0 = func_080771BC(current, work1, 0, work3, ({
                                     work2 = H(6);
                                     work4 = H(10);
                                     work6 &= work4;
                                     work6++;
                                     work2 += work6;
                                     work2 <<= 19;
                                     work2 >>= 16;
                                     work2;
                                 }),
                                 ({
                                     pointer6 = (u8 *)0x0201F5CC;
                                     BIND(pointer6);
                                     work2 = *(u16 *)pointer6;
                                     work2;
                                 }),
                                 ({
                                     pointer4 = (u8 *)0x0201F5CE;
                                     BIND(pointer4);
                                     work2 = *(u16 *)pointer4;
                                     work2;
                                 }),
                                 ({
                                     pointer5 = (u8 *)0x0201F5CB;
                                     BIND(pointer5);
                                     work4 = *pointer5;
                                     work4 <<= 6;
                                     pointer6 = pointer9;
                                     BIND(pointer6);
                                     work2 = *pointer6;
                                     work2 <<= 13;
                                     work6 = 0x21030;
                                     BIND(work6);
                                     work2 |= work6;
                                     work4 |= work2;
                                     work4;
                                 }),
                                 ({
                                     work2 = work8;
                                     BIND(work2);
                                     work2;
                                 }));
        pointer5 = (u8 *)0x0200C4EC;
        BIND(pointer5);
        STORE32(pointer5, pointer0);
        current = 0x080C9470;
        BIND(current);
        work1 = 0x080C9498;
        BIND(work1);
        work3 = H(4);
        work2 = H(8);
        work3 += work2;
        work3--;
        work3 <<= 19;
        work3 >>= 16;
        BIND(work3);
        work12 = work3;
        pointer0 = func_080771BC(current, work1, 0, work12, SPRITE_Y(2), SPRITE_TILE(2),
                                 SPRITE_PALETTE, SPRITE_FLAGS, SPRITE_ZERO);
        *(u32 *)(pointer5 + 4) = (u32)pointer0;
        current = 0x080C9518;
        BIND(current);
        work1 = 0x080C9540;
        BIND(work1);
        work3 = H(4);
        work3++;
        work3 <<= 19;
        work3 >>= 16;
        BIND(work3);
        work12 = work3;
        pointer0 = func_080771BC(current, work1, 0, work12, SPRITE_Y(1), SPRITE_TILE(4),
                                 SPRITE_PALETTE, SPRITE_FLAGS, SPRITE_ZERO);
        *(u32 *)(pointer5 + 8) = (u32)pointer0;
        current = 0x080C95C0;
        BIND(current);
        work1 = 0x080C95E8;
        BIND(work1);
        work3 = H(4);
        work2 = H(8);
        work3 += work2;
        work3 -= 2;
        work3 <<= 19;
        work3 >>= 16;
        BIND(work3);
        work12 = work3;
        pointer0 = func_080771BC(current, work1, 0, work12, SPRITE_Y(1), SPRITE_TILE(6),
                                 SPRITE_PALETTE, SPRITE_FLAGS, SPRITE_ZERO);
        *(u32 *)(pointer5 + 12) = (u32)pointer0;
        pointer1 = (u8 *)0x0200C4A0;
        BIND(pointer1);
        current = BYTE(22);
        STORE8(pointer1, current);
        pointer1 = (u8 *)0x0200C4A1;
        BIND(pointer1);
        current = BYTE(20);
        STORE8(pointer1, current);
    window_ready:
        pointer0 = (u8 *)0x0200C624;
        BIND(pointer0);
        work1 = BYTE(19);
        pointer1 = (u8 *)(work1 + (u32)pointer0);
        work1 = *pointer1;
        current = *(volatile u8 *)(record + 22);
        BIND(current);
        if ((u32)current < (u32)work1)
            goto selection_in_range;
        current = work1 - 1;
        work3 = 0;
        BYTE(22) = current;
        work1 = BYTE(20);
        current = (u8)current;
        if ((u32)work1 <= (u32)current)
            goto selection_changed;
        work2 = work1;
        BIND(work2);
        HALF0;
        if (work2 >= current) {
            current = work2 - current;
            BYTE(20) = current;
            goto selection_changed;
        }
        BYTE(20) = work3;
        asm volatile("" : : "r"(work3));
        goto selection_changed;
    selection_in_range:
        work3 = BYTE(22);
        work4 = BYTE(20);
        work2 = work3 - work4;
        if (work2 < 0)
            goto selection_rebase;
        HALF0;
        if (work2 < current)
            goto selection_compare;
    selection_rebase:
        BYTE(20) = work3;
        goto selection_changed;
    selection_compare:
        work5 = BYTE(21);
        BIND(work5);
        if (work4 == work5)
            goto selection_unchanged;
    selection_changed:
        MARK_CHANGED;
        current = 255;
        BYTE(23) = current;
        goto selection_begin;
    selection_unchanged:
        func_0807A1A4();
    selection_begin:
        work6 = 0;
        local.flag = work6;
        pointer0 = (u8 *)0x0200C4A2;
        STORE8(pointer0, work6);
    selection_loop:
        current = W(0);
        work1 = 2;
        current &= work1;
        if (current == 0)
            goto window_controls;
        current = *(volatile u8 *)(record + 22);
        BIND(current);
        work2 = BYTE(23);
        BIND(work2);
        if (current == work2)
            goto window_drawn;
        pointer0 = (u8 *)0x0200C4E8;
        pointer3 = *(u8 **)pointer0;
        work2 = H(6);
        work1 = H(10);
        work4 = 1;
        BIND(work4);
        work8 = work4;
        current = work8;
        BIND(current);
        current &= work1;
        current++;
        work2 += current;
        work2 <<= 11;
        current = BYTE(22);
        work1 = BYTE(20);
        current -= work1;
        current <<= 12;
        work2 += current;
        *(u32 *)(pointer3 + 8) = work2;
        work4 = BYTE(20);
        work6 = BYTE(21);
        work5 = work4 - work6;
        BIND(work5);
        count9 = work5;
        work1 = H(10);
        work3 = work1 - 2;
        current = (u32)work3 >> 31;
        current = work3 + current;
        current >>= 1;
        if (count9 >= current)
            goto redraw_all;
        work2 = work6 - work4;
        if (work2 < current)
            goto scroll_partial;
    redraw_all:
        current = BYTE(19);
        func_0807BD4C(current);
        work1 = H(10);
        current = work8;
        BIND(current);
        current &= work1;
        H(14) = current;
        work6 = 0;
        BIND(work6);
        work8 = work6;
        HALF0;
        if ((u32)work8 >= (u32)current)
            goto window_drawn;
        pointer1 = (u8 *)0x0200C624;
        BIND(pointer1);
        current = BYTE(19);
        pointer1 = (u8 *)(current + (u32)pointer1);
        work5 = current;
        work4 = BYTE(20);
        work1 = *pointer1;
        if ((u32)work4 >= (u32)work1)
            goto window_drawn;
    redraw_line:
        current = 0x1E5A;
        BIND(current);
        work1 = work5;
        BIND(work1);
        work1 *= current;
        current = work8;
        BIND(current);
        work2 = work4 + current;
        current = work2 << 3;
        current += work2;
        current <<= 2;
        current += work2;
        pointer2 = (u8 *)0x0200C62E;
        BIND(pointer2);
        current += (u32)pointer2;
        work1 += current;
        func_0807B048((u32)record, work1);
        current = 0;
        H(12) = current;
        current = H(14);
        current += 2;
        H(14) = current;
        work1 = 1;
        BIND(work1);
        work8 += work1;
        HALF0;
        if ((u32)work8 >= (u32)current)
            goto window_drawn;
        work2 = BYTE(20);
        work4 = work8;
        BIND(work4);
        work3 = work2 + work4;
        pointer1 = (u8 *)0x0200C624;
        BIND(pointer1);
        current = BYTE(19);
        pointer1 = (u8 *)(current + (u32)pointer1);
        work5 = current;
        work4 = work2;
        BIND(work4);
        work1 = *pointer1;
        if ((u32)work3 < (u32)work1)
            goto redraw_line;
        goto window_drawn;
    scroll_partial:
        work5 = work4;
        BIND(work5);
        work4 = work6;
        BIND(work4);
        if ((u32)work5 <= (u32)work4)
            goto scroll_back;
        work5 = work8;
        BIND(work5);
        work1 &= work5;
        work6 = work1 + 1;
        current = 0;
        BIND(current);
        work8 = current;
        work1 = count9;
        BIND(work1);
        current = work1 << 1;
        if ((u32)work8 >= (u32)current)
            goto forward_copy_init;
    forward_free_row:
        work2 = 1;
        BIND(work2);
        count9 = work2;
        work1 = H(8);
        current = work1 - 1;
        work4 = work8;
        BIND(work4);
        work4++;
        work3 = work6 + 1;
        local.next = work3;
        if (count9 >= current)
            goto forward_free_next;
    forward_free_tile:
        work1 *= work6;
        work1 += count9;
        work1 <<= 1;
        pointer0 = record;
        BIND(pointer0);
        pointer0 += 0x20;
        pointer0 += work1;
        work1 = *(u16 *)pointer0;
        work5 = 0x3FF;
        BIND(work5);
        current = work5;
        BIND(current);
        work1 &= current;
        pointer0 = (u8 *)0x0201F5C4;
        current = *(u32 *)pointer0;
        if ((u32)work1 < (u32)current)
            goto forward_free;
        current += 0x40;
        if ((u32)work1 >= (u32)current) {
        forward_free:
            TILE_FREE;
        }
        current = 1;
        BIND(current);
        count9 += current;
        work1 = H(8);
        current = work1 - 1;
        if (count9 < current)
            goto forward_free_tile;
    forward_free_next:
        work6 = local.next;
        work8 = work4;
        current = BYTE(20);
        work1 = BYTE(21);
        current -= work1;
        current <<= 1;
        if ((u32)work8 < (u32)current)
            goto forward_free_row;
    forward_copy_init:
        work1 = H(10);
        current = 1;
        current &= work1;
        H(14) = current;
        work6 = 0;
        work3 = *(volatile u16 *)(record + 10);
        current = work3 - 2;
        work1 = (u32)current >> 31;
        current += work1;
        current >>= 1;
        work1 = BYTE(20);
        work2 = BYTE(21);
        work1 -= work2;
        current -= work1;
        if (work6 >= current)
            goto forward_fill_test;
    forward_copy_row:
        current = 0;
        H(12) = current;
        count9 = current;
        work5 = H(8);
        current = work5 - 2;
        work6++;
        local.next = work6;
        if (count9 >= current)
            goto forward_copy_next;
        pointer6 = record;
        BIND(pointer6);
        pointer6 += 0x20;
    forward_copy_tile:
        COPY_FORWARD(1, , LOAD3_1, LOAD4_2);
        COPY_FORWARD(2, work5 = H(8), LOAD3_4, LOAD4_5);
        current = H(12);
        current++;
        H(12) = current;
        current = 1;
        BIND(current);
        count9 += current;
        work5 = H(8);
        current = work5 - 2;
        if (count9 < current)
            goto forward_copy_tile;
    forward_copy_next:
        current = H(14);
        current += 2;
        H(14) = current;
        work6 = local.next;
        work3 = H(10);
        work2 = work3 - 2;
        current = (u32)work2 >> 31;
        work2 += current;
        work2 >>= 1;
        work1 = BYTE(20);
        current = BYTE(21);
        work1 -= current;
        work2 -= work1;
        if (work6 < work2)
            goto forward_copy_row;
    forward_fill_test:
        current = work3 - 2;
        work1 = (u32)current >> 31;
        current += work1;
        current >>= 1;
        if (work6 >= current)
            goto window_drawn;
    forward_fill_row:
        current = 0;
        H(12) = current;
        count9 = current;
        work2 = H(8);
        current = work2 - 2;
        work1 = work6 + 1;
        local.next = work1;
        work5 = work6 >> 31;
        if (count9 >= current)
            goto forward_fill_text;
        pointer4 = record;
        BIND(pointer4);
        pointer4 += 0x20;
        pointer3 = (u8 *)0x0201F5C4;
        BIND(pointer3);
        pointer12 = pointer3;
        pointer0 = (u8 *)0x0201F5C8;
        BIND(pointer0);
        text8 = pointer0;
    forward_fill_tile:
        asm("" : "=r"(current));
        work1 = SH(12);
        asm("" : : "r"(current));
        current = SH(14);
        current++;
        current *= work2;
        current++;
        work1 += current;
        work1 <<= 1;
        pointer1 = (u8 *)((u32)pointer4 + work1);
        pointer0 = pointer12;
        BIND(pointer0);
        work3 = *(u32 *)pointer0;
        work3++;
        pointer2 = text8;
        BIND(pointer2);
        current = *(u16 *)pointer2;
        work3 |= current;
        STORE16(pointer1, work3);
        work2 = SH(12);
        work1 = SH(14);
        work1 += 2;
        current = H(8);
        current *= work1;
        current++;
        work2 += current;
        work2 <<= 1;
        pointer2 = (u8 *)((u32)pointer4 + work2);
        STORE16(pointer2, work3);
        current = H(12);
        current++;
        H(12) = current;
        work1 = 1;
        BIND(work1);
        count9 += work1;
        work2 = H(8);
        current = work2 - 2;
        if (count9 < current)
            goto forward_fill_tile;
    forward_fill_text:
        work3 = BYTE(20);
        work1 = work6 - work5;
        work1 >>= 1;
        work1 = work3 + work1;
        current = BYTE(19);
        pointer4 = (u8 *)0x0200C624;
        BIND(pointer4);
        pointer2 = (u8 *)(current + (u32)pointer4);
        work5 = current;
        work4 = work3;
        BIND(work4);
        work2 = *pointer2;
        if (work1 < work2) {
            current = 0;
            H(12) = current;
            DRAW_TEXT;
            current = H(14);
            current += 2;
            H(14) = current;
        }
        work6 = local.next;
        HALF0;
        if (work6 < current)
            goto forward_fill_row;
        goto window_drawn;
    scroll_back:
        if ((u32)work5 >= (u32)work4)
            goto window_drawn;
        work6 = work3;
        work5 = 0;
        BIND(work5);
        work8 = work5;
        current = work2 << 1;
        if ((u32)work8 >= (u32)current)
            goto back_copy_init;
    back_free_row:
        current = 1;
        BIND(current);
        count9 = current;
        work1 = H(8);
        current = work1 - 1;
        work4 = work8;
        BIND(work4);
        work4++;
        work2 = work6 - 1;
        BIND(work2);
        work8 = work2;
        if (count9 >= current)
            goto back_free_next;
    back_free_tile:
        work1 *= work6;
        work1 += count9;
        work1 <<= 1;
        pointer0 = record;
        BIND(pointer0);
        pointer0 += 0x20;
        pointer0 += work1;
        work1 = *(u16 *)pointer0;
        work3 = 0x3FF;
        BIND(work3);
        current = work3;
        BIND(current);
        work1 &= current;
        pointer0 = (u8 *)0x0201F5C4;
        current = *(u32 *)pointer0;
        if ((u32)work1 < (u32)current)
            goto back_free;
        current += 0x40;
        if ((u32)work1 >= (u32)current) {
        back_free:
            TILE_FREE;
        }
        work5 = 1;
        BIND(work5);
        count9 += work5;
        work1 = H(8);
        current = work1 - 1;
        if (count9 < current)
            goto back_free_tile;
    back_free_next:
        work6 = work8;
        work8 = work4;
        current = BYTE(21);
        work1 = BYTE(20);
        current -= work1;
        current <<= 1;
        if ((u32)work8 < (u32)current)
            goto back_free_row;
    back_copy_init:
        current = H(10);
        current -= 4;
        H(14) = current;
        HALF0;
        work6 = current - 1;
        current = BYTE(21);
        work1 = BYTE(20);
        current -= work1;
        if (work6 < current)
            goto back_fill_test;
    back_copy_row:
        current = 0;
        H(12) = current;
        count9 = current;
        work5 = H(8);
        current = work5 - 2;
        work6--;
        BIND(work6);
        work8 = work6;
        if (count9 >= current)
            goto back_copy_next;
        pointer6 = record;
        BIND(pointer6);
        pointer6 += 0x20;
    back_copy_tile:
        COPY_BACK(1, , LOAD3_0, LOAD4_1);
        COPY_BACK(2, work5 = H(8), LOAD3_2, LOAD4_5);
        current = H(12);
        current++;
        H(12) = current;
        current = 1;
        BIND(current);
        count9 += current;
        work5 = H(8);
        current = work5 - 2;
        if (count9 < current)
            goto back_copy_tile;
    back_copy_next:
        current = H(14);
        current -= 2;
        H(14) = current;
        work6 = work8;
        work1 = BYTE(21);
        current = BYTE(20);
        work1 -= current;
        if (work6 >= work1)
            goto back_copy_row;
        goto back_fill_test;
    back_fill_row:
        current = 0;
        H(12) = current;
        count9 = current;
        work2 = H(8);
        current = work2 - 2;
        work5 = work6 >> 31;
        work1 = work6 - 1;
        BIND(work1);
        work8 = work1;
        if (count9 >= current)
            goto back_fill_text;
        pointer4 = record;
        BIND(pointer4);
        pointer4 += 0x20;
        pointer3 = (u8 *)0x0201F5C8;
        BIND(pointer3);
        pointer12 = pointer3;
    back_fill_tile:
        asm("" : "=r"(work3));
        work1 = SH(12);
        asm("" : : "r"(work3));
        current = SH(14);
        current++;
        current *= work2;
        current++;
        work1 += current;
        work1 <<= 1;
        pointer1 = (u8 *)((u32)pointer4 + work1);
        pointer0 = (u8 *)0x0201F5C4;
        work3 = *(u32 *)pointer0;
        work3++;
        pointer2 = pointer12;
        BIND(pointer2);
        current = *(u16 *)pointer2;
        work3 |= current;
        STORE16(pointer1, work3);
        work2 = SH(12);
        work1 = SH(14);
        work1 += 2;
        current = H(8);
        current *= work1;
        current++;
        work2 += current;
        work2 <<= 1;
        pointer2 = (u8 *)((u32)pointer4 + work2);
        STORE16(pointer2, work3);
        current = H(12);
        current++;
        H(12) = current;
        work1 = 1;
        BIND(work1);
        count9 += work1;
        work2 = H(8);
        current = work2 - 2;
        if (count9 < current)
            goto back_fill_tile;
    back_fill_text:
        work3 = BYTE(20);
        work1 = work6 - work5;
        work1 >>= 1;
        work1 = work3 + work1;
        current = BYTE(19);
        pointer4 = (u8 *)0x0200C624;
        BIND(pointer4);
        pointer2 = (u8 *)(current + (u32)pointer4);
        work5 = current;
        work4 = work3;
        BIND(work4);
        work2 = *pointer2;
        if (work1 < work2) {
            current = 0;
            H(12) = current;
            DRAW_TEXT;
            current = H(14);
            current -= 2;
            H(14) = current;
        }
        work6 = work8;
    back_fill_test:
        if (work6 >= 0)
            goto back_fill_row;
    window_drawn:
        pointer1 = (u8 *)0x0200C4A0;
        BIND(pointer1);
        current = BYTE(22);
        STORE8(pointer1, current);
        pointer1 = (u8 *)0x0200C4A1;
        BIND(pointer1);
        current = BYTE(20);
        STORE8(pointer1, current);
        current = BYTE(22);
        BYTE(23) = current;
        current = BYTE(20);
        BYTE(21) = current;
        work5 = local.flag;
        if (work5 != 0)
            goto done;
        func_0807A1A4();
    window_controls:
        current = BYTE(20);
        if (current != 0) {
            pointer6 = (u8 *)0x0200C4EC;
            BIND(pointer6);
            pointer0 = *(u8 **)pointer6;
            work1 = *(u32 *)pointer0;
            work2 = 0xFFFDFFFF;
            BIND(work2);
            work1 &= work2;
            STORE32(pointer0, work1);
            pointer5 = pointer6;
        } else {
            pointer1 = (u8 *)0x0200C4EC;
            BIND(pointer1);
            pointer0 = *(u8 **)pointer1;
            work1 = *(u32 *)pointer0;
            work2 = 0x20000;
            BIND(work2);
            work1 |= work2;
            STORE32(pointer0, work1);
            pointer5 = (u8 *)0x0200C4EC;
            BIND(pointer5);
        }
        work4 = BYTE(20);
        pointer3 = (u8 *)0x0200C624;
        BIND(pointer3);
        current = BYTE(19);
        pointer0 = (u8 *)(current + (u32)pointer3);
        work2 = *pointer0;
        HALF0;
        work2 -= current;
        if (work4 < work2) {
            pointer0 = *(u8 **)(pointer5 + 4);
            work1 = *(u32 *)pointer0;
            work2 = 0xFFFDFFFF;
            BIND(work2);
            work1 &= work2;
        } else {
            pointer0 = *(u8 **)(pointer5 + 4);
            work1 = *(u32 *)pointer0;
            work2 = 0x20000;
            BIND(work2);
            work1 |= work2;
        }
        STORE32(pointer0, work1);
        current = BYTE(20);
        if (current != 0) {
            pointer0 = *(u8 **)(pointer5 + 8);
            work1 = *(u32 *)pointer0;
            work2 = 0xFFFDFFFF;
            BIND(work2);
            work1 &= work2;
        } else {
            pointer0 = *(u8 **)(pointer5 + 8);
            work1 = *(u32 *)pointer0;
            work2 = 0x20000;
            BIND(work2);
            work1 |= work2;
        }
        STORE32(pointer0, work1);
        work3 = BYTE(20);
        current = BYTE(19);
        pointer2 = (u8 *)0x0200C624;
        BIND(pointer2);
        pointer0 = (u8 *)(current + (u32)pointer2);
        work2 = *pointer0;
        HALF0;
        work2 -= current;
        if (work3 < work2) {
            pointer0 = *(u8 **)(pointer5 + 12);
            work1 = *(u32 *)pointer0;
            work2 = 0xFFFDFFFF;
            BIND(work2);
            work1 &= work2;
        } else {
            pointer0 = *(u8 **)(pointer5 + 12);
            work1 = *(u32 *)pointer0;
            work2 = 0x20000;
            BIND(work2);
            work1 |= work2;
        }
        STORE32(pointer0, work1);
        func_080C8FCC(1);
        pointer3 = script;
        BIND(pointer3);
        work1 = pointer3[2];
        current = 2;
        current &= work1;
        BIND(current);
        current <<= 24;
        current = (u32)current >> 24;
        current = -current;
        current = (u32)current >> 31;
        local.flag = current;
        pointer2 = (u8 *)0x0300000C;
        BIND(pointer2);
        current = *(u16 *)pointer2;
        work4 = H(28);
        BIND(work4);
        if (current != work4)
            goto input_new;
        pointer0 = (u8 *)0x03000081;
        BIND(pointer0);
        work1 = BYTE(27);
        current = *pointer0;
        work1 -= current;
        current = 0;
        BYTE(27) = work1;
        work1 <<= 24;
        if (work1 > 0)
            goto input_wait;
        current = *(u16 *)pointer2;
        pointer5 = (u8 *)0x0200C4A4;
        BIND(pointer5);
        STORE16(pointer5, current);
        current = 8;
        BYTE(27) = current;
        pointer6 = pointer5;
        goto input_ready;
    input_wait:
        pointer6 = (u8 *)0x0200C4A4;
        STORE16(pointer6, current);
        goto input_ready;
    input_new:
        H(28) = current;
        pointer0 = (u8 *)0x0300000E;
        current = *(u16 *)pointer0;
        pointer1 = (u8 *)0x0200C4A4;
        BIND(pointer1);
        STORE16(pointer1, current);
        current = 16;
        BYTE(27) = current;
        pointer6 = pointer1;
    input_ready:
        work1 = *(volatile u16 *)pointer6;
        work2 = 0x40;
        current = work2;
        BIND(current);
        current &= work1;
        BIND(current);
        current <<= 16;
        BIND(current);
        work3 = (u32)current >> 16;
        if (work3 == 0)
            goto input_down;
        current = BYTE(22);
        if (current == 0)
            goto input_up_wrap;
        current--;
        BYTE(22) = current;
        work1 = BYTE(20);
        current = (u8)current;
        if ((u32)current < (u32)work1) {
            current = work1 - 1;
            BYTE(20) = current;
            pointer2 = (u8 *)0x0200C4EC;
            BIND(pointer2);
            current = *(u32 *)pointer2;
            func_08077204(current, 1);
        }
        PLAY_MOVE;
        asm volatile("" : : "r"(record));
        goto input_up_done;
    input_up_wrap:
        pointer3 = script;
        BIND(pointer3);
        work1 = pointer3[2];
        current = 0x80;
        current &= work1;
        if (current == 0)
            goto input_up_done;
        pointer1 = (u8 *)0x0200C624;
        BIND(pointer1);
        current = BYTE(19);
        pointer0 = (u8 *)(current + (u32)pointer1);
        current = *pointer0;
        current--;
        BYTE(22) = current;
        PLAY_MOVE;
    input_up_done:
        pointer4 = (u8 *)0x0200C4A4;
        work1 = *(u16 *)pointer4;
        current = 0x40;
        current &= work1;
        STORE16(pointer4, current);
        goto input_done;
    input_down:
        work4 = 0x80;
        current = work4;
        BIND(current);
        current &= work1;
        if (current == 0)
            goto input_left;
        work2 = BYTE(22);
        pointer0 = (u8 *)0x0200C624;
        BIND(pointer0);
        work1 = BYTE(19);
        pointer1 = (u8 *)(work1 + (u32)pointer0);
        current = *pointer1;
        current--;
        if (work2 >= current)
            goto input_down_wrap;
        current = work2 + 1;
        BYTE(22) = current;
        work2 = BYTE(22);
        work3 = BYTE(20);
        HALF0;
        current = work3 + current;
        if (work2 >= current) {
            current = work3 + 1;
            BYTE(20) = current;
            pointer5 = (u8 *)0x0200C4EC;
            BIND(pointer5);
            current = *(u32 *)(pointer5 + 4);
            func_08077204(current, 1);
        }
        PLAY_MOVE;
        asm volatile("" : : "r"(record));
        goto input_down_done;
    input_down_wrap:
        pointer6 = script;
        BIND(pointer6);
        work1 = pointer6[2];
        current = work4;
        BIND(current);
        current &= work1;
        if (current == 0)
            goto input_down_done;
        BYTE(22) = work3;
        PLAY_MOVE;
    input_down_done:
        pointer0 = (u8 *)0x0200C4A4;
        work1 = *(u16 *)pointer0;
        current = 0x80;
        goto input_mask;
    input_left:
        current = 0x20;
        current &= work1;
        if (current == 0)
            goto input_right;
        current = BYTE(22);
        BIND(current);
        work3 = current;
        BIND(work3);
        if (work3 == 0)
            goto input_left_done;
        work2 = BYTE(20);
        HALF0;
        if (work2 >= current)
            work1 = work2 - current;
        else
            work1 = 0;
        BYTE(20) = work1;
        work2 = BYTE(21);
        current = work1 << 24;
        current = (u32)current >> 24;
        if (current == work2)
            goto input_left_done;
        current = work2 - work1;
        current = work3 - current;
        BYTE(22) = current;
        pointer2 = (u8 *)0x0200C4EC;
        BIND(pointer2);
        current = *(u32 *)(pointer2 + 8);
        func_08077204(current, 1);
        PLAY_MOVE;
    input_left_done:
        pointer3 = (u8 *)0x0200C4A4;
        work1 = *(u16 *)pointer3;
        current = 0x20;
        current &= work1;
        STORE16(pointer3, current);
        goto input_done;
    input_right:
        current = 0x10;
        current &= work1;
        if (current == 0)
            goto input_accept;
        work6 = BYTE(22);
        pointer0 = (u8 *)0x0200C624;
        BIND(pointer0);
        work1 = BYTE(19);
        pointer1 = (u8 *)(work1 + (u32)pointer0);
        BIND(pointer1);
        text8 = pointer1;
        work4 = *pointer1;
        current = work4 - 1;
        if (work6 >= current)
            goto input_right_done;
        work3 = *(volatile u8 *)(record + 20);
        BIND(work3);
        work2 = BYTE(20);
        current = H(10);
        current -= 2;
        work1 = (u32)current >> 31;
        current += work1;
        work5 = current >> 1;
        current = work4 - work5;
        if (work2 < current)
            work3 += work5;
        BYTE(20) = work3;
        current = work3 << 24;
        work4 = (u32)current >> 24;
        work3 = BYTE(21);
        if (work4 == work3)
            goto input_right_done;
        work2 = work6;
        BIND(work2);
        pointer0 = text8;
        BIND(pointer0);
        work1 = *pointer0;
        current = work1 - work5;
        if (work2 < current) {
            current = work2 + work5;
            goto input_right_store;
        }
        if (work3 != work4)
            goto input_right_last;
        current = work6;
        goto input_right_store;
    input_right_last:
        current = work1 - 1;
    input_right_store:
        BYTE(22) = current;
        pointer1 = (u8 *)0x0200C4EC;
        BIND(pointer1);
        current = *(u32 *)(pointer1 + 12);
        func_08077204(current, 1);
        PLAY_MOVE;
    input_right_done:
        pointer2 = (u8 *)0x0200C4A4;
        work1 = *(u16 *)pointer2;
        current = 0x10;
        current &= work1;
        STORE16(pointer2, current);
        goto input_done;
    input_accept:
        pointer3 = script;
        BIND(pointer3);
        work1 = pointer3[2];
        current = work2;
        BIND(current);
        current &= work1;
        work5 = work1;
        if (current != 0)
            goto input_cancel;
        pointer0 = (u8 *)0x0300000E;
        work1 = *(u16 *)pointer0;
        work2 = 1;
        work4 = 1;
        current = work4;
        BIND(current);
        current &= work1;
        if (current == 0)
            goto input_cancel;
        pointer0 = (u8 *)0x0200C4A2;
        STORE8(pointer0, work2);
        work5 = 3;
        BIND(work5);
        script += work5;
        func_08075F20(0xCA);
        work1 = *(u16 *)pointer6;
        current = work4;
        BIND(current);
        current &= work1;
        STORE16(pointer6, current);
        goto input_done;
    input_cancel:
        current = 1;
        current &= work5;
        if (current == 0)
            goto input_close;
        pointer0 = (u8 *)0x0300000E;
        work1 = *(u16 *)pointer0;
        work2 = 2;
        work4 = 2;
        current = work4;
        BIND(current);
        current &= work1;
        if (current == 0)
            goto input_close;
        pointer0 = (u8 *)0x0200C4A2;
        STORE8(pointer0, work2);
        work6 = 3;
        BIND(work6);
        script += work6;
        func_08075F20(0xCB);
        pointer0 = (u8 *)0x0200C4A4;
        work1 = *(u16 *)pointer0;
        current = work4;
        BIND(current);
    input_mask:
        current &= work1;
        pointer1 = (u8 *)0x0200C4A4;
        BIND(pointer1);
        STORE16(pointer1, current);
        goto input_done;
    input_close:
        work2 = work5;
        BIND(work2);
        work4 = 4;
        current = work4;
        BIND(current);
        current &= work2;
        if (current == 0)
            goto input_close_r;
        current = *(volatile u16 *)pointer6;
        work3 = 0x200;
        BIND(work3);
        work1 = work3;
        BIND(work1);
        current &= work1;
        if (current != 0)
            goto close_window;
    input_close_r:
        work3 = 8;
        current = work3;
        BIND(current);
        current &= work2;
        if (current == 0)
            goto input_close_start;
        current = *(volatile u16 *)pointer6;
        work6 = 0x100;
        BIND(work6);
        work1 = work6;
        BIND(work1);
        current &= work1;
        if (current != 0)
            goto close_window;
    input_close_start:
        current = 0x10;
        current &= work2;
        if (current == 0)
            goto input_close_select;
        pointer0 = (u8 *)0x0300000E;
        work1 = *(u16 *)pointer0;
        current = work3;
        BIND(current);
        current &= work1;
        if (current != 0)
            goto close_window;
    input_close_select:
        current = 0x20;
        current &= work5;
        if (current == 0)
            goto input_idle;
        pointer0 = (u8 *)0x0300000E;
        work1 = *(u16 *)pointer0;
        current = work4;
        BIND(current);
        current &= work1;
        if (current == 0)
            goto input_idle;
    close_window:
        DELETE_WINDOWS;
        current = 255;
        BYTE(23) = current;
        func_08075F20(0xCC);
        pointer5 = (u8 *)0x0200C4A4;
        BIND(pointer5);
        current = *(u16 *)pointer5;
        work6 = 0x30C;
        BIND(work6);
        work1 = work6;
        BIND(work1);
        current &= work1;
        STORE16(pointer5, current);
        goto done;
    input_idle:
        current = 0;
        local.flag = current;
    input_done:
        pointer0 = (u8 *)0x0200C4A2;
        current = *pointer0;
        if (current == 0)
            goto selection_loop;
        pointer0 = (u8 *)0x0200C4E8;
        current = *(u32 *)pointer0;
        func_080771F4(current);
        pointer4 = (u8 *)0x0200C4EC;
        current = *(u32 *)pointer4;
        func_080771F4(current);
        current = *(u32 *)(pointer4 + 4);
        func_080771F4(current);
        current = *(u32 *)(pointer4 + 8);
        func_080771F4(current);
        current = *(u32 *)(pointer4 + 12);
        func_080771F4(current);
        current = 255;
        BYTE(23) = current;
        goto continue_script;
    case 9:
        pointer1 = script;
        BIND(pointer1);
        current = pointer1[1];
        func_0807A0C8(current);
        pointer0 = (u8 *)0x0200C4FC;
        record = *(u8 **)pointer0;
        pointer2 = script;
        BIND(pointer2);
        work1 = pointer2[2];
        current = 1;
        current &= work1;
        work6 = 0;
        BYTE(22) = current;
        current = 0x080C9748;
        BIND(current);
        work1 = 0x080C977C;
        BIND(work1);
        work3 = H(4);
        work3 -= 2;
        work2 = H(8);
        work2 = (u32)work2 >> 1;
        work3 += work2;
        work3 <<= 19;
        work3 >>= 16;
        pointer0 = func_080771BC(current, work1, 0, work3, ({
                                     work4 = H(6);
                                     work2 = H(10);
                                     work4 += work2;
                                     work4 -= 5;
                                     work4 <<= 3;
                                     work2 = BYTE(22);
                                     work2 <<= 4;
                                     work4 += work2;
                                     work4 = (s16)work4;
                                     work4;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CC;
                                     BIND(pointer2);
                                     work2 = *(u16 *)pointer2;
                                     work2 += 14;
                                     work2 = (u16)work2;
                                     work2;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CE;
                                     BIND(pointer2);
                                     work2 = *(u16 *)pointer2;
                                     work2;
                                 }),
                                 ({
                                     pointer2 = (u8 *)0x0201F5CB;
                                     BIND(pointer2);
                                     work5 = *pointer2;
                                     work5 <<= 6;
                                     pointer2 = (u8 *)0x0201F5CA;
                                     BIND(pointer2);
                                     work2 = *pointer2;
                                     work2 <<= 13;
                                     work4 = 0x1020;
                                     BIND(work4);
                                     work2 |= work4;
                                     work5 |= work2;
                                     work5;
                                 }),
                                 work6);
        pointer1 = (u8 *)0x0200C4E8;
        BIND(pointer1);
        STORE32(pointer1, pointer0);
        func_0807A1A4();
        pointer0 = (u8 *)0x0200C4A2;
        STORE8(pointer0, work6);
        pointer4 = pointer0;
    yes_no_loop:
        pointer0 = (u8 *)0x0200C4E8;
        pointer2 = *(u8 **)pointer0;
        work1 = H(6);
        current = H(10);
        work1 += current;
        work1 -= 5;
        work1 <<= 11;
        current = BYTE(22);
        current <<= 12;
        work1 += current;
        *(u32 *)(pointer2 + 8) = work1;
        func_080C8FCC(1);
        pointer0 = (u8 *)0x0300000E;
        work2 = *(u16 *)pointer0;
        current = 0x40;
        current &= work2;
        if (current == 0)
            goto yes_no_down;
        current = BYTE(22);
        if (current == 0)
            goto yes_no_done;
        current--;
        goto yes_no_store;
    yes_no_down:
        current = 0x80;
        current &= work2;
        if (current == 0)
            goto yes_no_accept;
        current = BYTE(22);
        if (current != 0)
            goto yes_no_done;
        current++;
    yes_no_store:
        BYTE(22) = current;
        func_08075F20(0xCC);
        goto yes_no_done;
    yes_no_accept:
        work1 = 1;
        current = 1;
        current &= work2;
        if (current == 0)
            goto yes_no_cancel;
        STORE8(pointer4, work1);
        pointer1 = (u8 *)0x0200C4A0;
        BIND(pointer1);
        current = BYTE(22);
        STORE8(pointer1, current);
        work3 = 3;
        BIND(work3);
        script += work3;
        func_08075F20(0xCA);
        goto yes_no_done;
    yes_no_cancel:
        pointer5 = script;
        BIND(pointer5);
        work1 = pointer5[2];
        work3 = 2;
        current = work3;
        BIND(current);
        current &= work1;
        if (current != 0)
            goto yes_no_done;
        work1 = 2;
        current = work3;
        BIND(current);
        current &= work2;
        if (current == 0)
            goto yes_no_done;
        STORE8(pointer4, work1);
        work6 = 3;
        BIND(work6);
        script += work6;
        func_08075F20(0xCB);
    yes_no_done:
        current = *pointer4;
        if (current == 0)
            goto yes_no_loop;
        pointer0 = (u8 *)0x0200C4E8;
        current = *(u32 *)pointer0;
        func_080771F4(current);
        goto continue_script;
    case 12:
        pointer0 = script;
        BIND(pointer0);
        work1 = pointer0[1];
        current = 0x4D0;
        BIND(current);
        work1 *= current;
        pointer0 = (u8 *)0x02009480;
        BIND(pointer0);
        record = (u8 *)(work1 + (u32)pointer0);
        pointer1 = script;
        BIND(pointer1);
        current = pointer1[2];
        work1 = 0;
        BYTE(24) = current;
        pointer2 = script;
        BIND(pointer2);
        current = pointer2[2];
        switch (current) {
        case 0:
            BYTE(25) = work1;
            current = 5;
            asm volatile("" : : "r"(current));
            goto store_style;
        case 2:
            BYTE(25) = work1;
            current = 5;
            goto store_style;
        case 1:
        case 3:
            current = 4;
            BYTE(25) = current;
            current = 6;
        store_style:
            BYTE(26) = current;
        }
        current = W(0);
        work1 = 10;
        current |= work1;
        W(0) = current;
        work3 = 3;
        BIND(work3);
        script += work3;
        goto continue_script;
    case 13:
        pointer6 = script;
        BIND(pointer6);
        pointer6++;
        pointer4 = (u8 *)0x0300000E;
        work5 = 3;
        do {
            func_080C8FCC(1);
            work1 = *(u16 *)pointer4;
            current = work5;
            current &= work1;
        } while (current == 0);
        func_08075F20(0xCD);
        func_080C8FCC(1);
        script = pointer6;
        goto continue_script;
    case 14:
        pointer4 = script;
        BIND(pointer4);
        work1 = pointer4[1];
        current = 0x4D0;
        BIND(current);
        work1 *= current;
        pointer0 = (u8 *)0x02009480;
        BIND(pointer0);
        record = (u8 *)(work1 + (u32)pointer0);
        work6 = -1;
        pointer4 += 4;
        local.saved = pointer4;
        pointer5 = (u8 *)0x0201F5C4;
        pointer0 = (u8 *)0x0201F5C8;
        BIND(pointer0);
        text8 = pointer0;
    border_row:
        work1 = -1;
        BIND(work1);
        count9 = work1;
        work2 = work6 + 1;
        local.next = work2;
    border_tile:
        pointer3 = script;
        work1 = pointer3[2];
        work1 += count9;
        work2 = pointer3[3];
        work2 += work6;
        current = H(8);
        current *= work2;
        work1 += current;
        work1 <<= 1;
        work1 += 0x20;
        pointer4 = record + work1;
        work3 = *(u16 *)pointer4;
        work1 = 0x3FF;
        asm("" : "=r"(current), "+r"(work1) : "0"(work1));
        work1 = current;
        work1 &= work3;
        work2 = *(u32 *)pointer5;
        current = work2 + 2;
        if ((u32)work1 < (u32)current)
            goto border_replace;
        current += 7;
        if ((u32)work1 <= (u32)current)
            goto border_highlight;
    border_replace:
        if ((u32)work1 < (u32)work2)
            goto border_free;
        current = work2;
        current += 0x40;
        if ((u32)work1 >= (u32)current) {
        border_free:
            TILE_FREE;
        }
        current = -1;
        if (count9 != current)
            goto border_middle;
        if (work6 != count9)
            goto border_left;
        current = *(u32 *)pointer5;
        current += 0x18;
        pointer2 = text8;
        half1 = *(u16 *)pointer2;
        half0 = (u16)current | half1;
        goto border_store_first;
    border_left:
        if (work6 > 5)
            goto border_left_bottom;
        current = *(u32 *)pointer5;
        current += 0x1E;
        pointer3 = text8;
        half1 = *(u16 *)pointer3;
        half0 = (u16)current | half1;
        goto border_store_first;
    border_left_bottom:
        current = *(u32 *)pointer5;
        current += 0x1A;
        pointer2 = text8;
        work1 = *(u16 *)pointer2;
        current |= work1;
        half0 = current;
        goto border_store_first;
    border_middle:
        work3 = count9;
        if (work3 > 5)
            goto border_right;
        if (work6 != current)
            goto border_bottom;
        current = *(u32 *)pointer5;
        current += 0x1C;
        pointer2 = text8;
        work1 = *(u16 *)pointer2;
        current |= work1;
        half0 = current;
        goto border_store_second;
    border_bottom:
        if (work6 != 6)
            goto border_next;
        current = *(u32 *)pointer5;
        current += 0x1D;
        pointer3 = text8;
        work1 = *(u16 *)pointer3;
        current |= work1;
        half0 = current;
        goto border_store_first;
    border_right:
        if (work6 != current)
            goto border_right_side;
        current = *(u32 *)pointer5;
        current += 0x19;
        pointer2 = text8;
        work1 = *(u16 *)pointer2;
        current |= work1;
        half0 = current;
        goto border_store;
    border_right_side:
        if (work6 > 5)
            goto border_right_bottom;
        current = *(u32 *)pointer5;
        current += 0x1F;
        pointer3 = text8;
        work1 = *(u16 *)pointer3;
        current |= work1;
        half0 = current;
        goto border_store_second;
    border_right_bottom:
        current = *(u32 *)pointer5;
        current += 0x1B;
        pointer2 = text8;
        half1 = *(u16 *)pointer2;
        half0 = (u16)current | half1;
        goto border_store;
    border_highlight:
        current = work3;
        current += 14;
        half0 = current;
        /* Separate joins preserve the border cases without lengthening the loop branch. */
    border_store_first:
        asm volatile("" : : "r"(half0), "r"(work3));
    border_store_second:
        asm volatile("" : : "r"(half0), "r"(work3));
    border_store:
        *(u16 *)pointer4 = half0;
    border_next:
        work3 = 1;
        count9 += work3;
        work4 = count9;
        if (work4 <= 6)
            goto border_tile;
        asm("" : : "r"(work3), "r"(work4));
        work6 = local.next;
        if (work6 <= 6)
            goto border_row;
        MARK_CHANGED;
        pointer5 = local.saved;
        script = pointer5;
    default:
    continue_script:
        work6 = 0;
        BIND(work6);
        if (work6 == 0)
            goto next_command;
    done:
        return;
    }
}
