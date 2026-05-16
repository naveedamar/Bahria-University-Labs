; Accessing an array of car structs using an offset calculated from user input
.data
cars:
    .word 202, 2018, 1300
    .word 303, 2020, 1500
    .word 404, 2022, 1800

prompt: .asciiz "Select car type (1-3): "
msgModel: .asciiz "\nModel Code: "
msgYear: .asciiz "\nYear: "
msgCC: .asciiz "\nEngine CC: "
msgInv: .asciiz "\nInvalid Option"

.text
.globl main
main:
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 5
    syscall
    move $t0, $v0
    
    beq $t0, 1, load_car1
    beq $t0, 2, load_car2
    beq $t0, 3, load_car3
    j invalid

load_car1:
    li $t1, 0
    j display
load_car2:
    li $t1, 12
    j display
load_car3:
    li $t1, 24
    j display

invalid:
    la $a0, msgInv
    li $v0, 4
    syscall
    li $v0, 10
    syscall

display:
    la $t2, cars
    add $t2, $t2, $t1
    
    lw $t3, 0($t2)
    lw $t4, 4($t2)
    lw $t5, 8($t2)

    la $a0, msgModel
    li $v0, 4
    syscall
    move $a0, $t3
    li $v0, 1
    syscall

    la $a0, msgYear
    li $v0, 4
    syscall
    move $a0, $t4
    li $v0, 1
    syscall

    la $a0, msgCC
    li $v0, 4
    syscall
    move $a0, $t5
    li $v0, 1
    syscall

    li $v0, 10
    syscall