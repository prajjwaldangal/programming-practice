;SECTION .data		; data section
;msg:	db "Hello World",10	; the string to print, 10=cr
;len:	equ $-msg		; "$" means "here"
				; len is a value, not an address

;	SECTION .text		; code section
        global main		; make label available to linker 
main:				; standard  gcc  entry point
	push rbp                                  
	mov rbp, rsp                            
	mov [rbp-4], eax                    
	mov eax, [rbp-4]
	imul eax, eax
	;int 21h
	;pop rbp
	ret      
