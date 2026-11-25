#include "types.h"

struct Entry
{
    u16 flags;
    u16 id;
};

struct Info
{
    u8 kind;
    u8 field_1;
    u8 pad_2[0x72];
    struct Entry entries[3];
};

struct State
{
    u8 pad_0[8];
    u8 field_8;
    u8 pad_9[2];
    u8 field_B;
    u8 pad_C[4];
    struct Info *info;
    u8 pad_14[4];
    void *obj_18;
    u8 pad_1C[0x2C];
    void *obj_48;
};

struct Camera
{
    s32 x;
    s32 y;
    s32 field_8;
    s32 field_C;
    s32 field_10;
};

struct Part
{
    u32 field_0;
    u8 pad_4[0xC];
};

struct Kind
{
    u8 pad_0[2];
    u8 pal;
    u8 pad_3[0x31];
};

struct Save
{
    u8 pad_0[0x14];
    u8 field_14;
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern struct Save D_02009480;
extern void *D_02030B4C[];
extern void *D_02030B48;
extern u16 D_02001480[];
extern u8 D_0203124F;
extern u32 D_0201F5C4;
extern u16 D_0300004C;
extern u16 D_0300004E;
extern u16 D_03000050;
extern s16 D_03000052;
extern const struct Kind D_0873FCC8[];
extern const s16 D_087AD848[][8][2];
extern const s16 D_0879F990[][16];
extern const struct Part D_087B0324[];
extern const struct Part D_087B4C9C[];
extern const u8 D_087AEBA8[][3];
extern const s16 D_087B0FC4[];
extern const u8 D_087B0974[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_080F2354[];
extern const u8 D_080F2390[];
extern const u8 D_08000D21[];
extern const u8 D_08000DCA[];
extern const u8 D_08000DD5[];
extern const u8 D_08000DBF[];
void *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void *func_0807FA0C(u8, u8, u8, u8, u8, u16 *);
void func_0807FF9C(const struct Part *, u8, u16, u16);
void *func_080A0388(const void *, u16, u16, s16, s16, u16, u16, u32, s32, u8);
void func_080C8B7C(const void *, void *, u32);
void func_0807C290(const u8 *);
void func_0808B590(struct Info *, u8, void *, void *, u8);
void func_0808B868(void);
void func_0808CB54(void);
void func_0808C9D0(void);
void func_0808CA38(u8, u8, u8, u8);
void func_0808D35C(void);
void func_080785C0(u8, u8, u8, u8, u8);
void func_08078688(u8);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808A86C(u32);
s32 func_0808B9B4(void);
void func_0808C9A4(void);
void func_08075DA8(u8, void (*)(void));
void func_0808C8D8(void);
s32 func_0808CBB0(u8);
void func_08075E28(u8);
void func_0808C9F8(void);
void func_0808CFEC(void);
s32 func_0808D4D0(void);
void func_080784F8(void);
void func_080771F4(void *);
void func_08077E6C(void *);

void func_0808D7C0(u8 mode)
{
    u8 i;
    u32 pal;
    vu16 fill;
    u8 state;
    s32 r;

    D_0300004C |= 0x300;
    D_0201F5F8.obj_18 = func_080771BC(D_08424594, D_084245A0, 0, 0xC8, 0x68, 0x180, 3, 8, 0);
    D_0201F5F8.obj_48 = func_080771BC(D_080F2354, D_080F2390, D_0873FCC8[D_0201F5F8.info->kind].pal, 0x88, 0x50, 0x30D, 0xF, 8, 0);
    D_0300004E = 0x4586;
    D_02030B48 = func_0807FA0C(D_0201F5F8.info->kind, D_0201F5F8.info->field_1, 1, 5, 0, D_02001480);
    if (D_0201F5F8.info->entries[0].flags != 0 || D_0201F5F8.info->entries[0].id != 0)
    {
        D_03000060.x = (D_087AD848[D_0201F5F8.info->kind][0][0] - 0xD0) << 8;
        if (D_087AD848[D_0201F5F8.info->kind][0][1] < 0x20)
            D_03000060.y = 0;
        else
            D_03000060.y = 0x1000;
    }
    else
    {
        D_03000060.x = (D_0879F990[D_0201F5F8.info->kind][8] - 0xAC) << 8;
        D_03000060.y = 0x1000;
    }
    for (i = 0; i < 3; i++)
    {
        if ((u16)(D_0201F5F8.info->entries[i].id - 1) <= 0x63 && D_087B0324[D_0201F5F8.info->entries[i].id].field_0 != 0)
        {
            func_0807FF9C(D_087B0324, D_0201F5F8.info->entries[i].id * 2 + (i != 0), i << 7, i);
            pal = D_087AEBA8[D_0201F5F8.info->kind][i];
            if (pal == 1)
                pal = 2;
            D_02030B4C[i] = func_080A0388(D_087B0974, D_0201F5F8.info->entries[i].id * 2 + (i != 0), 0,
                D_087AD848[D_0201F5F8.info->kind][i][0] - (i == 2 ? D_087B0FC4[D_0201F5F8.info->entries[2].id] : 0),
                D_087AD848[D_0201F5F8.info->kind][i][1], i << 7, i, (pal << 6) | 0x1128, 0, 0);
        }
        else
        {
            D_02030B4C[i] = 0;
        }
    }
    D_03000050 = 0x208;
    D_03000052 = (D_03000052 & 0x3FFC) | 0xC001;
    fill = D_0201F5C4;
    func_080C8B7C((void *)&fill, (void *)0x06000800, 0x01000C00);
    func_0807C290(D_08000D21);
    func_0807C290(D_08000DCA);
    func_0808B590(D_0201F5F8.info, 3, D_0201F5F8.obj_18, D_0201F5F8.obj_48, 0);
    func_0808B868();
    func_0808CB54();
    func_0808C9D0();
    func_0808CA38(0, 0x1F, 2, 1);
    func_0808D35C();
    func_0807FF9C(D_087B4C9C, 0, 0x1C0, 4);
    func_080785C0(0, 0, 0x78, 0x58, 0x3F);
    func_08078688(0x3B);
    D_03000060.field_C = 0;
    D_03000060.field_8 = 0;
    D_03000060.field_10 = 0x7800;
    state = 1;
    D_0201F5F8.field_8 = 0;
    D_0201F5F8.field_B = 0;
    for (;;)
    {
        if (state == 0)
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            func_0808A86C(1);
            func_0808A7F8(2, 7, 0xAC, 0x68);
            r = func_0808D4D0();
            if (r == -1)
                break;
            if (r == 0)
                state = 1;
        }
        else if (state == 1)
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            if (D_0203124F > 1)
                func_0808A7F8(1, 8, 0x18, 0x68);
            else
                func_0808A86C(1);
            func_0808A7F8(2, 9, 0x9C, 0x68);
            r = func_0808B9B4();
            if (r == -1)
                break;
            if (r == 0)
            {
                state = 0;
            }
            else if (r == 1)
            {
                func_0808C9A4();
                state = 2;
            }
        }
        else if (state == 2)
        {
            func_0808A7F8(0, 1, 0x6C, 0x98);
            func_0808A7F8(1, 10, 0x18, 0x68);
            func_0808A86C(2);
            func_08075DA8(3, func_0808C8D8);
            r = func_0808CBB0(mode);
            if (r == -1)
            {
                func_08075E28(3);
                break;
            }
            if (r == 0)
            {
                func_08075E28(3);
                state = 1;
            }
            else
            {
                state = 3;
            }
        }
        else if (state == 3)
        {
            func_0808A86C(0);
            func_0808A86C(1);
            func_0808A86C(2);
            func_0808C9F8();
            func_0808CFEC();
            func_0808CA38(D_02009480.field_14, 0x1F, 2, 1);
            state = 2;
        }
    }
    func_0807C290(D_08000DD5);
    func_0807C290(D_08000DBF);
    func_080784F8();
    func_080771F4(D_0201F5F8.obj_18);
    func_080771F4(D_0201F5F8.obj_48);
    func_08077E6C(D_02030B48);
    for (i = 0; i < 3; i++)
    {
        if (D_02030B4C[i] != 0)
            func_080771F4(D_02030B4C[i]);
    }
    func_0808A86C(0);
    func_0808A86C(1);
    func_0808A86C(2);
    func_0808C9F8();
    D_0300004C &= 0xFCFF;
    D_03000052 &= 0x3FFC;
    D_03000060.field_10 = 0;
}
