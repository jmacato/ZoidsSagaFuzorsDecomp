#include "types.h"

struct Def
{
    u8 flags;
    u8 field_1;
    u8 field_2;
    u8 pad_3[0x31];
};

struct Big
{
    u8 pad_0[0x98];
    u8 field_98;
    u8 pad_99[0x80F];
    u32 field_8A8;
    u8 pad_8AC[0x49];
    u8 field_8F5;
};

void func_080A12B0(u8, s32);
void func_080A0580(u8, u8);
void func_0807FC64(u8, u8, u8, u8, u8);
void func_0807C290(const void *);
void func_0807A1A4(void);

extern const struct Def D_0873FCC8[];
extern struct Big D_02036E7C;
extern const u8 D_08007567[];
extern const u8 *const D_087A8874[];

void func_080B969C(u8 idx)
{
    const struct Def *def = &D_0873FCC8[idx];

    D_02036E7C.field_98 = 0;
    if (def->flags & 0x40)
        D_02036E7C.field_8F5 = 11;
    else if (def->flags & 0x80)
        D_02036E7C.field_8F5 = 13;
    else
        D_02036E7C.field_8F5 = 0;
    D_02036E7C.field_8A8 = 0xFFFF0000;
    func_080A12B0(2, 0);
    func_080A0580(idx, 0);
    func_0807FC64(D_02036E7C.field_8F5, def->field_2, 2, 2, 1);
    func_0807C290(D_08007567);
    func_0807C290(D_087A8874[idx]);
    func_0807A1A4();
}
