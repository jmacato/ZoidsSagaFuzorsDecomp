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
    s32 field_8C;
    u32 field_90;
    s32 field_94;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_080A72E4(void);
void func_080A7CB4(void);
void func_080A3578(void);

void func_080AF50C(struct Obj *obj)
{
    u8 i;

    if (obj->field_8C == 0)
    {
        switch (obj->field_90)
        {
        case 0:
            obj->children[0] = func_080A34A8(obj, 2, 0, obj->field_4, obj->field_94 + 0x50, 0x20, func_080A72E4, 1);
            obj->children[0]->field_30 = obj;
            obj->children[0]->field_34 = 0;
            obj->children[0]->field_38 = 0;
            obj->children[0]->field_3C = 2;
            func_080A38B0(0);
            break;
        case 1:
            obj->children[0] = func_080A34A8(obj, 0, 0, obj->field_4 + obj->field_94 * 2, 0x80, 0x20, func_080A7CB4, 1);
            obj->children[0]->field_30 = obj;
            obj->children[0]->field_34 = 0;
            obj->children[0]->field_38 = 0;
            func_080A38B0(0);
            break;
        case 2:
            obj->children[0] = func_080A34A8(obj, 4, 0, obj->field_4 - 0x10, obj->field_94 + 0x50, 0x410, func_080A3578, 1);
            obj->children[0]->field_30 = (void *)0x10;
            func_080A38B0(1);
            break;
        }
        obj->field_8C++;
    }
    else if (obj->field_90 <= 1)
    {
        if (obj->children[0]->flags & 0x20000)
        {
            for (i = 0x18; i < (obj->children[0]->field_34 >> 1) + 0x19 && obj->children[i] == 0; i++)
                ;
            if (i == (obj->children[0]->field_34 >> 1) + 0x19)
                func_08077E6C(obj);
        }
    }
    else if (obj->children[0] == 0)
    {
        func_08077E6C(obj);
    }
}
