#include "types.h"

struct State
{
    u8 pad_0[4];
    u8 field_4;
    u8 field_5;
    u8 pad_6[0x46];
    u32 *obj;
};

struct Save
{
    u8 pad_0[0x1824];
    u8 field_1824;
    u8 field_1825;
    u8 field_1826;
};

struct Pilot
{
    u8 data[0x40];
};

extern struct State D_0201F5F8;
extern struct Save D_02009480;
extern struct Pilot D_02027A10[];
extern u8 D_02030C26[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const u8 D_08001415[];
extern const u8 D_0800146C[];
extern const u8 D_08001470[];
extern const u8 D_085ECCF0[];
extern const u8 D_085ECCFC[];
void func_0807C290(const u8 *);
void func_0808A084(u32);
void func_0808AF0C(u32, u32, u32);
u32 *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808DC94(struct Pilot *, u8, u32 *, u8);
u32 func_0808B3BC(u32, u32, u32, u32);
void func_080771F4(u32 *);
void func_0808A86C(u32);

s32 func_0808DD80(void)
{
    s32 result;

    func_0807C290(D_08001415);
    D_02009480.field_1824 = D_02009480.field_1825 = D_0201F5F8.field_5;
    D_02009480.field_1826 = D_0201F5F8.field_4;
    func_0808A084(0);
    func_0808AF0C(5, 0, 0);
    D_0201F5F8.obj = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 0xA8, 0x30, 0, 0, 8, 0);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    func_0808A7F8(1, 0x10, 0xA0, 0x98);
    while (1)
    {
        func_0808DC94(&D_02027A10[D_02030C26[D_0201F5F8.field_4]], 6, D_0201F5F8.obj, 1);
        func_0807C290(D_0800146C);
        D_0201F5F8.field_5 = D_0200C4A1;
        D_0201F5F8.field_4 = D_0200C4A0;
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
            *D_0201F5F8.obj |= 0x20000;
            if (func_0808B3BC(5, 0, 0, 0))
            {
                D_0201F5F8.field_4 = 0;
                D_0201F5F8.field_5 = 0;
            }
            *D_0201F5F8.obj &= ~0x20000;
        }
    }
    func_0807C290(D_08001470);
    func_080771F4(D_0201F5F8.obj);
    func_0808A86C(0);
    func_0808A86C(1);
    return result;
}
