.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 'Enter first number: $'
    MSG2 DB 0DH,0AH,'Enter second number: $'
    MSGADD DB 0DH,0AH,'Addition Result: $'
    MSGSUB DB 0DH,0AH,'Subtraction Result: $'
    MSGMUL DB 0DH,0AH,'Multiplication Result: $'
    MSGDIV DB 0DH,0AH,'Division Result: $'

    NUM1 DB ?
    NUM2 DB ?
    RESULT DB ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; input first 
    LEA DX, MSG1
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    SUB AL, '0'
    MOV NUM1, AL

    ; input second
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    SUB AL, '0'
    MOV NUM2, AL

    ; addition 
    LEA DX, MSGADD
    MOV AH, 09H
    INT 21H

    MOV AL, NUM1
    ADD AL, NUM2
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ; subtraction 
    LEA DX, MSGSUB
    MOV AH, 09H
    INT 21H

    MOV AL, NUM1
    SUB AL, NUM2
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ; multiplication 
    LEA DX, MSGMUL
    MOV AH, 09H
    INT 21H

    MOV AL, NUM1
    MOV BL, NUM2
    MUL BL                ; AX = AL * BL
    MOV AH, 0             ; clear high byte
    AAM                   ; convert AL (binary) -> AH=tens, AL=ones (decimal)
    ADD AH, '0'
    MOV DL, AH
    MOV AH, 02H
    INT 21H
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ; division 
     LEA DX, MSGDIV
    MOV AH, 09H
    INT 21H

    MOV AL, NUM1
    MOV AH, 0
    MOV BL, NUM2
    DIV BL                ; AL = Quotient, AH = Remainder
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ; exit program 
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
