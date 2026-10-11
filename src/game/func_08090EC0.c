#include "types.h"

struct Obj
{
    u8 pad_0[0xC];
    s16 field_C;
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

struct Ctx
{
    u8 pad_0[0x34];
    struct Obj *obj;
};

extern struct Ctx D_02020E04;
extern struct Zoid D_02020E88[];
extern u8 D_02001480[];
extern const u8 D_087B4CAC[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
void func_080771F4(struct Obj *);
struct Obj *func_08077180(const u8 *, u32, u32, u32, u32, u32, u32, u32, u32);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0807FBDC(u8, u8, u32, u32, u8 *);
s32 func_0808B53C(struct Zoid *);

void func_08090EC0(u8 id)
{
    struct Zoid *zoid;

    if (D_02020E04.obj != 0)
        func_080771F4(D_02020E04.obj);
    if (id == 0)
    {
        D_02020E04.obj = func_08077180(D_087B4CAC, 0, 0, 0, 0, 0x1C0, 0xC, 0x60, 0);
        D_02020E04.obj->field_C = 0;
        D_02020E04.obj->field_E = -20;
        return;
    }
    zoid = &D_02020E88[id];
    func_0807FBDC(zoid->field_0, zoid->field_1, 0x180, 6, D_02001480);
    D_02020E04.obj = func_080771BC(D_08424594, D_084245A0, 0, 0, 0, 0x180, 6, 0x48, 0);
    D_02020E04.obj->field_10 = D_02020E04.obj->field_12 = 0xA0;
    D_02020E04.obj->field_C = D_02020E04.obj->field_E = -8;
    D_02020E04.obj->field_E += func_0808B53C(zoid) * 5 / 8;
}
