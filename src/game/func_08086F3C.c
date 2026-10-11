#include "types.h"

struct Event {
    u8 pad;
    u8 side;
    u8 id;
    u8 kind;
    u8 required;
};
extern u8 D_08741CE4[];
extern u8 D_02031A0C[];
extern u8 D_02031C50;
extern u8 D_020367EB[];
extern u8 D_020367E9;
extern u8 D_0201F6DC[];
void func_08083C5C(u32, s32, s32);
void func_0809743C(u32);
u32 func_080C8C80(u32, u32);

s32 func_08086F3C(u32 arg0, struct Event **arg1)
{
    volatile u32 id;
    struct Event **volatile event = arg1;
    u8 *volatile table;
    volatile s32 found;
    u8 *volatile pattern;
    volatile u32 nextGroup;
    volatile u32 nextStart;
    register u32 tableIndex asm("r2");
    register u8 *tableBase asm("r3");
    register s32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register u32 work3 asm("r3");
    register u32 work4 asm("r4");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register struct Event **event4 asm("r4");
    register struct Event **event3 asm("r3");
    register struct Event **event0 asm("r0");
    register struct Event *entry1 asm("r1");
    register struct Event *entry2 asm("r2");
    register u32 start asm("r8");
    register u8 *patterns asm("r9");
    register u32 groupOffset asm("r10");
    register u32 count asm("r4");
    register u32 candidate asm("r3");
    u8 scan;
    register u8 *game asm("r5");
    u8 *wanted;
    u8 *selected;

    id = (u8)arg0;
    tableIndex = 0;
    pointer0 = D_08741CE4;
    table = pointer0;
    current = *pointer0;
    tableBase = table;
    if (current == 0)
        goto done;
search:
    event4 = event;
    entry1 = *event4;
    pointer4 = table;
    current = *pointer4;
    work4 = entry1->id;
    if (current != work4)
        goto next_table;
    current = entry1->side;
    pointer1 = &D_02031C50;
    /* Keep store addresses separate from integer registers during agbcc null checks. */
    {
        u8 *writeAddress;
        asm("" : "=r"(writeAddress) : "0"(pointer1));
        *writeAddress = current;
        work1 = *writeAddress;
    }
    current = ((work1 << 3) - work1) << 6;
    pointer2 = D_02031A0C;
    asm("" : "+r"(pointer2));
    current += (u32)pointer2;
    event3 = event;
    entry1 = *event3;
    work1 = entry1->kind;
    work4 = 0x1D80;
    asm("" : "+r"(work4));
    current += work4;
    {
        u8 *writeAddress;
        asm("" : "=r"(writeAddress) : "0"(current));
        *writeAddress = work1;
    }
    current = (*event3)->id;
    work3 = 0x4DDC;
    asm("" : "+r"(work3));
    pointer1 = pointer2 + work3;
    {
        u8 *writeAddress;
        asm("" : "=r"(writeAddress) : "0"(pointer1));
        *writeAddress = current;
    }
    pointer4 = &D_02031C50;
    current = *pointer4;
    current <<= 2;
    current += (u32)pointer2;
    work2 = 0x4F85;
    asm("" : "+r"(work2));
    current += work2;
    work3 = 0;
    {
        u8 *writeAddress;
        asm("" : "=r"(writeAddress) : "0"(current));
        *writeAddress = work3;
    }
    work4 = 0;
    asm("" : "+r"(work4));
    found = work4;
    current = 0;
group_loop:
    asm("" : "+r"(current));
    work1 = 0;
    asm("" : "+r"(work1));
    start = work1;
    work2 = current + 1;
    nextGroup = work2;
    work3 = found;
    if (work3 != 0)
        goto advance_group;
    current <<= 2;
    groupOffset = current;
    asm("" : "+r"(groupOffset));
    pointer4 = table;
    pointer4 += 2;
    asm("" : "+r"(pointer4));
    patterns = pointer4;
    asm("" : "+r"(patterns));
    pointer4 += groupOffset;
    pattern = pointer4;
start_loop:
    count = 0;
    pointer1 = pattern;
    current = *pointer1;
    asm("" : "+r"(current));
    work2 = start + 1;
    nextStart = work2;
    if (current == 0)
        goto check_match;
part_loop:
    candidate = (u8)func_080C8C80(nextStart, 6);
    if (candidate == start)
        goto check_match;
    game = D_02031A0C;
    asm("" : "+r"(game));
    work1 = groupOffset;
    asm("" : "+r"(work1));
    current = count + work1;
    pointer2 = patterns;
    asm("" : "+r"(pointer2));
    wanted = pointer2 + current;
    work1 = 0x4DDF;
    asm("" : "+r"(work1));
    current = (u32)game + work1;
    selected = (u8 *)(count + current);
candidate_loop:
    current = 0x94;
    work1 = candidate;
    work1 *= current;
    pointer0 = &D_02031C50;
    work2 = *pointer0;
    current = 0x65C;
    current *= work2;
    work1 += current;
    work1 += (u32)game;
    work2 = 0x10C8;
    asm("" : "+r"(work2));
    work1 += work2;
    current = *(u8 *)work1;
    work1 = *wanted;
    if (current == work1) {
        *selected = candidate;
        if (count == 0) {
            pointer2 = &D_020367E9;
            *pointer2 = candidate;
        }
        goto candidate_found;
    }
    candidate = (u8)func_080C8C80(candidate + 1, 6);
    if (candidate != start)
        goto candidate_loop;
candidate_found:
    if (candidate == start)
        goto check_match;
    current = count + 1;
    asm("" : "+r"(current));
    count = (u8)current;
    if (count <= 3) {
        work3 = groupOffset;
        asm("" : "+r"(work3));
        current = count + work3;
        current += (u32)patterns;
        current = *(u8 *)current;
        if (current != 0)
            goto part_loop;
    }
check_match:
    if (count == 0)
        goto advance_start;
    if (count != 4) {
        work1 = groupOffset;
        current = count + work1;
        current += (u32)patterns;
        current = *(u8 *)current;
        if (current != 0)
            goto advance_start;
    }
    if (count <= 3) {
        pointer2 = D_02031A0C;
        work3 = 0x4DDF;
        asm("" : "+r"(pointer2), "+r"(work3));
        pointer1 = pointer2 + work3;
        pointer1 = (u8 *)(count + (u32)pointer1);
        {
            u8 *writeAddress;
            asm("" : "=r"(writeAddress) : "0"(pointer1));
            *writeAddress = 0xFF;
        }
    }
    event0 = event;
    entry2 = *event0;
    current = entry2->required;
    if (current == 0xFF)
        goto found_required;
    scan = 0;
    if (scan < count) {
        pointer3 = D_020367EB;
        work2 = current;
scan_loop:
        current = (s8)*(u8 *)(scan + (u32)pointer3);
        if (current == work2) {
            current = 1;
            found = current;
        }
        scan++;
        if (scan < count)
            goto scan_loop;
    }
    goto advance_start;
found_required:
    work1 = 1;
    found = work1;
advance_start:
    work2 = nextStart;
    current = (u8)work2;
    start = current;
    if ((u32)current <= 5) {
        work3 = found;
        if (work3 == 0)
            goto start_loop;
    }
advance_group:
    work4 = nextGroup;
    current = (u8)work4;
    if ((u32)current > 2)
        goto done;
    work1 = found;
    if (work1 == 0)
        goto group_loop;
    pointer0 = D_0201F6DC;
    work2 = 0x10F4;
    asm("" : "+r"(pointer0), "+r"(work2));
    pointer0 += work2;
    work3 = 0;
    *pointer0 = work3;
    pointer4 = D_02031A0C;
    work1 = 0x4DDD;
    asm("" : "+r"(pointer4), "+r"(work1));
    current = (u32)pointer4 + work1;
    asm("" : "+r"(current));
    current = *(u8 *)current;
    work2 = (current << 5) + current;
    pointer3 = &D_02031C50;
    work1 = *pointer3;
    current = (work1 << 3) - work1;
    work1 = current << 5;
    current += work1;
    current += work2;
    current <<= 3;
    current += (u32)pointer4;
    work4 = 0x259;
    asm("" : "+r"(work4));
    current += work4;
    *(u8 *)current = 0;
    func_0809743C(1);
    goto done;
next_table:
    current = tableIndex + 1;
    asm("" : "+r"(current));
    tableIndex = (u8)current;
    current = tableIndex << 4;
    pointer0 = (u8 *)(current + (u32)tableBase);
    table = pointer0;
    current = *pointer0;
    if (current != 0)
        goto search;
done:
    func_08083C5C(id, -1, 0);
    return 0;
}
