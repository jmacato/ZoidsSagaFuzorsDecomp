#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x10E6];
    u8 field_10E8;
    u8 pad_10E9[3];
    void *field_10EC;
    u8 pad_10F0[4];
    u8 field_10F4;
};

extern struct Script D_0201F6DC;
extern u16 D_0300004C;
extern const u8 D_08014B4B[];
extern const u8 D_08014B64[];
extern const u8 D_08014B6F[];
extern const u8 D_08014B74[];
void func_0807C290(const u8 *);

void func_080834C8(void)
{
    if (D_0201F6DC.field_1 != 2 || D_0201F6DC.field_10F4 != 0)
    {
        if (D_0201F6DC.field_10E8 == 0)
        {
            if (D_0201F6DC.field_10EC != 0)
            {
                func_0807C290(D_08014B4B);
                D_0201F6DC.field_10E8 = 1;
            }
            else
            {
                func_0807C290(D_08014B64);
                D_0201F6DC.field_10E8 = 2;
            }
        }
        else if (D_0201F6DC.field_10EC != 0)
        {
            if (D_0201F6DC.field_10E8 == 2)
            {
                func_0807C290(D_08014B74);
                func_0807C290(D_08014B4B);
                D_0201F6DC.field_10E8 = 1;
            }
        }
        else if (D_0201F6DC.field_10E8 == 1)
        {
            func_0807C290(D_08014B6F);
            func_0807C290(D_08014B64);
            D_0201F6DC.field_10E8 = 2;
        }
        if (D_0201F6DC.field_1 == 2 && D_0201F6DC.field_10F4 != 0)
            D_0300004C &= ~0x200;
    }
    else
        D_0201F6DC.field_10E8 = 1;
}
