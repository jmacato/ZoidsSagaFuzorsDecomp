#include "types.h"

struct Entry
{
    u8 id;
    u8 turns;
    u8 damage;
    u8 srcSide;
    u8 srcZoid;
    u8 field_5;
    s16 value;
};

struct Unit
{
    u8 zoid;
    u8 pad_1[7];
    struct Entry entries[32];
};

struct Zoid
{
    u8 pad_0[0x62];
    s16 field_62;
    s16 field_64;
    s16 field_66;
    s16 field_68;
    s16 field_6A;
    s16 field_6C;
    u8 pad_6E[0x26];
};

struct Battle
{
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
};

extern struct Battle D_02031C64;

void func_0809BB30(u8 side, u8 slot)
{
    struct Unit *unit = &D_02031C64.units[side][slot];
    struct Zoid *zoid = &D_02031C64.zoids[side][unit->zoid];
    u8 i;
    for (i = 0; i < 32; i++)
    {
        struct Entry *e = &unit->entries[i];
        switch (e->id)
        {
        case 3:
            zoid->field_62 += e->value;
            break;
        case 4:
            zoid->field_62 -= e->value;
            break;
        case 7:
            zoid->field_64 += e->value;
            break;
        case 8:
            zoid->field_64 -= e->value;
            break;
        case 9:
            zoid->field_66 += e->value;
            break;
        case 10:
            zoid->field_66 -= e->value;
            break;
        case 11:
            zoid->field_68 += e->value;
            break;
        case 12:
            zoid->field_68 -= e->value;
            break;
        case 13:
            zoid->field_6A += e->value;
            break;
        case 14:
            zoid->field_6A -= e->value;
            break;
        case 15:
            zoid->field_6C += e->value;
            break;
        case 16:
            zoid->field_6C -= e->value;
            break;
        case 25:
            zoid->field_66 *= 2;
            break;
        case 26:
            zoid->field_68 *= 2;
            break;
        case 27:
            zoid->field_6A *= 2;
            break;
        case 28:
            zoid->field_6C *= 2;
            break;
        }
    }
}
