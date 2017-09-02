%define STDOUT			1

global _ft_putchar
global ft_putchar

section .bss
	char: resb 1

section .text

_ft_putchar:
ft_putchar:
	xor rdx, rdx
	mov dl, dil
	mov [char], rdx

	mov rdi, STDOUT
	mov rsi, char
	mov rdx, 1
	mov rax, WRITE
	syscall

	cmp rax, 0
	jle end
	mov rax, [char]
	ret

end:
	mov rax, -42
	ret
