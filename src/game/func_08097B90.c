#include "types.h"

struct Obj
{
    u32 flags;
};

struct Slot
{
    u8 pad_0[4];
    struct Obj *obj;
    u8 pad_8[4];
    s32 x;
    u8 pad_10[4];
    s32 y;
};

struct Item
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x92];
};

struct Big
{
    u8 pad_0[0x10C8];
    struct Item items[2][11];
    u8 pad_1D80[0x4E3D - 0x1D80];
    u8 links[2][9];
};

struct Pos
{
    s32 x;
    s32 pad_4;
    s32 y;
};

struct ItemInfo
{
    u8 pad_0[2];
    u8 type;
    u8 pad_3[0x31];
};

extern struct Big D_02031A0C;
extern struct Slot D_02037B6C[2][6];
extern const struct Pos D_087357D8[];
extern const struct ItemInfo D_0873FCC8[];
void func_0809F7F4(void);
void func_0809FCD4(u32, u8, u8, u32);
void func_08079544(u32, u32);
void func_0807970C(void);
void func_0809F724(u8, u8);
void func_0809F530(u8, u8, u8, u8, u8, u32, u32);
void func_08075F20(u32);
void func_080C8FCC(u32);
void func_080BF170(u8, u8);
void func_0809F9DC(u8);
void func_0809F7AC(u8);

void func_08097B90(u8 side, u8 target)
{
    u8 list[4];
    u8 n;
    u8 i;
    u8 s;
    struct Item *item;
    u8 t;

    func_0809F7F4();
    func_0809FCD4(9, side, target, 0);
    D_02037B6C[side][target].obj->flags |= 0x80000;
    func_08079544(4, 0x10);
    func_0807970C();
    n = 0;
    for (i = 0; i < 9; i++)
    {
        if ((D_02031A0C.links[side][i] >> 4) == target)
        {
            s = D_02031A0C.links[side][i] & 0xF;
            item = &D_02031A0C.items[side][i];
            if (s == target)
                func_0809F724(side, target);
            func_0809F530(item->field_0, item->field_1, D_0873FCC8[item->field_0].type, side, s, 0, 0);
            D_02037B6C[side][s].obj->flags |= 0x80000;
            list[n] = s;
            n++;
        }
    }
    func_08075F20(0xE0);
    func_08079544(3, 0x10);
    func_0809FCD4(2, side, 0, 0);
    for (t = 0; t < 16; t++)
    {
        for (i = 0; i < n; i++)
        {
            D_02037B6C[side][list[i]].x = D_087357D8[side * 6 + target].x + (D_087357D8[side * 6 + list[i]].x - D_087357D8[side * 6 + target].x) * t / 16;
            D_02037B6C[side][list[i]].y = D_087357D8[side * 6 + target].y + (D_087357D8[side * 6 + list[i]].y - D_087357D8[side * 6 + target].y) * t / 16;
        }
        func_080C8FCC(1);
    }
    for (i = 0; i < n; i++)
    {
        D_02037B6C[side][list[i]].x = D_087357D8[side * 6 + list[i]].x;
        D_02037B6C[side][list[i]].y = D_087357D8[side * 6 + list[i]].y;
    }
    for (i = 0; i < n; i++)
        D_02037B6C[side][list[i]].obj->flags &= ~0x80000;
    for (t = 0; t < 16; t++)
        func_080C8FCC(1);
    func_080BF170(side, target);
    func_0809F9DC(side);
    func_0809F7AC(side);
}
