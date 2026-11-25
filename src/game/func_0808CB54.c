#include "types.h"

struct Entry
{
    u16 field_0;
    u16 id;
};

struct Info
{
    u8 pad_0[0x74];
    struct Entry entries[8];
};

struct State
{
    u8 pad_0[0x10];
    struct Info *info;
};

extern struct State D_0201F5F8;
extern char D_0203198C[];
extern const char D_080F3894[];
extern char *D_087A4890[];
void func_0807BE64(u32);
void func_0807BEF4(u32, char *, u32);
void func_080C8E88(char *, const char *, u32);
char *func_0807DB94(char *, const char *);

void func_0808CB54(void)
{
    u8 i;

    func_0807BE64(0);
    for (i = 0; i < 8; i++)
    {
        func_080C8E88(D_0203198C, D_080F3894, 7);
        func_0807DB94(D_0203198C, D_087A4890[D_0201F5F8.info->entries[i].id]);
        func_0807BEF4(0, D_0203198C, 0);
    }
}
