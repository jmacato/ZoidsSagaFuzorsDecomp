#include "types.h"

struct Obj
{
    u32 flags;
    s32 y;
};

struct State
{
    u8 pad_0[0x95C];
    struct Obj **field_95C;
    struct Obj *field_960;
};

extern struct State D_02036E7C;
extern const u8 D_087A0CF0[][2];
extern const u16 D_087A0CFE[];
extern const u8 D_087B4AE4[];
extern const u8 D_08637278[];
extern const u8 D_08637284[];
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;

void func_0807FF9C(const void *src, u8 a, u16 b, u8 c);
struct Obj *func_080771BC(const void *a, const void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
void func_080A12B0(u8 mode, s32 arg);
void func_08075F20(u16 se);
void func_080C8FCC(u32 frames);

void func_080A2B58(u8 mode, u8 id, u16 key)
{
    u16 i, j, alpha;
    if (mode == 1)
        return;
    for (i = 0; D_087A0CF0[i][0] != 0; i++)
    {
        if (id == D_087A0CF0[i][0])
        {
            for (j = 0; D_087A0CFE[j] != 0; j++)
            {
                if (key == D_087A0CFE[j])
                {
                    func_0807FF9C(D_087B4AE4, D_087A0CF0[i][1], 0x180, 3);
                    D_02036E7C.field_960 = func_080771BC(D_08637278, D_08637284, 0, 0xF0, 0, 0x180, 0, 0x408, 0);
                    if (D_02036E7C.field_95C != 0 && *D_02036E7C.field_95C != 0)
                        (*D_02036E7C.field_95C)->flags |= 0x400;
                    func_080A12B0(0x13, 0);
                    D_03000056 = 0x3FD7;
                    alpha = 0;
                    D_03000058 = 0x10;
                    func_08075F20(0xE7);
                    while (D_02036E7C.field_960->y > 0x7000)
                    {
                        D_02036E7C.field_960->y -= 0x800;
                        alpha++;
                        D_0300005A = alpha / 2;
                        func_080C8FCC(1);
                    }
                    return;
                }
            }
            return;
        }
    }
}
