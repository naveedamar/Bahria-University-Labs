;taking three values from user, adding them and displaying the sum

.MODEL SMALL
.STACK 100H
.DATA
    arr DB 3 DUP(?)
    msg1 DB 0DH,0AH,'ENTER 3 NUMBERS (0 TO 9): $'
    msg2 DB 0DH,0AH,'SUM = $'
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    LEA DX,msg1
    MOV AH,09H
    INT 21H

    LEA SI,arr
    MOV CX,3
    XOR BL,BL        

READ_LOOP:
    MOV AH,01H       
    INT 21H
    SUB AL,'0'       
    MOV [SI],AL
    ADD BL,AL        ;
    INC SI
    LOOP READ_LOOP

    LEA DX,msg2
    MOV AH,09H
    INT 21H

    MOV AL,BL
    CALL PRINT_NUM

    MOV AH,4CH
    INT 21H
MAIN ENDP

PRINT_NUM PROC
    CMP AL,9
    JBE SINGLE_DIGIT

    MOV AH,0
    MOV BL,10
    DIV BL
    ADD AL,'0'
    MOV DL,AL
    MOV AH,02H
    INT 21H

    MOV AL,AH
    ADD AL,'0'
    MOV DL,AL
    MOV AH,02H
    INT 21H
    RET

SINGLE_DIGIT:
    ADD AL,'0'
    MOV DL,AL
    MOV AH,02H
    INT 21H
    RET
PRINT_NUM ENDP
END MAIN



