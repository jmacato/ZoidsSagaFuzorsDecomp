#include "types.h"

#define ID_NUMBER 0x68736D53

struct MusicPlayerInfo;
struct MusicPlayerTrack;

struct WaveData
{
    u16 type;
    u16 status;
    u32 freq;
    u32 loopStart;
    u32 size;
    s8 data[1];
};

struct ToneData
{
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    struct WaveData *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct CgbChannel
{
    u8 sf;
    u8 ty;
    u8 rightVolume;
    u8 leftVolume;
    u8 at;
    u8 de;
    u8 su;
    u8 re;
    u8 ky;
    u8 ev;
    u8 eg;
    u8 ec;
    u8 echoVolume;
    u8 echoLength;
    u8 dummy1;
    u8 dummy2;
    u8 gt;
    u8 mk;
    u8 ve;
    u8 pr;
    u8 rp;
    u8 dummy3[3];
    u8 dummy5;
    u8 sg;
    u8 n4;
    u8 pan;
    u8 panMask;
    u8 mo;
    u8 le;
    u8 sw;
    u32 fr;
    u32 *wp;
    u32 *cp;
    u32 tp;
    u32 pp;
    u32 np;
    u8 dummy4[8];
};

struct SoundChannel
{
    u8 status;
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 ky;
    u8 envelopeVolume;
    u8 envelopeVolumeRight;
    u8 envelopeVolumeLeft;
    u8 echoVolume;
    u8 echoLength;
    u8 dummy1;
    u8 dummy2;
    u8 gateTime;
    u8 midiKey;
    u8 velocity;
    u8 priority;
    u8 rhythmPan;
    u8 dummy3[3];
    u32 count;
    u32 fw;
    u32 frequency;
    struct WaveData *wav;
    s8 *currentPointer;
    struct MusicPlayerTrack *track;
    void *prevChannelPointer;
    void *nextChannelPointer;
    u32 dummy4;
    u16 xpi;
    u16 xpc;
};

typedef void (*MPlayFunc)();
typedef void (*PlyNoteFunc)(u32, struct MusicPlayerInfo *, struct MusicPlayerTrack *);
typedef void (*CgbSoundFunc)(void);
typedef void (*CgbOscOffFunc)(u8);
typedef u32 (*MidiKeyToCgbFreqFunc)(u8, u8, u8);
typedef void (*ExtVolPitFunc)(void);
typedef void (*MPlayMainFunc)(struct MusicPlayerInfo *);

struct SoundInfo
{
    u32 ident;
    vu8 pcmDmaCounter;
    u8 reverb;
    u8 maxChans;
    u8 masterVolume;
    u8 freq;
    u8 mode;
    u8 c15;
    u8 pcmDmaPeriod;
    u8 maxLines;
    u8 gap[3];
    s32 pcmSamplesPerVBlank;
    s32 pcmFreq;
    s32 divFreq;
    struct CgbChannel *cgbChans;
    MPlayMainFunc MPlayMainHead;
    struct MusicPlayerInfo *musicPlayerHead;
    CgbSoundFunc CgbSound;
    CgbOscOffFunc CgbOscOff;
    MidiKeyToCgbFreqFunc MidiKeyToCgbFreq;
    MPlayFunc *MPlayJumpTable;
    PlyNoteFunc plynote;
    ExtVolPitFunc ExtVolPit;
    u8 gap2[16];
    struct SoundChannel chans[12];
    s8 pcmBuffer[0x630 * 2];
};

struct SongHeader
{
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    struct ToneData *tone;
    u8 *part[1];
};

struct MusicPlayerTrack
{
    u8 flags;
    u8 wait;
    u8 patternLevel;
    u8 repN;
    u8 gateTime;
    u8 key;
    u8 velocity;
    u8 runningStatus;
    u8 keyM;
    u8 pitM;
    s8 keyShift;
    s8 keyShiftX;
    s8 tune;
    u8 pitX;
    s8 bend;
    u8 bendRange;
    u8 volMR;
    u8 volML;
    u8 vol;
    u8 volX;
    s8 pan;
    s8 panX;
    s8 modM;
    u8 mod;
    u8 modT;
    u8 lfoSpeed;
    u8 lfoSpeedC;
    u8 lfoDelay;
    u8 lfoDelayC;
    u8 priority;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    struct SoundChannel *chan;
    struct ToneData tone;
    u8 gap[10];
    u16 unk_3A;
    u32 unk_3C;
    u8 *cmdPtr;
    u8 *patternStack[3];
};

struct MusicPlayerInfo
{
    struct SongHeader *songHeader;
    u32 status;
    u8 trackCount;
    u8 priority;
    u8 cmd;
    u8 unk_B;
    u32 clock;
    u8 gap[8];
    u8 *memAccArea;
    u16 tempoD;
    u16 tempoU;
    u16 tempoI;
    u16 tempoC;
    u16 fadeOI;
    u16 fadeOC;
    u16 fadeOV;
    struct MusicPlayerTrack *tracks;
    struct ToneData *tone;
    u32 ident;
    MPlayMainFunc MPlayMainNext;
    struct MusicPlayerInfo *MPlayMainNextPlayer;
};

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    struct MusicPlayerTrack *track;
    u8 numTracks;
    u16 unk_A;
};

struct Song
{
    struct SongHeader *header;
    u16 ms;
    u16 me;
};

#define SOUND_INFO_PTR (*(struct SoundInfo **)0x03007FF0)

extern const u8 D_0863E200[];

void func_080C7FD8(u8);
void func_080C8028(struct CgbChannel *);

void func_080C8090(void)
{
    s32 ch;
    struct CgbChannel *channels;
    s32 evAdd;
    s32 prevC15;
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *nrx0ptr;
    vu8 *nrx1ptr;
    vu8 *nrx2ptr;
    vu8 *nrx3ptr;
    vu8 *nrx4ptr;
    int mask = 0xff;

    if (soundInfo->c15)
        soundInfo->c15--;
    else
        soundInfo->c15 = 14;

    for (ch = 1, channels = soundInfo->cgbChans; ch <= 4; ch++, channels++)
    {
        if (!(channels->sf & 0xC7))
            continue;

        switch (ch)
        {
        case 1:
            nrx0ptr = (vu8 *)0x04000060;
            nrx1ptr = (vu8 *)0x04000062;
            nrx2ptr = (vu8 *)0x04000063;
            nrx3ptr = (vu8 *)0x04000064;
            nrx4ptr = (vu8 *)0x04000065;
            break;
        case 2:
            nrx0ptr = (vu8 *)0x04000061;
            nrx1ptr = (vu8 *)0x04000068;
            nrx2ptr = (vu8 *)0x04000069;
            nrx3ptr = (vu8 *)0x0400006C;
            nrx4ptr = (vu8 *)0x0400006D;
            break;
        case 3:
            nrx0ptr = (vu8 *)0x04000070;
            nrx1ptr = (vu8 *)0x04000072;
            nrx2ptr = (vu8 *)0x04000073;
            nrx3ptr = (vu8 *)0x04000074;
            nrx4ptr = (vu8 *)0x04000075;
            break;
        default:
            nrx0ptr = (vu8 *)0x04000071;
            nrx1ptr = (vu8 *)0x04000078;
            nrx2ptr = (vu8 *)0x04000079;
            nrx3ptr = (vu8 *)0x0400007C;
            nrx4ptr = (vu8 *)0x0400007D;
            break;
        }

        prevC15 = soundInfo->c15;
        evAdd = *nrx2ptr;

        if (channels->sf & 0x80)
        {
            if (!(channels->sf & 0x40))
            {
                channels->sf = 3;
                channels->mo = 3;
                func_080C8028(channels);
                switch (ch)
                {
                case 1:
                    *nrx0ptr = channels->sw;
                case 2:
                    *nrx1ptr = ((u32)channels->wp << 6) + channels->le;
                    goto init_env_step_time_dir;
                case 3:
                    if (channels->wp != channels->cp)
                    {
                        *nrx0ptr = 0x40;
                        *(vu32 *)0x04000090 = channels->wp[0];
                        *(vu32 *)0x04000094 = channels->wp[1];
                        *(vu32 *)0x04000098 = channels->wp[2];
                        *(vu32 *)0x0400009C = channels->wp[3];
                        channels->cp = channels->wp;
                    }
                    *nrx0ptr = 0;
                    *nrx1ptr = channels->le;
                    if (channels->le)
                        channels->n4 = 0xC0;
                    else
                        channels->n4 = 0x80;
                    break;
                default:
                    *nrx1ptr = channels->le;
                    *nrx3ptr = (u32)channels->wp << 3;
                init_env_step_time_dir:
                    evAdd = channels->at + 8;
                    if (channels->le)
                        channels->n4 = 0x40;
                    else
                        channels->n4 = 0x00;
                    break;
                }
                channels->ec = channels->at;
                if ((s8)(channels->at & mask))
                {
                    channels->ev = 0;
                    goto envelope_step_complete;
                }
                else
                {
                    goto envelope_decay_start;
                }
            }
            else
            {
                goto oscillator_off;
            }
        }
        else if (channels->sf & 0x04)
        {
            channels->echoLength--;
            if ((s8)(channels->echoLength & mask) <= 0)
            {
            oscillator_off:
                func_080C7FD8(ch);
                channels->sf = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        }
        else if ((channels->sf & 0x40) && (channels->sf & 0x03))
        {
            channels->sf &= ~0x03;
            channels->ec = channels->re;
            if ((s8)(channels->re & mask))
            {
                channels->mo |= 1;
                if (ch != 3)
                    evAdd = channels->re;
                goto envelope_step_complete;
            }
            else
            {
                goto envelope_pseudoecho_start;
            }
        }
        else
        {
        envelope_step_repeat:
            if (channels->ec == 0)
            {
                if (ch == 3)
                    channels->mo |= 1;

                func_080C8028(channels);
                if ((channels->sf & 0x03) == 0)
                {
                    channels->ev--;
                    if ((s8)(channels->ev & mask) <= 0)
                    {
                    envelope_pseudoecho_start:
                        channels->ev = ((channels->eg * channels->echoVolume) + 0xFF) >> 8;
                        if (channels->ev)
                        {
                            channels->sf |= 0x04;
                            channels->mo |= 1;
                            if (ch != 3)
                                evAdd = 0 + 8;
                            goto envelope_complete;
                        }
                        else
                        {
                            goto oscillator_off;
                        }
                    }
                    else
                    {
                        channels->ec = channels->re;
                    }
                }
                else if ((channels->sf & 0x03) == 1)
                {
                envelope_sustain:
                    channels->ev = channels->sg;
                    channels->ec = 7;
                }
                else if ((channels->sf & 0x03) == 2)
                {
                    int envelopeVolume, sustainGoal;

                    channels->ev--;
                    envelopeVolume = (s8)(channels->ev & mask);
                    sustainGoal = (s8)(channels->sg);
                    if (envelopeVolume <= sustainGoal)
                    {
                    envelope_sustain_start:
                        if (channels->su == 0)
                        {
                            channels->sf &= ~0x03;
                            goto envelope_pseudoecho_start;
                        }
                        else
                        {
                            channels->sf--;
                            channels->mo |= 1;
                            if (ch != 3)
                                evAdd = 0 + 8;
                            goto envelope_sustain;
                        }
                    }
                    else
                    {
                        channels->ec = channels->de;
                    }
                }
                else
                {
                    channels->ev++;
                    if ((u8)(channels->ev & mask) >= channels->eg)
                    {
                    envelope_decay_start:
                        channels->sf--;
                        channels->ec = channels->de;
                        if ((u8)(channels->ec & mask))
                        {
                            channels->mo |= 1;
                            channels->ev = channels->eg;
                            if (ch != 3)
                                evAdd = channels->de;
                        }
                        else
                        {
                            goto envelope_sustain_start;
                        }
                    }
                    else
                    {
                        channels->ec = channels->at;
                    }
                }
            }
        }

    envelope_step_complete:
        channels->ec--;
        if (prevC15 == 0)
        {
            prevC15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        if (channels->mo & 2)
        {
            if (ch < 4 && (channels->ty & 0x08))
            {
                int dac_pwm_rate = *(vu8 *)0x04000089;

                if (dac_pwm_rate < 0x40)
                    channels->fr = (channels->fr + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)
                    channels->fr = (channels->fr + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->fr;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->fr;
            channels->n4 = (channels->n4 & 0xC0) + (*((u8 *)(&channels->fr) + 1));
            *nrx4ptr = (s8)(channels->n4 & mask);
        }

        if (channels->mo & 1)
        {
            *(vu8 *)0x04000081 = (*(vu8 *)0x04000081 & ~channels->panMask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = D_0863E200[channels->ev];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= 0x7f;
                }
            }
            else
            {
                evAdd &= 0xf;
                *nrx2ptr = (channels->ev << 4) + evAdd;
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->mo = 0;
    }
}
