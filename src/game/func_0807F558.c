#include "types.h"

struct Pilot
{
    u8 pad0[3];
    u8 flags;
    u8 pad4[0x3A];
    u8 skill;
    u8 pad3F;
};

struct Zoid
{
    u8 pad0[2];
    u8 pilot;
    u8 pad3[0x91];
};

struct Save
{
    u8 pad0[0x3C];
    struct Zoid zoids[186];
    struct Pilot pilots[58];
    u8 pad7A44[0x26];
    u8 team[6];
};

struct Unit
{
    u8 pad0[0x62];
    s16 stat[5];
    s16 field_6C;
    u8 pad6E[6];
    struct
    {
        u16 field_0;
        u16 id;
    } parts[8];
};

struct Part
{
    u8 flags;
    u8 slots;
    u16 type;
    u8 pad4[8];
    s16 field_C;
    s16 field_E;
    s16 field_10;
    s16 field_12;
};

struct Skill
{
    u8 pad0[8];
    s16 bonus;
    u8 padA[2];
};

extern struct Save D_02020E4C;
extern struct Unit D_020312E8;
extern struct Pilot D_020313BC;
extern struct Part D_02031470;
extern const struct Skill D_0874731C[];

void func_080C8B7C(const void *, void *, u32);
void func_080BDDE4(struct Unit *, struct Pilot *, u8);
u32 func_0807F540(s16);
u32 func_0807F52C(s32);
s32 func_0807F544(s16);
s32 func_080BD2F4(s32, s16);
void func_080C0178(struct Unit *, struct Pilot *, u8, u8, struct Part *);
u8 func_080C0008(struct Part *);

u32 func_0807F558(void)
{
    u32 total;
    struct Pilot *pilot;
    u8 i, j, k, n, bits;
    struct Zoid *zoid;
    struct Part *part;
    s16 v;
    u8 flag;
    u32 value;

    total = 0;
    for (i = 0; i < 6; i++)
    {
        if (D_02020E4C.team[i] == 0)
            continue;
        zoid = &D_02020E4C.zoids[D_02020E4C.team[i]];
        func_080C8B7C(zoid, &D_020312E8, 0x04000025);
        if (zoid->pilot != 0xFF)
        {
            func_080C8B7C(&D_02020E4C.pilots[zoid->pilot], &D_020313BC, 0x04000010);
            if (D_020313BC.skill)
                D_020313BC.flags |= 0x80;
            pilot = &D_020313BC;
        }
        else
        {
            pilot = 0;
        }
        func_080BDDE4(&D_020312E8, pilot, 1);
        total += func_0807F540(D_020312E8.stat[0]);
        total += func_0807F540(D_020312E8.stat[1]);
        total += func_0807F540(D_020312E8.stat[2]);
        total += func_0807F540(D_020312E8.stat[3]);
        total += func_0807F540(D_020312E8.stat[4]);
        total += func_0807F52C(D_020312E8.field_6C);
        for (j = 0; j < 8; j++)
        {
            if (D_020312E8.parts[j].id == 0)
                continue;
            func_080C0178(&D_020312E8, pilot, j, 0, &D_02031470);
            flag = D_02031470.flags & 1;
            part = &D_02031470;
            if (!flag)
            {
                if (pilot && (D_020313BC.flags & 0x80))
                    part->field_C += func_080BD2F4(part->field_C, D_0874731C[D_020313BC.skill].bonus);
                v = D_02031470.field_E;
                if (D_02031470.field_E <= 0)
                    v = 1;
                else if (D_02031470.field_E > 99)
                    v = 99;
                value = func_080BD2F4(func_0807F544(D_02031470.field_C), v);
                v = D_02031470.field_12;
                if (D_02031470.field_12 <= 0)
                    v = 1;
                else if (D_02031470.field_12 > 99)
                    v = 99;
                value += func_080BD2F4(func_0807F544(D_02031470.field_10), v);
                n = func_080C0008(&D_02031470);
                for (k = 1; k <= n; k++)
                    total += value / k;
            }
            else if (part->field_10 == 0)
            {
                if (part->type != 18)
                {
                    total += func_0807F540(part->field_C) * func_080C0008(part);
                    total += func_0807F540(part->field_E) * func_080C0008(part);
                }
                else
                {
                    total += 50000;
                }
            }
            else if (part->type == 1 && part->slots != 0)
            {
                for (k = 0, bits = 0; k < 4; k++)
                {
                    if ((part->slots >> k) & 1)
                        bits++;
                }
                total += func_0807F52C(part->field_C * bits / 4);
            }
        }
        if (total > 999999998)
            return 999999999;
    }
    return total;
}
