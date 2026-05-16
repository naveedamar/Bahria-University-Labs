.data
msg: .asciiz "Sum using loop unrolling: "
arr: .word 2,4,6,8,10,12,14,16

.text
.globl main
main:
    la $t0, arr
    li $t1, 0

    lw $t2, 0($t0)
    lw $t3, 4($t0)
    add $t1, $t1, $t2
    add $t1, $t1, $t3

    lw $t2, 8($t0)
    lw $t3, 12($t0)
    add $t1, $t1, $t2
    add $t1, $t1, $t3

    lw $t2, 16($t0)
    lw $t3, 20($t0)
    add $t1, $t1, $t2
    add $t1, $t1, $t3

    lw $t2, 24($t0)
    lw $t3, 28($t0)
    add $t1, $t1, $t2
    add $t1, $t1, $t3

    la $a0, msg
    li $v0, 4
    syscall

    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall