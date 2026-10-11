#include "types.h"

struct Part
{
    u16 flags;
    u8 pad_2[0x202];
};

struct Game
{
    u8 pad_0[0x244];
    u8 field_244;
    u8 pad_245[0x3367];
    struct Part parts[2][6];
};

extern struct Game D_02031A0C;
void func_0809D79C(void);
void func_08098AC0(s32);
void func_08083C5C(u8, s32, s32);

s32 func_080879BC(u8 id, u8 **pc)
{
    struct Game *game = &D_02031A0C;
    u8 *p = *pc;
    u8 side, i;
    game->field_244 = p[1];
    side = p[1];
    func_0809D79C();
    for (i = 0; i < 6; i++)
    {
        if ((*pc)[i + 2] != 0)
            D_02031A0C.parts[side][i].flags |= 9;
    }
    func_08098AC0(1);
    func_08083C5C(id, -1, 0);
    return 0;
}
