#include "types.h"

struct Pair
{
    u16 field_0;
    u16 id;
};

struct Info
{
    u8 stage;
    u8 field_1;
    u8 pad_2[0x72];
    struct Pair pairs[4];
    u8 pad_84[0x10];
};

struct State
{
    u8 pad_0[0x98];
    u8 mirror;
};

struct Sprite
{
    const void *data;
    u8 pad_4[0xC];
};

extern struct State D_02036E7C;
extern u8 D_02001480[];
extern void *D_02030B48;
extern void *D_02030B4C[3];
extern const struct Sprite D_087B0324[];
extern const u8 D_087B0974[];
extern const s16 D_087AD848[][8][2];
extern const s16 D_087B0FC4[];
extern const u8 D_087AEBA8[][3];

void *func_0807F8A8(u8 stage, u8 a, u8 b, u8 c, u8 mirror, void *buf);
void func_0807FF9C(const void *src, u8 a, u16 b, u8 c);
void *func_080A0388(const void *data, u16 a, u16 b, s16 x, s16 y, u16 c, u16 d, u32 flags, s32 e, u8 flip);
void *memcpy(void *dst, const void *src, u32 n);
void func_080A05A0(void);

void func_080A03FC(struct Info *info)
{
    u8 stage = info->stage;
    u8 i;
    D_02030B48 = func_0807F8A8(stage, info->field_1, 1, 0, D_02036E7C.mirror, D_02001480);
    for (i = 0; i < 3; i++)
    {
        if ((u16)(info->pairs[i].id - 1) < 100 && D_087B0324[info->pairs[i].id].data != 0)
        {
            func_0807FF9C(D_087B0324, info->pairs[i].id * 2 + (i ? 1 : 0), i * 128, i);
            D_02030B4C[i] = func_080A0388(D_087B0974, info->pairs[i].id * 2 + (i ? 1 : 0), 0,
                D_087AD848[stage][i][0] - (i == 2 ? D_087B0FC4[info->pairs[2].id] : 0), D_087AD848[stage][i][1], i * 128, i,
                (D_087AEBA8[stage][i] << 6) | 0x1228 | (D_02036E7C.mirror ? 0x8000 : 0), 0, D_02036E7C.mirror);
        }
        else
            D_02030B4C[i] = 0;
    }
    memcpy(&D_02036E7C, info, 0x94);
    func_080A05A0();
}
