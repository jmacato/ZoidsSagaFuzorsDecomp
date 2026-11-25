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

struct Cam
{
    s32 x;
    s32 y;
};

extern struct Script D_0201F6DC;
extern struct Cam D_03000060;
extern s16 D_08734DB8[][2];
void func_08083C5C(u8, s32, s32);

s32 func_0808534C(u8 id, u8 **pc)
{
    u16 n;
    D_0201F6DC.field_0 = 1;
    n = ((*pc)[3] << 8) | (*pc)[2];
    D_0201F6DC.field_1138 = D_03000060.x + D_08734DB8[(*pc)[1]][0] * n;
    D_0201F6DC.field_113C = D_03000060.y - D_08734DB8[(*pc)[1]][1] * n;
    D_0201F6DC.field_1140 = ((*pc)[5] << 8) | (*pc)[4];
    D_0201F6DC.field_1135 = 1;
    func_08083C5C(id, -1, 0);
    return 0;
}
