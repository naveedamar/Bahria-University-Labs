; Looping from 1 to 9
.MODEL SMALL
.STACK 100H

.DATA    
    MSG DB 'NUMS: $'
     
.CODE              
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX     
    
    MOV DX, OFFSET MSG
    MOV AH, 09H
    INT 21H
 
    MOV CX, 9        ; loop counter
    MOV BL, 1        ; start from 1
    
    PRINT_LOOP:
        MOV DL, BL
        ADD DL, 30H      ; convert number to ASCII
        MOV AH, 02H
        INT 21H

        INC BL
    LOOP PRINT_LOOP
        
    MOV AH, 4CH
    INT 21H   
MAIN ENDP
END MAIN        