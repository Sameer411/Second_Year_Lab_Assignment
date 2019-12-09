global _start
  _start:
section .text

				;macro
%macro disp 2
    mov rax,1
    mov rdi,1  
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro
 
%macro accept 2
      mov rax,0
      mov rdi,0
      mov rsi,%1
      mov rdx,%2
      syscall
%endmacro
mov rsi,msg1
      


	
				;menu function
menu:

      disp msg,len
      accept choice,2
      mov al,byte[choice]
      cmp al,31H
      	je Successive_add
      cmp al,32H
      	je Addshift
      cmp al,33H
      	je Exit

				; successive addition function
Successive_add:

	disp msg1,len1		;Enter 1st no 
	accept num,03
	call convert
	mov [no1],al		
	
	disp msg2,len2		;Enter 2nd no
	accept num,03
	call convert
	mov [no2],al
	
	mov bx,0000h
	mov [res],bx
	mov bx,[no1]
a3:	add [res],bx
	dec byte[no2]
	jnz a3
	
	mov ax,[res]
	call display
	jmp menu

				;add & shift function
Addshift:

	disp msg1,len1		;Enter 1st no 
	accept num,03
	call convert
	mov [no1],al		
	
	disp msg2,len2		;Enter 2nd no
	accept num,03
	call convert
	mov [no2],al		
	mov bx, 0000h
	mov [res],bx
	mov ax,[no1]
	mov bx,[no2]
	
	a5: shr bx,01
	jnc a4
	
	add [res],ax
	a4: shl ax,01
	cmp ax,00
	jz a6
	cmp bx,0000h
	jnz a5
	
	a6: mov ax,[res]
	call display
	
	jmp menu

				;exit function
Exit:

	mov rax,60
	mov rdi,0
	syscall
				;displaying the procedure
display:

	mov rsi,disparr+3
	mov rcx,4
l2:     mov rdx,0
	mov rbx,10H
	div rbx
	cmp dl,09H
	jbe l1
	
	add dl,07H
l1:     add dl,30H
	mov[rsi],dl
	dec rsi
	dec rcx
	jnz l2
	
	mov rax,1
	mov rdi,1
	mov rsi,disparr
	mov rdx,4
	syscall
	ret
				;convert function
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
msg:	db "Menu:",10
	db "1.Successive addition",10
	db "2.Addshift",10
	db "3.Exit",10
	db "Enter choice",10
len:	equ $-msg
msg1:	db "Enter first no.",10
len1:	equ $-msg1
msg2:	db "Enter second no.",10
len2:	equ $-msg2

section .bss
	num resb 03
	no1 resb 02
	no2 resb 02
	choice resb 02
	res resb 04
	disparr resb 04
