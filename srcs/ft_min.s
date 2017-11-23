global _ft_min
global ft_min

section .text
; int ft_min(int a, int b)
_ft_min:
ft_min:
	mov rax, rdi
	cmp rdi, rsi
	jl end
	mov rax, rsi
end:
	ret
