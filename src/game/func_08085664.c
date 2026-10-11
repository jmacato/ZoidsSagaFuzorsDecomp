#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
};

extern struct Script D_0201F6DC;
void func_080A0358(void);
void func_080A3370(void);
void func_080832D8(void);
void func_08082F84(void);
void func_0808889C(u16, s32, s32);
void func_08080640(void);
void func_08083C5C(u8, s32, s32);

s32 func_08085664(u8 id, u8 **pc)
{
    D_0201F6DC.field_0 = 1;
    if (D_0201F6DC.field_1 != 0)
    {
        switch (D_0201F6DC.field_1)
        {
        case 1:
            func_080A0358();
            break;
        case 2:
            func_080A3370();
            break;
        }
        D_0201F6DC.field_1 = 0;
    }
    func_080832D8();
    func_08082F84();
    func_0808889C((*pc)[1] | ((*pc)[2] << 8), ((*pc)[3] | ((*pc)[4] << 8)) << 11, ((*pc)[5] | ((*pc)[6] << 8)) << 11);
    func_08080640();
    func_08083C5C(id, -1, 0);
    return 0;
}
