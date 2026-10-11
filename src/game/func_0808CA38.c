#include "types.h"

struct Entry
{
    u16 flags;
    u16 id;
};

struct Info
{
    u8 pad_0[0x74];
    struct Entry entries[8];
};

struct Pair
{
    void *a;
    void *b;
};

struct State
{
    u8 pad_0[0x10];
    struct Info *info;
    u8 pad_14[0x50];
    struct Pair pairs[4];
};

extern struct State D_0201F5F8;
extern const u8 D_08735360[];
extern const u8 D_087353B0[];
extern const u16 D_087353A0[];
extern const u16 D_087353C0[];
void func_0808C9F8(void);
void *func_08077180(const u8 *, u32, u32, s16, u32, u32, u32, u32, u32);

void func_0808CA38(u8 start, u8 y, u8 x, u8 pal)
{
    u8 i;
    u8 k;
    u8 kind;

    func_0808C9F8();
    for (i = 0; i < 4; i++)
    {
        k = i + start;
        if (k == 8)
            break;
        D_0201F5F8.pairs[i].a = func_08077180(D_08735360, k, 0, y * 8 - 2, (x + i * 2) * 8, D_087353A0[k], 0xF, (pal << 6) | 0x5008, 0);
        if (k < 4)
        {
            switch (D_0201F5F8.info->entries[k].flags & 3)
            {
            case 3:
                kind = 0;
                break;
            case 2:
                kind = 1;
                break;
            }
            D_0201F5F8.pairs[i].b = func_08077180(D_087353B0, kind, 0, y * 8 - 2, (x + i * 2 + 1) * 8, D_087353C0[kind], 0xF, (pal << 6) | 0x5008, 0);
        }
    }
}
