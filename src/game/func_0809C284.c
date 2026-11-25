#include "types.h"

struct Obj
{
    u32 flags;
};

struct Slot
{
    u8 flags;
    u8 tile;
    s16 field_2;
    struct Obj *obj;
    struct Obj *icon;
    s32 x;
    s32 z;
    s32 y;
};

struct Unit
{
    u8 data[0x108];
};

struct Event
{
    u8 side;
    u8 slot;
    u8 id;
    u8 pad_3;
    s16 prio;
    u16 pad_6;
};

struct Game
{
    u8 field_0;
    u8 field_1;
    u8 count;
    u8 cursor;
    struct Event events[0x4A];
    u8 pad_254[4];
    struct Unit units[2][7];
    u8 pad_10C8[0x1038];
    struct Unit temp;
    u8 pad_2208[0x2C35];
    u8 grid[2][9];
    u8 order[2][6];
};

struct Zoid
{
    u8 pad_0[0x68];
    s16 field_68;
};

extern struct Game D_02031A0C;
extern struct Slot D_02037B6C[][6];

void func_0809FCD4(u8 state, u8 side, u8 slot, u8 apply);
void func_080A0108(void);
struct Zoid *func_0809A908(u8 side, u8 slot);
void func_0809F7F4(u8 side);
void func_08075F20(u16 se);
void func_080C8FCC(u32 frames);
void func_0809F9DC(u8 side);
void func_0809F7AC(u8 side);

void func_0809C284(u8 side, u8 *perm)
{
    struct Slot tmpSlot;
    u8 inv[6];
    u8 done, i, j, pal;
    func_0809FCD4(2, side, 0, 0);
    func_080A0108();
    done = 0;
    for (i = 0; i < 6; i++)
    {
        if ((done >> i) & 1)
            continue;
        if (perm[i] == i)
            continue;
        D_02031A0C.temp = D_02031A0C.units[side][i];
        tmpSlot = D_02037B6C[side][i];
        j = i;
        do
        {
            D_02031A0C.units[side][j] = D_02031A0C.units[side][perm[j]];
            D_02037B6C[side][j] = D_02037B6C[side][perm[j]];
            if (D_02037B6C[side][j].flags & 1)
            {
                D_02037B6C[side][j].flags |= 4;
                done |= 0x40;
            }
            j = perm[j];
            done |= 1 << j;
        } while (perm[j] != i);
        D_02031A0C.units[side][j] = D_02031A0C.temp;
        D_02037B6C[side][j] = tmpSlot;
        if (D_02037B6C[side][j].flags & 1)
        {
            D_02037B6C[side][j].flags |= 4;
            done |= 0x40;
        }
        done |= 1 << i;
    }
    for (i = 0; i < 6; i++)
        inv[perm[i]] = i;
    for (i = 0; i < 9; i++)
    {
        if (D_02031A0C.grid[side][i] != 0xFF)
        {
            D_02031A0C.grid[side][i] = (D_02031A0C.grid[side][i] & 0xF0) | inv[D_02031A0C.grid[side][i] & 0xF];
            D_02031A0C.grid[side][i] = (D_02031A0C.grid[side][i] & 0xF) | (inv[D_02031A0C.grid[side][i] >> 4] << 4);
        }
    }
    for (i = 0; i < 6; i++)
    {
        if (D_02031A0C.order[side][i] != 0xFF)
            D_02031A0C.order[side][i] = inv[D_02031A0C.order[side][i]];
    }
    for (i = 0; i < D_02031A0C.count; i++)
    {
        if (D_02031A0C.events[i].side == side)
        {
            D_02031A0C.events[i].slot = inv[D_02031A0C.events[i].slot];
            D_02031A0C.events[i].prio = func_0809A908(side, D_02031A0C.events[i].slot)->field_68;
        }
    }
    if (done & 0x40)
    {
        func_0809F7F4(side);
        for (i = 0; i < 6; i++)
        {
            if (D_02037B6C[side][i].flags & 1)
                D_02037B6C[side][i].obj->flags = (D_02037B6C[side][i].obj->flags & ~0xC0) | 0x400C0;
        }
        func_08075F20(0xE1);
        do
        {
            func_080C8FCC(1);
            for (i = 0; i < 6; i++)
            {
                if ((D_02037B6C[side][i].flags & 5) == 5)
                    break;
            }
        } while (i != 6);
        for (i = 0; i < 6; i++)
        {
            if (D_02037B6C[side][i].flags & 1)
            {
                if (side == 0)
                    pal = 3 - i % 3;
                else
                    pal = i % 3 + 1;
                D_02037B6C[side][i].obj->flags = (D_02037B6C[side][i].obj->flags & 0xFFFBFF3F) | (pal << 6);
            }
        }
        func_0809F9DC(side);
        func_0809F7AC(side);
    }
    for (i = 0; i < 15; i++)
        func_080C8FCC(1);
}
