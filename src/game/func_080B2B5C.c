#include "types.h"

struct Child
{
    u8 pad_0[0x30];
    s32 field_30;
    s32 field_34;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
};

struct Child *func_08076FE0(const void *, u16, u16, s32, s32, u16, u16, u32, void *);
void func_080B2B08(void);

extern const u8 D_087B4CAC[];

void func_080B2B5C(const u8 *str, struct Obj *obj, u8 base)
{
    u8 i;
    u8 idx;
    struct Child *child;

    i = 0;
    while (*str != 0)
    {
        if ((u8)(*str - '0') <= 9)
        {
            idx = *str + 0xF0;
        }
        else
        {
            idx = *str - 'A';
            if (idx > 25)
            {
                if (*str == '+')
                    idx = 26;
                else if (*str == '-')
                    idx = 27;
                else if (*str == '/')
                    idx = 28;
                else if (*str == '<')
                    idx = 29;
                else if (*str == '>')
                    idx = 30;
                else if (*str == 0xA0)
                    idx = 31;
                else if (*str == '%')
                    idx = 42;
                else if (*str == '?')
                    idx = 43;
                else
                {
                    str++;
                    i++;
                    continue;
                }
            }
        }
        child = func_08076FE0(D_087B4CAC, 1, idx, obj->field_4 + i * 0x600, obj->field_8 - 0x800, 0x360, 13, 0x20048, func_080B2B08);
        obj->children[base + i] = child;
        child->field_30 = -i * 2;
        child->field_34 = -i * 2 + 0x2D;
        str++;
        i++;
    }
}
