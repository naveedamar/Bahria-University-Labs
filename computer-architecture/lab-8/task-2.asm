; Taking two integers as input and computing their quotient and remainder
.data
    msgQ: .asciiz "\nQuotient: "
    msgR: .asciiz "\nRemainder: "

.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 5
    syscall
    move $t1, $v0

    div $t0, $t1
    mflo $t2
    mfhi $t3

    li $v0, 4
    la $a0, msgQ
    syscall

    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, msgR
    syscall

    move $a0, $t3
    li $v0, 1
    syscall

    li $v0, 10
    syscall