#include "types.h"

struct Entry
{
    u16 flags;
    u16 id;
};

struct Info
{
    u8 kind;
    u8 pad_1;
    u8 pilot;
    u8 pad_3[0x71];
    struct Entry entries[3];
};

struct State
{
    u8 pad_0[8];
    u8 field_8;
    u8 pad_9[7];
    struct Info *info;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Pilot
{
    u8 data[0x40];
};

struct Camera
{
    u8 pad_0[0x10];
    s32 y;
};

struct Save
{
    u8 pad_0[0x14];
    u8 field_14;
};

extern struct State D_0201F5F8;
extern struct Save D_02009480;
extern struct Pilot D_02027A10[];
extern u8 D_02031410[];
extern struct Camera D_03000060;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const s16 D_087AD848[][8][2];
extern const u8 D_087B4CAC[];
extern const u8 D_080010FB[];
extern const u8 D_080010FF[];
extern const u8 D_08001103[];
struct Obj *func_08077180(const u8 *, u32, u32, u32, u32, u32, u32, u32, u32);
void func_080C0178(struct Info *, struct Pilot *, u8, u32, u8 *);
void func_0808BCA8(u32, u8 *, u32, u32);
void func_0808CA38(u8, u8, u8, u8);
void func_0807C290(const u8 *);
void func_08075F20(u32);
s32 func_0808CDA8(void);
void func_080C8FCC(u32);
void func_080771F4(struct Obj *);
void func_0808BB48(void);

s32 func_0808CBB0(u8 mode)
{
    struct Obj *cursor;
    s32 result;
    u8 i;

    cursor = func_08077180(D_087B4CAC, 0, 0, 0, 0, 0x1C0, 4, 0x1060, 0);
    while (1)
    {
        if (D_0201F5F8.info->entries[D_0201F5F8.field_8].id != 0)
        {
            if (D_0201F5F8.info->pilot != 0 && D_0201F5F8.info->pilot != 0xFF)
                func_080C0178(D_0201F5F8.info, &D_02027A10[D_0201F5F8.info->pilot], D_0201F5F8.field_8, 0, D_02031410);
            else
                func_080C0178(D_0201F5F8.info, 0, D_0201F5F8.field_8, 0, D_02031410);
            func_0808BCA8(2, D_02031410, 0, 0);
        }
        else
        {
            func_0808BCA8(2, 0, 0, 0);
        }
        if (D_0201F5F8.info->entries[D_0201F5F8.field_8].flags != 0 || D_0201F5F8.info->entries[D_0201F5F8.field_8].id != 0)
        {
            cursor->x = D_087AD848[D_0201F5F8.info->kind][D_0201F5F8.field_8][0] << 8;
            cursor->y = D_087AD848[D_0201F5F8.info->kind][D_0201F5F8.field_8][1] << 8;
            if (D_0201F5F8.field_8 == 0 && D_0201F5F8.info->entries[D_0201F5F8.field_8].id != 0 && D_0201F5F8.info->entries[D_0201F5F8.field_8].id < 0x52)
                cursor->y -= 0x1000;
            cursor->flags &= ~0x20000;
        }
        else
        {
            cursor->flags |= 0x20000;
        }
        func_0808CA38(D_02009480.field_14, 0x1F, 2, 1);
        if (mode == 0)
            func_0807C290(D_080010FB);
        else
            func_0807C290(D_080010FF);
        D_0201F5F8.field_8 = D_0200C4A0;
        if (D_0200C4A2 == 1)
        {
            if (D_0201F5F8.field_8 < 4)
            {
                result = 1;
                break;
            }
            func_08075F20(0x114);
            func_0807C290(D_08001103);
        }
        else if (D_0200C4A2 == 2)
        {
            result = -1;
            break;
        }
        else if (D_0200C4A4 & 0x200)
        {
            func_0808CDA8();
            for (i = 0; i < 8; i++)
            {
                D_03000060.y -= 0xF00;
                func_080C8FCC(1);
            }
            result = 0;
            break;
        }
    }
    func_080771F4(cursor);
    func_0808BB48();
    return result;
}
