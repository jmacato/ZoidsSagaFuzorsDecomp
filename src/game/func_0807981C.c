#include "types.h"

extern u8 D_03005714;
extern u8 D_03005715;
extern u8 D_03005716;
extern s16 D_03005718;
extern s16 D_0300571A;
extern u8 D_0300571C;
extern u8 D_0300571D;
extern u8 D_02001340[][0xA0];
extern u16 D_0300005C;
extern u16 D_0300004E;
extern u16 D_03000050;
extern u16 D_03000052;
extern u16 D_03000054;
extern u8 D_03005696;
extern u16 D_0300568E[2];
extern u16 D_03005692[2];
extern u16 D_03005698;
extern u8 D_0300569A;

u8 func_080796EC(void);
void func_0807975C(s16, s16, s32);
void func_080784F8(void);
s32 func_080C8B80(s32, s32);

#define SET_FADE(v)                                                  \
    if (D_03005714 & 0x80)                                           \
    {                                                                \
        if (v != 0)                                                  \
        {                                                            \
            v--;                                                     \
            D_0300005C = v | (v << 4) | (v << 8) | (v << 12);        \
            D_0300004E |= 0x40;                                   \
            D_03000050 |= 0x40;                                   \
            D_03000052 |= 0x40;                                   \
            D_03000054 |= 0x40;                                   \
        }                                                            \
        else                                                         \
        {                                                            \
            D_0300005C = v;                                          \
            D_0300004E &= ~0x40;                                  \
            D_03000050 &= ~0x40;                                  \
            D_03000052 &= ~0x40;                                  \
            D_03000054 &= ~0x40;                                  \
        }                                                            \
    }

void func_0807981C(void)
{
    u8 v;
    u16 i;
    u8 *p;

    if (func_080796EC())
        return;
    D_03005716++;
    if (D_03005714 & 0x80)
    {
        switch (D_03005714 & 0x7F)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 10:
        case 13:
        case 15:
            v = 16 - func_080C8B80(D_03005716 << 4, D_03005715);
            SET_FADE(v);
            break;
        case 2:
        case 4:
        case 6:
        case 8:
        case 11:
        case 12:
        case 14:
        case 16:
            v = func_080C8B80(D_03005716 << 4, D_03005715);
            SET_FADE(v);
            break;
        }
    }
    switch (D_03005714 & 0x7F)
    {
    case 5:
    case 6:
        D_03005696 = D_03005716 * 2;
        if (D_03005716 == D_03005715)
            func_080784F8();
        break;
    case 7:
    case 8:
        D_0300568E[0] = D_0300568E[1] = D_03005692[0] = D_03005692[1] = D_03005716 * D_03005716;
        if (D_03005716 == D_03005715)
            func_080784F8();
        break;
    case 9:
    case 10:
    case 11:
    case 12:
        D_03005698 = D_03005716 * 320 / D_03005715;
        if (D_03005716 == D_03005715)
            func_080784F8();
        break;
    case 13:
        func_0807975C((D_03005718 - 120) * (32 - D_03005716) / 32 + 120, (D_0300571A - 80) * (32 - D_03005716) / 32 + 80, D_03005716 * 120 / 32);
        if (D_03005716 == D_03005715)
            func_080784F8();
        break;
    case 14:
        func_0807975C((D_03005718 - 120) * D_03005716 / 32 + 120, (D_0300571A - 80) * D_03005716 / 32 + 80, (32 - D_03005716) * 120 / 32);
        if (D_03005716 == D_03005715)
            func_080784F8();
        break;
    case 15:
    case 16:
        D_0300569A = D_03005716 * 4;
        if (D_03005716 == D_03005715)
            func_080784F8();
        break;
    case 17:
        p = D_02001340[D_0300571C ^ 1];
        for (i = 0; i < 160; i++)
        {
            if (i < (20 - D_03005716) * 4 || 160 - i < (20 - D_03005716) * 4)
                *p = 0;
            else
                *p = 1;
            p++;
        }
        if (D_03005716 == D_03005715)
            D_0300571D = 2;
        break;
    case 18:
        if (D_03005716 == D_03005715)
        {
            D_0300571D = 2;
            break;
        }
        p = D_02001340[D_0300571C ^ 1];
        for (i = 0; i < 160; i++)
        {
            if (i < D_03005716 * 4 || 160 - i < D_03005716 * 4)
                *p = 0;
            else
                *p = 1;
            p++;
        }
        break;
    }
}
