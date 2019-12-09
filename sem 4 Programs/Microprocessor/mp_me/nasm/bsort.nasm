global _start
_start: 
%include "macro.nasm"

;====================================================================

section .text
	%macro disp 2
		mov rax,1
		mov rdi,1
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
		pop rcx								;no. of arguments
		pop rcx								;program name
		pop rcx								;file name
		mov [filename],rcx
		open [filename]
		cmp rax,-1h
		je error
		mov [filehandle],rax
		read [filehandle],buffer,bufflen
		dec rax
		mov [abufflen],rax
		disp msg2,len2
		disp buffer,[abufflen]
		call procedure1						;Find the length of buffer
		call buffer_array					;Create array of integers remove enter
		disp msg3,len3
		call b_sort							;For sorting the elements
		write [filehandle],buffer1,[num1]
		disp buffer1,[num1]
		close [filehandle]
	

	exit1:
		mov rax,60
		mov rdi,0
		syscall

;..................................................................

	error:
		disp msg1,len1                          
		jmp exit1
	
;..................................................................

	procedure1:
			mov rsi,buffer
			mov cl,00h
			mov al,50h
		 c1: 
			mov al,[rsi]
			cmp al,0Ah
			jne c2
			inc cl
			inc cl
		 c2:
			inc rsi
			dec dl
			jnz c1
			mov byte[abufflen],cl
			ret
	
;..................................................................
		
	buffer_array:
			mov rdi,buffer1
			mov rsi,buffer
			mov cl,00h
			mov dl,byte[abufflen]
		a1:	
			mov al,[rsi]
			mov [rdi],al
			inc rsi
			inc rsi
			inc rdi
			inc cl
			dec dl
			dec dl
			jnz a1	
			mov byte[num1],cl
			ret

;..................................................................
			
	b_sort:
			mov cl,[num1]
			mov [cnt1],cl
		z3:
			mov rsi,buffer1
			mov rdi,buffer1
			inc rdi
			mov cl,[num1]
			dec cl
			mov [cnt2],cl
		z2:	
			mov cl,[rsi]
			mov dl,[rdi]
			cmp cl,dl
			jbe z1
			call swap
		z1:
			mov [rsi],cl
			mov [rdi],dl
			inc rsi
			inc rdi
			dec byte[cnt2]
			jnz z2
			dec byte[cnt1]
			jnz z3
			ret
	swap:
			mov al,cl 
			mov cl,dl
			mov dl, al
			ret

;========================================================

section .data
msg1 : db "Error in opening file",10
		  len1: equ $-msg1
msg2 : db "Numbers are :  ",10
		  len2: equ $-msg2
msg3 : db "Sorted Numbers are : ",10
	      len3: equ $-msg3
		
;=========================================================
  
section .bss
	filename resb 200
	filehandle resb 200
	buffer resb 200
	bufflen resb 200
	buffer1 resb 200
	abufflen resb 200
	cnt1 resb 100
	cnt2 resb 100
	num1 resb 100

;===========================================================                                         
