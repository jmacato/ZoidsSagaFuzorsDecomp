.syntax unified
.cpu arm7tdmi
.text
.arm
.global rom_entry
rom_entry:
    .word 0xEA00002E
.size rom_entry, .-rom_entry
