#include "types.h"

struct Obj
{
    u8 pad_0[0xE];
    s16 field_E;
    s16 field_10;
    s16 field_12;
    u8 pad_14[0x1C];
    void *field_30;
};

struct Big
{
    u8 pad_0[0x4F38];
    struct Obj *objs[6];
    s8 dir;
    u8 count;
};

extern struct Big D_02031A0C;
s32 func_0808B53C(void *);
void func_08094AE0(void);

void func_08094B08(void)
{
    u8 i;

    if (D_02031A0C.dir != 0)
    {
        if (++D_02031A0C.count == 9)
        {
            if (D_02031A0C.dir == -1)
                func_08094AE0();
            D_02031A0C.count = 0;
            D_02031A0C.dir = 0;
        }
    }
    if (D_02031A0C.dir == 1)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02031A0C.objs[i] != 0)
            {
                D_02031A0C.objs[i]->field_10 = D_02031A0C.objs[i]->field_12 = D_02031A0C.count << 4;
                D_02031A0C.objs[i]->field_E = func_0808B53C(D_02031A0C.objs[i]->field_30) * D_02031A0C.objs[i]->field_10 / 256;
            }
        }
    }
    else if (D_02031A0C.dir == -1)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02031A0C.objs[i] != 0)
            {
                D_02031A0C.objs[i]->field_10 = D_02031A0C.objs[i]->field_12 = (8 - D_02031A0C.count) << 4;
                D_02031A0C.objs[i]->field_E = func_0808B53C(D_02031A0C.objs[i]->field_30) * D_02031A0C.objs[i]->field_10 / 256;
            }
        }
    }
}
