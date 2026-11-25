#include "types.h"

extern u8 D_02036E7C[];
extern u8 D_020377E0[];
extern u8 D_020378E0;
extern s32 D_03000060[];

void func_080A1E6C(void)
{
    /* Empty asm constraints preserve register lifetimes without emitting instructions. */
    register u8 *base asm("r12");
    register u8 *lowBase asm("r0") = D_02036E7C;
    register u32 modeOffset asm("r1") = 0x8C6;
    register u8 *mode asm("r3") = (u8 *)((u32)lowBase + modeOffset);
    register s32 state asm("r2") = *mode;
    register s16 *position asm("r4");
    register s16 *firstPosition asm("r2");
    register s16 *lastPosition asm("r1");
    register s16 *phase asm("r2");
    register s16 *wavePosition asm("r6");
    register s16 *wavePhase asm("r5");
    register s32 index asm("r3");
    register u8 *pixel asm("r1");
    register u32 value asm("r2");
    register u8 *buffer asm("r6");
    register u8 *selectorAddress asm("r5");
    register u32 one asm("r8");
    register u32 firstOne asm("r7");
    register u32 lastOne asm("r4");
    register s32 current asm("r0");
    register u8 *waveSelector asm("r8");
    register u8 *waveBuffer asm("r7");
    register u8 *wavePixel asm("r2");
    register u32 waveValue asm("r4");
    register s16 *phaseAddress asm("r0");
    register s32 row asm("r1");
    register u32 oneCopy asm("r1");
    register u32 firstValue asm("r1");
    register u32 lastValue asm("r2");
    asm("" : "+r"(state));
    base = lowBase;

    switch (state) {
    case 1:
        firstPosition = (s16 *)(base + 0x8C8);
        firstValue = *(u16 *)firstPosition;
        current = *firstPosition;
        if (current <= 0x3F) {
            current = firstValue + 1;
            *firstPosition = current;
            index = 0;
            firstOne = 1;
            asm("" : "+r"(firstOne));
            one = firstOne;
            buffer = D_020377E0;
            selectorAddress = &D_020378E0;
            asm("" : "+r"(buffer), "+r"(selectorAddress));
            position = firstPosition;
            asm("" : "+r"(position));
            do {
                if ((index & 1) == 0) {
                    current = *selectorAddress;
                    oneCopy = one;
                    asm("" : "+r"(oneCopy));
                    current = (current ^ oneCopy) << 7;
                    current = index + current;
                    pixel = (u8 *)(current + (u32)buffer);
                    value = 0;
                    if (index > *position * 2)
                        value = 1;
                } else {
                    current = (*selectorAddress ^ one) << 7;
                    current = index + current;
                    pixel = (u8 *)(current + (u32)buffer);
                    value = 0;
                    if (index < -(*position * 2) + 0x7F)
                        value = 1;
                }
                *pixel = value;
                index = (u8)(index + 1);
            } while ((s32)(index << 24) >= 0);
        } else {
            firstValue = 0;
            current = 0xFFF0U;
            *firstPosition = current;
            phaseAddress = (s16 *)(base + 0x8CA);
            *phaseAddress = firstValue;
            *mode = 2;
        }
        break;
    case 2:
        position = (s16 *)(base + 0x8C8);
        current = *(u16 *)position + 1;
        *position = current;
        current = (s16)current;
        if (current == 0x80) {
            current = 0xFFF0U;
            *position = current;
        }
        phase = (s16 *)(base + 0x8CA);
        current = *(u16 *)phase + 1;
        *phase = current;
        if ((current << 16) == 0x1000000)
            *phase = 0;
        index = 0;
        lowBase = &D_020378E0;
        asm("" : "+r"(lowBase));
        waveSelector = lowBase;
        waveBuffer = D_020377E0;
        asm("" : "+r"(waveSelector), "+r"(waveBuffer));
        wavePosition = position;
        wavePhase = phase;
        asm("" : "+r"(wavePosition), "+r"(wavePhase));
        do {
            register u8 *selectorCopy asm("r1") = waveSelector;
            asm("" : "+r"(selectorCopy));
            current = *selectorCopy;
            row = 1;
            asm("" : "+r"(row));
            row = (row ^ current) << 7;
            row = index + row;
            wavePixel = (u8 *)(row + (u32)waveBuffer);
            waveValue = 0;
            row = 1;
            asm("" : "+r"(row));
            row &= current;
            if ((row && index >= *wavePosition && index <= *wavePosition + 0x10)
                || index == *wavePhase / 2)
                waveValue = 1;
            *wavePixel = waveValue;
            index = (u8)(index + 1);
        } while ((s32)(index << 24) >= 0);
        break;
    case 3:
        lastPosition = (s16 *)(base + 0x8C8);
        lastValue = *(u16 *)lastPosition;
        current = *lastPosition;
        if (current > 0) {
            current = lastValue - 1;
            *lastPosition = current;
            index = 0;
            lastOne = 1;
            asm("" : "+r"(lastOne));
            one = lastOne;
            buffer = D_020377E0;
            selectorAddress = &D_020378E0;
            asm("" : "+r"(buffer), "+r"(selectorAddress));
            position = lastPosition;
            asm("" : "+r"(position));
            do {
                if (index & 1) {
                    current = (*selectorAddress ^ one) << 7;
                    current = index + current;
                    pixel = (u8 *)(current + (u32)buffer);
                    value = 0;
                    if (index > *position * 2)
                        value = 1;
                } else {
                    current = (*selectorAddress ^ one) << 7;
                    current = index + current;
                    pixel = (u8 *)(current + (u32)buffer);
                    value = 0;
                    if (index < -(*position * 2) + 0x7F)
                        value = 1;
                }
                *pixel = value;
                index = (u8)(index + 1);
            } while ((s32)(index << 24) >= 0);
        } else {
            base[0x8C5] = 2;
        }
        break;
    }
    if (base[0x8C6])
        D_03000060[2] = D_03000060[4] + 0x1000;
}
