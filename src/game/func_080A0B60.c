#include "types.h"

struct Layout
{
    s16 *script;
    u8 flags;
    u8 pad_5;
    s16 field_6;
    u16 field_8;
    u8 pad_A[2];
};

struct Anim
{
    u16 field_0;
    u8 pad_2[0x1A];
};

struct State
{
    u8 pad_0[0x99];
    u8 side;
    u8 pad_9A[0x85A];
    u8 active;
    u8 pad_8F5[3];
    s16 *script;
    s16 *scriptStart;
    u16 field_900;
    s16 field_902;
    s16 field_904;
    u8 field_906;
    u8 field_907;
    s16 field_908;
    u16 field_90A;
    u8 pad_90C[4];
    u8 field_910;
    u8 pad_911[3];
    s32 field_914;
    void *objs[16];
};

extern struct State D_02036E7C;
extern const s16 D_087B0FC4[];
extern const struct Anim D_087863EC[];
extern u16 D_03000056;
extern u16 D_03000058;

void func_080A3398(s32 id);

void func_080A0B60(const struct Layout *layout, u16 id, u8 side, u8 arg)
{
    u8 i;
    D_02036E7C.active = 1;
    D_02036E7C.side = side;
    D_02036E7C.field_906 = arg + (layout->flags & 3);
    if (D_02036E7C.field_906 > 2)
        D_02036E7C.field_906 = 2;
    D_02036E7C.field_907 = layout->flags & 0x3C;
    D_02036E7C.field_908 = layout->field_6 - ((side == 2 && id <= 0x51) ? D_087B0FC4[id] : 0);
    D_02036E7C.field_90A = layout->field_8;
    D_02036E7C.field_910 = 0;
    D_02036E7C.field_904 = 0;
    D_02036E7C.field_902 = 0;
    D_02036E7C.field_914 = 0;
    D_02036E7C.script = layout->script;
    func_080A3398(*D_02036E7C.script + D_02036E7C.field_906);
    D_02036E7C.field_900 = D_087863EC[*D_02036E7C.script + D_02036E7C.field_906].field_0;
    D_02036E7C.script++;
    D_02036E7C.scriptStart = D_02036E7C.script;
    for (i = 0; i < 16; i++)
        D_02036E7C.objs[i] = 0;
    D_03000056 = 0x740;
    D_03000058 = 0x810;
}
