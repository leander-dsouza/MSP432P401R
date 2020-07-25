				INCLUDE MSP432xx_constants.s	; Load Constant Definitions
				INCLUDE MSP432xx_tim_constants.s   ; TIM Constants
				AREA    main, CODE, READONLY
				EXPORT	__main		; make __main visible to linker
				ENTRY
				
__main			PROC
				LDR	R0, = 0x00000000
				LDR	R1, = 0x00000001
				LDR	R2, = 0x00000002
				LDR	R3, = 0x00000003
				LDR	R4, = 0x00000004
				LDR	R5, = 0x00000005
				LDR	R6, = 0x00000006
				LDR	R7, = 0x00000007
				LDR	R8, = 0x00000008
				LDR	R9, = 0x00000009
				LDR	R10,= 0x20000000
				
				
				STMIA R10!,{R0-R9}
				LDMDB R10!,{R0-R9}
				
				ENDP
					
				ALIGN
				AREA allocations, DATA, READWRITE
				END
