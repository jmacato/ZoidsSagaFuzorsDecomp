#include "types.h"

struct Unit
{
    u8 kind;
    u8 pad_1[0x75];
    u16 field_76;
};

struct Big
{
    u8 pad_0[0x24C];
    struct Unit *unit;
};

extern struct Big D_02031A0C;
extern s16 D_087AD848[][8][2];
void func_080944D4(u8, s16, s16);

void func_08094534(u8 id)
{
    s16 y = D_087AD848[D_02031A0C.unit->kind][id][1];

    if (id == 0 && D_02031A0C.unit->field_76 < 0x52)
        y -= 16;
    func_080944D4(0, D_087AD848[D_02031A0C.unit->kind][id][0], y);
}
