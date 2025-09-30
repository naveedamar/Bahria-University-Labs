;subtracting two HEX, output in decial        
.MODEL SMALL
.STACK 100H

.DATA
    NUM1 DB 25H
    NUM2 DB 12H
    RESULT DB ?
    MSG DB 'RESULTT =$'
 
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AL, NUM1
    SUB AL, NUM2
    MOV RESULT, AL
                    
    MOV DX, OFFSET MSG 
    AAM 
    MOV AH, 9
    INT 21H
    
    MOV AL, RESULT 
    AAM ;SPLIT AL INTO 2 DECIAML DIGITS, AH = 10S DIGIT, AL = 1S DIGIT    
    MOV DL, 30H
    MOV AH, 2
    INT 21H
           
    MOV DL, AL
    ADD DL, 30H
    MOV AH, 2
    INT 21H
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN