; Taking two integers as input and computing their product, quotient, and remainder
.data
    prompt: .asciiz "Enter two integers:\n"
    pMsg:   .asciiz "Product: "
    qMsg:   .asciiz "\nQuotient: "
    rMsg:   .asciiz "\nRemainder: "

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 5
    syscall
    move $t1, $v0

    mult $t0, $t1
    mflo $t2

    div $t0, $t1
    mflo $t3
    mfhi $t4

    li $v0, 4
    la $a0, pMsg
    syscall
    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, qMsg
    syscall
    move $a0, $t3
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, rMsg
    syscall
    move $a0, $t4
    li $v0, 1
    syscall

    li $v0, 10
    syscall