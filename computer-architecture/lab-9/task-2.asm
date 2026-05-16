; Defining a procedure to add two numbers passed as arguments
.text
.globl main
main:
	li $a0, 5
	li $a1, 3
	jal addNums
	
	move $a0, $v0
	li $v0, 1
	syscall

	li $v0, 10
	syscall

addNums:
	add $v0, $a0, $a1
	jr $ra