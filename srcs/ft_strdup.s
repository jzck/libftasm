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

	sub		rsp, 8		; align stack to 16 bytes, x86_64 or mach don't know
	call	_malloc
	add		rsp, 8

	pop		rcx
	pop		rsi
	cmp		rax, 0
	je		end

	mov		rdi, rax
	cld					; clear the directon flag
	rep		movsb
end:
	ret
