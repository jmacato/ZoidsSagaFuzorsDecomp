.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C71A4
.type func_080C71A4, %function
.thumb
.thumb_func
func_080C71A4:
.L_080C71A4:
    push {r4, r5, r6, r7, lr}
    mov r4, r8
    mov r5, sb
    mov r6, sl
    mov r7, fp
    push {r4, r5, r6, r7}
    sub sp, #0x18
    str r1, [sp]
    adds r5, r2, #0
    ldr r1, [pc, #0x1e4]
    ldr r1, [r1]
    str r1, [sp, #4]
    ldr r1, [pc, #0x1e0]
    adds r0, r0, r1
    ldrb r0, [r0]
    strb r0, [r5, #4]
    ldr r3, [r5, #0x40]
    ldrb r0, [r3]
    cmp r0, #0x80
    bhs .L_080C71EA
    strb r0, [r5, #5]
    adds r3, #1
    ldrb r0, [r3]
    cmp r0, #0x80
    bhs .L_080C71E8
    strb r0, [r5, #6]
    adds r3, #1
    ldrb r0, [r3]
    cmp r0, #0x80
    bhs .L_080C71E8
    ldrb r1, [r5, #4]
    adds r1, r1, r0
    strb r1, [r5, #4]
    adds r3, #1
.L_080C71E8:
    str r3, [r5, #0x40]
.L_080C71EA:
    movs r0, #0
    str r0, [sp, #0x14]
    adds r4, r5, #0
    adds r4, #0x24
    ldrb r2, [r4]
    movs r0, #0xc0
    tst r0, r2
    beq .L_080C723C
    ldrb r3, [r5, #5]
    movs r0, #0x40
    tst r0, r2
    beq .L_080C720A
    ldr r1, [r5, #0x2c]
    adds r1, r1, r3
    ldrb r0, [r1]
    b .L_080C720C
.L_080C720A:
    adds r0, r3, #0
.L_080C720C:
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #2
    ldr r0, [r5, #0x28]
    adds r1, r1, r0
    mov sb, r1
    mov r6, sb
    ldrb r1, [r6]
    movs r0, #0xc0
    tst r0, r1
    beq .L_080C7224
    b .L_080C738A
.L_080C7224:
    movs r0, #0x80
    tst r0, r2
    beq .L_080C7240
    ldrb r1, [r6, #3]
    movs r0, #0x80
    tst r0, r1
    beq .L_080C7238
    subs r1, #0xc0
    lsls r1, r1, #1
    str r1, [sp, #0x14]
.L_080C7238:
    ldrb r3, [r6, #1]
    b .L_080C7240
.L_080C723C:
    mov sb, r4
    ldrb r3, [r5, #5]
.L_080C7240:
    str r3, [sp, #8]
    ldr r6, [sp]
    ldrb r1, [r6, #9]
    ldrb r0, [r5, #0x1d]
    adds r0, r0, r1
    cmp r0, #0xff
    bls .L_080C7250
    movs r0, #0xff
.L_080C7250:
    str r0, [sp, #0x10]
    mov r6, sb
    ldrb r0, [r6]
    movs r6, #7
    ands r6, r0
    str r6, [sp, #0xc]
    beq .L_080C7290
    ldr r0, [sp, #4]
    ldr r4, [r0, #0x1c]
    cmp r4, #0
    bne .L_080C7268
    b .L_080C738A
.L_080C7268:
    subs r6, #1
    lsls r0, r6, #6
    adds r4, r4, r0
    ldrb r1, [r4]
    movs r0, #0xc7
    tst r0, r1
    beq .L_080C72E4
    movs r0, #0x40
    tst r0, r1
    bne .L_080C72E4
    ldrb r1, [r4, #0x13]
    ldr r0, [sp, #0x10]
    cmp r1, r0
    blo .L_080C72E4
    beq .L_080C7288
    b .L_080C738A
.L_080C7288:
    ldr r0, [r4, #0x2c]
    cmp r0, r5
    bhs .L_080C72E4
    b .L_080C738A
.L_080C7290:
    ldr r6, [sp, #0x10]
    adds r7, r5, #0
    movs r2, #0
    mov r8, r2
    ldr r4, [sp, #4]
    ldrb r3, [r4, #6]
    adds r4, #0x50
.L_080C729E:
    ldrb r1, [r4]
    movs r0, #0xc7
    tst r0, r1
    beq .L_080C72E4
    movs r0, #0x40
    tst r0, r1
    beq .L_080C72B8
    cmp r2, #0
    bne .L_080C72BC
    adds r2, #1
    ldrb r6, [r4, #0x13]
    ldr r7, [r4, #0x2c]
    b .L_080C72D6
.L_080C72B8:
    cmp r2, #0
    bne .L_080C72D8
.L_080C72BC:
    ldrb r0, [r4, #0x13]
    cmp r0, r6
    bhs .L_080C72C8
    adds r6, r0, #0
    ldr r7, [r4, #0x2c]
    b .L_080C72D6
.L_080C72C8:
    bhi .L_080C72D8
    ldr r0, [r4, #0x2c]
    cmp r0, r7
    bls .L_080C72D4
    adds r7, r0, #0
    b .L_080C72D6
.L_080C72D4:
    blo .L_080C72D8
.L_080C72D6:
    mov r8, r4
.L_080C72D8:
    adds r4, #0x40
    subs r3, #1
    bgt .L_080C729E
    mov r4, r8
    cmp r4, #0
    beq .L_080C738A
.L_080C72E4:
    adds r0, r4, #0
    bl func_080C78B0
    movs r1, #0
    str r1, [r4, #0x30]
    ldr r3, [r5, #0x20]
    str r3, [r4, #0x34]
    cmp r3, #0
    beq .L_080C72F8
    str r4, [r3, #0x30]
.L_080C72F8:
    str r4, [r5, #0x20]
    str r5, [r4, #0x2c]
    ldrb r0, [r5, #0x1b]
    strb r0, [r5, #0x1c]
    cmp r0, r1
    beq .L_080C730A
    adds r1, r5, #0
    bl func_080C73E4
.L_080C730A:
    ldr r0, [sp]
    adds r1, r5, #0
    bl func_080C7E7C
    ldr r0, [r5, #4]
    str r0, [r4, #0x10]
    ldr r0, [sp, #0x10]
    strb r0, [r4, #0x13]
    ldr r0, [sp, #8]
    strb r0, [r4, #8]
    ldr r0, [sp, #0x14]
    strb r0, [r4, #0x14]
    mov r6, sb
    ldrb r0, [r6]
    strb r0, [r4, #1]
    ldr r7, [r6, #4]
    str r7, [r4, #0x24]
    ldr r0, [r6, #8]
    str r0, [r4, #4]
    ldrh r0, [r5, #0x1e]
    strh r0, [r4, #0xc]
    bl func_080C7174
    ldrb r1, [r4, #8]
    movs r0, #8
    ldrsb r0, [r5, r0]
    adds r3, r1, r0
    bpl .L_080C7344
    movs r3, #0
.L_080C7344:
    ldr r6, [sp, #0xc]
    cmp r6, #0
    beq .L_080C7372
    mov r6, sb
    ldrb r0, [r6, #2]
    strb r0, [r4, #0x1e]
    ldrb r1, [r6, #3]
    movs r0, #0x80
    tst r0, r1
    bne .L_080C735E
    movs r0, #0x70
    tst r0, r1
    bne .L_080C7360
.L_080C735E:
    movs r1, #8
.L_080C7360:
    strb r1, [r4, #0x1f]
    ldrb r2, [r5, #9]
    adds r1, r3, #0
    ldr r0, [sp, #0xc]
    ldr r3, [sp, #4]
    ldr r3, [r3, #0x30]
    bl func_080C7120
    b .L_080C737C
.L_080C7372:
    ldrb r2, [r5, #9]
    adds r1, r3, #0
    adds r0, r7, #0
    bl func_080C7434
.L_080C737C:
    str r0, [r4, #0x20]
    movs r0, #0x80
    strb r0, [r4]
    ldrb r1, [r5]
    movs r0, #0xf0
    ands r0, r1
    strb r0, [r5]
.L_080C738A:
    add sp, #0x18
    pop {r0, r1, r2, r3, r4, r5, r6, r7}
    mov r8, r0
    mov sb, r1
    mov sl, r2
    mov fp, r3
    pop {r0}
    bx r0
    .hword 0x0000
    .word 0x03007FF0
    .word 0x0863E210
.size func_080C71A4, .-func_080C71A4
