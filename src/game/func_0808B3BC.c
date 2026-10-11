#include "types.h"

struct Save
{
    u8 pad_0[0x7B45];
    u8 field_7B45;
    u8 field_7B46;
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
extern const u8 D_08001477[];
extern const u8 D_080014C3[];
extern const u8 D_080014C7[];
void func_0807C290(const u8 *);
void func_0808A084(void *);
void func_0808AF0C(u8, u32, u8);

s32 func_0808B3BC(u8 side, void *list, u32 mode, u8 sel)
{
    s32 changed = 0;
    func_0807C290(D_08001477);
    D_02009480.field_E86 = D_02020E4C.field_7B45;
    while (1)
    {
        func_0807C290(D_080014C3);
        if (D_0200C4A2 == 1)
        {
            if (D_02020E4C.field_7B45 != D_0200C4A0)
            {
                D_02020E4C.field_7B45 = D_0200C4A0;
                D_02020E4C.field_7B46 = 0;
            }
            else
                D_02020E4C.field_7B46 ^= 1;
            D_02009480.parties[side].field_14 = D_02009480.parties[side].field_15 = D_02009480.parties[side].field_16 = 0;
            func_0808A084(list);
            func_0808AF0C(side, mode, sel);
            changed = 1;
        }
        else
            break;
    }
    func_0807C290(D_080014C7);
    return changed;
}
