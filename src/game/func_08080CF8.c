#include "types.h"

struct Actor
{
    u8 flags;
    u8 owner;
    u8 id;
    u8 kind;
    u8 pad_4[0x15];
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
    u8 pad_1C[0x28];
};

struct Map
{
    u8 pad_0[0x6C];
    struct Actor actors[14];
    u8 pad_424[4];
    u8 field_428;
};

extern struct Map D_020209D8;
void func_08081B80(struct Actor *);
void func_080810D0(struct Actor *);
void func_08081410(struct Actor *);
void func_08080E28(struct Actor *);
void func_080814D8(u8, struct Actor *);
void func_08081FFC(struct Actor *);
void func_08081D68(struct Actor *);
void func_08082B4C(struct Actor *);
void func_0808071C(struct Actor *);
void func_08081C7C(struct Actor *);
void func_08082BB4(struct Actor *);
void func_08082DA4(void);

void func_08080CF8(void)
{
    u8 i;
    struct Actor *a;
    if (D_020209D8.field_428 != 0)
        return;
    for (i = 0; i < 14; i++)
    {
        a = &D_020209D8.actors[i];
        if ((a->flags & 1) && (a->flags & 8))
            func_08081B80(a);
    }
    for (i = 0; i < 14; i++)
    {
        a = &D_020209D8.actors[i];
        if (!(a->flags & 1) || a->kind == 0xFF || a->kind == 2 || a->kind == 4 || a->kind == 5)
            continue;
        if (!(a->flags & 0x10))
        {
            switch (a->kind)
            {
            case 0:
                func_080810D0(a);
                func_08080E28(a);
                break;
            case 1:
                func_08081410(a);
                func_08080E28(a);
                break;
            case 3:
                func_08080E28(a);
                continue;
            case 6:
            case 7:
                func_080814D8(i, a);
                func_08080E28(a);
                if (!(a->flags & 1))
                    continue;
                break;
            }
            func_08081FFC(a);
            func_08081D68(a);
            func_08082B4C(a);
            a->field_1B = a->field_1A;
            func_0808071C(a);
            if (a->field_1B == a->field_1A)
                a->field_19 = 0;
            else
                a->field_19 = a->field_1A;
        }
        else
            func_08081C7C(a);
        func_08082BB4(a);
    }
    func_08082DA4();
}
