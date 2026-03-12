.data
arr: .word 12, 7, 25, 3, 18
size: .word 5

.text
.globl main
main:
    la $t0, arr
    lw $t1, size
    lw $t2, 0($t0)
    addi $t0, $t0, 4
    addi $t1, $t1, -1

loop:
    beqz $t1, done
    lw $t3, 0($t0)
    ble $t3, $t2, skip
    move $t2, $t3

skip:
    addi $t0, $t0, 4
    addi $t1, $t1, -1
    j loop

done:
    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 10
    syscall
