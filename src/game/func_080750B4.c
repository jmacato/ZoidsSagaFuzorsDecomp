#include "types.h"

extern u8 D_03000081;
extern u32 D_03000084;

void func_08075554(void);
void func_080C8FC4(void);
void func_08077EAC(void);
void func_08077384(void);
void func_0807A1B0(void);
void func_0807981C(void);
void func_080794B4(void);
void func_080757B8(void);
void func_080750F0(u8 frames);

void func_080750B4(void)
{
loop:
    func_08075554();
    func_080C8FC4();
    func_08077EAC();
    func_08077384();
    func_0807A1B0();
    func_0807981C();
    func_080794B4();
    func_080757B8();
    func_080750F0(D_03000081);
    D_03000084++;
    goto loop;
}
