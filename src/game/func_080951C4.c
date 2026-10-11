#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *children[32];
    u32 vals[4];
};

extern u8 D_0203198C[];
extern const u8 D_080F42CC[];
extern const u8 D_080F4274[];
extern const u8 D_087B4CAC[];
void func_080771F4(void *);
void func_0807B830(u32, u32, u32, u8 *);
char *func_0807DB94(u8 *, const u8 *);
void func_080C8E88(u8 *, const u8 *, u32);
void *func_08077180(const u8 *, u32, u8, s16, s16, u32, u32, u32, u32);

void func_080951C4(struct Obj *obj)
{
    u8 i;
    u8 col;
    u8 c;
    u8 tile;
    s16 ch;
    u8 *s;
    u32 diff;

    for (i = 0; i < 32; i++)
    {
        if (obj->children[i] != 0)
            func_080771F4(obj->children[i]);
    }
    if (obj->vals[2] == 0)
        return;
    for (i = 0; i < 2; i++)
    {
        if (obj->vals[i + 2] != (u32)-1)
        {
            diff = obj->vals[i + 2] - obj->vals[i];
            if (diff >= 2000)
                obj->vals[i] += 1000;
            else if (diff >= 200)
                obj->vals[i] += 100;
            else if (diff >= 20)
                obj->vals[i] += 10;
            else if (obj->vals[i + 2] != obj->vals[i])
                obj->vals[i] += 1;
            if (i == 0)
            {
                func_0807B830(obj->vals[0], 4, 0x12, D_0203198C);
            }
            else
            {
                func_0807B830(obj->vals[i], 3, 0x12, D_0203198C);
                func_0807DB94(D_0203198C, D_080F42CC);
            }
        }
        else
        {
            func_080C8E88(D_0203198C, D_080F4274, 5);
        }
        s = D_0203198C;
        for (col = 0; (c = *s) != 0; s++, col++)
        {
            if ((u8)(c - '0') <= 9)
            {
                tile = c + 0xF0;
            }
            else
            {
                tile = c - 'A';
                if (tile > 25)
                {
                    ch = c;
                    if (ch == '+')
                        tile = 0x1A;
                    else if (ch == '-')
                        tile = 0x1B;
                    else if (ch == '/')
                        tile = 0x1C;
                    else if (ch == '<')
                        tile = 0x1D;
                    else if (ch == '>')
                        tile = 0x1E;
                    else if (ch == 0xA0)
                        tile = 0x1F;
                    else if (ch == '%')
                        tile = 0x2A;
                    else if (ch == '?')
                        tile = 0x2B;
                    else
                        continue;
                }
            }
            obj->children[i * 4 + col] = func_08077180(D_087B4CAC, 1, tile, obj->x + col * 6, obj->y + i * 8, 0x330, 0xB, 0x48, 0);
        }
    }
}
