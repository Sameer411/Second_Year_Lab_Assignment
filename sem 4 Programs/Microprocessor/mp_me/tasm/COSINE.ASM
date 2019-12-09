
.model small
.stack 100
.data
x dd 0.0
xad dd 3.0
one80 dd 180.0
thirty dd 30.0
fifty dd 50.0
row db 00
col db 00
xcursor dd 00
ycursor dt 00
count dw 360
x1 dw 00

.code
.386
main:

mov ax,@data
mov ds,ax

mov ah,00
mov al,6
int 10h

up1:
        finit
        fldpi
        fdiv one80
        fmul x
        fcos
        fmul thirty
        fld fifty
        fsub st,st(1)
        fbstp ycursor
        lea si,ycursor
        mov ah,0ch
        mov al,01h
        mov bh,0h
        mov cx,x1
        mov dx,[si]
        int 10h
        inc x1
        fld x
        fadd xad
        fst x
        dec count
        jnz up1

        mov ah,4ch
        int 21h
        end main

