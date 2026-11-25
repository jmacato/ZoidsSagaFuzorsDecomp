#include "types.h"

struct Save
{
    u8 pad_0[0x20];
    u8 field_20;
};

struct Map
{
    u8 pad_0[0x424];
    void *current;
};

extern struct Save D_02020E4C;
extern struct Map D_020209D8;
void *func_08080B00(u8, u8, s32, s32, u8, u8, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08086C18(u8 id, u8 **pc)
{
    void *obj;
    s32 x, y;
    if ((*pc)[1] <= 12)
    {
        x = ((*pc)[2] | ((*pc)[3] << 8)) << 11;
        y = ((*pc)[4] | ((*pc)[5] << 8)) << 11;
        obj = func_08080B00(D_02020E4C.field_20, (*pc)[1], x, y, (*pc)[6], 0, (*pc)[7], 0);
        if (obj != 0 && (*pc)[7] == 0)
            D_020209D8.current = obj;
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
