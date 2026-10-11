#include "types.h"

extern u8 D_0200C624[];
void func_0807BD4C(u8);

void func_0807BE64(u8 id)
{
    D_0200C624[id] = 0;
    func_0807BD4C(id);
}
