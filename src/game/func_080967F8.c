#include "types.h"

struct Unit
{
    u8 kind;
};

struct Big
{
    u8 pad_0[0x24C];
    struct Unit *unit;
};

extern struct Big D_02031A0C;
extern u8 D_0203124A[];
extern u8 D_0203124F;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern const u8 *D_087A43E0[];
extern const u8 *D_087A8CF8[];
extern const u8 D_08003FEE[];
extern const u8 D_08003FCE[];
extern const u8 D_08003FAC[];
extern const u8 D_08003FF9[];
extern const u8 D_08004000[];
extern const u8 D_08004038[];
extern const u8 D_0800406E[];
extern const u8 D_080040A2[];
void func_0807C290(const u8 *);
void func_0807BEF4(u32, const u8 *, u32);

s32 func_080967F8(s32 mode)
{
    u8 list[8];
    s32 result;
    u8 n;
    u8 i;

    while (1)
    {
        if (mode == 1 || mode == 2)
        {
            n = 0;
            func_0807C290(D_08003FEE);
            if (mode == 1)
            {
                func_0807C290(D_08003FCE);
                for (i = 0; i < D_0203124F; i++)
                {
                    if (D_02031A0C.unit->kind != D_0203124A[i])
                    {
                        func_0807BEF4(1, D_087A43E0[D_0203124A[i]], 0);
                        list[n] = i;
                        n++;
                    }
                }
            }
            else
            {
                func_0807C290(D_08003FAC);
                for (i = 0; i < D_0203124F; i++)
                {
                    if (D_02031A0C.unit->kind != D_0203124A[i])
                    {
                        func_0807BEF4(1, D_087A8CF8[D_0203124A[i] - 0x69], 0);
                        list[n] = i;
                        n++;
                    }
                }
            }
            func_0807C290(D_08003FF9);
            if (D_0200C4A2 != 1)
            {
                result = -1;
                break;
            }
            result = list[D_0200C4A0];
        }
        else
        {
            if (D_02031A0C.unit->kind != D_0203124A[0])
                result = 0;
            else
                result = 1;
        }
        switch (mode)
        {
        case 1:
            func_0807C290(D_08004000);
            break;
        case 2:
            func_0807C290(D_08004038);
            break;
        case 3:
            func_0807C290(D_0800406E);
            break;
        case 4:
            func_0807C290(D_080040A2);
            break;
        }
        if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            break;
        if (mode == 3 || mode == 4)
        {
            result = -1;
            break;
        }
    }
    return result;
}
