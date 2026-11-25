#include "types.h"

struct Win
{
    u32 flags;
};

struct State
{
    u8 pad_0[0x8];
    void *field_8;
    struct Win *field_C[22];
    void *field_64;
    void *field_68;
    void *field_6C;
    u8 pad_70[0xC];
    u8 *field_7C;
    u8 field_80;
    u8 field_81;
    u8 field_82;
    u8 pad_83[0x2];
    u8 field_85;
    u8 pad_86;
    u8 field_87;
    u8 pad_88;
    u8 field_89;
};

void func_080C8B84(const void *, void *);
void *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_08077204(void *, u16);
void func_080B8664(u8, u8);
void func_080B84A8(void);
void func_0807A1A4(void);
void func_08079E70(void);

extern struct State D_02030A40;
extern const u8 D_080F0F84[];
extern const u8 D_080C9748[];
extern const u8 D_080C977C[];
extern const u8 D_080C93C8[];
extern const u8 D_080C93F0[];
extern const u8 D_080C9470[];
extern const u8 D_080C9498[];
extern const u8 D_080F20C0[];
extern const u8 D_080F20FC[];

void func_080B870C(u8 *list, u8 a, u8 b, u8 c)
{
    u8 i;

    func_080C8B84(D_080F0F84, (void *)0x06010000);
    D_02030A40.field_87 = 0;
    D_02030A40.field_85 = 0;
    D_02030A40.field_64 = func_080771BC(D_080C9748, D_080C977C, 0, 8, 0x48, 0x3F4, 0xF, 0x20, 0);
    D_02030A40.field_68 = func_080771BC(D_080C93C8, D_080C93F0, 0, 0xE8, 0x48, 0x3E6, 0xF, 0x20030, 0);
    D_02030A40.field_6C = func_080771BC(D_080C9470, D_080C9498, 0, 0xE8, 0x90, 0x3E8, 0xF, 0x20030, 0);
    D_02030A40.field_7C = list;
    D_02030A40.field_80 = a;
    D_02030A40.field_81 = b;
    D_02030A40.field_82 = 0;
    while (*list != 0)
    {
        D_02030A40.field_82++;
        list += 2;
    }
    D_02030A40.field_82 %= D_02030A40.field_80;
    for (i = 0; i < D_02030A40.field_80; i++)
        D_02030A40.field_C[i] = func_080771BC(D_080F20C0, D_080F20FC, 2, (c + i) * 8, 0x38, 0xB, 0xF, 8, 0);
    func_08077204(D_02030A40.field_C[D_02030A40.field_82], 1);
    D_02030A40.field_C[D_02030A40.field_82]->flags |= 0x200008;
    D_02030A40.field_8 = func_080771BC(D_080F20C0, D_080F20FC, 3, 0xF0, 0, 0xB, 0xF, 8, 0);
    D_02030A40.field_89 = 0;
    func_080B8664(0, 0xFF);
    func_080B84A8();
    func_0807A1A4();
    func_08079E70();
}
