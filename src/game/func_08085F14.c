#include "types.h"

struct Script
{
    u8 pad_0[0x280];
    void *field_280;
    u8 pad_284[0x10EC - 0x284];
    u8 field_10EC[8];
    u8 field_10F4;
    u8 pad_10F5[0x1142 - 0x10F5];
    u8 flags;
};

struct Cursor
{
    u8 index;
    u8 pad_1[0x93];
    s32 field_94;
    u8 mirror;
};

struct Game
{
    u8 pad_0[0x4E6F];
    s8 field_4E6F[8];
};

struct Cam
{
    s32 x;
    s32 y;
    s32 field_8;
    s32 field_C;
};

struct Battle
{
    u8 pad_0;
    u8 field_1;
};

struct Obj
{
    u8 pad_0[4];
    s32 x;
    s32 y;
    u8 pad_C[0x80];
    s32 field_8C;
};

extern struct Script D_0201F6DC;
extern struct Cursor D_02036E7C;
extern struct Game D_02031A0C;
extern struct Battle D_02020E3C;
struct Map
{
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0x31];
};

extern struct Map D_0873FCC8[];
extern s16 D_0879F990[][16];
extern struct Cam D_03000060;
extern u16 D_0300004C;
extern u16 D_03000050;
extern u8 D_087B1350[];
extern u8 D_087B14E8[];
void func_08076FA0(void);
void func_080832D8(void);
void func_08082F84(void);
void func_080A31D0(u8, u8, u8, u8, void *);
void func_080A0580(u8, u8);
void func_080C8B7C(const void *, void *, u32);
void func_0807FF9C(const void *, u8, u16, u16);
s32 func_08077180(const void *, u16, u16, s16, s16, u16, u16, u32, void *);
struct Obj *func_08077DF0(u32, void *, void *);
void func_080AC9D4(void);
void func_080A25D8(void);
void func_080A25FC(void);

void func_08085F14(u8 a, u8 b, u8 c, u8 flags)
{
    u16 *p;
    u16 i;
    u32 n;
    struct Obj *obj;
    s32 zero;

    func_08076FA0();
    func_080832D8();
    func_08082F84();
    D_0201F6DC.flags = flags;
    if (!(flags & 2))
        func_080A31D0(D_02020E3C.field_1, D_0873FCC8[a].field_2, c, 1, D_0201F6DC.field_10EC);
    else
        func_080A31D0(D_02020E3C.field_1, D_0873FCC8[a].field_2, c, 2, D_0201F6DC.field_10EC);
    if (D_0201F6DC.field_10F4 != 0)
    {
        D_0300004C |= 0x200;
        D_03000050 = 0x1700;
        p = (u16 *)0x0600B800;
        for (i = 0; i < 0x200; i++)
            *p++ = 0x1C0;
        for (; i < 0x400; i++)
            *p++ = 0x81C1;
        zero = 0;
        func_080C8B7C(&zero, (void *)0x05000100, 0x05000004);
        D_03000060.field_C = 0;
        D_03000060.field_8 = 0;
    }
    func_080A0580(a, b);
    if (D_0201F6DC.flags & 1)
    {
        func_0807FF9C(D_087B1350, 0, 0x380, 0xE);
        D_02036E7C.field_94 = func_08077180(D_087B14E8, 0x58, 0, D_02036E7C.mirror == 0 ? D_0879F990[D_02036E7C.index][2] : 0x100 - D_0879F990[D_02036E7C.index][2], D_0879F990[D_02036E7C.index][3], 0x380, 0xE, D_02036E7C.mirror ? 0x9248 : 0x1248, func_080AC9D4);
    }
    else
        D_02036E7C.field_94 = 0;
    n = (flags & 0xC) >> 2;
    if (n != 0)
    {
        D_02031A0C.field_4E6F[D_02036E7C.mirror] = n + 0x25;
        obj = func_08077DF0(0, func_080A25D8, func_080A25FC);
        D_0201F6DC.field_280 = obj;
        obj->x = D_0879F990[D_02036E7C.index][8];
        obj->y = D_0879F990[D_02036E7C.index][9];
        obj->field_8C = n - 1;
    }
    else
        D_02031A0C.field_4E6F[D_02036E7C.mirror] = n;
}
