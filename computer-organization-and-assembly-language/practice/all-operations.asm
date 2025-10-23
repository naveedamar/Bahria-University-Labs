.MODEL SMALL
.STACK 100H
.DATA
    NUM1 DB ?
    NUM2 DB ?       
    RESULT DB ?    
    MSG1 DB 'NUM1 = $'  
    MSG2 DB 'NUM2 = $'
    MSGA DB 'Addition = $'
    MSGS DB 'Subtraction = $'
    MSGM DB 'Multiplication = $'
    MSGD DB 'Division = $'
.CODE
MAIN PROC          
    
    MOV AX, @DATA
    MOV DX, AX
    
    MOV DX, OFFSET MSG1
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    SUB AL, '0'
    MOV NUM1, AL
    
    MOV DX, OFFSET MSG2
    MOV AH,09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    SUB AL, '0'
    MOV NUM2, AL
    MOV AL, NUM2
    MOV 
    
MAIN ENDP
END MAIN
