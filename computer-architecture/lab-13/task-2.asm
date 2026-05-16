; Summing an array utilizing a simplified pointer update loop structure
.data
msg: .asciiz "Sum using strength reduction: "
arr: .word 5, 10, 15, 20, 25

.text
.globl main
main:
    la $t0, arr
    li $t1, 0
    li $t2, 5

loop_opt:
    lw $t3, 0($t0)
    add $t1, $t1, $t3
    addi $t0, $t0, 4
    addi $t2, $t2, -1
    bgtz $t2, loop_opt

    la $a0, msg
    li $v0, 4
    syscall

    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall