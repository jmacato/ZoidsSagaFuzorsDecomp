#include "types.h"

struct Obj
{
    u8 pad_0[0x16];
    u8 palNum;
    u8 pad_17[0x19];
    s32 field_30;
    s32 field_34;
};

struct Demo
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    struct Obj *objs[2][6];
    u8 flags[2][6];
    u16 pal[16];
};

extern struct Demo D_02030AE8;
extern u32 D_03000084;

void func_080C8B78(const void *src, void *dest, u32 control);

void func_080C5B6C(struct Obj *obj)
{
    u8 *flag = &D_02030AE8.flags[obj->field_30][obj->field_34];
    u8 cur = *flag & 0xF;
    u16 *src;
    u16 *dst;
    u8 i;
    u8 r;
    u8 g;
    u8 b;
    u8 f;

    if (cur != (*flag >> 4))
    {
        if (cur == 0 && (*flag & 0xF0))
        {
            func_080C8B78(D_02030AE8.pal, (void *)(0x05000200 + obj->palNum * 32), 8);
            *flag = cur;
        }
        else
        {
            *flag = (*flag & 0xF) | (*flag << 4);
        }
    }

    switch (*flag & 0xF0)
    {
    case 0x10:
        src = D_02030AE8.pal;
        dst = (u16 *)(0x05000200 + obj->palNum * 32);
        for (i = 1; i < 16; i++)
        {
            r = *src & 0x1F;
            g = (*src & 0x3E0) >> 5;
            b = (*src & 0x7C00) >> 10;
            if (!(D_03000084 & 0x20))
                f = D_03000084 & 0x1F;
            else
                f = 0x20 - (D_03000084 & 0x1F);
            r += (31 - r) * f / 32;
            g += (31 - g) * f / 32;
            b += (31 - b) * f / 32;
            *dst = r | (g << 5) | (b << 10);
            src++;
            dst++;
        }
        break;
    case 0x20:
        src = D_02030AE8.pal;
        dst = (u16 *)(0x05000200 + obj->palNum * 32);
        for (i = 1; i < 16; i++)
        {
            r = *src & 0x1F;
            g = (*src & 0x3E0) >> 5;
            b = (*src & 0x7C00) >> 10;
            if (!(D_03000084 & 0x20))
                f = D_03000084 & 0x1F;
            else
                f = 0x20 - (D_03000084 & 0x1F);
            r += (31 - r) * f / 32;
            g -= g * f / 32;
            b -= b * f / 32;
            *dst = r | (g << 5) | (b << 10);
            src++;
            dst++;
        }
        break;
    }
}
