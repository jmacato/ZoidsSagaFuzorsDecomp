#include "types.h"

struct Child
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x20];
    void (*callback)(void *);
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 state;
    s32 field_90;
    s32 field_94;
    s32 timer;
};

extern u32 (*D_03000010)(void);
extern s32 D_03000060[];

s16 func_08075AAC(s16);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_08077E6C(struct Obj *);

void func_080AD308(struct Obj *obj)
{
    struct Child *child;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A3770(obj, 0, 0, obj->x + (D_03000010() * 65 >> 15) - 32,
            128 - func_08075AAC(0x36) * 192 / 256 - (obj->field_90 ? 16 : 0), 0x120, 0x4A, 0xC00, 1);
        obj->state++;
        break;
    case 1:
        if (++obj->timer == 16)
        {
            obj->child[1] = func_080A3770(obj, 1, 0, !(obj->flags & 2) ? obj->child[0]->x : 0xF0 - obj->child[0]->x, obj->child[0]->y, 0x400, 0xC0, 0x100, 0);
            child = obj->child[0];
            child->x += D_03000060[4] / 256;
            child->y += D_03000060[5] / 256;
            child->flags |= 0x5000;
            child->callback = 0;
            obj->state++;
        }
        break;
    case 2:
        child = obj->child[0];
        if (child == 0 || (!(obj->flags & 2) ? child->x - D_03000060[4] / 256 > 256 : child->x - D_03000060[4] / 256 < -16))
            func_08077E6C(obj);
        break;
    }
}
