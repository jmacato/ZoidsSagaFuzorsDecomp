#include "types.h"

struct Actor {
    u8 pad[3];
    u8 state;
    s32 x;
    s32 y;
};
struct Map {
    u8 pad[0x14];
    u16 width;
    u16 height;
    u8 mode;
};
extern s32 D_03000060[4];
extern struct Map D_020209D8;
extern s32 D_02031A0C[2];
s32 func_080C8C80(s32, s32);

void func_08082BB4(struct Actor *arg0)
{
    /* Empty asm preserves agbcc register copies without adding instructions. */
    register struct Actor *actor asm("r2") = arg0;
    register s32 *position asm("r8");
    register struct Map *map asm("r9");
    register s32 *enabled asm("r10");
    s32 *positionBase;
    register struct Map *mapBase asm("r0");
    s32 *enableBase;
    s32 originX;
    register s32 initialX asm("r3");
    register s32 x asm("r5");
    register s32 y asm("r6");
    s32 limit;
    register s32 nextY asm("r4");
    s32 firstWrappedX;
    s32 wrappedX;
    register s32 wrappedY asm("r1");
    register s32 lastY asm("r2");
    s32 extent;
    register s32 current asm("r0");
    register s32 negativeX asm("r1");
    register s32 *positionCopy asm("r2");
    register struct Map *mapCopy1 asm("r1");
    register struct Map *mapCopy2 asm("r2");
    register s32 status asm("r1");
    register u32 yOffset asm("r2");
    register s32 *positionCopy1 asm("r1");
    register s32 *positionCopy0 asm("r0");
    register s32 *controlCopy asm("r1");
    register u32 dimension asm("r0");

    if (actor->state != 0 && actor->state != 6)
        return;
    current = actor->x + 0xFFFF8800U;
    positionBase = D_03000060;
    originX = positionBase[0];
    current -= originX;
    asm("" : "+r"(current));
    position = positionBase;
    if (current < 0)
        current += 7;
    initialX = current >> 3;
    asm("" : "+r"(initialX));
    x = initialX;
    asm("" : "+r"(x));
    current = actor->y;
    yOffset = 0xFFFFB000U;
    asm("" : "+r"(yOffset));
    current += yOffset;
    asm("" : "+r"(current));
    positionCopy = position;
    asm("" : "+r"(positionCopy));
    current -= positionCopy[1];
    if (current < 0)
        current += 7;
    y = current >> 3;
    asm("" : "+r"(y));
    mapBase = &D_020209D8;
    status = mapBase->mode;
    asm("" : "+r"(status));
    map = mapBase;
    if (status == 2) {
        if (x < -0x800) {
            mapCopy1 = map;
            asm("" : "+r"(mapCopy1));
            x += mapCopy1->width << 8;
        } else if (x > 0x800) {
            mapCopy2 = map;
            asm("" : "+r"(mapCopy2));
            x -= mapCopy2->width << 8;
        }
        if (y < -0x800) {
            mapCopy1 = map;
            asm("" : "+r"(mapCopy1));
            y += mapCopy1->height << 8;
        } else if (y > 0x800) {
            mapCopy2 = map;
            asm("" : "+r"(mapCopy2));
            y -= mapCopy2->height << 8;
        }
    } else {
        if (initialX < 0) {
            negativeX = -originX;
            if (negativeX < 0)
                negativeX += 7;
            limit = negativeX >> 3;
            if (x >= limit)
                goto after_clamp_x;
            goto clamp_x;
        } else if (initialX > 0) {
            mapCopy1 = map;
            asm("" : "+r"(mapCopy1));
            current = ((mapCopy1->width - 30) << 11) - originX;
            if (current < 0)
                current += 7;
            limit = current >> 3;
            if (x > limit) {
clamp_x:
                x = limit;
            }
        }
after_clamp_x:
        if (y < 0) {
            positionCopy = position;
            asm("" : "+r"(positionCopy));
            current = -positionCopy[1];
            if (current < 0)
                current += 7;
            limit = current >> 3;
            if (y >= limit)
                goto after_clamp_y;
            goto clamp_y;
        } else if (y > 0) {
            mapCopy1 = map;
            asm("" : "+r"(mapCopy1));
            current = (mapCopy1->height - 20) << 11;
            positionCopy = position;
            asm("" : "+r"(positionCopy));
            current -= positionCopy[1];
            if (current < 0)
                current += 7;
            limit = current >> 3;
            if (y > limit) {
clamp_y:
                y = limit;
            }
        }
    }
after_clamp_y:
    enableBase = D_02031A0C;
    status = enableBase[0];
    asm("" : "+r"(status));
    enabled = enableBase;
    if (status != 0) {
        positionCopy1 = position;
        asm("" : "+r"(positionCopy1));
        current = positionCopy1[0] + x;
        positionCopy1[0] = current;
        nextY = positionCopy1[1] + y;
        positionCopy1[1] = nextY;
        mapCopy2 = map;
        asm("" : "+r"(mapCopy2));
        firstWrappedX = func_080C8C80(current, mapCopy2->width << 11);
        asm("" : "+r"(firstWrappedX));
        positionCopy0 = position;
        asm("" : "+r"(positionCopy0));
        positionCopy0[0] = firstWrappedX;
        mapCopy2 = map;
        asm("" : "+r"(mapCopy2));
        current = func_080C8C80(nextY, mapCopy2->height << 11);
        positionCopy1 = position;
        asm("" : "+r"(positionCopy1));
        positionCopy1[1] = current;
        if (firstWrappedX < 0) {
            positionCopy = position;
            asm("" : "+r"(positionCopy));
            mapCopy1 = map;
            asm("" : "+r"(mapCopy1));
            dimension = mapCopy1->width;
            asm("" : "+r"(dimension));
            extent = dimension << 11;
            current = firstWrappedX;
            do {
                current += extent;
            } while (current < 0);
            positionCopy[0] = current;
        }
        positionCopy = position;
        asm("" : "+r"(positionCopy));
        wrappedY = positionCopy[1];
        if (wrappedY < 0) {
            mapBase = &D_020209D8;
            asm("" : "+r"(mapBase));
            current = mapBase->height << 11;
            do {
                wrappedY += current;
            } while (wrappedY < 0);
            positionCopy[1] = wrappedY;
        }
    }
    controlCopy = enabled;
    asm("" : "+r"(controlCopy));
    if (controlCopy[1] != 0) {
        positionCopy = position;
        asm("" : "+r"(positionCopy));
        current = positionCopy[2] + x;
        positionCopy[2] = current;
        nextY = positionCopy[3] + y;
        positionCopy[3] = nextY;
        mapCopy2 = map;
        asm("" : "+r"(mapCopy2));
        wrappedX = func_080C8C80(current, mapCopy2->width << 11);
        positionCopy0 = position;
        asm("" : "+r"(positionCopy0));
        positionCopy0[2] = wrappedX;
        mapCopy2 = map;
        asm("" : "+r"(mapCopy2));
        current = func_080C8C80(nextY, mapCopy2->height << 11);
        positionCopy1 = position;
        asm("" : "+r"(positionCopy1));
        positionCopy1[3] = current;
        if (wrappedX < 0) {
            positionCopy = position;
            asm("" : "+r"(positionCopy));
            mapCopy1 = map;
            asm("" : "+r"(mapCopy1));
            dimension = mapCopy1->width;
            asm("" : "+r"(dimension));
            extent = dimension << 11;
            current = wrappedX;
            do {
                current += extent;
            } while (current < 0);
            positionCopy[2] = current;
        }
        positionCopy0 = position;
        asm("" : "+r"(positionCopy0));
        lastY = positionCopy0[3];
        asm("" : "+r"(lastY));
        if (lastY < 0) {
            positionCopy1 = position;
            asm("" : "+r"(positionCopy1));
            mapBase = &D_020209D8;
            asm("" : "+r"(mapBase));
            current = mapBase->height << 11;
            do {
                lastY += current;
            } while (lastY < 0);
            positionCopy1[3] = lastY;
        }
    }
}
