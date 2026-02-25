.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0
    li $t1, 1

loop:
    blez $t0, done
    mul $t1, $t1, $t0
    addi $t0, $t0, -1
    j loop

done:
    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall
