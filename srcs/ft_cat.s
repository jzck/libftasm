global _ft_cat
global ft_cat

%define STDOUT			1
%define BUFF_SIZE		1024

section .bss
	buf: resb BUFF_SIZE

section .text
; void ft_cat(int fd)
_ft_cat:
ft_cat:
	mov		r8, rdi
	cmp		rdi, 0
	jl		end
	lea		rsi, [rel buf]
	mov		rdx, BUFF_SIZE
	mov		rax, READ			; int read(int fd, void *buf, size_t count)
	syscall
	jc		end
	cmp		rax, 0
	jle		end

    mov     rdi, STDOUT
    mov     rdx, rax
    mov     rax, WRITE			; int write(int fd, const void *buf, size_t count)
    syscall
	jc		end
	cmp		rax, 0
	jl		end

	mov		rdi, r8
    jmp		ft_cat
end:		
	ret
