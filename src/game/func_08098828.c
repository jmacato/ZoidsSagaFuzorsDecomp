#include "types.h"

struct Slot
{
    u8 flags;
    u8 tile;
    s16 field_2;
    u8 pad_4[0x14];
};

struct Zoid
{
    u8 type;
    u8 level;
};

struct ZoidInfo
{
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0x31];
};

struct Team
{
    u8 field_0;
    u8 leader;
    u8 field_2;
    u8 field_3;
};

struct Game
{
    u8 pad_0[0x244];
    u8 side;
    u8 slot;
    u8 field_246;
    u8 pad_247[5];
    struct Zoid *zoid;
    u8 pad_250[0x4D34];
    struct Team teams[8];
};

extern struct Game D_02031A0C;
extern struct Slot D_02037B6C[][6];
extern u16 D_02030584;
extern const struct ZoidInfo D_0873FCC8[];

void func_08079544(u8 a, u8 b);
void func_0807970C(void);
void func_08093228(u8 a);
void func_080BF3E4(u8 side, u8 slot, u8 a, u8 b);
void func_080969A8(void (*fn)(s32), u8 arg);
void func_0809874C(s32 won);
void func_08075E28(u8 id);
void func_080A1204(void);
void func_0809325C(void);
void func_0809F7CC(u8 side, u8 slot);
void func_0809F724(u8 side, u8 slot);
void func_0809F530(u8 type, u8 a, u8 b, u8 side, u8 slot, s32 c, s32 d);
void func_08075F20(u16 se);
void func_080C8FCC(u32 frames);
void func_0809F910(u8 side, u8 slot);
void func_0809F784(u8 side, u8 slot);

void func_08098828(u8 won)
{
    if (!(D_02030584 & 2))
    {
        func_08079544(2, 0x10);
        func_0807970C();
        func_08093228(1);
        if (D_02031A0C.side == 0)
            func_08079544(9, 0);
        else
            func_08079544(0xA, 0);
        func_0807970C();
        func_080BF3E4(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.field_246, D_02031A0C.teams[D_02031A0C.side].leader);
        func_080969A8(func_0809874C, won);
        func_08079544(0x12, 0);
        func_0807970C();
        func_08075E28(4);
        func_080A1204();
        func_0809325C();
        func_08079544(1, 0x10);
        func_0807970C();
        return;
    }
    func_0809F7CC(D_02031A0C.side, D_02031A0C.slot);
    func_080BF3E4(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.field_246, D_02031A0C.teams[D_02031A0C.side].leader);
    if (won == 0)
    {
        func_0809F724(D_02031A0C.side, D_02031A0C.slot);
        func_0809F530(D_02031A0C.zoid->type, D_02031A0C.zoid->level, D_0873FCC8[D_02031A0C.zoid->type].field_2, D_02031A0C.side, D_02031A0C.slot, 0, 0);
        D_02037B6C[D_02031A0C.side][D_02031A0C.slot].field_2 = 0;
        func_08075F20(0xE1);
        while (D_02037B6C[D_02031A0C.side][D_02031A0C.slot].field_2 > -0x1000)
        {
            D_02037B6C[D_02031A0C.side][D_02031A0C.slot].field_2 -= 0x80;
            func_080C8FCC(1);
        }
        func_0809F910(D_02031A0C.side, D_02031A0C.slot);
        func_0809F784(D_02031A0C.side, D_02031A0C.slot);
    }
    else
    {
        func_08075F20(0xE2);
        while (D_02037B6C[D_02031A0C.side][D_02031A0C.slot].field_2 < 0)
        {
            D_02037B6C[D_02031A0C.side][D_02031A0C.slot].field_2 += 0x80;
            func_080C8FCC(1);
        }
        func_0809F724(D_02031A0C.side, D_02031A0C.slot);
        func_0809F530(D_02031A0C.zoid->type, D_02031A0C.zoid->level, D_0873FCC8[D_02031A0C.zoid->type].field_2, D_02031A0C.side, D_02031A0C.slot, 0, 0);
        func_0809F910(D_02031A0C.side, D_02031A0C.slot);
        func_0809F784(D_02031A0C.side, D_02031A0C.slot);
    }
}
