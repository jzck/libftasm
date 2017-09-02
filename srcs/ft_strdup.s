global		_ft_strdup
global		ft_strdup

extern		malloc
extern		ft_strlen
extern		ft_memcpy

_ft_strdup:			; void *ft_strdup(const char *d)
ft_strdup:
	mov		rax, 0
	cmp		rdi, 0
	je		end
	push	rdi
	call	ft_strlen
	inc		rax
	push	rax
	mov		rdi, rax
	call	malloc
	cmp		rax, 0
	je		end
	mov		rdi, rax
	pop		rcx
	pop		rsi
	cld
	rep		movsb
end:
	ret
