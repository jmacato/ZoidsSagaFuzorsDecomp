#include "types.h"

struct Mgr
{
    u8 field_0;
    u8 field_1;
};

extern struct Mgr D_0201F5F8;
extern u8 D_0200C4A0;
extern u8 D_0202898E;
extern u8 D_0200C4A2;
extern const u8 D_08000B82[];
void func_0807C290(const u8 *);
void func_0808A948(void);

s32 func_0808AB98(void)
{
    for (;;)
    {
        func_0807C290(D_08000B82);
        if (D_0200C4A2 == 1)
        {
            D_0201F5F8.field_1 = D_0200C4A0;
            return D_0200C4A0;
        }
        if (D_0200C4A2 == 2)
            return -1;
        D_0202898E ^= 1;
        func_0808A948();
    }
}
