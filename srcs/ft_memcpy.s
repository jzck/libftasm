global		_ft_memcpy
global		ft_memcpy

_ft_memcpy:			; void *ft_memcpy(void *dst, const void *src, size_t n)
ft_memcpy:
	push	rdi
	cmp		rdi, 0
	je		end
	cmp		rsi, 0
	je		end
	mov		rcx, rdx
	cld
	rep		movsb

end:
	pop		rdi
	mov		rax, rdi
	ret
