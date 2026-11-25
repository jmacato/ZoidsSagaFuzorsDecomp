.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6CB8
.type func_080C6CB8, %function
.thumb
.thumb_func
func_080C6CB8:
.L_080C6CB8:
    mov ip, lr
    movs r1, #0x24
    ldr r2, [pc, #0x28]
.L_080C6CBE:
    ldr r3, [r2]
    bl func_080C6CD2
    stm r0!, {r3}
    adds r2, #4
    subs r1, #1
    bgt .L_080C6CBE
    bx ip
    .hword 0x0000
.size func_080C6CB8, .-func_080C6CB8
