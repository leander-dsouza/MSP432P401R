				INCLUDE MSP432xx_constants.s	    ; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s  ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	   ; make __main visible to linker
				ENTRY
				
__main			PROC
				LDR    R1, =0x10000000		
				LDR    R2, =0x20000000
				LDR	   R3, =0x00000055
				

				STR	R3, [R2]		;send it to RAM2
				LDR	R3, [R1]		;get from RAM1
				
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
