#include "types.h"

struct StageMsg
{
    u8 field_0;
    u8 pad_1[3];
    const u8 *msgs[3];
};

extern const struct StageMsg D_087A5E44[][5];
extern u8 D_02001480[];
extern const u8 D_08024311[];
extern const u8 D_0802432A[];
extern const u8 D_08024347[];
extern const u8 D_0802436C[];
extern const u8 D_08024385[];
extern const u8 D_080243E1[];
extern const u8 D_080243F6[];
extern const u8 D_0802441A[];
extern const u8 D_080243A2[];
extern const u8 D_080243AB[];
extern const u8 D_080243B4[];
extern const u8 D_080243BF[];
extern const u8 D_080243CE[];
extern u8 D_02036A28[][11][46];

void func_0807FF2C(u8 stage, u8 a, u16 b, u8 c, void *buf);
void func_0807BD4C(u8 a);
void func_0807B77C(const u8 *msg, u8 a, u8 b);

void func_080A2D70(u8 stage, u8 kind, u8 idx, u16 id, u8 slot)
{
    if (stage != 0xFF)
        func_0807FF2C(stage, D_087A5E44[stage][kind].field_0, 0x3DC, 0xF, D_02001480);
    func_0807BD4C(1);
    if (stage == 0x81 || stage == 0xFF)
        func_0807B77C(D_087A5E44[0x81][kind].msgs[idx], 0, 1);
    else if (kind == 0 && id == 0xEA)
        func_0807B77C(D_08024311, 0, 1);
    else if (kind == 0 && (id == 0xDF || id == 0xE7 || id == 0xEB || id == 0xEF || id == 0x124 || id == 0x16B || id == 0x16F || id == 0x173
                           || id == 0x228 || id == 0x22C || id == 0x28E || id == 0x2AB || id == 0x2B3 || id == 0x2F6 || id == 0x313))
        func_0807B77C(D_0802432A, 0, 1);
    else if (kind == 0 && id == 0x18A)
        func_0807B77C(D_08024347, 0, 1);
    else if (kind == 0 && id == 0x109)
        func_0807B77C(D_0802436C, 0, 1);
    else if (kind == 0 && id == 0x14E)
        func_0807B77C(D_08024385, 0, 1);
    else if (kind == 0 && id == 0x2D7)
        func_0807B77C(D_080243E1, 0, 1);
    else if (kind == 0 && id == 0x2DA)
        func_0807B77C(D_080243F6, 0, 1);
    else if (kind == 0 && (id == 0x314 || id == 0x315 || id == 0x318 || id == 0x319 || id == 0x31C))
        func_0807B77C(D_0802441A, 0, 1);
    else if (kind == 2 && id == 0x32C && stage == 0x31)
        func_0807B77C(D_080243A2, 0, 1);
    else if (kind == 2 && id == 0x32C && stage == 0x3B)
        func_0807B77C(D_080243AB, 0, 1);
    else if (kind == 2 && id == 0x32C && (stage == 0x43 || stage == 0x30))
        func_0807B77C(D_080243B4, 0, 1);
    else if (kind == 2 && id == 0x32C && stage == 0x44)
        func_0807B77C(D_080243BF, 0, 1);
    else if (kind == 2 && (id == 0xB3 || id == 0xB4))
        func_0807B77C(D_080243CE, 0, 1);
    else if (stage == 1)
    {
        switch (kind)
        {
        case 0:
            func_0807B77C(D_02036A28[slot][idx], 0, 1);
            break;
        case 1:
            func_0807B77C(D_02036A28[slot][3 + idx], 0, 1);
            break;
        case 2:
            func_0807B77C(D_02036A28[slot][6 + idx], 0, 1);
            break;
        case 3:
            func_0807B77C(D_02036A28[slot][9], 0, 1);
            break;
        case 4:
            func_0807B77C(D_02036A28[slot][10], 0, 1);
            break;
        }
    }
    else
        func_0807B77C(D_087A5E44[stage][kind].msgs[idx], 0, 1);
}
