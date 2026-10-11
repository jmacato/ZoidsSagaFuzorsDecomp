#include "types.h"

struct Script
{
    u8 field_0;
    u8 pad_1[0x10E7];
    u8 field_10E8;
    u8 pad_10E9[0xC];
    u8 name[1];
};

struct Party
{
    u32 flags;
    u8 pad_4[0xC];
    u16 field_10;
    u8 pad_12[0x4BE];
};

extern struct Script D_0201F6DC;
extern u8 *D_0200C4A8;
extern struct Party D_02009480[];
extern const u8 D_08014B77[];
extern const u8 D_08014B7C[];
extern const u8 D_08014B81[];
extern const u8 D_08014B8A[];
extern const u8 D_08014B93[];
extern const u8 D_08014B96[];
void func_080834C8(void);
void func_0807C290(const u8 *);
s32 func_080C8F1C(u8 *, u8 *);
void func_080C8F78(u8 *, u8 *);
void func_0807BD4C(u8);
void func_0807B748(u8 *, s32, s32, s32, s32);
void func_08083C5C(u8, s32, s32);

s32 func_08084B90(u8 id, u8 **pc)
{
    u8 buf[0x40];
    u8 *p;
    D_0201F6DC.field_0 = 1;
    func_080834C8();
    if ((*pc)[1] == 0)
    {
        D_0200C4A8 = *pc + 2;
        if (D_0201F6DC.field_10E8 == 1)
        {
            D_02009480[1].flags &= ~0x800;
            func_0807C290(D_08014B77);
        }
        else
        {
            D_02009480[2].flags &= ~0x800;
            func_0807C290(D_08014B7C);
        }
        D_0201F6DC.name[0] = 0;
    }
    else
    {
        p = buf;
        D_0200C4A8 = *pc + 2;
        while (*D_0200C4A8 != 10)
            *p++ = *D_0200C4A8++;
        *p = 0;
        D_0200C4A8++;
        if (func_080C8F1C(buf, D_0201F6DC.name) == 0)
        {
            if (D_0201F6DC.field_10E8 == 1)
            {
                D_02009480[1].flags |= 0x800;
                D_02009480[1].field_10 = 2;
                func_0807C290(D_08014B81);
            }
            else
            {
                D_02009480[2].flags |= 0x800;
                D_02009480[2].field_10 = 2;
                func_0807C290(D_08014B8A);
            }
        }
        else
        {
            func_080C8F78(D_0201F6DC.name, buf);
            *p++ = 1;
            *p++ = 0;
            *p++ = 10;
            *p = 0;
            if (D_0201F6DC.field_10E8 == 1)
            {
                D_02009480[1].flags |= 0x800;
                func_0807BD4C(1);
                func_0807B748(buf, 2, 1, 0, 0);
                func_0807C290(D_08014B93);
            }
            else
            {
                D_02009480[2].flags |= 0x800;
                func_0807BD4C(2);
                func_0807B748(buf, 2, 2, 0, 0);
                func_0807C290(D_08014B96);
            }
        }
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
