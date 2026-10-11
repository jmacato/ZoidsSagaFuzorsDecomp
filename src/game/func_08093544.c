#include "types.h"

struct Obj
{
    u8 pad_0[8];
    s32 y;
};

extern u8 D_02031A0C;
extern const u8 D_080F38CC[];
extern const u8 D_080F4084[];
extern const u8 D_080F41C8[];
void func_080C8B84(const u8 *, void *);
struct Obj *func_080771BC(const u8 *, const u8 *, u16, s16, s16, u16, u16, u32, u32);
void func_080C8FCC(u32);
void func_080771F4(struct Obj *);

void func_08093544(void)
{
    struct Obj *obj;
    struct Obj *objs[2];
    u8 i;

    func_080C8B84(D_080F38CC, (void *)0x06016000);
    obj = func_080771BC(D_080F4084, D_080F41C8, 0x14, 0x78, 0x20, 0x300, 0xE, 0x150, 0);
    objs[0] = func_080771BC(D_080F4084, D_080F41C8, D_02031A0C % 10 + 10, 0x78, 0x70, 0x300, 0xE, 0x50, 0);
    objs[1] = func_080771BC(D_080F4084, D_080F41C8, D_02031A0C / 10, 0x78, -0x30, 0x300, 0xE, 0x50, 0);
    while (objs[0]->y >= 0x2000)
    {
        objs[0]->y -= 0x800;
        objs[1]->y += 0x800;
        func_080C8FCC(1);
    }
    while (objs[0]->y < 0x2000)
    {
        objs[0]->y += 0x200;
        objs[1]->y -= 0x200;
        func_080C8FCC(1);
    }
    for (i = 0; i < 30; i++)
        func_080C8FCC(1);
    func_080771F4(obj);
    func_080771F4(objs[0]);
    func_080771F4(objs[1]);
    func_080C8FCC(1);
}
