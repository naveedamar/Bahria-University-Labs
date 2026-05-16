; Taking user input for a name and printing a personalized greeting
.data
buffer: .space 50
prompt: .asciiz "Enter your name: "
result: .asciiz "Hello, "

.text
.globl main
main:
    la $a0, prompt
    li $v0, 4
    syscall

    la $a0, buffer
    li $a1, 50
    li $v0, 8
    syscall

    la $a0, result
    li $v0, 4
    syscall

    la $a0, buffer
    li $v0, 4
    syscall

    li $v0, 10
    syscall