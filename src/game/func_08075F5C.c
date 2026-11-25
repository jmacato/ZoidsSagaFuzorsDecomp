#include "types.h"

struct MusicPlayerInfo
{
    u32 songHeader;
    s32 status;
};

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

u32 func_08075F5C(u16 song)
{
    if (D_0863FFD4[D_08640040[song].ms].info->status < 0)
        return 1;
    return 0;
}
