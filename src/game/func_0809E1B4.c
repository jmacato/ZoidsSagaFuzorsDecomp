#include "types.h"

struct Zoid
{
    u8 pad_0[0x34];
    s16 stats[5];
};

void func_0807BA24(s16 value, u8 digits, u8 a, u8 b, u8 c, u16 x, u16 y);

void func_0809E1B4(struct Zoid *zoid, s16 *bonus)
{
    s16 total[5];
    u8 i;
    func_0807BA24(zoid->stats[0], 3, 0, 0x12, 3, 4, 0);
    func_0807BA24(zoid->stats[1], 3, 0, 0x12, 3, 4, 1);
    func_0807BA24(zoid->stats[2], 3, 0, 0x12, 3, 4, 2);
    func_0807BA24(zoid->stats[3], 3, 0, 0x12, 3, 4, 3);
    func_0807BA24(zoid->stats[4], 3, 0, 0x12, 3, 4, 4);
    for (i = 0; i < 5; i++)
        func_0807BA24(bonus[i], 2, 0, 0x12, 3, 9, i);
    if (zoid->stats[0] + bonus[0] < 999)
        total[0] = zoid->stats[0] + bonus[0];
    else
        total[0] = 999;
    if (zoid->stats[1] + bonus[1] < 999)
        total[1] = zoid->stats[1] + bonus[1];
    else
        total[1] = 999;
    if (zoid->stats[2] + bonus[2] < 999)
        total[2] = zoid->stats[2] + bonus[2];
    else
        total[2] = 999;
    if (zoid->stats[3] + bonus[3] < 999)
        total[3] = zoid->stats[3] + bonus[3];
    else
        total[3] = 999;
    if (zoid->stats[4] + bonus[4] < 999)
        total[4] = zoid->stats[4] + bonus[4];
    else
        total[4] = 999;
    for (i = 0; i < 5; i++)
        func_0807BA24(total[i], 3, 0, 0x12, 3, 12, i);
}
