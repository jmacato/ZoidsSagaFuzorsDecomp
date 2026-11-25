#include "types.h"

extern u8 D_08741C44[][10];

u8 *func_0809A908(u8, u8);
void func_0809B75C(u8, u8);
void func_080BE058(u8 *, u8);
void func_080BE46C(u8, u8);
void func_0809AC04(u8, u8, u8, u8);
void func_0809B26C(u8, u8, u8, u8, u8, u8, u8, u8, u8);

void func_080BF3E4(u8 a, u8 b, u8 c, u8 d)
{
    u8 *obj = func_0809A908(a, b);
    u8 i, j;
    u8 *p;
    for (i = 0; D_08741C44[i][0] != 0; i++)
    {
        for (p = D_08741C44[i], j = 0; j < 5 && *p != 0; p += 2, j++)
        {
            if (*p == *obj)
            {
                if (p[1] != 3 && p[1] != 4)
                    func_0809B75C(a, b);
                break;
            }
        }
        if (j < 5 && *p != 0)
            break;
    }
    func_080BE058(obj, d);
    func_080BE46C(a, b);
    func_0809AC04(a, b, c, 0);
    func_0809B26C(a, b, 0x29, 0, 1, 0, 0xFF, 0xFF, 0xFF);
}
