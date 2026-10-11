.syntax unified
.cpu arm7tdmi
.text
.balign 4
.global arm_runtime
.type arm_runtime, %function
.arm
arm_runtime:
    .word 0xE3A00012 @ mov r0, #0x12
    .word 0xE129F000 @ msr cpsr_fc, r0
    .word 0xE59FD030 @ ldr sp, [pc, #0x30]
    .word 0xE3A0001F @ mov r0, #0x1f
    .word 0xE129F000 @ msr cpsr_fc, r0
    .word 0xE59FD020 @ ldr sp, [pc, #0x20]
    .word 0xE59F1014 @ ldr r1, [pc, #0x14]
    .word 0xE28F0020 @ add r0, pc, #0x20
    .word 0xE5810000 @ str r0, [r1]
    .word 0xE59F100C @ ldr r1, [pc, #0xc]
    .word 0xE1A0E00F @ mov lr, pc
    .word 0xE12FFF11 @ bx r1
    .word 0xEAFFFFF2 @ b #0x80000c0
    .word 0x03007FFC @ movweq r7, #0xffc
    .word 0x08074FB1 @ stmdaeq r7, {r0, r4, r5, r7, r8, sb, sl, fp, lr}
    .word 0x03007F00 @ movweq r7, #0xf00
    .word 0x03007FA0 @ movweq r7, #0xfa0
    .word 0xE3A03301 @ mov r3, #0x4000000
    .word 0xE2833C02 @ add r3, r3, #0x200
    .word 0xE5932000 @ ldr r2, [r3]
    .word 0xE1D310B8 @ ldrh r1, [r3, #8]
    .word 0xE14F0000 @ mrs r0, spsr
    .word 0xE92D400F @ push {r0, r1, r2, r3, lr}
    .word 0xE3A00001 @ mov r0, #1
    .word 0xE1C300B8 @ strh r0, [r3, #8]
    .word 0xE0021822 @ and r1, r2, r2, lsr #16
    .word 0xE3A0C000 @ mov ip, #0
    .word 0xE2110001 @ ands r0, r1, #1
    .word 0x1A000024 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110002 @ ands r0, r1, #2
    .word 0x1A000021 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110004 @ ands r0, r1, #4
    .word 0x1A00001E @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE21100C0 @ ands r0, r1, #0xc0
    .word 0x1A00001B @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110008 @ ands r0, r1, #8
    .word 0x1A000018 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110010 @ ands r0, r1, #0x10
    .word 0x1A000015 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110020 @ ands r0, r1, #0x20
    .word 0x1A000012 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110C01 @ ands r0, r1, #0x100
    .word 0x1A00000F @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110C02 @ ands r0, r1, #0x200
    .word 0x1A00000C @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110B01 @ ands r0, r1, #0x400
    .word 0x1A000009 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110B02 @ ands r0, r1, #0x800
    .word 0x1A000006 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110A01 @ ands r0, r1, #0x1000
    .word 0x1A000003 @ bne #0x80001c8
    .word 0xE28CC004 @ add ip, ip, #4
    .word 0xE2110A02 @ ands r0, r1, #0x2000
    .word 0x1543017C @ strbne r0, [r3, #-0x17c]
    .word 0x1AFFFFFE @ bne #0x80001c4
    .word 0xE1C300B2 @ strh r0, [r3, #2]
    .word 0xE59F1070 @ ldr r1, [pc, #0x70]
    .word 0xE3500002 @ cmp r0, #2
    .word 0x0A000000 @ beq #0x80001dc
    .word 0xE38110C0 @ orr r1, r1, #0xc0
    .word 0xE0011002 @ and r1, r1, r2
    .word 0xE1C310B0 @ strh r1, [r3]
    .word 0xE10F3000 @ mrs r3, apsr
    .word 0xE3C330DF @ bic r3, r3, #0xdf
    .word 0xE383301F @ orr r3, r3, #0x1f
    .word 0xE129F003 @ msr cpsr_fc, r3
    .word 0xE59F104C @ ldr r1, [pc, #0x4c]
    .word 0xE081100C @ add r1, r1, ip
    .word 0xE5910000 @ ldr r0, [r1]
    .word 0xE92D4000 @ stmdb sp!, {lr}
    .word 0xE28FE000 @ add lr, pc, #0
    .word 0xE12FFF10 @ bx r0
    .word 0xE8BD4000 @ ldm sp!, {lr}
    .word 0xE10F3000 @ mrs r3, apsr
    .word 0xE3C330DF @ bic r3, r3, #0xdf
    .word 0xE3833092 @ orr r3, r3, #0x92
    .word 0xE129F003 @ msr cpsr_fc, r3
    .word 0xE8BD400F @ pop {r0, r1, r2, r3, lr}
    .word 0xE1C310B8 @ strh r1, [r3, #8]
    .word 0xE1D310B0 @ ldrh r1, [r3]
    .word 0xE2011006 @ and r1, r1, #6
    .word 0xE3C22006 @ bic r2, r2, #6
    .word 0xE1811002 @ orr r1, r1, r2
    .word 0xE1C310B0 @ strh r1, [r3]
    .word 0xE169F000 @ msr spsr_fc, r0
    .word 0xE12FFF1E @ bx lr
    .word 0x00002006 @ andeq r2, r0, r6
    .word 0x03000014 @ movweq r0, #0x14
    .word 0xE59F3168 @ ldr r3, [pc, #0x168]
    .word 0xE59F2168 @ ldr r2, [pc, #0x168]
    .word 0xE5832000 @ str r2, [r3]
    .word 0xE59F3164 @ ldr r3, [pc, #0x164]
    .word 0xE583E000 @ str lr, [r3]
    .word 0xE59F3160 @ ldr r3, [pc, #0x160]
    .word 0xE583D000 @ str sp, [r3]
    .word 0xE3A00001 @ mov r0, #1
    .word 0xE92DDFFF @ push {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr, pc}
    .word 0xE14F0000 @ mrs r0, spsr
    .word 0xE92D0001 @ stmdb sp!, {r0}
    .word 0xE59F314C @ ldr r3, [pc, #0x14c]
    .word 0xE59F514C @ ldr r5, [pc, #0x14c]
    .word 0xE5932000 @ ldr r2, [r3]
    .word 0xE59F1148 @ ldr r1, [pc, #0x148]
    .word 0xE5920008 @ ldr r0, [r2, #8]
    .word 0xE1500001 @ cmp r0, r1
    .word 0x0A000024 @ beq #0x8000328
    .word 0xE1A0000E @ mov r0, lr
    .word 0xE5820008 @ str r0, [r2, #8]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE582000C @ str r0, [r2, #0xc]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820010 @ str r0, [r2, #0x10]
    .word 0xE5C20001 @ strb r0, [r2, #1]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820014 @ str r0, [r2, #0x14]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820018 @ str r0, [r2, #0x18]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE582001C @ str r0, [r2, #0x1c]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820020 @ str r0, [r2, #0x20]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820024 @ str r0, [r2, #0x24]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820028 @ str r0, [r2, #0x28]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE582002C @ str r0, [r2, #0x2c]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820030 @ str r0, [r2, #0x30]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820034 @ str r0, [r2, #0x34]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820038 @ str r0, [r2, #0x38]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE582003C @ str r0, [r2, #0x3c]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820040 @ str r0, [r2, #0x40]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820044 @ str r0, [r2, #0x44]
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE5820048 @ str r0, [r2, #0x48]
    .word 0xE582D004 @ str sp, [r2, #4]
    .word 0xEA000000 @ b #0x800032c
    .word 0xE28DD040 @ add sp, sp, #0x40
    .word 0xE282204C @ add r2, r2, #0x4c
    .word 0xE5832000 @ str r2, [r3]
    .word 0xE5D20000 @ ldrb r0, [r2]
    .word 0xE3500008 @ cmp r0, #8
    .word 0x0A000019 @ beq #0x80003a8
    .word 0xE592E008 @ ldr lr, [r2, #8]
    .word 0xE15E0001 @ cmp lr, r1
    .word 0x0AFFFFF7 @ beq #0x800032c
    .word 0xE5D24001 @ ldrb r4, [r2, #1]
    .word 0xE2544001 @ subs r4, r4, #1
    .word 0x15C24001 @ strbne r4, [r2, #1]
    .word 0x1AFFFFF3 @ bne #0x800032c
    .word 0xE2400001 @ sub r0, r0, #1
    .word 0xE5C50000 @ strb r0, [r5]
    .word 0xE592000C @ ldr r0, [r2, #0xc]
    .word 0xE169F000 @ msr spsr_fc, r0
    .word 0xE5920010 @ ldr r0, [r2, #0x10]
    .word 0xE5921018 @ ldr r1, [r2, #0x18]
    .word 0xE592301C @ ldr r3, [r2, #0x1c]
    .word 0xE5924020 @ ldr r4, [r2, #0x20]
    .word 0xE5925024 @ ldr r5, [r2, #0x24]
    .word 0xE5926028 @ ldr r6, [r2, #0x28]
    .word 0xE592702C @ ldr r7, [r2, #0x2c]
    .word 0xE5928030 @ ldr r8, [r2, #0x30]
    .word 0xE5929034 @ ldr sb, [r2, #0x34]
    .word 0xE592A038 @ ldr sl, [r2, #0x38]
    .word 0xE592B03C @ ldr fp, [r2, #0x3c]
    .word 0xE592C040 @ ldr ip, [r2, #0x40]
    .word 0xE592D004 @ ldr sp, [r2, #4]
    .word 0xE5922014 @ ldr r2, [r2, #0x14]
    .word 0xE12FFF1E @ bx lr
    .word 0xE59F3028 @ ldr r3, [pc, #0x28]
    .word 0xE593D000 @ ldr sp, [r3]
    .word 0xE59F3024 @ ldr r3, [pc, #0x24]
    .word 0xE593E000 @ ldr lr, [r3]
    .word 0xE12FFF1E @ bx lr
    .word 0x03000E44 @ movweq r0, #0xe44
    .word 0x03000BB4 @ movweq r0, #0xbb4
    .word 0x03002348 @ movweq r2, #0x348
    .word 0x0300234C @ movweq r2, #0x34c
    .word 0x03000E44 @ movweq r0, #0xe44
    .word 0x03000BB0 @ movweq r0, #0xbb0
    .word 0xFFFFFFFF
    .word 0x0300234C @ movweq r2, #0x34c
    .word 0x03002348 @ movweq r2, #0x348
    .word 0xE92D40FE @ push {r1, r2, r3, r4, r5, r6, r7, lr}
    .word 0xE24DD020 @ sub sp, sp, #0x20
    .word 0xE1A0700D @ mov r7, sp
    .word 0xE5870000 @ str r0, [r7]
    .word 0xE5871004 @ str r1, [r7, #4]
    .word 0xE3500000 @ cmp r0, #0
    .word 0x0A00002D @ beq #0x80004b4
    .word 0xE3510000 @ cmp r1, #0
    .word 0x03A00000 @ moveq r0, #0
    .word 0x0A00002A @ beq #0x80004b4
    .word 0xE3A02000 @ mov r2, #0
    .word 0xE3A03000 @ mov r3, #0
    .word 0xE3500102 @ cmp r0, #0x80000000
    .word 0x20430000 @ subhs r0, r3, r0
    .word 0x22822001 @ addhs r2, r2, #1
    .word 0xE5870008 @ str r0, [r7, #8]
    .word 0xE3510102 @ cmp r1, #0x80000000
    .word 0x20431001 @ subhs r1, r3, r1
    .word 0x22822001 @ addhs r2, r2, #1
    .word 0xE587100C @ str r1, [r7, #0xc]
    .word 0xE1A00620 @ lsr r0, r0, #0xc
    .word 0xE5870010 @ str r0, [r7, #0x10]
    .word 0xE1A01621 @ lsr r1, r1, #0xc
    .word 0xE5871014 @ str r1, [r7, #0x14]
    .word 0xE59F307C @ ldr r3, [pc, #0x7c]
    .word 0xE5970008 @ ldr r0, [r7, #8]
    .word 0xE0030000 @ and r0, r3, r0
    .word 0xE5870008 @ str r0, [r7, #8]
    .word 0xE597100C @ ldr r1, [r7, #0xc]
    .word 0xE0031001 @ and r1, r3, r1
    .word 0xE587100C @ str r1, [r7, #0xc]
    .word 0xE5970010 @ ldr r0, [r7, #0x10]
    .word 0xE5971014 @ ldr r1, [r7, #0x14]
    .word 0xE0010190 @ mul r1, r0, r1
    .word 0xE1A01601 @ lsl r1, r1, #0xc
    .word 0xE5871018 @ str r1, [r7, #0x18]
    .word 0xE597100C @ ldr r1, [r7, #0xc]
    .word 0xE0000091 @ mul r0, r1, r0
    .word 0xE587001C @ str r0, [r7, #0x1c]
    .word 0xE5970014 @ ldr r0, [r7, #0x14]
    .word 0xE5971008 @ ldr r1, [r7, #8]
    .word 0xE0030091 @ mul r3, r1, r0
    .word 0xE597000C @ ldr r0, [r7, #0xc]
    .word 0xE0000091 @ mul r0, r1, r0
    .word 0xE1A01620 @ lsr r1, r0, #0xc
    .word 0xE0810003 @ add r0, r1, r3
    .word 0xE597101C @ ldr r1, [r7, #0x1c]
    .word 0xE0810000 @ add r0, r1, r0
    .word 0xE5971018 @ ldr r1, [r7, #0x18]
    .word 0xE0810000 @ add r0, r1, r0
    .word 0xE3520001 @ cmp r2, #1
    .word 0x03A01000 @ moveq r1, #0
    .word 0x00410000 @ subeq r0, r1, r0
    .word 0xE28DD020 @ add sp, sp, #0x20
    .word 0xE8BD00FE @ pop {r1, r2, r3, r4, r5, r6, r7}
    .word 0xE8BD4000 @ ldm sp!, {lr}
    .word 0xE12FFF1E @ bx lr
    .word 0x00000FFF @ strdeq r0, r1, [r0], -pc
    .word 0xE92D4000 @ stmdb sp!, {lr}
    .word 0xE59F203C @ ldr r2, [pc, #0x3c]
    .word 0xE5921000 @ ldr r1, [r2]
    .word 0xE1A0E00F @ mov lr, pc
    .word 0xE12FFF11 @ bx r1
    .word 0xE59F2030 @ ldr r2, [pc, #0x30]
    .word 0xE5921000 @ ldr r1, [r2]
    .word 0xE1A0E00F @ mov lr, pc
    .word 0xE12FFF11 @ bx r1
    .word 0xE59F2024 @ ldr r2, [pc, #0x24]
    .word 0xE5921000 @ ldr r1, [r2]
    .word 0xE1A0E00F @ mov lr, pc
    .word 0xE12FFF11 @ bx r1
    .word 0xE59F2018 @ ldr r2, [pc, #0x18]
    .word 0xE3A01002 @ mov r1, #2
    .word 0xE1C210B0 @ strh r1, [r2]
    .word 0xE8BD4000 @ ldm sp!, {lr}
    .word 0xE12FFF1E @ bx lr
    .word 0x03000000 @ movweq r0, #0
    .word 0x03000004 @ movweq r0, #4
    .word 0x03000008 @ movweq r0, #8
    .word 0x03007FF8 @ movweq r7, #0xff8
    .word 0xE92D4000 @ stmdb sp!, {lr}
    .word 0xE59F206C @ ldr r2, [pc, #0x6c]
    .word 0xE1D210B0 @ ldrh r1, [r2]
    .word 0xE3C11004 @ bic r1, r1, #4
    .word 0xE1C210B0 @ strh r1, [r2]
    .word 0xE59F1060 @ ldr r1, [pc, #0x60]
    .word 0xE5911000 @ ldr r1, [r1]
    .word 0xE3710001 @ cmn r1, #1
    .word 0x0A00000F @ beq #0x8000584
    .word 0xE5912004 @ ldr r2, [r1, #4]
    .word 0xE1A0E00F @ mov lr, pc
    .word 0xE12FFF12 @ bx r2
    .word 0xE59F2048 @ ldr r2, [pc, #0x48]
    .word 0xE5921000 @ ldr r1, [r2]
    .word 0xE1A00001 @ mov r0, r1
    .word 0xE591100C @ ldr r1, [r1, #0xc]
    .word 0xE5821000 @ str r1, [r2]
    .word 0xE3710001 @ cmn r1, #1
    .word 0x0A000005 @ beq #0x8000584
    .word 0xE59F2030 @ ldr r2, [pc, #0x30]
    .word 0xE5D23000 @ ldrb r3, [r2]
    .word 0xE20330FF @ and r3, r3, #0xff
    .word 0xE5D11000 @ ldrb r1, [r1]
    .word 0xE1833401 @ orr r3, r3, r1, lsl #8
    .word 0xE1C230B0 @ strh r3, [r2]
    .word 0xE59F201C @ ldr r2, [pc, #0x1c]
    .word 0xE3A01004 @ mov r1, #4
    .word 0xE1C210B0 @ strh r1, [r2]
    .word 0xE8BD4000 @ ldm sp!, {lr}
    .word 0xE12FFF1E @ bx lr
    .word 0x04000202 @ streq r0, [r0], #-0x202
    .word 0x03000894 @ movweq r0, #0x894
    .word 0x03000894 @ movweq r0, #0x894
    .word 0x04000004 @ streq r0, [r0], #-4
    .word 0x03007FF8 @ movweq r7, #0xff8
    .word 0xE92D4000 @ stmdb sp!, {lr}
    .word 0xE59F305C @ ldr r3, [pc, #0x5c]
    .word 0xE59F205C @ ldr r2, [pc, #0x5c]
    .word 0xE1D210B0 @ ldrh r1, [r2]
    .word 0xE1A01421 @ lsr r1, r1, #8
    .word 0xE1A01081 @ lsl r1, r1, #1
    .word 0xE0833001 @ add r3, r3, r1
    .word 0xE1D310B0 @ ldrh r1, [r3]
    .word 0xE92D000E @ push {r1, r2, r3}
    .word 0xEB000005 @ bl #0x80005ec
    .word 0xE8BD000E @ pop {r1, r2, r3}
    .word 0xE1C300B0 @ strh r0, [r3]
    .word 0xE1C200B0 @ strh r0, [r2]
    .word 0xE1A00001 @ mov r0, r1
    .word 0xE8BD4000 @ ldm sp!, {lr}
    .word 0xE12FFF1E @ bx lr
    .word 0xE59F3028 @ ldr r3, [pc, #0x28]
    .word 0xE5931000 @ ldr r1, [r3]
    .word 0xE59F2024 @ ldr r2, [pc, #0x24]
    .word 0xE0000291 @ mul r0, r1, r2
    .word 0xE59F1020 @ ldr r1, [pc, #0x20]
    .word 0xE0800001 @ add r0, r0, r1
    .word 0xE5830000 @ str r0, [r3]
    .word 0xE1A00820 @ lsr r0, r0, #0x10
    .word 0xE3C00902 @ bic r0, r0, #0x8000
    .word 0xE12FFF1E @ bx lr
    .word 0x030009C2 @ movweq r0, #0x9c2
    .word 0x030009C0 @ movweq r0, #0x9c0
    .word 0x030009BC @ movweq r0, #0x9bc
    .word 0x41C64E6D @ bicmi r4, r6, sp, ror #28
    .word 0x00003039 @ andeq r3, r0, sb, lsr r0
    .word 0xE92D0001 @ stmdb sp!, {r0}
    .word 0xE92D2000 @ stmdb sp!, {sp}
    .word 0xE8BD0001 @ ldm sp!, {r0}
    .word 0xE8BD2000 @ ldm sp!, {sp}
    .word 0xE2800004 @ add r0, r0, #4
    .word 0xE12FFF1E @ bx lr
    .word 0xE92D0F00 @ push {r8, sb, sl, fp}
    .word 0xE3A0C301 @ mov ip, #0x4000000
    .word 0xE59FB02C @ ldr fp, [pc, #0x2c]
    .word 0xE28BA028 @ add sl, fp, #0x28
    .word 0xE3A09001 @ mov sb, #1
    .word 0xE3A08000 @ mov r8, #0
    .word 0xE5CC8208 @ strb r8, [ip, #0x208]
    .word 0xE89A0003 @ ldm sl, {r0, r1}
    .word 0xE8AA0002 @ stm sl!, {r1}
    .word 0xE8AA0001 @ stm sl!, {r0}
    .word 0xE5DB0005 @ ldrb r0, [fp, #5]
    .word 0xE5CB8005 @ strb r8, [fp, #5]
    .word 0xE5CC9208 @ strb sb, [ip, #0x208]
    .word 0xE8BD0F00 @ pop {r8, sb, sl, fp}
    .word 0xE12FFF1E @ bx lr
    .word 0x030024B8 @ movweq r2, #0x4b8
    .word 0xE59F0058 @ ldr r0, [pc, #0x58]
    .word 0xE1D000B0 @ ldrh r0, [r0]
    .word 0xE2800001 @ add r0, r0, #1
    .word 0xE35000A0 @ cmp r0, #0xa0
    .word 0xA12FFF1E @ bxge lr
    .word 0xE1A02200 @ lsl r2, r0, #4
    .word 0xE59F0044 @ ldr r0, [pc, #0x44]
    .word 0xE5D00000 @ ldrb r0, [r0]
    .word 0xE1A00480 @ lsl r0, r0, #9
    .word 0xE0803100 @ add r3, r0, r0, lsl #2
    .word 0xE0821003 @ add r1, r2, r3
    .word 0xE59F0034 @ ldr r0, [pc, #0x34]
    .word 0xE5900000 @ ldr r0, [r0]
    .word 0xE0801001 @ add r1, r0, r1
    .word 0xE59F202C @ ldr r2, [pc, #0x2c]
    .word 0xE5910000 @ ldr r0, [r1]
    .word 0xE5820000 @ str r0, [r2]
    .word 0xE5910004 @ ldr r0, [r1, #4]
    .word 0xE5820004 @ str r0, [r2, #4]
    .word 0xE5910008 @ ldr r0, [r1, #8]
    .word 0xE5820008 @ str r0, [r2, #8]
    .word 0xE591000C @ ldr r0, [r1, #0xc]
    .word 0xE582000C @ str r0, [r2, #0xc]
    .word 0xE12FFF1E @ bx lr
    .word 0x04000006 @ streq r0, [r0], #-6
    .word 0x03002610 @ movweq r2, #0x610
    .word 0x0300260C @ movweq r2, #0x60c
    .word 0x04000020 @ streq r0, [r0], #-0x20
    .word 0xE59F0040 @ ldr r0, [pc, #0x40]
    .word 0xE1D000B0 @ ldrh r0, [r0]
    .word 0xE35000A0 @ cmp r0, #0xa0
    .word 0xA12FFF1E @ bxge lr
    .word 0xE1A02180 @ lsl r2, r0, #3
    .word 0xE59F0030 @ ldr r0, [pc, #0x30]
    .word 0xE5D00000 @ ldrb r0, [r0]
    .word 0xE1A00400 @ lsl r0, r0, #8
    .word 0xE0803100 @ add r3, r0, r0, lsl #2
    .word 0xE0821003 @ add r1, r2, r3
    .word 0xE59F0020 @ ldr r0, [pc, #0x20]
    .word 0xE0801001 @ add r1, r0, r1
    .word 0xE59F201C @ ldr r2, [pc, #0x1c]
    .word 0xE5910000 @ ldr r0, [r1]
    .word 0xE5820000 @ str r0, [r2]
    .word 0xE5910004 @ ldr r0, [r1, #4]
    .word 0xE5820004 @ str r0, [r2, #4]
    .word 0xE12FFF1E @ bx lr
    .word 0x04000006 @ streq r0, [r0], #-6
    .word 0x030056B6 @ movweq r5, #0x6b6
    .word 0x02000000 @ andeq r0, r0, #0
    .word 0x04000040 @ streq r0, [r0], #-0x40
    .word 0xE59F007C @ ldr r0, [pc, #0x7c]
    .word 0xE1D000B0 @ ldrh r0, [r0]
    .word 0xE35000A0 @ cmp r0, #0xa0
    .word 0xA12FFF1E @ bxge lr
    .word 0xE59F1070 @ ldr r1, [pc, #0x70]
    .word 0xE5D12000 @ ldrb r2, [r1]
    .word 0xE1A01382 @ lsl r1, r2, #7
    .word 0xE0811282 @ add r1, r1, r2, lsl #5
    .word 0xE0800001 @ add r0, r0, r1
    .word 0xE59F1060 @ ldr r1, [pc, #0x60]
    .word 0xE0800001 @ add r0, r0, r1
    .word 0xE5D00000 @ ldrb r0, [r0]
    .word 0xE3500000 @ cmp r0, #0
    .word 0x0A00000A @ beq #0x80007ac
    .word 0xE59F0050 @ ldr r0, [pc, #0x50]
    .word 0xE1D010B0 @ ldrh r1, [r0]
    .word 0xE59F004C @ ldr r0, [pc, #0x4c]
    .word 0xE1D020B0 @ ldrh r2, [r0]
    .word 0xE59F0048 @ ldr r0, [pc, #0x48]
    .word 0xE5903000 @ ldr r3, [r0]
    .word 0xE59F0044 @ ldr r0, [pc, #0x44]
    .word 0xE1C010B0 @ strh r1, [r0]
    .word 0xE1C020B4 @ strh r2, [r0, #4]
    .word 0xE5003008 @ str r3, [r0, #-8]
    .word 0xE12FFF1E @ bx lr
    .word 0xE3A010FF @ mov r1, #0xff
    .word 0xE3A02010 @ mov r2, #0x10
    .word 0xE59F302C @ ldr r3, [pc, #0x2c]
    .word 0xE59F0024 @ ldr r0, [pc, #0x24]
    .word 0xE1C010B0 @ strh r1, [r0]
    .word 0xE1C020B4 @ strh r2, [r0, #4]
    .word 0xE5003008 @ str r3, [r0, #-8]
    .word 0xE12FFF1E @ bx lr
    .word 0x04000006 @ streq r0, [r0], #-6
    .word 0x0300571C @ movweq r5, #0x71c
    .word 0x02001340 @ andeq r1, r0, #64, #6
    .word 0x03000056 @ movweq r0, #0x56
    .word 0x0300005A @ movweq r0, #0x5a
    .word 0x0300569C @ movweq r5, #0x69c
    .word 0x04000050 @ streq r0, [r0], #-0x50
    .word 0x3F3F3F3F @ svclo #0x3f3f3f
    .word 0xE59F0060 @ ldr r0, [pc, #0x60]
    .word 0xE1D000B0 @ ldrh r0, [r0]
    .word 0xE35000A0 @ cmp r0, #0xa0
    .word 0xA12FFF1E @ bxge lr
    .word 0xE1A02100 @ lsl r2, r0, #2
    .word 0xE59F0050 @ ldr r0, [pc, #0x50]
    .word 0xE5D00000 @ ldrb r0, [r0]
    .word 0xE1A00380 @ lsl r0, r0, #7
    .word 0xE0803100 @ add r3, r0, r0, lsl #2
    .word 0xE0821003 @ add r1, r2, r3
    .word 0xE59F0040 @ ldr r0, [pc, #0x40]
    .word 0xE0801001 @ add r1, r0, r1
    .word 0xE1D100F0 @ ldrsh r0, [r1]
    .word 0xE1D110F2 @ ldrsh r1, [r1, #2]
    .word 0xE59F2034 @ ldr r2, [pc, #0x34]
    .word 0xE5D22000 @ ldrb r2, [r2]
    .word 0xE59F3030 @ ldr r3, [pc, #0x30]
    .word 0xE3120001 @ tst r2, #1
    .word 0x0A000001 @ beq #0x8000840
    .word 0xE1C300B0 @ strh r0, [r3]
    .word 0xE1C310B2 @ strh r1, [r3, #2]
    .word 0xE2833004 @ add r3, r3, #4
    .word 0xE1A020A2 @ lsr r2, r2, #1
    .word 0xE3520000 @ cmp r2, #0
    .word 0x1AFFFFF7 @ bne #0x8000830
    .word 0xE12FFF1E @ bx lr
    .word 0x04000006 @ streq r0, [r0], #-6
    .word 0x02031988 @ andeq r1, r3, #136, #18
    .word 0x02031488 @ andeq r1, r3, #136, #8
    .word 0x02031989 @ andeq r1, r3, #0x224000
    .word 0x04000010 @ streq r0, [r0], #-0x10
.size arm_runtime, .-arm_runtime
