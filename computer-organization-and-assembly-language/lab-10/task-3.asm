;E3: Multiply by 10d (decimal) by 4d using left shift, give result in hec                                

.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC      

    MOV AX, 10
    SHL AX, 1
    SHL AX, 1
    
    ;Final ax = 40d = 0028h
    
    CALL PRINT_HEX

    MOV AH, 4CH
    INT 21H
MAIN ENDP
       
PRINT_HEX PROC
    PUSH AX
    PUSH CX
    PUSH BX
    PUSH DX

    MOV BX, AX
    MOV CX, 4
HEX_LOOP:
    ROL BX, 1
    ROL BX, 1
    ROL BX, 1
    ROL BX, 1
    MOV DL, BL
    AND DL, 0Fh
    CMP DL, 9
    JBE DIG
    ADD DL, 7
DIG:
    ADD DL, '0'
    MOV AH, 02h
    INT 21h
    LOOP HEX_LOOP

    POP DX
    POP BX
    POP CX
    POP AX
    RET
PRINT_HEX ENDP
END MAIN             
