#include "types.h"

struct Camera {
    s32 x;
    s32 y;
    s32 z;
    u16 angleX;
    u16 angleY;
    s16 value;
    u16 pad12;
    s32 originX;
    s32 originY;
    s32 focal;
    u8 pad20[8];
    s32 oldZ;
    u32 oldAngles;
    s16 oldValue;
    u16 pad32;
    s32 oldOriginX;
    s32 oldOriginY;
    s32 oldFocal;
    u8 pad40[0x20];
    s32 distance;
};
struct Projection {
    s32 originX;
    s32 originY;
    s32 focal;
};
struct Matrix {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
};
extern struct Camera D_030025A8;
extern struct Matrix *D_0300260C;
extern u8 D_03002610;
extern u8 D_03002684;
u16 func_08075AF8(s16);
u32 func_08075AAC(s16);
s32 func_080C8B80(s32, s32);

u8 func_08076B98(void)
{
    /* Empty asm constraints preserve register lifetimes without emitting instructions. */
    register struct Camera *initial asm("r0") = &D_030025A8;
    register s32 initialZ asm("r2") = initial->z;
    register s32 oldZ asm("r1") = initial->oldZ;
    register struct Camera *camera asm("r6") = initial;
    register struct Camera *cameraCopy asm("r9");
    struct Projection *projection;
    struct Matrix *matrix;
    register u32 cosineX asm("r10");
    register u32 sineX asm("r4");
    volatile u32 cosineY;
    volatile u32 sineY;
    volatile s32 numerator;
    volatile s32 distance;
    register s32 row asm("r8");
    register s32 denominator asm("r1");
    register s32 quotient asm("r2");
    s32 result;
    volatile s32 signedSine;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work6 asm("r6");
    register struct Camera *camera3 asm("r3");

    asm("" : "+r"(camera));
    if (initialZ != oldZ || *(u32 *)&camera->angleX != camera->oldAngles
        || camera->value != camera->oldValue || camera->originX != camera->oldOriginX
        || camera->originY != camera->oldOriginY || camera->focal != camera->oldFocal)
        D_03002684 = 0;
    else if (D_03002684 <= 1)
        D_03002684++;
    cosineX = func_08075AF8((s16)-camera->angleX);
    sineX = func_08075AAC((s16)-camera->angleX);
    asm("" : "+r"(sineX));
    sineX = (u16)sineX;
    cosineY = func_08075AF8((s16)-camera->angleY);
    sineY = (u16)func_08075AAC((s16)-camera->angleY);
    matrix = D_0300260C + (D_03002610 ^ 1) * 160;
    cameraCopy = camera;
    asm("" : "+r"(cameraCopy));
    projection = (struct Projection *)&cameraCopy->originX;
    asm("" : "+r"(projection));
    {
        register struct Camera *distanceBase asm("r3") = cameraCopy;
        asm("" : "+r"(distanceBase));
        work3 = distanceBase->distance;
        distance = work3;
    }
    sineX <<= 16;
    asm("" : "+r"(sineX));
    work1 = (s32)sineX >> 16;
    current = projection->focal;
    asm("" : "+r"(current));
    work2 = current;
    asm("" : "+r"(work2));
    work2 *= work1;
    current = camera->z / 256;
    asm("" : "+r"(current));
    work1 = current;
    asm("" : "+r"(work1));
    work1 *= work2;
    numerator = work1;
    work2 = 0;
    asm("" : "+r"(work2));
    row = work2;
    work3 = cosineX;
    asm("" : "+r"(work3));
    work3 <<= 16;
    cosineX = work3;
    do {
        asm("" : "+r"(sineX));
        if (D_03002684 == 2) {
            denominator = ((s32)sineX >> 16);
            if (denominator == 0)
                goto clear;
            current = projection->originY;
            work6 = row;
            asm("" : "+r"(work6));
            current = (work6 - current) << 8;
            goto translate;
        } else {
            current = (s32)sineX >> 16;
            signedSine = current;
            work3 = projection->focal;
            work2 = work3;
            asm("" : "+r"(work2));
            work2 *= current;
            current = projection->originY;
            work1 = row;
            asm("" : "+r"(work1));
            current -= work1;
            work6 = cosineX;
            asm("" : "+r"(work6));
            work1 = work6 >> 16;
            current *= work1;
            current = work2 + current;
            current /= 256;
            asm("" : "+r"(current));
            work1 = current;
            asm("" : "+r"(work1));
            work1 *= work3;
            denominator = work1;
            if (denominator == 0)
                goto clear;
            quotient = func_080C8B80(numerator, denominator);
            asm("" : "+r"(quotient));
            work1 = cosineY;
            current = (s16)work1;
            current *= quotient;
            current /= 256;
            matrix->pd = current;
            matrix->pa = current;
            work3 = sineY;
            current = (s16)work3;
            current *= quotient;
            current /= 256;
            matrix->pb = current;
            matrix->pc = -current;
            current = projection->originY;
            work6 = row;
            asm("" : "+r"(work6));
            current = (work6 - current) << 8;
            denominator = signedSine;
        }
translate:
        quotient = func_080C8B80(current, denominator);
        asm("" : "+r"(quotient));
        current = -projection->originX;
        work1 = matrix->pa;
        work1 *= current;
        asm("" : "+r"(work1));
        current = matrix->pb;
        current *= quotient;
        work1 -= current;
        camera3 = cameraCopy;
        asm("" : "+r"(camera3));
        current = camera3->x;
        work1 += current;
        matrix->dx = work1;
        current = -projection->originX;
        work1 = matrix->pc;
        work1 *= current;
        asm("" : "+r"(work1) : "r"(camera3));
        current = matrix->pd;
        current *= quotient;
        work1 -= current;
        camera = cameraCopy;
        asm("" : "+r"(camera));
        current = camera->y;
        work1 += current;
        matrix->dy = work1;
        goto advance;
clear:
        matrix->dy = denominator;
        matrix->dx = denominator;
        *(s32 *)&matrix->pc = denominator;
        *(s32 *)&matrix->pa = denominator;
advance:
        matrix++;
        current = 1;
        asm("" : "+r"(current));
        row += current;
        work1 = row;
        asm("" : "+r"(work1));
    } while (work1 <= 159);
    asm("" : "+r"(sineX));
    work3 = cosineX;
    asm("" : "+r"(work3));
    work2 = work3 >> 16;
    if (work2 != 0) {
        camera = cameraCopy;
        asm("" : "+r"(camera));
        current = camera->z;
        work1 = distance;
        current = work1 - current;
        work1 = (s32)sineX >> 16;
        current *= work1;
        current /= 256;
        work1 = current;
        asm("" : "+r"(work1));
        current = projection->focal;
        sineX = work1;
        asm("" : "+r"(sineX));
        sineX *= current;
        work3 = distance;
        current = work2;
        asm("" : "+r"(current));
        current *= work3;
        current /= 256;
        work1 = current;
        current = sineX;
        result = func_080C8B80(current, work1) + projection->originY;
        if ((u32)result <= 159)
            return result;
    }
    return 0xFF;
}
