#include "types.h"

struct Effect
{
    u8 id;
    u8 pad_1[5];
    u16 value;
};

struct EffectList
{
    u8 pad_0[4];
    struct Effect effects[64];
};

extern struct EffectList D_02034FB8[][6];

void func_0809B480(u8 side, u8 slot, u8 id, u16 value)
{
    struct EffectList *list = &D_02034FB8[side][slot];
    u8 i;
    for (i = 0; i < 32; i++)
    {
        struct Effect *e = &list->effects[i];
        if (e->id == 0)
        {
            e->id = id;
            e->value = value;
            return;
        }
    }
}
