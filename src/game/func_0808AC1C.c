#include "types.h"

struct Zoid
{
    u8 id;
    u8 pad_1;
    u8 pilot;
    u8 pad_3;
    u16 flags;
    u8 pad_6[0x8E];
};

struct ZoidInfo
{
    u8 pad_0[2];
    u8 type;
    u8 pad_3[0x31];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Save
{
    u8 pad_0[0x6BC4];
    struct Pilot pilots[58];
};

extern u8 D_02030C25;
extern u8 D_02030B6C[];
extern struct Zoid D_02020E88[];
extern struct ZoidInfo D_0873FCC8[];
extern struct Save D_02020E4C;
extern u8 *D_087A43E0[];
void func_0807BE64(u8);
void func_0807BEF4(u8, u8 *, u8);

void func_0808AC1C(u8 id, u32 mask)
{
    u8 i;
    u32 state;
    struct Zoid *z;
    func_0807BE64(id);
    for (i = 0; i < D_02030C25; i++)
    {
        z = &D_02020E88[D_02030B6C[i]];
        if (((mask & 1) && z->pilot == 0)
            || ((mask & 2) && (z->flags & 2))
            || ((mask & 4) && (z->flags & 1))
            || ((mask & 8) && (z->flags & 4))
            || ((mask & 0x10) && (z->flags & 8))
            || ((mask & 0x20) && D_0873FCC8[z->id].type == 0)
            || ((mask & 0x40) && D_0873FCC8[z->id].type == 1)
            || ((mask & 0x80) && D_0873FCC8[z->id].type == 2)
            || ((mask & 0x100) && D_0873FCC8[z->id].type == 3)
            || ((mask & 0x200) && D_0873FCC8[z->id].type == 4)
            || ((mask & 0x400) && z->pilot != 0 && z->pilot != 0xFF && D_02020E4C.pilots[z->pilot].id == 1)
            || ((mask & 0x800) && z->pilot == 0xFF))
            state = 4;
        else
            state = z->flags & 1;
        func_0807BEF4(id, D_087A43E0[z->id], state);
    }
}
