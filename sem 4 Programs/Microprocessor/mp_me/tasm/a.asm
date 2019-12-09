data segment
	msg db"Hello World$"
data ends

code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov ah,09h
	lea dx,msg
	int 21h
	mov ah,4Ch
	int 21h
code ends
end start
