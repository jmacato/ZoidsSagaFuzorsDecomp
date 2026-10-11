#include "types.h"

extern u8 D_0203116B;
extern u8 D_020310A3[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern const u8 *D_087A5730[];
extern const u8 D_080032F2[];
extern const u8 D_08000C01[];
extern const u8 D_080032B5[];
extern const u8 D_080032E9[];
extern const u8 D_080032ED[];
void func_0808A6DC(u32);
void func_08075F20(u32);
void func_0807C290(const u8 *);
void func_0808AC08(void);
void func_0808B180(u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0807BD4C(u32);
void func_0807B77C(const u8 *, u32, u32);
void func_0808A86C(u32);
void func_0808AB28(void);

u32 func_080900B0(void)
{
    u8 i;

    func_0808A6DC(0);
    if (D_0203116B == 0)
    {
        func_08075F20(0x114);
        func_0807C290(D_080032F2);
        return 0;
    }
    func_0808AC08();
    func_0807C290(D_08000C01);
    func_0807C290(D_080032B5);
    func_0808B180(5);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    i = 0;
    do
    {
        func_0807BD4C(6);
        func_0807B77C(D_087A5730[D_020310A3[i * 2]], 0, 6);
        func_0807C290(D_080032E9);
        i = D_0200C4A0;
    } while (D_0200C4A2 != 2);
    func_0807C290(D_080032ED);
    func_0808A86C(0);
    func_0808AB28();
    return 1;
}
