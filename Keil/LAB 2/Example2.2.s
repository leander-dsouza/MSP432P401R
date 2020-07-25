			INCLUDE MSP432xx_constants.s          ; Load Constant Definitions
			INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
			AREA    main, CODE, READONLY
			EXPORT	__main	       ; make __main visible to linker
			ENTRY
				
__main			PROC
				MOV 	R1, #0x40	
				MOV 	R2, #0x20
				MOV 	R3, #0x40	
				MOV 	R4, #0x20
				SUBS 	R5, R1, R2
				SBC    R3, R4, #0x01
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
