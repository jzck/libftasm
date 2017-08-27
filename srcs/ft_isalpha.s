global _ft_isalpha
global ft_isalpha

extern ft_islower
extern ft_isupper

_ft_isalpha:
ft_isalpha:
	mov rax, 0
	call ft_isupper
	cmp rax, 0
	jne end
	call ft_islower

end: ret
