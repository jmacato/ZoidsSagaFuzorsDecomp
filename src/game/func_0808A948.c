#include "types.h"

struct Zoid
{
    u8 id;
    u8 pad_1;
    u8 pilot;
    u8 pad_3[3];
    s16 hp;
    u8 pad_8[0x5A];
    s16 field_62;
    u8 pad_64[0x30];
};

struct Pilot
{
    u8 id;
    u8 pad_1;
    u8 level;
    u8 pad_3[0x3D];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    struct Pilot pilots[58];
    u8 pad_7A44[0x26];
    u8 team[6];
    u8 pad_7A70[0xD2];
    u8 field_7B42;
};

struct Mgr
{
    u8 pad_0[0x58];
    u32 *obj;
};

extern struct Save D_02020E4C;
extern struct Mgr D_0201F5F8;
extern u8 *D_087A43E0[];
extern const u8 D_080F364C[];
extern const u8 D_080F3650[];
extern const u8 D_080F3654[];
extern const u8 D_080F365C[];
extern const u8 D_080F3664[];
void func_0807BD4C(u8);
void func_0807B748(const u8 *, s8, u8, s16, s16);
void func_0807BA8C(s32, u8, u8, u8, s32);
s32 func_0808A8DC(struct Zoid *);
u8 *func_08082E70(u8);
void func_08077204(u32 *, u8);

void func_0808A948(void)
{
    u8 i;
    struct Zoid *zoid;
    struct Pilot *pilot;
    func_0807BD4C(1);
    for (i = 0; i < 6; i++)
    {
        if (D_02020E4C.team[i] != 0)
        {
            zoid = &D_02020E4C.zoids[D_02020E4C.team[i]];
            if (D_02020E4C.field_7B42 == 0)
            {
                func_0807B748(D_087A43E0[zoid->id], 0, 1, 0, i * 2);
                func_0807B748(D_080F364C, 0, 1, 0xE, i * 2);
                func_0807BA8C(zoid->hp, 4, func_0808A8DC(zoid), 0x12, 1);
                func_0807B748(D_080F3650, 0, 1, 0x10, i * 2 + 1);
                func_0807BA8C(zoid->field_62, 4, 0, 0x12, 1);
            }
            else if (zoid->pilot != 0xFF)
            {
                pilot = &D_02020E4C.pilots[zoid->pilot];
                func_0807B748(func_08082E70(pilot->id), 0, 1, 0, i * 2);
                func_0807B748(D_080F3654, 0, 1, 0xE, i * 2);
                func_0807BA8C(pilot->level, 2, 0, 0x12, 1);
            }
            else
            {
                func_0807B748(func_08082E70(0xFF), 0, 1, 0, i * 2);
                func_0807B748(D_080F365C, 0, 1, 0xE, i * 2);
            }
        }
        else
            func_0807B748(D_080F3664, 0, 1, 0, i * 2);
    }
    func_08077204(D_0201F5F8.obj, D_02020E4C.field_7B42);
    *D_0201F5F8.obj |= 8;
}
