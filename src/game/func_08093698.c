#include "types.h"

struct Zoid
{
    u8 id;
    u8 level;
    u8 pad_2[2];
    u16 flags;
    s16 hp;
    s16 field_8;
    u8 pad_A[0x58];
    s16 stats[6];
    u8 pad_6E[0x26];
};

struct Group
{
    u8 id;
    u8 pilot;
    u8 pad_2[0x106];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Big
{
    u8 pad_0[0x258];
    struct Group groups[2][7];
    struct Zoid zoids[2][11];
    struct Pilot pilots[2][7];
    u8 pad_2100[0x4E9C - 0x2100];
    s8 side;
    s8 slot;
};

struct Status
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[4];
    s16 value;
};

struct Task
{
    u8 pad_0[0x14];
    s32 field_14;
};

extern struct Big D_02031A0C;
extern struct Zoid D_02031254;
extern struct Status D_02031408;
extern struct Task D_030025A8;
extern const u8 D_08004147[];
extern const u8 D_080041A7[];
extern const u8 D_080F4258[];
extern const u8 D_080F4274[];
extern const u8 D_080F427C[];
extern const u8 D_080F4280[];
extern const u8 D_080F4288[];
extern const u8 D_080F4294[];
extern const u8 D_080F42A0[];
extern const u8 D_080F42B0[];
extern const u8 D_080F42B8[];
extern const u8 D_080F42C0[];
extern const u8 D_080F42CC[];
extern const u8 D_080F42D0[];
extern const u8 D_080F42DC[];
extern const u8 D_080F42EC[];
void func_0809BCA4(u8, u8);
void func_0809FCD4(u32, u8, u8, u32);
void func_0807C290(const u8 *);
void func_0807B748(const u8 *, u32, u32, u32, u32);
const u8 *func_080BF554(u8, u8, u8);
void func_080BE39C(u8, u8, struct Zoid *);
u8 func_0808A8DC(struct Zoid *);
u8 func_0808A928(s16, s16);
void func_0807BA24(s32, u32, u8, u32, u32, u32, u32);
u8 func_0809B834(u8, u8, u32, struct Status *);
void func_0807B77C(const u8 *, u32, u32);
void func_0807BA8C(s32, u32, u32, u32, u32);
void func_0807BD4C(u32);
const u8 *func_08082EAC(u8, u8);
void func_0807A1A4(void);
u8 func_0809BD70(u32);

void func_08093698(u8 side, u8 slot)
{
    s32 r;
    u8 done;
    struct Group *group;
    struct Zoid *zoid;

    func_0809BCA4(side, slot);
    func_0809FCD4(5, D_02031A0C.side, D_02031A0C.slot, 1);
    D_030025A8.field_14 = 0xB4;
    func_0807C290(D_08004147);
    r = 0;
    done = 0;
    do
    {
        switch (r)
        {
        case 1:
        case 2:
            func_0807C290(D_080041A7);
            D_030025A8.field_14 = 0x78;
            return;
        case 0:
            group = &D_02031A0C.groups[D_02031A0C.side][D_02031A0C.slot];
            zoid = &D_02031A0C.zoids[D_02031A0C.side][group->id];
            func_0807B748(D_080F4258, 0, 2, 0, 0);
            func_0807B748(func_080BF554(D_02031A0C.side, zoid->id, zoid->level), 0, 2, 0, 0);
            func_080BE39C(D_02031A0C.side, D_02031A0C.slot, &D_02031254);
            if (!(zoid->flags & 0x10))
            {
                func_0807BA24(zoid->hp, 4, func_0808A8DC(zoid), 0x12, 2, 4, 3);
                func_0807BA24(zoid->stats[0], 4, func_0808A928(zoid->stats[0], D_02031254.stats[0]), 0x12, 2, 9, 3);
                func_0807BA24(zoid->field_8, 4, 0, 0x12, 2, 4, 4);
                func_0807BA24(zoid->stats[1], 4, func_0808A928(zoid->stats[1], D_02031254.stats[1]), 0x12, 2, 9, 4);
                func_0807BA24(zoid->stats[2], 4, func_0808A928(zoid->stats[2], D_02031254.stats[2]), 0x12, 2, 9, 5);
                func_0807BA24(zoid->stats[3], 4, func_0808A928(zoid->stats[3], D_02031254.stats[3]), 0x12, 2, 9, 7);
                func_0807BA24(zoid->stats[4], 4, func_0808A928(zoid->stats[4], D_02031254.stats[4]), 0x12, 2, 9, 8);
                func_0807BA24(zoid->stats[5], 4, func_0808A928(zoid->stats[5], D_02031254.stats[5]), 0x12, 2, 9, 9);
            }
            else
            {
                func_0807B748(D_080F4274, 0, 2, 4, 3);
                func_0807B748(D_080F4274, 0, 2, 9, 3);
                func_0807B748(D_080F4274, 0, 2, 4, 4);
                func_0807B748(D_080F4274, 0, 2, 9, 4);
                func_0807B748(D_080F4274, 0, 2, 9, 5);
                func_0807B748(D_080F4274, 0, 2, 9, 7);
                func_0807B748(D_080F4274, 0, 2, 9, 8);
                func_0807B748(D_080F4274, 0, 2, 9, 9);
            }
            if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x22, &D_02031408) != 0xFF)
            {
                func_0807B748(D_080F427C, 0, 2, 0, 0xB);
                func_0807B77C(D_080F4280, 2, 2);
                func_0807BA8C(D_02031408.value, 1, 2, 0x14, 2);
            }
            else
            {
                func_0807B748(D_080F4288, 0, 2, 0, 0xB);
            }
            if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x23, &D_02031408) != 0xFF)
            {
                func_0807B748(D_080F427C, 0, 2, 0, 0xC);
                func_0807B77C(D_080F4294, 2, 2);
                func_0807BA8C(D_02031408.value, 3, 2, 0x12, 2);
            }
            else
            {
                func_0807B748(D_080F42A0, 0, 2, 0, 0xC);
            }
            if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x26, 0) != 0xFF)
            {
                func_0807B748(D_080F427C, 0, 2, 0, 0xD);
                func_0807B77C(D_080F42B0, 1, 2);
            }
            else
            {
                func_0807B748(D_080F42B8, 0, 2, 0, 0xD);
            }
            if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x25, &D_02031408) != 0xFF)
            {
                func_0807B748(D_080F427C, 0, 2, 0, 0xE);
                func_0807B77C(D_080F42C0, 1, 2);
                func_0807BA8C(D_02031408.value, 3, 1, 0x12, 2);
                func_0807B77C(D_080F42CC, 1, 2);
            }
            else
            {
                func_0807B748(D_080F42A0, 0, 2, 0, 0xE);
            }
            if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x10, &D_02031408) != 0xFF)
            {
                func_0807B748(D_080F427C, 0, 2, 0, 0xF);
                func_0807B77C(D_080F42D0, 1, 2);
                func_0807BA8C(D_02031408.value, 4, 1, 0x12, 2);
            }
            else
            {
                func_0807B748(D_080F42A0, 0, 2, 0, 0xF);
            }
            if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x2A, &D_02031408) != 0xFF)
            {
                func_0807B748(D_080F42DC, 2, 2, 0, 0x11);
                func_0807BA8C(D_02031408.field_1, 1, 0, 0x10, 2);
                func_0807BD4C(3);
                func_0807B748(D_080F42EC, 0, 3, 0, 0);
            }
            else
            {
                func_0807B748(D_080F42A0, 0, 2, 0, 0x11);
                func_0807BD4C(3);
                func_0807B748(func_08082EAC(D_02031A0C.pilots[D_02031A0C.side][group->pilot].id, D_02031A0C.side), 0, 3, 0, 0);
            }
            func_0807A1A4();
            func_0809FCD4(5, D_02031A0C.side, D_02031A0C.slot, 0);
            break;
        }
        r = func_0809BD70(1);
    } while (done == 0);
}
