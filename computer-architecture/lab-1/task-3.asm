#Task 3: Introduces syscall 11 to print a single character using its ASCII value.
.text
.globl main

main:
    li $v0, 11
    li $a0, 65
    syscall

    li $v0, 11
    li $a0, 10

    syscall

    li $v0, 10
    syscall