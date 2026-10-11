.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C8DC8
.type func_080C8DC8, %function
.thumb
.thumb_func
func_080C8DC8:
.L_080C8DC8:
    cmp r1, #0
    beq .L_080C8E7E
    movs r3, #1
    cmp r0, r1
    bhs .L_080C8DD4
    mov pc, lr
.L_080C8DD4:
    push {r4}
    movs r4, #1
    lsls r4, r4, #0x1c
.L_080C8DDA:
    cmp r1, r4
    bhs .L_080C8DE8
    cmp r1, r0
    bhs .L_080C8DE8
    lsls r1, r1, #4
    lsls r3, r3, #4
    b .L_080C8DDA
.L_080C8DE8:
    lsls r4, r4, #3
.L_080C8DEA:
    cmp r1, r4
    bhs .L_080C8DF8
    cmp r1, r0
    bhs .L_080C8DF8
    lsls r1, r1, #1
    lsls r3, r3, #1
    b .L_080C8DEA
.L_080C8DF8:
    movs r2, #0
    cmp r0, r1
    blo .L_080C8E00
    subs r0, r0, r1
.L_080C8E00:
    lsrs r4, r1, #1
    cmp r0, r4
    blo .L_080C8E12
    subs r0, r0, r4
    mov ip, r3
    movs r4, #1
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.L_080C8E12:
    lsrs r4, r1, #2
    cmp r0, r4
    blo .L_080C8E24
    subs r0, r0, r4
    mov ip, r3
    movs r4, #2
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.L_080C8E24:
    lsrs r4, r1, #3
    cmp r0, r4
    blo .L_080C8E36
    subs r0, r0, r4
    mov ip, r3
    movs r4, #3
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.L_080C8E36:
    mov ip, r3
    cmp r0, #0
    beq .L_080C8E44
    lsrs r3, r3, #4
    beq .L_080C8E44
    lsrs r1, r1, #4
    b .L_080C8DF8
.L_080C8E44:
    movs r4, #0xe
    lsls r4, r4, #0x1c
    ands r2, r4
    bne .L_080C8E50
    pop {r4}
    mov pc, lr
.L_080C8E50:
    mov r3, ip
    movs r4, #3
    rors r3, r4
    tst r2, r3
    beq .L_080C8E5E
    lsrs r4, r1, #3
    adds r0, r0, r4
.L_080C8E5E:
    mov r3, ip
    movs r4, #2
    rors r3, r4
    tst r2, r3
    beq .L_080C8E6C
    lsrs r4, r1, #2
    adds r0, r0, r4
.L_080C8E6C:
    mov r3, ip
    movs r4, #1
    rors r3, r4
    tst r2, r3
    beq .L_080C8E7A
    lsrs r4, r1, #1
    adds r0, r0, r4
.L_080C8E7A:
    pop {r4}
    mov pc, lr
.L_080C8E7E:
    push {lr}
    bl func_080C8C7C
    movs r0, #0
    pop {pc}
.size func_080C8DC8, .-func_080C8DC8
