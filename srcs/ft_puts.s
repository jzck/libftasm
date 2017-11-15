global _ft_puts
global ft_puts

extern ft_strlen
extern ft_putchar

%define STDOUT			1

section .data
	string db "(null)"
	.len: equ $ - string

_ft_puts:						; int puts(const char *s)
ft_puts:
	push	rdi					; because strlen will clobber rdi
	call	ft_strlen
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
	jc		error

print_nl:
	mov		rdi, 0xa
	call	ft_putchar
    test	rax, rax
    jc		error               ; if write failed, go to error

success:
	mov		rax, 0xa			; success returns '\n'
    jmp     end

error:
    pop     rax
    mov     rax, -1             ; Return EOF (alias -1) on error
    jmp     end

end:
	ret
