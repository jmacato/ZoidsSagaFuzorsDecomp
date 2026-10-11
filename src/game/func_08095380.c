#include "types.h"

struct Obj
{
    u8 pad_0[4];
    s32 x;
    s32 y;
    u8 pad_C[0x80];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
    s32 field_98;
};

extern struct Obj *D_02036960[];
struct Obj *func_08077DF0(u32, u32, void (*)(struct Obj *));
void func_080951C4(struct Obj *);
u8 func_080C8D50(u8, u32);
u8 func_080C8DC8(u8, u32);

void func_08095380(u8 side)
{
    u8 i;
    struct Obj *obj;

    for (i = 0; i < 6; i++)
    {
        obj = func_08077DF0(0, 0, func_080951C4);
        D_02036960[i] = obj;
        if (side == 0)
        {
            if (func_080C8D50(i, 3) == 0)
                obj->x = 0x10;
            else
                obj->x = 0x30;
            obj = D_02036960[i];
            obj->y = (func_080C8DC8(i, 3) << 5) + 8;
        }
        else
        {
            if (func_080C8D50(i, 3) == 0)
                obj->x = 0x30;
            else
                obj->x = 0x10;
            obj = D_02036960[i];
            obj->y = 0x48 - (func_080C8DC8(i, 3) << 5);
        }
        D_02036960[i]->field_8C = D_02036960[i]->field_90 = D_02036960[i]->field_94 = D_02036960[i]->field_98 = 0;
    }
}
