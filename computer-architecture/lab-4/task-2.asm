.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0
    li $t1, 0

loop:
    blez $t0, end
    add $t1, $t1, $t0
    addi $t0, $t0, -1
    j loop

end:
    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall