#include "types.h"

extern u8 D_08734B64[];
extern u16 D_0300000C;
extern u16 D_0300000E;
extern u8 D_020209D8[];
extern u8 D_02020E4C[];
u32 func_080C8B74(s32, s32);
void func_08077204(u32, u32);
void func_08075F20(u32);
void func_08081B60(u8 *, u8 *);

void func_080810D0(u8 *arg0)
{
    register u8 *input asm("r5") = arg0;
    u8 *entity;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *record asm("r4");
    register s32 limit asm("r4");
    register u8 *base asm("r10");
    register u16 *keys asm("r9");
    register u32 one asm("r9");
    register u32 contact asm("r8");
    register u8 *owned asm("r8");
    register u32 two asm("r4");
    register u32 slot asm("r6");
    u32 shifted;
    register u32 baseCopy asm("r7");
    register u32 bit asm("r7");
    register u8 *bitIndex asm("r6");

    asm("" : "=r"(entity) : "0"(input));
    work1 = entity[0];
    two = 2;
    asm("" : "+r"(two));
    current = two;
    asm("" : "+r"(current));
    current &= work1;
    asm("" : "+r"(current));
    work3 = (u8)current;
    if (work3 != 0) {
        entity[0x14] = 0;
        return;
    }
    pointer1 = D_08734B64;
    pointer0 = (u8 *)&D_0300000C;
    work2 = *(u16 *)pointer0;
    current = 0xF0;
    current &= work2;
    current = (u32)current >> 4;
    current += (u32)pointer1;
    current = *(u8 *)current;
    if (current != 0xFF) {
        entity[0x16] = current;
        current = two;
        asm("" : "+r"(current));
        current &= work2;
        if (current == 0) {
            current = 2;
            entity[0x14] = current;
        } else {
            current = 3;
            entity[0x14] = current;
        }
    } else {
        entity[0x14] = work3;
    }
    pointer2 = (u8 *)&D_0300000E;
    work1 = *(u16 *)pointer2;
    current = 3;
    current &= work1;
    keys = (u16 *)pointer2;
    if (current == 0)
        return;
    current = 0;
    contact = current;
    slot = 0;
    pointer1 = D_020209D8;
    asm("" : "+r"(pointer1));
    base = pointer1;
scan:
    work2 = (u32)slot << 4;
    current = work2 + slot;
    work3 = current << 2;
    baseCopy = (u32)base;
    asm("" : "=r"(shifted) : "0"(baseCopy));
    record = (u8 *)(work3 + shifted);
    pointer0 = record + 0x6C;
    work1 = *pointer0;
    current = 1;
    current &= work1;
    shifted = work2;
    if (current == 0)
        goto no_contact;
    pointer0 = base + 0x6C;
    pointer0 = (u8 *)(work3 + (u32)pointer0);
    if (entity == pointer0)
        goto no_contact;
    pointer0 = record + 0x6E;
    current = *pointer0;
    if (current == 0xD)
        goto no_contact;
    pointer0 = base + 0x70;
    pointer0 = (u8 *)(work3 + (u32)pointer0);
    work1 = *(s32 *)pointer0;
    current = *(s32 *)(entity + 4);
    work2 = work1 - current;
    pointer0 = base + 0x74;
    pointer0 = (u8 *)(work3 + (u32)pointer0);
    work1 = *(s32 *)pointer0;
    current = *(s32 *)(entity + 8);
    work3 = work1 - current;
    current = entity[0x16];
    switch (current) {
    case 0:
        current = 0x800;
        work1 = work2 + current;
        current = 0x1000;
        if ((u32)work1 > (u32)current)
            goto no_contact;
        current = -0x1800;
        if (work3 < current || work3 > 0)
            goto no_contact;
        goto interact;
    case 2:
        current = 0x1800;
        if ((u32)work2 > (u32)current)
            goto no_contact;
        current = -0x800;
        if (work3 < current)
            goto no_contact;
        current = 0x800;
        if (work3 > current)
            goto no_contact;
        goto interact;
    case 4:
        current = 0x800;
        work1 = work2 + current;
        current = 0x1000;
        if ((u32)work1 > (u32)current || work3 < 0)
            goto no_contact;
        current = 0x1800;
        if (work3 > current)
            goto no_contact;
        goto interact;
    case 6:
        work1 = 0x1800;
        current = work2 + work1;
        if ((u32)current > (u32)work1)
            goto no_contact;
        current = -0x800;
        if (work3 < current)
            goto no_contact;
        current = 0x800;
        if (work3 > current)
            goto no_contact;
        goto interact;
    case 1:
        limit = 0x800;
        work1 = work2 + limit;
        current = 0x2000;
        if ((u32)work1 > (u32)current)
            goto no_contact;
        current = -0x1800;
        if (work3 < current || work3 > limit)
            goto no_contact;
        goto interact;
    case 3:
        current = 0x800;
        work1 = work2 + current;
        current = 0x2000;
        if ((u32)work1 > (u32)current)
            goto no_contact;
        current = -0x800;
        if (work3 < current)
            goto no_contact;
        current = 0x1800;
        if (work3 > current)
            goto no_contact;
        goto interact;
    case 5:
        limit = 0x1800;
        work1 = work2 + limit;
        current = 0x2000;
        if ((u32)work1 > (u32)current)
            goto no_contact;
        current = -0x800;
        if (work3 < current || work3 > limit)
            goto no_contact;
        goto interact;
    case 7:
        current = 0x1800;
        work1 = work2 + current;
        current = 0x2000;
        if ((u32)work1 > (u32)current)
            goto no_contact;
        current = -0x1800;
        if (work3 < current)
            goto no_contact;
        current = 0x800;
        if (work3 > current)
            goto no_contact;
        work1 = 1;
        asm("" : "+r"(work1));
        contact = work1;
        break;
    }
no_contact:
    work2 = contact;
    asm("" : "+r"(work2));
    if (work2 == 0)
        goto next;
interact:
    pointer0 = (u8 *)keys;
    work2 = *(u16 *)pointer0;
    work1 = 1;
    asm("" : "+r"(work1));
    one = work1;
    asm("" : "+r"(one));
    current = one;
    current &= work2;
    if (current == 0)
        goto secondary;
    current = shifted + slot;
    work3 = current << 2;
    pointer2 = base;
    record = (u8 *)(work3 + (u32)pointer2);
    pointer2 = record + 0x6F;
    work1 = *pointer2;
    current = work1 - 1;
    current = (u8)current;
    if ((u32)current <= 3) {
        pointer0 = record + 0x6E;
        work1 = *pointer0;
        current = 0x429;
        current += (u32)base;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(current));
            *address = work1;
        }
        work1 = entity[0];
        current = 2;
        current |= work1;
        entity[0] = current;
        current = *pointer2;
        if (current != 2 && current != 4) {
            pointer0 = base + 0x74;
            pointer0 = (u8 *)(work3 + (u32)pointer0);
            current = *(s32 *)pointer0;
            work1 = *(s32 *)(entity + 8);
            current -= work1;
            current = (s16)current;
            work1 = *(s32 *)(entity + 4);
            pointer2 = base + 0x70;
            pointer2 = (u8 *)(work3 + (u32)pointer2);
            work2 = *(s32 *)pointer2;
            work1 -= work2;
            work1 = (s16)work1;
            current = func_080C8B74(current, work1);
            work1 = (u16)current;
            work2 = 0x2000;
            current = work1 + work2;
            current >>= 14;
            current <<= 1;
            work1 = 6;
            current &= work1;
            pointer1 = record + 0x82;
            *pointer1 = current;
        }
        asm("" : "+r"(shifted), "+r"(slot));
        current = shifted + slot;
        current <<= 2;
        current += (u32)base;
        pointer0 = (u8 *)current + 0x6C;
        work2 = *pointer0;
        work1 = 2;
        work1 |= work2;
        {
            u8 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
        return;
    }
    current = (u8)work1;
    if (current != 5)
        return;
    pointer1 = D_02020E4C;
    pointer0 = base + 0x90;
    bitIndex = (u8 *)(work3 + (u32)pointer0);
    work2 = *(u32 *)bitIndex;
    current = (u32)work2 >> 5;
    current <<= 2;
    bit = 0x7B00;
    asm("" : "+r"(bit));
    bit += (u32)pointer1;
    owned = (u8 *)bit;
    current += (u32)owned;
    bit = 0x1F;
    work2 &= bit;
    work1 = one;
    work1 <<= work2;
    current = *(u32 *)current;
    current &= work1;
    if (current != 0)
        return;
    pointer0 = record + 0x6E;
    work1 = *pointer0;
    current = 0x429;
    current += (u32)base;
    {
        u8 *address;
        asm("" : "=r"(address) : "0"(current));
        *address = work1;
    }
    work1 = entity[0];
    current = 2;
    current |= work1;
    entity[0] = current;
    pointer0 = base + 0x88;
    pointer0 = (u8 *)(work3 + (u32)pointer0);
    current = *(u32 *)pointer0;
    work1 = 2;
    func_08077204(current, work1);
    current = *(u32 *)bitIndex;
    work2 = (u32)current >> 5;
    work2 <<= 2;
    work2 += (u32)owned;
    current &= bit;
    work1 = one;
    work1 <<= current;
    current = *(u32 *)work2;
    current |= work1;
    *(u32 *)work2 = current;
    current = 0xD0;
    func_08075F20(current);
    return;
secondary:
    current = 2;
    current &= work2;
    if (current == 0)
        return;
    current = shifted + slot;
    work2 = current << 2;
    pointer1 = base;
    pointer0 = (u8 *)(work2 + (u32)pointer1);
    pointer0 += 0x6F;
    current = *pointer0;
    if (current != 1)
        return;
    pointer1 += 0x6C;
    pointer1 = (u8 *)(work2 + (u32)pointer1);
    pointer0 = entity;
    func_08081B60(pointer0, pointer1);
    return;
next:
    current = slot + 1;
    slot = (u8)current;
    if (slot <= 0xD)
        goto scan;
}
