 				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV 	R0, #1	
				MOV 	R1, #1
				MOV 	R3, #1
				MOV 	R4, #1
				
				AND		R5,R0,R1
				AND		R6,R3,R4
				AND		R7,R5,R6
				
			

				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
  