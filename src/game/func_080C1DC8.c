#include "types.h"

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 id;
    u8 pad1[7];
    s16 field_8;
    u8 padA[0x5A];
    s16 field_64;
    s16 field_66;
    u8 pad68[0xC];
    struct Slot slots[8];
};

struct Result
{
    u8 pad0[4];
    s16 damage;
};

struct Template
{
    u8 field_0;
    u8 field_1;
    u8 type;
    u8 pad3[0x31];
};

extern struct Result D_02031410;
extern struct Template D_0873FCC8[];

u32 func_0809A99C(u8, u8);
struct Obj *func_0809A908(u8, u8);
u8 func_080C1D04(u8, u8, u8);
void func_080C05A4(u8, u8, u8, u8, struct Result *);

u8 func_080C1DC8(u8 g, u8 kind)
{
    struct Obj *obj;
    u8 i, slot;
    s16 hp;

    switch (kind)
    {
    case 0x26:
        if (!func_0809A99C(g, 1) || !func_0809A99C(g, 3) || !func_0809A99C(g, 5))
            return 1;
        for (i = 1; i < 6; i += 2)
        {
            obj = func_0809A908(g, i);
            slot = func_080C1D04(g, i, 0);
            func_080C05A4(g, i, 0xFF, slot, &D_02031410);
            hp = obj->field_8 + obj->field_66;
            if (hp > obj->field_64)
                hp = obj->field_64;
            if (D_02031410.damage > hp)
                break;
        }
        if (i < 6)
            return 4;
        break;
    case 0x27:
        if (!func_0809A99C(g, 0) || !func_0809A99C(g, 2) || !func_0809A99C(g, 4))
            return 1;
        for (i = 0; i < 6; i += 2)
        {
            obj = func_0809A908(g, i);
            slot = func_080C1D04(g, i, 1);
            if (slot == 0xFF)
                return 2;
            func_080C05A4(g, i, 0xFF, slot, &D_02031410);
            hp = obj->field_8 + obj->field_66;
            if (hp > obj->field_64)
                hp = obj->field_64;
            if (D_02031410.damage > hp)
                break;
        }
        if (i < 6)
            return 4;
        break;
    case 0x28:
        obj = func_0809A908(g, 1);
        if (!func_0809A99C(g, 1) || (obj->id < 0x3E || obj->id > 0x3F) || !func_0809A99C(g, 4)
            || D_0873FCC8[func_0809A908(g, 4)->id].type > 2)
            return 1;
        for (slot = 0; slot < 4 && obj->slots[slot].item != 0x51; slot++)
            ;
        if (slot == 4)
            return 3;
        func_080C05A4(g, 1, 0xFF, slot, &D_02031410);
        hp = obj->field_8 + obj->field_66;
        if (hp > obj->field_64)
            hp = obj->field_64;
        if (D_02031410.damage > hp)
            return 4;
        obj = func_0809A908(g, 4);
        slot = func_080C1D04(g, 4, 0);
        func_080C05A4(g, 4, 0xFF, slot, &D_02031410);
        hp = obj->field_8 + obj->field_66;
        if (hp > obj->field_64)
            hp = obj->field_64;
        if (D_02031410.damage > hp)
            return 4;
        break;
    }
    return 0;
}
