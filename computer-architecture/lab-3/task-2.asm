.data
msg_even: .asciiz "Even\n"
msg_odd: .asciiz "Odd\n"

.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    li $t1, 2
    div $t0, $t1
    mfhi $t2

    beq $t2, $zero, print_even

print_odd:
    la $a0, msg_odd
    li $v0, 4
    syscall
    j exit

print_even:
    la $a0, msg_even
    li $v0, 4
    syscall

exit:
    li $v0, 10
    syscall
