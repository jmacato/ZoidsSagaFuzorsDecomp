#include "types.h"

struct Map
{
    u16 id;
    u16 prev_id;
    u8 pad_4[0x16];
    u16 entry;
};

struct Area
{
    u8 pad_0[0x20];
    u8 area;
    u8 pad_21[3];
};

struct Save
{
    u8 pad_0[6];
    u16 map;
    u8 pad_8[0x10];
    s32 x;
    s32 y;
    u8 pad_20[0x7B20 - 0x20];
    u32 visited[4];
};

extern struct Map D_020209D8;
extern struct Save D_02020E4C;
extern struct Area D_0877E074[];
extern s16 D_08785D6C[][26][3];
extern u16 D_08785FDC[4][26][5];
extern const u8 *D_087A5CA4[][26];
extern u16 D_08735044[][3];
extern s32 D_0200C4AC;
extern const u8 D_0801513C[];
extern const u8 D_08015147[];
extern const u8 D_08015158[];
extern const u8 D_08015163[];
u8 func_0807C100(const u8 *);
void func_0807C290(const u8 *);
void func_0807B748(const u8 *, u32, u32, s16, u32);
void func_0807B77C(const u8 *, u32, u32);
void func_0807A1A4(void);
void func_080C8FCC(u32);

void func_08088354(void)
{
    u16 prev;
    u8 n;
    u8 w;
    u8 mode;
    u8 i;
    u32 k;
    u16 *e;
    struct Map *map;

    if (D_020209D8.id == D_020209D8.prev_id)
        return;
    prev = D_020209D8.prev_id;
    D_020209D8.prev_id = D_020209D8.id;
    n = D_0877E074[D_020209D8.id].area;
    if (n == 0)
        return;
    if (D_020209D8.entry == 0 && n == 0x19)
    {
        D_02020E4C.x = (D_08785D6C[D_020209D8.entry][15][1] + 2) << 11;
        D_02020E4C.y = (D_08785D6C[D_020209D8.entry][15][2] + 2) << 11;
        goto check;
    mode1:
        mode = 1;
        w += 7;
        D_0200C4AC = map->id - e[0] + 1;
        goto done;
    }
    else
    {
        D_02020E4C.x = (D_08785D6C[D_020209D8.entry][n - 1][1] + 2) << 11;
        D_02020E4C.y = (D_08785D6C[D_020209D8.entry][n - 1][2] + 2) << 11;
        D_02020E4C.visited[(n >> 5) + D_020209D8.entry] |= 1 << (n & 31);
        if (D_08785FDC[D_020209D8.entry][n - 1][0] != 0)
            D_02020E4C.map = D_08785FDC[D_020209D8.entry][n - 1][0];
    }
check:
    if (D_0877E074[prev].area == n)
    {
        if (D_020209D8.id >= 0x83 && D_020209D8.id <= 0x84)
            goto show;
        if (D_020209D8.id >= 0x85 && D_020209D8.id <= 0x86)
            goto show;
        if (D_020209D8.id >= 0x87 && D_020209D8.id <= 0x89)
            goto show;
        if (D_020209D8.id >= 0x8A && D_020209D8.id <= 0x8B)
            goto show;
        if (D_020209D8.id >= 0x8C && D_020209D8.id <= 0x8F)
            goto show;
        if (D_020209D8.id >= 0x93 && D_020209D8.id <= 0x95)
            goto show;
        if (D_020209D8.id >= 0x96 && D_020209D8.id <= 0x9A)
            goto show;
        if (D_020209D8.id >= 0x9B && D_020209D8.id <= 0xA2)
            goto show;
        if (D_020209D8.id >= 0xA3 && D_020209D8.id <= 0xA5)
            goto show;
        if (D_020209D8.id >= 0xA6 && D_020209D8.id <= 0xA7)
            goto show;
        if (D_020209D8.id >= 0xA8 && D_020209D8.id <= 0xA9)
            goto show;
        if (D_020209D8.id >= 0xAA && D_020209D8.id <= 0xAB)
            goto show;
        return;
    }
show:
    w = func_0807C100(D_087A5CA4[D_020209D8.entry][n]);
    mode = 0;
    for (i = 0; D_08735044[i][0] != 0 || D_08735044[i][1] != 0 || D_08735044[i][2] != 0; i++)
    {
        map = &D_020209D8;
        e = D_08735044[i];
        if (map->id >= e[0] && map->id <= D_08735044[i][1])
        {
            if (D_08735044[i][2] == 0)
                goto mode1;
            mode = 2;
            w += 4;
            D_0200C4AC = map->id - e[0] + 1;
            break;
        }
    }
done:
    func_0807C290(D_0801513C);
    func_0807B748(D_087A5CA4[D_020209D8.entry][n], 0, 9, (0x1C - w) / 2, 0);
    switch (mode)
    {
    case 1:
        func_0807B77C(D_08015147, 0, 9);
        break;
    case 2:
        func_0807B77C(D_08015158, 0, 9);
        break;
    }
    func_0807A1A4();
    for (k = 0; k < 240; k++)
        func_080C8FCC(1);
    func_0807C290(D_08015163);
}
