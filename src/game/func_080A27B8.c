#include "types.h"

struct State
{
    u8 pad_0[0x98];
    u8 mirror;
};

struct Game
{
    u8 pad_0[0x4E6F];
    u8 types[2];
};

struct Display
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
};

struct Task
{
    u8 pad_0[0x8C];
    s32 type;
};

extern struct State D_02036E7C;
extern struct Game D_02031A0C;
extern u16 D_0300004C;
extern u16 D_03000050;
extern struct Display D_03000060;
extern u16 D_03000056;
extern u16 D_03000058;
extern const u16 D_08735898[];
extern const void *const D_0873588C[];
extern const u8 D_080F47F4[];
extern const u8 D_080F4E44[];
extern u8 D_02001480[];

void func_080C8B84(const void *src, void *dst);
void func_08080168(const void *src, u8 a, u8 b, void *buf);
struct Task *func_08077DF0(u32 a, void (*init)(struct Task *), void (*update)(struct Task *));
void func_080A25D8(struct Task *task);
void func_080A26FC(struct Task *task);
void func_08075F20(u16 se);
void func_080C8FCC(u32 frames);
void func_08077E6C(struct Task *task);

void func_080A27B8(void)
{
    struct Task *task;
    u32 i;
    D_0300004C |= 0x200;
    D_03000050 = 0x170B;
    D_03000060.field_8 = 0;
    D_03000060.field_C = D_08735898[D_02031A0C.types[D_02036E7C.mirror] - 0x26];
    func_080C8B84(D_080F47F4, (void *)0x0600A980);
    func_080C8B84(D_0873588C[D_02031A0C.types[D_02036E7C.mirror] - 0x26], (void *)0x05000100);
    func_08080168(D_080F4E44, 0x17, D_02036E7C.mirror, D_02001480);
    task = func_08077DF0(0, func_080A25D8, func_080A26FC);
    task->type = D_02031A0C.types[D_02036E7C.mirror] - 0x26;
    D_03000056 = 0x442;
    D_03000058 = 0x10;
    func_08075F20(0x113);
    for (i = 0; i < 0x98; i++)
    {
        if (D_02036E7C.mirror == 0)
            D_03000060.field_8 -= 0x1000;
        else
            D_03000060.field_8 += 0x1000;
        if (i >= 0x78)
            D_03000058 = (((i - 0x78) / 2) << 8) | ((0x98 - i) / 2);
        func_080C8FCC(1);
    }
    D_0300004C &= ~0x200;
    D_03000056 = 0;
    func_08077E6C(task);
}
