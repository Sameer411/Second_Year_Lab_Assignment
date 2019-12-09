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
			mov rsi,arr1
			mov rdi,arr2
	
			m1:
				mov al,[rsi]
				mov [rdi],al
				inc rsi
				inc rdi
				dec byte[cnt]
				jnz m1
				disp msg,len

				mov rsi,arr2
			m2:
				mov al,[rsi]
				push rsi
				call display
				disp msg1,len1

				pop rsi
				inc rsi
				dec byte[cnt1]
				jnz m2
	jmp menu


	with_string:
				mov rsi,arr1
				mov rdi,arr2
				cld
				mov rcx,05h
				rep movsb
				disp msg,len

				mov rsi,arr2
				m3:
					mov rax,[rsi]
					push rsi
					call display
					disp msg1,len1

				pop rsi
				inc rsi
				dec byte[cnt2]
				jnz m3

	jmp menu


	exit:
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
		     arr1 db 00h,01h,02h,03h,04h
		     arr2 db 00h,00h,00h,00h,00h 
		     cnt db 05
		     cnt1 db 05
		     cnt2 db 05

section .bss
		disparr resb 02
		choice resb 02
