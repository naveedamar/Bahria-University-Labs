.data
    msg: .asciiz "Enter a number: "
    positive_msg: .asciiz "Number is positive"
    negative_msg: .asciiz "Number is negative"

.text
.globl main
main:
 
    li $v0, 4
    la $a0, msg
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
        
    bgtz $t0, positive
    j negative
    
    positive:
        li $v0, 4
        la $a0, positive_msg
        syscall
            
        j exit
    
    negative:
        li $v0, 4
        la $a0, negative_msg
        syscall
        
        j exit
        
    exit:
        li $v0, 10
        syscall