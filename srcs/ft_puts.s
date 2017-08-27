global _ft_puts
global ft_puts

_ft_puts:
ft_puts:
	cmp rdi, 0
	je end
	WRITE rdi
	inc rdi
	jmp ft_puts
end:
	ret
