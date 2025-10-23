.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 'Enter Multiplicand (-9 to 9): $'
    MSG2 DB 0DH,0AH,'Enter Multiplier (-9 to 9): $'
    MSGR DB 0DH,0AH,'Result = $'
    MULTIPLICAND DB ?
    MULTIPLIER  DB ?
    RESULT DW ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    CMP AL, '-'
    JNE POS_M1
    MOV AH, 01H
    INT 21H
    SUB AL, '0'
    NEG AL
    JMP STORE_M1
POS_M1:
    SUB AL, '0'
STORE_M1:
    MOV MULTIPLICAND, AL

    
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    CMP AL, '-'
    JNE POS_M2
    MOV AH, 01H
    INT 21H
    SUB AL, '0'
    NEG AL
    JMP STORE_M2
POS_M2:
    SUB AL, '0'
STORE_M2:
    MOV MULTIPLIER, AL

    MOV AL, MULTIPLICAND    
    MOV BL, MULTIPLIER      
    IMUL BL                 
    MOV RESULT, AX          
    
    LEA DX, MSGR
    MOV AH, 09H
    INT 21H

    MOV AX, RESULT
    CALL PRINT_DECIMAL

    MOV AH, 4CH
    INT 21H
MAIN ENDP

PRINT_DECIMAL PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    CMP AX, 0
    JGE PD_POS
    MOV DL, '-'
    MOV AH, 02H
    INT 21H
    NEG AX
PD_POS:
    MOV CX, 0
    MOV BX, 10
PD_DIV:
    XOR DX, DX
    DIV BX
    PUSH DX
    INC CX
    CMP AX, 0
    JNE PD_DIV
PD_PRINT:
    POP DX
    ADD DL, '0'
    MOV AH, 02H
    INT 21H
    LOOP PD_PRINT

    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_DECIMAL ENDP

END MAINDX
    POP CX
    POP BX
    POP AX
    RET
PRINT_DECIMAL ENDP

END MAIN