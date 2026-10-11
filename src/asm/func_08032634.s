.syntax unified
.cpu arm7tdmi
.text
.balign 4
.global func_08032634
.type func_08032634, %function
.arm

@ func_080A1E2C copies these 160 bytes to 0x03005814, including the literal pool.
func_08032634:
    ldr r0, .L_vcount
    ldrh r0, [r0]
    cmp r0, #0x80
    bxge lr
    ldr r1, .L_selector
    ldrb r1, [r1]
    lsl r1, r1, #7
    add r0, r0, r1
    ldr r1, .L_scanlines
    add r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .L_08032690
    mov r0, #0x04000000
    ldrh r1, [r0]
    bic r1, r1, #0x8200
    strh r1, [r0]
    ldr r0, .L_blend_control
    mov r1, #0
    strh r1, [r0]
    ldr r0, .L_blend_shadow_clear
    strh r1, [r0]
    bx lr
.L_08032690:
    mov r0, #0x04000000
    ldrh r1, [r0]
    orr r1, r1, #0x8200
    strh r1, [r0]
    ldr r0, .L_blend_control
    ldr r1, .L_blend_value
    strh r1, [r0]
    ldr r0, .L_blend_shadow_set
    strh r1, [r0]
    bx lr
.L_vcount:
    .word 0x04000006
.L_selector:
    .word 0x020378E0
.L_scanlines:
    .word 0x020377E0
.L_blend_control:
    .word 0x04000050
.L_blend_shadow_clear:
    .word 0x03000056
.L_blend_value:
    .word 0x00000643
.L_blend_shadow_set:
    .word 0x03000056
.size func_08032634, .-func_08032634
