.data
msg2: .asciiz "Value after setting bit 2: "

.text
.globl main
main:
    li $t0, 32
    li $t1, 4
    or $t2, $t0, $t1
    
    la $a0, msg2
    li $v0, 4
    syscall
    
    move $a0, $t2
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall