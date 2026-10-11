#include "types.h"

struct Pair
{
    u16 a;
    u16 b;
};

struct Entry
{
    u8 pad_0[0x14];
    struct Pair vals[8];
};

extern struct Entry D_0873FCC8[];
void func_08086454(u16);
void func_08083C5C(u8, s32, s32);

s32 func_08086504(u8 id, u8 **pc)
{
    func_08086454(D_0873FCC8[(*pc)[1]].vals[(*pc)[2]].b);
    func_08083C5C(id, -1, 0);
    return 0;
}
