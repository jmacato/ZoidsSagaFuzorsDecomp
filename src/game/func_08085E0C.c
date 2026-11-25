#include "types.h"

struct Unit
{
    u8 zoid;
    u8 parts[7];
    u8 pad_8[0x100];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
};

extern struct Game D_02031A0C;
void func_0809F724(u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08085E0C(u8 id, u8 **pc)
{
    func_0809F724((*pc)[1], (*pc)[2]);
    D_02031A0C.units[(*pc)[1]][(*pc)[2]].zoid = 0xFF;
    func_08083C5C(id, -1, 0);
    return 0;
}
