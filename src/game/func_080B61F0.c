#include "types.h"

void func_08075F20(u32);
u8 *func_080771BC(u32, u32, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(u8 *);
void func_0807A1A4(void);
void func_0807BA24(s32, u32, u32, u32, u32, u32, u32);
void func_0807BEF4(u32, u32, u32);
void func_0807C290(u32);
void func_0807DB94(u32, u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808A86C(u32);
void func_0808C9D0(void);
void func_0808C9F8(void);
void func_0808CA38(u32, u32, u32, u32);
void func_080B4D10(u32);
void func_080B4D54(void);
void func_080B4D70(void);
u32 func_080B611C(u8 *, u32, u32);
u32 func_080BD368(u32);
void func_080C0178(u8 *, u32, u32, u32, u32);
void func_080C8B7C(volatile u16 *, u32, u32);
void func_080C8E88(u32, u32, u32);
void func_080C8FCC(u32);

void func_080B61F0(u8 *argument)
{
    struct Local {
        u16 counts[2];
        u16 token;
        u16 padding;
        u8 *argument;
        u8 *object;
        u32 quit;
        u32 delta_a;
        u32 delta_b;
        u32 kind;
        u32 slot;
    };
    volatile struct Local local;
    u32 cost;
    u32 reserved7;
    register s32 current asm("r0");
    register s32 work1 asm("r1");
    register s32 work2 asm("r2");
    register s32 work3 asm("r3");
    register s32 work4 asm("r4");
    register s32 work5 asm("r5");
    register s32 state asm("r6");
    register s32 setup7 asm("r7");
    register u8 *pointer0 asm("r0");
    register u8 *pointer1 asm("r1");
    register u8 *pointer2 asm("r2");
    register u8 *pointer3 asm("r3");
    register u8 *pointer6 asm("r6");
    u8 *pointer7;
    register u32 bound7 asm("r7");
    register u8 *stack_pointer asm("sp");
    register u8 *steps asm("r8");
    register u32 selection asm("r9");
    register volatile u16 *counts asm("r10");
    register u8 *names asm("r10");

    local.argument = argument;
    pointer2 = (u8 *)0x0300004C;
    current = *(u16 *)pointer2;
    work3 = 0x200;
    asm("" : "+r"(work3));
    work1 = work3;
    asm("" : "+r"(work1));
    current |= work1;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    pointer1 = (u8 *)0x03000050;
    setup7 = 0x108;
    current = setup7;
    asm("" : "+r"(current));
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer1));
        *address = current;
    }
    pointer2 = (u8 *)0x03000052;
    work1 = *(u16 *)pointer2;
    current = 0x3FFC;
    current &= work1;
    work3 = 0x4001;
    asm("" : "+r"(work3));
    work1 = work3;
    asm("" : "+r"(work1));
    current |= work1;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    asm volatile("" : : : "r7");
    pointer0 = (u8 *)&local.token;
    pointer1 = (u8 *)0x0201F5C4;
    work1 = *(u32 *)pointer1;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer0));
        *address = work1;
        pointer0 = (u8 *)address;
    }
    work1 = 0x06000800;
    work2 = 0x01000400;
    func_080C8B7C((u16 *)pointer0, work1, work2);
    pointer1 = (u8 *)0x03000060;
    current = 0;
    *(u32 *)(pointer1 + 12) = current;
    *(u32 *)(pointer1 + 8) = current;
    current = 0x08006C68;
    func_0807C290(current);
    func_0808C9D0();
    current = 4;
    work1 = 3;
    work2 = 3;
    work3 = 1;
    func_0808CA38(current, work1, work2, work3);
    state = 4;
    setup7 = 0x0203198C;
    current = 0x087A4890;
    names = (u8 *)current;
setup:
    current = state << 2;
    pointer2 = local.argument;
    pointer1 = pointer2 + current;
    asm("" : "+r"(pointer1));
    pointer2 = pointer1;
    pointer2 += 0x76;
    work1 = *(u16 *)pointer2;
    work5 = current;
    asm("" : "+r"(work5));
    if (work1 == 0)
        goto default_style;
    current = work1 << 1;
    current += work1;
    current <<= 3;
    work3 = 0x08741EF4;
    asm("" : "+r"(work3));
    current += work3;
    current = *(u8 *)current;
    work1 = 1;
    work1 &= current;
    work4 = 4;
    current = -work1;
    asm("" : "+r"(current));
    current |= work1;
    asm("" : "+r"(current));
    current >>= 31;
    work4 &= current;
    goto draw_name;
default_style:
    work4 = 4;
draw_name:
    current = setup7;
    work1 = 0x080F5AE4;
    work2 = 7;
    func_080C8E88(current, work1, work2);
    pointer1 = local.argument;
    pointer0 = pointer1 + work5;
    pointer0 += 0x76;
    current = *(u16 *)pointer0;
    current <<= 2;
    current += (u32)names;
    work1 = *(u32 *)current;
    current = setup7;
    func_0807DB94(current, work1);
    current = 1;
    work1 = setup7;
    work2 = work4;
    func_0807BEF4(current, work1, work2);
    current = state + 1;
    current <<= 24;
    state = (u32)current >> 24;
    if ((u32)state <= 7)
        goto setup;
    state = 0;
    work2 = 0;
    local.quit = work2;
    asm volatile("" : : : "r7");
    pointer3 = (u8 *)local.counts;
    asm("" : "+r"(pointer3));
    counts = (volatile u16 *)pointer3;
loop:
    setup7 = 0x1010;
    asm("" : "+r"(setup7));
    if (state == setup7)
        goto state_1010;
    if (state > setup7)
        goto upper_state;
    if (state == 0x10)
        goto state_10;
    if (state > 0x10)
        goto initial_state;
    if (state == 0)
        goto state_0;
    goto next;
initial_state:
    current = 0x1000;
    if (state == current)
        goto state_1000;
    goto next;
upper_state:
    current = 0x1030;
    if (state == current)
        goto poll;
    if (state > current)
        goto confirm_state;
    current -= 0x10;
    if (state == current)
        goto state_1020;
    goto next;
confirm_state:
    current = 0x2000;
    if (state == current)
        goto state_2000;
    goto next;
    {
    state_0:
        func_080B4D70();
        current = 0;
        work1 = 3;
        work2 = 0x60;
        work3 = 0x58;
        func_0808A7F8(current, work1, work2, work3);
        current = 0x08006EC2;
        func_0807C290(current);
        current = 0x08006C83;
        func_0807C290(current);
        pointer0 = (u8 *)0x0200C4A2;
        asm("" : "+r"(pointer0));
        work5 = *pointer0;
        if (work5 != 1)
            goto quit;
        pointer0 = (u8 *)0x0200C4A0;
        asm("" : "+r"(pointer0));
        current = *pointer0;
        local.slot = current;
        work2 = current;
        asm("" : "+r"(work2));
        work2 += 4;
        current = work2 << 2;
        pointer1 = local.argument;
        pointer0 = pointer1 + current;
        pointer0 += 0x76;
        current = *(u16 *)pointer0;
        if (current == 0)
            goto selection_error;
        work2 = (u8)work2;
        work4 = 0x02031410;
        func_080C0178(pointer1, 0, work2, 0, work4);
        asm volatile("" : "+r"(work4));
        pointer2 = (u8 *)0x02031410;
        current = *pointer2;
        work5 &= current;
        if (work5 != 0)
            goto selection_error;
        state = 0x10;
        goto close_selection;
    selection_error:
        current = 0x114;
        func_08075F20(current);
        goto close_selection;
    quit:
        work3 = 1;
        local.quit = work3;
    close_selection:
        current = 0;
        func_0808A86C(current);
        goto next;
    state_10:
        pointer7 = local.argument;
        current = *pointer7;
        current = func_080BD368(current);
        current = (u8)current;
        local.kind = current;
        current = 0;
        local.delta_b = current;
        work1 = 0;
        local.delta_a = work1;
        pointer2 = (u8 *)counts;
        *(u16 *)(pointer2 + 2) = current;
        pointer3 = stack_pointer;
        asm("" : "+r"(pointer3));
        work3 = *(u16 *)(pointer3 + 0x2C);
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer2));
            *address = work3;
        }
        selection = work1;
        goto initial_panel;
    state_1000:
        func_080B4D54();
        current = 0x08006C8A;
        func_0807C290(current);
        current = 0;
        work1 = 3;
        work2 = 0xB0;
        work3 = 0x58;
        func_0808A7F8(current, work1, work2, work3);
        pointer7 = (u8 *)0x02031410;
        current = *(s16 *)(pointer7 + 12);
        asm volatile("" : "+r"(pointer7));
        work2 = 9;
        func_0807BA24(current, 4, 0, 0x12, work2, ({
                          work3 = 4;
                          asm("" : "+r"(work3));
                          work3;
                      }),
                      ({
                          setup7 = 2;
                          asm("" : "+r"(setup7));
                          setup7;
                      }));
        pointer1 = (u8 *)0x02031410;
        current = *(s16 *)(pointer1 + 4);
        work3 = 9;
        func_0807BA24(current, 4, 0, 0x12, work3, ({
                          setup7 = 4;
                          asm("" : "+r"(setup7));
                          setup7;
                      }),
                      setup7);
        {
            asm("" : "+r"(state));
            asm("" : "=l"(reserved7) : "0"(setup7));
            asm(""
                : "=r"(current), "=r"(work1), "=r"(work2), "=r"(work3), "=r"(work4), "=r"(work5));
            local.object =
                func_080771BC(0x080C9680, 0x080C96B4, 0, 0x18, ({
                                  current = 0;
                                  asm("" : "+r"(current));
                                  current;
                              }),
                              ({
                                  current = 0x3EE;
                                  asm("" : "+r"(current));
                                  current;
                              }),
                              ({
                                  current = 0xF;
                                  asm("" : "+r"(current));
                                  current;
                              }),
                              ({
                                  current = 0x5020;
                                  asm("" : "+r"(current));
                                  current;
                              }),
                              ({
                                  asm volatile(""
                                               :
                                               : "r"(current), "r"(work1), "r"(work2), "r"(work3),
                                                 "r"(work4), "r"(work5), "r"(state), "l"(reserved7)
                                               : "r11", "r12");
                                  work1 = 0;
                                  asm("" : "+r"(work1));
                                  work1;
                              }));
            asm volatile("" : : "l"(reserved7));
        }
        pointer0 = (u8 *)0x02020E4C;
        asm("" : "+r"(pointer0));
        work2 = 0x7A5C;
        asm("" : "+r"(work2));
        pointer0 += work2;
        current = *(u32 *)pointer0;
        work3 = 9;
        func_0807BA24(current, 9, 0, 0x12, work3, ({
                          work1 = 12;
                          asm("" : "+r"(work1));
                          work1;
                      }),
                      ({
                          work1 = 7;
                          asm("" : "+r"(work1));
                          work1;
                      }));
    refresh_name:
        state = 0x1010;
        goto next;
    state_1010:
        pointer0 = (u8 *)0x0873661C;
        asm("" : "+r"(pointer0));
        setup7 = selection;
        work1 = setup7 << 2;
        work1 += (u32)pointer0;
        current = *(u32 *)work1;
        func_0807C290(current);
        state = 0x1020;
        goto next;
    state_1020:
        work1 = selection;
        asm("" : "+r"(work1));
        current = work1 << 12;
        work2 = 0x2800;
        asm("" : "+r"(work2));
        current += work2;
        pointer3 = local.object;
        *(u32 *)(pointer3 + 8) = current;
        setup7 = local.delta_a;
        current = setup7 << 16;
        work1 = current >> 16;
        if (work1 == 0)
            goto no_sign_a;
        work2 = 1;
        if (work1 <= 0)
            goto sign_a;
        work2 = 2;
        goto sign_a;
    no_sign_a:
        work2 = 0;
    sign_a:
        func_0807BA24(work1, 4, work2, 0x16, ({
                          current = 9;
                          asm("" : "+r"(current));
                          current;
                      }),
                      ({
                          current = 17;
                          asm("" : "+r"(current));
                          current;
                      }),
                      ({
                          work3 = 2;
                          asm("" : "+r"(work3));
                          work3;
                      }));
        reserved7 = local.delta_b;
        current = reserved7 << 16;
        work1 = current >> 16;
        if (work1 == 0)
            goto no_sign_b;
        work2 = 1;
        if (work1 <= 0)
            goto sign_b;
        work2 = 2;
        goto sign_b;
    no_sign_b:
        work2 = 0;
    sign_b:
        func_0807BA24(work1, 4, work2, 0x16, ({
                          current = 9;
                          asm("" : "+r"(current));
                          current;
                      }),
                      ({
                          current = 17;
                          asm("" : "+r"(current));
                          current;
                      }),
                      ({
                          work3 = 4;
                          asm("" : "+r"(work3));
                          work3;
                      }));
        setup7 = selection;
        work1 = setup7 << 2;
        current = 0x08741EEC;
        asm("" : "+r"(current));
        work1 += current;
        steps = (u8 *)work1;
        {
            asm("" : "=l"(reserved7) : "0"(bound7));
            asm volatile(""
                         : "=r"(current), "=r"(work3), "=r"(work4), "=r"(work5), "=r"(state)
                         :
                         : "r2");
            current = *(s16 *)work1;
            asm volatile("" : : "l"(reserved7), "r"(work3), "r"(work4), "r"(work5), "r"(state));
        }
        work1 = current;
        if (work1 == 0)
            goto no_sign_step_a;
        work2 = 1;
        if (work1 <= 0)
            goto sign_step_a;
        work2 = 2;
        goto sign_step_a;
    no_sign_step_a:
        work2 = 0;
    sign_step_a:
        reserved7 = 9;
        func_0807BA24(current, 2, work2, 0x16, reserved7, reserved7, ({
                          work1 = 2;
                          asm volatile("" : : "r"(work1));
                          work1;
                      }));
        pointer2 = steps;
        {
            asm("" : "=l"(reserved7) : "0"(bound7));
            asm volatile(""
                         : "=r"(current), "=r"(work1), "=r"(work4), "=r"(work5), "=r"(state)
                         :
                         : "r3");
            current = *(s16 *)(pointer2 + 2);
            asm volatile("" : : "l"(reserved7), "r"(work1), "r"(work4), "r"(work5), "r"(state));
        }
        work1 = current;
        if (work1 == 0)
            goto no_sign_step_b;
        work2 = 1;
        if (work1 <= 0)
            goto sign_step_b;
        work2 = 2;
        goto sign_step_b;
    no_sign_step_b:
        work2 = 0;
    sign_step_b:
        work1 = 9;
        func_0807BA24(current, 2, work2, 0x16, work1, work1, ({
                          work3 = 4;
                          asm("" : "+r"(work3));
                          work3;
                      }));
        pointer7 = (u8 *)counts;
        current = *(u16 *)pointer7;
        work1 = 9;
        func_0807BA24(current, 4, 0, 0x12, work1, ({
                          work4 = 13;
                          asm("" : "+r"(work4));
                          work4;
                      }),
                      ({
                          work2 = 2;
                          asm("" : "+r"(work2));
                          work2;
                      }));
        current = *(u16 *)(pointer7 + 2);
        work3 = 9;
        func_0807BA24(current, 4, 0, 0x12, work3, work4, ({
                          setup7 = 4;
                          asm("" : "+r"(setup7));
                          setup7;
                      }));
        work2 = local.slot;
        work2 += 4;
        work2 = (u8)work2;
        pointer0 = local.argument;
        work1 = local.kind;
        current = func_080B611C(pointer0, work1, work2);
        pointer2 = (u8 *)counts;
        work1 = *(u16 *)pointer2;
        work2 = *(u16 *)(pointer2 + 2);
        work1 += work2;
        work3 = current;
        work3 *= work1;
        cost = work3;
        reserved7 = 9;
        func_0807BA24(work3, 9, 0, 0x12, reserved7, ({
                          current = 12;
                          asm("" : "+r"(current));
                          current;
                      }),
                      ({
                          current = 6;
                          asm("" : "+r"(current));
                          current;
                      }));
        func_0807A1A4();
        state = 0x1030;
        goto next;
    next_input:
        current = 0x80;
        current &= work1;
        if (current == 0)
            goto left_key;
        current = 0xCC;
        func_08075F20(current);
        current = selection;
        asm("" : "+r"(current));
        if (current != 0)
            goto choose_first;
        work1 = 1;
        asm("" : "+r"(work1));
        selection = work1;
        goto refresh_name;
    choose_first:
        work2 = 0;
        asm("" : "+r"(work2));
        selection = work2;
        goto refresh_name;
    left_key:
        current = 0x20;
        current &= work1;
        if (current == 0)
            goto right_key;
        work3 = selection;
        asm("" : "+r"(work3));
        current = work3 << 1;
        pointer6 = (u8 *)&local;
        pointer6 += current;
        current = *(u16 *)pointer6;
        if (current == 0)
            goto input_error;
        pointer7 = (u8 *)0x02031410;
        asm("" : "=r"(work2), "=r"(work3), "=r"(work4), "=r"(work5), "+r"(pointer6));
        current = *(s16 *)(pointer7 + 12);
        asm volatile(""
                     : "+r"(pointer7)
                     : "r"(work2), "r"(work3), "r"(work4), "r"(work5), "r"(pointer6));
        work2 = local.delta_a;
        work1 = work2 << 16;
        work5 = work1 >> 16;
        current += work5;
        pointer3 = steps;
        asm("" : "=r"(work2), "=r"(work4));
        work1 = *(s16 *)pointer3;
        asm volatile("" : : "r"(work2), "r"(work4));
        current -= work1;
        current--;
        work2 = 0x270E;
        asm("" : "=l"(reserved7), "=r"(work4) : "0"(bound7));
        if ((u32)current > (u32)work2)
            goto input_error;
        pointer1 = (u8 *)0x02031410;
        {
            current = *(s16 *)(pointer1 + 4);
            asm volatile("" : : "l"(reserved7), "r"(work2), "r"(work5), "r"(pointer6), "r"(work4));
        }
        reserved7 = local.delta_b;
        work1 = reserved7 << 16;
        work4 = work1 >> 16;
        current += work4;
        pointer3 = steps;
        work1 = *(s16 *)(pointer3 + 2);
        current -= work1;
        current--;
        if ((u32)current <= (u32)work2)
            goto decrease;
        goto input_error;
    right_key:
        current = 0x10;
        current &= work1;
        if (current == 0)
            goto confirm_key;
        work1 = selection;
        current = work1 << 1;
        pointer6 = (u8 *)&local;
        pointer6 += current;
        current = *(u16 *)pointer6;
        reserved7 = 0x270E;
        if ((u32)current > (u32)reserved7)
            goto input_error;
        work2 = local.slot;
        work2 += 4;
        work2 <<= 24;
        pointer0 = local.argument;
        work1 = local.kind;
        work2 = (u32)work2 >> 24;
        current = func_080B611C(pointer0, work1, work2);
        /* Reading the spill slot directly preserves agbcc's scratch register order. */
        work2 = *(u32 *)(stack_pointer + 0x38);
        current = work2 + current;
        pointer1 = (u8 *)0x02020E4C;
        work3 = 0x7A5C;
        asm("" : "+r"(pointer1), "+r"(work3));
        pointer1 += work3;
        work1 = *(u32 *)pointer1;
        if ((u32)current > (u32)work1)
            goto input_error;
        pointer1 = (u8 *)0x02031410;
        current = *(s16 *)(pointer1 + 12);
        work3 = local.delta_a;
        work1 = work3 << 16;
        work5 = work1 >> 16;
        current += work5;
        pointer2 = steps;
        work1 = *(s16 *)pointer2;
        current += work1;
        current--;
        if ((u32)current > (u32)reserved7)
            goto input_error;
        pointer1 = (u8 *)0x02031410;
        current = *(s16 *)(pointer1 + 4);
        work3 = local.delta_b;
        work1 = work3 << 16;
        work4 = work1 >> 16;
        current += work4;
        pointer2 = steps;
        work1 = *(s16 *)(pointer2 + 2);
        current += work1;
        current--;
        if ((u32)current <= (u32)reserved7)
            goto increase;
        goto input_error;
    confirm_key:
        pointer0 = (u8 *)0x0300000E;
        work1 = *(u16 *)pointer0;
        current = 1;
        current &= work1;
        if (current == 0)
            goto cancel_key;
        pointer7 = (u8 *)counts;
        current = *(u16 *)pointer7;
        if (current != 0)
            goto confirm;
        current = *(u16 *)(pointer7 + 2);
        if (current == 0)
            goto input_error;
    confirm:
        current = 0xCA;
        func_08075F20(current);
        current = 0x08006D66;
        func_0807C290(current);
        pointer0 = local.object;
        func_080771F4(pointer0);
        current = 0;
        func_0808A86C(current);
        state = 0x2000;
        goto next;
    input_error:
        current = 0x114;
        func_08075F20(current);
        goto poll;
    cancel_key:
        current = 2;
        current &= work1;
        if (current != 0)
            goto cancel;
    poll:

        current = 1;
        func_080C8FCC(current);
        pointer0 = (u8 *)0x030057EC;
        work1 = *(u16 *)pointer0;
        current = 0x40;
        current &= work1;
        if (current == 0)
            goto next_input;
        current = 0xCC;
        func_08075F20(current);
        current = selection;
        if (current == 0)
            goto choose_second;
        current--;
        current = (u8)current;
        selection = current;
        goto refresh_name;
    choose_second:
        work1 = 1;
        asm("" : "+r"(work1));
        selection = work1;
        goto refresh_name;
    state_2000:
        func_080B4D70();
        current = 0x08006D6B;
        func_0807C290(current);
        pointer2 = (u8 *)0x02031410;
        {
            asm("" : "=l"(reserved7) : "0"(bound7));
            asm volatile(""
                         : "=r"(current), "=r"(work1), "=r"(work4), "=r"(work5), "=r"(state)
                         :
                         : "r3");
            current = *(s16 *)(pointer2 + 12);
            asm volatile("" : : "l"(reserved7), "r"(work1), "r"(work4), "r"(work5), "r"(state));
        }
        setup7 = 0;
        func_0807BA24(current, 4, 0, 0x12, setup7, ({
                          work1 = 4;
                          asm volatile("" : : "r"(work1));
                          work1;
                      }),
                      setup7);
        pointer2 = (u8 *)0x02031410;
        {
            asm("" : "=l"(reserved7) : "0"(bound7));
            asm volatile(""
                         : "=r"(current), "=r"(work1), "=r"(work4), "=r"(work5), "=r"(state)
                         :
                         : "r3");
            current = *(s16 *)(pointer2 + 4);
            asm volatile("" : : "l"(reserved7), "r"(work1), "r"(work4), "r"(work5), "r"(state));
        }
        func_0807BA24(current, 4, 0, 0x12, setup7, ({
                          setup7 = 4;
                          asm("" : "+r"(setup7));
                          setup7;
                      }),
                      ({
                          work1 = 2;
                          asm("" : "+r"(work1));
                          work1;
                      }));
        work2 = local.delta_a;
        current = work2 << 16;
        work1 = current >> 16;
        work4 = current;
        asm volatile("" : "+r"(work4));
        if (work1 == 0)
            goto no_sign_confirm_a;
        work2 = 1;
        if (work1 <= 0)
            goto sign_confirm_a;
        work2 = 2;
        goto sign_confirm_a;
    no_sign_confirm_a:
        work2 = 0;
    sign_confirm_a:
        work3 = 0;
        func_0807BA24(work1, 4, work2, 0x16, work3, ({
                          current = 8;
                          asm("" : "+r"(current));
                          current;
                      }),
                      work3);
        setup7 = local.delta_b;
        current = setup7 << 16;
        work1 = current >> 16;
        state = current;
        asm volatile("" : "+r"(state));
        if (work1 == 0)
            goto no_sign_confirm_b;
        work2 = 1;
        if (work1 <= 0)
            goto sign_confirm_b;
        work2 = 2;
        goto sign_confirm_b;
    no_sign_confirm_b:
        work2 = 0;
    sign_confirm_b:
        func_0807BA24(work1, 4, work2, 0x16, ({
                          current = 0;
                          asm("" : "+r"(current));
                          current;
                      }),
                      ({
                          work5 = 8;
                          asm("" : "+r"(work5));
                          work5;
                      }),
                      ({
                          work3 = 2;
                          asm("" : "+r"(work3));
                          work3;
                      }));
        pointer7 = (u8 *)0x02031410;
        asm("" : "=r"(work2), "=r"(work3));
        current = *(s16 *)(pointer7 + 12);
        asm volatile("" : : "r"(work2), "r"(work3));
        asm volatile("" : "+r"(pointer7));
        setup7 = work4 >> 16;
        current += setup7;
        work2 = 0;
        func_0807BA24(current, 4, work2, 0x12, work2, ({
                          work4 = 14;
                          asm("" : "+r"(work4));
                          work4;
                      }),
                      work2);
        pointer3 = (u8 *)0x02031410;
        asm("" : "+r"(pointer3));
        asm("" : "=r"(work2));
        current = *(s16 *)(pointer3 + 4);
        asm volatile("" : : "r"(work2));
        state >>= 16;
        current += state;
        work2 = 0;
        func_0807BA24(current, 4, work2, 0x12, work2, work4, ({
                          work3 = 2;
                          asm("" : "+r"(work3));
                          work3;
                      }));
        func_0807BA24(cost, 9, 0, 0x12, ({
                          current = 0;
                          asm("" : "+r"(current));
                          current;
                      }),
                      work5, ({
                          work1 = 4;
                          asm("" : "+r"(work1));
                          work1;
                      }));
        current = 0x08006E7E;
        func_0807C290(current);
        pointer0 = (u8 *)0x0200C4A2;
        current = *pointer0;
        if (current != 1)
            goto initial_panel;
        pointer0 = (u8 *)0x0200C4A0;
        asm("" : "+r"(pointer0));
        current = *pointer0;
        if (current != 0)
            goto initial_panel;
        current = 0xDA;
        func_08075F20(current);
        work3 = local.slot;
        work2 = work3 << 1;
        work1 = local.kind;
        current = work1 << 3;
        work2 += current;
        pointer1 = local.argument;
        pointer1 += 0x12;
        pointer1 += work2;
        current = *(u16 *)pointer1;
        current = setup7 + current;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = current;
        }
        pointer1 = local.argument;
        pointer1 += 0x3A;
        pointer1 += work2;
        current = *(u16 *)pointer1;
        current = state + current;
        {
            u16 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = current;
        }
        pointer1 = (u8 *)0x02020E4C;
        asm("" : "+r"(pointer1));
        work2 = 0x7A5C;
        asm("" : "+r"(work2));
        pointer1 += work2;
        current = *(u32 *)pointer1;
        work3 = cost;
        asm("" : "+r"(work3));
        current -= work3;
        {
            u32 *address;
            asm("" : "=r"(address) : "0"(pointer1));
            *address = current;
        }
        current = 8;
        func_080B4D10(current);
        current = 0x08006EF6;
        func_0807C290(current);
        state = 0;
        goto next;
    decrease:
        current = 0xCC;
        func_08075F20(current);
        pointer7 = steps;
        current = *(u16 *)pointer7;
        current = work5 - current;
        current = (u16)current;
        local.delta_a = current;
        current = *(u16 *)(pointer7 + 2);
        current = work4 - current;
        current = (u16)current;
        local.delta_b = current;
        current = *(u16 *)pointer6;
        current--;
        goto store_count;
    increase:
        current = 0xCC;
        func_08075F20(current);
        pointer1 = steps;
        current = *(u16 *)pointer1;
        current = work5 + current;
        current = (u16)current;
        local.delta_a = current;
        current = *(u16 *)(pointer1 + 2);
        current = work4 + current;
        current = (u16)current;
        local.delta_b = current;
        current = *(u16 *)pointer6;
        current++;
    store_count: {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer6));
        *address = current;
    }
        state = 0x1020;
        goto next;
    cancel:
        current = 0xCB;
        func_08075F20(current);
        current = 0x08006D66;
        func_0807C290(current);
        pointer0 = local.object;
        func_080771F4(pointer0);
        current = 0;
        func_0808A86C(current);
        state = 0;
        goto next;
    initial_panel:
        state = 0x1000;
        goto next;
    }
next:
    work2 = local.quit;
    if (work2 == 0)
        goto loop;
    current = 0x08006C87;
    func_0807C290(current);
    func_0808C9F8();
    pointer2 = (u8 *)0x0300004C;
    work1 = *(u16 *)pointer2;
    current = 0xFDFF;
    current &= work1;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
    pointer2 = (u8 *)0x03000052;
    work1 = *(u16 *)pointer2;
    current = 0x3FFC;
    current &= work1;
    {
        u16 *address;
        asm("" : "=r"(address) : "0"(pointer2));
        *address = current;
    }
}
