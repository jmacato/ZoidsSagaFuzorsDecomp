#include "types.h"

struct Win
{
    u32 flags;
};

struct Scroll
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
};

void func_08079EF4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_08076FA0(void);
void func_0807C290(const void *);
void func_080B969C(u8);
struct Win *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_08075DA8(s32, void (*)(void));
void func_08079544(s32, s32);
void func_0807970C(void);
void func_08077204(void *, u16);
void func_08075F20(u16);
void func_08077E6C(void *);
void func_080771F4(void *);
void func_080C8FCC(s32);
void func_08075E28(u8);
void func_080B968C(void);

extern u16 D_0300004C;
extern u16 D_0300004E;
extern u16 D_03000050;
extern u16 D_03000054;
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;
extern u16 D_0300000E;
extern struct Scroll D_03000060;
extern u32 D_02030504[];
extern void *D_02030B48;
extern void *D_02030B4C[];
extern const u8 D_08007548[];
extern const u8 D_080F25B4[];
extern const u8 D_080F25CC[];
extern const u8 D_080F24FC[];
extern const u8 D_080F2508[];
extern const u8 D_080F21DC[];
extern const u8 D_080F21E8[];

void func_080B975C(u8 *list, u8 sel)
{
    u8 anim;
    s32 show;
    struct Win *w;
    u8 i;
    u8 id;
    u8 cur;

    D_0300004C = 0x1F40;
    D_0300004E = 0x4086;
    D_03000050 = 0x40C;
    D_03000060.field_4 = D_03000060.field_8 = D_03000060.field_C = D_03000060.field_14 = 0;
    func_08079EF4(3, 3, 0, 0x1C0, 0x1C0, 3, 0xE, 0, 0x3E6, 0xF);
    D_03000054 = (D_03000054 & 0x3FFF) | 0x4000;
    func_08076FA0();
    func_0807C290(D_08007548);
    cur = sel;
    func_080B969C(list[cur]);
    w = func_080771BC(D_080F25B4, D_080F25CC, 0, 0, 0x78, 0x346, 0xF, 0x408, 0);
    func_080771BC(D_080F24FC, D_080F2508, 0, 0xA0, 0x98, 0x33F, 0xF, 0x408, 0);
    func_080771BC(D_080F21DC, D_080F21E8, 0, 0xD8, 0x98, 0x301, 0xF, 0x408, 0);
    func_08075DA8(3, func_080B968C);
    func_08079544(0xF, 0);
    func_0807970C();
    anim = 0;
    show = 1;
    while (1)
    {
        if (anim == 0)
        {
            if (D_0300000E & 0x100)
            {
                if (show == 0)
                {
                    D_0300004C |= 0x200;
                    show = 1;
                    func_08077204(w, 0);
                    w->flags |= 8;
                }
                else
                {
                    D_0300004C &= 0xFDFF;
                    show = 0;
                    func_08077204(w, 1);
                    w->flags |= 8;
                }
            }
            else if (D_0300000E & 0x20)
            {
                func_08075F20(0xCC);
                i = cur;
                do
                {
                    if (--i == 0)
                        i = list[0];
                    id = list[i];
                } while (!(D_02030504[id >> 5] & (1 << (id & 31))));
                cur = i;
                anim = 1;
            }
            else if (D_0300000E & 0x10)
            {
                func_08075F20(0xCC);
                i = cur;
                do
                {
                    if (++i > list[0])
                        i = 1;
                    id = list[i];
                } while (!(D_02030504[id >> 5] & (1 << (id & 31))));
                cur = i;
                anim = 1;
            }
            else if (D_0300000E & 2)
            {
                func_08075F20(0xCB);
                func_08079544(0x10, 0);
                func_0807970C();
                func_08075E28(3);
                return;
            }
        }
        else if (anim <= 8)
        {
            D_03000056 = 0xFD5;
            D_03000058 = 0x10;
            D_0300005A = anim * 2;
            anim++;
        }
        else if (anim == 9)
        {
            func_08077E6C(D_02030B48);
            for (i = 0; i < 3; i++)
            {
                if (D_02030B4C[i] != 0)
                {
                    func_080771F4(D_02030B4C[i]);
                    D_02030B4C[i] = 0;
                }
            }
            func_080B969C(list[cur]);
            anim++;
        }
        else if (anim <= 0x11)
        {
            D_03000056 = 0xFD5;
            D_0300005A = (0x11 - anim) * 2;
            anim++;
        }
        else
        {
            anim = 0;
        }
        func_080C8FCC(1);
    }
}
