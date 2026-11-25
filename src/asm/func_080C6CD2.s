.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6CD2
.type func_080C6CD2, %function
.thumb
.thumb_func
func_080C6CD2:
.L_080C6CD2:
    push {r0}
    lsrs r0, r2, #0x19
    bne .L_080C6CE4
    ldr r0, [pc, #0xc]
    cmp r2, r0
    blo .L_080C6CE2
    lsrs r0, r2, #0xe
    beq .L_080C6CE4
.L_080C6CE2:
    movs r3, #0
.L_080C6CE4:
    pop {r0}
    bx lr
    .word 0x0863DF9C
.size func_080C6CD2, .-func_080C6CD2
