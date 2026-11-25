#include "types.h"

extern u8 D_020311DA;
extern u8 D_0203116C[][2];
extern u8 D_02031249;
extern u8 D_020311DB[][2];
struct Team
{
    u8 pad_0[8];
    u8 members[5][2];
};

u8 func_080BF59C(struct Team *, u8);

void func_0808A72C(struct Team *src, u32 flag)
{
    u8 i, n;
    if (!(flag & 1))
    {
        D_020311DA = 0;
        for (i = 0; i < 5; i++)
        {
            D_0203116C[D_020311DA][0] = src->members[i][0];
            D_0203116C[D_020311DA][1] = src->members[i][1];
            D_020311DA++;
        }
    }
    else
    {
        D_02031249 = 0;
        for (i = 1; i < 0x38; i++)
        {
            n = func_080BF59C(src, i);
            if (n != 0)
            {
                D_020311DB[D_02031249][0] = i;
                D_020311DB[D_02031249][1] = n;
                D_02031249++;
            }
        }
    }
}
