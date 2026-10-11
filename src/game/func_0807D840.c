#include "types.h"

struct SaveBlock
{
    u8 *data;
    u32 size;
};

extern const struct SaveBlock D_08734614[];
extern const u8 D_08734610[];
extern u8 D_02001480[];
extern void (*D_030076F0)(const u8 *, u8 *, u32);
extern u32 (*D_030076F4)(const u8 *, u8 *, u32);

s32 func_080C8F1C(const u8 *, const u8 *);
u32 func_080C8B34(const u8 *, u8 *, u32);
u16 func_0807D7F4(const u8 *, u32);

s32 func_0807D840(u8 mode, u8 index)
{
    u8 *sram = (u8 *)0x0E000000;
    const struct SaveBlock *block = D_08734614;
    u32 i;
    u32 size;
    u8 tries;
    u16 crc;
    s32 result;

    for (i = 0; i < index; i++)
    {
        if (block->data == 0 && block->size == 0)
            return 2;
        sram += block->size + 5;
        block++;
    }
    size = block->size;
    tries = 0;
    while (1)
    {
        D_030076F0(sram, D_02001480, 3);
        if (D_030076F4(D_02001480, sram, 3) == 0)
            break;
        tries++;
        if (tries == 3)
            goto fail;
    }
    result = func_080C8F1C(D_02001480, D_08734610);
    if (result != 0)
    {
        switch (mode)
        {
        case 1:
            return 2;
        case 0:
            result = func_080C8B34(D_08734610, sram, 3);
            if (result == 0)
                break;
        case 2:
        fail:
            return 0;
        }
    }
    sram += 3;
    switch (mode)
    {
    case 0:
        for (i = 0; i < size; i++)
            D_02001480[i] = block->data[i];
        crc = func_0807D7F4(D_02001480, size);
        D_02001480[size] = crc;
        *(D_02001480 + size + 1) = crc >> 8;
        if (func_080C8B34(D_02001480, sram, size + 2) != 0)
            goto fail;
        goto ok;
    case 1:
    case 2:
        tries = 0;
        while (1)
        {
            D_030076F0(sram, D_02001480, size + 2);
            if (D_030076F4(D_02001480, sram, size + 2) == 0)
                break;
            tries++;
            if (tries == 3)
                goto fail;
        }
        crc = func_0807D7F4(D_02001480, size);
        if (((*(D_02001480 + size + 1) << 8) | D_02001480[size]) == crc)
        {
            if (mode == 1)
            {
                for (i = 0; i < size; i++)
                    block->data[i] = D_02001480[i];
            }
        ok:
            return 1;
        }
        if (mode != 1)
        {
            result = 0;
            goto fail;
        }
        return 2;
    }
}
