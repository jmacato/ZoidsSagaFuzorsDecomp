.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C73E4
.type func_080C73E4, %function
.thumb
.thumb_func
func_080C73E4:
.L_080C73E4:
    movs r2, #0
    strb r2, [r1, #0x16]
    strb r2, [r1, #0x1a]
    ldrb r2, [r1, #0x18]
    cmp r2, #0
    bne .L_080C73F4
    movs r2, #0xc
    b .L_080C73F6
.L_080C73F4:
    movs r2, #3
.L_080C73F6:
    ldrb r3, [r1]
    orrs r3, r2
    strb r3, [r1]
    bx lr
    .hword 0x0000
.size func_080C73E4, .-func_080C73E4
