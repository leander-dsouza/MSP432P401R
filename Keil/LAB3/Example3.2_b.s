				INCLUDE MSP432xx_constants.s     ; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	      ; make __main visible to linker
				ENTRY
				
__main			PROC
				MOV 	R1, #0x00 ; 00000	
				MOV 	R2, #0x12 ; 10010
				ORR 	R3, R2, R1  				
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END

