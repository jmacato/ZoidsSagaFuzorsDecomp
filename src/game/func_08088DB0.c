#include "types.h"

struct Entry
{
    u8 pad_0[0x21];
    u8 field_21;
    u8 pad_22[2];
};

extern struct Entry D_0877E074[];
extern u16 D_020209D8;
void func_08075E80(u8);

void func_08088DB0(void)
{
    func_08075E80(D_0877E074[D_020209D8].field_21);
}
