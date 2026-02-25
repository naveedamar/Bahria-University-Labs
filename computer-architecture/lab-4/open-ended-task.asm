.data
    space: .asciiz " x "
    eq: .asciiz " = "
    nl: .asciiz "\n"

.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0
    
    li $t1, 1

loop:
    bgt $t1, 10, exit
    
    mul $t2, $t0, $t1

    move $a0, $t0
    li $v0, 1
    syscall

    la $a0, space
    li $v0, 4
    syscall

    move $a0, $t1
    li $v0, 1
    syscall

    la $a0, eq
    li $v0, 4
    syscall

    move $a0, $t2
    li $v0, 1
    syscall

    la $a0, nl
    li $v0, 4
    syscall

    addi $t1, $t1, 1
    j loop

exit:
    li $v0, 10
    syscall