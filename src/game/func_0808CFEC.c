#include "types.h"

struct Entry
{
  u8 flags;
  u8 pad_1;
  u16 id;
};

struct Info
{
  u8 kind;
  u8 pad_1;
  u8 pilot;
  u8 pad_3[0x6B];
  s16 field_6E;
  u8 pad_70[4];
  struct Entry entries[3];
};

struct State
{
  u8 pad_0[8];
  u8 field_8;
  u8 pad_9[7];
  struct Info *info;
};

struct Obj
{
  u32 flags;
};

struct Part
{
  u8 flags;
  u8 pad_1[7];
  s16 field_8;
  u8 pad_A[0xE];
};

struct Choice
{
  u16 id;
  u16 count;
};

struct Pilot
{
  u8 data[0x40];
};

extern struct State D_0201F5F8;

extern struct Choice D_02030C5C[];

extern struct Obj *D_02030B4C[];

extern const struct Part D_08741EF4[];

extern struct Pilot D_02027A10[];

extern u8 D_02031410[];

struct SaveO
{
    u8 pad_0[0x7904];
    u8 owned[0x100];
};

extern struct SaveO D_02020E4C;

extern u8 D_0200C4A0;

extern u8 D_0200C4A2;

extern u16 D_0200C4C8;

extern const u8 D_08001246[];

extern const u8 D_08001261[];

extern const u8 D_08001279[];

extern const u8 D_080012D2[];

extern const u8 D_08001374[];

extern const u8 D_08001329[];

extern const u8 D_08001265[];

void func_0807C290(const u8 *);

void func_0808A340(u32);

void func_0808AE2C(u32, u32);

void func_0808A7F8(u32, u32, u32, u32);

void func_080C0178(struct Info *, struct Pilot *, u8, u32, u8 *);

void func_0808BCA8(u32, const void *, u32, u32);

s32 func_0808CE50(u8);

void func_08075F20(u32);

s16 func_080BD430(struct Info *);

void func_08078540(u32, u32, u32, u32, u32);

void func_08078638(void);

void func_080BE0D4(struct Info *, u8, u8);

void func_080BDDE4(struct Info *, struct Pilot *, u32);

void func_0808B868(void);

void func_0808CB54(void);

void func_080771F4(struct Obj *);

void func_0808BB48(void);

void func_0808A86C(u32);

void func_0808CFEC(void)
{
    u32 sel;
    u8 flags;
    u8 locked;
    u32 pflags;
    u8 res;
    u32 m;

    flags = D_0201F5F8.info->entries[D_0201F5F8.field_8].flags;
    func_0807C290(D_08001246);
    func_0808A340(1);
    m = 1;
    m &= ~flags;
    if (!(flags & 2))
        m |= 2;
    func_0808AE2C(3, m);
    func_0808A7F8(0, 3, 0x64, 0x98);
    sel = 0;
    while (1)
    {
        if (D_02030C5C[sel].id == 0)
        {
            if (D_0201F5F8.info->entries[D_0201F5F8.field_8].id != 0)
            {
                if (D_0201F5F8.info->pilot != 0 && D_0201F5F8.info->pilot != 0xFF)
                    func_080C0178(D_0201F5F8.info, &D_02027A10[D_0201F5F8.info->pilot], D_0201F5F8.field_8, 0, D_02031410);
                else
                    func_080C0178(D_0201F5F8.info, 0, D_0201F5F8.field_8, 0, D_02031410);
                func_0808BCA8(2, D_02031410, 0, 0);
            }
            else
            {
                func_0808BCA8(2, 0, 0, 0);
            }
            if (func_0808CE50(D_0201F5F8.info->entries[D_0201F5F8.field_8].id))
                D_02030B4C[D_0201F5F8.field_8]->flags |= 0x200000;
            locked = 0;
        }
        else
        {
            func_0808BCA8(2, &D_08741EF4[D_02030C5C[sel].id], 0, 0);
            pflags = D_08741EF4[D_02030C5C[sel].id].flags;
            if (((flags & 1) || (pflags & 1)) && ((flags & 2) || !(pflags & 1)))
            {
                func_0808CE50(D_02030C5C[sel].id);
                locked = 0;
            }
            else
            {
                func_0808CE50(0);
                locked = 1;
            }
        }
        func_0807C290(D_08001261);
        sel = D_0200C4A0;
        res = D_0200C4A2;
        if (res == 1)
        {
            if (!locked)
            {
                if (D_02030C5C[sel].id != 0)
                {
                    if (func_080BD430(D_0201F5F8.info) + D_08741EF4[D_02030C5C[sel].id].field_8 - D_08741EF4[D_0201F5F8.info->entries[D_0201F5F8.field_8].id].field_8 > D_0201F5F8.info->field_6E)
                    {
                        func_08078540(0x10, 0x20, 0xE0, 0x80, 0x3D);
                        func_0807C290(D_08001374);
                        func_08078638();
                        if (D_0200C4A2 == 2 || D_0200C4A0 == 1)
                            continue;
                    }
                }
                if (D_0201F5F8.info->entries[D_0201F5F8.field_8].id != 0 && D_0201F5F8.info->entries[D_0201F5F8.field_8].id != D_02030C5C[sel].id
                    && D_02020E4C.owned[D_0201F5F8.info->entries[D_0201F5F8.field_8].id] > 0x62)
                {
                    func_08078540(0x40, 0x20, 0xB0, 0x80, 0x3D);
                    D_0200C4C8 = D_0201F5F8.info->entries[D_0201F5F8.field_8].id;
                    func_0807C290(D_08001329);
                    func_08078638();
                    if (D_0200C4A2 == 2 || D_0200C4A0 == 1)
                        continue;
                }
                func_08075F20(0xDC);
                func_080BE0D4(D_0201F5F8.info, D_0201F5F8.field_8, D_02030C5C[sel].id);
                if (D_0201F5F8.info->pilot != 0xFF)
                    func_080BDDE4(D_0201F5F8.info, &D_02027A10[D_0201F5F8.info->pilot], 0);
                else
                    func_080BDDE4(D_0201F5F8.info, 0, 0);
                func_0808B868();
                func_0808CB54();
                if (D_0201F5F8.info->entries[D_0201F5F8.field_8].id == 0)
                {
                    func_080771F4(D_02030B4C[D_0201F5F8.field_8]);
                    D_02030B4C[D_0201F5F8.field_8] = 0;
                }
                break;
            }
            if (!(res & pflags))
            {
                func_08075F20(0x114);
                func_0807C290(D_08001279);
            }
            else
            {
                func_08075F20(0x114);
                func_0807C290(D_080012D2);
            }
        }
        else if (res == 2)
        {
            func_0808CE50(D_0201F5F8.info->entries[D_0201F5F8.field_8].id);
            break;
        }
    }
    func_0807C290(D_08001265);
    func_0808BB48();
    func_0808A86C(0);
}
