;E4: Multiply number by 16        

.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
             
    MOV AX, 5
    SHL AX, 4
    
    ;Final result = 5d * 16d = 80d
    
    ;ax = 0050h  (80d in hex)
    
    CALL PRINT_NUM
    
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H
    
    MOV AH, 4CH
    INT 21H
    
    
    
MAIN ENDP

PRINT_NUM PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    MOV CX, 0       
    MOV BX, 10      

DIV_LOOP:
    XOR DX, DX      
    DIV BX          
    PUSH DX         
    INC CX
    CMP AX, 0
    JNE DIV_LOOP

PRINT_LOOP:
    POP DX
    ADD DL, '0'
    MOV AH, 02H
    INT 21H
    LOOP PRINT_LOOP

    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUM ENDP

END MAIN