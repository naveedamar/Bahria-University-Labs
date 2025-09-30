; ADDING NUMBERS FROM 1 TO 10 USING LOOP
.MODEL SMALL
.STACK 100H

.DATA   
    SUM DB ?  
    MSG DB 'SUM: $'  
       
.CODE          
    
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX   

    MOV DX, OFFSET MSG
    MOV AH, 09H
    INT 21H
 
    MOV CX, 10        ; loop counter
    MOV BL, 1        ; start from 1  
    MOV AL, 0
    
    SUM_LOOP:
        ADD AL, BL      
        INC BL
    LOOP SUM_LOOP
                   
    MOV SUM, AL
    
    MOV DX, OFFSET MSG
    MOV AH, 09H
    INT 21H
    
    MOV AL, SUM
    AAM
    
    MOV DL, AH
    ADD DL, 30H
    
    MOV AH, 4CH
    INT 21H   
MAIN ENDP
END MAIN        