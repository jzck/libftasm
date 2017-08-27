global _ft_isalnum
global ft_isalnum

extern ft_isalpha
extern ft_isdigit

_ft_isalnum:
ft_isalnum:
	mov rax, 0
	call ft_isalpha
	cmp rax, 0
	jne end
	call ft_isdigit
end: ret
