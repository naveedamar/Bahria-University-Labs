.data
    prompt_x: .asciiz "Enter first number (x): "
    prompt_y: .asciiz "Enter second number (y): "
    x: .word 0
    y: .word 0
    z: .word 0

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt_x
    syscall

    li $v0, 5
    syscall
    sw $v0, x

    li $v0, 4
    la $a0, prompt_y
    syscall

    li $v0, 5
    syscall
    sw $v0, y

    lw $t0, x
    lw $t1, y
    add $t2, $t0, $t1

    sw $t2, z

    lw $a0, z
    li $v0, 1
    syscall

    li $v0, 10
    syscall