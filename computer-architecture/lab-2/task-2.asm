.data
    msg1: .asciiz "Enter first no: "
    msg2: .asciiz "Enter second no: "
    msg3: .asciiz "first - second = "
    
.text
.globl main
main:

    li $v0, 4
    la $a0, msg1
    syscall

    li $v0, 5
    syscall
    move $t0, $v0
    
    li $v0, 4
    la $a0, msg2
    syscall

    li $v0, 5
    syscall
    move $t1, $v0

    sub $t2, $t0, $t1

    li $v0, 4
    la $a0, msg3
    syscall
    
    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 10
    syscall
