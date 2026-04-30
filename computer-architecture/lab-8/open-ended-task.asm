.data
prompt1: .asciiz "Enter first integer: "
prompt2: .asciiz "Enter second integer: "
msg_prod: .asciiz "Product: "
msg_quot: .asciiz "\nQuotient: "
msg_rem: .asciiz "\nRemainder: "

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt1
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, prompt2
    syscall
    
    li $v0, 5
    syscall
    move $t1, $v0

    mult $t0, $t1
    mflo $t2

    div $t0, $t1
    mflo $t3
    mfhi $t4

    li $v0, 4
    la $a0, msg_prod
    syscall
    
    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, msg_quot
    syscall
    
    move $a0, $t3
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, msg_rem
    syscall
    
    move $a0, $t4
    li $v0, 1
    syscall

    li $v0, 10
    syscall