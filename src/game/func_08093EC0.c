#include "types.h"

struct Obj
{
    u32 flags;
};

struct Big
{
    u8 pad_0[0x4E5B];
    u8 list[10];
    u8 pad_4E65[0x4F84 - 0x4E65];
    u8 field_4F84;
    u8 field_4F85;
};

extern struct Big D_02031A0C;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u8 D_0200C4D8;
extern const u8 *D_087A58C4[];
extern const u8 D_08004249[];
extern const u8 D_0800426C[];
extern const u8 D_08004265[];
extern const u8 D_08004269[];
extern const u8 D_08004D59[];
extern const u8 D_080F24AC[];
extern const u8 D_080F24B8[];
void func_0807C290(const u8 *);
void func_0807BEF4(u32, const u8 *, u32);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(struct Obj *);
void func_08075F20(u32);
void func_080C1B4C(u32, u8);
u32 func_080C3290(u8);

s32 func_08093EC0(void)
{
    s32 state;
    struct Obj *obj;
    u8 sel;
    u8 i;

    state = 0;
    for (;;)
    {
        switch (state)
        {
        case 0:
            func_0807C290(D_08004249);
            for (i = 0; i < 10; i++)
                func_0807BEF4(2, D_087A58C4[D_02031A0C.list[i]], 0);
            func_0807C290(D_0800426C);
            obj = func_080771BC(D_080F24AC, D_080F24B8, 0, 0xA0, 0x98, 0x3DC, 0xF, 8, 0);
            state = 0x10;
            break;
        case 0x10:
            for (;;)
            {
                func_0807C290(D_08004265);
                sel = D_02031A0C.list[D_0200C4A0];
                if (D_0200C4A2 == 1)
                {
                    if (sel != 0)
                        break;
                    func_08075F20(0x114);
                }
                else if (D_0200C4A2 == 2)
                {
                    func_0807C290(D_08004269);
                    func_080771F4(obj);
                    return -1;
                }
                else
                {
                    obj->flags |= 0x20000;
                    func_080C1B4C(4, sel);
                    obj->flags &= ~0x20000;
                }
            }
            func_0807C290(D_08004269);
            func_080771F4(obj);
            state = 0x1000;
            break;
        case 0x1000:
            state = func_080C3290(sel) ? 0x2000 : 0;
            break;
        case 0x2000:
            D_0200C4D8 = sel;
            func_0807C290(D_08004D59);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                D_02031A0C.field_4F84 = 1;
                D_02031A0C.field_4F85 = sel;
                return 0;
            }
            state = 0;
            break;
        }
    }
}
