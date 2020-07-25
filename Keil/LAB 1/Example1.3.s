				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV 	R1, #0x40
				MOV 	R2, #0x20
				SUB 	R3, R1, R2



				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
