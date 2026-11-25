#include "types.h"

struct Big
{
    u8 pad_0[0x4E9D];
    s8 field_4E9D;
};

extern struct Big D_02031A0C;
extern const u8 D_087B4CAC[];
void func_08093DD8(void *);
void *func_08077180(const u8 *, u32, u32, u32, u32, u32, u32, u32, void (*)(void *));
void func_080771F4(void *);
u32 func_0809BD70(u32);

s32 func_08093E60(void)
{
    void *obj;
    s32 result;
    u32 r;

    obj = func_08077180(D_087B4CAC, 0, 0, 0, 0, 0x360, 0xD, 0x60, func_08093DD8);
    for (;;)
    {
        r = func_0809BD70(0);
        if (r == 1)
        {
            result = D_02031A0C.field_4E9D;
            break;
        }
        if (r == 2)
        {
            result = -1;
            break;
        }
    }
    func_080771F4(obj);
    return result;
}
