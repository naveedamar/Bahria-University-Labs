.text
.globl main 
main:
	li $a0, 5
	li $a1, 3
	jal addNums
	
	move $a0, $v0
	syscall

	li $v0, 10 
	syscall
	
addNums:
	add $v0, $a0, $a1