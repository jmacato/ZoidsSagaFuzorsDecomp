#include "types.h"

struct Slot
{
    u16 x;
    u16 y;
};

struct Formation
{
    u8 id;
    u8 pad_1[0x73];
    struct Slot slots[8];
};

struct Mgr
{
    u8 pad_0[8];
    u8 index;
    u8 pad_9[7];
    struct Formation *formation;
};

struct Cam
{
    s32 x;
    s32 y;
};

extern struct Mgr D_0201F5F8;
extern struct Cam D_03000060;
extern s16 D_087AD848[][8][2];
extern s16 D_0879F9A0[][16];
void func_080C8FCC(s32);

void func_0808C8D8(void)
{
    s16 (*home)[16];
    for (;;)
    {
        struct Formation *f = D_0201F5F8.formation;
        home = D_0879F9A0;
        if (f->slots[D_0201F5F8.index].x != 0 || f->slots[D_0201F5F8.index].y != 0)
        {
            D_03000060.x += (((D_087AD848[f->id][D_0201F5F8.index][0] - 0xD0) << 8) - D_03000060.x) / 8;
            if (D_087AD848[f->id][D_0201F5F8.index][1] <= 0x1F)
                D_03000060.y += (0 - D_03000060.y) / 8;
            else
                D_03000060.y += (0x1000 - D_03000060.y) / 8;
        }
        else
        {
            D_03000060.x += (((home[f->id][0] - 0xAC) << 8) - D_03000060.x) / 8;
            D_03000060.y += (0x1000 - D_03000060.y) / 8;
        }
        func_080C8FCC(1);
    }
}
