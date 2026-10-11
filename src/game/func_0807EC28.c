#include "types.h"

struct Names
{
    u16 count;
    char title[0x12];
    char names[11][0x2E];
};

struct Header
{
    u32 field_0;
    const char *title;
};

extern struct Names D_02030584;
extern const struct Header D_087A464C;
extern const char *const D_08734AF8[];

char *func_080C8F78(char *, const char *);

void func_0807EC28(void)
{
    u8 i;

    D_02030584.count = 0;
    func_080C8F78(D_02030584.title, D_087A464C.title);
    for (i = 0; i < 11; i++)
        func_080C8F78(D_02030584.names[i], D_08734AF8[i]);
}
