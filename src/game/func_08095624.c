#include "types.h"

struct Big
{
    u8 pad_0[0x4F85];
    u8 field_4F85[3];
};

extern struct Big D_02031A0C;
extern const u8 D_08005678[];
extern const u8 D_0800567B[];
extern const u8 D_0800567E[];
void func_0807C290(const u8 *);

void func_08095624(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (D_02031A0C.field_4F85[i] != 0xFF)
        {
            switch (i)
            {
            case 0:
                func_0807C290(D_08005678);
                break;
            case 1:
                func_0807C290(D_0800567B);
                break;
            case 2:
                func_0807C290(D_0800567E);
                break;
            }
        }
    }
}
