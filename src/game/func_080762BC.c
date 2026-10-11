#include "types.h"

struct Link
{
    u8 active;
    u8 field_1;
    u8 received;
    u8 valid;
    u8 pad4[0x28];
    u8 *packets;
};

extern struct Link D_030024B8;

void func_080C8B7C(const void *, void *, u32);

u8 func_080762BC(u8 *dst)
{
    u8 (*recv)(void) = (u8 (*)(void))0x03002358;
    vu32 unused = 0;
    vu32 zero;
    s32 i;
    u32 j;
    u16 *packet;
    u32 sum;

    u8 ok;

    ok = recv();
    D_030024B8.valid = 0;
    if (ok)
    {
        for (i = 0; i < 2; i++)
        {
            packet = (u16 *)(D_030024B8.packets + i * 0x18);
            sum = 0;
            for (j = 0; j < 10; j++)
                sum += packet[j];
            if ((s16)sum == -13)
            {
                func_080C8B7C(packet + 2, dst + i * 16, 0x04000004);
                D_030024B8.valid |= 1 << i;
            }
            zero = 0;
            func_080C8B7C((void *)&zero, packet + 2, 0x05000004);
        }
    }
    D_030024B8.received |= D_030024B8.valid;
    return D_030024B8.valid;
}
