global _ft_bzero
global ft_bzero
section .text

_ft_bzero:
ft_bzero:
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
start_loop:
	mov BYTE [rdi], 0
	inc rdi
	dec rsi
	jnz start_loop
; loop start_loop 

end:
	ret
