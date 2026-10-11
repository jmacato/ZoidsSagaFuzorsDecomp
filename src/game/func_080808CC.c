#include "types.h"

struct AnimEntry
{
    const u8 *data;
    u8 pad_4[0xC];
};

struct Actor
{
    u8 flags;
    u8 kind;
    u8 pad_2[0x12];
    u8 field_14;
    u8 pad_15[2];
    u8 dir;
};

extern struct AnimEntry D_087B1D90[];
extern const u8 D_08503604[];
extern const u8 D_0850362C[];
extern const u8 D_085EC350[];
extern const u8 D_085EC664[];
extern const u8 D_085EC978[];
extern const u8 D_085ECC8C[];
extern const u8 D_0850366C[];
extern const u8 D_08502EAC[];
extern const u8 D_0850350C[];
extern const u8 D_08734B74[];
extern const u8 D_08734B7C[];
extern const u8 D_08734B84[];

s32 func_080808CC(struct Actor *a)
{
    const u8 *data = D_087B1D90[a->kind].data;
    s32 r;
    if (data == D_08503604 || data == D_0850362C || data == D_085EC350 || data == D_085EC664 || data == D_085EC978 || data == D_085ECC8C)
        r = 0;
    else if (data == D_0850366C)
        r = D_08734B74[a->dir];
    else if (data == D_08502EAC || data == D_0850350C)
    {
        r = D_08734B84[a->dir];
        if (a->field_14 >= 1 && a->field_14 <= 6)
            r += 4;
    }
    else
    {
        r = D_08734B7C[a->dir];
        if (a->field_14 >= 1 && a->field_14 <= 6)
            r += 4;
    }
    return r;
}
