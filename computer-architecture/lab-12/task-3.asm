; Accessing an array of student structs based on user selection
.data
students:
    .word 1001, 20, 35
    .word 1002, 22, 32
    .word 1003, 19, 38

prompt: .asciiz "Select student (1-3): "
invmsg: .asciiz "Invalid selection. Exiting...\n"
msgID: .asciiz "\nID: "
msgAge: .asciiz "\nAge: "
msgGPA: .asciiz "\nGPA (x10): "

.text
.globl main
main:
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 5
    syscall
    move $s0, $v0

    li $t0, 1
    blt $s0, $t0, invalid
    li $t0, 3
    bgt $s0, $t0, invalid

    addi $s0, $s0, -1

    sll $t1, $s0, 3
    sll $t2, $s0, 2
    add $t3, $t1, $t2

    la $t4, students
    add $t5, $t4, $t3

    lw $t6, 0($t5)
    lw $t7, 4($t5)
    lw $t8, 8($t5)

    la $a0, msgID
    li $v0, 4
    syscall
    move $a0, $t6
    li $v0, 1
    syscall

    la $a0, msgAge
    li $v0, 4
    syscall
    move $a0, $t7
    li $v0, 1
    syscall

    la $a0, msgGPA
    li $v0, 4
    syscall
    move $a0, $t8
    li $v0, 1
    syscall

    li $v0, 10
    syscall

invalid:
    la $a0, invmsg
    li $v0, 4
    syscall

    li $v0, 10
    syscall