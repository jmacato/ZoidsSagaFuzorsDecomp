#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[3];
    u8 field_5;
    u8 pad_6[10];
};

struct Game
{
    u8 pad_0[0x7B49];
    u8 field_7B49;
    u8 field_7B4A;
    u8 field_7B4B;
    u8 field_7B4C;
};

extern struct Game D_02020E4C;
extern const struct Entry D_0877C7FC[][10];

void func_080B792C(u8 a, u8 b)
{
    const struct Entry *e;

    D_02020E4C.field_7B49 = a;
    D_02020E4C.field_7B4A = b;
    e = &D_0877C7FC[a][b];
    D_02020E4C.field_7B4B = e->field_1;
    D_02020E4C.field_7B4C = e->field_5;
}
