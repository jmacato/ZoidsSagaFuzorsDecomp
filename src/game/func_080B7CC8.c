#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u8 field_4;
    u8 field_5;
    u8 pad_6[2];
    u32 field_8;
    u8 pad_C[4];
};

void func_0807BAD4(u8, u8, u8, u8, u8, u8);
void func_080B7A60(u8, const struct Entry *, u8);

extern const struct Entry D_0877C7FC[][10];

void func_080B7CC8(u8 a, u8 b, u8 c)
{
    const struct Entry *e;
    u8 win;

    if (b < c)
    {
        e = &D_0877C7FC[a][b];
        if (e->field_0 != 0 || e->field_4 != 0 || e->field_8 != 0)
        {
            win = (b & 3) + 5;
            func_0807BAD4(win, (b * 20 + 5) % 64, 0x20, 0x14, 0x10, 0);
            func_080B7A60(win, e, 0);
        }
    }
}
