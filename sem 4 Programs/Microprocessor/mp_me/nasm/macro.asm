%macro open 1 
mov rax, 2
mov rdi,%1
mov rsi, 2
mov rdx, 0777o
syscall
%endmacro 

%macro read 3
mov rax, 0
mov rdi,%1
mov rsi, %2
mov rdx, %3
syscall
%endmacro

%macro write 3
mov rax, 1
mov rdi,%1
mov rsi, %2
mov rdx, %3
syscall
%endmacro

%macro close 1
mov rax, 3
mov rdi,%1
syscall
%endmacro

%macro delete 1
mov rax, 87
mov rdi,%1
syscall
%endmacro

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
