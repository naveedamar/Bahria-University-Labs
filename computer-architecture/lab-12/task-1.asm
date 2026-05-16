; Defining and accessing a simple student struct with ID, age, and GPA
.data
student:
    .word 1023
    .word 21
    .word 38

msgID: .asciiz "ID: "
msgAge: .asciiz "\nAge: "
msgGPA: .asciiz "\nGPA: "

.text
.globl main
main:
    la $t0, student
    lw $t1, 0($t0)
    lw $t2, 4($t0)
    lw $t3, 8($t0)

    la $a0, msgID
    li $v0, 4
    syscall
    move $a0, $t1
    li $v0, 1
    syscall

    la $a0, msgAge
    li $v0, 4
    syscall
    move $a0, $t2
    li $v0, 1
    syscall

    la $a0, msgGPA
    li $v0, 4
    syscall
    li $t4, 10
    div $t3, $t4
    mflo $a0
    li $v0, 1
    syscall

    li $v0, 10
    syscall