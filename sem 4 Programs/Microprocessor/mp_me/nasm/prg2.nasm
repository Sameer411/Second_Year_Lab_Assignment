%include "macro.asm"
global _main
_main:
global proc
extern abuflen,buffer

section .text
	proc:
		disp buffer,[abuflen]
		disp msg5,len5
		accept char1,02
		mov bl,[char1]
		mov rsi,buffer
		n2:mov al,[rsi]
	
	cmp al,20h
		je space1
	cmp al,0Ah
		je line1
	cmp al,bl
		je char2
		jmp n1
	
	space1:
		inc byte[spacecounter]
		jmp n1
	line1:
		inc byte[linecounter]
		jmp n1
	char2:
		inc byte[charcounter]
	n1: inc rsi

	dec byte[abuflen]
	jnz n2
	
	disp msg2,len2
	mov rax,[linecounter]
	call display
	
	disp msg3,len3
	mov rax,[spacecounter]
	call display
	
	disp msg4,len4 
	mov rax,[charcounter]
	call display
	
	ret
	
	display:
		mov rsi,disparr + 03
		mov rcx,04
	p1:	
		mov rdx ,0
		mov rbx,10h
		div rbx
		cmp dl,09h
		jbe add30
		add dl,07h
	add30:	
		add dl,30h
		mov [rsi],dl
		dec rsi
		dec rcx
		jnz p1
		mov rax,1
		mov rdi,1
		mov rsi,disparr
		mov rdx,04
		syscall
		ret
		
section .data
	msg2:db "line count is...",10
	len2:equ $-msg2	
	
	msg3:db "space count is....",10
	len3:equ $-msg3	
	
	msg4:db "char counter is.....",10
	len4:equ $-msg4
	msg5:db "Enter char .....",10
	len5:equ $-msg5
	
section .bss
	char1 resb 10
	linecounter resb 10
	spacecounter resb 10
	charcounter resb 10	

	disparr resb 50
