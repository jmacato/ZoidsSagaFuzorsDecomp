#include "types.h"

struct Info
{
    u8 pad_0[2];
    u8 level;
    u8 pad_3;
    u32 exp;
    u8 pad_8[0x2C];
    s16 stats[5];
    u8 pad_3E;
    u8 field_3F;
};

struct State
{
    u8 pad_0[0x14];
    struct Info *info;
};

extern struct State D_0201F5F8;
extern const u32 D_08747168[];
extern const u8 *D_08735444[];
extern const u8 D_080F389C[];
void func_0807BA24(s32, u32, u32, u32, u32, u32, u32);
u8 func_0807C100(const u8 *);
void func_0807B748(const u8 *, s8, u8, s16, s32);
void func_0807B77C(const u8 *, u32, u32);

void func_0808DECC(void)
{
    u8 i;
    u8 len;

    func_0807BA24(D_0201F5F8.info->stats[0], 3, 0, 0x16, 8, 8, 0);
    func_0807BA24(D_0201F5F8.info->stats[1], 3, 0, 0x16, 8, 8, 1);
    func_0807BA24(D_0201F5F8.info->stats[2], 3, 0, 0x16, 8, 8, 2);
    func_0807BA24(D_0201F5F8.info->stats[3], 3, 0, 0x16, 8, 8, 3);
    func_0807BA24(D_0201F5F8.info->stats[4], 3, 0, 0x16, 8, 8, 4);
    func_0807BA24(D_0201F5F8.info->level, 2, 0, 0x12, 8, 0xB, 6);
    func_0807BA24(D_0201F5F8.info->exp, 9, 0, 0x12, 8, 4, 7);
    if (D_0201F5F8.info->level < 99)
        func_0807BA24(D_08747168[D_0201F5F8.info->level], 9, 0, 0x12, 8, 4, 8);
    else
        func_0807BA24(0, 9, 0, 0x12, 8, 4, 8);
    len = func_0807C100(D_08735444[D_0201F5F8.info->field_3F]);
    for (i = 0; i < 7 - len; i++)
        func_0807B748(D_080F389C, 0, 8, i + 6, 0xA);
    func_0807B77C(D_08735444[D_0201F5F8.info->field_3F], 0, 8);
}
