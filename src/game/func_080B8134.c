#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u8 field_4;
    u8 field_5;
    u8 pad_6[2];
    u32 field_8;
    u8 pad_C[4];
};

struct Game
{
    u8 pad_0[0x7B49];
    u8 field_7B49;
    u8 field_7B4A;
};

void func_0807C290(const void *);
void func_080B7A60(u8, const struct Entry *, u8);
void func_080B7978(void);

extern struct Game D_02020E4C;
extern const struct Entry D_0877C7FC[][10];
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_08007313[];
extern const u8 D_0800733D[];
extern const u8 D_0800732D[];
extern const u8 D_0800736B[];
extern const u8 D_08007328[];

void func_080B8134(void)
{
    func_0807C290(D_08007313);
    func_0807C290(D_0800733D);
    func_080B7A60(5, &D_0877C7FC[D_02020E4C.field_7B49][D_02020E4C.field_7B4A], 0);
    func_0807C290(D_0800732D);
    if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
    {
        func_0807C290(D_0800736B);
        func_080B7978();
    }
    func_0807C290(D_08007328);
}
