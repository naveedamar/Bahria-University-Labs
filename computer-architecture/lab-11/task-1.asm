; Masking to extract the lower 4 bits of a hexadecimal number
.data
msg: .asciiz "Lower 4 bits: "

.text
.globl main
main:
    li $t0, 0xAB
    li $t1, 0x0F
    and $t2, $t0, $t1
    
    la $a0, msg
    li $v0, 4
    syscall
    
    move $a0, $t2
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall