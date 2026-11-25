.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C8D50
.type func_080C8D50, %function
.thumb
.thumb_func
func_080C8D50:
.L_080C8D50:
    cmp r1, #0
    beq .L_080C8DBE
    movs r3, #1
    movs r2, #0
    push {r4}
    cmp r0, r1
    blo .L_080C8DB8
    movs r4, #1
    lsls r4, r4, #0x1c
.L_080C8D62:
    cmp r1, r4
    bhs .L_080C8D70
    cmp r1, r0
    bhs .L_080C8D70
    lsls r1, r1, #4
    lsls r3, r3, #4
    b .L_080C8D62
.L_080C8D70:
    lsls r4, r4, #3
.L_080C8D72:
    cmp r1, r4
    bhs .L_080C8D80
    cmp r1, r0
    bhs .L_080C8D80
    lsls r1, r1, #1
    lsls r3, r3, #1
    b .L_080C8D72
.L_080C8D80:
    cmp r0, r1
    blo .L_080C8D88
    subs r0, r0, r1
    orrs r2, r3
.L_080C8D88:
    lsrs r4, r1, #1
    cmp r0, r4
    blo .L_080C8D94
    subs r0, r0, r4
    lsrs r4, r3, #1
    orrs r2, r4
.L_080C8D94:
    lsrs r4, r1, #2
    cmp r0, r4
    blo .L_080C8DA0
    subs r0, r0, r4
    lsrs r4, r3, #2
    orrs r2, r4
.L_080C8DA0:
    lsrs r4, r1, #3
    cmp r0, r4
    blo .L_080C8DAC
    subs r0, r0, r4
    lsrs r4, r3, #3
    orrs r2, r4
.L_080C8DAC:
    cmp r0, #0
    beq .L_080C8DB8
    lsrs r3, r3, #4
    beq .L_080C8DB8
    lsrs r1, r1, #4
    b .L_080C8D80
.L_080C8DB8:
    adds r0, r2, #0
    pop {r4}
    mov pc, lr
.L_080C8DBE:
    push {lr}
    bl func_080C8C7C
    movs r0, #0
    pop {pc}
.size func_080C8D50, .-func_080C8D50
