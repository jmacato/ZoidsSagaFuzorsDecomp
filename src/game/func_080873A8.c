#include "types.h"

extern u8 D_0201F6DC;
extern u8 D_02020E4C[];
extern u8 D_020209D8[];
extern u8 D_02020988[];
extern u8 D_085BF19C[];
extern u8 D_085BF1A8[];
extern s32 D_03000060[];
extern s32 D_08734DD8[];
void func_08075F20(u32);
u8 *func_080771BC(void *, void *, u32, s32, s32, u32, u32, u32, u32);
void func_080771F4(void *);
void func_08077204(void *, u32);
u32 func_08080C54(u32);
void func_08082F84(void);
void func_08082FE4(u32);
void func_080830F4(u32, u32, u32, s32, s32, u32, u32);
void func_0808329C(u32);
void func_08083C5C(u32, s32, u32);
void func_080872F4(void);
void func_080C8FCC(u32);

s32 func_080873A8(u32 arg0, u8 **arg1)
{
    register s32 current asm("r0");
    register u32 work1 asm("r1");
    register u32 work2 asm("r2");
    register s32 work3 asm("r3");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *coordinates asm("r8");
    register s32 x asm("r8");
    register s32 y asm("r9");
    register u8 *object asm("r10");
    register u8 **event asm("r7") = arg1;
    register u16 *destinationX asm("r5");
    register u16 *destinationY asm("r6");
    register volatile u32 selected asm("r4");
    register s32 position asm("r5");
    register s32 speed asm("r6");
    s32 limit;
    u8 **fallObject;
    register u8 **movingObject asm("r5");
    register u8 **objectAddress asm("r4");
    register s32 screenX asm("r7");
    register s32 screenY asm("r4");
    register volatile s32 zero asm("r7");
    register volatile s32 four asm("r6");
    register volatile s32 frame asm("r6");
    s32 *offsets;
    u8 index;
    volatile u32 id;

    id = (u8)arg0;
    pointer1 = &D_0201F6DC;
    current = 1;
    *pointer1 = current;
    pointer2 = D_02020E4C;
    pointer0 = *event;
    current = pointer0[1];
    current++;
    work3 = 0x7B4D;
    asm("" : "+r"(work3));
    pointer1 = pointer2 + work3;
    *pointer1 = current;
    pointer0 = D_020209D8;
    coordinates = pointer0;
    work1 = *(u16 *)pointer0;
    work3++;
    pointer0 = pointer2 + work3;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer0));
        *address = work1;
    }
    pointer0 = *event;
    work1 = pointer0[2];
    current = pointer0[3];
    current <<= 8;
    work1 |= current;
    current = 0x7B50;
    asm("" : "+r"(current));
    destinationX = (u16 *)(pointer2 + current);
    *destinationX = work1;
    pointer0 = *event;
    work1 = pointer0[4];
    current = pointer0[5];
    current <<= 8;
    work1 |= current;
    work3 += 4;
    destinationY = (u16 *)(pointer2 + work3);
    *destinationY = work1;
    pointer1 = *event;
    current = pointer1[7];
    if (current != 0) {
        current = pointer1[6];
        selected = (u8)func_08080C54(current);
        current = (selected << 4) + selected;
        work1 = current << 2;
        pointer0 = coordinates;
        pointer0 += 0x70;
        current = *(s32 *)(work1 + (u32)pointer0);
        if (current < 0) {
            work2 = 0x7FF;
            asm("" : "+r"(work2));
            current += work2;
        }
        current >>= 11;
        work3 = *destinationX;
        asm("" : "+r"(work3));
        current += work3;
        *destinationX = current;
        pointer0 = coordinates;
        pointer0 += 0x74;
        current = *(s32 *)(work1 + (u32)pointer0);
        if (current < 0) {
            work1 = 0x7FF;
            asm("" : "+r"(work1));
            current += work1;
        }
        current >>= 11;
        work2 = *destinationY;
        asm("" : "+r"(work2));
        current += work2;
        *destinationY = current;
    }
    func_08082FE4(4);
    func_08082FE4((u8)((*event)[1] + 9));
    pointer0 = D_02020E4C;
    work3 = 0x7B50;
    asm("" : "+r"(work3));
    pointer1 = pointer0 + work3;
    work1 = *(u16 *)pointer1;
    work1 <<= 11;
    x = work1;
    work1 = 0x7B52;
    asm("" : "+r"(work1));
    pointer0 += work1;
    current = *(u16 *)pointer0;
    current <<= 11;
    y = current;
    position = -0x6400;
    speed = 0;
    pointer0 = *event;
    current = pointer0[1];
    current += 9;
    work1 = (u8)current;
    current = x;
    asm("" : "+r"(current));
    current <<= 8;
    screenX = current >> 16;
    screenY = y;
    asm("" : "+r"(screenY));
    screenY = (screenY << 8) >> 16;
    func_080830F4(0, work1, 0, screenX, screenY, 1, 4);
    object = func_080771BC(D_085BF19C, D_085BF1A8, 0, screenX, screenY, 0x36A, 15, 0x12C8, speed);
    current = -0x800;
    asm("" : "+r"(current));
    limit = current;
    fallObject = (u8 **)D_02020988;
fall_loop:
    speed += 0x40;
    position += speed;
    if (position > limit)
        position = current;
    pointer1 = *fallObject;
    current = position;
    if (position < 0)
        current += 0xFF;
    current >>= 8;
    *(u16 *)(pointer1 + 14) = current;
    func_080C8FCC(1);
    current = limit;
    if (position < limit)
        goto fall_loop;
    pointer2 = &D_0201F6DC;
    work3 = 0x12AC;
    asm("" : "+r"(work3));
    pointer0 = pointer2 + work3;
    pointer0 = *(u8 **)pointer0;
    func_08077204(pointer0, 3);
    func_080771F4(object);
    current = x;
    asm("" : "+r"(current));
    position = current >> 8;
    current = position;
    current -= 12;
    work3 = (s16)current;
    screenY = y;
    asm("" : "+r"(screenY));
    screenY >>= 8;
    current = (s16)screenY;
    x = current;
    func_080830F4(1, 4, 0, work3, current,
        ({ zero = 0; asm("" : "+r"(zero)); zero; }),
        ({ four = 4; asm("" : "+r"(four)); four; }));
    work3 = (s16)(position - 4);
    screenY += 4;
    screenY = (s16)screenY;
    func_080830F4(2, 4, 0, work3, screenY, zero, four);
    work3 = (s16)(position + 4);
    func_080830F4(3, 4, 0, work3, screenY, zero, four);
    current = position;
    current += 12;
    work3 = (s16)current;
    current = x;
    asm("" : "+r"(current));
    func_080830F4(4, 4, 0, work3, current, zero, four);
    func_08075F20(0xD8);
    frame = 0;
    pointer1 = &D_0201F6DC;
    work3 = 0x12B0;
    asm("" : "+r"(work3));
    pointer2 = pointer1 + work3;
    pointer0 = *(u8 **)pointer2;
    current = *(u32 *)pointer0;
    work1 = 1;
    current &= work1;
    if (current == 0)
        goto done_moving;
    offsets = D_03000060;
    movingObject = (u8 **)pointer2;
move_loop:
    if (frame <= 8) {
        pointer0 = (u8 *)D_08734DD8;
        work2 = frame << 2;
        pointer2 = (u8 *)(work2 + (u32)pointer0);
        current = offsets[1];
        work1 = *(u32 *)pointer2;
        current += work1;
        offsets[1] = current;
        current = offsets[3];
        work1 = *(u32 *)pointer2;
        current += work1;
        offsets[3] = current;
        current = offsets[5];
        work1 = *(u32 *)pointer2;
        current += work1;
        offsets[5] = current;
        current = offsets[7];
        work1 = *(u32 *)pointer2;
        current += work1;
        offsets[7] = current;
        frame++;
    }
    func_080C8FCC(1);
    pointer0 = *movingObject;
    current = *(u32 *)pointer0;
    work1 = 1;
    current &= work1;
    if (current != 0)
        goto move_loop;
done_moving:
    pointer0 = &D_0201F6DC;
    work1 = 0x12AC;
    asm("" : "+r"(work1));
    objectAddress = (u8 **)(pointer0 + work1);
    pointer2 = *objectAddress;
    current = *(u32 *)pointer2;
    work1 = -0x31;
    current &= work1;
    *(u32 *)pointer2 = current;
    asm("" : "+r"(objectAddress));
    pointer2 = *objectAddress;
    current = *(u32 *)pointer2;
    work1 = 0x10;
    current |= work1;
    *(u32 *)pointer2 = current;
    asm("" : "+r"(objectAddress));
    func_08077204(*objectAddress, 1);
    func_08075F20(0xD9);
    pointer0 = *objectAddress;
    current = *(u32 *)pointer0;
    work1 = 4;
    current &= work1;
    if (current == 0) {
        register u8 **address asm("r5");
        register u32 mask asm("r4");
        address = objectAddress;
        asm("" : "+r"(address));
        mask = 4;
        asm("" : "+r"(mask));
wait_loop:
        func_080C8FCC(1);
        pointer0 = *address;
        current = *(u32 *)pointer0;
        current &= mask;
        if (current == 0)
            goto wait_loop;
    }
    index = 0;
cleanup_loop:
    func_0808329C(index);
    index++;
    if (index <= 15)
        goto cleanup_loop;
    func_08082F84();
    func_080872F4();
    work1 = -1;
    asm("" : "+r"(work1));
    current = id;
    work2 = 0;
    func_08083C5C(current, work1, work2);
    return 0;
}
