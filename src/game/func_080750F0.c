#include "types.h"

extern vu8 D_0300068C;
extern u8 D_0300068D;

void func_08075850(void);
void func_08075FF4(void);

void func_080750F0(u8 frames)
{
    if (frames > D_0300068D)
        frames -= D_0300068D;
    else
        frames = 1;
    frames--;
    while (frames != 0xFF)
    {
        if (frames != 0)
            D_0300068C = 2;
        else
            D_0300068C = 1;
    wait:
        if (D_0300068C != 0)
            goto wait;
        frames--;
    }
    func_08075850();
    func_08075FF4();
    D_0300068D = 0;
}
