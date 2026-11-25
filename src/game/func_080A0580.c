#include "types.h"

struct Info
{
    u8 data[0x94];
};

void func_080BD488(u8 a, u8 b, struct Info *info);
void func_080A03FC(struct Info *info);

void func_080A0580(u8 a, u8 b)
{
    struct Info info;
    func_080BD488(a, b, &info);
    func_080A03FC(&info);
}
