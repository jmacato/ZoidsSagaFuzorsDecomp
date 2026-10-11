#include "types.h"

struct Obj
{
    u8 pad_0[0xE];
    s16 field_E;
    s16 field_10;
    s16 field_12;
};

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x92];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[211];
    u8 pad_7A38[0x32];
    u8 team[6];
};

struct Ctx
{
    struct Obj *objs[6];
    struct Obj *objs2[6];
};

struct ItemInfo
{
    u8 pad_0[2];
    u8 type;
    u8 pad_3[0x31];
};

extern struct Save D_02020E4C;
extern struct Ctx D_02020E04;
extern s16 D_0873555C[][2];
extern const struct ItemInfo D_0873FCC8[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_080F241C[];
extern const u8 D_080F2458[];
void func_0807FB7C(u8, u8, u32, u8);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, s16, s16, u32, u32, u32, u32);
s32 func_0808B53C(struct Zoid *);

void func_08090D98(u8 slot)
{
    struct Zoid *zoid;

    if (D_02020E4C.team[slot] != 0)
    {
        zoid = &D_02020E4C.zoids[D_02020E4C.team[slot]];
        func_0807FB7C(zoid->field_0, zoid->field_1, slot << 6, slot);
        D_02020E04.objs[slot] = func_080771BC(D_08424594, D_084245A0, 0, D_0873555C[slot][0], D_0873555C[slot][1], slot << 6, slot, 0x348, 0);
        D_02020E04.objs[slot]->field_10 = D_02020E04.objs[slot]->field_12 = 0xA0;
        D_02020E04.objs[slot]->field_E = func_0808B53C(zoid) * 5 / 8;
        D_02020E04.objs2[slot] = func_080771BC(D_080F241C, D_080F2458, D_0873FCC8[zoid->field_0].type, D_0873555C[slot][0] + 4, D_0873555C[slot][1] - 8, 0x32B, 0xF, 0x248, 0);
    }
    else
    {
        D_02020E04.objs[slot] = D_02020E04.objs2[slot] = 0;
    }
}
