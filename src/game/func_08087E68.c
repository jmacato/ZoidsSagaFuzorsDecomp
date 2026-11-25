#include "types.h"

struct Obj {
    u8 pad[0x30];
    s32 entry;
};
struct Map {
    u8 pad[0x14];
    u16 width;
    u16 height;
    u8 mode;
    u8 flags;
    u16 entry;
    u8 pad1C[0x14];
    u8 slots[28];
    struct Obj *objects[4];
};
extern struct Map D_020209D8;
extern s16 D_08785D6C[][26][3];
extern s32 D_03000060[2];
extern u32 D_087B4B14[][2];
extern u32 D_087B4B18[][2];
extern u8 D_086372A0[];
extern u8 D_086372AC[];
struct Obj *func_080771BC(const void *, const void *, u32, s32, s32, u32, u32, u32, u32);
void func_080771F4(struct Obj *);
u32 func_0807806C(u32, u32, u16);
void func_08087DD0(struct Obj *);

void func_08087E68(void)
{
    /* Empty asm constraints preserve register lifetimes without emitting instructions. */
    s16 *entry = D_08785D6C[D_020209D8.entry][0];
    volatile u32 index;
    register u32 kind asm("r2");
    register s32 signedKind asm("r1");
    s16 *volatile next;
    register u32 nextIndex asm("r10");
    register struct Map *map asm("r9");
    register s32 *camera asm("r7");
    register s32 *cameraBase asm("r0");
    register struct Map *mapBase asm("r2");
    register struct Map *mapCopy asm("r1");
    register s32 current asm("r0");
    register s32 flags asm("r1");
    register s32 coordinate asm("r4");
    s32 end;
    register s32 cameraX asm("r3");
    register s32 cameraY asm("r2");
    register s32 extentX asm("r2");
    register s32 extentY asm("r3");
    register s32 shifted asm("r1");
    register s32 adjustment asm("r4");
    register s32 tile asm("r4");
    u8 slot;
    register struct Obj **objectSlot asm("r8");
    struct Obj *object;
    register struct Obj *empty asm("r5");
    u8 *slotId;
    struct Obj **objects;
    register u8 *visibleSlots asm("r1");
    register struct Obj **visibleObjects asm("r1");
    register u32 graphic asm("r0");
    register u32 length asm("r2");
    register s16 *next2 asm("r2");
    register s16 *next3 asm("r3");
    register u32 index2 asm("r2");
    register u32 index3 asm("r3");
    register u32 *graphics1 asm("r1");
    register u32 *graphics2 asm("r2");
    register struct Obj **objectBase asm("r4");
    register u32 spawnIndex asm("r1");
    register u32 paletteDestination asm("r1");
    register u32 paletteBase asm("r3");

    current = 0;
    index = current;
    kind = *(u16 *)entry;
    signedKind = entry[0];
    asm("" : : "r"(current));
    goto check;
loop:
    asm("" : "=r"(index3));
    if (kind == 0) {
        current = entry[1];
        asm("" : : "r"(kind), "r"(signedKind), "r"(index3));
        if (current != 0)
            goto nonempty;
        current = entry[2];
        asm("" : "+r"(entry));
        next2 = entry + 3;
        asm("" : "+r"(next2));
        next = next2;
        index3 = index;
        index3++;
        nextIndex = index3;
        if (current == 0)
            goto advance;
    }
nonempty:
    mapBase = &D_020209D8;
    flags = mapBase->flags;
    current = flags & 2;
    asm("" : "+r"(current));
    map = mapBase;
    if (current == 0)
        goto hidden;
    coordinate = entry[1];
    asm("" : : "r"(flags), "r"(mapBase), "r"(index3));
    end = (coordinate + 4) << 11;
    cameraBase = D_03000060;
    cameraX = cameraBase[0];
    asm("" : "+r"(cameraX));
    camera = cameraBase;
    if (end <= cameraX || (coordinate << 11) >= cameraX + 0xF000) {
        mapCopy = map;
        asm("" : "+r"(mapCopy));
        current = mapCopy->width;
        asm("" : "+r"(current));
        extentX = current << 11;
        if (end <= cameraX - extentX)
            goto hidden;
        shifted = coordinate << 11;
        adjustment = 0xFFFF1000;
        asm("" : "+r"(adjustment));
        current = extentX + adjustment;
        if (shifted >= cameraX - current)
            goto hidden;
    }
    asm("" : "=r"(shifted), "=r"(extentX), "=r"(cameraX));
    coordinate = entry[2];
    asm("" : : "r"(shifted), "r"(extentX), "r"(cameraX));
    end = (coordinate + 4) << 11;
    cameraY = camera[1];
    if (end <= cameraY || (coordinate << 11) >= cameraY + 0xA000) {
        mapCopy = map;
        asm("" : "+r"(mapCopy));
        current = mapCopy->height;
        asm("" : "+r"(current));
        extentY = current << 11;
        if (end <= cameraY - extentY)
            goto hidden;
        shifted = coordinate << 11;
        adjustment = 0xFFFF6000;
        asm("" : "+r"(adjustment));
        current = extentY + adjustment;
        if (shifted >= cameraY - current)
            goto hidden;
    }
    visibleSlots = map->slots;
    asm("" : "+r"(visibleSlots));
    index2 = index;
    current = *(u8 *)(index2 + (u32)visibleSlots);
    asm("" : "+r"(entry));
    next3 = entry + 3;
    next = next3;
    index2++;
    nextIndex = index2;
    if (current != 0xFF)
        goto advance;
    slot = 0;
    visibleObjects = (struct Obj **)(visibleSlots + 28);
find_slot:
    objectSlot = visibleObjects + slot;
    empty = *objectSlot;
    if (empty != 0) {
        slot++;
        if (slot <= 3)
            goto find_slot;
        goto advance;
    }
    current = entry[0] << 3;
    graphics1 = (u32 *)D_087B4B14;
    graphic = *(u32 *)(current + (u32)graphics1);
    tile = slot * 16;
    length = 0x200;
    tile += length;
    func_0807806C(graphic, (tile << 5) + 0x06010000, length);
    current = entry[0] << 3;
    graphics2 = (u32 *)D_087B4B18;
    graphic = *(u32 *)(current + (u32)graphics2);
    paletteDestination = (12 - slot) << 5;
    paletteBase = 0x05000200;
    asm("" : "+r"(paletteBase));
    paletteDestination += paletteBase;
    func_0807806C(graphic, paletteDestination, 0x20);
    object = func_080771BC(D_086372A0, D_086372AC, 0, 0, (s32)empty,
                         (u16)tile, ({
                             register u32 palette asm("r0") = (u16)(12 - slot);
                             asm("" : "+r"(palette) : : "r1", "r2", "r3", "r6", "r12");
                             palette;
                         }), 0x13C8, (u32)func_08087DD0);
    objectBase = objectSlot;
    *objectBase = object;
    spawnIndex = index;
    object->entry = spawnIndex;
    {
        /* Volatile lvalue casts prevent address hoisting without allocating volatile locals. */
        register u32 address asm("r0");
        (volatile u32)address = (u32)map;
        (volatile u32)address += 0x30;
        (volatile u32)address = spawnIndex + (volatile u32)address;
        *(u8 *)address = slot;
    }
    goto advance;
hidden:
    {
        register u32 address asm("r0");
        (volatile u32)address = (u32)map;
        (volatile u32)address += 0x30;
        index2 = index;
        slotId = (u8 *)(index2 + (volatile u32)address);
    }
    current = *slotId;
    entry += 3;
    next = entry;
    index2++;
    nextIndex = index2;
    if (current != 0xFF) {
        current = *slotId << 2;
        objects = map->objects;
        func_080771F4(*(struct Obj **)(current + (u32)objects));
        *(struct Obj **)((*slotId << 2) + (u32)objects) = 0;
        *slotId = 0xFF;
    }
advance:
    entry = next;
    index3 = nextIndex;
    asm("" : "+r"(index3));
    current = (u8)index3;
    index = current;
    kind = *(u16 *)entry;
    signedKind = entry[0];
    asm("" : : "r"(current), "r"(index3));
check:
    if (signedKind != -1)
        goto loop;
}
