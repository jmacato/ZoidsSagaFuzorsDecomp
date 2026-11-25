#include "types.h"

void func_08075F20(u32);
u32 func_080771BC(u8 *, u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(u32);
void func_0807BA24(s32, u32, u32, u32, u32, u32, u32);
void func_0807B77C(u8 *, u32, u32);
void func_0807C290(u8 *);
void func_08089CE0(u32, u32);
void func_0808A084(u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808A86C(u32);
void func_0808A890(u32);
void func_0808A8B4(u32);
void func_0808AC1C(u32, u32);
void func_0808AF0C(u32, u32, u32);
u32 func_0808B2F8(u32, u32, u32);
u32 func_0808B3BC(u32, u32, u32, u32);
void func_0808B590(u8 *, u32, u32, u32, u32);
void func_0808DC94(u8 *, u32, u32, u32);
s32 func_080BD2F4(s32, s32);
void func_080BD57C(u8 *);
void func_080BD98C(u8 *, volatile u8 **, u32, u32);
void func_080BDCD8(u8 *);
void func_080BDEB0(u32);
void func_080BF814(u32, u32);
s32 func_080BFADC(u8 *, u32);
s32 func_080BFB24(u8 *, u8 *);
void func_080C8E88(u8 *, u8 *, u32);

#define BIND(value) asm("" : "+r"(value))
#define MESSAGE(value) func_0807C290((u8 *)(value))
#define STORE8(pointer, value)                                                                     \
    {                                                                                              \
        u8 *address;                                                                               \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = value;                                                                          \
        pointer = address;                                                                         \
    }
#define STORE32(pointer, value)                                                                    \
    {                                                                                              \
        u32 *address;                                                                              \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = value;                                                                          \
        pointer = (u8 *)address;                                                                   \
    }

void func_08090168(void)
{
    volatile struct {
        u8 *members[4];
        u32 done;
    } local;
    register s32 current asm("r0");
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
    u8 *pointer7;
    register u8 *unit asm("r8");
    register u32 two asm("r9");
    register s32 state asm("r10");
    register u8 *pointer10 asm("r10");
    u32 reserved7;

    pointer1 = (u8 *)0x0201F5F8;
    current = 0;
    pointer1[4] = current;
    pointer1[5] = current;
    pointer1[2] = current;
    pointer1[3] = current;
    state = current;
    local.done = current;
    work1 = 2;
    two = work1;
    asm("" : "+r"(two) : "r"(work1));
state_loop:
    current = 0x1000;
    BIND(current);
    if (state == current)
        goto part_intro;
    if (state > current)
        goto later_states;
    work2 = state;
    BIND(work2);
    if (work2 == 0)
        goto unit_intro;
    goto next_state;
later_states:
    work3 = 0x1010;
    BIND(work3);
    if (state == work3)
        goto select_part;
    current = 0x2000;
    BIND(current);
    if (state == current)
        goto compare_parts;
    goto next_state;
unit_intro:
    MESSAGE(0x08000C3E);
    pointer5 = (u8 *)0x0201F5F8;
    work1 = pointer5[3];
    pointer2 = (u8 *)0x02009480;
    work3 = 0x1825;
    BIND(pointer2);
    BIND(work3);
    pointer0 = (u8 *)((u32)pointer2 + work3);
    STORE8(pointer0, work1);
    work5 = 0x1824;
    BIND(work5);
    pointer0 = (u8 *)((u32)pointer2 + work5);
    STORE8(pointer0, work1);
    pointer1 = (u8 *)0x0201F5F8;
    current = pointer1[2];
    pointer2 = (u8 *)0x0200ACA6;
    STORE8(pointer2, current);
    func_08089CE0(0, 0);
    current = 5;
    work1 = 0x808;
    asm("" : "+r"(current), "+r"(work1));
    func_0808AC1C(current, work1);
    asm(""
        : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work3), "=r"(work4), "=r"(work5),
          "=r"(work6), "=r"(work7), "=r"(unit));
    asm("" : "=l"(reserved7) : "0"(work7));
    current = func_080771BC((u8 *)0x08424594, (u8 *)0x084245A0, 0, 200, ({
                                current = 104;
                                BIND(current);
                                current;
                            }),
                            ({
                                current = 0x180;
                                BIND(current);
                                current;
                            }),
                            ({
                                current = 3;
                                BIND(current);
                                current;
                            }),
                            ({
                                work3 = 8;
                                BIND(work3);
                                work3;
                            }),
                            ({
                                work5 = state;
                                BIND(work5);
                                asm volatile(""
                                             :
                                             : "r"(current), "r"(work1), "r"(work2), "r"(work3),
                                               "r"(work4), "r"(work5), "r"(work6), "l"(reserved7),
                                               "r"(unit), "r"(state)
                                             : "r11", "r12");
                                work5;
                            }));
    pointer1 = (u8 *)0x0201F5F8;
    *(u32 *)(pointer1 + 0x18) = current;
    asm(""
        : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work3), "=r"(work4), "=r"(work6),
          "=r"(work7));
    BIND(work5);
    asm("" : "=l"(reserved7) : "0"(work7));
    current = func_080771BC((u8 *)0x080F2354, (u8 *)0x080F2390, 0, 136, ({
                                current = 80;
                                BIND(current);
                                current;
                            }),
                            ({
                                current = 0x30D;
                                BIND(current);
                                current;
                            }),
                            ({
                                current = 15;
                                BIND(current);
                                current;
                            }),
                            ({
                                work2 = 8;
                                BIND(work2);
                                work2;
                            }),
                            ({
                                asm volatile(""
                                             :
                                             : "r"(current), "r"(work1), "r"(work2), "r"(work3),
                                               "r"(work4), "r"(work5), "r"(work6), "l"(reserved7),
                                               "r"(unit), "r"(state)
                                             : "r11", "r12");
                                work5;
                            }));
    pointer3 = (u8 *)0x0201F5F8;
    *(u32 *)(pointer3 + 0x48) = current;
    func_0808A7F8(0, 1, 216, 152);
    func_0808A7F8(1, 16, 160, 152);
    pointer6 = (u8 *)0x0201F5F8;
    pointer7 = (u8 *)0x0200C4A2;
unit_picker:
    pointer1 = (u8 *)0x02030B6C;
    BIND(pointer1);
    current = pointer6[2];
    pointer0 = (u8 *)(current + (u32)pointer1);
    work1 = *pointer0;
    current = 0x94;
    current *= work1;
    pointer5 = (u8 *)0x02020E88;
    BIND(pointer5);
    pointer0 = (u8 *)(current + (u32)pointer5);
    unit = pointer0;
    asm("" : "+r"(unit) : "r"(pointer0));
    work2 = *(u32 *)(pointer6 + 0x18);
    work3 = *(u32 *)(pointer6 + 0x48);
    func_0808B590(unit, 6, work2, work3, ({
                      current = 1;
                      current;
                  }));
    MESSAGE(0x08000C96);
    pointer0 = (u8 *)0x0200C4A1;
    current = *pointer0;
    pointer6[3] = current;
    pointer1 = (u8 *)0x0200C4A0;
    current = *pointer1;
    pointer6[2] = current;
    current = *pointer7;
    if (current != 1)
        goto unit_menu_response;
    pointer3 = unit;
    BIND(pointer3);
    work2 = pointer3[2];
    if (work2 != 0xFF)
        goto unit_has_pilot;
    func_08075F20(0x114);
    pointer1 = (u8 *)0x0200C4BC;
    pointer5 = unit;
    BIND(pointer5);
    current = *pointer5;
    STORE8(pointer1, current);
    func_0808A890(0);
    pointer0 = (u8 *)0x080034E6;
    goto unit_error;
unit_has_pilot:
    pointer0 = unit;
    BIND(pointer0);
    work1 = *(u16 *)(pointer0 + 4);
    current = 4;
    current &= work1;
    if (current == 0)
        goto unit_unlocked;
    func_08075F20(0x114);
    pointer1 = unit;
    BIND(pointer1);
    current = pointer1[2];
    current <<= 6;
    pointer2 = (u8 *)0x02020E88;
    BIND(pointer2);
    pointer0 = (u8 *)((u32)pointer2 + current);
    work3 = 0x6B88;
    BIND(work3);
    pointer0 += work3;
    current = *pointer0;
    pointer5 = (u8 *)0x0200C4C0;
    STORE8(pointer5, current);
    pointer1 = (u8 *)0x0200C4BC;
    pointer2 = unit;
    BIND(pointer2);
    current = *pointer2;
    STORE8(pointer1, current);
    func_0808A890(0);
    pointer0 = (u8 *)0x080034A2;
unit_error:
    func_0807C290(pointer0);
    func_0808A8B4(0);
    goto unit_picker;
unit_unlocked:
    if (work2 == 0)
        goto choose_empty_unit;
    pointer1 = (u8 *)0x0200C4BC;
    pointer3 = unit;
    BIND(pointer3);
    current = *pointer3;
    STORE8(pointer1, current);
    current = pointer3[2];
    current <<= 6;
    pointer5 = (u8 *)0x02020E88;
    BIND(pointer5);
    pointer0 = (u8 *)((u32)pointer5 + current);
    work1 = 0x6B88;
    BIND(work1);
    pointer0 += work1;
    current = *pointer0;
    pointer2 = (u8 *)0x0200C4C0;
    STORE8(pointer2, current);
    func_0808A890(0);
    MESSAGE(0x08003406);
    func_0808A8B4(0);
    current = *pointer7;
    if (current != 1)
        goto unit_picker;
    pointer3 = (u8 *)0x0200C4A0;
    current = *pointer3;
    if (current != 0)
        goto unit_picker;
    work5 = 0x1000;
    BIND(work5);
    state = work5;
    goto close_unit_picker;
choose_empty_unit:
    current = 0x1000;
    BIND(current);
    state = current;
    goto close_unit_picker;
unused_pilot_error:
    func_08075F20(0x114);
    func_0808A890(0);
    MESSAGE(0x08003565);
    func_0808A8B4(0);
    goto checked_unused_pilots;
unit_menu_response:
    if (current != 2)
        goto check_unit_input;
    work4 = 1;
    pointer3 = (u8 *)0x02020E4C;
    work2 = 0x6BC4;
    BIND(work2);
scan_unused_pilots:
    current = work4 << 6;
    pointer1 = (u8 *)(current + (u32)pointer3);
    pointer0 = pointer1 + work2;
    current = *pointer0;
    if (current != 1)
        goto next_unused_pilot;
    work5 = 0x6BF2;
    BIND(work5);
    pointer0 = pointer1 + work5;
    current = *pointer0;
    if (current == 0)
        goto unused_pilot_error;
next_unused_pilot:
    current = work4 + 1;
    work4 = (u8)current;
    if ((u32)work4 <= 52)
        goto scan_unused_pilots;
checked_unused_pilots:
    if (work4 != 53)
        goto unit_picker;
    work4 = 0;
    pointer2 = (u8 *)0x02020E4C;
    current = 0x7A6A;
    BIND(current);
    pointer5 = pointer2 + current;
    work3 = 0x94;
scan_empty_units:
    pointer1 = (u8 *)(work4 + (u32)pointer5);
    current = *pointer1;
    if (current == 0)
        goto next_empty_unit;
    current *= work3;
    pointer0 = (u8 *)(current + (u32)pointer2);
    pointer0 += 0x3E;
    current = *pointer0;
    if (current == 0)
        goto found_empty_unit;
next_empty_unit:
    current = work4 + 1;
    work4 = (u8)current;
    if ((u32)work4 <= 5)
        goto scan_empty_units;
found_empty_unit:
    if ((u32)work4 > 5)
        goto no_empty_units;
    func_0808A890(0);
    MESSAGE(0x0800359F);
    func_0808A8B4(0);
    current = *pointer7;
    if (current != 1)
        goto unit_picker;
    pointer1 = (u8 *)0x0200C4A0;
    current = *pointer1;
    if (current != 0)
        goto unit_picker;
    work4 = 0;
    pointer5 = (u8 *)0x02020E4C;
clear_empty_units:
    work2 = 0x7A6A;
    BIND(work2);
    pointer0 = pointer5 + work2;
    pointer1 = (u8 *)(work4 + (u32)pointer0);
    current = *pointer1;
    if (current == 0)
        goto cleared_empty_unit;
    work1 = current;
    current = 0x94;
    current *= work1;
    pointer0 = (u8 *)(current + (u32)pointer5);
    pointer0 += 0x3E;
    current = *pointer0;
    if (current != 0)
        goto cleared_empty_unit;
    func_080BDEB0(work4);
cleared_empty_unit:
    current = work4 + 1;
    work4 = (u8)current;
    if ((u32)work4 <= 5)
        goto clear_empty_units;
    work3 = 1;
    local.done = work3;
    goto close_unit_picker;
no_empty_units:
    work5 = 1;
    local.done = work5;
    goto close_unit_picker;
check_unit_input:
    pointer0 = (u8 *)0x0200C4A4;
    work1 = *(u16 *)pointer0;
    current = 8;
    current &= work1;
    if (current == 0)
        goto unit_picker;
    pointer2 = *(u8 **)(pointer6 + 0x18);
    current = *(u32 *)pointer2;
    work1 = 0x20000;
    current |= work1;
    STORE32(pointer2, current);
    current = 5;
    work1 = 0;
    work2 = 0x808;
    asm("" : "+r"(current), "+r"(work1), "+r"(work2));
    current = func_0808B2F8(current, work1, work2);
    if (current != 0) {
        current = 0;
        pointer6[2] = current;
        pointer6[3] = current;
    }
    pointer0 = *(u8 **)(pointer6 + 0x18);
    work1 = *(u32 *)pointer0;
    work2 = 0xFFFDFFFF;
    work1 &= work2;
    STORE32(pointer0, work1);
    goto unit_picker;
close_unit_picker:
    MESSAGE(0x08000C9A);
    pointer1 = (u8 *)0x0201F5F8;
    current = *(u32 *)(pointer1 + 0x18);
    func_080771F4(current);
    pointer2 = (u8 *)0x0201F5F8;
    current = *(u32 *)(pointer2 + 0x48);
    func_080771F4(current);
    goto close_windows;
part_intro:
    MESSAGE(0x08003330);
    pointer3 = (u8 *)0x0201F5F8;
    work1 = pointer3[5];
    pointer5 = (u8 *)0x02009480;
    work2 = 0x2695;
    BIND(pointer5);
    BIND(work2);
    pointer0 = (u8 *)((u32)pointer5 + work2);
    STORE8(pointer0, work1);
    work3 = 0x2694;
    BIND(work3);
    pointer0 = (u8 *)((u32)pointer5 + work3);
    STORE8(pointer0, work1);
    pointer5 = (u8 *)0x0201F5F8;
    current = pointer5[4];
    pointer1 = (u8 *)0x0200BB16;
    STORE8(pointer1, current);
    func_0808A084(0);
    pointer1 = (u8 *)0x02020E4C;
    BIND(pointer1);
    pointer2 = unit;
    BIND(pointer2);
    current = pointer2[2];
    current <<= 6;
    pointer0 = (u8 *)(current + (u32)pointer1);
    work3 = 0x6BC4;
    BIND(work3);
    pointer0 += work3;
    work2 = *pointer0;
    func_0808AF0C(8, 1, work2);
    asm(""
        : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work3), "=r"(work4), "=r"(work5),
          "=r"(work6), "=r"(work7));
    asm("" : "=l"(reserved7) : "0"(work7));
    current = func_080771BC((u8 *)0x085ECCF0, (u8 *)0x085ECCFC, 0, 168, ({
                                current = 48;
                                BIND(current);
                                current;
                            }),
                            ({
                                work5 = 0;
                                BIND(work5);
                                work5;
                            }),
                            work5, ({
                                current = 8;
                                BIND(current);
                                current;
                            }),
                            ({
                                asm volatile(""
                                             :
                                             : "r"(current), "r"(work1), "r"(work2), "r"(work3),
                                               "r"(work4), "r"(work5), "r"(work6), "l"(reserved7),
                                               "r"(unit), "r"(state)
                                             : "r11", "r12");
                                work5;
                            }));
    pointer1 = (u8 *)0x0201F5F8;
    *(u32 *)(pointer1 + 0x4C) = current;
    work2 = 0x1010;
    BIND(work2);
    state = work2;
    goto next_state;
cancel_part:
    MESSAGE(0x0800338B);
    current = *(u32 *)(pointer5 + 0x4C);
    func_080771F4(current);
    work3 = 0;
    BIND(work3);
    state = work3;
    goto close_windows;
select_part:
    func_0808A7F8(0, 3, 200, 152);
    func_0808A7F8(1, 16, 144, 152);
    pointer5 = (u8 *)0x0201F5F8;
    pointer0 = (u8 *)0x0200C4C0;
    BIND(pointer0);
    pointer10 = pointer0;
    pointer7 = (u8 *)0x0200C4BC;
    pointer1 = (u8 *)0x02027A10;
    work2 = 0xFFFF943C;
    BIND(pointer1);
    BIND(work2);
    pointer6 = pointer1 + work2;
part_picker:
    pointer1 = (u8 *)0x02030C26;
    BIND(pointer1);
    current = pointer5[4];
    pointer0 = (u8 *)(current + (u32)pointer1);
    current = *pointer0;
    current <<= 6;
    pointer3 = (u8 *)0x02027A10;
    BIND(pointer3);
    pointer0 = (u8 *)(current + (u32)pointer3);
    local.members[0] = pointer0;
    work1 = 0;
    local.members[1] = (u8 *)work1;
    work2 = *(u32 *)(pointer5 + 0x4C);
    func_0808DC94(pointer0, work1, work2, 1);
    MESSAGE(0x08003387);
    pointer0 = (u8 *)0x0200C4A1;
    current = *pointer0;
    pointer5[5] = current;
    pointer2 = (u8 *)0x0200C4A0;
    current = *pointer2;
    pointer5[4] = current;
    pointer3 = (u8 *)0x0200C4A2;
    current = *pointer3;
    if (current != 1)
        goto part_menu_response;
    pointer3 = local.members[0];
    work1 = pointer3[3];
    current = two;
    current &= work1;
    if (current == 0)
        goto part_unlocked;
    func_08075F20(0x114);
    pointer1 = local.members[0];
    current = *pointer1;
    pointer2 = pointer10;
    STORE8(pointer2, current);
    pointer1 += 0x2E;
    work1 = *pointer1;
    current = 0x94;
    current *= work1;
    pointer0 = (u8 *)(current + (u32)pointer6);
    pointer0 += 0x3C;
    current = *pointer0;
    *pointer7 = current;
    func_0808A890(0);
    pointer0 = (u8 *)0x080034A2;
    goto part_error;
part_unlocked:
    pointer4 = pointer3 + 0x2E;
    work2 = *pointer4;
    if (work2 == 0)
        goto choose_part;
    pointer1 = (u8 *)0x02030B6C;
    BIND(pointer1);
    current = pointer5[2];
    pointer0 = (u8 *)(current + (u32)pointer1);
    current = *pointer0;
    if (work2 == current)
        goto part_already_selected;
    current = *pointer3;
    pointer3 = pointer10;
    STORE8(pointer3, current);
    work1 = *pointer4;
    current = 0x94;
    current *= work1;
    pointer0 = (u8 *)(current + (u32)pointer6);
    pointer0 += 0x3C;
    current = *pointer0;
    *pointer7 = current;
    func_0808A890(0);
    MESSAGE(0x08003455);
    func_0808A8B4(0);
    pointer1 = (u8 *)0x0200C4A2;
    current = *pointer1;
    if (current != 1)
        goto part_picker;
    pointer2 = (u8 *)0x0200C4A0;
    current = *pointer2;
    if (current != 0)
        goto part_picker;
    goto choose_part;
part_already_selected:
    func_08075F20(0x114);
    pointer1 = local.members[0];
    current = *pointer1;
    pointer2 = pointer10;
    STORE8(pointer2, current);
    pointer1 += 0x2E;
    work1 = *pointer1;
    current = 0x94;
    current *= work1;
    pointer0 = (u8 *)(current + (u32)pointer6);
    pointer0 += 0x3C;
    current = *pointer0;
    *pointer7 = current;
    func_0808A890(0);
    pointer0 = (u8 *)0x08003529;
part_error:
    func_0807C290(pointer0);
    func_0808A8B4(0);
    goto part_picker;
choose_part:
    work3 = 0x2000;
    BIND(work3);
    state = work3;
    goto close_windows;
part_menu_response:
    if (current == 2)
        goto cancel_part;
    pointer0 = (u8 *)0x0200C4A4;
    work1 = *(u16 *)pointer0;
    current = 8;
    current &= work1;
    if (current == 0)
        goto part_picker;
    pointer2 = *(u8 **)(pointer5 + 0x4C);
    current = *(u32 *)pointer2;
    work1 = 0x20000;
    current |= work1;
    STORE32(pointer2, current);
    pointer1 = unit;
    BIND(pointer1);
    current = pointer1[2];
    current <<= 6;
    pointer0 = (u8 *)(current + (u32)pointer6);
    work2 = 0x6BC4;
    BIND(work2);
    pointer0 += work2;
    work3 = *pointer0;
    current = func_0808B3BC(8, 0, 1, work3);
    if (current != 0) {
        work3 = 0;
        pointer5[4] = work3;
        pointer5[5] = work3;
    }
    pointer0 = *(u8 **)(pointer5 + 0x4C);
    work1 = *(u32 *)pointer0;
    work2 = 0xFFFDFFFF;
    work1 &= work2;
    STORE32(pointer0, work1);
    goto part_picker;
close_windows:
    func_0808A86C(0);
    func_0808A86C(1);
    goto next_state;
compare_parts:
    MESSAGE(0x08003392);
    pointer0 = (u8 *)0x02031254;
    BIND(pointer0);
    func_080C8E88(pointer0, unit, 0x94);
    pointer0 = (u8 *)0x02031254;
    BIND(pointer0);
    func_080BD57C(pointer0);
    pointer0 = (u8 *)0x02031254;
    BIND(pointer0);
    func_080BDCD8(pointer0);
    pointer5 = (u8 *)0x020312B6;
    current = *(s16 *)pointer5;
    func_0807BA24(current, 4, 0, 18, ({
                      work2 = two;
                      BIND(work2);
                      work2;
                  }),
                  ({
                      work3 = 4;
                      work3;
                  }),
                  ({
                      work5 = 0;
                      work5;
                  }));
    pointer1 = (u8 *)0x020312B8;
    current = *(s16 *)pointer1;
    func_0807BA24(current, 4, 0, 18, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  ({
                      work5 = 4;
                      work5;
                  }),
                  ({
                      work1 = 1;
                      work1;
                  }));
    pointer2 = (u8 *)0x020312BA;
    asm("" : "=r"(work1));
    current = *(s16 *)pointer2;
    asm("" : : "r"(work1));
    func_0807BA24(current, 4, 0, 18, ({
                      work5 = two;
                      BIND(work5);
                      work5;
                  }),
                  ({
                      work1 = 4;
                      work1;
                  }),
                  work5);
    pointer2 = (u8 *)0x020312BC;
    asm("" : "=r"(work1));
    current = *(s16 *)pointer2;
    asm("" : : "r"(work1));
    func_0807BA24(current, 4, 0, 18, work5, ({
                      work5 = 4;
                      work5;
                  }),
                  work5);
    pointer1 = (u8 *)0x020312BE;
    current = *(s16 *)pointer1;
    func_0807BA24(current, 4, 0, 18, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  work5, ({
                      work5 = 5;
                      work5;
                  }));
    pointer1 = (u8 *)0x020312C0;
    asm("" : "=r"(work3));
    current = *(s16 *)pointer1;
    asm("" : : "r"(work3));
    func_0807BA24(current, 4, 0, 18, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  ({
                      work5 = 4;
                      work5;
                  }),
                  ({
                      work1 = 6;
                      work1;
                  }));
    pointer0 = local.members[0];
    pointer1 = (u8 *)0x02031254;
    BIND(pointer1);
    current = func_080BFB24(pointer0, pointer1);
    work5 = current;
    BIND(work5);
    work5 <<= 16;
    work5 >>= 16;
    work4 = -work5;
    work4 |= work5;
    work4 >>= 31;
    work2 = two;
    BIND(work2);
    work4 &= work2;
    pointer0 = local.members[0];
    asm("" : "=r"(work1), "=r"(work2));
    current = *(s16 *)(pointer0 + 0x34);
    asm("" : : "r"(work1), "r"(work2));
    work5 += 100;
    current = func_080BD2F4(current, work5);
    func_0807BA24(current, 3, work4, 22, ({
                      work1 = two;
                      BIND(work1);
                      work1;
                  }),
                  ({
                      work2 = 8;
                      work2;
                  }),
                  ({
                      work3 = 0;
                      work3;
                  }));
    pointer6 = (u8 *)0x080F3798;
    func_0807B77C(pointer6, work4, 2);
    pointer0 = local.members[0];
    current = *(s16 *)(pointer0 + 0x36);
    current = func_080BD2F4(current, work5);
    func_0807BA24(current, 3, work4, 22, ({
                      work2 = two;
                      BIND(work2);
                      work2;
                  }),
                  ({
                      work3 = 8;
                      work3;
                  }),
                  ({
                      work1 = 4;
                      work1;
                  }));
    func_0807B77C(pointer6, work4, 2);
    pointer0 = local.members[0];
    current = *(s16 *)(pointer0 + 0x38);
    current = func_080BD2F4(current, work5);
    func_0807BA24(current, 3, work4, 22, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  ({
                      work1 = 8;
                      work1;
                  }),
                  ({
                      work2 = 5;
                      work2;
                  }));
    func_0807B77C(pointer6, work4, 2);
    pointer0 = local.members[0];
    current = *(s16 *)(pointer0 + 0x3A);
    current = func_080BD2F4(current, work5);
    func_0807BA24(current, 3, work4, 22, ({
                      work5 = two;
                      BIND(work5);
                      work5;
                  }),
                  ({
                      work1 = 8;
                      work1;
                  }),
                  ({
                      work2 = 6;
                      work2;
                  }));
    func_0807B77C(pointer6, work4, 2);
    pointer0 = local.members[0];
    current = func_080BFADC(pointer0, 0x1A);
    work4 = (u16)current;
    pointer0 = local.members[0];
    current = func_080BFADC(pointer0, 0x1B);
    work5 = (u16)current;
    pointer0 = local.members[0];
    current = func_080BFADC(pointer0, 0x1C);
    work6 = (u16)current;
    pointer0 = local.members[0];
    current = func_080BFADC(pointer0, 0x35);
    work1 = work4 << 16;
    work1 >>= 16;
    work1 -= current;
    work4 = (u16)work1;
    pointer0 = local.members[0];
    current = func_080BFADC(pointer0, 0x36);
    work1 = work5 << 16;
    work1 >>= 16;
    work1 -= current;
    work5 = (u16)work1;
    pointer0 = local.members[0];
    current = func_080BFADC(pointer0, 0x37);
    work1 = work6 << 16;
    work1 >>= 16;
    work1 -= current;
    work6 = (u16)work1;
    func_0807BA24(current, 4, 0, 22, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  ({
                      work7 = 13;
                      work7;
                  }),
                  ({
                      current = 0;
                      current;
                  }));
    current = work4 << 16;
    current >>= 16;
    work2 = 2;
    if (current <= 0)
        work2 = (u32)current >> 31;
    func_0807BA24(current, 4, work2, 22, ({
                      work1 = two;
                      BIND(work1);
                      work1;
                  }),
                  work7, ({
                      work3 = 4;
                      work3;
                  }));
    current = work5 << 16;
    current >>= 16;
    work2 = 2;
    if (current <= 0)
        work2 = (u32)current >> 31;
    func_0807BA24(current, 4, work2, 22, ({
                      work5 = two;
                      BIND(work5);
                      work5;
                  }),
                  work7, ({
                      work1 = 5;
                      work1;
                  }));
    current = work6 << 16;
    current >>= 16;
    work2 = 2;
    if (current <= 0)
        work2 = (u32)current >> 31;
    func_0807BA24(current, 4, work2, 22, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  work7, ({
                      work5 = 6;
                      work5;
                  }));
    asm("" : : : "r7");
    pointer0 = (u8 *)0x02031254;
    BIND(pointer0);
    func_080BD98C(pointer0, (volatile u8 **)&local.members[0], 0, 0);
    pointer0 = (u8 *)0x02031254;
    BIND(pointer0);
    func_080BDCD8(pointer0);
    pointer1 = (u8 *)0x020312B6;
    current = *(s16 *)pointer1;
    func_0807BA24(current, 4, 0, 18, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  ({
                      work4 = 20;
                      work4;
                  }),
                  ({
                      work5 = 0;
                      work5;
                  }));
    pointer1 = (u8 *)0x020312B8;
    asm("" : "=r"(work3));
    current = *(s16 *)pointer1;
    asm("" : : "r"(work3));
    func_0807BA24(current, 4, 0, 18, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  work4, ({
                      work5 = 1;
                      work5;
                  }));
    pointer1 = (u8 *)0x020312BA;
    asm("" : "=r"(work3));
    current = *(s16 *)pointer1;
    asm("" : : "r"(work3));
    func_0807BA24(current, 4, 0, 18, ({
                      work3 = two;
                      BIND(work3);
                      work3;
                  }),
                  work4, work3);
    pointer5 = (u8 *)0x020312BC;
    BIND(pointer5);
    asm("" : "=r"(work2), "=r"(work3));
    current = *(s16 *)pointer5;
    asm("" : : "r"(work2), "r"(work3));
    func_0807BA24(current, 4, 0, 18, ({
                      work2 = two;
                      BIND(work2);
                      work2;
                  }),
                  work4, ({
                      work3 = 4;
                      work3;
                  }));
    pointer5 = (u8 *)0x020312BE;
    BIND(pointer5);
    asm("" : "=r"(work2), "=r"(work3));
    current = *(s16 *)pointer5;
    asm("" : : "r"(work2), "r"(work3));
    func_0807BA24(current, 4, 0, 18, ({
                      work2 = two;
                      BIND(work2);
                      work2;
                  }),
                  work4, ({
                      work3 = 5;
                      work3;
                  }));
    pointer5 = (u8 *)0x020312C0;
    BIND(pointer5);
    asm("" : "=r"(work2), "=r"(work3));
    current = *(s16 *)pointer5;
    asm("" : : "r"(work2), "r"(work3));
    func_0807BA24(current, 4, 0, 18, ({
                      work2 = two;
                      BIND(work2);
                      work2;
                  }),
                  work4, ({
                      work3 = 6;
                      work3;
                  }));
    MESSAGE(0x080033FE);
    pointer0 = (u8 *)0x0200C4A2;
    current = *pointer0;
    if (current != 1)
        goto compare_response;
    pointer0 = (u8 *)0x0200C4A0;
    current = *pointer0;
    if (current != 0)
        goto compare_finished;
    pointer1 = (u8 *)0x02030C26;
    BIND(pointer1);
    pointer5 = (u8 *)0x0201F5F8;
    current = pointer5[4];
    pointer0 = (u8 *)(current + (u32)pointer1);
    current = *pointer0;
    pointer2 = (u8 *)0x02030B6C;
    BIND(pointer2);
    work1 = pointer5[2];
    pointer1 = (u8 *)(work1 + (u32)pointer2);
    work1 = *pointer1;
    func_080BF814(current, work1);
compare_finished:
    MESSAGE(0x0800338B);
    pointer1 = (u8 *)0x0201F5F8;
    current = *(u32 *)(pointer1 + 0x4C);
    func_080771F4(current);
    work2 = 0;
    BIND(work2);
    state = work2;
    goto next_state;
compare_response:
    if (current != 2)
        goto next_state;
    work3 = 0x1010;
    BIND(work3);
    state = work3;
next_state:
    work5 = local.done;
    if (work5 == 0)
        goto state_loop;
}
