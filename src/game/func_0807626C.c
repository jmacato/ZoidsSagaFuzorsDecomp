#include "types.h"

struct Packet
{
    u8 id;
    u8 key;
    u16 checksum;
    u32 data[4];
};

struct Link
{
    u8 active;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 pad5[6];
    u8 field_B;
    u8 padC[0x10];
    struct Packet *packet;
};

extern struct Link D_030024B8;

void func_080C8B7C(const void *, void *, u32);

void func_0807626C(const void *src)
{
    u32 sum = 0;
    u32 i;
    u16 *p;
    struct Link *link = &D_030024B8;

    link->packet->id = link->field_B;
    link->packet->key = link->field_2 ^ link->field_3;
    link->packet->checksum = 0;
    func_080C8B7C(src, link->packet->data, 0x04000004);
    p = (u16 *)link->packet;
    for (i = 0; i < 10; i++)
        sum += p[i];
    link->packet->checksum = ~sum - 12;
    link->field_4 = 1;
}
