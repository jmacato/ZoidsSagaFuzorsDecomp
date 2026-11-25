#include "m2c.h"

extern struct { s8 f_0; } D_0201F6DC;
extern struct { u16 f_0; u8 pad_2[0x2]; s32 f_4; s32 f_8; } D_020209D8;

M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_0807C290(M2C_UNK);
M2C_UNK func_08080C20();
M2C_UNK func_08082F84();
M2C_UNK func_08083490();
M2C_UNK func_080834C8();
M2C_UNK func_0808359C();
M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_0808889C(u16, s32, s32);
M2C_UNK func_08089C5C();
M2C_UNK func_080B828C(u8);

s32 func_08085A04(u8 arg0, u8 **arg1)
{
    D_0201F6DC.f_0 = 1;
    func_08083490();
    func_080834C8();
    func_0807C290(0x08014F98);
    func_0808359C();
    func_08079544(0x10, 0);
    func_0807970C();
    func_08089C5C();
    func_080B828C(M2C_FIELD(*arg1, u8 *, 1));
    func_08082F84();
    func_0808889C(D_020209D8.f_0, D_020209D8.f_4, D_020209D8.f_8);
    func_08080C20();
    func_08079544(0xF, 0);
    func_0807970C();
    func_08083C5C(arg0, -1, 0);
    return 0;
}
