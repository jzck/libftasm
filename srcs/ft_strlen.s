global _ft_strlen
global ft_strlen

_ft_strlen:
ft_strlen:
	mov rax, 0
	cmp rdi, 0
	je end
loop:
	cmp byte [rdi], 0
	je end
	inc rax
	inc rdi
	jmp loop
end:
	ret
