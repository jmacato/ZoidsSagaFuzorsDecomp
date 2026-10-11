#include "types.h"

struct Child
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 state;
    u8 pad_90[0x18];
    s32 field_A8;
};

extern u16 D_0203796C[2][64];
extern u16 D_02037A6C[2][48];
extern u16 D_03000058;

void func_080C8B78(const void *, void *, u32);
void func_0807806C(const void *, void *, s32);
void func_080771F4(struct Child *);
void func_080A2438(void);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
void func_08077E6C(struct Obj *);

void func_080AD5FC(struct Obj *obj)
{
    u16 dy;
    u32 dx;
    u8 i;
    u8 r;
    u8 g;
    u8 b;

    if (obj->state < 20)
    {
        if (obj->state == 0)
        {
            obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y + 0x80, 0x420, 0, 0);
            obj->field_A8 = 0xC0;
            obj->child[1] = func_080A34A8(obj, 0, 0, obj->x - 32, obj->y + 0x80, 0x420, 0, 0);
            func_080C8B78((void *)0x05000000, D_0203796C[0], 0x20);
            func_080C8B78((void *)0x05000200, D_02037A6C[0], 0x18);
            func_080A12B0(11, 0);
        }
        if (obj->state <= 3)
        {
            dx = (obj->flags & 2) == 0 ? 0x1000 : 0xF000;
            dy = 0xE000;
        }
        else
        {
            dx = (u16)((obj->flags & 2) == 0 ? 0x1000 / (s8)(obj->state >> 1) : -0x1000 / (s8)(obj->state >> 1));
            dy = -0x2000 / (s8)(obj->state >> 1);
            D_03000058 = (20 - obj->state) | 0x1000;
            for (i = 0; i < 64; i++)
            {
                r = D_0203796C[0][i] & 0x1F;
                g = (D_0203796C[0][i] >> 5) & 0x1F;
                b = (D_0203796C[0][i] >> 10) & 0x1F;
                r += (0x1F - r) * (obj->state - 3) / 16;
                g += (0x1F - g) * (obj->state - 3) / 16;
                b += (0x1F - b) * (obj->state - 3) / 16;
                D_0203796C[1][i] = r | (g << 5) | (b << 10);
            }
            for (i = 0; i < 48; i++)
            {
                r = D_02037A6C[0][i] & 0x1F;
                g = (D_02037A6C[0][i] >> 5) & 0x1F;
                b = (D_02037A6C[0][i] >> 10) & 0x1F;
                r += (0x1F - r) * (obj->state - 3) / 16;
                g += (0x1F - g) * (obj->state - 3) / 16;
                b += (0x1F - b) * (obj->state - 3) / 16;
                D_02037A6C[1][i] = r | (g << 5) | (b << 10);
            }
            func_0807806C(D_0203796C[1], (void *)0x05000000, 0x80);
            func_0807806C(D_02037A6C[1], (void *)0x05000200, 0x60);
        }
        obj->child[0]->x += (s16)dx;
        obj->child[0]->y += (s16)dy;
        obj->child[1]->x += (s16)dx;
        obj->child[1]->y += (s16)dy;
        obj->state++;
    }
    else if (obj->state <= 0x33)
    {
        if (obj->state == 20)
        {
            func_080771F4(obj->child[0]);
            func_080771F4(obj->child[1]);
            func_080A2438();
        }
        for (i = 0; i < 64; i++)
        {
            r = D_0203796C[0][i] & 0x1F;
            g = (D_0203796C[0][i] >> 5) & 0x1F;
            b = (D_0203796C[0][i] >> 10) & 0x1F;
            r += (0x1F - r) * (0x33 - obj->state) / 32;
            g += (0x1F - g) * (0x33 - obj->state) / 32;
            b += (0x1F - b) * (0x33 - obj->state) / 32;
            D_0203796C[1][i] = r | (g << 5) | (b << 10);
        }
        for (i = 0; i < 48; i++)
        {
            r = D_02037A6C[0][i] & 0x1F;
            g = (D_02037A6C[0][i] >> 5) & 0x1F;
            b = (D_02037A6C[0][i] >> 10) & 0x1F;
            r += (0x1F - r) * (0x33 - obj->state) / 32;
            g += (0x1F - g) * (0x33 - obj->state) / 32;
            b += (0x1F - b) * (0x33 - obj->state) / 32;
            D_02037A6C[1][i] = r | (g << 5) | (b << 10);
        }
        func_0807806C(D_0203796C[1], (void *)0x05000000, 0x80);
        func_0807806C(D_02037A6C[1], (void *)0x05000200, 0x60);
        obj->state++;
    }
    else
        func_08077E6C(obj);
}
