#include "types.h"

struct Obj
{
    u32 flags;
    s32 y;
    u8 pad_8[0x28];
    s32 field_30;
};

struct Spawner
{
    u32 flags;
    s32 field_4;
    s32 field_8;
    struct Obj *objs[32];
};

struct State
{
    u8 pad_0[0x98];
    u8 mirror;
};

extern u32 (*D_03000010)(void);
extern struct State D_02036E7C;
extern const u8 D_087B14E8[];

struct Obj *func_08077180(const void *data, u32 a, u32 b, u32 c, s16 d, u32 e, u32 f, u32 flags, void (*cb)(struct Obj *));
void func_080A2598(struct Obj *obj);

void func_080A25FC(struct Spawner *sp)
{
    u8 i;
    for (i = 0; i < 32; i++)
    {
        if (sp->objs[i] == 0)
        {
            u32 x;
            x = (D_03000010() * 4) >> 16;
            sp->objs[i] = func_08077180(D_087B14E8, 0x77, x, 0, sp->field_8 + ((D_03000010() * 65) >> 15) - 0x20, 0x35C, 10, D_02036E7C.mirror ? 0x9048 : 0x1048, func_080A2598);
            if (D_02036E7C.mirror == 0)
                sp->objs[i]->y = (sp->field_4 + ((D_03000010() * 65) >> 15) - 0x20) << 8;
            else
                sp->objs[i]->y = (((D_03000010() * 65) >> 15) - sp->field_4 + 0xD0) << 8;
            sp->objs[i]->field_30 = ((D_03000010() * 257) >> 15) + 0x200;
            return;
        }
    }
}
