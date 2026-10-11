#include "types.h"

struct Obj
{
    u32 flags;
};

struct Team
{
    u8 id;
    u8 pad_1[2];
    s8 members[5];
};

struct Big
{
    u8 pad_0[0x4DDC];
    struct Team teams[12];
    u8 count;
};

struct Slot
{
    u8 pad_0[4];
    struct Obj *a;
    struct Obj *b;
    u8 pad_C[0xC];
};

struct Task
{
    u8 pad_0[0x14];
    s32 field_14;
};

extern struct Big D_02031A0C;
extern struct Slot D_02037B6C[];
extern struct Task D_030025A8;
extern u16 D_03000056;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u8 D_0200C4BC;
extern const u8 *D_087A43E0[];
extern const u8 D_08003F39[];
extern const u8 D_08003F61[];
extern const u8 D_08003F6C[];
extern const u8 D_08003F74[];
extern const u8 D_08003F70[];
void func_0809FCD4(u32, u32, u32, u32);
void func_08096548(void);
void func_08075DA8(u32, void (*)(void));
void func_0807C290(const u8 *);
void func_0807BEF4(u32, const u8 *, u32);
u32 func_0809A99C(u8, u8);
void func_08075E28(u8);

s32 func_080965A8(void)
{
    u8 sel;
    u8 i;
    u8 j;
    s32 result;

    D_030025A8.field_14 = 0xB4;
    func_0809FCD4(2, 0, 0, 0);
    func_08075DA8(4, func_08096548);
    func_0807C290(D_08003F39);
    func_0807C290(D_08003F61);
    for (i = 0; i < D_02031A0C.count; i++)
        func_0807BEF4(1, D_087A43E0[D_02031A0C.teams[i].id], 0);
    sel = 0;
    while (1)
    {
        for (i = 0; i < 6; i++)
        {
            if (func_0809A99C(0, i))
            {
                for (j = 0; j < 4 && D_02031A0C.teams[sel].members[j] != -1; j++)
                {
                    if (D_02031A0C.teams[sel].members[j] == i)
                    {
                        D_02037B6C[i].a->flags &= ~0x400;
                        break;
                    }
                }
                if (j == 4 || D_02031A0C.teams[sel].members[j] == -1)
                    D_02037B6C[i].a->flags |= 0x400;
                D_02037B6C[i].b->flags |= 0x400;
            }
        }
        func_0807C290(D_08003F6C);
        sel = D_0200C4A0;
        if (D_0200C4A2 == 1)
        {
            D_0200C4BC = D_02031A0C.teams[sel].id;
            func_0807C290(D_08003F74);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                result = sel;
                break;
            }
        }
        else if (D_0200C4A2 == 2)
        {
            result = -1;
            break;
        }
    }
    func_0807C290(D_08003F70);
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(0, i))
        {
            D_02037B6C[i].a->flags &= ~0x400;
            D_02037B6C[i].b->flags &= ~0x400;
        }
    }
    func_08075E28(4);
    D_03000056 = 0;
    D_030025A8.field_14 = 0x78;
    return result;
}
