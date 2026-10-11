#include "types.h"

struct ItemInfo
{
    u16 flags;
    u8 pad_2[2];
};

struct Zoid
{
    u8 id;
    u8 pad_1[5];
    s16 hp;
    u8 pad_8[0x5A];
    s16 max_hp;
};

struct Big
{
    u8 pad_0[0x245];
    u8 field_245;
    u8 pad_246[0x4E92 - 0x246];
    u8 inv[10];
    u8 pad_4E9C[0x4F85 - 0x4E9C];
    u8 item;
};

struct Save
{
    u8 pad_0[0x4E6];
    u8 field_4E6;
};

extern struct Big D_02031A0C;
extern struct Save D_02009480;
extern u8 D_02030F90;
extern u8 D_02036992;
extern u8 D_02030F7E[][2];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u8 D_0200C4D0;
extern u8 D_0200C4BC;
extern const struct ItemInfo D_08759BCC[];
extern const u8 *D_087A5574[];
extern const u8 D_08004DF0[];
extern const u8 D_08004D8E[];
extern const u8 D_08004DE6[];
extern const u8 D_08004E87[];
extern const u8 D_08004DEA[];
extern const u8 D_08004E29[];
extern const u8 D_08004E4D[];
extern const u8 D_08004EC6[];
void func_0807C290(const u8 *);
void func_0808B028(u32);
void func_0807BD4C(u32);
void func_0807B77C(const u8 *, u32, u32);
void func_08075F20(u32);
void func_0807A1A4(void);
void func_08093E24(u32, u8);
s32 func_08093E60(void);
struct Zoid *func_0809A908(u8, u8);
u8 func_0809B834(u32, u8, u32, u32);

s32 func_08096304(void)
{
    u8 i;
    u8 sel;
    s32 who;
    struct Zoid *zoid;
    const struct ItemInfo *info;
    struct Big *big;
    u8 *target;

    D_02030F90 = 0;
    for (i = 1; i < 10; i++)
    {
        if (D_02031A0C.inv[i] != 0)
        {
            D_02030F7E[D_02030F90][0] = i;
            D_02030F7E[D_02030F90][1] = D_02031A0C.inv[i];
            D_02030F90++;
        }
    }
    if (D_02030F90 == 0)
    {
        func_0807C290(D_08004DF0);
        return -1;
    }
    func_0807C290(D_08004D8E);
    func_0808B028(1);
    sel = 0;
    while (1)
    {
        func_0807BD4C(2);
        func_0807B77C(D_087A5574[D_02030F7E[sel][0]], 0, 2);
        func_0807C290(D_08004DE6);
        sel = D_0200C4A0;
        if (D_0200C4A2 == 1)
        {
            info = &D_08759BCC[D_02030F7E[sel][0]];
            if (info->flags & 0x60)
            {
                func_08075F20(0x114);
                func_0807C290(D_08004E87);
                continue;
            }
            func_0807C290(D_08004DEA);
            func_0807C290(D_08004E29);
            func_0807A1A4();
            func_08093E24(0, D_02031A0C.field_245);
            big = &D_02031A0C;
            target = &D_02036992;
            while (1)
            {
                who = func_08093E60();
                if (who != -1)
                {
                    zoid = func_0809A908(0, who);
                    if (((info->flags & 7) && zoid->hp < zoid->max_hp)
                        || ((info->flags & 8) && func_0809B834(0, who, 0x26, 0) != 0xFF)
                        || ((info->flags & 0x10) && func_0809B834(0, who, 0x25, 0) != 0xFF))
                    {
                        D_0200C4D0 = D_02030F7E[sel][0];
                        D_0200C4BC = zoid->id;
                        func_0807C290(D_08004E4D);
                        if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                        {
                            big->item = D_02030F7E[sel][0];
                            *target = who;
                            return 1;
                        }
                        break;
                    }
                    func_08075F20(0x114);
                    func_0807C290(D_08004EC6);
                }
                else
                    break;
            }
            func_0807C290(D_08004D8E);
            func_0808B028(1);
            D_02009480.field_4E6 = sel;
        }
        else if (D_0200C4A2 == 2)
        {
            func_0807C290(D_08004DEA);
            return -1;
        }
    }
}
