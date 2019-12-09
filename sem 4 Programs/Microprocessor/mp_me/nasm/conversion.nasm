global _start
_start:
section .text

%macro accept 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro disp 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro
menu:
	disp new,len0
	disp msg,len
	disp choice,len2
	accept choice,02
	mov al,byte[choice]
	cmp al,31h
	je bcd_hex
	cmp al,32h
	je hex_bcd
	cmp al,33h
	je exit

	bcd_hex:
		mov bx,0000h
		mov [res],bx
		disp msg1,len3			;Enter bcd number
		mov rsi,arr
	
	l1:
		push rsi
		accept num,1
		call convert1
		pop rsi
		mov bx,[rsi]
		mul bx
		add [res],ax	
		add rsi,2
		dec byte [cnt]
		jnz l1

		disp msg3,len5
		mov ax,[res]
		call display		
		accept num,1			;so that the enter pressed won't do anything	

		jmp menu

  hex_bcd:
  		disp msg2,len4
		accept num,02
		call convert
		mov [no1],al
		accept num,03
		call convert
		mov [no2],al
		
		mov rsi,arr
		mov ah,[no1]
		mov al,[no2]
        r2:
               
		mov bx,[rsi]
		mov dx,0
		div bx
		mov [rem],dx
		mov [t1],al
		
		push rsi
		disp msg3,len5
		call display2
		
		pop rsi
		
		mov ax,[rem]
		add rsi,2
		dec byte[cnt1]
		jnz r2
		jmp menu
		
		exit:
		mov rax,60
		mov rdi,0
		syscall

convert:
		mov rsi,num
		mov al,[rsi]
		cmp al,39h
		jle a1
		sub al,07h
		a1:
		sub al,30h
		rol al,04
		mov bl,al
		inc rsi
		mov al,[rsi]
		cmp al,39h
		jle a2
		sub al,07h
		a2:
		sub al,30h
		add al,bl
		ret

convert1:
		mov al,[num]
		sub al,30h
		ret
display2:
              	mov al,[t1]
              	cmp al,09h
              	jbe g5
              	add al,07h
              	g5:add al,30h
              	mov [t1],al
              	disp t1,1
              	ret
display:
		mov rsi,disparr + 03
		mov rcx,04
p1:		mov rdx ,0
		mov rbx,10h
		div rbx
		cmp dl,09h
		jbe add30
		add dl,07h
add30:	add dl,30h
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
arr dw 2710h,03E8h,0064h,000Ah,0001h 
cnt db 05
cnt1 db 05
msg :	
			db "Menu: ",10
			db "1.BCD_HEX",10
			db "2.HEX_BCD",10
			db "3.EXIT",10
len:equ $-msg
new: db " ",10
		db "--------------------------------------",10
len0:equ $-new
choice: db "Enter your choice: "
len2:equ $-choice
msg1: db "Enter bcd number : "
len3:equ $-msg1	
msg3: db "     Result is:   "
len5:equ $-msg3
msg2: db "  Enter hex number : "
len4:equ $-msg2

section  .bss
disparr resb 02
cho resb 02
num resb 03
res resb 03
no1 resb 02
no2 resb 02
rem resb 02
t1 resb 02
