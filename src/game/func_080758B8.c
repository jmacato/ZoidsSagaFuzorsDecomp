#include "types.h"

struct Node
{
    struct Node *next;
    s32 id;
    u8 pad8[8];
};

extern struct Node D_03000B20[];

void func_080758B8(void)
{
    struct Node *node = D_03000B20;
    s32 i;

    for (i = 0; i < 8; i++)
    {
        node->next = node + 1;
        node = node->next;
    }
    node->next = 0;

    node = D_03000B20;
    for (i = 0; i < 9; i++)
    {
        node->id = -1;
        node++;
    }
}
