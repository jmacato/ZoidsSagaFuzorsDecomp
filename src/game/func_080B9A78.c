#include "types.h"

struct AnimEntry
{
    const u8 *data;
    u8 pad_4[0xC];
};

struct Obj
{
    u32 flags;
    u8 pad_4[0x14];
    u16 frame;
};

struct Save
{
    u32 seen[5];
    u32 owned[5];
};

void func_08079EF4(u8, u8, u16, u16, u16, u8, u8, u8, u16, u8);
void func_08076FA0(void);
struct Obj *func_080771BC(const void *, const void *, s32, s32, s32, s32, s32, s32, s32);
struct Obj *func_08077180(const void *, u16, u16, s16, s16, u16, u16, u32, u32);
void func_080771F4(struct Obj *);
void func_08077204(struct Obj *, u16);
void func_0807C290(const void *);
void func_08079544(s32, s32);
void func_0807A1A4(void);
void func_0807970C(void);
void func_080C8B84(const void *, void *);
void func_080C8FCC(u32);
void func_08075F20(u16);
void func_0807FF2C(u8, u8, u16, u8, u8 *);

extern vu16 D_0300004C;
extern u16 D_0300000E;
extern struct Save D_02030504;
extern u8 D_02001480[];
extern struct AnimEntry D_087B1D90[];
extern const u8 *const D_087A8ADC[];
extern const u8 D_080F24FC[];
extern const u8 D_080F2508[];
extern const u8 D_080F21DC[];
extern const u8 D_080F21E8[];
extern const u8 D_0800764C[];
extern const u8 D_080076E3[];
extern const u8 D_085BF14C[];
extern const u8 D_085BF19C[];
extern const u8 D_085BF1A8[];
extern const u8 D_085ECCF0[];
extern const u8 D_085ECCFC[];
extern const u8 D_08502EAC[];
extern const u8 D_0850350C[];
extern const u8 D_0850332C[];

void func_080B9A78(u8 *list, u8 cur)
{
    u8 sel;
    u8 id;
    u8 i;
    u8 n;
    u8 redraw;
    struct Obj *obj;
    struct Obj *panel;

    D_0300004C = 0x1840;
    func_08079EF4(3, 1, 0, 0x3C0, 0x3C0, 0, 0xE, 0, 0x3E6, 0xF);
    func_08076FA0();
    func_080771BC(D_080F24FC, D_080F2508, 0, 0xA0, 0x98, 0x33F, 0xF, 8, 0);
    func_080771BC(D_080F21DC, D_080F21E8, 0, 0xD8, 0x98, 0x301, 0xF, 8, 0);
    func_0807C290(D_0800764C);
    func_08079544(0xF, 0);
    sel = cur;
    id = list[sel];
    func_0807C290(D_087A8ADC[id]);
    func_0807A1A4();
    obj = 0;
    func_080C8B84(D_085BF14C, (void *)0x06010200);
    panel = func_080771BC(D_085BF19C, D_085BF1A8, 0, 0x60, 0x30, 0x10, 0xF, 0x108, 0);
    func_080771BC(D_085ECCF0, D_085ECCFC, 0, 8, 8, 0x20, 2, 8, 0);
    redraw = 1;
    while (1)
    {
        if (D_0300000E & 0x20)
        {
            func_08075F20(0xCC);
            i = sel;
            do
            {
                i--;
                if (i == 0)
                    i = list[0];
                n = list[i];
            } while (!(D_02030504.owned[n >> 5] & (1 << (n & 31))));
            sel = i;
        }
        else if (D_0300000E & 0x10)
        {
            func_08075F20(0xCC);
            i = sel;
            do
            {
                i++;
                if (i > list[0])
                    i = 1;
                n = list[i];
            } while (!(D_02030504.owned[n >> 5] & (1 << (n & 31))));
            sel = i;
        }
        else if (D_0300000E & 2)
        {
            break;
        }
        else if (!redraw)
        {
            goto anim;
        }
        id = list[sel];
        func_0807C290(D_080076E3);
        func_0807C290(D_087A8ADC[id]);
        func_0807FF2C(id, 0, 0x20, 2, D_02001480);
        if (obj != 0)
            func_080771F4(obj);
        func_080C8FCC(1);
        if (D_087B1D90[id].data != 0)
        {
            obj = func_08077180(D_087B1D90, id, 0, 0x60, 0x20, 0, 0, 0x400020, 0);
            if (id != 0x69 && id != 0x67)
                panel->flags &= ~0x20000;
            else
                panel->flags |= 0x20000;
        }
        else
        {
            obj = 0;
            panel->flags |= 0x20000;
        }
        func_0807A1A4();
        redraw = 0;
    anim:
        if (obj->flags & 4)
        {
            if (D_087B1D90[id].data == D_08502EAC || D_087B1D90[id].data == D_0850350C)
                func_08077204(obj, (obj->frame + 1) % 16);
            else if (D_087B1D90[id].data == D_0850332C)
                func_08077204(obj, (obj->frame + 1) % 8);
        }
        func_080C8FCC(1);
    }
    func_08075F20(0xCB);
    func_08079544(0x10, 0);
    func_0807970C();
}
