#include "types.h"

struct Part
{
    u8 flags;
    u8 marks;
    u16 kind;
    s16 field_4;
    s16 field_6;
    s16 field_8;
    s16 field_A;
    s16 field_C;
    s16 field_E;
    s16 field_10;
    s16 field_12;
    s16 field_14;
};

extern u8 D_087353EC[][18];
extern u16 D_08735434[];
extern u16 D_0873543C[];
extern s16 D_08747358[][6];
extern void *D_02030B58[5];
extern struct Part D_08741EF4;
extern u8 D_0203198C[];
extern const u8 D_080011C9[];
extern const u8 D_080F3760[];
extern const u8 D_080F376C[];
extern const u8 D_080F3774[];
extern const u8 D_080F377C[];
extern const u8 D_080F3780[];
extern const u8 D_080F3788[];
extern const u8 D_080F3790[];
extern const u8 D_080F3798[];
extern const u8 D_080F379C[];
extern const u8 D_080F37A8[];
extern const u8 D_080F37B0[];
extern const u8 D_080F37B8[];
extern const u8 D_080F37C0[];
extern const u8 D_080F37C8[];
extern const u8 D_080F37D0[];
extern const u8 D_080F37D8[];
extern const u8 D_080F37E4[];
extern const u8 D_080F37EC[];
extern const u8 D_080F37F4[];
extern const u8 D_080F3804[];
extern const u8 D_080F380C[];
extern const u8 D_080F3818[];
extern const u8 D_080F3820[];
extern const u8 D_080F3828[];
extern const u8 D_080F3838[];
extern const u8 D_080F383C[];
extern const u8 D_080F3844[];
extern const u8 D_080F3848[];
extern const u8 D_080F3854[];
extern const u8 D_080F3860[];
extern const u8 D_080F3868[];
extern const u8 D_080F3874[];
extern const u8 D_080F387C[];
extern const u8 D_080F3884[];
extern const u8 D_080F388C[];
extern const u8 D_080F3650[];
extern const u8 D_080F363C[];
extern const u8 D_080F3648[];
extern const u8 D_080F359C[];
extern const u8 D_080F35A8[];
extern const u8 D_080F35C4[];
extern const u8 D_080F35D0[];
extern const u8 D_080F35EC[];
extern const u8 D_080F35F8[];
extern const u8 D_080F3614[];
extern const u8 D_080F3620[];
void func_0808BB48(void);
void func_0807BD4C(u8);
void func_0807C290(const u8 *);
void func_0807B748(const u8 *, u32, u32, u32, u32);
void func_0807B77C(const u8 *, u32, u32);
void func_0807BA24(s32, u32, u32, u32, u32, u32, u32);
void *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u16, u16, u32, u32);
u8 *func_0808BB74(struct Part *, u8 *);
void func_0807A1A4(void);

void func_0808BCA8(u8 win, struct Part *p, struct Part *cmp, u8 type)
{
    u8 col;
    s16 *e;

    func_0808BB48();
    func_0807BD4C(win);
    if (type == 0)
        func_0807C290(D_080011C9);
    if (p == 0 || p == &D_08741EF4)
    {
        if (type == 0)
            func_0807B748(D_080F3760, 0, win, 9, 1);
        else
            func_0807B748(D_080F376C, 0, win, 3, 5);
        return;
    }
    if (!(p->flags & 1) || p->kind != 0x12)
    {
        func_0807B748(D_080F3774, 0, win, D_087353EC[type][4], D_087353EC[type][5]);
        func_0807BA24(p->field_4, 4, 0, 18, win, D_087353EC[type][4] + 8, D_087353EC[type][5]);
        if ((p->flags & 1) && (p->kind == 16 || p->kind == 17 || p->kind == 19))
            func_0807B77C(D_080F377C, 1, win);
    }
    if (type != 2)
    {
        func_0807B748(D_080F3780, 0, win, D_087353EC[type][6], D_087353EC[type][7]);
        func_0807BA24(p->field_8, 4, 0, 18, win, D_087353EC[type][6] + 8, D_087353EC[type][7]);
    }
    if (!(p->flags & 1))
    {
        func_0807B748(D_080F3788, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
        func_0807B748(D_080F3790, 0, win, D_087353EC[type][2], D_087353EC[type][3]);
        if (cmp == 0 || p->field_C == cmp->field_C)
            col = 0;
        else
            col = p->field_C > cmp->field_C ? 2 : 1;
        func_0807BA24(p->field_C, 4, col, 18, win, D_087353EC[type][0] + 8, D_087353EC[type][1]);
        if (cmp == 0 || p->field_E == cmp->field_E)
            col = 0;
        else
            col = p->field_E > cmp->field_E ? 2 : 1;
        func_0807BA24(p->field_E, 4, col, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
        func_0807B748(D_080F3798, col, win, D_087353EC[type][2] + 12, D_087353EC[type][3]);
        if (p->kind & 1)
            D_02030B58[4] = func_080771BC(D_080F363C, D_080F3648, 0, (D_087353EC[type][16] + 11) * 8, D_087353EC[type][17] * 8, D_08735434[type] + 16, D_0873543C[type], 8, 0);
        if (p->kind & 2)
            func_0807B748(D_080F379C, 1, win, D_087353EC[type][10], D_087353EC[type][11]);
        if (p->kind & 4)
        {
            func_0807B748(D_080F37A8, 1, win, D_087353EC[type][10], D_087353EC[type][11]);
            func_0807BA24(p->field_14, 4, 1, 18, win, D_087353EC[type][10] + 8, D_087353EC[type][11]);
            func_0807B77C(D_080F3798, 1, win);
        }
        if (p->kind & 8)
        {
            func_0807B748(D_080F37B0, 1, win, D_087353EC[type][10], D_087353EC[type][11]);
            func_0807BA24(p->field_14, 4, 1, 18, win, D_087353EC[type][10] + 8, D_087353EC[type][11]);
            func_0807B77C(D_080F3798, 1, win);
        }
        if (p->kind & 0x10)
            func_0807B748(D_080F37B8, 1, win, D_087353EC[type][10], D_087353EC[type][11]);
    }
    else
    {
        switch (p->kind)
        {
        case 1:
            func_0807B748(D_080F37C0, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 2:
            func_0807B748(D_080F37C8, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 3:
            func_0807B748(D_080F37D0, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 4:
            func_0807B748(D_080F37D8, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807B748(D_080F3650, 0, win, D_087353EC[type][2] + 6, D_087353EC[type][3]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 1, D_087353EC[type][3]);
            func_0807BA24(p->field_E, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 5:
            func_0807B748(D_080F37E4, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 6:
            func_0807B748(D_080F37EC, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 7:
            func_0807B748(D_080F37F4, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 1, D_087353EC[type][3]);
            func_0807BA24(p->field_E, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 8:
            func_0807B748(D_080F3804, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 9:
        case 19:
            func_0807B748(D_080F380C, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 10:
            func_0807B748(D_080F3818, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 11:
            func_0807B748(D_080F3820, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 12:
            func_0807B748(D_080F3828, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807B748(D_080F3650, 0, win, D_087353EC[type][2] + 6, D_087353EC[type][3]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 1, D_087353EC[type][3]);
            func_0807BA24(p->field_E, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 13:
            if (p->field_A == 0)
                func_0807B748(D_080F3838, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            else
                func_0807B748(D_080F383C, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 14:
            func_0807B748(D_080F3844, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 15:
            func_0807B748(D_080F3848, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807B748(D_080F3650, 0, win, D_087353EC[type][2] + 6, D_087353EC[type][3]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 1, D_087353EC[type][3]);
            func_0807BA24(p->field_E, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 16:
            func_0807B748(D_080F3854, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 17:
            func_0807B748(D_080F3860, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807BA24(p->field_C, 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            break;
        case 18:
            e = D_08747358[p->field_C];
            func_0807B748(D_080F3868, 0, win, D_087353EC[type][0], D_087353EC[type][1]);
            func_0807B748(D_080F3874, 0, win, D_087353EC[type][2], D_087353EC[type][3]);
            func_0807B748(D_080F387C, 0, win, D_087353EC[type][4], D_087353EC[type][5]);
            func_0807B748(D_080F3884, 0, win, D_087353EC[type][10], D_087353EC[type][11]);
            func_0807B748(D_080F388C, 0, win, D_087353EC[type][12], D_087353EC[type][13]);
            func_0807B748(D_080F3788, 0, win, D_087353EC[type][14], D_087353EC[type][15]);
            func_0807BA24(e[0], 4, 0, 18, win, D_087353EC[type][2] + 8, D_087353EC[type][3]);
            func_0807BA24(e[1], 4, 0, 18, win, D_087353EC[type][4] + 8, D_087353EC[type][5]);
            func_0807BA24(e[2], 4, 0, 18, win, D_087353EC[type][10] + 8, D_087353EC[type][11]);
            func_0807BA24(e[3], 4, 0, 18, win, D_087353EC[type][12] + 8, D_087353EC[type][13]);
            func_0807BA24(e[4], 4, 0, 18, win, D_087353EC[type][14] + 8, D_087353EC[type][15]);
            func_0807B748(D_080F3798, 0, win, D_087353EC[type][2] + 12, D_087353EC[type][3]);
            func_0807B748(D_080F3798, 0, win, D_087353EC[type][4] + 12, D_087353EC[type][5]);
            func_0807B748(D_080F3798, 0, win, D_087353EC[type][10] + 12, D_087353EC[type][11]);
            func_0807B748(D_080F3798, 0, win, D_087353EC[type][12] + 12, D_087353EC[type][13]);
            func_0807B748(D_080F3798, 0, win, D_087353EC[type][14] + 12, D_087353EC[type][15]);
            break;
        }
    }
    func_0807B748(func_0808BB74(p, D_0203198C), 2, win, D_087353EC[type][8], D_087353EC[type][9]);
    if (p->marks & 1)
        D_02030B58[0] = func_080771BC(D_080F359C, D_080F35A8, 0, D_087353EC[type][16] * 8, D_087353EC[type][17] * 8, D_08735434[type], D_0873543C[type], 8, 0);
    if (p->marks & 2)
        D_02030B58[1] = func_080771BC(D_080F35C4, D_080F35D0, 0, (D_087353EC[type][16] + 2) * 8, D_087353EC[type][17] * 8, D_08735434[type] + 4, D_0873543C[type], 8, 0);
    if (p->marks & 4)
        D_02030B58[2] = func_080771BC(D_080F35EC, D_080F35F8, 0, (D_087353EC[type][16] + 4) * 8, D_087353EC[type][17] * 8, D_08735434[type] + 8, D_0873543C[type], 8, 0);
    if (p->marks & 8)
        D_02030B58[3] = func_080771BC(D_080F3614, D_080F3620, 0, (D_087353EC[type][16] + 6) * 8, D_087353EC[type][17] * 8, D_08735434[type] + 12, D_0873543C[type], 8, 0);
    func_0807A1A4();
}
