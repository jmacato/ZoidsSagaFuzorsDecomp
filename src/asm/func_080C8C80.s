.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C8C80
.type func_080C8C80, %function
.thumb
.thumb_func
func_080C8C80:
.L_080C8C80:
    movs r3, #1
    cmp r1, #0
    beq .L_080C8D44
    bpl .L_080C8C8A
    rsbs r1, r1, #0
.L_080C8C8A:
    push {r4}
    push {r0}
    cmp r0, #0
    bpl .L_080C8C94
    rsbs r0, r0, #0
.L_080C8C94:
    cmp r0, r1
    blo .L_080C8D38
    movs r4, #1
    lsls r4, r4, #0x1c
.L_080C8C9C:
    cmp r1, r4
    bhs .L_080C8CAA
    cmp r1, r0
    bhs .L_080C8CAA
    lsls r1, r1, #4
    lsls r3, r3, #4
    b .L_080C8C9C
.L_080C8CAA:
    lsls r4, r4, #3
.L_080C8CAC:
    cmp r1, r4
    bhs .L_080C8CBA
    cmp r1, r0
    bhs .L_080C8CBA
    lsls r1, r1, #1
    lsls r3, r3, #1
    b .L_080C8CAC
.L_080C8CBA:
    movs r2, #0
    cmp r0, r1
    blo .L_080C8CC2
    subs r0, r0, r1
.L_080C8CC2:
    lsrs r4, r1, #1
    cmp r0, r4
    blo .L_080C8CD4
    subs r0, r0, r4
    mov ip, r3
    movs r4, #1
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.L_080C8CD4:
    lsrs r4, r1, #2
    cmp r0, r4
    blo .L_080C8CE6
    subs r0, r0, r4
    mov ip, r3
    movs r4, #2
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.L_080C8CE6:
    lsrs r4, r1, #3
    cmp r0, r4
    blo .L_080C8CF8
    subs r0, r0, r4
    mov ip, r3
    movs r4, #3
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.L_080C8CF8:
    mov ip, r3
    cmp r0, #0
    beq .L_080C8D06
    lsrs r3, r3, #4
    beq .L_080C8D06
    lsrs r1, r1, #4
    b .L_080C8CBA
.L_080C8D06:
    movs r4, #0xe
    lsls r4, r4, #0x1c
    ands r2, r4
    beq .L_080C8D38
    mov r3, ip
    movs r4, #3
    rors r3, r4
    tst r2, r3
    beq .L_080C8D1C
    lsrs r4, r1, #3
    adds r0, r0, r4
.L_080C8D1C:
    mov r3, ip
    movs r4, #2
    rors r3, r4
    tst r2, r3
    beq .L_080C8D2A
    lsrs r4, r1, #2
    adds r0, r0, r4
.L_080C8D2A:
    mov r3, ip
    movs r4, #1
    rors r3, r4
    tst r2, r3
    beq .L_080C8D38
    lsrs r4, r1, #1
    adds r0, r0, r4
.L_080C8D38:
    pop {r4}
    cmp r4, #0
    bpl .L_080C8D40
    rsbs r0, r0, #0
.L_080C8D40:
    pop {r4}
    mov pc, lr
.L_080C8D44:
    push {lr}
    bl func_080C8C7C
    movs r0, #0
    pop {pc}
    .hword 0x0000
.size func_080C8C80, .-func_080C8C80
