#include "types.h"

struct Save
{
    u8 pad_0[0x7B4D];
    u8 field_7B4D;
    u16 field_7B4E;
    u16 field_7B50;
    u16 field_7B52;
};

struct Sprite
{
    u8 pad_0[0xE];
    s16 field_E;
};

struct Script
{
    u8 pad_0[0x12EC];
    struct Sprite *sprite;
};

struct TableEntry
{
    const u8 *data;
    u32 field_4;
};

extern struct Save D_02020E4C;
extern u16 D_020209D8;
extern struct Script D_0201F6DC;
extern const struct TableEntry D_087B4B8C[];
extern const u8 D_087B4C14[];
void func_0807FF9C(const struct TableEntry *, u8, u16, u16);
struct Sprite *func_08077180(const u8 *, u8, u8, s16, s16, u16, u8, u32, u8);

void func_080872F4(void)
{
    if (D_02020E4C.field_7B4E == D_020209D8)
    {
        func_0807FF9C(D_087B4B8C, D_02020E4C.field_7B4D + 8, 0x398, 10);
        D_0201F6DC.sprite = func_08077180(D_087B4C14, 9, 4, D_02020E4C.field_7B50 << 3, D_02020E4C.field_7B52 << 3, 0x398, 10, 0x412C8, 0);
        D_0201F6DC.sprite->field_E = -8;
    }
    else
        D_0201F6DC.sprite = 0;
}
