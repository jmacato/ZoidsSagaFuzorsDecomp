#include "types.h"

struct State
{
    u8 pad_0[0x8CE];
    u8 mode;
    u8 count;
    u8 done;
};

extern struct State D_02036E7C;
extern u16 D_0300000C;
extern const u16 D_0848FC8C[][16];

void func_08078540(u8 a, u8 b, u8 c, u8 d, u8 e);
void func_08078688(u8 a);
void func_08079544(u8 a, u8 b);
void func_0807806C(const void *src, void *dst, u32 size);
void func_080C8FCC(u32 frames);

void func_08097E70(void)
{
    u8 delay = 0;
    u8 frame = 0;
    s32 dir = 0;
    func_08078540(0, 0x50, 0xF0, 0x50, 0x3F);
    func_08078688(0);
    for (;;)
    {
        if (D_02036E7C.done == 0 && D_02036E7C.mode == 0 && (D_0300000C & 2))
        {
            D_02036E7C.mode = 2;
            D_02036E7C.count = 0;
        }
        if (D_02036E7C.mode != 0)
        {
            if (D_02036E7C.mode == 1)
            {
                D_02036E7C.count++;
                func_08078540(0, 0x50 - D_02036E7C.count, 0xF0, 0x50 + D_02036E7C.count, 0x3F);
                if (D_02036E7C.count == 0x20)
                    D_02036E7C.mode = 0;
            }
            else
            {
                D_02036E7C.count++;
                func_08078540(0, 0x30 + D_02036E7C.count, 0xF0, 0x70 - D_02036E7C.count, 0x3F);
                if (D_02036E7C.count == 0x20)
                {
                    D_02036E7C.mode = 0;
                    D_02036E7C.done = 1;
                    func_08079544(2, 1);
                }
            }
        }
        if (!dir)
        {
            if (delay == 0)
            {
                func_0807806C(D_0848FC8C[frame], (void *)0x05000080, 0x20);
                if (frame == 5)
                    dir = 1;
                else
                    frame++;
                delay = 4;
            }
        }
        else
        {
            if (delay == 0)
            {
                func_0807806C(D_0848FC8C[frame], (void *)0x05000080, 0x20);
                if (frame == 0)
                    dir = 0;
                else
                    frame--;
                delay = 4;
            }
        }
        delay--;
        func_080C8FCC(1);
    }
}
