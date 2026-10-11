#include "types.h"

struct Save
{
    u8 pad_0[0x10];
    s32 x;
    s32 y;
    u8 pad_18[0xA];
    u8 field_22;
    u8 pad_23;
    u16 map;
};

extern struct Save D_02020E4C;
extern u16 D_020209D8;
void func_08080CA4(u8);
void *func_08080B00(u8, u8, s32, s32, u8, u8, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08086C9C(u8 id, u8 **pc)
{
    u16 map;
    D_02020E4C.map = map = ((*pc)[2] << 8) | (*pc)[1];
    D_02020E4C.x = (((*pc)[4] << 8) | (*pc)[3]) << 11;
    D_02020E4C.y = (((*pc)[6] << 8) | (*pc)[5]) << 11;
    if (D_020209D8 == map)
    {
        func_08080CA4(0xD);
        func_08080B00(0x8A, 0xD, D_02020E4C.x, D_02020E4C.y, D_02020E4C.field_22, 2, 0xFF, 0);
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
