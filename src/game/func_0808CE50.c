#include "types.h"

struct Entry
{
    u16 flags;
    u16 id;
};

struct Info
{
    u8 kind;
    u8 pad_1[0x73];
    struct Entry entries[3];
};

struct State
{
    u8 pad_0[8];
    u8 field_8;
    u8 pad_9[7];
    struct Info *info;
};

struct Part
{
    u8 flags;
    u8 pad_1[0x17];
};

extern struct State D_0201F5F8;
extern void *D_02030B4C[];
extern const struct Part D_08741EF4[];
extern const u8 D_087B0324[];
extern const u8 D_087B0974[];
extern const u8 D_087AEBA8[][3];
extern const s16 D_087AD848[][8][2];
extern const s16 D_087B0FC4[];
extern u8 D_02001480[];
void func_080771F4(void *);
void func_0807FFE0(const u8 *, u8, u32, u8, u8 *);
void *func_08077180(const u8 *, u16, u16, s16, s16, u16, u16, u32, u32);

s32 func_0808CE50(u8 id)
{
    u8 slot;
    u8 pal;
    const u8 *gfx;
    u16 tile;

    slot = D_0201F5F8.field_8;
    if (slot > 2)
        return 0;
    if (D_02030B4C[slot] != 0)
        func_080771F4(D_02030B4C[slot]);
    if ((u8)(id - 1) <= 0x50)
    {
        if (((D_0201F5F8.info->entries[D_0201F5F8.field_8].flags & 1) && !(D_08741EF4[id].flags & 1))
            || ((D_0201F5F8.info->entries[D_0201F5F8.field_8].flags & 2) && (D_08741EF4[id].flags & 1)))
        {
            func_0807FFE0(D_087B0324, D_0201F5F8.field_8 ? id * 2 + 1 : id * 2, D_0201F5F8.field_8 << 7, D_0201F5F8.field_8, D_02001480);
            pal = D_087AEBA8[D_0201F5F8.info->kind][D_0201F5F8.field_8];
            if (pal == 1)
                pal = 2;
            gfx = D_087B0974;
            if (D_0201F5F8.field_8 != 0)
                tile = id * 2 + 1;
            else
                tile = id * 2;
            D_02030B4C[D_0201F5F8.field_8] = func_08077180(gfx, tile, 0, D_087AD848[D_0201F5F8.info->kind][D_0201F5F8.field_8][0] - (D_0201F5F8.field_8 == 2 ? D_087B0FC4[id] : 0),
                D_087AD848[D_0201F5F8.info->kind][D_0201F5F8.field_8][1], D_0201F5F8.field_8 << 7, D_0201F5F8.field_8, (pal << 6) | 0x1128, 0);
            return 1;
        }
    }
    D_02030B4C[D_0201F5F8.field_8] = 0;
    return 0;
}
