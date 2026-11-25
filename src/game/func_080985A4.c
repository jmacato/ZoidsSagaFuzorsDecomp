#include "types.h"

struct Obj
{
    u32 flags;
};

struct Slot
{
    u8 flags;
    u8 tile;
    u8 pad_2[2];
    struct Obj *obj;
    struct Obj *icon;
    u8 pad_C[0xC];
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
    u8 *field_250;
    u8 pad_254[0x4D30];
    struct Team teams[8];
};

extern struct Game D_02031A0C;
extern struct Slot D_02037B6C[][6];
extern u16 D_02030584;
extern const struct ZoidInfo D_0873FCC8[];

void func_0809F7CC(u8 side, u8 slot);
void func_0809FCD4(u8 a, u8 side, u8 slot, u8 b);
void func_08079544(u8 a, u8 b);
void func_0807970C(void);
void func_080BF3E4(u8 side, u8 slot, u8 a, u8 b);
void func_08075F20(u16 se);
void func_08093228(u8 a);
void func_080A2D70(u8 a, u8 b, u8 c, u16 d, u8 e);
void func_080A0F00(u16 a);
void func_080A3358(void);
void func_0809325C(void);
void func_0809F724(u8 side, u8 slot);
void func_0809F530(u8 type, u8 a, u8 b, u8 side, u8 slot, s32 c, s32 d);
void func_0809F910(u8 side, u8 slot);
void func_0809F784(u8 side, u8 slot);

void func_080985A4(void)
{
    func_0809F7CC(D_02031A0C.side, D_02031A0C.slot);
    D_02037B6C[D_02031A0C.side][D_02031A0C.slot].obj->flags |= 0x80000;
    func_0809FCD4(9, D_02031A0C.side, D_02031A0C.slot, 0);
    func_08079544(4, 0x10);
    func_0807970C();
    func_080BF3E4(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.field_246, D_02031A0C.teams[D_02031A0C.side].leader);
    func_08075F20(0xDF);
    if (!(D_02030584 & 2))
    {
        func_08093228(1);
        func_080A2D70(*D_02031A0C.field_250, 2, 1, 0x32D, D_02031A0C.side);
        func_080A0F00(0x32D);
        func_08079544(3, 0x10);
        func_080A3358();
        func_08079544(4, 0x10);
        func_0807970C();
        func_0809325C();
        func_0809F7CC(D_02031A0C.side, D_02031A0C.slot);
    }
    else
    {
        func_0809F724(D_02031A0C.side, D_02031A0C.slot);
        func_0809F530(D_02031A0C.zoid->type, D_02031A0C.zoid->level, D_0873FCC8[D_02031A0C.zoid->type].field_2, D_02031A0C.side, D_02031A0C.slot, 0, 0);
    }
    D_02037B6C[D_02031A0C.side][D_02031A0C.slot].obj->flags |= 0x80000;
    func_0809FCD4(5, D_02031A0C.side, D_02031A0C.slot, 0);
    func_08079544(3, 0x10);
    func_0807970C();
    D_02037B6C[D_02031A0C.side][D_02031A0C.slot].obj->flags &= ~0x80000;
    func_0809F910(D_02031A0C.side, D_02031A0C.slot);
    func_0809F784(D_02031A0C.side, D_02031A0C.slot);
}
