#include "types.h"

struct Zoid
{
    u8 data[0x94];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x2D];
    u8 zoid;
    u8 pad_2F[0x11];
};

struct Save
{
    u8 pad_0[6];
    u16 map;
    u8 pad_8[8];
    s32 x;
    s32 y;
    u8 pad_18[0xB];
    u8 field_23;
    u16 entry;
};

struct Roster
{
    struct Zoid zoids[186];
    struct Pilot pilots[58];
};

extern struct Save D_02020E4C;
extern struct Roster D_02020E88;
extern u16 D_08785FDC[4][26][5];
void func_080BE378(struct Zoid *);
void func_080BDE24(u8, s32);
void func_08088D98(u16, s32, s32, s32);
u8 func_08082F4C(u8);

void func_080892C8(void)
{
    u8 i;
    struct Pilot *pilot;
    u16 *e;
    for (i = 1; i <= 0x34; i++)
    {
        pilot = &D_02020E88.pilots[i];
        if (pilot->id == 1)
            break;
    }
    func_080BE378(&D_02020E88.zoids[pilot->zoid]);
    func_080BDE24(pilot->zoid, 1);
    for (i = 0; i < 4; i++)
    {
        for (e = D_08785FDC[i][0]; e[0] != 0; e += 5)
        {
            if (e[0] == D_02020E4C.map)
                break;
        }
        if (e[0] != 0)
            break;
    }
    func_08088D98(e[0], e[1] << 11, e[2] << 11, 0);
    if (D_02020E4C.field_23 != 0 && (i == 0 || func_08082F4C(0xFF)))
    {
        D_02020E4C.entry = i;
        D_02020E4C.x = e[3] << 11;
        D_02020E4C.y = e[4] << 11;
    }
}
