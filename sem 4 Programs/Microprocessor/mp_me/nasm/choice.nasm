global _start
_start:
%include "macro.asm"

section .text
		menu:
			disp msg1,len1
			accept choice,2
			mov al,byte[choice]
			cmp al,31h
			je typec
			cmp al,32h
			je copyc
			cmp al,33h
			je delc
			cmp al,34h
			je exit
			
		typec:
			pop rcx
			pop rcx
			pop rcx
			mov [filename],rcx
			fopen [filename]
			cmp rax,-1h
				je error
			mov [filehandle],rax
			fread [filehandle],buffer,bufflen
			dec rax
			mov [abufflen],rax
			disp buffer,[abufflen]
			jmp menu
			
		copyc:
			pop rcx
			mov [filename1],rcx
			fopen [filename1]
			cmp rax,-1h
				je error
			mov [filehandle1],rax
			fwrite [filehandle1],buffer,abufflen
			fclose[filehandle1]
			fclose[filehandle]
			jmp menu
			
		delc:
				fdelete[filename]
				cmp rax,-1h
					je error
				disp msg2,len2
				jmp menu
				
		exit:
				mov rax,160
				mov rdi,10
				syscall
			
		error:
				disp msg,len
				jmp exit
				
section .data
		
			msg1:db "MENU  :  OPERATIONS",10
			  db "1.Type:",10
			  db "2.Cpoy ",10
			  db "3.Delete",10
			  db "4.Exit ",10
			  db "Enter your choice:",10
			len1:equ $-msg1
				
				msg: db "Error in opening a file"
				len:equ $-msg
				
				msg2: db "File deleted successfully"
				len2:equ $-msg2

section .bss

		buffer resb 200
		bufflen resb 200
		filename resb 200
		filename1 resb 200
		filehandle resb 200
		filehandle1 resb 200
		abufflen resb 200
		choice resb 02				
		
