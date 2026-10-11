#include "types.h"

struct Win
{
    u32 field_0;
    u8 pad_4[0x4CC];
};

struct Unit
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    u16 field_4;
    u16 field_6;
    u8 pad_8[2];
    u16 field_A;
    u16 field_C;
    u16 field_E;
    u16 field_10;
    u8 pad_12[0x82];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Unit units[0xBA];
};

struct Entry
{
    u8 pad_0[0x2E];
    u8 unit;
    u8 pad_2F[0x11];
};

struct Cfg
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u32 field_4;
    u8 pad_8[4];
    u8 field_C;
    u8 field_D;
    u8 field_E;
};

struct Member
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 pad_5[0x103];
};


struct Group
{
    struct Member members[7];
};

struct Battle
{
    u8 pad_0[0x258];
    struct Group groups[2];
    struct Unit items[2][11];
    struct Entry cells[2][7];
};

struct Demo
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    void *objs[2][6];
    u8 flags[2][6];
    u16 pal[16];
};

extern struct Save D_02020E4C;
extern struct Unit D_02020E88[];
extern struct Win D_02009480[];
extern struct Cfg D_02020E3C;
extern struct Battle D_02031A0C;
extern struct Demo D_02030AE8;
extern u16 D_0300000C;
extern u16 D_0300000E;
extern u16 D_030057EC;
extern u8 D_03000081;

void func_080C8B7C(const void *src, void *dest, u32 control);
void func_0807552C(void);
void func_080C8FCC(s32);
void func_0807BAD4(u8, u8, u8, u8, u8, u16);
void func_0807BD4C(u8);
void func_0807B77C(const u8 *, u32, u8);
void func_08075520(void);
void func_08075F20(u16);
void func_0807BD8C(u8);
void func_0807A1A4(void);
void func_0807970C(void);
u32 func_0807EC90(u8, u8);
u32 func_0807EE90(u8, u8);
u32 func_0807ECD8(u8, u8, u8, u8);
void func_080BDE24(u8, u8);
struct Entry *func_080C5EF0(u8);
void func_080BDDE4(struct Unit *, struct Entry *, u8);
void func_080BFA34(struct Entry *, u8, u8);
void func_080BF93C(struct Entry *, u8, u8);
void func_080BFAC4(struct Entry *, u8);
void func_0807F0C4(u8, u8);
void func_0807F128(u8, u8);
void func_0807F18C(u8);
void func_0807F1D0(u8, u8);
void func_0807F234(u8);
void func_0807F2D4(u32);
void func_080C5E98(u8);
void func_08075DA8(u8, void (*)(void));
void func_08075DB8(u8, void (*)(u32), u32);
void func_08091E48(void);
void func_080B4C54(u32);
void func_080B7708(void);
void func_080B828C(u32);
void func_080C5D44(void);
void func_08099664(void);
void func_080BE58C(u8);
void func_080BD488(u8, u8, struct Unit *);
void func_080BF608(u8, u8, struct Entry *);
void func_080BE46C(u8, u8);
void func_08075E28(u8);

void func_080C5F20(u8 *pc)
{
    s32 done;
    u8 mode;
    s32 prev;
    u8 win;
    u16 i;
    u8 op;
    u8 j;
    struct Entry *e;
    struct Unit *unit;
    vu32 zero;

    zero = 0;
    func_080C8B7C((void *)&zero, &D_02020E4C, 0x05000000 | (0x7B5C / 4));
    done = 0;
    mode = 0;
    prev = 0;
    win = 0xFF;
    func_0807552C();

    do
    {
        if (((*pc == 1 && prev != 1) || *pc == 2) && prev != 3)
        {
            D_0300000C = D_0300000E = D_030057EC = 0;
            for (i = 0; i < 15; i += D_03000081)
                func_080C8FCC(1);
        }

        op = *pc;
        prev = op;
        switch (op)
        {
        case 0:
            done = 1;
            break;
        case 1:
            if (win == 0xFF)
            {
                for (win = 0; win < 10; win++)
                {
                    if (!(D_02009480[win].field_0 & 1))
                    {
                        if (mode == 4)
                            func_0807BAD4(win, 0, 0xC, 0x1E, 8, 0x410);
                        else if (mode == 3)
                            func_0807BAD4(win, 0x20, 0xC, 0x1E, 8, 0x410);
                        else
                            func_0807BAD4(win, 0, 0x2C, 0x1E, 8, 0x410);
                        break;
                    }
                }
            }
            else
            {
                func_0807BD4C(win);
            }
            pc++;
            func_0807B77C(pc, 0, win);
            func_08075520();
            while (!(D_0300000E & 0xB))
            {
                D_0300000C = D_0300000E = D_030057EC = 0;
                func_080C8FCC(1);
                if (D_0300000E & 8)
                    done = 1;
            }
            func_08075F20(0xCD);
            func_0807552C();
            if (done)
            {
                func_0807BD8C(win);
                func_0807A1A4();
                func_080C8FCC(1);
                win = 0xFF;
            }
            else
            {
                while (*pc != 0)
                {
                    if (*pc == 1)
                        pc++;
                    pc++;
                }
                pc++;
                if (*pc != 1)
                {
                    func_0807BD8C(win);
                    func_0807A1A4();
                    func_080C8FCC(1);
                    win = 0xFF;
                }
            }
            break;
        case 2:
            D_0300000C = D_0300000E = D_030057EC = pc[1] | (pc[2] << 8);
            func_080C8FCC(1);
            pc += 3;
            break;
        case 3:
        {
            u16 n = pc[1] | (pc[2] << 8);
            i = 0;
            pc += 3;
            while (i < n)
            {
                func_080C8FCC(1);
                i += D_03000081;
            }
            break;
        }
        case 4:
            func_0807EC90(pc[1], 0);
            pc += 2;
            break;
        case 5:
            j = func_0807EC90(pc[1], 0);
            D_02020E4C.units[j].field_6 = 0;
            D_02020E4C.units[j].field_4 |= 2;
            pc += 2;
            break;
        case 6:
            func_0807EE90(pc[1], 1);
            pc += 2;
            break;
        case 7:
            func_0807ECD8(pc[1], 0, pc[2], 1);
            pc += 3;
            break;
        case 8:
            func_080BDE24(func_0807ECD8(pc[1], 0, pc[2], 1), pc[3]);
            pc += 4;
            break;
        case 9:
        {
            e = func_080C5EF0(pc[1]);
            if (e->unit)
                D_02020E4C.units[e->unit].field_6 -= pc[2] | (pc[3] << 8);
            pc += 4;
            break;
        }
        case 10:
        {
            e = func_080C5EF0(pc[1]);
            if (e->unit)
            {
                unit = &D_02020E88[e->unit];
                switch (pc[2])
                {
                case 0:
                    unit->field_A += pc[3] | (pc[4] << 8);
                    break;
                case 1:
                    unit->field_C += pc[3] | (pc[4] << 8);
                    break;
                case 2:
                    unit->field_E += pc[3] | (pc[4] << 8);
                    break;
                case 3:
                    unit->field_10 += pc[3] | (pc[4] << 8);
                    break;
                }
                func_080BDDE4(unit, e, 0);
            }
            pc += 5;
            break;
        }
        case 11:
        {
            e = func_080C5EF0(pc[1]);
            for (j = 0; j < pc[4]; j++)
                func_080BFA34(e, pc[3], pc[2]);
            pc += 5;
            break;
        }
        case 12:
            e = func_080C5EF0(pc[1]);
            func_080BF93C(e, pc[2], pc[3]);
            pc += 4;
            break;
        case 13:
            e = func_080C5EF0(pc[1]);
            func_080BFAC4(e, pc[2]);
            pc += 3;
            break;
        case 14:
            func_0807F0C4(pc[1], 1);
            pc += 3;
            break;
        case 15:
            func_0807F128(pc[1], 1);
            pc += 2;
            break;
        case 16:
            func_0807F18C(pc[1]);
            pc += 2;
            break;
        case 17:
            func_0807F1D0(pc[1], 1);
            pc += 2;
            break;
        case 18:
            func_0807F234(pc[1]);
            pc += 2;
            break;
        case 19:
            func_0807F2D4(pc[1] | (pc[2] << 8) | (pc[3] << 16) | (pc[4] << 24));
            pc += 5;
            break;
        case 20:
            func_080C5E98(mode);
            func_08075DA8(2, func_08091E48);
            func_080C8FCC(1);
            func_0807970C();
            mode = 1;
            pc += 1;
            break;
        case 21:
            func_080C5E98(mode);
            func_08075DB8(2, func_080B4C54, pc[1]);
            func_080C8FCC(1);
            func_0807970C();
            mode = 2;
            pc += 2;
            break;
        case 22:
            func_080C5E98(mode);
            func_08075DA8(2, func_080B7708);
            func_080C8FCC(1);
            func_0807970C();
            mode = 3;
            pc += 1;
            break;
        case 23:
            func_080C5E98(mode);
            func_08075DB8(2, func_080B828C, pc[1]);
            func_080C8FCC(1);
            func_0807970C();
            mode = 4;
            pc += 2;
            break;
        case 24:
            func_080C5E98(mode);
            func_08075DA8(2, func_080C5D44);
            func_080C8FCC(1);
            func_0807970C();
            mode = 6;
            pc += 1;
            break;
        case 25:
            D_02030AE8.flags[pc[1]][pc[2]] = (D_02030AE8.flags[pc[1]][pc[2]] & 0xF0) | pc[3];
            pc += 4;
            break;
        case 26:
            func_080C5E98(mode);
            D_02020E3C.field_0 = 0;
            D_02020E3C.field_1 = 0;
            D_02020E3C.field_4 = 0;
            D_02020E3C.field_C = 0;
            D_02020E3C.field_D = 0;
            D_02020E3C.field_E = 0;
            func_080BE58C(1);
            func_08075DA8(2, func_08099664);
            D_02030AE8.field_1 = D_02030AE8.field_2 = 0;
            mode = 5;
            pc += 1;
            break;
        case 27:
        {
            u8 n = pc[1];
            struct Member *member = &D_02031A0C.groups[1].members[n];
            unit = &D_02031A0C.items[1][n];
            e = &D_02031A0C.cells[1][n];
            func_080BD488(pc[2], 0, unit);
            func_080BF608(pc[3], 1, e);
            member->field_0 = n;
            unit->field_2 = n;
            member->field_1 = n;
            {
                u8 ff = 0xFF;
                member->field_4 = ff;
                member->field_3 = ff;
                member->field_2 = ff;
            }
            func_080BE46C(1, n);
            pc += 4;
            break;
        }
        case 28:
            while (!D_02030AE8.field_1)
                func_080C8FCC(1);
            pc += 1;
            break;
        case 29:
            D_02030AE8.field_1 = 0;
            pc += 1;
            break;
        case 30:
            D_02030AE8.field_2 = 1;
            pc += 1;
            break;
        }
    } while (!done);

    func_080C5E98(mode);
    func_08075E28(2);
    func_08075520();
}
