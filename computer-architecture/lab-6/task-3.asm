.data
arr: .word 2, 4, 6, 8, 10
size: .word 5

.text
.globl main
main:
    la $t0, arr
    lw $t1, size
    li $t2, 0

loop:
    beqz $t1, done
    lw $t3, 0($t0)
    add $t2, $t2, $t3
    addi $t0, $t0, 4
    addi $t1, $t1, -1
    j loop

done:
    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 10
    syscall
