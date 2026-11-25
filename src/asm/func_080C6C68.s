.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6C68
.type func_080C6C68, %function
.thumb
.thumb_func
func_080C6C68:
.L_080C6C68:
    ldr r3, [r0, #0x2c]
    cmp r3, #0
    beq .L_080C6C86
    ldr r1, [r0, #0x34]
    ldr r2, [r0, #0x30]
    cmp r2, #0
    beq .L_080C6C7A
    str r1, [r2, #0x34]
    b .L_080C6C7C
.L_080C6C7A:
    str r1, [r3, #0x20]
.L_080C6C7C:
    cmp r1, #0
    beq .L_080C6C82
    str r2, [r1, #0x30]
.L_080C6C82:
    movs r1, #0
    str r1, [r0, #0x2c]
.L_080C6C86:
    bx lr
.size func_080C6C68, .-func_080C6C68
