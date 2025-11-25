 ;E2: Divide bx by 4 using shift right

.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    MOV BX, 100
    SHR BX, 1
    SHR BX, 1       

    ;BX final result = 25, as we shifted twice, now bx contains bx / 4
    
    MOV AX, BX
    MOV CL, 10
    DIV CL

    MOV BL, AH

    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    MOV AL, BL
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN


    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
           
                                 
