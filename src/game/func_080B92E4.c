#include "types.h"

struct State
{
  u32 *field_0;
  u8 cursor;
  u8 flag;
  u8 pad_6[0x85];
  u8 dirty;
};

struct Unit
{
  u8 pad_0[0x1CF4];
  u8 field_1CF4;
  u8 pad_1CF5;
  u8 field_1CF6;
};

void func_08091DB4(void);

void func_080B926C(void);

void func_08079544(s32, s32);

void func_0807970C(void);

void func_080C8FCC(s32);

void func_08075F20(u16);

void func_080B9154(void);

void func_080B92C0(void);

void func_080B8E90(u8);

void func_0807C290(const void *);

void func_080B9014(u8);

void func_0807DAEC(void);

void func_0807DB38(void);

void func_0807DB84(void);

void func_0807DAA0(void);

void func_0807EC08(void);

void func_0807EC28(void);

void func_0807EC70(void);

void func_0807EB78(void);

void func_0807560C(void);

u8 func_0807DAFC(void);

void func_080755F4(void);

void func_0807A1A4(void);

extern struct State D_02030A40;

extern u8 D_02030ACB;

extern u16 D_030057EC;

extern u16 D_0300000E;

struct Opts
{
  u16 flags;
};

extern struct Opts D_02030584;

extern struct Unit D_02009480;

extern u8 D_0200C4A0;

extern u8 D_0200C4A1;

extern u8 D_0200C4A2;

extern u8 D_0201F5F4;

extern const u8 D_08005B48[];

extern const u8 D_08005C37[];

extern const u8 D_08005AD8[];

extern const u8 D_08005B1B[];

extern const u8 D_08005D02[];

extern const u8 D_08005D3E[];

extern const u8 D_08005D5D[];

extern const u8 D_08005D60[];

extern const u8 D_08005D82[];

void func_080B92E4(u8 flag)
{
  u16 up;
  u8 x;
  u8 y;
  u8 ok;
  D_02030A40.flag = flag;
  func_08091DB4();
  {
    register __typeof__(&D_02030A40.dirty) t15 asm("r6") = &D_02030A40.dirty;
    *t15 = 0;
  }
  D_02030A40.cursor = 0;
  func_080B926C();
  func_08079544(0xF, 0);
  func_0807970C();
  for (;;)
  {
    func_080C8FCC(1);
    up = D_030057EC & 0x40;
    if (up)
    {
      func_08075F20(0xCC);
      if (D_02030A40.cursor != 0)
        D_02030A40.cursor--;
      else
        D_02030A40.cursor = 4;
      func_080B9154();
    }
    else
      if (D_030057EC & 0x80)
    {
      func_08075F20(0xCC);
      if (D_02030A40.cursor <= 3)
        D_02030A40.cursor++;
      else
        D_02030A40.cursor = 0;
      func_080B9154();
    }
    else
      if (D_0300000E & 0x20)
    {
      if ((D_02030A40.cursor == 0) && (D_02030584.flags & 1))
      {
        D_02030584.flags &= ~1;
        func_08075F20(0xCC);
        func_080B9154();
        D_02030ACB = 1;
      }
      else
        if ((D_02030A40.cursor == 1) && (D_02030584.flags & 2))
      {
        D_02030584.flags &= ~2;
        func_08075F20(0xCC);
        func_080B9154();
        D_02030ACB = 1;
      }
    }
    else
      if (D_0300000E & 0x10)
    {
      if ((D_02030A40.cursor == 0) && (!(D_02030584.flags & 1)))
      {
        D_02030584.flags |= 1;
        func_08075F20(0xCC);
        func_080B9154();
        D_02030ACB = 1;
      }
      else
        if ((D_02030A40.cursor == 1) && (!(D_02030584.flags & 2)))
      {
        D_02030584.flags |= 2;
        func_08075F20(0xCC);
        func_080B9154();
        D_02030ACB = 1;
      }
    }
    else
      if (D_0300000E & 1)
    {
      if (D_02030A40.cursor == 2)
      {
        func_08075F20(0xCA);
        func_080B92C0();
        func_080B8E90(0);
        func_080B926C();
        D_02030ACB = 1;
      }
      else
        if (D_02030A40.cursor == 3)
      {
        func_08075F20(0xCA);
        *D_02030A40.field_0 |= 0x20000;
        x = 0;
        y = 0;
        while (1)
        {
          func_0807C290(D_08005B48);
          D_02009480.field_1CF4 = y;
          D_02009480.field_1CF6 = x;
          func_0807C290(D_08005C37);
          if (D_0200C4A2 != 1)
            break;
          y = D_0200C4A1;
          x = D_0200C4A0;
          func_080B92C0();
          func_080B9014(x);
          func_080B926C();
          *D_02030A40.field_0 |= 0x20000;
          D_02030A40.dirty = 1;
        }

        *D_02030A40.field_0 &= ~0x20000;
        func_080B9154();
      }
      else
        if (D_02030A40.cursor == 4)
      {
        func_08075F20(0xCA);
        if (D_02030A40.flag != 0)
        {
          *D_02030A40.field_0 |= 0x20000;
          if (D_0201F5F4 == 0)
          {
            func_08075F20(0x114);
          }
          else
          {
            func_0807C290(D_08005AD8);
            if ((D_0200C4A2 == 1) && (D_0200C4A0 == 0))
            {
              func_0807DAEC();
              func_0807DB38();
              func_0807DB84();
              func_0807DAA0();
              func_0807EC08();
              func_0807EC28();
              func_0807EC70();
              func_0807EB78();
              D_0201F5F4 = 0;
              func_0807C290(D_08005B1B);
            }
          }
          func_080B9154();
          *D_02030A40.field_0 &= ~0x20000;
        }
        else
        {
          func_08075F20(0x114);
        }
      }
      else
      {
        func_08075F20(0x114);
      }
    }
    else
      if (D_0300000E & 2)
    {
      break;
    }
  }

  func_08075F20(0xCB);
  if ((D_02030A40.flag != 0) && (D_02030A40.dirty != 0))
  {
    func_0807C290(D_08005D02);
    if ((D_0200C4A2 == 1) && (D_0200C4A0 == 0))
    {
      func_0807C290(D_08005D3E);
      func_0807560C();
      ok = func_0807DAFC();
      func_080755F4();
      func_0807C290(D_08005D5D);
      if (ok)
      {
        func_08075F20(0xC9);
        func_0807C290(D_08005D60);
      }
      else
      {
        func_08075F20(0x114);
        func_0807C290(D_08005D82);
      }
      func_0807A1A4();
    }
  }
  func_08079544(0x10, 0);
  func_0807970C();
}
