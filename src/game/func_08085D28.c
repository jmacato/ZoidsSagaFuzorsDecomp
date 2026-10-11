#include "types.h"

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x92];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[211];
    u8 pad_7A38[0x32];
    u8 team[6];
};

extern struct Save D_02020E4C;
void func_08085B58(u8, u8, u8, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08085D28(u8 id, u8 **pc)
{
    u32 i;
    for (i = 0; i < 6; i++)
    {
        if (D_02020E4C.team[i] != 0)
        {
            struct Zoid *zoid = &D_02020E4C.zoids[D_02020E4C.team[i]];
            func_08085B58(zoid->field_0, zoid->field_1, (*pc)[1], i, (*pc)[2]);
        }
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
