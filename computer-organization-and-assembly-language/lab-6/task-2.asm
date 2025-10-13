; Print numbers from 1 to 9 using loop
.MODEL SMALL
.STACK 100H
.DATA
    MSG DB 'Numbers: $'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV DX, OFFSET MSG
    MOV AH, 9
    INT 21H

    MOV CX, 9
    MOV DL, '1'
PRINT_LOOP:
    MOV AH, 2
    INT 21H
    INC DL
    LOOP PRINT_LOOP

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
