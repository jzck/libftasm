global _ft_islower
global ft_islower

_ft_islower:
ft_islower:
	mov rax, 0
	cmp rdi, 'a'
	jl end
	cmp rdi, 'z'
	jg end
	mov rax, rdi
end: ret
