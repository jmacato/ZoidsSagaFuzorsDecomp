#include "types.h"

struct Entry
{
    u16 flags;
    u16 id;
};

struct Unit
{
    u8 pad_0[0x74];
    struct Entry entries[8];
};

struct Leader
{
    u8 id;
};

struct Team
{
    u8 field_0;
    u8 slots[3];
};

struct Member
{
    u8 flags;
    u8 field_1;
    u16 type;
    u8 pad_4[0x26C];
};

struct Big
{
    u8 pad_0[0x244];
    u8 cur;
    u8 pad_245[7];
    struct Unit *unit;
    struct Leader *leader;
    u8 pad_254[0x222C - 0x254];
    struct Member members[8];
    u8 pad_35AC[0x4F77 - 0x35AC];
    u8 field_4F77;
    u8 pad_4F78[0xC];
    struct Team teams[2];
};

struct Fx
{
    u8 pad_0[0x9A];
    u8 field_9A;
};

extern struct Big D_02031A0C;
extern struct Fx D_02036E7C;
void func_080A05BC(u8);
u8 func_080A0B54(void);
void func_080C8FCC(u32);
void func_080A1AD0(u8);
void func_080A2AE8(void);
void func_080A2B58(u8, u8, u16);
void func_080A2D70(u8, u32, u32, u16, u8);
void func_080A2CBC(void);
u32 func_080C269C(u8, u8, u8 *);
void func_080A27B8(void);
u16 func_080BFADC(struct Leader *, u32);
void func_080A1BCC(void);
void func_080A0C94(u8, u32);
u8 func_080A3338(void);

void func_080969F0(void)
{
    u8 n;
    u8 i;
    u8 k;
    u8 kind;

    for (n = 0; n < 3; n++)
    {
        if (D_02031A0C.teams[D_02031A0C.cur].slots[n] == 0xFF)
            break;
    }
    for (i = 0; i < n; i++)
    {
        if (D_02036E7C.field_9A != 0xFF && k > 3)
        {
            func_080A05BC(k + 5);
            while (!func_080A0B54())
                func_080C8FCC(1);
        }
        k = D_02031A0C.teams[D_02031A0C.cur].slots[i] & 7;
        func_080A1AD0(k);
        func_080A2AE8();
        func_080C8FCC(1);
        func_080A2B58(D_02031A0C.cur, D_02031A0C.leader->id, D_02031A0C.unit->entries[k].id);
        if (!(D_02031A0C.members[k].flags & 1))
        {
            func_080A2D70(D_02031A0C.leader->id, 0, D_02031A0C.teams[D_02031A0C.cur].slots[i] >> 6, D_02031A0C.unit->entries[k].id, D_02031A0C.cur);
        }
        else
        {
            switch (D_02031A0C.members[k].type)
            {
            case 2:
            case 3:
            case 4:
            case 9:
            case 17:
            case 19:
                kind = 0;
                break;
            case 5:
            case 6:
            case 7:
                kind = 1;
                break;
            case 1:
            case 8:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 18:
                kind = 2;
                break;
            }
            func_080A2D70(D_02031A0C.leader->id, 2, kind, D_02031A0C.unit->entries[k].id, D_02031A0C.cur);
        }
        func_080A2CBC();
        if (func_080C269C(i, k, D_02031A0C.teams[D_02031A0C.cur].slots))
            func_080A27B8();
        if (func_080BFADC(D_02031A0C.leader, 0xF) && !(D_02031A0C.members[k].flags & 1) && (D_02031A0C.members[k].field_1 & 8))
            func_080A1BCC();
        func_080A0C94(k, 0);
        while (!func_080A3338())
            func_080C8FCC(1);
    }
    D_02031A0C.field_4F77 = 1;
}
