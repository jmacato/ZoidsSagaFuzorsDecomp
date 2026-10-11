#include "types.h"

struct Obj
{
    u32 flags;
    u8 pad4[8];
    struct Obj *children[32];
    u8 pad8C[0x20];
    void (*func1)(struct Obj *);
    void (*func2)(struct Obj *);
};

extern struct Obj D_03002688[];

void func_08077EAC(void)
{
    u8 i, j;
    struct Obj *obj;

    for (i = 0; i < 16; i++)
    {
        obj = &D_03002688[i];
        if (obj->flags & 1)
        {
            for (j = 0; j < 32; j++)
            {
                if (obj->children[j] != 0 && !(obj->children[j]->flags & 1))
                    obj->children[j] = 0;
            }
        }
    }
    for (i = 0; i < 16; i++)
    {
        obj = &D_03002688[i];
        if (obj->flags & 1)
        {
            if (obj->func1 != 0)
            {
                obj->func1(obj);
                obj->func1 = 0;
            }
            if (obj->func2 != 0)
                obj->func2(obj);
        }
    }
}
