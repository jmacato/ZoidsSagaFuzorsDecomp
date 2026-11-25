#include "types.h"

char *func_080C8F78(char *, const char *);

char *func_0807DB94(char *dst, const char *src)
{
    char *ret = dst;
    while (*dst)
        dst++;
    func_080C8F78(dst, src);
    return ret;
}
