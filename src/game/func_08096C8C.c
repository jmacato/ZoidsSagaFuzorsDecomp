#include "types.h"

struct Obj
{
    u32 flags;
};

struct Zoid
{
    u8 pad_0[6];
    s16 hp;
};

struct Entry
{
    u16 flags;
    u16 id;
};

struct Unit
{
    u8 pad_0[0x74];
    struct Entry entries[8];
};

struct Member
{
    u8 flags;
    u8 field_1;
    u16 type;
    u8 pad_4[0x26C];
};

struct Team
{
    u8 field_0;
    u8 slots[3];
};

struct Big
{
    u8 pad_0[0x244];
    u8 cur;
    u8 pad_245[7];
    struct Unit *unit;
    u8 pad_250[0x222C - 0x250];
    struct Member members[8];
    u8 pad_35AC[0x4F6C - 0x35AC];
    struct Obj *obj_4F6C;
    u8 pad_4F70[7];
    u8 done;
    u8 index;
    u8 side;
    u8 slot;
    u8 pad_4F7B[9];
    struct Team teams[2];
    u8 pad_4F8C[0x4FD4 - 0x4F8C];
    u8 results[3][2][6];
};

struct Fx
{
    u8 pad_0[0x94];
    struct Obj *obj;
};

extern struct Big D_02031A0C;
extern struct Fx D_02036E7C;
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;
void func_080C8FCC(u32);
void func_080A12B0(u32, u32);
u32 func_080A1B9C(void);
void func_080A2AE8(void);
u8 func_0809B834(u8, u8, u32, u32);
void func_080A0E18(u16, u32);
void func_080A0E8C(u16, u32);
u8 func_080A3338(void);
u8 *func_0809A954(u8, u8, u32);
void func_080A2D70(u8, u32, u32, u16, u8);
void func_080A1D48(void);
void func_080A0D0C(u16, u32, u32);
void func_080A0F48(u32);
void func_080A0DA4(u16, u32);
void func_08075F20(u32);
void func_080771F4(struct Obj *);
struct Zoid *func_0809A908(u8, u8);

void func_08096C8C(s32 mode)
{
    u8 k;
    u8 r;
    u32 kind;

    k = D_02031A0C.teams[D_02031A0C.cur].slots[D_02031A0C.index] & 7;
    if (D_03000056 == 0xD95 && D_03000058 == 0x10 && D_0300005A == 0x10)
    {
        do
        {
            D_0300005A--;
            func_080C8FCC(1);
        } while (D_0300005A != 0);
        D_03000056 = 0;
        if (D_02031A0C.obj_4F6C != 0)
            D_02031A0C.obj_4F6C->flags &= ~0x400;
    }
    func_080A12B0(4, 0x9000);
    while (!func_080A1B9C())
        func_080C8FCC(1);
    func_080A2AE8();
    r = D_02031A0C.results[D_02031A0C.index][D_02031A0C.side][D_02031A0C.slot];
    kind = r & 3;
    if (r & 0x10)
    {
        if (mode != 2)
        {
            if (D_02036E7C.obj == 0 || (D_02031A0C.members[k].type & 2))
            {
                func_080A0D0C(D_02031A0C.unit->entries[k].id, 0, (r >> 5) & 1);
                while (!func_080A3338())
                    func_080C8FCC(1);
                if (r & 0x40)
                {
                    func_080A0F48((r & 0xC) >> 2);
                    while (!func_080A3338())
                        func_080C8FCC(1);
                }
            }
            else
            {
                func_080A0DA4(D_02031A0C.unit->entries[k].id, 0);
                while (!func_080A3338())
                    func_080C8FCC(1);
                if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x23, 0) == 0xFF)
                {
                    func_08075F20(0x116);
                    func_080771F4(D_02036E7C.obj);
                    D_02036E7C.obj = 0;
                }
            }
            if (func_0809A908(D_02031A0C.side, D_02031A0C.slot)->hp > 0)
                func_080A2D70(*func_0809A954(D_02031A0C.side, D_02031A0C.slot, 0), 1, kind, D_02031A0C.unit->entries[k].id, D_02031A0C.side);
            else
                func_080A2D70(*func_0809A954(D_02031A0C.side, D_02031A0C.slot, 0), 4, kind, D_02031A0C.unit->entries[k].id, D_02031A0C.side);
        }
        else
        {
            func_080A1D48();
            func_080A0D0C(D_02031A0C.unit->entries[k].id, 0, 0);
            while (!func_080A3338())
                func_080C8FCC(1);
            func_080A2D70(*func_0809A954(D_02031A0C.side, D_02031A0C.slot, 0), 3, kind, D_02031A0C.unit->entries[k].id, D_02031A0C.side);
        }
    }
    else
    {
        if (func_0809B834(D_02031A0C.side, D_02031A0C.slot, 0x26, 0) == 0xFF)
            func_080A0E18(D_02031A0C.unit->entries[k].id, 0);
        else
            func_080A0E8C(D_02031A0C.unit->entries[k].id, 0);
        while (!func_080A3338())
            func_080C8FCC(1);
        func_080A2D70(*func_0809A954(D_02031A0C.side, D_02031A0C.slot, 0), 3, kind, D_02031A0C.unit->entries[k].id, D_02031A0C.side);
    }
    D_02031A0C.done = 1;
}
