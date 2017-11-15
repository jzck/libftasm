%define STDOUT			1

global _ft_putchar
global ft_putchar

section .bss
	char: resb 1

section .text

; int ft_putchar(int c)
_ft_putchar:
ft_putchar:
	; save c value
	push rdi

	; write(STDOUT, char, 1)
	mov rdi, STDOUT
	lea rsi, [rdi]
	mov rdx, 1
	mov rax, WRITE
	syscall

	cmp rax, 0
	jle err
	; success case then return c
	pop rax
	ret

err:
	; error case then return -1
	mov rax, -1
	ret
