#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Mgr
{
    u8 pad_0[0xB];
    u8 cursor;
};

struct Cam
{
    u8 pad_0[0x10];
    s32 field_10;
};

extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];
extern const u8 *D_087353C4[];
extern const u8 D_087353E4[];
extern struct Mgr D_0201F5F8;
extern u16 D_030057EC;
extern u16 D_0300000E;
extern u8 D_0203124F;
extern struct Cam D_03000060;
struct Obj *func_080771BC(const u8 *, const u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_080C8FCC(s32);
void func_08075F20(s32);
void func_080771F4(struct Obj *);

s32 func_0808B9B4(void)
{
    struct Obj *obj = func_080771BC(D_080C9680, D_080C96B4, 0, 0x78, 0, 0x3EE, 15, 0x5020, 0);
    u32 k;
    u8 i;
    for (;;)
    {
        func_0807C290(D_087353C4[D_0201F5F8.cursor]);
        func_0807A1A4();
        obj->y = D_087353E4[D_0201F5F8.cursor] << 11;
        while (1)
        {
            func_080C8FCC(1);
            k = D_030057EC & 0x40;
            if (k)
            {
                func_08075F20(0xCC);
                if (D_0201F5F8.cursor != 0)
                    D_0201F5F8.cursor--;
                else
                    D_0201F5F8.cursor = 7;
                break;
            }
            if (D_030057EC & 0x80)
            {
                func_08075F20(0xCC);
                if (D_0201F5F8.cursor <= 6)
                    D_0201F5F8.cursor++;
                else
                    D_0201F5F8.cursor = k;
                break;
            }
            if ((D_0300000E & 0x200) && D_0203124F > 1)
            {
                func_08075F20(0xCC);
                func_080771F4(obj);
                for (i = 0; i < 8; i++)
                {
                    D_03000060.field_10 -= 0xF00;
                    func_080C8FCC(1);
                }
                return 0;
            }
            if (D_0300000E & 0x100)
            {
                func_08075F20(0xCC);
                func_080771F4(obj);
                for (i = 0; i < 8; i++)
                {
                    D_03000060.field_10 += 0xF00;
                    func_080C8FCC(1);
                }
                return 1;
            }
            if (D_0300000E & 2)
            {
                func_08075F20(0xCB);
                func_080771F4(obj);
                return -1;
            }
        }
    }
}
