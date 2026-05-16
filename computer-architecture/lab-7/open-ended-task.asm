.data
    prompt:  .asciiz "Enter a sentence (up to 100 chars): "
    result:  .asciiz "Total vowel count: "
    buffer:  .space 101

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 8
    la $a0, buffer
    li $a1, 101
    syscall

    la $t0, buffer
    li $t1, 0

loop:
    lb $t2, 0($t0)
    beqz $t2, display

    li $t3, 'a'
    beq $t2, $t3, count

    li $t3, 'e'
    beq $t2, $t3, count

    li $t3, 'i'
    beq $t2, $t3, count

    li $t3, 'o'
    beq $t2, $t3, count

    li $t3, 'u'
    beq $t2, $t3, count

    j next_char

count:
    addi $t1, $t1, 1

next_char:
    addi $t0, $t0, 1
    j loop

display:
    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 10
    syscall