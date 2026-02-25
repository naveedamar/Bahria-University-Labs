.data
msg1: .asciiz "First number is greater\n"
msg2: .asciiz "Second number is greater\n"

.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 5
    syscall
    move $t1, $v0

    sub $t2, $t0, $t1
    bgtz $t2, first_greater

second_greater:
    la $a0, msg2
    li $v0, 4
    syscall
    j exit

first_greater:
    la $a0, msg1
    li $v0, 4
    syscall

exit:
    li $v0, 10
    syscall
