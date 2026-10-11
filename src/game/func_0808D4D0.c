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
    u8 pilot;
    u8 pad_3[0x71];
    struct Entry entries[3];
};

struct State
{
    u8 pad_0[8];
    u8 field_8;
    u8 pad_9[7];
    struct Info *info;
    u8 pad_14[4];
    void *obj_18;
    u8 pad_1C[0x2C];
    void *obj_48;
};

struct Pilot
{
    u8 data[0x40];
};

struct Camera
{
    s32 x;
    s32 y;
    u8 pad_8[8];
    s32 field_10;
};

struct Part
{
    u32 field_0;
    u8 pad_4[0xC];
};

extern struct State D_0201F5F8;
extern struct Pilot D_02027A10[];
extern struct Camera D_03000060;
extern void *D_02030B4C[];
extern void *D_02030B48;
extern u8 D_02001CA0[];
extern u8 D_0203124A[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const s16 D_087AD848[][8][2];
extern const s16 D_0879F990[][16];
extern const struct Part D_087B0324[];
extern const u8 D_087AEBA8[][3];
extern const s16 D_087B0FC4[];
extern const u8 D_087B0974[];
extern const u8 D_080011E0[];
extern const u8 D_080011DC[];
void func_0807C290(const u8 *);
void func_08075F20(u32);
void func_080BE058(struct Info *, u8);
void func_080BDDE4(struct Info *, struct Pilot *, u32);
void func_0808B590(struct Info *, u32, void *, void *, u32);
void func_0808D35C(void);
void func_0808B868(void);
void func_0808CB54(void);
void func_08077E6C(void *);
void *func_0807FA0C(u8, u8, u32, u32, u32, u8 *);
void func_080771F4(void *);
void func_0807FF9C(const struct Part *, u8, u16, u16);
void *func_080A0388(const void *, u16, u16, s16, s16, u16, u16, u32, s32, u8);
void func_080C8FCC(u32);

s32 func_0808D4D0(void)
{
    u8 i;
    u32 pal;

    func_0807C290(D_080011E0);
    while (1)
    {
        func_0807C290(D_080011DC);
        if (D_0200C4A2 == 1)
        {
            if (D_0201F5F8.info->kind != D_0203124A[D_0200C4A0])
            {
                func_08075F20(0xDF);
                func_080BE058(D_0201F5F8.info, D_0200C4A0);
                if (D_0201F5F8.info->pilot != 0xFF)
                    func_080BDDE4(D_0201F5F8.info, &D_02027A10[D_0201F5F8.info->pilot], 0);
                else
                    func_080BDDE4(D_0201F5F8.info, 0, 0);
                func_0808B590(D_0201F5F8.info, 3, D_0201F5F8.obj_18, D_0201F5F8.obj_48, 0);
                func_0808D35C();
                func_0808B868();
                func_0808CB54();
                func_08077E6C(D_02030B48);
                D_02030B48 = func_0807FA0C(D_0201F5F8.info->kind, D_0201F5F8.info->field_1, 1, 5, 0, D_02001CA0);
                if (D_0201F5F8.info->entries[D_0201F5F8.field_8].flags != 0 || D_0201F5F8.info->entries[D_0201F5F8.field_8].id != 0)
                {
                    D_03000060.x = (D_087AD848[D_0201F5F8.info->kind][D_0201F5F8.field_8][0] - 0xD0) << 8;
                    if (D_087AD848[D_0201F5F8.info->kind][D_0201F5F8.field_8][1] < 0x20)
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
                    if (D_02030B4C[i] != 0)
                        func_080771F4(D_02030B4C[i]);
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
            }
        }
        else if (D_0200C4A2 == 2)
        {
            return -1;
        }
        else if (D_0200C4A4 & 0x100)
        {
            for (i = 0; i < 8; i++)
            {
                D_03000060.field_10 += 0xF00;
                func_080C8FCC(1);
            }
            return 0;
        }
    }
}
