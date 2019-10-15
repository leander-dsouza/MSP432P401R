 				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV 	R0, #0x10	
				MOV 	R1, #0x10
				CMP 	R1, R0
				;CMN 	R1, R2
				;TST 	R1, R2
				;TEQ 	R1, R2
here
				B here
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
  