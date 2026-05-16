.text
.globl main
main:
    li $a0, 6
    jal fib
    move $a0, $v0
    li $v0, 1
    syscall
    li $v0, 10
    syscall

fib:
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $a0, 4($sp)
    ble $a0, 1, base_case
    addi $a0, $a0, -1
    jal fib
    move $t0, $v0
    lw $a0, 4($sp)
    addi $a0, $a0, -2
    jal fib
    add $v0, $v0, $t0
    j end_fib
base_case:
    move $v0, $a0
end_fib:
    lw $ra, 8($sp)
    addi $sp, $sp, 12
    jr $ra