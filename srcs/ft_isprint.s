global _ft_isprint
global ft_isprint

_ft_isprint:
ft_isprint:
	mov rax, 0
	cmp rdi, ' '
	jl end
	cmp rdi, '~'
	jg end
	mov rax, rdi
end:
	ret
