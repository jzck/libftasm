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
	push	rdi

	; int write(int fd, char *str, size_t len)
	lea		rsi, [char]		; char *str
	mov		[rsi], dil
	mov		rdi, STDOUT		; int fd
	mov		rdx, 1			; size_t len
	mov		rax, WRITE
	syscall

	cmp		rax, 0
	jl		err

	; success case then return c
	pop		rax
	ret

err:
	; error case then return -1
	pop		rax
	mov		rax, -1
	ret
