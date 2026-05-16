; Defining a procedure to calculate the sum of elements in an array
.data
my_array: .word 5, 10, 15, 20, 25
n_val:    .word 5
msg_sum:  .asciiz "The sum is: "

.text
.globl main
main:
    la $a0, my_array
    lw $a1, n_val

    jal sumArray

    move $t0, $v0

    li $v0, 4
    la $a0, msg_sum
    syscall

    move $a0, $t0
    li $v0, 1
    syscall

    li $v0, 10
    syscall

sumArray:
    li $v0, 0
    li $t0, 0
    move $t1, $a0

sum_loop:
    beq $t0, $a1, end_sum

    lw $t2, 0($t1)
    add $v0, $v0, $t2

    addi $t1, $t1, 4
    addi $t0, $t0, 1

    j sum_loop

end_sum:
    jr $ra