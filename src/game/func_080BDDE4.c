#include "types.h"

struct Param
{
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_C;
};

void func_080BD57C(void *obj);
void func_080BD98C(void *obj, struct Param *param, u16 a, u8 b);
void func_080BD790(void *obj, struct Param *param, u32 a);
void func_080BDC78(void *obj);
void func_080BDCD8(void *obj);

void func_080BDDE4(void *obj, u32 val, u8 b)
{
    struct Param param;
    func_080BD57C(obj);
    param.field_0 = val;
    param.field_4 = 0;
    func_080BD98C(obj, &param, 0, b);
    func_080BD790(obj, &param, 0);
    func_080BDC78(obj);
    func_080BDCD8(obj);
}
