#include "types.h"

struct Zoid
{
    u8 species;
    u8 pad1[0x93];
};

extern struct Zoid D_02020E88[];

void func_080BD488(u8, u8, struct Zoid *);
void func_0807F318(u8);
void func_0807F444(u8, u32);

u32 func_0807EC90(u8 species, u8 level)
{
    u32 i;

    for (i = 1; i < 186; i++)
    {
        if (D_02020E88[i].species == 0)
        {
            func_080BD488(species, level, &D_02020E88[i]);
            func_0807F318(species);
            func_0807F444(species, 0);
            return i;
        }
    }
    return 0;
}
