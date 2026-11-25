#include "types.h"

extern u32 D_0201F5C4;
extern u16 D_0300004C;
extern u16 D_03000050;
extern u8 D_03000060[];
extern u8 D_08735574[];
extern u8 D_087B4C9C[];
extern u8 D_02020E04[];
extern u8 D_02020E1C[];
extern s16 D_0873555C[];
extern u8 D_02020E4C[];
extern u8 D_020288B6[];
extern u8 *D_087A43E0[];
extern u8 D_0873FCC8[];
extern u32 D_03000084;
extern u8 D_080F38B0[];
extern u16 D_030057EC;
extern u16 D_0300000E;
extern u8 D_02030B6C[];
extern u8 D_02020E88[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;

void func_0807C290(u32);
void func_08090B3C(void);
void func_08089CE0(u32, u32);
void func_080C8B7C(u16 *, u32, u32);
void func_080780C0(u8 *, u32, u32, u32, u32, u32);
void func_08090D98(u32);
void func_0807FF9C(u8 *, u32, u32, u32);
void func_08090EC0(u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0807B748(u8 *, u32, u32, u32, s32);
u32 func_080C8DC8(u32, u32);
u32 func_080C8D50(u32, u32);
void func_08090BB0(u8 *, u32, u32);
void func_080BDEB0(u32);
void func_080771F4(u8 *);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u32);
void func_0808AC1C(u32, u32);
u32 func_08090F8C(u8 *, u32, u32, u32);
void func_080BDE24(u32, u32);
u32 func_0808B2F8(u32, u32, u32);
void func_0808A86C(u32);
void func_0808A890(u32);
void func_0808A8B4(u32);

void func_0809104C(void)
{
    volatile u16 fill;
    volatile u32 flags;
    volatile u32 previous;
    volatile u32 selected;
    volatile u32 chosen;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    register s32 cursor asm("r6");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer5 asm("r5");
    register u8 *pointer6 asm("r6");
    register u8 *records asm("r7");
    register s32 objectOffset asm("r8");
    register s32 status asm("r9");
    register s32 active asm("r10");
    register u8 *available asm("r10");
    register u8 *units asm("r8");
    s32 stride;

    current = 0x0800365D;
    func_0807C290(current);
    func_08090B3C();
    current = 0;
    work1 = 0;
    func_08089CE0(current, work1);
    current = 0;
    chosen = current;
    pointer1 = (u8 *)&fill;
    pointer0 = (u8 *)&D_0201F5C4;
    current = *(u32 *)pointer0;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = current;
    }
    work1 = 0x06000800;
    work2 = 0x01000400;
    pointer0 = (u8 *)&fill;
    func_080C8B7C((u16 *)pointer0, work1, work2);
    pointer2 = (u8 *)&D_0300004C;
    current = *(u16 *)pointer2;
    work3 = 0x200;
    asm("" : "+r"(work3));
    work1 = work3;
    asm("" : "+r"(work1));
    current |= work1;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    pointer1 = (u8 *)&D_03000050;
    work4 = 0x109;
    asm("" : "+r"(work4));
    current = work4;
    asm("" : "+r"(current));
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = current;
    }
    pointer0 = D_03000060;
    work1 = chosen;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer0));
        *(s32 *)(address + 12) = work1;
        *(s32 *)(address + 8) = work1;
    }
    pointer6 = D_08735574;
    work5 = 5;
    func_080780C0(pointer6, 1, 0x11, 4, work5,
        ({ work4 = 2; asm("" : "+r"(work4)); work4; }));
    func_080780C0(pointer6, 1, 0x11, 9, work5, work4);
    func_080780C0(pointer6, 1, 0x11, 14, work5, work4);
    func_080780C0(pointer6, 1, 0x18, 4, work5, work4);
    func_080780C0(pointer6, 1, 0x18, 9, work5, work4);
    func_080780C0(pointer6, 1, 0x18, 14, work5, work4);
    work4 = 0;
init_loop:
    current = work4;
    func_08090D98(current);
    current = work4 + 1;
    work4 = (u8)current;
    if ((u32)work4 <= 5)
        goto init_loop;
    pointer0 = D_087B4C9C;
    work2 = 0x1C0;
    work1 = 0;
    work3 = 12;
    func_0807FF9C(pointer0, work1, work2, work3);
    work2 = 0;
    selected = work2;
    work3 = 0;
    previous = work3;
    cursor = 0;
    pointer4 = D_02020E04;
    *(s32 *)(pointer4 + 0x34) = work2;
    current = 0;
    func_08090EC0(current);
    current = selected;
    *(s32 *)(pointer4 + 0x30) = current;
    current = 0;
    work1 = 1;
    work2 = 0xD8;
    work3 = 0x98;
    func_0808A7F8(current, work1, work2, work3);
frame:
    work1 = 255;
    asm("" : "+r"(work1));
    active = work1;
    pointer2 = D_02020E04;
    pointer3 = *(u8 **)(pointer2 + 0x34);
    pointer1 = (u8 *)D_0873555C;
    work2 = cursor << 2;
    pointer0 = (u8 *)(work2 + (u32)pointer1);
    current = *(s16 *)pointer0;
    current <<= 8;
    *(s32 *)(pointer3 + 4) = current;
    pointer1 += 2;
    pointer1 = (u8 *)(work2 + (u32)pointer1);
    {
        u32 spare;
        asm("" : "=r"(work4), "=r"(work5));
        asm("" : "=l"(spare) : "0"(records));
        asm volatile("" : : "r"(work4));
        current = *(s16 *)pointer1;
        asm volatile("" : : "l"(spare), "r"(work5));
    }
    current <<= 8;
    *(s32 *)(pointer3 + 8) = current;
    objectOffset = work2;
    current = selected;
    if (current == 0)
        goto check_neighbor;
    pointer4 = D_02020E4C;
    work1 = 0x7A6A;
    asm("" : "+r"(work1));
    asm("" : "+r"(work1));
    pointer5 = pointer4 + work1;
    work2 = previous;
    pointer3 = (u8 *)(work2 + (u32)pointer5);
    current = *pointer3;
    if (current == 0)
        goto activate_current;
    current = work2 << 2;
    pointer1 = D_02020E04;
    pointer0 = (u8 *)(current + (u32)pointer1);
    pointer2 = *(u8 **)pointer0;
    current = *(u32 *)pointer2;
    work1 = 0xFFDFFFFF;
    current &= work1;
    {
        s32 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    current = *pointer3;
    work2 = 0x94;
    current *= work2;
    current += (u32)pointer4;
    current += 0x3C;
    current = *(u8 *)current;
    current <<= 2;
    pointer3 = (u8 *)D_087A43E0;
    current += (u32)pointer3;
    pointer0 = *(u8 **)current;
    work4 = previous;
    work1 = work4 << 17;
    work1 >>= 16;
    func_0807B748(pointer0, 0, 4, 0, work1);
activate_current:
    pointer0 = (u8 *)(cursor + (u32)pointer5);
    current = *pointer0;
    if (current == 0)
        goto check_neighbor;
    active = cursor;
    pointer0 = D_02020E04;
    pointer0 += objectOffset;
    pointer2 = *(u8 **)pointer0;
    current = *(u32 *)pointer2;
    work1 = 0x200000;
    current |= work1;
    {
        s32 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
check_neighbor:
    current = cursor;
    work1 = 3;
    current = func_080C8DC8(current, work1);
    work1 = current;
    current = (u8)work1;
    if (current == 1)
        goto check_above;
    current = cursor - work1;
    current++;
    work3 = (u8)current;
    pointer1 = D_02020E4C;
    work2 = 0x7A6A;
    asm("" : "+r"(work2));
    pointer0 = pointer1 + work2;
    pointer2 = (u8 *)(work3 + (u32)pointer0);
    current = *pointer2;
    pointer5 = pointer1;
    if (current == 0)
        goto normal_status;
    work3 = 0x94;
    current *= work3;
    current += (u32)pointer5;
    current += 0x3C;
    work1 = *(u8 *)current;
    current = 52;
    current *= work1;
    pointer4 = D_0873FCC8;
    pointer0 = (u8 *)(current + (u32)pointer4);
    current = pointer0[2];
    if (current != 4)
        goto normal_status;
    current = 0x3C0;
    flags = current;
    work1 = 1;
    goto status_from_one;
normal_status:
    work2 = 0x200;
    flags = work2;
    work3 = 2;
    asm("" : "+r"(work3));
    status = work3;
    goto update_flags;
check_above:
    current = cursor - 1;
    work3 = (u8)current;
    pointer1 = D_02020E4C;
    work4 = 0x7A6A;
    asm("" : "+r"(work4));
    pointer0 = pointer1 + work4;
    pointer2 = (u8 *)(work3 + (u32)pointer0);
    current = *pointer2;
    pointer5 = pointer1;
    if (current == 0)
        goto check_below;
    work1 = 0x94;
    current *= work1;
    current += (u32)pointer5;
    current += 0x3C;
    work1 = *(u8 *)current;
    current = 52;
    current *= work1;
    pointer2 = D_0873FCC8;
    pointer0 = (u8 *)(current + (u32)pointer2);
    current = pointer0[2];
    if (current == 0)
        goto check_below;
    work3 = 0x200;
    flags = work3;
    work4 = 2;
    asm("" : "+r"(work4));
    status = work4;
    goto update_flags;
check_below:
    current = work3 + 2;
    work3 = (u8)current;
    work1 = 0x7A6A;
    asm("" : "+r"(work1));
    pointer0 = pointer5 + work1;
    pointer1 = (u8 *)(work3 + (u32)pointer0);
    current = *pointer1;
    if (current == 0)
        goto no_status;
    work2 = 0x94;
    current *= work2;
    current += (u32)pointer5;
    current += 0x3C;
    work1 = *(u8 *)current;
    current = 52;
    current *= work1;
    pointer3 = D_0873FCC8;
    pointer0 = (u8 *)(current + (u32)pointer3);
    current = pointer0[2];
    if (current == 0)
        goto no_status;
    work4 = 0x200;
    flags = work4;
    current = 2;
    asm("" : "+r"(current));
    status = current;
    goto update_flags;
no_status:
    work1 = 0;
    flags = work1;
status_from_one:
    status = work1;
update_flags:
    current = 3;
    work2 = flags;
    work2 |= current;
    flags = work2;
    work3 = 0x7A6A;
    asm("" : "+r"(work3));
    asm("" : "+r"(work3));
    pointer0 = pointer5 + work3;
    pointer1 = (u8 *)(cursor + (u32)pointer0);
    current = *pointer1;
    if (current == 0)
        goto empty_status;
    work4 = 0x94;
    current *= work4;
    pointer1 = pointer5;
    pointer1 += 0x3C;
    pointer0 = (u8 *)(current + (u32)pointer1);
    work1 = status;
    work2 = 0;
    func_08090BB0(pointer0, work1, work2);
    goto animation_init;
move_up:
    current = cursor - 1;
    goto move_cursor;
move_down:
    current = cursor + 1;
    goto move_cursor;
move_left:
    current = cursor - 3;
    goto move_cursor;
choose_current:
    work1 = *pointer1;
    selected = work1;
    current = cursor;
    func_080BDEB0(current);
    pointer0 = D_02020E04;
    pointer0 += objectOffset;
    pointer0 = *(u8 **)pointer0;
    func_080771F4(pointer0);
    pointer0 = D_02020E1C;
    pointer0 += objectOffset;
    pointer0 = *(u8 **)pointer0;
    func_080771F4(pointer0);
    func_08090B3C();
    current = selected;
    func_08090EC0(current);
    current = 0;
    work1 = 3;
    work2 = 0xC8;
    goto show_panel;
empty_status:
    current = 0;
    work1 = status;
    work2 = 0;
    func_08090BB0((u8 *)current, work1, work2);
animation_init:
    work1 = active;
    current = work1 << 17;
    work4 = current >> 16;
    pointer2 = D_02020E4C;
    work3 = 0x7A6A;
    asm("" : "+r"(work3));
    asm("" : "+r"(work3));
    records = pointer2 + work3;
    pointer5 = (u8 *)(work1 + (u32)records);
wait_input:
    current = active;
    asm("" : "+r"(current));
    if (current == 255)
        goto read_keys;
    pointer1 = (u8 *)&D_03000084;
    work2 = *(s32 *)pointer1;
    current = 0x3F;
    current &= work2;
    if (current == 0)
        goto stop_animation;
    work3 = previous;
    if (work3 == cursor)
        goto start_animation_check;
    current = 0x20;
    work2 &= current;
    if (work2 != 0)
        goto start_animation_check;
stop_animation:
    {
    u32 pinned;
    asm("" : "=l"(pinned) : "0"(records));
    asm("" : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work3));
    func_0807B748((u8 *)0x080F38B0, 0, 4, 0,
        ({ asm volatile("" : : "r"(current), "r"(work1), "r"(work2), "r"(work3), "r"(pointer5), "r"(cursor), "l"(pinned) : "r11", "r12"); work4; }));
    }
    func_0807A1A4();
    goto read_keys;
start_animation_check:
    work1 = *(s32 *)pointer1;
    current = 0x3F;
    current &= work1;
    if (current == 0x20)
        goto start_animation;
    current = previous;
    if (current == cursor)
        goto read_keys;
    current = 0x20;
    work1 &= current;
    if (work1 == 0)
        goto read_keys;
start_animation:
    current = *pointer5;
    work1 = 0x94;
    current *= work1;
    pointer2 = D_02020E4C;
    current += (u32)pointer2;
    current += 0x3C;
    current = *(u8 *)current;
    current <<= 2;
    pointer3 = (u8 *)D_087A43E0;
    current += (u32)pointer3;
    pointer0 = *(u8 **)current;
    func_0807B748(pointer0, 0, 4, 0, work4);
    func_0807A1A4();
read_keys:
    previous = cursor;
    current = 1;
    func_080C8FCC(current);
    pointer0 = (u8 *)&D_030057EC;
    work1 = *(u16 *)pointer0;
    current = 0x40;
    current &= work1;
    if (current == 0)
        goto down_key;
    current = 0xCC;
    func_08075F20(current);
    current = cursor;
    work1 = 3;
    current = func_080C8DC8(current, work1);
    current <<= 24;
    if (current != 0)
        goto move_up;
    current = cursor + 2;
    goto move_cursor;
down_key:
    current = 0x80;
    current &= work1;
    if (current == 0)
        goto horizontal_key;
    current = 0xCC;
    func_08075F20(current);
    current = cursor;
    work1 = 3;
    current = func_080C8DC8(current, work1);
    current = (u8)current;
    if ((u32)current <= 1)
        goto move_down;
    current = cursor - 2;
    goto move_cursor;
horizontal_key:
    current = 0x30;
    current &= work1;
    if (current == 0)
        goto confirm_key;
    current = 0xCC;
    func_08075F20(current);
    current = cursor;
    work1 = 3;
    current = func_080C8D50(current, work1);
    current <<= 24;
    if (current != 0)
        goto move_left;
    current = cursor + 3;
move_cursor:
    cursor = (u8)current;
    goto next_frame;
confirm_key:
    pointer0 = (u8 *)&D_0300000E;
    work1 = *(u16 *)pointer0;
    current = 1;
    current &= work1;
    if (current == 0)
        goto cancel_key;
    current = 0xCA;
    func_08075F20(current);
    current = selected;
    if (current != 0)
        goto place_selected;
    pointer1 = (u8 *)(cursor + (u32)records);
    current = *pointer1;
    if (current != 0)
        goto choose_current;
    current = 7;
    work1 = flags;
    func_0808AC1C(current, work1);
    current = 0;
    work1 = 3;
    work2 = 0xC8;
    work3 = 0x98;
    func_0808A7F8(current, work1, work2, work3);
    current = 1;
    work1 = 0x10;
    work2 = 0x90;
    work3 = 0x98;
    func_0808A7F8(current, work1, work2, work3);
    pointer1 = D_02030B6C;
    asm("" : "+r"(pointer1));
    available = pointer1;
    stride = 0x94;
    pointer2 = D_02020E88;
    asm("" : "+r"(pointer2));
    units = pointer2;
choose_loop:
    current = chosen;
    current += (u32)available;
    current = *(u8 *)current;
    current *= stride;
    pointer0 = (u8 *)(current + (u32)units);
    work1 = status;
    work2 = 0;
    func_08090BB0(pointer0, work1, work2);
    current = 0x0800375E;
    func_0807C290(current);
    pointer0 = &D_0200C4A0;
    current = *pointer0;
    chosen = current;
    pointer0 = &D_0200C4A2;
    work4 = *pointer0;
    if (work4 != 1)
        goto choose_result;
    work5 = chosen;
    pointer5 = (u8 *)(work5 + (u32)available);
    current = *pointer5;
    current *= stride;
    pointer0 = (u8 *)(current + (u32)units);
    work1 = status;
    work2 = cursor;
    work3 = 0;
    current = func_08090F8C(pointer0, work1, work2, work3);
    if (current == 0)
        goto choose_retry;
    work1 = *pointer5;
    current = work1;
    current *= stride;
    pointer3 = D_02020E4C;
    current += (u32)pointer3;
    current += 0x40;
    current = *(u16 *)current;
    work4 &= current;
    if (work4 == 0)
        goto place_chosen;
    work4 = 0;
    pointer2 = D_020288B6;
    current = *pointer2;
    if (current == work1)
        goto remove_chosen;
    pointer0 = D_02030B6C;
    work3 = chosen;
    pointer1 = (u8 *)(work3 + (u32)pointer0);
find_chosen:
    current = work4 + 1;
    work4 = (u8)current;
    if ((u32)work4 > 5)
        goto remove_chosen;
    pointer0 = (u8 *)(work4 + (u32)pointer2);
    current = *pointer0;
    work3 = *pointer1;
    asm("" : "+r"(work3));
    if (current != work3)
        goto find_chosen;
remove_chosen:
    work4 <<= 2;
    pointer1 = D_02020E04;
    pointer0 = (u8 *)(work4 + (u32)pointer1);
    pointer0 = *(u8 **)pointer0;
    func_080771F4(pointer0);
    pointer2 = D_02020E1C;
    pointer4 = (u8 *)(work4 + (u32)pointer2);
    pointer0 = *(u8 **)pointer4;
    func_080771F4(pointer0);
place_chosen:
    current = 0xDD;
    func_08075F20(current);
    current = chosen;
    current += (u32)available;
    current = *(u8 *)current;
    work1 = cursor;
    func_080BDE24(current, work1);
    current = cursor;
    func_08090D98(current);
    goto choose_done;
choose_result:
    if (work4 == 2)
        goto choose_done;
choose_retry:
    pointer0 = (u8 *)&D_0200C4A4;
    work1 = *(u16 *)pointer0;
    current = 8;
    current &= work1;
    if (current == 0)
        goto choose_loop;
    current = 7;
    work1 = 0;
    work2 = flags;
    current = func_0808B2F8(current, work1, work2);
    if (current == 0)
        goto choose_loop;
    work3 = 0;
    chosen = work3;
    goto choose_loop;
choose_done:
    func_08090B3C();
    current = 0;
    work1 = 1;
    work2 = 0xD8;
    work3 = 0x98;
    func_0808A7F8(current, work1, work2, work3);
    current = 1;
    func_0808A86C(current);
    goto next_frame;
place_selected:
    work1 = selected;
    work2 = 0x94;
    current = work1;
    current *= work2;
    pointer1 = D_02020E88;
    pointer0 = (u8 *)(current + (u32)pointer1);
    work1 = status;
    work2 = cursor;
    work3 = 0;
    current = func_08090F8C(pointer0, work1, work2, work3);
    if (current == 0)
        goto wait_input;
    current = 0xDD;
    func_08075F20(current);
    pointer4 = (u8 *)(cursor + (u32)records);
    current = *pointer4;
    if (current == 0)
        goto finish_placement;
    pointer0 = D_02020E04;
    pointer0 += objectOffset;
    pointer0 = *(u8 **)pointer0;
    func_080771F4(pointer0);
    pointer0 = D_02020E1C;
    pointer0 += objectOffset;
    pointer0 = *(u8 **)pointer0;
    func_080771F4(pointer0);
finish_placement:
    work4 = *pointer4;
    current = selected;
    work1 = cursor;
    func_080BDE24(current, work1);
    current = cursor;
    func_08090D98(current);
    func_08090B3C();
    selected = work4;
    current = work4;
    func_08090EC0(current);
    current = 0;
    work1 = 1;
    work2 = 0xD8;
show_panel:
    work3 = 0x98;
    func_0808A7F8(current, work1, work2, work3);
    goto next_frame;
cancel_key:
    current = 2;
    current &= work1;
    if (current == 0)
        goto wait_input;
    current = 0xCB;
    func_08075F20(current);
    work3 = selected;
    if (work3 != 0)
        goto cancel_selected;
    work4 = 0;
    {
        u8 *address;
        asm("" : "=r"(work1), "=r"(work2), "=r"(work3), "=r"(pointer5));
        asm("" : "=l"(address) : "0"(records));
        current = *address;
        asm volatile("" : : "l"(address), "r"(work1), "r"(work2), "r"(work3), "r"(pointer5));
    }
    pointer5 = D_02020E4C;
    if (current != 0)
        goto exit_check;
    current = 0x7A6A;
    pointer1 = pointer5 + current;
find_existing:
    current = work4 + 1;
    work4 = (u8)current;
    if ((u32)work4 > 5)
        goto exit_menu;
    pointer0 = (u8 *)(work4 + (u32)pointer1);
    current = *pointer0;
    if (current == 0)
        goto find_existing;
exit_check:
    if ((u32)work4 <= 5)
        goto done;
exit_menu:
    current = 0;
    func_0808A890(current);
    current = 0x08003919;
    func_0807C290(current);
    current = 0;
    func_0808A8B4(current);
    goto next_frame;
cancel_selected:
    work1 = 0;
    selected = work1;
    current = 0;
    func_08090EC0(current);
    work2 = active;
    if (work2 == 255)
        goto restore_panel;
    current = work2 << 2;
    pointer3 = D_02020E04;
    pointer0 = (u8 *)(current + (u32)pointer3);
    pointer2 = *(u8 **)pointer0;
    current = *(u32 *)pointer2;
    work1 = 0xFFDFFFFF;
    current &= work1;
    {
        s32 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    current = *pointer5;
    work1 = 0x94;
    current *= work1;
    pointer2 = D_02020E4C;
    current += (u32)pointer2;
    current += 0x3C;
    current = *(u8 *)current;
    current <<= 2;
    pointer3 = (u8 *)D_087A43E0;
    current += (u32)pointer3;
    pointer0 = *(u8 **)current;
    func_0807B748(pointer0, 0, 4, 0, work4);
    func_0807A1A4();
restore_panel:
    current = 0;
    work1 = 1;
    work2 = 0xD8;
    work3 = 0x98;
    func_0808A7F8(current, work1, work2, work3);
next_frame:
    work4 = 0;
    asm("" : "+r"(work4));
    if (work4 != 0)
        goto done;
    goto frame;
done:
    return;
}
