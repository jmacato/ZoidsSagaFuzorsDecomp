#include "types.h"

struct Item
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[0x74];
    struct Item slots[8];
};

struct Result
{
    u8 flags;
    u8 flags2;
    u8 pad2[2];
    s16 field_4;
    u8 pad6[6];
    s16 field_C;
};

extern struct Result D_02031440;

struct Obj *func_0809A908(u8, u8);
void func_080C05A4(u8, u8, u8, u8, struct Result *);

u8 func_080C1D04(u8 a, u8 b, u8 mode)
{
    struct Obj *obj;
    s16 best = -1;
    u8 found = 0xFF;
    s16 second;
    u8 i;
    obj = func_0809A908(a, b);
    for (i = 0; i < 8; i++)
    {
        if (obj->slots[i].item != 0)
        {
            func_080C05A4(a, b, 0xFF, i, &D_02031440);
            if (!(D_02031440.flags & 1))
            {
                if ((mode == 0 && (D_02031440.flags2 & 8)) || (mode == 1 && !(D_02031440.flags2 & 8)))
                {
                    if (best < D_02031440.field_C)
                    {
                        best = D_02031440.field_C;
                        second = D_02031440.field_4;
                        found = i;
                    }
                    else if (best == D_02031440.field_C && second > D_02031440.field_4)
                    {
                        second = D_02031440.field_4;
                        found = i;
                    }
                }
            }
        }
    }
    return found;
}
