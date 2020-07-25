				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV r0, #0
				MOV r1, #4
				MOV r2, #6
				ADD r3, r2, r1

				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
