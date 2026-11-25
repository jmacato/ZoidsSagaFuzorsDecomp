#include "types.h"

struct MusicPlayerInfo
{
    u32 songHeader;
    u16 field_4;
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

void func_080C8504(struct MusicPlayerInfo *, u16, u16);

void func_08075F90(u16 song, u16 volume)
{
    struct MusicPlayerInfo *info = D_0863FFD4[D_08640040[song].ms].info;
    func_080C8504(info, info->field_4, volume);
}
