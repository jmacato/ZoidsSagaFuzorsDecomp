#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x10EA];
    void *field_10EC;
    void *field_10F0;
    u8 field_10F4;
};

struct Cursor
{
    u8 pad_0[0x98];
    u8 field_98;
};

extern struct Script D_0201F6DC;
extern struct Cursor D_02036E7C;
extern u8 D_02001480[];
extern const u8 D_085ECCF0[];
extern const u8 D_085ECCFC[];
extern const u8 D_080F0960[];
extern const u8 D_080F0F1C[];
extern const u8 D_080F0F80[];
void func_0807FF2C(u8, u8, u16, u8, u8 *);
void *func_080771BC(const u8 *, const u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_080771F4(void *);
void func_080C8B84(const u8 *, void *);

void func_0808330C(u8 a, u8 b, u8 show)
{
    if (D_0201F6DC.field_1 != 2)
    {
        func_0807FF2C(a, b, 0x3C2, 0xE, D_02001480);
        if (D_0201F6DC.field_10EC == 0)
            D_0201F6DC.field_10EC = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 8, 0x68, 0x3C2, 0xE, 0x108, 0);
        if (show == 0)
        {
            if (D_0201F6DC.field_10F0 != 0)
            {
                func_080771F4(D_0201F6DC.field_10F0);
                D_0201F6DC.field_10F0 = 0;
            }
        }
        else if (D_0201F6DC.field_10F0 == 0)
        {
            func_080C8B84(D_080F0960, (void *)0x06016F40);
            D_0201F6DC.field_10F0 = func_080771BC(D_080F0F1C, D_080F0F80, 0, 8, 0x68, 0x37A, 0xF, 0x20, 0);
        }
    }
    else
    {
        func_0807FF2C(a, b, 0x3DC, 0xF, D_02001480);
        if (D_0201F6DC.field_10EC == 0)
        {
            if (D_0201F6DC.field_10F4 == 0)
            {
                if (D_02036E7C.field_98 == 0)
                    D_0201F6DC.field_10EC = func_080771BC(D_085ECCF0, D_085ECCFC, 0, -1, 0x72, 0x3DC, 0xF, 0x108, 0);
                else
                    D_0201F6DC.field_10EC = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 0xC1, 0x72, 0x3DC, 0xF, 0x108, 0);
            }
            else
                D_0201F6DC.field_10EC = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 8, 0x68, 0x3DC, 0xF, 0x108, 0);
        }
    }
}
