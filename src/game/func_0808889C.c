#include "types.h"

struct Map
{
    u16 id;
    u8 pad_2[2];
    s32 x;
    s32 y;
    s16 scroll[2][2];
    u16 width;
    u16 height;
    u8 mode;
    u8 field_19;
    u16 entry;
};

struct MapInfo
{
    u16 width;
    u16 height;
    const void *data[6];
    u8 pad_1C;
    u8 mode;
    u16 entry;
    u8 pad_20[4];
};

struct Layers
{
    u16 *layers[2];
};

struct Script
{
    u8 pad_0[0x11A8];
    u16 field_11A8;
    u8 pad_11AA[0x12EC - 0x11AA];
    u32 field_12EC;
};

struct Save
{
    u8 pad_0[0x7B4D];
    u8 field_7B4D;
};

extern struct Map D_020209D8;
extern struct MapInfo D_0877E074[];
extern struct Layers D_02031A0C;
extern const void *D_02031A14;
extern const void *D_02031A18;
extern u8 D_02031A1C[];
extern u8 D_02033A1C[];
extern u8 D_02035A1C[];
extern u8 D_02039A1C[];
extern u8 D_02001480[];
extern u16 D_0300004C;
extern u16 D_0300004E;
extern u16 D_03000050;
extern u16 D_03000052;
extern u16 D_03000056;
extern u16 D_03000058;
extern s32 D_03000060[];
extern const u8 D_080F5CCC[];
extern const u8 D_080F6574[];
extern const u8 D_080F6760[];
extern const u8 D_085BF14C[];
extern struct Save D_02020E4C;
extern struct Script D_0201F6DC;
extern u16 D_08735098[];
void func_08078044(void);
void func_08079EF4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_08076FA0(void);
void func_080C8B84(const void *, void *);
void func_080C8B88(const void *, void *);
void func_0807F860(const void *, void *, void *);
void func_08087D90(void);
u16 func_08087CB8(u8, s16, s16);
void func_080872F4(void);
u8 func_08082F4C(u8);
void func_08082FE4(u8);
void func_080830F4(s32, s32, s32, s32, s32, s32, s32);
void func_08075DA8(u8, void (*)(void));
void func_0808832C(void);
void func_08088354(void);

void func_0808889C(u16 id, s32 x, s32 y)
{
    u16 *vram;
    s16 sx;
    s16 sy;
    u8 i;
    s16 r;
    s16 c;
    u8 n;

    D_020209D8.id = id;
    D_020209D8.x = x;
    D_020209D8.y = y;
    func_08078044();
    func_08079EF4(3, 0, 0x100, 0xC0, 0x1C0, 3, 0xE, 0, 0x3E6, 0xF);
    func_08076FA0();
    func_080C8B84(D_0877E074[id].data[0], (void *)0x06004000);
    func_0807F860(D_0877E074[id].data[1], (void *)0x05000000, D_02001480);
    D_020209D8.mode = D_0877E074[id].mode;
    D_020209D8.entry = D_0877E074[id].entry;
    if (D_020209D8.mode)
    {
        D_02031A0C.layers[0] = (u16 *)D_0877E074[id].data[2];
        D_02031A0C.layers[1] = 0;
        D_02031A14 = D_0877E074[id].data[4];
        D_02031A18 = D_0877E074[id].data[5];
        D_0300004C = (D_0300004C & 0xE000) | 0x1940;
        D_0300004E = 7;
        func_080C8B84(D_080F5CCC, (void *)0x0600C000);
        func_080C8B84(D_080F6574, (void *)0x06000800);
        D_0300004C |= 0x200;
        D_03000050 = 0x10E;
        D_03000056 = 0x1542;
        D_03000058 = 0xC0A;
        func_080C8B84(D_080F6760, (void *)0x06001000);
        D_0300004C |= 0x400;
        D_03000052 = 0x20F;
        func_08087D90();
        D_020209D8.field_19 = 3;
    }
    else
    {
        if (D_0877E074[id].data[2])
        {
            func_080C8B88(D_0877E074[id].data[2], D_02031A1C);
            D_02031A0C.layers[0] = (u16 *)D_02031A1C;
        }
        else
            D_02031A0C.layers[0] = 0;
        if (D_0877E074[id].data[3])
        {
            func_080C8B88(D_0877E074[id].data[3], D_02033A1C);
            D_02031A0C.layers[1] = (u16 *)D_02033A1C;
        }
        else
            D_02031A0C.layers[1] = 0;
        func_080C8B88(D_0877E074[id].data[4], D_02035A1C);
        func_080C8B88(D_0877E074[id].data[5], D_02039A1C);
        D_02031A14 = D_02035A1C;
        D_02031A18 = D_02039A1C;
        D_0300004C = (D_0300004C & 0xE000) | 0x1840;
        if (D_02031A0C.layers[0])
        {
            D_0300004C |= 0x100;
            D_0300004E = 7;
        }
        if (D_02031A0C.layers[1])
        {
            D_0300004C |= 0x200;
            D_03000050 = 0x106;
        }
        D_020209D8.field_19 = 0;
        D_03000056 = 0;
    }
    D_020209D8.width = D_0877E074[id].width;
    D_020209D8.height = D_0877E074[id].height;
    x += -0x7800;
    y += -0x5000;
    if (D_020209D8.mode != 2)
    {
        if (x < 0)
            x = 0;
        else if (x > (D_020209D8.width - 30) << 11)
            x = (D_020209D8.width - 30) << 11;
        if (y < 0)
            y = 0;
        else if (y > (D_020209D8.height - 20) << 11)
            y = (D_020209D8.height - 20) << 11;
    }
    D_020209D8.scroll[0][0] = D_020209D8.scroll[1][0] = x >> 11;
    sx = x >> 11;
    D_020209D8.scroll[0][1] = D_020209D8.scroll[1][1] = y >> 11;
    sy = y >> 11;
    for (i = 0; i < 2; i++)
    {
        if (D_02031A0C.layers[i])
        {
            vram = (u16 *)(0x06000000 + i * 0x800);
            D_03000060[i * 2] = x;
            D_03000060[i * 2 + 1] = y;
            for (r = 0; r <= 20; r++)
                for (c = 0; c <= 30; c++)
                    *(vram + ((sx + c) & 31) + ((sy + r) & 31) * 32) = func_08087CB8(i, sx + c, sy + r);
        }
    }
    func_080C8B84(D_085BF14C, (void *)0x06016D40);
    if (D_02020E4C.field_7B4D)
        func_080872F4();
    else
        D_0201F6DC.field_12EC = 0;
    if (func_08082F4C(0xFF))
    {
        n = 0;
        for (i = 0; D_08735098[i] || D_08735098[i + 1] || D_08735098[i + 2]; i += 3)
        {
            if (D_020209D8.id == D_08735098[i])
            {
                if ((i == 0x27 || i == 0x2D) && !func_08082F4C(0x8B))
                    continue;
                if (n == 0)
                {
                    D_0201F6DC.field_11A8 = 8;
                    func_08082FE4(5);
                }
                func_080830F4(15 - n, 5, 0, D_08735098[i + 1] << 3, D_08735098[i + 2] << 3, 1, 3);
                n++;
            }
        }
    }
    func_08075DA8(3, func_0808832C);
    func_08075DA8(4, func_08088354);
}
