			INCLUDE MSP432xx_constants.s          ; Load Constant Definitions
			INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
			AREA    main, CODE, READONLY
			EXPORT	__main	       ; make __main visible to linker
			ENTRY
				
__main			PROC
				MOV 	R1, #0x12	
				MOV 	R2, #0x14
				MOV 	R3, #0x64	
				
				ADD     R4,R1,R2
				RSB     R5,R3,R4
ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END


