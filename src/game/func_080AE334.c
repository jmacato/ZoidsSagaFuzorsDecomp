#include "types.h"

struct Matrix
{
    s16 m[3][3];
    s32 trans[3];
};

struct Rot
{
    s16 x, y, z, w;
};

struct Child
{
    u8 pad_0[0x1A];
    u16 field_1A;
    u16 field_1C;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *children[32];
    u32 state;
    s32 field_90;
    s32 field_94;
    u32 field_98;
};

struct Big
{
    u8 pad_0[0x8A8];
    s32 field_8A8;
};

struct Scroll
{
    s32 x;
    s32 y;
};

void func_080787A4(s16 *, u16, u16, u8);
s32 func_080A38B0(u8);
void func_080767AC(const struct Rot *, struct Matrix *);
void func_08076698(const struct Matrix *, const s16 *, s16 *);
u16 func_080C8B74(s16, s16);
u16 func_08075AAC(u8);
u16 func_08075AF8(u8);
void func_080784F8(void);
struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
void func_08077E6C(void *);

extern s16 D_02037B2C[];
extern u16 D_03000056;
extern u16 D_03000058;
extern u8 D_03000081;
extern u8 D_030057F5;
extern const s16 D_08735954[];
extern struct Big D_02036E7C;
extern struct Scroll D_03000060;
extern u32 (*D_03000010)(void);

void func_080AE334(struct Obj *obj)
{
    struct Matrix mat;
    struct Rot rot;
    struct Rot v;
    s16 ang;
    s16 s;
    s16 c;
    u8 i;
    s32 y;
    s32 n;

    switch (obj->state)
    {
    case 0:
        func_080787A4(D_02037B2C, 0x3F3F, 0x1F1F, 8);
        D_03000056 = 0x3555;
        *(u16 *)0x05000000 = 0x7FFF;
        D_03000081 = D_030057F5 = 2;
        func_080A38B0(0);
        obj->state++;
    case 1:
        rot.x = obj->field_90 + 4;
        y = obj->field_94;
        if (obj->flags & 2)
            y += 0x80;
        rot.y = y;
        rot.z = obj->field_98;
        for (i = 0; i < 3; i++)
        {
            func_080767AC(&rot, &mat);
            func_08076698(&mat, D_08735954, &v.x);
            v.z = 0x80 - v.z;
            ang = func_080C8B74(v.x, v.y) >> 8;
            s = func_08075AAC(ang);
            c = func_08075AF8(ang);
            D_02037B2C[i * 7] = 3;
            D_02037B2C[i * 7 + 1] = (obj->flags & 2) == 0 ? obj->x : 0xF0 - obj->x;
            D_02037B2C[i * 7 + 2] = obj->y;
            D_02037B2C[i * 7 + 3] = ((v.x + s * (0x40 - (u16)obj->field_98) / 512) << 7) / v.z + D_02037B2C[i * 7 + 1];
            D_02037B2C[i * 7 + 4] = ((v.y - c * (0x40 - (u16)obj->field_98) / 512) << 7) / v.z + D_02037B2C[i * 7 + 2];
            D_02037B2C[i * 7 + 5] = ((v.x - s * (0x40 - (u16)obj->field_98) / 512) << 7) / v.z + D_02037B2C[i * 7 + 1];
            D_02037B2C[i * 7 + 6] = ((v.y + c * (0x40 - (u16)obj->field_98) / 512) << 7) / v.z + D_02037B2C[i * 7 + 2];
            rot.x += 0x55;
        }
        D_02037B2C[i * 7] = 0;
        D_03000058 = ((obj->field_98 >> 2) << 8) | 0x10;
        if (obj->field_98 == 0x40)
        {
            obj->state++;
            break;
        }
        if (!(obj->flags & 2))
            obj->field_90 += 8;
        else
            obj->field_90 -= 8;
        obj->field_98++;
        break;
    case 2:
        obj->field_90 = 0x80;
        D_03000081 = D_030057F5 = 1;
        obj->state++;
    case 3:
        if (obj->field_90 == 0)
        {
            func_080784F8();
            D_03000056 = 0;
            obj->state++;
            break;
        }
        D_02037B2C[0] = 4;
        D_02037B2C[1] = D_02037B2C[7] = (obj->flags & 2) == 0 ? obj->x : 0xF0 - obj->x;
        D_02037B2C[3] = D_02037B2C[5] = D_02037B2C[1] + ((obj->flags & 2) == 0 ? -obj->field_90 : obj->field_90);
        D_02037B2C[2] = D_02037B2C[4] = obj->y - 1;
        D_02037B2C[6] = D_02037B2C[8] = obj->y + 1;
        D_02037B2C[9] = 0;
        obj->field_90 -= 0x10;
        break;
    case 4:
        if (++obj->field_90 == 30)
        {
            D_03000056 = 0x740;
            D_03000058 = 0x810;
            obj->field_90 = 0;
            obj->state++;
        }
        break;
    case 5:
        obj->children[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x600, 0, 0);
        obj->children[1] = func_080A34A8(obj, 1, 0, obj->x - 0x80 + D_02036E7C.field_8A8 / 256,
                                         obj->y + D_03000060.y / 256, 0x1500, 0, 0);
        obj->field_94 = D_02036E7C.field_8A8;
        obj->field_98 = D_03000060.y;
        func_080A12B0(0xC, 0);
        func_080A38B0(1);
        obj->state++;
        break;
    case 6:
        if (obj->children[1]->field_1A <= 0x17)
        {
            n = obj->field_90 & 3;
            if (n == 0)
            {
                func_080A3770(obj, 2, 0, obj->x + (obj->field_94 - D_02036E7C.field_8A8) / 256,
                              obj->y + ((s32)obj->field_98 - D_03000060.y) / 256 + ((u32)obj->field_90 % 6 + (D_03000010() >> 14) - 2),
                              0x400, 0x80, 0x180, n);
            }
            obj->field_90++;
            break;
        }
        obj->state++;
        break;
    case 7:
        if (obj->children[0] == 0 && obj->children[1] == 0)
            func_08077E6C(obj);
        break;
    }
}
