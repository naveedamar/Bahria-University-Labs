.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    addi $t1, $t0, 10

    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall
