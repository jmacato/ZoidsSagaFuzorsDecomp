#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 x;
    s32 y;
    u8 pad_C[0x9C];
    u32 field_A8;
};

struct Big
{
    u8 pad_0[0x98];
    u8 mirror;
    u8 field_99;
    u8 pad_9A[0x80E];
    s32 field_8A8;
    u8 pad_8AC[0x5B];
    u8 field_907;
};

struct Def
{
    void *a;
    void *b;
};

struct Scroll
{
    s32 x;
    s32 y;
};

void func_080A3380(void);
struct Obj *func_08077DF0(s32, void *, void *);

extern struct Big D_02036E7C;
extern const struct Def D_08735B58[];
extern const s16 D_087AD848[][8][2];
extern const s16 D_0879F990[][16];
extern struct Scroll D_03000060;

struct Obj *func_080B229C(u8 slot, u16 id, s16 x, s16 y, u16 flags)
{
    struct Obj *o;

    func_080A3380();
    o = func_08077DF0(D_02036E7C.mirror ? 2 : 0, D_08735B58[id].a, D_08735B58[id].b);
    if (o != 0)
    {
        switch (D_02036E7C.field_907)
        {
        case 0:
            o->x = x;
            o->y = y;
            break;
        case 4:
            o->x = x - D_02036E7C.field_8A8 / 256;
            o->y = y - D_03000060.y / 256;
            break;
        case 8:
            o->x = x + D_087AD848[slot][D_02036E7C.field_99][0] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_087AD848[slot][D_02036E7C.field_99][1] - D_03000060.y / 256;
            break;
        case 12:
            o->x = x + D_0879F990[slot][0] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_0879F990[slot][1] - D_03000060.y / 256;
            break;
        case 16:
            o->x = x + D_0879F990[slot][2] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_0879F990[slot][3] - D_03000060.y / 256;
            break;
        case 20:
            o->x = x + D_0879F990[slot][4] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_0879F990[slot][5] - D_03000060.y / 256;
            break;
        case 24:
            o->x = x + D_0879F990[slot][6] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_0879F990[slot][7] - D_03000060.y / 256;
            break;
        case 28:
            o->x = x + D_0879F990[slot][8] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_0879F990[slot][9] - D_03000060.y / 256;
            break;
        case 32:
            o->x = x + D_0879F990[slot][10] - D_02036E7C.field_8A8 / 256;
            o->y = y + D_0879F990[slot][11] - D_03000060.y / 256;
            break;
        }
        o->field_A8 = flags;
    }
    return o;
}
