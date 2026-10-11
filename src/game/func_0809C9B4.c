#include "types.h"

extern u8 D_02031A0C[];
extern u8 D_02033C38[];
extern u8 D_020369E0[];
extern u8 D_02030AE8;
extern u32 D_03000010;
extern u32 D_02031C5C;
u8 *func_0809A908(u32, u32);
u32 func_080BFADC(u32, u32);
u32 func_080C0EB8(u32, u32, u32, u32);
u32 func_080C8BAC(u32);

void func_0809C9B4(void)
{
    u8 choices[4];
    volatile u32 side;
    u8 *volatile unit;
    volatile u32 slot;
    volatile u32 recordOffset;
    volatile u32 nextGroup;
    volatile u32 nextSide;
    volatile u32 nextPart;
    register u32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 group asm("r3");
    register u32 work4 asm("r4");
    register u32 work5 asm("r5");
    register s32 chance asm("r4");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer4 asm("r4");
    register u32 part asm("r8");
    register u32 sideOffset asm("r9");
    register u32 groupOffset asm("r10");
    u8 *flags;
    u8 *record;
    u32 *randomState;
    u8 choiceCount;
    u8 choiceIndex;

    group = 0;
    pointer2 = D_02031A0C;
    work5 = 0x244;
    asm("" : "+r"(work5));
    pointer0 = pointer2 + work5;
    current = *pointer0;
    current <<= 2;
    goto check_group;
group_loop:
    pointer1 = D_02031A0C;
    pointer0 = pointer1 + work5;
    current = *pointer0;
    current <<= 2;
    current = group + current;
    pointer1 += work4;
    current += (u32)pointer1;
    current = *(u8 *)current;
    work2 = 7;
    work1 = 7;
    asm("" : "+r"(work2), "+r"(work1));
    work1 &= current;
    current >>= 3;
    current &= work2;
    slot = current;
    current = work1 * 0x270;
    pointer2 = D_02033C38;
    asm("" : "+r"(pointer2));
    current += (u32)pointer2;
    unit = (u8 *)current;
    current = 0;
    side = current;
    current = group << 1;
    work1 = group + 1;
    nextGroup = work1;
    current += group;
    current <<= 2;
    groupOffset = current;
side_loop:
    work2 = 0;
    asm("" : "+r"(work2));
    part = work2;
    current = side;
    work1 = current << 1;
    current++;
    nextSide = current;
    work2 = side;
    work1 += work2;
    current = work1 << 4;
    current += 4;
    recordOffset = current;
    work1 <<= 1;
    sideOffset = work1;
part_loop:
    current = part;
    current += sideOffset;
    current += groupOffset;
    pointer1 = D_020369E0;
    asm("" : "+r"(pointer1));
    flags = (u8 *)(current + (u32)pointer1);
    current = 0;
    *flags = current;
    work2 = slot;
    work1 = 100;
    current = work2;
    current *= work1;
    current += 0x18;
    pointer2 = unit;
    current = (u32)pointer2 + current;
    work1 = recordOffset;
    current += work1;
    work2 = part;
    work1 = work2 << 3;
    record = (u8 *)(current + work1);
    current = *record;
    work2++;
    nextPart = work2;
    if (current == 0)
        goto advance_part;
    pointer0 = unit;
    work1 = *pointer0;
    current = 1;
    current &= work1;
    if (current != 0)
        goto guaranteed;
    pointer0 = &D_02030AE8;
    current = *pointer0;
    if (current != 0)
        goto guaranteed;
    chance = *(s16 *)(record + 2);
    asm volatile("" : "+r"(current));
    randomState = &D_03000010;
    current = func_080C8BAC(*randomState);
    work2 = 100;
    asm("" : "+r"(work2));
    current *= work2;
    current >>= 15;
    if (chance <= (s32)current)
        goto check_chance;
    work1 = *flags;
    current = 0x10;
    work1 |= current;
    *flags = work1;
    chance = *(s16 *)(record + 4);
    current = func_080C8BAC(*randomState);
    work1 = 100;
    asm("" : "+r"(work1));
    current *= work1;
    current >>= 15;
    if (chance > (s32)current) {
        work1 = *flags;
        current = 0x20;
        work1 |= current;
        *flags = work1;
    }
    pointer2 = unit;
    work1 = pointer2[1];
    current = 8;
    current &= work1;
    if (current == 0)
        goto check_chance;
    pointer1 = (u8 *)&D_02031C5C;
    current = *(u32 *)pointer1;
    chance = func_080BFADC(current, 0x17);
    asm("" : "+r"(chance));
    chance = (s16)chance;
    current = func_080C8BAC(*randomState);
    work2 = 100;
    asm("" : "+r"(work2));
    current *= work2;
    current >>= 15;
    if (chance <= (s32)current)
        goto check_chance;
    choiceCount = 0;
    choiceIndex = 0;
choice_loop:
    pointer0 = func_0809A908(side, part);
    work1 = choiceIndex << 2;
    pointer0 += work1;
    pointer0 += 0x76;
    current = *(u16 *)pointer0;
    if (current != 0) {
        u8 *address;
        pointer1 = choices;
        pointer0 = pointer1 + choiceCount;
        asm("" : "=r"(address) : "0"(pointer0));
        *address = choiceIndex;
        choiceCount++;
    }
    choiceIndex++;
    if (choiceIndex <= 3)
        goto choice_loop;
    if (choiceCount == 0)
        goto check_chance;
    work4 = part;
    work4 += sideOffset;
    work4 += groupOffset;
    pointer2 = D_020369E0;
    asm("" : "+r"(pointer2));
    work4 += (u32)pointer2;
    pointer4 = (u8 *)work4;
    work1 = *pointer4;
    current = 0x40;
    work1 |= current;
    *pointer4 = work1;
    current = func_080C8BAC(D_03000010);
    current *= choiceCount;
    current >>= 15;
    current = choices[current];
    current <<= 2;
    work1 = *pointer4;
    current |= work1;
    *pointer4 = current;
check_chance:
    pointer1 = D_02031A0C;
    work2 = 0x244;
    asm("" : "+r"(work2));
    pointer0 = pointer1 + work2;
    current = *pointer0;
    work2++;
    pointer1 += work2;
    work1 = *pointer1;
    chance = func_080C0EB8(current, work1, side, part);
    asm("" : "+r"(chance));
    chance = (u8)chance;
    current = func_080C8BAC(D_03000010);
    work1 = 100;
    asm("" : "+r"(work1));
    current *= work1;
    current >>= 15;
    if (chance <= (s32)current) {
        pointer2 = (u8 *)part;
        pointer2 += sideOffset;
        pointer2 += groupOffset;
        pointer0 = D_020369E0;
        asm("" : "+r"(pointer0));
        pointer2 += (u32)pointer0;
        work1 = *pointer2;
        current = 0x80;
        work1 |= current;
        *pointer2 = work1;
    }
    goto random_flags;
guaranteed:
    pointer2 = (u8 *)part;
    pointer2 += sideOffset;
    pointer2 += groupOffset;
    pointer1 = D_020369E0;
    asm("" : "+r"(pointer1));
    pointer2 += (u32)pointer1;
    work1 = *pointer2;
    current = 0x10;
    work1 |= current;
    *pointer2 = work1;
    work2 = part;
    work2++;
    nextPart = work2;
random_flags:
    current = func_080C8BAC(D_03000010);
    pointer2 = (u8 *)part;
    pointer2 += sideOffset;
    pointer2 += groupOffset;
    pointer1 = D_020369E0;
    asm("" : "+r"(pointer1));
    pointer2 += (u32)pointer1;
    work1 = (current << 1) + current;
    work1 >>= 15;
    current = *pointer2;
    work1 |= current;
    *pointer2 = work1;
advance_part:
    work2 = nextPart;
    current = (u8)work2;
    part = current;
    if (current <= 5)
        goto part_loop;
    work1 = nextSide;
    current = (u8)work1;
    side = current;
    if (current <= 1)
        goto side_loop;
    work2 = nextGroup;
    current = work2 << 24;
    asm("" : "+r"(current));
    group = current >> 24;
    if (group > 2)
        return;
    pointer2 = D_02031A0C;
    work5 = 0x244;
    asm("" : "+r"(work5));
    pointer0 = pointer2 + work5;
    current = *pointer0;
    current <<= 2;
    current = group + current;
check_group:
    work4 = 0x4F85;
    asm("" : "+r"(work4));
    pointer1 = pointer2 + work4;
    current += (u32)pointer1;
    current = *(u8 *)current;
    if (current != 0xFF)
        goto group_loop;
}
