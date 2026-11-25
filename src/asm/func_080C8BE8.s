.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C8BE8
.type func_080C8BE8, %function
.thumb
.thumb_func
func_080C8BE8:
.L_080C8BE8:
    cmp r1, #0
    beq .L_080C8C70
    push {r4}
    adds r4, r0, #0
    eors r4, r1
    mov ip, r4
    movs r3, #1
    movs r2, #0
    cmp r1, #0
    bpl .L_080C8BFE
    rsbs r1, r1, #0
.L_080C8BFE:
    cmp r0, #0
    bpl .L_080C8C04
    rsbs r0, r0, #0
.L_080C8C04:
    cmp r0, r1
    blo .L_080C8C62
    movs r4, #1
    lsls r4, r4, #0x1c
.L_080C8C0C:
    cmp r1, r4
    bhs .L_080C8C1A
    cmp r1, r0
    bhs .L_080C8C1A
    lsls r1, r1, #4
    lsls r3, r3, #4
    b .L_080C8C0C
.L_080C8C1A:
    lsls r4, r4, #3
.L_080C8C1C:
    cmp r1, r4
    bhs .L_080C8C2A
    cmp r1, r0
    bhs .L_080C8C2A
    lsls r1, r1, #1
    lsls r3, r3, #1
    b .L_080C8C1C
.L_080C8C2A:
    cmp r0, r1
    blo .L_080C8C32
    subs r0, r0, r1
    orrs r2, r3
.L_080C8C32:
    lsrs r4, r1, #1
    cmp r0, r4
    blo .L_080C8C3E
    subs r0, r0, r4
    lsrs r4, r3, #1
    orrs r2, r4
.L_080C8C3E:
    lsrs r4, r1, #2
    cmp r0, r4
    blo .L_080C8C4A
    subs r0, r0, r4
    lsrs r4, r3, #2
    orrs r2, r4
.L_080C8C4A:
    lsrs r4, r1, #3
    cmp r0, r4
    blo .L_080C8C56
    subs r0, r0, r4
    lsrs r4, r3, #3
    orrs r2, r4
.L_080C8C56:
    cmp r0, #0
    beq .L_080C8C62
    lsrs r3, r3, #4
    beq .L_080C8C62
    lsrs r1, r1, #4
    b .L_080C8C2A
.L_080C8C62:
    adds r0, r2, #0
    mov r4, ip
    cmp r4, #0
    bpl .L_080C8C6C
    rsbs r0, r0, #0
.L_080C8C6C:
    pop {r4}
    mov pc, lr
.L_080C8C70:
    push {lr}
    bl func_080C8C7C
    movs r0, #0
    pop {pc}
    .hword 0x0000
.size func_080C8BE8, .-func_080C8BE8
