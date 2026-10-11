#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
};

struct Map
{
    u16 id;
    u8 pad_2[2];
    s32 x;
    s32 y;
};

extern struct Script D_0201F6DC;
extern struct Map D_020209D8;
void func_080A0358(void);
void func_080A3370(void);
void func_080832D8(void);
void func_08082F84(void);
void func_0808889C(u16, s32, s32);
void func_08080C20(void);
void func_08083C5C(u8, s32, s32);

s32 func_08083DF4(u8 id)
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
        func_080832D8();
        func_08082F84();
        func_0808889C(D_020209D8.id, D_020209D8.x, D_020209D8.y);
        func_08080C20();
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
