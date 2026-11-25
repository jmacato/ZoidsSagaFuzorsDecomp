#include "types.h"

struct State
{
    u8 pad_0[0x8];
    void *field_8;
    void *field_C[22];
    void *field_64;
    void *field_68;
    void *field_6C;
    u8 pad_70[0x10];
    u8 field_80;
};

void func_080771F4(void *);

extern struct State D_02030A40;

void func_080B8E40(void)
{
    u8 i;

    func_080771F4(D_02030A40.field_8);
    for (i = 0; i < D_02030A40.field_80; i++)
        func_080771F4(D_02030A40.field_C[i]);
    func_080771F4(D_02030A40.field_64);
    func_080771F4(D_02030A40.field_68);
    func_080771F4(D_02030A40.field_6C);
}
