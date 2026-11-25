#include "types.h"

struct Part {
    u8 pad[2];
    u8 level;
};
struct Zoid {
    u8 pad[4];
    u16 flags;
};
struct Unit {
    u8 zoid;
    u8 parts[7];
    u8 pad[0x100];
};
struct Game {
    u8 pad[0x258];
    struct Unit units[2][7];
};
extern struct Game D_02031A0C;
extern u8 D_02031C65[];
struct Part *func_0809A954(u32, u32, u32);
struct Zoid *func_0809A908(u32, u32);
s32 func_080C8BE8(s32, s32);
s32 func_080C0E64(s32);
s32 func_080BFADC(struct Part *, u8);
s32 func_080BD2F4(s32, s32);

u8 func_080C0EB8(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    /* Empty asm constraints preserve register lifetimes without emitting instructions. */
    register u32 firstSide asm("r10") = (u8)arg0;
    register u32 firstSlot asm("r9") = (u8)arg1;
    volatile u32 secondSide = (u8)arg2;
    volatile u32 secondSlot = (u8)arg3;
    volatile u32 savedFirstOffset;
    volatile u32 savedSideEight;
    volatile u32 savedSlotThirtyTwo;
    register s32 secondSum asm("r6") = 0;
    register s32 firstSum asm("r5") = 0;
    register u32 count asm("r8");
    u8 index;
    register s32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 slotOffset asm("r3");
    register u32 factor asm("r4");
    register u8 *base asm("r1");
    register u32 baseOffset asm("r4");
    register u32 firstFactor asm("r4");
    register s32 firstAverage asm("r5");
    register u32 secondOffset asm("r9");
    register u8 *secondBase asm("r10");
    register u32 combined asm("r12");
    register u8 *base4 asm("r4");
    register s32 chance asm("r4");
    register u32 modifier asm("r5");
    register u32 thirdFactor asm("r6");
    register u32 thirdOffset asm("r8");
    register u8 *thirdBase asm("r9");

    asm("" : "+r"(firstSum));
    count = firstSum;
    index = 0;
    base = (u8 *)&D_02031A0C;
    asm("" : "+r"(base));
    work2 = firstSlot;
    asm("" : "+r"(work2));
    current = work2 << 5;
    current += firstSlot;
    slotOffset = current << 3;
    factor = firstSide;
    asm("" : "+r"(factor));
    current = factor << 3;
    work2 = current - factor;
    current = (work2 + (work2 << 5)) << 3;
    current = slotOffset + current;
    baseOffset = 0x259;
    asm("" : "+r"(baseOffset));
    base += baseOffset;
    current = *(u8 *)(current + (u32)base);
    if (current != 0xFF) {
        savedFirstOffset = slotOffset;
        firstFactor = work2;
        asm("" : "+r"(firstFactor));
first_loop:
        current = func_0809A954(firstSide, firstSlot, index)->level;
        current = firstSum + current;
        asm("" : "+r"(current));
        firstSum = current;
        count = (u8)(count + 1);
        index = (u8)(index + 1);
        if (index <= 3) {
            work1 = savedFirstOffset;
            current = index + work1;
            work1 = (firstFactor + (firstFactor << 5)) << 3;
            current += work1;
            work2 = (u32)D_02031C65;
            current = *(u8 *)(current + work2);
            if (current != 0xFF)
                goto first_loop;
        }
    }
    firstAverage = func_080C8BE8(firstSum, count);
    slotOffset = 0;
    asm("" : "+r"(slotOffset));
    count = slotOffset;
    index = 0;
    base4 = (u8 *)&D_02031A0C;
    asm("" : "+r"(base4));
    secondBase = base4;
    current = secondSlot;
    slotOffset = current << 5;
    current = (slotOffset + current) << 3;
    secondOffset = current;
    work1 = secondSide;
    work2 = work1 << 3;
    current = work2 - work1;
    work1 = current << 5;
    current = current + work1;
    work1 = current << 3;
    factor = secondOffset;
    asm("" : "+r"(factor));
    factor += work1;
    asm("" : "+r"(factor));
    combined = factor;
    asm("" : "+r"(combined));
    base4 = (u8 *)0x259;
    base4 += (u32)secondBase;
    current = combined;
    asm("" : "+r"(current));
    current += (u32)base4;
    asm("" : "+r"(current));
    current = *(u8 *)current;
    savedSlotThirtyTwo = slotOffset;
    savedSideEight = work2;
    if (current != 0xFF) {
        secondBase = base4;
        firstFactor = work1;
second_loop:
        current = secondSide;
        work1 = secondSlot;
        current = func_0809A954(current, work1, index)->level;
        current = secondSum + current;
        asm("" : "+r"(current));
        secondSum = current;
        count = (u8)(count + 1);
        index = (u8)(index + 1);
        if (index <= 3) {
            work1 = secondOffset;
            current = index + work1;
            current += firstFactor;
            current += (u32)secondBase;
            current = *(u8 *)current;
            if (current != 0xFF)
                goto second_loop;
        }
    }
    secondSum = func_080C8BE8(secondSum, count);
    asm("" : "+r"(secondSum));
    secondSum -= firstAverage;
    chance = func_080C0E64(secondSum * 0x533) + 50;
    if (chance <= 0)
        chance = 1;
    else if (chance > 99)
        chance = 99;
    modifier = 0;
    index = 0;
    base = (u8 *)&D_02031A0C;
    asm("" : "+r"(base));
    work2 = savedSlotThirtyTwo;
    slotOffset = secondSlot;
    current = work2 + slotOffset;
    slotOffset = current << 3;
    thirdFactor = savedSideEight;
    current = secondSide;
    work2 = thirdFactor - current;
    current = (work2 + (work2 << 5)) << 3;
    current = slotOffset + current;
    thirdFactor = 0x259;
    asm("" : "+r"(thirdFactor));
    base += thirdFactor;
    current = *(u8 *)(current + (u32)base);
    if (current != 0xFF) {
        thirdFactor = work2;
        thirdBase = base;
        thirdOffset = slotOffset;
third_loop:
        current = secondSide;
        work1 = secondSlot;
        current = func_080BFADC(func_0809A954(current, work1, index), 0x19);
        work1 = (s16)modifier;
        work1 += current;
        modifier = (u16)work1;
        current = secondSide;
        work1 = secondSlot;
        current = func_080BFADC(func_0809A954(current, work1, index), 0x34);
        work1 = (s16)modifier;
        work1 -= current;
        modifier = (u16)work1;
        index = (u8)(index + 1);
        if (index <= 3) {
            work1 = thirdOffset;
            current = index + work1;
            work1 = (thirdFactor + (thirdFactor << 5)) << 3;
            current += work1;
            current += (u32)thirdBase;
            current = *(u8 *)current;
            if (current != 0xFF)
                goto third_loop;
        }
    }
    chance -= func_080BD2F4(100 - chance, (s16)modifier);
    current = secondSide;
    work1 = secondSlot;
    if (func_0809A908(current, work1)->flags & 0x10)
        chance = func_080C8BE8(chance, 10);
    if (chance <= 0)
        chance = 1;
    else if (chance > 99)
        chance = 99;
    return chance;
}
