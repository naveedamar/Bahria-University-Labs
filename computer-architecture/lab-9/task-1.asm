.text
.globl main
main:
	li $a0, 10
	jal printNum 
	li $v0, 10
	syscall
	
printNum:
	move $t0, $a0
	li $v0, 1
	move $a0, $t0
	syscall
	jr $ra