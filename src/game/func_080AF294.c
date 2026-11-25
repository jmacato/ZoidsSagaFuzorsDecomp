#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_4[0x2C];
    void *field_30;
    u32 field_34;
    s32 field_38;
    s32 field_3C;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    u32 field_8C;
    s32 field_90;
    s32 field_94;
    u32 field_98;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
u8 func_080A3874(struct Child *, s32, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);
void func_080771F4(void *);
void func_080A72E4(void);
void func_080A7DC0(void);
void func_080A3578(void);

void func_080AF294(struct Obj *obj)
{
    u8 i;

    switch (obj->field_8C)
    {
    case 0:
        switch (obj->field_98)
        {
        case 0:
            obj->children[0] = func_080A34A8(obj, 2, 0, obj->field_90 - 0x100, obj->field_94, 0x20, func_080A72E4, 1);
            obj->children[0]->field_30 = obj;
            obj->children[0]->field_34 = 0;
            obj->children[0]->field_38 = obj->field_90;
            obj->children[0]->field_3C = 2;
            func_080A38B0(0);
            break;
        case 1:
            obj->children[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 0x100, obj->field_94 - 0x80, 0x20, func_080A7DC0, 1);
            obj->children[0]->field_30 = obj;
            obj->children[0]->field_34 = 0;
            obj->children[0]->field_38 = obj->field_90;
            func_080A38B0(0);
            break;
        case 2:
            obj->children[0] = func_080A34A8(obj, 4, 0, obj->field_90 - 0x100, obj->field_94, 0x410, func_080A3578, 1);
            obj->children[0]->field_30 = (void *)0x10;
            func_080A38B0(1);
            break;
        }
        obj->field_8C++;
        break;
    case 1:
        if (obj->field_98 <= 1)
        {
            if (obj->children[0]->flags & 0x20000)
            {
                obj->children[1] = func_080A34A8(obj, 5, 0, obj->field_90, obj->field_94, 0, 0, 0);
                func_080A12B0(6, 0);
                func_080A38B0(2);
                obj->field_8C++;
            }
        }
        else if (func_080A3874(obj->children[0], obj->field_90 - 0x10, obj->field_94))
        {
            func_080771F4(obj->children[0]);
            obj->children[0] = func_080A34A8(obj, 5, 0, obj->field_90, obj->field_94, 0, 0, 0);
            func_080A12B0(6, 0);
            func_080A38B0(2);
            obj->field_8C++;
        }
        break;
    case 2:
        if (obj->field_98 <= 1)
        {
            for (i = 0x18; i < (obj->children[0]->field_34 >> 1) + 0x19 && obj->children[i] == 0; i++)
                ;
            if (i == (obj->children[0]->field_34 >> 1) + 0x19 && obj->children[1] == 0)
                func_08077E6C(obj);
        }
        else if (obj->children[0] == 0)
        {
            func_08077E6C(obj);
        }
        break;
    }
}
