#include "types.h"

struct Packet
{
    u8 field_0;
    u8 field_1;
    u8 data[14];
};

extern u8 D_03005811;
extern s32 D_0300580C;
extern u8 D_030057F4;
extern struct Packet D_03000AD4[2];
extern u8 D_03000AC4;
extern u8 *D_030057FC;
extern u8 *D_03005804;
extern u16 D_03000B18;

void func_080801D0(void);

u32 func_08080510(void)
{
    u8 i;
    u8 v;
    u8 *flag;
    u8 *p;
    u8 *src;

    if (D_03005811 == 0)
        return 1;
    if (D_03005811 > 1 && D_0300580C <= 0)
    {
        if (D_030057F4)
        {
            flag = &D_03000AD4[1].field_1;
            if (*flag != 0)
                return 0;
            v = D_03000AD4[0].field_0;
        }
        else
        {
            flag = &D_03000AD4[0].field_1;
            if (*flag != 0)
                return 0;
            v = D_03000AD4[1].field_0;
        }
        if (v != 0)
            return 0;
        D_03005811 = v;
        return 1;
    }
    if (D_030057F4)
    {
        src = (u8 *)&D_03000AD4[1];
        if (src[1] != D_03005811)
            return 0;
    }
    else
    {
        src = (u8 *)&D_03000AD4[0];
        if (src[1] != D_03005811)
            return 0;
    }
    if (D_03005811 == 1)
    {
        p = D_030057FC;
        src += 2;
        for (i = 0; i < 14 && *p != 0; p++, src++, i++)
        {
            if (*src != *p)
            {
                func_080801D0();
                D_03000B18 |= 4;
                return 0;
            }
        }
    }
    else
    {
        src += 2;
        for (i = 0; i < 14 && D_0300580C != 0; i++)
        {
            *D_03005804 = *src;
            D_03005804++;
            src++;
            D_0300580C--;
        }
    }
    D_03005811++;
    if (D_0300580C == 0)
        D_03000AC4 = 0;
    else
        D_03000AC4 = D_03005811;
    return 0;
}
