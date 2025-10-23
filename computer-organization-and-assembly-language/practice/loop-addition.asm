; ADDING NUMBERS FROM 1 TO 10 USING LOOP
.MODEL SMALL
.STACK 100H

.DATA   
    SUM DW 0       
       
.CODE          
    
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX   

    MOV CX, 10        ; loop counter
    MOV BX, 1        ; start from 1  
    MOV AX, 0
    
    SUM_LOOP:
        ADD AX, BX     
        INC BX
    LOOP SUM_LOOP
                   
    MOV SUM, AX    
    MOV BX, SUM
    MOV DL, (BX / 10) + 30H 
    MOV AH,2     
    INT 21H
               
    MOV DL, (BX MOD 10) + 30H 
    MOV AH,2
    INT 21H
    
    MOV AH, 4CH
    INT 21H   
MAIN ENDP
END MAIN        MAIN         21H   
MAIN ENDP
END MAIN        