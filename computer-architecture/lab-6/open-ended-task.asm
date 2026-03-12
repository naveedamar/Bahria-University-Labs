.data
    arr: .space 400
    p1: .asciiz "Enter N: "
    p2: .asciiz "Enter element: "

.text
.globl main
main:
    li $v0, 4
    la $a0, p1
    syscall

    li $v0, 5
    syscall
    move $s0, $v0

    la $t0, arr
    li $t1, 0

input_loop:
    beq $t1, $s0, setup_reverse
    
    li $v0, 4
    la $a0, p2
    syscall

    li $v0, 5
    syscall
    sw $v0, 0($t0)

    addi $t0, $t0, 4
    addi $t1, $t1, 1
    j input_loop

setup_reverse:
    addi $t0, $t0, -4
    move $t1, $s0

print_loop:
    blez $t1, exit
    
    lw $a0, 0($t0)
    li $v0, 1
    syscall

    li $v0, 11
    li $a0, 32
    syscall

    addi $t0, $t0, -4
    addi $t1, $t1, -1
    j print_loop

exit:
    li $v0, 10
    syscall