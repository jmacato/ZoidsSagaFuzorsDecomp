#include "types.h"

struct Zoid
{
    u8 kind;
    u8 pad_1;
    u8 pilot;
    u8 pad_3[3];
    s16 field_6;
    u8 pad_8[0x5A];
    s16 field_62;
    s16 field_64;
};

struct Obj
{
    u32 flags;
};

struct Ctx
{
    u8 pad_0[0x30];
    struct Obj *obj;
};

struct Cfg
{
    u8 field_0;
};

struct ItemInfo
{
    u8 pad_0[2];
    u8 type;
    u8 pad_3[0x31];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Save
{
    u8 pad_0[0x6BC4];
    struct Pilot pilots[58];
};

struct Big
{
    u8 pad_0[0x1D80];
    struct Pilot cells[14];
};

extern struct Ctx D_02020E04;
extern struct Cfg D_02020E3C;
extern struct Save D_02020E4C;
extern struct Big D_02031A0C;
extern const struct ItemInfo D_0873FCC8[];
extern const u8 *D_087A43E0[];
extern const u8 D_080036B8[];
extern const u8 D_080036D1[];
extern const u8 D_080036F5[];
extern const u8 D_08003714[];
extern const u8 D_08003737[];
extern const u8 D_080F2354[];
extern const u8 D_080F2390[];
void func_0807C290(const u8 *);
void func_0807B748(const u8 *, u32, u32, u32, u32);
u8 func_0808A8DC(struct Zoid *);
void func_0807BA24(s32, u32, u32, u32, u32, u32, u32);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_08077204(struct Obj *, u32);
const u8 *func_08082E70(u8);
const u8 *func_08082EAC(u8, u32);
void func_0807B77C(const u8 *, u32, u32);
void func_080771F4(struct Obj *);
void func_0807A1A4(void);

void func_08090BB0(struct Zoid *zoid, u32 mode, u8 side)
{
    const u8 *name;
    u8 id;

    if (zoid != 0)
    {
        func_0807C290(D_080036B8);
        func_0807B748(D_087A43E0[zoid->kind], 0, 5, 0, 0);
        if (D_02020E3C.field_0 != 2)
            func_0807BA24(zoid->field_6, 4, func_0808A8DC(zoid), 0x12, 5, 4, 2);
        else
            func_0807BA24(zoid->field_62, 4, 0, 0x12, 5, 4, 2);
        func_0807BA24(zoid->field_62, 4, 0, 0x12, 5, 9, 2);
        func_0807BA24(zoid->field_64, 4, 0, 0x12, 5, 9, 3);
        if (D_02020E04.obj == 0)
        {
            D_02020E04.obj = func_080771BC(D_080F2354, D_080F2390, D_0873FCC8[zoid->kind].type, 0x74, 0x84, 0x30D, 0xF, 8, 0);
        }
        else
        {
            func_08077204(D_02020E04.obj, D_0873FCC8[zoid->kind].type);
            D_02020E04.obj->flags |= 8;
        }
        if (zoid->pilot != 0xFF)
        {
            if (side == 0)
            {
                id = D_02020E4C.pilots[zoid->pilot].id;
            }
            else
            {
                id = D_02031A0C.cells[zoid->pilot].id;
                name = func_08082EAC(id, 0);
                goto print;
            }
        }
        else
        {
            id = 0xFF;
        }
        name = func_08082E70(id);
    print:
        func_0807B77C(name, 0, 6);
    }
    else
    {
        func_0807C290(D_080036D1);
        switch (mode)
        {
        case 0:
            func_0807C290(D_080036F5);
            break;
        case 1:
            func_0807C290(D_08003714);
            break;
        case 2:
            func_0807C290(D_08003737);
            break;
        }
        if (D_02020E04.obj != 0)
        {
            func_080771F4(D_02020E04.obj);
            D_02020E04.obj = 0;
        }
        func_0807B77C(func_08082E70(0), 0, 6);
    }
    func_0807A1A4();
}
