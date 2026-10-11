#include "m2c.h"

extern struct { u8 f_0; } D_0200C4A0;
extern struct { u8 f_0; } D_0200C4A2;
extern struct { u8 pad_0[0x54]; s32 f_54; } D_0201F5F8;

s32 func_080771BC(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_0807C290(M2C_UNK);
M2C_UNK func_0808A7F8(s32, s32, s32, s32);
M2C_UNK func_08091DB4();
M2C_UNK func_080B3C9C();
M2C_UNK func_080B3DC0(u8);
M2C_UNK func_080B4024();

void func_080B42A4(u8 arg0)
{
    func_08091DB4();
    func_08079544(0xF, 0);
    func_0807C290(0x08006032);
    func_080B3C9C();
    D_0201F5F8.f_54 = func_080771BC(0x080F1FD4, 0x080F2008, 0, 0x80, 0x70, 0x2C2, 0xF, 0x20, 0);
loop_1:
    func_0808A7F8(0, 1, 0xD8, 0x98);
    func_0807C290(0x080060EA);
    func_0807970C();
    func_0807C290(0x08006089);
    if (D_0200C4A2.f_0 == 1)
    {
        if (D_0200C4A0.f_0 == 0)
        {
            func_080B3DC0(arg0);
        }
        else
        {
            func_080B4024();
        }
        goto loop_1;
    }
    func_0807C290(0x0800620E);
    func_08079544(0x10, 0);
    func_0807970C();
}
