#include "types.h"

struct Named
{
    const u8 *name;
    u8 pad4[0x68];
};

extern u8 D_02030586[];
extern const u8 *const D_087A43E0[];
extern const u8 *const D_087A486C[];
extern const u8 *const D_087A4890[];
extern const u8 *const D_087A554C[];
extern const u8 *const D_087A559C[];
extern const u8 *const D_087A58C4[];
extern const u8 *const D_087A5AE4[];
extern const struct Named D_087A5CA4[];
extern u8 D_0200C4BC[];
extern u8 D_0200C4C0[];
extern u8 D_0200C4C4[];
extern u16 D_0200C4C8[];
extern u8 D_0200C4D0[];
extern u8 D_0200C4D4[];
extern u8 D_0200C4D8[];
extern u8 D_0200C4DC[];
extern u8 D_0200C4E0[][2];

const u8 *func_08082E70(u8);

u8 func_0807C100(const u8 *str)
{
    u8 len = 0;

    while (*str != 0)
    {
        if (*str < 0x20)
        {
            switch (*str)
            {
            case 1:
                str++;
                break;
            case 2:
                str += 2;
                break;
            case 3:
                len += func_0807C100(D_02030586);
                break;
            case 4:
            case 5:
                str += 3;
                break;
            case 6:
                len += func_0807C100(D_087A43E0[D_0200C4BC[str[1]]]);
                str++;
                break;
            case 7:
                len += func_0807C100(func_08082E70(D_0200C4C0[str[1]]));
                str++;
                break;
            case 8:
                len += func_0807C100(D_087A486C[D_0200C4C4[str[1]]]);
                str++;
                break;
            case 9:
                len += func_0807C100(D_087A4890[D_0200C4C8[str[1]]]);
                str++;
                break;
            case 11:
                len += func_0807C100(D_087A554C[D_0200C4D0[str[1]]]);
                str++;
                break;
            case 12:
                len += func_0807C100(D_087A559C[D_0200C4D4[str[1]]]);
                str++;
                break;
            case 13:
                len += func_0807C100(D_087A58C4[D_0200C4D8[str[1]]]);
                str++;
                break;
            case 14:
                len += func_0807C100(D_087A5AE4[D_0200C4DC[str[1]]]);
                str++;
                break;
            case 15:
                len += func_0807C100(D_087A5CA4[D_0200C4E0[str[1]][0]].name);
                str++;
                break;
            }
            str++;
        }
        else
        {
            if ((u8)(*str + 0x80) < 0x20)
                str += 2;
            else
                str++;
            len++;
        }
    }
    return len;
}
