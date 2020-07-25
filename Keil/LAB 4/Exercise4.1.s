				INCLUDE MSP432xx_constants.s     ; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	      ; make __main visible to linker
				ENTRY
				
__main			PROC
				MOV R0, #0x20000000
				MOV R1, #0x00000014
				STR R1, [R0,#12]
				MOV R3, R1, ROR #30
				
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
 				END
	