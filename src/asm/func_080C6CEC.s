.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6CEC
.type func_080C6CEC, %function
.thumb
.thumb_func
func_080C6CEC:
.L_080C6CEC:
    ldr r2, [r1, #0x40]
    adds r3, r2, #1
    str r3, [r1, #0x40]
    ldrb r3, [r2]
    .hword 0xE7ED @ b #0x80c6cd2
    .hword 0x0000
.size func_080C6CEC, .-func_080C6CEC
