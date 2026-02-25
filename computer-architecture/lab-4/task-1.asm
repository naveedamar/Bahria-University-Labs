.text
.globl main
main:
    li $t0, 1 

loop:
    bgt $t0, 10, exit
    move $a0, $t0
    li $v0, 1
    syscall

    li $v0, 11  
    li $a0, 32
    syscall

    addi $t0, $t0, 1
    j loop

exit:
    li $v0, 10
    syscall
