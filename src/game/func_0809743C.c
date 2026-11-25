#include "types.h"

struct Obj
{
    u32 flags;
};

struct Slot
{
    u8 pad_0[4];
    struct Obj *obj;
    u8 pad_8[4];
    s32 x;
    u8 pad_10[4];
    s32 y;
};

struct Pos
{
    s32 x;
    s32 pad_4;
    s32 y;
};

struct Group
{
    u8 id;
    u8 pilot;
    u8 pad_2[0x106];
};

struct Zoid
{
    u8 id;
    u8 level;
    u8 pad_2[0x92];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Team
{
    u8 id;
    u8 target;
    u8 pad_2;
    s8 members[5];
};

struct Cmd
{
    u8 field_0;
    u8 leader;
    u8 pad_2[2];
};

struct Big
{
    u8 pad_0[0x244];
    u8 side;
    u8 slot;
    u8 pad_246[2];
    struct Group *group;
    struct Zoid *zoid;
    struct Pilot *pilot;
    u8 pad_254[4];
    struct Group groups[2][7];
    struct Zoid zoids[2][11];
    struct Pilot pilots[2][7];
    u8 pad_2100[0x4DDC - 0x2100];
    struct Team teams[20];
    u8 pad_4E7C[0x4F84 - 0x4E7C];
    struct Cmd cmds[2];
};

struct Kind
{
    u8 pad_0[2];
    u8 type;
    u8 pad_3[0x31];
};

extern struct Big D_02031A0C;
extern struct Slot D_02037B6C[2][6];
extern const struct Pos D_087357D8[];
extern const struct Kind D_0873FCC8[];
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_02030584;
extern u8 D_02001480[];
extern const u8 D_08024407[];
void func_0809F7F4(u8);
void func_0809FCD4(u8, u8, u8, u8);
s32 func_080A00FC(void);
void func_080C8FCC(u32);
s32 func_0809A99C(u8, u8);
void func_0809F724(u8, u8);
void func_08079544(u8, u8);
void func_080BEE40(u8, u8);
void func_08075F20(u32);
void func_08093228(u8);
void func_080A0F00(u32);
void func_0807FF2C(u16, u8, u16, u16, u8 *);
void func_0807B77C(const u8 *, u32, u32);
void func_080A3358(void);
void func_0807970C(void);
void func_0809325C(void);
struct Zoid *func_0809A908(u8, u8);
void func_0809F530(u8, u8, u8, u8, u8, s32, s32);
void func_0809A9F8(u8, u8);
void func_0809F9DC(u8);
void func_0809F7AC(u8);

void func_0809743C(u8 skip)
{
    struct Team *team;
    u8 list[6];
    u8 n;
    u8 i;
    u8 j;
    u8 k;
    struct Zoid *z;

    team = &D_02031A0C.teams[D_02031A0C.cmds[D_02031A0C.side].leader];
    if (skip == 0)
        func_0809F7F4(D_02031A0C.side);
    func_0809FCD4(2, D_02031A0C.side, 0, 0);
    while (!func_080A00FC())
        func_080C8FCC(1);
    D_03000056 = 0x540;
    D_03000058 = 0x10;
    n = 0;
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(D_02031A0C.side, i))
        {
            for (j = 0; j < 4 && ((s8 *)team + j)[3] != -1 && i != ((s8 *)team + j)[3]; j++)
                ;
            if (j == 4 || ((s8 *)team + j)[3] == -1)
            {
                list[n] = i;
                n++;
            }
        }
    }
    for (i = 0; i < n; i++)
        D_02037B6C[D_02031A0C.side][list[i]].obj->flags |= 0x400;
    for (k = 0; k < 16; k++)
    {
        for (i = 0; i < n; i++)
            D_02037B6C[D_02031A0C.side][list[i]].x += D_02031A0C.side == 0 ? 0x200 : -0x200;
        D_03000058 = (k << 8) | (0x10 - k);
        func_080C8FCC(1);
    }
    for (i = 0; i < n; i++)
        func_0809F724(D_02031A0C.side, list[i]);
    func_080C8FCC(1);
    for (i = 0; i < 4 && ((s8 *)team + i)[3] != -1; i++)
        D_02037B6C[D_02031A0C.side][((s8 *)team + i)[3]].obj->flags |= 0x80000;
    func_0809FCD4(9, D_02031A0C.side, team->target, 0);
    func_08079544(4, 0x10);
    for (k = 0; k < 16; k++)
    {
        for (i = 0; i < 4 && ((s8 *)team + i)[3] != -1; i++)
        {
            D_02037B6C[D_02031A0C.side][((s8 *)team + i)[3]].x = D_087357D8[D_02031A0C.side * 6 + ((s8 *)team + i)[3]].x
                + (D_087357D8[D_02031A0C.side * 6 + team->target].x - D_087357D8[D_02031A0C.side * 6 + ((s8 *)team + i)[3]].x) * k / 16;
            D_02037B6C[D_02031A0C.side][((s8 *)team + i)[3]].y = D_087357D8[D_02031A0C.side * 6 + ((s8 *)team + i)[3]].y
                + (D_087357D8[D_02031A0C.side * 6 + team->target].y - D_087357D8[D_02031A0C.side * 6 + ((s8 *)team + i)[3]].y) * k / 16;
        }
        func_080C8FCC(1);
    }
    func_080BEE40(D_02031A0C.side, D_02031A0C.cmds[D_02031A0C.side].leader);
    D_02031A0C.slot = team->target;
    D_02031A0C.group = &D_02031A0C.groups[D_02031A0C.side][D_02031A0C.slot];
    D_02031A0C.zoid = &D_02031A0C.zoids[D_02031A0C.side][D_02031A0C.group->id];
    D_02031A0C.pilot = &D_02031A0C.pilots[D_02031A0C.side][D_02031A0C.group->pilot];
    func_08075F20(0xE0);
    if (!(D_02030584 & 2) || skip != 0)
    {
        func_08093228(1);
        func_080A0F00(0x32D);
        func_08079544(3, 0x10);
        if (D_02031A0C.pilot->id != 0xFF)
            func_0807FF2C(D_02031A0C.pilot->id, 3, 0x3DC, 0xF, D_02001480);
        func_0807B77C(D_08024407, 0, 1);
        func_080A3358();
        func_08079544(4, 0x10);
        func_0807970C();
        func_0809325C();
        for (i = 0; i < n; i++)
            func_0809F724(D_02031A0C.side, list[i]);
        func_0809F7F4(D_02031A0C.side);
    }
    else
    {
        for (i = 0; i < 4 && D_02031A0C.teams[D_02031A0C.cmds[D_02031A0C.side].leader].members[i] != -1; i++)
            func_0809F724(D_02031A0C.side, D_02031A0C.teams[D_02031A0C.cmds[D_02031A0C.side].leader].members[i]);
        z = func_0809A908(D_02031A0C.side, team->target);
        func_0809F530(z->id, z->level, D_0873FCC8[z->id].type, D_02031A0C.side, team->target, 0, 0);
    }
    D_02037B6C[D_02031A0C.side][team->target].obj->flags |= 0x80000;
    func_08079544(3, 0x10);
    func_0809FCD4(2, D_02031A0C.side, 0, 0);
    while (!func_080A00FC())
        func_080C8FCC(1);
    D_02037B6C[D_02031A0C.side][team->target].obj->flags &= ~0x80000;
    for (i = 0; i < n; i++)
    {
        func_0809A9F8(D_02031A0C.side, list[i]);
        if (D_02031A0C.side == 0)
            D_02037B6C[D_02031A0C.side][list[i]].x += 0x2000;
        else
            D_02037B6C[D_02031A0C.side][list[i]].x -= 0x2000;
        D_02037B6C[D_02031A0C.side][list[i]].obj->flags |= 0x400;
    }
    D_03000056 = 0x540;
    D_03000058 = 0x1000;
    for (k = 0; k < 16; k++)
    {
        for (i = 0; i < n; i++)
            D_02037B6C[D_02031A0C.side][list[i]].x += D_02031A0C.side == 0 ? -0x200 : 0x200;
        D_03000058 = ((0x10 - k) << 8) | k;
        func_080C8FCC(1);
    }
    D_03000056 = 0;
    for (i = 0; i < n; i++)
        D_02037B6C[D_02031A0C.side][list[i]].obj->flags &= ~0x400;
    if (skip == 0)
    {
        func_0809F9DC(D_02031A0C.side);
        func_0809F7AC(D_02031A0C.side);
    }
    else
    {
        func_0809F7F4(D_02031A0C.side == 0);
    }
}
