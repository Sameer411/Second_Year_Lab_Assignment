global _start
_start:

section .text
	%macro disp 2 
			mov rax,1
			mov rdi,1
			mov rsi,%1
			mov rdx,%2
			syscall
	%endmacro

	%macro read 2 
			mov rax,0
			mov rdi,0
			mov rsi,%1
			mov rdx,%2
			syscall
	%endmacro

	menu:
			disp msg2,len2
			read choice,02
			mov al,byte[choice]
			cmp al,31h
				je without_string
	
			cmp al,32h
				je with_string
	
			cmp al,33h
				je exit
				
	without_string:
			mov rsi,arr
			mov rdi,arr
			add rsi,09 
			add rdi,13
			
			a1:
				mov al ,[rsi]
				mov [rdi],al
				dec rsi
				dec rdi 
				dec byte[cnt1]
				jnz a1
				
				mov rsi,arr
			a2:
				mov rax,[rsi]
				push rsi
				call display
				pop rsi
				inc rsi
				dec byte[cnt2]
				jnz a2
	jmp menu
	
	with_string:
			mov rsi,arr
			mov rdi,arr
			add rsi,09
			add rdi,13
		STD
			mov rcx,0AH 
			rep movsb
			
			mov rsi,arr
		a3:
			mov rax,[rsi]
			push rsi
			call display
			pop rsi
			inc rsi
			dec byte[cnt3]
			jnz a3
			jnp menu	
			
		exit : 
			mov rax,60
			mov rdi,0
			syscall		
		display:
			mov rsi,disparr+1
			mov rcx,02


		l1:
			mov rdx,0
			mov rbx,10h
			div rbx
			cmp dl,09h
			jbe add30
			add al,07h

			add30:add dl,30h
			mov [rsi],dl
			dec rsi
			dec rcx
			jnz l1

			mov rax,1
			mov rdi,1
			mov rsi,disparr
			mov rdx,2
			syscall
		ret
			
section .data
		msg:db"copied array is:",10
		msg1:db" ",10
		len:equ $-msg
		len1:equ $-msg1
			
		msg2:db"menu",10
     		     db"1.without string",10
     		     db"2.with string",10
     		     db"3.exit",10
     		     db"Enter choice",10
		len2:equ $-msg2
		
		arr db 01H,02H,03H,04H,05H,06H,07H,08H,09H,0AH,0BH,0CH,0DH,0EH,0FH
		cnt1 db 10 
		cnt2 db 15
		cnt3 db 15
section .bss
		disparr resb 02
		choice resb 03
