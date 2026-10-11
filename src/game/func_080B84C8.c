#include "types.h"

struct State
{
    u8 pad_0[0x83];
    u8 field_83;
    u8 field_84;
    u8 pad_85[0x4];
    u8 field_89;
};

u8 func_080B8480(void);
void func_0807B748(const void *, u8, u8, s32, s16);
void func_0807B77C(const void *, u8, u8);

extern struct State D_02030A40;
extern const u16 D_08736634[][131];
extern const u16 D_08736C58[][399];
extern u16 D_0203198C[];
extern const u32 D_0873F580[];
extern const u8 D_080F5B30[];
extern const u8 D_080F5B3C[];
extern const u8 D_080F5B48[];
extern const u8 D_080F5B54[];
extern const u8 D_080F5B60[];
extern const u8 D_080F5B6C[];
extern const u8 D_080F5B78[];

void func_080B84C8(void)
{
    const u16 *p;
    u16 remaining;
    u8 i;
    u8 j;

    if (func_080B8480() == 0)
    {
        p = &D_08736634[D_02030A40.field_83][1] + D_02030A40.field_89 * 13;
        remaining = D_08736634[D_02030A40.field_83][0] - D_02030A40.field_89 * 13;
    }
    else
    {
        p = &D_08736C58[D_02030A40.field_84][1] + D_02030A40.field_89 * 13;
        remaining = D_08736C58[D_02030A40.field_84][0] - D_02030A40.field_89 * 13;
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 13; j++)
        {
            if (remaining != 0)
            {
                D_0203198C[0] = *p;
                remaining--;
            }
            else
            {
                D_0203198C[0] = 0x4081;
            }
            D_0203198C[1] = 0;
            func_0807B748(D_0203198C, 0, 9, j * 2 + 1, i * 2);
            p++;
        }
    }
    if (func_080B8480() == 0)
    {
        switch (D_02030A40.field_83)
        {
        case 0:
            func_0807B748(D_080F5B30, 0, 8, 0, 0);
            break;
        case 1:
            func_0807B748(D_080F5B3C, 0, 8, 0, 0);
            break;
        case 2:
            func_0807B748(D_080F5B48, 0, 8, 0, 0);
            break;
        case 3:
            func_0807B748(D_080F5B54, 0, 8, 0, 0);
            break;
        case 4:
            func_0807B748(D_080F5B60, 0, 8, 0, 0);
            break;
        case 5:
            func_0807B748(D_080F5B6C, 0, 8, 0, 0);
            break;
        }
    }
    else
    {
        func_0807B748(D_080F5B78, 0, 8, 0, 0);
        func_0807B77C(&D_0873F580[D_02030A40.field_84], 0, 8);
    }
}
