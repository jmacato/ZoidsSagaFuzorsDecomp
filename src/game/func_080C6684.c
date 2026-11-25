#include "types.h"

struct Save
{
    u8 pad_0[0x4E4];
    u8 field_4E4;
    u8 field_4E5;
    u8 field_4E6;
};

extern u8 D_02020E4C[0x7B5C];
extern u8 D_020289A8[0x7B5C];
extern u8 D_02030504[0x40];
extern u8 D_02030544[0x40];
extern u8 D_02030584[0x210];
extern u8 D_02030794[0x210];
extern u32 D_020309A4;
extern u32 D_020309A8;
extern struct Save D_02009480;
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u8 D_02030AE8;
extern const u32 D_0873FC40[];

void func_080C8B7C(const void *src, void *dest, u32 control);
void func_08075E80(s32);
void func_08091DB4(void);
void func_0807C290(void (*)(void));
void func_0802826C(void);
void func_0802829C(void);
void func_0802846E(void);
void func_08079544(s32, s32);
void func_0807970C(void);
void func_080C6568(void);
void func_080C5F20(u32);

void func_080C6684(void)
{
    u8 x;
    u8 y;
    s32 done;

    func_080C8B7C(D_02020E4C, D_020289A8, 0x04000000 | (sizeof(D_02020E4C) / 4));
    func_080C8B7C(D_02030504, D_02030544, 0x04000000 | (sizeof(D_02030504) / 4));
    func_080C8B7C(D_02030584, D_02030794, 0x04000000 | (sizeof(D_02030584) / 4));
    func_080C8B7C(&D_020309A4, &D_020309A8, 0x04000000 | (sizeof(D_020309A4) / 4));

    done = 0;
    x = 0;
    y = 0;
    do
    {
        func_08075E80(0x27);
        func_08091DB4();
        func_0807C290(func_0802826C);
        D_02009480.field_4E4 = D_02009480.field_4E5 = x;
        D_02009480.field_4E6 = y;
        func_0807C290(func_0802829C);
        func_08079544(0xF, 0);
        func_0807970C();
        while (1)
        {
            func_0807C290(func_0802846E);
            x = D_0200C4A1;
            y = D_0200C4A0;
            if (D_0200C4A2 == 1)
            {
                if (D_0200C4A0 == 0x10)
                {
                    func_080C6568();
                    continue;
                }
                D_02030AE8 = 1;
                func_08079544(0x10, 0);
                func_0807970C();
                func_080C5F20(D_0873FC40[D_0200C4A0]);
                D_02030AE8 = 0;
            }
            else
                done = 1;
            break;
        }
    } while (!done);

    func_08079544(0x10, 0);
    func_0807970C();

    func_080C8B7C(D_020289A8, D_02020E4C, 0x04000000 | (sizeof(D_02020E4C) / 4));
    func_080C8B7C(D_02030544, D_02030504, 0x04000000 | (sizeof(D_02030504) / 4));
    func_080C8B7C(D_02030794, D_02030584, 0x04000000 | (sizeof(D_02030584) / 4));
    func_080C8B7C(&D_020309A8, &D_020309A4, 0x04000000 | (sizeof(D_020309A4) / 4));
}
