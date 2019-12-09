%include "macro.asm"
global _start
_start:
extern proc
global buffer,abuflen

section .text
	pop rcx 
	pop rcx
	pop rcx
	mov [filename],rcx
	open [filename]
	cmp rax,-1h
		je error
	mov [filehandle],rax
	read [filehandle],buffer,buflen
		dec rax
	mov [abuflen],rax
	
	call proc

	exit:
		close [filehandle]
		mov rax,60
		mov rdi,0
	syscall
	
	error:
		disp msg1,len1
		jmp exit

section .data
	msg1:db "Error in opening file......."
	len1: equ $-msg1

section .bss
	buffer resb 200
	buflen resb 200
	filename resb 100
	filehandle resb 200
	abuflen resb 200
