.MODEL SMALL
.STACK 100H
.DATA     

    SLOTS DB 5 DUP(0)
    EARNINGS DW 0
    RATE DB 10
    
    MENU_MSG DB 0DH, 0AH, 0DH, 0AH, '1. Park Vehicle', 0DH, 0AH, '2. Vehicle Exit (Bill)', 0DH, 0AH, '3. View Status', 0DH, 0AH, '4. Exit', 0DH, 0AH, 'Select: $'

    MSG_ASK_SLOT DB 0DH, 0AH, 'Enter Slot ID (0-4): $'
    MSG_ENTRY_TIME DB 0DH, 0AH, 'Enter Entry Hour (0-9): $'
    MSG_EXIT_TIME DB 0DH, 0AH, 'Enter Exit Hour (0-9): $'

    MSG_BOOKED DB 0DH, 0AH, 'Slot Booked. Slot ID: $'
    MSG_OCCUPIED DB 0DH, 0AH, 'Occupied Slots: $'
    MSG_FULL DB 0DH, 0AH, 'Parking is Full!$'
    MSG_EMPTY_SLOT DB 0DH, 0AH, 'Slot is already empty!$'

    MSG_BILL DB 0DH, 0AH, 'Total Bill: $'
    MSG_STATUS DB 0DH, 0AH, 'Total Earnings: $'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MENU_LOOP:     
    
        LEA DX, MENU_MSG
        MOV AH, 09H
        INT 21H

        MOV AH, 01H
        INT 21H

        CMP AL, '1'
        JE PARK_VEHICLE
        CMP AL, '2'
        JE EXIT_VEHICLE
        CMP AL, '3'
        JE VIEW_STATUS
        CMP AL, '4'
        JE EXIT_PROG
JMP MENU_LOOP

    PARK_VEHICLE:

        LEA SI, SLOTS
        MOV CX, 5
        MOV BL, 0

    CHECK_SLOT:

        MOV AL, [SI]
        CMP AL, 0
        JE BOOK_SLOT
        INC SI
        INC BL
        LOOP CHECK_SLOT

        LEA DX, MSG_FULL
        MOV AH, 09H
        INT 21H
JMP MENU_LOOP

    BOOK_SLOT:   
    
        MOV BYTE PTR [SI], 1
        LEA DX, MSG_BOOKED
        MOV AH, 09H
        INT 21H
        
        MOV DL, BL
        ADD DL, '0'
        MOV AH, 02H
        INT 21H
JMP MENU_LOOP

    EXIT_VEHICLE:  
    
        LEA DX, MSG_ASK_SLOT
        MOV AH, 09H
        INT 21H
    
        MOV AH, 01H
        INT 21H
        SUB AL, '0'
        MOV AH, 0
        MOV SI, AX
        
        LEA BX, SLOTS
        ADD BX, SI
        MOV AL, [BX]
        CMP AL, 0
        JE SLOT_IS_EMPTY
    
        MOV BYTE PTR [BX], 0
    
        LEA DX, MSG_ENTRY_TIME
        MOV AH, 09H
        INT 21H
        MOV AH, 01H
        INT 21H
        SUB AL, '0'
        MOV BL, AL
    
        LEA DX, MSG_EXIT_TIME
        MOV AH, 09H
        INT 21H
        MOV AH, 01H
        INT 21H
        SUB AL, '0'
        
        SUB AL, BL
        MUL RATE
        
        ADD EARNINGS, AX
        PUSH AX
    
        LEA DX, MSG_BILL
        MOV AH, 09H
        INT 21H
        
        POP AX
CALL PRINT_NUM
JMP MENU_LOOP

    SLOT_IS_EMPTY: 
    
        LEA DX, MSG_EMPTY_SLOT
        MOV AH, 09H
        INT 21H
JMP MENU_LOOP

    VIEW_STATUS:
    
        LEA DX, MSG_STATUS
        MOV AH, 09H
        INT 21H
        
        MOV AX, EARNINGS
CALL PRINT_NUM
    
    LEA DX, MSG_OCCUPIED
    MOV AH, 09H
    INT 21H
    
    LEA SI, SLOTS
    MOV CX, 5
    MOV BL, 0
    
    COUNT_LOOP:
        MOV AL, [SI]
        ADD BL, AL
        INC SI
    LOOP COUNT_LOOP

    MOV AL, BL
    MOV AH, 0
CALL PRINT_NUM
JMP MENU_LOOP

EXIT_PROG:
    MOV AH, 4CH
    INT 21H
MAIN ENDP

PRINT_NUM PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    MOV CX, 0
    MOV BX, 10

    DIV_LOOP:
        XOR DX, DX
        DIV BX
        PUSH DX
        INC CX
        CMP AX, 0
    JNE DIV_LOOP

    PRINT_LOOP:
        POP DX
        ADD DL, '0'
        MOV AH, 02H
        INT 21H
    LOOP PRINT_LOOP

    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUM ENDP

END MAIN