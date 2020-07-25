				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main		; make __main visible to linker
				ENTRY
				
__main			PROC
				LDR	R0, = 0x0000004E
				LDR	R1, = 0x0000004F
				LDR	R2, = 0x0000000A
				LDR	R10,= 0x20000000
				LDR R11,= 0x20001000
				
				
__loop			ADD R0, R0, #2
				ADD R1, R1, #2
				
				STR R0,[R10],#4
				STR R1,[R11],#4
				SUBS R2, R2, #1			
				BNE __loop
				ENDP


				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
