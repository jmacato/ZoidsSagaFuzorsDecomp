#include "types.h"

struct Zoid
{
    u8 pad_0[0x3C];
    u8 kind;
    u8 pad_3D[0x57];
};

struct Save
{
    struct Zoid zoids[211];
    u8 pad_79FC[0x6E];
    u8 team[6];
};

extern struct Save D_02020E4C;
extern const u8 *D_087A43E0[];
extern const u8 D_080F3664[];
void func_0807BD4C(u32);
void func_0807B748(const u8 *, u32, u32, u32, u32);

void func_08090B3C(void)
{
    u8 i;

    func_0807BD4C(4);
    for (i = 0; i < 6; i++)
    {
        if (D_02020E4C.team[i] != 0)
            func_0807B748(D_087A43E0[D_02020E4C.zoids[D_02020E4C.team[i]].kind], 0, 4, 0, i * 2);
        else
            func_0807B748(D_080F3664, 0, 4, 0, i * 2);
    }
}
