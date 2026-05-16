; Determining if an input integer is even or odd
.data
    msgE: .asciiz "Even\n"
    msgO: .asciiz "Odd\n"

.text
.globl main
main:
    li $v0, 5
    syscall
    move $t0, $v0

    li $t1, 2
    div $t0, $t1
    mfhi $t2

    beqz $t2, even

    la $a0, msgO
    li $v0, 4
    syscall
    j exit

even:
    la $a0, msgE
    li $v0, 4
    syscall

exit:
    li $v0, 10
    syscall