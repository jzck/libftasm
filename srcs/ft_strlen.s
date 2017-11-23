global _ft_strlen
global ft_strlen

_ft_strlen:
ft_strlen:
	mov		rax, 0
	cmp		rdi, 0
	je		end
t
	mov		rcx, -1
	cld
	repnz	scasb

	not		rcx
	lea		rax, [rcx - 1]

end:
	ret
