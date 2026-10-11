#include "types.h"

struct Unit
{
    u8 zoid;
    u8 parts[7];
    u8 pad_8[0x100];
};

struct Zoid
{
    u8 data[0x94];
};

struct Part
{
    u8 data[0x40];
};

struct Game
{
    u8 pad_0[0x244];
    u8 field_244;
    u8 field_245;
    u8 field_246;
    u8 pad_247[0x11];
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
    struct Part parts[2][7];
};

extern struct Game D_02031A0C;

struct Part *func_0809A954(u8 side, u8 slot, u8 k)
{
    return &D_02031A0C.parts[side][D_02031A0C.units[side][slot].parts[k]];
}
