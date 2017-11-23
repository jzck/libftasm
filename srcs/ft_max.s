global _ft_max
global ft_max

section .text
; int ft_max(int a, int b)
_ft_max:
ft_max:
	mov rax, rdi
	cmp rdi, rsi
	jge end
	mov rax, rsi
end:
	ret
