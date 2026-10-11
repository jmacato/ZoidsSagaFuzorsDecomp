#include "types.h"

struct Unit
{
    u8 zoid;
    u8 field_1;
    u8 pilot;
    u8 pad_3[3];
    s16 hp;
    u8 pad_8[0x5A];
    s16 stats[6];
    s16 field_6E;
    s32 field_70;
};

struct Sprite
{
    u8 pad_0[0xE];
    s16 field_E;
    u8 pad_10[4];
    u16 field_14;
    u8 field_16;
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

struct ZoidInfo
{
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0x31];
};

extern u8 *D_087A43E0[];
extern const u8 D_080F36A8[];
extern const u8 D_080F36AC[];
extern struct Save D_02020E4C;
extern u8 D_02001480[];
extern struct ZoidInfo D_0873FCC8[];
void func_0807BD4C(u8);
void func_0807B77C(const u8 *, s32, u8);
void func_0807B748(const u8 *, s32, u8, s32, s32);
u8 *func_08082E70(u8);
u8 func_0808A8DC(struct Unit *);
void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);
void func_0807FBDC(u8, u8, u16, u8, u8 *);
s32 func_0808B53C(struct Unit *);
void func_08077204(u32 *, u8);

s32 func_0808B590(struct Unit *u, u8 row, struct Sprite *spr, u32 *obj, u8 stats)
{
    func_0807BD4C(row);
    func_0807B77C(D_087A43E0[u->zoid], 0, row);
    func_0807B748(D_080F36A8, 0, row, 1, 2);
    if (u->pilot != 0xFF)
        func_0807B77C(func_08082E70(D_02020E4C.pilots[u->pilot].id), 0, row);
    else
        func_0807B77C(func_08082E70(0xFF), 0, row);
    func_0807B77C(D_080F36AC, 0, row);
    if (stats)
    {
        func_0807BA24(u->hp, 4, func_0808A8DC(u), 0x12, row + 1, 4, 0);
        func_0807BA24(u->stats[0], 4, 0, 0x12, row + 1, 9, 0);
        func_0807BA24(u->stats[1], 4, 0, 0x12, row + 1, 9, 1);
        func_0807BA24(u->field_70, 9, 0, 0x12, row + 1, 4, 3);
    }
    func_0807FBDC(u->zoid, u->field_1, spr->field_14, spr->field_16, D_02001480);
    spr->field_E = func_0808B53C(u);
    func_08077204(obj, D_0873FCC8[u->zoid].field_2);
    *obj |= 8;
}
