#include "types.h"

struct Entry
{
    u8 id;
    u8 turns;
    u8 damage;
    u8 srcSide;
    u8 srcZoid;
    u8 field_5;
    s16 value;
};

struct Unit
{
    u8 zoid;
    u8 pad_1[7];
    struct Entry entries[32];
};

struct Zoid
{
    u8 pad_0[6];
    s16 hp;
    s16 en;
    u8 pad_A[0x8A];
};

struct EffectList
{
    u16 flags;
    u8 pad_2[0x202];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
    u8 pad_1D80[0x182C];
    struct EffectList effects[2][6];
};

extern struct Game D_02031A0C;

s32 func_0809A99C(u8 side, u8 slot);
void func_080BE06C(struct Zoid *zoid, s16 v);
void func_080BE0A0(struct Zoid *zoid, s16 v);
void func_0809B480(u8 side, u8 slot, u8 id, s16 value);
void func_0809B4D0(u8 side, u8 slot, u8 index);

void func_0809B9BC(void)
{
    u8 side, slot;
    s16 k;
    for (side = 0; side < 2; side++)
    {
        for (slot = 0; slot < 6; slot++)
        {
            if (func_0809A99C(side, slot))
            {
                struct Unit *unit = &D_02031A0C.units[side][slot];
                struct Zoid *zoid = &D_02031A0C.zoids[side][unit->zoid];
                for (k = 0; k < 32; k++)
                {
                    if (unit->entries[k].id == 0)
                        continue;
                    switch (unit->entries[k].id)
                    {
                    case 1:
                        func_080BE06C(zoid, unit->entries[k].value);
                        func_0809B480(side, slot, 1, unit->entries[k].value);
                        D_02031A0C.effects[side][slot].flags = 1;
                        break;
                    }
                    if (unit->entries[k].damage != 0)
                    {
                        func_080BE0A0(zoid, -unit->entries[k].damage);
                        func_0809B480(side, slot, 6, unit->entries[k].damage);
                        D_02031A0C.effects[side][slot].flags = 1;
                        if (unit->entries[k].damage != 0 && zoid->en == 0)
                        {
                            func_0809B4D0(side, slot, k);
                            k--;
                            continue;
                        }
                    }
                    if (unit->entries[k].turns != 0 && --unit->entries[k].turns == 0)
                    {
                        func_0809B4D0(side, slot, k);
                        k--;
                    }
                }
            }
        }
    }
}
