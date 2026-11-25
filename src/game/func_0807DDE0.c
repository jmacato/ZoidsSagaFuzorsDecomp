#include "types.h"

struct Unk0201F6DC
{
    u8 pad0[0x2CA];
    u8 field_2CA;
};

extern struct Unk0201F6DC D_0201F6DC;
extern u32 D_0201F5F0;

void func_0807DE28(void);
void func_0807E550(void);
void func_0807DD34(void);

void func_0807DDE0(void)
{
    D_0201F6DC.field_2CA = 0;
    for (;;)
    {
        switch (D_0201F5F0)
        {
        case 0:
            func_0807DE28();
            D_0201F5F0 = 1;
            break;
        case 1:
            func_0807E550();
            D_0201F5F0 = 2;
            break;
        case 2:
            func_0807DD34();
            D_0201F5F0 = 1;
            break;
        }
    }
}
