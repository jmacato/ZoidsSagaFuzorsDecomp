#include "types.h"

struct Obj
{
    u32 flags;
};

struct State
{
    u8 pad_0[0x58];
    struct Obj *obj_58;
    struct Obj *obj_5C;
};

struct Save
{
    u8 pad_0[0x7A50];
    u32 flags[4];
    u8 list[10];
};

extern struct State D_0201F5F8;
extern struct Save D_02020E4C;
extern const u8 D_0873559C[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern const u8 D_0800398B[];
extern const u8 D_080039CC[];
extern const u8 D_08003A0B[];
extern const u8 D_08003A53[];
extern const u8 D_080F21DC[];
extern const u8 D_080F21E8[];
extern const u8 D_080F24AC[];
extern const u8 D_080F24B8[];
extern const u8 D_080F2268[];
extern const u8 D_080F2274[];
void func_0807C290(const u8 *);
void func_08091738(void);
void func_08091770(void);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808A86C(u32);
void func_0808A890(u32);
void func_0808A8B4(u32);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(struct Obj *);
void func_080C1B4C(u32, u8);
u32 func_0807F26C(u8, u8);
void func_08075F20(u32);

void func_0809181C(u8 mode)
{
    u8 slot;
    u8 id;
    s32 state;

    func_0807C290(D_0800398B);
    func_08091738();
    func_08091770();
    if (mode == 0)
    {
        func_0808A7F8(0, 1, 0xD8, 0x98);
        func_0808A7F8(1, 4, 0x78, 0x98);
    }
    else
    {
        D_0201F5F8.obj_58 = func_080771BC(D_080F21DC, D_080F21E8, 0, 0xD8, 0x98, 0x3D4, 0xF, 8, 0);
        D_0201F5F8.obj_5C = func_080771BC(D_080F24AC, D_080F24B8, 0, 0x78, 0x98, 0x3DC, 0xF, 8, 0);
    }
    state = 0;
    while (1)
    {
        if (state == 0)
        {
            func_0807C290(D_080039CC);
            if (D_0200C4A2 == 1)
            {
                slot = D_0200C4A0;
                if (mode == 0)
                {
                    func_0808A86C(0);
                    func_0808A7F8(0, 3, 0xC8, 0x98);
                }
                else
                {
                    func_080771F4(D_0201F5F8.obj_58);
                    D_0201F5F8.obj_58 = func_080771BC(D_080F2268, D_080F2274, 0, 0xC8, 0x98, 0x3D7, 0xF, 8, 0);
                }
                state = 1;
            }
            else if (D_0200C4A2 == 2)
            {
                break;
            }
            else
            {
                if (mode == 0)
                {
                    func_0808A890(0);
                    func_0808A890(1);
                }
                else
                {
                    D_0201F5F8.obj_58->flags |= 0x20000;
                    D_0201F5F8.obj_5C->flags |= 0x20000;
                }
                if (D_02020E4C.list[D_0200C4A0] != 0)
                    func_080C1B4C(7, D_02020E4C.list[D_0200C4A0]);
                else
                    func_080C1B4C(7, 0);
                if (mode == 0)
                {
                    func_0808A8B4(0);
                    func_0808A8B4(1);
                }
                else
                {
                    D_0201F5F8.obj_58->flags &= ~0x20000;
                    D_0201F5F8.obj_5C->flags &= ~0x20000;
                }
            }
        }
        else
        {
            func_0807C290(D_08003A0B);
            id = D_0873559C[D_0200C4A0];
            if (D_0200C4A2 == 1)
            {
                if (func_0807F26C(id, slot))
                {
                    func_08091738();
                    func_08091770();
                    if (mode == 0)
                    {
                        func_0808A86C(0);
                        func_0808A7F8(0, 1, 0xD8, 0x98);
                    }
                    else
                    {
                        func_080771F4(D_0201F5F8.obj_58);
                        D_0201F5F8.obj_58 = func_080771BC(D_080F21DC, D_080F21E8, 0, 0xD8, 0x98, 0x3D4, 0xF, 8, 0);
                    }
                    state = 0;
                }
                else
                {
                    func_08075F20(0x114);
                }
            }
            else if (D_0200C4A2 == 2)
            {
                if (mode == 0)
                {
                    func_0808A86C(0);
                    func_0808A7F8(0, 1, 0xD8, 0x98);
                }
                else
                {
                    func_080771F4(D_0201F5F8.obj_58);
                    D_0201F5F8.obj_58 = func_080771BC(D_080F21DC, D_080F21E8, 0, 0xD8, 0x98, 0x3D4, 0xF, 8, 0);
                }
                state = 0;
            }
            else
            {
                if (mode == 0)
                {
                    func_0808A890(0);
                    func_0808A890(1);
                }
                else
                {
                    D_0201F5F8.obj_58->flags |= 0x20000;
                    D_0201F5F8.obj_5C->flags |= 0x20000;
                }
                if (id != 0 && (D_02020E4C.flags[id >> 5] & (1 << (id & 31))))
                    func_080C1B4C(7, id);
                else
                    func_080C1B4C(7, 0);
                if (mode == 0)
                {
                    func_0808A8B4(0);
                    func_0808A8B4(1);
                }
                else
                {
                    D_0201F5F8.obj_58->flags &= ~0x20000;
                    D_0201F5F8.obj_5C->flags &= ~0x20000;
                }
            }
        }
    }
    func_0807C290(D_08003A53);
    if (mode == 0)
    {
        func_0808A86C(0);
        func_0808A86C(1);
    }
    else
    {
        func_080771F4(D_0201F5F8.obj_58);
        func_080771F4(D_0201F5F8.obj_5C);
    }
}
