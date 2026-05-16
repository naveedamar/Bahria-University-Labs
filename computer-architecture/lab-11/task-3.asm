; Multiplying and dividing a number by 2 using bitwise left and right shifts
.data
msgM: .asciiz "Multiplied by 2: "
msgD: .asciiz "\nDivided by 2: "

.text
.globl main
main:
    li $t0, 12
    
    sll $t1, $t0, 1
    srl $t2, $t0, 1
    
    la $a0, msgM
    li $v0, 4
    syscall
    
    move $a0, $t1
    li $v0, 1
    syscall
    
    la $a0, msgD
    li $v0, 4
    syscall
    
    move $a0, $t2
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall