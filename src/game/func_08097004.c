#include "types.h"

extern u8 D_02031A0C[];
extern u8 D_02036985;
extern u16 D_0300000C;
void func_080969F0(void);
void func_08096C8C(void);
void func_080969A8(void *, ...);
void func_08079544(u32, u32);
void func_0807970C(void);
void func_08075E28(u32);
void func_080A1204(void);
u8 *func_0809A908(u32, u32);
u32 func_0809A954(u32, u32, u32);
void func_08093140(u32, u8 *, u32, u32);
void func_080A290C(u32, u32);
u32 func_0809CC6C(u32, u32, u32);
void func_0809D624(void);
void func_080C8FCC(u32);

void func_08097004(void)
{
    u8 list[24];
    volatile u32 count;
    volatile u32 selectedSide;
    volatile u32 nextGroup;
    register u32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 work3 asm("r3");
    register u32 work4 asm("r4");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *pointer6 asm("r6");
    register u32 unitOffset asm("r10");
    register u32 slotOffset asm("r9");
    register u32 nextSide asm("r8");
    register u32 sideOffset asm("r12");
    register u8 *member asm("r8");
    register u32 nextEntry asm("r10");
    register u8 *result asm("r9");
    register u32 index asm("r4");
    u32 entry;
    register u32 side asm("r6");
    register u32 slot asm("r5");
    u8 *second;
    u8 *team;
    u8 *unit;
    register u32 firstSide asm("r4");
    register u32 shown asm("r5");
    u8 *game;

    current = 0;
    count = current;
    pointer0 = D_02031A0C;
    work1 = 0x244;
    asm("" : "+r"(work1));
    pointer3 = pointer0 + work1;
    work1 = *pointer3;
    work1 <<= 2;
    work4 = 0x4F85;
    asm("" : "+r"(work4));
    pointer2 = pointer0 + work4;
    pointer1 = (u8 *)(work1 + (u32)pointer2);
    current = *pointer1;
    work4 = (u32)func_080969F0;
    asm("" : "+r"(work4));
    if (current != 0xFF) {
        pointer1 = pointer2;
count_loop:
        current = count;
        current++;
        current = (u8)current;
        count = current;
        if (current <= 2) {
            current = *pointer3;
            current <<= 2;
            work2 = count;
            current = work2 + current;
            current += (u32)pointer1;
            current = *(u8 *)current;
            if (current != 0xFF)
                goto count_loop;
        }
    }
    func_080969A8((void *)work4, 0);
    func_08079544(18, 0);
    func_0807970C();
    func_08075E28(4);
    func_080A1204();
    pointer2 = D_02031A0C;
    work3 = 0x244;
    asm("" : "+r"(work3));
    pointer0 = pointer2 + work3;
    current = *pointer0;
    current <<= 2;
    current += (u32)pointer2;
    work4 = 0x4F85;
    asm("" : "+r"(work4));
    current += work4;
    current = *(u8 *)current;
    work1 = 7;
    work1 &= current;
    current = work1 * 0x270;
    current += (u32)pointer2;
    work1 = 0x222C;
    asm("" : "+r"(work1));
    current += work1;
    work1 = *(u8 *)current;
    current = 1;
    current &= work1;
    if (current != 0)
        goto disabled;
    index = 0;
    work2 = 0xFF;
clear_loop:
    current = index << 1;
    pointer3 = list;
    pointer1 = (u8 *)((u32)pointer3 + current);
    current = *pointer1;
    current |= work2;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = current;
    }
    current = index + 1;
    asm("" : "+r"(current));
    index = (u8)current;
    if (index <= 11)
        goto clear_loop;
    index = 0;
    current = count;
    if (index >= current)
        goto process_list;
    second = list + 1;
    pointer1 = D_02031A0C;
    work2 = 0x244;
    asm("" : "+r"(work2));
    pointer0 = pointer1 + work2;
    current = *pointer0;
    current <<= 2;
    selectedSide = current;
group_loop:
    work3 = selectedSide;
    current = index + work3;
    pointer2 = D_02031A0C;
    work3 = 0x4F85;
    asm("" : "+r"(work3));
    pointer1 = pointer2 + work3;
    current += (u32)pointer1;
    work2 = *(u8 *)current;
    work1 = 7;
    work1 &= work2;
    work2 >>= 3;
    current = 7;
    work2 &= current;
    side = 0;
    index++;
    nextGroup = index;
    current = work1 * 0x270;
    unitOffset = current;
    work3 = 100;
    work1 = work2;
    asm("" : "+r"(work1));
    work1 *= work3;
    asm("" : "+r"(work1));
    slotOffset = work1;
side_loop:
    slot = 0;
    current = side << 1;
    work4 = side + 1;
    asm("" : "+r"(work4));
    nextSide = work4;
    current += side;
    current <<= 4;
    sideOffset = current;
slot_loop:
    current = slot << 3;
    current += sideOffset;
    current += slotOffset;
    current += unitOffset;
    pointer1 = D_02031A0C;
    asm("" : "+r"(pointer1));
    current += (u32)pointer1;
    work2 = 0x2248;
    asm("" : "+r"(work2));
    current += work2;
    current = *(u8 *)current;
    work2 = slot + 1;
    if (current == 0)
        goto advance_slot;
    index = 0;
    pointer0 = list;
    current = *pointer0;
    if (current == side) {
        current = *second;
        if (current == slot)
            goto advance_slot;
    }
find_slot:
    work3 = index << 1;
    pointer0 = list;
    pointer1 = (u8 *)((u32)pointer0 + work3);
    current = *pointer1;
    if (current == 0xFF) {
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = side;
        }
        pointer0 = second + work3;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = slot;
        }
        goto advance_slot;
    }
    current = index + 1;
    asm("" : "+r"(current));
    index = (u8)current;
    if (index > 11)
        goto advance_slot;
    work1 = index << 1;
    pointer3 = list;
    pointer0 = (u8 *)((u32)pointer3 + work1);
    current = *pointer0;
    if (current != side)
        goto find_slot;
    pointer0 = second + work1;
    current = *pointer0;
    if (current != slot)
        goto find_slot;
advance_slot:
    current = work2 << 24;
    asm("" : "+r"(current));
    slot = current >> 24;
    if (slot <= 5)
        goto slot_loop;
    work4 = nextSide;
    asm("" : "+r"(work4));
    current = work4 << 24;
    asm("" : "+r"(current));
    side = current >> 24;
    if (side <= 1)
        goto side_loop;
    work1 = nextGroup;
    current = work1 << 24;
    asm("" : "+r"(current));
    index = current >> 24;
    work2 = count;
    if (index < work2)
        goto group_loop;
process_list:
    entry = 0;
    pointer0 = list;
    current = *pointer0;
    if (current == 0xFF)
        return;
    pointer6 = &D_02036985;
    asm("" : "=r"(team) : "0"(pointer6));
    pointer3 = team + 1;
    asm("" : "+r"(pointer3));
    member = pointer3;
process_loop:
    asm("" : "+r"(entry));
    work1 = entry << 1;
    pointer4 = list;
    asm("" : "+r"(pointer4));
    pointer0 = pointer4 + work1;
    current = *pointer0;
    *team = current;
    pointer0 = list;
    pointer0++;
    asm("" : "+r"(pointer0));
    pointer0 += work1;
    current = *pointer0;
    pointer1 = member;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = current;
        firstSide = *team;
        work1 = *address;
    }
    current = firstSide;
    unit = func_0809A908(current, work1);
    current = *team;
    pointer2 = member;
    work1 = *pointer2;
    work2 = func_0809A954(current, work1, 0);
    func_08093140(firstSide, unit, work2, 1);
    current = *team;
    pointer3 = member;
    work1 = *pointer3;
    func_080A290C(current, work1);
    current = *team;
    if (current == 0)
        func_08079544(9, 0);
    else
        func_08079544(10, 0);
    func_0807970C();
    shown = 0;
    firstSide = 0;
    entry++;
    nextEntry = entry;
    current = count;
    if (shown >= current)
        goto checked_groups;
    game = D_02031A0C;
    pointer1 = (u8 *)0x4F77;
    asm("" : "+r"(pointer1));
    pointer1 += (u32)game;
    asm("" : "+r"(pointer1));
    result = pointer1;
check_loop:
    work1 = *team;
    pointer3 = member;
    work2 = *pointer3;
    current = firstSide;
    current = func_0809CC6C(current, work1, work2);
    work1 = (u8)current;
    if (work1 != 0) {
        if (shown == 0) {
            work2 = 0x4F78;
            asm("" : "+r"(work2));
            pointer0 = game + work2;
            {
                u8 *address;
                asm("" : "=r"(address) : "0"(pointer0));
                *address = firstSide;
            }
            func_080969A8(func_08096C8C, work1);
            pointer3 = result;
            current = *pointer3;
            if (current == 0)
                shown = 1;
        }
        current = *team;
        pointer2 = member;
        work1 = *pointer2;
        pointer0 = func_0809A908(current, work1);
        asm("" : "+r"(work1), "+r"(work2));
        current = *(s16 *)(pointer0 + 6);
        asm volatile("" : : "r"(work1), "r"(work2));
        if ((s32)current <= 0)
            goto checked_groups;
    }
    current = firstSide + 1;
    asm("" : "+r"(current));
    firstSide = (u8)current;
    current = count;
    if (firstSide < current)
        goto check_loop;
checked_groups:
    if (shown == 0) {
        firstSide = 0;
        goto check_wait;
wait_loop:
        func_080C8FCC(1);
        current = firstSide + 1;
        asm("" : "+r"(current));
        firstSide = (u8)current;
        if (firstSide > 29)
            goto waited;
check_wait:
        pointer0 = (u8 *)&D_0300000C;
        work1 = *(u16 *)pointer0;
        current = 2;
        current &= work1;
        if (current == 0)
            goto wait_loop;
    }
waited:
    func_08079544(18, 0);
    func_0807970C();
    func_08075E28(4);
    func_080A1204();
    work1 = nextEntry;
    asm("" : "+r"(work1));
    current = work1 << 24;
    asm("" : "+r"(current));
    entry = current >> 24;
    if (entry <= 11) {
        current = entry << 1;
        pointer0 = list + current;
        asm("" : "+r"(pointer0));
        current = *pointer0;
        if (current != 0xFF)
            goto process_loop;
    }
    return;
disabled:
    func_0809D624();
}
