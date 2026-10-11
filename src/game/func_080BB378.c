#include "types.h"

struct Game
{
    u8 pad0[8];
    u32 field_8;
    u8 padC[2];
    u8 field_E;
};

extern struct Game D_02020E3C;
extern u32 D_0200C4AC;
extern const u8 *D_0873F91C[];
extern const u8 *D_0873F988[];

void func_0807BD4C(u8);
u32 func_0809D984(u8);
u32 func_0809D998(u8);
void func_0807B748(const u8 *, u32, u32, u32, s16);
void func_0807A1A4(void);

void func_080BB378(u8 mode, u8 msg)
{
    u8 i, n, color;
    func_0807BD4C(1);
    for (i = 1, n = 0; i < 24; i++)
    {
        if (mode == 0)
            color = 0;
        else if (func_0809D984(i))
        {
            switch (func_0809D998(i))
            {
            case 0:
                color = 1;
                break;
            case 1:
                color = 2;
                break;
            case 2:
                color = 0;
                break;
            }
        }
        if (i == 20)
        {
            if (func_0809D984(20))
            {
                D_0200C4AC = D_02020E3C.field_8 / 1000;
                func_0807B748(D_0873F91C[22], color, 1, 0, n * 2);
                n++;
            }
        }
        else if (func_0809D984(i))
        {
            func_0807B748(D_0873F91C[i], color, 1, 0, n * 2);
            n++;
        }
    }
    if (D_02020E3C.field_E != 0)
    {
        switch (D_02020E3C.field_E)
        {
        case 5:
            func_0807B748(D_0873F91C[24], 0, 1, 0, n * 2);
            break;
        case 10:
            func_0807B748(D_0873F91C[25], 0, 1, 0, n * 2);
            break;
        case 20:
            func_0807B748(D_0873F91C[26], 0, 1, 0, n * 2);
            break;
        }
        n++;
    }
    if (n == 0)
        func_0807B748(D_0873F91C[0], 0, 1, 0, n * 2);
    func_0807BD4C(2);
    func_0807B748(D_0873F988[msg], 0, 2, 0, 0);
    func_0807A1A4();
}
