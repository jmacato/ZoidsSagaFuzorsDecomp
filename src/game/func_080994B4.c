#include "types.h"

struct Obj
{
    u32 flags;
};

struct Slot
{
    u8 flags;
    u8 tile;
    u8 pad_2[2];
    struct Obj *obj;
    struct Obj *icon;
    u8 pad_C[0xC];
};

struct Game
{
    u8 pad_0[0x244];
    u8 side;
    u8 slot;
};

extern struct Slot D_02037B6C[][6];
extern struct Game D_02031A0C;
extern u16 D_02030584;
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;

s32 func_0809B240(void);
void func_080C8FCC(u32 frames);

void func_080994B4(void)
{
    s8 i;
    if ((D_02030584 & 2) && func_0809B240())
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02037B6C[D_02031A0C.side][i].flags & 1)
            {
                if (i != D_02031A0C.slot)
                    D_02037B6C[D_02031A0C.side][i].obj->flags |= 0x400;
                D_02037B6C[D_02031A0C.side][i].icon->flags |= 0x400;
            }
        }
        D_03000056 = 0x3F90;
        D_03000058 = 0x10;
        for (i = 16; i >= 0; i--)
        {
            D_0300005A = i;
            func_080C8FCC(1);
        }
        for (i = 0; i < 6; i++)
        {
            if (D_02037B6C[D_02031A0C.side][i].flags & 1)
            {
                if (i != D_02031A0C.slot)
                    D_02037B6C[D_02031A0C.side][i].obj->flags &= ~0x400;
                D_02037B6C[D_02031A0C.side][i].icon->flags &= ~0x400;
            }
        }
        D_03000056 = 0;
    }
}
