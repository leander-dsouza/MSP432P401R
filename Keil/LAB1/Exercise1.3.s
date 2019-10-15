				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV 	R1, #0x09
				MOV 	R2, #0x22
				MOV 	R3, #0x04
				MOV 	R4, #0x02
				
				ADD 	R5, R1, R2
				ADD 	R6, R3, R4
				SUB 	R0, R5, R6


				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
