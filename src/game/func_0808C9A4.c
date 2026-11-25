#include "types.h"

struct Mgr
{
    u8 pad_0[0x18];
    u32 *field_18;
    u8 pad_1C[0x2C];
    u32 *field_48;
};

extern struct Mgr D_0201F5F8;
extern const u8 D_08000DD5[];
void func_0807C290(const u8 *);

void func_0808C9A4(void)
{
    *D_0201F5F8.field_18 |= 0x20000;
    *D_0201F5F8.field_48 |= 0x20000;
    func_0807C290(D_08000DD5);
}
