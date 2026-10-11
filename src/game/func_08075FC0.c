#include "types.h"

struct MusicPlayerInfo;

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    u32 track;
    u32 numTracks;
};

struct Song
{
    u32 header;
    u16 ms;
    u16 me;
};

extern struct MusicPlayer D_0863FFD4[];
extern struct Song D_08640040[];
extern u16 D_03002350;

void func_080C76F4(struct MusicPlayerInfo *, u16);

void func_08075FC0(u16 tempo)
{
    func_080C76F4(D_0863FFD4[D_08640040[D_03002350].ms].info, tempo >> 4);
}
