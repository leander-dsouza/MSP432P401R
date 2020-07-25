				INCLUDE MSP432xx_constants.s     ; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	      ; make __main visible to linker
				ENTRY
				
__main			PROC
				MOV 	R1, #0x01
				STR R0, [R1,#4]
				STR R0, [R1], #4
				LDR R2, [R0]
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
