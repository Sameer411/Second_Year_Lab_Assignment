global _start										
_start:

section .text
mov rax,1																					; For First message
mov rdi,1
mov rsi,msg
mov rdx,len
syscall

mov rsi,array																				;For displaying array
l2:push rsi
mov rax,[rsi]
call display

mov rax,1
mov rdi,1
mov rsi,msg1
mov rdx,len1
syscall

pop rsi
add rsi,8
dec byte[cnt1]
jnz l2

mov rsi,array																				;For checking postive or negative number
l3:push rsi
bt qword[rsi],63
jc nc
inc byte[pcnt]
jmp l4
nc:inc byte[ncnt]
l4:pop rsi
add rsi,8
dec byte[cnt2]
jnz l3

mov rax,1																					;
mov rdi,1
mov rsi,msg2
mov rdx,len2
syscall
mov ah,00h
mov al, byte[pcnt]
call display1

mov rax,1
mov rdi,1
mov rsi,msg3
mov rdx,len3
syscall
mov ah,00h
mov al, byte[ncnt]
call display1

mov rax,60
mov rdi,0
syscall

display:
mov rsi,disparr+15
mov rcx,16
l1:mov rdx,0
mov rbx,10h
div rbx
cmp dl,09h
jbe add30
add dl,07h
add30:add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz l1
mov rax,1
mov rdi,1
mov rsi,disparr
mov rdx,16
syscall
ret

display1:
mov rsi,disparr+1
mov rcx,2
l5:mov rdx,0
mov rbx,10h
div rbx
cmp dl,09h
jbe add301
add dl,07h
add301:add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz l5
mov rax,1
mov rdi,1
mov rsi,disparr
mov rdx,2
syscall
ret


section .data
msg:db "The Number is:",10
len:equ $-msg

msg1:db " ",10
len1:equ $-msg1

msg2:db"The positive count is:",10
len2:equ $-msg2

msg3:db"The negative count is:",10
len3:equ $-msg3

array dq 1111111111111111h,222222222222222h,3333333333333333h,4444444444444444h,5555555555555555h
cnt1 db 5
cnt2 db 5

section .bss
disparr resb 16
pcnt resb 1
ncnt resb 1
