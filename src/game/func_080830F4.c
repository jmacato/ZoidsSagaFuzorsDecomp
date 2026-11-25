#include "types.h"

struct Script
{
    u8 pad_0[0x1146];
    u16 ids[16];
    u16 xs[16];
    u16 ys[16];
    u8 pad_11A6[0x106];
    void *objs[16];
};

extern struct Script D_0201F6DC;
extern const u8 D_087B4C14[];
void func_080830A0(u8 *);
void *func_08077180(const u8 *, u8, u8, s16, s16, u16, u16, u32, void (*)(u8 *));

void func_080830F4(u8 slot, u8 kind, u8 b, u16 x, u16 y, u8 mode, u8 prio)
{
    u8 i;
    u32 flags;
    if (D_0201F6DC.objs[slot] == 0)
    {
        for (i = 0; i < 16; i++)
        {
            if (D_0201F6DC.ids[i] == kind)
            {
                if (prio <= 3)
                    flags = (prio << 8) | 0x10C0;
                else
                    flags = 0x412C0;
                switch (mode)
                {
                case 1:
                    flags |= 0x20;
                    break;
                case 2:
                    flags |= 0x10;
                    break;
                case 0:
                    break;
                }
                D_0201F6DC.objs[slot] = func_08077180(D_087B4C14, kind, b, x, y, D_0201F6DC.xs[i], D_0201F6DC.ys[i], flags, kind == 11 ? func_080830A0 : 0);
                return;
            }
        }
    }
}
