#include "types.h"

void func_0807FF9C(const void *, u8, u16, u8);
void func_080C8B84(const void *, void *);

extern const u8 D_087B1D20[];
extern const u8 D_087B4C9C[];
extern const u8 D_08501648[];
extern const u8 D_08501664[];
extern const u8 D_08501B58[];
extern const u8 D_08501B74[];

void func_080B3A38(u8 side, u8 kind)
{
    switch (kind)
    {
    case 0:
        func_0807FF9C(D_087B1D20, 0, side ? 0 : 0x180, side ? 0 : 6);
        break;
    case 1:
        func_0807FF9C(D_087B1D20, 1, side ? 0 : 0x180, side ? 0 : 6);
        break;
    case 2:
        func_0807FF9C(D_087B1D20, 3, side ? 0 : 0x180, side ? 0 : 6);
        func_0807FF9C(D_087B1D20, 4, side == 0 ? 0x1A0 : 0x20, side == 0 ? 9 : 3);
        func_0807FF9C(D_087B1D20, 5, side == 0 ? 0x1B8 : 0x38, 12);
        func_0807FF9C(D_087B1D20, 6, side == 0 ? 0x1D8 : 0x58, 13);
        func_080C8B84(D_08501648, side == 0 ? (void *)0x050002E0 : (void *)0x05000220);
        func_080C8B84(D_08501664, side == 0 ? (void *)0x05000300 : (void *)0x05000240);
        func_080C8B84(D_08501B58, side == 0 ? (void *)0x05000340 : (void *)0x05000280);
        func_080C8B84(D_08501B74, side == 0 ? (void *)0x05000360 : (void *)0x050002A0);
        break;
    case 3:
        func_0807FF9C(D_087B1D20, 2, side ? 0 : 0x180, side ? 0 : 6);
        break;
    }
    func_0807FF9C(D_087B4C9C, 1, 0x360, 13);
}
