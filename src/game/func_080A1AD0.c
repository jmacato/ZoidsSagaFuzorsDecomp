#include "types.h"

struct Pair
{
    u16 field_0;
    u16 id;
};

struct State
{
    u8 stage;
    u8 pad_1[0x73];
    struct Pair pairs[4];
};

struct Layout
{
    u8 pad_0[4];
    u16 flags;
    s16 field_6;
    s16 field_8;
    u8 pad_A[2];
};

struct Offset
{
    s16 field_0;
    s16 field_2;
};

extern struct State D_02036E7C;
extern const struct Layout D_0878C790[][8];
extern const struct Offset D_087AD848[][8];
extern const s16 D_087B0FC4[];

void func_080A12B0(u8 mode, s32 arg);
s32 func_080A1B9C(void);
void func_080C8FCC(u32 frames);

void func_080A1AD0(u8 side)
{
    u16 id = D_02036E7C.pairs[side].id;
    const struct Layout *layout = D_0878C790[id];
    s16 v;
    if ((u8)(side - 1) <= 2)
        layout++;
    if (layout->field_6 != 0 || layout->field_8 != 0)
    {
        v = layout->field_6;
        if ((layout->flags & 0x3C) == 8)
        {
            s32 ofs = D_087AD848[D_02036E7C.stage][side].field_0;
            v += (side == 2 && id <= 0x51) ? ofs - D_087B0FC4[id] : ofs;
        }
        if (v <= 0x2F)
        {
            func_080A12B0(4, 0x7000);
            while (!func_080A1B9C())
                func_080C8FCC(1);
            return;
        }
    }
    func_080A12B0(4, 0x9000);
    while (!func_080A1B9C())
        func_080C8FCC(1);
}
