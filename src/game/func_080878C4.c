#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
};

extern struct Script D_0201F6DC;
void func_08089C5C(void);
void func_080A0358(void);
void func_080A3370(void);
void func_080BD0B8(void);
void func_08083C5C(u8, s32, s32);

s32 func_080878C4(u8 id)
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
    D_0201F6DC.field_1 = 0xFF;
    func_080BD0B8();
    func_08083C5C(id, -1, 0);
    return 0;
}
