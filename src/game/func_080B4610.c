#include "types.h"

struct Part
{
    u8 pad_0[0x4];
    s32 field_4;
};

struct Ctx
{
    u8 pad_0[0x85];
    u8 field_85;
    u8 pad_86[0x6];
    struct Part *field_8C;
    struct Part *field_90;
};

struct Entry
{
    u8 pad_0[0x4];
    u16 field_4;
    u8 pad_6[0x4CA];
};

u32 func_080B43AC(void *);

extern struct Ctx D_0201F5F8;
extern struct Entry D_02009480[];

s32 func_080B4610(void *obj, u8 a, u8 b)
{
    for (;;)
    {
        D_0201F5F8.field_8C->field_4 = D_0201F5F8.field_90->field_4 = (D_02009480[a].field_4 + b + 1 - D_0201F5F8.field_85) << 11;
        switch (func_080B43AC(obj))
        {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            break;
        }
    }
}
