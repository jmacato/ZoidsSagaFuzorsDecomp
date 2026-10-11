#include "types.h"

struct Link
{
    u8 active;
    u8 state;
    u8 received;
    u8 valid;
    u8 field_4;
    u8 pad5;
    u8 field_6;
    u8 error;
    u8 retries;
    u8 timer;
    u8 padA;
    u8 frame;
    u8 padC[8];
    s32 sendIndex;
};

struct SioCnt
{
    u32 baudRate:2;
    u32 si:1;
    u32 sd:1;
    u32 id:2;
    u32 error:1;
    u32 enable:1;
    u32 unused8:6;
    u32 irq:1;
    u32 unused15:17;
};

extern struct Link D_030024B8;

void func_080762BC(void *);

u32 func_08076158(void *buf)
{
    struct SioCnt *cnt = (struct SioCnt *)0x04000128;
    u32 sio = *(u32 *)cnt;
    u8 t;
    u32 status, v, w;
    u8 valid;
    u16 recv;
    u32 retry;

    switch (D_030024B8.state)
    {
    case 0:
        if (!(u8)(sio & 0x30))
        {
            t = sio & 0x88;
            if (t != 8)
                break;
            if (!(u8)(sio & 4) && D_030024B8.sendIndex == 12)
            {
                *(vu16 *)0x04000208 = 0;
                *(vu16 *)0x04000200 &= 0xFF7F;
                *(vu16 *)0x04000200 |= 0x40;
                *(vu16 *)0x04000208 = 1;
                cnt->irq = 0;
                *(vu32 *)0x0400010C = 0xABFB;
                *(vu16 *)0x04000202 = 0xC0;
                D_030024B8.active = t;
            }
        }
        D_030024B8.state = 1;
    case 1:
        if (D_030024B8.received)
        {
            if (D_030024B8.retries < 8)
                D_030024B8.retries++;
            else
                D_030024B8.state = 2;
        }
    case 2:
        func_080762BC(buf);
        break;
    }
    D_030024B8.frame++;
    valid = D_030024B8.valid;
    recv = D_030024B8.received << 8;
    if (D_030024B8.active == 8)
        v = 0x80 | recv | valid;
    else
        v = valid | recv;
    status = v;
    if (D_030024B8.error)
        status |= 0x1000;
    retry = (D_030024B8.retries >> 3) << 15;
    if ((sio << 26) >> 30 > 1)
        w = status | 0x2000 | retry;
    else
        w = status | retry;
    return w;
}
