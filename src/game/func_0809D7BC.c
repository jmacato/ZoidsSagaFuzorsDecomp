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

struct Zoid
{
    u8 pad_0[6];
    s16 hp;
    u8 pad_8[0x5A];
    s16 maxHp;
};

struct Item
{
    u16 flags;
    s16 amount;
};

struct Game
{
    u8 pad_0[0x4E92];
    u8 items[1];
};

extern const struct Item D_08759BCC[];
extern struct Entry D_02031408;
extern struct Game D_02031A0C;

void func_0809FCD4(u8 a, u8 side, u8 slot, u8 b);
void func_080A0108(void);
void func_0809F7CC(u8 side, u8 slot);
void func_0809F764(u8 side);
void func_080B3A38(u8 side, u8 a);
struct Zoid *func_0809A908(u8 side, u8 slot);
void func_080BE06C(struct Zoid *zoid, s16 v);
void func_080B3B94(u8 msg, u8 side, u8 slot, s16 v);
void func_080B3C84(void);
u8 func_0809B834(u8 side, u8 slot, u8 id, struct Entry *out);
void func_0809B5BC(u8 side, u8 slot, u8 id);
void func_0809F910(u8 side, u8 slot);
void func_0809F784(u8 side, u8 slot);
void func_0809AA44(u8 side);
void func_0809F9DC(u8 side);
void func_0809F7AC(u8 side);

void func_0809D7BC(u8 side, u8 slot, u8 item)
{
    struct Zoid *zoid;
    const struct Item *it;
    s16 heal;
    u8 other;
    func_0809FCD4(5, side, slot, 0);
    func_080A0108();
    func_0809F7CC(side, slot);
    func_0809F764(side == 0);
    func_080B3A38(side, 2);
    zoid = func_0809A908(side, slot);
    it = &D_08759BCC[item];
    if (it->flags & 4)
    {
        heal = zoid->maxHp - zoid->hp;
        zoid->hp = zoid->maxHp;
    }
    else if (it->flags & 2)
    {
        func_080BE06C(zoid, heal = zoid->maxHp / 2);
    }
    else
    {
        heal = it->amount;
        func_080BE06C(zoid, it->amount);
    }
    if (heal != 0)
    {
        func_080B3B94(6, side, slot, heal);
        func_080B3C84();
    }
    if ((it->flags & 8) && func_0809B834(side, slot, 0x26, &D_02031408) != 0xFF)
    {
        func_0809B5BC(side, slot, 0x26);
        func_080B3B94(0x29, side, slot, 0);
        func_080B3C84();
    }
    if ((it->flags & 0x10) && func_0809B834(side, slot, 0x25, &D_02031408) != 0xFF)
    {
        func_0809B5BC(side, slot, 0x25);
        func_080B3B94(0x24, side, slot, D_02031408.value);
        func_080B3C84();
    }
    if (side == 0)
        D_02031A0C.items[item]--;
    func_0809F910(side, slot);
    func_0809F784(side, slot);
    other = side == 0;
    func_0809AA44(other);
    func_0809F9DC(other);
    func_0809F7AC(other);
}
