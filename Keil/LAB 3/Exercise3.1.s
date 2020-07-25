 				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main	     ; make __main visible to linker
				ENTRY
				
__main			PROC

				MOV 	R1, #1	
				MOV 	R2, #1
				MOV 	R3, #1
				
				AND		R4,R1,R2
				AND		R7,R4,R3
			

				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
  