#include "types.h"

struct State
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 flags[10];
    u8 flags2[5];
};

extern struct State D_02030ACC;
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern const u8 D_0801496C[];
extern const u8 D_0801499D[];
extern const u8 D_080149A1[];
extern const u8 D_080149EC[];
extern const u8 D_08014A1F[];
extern const u8 D_08014A23[];
extern const u8 D_08014A26[];

void func_080BA9E8(void);
void func_080BAB00(void);
void func_080BABE4(void);
void func_080BAF2C(void);
void func_080BA970(u8, u8);
void func_0807C290(const u8 *);
void func_0807970C(void);
void func_08079544(u32, u32);
void func_08075F20(u32);
void func_08075E80(u32);
u8 func_08099664(void);

void func_080BB188(void)
{
    u8 r;
    D_02030ACC.id = D_02030ACC.field_1 = 0;
    func_080BA9E8();
    for (;;)
    {
        func_0807C290(D_0801496C);
        func_0807970C();
        func_0807C290(D_0801499D);
        if (D_0200C4A2 != 1)
            goto done;
        D_02030ACC.id = D_0200C4A0;
        D_02030ACC.field_1 = D_0200C4A1;
        if (D_02030ACC.flags[D_02030ACC.id] != 0)
        {
            D_02030ACC.field_2 = 0;
            func_080BAB00();
            for (;;)
            {
                func_0807C290(D_080149EC);
                func_0807970C();
                func_0807C290(D_08014A1F);
                if (D_0200C4A2 == 1)
                {
                    D_02030ACC.field_2 = D_0200C4A0;
                    if (D_02030ACC.flags2[D_02030ACC.field_2] != 0)
                    {
                        func_08079544(0x10, 0);
                        func_0807970C();
                        func_080BABE4();
                        func_08075E80(0x21);
                        r = func_08099664();
                        func_08075E80(2);
                        if (r == 1)
                            func_080BA970(D_02030ACC.id, D_02030ACC.field_2);
                        func_080BA9E8();
                        func_080BAB00();
                        func_08079544(0xF, 0);
                        if (r == 1)
                            func_080BAF2C();
                    }
                    else
                    {
                        func_08075F20(0x114);
                        func_0807C290(D_08014A26);
                    }
                }
                else
                {
                    func_0807C290(D_08014A23);
                    break;
                }
            }
        }
        else
        {
            func_08075F20(0x114);
            func_0807C290(D_080149A1);
        }

    }
done:
    func_08079544(0x10, 0);
    func_0807970C();
}
