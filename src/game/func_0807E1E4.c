#include "types.h"

struct Pilot
{
    u8 id;
    u8 pad1[0x3F];
};

struct Event
{
    u8 flags;
    u8 pad1[7];
};

struct Save
{
    u8 pad0[4];
    u16 field_4;
    u8 pad6[0xA];
    u32 field_10;
    u32 field_14;
    u8 pad18[0xC];
    u16 field_24;
    u16 field_26;
    u8 pad28[0x6B9C];
    struct Pilot pilots[57];
    u8 pad7A04[0x38];
    u32 field_7A3C;
    u32 field_7A40;
    u8 pad7A44[4];
    u32 field_7A48;
    u8 pad7A4C[0x24];
    struct Event events[14];
};

extern struct Save D_02020E4C;
extern u16 D_0300000E;
extern const u16 D_08734A70[4][17];

struct Unk0201F6DC
{
    u8 pad0[0x2CA];
    u8 field_2CA;
};
extern struct Unk0201F6DC D_0201F6DC;

void func_0807F18C(u8);
void func_08075F20(u16);
u8 func_08082F4C(u8);
void func_0807F1D0(u8, u8);
void func_08082EF4(u8);
void func_0807EF5C(u8);
void func_080C8FCC(u32);

void func_0807E1E4(void)
{
    u8 pos[4];
    u8 i, k;

    for (i = 0; i < 4; i++)
        pos[i] = 0;
    for (;;)
    {
        if (D_0300000E != 0)
        {
            for (i = 0; i < 4; i++)
            {
                if (D_0300000E == D_08734A70[i][pos[i]])
                {
                    if (++pos[i] == 17)
                    {
                        switch (i)
                        {
                        case 0:
                            if (!(D_02020E4C.field_7A48 & 0x00100200))
                            {
                                func_0807F18C(0x69);
                                func_0807F18C(0x74);
                                func_08075F20(0xDC);
                            }
                            break;
                        case 1:
                            if (!(D_02020E4C.field_7A3C & 0x08080000) && !(D_02020E4C.field_7A40 & 0x100))
                            {
                                func_0807F18C(0x13);
                                func_0807F18C(0x1B);
                                func_0807F18C(0x28);
                                func_08075F20(0xDF);
                            }
                            break;
                        case 2:
                            if (func_08082F4C(0xFF))
                            {
                                func_0807F18C(0x93);
                                func_0807F1D0(3, 1);
                                func_08075F20(0xDD);
                            }
                            break;
                        case 3:
                            if (func_08082F4C(0xFF) && !func_08082F4C(0x86))
                            {
                                func_08082EF4(0x86);
                                for (k = 1; k < 53; k++)
                                {
                                    if (D_02020E4C.pilots[k].id == 0x12)
                                    {
                                        func_0807EF5C(k);
                                        break;
                                    }
                                }
                                D_0201F6DC.field_2CA = 1;
                                D_02020E4C.field_4 = 4;
                                D_02020E4C.field_24 = 0;
                                D_02020E4C.field_10 = 0x64000;
                                D_02020E4C.field_14 = 0x6D000;
                                D_02020E4C.field_26 = 0xFFFF;
                                for (k = 0; k < 14; k++)
                                    D_02020E4C.events[k].flags = 0;
                                func_08075F20(0xD6);
                            }
                            break;
                        }
                        pos[i] = 0;
                    }
                }
                else
                {
                    pos[i] = 0;
                }
            }
        }
        func_080C8FCC(1);
    }
}
