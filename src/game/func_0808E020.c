#include "types.h"

struct Obj
{
    u8 pad_0[8];
    s32 y;
};

struct Info
{
    u8 pad_0[0x3E];
    u8 field_3E;
};

struct State
{
    u8 pad_0[0xB];
    u8 field_B;
    u8 pad_C[8];
    struct Info *info;
};

struct Camera
{
    u8 pad_0[0x10];
    s32 y;
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern u16 D_030057EC;
extern u16 D_0300000E;
extern const u8 *D_08735460[];
extern const u8 D_08735484[];
extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u32);
void func_080771F4(struct Obj *);

s32 func_0808E020(void)
{
    struct Obj *cursor;
    u8 i;

    cursor = func_080771BC(D_080C9680, D_080C96B4, 0, 0x78, 0, 0x3EE, 0xF, 0x5060, 0);
    while (1)
    {
        func_0807C290(D_08735460[D_0201F5F8.field_B]);
        func_0807A1A4();
        if (D_0201F5F8.field_B < 8)
            cursor->y = D_08735484[D_0201F5F8.field_B] << 11;
        else
            cursor->y = (D_08735484[D_0201F5F8.field_B] << 11) + 0x400;
        while (1)
        {
            func_080C8FCC(1);
            if (D_030057EC & 0x40)
            {
                func_08075F20(0xCC);
                if (D_0201F5F8.field_B != 0)
                    D_0201F5F8.field_B--;
                else
                    D_0201F5F8.field_B = 8;
                break;
            }
            if (D_030057EC & 0x80)
            {
                func_08075F20(0xCC);
                if (D_0201F5F8.field_B < 8)
                    D_0201F5F8.field_B++;
                else
                    D_0201F5F8.field_B = 0;
                break;
            }
            if ((D_0300000E & 0x200) && D_0201F5F8.info->field_3E != 0)
            {
                func_08075F20(0xCC);
                func_080771F4(cursor);
                for (i = 0; i < 8; i++)
                {
                    D_03000060.y -= 0xF00;
                    func_080C8FCC(1);
                }
                return 0;
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
                return 1;
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
