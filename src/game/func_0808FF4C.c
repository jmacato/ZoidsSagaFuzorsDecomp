#include "types.h"

struct State
{
    u8 pad_0[6];
    u8 field_6;
    u8 field_7;
};

struct Save
{
    u8 pad_0[0x1824];
    u8 field_1824;
    u8 field_1825;
    u8 field_1826;
};

struct Big
{
    u8 pad_0[0x7A3C];
    u32 bits[5];
};

extern struct State D_0201F5F8;
extern struct Save D_02009480;
extern struct Big D_02020E4C;
extern u16 D_02030F92[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const u8 D_08003142[];
extern const u8 D_080031DC[];
extern const u8 D_080031E0[];
void func_0807C290(const u8 *);
void func_0808B098(u32);
void func_0807BA24(s32, u32, u32, u32, u32, u32, u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808FC78(u8, u32);
void func_08075F20(u32);
u32 func_0808B488(u32);
void func_0808A86C(u32);

s32 func_0808FF4C(void)
{
    s32 result;
    u8 count;
    u8 i;

    func_0807C290(D_08003142);
    D_02009480.field_1824 = D_02009480.field_1825 = D_0201F5F8.field_7;
    D_02009480.field_1826 = D_0201F5F8.field_6;
    func_0808B098(5);
    count = 0;
    for (i = 1; i < 0x9A; i++)
    {
        if (D_02020E4C.bits[i >> 5] & (1 << (i & 31)))
            count++;
    }
    func_0807BA24(count, 3, 0, 0x12, 9, 6, 0);
    func_0807BA24(0x88, 3, 0, 0x12, 9, 0xA, 0);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    func_0808A7F8(1, 0x10, 0xA0, 0x98);
    while (1)
    {
        func_0808FC78(D_02030F92[D_0201F5F8.field_6], 0);
        func_0807C290(D_080031DC);
        D_0201F5F8.field_7 = D_0200C4A1;
        D_0201F5F8.field_6 = D_0200C4A0;
        if (D_0200C4A2 == 1)
        {
            if (!(D_02030F92[D_0201F5F8.field_6] & 0x8000))
            {
                result = 1;
                break;
            }
            func_08075F20(0x114);
        }
        else if (D_0200C4A2 == 2)
        {
            result = -1;
            break;
        }
        else if (D_0200C4A4 & 8)
        {
            if (func_0808B488(5))
            {
                D_0201F5F8.field_6 = 0;
                D_0201F5F8.field_7 = 0;
            }
        }
    }
    func_0807C290(D_080031E0);
    func_0808A86C(0);
    func_0808A86C(1);
    return result;
}
