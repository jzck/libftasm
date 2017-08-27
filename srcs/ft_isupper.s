global _ft_isupper
global ft_isupper

_ft_isupper:
ft_isupper:
	mov rax, 0
	cmp rdi, 'A'
	jl end
	cmp rdi, 'Z'
	jg end
	mov rax, rdi
end: ret
