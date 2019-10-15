				INCLUDE MSP432xx_constants.s     ; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	      ; make __main visible to linker
				ENTRY
				
__main			PROC
				MOV R1, #0x01
				MOV R1, R1, LSL #1
				MOV R1, R1, LSR #2
				MOV R1, R1, ASR #2
				MOV R1, R1, ROR #16
				ADD R1, R1, R1, LSL #4
				RSB R1, R1, R1, LSL #5

				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
 				END
	