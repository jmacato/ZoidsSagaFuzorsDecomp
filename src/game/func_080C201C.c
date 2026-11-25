#include "types.h"

struct Unit
{
    u8 id;
    u8 list[4];
    u8 pad[0x103];
};

struct Group
{
    struct Unit units[7];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    u8 pad[0x4E6F - 0x258 - 0x738 * 2];
    u8 types[3];
    s16 req[2][8];
};

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[8];
    s16 field_8;
    u8 padA[0x6A];
    struct Slot slots[8];
};

struct Stats
{
    u8 pad0[4];
    s16 field_4;
};

extern struct Data D_02031A0C;
extern u8 D_0200C4D8;
extern struct Stats D_02031410;
extern const u8 D_08004AF5[];
extern const u8 D_08004B3F[];
extern const u8 D_08004B89[];
extern const u8 D_08004BD5[];
extern const u8 D_08004C21[];
extern const u8 D_08004C69[];
extern const u8 D_08004CB1[];
extern const u8 D_08004D05[];

struct Obj *func_0809A908(u8, u8);
u32 func_0809A99C(u8, u8);
void func_0807C290(const u8 *);
void func_080C05A4(u8, u8, u8, u8, struct Stats *);

void func_080C201C(void)
{
    struct Obj *obj;
    u8 side, j, k, i;

    for (side = 0; side < 2; side++)
    {
        switch (D_02031A0C.types[side])
        {
        case 0x26:
            D_0200C4D8 = 0x26;
            for (j = 1, k = 1; j <= 5; j += 2, k++)
            {
                obj = func_0809A908(side, j);
                if (!func_0809A99C(side, j) || D_02031A0C.groups[side].units[j].id != D_02031A0C.req[side][k])
                {
                    if (side == 0)
                        func_0807C290(D_08004AF5);
                    else
                        func_0807C290(D_08004B3F);
                    D_02031A0C.types[side] = 0;
                    break;
                }
                for (i = 0; i < 8 && obj->slots[i].item != D_02031A0C.req[side][k + 3]; i++)
                    ;
                if (i == 8)
                {
                    if (D_02031A0C.req[side][k + 3] < 200)
                    {
                        if (side == 0)
                            func_0807C290(D_08004C21);
                        else
                            func_0807C290(D_08004C69);
                    }
                    else
                    {
                        if (side == 0)
                            func_0807C290(D_08004CB1);
                        else
                            func_0807C290(D_08004D05);
                    }
                    D_02031A0C.types[side] = 0;
                    break;
                }
                func_080C05A4(side, j, 0xFF, i, &D_02031410);
                if (D_02031410.field_4 > obj->field_8)
                {
                    if (side == 0)
                        func_0807C290(D_08004B89);
                    else
                        func_0807C290(D_08004BD5);
                    D_02031A0C.types[side] = 0;
                    break;
                }
            }
            break;
        case 0x27:
            D_0200C4D8 = 0x27;
            for (j = 0, k = 1; j <= 5; j += 2, k++)
            {
                obj = func_0809A908(side, j);
                if (!func_0809A99C(side, j) || D_02031A0C.groups[side].units[j].id != D_02031A0C.req[side][k])
                {
                    if (side == 0)
                        func_0807C290(D_08004AF5);
                    else
                        func_0807C290(D_08004B3F);
                    D_02031A0C.types[side] = 0;
                    break;
                }
                for (i = 0; i < 8 && obj->slots[i].item != D_02031A0C.req[side][k + 3]; i++)
                    ;
                if (i == 8)
                {
                    if (D_02031A0C.req[side][k + 3] < 200)
                    {
                        if (side == 0)
                            func_0807C290(D_08004C21);
                        else
                            func_0807C290(D_08004C69);
                    }
                    else
                    {
                        if (side == 0)
                            func_0807C290(D_08004CB1);
                        else
                            func_0807C290(D_08004D05);
                    }
                    D_02031A0C.types[side] = 0;
                    break;
                }
                func_080C05A4(side, j, 0xFF, i, &D_02031410);
                if (D_02031410.field_4 > obj->field_8)
                {
                    if (side == 0)
                        func_0807C290(D_08004B89);
                    else
                        func_0807C290(D_08004BD5);
                    D_02031A0C.types[side] = 0;
                    break;
                }
            }
            break;
        case 0x28:
            D_0200C4D8 = 0x28;
            if (!func_0809A99C(side, 1) || !func_0809A99C(side, 4)
                || D_02031A0C.groups[side].units[1].id != D_02031A0C.req[side][1]
                || D_02031A0C.groups[side].units[4].id != D_02031A0C.req[side][2])
            {
                if (side == 0)
                    func_0807C290(D_08004AF5);
                else
                    func_0807C290(D_08004B3F);
                D_02031A0C.types[side] = 0;
                break;
            }
            obj = func_0809A908(side, 1);
            for (i = 0; i < 4 && obj->slots[i].item != 0x51; i++)
                ;
            if (i == 4)
            {
                if (side == 0)
                    func_0807C290(D_08004C21);
                else
                    func_0807C290(D_08004C69);
                D_02031A0C.types[side] = 0;
                break;
            }
            func_080C05A4(side, 1, 0xFF, i, &D_02031410);
            if (D_02031410.field_4 > obj->field_8)
            {
                if (side == 0)
                    func_0807C290(D_08004B89);
                else
                    func_0807C290(D_08004BD5);
                D_02031A0C.types[side] = 0;
                break;
            }
            obj = func_0809A908(side, 4);
            for (i = 0; i < 8 && obj->slots[i].item != D_02031A0C.req[side][3]; i++)
                ;
            func_080C05A4(side, 4, 0xFF, i, &D_02031410);
            if (D_02031410.field_4 > obj->field_8)
            {
                if (side == 0)
                    func_0807C290(D_08004B89);
                else
                    func_0807C290(D_08004BD5);
                D_02031A0C.types[side] = 0;
            }
            break;
        }
    }
}
