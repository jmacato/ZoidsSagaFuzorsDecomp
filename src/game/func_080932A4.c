#include "types.h"

struct Item
{
    u8 id;
};

struct Cfg
{
    u8 field_0;
};

extern u32 D_02009480;
extern struct Cfg D_02020E3C;
extern u8 D_0200C4BC;
extern u32 D_0200C4AC;
extern const u8 D_08003D40[];
extern const u8 D_08003D59[];
u32 func_0809A99C(u8, u8);
struct Item *func_0809A908(u8, u8);
void func_0807C290(const u8 *);

void func_080932A4(void)
{
    u8 ids[6];
    u8 counts[6];
    u8 n;
    u8 i;
    u8 j;
    struct Item *item;

    D_02009480 |= 0x20;
    n = 0;
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(1, i))
        {
            item = func_0809A908(1, i);
            for (j = 0; j < n; j++)
            {
                if (ids[j] == item->id)
                {
                    counts[j]++;
                    break;
                }
            }
            if (j == n)
            {
                if (D_02020E3C.field_0 == 0 && *(u16 *)item == 0x10D)
                    ids[n] = 0x9A;
                else
                    ids[j] = item->id;
                counts[j] = 1;
                n++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        D_0200C4BC = ids[i];
        if (counts[i] == 1)
        {
            func_0807C290(D_08003D40);
        }
        else
        {
            D_0200C4AC = counts[i];
            func_0807C290(D_08003D59);
        }
    }
    D_02009480 &= ~0x20;
}
