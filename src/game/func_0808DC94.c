#include "types.h"

struct Unit
{
    u8 id;
    u8 pad_1;
    u8 level;
    u8 pad_3;
    u32 exp;
    u8 pad_8[0x26];
    u8 zoid;
};

struct Pal
{
    u8 pad_0[0x14];
    u16 field_14;
    u8 field_16;
};

struct Zoid
{
    u8 pad_0[0x3C];
    u8 kind;
    u8 pad_3D[0x57];
};

extern struct Zoid D_02020E4C[];
extern const u8 *D_087A43E0[];
extern const u32 D_08747168[];
extern u8 D_02001480[];
void func_0807BD4C(u8);
const u8 *func_08082E70(u8);
void func_0807B77C(const u8 *, u32, u8);
void func_0807B748(const u8 *, u32, u8, u32, u32);
void func_0807BA24(u32, u32, u32, u32, u8, u32, u32);
void func_0807FF2C(u8, u32, u16, u8, u8 *);

void func_0808DC94(struct Unit *unit, u8 win, struct Pal *pal, u8 detail)
{
    func_0807BD4C(win);
    func_0807B77C(func_08082E70(unit->id), 0, win);
    func_0807B748(D_087A43E0[D_02020E4C[unit->zoid].kind], 0, win, 0, 2);
    if (detail != 0)
    {
        func_0807BA24(unit->level, 2, 0, 0x12, win + 1, 0xB, 0);
        func_0807BA24(unit->exp, 9, 0, 0x12, win + 1, 4, 2);
        if (unit->level < 99)
            func_0807BA24(D_08747168[unit->level], 9, 0, 0x12, win + 1, 4, 3);
        else
            func_0807BA24(0, 9, 0, 0x12, win + 1, 4, 3);
    }
    func_0807FF2C(unit->id, 0, pal->field_14, pal->field_16, D_02001480);
}
