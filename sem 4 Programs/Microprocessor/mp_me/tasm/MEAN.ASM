data segment
msg db 13,10,"Welcome$"
msg1 db 13,10,"Mean Is:$"
msg2 db 13,10,"Variance Is:$"
msg3 db 13,10,"Standard D Is:$"
no1 dd 3.5
no2 dd 5.5
no3 dd 7.5
n dd 3.0
m dd ?
temp1 dd ?
temp2 dd ?
temp3 dd ?
v dd ?
s dd ?
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

;for calculating mean.

finit
fld no1
fadd no2
fadd no3
fdiv n
fst m
mov ah,09h
lea dx,msg1
int 21h
lea si,m
mov ch,04h
a1:mov al,[si+3]
call disp
dec si
dec ch
jnz a1

;for calculating variance.

fld no1
fsub m
fst temp1
fmul temp1
fst temp1

fld no2
fsub m
fst temp2
fmul temp2
fst temp2

fld no3
fsub m
fst temp3
fmul temp3
fst temp3

fadd temp2
fadd temp1
fst v
mov ah,09h
lea dx,msg2
int 21h
lea si,v
mov ch,04h
a2:mov al,[si+3]
call disp
dec si
dec ch
jnz a2

;for calculating standard deviation.

fld v
fsqrt
fst s
mov ah,09h
lea dx,msg3
int 21h
lea si,s
mov ch,04h
a3:mov al,[si+3]
call disp
dec si
dec ch
jnz a3

mov ah,4ch
int 21h

disp proc near
mov bl,al
and al,0F0h
rol al,04
cmp al,09h
jle l1
add al,07h
l1:add al,30h
mov ah,02h
mov dl,al
int 21h
mov al,bl
and al,0Fh
cmp al,09h
jle l2
add al,07h
l2:add al,30h
mov ah,02h
mov dl,al
int 21h
ret
disp endp
code ends
end start


