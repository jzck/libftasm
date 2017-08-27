global _ft_toupper
global ft_toupper

_ft_toupper:
ft_toupper:
	mov rax, rdi
	cmp rdi, 'a'
	jl end
	cmp rdi, 'z'
	jg end
	sub rax, 32
end:
	ret
