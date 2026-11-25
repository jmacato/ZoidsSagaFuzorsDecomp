.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C6C88
.type func_080C6C88, %function
.thumb
.thumb_func
func_080C6C88:
.L_080C6C88:
    push {r4, r5, lr}
    adds r5, r1, #0
    ldr r4, [r5, #0x20]
    cmp r4, #0
    beq .L_080C6CAC
.L_080C6C92:
    ldrb r1, [r4]
    movs r0, #0xc7
    tst r0, r1
    beq .L_080C6CA0
    movs r0, #0x40
    orrs r1, r0
    strb r1, [r4]
.L_080C6CA0:
    adds r0, r4, #0
    bl func_080C6C68
    ldr r4, [r4, #0x34]
    cmp r4, #0
    bne .L_080C6C92
.L_080C6CAC:
    movs r0, #0
    strb r0, [r5]
    pop {r4, r5}
    pop {r0}
    bx r0
    .hword 0x0000
.size func_080C6C88, .-func_080C6C88
