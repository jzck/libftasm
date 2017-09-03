global _ft_cat
global ft_cat

extern ft_putchar

%define STDOUT			1
%define BUFF_SIZE		10

section .bss
	buf: resb BUFF_SIZE

section .text

_ft_cat:						; void ft_cat(int fd)
ft_cat:
	push	rdi
	lea		rsi, [rel buf]
	mov		rdx, BUFF_SIZE
	mov		rax, READ			; int read(int fd, void *buf, size_t count)
	syscall
	cmp		rax, 0
	jle		end

    mov     rdi, STDOUT
    mov     rdx, rax
    mov     rax, WRITE			; int write(int fd, const void *buf, size_t count)
    syscall
	cmp		rax, 0
	jl		end

	pop		rdi
    jmp		ft_cat
end:		
	pop		rax
	ret
