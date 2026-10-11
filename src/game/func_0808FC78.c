#include "types.h"

struct Shop
{
    u8 items[2];
    u8 zoid;
    u8 pad_3;
    u32 price;
};

struct Unit
{
    u8 kind;
    u8 pad_1[0x93];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Unit units[211];
    u8 pad_7A38[4];
    u32 flags[8];
    u32 money;
};

extern struct Save D_02020E4C;
extern struct Unit D_02020E88[];
extern struct { u8 pad_0[0xE12]; u8 owned[101]; } D_02027A10;
extern const struct Shop D_08759BF4[];
extern const u8 *D_087A559C[];
extern const u8 *D_087A43E0[];
extern const u8 D_080031C5[];
extern const u8 D_080031A2[];
extern const u8 D_08003264[];
extern const u8 D_0800327F[];
extern const u8 D_0800329A[];
extern const u8 D_080031D4[];
extern const u8 D_080F38AC[];
void func_0807BD4C(u32);
void func_0807B748(const u8 *, u32, u32, u32, u32);
void func_0807B77C(const u8 *, u32, u32);
u8 func_0807C100(const u8 *);
u32 func_08089C98(struct Unit *, u8);
void func_0807BA24(u32, u32, u32, u32, u32, u32, u32);

void func_0808FC78(u8 id, u8 mode)
{
    u8 win;
    u8 none;
    const struct Shop *shop;
    u8 i;
    u8 row;
    u8 color;
    u8 item;
    struct Save *save;

    none = 0;
    win = 6;
    if (mode != 0)
    {
        win = 5;
        if (mode == 1)
            win = 7;
    }
    if (none == 0)
        shop = &D_08759BF4[id];
    else
        shop = D_08759BF4;
    func_0807BD4C(win);
    save = &D_02020E4C;
    if (save->flags[id >> 5] & (1 << (id & 31)))
    {
        func_0807B77C(D_080031A2, 0, win);
        row = 2;
        for (i = 0; i < 2; i++)
        {
            if (shop->items[i] != 0)
            {
                item = shop->items[i];
                color = D_02027A10.owned[item] != 0 ? 2 : 1;
                func_0807B748(D_087A559C[shop->items[i]], color, win, 13 - func_0807C100(D_087A559C[item]), row);
                row += 2;
            }
        }
        if (row == 2)
            func_0807B748(D_087A559C[shop->items[0]], 2, win, 11, row);
        if (shop->zoid < 200)
        {
            color = 1;
            for (i = 1; i < 0xBA; i++)
            {
                if (D_02020E4C.units[i].kind == shop->zoid)
                {
                    color = 2;
                    break;
                }
            }
            func_0807B748(D_087A43E0[shop->zoid], color, win, 13 - func_0807C100(D_087A43E0[shop->zoid]), 8);
        }
        else
        {
            color = 1;
            for (i = 1; i < 0xBA; i++)
            {
                if (func_08089C98(&D_02020E88[i], shop->zoid))
                {
                    color = 2;
                    break;
                }
            }
            if (shop->zoid == 200)
                func_0807B748(D_08003264, color, win, 0, 8);
            else if (shop->zoid == 201)
                func_0807B748(D_0800327F, color, win, 0, 8);
            if (mode == 0 || mode == 2)
                func_0807B748(D_0800329A, 1, win, 0, 10);
        }
    }
    else
    {
        asm("" :: "r"(save));
        func_0807B748(D_080031C5, 0, win, 3, 5);
    }
    if (D_02020E4C.money >= shop->price)
        color = 2;
    else
        color = 1;
    if (mode == 0)
    {
        func_0807BD4C(win + 1);
        if (D_02020E4C.flags[id >> 5] & (1 << (id & 31)))
        {
            func_0807BA24(shop->price, 9, color, 0x12, win + 1, 3, mode);
            func_0807B77C(D_080F38AC, 0, win + 1);
        }
        else
        {
            func_0807B748(D_080031D4, 0, win + 1, 3, mode);
        }
    }
    else if (mode == 1)
    {
        func_0807BA24(shop->price, 9, color, 0x12, win, 3, 10);
        func_0807B77C(D_080F38AC, 0, win);
    }
}
