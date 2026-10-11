#include "types.h"

struct Matrix
{
    s16 m[3][3];
    s32 trans[3];
};

s16 func_08075AAC(s16);
s16 func_08075AF8(s16);
void func_080764FC(struct Matrix *, struct Matrix *, struct Matrix *);

void func_080767AC(const s16 *angle, struct Matrix *out)
{
    struct Matrix rx;
    struct Matrix ry;
    struct Matrix rz;
    struct Matrix tmp;

    rx.m[0][0] = 0x100;
    rx.m[1][0] = 0;
    rx.m[2][0] = 0;
    rx.m[0][1] = 0;
    rx.m[1][1] = func_08075AF8(angle[0]);
    rx.m[2][1] = -func_08075AAC(angle[0]);
    rx.m[0][2] = 0;
    rx.m[1][2] = func_08075AAC(angle[0]);
    rx.m[2][2] = func_08075AF8(angle[0]);

    ry.m[0][0] = func_08075AF8(angle[1]);
    ry.m[1][0] = 0;
    ry.m[2][0] = func_08075AAC(angle[1]);
    ry.m[0][1] = 0;
    ry.m[1][1] = 0x100;
    ry.m[2][1] = 0;
    ry.m[0][2] = -func_08075AAC(angle[1]);
    ry.m[1][2] = 0;
    ry.m[2][2] = func_08075AF8(angle[1]);

    rz.m[0][0] = func_08075AF8(angle[2]);
    rz.m[1][0] = -func_08075AAC(angle[2]);
    rz.m[2][0] = 0;
    rz.m[0][1] = func_08075AAC(angle[2]);
    rz.m[1][1] = func_08075AF8(angle[2]);
    rz.m[2][1] = 0;
    rz.m[0][2] = 0;
    rz.m[1][2] = 0;
    rz.m[2][2] = 0x100;

    func_080764FC(&rx, &ry, &tmp);
    func_080764FC(&tmp, &rz, out);
}
