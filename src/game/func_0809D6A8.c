#include "types.h"

struct Unit
{
    u8 zoid;
    u8 parts[7];
    u8 pad_8[0x100];
};

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u16 flags;
    u8 pad_6[0x8E];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
    u8 pad_10C8[0x3EA8];
    u8 lost[6];
    u8 lostCount;
};

extern struct Game D_02031A0C;

struct Zoid *func_0809A908(u8 side, u8 slot);
void func_0809ACCC(u8 side, u8 slot, u8 arg);

void func_0809D6A8(u8 side, u8 slot)
{
    struct Zoid *zoid = func_0809A908(side, slot);
    zoid->flags |= 2;
    func_0809ACCC(side, slot, 0xFF);
    if (side == 1 && !(zoid->flags & 0x10))
    {
        D_02031A0C.lost[D_02031A0C.lostCount] = D_02031A0C.units[1][slot].zoid;
        D_02031A0C.lostCount++;
    }
}
