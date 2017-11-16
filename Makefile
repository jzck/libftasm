#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2016/12/24 02:14:21 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SHELL		:=	bash

NAME		=	libfts.a
NASM		=	nasm

UNAME_S		=	$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS_ASM	=	-g\
					-f elf64\
					-D READ=0x0000000\
					-DWRITE=0x0000001
endif
ifeq ($(UNAME_S),Darwin)
	FLAGS_ASM	=	-g\
					-f macho64\
					-D READ=0x2000003\
					-DWRITE=0x2000004
endif


LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-31-$(LEN_NAME)"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	= \
ft_bzero.s\
ft_strcat.s\
ft_isalpha.s\
ft_isdigit.s\
ft_isalnum.s\
ft_isascii.s\
ft_isprint.s\
ft_toupper.s\
ft_tolower.s\
ft_puts.s\
\
ft_strlen.s\
ft_memset.s\
ft_memcpy.s\
ft_strdup.s\
\
ft_cat.s\
\
ft_islower.s\
ft_isupper.s\
ft_putchar.s\

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.s=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@$(MAKE) -j $(NAME)

$(NAME) :		$(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.s | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(NASM) $(FLAGS_ASM) $< -o $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean :
	@if [ -e $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n"; \
	fi;

fclean :		clean
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n"; \
	fi;

re :			fclean all

test: $(NAME) test.c
	@gcc test.c -I $(INC_DIR) -L. -lfts -o test
	@printf "\r\033[38;5;117m✓ MAKE test\033[0m\033[K\n"

debug: $(NAME) debug.c
	@gcc debug.c -I $(INC_DIR) -L. -lfts -o debug
	@printf "\r\033[38;5;117m✓ MAKE debug\033[0m\033[K\n"

run-dbg: debug
	lldb ./debug

.PHONY :		fclean clean re run-gdb

-include $(OBJS:.o=.d)
