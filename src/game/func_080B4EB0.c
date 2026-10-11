#include "types.h"

struct Req
{
    u8 item1;
    u8 item2;
    u8 item3;
    u8 pad_3;
    u32 cost;
};

struct Game
{
    u8 pad_0[0x79D6];
    u8 owned[0x86];
    u32 money;
};

struct Win
{
    u8 pad_0[0x268C];
    u16 field_268C;
    u16 field_268E;
};

void func_0807C290(const void *);
void func_08089CE0(u8, u8);

extern const struct Req D_08759BF4[];
extern struct Game D_02020E4C;
extern u8 D_02030C25;
extern const u8 *const D_0873660C[];
extern u8 D_0200C4D4;
extern struct Win D_02009480;
extern const u8 D_080064E0[];
extern const u8 D_080064F4[];
extern const u8 D_08006512[];
extern const u8 D_0800652A[];

s32 func_080B4EB0(u8 idx)
{
    u8 list[4][2];
    u8 n = 0;
    u8 i;
    const struct Req *req = &D_08759BF4[idx];

    if (req->item1 != 0 && D_02020E4C.owned[req->item1] == 0)
    {
        list[n][0] = 1;
        list[n][1] = req->item1;
        n++;
    }
    if (req->item2 != 0 && D_02020E4C.owned[req->item2] == 0)
    {
        list[n][0] = 1;
        list[n][1] = req->item2;
        n++;
    }
    if (req->item3 != 0)
    {
        func_08089CE0(1, req->item3);
        if (D_02030C25 == 0)
        {
            list[n][0] = 2;
            n++;
        }
    }
    if (D_02020E4C.money < req->cost)
    {
        list[n][0] = 3;
        n++;
    }
    if (n != 0)
    {
        func_0807C290(D_0873660C[n - 1]);
        for (i = 0; i < n; i++)
        {
            switch (list[i][0])
            {
            case 1:
                D_0200C4D4 = list[i][1];
                func_0807C290(D_080064E0);
                break;
            case 2:
                func_0807C290(D_080064F4);
                break;
            case 3:
                func_0807C290(D_08006512);
                break;
            }
            D_02009480.field_268C = 0;
            D_02009480.field_268E += 2;
        }
        func_0807C290(D_0800652A);
        return 0;
    }
    return 1;
}
