.data
num: .word 25          

.text
.globl main
main:
    lw $a0, num      
    li $v0, 1          
    syscall

    li $v0, 10        
    syscall
