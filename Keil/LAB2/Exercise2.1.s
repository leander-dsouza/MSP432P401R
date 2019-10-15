			INCLUDE MSP432xx_constants.s          ; Load Constant Definitions
			INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
			AREA    main, CODE, READONLY
			EXPORT	__main	       ; make __main visible to linker
			ENTRY
				
__main			PROC
				MOV 	R1, #0x10	
				MOV 	R2, #0x13
				MOV 	R3, #0x06	
				ADD 	R4, R1, R2
				ADC     R5, R4, R3 
ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
