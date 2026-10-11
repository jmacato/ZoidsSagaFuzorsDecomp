.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6C50
.type func_080C6C50, %function
.thumb
.thumb_func
func_080C6C50:
.L_080C6C50:
    mov ip, r4
    movs r1, #0
    movs r2, #0
    movs r3, #0
    movs r4, #0
    stm r0!, {r1, r2, r3, r4}
    stm r0!, {r1, r2, r3, r4}
    stm r0!, {r1, r2, r3, r4}
    stm r0!, {r1, r2, r3, r4}
    mov r4, ip
    bx lr
    .hword 0x0000
.size func_080C6C50, .-func_080C6C50
