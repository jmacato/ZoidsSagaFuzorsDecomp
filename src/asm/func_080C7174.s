.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C7174
.type func_080C7174, %function
.thumb
.thumb_func
func_080C7174:
.L_080C7174:
    ldrb r1, [r4, #0x12]
    movs r0, #0x14
    ldrsb r2, [r4, r0]
    movs r3, #0x80
    adds r3, r3, r2
    muls r3, r1, r3
    ldrb r0, [r5, #0x10]
    muls r0, r3, r0
    asrs r0, r0, #0xe
    cmp r0, #0xff
    bls .L_080C718C
    movs r0, #0xff
.L_080C718C:
    strb r0, [r4, #2]
    movs r3, #0x7f
    subs r3, r3, r2
    muls r3, r1, r3
    ldrb r0, [r5, #0x11]
    muls r0, r3, r0
    asrs r0, r0, #0xe
    cmp r0, #0xff
    bls .L_080C71A0
    movs r0, #0xff
.L_080C71A0:
    strb r0, [r4, #3]
    bx lr
.size func_080C7174, .-func_080C7174
