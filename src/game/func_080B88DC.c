#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct State
{
    u8 pad_0[0x8];
    struct Obj *field_8;
    struct Obj *field_C[22];
    struct Obj *field_64;
    struct Obj *field_68;
    struct Obj *field_6C;
    u8 pad_70[0xC];
    u16 *field_7C;
    u8 field_80;
    u8 field_81;
    u8 field_82;
    u8 field_83;
    u8 field_84;
    u8 field_85;
    u8 field_86;
    u8 field_87;
    u8 field_88;
    u8 field_89;
    u8 field_8A;
};

void func_08077204(struct Obj *, u16);
void func_08075F20(u16);
u8 func_080B8480(void);
void func_0807BD4C(u8);
void func_080B84A8(void);
void func_0807A1A4(void);
void func_080B8664(u8, u8);

extern struct State D_02030A40;
extern u16 D_030057EC;
extern u16 D_0300000E;
extern const u16 D_08736634[][131];
extern const u16 D_08736C58[][399];
extern const u8 D_0873F580[][4];

u8 func_080B88DC(void)
{
    u8 oldScroll;
    u8 oldPage;
    u8 oldSub;
    u16 idx;
    u16 ch;
    u16 *p;
    u8 i;
    u8 found;

    oldScroll = D_02030A40.field_89;
    oldPage = D_02030A40.field_83;
    oldSub = D_02030A40.field_84;
    func_08077204(D_02030A40.field_C[D_02030A40.field_82], 2);
    D_02030A40.field_C[D_02030A40.field_82]->flags &= ~0x200000;
    D_02030A40.field_C[D_02030A40.field_82]->flags |= 8;
    if (D_030057EC & 0x40)
    {
        if (D_02030A40.field_87 != 0)
        {
            func_08075F20(0xCC);
            D_02030A40.field_87--;
        }
        else if (D_02030A40.field_89 != 0)
        {
            func_08075F20(0xCC);
            D_02030A40.field_89--;
            func_08077204(D_02030A40.field_68, 1);
        }
    }
    if (D_030057EC & 0x80)
    {
        if (D_02030A40.field_87 < 4)
        {
            func_08075F20(0xCC);
            D_02030A40.field_87++;
        }
        else if (D_02030A40.field_89 < D_02030A40.field_8A - 5)
        {
            func_08075F20(0xCC);
            D_02030A40.field_89++;
            func_08077204(D_02030A40.field_6C, 1);
        }
    }
    if (D_030057EC & 0x20)
    {
        func_08075F20(0xCC);
        if (D_02030A40.field_85 != 0)
            D_02030A40.field_85--;
        else
            D_02030A40.field_85 = 12;
    }
    if (D_030057EC & 0x10)
    {
        func_08075F20(0xCC);
        if (D_02030A40.field_85 < 12)
            D_02030A40.field_85++;
        else
            D_02030A40.field_85 = 0;
    }
    if (D_0300000E & 1)
    {
        idx = D_02030A40.field_85 + (D_02030A40.field_87 + D_02030A40.field_89) * 13;
        if (func_080B8480() == 0)
        {
            if (idx < D_08736634[D_02030A40.field_83][0])
                ch = D_08736634[D_02030A40.field_83][idx + 1];
            else
                ch = 0x4081;
        }
        else
        {
            if (idx < D_08736C58[D_02030A40.field_84][0])
                ch = D_08736C58[D_02030A40.field_84][idx + 1];
            else
                ch = 0x4081;
        }
        if (D_02030A40.field_83 == 5 && D_02030A40.field_84 == 0xFF)
        {
            for (i = 0; i < 44; i++)
            {
                if ((ch & 0xFF) == D_0873F580[i][0] && (ch >> 8) == D_0873F580[i][1])
                {
                    D_02030A40.field_84 = i;
                    D_02030A40.field_86 = D_02030A40.field_85;
                    D_02030A40.field_88 = D_02030A40.field_87;
                    D_02030A40.field_85 = D_02030A40.field_87 = 0;
                    func_08075F20(0xCA);
                    break;
                }
            }
            if (i == 44)
                func_08075F20(0x114);
        }
        else
        {
            func_08075F20(0xCA);
            if (ch != 0x4081)
            {
                p = D_02030A40.field_7C;
                found = 0;
                for (i = 0; i < D_02030A40.field_82 + 1; i++)
                {
                    if (*(u8 *)p == 0)
                        found = 1;
                    if (found)
                        *p = 0x4081;
                    p++;
                }
                p[-1] = ch;
                if (found)
                    *p = 0;
            }
            else
            {
                p = &D_02030A40.field_7C[D_02030A40.field_82];
                if (*(u8 *)p != 0)
                {
                    *p = ch;
                    if (*(u8 *)&p[1] == 0)
                    {
                        while (p > D_02030A40.field_7C && p[-1] == 0x4081)
                            p--;
                        *p = 0;
                    }
                }
            }
            func_0807BD4C(7);
            func_080B84A8();
            func_0807A1A4();
            D_02030A40.field_82 = (D_02030A40.field_82 + 1) % D_02030A40.field_80;
        }
    }
    else if (D_0300000E & 2)
    {
        func_08075F20(0xCB);
        if (func_080B8480())
        {
            D_02030A40.field_84 = 0xFF;
            D_02030A40.field_85 = D_02030A40.field_86;
            D_02030A40.field_87 = D_02030A40.field_88;
        }
        else
        {
            if (D_02030A40.field_82 == 0)
                D_02030A40.field_82 = D_02030A40.field_80 - 1;
            else
                D_02030A40.field_82--;
            p = &D_02030A40.field_7C[D_02030A40.field_82];
            if (*(u8 *)p != 0)
            {
                *p = 0x4081;
                if (*(u8 *)&p[1] == 0)
                {
                    while (p > D_02030A40.field_7C && p[-1] == 0x4081)
                        p--;
                    *p = 0;
                }
            }
            func_0807BD4C(7);
            func_080B84A8();
            func_0807A1A4();
        }
    }
    else if (D_030057EC & 0x200)
    {
        func_08075F20(0xCC);
        if (D_02030A40.field_82 != 0)
            D_02030A40.field_82--;
        else
            D_02030A40.field_82 = D_02030A40.field_80 - 1;
    }
    else if (D_030057EC & 0x100)
    {
        func_08075F20(0xCC);
        if (D_02030A40.field_82 < D_02030A40.field_80 - 1)
            D_02030A40.field_82++;
        else
            D_02030A40.field_82 = 0;
    }
    else if (D_0300000E & 4)
    {
        func_08075F20(0xCD);
        D_02030A40.field_83 = (D_02030A40.field_83 + 1) % 6;
        if (oldPage == 5)
            D_02030A40.field_84 = 0xFF;
    }
    else if (D_0300000E & 8)
    {
        func_08075F20(0xCA);
        return 1;
    }
    if (D_02030A40.field_89 != oldScroll || D_02030A40.field_83 != oldPage || D_02030A40.field_84 != oldSub)
    {
        func_080B8664(D_02030A40.field_83, D_02030A40.field_84);
        func_0807A1A4();
    }
    D_02030A40.field_64->x = (D_02030A40.field_85 * 16 + 8) << 8;
    D_02030A40.field_64->y = (D_02030A40.field_87 << 12) + 0x4800;
    if (D_02030A40.field_89 != 0)
        D_02030A40.field_68->flags &= ~0x20000;
    else
        D_02030A40.field_68->flags |= 0x20000;
    if (D_02030A40.field_8A > 5 && D_02030A40.field_89 < D_02030A40.field_8A - 5)
        D_02030A40.field_6C->flags &= ~0x20000;
    else
        D_02030A40.field_6C->flags |= 0x20000;
    func_08077204(D_02030A40.field_C[D_02030A40.field_82], 1);
    D_02030A40.field_C[D_02030A40.field_82]->flags |= 0x200008;
    return 0;
}
