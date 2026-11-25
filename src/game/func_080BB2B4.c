#include "types.h"

struct State
{
    u8 state;
    u8 ready;
    u8 result;
    u8 field_3;
    u8 field_4;
};

extern struct State D_02030AE0;
extern u8 D_080F5BA4[];
extern u8 D_08024C84[];
extern u32 D_0201F5F0;
extern u8 D_0201F5F6;

void func_080804DC(u8 *, u8, u8 *);
void func_08080390(u8 *, u8, u8 *);
u8 func_080803C4(void);
s32 func_08080510(void);
void func_080C8FCC(u32);
void func_08075E28(u8);
void func_08080370(void);
void func_0807C290(u8 *);
void func_08079544(u32, u32);
void func_0807970C(void);
void func_08075DA8(u8, void (*)(void));
void func_0807DDE0(void);

void func_080BB2B4(void)
{
    struct State *s = &D_02030AE0;
    s->result = s->field_4 = s->ready = s->field_3 = s->state = 0;
    func_080804DC(&s->field_4, 1, D_080F5BA4);
    while (1)
    {
        if (s->state == 1)
        {
            func_08080390(&s->field_3, 1, D_080F5BA4);
            s->state = 2;
        }
        if (s->state == 2)
            s->ready = func_080803C4();
        s->result = func_08080510();
        if ((s->ready && s->field_3) || (s->result && s->field_4))
            break;
        func_080C8FCC(1);
    }
    func_08075E28(1);
    func_08075E28(3);
    func_08075E28(5);
    func_080C8FCC(1);
    func_08080370();
    func_0807C290(D_08024C84);
    func_08079544(0x12, 0);
    func_0807970C();
    D_0201F5F0 = 1;
    D_0201F5F6 = 1;
    func_08075DA8(1, func_0807DDE0);
}
