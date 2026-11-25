#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_C[0xE];
    u16 frame;
    u16 field_1C;
};

struct Slot
{
    u8 flags;
    u8 tile;
    u8 pad_2[2];
    struct Obj *obj;
    struct Obj *icon;
    s32 x;
    s32 z;
    s32 y;
};

struct Zoid
{
    u8 type;
    u8 level;
};

struct ZoidInfo
{
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0x31];
};

struct Team
{
    u8 field_0;
    u8 leader;
    u8 field_2;
    u8 field_3;
};

struct Game
{
    u8 pad_0[0x244];
    u8 side;
    u8 slot;
    u8 field_246;
    u8 pad_247[5];
    struct Zoid *zoid;
    u8 *field_250;
    u8 pad_254[0x4D30];
    struct Team teams[8];
};

struct Fx
{
    u8 pad_0[0x98];
    u8 mirror;
    u8 pad_99[0x8A8 - 0x99];
    s32 field_8A8;
    s32 field_8AC;
    s32 field_8B0;
    s32 field_8B4;
    u8 pad_8B8[0x8CE - 0x8B8];
    u8 mode;
    u8 count;
    u8 done;
};

struct Bg
{
    s32 field_0;
    s32 field_4;
    u8 pad_8[0xC];
    s32 field_14;
};

extern struct Game D_02031A0C;
extern struct Slot D_02037B6C[][6];
extern u16 D_02030584;
extern const struct ZoidInfo D_0873FCC8[];
extern struct Fx D_02036E7C;
extern struct Bg D_03000060;
extern struct Obj *D_02030B48;
extern struct Obj *D_02030B4C[4];
extern const u8 D_0848C77C[];
extern const u8 D_0848D888[];
extern const u8 D_0848F68C[];
extern const u8 D_0848F72C[];
extern u8 D_02001480[];

void func_0809F7CC(u8 side, u8 slot);
void func_080C8FCC(u32 frames);
void func_08079544(u8 a, u8 b);
void func_0807970C(void);
void func_080A0358(void);
void func_080A31D0(u8, u8, u8, u8, void *);
void func_080A03FC(struct Zoid *);
void func_080BF3E4(u8 side, u8 slot, u8 a, u8 b);
void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);
void func_08075DA8(u8, void (*)(void));
void func_08097E70(void);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_08075F20(u16 se);
void func_08077E6C(struct Obj *);
void func_080771F4(struct Obj *);
void func_08075E28(u8);
void func_080784F8(void);
void func_0809325C(void);
void func_0809F724(u8 side, u8 slot);
void func_0809F530(u8 type, u8 a, u8 b, u8 side, u8 slot, s32 c, s32 d);
void func_0809F910(u8 side, u8 slot);
void func_0809F784(u8 side, u8 slot);

void func_08097FCC(void)
{
    struct Obj *obj;
    s32 speed;
    s32 state;
    u32 i;

    func_0809F7CC(D_02031A0C.side, D_02031A0C.slot);
    D_02037B6C[D_02031A0C.side][D_02031A0C.slot].flags |= 8;
    while (D_02037B6C[D_02031A0C.side][D_02031A0C.slot].flags & 8)
        func_080C8FCC(1);
    if (!(D_02030584 & 2))
    {
        func_08079544(2, 0x10);
        func_0807970C();
        func_080A0358();
        func_080A31D0(0xFF, 0, D_02031A0C.side, 0, 0);
        func_080A03FC(D_02031A0C.zoid);
        func_080BF3E4(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.field_246, D_02031A0C.teams[D_02031A0C.side].leader);
        func_080C8B84(D_0848C77C, (void *)0x06013000);
        func_0807F860(D_0848D888, (void *)0x05000260, D_02001480);
        D_02036E7C.field_8A8 = -0x9800;
        D_02036E7C.field_8AC = 0;
        D_03000060.field_4 = 0;
        D_03000060.field_14 = -0x3000;
        func_08075DA8(4, func_08097E70);
        D_02036E7C.mode = 1;
        D_02036E7C.count = 0;
        D_02036E7C.done = 0;
        obj = func_080771BC(D_0848F68C, D_0848F72C, 0, 0, 0, 0x180, 3, D_02036E7C.mirror ? 0x8018 : 0x18, 0);
        if (D_02036E7C.mirror == 0)
            obj->x = 0x32A00;
        else
            obj->x = -0x23A00;
        obj->y = 0x5000;
        D_02036E7C.field_8B0 = -0x100;
        D_02036E7C.field_8B4 = 0x200;
        speed = -0x300;
        func_08079544(1, 1);
        state = 0;
        while (D_02036E7C.done == 0)
        {
            if (D_02036E7C.mirror == 0)
                obj->x += speed;
            else
                obj->x -= speed;
            func_080C8FCC(1);
            switch (state)
            {
            case 0:
                if (D_02036E7C.field_8A8 != 0x2800)
                    break;
                obj->flags &= ~8;
                D_02036E7C.field_8B0 = D_02036E7C.field_8B4 = 0;
                state = 0x10;
            case 0x10:
                if (obj->frame == 0xC)
                {
                    func_08077E6C(D_02030B48);
                    for (i = 0; i < 4; i++)
                    {
                        if (D_02030B4C[i] != 0)
                            func_080771F4(D_02030B4C[i]);
                    }
                    func_080A03FC(D_02031A0C.zoid);
                    func_080C8FCC(1);
                    state = 0x20;
                    goto case20;
                }
                if (obj->frame == 0)
                {
                    speed = 0;
                    obj->y += 0x200;
                }
                else
                {
                    speed = (obj->frame >= 6 && obj->frame <= 8) ? -0x100 : 0;
                }
                if (obj->field_1C == 0 && (obj->frame == 1 || obj->frame == 9))
                    func_08075F20(0xDC);
                break;
            case 0x20:
            case20:
                if (obj->flags & 4)
                {
                    func_08075F20(0xE3);
                    state = 0x30;
                    goto case30;
                }
                speed = obj->frame <= 0xE ? 0x100 : 0;
                if (obj->field_1C == 0 && obj->frame == 0xF)
                    func_08075F20(0xDC);
                break;
            case 0x30:
            case30:
                if (D_02036E7C.field_8A8 > 0xFFFF)
                {
                    D_02036E7C.field_8B0 = 0x800;
                    speed = 0;
                    D_02036E7C.mode = 2;
                    D_02036E7C.count = 0;
                    state = 0x40;
                }
                else
                {
                    if (D_02036E7C.field_8B0 < 0x1000)
                        D_02036E7C.field_8B0 += 0x20;
                    if (D_02036E7C.field_8B4 > -0x800)
                    {
                        D_02036E7C.field_8B4 -= 0x40;
                        speed += 0x60;
                    }
                }
                break;
            case 0x40:
                break;
            }
        }
        func_08075E28(4);
        func_080784F8();
        func_0809325C();
        if (D_02031A0C.side == 0)
            D_02037B6C[D_02031A0C.side][D_02031A0C.slot].x += 0x10000;
        else
            D_02037B6C[D_02031A0C.side][D_02031A0C.slot].x += -0x10000;
        func_0809F7CC(D_02031A0C.side, D_02031A0C.slot);
        func_08079544(1, 0x10);
        func_0807970C();
    }
    else
    {
        func_08075F20(0xDF);
        func_080BF3E4(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.field_246, D_02031A0C.teams[D_02031A0C.side].leader);
        func_0809F724(D_02031A0C.side, D_02031A0C.slot);
        func_0809F530(D_02031A0C.zoid->type, D_02031A0C.zoid->level, D_0873FCC8[D_02031A0C.zoid->type].field_2, D_02031A0C.side, D_02031A0C.slot, 0, 0);
        if (D_02031A0C.side == 0)
            D_02037B6C[D_02031A0C.side][D_02031A0C.slot].x += 0x10000;
        else
            D_02037B6C[D_02031A0C.side][D_02031A0C.slot].x += -0x10000;
    }
    D_02037B6C[D_02031A0C.side][D_02031A0C.slot].flags |= 4;
    while (D_02037B6C[D_02031A0C.side][D_02031A0C.slot].flags & 4)
        func_080C8FCC(1);
    func_0809F910(D_02031A0C.side, D_02031A0C.slot);
    func_0809F784(D_02031A0C.side, D_02031A0C.slot);
    for (i = 0; i < 30; i++)
        func_080C8FCC(1);
}
