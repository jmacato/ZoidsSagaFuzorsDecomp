#include "types.h"

struct Entry
{
    u8 id;
    u8 field_1;
    u8 req[3][4];
    u8 pad_E[2];
};

struct Recipe
{
    u8 id;
    u8 unit;
    u8 field_2;
    s8 parts[4];
    u8 pad7;
};

struct Data
{
    u8 pad0[0x4DDC];
    struct Recipe recipes[12];
    u8 count;
};

struct Zoid
{
    u8 id;
};

extern struct Data D_02031A0C;
extern const struct Entry D_08741CE4[];

u32 func_0809A99C(u8, u8);
struct Zoid *func_0809A908(u8, u8);

void func_080BEB6C(u8 g, u8 u)
{
    s8 sel[4];
    const struct Entry *e;
    s8 k;
    u8 first;
    u8 n, row, i, j, t;

    D_02031A0C.count = 0;
    for (n = 0; D_08741CE4[n].id != 0; n++)
    {
        e = &D_08741CE4[n];
        for (row = 0; e->req[row][0] != 0; row++)
        {
            k = 0;
            sel[0] = -1;
            while (1)
            {
                if (k == 4 || e->req[row][k] == 0)
                {
                    for (i = 0; i < k && sel[i] != u; i++)
                        ;
                    if (i < k)
                    {
                        for (i = 0; i < D_02031A0C.count; i++)
                        {
                            if (D_02031A0C.recipes[i].id == e->id)
                            {
                                for (j = 0; j < 4 && D_02031A0C.recipes[i].parts[j] != -1; j++)
                                {
                                    for (t = 0; t < k && D_02031A0C.recipes[i].parts[j] != sel[t]; t++)
                                        ;
                                    if (t == k)
                                        break;
                                }
                                if (j == 4 || D_02031A0C.recipes[i].parts[j] == -1)
                                    break;
                            }
                        }
                        if (i == D_02031A0C.count)
                        {
                            D_02031A0C.recipes[D_02031A0C.count].id = e->id;
                            for (i = 0; i < 4; i++)
                                D_02031A0C.recipes[D_02031A0C.count].parts[i] = sel[i];
                            D_02031A0C.recipes[D_02031A0C.count].unit = first;
                            D_02031A0C.recipes[D_02031A0C.count].field_2 = e->field_1;
                            D_02031A0C.count++;
                        }
                    }
                    k--;
                }
                for (i = sel[k] + 1; i < 6; i++)
                {
                    if (func_0809A99C(g, i) && e->req[row][k] == func_0809A908(g, i)->id)
                    {
                        sel[k] = i;
                        if (k == 0)
                            first = i;
                        k++;
                        if (k < 4)
                            sel[k] = -1;
                        break;
                    }
                }
                if (i == 6)
                {
                    if (k == 0)
                        break;
                    k--;
                }
            }
        }
    }
}
