#include "types.h"

struct AnimEntry
{
    const u8 *data;
    u8 pad_4[0xC];
};

struct Sprite
{
    u32 flags;
    u8 pad_4[0xA];
    u16 field_E;
};

struct Actor
{
    u8 flags;
    u8 kind;
    u8 id;
    u8 pad_3;
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    u8 state;
    u8 prev_state;
    u8 dir;
    u8 facing;
    u8 counter;
    u8 pad_19[3];
    struct Sprite *obj1;
    struct Sprite *obj2;
    u32 field_24;
    u32 field_28;
    u32 field_2C;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u32 field_3C;
};

extern struct AnimEntry D_087B1D90[];
extern const u8 D_085BFB04[];
extern s32 D_08734B24[][2];
s32 func_080808CC(struct Actor *);
void func_08077204(struct Sprite *, u16);
void func_08080CA4(u8);

void func_08080E28(struct Actor *a)
{
    u8 old;
    u8 target;
    u8 cur;
    const u8 *data;
    const u8 *special;
    u32 d;
    struct Sprite *p;

    if (a->kind == 0xB0)
        return;
    old = a->facing;
    data = D_087B1D90[a->kind].data;
    special = D_085BFB04;
    cur = old;
    if (data != special)
    {
        if (!(a->flags & 0x20))
            target = a->dir;
        else
            target = (a->dir + 4) & 7;
        if (target == a->facing)
            a->counter = 0;
        else if (++a->counter == 3)
        {
            if (target > a->facing)
            {
                if (target - cur <= 3)
                    a->facing = cur + 1;
                else
                    a->facing = (cur - 1) & 7;
            }
            else
            {
                if (cur - target <= 4)
                    a->facing = cur - 1;
                else
                    a->facing = (cur + 1) & 7;
            }
            a->counter = 0;
        }
    }
    else
    {
        if (!(a->flags & 0x20))
            a->facing = a->dir;
        else
            a->facing = (a->dir + 4) & 7;
    }
    switch (a->state)
    {
    case 0:
        if (old != a->facing || a->prev_state != 0)
            func_08077204(a->obj1, func_080808CC(a));
        a->vx = a->vy = 0;
        break;
    case 1:
    case 2:
    case 3:
        if (old != a->facing || a->prev_state == 0)
            func_08077204(a->obj1, func_080808CC(a));
        switch (a->state)
        {
        case 1:
            a->vx = D_08734B24[a->dir][0] / 2;
            a->vy = D_08734B24[a->dir][1] / 2;
            break;
        case 2:
            a->vx = D_08734B24[a->dir][0];
            a->vy = D_08734B24[a->dir][1];
            break;
        case 3:
            a->vx = D_08734B24[a->dir][0] * 2;
            a->vy = D_08734B24[a->dir][1] * 2;
            break;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (old != a->facing || a->prev_state == 0)
            func_08077204(a->obj1, func_080808CC(a));
        a->vx = a->vy = 0;
        a->field_34 += a->field_24;
        a->field_38 += a->field_28;
        while (a->field_34 >= a->field_3C)
        {
            if (a->field_2C == 0)
                a->vx += 0x100;
            else
                a->vx -= 0x100;
            a->field_34 -= a->field_3C;
        }
        while (a->field_38 >= a->field_3C)
        {
            if (a->field_30 == 0)
                a->vy += 0x100;
            else
                a->vy -= 0x100;
            a->field_38 -= a->field_3C;
        }
        break;
    case 7:
        p = a->obj1;
        d = (a->field_24 - 1) / 2 - 3;
        p->field_E -= d;
        a->field_24--;
        break;
    case 8:
        a->vx = a->vy = 0;
        break;
    case 9:
        if (a->field_24 == a->field_28)
        {
            a->obj1->flags &= ~0x20000;
            a->obj2->flags &= ~0x20000;
            a->field_2C++;
            a->field_28 += a->field_2C;
            if (a->field_2C == 16)
            {
                func_08080CA4(a->id);
                return;
            }
        }
        else
        {
            a->obj1->flags |= 0x20000;
            a->obj2->flags |= 0x20000;
        }
        a->field_24++;
        break;
    }
    a->prev_state = a->state;
}
