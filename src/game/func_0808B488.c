#include "types.h"

struct Save
{
    u8 pad_0[0x7B47];
    u8 field_7B47;
    u8 field_7B48;
};

struct Party
{
    u8 pad_0[0x14];
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Menu
{
    struct Party parties[3];
    u8 pad_E70[0x16];
    u8 field_E86;
};

extern struct Save D_02020E4C;
extern struct Menu D_02009480;
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_080031E9[];
extern const u8 D_0800325D[];
extern const u8 D_08003261[];
void func_0807C290(const u8 *);
void func_0808A3F0(s32);
void func_0808B098(u8);

s32 func_0808B488(u8 side)
{
    s32 changed = 0;
    func_0807C290(D_080031E9);
    D_02009480.field_E86 = D_02020E4C.field_7B47;
    while (1)
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
                D_02020E4C.field_7B48 ^= 1;
            D_02009480.parties[side].field_14 = D_02009480.parties[side].field_15 = D_02009480.parties[side].field_16 = 0;
            func_0808A3F0(0);
            func_0808B098(side);
            changed = 1;
        }
        else
            break;
    }
    func_0807C290(D_08003261);
    return changed;
}
