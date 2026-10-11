#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x10E6];
    u8 field_10E8;
    u8 pad_10E9[0xB];
    u8 field_10F4;
};

extern struct Script D_0201F6DC;
extern u16 D_0300004C;
extern const u8 D_08014B6F[];
extern const u8 D_08014B74[];
extern const u8 D_08014B99[];
void func_08083490(void);
void func_0807C290(const u8 *);
void func_080832D8(void);

void func_0808359C(void)
{
    if (D_0201F6DC.field_1 != 2 || D_0201F6DC.field_10F4 != 0)
    {
        func_08083490();
        if (D_0201F6DC.field_10E8 != 0)
        {
            if (D_0201F6DC.field_10E8 == 1)
                func_0807C290(D_08014B6F);
            else
                func_0807C290(D_08014B74);
            func_0807C290(D_08014B99);
        }
        func_080832D8();
        if (D_0201F6DC.field_1 == 2 && D_0201F6DC.field_10F4 != 0)
            D_0300004C |= 0x200;
    }
}
