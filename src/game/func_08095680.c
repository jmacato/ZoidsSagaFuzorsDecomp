#include "types.h"

struct Effect
{
    u8 active;
    u8 pad_1[2];
    u8 side;
    u8 id;
    u8 target;
    u8 pad_6[2];
};

struct Group
{
    u8 id;
    u8 pad_1[7];
    struct Effect effects[32];
};

struct Leader
{
    u8 pad_0[3];
    u8 flags;
};

struct Big
{
    u8 pad_0[0x244];
    u8 cur;
    u8 index;
    u8 pad_246[0xA];
    struct Leader *leader;
    u8 pad_254[4];
    struct Group groups[2][7];
    u8 pad_10C8[0x4E6F - 0x10C8];
    u8 field_4E6F;
    u8 field_4E70;
};

struct Skill
{
    u8 flags;
    u8 field_1;
    u16 type;
    u8 pad_4[3];
    u8 field_7;
};

extern struct Big D_02031A0C;
extern u8 D_0200C4D8;
u32 func_0809A99C(u8, u8);
u32 func_0809D984(u32);
u8 func_0809B834(u8, u8, u32, u32);

s32 func_08095680(struct Skill *sk, u8 target)
{
    u8 side;
    u8 slot;
    u8 k;
    struct Effect *e;

    for (side = 0; side < 2; side++)
    {
        for (slot = 0; slot < 6; slot++)
        {
            if (func_0809A99C(side, slot))
            {
                for (k = 0; k < 32; k++)
                {
                    e = &D_02031A0C.groups[side][slot].effects[k];
                    if (e->active != 0
                        && e->side == D_02031A0C.cur
                        && e->id == D_02031A0C.groups[D_02031A0C.cur][D_02031A0C.index].id
                        && e->target == target)
                        return 7;
                }
            }
        }
    }
    if ((func_0809D984(0x10) && target < 4)
        || ((sk->flags & 1) && ((func_0809D984(0x11) && (u16)(sk->type - 0xD) <= 2) || (func_0809D984(0x13) && (u16)(sk->type - 0x11) <= 1))))
        return 1;
    if ((D_02031A0C.field_4E6F == 0x3A || D_02031A0C.field_4E70 == 0x3A) && target < 4)
    {
        D_0200C4D8 = 0x3A;
        return 2;
    }
    if (!(sk->flags & 1))
    {
        if ((D_02031A0C.field_4E6F == 0xF || D_02031A0C.field_4E70 == 0xF) && (sk->field_1 & 8))
        {
            D_0200C4D8 = 0xF;
            return 2;
        }
        if ((D_02031A0C.field_4E6F == 0x10 || D_02031A0C.field_4E70 == 0x10) && !(sk->field_1 & 8))
        {
            D_0200C4D8 = 0x10;
            return 2;
        }
        if ((D_02031A0C.field_4E6F == 0x16 || D_02031A0C.field_4E70 == 0x16) && (sk->field_1 & 2))
        {
            D_0200C4D8 = 0x16;
            return 2;
        }
        if ((D_02031A0C.field_4E6F == 0x31 || D_02031A0C.field_4E70 == 0x31) && (sk->field_1 & 4))
        {
            D_0200C4D8 = 0x31;
            return 2;
        }
        if ((D_02031A0C.field_4E6F == 0x32 || D_02031A0C.field_4E70 == 0x32) && (sk->field_1 & 1))
        {
            D_0200C4D8 = 0x32;
            return 2;
        }
        if ((D_02031A0C.field_4E6F == 0x34 || D_02031A0C.field_4E70 == 0x34) && (sk->type & 1))
        {
            D_0200C4D8 = 0x34;
            return 2;
        }
    }
    else
    {
        if ((D_02031A0C.field_4E6F == 0x33 || D_02031A0C.field_4E70 == 0x33))
        {
            D_0200C4D8 = 0x33;
            return 2;
        }
    }
    if (!(sk->flags & 1))
        return 0;
    if (sk->type == 0x10 && func_0809B834(D_02031A0C.cur, D_02031A0C.index, 0x23, 0) != 0xFF)
        return 3;
    if (sk->type == 0x11 && func_0809B834(D_02031A0C.cur, D_02031A0C.index, 0x22, 0) != 0xFF)
        return 4;
    if (sk->type == 9 || sk->type == 19)
    {
        if (sk->field_7 == 7)
        {
            if (func_0809B834(D_02031A0C.cur, D_02031A0C.index, 0x17, 0) == 0xFF && func_0809B834(D_02031A0C.cur, D_02031A0C.index, 0x2C, 0) == 0xFF)
                return 0;
            return 5;
        }
        for (slot = 0; slot < 6; slot++)
        {
            if (func_0809B834(D_02031A0C.cur, slot, 0x17, 0) != 0xFF || func_0809B834(D_02031A0C.cur, slot, 0x2C, 0) != 0xFF)
                return 5;
        }
        return 0;
    }
    if (sk->type == 18 && (D_02031A0C.leader->flags & 0x80))
        return 6;
    return 0;
}
