.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6E7C
.type func_080C6E7C, %function
.thumb
.thumb_func
func_080C6E7C:
.L_080C6E7C:
    ldr r0, [pc, #0x2a8]
    ldr r0, [r0]
    ldr r2, [pc, #0x2a8]
    ldr r3, [r0]
    subs r3, r3, r2
    cmp r3, #1
    bhi .L_080C6EBC
    ldrb r1, [r0, #4]
    subs r1, #1
    strb r1, [r0, #4]
    bgt .L_080C6EBC
    ldrb r1, [r0, #0xb]
    strb r1, [r0, #4]
    ldr r2, [pc, #0x28]
    ldr r1, [r2, #8]
    lsls r1, r1, #7
    blo .L_080C6EA2
    ldr r1, [pc, #0x24]
    str r1, [r2, #8]
.L_080C6EA2:
    ldr r1, [r2, #0x14]
    lsls r1, r1, #7
    blo .L_080C6EAC
    ldr r1, [pc, #0x18]
    str r1, [r2, #0x14]
.L_080C6EAC:
    movs r1, #4
    lsls r1, r1, #8
    strh r1, [r2, #0xa]
    strh r1, [r2, #0x16]
    movs r1, #0xb6
    lsls r1, r1, #8
    strh r1, [r2, #0xa]
    strh r1, [r2, #0x16]
.L_080C6EBC:
    bx lr
    .hword 0x0000
    .word 0x040000BC
    .word 0x84400004
.size func_080C6E7C, .-func_080C6E7C
