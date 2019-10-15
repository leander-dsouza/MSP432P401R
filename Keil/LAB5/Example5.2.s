				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main		; make __main visible to linker
				ENTRY
				
__main			PROC
				MOV	R0, #10	 		;counter
__loop			LDR	R2,=0x55555555
				STR	R2, [R1]			;send it to RAM
				ADD	R1, R1, #4		;R1 = R1 + 4 to increment pointer
				SUBS R0, R0, #1		;R0 = R0 - 1 for dec counter 
				
				B __loop
				ENDP				
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
