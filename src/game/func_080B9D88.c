#include "types.h"

struct Entry
{
    u8 id;
    u8 field_1;
    u8 items[4];
    u8 pad_6[10];
};

struct Save
{
    u8 pad_0[0x28];
    u8 flags[32];
};

void func_0807C290(const void *);
void func_0808A7F8(u8, u8, u8, u8);
void func_0807BEF4(u8, const void *, u8);
void func_0807BD4C(u8);
void func_0807B748(const void *, s8, u8, s16, s32);
void func_0808A86C(u8);

extern const struct Entry D_08741CE4[];
extern struct Save D_02030504;
extern const u8 *const D_087A43E0[];
extern const u8 D_080F5B80[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern const u8 D_080076FE[];
extern const u8 D_08007724[];
extern const u8 D_08007728[];

void func_080B9D88(void)
{
    u8 i;
    u8 j;
    u8 k;
    u8 m;
    const struct Entry *f;
    const struct Entry *e;

    func_0807C290(D_080076FE);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    i = 0;
    e = &D_08741CE4[i];
    while (e->id != 0)
    {
        if (D_02030504.flags[i] & 0x80)
        {
            func_0807BEF4(2, D_087A43E0[e->id], 0);
        }
        else
        {
            j = 2;
            for (k = 0; k < 4 && e->items[k] != 0; k++)
            {
                if (!((D_02030504.flags[i] >> k) & 1))
                {
                    j = 0;
                    break;
                }
            }
            func_0807BEF4(2, D_080F5B80, j);
        }
        i++;
        e = &D_08741CE4[i];
    }
    m = 0;
    do
    {
        func_0807BD4C(3);
        f = &D_08741CE4[m];
        for (i = 0; i < 4 && f->items[i] != 0; i++)
        {
            if ((D_02030504.flags[m] >> i) & 1)
                func_0807B748(D_087A43E0[f->items[i]], 0, 3, 0, i * 2);
            else
                func_0807B748(D_080F5B80, 0, 3, 0, i * 2);
        }
        func_0807C290(D_08007724);
        m = D_0200C4A0;
    } while (D_0200C4A2 != 2);
    func_0807C290(D_08007728);
    func_0808A86C(0);
}
