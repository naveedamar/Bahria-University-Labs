.data
menu: .asciiz "1.Add 2.Sub 3.Mul > "
msgA: .asciiz "Enter A: "
msgB: .asciiz "Enter B: "
msgR: .asciiz "Result: "
msgInv: .asciiz "Invalid Option\n"

.text
.globl main
main:
    la $a0, menu
    li $v0, 4
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    la $a0, msgA
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $t1, $v0

    la $a0, msgB
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $t2, $v0

    beq $t0, 1, add_case
    beq $t0, 2, sub_case
    beq $t0, 3, mul_case
    j default_case

add_case:
    add $t3, $t1, $t2
    j print
sub_case:
    sub $t3, $t1, $t2
    j print
mul_case:
    mul $t3, $t1, $t2
    j print

default_case:
    la $a0, msgInv
    li $v0, 4
    syscall
    j exit

print:
    la $a0, msgR
    li $v0, 4
    syscall
    move $a0, $t3
    li $v0, 1
    syscall

exit:
    li $v0, 10
    syscall