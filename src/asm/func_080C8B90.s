.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C8B90
.type func_080C8B90, %function
.thumb
.thumb_func
func_080C8B90:
.L_080C8B90:
    ldr r3, [pc, #0x10]
    movs r2, #0
    strb r2, [r3]
    ldr r3, [pc, #0x10]
    movs r2, #0
    strb r2, [r3]
    subs r3, #0xfa
    mov sp, r3
    svc #1
    svc #0
    .word 0x04000208
    .word 0x03007FFA
.size func_080C8B90, .-func_080C8B90
