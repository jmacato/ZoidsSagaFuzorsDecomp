#include "types.h"

void *func_08080B00(u8, u8, s32, s32, u8, u8, u8, u8);
void func_08084078(void *, u8);

void func_08084164(u8 a, u8 b, s32 x, s32 y, u8 c, u8 d, u8 e)
{
    void *obj = func_08080B00(a, b, x, y, c, 0, d, e);
    if (obj != 0)
        func_08084078(obj, 0xFF);
}
