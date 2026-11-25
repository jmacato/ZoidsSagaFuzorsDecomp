#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x10F2];
    u8 field_10F4;
};

struct Map2
{
    u8 field_0;
    u8 field_1;
};

extern struct Script D_0201F6DC;
extern struct Map2 D_02020E3C;
void func_08089C5C(void);
void func_080A0358(void);
void func_080A3370(void);
void func_08083C5C(u8, s32, s32);

s32 func_08083F04(u8 id, u8 **pc)
{
    D_0201F6DC.field_0 = 1;
    switch (D_0201F6DC.field_1)
    {
    case 0:
        func_08089C5C();
        break;
    case 1:
        func_080A0358();
        break;
    case 2:
        func_080A3370();
        break;
    }
    D_0201F6DC.field_1 = 2;
    D_02020E3C.field_1 = (*pc)[1];
    D_0201F6DC.field_10F4 = (*pc)[2];
    func_08083C5C(id, -1, 0);
    return 0;
}
