.data
    msg1: .asciiz "Enter no: "
    msg2: .asciiz "no + 10 = "
    
.text
.globl main
main:

    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0

    addi $t1, $t0, 10

    li $v0, 4
    la $a0, msg2
    syscall
    
    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall
