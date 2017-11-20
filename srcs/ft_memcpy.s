global		_ft_memcpy
global		ft_memcpy

; void *ft_memcpy(void *dst, const void *src, size_t n)
_ft_memcpy:
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
