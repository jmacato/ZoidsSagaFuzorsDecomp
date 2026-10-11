#include "types.h"

struct Unit
{
    u8 zoid;
    u8 pad_1[5];
    s16 field_6;
    u8 pad_8[0x100];
};

struct Game
{
    u8 pad_0[0x244];
    u8 side;
    u8 pad_245[0x13];
    struct Unit units[2][7];
    u8 pad_10C8[0x3DA7];
    u8 types[2];
};

struct Task
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_C[0x80];
    s32 type;
};

struct State
{
    u8 stage;
    u8 pad_1[0x93];
    void *field_94;
    u8 mirror;
    u8 pad_99[0x8BF];
    struct Task *field_958;
};

struct Frame
{
    u8 data[8];
};

extern struct Game D_02031A0C;
extern struct State D_02036E7C;
extern const struct Frame D_087B1090[];
extern const s16 D_0879F990[][16];
extern const u8 D_087B14E8[];

u8 func_0809B834(u8 side, u8 slot, u8 id, void *out);
void func_0807FF9C(const void *src, u8 a, u16 b, u8 c);
void *func_08077180(const void *data, u16 a, u16 b, s16 x, s16 y, u16 c, u16 d, u32 flags, void (*cb)(void *));
void func_080AC9D4(void *obj);
void func_080A20D8(void);
void func_080A2438(void);
struct Task *func_08077DF0(u32 a, void (*init)(struct Task *), void (*update)(struct Task *));
void func_080A25D8(struct Task *task);
void func_080A25FC(struct Task *task);

void func_080A290C(u8 side, u8 slot)
{
    if (func_0809B834(side, slot, 0x23, 0) != 0xFF)
    {
        func_0807FF9C(&D_087B1090[D_02031A0C.units[side][slot].field_6], 0, 0x380, 0xE);
        D_02036E7C.field_94 = func_08077180(D_087B14E8, D_02031A0C.units[side][slot].field_6, 0,
            D_02036E7C.mirror == 0 ? D_0879F990[D_02036E7C.stage][2] : 0x100 - D_0879F990[D_02036E7C.stage][2],
            D_0879F990[D_02036E7C.stage][3], 0x380, 0xE,
            D_02036E7C.mirror ? 0x9248 : 0x1248, func_080AC9D4);
    }
    else
        D_02036E7C.field_94 = 0;
    if (func_0809B834(side, slot, 0x2C, 0) != 0xFF)
        func_080A20D8();
    if (func_0809B834(side, slot, 0x22, 0) != 0xFF)
        func_080A2438();
    if (side == D_02031A0C.side
        && ((D_02031A0C.types[side] == 0x26 && slot == 1) || (D_02031A0C.types[side] == 0x27 && slot == 4) || (D_02031A0C.types[side] == 0x28 && slot == 1)))
    {
        struct Task *task = func_08077DF0(0, func_080A25D8, func_080A25FC);
        D_02036E7C.field_958 = task;
        task->x = D_0879F990[D_02036E7C.stage][8];
        task->y = D_0879F990[D_02036E7C.stage][9];
        task->type = D_02031A0C.types[side] - 0x26;
    }
    else
        D_02036E7C.field_958 = 0;
}
