#include "types.h"

struct Part
{
    u32 field_0;
    u8 pad_4[0xC];
};

struct Cursor
{
    u8 index;
    u8 pad_1[0x73];
    struct { u16 flags; u16 id; } entries[3];
    u8 pad_80[0x18];
    u8 field_98;
};

extern const struct Part D_087B0324[];
extern const u8 D_087B0974[];
extern const s16 D_087AD848[][8][2];
extern const s16 D_087B0FC4[];
extern const u8 D_087AEBA8[][3];
extern struct Cursor D_02036E7C;
extern void *D_02030B4C[];
void func_0807FF9C(const struct Part *, u8, u16, u16);
void *func_080A0388(const void *, u16, u16, s16, s16, u16, u16, u32, s32, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08086248(u8 id, u8 **pc)
{
    u16 n = ((*pc)[3] << 8) | (*pc)[2];

    if (n <= 100 && D_087B0324[n].field_0 != 0)
    {
        func_0807FF9C(D_087B0324, n * 2 + ((*pc)[1] != 0), (*pc)[1] << 7, (*pc)[1]);
        D_02030B4C[(*pc)[1]] = func_080A0388(D_087B0974, n * 2 + ((*pc)[1] != 0), 0,
            D_087AD848[D_02036E7C.index][(*pc)[1]][0] - ((*pc)[1] == 2 ? D_087B0FC4[n] : 0),
            D_087AD848[D_02036E7C.index][(*pc)[1]][1], (*pc)[1] << 7, (*pc)[1],
            (D_087AEBA8[D_02036E7C.index][(*pc)[1]] << 6) | 0x1328 | (D_02036E7C.field_98 ? 0x8000 : 0), 0, D_02036E7C.field_98);
    }
    D_02036E7C.entries[(*pc)[1]].id = n;
    func_08083C5C(id, -1, 0);
    return 0;
}
