			INCLUDE MSP432xx_constants.s          ; Load Constant Definitions
			INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
			AREA    main, CODE, READONLY
			EXPORT	__main	       ; make __main visible to linker
			ENTRY
				
__main			PROC
				MOV 	R1, #0x18	
				MOV 	R2, #0x10
				
				SUB     R0,R1,R2
				SBC     R3,R0,#0x03

					
				
ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
