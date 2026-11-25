#include "types.h"

struct Save
{
    u8 pad_0[0x7A50];
    u32 flags[4];
    u8 list[10];
};

extern struct Save D_02020E4C;
extern const u8 D_0873559C[];
extern const u8 *D_087A58C4[];
extern const u8 D_08003A42[];
void func_0807BE64(u32);
void func_0807BEF4(u32, const u8 *, u32);

void func_08091770(void)
{
    u8 i;
    u8 j;
    u8 id;
    u32 hl;

    func_0807BE64(5);
    func_0807BEF4(5, D_08003A42, 1);
    for (i = 1; i < 0x44; i++)
    {
        id = D_0873559C[i];
        if (D_02020E4C.flags[id >> 5] & (1 << (id & 31)))
        {
            hl = 0;
            for (j = 0; j < 10; j++)
            {
                if (D_02020E4C.list[j] == id)
                {
                    hl = 2;
                    break;
                }
            }
            func_0807BEF4(5, D_087A58C4[id], hl);
        }
        else
        {
            func_0807BEF4(5, D_087A58C4[0], 0);
        }
    }
}
