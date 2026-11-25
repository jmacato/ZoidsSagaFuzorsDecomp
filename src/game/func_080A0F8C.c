#include "types.h"

extern u8 D_02036E7C[];
extern u8 D_02037771;
void func_08075F20(u32);
void func_080A12B0(u32, u32);
void func_080A05BC(u32);
u32 func_080C8DC8(u32, u32);
u32 func_080B229C(u32, u32, s32, s32, u32);

void func_080A0F8C(void)
{
    register u32 current asm("r0");
    register s32 signed1 asm("r1");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 index asm("r3");
    register u32 work3 asm("r3");
    register u32 work4 asm("r4");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *context asm("r10");
    register u8 **script asm("r8");
    register u8 *counter asm("r9");
    u8 *table;
    u32 active;
    register u8 **initialScript asm("r5");
    u32 kind;
    u8 *base;
    u8 *record;
    u32 object;

    pointer1 = D_02036E7C;
    work2 = 0x90F;
    asm("" : "+r"(work2));
    pointer0 = pointer1 + work2;
    current = *pointer0;
    if (current == 2) {
        work3 = 0x910;
        asm("" : "+r"(work3));
        pointer0 = pointer1 + work3;
        current = *pointer0;
        if (current == 0) {
            func_08075F20(0xF6);
            func_080A12B0(13, 0);
        }
    }
    index = 0;
    pointer2 = D_02036E7C;
    current = 0x918;
    asm("" : "+r"(current));
    table = pointer2 + current;
    active = 1;
clear_loop:
    current = index << 2;
    pointer0 = (u8 *)(current + (u32)table);
    pointer1 = *(u8 **)pointer0;
    if (pointer1 != 0) {
        work1 = *(u32 *)pointer1;
        work1 &= active;
        if (work1 == 0) {
            u32 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
        }
    }
    current = index + 1;
    asm("" : "+r"(current));
    index = (u8)current;
    if (index <= 15)
        goto clear_loop;
    work1 = 0x904;
    asm("" : "+r"(work1));
    pointer0 = pointer2 + work1;
    current = *(u16 *)pointer0;
    if (current != 0)
        goto inspect_end;
    work3 = 0x8F8;
    asm("" : "+r"(work3));
    initialScript = (u8 **)(pointer2 + work3);
    pointer0 = *initialScript;
    signed1 = *(s16 *)pointer0;
    asm volatile("" : "+r"(work3));
    current = -1;
    if (signed1 == (s32)current)
        goto inspect_objects;
    context = pointer2;
    script = initialScript;
    current = 0x910;
    asm("" : "+r"(current));
    current += (u32)pointer2;
    counter = (u8 *)current;
script_loop:
    pointer1 = (u8 *)script;
    pointer3 = *(u8 **)pointer1;
    signed1 = *(s16 *)pointer3;
    asm volatile("" : "+r"(current));
    current = -2;
    if (signed1 == (s32)current) {
        work1 = 0x902;
        asm("" : "+r"(work1));
        pointer0 = pointer2 + work1;
        work1 = *(u16 *)pointer0;
        work1++;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer0));
            *address = work1;
            signed1 = *(s16 *)(pointer3 + 2);
            current = *address;
        }
        if (signed1 == (s32)current) {
            pointer0 = pointer3 + 4;
            pointer1 = (u8 *)script;
            *(u8 **)pointer1 = pointer0;
        } else {
            current = 0x8FC;
            asm("" : "+r"(current));
            current += (u32)context;
            pointer0 = *(u8 **)current;
            pointer3 = (u8 *)script;
            *(u8 **)pointer3 = pointer0;
        }
        goto continue_script;
    }
    work4 = 0x900;
    asm("" : "+r"(work4));
    pointer0 = pointer2 + work4;
    kind = *(u16 *)pointer0;
    if (kind == 1) {
        pointer1 = counter;
        current = *pointer1;
        current &= kind;
        kind = current + 1;
    } else if (kind == 0x5F) {
        pointer2 = counter;
        current = *pointer2;
        current = func_080C8DC8(current, 3);
        current <<= 24;
        if (current != 0) {
            pointer3 = &D_02037771;
            current = *pointer3;
            kind = 0x61;
            if (current == 13)
                kind = 0x60;
        }
    }
    pointer4 = D_02036E7C;
    current = *pointer4;
    if (current == 0x31) {
        work1 = 0x900;
        asm("" : "+r"(work1));
        pointer0 = pointer4 + work1;
        current = *(u16 *)pointer0;
        if (current == 0x70) {
            work2 = 0x8FC;
            asm("" : "+r"(work2));
            pointer0 = pointer4 + work2;
            pointer0 = *(u8 **)pointer0;
            pointer0 += 0x28;
            pointer3 = (u8 *)script;
            pointer1 = *(u8 **)pointer3;
            if (pointer1 == pointer0) {
                func_080A05BC(4);
                pointer1 = pointer4 + 0x9C;
                current = 1;
                *pointer1 = current;
            }
        }
    }
    base = D_02036E7C;
    asm("" : "+r"(base));
    current = *base;
    work4 = 0x908;
    asm("" : "+r"(work4));
    {
        u32 offset;
        asm("" : "=r"(offset) : "0"(work4));
        pointer1 = base + offset;
    }
    pointer2 = (u8 *)script;
    record = *(u8 **)pointer2;
    work2 = *(u16 *)(record + 2);
    work1 = *(u16 *)pointer1;
    work2 += work1;
    asm("" : "+r"(work2));
    work2 = (s16)work2;
    work3 = 0x90A;
    asm("" : "+r"(work3));
    {
        u32 offset;
        asm("" : "=r"(offset) : "0"(work3));
        pointer1 = base + offset;
    }
    work3 = *(u16 *)(record + 4);
    work1 = *(u16 *)pointer1;
    work3 += work1;
    asm("" : "+r"(work3));
    work3 = (s16)work3;
    work1 = 0x90C;
    asm("" : "+r"(work1));
    {
        u32 offset;
        asm("" : "=r"(offset) : "0"(work1));
        pointer4 = base + offset;
    }
    work1 = *(u16 *)(record + 6);
    work1 <<= 6;
    work4 = *(u16 *)pointer4;
    work1 = (u16)(work1 + work4);
    object = func_080B229C(current, kind, work2, work3, work1);
    if (object != 0) {
        index = 0;
        work2 = 0x918;
        asm("" : "+r"(work2));
        {
            u32 offset;
            asm("" : "=r"(offset) : "0"(work2));
            pointer1 = base + offset;
        }
        current = *(u32 *)pointer1;
        pointer2 = base;
        goto find_slot;
next_slot:
        current = index + 1;
        asm("" : "+r"(current));
        index = (u8)current;
        if (index > 15)
            goto stored;
        current = index << 2;
        work4 = 0x918;
        asm("" : "+r"(work4));
        pointer1 = pointer2 + work4;
        pointer1 = (u8 *)(current + (u32)pointer1);
        current = *(u32 *)pointer1;
find_slot:
        if (current != 0)
            goto next_slot;
        *(u32 *)pointer1 = object;
    }
stored:
    pointer1 = (u8 *)script;
    pointer0 = *(u8 **)pointer1;
    work1 = *(u16 *)pointer0;
    work2 = 0x904;
    asm("" : "+r"(work2));
    pointer2 = (u8 *)work2;
    pointer2 += (u32)context;
    *(u16 *)pointer2 = work1;
    pointer0 += 8;
    pointer3 = (u8 *)script;
    *(u8 **)pointer3 = pointer0;
    pointer4 = counter;
    current = *pointer4;
    current++;
    *pointer4 = current;
    current = (u32)-0x904;
    asm("" : "+r"(current));
    pointer2 += current;
continue_script:
    work1 = 0x904;
    asm("" : "+r"(work1));
    pointer0 = pointer2 + work1;
    current = *(u16 *)pointer0;
    if (current != 0)
        goto inspect_end;
    pointer3 = (u8 *)script;
    pointer0 = *(u8 **)pointer3;
    signed1 = *(s16 *)pointer0;
    asm volatile("" : "+r"(pointer3));
    current = -1;
    if (signed1 != (s32)current)
        goto script_loop;
inspect_end:
    work1 = 0x8F8;
    asm("" : "+r"(work1));
    pointer0 = pointer2 + work1;
    pointer0 = *(u8 **)pointer0;
    signed1 = *(s16 *)pointer0;
    current = -1;
    if (signed1 != (s32)current)
        goto decrement;
inspect_objects:
    index = 0;
    work4 = 0x918;
    asm("" : "+r"(work4));
    pointer1 = pointer2 + work4;
    current = *(u32 *)pointer1;
    if (current != 0)
        goto count_objects;
object_loop:
    current = index + 1;
    asm("" : "+r"(current));
    index = (u8)current;
    if (index > 15)
        goto count_objects;
    current = index << 2;
    current += (u32)pointer1;
    current = *(u32 *)current;
    if (current == 0)
        goto object_loop;
count_objects:
    if (index == 16) {
        current = 0x8F4;
        asm("" : "+r"(current));
        pointer1 = pointer2 + current;
        current = 2;
        *pointer1 = current;
    }
    return;
decrement:
    work3 = 0x904;
    asm("" : "+r"(work3));
    pointer1 = pointer2 + work3;
    current = *(u16 *)pointer1;
    current--;
    *(u16 *)pointer1 = current;
}
