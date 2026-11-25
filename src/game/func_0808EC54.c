#include "types.h"

struct Obj
{
    u8 pad_0[8];
    s32 y;
};

struct Info
{
    u8 id;
    u8 pad_1[0x2D];
    u8 zoid;
    u8 pad_2F[0xF];
    u8 field_3E;
};

struct State
{
    u8 pad_0[0xC];
    u8 field_C;
    u8 pad_D[7];
    struct Info *info;
};

struct Camera
{
    u8 pad_0[0x10];
    s32 y;
};

struct Zoid
{
    u8 pad_0[0x3C];
    u8 kind;
    u8 pad_3D[0x57];
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern struct Zoid D_02020E4C[];
extern u16 D_030057EC;
extern u16 D_0300000E;
extern u8 D_02001480[];
extern const u16 D_087B4AD0[];
extern const u8 *D_087354AC[];
extern const u8 D_087354C0[];
extern const u8 *D_087A43E0[];
extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];
void func_0807BD4C(u32);
const u8 *func_08082E70(u8);
void func_0807B77C(const u8 *, u32, u32);
void func_0807FF2C(u16, u32, u32, u32, u8 *);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u32);
void func_080771F4(struct Obj *);
void func_0807B748(const u8 *, u32, u32, u32, u32);

s32 func_0808EC54(void)
{
    struct Obj *cursor;
    u8 i;

    func_0807BD4C(4);
    func_0807B77C(func_08082E70(D_087B4AD0[D_0201F5F8.info->field_3E]), 0, 4);
    func_0807FF2C(D_087B4AD0[D_0201F5F8.info->field_3E], 0, 0, 0, D_02001480);
    cursor = func_080771BC(D_080C9680, D_080C96B4, 0, 0, 0, 0x3EE, 0xF, 0x5060, 0);
    while (1)
    {
        func_0807C290(D_087354AC[D_0201F5F8.field_C]);
        func_0807A1A4();
        cursor->y = D_087354C0[D_0201F5F8.field_C] << 11;
        while (1)
        {
            func_080C8FCC(1);
            if (D_030057EC & 0x40)
            {
                func_08075F20(0xCC);
                if (D_0201F5F8.field_C != 0)
                    D_0201F5F8.field_C--;
                else
                    D_0201F5F8.field_C = 4;
                break;
            }
            if (D_030057EC & 0x80)
            {
                func_08075F20(0xCC);
                if (D_0201F5F8.field_C < 4)
                    D_0201F5F8.field_C++;
                else
                    D_0201F5F8.field_C = 0;
                break;
            }
            if (D_0300000E & 0x100)
            {
                func_08075F20(0xCC);
                func_080771F4(cursor);
                for (i = 0; i < 8; i++)
                {
                    D_03000060.y += 0xF00;
                    func_080C8FCC(1);
                }
                func_0807BD4C(4);
                func_0807B77C(func_08082E70(D_0201F5F8.info->id), 0, 4);
                func_0807B748(D_087A43E0[D_02020E4C[D_0201F5F8.info->zoid].kind], 0, 4, 0, 2);
                func_0807FF2C(D_0201F5F8.info->id, 0, 0, 0, D_02001480);
                return 0;
            }
            if (D_0300000E & 2)
            {
                func_08075F20(0xCB);
                func_080771F4(cursor);
                return -1;
            }
        }
    }
}
