; Comparing normal array sum loop with loop unrolling for optimization
.data
arr: .word 1,2,3,4,5,6,7,8,9,10
msg1: .asciiz "Sum (Normal Loop): "
msg2: .asciiz "\nSum (Optimized Loop): "

.text
.globl main
main:
    la $t0, arr
    li $t1, 0
    li $t2, 10

normal_loop:
    lw $t3, 0($t0)
    add $t1, $t1, $t3
    addi $t0, $t0, 4
    addi $t2, $t2, -1
    bgtz $t2, normal_loop

    la $a0, msg1
    li $v0, 4
    syscall

    move $a0, $t1
    li $v0, 1
    syscall

    la $t0, arr
    lw $s0, 0($t0)
    lw $s1, 4($t0)
    lw $s2, 8($t0)
    lw $s3, 12($t0)
    lw $s4, 16($t0)
    lw $s5, 20($t0)
    lw $s6, 24($t0)
    lw $s7, 28($t0)
    lw $t8, 32($t0)
    lw $t9, 36($t0)

    add $a1, $s0, $s1
    add $a1, $a1, $s2
    add $a1, $a1, $s3
    add $a1, $a1, $s4
    add $a1, $a1, $s5
    add $a1, $a1, $s6
    add $a1, $a1, $s7
    add $a1, $a1, $t8
    add $a1, $a1, $t9

    la $a0, msg2
    li $v0, 4
    syscall

    move $a0, $a1
    li $v0, 1
    syscall

    li $v0, 10
    syscall