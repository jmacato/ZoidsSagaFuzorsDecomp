#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
};

extern u32 (*D_03000010)(void);

s16 func_08075AAC(s16);
s16 func_08075AF8(s16);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);

void func_080ADE30(struct Obj *obj, u8 speed)
{
    u8 i;
    u16 dist;
    u8 angle;

    for (i = 1; i < 32; i++)
    {
        if (obj->child[i] == 0)
        {
            dist = (D_03000010() * 21 >> 15) + 0x30;
            angle = (D_03000010() * 86 >> 15) + 0x55;
            obj->child[i] = func_080A3770(obj, 1, 0,
                obj->x + func_08075AF8(angle) * dist / 256,
                obj->y + func_08075AAC(angle) * dist / 256,
                0x400, angle + 0x80, (speed << 8) * dist / 48, 0);
            break;
        }
    }
}
