#include "types.h"

struct Save
{
    u8 pad0[4];
    u16 field_4;
    u8 pad6[2];
    u32 field_8;
    u32 field_C;
};

struct Unk020209D8
{
    u8 pad0[0x6A];
    u8 field_6A;
    u8 pad6B[0x3B9];
    u32 field_424;
};

struct Unk0201F6DC
{
    u8 pad0[0x2CA];
    u8 field_2CA;
};

extern struct Save D_02020E4C;
extern struct Unk020209D8 D_020209D8;
extern struct Unk0201F6DC D_0201F6DC;
extern u8 D_0201F5F5;

void func_080836FC(void);
void func_0808889C(u16, u32, u32);
void func_08080640(void);
void func_08083BBC(u16);
void func_080897FC(void);
void func_0807EFF0(void);
s32 func_08089390(void);
void func_08088630(void);
s32 func_08089938(void);
void func_080C8FCC(u32);
u8 func_08087A54(void);
void func_08089C5C(void);

void func_0807DD34(void)
{
    s32 done = 0;
    s32 started;
    u8 result;

    do
    {
        func_080836FC();
        func_0808889C(D_02020E4C.field_4, D_02020E4C.field_8, D_02020E4C.field_C);
        func_08080640();
        func_08083BBC(D_02020E4C.field_4);
        D_0201F5F5 = 0;
        started = 0;
        for (;;)
        {
            result = func_08087A54();
            if (result == 1)
                break;
            if (result == 2)
            {
                done = 1;
                break;
            }
            if (D_020209D8.field_424 == 0)
                func_080897FC();
            if (D_0201F6DC.field_2CA)
            {
                D_0201F6DC.field_2CA = 0;
                func_0807EFF0();
                if (func_08089390())
                    break;
            }
            if (!started)
            {
                func_08088630();
                D_020209D8.field_6A = 1;
                started = 1;
            }
            if (func_08089938())
                break;
            func_080C8FCC(1);
        }
    } while (!done);
    func_08089C5C();
}
