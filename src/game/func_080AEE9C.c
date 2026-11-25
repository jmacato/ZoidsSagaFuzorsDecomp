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
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_080A7154(void);
void func_080A7B14(void);
void func_080A3578(void);

void func_080AEE9C(struct Obj *obj)
{
    u8 i;

    if (obj->field_8C == 0)
    {
        switch (obj->field_90)
        {
        case 0:
            obj->children[0] = func_080A34A8(obj, 3, 0, obj->field_4, obj->field_8, 0x20, func_080A7154, 0);
            obj->children[0]->field_30 = obj;
            obj->children[0]->field_34 = 0;
            obj->children[0]->field_3C = 3;
            func_080A38B0(0);
            break;
        case 1:
            obj->children[0] = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0x20, func_080A7B14, 0);
            obj->children[0]->field_30 = obj;
            obj->children[0]->field_34 = 0;
            func_080A38B0(0);
            break;
        case 2:
            obj->children[0] = func_080A34A8(obj, 5, 0, obj->field_4, obj->field_8, 0x400, 0, 0);
            obj->children[1] = func_080A34A8(obj, 6, 0, obj->field_4, obj->field_8, 0x510, func_080A3578, 0);
            obj->children[1]->field_30 = (void *)0x10;
            func_080A38B0(1);
            break;
        }
        obj->field_8C++;
    }
    else if (obj->field_90 <= 1)
    {
        if (obj->children[0]->flags & 0x20000)
        {
            if (obj->children[0]->field_34 < 16)
            {
                for (i = 1; i < (obj->children[0]->field_34 >> 2) + 2 && obj->children[i] == 0; i++)
                    ;
                if (i == (obj->children[0]->field_34 >> 2) + 2)
                    func_08077E6C(obj);
            }
            else
            {
                for (i = 1; i < ((obj->children[0]->field_34 - 16) >> 1) + 6 && obj->children[i] == 0; i++)
                    ;
                if (i == ((obj->children[0]->field_34 - 16) >> 1) + 6)
                    func_08077E6C(obj);
            }
        }
    }
    else if (obj->children[0] == 0 && obj->children[1] == 0)
    {
        func_08077E6C(obj);
    }
}
