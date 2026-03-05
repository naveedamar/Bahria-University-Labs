.data
a: .word 10
b: .word 20

.text
.globl main
main:
    lw $t0, a          
    lw $t1, b         

    sw $t0, b         
    sw $t1, a         

    
    lw $a0, a
    li $v0, 1
    syscall

    li $v0, 11        
    li $a0, 32
    syscall

    lw $a0, b
    li $v0, 1
    syscall

    li $v0, 10
    syscall
