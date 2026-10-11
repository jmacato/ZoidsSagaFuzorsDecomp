.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6828
.type func_080C6828, %function
.thumb
.thumb_func
func_080C6828:
.L_080C6828:
    ldr r0, [pc, #0x68]
    ldr r0, [r0]
    ldr r2, [pc, #0x68]
    ldr r3, [r0]
    cmp r2, r3
    beq .L_080C6836
    bx lr
.L_080C6836:
    adds r3, #1
    str r3, [r0]
    push {r4, r5, r6, r7, lr}
    mov r1, r8
    mov r2, sb
    mov r3, sl
    mov r4, fp
    push {r0, r1, r2, r3, r4}
    sub sp, #0x18
    ldrb r1, [r0, #0xc]
    cmp r1, #0
    beq .L_080C685A
    ldr r2, [pc, #0x50]
    ldrb r2, [r2]
    cmp r2, #0xa0
    bhs .L_080C6858
    adds r2, #0xe4
.L_080C6858:
    adds r1, r1, r2
.L_080C685A:
    str r1, [sp, #0x14]
    ldr r3, [r0, #0x20]
    cmp r3, #0
    beq .L_080C686A
    ldr r0, [r0, #0x24]
    bl func_080C6C4A
    ldr r0, [sp, #0x18]
.L_080C686A:
    ldr r3, [r0, #0x28]
    bl func_080C6C4A
    ldr r0, [sp, #0x18]
    ldr r3, [r0, #0x10]
    mov r8, r3
    ldr r5, [pc, #0x2c]
    adds r5, r5, r0
    ldrb r4, [r0, #4]
    subs r7, r4, #1
    bls .L_080C688A
    ldrb r1, [r0, #0xb]
    subs r1, r1, r7
    mov r2, r8
    muls r2, r1, r2
    adds r5, r5, r2
.L_080C688A:
    str r5, [sp, #8]
    ldr r6, [pc, #0x18]
    ldr r3, [pc, #0xc]
    bx r3
    .hword 0x0000
    .word 0x03007FF0
    .word 0x68736D53
    .word 0x030076F9
    .word 0x04000006
    .word 0x00000350
    .word 0x00000630
.size func_080C6828, .-func_080C6828
