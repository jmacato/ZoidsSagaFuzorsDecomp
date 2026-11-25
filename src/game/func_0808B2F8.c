#include "types.h"

struct Save
{
    u8 pad_0[0x7B43];
    u8 field_7B43;
    u8 field_7B44;
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
extern const u8 D_08000CA1[];
extern const u8 D_08000D1A[];
extern const u8 D_08000D1E[];
void func_0807C290(const u8 *);
void func_08089CE0(void *, s32);
void func_0808AC1C(u8, void *);

s32 func_0808B2F8(u8 side, void *list, void *buf)
{
    s32 changed = 0;
    func_0807C290(D_08000CA1);
    D_02009480.field_E86 = D_02020E4C.field_7B43;
    while (1)
    {
        func_0807C290(D_08000D1A);
        if (D_0200C4A2 == 1)
        {
            if (D_02020E4C.field_7B43 != D_0200C4A0)
            {
                D_02020E4C.field_7B43 = D_0200C4A0;
                D_02020E4C.field_7B44 = 0;
            }
            else
                D_02020E4C.field_7B44 ^= 1;
            D_02009480.parties[side].field_14 = D_02009480.parties[side].field_15 = D_02009480.parties[side].field_16 = 0;
            func_08089CE0(list, 0);
            func_0808AC1C(side, buf);
            changed = 1;
        }
        else
            break;
    }
    func_0807C290(D_08000D1E);
    return changed;
}
