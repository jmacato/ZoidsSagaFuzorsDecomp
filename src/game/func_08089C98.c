#include "types.h"

extern u8 D_08734DB2[][5];

s32 func_08089C98(u8 *p, u8 id)
{
    u8 *list;
    u8 i;
    if (id < 200)
    {
        if (*p == id)
            return 1;
    }
    else
    {
        list = D_08734DB2[id];
        for (i = 0; i < 5 && *list != 0; list++, i++)
        {
            if (*p == *list)
                return 1;
        }
    }
    return 0;
}
