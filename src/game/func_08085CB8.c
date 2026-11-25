#include "types.h"

struct Pilot
{
    u8 id;
    u8 pad_1[0x2D];
    u8 zoid;
    u8 pad_2F[0x11];
};

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x92];
};

extern struct Pilot D_02027A10[];
extern struct Zoid D_02020E88[];
void func_08085B58(u8, u8, u8, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08085CB8(u8 id, u8 **pc)
{
    u32 i;
    struct Pilot *pilot;
    for (i = 1; i <= 0x34; i++)
    {
        pilot = &D_02027A10[i];
        if (pilot->id == (*pc)[1])
            break;
    }
    if (i <= 0x34 && pilot->zoid != 0)
    {
        struct Zoid *zoid = &D_02020E88[pilot->zoid];
        func_08085B58(zoid->field_0, zoid->field_1, (*pc)[2], (*pc)[3], (*pc)[4]);
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
