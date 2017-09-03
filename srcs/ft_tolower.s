global _ft_tolower
global ft_tolower

_ft_tolower:
ft_tolower:
	mov		rax, rdi
	cmp		rdi, 'A'
	jl		end
	cmp		rdi, 'Z'
	jg		end
	add		rax, 32
end:
	ret
