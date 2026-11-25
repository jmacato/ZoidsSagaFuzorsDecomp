#include "types.h"

struct Entry
{
    u16 field_0;
    u16 id;
};

struct Unit
{
    u8 pad_0[0x74];
    struct Entry entries[8];
};

struct Big
{
    u8 pad_0[0x24C];
    struct Unit *unit;
    u8 pad_250[0x4F85 - 0x250];
    u8 field_4F85[3];
};

extern struct Big D_02031A0C;
extern char *D_087A4890[];
extern const u8 D_0800562D[];
extern const u8 D_08005646[];
extern const u8 D_0800565F[];
void func_0807C290(const u8 *);
s32 func_080C269C(u8, u8, u8 *);
void func_0807B77C(char *, u32, u8);

void func_0809555C(void)
{
    u8 i;
    u8 slot;
    s32 r;

    for (i = 0; i < 3; i++)
    {
        if (D_02031A0C.field_4F85[i] != 0xFF)
        {
            switch (i)
            {
            case 0:
                func_0807C290(D_0800562D);
                break;
            case 1:
                func_0807C290(D_08005646);
                break;
            case 2:
                func_0807C290(D_0800565F);
                break;
            }
            slot = D_02031A0C.field_4F85[i] & 7;
            r = func_080C269C(i, slot, D_02031A0C.field_4F85);
            if (r == 0)
                func_0807B77C(D_087A4890[D_02031A0C.unit->entries[slot].id], 0, i + 5);
            else
                func_0807B77C(D_087A4890[r + 0x32B], 0, i + 5);
        }
    }
}
