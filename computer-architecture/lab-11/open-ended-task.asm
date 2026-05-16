; Performing various bitwise operations (masking, toggling, shifting) on user input
.data
prompt: .asciiz "Enter an 8-bit integer: "
msg_upper: .asciiz "\nUpper 4 bits: "
msg_lower: .asciiz "\nLower 4 bits: "
msg_toggle: .asciiz "\nBits 1 and 3 toggled: "
msg_shift: .asciiz "\nShifted left by 2: "

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $t1, 0xF0
    and $t2, $t0, $t1

    li $v0, 4
    la $a0, msg_upper
    syscall
    move $a0, $t2
    li $v0, 1
    syscall

    li $t1, 0x0F
    and $t3, $t0, $t1

    li $v0, 4
    la $a0, msg_lower
    syscall
    move $a0, $t3
    li $v0, 1
    syscall

    li $t1, 10
    xor $t4, $t0, $t1

    li $v0, 4
    la $a0, msg_toggle
    syscall
    move $a0, $t4
    li $v0, 1
    syscall

    sll $t5, $t0, 2

    li $v0, 4
    la $a0, msg_shift
    syscall
    move $a0, $t5
    li $v0, 1
    syscall

    li $v0, 10
    syscall