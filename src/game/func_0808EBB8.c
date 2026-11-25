#include "types.h"

struct Info
{
    u8 pad_0[0x3E];
    u8 field_3E;
};

struct State
{
    u8 pad_0[0x14];
    struct Info *info;
};

extern struct State D_0201F5F8;
extern const s16 D_0874731C[][6];
void func_0807BA24(s16, u32, u32, u32, u32, u32, u32);

void func_0808EBB8(void)
{
    u8 *p = &D_0201F5F8.info->field_3E;

    if (*p != 0)
    {
        const s16 *v = D_0874731C[*p];

        func_0807BA24(v[0], 3, 0, 0x16, 2, 8, 0);
        func_0807BA24(v[1], 3, 0, 0x16, 2, 8, 1);
        func_0807BA24(v[2], 3, 0, 0x16, 2, 8, 2);
        func_0807BA24(v[3], 3, 0, 0x16, 2, 8, 3);
        func_0807BA24(v[4], 3, 0, 0x16, 2, 8, 4);
    }
}
