.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C7130
.type func_080C7130, %function
.thumb
.thumb_func
func_080C7130:
.L_080C7130:
    push {r4, r5, r6, lr}
    adds r5, r1, #0
    ldrb r1, [r5]
    movs r0, #0x80
    tst r0, r1
    beq .L_080C7168
    ldr r4, [r5, #0x20]
    cmp r4, #0
    beq .L_080C7166
    movs r6, #0
.L_080C7144:
    ldrb r0, [r4]
    cmp r0, #0
    beq .L_080C715E
    ldrb r0, [r4, #1]
    movs r3, #7
    ands r0, r3
    beq .L_080C715C
    ldr r3, [pc, #0x1c]
    ldr r3, [r3]
    ldr r3, [r3, #0x2c]
    bl func_080C7120
.L_080C715C:
    strb r6, [r4]
.L_080C715E:
    str r6, [r4, #0x2c]
    ldr r4, [r4, #0x34]
    cmp r4, #0
    bne .L_080C7144
.L_080C7166:
    str r4, [r5, #0x20]
.L_080C7168:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .hword 0x0000
    .word 0x03007FF0
.size func_080C7130, .-func_080C7130
