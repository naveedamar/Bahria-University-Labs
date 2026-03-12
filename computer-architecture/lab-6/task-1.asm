.data
arr: .word 5, 10, 15, 20, 25
size: .word 5

.text
.globl main
main:
    la $t0, arr
    lw $t1, size
    li $t2, 0

loop:
    beq $t2, $t1, exit
    lw $a0, 0($t0)
    li $v0, 1
    syscall

    li $v0, 11
    li $a0, 32
    syscall

    addi $t0, $t0, 4
    addi $t2, $t2, 1
    j loop

exit:
    li $v0, 10
    syscall
