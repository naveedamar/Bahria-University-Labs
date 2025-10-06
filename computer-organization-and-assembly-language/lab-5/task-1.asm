.MODEL SMALL
.STACK 100H

.DATA
    MSG1 DB 'Hello, this is the first line.$'
    MSG2 DB 'And this is the second line.$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV DX, OFFSET MSG1
    MOV AH, 09H
    INT 21H                                  
    
    MOV DL, 0DH    
    MOV AH, 02H
    INT 21H

    MOV DL, 0AH    
    MOV AH, 02H
    INT 21H

    MOV DX, OFFSET MSG2
    MOV AH, 09H
    INT 21H

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
