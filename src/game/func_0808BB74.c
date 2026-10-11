#include "types.h"

struct Part
{
    u8 flags;
    u8 pad_1[5];
    u8 type;
    u8 level;
    u8 pad_8[8];
    s16 field_10;
};

extern const u8 D_080F36B0[];
extern const u8 D_080F36C0[];
extern const u8 D_080F36D0[];
extern const u8 D_080F36E0[];
extern const u8 D_080F36E8[];
extern const u8 D_080F36F0[];
extern const u8 D_080F36F8[];
extern const u8 D_080F3700[];
extern const u8 D_080F3708[];
extern const u8 D_080F3710[];
extern const u8 D_080F3718[];
extern const u8 D_080F3724[];
extern const u8 D_080F3730[];
extern const u8 D_080F373C[];
extern const u8 D_080F3748[];
extern const u8 D_080F3754[];
void func_080C8E88(u8 *, const u8 *, s32);
void func_0807DB94(u8 *, const u8 *);

u8 *func_0808BB74(struct Part *p, u8 *buf)
{
    if ((p->flags & 1) && p->field_10 == 1)
        func_080C8E88(buf, D_080F36B0, 13);
    else if (p->level == 6)
        func_080C8E88(buf, D_080F36C0, 13);
    else if (p->level == 7)
        func_080C8E88(buf, D_080F36D0, 13);
    else
    {
        if (!(p->flags & 1))
        {
            switch (p->type)
            {
            case 0:
                func_080C8E88(buf, D_080F36E0, 6);
                break;
            case 1:
                func_080C8E88(buf, D_080F36E8, 6);
                break;
            case 2:
                func_080C8E88(buf, D_080F36F0, 6);
                break;
            case 3:
                func_080C8E88(buf, D_080F36F8, 6);
                break;
            case 4:
                func_080C8E88(buf, D_080F3700, 6);
                break;
            case 5:
                func_080C8E88(buf, D_080F3708, 6);
                break;
            }
        }
        else
            func_080C8E88(buf, D_080F3710, 6);
        switch (p->level)
        {
        case 0:
            func_0807DB94(buf, D_080F3718);
            break;
        case 1:
            func_0807DB94(buf, D_080F3724);
            break;
        case 2:
            func_0807DB94(buf, D_080F3730);
            break;
        case 3:
            func_0807DB94(buf, D_080F373C);
            break;
        case 4:
            func_0807DB94(buf, D_080F3748);
            break;
        case 5:
            func_0807DB94(buf, D_080F3754);
            break;
        }
    }
    return buf;
}
