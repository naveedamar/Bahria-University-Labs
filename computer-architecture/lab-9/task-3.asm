; Defining a recursive procedure to calculate the factorial of a number
.text
.globl main
main:
    li $a0, 5
    jal factorial
    move $a0, $v0
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall

factorial:
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)
    blez $a0, base
    addi $a0, $a0, -1
    jal factorial
    lw $a0, 0($sp)
    mul $v0, $a0, $v0
    j end
base:
    li $v0, 1
end:
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra