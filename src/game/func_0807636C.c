#include "types.h"

struct Link
{
    u8 active;
    u8 field_1;
    u8 pad2[2];
    u8 field_4;
    u8 pad5;
    u8 field_6;
    u8 error;
    u8 pad8;
    u8 timer;
    u8 padA[0xA];
    u32 field_14;
    s32 field_18;
    void *field_1C;
    void *field_20;
    void *field_24;
    void *field_28;
};

struct SioCnt
{
    vu32 baudRate:2;
    u32 si:1;
    u32 sd:1;
    u32 id:2;
    u32 error:1;
    u32 enable:1;
    u32 unused:8;
    u32 data:16;
};

extern struct Link D_030024B8;
extern u16 D_03007FF8;

void func_0807636C(void)
{
    struct Link *link = &D_030024B8;
    void *tmp;

    if (link->active)
    {
        if (link->field_4 && link->field_1 && link->field_6)
        {
            vu16 *sio;

            link->field_18 = -1;
            tmp = link->field_28;
            link->field_28 = link->field_24;
            link->field_24 = tmp;
            tmp = link->field_20;
            link->field_20 = link->field_1C;
            link->field_1C = tmp;
            link->field_4 = 0;
            link->field_14 = 0;
            sio = (vu16 *)0x04000128;
            link->error = ((struct SioCnt *)sio)->error;
            ((struct SioCnt *)sio)->data = 0xFEFE;
            sio[0] |= 0x80;
            *(vu16 *)0x0400010E = 0xC0;
        }
    }
    else if (link->timer < 16)
    {
        link->timer++;
    }
    else
    {
        *(vu16 *)0x04000208 = 0;
        D_03007FF8 |= 0x80;
        *(vu16 *)0x04000208 = 1;
    }
}
