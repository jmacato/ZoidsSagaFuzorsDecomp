#include "types.h"

struct Recipe
{
    u8 id;
    u8 pad1;
    u8 parts[3][4];
    u8 padE[2];
};

extern const struct Recipe D_08741CE4[];
extern u8 D_0203052C[];

void func_0807F444(u8 id, u8 mode)
{
    u8 i;
    u8 j;
    u8 k;
    const struct Recipe *recipe;

    if (mode == 0)
    {
        for (i = 0; (recipe = &D_08741CE4[i])->id != 0; i++)
        {
            j = 0;
            if (recipe->parts[0][j] != 0)
            {
                for (;;)
                {
                    for (k = 0; k < 3 && recipe->parts[k][j] != 0; k++)
                    {
                        if (recipe->parts[k][j] == id)
                        {
                            D_0203052C[i] |= 1 << j;
                            break;
                        }
                    }
                    j++;
                    if (j >= 4 || recipe->parts[0][j] == 0)
                        break;
                }
            }
        }
    }
    else
    {
        i = 0;
        recipe = &D_08741CE4[i];
        if (recipe->id != 0)
        {
            do
            {
                if (recipe->id == id)
                    D_0203052C[i] |= 0x80;
                i++;
            } while ((recipe = &D_08741CE4[i])->id != 0);
        }
    }
}
