global		_ft_strdup
global		ft_strdup

extern		_malloc
extern		malloc
extern		_ft_strlen
extern		_ft_memcpy

; void *ft_strdup(const char *d)
_ft_strdup:
ft_strdup:
	mov		rax, 0
	cmp		rdi, 0
	je		end
	push	rdi
	call	_ft_strlen
	inc		rax
	push	rax
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	je		end

	mov		rdi, rax
	pop		rcx
	pop		rsi
	cld
	rep		movsb
end:
	ret
