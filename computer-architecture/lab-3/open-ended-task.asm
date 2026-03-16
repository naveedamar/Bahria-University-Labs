.data
	msg1: .asciiz "Enter number: "
	msg2: .asciiz "largest is "
	
.text
.globl main
main:
	
	#prompting user for input and saving it in t(n) 
	li $v0, 4
	la $a0, msg1
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 4
	la $a0, msg1
	syscall
	li $v0, 5
	syscall
	move $t1, $v0
	
	li $v0, 4
	la $a0, msg1
	syscall
	li $v0, 5
	syscall
	move $t2, $v0
	
	#assuming one greatest
	move $t3, $t0
	
	bgt $t1, $t3, update_t1
	j next_check

update_t1:
	move $t3, $t1

next_check:
	bgt $t2, $t3, update_t2
	j done

update_t2:
	move $t3, $t2

done:
	li $v0, 4
	la $a0, msg2
	syscall
	
	move $a0, $t3
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall