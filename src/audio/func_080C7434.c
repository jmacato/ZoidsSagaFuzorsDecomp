#include "types.h"

struct WaveData
{
    u16 type;
    u16 status;
    u32 freq;
};

extern const u8 D_0863E02C[];
extern const u32 D_0863E0E0[];

u32 func_080C6818(u32, u32);

u32 func_080C7434(struct WaveData *wav, u8 key, u8 fineAdjust)
{
    u32 val1;
    u32 val2;
    u32 fineAdjustShifted = fineAdjust << 24;

    if (key > 178)
    {
        key = 178;
        fineAdjustShifted = 255 << 24;
    }

    val1 = D_0863E02C[key];
    val1 = D_0863E0E0[val1 & 0xF] >> (val1 >> 4);

    val2 = D_0863E02C[key + 1];
    val2 = D_0863E0E0[val2 & 0xF] >> (val2 >> 4);

    return func_080C6818(wav->freq, val1 + func_080C6818(val2 - val1, fineAdjustShifted));
}
