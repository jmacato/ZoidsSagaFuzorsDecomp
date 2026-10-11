#include "types.h"

struct Unit {
    u8 id;
    u8 pad1[2];
    u8 flags;
    u8 pad4[6];
    s16 stats[4];
    s16 first[5][4];
    s16 second[5][4];
    u8 pad62[14];
    u32 level;
};
struct PartCost {
    u32 cost;
    u32 other;
};
extern u8 D_08741C44[][10];
extern u32 D_0877D4A4[];
extern struct PartCost D_08759BF8[];
extern s16 D_08741EEC[4];
u32 func_080B611C(struct Unit *, u8, u8);

u32 func_080BE174(struct Unit *arg0)
{
    /* Empty asm preserves agbcc register copies and reload lifetimes without adding instructions. */
    register struct Unit *unit asm("r9") = arg0;
    register u32 cost asm("r8") = 0;
    u32 level;
    u32 limit;
    u8 row = 0;
    u8 col;
    register u32 member asm("r2");
    register u8 *line asm("r1");
    register u8 *table asm("r10");
    register u32 *prices asm("r5");
    register struct PartCost *parts asm("r6");
    register struct PartCost *selectedParts asm("r4");
    register struct Unit *unitCopy asm("r4");
    register struct Unit *levelUnit asm("r2");
    register struct Unit *fallbackUnit asm("r1");
    register struct Unit *idUnit asm("r3");
    register u32 bit asm("r5");
    register u32 ceiling asm("r5");
    u8 group;
    s32 determinant;
    s32 a;
    s32 b;
    s32 sum;
    register s32 factor asm("r6");
    s16 value;
    u8 unitId;
    register u32 initial asm("r0");
    register u32 next asm("r0");
    u8 flags;
    s16 *first;
    s32 stride;
    s16 *second;
    register s32 index asm("r1");
    s32 product;
    s32 coefficient;
    register u32 loadScratch asm("r3");

    line = D_08741C44[0];
    initial = line[0];
    asm("" : "+r"(initial));
    table = line;
    if (initial != 0) {
        levelUnit = unit;
        asm("" : "+r"(levelUnit));
        level = levelUnit->level;
find_row:
        line = (u8 *)(row * 10 + (u32)line);
        member = 0;
        if (line[0] != 0) {
            unitId = unit->id;
            prices = D_0877D4A4;
            parts = D_08759BF8;
            asm("" : "+r"(prices), "+r"(parts));
find_member:
            if (line[member * 2] == unitId) {
                cost = prices[line[0]];
                row = 1;
                unitCopy = unit;
                asm("" : "+r"(unitCopy));
                flags = unitCopy->flags;
                bit = 1;
                asm("" : "+r"(bit));
                selectedParts = parts;
                asm("" : "+r"(selectedParts));
                do {
                    if ((flags >> row) & bit)
                        cost += selectedParts[line[row * 2]].cost >> 1;
                    row = (u8)(row + 1);
                } while (row <= 4);
            } else {
                next = member + 1;
                asm("" : "+r"(next));
                member = (u8)next;
                if (member <= 4 && line[member * 2] != 0)
                    goto find_member;
            }
        }
        initial = cost;
        asm("" : "+r"(initial));
        if (initial == 0) {
            row = (u8)(row + 1);
            line = table;
            if (line[row * 10] == 0)
                goto fallback;
            goto find_row;
        }
    } else {
fallback:
        fallbackUnit = unit;
        asm("" : "+r"(fallbackUnit));
        level = fallbackUnit->level;
        member = cost;
        asm("" : "+r"(member));
        if (member == 0) {
            line = (u8 *)D_0877D4A4;
            asm("" : "+r"(line));
            idUnit = unit;
            asm("" : "+r"(idUnit));
            cost = ((u32 *)line)[idUnit->id];
        }
    }
    ceiling = 999999999U;
    asm("" : "+r"(ceiling));
    limit = ceiling / cost;
    if (limit < level / 200)
        goto overflow;
    cost += cost * level / 200;
    if (cost > 999999998U)
        goto overflow;
    unitCopy = unit;
    asm("" : "+r"(unitCopy));
    /* Keep r3 live so agbcc uses r0 for the first signed load. */
    asm("" : "=r"(loadScratch));
    sum = unitCopy->stats[0];
    asm("" : : "r"(loadScratch));
    sum += unitCopy->stats[1];
    sum += unitCopy->stats[2];
    sum += unitCopy->stats[3];
    cost += (sum / 2) * 500;
    if (cost > 999999998U) {
overflow:
        return 999999999U;
    }
    determinant = D_08741EEC[1] * D_08741EEC[2] - D_08741EEC[0] * D_08741EEC[3];
    group = 0;
    second = &unit->second[0][0];
    first = &unit->first[0][0];
    do {
        col = 0;
        stride = group * 8;
        do {
            factor = D_08741EEC[2];
            asm("" : "+r"(factor));
            index = col * 2 + stride;
            product = factor * *(s16 *)((u8 *)second + index);
            coefficient = D_08741EEC[3];
            value = *(s16 *)((u8 *)first + index);
            a = (product - coefficient * value) / determinant;
            b = (value - a * D_08741EEC[0]) / factor;
            cost += (a + b) * (func_080B611C(unit, group, (u8)(col + 4)) >> 1);
            if (cost > 999999998U)
                goto overflow;
            col++;
        } while (col <= 3);
        group++;
    } while (group <= 4);
    return cost;
}
