#include "types.h"

struct Window {
    u32 flags;
    u8 pad[0x4CC];
};
extern u8 D_0200C624[];
extern u8 D_0200C62E[];
extern struct Window D_02009480[];
void func_0807BE80(struct Window *);

void func_0807BEF4(u32 arg0, u8 *arg1, s8 type)
{
    /* Empty asm keeps agbcc register copies without adding instructions. */
    register u8 *text asm("r5") = arg1;
    register u32 id asm("r8") = (u8)arg0;
    u8 *base = D_0200C62E;
    u8 *counts = D_0200C624;
    register u8 *row asm("r12") = counts + id;
    register s32 index asm("r0") = *row * 37;
    s32 offset = id * 0x1E5A;
    u8 pos;
    u8 value;
    register u8 *savedBase asm("r9");
    register u8 *savedCounts asm("r10");
    register u8 *loopRow asm("r3");
    register u8 *loopBase asm("r4");
    register u8 *typeBase asm("r1");
    register u32 writeIndex asm("r1");
    struct Window *win;
    u8 *endRow;

    base[index + offset] = 1;
    index = *row * 37 + offset;
    typeBase = base + 1;
    asm("" : "+r"(typeBase));
    *(u8 *)(index + (u32)typeBase) = type;
    pos = 2;
    value = *text;
    savedBase = base;
    savedCounts = counts;
    if (value != 0) {
        loopBase = savedBase;
        asm("" : "+r"(loopBase));
        loopRow = row;
        asm("" : "+r"(loopRow));
loop:
        writeIndex = pos + *loopRow * 37;
        writeIndex += offset;
        *(u8 *)(writeIndex + (u32)loopBase) = value;
        if (*text == 1) {
            text++;
            pos = (u8)(pos + 1);
            index = pos + *loopRow * 37 + offset;
            *(u8 *)(index + (u32)savedBase) = *text;
        }
        text++;
        pos = (u8)(pos + 1);
        if (pos <= 35) {
            value = *text;
            if (value != 0)
                goto loop;
        }
    }
    endRow = (u8 *)(id + (u32)savedCounts);
    index = pos + *endRow * 37;
    index += id * 0x1E5A;
    *(u8 *)(index + (u32)savedBase) = 0;
    win = (struct Window *)(id * 0x4D0 + (u32)D_02009480);
    func_0807BE80(win);
    (*endRow)++;
    win->flags |= 2;
}
