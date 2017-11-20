global _ft_puts
global ft_puts

extern _ft_strlen
extern _ft_putchar

%define STDOUT			1

section .data
	string: db "(null)"
	.len: equ $ - string

section .text
_ft_puts:						; int puts(const char *s)
ft_puts:
	push	rdi					; because strlen will clobber rdi
	call	_ft_strlen
	pop		rdi
    cmp     rax, 0
    je      print_nl			; if empty string skip printing

print_string:
	; int write(int fd, const char *str, size_t size)
	mov		rsi, rdi			; char *str
    mov     rdi, STDOUT			; int fd
    mov     rdx, rax            ; size_t strlen
    mov     rax, WRITE			; WRITE
    syscall
	cmp		rax, 0
	jl		finish

print_nl:
	mov		rdi, 0xa
	call	_ft_putchar
	cmp		rax, 0
	ret
	jl		finish

success:
	mov		rax, 0xa			; success returns '\n'
finish:
	ret
