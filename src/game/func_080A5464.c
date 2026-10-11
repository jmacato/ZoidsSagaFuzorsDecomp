#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0x2C];
    void *parent;
    u32 count;
    s32 target;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 state;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

void func_080A4E44(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A5464(struct Obj *obj)
{
    u8 i;
    u8 j;
    s16 px;
    s16 py;
    s32 ofs;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 256, obj->field_94, 0x20, func_080A4E44, 1);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        obj->child[0]->target = obj->field_90;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0]->flags & 0x20000)
        {
            for (i = 0; i < 1; i++)
            {
                px = obj->field_90 + i * 8;
                ofs = i ? 8 : 0;
                py = obj->field_94 + ((i & 1) ? -1 : 1) * ofs + ((D_03000010() * 9 >> 15) - 4);
                for (j = 0; j < 3; j++)
                    obj->child[i * 4 + j + 1] = func_080A3770(obj, 2, 0, px, py, 0x400, j * 12 - 12, (D_03000010() * 65 >> 15) + 0xC0, 0);
                obj->child[i * 4 + 4] = func_080A34A8(obj, 3, 0, px, py, 0, 0, 0);
            }
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        if (obj->child[0]->flags & 0x20000)
        {
            for (i = 24; i < obj->child[0]->count / 4 + 25 && obj->child[i] == 0; i++)
                ;
            if (i == obj->child[0]->count / 4 + 25)
            {
                for (i = 1; i < 5 && obj->child[i] == 0; i++)
                    ;
                if (i == 5)
                    func_08077E6C(obj);
            }
        }
        break;
    }
}
