#include "types.h"

struct Info
{
    u8 id;
    u8 pad_1[0x2D];
    u8 zoid;
    u8 pad_2F[0xF];
    u8 field_3E;
};

struct State
{
    u8 pad_0[0xB];
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 pad_E[6];
    struct Info *info;
    u8 pad_18[0x34];
    void *obj;
};

struct Camera
{
    u8 pad_0[8];
    s32 field_8;
    s32 field_C;
    s32 field_10;
};

struct Zoid
{
    u8 pad_0[0x3C];
    u8 kind;
    u8 pad_3D[0x57];
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern struct Zoid D_02020E4C[];
extern u16 D_0300004C;
extern u16 D_03000050;
extern s16 D_03000052;
extern u8 D_0201F5CB;
extern u32 D_0201F5C4;
extern const u8 *D_087A43E0[];
extern const u8 D_080014CA[];
extern const u8 D_080015FB[];
extern const u8 D_085ECCF0[];
extern const u8 D_085ECCFC[];
void func_080C8B7C(void *, void *, u32);
void func_0807C290(const u8 *);
const u8 *func_08082E70(u8);
void func_0807B77C(const u8 *, u32, u32);
void func_0807B748(const u8 *, u32, u32, u32, u32);
void func_0808DECC(void);
void func_0808EBB8(void);
void func_0807A1A4(void);
void func_0807FEDC(u8, u32, u32, u32);
void *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0808A72C(struct Info *, u32);
void func_0808B1F0(u32, u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808A86C(u32);
s32 func_0808E020(void);
s32 func_0808E21C(void);
s32 func_0808E608(void);
s32 func_0808EC54(void);
void func_080771F4(void *);

void func_0808EE20(void)
{
    vu16 fill;
    s32 state;
    s32 r;

    D_0300004C |= 0x200;
    D_03000050 = 0x208;
    D_03000052 = (D_03000052 & 0x3FFC) | 0xC001;
    D_0201F5CB = 1;
    fill = D_0201F5C4;
    func_080C8B7C((void *)&fill, (void *)0x06000800, 0x01000C00);
    func_0807C290(D_080014CA);
    func_0807B77C(func_08082E70(D_0201F5F8.info->id), 0, 4);
    func_0807B748(D_087A43E0[D_02020E4C[D_0201F5F8.info->zoid].kind], 0, 4, 0, 2);
    func_0808DECC();
    func_0808EBB8();
    func_0807A1A4();
    func_0807FEDC(D_0201F5F8.info->id, 0, 0, 0);
    D_0201F5F8.obj = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 0xA8, 0x30, 0, 0, 8, 0);
    func_0808A72C(D_0201F5F8.info, 0);
    func_0808B1F0(0, 0);
    D_03000060.field_8 = D_03000060.field_C = 0;
    D_03000060.field_10 = 0x7800;
    state = 1;
    D_0201F5F8.field_B = D_0201F5F8.field_C = D_0201F5F8.field_D = 0;
    for (;;)
    {
        if (state == 0)
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            func_0808A86C(1);
            func_0808A7F8(2, 7, 0xAD, 0x68);
            r = func_0808EC54();
            if (r == -1)
                break;
            state = 1;
        }
        else if (state == 1)
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            if (D_0201F5F8.info->field_3E != 0)
                func_0808A7F8(1, 0xB, 0x18, 0x68);
            else
                func_0808A86C(1);
            func_0808A7F8(2, 0xC, 0xB6, 0x68);
            r = func_0808E020();
            if (r == -1)
                break;
            state = 2;
            if (r == 0)
                state = 0;
        }
        else if (state == 2)
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            func_0808A7F8(1, 0xA, 0x18, 0x68);
            func_0808A7F8(2, 0xD, 0x9E, 0x68);
            r = func_0808E21C();
            if (r == -1)
                break;
            state = 3;
            if (r == 0)
                state = 1;
        }
        else
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            func_0808A7F8(1, 0xE, 0x18, 0x68);
            func_0808A86C(2);
            r = func_0808E608();
            if (r == -1)
                break;
            state = 2;
        }
    }
    func_0807C290(D_080015FB);
    func_080771F4(D_0201F5F8.obj);
    func_0808A86C(0);
    func_0808A86C(1);
    func_0808A86C(2);
    D_0300004C &= ~0x200;
    D_03000052 &= 0x3FFC;
    D_0201F5CB = 0;
    D_03000060.field_10 = 0;
}
