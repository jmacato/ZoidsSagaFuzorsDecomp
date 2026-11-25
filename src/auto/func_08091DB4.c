#include "m2c.h"

M2C_UNK func_08076FA0();
M2C_UNK func_08079EF4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_0808007C(s32, s32, M2C_UNK, s32, s32);
M2C_UNK func_0808A7D8();
M2C_UNK func_0808BB28();
M2C_UNK func_080C8B84(M2C_UNK, M2C_UNK);

void func_08091DB4(void)
{
    *(s16 *)0x0300004C = 0x1440;
    func_08079EF4(2, 2, 0, 0x35C, 0x3C0, 0, 0xE, 0, 0x3E6, 0xF);
    func_080C8B84(0x080F0F84, 0x060157A0);
    func_080C8B84(0x080F339C, 0x06015520);
    func_080C8B84(0x080F3560, 0x050003C0);
    func_0808007C(3, 0, 0x1EF, 4, 4);
    func_08076FA0();
    func_0808A7D8();
    func_0808BB28();
}
