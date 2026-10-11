#include "types.h"

struct Unit
{
    u8 pad_0[0x14];
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Game
{
    u8 pad_0[0x7B47];
    u8 field_7B47;
    u8 field_7B48;
};

void func_0807C290(const void *);
void func_0808A3F0(u8);
void func_0808B098(u8);

extern struct Unit D_02009480[];
extern struct Game D_02020E4C;
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_080031E9[];
extern const u8 D_0800325D[];
extern const u8 D_08003261[];

s32 func_080B4DFC(u8 id, u8 flag)
{
    func_0807C290(D_080031E9);
    D_02009480[3].field_16 = D_02020E4C.field_7B47;
    for (;;)
    {
        func_0807C290(D_0800325D);
        if (D_0200C4A2 == 1)
        {
            if (D_02020E4C.field_7B47 != D_0200C4A0)
        {
            D_02020E4C.field_7B47 = D_0200C4A0;
            D_02020E4C.field_7B48 = 0;
        }
        else
        {
            D_02020E4C.field_7B48 ^= 1;
        }
        D_02009480[id].field_16 = 0;
        D_02009480[id].field_15 = 0;
        D_02009480[id].field_14 = 0;
        func_0808A3F0(flag == 0 ? 6 : 5);
        func_0808B098(id);
        }
        else
            break;
    }
    func_0807C290(D_08003261);
}
