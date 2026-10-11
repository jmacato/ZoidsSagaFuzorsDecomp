#include "types.h"

extern u8 D_0203116C[];
extern u8 D_020311DA;
extern u8 D_020311DB[];
extern u8 D_02031249;
extern u8 *D_087A5AE4[];
extern u8 D_0203198C[];
extern u8 D_020319CC[];
extern const u8 D_080F3680[];
extern const u8 D_080F3684[];
extern const u8 D_080F36A4[];
void func_0807BE64(u8);
void func_080C8F78(u8 *, u8 *);
u8 func_0807C100(u8 *);
void func_0807DB94(u8 *, const u8 *);
void func_0807B830(u8, s32, s32, u8 *);
void func_0807BEF4(u8, u8 *, s32);

void func_0808B1F0(u8 id, u8 mode)
{
    u8 *list;
    u8 n, i, j, pad;
    func_0807BE64(id);
    if (mode == 0)
    {
        list = D_0203116C;
        n = D_020311DA;
    }
    else
    {
        list = D_020311DB;
        n = D_02031249;
    }
    for (i = 0; i < n; i++)
    {
        func_080C8F78(D_0203198C, D_087A5AE4[list[0]]);
        if (list[0] != 0 && list[1] != 0)
        {
            pad = 11 - func_0807C100(D_087A5AE4[list[0]]);
            for (j = 0; j < pad; j++)
                func_0807DB94(D_0203198C, D_080F3680);
            if (mode == 0)
                func_0807DB94(D_0203198C, D_080F36A4);
            else
                func_0807DB94(D_0203198C, D_080F3684);
            func_0807B830(list[1], 1, 0x12, D_020319CC);
            func_0807DB94(D_0203198C, D_020319CC);
        }
        func_0807BEF4(id, D_0203198C, 0);
        list += 2;
    }
}
