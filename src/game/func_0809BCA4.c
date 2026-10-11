#include "types.h"

struct Game
{
    u8 pad_0[0x4E9C];
    u8 selSide;
    s8 selSlot;
};

extern struct Game D_02031A0C;

s32 func_0809A99C(u8 side, u8 slot);
void func_08079E70(void);

void func_0809BCA4(u8 side, s8 slot)
{
    D_02031A0C.selSide = side;
    D_02031A0C.selSlot = slot;
    if (side == 0)
    {
        while (D_02031A0C.selSlot >= 0 && !func_0809A99C(D_02031A0C.selSide, D_02031A0C.selSlot))
            D_02031A0C.selSlot--;
        if (D_02031A0C.selSlot < 0)
        {
            D_02031A0C.selSlot = 5;
            while (D_02031A0C.selSlot > 2 && !func_0809A99C(D_02031A0C.selSide, D_02031A0C.selSlot))
                D_02031A0C.selSlot--;
        }
    }
    else
    {
        while (D_02031A0C.selSlot <= 5 && !func_0809A99C(D_02031A0C.selSide, D_02031A0C.selSlot))
            D_02031A0C.selSlot++;
    }
    func_08079E70();
}
