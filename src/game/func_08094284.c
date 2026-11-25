#include "types.h"

struct Obj
{
    u8 pad_0[4];
    s32 x;
    s32 y;
};

struct Vec
{
    s32 x;
    s32 y;
};

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
    u8 pad_250[0x4EA4 - 0x250];
    struct Obj *objs[7];
    struct Vec pos[7];
    struct Vec vel[7];
    u8 flags[8];
};

extern struct Big D_02031A0C;
extern s16 D_087AD848[][8][2];
extern const u8 D_087B4C9C[];
extern const u8 D_087B4CAC[];
void func_0807FF9C(const u8 *, u32, u32, u32);
struct Obj *func_08077180(const u8 *, u32, u32, s16, s16, u32, u32, u32, u32);

void func_08094284(u8 who)
{
    u8 i;
    struct Obj *obj;

    func_0807FF9C(D_087B4C9C, 0, 0x300, 0xC);
    for (i = 0; i < 7; i++)
    {
        obj = func_08077180(D_087B4CAC, 0, 0, D_087AD848[D_02031A0C.unit->kind][who][0], D_087AD848[D_02031A0C.unit->kind][who][1], 0x300, 0xC, 0x1060, 0);
        D_02031A0C.objs[i] = obj;
        if (who == 0 && D_02031A0C.unit->field_76 < 0x52)
            obj->y -= 0x1000;
        D_02031A0C.vel[i].x = D_02031A0C.objs[i]->x;
        D_02031A0C.vel[i].y = D_02031A0C.objs[i]->y;
        D_02031A0C.pos[i].x = D_02031A0C.objs[i]->x;
        D_02031A0C.pos[i].y = D_02031A0C.objs[i]->y;
        D_02031A0C.flags[i] = 8;
    }
    D_02031A0C.flags[7] = 0;
}
