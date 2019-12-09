global _start
_start:
section .text
mov rax,1
mov rdi,1
mov rsi,msg
mov rdx,len
syscall

mov rax,60
mov rdi,0
syscall

section .data
msg:db "Good Morning!!"
len:equ $-msg

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
