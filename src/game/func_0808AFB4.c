#include "types.h"

extern u8 *D_087A554C[];
extern const u8 D_080F3680[];
extern const u8 D_080F3684[];
void func_080C8F78(void *, u8 *);
u8 func_0807C100(u8 *);
void func_0807DB94(void *, const u8 *);
void func_0807B830(u8, s32, s32, u8 *);

void func_0808AFB4(u16 n, u8 b, u8 width, void *dst, u8 *buf)
{
    u8 i, pad;
    func_080C8F78(dst, D_087A554C[n]);
    pad = width - func_0807C100(D_087A554C[n]);
    for (i = 0; i < pad; i++)
        func_0807DB94(dst, D_080F3680);
    func_0807DB94(dst, D_080F3684);
    func_0807B830(b, 2, 0x12, buf);
    func_0807DB94(dst, buf);
}
