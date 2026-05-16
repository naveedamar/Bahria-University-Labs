; Counting the number of characters in a predefined string using a loop
.data
str: .asciiz "Assembly is fun!"
msg: .asciiz "Number of characters: "

.text
.globl main
main:
    la $t0, str
    li $t1, 0

loop:
    lb $t2, 0($t0)
    beqz $t2, done
    
    addi $t1, $t1, 1
    addi $t0, $t0, 1
    j loop

done:
    la $a0, msg
    li $v0, 4
    syscall

    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 10
    syscall