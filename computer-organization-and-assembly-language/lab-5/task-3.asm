.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 'Enter first number (0-9): $'
    MSG2 DB 'Enter second number (0-9): $'
    EQUAL_MSG DB 'Numbers are equal.$'
    NOTEQUAL_MSG DB 'Numbers are not equal.$'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV DX, OFFSET MSG1
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    SUB AL, 30H
    MOV BL, AL

    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H

    MOV DX, OFFSET MSG2
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    SUB AL, 30H
    MOV BH, AL

    CMP BL, BH
    JE EQUAL_LABEL

NOTEQUAL_LABEL:
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H

    MOV DX, OFFSET NOTEQUAL_MSG
    MOV AH, 09H
    INT 21H
    JMP EXIT

EQUAL_LABEL:
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H

    MOV DX, OFFSET EQUAL_MSG
    MOV AH, 09H
    INT 21H

EXIT:
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN