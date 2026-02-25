.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    bgtz $t0, positive
    j not_positive

positive:
    li $v0, 4
    la $a0, msg1
    syscall
    j exit

not_positive:
    li $v0, 4
    la $a0, msg2
    syscall

exit:
    li $v0, 10
    syscall

.data
msg1: .asciiz "The number is positive\n"
msg2: .asciiz "The number is not positive\n"
