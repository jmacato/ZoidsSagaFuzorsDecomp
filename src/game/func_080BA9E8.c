#include "types.h"

struct State
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 flags[10];
};

extern struct State D_02030ACC;
extern u8 D_02009480[];
extern u8 D_0203198C[];
extern u8 D_020319CC[];
extern const u8 D_0873F910[];
extern const u8 D_080F5B9C[];
extern const u8 D_080F5BA0[];
extern const u8 D_08014945[];

void func_08091DB4(void);
void func_08014956(void);
void func_0807C290(void (*)(void));
u8 func_08082F4C(u8);
u32 func_080BA9B0(u8, u8);
void *memcpy(void *, const void *, u32);
void func_0807DB94(void *, const void *);
void func_0807B830(u32, u32, u32, void *);
void func_0807BEF4(u32, void *, u32);
void func_08079544(u32, u32);

void func_080BA9E8(void)
{
    u8 i, j;
    u8 mode;
    func_08091DB4();
    func_0807C290(func_08014956);
    D_02009480[0x4E5] = D_02030ACC.field_1;
    D_02009480[0x4E4] = D_02030ACC.field_1;
    D_02009480[0x4E6] = D_02030ACC.id;
    for (i = 0; i < 10; i++)
    {
        if (D_0873F910[i] == 0 || func_08082F4C(D_0873F910[i]))
        {
            D_02030ACC.flags[i] = 1;
            mode = 0;
        }
        else
        {
            D_02030ACC.flags[i] = 0;
            mode = 4;
        }
        for (j = 0; j < 5 && func_080BA9B0(i, j); j++)
            ;
        if (j == 5)
            memcpy(D_0203198C, D_080F5B9C, 3);
        else
            memcpy(D_0203198C, D_080F5BA0, 3);
        func_0807DB94(D_0203198C, D_08014945);
        func_0807B830(i + 1, 2, 2, D_020319CC);
        func_0807DB94(D_0203198C, D_020319CC);
        func_0807BEF4(1, D_0203198C, mode);
    }
    func_08079544(0xF, 0);
}
