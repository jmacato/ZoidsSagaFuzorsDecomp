#include "types.h"

struct GfxEntry
{
    const u8 *gfx;
    const void *pal;
};

struct EffectSet
{
    s16 gfx[8];
    s16 extra[6];
};

extern const struct EffectSet D_087863EE[];
extern const struct GfxEntry D_087B1090[];
extern s32 D_020378E4;
extern s32 D_020378E8;
extern s32 D_020378EC[][4];

void func_0807FF9C(const struct GfxEntry *, u8, u16, u16);

void func_080A3398(s32 id)
{
    const s16 *list;
    const s16 *extra;
    u8 i;
    const u8 *data;

    list = D_087863EE[id].gfx;
    for (i = 0; i < 8 && *list != -1; list++, i++)
    {
        func_0807FF9C(D_087B1090, *list, D_020378E4, D_020378E8);
        D_020378EC[i][0] = *list;
        D_020378EC[i][1] = D_020378E4;
        D_020378EC[i][2] = D_020378E8;
        data = D_087B1090[*list].gfx;
        D_020378E4 += (data[1] | (data[2] << 8) | (data[3] << 16)) / 32;
        D_020378E8++;
    }
    extra = D_087863EE[id].extra;
    for (i = 0; i < 8 && *extra != -1; extra++, i++)
        D_020378EC[i][3] = *extra;
}
