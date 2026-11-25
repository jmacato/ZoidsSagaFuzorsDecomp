#include "types.h"

struct Info
{
    u8 kind;
    u8 pad_1;
    u8 slot;
};

struct State
{
    u8 pad_0[0x10];
    struct Info *info;
    u8 pad_14[4];
    u32 *obj_18;
    u8 pad_1C[0x2C];
    u32 *obj_48;
};

struct Entry
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Save
{
    u8 pad_0[0x6BC4];
    struct Entry entries[1];
};

extern struct State D_0201F5F8;
extern struct Save D_02020E4C;
extern const u8 *D_087A43E0[];
extern const u8 D_080F36A8[];
extern const u8 D_080F36AC[];
extern const u8 D_08000DCA[];
void func_0807C290(const u8 *);
void func_0807B77C(const u8 *, u32, u32);
void func_0807B748(const u8 *, u32, u32, u32, u32);
const u8 *func_08082E70(u8);
void func_0807A1A4(void);

s32 func_0808CDA8(void)
{
    *D_0201F5F8.obj_18 &= ~0x20000;
    *D_0201F5F8.obj_48 &= ~0x20000;
    func_0807C290(D_08000DCA);
    func_0807B77C(D_087A43E0[D_0201F5F8.info->kind], 0, 3);
    func_0807B748(D_080F36A8, 0, 3, 1, 2);
    if (D_0201F5F8.info->slot != 0xFF)
        func_0807B77C(func_08082E70(D_02020E4C.entries[D_0201F5F8.info->slot].id), 0, 3);
    else
        func_0807B77C(func_08082E70(0xFF), 0, 3);
    func_0807B77C(D_080F36AC, 0, 3);
    func_0807A1A4();
}
