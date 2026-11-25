.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C7400
.type func_080C7400, %function
.thumb
.thumb_func
func_080C7400:
.L_080C7400:
    ldr r2, [r1, #0x40]
    adds r3, r2, #1
    str r3, [r1, #0x40]
    ldrb r3, [r2]
    bx lr
    .hword 0x0000
.size func_080C7400, .-func_080C7400
