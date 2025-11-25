;E1: shift bl left by 4 and show results

.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC 
    
    MOV BL, 00001111B
    MOV CL, 4
    SHL BL, CL
    
    ;bl final result = 11110000b

    MOV BH, 80H
    MOV CX, 8
    
    PRINT_BIT:
        TEST BL, BH
        JZ PRINT_ZERO
        MOV DL, '1'
        MOV AH, 02H
        INT 21H
        JMP NEXT_BIT
    PRINT_ZERO:
        MOV DL, '0'
        MOV AH, 02H
        INT 21H
    NEXT_BIT:
        SHR BH, 1
        LOOP PRINT_BIT

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN        