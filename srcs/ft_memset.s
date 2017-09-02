global _ft_memset
global ft_memset

_ft_memset:			; void *ft_memset(void *s, int c, size_t n)
ft_memset:
	push	rdi
	cmp		rdi, 0
	je		end
	mov		rcx, rdx
	mov		al, sil
	cld
	rep		stosb

end:
	pop		rdi
	mov		rax, rdi
	ret
