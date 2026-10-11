#include "types.h"

struct Item
{
    u8 id;
};

struct ItemInfo
{
    u8 flags;
    u8 pad_1;
    u8 type;
    u8 pad_3[0x31];
};

struct Cfg
{
    u8 field_0;
    u8 field_1;
};

extern const struct ItemInfo D_0873FCC8[];
extern struct Cfg D_02020E3C;
extern void *D_02036978;
extern const u8 D_085ECCF0[];
extern const u8 D_085ECCFC[];
void func_080A31D0(u8, u8, u8, u8, void **);
void func_080A03FC(struct Item *);
void func_0807FEDC(u8, u32, u32, u32);
void *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0809309C(void);
void func_080930C0(void);

void func_08093140(u8 side, struct Item *item, u8 *p, u8 arg3)
{
    u8 v;

    if (!(D_0873FCC8[item->id].flags & 0x80))
    {
        v = D_02020E3C.field_1;
    }
    else
    {
        if ((u8)(D_02020E3C.field_1 - 0x10) < 8)
            v = D_02020E3C.field_1;
        else
            v = 0xD;
    }
    func_080A31D0(v, D_0873FCC8[item->id].type, side, arg3, &D_02036978);
    func_080A03FC(item);
    if (*p != 0xFF)
    {
        func_0807FEDC(*p, 0, 0x3DC, 0xF);
        if (side == 0)
            D_02036978 = func_080771BC(D_085ECCF0, D_085ECCFC, 0, -1, 0x72, 0x3DC, 0xF, 8, 0);
        else
            D_02036978 = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 0xC1, 0x72, 0x3DC, 0xF, 8, 0);
    }
    else
    {
        D_02036978 = 0;
    }
    func_0809309C();
    func_080930C0();
}
