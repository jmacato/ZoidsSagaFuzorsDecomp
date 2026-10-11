.syntax unified
.cpu arm7tdmi
.text
.balign 2
.global func_080C68AC
.type func_080C68AC, %function
.thumb
.thumb_func
func_080C68AC:
.L_080C68AC:
    ldrb r3, [r0, #5]
    cmp r3, #0
    beq .L_080C690C
    .hword 0xA101 @ adr r1, #4
    bx r1
    .hword 0x0000
    .word 0xE3540002
    .word 0x02807E35
    .word 0x10857008
    .word 0xE1A04008
    .word 0xE19500D6
    .word 0xE1D510D0
    .word 0xE0800001
    .word 0xE19710D6
    .word 0xE0800001
    .word 0xE0D710D1
    .word 0xE0800001
    .word 0xE0010390
    .word 0xE1A004C1
    .word 0xE3100080
    .word 0x12800001
    .word 0xE7C50006
    .word 0xE4C50001
    .word 0xE2544001
    .word 0xCAFFFFF0
    .word 0xE28F002F
    .word 0xE12FFF10
.L_080C690C:
    movs r0, #0
    mov r1, r8
    adds r6, r6, r5
    lsrs r1, r1, #3
    blo .L_080C691A
    stm r5!, {r0}
    stm r6!, {r0}
.L_080C691A:
    lsrs r1, r1, #1
    blo .L_080C6926
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
.L_080C6926:
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
    subs r1, #1
    bgt .L_080C6926
    ldr r4, [sp, #0x18]
    ldr r0, [r4, #0x18]
    mov ip, r0
    ldrb r0, [r4, #6]
    adds r4, #0x50
.L_080C6944:
    str r0, [sp, #4]
    ldr r3, [r4, #0x24]
    ldr r0, [sp, #0x14]
    cmp r0, #0
    beq .L_080C6964
    ldr r1, [pc, #0x10]
    ldrb r1, [r1]
    cmp r1, #0xa0
    bhs .L_080C6958
    adds r1, #0xe4
.L_080C6958:
    cmp r1, r0
    blo .L_080C6964
    b .L_080C6C36
    .hword 0x0000
    .word 0x04000006
.L_080C6964:
    ldrb r6, [r4]
    movs r0, #0xc7
    tst r0, r6
    bne .L_080C696E
    b .L_080C6C2C
.L_080C696E:
    movs r0, #0x80
    tst r0, r6
    beq .L_080C699E
    movs r0, #0x40
    tst r0, r6
    bne .L_080C69AE
    movs r6, #3
    strb r6, [r4]
    adds r0, r3, #0
    adds r0, #0x10
    str r0, [r4, #0x28]
    ldr r0, [r3, #0xc]
    str r0, [r4, #0x18]
    movs r5, #0
    strb r5, [r4, #9]
    str r5, [r4, #0x1c]
    ldrb r2, [r3, #3]
    movs r0, #0xc0
    tst r0, r2
    beq .L_080C69F6
    movs r0, #0x10
    orrs r6, r0
    strb r6, [r4]
    b .L_080C69F6
.L_080C699E:
    ldrb r5, [r4, #9]
    movs r0, #4
    tst r0, r6
    beq .L_080C69B4
    ldrb r0, [r4, #0xd]
    subs r0, #1
    strb r0, [r4, #0xd]
    bhi .L_080C6A04
.L_080C69AE:
    movs r0, #0
    strb r0, [r4]
    b .L_080C6C2C
.L_080C69B4:
    movs r0, #0x40
    tst r0, r6
    beq .L_080C69D4
    ldrb r0, [r4, #7]
    muls r5, r0, r5
    lsrs r5, r5, #8
    ldrb r0, [r4, #0xc]
    cmp r5, r0
    bhi .L_080C6A04
.L_080C69C6:
    ldrb r5, [r4, #0xc]
    cmp r5, #0
    beq .L_080C69AE
    movs r0, #4
    orrs r6, r0
    strb r6, [r4]
    b .L_080C6A04
.L_080C69D4:
    movs r2, #3
    ands r2, r6
    cmp r2, #2
    bne .L_080C69F2
    ldrb r0, [r4, #5]
    muls r5, r0, r5
    lsrs r5, r5, #8
    ldrb r0, [r4, #6]
    cmp r5, r0
    bhi .L_080C6A04
    adds r5, r0, #0
    beq .L_080C69C6
    subs r6, #1
    strb r6, [r4]
    b .L_080C6A04
.L_080C69F2:
    cmp r2, #3
    bne .L_080C6A04
.L_080C69F6:
    ldrb r0, [r4, #4]
    adds r5, r5, r0
    cmp r5, #0xff
    blo .L_080C6A04
    movs r5, #0xff
    subs r6, #1
    strb r6, [r4]
.L_080C6A04:
    strb r5, [r4, #9]
    ldr r0, [sp, #0x18]
    ldrb r0, [r0, #7]
    adds r0, #1
    muls r0, r5, r0
    lsrs r5, r0, #4
    ldrb r0, [r4, #2]
    muls r0, r5, r0
    lsrs r0, r0, #8
    strb r0, [r4, #0xa]
    ldrb r0, [r4, #3]
    muls r0, r5, r0
    lsrs r0, r0, #8
    strb r0, [r4, #0xb]
    movs r0, #0x10
    ands r0, r6
    str r0, [sp, #0x10]
    beq .L_080C6A38
    adds r0, r3, #0
    adds r0, #0x10
    ldr r1, [r3, #8]
    adds r0, r0, r1
    str r0, [sp, #0xc]
    ldr r0, [r3, #0xc]
    subs r0, r0, r1
    str r0, [sp, #0x10]
.L_080C6A38:
    ldr r5, [sp, #8]
    ldr r2, [r4, #0x18]
    ldr r3, [r4, #0x28]
    .hword 0xA001 @ adr r0, #4
    bx r0
    .hword 0x0000
    .word 0xE58D8000
    .word 0xE5D4A00A
    .word 0xE5D4B00B
    .word 0xE1A0A80A
    .word 0xE1A0B80B
    .word 0xE5D40001
    .word 0xE3100008
    .word 0x0A000047
    .word 0xE3520004
    .word 0xDA000019
    .word 0xE0522008
    .word 0xC3A0E000
    .word 0xCA000005
    .word 0xE1A0E008
    .word 0xE0822008
    .word 0xE2428004
    .word 0xE04EE008
    .word 0xE2122003
    .word 0x03A02004
    .word 0xE5956000
    .word 0xE5957630
    .word 0xE0D300D1
    .word 0xE001009A
    .word 0xE3C118FF
    .word 0xE0816466
    .word 0xE001009B
    .word 0xE3C118FF
    .word 0xE0817467
    .word 0xE2955101
    .word 0x3AFFFFF6
    .word 0xE5857630
    .word 0xE4856004
    .word 0xE2588004
    .word 0xCAFFFFF0
    .word 0xE098800E
    .word 0x0A000050
    .word 0xE5956000
    .word 0xE5957630
    .word 0xE0D300D1
    .word 0xE001009A
    .word 0xE3C118FF
    .word 0xE0816466
    .word 0xE001009B
    .word 0xE3C118FF
    .word 0xE0817467
    .word 0xE2522001
    .word 0x0A000012
    .word 0xE2955101
    .word 0x3AFFFFF4
    .word 0xE5857630
    .word 0xE4856004
    .word 0xE2588004
    .word 0xCAFFFFD2
    .word 0xEA00003E
    .word 0xE59D0018
    .word 0xE3500000
    .word 0x0A000005
    .word 0xE59D3014
    .word 0xE2629000
    .word 0xE0902002
    .word 0xCA00002B
    .word 0xE0499000
    .word 0xEAFFFFFB
    .word 0xE8BD1010
    .word 0xE3A02000
    .word 0xEA000003
    .word 0xE59D2010
    .word 0xE3520000
    .word 0x159D300C
    .word 0x1AFFFFE8
    .word 0xE5C42000
    .word 0xE1A00F25
    .word 0xE3C55103
    .word 0xE2600003
    .word 0xE1A00180
    .word 0xE1A06076
    .word 0xE1A07077
    .word 0xE5857630
    .word 0xE4856004
    .word 0xEA000026
    .word 0xE92D1010
    .word 0xE594E01C
    .word 0xE5941020
    .word 0xE004019C
    .word 0xE1D300D0
    .word 0xE1F310D1
    .word 0xE0411000
    .word 0xE5956000
    .word 0xE5957630
    .word 0xE009019E
    .word 0xE0809BC9
    .word 0xE00C099A
    .word 0xE3CCC8FF
    .word 0xE08C6466
    .word 0xE00C099B
    .word 0xE3CCC8FF
    .word 0xE08C7467
    .word 0xE08EE004
    .word 0xE1B09BAE
    .word 0x0A000007
    .word 0xE3CEE5FE
    .word 0xE0522009
    .word 0xDAFFFFCE
    .word 0xE2599001
    .word 0x00800001
    .word 0x11B300D9
    .word 0xE1F310D1
    .word 0xE0411000
    .word 0xE2955101
    .word 0x3AFFFFEA
    .word 0xE5857630
    .word 0xE4856004
    .word 0xE2588004
    .word 0xCAFFFFE4
    .word 0xE2433001
    .word 0xE8BD1010
    .word 0xE584E01C
    .word 0xE5842018
    .word 0xE5843028
    .word 0xE59D8000
    .word 0xE28F0001
    .word 0xE12FFF10
.L_080C6C2C:
    ldr r0, [sp, #4]
    subs r0, #1
    ble .L_080C6C36
    adds r4, #0x40
    b .L_080C6944
.L_080C6C36:
    ldr r0, [sp, #0x18]
    ldr r3, [pc, #0x10]
    str r3, [r0]
    add sp, #0x1c
    pop {r0, r1, r2, r3, r4, r5, r6, r7}
    mov r8, r0
    mov sb, r1
    mov sl, r2
    mov fp, r3
    pop {r3}
.size func_080C68AC, .-func_080C68AC
