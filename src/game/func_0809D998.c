#include "types.h"

struct Zoid
{
    u8 type;
    u8 field_1;
    u8 pilot;
    u8 field_3;
    u16 flags;
    u8 pad_6[0x8E];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    u8 pad_6BC4[0x6BC4 - 0x3C - 186 * 0x94];
    struct Pilot pilots[58];
    u8 pad_7A44[0x7A6A - 0x6BC4 - 58 * 0x40];
    u8 team[6];
};

struct ZoidInfo
{
    u8 flags;
    u8 field_1;
    u8 field_2;
    u8 pad_3[0x31];
};

struct Party
{
    u32 flags;
    u8 pad_4[0xC];
    u16 field_10;
    u8 pad_12[0x4BE];
};

struct Script
{
    u8 field_0;
    u8 pad_1[0x10E7];
    u8 field_10E8;
    u8 pad_10E9[0xC];
    u8 name[1];
};

struct Clock
{
    u8 pad_0[8];
    u32 limit;
};

extern struct Save D_02020E4C;
extern struct Zoid D_02020E88[];
extern const struct ZoidInfo D_0873FCC8[];
extern struct Clock D_02020E3C;
extern const u8 *D_0200C4A8;
extern struct Party D_02009480[];
extern struct Script D_0201F6DC;
extern u8 *D_087A464C[];
extern u16 D_0203198C[];
extern const u8 D_08014BB1[];
extern const u8 D_08014BFC[];
extern const u8 D_08014BDB[];
extern const u8 D_08014C34[];
extern const u8 D_08014B81[];
extern const u8 D_08014B93[];

s32 func_080BD2AC(u8, u8);
u32 func_0807F558(void);
void func_0808330C(u8 a, u8 b, u8 show);
void func_080834C8(void);
s32 func_080C8F1C(u8 *, u8 *);
void func_080C8F78(u8 *, u8 *);
void func_0807C290(const u8 *);
void func_0807BD4C(u8);
void func_0807B748(u8 *, s32, s32, s32, s32);
void func_0807B77C(const void *, u32, u32);

s32 func_0809D998(u8 cond)
{
    u8 n, i, a, b, found;
    struct Zoid *z;

    switch (cond)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 22:
        n = 0;
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0)
                n++;
        }
        switch (cond)
        {
        case 1:
            if (n > 1)
                return 0;
            break;
        case 2:
            if (n > 2)
                return 0;
            break;
        case 3:
            if (n > 3)
                return 0;
            break;
        case 4:
            if (n > 4)
                return 0;
            break;
        case 22:
            if (n != 2)
                return 0;
            break;
        }
        break;
    case 5:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].field_2 != 0)
                return 0;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].field_2 > 1)
                return 0;
        }
        break;
    case 7:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].field_2 != 1)
                return 0;
        }
        break;
    case 8:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].field_2 > 2)
                return 0;
        }
        break;
    case 9:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].field_2 > 1)
                break;
        }
        if (i == 6)
            return 0;
        break;
    case 10:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].field_2 > 2)
                break;
        }
        if (i == 6)
            return 0;
        break;
    case 11:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && (D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].flags & 0x80))
                return 0;
        }
        break;
    case 12:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && !(D_0873FCC8[D_02020E4C.zoids[D_02020E4C.team[i]].type].flags & 0x80))
                return 0;
        }
        break;
    case 13:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 1) && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 10))
                return 0;
        }
        break;
    case 14:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 6))
                return 0;
        }
        break;
    case 15:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 7))
                return 0;
        }
        break;
    case 21:
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] != 0 && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 1) && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 6) && !func_080BD2AC(D_02020E4C.zoids[D_02020E4C.team[i]].type, 7))
                return 0;
        }
        break;
    case 20:
        if (func_0807F558() > D_02020E3C.limit)
            return 0;
        break;
    case 23:
        for (i = 1, found = 0; i < 186; i++)
        {
            z = &D_02020E88[i];
            if (z->type != 0 && z->pilot != 0xFF && !(z->flags & 2))
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            for (i = 0, a = 0, b = 0; i < 6; i++)
            {
                if (D_02020E4C.team[i] != 0)
                {
                    if (D_02020E4C.pilots[D_02020E4C.zoids[D_02020E4C.team[i]].pilot].id == 0x12)
                        a++;
                    b++;
                }
            }
        }
        if (!found || a != 1 || b != 1)
        {
            if (found)
                D_0200C4A8 = D_08014BB1;
            else
                D_0200C4A8 = D_08014BFC;
            func_0808330C(0x12, 0, 0);
            func_080834C8();
            if (func_080C8F1C(D_087A464C[0x12], D_0201F6DC.name) == 0)
            {
                D_02009480[1].flags |= 0x800;
                D_02009480[1].field_10 = 2;
                func_0807C290(D_08014B81);
            }
            else
            {
                func_080C8F78(D_0201F6DC.name, D_087A464C[0x12]);
                D_0203198C[0] = 1;
                D_0203198C[1] = 10;
                D_02009480[1].flags |= 0x800;
                func_0807BD4C(1);
                func_0807B748(D_087A464C[0x12], 2, 1, 0, 0);
                func_0807B77C(D_0203198C, 0, 1);
                func_0807C290(D_08014B93);
            }
            if (found)
                return 0;
        }
        else
        {
            D_0200C4A8 = D_08014BDB;
            goto show;
        }
        D_0200C4A8 = D_08014C34;
    show:
        func_0808330C(0x12, 3, 0);
        func_080834C8();
        if (func_080C8F1C(D_087A464C[0x12], D_0201F6DC.name) == 0)
        {
            D_02009480[1].flags |= 0x800;
            D_02009480[1].field_10 = 2;
            func_0807C290(D_08014B81);
        }
        else
        {
            func_080C8F78(D_0201F6DC.name, D_087A464C[0x12]);
            D_0203198C[0] = 1;
            D_0203198C[1] = 10;
            D_02009480[1].flags |= 0x800;
            func_0807BD4C(1);
            func_0807B748(D_087A464C[0x12], 2, 1, 0, 0);
            func_0807B77C(D_0203198C, 0, 1);
            func_0807C290(D_08014B93);
        }
        break;
    default:
        return 2;
    }
    return 1;
}
