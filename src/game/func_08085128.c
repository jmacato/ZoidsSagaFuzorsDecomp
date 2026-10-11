#include "types.h"

struct Actor
{
    u8 flags;
    u8 id;
    u8 pad_2;
    u8 field_3;
    s32 x;
    s32 y;
    u8 pad_C[0x38];
};

struct Map
{
    u8 pad_0[0x6C];
    struct Actor actors[14];
    struct Actor *current;
};

struct Cam
{
    s32 x;
    s32 y;
};

extern u8 D_0201F6DC;
extern struct Map D_020209D8;
extern struct Cam D_03000060;
extern s16 D_03005718;
extern s16 D_0300571A;
void func_0807970C(void);
void func_08079544(s32, s32);
void func_08083C5C(u8, s32, s32);

s32 func_08085128(u8 id)
{
    u8 *flag = &D_0201F6DC;
    u32 one = 1;
    struct Actor *a;
    u32 i;
    *flag = one;
    func_0807970C();
    func_08079544(0xE, 0);
    if (D_020209D8.current != 0)
    {
        D_03005718 = (D_020209D8.current->x - D_03000060.x) / 256;
        D_0300571A = (D_020209D8.current->y - D_03000060.y) / 256;
    }
    else
    {
        for (i = 0; i < 14; i++)
        {
            a = &D_020209D8.actors[i];
            if ((a->flags & 1) && a->field_3 == 6)
                break;
        }
        if (i < 14)
        {
            D_03005718 = (a->x - D_03000060.x) / 256;
            D_0300571A = (a->y - D_03000060.y) / 256;
        }
        else
        {
            D_03005718 = 0x78;
            D_0300571A = 0x50;
        }
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
