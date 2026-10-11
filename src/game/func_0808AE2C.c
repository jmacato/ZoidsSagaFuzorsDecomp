#include "types.h"

struct Item
{
    u8 flags;
    u8 pad_1[0x17];
};

extern u16 D_02030F7C;
extern u16 D_02030C5C[][2];
extern struct Item D_08741EF4[];
extern const u8 D_08001268[];
extern u8 D_0203198C[];
extern u8 D_020319CC[];
void func_0807BE64(u8);
void func_0807BEF4(u8, const u8 *, u8);
void func_0808ADB8(u16, u8, u8, u8 *, u8 *);

void func_0808AE2C(u8 id, u32 mode)
{
    u8 i, state;
    func_0807BE64(id);
    for (i = 0; i < D_02030F7C; i++)
    {
        if (D_02030C5C[i][0] == 0)
            func_0807BEF4(id, D_08001268, 1);
        else
        {
            func_0808ADB8(D_02030C5C[i][0], D_02030C5C[i][1], 10, D_0203198C, D_020319CC);
            if (((mode & 1) && !(D_08741EF4[D_02030C5C[i][0]].flags & 1)) || ((mode & 2) && (D_08741EF4[D_02030C5C[i][0]].flags & 1)))
                state = 4;
            else
                state = 0;
            func_0807BEF4(id, D_0203198C, state);
        }
    }
}
