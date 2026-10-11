#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 state;
    u32 size;
    u32 phase;
};

extern s16 D_02037B2C[];
extern u16 D_03000056;

s16 func_08075AAC(s16);
s16 func_08075AF8(s16);
void func_080784F8(void);
void func_08077E6C(struct Obj *);
s32 func_080A38B0(u8);

void func_080ACB58(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        if (obj->size < 0x80)
        {
            D_02037B2C[0] = 2;
            D_02037B2C[1] = obj->x;
            D_02037B2C[2] = obj->y;
            D_02037B2C[3] = obj->x - obj->size;
            D_02037B2C[4] = obj->y;
            D_02037B2C[5] = 0;
            obj->size += 8;
            break;
        }
        obj->size = 0;
        obj->state++;
    case 1:
        if (obj->size < 32)
        {
            D_02037B2C[0] = 8;
            D_02037B2C[1] = obj->x;
            D_02037B2C[2] = obj->y;
            for (i = 0; i < 7; i++)
            {
                D_02037B2C[(i + 1) * 2 + 1] = obj->x + func_08075AF8(i * obj->size / 6 - (obj->size / 2 - 0x80)) / 2;
                D_02037B2C[(i + 1) * 2 + 2] = obj->y + func_08075AAC(i * obj->size / 6 - (obj->size / 2 - 0x80)) / 2;
            }
            D_02037B2C[17] = 0;
            obj->size++;
            break;
        }
        func_080A38B0(0);
        obj->phase = 0;
        obj->size = 0;
        obj->state++;
    case 2:
        if (obj->phase <= 3 || obj->size != 0)
        {
            D_02037B2C[0] = 8;
            D_02037B2C[1] = obj->x;
            D_02037B2C[2] = obj->y;
            for (i = 0; i < 7; i++)
            {
                D_02037B2C[(i + 1) * 2 + 1] = obj->x + func_08075AF8(i * 32 / 6 + 0x70 + obj->size) / 2;
                D_02037B2C[(i + 1) * 2 + 2] = obj->y + func_08075AAC(i * 32 / 6 + 0x70 + obj->size) / 2;
            }
            D_02037B2C[17] = 0;
            if (!(obj->phase & 1))
            {
                obj->size += 2;
                if (obj->size == 32)
                    obj->phase++;
            }
            else
            {
                obj->size -= 2;
                if (obj->size == -32)
                    obj->phase++;
            }
            break;
        }
        obj->size = 32;
        obj->state++;
    case 3:
        if (obj->size != 0)
        {
            D_02037B2C[0] = 8;
            D_02037B2C[1] = obj->x;
            D_02037B2C[2] = obj->y;
            for (i = 0; i < 7; i++)
            {
                D_02037B2C[(i + 1) * 2 + 1] = obj->x + func_08075AF8(i * obj->size / 6 - (obj->size / 2 - 0x80)) / 2;
                D_02037B2C[(i + 1) * 2 + 2] = obj->y + func_08075AAC(i * obj->size / 6 - (obj->size / 2 - 0x80)) / 2;
            }
            D_02037B2C[17] = 0;
            obj->size--;
            break;
        }
        obj->size = 0x80;
        obj->state++;
    case 4:
        if (obj->size != 0)
        {
            D_02037B2C[0] = 2;
            D_02037B2C[1] = obj->x;
            D_02037B2C[2] = obj->y;
            D_02037B2C[3] = obj->x - obj->size;
            D_02037B2C[4] = obj->y;
            D_02037B2C[5] = 0;
            obj->size -= 8;
        }
        else
        {
            func_080784F8();
            D_03000056 = 0;
            func_08077E6C(obj);
        }
        break;
    }
    for (i = 0; i < D_02037B2C[0]; i++)
        D_02037B2C[i * 2 + 1] = !(obj->flags & 2) ? D_02037B2C[i * 2 + 1] : 0xF0 - D_02037B2C[i * 2 + 1];
}
