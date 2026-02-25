.data
    my_number: .word 50

.text
.globl main
main:
    lw $a0, my_number
    
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall