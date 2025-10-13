; Print lowercase (a-z) and uppercase (A-Z) alphabets using loops
.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 'Lowercase: $'
    MSG2 DB 0DH,0AH,'Uppercase: $'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV DX, OFFSET MSG1
    MOV AH, 9
    INT 21H

    MOV CX, 26
    MOV DL, 'a'
LOWER_LOOP:
    MOV AH, 2
    INT 21H
    INC DL
    LOOP LOWER_LOOP

    MOV DX, OFFSET MSG2
    MOV AH, 9
    INT 21H

    MOV CX, 26
    MOV DL, 'A'
UPPER_LOOP:
    MOV AH, 2
    INT 21H
    INC DL
    LOOP UPPER_LOOP

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
