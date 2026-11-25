#include "types.h"

struct Party
{
    u8 pad_0[0x14];
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Mgr
{
    u8 pad_0[2];
    u8 field_2;
    u8 field_3;
    u8 pad_4[0x14];
    u32 *obj18;
    u8 pad_1C[0x2C];
    u32 *obj48;
};

struct Zoid
{
    u8 data[0x94];
};

extern struct Party D_02009480[];
extern struct Mgr D_0201F5F8;
extern u8 D_02030B6C[];
extern struct Zoid D_02020E88[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const u8 D_08000C3E[];
extern const u8 D_08000C96[];
extern const u8 D_08000C9A[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_080F2354[];
extern const u8 D_080F2390[];
void func_0807C290(const u8 *);
void func_0808AC1C(u8, void *);
u32 *func_080771BC(const u8 *, const u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_0808A7F8(u8, u8, u16, u16);
s32 func_0808B590(struct Zoid *, u8, u32 *, u32 *, u8);
s32 func_0808B2F8(u8, void *, void *);
void func_080771F4(u32 *);
void func_0808A86C(u8);

s32 func_0808B6E8(void)
{
    s32 result;
    func_0807C290(D_08000C3E);
    D_02009480[5].field_14 = D_02009480[5].field_15 = D_0201F5F8.field_3;
    D_02009480[5].field_16 = D_0201F5F8.field_2;
    func_0808AC1C(5, 0);
    D_0201F5F8.obj18 = func_080771BC(D_08424594, D_084245A0, 0, 0xC8, 0x68, 0x180, 3, 8, 0);
    D_0201F5F8.obj48 = func_080771BC(D_080F2354, D_080F2390, 0, 0x88, 0x50, 0x30D, 0xF, 8, 0);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    func_0808A7F8(1, 0x10, 0xA0, 0x98);
    result = 0;
    while (1)
    {
        func_0808B590(&D_02020E88[D_02030B6C[D_0201F5F8.field_2]], 6, D_0201F5F8.obj18, D_0201F5F8.obj48, 1);
        func_0807C290(D_08000C96);
        D_0201F5F8.field_3 = D_0200C4A1;
        D_0201F5F8.field_2 = D_0200C4A0;
        if (D_0200C4A2 == 1)
        {
            result = 1;
            break;
        }
        if (D_0200C4A2 == 2)
        {
            result = -1;
            break;
        }
        if (D_0200C4A4 & 8)
        {
            *D_0201F5F8.obj18 |= 0x20000;
            if (func_0808B2F8(5, 0, 0))
            {
                D_0201F5F8.field_2 = result;
                D_0201F5F8.field_3 = result;
            }
            *D_0201F5F8.obj18 &= ~0x20000;
        }
    }
    func_0807C290(D_08000C9A);
    func_080771F4(D_0201F5F8.obj18);
    func_080771F4(D_0201F5F8.obj48);
    func_0808A86C(0);
    func_0808A86C(1);
    return result;
}
