%macro display 2  
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

global _start
_start:

section .text

	smsw eax
	mov[cr0_data],eax
	bt eax,00
	jc protected_mode
	display msg,len
	jmp exit

protected_mode:
	display msg1,len1
	mov ax,[cr0_data+2]
	
	call display1
		mov ax,[cr0_data]
	call display1
		display msg3,len3

	sgdt[gdtdata]
	mov ax,[gdtdata+4]
	call display1
		mov ax,[gdtdata+2]
	call display1
		mov ax,[gdtdata]
	call display1
	display msg4,len4

	sidt[idtdata]
	mov ax,[idtdata+4]
	call display1
		mov ax,[idtdata+2]
	call display1
		mov ax,[idtdata]
	call display1
		display msg5,len5

	sldt[ldtdata]
	mov ax,[ldtdata]
	call display1
		display msg6,len6

	str[trdata]
	mov ax,[trdata]
	call display1
	display msg7,len7
 
	exit:
		mov rax,60
		mov rdi,0
	syscall

display1:
	mov rsi,disparr+3
	mov rcx,4
	l:mov rdx,0
	mov rbx,10h
	div rbx
	cmp dl,09h
	jbe add30
	add dl,07h
	add30:add dl,30h
	mov [rsi],dl
	dec rsi
	dec rcx
	jnz l
	mov rax,1
	mov rdi,1
	mov rsi,disparr
	mov rdx,4
	syscall
	ret

section .data
	msg db "Real mode",10
	len equ $-msg
	msg1 db "Protected mode",10
	len1 equ $-msg1
	msg4 db " :contents of GDTR",10
	len4 equ $-msg4
	msg5 db " :contents of IDTR",10
	len5 equ $-msg5
	msg6 db " :contents of LDTR",10
	len6 equ $-msg6
	msg7 db " :contents of TR",10
	len7 equ $-msg7
	
section .bss
cr0_data resb 10
gdtdata resb 10
ldtdata resb 10
trdata resb 10
idtdata resb 10	
disparr resb 200
