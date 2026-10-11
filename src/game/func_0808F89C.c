#include "types.h"

struct Item
{
    u8 flags;
    u8 field_1;
    u16 kind;
    u8 pad_4[6];
    s16 field_A;
    u8 pad_C[0xC];
};

struct Obj
{
    u8 pad_0[8];
    s32 y;
};

extern u16 D_02030F7C;
extern u16 D_02030C5C[][2];
extern const struct Item D_08741EF4[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_030057EC;
extern u16 D_0300000E;
extern const u8 *D_087354C8[];
extern const u8 D_087354E4[];
extern const u8 *D_087354EC[];
extern const u8 D_08735538[];
extern const u8 *D_08735540[];
extern const u8 D_08735554[];
extern const u8 D_0800238E[];
extern const u8 D_08000BD3[];
extern const u8 D_08002355[];
extern const u8 D_08002385[];
extern const u8 D_080023C2[];
extern const u8 D_080023CD[];
extern const u8 D_08002389[];
extern const u8 D_080025F3[];
extern const u8 D_08002654[];
extern const u8 D_080026A8[];
extern const u8 D_08002702[];
extern const u8 D_08002B19[];
extern const u8 D_08002492[];
extern const u8 D_080030B1[];
extern const u8 D_08002CC7[];
extern const u8 D_08002572[];
extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];
void func_0808A340(u32);
void func_08075F20(u32);
void func_0807C290(const u8 *);
void func_0808AC08(void);
void func_0808AE2C(u8, u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808BCA8(u32, const struct Item *, u32, u32);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0808A890(u32);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_080771F4(struct Obj *);
void func_0808A8B4(u32);
void func_0808BB48(void);
void func_0808A86C(u32);
void func_0808AB28(void);
void func_0808F850(const struct Item *);

s32 func_0808F89C(void)
{
    const struct Item *item;
    struct Obj *cursor;
    u8 sel;
    u8 mode;
    u8 kind;
    u8 cur;
    u8 max;
    u8 done;

    func_0808A340(0);
    if (D_02030F7C == 0)
    {
        func_08075F20(0x114);
        func_0807C290(D_0800238E);
        return 0;
    }
    func_0808AC08();
    func_0807C290(D_08000BD3);
    func_0807C290(D_08002355);
    func_0808AE2C(5, 0);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    sel = 0;
    while (1)
    {
        item = &D_08741EF4[D_02030C5C[sel][0]];
        func_0808BCA8(6, item, 0, 3);
        func_0807C290(D_08002385);
        sel = D_0200C4A0;
        mode = D_0200C4A2;
        if (mode == 1)
        {
            func_0807C290(D_080023C2);
            cursor = func_080771BC(D_080C9680, D_080C96B4, 0, 0x78, 0, 0x3EE, 0xF, 0x5020, 0);
            func_0808A890(0);
            done = 0;
            cur = 0;
            if (!(item->flags & 1))
            {
                kind = 0;
                max = 6;
            }
            else if (item->kind != 0x12)
            {
                kind = 1;
                max = 4;
            }
            else
            {
                kind = 2;
                max = 7;
            }
            while (done == 0)
            {
                switch (kind)
                {
                case 0:
                    if (cur != 3)
                        func_0807C290(D_087354C8[cur]);
                    else if (item->kind & 2)
                        func_0807C290(D_080025F3);
                    else if (item->kind & 4)
                        func_0807C290(D_08002654);
                    else if (item->kind & 8)
                        func_0807C290(D_080026A8);
                    else if (item->kind & 0x10)
                        func_0807C290(D_08002702);
                    func_0807A1A4();
                    if (cur != 4)
                        cursor->y = D_087354E4[cur] << 11;
                    else
                        cursor->y = (D_087354E4[cur] << 11) + 0x400;
                    break;
                case 1:
                    switch (cur)
                    {
                    case 0:
                        if (item->kind != 0xD || item->field_A == 0)
                            func_0807C290(D_087354EC[item->kind - 1]);
                        else
                            func_0807C290(D_08002B19);
                        break;
                    case 1:
                        if (item->kind != 0x10 && item->kind != 0x11 && item->kind != 0x13)
                            func_0807C290(D_08002492);
                        else
                            func_0807C290(D_080030B1);
                        break;
                    case 2:
                        func_0807C290(D_08002CC7);
                        break;
                    case 3:
                        func_0807C290(D_08002572);
                        break;
                    case 4:
                        func_0808F850(item);
                        break;
                    }
                    func_0807A1A4();
                    if (cur != 0 && cur != 2)
                        cursor->y = D_08735538[cur] << 11;
                    else
                        cursor->y = (D_08735538[cur] << 11) + 0x400;
                    break;
                case 2:
                    if (cur == 0)
                        func_0807C290(D_087354EC[item->kind - 1]);
                    else if (cur < 6)
                        func_0807C290(D_08735540[cur - 1]);
                    else if (cur == 6)
                        func_0807C290(D_08002572);
                    else
                        func_0808F850(item);
                    func_0807A1A4();
                    cursor->y = D_08735554[cur] << 11;
                    break;
                }
                while (1)
                {
                    func_080C8FCC(1);
                    if (D_030057EC & 0x40)
                    {
                        func_08075F20(0xCC);
                        if (cur != 0)
                            cur--;
                        else
                            cur = max;
                        if ((kind == 0 && cur == 3 && (item->kind & ~1) == 0) || (kind == 1 && cur == 2 && item->field_1 == 0))
                            cur--;
                        break;
                    }
                    if (D_030057EC & 0x80)
                    {
                        func_08075F20(0xCC);
                        if (cur < max)
                            cur++;
                        else
                            cur = 0;
                        if ((kind == 0 && cur == 3 && (item->kind & ~1) == 0) || (kind == 1 && cur == 2 && item->field_1 == 0))
                            cur++;
                        break;
                    }
                    if (D_0300000E & 3)
                    {
                        func_08075F20(0xCB);
                        func_080771F4(cursor);
                        done = 1;
                        break;
                    }
                }
            }
            func_0807C290(D_080023CD);
            func_0808A8B4(0);
        }
        else if (mode == 2)
        {
            func_0807C290(D_08002389);
            func_0808BB48();
            func_0808A86C(0);
            func_0808AB28();
            return 1;
        }
    }
}
