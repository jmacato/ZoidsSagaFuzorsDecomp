#include "types.h"

struct Pos
{
    u8 pad_0[0x4];
    s32 x;
    s32 y;
};

struct Slot
{
    u8 flags;
    u8 pad_1[0x3];
    struct Pos *pos;
    u8 pad_8[0x10];
};

struct Child
{
    u8 pad_0[0x4];
    s32 x;
    s32 y;
    u8 pad_C[0x90];
    s32 field_9C;
    s32 field_A0;
    s32 field_A4;
    s32 field_A8;
};

struct Def
{
    void *a;
    void *b;
};

struct Child *func_08077DF0(s32, void *, void *);

extern struct Slot D_02037B6C[][6];
extern const struct Def D_087364AC[];
extern struct Child *D_02037CF4[];

void func_080B3B94(u16 id, u8 a, u8 b, s32 arg)
{
    struct Child *child;

    if (D_02037B6C[a][b].flags & 1)
    {
        child = func_08077DF0(0, D_087364AC[id].a, D_087364AC[id].b);
        D_02037CF4[b] = child;
        child->x = D_02037B6C[a][b].pos->x;
        child->y = D_02037B6C[a][b].pos->y;
        child->field_9C = 0;
        child->field_A0 = arg;
        child->field_A4 = a;
        child->field_A8 = b;
    }
}
