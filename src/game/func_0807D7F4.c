#include "types.h"

u16 func_0807D7F4(const u8 *data, u32 len)
{
    u32 crc = 0xFFFF;
    u32 i, j;

    for (i = 0; i < len; i++)
    {
        crc ^= *data;
        for (j = 0, data++; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc >>= 1;
        }
    }
    return ~crc;
}
