#include "types.h"

struct Save
{
    u8 pad_0[0x7B49];
    u8 field_7B49;
    u8 field_7B4A;
    u8 counts[2];
};

extern struct Save D_02020E4C;
struct Item
{
    u8 kind;
    u8 pad_1[3];
};

struct Reward
{
    struct Item items[4];
};

extern const struct Reward D_0877C7FC[][10];
extern u32 D_0200C4AC;
extern u16 D_0300000E;
extern const u8 D_08003A5A[];
extern const u8 D_08003AAD[];
extern const u8 D_08003ABA[];
extern const u8 D_08003AAA[];
extern const u8 D_08003ACB[];
void func_0807C290(const u8 *);
void func_080B7A60(u32, const struct Reward *, u32);
void func_0807B748(const u8 *, u32, u32, u32, s16);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u32);

void func_08091AFC(void)
{
    const struct Reward *p;
    u8 n;
    u8 i;

    if (D_02020E4C.field_7B49 != 0)
    {
        func_0807C290(D_08003A5A);
        p = &D_0877C7FC[D_02020E4C.field_7B49][D_02020E4C.field_7B4A];
        func_080B7A60(4, p, 1);
        n = 0;
        for (i = 0; i < 2; i++)
        {
            if (p->items[i].kind != 0)
            {
                if (D_02020E4C.counts[i] != 0)
                {
                    D_0200C4AC = D_02020E4C.counts[i];
                    func_0807B748(D_08003AAD, 1, 4, 0xC, (n << 18) + 0x80000 >> 16);
                }
                else
                {
                    func_0807B748(D_08003ABA, 2, 4, 0xA, (n << 18) + 0x80000 >> 16);
                }
                n++;
            }
        }
        func_0807A1A4();
        do
        {
            func_080C8FCC(1);
        } while (!(D_0300000E & 3));
        func_08075F20(0xCD);
        func_0807C290(D_08003AAA);
    }
    else
    {
        func_08075F20(0x114);
        func_0807C290(D_08003ACB);
    }
}
