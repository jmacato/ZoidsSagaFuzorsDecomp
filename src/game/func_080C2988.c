#include "types.h"

struct Sprite
{
    u8 pad0[0xC];
    s16 x;
    s16 y;
    s16 field_10;
    s16 field_12;
};

struct Menu
{
    struct Sprite *sprites[6];
    struct Sprite *icons[6];
};

struct Obj
{
    u8 field_0;
    u8 field_1;
};

struct Template
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad3[0x31];
};

struct Data
{
    u8 pad0[0x2208];
    u8 slots[6];
};

extern struct Data D_02031A0C;
extern struct Menu D_02020E04;
extern s16 D_0873555C[][2];
extern struct Template D_0873FCC8[];
extern u8 D_08424594[];
extern u8 D_084245A0[];
extern u8 D_080F241C[];
extern u8 D_080F2458[];

struct Obj *func_0809A908(u8, u8);
void func_0807FB7C(u8, u8, u32, u32);
struct Sprite *func_080771BC(void *, void *, u32, s32, s32, u32, u32, u32, u32);
s32 func_0808B53C(struct Obj *);

void func_080C2988(u8 i)
{
    struct Obj *obj;
    if (D_02031A0C.slots[i] != 0xFF)
    {
        obj = func_0809A908(0, D_02031A0C.slots[i]);
        func_0807FB7C(obj->field_0, obj->field_1, i << 6, i);
        D_02020E04.sprites[i] = func_080771BC(D_08424594, D_084245A0, 0, D_0873555C[i][0], D_0873555C[i][1], i << 6, i, 0x348, 0);
        D_02020E04.sprites[i]->field_10 = D_02020E04.sprites[i]->field_12 = 0xA0;
        D_02020E04.sprites[i]->y = func_0808B53C(obj) * 5 / 8;
        D_02020E04.icons[i] = func_080771BC(D_080F241C, D_080F2458, D_0873FCC8[obj->field_0].field_2, (s16)(D_0873555C[i][0] + 4), (s16)(D_0873555C[i][1] - 8), 0x32B, 15, 0x248, 0);
    }
    else
    {
        D_02020E04.sprites[i] = D_02020E04.icons[i] = 0;
    }
}
