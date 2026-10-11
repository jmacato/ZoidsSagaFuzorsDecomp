#include "types.h"

struct AnimFrame
{
    s16 frame;
    s16 duration;
};

struct Part
{
    s16 tile;
    u8 flip;
    u8 angle;
    u16 x;
    u16 y;
    s16 w;
    s16 h;
    s16 scaleX;
    s16 scaleY;
    u8 field_10;
    u8 attr;
    u8 pad12[2];
};

struct Sprite
{
    u32 flags;
    s32 x;
    s32 y;
    u16 offX;
    u16 offY;
    s16 scaleX;
    s16 scaleY;
    u16 tileBase;
    u8 palette;
    u8 angle;
    u16 animIdx;
    u16 frameIdx;
    u16 timer;
    s16 field_1E;
    struct Part **frames;
    struct AnimFrame **anims;
    u32 gfx;
    void (*callback)(struct Sprite *);
    u8 pad30[0x10];
};

struct OamData
{
    u32 y:8;
    u32 affineMode:2;
    u32 objMode:2;
    u32 mosaic:1;
    u32 bpp:1;
    u32 shape:2;
    u32 x:9;
    u32 matrixNum:5;
    u32 size:2;
    u16 tileNum:10;
    u16 priority:2;
    u16 paletteNum:4;
    u16 affineParam;
};

extern struct Sprite D_030031C8[128];
extern struct Sprite *D_030051C8[128];
extern u8 D_030053C8;
extern u16 D_0300028C[512];
extern u32 D_03000084;
extern u8 D_03000081;
extern s32 D_03000060[];
extern u8 D_03005714;

void func_0807721C(void);
void func_08077204(struct Sprite *, u16);
u32 func_0807806C(u32, u32, u16);
s16 func_08075AAC(u16);
s16 func_08075AF8(u16);
s32 func_080C8B80(s32, s32);

void func_08077384(void)
{
    s16 i;
    s16 j;
    struct Sprite *s;
    struct AnimFrame *anim;
    struct Part *part;
    u16 *oam;
    s16 x, y, cx, cy, y2, w, h, sw, sh, cx2, cy2;
    u8 affineIdx;
    u16 tileOff;
    u8 hidden;
    s16 sn, cs;
    u32 attr;
    u32 flip;
    s16 *mtx;
    u32 matrixBits;

    for (i = 0; i < 128; i++)
    {
        s = &D_030031C8[i];
        if ((s->flags & 1) && s->callback)
            s->callback(s);
    }
    func_0807721C();
    oam = D_0300028C;
    affineIdx = 0;
    for (i = 0; i < D_030053C8; i++)
    {
        s = D_030051C8[i];
        anim = s->anims[s->animIdx] + s->frameIdx;
        hidden = 0;
        if (s->flags & 0x20000)
            goto hide;
        if ((s->flags & 0x200000) && !(D_03000084 & 0x20))
            goto hide;
        if (s->scaleX == 0)
            goto hide;
        if (s->scaleY == 0)
            goto hide;
        part = s->frames[anim->frame];
        tileOff = 0;
        while (part->tile != -1 && oam < &D_0300028C[512])
        {
            if (s->angle == 0 && s->scaleX == 0x100 && s->scaleY == 0x100)
            {
                x = part->x;
                y = part->y;
            }
            else
            {
                cx = part->w / 2 + part->x;
                cy = part->h / 2 + part->y;
                if (s->scaleX != 0x100)
                    cx = cx * s->scaleX / 256;
                if (s->scaleY != 0x100)
                    cy = cy * s->scaleY / 256;
                if (s->angle == 0)
                {
                    x = cx + -part->w / 2;
                    y = cy + -part->h / 2;
                }
                else
                {
                    sn = func_08075AAC(s->angle);
                    cs = func_08075AF8(s->angle);
                    x = -part->w / 2 + (cx * cs - cy * sn) / 256;
                    y = -part->h / 2 + (cx * sn + cy * cs) / 256;
                }
            }
            if (!(part->attr & 2))
            {
                if (s->flags & 0x8000)
                    x = -x - part->w;
                if (s->flags & 0x10000)
                    y = -y - part->h;
                if (!(s->flags & 0x80000))
                {
                    w = part->w;
                    h = part->h;
                }
                else
                {
                    x -= part->w / 2;
                    y -= part->h / 2;
                    w = part->w * 2;
                    h = part->h * 2;
                }
            }
            else
            {
                w = part->w * 2;
                h = part->h * 2;
                if (s->flags & 0x8000)
                    x = -x - w;
                if (s->flags & 0x10000)
                    y = -y - h;
            }
            x += s->x / 256 + s->offX;
            y2 = y + (s->y / 256 + s->offY);
            if (s->flags & 0x1000)
            {
                x -= D_03000060[((s->flags & 0x6000) >> 13) * 2] / 256;
                y2 -= D_03000060[((s->flags & 0x6000) >> 13) * 2 + 1] / 256;
            }
            if (part->scaleX == 0x100 && part->scaleY == 0x100 && s->scaleX == 0x100 && s->scaleY == 0x100)
            {
                sw = part->w;
                sh = part->h;
            }
            else
            {
                sw = part->w * s->scaleX / 256 * part->scaleX / 256;
                sh = part->h * s->scaleY / 256 * part->scaleY / 256;
                if (sw > w)
                    sw = w;
                if (sh > h)
                    sh = h;
            }
            cx2 = x + (w - sw) / 2;
            cy2 = y2 + (h - sh) / 2;
            if (cx2 > -sw && cy2 > -sh && cx2 <= 239 && cy2 <= 159)
            {
                attr = (y2 & 0xFF) | (s->flags & 0xC00) | (u8)(D_03005714 & 0x80) | (part->attr << 8) | ((x & 0x1FF) << 16);
                switch (part->w)
                {
                case 8:
                    switch (part->h)
                    {
                    case 8:
                        break;
                    case 16:
                        attr |= 0x8000;
                        break;
                    case 32:
                        attr |= 0x40008000;
                        break;
                    }
                    break;
                case 16:
                    switch (part->h)
                    {
                    case 8:
                        attr |= 0x4000;
                        break;
                    case 16:
                        attr |= 0x40000000;
                        break;
                    case 32:
                        attr |= 0x80008000;
                        break;
                    }
                    break;
                case 32:
                    switch (part->h)
                    {
                    case 8:
                        attr |= 0x40004000;
                        break;
                    case 16:
                        attr |= 0x80004000;
                        break;
                    case 32:
                        attr |= 0x80000000;
                        break;
                    case 64:
                        attr |= 0xC0008000;
                        break;
                    }
                    break;
                case 64:
                    switch (part->h)
                    {
                    case 32:
                        attr |= 0xC0004000;
                        break;
                    case 64:
                        attr |= 0xC0000000;
                        break;
                    }
                    break;
                }
                flip = part->flip ^ ((s->flags & 0x18000) >> 15);
                if (!(part->attr & 1) && s->angle == 0 && s->scaleX == 0x100 && s->scaleY == 0x100 && !(s->flags & 0x80000))
                {
                    attr |= flip << 28;
                }
                else if (affineIdx < 32)
                {
                    mtx = &D_0300028C[affineIdx * 16 + 3];
                    if (part->angle == 0 && s->angle == 0)
                    {
                        if (!(flip & 1))
                            mtx[0] = func_080C8B80(0x1000000, s->scaleX * part->scaleX);
                        else
                            mtx[0] = -func_080C8B80(0x1000000, s->scaleX * part->scaleX);
                        mtx[4] = 0;
                        mtx[8] = 0;
                        if (!(flip & 2))
                            mtx[12] = func_080C8B80(0x1000000, s->scaleY * part->scaleY);
                        else
                            mtx[12] = -func_080C8B80(0x1000000, s->scaleY * part->scaleY);
                    }
                    else
                    {
                        sn = func_08075AAC(part->angle + s->angle);
                        cs = func_08075AF8(part->angle + s->angle);
                        if (part->scaleX == 0x100 && part->scaleY == 0x100 && s->scaleX == 0x100 && s->scaleY == 0x100)
                        {
                            if (!(flip & 1))
                            {
                                mtx[0] = cs;
                                mtx[8] = -sn;
                            }
                            else
                            {
                                mtx[0] = -cs;
                                mtx[8] = sn;
                            }
                            if (!(flip & 2))
                            {
                                mtx[4] = sn;
                                mtx[12] = cs;
                            }
                            else
                            {
                                mtx[12] = -cs;
                                mtx[4] = -sn;
                            }
                        }
                        else
                        {
                            if (!(flip & 1))
                            {
                                mtx[0] = func_080C8B80(cs << 16, s->scaleX * part->scaleX);
                                mtx[8] = -func_080C8B80(sn << 16, s->scaleY * part->scaleY);
                            }
                            else
                            {
                                mtx[0] = -func_080C8B80(cs << 16, s->scaleX * part->scaleX);
                                mtx[8] = func_080C8B80(sn << 16, s->scaleY * part->scaleY);
                            }
                            if (!(flip & 2))
                            {
                                mtx[4] = func_080C8B80(sn << 16, s->scaleX * part->scaleX);
                                mtx[12] = func_080C8B80(cs << 16, s->scaleY * part->scaleY);
                            }
                            else
                            {
                                mtx[4] = -func_080C8B80(sn << 16, s->scaleX * part->scaleX);
                                mtx[12] = -func_080C8B80(cs << 16, s->scaleY * part->scaleY);
                            }
                        }
                    }
                    matrixBits = affineIdx << 25;
                    if (s->flags & 0x80000)
                    {
                        attr |= 0x300;
                        attr |= matrixBits;
                    }
                    else
                    {
                        attr |= 0x100;
                        attr |= matrixBits;
                    }
                    affineIdx++;
                }
                *(u32 *)oam = attr;
                if (!(s->flags & 0x400000))
                {
                    oam[2] = (part->tile + s->tileBase) | (s->palette << 12) | ((s->flags & 0xC0) << 4);
                }
                else
                {
                    if (!(s->flags & 0x800000) && (s->flags & 0x1000008) != 0x1000008)
                        func_0807806C(s->gfx + part->tile * 32, (s->tileBase + tileOff) * 32 + 0x06010000, part->w * part->h / 64 * 32);
                    oam[2] = (tileOff + s->tileBase) | (s->palette << 12) | ((s->flags & 0xC0) << 4);
                }
                if (s->flags & 0x100000)
                {
                    oam += 4;
                    *(u32 *)oam = *(u32 *)(oam - 4);
                    oam[2] = oam[-2];
                    ((struct OamData *)oam)->objMode = 2;
                }
                oam += 4;
            }
            else
            {
                hidden = 1;
            }
            if (s->flags & 0x400000)
                tileOff += part->w * part->h / 64;
            part++;
        }
        goto done;
    hide:
        hidden = 1;
    done:
        if (hidden == 0)
            s->flags |= 0x1000000;
        else
            s->flags &= ~0x1000000;
        for (j = 0; j < D_03000081 && !(s->flags & 8); j++)
        {
            s->timer++;
            if (anim->duration <= s->timer)
            {
                if (anim[1].frame != -1)
                {
                    s->frameIdx++;
                    s->timer = 0;
                    s->flags &= ~0x1000000;
                    anim++;
                }
                else
                {
                    s->flags |= 4;
                    switch (s->flags & 0x30)
                    {
                    case 0:
                        s->flags &= ~1;
                        break;
                    case 0x10:
                        s->flags |= 8;
                        break;
                    case 0x20:
                        s->frameIdx = 0;
                        s->timer = 0;
                        s->flags &= ~0x1000000;
                        anim = s->anims[s->animIdx];
                        break;
                    case 0x30:
                        func_08077204(s, 0);
                        anim = s->anims[0];
                        break;
                    }
                }
            }
        }
    }
    while (oam < &D_0300028C[512])
    {
        *(u32 *)oam = 0x200;
        oam += 4;
    }
}
