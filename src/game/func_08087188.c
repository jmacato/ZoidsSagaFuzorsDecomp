#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
};

extern struct Script D_0201F6DC;
extern u8 D_0201F5F8;
void func_08089C5C(void);
void func_080A0358(void);
void func_080A3370(void);
void func_08091E48(void);
void func_08083C5C(u8, s32, s32);

s32 func_08087188(u8 id, u8 **pc)
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
    {
        u8 *flag = &D_0201F5F8;
        u8 v = (*pc)[1];
        u8 zero = 0;
        *flag = v;
        func_08091E48();
        *flag = zero;
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
