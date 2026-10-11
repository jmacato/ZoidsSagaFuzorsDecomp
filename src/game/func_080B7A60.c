#include "types.h"

struct Item
{
    u8 id;
    u8 qty;
    u8 pad_2[2];
};

struct Entry
{
    struct Item items[2];
    u32 money;
    u8 kind;
    u8 arg;
    u8 pad_E[2];
};

void func_0807B77C(const void *, u8, u8);
void func_080C8F78(void *, const void *);
u32 func_0807C100(const void *);
void func_0807DB94(void *, const void *);
void func_0807B830(u8, u8, u8, void *);
void func_0807B748(const void *, u8, u8, s32, s16);
void func_0807BA24(u32, u8, u8, u8, u8, u8, u8);
void func_0807A1A4(void);
void *memcpy(void *, const void *, u32);

extern u8 D_0203198C[];
extern u8 D_020319CC[];
extern const u8 *const D_087A43E0[];
extern const u8 *const D_087A4890[];
extern const u8 *const D_087A554C[];
extern const u8 *const D_087A559C[];
extern const u8 *const D_087A58C4[];
extern const u8 D_080071F0[];
extern const u8 D_080F5AEC[];
extern const u8 D_080F5AF0[];
extern const u8 D_080F5AF4[];
extern const u8 D_080F5AFC[];
extern const u8 D_080F5B08[];
extern const u8 D_080F5B14[];
extern const u8 D_080F5B24[];

static inline void PutCode(u8 *p, s32 code)
{
    *(u16 *)p = code;
}

void func_080B7A60(u8 win, const struct Entry *e, u8 mode)
{
    u8 row;
    u8 i;
    u8 j;
    u8 pad;

    if (mode == 0)
        func_0807B77C(D_080071F0, 0, win);
    row = 0;
    for (i = 0; i < 2; i++)
    {
        if (e->items[i].id != 0)
        {
            func_080C8F78(D_0203198C, D_087A43E0[e->items[i].id]);
            pad = 13 - func_0807C100(D_087A43E0[e->items[i].id]);
            for (j = 0; j < pad; j++)
                func_0807DB94(D_0203198C, D_080F5AEC);
            func_0807DB94(D_0203198C, D_080F5AF0);
            func_0807B830(e->items[i].qty, 2, 0x12, D_020319CC);
            func_0807DB94(D_0203198C, D_020319CC);
            func_0807B748(D_0203198C, 0, win, 1, (mode * 2 + 2) * row + 6);
            row++;
        }
    }
    func_0807BA24(e->money, 9, 0, 0x12, win, 8, mode == 0 ? 0xB : 0xF);
    if (e->kind != 0)
    {
        switch (e->kind)
        {
        case 1:
            memcpy(D_0203198C, D_080F5AF4, 5);
            PutCode(D_0203198C + 4, 0x201);
            func_080C8F78(D_0203198C + 6, D_087A4890[e->arg]);
            break;
        case 2:
            memcpy(D_0203198C, D_080F5AFC, 9);
            PutCode(D_0203198C + 8, 0x201);
            func_080C8F78(D_0203198C + 10, D_087A554C[e->arg]);
            break;
        case 3:
            memcpy(D_0203198C, D_080F5B08, 11);
            PutCode(D_0203198C + 10, 0x201);
            func_080C8F78(D_0203198C + 12, D_087A43E0[e->arg]);
            break;
        case 4:
            memcpy(D_0203198C, D_080F5B14, 15);
            PutCode(D_0203198C + 14, 0x201);
            func_080C8F78(D_0203198C + 16, D_087A559C[e->arg]);
            break;
        case 5:
            memcpy(D_0203198C, D_080F5B24, 11);
            PutCode(D_0203198C + 10, 0x201);
            func_080C8F78(D_0203198C + 12, D_087A58C4[e->arg]);
            break;
        }
        func_0807B748(D_0203198C, 0, win, 0x12 - (u8)func_0807C100(D_0203198C), mode == 0 ? 0xC : 0x10);
    }
    func_0807A1A4();
}
