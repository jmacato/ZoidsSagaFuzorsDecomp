#include "types.h"

struct State
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 pad3[0xA];
    u8 flags[5];
};

extern struct State D_02030ACC;
extern u8 D_02009480[];
extern u8 D_0203198C[];
extern u8 D_020319CC[];
extern const u8 D_080F5B9C[];
extern const u8 D_080F5BA0[];
extern const u8 D_0801494C[];

void func_080149E0(void);
void func_0807C290(void (*)(void));
u32 func_080BA9B0(u8, u8);
void *memcpy(void *, const void *, u32);
void func_0807DB94(void *, const void *);
void func_0807B830(u32, u32, u32, void *);
void func_0807BEF4(u32, void *, u32);

void func_080BAB00(void)
{
    u8 i;
    u8 mode;
    func_0807C290(func_080149E0);
    D_02009480[0x9B6] = D_02030ACC.field_2;
    for (i = 0; i < 5; i++)
    {
        if (func_080BA9B0(D_02030ACC.id, i))
        {
            mode = 0;
            D_02030ACC.flags[i] = 1;
            memcpy(D_0203198C, D_080F5B9C, 3);
        }
        else
        {
            if (i == 0 || func_080BA9B0(D_02030ACC.id, i - 1))
            {
                mode = 0;
                D_02030ACC.flags[i] = 1;
            }
            else
            {
                mode = 4;
                D_02030ACC.flags[i] = 0;
            }
            memcpy(D_0203198C, D_080F5BA0, 3);
        }
        func_0807DB94(D_0203198C, D_0801494C);
        func_0807B830(i + 1, 1, 2, D_020319CC);
        func_0807DB94(D_0203198C, D_020319CC);
        func_0807BEF4(2, D_0203198C, mode);
    }
}
