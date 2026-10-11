#include "types.h"

struct Script
{
    u8 pad_0[0x1144];
    u8 count;
    u8 pad_1145;
    u16 ids[16];
    u16 xs[16];
    u16 ys[16];
    u8 pad_11A6[0];
    u16 x;
    u16 y;
};

struct TableEntry
{
    const u8 *data;
    u32 field_4;
};

extern struct Script D_0201F6DC;
extern const struct TableEntry D_087B4B8C[];
void func_0807FF9C(const struct TableEntry *, u8, u16, u16);

void func_08082FE4(u8 id)
{
    u8 i;
    u32 len;
    if (D_0201F6DC.count < 16)
    {
        for (i = 0; i < D_0201F6DC.count; i++)
        {
            if (D_0201F6DC.ids[i] == id)
                return;
        }
        len = D_087B4B8C[id].data[1] | (D_087B4B8C[id].data[2] << 8) | (D_087B4B8C[id].data[3] << 16);
        D_0201F6DC.x -= len >> 5;
        D_0201F6DC.y--;
        func_0807FF9C(D_087B4B8C, id, D_0201F6DC.x, D_0201F6DC.y);
        D_0201F6DC.ids[D_0201F6DC.count] = id;
        D_0201F6DC.xs[D_0201F6DC.count] = D_0201F6DC.x;
        D_0201F6DC.ys[D_0201F6DC.count] = D_0201F6DC.y;
        D_0201F6DC.count++;
    }
}
