.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C73A4
.type func_080C73A4, %function
.thumb
.thumb_func
func_080C73A4:
.L_080C73A4:
    push {r4, r5}
    ldr r2, [r1, #0x40]
    ldrb r3, [r2]
    cmp r3, #0x80
    bhs .L_080C73B6
    strb r3, [r1, #5]
    adds r2, #1
    str r2, [r1, #0x40]
    b .L_080C73B8
.L_080C73B6:
    ldrb r3, [r1, #5]
.L_080C73B8:
    ldr r1, [r1, #0x20]
    cmp r1, #0
    beq .L_080C73E0
    movs r4, #0x83
    movs r5, #0x40
.L_080C73C2:
    ldrb r2, [r1]
    tst r2, r4
    beq .L_080C73DA
    tst r2, r5
    bne .L_080C73DA
    ldrb r0, [r1, #0x11]
    cmp r0, r3
    bne .L_080C73DA
    movs r0, #0x40
    orrs r2, r0
    strb r2, [r1]
    b .L_080C73E0
.L_080C73DA:
    ldr r1, [r1, #0x34]
    cmp r1, #0
    bne .L_080C73C2
.L_080C73E0:
    pop {r4, r5}
    bx lr
.size func_080C73A4, .-func_080C73A4
