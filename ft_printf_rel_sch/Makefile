# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brice <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 04:22:21 by brice             #+#    #+#              #
#    Updated: 2021/01/12 21:49:09 by brice            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

LIBFTDIR	= ./libft/

PARSERDIR	= ./parser/

INCLUDE 	= ./include/

PROCDIR 	= ./processor/

HELPDIR		= ./helper/

LIBFT		= libft.a

FILETEST	= tests_func.c

VALUES 		= \"FFFFF%10.20s\\\n\", \"hello\"

SRCS		= ft_printf.c $(PARSERDIR)ft_itoa_base_ull.c $(PARSERDIR)ft_itoa_base_xu.c  \
						  $(PARSERDIR)ft_parser.c  $(PARSERDIR)ft_struct_init.c \
						  $(PROCDIR)ft_print_char.c $(PROCDIR)ft_print_char.c \
						  $(PROCDIR)ft_print_d.c   $(PROCDIR)ft_print_p.c \
						  $(PROCDIR)ft_print_percent.c $(PROCDIR)ft_print_string.c \
						  $(PROCDIR)ft_print_u.c \
						  \
						  $(HELPDIR)ft_helper_prints.c \
						  \
						  $(HELPDIR)ft_helper_check_u.c $(HELPDIR)ft_check_minus_helper.c \
						  $(HELPDIR)ft_while_print_null_helper.c \
						  \
						  $(HELPDIR)ft_print_helpers_str.c \
						  \
						  $(HELPDIR)ft_first_check_d_help.c\

OBJS		= $(SRCS:.c=.o)

%.o:	%.c
			@$(GCC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C $(LIBFTDIR)
			@cp  $(LIBFTDIR)$(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "\033[42m\033[31mbuild libftprintf\033[0m"

all:		$(NAME)

clean:
			@echo "\033[31m\033[42mclean\033[0m\033[31m libft & libftprintf\033[0m"
			@make -C $(LIBFTDIR) clean
			@rm -rf $(OBJS) #$(FILETEST)

fclean:		clean
			@echo "\033[31m\033[42mfclean\033[0m\033[31m libft & libftprintf\033[0m"
			@make -C $(LIBFTDIR) fclean
			@rm -rf $(NAME) $(LIBFT) $(FILETEST) a.out

re:			fclean all

test:
			@echo "\033[35msuccess $(FILETEST)\033[0m"
			@touch $(FILETEST)
			@echo "#include \"ft_printf.h\"\n#include <stdio.h>\n\nint main()\n{\n\tft_printf($(VALUES));\n\tprintf($(VALUES));\n}" > $(FILETEST)

compile:
		@echo "\033[35m<--compile $(FILETEST)-->\033[0m"
		@$(GCC) $(CFLAGS) $(FILETEST) -I $(INCLUDE) -L. -lftprintf
