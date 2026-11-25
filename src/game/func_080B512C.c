#include "types.h"

struct Slot
{
    u16 field_0;
    u16 id;
};

struct Unit
{
    u8 kind;
    u8 field_1;
    u8 pad_2[0x72];
    struct Slot slots[4];
};

struct Obj
{
    u32 flags;
};

struct GfxEntry
{
    const u8 *data;
    u8 pad_4[0xC];
};

struct Background
{
    const void *gfx;
    const void *map;
    const void *objGfx;
};

struct Scroll
{
    s32 x;
    s32 y;
};

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);
struct Obj *func_080771BC(const void *, const void *, s32, s32, s32, s32, s32, s32, s32);
void *func_0807FA0C(u8, u8, s32, s32, s32, void *);
void func_0807FF9C(const struct GfxEntry *, u8, u16, u8);
void *func_080A0388(const void *, u16, u16, s16, s16, u16, u16, u32, s32, u8);
void func_080785C0(u8, u8, u8, u8, u8);
void func_08078688(u8);
void func_0807C290(const void *);
void func_0807A1A4(void);
void func_0808A7F8(u8, u8, u16, u16);
void func_080C8B88(const void *, void *);
void func_0807806C(const void *, void *, s32);
void func_08077204(struct Obj *, u16);
void func_080C8FCC(u32);
void func_08075F20(u16);
void func_080771F4(void *);
void func_08077E6C(void *);
void func_080784F8(void);

extern u16 D_0300004C;
extern u16 D_0300004E;
extern u16 D_0300000E;
extern u16 D_030057EC;
extern void *D_02030B48;
extern void *D_02030B4C[3];
extern struct Scroll D_03000060;
extern u16 D_02001480[];
extern const u8 D_080F5254[];
extern const u8 D_080F5478[];
extern const u8 D_080F5A60[];
extern const u8 D_080F5AC0[];
extern const u8 D_0800681E[];
extern const struct GfxEntry D_087B0324[];
extern const u8 D_087B0974[];
extern const s16 D_087AD848[][8][2];
extern const s16 D_087B0FC4[];
extern const u8 D_087AEBA8[][3];
extern const struct Background D_087A8D34[];
extern const u8 *const D_087A9478[][8];
extern const u8 *const D_087AC010[][8];

u8 func_080B512C(struct Unit *unit)
{
    struct Obj *obj;
    u8 i;
    u8 sel;
    u8 done;

    func_080C8B84(D_080F5254, (void *)0x06015020);
    func_0807F860(D_080F5478, (void *)0x050003A0, D_02001480);
    obj = func_080771BC(D_080F5A60, D_080F5AC0, unit->field_1, 4, 4, 0x281, 0xD, 8, 0);
    D_0300004C |= 0x100;
    D_0300004E = 0x186;
    D_02030B48 = func_0807FA0C(unit->kind, unit->field_1, 1, 1, 0, D_02001480);
    D_03000060.x = 0x1000;
    D_03000060.y = 0;
    for (i = 0; i < 3; i++)
    {
        if (unit->slots[i].id != 0 && unit->slots[i].id <= 100 && D_087B0324[unit->slots[i].id].data != 0)
        {
            func_0807FF9C(D_087B0324, unit->slots[i].id * 2 + (i ? 1 : 0), i << 7, i);
            D_02030B4C[i] = func_080A0388(D_087B0974, unit->slots[i].id * 2 + (i ? 1 : 0), 0,
                                          D_087AD848[unit->kind][i][0] - (i == 2 ? D_087B0FC4[unit->slots[2].id] : 0),
                                          D_087AD848[unit->kind][i][1], i << 7, i,
                                          (D_087AEBA8[unit->kind][i] << 6) | 0x1128, 0, 0);
        }
        else
        {
            D_02030B4C[i] = 0;
        }
    }
    func_080785C0(0, 0, 0xF0, 0x80, 0x3B);
    func_08078688(0x3F);
    func_0807C290(D_0800681E);
    func_0807A1A4();
    func_0808A7F8(0, 3, 0xC8, 0x98);
    done = 0;
    sel = unit->field_1;
    do
    {
        func_080C8B88(D_087A9478[unit->kind][sel], D_02001480);
        D_02001480[0] = *(u16 *)0x05000000;
        func_0807806C(D_02001480, (void *)0x05000000, 0x80);
        if (D_087A8D34[unit->kind].objGfx != 0)
        {
            func_080C8B88(D_087AC010[unit->kind][sel], D_02001480 + 0x40);
            func_0807806C(D_02001480 + 0x40, (void *)0x05000200, 0x20);
        }
        func_08077204(obj, sel);
        obj->flags |= 8;
        while (1)
        {
            func_080C8FCC(1);
            if (D_030057EC & 0x40)
            {
                func_08075F20(0xCC);
                if (sel != 0)
                    sel--;
                else
                    sel = 7;
                break;
            }
            if (D_030057EC & 0x80)
            {
                func_08075F20(0xCC);
                if (sel < 7)
                    sel++;
                else
                    sel = 0;
                break;
            }
            if (D_0300000E & 1)
            {
                func_08075F20(0xCA);
                done = 1;
                break;
            }
            if (D_0300000E & 2)
            {
                func_08075F20(0xCB);
                sel = 0xFF;
                done = 1;
                break;
            }
        }
    } while (!done);
    D_0300004C &= 0xFEFF;
    func_080771F4(obj);
    func_08077E6C(D_02030B48);
    for (i = 0; i < 3; i++)
    {
        if (D_02030B4C[i] != 0)
            func_080771F4(D_02030B4C[i]);
    }
    func_080784F8();
    return sel;
}
