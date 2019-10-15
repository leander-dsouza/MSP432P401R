				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV 	R1, #0x10
				MOV 	R2, #0x13
				MOV 	R3, #0x16
				MOV 	R4, #0x2F
				
				ADD 	R5, R2, R1
				ADD 	R6, R3, R4
				ADD 	R7, R5, R6


				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
