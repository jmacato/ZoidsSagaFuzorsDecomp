#include "types.h"

struct Info
{
    u8 pad_0[0x3F];
    u8 sel;
};

struct State
{
    u8 pad_0[9];
    u8 field_9;
    u8 field_A;
    u8 pad_B[9];
    struct Info *info;
};

struct Save
{
    u8 pad_0[0x4E4];
    u8 field_4E4;
    u8 field_4E5;
    u8 field_4E6;
};

extern struct Save D_02009480;
extern struct State D_0201F5F8;
extern char *D_08735444[];
void func_0807BE64(u32);
void func_0807BEF4(u32, char *, u32);
void func_0807A1A4(void);

void func_0808E1B0(void)
{
    u8 i;

    D_02009480.field_4E4 = D_02009480.field_4E5 = D_0201F5F8.field_A;
    D_02009480.field_4E6 = D_0201F5F8.field_9;
    func_0807BE64(1);
    for (i = 0; i < 7; i++)
        func_0807BEF4(1, D_08735444[i], D_0201F5F8.info->sel == i);
    func_0807A1A4();
}
