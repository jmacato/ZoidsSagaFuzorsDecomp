#include "types.h"

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Template
{
    u8 pad0[4];
    u16 stats[7];
    u8 pad12[2];
    struct Slot slots[8];
};

struct Obj
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 field_4;
    s16 field_6;
    s16 field_8;
    s16 field_A;
    s16 field_C;
    s16 field_E;
    s16 field_10;
    s16 a[5][4];
    s16 b[5][4];
    u16 stats[7];
    u32 field_70;
    struct Slot slots[8];
};

extern struct Template D_0873FCC8[];

u8 func_080BD304(u8);

void func_080BD488(u8 id, u8 b, struct Obj *obj)
{
    struct Template *t = &D_0873FCC8[id];
    u8 i, j;
    obj->id = id;
    obj->field_1 = b;
    obj->stats[0] = t->stats[0];
    obj->stats[1] = t->stats[1];
    obj->stats[2] = t->stats[2];
    obj->stats[3] = t->stats[3];
    obj->stats[4] = t->stats[4];
    obj->stats[5] = t->stats[5];
    obj->stats[6] = t->stats[6];
    for (i = 0; i < 8; i++)
    {
        obj->slots[i].field_0 = t->slots[i].field_0;
        obj->slots[i].item = t->slots[i].item;
    }
    obj->field_2 = 0;
    obj->field_3 = (1 << func_080BD304(id)) | 1;
    obj->field_4 = 0;
    obj->field_6 = obj->stats[0];
    obj->field_8 = (s16)obj->stats[1] / 2;
    obj->field_A = 0;
    obj->field_C = 0;
    obj->field_E = 0;
    obj->field_10 = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            obj->a[i][j] = 0;
            obj->b[i][j] = 0;
        }
    }
    obj->field_70 = 0;
}
