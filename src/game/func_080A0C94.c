#include "types.h"

struct Pair
{
    u16 field_0;
    u16 id;
};

struct State
{
    u8 pad_0[0x74];
    struct Pair pairs[4];
    u8 pad_84[0x888];
    u16 field_90C;
    u8 pad_90E;
    u8 field_90F;
};

struct Layout
{
    u8 data[0xC];
};

extern struct State D_02036E7C;
extern const struct Layout D_0878C790[][8];

void func_080A3380(void);
void func_080A0B60(const struct Layout *layout, u16 id, u8 side, u8 arg);
void func_080A05BC(u8 side);

void func_080A0C94(u8 side, u8 arg)
{
    u16 id = D_02036E7C.pairs[side].id;
    const struct Layout *layout;
    D_02036E7C.field_90F = 0;
    func_080A3380();
    if (side != 2)
        D_02036E7C.field_90C = 0x40;
    else
        D_02036E7C.field_90C = 0xC0;
    layout = D_0878C790[id];
    if ((u8)(side - 1) <= 2)
        layout++;
    func_080A0B60(layout, id, side, arg);
    func_080A05BC(side);
}
