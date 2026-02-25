.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 5
    syscall
    move $t1, $v0

    add $t2, $t0, $t1

    sub $t3, $t0, $t1

    sub $t4, $t2, $t3

    move $a0, $t4
    li $v0, 1
    syscall

    li $v0, 10
    syscall