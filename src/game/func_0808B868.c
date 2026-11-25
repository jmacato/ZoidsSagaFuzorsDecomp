#include "types.h"

struct Unit
{
    u8 pad_0[6];
    s16 hp;
    u8 pad_8[0x5A];
    s16 stats[6];
    s16 field_6E;
    s32 field_70;
};

struct Mgr
{
    u8 pad_0[0x10];
    struct Unit *unit;
};

extern struct Mgr D_0201F5F8;
u8 func_0808A8DC(struct Unit *);
s16 func_080BD430(struct Unit *);
u8 func_0808A904(struct Unit *);
void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);

void func_0808B868(void)
{
    func_0807BA24(D_0201F5F8.unit->hp, 4, func_0808A8DC(D_0201F5F8.unit), 0x12, 8, 4, 0);
    func_0807BA24(D_0201F5F8.unit->stats[0], 4, 0, 0x12, 8, 9, 0);
    func_0807BA24(D_0201F5F8.unit->stats[1], 4, 0, 0x12, 8, 9, 1);
    func_0807BA24(D_0201F5F8.unit->stats[2], 4, 0, 0x12, 8, 9, 2);
    func_0807BA24(D_0201F5F8.unit->stats[3], 4, 0, 0x12, 8, 9, 4);
    func_0807BA24(D_0201F5F8.unit->stats[4], 4, 0, 0x12, 8, 9, 5);
    func_0807BA24(D_0201F5F8.unit->stats[5], 4, 0, 0x12, 8, 9, 6);
    func_0807BA24(D_0201F5F8.unit->field_70, 9, 0, 0x12, 8, 4, 8);
    func_0807BA24(func_080BD430(D_0201F5F8.unit), 4, func_0808A904(D_0201F5F8.unit), 0x12, 1, 4, 0);
    func_0807BA24(D_0201F5F8.unit->field_6E, 4, 0, 0x12, 1, 9, 0);
}
