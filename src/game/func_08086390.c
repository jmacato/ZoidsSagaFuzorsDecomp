#include "types.h"

struct Game
{
    u8 pad_0[0x4E6F];
    u8 field_4E6F[8];
};

struct Cursor
{
    u8 pad_0[0x98];
    u8 index;
};

struct Script
{
    u8 pad_0[0x280];
    void *field_280;
    u8 pad_284[0xEBF];
    u8 field_1143;
};

extern struct Game D_02031A0C;
extern struct Cursor D_02036E7C;
extern struct Script D_0201F6DC;
void func_080A1AD0(u8);
u8 func_080A2250(void);
void func_080A2158(void);
void func_080C8FCC(s32);
u8 func_080A24F0(void);
void func_080A24B4(void);
void func_08077E6C(void *);
void func_080A27B8(void);
void func_080A1BCC(void);
void func_080A0C94(u8, s32);
void func_080A3358(void);
void func_08083C5C(u8, s32, s32);

s32 func_08086390(u8 id, u8 **pc)
{
    func_080A1AD0((*pc)[1]);
    if (func_080A2250() == 1)
    {
        func_080A2158();
        while (func_080A2250() <= 1)
            func_080C8FCC(1);
    }
    if (!func_080A24F0())
    {
        func_080A24B4();
        while (!func_080A24F0())
            func_080C8FCC(1);
    }
    if (D_02031A0C.field_4E6F[D_02036E7C.index] != 0)
    {
        func_08077E6C(D_0201F6DC.field_280);
        func_080A27B8();
    }
    if (D_0201F6DC.field_1143 != 0)
    {
        func_080A1BCC();
        D_0201F6DC.field_1143 = 0;
    }
    func_080A0C94((*pc)[1], 0);
    func_080A3358();
    func_08083C5C(id, -1, 0);
    return 0;
}
