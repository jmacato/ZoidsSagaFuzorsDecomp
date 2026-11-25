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
    u8 pad0[0x34];
    struct Sprite *sprite;
};

struct Obj
{
    u8 field_0;
    u8 field_1;
};

extern struct Menu D_02020E04;
extern u8 D_087B4CAC[];
extern u8 D_02001480[];
extern u8 D_08424594[];
extern u8 D_084245A0[];

void func_080771F4(struct Sprite *);
struct Sprite *func_08077180(void *, u32, u32, u32, u32, u32, u32, u32, u32);
struct Sprite *func_080771BC(void *, void *, u32, u32, u32, u32, u32, u32, u32);
void func_0807FBDC(u8, u8, u32, u32, void *);
s32 func_0808B53C(struct Obj *);
struct Obj *func_0809A908(u8, u8);

void func_080C2AAC(u8 id)
{
    struct Obj *obj;
    if (D_02020E04.sprite)
        func_080771F4(D_02020E04.sprite);
    if (id == 0xFF)
    {
        D_02020E04.sprite = func_08077180(D_087B4CAC, 0, 0, 0, 0, 0x1C0, 12, 0x60, 0);
        D_02020E04.sprite->x = 0;
        D_02020E04.sprite->y = -20;
    }
    else
    {
        obj = func_0809A908(0, id);
        func_0807FBDC(obj->field_0, obj->field_1, 0x180, 6, D_02001480);
        D_02020E04.sprite = func_080771BC(D_08424594, D_084245A0, 0, 0, 0, 0x180, 6, 0x48, 0);
        D_02020E04.sprite->field_10 = D_02020E04.sprite->field_12 = 0xA0;
        D_02020E04.sprite->x = D_02020E04.sprite->y = -8;
        D_02020E04.sprite->y += func_0808B53C(obj) * 5 / 8;
    }
}
