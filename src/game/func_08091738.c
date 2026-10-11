#include "types.h"

extern void *D_087A58C4[];
extern struct { u8 pad_0[0xE9C]; u8 ids[10]; } D_02027A10;
void func_0807BE64(u32);
void func_0807BEF4(u32, void *, u32);

void func_08091738(void)
{
    u8 i;

    func_0807BE64(4);
    for (i = 0; i < 10; i++)
        func_0807BEF4(4, D_087A58C4[D_02027A10.ids[i]], 0);
}
