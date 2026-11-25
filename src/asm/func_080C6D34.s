.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6D34
.type func_080C6D34, %function
.thumb
.thumb_func
func_080C6D34:
.L_080C6D34:
    ldrb r2, [r1, #2]
    cmp r2, #0
    beq .L_080C6D46
    subs r2, #1
    strb r2, [r1, #2]
    lsls r2, r2, #2
    adds r3, r1, r2
    ldr r2, [r3, #0x44]
    str r2, [r1, #0x40]
.L_080C6D46:
    bx lr
.size func_080C6D34, .-func_080C6D34
