#include "types.h"

union SioMulti
{
    unsigned long long raw;
    u16 data[4];
};

struct SioCnt
{
    u32 baudRate:2;
    u32 si:1;
    u32 sd:1;
    u32 id:2;
    u32 error:1;
    u32 enable:1;
    u32 unused:8;
    u32 data:16;
};

struct Link
{
    u8 active;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 sending;
    u8 received;
    u8 field_6;
    u8 error;
    u8 field_8;
    u8 timer;
    u8 padA[0xA];
    s32 sendIndex;
    s32 recvIndex;
    u16 *sendNext;
    u16 *sendCur;
    u16 *recvCur;
    u16 *recvNext;
};

extern struct Link D_030024B8;
extern u16 D_03007FF8;

void func_08076400(void)
{
    union SioMulti recv;
    u16 *tmp;
    s32 i;
    s32 idx;

    recv.raw = *(unsigned long long *)0x04000120;
    D_030024B8.error = ((vu32 *)0x04000128)[0] << 25 >> 31;
    if (recv.data[0] == 0xFEFE && D_030024B8.recvIndex > 9)
    {
        D_030024B8.recvIndex = -1;
        tmp = D_030024B8.recvNext;
        D_030024B8.recvNext = D_030024B8.recvCur;
        D_030024B8.recvCur = tmp;
        if (D_030024B8.sending)
        {
            tmp = D_030024B8.sendCur;
            D_030024B8.sendCur = D_030024B8.sendNext;
            D_030024B8.sendNext = tmp;
            D_030024B8.sending = 0;
            D_030024B8.sendIndex = 0;
        }
        *(vu16 *)0x04000208 = 0;
        D_03007FF8 |= 0x80;
        *(vu16 *)0x04000208 = 1;
    }
    if (D_030024B8.sendIndex <= 9)
        ((struct SioCnt *)0x04000128)->data = D_030024B8.sendCur[D_030024B8.sendIndex];
    if (D_030024B8.sendIndex <= 10)
        D_030024B8.sendIndex++;
    if (D_030024B8.recvIndex >= 0)
    {
        idx = D_030024B8.recvIndex;
        for (i = 0; i < 2; i++)
            *(D_030024B8.recvCur + i * 12 + idx) = recv.data[i];
        if (D_030024B8.recvIndex == 9)
            D_030024B8.received = 1;
    }
    if (D_030024B8.recvIndex <= 10)
        D_030024B8.recvIndex++;
    if (D_030024B8.active)
        *(vu16 *)0x0400010E = 0;
    if (D_030024B8.sendIndex <= 10 && D_030024B8.active)
    {
        *(vu16 *)0x04000128 |= 0x80;
        *(vu16 *)0x0400010E = 0xC0;
    }
    D_030024B8.timer = 0;
}
