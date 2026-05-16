.text
.globl main
main:
    li $a0, 2
    li $a1, 3
    jal power
    move $a0, $v0
    li $v0, 1
    syscall
    li $v0, 10
    syscall

power:
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $a0, 4($sp)
    sw $a1, 0($sp)
    blez $a1, p_base
    addi $a1, $a1, -1
    jal power
    lw $a0, 4($sp)
    mul $v0, $v0, $a0
    j p_end
p_base:
    li $v0, 1
p_end:
    lw $ra, 8($sp)
    addi $sp, $sp, 12
    jr $ra