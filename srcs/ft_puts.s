global _ft_puts
global ft_puts

extern ft_strlen
extern ft_putchar

%define STDOUT			1

_ft_puts:						; int puts(const char *s)
ft_puts:
	push	rdi
    call    ft_strlen
	pop		rdi
    push    rax					; Number of printed chars have to be returned by ft_puts
    cmp     rax, 0
    jg      print_string		; if length > 0, print string
	mov		rdi, 0xa
	call	ft_putchar
    jmp     error				; else go to error

print_string:
    mov     rsi, rdi            ; string arg for write
    mov     rdi, STDOUT			; file_descriptor arg for write
    mov     rdx, rax            ; length arg returned by ft_strlen for write
    mov     rax, WRITE			; write
	mov		byte [rsi + rdx], 0xa	; newline at end of string
	inc		rdx
    syscall
	dec		rdx
	mov		byte [rsi + rdx], 0x0	; put back eos

    test    rax, rax
    jle     error               ; if write failed, go to error
	jmp		success

success:
    pop     rax                 ; Get number of chars printed by print_string
    inc     rax                 ; Add new line printed by print_newline to this number
    jmp     end

error:
    pop     rax
    mov     rax, -1             ; Return EOF (alias -1) on error
    jmp     end

end:
	ret
