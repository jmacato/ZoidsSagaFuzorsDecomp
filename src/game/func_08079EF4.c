#include "types.h"

struct Win
{
    u32 flags;
    u8 pad4[0xF];
    u8 id;
    u8 pad14[0x4BC];
};

extern u16 D_0300004E[];
extern u8 D_0201F5CA;
extern u8 D_0201F5CB;
extern u32 D_0201F5D0;
extern u32 D_0201F5B8;
extern u32 D_0201F5B4;
extern u32 D_0201F5BC;
extern u32 D_0201F5C0;
extern u32 D_0201F5C4;
extern u16 D_0201F5C8;
extern u16 D_0201F5CC;
extern u16 D_0201F5CE;
extern const u8 D_080C906C[];
extern const u8 D_080C91B8[];
extern const u8 D_080C91F4[];
extern const u8 D_080C9328[];
extern struct Win *D_0200C4FC[10];
extern struct Win D_02009480[10];
extern u32 D_0200C524[];
extern u32 D_0200C5A4[];
extern s32 D_03000060[];
extern u8 D_0201F5D4;
extern u8 D_0201F5D5;

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);
void func_080C8B7C(const void *, void *, u32);
void func_080C8B78(const void *, void *, u32);
void func_0807BE44(void);

void func_08079EF4(u8 bg, u8 charBase, u32 tileBase, u32 tileCount, u32 frameTile, u8 screenBase, u8 pal, u16 bgFlags, u16 objTile, u16 objPal)
{
    vu16 fill16;
    u32 fill32a;
    u32 fill32b;
    u32 i;

    *(bg + D_0300004E) = (screenBase << 8) | (charBase << 2) | bgFlags;
    D_0201F5CA = bg;
    D_0201F5CB = bgFlags;
    D_0201F5D0 = tileBase;
    D_0201F5B8 = tileCount;
    D_0201F5B4 = (u32)((u8 *)(0x06000000 + charBase * 0x4000) + tileBase * 32);
    D_0201F5BC = screenBase * 0x800 + 0x06000000;
    D_0201F5C0 = (u32)((u8 *)(0x06000000 + charBase * 0x4000) + frameTile * 32);
    D_0201F5C4 = frameTile;
    D_0201F5C8 = pal << 12;
    D_0201F5CC = objTile;
    D_0201F5CE = objPal;
    func_080C8B84(D_080C906C, (void *)D_0201F5C0);
    func_0807F860(D_080C91B8, (void *)(0x05000000 + pal * 32), (void *)0x02001480);
    func_080C8B84(D_080C91F4, (void *)(0x06010000 + D_0201F5CC * 32));
    func_0807F860(D_080C9328, (void *)(0x05000200 + D_0201F5CE * 32), (void *)0x02001480);
    for (i = 0; i < 10; i++)
    {
        D_02009480[i].flags = 0;
        D_02009480[i].id = i;
        D_0200C4FC[i] = &D_02009480[i];
    }
    fill16 = frameTile | D_0201F5C8;
    func_080C8B7C((void *)&fill16, (void *)D_0201F5BC, 0x01000400);
    fill32a = 0;
    func_080C8B78(&fill32a, D_0200C524, 0x01000020);
    fill32b = 0;
    func_080C8B78(&fill32b, D_0200C5A4, 0x01000020);
    D_03000060[bg * 2] = D_03000060[bg * 2 + 1] = 0;
    func_0807BE44();
    D_0201F5D4 = 0;
    D_0201F5D5 = 0;
}
