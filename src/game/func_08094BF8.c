#include "types.h"

struct Entry
{
    u16 field_0;
    u16 id;
};

struct Unit
{
    u8 pad_0[0x74];
    struct Entry entries[8];
};

struct Team
{
    u8 field_0;
    u8 slots[3];
};

struct Big
{
    u8 pad_0[0x244];
    u8 cur;
    u8 pad_245[7];
    struct Unit *unit;
    u8 pad_250[0x4F84 - 0x250];
    struct Team teams[2];
};

struct Part
{
    u16 b0:1;
    u16 b1:10;
    u16 b11:1;
    u16 b12:4;
    u8 pad_2[0xE];
    s16 field_10;
    u8 pad_12[6];
};

extern struct Big D_02031A0C;
extern const struct Part D_08741EF4[];

u8 func_08094BF8(s8 i, s8 dir)
{
    s8 end;
    const struct Part *part;
    const struct Part *p;
    u8 j;
    s32 k;

    if (i < 0)
        i += 8;
    else if (i > 7)
        i -= 8;
    end = i - dir;
    if (end < 0)
        end += 8;
    else if (end > 7)
        end -= 8;
    while (i != end)
    {
        if (D_02031A0C.unit->entries[i].id != 0)
        {
            part = &D_08741EF4[D_02031A0C.unit->entries[i].id];
            for (j = 0; j < 3 && D_02031A0C.teams[D_02031A0C.cur].slots[j] != 0xFF; j++)
            {
                k = D_02031A0C.teams[D_02031A0C.cur].slots[j] & 7;
                if (k == i)
                    break;
                p = &D_08741EF4[D_02031A0C.unit->entries[k].id];
                if (!p->b0 && p->b11)
                    break;
                if (p->b0)
                    break;
            }
            if ((j == 3 || D_02031A0C.teams[D_02031A0C.cur].slots[j] == 0xFF)
                && (!part->b0 || part->field_10 == 0)
                && (D_02031A0C.teams[D_02031A0C.cur].slots[0] == 0xFF || !(part->b0 || part->b11)))
                return i;
        }
        i += dir;
        if (i < 0)
            i += 8;
        else if (i > 7)
            i -= 8;
    }
    return 0xFF;
}
