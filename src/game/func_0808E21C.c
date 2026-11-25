#include "types.h"

struct Pilot
{
    u8 pad_0[0x2E];
    u8 zoid;
    u8 pad_2F[0x10];
    u8 field_3F;
};

struct Zoid
{
    u8 data[0x94];
};

struct Units
{
    struct Zoid zoids[186];
    struct Pilot pilots[58];
};

struct State
{
    u8 pad_0[4];
    u8 field_4;
    u8 pad_5[4];
    u8 field_9;
    u8 field_A;
    u8 pad_B[2];
    u8 field_D;
    u8 pad_E[6];
    struct Pilot *info;
    u8 pad_18[0x34];
    u32 *obj;
};

struct Camera
{
    u8 pad_0[0x10];
    s32 y;
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern struct Units D_02020E88;
extern u8 D_02030C26[];
extern u32 D_0200C4AC;
extern u8 D_0203116C[][2];
extern u8 D_020311DB[][2];
extern u8 D_02031249;
extern u8 D_0200C4DC[2];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const s16 D_08759AD8[][2];
extern const u8 *D_087A5BC4[];
extern const u8 D_08759BB8[];
extern const u8 D_0800184F[];
extern const u8 D_0800184B[];
extern const u8 D_08001868[];
extern const u8 D_08001882[];
extern const u8 D_08001886[];
extern const u8 D_08001889[];
extern const u8 D_080018BF[];
extern const u8 D_080018E5[];
extern const u8 D_0800191B[];
extern const u8 D_0800196A[];
extern const u8 D_080019BE[];
extern const u8 D_080019F1[];
void func_0807C290(const u8 *);
void func_0807BD4C(u8);
void func_0807B77C(const u8 *, u32, u32);
void func_080C8FCC(u32);
void func_0808E1B0(void);
void func_0808A72C(struct Pilot *, u32);
void func_0808A890(u32);
void func_0808A8B4(u32);
void func_080785C0(u8, u8, u8, u8, u8);
void func_08078688(u8);
void func_0808B1F0(u8, u8);
u8 func_080BF9B4(struct Pilot *, u8);
void func_080BFA34(struct Pilot *, u8, u8);
void func_080BDDE4(struct Zoid *, struct Pilot *, u8);
void func_08075F20(u32);
void func_080784F8(void);

s32 func_0808E21C(void)
{
    u32 state;
    u8 i;
    u8 sel;

    func_0807C290(D_0800184F);
    state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
            while (1)
            {
                func_0807BD4C(3);
                D_0200C4AC = D_08759AD8[D_0203116C[D_0201F5F8.field_D][0]][0] * D_0203116C[D_0201F5F8.field_D][1];
                func_0807B77C(D_087A5BC4[D_0203116C[D_0201F5F8.field_D][0]], 0, 3);
                func_0807C290(D_0800184B);
                D_0201F5F8.field_D = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    state = 0x1000;
                    break;
                }
                if (D_0200C4A2 == 2)
                    return -1;
                if (D_0200C4A4 & 0x200)
                {
                    for (i = 0; i < 8; i++)
                    {
                        D_03000060.y -= 0xF00;
                        func_080C8FCC(1);
                    }
                    return 0;
                }
                if (D_0200C4A4 & 0x100)
                {
                    D_0201F5F8.field_9 = D_0201F5F8.info->field_3F;
                    if (D_0201F5F8.field_9 <= 5)
                        D_0201F5F8.field_A = 0;
                    else
                        D_0201F5F8.field_A = D_0201F5F8.field_9 - 5;
                    func_0808E1B0();
                    for (i = 0; i < 8; i++)
                    {
                        D_03000060.y += 0xF00;
                        func_080C8FCC(1);
                    }
                    return 1;
                }
            }
            break;
        case 0x1000:
            func_0808A72C(D_0201F5F8.info, 1);
            if (D_02031249 != 0)
            {
            *D_0201F5F8.obj |= 0x20000;
            func_0808A890(1);
            func_0808A890(2);
            func_080785C0(0x78, 0, 0xF0, 0x70, 0x3D);
            func_08078688(0x3F);
            func_0807C290(D_08001868);
            func_0808B1F0(5, 1);
            sel = 0;
            while (1)
            {
                func_0807BD4C(3);
                D_0200C4AC = D_08759AD8[D_020311DB[sel][0]][0];
                func_0807B77C(D_087A5BC4[D_020311DB[sel][0]], 0, 3);
                func_0807C290(D_08001882);
                sel = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    D_0200C4DC[0] = D_020311DB[sel][0];
                    i = func_080BF9B4(&D_02020E88.pilots[D_02030C26[D_0201F5F8.field_4]], D_020311DB[sel][0]);
                    if (i == 5)
                    {
                        D_0200C4DC[1] = D_0203116C[D_0201F5F8.field_D][0];
                        if (D_0203116C[D_0201F5F8.field_D][0] == 0)
                        {
                            func_0807C290(D_080018BF);
                        }
                        else
                        {
                            for (i = 0; i < 10; i++)
                                if (D_0203116C[D_0201F5F8.field_D][0] == D_08759BB8[i])
                                    break;
                            if (i == 10)
                            {
                                func_0807C290(D_080018E5);
                            }
                            else
                            {
                                func_08075F20(0x114);
                                func_0807C290(D_080019F1);
                                continue;
                            }
                        }
                    }
                    else
                    {
                        D_0200C4DC[1] = D_0203116C[i][0];
                        if (D_0203116C[i][0] == D_020311DB[sel][0])
                        {
                            if (D_0203116C[i][1] < D_08759AD8[D_0203116C[i][0]][1])
                            {
                                func_0807C290(D_0800191B);
                            }
                            else
                            {
                                func_08075F20(0x114);
                                func_0807C290(D_080019BE);
                                continue;
                            }
                        }
                        else
                        {
                            func_0807C290(D_0800196A);
                        }
                    }
                    if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                    {
                        func_080BFA34(&D_02020E88.pilots[D_02030C26[D_0201F5F8.field_4]], D_0201F5F8.field_D, D_020311DB[sel][0]);
                        if (D_0201F5F8.info->zoid != 0)
                            func_080BDDE4(&D_02020E88.zoids[D_0201F5F8.info->zoid], D_0201F5F8.info, 0);
                        func_0808A72C(D_0201F5F8.info, 0);
                        func_0808B1F0(0, 0);
                        break;
                    }
                }
                else if (D_0200C4A2 == 2)
                {
                    break;
                }
            }
            state = 0;
            func_080784F8();
            *D_0201F5F8.obj &= ~0x20000;
            func_0808A8B4(1);
            func_0808A8B4(2);
            func_0807C290(D_08001886);
            }
            else
            {
                func_08075F20(0x114);
                func_0807C290(D_08001889);
                state = 0;
            }
            break;
        }
    }
}
