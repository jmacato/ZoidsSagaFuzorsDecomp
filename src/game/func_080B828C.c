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
    u8 field_7B4B;
    u8 field_7B4C;
};

struct Ctx
{
    u8 field_0;
    u8 field_1;
};

void func_08079EF4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_080C8B84(const void *, void *);
void func_0808007C(s32, s32, s32, s32, s32);
void func_08076FA0(void);
void func_08079544(s32, s32);
void func_080B81BC(void);
void func_080B79E0(void);
void func_0808A7F8(u8, u8, u8, u8);
void func_0807C290(const void *);
void func_0807970C(void);
void func_080B7A44(void);
void func_080B7D5C(u8);
void func_08075F20(u16);
void func_0808A86C(u8);
void func_080B8134(void);

extern u16 D_0300004C;
extern struct Game D_02020E4C;
extern struct Ctx D_0201F5F8;
extern const struct Entry D_0877C7FC[][10];
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_080F0F84[];
extern const u8 D_0800711A[];
extern const u8 D_0800710D[];
extern const u8 D_0800714E[];
extern const u8 D_080071AA[];
extern const u8 D_0800717E[];

void func_080B828C(u8 arg)
{
    s32 state;
    u8 done;

    D_0300004C = 0x1440;
    func_08079EF4(2, 2, 0, 0x35C, 0x3C0, 0, 0xE, 0, 0x3E6, 0xF);
    func_080C8B84(D_080F0F84, (void *)0x060157A0);
    func_0808007C(3, 0, 0x1EF, 4, 4);
    func_08076FA0();
    func_08079544(0xF, 0);
    D_0201F5F8.field_1 = 0;
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            if (D_02020E4C.field_7B49 != 0
                && (D_0877C7FC[D_02020E4C.field_7B49][D_02020E4C.field_7B4A].field_0 == 0 || D_02020E4C.field_7B4B == 0)
                && (D_0877C7FC[D_02020E4C.field_7B49][D_02020E4C.field_7B4A].field_4 == 0 || D_02020E4C.field_7B4C == 0))
                func_080B81BC();
            func_080B79E0();
            state = 0x1000;
            break;
        case 0x1000:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0807C290(D_0800711A);
            func_0807970C();
            func_0807C290(D_0800710D);
            if (D_0200C4A2 == 1)
            {
                D_0201F5F8.field_1 = D_0200C4A0;
                switch (D_0200C4A0)
                {
                case 0:
                    state = 0x2000;
                    break;
                case 1:
                    state = 0x3000;
                    break;
                }
            }
            else
            {
                func_0807C290(D_0800714E);
                done = 1;
            }
            break;
        case 0x2000:
            if (D_02020E4C.field_7B49 == 0)
            {
                func_080B7A44();
                func_080B7D5C(arg);
                state = 0;
            }
            else
            {
                func_08075F20(0x114);
                func_0808A86C(0);
                func_0807C290(D_080071AA);
                state = 0x1000;
            }
            break;
        case 0x3000:
            if (D_02020E4C.field_7B49 == 0)
            {
                func_08075F20(0x114);
                func_0808A86C(0);
                func_0807C290(D_0800717E);
                state = 0x1000;
            }
            else
            {
                func_080B7A44();
                func_0808A86C(0);
                func_080B8134();
                state = 0;
            }
            break;
        }
    }
    func_08079544(0x10, 0);
    func_0807970C();
}
