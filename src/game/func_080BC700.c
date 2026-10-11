#include "types.h"

void func_080755F4(void);
void func_0807560C(void);
void func_08075F20(u32);
void func_08079544(u32, u32);
void func_0807970C(void);
void func_0807A1A4(void);
void func_0807B748(u8 *, u32, u32, u32, u32);
void func_0807B77C(u32, u32, u32);
void func_0807BD4C(u32);
void func_0807C290(u8 *);
u32 func_0807DA64(void);
u32 func_0807F18C(void);
void func_0807F1D0(u32, u32);
void func_0807F204(u32, u32);
void func_080801D0(void);
u32 func_08080308(void);
void func_08080370(void);
void func_08080390(u8 *, u32, u8 *);
u32 func_080803C4(void);
void func_080804DC(u8 *, u32, u8 *);
u32 func_08080510(void);
void func_0808A3F0(u32);
void func_0808A6DC(u32);
void func_0808B098(u32);
void func_0808B10C(u32, u32, u32, u8 *, u8 *);
void func_0808B180(u32);
void func_0808FC78(u32, u32);
void func_08091DB4(void);
void func_080B453C(u32, u32, u32);
u32 func_080B4610(u8 *, u32, u32);
void func_080B467C(void);
void func_080C8FCC(u32);

#define BIND(value) asm("" : "+r"(value))
#define MESSAGE(value) func_0807C290((u8 *)(value))
#define STORE8(pointer, value)                                                                     \
    {                                                                                              \
        u8 *address;                                                                               \
        asm("" : "=r"(address) : "0"(pointer));                                                    \
        *address = (value);                                                                        \
        pointer = address;                                                                         \
    }
#define SHOW(function, address, mode, text)                                                        \
    pointer0 = (address);                                                                          \
    work1 = (mode);                                                                                \
    pointer2 = (u8 *)(text);                                                                       \
    function(pointer0, work1, pointer2)
#define WAIT_LEFT(label)                                                                           \
    label:                                                                                         \
    current = func_080803C4();                                                                     \
    current <<= 24;                                                                                \
    work5 = current >> 24;                                                                         \
    func_080C8FCC(1);                                                                              \
    if (work5 == 0)                                                                                \
    goto label
#define WAIT_RIGHT(label)                                                                          \
    label:                                                                                         \
    current = func_08080510();                                                                     \
    current <<= 24;                                                                                \
    work4 = current >> 24;                                                                         \
    func_080C8FCC(1);                                                                              \
    if (work4 == 0)                                                                                \
    goto label
#define STACK_BYTE(pointer, value)                                                                 \
    pointer = stack_pointer;                                                                       \
    pointer += value

void func_080BC700(void)
{
    volatile struct {
        u8 mode, action, unit, option;
        s32 amount;
        u32 count, seen;
    } local;
    register u32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 work3 asm("r3");
    register u32 work4 asm("r4");
    register u32 work5 asm("r5");
    register s32 state asm("r6");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    u8 *pointer7;
    register u8 *table8 asm("r8");
    register u8 *action asm("r9");
    register u32 cursor asm("r10");
    register u8 *stack_pointer asm("sp");

    func_08091DB4();
    MESSAGE(0x08024CAA);
    func_08079544(15, 0);
    func_0807970C();
    func_080801D0();
    goto check_ready;
wait_ready:
    pointer0 = (u8 *)0x0300000E;
    work1 = *(u16 *)pointer0;
    current = 2;
    current &= work1;
    if (current == 0)
        goto tick_ready;
    func_08075F20(0xCB);
    func_08080370();
    MESSAGE(0x080244DB);
    func_08079544(16, 0);
    func_0807970C();
    goto done;
tick_ready:
    func_080C8FCC(1);
check_ready:
    current = func_08080308();
    current <<= 24;
    if (current == 0)
        goto wait_ready;
    pointer4 = (u8 *)0x080F5C20;
    func_08080390(0, 0, pointer4);
    func_080804DC(0, 0, pointer4);
    current = 5;
    BIND(current);
    pointer0 = (u8 *)(current + (u32)stack_pointer);
    BIND(pointer0);
    action = pointer0;
wait_both:
    current = func_080803C4();
    current <<= 24;
    work5 = current >> 24;
    current = func_08080510();
    current <<= 24;
    work4 = current >> 24;
    func_080C8FCC(1);
    if (work5 == 0)
        goto wait_both;
    if (work4 == 0)
        goto wait_both;
    MESSAGE(0x08024CEE);
    work1 = 0;
    pointer2 = action;
    STORE8(pointer2, work1);
    pointer0 = (u8 *)&local.mode;
    STORE8(pointer0, work1);
    state = 0;
state_loop:
    current = 0x1220;
    BIND(current);
    if (state == current)
        goto choose_amount;
    if (state > (s32)current)
        goto upper_states;
    current = 0x1100;
    BIND(current);
    if (state == current)
        goto show_units;
    if (state > (s32)current)
        goto middle_states;
    current = 0x1000;
    BIND(current);
    if (state == current)
        goto unit_intro;
    if (state > (s32)current)
        goto unit_menu_state;
    if (state == 0)
        goto choose_mode;
    goto next_state;
unit_menu_state:
    current = 0x1010;
    BIND(current);
    if (state == current)
        goto unit_menu;
    goto next_state;
middle_states:
    current = 0x1200;
    BIND(current);
    if (state == current)
        goto part_intro;
    if (state > (s32)current)
        goto choose_part_state;
    current -= 0xF0;
    BIND(current);
    if (state == current)
        goto choose_unit;
    goto next_state;
choose_part_state:
    current = 0x1210;
    BIND(current);
    if (state == current)
        goto choose_part;
    goto next_state;
upper_states:
    current = 0x2100;
    BIND(current);
    if (state == current)
        goto select_free_parts;
    if (state > (s32)current)
        goto transfer_states;
    current = 0x2000;
    BIND(current);
    if (state == current)
        goto part_menu_intro;
    if (state > (s32)current)
        goto part_menu_state;
    current = 0x1230;
    BIND(current);
    if (state == current)
        goto transfer_to_unit;
    goto next_state;
part_menu_state:
    current = 0x2010;
    BIND(current);
    if (state == current)
        goto part_menu;
    goto next_state;
transfer_states:
    work4 = 0x2210;
    BIND(work4);
    if (state == work4)
        goto select_counted_parts;
    if (state > (s32)work4)
        goto amount_states;
    current = 0x2200;
    BIND(current);
    if (state == current)
        goto counted_parts_intro;
    goto next_state;
amount_states:
    current = 0x2220;
    BIND(current);
    if (state == current)
        goto available_amount;
    current += 0x10;
    BIND(current);
    if (state == current)
        goto transfer_from_unit;
    goto next_state;
choose_mode:
    pointer0 = (u8 *)0x030057F4;
    current = *pointer0;
    if (current == 0)
        goto choose_remote_mode;
    MESSAGE(0x08024CFC);
    pointer1 = (u8 *)0x02009480;
    BIND(pointer1);
    current = 0x4E6;
    BIND(current);
    pointer1 += current;
    pointer0 = (u8 *)&local.mode;
    current = *pointer0;
    STORE8(pointer1, current);
    MESSAGE(0x08024D40);
    pointer0 = (u8 *)0x0200C4A2;
    current = *pointer0;
    if (current != 1)
        goto cancel_mode;
    pointer0 = (u8 *)0x0200C4A0;
    BIND(pointer0);
    work1 = *pointer0;
    goto store_mode;
cancel_mode:
    work1 = 2;
store_mode:
    pointer0 = (u8 *)&local.mode;
    STORE8(pointer0, work1);
    SHOW(func_08080390, (u8 *)&local.mode, 1, 0x080F5C20);
    WAIT_LEFT(wait_mode_left);
    goto selected_mode;
choose_remote_mode:
    MESSAGE(0x08024D68);
    SHOW(func_080804DC, (u8 *)&local.mode, 1, 0x080F5C20);
    WAIT_RIGHT(wait_mode_right);
selected_mode:
    pointer0 = (u8 *)&local.mode;
    work2 = *pointer0;
    if (work2 == 2)
        goto cancel;
    pointer0 = (u8 *)0x030057F4;
    current = *pointer0;
    if (current != 0)
        goto mode_chosen;
    pointer0 = (u8 *)&local.mode;
    work1 = 0;
    if (work2 == 0)
        work1 = 1;
    STORE8(pointer0, work1);
    goto mode_chosen;
cancel:
    func_08080370();
    MESSAGE(0x08024D46);
    goto close;
mode_chosen:
    pointer0 = (u8 *)&local.mode;
    current = *pointer0;
    state = 0x2000;
    BIND(state);
    if (current != 0)
        goto next_state;
    state = 0x1000;
    goto next_state;
unit_intro:
    pointer0 = (u8 *)0x08024D9D;
    goto return_to_unit_menu;
unit_menu:
    MESSAGE(0x08024D83);
choose_action:
    MESSAGE(0x08024DDB);
    pointer0 = (u8 *)0x0200C4A2;
    BIND(pointer0);
    work4 = *pointer0;
    if (work4 != 1)
        goto cancel_action;
    pointer0 = (u8 *)0x0200C4A0;
    current = *pointer0;
    if (current != 0)
        goto check_unit_parts;
    work3 = 0;
    pointer1 = (u8 *)0x02028888;
    current = *(u32 *)pointer1;
    current &= work4;
    if (current != 0)
        goto found_unit;
    pointer7 = pointer1;
    work4 = 31;
    work5 = 1;
scan_units:
    current = work3 + 1;
    current <<= 24;
    work3 = current >> 24;
    if (work3 > 153)
        goto found_unit;
    work2 = current >> 29;
    work2 <<= 2;
    pointer2 = (u8 *)(work2 + (u32)pointer7);
    current = work3;
    current &= work4;
    work1 = work5;
    work1 <<= current;
    current = *(u32 *)pointer2;
    current &= work1;
    if (current == 0)
        goto scan_units;
found_unit:
    if (work3 != 154)
        goto action_units;
    func_08075F20(0x114);
    MESSAGE(0x08024DE4);
    goto choose_action;
action_units:
    current = 0;
    pointer2 = action;
    STORE8(pointer2, current);
    goto action_chosen;
check_unit_parts:
    func_0808A6DC(0);
    pointer0 = (u8 *)0x0203116B;
    current = *pointer0;
    if (current != 0)
        goto action_parts;
    func_08075F20(0x114);
    MESSAGE(0x08024E1A);
    goto choose_action;
action_parts:
    pointer0 = action;
    STORE8(pointer0, work4);
    goto action_chosen;
cancel_action:
    current = 2;
    pointer1 = action;
    STORE8(pointer1, current);
action_chosen:
    SHOW(func_08080390, action, 1, 0x080F5C2C);
    WAIT_LEFT(wait_action);
    pointer2 = action;
    current = *pointer2;
    switch ((s32)current) {
    case 0:
        state = 0x1100;
        goto next_state;
    case 1:
        state = 0x1200;
        goto next_state;
    case 2:
        pointer0 = (u8 *)0x08024DDF;
        goto reset_menu;
    }
    goto next_state;
show_units:
    MESSAGE(0x08024E80);
    func_0808A3F0(0);
    func_0808B098(4);
    current = 0;
    cursor = current;
    state = 0x1110;
    goto next_state;
choose_unit:
    MESSAGE(0x08024E54);
    STACK_BYTE(pointer7, 6);
    pointer1 = (u8 *)0x02030F92;
    BIND(pointer1);
    table8 = pointer1;
unit_picker:
    work2 = cursor;
    BIND(work2);
    current = work2 << 1;
    pointer0 = (u8 *)(current + (u32)table8);
    current = *pointer0;
    func_0808FC78(current, 2);
    MESSAGE(0x08024F3E);
    pointer0 = (u8 *)0x0200C4A0;
    current = *pointer0;
    cursor = current;
    pointer0 = (u8 *)0x0200C4A2;
    current = *pointer0;
    if (current == 0)
        goto unit_picker;
    if (current != 1)
        goto cancel_unit;
    work1 = cursor;
    BIND(work1);
    current = work1 << 1;
    pointer0 = (u8 *)(current + (u32)table8);
    work1 = *(u16 *)pointer0;
    work2 = 0x8000;
    BIND(work2);
    current = work2;
    current &= work1;
    if (current == 0)
        goto chosen_unit;
    func_08075F20(0x114);
    goto unit_picker;
chosen_unit:
    *pointer7 = work1;
    goto show_chosen_unit;
cancel_unit:
    current = 0xFF;
    *pointer7 = current;
show_chosen_unit:
    SHOW(func_08080390, pointer7, 1, 0x080F5C38);
    WAIT_LEFT(wait_chosen_unit);
    current = *pointer7;
    if (current == 0xFF)
        goto unit_picker_cancelled;
    STACK_BYTE(pointer0, 7);
    SHOW(func_080804DC, pointer0, 1, 0x080F5C40);
    STACK_BYTE(pointer6, 7);
    WAIT_RIGHT(wait_unit_confirm);
    pointer0 = (u8 *)0x0200C4BC;
    work1 = *pointer7;
    STORE8(pointer0, work1);
    current = *pointer6;
    if (current == 0)
        goto reject_unit;
    MESSAGE(0x08024FBA);
    goto unit_picker;
reject_unit:
    func_08075F20(0x114);
    MESSAGE(0x08024FE9);
    goto unit_picker;
unit_picker_cancelled:
    pointer0 = (u8 *)0x08024F42;
return_to_unit_menu:
    func_0807C290(pointer0);
unit_menu_again:
    state = 0x1010;
    goto next_state;
part_intro:
    MESSAGE(0x08024F0A);
    current = 0;
    BIND(current);
    cursor = current;
part_menu_again:
    state = 0x1210;
    goto next_state;
choose_part:
    func_0808A6DC(0);
    pointer0 = (u8 *)0x0203116B;
    current = *pointer0;
    if (current != 0)
        goto show_part_list;
    STACK_BYTE(pointer1, 6);
    current = 0xFF;
    *pointer1 = current;
    pointer7 = pointer1;
    goto show_chosen_part;
pick_part:
    work1 = cursor;
    BIND(work1);
    current = work1 << 1;
    pointer0 = (u8 *)(current + (u32)pointer4);
    current = *pointer0;
    goto part_selected;
show_part_list:
    func_0808B180(4);
    MESSAGE(0x08024EDA);
    STACK_BYTE(pointer7, 6);
    pointer5 = (u8 *)0x087A5730;
    pointer4 = (u8 *)0x020310A3;
part_picker:
    func_0807BD4C(5);
    work2 = cursor;
    BIND(work2);
    current = work2 << 1;
    pointer0 = (u8 *)(current + (u32)pointer4);
    current = *pointer0;
    current <<= 2;
    pointer0 = (u8 *)(current + (u32)pointer5);
    current = *(u32 *)pointer0;
    func_0807B77C(current, 0, 5);
    MESSAGE(0x08024F3E);
    pointer0 = (u8 *)0x0200C4A0;
    current = *pointer0;
    cursor = current;
    pointer0 = (u8 *)0x0200C4A2;
    current = *pointer0;
    if (current == 0)
        goto part_picker;
    if (current == 1)
        goto pick_part;
    current = 0xFF;
part_selected:
    *pointer7 = current;
show_chosen_part:
    SHOW(func_08080390, pointer7, 1, 0x080F5C38);
    WAIT_LEFT(wait_chosen_part);
    current = *pointer7;
    if (current == 0xFF)
        goto part_picker_cancelled;
    state = 0x1220;
    goto next_state;
part_picker_cancelled:
    MESSAGE(0x08024F42);
    pointer0 = (u8 *)0x0203116B;
    current = *pointer0;
    if (current != 0)
        goto unit_menu_again;
    func_08075F20(0x114);
    MESSAGE(0x08024E1A);
    goto unit_menu_again;
choose_amount:
    SHOW(func_080804DC, (u8 *)&local.amount, 4, 0x080F5C4C);
    STACK_BYTE(pointer7, 6);
    WAIT_RIGHT(wait_amount);
    current = *pointer7;
    pointer1 = (u8 *)0x02028822;
    pointer0 = (u8 *)(current + (u32)pointer1);
    work1 = *pointer0;
    current = local.amount;
    if ((s32)current <= (s32)work1)
        goto amount_chosen;
    local.amount = work1;
amount_chosen:
    state = 0x1230;
    goto next_state;
transfer_to_unit:
    work4 = local.amount;
    if (work4 != 0)
        goto choose_transfer_count;
    func_08075F20(0x114);
    MESSAGE(0x08024F6B);
    local.count = work4;
    pointer5 = (u8 *)&local.count;
    BIND(pointer5);
    goto show_transfer_count;
choose_transfer_count:
    MESSAGE(0x08024F47);
    current = 1;
    local.count = current;
    pointer0 = (u8 *)0x0200C4A0;
    BIND(pointer0);
    work1 = *pointer0;
    pointer0 = (u8 *)0x0200C4A1;
    current = *pointer0;
    work1 -= current;
    work1 <<= 25;
    work1 >>= 24;
    work2 = local.amount;
    func_080B453C(4, work1, work2);
    STACK_BYTE(pointer7, 6);
    pointer5 = (u8 *)&local.count;
    BIND(pointer5);
    pointer6 = (u8 *)0x0203198C;
count_picker:
    current = *pointer7;
    asm("" : : : "r7");
    pointer4 = (u8 *)&local.count;
    BIND(pointer4);
    work1 = *pointer5;
    func_0808B10C(current, work1, 10, pointer6, (u8 *)0x020319CC);
    pointer0 = (u8 *)0x0200C4A0;
    current = *pointer0;
    pointer1 = (u8 *)0x0200C4A1;
    work1 = *pointer1;
    current -= work1;
    current <<= 1;
    func_0807B748(pointer6, 0, 4, 0, current);
    func_0807A1A4();
    current = func_080B4610(pointer4, 4, 12);
    if (current == 0)
        goto count_picker;
    func_080B467C();
show_transfer_count:
    SHOW(func_08080390, pointer5, 4, 0x080F5C58);
    WAIT_LEFT(wait_transfer_count);
    work1 = local.count;
    if (work1 == 0)
        goto part_menu_again;
    STACK_BYTE(pointer4, 6);
    current = *pointer4;
    work1 = (u8)work1;
    func_0807F204(current, work1);
    func_0807560C();
    current = func_0807DA64();
    current <<= 24;
    work5 = current >> 24;
    func_080755F4();
    pointer1 = (u8 *)0x0200C4D4;
    current = *pointer4;
    STORE8(pointer1, current);
    pointer1 = (u8 *)0x0200C4AC;
    current = local.count;
    *(u32 *)pointer1 = current;
    MESSAGE(0x08025037);
    if (work5 != 0)
        goto part_menu_again;
    func_08075F20(0x114);
    MESSAGE(0x08025134);
    goto part_menu_again;
part_menu_intro:
    MESSAGE(0x08024D68);
    MESSAGE(0x0802506F);
    state = 0x2010;
    goto next_state;
part_menu:
    SHOW(func_080804DC, action, 1, 0x080F5C2C);
    WAIT_RIGHT(wait_part_menu);
    pointer2 = action;
    current = *pointer2;
    switch ((s32)current) {
    case 0:
        state = 0x2100;
        goto next_state;
    case 1:
        state = 0x2200;
        goto next_state;
    case 2:
        pointer0 = (u8 *)0x08025088;
        goto reset_menu;
    }
    goto next_state;
reset_menu:
    func_0807C290(pointer0);
    state = 0;
    goto next_state;
select_free_parts:
    current = 0;
    local.seen = current;
    MESSAGE(0x0802508B);
    STACK_BYTE(pointer7, 6);
    work1 = 7;
    BIND(work1);
    pointer1 = (u8 *)(work1 + (u32)stack_pointer);
    BIND(pointer1);
    table8 = pointer1;
free_part_picker:
    SHOW(func_080804DC, pointer7, 1, 0x080F5C38);
    WAIT_RIGHT(wait_free_part);
    current = *pointer7;
    if (current == 0xFF)
        goto free_parts_cancelled;
    current = func_0807F18C();
    pointer2 = table8;
    STORE8(pointer2, current);
    SHOW(func_08080390, table8, 1, 0x080F5C40);
    STACK_BYTE(pointer6, 7);
    WAIT_LEFT(wait_free_confirm);
    current = *pointer6;
    if (current == 0)
        goto free_part_picker;
    func_0807560C();
    current = func_0807DA64();
    current <<= 24;
    work5 = current >> 24;
    func_080755F4();
    current = local.seen;
    if (current != 0)
        goto free_transfer_ready;
    MESSAGE(0x080250C6);
    work1 = 1;
    local.seen = work1;
free_transfer_ready:
    pointer1 = (u8 *)0x0200C4BC;
    current = *pointer7;
    STORE8(pointer1, current);
    MESSAGE(0x080250D1);
    if (work5 != 0)
        goto free_part_picker;
    func_08075F20(0x114);
    MESSAGE(0x08025134);
    goto free_part_picker;
free_parts_cancelled:
    work2 = local.seen;
    if (work2 == 0)
        goto finish_part_list;
    goto finish_transfer;
counted_parts_intro:
    current = 0;
    local.seen = current;
    MESSAGE(0x080250A6);
    goto counted_parts_again;
select_counted_parts:
    STACK_BYTE(pointer0, 6);
    SHOW(func_080804DC, pointer0, 1, 0x080F5C38);
    STACK_BYTE(pointer7, 6);
    WAIT_RIGHT(wait_counted_part);
    current = *pointer7;
    if (current == 0xFF)
        goto counted_parts_cancelled;
    state = 0x2220;
    goto next_state;
counted_parts_cancelled:
    work1 = local.seen;
    if (work1 == 0)
        goto finish_part_list;
finish_transfer:
    MESSAGE(0x08025131);
finish_part_list:
    MESSAGE(0x080250C3);
    func_0807A1A4();
    state = 0x2010;
    goto next_state;
available_amount:
    STACK_BYTE(pointer0, 6);
    current = *pointer0;
    pointer2 = (u8 *)0x02028822;
    BIND(pointer2);
    pointer0 = (u8 *)(current + (u32)pointer2);
    work1 = *pointer0;
    current = 99;
    current -= work1;
    local.amount = current;
    SHOW(func_08080390, (u8 *)&local.amount, 4, 0x080F5C4C);
    WAIT_LEFT(wait_available_amount);
    state = 0x2230;
    goto next_state;
transfer_from_unit:
    SHOW(func_080804DC, (u8 *)&local.count, 4, 0x080F5C58);
    WAIT_RIGHT(wait_remove_count);
    work1 = local.count;
    if (work1 == 0)
        goto counted_parts_again;
    STACK_BYTE(pointer4, 6);
    current = *pointer4;
    work1 = (u8)work1;
    func_0807F1D0(current, work1);
    func_0807560C();
    current = func_0807DA64();
    current <<= 24;
    work5 = current >> 24;
    func_080755F4();
    current = local.seen;
    if (current != 0)
        goto counted_transfer_ready;
    MESSAGE(0x080250F7);
    work1 = 1;
    local.seen = work1;
counted_transfer_ready:
    pointer1 = (u8 *)0x0200C4D4;
    current = *pointer4;
    STORE8(pointer1, current);
    pointer1 = (u8 *)0x0200C4AC;
    current = local.count;
    *(u32 *)pointer1 = current;
    MESSAGE(0x08025102);
    if (work5 != 0)
        goto counted_parts_again;
    func_08075F20(0x114);
    MESSAGE(0x08025134);
counted_parts_again:
    state = 0x2210;
next_state:
    work2 = 0;
    BIND(work2);
    if (work2 == 0)
        goto state_loop;
close:
    func_08079544(16, 0);
    func_0807970C();
done:
    return;
}
