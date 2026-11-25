#include "types.h"

void func_080780C0(u8 *, u32, u32, u32, u32, u32);
void func_080784F8(void);
void func_08078540(u32, u32, u32, u32, u32);
void func_080785C0(u32, u32, u32, u32, u32);
/* The quoted symbol keeps the inner and full channel call tails separate. */
void draw_inner_channel(u32, u32, u32, u32, u32) asm("\"func_08078540\"");
void func_08078638(void);
void func_08078660(void);
void func_08078688(u32);

register s32 work1 asm("r1");
register s32 current asm("r0");
register volatile s32 work3 asm("r3");

#define TILE_STEP(amount)                                                                          \
    current = *(u16 *)palette;                                                                     \
    if ((amount) == 1)                                                                             \
        work3++;                                                                                   \
    else                                                                                           \
        work3 += (amount);                                                                         \
    work1 = work3;                                                                                 \
    current |= work1;                                                                              \
    *tiles = current;                                                                              \
    tiles++;

#define TILE_START(value)                                                                          \
    current = *(u16 *)palette;                                                                     \
    work3 = (value);                                                                               \
    work1 = work3;                                                                                 \
    current |= work1;                                                                              \
    *tiles = current;                                                                              \
    tiles++;

void func_0807A1B0(void)
{
    volatile struct {
        u32 index;
        u32 count;
    } local;
    register s32 work2 asm("r2");
    register s32 work4 asm("r4");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer4 asm("r4");
    register u8 *palette asm("r5");
    register u8 *record asm("r6");
    u8 *flags;
    register u32 channel asm("r8");
    register u8 *fill_source asm("r9");
    register u32 channel_mask asm("r10");
    u16 *tiles;
    u8 *flag_address;

    pointer0 = (u8 *)0x0201F5D5;
    current = *pointer0;
    if (current == 0)
        return;
    current = 0;
    local.count = current;
    work2 = 0;
    work1 = 9;
    local.index = work1;
    palette = (u8 *)0x0201F5C8;
    pointer3 = (u8 *)0x0201F5C4;
    asm("" : "+r"(pointer3));
    fill_source = pointer3;
record_loop:
    pointer0 = (u8 *)0x0200C4FC;
    work3 = local.index;
    work1 = work3 << 24;
    work1 >>= 22;
    work1 += (u32)pointer0;
    record = *(u8 **)work1;
    work1 = *(u32 *)record;
    current = 1;
    current &= work1;
    if (current == 0)
        goto check_extra;
    if (work2 != 0)
        goto draw_record;
    current = 2;
    current &= work1;
    if (current != 0)
        goto draw_record;
check_extra:
    current = 8;
    work1 &= current;
    if (work1 == 0)
        goto next_record;
draw_record:
    pointer0 = record + 0x20;
    pointer1 = (u8 *)0x0201F5CA;
    work1 = *pointer1;
    work2 = *(u16 *)(record + 4);
    work3 = *(u16 *)(record + 6);
    func_080780C0(pointer0, work1, work2, work3, ({
                      work4 = *(u16 *)(record + 8);
                      work4;
                  }),
                  ({
                      work4 = *(u16 *)(record + 10);
                      work4;
                  }));
    current = *(u32 *)record;
    work1 = 8;
    current &= work1;
    if (current == 0)
        goto check_effect;
    work1 = *(u16 *)(record + 8);
    current = *(u16 *)(record + 10);
    current *= work1;
    current <<= 1;
    current += 0x20;
    tiles = (u16 *)(record + current);
    current = local.count;
    if (current != 0)
        goto later_row;
    current = record[0x18];
    switch (current) {
    case 0:
        TILE_START(0x38E);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x15);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        pointer1 = fill_source;
        current = *(u32 *)pointer1;
        current += 8;
        asm volatile("" : : "r"(current));
        goto first_fill;
    case 1:
        TILE_START(0x393);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x14);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        current = *(u16 *)palette;
        work3 -= 0x24;
        goto first_last_tile;
    case 2:
        TILE_START(0x39B);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x15);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        pointer1 = fill_source;
        current = *(u32 *)pointer1;
        current += 8;
        goto first_fill;
    case 3:
        TILE_START(0x3A0);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x14);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        current = *(u16 *)palette;
        work3 -= 0x31;
    first_last_tile:
        work1 = work3;
        current |= work1;
        *tiles = current;
        tiles++;
        pointer1 = fill_source;
        current = *(u32 *)pointer1;
        current++;
    first_fill:
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        tiles++;
        pointer3 = fill_source;
        current = *(u32 *)pointer3;
        current++;
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        tiles++;
        current = *(u32 *)pointer3;
        current++;
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        tiles++;
        current = *(u32 *)pointer3;
        current++;
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        current = *(u16 *)palette;
        work3 = 0x374;
        work1 = work3;
        current |= work1;
        tiles[1] = current;
    }
    current = local.count;
    current++;
    current <<= 24;
    current = (u32)current >> 24;
    local.count = current;
    goto draw_extra;
later_row:
    current = record[0x18];
    switch (current) {
    case 0:
        TILE_START(0x35C);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x15);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        pointer1 = fill_source;
        current = *(u32 *)pointer1;
        current += 8;
        asm volatile("" : : "r"(current));
        goto later_fill;
    case 1:
        TILE_START(0x361);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x14);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        current = *(u16 *)palette;
        work3 += 0xE;
        goto later_last_tile;
    case 2:
        TILE_START(0x369);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x15);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        pointer1 = fill_source;
        current = *(u32 *)pointer1;
        current += 8;
        goto later_fill;
    case 3:
        TILE_START(0x36E);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(0x14);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        TILE_STEP(1);
        current = *(u16 *)palette;
        work3++;
    later_last_tile:
        work1 = work3;
        current |= work1;
        *tiles = current;
        tiles++;
        pointer1 = fill_source;
        current = *(u32 *)pointer1;
        current++;
    later_fill:
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        tiles++;
        pointer3 = fill_source;
        current = *(u32 *)pointer3;
        current++;
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        tiles++;
        current = *(u32 *)pointer3;
        current++;
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        tiles++;
        current = *(u32 *)pointer3;
        current++;
        work1 = *(u16 *)palette;
        current |= work1;
        *tiles = current;
        current = *(u16 *)palette;
        work3 = 0x374;
        work1 = work3;
        current |= work1;
        tiles[1] = current;
    }
draw_extra:
    work1 = *(u16 *)(record + 8);
    current = *(u16 *)(record + 10);
    current *= work1;
    current <<= 1;
    current += 0x20;
    pointer0 = record + current;
    pointer1 = (u8 *)0x0201F5CA;
    work1 = *pointer1;
    work3 = record[0x19];
    work2 = *(u16 *)(record + 4);
    work2 += work3;
    work2 = (u16)work2;
    work3 = *(u16 *)(record + 6);
    work3 -= 2;
    work3 <<= 16;
    work3 = (u32)work3 >> 16;
    func_080780C0(pointer0, work1, work2, work3, ({
                      work4 = record[0x1A];
                      work4;
                  }),
                  ({
                      work4 = 3;
                      work4;
                  }));
check_effect:
    work1 = *(u32 *)record;
    current = 0x400;
    current &= work1;
    if (current == 0)
        goto clear_record_flags;
    current = 4;
    current &= work1;
    if (current != 0)
        goto remove_effect;
    current = record[0x1E];
    if (current != 0)
        goto clear_record_flags;
    current = 0x100;
    current &= work1;
    if (current == 0)
        goto check_channel;
    work2 = *(u16 *)(record + 8);
    work2 = (u32)work2 >> 1;
    current = *(u16 *)(record + 4);
    work2 += current;
    current = work2 - 2;
    current <<= 27;
    current = (u32)current >> 24;
    work3 = *(u16 *)(record + 6);
    work1 = *(u16 *)(record + 10);
    work3 += work1;
    work1 = work3 - 5;
    work1 <<= 27;
    work1 = (u32)work1 >> 24;
    work2--;
    work2 <<= 27;
    work2 = (u32)work2 >> 24;
    work3--;
    work3 <<= 27;
    work3 = (u32)work3 >> 24;
    func_08078540(current, work1, work2, work3, ({
                      work4 = 0x3F;
                      work4;
                  }));
    work2 = *(u16 *)(record + 4);
    current = work2 << 27;
    current = (u32)current >> 24;
    work3 = *(u16 *)(record + 6);
    work1 = work3 << 27;
    work1 = (u32)work1 >> 24;
    work4 = *(u16 *)(record + 8);
    work2 += work4;
    work2 <<= 27;
    work2 = (u32)work2 >> 24;
    work4 = *(u16 *)(record + 10);
    work3 += work4;
    work3 <<= 27;
    work3 = (u32)work3 >> 24;
    func_080785C0(current, work1, work2, work3, ({
                      work4 = 0x2F;
                      work4;
                  }));
    func_08078688(0x3F);
    current = 1;
    goto store_channel;
check_channel:
    current = 0x80;
    work1 &= current;
    if (work1 == 0)
        goto full_channel;
    flags = (u8 *)0x0201F5D4;
    work1 = *flags;
    work3 = 1;
    channel_mask = work3;
    current = 1;
    channel = current;
    current &= work1;
    if (current != 0)
        goto second_inner_channel;
    work2 = *(u16 *)(record + 4);
    current = work2 + 1;
    current <<= 27;
    current = (u32)current >> 24;
    work3 = *(u16 *)(record + 6);
    work1 = work3 << 27;
    work1 = (u32)work1 >> 24;
    work4 = *(u16 *)(record + 8);
    work2 += work4;
    work2 <<= 27;
    work2 = (u32)work2 >> 24;
    work4 = *(u16 *)(record + 10);
    work3 += work4;
    work3 <<= 27;
    work3 = (u32)work3 >> 24;
    draw_inner_channel(current, work1, work2, work3, ({
                           work4 = 0x2F;
                           work4;
                       }));
    goto set_channel;
second_inner_channel:
    current = 2;
    channel_mask = current;
    work3 = 2;
    channel = work3;
    current = channel;
    current &= work1;
    if (current != 0)
        goto check_sound;
    work2 = *(u16 *)(record + 4);
    current = work2 + 1;
    current <<= 27;
    goto second_channel_coordinates;
full_channel:
    flags = (u8 *)0x0201F5D4;
    work1 = *flags;
    current = 1;
    channel_mask = current;
    work3 = 1;
    channel = work3;
    current = channel;
    current &= work1;
    if (current != 0)
        goto second_full_channel;
    work2 = *(u16 *)(record + 4);
    current = work2 << 27;
    current = (u32)current >> 24;
    work3 = *(u16 *)(record + 6);
    work1 = work3 << 27;
    work1 = (u32)work1 >> 24;
    work4 = *(u16 *)(record + 8);
    work2 += work4;
    work2 <<= 27;
    work2 = (u32)work2 >> 24;
    work4 = *(u16 *)(record + 10);
    work3 += work4;
    work3 <<= 27;
    work3 = (u32)work3 >> 24;
    func_08078540(current, work1, work2, work3, ({
                      work4 = 0x2F;
                      work4;
                  }));
    goto set_channel;
second_full_channel:
    current = 2;
    channel_mask = current;
    work3 = 2;
    channel = work3;
    current = channel;
    current &= work1;
    if (current != 0)
        goto check_sound;
    work2 = *(u16 *)(record + 4);
    current = work2 << 27;
second_channel_coordinates:
    current = (u32)current >> 24;
    work3 = *(u16 *)(record + 6);
    work1 = work3 << 27;
    work1 = (u32)work1 >> 24;
    work4 = *(u16 *)(record + 8);
    work2 += work4;
    work2 <<= 27;
    work2 = (u32)work2 >> 24;
    work4 = *(u16 *)(record + 10);
    work3 += work4;
    work3 <<= 27;
    work3 = (u32)work3 >> 24;
    func_080785C0(current, work1, work2, work3, ({
                      work4 = 0x2F;
                      work4;
                  }));
set_channel:
    current = *flags;
    work1 = channel_mask;
    current |= work1;
    *flags = current;
    work3 = channel;
    record[0x1E] = work3;
check_sound:
    pointer0 = (u8 *)0x0300569E;
    current = *(u16 *)pointer0;
    if (current != 0)
        goto clear_record_flags;
    func_08078688(0x3F);
    goto clear_record_flags;
remove_effect:
    current = 0x100;
    work1 &= current;
    if (work1 == 0)
        goto remove_channel;
    func_080784F8();
    goto zero_channel;
remove_channel:
    current = record[0x1E];
    if (current != 1)
        goto remove_second_channel;
    func_08078638();
    flag_address = (u8 *)0x0201F5D4;
    work1 = *flag_address;
    current = 0xFE;
    goto clear_channel_bit;
remove_second_channel:
    if (current != 2)
        goto zero_channel;
    func_08078660();
    flag_address = (u8 *)0x0201F5D4;
    work1 = *flag_address;
    current = 0xFD;
clear_channel_bit:
    current &= work1;
    *flag_address = current;
zero_channel:
    current = 0;
store_channel:
    record[0x1E] = current;
clear_record_flags:
    work1 = *(u32 *)record;
    current = -3;
    work1 &= current;
    *(u32 *)record = work1;
    current = 4;
    current &= work1;
    if (current == 0)
        goto record_done;
    current = -2;
    work1 &= current;
    *(u32 *)record = work1;
record_done:
    work2 = 1;
next_record:
    work1 = local.index;
    current = work1 << 24;
    work3 = 0xFF000000;
    current += work3;
    work1 = (u32)current >> 24;
    local.index = work1;
    if (current >= 0)
        goto record_loop;
    work3 = 0;
    local.index = work3;
    pointer0 = (u8 *)0x0201F5D5;
    channel = (u32)pointer0;
    flags = (u8 *)0x0200C524;
    record = (u8 *)0x0200C5A4;
    work4 = 0;
    palette = (u8 *)work4;
finish_loop:
    work1 = local.index;
    work2 = work1 << 24;
    work2 >>= 24;
    work3 = work2 << 2;
    pointer4 = (u8 *)(work3 + (u32)flags);
    pointer3 = (u8 *)(work3 + (u32)record);
    current = *(u32 *)pointer4;
    work1 = *(u32 *)pointer3;
    current ^= work1;
    *(u32 *)pointer4 = current;
    *(u32 *)pointer3 = (u32)palette;
    work2++;
    work2 <<= 24;
    work3 = (u32)work2 >> 24;
    local.index = work3;
    work2 >>= 24;
    if (work2 <= 31)
        goto finish_loop;
    current = 0;
    pointer1 = (u8 *)channel;
    *pointer1 = current;
}
