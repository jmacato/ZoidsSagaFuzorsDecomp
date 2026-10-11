#include "types.h"

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u16 flags;
    s16 hp;
    s16 en;
    u8 pad_A[0x58];
    s16 maxHp;
    s16 maxEn;
};

struct Slot
{
    u8 flags;
    u8 tile;
    u8 pad_2[0x16];
};

extern struct Slot D_02037B6C[][6];
extern u8 D_02001480[];
extern const u8 D_08500594[];

s32 func_0809A99C(u8 side, u8 slot);
struct Zoid *func_0809A908(u8 side, u8 slot);
void func_080C8B78(const void *src, void *dst, u32 size);
void func_0809F814(u8 value, u8 *dst);

void func_0809F910(u8 side, u8 slot)
{
    struct Zoid *zoid;
    u8 hp, en;
    if (func_0809A99C(side, slot))
    {
        zoid = func_0809A908(side, slot);
        func_080C8B78(D_08500594, D_02001480, 0x40);
        if (!(zoid->flags & 0x10))
            hp = zoid->hp * 20 / zoid->maxHp;
        else
            hp = 0xFF;
        en = zoid->en * 20 / zoid->maxEn;
        func_0809F814(hp, &D_02001480[0x29]);
        func_0809F814(en, &D_02001480[0xA9]);
        func_080C8B78(D_02001480, (void *)(0x06016000 + (D_02037B6C[side][slot].tile << 8)), 0x40);
    }
}
