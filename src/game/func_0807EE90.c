#include "types.h"

struct Pilot
{
    u8 id;
    u8 known;
    u8 level;
    u8 flags;
    u8 pad4[0x2A];
    u8 zoid;
    u8 pad2F[0xF];
    u8 field_3E;
    u8 pad3F;
};

extern struct Pilot D_02027A10[];
extern u8 D_02030AE8;

void func_080BF608(u8, u8, struct Pilot *);
void func_0807F420(u8);
void func_080BFD6C(struct Pilot *);
u8 func_08082F4C(u8);

u8 func_0807EE90(u8 id, u8 level)
{
    u8 slot = 0xFF;
    u8 i, j;
    struct Pilot *pilot;

    for (i = 1; i < 53; i++)
    {
        pilot = &D_02027A10[i];
        if (pilot->id == 0)
        {
            if (pilot->known == 0)
            {
                if (slot == 0xFF)
                    slot = i;
            }
            else if (pilot->known == id)
            {
                slot = i;
            }
        }
        else if (pilot->id == id)
        {
            return 0;
        }
    }
    if (slot != 0xFF)
    {
        pilot = &D_02027A10[slot];
        if (pilot->known == 0)
        {
            func_080BF608(id, level, pilot);
            pilot->known = id;
            func_0807F420(id);
        }
        else
        {
            pilot->id = id;
            pilot->flags = pilot->zoid = 0;
            for (j = pilot->level; j < level; j++)
                func_080BFD6C(pilot);
        }
        if (id == 0x3B)
        {
            if (D_02030AE8 == 0 && func_08082F4C(0x27) == 0)
                pilot->field_3E = 0;
            else
                pilot->field_3E = 2;
        }
        return slot;
    }
    return 0;
}
