.data
line1: .asciiz "Welcome to CSC 327!\n" 
line2: .asciiz "This is your first MIPS lab.\n" 
line3: .asciiz "Let's start coding!\n"

.text
.global main

main:
li $v0, 4
la $a0, line1 
syscall

li $v0, 4
la $a0, line2
syscall

li $v0, 4
la $a0, line3 
syscall

li $v0, 10 
syscall



		
