#include "types.h"

struct Info
{
    u8 id;
};

struct State
{
    u8 pad_0[0x10];
    struct Info *info;
};

struct Save
{
    u8 pad_0[0x1354];
    u8 top;
    u8 field_1355;
    u8 cursor;
};

extern struct State D_0201F5F8;
extern struct Save D_02009480;
extern u8 D_0203124A[];
extern u8 D_0203124F;
extern u8 D_02031250;
extern const u8 *D_087A43E0[];
extern const u8 *D_087A8CF8[];
extern const u8 D_0800122A[];
extern const u8 D_08001239[];
void func_0807BE64(u32);
void func_080BDF60(struct Info *);
void func_0807BEF4(u32, const u8 *, u32);

void func_0808D35C(void)
{
    u8 i;
    u32 hl;

    func_0807BE64(4);
    func_080BDF60(D_0201F5F8.info);
    for (i = 0; i < D_0203124F; i++)
    {
        if (D_0201F5F8.info->id == D_0203124A[i])
        {
            D_02009480.cursor = i;
            if (D_02009480.cursor - D_02009480.top > 3)
                D_02009480.top = D_02009480.field_1355 = D_02009480.cursor - 3;
            break;
        }
    }
    switch (D_02031250)
    {
    case 1:
        for (i = 0; i < D_0203124F; i++)
        {
            if (D_0201F5F8.info->id == D_0203124A[i])
                hl = 1;
            else
                hl = 0;
            func_0807BEF4(4, D_087A43E0[D_0203124A[i]], hl);
        }
        break;
    case 2:
        for (i = 0; i < D_0203124F; i++)
        {
            if (D_0201F5F8.info->id == D_0203124A[i])
                hl = 1;
            else
                hl = 0;
            func_0807BEF4(4, D_087A8CF8[D_0203124A[i] - 0x69], hl);
        }
        break;
    case 3:
        func_0807BEF4(4, D_0800122A, 1);
        func_0807BEF4(4, D_08001239, 0);
        break;
    case 4:
        func_0807BEF4(4, D_0800122A, 0);
        func_0807BEF4(4, D_08001239, 1);
        break;
    }
}
