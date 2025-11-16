;printing array elements along with there index number

.MODEL SMALL
.STACK 100H
.DATA
    arr DB 5, 10, 15, 20, 25
    msg DB 0DH, 0AH, 'INDEX  : VALUE', 0DH, 0AH, '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, msg
    MOV AH, 09H
    INT 21H

    LEA SI, arr
    MOV CX, 5
    MOV BL, 0

LOOP123:
    MOV AL, BL
    CALL PRINT_NUM

    MOV DL, ' '
    MOV AH, 02H
    INT 21H    
        
    MOV DL, ' '
    MOV AH, 02H
    INT 21H
    
    MOV AL, [SI]
    CALL PRINT_NUM
    
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
        
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H
    
    INC BL
    INC SI
LOOP LOOP123

    MOV AH, 4CH
    INT 21H
MAIN ENDP

PRINT_NUM PROC
    PUSH AX
    PUSH BX
    PUSH DX
    
    MOV AH, 0
    CMP AL, 9
    JBE SINGLE_DIGIT_PRINT

    MOV BL, 10
    DIV BL
    
    PUSH AX
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    POP AX

    MOV AL, AH
    JMP FINAL_PRINT
    
SINGLE_DIGIT_PRINT:
    
FINAL_PRINT:
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    POP DX
    POP BX
    POP AX
    RET
PRINT_NUM ENDP

END MAINDP

END MAIN

