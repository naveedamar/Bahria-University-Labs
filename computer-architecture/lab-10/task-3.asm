; Calculating the sum of first N integers recursively
.text
.globl main
main:
    li $a0, 5
    jal sumN
    move $a0, $v0
    li $v0, 1
    syscall
    li $v0, 10
    syscall

sumN:
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)
    blez $a0, base
    addi $a0, $a0, -1
    jal sumN
    lw $a0, 0($sp)
    add $v0, $v0, $a0
    j end
base:
    li $v0, 0
end:
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra