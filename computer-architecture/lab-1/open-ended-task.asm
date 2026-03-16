.data
    my_number: .word 50

.text
.globl main
main:

    li $v0, 1
    lw $a0, my_number
    syscall

    li $v0, 10
    syscall