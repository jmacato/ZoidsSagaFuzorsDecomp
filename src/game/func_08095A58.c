#include "types.h"

struct Move
{
  u16 field_0;
  u16 id;
};

struct Zoid
{
  u8 pad_0[8];
  u16 hp;
  u8 pad_A[0x5A];
  s16 maxhp;
  u8 pad_66[0xE];
  struct Move moves[8];
};

struct Header
{
  u8 flags;
  u8 pad_1[3];
  s16 cost;
  u8 pad_6;
  u8 kind;
  u8 pad_8[0x10];
};

struct Pilot
{
  struct Header head;
  u8 pad_18[0x258];
};

struct Unit
{
  u8 id;
  u8 pad_1[0x107];
};

struct Battle
{
  u8 pad_0[0x245];
  u8 slot;
  u8 pad_246[6];
  struct Zoid *zoid;
  void *field_250;
  u8 field_254;
  u8 pad_255[3];
  struct Unit units[30];
  u8 pad_2148[0x220E - 0x2148];
  u8 tbl[10][3];
  struct Pilot pilots[8];
  u8 pad_35AC[0x4EF8 - 0x35AC];
  s32 field_4EF8;
  u8 pad_4EFC[0x4F50 - 0x4EFC];
  s8 field_4F50;
  u8 pad_4F51[0x4F85 - 0x4F51];
  u8 cmds[3];
};

struct Win
{
  u32 flags;
  u8 pad_4[0x4CC];
};

struct Unk02036E7C
{
  u8 pad_0[0x8A8];
  u32 field_8A8;
};

extern struct Battle D_02031A0C;

extern struct Win D_02009480[];

extern struct Unk02036E7C D_02036E7C;

extern struct Header D_02031410;

extern u8 D_02031428[];

extern u16 D_0300000E;

extern u16 D_030057EC;

extern u8 D_0200C4A0;

extern u8 D_0200C4A2;

extern u32 (*D_03000010)(void);

extern const u8 *D_087A4890[];

extern const u8 D_087B4C9C[];

extern const u8 D_080F339C[];

extern const u8 D_080F3560[];

extern const u8 D_08005598[];

extern const u8 D_08005681[];

extern const u8 D_080055CE[];

extern const u8 D_08005705[];

extern const u8 D_08005730[];

extern const u8 D_0800574D[];

extern const u8 D_08005772[];

extern const u8 D_080057A1[];

extern const u8 D_080057C8[];

extern const u8 D_080056EC[];

extern const u8 D_080056C1[];

extern const u8 D_080057ED[];

extern const u8 D_080056A0[];

extern const u8 D_08005607[];

extern const u8 D_080055D4[];

s32 func_080A1B9C(void);

void func_080C8FCC(u32);

u8 func_08094BF8(s8, s8);

void func_08094284(u8);

void func_0807FF9C(const void *, u8, u16, u16);

void func_0808BB28(void);

void func_0807C290(const u8 *);

void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);

void func_080943A8(u8);

void func_080C8B84(const void *, void *);

void func_0808BB48(void);

s32 func_080C280C(u8, u8, void *, struct Header *);

void func_080C0178(struct Zoid *, void *, u8, u8, u8 *);

void func_0808BCA8(u32, struct Header *, u8 *, u32);

void func_0807B748(const u8 *, u32, u32, u32, u32);

void func_08094534(u8);

void func_080A12B0(u8, s32);

void func_080947E8(void);

void func_08075F20(u32);

s32 func_08095680(struct Header *, u8);

u8 func_08094D98(u8, u8, s8, s8, u8);

void func_0809499C(u8);

void func_08095380(u8);

void func_0809459C(u8, u8, struct Header *);

void func_08095460(u8, u8, u8);

void func_08094B08(void);

void func_0809543C(void);

void func_08094970(void);

void func_0809555C(void);

void func_08095624(void);

void func_08094944(void);

void func_08094920(void);

void func_0807A1A4(void);

s32 func_08095A58(void)
{
  u8 mode;
  u8 count;
  s16 hp;
  u8 cur;
  s32 state;
  s32 r;
  s32 e2;
  u8 n;
  u8 sel;
  u8 old;
  u8 i;
  u8 e;
  const u8 *msg;
  while ((!func_080A1B9C()) && (!(D_0300000E & 3)))
    func_080C8FCC(1);

  D_02036E7C.field_8A8 = 0x1000;
  count = 0;
  cur = D_02031A0C.tbl[D_02031A0C.units[D_02031A0C.slot].id][count];
  if (cur == 0xFF)
    cur = 0;
  for (i = 0; i < 3; i++)
    D_02031A0C.cmds[i] |= 0xFF;

  hp = D_02031A0C.zoid->hp;
  D_02009480[1].flags &= ~0x10;
  cur = func_08094BF8(cur, 1);
  func_08094284(cur);
  func_0807FF9C(D_087B4C9C, 1, 0x330, 0xB);
  func_0808BB28();
  state = 0;
  while (1)
  {
    switch (state)
    {
      case 0:
        func_0807C290(D_08005598);
        func_0807BA24(hp, 4, 0, 0x12, 3, 4, 0);
        func_0807BA24(D_02031A0C.zoid->maxhp, 4, 0, 0x12, 3, 9, 0);
        func_080943A8(0);
        func_080C8B84(D_080F339C, (void *) 0x06013000);
        func_080C8B84(D_080F3560, (void *) 0x05000260);
        state = 0x10;
        break;

      case 0x10:
        func_0808BB48();
        D_02031410 = *((struct Header *) (&D_02031A0C.pilots[cur]));
        e2 = func_080C280C(count, cur, D_02031A0C.cmds, &D_02031410);
        func_080C0178(D_02031A0C.zoid, D_02031A0C.field_250, cur, 1, D_02031428);
        func_0808BCA8(2, &D_02031410, D_02031428, 2);
        if (e2 == 0)
        func_0807B748(D_087A4890[D_02031A0C.zoid->moves[cur].id], 0, 2, 0, e2);
      else
        func_0807B748(D_087A4890[e2 + 0x32B], 0, 2, 0, 0);
        func_0807C290(D_08005681);
        func_08094534(cur);
        func_080A12B0(4, D_02031A0C.field_4EF8);
        state = 0x20;
        break;

      case 0x20:
        func_080947E8();
        func_080C8FCC(1);
        if (D_030057EC & 0x60)
      {
        n = func_08094BF8(cur - 1, -1);
        if (n != 0xFF)
        {
          func_08075F20(0xCC);
          cur = n;
          state = 0x10;
        }
      }
      else
        if (D_030057EC & 0x90)
      {
        n = func_08094BF8(cur + 1, 1);
        if (n != 0xFF)
        {
          func_08075F20(0xCC);
          cur = n;
          state = 0x10;
        }
      }
      else
        if (D_0300000E & 1)
      {
        func_08075F20(0xCA);
        state = 0x1000;
      }
      else
        if (D_0300000E & 2)
      {
        func_08075F20(0xCB);
        if (count != 0)
        {
          func_0808BB48();
          func_0807C290(D_080055CE);
          state = 0x3010;
        }
        else
        {
          return -1;
        }
      }
        break;

      case 0x1000:
        r = func_08095680(&D_02031410, cur);
        switch (r)
      {
        case 1:
          func_08075F20(0x114);
          func_0807C290(D_08005705);
          state = 0x20;
          break;

        case 2:
          func_08075F20(0x114);
          func_0807C290(D_08005730);
          state = 0x20;
          break;

        case 3:
          func_08075F20(0x114);
          func_0807C290(D_0800574D);
          state = 0x20;
          break;

        case 4:
          func_08075F20(0x114);
          func_0807C290(D_08005772);
          state = 0x20;
          break;

        case 6:
          func_08075F20(0x114);
          func_0807C290(D_080057A1);
          state = 0x20;
          break;

        case 7:
          func_08075F20(0x114);
          func_0807C290(D_080057C8);
          state = 0x20;
          break;

        default:
          if (hp < D_02031410.cost)
        {
          func_08075F20(0x114);
          func_0807C290(D_080056EC);
          state = 0x20;
          break;
        }
          if (!(D_02031410.flags & 1))
            mode = 1;
          else
            mode = 0;
          sel = func_08094D98(mode, 0xFF, 0, 0, cur);
          if (sel == 0xFF)
        {
          func_08075F20(0x114);
          func_0807C290(D_080056C1);
          state = 0x20;
          break;
        }
          func_0808BB48();
          func_0807C290(D_080055CE);
          if (r == 5)
        {
          func_0807C290(D_080057ED);
          if ((D_0200C4A2 == 2) || (D_0200C4A0 != 0))
          {
            state = 0;
            break;
          }
        }
          state = 0x2000;
          break;

      }

        break;

      case 0x2000:
        if (((u8) (D_02031410.kind - 6)) > 1)
      {
        func_0807C290(D_080056A0);
        func_0809499C(mode);
        func_08095380(mode);
        func_080943A8(1);
        state = 0x2010;
      }
      else
      {
        if (D_02031410.kind == 7)
          sel = D_02031A0C.slot;
        else
          sel = 0;
        state = 0x3000;
      }
        break;

      case 0x2010:
        func_0809459C(mode, sel, &D_02031410);
        func_08095460(mode, sel, cur);
        state = 0x2020;
        break;
        case 0x2020:
          func_080947E8();

        func_08094B08();
        func_080C8FCC(1);
        if (D_030057EC & 0x40)
        {
          old = sel;
          sel = func_08094D98(mode, old, 0, -1, cur);
          if (sel != old)
            func_08075F20(0xCC);
          state = 0x2010;
        }
        else
          if (D_030057EC & 0x80)
        {
          old = sel;
          sel = func_08094D98(mode, old, 0, 1, cur);
          if (sel != old)
            func_08075F20(0xCC);
          state = 0x2010;
        }
        else
          if (D_030057EC & 0x20)
        {
          old = sel;
          sel = func_08094D98(mode, old, -1, 0, cur);
          if (sel != old)
            func_08075F20(0xCC);
          state = 0x2010;
        }
        else
          if (D_030057EC & 0x10)
        {
          old = sel;
          sel = func_08094D98(mode, old, 1, 0, cur);
          if (sel != old)
            func_08075F20(0xCC);
          state = 0x2010;
        }
        else
          if (D_0300000E & 3)
        {
          if (D_0300000E & 1)
          {
            func_08075F20(0xCA);
            state = 0x3000;
          }
          else
          {
            func_08075F20(0xCB);
            state = 0;
          }
          func_0809543C();
          D_02031A0C.field_4F50 = -1;
          while (D_02031A0C.field_4F50 != 0)
          {
            func_08094B08();
            func_080C8FCC(1);
          }
        }
        break;

      case 0x3000:
        D_02031A0C.cmds[count] = ((((D_03000010() * 3) >> 15) << 6) | (sel << 3)) | cur;
        hp -= D_02031410.cost;
        count++;
        state = 0x3010;
        break;

      case 0x3010:
        func_08094970();
        func_0809555C();
        cur = D_02031A0C.tbl[D_02031A0C.units[D_02031A0C.slot].id][count];
        if (cur == 0xFF)
        cur = 0;
        if ((count == D_02031A0C.field_254) || ((n = func_08094BF8(cur, 1)) == 0xFF))
      {
        func_0807C290(D_08005607);
        func_08095624();
        if ((D_0200C4A2 == 1) && (D_0200C4A0 == 0))
        {
          state = 0x3020;
          break;
        }
      }
      else
      {
        func_0807C290(D_080055D4);
        func_08095624();
        if ((D_0200C4A2 == 1) && (D_0200C4A0 != 2))
        {
          if (D_0200C4A0 != 0)
          {
            state = 0x3020;
            break;
          }
          cur = n;
          func_08094944();
          state = 0;
          break;
        }
      }
        count--;
        e = D_02031A0C.cmds[count];
        cur = e & 7;
        sel = (e >> 3) & 7;
        D_02031A0C.cmds[count] = 0xFF;
        D_02031410 = *((struct Header *) (&D_02031A0C.pilots[cur]));
        func_080C280C(count, cur, D_02031A0C.cmds, &D_02031410);
        hp += D_02031410.cost;
        func_08094944();
        func_08094534(cur);
        func_080A12B0(4, D_02031A0C.field_4EF8);
        state = (((u8) (D_02031410.kind - 6)) > 1) ? (0x2000) : (0);
        break;

      case 0x3020:
        func_08094920();
        func_0807A1A4();
        for (i = 0; i < count; i++)
        D_02031A0C.tbl[D_02031A0C.units[D_02031A0C.slot].id][i] = D_02031A0C.cmds[i] & 7;

        for (; i < 3; i++)
        D_02031A0C.tbl[D_02031A0C.units[D_02031A0C.slot].id][i] |= 0xFF;

        return 1;

    }

  }

}
