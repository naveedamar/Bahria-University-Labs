.data
    msg1: .asciiz "Enter first number: "
    msg2: .asciiz "Enter second number: "
    msg3: .asciiz "First number is greater\n"
    msg4: .asciiz "Second number is greater\n"

.text
.globl main
main:

    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
    
    li $v0, 4
    la $a0, msg2
    syscall

    li $v0, 5
    syscall
    move $t1, $v0

    sub $t2, $t0, $t1
    bgtz $t2, first_greater

second_greater:
    la $a0, msg4
    li $v0, 4
    syscall
    j exit

first_greater:
    la $a0, msg3
    li $v0, 4
    syscall

exit:
    li $v0, 10
    syscall