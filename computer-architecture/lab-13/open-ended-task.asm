; Comparing the performance of summing a large array using a standard loop versus a 4x unrolled loop
.data
arr: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
msg_norm: .asciiz "Sum (Normal): "
msg_opt:  .asciiz "\nSum (Optimized): "

.text
.globl main
main:
    la $t0, arr
    li $t1, 0
    li $t2, 20

norm_loop:
    lw $t3, 0($t0)
    add $t1, $t1, $t3
    addi $t0, $t0, 4
    addi $t2, $t2, -1
    bgtz $t2, norm_loop

    la $a0, msg_norm
    li $v0, 4
    syscall
    move $a0, $t1
    li $v0, 1
    syscall

    la $t0, arr
    li $t1, 0
    li $t2, 5

opt_loop:
    lw $t3, 0($t0)
    lw $t4, 4($t0)
    lw $t5, 8($t0)
    lw $t6, 12($t0)

    add $t1, $t1, $t3
    add $t1, $t1, $t4
    add $t1, $t1, $t5
    add $t1, $t1, $t6

    addi $t0, $t0, 16
    addi $t2, $t2, -1
    bgtz $t2, opt_loop

    la $a0, msg_opt
    li $v0, 4
    syscall
    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall