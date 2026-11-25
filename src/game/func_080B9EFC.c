#include "types.h"

struct Entry
{
    u8 id;
    u8 field_1;
    u8 items[4];
    u8 pad_6[10];
};

struct Save
{
    u32 seen[5];
    u32 owned[5];
    u8 flags[32];
};

void func_08091DB4(void);
void func_0807C290(const void *);
void func_0807BA24(u8, u8, u8, u8, u8, u8, u8);
void func_08079544(s32, s32);

extern struct Save D_02030504;
extern const u8 D_0873F833[][3][31];
extern const struct Entry D_08741CE4[];
extern const u8 D_08007393[];

void func_080B9EFC(void)
{
    u8 count;
    u8 i;
    u8 j;
    u8 k;
    u8 id;
    const struct Entry *e;

    func_08091DB4();
    func_0807C290(D_08007393);
    count = 0;
    for (i = 1; i < 154; i++)
    {
        if (D_02030504.seen[i >> 5] & (1 << (i & 31)))
            count++;
    }
    func_0807BA24(count, 3, 0, 2, 1, 0xB, 0);
    count = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3 && D_0873F833[i][j][0] != 0; j++)
        {
            for (k = 1; k <= D_0873F833[i][j][0]; k++)
            {
                id = D_0873F833[i][j][k];
                if (D_02030504.owned[id >> 5] & (1 << (id & 31)))
                    count++;
            }
        }
    }
    func_0807BA24(count, 3, 0, 2, 1, 0xB, 2);
    count = 0;
    i = 0;
    e = &D_08741CE4[i];
    while (e->id != 0)
    {
        if (D_02030504.flags[i] & 0x80)
        {
            for (j = 0; j < 4 && e->items[j] != 0 && ((D_02030504.flags[i] >> j) & 1); j++)
                ;
            if (j == 4 || e->items[j] == 0)
                count++;
        }
        i++;
        e = &D_08741CE4[i];
    }
    func_0807BA24(count, 3, 0, 2, 1, 0xB, 4);
    func_08079544(0xF, 0);
}
