.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6D48
.type func_080C6D48, %function
.thumb
.thumb_func
func_080C6D48:
.L_080C6D48:
    push {lr}
    ldr r2, [r1, #0x40]
    ldrb r3, [r2]
    cmp r3, #0
    bne .L_080C6D58
    adds r2, #1
    str r2, [r1, #0x40]
    .hword 0xE7D0 @ b #0x80c6cfa
.L_080C6D58:
    ldrb r3, [r1, #3]
    adds r3, #1
    strb r3, [r1, #3]
    mov ip, r3
    bl func_080C6CEC
    cmp ip, r3
    bhs .L_080C6D6A
    .hword 0xE7C7 @ b #0x80c6cfa
.L_080C6D6A:
    movs r3, #0
    strb r3, [r1, #3]
    adds r2, #5
    str r2, [r1, #0x40]
    pop {r0}
    bx r0
    .hword 0x0000
.size func_080C6D48, .-func_080C6D48
