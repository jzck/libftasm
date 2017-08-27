global _ft_isascii
global ft_isascii

_ft_isascii:
ft_isascii:
	mov rax, 0
	and rdi, 128
	jne end
	mov rax, 1
end:
	ret
