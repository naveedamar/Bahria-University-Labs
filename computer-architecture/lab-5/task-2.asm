.data
    prompt: .asciiz "Enter a number: "
    num: .word 0

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    sw $v0, num

    lw $a0, num
    li $v0, 1
    syscall

    li $v0, 10
    syscall