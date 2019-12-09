%macro display 2  
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro accept 2 
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

global _start
_start:

	display msg,len
	accept num,3
	call convert

	cmp al,01h
	ja fact
	display msg1,len1
exit:

fact:
	mov rcx,rax
	dec rcx
l1:
	push rax
	dec rax
	cmp rax,01h
	ja l1
	
l2:
	pop rbx
	mul rbx
	dec rcx
	jnz l2
	
	call display1
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
	
convert:
	mov rsi,num
	mov al,[rsi]
	cmp al,39h
	jle a1	
	sub al,09h
a1:	sub al,30h
	rol al,04
	mov bl,al
	inc rsi
	mov al,[rsi]
	cmp al,39h
	jle a2	
	sub al,07h
a2:	sub al,30h
	add al,bl
	ret	

section .data

	msg db "Enter the number : ",10
	len equ $-msg
	
	msg1 db "Factorial of a number is 1",10
	len1 equ $-msg1

section .bss

	num resb 50
	no resb 50
	disparr resb 50
