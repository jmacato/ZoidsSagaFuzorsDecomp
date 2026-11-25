#include "types.h"

struct State
{
    u8 pad_0[0x83];
    u8 field_83;
    u8 field_84;
    u8 pad_85[0x4];
    u8 field_89;
    u8 field_8A;
};

u8 func_080B8480(void);
void func_080B84C8(void);

extern struct State D_02030A40;
extern const u16 D_08736634[][131];
extern const u16 D_08736C58[][399];

void func_080B8664(u8 a, u8 b)
{
    u16 count;
    u16 rem;
    u8 n;
    struct State *s;

    D_02030A40.field_83 = a;
    D_02030A40.field_84 = b;
    if (func_080B8480() == 0)
        count = D_08736634[D_02030A40.field_83][0];
    else
        count = D_08736C58[D_02030A40.field_84][0];
    n = 13;
    s = &D_02030A40;
    rem = count % 13;
    s->field_8A = (rem != 0 ? count + n - rem : count) / n;
    if (D_02030A40.field_8A <= 4)
        D_02030A40.field_89 = 0;
    else if (D_02030A40.field_89 > D_02030A40.field_8A - 5)
        D_02030A40.field_89 = D_02030A40.field_8A - 5;
    func_080B84C8();
}
