#include "types.h"

struct Script
{
    u8 field_0;
    u8 pad_1[0x1134];
    u8 field_1135;
    u8 pad_1136[2];
    s32 field_1138;
    s32 field_113C;
    u16 field_1140;
};

extern struct Script D_0201F6DC;
void func_08083C5C(u8, s32, s32);

s32 func_080853F4(u8 id, u8 **pc)
{
    D_0201F6DC.field_0 = 1;
    D_0201F6DC.field_1138 = ((((*pc)[2] << 8) | (*pc)[1]) - 15) << 11;
    D_0201F6DC.field_113C = ((((*pc)[4] << 8) | (*pc)[3]) - 10) << 11;
    D_0201F6DC.field_1140 = ((*pc)[6] << 8) | (*pc)[5];
    D_0201F6DC.field_1135 = 1;
    func_08083C5C(id, -1, 0);
    return 0;
}
