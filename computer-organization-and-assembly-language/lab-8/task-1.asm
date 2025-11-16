 ;printing each element of array on new line

.MODEL SMALL
.STACK 100H
.DATA
    arr DB 1, 2, 3, 4, 5
    msg DB 'ARRAY VALUES:', 0DH, 0AH, '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, msg
    MOV AH, 09H
    INT 21H

    
    LEA SI, arr
    MOV CX, 5

PRINT_LOOP:
    MOV AL, [SI]
    CALL PRINT_NUM

    
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H

    INC SI
    LOOP PRINT_LOOP

    MOV AH, 4CH
    INT 21H
MAIN ENDP

PRINT_NUM PROC
    ADD AL, 30H      
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    RET
PRINT_NUM ENDP

END MAIN
 21H
MAIN ENDP
END MAIN
DP

END MAIN
 21H
MAIN ENDP
END MAIN
