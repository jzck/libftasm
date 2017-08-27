global _ft_strcat
global ft_strcat

_ft_strcat:
ft_strcat:
	mov rax, rdi
rloop:
	cmp byte [rdi], 0
	je wloop
	inc rdi
	jmp rloop

wloop:
	mov cl, [rsi]
	mov [rdi], cl
	cmp byte [rdi], 0
	je end
	inc rdi
	inc rsi
	jmp wloop
end: ret
