#include "types.h"

struct Win
{
    u8 pad_0[0x8];
    s32 field_8;
};

struct State
{
    struct Win *field_0;
    u8 field_4;
    u8 field_5;
};

void func_0807B748(const void *, u8, u8, s16, s32);
void func_0807C290(const void *);
void func_0807A1A4(void);

extern u16 D_02030584;
extern struct State D_02030A40;
extern u8 D_0201F5F4;
extern const u8 D_0800593C[];
extern const u8 D_08005949[];
extern const u8 D_08005950[];
extern const u8 D_08005955[];
extern const u8 D_08005ABA[];
extern const u8 D_08005922[];
extern const u8 *const D_0873F630[];

void func_080B9154(void)
{
    u8 a;
    u8 b;

    if (!(D_02030584 & 1))
    {
        a = 1;
        b = 4;
    }
    else
    {
        a = 4;
        b = 1;
    }
    func_0807B748(D_0800593C, a, 4, 8, 0);
    func_0807B748(D_08005949, b, 4, 16, 0);
    if (!(D_02030584 & 2))
    {
        a = 1;
        b = 4;
    }
    else
    {
        a = 4;
        b = 1;
    }
    func_0807B748(D_08005950, a, 4, 8, 2);
    func_0807B748(D_08005955, b, 4, 16, 2);
    if (D_02030A40.field_5 == 0 || D_02030A40.field_4 <= 3)
        func_0807C290(D_0873F630[D_02030A40.field_4]);
    else
        func_0807C290(D_08005ABA);
    if (D_02030A40.field_5 != 0 && D_0201F5F4 != 0)
        func_0807B748(D_08005922, 0, 4, 0, 8);
    else
        func_0807B748(D_08005922, 4, 4, 0, 8);
    func_0807A1A4();
    D_02030A40.field_0->field_8 = (D_02030A40.field_4 << 12) + 0x1000;
}
